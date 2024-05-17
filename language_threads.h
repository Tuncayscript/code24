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

// Meant to be included in <code.h>
#ifndef LANGUAGE_THREADS_H
#define LANGUAGE_THREADS_H

#include "language_atomics.h"
#include "work-stealing-queue.h"
#ifndef _OS_WINDOWS_
#include "pthread.h"
#endif
// threading ------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif


LANGUAGE_DLLEXPORT int16_t language_threadid(void);
LANGUAGE_DLLEXPORT int8_t language_threadpoolid(int16_t tid) LANGUAGE_NOTSAFEPOINT;

// JULIA_ENABLE_THREADING may be controlled by altering JULIA_THREADS in Make.user

// When running into scheduler issues, this may help provide information on the
// sequence of events that led to the issue. Normally, it is empty.
//#define JULIA_DEBUG_SLEEPWAKE(x) x
#define JULIA_DEBUG_SLEEPWAKE(x)

//  Options for task switching algorithm (in order of preference):
// LANGUAGE_HAVE_ASM -- mostly setjmp
// LANGUAGE_HAVE_ASM && LANGUAGE_HAVE_UNW_CONTEXT -- libunwind-based
// LANGUAGE_HAVE_UNW_CONTEXT -- libunwind-based
// LANGUAGE_HAVE_UCONTEXT -- posix standard API, requires syscall for resume
// LANGUAGE_HAVE_SIGALTSTACK -- requires several syscall for start, setjmp for resume

#ifdef _OS_WINDOWS_
#define LANGUAGE_HAVE_UCONTEXT
typedef win32_ucontext_t language_stack_context_t;
typedef language_stack_context_t _language_ucontext_t;

#elif defined(_OS_OPENBSD_)
#define LANGUAGE_HAVE_UNW_CONTEXT
#define UNW_LOCAL_ONLY
#include <libunwind.h>
typedef unw_context_t _language_ucontext_t;
typedef struct {
    language_jmp_buf uc_mcontext;
} language_stack_context_t;

#else
typedef struct {
    language_jmp_buf uc_mcontext;
} language_stack_context_t;
#if !defined(LANGUAGE_HAVE_UCONTEXT) && \
    !defined(LANGUAGE_HAVE_ASM) && \
    !defined(LANGUAGE_HAVE_UNW_CONTEXT) && \
    !defined(LANGUAGE_HAVE_SIGALTSTACK)
#if (defined(_CPU_X86_64_) || defined(_CPU_X86_) || defined(_CPU_AARCH64_) ||  \
     defined(_CPU_ARM_) || defined(_CPU_PPC64_))
#define LANGUAGE_HAVE_ASM
#endif
#if 0
// very slow, but more debugging
//#elif defined(_OS_DARWIN_)
//#define LANGUAGE_HAVE_UNW_CONTEXT
//#elif defined(_OS_LINUX_)
//#define LANGUAGE_HAVE_UNW_CONTEXT
#elif !defined(LANGUAGE_HAVE_ASM)
#define LANGUAGE_HAVE_UNW_CONTEXT // optimistically?
#endif
#endif

#if (!defined(LANGUAGE_HAVE_UNW_CONTEXT) && defined(LANGUAGE_HAVE_ASM)) || defined(LANGUAGE_HAVE_SIGALTSTACK)
typedef language_stack_context_t _language_ucontext_t;
#endif
#pragma GCC visibility push(default)
#if defined(LANGUAGE_HAVE_UNW_CONTEXT)
#define UNW_LOCAL_ONLY
#include <libunwind.h>
typedef unw_context_t _language_ucontext_t;
#endif
#if defined(LANGUAGE_HAVE_UCONTEXT)
#include <ucontext.h>
typedef ucontext_t _language_ucontext_t;
#endif
#pragma GCC visibility pop
#endif

typedef struct {
    union {
        _language_ucontext_t ctx;
        language_stack_context_t copy_ctx;
    };
#if defined(_COMPILER_TSAN_ENABLED_)
    void *tsan_state;
#endif
#if defined(_COMPILER_ASAN_ENABLED_)
    void *asan_fake_stack;
#endif
} language_ucontext_t;


// handle to reference an OS thread
#ifdef _OS_WINDOWS_
typedef HANDLE language_thread_t;
#else
typedef pthread_t language_thread_t;
#endif

struct _language_task_t;

// Recursive spin lock
typedef struct {
    _Atomic(struct _language_task_t*) owner;
    uint32_t count;
} language_mutex_t;

typedef struct {
    language_taggedvalue_t *freelist;   // root of list of free objects
    language_taggedvalue_t *newpages;   // root of list of chunks of free objects
    uint16_t osize;      // size of objects in this pool
} language_gc_pool_t;

typedef struct {
    _Atomic(int64_t) allocd;
    _Atomic(int64_t) pool_live_bytes;
    _Atomic(uint64_t) malloc;
    _Atomic(uint64_t) realloc;
    _Atomic(uint64_t) poolalloc;
    _Atomic(uint64_t) bigalloc;
    _Atomic(int64_t) free_acc;
    _Atomic(uint64_t) alloc_acc;
} language_thread_gc_num_t;

typedef struct {
    // variable for tracking weak references
    small_arraylist_t weak_refs;
    // live tasks started on this thread
    // that are holding onto a stack from the pool
    small_arraylist_t live_tasks;

    // variables for tracking malloc'd arrays
    struct _mallocarray_t *mallocarrays;
    struct _mallocarray_t *mafreelist;

    // variables for tracking big objects
    struct _bigval_t *big_objects;

    // variables for tracking "remembered set"
    arraylist_t _remset[2]; // contains language_value_t*
    // lower bound of the number of pointers inside remembered values
    int remset_nptr;
    arraylist_t *remset;
    arraylist_t *last_remset;

    // variables for allocating objects from pools
#define LANGUAGE_GC_N_MAX_POOLS 51 // conservative. must be kept in sync with `src/language_internal.h`
    language_gc_pool_t norm_pools[LANGUAGE_GC_N_MAX_POOLS];

#define LANGUAGE_N_STACK_POOLS 16
    small_arraylist_t free_stacks[LANGUAGE_N_STACK_POOLS];
} language_thread_heap_t;

typedef struct {
    ws_queue_t chunk_queue;
    ws_queue_t ptr_queue;
    arraylist_t reclaim_set;
} language_gc_markqueue_t;

typedef struct {
    // thread local increment of `perm_scanned_bytes`
    size_t perm_scanned_bytes;
    // thread local increment of `scanned_bytes`
    size_t scanned_bytes;
    // Number of queued big objects (<= 1024)
    size_t nbig_obj;
    // Array of queued big objects to be moved between the young list
    // and the old list.
    // A set low bit means that the object should be moved from the old list
    // to the young list (`mark_reset_age`).
    // Objects can only be put into this list when the mark bit is flipped to
    // `1` (atomically). Combining with the sync after marking,
    // this makes sure that a single objects can only appear once in
    // the lists (the mark bit cannot be flipped to `0` without sweeping)
    void *big_obj[1024];
} language_gc_mark_cache_t;

struct _language_bt_element_t;
struct _language_gc_pagemeta_t;

typedef struct {
    _Atomic(struct _language_gc_pagemeta_t *) bottom;
} language_gc_page_stack_t;

// This includes all the thread local states we care about for a thread.
// Changes to TLS field types must be reflected in codegen.
#define LANGUAGE_MAX_BT_SIZE 80000
typedef struct _language_tls_states_t {
    int16_t tid;
    int8_t threadpoolid;
    uint64_t rngseed;
    _Atomic(volatile size_t *) safepoint; // may be changed to the suspend page by any thread
    _Atomic(int8_t) sleep_check_state; // read/write from foreign threads
    // Whether it is safe to execute GC at the same time.
#define LANGUAGE_GC_STATE_UNSAFE 0
    // gc_state = 0 means the thread is running Julia code and is not
    //              safe to run concurrently to the GC
#define LANGUAGE_GC_STATE_WAITING 1
    // gc_state = 1 means the thread is doing GC or is waiting for the GC to
    //              finish.
#define LANGUAGE_GC_STATE_SAFE 2
    // gc_state = 2 means the thread is running unmanaged code that can be
    //              execute at the same time with the GC.
    _Atomic(int8_t) gc_state; // read from foreign threads
    // execution of certain certain impure
    // statements is prohibited from certain
    // callbacks (such as generated functions)
    // as it may make compilation undecidable
    int16_t in_pure_callback;
    int16_t in_finalizer;
    int16_t disable_gc;
    // Counter to disable finalizer **on the current thread**
    int finalizers_inhibited;
    language_thread_heap_t heap; // this is very large, and the offset is baked into codegen
    language_thread_gc_num_t gc_num;
    volatile sig_atomic_t defer_signal;
    _Atomic(struct _language_task_t*) current_task;
    struct _language_task_t *next_task;
    struct _language_task_t *previous_task;
    struct _language_task_t *root_task;
    struct _language_timing_block_t *timing_stack;
    void *stackbase;
    size_t stacksize;
    union {
        _language_ucontext_t base_ctx; // base context of stack
        // This hack is needed to support always_copy_stacks:
        language_stack_context_t copy_stack_ctx;
    };
    // Temp storage for exception thrown in signal handler. Not rooted.
    struct _language_value_t *sig_exception;
    // Temporary backtrace buffer. Scanned for gc roots when bt_size > 0.
    struct _language_bt_element_t *bt_data; // LANGUAGE_MAX_BT_SIZE + 1 elements long
    size_t bt_size;    // Size for backtrace in transit in bt_data
    // Temporary backtrace buffer used only for allocations profiler.
    struct _language_bt_element_t *profiling_bt_buffer;
    // Atomically set by the sender, reset by the handler.
    volatile _Atomic(sig_atomic_t) signal_request; // TODO: no actual reason for this to be _Atomic
    // Allow the sigint to be raised asynchronously
    // this is limited to the few places we do synchronous IO
    // we can make this more general (similar to defer_signal) if necessary
    volatile sig_atomic_t io_wait;
#ifdef _OS_WINDOWS_
    int needs_resetstkoflw;
#else
    void *signal_stack;
    size_t signal_stack_size;
#endif
    language_thread_t system_id;
    _Atomic(int16_t) suspend_count;
    arraylist_t finalizers;
    language_gc_page_stack_t page_metadata_allocd;
    language_gc_page_stack_t page_metadata_buffered;
    language_gc_markqueue_t mark_queue;
    language_gc_mark_cache_t gc_cache;
    arraylist_t sweep_objs;
    _Atomic(int64_t) gc_sweeps_requested;
    // Saved exception for previous *external* API call or NULL if cleared.
    // Access via language_exception_occurred().
    struct _language_value_t *previous_exception;

    // currently-held locks, to be released when an exception is thrown
    small_arraylist_t locks;

    JULIA_DEBUG_SLEEPWAKE(
        uint64_t uv_run_enter;
        uint64_t uv_run_leave;
        uint64_t sleep_enter;
        uint64_t sleep_leave;
    )

    // some hidden state (usually just because we don't have the type's size declaration)
#ifdef LANGUAGE_LIBRARY_EXPORTS
    uv_mutex_t sleep_lock;
    uv_cond_t wake_signal;
#endif
} language_tls_states_t;

#ifndef LANGUAGE_LIBRARY_EXPORTS
// deprecated (only for external consumers)
LANGUAGE_DLLEXPORT void *language_get_ptls_states(void);
#endif

// Update codegen version in `ccall.cpp` after changing either `pause` or `wake`
#ifdef __MIC__
#  define language_cpu_pause() _mm_delay_64(100)
#  define language_cpu_suspend() _mm_delay_64(100)
#  define language_cpu_wake() ((void)0)
#  define LANGUAGE_CPU_WAKE_NOOP 1
#elif defined(_CPU_X86_64_) || defined(_CPU_X86_)  /* !__MIC__ */
#  define language_cpu_pause() _mm_pause()
#  define language_cpu_suspend() _mm_pause()
#  define language_cpu_wake() ((void)0)
#  define LANGUAGE_CPU_WAKE_NOOP 1
#elif defined(_CPU_AARCH64_) || (defined(_CPU_ARM_) && __ARM_ARCH >= 7)
#  define language_cpu_pause() __asm__ volatile ("isb" ::: "memory")
#  define language_cpu_suspend() __asm__ volatile ("wfe" ::: "memory")
#  define language_cpu_wake() __asm__ volatile ("sev" ::: "memory")
#  define LANGUAGE_CPU_WAKE_NOOP 0
#else
#  define language_cpu_pause() ((void)0)
#  define language_cpu_suspend() ((void)0)
#  define language_cpu_wake() ((void)0)
#  define LANGUAGE_CPU_WAKE_NOOP 1
#endif

LANGUAGE_DLLEXPORT void (language_cpu_pause)(void);
LANGUAGE_DLLEXPORT void (language_cpu_suspend)(void);
LANGUAGE_DLLEXPORT void (language_cpu_wake)(void);

#ifdef __clang_gcanalyzer__
// Note that the sigint safepoint can also trigger GC, albeit less likely
void language_gc_safepoint_(language_ptls_t tls);
void language_sigint_safepoint(language_ptls_t tls);
#else
// gc safepoint and gc states
// This triggers a SegFault when we are in GC
// Assign it to a variable to make sure the compiler emit the load
// and to avoid Clang warning for -Wunused-volatile-lvalue
#define language_gc_safepoint_(ptls) do {                                            \
        language_signal_fence();                                                     \
        size_t safepoint_load = language_atomic_load_relaxed(&ptls->safepoint)[0];   \
        language_signal_fence();                                                     \
        (void)safepoint_load;                                                  \
    } while (0)
#define language_sigint_safepoint(ptls) do {                                         \
        language_signal_fence();                                                     \
        size_t safepoint_load = language_atomic_load_relaxed(&ptls->safepoint)[-1];  \
        language_signal_fence();                                                     \
        (void)safepoint_load;                                                  \
    } while (0)
#endif
STATIC_INLINE int8_t language_gc_state_set(language_ptls_t ptls, int8_t state,
                                     int8_t old_state)
{
    language_atomic_store_release(&ptls->gc_state, state);
    if (state == LANGUAGE_GC_STATE_UNSAFE || old_state == LANGUAGE_GC_STATE_UNSAFE)
        language_gc_safepoint_(ptls);
    return old_state;
}
STATIC_INLINE int8_t language_gc_state_save_and_set(language_ptls_t ptls,
                                              int8_t state)
{
    return language_gc_state_set(ptls, state, language_atomic_load_relaxed(&ptls->gc_state));
}
#ifdef __clang_gcanalyzer__
int8_t language_gc_unsafe_enter(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_LEAVE; // this could be a safepoint, but we will assume it is not
void language_gc_unsafe_leave(language_ptls_t ptls, int8_t state) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER;
int8_t language_gc_safe_enter(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER;
void language_gc_safe_leave(language_ptls_t ptls, int8_t state) LANGUAGE_NOTSAFEPOINT_LEAVE; // this might not be a safepoint, but we have to assume it could be (statically)
#else
#define language_gc_unsafe_enter(ptls) language_gc_state_save_and_set(ptls, LANGUAGE_GC_STATE_UNSAFE)
#define language_gc_unsafe_leave(ptls, state) ((void)language_gc_state_set(ptls, (state), LANGUAGE_GC_STATE_UNSAFE))
#define language_gc_safe_enter(ptls) language_gc_state_save_and_set(ptls, LANGUAGE_GC_STATE_SAFE)
#define language_gc_safe_leave(ptls, state) ((void)language_gc_state_set(ptls, (state), LANGUAGE_GC_STATE_SAFE))
#endif

LANGUAGE_DLLEXPORT void language_gc_enable_finalizers(struct _language_task_t *ct, int on);
LANGUAGE_DLLEXPORT void language_gc_disable_finalizers_internal(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_enable_finalizers_internal(void);
LANGUAGE_DLLEXPORT void language_gc_run_pending_finalizers(struct _language_task_t *ct);
extern LANGUAGE_DLLEXPORT _Atomic(int) language_gc_have_pending_finalizers;
LANGUAGE_DLLEXPORT int8_t language_gc_is_in_finalizer(void) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_wakeup_thread(int16_t tid);

#ifdef __cplusplus
}
#endif

#endif
