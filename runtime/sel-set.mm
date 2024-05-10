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
 *
 */

/*
 * code-sel-set.h
 * A cut-down copy of CFSet used for SEL uniquing.
 */


// NOTE: even on a 64-bit system, the implementation is still limited
// to 32-bit integers (like, the count), but SEL can be any size.

#include <stdint.h>
#include "code-private.h"
#include "code-sel-set.h"

#if !__CODE__


#if !SUPPORT_MOD
// mod-free power of 2 version

#define CONSTRAIN(val, range) ((val) & ((range)-1))
#define SIZE 27

static const uint32_t __code_sel_set_capacities[SIZE+1] = {
    3, 6, 12, 24, 48,  96, 192, 384,  768, 1536, 3072, 6144, 12288, 24576, 
    49152,  98304, 196608, 393216,  786432, 1572864, 3145728, 6291456, 
    12582912, 25165824, 50331648, 100663296, 201326592, UINT32_MAX
};

static const uint32_t __code_sel_set_buckets[SIZE] = {    // powers of 2
    4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
    65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 
    16777216, 33554432, 67108864, 134217728, 268435456
};

#else
// prime version

#define CONSTRAIN(val, range) ((val) % (range))
#define SIZE 42

static const uint32_t __code_sel_set_capacities[SIZE+1] = {
    4,  8, 17, 29, 47,  76, 123, 199, 322, 521,  843, 1364, 2207, 3571, 
    5778,  9349, 15127, 24476, 39603,  64079, 103682, 167761, 271443, 
    439204,  710647, 1149851, 1860498, 3010349, 4870847,  7881196, 12752043, 
    20633239, 33385282, 54018521,  87403803, 141422324, 228826127, 370248451, 
    599074578,  969323029, 1568397607, 2537720636U, UINT32_MAX
};

static const uint32_t __code_sel_set_buckets[SIZE] = {    // primes
    5, 11, 23, 41, 67, 113, 199, 317, 521, 839, 1361, 2207, 3571, 5779, 
    9349, 15121, 24473, 39607, 64081, 103681, 167759, 271429, 439199, 
    710641, 1149857, 1860503, 3010349, 4870843, 7881193, 12752029, 20633237, 
    33385273, 54018521, 87403763, 141422317, 228826121, 370248451, 599074561, 
    969323023, 1568397599, 2537720629U, 4106118251U
};

#endif

struct __code_sel_set {
    uint32_t _count;            /* number of slots used */
    uint32_t _capacity;         /* maximum number of used slots */
    uint32_t _bucketsNum;       /* number of slots */
    SEL *_buckets;              /* can be NULL if not allocated yet */
};

struct __code_sel_set_finds {
    SEL match;
    uint32_t nomatch;
};

// candidate may not be 0; match is 0 if not present
static struct __code_sel_set_finds __code_sel_set_findBuckets(struct __code_sel_set *sset, SEL candidate) {
    struct __code_sel_set_finds ret = {0, 0xffffffff};
    uint32_t probe = CONSTRAIN((uint32_t)_code_strhash((const char *)candidate), sset->_bucketsNum);
    for (;;) {
        SEL currentSel = sset->_buckets[probe];
        if (!currentSel) {
            ret.nomatch = probe;
            return ret;
        } else if (!ret.match && 0 == strcmp((const char *)currentSel, (const char *)candidate)) {
            ret.match = currentSel;
        }
        probe++;
        if (sset->_bucketsNum <= probe) {
            probe -= sset->_bucketsNum;
        }
    }
}

// create a set with given starting capacity, will resize as needed
struct __code_sel_set *__code_sel_set_create(size_t selrefs) {
    uint32_t idx;

    struct __code_sel_set *sset = (struct __code_sel_set *)
        malloc(sizeof(struct __code_sel_set));
    if (!sset) _code_fatal("code_sel_set failure");
    sset->_count = 0;

    // heuristic to convert executable's selrefs count to table size
#if TARGET_OS_IPHONE
    for (idx = 0; __code_sel_set_capacities[idx] < selrefs; idx++);
    if (idx > 0 && selrefs < 1536) idx--;
#else
    if (selrefs < 1024) selrefs = 1024;
    for (idx = 0; __code_sel_set_capacities[idx] < selrefs; idx++);
    idx++;
#endif

    if (SIZE <= idx) _code_fatal("code_sel_set failure");
    sset->_capacity = __code_sel_set_capacities[idx];
    sset->_bucketsNum = __code_sel_set_buckets[idx];
    sset->_buckets = (SEL *)calloc(sset->_bucketsNum, sizeof(SEL));
    if (!sset->_buckets) _code_fatal("code_sel_set failure");
    return sset;
}

// returns 0 on failure; candidate may not be 0
SEL __code_sel_set_get(struct __code_sel_set *sset, SEL candidate) {
    return __code_sel_set_findBuckets(sset, candidate).match;
}

// value may not be 0; should not be called unless it is known the value is not in the set
void __code_sel_set_add(struct __code_sel_set *sset, SEL value) {
    if (sset->_count == sset->_capacity) {
        SEL *oldbuckets = sset->_buckets;
        uint32_t oldnbuckets = sset->_bucketsNum;
        uint32_t idx, capacity = sset->_count + 1;
        for (idx = 0; __code_sel_set_capacities[idx] < capacity; idx++);
        if (SIZE <= idx) _code_fatal("code_sel_set failure");
        sset->_capacity = __code_sel_set_capacities[idx];
        sset->_bucketsNum = __code_sel_set_buckets[idx];
        sset->_buckets = (SEL *)
            calloc(sset->_bucketsNum, sizeof(SEL));
        if (!sset->_buckets) _code_fatal("code_sel_set failure");
        for (idx = 0; idx < oldnbuckets; idx++) {
            SEL currentSel = oldbuckets[idx];
            if (currentSel) {
                uint32_t nomatch = __code_sel_set_findBuckets(sset, currentSel).nomatch;
                sset->_buckets[nomatch] = currentSel;
            }
        }
        free(oldbuckets);
    }
    {
        uint32_t nomatch = __code_sel_set_findBuckets(sset, value).nomatch;
        sset->_buckets[nomatch] = value;
        sset->_count++;
    }
}


// !__CODE__
#endif
