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

#ifndef LANGUAGE_GCEXT_H
#define LANGUAGE_GCEXT_H

#ifdef __cplusplus
extern "C" {
#endif

// requires including "code.h" beforehand.

// Callbacks that allow C code to hook into the GC.

// Marking callbacks for global roots and tasks, respectively. These,
// along with custom mark functions must not alter the GC state except
// through calling language_gc_mark_queue_obj() and language_gc_mark_queue_objarray().
typedef void (*language_gc_cb_root_scanner_t)(int full) LANGUAGE_NOTSAFEPOINT;
typedef void (*language_gc_cb_task_scanner_t)(language_task_t *task, int full) LANGUAGE_NOTSAFEPOINT;

// Callbacks that are invoked before and after a collection.
typedef void (*language_gc_cb_pre_gc_t)(int full) LANGUAGE_NOTSAFEPOINT;
typedef void (*language_gc_cb_post_gc_t)(int full) LANGUAGE_NOTSAFEPOINT;

// Callbacks to track external object allocations.
typedef void (*language_gc_cb_notify_external_alloc_t)(void *addr, size_t size) LANGUAGE_NOTSAFEPOINT;
typedef void (*language_gc_cb_notify_external_free_t)(void *addr) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_gc_set_cb_root_scanner(language_gc_cb_root_scanner_t cb, int enable);
LANGUAGE_DLLEXPORT void language_gc_set_cb_task_scanner(language_gc_cb_task_scanner_t cb, int enable);
LANGUAGE_DLLEXPORT void language_gc_set_cb_pre_gc(language_gc_cb_pre_gc_t cb, int enable);
LANGUAGE_DLLEXPORT void language_gc_set_cb_post_gc(language_gc_cb_post_gc_t cb, int enable);
LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_external_alloc(language_gc_cb_notify_external_alloc_t cb,
        int enable);
LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_external_free(language_gc_cb_notify_external_free_t cb,
        int enable);

// Memory pressure callback
typedef void (*language_gc_cb_notify_gc_pressure_t)(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_set_cb_notify_gc_pressure(language_gc_cb_notify_gc_pressure_t cb, int enable);

// Types for custom mark and sweep functions.
typedef uintptr_t (*language_markfunc_t)(language_ptls_t, language_value_t *obj);
typedef void (*language_sweepfunc_t)(language_value_t *obj);

// Function to create a new foreign type with custom
// mark and sweep functions.
LANGUAGE_DLLEXPORT language_datatype_t *language_new_foreign_type(
        language_sym_t *name,
        language_module_t *module,
        language_datatype_t *super,
        language_markfunc_t markfunc,
        language_sweepfunc_t sweepfunc,
        int haspointers,
        int large);


#define HAVE_LANGUAGE_REINIT_FOREIGN_TYPE 1
LANGUAGE_DLLEXPORT int language_reinit_foreign_type(
        language_datatype_t *dt,
        language_markfunc_t markfunc,
        language_sweepfunc_t sweepfunc);

LANGUAGE_DLLEXPORT int language_is_foreign_type(language_datatype_t *dt);

LANGUAGE_DLLEXPORT size_t language_gc_max_internal_obj_size(void);
LANGUAGE_DLLEXPORT size_t language_gc_external_obj_hdr_size(void);

// Field layout descriptor for custom types that do
// not fit Julia layout conventions. This is associated with
// language_datatype_t instances where fielddesc_type == 3.

typedef struct {
    language_markfunc_t markfunc;
    language_sweepfunc_t sweepfunc;
} language_fielddescdyn_t;

// Allocate an object of a foreign type.
LANGUAGE_DLLEXPORT void *language_gc_alloc_typed(language_ptls_t ptls, size_t sz, void *ty);

// Queue an object or array of objects for scanning by the garbage collector.
// These functions must only be called from within a root scanner callback
// or from within a custom mark function.
LANGUAGE_DLLEXPORT int language_gc_mark_queue_obj(language_ptls_t ptls, language_value_t *obj);
LANGUAGE_DLLEXPORT void language_gc_mark_queue_objarray(language_ptls_t ptls, language_value_t *parent,
    language_value_t **objs, size_t nobjs);

// Sweep functions will not automatically be called for objects of
// foreign types, as that may not always be desired. Only calling
// language_gc_schedule_foreign_sweepfunc() on an object of a foreign type
// will result in the custom sweep function actually being called.
// This must be done at most once per object and should usually be
// done right after allocating the object.
LANGUAGE_DLLEXPORT void language_gc_schedule_foreign_sweepfunc(language_ptls_t ptls, language_value_t *bj);

// The following functions enable support for conservative marking. This
// functionality allows the user to determine if a machine word can be
// interpreted as a pointer to an object (including the interior of an
// object). It can be used to, for example, scan foreign stack frames or
// data structures with an unknown layout. It is called conservative
// marking, because it can lead to false positives, as non-pointer data
// can mistakenly be interpreted as a pointer to a Julia object.

// CAUTION: This is a sharp tool and should only be used as a measure of
// last resort. The user should be familiar with the risk of memory
// leaks (especially on 32-bit machines) if used inappropriately and how
// optimizing compilers can hide references from conservative stack
// scanning. In particular, arrays must be kept explicitly visible to
// the GC (by using LANGUAGE_GC_PUSH1(), storing them in a location marked by
// the Julia GC, etc.) while their contents are being accessed. The
// reason is that array contents aren't marked separately, so if the
// object itself is not visible to the GC, neither are the contents.

// Enable support for conservative marking. The function returns
// whether support was already enabled. The function may implicitly
// trigger a full garbage collection to properly update all internal
// data structures.
LANGUAGE_DLLEXPORT int language_gc_enable_conservative_gc_support(void);

// This function returns whether support for conservative scanning has
// been enabled. The return values are the same as for
// language_gc_enable_conservative_gc_support().
LANGUAGE_DLLEXPORT int language_gc_conservative_gc_support_enabled(void);

// Returns the base address of a memory block, assuming it is stored in
// a julia memory pool. Return NULL otherwise. Conservative support
// *must* have been enabled for this to work reliably.
//
// NOTE: This will only work for internal pool allocations. For external
// allocations, the user must track allocations using the notification
// callbacks above and verify that they are valid objects. Note that
// external allocations may not all be valid objects and that for those,
// the user *must* validate that they have a proper type, i.e. that
// language_typeof(obj) is an actual type object.
//
// NOTE: Only valid to call from within a GC context.
LANGUAGE_DLLEXPORT language_value_t *language_gc_internal_obj_base_ptr(void *p);

// Return a non-null pointer to the start of the stack area if the task
// has an associated stack buffer. In that case, *size will also contain
// the size of that stack buffer upon return. Also, if task is a thread's
// current task, that thread's id will be stored in *tid; otherwise,
// *tid will be set to -1.
//
// DEPRECATED: use language_active_task_stack() instead.
LANGUAGE_DLLEXPORT void *language_task_stack_buffer(language_task_t *task, size_t *size, int *tid);

// Query the active and total stack range for the given task, and set
// *active_start and *active_end respectively *total_start and *total_end
// accordingly. The range for the active part is a best-effort approximation
// and may not be tight.
LANGUAGE_DLLEXPORT void language_active_task_stack(language_task_t *task,
                                       char **active_start, char **active_end,
                                       char **total_start, char **total_end);

#ifdef __cplusplus
}
#endif

#endif // _JULIA_GCEXT_H
