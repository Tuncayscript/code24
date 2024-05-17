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

#include "gc.h"
#include "gc-page-profiler.h"
#include "code.h"
#include "language_atomics.h"
#include "language_gcext.h"
#include "language_assert.h"
#ifdef __GLIBC__
#include <malloc.h> // for malloc_trim
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Number of GC threads that may run parallel marking
int language_n_markthreads;
// Number of GC threads that may run concurrent sweeping (0 or 1)
int language_n_sweepthreads;
// Number of threads currently running the GC mark-loop
_Atomic(int) gc_n_threads_marking;
// Number of threads sweeping
_Atomic(int) gc_n_threads_sweeping;
// Temporary for the `ptls->page_metadata_allocd` used during parallel sweeping (padded to avoid false sharing)
_Atomic(language_gc_padded_page_stack_t *) gc_allocd_scratch;
// `tid` of mutator thread that triggered GC
_Atomic(int) gc_master_tid;
// `tid` of first GC thread
int gc_first_tid;
// Mutex/cond used to synchronize wakeup of GC threads on parallel marking
uv_mutex_t gc_threads_lock;
uv_cond_t gc_threads_cond;
// To indicate whether concurrent sweeping should run
uv_sem_t gc_sweep_assists_needed;
// Mutex used to coordinate entry of GC threads in the mark loop
uv_mutex_t gc_queue_observer_lock;

// Linked list of callback functions

typedef void (*language_gc_cb_func_t)(void);

typedef struct language_gc_callback_list_t {
    struct language_gc_callback_list_t *next;
    language_gc_cb_func_t func;
} language_gc_callback_list_t;

static language_gc_callback_list_t *gc_cblist_root_scanner;
static language_gc_callback_list_t *gc_cblist_task_scanner;
static language_gc_callback_list_t *gc_cblist_pre_gc;
static language_gc_callback_list_t *gc_cblist_post_gc;
static language_gc_callback_list_t *gc_cblist_notify_external_alloc;
static language_gc_callback_list_t *gc_cblist_notify_external_free;
static language_gc_callback_list_t *gc_cblist_notify_gc_pressure;

#define gc_invoke_callbacks(ty, list, args) \
    do { \
        for (language_gc_callback_list_t *cb = list; \
                cb != NULL; \
                cb = cb->next) \
        { \
            ((ty)(cb->func)) args; \
        } \
    } while (0)

static void language_gc_register_callback(language_gc_callback_list_t **list,
        language_gc_cb_func_t func)
{
    while (*list != NULL) {
        if ((*list)->func == func)
            return;
        list = &((*list)->next);
    }
    *list = (language_gc_callback_list_t *)malloc_s(sizeof(language_gc_callback_list_t));
    (*list)->next = NULL;
    (*list)->func = func;
}

static void language_gc_deregister_callback(language_gc_callback_list_t **list,
        language_gc_cb_func_t func)
{
    while (*list != NULL) {
        if ((*list)->func == func) {
            language_gc_callback_list_t *tmp = *list;
            (*list) = (*list)->next;
            free(tmp);
            return;
        }
        list = &((*list)->next);
    }
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_root_scanner(language_gc_cb_root_scanner_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_root_scanner, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_root_scanner, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_task_scanner(language_gc_cb_task_scanner_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_task_scanner, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_task_scanner, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_pre_gc(language_gc_cb_pre_gc_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_pre_gc, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_pre_gc, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_post_gc(language_gc_cb_post_gc_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_post_gc, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_post_gc, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_external_alloc(language_gc_cb_notify_external_alloc_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_notify_external_alloc, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_notify_external_alloc, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_external_free(language_gc_cb_notify_external_free_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_notify_external_free, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_notify_external_free, (language_gc_cb_func_t)cb);
}

LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_gc_pressure(language_gc_cb_notify_gc_pressure_t cb, int enable)
{
    if (enable)
        language_gc_register_callback(&gc_cblist_notify_gc_pressure, (language_gc_cb_func_t)cb);
    else
        language_gc_deregister_callback(&gc_cblist_notify_gc_pressure, (language_gc_cb_func_t)cb);
}

// Protect all access to `finalizer_list_marked` and `to_finalize`.
// For accessing `ptls->finalizers`, the lock is needed if a thread
// is going to realloc the buffer (of its own list) or accessing the
// list of another thread
static language_mutex_t finalizers_lock;
static uv_mutex_t gc_cache_lock;

// mutex for gc-heap-snapshot.
language_mutex_t heapsnapshot_lock;

// Flag that tells us whether we need to support conservative marking
// of objects.
static _Atomic(int) support_conservative_marking = 0;

/**
 * Note about GC synchronization:
 *
 * When entering `language_gc_collect()`, `language_gc_running` is atomically changed from
 * `0` to `1` to make sure that only one thread can be running `_language_gc_collect`. Other
 * mutator threads that enters `language_gc_collect()` at the same time (or later calling
 * from unmanaged code) will wait in `language_gc_collect()` until the GC is finished.
 *
 * Before starting the mark phase the GC thread calls `language_safepoint_start_gc()`
 * and `language_gc_wait_for_the_world()`
 * to make sure all the thread are in a safe state for the GC. The function
 * activates the safepoint and wait for all the threads to get ready for the
 * GC (`gc_state != 0`). It also acquires the `finalizers` lock so that no
 * other thread will access them when the GC is running.
 *
 * During the mark and sweep phase of the GC, the mutator threads that are not running
 * the GC should either be running unmanaged code (or code section that does
 * not have a GC critical region mainly including storing to the stack or
 * another object) or paused at a safepoint and wait for the GC to finish.
 * If a thread want to switch from running unmanaged code to running managed
 * code, it has to perform a GC safepoint check after setting the `gc_state`
 * flag (see `language_gc_state_save_and_set()`. it is possible that the thread might
 * have `gc_state == 0` in the middle of the GC transition back before entering
 * the safepoint. This is fine since the thread won't be executing any GC
 * critical region during that time).
 *
 * The finalizers are run after the GC finishes in normal mode (the `gc_state`
 * when `language_gc_collect` is called) with `language_in_finalizer = 1`. (TODO:) When we
 * have proper support of GC transition in codegen, we should execute the
 * finalizers in unmanaged (GC safe) mode.
 */

language_gc_num_t gc_num = {0};
static size_t last_long_collect_interval;
int gc_n_threads;
language_ptls_t* gc_all_tls_states;
gc_heapstatus_t gc_heap_stats = {0};
int next_sweep_full = 0;
const uint64_t _language_buff_tag[3] = {0x4eadc0004eadc000ull, 0x4eadc0004eadc000ull, 0x4eadc0004eadc000ull}; // aka 0xHEADER00
LANGUAGE_DLLEXPORT uintptr_t language_get_buff_tag(void) LANGUAGE_NOTSAFEPOINT
{
    return language_buff_tag;
}

// List of marked big objects.  Not per-thread.  Accessed only by master thread.
bigval_t *big_objects_marked = NULL;

// -- Finalization --
// `ptls->finalizers` and `finalizer_list_marked` might have tagged pointers.
// If an object pointer has the lowest bit set, the next pointer is an unboxed c function pointer.
// If an object pointer has the second lowest bit set, the current pointer is a c object pointer.
//   It must be aligned at least 4, and it finalized immediately (at "quiescence").
// `to_finalize` should not have tagged pointers.
arraylist_t finalizer_list_marked;
arraylist_t to_finalize;
LANGUAGE_DLLEXPORT _Atomic(int) language_gc_have_pending_finalizers = 0;


NOINLINE uintptr_t gc_get_stack_ptr(void)
{
    return (uintptr_t)language_get_frame_addr();
}

void language_gc_wait_for_the_world(language_ptls_t* gc_all_tls_states, int gc_n_threads);

// malloc wrappers, aligned allocation

#if defined(_OS_WINDOWS_)
STATIC_INLINE void *language_malloc_aligned(size_t sz, size_t align)
{
    return _aligned_malloc(sz ? sz : 1, align);
}
STATIC_INLINE void *language_realloc_aligned(void *p, size_t sz, size_t oldsz,
                                       size_t align)
{
    (void)oldsz;
    return _aligned_realloc(p, sz ? sz : 1, align);
}
STATIC_INLINE void language_free_aligned(void *p) LANGUAGE_NOTSAFEPOINT
{
    _aligned_free(p);
}
#else
STATIC_INLINE void *language_malloc_aligned(size_t sz, size_t align)
{
#if defined(_P64) || defined(__APPLE__)
    if (align <= 16)
        return malloc(sz);
#endif
    void *ptr;
    if (posix_memalign(&ptr, align, sz))
        return NULL;
    return ptr;
}
STATIC_INLINE void *language_realloc_aligned(void *d, size_t sz, size_t oldsz,
                                       size_t align)
{
#if defined(_P64) || defined(__APPLE__)
    if (align <= 16)
        return realloc(d, sz);
#endif
    void *b = language_malloc_aligned(sz, align);
    if (b != NULL) {
        memcpy(b, d, oldsz > sz ? sz : oldsz);
        free(d);
    }
    return b;
}
STATIC_INLINE void language_free_aligned(void *p) LANGUAGE_NOTSAFEPOINT
{
    free(p);
}
#endif
#define malloc_cache_align(sz) language_malloc_aligned(sz, LANGUAGE_CACHE_BYTE_ALIGNMENT)
#define realloc_cache_align(p, sz, oldsz) language_realloc_aligned(p, sz, oldsz, LANGUAGE_CACHE_BYTE_ALIGNMENT)

static void schedule_finalization(void *o, void *f) LANGUAGE_NOTSAFEPOINT
{
    arraylist_push(&to_finalize, o);
    arraylist_push(&to_finalize, f);
    // doesn't need release, since we'll keep checking (on the reader) until we see the work and
    // release our lock, and that will have a release barrier by then
    language_atomic_store_relaxed(&language_gc_have_pending_finalizers, 1);
}

static void run_finalizer(language_task_t *ct, void *o, void *ff)
{
    int ptr_finalizer = gc_ptr_tag(o, 1);
    o = gc_ptr_clear_tag(o, 3);
    if (ptr_finalizer) {
        ((void (*)(void*))ff)((void*)o);
        return;
    }
    LANGUAGE_TRY {
        size_t last_age = ct->world_age;
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        language_apply_generic((language_value_t*)ff, (language_value_t**)&o, 1);
        ct->world_age = last_age;
    }
    LANGUAGE_CATCH {
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "error in running finalizer: ");
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
        jlbacktrace(); // written to STDERR_FILENO
    }
}

// if `need_sync` is true, the `list` is the `finalizers` list of another
// thread and we need additional synchronizations
static void finalize_object(arraylist_t *list, language_value_t *o,
                            arraylist_t *copied_list, int need_sync) LANGUAGE_NOTSAFEPOINT
{
    // The acquire load makes sure that the first `len` objects are valid.
    // If `need_sync` is true, all mutations of the content should be limited
    // to the first `oldlen` elements and no mutation is allowed after the
    // new length is published with the `cmpxchg` at the end of the function.
    // This way, the mutation should not conflict with the owning thread,
    // which only writes to locations later than `len`
    // and will not resize the buffer without acquiring the lock.
    size_t len = need_sync ? language_atomic_load_acquire((_Atomic(size_t)*)&list->len) : list->len;
    size_t oldlen = len;
    void **items = list->items;
    size_t j = 0;
    for (size_t i = 0; i < len; i += 2) {
        void *v = items[i];
        int move = 0;
        if (o == (language_value_t*)gc_ptr_clear_tag(v, 1)) {
            void *f = items[i + 1];
            move = 1;
            arraylist_push(copied_list, v);
            arraylist_push(copied_list, f);
        }
        if (move || __unlikely(!v)) {
            // remove item
        }
        else {
            if (j < i) {
                items[j] = items[i];
                items[j+1] = items[i+1];
            }
            j += 2;
        }
    }
    len = j;
    if (oldlen == len)
        return;
    if (need_sync) {
        // The memset needs to be unconditional since the thread might have
        // already read the length.
        // The `memset` (like any other content mutation) has to be done
        // **before** the `cmpxchg` which publishes the length.
        memset(&items[len], 0, (oldlen - len) * sizeof(void*));
        language_atomic_cmpswap((_Atomic(size_t)*)&list->len, &oldlen, len);
    }
    else {
        list->len = len;
    }
}

// The first two entries are assumed to be empty and the rest are assumed to
// be pointers to `language_value_t` objects
static void language_gc_push_arraylist(language_task_t *ct, arraylist_t *list) LANGUAGE_NOTSAFEPOINT
{
    void **items = list->items;
    items[0] = (void*)LANGUAGE_GC_ENCODE_PUSHARGS(list->len - 2);
    items[1] = ct->gcstack;
    ct->gcstack = (language_gcframe_t*)items;
}

// Same assumption as `language_gc_push_arraylist`. Requires the finalizers lock
// to be hold for the current thread and will release the lock when the
// function returns.
static void language_gc_run_finalizers_in_list(language_task_t *ct, arraylist_t *list) LANGUAGE_NOTSAFEPOINT_LEAVE
{
    // Avoid marking `ct` as non-migratable via an `@async` task (as noted in the docstring
    // of `finalizer`) in a finalizer:
    uint8_t sticky = ct->sticky;
    // empty out the first two entries for the GC frame
    arraylist_push(list, list->items[0]);
    arraylist_push(list, list->items[1]);
    language_gc_push_arraylist(ct, list);
    void **items = list->items;
    size_t len = list->len;
    LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
    // run finalizers in reverse order they were added, so lower-level finalizers run last
    for (size_t i = len-4; i >= 2; i -= 2)
        run_finalizer(ct, items[i], items[i + 1]);
    // first entries were moved last to make room for GC frame metadata
    run_finalizer(ct, items[len-2], items[len-1]);
    // matches the language_gc_push_arraylist above
    LANGUAGE_GC_POP();
    ct->sticky = sticky;
}

static uint64_t finalizer_rngState[LANGUAGE_RNG_SIZE];

void language_rng_split(uint64_t dst[LANGUAGE_RNG_SIZE], uint64_t src[LANGUAGE_RNG_SIZE]) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_gc_init_finalizer_rng_state(void)
{
    language_rng_split(finalizer_rngState, language_current_task->rngState);
}

static void run_finalizers(language_task_t *ct, int finalizers_thread)
{
    // Racy fast path:
    // The race here should be OK since the race can only happen if
    // another thread is writing to it with the lock held. In such case,
    // we don't need to run pending finalizers since the writer thread
    // will flush it.
    if (to_finalize.len == 0)
        return;
    LANGUAGE_LOCK_NOGC(&finalizers_lock);
    if (to_finalize.len == 0) {
        LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
        return;
    }
    arraylist_t copied_list;
    memcpy(&copied_list, &to_finalize, sizeof(copied_list));
    if (to_finalize.items == to_finalize._space) {
        copied_list.items = copied_list._space;
    }
    language_atomic_store_relaxed(&language_gc_have_pending_finalizers, 0);
    arraylist_new(&to_finalize, 0);

    uint64_t save_rngState[LANGUAGE_RNG_SIZE];
    memcpy(&save_rngState[0], &ct->rngState[0], sizeof(save_rngState));
    language_rng_split(ct->rngState, finalizer_rngState);

    // This releases the finalizers lock.
    int8_t was_in_finalizer = ct->ptls->in_finalizer;
    ct->ptls->in_finalizer = !finalizers_thread;
    language_gc_run_finalizers_in_list(ct, &copied_list);
    ct->ptls->in_finalizer = was_in_finalizer;
    arraylist_free(&copied_list);

    memcpy(&ct->rngState[0], &save_rngState[0], sizeof(save_rngState));
}

LANGUAGE_DLLEXPORT void language_gc_run_pending_finalizers(language_task_t *ct)
{
    if (ct == NULL)
        ct = language_current_task;
    language_ptls_t ptls = ct->ptls;
    if (!ptls->in_finalizer && ptls->locks.len == 0 && ptls->finalizers_inhibited == 0) {
        run_finalizers(ct, 0);
    }
}

LANGUAGE_DLLEXPORT int language_gc_get_finalizers_inhibited(language_ptls_t ptls)
{
    if (ptls == NULL)
        ptls = language_current_task->ptls;
    return ptls->finalizers_inhibited;
}

LANGUAGE_DLLEXPORT void language_gc_disable_finalizers_internal(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    ptls->finalizers_inhibited++;
}

LANGUAGE_DLLEXPORT void language_gc_enable_finalizers_internal(void)
{
    language_task_t *ct = language_current_task;
#ifdef NDEBUG
    ct->ptls->finalizers_inhibited--;
#else
    language_gc_enable_finalizers(ct, 1);
#endif
}

LANGUAGE_DLLEXPORT void language_gc_enable_finalizers(language_task_t *ct, int on)
{
    if (ct == NULL)
        ct = language_current_task;
    language_ptls_t ptls = ct->ptls;
    int old_val = ptls->finalizers_inhibited;
    int new_val = old_val + (on ? -1 : 1);
    if (new_val < 0) {
        LANGUAGE_TRY {
            language_error(""); // get a backtrace
        }
        LANGUAGE_CATCH {
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "WARNING: GC finalizers already enabled on this thread.\n");
            // Only print the backtrace once, to avoid spamming the logs
            static int backtrace_printed = 0;
            if (backtrace_printed == 0) {
                backtrace_printed = 1;
                jlbacktrace(); // written to STDERR_FILENO
            }
        }
        return;
    }
    ptls->finalizers_inhibited = new_val;
    if (language_atomic_load_relaxed(&language_gc_have_pending_finalizers)) {
        language_gc_run_pending_finalizers(ct);
    }
}

LANGUAGE_DLLEXPORT int8_t language_gc_is_in_finalizer(void)
{
    return language_current_task->ptls->in_finalizer;
}

static void schedule_all_finalizers(arraylist_t *flist) LANGUAGE_NOTSAFEPOINT
{
    void **items = flist->items;
    size_t len = flist->len;
    for(size_t i = 0; i < len; i+=2) {
        void *v = items[i];
        void *f = items[i + 1];
        if (__unlikely(!v))
            continue;
        schedule_finalization(v, f);
    }
    flist->len = 0;
}

void language_gc_run_all_finalizers(language_task_t *ct)
{
    int gc_n_threads;
    language_ptls_t* gc_all_tls_states;
    gc_n_threads = language_atomic_load_acquire(&language_n_threads);
    gc_all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    // this is called from `language_atexit_hook`; threads could still be running
    // so we have to guard the finalizers' lists
    LANGUAGE_LOCK_NOGC(&finalizers_lock);
    schedule_all_finalizers(&finalizer_list_marked);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            schedule_all_finalizers(&ptls2->finalizers);
    }
    // unlock here because `run_finalizers` locks this
    LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
    run_finalizers(ct, 1);
}

void language_gc_add_finalizer_(language_ptls_t ptls, void *v, void *f) LANGUAGE_NOTSAFEPOINT
{
    assert(language_atomic_load_relaxed(&ptls->gc_state) == LANGUAGE_GC_STATE_UNSAFE);
    arraylist_t *a = &ptls->finalizers;
    // This acquire load and the release store at the end are used to
    // synchronize with `finalize_object` on another thread. Apart from the GC,
    // which is blocked by entering a unsafe region, there might be only
    // one other thread accessing our list in `finalize_object`
    // (only one thread since it needs to acquire the finalizer lock).
    // Similar to `finalize_object`, all content mutation has to be done
    // between the acquire and the release of the length.
    size_t oldlen = language_atomic_load_acquire((_Atomic(size_t)*)&a->len);
    if (__unlikely(oldlen + 2 > a->max)) {
        LANGUAGE_LOCK_NOGC(&finalizers_lock);
        // `a->len` might have been modified.
        // Another possibility is to always grow the array to `oldlen + 2` but
        // it's simpler this way and uses slightly less memory =)
        oldlen = a->len;
        arraylist_grow(a, 2);
        a->len = oldlen;
        LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
    }
    void **items = a->items;
    items[oldlen] = v;
    items[oldlen + 1] = f;
    language_atomic_store_release((_Atomic(size_t)*)&a->len, oldlen + 2);
}

LANGUAGE_DLLEXPORT void language_gc_add_ptr_finalizer(language_ptls_t ptls, language_value_t *v, void *f) LANGUAGE_NOTSAFEPOINT
{
    language_gc_add_finalizer_(ptls, (void*)(((uintptr_t)v) | 1), f);
}

// schedule f(v) to call at the next quiescent interval (aka after the next safepoint/region on all threads)
LANGUAGE_DLLEXPORT void language_gc_add_quiescent(language_ptls_t ptls, void **v, void *f) LANGUAGE_NOTSAFEPOINT
{
    assert(!gc_ptr_tag(v, 3));
    language_gc_add_finalizer_(ptls, (void*)(((uintptr_t)v) | 3), f);
}

LANGUAGE_DLLEXPORT void language_gc_add_finalizer_th(language_ptls_t ptls, language_value_t *v, language_function_t *f) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(language_typetagis(f, language_voidpointer_type))) {
        language_gc_add_ptr_finalizer(ptls, v, language_unbox_voidpointer(f));
    }
    else {
        language_gc_add_finalizer_(ptls, v, f);
    }
}

LANGUAGE_DLLEXPORT void language_finalize_th(language_task_t *ct, language_value_t *o)
{
    LANGUAGE_LOCK_NOGC(&finalizers_lock);
    // Copy the finalizers into a temporary list so that code in the finalizer
    // won't change the list as we loop through them.
    // This list is also used as the GC frame when we are running the finalizers
    arraylist_t copied_list;
    arraylist_new(&copied_list, 0);
    // No need to check the to_finalize list since the user is apparently
    // still holding a reference to the object
    int gc_n_threads;
    language_ptls_t* gc_all_tls_states;
    gc_n_threads = language_atomic_load_acquire(&language_n_threads);
    gc_all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            finalize_object(&ptls2->finalizers, o, &copied_list, language_atomic_load_relaxed(&ct->tid) != i);
    }
    finalize_object(&finalizer_list_marked, o, &copied_list, 0);
    if (copied_list.len > 0) {
        // This releases the finalizers lock.
        language_gc_run_finalizers_in_list(ct, &copied_list);
    }
    else {
        LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
    }
    arraylist_free(&copied_list);
}

// explicitly scheduled objects for the sweepfunc callback
static void gc_sweep_foreign_objs_in_list(arraylist_t *objs)
{
    size_t p = 0;
    for (size_t i = 0; i < objs->len; i++) {
        language_value_t *v = (language_value_t*)(objs->items[i]);
        language_datatype_t *t = (language_datatype_t*)(language_typeof(v));
        const language_datatype_layout_t *layout = t->layout;
        language_fielddescdyn_t *desc = (language_fielddescdyn_t*)language_dt_layout_fields(layout);

        int bits = language_astaggedvalue(v)->bits.gc;
        if (!gc_marked(bits))
            desc->sweepfunc(v);
        else
            objs->items[p++] = v;
    }
    objs->len = p;
}

static void gc_sweep_foreign_objs(void)
{
    assert(gc_n_threads);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            gc_sweep_foreign_objs_in_list(&ptls2->sweep_objs);
    }
}

// GC knobs and self-measurement variables
static int64_t last_gc_total_bytes = 0;

// max_total_memory is a suggestion.  We try very hard to stay
// under this limit, but we will go above it rather than halting.
#ifdef _P64
typedef uint64_t memsize_t;
static const size_t default_collect_interval = 5600 * 1024 * sizeof(void*);
static size_t total_mem;
// We expose this to the user/ci as language_gc_set_max_memory
static memsize_t max_total_memory = (memsize_t) 2 * 1024 * 1024 * 1024 * 1024 * 1024;
#else
typedef uint32_t memsize_t;
static const size_t default_collect_interval = 3200 * 1024 * sizeof(void*);
// Work really hard to stay within 2GB
// Alternative is to risk running out of address space
// on 32 bit architectures.
#define MAX32HEAP 1536 * 1024 * 1024
static memsize_t max_total_memory = (memsize_t) MAX32HEAP;
#endif
// heuristic stuff for https://dl.acm.org/doi/10.1145/3563323
// start with values that are in the target ranges to reduce transient hiccups at startup
static uint64_t old_pause_time = 1e7; // 10 ms
static uint64_t old_mut_time = 1e9; // 1 second
static uint64_t old_heap_size = 0;
static uint64_t old_alloc_diff = default_collect_interval;
static uint64_t old_freed_diff = default_collect_interval;
static uint64_t gc_end_time = 0;
static int thrash_counter = 0;
static int thrashing = 0;
// global variables for GC stats
static uint64_t freed_in_runtime = 0;

// Resetting the object to a young object, this is used when marking the
// finalizer list to collect them the next time because the object is very
// likely dead. This also won't break the GC invariance since these objects
// are not reachable from anywhere else.
static int mark_reset_age = 0;

/*
 * The state transition looks like :
 *
 * ([(quick)sweep] means either a sweep or a quicksweep)
 *
 * <-[(quick)sweep]-
 *                 |
 *     ---->  GC_OLD  <--[(quick)sweep]-------------------
 *     |     |                                           |
 *     |     |  GC_MARKED (in remset)                    |
 *     |     |     ^            |                        |
 *     |   [mark]  |          [mark]                     |
 *     |     |     |            |                        |
 *     |     |     |            |                        |
 *  [sweep]  | [write barrier]  |                        |
 *     |     v     |            v                        |
 *     ----- GC_OLD_MARKED <----                         |
 *              |               ^                        |
 *              |               |                        |
 *              --[quicksweep]---                        |
 *                                                       |
 *  ========= above this line objects are old =========  |
 *                                                       |
 *  ----[new]------> GC_CLEAN ------[mark]-----------> GC_MARKED
 *                    |
 *  <-[(quick)sweep]---
 *
 */

// A quick sweep is a sweep where `!sweep_full`
// It means we won't touch GC_OLD_MARKED objects (old gen).

// When a reachable object has survived more than PROMOTE_AGE+1 collections
// it is tagged with GC_OLD during sweep and will be promoted on next mark
// because at that point we can know easily if it references young objects.
// Marked old objects that reference young ones are kept in the remset.

// When a write barrier triggers, the offending marked object is both queued,
// so as not to trigger the barrier again, and put in the remset.

static int64_t scanned_bytes; // young bytes scanned while marking
static int64_t perm_scanned_bytes; // old bytes scanned while marking
int prev_sweep_full = 1;
int current_sweep_full = 0;
int under_pressure = 0;

// Full collection heuristics
static int64_t live_bytes = 0;
static int64_t promoted_bytes = 0;
static int64_t last_live_bytes = 0; // live_bytes at last collection
static int64_t t_start = 0; // Time GC starts;
#ifdef __GLIBC__
// maxrss at last malloc_trim
static int64_t last_trim_maxrss = 0;
#endif

static void gc_sync_cache_nolock(language_ptls_t ptls, language_gc_mark_cache_t *gc_cache) LANGUAGE_NOTSAFEPOINT
{
    const int nbig = gc_cache->nbig_obj;
    for (int i = 0; i < nbig; i++) {
        void *ptr = gc_cache->big_obj[i];
        bigval_t *hdr = (bigval_t*)gc_ptr_clear_tag(ptr, 1);
        gc_big_object_unlink(hdr);
        if (gc_ptr_tag(ptr, 1)) {
            gc_big_object_link(hdr, &ptls->heap.big_objects);
        }
        else {
            // Move hdr from `big_objects` list to `big_objects_marked list`
            gc_big_object_link(hdr, &big_objects_marked);
        }
    }
    gc_cache->nbig_obj = 0;
    perm_scanned_bytes += gc_cache->perm_scanned_bytes;
    scanned_bytes += gc_cache->scanned_bytes;
    gc_cache->perm_scanned_bytes = 0;
    gc_cache->scanned_bytes = 0;
}

static void gc_sync_cache(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    uv_mutex_lock(&gc_cache_lock);
    gc_sync_cache_nolock(ptls, &ptls->gc_cache);
    uv_mutex_unlock(&gc_cache_lock);
}

// No other threads can be running marking at the same time
static void gc_sync_all_caches_nolock(language_ptls_t ptls)
{
    assert(gc_n_threads);
    for (int t_i = 0; t_i < gc_n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 != NULL)
            gc_sync_cache_nolock(ptls, &ptls2->gc_cache);
    }
}

STATIC_INLINE void gc_queue_big_marked(language_ptls_t ptls, bigval_t *hdr,
                                       int toyoung) LANGUAGE_NOTSAFEPOINT
{
    const int nentry = sizeof(ptls->gc_cache.big_obj) / sizeof(void*);
    size_t nobj = ptls->gc_cache.nbig_obj;
    if (__unlikely(nobj >= nentry)) {
        gc_sync_cache(ptls);
        nobj = 0;
    }
    uintptr_t v = (uintptr_t)hdr;
    ptls->gc_cache.big_obj[nobj] = (void*)(toyoung ? (v | 1) : v);
    ptls->gc_cache.nbig_obj = nobj + 1;
}

// Atomically set the mark bit for object and return whether it was previously unmarked
FORCE_INLINE int gc_try_setmark_tag(language_taggedvalue_t *o, uint8_t mark_mode) LANGUAGE_NOTSAFEPOINT
{
    assert(gc_marked(mark_mode));
    uintptr_t tag = o->header;
    if (gc_marked(tag))
        return 0;
    if (mark_reset_age) {
        // Reset the object as if it was just allocated
        mark_mode = GC_MARKED;
        tag = gc_set_bits(tag, mark_mode);
    }
    else {
        if (gc_old(tag))
            mark_mode = GC_OLD_MARKED;
        tag = tag | mark_mode;
        assert((tag & 0x3) == mark_mode);
    }
    // XXX: note that marking not only sets the GC bits but also updates the
    // page metadata for pool allocated objects.
    // The second step is **not** idempotent, so we need a compare exchange here
    // (instead of a pair of load&store) to avoid marking an object twice
    tag = language_atomic_exchange_relaxed((_Atomic(uintptr_t)*)&o->header, tag);
    verify_val(language_valueof(o));
    return !gc_marked(tag);
}

// This function should be called exactly once during marking for each big
// object being marked to update the big objects metadata.
STATIC_INLINE void gc_setmark_big(language_ptls_t ptls, language_taggedvalue_t *o,
                                  uint8_t mark_mode) LANGUAGE_NOTSAFEPOINT
{
    assert(!gc_alloc_map_is_set((char*)o));
    bigval_t *hdr = bigval_header(o);
    if (mark_mode == GC_OLD_MARKED) {
        ptls->gc_cache.perm_scanned_bytes += hdr->sz & ~3;
        gc_queue_big_marked(ptls, hdr, 0);
    }
    else {
        ptls->gc_cache.scanned_bytes += hdr->sz & ~3;
        // We can't easily tell if the object is old or being promoted
        // from the gc bits but if the `age` is `0` then the object
        // must be already on a young list.
        if (mark_reset_age) {
            // Reset the object as if it was just allocated
            gc_queue_big_marked(ptls, hdr, 1);
        }
    }
    objprofile_count(language_typeof(language_valueof(o)),
                     mark_mode == GC_OLD_MARKED, hdr->sz & ~3);
}

// This function should be called exactly once during marking for each pool
// object being marked to update the page metadata.
STATIC_INLINE void gc_setmark_pool_(language_ptls_t ptls, language_taggedvalue_t *o,
                                    uint8_t mark_mode, language_gc_pagemeta_t *page) LANGUAGE_NOTSAFEPOINT
{
#ifdef MEMDEBUG
    gc_setmark_big(ptls, o, mark_mode);
#else
    if (mark_mode == GC_OLD_MARKED) {
        ptls->gc_cache.perm_scanned_bytes += page->osize;
        static_assert(sizeof(_Atomic(uint16_t)) == sizeof(page->nold), "");
        language_atomic_fetch_add_relaxed((_Atomic(uint16_t)*)&page->nold, 1);
    }
    else {
        ptls->gc_cache.scanned_bytes += page->osize;
        if (mark_reset_age) {
            page->has_young = 1;
        }
    }
    objprofile_count(language_typeof(language_valueof(o)),
                     mark_mode == GC_OLD_MARKED, page->osize);
    page->has_marked = 1;
#endif
}

STATIC_INLINE void gc_setmark_pool(language_ptls_t ptls, language_taggedvalue_t *o,
                                   uint8_t mark_mode) LANGUAGE_NOTSAFEPOINT
{
    gc_setmark_pool_(ptls, o, mark_mode, page_metadata((char*)o));
}

STATIC_INLINE void gc_setmark(language_ptls_t ptls, language_taggedvalue_t *o,
                              uint8_t mark_mode, size_t sz) LANGUAGE_NOTSAFEPOINT
{
    if (sz <= GC_MAX_SZCLASS) {
        gc_setmark_pool(ptls, o, mark_mode);
    }
    else {
        gc_setmark_big(ptls, o, mark_mode);
    }
}

STATIC_INLINE void gc_setmark_buf_(language_ptls_t ptls, void *o, uint8_t mark_mode, size_t minsz) LANGUAGE_NOTSAFEPOINT
{
    language_taggedvalue_t *buf = language_astaggedvalue(o);
    uint8_t bits = (gc_old(buf->header) && !mark_reset_age) ? GC_OLD_MARKED : GC_MARKED;;
    // If the object is larger than the max pool size it can't be a pool object.
    // This should be accurate most of the time but there might be corner cases
    // where the size estimate is a little off so we do a pool lookup to make
    // sure.
    if (__likely(gc_try_setmark_tag(buf, mark_mode)) && !gc_verifying) {
        if (minsz <= GC_MAX_SZCLASS) {
            language_gc_pagemeta_t *meta = page_metadata(buf);
            if (meta != NULL) {
                gc_setmark_pool_(ptls, buf, bits, meta);
                return;
            }
        }
        gc_setmark_big(ptls, buf, bits);
    }
}

void gc_setmark_buf(language_ptls_t ptls, void *o, uint8_t mark_mode, size_t minsz) LANGUAGE_NOTSAFEPOINT
{
    gc_setmark_buf_(ptls, o, mark_mode, minsz);
}

STATIC_INLINE void maybe_collect(language_ptls_t ptls)
{
    if (language_atomic_load_relaxed(&gc_heap_stats.heap_size) >= language_atomic_load_relaxed(&gc_heap_stats.heap_target) || language_gc_debug_check_other()) {
        language_gc_collect(LANGUAGE_GC_AUTO);
    }
    else {
        language_gc_safepoint_(ptls);
    }
}

// weak references

LANGUAGE_DLLEXPORT language_weakref_t *language_gc_new_weakref_th(language_ptls_t ptls,
                                                language_value_t *value)
{
    language_weakref_t *wr = (language_weakref_t*)language_gc_alloc(ptls, sizeof(void*),
                                                  language_weakref_type);
    wr->value = value;  // NOTE: wb not needed here
    small_arraylist_push(&ptls->heap.weak_refs, wr);
    return wr;
}

static void clear_weak_refs(void)
{
    assert(gc_n_threads);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL) {
            size_t n, l = ptls2->heap.weak_refs.len;
            void **lst = ptls2->heap.weak_refs.items;
            for (n = 0; n < l; n++) {
                language_weakref_t *wr = (language_weakref_t*)lst[n];
                if (!gc_marked(language_astaggedvalue(wr->value)->bits.gc))
                    wr->value = (language_value_t*)language_nothing;
            }
        }
    }
}

static void sweep_weak_refs(void)
{
    assert(gc_n_threads);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL) {
            size_t n = 0;
            size_t ndel = 0;
            size_t l = ptls2->heap.weak_refs.len;
            void **lst = ptls2->heap.weak_refs.items;
            if (l == 0)
                continue;
            while (1) {
                language_weakref_t *wr = (language_weakref_t*)lst[n];
                if (gc_marked(language_astaggedvalue(wr)->bits.gc))
                    n++;
                else
                    ndel++;
                if (n >= l - ndel)
                    break;
                void *tmp = lst[n];
                lst[n] = lst[n + ndel];
                lst[n + ndel] = tmp;
            }
            ptls2->heap.weak_refs.len -= ndel;
        }
    }
}


STATIC_INLINE void language_batch_accum_heap_size(language_ptls_t ptls, uint64_t sz) LANGUAGE_NOTSAFEPOINT
{
    uint64_t alloc_acc = language_atomic_load_relaxed(&ptls->gc_num.alloc_acc) + sz;
    if (alloc_acc < 16*1024)
        language_atomic_store_relaxed(&ptls->gc_num.alloc_acc, alloc_acc);
    else {
        language_atomic_fetch_add_relaxed(&gc_heap_stats.heap_size, alloc_acc);
        language_atomic_store_relaxed(&ptls->gc_num.alloc_acc, 0);
    }
}

STATIC_INLINE void language_batch_accum_free_size(language_ptls_t ptls, uint64_t sz) LANGUAGE_NOTSAFEPOINT
{
    language_atomic_store_relaxed(&ptls->gc_num.free_acc, language_atomic_load_relaxed(&ptls->gc_num.free_acc) + sz);
}

// big value list

// Size includes the tag and the tag is not cleared!!
STATIC_INLINE language_value_t *language_gc_big_alloc_inner(language_ptls_t ptls, size_t sz)
{
    maybe_collect(ptls);
    size_t offs = offsetof(bigval_t, header);
    assert(sz >= sizeof(language_taggedvalue_t) && "sz must include tag");
    static_assert(offsetof(bigval_t, header) >= sizeof(void*), "Empty bigval header?");
    static_assert(sizeof(bigval_t) % LANGUAGE_HEAP_ALIGNMENT == 0, "");
    size_t allocsz = LLT_ALIGN(sz + offs, LANGUAGE_CACHE_BYTE_ALIGNMENT);
    if (allocsz < sz)  // overflow in adding offs, size was "negative"
        language_throw(language_memory_exception);
    bigval_t *v = (bigval_t*)malloc_cache_align(allocsz);
    if (v == NULL)
        language_throw(language_memory_exception);
    gc_invoke_callbacks(language_gc_cb_notify_external_alloc_t,
        gc_cblist_notify_external_alloc, (v, allocsz));
    language_atomic_store_relaxed(&ptls->gc_num.allocd,
        language_atomic_load_relaxed(&ptls->gc_num.allocd) + allocsz);
    language_atomic_store_relaxed(&ptls->gc_num.bigalloc,
        language_atomic_load_relaxed(&ptls->gc_num.bigalloc) + 1);
    language_batch_accum_heap_size(ptls, allocsz);
#ifdef MEMDEBUG
    memset(v, 0xee, allocsz);
#endif
    v->sz = allocsz;
    gc_big_object_link(v, &ptls->heap.big_objects);
    return language_valueof(&v->header);
}

// Deprecated version, supported for legacy code.
LANGUAGE_DLLEXPORT language_value_t *language_gc_big_alloc(language_ptls_t ptls, size_t sz)
{
    language_value_t *val = language_gc_big_alloc_inner(ptls, sz);
    maybe_record_alloc_to_profile(val, sz, language_gc_unknown_type_tag);
    return val;
}
// Instrumented version of language_gc_big_alloc_inner, called into by LLVM-generated code.
LANGUAGE_DLLEXPORT language_value_t *language_gc_big_alloc_instrumented(language_ptls_t ptls, size_t sz, language_value_t *type)
{
    language_value_t *val = language_gc_big_alloc_inner(ptls, sz);
    maybe_record_alloc_to_profile(val, sz, (language_datatype_t*)type);
    return val;
}

// This wrapper exists only to prevent `language_gc_big_alloc_inner` from being inlined into
// its callers. We provide an external-facing interface for callers, and inline `language_gc_big_alloc_inner`
// into this. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
language_value_t *language_gc_big_alloc_noinline(language_ptls_t ptls, size_t sz) {
    return language_gc_big_alloc_inner(ptls, sz);
}

// Sweep list rooted at *pv, removing and freeing any unmarked objects.
// Return pointer to last `next` field in the culled list.
static bigval_t **sweep_big_list(int sweep_full, bigval_t **pv) LANGUAGE_NOTSAFEPOINT
{
    bigval_t *v = *pv;
    while (v != NULL) {
        bigval_t *nxt = v->next;
        int bits = v->bits.gc;
        int old_bits = bits;
        if (gc_marked(bits)) {
            pv = &v->next;
            if (sweep_full || bits == GC_MARKED) {
                bits = GC_OLD;
            }
            v->bits.gc = bits;
        }
        else {
            // Remove v from list and free it
            *pv = nxt;
            if (nxt)
                nxt->prev = pv;
            gc_num.freed += v->sz&~3;
            language_atomic_store_relaxed(&gc_heap_stats.heap_size,
                language_atomic_load_relaxed(&gc_heap_stats.heap_size) - (v->sz&~3));
#ifdef MEMDEBUG
            memset(v, 0xbb, v->sz&~3);
#endif
            gc_invoke_callbacks(language_gc_cb_notify_external_free_t,
                gc_cblist_notify_external_free, (v));
            language_free_aligned(v);
        }
        gc_time_count_big(old_bits, bits);
        v = nxt;
    }
    return pv;
}

static void sweep_big(language_ptls_t ptls, int sweep_full) LANGUAGE_NOTSAFEPOINT
{
    gc_time_big_start();
    assert(gc_n_threads);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            sweep_big_list(sweep_full, &ptls2->heap.big_objects);
    }
    if (sweep_full) {
        bigval_t **last_next = sweep_big_list(sweep_full, &big_objects_marked);
        // Move all survivors from big_objects_marked list to the big_objects list of this thread.
        if (ptls->heap.big_objects)
            ptls->heap.big_objects->prev = last_next;
        *last_next = ptls->heap.big_objects;
        ptls->heap.big_objects = big_objects_marked;
        if (ptls->heap.big_objects)
            ptls->heap.big_objects->prev = &ptls->heap.big_objects;
        big_objects_marked = NULL;
    }
    gc_time_big_end();
}

// tracking Memorys with malloc'd storage

void language_gc_track_malloced_genericmemory(language_ptls_t ptls, language_genericmemory_t *m, int isaligned){
    // This is **NOT** a GC safe point.
    mallocarray_t *ma;
    if (ptls->heap.mafreelist == NULL) {
        ma = (mallocarray_t*)malloc_s(sizeof(mallocarray_t));
    }
    else {
        ma = ptls->heap.mafreelist;
        ptls->heap.mafreelist = ma->next;
    }
    ma->a = (language_value_t*)((uintptr_t)m | !!isaligned);
    ma->next = ptls->heap.mallocarrays;
    ptls->heap.mallocarrays = ma;
}


void language_gc_count_allocd(size_t sz) LANGUAGE_NOTSAFEPOINT
{
    language_ptls_t ptls = language_current_task->ptls;
    language_atomic_store_relaxed(&ptls->gc_num.allocd,
        language_atomic_load_relaxed(&ptls->gc_num.allocd) + sz);
    language_batch_accum_heap_size(ptls, sz);
}

void language_gc_count_freed(size_t sz) LANGUAGE_NOTSAFEPOINT
{
    language_batch_accum_free_size(language_current_task->ptls, sz);
}

// Only safe to update the heap inside the GC
static void combine_thread_gc_counts(language_gc_num_t *dest, int update_heap) LANGUAGE_NOTSAFEPOINT
{
    int gc_n_threads;
    language_ptls_t* gc_all_tls_states;
    gc_n_threads = language_atomic_load_acquire(&language_n_threads);
    gc_all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls = gc_all_tls_states[i];
        if (ptls) {
            dest->allocd += (language_atomic_load_relaxed(&ptls->gc_num.allocd) + gc_num.interval);
            dest->malloc += language_atomic_load_relaxed(&ptls->gc_num.malloc);
            dest->realloc += language_atomic_load_relaxed(&ptls->gc_num.realloc);
            dest->poolalloc += language_atomic_load_relaxed(&ptls->gc_num.poolalloc);
            dest->bigalloc += language_atomic_load_relaxed(&ptls->gc_num.bigalloc);
            dest->freed += language_atomic_load_relaxed(&ptls->gc_num.free_acc);
            if (update_heap) {
                uint64_t alloc_acc = language_atomic_load_relaxed(&ptls->gc_num.alloc_acc);
                freed_in_runtime += language_atomic_load_relaxed(&ptls->gc_num.free_acc);
                language_atomic_store_relaxed(&gc_heap_stats.heap_size, alloc_acc + language_atomic_load_relaxed(&gc_heap_stats.heap_size));
                language_atomic_store_relaxed(&ptls->gc_num.alloc_acc, 0);
                language_atomic_store_relaxed(&ptls->gc_num.free_acc, 0);
            }
        }
    }
}

static void reset_thread_gc_counts(void) LANGUAGE_NOTSAFEPOINT
{
    int gc_n_threads;
    language_ptls_t* gc_all_tls_states;
    gc_n_threads = language_atomic_load_acquire(&language_n_threads);
    gc_all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls = gc_all_tls_states[i];
        if (ptls != NULL) {
            // don't reset `pool_live_bytes` here
            language_atomic_store_relaxed(&ptls->gc_num.allocd, -(int64_t)gc_num.interval);
            language_atomic_store_relaxed(&ptls->gc_num.malloc, 0);
            language_atomic_store_relaxed(&ptls->gc_num.realloc, 0);
            language_atomic_store_relaxed(&ptls->gc_num.poolalloc, 0);
            language_atomic_store_relaxed(&ptls->gc_num.bigalloc, 0);
            language_atomic_store_relaxed(&ptls->gc_num.alloc_acc, 0);
            language_atomic_store_relaxed(&ptls->gc_num.free_acc, 0);
        }
    }
}

static int64_t inc_live_bytes(int64_t inc) LANGUAGE_NOTSAFEPOINT
{
    language_timing_counter_inc(LANGUAGE_TIMING_COUNTER_HeapSize, inc);
    return live_bytes += inc;
}

void language_gc_reset_alloc_count(void) LANGUAGE_NOTSAFEPOINT
{
    combine_thread_gc_counts(&gc_num, 0);
    inc_live_bytes(gc_num.deferred_alloc + gc_num.allocd);
    gc_num.allocd = 0;
    gc_num.deferred_alloc = 0;
    reset_thread_gc_counts();
}

size_t language_genericmemory_nbytes(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT
{
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m))->layout;
    size_t sz = layout->size * m->length;
    if (layout->flags.arrayelem_isunion)
        // account for isbits Union array selector bytes
        sz += m->length;
    return sz;
}


static void language_gc_free_memory(language_value_t *v, int isaligned) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_genericmemory(v));
    language_genericmemory_t *m = (language_genericmemory_t*)v;
    assert(language_genericmemory_how(m) == 1 || language_genericmemory_how(m) == 2);
    char *d = (char*)m->ptr;
    if (isaligned)
        language_free_aligned(d);
    else
        free(d);
    language_atomic_store_relaxed(&gc_heap_stats.heap_size,
        language_atomic_load_relaxed(&gc_heap_stats.heap_size) - language_genericmemory_nbytes(m));
    gc_num.freed += language_genericmemory_nbytes(m);
    gc_num.freecall++;
}

static void sweep_malloced_memory(void) LANGUAGE_NOTSAFEPOINT
{
    gc_time_mallocd_memory_start();
    assert(gc_n_threads);
    for (int t_i = 0; t_i < gc_n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 != NULL) {
            mallocarray_t *ma = ptls2->heap.mallocarrays;
            mallocarray_t **pma = &ptls2->heap.mallocarrays;
            while (ma != NULL) {
                mallocarray_t *nxt = ma->next;
                language_value_t *a = (language_value_t*)((uintptr_t)ma->a & ~1);
                int bits = language_astaggedvalue(a)->bits.gc;
                if (gc_marked(bits)) {
                    pma = &ma->next;
                }
                else {
                    *pma = nxt;
                    int isaligned = (uintptr_t)ma->a & 1;
                    language_gc_free_memory(a, isaligned);
                    ma->next = ptls2->heap.mafreelist;
                    ptls2->heap.mafreelist = ma;
                }
                gc_time_count_mallocd_memory(bits);
                ma = nxt;
            }
        }
    }
    gc_time_mallocd_memory_end();
}

// pool allocation
STATIC_INLINE language_taggedvalue_t *gc_reset_page(language_ptls_t ptls2, const language_gc_pool_t *p, language_gc_pagemeta_t *pg) LANGUAGE_NOTSAFEPOINT
{
    assert(GC_PAGE_OFFSET >= sizeof(void*));
    pg->nfree = (GC_PAGE_SZ - GC_PAGE_OFFSET) / p->osize;
    pg->pool_n = p - ptls2->heap.norm_pools;
    language_taggedvalue_t *beg = (language_taggedvalue_t*)(pg->data + GC_PAGE_OFFSET);
    pg->has_young = 0;
    pg->has_marked = 0;
    pg->prev_nold = 0;
    pg->nold = 0;
    pg->fl_begin_offset = UINT16_MAX;
    pg->fl_end_offset = UINT16_MAX;
    return beg;
}

language_gc_page_stack_t global_page_pool_lazily_freed;
language_gc_page_stack_t global_page_pool_clean;
language_gc_page_stack_t global_page_pool_freed;
pagetable_t alloc_map;

// Add a new page to the pool. Discards any pages in `p->newpages` before.
static NOINLINE language_taggedvalue_t *gc_add_page(language_gc_pool_t *p) LANGUAGE_NOTSAFEPOINT
{
    // Do not pass in `ptls` as argument. This slows down the fast path
    // in pool_alloc significantly
    language_ptls_t ptls = language_current_task->ptls;
    language_gc_pagemeta_t *pg = pop_lf_back(&ptls->page_metadata_buffered);
    if (pg != NULL) {
        gc_alloc_map_set(pg->data, GC_PAGE_ALLOCATED);
    }
    else {
        pg = language_gc_alloc_page();
    }
    pg->osize = p->osize;
    pg->thread_n = ptls->tid;
    set_page_metadata(pg);
    push_lf_back(&ptls->page_metadata_allocd, pg);
    language_taggedvalue_t *fl = gc_reset_page(ptls, p, pg);
    language_atomic_fetch_add_relaxed(&gc_heap_stats.heap_size, GC_PAGE_SZ);
    p->newpages = fl;
    return fl;
}

// Size includes the tag and the tag is not cleared!!
STATIC_INLINE language_value_t *language_gc_pool_alloc_inner(language_ptls_t ptls, int pool_offset,
                                          int osize)
{
    // Use the pool offset instead of the pool address as the argument
    // to workaround a llvm bug.
    // Ref https://llvm.org/bugs/show_bug.cgi?id=27190
    language_gc_pool_t *p = (language_gc_pool_t*)((char*)ptls + pool_offset);
    assert(language_atomic_load_relaxed(&ptls->gc_state) == 0);
#ifdef MEMDEBUG
    return language_gc_big_alloc(ptls, osize);
#endif
    maybe_collect(ptls);
    language_atomic_store_relaxed(&ptls->gc_num.allocd,
        language_atomic_load_relaxed(&ptls->gc_num.allocd) + osize);
    language_atomic_store_relaxed(&ptls->gc_num.pool_live_bytes,
        language_atomic_load_relaxed(&ptls->gc_num.pool_live_bytes) + osize);
    language_atomic_store_relaxed(&ptls->gc_num.poolalloc,
        language_atomic_load_relaxed(&ptls->gc_num.poolalloc) + 1);
    // first try to use the freelist
    language_taggedvalue_t *v = p->freelist;
    if (v != NULL) {
        language_taggedvalue_t *next = v->next;
        p->freelist = next;
        if (__unlikely(gc_page_data(v) != gc_page_data(next))) {
            // we only update pg's fields when the freelist changes page
            // since pg's metadata is likely not in cache
            language_gc_pagemeta_t *pg = language_assume(page_metadata_unsafe(v));
            assert(pg->osize == p->osize);
            pg->nfree = 0;
            pg->has_young = 1;
        }
        msan_allocated_memory(v, osize);
        return language_valueof(v);
    }
    // if the freelist is empty we reuse empty but not freed pages
    v = p->newpages;
    language_taggedvalue_t *next = (language_taggedvalue_t*)((char*)v + osize);
    // If there's no pages left or the current page is used up,
    // we need to use the slow path.
    char *cur_page = gc_page_data((char*)v - 1);
    if (__unlikely(v == NULL || cur_page + GC_PAGE_SZ < (char*)next)) {
        if (v != NULL) {
            // like the freelist case,
            // but only update the page metadata when it is full
            language_gc_pagemeta_t *pg = language_assume(page_metadata_unsafe((char*)v - 1));
            assert(pg->osize == p->osize);
            pg->nfree = 0;
            pg->has_young = 1;
        }
        v = gc_add_page(p);
        next = (language_taggedvalue_t*)((char*)v + osize);
    }
    p->newpages = next;
    msan_allocated_memory(v, osize);
    return language_valueof(v);
}

// Deprecated version, supported for legacy code.
LANGUAGE_DLLEXPORT language_value_t *language_gc_pool_alloc(language_ptls_t ptls, int pool_offset,
                                          int osize)
{
    language_value_t *val = language_gc_pool_alloc_inner(ptls, pool_offset, osize);
    maybe_record_alloc_to_profile(val, osize, language_gc_unknown_type_tag);
    return val;
}
// Instrumented version of language_gc_pool_alloc_inner, called into by LLVM-generated code.
LANGUAGE_DLLEXPORT language_value_t *language_gc_pool_alloc_instrumented(language_ptls_t ptls, int pool_offset,
                                        int osize, language_value_t* type)
{
    language_value_t *val = language_gc_pool_alloc_inner(ptls, pool_offset, osize);
    maybe_record_alloc_to_profile(val, osize, (language_datatype_t*)type);
    return val;
}

// This wrapper exists only to prevent `language_gc_pool_alloc_inner` from being inlined into
// its callers. We provide an external-facing interface for callers, and inline `language_gc_pool_alloc_inner`
// into this. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
language_value_t *language_gc_pool_alloc_noinline(language_ptls_t ptls, int pool_offset, int osize) {
    return language_gc_pool_alloc_inner(ptls, pool_offset, osize);
}

int language_gc_classify_pools(size_t sz, int *osize)
{
    if (sz > GC_MAX_SZCLASS)
        return -1;
    size_t allocsz = sz + sizeof(language_taggedvalue_t);
    int klass = language_gc_szclass(allocsz);
    *osize = language_gc_sizeclasses[klass];
    return (int)(intptr_t)(&((language_ptls_t)0)->heap.norm_pools[klass]);
}

// sweep phase

gc_fragmentation_stat_t gc_page_fragmentation_stats[LANGUAGE_GC_N_POOLS];
LANGUAGE_DLLEXPORT double language_gc_page_utilization_stats[LANGUAGE_GC_N_MAX_POOLS];

STATIC_INLINE void gc_update_page_fragmentation_data(language_gc_pagemeta_t *pg) LANGUAGE_NOTSAFEPOINT
{
    gc_fragmentation_stat_t *stats = &gc_page_fragmentation_stats[pg->pool_n];
    language_atomic_fetch_add_relaxed(&stats->n_freed_objs, pg->nfree);
    language_atomic_fetch_add_relaxed(&stats->n_pages_allocd, 1);
}

STATIC_INLINE void gc_dump_page_utilization_data(void) LANGUAGE_NOTSAFEPOINT
{
    for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
        gc_fragmentation_stat_t *stats = &gc_page_fragmentation_stats[i];
        double utilization = 1.0;
        size_t n_freed_objs = language_atomic_load_relaxed(&stats->n_freed_objs);
        size_t n_pages_allocd = language_atomic_load_relaxed(&stats->n_pages_allocd);
        if (n_pages_allocd != 0) {
            utilization -= ((double)n_freed_objs * (double)language_gc_sizeclasses[i]) / (double)n_pages_allocd / (double)GC_PAGE_SZ;
        }
        language_gc_page_utilization_stats[i] = utilization;
        language_atomic_store_relaxed(&stats->n_freed_objs, 0);
        language_atomic_store_relaxed(&stats->n_pages_allocd, 0);
    }
}

int64_t buffered_pages = 0;

// Returns pointer to terminal pointer of list rooted at *pfl.
static void gc_sweep_page(gc_page_profiler_serializer_t *s, language_gc_pool_t *p, language_gc_page_stack_t *allocd, language_gc_page_stack_t *buffered,
                          language_gc_pagemeta_t *pg, int osize) LANGUAGE_NOTSAFEPOINT
{
    char *data = pg->data;
    language_taggedvalue_t *v0 = (language_taggedvalue_t*)(data + GC_PAGE_OFFSET);
    char *lim = data + GC_PAGE_SZ - osize;
    char *lim_newpages = data + GC_PAGE_SZ;
    if (gc_page_data((char*)p->newpages - 1) == data) {
        lim_newpages = (char*)p->newpages;
    }
    size_t old_nfree = pg->nfree;
    size_t nfree;
    // avoid loading a global variable in the hot path
    int page_profile_enabled = gc_page_profile_is_enabled();
    gc_page_serializer_init(s, pg);

    int re_use_page = 1;
    int keep_as_local_buffer = 0;
    int freedall = 1;
    int pg_skpd = 1;
    if (!pg->has_marked) {
        re_use_page = 0;
    #ifdef _P64 // TODO: re-enable on `_P32`?
        // lazy version: (empty) if the whole page was already unused, free it (return it to the pool)
        // eager version: (freedall) free page as soon as possible
        // the eager one uses less memory.
        // FIXME - need to do accounting on a per-thread basis
        // on quick sweeps, keep a few pages empty but allocated for performance
        if (!current_sweep_full && buffered_pages <= default_collect_interval / GC_PAGE_SZ) {
            buffered_pages++;
            keep_as_local_buffer = 1;
        }
    #endif
        nfree = (GC_PAGE_SZ - GC_PAGE_OFFSET) / osize;
        gc_page_profile_write_empty_page(s, page_profile_enabled);
        goto done;
    }
    // For quick sweep, we might be able to skip the page if the page doesn't
    // have any young live cell before marking.
    if (!current_sweep_full && !pg->has_young) {
        assert(!prev_sweep_full || pg->prev_nold >= pg->nold);
        if (!prev_sweep_full || pg->prev_nold == pg->nold) {
            freedall = 0;
            nfree = pg->nfree;
            gc_page_profile_write_empty_page(s, page_profile_enabled);
            goto done;
        }
    }

    pg_skpd = 0;
    {   // scope to avoid clang goto errors
        int has_marked = 0;
        int has_young = 0;
        int16_t prev_nold = 0;
        int pg_nfree = 0;
        language_taggedvalue_t *fl = NULL;
        language_taggedvalue_t **pfl = &fl;
        language_taggedvalue_t **pfl_begin = NULL;
        // collect page profile
        language_taggedvalue_t *v = v0;
        if (page_profile_enabled) {
            while ((char*)v <= lim) {
                int bits = v->bits.gc;
                if (!gc_marked(bits) || (char*)v >= lim_newpages) {
                    gc_page_profile_write_garbage(s, page_profile_enabled);
                }
                else {
                    gc_page_profile_write_live_obj(s, v, page_profile_enabled);
                }
                v = (language_taggedvalue_t*)((char*)v + osize);
            }
            v = v0;
        }
        // sweep the page
        while ((char*)v <= lim) {
            int bits = v->bits.gc;
            // if an object is past `lim_newpages` then we can guarantee it's garbage
            if (!gc_marked(bits) || (char*)v >= lim_newpages) {
                *pfl = v;
                pfl = &v->next;
                pfl_begin = (pfl_begin != NULL) ? pfl_begin : pfl;
                pg_nfree++;
            }
            else { // marked young or old
                if (current_sweep_full || bits == GC_MARKED) { // old enough
                    bits = v->bits.gc = GC_OLD; // promote
                }
                prev_nold++;
                has_marked |= gc_marked(bits);
                freedall = 0;
            }
            v = (language_taggedvalue_t*)((char*)v + osize);
        }
        assert(!freedall);
        pg->has_marked = has_marked;
        pg->has_young = has_young;
        if (pfl_begin) {
            pg->fl_begin_offset = (char*)pfl_begin - data;
            pg->fl_end_offset = (char*)pfl - data;
        }
        else {
            pg->fl_begin_offset = UINT16_MAX;
            pg->fl_end_offset = UINT16_MAX;
        }

        pg->nfree = pg_nfree;
        if (current_sweep_full) {
            pg->nold = 0;
            pg->prev_nold = prev_nold;
        }
    }
    nfree = pg->nfree;

done:
    if (re_use_page) {
        push_lf_back(allocd, pg);
    }
    else {
        gc_alloc_map_set(pg->data, GC_PAGE_LAZILY_FREED);
        language_atomic_fetch_add_relaxed(&gc_heap_stats.heap_size, -GC_PAGE_SZ);
        if (keep_as_local_buffer) {
            push_lf_back(buffered, pg);
        }
        else {
            push_lf_back(&global_page_pool_lazily_freed, pg);
        }
    }
    gc_page_profile_write_to_file(s);
    gc_update_page_fragmentation_data(pg);
    gc_time_count_page(freedall, pg_skpd);
    language_ptls_t ptls = gc_all_tls_states[pg->thread_n];
    language_atomic_fetch_add_relaxed(&ptls->gc_num.pool_live_bytes, GC_PAGE_SZ - GC_PAGE_OFFSET - nfree * osize); //TODO: Could we avoid doing a fetch_add here?
    language_atomic_fetch_add_relaxed((_Atomic(int64_t) *)&gc_num.freed, (nfree - old_nfree) * osize);
}

// the actual sweeping over all allocated pages in a memory pool
STATIC_INLINE void gc_sweep_pool_page(gc_page_profiler_serializer_t *s, language_gc_page_stack_t *allocd, language_gc_page_stack_t *lazily_freed,
                                      language_gc_pagemeta_t *pg) LANGUAGE_NOTSAFEPOINT
{
    int p_n = pg->pool_n;
    int t_n = pg->thread_n;
    language_ptls_t ptls2 = gc_all_tls_states[t_n];
    language_gc_pool_t *p = &ptls2->heap.norm_pools[p_n];
    int osize = pg->osize;
    gc_sweep_page(s, p, allocd, lazily_freed, pg, osize);
}

// sweep over all memory that is being used and not in a pool
static void gc_sweep_other(language_ptls_t ptls, int sweep_full) LANGUAGE_NOTSAFEPOINT
{
    sweep_malloced_memory();
    sweep_big(ptls, sweep_full);
}

static void gc_pool_sync_nfree(language_gc_pagemeta_t *pg, language_taggedvalue_t *last) LANGUAGE_NOTSAFEPOINT
{
    assert(pg->fl_begin_offset != UINT16_MAX);
    char *cur_pg = gc_page_data(last);
    // Fast path for page that has no allocation
    language_taggedvalue_t *fl_beg = (language_taggedvalue_t*)(cur_pg + pg->fl_begin_offset);
    if (last == fl_beg)
        return;
    int nfree = 0;
    do {
        nfree++;
        last = last->next;
    } while (gc_page_data(last) == cur_pg);
    pg->nfree = nfree;
}

// pre-scan pages to check whether there are enough pages so that's worth parallelizing
// also sweeps pages that don't need to be linearly scanned
int gc_sweep_prescan(language_ptls_t ptls, language_gc_padded_page_stack_t *new_gc_allocd_scratch)
{
    // 4MB worth of pages is worth parallelizing
    const int n_pages_worth_parallel_sweep = (int)(4 * (1 << 20) / GC_PAGE_SZ);
    int n_pages_to_scan = 0;
    gc_page_profiler_serializer_t serializer = gc_page_serializer_create();
    for (int t_i = 0; t_i < gc_n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 == NULL) {
            continue;
        }
        language_gc_page_stack_t *dest = &new_gc_allocd_scratch[ptls2->tid].stack;
        language_gc_page_stack_t tmp;
        language_gc_pagemeta_t *tail = NULL;
        memset(&tmp, 0, sizeof(tmp));
        while (1) {
            language_gc_pagemeta_t *pg = pop_lf_back_nosync(&ptls2->page_metadata_allocd);
            if (pg == NULL) {
                break;
            }
            int should_scan = 1;
            if (!pg->has_marked) {
                should_scan = 0;
            }
            if (!current_sweep_full && !pg->has_young) {
                assert(!prev_sweep_full || pg->prev_nold >= pg->nold);
                if (!prev_sweep_full || pg->prev_nold == pg->nold) {
                    should_scan = 0;
                }
            }
            if (should_scan) {
                if (tail == NULL) {
                    tail = pg;
                }
                n_pages_to_scan++;
                push_lf_back_nosync(&tmp, pg);
            }
            else {
                gc_sweep_pool_page(&serializer, dest, &ptls2->page_metadata_buffered, pg);
            }
            if (n_pages_to_scan >= n_pages_worth_parallel_sweep) {
                break;
            }
        }
        if (tail != NULL) {
            tail->next = language_atomic_load_relaxed(&ptls2->page_metadata_allocd.bottom);
        }
        ptls2->page_metadata_allocd = tmp;
        if (n_pages_to_scan >= n_pages_worth_parallel_sweep) {
            break;
        }
    }
    gc_page_serializer_destroy(&serializer);
    return n_pages_to_scan >= n_pages_worth_parallel_sweep;
}

// wake up all threads to sweep the pages
void gc_sweep_wake_all(language_ptls_t ptls, language_gc_padded_page_stack_t *new_gc_allocd_scratch)
{
    int parallel_sweep_worthwhile = gc_sweep_prescan(ptls, new_gc_allocd_scratch);
    if (parallel_sweep_worthwhile && !page_profile_enabled) {
        language_atomic_store(&gc_allocd_scratch, new_gc_allocd_scratch);
        uv_mutex_lock(&gc_threads_lock);
        for (int i = gc_first_tid; i < gc_first_tid + language_n_markthreads; i++) {
            language_ptls_t ptls2 = gc_all_tls_states[i];
            assert(ptls2 != NULL); // should be a GC thread
            language_atomic_fetch_add(&ptls2->gc_sweeps_requested, 1);
        }
        uv_cond_broadcast(&gc_threads_cond);
        uv_mutex_unlock(&gc_threads_lock);
        return;
    }
    if (page_profile_enabled) {
        // we need to ensure that no threads are running sweeping when
        // collecting a page profile.
        // wait for all to leave in order to ensure that a straggler doesn't
        // try to enter sweeping after we set `gc_allocd_scratch` below.
        for (int i = gc_first_tid; i < gc_first_tid + language_n_markthreads; i++) {
            language_ptls_t ptls2 = gc_all_tls_states[i];
            assert(ptls2 != NULL); // should be a GC thread
            while (language_atomic_load_acquire(&ptls2->gc_sweeps_requested) != 0) {
                language_cpu_pause();
            }
        }
    }
    language_atomic_store(&gc_allocd_scratch, new_gc_allocd_scratch);
}

// wait for all threads to finish sweeping
void gc_sweep_wait_for_all(void)
{
    language_atomic_store(&gc_allocd_scratch, NULL);
    while (language_atomic_load_acquire(&gc_n_threads_sweeping) != 0) {
        language_cpu_pause();
    }
}

// sweep all pools
void gc_sweep_pool_parallel(language_ptls_t ptls)
{
    language_atomic_fetch_add(&gc_n_threads_sweeping, 1);
    language_gc_padded_page_stack_t *allocd_scratch = language_atomic_load(&gc_allocd_scratch);
    if (allocd_scratch != NULL) {
        gc_page_profiler_serializer_t serializer = gc_page_serializer_create();
        while (1) {
            int found_pg = 0;
            // sequentially walk the threads and sweep the pages
            for (int t_i = 0; t_i < gc_n_threads; t_i++) {
                language_ptls_t ptls2 = gc_all_tls_states[t_i];
                // skip foreign threads that already exited
                if (ptls2 == NULL) {
                    continue;
                }
                language_gc_page_stack_t *dest = &allocd_scratch[ptls2->tid].stack;
                language_gc_pagemeta_t *pg = try_pop_lf_back(&ptls2->page_metadata_allocd);
                // failed steal attempt
                if (pg == NULL) {
                    continue;
                }
                gc_sweep_pool_page(&serializer, dest, &ptls2->page_metadata_buffered, pg);
                found_pg = 1;
            }
            if (!found_pg) {
                // check for termination
                int no_more_work = 1;
                for (int t_i = 0; t_i < gc_n_threads; t_i++) {
                    language_ptls_t ptls2 = gc_all_tls_states[t_i];
                    // skip foreign threads that already exited
                    if (ptls2 == NULL) {
                        continue;
                    }
                    language_gc_pagemeta_t *pg = language_atomic_load_relaxed(&ptls2->page_metadata_allocd.bottom);
                    if (pg != NULL) {
                        no_more_work = 0;
                        break;
                    }
                }
                if (no_more_work) {
                    break;
                }
            }
            language_cpu_pause();
        }
        gc_page_serializer_destroy(&serializer);
    }
    language_atomic_fetch_add(&gc_n_threads_sweeping, -1);
}

// free all pages (i.e. through `madvise` on Linux) that were lazily freed
void gc_free_pages(void)
{
    while (1) {
        language_gc_pagemeta_t *pg = pop_lf_back(&global_page_pool_lazily_freed);
        if (pg == NULL) {
            break;
        }
        language_gc_free_page(pg);
        push_lf_back(&global_page_pool_freed, pg);
    }
}

void gc_move_to_global_page_pool(language_gc_page_stack_t *pgstack)
{
    while (1) {
        language_gc_pagemeta_t *pg = pop_lf_back(pgstack);
        if (pg == NULL) {
            break;
        }
        language_gc_free_page(pg);
        language_atomic_fetch_add_relaxed(&gc_heap_stats.heap_size, -GC_PAGE_SZ);
        push_lf_back(&global_page_pool_freed, pg);
    }
}

// setup the data-structures for a sweep over all memory pools
static void gc_sweep_pool(void)
{
    gc_time_pool_start();
    buffered_pages = 0;

    // For the benefit of the analyzer, which doesn't know that gc_n_threads
    // doesn't change over the course of this function
    size_t n_threads = gc_n_threads;

    // allocate enough space to hold the end of the free list chain
    // for every thread and pool size
    language_taggedvalue_t ***pfl = (language_taggedvalue_t ***) malloc_s(n_threads * LANGUAGE_GC_N_POOLS * sizeof(language_taggedvalue_t**));

    // update metadata of pages that were pointed to by freelist or newpages from a pool
    // i.e. pages being the current allocation target
    for (int t_i = 0; t_i < n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 == NULL) {
            for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
                pfl[t_i * LANGUAGE_GC_N_POOLS + i] = NULL;
            }
            continue;
        }
        language_atomic_store_relaxed(&ptls2->gc_num.pool_live_bytes, 0);
        for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
            language_gc_pool_t *p = &ptls2->heap.norm_pools[i];
            language_taggedvalue_t *last = p->freelist;
            if (last != NULL) {
                language_gc_pagemeta_t *pg = language_assume(page_metadata_unsafe(last));
                gc_pool_sync_nfree(pg, last);
                pg->has_young = 1;
            }
            p->freelist =  NULL;
            pfl[t_i * LANGUAGE_GC_N_POOLS + i] = &p->freelist;

            last = p->newpages;
            if (last != NULL) {
                char *last_p = (char*)last;
                language_gc_pagemeta_t *pg = language_assume(page_metadata_unsafe(last_p - 1));
                assert(last_p - gc_page_data(last_p - 1) >= GC_PAGE_OFFSET);
                pg->nfree = (GC_PAGE_SZ - (last_p - gc_page_data(last_p - 1))) / p->osize;
                pg->has_young = 1;
            }
        }
        language_gc_pagemeta_t *pg = language_atomic_load_relaxed(&ptls2->page_metadata_buffered.bottom);
        while (pg != NULL) {
            language_gc_pagemeta_t *pg2 = pg->next;
            buffered_pages++;
            pg = pg2;
        }
    }

    // the actual sweeping
    language_gc_padded_page_stack_t *new_gc_allocd_scratch = (language_gc_padded_page_stack_t *) calloc_s(n_threads * sizeof(language_gc_padded_page_stack_t));
    language_ptls_t ptls = language_current_task->ptls;
    gc_sweep_wake_all(ptls, new_gc_allocd_scratch);
    gc_sweep_pool_parallel(ptls);
    gc_sweep_wait_for_all();

    // reset half-pages pointers
    for (int t_i = 0; t_i < n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 != NULL) {
            ptls2->page_metadata_allocd = new_gc_allocd_scratch[t_i].stack;
            for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
                language_gc_pool_t *p = &ptls2->heap.norm_pools[i];
                p->newpages = NULL;
            }
        }
    }

    // merge free lists
    for (int t_i = 0; t_i < n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 == NULL) {
            continue;
        }
        language_gc_pagemeta_t *pg = language_atomic_load_relaxed(&ptls2->page_metadata_allocd.bottom);
        while (pg != NULL) {
            language_gc_pagemeta_t *pg2 = pg->next;
            if (pg->fl_begin_offset != UINT16_MAX) {
                char *cur_pg = pg->data;
                language_taggedvalue_t *fl_beg = (language_taggedvalue_t*)(cur_pg + pg->fl_begin_offset);
                language_taggedvalue_t *fl_end = (language_taggedvalue_t*)(cur_pg + pg->fl_end_offset);
                *pfl[t_i * LANGUAGE_GC_N_POOLS + pg->pool_n] = fl_beg;
                pfl[t_i * LANGUAGE_GC_N_POOLS + pg->pool_n] = &fl_end->next;
            }
            pg = pg2;
        }
    }

    // null out terminal pointers of free lists
    for (int t_i = 0; t_i < n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 != NULL) {
            for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
                *pfl[t_i * LANGUAGE_GC_N_POOLS + i] = NULL;
            }
        }
    }

    // cleanup
    free(pfl);
    free(new_gc_allocd_scratch);

#ifdef _P64 // only enable concurrent sweeping on 64bit
    // wake thread up to sweep concurrently
    if (language_n_sweepthreads > 0) {
        uv_sem_post(&gc_sweep_assists_needed);
    }
    else {
        gc_free_pages();
    }
#else
    gc_free_pages();
#endif
    gc_dump_page_utilization_data();
    gc_time_pool_end(current_sweep_full);
}

static void gc_sweep_perm_alloc(void)
{
    uint64_t t0 = language_hrtime();
    gc_sweep_sysimg();
    gc_time_sysimg_end(t0);
}

// mark phase

LANGUAGE_DLLEXPORT void language_gc_queue_root(const language_value_t *ptr)
{
    language_ptls_t ptls = language_current_task->ptls;
    language_taggedvalue_t *o = language_astaggedvalue(ptr);
    // The modification of the `gc_bits` needs to be atomic.
    // We need to ensure that objects are in the remset at
    // most once, since the mark phase may update page metadata,
    // which is not idempotent. See comments in https://github.com/JuliaLang/julia/issues/50419
    uintptr_t header = language_atomic_load_relaxed((_Atomic(uintptr_t) *)&o->header);
    header &= ~GC_OLD; // clear the age bit
    header = language_atomic_exchange_relaxed((_Atomic(uintptr_t) *)&o->header, header);
    if (header & GC_OLD) { // write barrier has not been triggered in this object yet
        arraylist_push(ptls->heap.remset, (language_value_t*)ptr);
        ptls->heap.remset_nptr++; // conservative
    }
}

void language_gc_queue_multiroot(const language_value_t *parent, const void *ptr, language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT
{
    const language_datatype_layout_t *ly = dt->layout;
    uint32_t npointers = ly->npointers;
    //if (npointers == 0) // this was checked by the caller
    //    return;
    language_value_t *ptrf = ((language_value_t**)ptr)[ly->first_ptr];
    if (ptrf && (language_astaggedvalue(ptrf)->bits.gc & 1) == 0) {
        // this pointer was young, move the barrier back now
        language_gc_wb_back(parent);
        return;
    }
    const uint8_t *ptrs8 = (const uint8_t *)language_dt_layout_ptrs(ly);
    const uint16_t *ptrs16 = (const uint16_t *)language_dt_layout_ptrs(ly);
    const uint32_t *ptrs32 = (const uint32_t*)language_dt_layout_ptrs(ly);
    for (size_t i = 1; i < npointers; i++) {
        uint32_t fld;
        if (ly->flags.fielddesc_type == 0) {
            fld = ptrs8[i];
        }
        else if (ly->flags.fielddesc_type == 1) {
            fld = ptrs16[i];
        }
        else {
            assert(ly->flags.fielddesc_type == 2);
            fld = ptrs32[i];
        }
        language_value_t *ptrf = ((language_value_t**)ptr)[fld];
        if (ptrf && (language_astaggedvalue(ptrf)->bits.gc & 1) == 0) {
            // this pointer was young, move the barrier back now
            language_gc_wb_back(parent);
            return;
        }
    }
}


#ifdef LANGUAGE_DEBUG_BUILD
static void *volatile gc_findval; // for usage from gdb, for finding the gc-root for a value
#endif


// Handle the case where the stack is only partially copied.
STATIC_INLINE uintptr_t gc_get_stack_addr(void *_addr, uintptr_t offset,
                                          uintptr_t lb, uintptr_t ub) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t addr = (uintptr_t)_addr;
    if (addr >= lb && addr < ub)
        return addr + offset;
    return addr;
}

STATIC_INLINE uintptr_t gc_read_stack(void *_addr, uintptr_t offset,
                                      uintptr_t lb, uintptr_t ub) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t real_addr = gc_get_stack_addr(_addr, offset, lb, ub);
    return *(uintptr_t*)real_addr;
}

STATIC_INLINE void gc_assert_parent_validity(language_value_t *parent, language_value_t *child) LANGUAGE_NOTSAFEPOINT
{
#if defined(GC_VERIFY) || defined(GC_ASSERT_PARENT_VALIDITY)
    language_taggedvalue_t *child_astagged = language_astaggedvalue(child);
    language_taggedvalue_t *child_vtag = (language_taggedvalue_t *)(child_astagged->header & ~(uintptr_t)0xf);
    uintptr_t child_vt = (uintptr_t)child_vtag;
    if (child_vt == (language_datatype_tag << 4) ||
        child_vt == (language_unionall_tag << 4) ||
        child_vt == (language_uniontype_tag << 4) ||
        child_vt == (language_tvar_tag << 4) ||
        child_vt == (language_vararg_tag << 4)) {
        // Skip, since these wouldn't hit the object assert anyway
        return;
    }
    else if (child_vt < language_max_tags << 4) {
        // Skip, since these wouldn't hit the object assert anyway
        return;
    }
    if (__unlikely(!language_is_datatype((language_datatype_t *)child_vt) || ((language_datatype_t *)child_vt)->smalltag)) {
        language_safe_printf("GC error (probable corruption)\n");
        language_gc_debug_print_status();
        language_safe_printf("Parent %p\n", (void *)parent);
        language_safe_printf("of type:\n");
        code_(language_typeof(parent));
        language_safe_printf("While marking child at %p\n", (void *)child);
        language_safe_printf("of type:\n");
        code_(child_vtag);
        language_gc_debug_critical_error();
        abort();
    }
#endif
}

// Check if `nptr` is tagged for `old + refyoung`,
// Push the object to the remset and update the `nptr` counter if necessary.
STATIC_INLINE void gc_mark_push_remset(language_ptls_t ptls, language_value_t *obj,
                                       uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely((nptr & 0x3) == 0x3)) {
        ptls->heap.remset_nptr += nptr >> 2;
        arraylist_t *remset = ptls->heap.remset;
        size_t len = remset->len;
        if (__unlikely(len >= remset->max)) {
            arraylist_push(remset, obj);
        }
        else {
            remset->len = len + 1;
            remset->items[len] = obj;
        }
    }
}

// Push a work item to the queue
STATIC_INLINE void gc_ptr_queue_push(language_gc_markqueue_t *mq, language_value_t *obj) LANGUAGE_NOTSAFEPOINT
{
#ifdef LANGUAGE_DEBUG_BUILD
    if (obj == gc_findval)
        language_raise_debugger();
#endif
    ws_array_t *old_a = ws_queue_push(&mq->ptr_queue, &obj, sizeof(language_value_t*));
    // Put `old_a` in `reclaim_set` to be freed after the mark phase
    if (__unlikely(old_a != NULL))
        arraylist_push(&mq->reclaim_set, old_a);
}

// Pop from the mark queue
STATIC_INLINE language_value_t *gc_ptr_queue_pop(language_gc_markqueue_t *mq) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *v = NULL;
    ws_queue_pop(&mq->ptr_queue, &v, sizeof(language_value_t*));
    return v;
}

// Steal from `mq2`
STATIC_INLINE language_value_t *gc_ptr_queue_steal_from(language_gc_markqueue_t *mq2) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *v = NULL;
    ws_queue_steal_from(&mq2->ptr_queue, &v, sizeof(language_value_t*));
    return v;
}

// Push chunk `*c` into chunk queue
STATIC_INLINE void gc_chunkqueue_push(language_gc_markqueue_t *mq, language_gc_chunk_t *c) LANGUAGE_NOTSAFEPOINT
{
    ws_array_t *old_a = ws_queue_push(&mq->chunk_queue, c, sizeof(language_gc_chunk_t));
    // Put `old_a` in `reclaim_set` to be freed after the mark phase
    if (__unlikely(old_a != NULL))
        arraylist_push(&mq->reclaim_set, old_a);
}

// Pop chunk from chunk queue
STATIC_INLINE language_gc_chunk_t gc_chunkqueue_pop(language_gc_markqueue_t *mq) LANGUAGE_NOTSAFEPOINT
{
    language_gc_chunk_t c = {.cid = GC_empty_chunk};
    ws_queue_pop(&mq->chunk_queue, &c, sizeof(language_gc_chunk_t));
    return c;
}

// Dump mark queue on critical error
LANGUAGE_NORETURN NOINLINE void gc_dump_queue_and_abort(language_ptls_t ptls, language_datatype_t *vt) LANGUAGE_NOTSAFEPOINT
{
    language_safe_printf("GC error (probable corruption)\n");
    language_gc_debug_print_status();
    code_(vt);
    language_gc_debug_critical_error();
    if (language_n_gcthreads == 0) {
        language_safe_printf("\n");
        language_value_t *new_obj;
        language_gc_markqueue_t *mq = &ptls->mark_queue;
        language_safe_printf("thread %d ptr queue:\n", ptls->tid);
        language_safe_printf("~~~~~~~~~~ ptr queue top ~~~~~~~~~~\n");
        while ((new_obj = gc_ptr_queue_steal_from(mq)) != NULL) {
            code_(new_obj);
            language_safe_printf("==========\n");
        }
        language_safe_printf("~~~~~~~~~~ ptr queue bottom ~~~~~~~~~~\n");
    }
    abort();
}

// Steal chunk from `mq2`
STATIC_INLINE language_gc_chunk_t gc_chunkqueue_steal_from(language_gc_markqueue_t *mq2) LANGUAGE_NOTSAFEPOINT
{
    language_gc_chunk_t c = {.cid = GC_empty_chunk};
    ws_queue_steal_from(&mq2->chunk_queue, &c, sizeof(language_gc_chunk_t));
    return c;
}

// Enqueue an unmarked obj. last bit of `nptr` is set if `_obj` is young
STATIC_INLINE void gc_try_claim_and_push(language_gc_markqueue_t *mq, void *_obj,
                           uintptr_t *nptr) LANGUAGE_NOTSAFEPOINT
{
    if (_obj == NULL)
        return;
    language_value_t *obj = (language_value_t *)language_assume(_obj);
    language_taggedvalue_t *o = language_astaggedvalue(obj);
    if (!gc_old(o->header) && nptr)
        *nptr |= 1;
    if (gc_try_setmark_tag(o, GC_MARKED))
        gc_ptr_queue_push(mq, obj);
}

// Mark object with 8bit field descriptors
STATIC_INLINE language_value_t *gc_mark_obj8(language_ptls_t ptls, char *obj8_parent, uint8_t *obj8_begin,
                         uint8_t *obj8_end, uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    (void)language_assume(obj8_begin < obj8_end);
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t **slot = NULL;
    language_value_t *new_obj = NULL;
    for (; obj8_begin < obj8_end; obj8_begin++) {
        slot = &((language_value_t**)obj8_parent)[*obj8_begin];
        new_obj = *slot;
        if (new_obj != NULL) {
            verify_parent2("object", obj8_parent, slot, "field(%d)",
                            gc_slot_to_fieldidx(obj8_parent, slot, (language_datatype_t*)language_typeof(obj8_parent)));
            gc_assert_parent_validity((language_value_t *)obj8_parent, new_obj);
            if (obj8_begin + 1 != obj8_end) {
                gc_try_claim_and_push(mq, new_obj, &nptr);
            }
            else {
                // Unroll marking of last item to avoid pushing
                // and popping it right away
                language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                nptr |= !gc_old(o->header);
                if (!gc_try_setmark_tag(o, GC_MARKED)) new_obj = NULL;
            }
            gc_heap_snapshot_record_object_edge((language_value_t*)obj8_parent, slot);
        }
    }
    gc_mark_push_remset(ptls, (language_value_t *)obj8_parent, nptr);
    return new_obj;
}

// Mark object with 16bit field descriptors
STATIC_INLINE language_value_t *gc_mark_obj16(language_ptls_t ptls, char *obj16_parent, uint16_t *obj16_begin,
                          uint16_t *obj16_end, uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    (void)language_assume(obj16_begin < obj16_end);
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t **slot = NULL;
    language_value_t *new_obj = NULL;
    for (; obj16_begin < obj16_end; obj16_begin++) {
        slot = &((language_value_t **)obj16_parent)[*obj16_begin];
        new_obj = *slot;
        if (new_obj != NULL) {
            verify_parent2("object", obj16_parent, slot, "field(%d)",
                            gc_slot_to_fieldidx(obj16_parent, slot, (language_datatype_t*)language_typeof(obj16_parent)));
            gc_assert_parent_validity((language_value_t *)obj16_parent, new_obj);
            if (obj16_begin + 1 != obj16_end) {
                gc_try_claim_and_push(mq, new_obj, &nptr);
            }
            else {
                // Unroll marking of last item to avoid pushing
                // and popping it right away
                language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                nptr |= !gc_old(o->header);
                if (!gc_try_setmark_tag(o, GC_MARKED)) new_obj = NULL;
            }
            gc_heap_snapshot_record_object_edge((language_value_t*)obj16_parent, slot);
        }
    }
    gc_mark_push_remset(ptls, (language_value_t *)obj16_parent, nptr);
    return new_obj;
}

// Mark object with 32bit field descriptors
STATIC_INLINE language_value_t *gc_mark_obj32(language_ptls_t ptls, char *obj32_parent, uint32_t *obj32_begin,
                          uint32_t *obj32_end, uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    (void)language_assume(obj32_begin < obj32_end);
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t **slot = NULL;
    language_value_t *new_obj = NULL;
    for (; obj32_begin < obj32_end; obj32_begin++) {
        slot = &((language_value_t **)obj32_parent)[*obj32_begin];
        new_obj = *slot;
        if (new_obj != NULL) {
            verify_parent2("object", obj32_parent, slot, "field(%d)",
                            gc_slot_to_fieldidx(obj32_parent, slot, (language_datatype_t*)language_typeof(obj32_parent)));
            gc_assert_parent_validity((language_value_t *)obj32_parent, new_obj);
            if (obj32_begin + 1 != obj32_end) {
                gc_try_claim_and_push(mq, new_obj, &nptr);
            }
            else {
                // Unroll marking of last item to avoid pushing
                // and popping it right away
                language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                nptr |= !gc_old(o->header);
                if (!gc_try_setmark_tag(o, GC_MARKED)) new_obj = NULL;
            }
            gc_heap_snapshot_record_object_edge((language_value_t*)obj32_parent, slot);
        }
    }
    gc_mark_push_remset(ptls, (language_value_t *)obj32_parent, nptr);
    return new_obj;
}

// Mark object array
STATIC_INLINE void gc_mark_objarray(language_ptls_t ptls, language_value_t *obj_parent, language_value_t **obj_begin,
                      language_value_t **obj_end, uint32_t step, uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *new_obj;
    // Decide whether need to chunk objary
    assert(step > 0);
    (void)language_assume(step > 0);
    if ((nptr & 0x2) == 0x2) {
        // pre-scan this object: most of this object should be old, so look for
        // the first young object before starting this chunk
        // (this also would be valid for young objects, but probably less beneficial)
        for (; obj_begin < obj_end; obj_begin += step) {
            language_value_t **slot = obj_begin;
            new_obj = *slot;
            if (new_obj != NULL) {
                verify_parent2("obj array", obj_parent, obj_begin, "elem(%d)",
                               gc_slot_to_arrayidx(obj_parent, obj_begin));
                language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                if (!gc_old(o->header))
                    nptr |= 1;
                if (!gc_marked(o->header))
                    break;
                gc_heap_snapshot_record_array_edge(obj_parent, slot);
            }
        }
    }
    size_t too_big = (obj_end - obj_begin) / GC_CHUNK_BATCH_SIZE > step; // use this order of operations to avoid idiv
    language_value_t **scan_end = obj_end;
    int pushed_chunk = 0;
    if (too_big) {
        scan_end = obj_begin + step * GC_CHUNK_BATCH_SIZE;
        // case 1: array owner is young, so we won't need to scan through all its elements
        // to know that we will never need to push it to the remset. it's fine
        // to create a chunk with "incorrect" `nptr` and push it to the chunk-queue
        // ASAP in order to expose as much parallelism as possible
        // case 2: lowest two bits of `nptr` are already set to 0x3, so won't change after
        // scanning the array elements
        if ((nptr & 0x2) != 0x2 || (nptr & 0x3) == 0x3) {
            language_gc_chunk_t c = {GC_objary_chunk, obj_parent, scan_end, obj_end, NULL, NULL, step, nptr};
            gc_chunkqueue_push(mq, &c);
            pushed_chunk = 1;
        }
    }
    for (; obj_begin < scan_end; obj_begin += step) {
        language_value_t **slot = obj_begin;
        new_obj = *obj_begin;
        if (new_obj != NULL) {
            verify_parent2("obj array", obj_parent, obj_begin, "elem(%d)",
                        gc_slot_to_arrayidx(obj_parent, obj_begin));
            gc_assert_parent_validity(obj_parent, new_obj);
            gc_try_claim_and_push(mq, new_obj, &nptr);
            gc_heap_snapshot_record_array_edge(obj_parent, slot);
        }
    }
    if (too_big) {
        if (!pushed_chunk) {
            language_gc_chunk_t c = {GC_objary_chunk, obj_parent, scan_end, obj_end, NULL, NULL, step, nptr};
            gc_chunkqueue_push(mq, &c);
        }
    }
    else {
        gc_mark_push_remset(ptls, obj_parent, nptr);
    }
}

// Mark array with 8bit field descriptors
STATIC_INLINE void gc_mark_memory8(language_ptls_t ptls, language_value_t *ary8_parent, language_value_t **ary8_begin,
                    language_value_t **ary8_end, uint8_t *elem_begin, uint8_t *elem_end, uintptr_t elsize,
                    uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *new_obj;
    assert(elsize > 0);
    (void)language_assume(elsize > 0);
    // Decide whether need to chunk objary
    if ((nptr & 0x2) == 0x2) {
        // pre-scan this object: most of this object should be old, so look for
        // the first young object before starting this chunk
        // (this also would be valid for young objects, but probably less beneficial)
        for (; ary8_begin < ary8_end; ary8_begin += elsize) {
            int early_end = 0;
            for (uint8_t *pindex = elem_begin; pindex < elem_end; pindex++) {
                language_value_t **slot = &ary8_begin[*pindex];
                new_obj = *slot;
                if (new_obj != NULL) {
                    verify_parent2("array", ary8_parent, &new_obj, "elem(%d)",
                                gc_slot_to_arrayidx(ary8_parent, ary8_begin));
                    language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                    if (!gc_old(o->header))
                        nptr |= 1;
                    if (!gc_marked(o->header)){
                        early_end = 1;
                        break;
                    }
                    gc_heap_snapshot_record_array_edge(ary8_parent, slot);
                }
            }
            if (early_end)
                break;
        }
    }
    size_t too_big = (ary8_end - ary8_begin) / GC_CHUNK_BATCH_SIZE > elsize; // use this order of operations to avoid idiv
    language_value_t **scan_end = ary8_end;
    int pushed_chunk = 0;
    if (too_big) {
        scan_end = ary8_begin + elsize * GC_CHUNK_BATCH_SIZE;
        // case 1: array owner is young, so we won't need to scan through all its elements
        // to know that we will never need to push it to the remset. it's fine
        // to create a chunk with "incorrect" `nptr` and push it to the chunk-queue
        // ASAP in order to expose as much parallelism as possible
        // case 2: lowest two bits of `nptr` are already set to 0x3, so won't change after
        // scanning the array elements
        if ((nptr & 0x2) != 0x2 || (nptr & 0x3) == 0x3) {
            language_gc_chunk_t c = {GC_ary8_chunk, ary8_parent, scan_end, ary8_end, elem_begin, elem_end, elsize, nptr};
            gc_chunkqueue_push(mq, &c);
            pushed_chunk = 1;
        }
    }
    for (; ary8_begin < scan_end; ary8_begin += elsize) {
        for (uint8_t *pindex = elem_begin; pindex < elem_end; pindex++) {
            language_value_t **slot = &ary8_begin[*pindex];
            new_obj = *slot;
            if (new_obj != NULL) {
                verify_parent2("array", ary8_parent, &new_obj, "elem(%d)",
                               gc_slot_to_arrayidx(ary8_parent, ary8_begin));
                gc_assert_parent_validity(ary8_parent, new_obj);
                gc_try_claim_and_push(mq, new_obj, &nptr);
                gc_heap_snapshot_record_array_edge(ary8_parent, slot);
            }
        }
    }
    if (too_big) {
        if (!pushed_chunk) {
            language_gc_chunk_t c = {GC_ary8_chunk, ary8_parent, scan_end, ary8_end, elem_begin, elem_end, elsize, nptr};
            gc_chunkqueue_push(mq, &c);
        }
    }
    else {
        gc_mark_push_remset(ptls, ary8_parent, nptr);
    }
}

// Mark array with 16bit field descriptors
STATIC_INLINE void gc_mark_memory16(language_ptls_t ptls, language_value_t *ary16_parent, language_value_t **ary16_begin,
                     language_value_t **ary16_end, uint16_t *elem_begin, uint16_t *elem_end, size_t elsize,
                     uintptr_t nptr) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *new_obj;
    assert(elsize > 0);
    (void)language_assume(elsize > 0);
    // Decide whether need to chunk objary
    if ((nptr & 0x2) == 0x2) {
        // pre-scan this object: most of this object should be old, so look for
        // the first young object before starting this chunk
        // (this also would be valid for young objects, but probably less beneficial)
        for (; ary16_begin < ary16_end; ary16_begin += elsize) {
            int early_end = 0;
            for (uint16_t *pindex = elem_begin; pindex < elem_end; pindex++) {
                language_value_t **slot = &ary16_begin[*pindex];
                new_obj = *slot;
                if (new_obj != NULL) {
                    verify_parent2("array", ary16_parent, &new_obj, "elem(%d)",
                                gc_slot_to_arrayidx(ary16_parent, ary16_begin));
                    language_taggedvalue_t *o = language_astaggedvalue(new_obj);
                    if (!gc_old(o->header))
                        nptr |= 1;
                    if (!gc_marked(o->header)){
                        early_end = 1;
                        break;
                    }
                    gc_heap_snapshot_record_array_edge(ary16_parent, slot);
                }
            }
            if (early_end)
                break;
        }
    }
    size_t too_big = (ary16_end - ary16_begin) / GC_CHUNK_BATCH_SIZE > elsize; // use this order of operations to avoid idiv
    language_value_t **scan_end = ary16_end;
    int pushed_chunk = 0;
    if (too_big) {
        scan_end = ary16_begin + elsize * GC_CHUNK_BATCH_SIZE;
        // case 1: array owner is young, so we won't need to scan through all its elements
        // to know that we will never need to push it to the remset. it's fine
        // to create a chunk with "incorrect" `nptr` and push it to the chunk-queue
        // ASAP in order to expose as much parallelism as possible
        // case 2: lowest two bits of `nptr` are already set to 0x3, so won't change after
        // scanning the array elements
        if ((nptr & 0x2) != 0x2 || (nptr & 0x3) == 0x3) {
            language_gc_chunk_t c = {GC_ary16_chunk, ary16_parent, scan_end, ary16_end, elem_begin, elem_end, elsize, nptr};
            gc_chunkqueue_push(mq, &c);
            pushed_chunk = 1;
        }
    }
    for (; ary16_begin < scan_end; ary16_begin += elsize) {
        for (uint16_t *pindex = elem_begin; pindex < elem_end; pindex++) {
            language_value_t **slot = &ary16_begin[*pindex];
            new_obj = *slot;
            if (new_obj != NULL) {
                verify_parent2("array", ary16_parent, &new_obj, "elem(%d)",
                               gc_slot_to_arrayidx(ary16_parent, ary16_begin));
                gc_assert_parent_validity(ary16_parent, new_obj);
                gc_try_claim_and_push(mq, new_obj, &nptr);
                gc_heap_snapshot_record_array_edge(ary16_parent, slot);
            }
        }
    }
    if (too_big) {
        if (!pushed_chunk) {
            language_gc_chunk_t c = {GC_ary16_chunk, ary16_parent, scan_end, ary16_end, elem_begin, elem_end, elsize, nptr};
            gc_chunkqueue_push(mq, &c);
        }
    }
    else {
        gc_mark_push_remset(ptls, ary16_parent, nptr);
    }
}

// Mark chunk of large array
STATIC_INLINE void gc_mark_chunk(language_ptls_t ptls, language_gc_markqueue_t *mq, language_gc_chunk_t *c) LANGUAGE_NOTSAFEPOINT
{
    switch (c->cid) {
        case GC_objary_chunk: {
            language_value_t *obj_parent = c->parent;
            language_value_t **obj_begin = c->begin;
            language_value_t **obj_end = c->end;
            uint32_t step = c->step;
            uintptr_t nptr = c->nptr;
            gc_mark_objarray(ptls, obj_parent, obj_begin, obj_end,
                             step, nptr);
            break;
        }
        case GC_ary8_chunk: {
            language_value_t *ary8_parent = c->parent;
            language_value_t **ary8_begin = c->begin;
            language_value_t **ary8_end = c->end;
            uint8_t *elem_begin = (uint8_t *)c->elem_begin;
            uint8_t *elem_end = (uint8_t *)c->elem_end;
            size_t elsize = c->step;
            uintptr_t nptr = c->nptr;
            gc_mark_memory8(ptls, ary8_parent, ary8_begin, ary8_end, elem_begin, elem_end,
                           elsize, nptr);
            break;
        }
        case GC_ary16_chunk: {
            language_value_t *ary16_parent = c->parent;
            language_value_t **ary16_begin = c->begin;
            language_value_t **ary16_end = c->end;
            uint16_t *elem_begin = (uint16_t *)c->elem_begin;
            uint16_t *elem_end = (uint16_t *)c->elem_end;
            size_t elsize = c->step;
            uintptr_t nptr = c->nptr;
            gc_mark_memory16(ptls, ary16_parent, ary16_begin, ary16_end, elem_begin, elem_end,
                            elsize, nptr);
            break;
        }
        case GC_finlist_chunk: {
            language_value_t *fl_parent = c->parent;
            language_value_t **fl_begin = c->begin;
            language_value_t **fl_end = c->end;
            gc_mark_finlist_(mq, fl_parent, fl_begin, fl_end);
            break;
        }
        default: {
            // `empty-chunk` should be checked by caller
            language_safe_printf("GC internal error: chunk mismatch\n");
            abort();
        }
    }
}

// Mark gc frame
STATIC_INLINE void gc_mark_stack(language_ptls_t ptls, language_gcframe_t *s, uint32_t nroots, uintptr_t offset,
                   uintptr_t lb, uintptr_t ub) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *new_obj;
    uint32_t nr = nroots >> 2;
    while (1) {
        language_value_t ***rts = (language_value_t ***)(((void **)s) + 2);
        for (uint32_t i = 0; i < nr; i++) {
            if (nroots & 1) {
                void **slot = (void **)gc_read_stack(&rts[i], offset, lb, ub);
                new_obj = (language_value_t *)gc_read_stack(slot, offset, lb, ub);
                if (new_obj == NULL)
                    continue;
            }
            else {
                new_obj = (language_value_t *)gc_read_stack(&rts[i], offset, lb, ub);
                if (gc_ptr_tag(new_obj, 1)) {
                    // handle tagged pointers in finalizer list
                    new_obj = (language_value_t *)gc_ptr_clear_tag(new_obj, 1);
                    // skip over the finalizer fptr
                    i++;
                }
                if (gc_ptr_tag(new_obj, 2))
                    continue;
                // conservatively check for the presence of any smalltag type, instead of just NULL
                // in the very unlikely event that codegen decides to root the result of julia.typeof
                if (new_obj < (language_value_t*)((uintptr_t)language_max_tags << 4))
                    continue;
            }
            gc_try_claim_and_push(mq, new_obj, NULL);
            gc_heap_snapshot_record_frame_to_object_edge(s, new_obj);
        }
        language_gcframe_t *sprev = (language_gcframe_t *)gc_read_stack(&s->prev, offset, lb, ub);
        if (sprev == NULL)
            break;
        gc_heap_snapshot_record_frame_to_frame_edge(s, sprev);
        s = sprev;
        uintptr_t new_nroots = gc_read_stack(&s->nroots, offset, lb, ub);
        assert(new_nroots <= UINT32_MAX);
        nroots = (uint32_t)new_nroots;
        nr = nroots >> 2;
    }
}

// Mark exception stack
STATIC_INLINE void gc_mark_excstack(language_ptls_t ptls, language_excstack_t *excstack, size_t itr) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *new_obj;
    while (itr > 0) {
        size_t bt_size = language_excstack_bt_size(excstack, itr);
        language_bt_element_t *bt_data = language_excstack_bt_data(excstack, itr);
        for (size_t bt_index = 0; bt_index < bt_size;
             bt_index += language_bt_entry_size(bt_data + bt_index)) {
            language_bt_element_t *bt_entry = bt_data + bt_index;
            if (language_bt_is_native(bt_entry))
                continue;
            // Found an extended backtrace entry: iterate over any
            // GC-managed values inside.
            size_t njlvals = language_bt_num_jlvals(bt_entry);
            for (size_t jlval_index = 0; jlval_index < njlvals; jlval_index++) {
                new_obj = language_bt_entry_jlvalue(bt_entry, jlval_index);
                gc_try_claim_and_push(mq, new_obj, NULL);
                gc_heap_snapshot_record_frame_to_object_edge(bt_entry, new_obj);
            }
        }
        // The exception comes last - mark it
        new_obj = language_excstack_exception(excstack, itr);
        itr = language_excstack_next(excstack, itr);
        gc_try_claim_and_push(mq, new_obj, NULL);
        gc_heap_snapshot_record_frame_to_object_edge(excstack, new_obj);
    }
}

// Mark module binding
STATIC_INLINE void gc_mark_module_binding(language_ptls_t ptls, language_module_t *mb_parent, uintptr_t nptr,
                            uint8_t bits) LANGUAGE_NOTSAFEPOINT
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_value_t *bindings = (language_value_t *)language_atomic_load_relaxed(&mb_parent->bindings);
    gc_assert_parent_validity((language_value_t *)mb_parent, bindings);
    gc_try_claim_and_push(mq, bindings, &nptr);
    language_value_t *bindingkeyset = (language_value_t *)language_atomic_load_relaxed(&mb_parent->bindingkeyset);
    gc_assert_parent_validity((language_value_t *)mb_parent, bindingkeyset);
    gc_try_claim_and_push(mq, bindingkeyset, &nptr);
    gc_heap_snapshot_record_module_to_binding(mb_parent, bindings, bindingkeyset);
    gc_assert_parent_validity((language_value_t *)mb_parent, (language_value_t *)mb_parent->parent);
    gc_try_claim_and_push(mq, (language_value_t *)mb_parent->parent, &nptr);
    size_t nusings = mb_parent->usings.len;
    if (nusings > 0) {
        // this is only necessary because bindings for "using" modules
        // are added only when accessed. therefore if a module is replaced
        // after "using" it but before accessing it, this array might
        // contain the only reference.
        language_value_t *obj_parent = (language_value_t *)mb_parent;
        language_value_t **objary_begin = (language_value_t **)mb_parent->usings.items;
        language_value_t **objary_end = objary_begin + nusings;
        gc_mark_objarray(ptls, obj_parent, objary_begin, objary_end, 1, nptr);
    }
    else {
        gc_mark_push_remset(ptls, (language_value_t *)mb_parent, nptr);
    }
}

void gc_mark_finlist_(language_gc_markqueue_t *mq, language_value_t *fl_parent, language_value_t **fl_begin, language_value_t **fl_end)
{
    language_value_t *new_obj;
    // Decide whether need to chunk finlist
    size_t nrefs = (fl_end - fl_begin);
    if (nrefs > GC_CHUNK_BATCH_SIZE) {
        language_gc_chunk_t c = {GC_finlist_chunk, NULL, fl_begin + GC_CHUNK_BATCH_SIZE, fl_end, 0, 0, 0, 0};
        gc_chunkqueue_push(mq, &c);
        fl_end = fl_begin + GC_CHUNK_BATCH_SIZE;
    }
    size_t i = 0;
    for (; fl_begin < fl_end; fl_begin++) {
        language_value_t **slot = fl_begin;
        new_obj = *slot;
        if (__unlikely(new_obj == NULL))
            continue;
        if (gc_ptr_tag(new_obj, 1)) {
            new_obj = (language_value_t *)gc_ptr_clear_tag(new_obj, 1);
            fl_begin++;
            assert(fl_begin < fl_end);
        }
        if (gc_ptr_tag(new_obj, 2))
            continue;
        gc_try_claim_and_push(mq, new_obj, NULL);
        if (fl_parent != NULL) {
            gc_heap_snapshot_record_array_edge(fl_parent, slot);
        } else {
            // This is a list of objects following the same format as a finlist
            // if `fl_parent` is NULL
            gc_heap_snapshot_record_finlist(new_obj, ++i);
        }
    }
}

// Mark finalizer list (or list of objects following same format)
void gc_mark_finlist(language_gc_markqueue_t *mq, arraylist_t *list, size_t start)
{
    size_t len = list->len;
    if (len <= start)
        return;
    language_value_t **fl_begin = (language_value_t **)list->items + start;
    language_value_t **fl_end = (language_value_t **)list->items + len;
    gc_mark_finlist_(mq, NULL, fl_begin, fl_end);
}

LANGUAGE_DLLEXPORT int language_gc_mark_queue_obj(language_ptls_t ptls, language_value_t *obj)
{
    int may_claim = gc_try_setmark_tag(language_astaggedvalue(obj), GC_MARKED);
    if (may_claim)
        gc_ptr_queue_push(&ptls->mark_queue, obj);
    return may_claim;
}

LANGUAGE_DLLEXPORT void language_gc_mark_queue_objarray(language_ptls_t ptls, language_value_t *parent,
                                            language_value_t **objs, size_t nobjs)
{
    uintptr_t nptr = (nobjs << 2) | (language_astaggedvalue(parent)->bits.gc & 2);
    gc_mark_objarray(ptls, parent, objs, objs + nobjs, 1, nptr);
}

// Enqueue and mark all outgoing references from `new_obj` which have not been marked yet.
// `_new_obj` has its lowest bit tagged if it's in the remset (in which case we shouldn't update page metadata)
FORCE_INLINE void gc_mark_outrefs(language_ptls_t ptls, language_gc_markqueue_t *mq, void *_new_obj)
{
    int meta_updated = (uintptr_t)_new_obj & GC_REMSET_PTR_TAG;
    language_value_t *new_obj = (language_value_t *)((uintptr_t)_new_obj & ~(uintptr_t)GC_REMSET_PTR_TAG);
    mark_obj: {
        language_taggedvalue_t *o = language_astaggedvalue(new_obj);
        uintptr_t vtag = o->header & ~(uintptr_t)0xf;
        uint8_t bits = (gc_old(o->header) && !mark_reset_age) ? GC_OLD_MARKED : GC_MARKED;
        int update_meta = __likely(!meta_updated && !gc_verifying);
        int foreign_alloc = 0;
        if (update_meta && o->bits.in_image) {
            foreign_alloc = 1;
            update_meta = 0;
        }
        // Symbols are always marked
        assert(vtag != (uintptr_t)language_symbol_type && vtag != language_symbol_tag << 4);
        if (vtag == (language_datatype_tag << 4) ||
            vtag == (language_unionall_tag << 4) ||
            vtag == (language_uniontype_tag << 4) ||
            vtag == (language_tvar_tag << 4) ||
            vtag == (language_vararg_tag << 4)) {
            // these objects have pointers in them, but no other special handling
            // so we want these to fall through to the end
            vtag = (uintptr_t)ilanguage_small_typeof[vtag / sizeof(*ilanguage_small_typeof)];
        }
        else if (vtag < language_max_tags << 4) {
            // these objects either have specialing handling
            if (vtag == language_simplevector_tag << 4) {
                size_t l = language_svec_len(new_obj);
                language_value_t **data = language_svec_data(new_obj);
                size_t dtsz = l * sizeof(void *) + sizeof(language_svec_t);
                if (update_meta)
                    gc_setmark(ptls, o, bits, dtsz);
                else if (foreign_alloc)
                    objprofile_count(language_simplevector_type, bits == GC_OLD_MARKED, dtsz);
                language_value_t *objary_parent = new_obj;
                language_value_t **objary_begin = data;
                language_value_t **objary_end = data + l;
                uint32_t step = 1;
                uintptr_t nptr = (l << 2) | (bits & GC_OLD);
                gc_mark_objarray(ptls, objary_parent, objary_begin, objary_end, step, nptr);
            }
            else if (vtag == language_module_tag << 4) {
                if (update_meta)
                    gc_setmark(ptls, o, bits, sizeof(language_module_t));
                else if (foreign_alloc)
                    objprofile_count(language_module_type, bits == GC_OLD_MARKED, sizeof(language_module_t));
                language_module_t *mb_parent = (language_module_t *)new_obj;
                uintptr_t nptr = ((mb_parent->usings.len + 1) << 2) | (bits & GC_OLD);
                gc_mark_module_binding(ptls, mb_parent, nptr, bits);
            }
            else if (vtag == language_task_tag << 4) {
                if (update_meta)
                    gc_setmark(ptls, o, bits, sizeof(language_task_t));
                else if (foreign_alloc)
                    objprofile_count(language_task_type, bits == GC_OLD_MARKED, sizeof(language_task_t));
                language_task_t *ta = (language_task_t *)new_obj;
                gc_scrub_record_task(ta);
                if (gc_cblist_task_scanner) {
                    int16_t tid = language_atomic_load_relaxed(&ta->tid);
                    gc_invoke_callbacks(language_gc_cb_task_scanner_t, gc_cblist_task_scanner,
                                        (ta, tid != -1 && ta == gc_all_tls_states[tid]->root_task));
                }
        #ifdef COPY_STACKS
                void *stkbuf = ta->stkbuf;
                if (stkbuf && ta->copy_stack) {
                    gc_setmark_buf_(ptls, stkbuf, bits, ta->bufsz);
                    // For gc_heap_snapshot_record:
                    // TODO: attribute size of stack
                    // TODO: edge to stack data
                    // TODO: synthetic node for stack data (how big is it?)
                }
        #endif
                language_gcframe_t *s = ta->gcstack;
                size_t nroots;
                uintptr_t offset = 0;
                uintptr_t lb = 0;
                uintptr_t ub = (uintptr_t)-1;
        #ifdef COPY_STACKS
                if (stkbuf && ta->copy_stack && !ta->ptls) {
                    int16_t tid = language_atomic_load_relaxed(&ta->tid);
                    assert(tid >= 0);
                    language_ptls_t ptls2 = gc_all_tls_states[tid];
                    ub = (uintptr_t)ptls2->stackbase;
                    lb = ub - ta->copy_stack;
                    offset = (uintptr_t)stkbuf - lb;
                }
        #endif
                if (s != NULL) {
                    nroots = gc_read_stack(&s->nroots, offset, lb, ub);
                    gc_heap_snapshot_record_task_to_frame_edge(ta, s);
                    assert(nroots <= UINT32_MAX);
                    gc_mark_stack(ptls, s, (uint32_t)nroots, offset, lb, ub);
                }
                if (ta->excstack) {
                    language_excstack_t *excstack = ta->excstack;
                    gc_heap_snapshot_record_task_to_frame_edge(ta, excstack);
                    size_t itr = ta->excstack->top;
                    gc_setmark_buf_(ptls, excstack, bits,
                                    sizeof(language_excstack_t) +
                                        sizeof(uintptr_t) * excstack->reserved_size);
                    gc_mark_excstack(ptls, excstack, itr);
                }
                const language_datatype_layout_t *layout = language_task_type->layout;
                assert(layout->flags.fielddesc_type == 0);
                assert(layout->nfields > 0);
                uint32_t npointers = layout->npointers;
                char *obj8_parent = (char *)ta;
                uint8_t *obj8_begin = (uint8_t *)language_dt_layout_ptrs(layout);
                uint8_t *obj8_end = obj8_begin + npointers;
                // assume tasks always reference young objects: set lowest bit
                uintptr_t nptr = (npointers << 2) | 1 | bits;
                new_obj = gc_mark_obj8(ptls, obj8_parent, obj8_begin, obj8_end, nptr);
                if (new_obj != NULL) {
                    if (!meta_updated)
                        goto mark_obj;
                    else
                        gc_ptr_queue_push(mq, new_obj);
                }
            }
            else if (vtag == language_string_tag << 4) {
                size_t dtsz = language_string_len(new_obj) + sizeof(size_t) + 1;
                if (update_meta)
                    gc_setmark(ptls, o, bits, dtsz);
                else if (foreign_alloc)
                    objprofile_count(language_string_type, bits == GC_OLD_MARKED, dtsz);
            }
            else {
                language_datatype_t *vt = ilanguage_small_typeof[vtag / sizeof(*ilanguage_small_typeof)];
                size_t dtsz = language_datatype_size(vt);
                if (update_meta)
                    gc_setmark(ptls, o, bits, dtsz);
                else if (foreign_alloc)
                    objprofile_count(vt, bits == GC_OLD_MARKED, dtsz);
            }
            return;
        }
        else {
            language_datatype_t *vt = (language_datatype_t *)vtag;
            if (__unlikely(!language_is_datatype(vt) || vt->smalltag))
                gc_dump_queue_and_abort(ptls, vt);
        }
        language_datatype_t *vt = (language_datatype_t *)vtag;
        if (vt->name == language_genericmemory_typename) {
            language_genericmemory_t *m = (language_genericmemory_t*)new_obj;
            int pooled = 1; // The language_genericmemory_t itself is always pooled-size, even with data attached to it
            if (update_meta) {
                if (pooled)
                    gc_setmark_pool(ptls, o, bits);
                else
                    gc_setmark_big(ptls, o, bits);
            }
            else if (foreign_alloc) {
                objprofile_count(vt, bits == GC_OLD_MARKED, sizeof(language_genericmemory_t));
            }
            int how = language_genericmemory_how(m);
            if (how == 0 || how == 2) {
                gc_heap_snapshot_record_hidden_edge(new_obj, m->ptr, language_genericmemory_nbytes(m), how == 0 ? 2 : 0);
            }
            else if (how == 1) {
                if (update_meta || foreign_alloc) {
                    objprofile_count(language_malloc_tag, bits == GC_OLD_MARKED,
                                     language_genericmemory_nbytes(m));
                    size_t nb = language_genericmemory_nbytes(m);
                    gc_heap_snapshot_record_hidden_edge(new_obj, m->ptr, nb, 0);
                    if (bits == GC_OLD_MARKED) {
                        ptls->gc_cache.perm_scanned_bytes += nb;
                    }
                    else {
                        ptls->gc_cache.scanned_bytes += nb;
                    }
                }
            }
            else if (how == 3) {
                language_value_t *owner = language_genericmemory_data_owner_field(m);
                uintptr_t nptr = (1 << 2) | (bits & GC_OLD);
                gc_try_claim_and_push(mq, owner, &nptr);
                gc_heap_snapshot_record_internal_array_edge(new_obj, owner);
                gc_mark_push_remset(ptls, new_obj, nptr);
                return;
            }
            if (m->length == 0)
                return;
            const language_datatype_layout_t *layout = vt->layout;
            if (layout->flags.arrayelem_isboxed) {
                if ((language_datatype_t*)language_tparam1(vt) == language_symbol_type)
                    return;
                language_value_t *objary_parent = new_obj;
                language_value_t **objary_begin = (language_value_t **)m->ptr;
                language_value_t **objary_end = objary_begin + m->length;
                uint32_t step = 1;
                uintptr_t nptr = (m->length << 2) | (bits & GC_OLD);
                gc_mark_objarray(ptls, objary_parent, objary_begin, objary_end, step, nptr);
            }
            else if (layout->first_ptr >= 0) {
                const language_datatype_layout_t *layout = vt->layout;
                unsigned npointers = layout->npointers;
                unsigned elsize = layout->size / sizeof(language_value_t*);
                size_t l = m->length;
                language_value_t *objary_parent = new_obj;
                language_value_t **objary_begin = (language_value_t**)m->ptr;
                language_value_t **objary_end = objary_begin + l * elsize;
                uint32_t step = elsize;
                uintptr_t nptr = ((l * npointers) << 2) | (bits & GC_OLD);
                if (npointers == 1) { // TODO: detect anytime time stride is uniform?
                    objary_begin += layout->first_ptr;
                    gc_mark_objarray(ptls, objary_parent, objary_begin, objary_end, step, nptr);
                }
                else if (layout->flags.fielddesc_type == 0) {
                    uint8_t *obj8_begin = (uint8_t*)language_dt_layout_ptrs(layout);
                    uint8_t *obj8_end = obj8_begin + npointers;
                    gc_mark_memory8(ptls, objary_parent, objary_begin, objary_end, obj8_begin, obj8_end,
                                   elsize, nptr);
                }
                else if (layout->flags.fielddesc_type == 1) {
                    uint16_t *obj16_begin = (uint16_t*)language_dt_layout_ptrs(layout);
                    uint16_t *obj16_end = obj16_begin + npointers;
                    gc_mark_memory16(ptls, objary_parent, objary_begin, objary_end, obj16_begin, obj16_end,
                                    elsize, nptr);
                }
                else {
                    assert(0 && "unimplemented");
                }
            }
            return;
        }
        size_t dtsz = language_datatype_size(vt);
        if (update_meta)
            gc_setmark(ptls, o, bits, dtsz);
        else if (foreign_alloc)
            objprofile_count(vt, bits == GC_OLD_MARKED, dtsz);
        if (vt == language_weakref_type)
            return;
        const language_datatype_layout_t *layout = vt->layout;
        uint32_t npointers = layout->npointers;
        if (npointers == 0)
            return;
        uintptr_t nptr = (npointers << 2 | (bits & GC_OLD));
        assert((layout->nfields > 0 || layout->flags.fielddesc_type == 3) &&
               "opaque types should have been handled specially");
        if (layout->flags.fielddesc_type == 0) {
            char *obj8_parent = (char *)new_obj;
            uint8_t *obj8_begin = (uint8_t *)language_dt_layout_ptrs(layout);
            uint8_t *obj8_end = obj8_begin + npointers;
            assert(obj8_begin < obj8_end);
            new_obj = gc_mark_obj8(ptls, obj8_parent, obj8_begin, obj8_end, nptr);
            if (new_obj != NULL) {
                if (!meta_updated)
                    goto mark_obj;
                else
                    gc_ptr_queue_push(mq, new_obj);
            }
        }
        else if (layout->flags.fielddesc_type == 1) {
            char *obj16_parent = (char *)new_obj;
            uint16_t *obj16_begin = (uint16_t *)language_dt_layout_ptrs(layout);
            uint16_t *obj16_end = obj16_begin + npointers;
            assert(obj16_begin < obj16_end);
            new_obj = gc_mark_obj16(ptls, obj16_parent, obj16_begin, obj16_end, nptr);
            if (new_obj != NULL) {
                if (!meta_updated)
                    goto mark_obj;
                else
                    gc_ptr_queue_push(mq, new_obj);
            }
        }
        else if (layout->flags.fielddesc_type == 2) {
            // This is very uncommon
            // Do not do store to load forwarding to save some code size
            char *obj32_parent = (char *)new_obj;
            uint32_t *obj32_begin = (uint32_t *)language_dt_layout_ptrs(layout);
            uint32_t *obj32_end = obj32_begin + npointers;
            assert(obj32_begin < obj32_end);
            new_obj = gc_mark_obj32(ptls, obj32_parent, obj32_begin, obj32_end, nptr);
            if (new_obj != NULL) {
                if (!meta_updated)
                    goto mark_obj;
                else
                    gc_ptr_queue_push(mq, new_obj);
            }
        }
        else {
            assert(layout->flags.fielddesc_type == 3);
            language_fielddescdyn_t *desc = (language_fielddescdyn_t *)language_dt_layout_fields(layout);
            int old = language_astaggedvalue(new_obj)->bits.gc & 2;
            uintptr_t young = desc->markfunc(ptls, new_obj);
            if (old && young)
                gc_mark_push_remset(ptls, new_obj, young * 4 + 3);
        }
    }
}

// Used in gc-debug
void gc_mark_loop_serial_(language_ptls_t ptls, language_gc_markqueue_t *mq)
{
    while (1) {
        void *new_obj = (void *)gc_ptr_queue_pop(&ptls->mark_queue);
        // No more objects to mark
        if (__unlikely(new_obj == NULL)) {
            return;
        }
        gc_mark_outrefs(ptls, mq, new_obj);
    }
}

// Drain items from worker's own chunkqueue
void gc_drain_own_chunkqueue(language_ptls_t ptls, language_gc_markqueue_t *mq)
{
    language_gc_chunk_t c = {.cid = GC_empty_chunk};
    do {
        c = gc_chunkqueue_pop(mq);
        if (c.cid != GC_empty_chunk) {
            gc_mark_chunk(ptls, mq, &c);
            gc_mark_loop_serial_(ptls, mq);
        }
    } while (c.cid != GC_empty_chunk);
}

// Main mark loop. Stack (allocated on the heap) of `language_value_t *`
// is used to keep track of processed items. Maintaining this stack (instead of
// native one) avoids stack overflow when marking deep objects and
// makes it easier to implement parallel marking via work-stealing
LANGUAGE_EXTENSION NOINLINE void gc_mark_loop_serial(language_ptls_t ptls)
{
    gc_mark_loop_serial_(ptls, &ptls->mark_queue);
    gc_drain_own_chunkqueue(ptls, &ptls->mark_queue);
}

void gc_mark_and_steal(language_ptls_t ptls)
{
    int master_tid = language_atomic_load(&gc_master_tid);
    assert(master_tid != -1);
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    language_gc_markqueue_t *mq_master = &gc_all_tls_states[master_tid]->mark_queue;
    void *new_obj;
    language_gc_chunk_t c;
    pop : {
        new_obj = gc_ptr_queue_pop(mq);
        if (new_obj != NULL) {
            goto mark;
        }
        c = gc_chunkqueue_pop(mq);
        if (c.cid != GC_empty_chunk) {
            gc_mark_chunk(ptls, mq, &c);
            goto pop;
        }
        goto steal;
    }
    mark : {
        gc_mark_outrefs(ptls, mq, new_obj);
        goto pop;
    }
    // Note that for the stealing heuristics, we try to
    // steal chunks much more aggressively than pointers,
    // since we know chunks will likely expand into a lot
    // of work for the mark loop
    steal : {
        // Try to steal chunk from random GC thread
        for (int i = 0; i < 4 * language_n_markthreads; i++) {
            uint32_t v = gc_first_tid + cong(language_n_markthreads,  &ptls->rngseed);
            language_gc_markqueue_t *mq2 = &gc_all_tls_states[v]->mark_queue;
            c = gc_chunkqueue_steal_from(mq2);
            if (c.cid != GC_empty_chunk) {
                gc_mark_chunk(ptls, mq, &c);
                goto pop;
            }
        }
        // Sequentially walk GC threads to try to steal chunk
        for (int i = gc_first_tid; i < gc_first_tid + language_n_markthreads; i++) {
            language_gc_markqueue_t *mq2 = &gc_all_tls_states[i]->mark_queue;
            c = gc_chunkqueue_steal_from(mq2);
            if (c.cid != GC_empty_chunk) {
                gc_mark_chunk(ptls, mq, &c);
                goto pop;
            }
        }
        // Try to steal chunk from master thread
        c = gc_chunkqueue_steal_from(mq_master);
        if (c.cid != GC_empty_chunk) {
            gc_mark_chunk(ptls, mq, &c);
            goto pop;
        }
        // Try to steal pointer from random GC thread
        for (int i = 0; i < 4 * language_n_markthreads; i++) {
            uint32_t v = gc_first_tid + cong(language_n_markthreads, &ptls->rngseed);
            language_gc_markqueue_t *mq2 = &gc_all_tls_states[v]->mark_queue;
            new_obj = gc_ptr_queue_steal_from(mq2);
            if (new_obj != NULL)
                goto mark;
        }
        // Sequentially walk GC threads to try to steal pointer
        for (int i = gc_first_tid; i < gc_first_tid + language_n_markthreads; i++) {
            language_gc_markqueue_t *mq2 = &gc_all_tls_states[i]->mark_queue;
            new_obj = gc_ptr_queue_steal_from(mq2);
            if (new_obj != NULL)
                goto mark;
        }
        // Try to steal pointer from master thread
        new_obj = gc_ptr_queue_steal_from(mq_master);
        if (new_obj != NULL)
            goto mark;
    }
}

size_t gc_count_work_in_queue(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT
{
    assert(ptls != NULL);
    // assume each chunk is worth 256 units of work and each pointer
    // is worth 1 unit of work
    size_t work = 256 * (language_atomic_load_relaxed(&ptls->mark_queue.chunk_queue.bottom) -
        language_atomic_load_relaxed(&ptls->mark_queue.chunk_queue.top));
    work += (language_atomic_load_relaxed(&ptls->mark_queue.ptr_queue.bottom) -
        language_atomic_load_relaxed(&ptls->mark_queue.ptr_queue.top));
    return work;
}

/**
 * Correctness argument for the mark-loop termination protocol.
 *
 * Safety properties:
 * - No work items shall be in any thread's queues when `gc_should_mark` observes
 * that `gc_n_threads_marking` is zero.
 *
 * - No work item shall be stolen from the master thread (i.e. mutator thread which started
 * GC and which helped the `language_n_markthreads` - 1 threads to mark) after
 * `gc_should_mark` observes that `gc_n_threads_marking` is zero. This property is
 * necessary because we call `gc_mark_loop_serial` after marking the finalizer list in
 * `_language_gc_collect`, and want to ensure that we have the serial mark-loop semantics there,
 * and that no work is stolen from us at that point.
 *
 * Proof:
 * - If a thread observes that `gc_n_threads_marking` is zero inside `gc_should_mark`, that
 * means that no thread has work on their queue, this is guaranteed because a thread may only exit
 * `gc_mark_and_steal` when its own queue is empty, this information is synchronized by the
 * seq-cst fetch_add to a thread that is in `gc_should_mark`. `gc_queue_observer_lock`
 * guarantees that once `gc_n_threads_marking` reaches zero, no thread will increment it again,
 * because incrementing is only legal from inside the lock. Therefore, no thread will reenter
 * the mark-loop after `gc_n_threads_marking` reaches zero.
 */

int gc_should_mark(void)
{
    int should_mark = 0;
    uv_mutex_lock(&gc_queue_observer_lock);
    while (1) {
        int n_threads_marking = language_atomic_load(&gc_n_threads_marking);
        if (n_threads_marking == 0) {
            break;
        }
        int tid = language_atomic_load_relaxed(&gc_master_tid);
        assert(tid != -1);
        size_t work = gc_count_work_in_queue(gc_all_tls_states[tid]);
        for (tid = gc_first_tid; tid < gc_first_tid + language_n_markthreads; tid++) {
            language_ptls_t ptls2 = gc_all_tls_states[tid];
            if (ptls2 == NULL) {
                continue;
            }
            work += gc_count_work_in_queue(ptls2);
        }
        // if there is a lot of work left, enter the mark loop
        if (work >= 16 * n_threads_marking) {
            language_atomic_fetch_add(&gc_n_threads_marking, 1); // A possibility would be to allow a thread that found lots
                                                           // of work to increment this
            should_mark = 1;
            break;
        }
        language_cpu_pause();
    }
    uv_mutex_unlock(&gc_queue_observer_lock);
    return should_mark;
}

void gc_wake_all_for_marking(language_ptls_t ptls)
{
    uv_mutex_lock(&gc_threads_lock);
    uv_cond_broadcast(&gc_threads_cond);
    uv_mutex_unlock(&gc_threads_lock);
}

void gc_mark_loop_parallel(language_ptls_t ptls, int master)
{
    if (master) {
        language_atomic_store(&gc_master_tid, ptls->tid);
        language_atomic_fetch_add(&gc_n_threads_marking, 1);
        gc_wake_all_for_marking(ptls);
        gc_mark_and_steal(ptls);
        language_atomic_fetch_add(&gc_n_threads_marking, -1);
    }
    while (1) {
        int should_mark = gc_should_mark();
        if (!should_mark) {
            break;
        }
        gc_mark_and_steal(ptls);
        language_atomic_fetch_add(&gc_n_threads_marking, -1);
    }
}

void gc_mark_loop(language_ptls_t ptls)
{
    if (language_n_markthreads == 0 || gc_heap_snapshot_enabled) {
        gc_mark_loop_serial(ptls);
    }
    else {
        gc_mark_loop_parallel(ptls, 1);
    }
}

void gc_mark_loop_barrier(void)
{
    assert(language_atomic_load_relaxed(&gc_n_threads_marking) == 0);
    language_atomic_store_relaxed(&gc_master_tid, -1);
}

void gc_mark_clean_reclaim_sets(void)
{
    // Clean up `reclaim-sets`
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 == NULL) {
            continue;
        }
        arraylist_t *reclaim_set2 = &ptls2->mark_queue.reclaim_set;
        ws_array_t *a = NULL;
        while ((a = (ws_array_t *)arraylist_pop(reclaim_set2)) != NULL) {
            free(a->buffer);
            free(a);
        }
    }
    // Reset queue indices
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 == NULL) {
            continue;
        }
        language_atomic_store_relaxed(&ptls2->mark_queue.ptr_queue.bottom, 0);
        language_atomic_store_relaxed(&ptls2->mark_queue.ptr_queue.top, 0);
        language_atomic_store_relaxed(&ptls2->mark_queue.chunk_queue.bottom, 0);
        language_atomic_store_relaxed(&ptls2->mark_queue.chunk_queue.top, 0);
    }
}

static void gc_premark(language_ptls_t ptls2)
{
    arraylist_t *remset = ptls2->heap.remset;
    ptls2->heap.remset = ptls2->heap.last_remset;
    ptls2->heap.last_remset = remset;
    ptls2->heap.remset->len = 0;
    ptls2->heap.remset_nptr = 0;
    // avoid counting remembered objects
    // in `perm_scanned_bytes`
    size_t len = remset->len;
    void **items = remset->items;
    for (size_t i = 0; i < len; i++) {
        language_value_t *item = (language_value_t *)items[i];
        objprofile_count(language_typeof(item), 2, 0);
        language_astaggedvalue(item)->bits.gc = GC_OLD_MARKED;
    }
}

static void gc_queue_thread_local(language_gc_markqueue_t *mq, language_ptls_t ptls2)
{
    language_task_t *task;
    task = ptls2->root_task;
    if (task != NULL) {
        gc_try_claim_and_push(mq, task, NULL);
        gc_heap_snapshot_record_root((language_value_t*)task, "root task");
    }
    task = language_atomic_load_relaxed(&ptls2->current_task);
    if (task != NULL) {
        gc_try_claim_and_push(mq, task, NULL);
        gc_heap_snapshot_record_root((language_value_t*)task, "current task");
    }
    task = ptls2->next_task;
    if (task != NULL) {
        gc_try_claim_and_push(mq, task, NULL);
        gc_heap_snapshot_record_root((language_value_t*)task, "next task");
    }
    task = ptls2->previous_task;
    if (task != NULL) {
        gc_try_claim_and_push(mq, task, NULL);
        gc_heap_snapshot_record_root((language_value_t*)task, "previous task");
    }
    if (ptls2->previous_exception) {
        gc_try_claim_and_push(mq, ptls2->previous_exception, NULL);
        gc_heap_snapshot_record_root((language_value_t*)ptls2->previous_exception, "previous exception");
    }
}

static void gc_queue_bt_buf(language_gc_markqueue_t *mq, language_ptls_t ptls2)
{
    language_bt_element_t *bt_data = ptls2->bt_data;
    size_t bt_size = ptls2->bt_size;
    for (size_t i = 0; i < bt_size; i += language_bt_entry_size(bt_data + i)) {
        language_bt_element_t *bt_entry = bt_data + i;
        if (language_bt_is_native(bt_entry))
            continue;
        size_t njlvals = language_bt_num_jlvals(bt_entry);
        for (size_t j = 0; j < njlvals; j++)
            gc_try_claim_and_push(mq, language_bt_entry_jlvalue(bt_entry, j), NULL);
    }
}

static void gc_queue_remset(language_ptls_t ptls, language_ptls_t ptls2)
{
    size_t len = ptls2->heap.last_remset->len;
    void **items = ptls2->heap.last_remset->items;
    for (size_t i = 0; i < len; i++) {
        // Tag the pointer to indicate it's in the remset
        language_value_t *v = (language_value_t *)((uintptr_t)items[i] | GC_REMSET_PTR_TAG);
        gc_ptr_queue_push(&ptls->mark_queue, v);
    }
}

extern language_value_t *cmpswap_names LANGUAGE_GLOBALLY_ROOTED;
extern language_task_t *wait_empty LANGUAGE_GLOBALLY_ROOTED;

// mark the initial root set
static void gc_mark_roots(language_gc_markqueue_t *mq)
{
    // modules
    gc_try_claim_and_push(mq, language_main_module, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_main_module, "main_module");
    // invisible builtin values
    gc_try_claim_and_push(mq, language_an_empty_vec_any, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_an_empty_vec_any, "an_empty_vec_any");
    gc_try_claim_and_push(mq, language_module_init_order, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_module_init_order, "module_init_order");
    for (size_t i = 0; i < language_current_modules.size; i += 2) {
        if (language_current_modules.table[i + 1] != HT_NOTFOUND) {
            gc_try_claim_and_push(mq, language_current_modules.table[i], NULL);
            gc_heap_snapshot_record_gc_roots((language_value_t*)language_current_modules.table[i], "top level module");
        }
    }
    gc_try_claim_and_push(mq, language_anytuple_type_type, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_anytuple_type_type, "anytuple_type_type");
    for (size_t i = 0; i < N_CALL_CACHE; i++) {
        language_typemap_entry_t *v = language_atomic_load_relaxed(&call_cache[i]);
        gc_try_claim_and_push(mq, v, NULL);
        gc_heap_snapshot_record_array_edge_index((language_value_t*)language_anytuple_type_type, (language_value_t*)v, i);
    }
    gc_try_claim_and_push(mq, _language_debug_method_invalidation, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)_language_debug_method_invalidation, "debug_method_invalidation");
    // constants
    gc_try_claim_and_push(mq, language_emptytuple_type, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_emptytuple_type, "emptytuple_type");
    gc_try_claim_and_push(mq, cmpswap_names, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)cmpswap_names, "cmpswap_names");
    gc_try_claim_and_push(mq, language_global_roots_list, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_global_roots_list, "global_roots_list");
    gc_try_claim_and_push(mq, language_global_roots_keyset, NULL);
    gc_heap_snapshot_record_gc_roots((language_value_t*)language_global_roots_keyset, "global_roots_keyset");
}

// find unmarked objects that need to be finalized from the finalizer list "list".
// this must happen last in the mark phase.
static void sweep_finalizer_list(arraylist_t *list)
{
    void **items = list->items;
    size_t len = list->len;
    size_t j = 0;
    for (size_t i=0; i < len; i+=2) {
        void *v0 = items[i];
        void *v = gc_ptr_clear_tag(v0, 3);
        if (__unlikely(!v0)) {
            // remove from this list
            continue;
        }

        void *fin = items[i+1];
        int isfreed;
        int isold;
        if (gc_ptr_tag(v0, 2)) {
            isfreed = 1;
            isold = 0;
        }
        else {
            isfreed = !gc_marked(language_astaggedvalue(v)->bits.gc);
            isold = (list != &finalizer_list_marked &&
                     language_astaggedvalue(v)->bits.gc == GC_OLD_MARKED &&
                     language_astaggedvalue(fin)->bits.gc == GC_OLD_MARKED);
        }
        if (isfreed || isold) {
            // remove from this list
        }
        else {
            if (j < i) {
                items[j] = items[i];
                items[j+1] = items[i+1];
            }
            j += 2;
        }
        if (isfreed) {
            schedule_finalization(v0, fin);
        }
        if (isold) {
            // The caller relies on the new objects to be pushed to the end of
            // the list!!
            arraylist_push(&finalizer_list_marked, v0);
            arraylist_push(&finalizer_list_marked, fin);
        }
    }
    list->len = j;
}

// collector entry point and control
_Atomic(uint32_t) language_gc_disable_counter = 1;

LANGUAGE_DLLEXPORT int language_gc_enable(int on)
{
    language_ptls_t ptls = language_current_task->ptls;
    int prev = !ptls->disable_gc;
    ptls->disable_gc = (on == 0);
    if (on && !prev) {
        // disable -> enable
        if (language_atomic_fetch_add(&language_gc_disable_counter, -1) == 1) {
            gc_num.allocd += gc_num.deferred_alloc;
            gc_num.deferred_alloc = 0;
        }
    }
    else if (prev && !on) {
        // enable -> disable
        language_atomic_fetch_add(&language_gc_disable_counter, 1);
        // check if the GC is running and wait for it to finish
        language_gc_safepoint_(ptls);
    }
    return prev;
}

LANGUAGE_DLLEXPORT int language_gc_is_enabled(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    return !ptls->disable_gc;
}

LANGUAGE_DLLEXPORT void language_gc_get_total_bytes(int64_t *bytes) LANGUAGE_NOTSAFEPOINT
{
    language_gc_num_t num = gc_num;
    combine_thread_gc_counts(&num, 0);
    // Sync this logic with `base/util.jl:GC_Diff`
    *bytes = (num.total_allocd + num.deferred_alloc + num.allocd);
}

LANGUAGE_DLLEXPORT uint64_t language_gc_total_hrtime(void)
{
    return gc_num.total_time;
}

LANGUAGE_DLLEXPORT language_gc_num_t language_gc_num(void)
{
    language_gc_num_t num = gc_num;
    combine_thread_gc_counts(&num, 0);
    return num;
}

LANGUAGE_DLLEXPORT void language_gc_reset_stats(void)
{
    gc_num.max_pause = 0;
    gc_num.max_memory = 0;
    gc_num.max_time_to_safepoint = 0;
}

// TODO: these were supposed to be thread local
LANGUAGE_DLLEXPORT int64_t language_gc_diff_total_bytes(void) LANGUAGE_NOTSAFEPOINT
{
    int64_t oldtb = last_gc_total_bytes;
    int64_t newtb;
    language_gc_get_total_bytes(&newtb);
    last_gc_total_bytes = newtb;
    return newtb - oldtb;
}

LANGUAGE_DLLEXPORT int64_t language_gc_sync_total_bytes(int64_t offset) LANGUAGE_NOTSAFEPOINT
{
    int64_t oldtb = last_gc_total_bytes;
    int64_t newtb;
    language_gc_get_total_bytes(&newtb);
    last_gc_total_bytes = newtb - offset;
    return newtb - oldtb;
}

LANGUAGE_DLLEXPORT int64_t language_gc_pool_live_bytes(void)
{
    int n_threads = language_atomic_load_acquire(&language_n_threads);
    language_ptls_t *all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    int64_t pool_live_bytes = 0;
    for (int i = 0; i < n_threads; i++) {
        language_ptls_t ptls2 = all_tls_states[i];
        if (ptls2 != NULL) {
            pool_live_bytes += language_atomic_load_relaxed(&ptls2->gc_num.pool_live_bytes);
        }
    }
    return pool_live_bytes;
}

LANGUAGE_DLLEXPORT int64_t language_gc_live_bytes(void)
{
    return live_bytes;
}

uint64_t language_gc_smooth(uint64_t old_val, uint64_t new_val, double factor)
{
    double est = factor * old_val + (1 - factor) * new_val;
    if (est <= 1)
        return 1; // avoid issues with <= 0
    if (est > (uint64_t)2<<36)
        return (uint64_t)2<<36; // avoid overflow
    return est;
}

// an overallocation curve inspired by array allocations
// grows very fast initially, then much slower at large heaps
static uint64_t overallocation(uint64_t old_val, uint64_t val, uint64_t max_val)
{
    // compute maxsize = maxsize + 4*maxsize^(7/8) + maxsize/8
    // for small n, we grow much faster than O(n)
    // for large n, we grow at O(n/8)
    // and as we reach O(memory) for memory>>1MB,
    // this means we end by adding about 10% of memory each time at most
    int exp2 = sizeof(old_val) * 8 -
#ifdef _P64
        __builtin_clzll(old_val);
#else
        __builtin_clz(old_val);
#endif
    uint64_t inc = (uint64_t)((size_t)1 << (exp2 * 7 / 8)) * 4 + old_val / 8;
    // once overallocation would exceed max_val, grow by no more than 5% of max_val
    if (inc + val > max_val)
        if (inc > max_val / 20)
            return max_val / 20;
    return inc;
}

size_t language_maxrss(void);

// Only one thread should be running in this function
static int _language_gc_collect(language_ptls_t ptls, language_gc_collection_t collection)
{
    combine_thread_gc_counts(&gc_num, 1);

    // We separate the update of the graph from the update of live_bytes here
    // so that the sweep shows a downward trend in memory usage.
    language_timing_counter_inc(LANGUAGE_TIMING_COUNTER_HeapSize, gc_num.allocd);

    language_gc_markqueue_t *mq = &ptls->mark_queue;

    uint64_t gc_start_time = language_hrtime();
    uint64_t mutator_time = gc_end_time == 0 ? old_mut_time : gc_start_time - gc_end_time;
    uint64_t before_free_heap_size = language_atomic_load_relaxed(&gc_heap_stats.heap_size);
    int64_t last_perm_scanned_bytes = perm_scanned_bytes;
    uint64_t start_mark_time = language_hrtime();
    LANGUAGE_PROBE_GC_MARK_BEGIN();
    {
        LANGUAGE_TIMING(GC, GC_Mark);

        // 1. fix GC bits of objects in the remset.
        assert(gc_n_threads);
        for (int t_i = 0; t_i < gc_n_threads; t_i++) {
            language_ptls_t ptls2 = gc_all_tls_states[t_i];
            if (ptls2 != NULL)
                gc_premark(ptls2);
        }

        assert(gc_n_threads);
        int single_threaded_mark = (language_n_markthreads == 0 || gc_heap_snapshot_enabled);
        for (int t_i = 0; t_i < gc_n_threads; t_i++) {
            language_ptls_t ptls2 = gc_all_tls_states[t_i];
            language_ptls_t ptls_dest = ptls;
            language_gc_markqueue_t *mq_dest = mq;
            if (!single_threaded_mark) {
                ptls_dest = gc_all_tls_states[gc_first_tid + t_i % language_n_markthreads];
                mq_dest = &ptls_dest->mark_queue;
            }
            if (ptls2 != NULL) {
                // 2.1. mark every thread local root
                gc_queue_thread_local(mq_dest, ptls2);
                // 2.2. mark any managed objects in the backtrace buffer
                // TODO: treat these as roots for gc_heap_snapshot_record
                gc_queue_bt_buf(mq_dest, ptls2);
                // 2.3. mark every object in the `last_remsets` and `rem_binding`
                gc_queue_remset(ptls_dest, ptls2);
            }
        }

        // 3. walk roots
        gc_mark_roots(mq);
        if (gc_cblist_root_scanner) {
            gc_invoke_callbacks(language_gc_cb_root_scanner_t,
                gc_cblist_root_scanner, (collection));
        }
        gc_mark_loop(ptls);
        gc_mark_loop_barrier();
        gc_mark_clean_reclaim_sets();

        // 4. check for objects to finalize
        clear_weak_refs();
        // Record the length of the marked list since we need to
        // mark the object moved to the marked list from the
        // `finalizer_list` by `sweep_finalizer_list`
        size_t orig_marked_len = finalizer_list_marked.len;
        assert(gc_n_threads);
        for (int i = 0; i < gc_n_threads; i++) {
            language_ptls_t ptls2 = gc_all_tls_states[i];
            if (ptls2 != NULL)
                sweep_finalizer_list(&ptls2->finalizers);
        }
        if (prev_sweep_full) {
            sweep_finalizer_list(&finalizer_list_marked);
            orig_marked_len = 0;
        }
        assert(gc_n_threads);
        for (int i = 0; i < gc_n_threads; i++) {
            language_ptls_t ptls2 = gc_all_tls_states[i];
            if (ptls2 != NULL)
                gc_mark_finlist(mq, &ptls2->finalizers, 0);
        }
        gc_mark_finlist(mq, &finalizer_list_marked, orig_marked_len);
        // "Flush" the mark stack before flipping the reset_age bit
        // so that the objects are not incorrectly reset.
        gc_mark_loop_serial(ptls);
        // Conservative marking relies on age to tell allocated objects
        // and freelist entries apart.
        mark_reset_age = !language_gc_conservative_gc_support_enabled();
        // Reset the age and old bit for any unmarked objects referenced by the
        // `to_finalize` list. These objects are only reachable from this list
        // and should not be referenced by any old objects so this won't break
        // the GC invariant.
        gc_mark_finlist(mq, &to_finalize, 0);
        gc_mark_loop_serial(ptls);
        mark_reset_age = 0;
    }

    LANGUAGE_PROBE_GC_MARK_END(scanned_bytes, perm_scanned_bytes);
    gc_settime_premark_end();
    gc_time_mark_pause(gc_start_time, scanned_bytes, perm_scanned_bytes);
    uint64_t end_mark_time = language_hrtime();
    uint64_t mark_time = end_mark_time - start_mark_time;
    gc_num.mark_time = mark_time;
    gc_num.total_mark_time += mark_time;
    gc_settime_postmark_end();
    // marking is over

    // Flush everything in mark cache
    gc_sync_all_caches_nolock(ptls);


    gc_verify(ptls);
    gc_stats_all_pool();
    gc_stats_big_obj();
    objprofile_printall();
    objprofile_reset();
    gc_num.total_allocd += gc_num.allocd;
    if (!prev_sweep_full)
        promoted_bytes += perm_scanned_bytes - last_perm_scanned_bytes;
    // 5. next collection decision
    int remset_nptr = 0;
    int sweep_full = next_sweep_full;
    int recollect = 0;
    assert(gc_n_threads);
    for (int i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            remset_nptr += ptls2->heap.remset_nptr;
    }
    (void)remset_nptr; //Use this information for something?


    // If the live data outgrows the suggested max_total_memory
    // we keep going with minimum intervals and full gcs until
    // we either free some space or get an OOM error.
    if (gc_sweep_always_full) {
        sweep_full = 1;
    }
    if (collection == LANGUAGE_GC_FULL && !prev_sweep_full) {
        sweep_full = 1;
        recollect = 1;
    }
    if (sweep_full) {
        // these are the difference between the number of gc-perm bytes scanned
        // on the first collection after sweep_full, and the current scan
        perm_scanned_bytes = 0;
        promoted_bytes = 0;
    }
    scanned_bytes = 0;
    // 6. start sweeping
    uint64_t start_sweep_time = language_hrtime();
    LANGUAGE_PROBE_GC_SWEEP_BEGIN(sweep_full);
    {
        LANGUAGE_TIMING_CREATE_BLOCK(incremental_timing_block,
                               GC, GC_IncrementalSweep);
        LANGUAGE_TIMING_CREATE_BLOCK(full_timing_block,
                               GC, GC_FullSweep);
        language_timing_block_start(sweep_full ? &full_timing_block : &incremental_timing_block);
#ifdef USE_TRACY
        TracyCZoneColor(full_timing_block.tracy_ctx, 0xFFA500);
#endif
        current_sweep_full = sweep_full;
        sweep_weak_refs();
        sweep_stack_pools();
        gc_sweep_foreign_objs();
        gc_sweep_other(ptls, sweep_full);
        gc_scrub();
        gc_verify_tags();
        gc_sweep_pool();
        if (sweep_full)
            gc_sweep_perm_alloc();
    }

    LANGUAGE_PROBE_GC_SWEEP_END();

    gc_end_time = language_hrtime();
    uint64_t pause = gc_end_time - gc_start_time;
    uint64_t sweep_time = gc_end_time - start_sweep_time;
    gc_num.total_sweep_time += sweep_time;
    gc_num.sweep_time = sweep_time;
    if (sweep_full) {
        gc_num.last_full_sweep = gc_end_time;
    }
    else {
        gc_num.last_incremental_sweep = gc_end_time;
    }

    size_t heap_size = language_atomic_load_relaxed(&gc_heap_stats.heap_size) - freed_in_runtime;
    language_atomic_store_relaxed(&gc_heap_stats.heap_size, heap_size);
    freed_in_runtime = 0;
    uint64_t user_max = max_total_memory * 0.8;
    uint64_t alloc_diff = before_free_heap_size - old_heap_size;
    uint64_t freed_diff = before_free_heap_size - heap_size;
    uint64_t target_heap;
    const char *reason = ""; (void)reason; // for GC_TIME output stats
    old_heap_size = heap_size; // TODO: Update these values dynamically instead of just during the GC
    if (collection == LANGUAGE_GC_AUTO) {
        // update any heuristics only when the user does not force the GC
        // but still update the timings, since GC was run and reset, even if it was too early
        uint64_t target_allocs = 0.0;
        double alloc_smooth_factor = 0.95;
        double collect_smooth_factor = 0.5;
        double tuning_factor = 2e4;
        uint64_t alloc_mem = language_gc_smooth(old_alloc_diff, alloc_diff, alloc_smooth_factor);
        uint64_t alloc_time = language_gc_smooth(old_mut_time, mutator_time, alloc_smooth_factor); // TODO: subtract estimated finalizer time?
        uint64_t gc_mem = language_gc_smooth(old_freed_diff, freed_diff, collect_smooth_factor);
        uint64_t gc_time = language_gc_smooth(old_pause_time, pause - sweep_time, collect_smooth_factor);
        old_alloc_diff = alloc_mem;
        old_mut_time = alloc_time;
        old_freed_diff = gc_mem;
        old_pause_time = gc_time;
        // thrashing estimator: if GC time more than 50% of the runtime
        if (pause > mutator_time && !(thrash_counter < 4))
            thrash_counter += 1;
        else if (thrash_counter > 0)
            thrash_counter -= 1;
        if (alloc_mem != 0 && alloc_time != 0 && gc_mem != 0 && gc_time != 0) {
            double alloc_rate = (double)alloc_mem/alloc_time;
            double gc_rate = (double)gc_mem/gc_time;
            target_allocs = sqrt((double)heap_size * alloc_rate / gc_rate) * tuning_factor;
        }

        if (thrashing == 0 && thrash_counter >= 3) {
            // require 3 consecutive thrashing cycles to force the default allocator rate
            thrashing = 1;
            // and require 4 default allocations to clear
            thrash_counter = 6;
        }
        else if (thrashing == 1 && thrash_counter <= 2) {
            thrashing = 0; // maybe we should report this to the user or error out?
        }

        target_heap = target_allocs + heap_size;
        // optionally smooth this:
        //   target_heap = language_gc_smooth(language_atomic_load_relaxed(&gc_heap_stats.heap_target), target_heap, alloc_smooth_factor);

        // compute some guardrails values
        uint64_t min_target_allocs = heap_size / 20; // minimum 5% of current heap
        if (min_target_allocs < default_collect_interval / 8) // unless the heap is small
            min_target_allocs = default_collect_interval / 8;
        uint64_t max_target_allocs = overallocation(before_free_heap_size, heap_size, user_max);
        if (max_target_allocs < min_target_allocs)
            max_target_allocs = min_target_allocs;
        // respect max_total_memory first
        if (target_heap > user_max) {
            target_allocs = heap_size < user_max ? user_max - heap_size : 1;
            reason = " user limit";
        }
        // If we are thrashing use a default only (an average) for a couple collections
        if (thrashing) {
            uint64_t thrashing_allocs = sqrt((double)min_target_allocs * max_target_allocs);
            if (target_allocs < thrashing_allocs) {
                target_allocs = thrashing_allocs;
                reason = " thrashing";
            }
        }
        // then add the guardrails for transient issues
        if (target_allocs > max_target_allocs) {
            target_allocs = max_target_allocs;
            reason = " rate limit max";
        }
        else if (target_allocs < min_target_allocs) {
            target_allocs = min_target_allocs;
            reason = " min limit";
        }
        // and set the heap detection threshold
        target_heap = target_allocs + heap_size;
        if (target_heap < default_collect_interval) {
            target_heap = default_collect_interval;
            reason = " min heap";
        }
        language_atomic_store_relaxed(&gc_heap_stats.heap_target, target_heap);
    }
    else {
        target_heap = language_atomic_load_relaxed(&gc_heap_stats.heap_target);
    }

    double old_ratio = (double)promoted_bytes/(double)heap_size;
    if (heap_size > user_max || old_ratio > 0.15)
        next_sweep_full = 1;
    else
        next_sweep_full = 0;
    if (heap_size > user_max || thrashing)
        under_pressure = 1;
    // sweeping is over
    // 7. if it is a quick sweep, put back the remembered objects in queued state
    // so that we don't trigger the barrier again on them.
    assert(gc_n_threads);
    for (int t_i = 0; t_i < gc_n_threads; t_i++) {
        language_ptls_t ptls2 = gc_all_tls_states[t_i];
        if (ptls2 == NULL)
            continue;
        if (!sweep_full) {
            for (int i = 0; i < ptls2->heap.remset->len; i++) {
                void *ptr = ptls2->heap.remset->items[i];
                language_astaggedvalue(ptr)->bits.gc = GC_MARKED;
            }
        }
        else {
            ptls2->heap.remset->len = 0;
        }
        // free empty GC state for threads that have exited
        if (language_atomic_load_relaxed(&ptls2->current_task) == NULL &&
            (ptls->tid < gc_first_tid || ptls2->tid >= gc_first_tid + language_n_gcthreads)) {
            language_thread_heap_t *heap = &ptls2->heap;
            if (heap->weak_refs.len == 0)
                small_arraylist_free(&heap->weak_refs);
            if (heap->live_tasks.len == 0)
                small_arraylist_free(&heap->live_tasks);
            if (heap->remset->len == 0)
                arraylist_free(heap->remset);
            if (heap->last_remset->len == 0)
                arraylist_free(heap->last_remset);
            if (ptls2->finalizers.len == 0)
                arraylist_free(&ptls2->finalizers);
            if (ptls2->sweep_objs.len == 0)
                arraylist_free(&ptls2->sweep_objs);
            gc_move_to_global_page_pool(&ptls2->page_metadata_buffered);
        }
    }

#ifdef __GLIBC__
    if (sweep_full) {
        // issue #30653
        // empirically, the malloc runaway seemed to occur within a growth gap
        // of about 20-25%
        if (language_maxrss() > (last_trim_maxrss/4)*5) {
            malloc_trim(0);
            last_trim_maxrss = language_maxrss();
        }
    }
#endif

    _report_gc_finished(pause, gc_num.freed, sweep_full, recollect, live_bytes);
    uint64_t max_memory = last_live_bytes + gc_num.allocd;
    if (max_memory > gc_num.max_memory) {
        gc_num.max_memory = max_memory;
    }
    gc_final_pause_end(gc_start_time, gc_end_time);
    gc_time_sweep_pause(gc_end_time, gc_num.allocd, live_bytes,
                        gc_num.freed, sweep_full);
    gc_num.full_sweep += sweep_full;
    last_live_bytes = live_bytes;
    live_bytes += -gc_num.freed + gc_num.allocd;
    language_timing_counter_dec(LANGUAGE_TIMING_COUNTER_HeapSize, gc_num.freed);

    gc_time_summary(sweep_full, t_start, gc_end_time, gc_num.freed,
                    live_bytes, gc_num.interval, pause,
                    gc_num.time_to_safepoint,
                    gc_num.mark_time, gc_num.sweep_time);
    if (collection == LANGUAGE_GC_AUTO) {
        gc_heuristics_summary(
            old_alloc_diff, alloc_diff,
            old_mut_time, mutator_time,
            old_freed_diff, freed_diff,
            old_pause_time, pause - sweep_time,
            thrash_counter, reason,
            heap_size, target_heap);
    }

    prev_sweep_full = sweep_full;
    gc_num.pause += !recollect;
    gc_num.total_time += pause;
    gc_num.allocd = 0;
    gc_num.freed = 0;
    if (pause > gc_num.max_pause) {
        gc_num.max_pause = pause;
    }
    reset_thread_gc_counts();

    return recollect;
}

LANGUAGE_DLLEXPORT void language_gc_collect(language_gc_collection_t collection)
{
    LANGUAGE_PROBE_GC_BEGIN(collection);

    language_task_t *ct = language_current_task;
    language_ptls_t ptls = ct->ptls;
    if (language_atomic_load_acquire(&language_gc_disable_counter)) {
        size_t localbytes = language_atomic_load_relaxed(&ptls->gc_num.allocd) + gc_num.interval;
        language_atomic_store_relaxed(&ptls->gc_num.allocd, -(int64_t)gc_num.interval);
        static_assert(sizeof(_Atomic(uint64_t)) == sizeof(gc_num.deferred_alloc), "");
        language_atomic_fetch_add_relaxed((_Atomic(uint64_t)*)&gc_num.deferred_alloc, localbytes);
        return;
    }
    language_gc_debug_print();

    int8_t old_state = language_atomic_load_relaxed(&ptls->gc_state);
    language_atomic_store_release(&ptls->gc_state, LANGUAGE_GC_STATE_WAITING);
    // `language_safepoint_start_gc()` makes sure only one thread can run the GC.
    uint64_t t0 = language_hrtime();
    if (!language_safepoint_start_gc()) {
        // either another thread is running GC, or the GC got disabled just now.
        language_gc_state_set(ptls, old_state, LANGUAGE_GC_STATE_WAITING);
        language_safepoint_wait_thread_resume(); // block in thread-suspend now if requested, after clearing the gc_state
        return;
    }

    LANGUAGE_TIMING_SUSPEND_TASK(GC, ct);
    LANGUAGE_TIMING(GC, GC);

    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    // Now we are ready to wait for other threads to hit the safepoint,
    // we can do a few things that doesn't require synchronization.
    //
    // We must sync here with the tls_lock operations, so that we have a
    // seq-cst order between these events now we know that either the new
    // thread must run into our safepoint flag or we must observe the
    // existence of the thread in the language_n_threads count.
    //
    // TODO: concurrently queue objects
    language_fence();
    gc_n_threads = language_atomic_load_acquire(&language_n_threads);
    gc_all_tls_states = language_atomic_load_relaxed(&language_all_tls_states);
    language_gc_wait_for_the_world(gc_all_tls_states, gc_n_threads);
    LANGUAGE_PROBE_GC_STOP_THE_WORLD();

    uint64_t t1 = language_hrtime();
    uint64_t duration = t1 - t0;
    if (duration > gc_num.max_time_to_safepoint)
        gc_num.max_time_to_safepoint = duration;
    gc_num.time_to_safepoint = duration;
    gc_num.total_time_to_safepoint += duration;

    gc_invoke_callbacks(language_gc_cb_pre_gc_t,
        gc_cblist_pre_gc, (collection));

    if (!language_atomic_load_acquire(&language_gc_disable_counter)) {
        LANGUAGE_LOCK_NOGC(&finalizers_lock); // all the other threads are stopped, so this does not make sense, right? otherwise, failing that, this seems like plausibly a deadlock
#ifndef __clang_gcanalyzer__
        if (_language_gc_collect(ptls, collection)) {
            // recollect
            int ret = _language_gc_collect(ptls, LANGUAGE_GC_AUTO);
            (void)ret;
            assert(!ret);
        }
#endif
        LANGUAGE_UNLOCK_NOGC(&finalizers_lock);
    }

    gc_n_threads = 0;
    gc_all_tls_states = NULL;
    language_safepoint_end_gc();
    language_gc_state_set(ptls, old_state, LANGUAGE_GC_STATE_WAITING);
    LANGUAGE_PROBE_GC_END();
    language_safepoint_wait_thread_resume(); // block in thread-suspend now if requested, after clearing the gc_state

    // Only disable finalizers on current thread
    // Doing this on all threads is racy (it's impossible to check
    // or wait for finalizers on other threads without dead lock).
    if (!ptls->finalizers_inhibited && ptls->locks.len == 0) {
        LANGUAGE_TIMING(GC, GC_Finalizers);
        run_finalizers(ct, 0);
    }
    LANGUAGE_PROBE_GC_FINALIZER();

    gc_invoke_callbacks(language_gc_cb_post_gc_t,
        gc_cblist_post_gc, (collection));
    if (under_pressure)
        gc_invoke_callbacks(language_gc_cb_notify_gc_pressure_t,
            gc_cblist_notify_gc_pressure, ());
    under_pressure = 0;
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
}

void gc_mark_queue_all_roots(language_ptls_t ptls, language_gc_markqueue_t *mq)
{
    assert(gc_n_threads);
    for (size_t i = 0; i < gc_n_threads; i++) {
        language_ptls_t ptls2 = gc_all_tls_states[i];
        if (ptls2 != NULL)
            gc_queue_thread_local(mq, ptls2);
    }
    gc_mark_roots(mq);
}

// allocator entry points

LANGUAGE_DLLEXPORT language_value_t *(language_gc_alloc)(language_ptls_t ptls, size_t sz, void *ty)
{
    return language_gc_alloc_(ptls, sz, ty);
}

// Per-thread initialization
void language_init_thread_heap(language_ptls_t ptls)
{
    language_thread_heap_t *heap = &ptls->heap;
    language_gc_pool_t *p = heap->norm_pools;
    for (int i = 0; i < LANGUAGE_GC_N_POOLS; i++) {
        p[i].osize = language_gc_sizeclasses[i];
        p[i].freelist = NULL;
        p[i].newpages = NULL;
    }
    small_arraylist_new(&heap->weak_refs, 0);
    small_arraylist_new(&heap->live_tasks, 0);
    for (int i = 0; i < LANGUAGE_N_STACK_POOLS; i++)
        small_arraylist_new(&heap->free_stacks[i], 0);
    heap->mallocarrays = NULL;
    heap->mafreelist = NULL;
    heap->big_objects = NULL;
    heap->remset = &heap->_remset[0];
    heap->last_remset = &heap->_remset[1];
    arraylist_new(heap->remset, 0);
    arraylist_new(heap->last_remset, 0);
    arraylist_new(&ptls->finalizers, 0);
    arraylist_new(&ptls->sweep_objs, 0);

    language_gc_mark_cache_t *gc_cache = &ptls->gc_cache;
    gc_cache->perm_scanned_bytes = 0;
    gc_cache->scanned_bytes = 0;
    gc_cache->nbig_obj = 0;

    // Initialize GC mark-queue
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    ws_queue_t *cq = &mq->chunk_queue;
    ws_array_t *wsa = create_ws_array(GC_CHUNK_QUEUE_INIT_SIZE, sizeof(language_gc_chunk_t));
    language_atomic_store_relaxed(&cq->top, 0);
    language_atomic_store_relaxed(&cq->bottom, 0);
    language_atomic_store_relaxed(&cq->array, wsa);
    ws_queue_t *q = &mq->ptr_queue;
    ws_array_t *wsa2 = create_ws_array(GC_PTR_QUEUE_INIT_SIZE, sizeof(language_value_t *));
    language_atomic_store_relaxed(&q->top, 0);
    language_atomic_store_relaxed(&q->bottom, 0);
    language_atomic_store_relaxed(&q->array, wsa2);
    arraylist_new(&mq->reclaim_set, 32);

    memset(&ptls->gc_num, 0, sizeof(ptls->gc_num));
    language_atomic_store_relaxed(&ptls->gc_num.allocd, -(int64_t)gc_num.interval);
}

void language_free_thread_gc_state(language_ptls_t ptls)
{
    language_gc_markqueue_t *mq = &ptls->mark_queue;
    ws_queue_t *cq = &mq->chunk_queue;
    free_ws_array(language_atomic_load_relaxed(&cq->array));
    language_atomic_store_relaxed(&cq->array, NULL);
    ws_queue_t *q = &mq->ptr_queue;
    free_ws_array(language_atomic_load_relaxed(&q->array));
    language_atomic_store_relaxed(&q->array, NULL);
    arraylist_free(&mq->reclaim_set);
}

// System-wide initializations
void language_gc_init(void)
{
    LANGUAGE_MUTEX_INIT(&heapsnapshot_lock, "heapsnapshot_lock");
    LANGUAGE_MUTEX_INIT(&finalizers_lock, "finalizers_lock");
    uv_mutex_init(&page_profile_lock);
    uv_mutex_init(&gc_cache_lock);
    uv_mutex_init(&gc_perm_lock);
    uv_mutex_init(&gc_threads_lock);
    uv_cond_init(&gc_threads_cond);
    uv_sem_init(&gc_sweep_assists_needed, 0);
    uv_mutex_init(&gc_queue_observer_lock);

    language_gc_init_page();
    language_gc_debug_init();

    arraylist_new(&finalizer_list_marked, 0);
    arraylist_new(&to_finalize, 0);
    language_atomic_store_relaxed(&gc_heap_stats.heap_target, default_collect_interval);
    gc_num.interval = default_collect_interval;
    last_long_collect_interval = default_collect_interval;
    gc_num.allocd = 0;
    gc_num.max_pause = 0;
    gc_num.max_memory = 0;

    uint64_t mem_reserve = 250*1024*1024; // LLVM + other libraries need some amount of memory
    uint64_t min_heap_size_hint = mem_reserve + 1*1024*1024;
    uint64_t hint = language_options.heap_size_hint;
#ifdef _P64
    total_mem = uv_get_total_memory();
    if (hint == 0) {
        uint64_t constrained_mem = uv_get_constrained_memory();
        if (constrained_mem > 0 && constrained_mem < total_mem)
            hint = constrained_mem;
    }
#endif
    if (hint) {
        if (hint < min_heap_size_hint)
            hint = min_heap_size_hint;
        language_gc_set_max_memory(hint - mem_reserve);
    }

    t_start = language_hrtime();
}

LANGUAGE_DLLEXPORT void language_gc_set_max_memory(uint64_t max_mem)
{
    if (max_mem > 0
        && max_mem < (uint64_t)1 << (sizeof(memsize_t) * 8 - 1)) {
        #ifdef _P64
        max_total_memory = max_mem;
        #else
        max_total_memory = max_mem < MAX32HEAP ? max_mem : MAX32HEAP;
        #endif
    }
}

LANGUAGE_DLLEXPORT uint64_t language_gc_get_max_memory(void)
{
    return max_total_memory;
}

// callback for passing OOM errors from gmp
LANGUAGE_DLLEXPORT void language_throw_out_of_memory_error(void)
{
    language_throw(language_memory_exception);
}

// allocation wrappers that track allocation and let collection run

LANGUAGE_DLLEXPORT void *language_gc_counted_malloc(size_t sz)
{
    language_gcframe_t **pgcstack = language_get_pgcstack();
    language_task_t *ct = language_current_task;
    void *data = malloc(sz);
    if (data != NULL && pgcstack != NULL && ct->world_age) {
        language_ptls_t ptls = ct->ptls;
        maybe_collect(ptls);
        language_atomic_store_relaxed(&ptls->gc_num.allocd,
            language_atomic_load_relaxed(&ptls->gc_num.allocd) + sz);
        language_atomic_store_relaxed(&ptls->gc_num.malloc,
            language_atomic_load_relaxed(&ptls->gc_num.malloc) + 1);
        language_batch_accum_heap_size(ptls, sz);
    }
    return data;
}

LANGUAGE_DLLEXPORT void *language_gc_counted_calloc(size_t nm, size_t sz)
{
    language_gcframe_t **pgcstack = language_get_pgcstack();
    language_task_t *ct = language_current_task;
    void *data = calloc(nm, sz);
    if (data != NULL && pgcstack != NULL && ct->world_age) {
        language_ptls_t ptls = ct->ptls;
        maybe_collect(ptls);
        language_atomic_store_relaxed(&ptls->gc_num.allocd,
            language_atomic_load_relaxed(&ptls->gc_num.allocd) + nm*sz);
        language_atomic_store_relaxed(&ptls->gc_num.malloc,
            language_atomic_load_relaxed(&ptls->gc_num.malloc) + 1);
        language_batch_accum_heap_size(ptls, sz * nm);
    }
    return data;
}

LANGUAGE_DLLEXPORT void language_gc_counted_free_with_size(void *p, size_t sz)
{
    language_gcframe_t **pgcstack = language_get_pgcstack();
    language_task_t *ct = language_current_task;
    free(p);
    if (pgcstack != NULL && ct->world_age) {
        language_batch_accum_free_size(ct->ptls, sz);
    }
}

LANGUAGE_DLLEXPORT void *language_gc_counted_realloc_with_old_size(void *p, size_t old, size_t sz)
{
    language_gcframe_t **pgcstack = language_get_pgcstack();
    language_task_t *ct = language_current_task;
    void *data = realloc(p, sz);
    if (data != NULL && pgcstack != NULL && ct->world_age) {
        language_ptls_t ptls = ct->ptls;
        maybe_collect(ptls);
        if (!(sz < old))
            language_atomic_store_relaxed(&ptls->gc_num.allocd,
                language_atomic_load_relaxed(&ptls->gc_num.allocd) + (sz - old));
        language_atomic_store_relaxed(&ptls->gc_num.realloc,
            language_atomic_load_relaxed(&ptls->gc_num.realloc) + 1);

        int64_t diff = sz - old;
        if (diff < 0) {
            language_batch_accum_free_size(ptls, -diff);
        }
        else {
            language_batch_accum_heap_size(ptls, diff);
        }
    }
    return data;
}

// allocation wrappers that save the size of allocations, to allow using
// language_gc_counted_* functions with a libc-compatible API.

LANGUAGE_DLLEXPORT void *language_malloc(size_t sz)
{
    int64_t *p = (int64_t *)language_gc_counted_malloc(sz + LANGUAGE_SMALL_BYTE_ALIGNMENT);
    if (p == NULL)
        return NULL;
    p[0] = sz;
    return (void *)(p + 2); // assumes LANGUAGE_SMALL_BYTE_ALIGNMENT == 16
}

//_unchecked_calloc does not check for potential overflow of nm*sz
STATIC_INLINE void *_unchecked_calloc(size_t nm, size_t sz) {
    size_t nmsz = nm*sz;
    int64_t *p = (int64_t *)language_gc_counted_calloc(nmsz + LANGUAGE_SMALL_BYTE_ALIGNMENT, 1);
    if (p == NULL)
        return NULL;
    p[0] = nmsz;
    return (void *)(p + 2); // assumes LANGUAGE_SMALL_BYTE_ALIGNMENT == 16
}

LANGUAGE_DLLEXPORT void *language_calloc(size_t nm, size_t sz)
{
    if (nm > SSIZE_MAX/sz - LANGUAGE_SMALL_BYTE_ALIGNMENT)
        return NULL;
    return _unchecked_calloc(nm, sz);
}

LANGUAGE_DLLEXPORT void language_free(void *p)
{
    if (p != NULL) {
        int64_t *pp = (int64_t *)p - 2;
        size_t sz = pp[0];
        language_gc_counted_free_with_size(pp, sz + LANGUAGE_SMALL_BYTE_ALIGNMENT);
    }
}

LANGUAGE_DLLEXPORT void *language_realloc(void *p, size_t sz)
{
    int64_t *pp;
    size_t szold;
    if (p == NULL) {
        pp = NULL;
        szold = 0;
    }
    else {
        pp = (int64_t *)p - 2;
        szold = pp[0] + LANGUAGE_SMALL_BYTE_ALIGNMENT;
    }
    int64_t *pnew = (int64_t *)language_gc_counted_realloc_with_old_size(pp, szold, sz + LANGUAGE_SMALL_BYTE_ALIGNMENT);
    if (pnew == NULL)
        return NULL;
    pnew[0] = sz;
    return (void *)(pnew + 2); // assumes LANGUAGE_SMALL_BYTE_ALIGNMENT == 16
}

// allocating blocks for Arrays and Strings

LANGUAGE_DLLEXPORT void *language_gc_managed_malloc(size_t sz)
{
    language_ptls_t ptls = language_current_task->ptls;
    maybe_collect(ptls);
    size_t allocsz = LLT_ALIGN(sz, LANGUAGE_CACHE_BYTE_ALIGNMENT);
    if (allocsz < sz)  // overflow in adding offs, size was "negative"
        language_throw(language_memory_exception);

    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    void *b = malloc_cache_align(allocsz);
    if (b == NULL)
        language_throw(language_memory_exception);

    language_atomic_store_relaxed(&ptls->gc_num.allocd,
        language_atomic_load_relaxed(&ptls->gc_num.allocd) + allocsz);
    language_atomic_store_relaxed(&ptls->gc_num.malloc,
        language_atomic_load_relaxed(&ptls->gc_num.malloc) + 1);
    language_batch_accum_heap_size(ptls, allocsz);
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
    // language_gc_managed_malloc is currently always used for allocating array buffers.
    maybe_record_alloc_to_profile((language_value_t*)b, sz, (language_datatype_t*)language_buff_tag);
    return b;
}

static void *gc_managed_realloc_(language_ptls_t ptls, void *d, size_t sz, size_t oldsz,
                                 int isaligned, language_value_t *owner, int8_t can_collect)
{
    if (can_collect)
        maybe_collect(ptls);
    int is_old_marked = language_astaggedvalue(owner)->bits.gc == GC_OLD_MARKED;
    size_t allocsz = LLT_ALIGN(sz, LANGUAGE_CACHE_BYTE_ALIGNMENT);
    if (allocsz < sz)  // overflow in adding offs, size was "negative"
        language_throw(language_memory_exception);

    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    void *b;
    if (isaligned)
        b = realloc_cache_align(d, allocsz, oldsz);
    else
        b = realloc(d, allocsz);
    if (b == NULL)
        language_throw(language_memory_exception);
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
    // gc_managed_realloc_ is currently used exclusively for resizing array buffers.
    if (is_old_marked) {
        ptls->gc_cache.perm_scanned_bytes += allocsz - oldsz;
        inc_live_bytes(allocsz - oldsz);
    }
    else if (!(allocsz < oldsz))
        language_atomic_store_relaxed(&ptls->gc_num.allocd,
            language_atomic_load_relaxed(&ptls->gc_num.allocd) + (allocsz - oldsz));
    language_atomic_store_relaxed(&ptls->gc_num.realloc,
        language_atomic_load_relaxed(&ptls->gc_num.realloc) + 1);

    int64_t diff = allocsz - oldsz;
    if (diff < 0) {
        language_batch_accum_free_size(ptls, -diff);
    }
    else {
        language_batch_accum_heap_size(ptls, diff);
    }
    if (allocsz > oldsz) {
        maybe_record_alloc_to_profile((language_value_t*)b, allocsz - oldsz, (language_datatype_t*)language_buff_tag);
    }
    return b;
}

LANGUAGE_DLLEXPORT void *language_gc_managed_realloc(void *d, size_t sz, size_t oldsz,
                                         int isaligned, language_value_t *owner)
{
    language_ptls_t ptls = language_current_task->ptls;
    return gc_managed_realloc_(ptls, d, sz, oldsz, isaligned, owner, 1);
}

language_value_t *language_gc_realloc_string(language_value_t *s, size_t sz)
{
    size_t len = language_string_len(s);
    if (sz <= len) return s;
    language_taggedvalue_t *v = language_astaggedvalue(s);
    size_t strsz = len + sizeof(size_t) + 1;
    if (strsz <= GC_MAX_SZCLASS ||
        // TODO: because of issue #17971 we can't resize old objects
        gc_marked(v->bits.gc)) {
        // pool allocated; can't be grown in place so allocate a new object.
        language_value_t *snew = language_alloc_string(sz);
        memcpy(language_string_data(snew), language_string_data(s), len);
        return snew;
    }
    size_t newsz = sz + sizeof(size_t) + 1;
    size_t offs = sizeof(bigval_t);
    size_t oldsz = LLT_ALIGN(strsz + offs, LANGUAGE_CACHE_BYTE_ALIGNMENT);
    size_t allocsz = LLT_ALIGN(newsz + offs, LANGUAGE_CACHE_BYTE_ALIGNMENT);
    if (allocsz < sz)  // overflow in adding offs, size was "negative"
        language_throw(language_memory_exception);
    bigval_t *hdr = bigval_header(v);
    language_ptls_t ptls = language_current_task->ptls;
    maybe_collect(ptls); // don't want this to happen during language_gc_managed_realloc
    gc_big_object_unlink(hdr);
    // TODO: this is not safe since it frees the old pointer. ideally we'd like
    // the old pointer to be left alone if we can't grow in place.
    // for now it's up to the caller to make sure there are no references to the
    // old pointer.
    bigval_t *newbig = (bigval_t*)gc_managed_realloc_(ptls, hdr, allocsz, oldsz, 1, s, 0);
    newbig->sz = allocsz;
    gc_big_object_link(newbig, &ptls->heap.big_objects);
    language_value_t *snew = language_valueof(&newbig->header);
    *(size_t*)snew = sz;
    return snew;
}

// Perm gen allocator
// 2M pool
#define GC_PERM_POOL_SIZE (2 * 1024 * 1024)
// 20k limit for pool allocation. At most 1% fragmentation
#define GC_PERM_POOL_LIMIT (20 * 1024)
uv_mutex_t gc_perm_lock;
static uintptr_t gc_perm_pool = 0;
static uintptr_t gc_perm_end = 0;

static void *gc_perm_alloc_large(size_t sz, int zero, unsigned align, unsigned offset) LANGUAGE_NOTSAFEPOINT
{
    // `align` must be power of two
    assert(offset == 0 || offset < align);
    const size_t malloc_align = sizeof(void*) == 8 ? 16 : 4;
    if (align > 1 && (offset != 0 || align > malloc_align))
        sz += align - 1;
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    void *base = zero ? calloc(1, sz) : malloc(sz);
    if (base == NULL)
        language_throw(language_memory_exception);
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    language_atomic_fetch_add_relaxed(&gc_heap_stats.heap_size,sz);
    errno = last_errno;
    language_may_leak(base);
    assert(align > 0);
    return (void*)(LLT_ALIGN((uintptr_t)base + offset, (uintptr_t)align) - offset);
}

STATIC_INLINE void *gc_try_perm_alloc_pool(size_t sz, unsigned align, unsigned offset) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t pool = LLT_ALIGN(gc_perm_pool + offset, (uintptr_t)align) - offset;
    uintptr_t end = pool + sz;
    if (end > gc_perm_end)
        return NULL;
    gc_perm_pool = end;
    return (void*)language_assume(pool);
}

// **NOT** a safepoint
void *language_gc_perm_alloc_nolock(size_t sz, int zero, unsigned align, unsigned offset)
{
    // The caller should have acquired `gc_perm_lock`
    assert(align < GC_PERM_POOL_LIMIT);
#ifndef MEMDEBUG
    if (__unlikely(sz > GC_PERM_POOL_LIMIT))
#endif
        return gc_perm_alloc_large(sz, zero, align, offset);
    void *ptr = gc_try_perm_alloc_pool(sz, align, offset);
    if (__likely(ptr))
        return ptr;
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
    void *pool = VirtualAlloc(NULL, GC_PERM_POOL_SIZE, MEM_COMMIT, PAGE_READWRITE);
    SetLastError(last_error);
    errno = last_errno;
    if (__unlikely(pool == NULL))
        return NULL;
#else
    void *pool = mmap(0, GC_PERM_POOL_SIZE, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    errno = last_errno;
    if (__unlikely(pool == MAP_FAILED))
        return NULL;
#endif
    gc_perm_pool = (uintptr_t)pool;
    gc_perm_end = gc_perm_pool + GC_PERM_POOL_SIZE;
    return gc_try_perm_alloc_pool(sz, align, offset);
}

// **NOT** a safepoint
void *language_gc_perm_alloc(size_t sz, int zero, unsigned align, unsigned offset)
{
    assert(align < GC_PERM_POOL_LIMIT);
#ifndef MEMDEBUG
    if (__unlikely(sz > GC_PERM_POOL_LIMIT))
#endif
        return gc_perm_alloc_large(sz, zero, align, offset);
    uv_mutex_lock(&gc_perm_lock);
    void *p = language_gc_perm_alloc_nolock(sz, zero, align, offset);
    uv_mutex_unlock(&gc_perm_lock);
    return p;
}

LANGUAGE_DLLEXPORT void language_gc_add_finalizer(language_value_t *v, language_function_t *f)
{
    language_ptls_t ptls = language_current_task->ptls;
    language_gc_add_finalizer_th(ptls, v, f);
}

LANGUAGE_DLLEXPORT void language_finalize(language_value_t *o)
{
    language_finalize_th(language_current_task, o);
}

LANGUAGE_DLLEXPORT language_weakref_t *language_gc_new_weakref(language_value_t *value)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_new_weakref_th(ptls, value);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_allocobj(size_t sz)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_alloc(ptls, sz, NULL);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_0w(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_alloc(ptls, 0, NULL);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_1w(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_alloc(ptls, sizeof(void*), NULL);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_2w(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_alloc(ptls, sizeof(void*) * 2, NULL);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_3w(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    return language_gc_alloc(ptls, sizeof(void*) * 3, NULL);
}

LANGUAGE_DLLEXPORT int language_gc_enable_conservative_gc_support(void)
{
    if (language_is_initialized()) {
        int result = language_atomic_fetch_or(&support_conservative_marking, 1);
        if (!result) {
            // Do a full collection to ensure that age bits are updated
            // properly. We don't have to worry about race conditions
            // for this part, as allocation itself is unproblematic and
            // a collection will wait for safepoints.
            language_gc_collect(LANGUAGE_GC_FULL);
        }
        return result;
    } else {
        int result = language_atomic_load(&support_conservative_marking);
        language_atomic_store(&support_conservative_marking, 1);
        return result;
    }
}

LANGUAGE_DLLEXPORT int language_gc_conservative_gc_support_enabled(void)
{
    return language_atomic_load(&support_conservative_marking);
}

LANGUAGE_DLLEXPORT language_value_t *language_gc_internal_obj_base_ptr(void *p)
{
    p = (char *) p - 1;
    language_gc_pagemeta_t *meta = page_metadata(p);
    if (meta != NULL) {
        char *page = gc_page_data(p);
        // offset within page.
        size_t off = (char *)p - page;
        if (off < GC_PAGE_OFFSET)
            return NULL;
        // offset within object
        size_t off2 = (off - GC_PAGE_OFFSET);
        size_t osize = meta->osize;
        if (osize == 0)
            return NULL;
        off2 %= osize;
        if (off - off2 + osize > GC_PAGE_SZ)
            return NULL;
        language_taggedvalue_t *cell = (language_taggedvalue_t *)((char *)p - off2);
        // We have to distinguish between three cases:
        // 1. We are on a page where every cell is allocated.
        // 2. We are on a page where objects are currently bump-allocated
        //    from the corresponding pool->newpages list.
        // 3. We are on a page with a freelist that is used for object
        //    allocation.
        if (meta->nfree == 0) {
            // case 1: full page; `cell` must be an object
            goto valid_object;
        }
        language_gc_pool_t *pool =
            gc_all_tls_states[meta->thread_n]->heap.norm_pools +
            meta->pool_n;
        if (meta->fl_begin_offset == UINT16_MAX) {
            // case 2: this is a page on the newpages list
            language_taggedvalue_t *newpages = pool->newpages;
            // Check if the page is being allocated from via newpages
            if (!newpages)
                return NULL;
            char *data = gc_page_data(newpages);
            if (data != meta->data) {
                // Pages on newpages form a linked list where only the
                // first one is allocated from (see gc_reset_page()).
                // All other pages are empty.
                return NULL;
            }
            // This is the first page on the newpages list, where objects
            // are allocated from.
            if ((char *)cell >= (char *)newpages) // past allocation pointer
                return NULL;
            goto valid_object;
        }
        // case 3: this is a page with a freelist
        // marked or old objects can't be on the freelist
        if (cell->bits.gc)
            goto valid_object;
        // When allocating from a freelist, three subcases are possible:
        // * The freelist of a page has been exhausted; this was handled
        //   under case 1, as nfree == 0.
        // * The freelist of the page has not been used, and the age bits
        //   reflect whether a cell is on the freelist or an object.
        // * The freelist is currently being allocated from. In this case,
        //   pool->freelist will point to the current page; any cell with
        //   a lower address will be an allocated object, and for cells
        //   with the same or a higher address, the corresponding age
        //   bit will reflect whether it's on the freelist.
        // Age bits are set in sweep_page() and are 0 for freelist
        // entries and 1 for live objects. The above subcases arise
        // because allocating a cell will not update the age bit, so we
        // need extra logic for pages that have been allocated from.
        // We now distinguish between the second and third subcase.
        // Freelist entries are consumed in ascending order. Anything
        // before the freelist pointer was either live during the last
        // sweep or has been allocated since.
        if (gc_page_data(cell) == gc_page_data(pool->freelist)
            && (char *)cell < (char *)pool->freelist)
            goto valid_object;
        // already skipped marked or old objects above, so here
        // the age bits are 0, thus the object is on the freelist
        return NULL;
        // Not a freelist entry, therefore a valid object.
    valid_object:
        // We have to treat objects with type `language_buff_tag` differently,
        // as they must not be passed to the usual marking functions.
        // Note that language_buff_tag is real pointer into libjulia,
        // thus it cannot be a type reference.
        if ((cell->header & ~(uintptr_t) 3) == language_buff_tag)
            return NULL;
        return language_valueof(cell);
    }
    return NULL;
}

LANGUAGE_DLLEXPORT size_t language_gc_max_internal_obj_size(void)
{
    return GC_MAX_SZCLASS;
}

LANGUAGE_DLLEXPORT size_t language_gc_external_obj_hdr_size(void)
{
    return sizeof(bigval_t);
}


LANGUAGE_DLLEXPORT void * language_gc_alloc_typed(language_ptls_t ptls, size_t sz, void *ty)
{
    return language_gc_alloc(ptls, sz, ty);
}

LANGUAGE_DLLEXPORT void language_gc_schedule_foreign_sweepfunc(language_ptls_t ptls, language_value_t *obj)
{
    arraylist_push(&ptls->sweep_objs, obj);
}

#ifdef __cplusplus
}
#endif
