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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "code.h"
#include "language_internal.h"
#include "gc.h"
#include "threading.h"

#ifdef __cplusplus
extern "C" {
#endif


// thread sleep state

// default to DEFAULT_THREAD_SLEEP_THRESHOLD; set via $JULIA_THREAD_SLEEP_THRESHOLD
uint64_t sleep_threshold;

// thread should not be sleeping--it might need to do work.
static const int16_t not_sleeping = 0;

// it is acceptable for the thread to be sleeping.
static const int16_t sleeping = 1;

// this thread is dead.
static const int16_t sleeping_like_the_dead LANGUAGE_UNUSED = 2;

// a running count of how many threads are currently not_sleeping
// plus a running count of the number of in-flight wake-ups
// n.b. this may temporarily exceed language_n_threads
static _Atomic(int) nrunning = 0;

// invariant: No thread is ever asleep unless sleep_check_state is sleeping (or we have a wakeup signal pending).
// invariant: Any particular thread is not asleep unless that thread's sleep_check_state is sleeping.
// invariant: The transition of a thread state to sleeping must be followed by a check that there wasn't work pending for it.
// information: Observing thread not-sleeping is sufficient to ensure the target thread will subsequently inspect its local queue.
// information: Observing thread is-sleeping says it may be necessary to notify it at least once to wakeup. It may already be awake however for a variety of reasons.
// information: These observations require sequentially-consistent fences to be inserted between each of those operational phases.
// [^store_buffering_1]: These fences are used to avoid the cycle 2b -> 1a -> 1b -> 2a -> 2b where
// * Dequeuer:
//   * 1: `language_atomic_store_relaxed(&ptls->sleep_check_state, sleeping)`
// * Enqueuer:
//   * 2: `language_atomic_load_relaxed(&ptls->sleep_check_state)` in `language_wakeup_thread` returns `not_sleeping`
// i.e., the dequeuer misses the enqueue and enqueuer misses the sleep state transition.
// [^store_buffering_2]: and also
// * Enqueuer:
//   * 1a: `language_atomic_store_relaxed(language_uv_n_waiters, 1)` in `LANGUAGE_UV_LOCK`
//   * 1b: "cheap read" of `handle->pending` in `uv_async_send` (via `LANGUAGE_UV_LOCK`) loads `0`
// * Dequeuer:
//   * 2a: store `2` to `handle->pending` in `uv_async_send` (via `LANGUAGE_UV_LOCK` in `language_task_get_next`)
//   * 2b: `language_atomic_load_relaxed(language_uv_n_waiters)` in `language_task_get_next` returns `0`
// i.e., the dequeuer misses the `n_waiters` is set and enqueuer misses the `uv_stop` flag (in `signal_async`) transition to cleared

JULIA_DEBUG_SLEEPWAKE(
uint64_t wakeup_enter;
uint64_t wakeup_leave;
uint64_t io_wakeup_enter;
uint64_t io_wakeup_leave;
);

LANGUAGE_DLLEXPORT int language_set_task_tid(language_task_t *task, int16_t tid) LANGUAGE_NOTSAFEPOINT
{
    // Try to acquire the lock on this task.
    int16_t was = language_atomic_load_relaxed(&task->tid);
    if (was == tid)
        return 1;
    if (was == -1)
        return language_atomic_cmpswap(&task->tid, &was, tid) || was == tid;
    return 0;
}

LANGUAGE_DLLEXPORT int language_set_task_threadpoolid(language_task_t *task, int8_t tpid) LANGUAGE_NOTSAFEPOINT
{
    if (tpid < -1 || tpid >= language_n_threadpools)
        return 0;
    task->threadpoolid = tpid;
    return 1;
}

// GC functions used
extern int language_gc_mark_queue_obj_explicit(language_gc_mark_cache_t *gc_cache,
                                         language_gc_markqueue_t *mq, language_value_t *obj) LANGUAGE_NOTSAFEPOINT;

// parallel task runtime
// ---

LANGUAGE_DLLEXPORT uint32_t language_rand_ptls(uint32_t max)
{
    language_ptls_t ptls = language_current_task->ptls;
    return cong(max, &ptls->rngseed);
}

// initialize the threading infrastructure
// (called only by the main thread)
void language_init_threadinginfra(void)
{
    /* initialize the synchronization trees pool */
    sleep_threshold = DEFAULT_THREAD_SLEEP_THRESHOLD;
    char *cp = getenv(THREAD_SLEEP_THRESHOLD_NAME);
    if (cp) {
        if (!strncasecmp(cp, "infinite", 8))
            sleep_threshold = UINT64_MAX;
        else
            sleep_threshold = (uint64_t)strtol(cp, NULL, 10);
    }
}


void LANGUAGE_NORETURN language_finish_task(language_task_t *ct);

static inline int may_mark(void) LANGUAGE_NOTSAFEPOINT
{
    return (language_atomic_load(&gc_n_threads_marking) > 0);
}

static inline int may_sweep(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    return (language_atomic_load(&ptls->gc_sweeps_requested) > 0);
}

// parallel gc thread function
void language_parallel_gc_threadfun(void *arg)
{
    language_threadarg_t *targ = (language_threadarg_t*)arg;

    // initialize this thread (set tid and create heap)
    language_ptls_t ptls = language_init_threadtls(targ->tid);
    void *stack_lo, *stack_hi;
    language_init_stack_limits(0, &stack_lo, &stack_hi);
    // warning: this changes `language_current_task`, so be careful not to call that from this function
    language_task_t *ct = language_init_root_task(ptls, stack_lo, stack_hi);
    LANGUAGE_GC_PROMISE_ROOTED(ct);
    (void)language_atomic_fetch_add_relaxed(&nrunning, -1);
    // wait for all threads
    language_gc_state_set(ptls, LANGUAGE_GC_STATE_WAITING, LANGUAGE_GC_STATE_UNSAFE);
    uv_barrier_wait(targ->barrier);

    // free the thread argument here
    free(targ);

    while (1) {
        uv_mutex_lock(&gc_threads_lock);
        while (!may_mark() && !may_sweep(ptls)) {
            uv_cond_wait(&gc_threads_cond, &gc_threads_lock);
        }
        uv_mutex_unlock(&gc_threads_lock);
        gc_mark_loop_parallel(ptls, 0);
        if (may_sweep(ptls)) { // not an else!
            gc_sweep_pool_parallel(ptls);
            language_atomic_fetch_add(&ptls->gc_sweeps_requested, -1);
        }
    }
}

// concurrent gc thread function
void language_concurrent_gc_threadfun(void *arg)
{
    language_threadarg_t *targ = (language_threadarg_t*)arg;

    // initialize this thread (set tid and create heap)
    language_ptls_t ptls = language_init_threadtls(targ->tid);
    void *stack_lo, *stack_hi;
    language_init_stack_limits(0, &stack_lo, &stack_hi);
    // warning: this changes `language_current_task`, so be careful not to call that from this function
    language_task_t *ct = language_init_root_task(ptls, stack_lo, stack_hi);
    LANGUAGE_GC_PROMISE_ROOTED(ct);
    (void)language_atomic_fetch_add_relaxed(&nrunning, -1);
    // wait for all threads
    language_gc_state_set(ptls, LANGUAGE_GC_STATE_WAITING, LANGUAGE_GC_STATE_UNSAFE);
    uv_barrier_wait(targ->barrier);

    // free the thread argument here
    free(targ);

    while (1) {
        uv_sem_wait(&gc_sweep_assists_needed);
        gc_free_pages();
    }
}

// thread function: used by all mutator threads except the main thread
void language_threadfun(void *arg)
{
    language_threadarg_t *targ = (language_threadarg_t*)arg;

    // initialize this thread (set tid, create heap, set up root task)
    language_ptls_t ptls = language_init_threadtls(targ->tid);
    void *stack_lo, *stack_hi;
    language_init_stack_limits(0, &stack_lo, &stack_hi);
    // warning: this changes `language_current_task`, so be careful not to call that from this function
    language_task_t *ct = language_init_root_task(ptls, stack_lo, stack_hi);
    LANGUAGE_GC_PROMISE_ROOTED(ct);

    // wait for all threads
    language_gc_state_set(ptls, LANGUAGE_GC_STATE_SAFE, LANGUAGE_GC_STATE_UNSAFE);
    uv_barrier_wait(targ->barrier);

    // free the thread argument here
    free(targ);

    (void)language_gc_unsafe_enter(ptls);
    language_finish_task(ct); // noreturn
}



void language_init_thread_scheduler(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    uv_mutex_init(&ptls->sleep_lock);
    uv_cond_init(&ptls->wake_signal);
    // record that there is now another thread that may be used to schedule work
    // we will decrement this again in scheduler_delete_thread, only slightly
    // in advance of pthread_join (which hopefully itself also had been
    // adopted by now and is included in nrunning too)
    (void)language_atomic_fetch_add_relaxed(&nrunning, 1);
    // n.b. this is the only point in the code where we ignore the invariants on the ordering of nrunning
    // since we are being initialized from foreign code, we could not necessarily have expected or predicted that to happen
}

int language_running_under_rr(int recheck)
{
#ifdef _OS_LINUX_
#define RR_CALL_BASE 1000
#define SYS_rrcall_check_presence (RR_CALL_BASE + 8)
    static _Atomic(int) is_running_under_rr = 0;
    int rr = language_atomic_load_relaxed(&is_running_under_rr);
    if (rr == 0 || recheck) {
        int ret = syscall(SYS_rrcall_check_presence, 0, 0, 0, 0, 0, 0);
        if (ret == -1)
            // Should always be ENOSYS, but who knows what people do for
            // unknown syscalls with their seccomp filters, so just say
            // that we don't have rr.
            rr = 2;
        else
            rr = 1;
        language_atomic_store_relaxed(&is_running_under_rr, rr);
    }
    return rr == 1;
#else
    return 0;
#endif
}


//  sleep_check_after_threshold() -- if sleep_threshold ns have passed, return 1
static int sleep_check_after_threshold(uint64_t *start_cycles) LANGUAGE_NOTSAFEPOINT
{
    JULIA_DEBUG_SLEEPWAKE( return 1 ); // hammer on the sleep/wake logic much harder
    /**
     * This wait loop is a bit of a worst case for rr - it needs timer access,
     * which are slow and it busy loops in user space, which prevents the
     * scheduling logic from switching to other threads. Just don't bother
     * trying to wait here
     */
    if (language_running_under_rr(0))
        return 1;
    if (!(*start_cycles)) {
        *start_cycles = language_hrtime();
        return 0;
    }
    uint64_t elapsed_cycles = language_hrtime() - (*start_cycles);
    if (elapsed_cycles >= sleep_threshold) {
        *start_cycles = 0;
        return 1;
    }
    return 0;
}

static int set_not_sleeping(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    if (language_atomic_load_relaxed(&ptls->sleep_check_state) != not_sleeping) {
        if (language_atomic_exchange_relaxed(&ptls->sleep_check_state, not_sleeping) != not_sleeping) {
            return 1;
        }
    }
    int wasrunning = language_atomic_fetch_add_relaxed(&nrunning, -1); // consume in-flight wakeup
    assert(wasrunning > 1); (void)wasrunning;
    return 0;
}

static int wake_thread(int16_t tid) LANGUAGE_NOTSAFEPOINT
{
    language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[tid];

    if (language_atomic_load_relaxed(&ptls2->sleep_check_state) != not_sleeping) {
        int8_t state = sleeping;
        if (language_atomic_cmpswap_relaxed(&ptls2->sleep_check_state, &state, not_sleeping)) {
            int wasrunning = language_atomic_fetch_add_relaxed(&nrunning, 1); // increment in-flight wakeup count
            assert(wasrunning); (void)wasrunning;
            LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKE(ptls2, state);
            uv_mutex_lock(&ptls2->sleep_lock);
            uv_cond_signal(&ptls2->wake_signal);
            uv_mutex_unlock(&ptls2->sleep_lock);
            return 1;
        }
    }
    return 0;
}


static void wake_libuv(void) LANGUAGE_NOTSAFEPOINT
{
    JULIA_DEBUG_SLEEPWAKE( io_wakeup_enter = cycleclock() );
    language_wake_libuv();
    JULIA_DEBUG_SLEEPWAKE( io_wakeup_leave = cycleclock() );
}

/* ensure thread tid is awake if necessary */
LANGUAGE_DLLEXPORT void language_wakeup_thread(int16_t tid) LANGUAGE_NOTSAFEPOINT
{
    language_task_t *ct = language_current_task;
    int16_t self = language_atomic_load_relaxed(&ct->tid);
    if (tid != self)
        language_fence(); // [^store_buffering_1]
    language_task_t *uvlock = language_atomic_load_relaxed(&language_uv_mutex.owner);
    JULIA_DEBUG_SLEEPWAKE( wakeup_enter = cycleclock() );
    if (tid == self || tid == -1) {
        // we're already awake, but make sure we'll exit uv_run
        // and that nrunning is updated if this is now considered in-flight
        language_ptls_t ptls = ct->ptls;
        if (language_atomic_load_relaxed(&ptls->sleep_check_state) != not_sleeping) {
            if (language_atomic_exchange_relaxed(&ptls->sleep_check_state, not_sleeping) != not_sleeping) {
                int wasrunning = language_atomic_fetch_add_relaxed(&nrunning, 1);
                assert(wasrunning); (void)wasrunning;
                LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKEUP(ptls);
            }
        }
        if (uvlock == ct)
            uv_stop(language_global_event_loop());
    }
    else {
        // something added to the sticky-queue: notify that thread
        if (wake_thread(tid) && uvlock != ct) {
            // check if we need to notify uv_run too
            language_fence();
            language_ptls_t other = language_atomic_load_relaxed(&language_all_tls_states)[tid];
            language_task_t *tid_task = language_atomic_load_relaxed(&other->current_task);
            // now that we have changed the thread to not-sleeping, ensure that
            // either it has not yet acquired the libuv lock, or that it will
            // observe the change of state to not_sleeping
            if (language_atomic_load_relaxed(&language_uv_mutex.owner) == tid_task)
                wake_libuv();
        }
    }
    // check if the other threads might be sleeping
    if (tid == -1) {
        // something added to the multi-queue: notify all threads
        // in the future, we might want to instead wake some fraction of threads,
        // and let each of those wake additional threads if they find work
        int anysleep = 0;
        int nthreads = language_atomic_load_acquire(&language_n_threads);
        for (tid = 0; tid < nthreads; tid++) {
            if (tid != self)
                anysleep |= wake_thread(tid);
        }
        // check if we need to notify uv_run too
        if (uvlock != ct && anysleep) {
            language_fence();
            if (language_atomic_load_relaxed(&language_uv_mutex.owner) != NULL)
                wake_libuv();
        }
    }
    JULIA_DEBUG_SLEEPWAKE( wakeup_leave = cycleclock() );
}


// get the next runnable task
static language_task_t *get_next_task(language_value_t *trypoptask, language_value_t *q)
{
    language_gc_safepoint();
    language_task_t *task = (language_task_t*)language_apply_generic(trypoptask, &q, 1);
    if (language_is_task(task)) {
        int self = language_atomic_load_relaxed(&language_current_task->tid);
        language_set_task_tid(task, self);
        return task;
    }
    return NULL;
}

static int check_empty(language_value_t *checkempty)
{
    return language_apply_generic(checkempty, NULL, 0) == language_true;
}

language_task_t *wait_empty LANGUAGE_GLOBALLY_ROOTED;
void language_wait_empty_begin(void);
void language_wait_empty_end(void);

void language_task_wait_empty(void)
{
    language_task_t *ct = language_current_task;
    if (language_atomic_load_relaxed(&ct->tid) == 0 && language_base_module) {
        language_wait_empty_begin();
        language_value_t *f = language_get_global(language_base_module, language_symbol("wait"));
        wait_empty = ct;
        size_t lastage = ct->world_age;
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        if (f)
            language_apply_generic(f, NULL, 0);
        // we are back from language_task_get_next now
        ct->world_age = lastage;
        wait_empty = NULL;
        // TODO: move this lock acquire to before the wait_empty return and the
        // unlock to the caller, so that we ensure new work (from uv_unref
        // objects) didn't unexpectedly get scheduled and start running behind
        // our back during the function return
        LANGUAGE_UV_LOCK();
        language_wait_empty_end();
        LANGUAGE_UV_UNLOCK();
    }
}

static int may_sleep(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    // sleep_check_state is only transitioned from not_sleeping to sleeping
    // by the thread itself. As a result, if this returns false, it will
    // continue returning false. If it returns true, we know the total
    // modification order of the fences.
    language_fence(); // [^store_buffering_1] [^store_buffering_2]
    return language_atomic_load_relaxed(&ptls->sleep_check_state) == sleeping;
}


LANGUAGE_DLLEXPORT language_task_t *language_task_get_next(language_value_t *trypoptask, language_value_t *q, language_value_t *checkempty)
{
    language_task_t *ct = language_current_task;
    uint64_t start_cycles = 0;

    while (1) {
        language_task_t *task = get_next_task(trypoptask, q);
        if (task)
            return task;

        // quick, race-y check to see if there seems to be any stuff in there
        language_cpu_pause();
        if (!check_empty(checkempty)) {
            start_cycles = 0;
            continue;
        }

        language_cpu_pause();
        language_ptls_t ptls = ct->ptls;
        if (sleep_check_after_threshold(&start_cycles) || (ptls->tid == language_atomic_load_relaxed(&io_loop_tid) && (!language_atomic_load_relaxed(&_threadedregion) || wait_empty))) {
            // acquire sleep-check lock
            assert(language_atomic_load_relaxed(&ptls->sleep_check_state) == not_sleeping);
            language_atomic_store_relaxed(&ptls->sleep_check_state, sleeping);
            language_fence(); // [^store_buffering_1]
            LANGUAGE_PROBE_RT_SLEEP_CHECK_SLEEP(ptls);
            if (!check_empty(checkempty)) { // uses relaxed loads
                if (set_not_sleeping(ptls)) {
                    LANGUAGE_PROBE_RT_SLEEP_CHECK_TASKQ_WAKE(ptls);
                }
                continue;
            }
            task = get_next_task(trypoptask, q); // note: this should not yield
            if (ptls != ct->ptls) {
                // sigh, a yield was detected, so let's go ahead and handle it anyway by starting over
                ptls = ct->ptls;
                if (set_not_sleeping(ptls)) {
                    LANGUAGE_PROBE_RT_SLEEP_CHECK_TASK_WAKE(ptls);
                }
                if (task)
                    return task;
                continue;
            }
            if (task) {
                if (set_not_sleeping(ptls)) {
                    LANGUAGE_PROBE_RT_SLEEP_CHECK_TASK_WAKE(ptls);
                }
                return task;
            }

            // IO is always permitted, but outside a threaded region, only
            // thread 0 will process messages.
            // Inside a threaded region, any thread can listen for IO messages,
            // and one thread should win this race and watch the event loop,
            // but we bias away from idle threads getting parked here.
            //
            // The reason this works is somewhat convoluted, and closely tied to [^store_buffering_1]:
            //  - After decrementing _threadedregion, the thread is required to
            //    call language_wakeup_thread(0), that will kick out any thread who is
            //    already there, and then eventually thread 0 will get here.
            //  - Inside a _threadedregion, there must exist at least one
            //    thread that has a happens-before relationship on the libuv lock
            //    before reaching this decision point in the code who will see
            //    the lock as unlocked and thus must win this race here.
            int uvlock = 0;
            if (language_atomic_load_relaxed(&_threadedregion)) {
                uvlock = language_mutex_trylock(&language_uv_mutex);
            }
            else if (ptls->tid == language_atomic_load_relaxed(&io_loop_tid)) {
                uvlock = 1;
                LANGUAGE_UV_LOCK();
            }
            else {
                // Since we might have started some IO work, we might need
                // to ensure tid = 0 will go watch that new event source.
                // If trylock would have succeeded, that may have been our
                // responsibility, so need to make sure thread 0 will take care
                // of us.
                if (language_atomic_load_relaxed(&language_uv_mutex.owner) == NULL) // aka trylock
                    language_wakeup_thread(0);
            }
            if (uvlock) {
                int enter_eventloop = may_sleep(ptls);
                int active = 0;
                if (language_atomic_load_relaxed(&language_uv_n_waiters) != 0)
                    // if we won the race against someone who actually needs
                    // the lock to do real work, we need to let them have it instead
                    enter_eventloop = 0;
                if (enter_eventloop) {
                    uv_loop_t *loop = language_global_event_loop();
                    loop->stop_flag = 0;
                    JULIA_DEBUG_SLEEPWAKE( ptls->uv_run_enter = cycleclock() );
                    active = uv_run(loop, UV_RUN_ONCE);
                    JULIA_DEBUG_SLEEPWAKE( ptls->uv_run_leave = cycleclock() );
                    language_gc_safepoint();
                }
                LANGUAGE_UV_UNLOCK();
                // optimization: check again first if we may have work to do.
                // Otherwise we got a spurious wakeup since some other thread
                // that just wanted to steal libuv from us. We will just go
                // right back to sleep on the individual wake signal to let
                // them take it from us without conflict.
                if (active || !may_sleep(ptls)) {
                    if (set_not_sleeping(ptls)) {
                        LANGUAGE_PROBE_RT_SLEEP_CHECK_UV_WAKE(ptls);
                    }
                    start_cycles = 0;
                    continue;
                }
                if (!enter_eventloop && !language_atomic_load_relaxed(&_threadedregion) && ptls->tid == language_atomic_load_relaxed(&io_loop_tid)) {
                    // thread 0 is the only thread permitted to run the event loop
                    // so it needs to stay alive, just spin-looping if necessary
                    if (set_not_sleeping(ptls)) {
                        LANGUAGE_PROBE_RT_SLEEP_CHECK_UV_WAKE(ptls);
                    }
                    start_cycles = 0;
                    continue;
                }
            }

            // any thread which wants us running again will have to observe
            // sleep_check_state==sleeping and increment nrunning for us
            int wasrunning = language_atomic_fetch_add_relaxed(&nrunning, -1);
            assert(wasrunning);
            if (wasrunning == 1) {
                // This was the last running thread, and there is no thread with !may_sleep
                // so make sure io_loop_tid is notified to check wait_empty
                // TODO: this also might be a good time to check again that
                // libuv's queue is truly empty, instead of during delete_thread
                int16_t tid2 = 0;
                if (ptls->tid != tid2) {
                    language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[tid2];
                    uv_mutex_lock(&ptls2->sleep_lock);
                    uv_cond_signal(&ptls2->wake_signal);
                    uv_mutex_unlock(&ptls2->sleep_lock);
                }
            }

            // the other threads will just wait for an individual wake signal to resume
            JULIA_DEBUG_SLEEPWAKE( ptls->sleep_enter = cycleclock() );
            int8_t gc_state = language_gc_safe_enter(ptls);
            uv_mutex_lock(&ptls->sleep_lock);
            while (may_sleep(ptls)) {
                if (ptls->tid == 0) {
                    task = wait_empty;
                    if (task && language_atomic_load_relaxed(&nrunning) == 0) {
                        wasrunning = language_atomic_fetch_add_relaxed(&nrunning, 1);
                        assert(!wasrunning);
                        wasrunning = !set_not_sleeping(ptls);
                        assert(!wasrunning);
                        LANGUAGE_PROBE_RT_SLEEP_CHECK_TASK_WAKE(ptls);
                        if (!ptls->finalizers_inhibited)
                            ptls->finalizers_inhibited++; // this annoyingly is rather sticky (we should like to reset it at the end of language_task_wait_empty)
                        break;
                    }
                    task = NULL;
                }
                // else should we warn the user of certain deadlock here if tid == 0 && nrunning == 0?
                uv_cond_wait(&ptls->wake_signal, &ptls->sleep_lock);
            }
            assert(language_atomic_load_relaxed(&ptls->sleep_check_state) == not_sleeping);
            assert(language_atomic_load_relaxed(&nrunning));
            start_cycles = 0;
            uv_mutex_unlock(&ptls->sleep_lock);
            JULIA_DEBUG_SLEEPWAKE( ptls->sleep_leave = cycleclock() );
            language_gc_safe_leave(ptls, gc_state); // contains language_gc_safepoint
            if (task) {
                assert(task == wait_empty);
                wait_empty = NULL;
                return task;
            }
        }
        else {
            // maybe check the kernel for new messages too
            language_process_events();
        }
    }
}

void scheduler_delete_thread(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    int notsleeping = language_atomic_exchange_relaxed(&ptls->sleep_check_state, sleeping_like_the_dead) == not_sleeping;
    language_fence();
    if (notsleeping) {
        if (language_atomic_load_relaxed(&nrunning) == 1) {
            language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[language_atomic_load_relaxed(&io_loop_tid)];
            // This was the last running thread, and there is no thread with !may_sleep
            // so make sure tid 0 is notified to check wait_empty
            uv_mutex_lock(&ptls2->sleep_lock);
            uv_cond_signal(&ptls2->wake_signal);
            uv_mutex_unlock(&ptls2->sleep_lock);
        }
    }
    else {
        language_atomic_fetch_add_relaxed(&nrunning, 1);
    }
    language_wakeup_thread(0); // force thread 0 to see that we do not have the IO lock (and am dead)
    language_atomic_fetch_add_relaxed(&nrunning, -1);
}

#ifdef __cplusplus
}
#endif
