
// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: This file provides a fallback implementation of the languagegen plugin interface,
// used when libnextcode-codegen is not available.

#include "code.h"
#include "code_internal.h"

#include "intrinsics.h"

#define UNAVAILABLE { language_errorf("%s: not available in this build of NeXTCode", __func__); }

LANGUAGE_DLLEXPORT void language_dump_native_fallback(void *native_language,
        const char *bc_fname, const char *unopt_bc_fname, const char *obj_fname, const char *asm_fname,
        ios_t *z, ios_t *s) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvm_gvs_fallback(void *native_language, arraylist_t *gvs) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvm_external_fns_fallback(void *native_language, arraylist_t *gvs) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_extern_c_fallback(language_function_t *f, language_value_t *rt, language_value_t *argt, char *name) UNAVAILABLE
LANGUAGE_DLLEXPORT language_value_t *language_dump_method_asm_fallback(language_method_instance_t *linfo, size_t world,
        char emit_mc, char getwrapper, const char* asm_variant, const char *debuginfo, char binary) UNAVAILABLE
LANGUAGE_DLLEXPORT language_value_t *language_dump_function_ir_fallback(language_llvmf_dump_t *dump, char strip_ir_metadata, char dump_module, const char *debuginfo) UNAVAILABLE
LANGUAGE_DLLEXPORT void language_get_llvmf_defn_fallback(language_llvmf_dump_t *dump, language_method_instance_t *linfo, language_language_info_t *src, char getwrapper, char optimize, const language_cgparams_t params) UNAVAILABLE

LANGUAGE_DLLEXPORT void *language_LLVMCreateDisasm_fallback(const char *TripleName, void *DisInfo, int TagType, void *GetOpInfo, void *SymbolLookUp) UNAVAILABLE
LANGUAGE_DLLEXPORT size_t language_LLVMDisasmInstruction_fallback(void *DC, uint8_t *Bytes, uint64_t BytesSize, uint64_t PC, char *OutString, size_t OutStringSize) UNAVAILABLE

LANGUAGE_DLLEXPORT void language_init_languagegen_fallback(void) { }

LANGUAGE_DLLEXPORT int language_getFunctionInfo_fallback(language_frame_t **frames, uintptr_t pointer, int skipC, int noInline)
{
    return 0;
}

LANGUAGE_DLLEXPORT void language_register_fptrs_fallback(uint64_t image_base, const struct _language_image_fptrs_t *fptrs,
                       language_method_instance_t **linfos, size_t n)
{
    (void)image_base; (void)fptrs; (void)linfos; (void)n;
}

LANGUAGE_DLLEXPORT void language_generate_fptr_for_unspecialized_fallback(language_language_instance_t *unspec)
{
    language_atomic_store_release(&unspec->invoke, &language_fptr_interpret_call);
}

LANGUAGE_DLLEXPORT int language_compile_languageinst_fallback(language_language_instance_t *unspec)
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

LANGUAGE_DLLEXPORT void language_teardown_languagegen_fallback(void) LANGUAGE_NOTSAFEPOINT
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

LANGUAGE_DLLEXPORT void language_get_function_id_fallback(void *native_language, language_language_instance_t *nlanguage,
        int32_t *func_idx, int32_t *specfunc_idx) UNAVAILABLE


LANGUAGE_DLLEXPORT void *language_get_llvm_function_fallback(void *native_language, uint32_t idx) UNAVAILABLE

LANGUAGE_DLLEXPORT LLVMOrcThreadSafeModuleRef language_get_llvm_module_fallback(void *native_language) UNAVAILABLE

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

#include "llvm-language-passes.inc"

#undef MODULE_PASS
#undef CGSCC_PASS
#undef FUNCTION_PASS
#undef LOOP_PASS

//LLVM C api to the language JIT
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
