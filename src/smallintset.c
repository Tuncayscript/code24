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

#include <stdlib.h>
#include <string.h>
#include "code.h"
#include "language_internal.h"
#ifndef _OS_WINDOWS_
#include <unistd.h>
#endif
#include "language_assert.h"

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)((hv) & ((sz)-1))

// a set of small positive integers representing the indices into another set
// (or dict) where the hash is derived from the keys in the set via the lambdas
// `hash` and `eq` supports concurrent calls to language_smallintset_lookup (giving
// acquire ordering), provided that a lock is held over calls to
// smallintset_rehash, and the elements of `data` support release-consume
// atomics.

#ifdef __cplusplus
extern "C" {
#endif

static inline size_t ignore_tombstone(size_t val, size_t tombstone) LANGUAGE_NOTSAFEPOINT
{
    return val == tombstone ? 0 : val;
}
static inline size_t language_intref(const language_genericmemory_t *arr, size_t idx) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *el = (language_value_t*)language_typetagof(arr);
    if (el == language_memory_uint8_type)
        return ignore_tombstone(language_atomic_load_relaxed(&((_Atomic(uint8_t)*)arr->ptr)[idx]), (uint8_t)-1);
    else if (el == language_memory_uint16_type)
        return ignore_tombstone(language_atomic_load_relaxed(&((_Atomic(uint16_t)*)arr->ptr)[idx]), (uint16_t)-1);
    else if (el == language_memory_uint32_type)
        return ignore_tombstone(language_atomic_load_relaxed(&((_Atomic(uint32_t)*)arr->ptr)[idx]), UINT32_MAX);
    else
        abort();
}

static inline size_t acquire_tombstone(size_t val, size_t tombstone) LANGUAGE_NOTSAFEPOINT
{
    return val == tombstone ? (size_t)-1 : val;
}
static inline size_t language_intref_acquire(const language_genericmemory_t *arr, size_t idx) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *el = (language_value_t*)language_typetagof(arr);
    if (el == language_memory_uint8_type)
        return acquire_tombstone(language_atomic_load_acquire(&((_Atomic(uint8_t)*)arr->ptr)[idx]), (uint8_t)-1);
    else if (el == language_memory_uint16_type)
        return acquire_tombstone(language_atomic_load_acquire(&((_Atomic(uint16_t)*)arr->ptr)[idx]), (uint16_t)-1);
    else if (el == language_memory_uint32_type)
        return acquire_tombstone(language_atomic_load_acquire(&((_Atomic(uint32_t)*)arr->ptr)[idx]), UINT32_MAX);
    else
        abort();
}

static inline void language_intset_release(const language_genericmemory_t *arr, size_t idx, size_t val) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *el = (language_value_t*)language_typetagof(arr);
    if (el == language_memory_uint8_type)
        language_atomic_store_release(&((_Atomic(uint8_t)*)arr->ptr)[idx], val);
    else if (el == language_memory_uint16_type)
        language_atomic_store_release(&((_Atomic(uint16_t)*)arr->ptr)[idx], val);
    else if (el == language_memory_uint32_type)
        language_atomic_store_release(&((_Atomic(uint32_t)*)arr->ptr)[idx], val);
    else
        abort();
}

static inline size_t language_max_int(const language_genericmemory_t *arr) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *el = (language_value_t*)language_typetagof(arr);
    if (el == language_memory_uint8_type)
        return 0xFF;
    else if (el == language_memory_uint16_type)
        return 0xFFFF;
    else if (el == language_memory_uint32_type)
        return 0xFFFFFFFF;
    else if (el == language_memory_any_type)
        return 0;
    else
        abort();
}

void smallintset_empty(const language_genericmemory_t *a) LANGUAGE_NOTSAFEPOINT
{
    size_t elsize;
    language_value_t *el = (language_value_t*)language_typetagof(a);
    if (el == language_memory_uint8_type)
        elsize = sizeof(uint8_t);
    else if (el == language_memory_uint16_type)
        elsize = sizeof(uint16_t);
    else if (el == language_memory_uint32_type)
        elsize = sizeof(uint32_t);
    else if (el == language_memory_any_type)
        elsize = 0;
    else
        abort();
    memset(a->ptr, 0, a->length * elsize);
}

static language_genericmemory_t *language_alloc_int_1d(size_t np, size_t len)
{
    language_value_t *ty;
    if (np < 0xFF)
        ty = language_memory_uint8_type;
    else if (np < 0xFFFF)
        ty = language_memory_uint16_type;
    else
        ty = language_memory_uint32_type;
    assert(np < 0x7FFFFFFF);
    language_genericmemory_t *a = language_alloc_genericmemory(ty, len);
    smallintset_empty(a);
    return a;
}

ssize_t language_smallintset_lookup(language_genericmemory_t *cache, smallintset_eq eq, const void *key, language_value_t *data, uint_t hv, int pop)
{
    size_t sz = cache->length;
    if (sz == 0)
        return -1;
    LANGUAGE_GC_PUSH1(&cache);
    size_t maxprobe = max_probe(sz);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        size_t val1 = language_intref_acquire(cache, index);
        if (val1 == 0) {
            LANGUAGE_GC_POP();
            return -1;
        }
        if (val1 != -1 && eq(val1 - 1, key, data, hv)) {
            LANGUAGE_GC_POP();
            if (pop)
                language_intset_release(cache, index, (size_t)-1); // replace with tombstone
            return val1 - 1;
        }
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    LANGUAGE_GC_POP();
    return -1;
}

static int smallintset_insert_(language_genericmemory_t *a, uint_t hv, size_t val1) LANGUAGE_NOTSAFEPOINT
{
    size_t sz = a->length;
    if (sz <= 1)
        return 0;
    size_t orig, index, iter;
    iter = 0;
    index = h2index(hv, sz);
    orig = index;
    size_t maxprobe = max_probe(sz);
    do {
        if (language_intref(a, index) == 0) {
            language_intset_release(a, index, val1);
            return 1;
        }
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return 0;
}
//}

void language_smallintset_insert(_Atomic(language_genericmemory_t*) *pcache, language_value_t *parent, smallintset_hash hash, size_t val, language_value_t *data)
{
    language_genericmemory_t *a = language_atomic_load_relaxed(pcache);
    if (val + 1 >= language_max_int(a)) {
        a = smallintset_rehash(a, hash, data, a->length, val + 1);
        language_atomic_store_release(pcache, a);
        if (parent) language_gc_wb(parent, a);
    }
    while (1) {
        if (smallintset_insert_(a, hash(val, data), val + 1))
            return;

        /* table full */
        /* rehash to grow and retry the insert */
        /* it's important to grow the table really fast; otherwise we waste */
        /* lots of time rehashing all the keys over and over. */
        size_t newsz;
        a = language_atomic_load_relaxed(pcache);
        size_t sz = a->length;
        if (sz < HT_N_INLINE)
            newsz = HT_N_INLINE;
        else if (sz >= (1 << 19) || (sz <= (1 << 8)))
            newsz = sz << 1;
        else
            newsz = sz << 2;
        a = smallintset_rehash(a, hash, data, newsz, 0);
        language_atomic_store_release(pcache, a);
        if (parent) language_gc_wb(parent, a);
    }
}

language_genericmemory_t* smallintset_rehash(language_genericmemory_t* a, smallintset_hash hash, language_value_t *data, size_t newsz, size_t np)
{
    size_t sz = a->length;
    size_t i;
    for (i = 0; i < sz; i += 1) {
        size_t val = language_intref(a, i);
        if (val > np)
            np = val;
    }
    while (1) {
        language_genericmemory_t *newa = language_alloc_int_1d(np + 1, newsz);
        LANGUAGE_GC_PUSH1(&newa);
        for (i = 0; i < sz; i += 1) {
            size_t val1 = language_intref(a, i);
            if (val1 != 0) {
                if (!smallintset_insert_(newa, hash(val1 - 1, data), val1)) {
                    break;
                }
            }
        }
        LANGUAGE_GC_POP();
        if (i == sz)
            return newa;
        newsz <<= 1;
    }
}

#ifdef __cplusplus
}
#endif
