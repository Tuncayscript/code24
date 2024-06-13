#include "platform.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef _OS_WINDOWS_
#include <ws2tcpip.h>
#include <malloc.h>
#else
#include "errno.h"
#include <unistd.h>
#include <sys/socket.h>
#endif

#include "code.h"
#include "code_internal.h"
#include "support/ios.h"
#include "uv.h"

#include "code_assert.h"

#ifdef __cplusplus
#include <cstring>
extern "C" {
#endif

static uv_async_t signal_async;
static uv_timer_t wait_empty_worker;

static void walk_print_cb(uv_handle_t *h, void *arg)
{
    if (!uv_is_active(h) || !uv_has_ref(h))
        return;
    const char *type = uv_handle_type_name(h->type);
    if (!type)
        type = "<unknown>";
    size_t resource_id; // fits an int or pid_t on Unix, HANDLE or PID on Windows
    uv_os_fd_t fd;
    if (h->type == UV_PROCESS)
        resource_id = (size_t)uv_process_get_pid((uv_process_t*)h);
    else if (uv_fileno(h, &fd) == 0)
        resource_id = (size_t)fd;
    else
        resource_id = -1;
    const char *pad = "                "; // 16 spaces
    int npad = resource_id == -1 ? 0 : snprintf(NULL, 0, "%zd", resource_id);
    if (npad < 0)
        npad = 0;
    npad += strlen(type);
    pad += npad < strlen(pad) ? npad : strlen(pad);
    if (resource_id == -1)
        code_safe_printf(" %s   %s%p->%p\n", type,             pad, (void*)h, (void*)h->data);
    else
        code_safe_printf(" %s[%zd] %s%p->%p\n", type, resource_id, pad, (void*)h, (void*)h->data);
}

static void wait_empty_func(uv_timer_t *t)
{
    // make sure this is hidden now, since we would auto-unref it later
    uv_unref((uv_handle_t*)&signal_async);
    if (!uv_loop_alive(t->loop))
        return;
    code_safe_printf("\n[pid %zd] waiting for IO to finish:\n"
                   " Handle type        uv_handle_t->data\n",
                   (size_t)uv_os_getpid());
    uv_walk(code_io_loop, walk_print_cb, NULL);
    if (code_generating_output() && code_options.incremental) {
        code_safe_printf("This means that a package has started a background task or event source that has not finished running. For precompilation to complete successfully, the event source needs to be closed explicitly. See the developer documentation on fixing precompilation hangs for more help.\n");
    }
    code_gc_collect(CODE_GC_FULL);
}

void code_wait_empty_begin(void)
{
    CODE_UV_LOCK();
    if (code_io_loop) {
        if (wait_empty_worker.type != UV_TIMER) {
            // try to purge anything that is just waiting for cleanup
            code_io_loop->stop_flag = 0;
            uv_run(code_io_loop, UV_RUN_NOWAIT);
            uv_timer_init(code_io_loop, &wait_empty_worker);
            uv_unref((uv_handle_t*)&wait_empty_worker);
        }
        // make sure this is running
        uv_update_time(code_io_loop);
        uv_timer_start(&wait_empty_worker, wait_empty_func, 10, 15000);
    }
    CODE_UV_UNLOCK();
}
void code_wait_empty_end(void)
{
    // n.b. caller must be holding code_uv_mutex
    if (wait_empty_worker.type == UV_TIMER)
        // make sure this timer is stopped, but not destroyed in case the user calls code_wait_empty_begin again
        uv_timer_stop(&wait_empty_worker);
}



static void code_signal_async_cb(uv_async_t *hdl)
{
    // This should abort the current loop and the julia code it returns to
    // or the safepoint in the callers of `uv_run` should throw the exception.
    (void)hdl;
    uv_stop(code_io_loop);
}

void code_wake_libuv(void)
{
    uv_async_send(&signal_async);
}

code_mutex_t code_uv_mutex;

void code_init_uv(void)
{
    uv_async_init(code_io_loop, &signal_async, code_signal_async_cb);
    uv_unref((uv_handle_t*)&signal_async);
    CODE_MUTEX_INIT(&code_uv_mutex, "code_uv_mutex"); // a file-scope initializer can be used instead
}

_Atomic(int) code_uv_n_waiters = 0;

void CODE_UV_LOCK(void)
{
    if (code_mutex_trylock(&code_uv_mutex)) {
    }
    else {
        code_atomic_fetch_add_relaxed(&code_uv_n_waiters, 1);
        code_fence(); // [^store_buffering_2]
        code_wake_libuv();
        CODE_LOCK(&code_uv_mutex);
        code_atomic_fetch_add_relaxed(&code_uv_n_waiters, -1);
    }
}

/**
 * @brief Begin an IO lock.
 */
CODE_DLLEXPORT void code_iolock_begin(void)
{
    CODE_UV_LOCK();
}

/**
 * @brief End an IO lock.
 */
CODE_DLLEXPORT void code_iolock_end(void)
{
    CODE_UV_UNLOCK();
}


static void code_uv_call_close_callback(code_value_t *val)
{
    code_value_t **args;
    CODE_GC_PUSHARGS(args, 2); // val is "rooted" in the finalizer list only right now
    args[0] = code_get_global(code_base_relative_to(((code_datatype_t*)code_typeof(val))->name->module),
            code_symbol("_uv_hook_close")); // topmod(typeof(val))._uv_hook_close
    args[1] = val;
    assert(args[0]);
    code_apply(args, 2); // TODO: wrap in try-catch?
    CODE_GC_POP();
}

static void code_uv_closeHandle(uv_handle_t *handle)
{
    // if the user killed a stdio handle,
    // revert back to direct stdio FILE* writes
    // so that errors can still be reported
    if (handle == (uv_handle_t*)CODE_STDIN)
        CODE_STDIN = (CODE_STREAM*)STDIN_FILENO;
    if (handle == (uv_handle_t*)CODE_STDOUT)
        CODE_STDOUT = (CODE_STREAM*)STDOUT_FILENO;
    if (handle == (uv_handle_t*)CODE_STDERR)
        CODE_STDERR = (CODE_STREAM*)STDERR_FILENO;
    // also let the client app do its own cleanup
    if (handle->type != UV_FILE && handle->data) {
        code_task_t *ct = code_current_task;
        size_t last_age = ct->world_age;
        ct->world_age = code_atomic_load_acquire(&code_world_counter);
        code_uv_call_close_callback((code_value_t*)handle->data);
        ct->world_age = last_age;
        return;
    }
    if (handle == (uv_handle_t*)&wait_empty_worker)
        handle->type = UV_UNKNOWN_HANDLE;
    else if (handle == (uv_handle_t*)&signal_async)
        return;
    else
        free(handle);
}

static void code_uv_flush_close_callback(uv_write_t *req, int status)
{
    uv_stream_t *stream = req->handle;
    req->handle = NULL;
    // ignore attempts to close the stream while attempting a graceful shutdown
#ifdef _OS_WINDOWS_
    if (stream->stream.conn.shutdown_req)
#else
    if (stream->shutdown_req)
#endif
    {
        free(req);
        return;
    }
    if (uv_is_closing((uv_handle_t*)stream)) { // avoid double-close on the stream
        free(req);
        return;
    }
    if (status == 0 && uv_is_writable(stream) && stream->write_queue_size != 0) {
        // new data was written, wait for it to flush too
        uv_buf_t buf;
        buf.base = (char*)(req + 1);
        buf.len = 0;
        req->data = NULL;
        if (uv_write(req, stream, &buf, 1, (uv_write_cb)code_uv_flush_close_callback) == 0)
            return; // success
    }
    free(req);
    if (stream->type == UV_TTY)
        uv_tty_set_mode((uv_tty_t*)stream, UV_TTY_MODE_NORMAL);
    uv_close((uv_handle_t*)stream, &code_uv_closeHandle);
}

static void uv_flush_callback(uv_write_t *req, int status)
{
    *(int*)(req->data) = 1;
    uv_stop(req->handle->loop);
    free(req);
}

/**
 * @brief Flush a UV stream.
 *
 * Primarily used from C and gdb to convert a normal write operation on a UV stream
 * into a blocking write. It calls uv_run, which can have unbounded side-effects.
 * Caution is advised as the location from where this function is called is critical
 * due to the non-reentrancy of the libuv loop.
 *
 * @param stream A pointer to `uv_stream_t` representing the stream to flush.
 */
CODE_DLLEXPORT void code_uv_flush(uv_stream_t *stream)
{
    if (stream == (void*)STDIN_FILENO ||
        stream == (void*)STDOUT_FILENO ||
        stream == (void*)STDERR_FILENO)
        return;
    if (stream->type != UV_TTY &&
        stream->type != UV_TCP &&
        stream->type != UV_NAMED_PIPE)
        return;
    CODE_UV_LOCK();
    while (uv_is_writable(stream) && stream->write_queue_size != 0) {
        int fired = 0;
        uv_buf_t buf;
        buf.base = (char*)(&buf + 1);
        buf.len = 0;
        uv_write_t *write_req = (uv_write_t*)malloc_s(sizeof(uv_write_t));
        write_req->data = (void*)&fired;
        if (uv_write(write_req, stream, &buf, 1, uv_flush_callback) != 0) {
            CODE_UV_UNLOCK();
            return;
        }
        while (!fired) {
            uv_run(uv_default_loop(), UV_RUN_DEFAULT);
        }
    }
    CODE_UV_UNLOCK();
}

// getters and setters
// TODO: check if whoever calls these is thread-safe
/**
 * @brief Get the process ID of a UV process.
 *
 * @param p A pointer to `uv_process_t` representing the UV process.
 * @return The process ID.
 */
CODE_DLLEXPORT int code_uv_process_pid(uv_process_t *p) { return p->pid; }

/**
 * @brief Get the data associated with a UV process.
 *
 * @param p A pointer to `uv_process_t` representing the UV process.
 * @return A pointer to the process data.
 */
CODE_DLLEXPORT void *code_uv_process_data(uv_process_t *p) { return p->data; }

/**
 * @brief Get the base pointer of a UV buffer.
 *
 * @param buf A constant pointer to `uv_buf_t` representing the UV buffer.
 * @return A pointer to the base of the buffer.
 */
CODE_DLLEXPORT void *code_uv_buf_base(const uv_buf_t *buf) { return buf->base; }

/**
 * @brief Get the length of a UV buffer.
 *
 * @param buf A constant pointer to `uv_buf_t` representing the UV buffer.
 * @return The length of the buffer as `size_t`.
 */
CODE_DLLEXPORT size_t code_uv_buf_len(const uv_buf_t *buf) { return buf->len; }

/**
 * @brief Set the base pointer of a UV buffer.
 *
 * @param buf A pointer to `uv_buf_t` representing the UV buffer.
 * @param b A pointer to `char` representing the new base of the buffer.
 */
CODE_DLLEXPORT void code_uv_buf_set_base(uv_buf_t *buf, char *b) { buf->base = b; }

/**
 * @brief Set the length of a UV buffer.
 *
 * @param buf A pointer to `uv_buf_t` representing the UV buffer.
 * @param n The new length of the buffer as `size_t`.
 */
CODE_DLLEXPORT void code_uv_buf_set_len(uv_buf_t *buf, size_t n) { buf->len = n; }

/**
 * @brief Get the handle associated with a UV connect request.
 *
 * @param connect A pointer to `uv_connect_t` representing the connect request.
 * @return A pointer to the associated handle.
 */
CODE_DLLEXPORT void *code_uv_connect_handle(uv_connect_t *connect) { return connect->handle; }

/**
 * @brief Get the file descriptor from a UV file structure.
 *
 * @param f A pointer to `code_uv_file_t` representing the UV file.
 * @return The file descriptor as `uv_os_fd_t`.
 */
CODE_DLLEXPORT uv_os_fd_t code_uv_file_handle(code_uv_file_t *f) { return f->file; }

/**
 * @brief Get the data field from a UV request.
 *
 * @param req A pointer to `uv_req_t` representing the request.
 * @return A pointer to the data associated with the request.
 */
CODE_DLLEXPORT void *code_uv_req_data(uv_req_t *req) { return req->data; }

/**
 * @brief Set the data field of a UV request.
 *
 * @param req A pointer to `uv_req_t` representing the request.
 * @param data A pointer to the data to be associated with the request.
 */
CODE_DLLEXPORT void code_uv_req_set_data(uv_req_t *req, void *data) { req->data = data; }

/**
 * @brief Get the data field from a UV handle.
 *
 * @param handle A pointer to `uv_handle_t` representing the handle.
 * @return A pointer to the data associated with the handle.
 */
CODE_DLLEXPORT void *code_uv_handle_data(uv_handle_t *handle) { return handle->data; }

/**
 * @brief Get the handle associated with a UV write request.
 *
 * @param req A pointer to `uv_write_t` representing the write request.
 * @return A pointer to the handle associated with the write request.
 */
CODE_DLLEXPORT void *code_uv_write_handle(uv_write_t *req) { return req->handle; }

/**
 * @brief Process pending UV events.
 *
 * See also `uv_run` in the libuv documentation for status code enumeration.
 *
 * @return An integer indicating the status of the event processing.
 */
CODE_DLLEXPORT int code_process_events(void)
{
    code_task_t *ct = code_current_task;
    uv_loop_t *loop = code_io_loop;
    code_gc_safepoint_(ct->ptls);
    if (loop && (code_atomic_load_relaxed(&_threadedregion) || code_atomic_load_relaxed(&ct->tid) == code_atomic_load_relaxed(&io_loop_tid))) {
        if (code_atomic_load_relaxed(&code_uv_n_waiters) == 0 && code_mutex_trylock(&code_uv_mutex)) {
            CODE_PROBE_RT_START_PROCESS_EVENTS(ct);
            loop->stop_flag = 0;
            uv_ref((uv_handle_t*)&signal_async); // force the loop alive
            int r = uv_run(loop, UV_RUN_NOWAIT);
            uv_unref((uv_handle_t*)&signal_async);
            CODE_PROBE_RT_FINISH_PROCESS_EVENTS(ct);
            CODE_UV_UNLOCK();
            return r;
        }
        code_gc_safepoint_(ct->ptls);
    }
    return 0;
}

static void code_proc_exit_cleanup_cb(uv_process_t *process, int64_t exit_status, int term_signal)
{
    uv_close((uv_handle_t*)process, (uv_close_cb)&free);
}

/**
 * @brief Close a UV handle.
 *
 * @param handle A pointer to `uv_handle_t` that needs to be closed.
 */
CODE_DLLEXPORT void code_close_uv(uv_handle_t *handle)
{
    CODE_UV_LOCK();
    if (handle->type == UV_PROCESS && ((uv_process_t*)handle)->pid != 0) {
        // take ownership of this handle,
        // so we can waitpid for the resource to exit and avoid leaving zombies
        assert(handle->data == NULL); // make sure Julia has forgotten about it already
        ((uv_process_t*)handle)->exit_cb = code_proc_exit_cleanup_cb;
        uv_unref(handle);
    }
    else if (handle->type == UV_FILE) {
        uv_fs_t req;
        code_uv_file_t *fd = (code_uv_file_t*)handle;
        if ((ssize_t)fd->file != -1) {
            uv_fs_close(handle->loop, &req, fd->file, NULL);
            fd->file = (uv_os_fd_t)(ssize_t)-1;
        }
        code_uv_closeHandle(handle); // synchronous (ok since the callback is known to not interact with any global state)
    }
    else if (!uv_is_closing(handle)) { // avoid double-closing the stream
        if (handle->type == UV_NAMED_PIPE || handle->type == UV_TCP || handle->type == UV_TTY) {
            // flush the stream write-queue first
            uv_write_t *req = (uv_write_t*)malloc_s(sizeof(uv_write_t));
            req->handle = (uv_stream_t*)handle;
            code_uv_flush_close_callback(req, 0);
        }
        else {
            uv_close(handle, &code_uv_closeHandle);
        }
    }
    CODE_UV_UNLOCK();
}

/**
 * @brief Forcefully close a UV handle.
 *
 * @param handle A pointer to `uv_handle_t` to be forcefully closed.
 */
CODE_DLLEXPORT void code_forceclose_uv(uv_handle_t *handle)
{
    if (!uv_is_closing(handle)) { // avoid double-closing the stream
        CODE_UV_LOCK();
        if (!uv_is_closing(handle)) { // double-check
            uv_close(handle, &code_uv_closeHandle);
        }
        CODE_UV_UNLOCK();
    }
}

/**
 * @brief Associate a Julia structure with a UV handle.
 *
 * @param handle A pointer to `uv_handle_t` to be associated with a Julia structure.
 * @param data Additional parameters representing the Julia structure to be associated.
 */
CODE_DLLEXPORT void code_uv_associate_julia_struct(uv_handle_t *handle,
                                               code_value_t *data)
{
    handle->data = data;
}

/**
 * @brief Disassociate a Julia structure from a UV handle.
 *
 * @param handle A pointer to `uv_handle_t` from which the Julia structure will be disassociated.
 */
CODE_DLLEXPORT void code_uv_disassociate_julia_struct(uv_handle_t *handle)
{
    handle->data = NULL;
}

#define UV_HANDLE_CLOSED 0x02

/**
 * @brief Spawn a new process.
 *
 * Spawns a new process to execute external programs or scripts within the context of the Julia application.
 *
 * @param name A C string representing the name or path of the executable to spawn.
 * @param argv An array of C strings representing the arguments for the process. The array should be null-terminated.
 * @param loop A pointer to `uv_loop_t` representing the event loop where the process is registered.
 * @param proc A pointer to `uv_process_t` where the details of the spawned process are stored.
 * @param stdio An array of `uv_stdio_container_t` representing the file descriptors for standard input, output, and error.
 * @param nstdio An integer representing the number of elements in the stdio array.
 * @param flags A uint32_t representing process creation flags.
          See also `enum uv_process_flags` in the libuv documentation.
 * @param env An array of C strings for setting environment variables. The array should be null-terminated.
 * @param cwd A C string representing the current working directory for the process.
 * @param cpumask A C string representing the CPU affinity mask for the process.
          See also the `cpumask` field of the `uv_process_options_t` structure in the libuv documentation.
 * @param cpumask_size The size of the cpumask.
 * @param cb A function pointer to `uv_exit_cb` which is the callback function to be called upon process exit.
 *
 * @return An integer indicating the success or failure of the spawn operation. A return value of 0 indicates success,
 *         while a non-zero value indicates an error.
 */
CODE_DLLEXPORT int code_spawn(char *name, char **argv,
                          uv_loop_t *loop, uv_process_t *proc,
                          uv_stdio_container_t *stdio, int nstdio,
                          uint32_t flags, char **env, char *cwd, char* cpumask,
                          size_t cpumask_size, uv_exit_cb cb)
{
    uv_process_options_t opts = {0};
    opts.stdio = stdio;
    opts.file = name;
    opts.env = env;
    opts.flags = flags;
    // unused fields:
    //opts.uid = 0;
    //opts.gid = 0;
    opts.cpumask = cpumask;
    opts.cpumask_size = cpumask_size;
    opts.cwd = cwd;
    opts.args = argv;
    opts.stdio_count = nstdio;
    while (nstdio--) {
        int flags = opts.stdio[nstdio].flags;
        if (!(flags == UV_INHERIT_FD || flags == UV_INHERIT_STREAM || flags == UV_IGNORE)) {
            proc->type = UV_PROCESS;
            proc->loop = loop;
            proc->flags = UV_HANDLE_CLOSED;
            return UV_EINVAL;
        }
    }
    opts.exit_cb = cb;
    CODE_UV_LOCK();
    int r = uv_spawn(loop, proc, &opts);
    CODE_UV_UNLOCK();
    return r;
}

#ifdef _OS_WINDOWS_
#include <time.h>
CODE_DLLEXPORT struct tm *localtime_r(const time_t *t, struct tm *tm)
{
    struct tm *tmp = localtime(t); //localtime is reentrant on windows
    if (tmp)
        *tm = *tmp;
    return tmp;
}
#endif

CODE_DLLEXPORT uv_loop_t *code_global_event_loop(void)
{
    return code_io_loop;
}

CODE_DLLEXPORT int code_fs_unlink(char *path)
{
    uv_fs_t req;
    CODE_SIGATOMIC_BEGIN();
    int ret = uv_fs_unlink(unused_uv_loop_arg, &req, path, NULL);
    uv_fs_req_cleanup(&req);
    CODE_SIGATOMIC_END();
    return ret;
}

CODE_DLLEXPORT int code_fs_rename(const char *src_path, const char *dst_path)
{
    uv_fs_t req;
    CODE_SIGATOMIC_BEGIN();
    int ret = uv_fs_rename(unused_uv_loop_arg, &req, src_path, dst_path, NULL);
    uv_fs_req_cleanup(&req);
    CODE_SIGATOMIC_END();
    return ret;
}

CODE_DLLEXPORT int code_fs_sendfile(uv_os_fd_t src_fd, uv_os_fd_t dst_fd,
                                int64_t in_offset, size_t len)
{
    uv_fs_t req;
    CODE_SIGATOMIC_BEGIN();
    int ret = uv_fs_sendfile(unused_uv_loop_arg, &req, dst_fd, src_fd,
                             in_offset, len, NULL);
    uv_fs_req_cleanup(&req);
    CODE_SIGATOMIC_END();
    return ret;
}

CODE_DLLEXPORT int code_fs_hardlink(char *path, char *new_path)
{
    uv_fs_t req;
    int ret = uv_fs_link(unused_uv_loop_arg, &req, path, new_path, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_symlink(char *path, char *new_path, int flags)
{
    uv_fs_t req;
    int ret = uv_fs_symlink(unused_uv_loop_arg, &req, path, new_path, flags, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_chmod(char *path, int mode)
{
    uv_fs_t req;
    int ret = uv_fs_chmod(unused_uv_loop_arg, &req, path, mode, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_chown(char *path, int uid, int gid)
{
    uv_fs_t req;
    int ret = uv_fs_chown(unused_uv_loop_arg, &req, path, uid, gid, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_access(char *path, int mode)
{
    uv_fs_t req;
    int ret = uv_fs_access(unused_uv_loop_arg, &req, path, mode, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_write(uv_os_fd_t handle, const char *data, size_t len,
                             int64_t offset) CODE_NOTSAFEPOINT
{
    code_task_t *ct = code_get_current_task();
    // TODO: fix this cheating
    if (code_get_safe_restore() || ct == NULL || code_atomic_load_relaxed(&ct->tid) != code_atomic_load_relaxed(&io_loop_tid))
#ifdef _OS_WINDOWS_
        return WriteFile(handle, data, len, NULL, NULL);
#else
        return write(handle, data, len);
#endif
    uv_fs_t req;
    uv_buf_t buf[1];
    buf[0].base = (char*)data;
    buf[0].len = len;
    if (!code_io_loop)
        code_io_loop = uv_default_loop();
    int ret = uv_fs_write(unused_uv_loop_arg, &req, handle, buf, 1, offset, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_read(uv_os_fd_t handle, char *data, size_t len)
{
    uv_fs_t req;
    uv_buf_t buf[1];
    buf[0].base = data;
    buf[0].len = len;
    int ret = uv_fs_read(unused_uv_loop_arg, &req, handle, buf, 1, -1, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_fs_close(uv_os_fd_t handle)
{
    uv_fs_t req;
    int ret = uv_fs_close(unused_uv_loop_arg, &req, handle, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

CODE_DLLEXPORT int code_uv_write(uv_stream_t *stream, const char *data, size_t n,
                             uv_write_t *uvw, uv_write_cb writecb)
{
    uv_buf_t buf[1];
    buf[0].base = (char*)data;
    buf[0].len = n;
    CODE_UV_LOCK();
    CODE_SIGATOMIC_BEGIN();
    int err = uv_write(uvw, stream, buf, 1, writecb);
    CODE_UV_UNLOCK();
    CODE_SIGATOMIC_END();
    return err;
}

static void code_uv_writecb(uv_write_t *req, int status) CODE_NOTSAFEPOINT
{
    free(req);
    if (status < 0) {
        code_safe_printf("code_uv_writecb() ERROR: %s %s\n",
                       uv_strerror(status), uv_err_name(status));
    }
}

CODE_DLLEXPORT void code_uv_puts(uv_stream_t *stream, const char *str, size_t n)
{
    assert(stream);
    static_assert(offsetof(uv_stream_t,type) == offsetof(ios_t,bm) &&
        sizeof(((uv_stream_t*)0)->type) == sizeof(((ios_t*)0)->bm),
            "UV and ios layout mismatch");

    uv_os_fd_t fd = (uv_os_fd_t)(ssize_t)-1;

    // Fallback for output during early initialisation...
    if (stream == (void*)STDOUT_FILENO) {
        fd = UV_STDOUT_FD;
    }
    else if (stream == (void*)STDERR_FILENO) {
        fd = UV_STDERR_FD;
    }
    else if (stream->type == UV_FILE) {
        fd = ((code_uv_file_t*)stream)->file;
    }

    // TODO: Hack to make CoreIO thread-safer
    code_task_t *ct = code_get_current_task();
    if (ct == NULL || code_atomic_load_relaxed(&ct->tid) != code_atomic_load_relaxed(&io_loop_tid)) {
        if (stream == CODE_STDOUT) {
            fd = UV_STDOUT_FD;
        }
        else if (stream == CODE_STDERR) {
            fd = UV_STDERR_FD;
        }
    }

    if ((ssize_t)fd != -1) {
        // Write to file descriptor...
        code_fs_write(fd, str, n, -1);
    }
    else if (stream->type > UV_HANDLE_TYPE_MAX) {
        // Write to ios.c stream...
        // This is needed because caller code_static_show() in builtins.c can be
        // called from fl_print in flisp/print.c (via cvalue_printdata()),
        // and cvalue_printdata() passes ios_t* to code_static_show().
        ios_write((ios_t*)stream, str, n);
    }
    else {
        // Write to libuv stream...
        uv_write_t *req = (uv_write_t*)malloc_s(sizeof(uv_write_t) + n);
        char *data = (char*)(req + 1);
        memcpy(data, str, n);
        uv_buf_t buf[1];
        buf[0].base = data;
        buf[0].len = n;
        req->data = NULL;
        CODE_UV_LOCK();
        CODE_SIGATOMIC_BEGIN();
        int status = uv_write(req, stream, buf, 1, (uv_write_cb)code_uv_writecb);
        CODE_UV_UNLOCK();
        CODE_SIGATOMIC_END();
        if (status < 0) {
            code_uv_writecb(req, status);
        }
    }
}

CODE_DLLEXPORT void code_uv_putb(uv_stream_t *stream, uint8_t b)
{
    code_uv_puts(stream, (char*)&b, 1);
}

CODE_DLLEXPORT void code_uv_putc(uv_stream_t *stream, uint32_t c)
{
    char s[4];
    int n = 1;
    s[0] = c >> 24;
    if ((s[1] = c >> 16)) {
        n++;
        if ((s[2] = c >> 8)) {
            n++;
            if ((s[3] = c)) {
                n++;
            }
        }
    }
    code_uv_puts(stream, s, n);
}

extern int vasprintf(char **str, const char *fmt, va_list ap);

CODE_DLLEXPORT int code_vprintf(uv_stream_t *s, const char *format, va_list args)
{
    char *str = NULL;
    int c;
    va_list al;
#if defined(_OS_WINDOWS_) && !defined(_COMPILER_GCC_)
    al = args;
#else
    va_copy(al, args);
#endif

    c = vasprintf(&str, format, al);

    if (c >= 0) {
        code_uv_puts(s, str, c);
        free(str);
    }
    va_end(al);
    return c;
}

CODE_DLLEXPORT int code_printf(uv_stream_t *s, const char *format, ...)
{
    va_list args;
    int c;

    va_start(args, format);
    c = code_vprintf(s, format, args);
    va_end(args);
    return c;
}

CODE_DLLEXPORT void code_safe_printf(const char *fmt, ...)
{
    static char buf[1000];
    buf[0] = '\0';
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif

    va_list args;
    va_start(args, fmt);
    // Not async signal safe on some platforms?
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    buf[999] = '\0';
    if (write(STDERR_FILENO, buf, strlen(buf)) < 0) {
        // nothing we can do; ignore the failure
    }
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
}

typedef union {
    struct sockaddr in;
    struct sockaddr_in v4;
    struct sockaddr_in6 v6;
} uv_sockaddr_in;

static void code_sockaddr_fill(uv_sockaddr_in *addr, uint16_t port, void *host, int ipv6)
{
    memset(addr, 0, sizeof(*addr));
    if (ipv6) {
        addr->v6.sin6_family = AF_INET6;
        memcpy(&addr->v6.sin6_addr, host, 16);
        addr->v6.sin6_port = port;
    }
    else {
        addr->v4.sin_family = AF_INET;
        addr->v4.sin_addr.s_addr = *(uint32_t*)host;
        addr->v4.sin_port = port;
    }
}

//NOTE: These function expects port/host to be in network byte-order (Big Endian)
CODE_DLLEXPORT int code_tcp_bind(uv_tcp_t *handle, uint16_t port, void *host,
                             unsigned int flags, int ipv6)
{
    uv_sockaddr_in addr;
    code_sockaddr_fill(&addr, port, host, ipv6);
    return uv_tcp_bind(handle, (struct sockaddr*)&addr, flags);
}

CODE_DLLEXPORT int code_tcp_getsockname(uv_tcp_t *handle, uint16_t *port,
                                    void *host, uint32_t *family)
{
    int namelen;
    struct sockaddr_storage addr;
    memset(&addr, 0, sizeof(struct sockaddr_storage));
    namelen = sizeof addr;
    int res = uv_tcp_getsockname(handle, (struct sockaddr*)&addr, &namelen);
    if (res)
        return res;
    *family = addr.ss_family;
    if (addr.ss_family == AF_INET) {
        struct sockaddr_in *addr4 = (struct sockaddr_in*)&addr;
        *port = addr4->sin_port;
        memcpy(host, &(addr4->sin_addr), 4);
    }
    else if (addr.ss_family == AF_INET6) {
        struct sockaddr_in6 *addr6 = (struct sockaddr_in6*)&addr;
        *port = addr6->sin6_port;
        memcpy(host, &(addr6->sin6_addr), 16);
    }
    return res;
}

CODE_DLLEXPORT int code_tcp_getpeername(uv_tcp_t *handle, uint16_t *port,
                                    void *host, uint32_t *family)
{
    int namelen;
    struct sockaddr_storage addr;
    memset(&addr, 0, sizeof(struct sockaddr_storage));
    namelen = sizeof addr;
    int res = uv_tcp_getpeername(handle, (struct sockaddr*)&addr, &namelen);
    if (res)
        return res;
    *family = addr.ss_family;
    if (addr.ss_family == AF_INET) {
        struct sockaddr_in *addr4 = (struct sockaddr_in*)&addr;
        *port = addr4->sin_port;
        memcpy(host, &(addr4->sin_addr), 4);
    }
    else if (addr.ss_family == AF_INET6) {
        struct sockaddr_in6 *addr6 = (struct sockaddr_in6*)&addr;
        *port = addr6->sin6_port;
        memcpy(host, &(addr6->sin6_addr), 16);
    }
    return res;
}

CODE_DLLEXPORT int code_udp_bind(uv_udp_t *handle, uint16_t port, void *host,
                             uint32_t flags, int ipv6)
{
    uv_sockaddr_in addr;
    code_sockaddr_fill(&addr, port, host, ipv6);
    return uv_udp_bind(handle, (struct sockaddr*)&addr, flags);
}

CODE_DLLEXPORT int code_udp_send(uv_udp_send_t *req, uv_udp_t *handle, uint16_t port, void *host,
                             char *data, uint32_t size, uv_udp_send_cb cb, int ipv6)
{
    uv_sockaddr_in addr;
    code_sockaddr_fill(&addr, port, host, ipv6);
    uv_buf_t buf[1];
    buf[0].base = data;
    buf[0].len = size;
    int r = uv_udp_send(req, handle, buf, 1, (struct sockaddr*)&addr, cb);
    return r;
}

CODE_DLLEXPORT int code_uv_sizeof_interface_address(void)
{
    return sizeof(uv_interface_address_t);
}

CODE_DLLEXPORT int code_uv_interface_addresses(uv_interface_address_t **ifAddrStruct,
                                           int *count)
{
    return uv_interface_addresses(ifAddrStruct, count);
}

CODE_DLLEXPORT int code_uv_interface_address_is_internal(uv_interface_address_t *addr)
{
    return addr->is_internal;
}

CODE_DLLEXPORT struct sockaddr_in *code_uv_interface_address_sockaddr(uv_interface_address_t *ifa)
{
    return &ifa->address.address4;
}

CODE_DLLEXPORT int code_getaddrinfo(uv_loop_t *loop, uv_getaddrinfo_t *req,
        const char *host, const char *service, uv_getaddrinfo_cb uvcb)
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags |= AI_CANONNAME;

    req->data = NULL;
    return uv_getaddrinfo(loop, req, uvcb, host, service, &hints);
}

CODE_DLLEXPORT int code_getnameinfo(uv_loop_t *loop, uv_getnameinfo_t *req,
        void *host, uint16_t port, int flags, uv_getnameinfo_cb uvcb, int ipv6)
{
    uv_sockaddr_in addr;
    code_sockaddr_fill(&addr, port, host, ipv6);
    return uv_getnameinfo(loop, req, uvcb, (struct sockaddr*)&addr, flags);
}

CODE_DLLEXPORT struct sockaddr *code_sockaddr_from_addrinfo(struct addrinfo *addrinfo)
{
    return addrinfo->ai_addr;
}

CODE_DLLEXPORT struct addrinfo *code_next_from_addrinfo(struct addrinfo *addrinfo)
{
    return addrinfo->ai_next;
}

CODE_DLLEXPORT int code_sockaddr_is_ip4(struct sockaddr *addr)
{
    return (addr->sa_family == AF_INET);
}

CODE_DLLEXPORT int code_sockaddr_is_ip6(struct sockaddr *addr)
{
    return (addr->sa_family == AF_INET6);
}

CODE_DLLEXPORT uint32_t code_sockaddr_host4(struct sockaddr_in *addr)
{
    return addr->sin_addr.s_addr;
}

CODE_DLLEXPORT unsigned code_sockaddr_host6(struct sockaddr_in6 *addr, char *host)
{
    memcpy(host, &addr->sin6_addr, 16);
    return addr->sin6_scope_id;
}

CODE_DLLEXPORT uint16_t code_sockaddr_port4(struct sockaddr_in *addr)
{
    return addr->sin_port;
}

CODE_DLLEXPORT uint16_t code_sockaddr_port6(struct sockaddr_in6 *addr)
{
    return addr->sin6_port;
}


CODE_DLLEXPORT void code_sockaddr_set_port(uv_sockaddr_in *addr, uint16_t port)
{
    if (addr->in.sa_family == AF_INET)
        addr->v4.sin_port = port;
    else
        addr->v6.sin6_port = port;
}

CODE_DLLEXPORT int code_tcp_connect(uv_tcp_t *handle, void *host, uint16_t port,
                                uv_connect_cb cb, int ipv6)
{
    uv_sockaddr_in addr;
    code_sockaddr_fill(&addr, port, host, ipv6);
    uv_connect_t *req = (uv_connect_t*)malloc_s(sizeof(uv_connect_t));
    req->data = NULL;
    int r = uv_tcp_connect(req, handle, &addr.in, cb);
    if (r)
        free(req);
    return r;
}

#ifdef _OS_LINUX_
CODE_DLLEXPORT int code_tcp_quickack(uv_tcp_t *handle, int on)
{
    int fd = (handle)->io_watcher.fd;
    if (fd != -1) {
        if (setsockopt(fd, IPPROTO_TCP, TCP_QUICKACK, &on, sizeof(on))) {
            return -1;
        }
    }
    return 0;
}

#endif

CODE_DLLEXPORT int code_has_so_reuseport(void)
{
#if defined(SO_REUSEPORT) && !defined(_OS_DARWIN_)
    return 1;
#else
    return 0;
#endif
}

CODE_DLLEXPORT int code_tcp_reuseport(uv_tcp_t *handle)
{
#if defined(SO_REUSEPORT)
    int fd = (handle)->io_watcher.fd;
    int yes = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes))) {
        return -1;
    }
    return 0;
#else
    return -1;
#endif
}

#ifndef _OS_WINDOWS_

CODE_DLLEXPORT int code_uv_unix_fd_is_watched(int fd, uv_poll_t *handle,
                                          uv_loop_t *loop)
{
    CODE_UV_LOCK();
    if (fd >= loop->nwatchers) {
        CODE_UV_UNLOCK();
        return 0;
    }
    if (loop->watchers[fd] == NULL) {
        CODE_UV_UNLOCK();
        return 0;
    }
    if (handle && loop->watchers[fd] == &handle->io_watcher) {
        CODE_UV_UNLOCK();
        return 0;
    }
    CODE_UV_UNLOCK();
    return 1;
}

#endif

#ifdef _OS_WINDOWS_
static inline int ishexchar(char c)
{
   if (c >= '0' && c <= '9') return 1;
   if (c >= 'a' && c <= 'z') return 1;
   return 0;
}

CODE_DLLEXPORT int code_ispty(uv_pipe_t *pipe)
{
    char namebuf[0];
    size_t len = 0;
    if (pipe->type != UV_NAMED_PIPE)
        return 0;
    if (uv_pipe_getpeername(pipe, namebuf, &len) != UV_ENOBUFS)
        return 0;
    char *name = (char*)alloca(len + 1);
    if (uv_pipe_getpeername(pipe, name, &len))
        return 0;
    name[len] = '\0';
    // return true if name matches regex:
    // ^\\\\?\\pipe\\(msys|cygwin)-[0-9a-z]{16}-[pt]ty[1-9][0-9]*-
    //code_printf(CODE_STDERR,"pipe_name: %s\n", name);
    int n = 0;
    if (!strncmp(name, "\\\\?\\pipe\\msys-", 14))
        n = 14;
    else if (!strncmp(name, "\\\\?\\pipe\\cygwin-", 16))
        n = 16;
    else
        return 0;
    //code_printf(CODE_STDERR,"prefix pass\n");
    name += n;
    for (int n = 0; n < 16; n++)
        if (!ishexchar(*name++))
            return 0;
    //code_printf(CODE_STDERR,"hex pass\n");
    if ((*name++)!='-')
        return 0;
    if (*name != 'p' && *name != 't')
        return 0;
    name++;
    if (*name++ != 't' || *name++ != 'y')
        return 0;
    //code_printf(CODE_STDERR,"tty pass\n");
    return 1;
}
#endif

CODE_DLLEXPORT uv_handle_type code_uv_handle_type(uv_handle_t *handle)
{
#ifdef _OS_WINDOWS_
    if (code_ispty((uv_pipe_t*)handle))
        return UV_TTY;
#endif
    return handle->type;
}

CODE_DLLEXPORT int code_tty_set_mode(uv_tty_t *handle, int mode)
{
    if (handle->type != UV_TTY) return 0;
    uv_tty_mode_t mode_enum = UV_TTY_MODE_NORMAL;
    if (mode)
        mode_enum = UV_TTY_MODE_RAW;
    // TODO: do we need lock?
    return uv_tty_set_mode(handle, mode_enum);
}

typedef int (*work_cb_t)(void *, void *, void *);
typedef void (*notify_cb_t)(int);

struct work_baton {
    uv_work_t req;
    work_cb_t work_func;
    void      *ccall_fptr;
    void      *work_args;
    void      *work_retval;
    notify_cb_t notify_func;
    int       notify_idx;
};

#ifdef _OS_LINUX_
#include <sys/syscall.h>
#endif

void code_work_wrapper(uv_work_t *req)
{
    struct work_baton *baton = (struct work_baton*) req->data;
    baton->work_func(baton->ccall_fptr, baton->work_args, baton->work_retval);
}

void code_work_notifier(uv_work_t *req, int status)
{
    struct work_baton *baton = (struct work_baton*) req->data;
    baton->notify_func(baton->notify_idx);
    free(baton);
}

CODE_DLLEXPORT int code_queue_work(work_cb_t work_func, void *ccall_fptr, void *work_args, void *work_retval,
                               notify_cb_t notify_func, int notify_idx)
{
    struct work_baton *baton = (struct work_baton*)malloc_s(sizeof(struct work_baton));
    baton->req.data = (void*) baton;
    baton->work_func = work_func;
    baton->ccall_fptr = ccall_fptr;
    baton->work_args = work_args;
    baton->work_retval = work_retval;
    baton->notify_func = notify_func;
    baton->notify_idx = notify_idx;

    CODE_UV_LOCK();
    uv_queue_work(code_io_loop, &baton->req, code_work_wrapper, code_work_notifier);
    CODE_UV_UNLOCK();

    return 0;
}

#ifndef _OS_WINDOWS_
#if defined(__APPLE__)
int uv___stream_fd(uv_stream_t *handle);
#define uv__stream_fd(handle) (uv___stream_fd((uv_stream_t*)(handle)))
#else
#define uv__stream_fd(handle) ((handle)->io_watcher.fd)
#endif /* defined(__APPLE__) */
CODE_DLLEXPORT int code_uv_handle(uv_stream_t *handle)
{
    return uv__stream_fd(handle);
}
#else
CODE_DLLEXPORT HANDLE code_uv_handle(uv_stream_t *handle)
{
    switch (handle->type) {
    case UV_TTY:
        return ((uv_tty_t*)handle)->handle;
    case UV_NAMED_PIPE:
        return ((uv_pipe_t*)handle)->handle;
    default:
        return INVALID_HANDLE_VALUE;
    }
}
#endif

#ifdef __cplusplus
}
#endif
