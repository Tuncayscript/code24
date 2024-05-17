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

/*
  functions common to all hash table instantiations
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "dtypes.h"
#include "htable.h"
#include "hashing.h"

#ifdef __cplusplus
extern "C" {
#endif

htable_t *htable_new(htable_t *h, size_t size)
{
    if (size <= HT_N_INLINE / 2) {
        h->size = size = HT_N_INLINE;
        h->table = &h->_space[0];
    }
    else {
        size = next_power_of_two(size);
        size *= 2;  // 2 pointers per key/value pair
        size *= 2;  // aim for 50% occupancy
        h->size = size;
        h->table = (void**)LLT_ALLOC(size * sizeof(void*));
    }
    if (h->table == NULL)
        return NULL;
    size_t i;
    for (i = 0; i < size; i++)
        h->table[i] = HT_NOTFOUND;
    return h;
}

void htable_free(htable_t *h)
{
    if (h->table != &h->_space[0])
        LLT_FREE(h->table);
}

// empty and reduce size
void htable_reset(htable_t *h, size_t sz)
{
    sz = next_power_of_two(sz);
    if (h->size > sz * 4 && h->size > HT_N_INLINE) {
        LLT_FREE(h->table);
        h->table = NULL;
        if (htable_new(h, sz) == NULL)
            htable_new(h, 0);
    }
    else {
        size_t i, hsz = h->size;
        for (i = 0; i < hsz; i++)
            h->table[i] = HT_NOTFOUND;
    }
}

#ifdef __cplusplus
}
#endif
