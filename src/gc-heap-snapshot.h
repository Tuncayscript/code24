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

#ifndef LANGUAGE_GC_HEAP_SNAPSHOT_H
#define LANGUAGE_GC_HEAP_SNAPSHOT_H

#include "code.h"
#include "ios.h"

#ifdef __cplusplus
extern "C" {
#endif


// ---------------------------------------------------------------------
// Functions to call from GC when heap snapshot is enabled
// ---------------------------------------------------------------------
void _gc_heap_snapshot_record_root(language_value_t *root, char *name) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_frame_to_object_edge(void *from, language_value_t *to) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_task_to_frame_edge(language_task_t *from, void *to) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_frame_to_frame_edge(language_gcframe_t *from, language_gcframe_t *to) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_array_edge(language_value_t *from, language_value_t *to, size_t index) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_object_edge(language_value_t *from, language_value_t *to, void* slot) LANGUAGE_NOTSAFEPOINT;
void _gc_heap_snapshot_record_module_to_binding(language_module_t* module, language_value_t *bindings, language_value_t *bindingkeyset) LANGUAGE_NOTSAFEPOINT;
// Used for objects managed by GC, but which aren't exposed in the julia object, so have no
// field or index.  i.e. they're not reachable from julia code, but we _will_ hit them in
// the GC mark phase (so we can check their type tag to get the size).
void _gc_heap_snapshot_record_internal_array_edge(language_value_t *from, language_value_t *to) LANGUAGE_NOTSAFEPOINT;
// Used for objects manually allocated in C (outside julia GC), to still tell the heap snapshot about the
// size of the object, even though we're never going to mark that object.
void _gc_heap_snapshot_record_hidden_edge(language_value_t *from, void* to, size_t bytes, uint16_t alloc_type) LANGUAGE_NOTSAFEPOINT;
// Used for objects that are reachable from the GC roots
void _gc_heap_snapshot_record_gc_roots(language_value_t *root, char *name) LANGUAGE_NOTSAFEPOINT;
// Used for objects that are reachable from the finalizer list
void _gc_heap_snapshot_record_finlist(language_value_t *finlist, size_t index) LANGUAGE_NOTSAFEPOINT;

extern int gc_heap_snapshot_enabled;
extern int prev_sweep_full;

int gc_slot_to_fieldidx(void *_obj, void *slot, language_datatype_t *vt) LANGUAGE_NOTSAFEPOINT;
int gc_slot_to_arrayidx(void *_obj, void *begin) LANGUAGE_NOTSAFEPOINT;

static inline void gc_heap_snapshot_record_frame_to_object_edge(void *from, language_value_t *to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_frame_to_object_edge(from, to);
    }
}
static inline void gc_heap_snapshot_record_task_to_frame_edge(language_task_t *from, void *to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_task_to_frame_edge(from, to);
    }
}
static inline void gc_heap_snapshot_record_frame_to_frame_edge(language_gcframe_t *from, language_gcframe_t *to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_frame_to_frame_edge(from, to);
    }
}
static inline void gc_heap_snapshot_record_root(language_value_t *root, char *name) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_root(root, name);
    }
}
static inline void gc_heap_snapshot_record_array_edge_index(language_value_t *from, language_value_t *to, size_t index) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full && from != NULL && to != NULL)) {
        _gc_heap_snapshot_record_array_edge(from, to, index);
    }
}
static inline void gc_heap_snapshot_record_array_edge(language_value_t *from, language_value_t **to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_array_edge(from, *to, gc_slot_to_arrayidx(from, to));
    }
}
static inline void gc_heap_snapshot_record_object_edge(language_value_t *from, language_value_t **to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_object_edge(from, *to, to);
    }
}

static inline void gc_heap_snapshot_record_module_to_binding(language_module_t* module, language_value_t *bindings, language_value_t *bindingkeyset) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full) && bindings != NULL && bindingkeyset != NULL) {
        _gc_heap_snapshot_record_module_to_binding(module, bindings, bindingkeyset);
    }
}

static inline void gc_heap_snapshot_record_internal_array_edge(language_value_t *from, language_value_t *to) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_internal_array_edge(from, to);
    }
}

static inline void gc_heap_snapshot_record_hidden_edge(language_value_t *from, void* to, size_t bytes, uint16_t alloc_type) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full)) {
        _gc_heap_snapshot_record_hidden_edge(from, to, bytes, alloc_type);
    }
}

static inline void gc_heap_snapshot_record_gc_roots(language_value_t *root, char *name) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full && root != NULL)) {
        _gc_heap_snapshot_record_gc_roots(root, name);
    }
}

static inline void gc_heap_snapshot_record_finlist(language_value_t *finlist, size_t index) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(gc_heap_snapshot_enabled && prev_sweep_full && finlist != NULL)) {
        _gc_heap_snapshot_record_finlist(finlist, index);
    }
}

// ---------------------------------------------------------------------
// Functions to call from Julia to take heap snapshot
// ---------------------------------------------------------------------
LANGUAGE_DLLEXPORT void language_gc_take_heap_snapshot(ios_t *nodes, ios_t *edges,
    ios_t *strings, ios_t *json, char all_one);


#ifdef __cplusplus
}
#endif


#endif  // LANGUAGE_GC_HEAP_SNAPSHOT_H
