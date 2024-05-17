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
#include "support/platform.h"
#include "support/dtypes.h"

#include "llvm/Config/llvm-config.h"
#include "llvm/IR/IRBuilder.h"
#include <llvm/Support/raw_ostream.h>

#include "code.h"
#include "llvm-codegen-shared.h"

using namespace llvm;

// Borrow definition from `support/dtypes.h`
#ifdef _OS_WINDOWS_
#  define DLLEXPORT __declspec(dllexport)
#else
#  define DLLEXPORT __attribute__ ((visibility("default")))
#endif

extern "C" {

DLLEXPORT const char *MakeIdentityFunction(language_value_t* language_AnyTy) {
    LLVMContext Ctx;
    // FIXME: get TrackedTy via language_type_to_llvm(Ctx, language_AnyTy)
    Type *TrackedTy = PointerType::get(StructType::get(Ctx), AddressSpace::Tracked);
    Module *M = new llvm::Module("shadow", Ctx);
    Function *F = Function::Create(
        FunctionType::get(
            TrackedTy, {TrackedTy}, false),
        llvm::GlobalValue::ExternalLinkage,
        "identity",
        M
    );

    IRBuilder<> Builder(BasicBlock::Create(Ctx, "top", F));
    Builder.CreateRet(&*F->arg_begin());

    std::string buf;
    raw_string_ostream os(buf);
    M->print(os, NULL);
    os.flush();
    return strdup(buf.c_str());
}

DLLEXPORT const char *MakeLoadGlobalFunction() {
    LLVMContext Ctx;

    auto M = new Module("shadow", Ctx);
    auto intType = Type::getInt32Ty(Ctx);
    auto G = new GlobalVariable(
        *M,
        intType,
        true,
        GlobalValue::InternalLinkage,
        Constant::getNullValue(intType),
        "test_global_var");

    auto resultType = Type::getInt64Ty(Ctx);
    auto F = Function::Create(
        FunctionType::get(resultType, {}, false),
        GlobalValue::ExternalLinkage,
        "load_global_var",
        M);

    IRBuilder<> Builder(BasicBlock::Create(Ctx, "top", F));
    Builder.CreateRet(Builder.CreatePtrToInt(G, resultType));

    std::string buf;
    raw_string_ostream os(buf);
    M->print(os, NULL);
    os.flush();
    return strdup(buf.c_str());
}

}
