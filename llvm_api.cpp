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

#undef DEBUG
#include "llvm-version.h"
#include "platform.h"

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

#include "jitlayers.h"
#include "passes.h"

#include <llvm-c/Core.h>
#include <llvm-c/Error.h>
#include <llvm-c/Orc.h>
#include <llvm-c/OrcEE.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Types.h>
#include <llvm/Support/CBindingWrapping.h>
#include <llvm/Support/MemoryBuffer.h>

namespace llvm {
namespace orc {
class OrcV2CAPIHelper {
public:
    using PoolEntry = orc::SymbolStringPtr::PoolEntry;
    using PoolEntryPtr = orc::SymbolStringPtr::PoolEntryPtr;

    // Move from SymbolStringPtr to PoolEntryPtr (no change in ref count).
    static PoolEntryPtr moveFromSymbolStringPtr(SymbolStringPtr S)
    {
        PoolEntryPtr Result = nullptr;
        std::swap(Result, S.S);
        return Result;
    }
};
} // namespace orc
} // namespace llvm


typedef struct LANGUAGEOpaqueJuliaOJIT *JuliaOJITRef;
typedef struct LLVMOrcOpaqueIRCompileLayer *LLVMOrcIRCompileLayerRef;

DEFINE_SIMPLE_CONVERSION_FUNCTIONS(JuliaOJIT, JuliaOJITRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::JITDylib, LLVMOrcJITDylibRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::ExecutionSession, LLVMOrcExecutionSessionRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::OrcV2CAPIHelper::PoolEntry,
                                   LLVMOrcSymbolStringPoolEntryRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::IRCompileLayer, LLVMOrcIRCompileLayerRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::MaterializationResponsibility,
                                   LLVMOrcMaterializationResponsibilityRef)

typedef struct LLVMOpaqueModulePassManager *LLVMModulePassManagerRef;
typedef struct LLVMOpaqueFunctionPassManager *LLVMFunctionPassManagerRef;
typedef struct LLVMOpaqueLoopPassManager *LLVMLoopPassManagerRef;

DEFINE_SIMPLE_CONVERSION_FUNCTIONS(llvm::ModulePassManager, LLVMModulePassManagerRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(llvm::FunctionPassManager, LLVMFunctionPassManagerRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(llvm::LoopPassManager, LLVMLoopPassManagerRef)

extern "C" {

LANGUAGE_DLLEXPORT_CODEGEN JuliaOJITRef LANGUAGEJITGetJuliaOJIT_impl(void)
{
    return wrap(language_ExecutionEngine);
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMOrcExecutionSessionRef
LANGUAGEJITGetLLVMOrcExecutionSession_impl(JuliaOJITRef JIT)
{
    return wrap(&unwrap(JIT)->getExecutionSession());
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMOrcJITDylibRef
LANGUAGEJITGetExternalJITDylib_impl(JuliaOJITRef JIT)
{
    return wrap(&unwrap(JIT)->getExternalJITDylib());
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMErrorRef LANGUAGEJITAddObjectFile_impl(
    JuliaOJITRef JIT, LLVMOrcJITDylibRef JD, LLVMMemoryBufferRef ObjBuffer)
{
    return wrap(unwrap(JIT)->addObjectFile(
        *unwrap(JD), std::unique_ptr<MemoryBuffer>(unwrap(ObjBuffer))));
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMErrorRef LANGUAGEJITAddLLVMIRModule_impl(
    JuliaOJITRef JIT, LLVMOrcJITDylibRef JD, LLVMOrcThreadSafeModuleRef TSM)
{
    std::unique_ptr<orc::ThreadSafeModule> TmpTSM(unwrap(TSM));
    return wrap(unwrap(JIT)->addExternalModule(*unwrap(JD), std::move(*TmpTSM)));
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMErrorRef
LANGUAGEJITLookup_impl(JuliaOJITRef JIT, LLVMOrcExecutorAddress *Result,
                                   const char *Name, int ExternalJDOnly)
{
    auto Sym = unwrap(JIT)->findExternalJDSymbol(Name, ExternalJDOnly);
    if (Sym) {
        auto addr = Sym->getAddress();
        *Result = orc::ExecutorAddr(addr).getValue();
        return LLVMErrorSuccess;
    }
    else {
        *Result = 0;
        return wrap(Sym.takeError());
    }
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMOrcSymbolStringPoolEntryRef
LANGUAGEJITMangleAndIntern_impl(JuliaOJITRef JIT,
                                            const char *Name)
{
    return wrap(orc::OrcV2CAPIHelper::moveFromSymbolStringPtr(unwrap(JIT)->mangle(Name)));
}

LANGUAGE_DLLEXPORT_CODEGEN const char *
LANGUAGEJITGetTripleString_impl(JuliaOJITRef JIT)
{
    return unwrap(JIT)->getTargetTriple().str().c_str();
}

LANGUAGE_DLLEXPORT_CODEGEN const char
LANGUAGEJITGetGlobalPrefix_impl(JuliaOJITRef JIT)
{
    return unwrap(JIT)->getDataLayout().getGlobalPrefix();
}

LANGUAGE_DLLEXPORT_CODEGEN const char *
LANGUAGEJITGetDataLayoutString_impl(JuliaOJITRef JIT)
{
    return unwrap(JIT)->getDataLayout().getStringRepresentation().c_str();
}

LANGUAGE_DLLEXPORT_CODEGEN LLVMOrcIRCompileLayerRef
LANGUAGEJITGetIRCompileLayer_impl(JuliaOJITRef JIT)
{
    return wrap(&unwrap(JIT)->getIRCompileLayer());
}

#define MODULE_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT_CODEGEN void LLVMExtraMPMAdd##CLASS##_impl(LLVMModulePassManagerRef PM) \
    { \
        unwrap(PM)->addPass(CREATE_PASS); \
    }
#define FUNCTION_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT_CODEGEN void LLVMExtraFPMAdd##CLASS##_impl(LLVMFunctionPassManagerRef PM) \
    { \
        unwrap(PM)->addPass(CREATE_PASS); \
    }
#define LOOP_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT_CODEGEN void LLVMExtraLPMAdd##CLASS##_impl(LLVMLoopPassManagerRef PM) \
    { \
        unwrap(PM)->addPass(CREATE_PASS); \
    }

#include "llvm-julia-passes.inc"

#undef MODULE_PASS
#undef CGSCC_PASS
#undef FUNCTION_PASS
#undef LOOP_PASS

} // extern "C"
