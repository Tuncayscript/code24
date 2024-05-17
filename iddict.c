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

#define hash_size(h) (h->length / 2)

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)

#define keyhash(k) language_object_id_(language_typetagof(k), k)
#define h2index(hv, sz) (size_t)(((hv) & ((sz)-1)) * 2)

static inline int language_table_assign_bp(language_genericmemory_t **pa, language_value_t *key, language_value_t *val);

LANGUAGE_DLLEXPORT language_genericmemory_t *language_idtable_rehash(language_genericmemory_t *a, size_t newsz)
{
    size_t sz = a->length;
    size_t i;
    language_value_t **ol = (language_value_t **) a->ptr;
    language_genericmemory_t *newa = NULL;
    // keep the original memory in the original slot since we need `ol`
    // to be valid in the loop below.
    LANGUAGE_GC_PUSH2(&newa, &a);
    newa = language_alloc_memory_any(newsz);
    for (i = 0; i < sz; i += 2) {
        if (ol[i + 1] != NULL) {
            language_table_assign_bp(&newa, ol[i], ol[i + 1]);
        }
    }
    LANGUAGE_GC_POP();
    return newa;
}

static inline int language_table_assign_bp(language_genericmemory_t **pa, language_value_t *key, language_value_t *val)
{
    // pa points to a **un**rooted address
    uint_t hv;
    language_genericmemory_t *a = *pa;
    size_t orig, index, iter, empty_slot;
    size_t newsz, sz = hash_size(a);
    if (sz == 0) {
        a = language_alloc_memory_any(HT_N_INLINE);
        sz = hash_size(a);
        *pa = a;
    }
    size_t maxprobe = max_probe(sz);
    _Atomic(language_value_t*) *tab = (_Atomic(language_value_t*)*) a->ptr;

    hv = keyhash(key);
    while (1) {
        iter = 0;
        index = h2index(hv, sz);
        sz *= 2;
        orig = index;
        empty_slot = -1;

        do {
            language_value_t *k2 = language_atomic_load_relaxed(&tab[index]);
            if (k2 == NULL) {
                if (empty_slot == -1)
                    empty_slot = index;
                break;
            }
            if (language_egal(key, k2)) {
                if (language_atomic_load_relaxed(&tab[index + 1]) != NULL) {
                    language_atomic_store_release(&tab[index + 1], val);
                    language_gc_wb(a, val);
                    return 0;
                }
                // `nothing` is our sentinel value for deletion, so need to keep searching if it's also our search key
                assert(key == language_nothing);
                if (empty_slot == -1)
                    empty_slot = index;
            }
            if (empty_slot == -1 && language_atomic_load_relaxed(&tab[index + 1]) == NULL) {
                assert(language_atomic_load_relaxed(&tab[index]) == language_nothing);
                empty_slot = index;
            }

            index = (index + 2) & (sz - 1);
            iter++;
        } while (iter <= maxprobe && index != orig);

        if (empty_slot != -1) {
            language_atomic_store_release(&tab[empty_slot], key);
            language_gc_wb(a, key);
            language_atomic_store_release(&tab[empty_slot + 1], val);
            language_gc_wb(a, val);
            return 1;
        }

        /* table full */
        /* quadruple size, rehash, retry the insert */
        /* it's important to grow the table really fast; otherwise we waste */
        /* lots of time rehashing all the keys over and over. */
        sz = a -> length;
        if (sz < HT_N_INLINE)
            newsz = HT_N_INLINE;
        else if (sz >= (1 << 19) || (sz <= (1 << 8)))
            newsz = sz << 1;
        else
            newsz = sz << 2;
        *pa = language_idtable_rehash(*pa, newsz);

        a = *pa;
        tab =  (_Atomic(language_value_t*)*) a->ptr;
        sz = hash_size(a);
        maxprobe = max_probe(sz);
    }
}

/* returns bp if key is in hash, otherwise NULL */
inline _Atomic(language_value_t*) *language_table_peek_bp(language_genericmemory_t *a, language_value_t *key) LANGUAGE_NOTSAFEPOINT
{
    size_t sz = hash_size(a);
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(language_value_t*) *tab = (_Atomic(language_value_t*)*) a->ptr;
    uint_t hv = keyhash(key);
    size_t index = h2index(hv, sz);
    sz *= 2;
    size_t orig = index;
    size_t iter = 0;

    do {
        language_value_t *k2 = language_atomic_load_relaxed(&tab[index]); // just to ensure the load doesn't get duplicated
        if (k2 == NULL)
            return NULL;
        if (language_egal(key, k2)) {
            if (language_atomic_load_relaxed(&tab[index + 1]) != NULL)
                return &tab[index + 1];
            // `nothing` is our sentinel value for deletion, so need to keep searching if it's also our search key
            if (key != language_nothing)
                return NULL; // concurrent insertion hasn't completed yet
        }

        index = (index + 2) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);

    return NULL;
}

LANGUAGE_DLLEXPORT
language_genericmemory_t *language_eqtable_put(language_genericmemory_t *h, language_value_t *key, language_value_t *val, int *p_inserted)
{
    int inserted = language_table_assign_bp(&h, key, val);
    if (p_inserted)
        *p_inserted = inserted;
    return h;
}

// Note: lookup in the IdDict is permitted concurrently, if you avoid deletions,
// and assuming you do use an external lock around all insertions
LANGUAGE_DLLEXPORT
language_value_t *language_eqtable_get(language_genericmemory_t *h, language_value_t *key, language_value_t *deflt) LANGUAGE_NOTSAFEPOINT
{
    _Atomic(language_value_t*) *bp = language_table_peek_bp(h, key);
    return (bp == NULL) ? deflt : language_atomic_load_relaxed(bp);
}

language_value_t *language_eqtable_getkey(language_genericmemory_t *h, language_value_t *key, language_value_t *deflt) LANGUAGE_NOTSAFEPOINT
{
    _Atomic(language_value_t*) *bp = language_table_peek_bp(h, key);
    return (bp == NULL) ? deflt : language_atomic_load_relaxed(bp - 1);
}

LANGUAGE_DLLEXPORT
language_value_t *language_eqtable_pop(language_genericmemory_t *h, language_value_t *key, language_value_t *deflt, int *found)
{
    _Atomic(language_value_t*) *bp = language_table_peek_bp(h, key);
    if (found)
        *found = (bp != NULL);
    if (bp == NULL)
        return deflt;
    language_value_t *val = language_atomic_load_relaxed(bp);
    language_atomic_store_relaxed(bp - 1, language_nothing); // clear the key
    language_atomic_store_relaxed(bp, NULL); // and the value (briefly corrupting the table)
    return val;
}

LANGUAGE_DLLEXPORT
size_t language_eqtable_nextind(language_genericmemory_t *t, size_t i)
{
    if (i & 1)
        i++;
    size_t alen = t->length;
    while (i < alen && ((void**) t->ptr)[i + 1] == NULL)
        i += 2;
    if (i >= alen)
        return (size_t)-1;
    return i;
}

#undef hash_size
#undef max_probe
#undef h2index
