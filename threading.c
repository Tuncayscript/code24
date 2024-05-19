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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef USE_ITTAPI
#include "ittapi/ittnotify.h"
#endif

// Ref https://www.uclibc.org/docs/tls.pdf
// For variant 1 LANGUAGE_ELF_TLS_INIT_SIZE is the size of the thread control block (TCB)
// For variant 2 LANGUAGE_ELF_TLS_INIT_SIZE is 0
#if defined(_OS_LINUX_) || defined(_OS_FREEBSD_)
#  if defined(_CPU_X86_64_) || defined(_CPU_X86_)
#    define LANGUAGE_ELF_TLS_VARIANT 2
#    define LANGUAGE_ELF_TLS_INIT_SIZE 0
#  elif defined(_CPU_AARCH64_)
#    define LANGUAGE_ELF_TLS_VARIANT 1
#    define LANGUAGE_ELF_TLS_INIT_SIZE 16
#  elif defined(__ARM_ARCH) && __ARM_ARCH >= 7
#    define LANGUAGE_ELF_TLS_VARIANT 1
#    define LANGUAGE_ELF_TLS_INIT_SIZE 8
#  endif
#endif

#ifdef LANGUAGE_ELF_TLS_VARIANT
#  include <link.h>
#endif

// `ElfW` was added to FreeBSD in 12.3 but we still support 12.2
#if defined(_OS_FREEBSD_) && !defined(ElfW)
#  define ElfW(x) __ElfN(x)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "threading.h"

LANGUAGE_DLLEXPORT _Atomic(uint8_t) language_measure_compile_time_enabled = 0;
LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_cumulative_compile_time = 0;
LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_cumulative_recompile_time = 0;

LANGUAGE_DLLEXPORT void *language_get_ptls_states(void)
{
    // mostly deprecated: use current_task instead
    return language_current_task->ptls;
}

static void language_delete_thread(void*);

#if !defined(_OS_WINDOWS_)
static pthread_key_t language_task_exit_key;
static pthread_key_t language_safe_restore_key;

__attribute__((constructor)) void _language_init_safe_restore(void)
{
    pthread_key_create(&language_safe_restore_key, NULL);
    pthread_key_create(&language_task_exit_key, language_delete_thread);
}

LANGUAGE_DLLEXPORT language_jmp_buf *language_get_safe_restore(void)
{
    return (language_jmp_buf*)pthread_getspecific(language_safe_restore_key);
}

LANGUAGE_DLLEXPORT void language_set_safe_restore(language_jmp_buf *sr)
{
    pthread_setspecific(language_safe_restore_key, (void*)sr);
}
#endif


// The tls_states buffer:
//
// On platforms that do not use ELF (i.e. where `__thread` is emulated with
// lower level API) (Mac, Windows), we use the platform runtime API to create
// TLS variable directly.
// This is functionally equivalent to using `__thread` but can be
// more efficient since we can have better control over the creation and
// initialization of the TLS buffer.
//
// On platforms that use ELF (Linux, FreeBSD), we use a `__thread` variable
// as the fallback in the shared object. For better efficiency, we also
// create a `__thread` variable in the main executable using a static TLS
// model.
#if defined(_OS_DARWIN_)
// Mac doesn't seem to have static TLS model so the runtime TLS getter
// registration will only add overhead to TLS access. The `__thread` variables
// are emulated with `pthread_key_t` so it is actually faster to use it directly.
static pthread_key_t language_pgcstack_key;

__attribute__((constructor)) void language_init_tls(void)
{
    pthread_key_create(&language_pgcstack_key, NULL);
}

LANGUAGE_CONST_FUNC language_gcframe_t **language_get_pgcstack(void) LANGUAGE_NOTSAFEPOINT
{
    return (language_gcframe_t**)pthread_getspecific(language_pgcstack_key);
}

void language_set_pgcstack(language_gcframe_t **pgcstack) LANGUAGE_NOTSAFEPOINT
{
    pthread_setspecific(language_pgcstack_key, (void*)pgcstack);
}

void language_pgcstack_getkey(language_get_pgcstack_func **f, pthread_key_t *k)
{
    // for codegen
    *f = pthread_getspecific;
    *k = language_pgcstack_key;
}


LANGUAGE_DLLEXPORT void language_pgcstack_setkey(language_get_pgcstack_func *f, pthread_key_t k)
{
    language_safe_printf("ERROR: Attempt to change TLS address.\n");
}

#elif defined(_OS_WINDOWS_)
// Apparently windows doesn't have a static TLS model (or one that can be
// reliably used from a shared library) either..... Use `TLSAlloc` instead.

static DWORD language_pgcstack_key;
static DWORD language_safe_restore_key;

// Put this here for now. We can move this out later if we find more use for it.
BOOLEAN WINAPI DllMain(IN HINSTANCE hDllHandle, IN DWORD nReason,
                       IN LPVOID Reserved)
{
    language_task_t *ct;
    switch (nReason) {
    case DLL_PROCESS_ATTACH:
        language_pgcstack_key = TlsAlloc();
        assert(language_pgcstack_key != TLS_OUT_OF_INDEXES);
        language_safe_restore_key = TlsAlloc();
        assert(language_safe_restore_key != TLS_OUT_OF_INDEXES);
        break;
    case DLL_PROCESS_DETACH:
        TlsFree(language_pgcstack_key);
        TlsFree(language_safe_restore_key);
        break;
    case DLL_THREAD_ATTACH:
        // will call language_adopt_thread lazily on-demand
        break;
    case DLL_THREAD_DETACH:
        ct = language_get_current_task();
        if (ct != NULL)
            language_delete_thread((void*)ct->ptls);
        break;
    }
    return 1; // success
}

#if defined(_CPU_X86_64_)
#define SAVE_ERRNO \
    DWORD *plast_error = (DWORD*)(__readgsqword(0x30) + 0x68); \
    DWORD last_error = *plast_error
#define LOAD_ERRNO \
    *plast_error = last_error
#elif defined(_CPU_X86_)
#define SAVE_ERRNO \
    DWORD *plast_error = (DWORD*)(__readfsdword(0x18) + 0x34); \
    DWORD last_error = *plast_error
#define LOAD_ERRNO \
    *plast_error = last_error
#else
#define SAVE_ERRNO \
    DWORD last_error = GetLastError()
#define LOAD_ERRNO \
    SetLastError(last_error)
#endif

LANGUAGE_DLLEXPORT language_jmp_buf *language_get_safe_restore(void)
{
    SAVE_ERRNO;
    language_jmp_buf *sr = (language_jmp_buf*)TlsGetValue(language_safe_restore_key);
    LOAD_ERRNO;
    return sr;
}

LANGUAGE_DLLEXPORT void language_set_safe_restore(language_jmp_buf *sr)
{
    SAVE_ERRNO;
    TlsSetValue(language_safe_restore_key, (void*)sr);
    LOAD_ERRNO;
}

LANGUAGE_CONST_FUNC language_gcframe_t **language_get_pgcstack(void) LANGUAGE_NOTSAFEPOINT
{
    SAVE_ERRNO;
    language_gcframe_t **pgcstack = (language_gcframe_t**)TlsGetValue(language_pgcstack_key);
    LOAD_ERRNO;
    return pgcstack;
}

void language_set_pgcstack(language_gcframe_t **pgcstack) LANGUAGE_NOTSAFEPOINT
{
    // n.b.: this smashes GetLastError
    TlsSetValue(language_pgcstack_key, (void*)pgcstack);
}

void language_pgcstack_getkey(language_get_pgcstack_func **f, DWORD *k)
{
    // for codegen
    *f = language_get_pgcstack;
    *k = language_pgcstack_key;
}

LANGUAGE_DLLEXPORT void language_pgcstack_setkey(language_get_pgcstack_func *f, DWORD k)
{
    language_safe_printf("ERROR: Attempt to change TLS address.\n");
}


#else
// We use the faster static version in the main executable to replace
// the slower version in the shared object. The code in different libraries
// or executables, however, have to agree on which version to use.
// The general solution is to add one more indirection in the C entry point.
//
// When `ifunc` is available, we can use it to trick the linker to use the
// real address (`language_get_pgcstack_static`) directly as the symbol address.
//
// However, since the detection of the static version in `ifunc`
// is not guaranteed to be reliable, we still need to fallback to the wrapper
// version as the symbol address if we didn't find the static version in `ifunc`.

// fallback provided for embedding
static language_pgcstack_key_t language_pgcstack_key;
static __thread language_gcframe_t **pgcstack_;
static language_gcframe_t **language_get_pgcstack_fallback(void) LANGUAGE_NOTSAFEPOINT
{
    return pgcstack_;
}
static language_gcframe_t ***language_pgcstack_addr_fallback(void) LANGUAGE_NOTSAFEPOINT
{
    return &pgcstack_;
}
void language_set_pgcstack(language_gcframe_t **pgcstack) LANGUAGE_NOTSAFEPOINT
{
    *language_pgcstack_key() = pgcstack;
}
#  if LANGUAGE_USE_IFUNC
LANGUAGE_DLLEXPORT __attribute__((weak))
void language_register_pgcstack_getter(void);
#  endif
static language_gcframe_t **language_get_pgcstack_init(void);
static language_get_pgcstack_func *language_get_pgcstack_cb = language_get_pgcstack_init;
static language_gcframe_t **language_get_pgcstack_init(void)
{
    // This 2-step initialization is used to detect calling
    // `language_pgcstack_getkey` after the address of the TLS variables
    // are used. Since the address of TLS variables should be constant,
    // changing the getter address can result in weird crashes.

    // This is clearly not thread-safe but should be fine since we
    // make sure the tls states callback is finalized before adding
    // multiple threads
#  if LANGUAGE_USE_IFUNC
    if (language_register_pgcstack_getter)
        language_register_pgcstack_getter();
    else
#  endif
    {
        language_get_pgcstack_cb = language_get_pgcstack_fallback;
        language_pgcstack_key = &language_pgcstack_addr_fallback;
    }
    return language_get_pgcstack_cb();
}

LANGUAGE_DLLEXPORT void language_pgcstack_setkey(language_get_pgcstack_func *f, language_pgcstack_key_t k)
{
    if (f == language_get_pgcstack_cb || !f)
        return;
    // only allow setting this once
    if (language_get_pgcstack_cb != language_get_pgcstack_init) {
        language_safe_printf("ERROR: Attempt to change TLS address.\n");
        exit(1);
    }
    language_get_pgcstack_cb = f;
    language_pgcstack_key = k;
}

LANGUAGE_DLLEXPORT language_gcframe_t **language_get_pgcstack(void) LANGUAGE_GLOBALLY_ROOTED
{
#ifndef __clang_gcanalyzer__
    return language_get_pgcstack_cb();
#endif
}

void language_pgcstack_getkey(language_get_pgcstack_func **f, language_pgcstack_key_t *k)
{
#ifndef __clang_gcanalyzer__
    if (language_get_pgcstack_cb == language_get_pgcstack_init)
        language_get_pgcstack_init();
#endif
    // for codegen
    *f = language_get_pgcstack_cb;
    *k = language_pgcstack_key;
}
#endif

static uv_mutex_t tls_lock; // controls write-access to these variables:
_Atomic(language_ptls_t*) language_all_tls_states LANGUAGE_GLOBALLY_ROOTED;
int language_all_tls_states_size;
static uv_cond_t cond;
// concurrent reads are permitted, using the same pattern as mtsmall_arraylist
// it is implemented separately because the API of direct language_all_tls_states use is already widely prevalent
void language_init_thread_scheduler(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT;

// return calling thread's ID
LANGUAGE_DLLEXPORT int16_t language_threadid(void)
{
    return language_atomic_load_relaxed(&language_current_task->tid);
}

LANGUAGE_DLLEXPORT int8_t language_threadpoolid(int16_t tid) LANGUAGE_NOTSAFEPOINT
{
    int nthreads = language_atomic_load_acquire(&language_n_threads);
    if (tid < 0 || tid >= nthreads)
        language_error("invalid tid");
    int n = 0;
    for (int i = 0; i < language_n_threadpools; i++) {
        n += language_n_threads_per_pool[i];
        if (tid < n)
            return (int8_t)i;
    }
    return -1; // everything else uses threadpool -1 (does not belong to any threadpool)
}

language_ptls_t language_init_threadtls(int16_t tid)
{
#ifndef _OS_WINDOWS_
    if (pthread_getspecific(language_task_exit_key))
        abort();
#endif
    if (language_get_pgcstack() != NULL)
        abort();
    language_ptls_t ptls = (language_ptls_t)calloc(1, sizeof(language_tls_states_t));
#ifndef _OS_WINDOWS_
    pthread_setspecific(language_task_exit_key, (void*)ptls);
#endif
    ptls->system_id = uv_thread_self();
    ptls->rngseed = language_rand();
    if (tid == 0)
        ptls->disable_gc = 1;
#ifdef _OS_WINDOWS_
    if (tid == 0) {
        if (!DuplicateHandle(GetCurrentProcess(), GetCurrentThread(),
                             GetCurrentProcess(), &hMainThread, 0,
                             FALSE, DUPLICATE_SAME_ACCESS)) {
            language_printf(LANGUAGE_STDERR, "WARNING: failed to access handle to main thread\n");
            hMainThread = INVALID_HANDLE_VALUE;
        }
    }
#endif
    language_atomic_store_relaxed(&ptls->gc_state, LANGUAGE_GC_STATE_UNSAFE); // GC unsafe
    // Conditionally initialize the safepoint address. See comment in
    // `safepoint.c`
    if (tid == 0) {
        language_atomic_store_relaxed(&ptls->safepoint, (size_t*)(language_safepoint_pages + language_page_size));
    }
    else {
        language_atomic_store_relaxed(&ptls->safepoint, (size_t*)(language_safepoint_pages + language_page_size * 2 +
                                sizeof(size_t)));
    }
    language_bt_element_t *bt_data = (language_bt_element_t*)
        malloc_s(sizeof(language_bt_element_t) * (LANGUAGE_MAX_BT_SIZE + 1));
    memset(bt_data, 0, sizeof(language_bt_element_t) * (LANGUAGE_MAX_BT_SIZE + 1));
    ptls->bt_data = bt_data;
    small_arraylist_new(&ptls->locks, 0);
    language_init_thread_heap(ptls);
    language_init_thread_scheduler(ptls);

    uv_mutex_lock(&tls_lock);
    if (tid == -1)
        tid = language_atomic_load_relaxed(&language_n_threads);
    ptls->tid = tid;
    language_ptls_t *allstates = language_atomic_load_relaxed(&language_all_tls_states);
    if (language_all_tls_states_size <= tid) {
        int i, newsize = language_all_tls_states_size + tid + 2;
        language_ptls_t *newpptls = (language_ptls_t*)calloc(newsize, sizeof(language_ptls_t));
        for (i = 0; i < language_all_tls_states_size; i++) {
            newpptls[i] = allstates[i];
        }
        language_atomic_store_release(&language_all_tls_states, newpptls);
        language_all_tls_states_size = newsize;
        language_gc_add_quiescent(ptls, (void**)allstates, free);
        allstates = newpptls;
    }
    allstates[tid] = ptls;
    if (language_atomic_load_relaxed(&language_n_threads) < tid + 1)
        language_atomic_store_release(&language_n_threads, tid + 1);
    language_fence();
    uv_mutex_unlock(&tls_lock);

    return ptls;
}

LANGUAGE_DLLEXPORT language_gcframe_t **language_adopt_thread(void)
{
    // `language_init_threadtls` puts us in a GC unsafe region, so ensure GC isn't running.
    // we can't use a normal safepoint because we don't have signal handlers yet.
    // we also can't use language_safepoint_wait_gc because that assumes we're in a task.
    language_atomic_fetch_add(&language_gc_disable_counter, 1);
    while (language_atomic_load_acquire(&language_gc_running)) {
        language_cpu_pause();
    }
    // this check is coupled with the one in `language_safepoint_wait_gc`, where we observe if a
    // foreign thread has asked to disable the GC, guaranteeing the order of events.

    // initialize this thread (assign tid, create heap, set up root task)
    language_ptls_t ptls = language_init_threadtls(-1);
    void *stack_lo, *stack_hi;
    language_init_stack_limits(0, &stack_lo, &stack_hi);

    // warning: this changes `language_current_task`, so be careful not to call that from this function
    language_task_t *ct = language_init_root_task(ptls, stack_lo, stack_hi); // assumes the GC is disabled
    LANGUAGE_GC_PROMISE_ROOTED(ct);
    uv_random(NULL, NULL, &ct->rngState, sizeof(ct->rngState), 0, NULL);
    language_atomic_fetch_add(&language_gc_disable_counter, -1);
    return &ct->gcstack;
}

void language_task_frame_noreturn(language_task_t *ct) LANGUAGE_NOTSAFEPOINT;
void scheduler_delete_thread(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT;

void language_free_thread_gc_state(language_ptls_t ptls);

static void language_delete_thread(void *value) LANGUAGE_NOTSAFEPOINT_ENTER
{
#ifndef _OS_WINDOWS_
    pthread_setspecific(language_task_exit_key, NULL);
#endif
    language_ptls_t ptls = (language_ptls_t)value;
    // safepoint until GC exit, in case GC was running concurrently while in
    // prior unsafe-region (before we let it release the stack memory)
    (void)language_gc_unsafe_enter(ptls);
    scheduler_delete_thread(ptls);
    // try to free some state we do not need anymore
#ifndef _OS_WINDOWS_
    void *signal_stack = ptls->signal_stack;
    size_t signal_stack_size = ptls->signal_stack_size;
    if (signal_stack != NULL) {
        stack_t ss;
        if (sigaltstack(NULL, &ss))
            language_errorf("fatal error: sigaltstack: %s", strerror(errno));
        if (ss.ss_sp == signal_stack) {
            ss.ss_flags = SS_DISABLE;
            if (sigaltstack(&ss, NULL) != 0) {
                language_errorf("warning: sigaltstack: %s (will leak this memory)", strerror(errno));
                signal_stack = NULL;
            }
        }
        if (signal_stack != NULL) {
            if (signal_stack_size)
                language_free_stack(signal_stack, signal_stack_size);
            else
                free(signal_stack);
        }
        ptls->signal_stack = NULL;
    }
#endif
    // Acquire the profile write lock, to ensure we are not racing with the `kill`
    // call in the profile code which will also try to look at this thread.
    // We have no control over when the user calls pthread_join, so we must do
    // this here by blocking. This also synchronizes our read of `current_task`
    // (which is the flag we currently use to check the liveness state of a thread).
#ifdef _OS_WINDOWS_
    language_lock_profile_wr();
#elif defined(LANGUAGE_DISABLE_LIBUNWIND)
    // nothing
#elif defined(__APPLE__)
    language_lock_profile_wr();
#else
    pthread_mutex_lock(&in_signal_lock);
#endif
    // need to clear pgcstack and eh, but we can clear everything now too
    language_task_frame_noreturn(language_atomic_load_relaxed(&ptls->current_task));
    if (language_set_task_tid(ptls->root_task, ptls->tid)) {
        // the system will probably free this stack memory soon
        // so prevent any other thread from accessing it later
        language_task_frame_noreturn(ptls->root_task);
    }
    else {
        // Uh oh. The user cleared the sticky bit so it started running
        // elsewhere, then called pthread_exit on this thread. This is not
        // recoverable. Though we could just hang here, a fatal message is better.
        language_safe_printf("fatal: thread exited from wrong Task.\n");
        abort();
    }
    language_atomic_store_relaxed(&ptls->current_task, NULL); // dead
    // finally, release all of the locks we had grabbed
#ifdef _OS_WINDOWS_
    language_unlock_profile_wr();
#elif defined(LANGUAGE_DISABLE_LIBUNWIND)
    // nothing
#elif defined(__APPLE__)
    language_unlock_profile_wr();
#else
    pthread_mutex_unlock(&in_signal_lock);
#endif
    free(ptls->bt_data);
    small_arraylist_free(&ptls->locks);
    ptls->previous_exception = NULL;
    // allow the page root_task is on to be freed
    ptls->root_task = NULL;
    language_free_thread_gc_state(ptls);
    // then park in safe-region
    (void)language_gc_safe_enter(ptls);
}

//// debugging hack: if we are exiting too fast for error message printing on threads,
//// enabling this will stall that first thread just before exiting, to give
//// the other threads time to fail and emit their failure message
//__attribute__((destructor)) static void _waitthreaddeath(void) { sleep(1); }

LANGUAGE_DLLEXPORT language_mutex_t language_codegen_lock;
language_mutex_t typecache_lock;

LANGUAGE_DLLEXPORT ssize_t language_tls_offset = -1;

#ifdef LANGUAGE_ELF_TLS_VARIANT
LANGUAGE_DLLEXPORT const int language_tls_elf_support = 1;
// Optimize TLS access in codegen if the TLS buffer is using a IE or LE model.
// To detect such case, we find the size of the TLS segment in the main
// executable and the thread pointer (TP) and then see if the TLS pointer on the
// current thread is in the right range.
// This can in principle be extended to the case where the TLS buffer is
// in the shared library but is part of the static buffer but that seems harder
// to detect.
#  if LANGUAGE_ELF_TLS_VARIANT == 1
// In Variant 1, the static TLS buffer comes after a fixed size TCB.
// The alignment needs to be applied to the original size.
static inline size_t language_add_tls_size(size_t orig_size, size_t size, size_t align)
{
    return LLT_ALIGN(orig_size, align) + size;
}
static inline ssize_t language_check_tls_bound(void *tp, language_gcframe_t ***k0, size_t tls_size)
{
    ssize_t offset = (char*)k0 - (char*)tp;
    if (offset < LANGUAGE_ELF_TLS_INIT_SIZE ||
        (size_t)offset + sizeof(*k0) > tls_size)
        return -1;
    return offset;
}
#  elif LANGUAGE_ELF_TLS_VARIANT == 2
// In Variant 2, the static TLS buffer comes before a unknown size TCB.
// The alignment needs to be applied to the new size.
static inline size_t language_add_tls_size(size_t orig_size, size_t size, size_t align)
{
    return LLT_ALIGN(orig_size + size, align);
}
static inline ssize_t language_check_tls_bound(void *tp, language_gcframe_t ***k0, size_t tls_size)
{
    ssize_t offset = (char*)tp - (char*)k0;
    if (offset < sizeof(*k0) || offset > tls_size)
        return -1;
    return -offset;
}
#  else
#    error "Unknown static TLS variant"
#  endif

// Find the size of the TLS segment in the main executable
typedef struct {
    size_t total_size;
} check_tls_cb_t;

static int check_tls_cb(struct dl_phdr_info *info, size_t size, void *_data)
{
    check_tls_cb_t *data = (check_tls_cb_t*)_data;
    const ElfW(Phdr) *phdr = info->dlpi_phdr;
    unsigned phnum = info->dlpi_phnum;
    size_t total_size = LANGUAGE_ELF_TLS_INIT_SIZE;

    for (unsigned i = 0; i < phnum; i++) {
        const ElfW(Phdr) *seg = &phdr[i];
        if (seg->p_type != PT_TLS)
            continue;
        // There should be only one TLS segment
        // Variant II
        total_size = language_add_tls_size(total_size, seg->p_memsz, seg->p_align);
    }
    data->total_size = total_size;
    // only run once (on the main executable)
    return 1;
}

static void language_check_tls(void)
{
    language_get_pgcstack_func *f;
    language_gcframe_t ***(*k)(void);
    language_pgcstack_getkey(&f, &k);
    language_gcframe_t ***k0 = k();
    if (k0 == NULL)
        return;
    check_tls_cb_t data = {0};
    dl_iterate_phdr(check_tls_cb, &data);
    if (data.total_size == 0)
        return;
    void *tp; // Thread pointer
#if defined(_CPU_X86_64_)
    asm("movq %%fs:0, %0" : "=r"(tp));
#elif defined(_CPU_X86_)
    asm("movl %%gs:0, %0" : "=r"(tp));
#elif defined(_CPU_AARCH64_)
    asm("mrs %0, tpidr_el0" : "=r"(tp));
#elif defined(__ARM_ARCH) && __ARM_ARCH >= 7
    asm("mrc p15, 0, %0, c13, c0, 3" : "=r"(tp));
#else
#  error "Cannot emit thread pointer for this architecture."
#endif
    ssize_t offset = language_check_tls_bound(tp, k0, data.total_size);
    if (offset == -1)
        return;
    language_tls_offset = offset;
}
#else
// !LANGUAGE_ELF_TLS_VARIANT
LANGUAGE_DLLEXPORT const int language_tls_elf_support = 0;
#endif

extern int language_n_markthreads;
extern int language_n_sweepthreads;
extern int gc_first_tid;

// interface to Julia; sets up to make the runtime thread-safe
void language_init_threading(void)
{
    char *cp;

    uv_mutex_init(&tls_lock);
    uv_cond_init(&cond);
#ifdef LANGUAGE_ELF_TLS_VARIANT
    language_check_tls();
#endif

    // Determine how many threads and pools are requested. This may have been
    // specified on the command line (and so are in `language_options`) or by the
    // environment variable. Set the globals `language_n_threadpools`, `language_n_threads`
    // and `language_n_threads_per_pool`.
    language_n_threadpools = 2;
    int16_t nthreads = JULIA_NUM_THREADS;
    int16_t nthreadsi = 0;
    char *endptr, *endptri;

    if (language_options.nthreads != 0) { // --threads specified
        nthreads = language_options.nthreads_per_pool[0];
        if (nthreads < 0)
            nthreads = language_effective_threads();
        if (language_options.nthreadpools == 2)
            nthreadsi = language_options.nthreads_per_pool[1];
    }
    else if ((cp = getenv(NUM_THREADS_NAME))) { // ENV[NUM_THREADS_NAME] specified
        if (!strncmp(cp, "auto", 4)) {
            nthreads = language_effective_threads();
            cp += 4;
        }
        else {
            errno = 0;
            nthreads = strtol(cp, &endptr, 10);
            if (errno != 0 || endptr == cp || nthreads <= 0)
                nthreads = 1;
            cp = endptr;
        }
        if (*cp == ',') {
            cp++;
            if (!strncmp(cp, "auto", 4))
                nthreadsi = 1;
            else {
                errno = 0;
                nthreadsi = strtol(cp, &endptri, 10);
                if (errno != 0 || endptri == cp || nthreadsi < 0)
                    nthreadsi = 0;
            }
        }
    }

    int cpu = language_cpu_threads();
    language_n_markthreads = language_options.nmarkthreads - 1;
    language_n_sweepthreads = language_options.nsweepthreads;
    if (language_n_markthreads == -1) { // --gcthreads not specified
        if ((cp = getenv(NUM_GC_THREADS_NAME))) { // ENV[NUM_GC_THREADS_NAME] specified
            errno = 0;
            language_n_markthreads = (uint64_t)strtol(cp, &endptr, 10) - 1;
            if (errno != 0 || endptr == cp || nthreads <= 0)
                language_n_markthreads = 0;
            cp = endptr;
            if (*cp == ',') {
                cp++;
                errno = 0;
                language_n_sweepthreads = strtol(cp, &endptri, 10);
                if (errno != 0 || endptri == cp || language_n_sweepthreads < 0) {
                    language_n_sweepthreads = 0;
                }
            }
        }
        else {
            // if `--gcthreads` or ENV[NUM_GCTHREADS_NAME] was not specified,
            // set the number of mark threads to the number of compute threads
            // and number of sweep threads to 0
            language_n_markthreads = nthreads - 1; // -1 for the master (mutator) thread which may also do marking
            // if `--gcthreads` or ENV[NUM_GCTHREADS_NAME] was not specified,
            // cap the number of threads that may run the mark phase to
            // the number of CPU cores
            if (language_n_markthreads + 1 >= cpu) {
                language_n_markthreads = cpu - 1;
            }
        }
    }
    // warn the user if they try to run with a number
    // of GC threads which is larger than the number
    // of physical cores
    if (language_n_markthreads + 1 > cpu) {
        language_safe_printf("WARNING: running Julia with %d GC threads on %d CPU cores\n", language_n_markthreads + 1, cpu);
    }
    int16_t ngcthreads = language_n_markthreads + language_n_sweepthreads;

    language_all_tls_states_size = nthreads + nthreadsi + ngcthreads;
    language_n_threads_per_pool = (int*)malloc_s(2 * sizeof(int));
    language_n_threads_per_pool[0] = nthreadsi;
    language_n_threads_per_pool[1] = nthreads;
    assert(language_all_tls_states_size > 0);
    language_atomic_store_release(&language_all_tls_states, (language_ptls_t*)calloc(language_all_tls_states_size, sizeof(language_ptls_t)));
    language_atomic_store_release(&language_n_threads, language_all_tls_states_size);
    language_n_gcthreads = ngcthreads;
    gc_first_tid = nthreads;
}

static uv_barrier_t thread_init_done;

void language_start_threads(void)
{
    int nthreads = language_atomic_load_relaxed(&language_n_threads);
    int ngcthreads = language_n_gcthreads;
    int cpumasksize = uv_cpumask_size();
    char *cp;
    int i, exclusive;
    uv_thread_t uvtid;
    if (cpumasksize < nthreads) // also handles error case
        cpumasksize = nthreads;
    char *mask = (char*)alloca(cpumasksize);

    // do we have exclusive use of the machine? default is no
    exclusive = DEFAULT_MACHINE_EXCLUSIVE;
    cp = getenv(MACHINE_EXCLUSIVE_NAME);
    if (cp && strcmp(cp, "0") != 0)
        exclusive = 1;

    // exclusive use: affinitize threads, master thread on proc 0, rest
    // according to a 'compact' policy
    // non-exclusive: no affinity settings; let the kernel move threads about
    if (exclusive) {
        if (nthreads > language_cpu_threads()) {
            language_printf(LANGUAGE_STDERR, "ERROR: Too many threads requested for %s option.\n", MACHINE_EXCLUSIVE_NAME);
            exit(1);
        }
        memset(mask, 0, cpumasksize);
        mask[0] = 1;
        uvtid = uv_thread_self();
        uv_thread_setaffinity(&uvtid, mask, NULL, cpumasksize);
        mask[0] = 0;
    }

    // create threads
    uv_barrier_init(&thread_init_done, nthreads);

    // GC/System threads need to be after the worker threads.
    int nworker_threads = nthreads - ngcthreads;

    for (i = 1; i < nthreads; ++i) {
        language_threadarg_t *t = (language_threadarg_t *)malloc_s(sizeof(language_threadarg_t)); // ownership will be passed to the thread
        t->tid = i;
        t->barrier = &thread_init_done;
        if (i < nworker_threads) {
            uv_thread_create(&uvtid, language_threadfun, t);
            if (exclusive) {
                mask[i] = 1;
                uv_thread_setaffinity(&uvtid, mask, NULL, cpumasksize);
                mask[i] = 0;
            }
        }
        else if (i == nthreads - 1 && language_n_sweepthreads == 1) {
            uv_thread_create(&uvtid, language_concurrent_gc_threadfun, t);
        }
        else {
            uv_thread_create(&uvtid, language_parallel_gc_threadfun, t);
        }
        uv_thread_detach(&uvtid);
    }

    uv_barrier_wait(&thread_init_done);
}

_Atomic(unsigned) _threadedregion; // keep track of whether to prioritize IO or threading
_Atomic(uint16_t) io_loop_tid; // mark which thread is assigned to run the uv_loop

LANGUAGE_DLLEXPORT int language_in_threaded_region(void)
{
    return language_atomic_load_relaxed(&_threadedregion) != 0;
}

LANGUAGE_DLLEXPORT void language_enter_threaded_region(void)
{
    language_atomic_fetch_add(&_threadedregion, 1);
}

LANGUAGE_DLLEXPORT void language_exit_threaded_region(void)
{
    if (language_atomic_fetch_add(&_threadedregion, -1) == 1) {
        // make sure no more callbacks will run while user code continues
        // outside thread region and might touch an I/O object.
        LANGUAGE_UV_LOCK();
        LANGUAGE_UV_UNLOCK();
        // make sure thread 0 is not using the sleep_lock
        // so that it may enter the libuv event loop instead
        language_fence();
        language_wakeup_thread(language_atomic_load_relaxed(&io_loop_tid));
    }
}

LANGUAGE_DLLEXPORT void language_set_io_loop_tid(int16_t tid)
{
    if (tid < 0 || tid >= language_atomic_load_relaxed(&language_n_threads)) {
        // TODO: do we care if this thread has exited or not started yet,
        // since ptls2 might not be defined yet and visible on all threads yet
        return;
    }
    language_atomic_store_relaxed(&io_loop_tid, tid);
    language_fence();
    if (language_atomic_load_relaxed(&_threadedregion) == 0) {
        // make sure the previous io_loop_tid leaves the libuv event loop
        LANGUAGE_UV_LOCK();
        LANGUAGE_UV_UNLOCK();
        // make sure thread io_loop_tid is not using the sleep_lock
        // so that it may enter the libuv event loop instead
        language_wakeup_thread(tid);
    }
}

// Profiling stubs

void _language_mutex_init(language_mutex_t *lock, const char *name) LANGUAGE_NOTSAFEPOINT
{
    language_atomic_store_relaxed(&lock->owner, (language_task_t*)NULL);
    lock->count = 0;
    language_profile_lock_init(lock, name);
}

void _language_mutex_wait(language_task_t *self, language_mutex_t *lock, int safepoint)
{
    language_task_t *owner = language_atomic_load_relaxed(&lock->owner);
    if (owner == self) {
        lock->count++;
        return;
    }
    // Don't use LANGUAGE_TIMING for instant acquires, results in large blowup of events
    language_profile_lock_start_wait(lock);
    if (owner == NULL && language_atomic_cmpswap(&lock->owner, &owner, self)) {
        lock->count = 1;
        language_profile_lock_acquired(lock);
        return;
    }
    LANGUAGE_TIMING(LOCK_SPIN, LOCK_SPIN);
    while (1) {
        if (owner == NULL && language_atomic_cmpswap(&lock->owner, &owner, self)) {
            lock->count = 1;
            language_profile_lock_acquired(lock);
            return;
        }
        if (safepoint) {
            language_gc_safepoint_(self->ptls);
        }
        if (language_running_under_rr(0)) {
            // when running under `rr`, use system mutexes rather than spin locking
            uv_mutex_lock(&tls_lock);
            if (language_atomic_load_relaxed(&lock->owner))
                uv_cond_wait(&cond, &tls_lock);
            uv_mutex_unlock(&tls_lock);
        }
        language_cpu_suspend();
        owner = language_atomic_load_relaxed(&lock->owner);
    }
}

static void language_lock_frame_push(language_task_t *self, language_mutex_t *lock)
{
    language_ptls_t ptls = self->ptls;
    small_arraylist_t *locks = &ptls->locks;
    uint32_t len = locks->len;
    if (__unlikely(len >= locks->max)) {
        small_arraylist_grow(locks, 1);
    }
    else {
        locks->len = len + 1;
    }
    locks->items[len] = (void*)lock;
}

static void language_lock_frame_pop(language_task_t *self)
{
    language_ptls_t ptls = self->ptls;
    assert(ptls->locks.len > 0);
    ptls->locks.len--;
}

void _language_mutex_lock(language_task_t *self, language_mutex_t *lock)
{
    LANGUAGE_SIGATOMIC_BEGIN_self();
    _language_mutex_wait(self, lock, 1);
    language_lock_frame_push(self, lock);
}

int _language_mutex_trylock_nogc(language_task_t *self, language_mutex_t *lock)
{
    language_task_t *owner = language_atomic_load_acquire(&lock->owner);
    if (owner == self) {
        lock->count++;
        return 1;
    }
    if (owner == NULL && language_atomic_cmpswap(&lock->owner, &owner, self)) {
        lock->count = 1;
        return 1;
    }
    return 0;
}

int _language_mutex_trylock(language_task_t *self, language_mutex_t *lock)
{
    int got = _language_mutex_trylock_nogc(self, lock);
    if (got) {
        LANGUAGE_SIGATOMIC_BEGIN_self();
        language_lock_frame_push(self, lock);
    }
    return got;
}

void _language_mutex_unlock_nogc(language_mutex_t *lock)
{
#ifndef __clang_gcanalyzer__
    assert(language_atomic_load_relaxed(&lock->owner) == language_current_task &&
           "Unlocking a lock in a different thread.");
    if (--lock->count == 0) {
        language_profile_lock_release_start(lock);
        language_atomic_store_release(&lock->owner, (language_task_t*)NULL);
        language_cpu_wake();
        if (language_running_under_rr(0)) {
            // when running under `rr`, use system mutexes rather than spin locking
            uv_mutex_lock(&tls_lock);
            uv_cond_broadcast(&cond);
            uv_mutex_unlock(&tls_lock);
        }
        language_profile_lock_release_end(lock);
    }
#endif
}

void _language_mutex_unlock(language_task_t *self, language_mutex_t *lock)
{
    _language_mutex_unlock_nogc(lock);
    language_lock_frame_pop(self);
    LANGUAGE_SIGATOMIC_END_self();
    if (language_atomic_load_relaxed(&language_gc_have_pending_finalizers)) {
        language_gc_run_pending_finalizers(self); // may GC
    }
}


// Make gc alignment available for threading
// see threads.jl alignment
LANGUAGE_DLLEXPORT int language_alignment(size_t sz)
{
    return language_gc_alignment(sz);
}

#ifdef __cplusplus
}
#endif
