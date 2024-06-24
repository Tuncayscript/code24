/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: This file provides a fallback implementation of the codegen plugin interface,
// used when libnextcode-codegen is not available.

#include "code.h"
#include "code_internal.h"

#include "intrinsics.h"

#define UNAVAILABLE { code_errorf("%s: not available in this build of NeXTCode", __func__); }

CODE_DLLEXPORT void code_dump_native_fallback(void *native_code,
        const char *bc_fname, const char *unopt_bc_fname, const char *obj_fname, const char *asm_fname,
        ios_t *z, ios_t *s) UNAVAILABLE
CODE_DLLEXPORT void code_get_llvm_gvs_fallback(void *native_code, arraylist_t *gvs) UNAVAILABLE
CODE_DLLEXPORT void code_get_llvm_external_fns_fallback(void *native_code, arraylist_t *gvs) UNAVAILABLE

CODE_DLLEXPORT void code_extern_c_fallback(code_function_t *f, code_value_t *rt, code_value_t *argt, char *name) UNAVAILABLE
CODE_DLLEXPORT code_value_t *code_dump_method_asm_fallback(code_method_instance_t *linfo, size_t world,
        char emit_mc, char getwrapper, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE
CODE_DLLEXPORT code_value_t *code_dump_function_ir_fallback(code_llvmf_dump_t *dump, char strip_ir_metadata, char dump_module, const char *debuginfo) UNAVAILABLE
CODE_DLLEXPORT void code_get_llvmf_defn_fallback(code_llvmf_dump_t *dump, code_method_instance_t *linfo, code_code_info_t *src, char getwrapper, char optimize, const code_cgparams_t params) UNAVAILABLE

CODE_DLLEXPORT void *code_LLVMCreateDisasm_fallback(const char *TripleName, void *DisInfo, int TagType, void *GetOpInfo, void *SymbolLookUp) UNAVAILABLE
CODE_DLLEXPORT size_t code_LLVMDisasmInstruction_fallback(void *DC, uint8_t *Bytes, uint64_t BytesSize, uint64_t PC, char *OutString, size_t OutStringSize) UNAVAILABLE

CODE_DLLEXPORT void code_init_codegen_fallback(void) { }

CODE_DLLEXPORT int code_getFunctionInfo_fallback(code_frame_t **frames, uintptr_t pointer, int skipC, int noInline)
{
    return 0;
}

CODE_DLLEXPORT void code_register_fptrs_fallback(uint64_t image_base, const struct _code_image_fptrs_t *fptrs,
                       code_method_instance_t **linfos, size_t n)
{
    (void)image_base; (void)fptrs; (void)linfos; (void)n;
}

CODE_DLLEXPORT void code_generate_fptr_for_unspecialized_fallback(code_code_instance_t *unspec)
{
    code_atomic_store_release(&unspec->invoke, &code_fptr_interpret_call);
}

CODE_DLLEXPORT int code_compile_codeinst_fallback(code_code_instance_t *unspec)
{
    // Do nothing. The caller will notice that we failed to provide a an ->invoke and trigger
    // appropriate fallbacks.
    return 0;
}

CODE_DLLEXPORT uint32_t code_get_LLVM_VERSION_fallback(void)
{
    return 0;
}

CODE_DLLEXPORT int code_compile_extern_c_fallback(LLVMOrcThreadSafeModuleRef llvmmod, void *params, void *sysimg, code_value_t *declrt, code_value_t *sigt)
{
    return 0;
}

CODE_DLLEXPORT void code_teardown_codegen_fallback(void) CODE_NOTSAFEPOINT
{
}

CODE_DLLEXPORT size_t code_jit_total_bytes_fallback(void)
{
    return 0;
}

CODE_DLLEXPORT void *code_create_native_fallback(code_array_t *methods, LLVMOrcThreadSafeModuleRef llvmmod, const code_cgparams_t *cgparams, int _policy, int _imaging_mode, int _external_linkage, size_t _world) UNAVAILABLE

CODE_DLLEXPORT void code_dump_compiles_fallback(void *s)
{
}

CODE_DLLEXPORT void code_dump_emitted_mi_name_fallback(void *s)
{
}

CODE_DLLEXPORT void code_dump_llvm_opt_fallback(void *s)
{
}

CODE_DLLEXPORT code_value_t *code_dump_fptr_asm_fallback(uint64_t fptr, char emit_mc, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE

CODE_DLLEXPORT code_value_t *code_dump_function_asm_fallback(code_llvmf_dump_t* dump, char emit_mc, const char* asm_variant, const char *debuginfo, char binary, char raw) UNAVAILABLE

CODE_DLLEXPORT void code_get_function_id_fallback(void *native_code, code_code_instance_t *ncode,
        int32_t *func_idx, int32_t *specfunc_idx) UNAVAILABLE


CODE_DLLEXPORT void *code_get_llvm_function_fallback(void *native_code, uint32_t idx) UNAVAILABLE

CODE_DLLEXPORT LLVMOrcThreadSafeModuleRef code_get_llvm_module_fallback(void *native_code) UNAVAILABLE

CODE_DLLEXPORT void *code_type_to_llvm_fallback(code_value_t *jt, LLVMContextRef llvmctxt, bool_t *isboxed) UNAVAILABLE

CODE_DLLEXPORT code_value_t *code_get_libllvm_fallback(void) CODE_NOTSAFEPOINT
{
    return code_nothing;
}

CODE_DLLEXPORT uint64_t code_getUnwindInfo_fallback(uint64_t dwAddr)
{
    return 0;
}

CODE_DLLEXPORT void code_build_newpm_pipeline_fallback(void *MPM, void *PB, void *config) UNAVAILABLE

CODE_DLLEXPORT void code_register_passbuilder_callbacks_fallback(void *PB) { }

#define MODULE_PASS(NAME, CLASS, CREATE_PASS) \
    CODE_DLLEXPORT void LLVMExtraMPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define CGSCC_PASS(NAME, CLASS, CREATE_PASS) \
    CODE_DLLEXPORT void LLVMExtraCGPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define FUNCTION_PASS(NAME, CLASS, CREATE_PASS) \
    CODE_DLLEXPORT void LLVMExtraFPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define LOOP_PASS(NAME, CLASS, CREATE_PASS) \
    CODE_DLLEXPORT void LLVMExtraLPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE

#include "llvm-code-passes.inc"

#undef MODULE_PASS
#undef CGSCC_PASS
#undef FUNCTION_PASS
#undef LOOP_PASS

//LLVM C api to the code JIT
CODE_DLLEXPORT void* CODEJITGetLLVMOrcExecutionSession_fallback(void* JIT) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITGetJuliaOJIT_fallback(void) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITGetExternalJITDylib_fallback(void* JIT) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITAddObjectFile_fallback(void* JIT, void* JD, void* ObjBuffer) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITAddLLVMIRModule_fallback(void* JIT, void* JD, void* TSM) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITLookup_fallback(void* JIT, void* Result, const char *Name) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITMangleAndIntern_fallback(void* JIT, const char *Name) UNAVAILABLE

CODE_DLLEXPORT const char *CODEJITGetTripleString_fallback(void* JIT) UNAVAILABLE

CODE_DLLEXPORT const char CODEJITGetGlobalPrefix_fallback(void* JIT) UNAVAILABLE

CODE_DLLEXPORT const char *CODEJITGetDataLayoutString_fallback(void* JIT) UNAVAILABLE

CODE_DLLEXPORT void* CODEJITGetIRCompileLayer_fallback(void* JIT) UNAVAILABLE
