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

#ifndef WORK_STEALING_QUEUE_H
#define WORK_STEALING_QUEUE_H

#include <stdalign.h>

#include "language_atomics.h"
#include "assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// =======
// Chase and Lev's work-stealing queue, optimized for
// weak memory models by Le et al.
//
// * Chase D., Lev Y. Dynamic Circular Work-Stealing queue
// * Le N. M. et al. Correct and Efficient Work-Stealing for
//   Weak Memory Models
// =======

typedef struct {
    char *buffer;
    int32_t capacity;
    int32_t mask;
} ws_array_t;

static inline ws_array_t *create_ws_array(size_t capacity, int32_t eltsz) LANGUAGE_NOTSAFEPOINT
{
    ws_array_t *a = (ws_array_t *)malloc_s(sizeof(ws_array_t));
    a->buffer = (char *)malloc_s(capacity * eltsz);
    a->capacity = capacity;
    a->mask = capacity - 1;
    return a;
}

static inline void free_ws_array(ws_array_t *a)
{
    free(a->buffer);
    free(a);
}

typedef struct {
    // align to LANGUAGE_CACHE_BYTE_ALIGNMENT
    alignas(LANGUAGE_CACHE_BYTE_ALIGNMENT) _Atomic(int64_t) top;
    alignas(LANGUAGE_CACHE_BYTE_ALIGNMENT) _Atomic(int64_t) bottom;
    alignas(LANGUAGE_CACHE_BYTE_ALIGNMENT) _Atomic(ws_array_t *) array;
} ws_queue_t;

static inline ws_array_t *ws_queue_push(ws_queue_t *q, void *elt, int32_t eltsz) LANGUAGE_NOTSAFEPOINT
{
    int64_t b = language_atomic_load_relaxed(&q->bottom);
    int64_t t = language_atomic_load_acquire(&q->top);
    ws_array_t *ary = language_atomic_load_relaxed(&q->array);
    ws_array_t *old_ary = NULL;
    if (__unlikely(b - t > ary->capacity - 1)) {
        ws_array_t *new_ary = create_ws_array(2 * ary->capacity, eltsz);
        for (int i = 0; i < ary->capacity; i++) {
            memcpy(new_ary->buffer + ((t + i) & new_ary->mask) * eltsz, ary->buffer + ((t + i) & ary->mask) * eltsz, eltsz);
        }
        language_atomic_store_release(&q->array, new_ary);
        old_ary = ary;
        ary = new_ary;
    }
    memcpy(ary->buffer + (b & ary->mask) * eltsz, elt, eltsz);
    language_fence_release();
    language_atomic_store_relaxed(&q->bottom, b + 1);
    return old_ary;
}

static inline void ws_queue_pop(ws_queue_t *q, void *dest, int32_t eltsz) LANGUAGE_NOTSAFEPOINT
{
    int64_t b = language_atomic_load_relaxed(&q->bottom) - 1;
    ws_array_t *ary = language_atomic_load_relaxed(&q->array);
    language_atomic_store_relaxed(&q->bottom, b);
    language_fence();
    int64_t t = language_atomic_load_relaxed(&q->top);
    if (__likely(t <= b)) {
        memcpy(dest, ary->buffer + (b & ary->mask) * eltsz, eltsz);
        if (t == b) {
            if (!language_atomic_cmpswap(&q->top, &t, t + 1))
                memset(dest, 0, eltsz);
            language_atomic_store_relaxed(&q->bottom, b + 1);
        }
    }
    else {
        memset(dest, 0, eltsz);
        language_atomic_store_relaxed(&q->bottom, b + 1);
    }
}

static inline void ws_queue_steal_from(ws_queue_t *q, void *dest, int32_t eltsz) LANGUAGE_NOTSAFEPOINT
{
    int64_t t = language_atomic_load_acquire(&q->top);
    language_fence();
    int64_t b = language_atomic_load_acquire(&q->bottom);
    if (t < b) {
        ws_array_t *ary = language_atomic_load_relaxed(&q->array);
        memcpy(dest, ary->buffer + (t & ary->mask) * eltsz, eltsz);
        if (!language_atomic_cmpswap(&q->top, &t, t + 1))
            memset(dest, 0, eltsz);
    }
}

#ifdef __cplusplus
}
#endif

#endif
