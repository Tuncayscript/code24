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

#include "llvm-version.h"
#include <llvm/ADT/ArrayRef.h>
#include <llvm/ADT/APInt.h>
#include <llvm/ADT/APFloat.h>
#include <llvm/Support/MathExtras.h>

#include "APInt-C.h"
#include "language_assert.h"
#include "language_internal.h"

using namespace llvm;

const unsigned int integerPartWidth = llvm::APInt::APINT_BITS_PER_WORD;
const unsigned int host_char_bit = 8;

/* create "APInt s" from "integerPart *ps" */
#define CREATE(s) \
    APInt s; \
    if ((numbits % integerPartWidth) != 0) { \
        /* use LLT_ALIGN to round the memory area up to the nearest integerPart-sized chunk */ \
        unsigned nbytes = alignTo(numbits, integerPartWidth) / host_char_bit; \
        integerPart *data_a64 = (integerPart*)alloca(nbytes); \
        /* TODO: this memcpy assumes little-endian,
         * for big-endian, need to align the copy to the other end */ \
        memcpy(data_a64, p##s, alignTo(numbits, host_char_bit) / host_char_bit); \
        s = APInt(numbits, ArrayRef<uint64_t>(data_a64, nbytes / sizeof(integerPart))); \
    } \
    else { \
        s = APInt(numbits, ArrayRef<uint64_t>(p##s, numbits / integerPartWidth)); \
    }

/* assign to "integerPart *pr" from "APInt a" */
#define ASSIGN(r, a) \
    if (numbits <= 8) \
        *(uint8_t*)p##r = a.getZExtValue(); \
    else if (numbits <= 16) \
        *(uint16_t*)p##r = a.getZExtValue(); \
    else if (numbits <= 32) \
        *(uint32_t*)p##r = a.getZExtValue(); \
    else if (numbits <= 64) \
        *(uint64_t*)p##r = a.getZExtValue(); \
    else \
        memcpy(p##r, a.getRawData(), alignTo(numbits, host_char_bit) / host_char_bit); \

extern "C" LANGUAGE_DLLEXPORT
void LLVMNeg(unsigned numbits, integerPart *pa, integerPart *pr) {
    APInt z(numbits, 0);
    CREATE(a)
    z -= a;
    ASSIGN(r, z)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMAdd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a += b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMSub(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a -= b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMMul(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a *= b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMSDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    if (LLVMDiv_sov(numbits, pa, pb, pr))
        language_throw(language_diverror_exception);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMUDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    if (LLVMDiv_uov(numbits, pa, pb, pr))
        language_throw(language_diverror_exception);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMSRem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    if (LLVMRem_sov(numbits, pa, pb, pr))
        language_throw(language_diverror_exception);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMURem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    if (LLVMRem_uov(numbits, pa, pb, pr))
        language_throw(language_diverror_exception);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpEQ(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.eq(b);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpNE(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.ne(b);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpSLT(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.slt(b);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpULT(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.ult(b);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpSLE(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.sle(b);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMICmpULE(unsigned numbits, integerPart *pa, integerPart *pb) {
    CREATE(a)
    CREATE(b)
    return a.ule(b);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMAnd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a &= b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMOr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a |= b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMXor(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a ^= b;
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMShl(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a = a.shl(b);
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMLShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a = a.lshr(b);
    ASSIGN(r, a)
}
extern "C" LANGUAGE_DLLEXPORT
void LLVMAShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    a = a.ashr(b);
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMFlipAllBits(unsigned numbits, integerPart *pa, integerPart *pr) {
    CREATE(a)
    a.flipAllBits();
    ASSIGN(r, a)
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMAdd_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.uadd_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMAdd_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.sadd_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMSub_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.usub_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMSub_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.ssub_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMMul_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.smul_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMMul_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    bool Overflow;
    a = a.umul_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMDiv_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    if (!b)
        return true;
    bool Overflow;
    a = a.sdiv_ov(b, Overflow);
    ASSIGN(r, a)
    return Overflow;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMDiv_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    if (!b)
        return true;
    a = a.udiv(b);
    ASSIGN(r, a)
    return false;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMRem_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    if (!b)
        return true;
    a = a.srem(b);
    ASSIGN(r, a)
    return false;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMRem_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    CREATE(a)
    CREATE(b)
    if (!b)
        return true;
    a = a.urem(b);
    ASSIGN(r, a)
    return false;
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMByteSwap(unsigned numbits, integerPart *pa, integerPart *pr) {
    CREATE(a)
    a = a.byteSwap();
    ASSIGN(r, a)
}

extern "C" float language_half_to_float(uint16_t ival) LANGUAGE_NOTSAFEPOINT;
extern "C" uint16_t language_float_to_half(float param) LANGUAGE_NOTSAFEPOINT;
extern "C" float language_bfloat_to_float(uint16_t ival) LANGUAGE_NOTSAFEPOINT;
extern "C" uint16_t language_float_to_bfloat(float param) LANGUAGE_NOTSAFEPOINT;

void LLVMFPtoInt(language_datatype_t *ty, void *pa, language_datatype_t *oty, integerPart *pr, bool isSigned, bool *isExact) {
    double Val;
    if (ty == language_float16_type)
        Val = language_half_to_float(*(uint16_t*)pa);
    else if (ty == language_bfloat16_type)
        Val = language_bfloat_to_float(*(uint16_t*)pa);
    else if (ty == language_float32_type)
        Val = *(float*)pa;
    else if (language_float64_type)
        Val = *(double*)pa;
    else
        language_error("FPtoSI: runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64");
    unsigned onumbytes = language_datatype_size(oty);
    unsigned onumbits = onumbytes * host_char_bit;
    if (onumbits <= 64) { // fast-path, if possible
        if (isSigned) {
            int64_t ia = Val;
            memcpy(pr, &ia, onumbytes); // TODO: assumes little-endian
            if (isExact) {
                // check whether the conversion was lossless
                int64_t ia2 = ia < 0 ? -1 : 0;
                memcpy(&ia2, pr, onumbytes);
                *isExact = (Val == (double)ia2 && ia == ia2);
            }
        }
        else {
            uint64_t ia = Val;
            memcpy(pr, &ia, onumbytes); // TODO: assumes little-endian
            if (isExact) {
                // check whether the conversion was lossless
                uint64_t ia2 = 0;
                memcpy(&ia2, pr, onumbytes);
                *isExact = (Val == (double)ia2 && ia == ia2);
            }
        }
    }
    else {
        APFloat a(Val);
        bool isVeryExact;
        APFloat::roundingMode rounding_mode = APFloat::rmNearestTiesToEven;
        unsigned nbytes = alignTo(onumbits, integerPartWidth) / host_char_bit;
        integerPart *parts = (integerPart*)alloca(nbytes);
        APFloat::opStatus status = a.convertToInteger(MutableArrayRef<integerPart>(parts, nbytes), onumbits, isSigned, rounding_mode, &isVeryExact);
        memcpy(pr, parts, onumbytes);
        if (isExact)
            *isExact = (status == APFloat::opOK);
    }
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMFPtoSI(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    LLVMFPtoInt(ty, pa, oty, pr, true, NULL);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMFPtoUI(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    LLVMFPtoInt(ty, pa, oty, pr, false, NULL);
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMFPtoSI_exact(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    bool isExact;
    LLVMFPtoInt(ty, pa, oty, pr, true, &isExact);
    return isExact;
}

extern "C" LANGUAGE_DLLEXPORT
int LLVMFPtoUI_exact(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    bool isExact;
    LLVMFPtoInt(ty, pa, oty, pr, false, &isExact);
    return isExact;
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMSItoFP(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    double val;
    { // end scope before language_error call
        unsigned numbytes = language_datatype_size(ty);
        unsigned numbits = numbytes * host_char_bit;
        CREATE(a)
        val = a.roundToDouble(true);
    }
    if (oty == language_float16_type)
        *(uint16_t*)pr = language_float_to_half(val);
    else if (oty == language_bfloat16_type)
        *(uint16_t*)pr = language_float_to_bfloat(val);
    else if (oty == language_float32_type)
        *(float*)pr = val;
    else if (oty == language_float64_type)
        *(double*)pr = val;
    else
        language_error("SItoFP: runtime floating point intrinsics are not implemented for bit sizes other than 16, 32 and 64");
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMUItoFP(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr) {
    double val;
    { // end scope before language_error call
        unsigned numbytes = language_datatype_size(ty);
        unsigned numbits = numbytes * host_char_bit;
        CREATE(a)
        val = a.roundToDouble(false);
    }
    if (oty == language_float16_type)
        *(uint16_t*)pr = language_float_to_half(val);
    else if (oty == language_bfloat16_type)
        *(uint16_t*)pr = language_float_to_bfloat(val);
    else if (oty == language_float32_type)
        *(float*)pr = val;
    else if (oty == language_float64_type)
        *(double*)pr = val;
    else
        language_error("UItoFP: runtime floating point intrinsics are not implemented for bit sizes other than 32 and 64");
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMSExt(language_datatype_t *ty, integerPart *pa, language_datatype_t *otys, integerPart *pr) {
    unsigned inumbytes = language_datatype_size(ty);
    unsigned onumbytes = language_datatype_size(otys);
    if (!(onumbytes > inumbytes))
        language_error("SExt: output bitsize must be > input bitsize");
    unsigned inumbits = inumbytes * host_char_bit;
    int bits = (0 - inumbits) % host_char_bit;
    int signbit = (inumbits - 1) % host_char_bit;
    int sign = ((unsigned char*)pa)[inumbytes - 1] & (1 << signbit) ? -1 : 0;
    // copy over the input bytes
    memcpy(pr, pa, inumbytes);
    if (bits) {
        // sign-extend the partial byte
        ((signed char*)pr)[inumbytes - 1] = ((signed char*)pa)[inumbytes - 1] << bits >> bits;
    }
    // sign-extend the rest of the bytes
    memset((char*)pr + inumbytes, sign, onumbytes - inumbytes);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMZExt(language_datatype_t *ty, integerPart *pa, language_datatype_t *otys, integerPart *pr) {
    unsigned inumbytes = language_datatype_size(ty);
    unsigned onumbytes = language_datatype_size(otys);
    if (!(onumbytes > inumbytes))
        language_error("ZExt: output bitsize must be > input bitsize");
    unsigned inumbits = inumbytes * host_char_bit;
    int bits = (0 - inumbits) % host_char_bit;
    // copy over the input bytes
    memcpy(pr, pa, inumbytes);
    if (bits) {
        // zero the remaining bits of the partial byte
        ((unsigned char*)pr)[inumbytes - 1] = ((unsigned char*)pa)[inumbytes - 1] << bits >> bits;
    }
    // zero-extend the rest of the bytes
    memset((char*)pr + inumbytes, 0, onumbytes - inumbytes);
}

extern "C" LANGUAGE_DLLEXPORT
void LLVMTrunc(language_datatype_t *ty, integerPart *pa, language_datatype_t *otys, integerPart *pr) {
    unsigned inumbytes = language_datatype_size(ty);
    unsigned onumbytes = language_datatype_size(otys);
    if (!(onumbytes < inumbytes))
        language_error("Trunc: output bitsize must be < input bitsize");
    memcpy(pr, pa, onumbytes);
}

#if LANGUAGE_LLVM_VERSION >= 170000
extern "C" LANGUAGE_DLLEXPORT
unsigned countr_zero_8(uint8_t Val) {
    return countr_zero(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countr_zero_16(uint16_t Val) {
    return countr_zero(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countr_zero_32(uint32_t Val) {
    return countr_zero(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countr_zero_64(uint64_t Val) {
    return countr_zero(Val);
}
#else
extern "C" LANGUAGE_DLLEXPORT
unsigned countTrailingZeros_8(uint8_t Val) {
    return countTrailingZeros(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countTrailingZeros_16(uint16_t Val) {
    return countTrailingZeros(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countTrailingZeros_32(uint32_t Val) {
    return countTrailingZeros(Val);
}

extern "C" LANGUAGE_DLLEXPORT
unsigned countTrailingZeros_64(uint64_t Val) {
    return countTrailingZeros(Val);
}
#endif

extern "C" LANGUAGE_DLLEXPORT
void language_LLVMSMod(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    { // end scope before language_error call
        CREATE(a)
        CREATE(b)
        if (!!b) {
            APInt r = a.srem(b);
            if (a.isNegative() != b.isNegative()) {
                r = (b + r).srem(b);
            }
            ASSIGN(r, r)
            return;
        }
    }
    language_throw(language_diverror_exception);
}

extern "C" LANGUAGE_DLLEXPORT
void language_LLVMFlipSign(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr) {
    unsigned numbytes = (numbits + host_char_bit - 1) / host_char_bit;
    int signbit = (numbits - 1) % host_char_bit;
    int sign = ((unsigned char*)pb)[numbytes - 1] & (1 << signbit);
    if (sign)
        LLVMNeg(numbits, pa, pr);
    else
        memcpy(pr, pa, numbytes);
}

#if LANGUAGE_LLVM_VERSION >= 170000
extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMPopcount(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.popcount();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountr_one(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countr_one();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountr_zero(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countr_zero();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountl_one(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countl_one();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountl_zero(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countl_zero();
}
#else
extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountPopulation(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countPopulation();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountTrailingOnes(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countTrailingOnes();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountTrailingZeros(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countTrailingZeros();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountLeadingOnes(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countLeadingOnes();
}

extern "C" LANGUAGE_DLLEXPORT
unsigned LLVMCountLeadingZeros(unsigned numbits, integerPart *pa) {
    CREATE(a)
    return a.countLeadingZeros();
}
#endif
