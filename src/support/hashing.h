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

#ifndef LANGUAGE_HASHING_H
#define LANGUAGE_HASHING_H

#include "utils.h"
#include "dtypes.h"
#include "analyzer_annotations.h"

#ifdef __cplusplus
extern "C" {
#endif

uint_t nextipow2(uint_t i) LANGUAGE_NOTSAFEPOINT;
uint32_t int32hash(uint32_t a) LANGUAGE_NOTSAFEPOINT;
uint64_t int64hash(uint64_t key) LANGUAGE_NOTSAFEPOINT;
uint32_t int64to32hash(uint64_t key) LANGUAGE_NOTSAFEPOINT;
#ifdef _P64
#define inthash int64hash
#else
#define inthash int32hash
#endif
LANGUAGE_DLLEXPORT uint64_t memhash(const char *buf, size_t n) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint64_t memhash_seed(const char *buf, size_t n, uint32_t seed) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint32_t memhash32(const char *buf, size_t n) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint32_t memhash32_seed(const char *buf, size_t n, uint32_t seed) LANGUAGE_NOTSAFEPOINT;

#ifdef _P64
STATIC_INLINE uint64_t bitmix(uint64_t a, uint64_t b) LANGUAGE_NOTSAFEPOINT
{
    return int64hash(a^bswap_64(b));
}
#else
STATIC_INLINE uint32_t bitmix(uint32_t a, uint32_t b) LANGUAGE_NOTSAFEPOINT
{
    return int64to32hash((((uint64_t)a) << 32) | (uint64_t)b);
}
#endif
#define bitmix(a, b) (bitmix)((uintptr_t)(a), (uintptr_t)(b))

#ifdef __cplusplus
}
#endif

#endif
