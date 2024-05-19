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

// This file provides a fallback implementation of the codegen plugin interface,
// used when libcode-codegen is not available.

#include "code.h"
#include "language_internal.h"

#include "intrinsics.h"

#define UNAVAILABLE { language_errorf("%s: not available in this build of Julia", __func__); }

LANGUAGE_DLLEXPORT void language_dump_native_fallback(void *native_code,
        const char *bc_fname, const char *unopt_bc_fname, const char *obj_fname, const char *asm_fname,
        ios_t *z, ios_t *s) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvm_gvs_fallback(void *native_code, arraylist_t *gvs) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvm_external_fns_fallback(void *native_code, arraylist_t *gvs) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_extern_c_fallback(language_function_t *f, language_value_t *rt, language_value_t *argt, char *name) UNAVAILABLE
LANGUAGE_DLLEXPORT language_value_t *language_dump_method_asm_fallback(language_method_instance_t *linfo, size_t world,
        char emit_mc, char getwrapper, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE
LANGUAGE_DLLEXPORT language_value_t *language_dump_function_ir_fallback(language_llvmf_dump_t *dump, char strip_ir_metadata, char dump_module, const char *debuginfo) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvmf_defn_fallback(language_llvmf_dump_t *dump, language_method_instance_t *linfo, size_t world, char getwrapper, char optimize, const language_cgparams_t params) UNAVAILABLE

LANGUAGE_DLLEXPORT void *language_LLVMCreateDisasm_fallback(const char *TripleName, void *DisInfo, int TagType, void *GetOpInfo, void *SymbolLookUp) UNAVAILABLE
LANGUAGE_DLLEXPORT size_t language_LLVMDisasmInstruction_fallback(void *DC, uint8_t *Bytes, uint64_t BytesSize, uint64_t PC, char *OutString, size_t OutStringSize) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_init_codegen_fallback(void) { }

LANGUAGE_DLLEXPORT int language_getFunctionInfo_fallback(language_frame_t **frames, uintptr_t pointer, int skipC, int noInline)
{
    return 0;
}

LANGUAGE_DLLEXPORT void language_register_fptrs_fallback(uint64_t image_base, const struct _language_image_fptrs_t *fptrs,
                       language_method_instance_t **linfos, size_t n)
{
    (void)image_base; (void)fptrs; (void)linfos; (void)n;
}

LANGUAGE_DLLEXPORT void language_generate_fptr_for_unspecialized_fallback(language_code_instance_t *unspec)
{
    language_atomic_store_release(&unspec->invoke, &language_fptr_interpret_call);
}

LANGUAGE_DLLEXPORT int language_compile_codeinst_fallback(language_code_instance_t *unspec)
{
    // Do nothing. The caller will notice that we failed to provide a an ->invoke and trigger
    // appropriate fallbacks.
    return 0;
}

LANGUAGE_DLLEXPORT uint32_t language_get_LLVM_VERSION_fallback(void)
{
    return 0;
}

LANGUAGE_DLLEXPORT int language_compile_extern_c_fallback(LLVMOrcThreadSafeModuleRef llvmmod, void *params, void *sysimg, language_value_t *declrt, language_value_t *sigt)
{
    return 0;
}

LANGUAGE_DLLEXPORT void language_teardown_codegen_fallback(void) LANGUAGE_NOTSAFEPOINT
{
}

LANGUAGE_DLLEXPORT size_t language_jit_total_bytes_fallback(void)
{
    return 0;
}

LANGUAGE_DLLEXPORT void *language_create_native_fallback(language_array_t *methods, LLVMOrcThreadSafeModuleRef llvmmod, const language_cgparams_t *cgparams, int _policy, int _imaging_mode, int _external_linkage, size_t _world) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_dump_compiles_fallback(void *s)
{
}

LANGUAGE_DLLEXPORT void language_dump_emitted_mi_name_fallback(void *s)
{
}

LANGUAGE_DLLEXPORT void language_dump_llvm_opt_fallback(void *s)
{
}

LANGUAGE_DLLEXPORT language_value_t *language_dump_fptr_asm_fallback(uint64_t fptr, char emit_mc, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE

LANGUAGE_DLLEXPORT language_value_t *language_dump_function_asm_fallback(language_llvmf_dump_t* dump, char emit_mc, const char* asm_variant, const char *debuginfo, char binary, char raw) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_get_function_id_fallback(void *native_code, language_code_instance_t *ncode,
        int32_t *func_idx, int32_t *specfunc_idx) UNAVAILABLE


LANGUAGE_DLLEXPORT void *language_get_llvm_function_fallback(void *native_code, uint32_t idx) UNAVAILABLE

LANGUAGE_DLLEXPORT LLVMOrcThreadSafeModuleRef language_get_llvm_module_fallback(void *native_code) UNAVAILABLE

LANGUAGE_DLLEXPORT void *language_type_to_llvm_fallback(language_value_t *jt, LLVMContextRef llvmctxt, bool_t *isboxed) UNAVAILABLE

LANGUAGE_DLLEXPORT language_value_t *language_get_libllvm_fallback(void) LANGUAGE_NOTSAFEPOINT
{
    return language_nothing;
}

LANGUAGE_DLLEXPORT uint64_t language_getUnwindInfo_fallback(uint64_t dwAddr)
{
    return 0;
}

LANGUAGE_DLLEXPORT void language_build_newpm_pipeline_fallback(void *MPM, void *PB, void *config) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_register_passbuilder_callbacks_fallback(void *PB) { }

#define MODULE_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT void LLVMExtraMPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define CGSCC_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT void LLVMExtraCGPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define FUNCTION_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT void LLVMExtraFPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE
#define LOOP_PASS(NAME, CLASS, CREATE_PASS) \
    LANGUAGE_DLLEXPORT void LLVMExtraLPMAdd##CLASS##_fallback(void *PM) UNAVAILABLE

#include "llvm-julia-passes.inc"

#undef MODULE_PASS
#undef CGSCC_PASS
#undef FUNCTION_PASS
#undef LOOP_PASS

//LLVM C api to the julia JIT
LANGUAGE_DLLEXPORT void* LANGUAGEJITGetLLVMOrcExecutionSession_fallback(void* JIT) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITGetJuliaOJIT_fallback(void) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITGetExternalJITDylib_fallback(void* JIT) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITAddObjectFile_fallback(void* JIT, void* JD, void* ObjBuffer) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITAddLLVMIRModule_fallback(void* JIT, void* JD, void* TSM) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITLookup_fallback(void* JIT, void* Result, const char *Name) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITMangleAndIntern_fallback(void* JIT, const char *Name) UNAVAILABLE

LANGUAGE_DLLEXPORT const char *LANGUAGEJITGetTripleString_fallback(void* JIT) UNAVAILABLE

LANGUAGE_DLLEXPORT const char LANGUAGEJITGetGlobalPrefix_fallback(void* JIT) UNAVAILABLE

LANGUAGE_DLLEXPORT const char *LANGUAGEJITGetDataLayoutString_fallback(void* JIT) UNAVAILABLE

LANGUAGE_DLLEXPORT void* LANGUAGEJITGetIRCompileLayer_fallback(void* JIT) UNAVAILABLE
