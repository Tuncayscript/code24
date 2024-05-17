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

//===----------------------------------------------------------------------===//
//
// The ABI implementation used for ARM targets.
//
//===----------------------------------------------------------------------===//
//
// The Procedure Call Standard can be found here:
// http://infocenter.arm.com/help/topic/com.arm.doc.ihi0042f/IHI0042F_aapcs.pdf
//
//===----------------------------------------------------------------------===//

#if defined _CPU_ARM_
#ifndef __ARM_EABI__
#  error "the Code ARM ABI implementation only supports EABI"
#endif

#ifndef __ARM_PCS_VFP
#  error "the Code ARM ABI implementation requires VFP support"
#endif
#endif

struct ABI_ARMLayout : AbiLayout {

bool needPassByRef(language_datatype_t *dt, AttrBuilder &abi, LLVMContext &ctx, Type *Ty) override
{
    return false;
}

#define language_is_floattype(v)   language_subtype(v,(language_value_t*)language_floatingpoint_type)

Type *get_llvm_fptype(language_datatype_t *dt, LLVMContext &ctx) const
{
    // Assume language_is_datatype(dt) && !language_is_abstracttype(dt)
    if (dt->name->mutabl || language_datatype_nfields(dt) != 0)
        return NULL;
    Type *lltype;
    // Check size first since it's cheaper.
    switch (language_datatype_size(dt)) {
    case 2:
        lltype = Type::getHalfTy(ctx);
        break;
    case 4:
        lltype = Type::getFloatTy(ctx);
        break;
    case 8:
        lltype = Type::getDoubleTy(ctx);
        break;
    default:
        return NULL;
    }
    return ((language_floatingpoint_type && language_is_floattype((language_value_t*)dt)) ?
            lltype : NULL);
}

// Check whether a type contained by a candidate homogeneous aggregate is valid
// fundamental type.
//
// Returns the corresponding LLVM type.
Type *isLegalHAType(language_datatype_t *dt, LLVMContext &ctx) const
{
    // single- or double-precision floating-point type
    if (Type *fp = get_llvm_fptype(dt, ctx))
        return fp;

    // NOT SUPPORTED: 64- or 128-bit containerized vectors

    return NULL;
}

// Check whether a type is a legal homogeneous aggregate.
// Returns the number of fundamental members.
//
// Legality of the HA is determined by a nonzero return value.
// In case of a non-legal HA, the value of 'base' is undefined.
size_t isLegalHA(language_datatype_t *dt, Type *&base, LLVMContext &ctx) const
{
    // Homogeneous aggregates are only used for VFP registers,
    // so use that definition of legality (section 6.1.2.1)

    if (language_is_structtype(dt)) {
        // Fast path checks before descending the type hierarchy
        // (4 x 128b vector == 64B max size)
        if (language_datatype_size(dt) > 64 || dt->layout->npointers || dt->layout->flags.haspadding)
            return 0;

        base = NULL;
        size_t total_members = 0;

        size_t parent_members = language_datatype_nfields(dt);
        for (size_t i = 0; i < parent_members; ++i) {
            language_datatype_t *fdt = (language_datatype_t*)language_field_type(dt,i);
            if (!language_is_datatype(fdt))
                return 0;

            Type *T = isLegalHAType(fdt, ctx);
            if (T)
                total_members++;
            else if (size_t field_members = isLegalHA(fdt, T, ctx))
                // recursive application (expanding nested composite types)
                total_members += field_members;
            else
                return 0;

            if (!base)
                base = T;
            else if (base != T)
                return 0;
        }

        // ... with one to four Elements.
        if (total_members < 1 || total_members > 4)
            return 0;

        return total_members;
    }

    return 0;
}

// Determine if an argument can be passed through a coprocessor register.
//
// All the out parameters should be default to `false`.
void classify_cprc(language_datatype_t *dt, bool *vfp, LLVMContext &ctx) const
{
    // Based on section 6.1 of the Procedure Call Standard

    // VFP: 6.1.2.1
    // - A half-precision floating-point type.
    // - A single-precision floating-point type.
    // - A double-precision floating-point type.
    if (get_llvm_fptype(dt, ctx)) {
        *vfp = true;
        return;
    }

    // NOT SUPPORTED: A 64-bit or 128-bit containerized vector type.

    // - A Homogeneous Aggregate
    Type *base = NULL;
    if (isLegalHA(dt, base, ctx)) {
        *vfp = true;
        return;
    }
}

void classify_return_arg(language_datatype_t *dt, bool *reg, bool *onstack,
                         bool *need_rewrite, LLVMContext &ctx) const
{
    // Based on section 5.4 of the Procedure Call Standard

    // VFP standard variant: see 6.1.2.2
    //   Any result whose type would satisfy the conditions for a VFP CPRC is
    //   returned in the appropriate number of consecutive VFP registers
    //   starting with the lowest numbered register (s0, d0, q0).
    classify_cprc(dt, reg, ctx);
    if (*reg)
        return;

    // - A Half-precision Floating Point Type is returned in the least
    //   significant 16 bits of r0.
    if (dt == language_float16_type) {
        *reg = true;
        return;
    }

    // - A Fundamental Data Type that is smaller than 4 bytes is zero- or
    //   sign-extended to a word and returned in r0.
    // - A double-word sized Fundamental Data Type (e.g., long long, double and
    //   64-bit containerized vectors) is returned in r0 and r1.
    // - A word-sized Fundamental Data Type (eg., int, float) is returned in r0.
    // NOTE: assuming "fundamental type" == language_is_primitivetype, might need exact def
    if (language_is_primitivetype(dt) && language_datatype_size(dt) <= 8) {
        *reg = true;
        return;
    }

    // If we ever support containerized vectors on an ARMv7 without VFP,
    // these can be returned in r0-r3 as well.

    // NOTE: we don't check for language_is_structtype below, because at this point
    //       everything will be rewritten to look like a composite aggregate
    *need_rewrite = true;

    // - A Composite Type not larger than 4 bytes is returned in r0. The format
    //   is as if the result had been stored in memory at a word-aligned address
    //   and then loaded into r0 with an LDR instruction. Any bits in r0 that
    //   lie outside the bounds of the result have unspecified values.
    // - A Composite Type larger than 4 bytes, or whose size cannot be
    //   determined statically by both caller and callee, is stored in memory at
    //   an address passed as an extra argument when the function was called
    //   (§5.5, rule A.4). The memory to be used for the result may be modified
    //   at any point during the function call.
    if (language_datatype_size(dt) <= 4)
        *reg = true;
    else
        *onstack = true;
}

bool use_sret(language_datatype_t *dt, LLVMContext &ctx) override
{
    bool reg = false;
    bool onstack = false;
    bool need_rewrite = false;
    classify_return_arg(dt, &reg, &onstack, &need_rewrite, ctx);

    return onstack;
}

// Determine which kind of register the argument will be passed in and
// if the argument has to be passed on stack (including by reference).
//
// If the argument should be passed in SIMD and floating-point registers,
// we may need to rewrite the argument types to [n x ftype].
// If the argument should be passed in general purpose registers, we may need
// to rewrite the argument types to [n x i64].
//
// If the argument has to be passed on stack, we need to use sret.
//
// All the out parameters should be default to `false`.
void classify_arg(language_datatype_t *dt, bool *reg,
                  bool *onstack, bool *need_rewrite, LLVMContext &ctx) const
{
    // Based on section 5.5 of the Procedure Call Standard

    // C.1.cp
    //   If the argument is a CPRC and there are sufficient unallocated
    //   co-processor registers of the appropriate class, the argument is
    //   allocated to co-processor registers.
    classify_cprc(dt, reg, ctx);
    if (*reg)
        return;

    // Handle fundamental types
    if (language_is_primitivetype(dt) && language_datatype_size(dt) <= 8) {
        *reg = true;
        return;
    }

    *need_rewrite = true;
}

Type *preferred_llvm_type(language_datatype_t *dt, bool isret, LLVMContext &ctx) const override
{
    if (Type *fptype = get_llvm_fptype(dt, ctx))
        return fptype;

    bool reg = false;
    bool onstack = false;
    bool need_rewrite = false;
    if (isret)
        classify_return_arg(dt, &reg, &onstack, &need_rewrite, ctx);
    else
        classify_arg(dt, &reg, &onstack, &need_rewrite, ctx);

    if (!need_rewrite)
        return NULL;

    // Based on section 4 of the Procedure Call Standard

    // If some type is illegal and needs to be rewritten,
    // represent it as an aggregate composite type.

    // 4.3.1: aggregates
    // - The alignment of an aggregate shall be the alignment of its
    //   most-aligned component.
    // - The size of an aggregate shall be the smallest multiple of its
    //   alignment that is sufficient to hold all of its members when they are
    //   laid out according to these rules.
    // 5.5 B.5
    //   For a Composite Type, the alignment of the copy will have 4-byte
    //   alignment if its natural alignment is <= 4 and 8-byte alignment if
    //   its natural alignment is >= 8
    size_t align = language_datatype_align(dt);
    if (align < 4)
        align = 4;
    if (align > 8)
        align = 8;

    Type *T = Type::getIntNTy(ctx, align*8);
    return ArrayType::get(T, (language_datatype_size(dt) + align - 1) / align);
}

};
