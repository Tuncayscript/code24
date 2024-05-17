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

#ifndef LANGUAGE_APINT_C_H
#define LANGUAGE_APINT_C_H

#include "code.h"
#include "dtypes.h"
#include "llvm-version.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__cplusplus) && defined(LLVM_VERSION_MAJOR)
using integerPart = llvm::APInt::WordType;
#else
typedef void integerPart;
#endif

LANGUAGE_DLLEXPORT void LLVMNeg(unsigned numbits, integerPart *pa, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMByteSwap(unsigned numbits, integerPart *pa, integerPart *pr);

LANGUAGE_DLLEXPORT void LLVMAdd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMSub(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMMul(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMSDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMUDiv(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMSRem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMURem(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

LANGUAGE_DLLEXPORT void LLVMAnd(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMOr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMXor(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMShl(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMLShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMAShr(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMFlipAllBits(unsigned numbits, integerPart *pa, integerPart *pr);

LANGUAGE_DLLEXPORT int LLVMICmpEQ(unsigned numbits, integerPart *pa, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMICmpNE(unsigned numbits, integerPart *pa, integerPart *pb);
LANGUAGE_DLLEXPORT int LLVMICmpSLT(unsigned numbits, integerPart *pa, integerPart *pb);
LANGUAGE_DLLEXPORT int LLVMICmpULT(unsigned numbits, integerPart *pa, integerPart *pb);
LANGUAGE_DLLEXPORT int LLVMICmpSLE(unsigned numbits, integerPart *pa, integerPart *pb);
LANGUAGE_DLLEXPORT int LLVMICmpULE(unsigned numbits, integerPart *pa, integerPart *pb);

LANGUAGE_DLLEXPORT int LLVMAdd_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMAdd_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMSub_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMSub_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMMul_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMMul_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMDiv_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMDiv_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMRem_sov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMRem_uov(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

#if LANGUAGE_LLVM_VERSION >= 170000
LANGUAGE_DLLEXPORT unsigned LLVMPopcount(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountr_one(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountr_zero(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountl_one(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountl_zero(unsigned numbits, integerPart *pa);
#else
LANGUAGE_DLLEXPORT unsigned LLVMCountPopulation(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountTrailingOnes(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountTrailingZeros(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountLeadingOnes(unsigned numbits, integerPart *pa);
LANGUAGE_DLLEXPORT unsigned LLVMCountLeadingZeros(unsigned numbits, integerPart *pa);
#endif

LANGUAGE_DLLEXPORT void LLVMFPtoSI(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMFPtoUI(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMSItoFP(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMUItoFP(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMSExt(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMZExt(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT void LLVMTrunc(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);

LANGUAGE_DLLEXPORT int LLVMFPtoSI_exact(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);
LANGUAGE_DLLEXPORT int LLVMFPtoUI_exact(language_datatype_t *ty, integerPart *pa, language_datatype_t *oty, integerPart *pr);

LANGUAGE_DLLEXPORT void language_LLVMSMod(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);
LANGUAGE_DLLEXPORT void language_LLVMFlipSign(unsigned numbits, integerPart *pa, integerPart *pb, integerPart *pr);

#if LANGUAGE_LLVM_VERSION >= 170000
LANGUAGE_DLLEXPORT unsigned countr_zero_8(uint8_t Val);
LANGUAGE_DLLEXPORT unsigned countr_zero_16(uint16_t Val);
LANGUAGE_DLLEXPORT unsigned countr_zero_32(uint32_t Val);
LANGUAGE_DLLEXPORT unsigned countr_zero_64(uint64_t Val);
#else
LANGUAGE_DLLEXPORT unsigned countTrailingZeros_8(uint8_t Val);
LANGUAGE_DLLEXPORT unsigned countTrailingZeros_16(uint16_t Val);
LANGUAGE_DLLEXPORT unsigned countTrailingZeros_32(uint32_t Val);
LANGUAGE_DLLEXPORT unsigned countTrailingZeros_64(uint64_t Val);
#endif

//uint8_t getSwappedBytes_8(uint8_t Value); // no-op
//uint16_t getSwappedBytes_16(uint16_t Value);
//uint32_t getSwappedBytes_32(uint32_t Value);
//uint64_t getSwappedBytes_64(uint64_t Value);


#ifdef __cplusplus
}
#endif

#endif
