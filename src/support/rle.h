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

#ifndef LANGUAGE_RLE_H
#define LANGUAGE_RLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "analyzer_annotations.h"

/* Run-length encoding (RLE) utilities */
/* In the RLE table, even indexes encode the key (the item classification), odd indexes encode the item index */
/* For example, a table

       {77, 3, 88, 5, 77, 8}

   would represent a list where items at indexes 3-4 have key 77, items at indexes 5-7 have key 88,
   and items from 8 onward have key 77. Items prior to index 3 have an implicit key passed in as `key0`.
*/

/* iteration */
typedef struct _rle_iter_state_t {
    size_t i;      // index for the items
    size_t j;      // index for the rle table
    uint64_t key;  // current identifier
} rle_iter_state;

rle_iter_state rle_iter_init(/* implicit value of key for indexes prior to first explicit rle pair */ uint64_t key0) LANGUAGE_NOTSAFEPOINT;
int rle_iter_increment(rle_iter_state *state, /* number of items */ size_t len, uint64_t *rletable, /*length of rletable */ size_t npairs) LANGUAGE_NOTSAFEPOINT;

/* indexing */
typedef struct {
    uint64_t key;
    int index;     // number of preceding items in the list with the same key
} rle_reference;

void rle_index_to_reference(rle_reference *rr, /* item index */ size_t i, uint64_t *rletable, size_t npairs, uint64_t key0) LANGUAGE_NOTSAFEPOINT;
size_t rle_reference_to_index(rle_reference *rr, uint64_t *rletable, size_t npairs, uint64_t key0) LANGUAGE_NOTSAFEPOINT;


#ifdef __cplusplus
}
#endif

#endif
