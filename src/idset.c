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


static uint_t idset_hash(size_t idx, language_value_t *data)
{
    language_value_t *x = language_genericmemory_ptr_ref(data, idx);
    // x should not be NULL, unless there was concurrent corruption
    return x == NULL ? 0 : language_object_id(x);
}

static int idset_eq(size_t idx, const void *y, language_value_t *data, uint_t hv)
{
    language_value_t *x = language_genericmemory_ptr_ref(data, idx);
    // x should not be NULL, unless there was concurrent corruption
    return x == NULL ? 0 : language_egal(x, (language_value_t*)y);
}

language_genericmemory_t *language_idset_rehash(language_genericmemory_t *keys, language_genericmemory_t *idxs, size_t newsz)
{
    if (newsz == 0)
        return idxs;
    newsz = next_power_of_two(newsz);
    //if (idxs->length == newsz)
    //    language_idset_put_idx(keys, idxs, -newsz+1);
    //else
    return smallintset_rehash(idxs, idset_hash, (language_value_t*)keys, newsz, 0);
}

// Return idx if key is in hash, otherwise -1
// Note: lookup in the IdSet is permitted concurrently, if you avoid deletions,
// and assuming you do use an external lock around all insertions
ssize_t language_idset_peek_bp(language_genericmemory_t *keys, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t hv = language_object_id(key);
    return language_smallintset_lookup(idxs, idset_eq, key, (language_value_t*)keys, hv, 0);
}

language_value_t *language_idset_get(language_genericmemory_t *keys, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT
{
    ssize_t idx = language_idset_peek_bp(keys, idxs, key);
    if (idx == -1)
        return NULL;
    return language_genericmemory_ptr_ref(keys, idx);
}


static ssize_t idset_compact(language_genericmemory_t *keys)
{
    // compact keys before rehashing idxs
    ssize_t i, j;
    ssize_t rehash = 0;
    for (i = j = 0; i < keys->length; i++) {
        language_value_t *k = language_genericmemory_ptr_ref(keys, i);
        if (k != NULL) {
            if (i != j) {
                rehash = 1;
                language_genericmemory_ptr_set(keys, j, k);
                language_genericmemory_ptr_set(keys, i, NULL);
            }
            j++;
        }
    }
    return rehash ? -j : j;
}

language_genericmemory_t *language_idset_put_key(language_genericmemory_t *keys, language_value_t *key, ssize_t *newidx)
{
    ssize_t l = keys->length;
    ssize_t i = l;
    while (i > 0 && language_genericmemory_ptr_ref(keys, i - 1) == NULL)
        i--;
    // i points to the place to insert
    *newidx = i;
    if (i == l) {
        i = idset_compact(keys);
        if (i < 0) {
            *newidx = i - 1;
            i = -i;
        }
        if (i >= l / 3 * 2) {
            size_t nl = l < 4 ? 4 : (l * 3) >> 1; // grow space by 50% if less than 33% free after compacting
            language_genericmemory_t *nk = language_alloc_genericmemory(language_memory_any_type, nl);
            if (i > 0)
                memcpy(nk->ptr, keys->ptr, sizeof(void*) * i);
            keys = nk;
        }
    }
    assert(language_genericmemory_ptr_ref(keys, i) == NULL);
    language_genericmemory_ptr_set(keys, i, key);
    return keys;
}

language_genericmemory_t *language_idset_put_idx(language_genericmemory_t *keys, language_genericmemory_t *idxs, ssize_t idx)
{
    _Atomic(language_genericmemory_t*) newidxs = idxs;
    LANGUAGE_GC_PUSH1(&newidxs);
    if (idx < 0) { // full rehash
        smallintset_empty(idxs);
        for (ssize_t i = 0; i < -idx; i++)
            if (language_genericmemory_ptr_ref(keys, i) != NULL)
                language_smallintset_insert(&newidxs, NULL, idset_hash, i, (language_value_t*)keys);
    }
    else {
        language_smallintset_insert(&newidxs, NULL, idset_hash, idx, (language_value_t*)keys);
    }
    LANGUAGE_GC_POP();
    return language_atomic_load_relaxed(&newidxs);
}

/* returns idx if key is in hash, otherwise -1 */
ssize_t language_idset_pop(language_genericmemory_t *keys, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t hv = language_object_id(key);
    ssize_t idx = language_smallintset_lookup(idxs, idset_eq, key, (language_value_t*)keys, hv, 1);
    if (idx != -1)
        language_genericmemory_ptr_set(keys, idx, NULL);
    return idx;
}
