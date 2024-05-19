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

#ifndef LANGUAGE_SERIALIZE_H
#define LANGUAGE_SERIALIZE_H

#ifdef __cplusplus
extern "C" {
#endif

#define TAG_SYMBOL              2
#define TAG_SSAVALUE            3
#define TAG_DATATYPE            4
#define TAG_SLOTNUMBER          5
#define TAG_SVEC                6
#define TAG_ARRAY               7
#define TAG_NULL                8
#define TAG_EXPR                9
#define TAG_PHINODE            10
#define TAG_PHICNODE           11
#define TAG_LONG_SYMBOL        12
#define TAG_LONG_SVEC          13
#define TAG_LONG_EXPR          14
#define TAG_LONG_PHINODE       15
#define TAG_LONG_PHICNODE      16
#define TAG_METHODROOT         17
#define TAG_STRING             18
#define TAG_SHORT_INT64        19
#define TAG_SHORT_GENERAL      20
#define TAG_CNULL              21
#define TAG_ARRAY1D            22
#define TAG_SINGLETON          23
#define TAG_MODULE             24
#define TAG_TVAR               25
#define TAG_METHOD_INSTANCE    26
#define TAG_METHOD             27
#define TAG_CODE_INSTANCE      28
#define TAG_COMMONSYM          29
#define TAG_NEARBYGLOBAL       30
#define TAG_GLOBALREF          31
#define TAG_CORE               32
#define TAG_BASE               33
#define TAG_BITYPENAME         34
#define TAG_NEARBYMODULE       35
#define TAG_INT32              36
#define TAG_INT64              37
#define TAG_UINT8              38
#define TAG_VECTORTY           39
#define TAG_PTRTY              40
#define TAG_LONG_SSAVALUE      41
#define TAG_LONG_METHODROOT    42
#define TAG_SHORTER_INT64      43
#define TAG_SHORT_INT32        44
#define TAG_CALL1              45
#define TAG_CALL2              46
#define TAG_SHORT_BACKREF      47
#define TAG_BACKREF            48
#define TAG_UNIONALL           49
#define TAG_GOTONODE           50
#define TAG_QUOTENODE          51
#define TAG_GENERAL            52
#define TAG_GOTOIFNOT          53
#define TAG_RETURNNODE         54
#define TAG_ARGUMENT           55
#define TAG_RELOC_METHODROOT   56
#define TAG_BINDING            57
#define TAG_MEMORYT            58
#define TAG_ENTERNODE          59

#define LAST_TAG 59

#define write_uint8(s, n) ios_putc((n), (s))
#define read_uint8(s) ((uint8_t)ios_getc((s)))
#define write_int8(s, n) write_uint8((s), (n))
#define read_int8(s) read_uint8((s))

/* read and write in host byte order */

static inline void write_int32(ios_t *s, int32_t i) LANGUAGE_NOTSAFEPOINT
{
    ios_write(s, (char*)&i, 4);
}

static inline int32_t read_int32(ios_t *s) LANGUAGE_NOTSAFEPOINT
{
    int32_t x = 0;
    ios_read(s, (char*)&x, 4);
    return x;
}

static inline uint64_t read_uint64(ios_t *s) LANGUAGE_NOTSAFEPOINT
{
    uint64_t x = 0;
    ios_read(s, (char*)&x, 8);
    return x;
}

static inline void write_uint64(ios_t *s, uint64_t i) LANGUAGE_NOTSAFEPOINT
{
    ios_write(s, (char*)&i, 8);
}

static inline void write_uint16(ios_t *s, uint16_t i) LANGUAGE_NOTSAFEPOINT
{
    ios_write(s, (char*)&i, 2);
}

static inline uint16_t read_uint16(ios_t *s) LANGUAGE_NOTSAFEPOINT
{
    int16_t x = 0;
    ios_read(s, (char*)&x, 2);
    return x;
}

static inline void write_uint32(ios_t *s, uint32_t i) LANGUAGE_NOTSAFEPOINT
{
    ios_write(s, (char*)&i, 4);
}

static inline uint32_t read_uint32(ios_t *s) LANGUAGE_NOTSAFEPOINT
{
    uint32_t x = 0;
    ios_read(s, (char*)&x, 4);
    return x;
}

#ifdef _P64
#define write_uint(s, i) write_uint64(s, i)
#else
#define write_uint(s, i) write_uint32(s, i)
#endif

#ifdef _P64
#define read_uint(s) read_uint64(s)
#else
#define read_uint(s) read_uint32(s)
#endif


void *language_lookup_ser_tag(language_value_t *v);
void *language_lookup_common_symbol(language_value_t *v);
language_value_t *language_deser_tag(uint8_t tag);
language_value_t *language_deser_symbol(uint8_t tag);

#ifdef __cplusplus
}
#endif

#endif /* LANGUAGE_SERIALIZE_H */
