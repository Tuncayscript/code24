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

#ifndef LANGUAGE_ARRAYLIST_H
#define LANGUAGE_ARRAYLIST_H

#define AL_N_INLINE 29

#define SMALL_AL_N_INLINE 6

#ifdef __cplusplus
extern "C" {
#endif

#include "analyzer_annotations.h"

typedef struct {
    size_t len;
    size_t max;
    void **items;
    void *_space[AL_N_INLINE];
} arraylist_t;

arraylist_t *arraylist_new(arraylist_t *a, size_t size) LANGUAGE_NOTSAFEPOINT;
void arraylist_free(arraylist_t *a) LANGUAGE_NOTSAFEPOINT;

void arraylist_push(arraylist_t *a, void *elt) LANGUAGE_NOTSAFEPOINT;
void *arraylist_pop(arraylist_t *a) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void arraylist_grow(arraylist_t *a, size_t n) LANGUAGE_NOTSAFEPOINT;

typedef struct {
    uint32_t len;
    uint32_t max;
    void **items;
    void *_space[SMALL_AL_N_INLINE];
} small_arraylist_t;

small_arraylist_t *small_arraylist_new(small_arraylist_t *a, uint32_t size) LANGUAGE_NOTSAFEPOINT;
void small_arraylist_free(small_arraylist_t *a) LANGUAGE_NOTSAFEPOINT;

void small_arraylist_push(small_arraylist_t *a, void *elt) LANGUAGE_NOTSAFEPOINT;
void *small_arraylist_pop(small_arraylist_t *a) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void small_arraylist_grow(small_arraylist_t *a, uint32_t n) LANGUAGE_NOTSAFEPOINT;

#ifdef __cplusplus
}
#endif

#endif
