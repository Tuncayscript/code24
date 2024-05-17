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

#ifndef LANGUAGE_UTILS_H
#define LANGUAGE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

char *uint2str(char *dest, size_t len, uint64_t num, uint32_t base);
int str2int(char *str, size_t len, int64_t *res, uint32_t base);
int isdigit_base(char c, int base);

double conv_to_double(void *data, numerictype_t tag);
int64_t conv_to_int64(void *data, numerictype_t tag);
uint64_t conv_to_uint64(void *data, numerictype_t tag);
int32_t conv_to_int32(void *data, numerictype_t tag);
uint32_t conv_to_uint32(void *data, numerictype_t tag);
#ifdef _P64
#define conv_to_ptrdiff conv_to_int64
#define conv_to_size conv_to_uint64
#else
#define conv_to_ptrdiff conv_to_int32
#define conv_to_size conv_to_uint32
#endif
int cmp_same_lt(void *a, void *b, numerictype_t tag);
int cmp_same_eq(void *a, void *b, numerictype_t tag);
int cmp_lt(void *a, numerictype_t atag, void *b, numerictype_t btag);
int cmp_eq(void *a, numerictype_t atag, void *b, numerictype_t btag,
           int equalnans);

#if defined(__clang__) || (defined(__GNUC__) && (__GNUC__ > 4 || __GNUC_MINOR__ >= 8))
#define bswap_16(x) __builtin_bswap16(x)
#define bswap_32(x) __builtin_bswap32(x)
#define bswap_64(x) __builtin_bswap64(x)
#else
#define bswap_16(x) (((x) & 0x00ff) << 8 | ((x) & 0xff00) >> 8)
#define bswap_32(x) \
     ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
      (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
STATIC_INLINE uint64_t ByteSwap64(uint64_t x)
{
    uint32_t high = (uint32_t) (x >> 32);
    uint32_t low  = (uint32_t)  x;
    return  ((uint64_t) bswap_32 (high)) |
           (((uint64_t) bswap_32 (low)) << 32);
}
#define bswap_64(x) ByteSwap64(x)
#endif

#ifdef __cplusplus
}
#endif

#endif
