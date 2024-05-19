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

// This is in implementation of the Julia intrinsic functions against boxed types
// excluding the native function call interface (ccall, llvmcall)
//
// this file assumes a little-endian processor, although that isn't too hard to fix
// it also assumes two's complement negative numbers, which might be a bit harder to fix

#include "APInt-C.h"
#include "code.h"
#include "language_internal.h"
#include "llvm-version.h"

const unsigned int host_char_bit = 8;

// float16 conversion helpers

static inline float half_to_float(uint16_t ival) LANGUAGE_NOTSAFEPOINT
{
    uint32_t sign = (ival & 0x8000) >> 15;
    uint32_t exp = (ival & 0x7c00) >> 10;
    uint32_t sig = (ival & 0x3ff) >> 0;
    uint32_t ret;

    if (exp == 0) {
        if (sig == 0) {
            sign = sign << 31;
            ret = sign | exp | sig;
        }
        else {
            int n_bit = 1;
            uint16_t bit = 0x0200;
            while ((bit & sig) == 0) {
                n_bit = n_bit + 1;
                bit = bit >> 1;
            }
            sign = sign << 31;
            exp = ((-14 - n_bit + 127) << 23);
            sig = ((sig & (~bit)) << n_bit) << (23 - 10);
            ret = sign | exp | sig;
        }
    }
    else if (exp == 0x1f) {
        if (sig == 0) { // Inf
            if (sign == 0)
                ret = 0x7f800000;
            else
                ret = 0xff800000;
        }
        else // NaN
            ret = 0x7fc00000 | (sign << 31) | (sig << (23 - 10));
    }
    else {
        sign = sign << 31;
        exp = ((exp - 15 + 127) << 23);
        sig = sig << (23 - 10);
        ret = sign | exp | sig;
    }

    float fret;
    memcpy(&fret, &ret, sizeof(float));
    return fret;
}

// float to half algorithm from:
//   "Fast Half Float Conversion" by Jeroen van der Zijp
//   ftp://ftp.fox-toolkit.org/pub/fasthalffloatconversion.pdf
//
// With adjustments for round-to-nearest, ties to even.

static uint16_t basetable[512] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0400, 0x0800, 0x0c00, 0x1000, 0x1400, 0x1800, 0x1c00, 0x2000,
    0x2400, 0x2800, 0x2c00, 0x3000, 0x3400, 0x3800, 0x3c00, 0x4000, 0x4400, 0x4800, 0x4c00,
    0x5000, 0x5400, 0x5800, 0x5c00, 0x6000, 0x6400, 0x6800, 0x6c00, 0x7000, 0x7400, 0x7800,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00, 0x7c00,
    0x7c00, 0x7c00, 0x7c00, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
    0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8400, 0x8800, 0x8c00, 0x9000, 0x9400,
    0x9800, 0x9c00, 0xa000, 0xa400, 0xa800, 0xac00, 0xb000, 0xb400, 0xb800, 0xbc00, 0xc000,
    0xc400, 0xc800, 0xcc00, 0xd000, 0xd400, 0xd800, 0xdc00, 0xe000, 0xe400, 0xe800, 0xec00,
    0xf000, 0xf400, 0xf800, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00,
    0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00, 0xfc00};

static uint8_t shifttable[512] = {
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0f,
    0x0e, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0d, 0x0d, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x0d, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13,
    0x12, 0x11, 0x10, 0x0f, 0x0e, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0d};

static inline uint16_t float_to_half(float param) LANGUAGE_NOTSAFEPOINT
{
    uint32_t f;
    memcpy(&f, &param, sizeof(float));
    if (isnan(param)) {
        uint32_t t = 0x8000 ^ (0x8000 & ((uint16_t)(f >> 0x10)));
        return t ^ ((uint16_t)(f >> 0xd));
    }
    int i = ((f & ~0x007fffff) >> 23);
    uint8_t sh = shifttable[i];
    f &= 0x007fffff;
    // If `val` is subnormal, the tables are set up to force the
    // result to 0, so the significand has an implicit `1` in the
    // cases we care about.
    f |= 0x007fffff + 0x1;
    uint16_t h = (uint16_t)(basetable[i] + ((f >> sh) & 0x03ff));
    // round
    // NOTE: we maybe should ignore NaNs here, but the payload is
    // getting truncated anyway so "rounding" it might not matter
    int nextbit = (f >> (sh - 1)) & 1;
    if (nextbit != 0 && (h & 0x7C00) != 0x7C00) {
        // Round halfway to even or check lower bits
        if ((h & 1) == 1 || (f & ((1 << (sh - 1)) - 1)) != 0)
            h += UINT16_C(1);
    }
    return h;
}

static inline uint16_t double_to_half(double param) LANGUAGE_NOTSAFEPOINT
{
    float temp = (float)param;
    uint32_t tempi;
    memcpy(&tempi, &temp, sizeof(temp));

    // if Float16(res) is subnormal
    if ((tempi&0x7fffffffu) < 0x38800000u) {
        // shift so that the mantissa lines up where it would for normal Float16
        uint32_t shift = 113u-((tempi & 0x7f800000u)>>23u);
        if (shift<23u) {
            tempi |= 0x00800000; // set implicit bit
            tempi >>= shift;
        }
    }

    // if we are halfway between 2 Float16 values
    if ((tempi & 0x1fffu) == 0x1000u) {
        memcpy(&tempi, &temp, sizeof(temp));
        // adjust the value by 1 ULP in the direction that will make Float16(temp) give the right answer
        tempi += (fabs(temp) < fabs(param)) - (fabs(param) < fabs(temp));
        memcpy(&temp, &tempi, sizeof(temp));
    }

    return float_to_half(temp);
}

// x86-specific helpers for emulating the (B)Float16 ABI
#if defined(_CPU_X86_) || defined(_CPU_X86_64_)
#include <xmmintrin.h>
__attribute__((unused)) static inline __m128 return_in_xmm(uint16_t input) LANGUAGE_NOTSAFEPOINT {
    __m128 xmm_output;
    asm (
        "movd %[input], %%xmm0\n\t"
        "movss %%xmm0, %[xmm_output]\n\t"
        : [xmm_output] "=x" (xmm_output)
        : [input] "r" ((uint32_t)input)
        : "xmm0"
    );
    return xmm_output;
}
__attribute__((unused)) static inline uint16_t take_from_xmm(__m128 xmm_input) LANGUAGE_NOTSAFEPOINT {
    uint32_t output;
    asm (
        "movss %[xmm_input], %%xmm0\n\t"
        "movd %%xmm0, %[output]\n\t"
        : [output] "=r" (output)
        : [xmm_input] "x" (xmm_input)
        : "xmm0"
    );
    return (uint16_t)output;
}
#endif

// float16 conversion API

// for use in APInt and other soft-float ABIs (i.e. without the ABI shenanigans from below)
LANGUAGE_DLLEXPORT uint16_t language_float_to_half(float param) {
    return float_to_half(param);
}
LANGUAGE_DLLEXPORT uint16_t language_double_to_half(double param) {
    return double_to_half(param);
}
LANGUAGE_DLLEXPORT float language_half_to_float(uint16_t param) {
    return half_to_float(param);
}

// starting with GCC 12 and Clang 15, we have _Float16 on most platforms
// (but not on Windows; this may be a bug in the MSYS2 GCC compilers)
#if ((defined(__GNUC__) && __GNUC__ > 11) || \
     (defined(__clang__) && __clang_major__ > 14)) && \
    !defined(_CPU_PPC64_) && !defined(_CPU_PPC_) && \
    !defined(_OS_WINDOWS_)
    #define FLOAT16_TYPE _Float16
    #define FLOAT16_TO_UINT16(x) (*(uint16_t*)&(x))
    #define FLOAT16_FROM_UINT16(x) (*(_Float16*)&(x))
// on older compilers, we need to emulate the platform-specific ABI
#elif defined(_CPU_X86_) || (defined(_CPU_X86_64_) && !defined(_OS_WINDOWS_))
    // on x86, we can use __m128; except on Windows where x64 calling
    // conventions expect to pass __m128 by reference.
    #define FLOAT16_TYPE __m128
    #define FLOAT16_TO_UINT16(x) take_from_xmm(x)
    #define FLOAT16_FROM_UINT16(x) return_in_xmm(x)
#elif defined(_CPU_PPC64_) || defined(_CPU_PPC_)
    // on PPC, pass Float16 as if it were an integer, similar to the old x86 ABI
    // before _Float16
    #define FLOAT16_TYPE uint16_t
    #define FLOAT16_TO_UINT16(x) (x)
    #define FLOAT16_FROM_UINT16(x) (x)
#else
    // otherwise, pass using floating-point calling conventions
    #define FLOAT16_TYPE float
    #define FLOAT16_TO_UINT16(x) ((uint16_t)*(uint32_t*)&(x))
    #define FLOAT16_FROM_UINT16(x) ({ uint32_t tmp = (uint32_t)(x); *(float*)&tmp; })
#endif

LANGUAGE_DLLEXPORT float language__gnu_h2f_ieee(FLOAT16_TYPE param)
{
    uint16_t param16 = FLOAT16_TO_UINT16(param);
    return half_to_float(param16);
}

LANGUAGE_DLLEXPORT FLOAT16_TYPE language__gnu_f2h_ieee(float param)
{
    uint16_t res = float_to_half(param);
    return FLOAT16_FROM_UINT16(res);
}

LANGUAGE_DLLEXPORT FLOAT16_TYPE language__truncdfhf2(double param)
{
    uint16_t res = double_to_half(param);
    return FLOAT16_FROM_UINT16(res);
}


// bfloat16 conversion helpers

static inline uint16_t float_to_bfloat(float param) LANGUAGE_NOTSAFEPOINT
{
    if (isnan(param))
        return 0x7fc0;

    uint32_t bits = *((uint32_t*) &param);

    // round to nearest even
    bits += 0x7fff + ((bits >> 16) & 1);
    return (uint16_t)(bits >> 16);
}

static inline uint16_t double_to_bfloat(double param) LANGUAGE_NOTSAFEPOINT
{
    float temp = (float)param;
    uint32_t tempi;
    memcpy(&tempi, &temp, sizeof(temp));

    // bfloat16 uses the same exponent as float32, so we don't need special handling
    // for subnormals when truncating float64 to bfloat16.

    // if we are halfway between 2 bfloat16 values
    if ((tempi & 0x1ffu) == 0x100u) {
        // adjust the value by 1 ULP in the direction that will make bfloat16(temp) give the right answer
        tempi += (fabs(temp) < fabs(param)) - (fabs(param) < fabs(temp));
        memcpy(&temp, &tempi, sizeof(temp));
    }

    return float_to_bfloat(temp);
}

static inline float bfloat_to_float(uint16_t param) LANGUAGE_NOTSAFEPOINT
{
    uint32_t bits = ((uint32_t)param) << 16;
    float result;
    memcpy(&result, &bits, sizeof(result));
    return result;
}

// bfloat16 conversion API

// for use in APInt (without the ABI shenanigans from below)
uint16_t language_float_to_bfloat(float param) {
    return float_to_bfloat(param);
}
float language_bfloat_to_float(uint16_t param) {
    return bfloat_to_float(param);
}

// starting with GCC 13 and Clang 17, we have __bf16 on most platforms
// (but not on Windows; this may be a bug in the MSYS2 GCC compilers)
#if ((defined(__GNUC__) && __GNUC__ > 12) || \
     (defined(__clang__) && __clang_major__ > 16)) && \
    !defined(_CPU_PPC64_) && !defined(_CPU_PPC_) && \
    !defined(_OS_WINDOWS_)
    #define BFLOAT16_TYPE __bf16
    #define BFLOAT16_TO_UINT16(x) (*(uint16_t*)&(x))
    #define BFLOAT16_FROM_UINT16(x) (*(__bf16*)&(x))
// on older compilers, we need to emulate the platform-specific ABI.
// for more details, see similar code above that deals with Float16.
#elif defined(_CPU_X86_) || (defined(_CPU_X86_64_) && !defined(_OS_WINDOWS_))
    #define BFLOAT16_TYPE __m128
    #define BFLOAT16_TO_UINT16(x) take_from_xmm(x)
    #define BFLOAT16_FROM_UINT16(x) return_in_xmm(x)
#elif defined(_CPU_PPC64_) || defined(_CPU_PPC_)
    #define BFLOAT16_TYPE uint16_t
    #define BFLOAT16_TO_UINT16(x) (x)
    #define BFLOAT16_FROM_UINT16(x) (x)
#else
    #define BFLOAT16_TYPE float
    #define BFLOAT16_TO_UINT16(x) ((uint16_t)*(uint32_t*)&(x))
    #define BFLOAT16_FROM_UINT16(x) ({ uint32_t tmp = (uint32_t)(x); *(float*)&tmp; })
#endif

LANGUAGE_DLLEXPORT BFLOAT16_TYPE language__truncsfbf2(float param) LANGUAGE_NOTSAFEPOINT
{
    uint16_t res = float_to_bfloat(param);
    return BFLOAT16_FROM_UINT16(res);
}

LANGUAGE_DLLEXPORT BFLOAT16_TYPE language__truncdfbf2(double param) LANGUAGE_NOTSAFEPOINT
{
    uint16_t res = double_to_bfloat(param);
    return BFLOAT16_FROM_UINT16(res);
}


// run time version of bitcast intrinsic
LANGUAGE_DLLEXPORT language_value_t *language_bitcast(language_value_t *ty, language_value_t *v)
{
    LANGUAGE_TYPECHK(bitcast, datatype, ty);
    if (!language_is_concrete_type(ty) || !language_is_primitivetype(ty))
        language_error("bitcast: target type not a leaf primitive type");
    if (!language_is_primitivetype(language_typeof(v)))
        language_error("bitcast: value not a primitive type");
    if (language_datatype_size(language_typeof(v)) != language_datatype_size(ty))
        language_error("bitcast: argument size does not match size of target type");
    if (ty == language_typeof(v))
        return v;
    if (ty == (language_value_t*)language_bool_type)
        return *(uint8_t*)language_data_ptr(v) & 1 ? language_true : language_false;
    return language_new_bits(ty, language_data_ptr(v));
}

// run time version of pointerref intrinsic (warning: i is not rooted)
LANGUAGE_DLLEXPORT language_value_t *language_pointerref(language_value_t *p, language_value_t *i, language_value_t *align)
{
    LANGUAGE_TYPECHK(pointerref, pointer, p);
    LANGUAGE_TYPECHK(pointerref, long, i)
    LANGUAGE_TYPECHK(pointerref, long, align);
    language_value_t *ety = language_tparam0(language_typeof(p));
    if (ety == (language_value_t*)language_any_type) {
        language_value_t **pp = (language_value_t**)(language_unbox_long(p) + (language_unbox_long(i)-1)*sizeof(void*));
        return *pp;
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("pointerref: invalid pointer");
        size_t nb = LLT_ALIGN(language_datatype_size(ety), language_datatype_align(ety));
        char *pp = (char*)language_unbox_long(p) + (language_unbox_long(i)-1)*nb;
        return language_new_bits(ety, pp);
    }
}

// run time version of pointerset intrinsic (warning: x is not gc-rooted)
LANGUAGE_DLLEXPORT language_value_t *language_pointerset(language_value_t *p, language_value_t *x, language_value_t *i, language_value_t *align)
{
    LANGUAGE_TYPECHK(pointerset, pointer, p);
    LANGUAGE_TYPECHK(pointerset, long, i);
    LANGUAGE_TYPECHK(pointerset, long, align);
    language_value_t *ety = language_tparam0(language_typeof(p));
    if (ety == (language_value_t*)language_any_type) {
        language_value_t **pp = (language_value_t**)(language_unbox_long(p) + (language_unbox_long(i)-1)*sizeof(void*));
        *pp = x;
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("pointerset: invalid pointer");
        if (language_typeof(x) != ety)
            language_type_error("pointerset", ety, x);
        size_t elsz = language_datatype_size(ety);
        size_t nb = LLT_ALIGN(elsz, language_datatype_align(ety));
        char *pp = (char*)language_unbox_long(p) + (language_unbox_long(i)-1)*nb;
        memcpy(pp, x, elsz);
    }
    return p;
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerref(language_value_t *p, language_value_t *order)
{
    LANGUAGE_TYPECHK(atomic_pointerref, pointer, p);
    LANGUAGE_TYPECHK(atomic_pointerref, symbol, order)
    (void)language_get_atomic_order_checked((language_sym_t*)order, 1, 0);
    language_value_t *ety = language_tparam0(language_typeof(p));
    char *pp = (char*)language_unbox_long(p);
    if (ety == (language_value_t*)language_any_type) {
        return language_atomic_load((_Atomic(language_value_t*)*)pp);
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("atomic_pointerref: invalid pointer");
        size_t nb = language_datatype_size(ety);
        if ((nb & (nb - 1)) != 0 || nb > MAX_POINTERATOMIC_SIZE)
            language_error("atomic_pointerref: invalid pointer for atomic operation");
        return language_atomic_new_bits(ety, pp);
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerset(language_value_t *p, language_value_t *x, language_value_t *order)
{
    LANGUAGE_TYPECHK(atomic_pointerset, pointer, p);
    LANGUAGE_TYPECHK(atomic_pointerset, symbol, order);
    (void)language_get_atomic_order_checked((language_sym_t*)order, 0, 1);
    language_value_t *ety = language_tparam0(language_typeof(p));
    char *pp = (char*)language_unbox_long(p);
    if (ety == (language_value_t*)language_any_type) {
        language_atomic_store((_Atomic(language_value_t*)*)pp, x);
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("atomic_pointerset: invalid pointer");
        if (language_typeof(x) != ety)
            language_type_error("atomic_pointerset", ety, x);
        size_t nb = language_datatype_size(ety);
        if ((nb & (nb - 1)) != 0 || nb > MAX_POINTERATOMIC_SIZE)
            language_error("atomic_pointerset: invalid pointer for atomic operation");
        language_atomic_store_bits(pp, x, nb);
    }
    return p;
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerswap(language_value_t *p, language_value_t *x, language_value_t *order)
{
    LANGUAGE_TYPECHK(atomic_pointerswap, pointer, p);
    LANGUAGE_TYPECHK(atomic_pointerswap, symbol, order);
    (void)language_get_atomic_order_checked((language_sym_t*)order, 1, 1);
    language_value_t *ety = language_tparam0(language_typeof(p));
    language_value_t *y;
    char *pp = (char*)language_unbox_long(p);
    if (ety == (language_value_t*)language_any_type) {
        y = language_atomic_exchange((_Atomic(language_value_t*)*)pp, x);
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("atomic_pointerswap: invalid pointer");
        if (language_typeof(x) != ety)
            language_type_error("atomic_pointerswap", ety, x);
        size_t nb = language_datatype_size(ety);
        if ((nb & (nb - 1)) != 0 || nb > MAX_POINTERATOMIC_SIZE)
            language_error("atomic_pointerswap: invalid pointer for atomic operation");
        y = language_atomic_swap_bits(ety, pp, x, nb);
    }
    return y;
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointermodify(language_value_t *p, language_value_t *f, language_value_t *x, language_value_t *order)
{
    LANGUAGE_TYPECHK(atomic_pointermodify, pointer, p);
    LANGUAGE_TYPECHK(atomic_pointermodify, symbol, order)
    (void)language_get_atomic_order_checked((language_sym_t*)order, 1, 1);
    language_value_t *ety = language_tparam0(language_typeof(p));
    char *pp = (char*)language_unbox_long(p);
    language_value_t *expected;
    if (ety == (language_value_t*)language_any_type) {
        expected = language_atomic_load((_Atomic(language_value_t*)*)pp);
    }
    else {
        if (!is_valid_intrinsic_elptr(ety))
            language_error("atomic_pointermodify: invalid pointer");
        size_t nb = language_datatype_size(ety);
        if ((nb & (nb - 1)) != 0 || nb > MAX_POINTERATOMIC_SIZE)
            language_error("atomic_pointermodify: invalid pointer for atomic operation");
        expected = language_atomic_new_bits(ety, pp);
    }
    language_value_t **args;
    LANGUAGE_GC_PUSHARGS(args, 2);
    args[0] = expected;
    while (1) {
        args[1] = x;
        language_value_t *y = language_apply_generic(f, args, 2);
        args[1] = y;
        if (ety == (language_value_t*)language_any_type) {
            if (language_atomic_cmpswap((_Atomic(language_value_t*)*)pp, &expected, y))
                break;
        }
        else {
            //if (!is_valid_intrinsic_elptr(ety)) // handled by language_atomic_pointerref earlier
            //    language_error("atomic_pointermodify: invalid pointer");
            if (language_typeof(y) != ety)
                language_type_error("atomic_pointermodify", ety, y);
            size_t nb = language_datatype_size(ety);
            if (language_atomic_bool_cmpswap_bits(pp, expected, y, nb))
                break;
            expected = language_atomic_new_bits(ety, pp);
        }
        args[0] = expected;
        language_gc_safepoint();
    }
    // args[0] == expected (old)
    // args[1] == y (new)
    language_datatype_t *rettyp = language_apply_modify_type(ety);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    args[0] = language_new_struct(rettyp, args[0], args[1]);
    LANGUAGE_GC_POP();
    return args[0];
}


LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerreplace(language_value_t *p, language_value_t *expected, language_value_t *x, language_value_t *success_order_sym, language_value_t *failure_order_sym)
{
    LANGUAGE_TYPECHK(atomic_pointerreplace, pointer, p);
    LANGUAGE_TYPECHK(atomic_pointerreplace, symbol, success_order_sym);
    LANGUAGE_TYPECHK(atomic_pointerreplace, symbol, failure_order_sym);
    enum language_memory_order success_order = language_get_atomic_order_checked((language_sym_t*)success_order_sym, 1, 1);
    enum language_memory_order failure_order = language_get_atomic_order_checked((language_sym_t*)failure_order_sym, 1, 0);
    if (failure_order > success_order)
        language_atomic_error("atomic_pointerreplace: invalid atomic ordering");
    // TODO: filter other invalid orderings
    language_value_t *ety = language_tparam0(language_typeof(p));
    if (!is_valid_intrinsic_elptr(ety))
        language_error("atomic_pointerreplace: invalid pointer");
    char *pp = (char*)language_unbox_long(p);
    language_datatype_t *rettyp = language_apply_cmpswap_type(ety);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    language_value_t *result = NULL;
    LANGUAGE_GC_PUSH1(&result);
    if (ety == (language_value_t*)language_any_type) {
        result = expected;
        int success;
        while (1) {
            success = language_atomic_cmpswap((_Atomic(language_value_t*)*)pp, &result, x);
            if (success || !language_egal(result, expected))
                break;
        }
        result = language_new_struct(rettyp, result, success ? language_true : language_false);
    }
    else {
        if (language_typeof(x) != ety)
            language_type_error("atomic_pointerreplace", ety, x);
        size_t nb = language_datatype_size(ety);
        if ((nb & (nb - 1)) != 0 || nb > MAX_POINTERATOMIC_SIZE)
            language_error("atomic_pointerreplace: invalid pointer for atomic operation");
        int isptr = language_field_isptr(rettyp, 0);
        language_task_t *ct = language_current_task;
        result = language_gc_alloc(ct->ptls, isptr ? nb : language_datatype_size(rettyp), isptr ? ety : (language_value_t*)rettyp);
        int success = language_atomic_cmpswap_bits((language_datatype_t*)ety, result, pp, expected, x, nb);
        if (isptr) {
            language_value_t *z = language_gc_alloc(ct->ptls, language_datatype_size(rettyp), rettyp);
            *(language_value_t**)z = result;
            result = z;
            nb = sizeof(language_value_t*);
        }
        *((uint8_t*)result + nb) = success ? 1 : 0;
    }
    LANGUAGE_GC_POP();
    return result;
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_fence(language_value_t *order_sym)
{
    LANGUAGE_TYPECHK(fence, symbol, order_sym);
    enum language_memory_order order = language_get_atomic_order_checked((language_sym_t*)order_sym, 1, 1);
    if (order > language_memory_order_monotonic)
        language_fence();
    return language_nothing;
}

LANGUAGE_DLLEXPORT language_value_t *language_cglobal(language_value_t *v, language_value_t *ty)
{
    LANGUAGE_TYPECHK(cglobal, type, ty);
    LANGUAGE_GC_PUSH1(&v);
    language_value_t *rt =
        ty == (language_value_t*)language_nothing_type ? (language_value_t*)language_voidpointer_type : // a common case
            (language_value_t*)language_apply_type1((language_value_t*)language_pointer_type, ty);
    LANGUAGE_GC_PROMISE_ROOTED(rt); // (LANGUAGE_ALWAYS_LEAFTYPE)

    if (!language_is_concrete_type(rt))
        language_error("cglobal: type argument not concrete");

    if (language_is_tuple(v) && language_nfields(v) == 1)
        v = language_fieldref(v, 0);

    if (language_is_pointer(v)) {
        v = language_bitcast(rt, v);
        LANGUAGE_GC_POP();
        return v;
    }

    char *f_lib = NULL;
    if (language_is_tuple(v) && language_nfields(v) > 1) {
        language_value_t *t1 = language_fieldref(v, 1);
        if (language_is_symbol(t1))
            f_lib = language_symbol_name((language_sym_t*)t1);
        else if (language_is_string(t1))
            f_lib = language_string_data(t1);
        else
            LANGUAGE_TYPECHK(cglobal, symbol, t1)
        v = language_fieldref(v, 0);
    }

    char *f_name = NULL;
    if (language_is_symbol(v))
        f_name = language_symbol_name((language_sym_t*)v);
    else if (language_is_string(v))
        f_name = language_string_data(v);
    else
        LANGUAGE_TYPECHK(cglobal, symbol, v)

    if (!f_lib)
        f_lib = (char*)language_dlfind(f_name);

    void *ptr;
    language_dlsym(language_get_library(f_lib), f_name, &ptr, 1);
    language_value_t *jv = language_gc_alloc_1w();
    language_set_typeof(jv, rt);
    *(void**)language_data_ptr(jv) = ptr;
    LANGUAGE_GC_POP();
    return jv;
}

LANGUAGE_DLLEXPORT language_value_t *language_cglobal_auto(language_value_t *v) {
    return language_cglobal(v, (language_value_t*)language_nothing_type);
}

static inline char signbitbyte(void *a, unsigned bytes) LANGUAGE_NOTSAFEPOINT
{
    // sign bit of an signed number of n bytes, as a byte
    return (((signed char*)a)[bytes - 1] < 0) ? ~0 : 0;
}

static inline char usignbitbyte(void *a, unsigned bytes) LANGUAGE_NOTSAFEPOINT
{
    // sign bit of an unsigned number
    return 0;
}

static inline unsigned select_by_size(unsigned sz) LANGUAGE_NOTSAFEPOINT
{
    /* choose the right sized function specialization */
    switch (sz) {
    default: return 0;
    case  1: return 1;
    case  2: return 2;
    case  4: return 3;
    case  8: return 4;
    case 16: return 5;
    }
}

#define SELECTOR_FUNC(intrinsic) \
    typedef intrinsic##_t select_##intrinsic##_t[6]; \
    static inline intrinsic##_t select_##intrinsic(unsigned sz, const select_##intrinsic##_t list) LANGUAGE_NOTSAFEPOINT \
    { \
        intrinsic##_t thunk = list[select_by_size(sz)]; \
        if (!thunk) thunk = list[0]; \
        return thunk; \
    }

#define fp_select(a, func) \
    sizeof(a) <= sizeof(float) ? func##f((float)a) : func(a)
#define fp_select2(a, b, func) \
    sizeof(a) <= sizeof(float) ? func##f(a, b) : func(a, b)

// fast-function generators //

// integer input
// OP::Function macro(input)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define un_iintrinsic_ctype(OP, name, nbits, c_type) \
static inline void code_##name##nbits(unsigned runtime_nbits, void *pa, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    *(c_type*)pr = OP(a); \
}

// integer input, unsigned output
// OP::Function macro(input)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define uu_iintrinsic_ctype(OP, name, nbits, c_type) \
static inline unsigned code_##name##nbits(unsigned runtime_nbits, void *pa) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    return OP(a); \
}

// floating point
// OP::Function macro(output pointer, input)
// name::unique string
// nbits::number of bits in the *input*
// c_type::c_type corresponding to nbits
#define un_fintrinsic_ctype(OP, name, c_type) \
static inline void name(unsigned osize, language_value_t *ty, void *pa, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    OP(ty, (c_type*)pr, a); \
}

#define un_fintrinsic_half(OP, name) \
static inline void name(unsigned osize, language_value_t *ty, void *pa, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    float A = half_to_float(a); \
    if (osize == 16) { \
        float R; \
        OP(ty, &R, A); \
        *(uint16_t*)pr = float_to_half(R); \
    } else { \
        OP(ty, (uint16_t*)pr, A); \
    } \
}

#define un_fintrinsic_bfloat(OP, name) \
static inline void name(unsigned osize, language_value_t *ty, void *pa, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    float A = bfloat_to_float(a); \
    if (osize == 16) { \
        float R; \
        OP(ty, &R, A); \
        *(uint16_t*)pr = float_to_bfloat(R); \
    } else { \
        OP(ty, (uint16_t*)pr, A); \
    } \
}

// float or integer inputs
// OP::Function macro(inputa, inputb)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define bi_intrinsic_ctype(OP, name, nbits, c_type) \
static void code_##name##nbits(unsigned runtime_nbits, void *pa, void *pb, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    c_type b = *(c_type*)pb; \
    *(c_type*)pr = (c_type)OP(a, b); \
}

#define bi_intrinsic_half(OP, name) \
static void code_##name##16(unsigned runtime_nbits, void *pa, void *pb, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    float A = half_to_float(a); \
    float B = half_to_float(b); \
    runtime_nbits = 16; \
    float R = OP(A, B); \
    *(uint16_t*)pr = float_to_half(R); \
    *(uint16_t*)pr = float_to_half(R); \
}

#define bi_intrinsic_bfloat(OP, name) \
static void code_##name##bf16(unsigned runtime_nbits, void *pa, void *pb, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    float A = bfloat_to_float(a); \
    float B = bfloat_to_float(b); \
    runtime_nbits = 16; \
    float R = OP(A, B); \
    *(uint16_t*)pr = float_to_bfloat(R); \
}

// float or integer inputs, bool output
// OP::Function macro(inputa, inputb)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define bool_intrinsic_ctype(OP, name, nbits, c_type) \
static int code_##name##nbits(unsigned runtime_nbits, void *pa, void *pb) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    c_type b = *(c_type*)pb; \
    return OP(a, b); \
}

#define bool_intrinsic_half(OP, name) \
static int code_##name##16(unsigned runtime_nbits, void *pa, void *pb) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    float A = half_to_float(a); \
    float B = half_to_float(b); \
    runtime_nbits = 16; \
    return OP(A, B); \
}

#define bool_intrinsic_bfloat(OP, name) \
static int code_##name##bf16(unsigned runtime_nbits, void *pa, void *pb) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    float A = bfloat_to_float(a); \
    float B = bfloat_to_float(b); \
    runtime_nbits = 16; \
    return OP(A, B); \
}


// integer inputs, with precondition test
// OP::Function macro(inputa, inputb)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define checked_intrinsic_ctype(CHECK_OP, OP, name, nbits, c_type) \
static int code_##name##nbits(unsigned runtime_nbits, void *pa, void *pb, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    c_type b = *(c_type*)pb; \
    *(c_type*)pr = (c_type)OP(a, b); \
    return CHECK_OP(c_type, a, b);    \
}

// float inputs
// OP::Function macro(inputa, inputb, inputc)
// name::unique string
// nbits::number of bits
// c_type::c_type corresponding to nbits
#define ter_intrinsic_ctype(OP, name, nbits, c_type) \
static void code_##name##nbits(unsigned runtime_nbits, void *pa, void *pb, void *pc, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    c_type a = *(c_type*)pa; \
    c_type b = *(c_type*)pb; \
    c_type c = *(c_type*)pc; \
    *(c_type*)pr = (c_type)OP(a, b, c); \
}

#define ter_intrinsic_half(OP, name) \
static void code_##name##16(unsigned runtime_nbits, void *pa, void *pb, void *pc, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    uint16_t c = *(uint16_t*)pc; \
    float A = half_to_float(a); \
    float B = half_to_float(b); \
    float C = half_to_float(c); \
    runtime_nbits = 16; \
    float R = OP(A, B, C); \
    *(uint16_t*)pr = float_to_half(R); \
    *(uint16_t*)pr = float_to_half(R); \
}

#define ter_intrinsic_bfloat(OP, name) \
static void code_##name##bf16(unsigned runtime_nbits, void *pa, void *pb, void *pc, void *pr) LANGUAGE_NOTSAFEPOINT \
{ \
    uint16_t a = *(uint16_t*)pa; \
    uint16_t b = *(uint16_t*)pb; \
    uint16_t c = *(uint16_t*)pc; \
    float A = bfloat_to_float(a); \
    float B = bfloat_to_float(b); \
    float C = bfloat_to_float(c); \
    runtime_nbits = 16; \
    float R = OP(A, B, C); \
    *(uint16_t*)pr = float_to_bfloat(R); \
}


// unary operator generator //

typedef void (*intrinsic_1_t)(unsigned, void*, void*);
SELECTOR_FUNC(intrinsic_1)
#define un_iintrinsic(name, u) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a) \
{ \
    return language_iintrinsic_1(a, #name, u##signbitbyte, language_intrinsiclambda_ty1, name##_list); \
}
#define un_iintrinsic_fast(LLVMOP, OP, name, u) \
un_iintrinsic_ctype(OP, name, 8, u##int##8_t) \
un_iintrinsic_ctype(OP, name, 16, u##int##16_t) \
un_iintrinsic_ctype(OP, name, 32, u##int##32_t) \
un_iintrinsic_ctype(OP, name, 64, u##int##64_t) \
static const select_intrinsic_1_t name##_list = { \
    LLVMOP, \
    code_##name##8, \
    code_##name##16, \
    code_##name##32, \
    code_##name##64, \
}; \
un_iintrinsic(name, u)
#define un_iintrinsic_slow(LLVMOP, name, u) \
static const select_intrinsic_1_t name##_list = { \
    LLVMOP \
}; \
un_iintrinsic(name, u)

typedef unsigned (*intrinsic_u1_t)(unsigned, void*);
SELECTOR_FUNC(intrinsic_u1)
#define uu_iintrinsic(name, u) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a) \
{ \
    return language_iintrinsic_1(a, #name, u##signbitbyte, language_intrinsiclambda_u1, name##_list); \
}
#define uu_iintrinsic_fast(LLVMOP, OP, name, u) \
uu_iintrinsic_ctype(OP, name, 8, u##int##8_t) \
uu_iintrinsic_ctype(OP, name, 16, u##int##16_t) \
uu_iintrinsic_ctype(OP, name, 32, u##int##32_t) \
uu_iintrinsic_ctype(OP, name, 64, u##int##64_t) \
static const select_intrinsic_u1_t name##_list = { \
    LLVMOP, \
    code_##name##8, \
    code_##name##16, \
    code_##name##32, \
    code_##name##64, \
}; \
uu_iintrinsic(name, u)
#define uu_iintrinsic_slow(LLVMOP, name, u) \
static const select_intrinsic_u1_t name##_list = { \
    LLVMOP \
}; \
uu_iintrinsic(name, u)

static inline
language_value_t *language_iintrinsic_1(language_value_t *a, const char *name,
                            char (*getsign)(void*, unsigned),
                            language_value_t *(*lambda1)(language_value_t*, void*, unsigned, unsigned, const void*), const void *list)
{
    language_value_t *ty = language_typeof(a);
    if (!language_is_primitivetype(ty))
        language_errorf("%s: value is not a primitive type", name);
    void *pa = language_data_ptr(a);
    unsigned isize = language_datatype_size(language_typeof(a));
    unsigned isize2 = next_power_of_two(isize);
    unsigned osize = language_datatype_size(ty);
    unsigned osize2 = next_power_of_two(osize);
    if (isize2 > osize2)
        osize2 = isize2;
    if (osize2 > isize || isize2 > isize) {
        /* if needed, round type up to a real c-type and set/clear the unused bits */
        void *pa2;
        pa2 = alloca(osize2);
        /* TODO: this memcpy assumes little-endian,
         * for big-endian, need to align the copy to the other end */ \
        memcpy(pa2, pa, isize);
        memset((char*)pa2 + isize, getsign(pa, isize), osize2 - isize);
        pa = pa2;
    }
    language_value_t *newv = lambda1(ty, pa, osize, osize2, list);
    if (ty == (language_value_t*)language_bool_type)
        return *(uint8_t*)language_data_ptr(newv) & 1 ? language_true : language_false;
    return newv;
}

static inline language_value_t *language_intrinsiclambda_ty1(language_value_t *ty, void *pa, unsigned osize, unsigned osize2, const void *voidlist)
{
    intrinsic_1_t op = select_intrinsic_1(osize2, (const intrinsic_1_t*)voidlist);
    void *pr = alloca(osize2);
    op(osize * host_char_bit, pa, pr);
    return language_new_bits(ty, pr);
}

static inline language_value_t *language_intrinsiclambda_u1(language_value_t *ty, void *pa, unsigned osize, unsigned osize2, const void *voidlist)
{
    language_task_t *ct = language_current_task;
    intrinsic_u1_t op = select_intrinsic_u1(osize2, (const intrinsic_u1_t*)voidlist);
    uint64_t cnt = op(osize * host_char_bit, pa);
    // TODO: the following assume little-endian
    // for big-endian, need to copy from the other end of cnt
    if (osize <= sizeof(cnt)) {
        return language_new_bits(ty, &cnt);
    }
    language_value_t *newv = language_gc_alloc(ct->ptls, osize, ty);
    // perform zext, if needed
    memset((char*)language_data_ptr(newv) + sizeof(cnt), 0, osize - sizeof(cnt));
    memcpy(language_data_ptr(newv), &cnt, sizeof(cnt));
    return newv;
}

// conversion operator

typedef void (*intrinsic_cvt_t)(language_datatype_t*, void*, language_datatype_t*, void*);
typedef unsigned (*intrinsic_cvt_check_t)(unsigned, unsigned, void*);
#define cvt_iintrinsic(LLVMOP, name) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *ty, language_value_t *a) \
{ \
    return language_intrinsic_cvt(ty, a, #name, LLVMOP); \
}

static inline language_value_t *language_intrinsic_cvt(language_value_t *ty, language_value_t *a, const char *name, intrinsic_cvt_t op)
{
    LANGUAGE_TYPECHKS(name, datatype, ty);
    if (!language_is_concrete_type(ty) || !language_is_primitivetype(ty))
        language_errorf("%s: target type not a leaf primitive type", name);
    language_value_t *aty = language_typeof(a);
    if (!language_is_primitivetype(aty))
        language_errorf("%s: value is not a primitive type", name);
    void *pa = language_data_ptr(a);
    unsigned osize = language_datatype_size(ty);
    void *pr = alloca(osize);
    op((language_datatype_t*)aty, pa, (language_datatype_t*)ty, pr);
    return language_new_bits(ty, pr);
}

// floating point

#define un_fintrinsic_withtype(OP, name) \
un_fintrinsic_bfloat(OP, code_##name##bf16) \
un_fintrinsic_half(OP, code_##name##16) \
un_fintrinsic_ctype(OP, code_##name##32, float) \
un_fintrinsic_ctype(OP, code_##name##64, double) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *ty, language_value_t *a) \
{ \
    return language_fintrinsic_1(ty, a, #name, code_##name##bf16, code_##name##16, code_##name##32, code_##name##64); \
}

#define un_fintrinsic(OP, name) \
un_fintrinsic_withtype(OP, name##_withtype) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a) \
{ \
    return code_##name##_withtype(language_typeof(a), a); \
}

typedef void (fintrinsic_op1)(unsigned, language_value_t*, void*, void*);

static inline language_value_t *language_fintrinsic_1(language_value_t *ty, language_value_t *a, const char *name, fintrinsic_op1 *bfloatop, fintrinsic_op1 *halfop, fintrinsic_op1 *floatop, fintrinsic_op1 *doubleop)
{
    language_task_t *ct = language_current_task;
    if (!language_is_primitivetype(language_typeof(a)))
        language_errorf("%s: value is not a primitive type", name);
    if (!language_is_primitivetype(ty))
        language_errorf("%s: type is not a primitive type", name);
    unsigned sz2 = language_datatype_size(ty);
    language_value_t *newv = language_gc_alloc(ct->ptls, sz2, ty);
    void *pa = language_data_ptr(a), *pr = language_data_ptr(newv);
    unsigned sz = language_datatype_size(language_typeof(a));
    switch (sz) {
    /* choose the right size c-type operation based on the input */
    case 2:
        if (language_typeof(a) == (language_value_t*)language_float16_type)
            halfop(sz2 * host_char_bit, ty, pa, pr);
        else /*if (language_typeof(a) == (language_value_t*)language_bfloat16_type)*/
            bfloatop(sz2 * host_char_bit, ty, pa, pr);
        break;
    case 4:
        floatop(sz2 * host_char_bit, ty, pa, pr);
        break;
    case 8:
        doubleop(sz2 * host_char_bit, ty, pa, pr);
        break;
    default:
        language_errorf("%s: runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64", name);
    }
    return newv;
}

// binary operator generator //

// integer

typedef void (*intrinsic_2_t)(unsigned, void*, void*, void*);
SELECTOR_FUNC(intrinsic_2)
#define bi_iintrinsic(name, u, cvtb) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b) \
{ \
    return language_iintrinsic_2(a, b, #name, u##signbitbyte, language_intrinsiclambda_2, name##_list, cvtb); \
}
#define bi_iintrinsic_cnvtb_fast(LLVMOP, OP, name, u, cvtb) \
bi_intrinsic_ctype(OP, name, 8, u##int##8_t) \
bi_intrinsic_ctype(OP, name, 16, u##int##16_t) \
bi_intrinsic_ctype(OP, name, 32, u##int##32_t) \
bi_intrinsic_ctype(OP, name, 64, u##int##64_t) \
static const select_intrinsic_2_t name##_list = { \
    LLVMOP, \
    code_##name##8, \
    code_##name##16, \
    code_##name##32, \
    code_##name##64, \
}; \
bi_iintrinsic(name, u, cvtb)
#define bi_iintrinsic_fast(LLVMOP, OP, name, u) \
    bi_iintrinsic_cnvtb_fast(LLVMOP, OP, name, u, 0)

typedef int (*intrinsic_cmp_t)(unsigned, void*, void*);
SELECTOR_FUNC(intrinsic_cmp)
#define cmp_iintrinsic(name, u) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b) \
{ \
    return language_iintrinsic_2(a, b, #name, u##signbitbyte, language_intrinsiclambda_cmp, name##_list, 0); \
}
#define bool_iintrinsic_fast(LLVMOP, OP, name, u) \
bool_intrinsic_ctype(OP, name, 8, u##int##8_t) \
bool_intrinsic_ctype(OP, name, 16, u##int##16_t) \
bool_intrinsic_ctype(OP, name, 32, u##int##32_t) \
bool_intrinsic_ctype(OP, name, 64, u##int##64_t) \
static const select_intrinsic_cmp_t name##_list = { \
    LLVMOP, \
    code_##name##8, \
    code_##name##16, \
    code_##name##32, \
    code_##name##64, \
}; \
cmp_iintrinsic(name, u)

typedef int (*intrinsic_checked_t)(unsigned, void*, void*, void*) LANGUAGE_NOTSAFEPOINT;
SELECTOR_FUNC(intrinsic_checked)
#define checked_iintrinsic(name, u, lambda_checked) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b) \
{ \
    return language_iintrinsic_2(a, b, #name, u##signbitbyte, lambda_checked, name##_list, 0); \
}
#define checked_iintrinsic_fast(LLVMOP, CHECK_OP, OP, name, u) \
checked_intrinsic_ctype(CHECK_OP, OP, name, 8, u##int##8_t) \
checked_intrinsic_ctype(CHECK_OP, OP, name, 16, u##int##16_t) \
checked_intrinsic_ctype(CHECK_OP, OP, name, 32, u##int##32_t) \
checked_intrinsic_ctype(CHECK_OP, OP, name, 64, u##int##64_t) \
static const select_intrinsic_checked_t name##_list = { \
    LLVMOP, \
    code_##name##8, \
    code_##name##16, \
    code_##name##32, \
    code_##name##64, \
}; \
checked_iintrinsic(name, u, language_intrinsiclambda_checked)
#define checked_iintrinsic_slow(LLVMOP, name, u) \
static const select_intrinsic_checked_t name##_list = { \
    LLVMOP \
}; \
checked_iintrinsic(name, u, language_intrinsiclambda_checked)
#define checked_iintrinsic_div(LLVMOP, name, u) \
static const select_intrinsic_checked_t name##_list = { \
    LLVMOP \
}; \
checked_iintrinsic(name, u, language_intrinsiclambda_checkeddiv)

static inline
language_value_t *language_iintrinsic_2(language_value_t *a, language_value_t *b, const char *name,
                            char (*getsign)(void*, unsigned),
                            language_value_t *(*lambda2)(language_value_t*, void*, void*, unsigned, unsigned, const void*),
                            const void *list, int cvtb)
{
    language_value_t *ty = language_typeof(a);
    language_value_t *tyb = language_typeof(b);
    if (tyb != ty) {
        if (!cvtb)
            language_errorf("%s: types of a and b must match", name);
        if (!language_is_primitivetype(tyb))
            language_errorf("%s: b is not a primitive type", name);
    }
    if (!language_is_primitivetype(ty))
        language_errorf("%s: a is not a primitive type", name);
    void *pa = language_data_ptr(a), *pb = language_data_ptr(b);
    unsigned sz = language_datatype_size(ty);
    unsigned sz2 = next_power_of_two(sz);
    unsigned szb = cvtb ? language_datatype_size(tyb) : sz;
    if (sz2 > sz) {
        /* round type up to the appropriate c-type and set/clear the unused bits */
        void *pa2 = alloca(sz2);
        memcpy(pa2, pa, sz);
        memset((char*)pa2 + sz, getsign(pa, sz), sz2 - sz);
        pa = pa2;
    }
    if (sz2 > szb) {
        /* round type up to the appropriate c-type and set/clear/truncate the unused bits
         * (zero-extend if cvtb is set, since in that case b is unsigned while the sign of a comes from the op)
         */
        void *pb2 = alloca(sz2);
        memcpy(pb2, pb, szb);
        memset((char*)pb2 + szb, cvtb ? 0 : getsign(pb, szb), sz2 - szb);
        pb = pb2;
    }
    language_value_t *newv = lambda2(ty, pa, pb, sz, sz2, list);
    return newv;
}

static inline language_value_t *language_intrinsiclambda_2(language_value_t *ty, void *pa, void *pb, unsigned sz, unsigned sz2, const void *voidlist)
{
    void *pr = alloca(sz2);
    intrinsic_2_t op = select_intrinsic_2(sz2, (const intrinsic_2_t*)voidlist);
    op(sz * host_char_bit, pa, pb, pr);
    return language_new_bits(ty, pr);
}

static inline language_value_t *language_intrinsiclambda_cmp(language_value_t *ty, void *pa, void *pb, unsigned sz, unsigned sz2, const void *voidlist)
{
    intrinsic_cmp_t op = select_intrinsic_cmp(sz2, (const intrinsic_cmp_t*)voidlist);
    int cmp = op(sz * host_char_bit, pa, pb);
    return cmp ? language_true : language_false;
}

static inline language_value_t *language_intrinsiclambda_checked(language_value_t *ty, void *pa, void *pb, unsigned sz, unsigned sz2, const void *voidlist)
{
    language_value_t *params[2];
    params[0] = ty;
    params[1] = (language_value_t*)language_bool_type;
    language_datatype_t *tuptyp = (language_datatype_t*)language_apply_tuple_type_v(params, 2);
    LANGUAGE_GC_PROMISE_ROOTED(tuptyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    language_task_t *ct = language_current_task;
    language_value_t *newv = language_gc_alloc(ct->ptls, language_datatype_size(tuptyp), tuptyp);

    intrinsic_checked_t op = select_intrinsic_checked(sz2, (const intrinsic_checked_t*)voidlist);
    int ovflw = op(sz * host_char_bit, pa, pb, language_data_ptr(newv));

    char *ao = (char*)language_data_ptr(newv) + sz;
    *ao = (char)ovflw;
    return newv;
}
static inline language_value_t *language_intrinsiclambda_checkeddiv(language_value_t *ty, void *pa, void *pb, unsigned sz, unsigned sz2, const void *voidlist)
{
    void *pr = alloca(sz2);
    intrinsic_checked_t op = select_intrinsic_checked(sz2, (const intrinsic_checked_t*)voidlist);
    int ovflw = op(sz * host_char_bit, pa, pb, pr);
    if (ovflw)
        language_throw(language_diverror_exception);
    return language_new_bits(ty, pr);
}

// floating point

#define bi_fintrinsic(OP, name) \
    bi_intrinsic_bfloat(OP, name) \
    bi_intrinsic_half(OP, name) \
    bi_intrinsic_ctype(OP, name, 32, float) \
    bi_intrinsic_ctype(OP, name, 64, double) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b) \
{ \
    language_task_t *ct = language_current_task; \
    language_value_t *ty = language_typeof(a); \
    if (language_typeof(b) != ty) \
        language_error(#name ": types of a and b must match"); \
    if (!language_is_primitivetype(ty)) \
        language_error(#name ": values are not primitive types"); \
    int sz = language_datatype_size(ty); \
    language_value_t *newv = language_gc_alloc(ct->ptls, sz, ty); \
    void *pa = language_data_ptr(a), *pb = language_data_ptr(b), *pr = language_data_ptr(newv); \
    switch (sz) { \
    /* choose the right size c-type operation */ \
    case 2: \
        if ((language_datatype_t*)ty == language_float16_type) \
            code_##name##16(16, pa, pb, pr); \
        else /*if ((language_datatype_t*)ty == language_bfloat16_type)*/ \
            code_##name##bf16(16, pa, pb, pr); \
        break; \
    case 4: \
        code_##name##32(32, pa, pb, pr); \
        break; \
    case 8: \
        code_##name##64(64, pa, pb, pr); \
        break; \
    default: \
        language_error(#name ": runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64"); \
    } \
    return newv; \
}

#define bool_fintrinsic(OP, name) \
    bool_intrinsic_bfloat(OP, name) \
    bool_intrinsic_half(OP, name) \
    bool_intrinsic_ctype(OP, name, 32, float) \
    bool_intrinsic_ctype(OP, name, 64, double) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b) \
{ \
    language_value_t *ty = language_typeof(a); \
    if (language_typeof(b) != ty) \
        language_error(#name ": types of a and b must match"); \
    if (!language_is_primitivetype(ty)) \
        language_error(#name ": values are not primitive types"); \
    void *pa = language_data_ptr(a), *pb = language_data_ptr(b); \
    int sz = language_datatype_size(ty); \
    int cmp; \
    switch (sz) { \
    /* choose the right size c-type operation */ \
    case 2: \
        if ((language_datatype_t*)ty == language_float16_type) \
            cmp = code_##name##16(16, pa, pb); \
        else /*if ((language_datatype_t*)ty == language_bfloat16_type)*/ \
            cmp = code_##name##bf16(16, pa, pb); \
        break; \
    case 4: \
        cmp = code_##name##32(32, pa, pb); \
        break; \
    case 8: \
        cmp = code_##name##64(64, pa, pb); \
        break; \
    default: \
        language_error(#name ": runtime floating point intrinsics are not implemented for bit sizes other than 32 and 64"); \
    } \
    return cmp ? language_true : language_false; \
}

#define ter_fintrinsic(OP, name) \
    ter_intrinsic_bfloat(OP, name) \
    ter_intrinsic_half(OP, name) \
    ter_intrinsic_ctype(OP, name, 32, float) \
    ter_intrinsic_ctype(OP, name, 64, double) \
LANGUAGE_DLLEXPORT language_value_t *code_##name(language_value_t *a, language_value_t *b, language_value_t *c) \
{ \
    language_task_t *ct = language_current_task; \
    language_value_t *ty = language_typeof(a); \
    if (language_typeof(b) != ty || language_typeof(c) != ty) \
        language_error(#name ": types of a, b, and c must match"); \
    if (!language_is_primitivetype(ty)) \
        language_error(#name ": values are not primitive types"); \
    int sz = language_datatype_size(ty); \
    language_value_t *newv = language_gc_alloc(ct->ptls, sz, ty); \
    void *pa = language_data_ptr(a), *pb = language_data_ptr(b), *pc = language_data_ptr(c), *pr = language_data_ptr(newv); \
    switch (sz) { \
    /* choose the right size c-type operation */ \
    case 2: \
        if ((language_datatype_t*)ty == language_float16_type) \
            code_##name##16(16, pa, pb, pc, pr); \
        else /*if ((language_datatype_t*)ty == language_bfloat16_type)*/ \
            code_##name##bf16(16, pa, pb, pc, pr); \
        break; \
    case 4: \
        code_##name##32(32, pa, pb, pc, pr); \
        break; \
    case 8: \
        code_##name##64(64, pa, pb, pc, pr); \
        break; \
    default: \
        language_error(#name ": runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64"); \
    } \
    return newv; \
}

// arithmetic
#define neg(a) -a
#define neg_float(ty, pr, a) *pr = -a
un_iintrinsic_fast(LLVMNeg, neg, neg_int, u)
#define add(a,b) a + b
bi_iintrinsic_fast(LLVMAdd, add, add_int, u)
#define sub(a,b) a - b
bi_iintrinsic_fast(LLVMSub, sub, sub_int, u)
#define mul(a,b) a * b
bi_iintrinsic_fast(LLVMMul, mul, mul_int, u)
#define div(a,b) a / b
bi_iintrinsic_fast(LLVMSDiv, div, sdiv_int,  )
bi_iintrinsic_fast(LLVMUDiv, div, udiv_int, u)
#define rem(a,b) a % b
bi_iintrinsic_fast(LLVMSRem, rem, srem_int,  )
bi_iintrinsic_fast(LLVMURem, rem, urem_int, u)
#define smod(a,b) ((a < 0) == (b < 0)) ? a % b : (b + (a % b)) % b
bi_iintrinsic_fast(language_LLVMSMod, smod, smod_int,  )
#define frem(a, b) \
    fp_select2(a, b, fmod)

un_fintrinsic(neg_float,neg_float)
bi_fintrinsic(add,add_float)
bi_fintrinsic(sub,sub_float)
bi_fintrinsic(mul,mul_float)
bi_fintrinsic(div,div_float)

// ternary operators //
// runtime fma is broken on windows, define language_fma(f) ourself with fma_emulated as reference.
#if defined(_OS_WINDOWS_)
// reinterpret(UInt64, ::Float64)
uint64_t bitcast_d2u(double d) {
    uint64_t r;
    memcpy(&r, &d, 8);
    return r;
}
// reinterpret(Float64, ::UInt64)
double bitcast_u2d(uint64_t d) {
    double r;
    memcpy(&r, &d, 8);
    return r;
}
// Base.splitbits(::Float64)
void splitbits(double *hi, double *lo, double d) {
    *hi = bitcast_u2d(bitcast_d2u(d) & 0xfffffffff8000000);
    *lo = d - *hi;
}
// Base.exponent(::Float64)
int exponent(double a) {
    int e;
    frexp(a, &e);
    return e - 1;
}
// Base.fma_emulated(::Float32, ::Float32, ::Float32)
float language_fmaf(float a, float b, float c) {
    double ab, res;
    ab = (double)a * b;
    res = ab + (double)c;
    if ((bitcast_d2u(res) & 0x1fffffff) == 0x10000000){
        double reslo = fabsf(c) > fabs(ab) ? ab-(res - c) : c-(res - ab);
        if (reslo != 0)
            res = nextafter(res, copysign(1.0/0.0, reslo));
    }
    return (float)res;
}
// Base.twomul(::Float64, ::Float64)
void two_mul(double *abhi, double *ablo, double a, double b) {
    double ahi, alo, bhi, blo, blohi, blolo;
    splitbits(&ahi, &alo, a);
    splitbits(&bhi, &blo, b);
    splitbits(&blohi, &blolo, blo);
    *abhi = a*b;
    *ablo = alo*blohi - (((*abhi - ahi*bhi) - alo*bhi) - ahi*blo) + blolo*alo;
}
// Base.issubnormal(::Float64) (Win32's fpclassify seems broken)
int issubnormal(double d) {
    uint64_t y = bitcast_d2u(d);
    return ((y & 0x7ff0000000000000) == 0) & ((y & 0x000fffffffffffff) != 0);
}
#if defined(_WIN32)
// Win32 needs volatile (avoid over optimization?)
#define VDOUBLE volatile double
#else
#define VDOUBLE double
#endif

// Base.fma_emulated(::Float64, ::Float64, ::Float64)
double language_fma(double a, double b, double c) {
    double abhi, ablo, r, s;
    two_mul(&abhi, &ablo, a, b);
    if (!isfinite(abhi+c) || fabs(abhi) < 2.0041683600089732e-292 ||
        issubnormal(a) || issubnormal(b)) {
        int aandbfinite = isfinite(a) && isfinite(b);
        if (!(aandbfinite && isfinite(c)))
            return aandbfinite ? c : abhi+c;
        if (a == 0 || b == 0)
            return abhi+c;
        int bias = exponent(a) + exponent(b);
        VDOUBLE c_denorm = ldexp(c, -bias);
        if (isfinite(c_denorm)) {
            if (issubnormal(a))
                a *= 4.503599627370496e15;
            if (issubnormal(b))
                b *= 4.503599627370496e15;
            a = bitcast_u2d((bitcast_d2u(a) & 0x800fffffffffffff) | 0x3ff0000000000000);
            b = bitcast_u2d((bitcast_d2u(b) & 0x800fffffffffffff) | 0x3ff0000000000000);
            c = c_denorm;
            two_mul(&abhi, &ablo, a, b);
            r = abhi+c;
            s = (fabs(abhi) > fabs(c)) ? (abhi-r+c+ablo) : (c-r+abhi+ablo);
            double sumhi = r+s;
            if (issubnormal(ldexp(sumhi, bias))) {
                double sumlo = r-sumhi+s;
                int bits_lost = -bias-exponent(sumhi)-1022;
                if ((bits_lost != 1) ^ ((bitcast_d2u(sumhi)&1) == 1))
                    if (sumlo != 0)
                        sumhi = nextafter(sumhi, copysign(1.0/0.0, sumlo));
            }
            return ldexp(sumhi, bias);
        }
        if (isinf(abhi) && signbit(c) == signbit(a*b))
            return abhi;
    }
    r = abhi+c;
    s = (fabs(abhi) > fabs(c)) ? (abhi-r+c+ablo) : (c-r+abhi+ablo);
    return r+s;
}
#define fma(a, b, c) \
    sizeof(a) == sizeof(float) ? language_fmaf(a, b, c) : language_fma(a, b, c)
#else // On other systems use fma(f) directly
#define fma(a, b, c) \
    sizeof(a) == sizeof(float) ? fmaf(a, b, c) : fma(a, b, c)
#endif

#define muladd(a, b, c) a * b + c
ter_fintrinsic(fma,fma_float)
ter_fintrinsic(muladd,muladd_float)

// same-type comparisons
#define eq(a,b) a == b
bool_iintrinsic_fast(LLVMICmpEQ, eq, eq_int, u)
#define ne(a,b) a != b
bool_iintrinsic_fast(LLVMICmpNE, ne, ne_int, u)
#define lt(a,b) a < b
bool_iintrinsic_fast(LLVMICmpSLT, lt, slt_int,  )
bool_iintrinsic_fast(LLVMICmpULT, lt, ult_int, u)
#define le(a,b) a <= b
bool_iintrinsic_fast(LLVMICmpSLE, le, sle_int,  )
bool_iintrinsic_fast(LLVMICmpULE, le, ule_int, u)

typedef union {
    float f;
    int32_t d;
    uint32_t ud;
} bits32;
typedef union {
    double f;
    int64_t d;
    uint64_t ud;
} bits64;

#define fpiseq_n(c_type, nbits) \
static inline int fpiseq##nbits(c_type a, c_type b) LANGUAGE_NOTSAFEPOINT { \
    bits##nbits ua, ub; \
    ua.f = a; \
    ub.f = b; \
    return (isnan(a) && isnan(b)) || ua.d == ub.d; \
}
fpiseq_n(float, 32)
fpiseq_n(double, 64)
#define fpiseq(a,b) \
    sizeof(a) <= sizeof(float) ? fpiseq32(a, b) : fpiseq64(a, b)

bool_fintrinsic(eq,eq_float)
bool_fintrinsic(ne,ne_float)
bool_fintrinsic(lt,lt_float)
bool_fintrinsic(le,le_float)
bool_fintrinsic(fpiseq,fpiseq)

// bitwise operators
#define and_op(a,b) a & b
bi_iintrinsic_fast(LLVMAnd, and_op, and_int, u)
#define or_op(a,b) a | b
bi_iintrinsic_fast(LLVMOr, or_op, or_int, u)
#define xor_op(a,b) a ^ b
bi_iintrinsic_fast(LLVMXor, xor_op, xor_int, u)
#define shl_op(a,b) b >= 8 * sizeof(a) ? 0 : a << b
bi_iintrinsic_cnvtb_fast(LLVMShl, shl_op, shl_int, u, 1)
#define lshr_op(a,b) (b >= 8 * sizeof(a)) ? 0 : a >> b
bi_iintrinsic_cnvtb_fast(LLVMLShr, lshr_op, lshr_int, u, 1)
#define ashr_op(a,b) ((b < 0 || b >= 8 * sizeof(a)) ? a >> (8 * sizeof(a) - 1) : a >> b)
bi_iintrinsic_cnvtb_fast(LLVMAShr, ashr_op, ashr_int, , 1)
//#define bswap_op(a) __builtin_bswap(a)
//un_iintrinsic_fast(LLVMByteSwap, bswap_op, bswap_int, u)
un_iintrinsic_slow(LLVMByteSwap, bswap_int, u)
//#define ctpop_op(a) __builtin_ctpop(a)
#if LANGUAGE_LLVM_VERSION >= 170000
//uu_iintrinsic_fast(LLVMPopcount, ctpop_op, ctpop_int, u)
uu_iintrinsic_slow(LLVMPopcount, ctpop_int, u)
//#define ctlz_op(a) __builtin_ctlz(a)
//uu_iintrinsic_fast(LLVMCountl_zero, ctlz_op, ctlz_int, u)
uu_iintrinsic_slow(LLVMCountl_zero, ctlz_int, u)
//#define cttz_op(a) __builtin_cttz(a)
//uu_iintrinsic_fast(LLVMCountr_zero, cttz_op, cttz_int, u)
uu_iintrinsic_slow(LLVMCountr_zero, cttz_int, u)
#else
//uu_iintrinsic_fast(LLVMCountPopulation, ctpop_op, ctpop_int, u)
uu_iintrinsic_slow(LLVMCountPopulation, ctpop_int, u)
//#define ctlz_op(a) __builtin_ctlz(a)
//uu_iintrinsic_fast(LLVMCountLeadingZeros, ctlz_op, ctlz_int, u)
uu_iintrinsic_slow(LLVMCountLeadingZeros, ctlz_int, u)
//#define cttz_op(a) __builtin_cttz(a)
//uu_iintrinsic_fast(LLVMCountTrailingZeros, cttz_op, cttz_int, u)
uu_iintrinsic_slow(LLVMCountTrailingZeros, cttz_int, u)
#endif
#define not_op(a) ~a
un_iintrinsic_fast(LLVMFlipAllBits, not_op, not_int, u)

// conversions
cvt_iintrinsic(LLVMTrunc, trunc_int)
cvt_iintrinsic(LLVMSExt, sext_int)
cvt_iintrinsic(LLVMZExt, zext_int)
cvt_iintrinsic(LLVMSItoFP, sitofp)
cvt_iintrinsic(LLVMUItoFP, uitofp)
cvt_iintrinsic(LLVMFPtoSI, fptosi)
cvt_iintrinsic(LLVMFPtoUI, fptoui)

#define fptrunc(tr, pr, a) \
        if (!(osize < 8 * sizeof(a))) \
            language_error("fptrunc: output bitsize must be < input bitsize"); \
        else if (osize == 16) { \
            if ((language_datatype_t*)tr == language_float16_type) \
                *(uint16_t*)pr = float_to_half(a); \
            else /*if ((language_datatype_t*)tr == language_bfloat16_type)*/ \
                *(uint16_t*)pr = float_to_bfloat(a); \
        } \
        else if (osize == 32) \
            *(float*)pr = a; \
        else if (osize == 64) \
            *(double*)pr = a; \
        else \
            language_error("fptrunc: runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64");
#define fpext(tr, pr, a) \
        if (!(osize >= 8 * sizeof(a))) \
            language_error("fpext: output bitsize must be >= input bitsize"); \
        if (osize == 32) \
            *(float*)pr = a; \
        else if (osize == 64) \
            *(double*)pr = a; \
        else \
            language_error("fpext: runtime floating point intrinsics are not implemented for bit sizes other than 32 and 64");
un_fintrinsic_withtype(fptrunc,fptrunc)
un_fintrinsic_withtype(fpext,fpext)

// checked arithmetic
/**
 * s_typemin = - s_typemax - 1
 * s_typemax = ((t)1 << (runtime_nbits - 1)) - 1
 * u_typemin = 0
 * u_typemax = ((t)1 << runtime_nbits) - 1
 **/
#define sTYPEMIN(t) -sTYPEMAX(t) - 1
#define sTYPEMAX(t)                                                \
    ((t)(8 * sizeof(a) == runtime_nbits                            \
         ? ((((((t)1) << (8 * sizeof(t) - 2)) - 1) << 1) + 1)      \
         : (  (((t)1) << (runtime_nbits - 1)) - 1)))

#define uTYPEMIN(t) ((t)0)
#define uTYPEMAX(t)                                             \
    ((t)(8 * sizeof(t) == runtime_nbits                         \
         ? (~((t)0)) : (~(((t)~((t)0)) << runtime_nbits))))
#define check_sadd_int(t, a, b)                                         \
        /* this test checks for (b >= 0) ? (a + b > typemax) : (a + b < typemin) ==> overflow */ \
        (b >= 0) ? (a > sTYPEMAX(t) - b) : (a < sTYPEMIN(t) - b)
checked_iintrinsic_fast(LLVMAdd_sov, check_sadd_int, add, checked_sadd_int,  )
#define check_uadd_int(t, a, b)                                       \
    /* this test checks for (a + b) > typemax(a) ==> overflow */      \
    a > uTYPEMAX(t) - b
checked_iintrinsic_fast(LLVMAdd_uov, check_uadd_int, add, checked_uadd_int, u)
#define check_ssub_int(t, a, b)                                         \
    /* this test checks for (b >= 0) ? (a - b < typemin) : (a - b > typemax) ==> overflow */ \
    (b >= 0) ? (a < sTYPEMIN(t) + b) : (a > sTYPEMAX(t) + b)
checked_iintrinsic_fast(LLVMSub_sov, check_ssub_int, sub, checked_ssub_int,  )
#define check_usub_int(t, a, b)                                   \
    /* this test checks for (a - b) < typemin ==> overflow */     \
    a < uTYPEMIN(t) + b
checked_iintrinsic_fast(LLVMSub_uov, check_usub_int, sub, checked_usub_int, u)
checked_iintrinsic_slow(LLVMMul_sov, checked_smul_int,  )
checked_iintrinsic_slow(LLVMMul_uov, checked_umul_int, u)

checked_iintrinsic_div(LLVMDiv_sov, checked_sdiv_int,  )
checked_iintrinsic_div(LLVMDiv_uov, checked_udiv_int, u)
checked_iintrinsic_div(LLVMRem_sov, checked_srem_int,  )
checked_iintrinsic_div(LLVMRem_uov, checked_urem_int, u)

// functions
#define flipsign(a, b) \
        (b >= 0) ? a : -a
bi_iintrinsic_fast(language_LLVMFlipSign, flipsign, flipsign_int,  )
#define abs_float(ty, pr, a)      *pr = fp_select(a, fabs)
#define ceil_float(ty, pr, a)     *pr = fp_select(a, ceil)
#define floor_float(ty, pr, a)    *pr = fp_select(a, floor)
#define trunc_float(ty, pr, a)    *pr = fp_select(a, trunc)
#define rint_float(ty, pr, a)     *pr = fp_select(a, rint)
#define sqrt_float(ty, pr, a)     *pr = fp_select(a, sqrt)
#define copysign_float(a, b)  fp_select2(a, b, copysign)

un_fintrinsic(abs_float,abs_float)
bi_fintrinsic(copysign_float,copysign_float)
un_fintrinsic(ceil_float,ceil_llvm)
un_fintrinsic(floor_float,floor_llvm)
un_fintrinsic(trunc_float,trunc_llvm)
un_fintrinsic(rint_float,rint_llvm)
un_fintrinsic(sqrt_float,sqrt_llvm)
un_fintrinsic(sqrt_float,sqrt_llvm_fast)
language_value_t *language_cpu_has_fma(int bits);

LANGUAGE_DLLEXPORT language_value_t *language_have_fma(language_value_t *typ)
{
    LANGUAGE_TYPECHK(have_fma, datatype, typ); // TODO what about float16/bfloat16?
    if (typ == (language_value_t*)language_float32_type)
        return language_cpu_has_fma(32);
    else if (typ == (language_value_t*)language_float64_type)
        return language_cpu_has_fma(64);
    else
        return language_false;
}

LANGUAGE_DLLEXPORT language_value_t *language_add_ptr(language_value_t *ptr, language_value_t *offset)
{
    LANGUAGE_TYPECHK(add_ptr, pointer, ptr);
    LANGUAGE_TYPECHK(add_ptr, ulong, offset);
    char *ptrval = (char*)language_unbox_long(ptr) + language_unbox_ulong(offset);
    return language_new_bits(language_typeof(ptr), &ptrval);
}

LANGUAGE_DLLEXPORT language_value_t *language_sub_ptr(language_value_t *ptr, language_value_t *offset)
{
    LANGUAGE_TYPECHK(sub_ptr, pointer, ptr);
    LANGUAGE_TYPECHK(sub_ptr, ulong, offset);
    char *ptrval = (char*)language_unbox_long(ptr) - language_unbox_ulong(offset);
    return language_new_bits(language_typeof(ptr), &ptrval);
}
