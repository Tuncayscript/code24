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

#ifndef LANGUAGE_TIMING_H
#define LANGUAGE_TIMING_H

#include "code.h"

static inline const char *gnu_basename(const char *path)
{
    const char *base = strrchr(path, '/');
#ifdef _WIN32
    const char *backslash = strrchr(path, '\\');
    if (backslash > base)
        base = backslash;
#endif
    return base ? base+1 : path;
}

#ifdef USE_TRACY
typedef struct {
    _Atomic(int64_t) val;
    char* name;
} language_tracy_counter_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

void language_init_timing(void);
void language_destroy_timing(void) LANGUAGE_NOTSAFEPOINT;

// Update the enable bit-mask to enable/disable tracing events for
// the subsystem in `language_timing_subsystems` matching the provided string.
//
// Returns -1 if no matching sub-system was found.
LANGUAGE_DLLEXPORT int language_timing_set_enable(const char *subsystem, uint8_t enabled);

// Check for environment vars "JULIA_TIMING_METADATA_PRINT_LIMIT" and
// "JULIA_TIMING_SUBSYSTEMS" and if present apply these to the metadata
// print limit and the timings enable mask, respectively.
//
// For example, to enable INFERENCE and METHOD_MATCH and disable GC:
//     JULIA_TIMING_SUBSYSTEMS="+INFERENCE,-GC,+METHOD_MATCH"
//
// For example, to increase the metadata item print limit from 10 to 20:
//     JULIA_TIMING_METADATA_PRINT_LIMIT=20
void language_timing_apply_env(void);

// Configurable item limit, runtime code should use this to limit printing
// when adding potentially many items of metadata to a single timing zone.
extern LANGUAGE_DLLEXPORT uint32_t language_timing_print_limit;

LANGUAGE_DLLEXPORT language_timing_event_t *_language_timing_event_create(const char *subsystem, const char *name, const char *function, const char *file, int line, int color);
LANGUAGE_DLLEXPORT void _language_timing_block_init(char *buf, size_t size, language_timing_event_t *event);
LANGUAGE_DLLEXPORT void _language_timing_block_start(language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void _language_timing_block_end(language_timing_block_t *cur_block);

#ifdef __cplusplus
}
#endif

#if defined(_COMPILER_CLANG_)
#define HAVE_TIMING_SUPPORT
#elif defined(_COMPILER_GCC_)
#define HAVE_TIMING_SUPPORT
#endif

#if defined( USE_TRACY ) || defined( USE_ITTAPI ) || defined( USE_TIMING_COUNTS )
#define ENABLE_TIMINGS
#endif

#if !defined( ENABLE_TIMINGS ) || !defined( HAVE_TIMING_SUPPORT )

#define LANGUAGE_TIMING(subsystem, event)
#define LANGUAGE_TIMING_CREATE_BLOCK(new_block_name, subsystem, event)

#define LANGUAGE_TIMING_SUSPEND_TASK(subsystem, ct)

#define language_timing_show(v, b)
#define language_timing_show_module(m, b)
#define language_timing_show_filename(f, b)
#define language_timing_show_method_instance(mi, b)
#define language_timing_show_method(mi, b)
#define language_timing_show_func_sig(tt, b)
#define language_timing_show_location(file, line, mod, b)
#define language_timing_show_macro(macro, lno, mod, b)
#define language_timing_printf(b, f, ...)
#define language_timing_puts(b, s)
#define language_timing_task_init(t)
#define language_timing_event_create(blk)
#define language_timing_block_start(blk)
#define language_timing_block_task_enter(ct, ptls, blk)
#define language_timing_block_task_exit(ct, ptls) ((language_timing_block_t *)NULL)
#define language_timing_block_pop(blk)

#define language_timing_counter_inc(counter, value)
#define language_timing_counter_dec(counter, value)

#define language_profile_lock_init(lock, name)
#define language_profile_lock_start_wait(lock)
#define language_profile_lock_acquired(lock)
#define language_profile_lock_release_start(lock)
#define language_profile_lock_release_end(lock)

#else

#include "language_assert.h"
#ifdef USE_TRACY
#include "tracy/TracyC.h"
typedef struct ___tracy_source_location_data TracySrcLocData;
#endif

#ifdef USE_ITTAPI
#include <ittapi/ittnotify.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
void language_print_timings(void);

void language_timing_task_init(language_task_t *t);
void language_timing_block_task_enter(language_task_t *ct, language_ptls_t ptls, language_timing_block_t *prev_blk);
language_timing_block_t *language_timing_block_task_exit(language_task_t *ct, language_ptls_t ptls);
language_timing_block_t *language_timing_block_pop(language_timing_block_t *cur_block);

// Add the output of `language_static_show(x)` as a text annotation to the
// profiling region corresponding to `cur_block`.
//
// If larger than IOS_INLSIZE (~80 characters), text is truncated.
LANGUAGE_DLLEXPORT void language_timing_show(language_value_t *v, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_module(language_module_t *m, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_filename(const char *path, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_method_instance(language_method_instance_t *mi, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_method(language_method_t *method, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_func_sig(language_value_t *v, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_location(const char *file, int line, language_module_t* mod, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_show_macro(language_method_instance_t *macro, language_value_t* lno, language_module_t* mod, language_timing_block_t *cur_block);
LANGUAGE_DLLEXPORT void language_timing_printf(language_timing_block_t *cur_block, const char *format, ...);
LANGUAGE_DLLEXPORT void language_timing_puts(language_timing_block_t *cur_block, const char *str);

#define language_timing_event_create(subsystem, name, function, file, line, color) _language_timing_event_create(subsystem, name, function, file, line, color)
#define language_timing_block_start(blk) _language_timing_block_start(blk)
#define language_timing_block_end(blk) _language_timing_block_end(blk)

#ifdef __cplusplus
}
#endif

#define LANGUAGE_TIMING_DEFAULT_BLOCK (&__timing_block)

#define LANGUAGE_TIMING_SUBSYSTEMS     \
        X(ROOT)                  \
        X(GC)                    \
        X(LOWERING)              \
        X(PARSING)               \
        X(INFERENCE)             \
        X(CODEGEN)               \
        X(METHOD_LOOKUP_SLOW)    \
        X(METHOD_LOOKUP_FAST)    \
        X(CODEINST_COMPILE)      \
        X(LLVM_JIT)              \
        X(METHOD_MATCH)          \
        X(TYPE_CACHE_LOOKUP)     \
        X(TYPE_CACHE_INSERT)     \
        X(STAGED_FUNCTION)       \
        X(MACRO_INVOCATION)      \
        X(AST_COMPRESS)          \
        X(AST_UNCOMPRESS)        \
        X(SYSIMG_DUMP)           \
        X(NATIVE_AOT)            \
        X(ADD_METHOD)            \
        X(LOAD_MODULE)           \
        X(LOAD_IMAGE)            \
        X(VERIFY_IMAGE)          \
        X(VERIFY_IR)             \
        X(SAVE_MODULE)           \
        X(INIT_MODULE)           \
        X(LOCK_SPIN)             \
        X(STACKWALK)             \
        X(DL_OPEN)               \
        X(JULIA_INIT)            \


#define LANGUAGE_TIMING_COUNTERS \
        X(Invalidations) \
        X(HeapSize) \
        X(JITSize) \
        X(JITCodeSize) \
        X(JITDataSize) \
        X(ImageSize) \


enum language_timing_subsystem {
#define X(name) LANGUAGE_TIMING_ ## name,
    LANGUAGE_TIMING_SUBSYSTEMS
#undef X
    LANGUAGE_TIMING_SUBSYSTEM_LAST
};

enum language_timing_counter_types {
#define X(name) LANGUAGE_TIMING_COUNTER_ ## name,
    LANGUAGE_TIMING_COUNTERS
#undef X
    LANGUAGE_TIMING_COUNTER_LAST
};

#define TIMING_XCONCAT(x1, x2) x1##x2
#define TIMING_CONCAT(x1, x2) TIMING_XCONCAT(x1, x2)

/**
 * Timing Backend: Aggregated timing counts (implemented in timing.c)
 **/

typedef struct language_timing_counts_event_t {
    const char *name;
    _Atomic(uint64_t) self;
    _Atomic(uint64_t) total;
} language_timing_counts_event_t;

typedef struct _language_timing_counts_t {
    uint64_t total;
    uint64_t start;
    uint64_t t0;
#ifdef LANGUAGE_DEBUG_BUILD
    uint8_t running;
#endif
} language_timing_counts_t;

#ifdef USE_TIMING_COUNTS
#define _COUNTS_EVENT_MEMBER             language_timing_counts_event_t *counts_event;
#define _COUNTS_BLOCK_MEMBER             language_timing_counts_t counts_ctx;
#define _COUNTS_START(block, t)          _language_timing_counts_start(block, t)
#define _COUNTS_STOP(block, t)           _language_timing_counts_stop(block, t)
#define _COUNTS_PAUSE(block, t)          _language_timing_counts_pause(block, t)
#define _COUNTS_RESUME(block, t)         _language_timing_counts_resume(block, t)
#else
#define _COUNTS_EVENT_MEMBER
#define _COUNTS_BLOCK_MEMBER
#define _COUNTS_START(block, t)
#define _COUNTS_STOP(block, t)
#define _COUNTS_PAUSE(block, t)
#define _COUNTS_RESUME(block, t)
#endif

/**
 * Timing Backend: Tracy
 **/

#ifdef USE_TRACY
#define _TRACY_EVENT_MEMBER              TracySrcLocData tracy_srcloc;
#define _TRACY_BLOCK_MEMBER              TracyCZoneCtx tracy_ctx;
#define _TRACY_START(block)              (block)->tracy_ctx = ___tracy_emit_zone_begin( &(block)->event->tracy_srcloc, 1 );
#define _TRACY_STOP(ctx)                 TracyCZoneEnd(ctx)
#else
#define _TRACY_EVENT_MEMBER
#define _TRACY_BLOCK_MEMBER
#define _TRACY_START(block)
#define _TRACY_STOP(ctx)
#endif

/**
 * Timing Backend: Intel VTune (ITTAPI)
 **/

#ifdef USE_ITTAPI
#define _ITTAPI_EVENT_MEMBER              __itt_event ittapi_event;
#define _ITTAPI_BLOCK_MEMBER
#define _ITTAPI_START(block)              __itt_event_start((block)->event->ittapi_event)
#define _ITTAPI_STOP(block)               __itt_event_end((block)->event->ittapi_event)
#else
#define _ITTAPI_EVENT_MEMBER
#define _ITTAPI_BLOCK_MEMBER
#define _ITTAPI_START(block)
#define _ITTAPI_STOP(block)
#endif

/**
 * Top-level language_timing implementation
 **/

extern LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_timing_disable_mask[(LANGUAGE_TIMING_SUBSYSTEM_LAST + sizeof(uint64_t) * CHAR_BIT - 1) / (sizeof(uint64_t) * CHAR_BIT)];
extern const char *language_timing_subsystems[(int)LANGUAGE_TIMING_SUBSYSTEM_LAST];

/**
 * Stores all static attributes associated with a profiling event.
 *
 * A single event can be used to create many timing blocks with
 * the same name/source information.
 **/
struct _language_timing_event_t { // typedef in code.h
    _TRACY_EVENT_MEMBER
    _ITTAPI_EVENT_MEMBER
    _COUNTS_EVENT_MEMBER

    int subsystem;
};

/**
 * Stores all dynamic attributes associated with a timing block.
 *
 * Every time the application enters an instrumented block of code,
 * a new timing block is created. A timing block corresponds to one
 * "span" of time in the profiler.
 **/
struct _language_timing_block_t { // typedef in code.h
    struct _language_timing_block_t *prev;
    language_timing_event_t *event;

    _TRACY_BLOCK_MEMBER
    _ITTAPI_BLOCK_MEMBER
    _COUNTS_BLOCK_MEMBER

    uint8_t is_running;
};

STATIC_INLINE int _language_timing_enabled(int subsystem) LANGUAGE_NOTSAFEPOINT {
    return (language_atomic_load_relaxed(language_timing_disable_mask + subsystem / (sizeof(uint64_t) * CHAR_BIT)) & (1 << (subsystem % (sizeof(uint64_t) * CHAR_BIT)))) == 0;
}

typedef struct _language_timing_suspend_t {
    language_task_t *ct;
} language_timing_suspend_t;

STATIC_INLINE void _language_timing_suspend_ctor(language_timing_suspend_t *suspend, const char *subsystem, language_task_t *ct) LANGUAGE_NOTSAFEPOINT {
    suspend->ct = ct;
#ifdef USE_TRACY
    TracyCFiberEnter(subsystem);
#endif
}

STATIC_INLINE void _language_timing_suspend_destroy(language_timing_suspend_t *suspend) LANGUAGE_NOTSAFEPOINT {
#ifdef USE_TRACY
    TracyCFiberEnter(suspend->ct->name);
#endif
}

#define LANGUAGE_TIMING(subsystem, event)                                           \
    LANGUAGE_TIMING_CREATE_BLOCK(__timing_block, subsystem, event);                 \
    language_timing_block_start(&__timing_block)

#define LANGUAGE_TIMING_CREATE_BLOCK(block, subsystem_name, event_name)             \
    static language_timing_event_t *TIMING_CONCAT(__timing_event, __LINE__) = 0;    \
    if (!TIMING_CONCAT(__timing_event, __LINE__))                             \
        TIMING_CONCAT(__timing_event, __LINE__) = language_timing_event_create(     \
            #subsystem_name, #event_name, __func__, __FILE__, __LINE__, 0     \
        );                                                                    \
    __attribute__((cleanup(_language_timing_block_end)))                            \
    language_timing_block_t block = { 0 };                                          \
    block.event = TIMING_CONCAT(__timing_event, __LINE__)

#define LANGUAGE_TIMING_SUSPEND_TASK(subsystem, ct) \
    __attribute__((cleanup(_language_timing_suspend_destroy))) \
    language_timing_suspend_t __timing_suspend; \
    _language_timing_suspend_ctor(&__timing_suspend, #subsystem, ct)

// Counting
#ifdef USE_ITTAPI
#define _ITTAPI_COUNTER_MEMBER __itt_counter ittapi_counter;
#else
#define _ITTAPI_COUNTER_MEMBER
#endif

#ifdef USE_TRACY
# define _TRACY_COUNTER_MEMBER language_tracy_counter_t tracy_counter;
# else
# define _TRACY_COUNTER_MEMBER
#endif

#ifdef USE_TIMING_COUNTS
#define _COUNTS_MEMBER _Atomic(uint64_t) basic_counter;
#else
#define _COUNTS_MEMBER
#endif

typedef struct {
    _ITTAPI_COUNTER_MEMBER
    _TRACY_COUNTER_MEMBER
    _COUNTS_MEMBER
} language_timing_counter_t;

LANGUAGE_DLLEXPORT extern language_timing_counter_t language_timing_counters[LANGUAGE_TIMING_COUNTER_LAST];

static inline void language_timing_counter_inc(int counter, uint64_t val) LANGUAGE_NOTSAFEPOINT {
#ifdef USE_ITTAPI
    __itt_counter_inc_delta(language_timing_counters[counter].ittapi_counter, val);
#endif
#ifdef USE_TRACY
    language_tracy_counter_t *tracy_counter = &language_timing_counters[counter].tracy_counter;
    uint64_t oldval = language_atomic_fetch_add_relaxed(&tracy_counter->val, val);
    TracyCPlotI(tracy_counter->name, oldval + val);
#endif
#ifdef USE_TIMING_COUNTS
    language_atomic_fetch_add_relaxed(&language_timing_counters[counter].basic_counter, val);
#endif
}

static inline void language_timing_counter_dec(int counter, uint64_t val) LANGUAGE_NOTSAFEPOINT {
#ifdef USE_ITTAPI
    __itt_counter_dec_delta(language_timing_counters[counter].ittapi_counter, val);
#endif
#ifdef USE_TRACY
    language_tracy_counter_t *tracy_counter = &language_timing_counters[counter].tracy_counter;
    uint64_t oldval = language_atomic_fetch_add_relaxed(&tracy_counter->val, -val);
    TracyCPlotI(tracy_counter->name, oldval - val);
#endif
#ifdef USE_TIMING_COUNTS
    language_atomic_fetch_add_relaxed(&language_timing_counters[counter].basic_counter, -(int64_t)val);
#endif
}

// Locking profiling
static inline void language_profile_lock_init(language_mutex_t *lock, const char *name) {
#ifdef USE_ITTAPI
    __itt_sync_create(lock, "language_mutex_t", name, __itt_attr_mutex);
#endif
}
static inline void language_profile_lock_start_wait(language_mutex_t *lock) {
#ifdef USE_ITTAPI
    __itt_sync_prepare(lock);
#endif
}
static inline void language_profile_lock_acquired(language_mutex_t *lock) {
#ifdef USE_ITTAPI
    __itt_sync_acquired(lock);
#endif
}
static inline void language_profile_lock_release_start(language_mutex_t *lock) {
#ifdef USE_ITTAPI
    __itt_sync_releasing(lock);
#endif
}
static inline void language_profile_lock_release_end(language_mutex_t *lock) {}

#endif

#endif
