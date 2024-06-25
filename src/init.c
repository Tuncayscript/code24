/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: System Initialization and Global State

#include "platform.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h> // defines dirname

#if !defined(_OS_WINDOWS_) || defined(_COMPILER_GCC_)
#include <getopt.h>
#endif

#if defined(_OS_FREEBSD_)
#include <pthread_np.h>
#endif

#include "code.h"
#include "language_internal.h"
#define DEFINE_BUILTIN_GLOBALS
#include "builtin_proto.h"
#undef DEFINE_BUILTIN_GLOBALS
#include "threading.h"
#include "language_assert.h"
#include "processor.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _OS_WINDOWS_
extern int needsSymRefreshModuleList;
extern BOOL (WINAPI *hSymRefreshModuleList)(HANDLE);
#else
#include <sys/resource.h>
#include <unistd.h>
#endif

// list of modules being deserialized with __init__ methods
language_array_t *language_module_init_order;

LANGUAGE_DLLEXPORT size_t language_page_size;

void language_init_stack_limits(int ismaster, void **stack_lo, void **stack_hi)
{
#ifdef _OS_WINDOWS_
    (void)ismaster;
    // https://en.wikipedia.org/wiki/Win32_Thread_Information_Block
#  ifdef _P64
    *stack_hi = (void**)__readgsqword(0x08); // Stack Base / Bottom of stack (high address)
    *stack_lo = (void**)__readgsqword(0x10); // Stack Limit / Ceiling of stack (low address)
#  else // !_P64
    *stack_hi = (void**)__readfsdword(0x04); // Stack Base / Bottom of stack (high address)
    *stack_lo = (void**)__readfsdword(0x08); // Stack Limit / Ceiling of stack (low address)
#  endif // _P64
#else // !_OS_WINDOWS_
    // Only use pthread_*_np functions to get stack address for non-master
    // threads since it seems to return bogus values for master thread on Linux
    // and possibly OSX.
    if (!ismaster) {
#  if defined(_OS_LINUX_)
        pthread_attr_t attr;
        pthread_getattr_np(pthread_self(), &attr);
        void *stackaddr;
        size_t stacksize;
        pthread_attr_getstack(&attr, &stackaddr, &stacksize);
        pthread_attr_destroy(&attr);
        *stack_hi = stackaddr;
        *stack_lo = (char*)stackaddr - stacksize;
        return;
#  elif defined(_OS_DARWIN_)
        extern void *pthread_get_stackaddr_np(pthread_t thread);
        extern size_t pthread_get_stacksize_np(pthread_t thread);
        pthread_t thread = pthread_self();
        void *stackaddr = pthread_get_stackaddr_np(thread);
        size_t stacksize = pthread_get_stacksize_np(thread);
        *stack_hi = stackaddr;
        *stack_lo = (char*)stackaddr - stacksize;
        return;
#  elif defined(_OS_FREEBSD_)
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_get_np(pthread_self(), &attr);
        void *stackaddr;
        size_t stacksize;
        pthread_attr_getstack(&attr, &stackaddr, &stacksize);
        pthread_attr_destroy(&attr);
        *stack_hi = stackaddr;
        *stack_lo = (char*)stackaddr - stacksize;
        return;
#  else
#      warning "Getting precise stack size for thread is not supported."
#  endif
    }
    struct rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    size_t stacksize = rl.rlim_cur;
    *stack_hi = __builtin_frame_address(0);
    *stack_lo = (void*)((char*)*stack_hi - stacksize);
#endif
}

static void language_prep_sanitizers(void)
{
#if !defined(_OS_WINDOWS_)
#if defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_MSAN_ENABLED_)
    struct rlimit rl;

    // When using the sanitizers, increase stack size because they bloat
    // stack usage
    const rlim_t kStackSize = 64 * 1024 * 1024;   // 64MiB stack
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
#endif
#endif
}

struct uv_shutdown_queue_item { uv_handle_t *h; struct uv_shutdown_queue_item *next; };
struct uv_shutdown_queue { struct uv_shutdown_queue_item *first; struct uv_shutdown_queue_item *last; };

static void language_uv_exitcleanup_add(uv_handle_t *handle, struct uv_shutdown_queue *queue)
{
    struct uv_shutdown_queue_item *item = (struct uv_shutdown_queue_item*)malloc_s(sizeof(struct uv_shutdown_queue_item));
    item->h = handle;
    item->next = NULL;
    if (queue->last)
        queue->last->next = item;
    if (!queue->first)
        queue->first = item;
    queue->last = item;
}

static void language_uv_exitcleanup_walk(uv_handle_t *handle, void *arg)
{
    language_uv_exitcleanup_add(handle, (struct uv_shutdown_queue*)arg);
}

static struct uv_shutdown_queue_item *next_shutdown_queue_item(struct uv_shutdown_queue_item *item)
{
    struct uv_shutdown_queue_item *rv = item->next;
    free(item);
    return rv;
}

static void language_close_item_atexit(uv_handle_t *handle)
{
    if (handle->type != UV_FILE && uv_is_closing(handle))
        return;
    switch(handle->type) {
    case UV_PROCESS:
        // cause Julia to forget about the Process object
        handle->data = NULL;
        // and make libuv think it is already dead
        ((uv_process_t*)handle)->pid = 0;
        // fall-through
    case UV_TTY:
    case UV_UDP:
    case UV_TCP:
    case UV_NAMED_PIPE:
    case UV_POLL:
    case UV_TIMER:
    case UV_ASYNC:
    case UV_FS_EVENT:
    case UV_FS_POLL:
    case UV_IDLE:
    case UV_PREPARE:
    case UV_CHECK:
    case UV_SIGNAL:
    case UV_FILE:
        // These will be shutdown as appropriate by language_close_uv
        language_close_uv(handle);
        break;
    case UV_HANDLE:
    case UV_STREAM:
    default:
        assert(0 && "not a valid libuv handle");
    }
}

// This prevents `ct` from returning via error handlers or other unintentional
// means by destroying some old state before we start destroying that state in atexit hooks.
void language_task_frame_noreturn(language_task_t *ct) LANGUAGE_NOTSAFEPOINT;

// cause this process to exit with WEXITSTATUS(signo), after waiting to finish all julia, C, and C++ cleanup
LANGUAGE_DLLEXPORT void language_exit(int exitcode)
{
    language_atexit_hook(exitcode);
    exit(exitcode);
}

// cause this process to exit with WTERMSIG(signo),
// fairly aggressively (flushing stderr a bit, and doing a little bit of other
// external cleanup, but no internal cleanup)
LANGUAGE_DLLEXPORT void language_raise(int signo)
{
    uv_tty_reset_mode();
    fflush(NULL);
#ifdef _OS_WINDOWS_
    if (signo == SIGABRT) {
        signal(signo, SIG_DFL);
        abort();
    }
    // the exit status could also potentially be set to an NTSTATUS value
    // corresponding to a signal number, but this seems somewhat is uncommon on Windows
    TerminateProcess(GetCurrentProcess(), 3); // aka _exit
    abort(); // prior call does not return, because we passed GetCurrentProcess()
#else
    signal(signo, SIG_DFL);
    sigset_t sset;
    sigemptyset(&sset);
    sigaddset(&sset, signo);
    pthread_sigmask(SIG_UNBLOCK, &sset, NULL);
    raise(signo); // aka pthread_kill(pthread_self(), signo);
    if (signo == SIGABRT)
        abort();
    _exit(128 + signo);
#endif
}

LANGUAGE_DLLEXPORT void language_atexit_hook(int exitcode) LANGUAGE_NOTSAFEPOINT_ENTER
{
    uv_tty_reset_mode();

    if (language_atomic_load_relaxed(&language_all_tls_states) == NULL)
        return;

    language_task_t *ct = language_get_current_task();

    if (ct == NULL && language_base_module) {
        ct = container_of(language_adopt_thread(), language_task_t, gcstack);
    }
    else if (ct != NULL) {
        // we are about to start tearing everything down, so lets try not to get
        // upset by the local mess of things when we run the user's _atexit hooks
        // this also forces us into a GC-unsafe region without a safepoint
        language_task_frame_noreturn(ct);
        language_gc_safepoint_(ct->ptls);
    }

    if (language_base_module) {
        language_value_t *f = language_get_global(language_base_module, language_symbol("_atexit"));
        if (f != NULL) {
            language_value_t **fargs;
            LANGUAGE_GC_PUSHARGS(fargs, 2);
            fargs[0] = f;
            fargs[1] = language_box_int32(exitcode);
            LANGUAGE_TRY {
                assert(ct);
                size_t last_age = ct->world_age;
                ct->world_age = language_get_world_counter();
                language_apply(fargs, 2);
                ct->world_age = last_age;
            }
            LANGUAGE_CATCH {
                language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\natexit hook threw an error: ");
                language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
                language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
                languagebacktrace(); // written to STDERR_FILENO
            }
            LANGUAGE_GC_POP();
        }
    }

    if (ct && exitcode == 0)
        language_write_compiler_output();

    language_print_gc_stats(LANGUAGE_STDERR);
    if (language_options.code_coverage)
        language_write_coverage_data(language_options.output_code_coverage);
    if (language_options.malloc_log)
        language_write_malloc_log();

    // replace standard output streams with something that we can still print to
    // after the finalizers from base/stream.language close the TTY
    LANGUAGE_STDOUT = (uv_stream_t*) STDOUT_FILENO;
    LANGUAGE_STDERR = (uv_stream_t*) STDERR_FILENO;

    if (ct)
        language_gc_run_all_finalizers(ct);

    uv_loop_t *loop = language_global_event_loop();
    if (loop != NULL) {
        struct uv_shutdown_queue queue = {NULL, NULL};
        LANGUAGE_UV_LOCK();
        uv_walk(loop, language_uv_exitcleanup_walk, &queue);
        struct uv_shutdown_queue_item *item = queue.first;
        if (ct) {
            while (item) {
                LANGUAGE_TRY {
                    while (item) {
                        language_close_item_atexit(item->h);
                        item = next_shutdown_queue_item(item);
                    }
                }
                LANGUAGE_CATCH {
                    //error handling -- continue cleanup, as much as possible
                    assert(item);
                    uv_unref(item->h);
                    language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "error during exit cleanup: close: ");
                    language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
                    language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
                    languagebacktrace(); // written to STDERR_FILENO
                    item = next_shutdown_queue_item(item);
                }
            }
        }
        else {
            while (item) {
                language_close_item_atexit(item->h);
                item = next_shutdown_queue_item(item);
            }
        }

        // force libuv to spin until everything has finished closing
        loop->stop_flag = 0;
        while (uv_run(loop, UV_RUN_DEFAULT)) { }
        language_wake_libuv(); // set the async pending flag, so that future calls are immediate no-ops on other threads
                         // we would like to guarantee this, but cannot currently, so there is still a small race window
                         // that needs to be fixed in libuv
    }
    if (ct)
        (void)language_gc_safe_enter(ct->ptls); // park in gc-safe
    if (loop != NULL) {
        // TODO: consider uv_loop_close(loop) here, before shutdown?
        uv_library_shutdown();
        // no LANGUAGE_UV_UNLOCK(), since it is now torn down
    }

    // TODO: Destroy threads?

    language_destroy_timing(); // cleans up the current timing_stack for noreturn
#ifdef USE_TIMING_COUNTS
    language_print_timings();
#endif
    language_teardown_codegen(); // prints stats
}

LANGUAGE_DLLEXPORT void language_postoutput_hook(void)
{
    if (language_atomic_load_relaxed(&language_all_tls_states) == NULL)
        return;

    if (language_base_module) {
        language_task_t *ct = language_get_current_task();
        language_value_t *f = language_get_global(language_base_module, language_symbol("_postoutput"));
        if (f != NULL) {
            LANGUAGE_TRY {
                size_t last_age = ct->world_age;
                ct->world_age = language_get_world_counter();
                language_apply(&f, 1);
                ct->world_age = last_age;
            }
            LANGUAGE_CATCH {
                language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\npostoutput hook threw an error: ");
                language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
                language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
                languagebacktrace(); // written to STDERR_FILENO
            }
        }
    }
    return;
}

void post_boot_hooks(void);
void post_image_load_hooks(void);

LANGUAGE_DLLEXPORT void *language_libjulia_internal_handle;
LANGUAGE_DLLEXPORT void *language_libjulia_handle;
LANGUAGE_DLLEXPORT void *language_RTLD_DEFAULT_handle;
LANGUAGE_DLLEXPORT void *language_exe_handle;
#ifdef _OS_WINDOWS_
void *language_ntdll_handle;
void *language_kernel32_handle;
void *language_crtdll_handle;
void *language_winsock_handle;
extern const char *language_crtdll_name;
#endif

uv_loop_t *language_io_loop;

#ifdef _OS_WINDOWS_
static int uv_dup(uv_os_fd_t fd, uv_os_fd_t* dupfd) {
    HANDLE current_process;

    if (fd == UV_STDIN_FD || fd == UV_STDOUT_FD || fd == UV_STDERR_FD)
        fd = GetStdHandle((DWORD)(uintptr_t) fd);

    /* _get_osfhandle will sometimes return -2 in case of an error. This seems */
    /* to happen when fd <= 2 and the process' corresponding stdio handle is */
    /* set to NULL. Unfortunately DuplicateHandle will happily duplicate */
    /* (HANDLE) -2, so this situation goes unnoticed until someone tries to */
    /* use the duplicate. Therefore we filter out known-invalid handles here. */
    if (fd == INVALID_HANDLE_VALUE ||
        fd == NULL ||
        fd == (HANDLE) -2) {
        *dupfd = INVALID_HANDLE_VALUE;
        return 0; // allow the execution to continue even if stdio is not available as in batchmode or without a console
    }

    current_process = GetCurrentProcess();

    if (!DuplicateHandle(current_process,
                         fd,
                         current_process,
                         dupfd,
                         0,
                         TRUE,
                         DUPLICATE_SAME_ACCESS)) {
        *dupfd = INVALID_HANDLE_VALUE;
        return GetLastError();
    }

    return 0;
}
#else
static int uv_dup(uv_os_fd_t fd, uv_os_fd_t* dupfd) {
    if ((*dupfd = fcntl(fd, F_DUPFD_CLOEXEC, 3)) == -1)
        return -errno;
    return 0;
}
#endif

static void *init_stdio_handle(const char *stdio, uv_os_fd_t fd, int readable)
{
    void *handle;
    int err;
    // Duplicate the file descriptor so we can later dup it over if we want to redirect
    // STDIO without having to worry about closing the associated libuv object.
    // This also helps limit the impact other libraries can cause on our file handle.
    if ((err = uv_dup(fd, &fd)))
        language_errorf("error initializing %s in uv_dup: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
    switch(uv_guess_handle(fd)) {
    case UV_TTY:
        handle = malloc_s(sizeof(uv_tty_t));
        if ((err = uv_tty_init(language_io_loop, (uv_tty_t*)handle, fd, 0))) {
            language_errorf("error initializing %s in uv_tty_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_tty_t*)handle)->data = NULL;
        uv_tty_set_mode((uv_tty_t*)handle, UV_TTY_MODE_NORMAL); // initialized cooked stdio
        break;
    default:
        assert(0 && "missing case for uv_guess_handle return handling");
        LANGUAGE_FALLTHROUGH;
    case UV_UDP:
        LANGUAGE_FALLTHROUGH;
    case UV_UNKNOWN_HANDLE:
        // dup the descriptor with a new one pointing at the bit bucket ...
#if defined(_OS_WINDOWS_)
        CloseHandle(fd);
        fd = CreateFile("NUL", readable ? FILE_GENERIC_READ : FILE_GENERIC_WRITE | FILE_READ_ATTRIBUTES,
                FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
#else
        {
            int nullfd;
            nullfd = open("/dev/null", O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH /* 0666 */);
            assert(nullfd != -1);
            dup2(nullfd, fd);
            close(nullfd);
        }
#endif
        // ...and continue on as in the UV_FILE case
        LANGUAGE_FALLTHROUGH;
    case UV_FILE:
        handle = malloc_s(sizeof(language_uv_file_t));
        {
            language_uv_file_t *file = (language_uv_file_t*)handle;
            file->loop = language_io_loop;
            file->type = UV_FILE;
            file->file = fd;
            file->data = NULL;
        }
        break;
    case UV_NAMED_PIPE:
        handle = malloc_s(sizeof(uv_pipe_t));
        if ((err = uv_pipe_init(language_io_loop, (uv_pipe_t*)handle, 0))) {
            language_errorf("error initializing %s in uv_pipe_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        if ((err = uv_pipe_open((uv_pipe_t*)handle, fd))) {
            language_errorf("error initializing %s in uv_pipe_open: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_pipe_t*)handle)->data = NULL;
        break;
    case UV_TCP:
        handle = malloc_s(sizeof(uv_tcp_t));
        if ((err = uv_tcp_init(language_io_loop, (uv_tcp_t*)handle))) {
            language_errorf("error initializing %s in uv_tcp_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        if ((err = uv_tcp_open((uv_tcp_t*)handle, (uv_os_sock_t)fd))) {
            language_errorf("error initializing %s in uv_tcp_open: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_tcp_t*)handle)->data = NULL;
        break;
    }
    return handle;
}

static void init_stdio(void)
{
    LANGUAGE_STDIN  = (uv_stream_t*)init_stdio_handle("stdin", UV_STDIN_FD, 1);
    LANGUAGE_STDOUT = (uv_stream_t*)init_stdio_handle("stdout", UV_STDOUT_FD, 0);
    LANGUAGE_STDERR = (uv_stream_t*)init_stdio_handle("stderr", UV_STDERR_FD, 0);
    language_flush_cstdio();
}

int language_isabspath(const char *in) LANGUAGE_NOTSAFEPOINT
{
#ifdef _OS_WINDOWS_
    char c0 = in[0];
    if (c0 == '/' || c0 == '\\') {
        return 1; // absolute path relative to %CD% (current drive), or UNC
    }
    else if (c0 && in[1] == ':') {
        char c2 = in[2];
        return c2 == '/' || c2 == '\\'; // absolute path with drive name
    }
#else
    if (in[0] == '/') return 1; // absolute path
#endif
    return 0; // relative path
}

static char *absrealpath(const char *in, int nprefix)
{ // compute an absolute realpath location, so that chdir doesn't change the file reference
  // ignores (copies directly over) nprefix characters at the start of abspath
#ifndef _OS_WINDOWS_
    char *out = realpath(in + nprefix, NULL);
    if (out) {
        if (nprefix > 0) {
            size_t sz = strlen(out) + 1;
            char *cpy = (char*)malloc_s(sz + nprefix);
            memcpy(cpy, in, nprefix);
            memcpy(cpy + nprefix, out, sz);
            free(out);
            out = cpy;
        }
    }
    else {
        size_t sz = strlen(in + nprefix) + 1;
        if (in[nprefix] == PATHSEPSTRING[0]) {
            out = (char*)malloc_s(sz + nprefix);
            memcpy(out, in, sz + nprefix);
        }
        else {
            size_t path_size = LANGUAGE_PATH_MAX;
            char *path = (char*)malloc_s(LANGUAGE_PATH_MAX);
            if (uv_cwd(path, &path_size)) {
                language_error("fatal error: unexpected error while retrieving current working directory");
            }
            out = (char*)malloc_s(path_size + 1 + sz + nprefix);
            memcpy(out, in, nprefix);
            memcpy(out + nprefix, path, path_size);
            out[nprefix + path_size] = PATHSEPSTRING[0];
            memcpy(out + nprefix + path_size + 1, in + nprefix, sz);
            free(path);
        }
    }
#else
    // GetFullPathName intentionally errors if given an empty string so manually insert `.` to invoke cwd
    char *in2 = (char*)malloc_s(LANGUAGE_PATH_MAX);
    if (strlen(in) - nprefix == 0) {
        memcpy(in2, in, nprefix);
        in2[nprefix] = '.';
        in2[nprefix+1] = '\0';
        in = in2;
    }
    DWORD n = GetFullPathName(in + nprefix, 0, NULL, NULL);
    if (n <= 0) {
        language_error("fatal error: language_options.image_file path too long or GetFullPathName failed");
    }
    char *out = (char*)malloc_s(n + nprefix);
    DWORD m = GetFullPathName(in + nprefix, n, out + nprefix, NULL);
    if (n != m + 1) {
        language_error("fatal error: language_options.image_file path too long or GetFullPathName failed");
    }
    memcpy(out, in, nprefix);
    free(in2);
#endif
    return out;
}

// create an absolute-path copy of the input path format string
// formed as `joinpath(replace(pwd(), "%" => "%%"), in)`
// unless `in` starts with `%`
static const char *absformat(const char *in)
{
    if (in[0] == '%' || language_isabspath(in))
        return in;
    // get an escaped copy of cwd
    size_t path_size = LANGUAGE_PATH_MAX;
    char path[LANGUAGE_PATH_MAX];
    if (uv_cwd(path, &path_size)) {
        language_error("fatal error: unexpected error while retrieving current working directory");
    }
    size_t sz = strlen(in) + 1;
    size_t i, fmt_size = 0;
    for (i = 0; i < path_size; i++)
        fmt_size += (path[i] == '%' ? 2 : 1);
    char *out = (char*)malloc_s(fmt_size + 1 + sz);
    fmt_size = 0;
    for (i = 0; i < path_size; i++) { // copy-replace pwd portion
        char c = path[i];
        out[fmt_size++] = c;
        if (c == '%')
            out[fmt_size++] = '%';
    }
    out[fmt_size++] = PATHSEPSTRING[0]; // path sep
    memcpy(out + fmt_size, in, sz); // copy over format, including nul
    return out;
}

static void language_resolve_sysimg_location(LANGUAGE_IMAGE_SEARCH rel)
{
    // this function resolves the paths in language_options to absolute file locations as needed
    // and it replaces the pointers to `julia_bindir`, `julia_bin`, `image_file`, and output file paths
    // it may fail, print an error, and exit(1) if any of these paths are longer than LANGUAGE_PATH_MAX
    //
    // note: if you care about lost memory, you should call the appropriate `free()` function
    // on the original pointer for each `char*` you've inserted into `language_options`, after
    // calling `julia_init()`
    char *free_path = (char*)malloc_s(LANGUAGE_PATH_MAX);
    size_t path_size = LANGUAGE_PATH_MAX;
    if (uv_exepath(free_path, &path_size)) {
        language_error("fatal error: unexpected error while retrieving exepath");
    }
    if (path_size >= LANGUAGE_PATH_MAX) {
        language_error("fatal error: language_options.julia_bin path too long");
    }
    language_options.julia_bin = (char*)malloc_s(path_size + 1);
    memcpy((char*)language_options.julia_bin, free_path, path_size);
    ((char*)language_options.julia_bin)[path_size] = '\0';
    if (!language_options.julia_bindir) {
        language_options.julia_bindir = getenv("JULIA_BINDIR");
        if (!language_options.julia_bindir) {
            language_options.julia_bindir = dirname(free_path);
        }
    }
    if (language_options.julia_bindir)
        language_options.julia_bindir = absrealpath(language_options.julia_bindir, 0);
    free(free_path);
    free_path = NULL;
    if (language_options.image_file) {
        if (rel == LANGUAGE_IMAGE_JULIA_HOME && !language_isabspath(language_options.image_file)) {
            // build time path, relative to JULIA_BINDIR
            free_path = (char*)malloc_s(LANGUAGE_PATH_MAX);
            int n = snprintf(free_path, LANGUAGE_PATH_MAX, "%s" PATHSEPSTRING "%s",
                             language_options.julia_bindir, language_options.image_file);
            if (n >= LANGUAGE_PATH_MAX || n < 0) {
                language_error("fatal error: language_options.image_file path too long");
            }
            language_options.image_file = free_path;
        }
        if (language_options.image_file)
            language_options.image_file = absrealpath(language_options.image_file, 0);
        if (free_path) {
            free(free_path);
            free_path = NULL;
        }
    }
    if (language_options.outputo)
        language_options.outputo = absrealpath(language_options.outputo, 0);
    if (language_options.outputji)
        language_options.outputji = absrealpath(language_options.outputji, 0);
    if (language_options.outputbc)
        language_options.outputbc = absrealpath(language_options.outputbc, 0);
    if (language_options.outputasm)
        language_options.outputasm = absrealpath(language_options.outputasm, 0);
    if (language_options.machine_file)
        language_options.machine_file = absrealpath(language_options.machine_file, 0);
    if (language_options.output_code_coverage)
        language_options.output_code_coverage = absformat(language_options.output_code_coverage);
    if (language_options.tracked_path)
        language_options.tracked_path = absrealpath(language_options.tracked_path, 0);

    const char **cmdp = language_options.cmds;
    if (cmdp) {
        for (; *cmdp; cmdp++) {
            const char *cmd = *cmdp;
            if (cmd[0] == 'L') {
                *cmdp = absrealpath(cmd, 1);
            }
        }
    }
}

LANGUAGE_DLLEXPORT int language_is_file_tracked(language_sym_t *path)
{
    const char* path_ = language_symbol_name(path);
    int tpath_len = strlen(language_options.tracked_path);
    return (strlen(path_) >= tpath_len) && (strncmp(path_, language_options.tracked_path, tpath_len) == 0);
}

static void language_set_io_wait(int v)
{
    language_task_t *ct = language_current_task;
    ct->ptls->io_wait = v;
}

extern language_mutex_t language_modules_mutex;
extern language_mutex_t precomp_statement_out_lock;
extern language_mutex_t newly_inferred_mutex;
extern language_mutex_t global_roots_lock;
extern language_mutex_t profile_show_peek_cond_lock;

static void restore_fp_env(void)
{
    if (language_set_zero_subnormals(0) || language_set_default_nans(0)) {
        language_error("Failed to configure floating point environment");
    }
}

static NOINLINE void _finish_julia_init(LANGUAGE_IMAGE_SEARCH rel, language_ptls_t ptls, language_task_t *ct);

LANGUAGE_DLLEXPORT int language_default_debug_info_kind;

static void init_global_mutexes(void) {
    LANGUAGE_MUTEX_INIT(&language_modules_mutex, "language_modules_mutex");
    LANGUAGE_MUTEX_INIT(&precomp_statement_out_lock, "precomp_statement_out_lock");
    LANGUAGE_MUTEX_INIT(&newly_inferred_mutex, "newly_inferred_mutex");
    LANGUAGE_MUTEX_INIT(&global_roots_lock, "global_roots_lock");
    LANGUAGE_MUTEX_INIT(&language_codegen_lock, "language_codegen_lock");
    LANGUAGE_MUTEX_INIT(&typecache_lock, "typecache_lock");
    LANGUAGE_MUTEX_INIT(&profile_show_peek_cond_lock, "profile_show_peek_cond_lock");
}

LANGUAGE_DLLEXPORT void julia_init(LANGUAGE_IMAGE_SEARCH rel)
{
    // initialize many things, in no particular order
    // but generally running from simple platform things to optional
    // configuration features
    language_init_timing();
    // Make sure we finalize the tls callback before starting any threads.
    (void)language_get_pgcstack();

    // initialize backtraces
    language_init_profile_lock();
#ifdef _OS_WINDOWS_
    uv_mutex_init(&language_in_stackwalk);
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES | SYMOPT_IGNORE_CVREC);
    if (!SymInitialize(GetCurrentProcess(), "", 1)) {
        language_safe_printf("WARNING: failed to initialize stack walk info\n");
    }
    needsSymRefreshModuleList = 0;
#else
    // nongnu libunwind initialization is only threadsafe on architecture where the
    // author could access TSAN, per https://github.com/libunwind/libunwind/pull/109
    // so we need to do this once early (before threads)
    rec_backtrace(NULL, 0, 0);
#endif

    libsupport_init();
    language_safepoint_init();
    language_page_size = language_getpagesize();
    htable_new(&language_current_modules, 0);
    init_global_mutexes();
    language_precompile_toplevel_module = NULL;
    ios_set_io_wait_func = language_set_io_wait;
    language_io_loop = uv_default_loop(); // this loop will internal events (spawning process etc.),
                                    // best to call this first, since it also initializes libuv
    language_init_uv();
    init_stdio();
    restore_fp_env();
    if (language_options.handle_signals == LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON)
        restore_signals();

    language_init_intrinsic_properties();

    // Important offset for external codegen.
    language_task_gcstack_offset = offsetof(language_task_t, gcstack);
    language_task_ptls_offset = offsetof(language_task_t, ptls);

    language_prep_sanitizers();
    void *stack_lo, *stack_hi;
    language_init_stack_limits(1, &stack_lo, &stack_hi);

    language_libjulia_internal_handle = language_find_dynamic_library_by_addr(&language_load_dynamic_library);
    language_libjulia_handle = language_find_dynamic_library_by_addr(&language_any_type);
#ifdef _OS_WINDOWS_
    language_exe_handle = GetModuleHandleA(NULL);
    language_RTLD_DEFAULT_handle = language_libjulia_internal_handle;
    language_ntdll_handle = language_dlopen("ntdll.dll", LANGUAGE_RTLD_NOLOAD); // bypass julia's pathchecking for system dlls
    language_kernel32_handle = language_dlopen("kernel32.dll", LANGUAGE_RTLD_NOLOAD);
    language_crtdll_handle = language_dlopen(language_crtdll_name, LANGUAGE_RTLD_NOLOAD);
    language_winsock_handle = language_dlopen("ws2_32.dll", LANGUAGE_RTLD_NOLOAD);
    HMODULE language_dbghelp = (HMODULE) language_dlopen("dbghelp.dll", LANGUAGE_RTLD_NOLOAD);
    needsSymRefreshModuleList = 0;
    if (language_dbghelp)
        language_dlsym(language_dbghelp, "SymRefreshModuleList", (void **)&hSymRefreshModuleList, 1);
#else
    language_exe_handle = language_dlopen(NULL, LANGUAGE_RTLD_NOW);
#ifdef RTLD_DEFAULT
    language_RTLD_DEFAULT_handle = RTLD_DEFAULT;
#else
    language_RTLD_DEFAULT_handle = language_exe_handle;
#endif
#endif

    language_init_rand();
    language_init_runtime_ccall();
    language_init_tasks();
    language_init_threading();
    language_init_threadinginfra();
    if (language_options.handle_signals == LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON)
        language_install_default_signal_handlers();

    language_gc_init();

    arraylist_new(&language_linkage_blobs, 0);
    arraylist_new(&language_image_relocs, 0);
    arraylist_new(&language_top_mods, 0);
    arraylist_new(&eytzinger_image_tree, 0);
    arraylist_new(&eytzinger_idxs, 0);
    arraylist_push(&eytzinger_idxs, (void*)0);
    arraylist_push(&eytzinger_image_tree, (void*)1); // outside image

    language_ptls_t ptls = language_init_threadtls(0);
#pragma GCC diagnostic push
#if defined(_COMPILER_GCC_) && __GNUC__ >= 12
#pragma GCC diagnostic ignored "-Wdangling-pointer"
#endif
    // warning: this changes `language_current_task`, so be careful not to call that from this function
    language_task_t *ct = language_init_root_task(ptls, stack_lo, stack_hi);
#pragma GCC diagnostic pop
    LANGUAGE_GC_PROMISE_ROOTED(ct);
    _finish_julia_init(rel, ptls, ct);
}

static NOINLINE void _finish_julia_init(LANGUAGE_IMAGE_SEARCH rel, language_ptls_t ptls, language_task_t *ct)
{
    LANGUAGE_TIMING(JULIA_INIT, JULIA_INIT);
    language_resolve_sysimg_location(rel);
    // loads sysimg if available, and conditionally sets language_options.cpu_target
    if (rel == LANGUAGE_IMAGE_IN_MEMORY)
        language_set_sysimg_so(language_exe_handle);
    else if (language_options.image_file)
        language_preload_sysimg_so(language_options.image_file);
    if (language_options.cpu_target == NULL)
        language_options.cpu_target = "native";
    language_init_codegen();

    language_init_common_symbols();
    if (language_options.image_file) {
        language_restore_system_image(language_options.image_file);
    } else {
        language_init_types();
        language_global_roots_list = (language_genericmemory_t*)language_an_empty_memory_any;
        language_global_roots_keyset = (language_genericmemory_t*)language_an_empty_memory_any;
    }

    language_init_flisp();
    language_init_serializer();

    if (!language_options.image_file) {
        language_top_module = language_core_module;
        language_init_intrinsic_functions();
        language_init_primitives();
        language_init_main_module();
        language_load(language_core_module, "boot.language");
        post_boot_hooks();
    }

    if (language_base_module == NULL) {
        // nthreads > 1 requires code in Base
        language_atomic_store_relaxed(&language_n_threads, 1);
        language_n_markthreads = 0;
        language_n_sweepthreads = 0;
        language_n_gcthreads = 0;
        language_n_threads_per_pool[0] = 1;
        language_n_threads_per_pool[1] = 0;
    } else {
        post_image_load_hooks();
    }
    language_start_threads();

    language_gc_enable(1);

    if (language_options.image_file && (!language_generating_output() || language_options.incremental) && language_module_init_order) {
        language_array_t *init_order = language_module_init_order;
        LANGUAGE_GC_PUSH1(&init_order);
        language_module_init_order = NULL;
        int i, l = language_array_nrows(init_order);
        for (i = 0; i < l; i++) {
            language_value_t *mod = language_array_ptr_ref(init_order, i);
            language_module_run_initializer((language_module_t*)mod);
        }
        LANGUAGE_GC_POP();
    }

    if (language_options.handle_signals == LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON)
        language_install_sigint_handler();
}

#ifdef __cplusplus
}
#endif
