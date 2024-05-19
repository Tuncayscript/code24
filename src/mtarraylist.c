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

#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// this file provides some alternate API functions for small_arraylist (push and add)
// which can be safely observed from other threads concurrently
// there is only permitted to be a single writer thread (or a mutex)
// but there can be any number of observers

typedef struct {
    _Atomic(uint32_t) len;
    uint32_t max;
    _Atomic(_Atomic(void*)*) items;
    _Atomic(void*) _space[SMALL_AL_N_INLINE];
} small_mtarraylist_t;

// change capacity to at least newlen
static void mtarraylist_resizeto(small_mtarraylist_t *a, size_t len, size_t newlen) LANGUAGE_NOTSAFEPOINT
{
    size_t max = a->max;
    if (newlen > max) {
        size_t nm = max * 2;
        if (nm == 0)
            nm = 1;
        while (newlen > nm)
            nm *= 2;
        void *olditems = (void*)language_atomic_load_relaxed(&a->items);
        void *p = calloc_s(nm * sizeof(void*));
        memcpy(p, olditems, len * sizeof(void*));
        language_atomic_store_release(&a->items, (_Atomic(void*)*)p);
        a->max = nm;
        if (olditems != (void*)&a->_space[0]) {
            language_task_t *ct = language_current_task;
            language_gc_add_quiescent(ct->ptls, (void**)olditems, free);
        }
    }
}

// single-threaded
void mtarraylist_push(small_arraylist_t *_a, void *elt)
{
    small_mtarraylist_t *a = (small_mtarraylist_t*)_a;
    size_t len = language_atomic_load_relaxed(&a->len);
    mtarraylist_resizeto(a, len, len + 1);
    language_atomic_store_release(&language_atomic_load_relaxed(&a->items)[len], elt);
    language_atomic_store_release(&a->len, len + 1);
}

// single-threaded
void mtarraylist_add(small_arraylist_t *_a, void *elt, size_t idx)
{
    small_mtarraylist_t *a = (small_mtarraylist_t*)_a;
    size_t len = language_atomic_load_relaxed(&a->len);
    mtarraylist_resizeto(a, len, idx + 1);
    language_atomic_store_release(&language_atomic_load_relaxed(&a->items)[idx], elt);
    if (language_atomic_load_relaxed(&a->len) < idx + 1)
        language_atomic_store_release(&a->len, idx + 1);
}

// concurrent-safe
size_t mtarraylist_length(small_arraylist_t *_a)
{
    small_mtarraylist_t *a = (small_mtarraylist_t*)_a;
    return language_atomic_load_relaxed(&a->len);
}

// concurrent-safe
void *mtarraylist_get(small_arraylist_t *_a, size_t idx)
{
    small_mtarraylist_t *a = (small_mtarraylist_t*)_a;
    size_t len = language_atomic_load_acquire(&a->len);
    if (idx >= len)
        return NULL;
    return language_atomic_load_relaxed(&language_atomic_load_relaxed(&a->items)[idx]);
}
