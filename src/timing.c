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

#include <inttypes.h>
#include "code.h"
#include "language_internal.h"
#include "options.h"
#include "stdio.h"

#if defined(USE_TRACY) || defined(USE_ITTAPI)
#define DISABLE_FREQUENT_EVENTS
#endif

language_module_t *language_module_root(language_module_t *m);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ENABLE_TIMINGS

#ifndef HAVE_TIMING_SUPPORT
#error Timings are not supported on your compiler
#endif

static uint64_t t0;

LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_timing_disable_mask[(LANGUAGE_TIMING_SUBSYSTEM_LAST + sizeof(uint64_t) * CHAR_BIT - 1) / (sizeof(uint64_t) * CHAR_BIT)];

// Used to as an item limit when several strings of metadata can
// potentially be associated with a single timing zone.
LANGUAGE_DLLEXPORT uint32_t language_timing_print_limit = 10;

const char *language_timing_subsystems[(int)LANGUAGE_TIMING_SUBSYSTEM_LAST] =
    {
#define X(name) #name,
        LANGUAGE_TIMING_SUBSYSTEMS
#undef X
    };

LANGUAGE_DLLEXPORT language_timing_counter_t language_timing_counters[LANGUAGE_TIMING_COUNTER_LAST];

#ifdef USE_TIMING_COUNTS
static arraylist_t language_timing_counts_events;
static language_mutex_t language_timing_counts_events_lock;
#endif //USE_TIMING_COUNTS

#ifdef USE_ITTAPI
static arraylist_t language_timing_ittapi_events;
static language_mutex_t language_timing_ittapi_events_lock;
#endif //USE_ITTAPI

#ifdef USE_TIMING_COUNTS
static int cmp_counts_events(const void *a, const void *b) {
    language_timing_counts_event_t *event_a = *(language_timing_counts_event_t **)a;
    language_timing_counts_event_t *event_b = *(language_timing_counts_event_t **)b;
    return strcmp(event_a->name, event_b->name);
}
#endif

void language_print_timings(void)
{
#ifdef USE_TIMING_COUNTS
    qsort(language_timing_counts_events.items, language_timing_counts_events.len,
          sizeof(language_timing_counts_event_t *), cmp_counts_events);

    LANGUAGE_LOCK_NOGC(&language_timing_counts_events_lock);
    uint64_t total_time = cycleclock() - t0;
    uint64_t root_time = total_time;
    language_timing_counts_event_t *root_event;
    for (int i = 0; i < language_timing_counts_events.len; i++) {
        language_timing_counts_event_t *other_event = (language_timing_counts_event_t *)language_timing_counts_events.items[i];
        if (strcmp(other_event->name, "ROOT") == 0) {
            root_event = other_event;
        } else {
            root_time -= language_atomic_load_relaxed(&other_event->self);
        }
    }
    language_atomic_store_relaxed(&root_event->self, root_time);
    language_atomic_store_relaxed(&root_event->total, total_time);

    fprintf(stderr, "\nJULIA TIMINGS\n");
    fprintf(stderr, "%-25s, %-30s, %-30s\n", "Event", "Self Cycles (% of Total)", "Total Cycles (% of Total)");
    for (int i = 0; i < language_timing_counts_events.len; i++) {
        language_timing_counts_event_t *event = (language_timing_counts_event_t *)language_timing_counts_events.items[i];
        uint64_t self = language_atomic_load_relaxed(&event->self);
        uint64_t total = language_atomic_load_relaxed(&event->total);
        if (total != 0)
            fprintf(stderr, "%-25s, %20" PRIu64 " (%5.2f %%), %20" PRIu64 " (%5.2f %%)\n",
                    event->name,
                    self, 100 * (((double)self) / total_time),
                    total, 100 * (((double)total) / total_time));
    }
    LANGUAGE_UNLOCK_NOGC(&language_timing_counts_events_lock);

    fprintf(stderr, "\nJULIA COUNTERS\n");
    fprintf(stderr, "%-25s, %-20s\n", "Counter", "Value");
#define X(name) do { \
        int64_t val = (int64_t) language_atomic_load_relaxed(&language_timing_counters[(int)LANGUAGE_TIMING_COUNTER_##name].basic_counter); \
        if (val != 0) \
            fprintf(stderr, "%-25s, %20" PRIi64 "\n", #name, val); \
    } while (0);

    LANGUAGE_TIMING_COUNTERS
#undef X
#endif
}

static int indirect_strcmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void language_init_timing(void)
{
    t0 = cycleclock();

    _Static_assert(LANGUAGE_TIMING_SUBSYSTEM_LAST < sizeof(uint64_t) * CHAR_BIT, "Too many timing subsystems!");

#ifdef USE_TIMING_COUNTS
    LANGUAGE_MUTEX_INIT(&language_timing_counts_events_lock, "language_timing_counts_events_lock");

    // Create events list for counts backend
    arraylist_new(&language_timing_counts_events, 1);

    language_timing_counts_event_t *root_event = (language_timing_counts_event_t *)malloc(sizeof(language_timing_counts_event_t));
    arraylist_push(&language_timing_counts_events, (void *)root_event);

    root_event->name = "ROOT";
    language_atomic_store_relaxed(&root_event->self, 0);
    language_atomic_store_relaxed(&root_event->total, 0);
#endif

#ifdef USE_ITTAPI
    // Create events list for ITTAPI backend
    LANGUAGE_MUTEX_INIT(&language_timing_ittapi_events_lock, "language_timing_ittapi_events_lock");
    arraylist_new(&language_timing_ittapi_events, 0);
#endif

    // Sort the subsystem names for quick enable/disable lookups
    qsort(language_timing_subsystems, LANGUAGE_TIMING_SUBSYSTEM_LAST,
          sizeof(const char *), indirect_strcmp);

    int i __attribute__((unused)) = 0;
#ifdef USE_ITTAPI
    i = 0;
#define X(name) language_timing_counters[i++].ittapi_counter = __itt_counter_create(#name, "julia.runtime");
    LANGUAGE_TIMING_COUNTERS
#undef X
#endif
#ifdef USE_TRACY
    i = 0;
#define X(counter_name) language_timing_counters[i].tracy_counter = (language_tracy_counter_t){0, #counter_name}; \
        TracyCPlotConfig(language_timing_counters[i++].tracy_counter.name, TracyPlotFormatNumber, /* rectilinear */ 1, /* fill */ 1, /* color */ 0);
    LANGUAGE_TIMING_COUNTERS
#undef X
    // We reference these by enum indexing and then asking for the name, since that allows the compiler
    // to catch name mismatches.
    TracyCPlotConfig(language_timing_counters[LANGUAGE_TIMING_COUNTER_HeapSize].tracy_counter.name, TracyPlotFormatMemory, /* rectilinear */ 0, /* fill */ 1, /* color */ 0);
    TracyCPlotConfig(language_timing_counters[LANGUAGE_TIMING_COUNTER_JITSize].tracy_counter.name, TracyPlotFormatMemory, /* rectilinear */ 0, /* fill */ 1, /* color */ 0);
    TracyCPlotConfig(language_timing_counters[LANGUAGE_TIMING_COUNTER_JITCodeSize].tracy_counter.name, TracyPlotFormatMemory, /* rectilinear */ 0, /* fill */ 1, /* color */ 0);
    TracyCPlotConfig(language_timing_counters[LANGUAGE_TIMING_COUNTER_JITDataSize].tracy_counter.name, TracyPlotFormatMemory, /* rectilinear */ 0, /* fill */ 1, /* color */ 0);
    TracyCPlotConfig(language_timing_counters[LANGUAGE_TIMING_COUNTER_ImageSize].tracy_counter.name, TracyPlotFormatMemory, /* rectilinear */ 0, /* fill */ 1, /* color */ 0);
#endif

/**
 * These sources often generate millions of events / minute. Although Tracy
 * can generally keep up with that, those events also bloat the saved ".tracy"
 * files, so we disable them by default.
 **/
#ifdef DISABLE_FREQUENT_EVENTS
    uint8_t error = 0;
    error |= language_timing_set_enable("ROOT", 0);
    error |= language_timing_set_enable("TYPE_CACHE_LOOKUP", 0);
    error |= language_timing_set_enable("METHOD_MATCH", 0);
    error |= language_timing_set_enable("METHOD_LOOKUP_FAST", 0);
    error |= language_timing_set_enable("AST_COMPRESS", 0);
    error |= language_timing_set_enable("AST_UNCOMPRESS", 0);
    if (error)
        language_error("invalid timing subsystem encountered in language_init_timing");
#endif

    // Apply e.g. JULIA_TIMING_SUBSYSTEMS="+GC,-INFERENCE" and
    //            JULIA_TIMING_METADATA_PRINT_LIMIT=20
    language_timing_apply_env();
}

void language_destroy_timing(void)
{
    language_ptls_t ptls = language_current_task->ptls;
    language_timing_block_t *stack = ptls->timing_stack;
    while (stack) {
        language_timing_block_end(stack);
        stack = stack->prev;
    }
}

static const int get_timing_subsystem(const char *subsystem) {
    const char **match = (const char **)bsearch(
        &subsystem, language_timing_subsystems, LANGUAGE_TIMING_SUBSYSTEM_LAST,
        sizeof(const char *), indirect_strcmp
    );
    if (!match)
        return LANGUAGE_TIMING_SUBSYSTEM_LAST;

    return (int)(match - &language_timing_subsystems[0]);
}

#ifdef USE_ITTAPI

typedef struct {
    __itt_event event;
    const char *name;
} cached_ittapi_event_t;

static __itt_event _language_timing_ittapi_event_create(const char *event) {
    LANGUAGE_LOCK_NOGC(&language_timing_ittapi_events_lock);
    const size_t n = language_timing_ittapi_events.len;
    for (size_t i = 0; i < n; i++) {
        cached_ittapi_event_t *other_event = (cached_ittapi_event_t *)language_timing_ittapi_events.items[i];
        if (strcmp(event, other_event->name) == 0) {
            LANGUAGE_UNLOCK_NOGC(&language_timing_ittapi_events_lock);
            return other_event->event;
        }
    }

    // No matching event found - create a new one
    cached_ittapi_event_t *new_event = (cached_ittapi_event_t *)malloc(sizeof(cached_ittapi_event_t));
    arraylist_push(&language_timing_ittapi_events, (void *)new_event);
    new_event->name = event;
    new_event->event = __itt_event_create(event, strlen(event));
    LANGUAGE_UNLOCK_NOGC(&language_timing_ittapi_events_lock);

    return new_event->event;
}

#endif // USE_ITTAPI

#ifdef USE_TIMING_COUNTS

// This function is analogous to __itt_event_create but for the counts backend
//
// `event` is required to live forever
static language_timing_counts_event_t *_language_timing_counts_event_create(const char *event) {
    LANGUAGE_LOCK_NOGC(&language_timing_counts_events_lock);
    const size_t n = language_timing_counts_events.len;
    for (size_t i = 0; i < n; i++) {
        language_timing_counts_event_t *other_event = (language_timing_counts_event_t *)language_timing_counts_events.items[i];
        if (strcmp(event, other_event->name) == 0) {
            LANGUAGE_UNLOCK_NOGC(&language_timing_counts_events_lock);
            return other_event;
        }
    }

    // No matching event found - create a new one
    language_timing_counts_event_t *new_event = (language_timing_counts_event_t *)malloc(sizeof(language_timing_counts_event_t));
    arraylist_push(&language_timing_counts_events, (void *)new_event);
    new_event->name = event;
    language_atomic_store_relaxed(&new_event->self, 0);
    language_atomic_store_relaxed(&new_event->total, 0);
    LANGUAGE_UNLOCK_NOGC(&language_timing_counts_events_lock);

    return new_event;
}

STATIC_INLINE void _language_timing_counts_pause(language_timing_counts_t *block, uint64_t t) LANGUAGE_NOTSAFEPOINT {
#ifdef LANGUAGE_DEBUG_BUILD
    assert(block->running);
    block->running = 0;
#endif
    block->total += t - block->start;
}

STATIC_INLINE void _language_timing_counts_resume(language_timing_counts_t *block, uint64_t t) LANGUAGE_NOTSAFEPOINT {
#ifdef LANGUAGE_DEBUG_BUILD
    assert(!block->running);
    block->running = 1;
#endif
    block->start = t;
}

STATIC_INLINE void _language_timing_counts_start(language_timing_counts_t *block, uint64_t t) LANGUAGE_NOTSAFEPOINT {
    block->total = 0;
    block->start = t;
    block->t0 = t;
#ifdef LANGUAGE_DEBUG_BUILD
    block->running = 1;
#endif
}

STATIC_INLINE void _language_timing_counts_stop(language_timing_block_t *block, uint64_t t) LANGUAGE_NOTSAFEPOINT {
#ifdef LANGUAGE_DEBUG_BUILD
    assert(block->counts_ctx.running);
    block->counts_ctx.running = 0;
#endif
    language_timing_counts_event_t *event = block->event->counts_event;
    block->counts_ctx.total += t - block->counts_ctx.start;
    language_atomic_fetch_add_relaxed(&event->self, block->counts_ctx.total);
    language_atomic_fetch_add_relaxed(&event->total, t - block->counts_ctx.t0);
}

#endif // USE_TIMING_COUNTS

LANGUAGE_DLLEXPORT language_timing_event_t *_language_timing_event_create(const char *subsystem, const char *name, const char *function, const char *file, int line, int color) {
    int maybe_subsystem = get_timing_subsystem(subsystem);
    if (maybe_subsystem >= LANGUAGE_TIMING_SUBSYSTEM_LAST) {
        language_errorf("invalid timing subsystem name: %s", subsystem);
        return NULL;
    }

    language_timing_event_t *event = (language_timing_event_t *) malloc(sizeof(language_timing_event_t));
    event->subsystem = maybe_subsystem;

#ifdef USE_TIMING_COUNTS
    event->counts_event = _language_timing_counts_event_create(name);
#endif // USE_TIMING_COUNTS

#ifdef USE_ITTAPI
    event->ittapi_event = _language_timing_ittapi_event_create(name);
#endif // USE_ITTAPI

#ifdef USE_TRACY
    event->tracy_srcloc.name = name;
    event->tracy_srcloc.function = function;
    event->tracy_srcloc.file = file;
    event->tracy_srcloc.line = line;
    event->tracy_srcloc.color = color;
#endif // USE_TRACY

    return event;
}

LANGUAGE_DLLEXPORT void _language_timing_block_init(char *buf, size_t size, language_timing_event_t *event) {
    if (size < sizeof(language_timing_block_t)) {
        language_errorf("language_timing_block_t buffer must be at least %d bytes", sizeof(language_timing_block_t));
        return;
    }

    language_timing_block_t *block = (language_timing_block_t *)buf;
    memset(block, 0, sizeof(language_timing_block_t));
    block->event = event;
}

LANGUAGE_DLLEXPORT void _language_timing_block_start(language_timing_block_t *block) {
    assert(!block->is_running);
    if (!_language_timing_enabled(block->event->subsystem)) return;
    if (language_get_pgcstack() == NULL) return; // not setup on this thread

    uint64_t t = cycleclock(); (void)t;
    _COUNTS_START(&block->counts_ctx, t);
    _ITTAPI_START(block);
    _TRACY_START(block);

    language_timing_block_t **prevp = &language_current_task->ptls->timing_stack;
    block->prev = *prevp;
    block->is_running = 1;
    if (block->prev) {
        _COUNTS_PAUSE(&block->prev->counts_ctx, t);
    }
    *prevp = block;
}

LANGUAGE_DLLEXPORT void _language_timing_block_end(language_timing_block_t *block) {
    if (block->is_running) {
        uint64_t t = cycleclock(); (void)t;
        _ITTAPI_STOP(block);
        _TRACY_STOP(block->tracy_ctx);
        _COUNTS_STOP(block, t);

        language_task_t *ct = language_current_task;
        language_timing_block_t **pcur = &ct->ptls->timing_stack;
        assert(*pcur == block);
        *pcur = block->prev;
        if (block->prev) {
            _COUNTS_RESUME(&block->prev->counts_ctx, t);
        }
    }
}

language_timing_block_t *language_timing_block_pop(language_timing_block_t *cur_block)
{
    language_timing_block_end(cur_block);
    return cur_block->prev;
}

void language_timing_block_task_enter(language_task_t *ct, language_ptls_t ptls, language_timing_block_t *prev_blk)
{
    if (prev_blk != NULL) {
        assert(ptls->timing_stack == NULL);

        ptls->timing_stack = prev_blk;
        if (prev_blk != NULL) {
            _COUNTS_RESUME(&prev_blk->counts_ctx, cycleclock());
        }
    }

#ifdef USE_TRACY
    TracyCFiberEnter(ct->name);
#else
    (void)ct;
#endif
}

language_timing_block_t *language_timing_block_task_exit(language_task_t *ct, language_ptls_t ptls)
{
#ifdef USE_TRACY
    // Tracy is fairly strict about not leaving a fiber that hasn't
    // been entered, which happens often when connecting to a running
    // Julia session.
    //
    // Eventually, Tracy will support telling the server which fibers
    // are active upon connection, but until then we work around the
    // problem by not explicitly leaving the fiber at all.
    //
    // Later when we enter the new fiber directly, that will cause the
    // the active fiber to be left implicitly.

    //TracyCFiberLeave;
#endif
    (void)ct;

    language_timing_block_t *blk = ptls->timing_stack;
    ptls->timing_stack = NULL;

    if (blk != NULL) {
        _COUNTS_PAUSE(&blk->counts_ctx, cycleclock());
    }
    return blk;
}

LANGUAGE_DLLEXPORT void language_timing_show(language_value_t *v, language_timing_block_t *cur_block)
{
#ifdef USE_TRACY
    ios_t buf;
    ios_mem(&buf, IOS_INLSIZE);
    buf.growable = 0; // Restrict to inline buffer to avoid allocation

    language_static_show((LANGUAGE_STREAM*)&buf, v);
    if (buf.size == buf.maxsize)
        memset(&buf.buf[IOS_INLSIZE - 3], '.', 3);

    TracyCZoneText(cur_block->tracy_ctx, buf.buf, buf.size);
#endif
}

LANGUAGE_DLLEXPORT void language_timing_show_module(language_module_t *m, language_timing_block_t *cur_block)
{
#ifdef USE_TRACY
    language_module_t *root = language_module_root(m);
    if (root == m || root == language_main_module) {
        const char *module_name = language_symbol_name(m->name);
        TracyCZoneText(cur_block->tracy_ctx, module_name, strlen(module_name));
    } else {
        language_timing_printf(cur_block, "%s.%s", language_symbol_name(root->name), language_symbol_name(m->name));
    }
#endif
}

LANGUAGE_DLLEXPORT void language_timing_show_filename(const char *path, language_timing_block_t *cur_block)
{
#ifdef USE_TRACY
    const char *filename = gnu_basename(path);
    TracyCZoneText(cur_block->tracy_ctx, filename, strlen(filename));
#endif
}

LANGUAGE_DLLEXPORT void language_timing_show_location(const char *file, int line, language_module_t* mod, language_timing_block_t *cur_block)
{
#ifdef USE_TRACY
    language_module_t *root = language_module_root(mod);
    if (root == mod || root == language_main_module) {
        language_timing_printf(cur_block, "%s:%d in %s",
                         gnu_basename(file),
                         line,
                         language_symbol_name(mod->name));
    } else {
        // TODO: generalize to print the entire module hierarchy
        language_timing_printf(cur_block, "%s:%d in %s.%s",
                         gnu_basename(file),
                         line,
                         language_symbol_name(root->name),
                         language_symbol_name(mod->name));
    }
#endif
}

LANGUAGE_DLLEXPORT void language_timing_show_method_instance(language_method_instance_t *mi, language_timing_block_t *cur_block)
{
    language_timing_show_func_sig(mi->specTypes, cur_block);
    if (language_is_method(mi->def.value)) {
        language_method_t *def = mi->def.method;
        language_timing_show_location(language_symbol_name(def->file), def->line, def->module, cur_block);
    } else {
        language_timing_printf(cur_block, "<top-level thunk> in %s",
                         language_symbol_name(mi->def.module->name));
    }
}

LANGUAGE_DLLEXPORT void language_timing_show_method(language_method_t *method, language_timing_block_t *cur_block)
{
    language_timing_show((language_value_t *)method, cur_block);
    language_timing_show_location(language_symbol_name(method->file), method->line, method->module, cur_block);
}

LANGUAGE_DLLEXPORT void language_timing_show_func_sig(language_value_t *v, language_timing_block_t *cur_block)
{
#ifdef USE_TRACY
    ios_t buf;
    ios_mem(&buf, IOS_INLSIZE);
    buf.growable = 0; // Restrict to inline buffer to avoid allocation

    language_static_show_config_t config = { /* quiet */ 1 };
    language_static_show_func_sig_((LANGUAGE_STREAM*)&buf, v, config);
    if (buf.size == buf.maxsize)
        memset(&buf.buf[IOS_INLSIZE - 3], '.', 3);

    TracyCZoneText(cur_block->tracy_ctx, buf.buf, buf.size);
#endif
}

LANGUAGE_DLLEXPORT void language_timing_show_macro(language_method_instance_t *macro, language_value_t* lno, language_module_t* mod, language_timing_block_t *cur_block)
{
    language_timing_printf(cur_block, "%s", language_symbol_name(macro->def.method->name));
    assert(language_typetagis(lno, language_linenumbernode_type));
    language_timing_show_location(language_symbol_name((language_sym_t*)language_fieldref(lno, 1)),
                            language_unbox_int64(language_fieldref(lno, 0)),
                            mod, cur_block);
}

LANGUAGE_DLLEXPORT void language_timing_printf(language_timing_block_t *cur_block, const char *format, ...)
{
    va_list args;
    va_start(args, format);

#ifdef USE_TRACY
    ios_t buf;
    ios_mem(&buf, IOS_INLSIZE);
    buf.growable = 0; // Restrict to inline buffer to avoid allocation

    language_vprintf((LANGUAGE_STREAM*)&buf, format, args);
    if (buf.size == buf.maxsize)
        memset(&buf.buf[IOS_INLSIZE - 3], '.', 3);

    TracyCZoneText(cur_block->tracy_ctx, buf.buf, buf.size);
#endif
    va_end(args);
}

LANGUAGE_DLLEXPORT void language_timing_puts(language_timing_block_t *cur_block, const char *str)
{
#ifdef USE_TRACY
    TracyCZoneText(cur_block->tracy_ctx, str, strlen(str));
#endif
}

void language_timing_task_init(language_task_t *t)
{
#ifdef USE_TRACY
    language_value_t *start_type = language_typeof(t->start);
    const char *start_name = "";
    if (language_is_datatype(start_type))
        start_name = language_symbol_name(((language_datatype_t *) start_type)->name->name);

    static uint16_t task_id = 1;

    // XXX: Tracy uses this as a handle internally and requires that this
    // string live forever, so this allocation is intentionally leaked.
    char *fiber_name;
    if (start_name[0] == '#') {
        language_method_instance_t *mi = language_method_lookup(&t->start, 1, language_get_world_counter());
        const char *filename = gnu_basename(language_symbol_name(mi->def.method->file));
        const char *module_name = language_symbol_name(mi->def.method->module->name);

        // 26 characters in "Task 65535 (:0000000 in )\0"
        size_t fiber_name_len = strlen(filename) + strlen(module_name) + 26;
        fiber_name = (char *)malloc(fiber_name_len);
        snprintf(fiber_name, fiber_name_len,  "Task %d (%s:%d in %s)",
                 task_id++, filename, mi->def.method->line, module_name);
    } else {

        // 16 characters in "Task 65535 (\"\")\0"
        size_t fiber_name_len = strlen(start_name) + 16;
        fiber_name = (char *)malloc(fiber_name_len);
        snprintf(fiber_name, fiber_name_len,  "Task %d (\"%s\")",
                 task_id++, start_name);
    }

    t->name = fiber_name;
#endif
}

LANGUAGE_DLLEXPORT int language_timing_set_enable(const char *subsystem, uint8_t enabled)
{
    int i = get_timing_subsystem(subsystem);
    if (i >= LANGUAGE_TIMING_SUBSYSTEM_LAST)
        return -1;

    uint64_t subsystem_bit = 1ul << (i % (sizeof(uint64_t) * CHAR_BIT));
    if (enabled) {
        language_atomic_fetch_and_relaxed(language_timing_disable_mask + (i / (sizeof(uint64_t) * CHAR_BIT)), ~subsystem_bit);
    } else {
        language_atomic_fetch_or_relaxed(language_timing_disable_mask + (i / (sizeof(uint64_t) * CHAR_BIT)), subsystem_bit);
    }
    return 0;
}

static void language_timing_set_enable_from_env(void)
{
    const char *env = getenv("JULIA_TIMING_SUBSYSTEMS");
    if (!env)
        return;

    // Copy `env`, so that we can modify it
    size_t sz = strlen(env) + 1;
    char *env_copy = (char *)malloc(sz);
    memcpy(env_copy, env, sz);

    char *subsystem = env_copy;
    char *ch = subsystem;
    uint8_t enable = 1;
    while (1) {
        // +SUBSYSTEM means enable, -SUBSYSTEM means disable
        if (*subsystem == '+' || *subsystem == '-')
            enable = (*subsystem++ == '+');

        if (*ch == ',') {
            *ch++ = '\0';
            if ((*subsystem != '\0') && language_timing_set_enable(subsystem, enable))
                fprintf(stderr, "warning: unable to configure timing for non-existent subsystem \"%s\"\n", subsystem);

            subsystem = ch;
            enable = 1;
        }
        else if (*ch == '\0') {
            if ((*subsystem != '\0') && language_timing_set_enable(subsystem, enable))
                fprintf(stderr, "warning: unable to configure timing for non-existent subsystem \"%s\"\n", subsystem);

            break;
        }
        else ch++;
    }
    free(env_copy);
}

static void language_timing_set_print_limit_from_env(void)
{
    const char *const env = getenv("JULIA_TIMING_METADATA_PRINT_LIMIT");
    if (!env)
        return;

    char *endp;
    long value = strtol(env, &endp, 10);
    if (*endp == '\0' && value >= 0 && value <= UINT32_MAX)
        language_timing_print_limit = (uint32_t)value;
}

void language_timing_apply_env(void)
{
    // JULIA_TIMING_SUBSYSTEMS
    language_timing_set_enable_from_env();

    // JULIA_TIMING_METADATA_PRINT_LIMIT
    language_timing_set_print_limit_from_env();
}

#else

void language_init_timing(void) { }
void language_destroy_timing(void) { }

LANGUAGE_DLLEXPORT language_timing_event_t *_language_timing_event_create(const char *subsystem, const char *name, const char *function, const char *file, int line, int color) { return NULL; }

LANGUAGE_DLLEXPORT void _language_timing_block_init(char *buf, size_t size, language_timing_event_t *event) { }
LANGUAGE_DLLEXPORT void _language_timing_block_start(language_timing_block_t *block) { }
LANGUAGE_DLLEXPORT void _language_timing_block_end(language_timing_block_t *block) { }

LANGUAGE_DLLEXPORT int language_timing_set_enable(const char *subsystem, uint8_t enabled) { return -1; }
LANGUAGE_DLLEXPORT uint32_t language_timing_print_limit = 0;

#endif

#ifdef __cplusplus
}
#endif
