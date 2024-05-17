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

#ifndef LANGUAGE_HTABLE_H
#define LANGUAGE_HTABLE_H

#define HT_N_INLINE 32

#include "analyzer_annotations.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Power-of-two hash table with linear probing.
//
// Keys and values are stored as in consecutive elements
//   key   = table[2*i]
//   value = table[2*i+1]
// where `2*i < size`. An empty slot at index `i` is indicated with
// `value == HT_NOTFOUND`.
//
// `_space` is reserved space for efficiently allocating small tables.
typedef struct {
    size_t size;
    void **table;
    void *_space[HT_N_INLINE];
} htable_t;

// define this to be an invalid key/value
#define HT_NOTFOUND ((void*)1)

// initialize hash table, reserving space for `size` expected number of
// elements. (Expect `h->size > size` for efficient occupancy factor.)
htable_t *htable_new(htable_t *h, size_t size) LANGUAGE_NOTSAFEPOINT;
void htable_free(htable_t *h);

// clear and (possibly) change size
void htable_reset(htable_t *h, size_t sz);

// Lookup and mutation. See htable.inc for detail.
#define HTPROT(HTNAME)                                                  \
void *HTNAME##_get(htable_t *h, void *key) LANGUAGE_NOTSAFEPOINT;             \
void HTNAME##_put(htable_t *h, void *key, void *val) LANGUAGE_NOTSAFEPOINT;   \
void HTNAME##_adjoin(htable_t *h, void *key, void *val) LANGUAGE_NOTSAFEPOINT;\
int HTNAME##_has(htable_t *h, void *key) LANGUAGE_NOTSAFEPOINT;               \
int HTNAME##_remove(htable_t *h, void *key) LANGUAGE_NOTSAFEPOINT;            \
void **HTNAME##_bp(htable_t *h, void *key) LANGUAGE_NOTSAFEPOINT;

#define HTPROT_R(HTNAME)                                                                \
void *HTNAME##_get_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;                \
void HTNAME##_put_r(htable_t *h, void *key, void *val, void *ctx) LANGUAGE_NOTSAFEPOINT;      \
void HTNAME##_adjoin_r(htable_t *h, void *key, void *val, void *ctx) LANGUAGE_NOTSAFEPOINT;   \
int HTNAME##_has_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;                  \
int HTNAME##_remove_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;               \
void **HTNAME##_bp_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;

#ifdef __cplusplus
}
#endif

#endif
