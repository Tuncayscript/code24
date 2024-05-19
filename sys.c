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

/*
  sys.c
  I/O and operating system utility functions
*/
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>

#include "code.h"
#include "language_internal.h"

#ifdef _OS_WINDOWS_
#include <psapi.h>
#else
#include <unistd.h>
#if !defined(_SC_NPROCESSORS_ONLN) || defined(_OS_FREEBSD_) || defined(_OS_DARWIN_)
// try secondary location for _SC_NPROCESSORS_ONLN, or for HW_AVAILCPU on BSDs
#include <sys/sysctl.h>
#endif
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <grp.h>

// For `struct termios`
#include <termios.h>
#endif

#ifndef _OS_WINDOWS_
// for getrusage
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <mach-o/nlist.h>
#include <sys/types.h> // for language_raise_debugger
#elif !defined(_OS_WINDOWS_)
#include <link.h>
#endif

#ifdef __SSE__
#include <xmmintrin.h>
#endif

#ifdef _COMPILER_MSAN_ENABLED_
#include <sanitizer/msan_interface.h>
#endif

#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

LANGUAGE_DLLEXPORT int language_sizeof_off_t(void) { return sizeof(off_t); }
#ifndef _OS_WINDOWS_
LANGUAGE_DLLEXPORT int language_sizeof_mode_t(void) { return sizeof(mode_t); }
LANGUAGE_DLLEXPORT int language_ftruncate(int fd, int64_t length)
{
    return ftruncate(fd, (off_t)length);
}
LANGUAGE_DLLEXPORT int64_t language_lseek(int fd, int64_t offset, int whence)
{
    return lseek(fd, (off_t)offset, whence);
}
LANGUAGE_DLLEXPORT ssize_t language_pwrite(int fd, const void *buf, size_t count, int64_t offset)
{
    return pwrite(fd, buf, count, (off_t)offset);
}
LANGUAGE_DLLEXPORT void *language_mmap(void *addr, size_t length, int prot, int flags,
                           int fd, int64_t offset)
{
    return mmap(addr, length, prot, flags, fd, (off_t)offset);
}
#else
LANGUAGE_DLLEXPORT int64_t language_lseek(HANDLE fd, int64_t offset, int whence)
{
    LARGE_INTEGER tell;
    tell.QuadPart = offset;
    if (SetFilePointerEx(fd, tell, &tell, whence) == 0)
        return -1;
    return tell.QuadPart;
}
#endif
LANGUAGE_DLLEXPORT int language_sizeof_ios_t(void) { return sizeof(ios_t); }

LANGUAGE_DLLEXPORT long language_ios_fd(ios_t *s) { return s->fd; }

LANGUAGE_DLLEXPORT int32_t language_nb_available(ios_t *s)
{
    return (int32_t)(s->size - s->bpos);
}

// --- dir/file stuff ---

LANGUAGE_DLLEXPORT int language_sizeof_uv_fs_t(void) { return sizeof(uv_fs_t); }
LANGUAGE_DLLEXPORT char *language_uv_fs_t_ptr(uv_fs_t *req) { return (char*)req->ptr; }
LANGUAGE_DLLEXPORT char *language_uv_fs_t_path(uv_fs_t *req) { return (char*)req->path; }

// --- stat ---
LANGUAGE_DLLEXPORT int language_sizeof_stat(void) { return sizeof(uv_stat_t); }

LANGUAGE_DLLEXPORT int32_t language_stat(const char *path, char *statbuf) LANGUAGE_NOTSAFEPOINT
{
    uv_fs_t req;
    int ret;

    // Ideally one would use the statbuf for the storage in req, but
    // it's not clear that this is possible using libuv
    ret = uv_fs_stat(unused_uv_loop_arg, &req, path, NULL);
    if (ret == 0)
        memcpy(statbuf, req.ptr, sizeof(uv_stat_t));
    uv_fs_req_cleanup(&req);
    return ret;
}

LANGUAGE_DLLEXPORT int32_t language_lstat(const char *path, char *statbuf)
{
    uv_fs_t req;
    int ret;

    ret = uv_fs_lstat(unused_uv_loop_arg, &req, path, NULL);
    if (ret == 0)
        memcpy(statbuf, req.ptr, sizeof(uv_stat_t));
    uv_fs_req_cleanup(&req);
    return ret;
}

LANGUAGE_DLLEXPORT int32_t language_fstat(uv_os_fd_t fd, char *statbuf)
{
    uv_fs_t req;
    int ret;

    ret = uv_fs_fstat(unused_uv_loop_arg, &req, fd, NULL);
    if (ret == 0)
        memcpy(statbuf, req.ptr, sizeof(uv_stat_t));
    uv_fs_req_cleanup(&req);
    return ret;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_dev(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_dev;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_ino(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_ino;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_mode(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_mode;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_nlink(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_nlink;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_uid(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_uid;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_gid(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_gid;
}

LANGUAGE_DLLEXPORT unsigned int language_stat_rdev(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_rdev;
}

LANGUAGE_DLLEXPORT uint64_t language_stat_size(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_size;
}

LANGUAGE_DLLEXPORT uint64_t language_stat_blksize(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_blksize;
}

LANGUAGE_DLLEXPORT uint64_t language_stat_blocks(char *statbuf)
{
    return ((uv_stat_t*)statbuf)->st_blocks;
}

/*
// atime is stupid, let's not support it
LANGUAGE_DLLEXPORT double language_stat_atime(char *statbuf)
{
  uv_stat_t *s;
  s = (uv_stat_t*)statbuf;
  return (double)s->st_atim.tv_sec + (double)s->st_atim.tv_nsec * 1e-9;
}
*/

LANGUAGE_DLLEXPORT double language_stat_mtime(char *statbuf)
{
    uv_stat_t *s;
    s = (uv_stat_t*)statbuf;
    return (double)s->st_mtim.tv_sec + (double)s->st_mtim.tv_nsec * 1e-9;
}

LANGUAGE_DLLEXPORT double language_stat_ctime(char *statbuf)
{
    uv_stat_t *s;
    s = (uv_stat_t*)statbuf;
    return (double)s->st_ctim.tv_sec + (double)s->st_ctim.tv_nsec * 1e-9;
}

LANGUAGE_DLLEXPORT unsigned long language_getuid(void)
{
#ifdef _OS_WINDOWS_
    return -1;
#else
    return getuid();
#endif
}

LANGUAGE_DLLEXPORT unsigned long language_geteuid(void)
{
#ifdef _OS_WINDOWS_
    return -1;
#else
    return geteuid();
#endif
}

// --- buffer manipulation ---

LANGUAGE_DLLEXPORT language_array_t *language_take_buffer(ios_t *s)
{
    size_t n;
    language_array_t *a;
    if (s->buf == &s->local[0]) {
        // small data case. copies, but this can be avoided using the
        // technique of language_readuntil below.
        a = language_pchar_to_array(s->buf, s->size);
        ios_trunc(s, 0);
    }
    else {
        char *b = ios_take_buffer(s, &n);
        a = language_ptr_to_array_1d(language_array_uint8_type, b, n-1, 1);
    }
    return a;
}

// str: if 1 return a string, otherwise return a Vector{UInt8}
// chomp:
//   0 - keep delimiter
//   1 - remove 1 byte delimiter
//   2 - remove 2 bytes \r\n if present
LANGUAGE_DLLEXPORT language_value_t *language_readuntil(ios_t *s, uint8_t delim, uint8_t str, uint8_t chomp)
{
    language_array_t *a;
    // manually inlined common case
    char *pd = (char*)memchr(s->buf + s->bpos, delim, (size_t)(s->size - s->bpos));
    if (pd) {
        size_t n = pd - (s->buf + s->bpos) + 1;
        size_t nchomp = 0;
        if (chomp) {
            nchomp = chomp == 2 ? ios_nchomp(s, n) : 1;
        }
        if (str) {
            language_value_t *str = language_pchar_to_string(s->buf + s->bpos, n - nchomp);
            s->bpos += n;
            return str;
        }
        a = language_alloc_array_1d(language_array_uint8_type, n - nchomp);
        memcpy(language_array_data(a, uint8_t), s->buf + s->bpos, n - nchomp);
        s->bpos += n;
    }
    else {
        a = language_alloc_array_1d(language_array_uint8_type, 80);
        ios_t dest;
        ios_mem(&dest, 0);
        char *mem = language_array_data(a, char);
        ios_setbuf(&dest, (char*)mem, 80, 0);
        size_t n = ios_copyuntil(&dest, s, delim, 1);
        if (chomp && n > 0 && dest.buf[n - 1] == delim) {
            n--;
            if (chomp == 2 && n > 0 && dest.buf[n - 1] == '\r') {
                n--;
            }
            int truncret = ios_trunc(&dest, n); // it should always be possible to truncate dest
            assert(truncret == 0);
            (void)truncret; // ensure the variable is used to avoid warnings
        }
        if (dest.buf != mem) {
            a = language_take_buffer(&dest);
        }
        else {
            a->dimsize[0] = n;
        }
        if (str) {
            LANGUAGE_GC_PUSH1(&a);
            language_value_t *st = language_array_to_string(a);
            LANGUAGE_GC_POP();
            return st;
        }
    }
    return (language_value_t*)a;
}

// read up to buflen bytes, including delim, into buf.  returns number of bytes read.
LANGUAGE_DLLEXPORT size_t language_readuntil_buf(ios_t *s, uint8_t delim, uint8_t *buf, size_t buflen)
{
    // manually inlined common case
    size_t avail = (size_t)(s->size - s->bpos);
    if (avail > buflen) avail = buflen;
    char *pd = (char*)memchr(s->buf + s->bpos, delim, avail);
    if (pd) {
        size_t n = pd - (s->buf + s->bpos) + 1;
        memcpy(buf, s->buf + s->bpos, n);
        s->bpos += n;
        return n;
    }
    else {
        size_t total = avail;
        memcpy(buf, s->buf + s->bpos, avail);
        s->bpos += avail;
        if (avail == buflen) return total;

        // code derived from ios_copyuntil
        while (!ios_eof(s)) {
            avail = ios_readprep(s, 160); // read LINE_CHUNK_SIZE
            if (avail == 0) break;
            if (total+avail > buflen) avail = buflen-total;
            char *pd = (char*)memchr(s->buf+s->bpos, delim, avail);
            if (pd == NULL) {
                memcpy(buf+total, s->buf+s->bpos, avail);
                s->bpos += avail;
                total += avail;
                if (buflen == total) return total;
            }
            else {
                size_t ntowrite = pd - (s->buf+s->bpos) + 1;
                memcpy(buf+total, s->buf+s->bpos, ntowrite);
                s->bpos += ntowrite;
                total += ntowrite;
                return total;
            }
        }
        s->_eof = 1;
        return total;
    }
}

LANGUAGE_DLLEXPORT int language_ios_buffer_n(ios_t *s, const size_t n)
{
    size_t space, ret;
    do {
        space = (size_t)(s->size - s->bpos);
        ret = ios_readprep(s, n);
        if (space == ret && ret < n)
            return 1;
    } while (ret < n);
    return 0;
}

LANGUAGE_DLLEXPORT uint64_t language_ios_get_nbyte_int(ios_t *s, const size_t n)
{
    assert(n <= 8);
    uint64_t x = 0;
    uint8_t *buf = (uint8_t*)&s->buf[s->bpos];
    if (n == 8) {
        // expecting loop unrolling optimization
        for (size_t i = 0; i < 8; i++)
            x |= (uint64_t)buf[i] << (i << 3);
    }
    else if (n >= 4) {
        // expecting loop unrolling optimization
        for (size_t i = 0; i < 4; i++)
            x |= (uint64_t)buf[i] << (i << 3);
        for (size_t i = 4; i < n; i++)
            x |= (uint64_t)buf[i] << (i << 3);
    }
    else {
        for (size_t i = 0; i < n; i++)
            x |= (uint64_t)buf[i] << (i << 3);
    }
    s->bpos += n;
    return x;
}

// -- syscall utilities --

LANGUAGE_DLLEXPORT int language_errno(void) LANGUAGE_NOTSAFEPOINT { return errno; }
LANGUAGE_DLLEXPORT void language_set_errno(int e) LANGUAGE_NOTSAFEPOINT { errno = e; }

// -- get the number of CPU threads (logical cores) --

#ifdef _OS_WINDOWS_
typedef DWORD (WINAPI *GAPC)(WORD);
#ifndef ALL_PROCESSOR_GROUPS
#define ALL_PROCESSOR_GROUPS 0xffff
#endif
#endif

// Apple's M1 processor is a big.LITTLE style processor, with 4x "performance"
// cores, and 4x "efficiency" cores.  Because Julia expects to be able to run
// things like heavy linear algebra workloads on all cores, it's best for us
// to only spawn as many threads as there are performance cores.  Once macOS
// 12 is released, we'll be able to query the multiple "perf levels" of the
// cores of a CPU (see this PR [0] to pytorch/cpuinfo for an example) but
// until it's released, we will just recognize the M1 by its CPU family
// identifier, then subtract how many efficiency cores we know it has.

LANGUAGE_DLLEXPORT int language_cpu_threads(void) LANGUAGE_NOTSAFEPOINT
{
#if defined(HW_AVAILCPU) && defined(HW_NCPU)
    size_t len = 4;
    int32_t count;
    int nm[2] = {CTL_HW, HW_AVAILCPU};
    sysctl(nm, 2, &count, &len, NULL, 0);
    if (count < 1) {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if (count < 1) { count = 1; }
    }

#if defined(__APPLE__) && defined(_CPU_AARCH64_)
//MacOS 12 added a way to query performance cores
    char buf[7];
    len = 7;
    sysctlbyname("kern.osrelease", buf, &len, NULL, 0);
    if (buf[0] > 1 && buf[1] > 0){
        len = 4;
        sysctlbyname("hw.perflevel0.physicalcpu", &count, &len, NULL, 0);
    }
    else {
        int32_t family = 0;
        len = 4;
        sysctlbyname("hw.cpufamily", &family, &len, NULL, 0);
        if (family >= 1 && count > 1) {
            if (family == CPUFAMILY_ARM_FIRESTORM_ICESTORM) {
                // We know the Apple M1 has 4 efficiency cores, so subtract them out.
                count -= 4;
            }
        }
    }
#endif
    return count;
#elif defined(_SC_NPROCESSORS_ONLN)
    long count = sysconf(_SC_NPROCESSORS_ONLN);
    if (count < 1)
        return 1;
    return count;
#elif defined(_OS_WINDOWS_)
    //Try to get WIN7 API method
    GAPC gapc;
    if (language_dlsym(language_kernel32_handle, "GetActiveProcessorCount", (void **)&gapc, 0)) {
        return gapc(ALL_PROCESSOR_GROUPS);
    }
    else { //fall back on GetSystemInfo
        SYSTEM_INFO info;
        GetSystemInfo(&info);
        return info.dwNumberOfProcessors;
    }
#else
#warning "cpu core detection not defined for this platform"
    return 1;
#endif
}

LANGUAGE_DLLEXPORT int language_effective_threads(void) LANGUAGE_NOTSAFEPOINT
{
    int cpu = language_cpu_threads();
    int masksize = uv_cpumask_size();
    if (masksize < 0 || language_running_under_rr(0))
        return cpu;
    uv_thread_t tid = uv_thread_self();
    char *cpumask = (char *)calloc(masksize, sizeof(char));
    int err = uv_thread_getaffinity(&tid, cpumask, masksize);
    if (err) {
        free(cpumask);
        language_safe_printf("WARNING: failed to get thread affinity (%s %d)\n", uv_err_name(err),
                       err);
        return cpu;
    }
    int n = 0;
    for (size_t i = 0; i < masksize; i++) {
        n += cpumask[i];
    }
    free(cpumask);
    return n < cpu ? n : cpu;
}


// -- high resolution timers --
// Returns time in nanosec
LANGUAGE_DLLEXPORT uint64_t language_hrtime(void) LANGUAGE_NOTSAFEPOINT
{
    return uv_hrtime();
}

// -- iterating the environment --

#ifdef __APPLE__
#include <crt_externs.h>
#else
#if !defined(_OS_WINDOWS_) || defined(_COMPILER_GCC_)
extern char **environ;
#endif
#endif

LANGUAGE_DLLEXPORT language_value_t *language_environ(int i)
{
#ifdef __APPLE__
    char **environ = *_NSGetEnviron();
#endif
    char *env = environ[i];
    return env ? language_pchar_to_string(env, strlen(env)) : language_nothing;
}

// -- child process status --

#if defined _OS_WINDOWS_
/* Native Woe32 API.  */
#include <process.h>
#define waitpid(pid,statusp,options) _cwait (statusp, pid, WAIT_CHILD)
#define WAIT_T int
#define WTERMSIG(x) ((x) & 0xff) /* or: SIGABRT ?? */
#define WCOREDUMP(x) 0
#define WEXITSTATUS(x) (((x) >> 8) & 0xff) /* or: (x) ?? */
#define WIFSIGNALED(x) (WTERMSIG (x) != 0) /* or: ((x) == 3) ?? */
#define WIFEXITED(x) (WTERMSIG (x) == 0) /* or: ((x) != 3) ?? */
#define WIFSTOPPED(x) 0
#define WSTOPSIG(x) 0 //Is this correct?
#endif

int language_process_exited(int status)      { return WIFEXITED(status); }
int language_process_signaled(int status)    { return WIFSIGNALED(status); }
int language_process_stopped(int status)     { return WIFSTOPPED(status); }

int language_process_exit_status(int status) { return WEXITSTATUS(status); }
int language_process_term_signal(int status) { return WTERMSIG(status); }
int language_process_stop_signal(int status) { return WSTOPSIG(status); }

// -- access to std filehandles --

LANGUAGE_STREAM *LANGUAGE_STDIN  = (LANGUAGE_STREAM*)STDIN_FILENO;
LANGUAGE_STREAM *LANGUAGE_STDOUT = (LANGUAGE_STREAM*)STDOUT_FILENO;
LANGUAGE_STREAM *LANGUAGE_STDERR = (LANGUAGE_STREAM*)STDERR_FILENO;

LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stdin_stream(void)  { return LANGUAGE_STDIN; }
LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stdout_stream(void) { return LANGUAGE_STDOUT; }
LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stderr_stream(void) { return LANGUAGE_STDERR; }

LANGUAGE_DLLEXPORT int language_termios_size(void) {
#if defined(_OS_WINDOWS_)
    return 0;
#else
    return sizeof(struct termios);
#endif
}

// -- processor native alignment information --

LANGUAGE_DLLEXPORT void language_native_alignment(uint_t *int8align, uint_t *int16align, uint_t *int32align,
                                      uint_t *int64align, uint_t *float32align, uint_t *float64align)
{
    *int8align = __alignof(uint8_t);
    *int16align = __alignof(uint16_t);
    *int32align = __alignof(uint32_t);
    *int64align = __alignof(uint64_t);
    *float32align = __alignof(float);
    *float64align = __alignof(double);
}

LANGUAGE_DLLEXPORT language_value_t *language_is_char_signed(void)
{
    return ((char)255) < 0 ? language_true : language_false;
}

// -- misc sysconf info --

#ifdef _OS_WINDOWS_
static long cachedPagesize = 0;
LANGUAGE_DLLEXPORT long language_getpagesize(void)
{
    if (!cachedPagesize) {
        SYSTEM_INFO systemInfo;
        GetSystemInfo (&systemInfo);
        cachedPagesize = systemInfo.dwPageSize;
    }
    return cachedPagesize;
}
#else
LANGUAGE_DLLEXPORT long language_getpagesize(void)
{
    long page_size = sysconf(_SC_PAGESIZE);
    assert(page_size != -1);
    return page_size;
}
#endif

#ifdef _OS_WINDOWS_
static long cachedAllocationGranularity = 0;
LANGUAGE_DLLEXPORT long language_getallocationgranularity(void) LANGUAGE_NOTSAFEPOINT
{
    if (!cachedAllocationGranularity) {
        SYSTEM_INFO systemInfo;
        GetSystemInfo (&systemInfo);
        cachedAllocationGranularity = systemInfo.dwAllocationGranularity;
    }
    return cachedAllocationGranularity;
}
#else
LANGUAGE_DLLEXPORT long language_getallocationgranularity(void) LANGUAGE_NOTSAFEPOINT
{
    return language_getpagesize();
}
#endif

LANGUAGE_DLLEXPORT long language_SC_CLK_TCK(void)
{
#ifndef _OS_WINDOWS_
    return sysconf(_SC_CLK_TCK);
#else
    return 1000; /* uv_cpu_info returns times in ms on Windows */
#endif
}

#ifdef _OS_OPENBSD_
// Helper for language_pathname_for_handle()
struct dlinfo_data {
    void       *searched;
    const char *result;
};

static int dlinfo_helper(struct dl_phdr_info *info, size_t size, void *vdata)
{
    struct dlinfo_data *data = (struct dlinfo_data *)vdata;
    void *handle;

    /* ensure dl_phdr_info at compile-time to be compatible with the one at runtime */
    if (sizeof(*info) < size)
        return -1;

    /* dlopen the name */
    handle = dlopen(info->dlpi_name, RTLD_LAZY | RTLD_NOLOAD);
    if (handle == NULL)
        return 0;

    /* check if the opened library is the same as the searched handle */
    if (data->searched == handle)
        data->result = info->dlpi_name;

    dlclose(handle);

    /* continue if still not found */
    return (data->result != NULL);
}
#endif

// Takes a handle (as returned from dlopen()) and returns the absolute path to the image loaded
LANGUAGE_DLLEXPORT const char *language_pathname_for_handle(void *handle)
{
    if (!handle)
        return NULL;

#ifdef __APPLE__
    // Iterate through all images currently in memory
    for (int32_t i = _dyld_image_count() - 1; i >= 0 ; i--) {
        // dlopen() each image, check handle
        const char *image_name = _dyld_get_image_name(i);
        void *probe_lib = language_load_dynamic_library(image_name, LANGUAGE_RTLD_DEFAULT | LANGUAGE_RTLD_NOLOAD, 0);
        language_dlclose(probe_lib);

        // If the handle is the same as what was passed in (modulo mode bits), return this image name
        if (((intptr_t)handle & (-4)) == ((intptr_t)probe_lib & (-4)))
            return image_name;
    }

#elif defined(_OS_WINDOWS_)

    wchar_t *pth16 = (wchar_t*)malloc_s(32768 * sizeof(*pth16)); // max long path length
    DWORD n16 = GetModuleFileNameW((HMODULE)handle, pth16, 32768);
    if (n16 <= 0) {
        free(pth16);
        return NULL;
    }
    pth16[n16] = L'\0';
    DWORD n8 = WideCharToMultiByte(CP_UTF8, 0, pth16, -1, NULL, 0, NULL, NULL);
    if (n8 == 0) {
        free(pth16);
        return NULL;
    }
    char *filepath = (char*)malloc_s(++n8);
    if (!WideCharToMultiByte(CP_UTF8, 0, pth16, -1, filepath, n8, NULL, NULL)) {
        free(pth16);
        free(filepath);
        return NULL;
    }
    free(pth16);
    return filepath;

#elif defined(_OS_OPENBSD_)
    struct dlinfo_data data = {
        .searched = handle,
        .result = NULL,
    };
    dl_iterate_phdr(&dlinfo_helper, &data);
    return data.result;

#else // Linux, FreeBSD, ...

    struct link_map *map;
    dlinfo(handle, RTLD_DI_LINKMAP, &map);
#ifdef _COMPILER_MSAN_ENABLED_
    __msan_unpoison(&map,sizeof(struct link_map*));
    if (map) {
        __msan_unpoison(map, sizeof(struct link_map));
        __msan_unpoison_string(map->l_name);
    }
#endif
    if (map)
        return map->l_name;

#endif
    return NULL;
}

#ifdef _OS_WINDOWS_
// Get a list of all the modules in this process.
LANGUAGE_DLLEXPORT int language_dllist(language_array_t *list)
{
    DWORD cb, cbNeeded;
    HMODULE *hMods = NULL;
    unsigned int i;
    cbNeeded = 1024 * sizeof(*hMods);
    do {
        cb = cbNeeded;
        hMods = (HMODULE*)realloc_s(hMods, cb);
        if (!EnumProcessModulesEx(GetCurrentProcess(), hMods, cb, &cbNeeded, LIST_MODULES_ALL)) {
          free(hMods);
          return FALSE;
        }
    } while (cb < cbNeeded);
    for (i = 0; i < cbNeeded / sizeof(HMODULE); i++) {
        const char *path = language_pathname_for_handle(hMods[i]);
        if (path == NULL)
            continue;
        language_array_grow_end((language_array_t*)list, 1);
        language_value_t *v = language_cstr_to_string(path);
        free((char*)path);
        language_array_ptr_set(list, language_array_dim0(list) - 1, v);
    }
    free(hMods);
    return TRUE;
}
#endif

LANGUAGE_DLLEXPORT void language_raise_debugger(void)
{
#if defined(_OS_WINDOWS_)
    if (IsDebuggerPresent() == 1)
        DebugBreak();
#else
    raise(SIGTRAP);
#endif // _OS_WINDOWS_
}

LANGUAGE_DLLEXPORT language_sym_t *language_get_UNAME(void) LANGUAGE_NOTSAFEPOINT
{
    return language_symbol(LANGUAGE_BUILD_UNAME);
}

LANGUAGE_DLLEXPORT language_sym_t *language_get_ARCH(void) LANGUAGE_NOTSAFEPOINT
{
    return language_symbol(LANGUAGE_BUILD_ARCH);
}

LANGUAGE_DLLEXPORT size_t language_maxrss(void)
{
#if defined(_OS_WINDOWS_)
    PROCESS_MEMORY_COUNTERS counter;
    GetProcessMemoryInfo( GetCurrentProcess( ), &counter, sizeof(counter) );
    return (size_t)counter.PeakWorkingSetSize;

// FIXME: `rusage` is available on OpenBSD, DragonFlyBSD and NetBSD as well.
//        All of them return `ru_maxrss` in kilobytes.
#elif defined(_OS_LINUX_) || defined(_OS_DARWIN_) || defined (_OS_FREEBSD_) || defined (_OS_OPENBSD_)
    struct rusage rusage;
    getrusage( RUSAGE_SELF, &rusage );

#if defined(_OS_LINUX_) || defined(_OS_FREEBSD_) || defined (_OS_OPENBSD_)
    return (size_t)(rusage.ru_maxrss * 1024);
#else
    return (size_t)rusage.ru_maxrss;
#endif

#else
    return (size_t)0;
#endif
}

// Simple `rand()` like function, with global seed and added thread-safety
// (but slow and insecure)
static _Atomic(uint64_t) g_rngseed;
LANGUAGE_DLLEXPORT uint64_t language_rand(void) LANGUAGE_NOTSAFEPOINT
{
    uint64_t max = UINT64_MAX;
    uint64_t rngseed0 = language_atomic_load_relaxed(&g_rngseed);
    uint64_t rngseed;
    uint64_t rnd;
    do {
        rngseed = rngseed0;
        rnd = cong(max, &rngseed);
    } while (!language_atomic_cmpswap_relaxed(&g_rngseed, &rngseed0, rngseed));
    return rnd;
}

LANGUAGE_DLLEXPORT void language_srand(uint64_t rngseed) LANGUAGE_NOTSAFEPOINT
{
    language_atomic_store_relaxed(&g_rngseed, rngseed);
}

void language_init_rand(void) LANGUAGE_NOTSAFEPOINT
{
    uint64_t rngseed;
    if (uv_random(NULL, NULL, &rngseed, sizeof(rngseed), 0, NULL)) {
        ios_puts("WARNING: Entropy pool not available to seed RNG; using ad-hoc entropy sources.\n", ios_stderr);
        rngseed = uv_hrtime();
        rngseed ^= int64hash(uv_os_getpid());
    }
    language_srand(rngseed);
    srand(rngseed);
}

#ifdef __cplusplus
}
#endif
