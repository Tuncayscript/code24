/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef __GLIBC__
#include <link.h>
#endif

#include "platform.h"
#include "code.h"
#include "language_internal.h"
#ifdef _OS_WINDOWS_
#include <direct.h>
#else
#include <unistd.h>
#include <dlfcn.h>
#endif
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__APPLE__)
static char const *const extensions[] = { "", ".dylib" };
#elif defined(_OS_WINDOWS_)
static char const *const extensions[] = { "", ".dll" };
extern volatile int needsSymRefreshModuleList;
#else
static char const *const extensions[] = { "", ".so" };
#endif
#define N_EXTENSIONS (sizeof(extensions) / sizeof(char*))

static int endswith_extension(const char *path) LANGUAGE_NOTSAFEPOINT
{
    if (!path)
        return 0;
    size_t len = strlen(path);
    // Skip the first one since it is empty
    for (size_t i = 1; i < N_EXTENSIONS; i++) {
        const char *ext = extensions[i];
        size_t extlen = strlen(ext);
        if (len < extlen)
            return 0;
        // Skip version extensions if present
        size_t j = len - 1;
        while (j > 0) {
            if (path[j] == '.' || (path[j] >= '0' && path[j] <= '9'))
                j--;
            else
                break;
        }
        if ((j == len-1 || path[j+1] == '.') && memcmp(ext, path + j - extlen + 1, extlen) == 0) {
            return 1;
        }
    }
    return 0;
}

#ifdef _OS_WINDOWS_
#define CRTDLL_BASENAME "msvcrt"

LANGUAGE_DLLEXPORT const char *language_crtdll_basename = CRTDLL_BASENAME;
const char *language_crtdll_name = CRTDLL_BASENAME ".dll";

#undef CRTDLL_BASENAME
#endif

#define PATHBUF 4096

#ifdef _OS_WINDOWS_
void win32_formatmessage(DWORD code, char *reason, int len) LANGUAGE_NOTSAFEPOINT
{
    DWORD res;
    LPWSTR errmsg;
    res = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                         FORMAT_MESSAGE_FROM_SYSTEM |
                         FORMAT_MESSAGE_IGNORE_INSERTS |
                         FORMAT_MESSAGE_MAX_WIDTH_MASK,
                         NULL, code,
                         MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                         (LPWSTR)&errmsg, 0, NULL);
    if (!res && (GetLastError() == ERROR_MUI_FILE_NOT_FOUND ||
                 GetLastError() == ERROR_RESOURCE_TYPE_NOT_FOUND)) {
      res = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                           FORMAT_MESSAGE_FROM_SYSTEM |
                           FORMAT_MESSAGE_IGNORE_INSERTS |
                           FORMAT_MESSAGE_MAX_WIDTH_MASK,
                           NULL, code,
                           0, (LPWSTR)&errmsg, 0, NULL);
    }
    res = WideCharToMultiByte(CP_UTF8, 0, errmsg, -1, reason, len, NULL, NULL);
    assert(res > 0 || GetLastError() == ERROR_INSUFFICIENT_BUFFER);
    reason[len - 1] = '\0';
    LocalFree(errmsg);
}
#endif

#if defined(_COMPILER_MSAN_ENABLED_) || defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_)
struct link_map;
typedef void* (dlopen_prototype)(const char* filename, int flags);

/* This function is copied from the memory sanitizer runtime.
   Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
   See https://llvm.org/LICENSE.txt for license information.
   SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
*/
static inline uintptr_t RoundUpTo(uintptr_t size, uintptr_t boundary) {
  return (size + boundary - 1) & ~(boundary - 1);
}
static inline uintptr_t RoundDownTo(uintptr_t x, uintptr_t boundary) {
  return x & ~(boundary - 1);
}
void ForEachMappedRegion(struct link_map *map, void (*cb)(const volatile void *, uintptr_t)) {
#if !defined(_OS_FREEBSD_)
  typedef ElfW(Phdr) Elf_Phdr;
  typedef ElfW(Ehdr) Elf_Ehdr;
#endif
  char *base = (char *)map->l_addr;
  Elf_Ehdr *ehdr = (Elf_Ehdr *)base;
  char *phdrs = base + ehdr->e_phoff;
  char *phdrs_end = phdrs + ehdr->e_phnum * ehdr->e_phentsize;

  // Find the segment with the minimum base so we can "relocate" the p_vaddr
  // fields.  Typically ET_DYN objects (DSOs) have base of zero and ET_EXEC
  // objects have a non-zero base.
  uintptr_t preferred_base = (uintptr_t)-1;
  for (char *iter = phdrs; iter != phdrs_end; iter += ehdr->e_phentsize) {
    Elf_Phdr *phdr = (Elf_Phdr *)iter;
    if (phdr->p_type == PT_LOAD && preferred_base > (uintptr_t)phdr->p_vaddr)
      preferred_base = (uintptr_t)phdr->p_vaddr;
  }

  // Compute the delta from the real base to get a relocation delta.
  intptr_t delta = (uintptr_t)base - preferred_base;
  // Now we can figure out what the loader really mapped.
  for (char *iter = phdrs; iter != phdrs_end; iter += ehdr->e_phentsize) {
    Elf_Phdr *phdr = (Elf_Phdr *)iter;
    if (phdr->p_type == PT_LOAD) {
      uintptr_t seg_start = phdr->p_vaddr + delta;
      uintptr_t seg_end = seg_start + phdr->p_memsz;
      // None of these values are aligned.  We consider the ragged edges of the
      // load command as defined, since they are mapped from the file.
      seg_start = RoundDownTo(seg_start, language_page_size);
      seg_end = RoundUpTo(seg_end, language_page_size);
      cb((void *)seg_start, seg_end - seg_start);
    }
  }
}
#endif

#if defined(_OS_WINDOWS_)
LANGUAGE_DLLEXPORT void *language_dlopen(const char *filename, unsigned flags) LANGUAGE_NOTSAFEPOINT
{
    size_t len = MultiByteToWideChar(CP_UTF8, 0, filename, -1, NULL, 0);
    if (!len) return NULL;
    WCHAR *wfilename = (WCHAR*)alloca(len * sizeof(WCHAR));
    if (!MultiByteToWideChar(CP_UTF8, 0, filename, -1, wfilename, len)) return NULL;
    HANDLE lib;
    if (flags & LANGUAGE_RTLD_NOLOAD) {
        lib = GetModuleHandleW(wfilename);
    }
    else {
        lib = LoadLibraryExW(wfilename, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        if (lib)
            needsSymRefreshModuleList = 1;
    }
    return lib;
}
#else

#define LANGUAGE_RTLD(flags, FLAG) (flags & LANGUAGE_RTLD_ ## FLAG ? RTLD_ ## FLAG : 0)

LANGUAGE_DLLEXPORT LANGUAGE_NO_SANITIZE void *language_dlopen(const char *filename, unsigned flags) LANGUAGE_NOTSAFEPOINT
{
    /* The sanitizers break RUNPATH use in dlopen for annoying reasons that are
       are hard to fix. Specifically, libc will use the return address of the
       caller to determine certain paths and flags that affect .so location lookup.
       To work around this, we need to avoid using the sanitizer's dlopen interposition,
       instead using the real dlopen directly from the current shared library.
       Of course, this does mean that we need to manually perform the work that
       the sanitizers would otherwise do. */
#if (defined(_COMPILER_MSAN_ENABLED_) || defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_)) && __GLIBC__
    static dlopen_prototype *dlopen = NULL;
    if (!dlopen) {
        dlopen = (dlopen_prototype*)dlsym(RTLD_NEXT, "dlopen");
        if (!dlopen)
            return NULL;
        void *libdl_handle = dlopen("libdl.so.2", RTLD_NOW | RTLD_NOLOAD);
        assert(libdl_handle);
        dlopen = (dlopen_prototype*)dlsym(libdl_handle, "dlopen");
        dlclose(libdl_handle);
        assert(dlopen);
    }
    // The real interceptors check the validity of the string here, but let's
    // just skip that for the time being.
#endif
    void *hnd = dlopen(filename,
                  (flags & LANGUAGE_RTLD_NOW ? RTLD_NOW : RTLD_LAZY)
                  | LANGUAGE_RTLD(flags, LOCAL)
                  | LANGUAGE_RTLD(flags, GLOBAL)
#ifdef RTLD_NODELETE
                  | LANGUAGE_RTLD(flags, NODELETE)
#endif
#ifdef RTLD_NOLOAD
                  | LANGUAGE_RTLD(flags, NOLOAD)
#endif
#if defined(RTLD_DEEPBIND) && !(defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_) || defined(_COMPILER_MSAN_ENABLED_))
                  | LANGUAGE_RTLD(flags, DEEPBIND)
#endif
#ifdef RTLD_FIRST
                  | LANGUAGE_RTLD(flags, FIRST)
#endif
                  );
#if defined(_COMPILER_MSAN_ENABLED_) && defined(__GLIBC__)
    struct link_map *map = (struct link_map*)hnd;
    if (filename && map)
      ForEachMappedRegion(map, __msan_unpoison);
#endif
    return hnd;
}
#endif


LANGUAGE_DLLEXPORT int language_dlclose(void *handle) LANGUAGE_NOTSAFEPOINT
{
#ifdef _OS_WINDOWS_
    if (!handle) {
        return -1;
    }
    return !FreeLibrary((HMODULE) handle);
#else
    if (!handle) {
        dlerror(); /* Reset error status. */
        return -1;
    }
    return dlclose(handle);
#endif
}

void *language_find_dynamic_library_by_addr(void *symbol) {
    void *handle;
#ifdef _OS_WINDOWS_
    if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            (LPCWSTR)symbol,
                            (HMODULE*)&handle)) {
        language_error("could not load base module");
    }
#else
    Dl_info info;
    if (!dladdr(symbol, &info) || !info.dli_fname) {
        language_error("could not load base module");
    }
    handle = dlopen(info.dli_fname, RTLD_NOW | RTLD_NOLOAD | RTLD_LOCAL);
    dlclose(handle); // Undo ref count increment from `dlopen`
#endif
    return handle;
}

LANGUAGE_DLLEXPORT void *language_load_dynamic_library(const char *modname, unsigned flags, int throw_err)
{
    char path[PATHBUF], relocated[PATHBUF];
    int i;
#ifdef _OS_WINDOWS_
    int err;
#endif
    uv_stat_t stbuf;
    void *handle;
    int abspath;
    int is_atpath;
    // number of extensions to try — if modname already ends with the
    // standard extension, then we don't try adding additional extensions
    int n_extensions = endswith_extension(modname) ? 1 : N_EXTENSIONS;
    int ret;

    // modname == NULL is a sentinel value requesting the handle of libjulia-internal
    if (modname == NULL)
        return language_find_dynamic_library_by_addr(&language_load_dynamic_library);

    abspath = language_isabspath(modname);
    is_atpath = 0;

    LANGUAGE_TIMING(DL_OPEN, DL_OPEN);
    if (!(flags & LANGUAGE_RTLD_NOLOAD))
        language_timing_puts(LANGUAGE_TIMING_DEFAULT_BLOCK, modname);

    // Detect if our `modname` is something like `@rpath/libfoo.dylib`
#ifdef _OS_DARWIN_
    size_t nameLen = strlen(modname);
    const char *const atPaths[] = {"@executable_path/", "@loader_path/", "@rpath/"};
    for (i = 0; i < sizeof(atPaths)/sizeof(char*); ++i) {
        size_t atLen = strlen(atPaths[i]);
        if (nameLen >= atLen && 0 == strncmp(modname, atPaths[i], atLen)) {
            is_atpath = 1;
        }
    }
#endif

    /*
      this branch permutes all base paths in DL_LOAD_PATH with all extensions
      note: skip when !language_base_module to avoid UndefVarError(:DL_LOAD_PATH),
            and also skip for absolute paths
            and also skip for `@`-paths on macOS
      We also do simple string replacement here for elements starting with `@executable_path/`.
      While these exist as OS concepts on Darwin, we want to use them on other platforms
      such as Windows, so we emulate them here.
    */
    if (!abspath && !is_atpath && language_base_module != NULL) {
        language_binding_t *b = language_get_module_binding(language_base_module, language_symbol("DL_LOAD_PATH"), 0);
        language_array_t *DL_LOAD_PATH = (language_array_t*)(b ? language_atomic_load_relaxed(&b->value) : NULL);
        if (DL_LOAD_PATH != NULL) {
            size_t j;
            for (j = 0; j < language_array_nrows(DL_LOAD_PATH); j++) {
                char *dl_path = language_string_data(language_array_ptr_data(DL_LOAD_PATH)[j]);
                size_t len = strlen(dl_path);
                if (len == 0)
                    continue;

                // Is this entry supposed to be relative to the bindir?
                if (len >= 16 && strncmp(dl_path, "@executable_path", 16) == 0) {
                    snprintf(relocated, PATHBUF, "%s%s", language_options.language_bindir, dl_path + 16);
                    len = len - 16 + strlen(language_options.language_bindir);
                } else {
                    strncpy(relocated, dl_path, PATHBUF);
                    relocated[PATHBUF-1] = '\0';
                }
                for (i = 0; i < n_extensions; i++) {
                    const char *ext = extensions[i];
                    path[0] = '\0';
                    if (relocated[len-1] == PATHSEPSTRING[0])
                        snprintf(path, PATHBUF, "%s%s%s", relocated, modname, ext);
                    else {
                        ret = snprintf(path, PATHBUF, "%s" PATHSEPSTRING "%s%s", relocated, modname, ext);
                        if (ret < 0)
                            language_errorf("path is longer than %d\n", PATHBUF);
                    }

#ifdef _OS_WINDOWS_
                    if (i == 0) { // LoadLibrary already tested the extensions, we just need to check the `stat` result
#endif
                        handle = language_dlopen(path, flags);
                        if (handle && !(flags & LANGUAGE_RTLD_NOLOAD))
                            language_timing_puts(LANGUAGE_TIMING_DEFAULT_BLOCK, language_pathname_for_handle(handle));
                        if (handle)
                            return handle;
#ifdef _OS_WINDOWS_
                        err = GetLastError();
                    }
#endif
                    // bail out and show the error if file actually exists
                    if (language_stat(path, (char*)&stbuf) == 0)
                        goto notfound;
                }
            }
        }
    }

    // now fall back and look in default library paths, for all extensions
    for (i = 0; i < n_extensions; i++) {
        const char *ext = extensions[i];
        path[0] = '\0';
        snprintf(path, PATHBUF, "%s%s", modname, ext);
        handle = language_dlopen(path, flags);
        if (handle && !(flags & LANGUAGE_RTLD_NOLOAD))
            language_timing_puts(LANGUAGE_TIMING_DEFAULT_BLOCK, language_pathname_for_handle(handle));
        if (handle)
            return handle;
#ifdef _OS_WINDOWS_
        err = GetLastError();
        break; // LoadLibrary already tested the rest
#else
        // bail out and show the error if file actually exists
        if (language_stat(path, (char*)&stbuf) == 0)
            break;
#endif
    }

notfound:
    if (throw_err) {
#ifdef _OS_WINDOWS_
        char reason[256];
        win32_formatmessage(err, reason, sizeof(reason));
#else
        const char *reason = dlerror();
#endif
        language_errorf("could not load library \"%s\"\n%s", modname, reason);
    }
    handle = NULL;

    return handle;
}

LANGUAGE_DLLEXPORT int language_dlsym(void *handle, const char *symbol, void ** value, int throw_err) LANGUAGE_NOTSAFEPOINT
{
    int symbol_found = 0;

    /* First, get the symbol value */
#ifdef _OS_WINDOWS_
    *value = GetProcAddress((HMODULE) handle, symbol);
#else
    *value = dlsym(handle, symbol);
#endif

    /* Next, check for errors. On Windows, a NULL pointer means the symbol was
     * not found. On everything else, we can have NULL symbols, so we check for
     * non-NULL returns from dlerror(). Since POSIX doesn't require `dlerror`
     * to be implemented safely, FreeBSD doesn't (unlike everyone else, who
     * realized decades ago that threads are here to stay), so we avoid calling
     * `dlerror` unless we need to get the error message.
     * https://github.com/freebsd/freebsd-src/blob/12db51d20823a5e3b9e5f8a2ea73156fe1cbfc28/libexec/rtld-elf/rtld.c#L198
     */
    symbol_found = *value != NULL;
#ifndef _OS_WINDOWS_
    const char *err = "";
    if (!symbol_found) {
        dlerror(); /* Reset error status. */
        *value = dlsym(handle, symbol);
        err = dlerror();
        symbol_found = *value != NULL || err == NULL;
    }
#endif

    if (!symbol_found && throw_err) {
#ifdef _OS_WINDOWS_
        char err[256];
        win32_formatmessage(GetLastError(), err, sizeof(err));
#endif
        language_errorf("could not load symbol \"%s\":\n%s", symbol, err);
    }
    return symbol_found;
}

// Look for symbols in internal libraries
LANGUAGE_DLLEXPORT const char *language_dlfind(const char *f_name)
{
#ifdef _OS_FREEBSD_
    // This is a workaround for FreeBSD <= 13.2 which do not have
    // https://cgit.freebsd.org/src/commit/?id=21a52f99440c9bec7679f3b0c5c9d888901c3694
    // (See https://github.com/JuliaLang/julia/issues/50846)
    if (strcmp(f_name, "dl_iterate_phdr") == 0)
        return LANGUAGE_EXE_LIBNAME;
#endif
    void * dummy;
    if (language_dlsym(language_liblanguage_internal_handle, f_name, &dummy, 0))
        return LANGUAGE_LIBJULIA_INTERNAL_DL_LIBNAME;
    if (language_dlsym(language_liblanguage_handle, f_name, &dummy, 0))
        return LANGUAGE_LIBJULIA_DL_LIBNAME;
    if (language_dlsym(language_exe_handle, f_name, &dummy, 0))
        return LANGUAGE_EXE_LIBNAME;
#ifdef _OS_WINDOWS_
    if (language_dlsym(language_kernel32_handle, f_name, &dummy, 0))
        return "kernel32";
    if (language_dlsym(language_crtdll_handle, f_name, &dummy, 0)) // Prefer crtdll over ntdll
        return language_crtdll_basename;
    if (language_dlsym(language_ntdll_handle, f_name, &dummy, 0))
        return "ntdll";
    if (language_dlsym(language_winsock_handle, f_name, &dummy, 0))
        return "ws2_32";
#endif
    // additional common libraries (libc?) could be added here, but in general,
    // it is better to specify the library explicitly in the code. This exists
    // mainly to ease compatibility with linux, and for libraries that don't
    // have a name (julia.exe and libjulia.dll)
    // We could also loop over all libraries that have been used so far, but, again,
    // explicit is preferred over implicit
    return NULL;
    // oops, we didn't find it. NULL defaults to searching language_RTLD_DEFAULT_handle,
    // which defaults to language_liblanguage_internal_handle, where we won't find it, and
    // will throw the appropriate error.
}

#ifdef __cplusplus
}
#endif
