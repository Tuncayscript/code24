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

#include <setjmp.h>
#include <string>
#include <fstream>
#include <map>
#include <array>
#include <vector>
#include <set>
#include <functional>

// target machine computation
#include <llvm/CodeGen/TargetSubtargetInfo.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Target/TargetOptions.h>
#if LANGUAGE_LLVM_VERSION >= 170000
#include <llvm/TargetParser/Host.h>
#else
#include <llvm/ADT/Host.h>
#endif
#include <llvm/Support/TargetSelect.h>
#include <llvm/Object/SymbolSize.h>

#include <llvm/InitializePasses.h>

// IR building
#include <llvm/IR/IntrinsicInst.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/IR/DIBuilder.h>
#include <llvm/AsmParser/Parser.h>
#include <llvm/DebugInfo/DIContext.h>
#include "llvm/IR/DebugInfoMetadata.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/Attributes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/MDBuilder.h>
#include <llvm/Analysis/InstructionSimplify.h>

// support
#include <llvm/ADT/SmallBitVector.h>
#include <llvm/ADT/Statistic.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/SourceMgr.h> // for llvmcall
#include <llvm/Transforms/Utils/Cloning.h> // for llvmcall inlining
#include <llvm/Transforms/Utils/BasicBlockUtils.h>
#include <llvm/IR/Verifier.h> // for llvmcall validation
#include <llvm/IR/PassTimingInfo.h>
#include <llvm/Bitcode/BitcodeWriter.h>

// C API
#include <llvm-c/Types.h>

// for configuration options
#include <llvm/Support/PrettyStackTrace.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Process.h>

#include <llvm/IR/InlineAsm.h>
#if defined(_CPU_ARM_) || defined(_CPU_AARCH64_)
#  include <sys/utsname.h>
#endif
#if defined(USE_POLLY)
#include <polly/RegisterPasses.h>
#include <polly/ScopDetection.h>
#endif
#include <llvm/Target/TargetMachine.h>

#include "llvm/Support/Path.h" // for llvm::sys::path
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Linker/Linker.h>

using namespace llvm;

static bool language_fpo_disabled(const Triple &TT) {
#ifdef LANGUAGE_DISABLE_FPO
    return true;
#endif
#ifdef _COMPILER_MSAN_ENABLED_
    // MSAN doesn't support FPO
    return true;
#endif
    if (TT.isOSLinux() || TT.isOSWindows() || TT.isOSFreeBSD() || TT.isOSOpenBSD()) {
        return true;
    }
    return false;
}

static bool language_floattemp_var_needed(const Triple &TT) {
#ifdef LANGUAGE_NEED_FLOATTEMP_VAR
    return true;
#endif
    return TT.getArch() == Triple::x86;
}

//Drag some useful type functions into our namespace
//to reduce verbosity of our code
auto getInt1Ty(LLVMContext &ctxt) {
    return Type::getInt1Ty(ctxt);
}
auto getInt8Ty(LLVMContext &ctxt) {
    return Type::getInt8Ty(ctxt);
}
auto getInt16Ty(LLVMContext &ctxt) {
    return Type::getInt16Ty(ctxt);
}
auto getInt32Ty(LLVMContext &ctxt) {
    return Type::getInt32Ty(ctxt);
}
auto getInt64Ty(LLVMContext &ctxt) {
    return Type::getInt64Ty(ctxt);
}
auto getHalfTy(LLVMContext &ctxt) {
    return Type::getHalfTy(ctxt);
}
auto getFloatTy(LLVMContext &ctxt) {
    return Type::getFloatTy(ctxt);
}
auto getDoubleTy(LLVMContext &ctxt) {
    return Type::getDoubleTy(ctxt);
}
auto getBFloatTy(LLVMContext &ctxt) {
    return Type::getBFloatTy(ctxt);
}
auto getFP128Ty(LLVMContext &ctxt) {
    return Type::getFP128Ty(ctxt);
}
auto getVoidTy(LLVMContext &ctxt) {
    return Type::getVoidTy(ctxt);
}
auto getCharTy(LLVMContext &ctxt) {
    return getInt32Ty(ctxt);
}
auto getInt8PtrTy(LLVMContext &ctxt) {
    return Type::getInt8PtrTy(ctxt);
}
auto getInt16PtrTy(LLVMContext &ctxt) {
    return Type::getInt16PtrTy(ctxt);
}
auto getInt32PtrTy(LLVMContext &ctxt) {
    return Type::getInt32PtrTy(ctxt);
}
auto getInt64PtrTy(LLVMContext &ctxt) {
    return Type::getInt64PtrTy(ctxt);
}
auto getFloatPtrTy(LLVMContext &ctxt) {
    return Type::getFloatPtrTy(ctxt);
}
auto getDoublePtrTy(LLVMContext &ctxt) {
    return Type::getDoublePtrTy(ctxt);
}

typedef Instruction TerminatorInst;

#if defined(_OS_WINDOWS_) && !defined(NOMINMAX)
#define NOMINMAX
#endif

#include "jitlayers.h"
#include "processor.h"
#include "language_assert.h"

#undef DEBUG_TYPE //LLVM occasionally likes to set DEBUG_TYPE in a header...
#define DEBUG_TYPE "language_irgen_codegen"

void setName(language_codegen_params_t &params, Value *V, const Twine &Name)
{
    // we do the constant check again later, duplicating it here just makes sure the assertion
    // fires on debug builds even if debug info is not enabled
    // note that if this assertion fires then the implication is that the caller of setName
    // is not checking that setName is only called for non-folded instructions (e.g. folded bitcasts
    // and 0-byte geps), which can result in information loss on the renamed instruction.
    assert((isa<Constant>(V) || isa<Instruction>(V)) && "Should only set names on instructions!");
    if (params.debug_level >= 2 && !isa<Constant>(V)) {
        V->setName(Name);
    }
}

void setName(language_codegen_params_t &params, Value *V, std::function<std::string()> GetName)
{
    assert((isa<Constant>(V) || isa<Instruction>(V)) && "Should only set names on instructions!");
    if (params.debug_level >= 2 && !isa<Constant>(V)) {
        V->setName(Twine(GetName()));
    }
}

void setNameWithField(language_codegen_params_t &params, Value *V, std::function<StringRef()> GetObjName, language_datatype_t *jt, unsigned idx, const Twine &suffix)
{
    assert((isa<Constant>(V) || isa<Instruction>(V)) && "Should only set names on instructions!");
    if (params.debug_level >= 2 && !isa<Constant>(V)) {
        if (language_is_tuple_type(jt)){
            V->setName(Twine(GetObjName()) + "[" + Twine(idx + 1) + "]"+ suffix);
            return;
        }

        if (language_is_namedtuple_type(jt)) {
            auto names = language_tparam0(jt);
            assert(language_is_tuple(names));
            if (idx < language_nfields(names)) {
                auto name = language_fieldref(names, idx);
                assert(language_is_symbol(name));
                V->setName(Twine(GetObjName()) + "." + Twine(language_symbol_name((language_sym_t*)name)) + suffix);
                return;
            }
        } else {
            auto flds = language_field_names(jt);
            if (idx < language_svec_len(flds)) {
                auto name = language_svecref(flds, idx);
                assert(language_is_symbol(name));
                V->setName(Twine(GetObjName()) + "." + Twine(language_symbol_name((language_sym_t*)name)) + suffix);
                return;
            }
        }
        V->setName(Twine(GetObjName()) + "." + Twine("unknown field") + suffix);
    }
}

STATISTIC(EmittedAllocas, "Number of allocas emitted");
STATISTIC(EmittedIntToPtrs, "Number of inttoptrs emitted");
STATISTIC(ModulesCreated, "Number of LLVM Modules created");
STATISTIC(EmittedBoxCompares, "Number of box compares emitted");
STATISTIC(EmittedBitsUnionCompares, "Number of bitsunion compares emitted");
STATISTIC(EmittedBitsCompares, "Number of bits compares emitted");
STATISTIC(EmittedEgals, "Number of egals emitted");
STATISTIC(EmittedOpfields, "Number of opfields emitted");
STATISTIC(EmittedBuiltinCalls, "Number of builtin calls emitted");
STATISTIC(EmittedLANGUAGECalls, "Number of jlcalls emitted");
STATISTIC(EmittedSpecfunCalls, "Number of specialized calls emitted");
STATISTIC(EmittedInvokes, "Number of invokes emitted");
STATISTIC(EmittedCalls, "Number of calls emitted");
STATISTIC(EmittedUndefVarErrors, "Number of undef var errors emitted");
STATISTIC(EmittedOpaqueClosureFunctions, "Number of opaque closures emitted");
STATISTIC(EmittedToLANGUAGEInvokes, "Number of tojlinvoke calls emitted");
STATISTIC(EmittedCFuncInvalidates, "Number of C function invalidates emitted");
STATISTIC(GeneratedCFuncWrappers, "Number of C function wrappers generated");
STATISTIC(GeneratedCCallables, "Number of C-callable functions generated");
STATISTIC(GeneratedInvokeWrappers, "Number of invoke wrappers generated");
STATISTIC(EmittedFunctions, "Number of functions emitted");

extern "C" LANGUAGE_DLLEXPORT_CODEGEN
void language_dump_emitted_mi_name_impl(void *s)
{
    **language_ExecutionEngine->get_dump_emitted_mi_name_stream() = (ios_t*)s;
}

extern "C" {

#include "builtin_proto.h"

extern void __stack_chk_fail();

#ifdef _OS_WINDOWS_
#if defined(_CPU_X86_64_)
#if defined(_COMPILER_GCC_)
extern void ___chkstk_ms(void);
#else
extern void __chkstk(void);
#endif
#else
#if defined(_COMPILER_GCC_)
#undef _alloca
extern void _alloca(void);
#else
extern void _chkstk(void);
#endif
#endif
//void *force_chkstk(void) {
//    return alloca(40960);
//}
#endif
}

// shared llvm state
#define language_Module ctx.f->getParent()
#define language_builderModule(builder) (builder).GetInsertBlock()->getParent()->getParent()
#define prepare_call(Callee) prepare_call_in(language_Module, (Callee))

// types
struct language_typecache_t {
    Type *T_ptr;
    Type *T_size;
    Type *T_jlvalue;
    Type *T_pjlvalue;
    Type *T_prjlvalue;
    Type *T_ppjlvalue;
    Type *T_pprjlvalue;
    StructType *T_jlgenericmemory;
    StructType *T_jlarray;
    Type *T_pjlarray;
    FunctionType *T_jlfunc;
    FunctionType *T_jlfuncparams;

    IntegerType *T_sigatomic;

    Type *T_ppint8;
    unsigned sizeof_ptr;
    Align alignof_ptr;

    bool initialized;

    language_typecache_t() :
        T_ptr(nullptr), T_jlvalue(nullptr), T_pjlvalue(nullptr), T_prjlvalue(nullptr),
        T_ppjlvalue(nullptr), T_pprjlvalue(nullptr),
        T_jlgenericmemory(nullptr), T_jlarray(nullptr), T_pjlarray(nullptr),
        T_jlfunc(nullptr), T_jlfuncparams(nullptr), T_sigatomic(nullptr), T_ppint8(nullptr),
        initialized(false) {}

    void initialize(LLVMContext &context, const DataLayout &DL) {
        if (initialized) {
            return;
        }
        initialized = true;
        T_ptr = getInt8PtrTy(context);
        T_ppint8 = PointerType::get(getInt8PtrTy(context), 0);
        T_sigatomic = Type::getIntNTy(context, sizeof(sig_atomic_t) * 8);
        T_size = DL.getIntPtrType(context);
        sizeof_ptr = DL.getPointerSize();
        // use pointer abi alignment for intptr_t
        alignof_ptr = DL.getPointerABIAlignment(0);
        T_jlvalue = JuliaType::get_jlvalue_ty(context);
        T_pjlvalue = PointerType::get(T_jlvalue, 0);
        T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        T_ppjlvalue = PointerType::get(T_pjlvalue, 0);
        T_pprjlvalue = PointerType::get(T_prjlvalue, 0);

        T_jlfunc = JuliaType::get_jlfunc_ty(context);
        assert(T_jlfunc != NULL);
        T_jlfuncparams = JuliaType::get_jlfuncparams_ty(context);
        assert(T_jlfuncparams != NULL);

        T_jlgenericmemory = StructType::get(context, { T_size, T_pprjlvalue /* [, real-owner] */ });
        Type *vaelts[] = { PointerType::get(getInt8Ty(context), AddressSpace::Loaded),
                           PointerType::get(T_jlgenericmemory, AddressSpace::Tracked),
                           // dimsize[ndims]
        };
        T_jlarray = StructType::get(context, ArrayRef<Type*>(vaelts));
        T_pjlarray = PointerType::get(T_jlarray, 0);
    }
};

struct language_tbaacache_t {
    // type-based alias analysis nodes.  Indentation of comments indicates hierarchy.
    MDNode *tbaa_root;     // Everything
    MDNode *tbaa_gcframe;    // GC frame
    // LLVM should have enough info for alias analysis of non-gcframe stack slot
    // this is mainly a place holder for `language_cgval_t::tbaa`
    MDNode *tbaa_stack;      // stack slot
    MDNode *tbaa_unionselbyte;   // a selector byte in isbits Union struct fields
    MDNode *tbaa_data;       // Any user data that `pointerset/ref` are allowed to alias
    MDNode *tbaa_binding;        // language_binding_t::value
    MDNode *tbaa_value;          // language_value_t, that is not language_array_t or language_genericmemory_t
    MDNode *tbaa_mutab;              // mutable type
    MDNode *tbaa_datatype;               // datatype
    MDNode *tbaa_immut;              // immutable type
    MDNode *tbaa_ptrarraybuf;    // Data in an array of boxed values
    MDNode *tbaa_arraybuf;       // Data in an array of POD
    MDNode *tbaa_array;      // language_array_t or language_genericmemory_t
    MDNode *tbaa_arrayptr;       // The pointer inside a language_array_t (to memoryref)
    MDNode *tbaa_arraysize;      // A size in a language_array_t
    MDNode *tbaa_arrayselbyte;   // a selector byte in a isbits Union language_genericmemory_t
    MDNode *tbaa_memoryptr;      // The pointer inside a language_genericmemory_t
    MDNode *tbaa_memorylen;      // The length in a language_genericmemory_t
    MDNode *tbaa_memoryown;      // The owner in a foreign language_genericmemory_t
    MDNode *tbaa_const;      // Memory that is immutable by the time LLVM can see it
    bool initialized;

    language_tbaacache_t(): tbaa_root(nullptr), tbaa_gcframe(nullptr), tbaa_stack(nullptr),
                    tbaa_unionselbyte(nullptr), tbaa_data(nullptr), tbaa_binding(nullptr),
                    tbaa_value(nullptr), tbaa_mutab(nullptr), tbaa_datatype(nullptr),
                    tbaa_immut(nullptr), tbaa_ptrarraybuf(nullptr), tbaa_arraybuf(nullptr),
                    tbaa_array(nullptr), tbaa_arrayptr(nullptr), tbaa_arraysize(nullptr),
                    tbaa_arrayselbyte(nullptr), tbaa_memoryptr(nullptr), tbaa_memorylen(nullptr), tbaa_memoryown(nullptr),
                    tbaa_const(nullptr), initialized(false) {}

    auto tbaa_make_child(MDBuilder &mbuilder, const char *name, MDNode *parent = nullptr, bool isConstant = false) {
        MDNode *scalar = mbuilder.createTBAAScalarTypeNode(name, parent ? parent : tbaa_root);
        MDNode *n = mbuilder.createTBAAStructTagNode(scalar, scalar, 0, isConstant);
        return std::make_pair(n, scalar);
    }

    void initialize(llvm::LLVMContext &context) {
        if (initialized) {
            assert(&tbaa_root->getContext() == &context);
            return;
        }
        initialized = true;
        MDBuilder mbuilder(context);
        MDNode *jtbaa = mbuilder.createTBAARoot("jtbaa");
        tbaa_root = mbuilder.createTBAAScalarTypeNode("jtbaa", jtbaa);
        tbaa_gcframe = tbaa_make_child(mbuilder, "jtbaa_gcframe").first;
        MDNode *tbaa_stack_scalar;
        std::tie(tbaa_stack, tbaa_stack_scalar) = tbaa_make_child(mbuilder, "jtbaa_stack");
        tbaa_unionselbyte = tbaa_make_child(mbuilder, "jtbaa_unionselbyte", tbaa_stack_scalar).first;
        MDNode *tbaa_data_scalar;
        std::tie(tbaa_data, tbaa_data_scalar) = tbaa_make_child(mbuilder, "jtbaa_data");
        tbaa_binding = tbaa_make_child(mbuilder, "jtbaa_binding", tbaa_data_scalar).first;
        MDNode *tbaa_value_scalar;
        std::tie(tbaa_value, tbaa_value_scalar) =
            tbaa_make_child(mbuilder, "jtbaa_value", tbaa_data_scalar);
        MDNode *tbaa_mutab_scalar;
        std::tie(tbaa_mutab, tbaa_mutab_scalar) =
            tbaa_make_child(mbuilder, "jtbaa_mutab", tbaa_value_scalar);
        tbaa_datatype = tbaa_make_child(mbuilder, "jtbaa_datatype", tbaa_mutab_scalar).first;
        tbaa_immut = tbaa_make_child(mbuilder, "jtbaa_immut", tbaa_value_scalar).first;
        tbaa_arraybuf = tbaa_make_child(mbuilder, "jtbaa_arraybuf", tbaa_data_scalar).first;
        tbaa_ptrarraybuf = tbaa_make_child(mbuilder, "jtbaa_ptrarraybuf", tbaa_data_scalar).first;
        MDNode *tbaa_array_scalar;
        std::tie(tbaa_array, tbaa_array_scalar) = tbaa_make_child(mbuilder, "jtbaa_array");
        tbaa_arrayptr = tbaa_make_child(mbuilder, "jtbaa_arrayptr", tbaa_array_scalar).first;
        tbaa_arraysize = tbaa_make_child(mbuilder, "jtbaa_arraysize", tbaa_array_scalar).first;
        tbaa_arrayselbyte = tbaa_make_child(mbuilder, "jtbaa_arrayselbyte", tbaa_array_scalar).first;
        tbaa_memoryptr = tbaa_make_child(mbuilder, "jtbaa_memoryptr", tbaa_array_scalar, true).first;
        tbaa_memorylen = tbaa_make_child(mbuilder, "jtbaa_memorylen", tbaa_array_scalar, true).first;
        tbaa_memoryown = tbaa_make_child(mbuilder, "jtbaa_memoryown", tbaa_array_scalar, true).first;
        tbaa_const = tbaa_make_child(mbuilder, "jtbaa_const", nullptr, true).first;
    }
};

struct language_noaliascache_t {
    // Each domain operates completely independently.
    // "No aliasing" is inferred if it is implied by any domain.

    // memory regions domain
    struct language_regions_t {
        MDNode *gcframe;        // GC frame
        MDNode *stack;          // Stack slot
        MDNode *data;           // Any user data that `pointerset/ref` are allowed to alias
        MDNode *type_metadata;  // Non-user-accessible type metadata incl. union selectors, etc.
        MDNode *constant;       // Memory that is immutable by the time LLVM can see it

        language_regions_t(): gcframe(nullptr), stack(nullptr), data(nullptr), type_metadata(nullptr), constant(nullptr) {}

        void initialize(llvm::LLVMContext &context) {
            MDBuilder mbuilder(context);
            MDNode *domain = mbuilder.createAliasScopeDomain("jnoalias");

            this->gcframe = mbuilder.createAliasScope("jnoalias_gcframe", domain);
            this->stack = mbuilder.createAliasScope("jnoalias_stack", domain);
            this->data = mbuilder.createAliasScope("jnoalias_data", domain);
            this->type_metadata = mbuilder.createAliasScope("jnoalias_typemd", domain);
            this->constant = mbuilder.createAliasScope("jnoalias_const", domain);
        }
    } regions;

    // `@aliasscope` domain
    struct language_aliasscope_t {
        MDNode *current;

        language_aliasscope_t(): current(nullptr) {}

        // No init required, this->current is only used to store the currently active aliasscope
        void initialize(llvm::LLVMContext &context) {}
    } aliasscope;

    bool initialized;

    language_noaliascache_t(): regions(), aliasscope(), initialized(false) {}

    void initialize(llvm::LLVMContext &context) {
        if (initialized) {
            assert(&regions.constant->getContext() == &context);
            return;
        }
        initialized = true;
        regions.initialize(context);
        aliasscope.initialize(context);
    }
};

struct language_debugcache_t {
    // Basic DITypes
    DIDerivedType *language_pvalue_dillvmt;
    DIDerivedType *language_ppvalue_dillvmt;
    DISubroutineType *language_di_func_sig;
    DISubroutineType *language_di_func_null_sig;
    bool initialized;

    language_debugcache_t()
    : language_pvalue_dillvmt(nullptr), language_ppvalue_dillvmt(nullptr),
    language_di_func_sig(nullptr), language_di_func_null_sig(nullptr), initialized(false) {}

    void initialize(Module *m);
};


// constants
static bool type_is_ghost(Type *ty)
{
    return (ty == getVoidTy(ty->getContext()) || ty->isEmptyTy());
}

// should agree with `Core.Compiler.hasuniquerep`
static bool type_has_unique_rep(language_value_t *t)
{
    if (t == (language_value_t*)language_typeofbottom_type)
        return false;
    if (t == language_bottom_type)
        return true;
    if (language_is_typevar(t))
        return false;
    if (!language_is_kind(language_typeof(t)))
        return true;
    if (language_is_concrete_type(t))
        return true;
    if (language_is_datatype(t)) {
        language_datatype_t *dt = (language_datatype_t*)t;
        if (dt->name != language_tuple_typename) {
            for (size_t i = 0; i < language_nparams(dt); i++)
                if (!type_has_unique_rep(language_tparam(dt, i)))
                    return false;
            return true;
        }
    }
    return false;
}

static bool is_uniquerep_Type(language_value_t *t)
{
    return language_is_type_type(t) && type_has_unique_rep(language_tparam0(t));
}

class language_codectx_t;
struct JuliaVariable {
public:
    StringLiteral name;
    bool isconst;
    Type *(*_type)(Type *T_size);

    JuliaVariable(const JuliaVariable&) = delete;
    JuliaVariable(const JuliaVariable&&) = delete;
    GlobalVariable *realize(Module *m) {
        if (GlobalValue *V = m->getNamedValue(name))
            return cast<GlobalVariable>(V);
        auto T_size = m->getDataLayout().getIntPtrType(m->getContext());
        return new GlobalVariable(*m, _type(T_size),
                isconst, GlobalVariable::ExternalLinkage,
                NULL, name);
    }
    GlobalVariable *realize(language_codectx_t &ctx);
};
static inline void add_named_global(JuliaVariable *name, void *addr)
{
    add_named_global(name->name, addr);
}


typedef FunctionType *(*TypeFnContextOnly)(LLVMContext &C);
typedef FunctionType *(*TypeFnContextAndSizeT)(LLVMContext &C, Type *T_size);
typedef FunctionType *(*TypeFnContextAndTriple)(LLVMContext &C, const Triple &triple);

FunctionType *invoke_type(TypeFnContextOnly f, Module &M)
{
    return f(M.getContext());
}

FunctionType *invoke_type(TypeFnContextAndSizeT f, Module &M)
{
    return f(M.getContext(), M.getDataLayout().getIntPtrType(M.getContext()));
}

FunctionType *invoke_type(TypeFnContextAndTriple f, Module &M)
{
    return f(M.getContext(), Triple(M.getTargetTriple()));
}

template<typename TypeFn_t = TypeFnContextOnly>
struct JuliaFunction {
public:
    llvm::StringLiteral name;
    TypeFn_t _type;
    llvm::AttributeList (*_attrs)(llvm::LLVMContext &C);

    JuliaFunction(const JuliaFunction&) = delete;
    JuliaFunction(const JuliaFunction&&) = delete;
    llvm::Function *realize(llvm::Module *m) {
        if (llvm::GlobalValue *V = m->getNamedValue(name))
            return llvm::cast<llvm::Function>(V);
        llvm::Function *F = llvm::Function::Create(invoke_type(_type, *m),
                         llvm::Function::ExternalLinkage,
                         name, m);
        if (_attrs)
            F->setAttributes(_attrs(m->getContext()));
        return F;
    }
};

template<typename T, typename TypeFn_t>
static inline void add_named_global(JuliaFunction<TypeFn_t> *name, T *addr)
{
    // cast through integer to avoid c++ pedantic warning about casting between
    // data and code pointers
    add_named_global(name->name, (void*)(uintptr_t)addr);
}
template<typename T>
static inline void add_named_global(StringRef name, T *addr)
{
    // cast through integer to avoid c++ pedantic warning about casting between
    // data and code pointers
    add_named_global(name, (void*)(uintptr_t)addr);
}

AttributeSet Attributes(LLVMContext &C, std::initializer_list<Attribute::AttrKind> attrkinds, std::initializer_list<Attribute> extra={})
{
    SmallVector<Attribute, 8> attrs(attrkinds.size() + extra.size());
    for (size_t i = 0; i < attrkinds.size(); i++)
        attrs[i] = Attribute::get(C, attrkinds.begin()[i]);
    for (size_t i = 0; i < extra.size(); i++)
        attrs[attrkinds.size() + i] = extra.begin()[i];
    return AttributeSet::get(C, ArrayRef<Attribute>(attrs));
}

static Type *get_pjlvalue(LLVMContext &C) { return JuliaType::get_pjlvalue_ty(C); }

static FunctionType *get_func_sig(LLVMContext &C) { return JuliaType::get_jlfunc_ty(C); }
static FunctionType *get_func2_sig(LLVMContext &C) { return JuliaType::get_jlfunc2_ty(C); }
static FunctionType *get_func3_sig(LLVMContext &C) { return JuliaType::get_jlfunc3_ty(C); }

static FunctionType *get_donotdelete_sig(LLVMContext &C) {
    return FunctionType::get(getVoidTy(C), true);
}

static AttributeList get_func_attrs(LLVMContext &C)
{
    return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            {AttributeSet(),
             Attributes(C, {Attribute::NoAlias, Attribute::ReadOnly, Attribute::NoCapture, Attribute::NoUndef})});
}

static AttributeList get_donotdelete_func_attrs(LLVMContext &C)
{
    AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
    FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly());
#else
    FnAttrs.addAttribute(Attribute::InaccessibleMemOnly);
#endif
    FnAttrs.addAttribute(Attribute::WillReturn);
    FnAttrs.addAttribute(Attribute::NoUnwind);
    return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            Attributes(C, {}),
            None);
}

static AttributeList get_attrs_noreturn(LLVMContext &C)
{
    return AttributeList::get(C,
                Attributes(C, {Attribute::NoReturn}),
                AttributeSet(),
                None);
}

static AttributeList get_attrs_basic(LLVMContext &C)
{
    return AttributeList::get(C,
                AttributeSet(),
                Attributes(C, {Attribute::NonNull}),
                None);
}

static AttributeList get_attrs_box_float(LLVMContext &C, unsigned nbytes)
{
    auto FnAttrs = AttrBuilder(C);
    FnAttrs.addAttribute(Attribute::WillReturn);
    FnAttrs.addAttribute(Attribute::NoUnwind);
#if LANGUAGE_LLVM_VERSION >= 160000
    FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly());
#else
    FnAttrs.addAttribute(Attribute::InaccessibleMemOnly);
#endif
    auto RetAttrs = AttrBuilder(C);
    RetAttrs.addAttribute(Attribute::NonNull);
    RetAttrs.addDereferenceableAttr(nbytes);
    RetAttrs.addAlignmentAttr(Align(alignof(void*)));
    return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet::get(C, RetAttrs),
                None);
}

static AttributeList get_attrs_box_sext(LLVMContext &C, unsigned nbytes)
{
    auto FnAttrs = AttrBuilder(C);
    FnAttrs.addAttribute(Attribute::WillReturn);
    FnAttrs.addAttribute(Attribute::NoUnwind);
#if LANGUAGE_LLVM_VERSION >= 160000
    FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly());
#else
    FnAttrs.addAttribute(Attribute::InaccessibleMemOnly);
#endif
    auto RetAttrs = AttrBuilder(C);
    RetAttrs.addAttribute(Attribute::NonNull);
    RetAttrs.addAttribute(Attribute::getWithDereferenceableBytes(C, nbytes));
    RetAttrs.addDereferenceableAttr(nbytes);
    RetAttrs.addAlignmentAttr(Align(alignof(void*)));
    return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet::get(C, RetAttrs),
                AttributeSet::get(C, {Attribute::get(C, Attribute::SExt)}));
}

static AttributeList get_attrs_box_zext(LLVMContext &C, unsigned nbytes)
{
    auto FnAttrs = AttrBuilder(C);
    FnAttrs.addAttribute(Attribute::WillReturn);
    FnAttrs.addAttribute(Attribute::NoUnwind);
#if LANGUAGE_LLVM_VERSION >= 160000
    FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly());
#else
    FnAttrs.addAttribute(Attribute::InaccessibleMemOnly);
#endif
    auto RetAttrs = AttrBuilder(C);
    RetAttrs.addAttribute(Attribute::NonNull);
    RetAttrs.addDereferenceableAttr(nbytes);
    RetAttrs.addAlignmentAttr(Align(alignof(void*)));
    return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet::get(C, RetAttrs),
                AttributeSet::get(C, {Attribute::get(C, Attribute::ZExt)}));
}


// global vars
static const auto jlRTLD_DEFAULT_var = new JuliaVariable{
    XSTR(language_RTLD_DEFAULT_handle),
    true,
    [](Type *T_size) -> Type * { return getInt8PtrTy(T_size->getContext()); },
};
static const auto jlexe_var = new JuliaVariable{
    XSTR(language_exe_handle),
    true,
    [](Type *T_size) -> Type * { return getInt8PtrTy(T_size->getContext()); },
};
static const auto jldll_var = new JuliaVariable{
    XSTR(language_liblanguage_handle),
    true,
    [](Type *T_size) -> Type * { return getInt8PtrTy(T_size->getContext()); },
};
static const auto jldlli_var = new JuliaVariable{
    XSTR(language_liblanguage_internal_handle),
    true,
    [](Type *T_size) -> Type * { return getInt8PtrTy(T_size->getContext()); },
};
static const auto language_small_typeof_var = new JuliaVariable{
    XSTR(language_small_typeof),
    true,
    [](Type *T_size) -> Type * { return getInt8Ty(T_size->getContext()); },
};

static const auto jlstack_chk_guard_var = new JuliaVariable{
    XSTR(__stack_chk_guard),
    true,
    [](Type *T_size) -> Type * { return get_pjlvalue(T_size->getContext()); },
};

static const auto jlgetworld_global = new JuliaVariable{
    XSTR(language_world_counter),
    false,
    [](Type *T_size) -> Type * { return T_size; },
};

static const auto jlboxed_int8_cache = new JuliaVariable{
    XSTR(language_boxed_int8_cache),
    true,
    [](Type *T_size) -> Type * { return ArrayType::get(get_pjlvalue(T_size->getContext()), 256); },
};

static const auto jlboxed_uint8_cache = new JuliaVariable{
    XSTR(language_boxed_uint8_cache),
    true,
    [](Type *T_size) -> Type * { return ArrayType::get(get_pjlvalue(T_size->getContext()), 256); },
};

static const auto jlpgcstack_func = new JuliaFunction<>{
    "julia.get_pgcstack",
    [](LLVMContext &C) { return FunctionType::get(PointerType::get(JuliaType::get_ppjlvalue_ty(C), 0), false); },
    nullptr,
};

static const auto jladoptthread_func = new JuliaFunction<>{
    "julia.get_pgcstack_or_new",
    jlpgcstack_func->_type,
    jlpgcstack_func->_attrs,
};


// important functions
// Symbols are not gc-tracked, but we'll treat them as callee rooted anyway,
// because they may come from a gc-rooted location
static const auto jlnew_func = new JuliaFunction<>{
    XSTR(language_new_structv),
    get_func_sig,
    get_func_attrs,
};
static const auto jlsplatnew_func = new JuliaFunction<>{
    XSTR(language_new_structt),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_prjlvalue, T_prjlvalue}, false);
    },
    get_attrs_basic,
};
static const auto jlthrow_func = new JuliaFunction<>{
    XSTR(language_throw),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    get_attrs_noreturn,
};
static const auto jlerror_func = new JuliaFunction<>{
    XSTR(language_error),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {getInt8PtrTy(C)}, false); },
    get_attrs_noreturn,
};
static const auto jlatomicerror_func = new JuliaFunction<>{
    XSTR(language_atomic_error),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {getInt8PtrTy(C)}, false); },
    get_attrs_noreturn,
};
static const auto jltypeerror_func = new JuliaFunction<>{
    XSTR(language_type_error),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {getInt8PtrTy(C), JuliaType::get_prjlvalue_ty(C), PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    get_attrs_noreturn,
};
static const auto jlundefvarerror_func = new JuliaFunction<>{
    XSTR(language_undefined_var_error),
    [](LLVMContext &C) {
        Type *T = PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted);
        return FunctionType::get(getVoidTy(C), {T, T}, false);
    },
    get_attrs_noreturn,
};
static const auto jlhasnofield_func = new JuliaFunction<>{
    XSTR(language_has_no_field_error),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted),
             PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    get_attrs_noreturn,
};
static const auto jlboundserrorv_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_bounds_error_ints),
    [](LLVMContext &C, Type *T_size) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted), T_size->getPointerTo(), T_size}, false); },
    get_attrs_noreturn,
};
static const auto jlboundserror_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_bounds_error_int),
    [](LLVMContext &C, Type *T_size) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted), T_size}, false); },
    get_attrs_noreturn,
};
static const auto jlvboundserror_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_bounds_error_tuple_int),
    [](LLVMContext &C, Type *T_size) { return FunctionType::get(getVoidTy(C),
            {JuliaType::get_pprjlvalue_ty(C), T_size, T_size}, false); },
    get_attrs_noreturn,
};
static const auto jluboundserror_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_bounds_error_unboxed_int),
    [](LLVMContext &C, Type *T_size) {
        return FunctionType::get(getVoidTy(C),
            {PointerType::get(getInt8Ty(C), AddressSpace::Derived), JuliaType::get_pjlvalue_ty(C), T_size}, false); },
    get_attrs_noreturn,
};
static const auto jlcheckassign_func = new JuliaFunction<>{
    XSTR(language_checked_assignment),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, T_pjlvalue, T_pjlvalue, PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    nullptr,
};
static const auto jlcheckreplace_func = new JuliaFunction<>{
    XSTR(language_checked_replace),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_pjlvalue, T_pjlvalue, T_pjlvalue, T_prjlvalue, T_prjlvalue}, false); },
    nullptr,
};
static const auto jlcheckmodify_func = new JuliaFunction<>{
    XSTR(language_checked_modify),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_pjlvalue, T_pjlvalue, T_pjlvalue, T_prjlvalue, T_prjlvalue}, false); },
    nullptr,
};
static const auto jlcheckswap_func = new JuliaFunction<>{
    XSTR(language_checked_swap),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_pjlvalue, T_pjlvalue, T_pjlvalue, PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    nullptr,
};
static const auto jlcheckassignonce_func = new JuliaFunction<>{
    XSTR(language_checked_assignonce),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_pjlvalue, T_pjlvalue, T_pjlvalue, PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    nullptr,
};
static const auto jldeclareconst_func = new JuliaFunction<>{
    XSTR(language_declare_constant),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, T_pjlvalue, T_pjlvalue}, false); },
    nullptr,
};
static const auto jlgetbindingorerror_func = new JuliaFunction<>{
    XSTR(language_get_binding_or_error),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(T_pjlvalue,
                {T_pjlvalue, T_pjlvalue}, false);
    },
    nullptr,
};
static const auto jlgetbindingwrorerror_func = new JuliaFunction<>{
    XSTR(language_get_binding_wr),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(T_pjlvalue,
                {T_pjlvalue, T_pjlvalue}, false);
    },
    nullptr,
};
static const auto jlboundp_func = new JuliaFunction<>{
    XSTR(language_boundp),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getInt32Ty(C),
                {T_pjlvalue, T_pjlvalue}, false);
    },
    nullptr,
};
static const auto jltopeval_func = new JuliaFunction<>{
    XSTR(language_toplevel_eval),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(T_pjlvalue,
                {T_pjlvalue, T_pjlvalue}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
static const auto jlcopyast_func = new JuliaFunction<>{
    XSTR(language_copy_ast),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
                {T_prjlvalue}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
static const auto jlapplygeneric_func = new JuliaFunction<>{
    XSTR(language_apply_generic),
    get_func_sig,
    get_func_attrs,
};
static const auto jlinvoke_func = new JuliaFunction<>{
    XSTR(language_invoke),
    get_func2_sig,
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            {AttributeSet(),
             Attributes(C, {Attribute::ReadOnly, Attribute::NoCapture})}); },
};
static const auto jlmethod_func = new JuliaFunction<>{
    XSTR(language_method_def),
    [](LLVMContext &C) {
        auto T_jlvalue = JuliaType::get_jlvalue_ty(C);
        auto T_pjlvalue = PointerType::get(T_jlvalue, 0);
        auto T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        return FunctionType::get(T_prjlvalue,
                {T_prjlvalue, T_prjlvalue, T_prjlvalue, T_pjlvalue}, false);
    },
    nullptr,
};
static const auto jlgenericfunction_func = new JuliaFunction<>{
    XSTR(language_generic_function_def),
    [](LLVMContext &C) {
        auto T_jlvalue = JuliaType::get_jlvalue_ty(C);
        auto T_pjlvalue = PointerType::get(T_jlvalue, 0);
        auto T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        auto T_pprjlvalue = PointerType::get(T_prjlvalue, 0);
        return FunctionType::get(T_prjlvalue, {T_pjlvalue, T_pjlvalue, T_pprjlvalue, T_pjlvalue}, false);
    },
    nullptr,
};
static const auto jllockvalue_func = new JuliaFunction<>{
    XSTR(language_lock_value),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            AttributeSet(),
            {Attributes(C, {Attribute::NoCapture})}); },
};
static const auto jlunlockvalue_func = new JuliaFunction<>{
    XSTR(language_unlock_value),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::CalleeRooted)}, false); },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            AttributeSet(),
            {Attributes(C, {Attribute::NoCapture})}); },
};
static const auto jllockfield_func = new JuliaFunction<>{
    XSTR(language_lock_field),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::Loaded)}, false); },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            AttributeSet(),
            {Attributes(C, {Attribute::NoCapture})}); },
};
static const auto jlunlockfield_func = new JuliaFunction<>{
    XSTR(language_unlock_field),
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::Loaded)}, false); },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            AttributeSet(),
            {Attributes(C, {Attribute::NoCapture})}); },
};
static const auto jlenter_func = new JuliaFunction<>{
    XSTR(language_enter_handler),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, getInt8PtrTy(C)}, false); },
    nullptr,
};
static const auto language_current_exception_func = new JuliaFunction<>{
    XSTR(language_current_exception),
    [](LLVMContext &C) { return FunctionType::get(JuliaType::get_prjlvalue_ty(C), {JuliaType::get_pjlvalue_ty(C)}, false); },
    nullptr,
};
static const auto jlleave_func = new JuliaFunction<>{
    XSTR(language_pop_handler),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, getInt32Ty(C)}, false); },
    [](LLVMContext &C) {
            auto FnAttrs = AttrBuilder(C);
            FnAttrs.addAttribute(Attribute::WillReturn);
            FnAttrs.addAttribute(Attribute::NoUnwind);
            auto RetAttrs = AttrBuilder(C);
            return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet(),
                None);
        },
};
static const auto jlleave_noexcept_func = new JuliaFunction<>{
    XSTR(language_pop_handler_noexcept),
    [](LLVMContext &C) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, getInt32Ty(C)}, false); },
    [](LLVMContext &C) {
            auto FnAttrs = AttrBuilder(C);
            FnAttrs.addAttribute(Attribute::WillReturn);
            FnAttrs.addAttribute(Attribute::NoUnwind);
            auto RetAttrs = AttrBuilder(C);
            return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet(),
                None);
        },
};
static const auto language_restore_excstack_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_restore_excstack),
    [](LLVMContext &C, Type *T_size) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_pjlvalue, T_size}, false); },
    nullptr,
};
static const auto language_excstack_state_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_excstack_state),
    [](LLVMContext &C, Type *T_size) {
        auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
        return FunctionType::get(T_size, {T_pjlvalue}, false); },
    nullptr,
};
static const auto jlegalx_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_egal__unboxed),
    [](LLVMContext &C, Type *T_size) {
        Type *T = PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::Derived);
        return FunctionType::get(getInt32Ty(C), {T, T, T_size}, false); },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleOrArgMemOnly());
#else
        FnAttrs.addAttribute(Attribute::ReadOnly);
        FnAttrs.addAttribute(Attribute::ArgMemOnly);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet(),
                None); },
};
static const auto language_alloc_obj_func = new JuliaFunction<TypeFnContextAndSizeT>{
    "julia.gc_alloc_obj",
    [](LLVMContext &C, Type *T_size) {
        auto T_jlvalue = JuliaType::get_jlvalue_ty(C);
        auto T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        auto T_pjlvalue = PointerType::get(T_jlvalue, 0);
        return FunctionType::get(T_prjlvalue,
                {T_pjlvalue, T_size, T_prjlvalue}, false);
    },
    [](LLVMContext &C) {
        auto FnAttrs = AttrBuilder(C);
        FnAttrs.addAllocSizeAttr(1, None); // returns %1 bytes
        FnAttrs.addAllocKindAttr(AllocFnKind::Alloc);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::argMemOnly(ModRefInfo::Ref) | MemoryEffects::inaccessibleMemOnly(ModRefInfo::ModRef));
#endif
        FnAttrs.addAttribute(Attribute::WillReturn);
        FnAttrs.addAttribute(Attribute::NoUnwind);
        auto RetAttrs = AttrBuilder(C);
        RetAttrs.addAttribute(Attribute::NoAlias);
        RetAttrs.addAttribute(Attribute::NonNull);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            AttributeSet::get(C, RetAttrs),
            None);
    },
};
static const auto language_newbits_func = new JuliaFunction<>{
    XSTR(language_new_bits),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
                {T_prjlvalue, getInt8PtrTy(C)}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
// `julia.typeof` does read memory, but it is effectively readnone before we lower
// the allocation function. This is OK as long as we lower `julia.typeof` no later than
// `julia.gc_alloc_obj`.
static const auto language_typeof_func = new JuliaFunction<>{
    "julia.typeof",
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
                {T_prjlvalue}, false);
    },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::none());
#else
        FnAttrs.addAttribute(Attribute::ReadNone);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        FnAttrs.addAttribute(Attribute::NoRecurse);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            Attributes(C, {Attribute::NonNull}),
            None); },
};

static const auto language_write_barrier_func = new JuliaFunction<>{
    "julia.write_barrier",
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C),
            {JuliaType::get_prjlvalue_ty(C)}, true); },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly());
#else
        FnAttrs.addAttribute(Attribute::InaccessibleMemOnly);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        FnAttrs.addAttribute(Attribute::NoRecurse);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            AttributeSet(),
            {Attributes(C, {Attribute::ReadOnly})});
    },
};

static const auto jlisa_func = new JuliaFunction<>{
    XSTR(language_isa),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(getInt32Ty(C),
            {T_prjlvalue, T_prjlvalue}, false);
    },
    nullptr,
};

static const auto jlsubtype_func = new JuliaFunction<>{
    XSTR(language_subtype),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(getInt32Ty(C),
            {T_prjlvalue, T_prjlvalue}, false);
    },
    nullptr,
};
static const auto jlapplytype_func = new JuliaFunction<>{
    XSTR(language_instantiate_type_in_env),
    [](LLVMContext &C) {
        auto T_jlvalue = JuliaType::get_jlvalue_ty(C);
        auto T_pjlvalue = PointerType::get(T_jlvalue, 0);
        auto T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        auto T_pprjlvalue = PointerType::get(T_prjlvalue, 0);
        return FunctionType::get(T_prjlvalue,
            {T_pjlvalue, T_pjlvalue, T_pprjlvalue}, false);
    },
    [](LLVMContext &C) {
        return AttributeList::get(C,
            AttributeSet(),
            AttributeSet::get(C, ArrayRef<Attribute>({Attribute::get(C, Attribute::NonNull),
                                               Attribute::getWithAlignment(C, Align(16))})),
            None);
    },
};
static const auto language_object_id__func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_object_id_),
    [](LLVMContext &C, Type *T_size) { return FunctionType::get(T_size,
            {T_size, PointerType::get(getInt8Ty(C), AddressSpace::Derived)}, false); },
    nullptr,
};
static const auto setjmp_func = new JuliaFunction<TypeFnContextAndTriple>{
    language_setjmp_name,
    [](LLVMContext &C, const Triple &T) {
        if (T.isOSWindows())
            return FunctionType::get(getInt32Ty(C),
                {getInt8PtrTy(C)}, false);
        return FunctionType::get(getInt32Ty(C),
            {getInt8PtrTy(C), getInt32Ty(C)}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            Attributes(C, {Attribute::ReturnsTwice}),
            AttributeSet(),
            None); },
};
static const auto memcmp_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(memcmp),
    [](LLVMContext &C, Type *T_size) { return FunctionType::get(getInt32Ty(C),
            {getInt8PtrTy(C), getInt8PtrTy(C), T_size}, false); },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::argMemOnly(ModRefInfo::Ref));
#else
        FnAttrs.addAttribute(Attribute::ArgMemOnly);
        FnAttrs.addAttribute(Attribute::ReadOnly);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            AttributeSet(),
            None); },
    // TODO: inferLibFuncAttributes(*memcmp_func, TLI);
};
static const auto jldlsym_func = new JuliaFunction<>{
    XSTR(language_load_and_lookup),
    [](LLVMContext &C) { return FunctionType::get(JuliaType::get_pvoidfunc_ty(C),
            {getInt8PtrTy(C), getInt8PtrTy(C), PointerType::get(getInt8PtrTy(C), 0)}, false); },
    nullptr,
};
static const auto jllazydlsym_func = new JuliaFunction<>{
    XSTR(language_lazy_load_and_lookup),
    [](LLVMContext &C) { return FunctionType::get(JuliaType::get_pvoidfunc_ty(C),
            {JuliaType::get_prjlvalue_ty(C), getInt8PtrTy(C)}, false); },
    nullptr,
};
static const auto jltypeassert_func = new JuliaFunction<>{
    XSTR(language_typeassert),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(getVoidTy(C),
            {T_prjlvalue, T_prjlvalue}, false);
    },
    nullptr,
};
static const auto jlgetnthfieldchecked_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_get_nth_field_checked),
    [](LLVMContext &C, Type *T_size) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_prjlvalue, T_size}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
static const auto jlfieldindex_func = new JuliaFunction<>{
    XSTR(language_field_index),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(getInt32Ty(C),
            {T_prjlvalue, T_prjlvalue, getInt32Ty(C)}, false);
    },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::readOnly());
#else
        FnAttrs.addAttribute(Attribute::ReadOnly);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        FnAttrs.addAttribute(Attribute::WillReturn);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            AttributeSet(),
            None); }, // This function can error if the third argument is 1 so don't do that.
};
static const auto jlfieldisdefinedchecked_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_field_isdefined_checked),
    [](LLVMContext &C, Type *T_size) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(getInt32Ty(C),
            {T_prjlvalue, T_size}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {}),
            None); },
};
static const auto jlgetcfunctiontrampoline_func = new JuliaFunction<>{
    XSTR(language_get_cfunction_trampoline),
    [](LLVMContext &C) {
        auto T_jlvalue = JuliaType::get_jlvalue_ty(C);
        auto T_pjlvalue = PointerType::get(T_jlvalue, 0);
        auto T_prjlvalue = PointerType::get(T_jlvalue, AddressSpace::Tracked);
        auto T_ppjlvalue = PointerType::get(T_pjlvalue, 0);
        auto T_pprjlvalue = PointerType::get(T_prjlvalue, 0);
        return FunctionType::get(T_prjlvalue,
            {
                T_prjlvalue, // f (object)
                T_pjlvalue, // result
                getInt8PtrTy(C), // cache
                T_pjlvalue, // fill
                FunctionType::get(getInt8PtrTy(C), { getInt8PtrTy(C), T_ppjlvalue }, false)->getPointerTo(), // trampoline
                T_pjlvalue, // env
                T_pprjlvalue, // vals
            }, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            AttributeSet(),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
static const auto diff_gc_total_bytes_func = new JuliaFunction<>{
    XSTR(language_gc_diff_total_bytes),
    [](LLVMContext &C) { return FunctionType::get(getInt64Ty(C), false); },
    nullptr,
};
static const auto sync_gc_total_bytes_func = new JuliaFunction<>{
    XSTR(language_gc_sync_total_bytes),
    [](LLVMContext &C) { return FunctionType::get(getInt64Ty(C),
            {getInt64Ty(C)}, false); },
    nullptr,
};
static const auto language_allocgenericmemory = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_alloc_genericmemory),
    [](LLVMContext &C, Type *T_Size) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue, // new Memory
                                {T_prjlvalue, // type
                                T_Size        // nelements
                                }, false); },
        [](LLVMContext &C) {
            AttrBuilder FnAttrs(C);
            AttrBuilder RetAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
            FnAttrs.addMemoryAttr(MemoryEffects::inaccessibleMemOnly(ModRefInfo::ModRef) | MemoryEffects::argMemOnly(ModRefInfo::Ref));
#endif
            FnAttrs.addAttribute(Attribute::WillReturn);
            RetAttrs.addAlignmentAttr(Align(16));
            RetAttrs.addAttribute(Attribute::NonNull);
            RetAttrs.addDereferenceableAttr(16);
            return AttributeList::get(C,
                AttributeSet::get(C, FnAttrs),
                AttributeSet::get(C, RetAttrs),
                None); },
};
static const auto jlarray_data_owner_func = new JuliaFunction<>{
    XSTR(language_array_data_owner),
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_prjlvalue}, false);
    },
    [](LLVMContext &C) { return AttributeList::get(C,
            Attributes(C, {Attribute::ReadOnly, Attribute::NoUnwind}),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
#define BOX_FUNC(ct,at,attrs,nbytes)                                                    \
static const auto box_##ct##_func = new JuliaFunction<>{                           \
    XSTR(language_box_##ct),                                                           \
    [](LLVMContext &C) { return FunctionType::get(JuliaType::get_prjlvalue_ty(C),\
            {at}, false); },                                                     \
    [](LLVMContext &C) { return attrs(C,nbytes); },                                                                \
}
BOX_FUNC(int16, getInt16Ty(C), get_attrs_box_sext, 2);
BOX_FUNC(uint16, getInt16Ty(C), get_attrs_box_zext, 2);
BOX_FUNC(int32, getInt32Ty(C), get_attrs_box_sext, 4);
BOX_FUNC(uint32, getInt32Ty(C), get_attrs_box_zext, 4);
BOX_FUNC(int64, getInt64Ty(C), get_attrs_box_sext, 8);
BOX_FUNC(uint64, getInt64Ty(C), get_attrs_box_zext, 8);
BOX_FUNC(char, getCharTy(C), get_attrs_box_zext, 1);
BOX_FUNC(float32, getFloatTy(C), get_attrs_box_float, 4);
BOX_FUNC(float64, getDoubleTy(C), get_attrs_box_float, 8);
#undef BOX_FUNC

static const auto box_ssavalue_func = new JuliaFunction<TypeFnContextAndSizeT>{
    XSTR(language_box_ssavalue),
    [](LLVMContext &C, Type *T_size) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {T_size}, false);
    },
    get_attrs_basic,
};
static const auto jlgetbuiltinfptr_func = new JuliaFunction<>{
    XSTR(language_get_builtin_fptr),
    [](LLVMContext &C) { return FunctionType::get(get_func_sig(C)->getPointerTo(),
            {JuliaType::get_prjlvalue_ty(C)}, false); },
    nullptr,
};


// placeholder functions
static const auto gcroot_flush_func = new JuliaFunction<>{
    "julia.gcroot_flush",
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C), false); },
    nullptr,
};
static const auto gc_preserve_begin_func = new JuliaFunction<>{
    "llvm.julia.gc_preserve_begin",
    [](LLVMContext &C) { return FunctionType::get(Type::getTokenTy(C), true); },
    nullptr,
};
static const auto gc_preserve_end_func = new JuliaFunction<> {
    "llvm.julia.gc_preserve_end",
    [](LLVMContext &C) { return FunctionType::get(getVoidTy(C), {Type::getTokenTy(C)}, false); },
    nullptr,
};
static const auto except_enter_func = new JuliaFunction<>{
    "julia.except_enter",
    [](LLVMContext &C) {
         auto T_pjlvalue = JuliaType::get_pjlvalue_ty(C);
         return FunctionType::get(getInt32Ty(C), {T_pjlvalue}, false); },
    [](LLVMContext &C) { return AttributeList::get(C,
            Attributes(C, {Attribute::ReturnsTwice}),
            AttributeSet(),
            None); },
};
static const auto pointer_from_objref_func = new JuliaFunction<>{
    "julia.pointer_from_objref",
    [](LLVMContext &C) { return FunctionType::get(JuliaType::get_pjlvalue_ty(C),
            {PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::Derived)}, false); },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::none());
#else
        FnAttrs.addAttribute(Attribute::ReadNone);
#endif
        FnAttrs.addAttribute(Attribute::NoUnwind);
        return AttributeList::get(C,
            AttributeSet::get(C, FnAttrs),
            Attributes(C, {Attribute::NonNull}),
            None); },
};
static const auto gc_loaded_func = new JuliaFunction<>{
    "julia.gc_loaded",
    // # memory(none) nosync nounwind speculatable willreturn norecurse
    // declare nonnull noundef ptr(Loaded) @"julia.gc_loaded"(ptr(Tracked) nocapture nonnull noundef readnone, ptr nonnull noundef readnone)
    //  top:
    //   %metadata GC base pointer is ptr(Tracked)
    //   ret addrspacecast ptr to ptr(Loaded)
    [](LLVMContext &C) { return FunctionType::get(PointerType::get(JuliaType::get_prjlvalue_ty(C), AddressSpace::Loaded),
            {JuliaType::get_prjlvalue_ty(C), PointerType::get(JuliaType::get_prjlvalue_ty(C), 0)}, false); },
    [](LLVMContext &C) {
        AttrBuilder FnAttrs(C);
        FnAttrs.addAttribute(Attribute::NoSync);
        FnAttrs.addAttribute(Attribute::NoUnwind);
        FnAttrs.addAttribute(Attribute::Speculatable);
        FnAttrs.addAttribute(Attribute::WillReturn);
        FnAttrs.addAttribute(Attribute::NoRecurse);
#if LANGUAGE_LLVM_VERSION >= 160000
        FnAttrs.addMemoryAttr(MemoryEffects::none());
#else
        FnAttrs.addAttribute(Attribute::ReadNone);
#endif
        AttrBuilder RetAttrs(C);
        RetAttrs.addAttribute(Attribute::NonNull);
        RetAttrs.addAttribute(Attribute::NoUndef);
        return AttributeList::get(C, AttributeSet::get(C,FnAttrs), AttributeSet::get(C,RetAttrs),
                { Attributes(C, {Attribute::NonNull, Attribute::NoUndef, Attribute::ReadNone, Attribute::NoCapture}),
                  Attributes(C, {Attribute::NonNull, Attribute::NoUndef, Attribute::ReadNone}) });
                  },
};

// julia.call represents a call with julia calling convention, it is used as
//
//   ptr julia.call(ptr %fptr, ptr %f, ptr %arg1, ptr %arg2, ...)
//
// In late lowering the call will then be rewritten as
//
//   ptr %fptr(ptr %f, ptr args, i64 nargs)
//
// with all the spelled out args appropriately moved into the argument stack buffer.
// By representing it this way rather than allocating the stack buffer earlier, we
// allow LLVM to make more aggressive optimizations on the call arguments.
static const auto language_call = new JuliaFunction<>{
    "julia.call",
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {get_func_sig(C)->getPointerTo(),
             T_prjlvalue}, // %f
            true); }, // %args
    get_attrs_basic,
};

// julia.call2 is like julia.call, except that %arg1 gets passed as a register
// argument at the end of the argument list.
static const auto language_call2 = new JuliaFunction<>{
    "julia.call2",
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        return FunctionType::get(T_prjlvalue,
            {get_func2_sig(C)->getPointerTo(),
             T_prjlvalue, // %arg1
             T_prjlvalue}, // %f
            true); }, // %args
    get_attrs_basic,
};

// julia.call3 is like julia.call, except that %fptr is derived rather than tracked
static const auto language_call3 = new JuliaFunction<>{
    "julia.call3",
    [](LLVMContext &C) {
        auto T_prjlvalue = JuliaType::get_prjlvalue_ty(C);
        Type *T = PointerType::get(JuliaType::get_jlvalue_ty(C), AddressSpace::Derived);
        return FunctionType::get(T_prjlvalue,
            {get_func3_sig(C)->getPointerTo(),
             T}, // %f
            true); }, // %args
    get_attrs_basic,
};


static const auto jltuple_func = new JuliaFunction<>{XSTR(language_f_tuple), get_func_sig, get_func_attrs};
static const auto jlintrinsic_func = new JuliaFunction<>{XSTR(language_f_intrinsic_call), get_func3_sig, get_func_attrs};

static const auto &builtin_func_map() {
    static std::map<language_fptr_args_t, JuliaFunction<>*> builtins = {
          { language_f_is_addr,                 new JuliaFunction<>{XSTR(language_f_is), get_func_sig, get_func_attrs} },
          { language_f_typeof_addr,             new JuliaFunction<>{XSTR(language_f_typeof), get_func_sig, get_func_attrs} },
          { language_f_sizeof_addr,             new JuliaFunction<>{XSTR(language_f_sizeof), get_func_sig, get_func_attrs} },
          { language_f_issubtype_addr,          new JuliaFunction<>{XSTR(language_f_issubtype), get_func_sig, get_func_attrs} },
          { language_f_isa_addr,                new JuliaFunction<>{XSTR(language_f_isa), get_func_sig, get_func_attrs} },
          { language_f_typeassert_addr,         new JuliaFunction<>{XSTR(language_f_typeassert), get_func_sig, get_func_attrs} },
          { language_f_ifelse_addr,             new JuliaFunction<>{XSTR(language_f_ifelse), get_func_sig, get_func_attrs} },
          { language_f__apply_iterate_addr,     new JuliaFunction<>{XSTR(language_f__apply_iterate), get_func_sig, get_func_attrs} },
          { language_f__apply_pure_addr,        new JuliaFunction<>{XSTR(language_f__apply_pure), get_func_sig, get_func_attrs} },
          { language_f__call_latest_addr,       new JuliaFunction<>{XSTR(language_f__call_latest), get_func_sig, get_func_attrs} },
          { language_f__call_in_world_addr,     new JuliaFunction<>{XSTR(language_f__call_in_world), get_func_sig, get_func_attrs} },
          { language_f__call_in_world_total_addr, new JuliaFunction<>{XSTR(language_f__call_in_world_total), get_func_sig, get_func_attrs} },
          { language_f_throw_addr,              new JuliaFunction<>{XSTR(language_f_throw), get_func_sig, get_func_attrs} },
          { language_f_tuple_addr,              jltuple_func },
          { language_f_svec_addr,               new JuliaFunction<>{XSTR(language_f_svec), get_func_sig, get_func_attrs} },
          { language_f_applicable_addr,         new JuliaFunction<>{XSTR(language_f_applicable), get_func_sig, get_func_attrs} },
          { language_f_invoke_addr,             new JuliaFunction<>{XSTR(language_f_invoke), get_func_sig, get_func_attrs} },
          { language_f_isdefined_addr,          new JuliaFunction<>{XSTR(language_f_isdefined), get_func_sig, get_func_attrs} },
          { language_f_getfield_addr,           new JuliaFunction<>{XSTR(language_f_getfield), get_func_sig, get_func_attrs} },
          { language_f_setfield_addr,           new JuliaFunction<>{XSTR(language_f_setfield), get_func_sig, get_func_attrs} },
          { language_f_swapfield_addr,          new JuliaFunction<>{XSTR(language_f_swapfield), get_func_sig, get_func_attrs} },
          { language_f_modifyfield_addr,        new JuliaFunction<>{XSTR(language_f_modifyfield), get_func_sig, get_func_attrs} },
          { language_f_fieldtype_addr,          new JuliaFunction<>{XSTR(language_f_fieldtype), get_func_sig, get_func_attrs} },
          { language_f_nfields_addr,            new JuliaFunction<>{XSTR(language_f_nfields), get_func_sig, get_func_attrs} },
          { language_f__expr_addr,              new JuliaFunction<>{XSTR(language_f__expr), get_func_sig, get_func_attrs} },
          { language_f__typevar_addr,           new JuliaFunction<>{XSTR(language_f__typevar), get_func_sig, get_func_attrs} },
          { language_f_memoryref_addr,          new JuliaFunction<>{XSTR(language_f_memoryref), get_func_sig, get_func_attrs} },
          { language_f_memoryrefoffset_addr,    new JuliaFunction<>{XSTR(language_f_memoryrefoffset), get_func_sig, get_func_attrs} },
          { language_f_memoryrefset_addr,       new JuliaFunction<>{XSTR(language_f_memoryrefset), get_func_sig, get_func_attrs} },
          { language_f_memoryrefswap_addr,      new JuliaFunction<>{XSTR(language_f_memoryrefswap), get_func_sig, get_func_attrs} },
          { language_f_memoryrefreplace_addr,   new JuliaFunction<>{XSTR(language_f_memoryrefreplace), get_func_sig, get_func_attrs} },
          { language_f_memoryrefmodify_addr,    new JuliaFunction<>{XSTR(language_f_memoryrefmodify), get_func_sig, get_func_attrs} },
          { language_f_memoryrefsetonce_addr,   new JuliaFunction<>{XSTR(language_f_memoryrefsetonce), get_func_sig, get_func_attrs} },
          { language_f_memoryref_isassigned_addr,new JuliaFunction<>{XSTR(language_f_memoryref_isassigned), get_func_sig, get_func_attrs} },
          { language_f_apply_type_addr,         new JuliaFunction<>{XSTR(language_f_apply_type), get_func_sig, get_func_attrs} },
          { language_f_donotdelete_addr,        new JuliaFunction<>{XSTR(language_f_donotdelete), get_donotdelete_sig, get_donotdelete_func_attrs} },
          { language_f_compilerbarrier_addr,    new JuliaFunction<>{XSTR(language_f_compilerbarrier), get_func_sig, get_func_attrs} },
          { language_f_finalizer_addr,          new JuliaFunction<>{XSTR(language_f_finalizer), get_func_sig, get_func_attrs} },
          { language_f__svec_ref_addr,          new JuliaFunction<>{XSTR(language_f__svec_ref), get_func_sig, get_func_attrs} }
        };
    return builtins;
}

static const auto language_new_opaque_closure_jlcall_func = new JuliaFunction<>{XSTR(language_new_opaque_closure_jlcall), get_func_sig, get_func_attrs};

static _Atomic(uint64_t) globalUniqueGeneratedNames{1};

// --- code generation ---

extern "C" {
    language_cgparams_t language_default_cgparams = {
        /* track_allocations */ 1,
        /* code_coverage */ 1,
        /* prefer_specsig */ 0,
#ifdef _OS_WINDOWS_
        /* gnu_pubnames */ 0,
#else
        /* gnu_pubnames */ 1,
#endif
        /* debug_info_kind */ (int) DICompileUnit::DebugEmissionKind::FullDebug,
        /* debug_line_info */ 1,
        /* safepoint_on_entry */ 1,
        /* gcstack_arg */ 1,
        /* use_jlplt*/ 1,
        /* lookup */ language_rettype_inferred_addr };
}


static MDNode *best_tbaa(language_tbaacache_t &tbaa_cache, language_value_t *jt) {
    jt = language_unwrap_unionall(jt);
    if (jt == (language_value_t*)language_datatype_type ||
        (language_is_type_type(jt) && language_is_datatype(language_tparam0(jt))))
        return tbaa_cache.tbaa_datatype;
    if (!language_is_datatype(jt))
        return tbaa_cache.tbaa_value;
    if (language_is_abstracttype(jt))
        return tbaa_cache.tbaa_value;
    if (language_is_genericmemory_type(jt) || language_is_array_type(jt))
        return tbaa_cache.tbaa_array;
    // If we're here, we know all subtypes are (im)mutable, even if we
    // don't know what the exact type is
    return language_is_mutable(jt) ? tbaa_cache.tbaa_mutab : tbaa_cache.tbaa_immut;
}

// tracks whether codegen is currently able to simply stack-allocate this type
// note that this includes language_isbits, although codegen should work regardless
static bool language_is_concrete_immutable(language_value_t* t)
{
    return language_is_immutable_datatype(t) && ((language_datatype_t*)t)->isconcretetype;
}

static bool language_is_pointerfree(language_value_t* t)
{
    if (!language_is_concrete_immutable(t))
        return 0;
    const language_datatype_layout_t *layout = ((language_datatype_t*)t)->layout;
    return layout && layout->npointers == 0;
}

// these queries are usually related, but we split them out here
// for convenience and clarity (and because it changes the calling convention)
// n.b. this must include language_is_datatype_singleton (ghostType) and primitive types
static bool deserves_stack(language_value_t* t)
{
    if (!language_is_concrete_immutable(t))
        return false;
    language_datatype_t *dt = (language_datatype_t*)t;
    return language_is_datatype_singleton(dt) || language_datatype_isinlinealloc(dt, 0);
}
static bool deserves_argbox(language_value_t* t)
{
    return !deserves_stack(t);
}
static bool deserves_retbox(language_value_t* t)
{
    return deserves_argbox(t);
}
static bool deserves_sret(language_value_t *dt, Type *T)
{
    assert(language_is_datatype(dt));
    return (size_t)language_datatype_size(dt) > sizeof(void*) && !T->isFloatingPointTy() && !T->isVectorTy();
}

// Alias Analysis Info (analogous to llvm::AAMDNodes)
struct language_aliasinfo_t {
    MDNode *tbaa = nullptr;          // '!tbaa': Struct-path TBAA. TBAA graph forms a tree (indexed by offset).
                                     //          Two pointers do not alias if they are not transitive parents
                                     //          (effectively, subfields) of each other or equal.
    MDNode *tbaa_struct = nullptr;   // '!tbaa.struct': Describes memory layout of struct.
    MDNode *scope = nullptr;         // '!alias.scope': Generic "noalias" memory access sets.
                                     //                 If alias.scope(inst_a) ⊆ noalias(inst_b) (in any "domain")
                                     //                    => inst_a, inst_b do not alias.
    MDNode *noalias = nullptr;       // '!noalias': See '!alias.scope' above.

    enum class Region { unknown, gcframe, stack, data, constant, type_metadata }; // See language_regions_t

    explicit language_aliasinfo_t() = default;
    explicit language_aliasinfo_t(language_codectx_t &ctx, Region r, MDNode *tbaa);
    explicit language_aliasinfo_t(MDNode *tbaa, MDNode *tbaa_struct, MDNode *scope, MDNode *noalias)
        : tbaa(tbaa), tbaa_struct(tbaa_struct), scope(scope), noalias(noalias) {}
    language_aliasinfo_t(const language_aliasinfo_t &) = default;

    // Add !tbaa, !tbaa.struct, !alias.scope, !noalias annotations to an instruction.
    //
    // Also adds `invariant.load` to load instructions in the constant !noalias scope.
    Instruction *decorateInst(Instruction *inst) const {

        if (this->tbaa)
            inst->setMetadata(LLVMContext::MD_tbaa, this->tbaa);
        if (this->tbaa_struct)
            inst->setMetadata(LLVMContext::MD_tbaa_struct, this->tbaa_struct);
        if (this->scope)
            inst->setMetadata(LLVMContext::MD_alias_scope, this->scope);
        if (this->noalias)
            inst->setMetadata(LLVMContext::MD_noalias, this->noalias);

        if (this->scope && isa<LoadInst>(inst)) {
            // If this is in the read-only region, mark the load with "!invariant.load"
            if (this->scope->getNumOperands() == 1) {
                MDNode *operand = cast<MDNode>(this->scope->getOperand(0));
                auto scope_name = cast<MDString>(operand->getOperand(0))->getString();
                if (scope_name == "jnoalias_const")
                    inst->setMetadata(LLVMContext::MD_invariant_load, MDNode::get(inst->getContext(), None));
            }
        }

        return inst;
    }

    // Merge two sets of alias information.
    language_aliasinfo_t merge(const language_aliasinfo_t &other) const {
        language_aliasinfo_t result;
        result.tbaa = MDNode::getMostGenericTBAA(this->tbaa, other.tbaa);
        result.tbaa_struct = nullptr;
        result.scope = MDNode::getMostGenericAliasScope(this->scope, other.scope);
        result.noalias = MDNode::intersect(this->noalias, other.noalias);
        return result;
    }

    // Create alias information based on the provided TBAA metadata.
    //
    // This function only exists to help transition to using !noalias to encode
    // memory region non-aliasing. It should be deleted once the TBAA metadata
    // is improved to encode only memory layout and *not* memory regions.
    static language_aliasinfo_t fromTBAA(language_codectx_t &ctx, MDNode *tbaa);
};

// metadata tracking for a llvm Value* during codegen
const uint8_t UNION_BOX_MARKER = 0x80;
struct language_cgval_t {
    Value *V; // may be of type T* or T, or set to NULL if ghost (or if the value has not been initialized yet, for a variable definition)
    // For unions, we may need to keep a reference to the boxed part individually.
    // If this is non-NULL, then, at runtime, we satisfy the invariant that (for the corresponding
    // runtime values) if `(TIndex | UNION_BOX_MARKER) != 0`, then `Vboxed == V` (by value).
    // For convenience, we also set this value of isboxed values, in which case
    // it is equal (at compile time) to V.

    // If this is non-NULL (at compile time), it is always of type `T_prjlvalue`.
    // N.B.: In general we expect this to always be a dereferenceable pointer at runtime.
    //       However, there are situations where this value may be a runtime NULL
    //       (PhiNodes with undef predecessors or PhiC with undef UpsilonNode).
    //       The middle-end arranges appropriate error checks before any use
    //       of this value that may read a non-dereferenceable Vboxed, with two
    //       exceptions: PhiNode and UpsilonNode arguments which need special
    //       handling to account for the possibility that this may be NULL.
    Value *Vboxed;

    Value *TIndex; // if `V` is an unboxed (tagged) Union described by `typ`, this gives the DataType index (1-based, small int) as an i8
    language_value_t *constant; // constant value (rooted in linfo.def.roots)
    language_value_t *typ; // the original type of V, never NULL
    bool isboxed; // whether this value is a language_value_t* allocated on the heap with the right type tag
    bool isghost; // whether this value is "ghost"
    MDNode *tbaa; // The related tbaa node. Non-NULL iff this holds an address.
    // If non-null, this memory location may be promoted on use, by hoisting the
    // destination memory above the promotion point.
    Instruction *promotion_point;
    // If promotion_ssa is non-null, the julia src ssa value that corresponds
    // to the promotion point. This is used for dominator analysis, since LLVM's
    // dominator analysis has algorithmic problems for large basic blocks.
    ssize_t promotion_ssa;
    bool ispointer() const
    {
        // whether this value is compatible with `data_pointer`
        return tbaa != nullptr;
    }
    language_cgval_t(Value *Vval, language_value_t *typ, Value *tindex) : // general value constructor
        V(Vval), // V is allowed to be NULL in a language_varinfo_t context, but not during codegen contexts
        Vboxed(nullptr),
        TIndex(tindex),
        constant(NULL),
        typ(typ),
        isboxed(false),
        isghost(false),
        tbaa(nullptr),
        promotion_point(nullptr),
        promotion_ssa(-1)
    {
        assert(TIndex == NULL || TIndex->getType() == getInt8Ty(TIndex->getContext()));
    }
    language_cgval_t(Value *Vptr, bool isboxed, language_value_t *typ, Value *tindex, MDNode *tbaa) : // general pointer constructor
        V(Vptr),
        Vboxed(isboxed ? Vptr : nullptr),
        TIndex(tindex),
        constant(NULL),
        typ(typ),
        isboxed(isboxed),
        isghost(false),
        tbaa(tbaa),
        promotion_point(nullptr),
        promotion_ssa(-1)
    {
        if (Vboxed)
            assert(Vboxed->getType() == JuliaType::get_prjlvalue_ty(Vboxed->getContext()));
        assert(tbaa != NULL);
        assert(!(isboxed && TIndex != NULL));
        assert(TIndex == NULL || TIndex->getType() == getInt8Ty(TIndex->getContext()));
    }
    explicit language_cgval_t(language_value_t *typ) : // ghost value constructor
        // mark explicit to avoid being used implicitly for conversion from NULL (use language_cgval_t() instead)
        V(NULL),
        Vboxed(NULL),
        TIndex(NULL),
        constant(((language_datatype_t*)typ)->instance),
        typ(typ),
        isboxed(false),
        isghost(true),
        tbaa(nullptr),
        promotion_point(nullptr),
        promotion_ssa(-1)
    {
        assert(language_is_datatype(typ));
        assert(constant);
    }
    language_cgval_t(const language_cgval_t &v, language_value_t *typ, Value *tindex) : // copy constructor with new type
        V(v.V),
        Vboxed(v.Vboxed),
        TIndex(tindex),
        constant(v.constant),
        typ(typ),
        isboxed(v.isboxed),
        isghost(v.isghost),
        tbaa(v.tbaa),
        promotion_point(v.promotion_point),
        promotion_ssa(v.promotion_ssa)
    {
        if (Vboxed)
            assert(Vboxed->getType() == JuliaType::get_prjlvalue_ty(Vboxed->getContext()));
        // this constructor expects we had a badly or equivalently typed version
        // make sure we aren't discarding the actual type information
        if (v.TIndex) {
            assert((TIndex == NULL) == language_is_concrete_type(typ));
        }
        else {
            assert(isboxed || v.typ == typ || tindex);
        }
    }
    explicit language_cgval_t() : // undef / unreachable constructor
        V(NULL),
        Vboxed(NULL),
        TIndex(NULL),
        constant(NULL),
        typ(language_bottom_type),
        isboxed(false),
        isghost(true),
        tbaa(nullptr),
        promotion_point(nullptr),
        promotion_ssa(-1)
    {
    }
};

// per-local-variable information
struct language_varinfo_t {
    Instruction *boxroot; // an address, if the var might be in a language_value_t** stack slot (marked ctx.tbaa().tbaa_const, if appropriate)
    language_cgval_t value; // a stack slot or constant value
    Value *pTIndex; // i8* stack slot for the value.TIndex tag describing `value.V`
    DILocalVariable *dinfo;
    // if the variable might be used undefined and is not boxed
    // this i1 flag is true when it is defined
    Value *defFlag;
    bool isSA; // whether all stores dominate all uses
    bool isVolatile;
    bool isArgument;
    bool usedUndef;
    bool used;

    language_varinfo_t(LLVMContext &ctxt) : boxroot(NULL),
                     value(language_cgval_t()),
                     pTIndex(NULL),
                     dinfo(NULL),
                     defFlag(NULL),
                     isSA(false),
                     isVolatile(false),
                     isArgument(false),
                     usedUndef(false),
                     used(false)
    {
    }
};

// information about the context of a piece of code: its enclosing
// function and module, and visible local variables and labels.
class language_codectx_t {
public:
    IRBuilder<> builder;
    language_codegen_params_t &emission_context;
    llvm::MapVector<language_code_instance_t*, language_codegen_call_target_t> call_targets;
    Function *f = NULL;
    MDNode* LoopID = NULL;
    // local var info. globals are not in here.
    SmallVector<language_varinfo_t, 0> slots;
    std::map<int, language_varinfo_t> phic_slots;
    std::map<int, std::pair<Value*, Value*> > scope_restore;
    SmallVector<language_cgval_t, 0> SAvalues;
    SmallVector<std::tuple<language_cgval_t, BasicBlock *, AllocaInst *, PHINode *, language_value_t *>, 0> PhiNodes;
    SmallVector<bool, 0> ssavalue_assigned;
    SmallVector<int, 0> ssavalue_usecount;
    language_module_t *module = NULL;
    language_typecache_t type_cache;
    language_tbaacache_t tbaa_cache;
    language_noaliascache_t aliasscope_cache;
    language_method_instance_t *linfo = NULL;
    language_value_t *rettype = NULL;
    language_code_info_t *source = NULL;
    language_array_t *code = NULL;
    size_t min_world = 0;
    size_t max_world = -1;
    const char *name = NULL;
    StringRef file{};
    ssize_t *line = NULL;
    Value *spvals_ptr = NULL;
    Value *argArray = NULL;
    Value *argCount = NULL;
    std::string funcName;
    int vaSlot = -1;        // name of vararg argument
    int nReqArgs = 0;
    int nargs = 0;
    int nvargs = -1;
    bool is_opaque_closure = false;

    Value *pgcstack = NULL;
    Instruction *topalloca = NULL;

    bool use_cache = false;
    bool external_linkage = false;
    const language_cgparams_t *params = NULL;

    SmallVector<std::unique_ptr<Module>, 0> llvmcall_modules;

    language_codectx_t(LLVMContext &llvmctx, language_codegen_params_t &params, size_t min_world, size_t max_world)
      : builder(llvmctx),
        emission_context(params),
        call_targets(),
        min_world(min_world),
        max_world(max_world),
        use_cache(params.cache),
        external_linkage(params.external_linkage),
        params(params.params) {
    }

    language_codectx_t(LLVMContext &llvmctx, language_codegen_params_t &params, language_code_instance_t *ci) :
        language_codectx_t(llvmctx, params, language_atomic_load_relaxed(&ci->min_world), language_atomic_load_relaxed(&ci->max_world)) {}

    language_typecache_t &types() {
        type_cache.initialize(builder.getContext(), emission_context.DL);
        return type_cache;
    }

    language_tbaacache_t &tbaa() {
        tbaa_cache.initialize(builder.getContext());
        return tbaa_cache;
    }

    language_noaliascache_t &noalias() {
        aliasscope_cache.initialize(builder.getContext());
        return aliasscope_cache;
    }

    ~language_codectx_t() {
        // Transfer local delayed calls to the global queue
        for (auto call_target : call_targets)
            emission_context.workqueue.push_back(call_target);
    }
};

GlobalVariable *JuliaVariable::realize(language_codectx_t &ctx) {
    return realize(language_Module);
}

language_aliasinfo_t::language_aliasinfo_t(language_codectx_t &ctx, Region r, MDNode *tbaa): tbaa(tbaa), tbaa_struct(nullptr) {
    MDNode *alias_scope = nullptr;
    language_noaliascache_t::language_regions_t regions = ctx.noalias().regions;
    switch (r) {
        case Region::unknown:
            alias_scope = nullptr;
            break;
        case Region::gcframe:
            alias_scope = regions.gcframe;
            break;
        case Region::stack:
            alias_scope = regions.stack;
            break;
        case Region::data:
            alias_scope = regions.data;
            break;
        case Region::constant:
            alias_scope = regions.constant;
            break;
        case Region::type_metadata:
            alias_scope = regions.type_metadata;
            break;
    }

    MDNode *all_scopes[5] = { regions.gcframe, regions.stack, regions.data, regions.type_metadata, regions.constant };
    if (alias_scope) {
        // The matching region is added to !alias.scope
        // All other regions are added to !noalias

        int i = 0;
        Metadata *scopes[1] = { alias_scope };
        Metadata *noaliases[4];
        for (auto const &scope: all_scopes) {
            if (scope == alias_scope) continue;
            noaliases[i++] = scope;
        }

        this->scope = MDNode::get(ctx.builder.getContext(), ArrayRef<Metadata*>(scopes));
        this->noalias = MDNode::get(ctx.builder.getContext(), ArrayRef<Metadata*>(noaliases));
    }
}

language_aliasinfo_t language_aliasinfo_t::fromTBAA(language_codectx_t &ctx, MDNode *tbaa) {
    auto cache = ctx.tbaa();

    // Each top-level TBAA node has a corresponding !alias.scope scope
    MDNode *tbaa_srcs[5] = { cache.tbaa_gcframe, cache.tbaa_stack, cache.tbaa_data, cache.tbaa_array, cache.tbaa_const };
    Region regions[5] = { Region::gcframe, Region::stack, Region::data, Region::type_metadata, Region::constant };

    if (tbaa != nullptr) {
        MDNode *node = cast<MDNode>(tbaa->getOperand(1));
        if (cast<MDString>(node->getOperand(0))->getString() != "jtbaa") {

            // Climb up to node just before root
            MDNode *parent_node = cast<MDNode>(node->getOperand(1));
            while (cast<MDString>(parent_node->getOperand(0))->getString() != "jtbaa") {
                node = parent_node;
                parent_node = cast<MDNode>(node->getOperand(1));
            }

            // Find the matching node's index
            for (int i = 0; i < 5; i++) {
                if (cast<MDNode>(tbaa_srcs[i]->getOperand(1)) == node)
                    return language_aliasinfo_t(ctx, regions[i], tbaa);
            }
        }
    }

    return language_aliasinfo_t(ctx, Region::unknown, tbaa);
}

static Type *language_type_to_llvm(language_codectx_t &ctx, language_value_t *jt, bool *isboxed = NULL);
static language_returninfo_t get_specsig_function(language_codectx_t &ctx, Module *M, Value *fval, StringRef name, language_value_t *sig, language_value_t *jlrettype, bool is_opaque_closure, bool gcstack_arg, BitVector *used_arguments=nullptr, size_t *args_begin=nullptr);
static language_cgval_t emit_expr(language_codectx_t &ctx, language_value_t *expr, ssize_t ssaval = -1);
static Value *global_binding_pointer(language_codectx_t &ctx, language_module_t *m, language_sym_t *s,
                                     language_binding_t **pbnd, bool assign);
static language_cgval_t emit_checked_var(language_codectx_t &ctx, Value *bp, language_sym_t *name, language_value_t *scope, bool isvol, MDNode *tbaa);
static language_cgval_t emit_sparam(language_codectx_t &ctx, size_t i);
static Value *emit_condition(language_codectx_t &ctx, const language_cgval_t &condV, const Twine &msg);
static Value *get_current_task(language_codectx_t &ctx);
static Value *get_current_ptls(language_codectx_t &ctx);
static Value *get_last_age_field(language_codectx_t &ctx);
static void CreateTrap(IRBuilder<> &irbuilder, bool create_new_block = true);
static CallInst *emit_jlcall(language_codectx_t &ctx, FunctionCallee theFptr, Value *theF,
                             ArrayRef<language_cgval_t> args, size_t nargs, JuliaFunction<> *trampoline);
static CallInst *emit_jlcall(language_codectx_t &ctx, JuliaFunction<> *theFptr, Value *theF,
                             ArrayRef<language_cgval_t> args, size_t nargs, JuliaFunction<> *trampoline);
static Value *emit_f_is(language_codectx_t &ctx, const language_cgval_t &arg1, const language_cgval_t &arg2,
                        Value *nullcheck1 = nullptr, Value *nullcheck2 = nullptr);
static language_cgval_t emit_new_struct(language_codectx_t &ctx, language_value_t *ty, size_t nargs, ArrayRef<language_cgval_t> argv, bool is_promotable=false);
static language_cgval_t emit_invoke(language_codectx_t &ctx, const language_cgval_t &lival, ArrayRef<language_cgval_t> argv, size_t nargs, language_value_t *rt);

static Value *literal_pointer_val(language_codectx_t &ctx, language_value_t *p);
static unsigned language_alignment(language_value_t *jt);

static GlobalVariable *prepare_global_in(Module *M, JuliaVariable *G)
{
    return G->realize(M);
}

template<typename TypeFn_t>
static Function *prepare_call_in(Module *M, JuliaFunction<TypeFn_t> *G)
{
    return G->realize(M);
}

static inline GlobalVariable *prepare_global_in(Module *M, GlobalVariable *G)
{
    if (G->getParent() == M)
        return G;
    GlobalValue *local = M->getNamedValue(G->getName());
    if (!local) {
        // Copy the GlobalVariable, but without the initializer, so it becomes a declaration
        GlobalVariable *proto = new GlobalVariable(*M, G->getValueType(),
                G->isConstant(), G->getLinkage(),
                nullptr, G->getName(), nullptr, G->getThreadLocalMode());
        if (proto->hasLocalLinkage()) {
            proto->setInitializer(G->getInitializer());
        }
        proto->copyAttributesFrom(G);
        // DLLImport only needs to be set for the shadow module
        // it just gets annoying in the JIT
        proto->setDLLStorageClass(GlobalValue::DefaultStorageClass);
        return proto;
    }
    return cast<GlobalVariable>(local);
}


// --- convenience functions for tagging llvm values with julia types ---

static GlobalVariable *get_pointer_to_constant(language_codegen_params_t &emission_context, Constant *val, Align align, const Twine &name, Module &M)
{
    GlobalVariable *&gv = emission_context.mergedConstants[val];
    auto get_gv = [&](const Twine &name) {
        auto gv = new GlobalVariable(
                M,
                val->getType(),
                true,
                GlobalVariable::PrivateLinkage,
                val,
                name);
        gv->setUnnamedAddr(GlobalValue::UnnamedAddr::Global);
        gv->setAlignment(align);
        return gv;
    };
    if (gv == nullptr) {
        gv = get_gv(name + "#" + Twine(emission_context.mergedConstants.size()));
    }
    else if (gv->getParent() != &M) {
        StringRef gvname = gv->getName();
        gv = M.getNamedGlobal(gvname);
        if (!gv) {
            gv = get_gv(gvname);
        }
    }
    assert(gv->getName().startswith(name.str()));
    assert(val == gv->getInitializer());
    return gv;
}

static AllocaInst *emit_static_alloca(language_codectx_t &ctx, Type *lty)
{
    ++EmittedAllocas;
    return new AllocaInst(lty, ctx.topalloca->getModule()->getDataLayout().getAllocaAddrSpace(), "", /*InsertBefore=*/ctx.topalloca);
}

static void undef_derived_strct(language_codectx_t &ctx, Value *ptr, language_datatype_t *sty, MDNode *tbaa)
{
    assert(ptr->getType()->getPointerAddressSpace() != AddressSpace::Tracked);
    size_t first_offset = sty->layout->nfields ? language_field_offset(sty, 0) : 0;
    if (first_offset != 0)
        ctx.builder.CreateMemSet(ptr, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0), first_offset, MaybeAlign(0));
    if (sty->layout->first_ptr < 0)
        return;
    size_t i, np = sty->layout->npointers;
    auto T_prjlvalue = JuliaType::get_prjlvalue_ty(ctx.builder.getContext());
    ptr = ctx.builder.CreateBitCast(ptr, T_prjlvalue->getPointerTo(ptr->getType()->getPointerAddressSpace()));
    for (i = 0; i < np; i++) {
        Value *fld = ctx.builder.CreateConstInBoundsGEP1_32(T_prjlvalue, ptr, language_ptr_offset(sty, i));
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, tbaa);
        ai.decorateInst(ctx.builder.CreateStore(Constant::getNullValue(T_prjlvalue), fld));
    }
}

static Value *emit_inttoptr(language_codectx_t &ctx, Value *v, Type *ty)
{
    // Almost all of our inttoptr are generated due to representing `Ptr` with `ctx.types().T_size`
    // in LLVM and most of these integers are generated from `ptrtoint` in the first place.
    if (auto I = dyn_cast<PtrToIntInst>(v)) {
        auto ptr = I->getOperand(0);
        if (ty->getPointerAddressSpace() == ptr->getType()->getPointerAddressSpace())
            return ctx.builder.CreateBitCast(ptr, ty);
        #if LANGUAGE_LLVM_VERSION >= 170000
        else
        #else
        else if (cast<PointerType>(ty)->hasSameElementTypeAs(cast<PointerType>(ptr->getType())))
        #endif
            return ctx.builder.CreateAddrSpaceCast(ptr, ty);
    }
    ++EmittedIntToPtrs;
    return ctx.builder.CreateIntToPtr(v, ty);
}

static inline language_cgval_t ghostValue(language_codectx_t &ctx, language_value_t *typ)
{
    if (typ == language_bottom_type)
        return language_cgval_t(); // Undef{}
    if (typ == (language_value_t*)language_typeofbottom_type) {
        // normalize TypeofBottom to Type{Union{}}
        typ = (language_value_t*)language_typeofbottom_type->super;
    }
    if (language_is_type_type(typ)) {
        assert(is_uniquerep_Type(typ));
        // replace T::Type{T} with T, by assuming that T must be a leaftype of some sort
        language_cgval_t constant(NULL, true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
        constant.constant = language_tparam0(typ);
        return constant;
    }
    return language_cgval_t(typ);
}
static inline language_cgval_t ghostValue(language_codectx_t &ctx, language_datatype_t *typ)
{
    return ghostValue(ctx, (language_value_t*)typ);
}

static inline language_cgval_t mark_language_const(language_codectx_t &ctx, language_value_t *jv)
{
    language_value_t *typ;
    if (language_is_type(jv)) {
        typ = (language_value_t*)language_wrap_Type(jv); // TODO: gc-root this?
    }
    else {
        typ = language_typeof(jv);
        if (language_is_datatype_singleton((language_datatype_t*)typ))
            return ghostValue(ctx, typ);
    }
    language_cgval_t constant(NULL, true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
    constant.constant = jv;
    return constant;
}


static inline language_cgval_t mark_language_slot(Value *v, language_value_t *typ, Value *tindex, MDNode *tbaa)
{
    // this enables lazy-copying of immutable values and stack or argument slots
    language_cgval_t tagval(v, false, typ, tindex, tbaa);
    return tagval;
}

static bool valid_as_globalinit(const Value *v) {
    if (isa<ConstantExpr>(v)) {
        // llvm can't handle all the things that could be inside a ConstantExpr
        // (such as addrspacecast), and we don't really mind losing this optimization
        return false;
    }
    if (const auto *CC = dyn_cast<ConstantAggregate>(v)) {
        for (const Value *elem : CC->operand_values())
            if (!valid_as_globalinit(elem))
                return false;
    }
    return isa<Constant>(v);
}

static Value *zext_struct(language_codectx_t &ctx, Value *V);

static inline language_cgval_t value_to_pointer(language_codectx_t &ctx, Value *v, language_value_t *typ, Value *tindex)
{
    Value *loc;
    v = zext_struct(ctx, v);
    if (valid_as_globalinit(v)) { // llvm can't handle all the things that could be inside a ConstantExpr
        assert(language_is_concrete_type(typ)); // not legal to have an unboxed abstract type
        loc = get_pointer_to_constant(ctx.emission_context, cast<Constant>(v), Align(language_alignment(typ)), "_j_const", *language_Module);
    }
    else {
        loc = emit_static_alloca(ctx, v->getType());
        ctx.builder.CreateStore(v, loc);
    }
    return mark_language_slot(loc, typ, tindex, ctx.tbaa().tbaa_stack);
}
static inline language_cgval_t value_to_pointer(language_codectx_t &ctx, const language_cgval_t &v)
{
    if (v.ispointer())
        return v;
    return value_to_pointer(ctx, v.V, v.typ, v.TIndex);
}

static inline language_cgval_t mark_language_type(language_codectx_t &ctx, Value *v, bool isboxed, language_value_t *typ)
{
    if (language_is_type_type(typ)) {
        if (is_uniquerep_Type(typ)) {
            // replace T::Type{T} with T
            return ghostValue(ctx, typ);
        }
    } else if (language_is_datatype(typ) && language_is_datatype_singleton((language_datatype_t*)typ)) {
        // no need to explicitly load/store a constant/ghost value
        return ghostValue(ctx, typ);
    }
    Type *T = language_type_to_llvm(ctx, typ);
    if (type_is_ghost(T)) {
        return ghostValue(ctx, typ);
    }
    if (v && !isboxed && v->getType()->isAggregateType() && CountTrackedPointers(v->getType()).count == 0) {
        // eagerly put this back onto the stack
        // llvm mem2reg pass will remove this if unneeded
        return value_to_pointer(ctx, v, typ, NULL);
    }
    if (isboxed)
        return language_cgval_t(v, isboxed, typ, NULL, best_tbaa(ctx.tbaa(), typ));
    return language_cgval_t(v, typ, NULL);
}

static inline language_cgval_t mark_language_type(language_codectx_t &ctx, Value *v, bool isboxed, language_datatype_t *typ)
{
    return mark_language_type(ctx, v, isboxed, (language_value_t*)typ);
}

// see if it might be profitable (and cheap) to change the type of v to typ
static inline language_cgval_t update_language_type(language_codectx_t &ctx, const language_cgval_t &v, language_value_t *typ)
{
    if (v.typ == language_bottom_type || typ == (language_value_t*)language_any_type || language_egal(v.typ, typ))
        return v; // fast-path
    if (v.constant)
        return language_isa(v.constant, typ) ? v : language_cgval_t();
    if (language_is_concrete_type(v.typ) && !language_is_kind(v.typ)) {
        if (language_is_concrete_type(typ) && !language_is_kind(typ)) {
            // type mismatch: changing from one leaftype to another
            CreateTrap(ctx.builder);
            return language_cgval_t();
        }
        return v; // doesn't improve type info
    }
    if (v.TIndex) {
        language_value_t *utyp = language_unwrap_unionall(typ);
        if (language_is_datatype(utyp)) {
            bool alwaysboxed;
            if (language_is_concrete_type(utyp))
                alwaysboxed = !language_is_pointerfree(utyp);
            else
                alwaysboxed = !((language_datatype_t*)utyp)->name->abstract && ((language_datatype_t*)utyp)->name->mutabl;
            if (alwaysboxed) {
                // discovered that this union-split type must actually be isboxed
                if (v.Vboxed) {
                    return language_cgval_t(v.Vboxed, true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
                }
                else {
                    // type mismatch (there weren't any boxed values in the union)
                    CreateTrap(ctx.builder);
                    return language_cgval_t();
                }
            }
        }
        if (!language_is_concrete_type(typ))
            return v; // not generally worth trying to change type info (which would require recomputing tindex)
    }
    Type *T = language_type_to_llvm(ctx, typ);
    if (type_is_ghost(T))
        return ghostValue(ctx, typ);
    else if (v.TIndex && v.V == NULL) {
        // type mismatch (there weren't any non-ghost values in the union)
        CreateTrap(ctx.builder);
        return language_cgval_t();
    }
    return language_cgval_t(v, typ, NULL);
}

static language_cgval_t convert_language_type(language_codectx_t &ctx, const language_cgval_t &v, language_value_t *typ, Value **skip=nullptr);

// --- allocating local variables ---

static language_sym_t *slot_symbol(language_codectx_t &ctx, int s)
{
    return (language_sym_t*)language_array_ptr_ref(ctx.source->slotnames, s);
}

static void store_def_flag(language_codectx_t &ctx, const language_varinfo_t &vi, bool val)
{
    assert((!vi.boxroot || vi.pTIndex) && "undef check is null pointer for boxed things");
    assert(vi.usedUndef && vi.defFlag && "undef flag codegen corrupted");
    ctx.builder.CreateStore(ConstantInt::get(getInt1Ty(ctx.builder.getContext()), val), vi.defFlag, vi.isVolatile);
}

static void alloc_def_flag(language_codectx_t &ctx, language_varinfo_t& vi)
{
    assert((!vi.boxroot || vi.pTIndex) && "undef check is null pointer for boxed things");
    if (vi.usedUndef) {
        vi.defFlag = emit_static_alloca(ctx, getInt1Ty(ctx.builder.getContext()));
        setName(ctx.emission_context, vi.defFlag, "isdefined");
        store_def_flag(ctx, vi, false);
    }
}


// --- utilities ---

static void CreateTrap(IRBuilder<> &irbuilder, bool create_new_block)
{
    Function *f = irbuilder.GetInsertBlock()->getParent();
    Function *trap_func = Intrinsic::getDeclaration(
            f->getParent(),
            Intrinsic::trap);
    irbuilder.CreateCall(trap_func);
    irbuilder.CreateUnreachable();
    if (create_new_block) {
        BasicBlock *newBB = BasicBlock::Create(irbuilder.getContext(), "after_noret", f);
        irbuilder.SetInsertPoint(newBB);
    }
    else {
        irbuilder.ClearInsertionPoint();
    }
}

#if 0 // this code is likely useful, but currently unused
#ifndef LANGUAGE_NDEBUG
static void CreateConditionalAbort(IRBuilder<> &irbuilder, Value *test)
{
    Function *f = irbuilder.GetInsertBlock()->getParent();
    BasicBlock *abortBB = BasicBlock::Create(irbuilder.getContext(), "debug_abort", f);
    BasicBlock *postBB = BasicBlock::Create(irbuilder.getContext(), "post_abort", f);
    irbuilder.CreateCondBr(test, abortBB, postBB);
    irbuilder.SetInsertPoint(abortBB);
    Function *trap_func = Intrinsic::getDeclaration(
            f->getParent(),
            Intrinsic::trap);
    irbuilder.CreateCall(trap_func);
    irbuilder.CreateUnreachable();
    irbuilder.SetInsertPoint(postBB);
}
#endif
#endif


#include "cgutils.cpp"

static language_cgval_t convert_language_type_union(language_codectx_t &ctx, const language_cgval_t &v, language_value_t *typ, Value **skip)
{
    // previous value was a split union, compute new index, or box
    Value *new_tindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER);
    SmallBitVector skip_box(1, true);
    Value *tindex = ctx.builder.CreateAnd(v.TIndex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0x7f));
    if (language_is_uniontype(typ)) {
        // compute the TIndex mapping from v.typ -> typ
        unsigned counter = 0;
        for_each_uniontype_small(
            // for each old union-split value
            [&](unsigned idx, language_datatype_t *jt) {
                unsigned new_idx = get_box_tindex(jt, typ);
                bool t;
                if (new_idx) {
                    // found a matching element,
                    // match it against either the unboxed index
                    Value *cmp = ctx.builder.CreateICmpEQ(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), idx));
                    new_tindex = ctx.builder.CreateSelect(cmp, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), new_idx), new_tindex);
                    t = true;
                }
                else if (!language_subtype((language_value_t*)jt, typ)) {
                    // new value doesn't need to be boxed
                    // since it isn't part of the new union
                    t = true;
                    if (skip) {
                        Value *skip1 = ctx.builder.CreateICmpEQ(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), idx));
                        *skip = *skip ? ctx.builder.CreateOr(*skip, skip1) : skip1;
                    }
                }
                else {
                    // will actually need to box this element
                    // since it appeared as a leaftype in the original type
                    // but not in the remark type
                    t = false;
                }
                skip_box.resize(idx + 1, t);
            },
            v.typ,
            counter);
    }
    setName(ctx.emission_context, new_tindex, "tindex");

    // some of the values are still unboxed
    if (!isa<Constant>(new_tindex)) {
        Value *wasboxed = NULL;
        // If the old value was boxed and unknown (type tag UNION_BOX_MARKER),
        // it is possible that the tag was actually one of the types
        // that are now explicitly represented. To find out, we need
        // to compare typeof(v.Vboxed) (i.e. the type of the unknown
        // value) against all the types that are now explicitly
        // selected and select the appropriate one as our new tindex.
        if (v.Vboxed) {
            wasboxed = ctx.builder.CreateAnd(v.TIndex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
            new_tindex = ctx.builder.CreateOr(wasboxed, new_tindex);
            wasboxed = ctx.builder.CreateICmpNE(wasboxed, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
            setName(ctx.emission_context, wasboxed, "wasboxed");

            BasicBlock *currBB = ctx.builder.GetInsertBlock();

            // We lazily create a BB for this, once we decide that we
            // actually need it.
            Value *union_box_dt = NULL;
            BasicBlock *union_isaBB = NULL;
            BasicBlock *post_union_isaBB = NULL;
            auto maybe_setup_union_isa = [&]() {
                if (!union_isaBB) {
                    union_isaBB = BasicBlock::Create(ctx.builder.getContext(), "union_isa", ctx.f);
                    ctx.builder.SetInsertPoint(union_isaBB);
                    union_box_dt = emit_typeof(ctx, v.Vboxed, skip != NULL, true);
                    post_union_isaBB = ctx.builder.GetInsertBlock();
                }
            };

            // If we don't find a match. The type remains unknown
            // (UNION_BOX_MARKER). We could use `v.Tindex`, here, since we know
            // it has to be UNION_BOX_MARKER, but it seems likely the backend
            // will like the explicit constant better.
            Value *union_box_tindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER);
            unsigned counter = 0;
            for_each_uniontype_small(
                // for each new union-split value
                [&](unsigned idx, language_datatype_t *jt) {
                    unsigned old_idx = get_box_tindex(jt, v.typ);
                    if (old_idx == 0) {
                        // didn't handle this item before, select its new union index
                        maybe_setup_union_isa();
                        Value *cmp = ctx.builder.CreateICmpEQ(emit_tagfrom(ctx, jt), union_box_dt);
                        union_box_tindex = ctx.builder.CreateSelect(cmp, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER | idx), union_box_tindex);
                    }
                },
                typ,
                counter);
            setName(ctx.emission_context, union_box_tindex, "union_box_tindex");
            if (union_box_dt) {
                BasicBlock *postBB = BasicBlock::Create(ctx.builder.getContext(), "post_union_isa", ctx.f);
                ctx.builder.CreateBr(postBB);
                ctx.builder.SetInsertPoint(currBB);
                Value *wasunknown = ctx.builder.CreateICmpEQ(v.TIndex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
                ctx.builder.CreateCondBr(wasunknown, union_isaBB, postBB);
                ctx.builder.SetInsertPoint(postBB);
                PHINode *tindex_phi = ctx.builder.CreatePHI(getInt8Ty(ctx.builder.getContext()), 2);
                tindex_phi->addIncoming(new_tindex, currBB);
                tindex_phi->addIncoming(union_box_tindex, post_union_isaBB);
                new_tindex = tindex_phi;
                setName(ctx.emission_context, new_tindex, "tindex");
            }
        }
        if (!skip_box.all()) {
            // some values weren't unboxed in the new union
            // box them now (tindex above already selected UNION_BOX_MARKER = box for them)
            Value *boxv = box_union(ctx, v, skip_box);
            if (v.Vboxed) {
                // If the value is boxed both before and after, we don't need
                // to touch it at all. Otherwise we're either transitioning
                // unboxed->boxed, or leaving an unboxed value in place.
                Value *isboxed = ctx.builder.CreateICmpNE(
                    ctx.builder.CreateAnd(new_tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                    ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
                boxv = ctx.builder.CreateSelect(
                    ctx.builder.CreateAnd(wasboxed, isboxed), v.Vboxed, boxv);
            }
            Value *slotv;
            MDNode *tbaa;
            if (v.V == NULL) {
                // v.V might be NULL if it was all ghost objects before
                slotv = NULL;
                tbaa = ctx.tbaa().tbaa_const;
            }
            else {
                Value *isboxv = ctx.builder.CreateIsNotNull(boxv);
                language_cgval_t oldv = value_to_pointer(ctx, v);
                slotv = oldv.V;
                tbaa = oldv.tbaa;
                slotv = ctx.builder.CreateSelect(isboxv,
                            decay_derived(ctx, boxv),
                            decay_derived(ctx, emit_bitcast(ctx, slotv, boxv->getType())));
            }
            language_cgval_t newv = language_cgval_t(slotv, false, typ, new_tindex, tbaa);
            assert(boxv->getType() == ctx.types().T_prjlvalue);
            newv.Vboxed = boxv;
            return newv;
        }
    }
    else {
        return language_cgval_t(boxed(ctx, v), true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
    }
    return language_cgval_t(v, typ, new_tindex);
}

// given a value marked with type `v.typ`, compute the mapping and/or boxing to return a value of type `typ`
// TODO: should this set TIndex when trivial (such as UNION_BOX_MARKER or concrete types) ?
static language_cgval_t convert_language_type(language_codectx_t &ctx, const language_cgval_t &v, language_value_t *typ, Value **skip)
{
    if (typ == (language_value_t*)language_typeofbottom_type)
        return ghostValue(ctx, typ); // normalize TypeofBottom to Type{Union{}}
    if (v.typ == language_bottom_type || language_egal(v.typ, typ))
        return v; // fast-path
    Type *T = language_type_to_llvm(ctx, typ);
    if (type_is_ghost(T))
        return ghostValue(ctx, typ);
    Value *new_tindex = NULL;
    if (language_is_concrete_type(typ)) {
        if (language_is_concrete_type(v.typ)) {
            // type mismatch: changing from one leaftype to another
            if (skip)
                *skip = ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);
            else
                CreateTrap(ctx.builder);
            return language_cgval_t();
        }
        bool mustbox_union = v.TIndex && !language_is_pointerfree(typ);
        if (v.Vboxed && (v.isboxed || mustbox_union)) {
            if (skip) {
                *skip = ctx.builder.CreateNot(emit_exactly_isa(ctx, v, (language_datatype_t*)typ, true));
            }
            return language_cgval_t(v.Vboxed, true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
        }
        if (mustbox_union) {
            // type mismatch: there weren't any boxed values in the union
            if (skip)
                *skip = ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);
            else
                CreateTrap(ctx.builder);
            return language_cgval_t();
        }
    }
    else {
        bool makeboxed = false;
        if (v.TIndex) {
            return convert_language_type_union(ctx, v, typ, skip);
        }
        else if (!v.isboxed && language_is_uniontype(typ)) {
            // previous value was unboxed (leaftype), statically compute union tindex
            assert(language_is_concrete_type(v.typ));
            unsigned new_idx = get_box_tindex((language_datatype_t*)v.typ, typ);
            if (new_idx) {
                new_tindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), new_idx);
                if (v.V && !v.ispointer()) {
                    // TODO: remove this branch once all consumers of v.TIndex understand how to handle a non-ispointer value
                    return language_cgval_t(value_to_pointer(ctx, v), typ, new_tindex);
                }
            }
            else if (language_subtype(v.typ, typ)) {
                makeboxed = true;
            }
            else if (skip) {
                // undef
                *skip = ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);
                return language_cgval_t();
            }
            else {
                // unreachable
                CreateTrap(ctx.builder);
                return language_cgval_t();
            }
        }
        else if (!v.isboxed) {
            makeboxed = true;
        }
        if (makeboxed) {
            // convert to a simple isboxed value
            return language_cgval_t(boxed(ctx, v), true, typ, NULL, best_tbaa(ctx.tbaa(), typ));
        }
    }
    return language_cgval_t(v, typ, new_tindex);
}

std::unique_ptr<Module> language_create_llvm_module(StringRef name, LLVMContext &context, const DataLayout &DL, const Triple &triple)
{
    ++ModulesCreated;
    auto m = std::make_unique<Module>(name, context);
    // According to clang darwin above 10.10 supports dwarfv4
    if (!m->getModuleFlag("Dwarf Version")) {
        m->addModuleFlag(llvm::Module::Warning, "Dwarf Version", 4);
    }
    if (!m->getModuleFlag("Debug Info Version"))
        m->addModuleFlag(llvm::Module::Warning, "Debug Info Version",
            llvm::DEBUG_METADATA_VERSION);
    m->setDataLayout(DL);
    m->setTargetTriple(triple.str());

    if (triple.isOSWindows() && triple.getArch() == Triple::x86) {
        // tell Win32 to assume the stack is always 16-byte aligned,
        // and to ensure that it is 16-byte aligned for out-going calls,
        // to ensure compatibility with GCC codes
        m->setOverrideStackAlignment(16);
    }

#if defined(LANGUAGE_DEBUG_BUILD)
    m->setStackProtectorGuard("global");
#endif
    return m;
}

static void language_name_jlfunc_args(language_codegen_params_t &params, Function *F) {
    assert(F->arg_size() == 3);
    F->getArg(0)->setName("function::Core.Function");
    F->getArg(1)->setName("args::Any[]");
    F->getArg(2)->setName("nargs::UInt32");
}

static void language_name_jlfuncparams_args(language_codegen_params_t &params, Function *F) {
    assert(F->arg_size() == 4);
    F->getArg(0)->setName("function::Core.Function");
    F->getArg(1)->setName("args::Any[]");
    F->getArg(2)->setName("nargs::UInt32");
    F->getArg(3)->setName("sparams::Any");
}

static void language_init_function(Function *F, const Triple &TT)
{
    // set any attributes that *must* be set on all functions
    AttrBuilder attr(F->getContext());
    if (TT.isOSWindows() && TT.getArch() == Triple::x86) {
        // tell Win32 to assume the stack is always 16-byte aligned,
        // and to ensure that it is 16-byte aligned for out-going calls,
        // to ensure compatibility with GCC codes
        attr.addStackAlignmentAttr(16);
    }
    if (TT.isOSWindows() && TT.getArch() == Triple::x86_64) {
        attr.addUWTableAttr(llvm::UWTableKind::Default); // force NeedsWinEH
    }
    if (language_fpo_disabled(TT))
        attr.addAttribute("frame-pointer", "all");
    if (!TT.isOSWindows()) {
#if !defined(_COMPILER_ASAN_ENABLED_)
        // ASAN won't like us accessing undefined memory causing spurious issues,
        // and Windows has platform-specific handling which causes it to mishandle
        // this annotation. Other platforms should just ignore this if they don't
        // implement it.
        attr.addAttribute("probe-stack", "inline-asm");
        //attr.addAttribute("stack-probe-size", "4096"); // can use this to change the default
#endif
    }
#if defined(_COMPILER_ASAN_ENABLED_)
    attr.addAttribute(Attribute::SanitizeAddress);
#endif
#if defined(_COMPILER_MSAN_ENABLED_)
    attr.addAttribute(Attribute::SanitizeMemory);
#endif
    F->addFnAttrs(attr);
}

static bool uses_specsig(language_value_t *sig, bool needsparams, language_value_t *rettype, bool prefer_specsig)
{
    if (needsparams)
        return false;
    if (sig == (language_value_t*)language_anytuple_type)
        return false;
    if (!language_is_datatype(sig))
        return false;
    if (language_nparams(sig) == 0)
        return false;
    if (language_vararg_kind(language_tparam(sig, language_nparams(sig) - 1)) == LANGUAGE_VARARG_UNBOUND)
        return false;
    // not invalid, consider if specialized signature is worthwhile
    if (prefer_specsig)
        return true;
    if (!deserves_retbox(rettype) && !language_is_datatype_singleton((language_datatype_t*)rettype) && rettype != (language_value_t*)language_bool_type)
        return true;
    if (language_is_uniontype(rettype)) {
        bool allunbox;
        size_t nbytes, align, min_align;
        union_alloca_type((language_uniontype_t*)rettype, allunbox, nbytes, align, min_align);
        if (nbytes > 0)
            return true; // some elements of the union could be returned unboxed avoiding allocation
    }
    if (language_nparams(sig) <= 3) // few parameters == more efficient to pass directly
        return true;
    bool allSingleton = true;
    for (size_t i = 0; i < language_nparams(sig); i++) {
        language_value_t *sigt = language_tparam(sig, i);
        bool issing = language_is_datatype(sigt) && language_is_datatype_singleton((language_datatype_t*)sigt);
        allSingleton &= issing;
        if (!deserves_argbox(sigt) && !issing) {
            return true;
        }
    }
    if (allSingleton)
        return true;
    return false; // jlcall sig won't require any box allocations
}

static std::pair<bool, bool> uses_specsig(language_method_instance_t *lam, language_value_t *rettype, bool prefer_specsig)
{
    language_value_t *sig = lam->specTypes;
    bool needsparams = false;
    if (language_is_method(lam->def.method)) {
        if ((size_t)language_subtype_env_size(lam->def.method->sig) != language_svec_len(lam->sparam_vals))
            needsparams = true;
        for (size_t i = 0; i < language_svec_len(lam->sparam_vals); ++i) {
            if (language_is_typevar(language_svecref(lam->sparam_vals, i)))
                needsparams = true;
        }
    }
    return std::make_pair(uses_specsig(sig, needsparams, rettype, prefer_specsig), needsparams);
}


// Logging for code coverage and memory allocation

LANGUAGE_DLLEXPORT void language_coverage_alloc_line(StringRef filename, int line);
LANGUAGE_DLLEXPORT uint64_t *language_coverage_data_pointer(StringRef filename, int line);
LANGUAGE_DLLEXPORT uint64_t *language_malloc_data_pointer(StringRef filename, int line);

static void visitLine(language_codectx_t &ctx, uint64_t *ptr, Value *addend, const char *name)
{
    Value *pv = ConstantExpr::getIntToPtr(
        ConstantInt::get(ctx.types().T_size, (uintptr_t)ptr),
        getInt64PtrTy(ctx.builder.getContext()));
    Value *v = ctx.builder.CreateLoad(getInt64Ty(ctx.builder.getContext()), pv, true, name);
    v = ctx.builder.CreateAdd(v, addend);
    ctx.builder.CreateStore(v, pv, true); // volatile, not atomic, so this might be an underestimate,
                                          // but it's faster this way
}

// Code coverage

static void coverageVisitLine(language_codectx_t &ctx, StringRef filename, int line)
{
    if (ctx.emission_context.imaging_mode)
        return; // TODO
    if (filename == "" || filename == "none" || filename == "no file" || filename == "<missing>" || line < 0)
        return;
    visitLine(ctx, language_coverage_data_pointer(filename, line), ConstantInt::get(getInt64Ty(ctx.builder.getContext()), 1), "lcnt");
}

// Memory allocation log (malloc_log)

static void mallocVisitLine(language_codectx_t &ctx, StringRef filename, int line, Value *sync)
{
    if (ctx.emission_context.imaging_mode)
        return; // TODO
    if (filename == "" || filename == "none" || filename == "no file" || filename == "<missing>" || line < 0)
        return;
    Value *addend = sync
        ? ctx.builder.CreateCall(prepare_call(sync_gc_total_bytes_func), {sync})
        : ctx.builder.CreateCall(prepare_call(diff_gc_total_bytes_func), {});
    visitLine(ctx, language_malloc_data_pointer(filename, line), addend, "bytecnt");
}

// --- constant determination ---

static void show_source_loc(language_codectx_t &ctx, LANGUAGE_STREAM *out)
{
    language_printf(out, "in %s at %s", ctx.name, ctx.file.str().c_str());
}

static void cg_bdw(language_codectx_t &ctx, language_sym_t *var, language_binding_t *b)
{
    language_binding_deprecation_warning(ctx.module, var, b);
    if (b->deprecated == 1 && language_options.depwarn) {
        show_source_loc(ctx, LANGUAGE_STDERR);
        language_printf(LANGUAGE_STDERR, "\n");
    }
}

static language_value_t *static_apply_type(language_codectx_t &ctx, ArrayRef<language_cgval_t> args, size_t nargs)
{
    assert(nargs > 1);
    SmallVector<language_value_t *, 0> v(nargs);
    for (size_t i = 0; i < nargs; i++) {
        if (!args[i].constant)
            return NULL;
        v[i] = args[i].constant;
    }
    assert(v[0] == language_builtin_apply_type);
    size_t last_age = language_current_task->world_age;
    // call apply_type, but ignore errors. we know that will work in world 1.
    language_current_task->world_age = 1;
    language_value_t *result;
    LANGUAGE_TRY {
        result = language_apply(v.data(), nargs);
    }
    LANGUAGE_CATCH {
        result = NULL;
    }
    language_current_task->world_age = last_age;
    return result;
}

// try to statically evaluate, NULL if not possible. note that this may allocate, and as
// such the resulting value should not be embedded directly in the generated code.
static language_value_t *static_eval(language_codectx_t &ctx, language_value_t *ex)
{
    if (language_is_symbol(ex)) {
        language_sym_t *sym = (language_sym_t*)ex;
        if (language_is_const(ctx.module, sym))
            return language_get_global(ctx.module, sym);
        return NULL;
    }
    if (language_is_slotnumber(ex) || language_is_argument(ex))
        return NULL;
    if (language_is_ssavalue(ex)) {
        ssize_t idx = ((language_ssavalue_t*)ex)->id - 1;
        assert(idx >= 0);
        if (ctx.ssavalue_assigned[idx]) {
            return ctx.SAvalues[idx].constant;
        }
        return NULL;
    }
    if (language_is_quotenode(ex))
        return language_fieldref(ex, 0);
    if (language_is_method_instance(ex))
        return NULL;
    language_module_t *m = NULL;
    language_sym_t *s = NULL;
    if (language_is_globalref(ex)) {
        s = language_globalref_name(ex);
        language_binding_t *b = language_get_binding(language_globalref_mod(ex), s);
        if (b && b->constp) {
            if (b->deprecated)
                cg_bdw(ctx, s, b);
            return language_atomic_load_relaxed(&b->value);
        }
        return NULL;
    }
    if (language_is_expr(ex)) {
        language_expr_t *e = (language_expr_t*)ex;
        if (e->head == language_call_sym) {
            language_value_t *f = static_eval(ctx, language_exprarg(e, 0));
            if (f) {
                if (language_array_dim0(e->args) == 3 && (f == language_builtin_getfield || f == language_builtin_getglobal)) {
                    m = (language_module_t*)static_eval(ctx, language_exprarg(e, 1));
                    // Check the tag before evaluating `s` so that a value of random
                    // type won't be corrupted.
                    if (!m || !language_is_module(m))
                        return NULL;
                    // Assumes that the module is rooted somewhere.
                    s = (language_sym_t*)static_eval(ctx, language_exprarg(e, 2));
                    if (s && language_is_symbol(s)) {
                        language_binding_t *b = language_get_binding(m, s);
                        if (b && b->constp) {
                            if (b->deprecated)
                                cg_bdw(ctx, s, b);
                            return language_atomic_load_relaxed(&b->value);
                        }
                    }
                }
                else if (f==language_builtin_tuple || f==language_builtin_apply_type) {
                    size_t i;
                    size_t n = language_array_dim0(e->args)-1;
                    if (n==0 && f==language_builtin_tuple) return (language_value_t*)language_emptytuple;
                    language_value_t **v;
                    LANGUAGE_GC_PUSHARGS(v, n+1);
                    v[0] = f;
                    for (i = 0; i < n; i++) {
                        v[i+1] = static_eval(ctx, language_exprarg(e, i+1));
                        if (v[i+1] == NULL) {
                            LANGUAGE_GC_POP();
                            return NULL;
                        }
                    }
                    size_t last_age = language_current_task->world_age;
                    // here we know we're calling specific builtin functions that work in world 1.
                    language_current_task->world_age = 1;
                    language_value_t *result;
                    LANGUAGE_TRY {
                        result = language_apply(v, n+1);
                    }
                    LANGUAGE_CATCH {
                        result = NULL;
                    }
                    language_current_task->world_age = last_age;
                    LANGUAGE_GC_POP();
                    return result;
                }
            }
        }
        else if (e->head == language_static_parameter_sym) {
            size_t idx = language_unbox_long(language_exprarg(e, 0));
            if (idx <= language_svec_len(ctx.linfo->sparam_vals)) {
                language_value_t *e = language_svecref(ctx.linfo->sparam_vals, idx - 1);
                if (language_is_typevar(e))
                    return NULL;
                return e;
            }
        }
        return NULL;
    }
    return ex;
}

static bool slot_eq(language_value_t *e, int sl)
{
    return (language_is_slotnumber(e) || language_is_argument(e)) && language_slot_number(e)-1 == sl;
}

// --- code gen for intrinsic functions ---

#include "intrinsics.cpp"

// --- find volatile variables ---

// assigned in a try block and used outside that try block

static bool local_var_occurs(language_value_t *e, int sl)
{
    if (slot_eq(e, sl)) {
        return true;
    }
    else if (language_is_expr(e)) {
        language_expr_t *ex = (language_expr_t*)e;
        size_t alength = language_array_dim0(ex->args);
        for(int i=0; i < (int)alength; i++) {
            if (local_var_occurs(language_exprarg(ex,i),sl))
                return true;
        }
    }
    else if (language_is_returnnode(e)) {
        language_value_t *retexpr = language_returnnode_value(e);
        if (retexpr != NULL)
            return local_var_occurs(retexpr, sl);
    }
    else if (language_is_gotoifnot(e)) {
        return local_var_occurs(language_gotoifnot_cond(e), sl);
    }
    return false;
}

static std::set<int> assigned_in_try(language_array_t *stmts, int s, long l)
{
    std::set<int> av;
    for(int i=s; i < l; i++) {
        language_value_t *st = language_array_ptr_ref(stmts,i);
        if (language_is_expr(st)) {
            if (((language_expr_t*)st)->head == language_assign_sym) {
                language_value_t *ar = language_exprarg(st, 0);
                if (language_is_slotnumber(ar)) {
                    av.insert(language_slot_number(ar)-1);
                }
            }
        }
    }
    return av;
}

static void mark_volatile_vars(language_array_t *stmts, SmallVectorImpl<language_varinfo_t> &slots)
{
    size_t slength = language_array_dim0(stmts);
    for (int i = 0; i < (int)slength; i++) {
        language_value_t *st = language_array_ptr_ref(stmts, i);
        if (language_is_enternode(st)) {
            int last = language_enternode_catch_dest(st);
            if (last == 0)
                continue;
            std::set<int> as = assigned_in_try(stmts, i + 1, last - 1);
            for (int j = 0; j < (int)slength; j++) {
                if (j < i || j > last) {
                    std::set<int>::iterator it = as.begin();
                    for (; it != as.end(); it++) {
                        if (local_var_occurs(language_array_ptr_ref(stmts, j), *it)) {
                            language_varinfo_t &vi = slots[*it];
                            vi.isVolatile = true;
                        }
                    }
                }
            }
        }
    }
}

// --- use analysis ---

// a very simple, conservative use analysis
// to eagerly remove slot assignments that are never read from

template <typename callback>
static void general_use_analysis(language_codectx_t &ctx, language_value_t *expr, callback &f)
{
    if (f(expr)) {
        return;
    }
    else if (language_is_expr(expr)) {
        language_expr_t *e = (language_expr_t*)expr;
        if (e->head == language_method_sym) {
            general_use_analysis(ctx, language_exprarg(e, 0), f);
            if (language_expr_nargs(e) > 1) {
                general_use_analysis(ctx, language_exprarg(e, 1), f);
                general_use_analysis(ctx, language_exprarg(e, 2), f);
            }
        }
        else if (e->head == language_assign_sym) {
            // don't consider assignment LHS as a variable "use"
            general_use_analysis(ctx, language_exprarg(e, 1), f);
        }
        else {
            size_t i, elen = language_array_dim0(e->args);
            for (i = 0; i < elen; i++) {
                general_use_analysis(ctx, language_exprarg(e, i), f);
            }
        }
    }
    else if (language_is_returnnode(expr)) {
        language_value_t *retexpr = language_returnnode_value(expr);
        if (retexpr != NULL)
            general_use_analysis(ctx, retexpr, f);
    }
    else if (language_is_gotoifnot(expr)) {
        general_use_analysis(ctx, language_gotoifnot_cond(expr), f);
    }
    else if (language_is_pinode(expr)) {
        general_use_analysis(ctx, language_fieldref_noalloc(expr, 0), f);
    }
    else if (language_is_upsilonnode(expr)) {
        language_value_t *val = language_fieldref_noalloc(expr, 0);
        if (val)
            general_use_analysis(ctx, val, f);
    }
    else if (language_is_phicnode(expr)) {
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(expr, 0);
        size_t i, elen = language_array_nrows(values);
        for (i = 0; i < elen; i++) {
            language_value_t *v = language_array_ptr_ref(values, i);
            general_use_analysis(ctx, v, f);
        }
    }
    else if (language_is_phinode(expr)) {
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(expr, 1);
        size_t i, elen = language_array_nrows(values);
        for (i = 0; i < elen; i++) {
            language_value_t *v = language_array_ptr_ref(values, i);
            if (v)
                general_use_analysis(ctx, v, f);
        }
    }
}

static void simple_use_analysis(language_codectx_t &ctx, language_value_t *expr)
{
    auto scan_slot_arg = [&](language_value_t *expr) {
        if (language_is_slotnumber(expr) || language_is_argument(expr)) {
            int i = language_slot_number(expr) - 1;
            ctx.slots[i].used = true;
            return true;
        }
        return false;
    };
    return general_use_analysis(ctx, expr, scan_slot_arg);
}

// --- gc root utils ---

// ---- Get Element Pointer (GEP) instructions within the GC frame ----

static language_value_t *language_ensure_rooted(language_codectx_t &ctx, language_value_t *val)
{
    if (language_is_globally_rooted(val))
        return val;
    language_method_t *m = ctx.linfo->def.method;
    if (language_is_method(m)) {
        // the method might have a root for this already; use it if so
        LANGUAGE_LOCK(&m->writelock);
        if (m->roots) {
            size_t i, len = language_array_dim0(m->roots);
            for (i = 0; i < len; i++) {
                language_value_t *mval = language_array_ptr_ref(m->roots, i);
                if (mval == val || language_egal(mval, val)) {
                    LANGUAGE_UNLOCK(&m->writelock);
                    return mval;
                }
            }
        }
        LANGUAGE_UNLOCK(&m->writelock);
    }
    return language_as_global_root(val, 1);
}

// --- generating function calls ---

static language_cgval_t emit_globalref(language_codectx_t &ctx, language_module_t *mod, language_sym_t *name, AtomicOrdering order)
{
    language_binding_t *bnd = NULL;
    Value *bp = global_binding_pointer(ctx, mod, name, &bnd, false);
    if (bp == NULL)
        return language_cgval_t();
    bp = language_binding_pvalue(ctx, bp);
    language_value_t *ty = nullptr;
    if (bnd) {
        language_value_t *v = language_atomic_load_acquire(&bnd->value); // acquire value for ty
        if (v != NULL && bnd->constp)
            return mark_language_const(ctx, v);
        ty = language_atomic_load_relaxed(&bnd->ty);
    }
    if (ty == nullptr)
        ty = (language_value_t*)language_any_type;
    return update_language_type(ctx, emit_checked_var(ctx, bp, name, (language_value_t*)mod, false, ctx.tbaa().tbaa_binding), ty);
}

static language_cgval_t emit_globalop(language_codectx_t &ctx, language_module_t *mod, language_sym_t *sym, language_cgval_t rval, const language_cgval_t &cmp,
                                AtomicOrdering Order, AtomicOrdering FailOrder,
                                bool issetglobal, bool isreplaceglobal, bool isswapglobal, bool ismodifyglobal, bool issetglobalonce,
                                const language_cgval_t *modifyop)
{
    language_binding_t *bnd = NULL;
    Value *bp = global_binding_pointer(ctx, mod, sym, &bnd, true);
    if (bp == NULL)
        return language_cgval_t();
    if (bnd && !bnd->constp) {
        language_value_t *ty = language_atomic_load_relaxed(&bnd->ty);
        if (ty != nullptr) {
            const std::string fname = issetglobal ? "setglobal!" : isreplaceglobal ? "replaceglobal!" : isswapglobal ? "swapglobal!" : ismodifyglobal ? "modifyglobal!" : "setglobalonce!";
            if (!ismodifyglobal) {
                // TODO: use typeassert in language_check_binding_wr too
                emit_typecheck(ctx, rval, ty, "typeassert");
                rval = update_language_type(ctx, rval, ty);
                if (rval.typ == language_bottom_type)
                    return language_cgval_t();
            }
            bool isboxed = true;
            bool maybe_null = language_atomic_load_relaxed(&bnd->value) == NULL;
            return typed_store(ctx,
                               language_binding_pvalue(ctx, bp),
                               rval, cmp, ty,
                               ctx.tbaa().tbaa_binding,
                               nullptr,
                               bp,
                               isboxed,
                               Order,
                               FailOrder,
                               0,
                               nullptr,
                               issetglobal,
                               isreplaceglobal,
                               isswapglobal,
                               ismodifyglobal,
                               issetglobalonce,
                               maybe_null,
                               modifyop,
                               fname,
                               mod,
                               sym);

        }
    }
    Value *m = literal_pointer_val(ctx, (language_value_t*)mod);
    Value *s = literal_pointer_val(ctx, (language_value_t*)sym);
    if (issetglobal) {
        ctx.builder.CreateCall(prepare_call(jlcheckassign_func),
                { bp, m, s, mark_callee_rooted(ctx, boxed(ctx, rval)) });
        return rval;
    }
    else if (isreplaceglobal) {
        Value *r = ctx.builder.CreateCall(prepare_call(jlcheckreplace_func),
                { bp, m, s, boxed(ctx, cmp), boxed(ctx, rval) });
        return mark_language_type(ctx, r, true, language_any_type);
    }
    else if (isswapglobal) {
        Value *r = ctx.builder.CreateCall(prepare_call(jlcheckswap_func),
                { bp, m, s, mark_callee_rooted(ctx, boxed(ctx, rval)) });
        return mark_language_type(ctx, r, true, language_any_type);
    }
    else if (ismodifyglobal) {
        Value *r = ctx.builder.CreateCall(prepare_call(jlcheckmodify_func),
                { bp, m, s, boxed(ctx, cmp), boxed(ctx, rval) });
        return mark_language_type(ctx, r, true, language_any_type);
    }
    else if (issetglobalonce) {
        Value *r = ctx.builder.CreateCall(prepare_call(jlcheckassignonce_func),
                { bp, m, s, mark_callee_rooted(ctx, boxed(ctx, rval)) });
        return mark_language_type(ctx, r, true, language_bool_type);
    }
    abort(); // unreachable
}

static Value *emit_box_compare(language_codectx_t &ctx, const language_cgval_t &arg1, const language_cgval_t &arg2,
                               Value *nullcheck1, Value *nullcheck2)
{
    ++EmittedBoxCompares;
    if (language_pointer_egal(arg1.typ) || language_pointer_egal(arg2.typ)) {
        // if we can be certain we won't try to load from the pointer (because
        // we know boxed is trivial), we can skip the separate null checks
        // and just do the ICmpEQ test
        if (!arg1.TIndex && !arg2.TIndex)
            nullcheck1 = nullcheck2 = nullptr;
    }
    return emit_nullcheck_guard2(ctx, nullcheck1, nullcheck2, [&] {
        Value *varg1 = decay_derived(ctx, boxed(ctx, arg1));
        Value *varg2 = decay_derived(ctx, boxed(ctx, arg2));
        if (language_pointer_egal(arg1.typ) || language_pointer_egal(arg2.typ)) {
            return ctx.builder.CreateICmpEQ(varg1, varg2);
        }
        Value *neq = ctx.builder.CreateICmpNE(varg1, varg2);
        return emit_guarded_test(ctx, neq, true, [&] {
            Value *dtarg = emit_typeof(ctx, arg1, false, true);
            Value *dt_eq = ctx.builder.CreateICmpEQ(dtarg, emit_typeof(ctx, arg2, false, true));
            return emit_guarded_test(ctx, dt_eq, false, [&] {
                return ctx.builder.CreateTrunc(ctx.builder.CreateCall(prepare_call(jlegalx_func),
                                                                      {varg1, varg2, dtarg}), getInt1Ty(ctx.builder.getContext()));
            });
        });
    });
}

static Value *emit_bits_compare(language_codectx_t &ctx, language_cgval_t arg1, language_cgval_t arg2);

static Value *emit_bitsunion_compare(language_codectx_t &ctx, const language_cgval_t &arg1, const language_cgval_t &arg2)
{
    ++EmittedBitsUnionCompares;
    assert(language_egal(arg1.typ, arg2.typ) && arg1.TIndex && arg2.TIndex && language_is_uniontype(arg1.typ) && "unimplemented");
    Value *tindex = arg1.TIndex;
    tindex = ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0x7f));
    Value *tindex2 = arg2.TIndex;
    tindex2 = ctx.builder.CreateAnd(tindex2, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0x7f));
    Value *typeeq = ctx.builder.CreateICmpEQ(tindex, tindex2);
    setName(ctx.emission_context, typeeq, "typematch");
    tindex = ctx.builder.CreateSelect(typeeq, tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0x00));
    BasicBlock *defaultBB = BasicBlock::Create(ctx.builder.getContext(), "unionbits_is_boxed", ctx.f);
    SwitchInst *switchInst = ctx.builder.CreateSwitch(tindex, defaultBB);
    BasicBlock *postBB = BasicBlock::Create(ctx.builder.getContext(), "post_unionbits_is", ctx.f);
    ctx.builder.SetInsertPoint(postBB);
    PHINode *phi = ctx.builder.CreatePHI(getInt1Ty(ctx.builder.getContext()), 2);
    switchInst->addCase(ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0), postBB);
    phi->addIncoming(ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 0), switchInst->getParent());
    unsigned counter = 0;
    bool allunboxed = for_each_uniontype_small(
        [&](unsigned idx, language_datatype_t *jt) {
            BasicBlock *tempBB = BasicBlock::Create(ctx.builder.getContext(), "unionbits_is", ctx.f);
            ctx.builder.SetInsertPoint(tempBB);
            switchInst->addCase(ConstantInt::get(getInt8Ty(ctx.builder.getContext()), idx), tempBB);
            language_cgval_t sel_arg1(arg1, (language_value_t*)jt, NULL);
            language_cgval_t sel_arg2(arg2, (language_value_t*)jt, NULL);
            Value *cmp = emit_bits_compare(ctx, sel_arg1, sel_arg2);
            tempBB = ctx.builder.GetInsertBlock(); // could have changed
            phi->addIncoming(cmp, tempBB);
            ctx.builder.CreateBr(postBB);
        },
        arg1.typ,
        counter);
    assert(allunboxed); (void)allunboxed;
    ctx.builder.SetInsertPoint(defaultBB);
    Function *trap_func = Intrinsic::getDeclaration(
        ctx.f->getParent(),
        Intrinsic::trap);
    ctx.builder.CreateCall(trap_func);
    ctx.builder.CreateUnreachable();
    ctx.builder.SetInsertPoint(postBB);
    setName(ctx.emission_context, phi, "unionbits_is");
    return phi;
}

struct egal_desc {
    size_t offset;
    size_t nrepeats;
    size_t data_bytes;
    size_t padding_bytes;
};

template <typename callback>
static size_t emit_masked_bits_compare(callback &emit_desc, language_datatype_t *aty, egal_desc &current_desc)
{
    // Memcmp, but with masked padding
    size_t data_bytes = 0;
    size_t padding_bytes = 0;
    size_t nfields = language_datatype_nfields(aty);
    size_t total_size = language_datatype_size(aty);
    for (size_t i = 0; i < nfields; ++i) {
        size_t offset = language_field_offset(aty, i);
        size_t fend = i == nfields - 1 ? total_size : language_field_offset(aty, i + 1);
        size_t fsz = language_field_size(aty, i);
        language_datatype_t *fty = (language_datatype_t*)language_field_type(aty, i);
        if (language_field_isptr(aty, i) || !fty->layout->flags.haspadding) {
            // The field has no internal padding
            data_bytes += fsz;
            if (offset + fsz == fend) {
                // The field has no padding after. Merge this into the current
                // comparison range and go to next field.
            } else {
                padding_bytes = fend - offset - fsz;
                // Found padding. Either merge this into the current comparison
                // range, or emit the old one and start a new one.
                if (current_desc.data_bytes == data_bytes &&
                        current_desc.padding_bytes == padding_bytes) {
                    // Same as the previous range, just note that down, so we
                    // emit this as a loop.
                    current_desc.nrepeats += 1;
                } else {
                    if (current_desc.nrepeats != 0)
                        emit_desc(current_desc);
                    current_desc.nrepeats = 1;
                    current_desc.data_bytes = data_bytes;
                    current_desc.padding_bytes = padding_bytes;
                }
                data_bytes = 0;
            }
        } else {
            // The field may have internal padding. Recurse this.
            data_bytes += emit_masked_bits_compare(emit_desc, fty, current_desc);
        }
    }
    return data_bytes;
}

static Value *emit_bits_compare(language_codectx_t &ctx, language_cgval_t arg1, language_cgval_t arg2)
{
    ++EmittedBitsCompares;
    bool isboxed;
    Type *at = language_type_to_llvm(ctx, arg1.typ, &isboxed);
    assert(language_is_datatype(arg1.typ) && arg1.typ == arg2.typ && !isboxed);

    if (type_is_ghost(at))
        return ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);

    if (at->isIntegerTy() || at->isPointerTy() || at->isFloatingPointTy()) {
        Type *at_int = INTT(at, ctx.emission_context.DL);
        Value *varg1 = emit_unbox(ctx, at_int, arg1, arg1.typ);
        Value *varg2 = emit_unbox(ctx, at_int, arg2, arg2.typ);
        return ctx.builder.CreateICmpEQ(varg1, varg2);
    }

    if (at->isVectorTy()) {
        language_svec_t *types = ((language_datatype_t*)arg1.typ)->types;
        Value *answer = ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);
        Value *varg1 = emit_unbox(ctx, at, arg1, arg1.typ);
        Value *varg2 = emit_unbox(ctx, at, arg2, arg2.typ);
        for (size_t i = 0, l = language_svec_len(types); i < l; i++) {
            language_value_t *fldty = language_svecref(types, i);
            Value *subAns, *fld1, *fld2;
            fld1 = ctx.builder.CreateExtractElement(varg1, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), i)),
            fld2 = ctx.builder.CreateExtractElement(varg2, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), i)),
            subAns = emit_bits_compare(ctx,
                    mark_language_type(ctx, fld1, false, fldty),
                    mark_language_type(ctx, fld2, false, fldty));
            answer = ctx.builder.CreateAnd(answer, subAns);
        }
        return answer;
    }

    if (at->isAggregateType()) { // Struct or Array
        language_datatype_t *sty = (language_datatype_t*)arg1.typ;
        size_t sz = language_datatype_size(sty);
        if (sz > 512 && !sty->layout->flags.haspadding && sty->layout->flags.isbitsegal) {
            Value *varg1 = arg1.ispointer() ? data_pointer(ctx, arg1) :
                value_to_pointer(ctx, arg1).V;
            Value *varg2 = arg2.ispointer() ? data_pointer(ctx, arg2) :
                value_to_pointer(ctx, arg2).V;
            varg1 = emit_pointer_from_objref(ctx, varg1);
            varg2 = emit_pointer_from_objref(ctx, varg2);
            SmallVector<Value*, 0> gc_uses;
            // these roots may seem a bit overkill, but we want to make sure
            // that a!=b implies (a,)!=(b,) even if a and b are unused and
            // therefore could be freed and then the memory for a reused for b
            gc_uses.append(get_gc_roots_for(ctx, arg1));
            gc_uses.append(get_gc_roots_for(ctx, arg2));
            OperandBundleDef OpBundle("language_roots", gc_uses);
            auto answer = ctx.builder.CreateCall(prepare_call(memcmp_func), {
                        ctx.builder.CreateBitCast(varg1, getInt8PtrTy(ctx.builder.getContext())),
                        ctx.builder.CreateBitCast(varg2, getInt8PtrTy(ctx.builder.getContext())),
                        ConstantInt::get(ctx.types().T_size, sz) },
                    ArrayRef<OperandBundleDef>(&OpBundle, gc_uses.empty() ? 0 : 1));

            if (arg1.tbaa || arg2.tbaa) {
                language_aliasinfo_t ai;
                if (!arg1.tbaa) {
                    ai = language_aliasinfo_t::fromTBAA(ctx, arg2.tbaa);
                }
                else if (!arg2.tbaa) {
                    ai = language_aliasinfo_t::fromTBAA(ctx, arg1.tbaa);
                }
                else {
                    language_aliasinfo_t arg1_ai = language_aliasinfo_t::fromTBAA(ctx, arg1.tbaa);
                    language_aliasinfo_t arg2_ai = language_aliasinfo_t::fromTBAA(ctx, arg2.tbaa);
                    ai = arg1_ai.merge(arg2_ai);
                }
                ai.decorateInst(answer);
            }
            return ctx.builder.CreateICmpEQ(answer, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0));
        }
        else if (sz > 512 && language_struct_try_layout(sty) && sty->layout->flags.isbitsegal) {
            Type *TInt8 = getInt8Ty(ctx.builder.getContext());
            Type *TpInt8 = getInt8PtrTy(ctx.builder.getContext());
            Type *TInt1 = getInt1Ty(ctx.builder.getContext());
            Value *varg1 = arg1.ispointer() ? data_pointer(ctx, arg1) :
                value_to_pointer(ctx, arg1).V;
            Value *varg2 = arg2.ispointer() ? data_pointer(ctx, arg2) :
                value_to_pointer(ctx, arg2).V;
            varg1 = emit_pointer_from_objref(ctx, varg1);
            varg2 = emit_pointer_from_objref(ctx, varg2);
            varg1 = emit_bitcast(ctx, varg1, TpInt8);
            varg2 = emit_bitcast(ctx, varg2, TpInt8);

            // See above for why we want to do this
            SmallVector<Value*, 0> gc_uses;
            gc_uses.append(get_gc_roots_for(ctx, arg1));
            gc_uses.append(get_gc_roots_for(ctx, arg2));
            OperandBundleDef OpBundle("language_roots", gc_uses);

            Value *answer = nullptr;
            auto emit_desc = [&](egal_desc desc) {
                Value *ptr1 = varg1;
                Value *ptr2 = varg2;
                if (desc.offset != 0) {
                    ptr1 = ctx.builder.CreateConstInBoundsGEP1_32(TInt8, ptr1, desc.offset);
                    ptr2 = ctx.builder.CreateConstInBoundsGEP1_32(TInt8, ptr2, desc.offset);
                }

                Value *new_ptr1 = ptr1;
                Value *endptr1 = nullptr;
                BasicBlock *postBB = nullptr;
                BasicBlock *loopBB = nullptr;
                PHINode *answerphi = nullptr;
                if (desc.nrepeats != 1) {
                    // Set up loop
                    endptr1 = ctx.builder.CreateConstInBoundsGEP1_32(TInt8, ptr1, desc.nrepeats * (desc.data_bytes + desc.padding_bytes));;

                    BasicBlock *currBB = ctx.builder.GetInsertBlock();
                    loopBB = BasicBlock::Create(ctx.builder.getContext(), "egal_loop", ctx.f);
                    postBB = BasicBlock::Create(ctx.builder.getContext(), "post", ctx.f);
                    ctx.builder.CreateBr(loopBB);

                    ctx.builder.SetInsertPoint(loopBB);
                    answerphi = ctx.builder.CreatePHI(TInt1, 2);
                    answerphi->addIncoming(answer ? answer : ConstantInt::get(TInt1, 1), currBB);
                    answer = answerphi;

                    PHINode *itr1 = ctx.builder.CreatePHI(ptr1->getType(), 2);
                    PHINode *itr2 = ctx.builder.CreatePHI(ptr2->getType(), 2);

                    new_ptr1 = ctx.builder.CreateConstInBoundsGEP1_32(TInt8, itr1, desc.data_bytes + desc.padding_bytes);
                    itr1->addIncoming(ptr1, currBB);
                    itr1->addIncoming(new_ptr1, loopBB);

                    Value *new_ptr2 = ctx.builder.CreateConstInBoundsGEP1_32(TInt8, itr2, desc.data_bytes + desc.padding_bytes);
                    itr2->addIncoming(ptr2, currBB);
                    itr2->addIncoming(new_ptr2, loopBB);

                    ptr1 = itr1;
                    ptr2 = itr2;
                }

                // Emit memcmp. TODO: LLVM has a pass to expand this for additional
                // performance.
                Value *this_answer = ctx.builder.CreateCall(prepare_call(memcmp_func),
                    { ptr1,
                      ptr2,
                      ConstantInt::get(ctx.types().T_size, desc.data_bytes) },
                    ArrayRef<OperandBundleDef>(&OpBundle, gc_uses.empty() ? 0 : 1));
                this_answer = ctx.builder.CreateICmpEQ(this_answer, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0));
                answer = answer ? ctx.builder.CreateAnd(answer, this_answer) : this_answer;
                if (endptr1) {
                    answerphi->addIncoming(answer, loopBB);
                    Value *loopend = ctx.builder.CreateICmpEQ(new_ptr1, endptr1);
                    ctx.builder.CreateCondBr(loopend, postBB, loopBB);
                    ctx.builder.SetInsertPoint(postBB);
                }
            };
            egal_desc current_desc = {0};
            size_t trailing_data_bytes = emit_masked_bits_compare(emit_desc, sty, current_desc);
            assert(current_desc.nrepeats != 0);
            emit_desc(current_desc);
            if (trailing_data_bytes != 0) {
                current_desc.nrepeats = 1;
                current_desc.data_bytes = trailing_data_bytes;
                current_desc.padding_bytes = 0;
                emit_desc(current_desc);
            }
            return answer;
        }
        else {
            language_svec_t *types = sty->types;
            Value *answer = ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 1);
            for (size_t i = 0, l = language_svec_len(types); i < l; i++) {
                language_value_t *fldty = language_svecref(types, i);
                if (type_is_ghost(language_type_to_llvm(ctx, fldty)))
                    continue;
                Value *nullcheck1 = nullptr;
                Value *nullcheck2 = nullptr;
                auto fld1 = emit_getfield_knownidx(ctx, arg1, i, sty, language_memory_order_notatomic, &nullcheck1);
                auto fld2 = emit_getfield_knownidx(ctx, arg2, i, sty, language_memory_order_notatomic, &nullcheck2);
                Value *fld_answer;
                if (language_field_isptr(sty, i) && language_is_concrete_immutable(fldty)) {
                    // concrete immutables that are !isinlinealloc might be reference cycles
                    // issue #37872
                    fld_answer = emit_box_compare(ctx, fld1, fld2, nullcheck1, nullcheck2);
                }
                else {
                    fld_answer = emit_f_is(ctx, fld1, fld2, nullcheck1, nullcheck2);
                }
                answer = ctx.builder.CreateAnd(answer, fld_answer);
            }
            return answer;
        }
    }
    assert(0 && "what is this llvm type?");
    abort();
}

// emit code for is (===).
// If either `nullcheck1` or `nullcheck2` are non-NULL, they are pointer values
// representing the undef-ness of `arg1` and `arg2`.
// This can only happen when comparing two fields of the same time and the result should be
// true if both are NULL
// Like the runtime counterpart, this is codegen guaranteed to be non-allocating and to exclude safepoints
static Value *emit_f_is(language_codectx_t &ctx, const language_cgval_t &arg1, const language_cgval_t &arg2,
                        Value *nullcheck1, Value *nullcheck2)
{
    ++EmittedEgals;
    // handle simple static expressions with no side-effects
    if (arg1.constant && arg2.constant)
        return ConstantInt::get(getInt1Ty(ctx.builder.getContext()), language_egal(arg1.constant, arg2.constant));

    language_value_t *rt1 = arg1.typ;
    language_value_t *rt2 = arg2.typ;
    if (language_is_concrete_type(rt1) && language_is_concrete_type(rt2) && !language_is_kind(rt1) && !language_is_kind(rt2) && rt1 != rt2) {
        // disjoint concrete leaf types are never equal (quick test)
        return ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 0);
    }

    if (arg1.isghost || arg2.isghost || arg1.constant == language_bottom_type ||
        arg2.constant == language_bottom_type) {
        // comparing to a singleton object, special case for value `language_bottom_type`
        // since it is normalized to `::Type{Union{}}` instead...
        if (arg1.TIndex)
            return emit_nullcheck_guard(ctx, nullcheck1, [&] {
                return emit_exactly_isa(ctx, arg1, (language_datatype_t*)rt2); // rt2 is a singleton type
            });
        if (arg2.TIndex)
            return emit_nullcheck_guard(ctx, nullcheck2, [&] {
                return emit_exactly_isa(ctx, arg2, (language_datatype_t*)rt1); // rt1 is a singleton type
            });
        if (!(arg1.isboxed || arg1.constant) || !(arg2.isboxed || arg2.constant))
            // not TIndex && not boxed implies it is an unboxed value of a different type from this singleton
            // (which was probably caught above, but just to be safe, we repeat it here explicitly)
            return ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 0);
        Value *varg1 = arg1.constant ? literal_pointer_val(ctx, arg1.constant) : maybe_bitcast(ctx, arg1.Vboxed, ctx.types().T_pjlvalue);
        Value *varg2 = arg2.constant ? literal_pointer_val(ctx, arg2.constant) : maybe_bitcast(ctx, arg2.Vboxed, ctx.types().T_pjlvalue);
        // rooting these values isn't needed since we won't load this pointer
        // and we know at least one of them is a unique Singleton
        // which is already enough to ensure pointer uniqueness for this test
        // even if the other pointer managed to get garbage collected
        // TODO: use emit_pointer_from_objref instead, per comment above
        return ctx.builder.CreateICmpEQ(decay_derived(ctx, varg1), decay_derived(ctx, varg2));
    }

    if (language_type_intersection(rt1, rt2) == (language_value_t*)language_bottom_type) // types are disjoint (exhaustive test)
        return ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 0);

    bool justbits1 = language_is_concrete_immutable(rt1);
    bool justbits2 = language_is_concrete_immutable(rt2);
    if (justbits1 || justbits2) { // whether this type is unique'd by value
        return emit_nullcheck_guard2(ctx, nullcheck1, nullcheck2, [&] () -> Value* {
            language_datatype_t *typ = (language_datatype_t*)(justbits1 ? rt1 : rt2);
            if (typ == language_bool_type) { // aka language_pointer_egal
                // some optimizations for bool, since pointer comparison may be better
                if ((arg1.isboxed || arg1.constant) && (arg2.isboxed || arg2.constant)) { // aka have-fast-pointer
                    Value *varg1 = arg1.constant ? literal_pointer_val(ctx, arg1.constant) : maybe_bitcast(ctx, arg1.Vboxed, ctx.types().T_pjlvalue);
                    Value *varg2 = arg2.constant ? literal_pointer_val(ctx, arg2.constant) : maybe_bitcast(ctx, arg2.Vboxed, ctx.types().T_pjlvalue);
                    return ctx.builder.CreateICmpEQ(decay_derived(ctx, varg1), decay_derived(ctx, varg2));
                }
            }
            if (rt1 == rt2)
                return emit_bits_compare(ctx, arg1, arg2);
            Value *same_type = emit_exactly_isa(ctx, (justbits1 ? arg2 : arg1), typ);
            BasicBlock *currBB = ctx.builder.GetInsertBlock();
            BasicBlock *isaBB = BasicBlock::Create(ctx.builder.getContext(), "is", ctx.f);
            BasicBlock *postBB = BasicBlock::Create(ctx.builder.getContext(), "post_is", ctx.f);
            ctx.builder.CreateCondBr(same_type, isaBB, postBB);
            ctx.builder.SetInsertPoint(isaBB);
            Value *bitcmp = emit_bits_compare(ctx, language_cgval_t(arg1, (language_value_t*)typ, NULL),
                                              language_cgval_t(arg2, (language_value_t*)typ, NULL));
            isaBB = ctx.builder.GetInsertBlock(); // might have changed
            ctx.builder.CreateBr(postBB);
            ctx.builder.SetInsertPoint(postBB);
            PHINode *cmp = ctx.builder.CreatePHI(getInt1Ty(ctx.builder.getContext()), 2);
            cmp->addIncoming(ConstantInt::get(getInt1Ty(ctx.builder.getContext()), 0), currBB);
            cmp->addIncoming(bitcmp, isaBB);
            return cmp;
        });
    }

    // TODO: handle the case where arg1.typ is not exactly arg2.typ, or when
    // one of these isn't union, or when the union can be pointer
    if (arg1.TIndex && arg2.TIndex && language_egal(arg1.typ, arg2.typ) &&
        language_is_uniontype(arg1.typ) && is_uniontype_allunboxed(arg1.typ))
        return emit_nullcheck_guard2(ctx, nullcheck1, nullcheck2, [&] {
            return emit_bitsunion_compare(ctx, arg1, arg2);
        });

    return emit_box_compare(ctx, arg1, arg2, nullcheck1, nullcheck2);
}

static bool emit_f_opglobal(language_codectx_t &ctx, language_cgval_t *ret, language_value_t *f,
                            ArrayRef<language_cgval_t> argv, size_t nargs, const language_cgval_t *modifyop)
{
    bool issetglobal = f == language_builtin_setglobal;
    bool isreplaceglobal = f == language_builtin_replaceglobal;
    bool isswapglobal = f == language_builtin_swapglobal;
    bool ismodifyglobal = f == language_builtin_modifyglobal;
    bool issetglobalonce = f == language_builtin_setglobalonce;
    const language_cgval_t undefval;
    const language_cgval_t &mod = argv[1];
    const language_cgval_t &sym = argv[2];
    language_cgval_t val = argv[isreplaceglobal || ismodifyglobal ? 4 : 3];
    const language_cgval_t &cmp = isreplaceglobal || ismodifyglobal ? argv[3] : undefval;
    enum language_memory_order order = language_memory_order_release;
    const std::string fname = issetglobal ? "setglobal!" : isreplaceglobal ? "replaceglobal!" : isswapglobal ? "swapglobal!" : ismodifyglobal ? "modifyglobal!" : "setglobalonce!";
    if (nargs >= (isreplaceglobal || ismodifyglobal ? 5 : 4)) {
        const language_cgval_t &ord = argv[isreplaceglobal || ismodifyglobal ? 5 : 4];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        order = language_get_atomic_order((language_sym_t*)ord.constant, !issetglobal, true);
    }
    enum language_memory_order fail_order = order;
    if ((isreplaceglobal || issetglobalonce) && nargs == (isreplaceglobal ? 6 : 5)) {
        const language_cgval_t &ord = argv[isreplaceglobal ? 6 : 5];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        fail_order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
    }
    if (order == language_memory_order_invalid || fail_order == language_memory_order_invalid || fail_order > order) {
        emit_atomic_error(ctx, "invalid atomic ordering");
        *ret = language_cgval_t(); // unreachable
        return true;
    }

    if (order == language_memory_order_notatomic) {
        emit_atomic_error(ctx,
                issetglobal ? "setglobal!: module binding cannot be written non-atomically" :
                isreplaceglobal ? "replaceglobal!: module binding cannot be written non-atomically" :
                isswapglobal ? "swapglobal!: module binding cannot be written non-atomically" :
                ismodifyglobal ? "modifyglobal!: module binding cannot be written non-atomically" :
                "setglobalonce!: module binding cannot be written non-atomically");
        *ret = language_cgval_t(); // unreachable
        return true;
    }
    else if (fail_order == language_memory_order_notatomic) {
        emit_atomic_error(ctx,
                isreplaceglobal ? "replaceglobal!: module binding cannot be accessed non-atomically" :
                "setglobalonce!: module binding cannot be accessed non-atomically");
        *ret = language_cgval_t(); // unreachable
        return true;
    }

    if (sym.constant && language_is_symbol(sym.constant)) {
        if (mod.constant && language_is_module(mod.constant)) {
            *ret = emit_globalop(ctx, (language_module_t*)mod.constant, (language_sym_t*)sym.constant, val, cmp,
                                 get_llvm_atomic_order(order), get_llvm_atomic_order(fail_order),
                                 issetglobal,
                                 isreplaceglobal,
                                 isswapglobal,
                                 ismodifyglobal,
                                 issetglobalonce,
                                 modifyop);
            return true;
        }
    }

    return false;
}

static bool emit_f_opfield(language_codectx_t &ctx, language_cgval_t *ret, language_value_t *f,
                           ArrayRef<language_cgval_t> argv, size_t nargs, const language_cgval_t *modifyop)
{
    ++EmittedOpfields;
    bool issetfield = f == language_builtin_setfield;
    bool isreplacefield = f == language_builtin_replacefield;
    bool isswapfield = f == language_builtin_swapfield;
    bool ismodifyfield = f == language_builtin_modifyfield;
    bool issetfieldonce = f == language_builtin_setfieldonce;
    const language_cgval_t undefval;
    const language_cgval_t &obj = argv[1];
    const language_cgval_t &fld = argv[2];
    language_cgval_t val = argv[isreplacefield || ismodifyfield ? 4 : 3];
    const language_cgval_t &cmp = isreplacefield || ismodifyfield ? argv[3] : undefval;
    enum language_memory_order order = language_memory_order_notatomic;
    const std::string fname = issetfield ? "setfield!" : isreplacefield ? "replacefield!" : isswapfield ? "swapfield!" : ismodifyfield ? "modifyfield!" : "setfieldonce!";
    if (nargs >= (isreplacefield || ismodifyfield ? 5 : 4)) {
        const language_cgval_t &ord = argv[isreplacefield || ismodifyfield ? 5 : 4];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        order = language_get_atomic_order((language_sym_t*)ord.constant, !issetfield, true);
    }
    enum language_memory_order fail_order = order;
    if ((isreplacefield || issetfieldonce) && nargs == (isreplacefield ? 6 : 5)) {
        const language_cgval_t &ord = argv[isreplacefield ? 6 : 5];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        fail_order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
    }
    if (order == language_memory_order_invalid || fail_order == language_memory_order_invalid || fail_order > order) {
        emit_atomic_error(ctx, "invalid atomic ordering");
        *ret = language_cgval_t(); // unreachable
        return true;
    }

    language_datatype_t *uty = (language_datatype_t*)language_unwrap_unionall(obj.typ);
    if (language_is_datatype(uty) && language_struct_try_layout(uty)) {
        ssize_t idx = -1;
        if (fld.constant && language_is_symbol(fld.constant)) {
            idx = language_field_index(uty, (language_sym_t*)fld.constant, 0);
        }
        else if (fld.constant && fld.typ == (language_value_t*)language_long_type) {
            ssize_t i = language_unbox_long(fld.constant);
            if (i > 0 && i <= (ssize_t)language_datatype_nfields(uty))
                idx = i - 1;
        }
        if (idx != -1) {
            language_value_t *ft = language_field_type(uty, idx);
            if (!language_has_free_typevars(ft)) {
                if (!ismodifyfield) {
                    emit_typecheck(ctx, val, ft, fname);
                    val = update_language_type(ctx, val, ft);
                    if (val.typ == language_bottom_type)
                        return true;
                }
                // TODO: attempt better codegen for approximate types
                bool isboxed = language_field_isptr(uty, idx);
                bool isatomic = language_field_isatomic(uty, idx);
                bool needlock = isatomic && !isboxed && language_datatype_size(language_field_type(uty, idx)) > MAX_ATOMIC_SIZE;
                *ret = language_cgval_t();
                if (isatomic == (order == language_memory_order_notatomic)) {
                    emit_atomic_error(ctx,
                            issetfield ?
                            (isatomic ? "setfield!: atomic field cannot be written non-atomically"
                                      : "setfield!: non-atomic field cannot be written atomically") :
                            isreplacefield ?
                            (isatomic ? "replacefield!: atomic field cannot be written non-atomically"
                                      : "replacefield!: non-atomic field cannot be written atomically") :
                            isswapfield ?
                            (isatomic ? "swapfield!: atomic field cannot be written non-atomically"
                                      : "swapfield!: non-atomic field cannot be written atomically") :
                            ismodifyfield ?
                            (isatomic ? "modifyfield!: atomic field cannot be written non-atomically"
                                      : "modifyfield!: non-atomic field cannot be written atomically") :
                            (isatomic ? "setfieldonce!: atomic field cannot be written non-atomically"
                                      : "setfieldonce!: non-atomic field cannot be written atomically"));
                }
                else if (isatomic == (fail_order == language_memory_order_notatomic)) {
                    emit_atomic_error(ctx,
                            isreplacefield ?
                            (isatomic ? "replacefield!: atomic field cannot be accessed non-atomically"
                                      : "replacefield!: non-atomic field cannot be accessed atomically") :
                            (isatomic ? "setfieldonce!: atomic field cannot be accessed non-atomically"
                                      : "setfieldonce!: non-atomic field cannot be accessed atomically"));
                }
                else if (!uty->name->mutabl) {
                    std::string msg = fname + ": immutable struct of type "
                        + std::string(language_symbol_name(uty->name->name))
                        + " cannot be changed";
                    emit_error(ctx, msg);
                }
                else if (language_field_isconst(uty, idx)) {
                    std::string msg = fname + ": const field ."
                        + std::string(language_symbol_name((language_sym_t*)language_svecref(language_field_names(uty), idx)))
                        + " of type "
                        + std::string(language_symbol_name(uty->name->name))
                        + " cannot be changed";
                    emit_error(ctx, msg);
                }
                else {
                    assert(obj.isboxed);
                    *ret = emit_setfield(ctx, uty, obj, idx, val, cmp, true,
                            (needlock || order <= language_memory_order_notatomic)
                                ? AtomicOrdering::NotAtomic
                                : get_llvm_atomic_order(order),
                            (needlock || fail_order <= language_memory_order_notatomic)
                                ? AtomicOrdering::NotAtomic
                                : get_llvm_atomic_order(fail_order),
                            needlock ? boxed(ctx, obj) : nullptr,
                            issetfield, isreplacefield, isswapfield, ismodifyfield, issetfieldonce,
                            modifyop, fname);
                }
                return true;
            }
        }
    }
    return false;
}

static bool emit_f_opmemory(language_codectx_t &ctx, language_cgval_t *ret, language_value_t *f,
                            ArrayRef<language_cgval_t> argv, size_t nargs, const language_cgval_t *modifyop)
{
    bool issetmemory = f == language_builtin_memoryrefset;
    bool isreplacememory = f == language_builtin_memoryrefreplace;
    bool isswapmemory = f == language_builtin_memoryrefswap;
    bool ismodifymemory = f == language_builtin_memoryrefmodify;
    bool issetmemoryonce = f == language_builtin_memoryrefsetonce;

    const language_cgval_t undefval;
    const language_cgval_t &ref = argv[1];
    language_cgval_t val = argv[isreplacememory || ismodifymemory ? 3 : 2];
    language_value_t *mty_dt = language_unwrap_unionall(ref.typ);
    if (!language_is_genericmemoryref_type(mty_dt) || !language_is_concrete_type(mty_dt))
        return false;

    language_value_t *kind = language_tparam0(mty_dt);
    language_value_t *ety = language_tparam1(mty_dt);
    language_value_t *addrspace = language_tparam2(mty_dt); (void)addrspace; // TODO
    mty_dt = language_field_type_concrete((language_datatype_t*)mty_dt, 1);
    if (kind != (language_value_t*)language_not_atomic_sym && kind != (language_value_t*)language_atomic_sym)
        return false;

    const language_cgval_t &cmp = isreplacememory || ismodifymemory ? argv[2] : undefval;
    enum language_memory_order order = language_memory_order_notatomic;
    const std::string fname = issetmemory ? "memoryrefset!" : isreplacememory ? "memoryrefreplace!" : isswapmemory ? "memoryrefswap!" : ismodifymemory ? "memoryrefmodify!" : "memoryrefsetonce!";
    {
        const language_cgval_t &ord = argv[isreplacememory || ismodifymemory ? 4 : 3];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        order = language_get_atomic_order((language_sym_t*)ord.constant, !issetmemory, true);
    }
    enum language_memory_order fail_order = order;
    if (isreplacememory || issetmemoryonce) {
        const language_cgval_t &ord = argv[isreplacememory ? 5 : 4];
        emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
        if (!ord.constant)
            return false;
        fail_order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
    }
    if (order == language_memory_order_invalid || fail_order == language_memory_order_invalid || fail_order > order) {
        emit_atomic_error(ctx, "invalid atomic ordering");
        *ret = language_cgval_t(); // unreachable
        return true;
    }

    language_value_t *boundscheck = argv[nargs].constant;
    emit_typecheck(ctx, argv[nargs], (language_value_t*)language_bool_type, fname);
    const language_datatype_layout_t *layout = ((language_datatype_t*)mty_dt)->layout;
    bool isboxed = layout->flags.arrayelem_isboxed;
    bool isunion = layout->flags.arrayelem_isunion;
    bool isatomic = kind == (language_value_t*)language_atomic_sym;
    bool needlock = isatomic && layout->size > MAX_ATOMIC_SIZE;
    size_t elsz = layout->size;
    size_t al = layout->alignment;
    if (al > LANGUAGE_HEAP_ALIGNMENT)
        al = LANGUAGE_HEAP_ALIGNMENT;
    if (isatomic == (order == language_memory_order_notatomic)) {
        emit_atomic_error(ctx,
                issetmemory ?
                (isatomic ? "memoryrefset!: atomic memory cannot be written non-atomically"
                          : "memoryrefset!: non-atomic memory cannot be written atomically") :
                isreplacememory ?
                (isatomic ? "memoryrefreplace!: atomic memory cannot be written non-atomically"
                          : "memoryrefreplace!: non-atomic memory cannot be written atomically") :
                isswapmemory ?
                (isatomic ? "memoryrefswap!: atomic memory cannot be written non-atomically"
                          : "memoryrefswap!: non-atomic memory cannot be written atomically") :
                ismodifymemory ?
                (isatomic ? "memoryrefmodify!: atomic memory cannot be written non-atomically"
                          : "memoryrefmodify!: non-atomic memory cannot be written atomically") :
                (isatomic ? "memoryrefsetonce!: atomic memory cannot be written non-atomically"
                          : "memoryrefsetonce!: non-atomic memory cannot be written atomically"));
        *ret = language_cgval_t();
        return true;
    }
    else if (isatomic == (fail_order == language_memory_order_notatomic)) {
        emit_atomic_error(ctx,
                isreplacememory ?
                (isatomic ? "memoryrefreplace!: atomic memory cannot be accessed non-atomically"
                          : "memoryrefreplace!: non-atomic memory cannot be accessed atomically") :
                (isatomic ? "memoryrefsetonce!: atomic memory cannot be accessed non-atomically"
                          : "memoryrefsetonce!: non-atomic memory cannot be accessed atomically"));
        *ret = language_cgval_t();
        return true;
    }
    Value *mem = emit_memoryref_mem(ctx, ref, layout);
    Value *mlen = emit_genericmemorylen(ctx, mem, ref.typ);
    if (bounds_check_enabled(ctx, boundscheck)) {
        BasicBlock *failBB, *endBB;
        failBB = BasicBlock::Create(ctx.builder.getContext(), "oob");
        endBB = BasicBlock::Create(ctx.builder.getContext(), "load");
        ctx.builder.CreateCondBr(ctx.builder.CreateIsNull(mlen), failBB, endBB);
        failBB->insertInto(ctx.f);
        ctx.builder.SetInsertPoint(failBB);
        ctx.builder.CreateCall(prepare_call(jlboundserror_func), { mark_callee_rooted(ctx, mem), ConstantInt::get(ctx.types().T_size, 1) });
        ctx.builder.CreateUnreachable();
        endBB->insertInto(ctx.f);
        ctx.builder.SetInsertPoint(endBB);
    }
    if (!ismodifymemory) {
        emit_typecheck(ctx, val, ety, fname);
        val = update_language_type(ctx, val, ety);
        if (val.typ == language_bottom_type)
            return true;
    }
    AtomicOrdering Order = (needlock || order <= language_memory_order_notatomic)
                            ? AtomicOrdering::NotAtomic
                            : get_llvm_atomic_order(order);
    AtomicOrdering FailOrder = (needlock || fail_order <= language_memory_order_notatomic)
                        ? AtomicOrdering::NotAtomic
                        : get_llvm_atomic_order(fail_order);
    if (isunion) {
        assert(!isatomic && !needlock);
        Value *V = emit_memoryref_FCA(ctx, ref, layout);
        Value *idx0 = CreateSimplifiedExtractValue(ctx, V, 0);
        Value *mem = CreateSimplifiedExtractValue(ctx, V, 1);
        Value *data = emit_genericmemoryptr(ctx, mem, layout, AddressSpace::Loaded);
        Type *AT = ArrayType::get(IntegerType::get(ctx.builder.getContext(), 8 * al), (elsz + al - 1) / al);
        data = emit_bitcast(ctx, data, AT->getPointerTo());
        // compute tindex from val
        Value *ptindex;
        if (elsz == 0) {
            ptindex = data;
        }
        else {
            data = emit_bitcast(ctx, data, AT->getPointerTo());
            // isbits union selector bytes are stored after mem->length
            ptindex = ctx.builder.CreateInBoundsGEP(AT, data, mlen);
            data = ctx.builder.CreateInBoundsGEP(AT, data, idx0);
        }
        ptindex = emit_bitcast(ctx, ptindex, getInt8PtrTy(ctx.builder.getContext()));
        ptindex = ctx.builder.CreateInBoundsGEP(getInt8Ty(ctx.builder.getContext()), ptindex, idx0);
        *ret = union_store(ctx, data, ptindex, val, cmp, ety,
            ctx.tbaa().tbaa_arraybuf, ctx.tbaa().tbaa_arrayselbyte,
            Order, FailOrder,
            nullptr, issetmemory, isreplacememory, isswapmemory, ismodifymemory, issetmemoryonce,
            modifyop, fname);
    }
    else {
        Value *ptr = (layout->size == 0 ? nullptr : emit_memoryref_ptr(ctx, ref, layout));
        Value *lock = nullptr;
        bool maybenull = true;
        if (needlock) {
            assert(ptr);
            lock = ptr;
            // ptr += sizeof(lock);
            ptr = emit_bitcast(ctx, ptr, getInt8PtrTy(ctx.builder.getContext()));
            ptr = ctx.builder.CreateConstInBoundsGEP1_32(getInt8Ty(ctx.builder.getContext()), ptr, LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT));
        }
        Value *data_owner = NULL; // owner object against which the write barrier must check
        if (isboxed || layout->first_ptr >= 0) { // if elements are just bits, don't need a write barrier
            Value *V = emit_memoryref_FCA(ctx, ref, layout);
            data_owner = emit_genericmemoryowner(ctx, CreateSimplifiedExtractValue(ctx, V, 1));
        }
        *ret = typed_store(ctx,
                    ptr,
                    val, cmp, ety,
                    isboxed ? ctx.tbaa().tbaa_ptrarraybuf : ctx.tbaa().tbaa_arraybuf,
                    ctx.noalias().aliasscope.current,
                    data_owner,
                    isboxed,
                    Order,
                    FailOrder,
                    al,
                    lock,
                    issetmemory,
                    isreplacememory,
                    isswapmemory,
                    ismodifymemory,
                    issetmemoryonce,
                    maybenull,
                    modifyop,
                    fname,
                    nullptr,
                    nullptr);
    }
    return true;
}

static language_llvm_functions_t
    emit_function(
        orc::ThreadSafeModule &TSM,
        language_method_instance_t *lam,
        language_code_info_t *src,
        language_value_t *jlrettype,
        language_codegen_params_t &params,
        size_t min_world, size_t max_world);

static void emit_hasnofield_error_ifnot(language_codectx_t &ctx, Value *ok, language_sym_t *type, language_cgval_t name);

static bool emit_builtin_call(language_codectx_t &ctx, language_cgval_t *ret, language_value_t *f,
                              ArrayRef<language_cgval_t> argv, size_t nargs, language_value_t *rt,
                              language_expr_t *ex, bool is_promotable)
// returns true if the call has been handled
{
    ++EmittedBuiltinCalls;
    if (f == language_builtin_is && nargs == 2) {
        // emit comparison test
        Value *ans = emit_f_is(ctx, argv[1], argv[2]);
        *ret = mark_language_type(ctx, ans, false, language_bool_type);
        return true;
    }

    else if (f == language_builtin_typeof && nargs == 1) {
        const language_cgval_t &p = argv[1];
        if (p.constant)
            *ret = mark_language_const(ctx, language_typeof(p.constant));
        else if (language_is_concrete_type(p.typ))
            *ret = mark_language_const(ctx, p.typ);
        else
            *ret = mark_language_type(ctx, emit_typeof(ctx, p, false, false), true, language_datatype_type);
        return true;
    }

    else if (f == language_builtin_typeassert && nargs == 2) {
        const language_cgval_t &arg = argv[1];
        const language_cgval_t &ty = argv[2];
        if (language_is_type_type(ty.typ) && !language_has_free_typevars(ty.typ)) {
            language_value_t *tp0 = language_tparam0(ty.typ);
            emit_typecheck(ctx, arg, tp0, "typeassert");
            *ret = update_language_type(ctx, arg, tp0);
            return true;
        }
        if (language_subtype(ty.typ, (language_value_t*)language_type_type)) {
            Value *rt_arg = boxed(ctx, arg);
            Value *rt_ty = boxed(ctx, ty);
            ctx.builder.CreateCall(prepare_call(jltypeassert_func), {rt_arg, rt_ty});
            *ret = arg;
            return true;
        }
    }

    else if (f == language_builtin_isa && nargs == 2) {
        const language_cgval_t &arg = argv[1];
        const language_cgval_t &ty = argv[2];
        if (language_is_type_type(ty.typ) && !language_has_free_typevars(ty.typ)) {
            language_value_t *tp0 = language_tparam0(ty.typ);
            Value *isa_result = emit_isa(ctx, arg, tp0, Twine()).first;
            *ret = mark_language_type(ctx, isa_result, false, language_bool_type);
            return true;
        }
    }

    else if (f == language_builtin_issubtype && nargs == 2) {
        const language_cgval_t &ta = argv[1];
        const language_cgval_t &tb = argv[2];
        if (language_is_type_type(ta.typ) && !language_has_free_typevars(ta.typ) &&
            language_is_type_type(tb.typ) && !language_has_free_typevars(tb.typ)) {
            int issub = language_subtype(language_tparam0(ta.typ), language_tparam0(tb.typ));
            *ret = mark_language_type(ctx, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), issub), false, language_bool_type);
            return true;
        }
    }

    else if ((f == language_builtin__apply_iterate && nargs == 3) && ctx.vaSlot > 0) {
        // turn Core._apply_iterate(iter, f, Tuple) ==> f(Tuple...) using the jlcall calling convention if Tuple is the va allocation
        if (LoadInst *load = dyn_cast_or_null<LoadInst>(argv[3].V)) {
            if (load->getPointerOperand() == ctx.slots[ctx.vaSlot].boxroot && ctx.argArray) {
                Value *theF = boxed(ctx, argv[2]);
                Value *nva = emit_n_varargs(ctx);
#ifdef _P64
                nva = ctx.builder.CreateTrunc(nva, getInt32Ty(ctx.builder.getContext()));
#endif
                Value *theArgs = ctx.builder.CreateInBoundsGEP(ctx.types().T_prjlvalue, ctx.argArray, ConstantInt::get(ctx.types().T_size, ctx.nReqArgs));
                Value *r = ctx.builder.CreateCall(prepare_call(jlapplygeneric_func), { theF, theArgs, nva });
                *ret = mark_language_type(ctx, r, true, language_any_type);
                return true;
            }
        }
    }

    else if (f == language_builtin_tuple) {
        if (nargs == 0) {
            *ret = ghostValue(ctx, language_emptytuple_type);
            return true;
        }
        if (language_is_tuple_type(rt) && language_is_concrete_type(rt) && nargs == language_datatype_nfields(rt)) {
            *ret = emit_new_struct(ctx, rt, nargs, argv.drop_front(), is_promotable);
            return true;
        }
    }

    else if (f == language_builtin_throw && nargs == 1) {
        Value *arg1 = boxed(ctx, argv[1]);
        raise_exception(ctx, arg1);
        *ret = language_cgval_t();
        return true;
    }

    else if (f == language_builtin_memoryref && nargs == 1) {
        const language_cgval_t &mem = argv[1];
        language_datatype_t *mty_dt = (language_datatype_t*)language_unwrap_unionall(mem.typ);
        if (language_is_genericmemory_type(mty_dt) && language_is_concrete_type((language_value_t*)mty_dt)) {
            language_value_t *typ = language_apply_type((language_value_t*)language_genericmemoryref_type, language_svec_data(mty_dt->parameters), language_svec_len(mty_dt->parameters));
            const language_datatype_layout_t *layout = mty_dt->layout;
            *ret = _emit_memoryref(ctx, mem, layout, typ);
            return true;
        }
    }

    else if (f == language_builtin_memoryref && (nargs == 2 || nargs == 3)) {
        const language_cgval_t &ref = argv[1];
        language_value_t *mty_dt = language_unwrap_unionall(ref.typ);
        if (language_is_genericmemoryref_type(mty_dt) && language_is_concrete_type(mty_dt)) {
            mty_dt = language_field_type_concrete((language_datatype_t*)mty_dt, 1);
            const language_datatype_layout_t *layout = ((language_datatype_t*)mty_dt)->layout;
            language_value_t *boundscheck = nargs == 3 ? argv[3].constant : nullptr;
            if (nargs == 3)
                emit_typecheck(ctx, argv[3], (language_value_t*)language_bool_type, "memoryref");
            *ret = emit_memoryref(ctx, ref, argv[2], boundscheck, layout);
            return true;
        }
    }

    else if (f == language_builtin_memoryrefoffset && nargs == 1) {
        const language_cgval_t &ref = argv[1];
        language_value_t *mty_dt = language_unwrap_unionall(ref.typ);
        if (language_is_genericmemoryref_type(mty_dt) && language_is_concrete_type(mty_dt)) {
            mty_dt = language_field_type_concrete((language_datatype_t*)mty_dt, 1);
            const language_datatype_layout_t *layout = ((language_datatype_t*)mty_dt)->layout;
            *ret = emit_memoryref_offset(ctx, ref, layout);
            return true;
        }
    }

    else if (f == language_builtin_memoryrefget && nargs == 3) {
        const language_cgval_t &ref = argv[1];
        language_value_t *mty_dt = language_unwrap_unionall(ref.typ);
        if (language_is_genericmemoryref_type(mty_dt) && language_is_concrete_type(mty_dt)) {
            language_value_t *kind = language_tparam0(mty_dt);
            language_value_t *ety = language_tparam1(mty_dt);
            language_value_t *addrspace = language_tparam2(mty_dt); (void)addrspace; // TODO
            mty_dt = language_field_type_concrete((language_datatype_t*)mty_dt, 1);
            if (kind != (language_value_t*)language_not_atomic_sym && kind != (language_value_t*)language_atomic_sym)
                return false;
            enum language_memory_order order = language_memory_order_unspecified;
            const std::string fname = "memoryrefget";
            {
                const language_cgval_t &ord = argv[2];
                emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
                if (!ord.constant)
                    return false;
                order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
            }
            if (order == language_memory_order_invalid) {
                emit_atomic_error(ctx, "invalid atomic ordering");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            bool isatomic = kind == (language_value_t*)language_atomic_sym;
            if (!isatomic && order != language_memory_order_notatomic && order != language_memory_order_unspecified) {
                emit_atomic_error(ctx, "memoryrefget: non-atomic memory cannot be accessed atomically");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            if (isatomic && order == language_memory_order_notatomic) {
                emit_atomic_error(ctx, "memoryrefget: atomic memory cannot be accessed non-atomically");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            if (order == language_memory_order_unspecified) {
                order = isatomic ? language_memory_order_unordered : language_memory_order_notatomic;
            }
            language_value_t *boundscheck = argv[3].constant;
            emit_typecheck(ctx, argv[3], (language_value_t*)language_bool_type, "memoryref");
            const language_datatype_layout_t *layout = ((language_datatype_t*)mty_dt)->layout;
            Value *mem = emit_memoryref_mem(ctx, ref, layout);
            Value *mlen = emit_genericmemorylen(ctx, mem, ref.typ);
            if (bounds_check_enabled(ctx, boundscheck)) {
                BasicBlock *failBB, *endBB;
                failBB = BasicBlock::Create(ctx.builder.getContext(), "oob");
                endBB = BasicBlock::Create(ctx.builder.getContext(), "load");
                ctx.builder.CreateCondBr(ctx.builder.CreateIsNull(mlen), failBB, endBB);
                failBB->insertInto(ctx.f);
                ctx.builder.SetInsertPoint(failBB);
                ctx.builder.CreateCall(prepare_call(jlboundserror_func), { mark_callee_rooted(ctx, mem), ConstantInt::get(ctx.types().T_size, 1) });
                ctx.builder.CreateUnreachable();
                endBB->insertInto(ctx.f);
                ctx.builder.SetInsertPoint(endBB);
            }
            bool isboxed = layout->flags.arrayelem_isboxed;
            bool isunion = layout->flags.arrayelem_isunion;
            size_t elsz = layout->size;
            size_t al = layout->alignment;
            if (al > LANGUAGE_HEAP_ALIGNMENT)
                al = LANGUAGE_HEAP_ALIGNMENT;
            bool needlock = isatomic && !isboxed && elsz > MAX_ATOMIC_SIZE;
            AtomicOrdering Order = (needlock || order <= language_memory_order_notatomic)
                                    ? (isboxed ? AtomicOrdering::Unordered : AtomicOrdering::NotAtomic)
                                    : get_llvm_atomic_order(order);
            bool maybenull = true;
            if (!isboxed && !isunion && elsz == 0) {
                assert(language_is_datatype(ety) && language_is_datatype_singleton((language_datatype_t*)ety));
                *ret = ghostValue(ctx, ety);
                if (isStrongerThanMonotonic(Order))
                    ctx.builder.CreateFence(Order);
            }
            else if (isunion) {
                assert(!isatomic && !needlock);
                Value *V = emit_memoryref_FCA(ctx, ref, layout);
                Value *idx0 = CreateSimplifiedExtractValue(ctx, V, 0);
                Value *mem = CreateSimplifiedExtractValue(ctx, V, 1);
                Value *data = emit_genericmemoryptr(ctx, mem, layout, AddressSpace::Loaded);
                Value *ptindex;
                if (elsz == 0) {
                    ptindex = data;
                }
                else {
                    Type *AT = ArrayType::get(IntegerType::get(ctx.builder.getContext(), 8 * al), (elsz + al - 1) / al);
                    data = emit_bitcast(ctx, data, AT->getPointerTo());
                    // isbits union selector bytes are stored after mem->length bytes
                    ptindex = ctx.builder.CreateInBoundsGEP(AT, data, mlen);
                    data = ctx.builder.CreateInBoundsGEP(AT, data, idx0);
                }
                ptindex = emit_bitcast(ctx, ptindex, getInt8PtrTy(ctx.builder.getContext()));
                ptindex = ctx.builder.CreateInBoundsGEP(getInt8Ty(ctx.builder.getContext()), ptindex, idx0);
                size_t elsz_c = 0, al_c = 0;
                int union_max = language_islayout_inline(ety, &elsz_c, &al_c);
                assert(union_max && LLT_ALIGN(elsz_c, al_c) == elsz && al_c == al);
                *ret = emit_unionload(ctx, data, ptindex, ety, elsz_c, al, ctx.tbaa().tbaa_arraybuf, true, union_max, ctx.tbaa().tbaa_arrayselbyte);
            }
            else {
                Value *ptr = (layout->size == 0 ? nullptr : emit_memoryref_ptr(ctx, ref, layout));
                Value *lock = nullptr;
                if (needlock) {
                    assert(ptr);
                    lock = ptr;
                    // ptr += sizeof(lock);
                    ptr = emit_bitcast(ctx, ptr, getInt8PtrTy(ctx.builder.getContext()));
                    ptr = ctx.builder.CreateConstInBoundsGEP1_32(getInt8Ty(ctx.builder.getContext()), ptr, LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT));
                    emit_lockstate_value(ctx, lock, true);
                }
                *ret = typed_load(ctx, ptr, nullptr, ety,
                        isboxed ? ctx.tbaa().tbaa_ptrarraybuf : ctx.tbaa().tbaa_arraybuf,
                        ctx.noalias().aliasscope.current,
                        isboxed, Order, maybenull, al);
                if (needlock) {
                    emit_lockstate_value(ctx, lock, false);
                }
            }
            return true;
        }
    }

    else if ((f == language_builtin_memoryrefset && nargs == 4) ||
             (f == language_builtin_memoryrefswap && nargs == 4) ||
             (f == language_builtin_memoryrefreplace && nargs == 6) ||
             (f == language_builtin_memoryrefmodify && nargs == 5) ||
             (f == language_builtin_memoryrefsetonce && nargs == 5)) {
        return emit_f_opmemory(ctx, ret, f, argv, nargs, nullptr);
    }


    else if (f == language_builtin_memoryref_isassigned && nargs == 3) {
        const language_cgval_t &ref = argv[1];
        language_value_t *mty_dt = language_unwrap_unionall(ref.typ);
        if (language_is_genericmemoryref_type(mty_dt) && language_is_concrete_type(mty_dt)) {
            language_value_t *kind = language_tparam0(mty_dt);
            mty_dt = language_field_type_concrete((language_datatype_t*)mty_dt, 1);
            if (kind != (language_value_t*)language_not_atomic_sym && kind != (language_value_t*)language_atomic_sym)
                return false;
            enum language_memory_order order = language_memory_order_unspecified;
            const std::string fname = "memoryref_isassigned";
            {
                const language_cgval_t &ord = argv[2];
                emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, fname);
                if (!ord.constant)
                    return false;
                order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
            }
            if (order == language_memory_order_invalid) {
                emit_atomic_error(ctx, "invalid atomic ordering");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            bool isatomic = kind == (language_value_t*)language_atomic_sym;
            if (!isatomic && order != language_memory_order_notatomic && order != language_memory_order_unspecified) {
                emit_atomic_error(ctx, "memoryref_isassigned: non-atomic memory cannot be accessed atomically");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            if (isatomic && order == language_memory_order_notatomic) {
                emit_atomic_error(ctx, "memoryref_isassigned: atomic memory cannot be accessed non-atomically");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            if (order == language_memory_order_unspecified) {
                order = isatomic ? language_memory_order_unordered : language_memory_order_notatomic;
            }
            language_value_t *boundscheck = argv[3].constant;
            emit_typecheck(ctx, argv[3], (language_value_t*)language_bool_type, fname);
            const language_datatype_layout_t *layout = ((language_datatype_t*)mty_dt)->layout;
            Value *mem = emit_memoryref_mem(ctx, ref, layout);
            Value *mlen = emit_genericmemorylen(ctx, mem, ref.typ);
            Value *oob = bounds_check_enabled(ctx, boundscheck) ? ctx.builder.CreateIsNull(mlen) : nullptr;
            bool isboxed = layout->flags.arrayelem_isboxed;
            if (isboxed || layout->first_ptr >= 0) {
                bool needlock = isatomic && !isboxed && layout->size > MAX_ATOMIC_SIZE;
                AtomicOrdering Order = (needlock || order <= language_memory_order_notatomic)
                                        ? (isboxed ? AtomicOrdering::Unordered : AtomicOrdering::NotAtomic)
                                        : get_llvm_atomic_order(order);
                PHINode *result = nullptr;
                if (oob) {
                    BasicBlock *passBB, *endBB, *fromBB;
                    passBB = BasicBlock::Create(ctx.builder.getContext(), "load");
                    endBB = BasicBlock::Create(ctx.builder.getContext(), "oob");

                    passBB->insertInto(ctx.f);
                    endBB->insertInto(ctx.f);
                    fromBB = ctx.builder.CreateCondBr(oob, endBB, passBB)->getParent();
                    ctx.builder.SetInsertPoint(endBB);
                    result = ctx.builder.CreatePHI(getInt1Ty(ctx.builder.getContext()), 2);
                    result->addIncoming(ConstantInt::get(result->getType(), 0), fromBB);
                    setName(ctx.emission_context, result, "arraysize");
                    ctx.builder.SetInsertPoint(passBB);
                }
                Value *elem = emit_memoryref_ptr(ctx, ref, layout);
                if (needlock) {
                    // n.b. no actual lock acquire needed, as the check itself only needs to load a single pointer and check for null
                    // elem += sizeof(lock);
                    elem = emit_bitcast(ctx, elem, getInt8PtrTy(ctx.builder.getContext()));
                    elem = ctx.builder.CreateConstInBoundsGEP1_32(getInt8Ty(ctx.builder.getContext()), elem, LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT));
                }
                elem = emit_bitcast(ctx, elem, ctx.types().T_pprjlvalue);
                if (!isboxed)
                    elem = ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, elem, layout->first_ptr);
                // emit this using the same type as language_builtin_memoryrefget
                // so that LLVM may be able to load-load forward them and fold the result
                auto tbaa = isboxed ? ctx.tbaa().tbaa_ptrarraybuf : ctx.tbaa().tbaa_arraybuf;
                language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, tbaa);
                LoadInst *fldv = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, elem, ctx.types().alignof_ptr);
                fldv->setOrdering(Order);
                ai.decorateInst(fldv);
                Value *isdef = ctx.builder.CreateIsNotNull(fldv);
                setName(ctx.emission_context, isdef, fname);
                if (oob) {
                    assert(result);
                    result->addIncoming(isdef, ctx.builder.CreateBr(result->getParent())->getParent());
                    ctx.builder.SetInsertPoint(result->getParent());
                    isdef = result;
                }
                *ret = mark_language_type(ctx, isdef, false, language_bool_type);
            }
            else if (oob) {
                Value *isdef = ctx.builder.CreateNot(oob);
                *ret = mark_language_type(ctx, isdef, false, language_bool_type);
            }
            else {
                *ret = mark_language_const(ctx, language_true);
            }
            return true;
        }
    }


    else if (f == language_builtin_getfield && (nargs == 2 || nargs == 3 || nargs == 4)) {
        const language_cgval_t &obj = argv[1];
        const language_cgval_t &fld = argv[2];
        enum language_memory_order order = language_memory_order_unspecified;
        language_value_t *boundscheck = language_true;

        if (nargs == 4) {
            const language_cgval_t &ord = argv[3];
            const language_cgval_t &inb = argv[4];
            emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, "getfield");
            emit_typecheck(ctx, inb, (language_value_t*)language_bool_type, "getfield");
            if (!ord.constant)
                return false;
            order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
            if (inb.constant == language_false)
                boundscheck = language_false;
        }
        else if (nargs == 3) {
            const language_cgval_t &arg3 = argv[3];
            if (arg3.constant && language_is_symbol(arg3.constant))
                order = language_get_atomic_order((language_sym_t*)arg3.constant, true, false);
            else if (arg3.constant == language_false)
                boundscheck = language_false;
            else if (arg3.typ != (language_value_t*)language_bool_type)
                return false;
        }
        if (order == language_memory_order_invalid) {
            emit_atomic_error(ctx, "invalid atomic ordering");
            *ret = language_cgval_t(); // unreachable
            return true;
        }

        language_datatype_t *utt = (language_datatype_t*)language_unwrap_unionall(obj.typ);
        if (language_is_type_type((language_value_t*)utt) && language_is_concrete_type(language_tparam0(utt)))
            utt = (language_datatype_t*)language_typeof(language_tparam0(utt));

        if (fld.constant && language_is_symbol(fld.constant)) {
            language_sym_t *name = (language_sym_t*)fld.constant;
            if (obj.constant && language_is_module(obj.constant)) {
                *ret = emit_globalref(ctx, (language_module_t*)obj.constant, name, order == language_memory_order_unspecified ? AtomicOrdering::Unordered : get_llvm_atomic_order(order));
                return true;
            }

            if (language_is_datatype(utt) && language_struct_try_layout(utt)) {
                ssize_t idx = language_field_index(utt, name, 0);
                if (idx != -1 && !language_has_free_typevars(language_field_type(utt, idx))) {
                    *ret = emit_getfield_knownidx(ctx, obj, idx, utt, order);
                    return true;
                }
            }
        }
        else if (fld.typ == (language_value_t*)language_long_type) {
            if (ctx.vaSlot > 0) {
                // optimize VA tuple
                if (LoadInst *load = dyn_cast_or_null<LoadInst>(obj.V)) {
                    if (load->getPointerOperand() == ctx.slots[ctx.vaSlot].boxroot && ctx.argArray) {
                        Value *valen = emit_n_varargs(ctx);
                        language_cgval_t va_ary( // fake instantiation of a cgval, in order to call emit_bounds_check (it only checks the `.V` field)
                                ctx.builder.CreateInBoundsGEP(ctx.types().T_prjlvalue, ctx.argArray, ConstantInt::get(ctx.types().T_size, ctx.nReqArgs)),
                                NULL, NULL);
                        Value *idx = emit_unbox(ctx, ctx.types().T_size, fld, (language_value_t*)language_long_type);
                        idx = emit_bounds_check(ctx, va_ary, NULL, idx, valen, boundscheck);
                        idx = ctx.builder.CreateAdd(idx, ConstantInt::get(ctx.types().T_size, ctx.nReqArgs));
                        Instruction *v = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, ctx.builder.CreateInBoundsGEP(ctx.types().T_prjlvalue, ctx.argArray, idx), Align(sizeof(void*)));
                        setName(ctx.emission_context, v, "getfield");
                        // if we know the result type of this load, we will mark that information here too
                        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_value);
                        ai.decorateInst(maybe_mark_load_dereferenceable(v, false, rt));
                        *ret = mark_language_type(ctx, v, /*boxed*/ true, rt);
                        return true;
                    }
                }
            }

            if (language_is_datatype(utt)) {
                if (language_struct_try_layout(utt)) {
                    size_t nfields = language_datatype_nfields(utt);
                    // integer index
                    size_t idx;
                    if (fld.constant && (idx = language_unbox_long(fld.constant) - 1) < nfields) {
                        if (!language_has_free_typevars(language_field_type(utt, idx))) {
                            // known index
                            *ret = emit_getfield_knownidx(ctx, obj, idx, utt, order);
                            return true;
                        }
                    }
                    else {
                        // unknown index
                        Value *vidx = emit_unbox(ctx, ctx.types().T_size, fld, (language_value_t*)language_long_type);
                        if (emit_getfield_unknownidx(ctx, ret, obj, vidx, utt, boundscheck, order)) {
                            return true;
                        }
                    }
                }
                Value *vidx = emit_unbox(ctx, ctx.types().T_size, fld, (language_value_t*)language_long_type);
                if (language_is_tuple_type(utt) && is_tupletype_homogeneous(utt->parameters, true)) {
                    // For tuples, we can emit code even if we don't know the exact
                    // type (e.g. because we don't know the length). This is possible
                    // as long as we know that all elements are of the same (leaf) type.
                    if (obj.ispointer()) {
                        if (order != language_memory_order_notatomic && order != language_memory_order_unspecified) {
                            emit_atomic_error(ctx, "getfield: non-atomic field cannot be accessed atomically");
                            *ret = language_cgval_t(); // unreachable
                            return true;
                        }
                        // Determine which was the type that was homogeneous
                        language_value_t *jt = language_tparam0(utt);
                        if (language_is_vararg(jt))
                            jt = language_unwrap_vararg(jt);
                        assert(language_is_datatype(jt));
                        // This is not necessary for correctness, but allows to omit
                        // the extra code for getting the length of the tuple
                        if (!bounds_check_enabled(ctx, boundscheck)) {
                            vidx = ctx.builder.CreateSub(vidx, ConstantInt::get(ctx.types().T_size, 1));
                        }
                        else {
                            vidx = emit_bounds_check(ctx, obj, (language_value_t*)obj.typ, vidx,
                                emit_datatype_nfields(ctx, emit_typeof(ctx, obj, false, false)),
                                language_true);
                        }
                        bool isboxed = !language_datatype_isinlinealloc((language_datatype_t*)jt, 0);
                        Value *ptr = data_pointer(ctx, obj);
                        *ret = typed_load(ctx, ptr, vidx,
                                isboxed ? (language_value_t*)language_any_type : jt,
                                obj.tbaa, nullptr, isboxed, AtomicOrdering::NotAtomic, false);
                        return true;
                    }
                }

                // Unknown object, but field known to be integer
                vidx = ctx.builder.CreateSub(vidx, ConstantInt::get(ctx.types().T_size, 1));
                Value *fld_val = ctx.builder.CreateCall(prepare_call(jlgetnthfieldchecked_func), { boxed(ctx, obj), vidx }, "getfield");
                *ret = mark_language_type(ctx, fld_val, true, language_any_type);
                return true;
            }
        }
        else if (fld.typ == (language_value_t*)language_symbol_type) { // Known type but unknown symbol
            if (language_is_datatype(utt) && (utt != language_module_type) && language_struct_try_layout(utt)) {
                if ((language_datatype_nfields(utt) == 1 && !language_is_namedtuple_type(utt) && !language_is_tuple_type(utt))) {
                    language_svec_t *fn = language_field_names(utt);
                    assert(language_svec_len(fn) == 1);
                    Value *typ_sym = literal_pointer_val(ctx, language_svecref(fn, 0));
                    Value *cond = ctx.builder.CreateICmpEQ(mark_callee_rooted(ctx, typ_sym), mark_callee_rooted(ctx, boxed(ctx, fld)));
                    emit_hasnofield_error_ifnot(ctx, cond, utt->name->name, fld);
                    *ret = emit_getfield_knownidx(ctx, obj, 0, utt, order);
                    return true;
                }
                else {
                    Value *index = ctx.builder.CreateCall(prepare_call(jlfieldindex_func),
                            {emit_typeof(ctx, obj, false, false), boxed(ctx, fld), ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0)});
                    Value *cond = ctx.builder.CreateICmpNE(index, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), -1));
                    emit_hasnofield_error_ifnot(ctx, cond, utt->name->name, fld);
                    Value *idx2 = ctx.builder.CreateAdd(ctx.builder.CreateIntCast(index, ctx.types().T_size, false), ConstantInt::get(ctx.types().T_size, 1)); // getfield_unknown is 1 based
                    if (emit_getfield_unknownidx(ctx, ret, obj, idx2, utt, language_false, order))
                        return true;
                }
            }
        }
        return false;
    }

    else if (f == language_builtin_getglobal && (nargs == 2 || nargs == 3)) {
        const language_cgval_t &mod = argv[1];
        const language_cgval_t &sym = argv[2];
        enum language_memory_order order = language_memory_order_unspecified;

        if (nargs == 3) {
            const language_cgval_t &arg3 = argv[3];
            if (arg3.constant && language_is_symbol(arg3.constant))
                order = language_get_atomic_order((language_sym_t*)arg3.constant, true, false);
            else
                return false;
        }
        else
            order = language_memory_order_monotonic;

        if (order == language_memory_order_invalid || order == language_memory_order_notatomic) {
            emit_atomic_error(ctx, order == language_memory_order_invalid ? "invalid atomic ordering" : "getglobal: module binding cannot be read non-atomically");
            *ret = language_cgval_t(); // unreachable
            return true;
        }

        if (sym.constant && language_is_symbol(sym.constant)) {
            language_sym_t *name = (language_sym_t*)sym.constant;
            if (mod.constant && language_is_module(mod.constant)) {
                *ret = emit_globalref(ctx, (language_module_t*)mod.constant, name, get_llvm_atomic_order(order));
                return true;
            }
        }

        return false;
    }

    else if ((f == language_builtin_setglobal && (nargs == 3 || nargs == 4)) ||
             (f == language_builtin_swapglobal && (nargs == 3 || nargs == 4)) ||
             (f == language_builtin_replaceglobal && (nargs == 4 || nargs == 5 || nargs == 6)) ||
             (f == language_builtin_modifyglobal && (nargs == 4 || nargs == 5)) ||
             (f == language_builtin_setglobalonce && (nargs == 3 || nargs == 4 || nargs == 5))) {
        return emit_f_opglobal(ctx, ret, f, argv, nargs, nullptr);
    }

    else if ((f == language_builtin_setfield && (nargs == 3 || nargs == 4)) ||
             (f == language_builtin_swapfield && (nargs == 3 || nargs == 4)) ||
             (f == language_builtin_replacefield && (nargs == 4 || nargs == 5 || nargs == 6)) ||
             (f == language_builtin_modifyfield && (nargs == 4 || nargs == 5)) ||
             (f == language_builtin_setfieldonce && (nargs == 3 || nargs == 4 || nargs == 5))) {
        return emit_f_opfield(ctx, ret, f, argv, nargs, nullptr);
    }

    else if (f == language_builtin_nfields && nargs == 1) {
        const language_cgval_t &obj = argv[1];
        if (ctx.vaSlot > 0) {
            // optimize VA tuple
            if (LoadInst *load = dyn_cast_or_null<LoadInst>(obj.V)) {
                if (load->getPointerOperand() == ctx.slots[ctx.vaSlot].boxroot) {
                    *ret = mark_language_type(ctx, emit_n_varargs(ctx), false, language_long_type);
                    return true;
                }
            }
        }
        ssize_t nf = -1;
        if (obj.constant) {
            nf = language_datatype_nfields(language_typeof(obj.constant));
        }
        else if (language_is_type_type(obj.typ)) {
            language_value_t *tp0 = language_tparam0(obj.typ);
            if (language_is_datatype(tp0) && language_is_datatype_singleton((language_datatype_t*)tp0))
                nf = language_datatype_nfields((language_value_t*)language_datatype_type);
        }
        else if (language_is_concrete_type(obj.typ)) {
            nf = language_datatype_nfields(obj.typ);
        }
        Value *sz;
        if (nf != -1)
            sz = ConstantInt::get(ctx.types().T_size, nf);
        else
            sz = emit_datatype_nfields(ctx, emit_typeof(ctx, obj, false, false));
        *ret = mark_language_type(ctx, sz, false, language_long_type);
        return true;
    }

    else if (f == language_builtin_fieldtype && (nargs == 2 || nargs == 3)) {
        const language_cgval_t &typ = argv[1];
        const language_cgval_t &fld = argv[2];
        if ((language_is_type_type(typ.typ) && language_is_concrete_type(language_tparam0(typ.typ))) ||
                (typ.constant && language_is_concrete_type(typ.constant))) {
            if (fld.typ == (language_value_t*)language_long_type) {
                assert(typ.isboxed);
                Value *tyv = boxed(ctx, typ);
                Value *types_svec = emit_datatype_types(ctx, tyv);
                Value *types_len = emit_datatype_nfields(ctx, tyv);
                Value *idx = emit_unbox(ctx, ctx.types().T_size, fld, (language_value_t*)language_long_type);
                language_value_t *boundscheck = (nargs == 3 ? argv[3].constant : language_true);
                if (nargs == 3)
                    emit_typecheck(ctx, argv[3], (language_value_t*)language_bool_type, "fieldtype");
                emit_bounds_check(ctx, typ, (language_value_t*)language_datatype_type, idx, types_len, boundscheck);
                Value *fieldtyp_p = ctx.builder.CreateInBoundsGEP(ctx.types().T_prjlvalue, decay_derived(ctx, emit_bitcast(ctx, types_svec, ctx.types().T_pprjlvalue)), idx);
                language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
                Value *fieldtyp = ai.decorateInst(ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, fieldtyp_p, Align(sizeof(void*))));
                setName(ctx.emission_context, fieldtyp, "fieldtype");
                *ret = mark_language_type(ctx, fieldtyp, true, (language_value_t*)language_type_type);
                return true;
            }
        }
    }

    else if (f == language_builtin_sizeof && nargs == 1) {
        const language_cgval_t &obj = argv[1];
        language_datatype_t *sty = (language_datatype_t*)language_unwrap_unionall(obj.typ);
        assert(language_string_type->name->mutabl);
        if (sty == language_string_type || sty == language_simplevector_type) {
            if (obj.constant) {
                size_t sz;
                if (sty == language_string_type) {
                    sz = language_string_len(obj.constant);
                }
                else {
                    sz = (1 + language_svec_len(obj.constant)) * sizeof(void*);
                }
                *ret = mark_language_type(ctx, ConstantInt::get(ctx.types().T_size, sz), false, language_long_type);
                return true;
            }
            // String and SimpleVector's length fields have the same layout
            auto ptr = emit_bitcast(ctx, boxed(ctx, obj), ctx.types().T_size->getPointerTo());
            language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
            Value *len = ai.decorateInst(ctx.builder.CreateAlignedLoad(ctx.types().T_size, ptr, ctx.types().alignof_ptr));
            MDBuilder MDB(ctx.builder.getContext());
            if (sty == language_simplevector_type) {
                auto rng = MDB.createRange(
                    Constant::getNullValue(ctx.types().T_size), ConstantInt::get(ctx.types().T_size, INTPTR_MAX / sizeof(void*) - 1));
                cast<LoadInst>(len)->setMetadata(LLVMContext::MD_range, rng);
                len = ctx.builder.CreateMul(len, ConstantInt::get(ctx.types().T_size, sizeof(void*)));
                len = ctx.builder.CreateAdd(len, ConstantInt::get(ctx.types().T_size, sizeof(void*)));
            }
            else {
                auto rng = MDB.createRange(Constant::getNullValue(ctx.types().T_size), ConstantInt::get(ctx.types().T_size, INTPTR_MAX));
                cast<LoadInst>(len)->setMetadata(LLVMContext::MD_range, rng);
            }
            setName(ctx.emission_context, len, "sizeof");
            *ret = mark_language_type(ctx, len, false, language_long_type);
            return true;
        }
        else if (language_is_genericmemory_type(sty)) {
            Value *v = boxed(ctx, obj);
            auto len = emit_genericmemorylen(ctx, v, (language_value_t*)sty);
            auto elsize = emit_genericmemoryelsize(ctx, v, obj.typ, true);
            *ret = mark_language_type(ctx, ctx.builder.CreateMul(len, elsize), false, language_long_type);
            return true;
        }
    }

    else if (f == language_builtin_apply_type && nargs > 0) {
        if (language_is_method(ctx.linfo->def.method)) {
            // don't bother codegen constant-folding for toplevel.
            language_value_t *ty = static_apply_type(ctx, argv, nargs + 1);
            if (ty != NULL) {
                LANGUAGE_GC_PUSH1(&ty);
                ty = language_ensure_rooted(ctx, ty);
                LANGUAGE_GC_POP();
                *ret = mark_language_const(ctx, ty);
                return true;
            }
        }
    }

    else if (f == language_builtin_isdefined && (nargs == 2 || nargs == 3)) {
        const language_cgval_t &obj = argv[1];
        const language_cgval_t &fld = argv[2];
        language_datatype_t *stt = (language_datatype_t*)obj.typ;
        ssize_t fieldidx = -1;
        if (language_is_type_type((language_value_t*)stt)) {
            // the representation type of Type{T} is either typeof(T), or unknown
            // TODO: could use `issingletontype` predicate here, providing better type knowledge
            // than only handling DataType
            if (language_is_concrete_type(language_tparam0(stt)))
                stt = (language_datatype_t*)language_typeof(language_tparam0(stt));
            else
                return false;
        }
        if (!language_is_concrete_type((language_value_t*)stt) || language_is_array_type(stt) ||
            stt == language_module_type) { // TODO: use ->layout here instead of concrete_type
            goto isdefined_unknown_idx;
        }
        assert(language_is_datatype(stt));

        if (fld.constant && language_is_symbol(fld.constant)) {
            language_sym_t *sym = (language_sym_t*)fld.constant;
            fieldidx = language_field_index(stt, sym, 0);
        }
        else if (fld.constant && fld.typ == (language_value_t*)language_long_type) {
            fieldidx = language_unbox_long(fld.constant) - 1;
        }
        else {
isdefined_unknown_idx:
            if (nargs == 3 || fld.typ != (language_value_t*)language_long_type)
                return false;
            Value *vidx = emit_unbox(ctx, ctx.types().T_size, fld, (language_value_t*)language_long_type);
            vidx = ctx.builder.CreateSub(vidx, ConstantInt::get(ctx.types().T_size, 1));
            Value *isd = ctx.builder.CreateCall(prepare_call(jlfieldisdefinedchecked_func), { boxed(ctx, obj), vidx });
            isd = ctx.builder.CreateTrunc(isd, getInt8Ty(ctx.builder.getContext()));
            *ret = mark_language_type(ctx, isd, false, language_bool_type);
            return true;
        }
        enum language_memory_order order = language_memory_order_unspecified;
        if (nargs == 3) {
            const language_cgval_t &ord = argv[3];
            emit_typecheck(ctx, ord, (language_value_t*)language_symbol_type, "isdefined");
            if (!ord.constant)
                return false;
            order = language_get_atomic_order((language_sym_t*)ord.constant, true, false);
        }
        if (order == language_memory_order_invalid) {
            emit_atomic_error(ctx, "invalid atomic ordering");
            *ret = language_cgval_t(); // unreachable
            return true;
        }
        ssize_t nf = language_datatype_nfields(stt);
        if (fieldidx < 0 || fieldidx >= nf) {
            if (order != language_memory_order_unspecified) {
                emit_atomic_error(ctx, "isdefined: atomic ordering cannot be specified for nonexistent field");
                *ret = language_cgval_t(); // unreachable
                return true;
            }
            *ret = mark_language_const(ctx, language_false);
            return true;
        }
        bool isatomic = language_field_isatomic(stt, fieldidx);
        if (!isatomic && order != language_memory_order_notatomic && order != language_memory_order_unspecified) {
            emit_atomic_error(ctx, "isdefined: non-atomic field cannot be accessed atomically");
            *ret = language_cgval_t(); // unreachable
            return true;
        }
        if (isatomic && order == language_memory_order_notatomic) {
            emit_atomic_error(ctx, "isdefined: atomic field cannot be accessed non-atomically");
            *ret = language_cgval_t(); // unreachable
            return true;
        }
        else if (fieldidx < nf - stt->name->n_uninitialized) {
            *ret = mark_language_const(ctx, language_true);
        }
        else if (language_field_isptr(stt, fieldidx) || language_type_hasptr(language_field_type(stt, fieldidx))) {
            Value *fldv;
            size_t offs = language_field_offset(stt, fieldidx) / sizeof(language_value_t*);
            if (obj.ispointer()) {
                auto tbaa = best_field_tbaa(ctx, obj, stt, fieldidx, offs);
                if (!language_field_isptr(stt, fieldidx))
                    offs += ((language_datatype_t*)language_field_type(stt, fieldidx))->layout->first_ptr;
                Value *ptr = emit_bitcast(ctx, data_pointer(ctx, obj), ctx.types().T_pprjlvalue);
                Value *addr = ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, ptr, offs);
                // emit this using the same type as emit_getfield_knownidx
                // so that LLVM may be able to load-load forward them and fold the result
                language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, tbaa);
                fldv = ai.decorateInst(ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, addr, ctx.types().alignof_ptr));
                cast<LoadInst>(fldv)->setOrdering(order <= language_memory_order_notatomic ? AtomicOrdering::Unordered : get_llvm_atomic_order(order));
            }
            else {
                fldv = ctx.builder.CreateExtractValue(obj.V, offs);
                if (!language_field_isptr(stt, fieldidx)) {
                    fldv = extract_first_ptr(ctx, fldv);
                    assert(fldv);
                }
            }
            Value *isdef = ctx.builder.CreateIsNotNull(fldv);
            setName(ctx.emission_context, isdef, "isdefined");
            *ret = mark_language_type(ctx, isdef, false, language_bool_type);
        }
        else {
            *ret = mark_language_const(ctx, language_true);
        }
        if (order > language_memory_order_monotonic && ret->constant) {
            // fence instructions may only have acquire, release, acq_rel, or seq_cst ordering.
            ctx.builder.CreateFence(get_llvm_atomic_order(order));
        }
        return true;
    }

    else if (f == language_builtin_donotdelete) {
        // For now we emit this as a vararg call to the builtin
        // (which doesn't look at the arguments). In the future,
        // this should be an LLVM builtin.
        auto it = builtin_func_map().find(language_f_donotdelete_addr);
        if (it == builtin_func_map().end()) {
            return false;
        }

        *ret = mark_language_const(ctx, language_nothing);
        FunctionType *Fty = FunctionType::get(getVoidTy(ctx.builder.getContext()), true);
        Function *dnd = prepare_call(it->second);
        SmallVector<Value*, 1> call_args;

        for (size_t i = 1; i <= nargs; ++i) {
            const language_cgval_t &obj = argv[i];
            if (obj.V) {
                // TODO is this strong enough to constitute a read of any contained
                // pointers?
                Value *V = obj.V;
                if (obj.isboxed) {
                    V = emit_pointer_from_objref(ctx, V);
                }
                call_args.push_back(V);
            }
        }
        ctx.builder.CreateCall(Fty, dnd, call_args);
        return true;
    }

    else if (f == language_builtin_compilerbarrier && (nargs == 2)) {
        emit_typecheck(ctx, argv[1], (language_value_t*)language_symbol_type, "compilerbarrier");
        *ret = argv[2];
        return true;
    }

    return false;
}

// Returns ctx.types().T_prjlvalue
static CallInst *emit_jlcall(language_codectx_t &ctx, FunctionCallee theFptr, Value *theF,
                             ArrayRef<language_cgval_t> argv, size_t nargs, JuliaFunction<> *trampoline)
{
    ++EmittedLANGUAGECalls;
    Function *TheTrampoline = prepare_call(trampoline);
    // emit arguments
    SmallVector<Value*, 4> theArgs;
    theArgs.push_back(theFptr.getCallee());
    if (theF)
        theArgs.push_back(theF);
    for (size_t i = 0; i < nargs; i++) {
        Value *arg = boxed(ctx, argv[i]);
        theArgs.push_back(arg);
    }
    CallInst *result = ctx.builder.CreateCall(TheTrampoline, theArgs);
    result->setAttributes(TheTrampoline->getAttributes());
    // TODO: we could add readonly attributes in many cases to the args
    return result;
}

// Returns ctx.types().T_prjlvalue
static CallInst *emit_jlcall(language_codectx_t &ctx, JuliaFunction<> *theFptr, Value *theF,
                             ArrayRef<language_cgval_t> argv, size_t nargs, JuliaFunction<> *trampoline)
{
    return emit_jlcall(ctx, prepare_call(theFptr), theF, argv, nargs, trampoline);
}

static language_cgval_t emit_call_specfun_other(language_codectx_t &ctx, bool is_opaque_closure, language_value_t *specTypes, language_value_t *jlretty, llvm::Value *callee, StringRef specFunctionObject, language_code_instance_t *fromexternal,
                                          ArrayRef<language_cgval_t> argv, size_t nargs, language_returninfo_t::CallingConv *cc, unsigned *return_roots, language_value_t *inferred_retty)
{
    ++EmittedSpecfunCalls;
    // emit specialized call site
    bool gcstack_arg = LANGUAGE_FEAT_TEST(ctx, gcstack_arg);
    language_returninfo_t returninfo = get_specsig_function(ctx, language_Module, callee, specFunctionObject, specTypes, jlretty, is_opaque_closure, gcstack_arg);
    FunctionType *cft = returninfo.decl.getFunctionType();
    *cc = returninfo.cc;
    *return_roots = returninfo.return_roots;

    size_t nfargs = cft->getNumParams();
    SmallVector<Value *, 0> argvals(nfargs);
    unsigned idx = 0;
    AllocaInst *result = nullptr;
    switch (returninfo.cc) {
    case language_returninfo_t::Boxed:
    case language_returninfo_t::Register:
    case language_returninfo_t::Ghosts:
        break;
    case language_returninfo_t::SRet:
        result = emit_static_alloca(ctx, getAttributeAtIndex(returninfo.attrs, 1, Attribute::StructRet).getValueAsType());
        #if LANGUAGE_LLVM_VERSION < 170000
        assert(cast<PointerType>(result->getType())->hasSameElementTypeAs(cast<PointerType>(cft->getParamType(0))));
        #endif
        argvals[idx] = result;
        idx++;
        break;
    case language_returninfo_t::Union:
        result = emit_static_alloca(ctx, ArrayType::get(getInt8Ty(ctx.builder.getContext()), returninfo.union_bytes));
        setName(ctx.emission_context, result, "sret_box");
        if (returninfo.union_align > 1)
            result->setAlignment(Align(returninfo.union_align));
        argvals[idx] = result;
        idx++;
        break;
    }

    if (returninfo.return_roots) {
        AllocaInst *return_roots = emit_static_alloca(ctx, ArrayType::get(ctx.types().T_prjlvalue, returninfo.return_roots));
        argvals[idx] = return_roots;
        idx++;
    }
    if (gcstack_arg) {
        argvals[idx] = ctx.pgcstack;
        idx++;
    }
    for (size_t i = 0; i < nargs; i++) {
        language_value_t *jt = language_nth_slot_type(specTypes, i);
        // n.b.: specTypes is required to be a datatype by construction for specsig
        language_cgval_t arg = argv[i];
        if (is_opaque_closure && i == 0) {
            Type *at = cft->getParamType(idx);
            // Special optimization for opaque closures: We know that specsig opaque
            // closures don't look at their type tag (they are fairly quickly discarded
            // for their environments). Therefore, we can just pass these as a pointer,
            // rather than a boxed value.
            arg = value_to_pointer(ctx, arg);
            argvals[idx] = decay_derived(ctx, maybe_bitcast(ctx, data_pointer(ctx, arg), at));
        }
        else if (is_uniquerep_Type(jt)) {
            continue;
        } else {
            bool isboxed = deserves_argbox(jt);
            Type *et = isboxed ? ctx.types().T_prjlvalue : language_type_to_llvm(ctx, jt);
            if (type_is_ghost(et))
                continue;
            assert(idx < nfargs);
            Type *at = cft->getParamType(idx);
            if (isboxed) {
                assert(at == ctx.types().T_prjlvalue && et == ctx.types().T_prjlvalue);
                argvals[idx] = boxed(ctx, arg);
            }
            else if (et->isAggregateType()) {
                arg = value_to_pointer(ctx, arg);
                // can lazy load on demand, no copy needed
                assert(at == PointerType::get(et, AddressSpace::Derived));
                argvals[idx] = decay_derived(ctx, maybe_bitcast(ctx, data_pointer(ctx, arg), at));
            }
            else {
                assert(at == et);
                Value *val = emit_unbox(ctx, et, arg, jt);
                if (!val) {
                    // There was a type mismatch of some sort - exit early
                    CreateTrap(ctx.builder);
                    return language_cgval_t();
                }
                argvals[idx] = val;
            }
        }
        idx++;
    }
    assert(idx == nfargs);
    Value *TheCallee = returninfo.decl.getCallee();
    if (fromexternal) {
        std::string namep("p");
        namep += cast<Function>(returninfo.decl.getCallee())->getName();
        GlobalVariable *GV = cast_or_null<GlobalVariable>(language_Module->getNamedValue(namep));
        if (GV == nullptr) {
            GV = new GlobalVariable(*language_Module, TheCallee->getType(), false,
                                    GlobalVariable::ExternalLinkage,
                                    Constant::getNullValue(TheCallee->getType()),
                                    namep);
            ctx.emission_context.external_fns[std::make_tuple(fromexternal, true)] = GV;
        }
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
        TheCallee = ai.decorateInst(ctx.builder.CreateAlignedLoad(TheCallee->getType(), GV, Align(sizeof(void*))));
        setName(ctx.emission_context, TheCallee, namep);
    }
    CallInst *call = ctx.builder.CreateCall(cft, TheCallee, argvals);
    call->setAttributes(returninfo.attrs);
    if (gcstack_arg)
        call->setCallingConv(CallingConv::Swift);

    language_cgval_t retval;
    switch (returninfo.cc) {
        case language_returninfo_t::Boxed:
            retval = mark_language_type(ctx, call, true, jlretty);
            break;
        case language_returninfo_t::Register:
            retval = mark_language_type(ctx, call, false, jlretty);
            break;
        case language_returninfo_t::SRet:
            assert(result);
            retval = mark_language_slot(result, jlretty, NULL, ctx.tbaa().tbaa_stack);
            break;
        case language_returninfo_t::Union: {
            Value *box = ctx.builder.CreateExtractValue(call, 0);
            Value *tindex = ctx.builder.CreateExtractValue(call, 1);
            Value *derived = ctx.builder.CreateSelect(
                ctx.builder.CreateICmpEQ(
                        ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                        ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0)),
                decay_derived(ctx, ctx.builder.CreateBitCast(argvals[0], ctx.types().T_pjlvalue)),
                decay_derived(ctx, box)
            );
            retval = mark_language_slot(derived,
                                     jlretty,
                                     tindex,
                                     ctx.tbaa().tbaa_stack);
            retval.Vboxed = box;
            break;
        }
        case language_returninfo_t::Ghosts:
            retval = mark_language_slot(NULL, jlretty, call, ctx.tbaa().tbaa_stack);
            break;
    }
    // see if inference has a different / better type for the call than the lambda
    return update_language_type(ctx, retval, inferred_retty);
}

static language_cgval_t emit_call_specfun_other(language_codectx_t &ctx, language_method_instance_t *mi, language_value_t *jlretty, StringRef specFunctionObject, language_code_instance_t *fromexternal,
                                          ArrayRef<language_cgval_t> argv, size_t nargs, language_returninfo_t::CallingConv *cc, unsigned *return_roots, language_value_t *inferred_retty)
{
    bool is_opaque_closure = language_is_method(mi->def.value) && mi->def.method->is_for_opaque_closure;
    return emit_call_specfun_other(ctx, is_opaque_closure, mi->specTypes, jlretty, NULL,
        specFunctionObject, fromexternal, argv, nargs, cc, return_roots, inferred_retty);
}

static language_cgval_t emit_call_specfun_boxed(language_codectx_t &ctx, language_value_t *jlretty, StringRef specFunctionObject, language_code_instance_t *fromexternal,
                                          ArrayRef<language_cgval_t> argv, size_t nargs, language_value_t *inferred_retty)
{
    Value *theFptr;
    if (fromexternal) {
        std::string namep("p");
        namep += specFunctionObject;
        GlobalVariable *GV = cast_or_null<GlobalVariable>(language_Module->getNamedValue(namep));
        Type *pfunc = ctx.types().T_jlfunc->getPointerTo();
        if (GV == nullptr) {
            GV = new GlobalVariable(*language_Module, pfunc, false,
                                    GlobalVariable::ExternalLinkage,
                                    Constant::getNullValue(pfunc),
                                    namep);
            ctx.emission_context.external_fns[std::make_tuple(fromexternal, false)] = GV;
        }
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
        theFptr = ai.decorateInst(ctx.builder.CreateAlignedLoad(pfunc, GV, Align(sizeof(void*))));
        setName(ctx.emission_context, theFptr, specFunctionObject);
    }
    else {
        theFptr = language_Module->getOrInsertFunction(specFunctionObject, ctx.types().T_jlfunc).getCallee();
        addRetAttr(cast<Function>(theFptr), Attribute::NonNull);
    }
    Value *ret = emit_jlcall(ctx, FunctionCallee(ctx.types().T_jlfunc, theFptr), nullptr, argv, nargs, language_call);
    return update_language_type(ctx, mark_language_type(ctx, ret, true, jlretty), inferred_retty);
}

static language_cgval_t emit_invoke(language_codectx_t &ctx, language_expr_t *ex, language_value_t *rt)
{
    language_value_t **args = language_array_data(ex->args, language_value_t*);
    size_t arglen = language_array_dim0(ex->args);
    size_t nargs = arglen - 1;
    assert(arglen >= 2);

    language_cgval_t lival = emit_expr(ctx, args[0]);
    SmallVector<language_cgval_t, 0> argv(nargs);
    for (size_t i = 0; i < nargs; ++i) {
        argv[i] = emit_expr(ctx, args[i + 1]);
        if (argv[i].typ == language_bottom_type)
            return language_cgval_t();
    }
    return emit_invoke(ctx, lival, argv, nargs, rt);
}

static language_cgval_t emit_invoke(language_codectx_t &ctx, const language_cgval_t &lival, ArrayRef<language_cgval_t> argv, size_t nargs, language_value_t *rt)
{
    ++EmittedInvokes;
    bool handled = false;
    language_cgval_t result;
    if (lival.constant) {
        language_method_instance_t *mi = (language_method_instance_t*)lival.constant;
        assert(language_is_method_instance(mi));
        if (mi == ctx.linfo) {
            // handle self-recursion specially
            language_returninfo_t::CallingConv cc = language_returninfo_t::CallingConv::Boxed;
            FunctionType *ft = ctx.f->getFunctionType();
            StringRef protoname = ctx.f->getName();
            if (ft == ctx.types().T_jlfunc) {
                result = emit_call_specfun_boxed(ctx, ctx.rettype, protoname, nullptr, argv, nargs, rt);
                handled = true;
            }
            else if (ft != ctx.types().T_jlfuncparams) {
                unsigned return_roots = 0;
                result = emit_call_specfun_other(ctx, mi, ctx.rettype, protoname, nullptr, argv, nargs, &cc, &return_roots, rt);
                handled = true;
            }
        }
        else {
            language_value_t *ci = ctx.params->lookup(mi, ctx.min_world, ctx.max_world);
            if (ci != language_nothing) {
                language_code_instance_t *codeinst = (language_code_instance_t*)ci;
                auto invoke = language_atomic_load_acquire(&codeinst->invoke);
                 // check if we know how to handle this specptr
                if (invoke == language_fptr_const_return_addr) {
                    result = mark_language_const(ctx, codeinst->rettype_const);
                    handled = true;
                }
                else if (invoke != language_fptr_sparam_addr) {
                    bool specsig, needsparams;
                    std::tie(specsig, needsparams) = uses_specsig(mi, codeinst->rettype, ctx.params->prefer_specsig);
                    std::string name;
                    StringRef protoname;
                    bool need_to_emit = true;
                    bool cache_valid = ctx.use_cache || ctx.external_linkage;
                    bool external = false;

                    // Check if we already queued this up
                    auto it = ctx.call_targets.find(codeinst);
                    if (need_to_emit && it != ctx.call_targets.end()) {
                        protoname = it->second.decl->getName();
                        need_to_emit = cache_valid = false;
                    }

                    // Check if it is already compiled (either JIT or externally)
                    if (cache_valid) {
                        // optimization: emit the correct name immediately, if we know it
                        // TODO: use `emitted` map here too to try to consolidate names?
                        // WARNING: isspecsig is protected by the codegen-lock. If that lock is removed, then the isspecsig load needs to be properly atomically sequenced with this.
                        auto fptr = language_atomic_load_relaxed(&codeinst->specptr.fptr);
                        if (fptr) {
                            while (!(language_atomic_load_acquire(&codeinst->specsigflags) & 0b10)) {
                                language_cpu_pause();
                            }
                            invoke = language_atomic_load_relaxed(&codeinst->invoke);
                            if (specsig ? language_atomic_load_relaxed(&codeinst->specsigflags) & 0b1 : invoke == language_fptr_args_addr) {
                                protoname = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)fptr, codeinst);
                                if (ctx.external_linkage) {
                                    // TODO: Add !specsig support to aotcompile.cpp
                                    // Check that the codeinst is containing native code
                                    if (specsig && language_atomic_load_relaxed(&codeinst->specsigflags) & 0b100) {
                                        external = true;
                                        need_to_emit = false;
                                    }
                                }
                                else { // ctx.use_cache
                                    need_to_emit = false;
                                }
                            }
                        }
                    }
                    if (need_to_emit) {
                        raw_string_ostream(name) << (specsig ? "j_" : "j1_") << name_from_method_instance(mi) << "_" << language_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
                        protoname = StringRef(name);
                    }
                    language_returninfo_t::CallingConv cc = language_returninfo_t::CallingConv::Boxed;
                    unsigned return_roots = 0;
                    if (specsig)
                        result = emit_call_specfun_other(ctx, mi, codeinst->rettype, protoname, external ? codeinst : nullptr, argv, nargs, &cc, &return_roots, rt);
                    else
                        result = emit_call_specfun_boxed(ctx, codeinst->rettype, protoname, external ? codeinst : nullptr, argv, nargs, rt);
                    handled = true;
                    if (need_to_emit) {
                        Function *trampoline_decl = cast<Function>(language_Module->getNamedValue(protoname));
                        ctx.call_targets[codeinst] = {cc, return_roots, trampoline_decl, specsig};
                    }
                }
            }
        }
    }
    if (!handled) {
        Value *r = emit_jlcall(ctx, jlinvoke_func, boxed(ctx, lival), argv, nargs, language_call2);
        result = mark_language_type(ctx, r, true, rt);
    }
    if (result.typ == language_bottom_type)
        CreateTrap(ctx.builder);
    return result;
}

static language_cgval_t emit_invoke_modify(language_codectx_t &ctx, language_expr_t *ex, language_value_t *rt)
{
    ++EmittedInvokes;
    language_value_t **args = language_array_data(ex->args, language_value_t*);
    size_t arglen = language_array_dim0(ex->args);
    size_t nargs = arglen - 1;
    assert(arglen >= 2);
    language_cgval_t lival = emit_expr(ctx, args[0]);
    SmallVector<language_cgval_t, 0> argv(nargs);
    for (size_t i = 0; i < nargs; ++i) {
        argv[i] = emit_expr(ctx, args[i + 1]);
        if (argv[i].typ == language_bottom_type)
            return language_cgval_t();
    }
    const language_cgval_t &f = argv[0];
    if (f.constant) {
        language_cgval_t ret;
        auto it = builtin_func_map().end();
        if (f.constant == language_builtin_modifyfield) {
            if (emit_f_opfield(ctx, &ret, language_builtin_modifyfield, argv, nargs - 1, &lival))
                return ret;
            it = builtin_func_map().find(language_f_modifyfield_addr);
            assert(it != builtin_func_map().end());
        }
        else if (f.constant == language_builtin_modifyglobal) {
            if (emit_f_opglobal(ctx, &ret, language_builtin_modifyglobal, argv, nargs - 1, &lival))
                return ret;
            it = builtin_func_map().find(language_f_modifyglobal_addr);
            assert(it != builtin_func_map().end());
        }
        else if (f.constant == language_builtin_memoryrefmodify) {
            if (emit_f_opmemory(ctx, &ret, language_builtin_memoryrefmodify, argv, nargs - 1, &lival))
                return ret;
            it = builtin_func_map().find(language_f_memoryrefmodify_addr);
            assert(it != builtin_func_map().end());
        }
        else if (language_typetagis(f.constant, language_intrinsic_type)) {
            LANGUAGE_I::intrinsic fi = (intrinsic)*(uint32_t*)language_data_ptr(f.constant);
            if (fi == LANGUAGE_I::atomic_pointermodify && language_intrinsic_nargs((int)fi) == nargs - 1)
                return emit_atomic_pointerop(ctx, fi, ArrayRef<language_cgval_t>(argv).drop_front(), nargs - 1, &lival);
        }

        if (it != builtin_func_map().end()) {
            Value *oldnew = emit_jlcall(ctx, it->second, Constant::getNullValue(ctx.types().T_prjlvalue), ArrayRef<language_cgval_t>(argv).drop_front(), nargs - 1, language_call);
            return mark_language_type(ctx, oldnew, true, rt);
        }
    }

    // emit function and arguments
    Value *callval = emit_jlcall(ctx, jlapplygeneric_func, nullptr, argv, nargs, language_call);
    return mark_language_type(ctx, callval, true, rt);
}

static language_cgval_t emit_specsig_oc_call(language_codectx_t &ctx, language_value_t *oc_type, language_value_t *sigtype, MutableArrayRef<language_cgval_t> argv /*n.b. this mutation is unusual */, size_t nargs)
{
    language_datatype_t *oc_argt = (language_datatype_t *)language_tparam0(oc_type);
    language_value_t *oc_rett = language_tparam1(oc_type);
    language_svec_t *types = language_get_fieldtypes((language_datatype_t*)oc_argt);
    size_t ntypes = language_svec_len(types);
    for (size_t i = 0; i < nargs-1; ++i) {
        language_value_t *typ = i >= ntypes ? language_svecref(types, ntypes-1) : language_svecref(types, i);
        if (language_is_vararg(typ))
            typ = language_unwrap_vararg(typ);
        emit_typecheck(ctx, argv[i+1], typ, "typeassert");
        argv[i+1] = update_language_type(ctx, argv[i+1], typ);
        if (argv[i+1].typ == language_bottom_type)
            return language_cgval_t();
    }
    language_returninfo_t::CallingConv cc = language_returninfo_t::CallingConv::Boxed;
    unsigned return_roots = 0;

    // Load specptr
    language_cgval_t &theArg = argv[0];
    language_cgval_t closure_specptr = emit_getfield_knownidx(ctx, theArg, 4, (language_datatype_t*)oc_type, language_memory_order_notatomic);
    Value *specptr = emit_unbox(ctx, ctx.types().T_size, closure_specptr, (language_value_t*)language_long_type);
    LANGUAGE_GC_PUSH1(&sigtype);
    language_cgval_t r = emit_call_specfun_other(ctx, true, sigtype, oc_rett, specptr, "", NULL, argv, nargs,
        &cc, &return_roots, oc_rett);
    LANGUAGE_GC_POP();
    return r;
}

static language_cgval_t emit_call(language_codectx_t &ctx, language_expr_t *ex, language_value_t *rt, bool is_promotable)
{
    ++EmittedCalls;
    language_value_t **args = language_array_data(ex->args, language_value_t*);
    size_t nargs = language_array_dim0(ex->args);
    assert(nargs >= 1);
    language_cgval_t f = emit_expr(ctx, args[0]);
    if (f.typ == language_bottom_type) {
        return language_cgval_t();
    }

    if (f.constant && language_typetagis(f.constant, language_intrinsic_type)) {
        LANGUAGE_I::intrinsic fi = (intrinsic)*(uint32_t*)language_data_ptr(f.constant);
        return emit_intrinsic(ctx, fi, args, nargs - 1);
    }

    size_t n_generic_args = nargs;

    SmallVector<language_cgval_t, 0> argv(n_generic_args);

    argv[0] = f;
    for (size_t i = 1; i < nargs; ++i) {
        argv[i] = emit_expr(ctx, args[i]);
        if (argv[i].typ == language_bottom_type)
            return language_cgval_t(); // anything past here is unreachable
    }

    if (language_subtype(f.typ, (language_value_t*)language_builtin_type)) {
        if (f.constant) {
            if (f.constant == language_builtin_ifelse && nargs == 4)
                return emit_ifelse(ctx, argv[1], argv[2], argv[3], rt);
            language_cgval_t result;
            bool handled = emit_builtin_call(ctx, &result, f.constant, argv, nargs - 1, rt, ex, is_promotable);
            if (handled)
                return result;

            // special case for some known builtin not handled by emit_builtin_call
            auto it = builtin_func_map().find(language_get_builtin_fptr((language_datatype_t*)language_typeof(f.constant)));
            if (it != builtin_func_map().end()) {
                Value *ret = emit_jlcall(ctx, it->second, Constant::getNullValue(ctx.types().T_prjlvalue), ArrayRef<language_cgval_t>(argv).drop_front(), nargs - 1, language_call);
                setName(ctx.emission_context, ret, it->second->name + "_ret");
                return mark_language_type(ctx, ret, true, rt);
            }
        }
        FunctionCallee fptr;
        Value *F;
        JuliaFunction<> *cc;
        if (f.typ == (language_value_t*)language_intrinsic_type) {
            fptr = prepare_call(jlintrinsic_func);
            F = f.ispointer() ? data_pointer(ctx, f) : value_to_pointer(ctx, f).V;
            F = decay_derived(ctx, maybe_bitcast(ctx, F, ctx.types().T_pjlvalue));
            cc = language_call3;
        }
        else {
            fptr = FunctionCallee(get_func_sig(ctx.builder.getContext()), ctx.builder.CreateCall(prepare_call(jlgetbuiltinfptr_func), {emit_typeof(ctx, f)}));
            F = boxed(ctx, f);
            cc = language_call;
        }
        Value *ret = emit_jlcall(ctx, fptr, F, ArrayRef<language_cgval_t>(argv).drop_front(), nargs - 1, cc);
        setName(ctx.emission_context, ret, "Builtin_ret");
        return mark_language_type(ctx, ret, true, rt);
    }

    // handle calling an OpaqueClosure
    if (language_is_concrete_type(f.typ) && language_subtype(f.typ, (language_value_t*)language_opaque_closure_type)) {
        language_value_t *oc_argt = language_tparam0(f.typ);
        language_value_t *oc_rett = language_tparam1(f.typ);
        if (language_is_datatype(oc_argt) && language_tupletype_length_compat(oc_argt, nargs-1)) {
            language_value_t *sigtype = language_argtype_with_function_type((language_value_t*)f.typ, (language_value_t*)oc_argt);
            if (uses_specsig(sigtype, false, oc_rett, true)) {
                LANGUAGE_GC_PUSH1(&sigtype);
                language_cgval_t r = emit_specsig_oc_call(ctx, f.typ, sigtype, argv, nargs);
                LANGUAGE_GC_POP();
                return r;
            }
        }
    }

    // emit function and arguments
    Value *callval = emit_jlcall(ctx, jlapplygeneric_func, nullptr, argv, n_generic_args, language_call);
    return mark_language_type(ctx, callval, true, rt);
}

// --- accessing and assigning variables ---

static void emit_hasnofield_error_ifnot(language_codectx_t &ctx, Value *ok, language_sym_t *type, language_cgval_t name)
{
    ++EmittedUndefVarErrors;
    assert(name.typ == (language_value_t*)language_symbol_type);
    BasicBlock *err = BasicBlock::Create(ctx.builder.getContext(), "err", ctx.f);
    BasicBlock *ifok = BasicBlock::Create(ctx.builder.getContext(), "ok");
    ctx.builder.CreateCondBr(ok, ifok, err);
    ctx.builder.SetInsertPoint(err);
    ctx.builder.CreateCall(prepare_call(jlhasnofield_func),
                          {mark_callee_rooted(ctx, literal_pointer_val(ctx, (language_value_t*)type)),
                           mark_callee_rooted(ctx, boxed(ctx, name))});
    ctx.builder.CreateUnreachable();
    ifok->insertInto(ctx.f);
    ctx.builder.SetInsertPoint(ifok);
}

// returns a language_ppvalue_t location for the global variable m.s
// if the reference currently bound or assign == true,
//   pbnd will also be assigned with the binding address
static Value *global_binding_pointer(language_codectx_t &ctx, language_module_t *m, language_sym_t *s,
                                     language_binding_t **pbnd, bool assign)
{
    language_binding_t *b = language_get_module_binding(m, s, 1);
    if (assign) {
        if (language_atomic_load_relaxed(&b->owner) == NULL)
            // not yet declared
            b = NULL;
    }
    else {
        b = language_atomic_load_relaxed(&b->owner);
        if (b == NULL)
            // try to look this up now
            b = language_get_binding(m, s);
    }
    if (b == NULL) {
        // var not found. switch to delayed lookup.
        Constant *initnul = Constant::getNullValue(ctx.types().T_pjlvalue);
        GlobalVariable *bindinggv = new GlobalVariable(*ctx.f->getParent(), ctx.types().T_pjlvalue,
                false, GlobalVariable::PrivateLinkage, initnul, "language_binding_ptr"); // LLVM has bugs with nameless globals
        LoadInst *cachedval = ctx.builder.CreateAlignedLoad(ctx.types().T_pjlvalue, bindinggv, Align(sizeof(void*)));
        setName(ctx.emission_context, cachedval, language_symbol_name(m->name) + StringRef(".") + language_symbol_name(s) + ".cached");
        cachedval->setOrdering(AtomicOrdering::Unordered);
        BasicBlock *have_val = BasicBlock::Create(ctx.builder.getContext(), "found");
        BasicBlock *not_found = BasicBlock::Create(ctx.builder.getContext(), "notfound");
        BasicBlock *currentbb = ctx.builder.GetInsertBlock();
        auto iscached = ctx.builder.CreateICmpNE(cachedval, initnul);
        setName(ctx.emission_context, iscached, "iscached");
        ctx.builder.CreateCondBr(iscached, have_val, not_found);
        not_found->insertInto(ctx.f);
        ctx.builder.SetInsertPoint(not_found);
        Value *bval = ctx.builder.CreateCall(prepare_call(assign ? jlgetbindingwrorerror_func : jlgetbindingorerror_func),
                { literal_pointer_val(ctx, (language_value_t*)m),
                  literal_pointer_val(ctx, (language_value_t*)s) });
        setName(ctx.emission_context, bval, language_symbol_name(m->name) + StringRef(".") + language_symbol_name(s) + ".found");
        ctx.builder.CreateAlignedStore(bval, bindinggv, Align(sizeof(void*)))->setOrdering(AtomicOrdering::Release);
        ctx.builder.CreateBr(have_val);
        have_val->insertInto(ctx.f);
        ctx.builder.SetInsertPoint(have_val);
        PHINode *p = ctx.builder.CreatePHI(ctx.types().T_pjlvalue, 2);
        p->addIncoming(cachedval, currentbb);
        p->addIncoming(bval, not_found);
        setName(ctx.emission_context, p, language_symbol_name(m->name) + StringRef(".") + language_symbol_name(s));
        return p;
    }
    if (assign) {
        if (language_atomic_load_relaxed(&b->owner) != b) {
            // this will fail at runtime, so defer to the runtime to create the error
            ctx.builder.CreateCall(prepare_call(jlgetbindingwrorerror_func),
                    { literal_pointer_val(ctx, (language_value_t*)m),
                      literal_pointer_val(ctx, (language_value_t*)s) });
            CreateTrap(ctx.builder);
            return NULL;
        }
    }
    else {
        if (b->deprecated)
            cg_bdw(ctx, s, b);
    }
    *pbnd = b;
    return language_binding_gv(ctx, b);
}

static language_cgval_t emit_checked_var(language_codectx_t &ctx, Value *bp, language_sym_t *name, language_value_t *scope, bool isvol, MDNode *tbaa)
{
    LoadInst *v = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, bp, Align(sizeof(void*)));
    setName(ctx.emission_context, v, language_symbol_name(name) + StringRef(".checked"));
    if (isvol)
        v->setVolatile(true);
    v->setOrdering(AtomicOrdering::Unordered);
    if (tbaa) {
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, tbaa);
        ai.decorateInst(v);
    }
    undef_var_error_ifnot(ctx, ctx.builder.CreateIsNotNull(v), name, scope);
    return mark_language_type(ctx, v, true, language_any_type);
}

static language_cgval_t emit_sparam(language_codectx_t &ctx, size_t i)
{
    if (language_svec_len(ctx.linfo->sparam_vals) > 0) {
        language_value_t *e = language_svecref(ctx.linfo->sparam_vals, i);
        if (!language_is_typevar(e)) {
            return mark_language_const(ctx, e);
        }
    }
    assert(ctx.spvals_ptr != NULL);
    Value *bp = ctx.builder.CreateConstInBoundsGEP1_32(
            ctx.types().T_prjlvalue,
            ctx.spvals_ptr,
            i + sizeof(language_svec_t) / sizeof(language_value_t*));
    language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
    Value *sp = ai.decorateInst(ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, bp, Align(sizeof(void*))));
    setName(ctx.emission_context, sp, "sparam");
    Value *isnull = ctx.builder.CreateICmpNE(emit_typeof(ctx, sp, false, true), emit_tagfrom(ctx, language_tvar_type));
    language_unionall_t *sparam = (language_unionall_t*)ctx.linfo->def.method->sig;
    for (size_t j = 0; j < i; j++) {
        sparam = (language_unionall_t*)sparam->body;
        assert(language_is_unionall(sparam));
    }
    undef_var_error_ifnot(ctx, isnull, sparam->var->name, (language_value_t*)language_static_parameter_sym);
    return mark_language_type(ctx, sp, true, language_any_type);
}

static language_cgval_t emit_isdefined(language_codectx_t &ctx, language_value_t *sym)
{
    Value *isnull = NULL;
    if (language_is_slotnumber(sym) || language_is_argument(sym)) {
        size_t sl = language_slot_number(sym) - 1;
        language_varinfo_t &vi = ctx.slots[sl];
        if (!vi.usedUndef)
            return mark_language_const(ctx, language_true);
        if (vi.boxroot == NULL || vi.pTIndex != NULL) {
            assert(vi.defFlag);
            isnull = ctx.builder.CreateAlignedLoad(getInt1Ty(ctx.builder.getContext()), vi.defFlag, Align(1), vi.isVolatile);
        }
        if (vi.boxroot != NULL) {
            Value *boxed = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, vi.boxroot, Align(sizeof(void*)), vi.isVolatile);
            Value *box_isnull = ctx.builder.CreateICmpNE(boxed, Constant::getNullValue(ctx.types().T_prjlvalue));
            if (vi.pTIndex) {
                // value is either boxed in the stack slot, or unboxed in value
                // as indicated by testing (pTIndex & UNION_BOX_MARKER)
                Value *tindex = ctx.builder.CreateAlignedLoad(getInt8Ty(ctx.builder.getContext()), vi.pTIndex, Align(sizeof(void*)), vi.isVolatile);
                Value *load_unbox = ctx.builder.CreateICmpEQ(
                            ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                            ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
                isnull = ctx.builder.CreateSelect(load_unbox, isnull, box_isnull);
            }
            else {
                isnull = box_isnull;
            }
        }
    }
    else if (language_is_expr(sym)) {
        assert(((language_expr_t*)sym)->head == language_static_parameter_sym && "malformed isdefined expression");
        size_t i = language_unbox_long(language_exprarg(sym, 0)) - 1;
        if (language_svec_len(ctx.linfo->sparam_vals) > 0) {
            language_value_t *e = language_svecref(ctx.linfo->sparam_vals, i);
            if (!language_is_typevar(e)) {
                return mark_language_const(ctx, language_true);
            }
        }
        assert(ctx.spvals_ptr != NULL);
        Value *bp = ctx.builder.CreateConstInBoundsGEP1_32(
                ctx.types().T_prjlvalue,
                ctx.spvals_ptr,
                i + sizeof(language_svec_t) / sizeof(language_value_t*));
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
        Value *sp = ai.decorateInst(ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, bp, Align(sizeof(void*))));
        isnull = ctx.builder.CreateICmpNE(emit_typeof(ctx, sp, false, true), emit_tagfrom(ctx, language_tvar_type));
    }
    else {
        language_module_t *modu;
        language_sym_t *name;
        if (language_is_globalref(sym)) {
            modu = language_globalref_mod(sym);
            name = language_globalref_name(sym);
        }
        else {
            assert(language_is_symbol(sym) && "malformed isdefined expression");
            modu = ctx.module;
            name = (language_sym_t*)sym;
        }
        language_binding_t *bnd = language_get_binding(modu, name);
        if (bnd) {
            if (language_atomic_load_acquire(&bnd->value) != NULL && bnd->constp)
                return mark_language_const(ctx, language_true);
            Value *bp = language_binding_gv(ctx, bnd);
            bp = language_binding_pvalue(ctx, bp);
            LoadInst *v = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, bp, Align(sizeof(void*)));
            language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_binding);
            ai.decorateInst(v);
            v->setOrdering(AtomicOrdering::Unordered);
            isnull = ctx.builder.CreateICmpNE(v, Constant::getNullValue(ctx.types().T_prjlvalue));
        }
        else {
            Value *v = ctx.builder.CreateCall(prepare_call(jlboundp_func), {
                    literal_pointer_val(ctx, (language_value_t*)modu),
                    literal_pointer_val(ctx, (language_value_t*)name)
                });
            isnull = ctx.builder.CreateICmpNE(v, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0));
        }
    }
    return mark_language_type(ctx, isnull, false, language_bool_type);
}

static language_cgval_t emit_varinfo(language_codectx_t &ctx, language_varinfo_t &vi, language_sym_t *varname) {
    language_value_t *typ = vi.value.typ;
    language_cgval_t v;
    Value *isnull = NULL;
    if (vi.boxroot == NULL || vi.pTIndex != NULL) {
        if ((!vi.isVolatile && vi.isSA) || vi.isArgument || vi.value.constant || !vi.value.V) {
            v = vi.value;
            if (vi.pTIndex)
                v.TIndex = ctx.builder.CreateAlignedLoad(getInt8Ty(ctx.builder.getContext()), vi.pTIndex, Align(1));
        }
        else {
            // copy value to a non-mutable (non-volatile SSA) location
            AllocaInst *varslot = cast<AllocaInst>(vi.value.V);
            setName(ctx.emission_context, varslot, language_symbol_name(varname));
            Type *T = varslot->getAllocatedType();
            assert(!varslot->isArrayAllocation() && "variables not expected to be VLA");
            AllocaInst *ssaslot = cast<AllocaInst>(varslot->clone());
            setName(ctx.emission_context, ssaslot, language_symbol_name(varname) + StringRef(".ssa"));
            ssaslot->insertAfter(varslot);
            if (vi.isVolatile) {
                Value *unbox = ctx.builder.CreateAlignedLoad(ssaslot->getAllocatedType(), varslot,
                        varslot->getAlign(),
                        true);
                ctx.builder.CreateAlignedStore(unbox, ssaslot, ssaslot->getAlign());
            }
            else {
                const DataLayout &DL = language_Module->getDataLayout();
                uint64_t sz = DL.getTypeStoreSize(T);
                emit_memcpy(ctx, ssaslot, language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_stack), vi.value, sz, ssaslot->getAlign().value(), varslot->getAlign().value());
            }
            Value *tindex = NULL;
            if (vi.pTIndex)
                tindex = ctx.builder.CreateAlignedLoad(getInt8Ty(ctx.builder.getContext()), vi.pTIndex, Align(1), vi.isVolatile);
            v = mark_language_slot(ssaslot, vi.value.typ, tindex, ctx.tbaa().tbaa_stack);
        }
        if (vi.boxroot == NULL)
            v = update_language_type(ctx, v, typ);
        if (vi.usedUndef) {
            assert(vi.defFlag);
            isnull = ctx.builder.CreateAlignedLoad(getInt1Ty(ctx.builder.getContext()), vi.defFlag, Align(1), vi.isVolatile);
        }
    }
    if (vi.boxroot != NULL) {
        Instruction *boxed = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, vi.boxroot, Align(sizeof(void*)), vi.isVolatile);
        Value *box_isnull = NULL;
        if (vi.usedUndef)
            box_isnull = ctx.builder.CreateICmpNE(boxed, Constant::getNullValue(ctx.types().T_prjlvalue));
        maybe_mark_load_dereferenceable(boxed, vi.usedUndef || vi.pTIndex, typ);
        if (vi.pTIndex) {
            // value is either boxed in the stack slot, or unboxed in value
            // as indicated by testing (pTIndex & UNION_BOX_MARKER)
            Value *load_unbox = ctx.builder.CreateICmpEQ(
                        ctx.builder.CreateAnd(v.TIndex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                        ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
            if (vi.usedUndef)
                isnull = ctx.builder.CreateSelect(load_unbox, isnull, box_isnull);
            if (v.V) { // v.V will be null if it is a union of all ghost values
                v.V = ctx.builder.CreateSelect(load_unbox, emit_bitcast(ctx,
                    decay_derived(ctx, v.V), boxed->getType()), decay_derived(ctx, boxed));
            } else
                v.V = boxed;
            v.Vboxed = boxed;
            v = update_language_type(ctx, v, typ);
        }
        else {
            v = mark_language_type(ctx, boxed, true, typ);
            if (vi.usedUndef)
                isnull = box_isnull;
        }
    }
    if (isnull) {
        setName(ctx.emission_context, isnull, language_symbol_name(varname) + StringRef("_is_null"));
        undef_var_error_ifnot(ctx, isnull, varname, (language_value_t*)language_local_sym);
    }
    return v;
}

static language_cgval_t emit_local(language_codectx_t &ctx, language_value_t *slotload)
{
    size_t sl = language_slot_number(slotload) - 1;
    language_varinfo_t &vi = ctx.slots[sl];
    language_sym_t *sym = slot_symbol(ctx, sl);
    if (sym == language_unused_sym) {
        // This shouldn't happen in well-formed input, but let's be robust,
        // since we otherwise cause undefined behavior here.
        emit_error(ctx, "(INTERNAL ERROR): Tried to use `#undef#` argument.");
        return language_cgval_t();
    }
    return emit_varinfo(ctx, vi, sym);
}

static void emit_vi_assignment_unboxed(language_codectx_t &ctx, language_varinfo_t &vi, Value *isboxed, language_cgval_t rval_info)
{
    if (vi.usedUndef)
        store_def_flag(ctx, vi, true);

    if (!vi.value.constant) { // check that this is not a virtual store
        assert(vi.value.ispointer() || (vi.pTIndex && vi.value.V == NULL));
        // store value
        if (vi.value.V == NULL) {
            // all ghost values in destination - nothing to copy or store
        }
        else if (rval_info.constant || !rval_info.ispointer()) {
            if (rval_info.isghost) {
                // all ghost values in source - nothing to copy or store
            }
            else {
                if (rval_info.typ != vi.value.typ && !vi.pTIndex && !rval_info.TIndex) {
                    // isbits cast-on-assignment is invalid. this branch should be dead-code.
                    CreateTrap(ctx.builder);
                }
                else {
                    Value *dest = vi.value.V;
                    if (vi.pTIndex) // TODO: use lifetime-end here instead
                        ctx.builder.CreateStore(UndefValue::get(cast<AllocaInst>(vi.value.V)->getAllocatedType()), vi.value.V);
                    Type *store_ty = language_type_to_llvm(ctx, rval_info.constant ? language_typeof(rval_info.constant) : rval_info.typ);
                    Type *dest_ty = store_ty->getPointerTo();
                    if (dest_ty != dest->getType())
                        dest = emit_bitcast(ctx, dest, dest_ty);
                    language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_stack);
                    ai.decorateInst(ctx.builder.CreateStore(
                                      emit_unbox(ctx, store_ty, rval_info, rval_info.typ),
                                      dest,
                                      vi.isVolatile));
                }
            }
        }
        else {
            if (vi.pTIndex == NULL) {
                assert(language_is_concrete_type(vi.value.typ));
                // Sometimes we can get into situations where the LHS and RHS
                // are the same slot. We're not allowed to memcpy in that case
                // due to LLVM bugs.
                // This check should probably mostly catch the relevant situations.
                if (vi.value.V != rval_info.V) {
                    Value *copy_bytes = ConstantInt::get(getInt32Ty(ctx.builder.getContext()), language_datatype_size(vi.value.typ));
                    emit_memcpy(ctx, vi.value.V, language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_stack), rval_info, copy_bytes,
                                language_alignment(rval_info.typ), language_alignment(rval_info.typ), vi.isVolatile);
                }
            }
            else {
                emit_unionmove(ctx, vi.value.V, ctx.tbaa().tbaa_stack, rval_info, /*skip*/isboxed, vi.isVolatile);
            }
        }
    }
    else {
        assert(vi.pTIndex == NULL);
    }
}

static void emit_phinode_assign(language_codectx_t &ctx, ssize_t idx, language_value_t *r)
{
    language_value_t *ssavalue_types = (language_value_t*)ctx.source->ssavaluetypes;
    language_value_t *phiType = NULL;
    if (language_is_array(ssavalue_types)) {
        phiType = language_array_ptr_ref(ssavalue_types, idx);
    } else {
        phiType = (language_value_t*)language_any_type;
    }
    language_array_t *edges = (language_array_t*)language_fieldref_noalloc(r, 0);
    BasicBlock *BB = ctx.builder.GetInsertBlock();
    auto InsertPt = BB->getFirstInsertionPt();
    if (phiType == language_bottom_type) {
        return;
    }
    AllocaInst *dest = nullptr;
    // N.B.: For any memory space, used as a phi,
    // we need to emit space twice here. The reason for this is that
    // phi nodes may be arguments of other phi nodes, so if we don't
    // have two buffers, one may be overwritten before its value is
    // used. Hopefully LLVM will be able to fold this back where legal.
    if (language_is_uniontype(phiType)) {
        bool allunbox;
        size_t min_align, nbytes;
        dest = try_emit_union_alloca(ctx, ((language_uniontype_t*)phiType), allunbox, min_align, nbytes);
        if (dest) {
            Instruction *phi = dest->clone();
            phi->insertAfter(dest);
            PHINode *Tindex_phi = PHINode::Create(getInt8Ty(ctx.builder.getContext()), language_array_nrows(edges), "tindex_phi");
            Tindex_phi->insertInto(BB, InsertPt);
            PHINode *ptr_phi = PHINode::Create(ctx.types().T_prjlvalue, language_array_nrows(edges), "ptr_phi");
            ptr_phi->insertInto(BB, InsertPt);
            Value *isboxed = ctx.builder.CreateICmpNE(
                    ctx.builder.CreateAnd(Tindex_phi, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                    ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
            ctx.builder.CreateMemCpy(phi, MaybeAlign(min_align), dest, dest->getAlign(), nbytes, false);
            ctx.builder.CreateLifetimeEnd(dest);
            Value *ptr = ctx.builder.CreateSelect(isboxed,
                maybe_bitcast(ctx, decay_derived(ctx, ptr_phi), getInt8PtrTy(ctx.builder.getContext())),
                maybe_bitcast(ctx, decay_derived(ctx, phi), getInt8PtrTy(ctx.builder.getContext())));
            language_cgval_t val = mark_language_slot(ptr, phiType, Tindex_phi, best_tbaa(ctx.tbaa(), phiType));
            val.Vboxed = ptr_phi;
            ctx.PhiNodes.push_back(std::make_tuple(val, BB, dest, ptr_phi, r));
            ctx.SAvalues[idx] = val;
            ctx.ssavalue_assigned[idx] = true;
            return;
        }
        else if (allunbox) {
            PHINode *Tindex_phi = PHINode::Create(getInt8Ty(ctx.builder.getContext()), language_array_nrows(edges), "tindex_phi");
            Tindex_phi->insertInto(BB, InsertPt);
            language_cgval_t val = mark_language_slot(NULL, phiType, Tindex_phi, ctx.tbaa().tbaa_stack);
            ctx.PhiNodes.push_back(std::make_tuple(val, BB, dest, (PHINode*)NULL, r));
            ctx.SAvalues[idx] = val;
            ctx.ssavalue_assigned[idx] = true;
            return;
        }
    }
    bool isboxed = !deserves_stack(phiType);
    Type *vtype = isboxed ? ctx.types().T_prjlvalue : language_type_to_llvm(ctx, phiType);
    // The frontend should really not emit this, but we allow it
    // for convenience.
    if (type_is_ghost(vtype)) {
        assert(language_is_datatype(phiType) && language_is_datatype_singleton((language_datatype_t*)phiType));
        // Skip adding it to the PhiNodes list, since we didn't create one.
        ctx.SAvalues[idx] = mark_language_const(ctx, ((language_datatype_t*)phiType)->instance);
        ctx.ssavalue_assigned[idx] = true;
        return;
    }
    language_cgval_t slot;
    PHINode *value_phi = NULL;
    if (vtype->isAggregateType() && CountTrackedPointers(vtype).count == 0) {
        // the value will be moved into dest in the predecessor critical block.
        // here it's moved into phi in the successor (from dest)
        dest = emit_static_alloca(ctx, vtype);
        Value *phi = emit_static_alloca(ctx, vtype);
        ctx.builder.CreateMemCpy(phi, Align(language_alignment(phiType)),
             dest, dest->getAlign(),
             language_datatype_size(phiType), false);
        ctx.builder.CreateLifetimeEnd(dest);
        slot = mark_language_slot(phi, phiType, NULL, ctx.tbaa().tbaa_stack);
    }
    else {
        value_phi = PHINode::Create(vtype, language_array_nrows(edges), "value_phi");
        value_phi->insertInto(BB, InsertPt);
        slot = mark_language_type(ctx, value_phi, isboxed, phiType);
    }
    ctx.PhiNodes.push_back(std::make_tuple(slot, BB, dest, value_phi, r));
    ctx.SAvalues[idx] = slot;
    ctx.ssavalue_assigned[idx] = true;
    return;
}

static void emit_ssaval_assign(language_codectx_t &ctx, ssize_t ssaidx_0based, language_value_t *r)
{
    assert(!ctx.ssavalue_assigned[ssaidx_0based]);
    if (language_is_phinode(r)) {
        return emit_phinode_assign(ctx, ssaidx_0based, r);
    }

    language_cgval_t slot;
    if (language_is_phicnode(r)) {
        auto it = ctx.phic_slots.find(ssaidx_0based);
        if (it == ctx.phic_slots.end()) {
            it = ctx.phic_slots.emplace(ssaidx_0based, language_varinfo_t(ctx.builder.getContext())).first;
        }
        slot = emit_varinfo(ctx, it->second, language_symbol("phic"));
    } else {
        slot = emit_expr(ctx, r, ssaidx_0based); // slot could be a language_value_t (unboxed) or language_value_t* (ispointer)
    }
    if (slot.isboxed || slot.TIndex) {
        // see if inference suggested a different type for the ssavalue than the expression
        // e.g. sometimes the information is inconsistent after inlining getfield on a Tuple
        language_value_t *ssavalue_types = (language_value_t*)ctx.source->ssavaluetypes;
        if (language_is_array(ssavalue_types)) {
            language_value_t *declType = language_array_ptr_ref(ssavalue_types, ssaidx_0based);
            if (declType != slot.typ) {
                slot = update_language_type(ctx, slot, declType);
            }
        }
    }
    ctx.SAvalues[ssaidx_0based] = slot; // now SAvalues[ssaidx_0based] contains the SAvalue
    ctx.ssavalue_assigned[ssaidx_0based] = true;
}

static void emit_varinfo_assign(language_codectx_t &ctx, language_varinfo_t &vi, language_cgval_t rval_info, language_value_t *l=NULL, bool allow_mismatch=false)
{
    if (!vi.used || vi.value.typ == language_bottom_type)
        return;

    // convert rval-type to lval-type
    language_value_t *slot_type = vi.value.typ;
    // If allow_mismatch is set, type mismatches will not result in traps.
    // This is used for upsilon nodes, where the destination can have a narrower
    // type than the store, if inference determines that the store is never read.
    Value *skip = NULL;
    rval_info = convert_language_type(ctx, rval_info, slot_type, &skip);
    if (!allow_mismatch && skip) {
        CreateTrap(ctx.builder);
        return;
    }

    if (rval_info.typ == language_bottom_type)
        return;

    // compute / store tindex info
    if (vi.pTIndex) {
        Value *tindex;
        if (rval_info.TIndex) {
            tindex = rval_info.TIndex;
            if (!vi.boxroot)
                tindex = ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), ~UNION_BOX_MARKER));
        }
        else {
            assert(rval_info.isboxed || rval_info.constant);
            tindex = compute_tindex_unboxed(ctx, rval_info, vi.value.typ);
            if (vi.boxroot)
                tindex = ctx.builder.CreateOr(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
            else
                rval_info.TIndex = tindex;
        }
        ctx.builder.CreateStore(tindex, vi.pTIndex, vi.isVolatile);
    }

    // store boxed variables
    Value *isboxed = NULL;
    if (vi.boxroot) {
        Value *rval;
        if (vi.pTIndex && rval_info.TIndex) {
            ctx.builder.CreateStore(rval_info.TIndex, vi.pTIndex, vi.isVolatile);
            isboxed = ctx.builder.CreateICmpNE(
                    ctx.builder.CreateAnd(rval_info.TIndex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                    ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
            rval = rval_info.Vboxed ? rval_info.Vboxed : Constant::getNullValue(ctx.types().T_prjlvalue);
            assert(rval->getType() == ctx.types().T_prjlvalue);
            assert(!vi.value.constant);
        }
        else {
            assert(!vi.pTIndex || rval_info.isboxed || rval_info.constant);
            rval = boxed(ctx, rval_info);
        }
        ctx.builder.CreateStore(rval, vi.boxroot, vi.isVolatile);
    }

    // store unboxed variables
    if (!vi.boxroot || (vi.pTIndex && rval_info.TIndex)) {
        emit_guarded_test(ctx, skip ? ctx.builder.CreateNot(skip) : nullptr, nullptr, [&]{
            emit_vi_assignment_unboxed(ctx, vi, isboxed, rval_info);
            return nullptr;
        });
    }

    return;
}

static void emit_assignment(language_codectx_t &ctx, language_value_t *l, language_value_t *r, ssize_t ssaval)
{
    assert(!language_is_ssavalue(l));
    language_cgval_t rval_info = emit_expr(ctx, r, ssaval);

    if (language_is_slotnumber(l)) {
        int sl = language_slot_number(l) - 1;
        // it's a local variable
        language_varinfo_t &vi = ctx.slots[sl];
        emit_varinfo_assign(ctx, vi, rval_info, l);
        return;
    }

    language_module_t *mod;
    language_sym_t *sym;
    if (language_is_symbol(l)) {
        mod = ctx.module;
        sym = (language_sym_t*)l;
    }
    else {
        assert(language_is_globalref(l));
        mod = language_globalref_mod(l);
        sym = language_globalref_name(l);
    }
    emit_globalop(ctx, mod, sym, rval_info, language_cgval_t(), AtomicOrdering::Release, AtomicOrdering::NotAtomic,
                  true, false, false, false, false, nullptr);
    // Global variable. Does not need debug info because the debugger knows about
    // its memory location.
}

static void emit_upsilonnode(language_codectx_t &ctx, ssize_t phic, language_value_t *val)
{
    auto it = ctx.phic_slots.find(phic);
    if (it == ctx.phic_slots.end()) {
        it = ctx.phic_slots.emplace(phic, language_varinfo_t(ctx.builder.getContext())).first;
    }
    language_varinfo_t &vi = it->second;
    // If the val is null, we can ignore the store.
    // The middle end guarantees that the value from this
    // upsilon node is not dynamically observed.
    if (val) {
        language_cgval_t rval_info = emit_expr(ctx, val);
        if (rval_info.typ == language_bottom_type) {
            // as a special case, PhiC nodes are allowed to use undefined
            // values, since they are just copy operations, so we need to
            // ignore the store (it will not by dynamically observed), while
            // normally, for any other operation result, we'd assume this store
            // was unreachable and dead
            val = NULL;
        }
        else {
            emit_varinfo_assign(ctx, vi, rval_info, NULL, true);
        }
    }
    if (!val) {
        if (vi.boxroot) {
            // memory optimization: eagerly clear this gc-root now
            ctx.builder.CreateAlignedStore(Constant::getNullValue(ctx.types().T_prjlvalue), vi.boxroot, Align(sizeof(void*)), true);
        }
        if (vi.pTIndex) {
            // We don't care what the contents of the variable are, but it
            // does need to satisfy the union invariants (i.e. inbounds
            // tindex).
            ctx.builder.CreateAlignedStore(
                vi.boxroot ? ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER) :
                             ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0x01),
                vi.pTIndex, Align(1), true);
        }
        else if (vi.value.V && !vi.value.constant && vi.value.typ != language_bottom_type) {
            assert(vi.value.ispointer());
            Type *T = cast<AllocaInst>(vi.value.V)->getAllocatedType();
            if (CountTrackedPointers(T).count) {
                // make sure gc pointers (including ptr_phi of union-split) are initialized to NULL
                ctx.builder.CreateStore(Constant::getNullValue(T), vi.value.V, true);
            }
        }
    }
}

// --- convert expression to code ---

static language_cgval_t emit_cfunction(language_codectx_t &ctx, language_value_t *output_type, const language_cgval_t &fexpr, language_value_t *rt, language_svec_t *argt);

static Value *emit_condition(language_codectx_t &ctx, const language_cgval_t &condV, const Twine &msg)
{
    bool isbool = (condV.typ == (language_value_t*)language_bool_type);
    if (!isbool) {
        if (condV.TIndex) {
            // check whether this might be bool
            isbool = language_subtype((language_value_t*)language_bool_type, condV.typ);
        }
        emit_typecheck(ctx, condV, (language_value_t*)language_bool_type, msg);
    }
    if (isbool) {
        Value *cond = emit_unbox(ctx, getInt1Ty(ctx.builder.getContext()), condV, (language_value_t*)language_bool_type);
        return ctx.builder.CreateNot(cond);
    }
    if (condV.isboxed) {
        return ctx.builder.CreateICmpEQ(boxed(ctx, condV),
            track_pjlvalue(ctx, literal_pointer_val(ctx, language_false)));
    }
    // not a boolean (unreachable dead code)
    return UndefValue::get(getInt1Ty(ctx.builder.getContext()));
}

static Value *emit_condition(language_codectx_t &ctx, language_value_t *cond, const Twine &msg)
{
    return emit_condition(ctx, emit_expr(ctx, cond), msg);
}

static void emit_stmtpos(language_codectx_t &ctx, language_value_t *expr, int ssaval_result)
{
    if (language_is_ssavalue(expr) && ssaval_result == -1)
        return; // value not used, no point in attempting codegen for it
    if (language_is_slotnumber(expr) && ssaval_result == -1) {
        size_t sl = language_slot_number(expr) - 1;
        language_varinfo_t &vi = ctx.slots[sl];
        if (vi.usedUndef)
            (void)emit_expr(ctx, expr);
        return;
    }
    if (language_is_argument(expr) && ssaval_result == -1) {
        return;
    }
    if (language_is_newvarnode(expr)) {
        language_value_t *var = language_fieldref(expr, 0);
        assert(language_is_slotnumber(var));
        language_varinfo_t &vi = ctx.slots[language_slot_number(var)-1];
        if (vi.usedUndef) {
            // create a new uninitialized variable
            Value *lv = vi.boxroot;
            if (lv != NULL)
                ctx.builder.CreateStore(Constant::getNullValue(ctx.types().T_prjlvalue), lv);
            if (lv == NULL || vi.pTIndex != NULL)
                store_def_flag(ctx, vi, false);
        }
        return;
    }
    if (!language_is_expr(expr)) {
        assert(ssaval_result != -1);
        emit_ssaval_assign(ctx, ssaval_result, expr);
        return;
    }
    language_expr_t *ex = (language_expr_t*)expr;
    language_value_t **args = language_array_data(ex->args, language_value_t*);
    language_sym_t *head = ex->head;
    if (head == language_meta_sym || head == language_inbounds_sym || head == language_coverageeffect_sym
            || head == language_aliasscope_sym || head == language_popaliasscope_sym || head == language_inline_sym || head == language_noinline_sym) {
        // some expression types are metadata and can be ignored
        // in statement position
        return;
    }
    else if (head == language_leave_sym) {
        int hand_n_leave = 0;
        Value *scope_to_restore = nullptr;
        Value *scope_ptr = nullptr;
        for (size_t i = 0; i < language_expr_nargs(ex); ++i) {
            language_value_t *arg = args[i];
            if (arg == language_nothing)
                continue;
            assert(language_is_ssavalue(arg));
            size_t enter_idx = ((language_ssavalue_t*)arg)->id - 1;
            language_value_t *enter_stmt = language_array_ptr_ref(ctx.code, enter_idx);
            if (enter_stmt == language_nothing)
                continue;
            if (ctx.scope_restore.count(enter_idx))
                std::tie(scope_to_restore, scope_ptr) = ctx.scope_restore[enter_idx];
            if (language_enternode_catch_dest(enter_stmt)) {
                // We're not actually setting up the exception frames for these, so
                // we don't need to exit them.
                hand_n_leave += 1;
            }
        }
        ctx.builder.CreateCall(prepare_call(jlleave_noexcept_func), {get_current_task(ctx), ConstantInt::get(getInt32Ty(ctx.builder.getContext()), hand_n_leave)});
        if (scope_to_restore) {
            language_aliasinfo_t scope_ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
            scope_ai.decorateInst(
                ctx.builder.CreateAlignedStore(scope_to_restore, scope_ptr, ctx.types().alignof_ptr));
        }
    }
    else if (head == language_pop_exception_sym) {
        language_cgval_t excstack_state = emit_expr(ctx, language_exprarg(expr, 0));
        assert(excstack_state.V && excstack_state.V->getType() == ctx.types().T_size);
        ctx.builder.CreateCall(prepare_call(language_restore_excstack_func), {get_current_task(ctx), excstack_state.V});
        return;
    }
    else {
        assert(ssaval_result != -1);
        emit_ssaval_assign(ctx, ssaval_result, expr);
    }
}

static std::pair<Function*, Function*> get_oc_function(language_codectx_t &ctx, language_method_t *closure_method, language_tupletype_t *env_t, language_tupletype_t *argt_typ, language_value_t *rettype)
{
    language_svec_t *sig_args = NULL;
    language_value_t *sigtype = NULL;
    LANGUAGE_GC_PUSH2(&sig_args, &sigtype);

    size_t nsig = 1 + language_svec_len(argt_typ->parameters);
    sig_args = language_alloc_svec_uninit(nsig);
    language_svecset(sig_args, 0, env_t);
    for (size_t i = 0; i < language_svec_len(argt_typ->parameters); ++i) {
        language_svecset(sig_args, 1+i, language_svecref(argt_typ->parameters, i));
    }
    sigtype = language_apply_tuple_type_v(language_svec_data(sig_args), nsig);

    language_method_instance_t *mi;
    language_code_instance_t *ci;

    if (closure_method->source) {
        mi = language_specializations_get_linfo(closure_method, sigtype, language_emptysvec);
        ci = (language_code_instance_t*)language_rettype_inferred_addr(mi, ctx.min_world, ctx.max_world);
    } else {
        mi = (language_method_instance_t*)language_atomic_load_relaxed(&closure_method->specializations);
        assert(language_is_method_instance(mi));
        ci = language_atomic_load_relaxed(&mi->cache);
    }

    if (ci == NULL || (language_value_t*)ci == language_nothing) {
        LANGUAGE_GC_POP();
        return std::make_pair((Function*)NULL, (Function*)NULL);
    }
    auto inferred = language_atomic_load_relaxed(&ci->inferred);
    if (!inferred || inferred == language_nothing) {
        LANGUAGE_GC_POP();
        return std::make_pair((Function*)NULL, (Function*)NULL);
    }

    auto it = ctx.emission_context.compiled_functions.find(ci);

    if (it == ctx.emission_context.compiled_functions.end()) {
        ++EmittedOpaqueClosureFunctions;
        language_code_info_t *ir = language_uncompress_ir(closure_method, ci, (language_value_t*)inferred);
        LANGUAGE_GC_PUSH1(&ir);
        // TODO: Emit this inline and outline it late using LLVM's coroutine support.
        orc::ThreadSafeModule closure_m = language_create_ts_module(
                name_from_method_instance(mi), ctx.emission_context.tsctx,
                language_Module->getDataLayout(), Triple(language_Module->getTargetTriple()));
        language_llvm_functions_t closure_decls = emit_function(closure_m, mi, ir, rettype, ctx.emission_context, ctx.min_world, ctx.max_world);
        LANGUAGE_GC_POP();
        it = ctx.emission_context.compiled_functions.insert(std::make_pair(ci, std::make_pair(std::move(closure_m), std::move(closure_decls)))).first;
    }

    auto &closure_m = it->second.first;
    auto &closure_decls = it->second.second;

    assert(closure_decls.functionObject != "language_fptr_sparam");
    bool isspecsig = closure_decls.functionObject != "language_fptr_args";

    Function *F = NULL;
    std::string fname = isspecsig ?
        closure_decls.functionObject :
        closure_decls.specFunctionObject;
    if (GlobalValue *V = language_Module->getNamedValue(fname)) {
        F = cast<Function>(V);
    } else {
        F = Function::Create(get_func_sig(ctx.builder.getContext()),
                             Function::ExternalLinkage,
                             fname, language_Module);
        language_init_function(F, ctx.emission_context.TargetTriple);
        language_name_jlfunc_args(ctx.emission_context, F);
        F->setAttributes(AttributeList::get(ctx.builder.getContext(), {get_func_attrs(ctx.builder.getContext()), F->getAttributes()}));
    }
    Function *specF = NULL;
    if (!isspecsig) {
        specF = F;
    } else {
        //emission context holds context lock so can get module
        specF = closure_m.getModuleUnlocked()->getFunction(closure_decls.specFunctionObject);
        if (specF) {
            language_returninfo_t returninfo = get_specsig_function(ctx, language_Module, NULL,
                closure_decls.specFunctionObject, sigtype, rettype, true, LANGUAGE_FEAT_TEST(ctx,gcstack_arg));
            specF = cast<Function>(returninfo.decl.getCallee());
        }
    }
    LANGUAGE_GC_POP();
    return std::make_pair(F, specF);
}

// `expr` is not clobbered in LANGUAGE_TRY
LANGUAGE_GCC_IGNORE_START("-Wclobbered")
static language_cgval_t emit_expr(language_codectx_t &ctx, language_value_t *expr, ssize_t ssaidx_0based)
{
    if (language_is_symbol(expr)) {
        language_sym_t *sym = (language_sym_t*)expr;
        return emit_globalref(ctx, ctx.module, sym, AtomicOrdering::Unordered);
    }
    if (language_is_slotnumber(expr) || language_is_argument(expr)) {
        return emit_local(ctx, expr);
    }
    if (language_is_ssavalue(expr)) {
        ssize_t idx = ((language_ssavalue_t*)expr)->id - 1;
        assert(idx >= 0);
        if (!ctx.ssavalue_assigned[idx]) {
            ctx.ssavalue_assigned[idx] = true; // (assignment, not comparison test)
            return language_cgval_t(); // dead code branch
        }
        else {
            return ctx.SAvalues[idx]; // at this point, SAvalues[idx] actually contains the SAvalue
        }
    }
    if (language_is_globalref(expr)) {
        return emit_globalref(ctx, language_globalref_mod(expr), language_globalref_name(expr), AtomicOrdering::Unordered);
    }
    if (language_is_linenode(expr)) {
        language_error("LineNumberNode in value position");
    }
    if (language_is_gotonode(expr)) {
        language_error("GotoNode in value position");
    }
    if (language_is_gotoifnot(expr)) {
        language_error("GotoIfNot in value position");
    }
    if (language_is_pinode(expr)) {
        Value *skip = NULL;
        return convert_language_type(ctx, emit_expr(ctx, language_fieldref_noalloc(expr, 0)), language_fieldref_noalloc(expr, 1), &skip);
    }
    if (!language_is_expr(expr)) {
        language_value_t *val = expr;
        if (language_is_quotenode(expr))
            val = language_fieldref_noalloc(expr, 0);
        if (language_is_method(ctx.linfo->def.method)) // toplevel exprs are already rooted
            val = language_ensure_rooted(ctx, val);
        return mark_language_const(ctx, val);
    }

    language_expr_t *ex = (language_expr_t*)expr;
    language_value_t **args = language_array_data(ex->args, language_value_t*);
    size_t nargs = language_array_nrows(ex->args);
    language_sym_t *head = ex->head;
    // this is object-disoriented.
    // however, this is a good way to do it because it should *not* be easy
    // to add new node types.
    if (head == language_isdefined_sym) {
        assert(nargs == 1);
        return emit_isdefined(ctx, args[0]);
    }
    else if (head == language_throw_undef_if_not_sym) {
        assert(nargs == 2);
        language_sym_t *var = (language_sym_t*)args[0];
        Value *cond = ctx.builder.CreateTrunc(emit_unbox(ctx, getInt8Ty(ctx.builder.getContext()), emit_expr(ctx, args[1]), (language_value_t*)language_bool_type), getInt1Ty(ctx.builder.getContext()));
        if (var == language_getfield_undefref_sym) {
            raise_exception_unless(ctx, cond,
                literal_pointer_val(ctx, language_undefref_exception));
        }
        else {
            undef_var_error_ifnot(ctx, cond, var, (language_value_t*)language_local_sym);
        }
        return ghostValue(ctx, language_nothing_type);
    }
    else if (head == language_invoke_sym) {
        assert(ssaidx_0based >= 0);
        language_value_t *expr_t = language_is_long(ctx.source->ssavaluetypes) ? (language_value_t*)language_any_type :
            language_array_ptr_ref(ctx.source->ssavaluetypes, ssaidx_0based);
        return emit_invoke(ctx, ex, expr_t);
    }
    else if (head == language_invoke_modify_sym) {
        assert(ssaidx_0based >= 0);
        language_value_t *expr_t = language_is_long(ctx.source->ssavaluetypes) ? (language_value_t*)language_any_type :
            language_array_ptr_ref(ctx.source->ssavaluetypes, ssaidx_0based);
        return emit_invoke_modify(ctx, ex, expr_t);
    }
    else if (head == language_call_sym) {
        language_value_t *expr_t;
        bool is_promotable = false;
        if (ssaidx_0based < 0)
            // TODO: this case is needed for the call to emit_expr in emit_llvmcall
            expr_t = (language_value_t*)language_any_type;
        else {
            expr_t = language_is_long(ctx.source->ssavaluetypes) ? (language_value_t*)language_any_type : language_array_ptr_ref(ctx.source->ssavaluetypes, ssaidx_0based);
            is_promotable = ctx.ssavalue_usecount[ssaidx_0based] == 1;
        }
        language_cgval_t res = emit_call(ctx, ex, expr_t, is_promotable);
        // some intrinsics (e.g. typeassert) can return a wider type
        // than what's actually possible
        if (is_promotable && res.promotion_point && res.promotion_ssa == -1) {
            res.promotion_ssa = ssaidx_0based;
        }
        res = update_language_type(ctx, res, expr_t);
        if (res.typ == language_bottom_type || expr_t == language_bottom_type) {
            CreateTrap(ctx.builder);
        }
        return res;
    }
    else if (head == language_foreigncall_sym) {
        return emit_ccall(ctx, args, language_array_dim0(ex->args));
    }
    else if (head == language_cfunction_sym) {
        assert(nargs == 5);
        language_cgval_t fexpr_rt = emit_expr(ctx, args[1]);
        return emit_cfunction(ctx, args[0], fexpr_rt, args[2], (language_svec_t*)args[3]);
    }
    else if (head == language_assign_sym) {
        assert(nargs == 2);
        emit_assignment(ctx, args[0], args[1], ssaidx_0based);
        return ghostValue(ctx, language_nothing_type);
    }
    else if (head == language_static_parameter_sym) {
        assert(nargs == 1);
        return emit_sparam(ctx, language_unbox_long(args[0]) - 1);
    }
    else if (head == language_method_sym) {
        if (nargs == 1) {
            language_value_t *mn = args[0];
            assert(language_is_symbol(mn) || language_is_slotnumber(mn));

            Value *bp = NULL, *name;
            language_binding_t *bnd = NULL;
            bool issym = language_is_symbol(mn);
            bool isglobalref = !issym && language_is_globalref(mn);
            language_module_t *mod = ctx.module;
            if (issym || isglobalref) {
                if (isglobalref) {
                    mod = language_globalref_mod(mn);
                    mn = (language_value_t*)language_globalref_name(mn);
                }
                LANGUAGE_TRY {
                    if (language_symbol_name((language_sym_t*)mn)[0] == '@')
                        language_errorf("macro definition not allowed inside a local scope");
                    name = literal_pointer_val(ctx, mn);
                    bnd = language_get_binding_for_method_def(mod, (language_sym_t*)mn);
                }
                LANGUAGE_CATCH {
                    language_value_t *e = language_current_exception(language_current_task);
                    // errors. boo. :(
                    LANGUAGE_GC_PUSH1(&e);
                    e = language_as_global_root(e, 1);
                    LANGUAGE_GC_POP();
                    raise_exception(ctx, literal_pointer_val(ctx, e));
                    return ghostValue(ctx, language_nothing_type);
                }
                bp = language_binding_gv(ctx, bnd);
                bp = language_binding_pvalue(ctx, bp);
            }
            else if (language_is_slotnumber(mn) || language_is_argument(mn)) {
                // XXX: eval_methoddef does not have this code branch
                int sl = language_slot_number(mn)-1;
                language_varinfo_t &vi = ctx.slots[sl];
                bp = vi.boxroot;
                name = literal_pointer_val(ctx, (language_value_t*)slot_symbol(ctx, sl));
            }
            if (bp) {
                Value *mdargs[] = { name, literal_pointer_val(ctx, (language_value_t*)mod), bp, literal_pointer_val(ctx, bnd) };
                language_cgval_t gf = mark_language_type(
                        ctx,
                        ctx.builder.CreateCall(prepare_call(jlgenericfunction_func), ArrayRef<Value*>(mdargs)),
                        true,
                        language_function_type);
                return gf;
            }
            emit_error(ctx, "method: invalid declaration");
            return language_cgval_t();
        }
        assert(nargs == 3);
        Value *a1 = boxed(ctx, emit_expr(ctx, args[1]));
        Value *a2 = boxed(ctx, emit_expr(ctx, args[2]));
        Value *mdargs[4] = {
            /*argdata*/a1,
            ConstantPointerNull::get(cast<PointerType>(ctx.types().T_prjlvalue)),
            /*code*/a2,
            /*module*/literal_pointer_val(ctx, (language_value_t*)ctx.module)
        };
        language_cgval_t meth = mark_language_type(
            ctx,
            ctx.builder.CreateCall(prepare_call(jlmethod_func), ArrayRef<Value*>(mdargs)),
            true,
            language_method_type);
        return meth;
    }
    else if (head == language_const_sym) {
        assert(nargs == 1);
        language_sym_t *sym = (language_sym_t*)args[0];
        language_module_t *mod = ctx.module;
        if (language_is_globalref(sym)) {
            mod = language_globalref_mod(sym);
            sym = language_globalref_name(sym);
        }
        if (language_is_symbol(sym)) {
            language_binding_t *bnd = NULL;
            Value *bp = global_binding_pointer(ctx, mod, sym, &bnd, true);
            if (bp)
                ctx.builder.CreateCall(prepare_call(jldeclareconst_func),
                        { bp, literal_pointer_val(ctx, (language_value_t*)mod), literal_pointer_val(ctx, (language_value_t*)sym) });
        }
    }
    else if (head == language_new_sym) {
        bool is_promotable = false;
        if (ssaidx_0based >= 0) {
            is_promotable = ctx.ssavalue_usecount[ssaidx_0based] == 1;
        }
        assert(nargs > 0);
        SmallVector<language_cgval_t, 0> argv(nargs);
        for (size_t i = 0; i < nargs; ++i) {
            argv[i] = emit_expr(ctx, args[i]);
        }
        language_value_t *ty = argv[0].typ;
        if (language_is_type_type(ty) &&
                language_is_datatype(language_tparam0(ty)) &&
                language_is_concrete_type(language_tparam0(ty))) {
            assert(nargs <= language_datatype_nfields(language_tparam0(ty)) + 1);
            language_cgval_t res = emit_new_struct(ctx, language_tparam0(ty), nargs - 1, ArrayRef<language_cgval_t>(argv).drop_front(), is_promotable);
            if (is_promotable && res.promotion_point && res.promotion_ssa==-1)
                res.promotion_ssa = ssaidx_0based;
            return res;
        }
        Value *val = emit_jlcall(ctx, jlnew_func, nullptr, argv, nargs, language_call);
        // temporarily mark as `Any`, expecting `emit_ssaval_assign` to update
        // it to the inferred type.
        return mark_language_type(ctx, val, true, (language_value_t*)language_any_type);
    }
    else if (head == language_splatnew_sym) {
        language_cgval_t argv[2] = {language_cgval_t(), language_cgval_t()};
        assert(nargs == 2);
        argv[0] = emit_expr(ctx, args[0]);
        argv[1] = emit_expr(ctx, args[1]);
        Value *typ = boxed(ctx, argv[0]);
        Value *tup = boxed(ctx, argv[1]);
        Value *val = ctx.builder.CreateCall(prepare_call(jlsplatnew_func), { typ, tup });
        // temporarily mark as `Any`, expecting `emit_ssaval_assign` to update
        // it to the inferred type.
        return mark_language_type(ctx, val, true, (language_value_t*)language_any_type);
    }
    else if (head == language_new_opaque_closure_sym) {
        assert(nargs >= 4 && "Not enough arguments in new_opaque_closure");
        SmallVector<language_cgval_t, 4> argv(nargs, language_cgval_t());
        for (size_t i = 0; i < nargs; ++i) {
            argv[i] = emit_expr(ctx, args[i]);
        }
        const language_cgval_t &argt = argv[0];
        const language_cgval_t &lb = argv[1];
        const language_cgval_t &ub = argv[2];
        const language_cgval_t &source = argv[3];
        if (source.constant == NULL) {
            // For now, we require non-constant source to be handled by using
            // eval. This should probably be a verifier error and an abort here.
            emit_error(ctx, "(internal error) invalid IR: opaque closure source must be constant");
            return language_cgval_t();
        }
        bool can_optimize = argt.constant != NULL && lb.constant != NULL && ub.constant != NULL &&
            language_is_tuple_type(argt.constant) &&
            language_is_type(lb.constant) && language_is_type(ub.constant) && language_is_method(source.constant) &&
            ((language_method_t*)source.constant)->nargs > 0 &&
            language_is_valid_oc_argtype((language_tupletype_t*)argt.constant, (language_method_t*)source.constant);

        if (can_optimize) {
            language_value_t *closure_t = NULL;
            language_value_t *env_t = NULL;
            LANGUAGE_GC_PUSH2(&closure_t, &env_t);

            SmallVector<language_value_t *, 0> env_component_ts(nargs-4);
            for (size_t i = 0; i < nargs - 4; ++i) {
                env_component_ts[i] = argv[4+i].typ;
            }

            env_t = language_apply_tuple_type_v(env_component_ts.data(), nargs-4);
            // we need to know the full env type to look up the right specialization
            if (language_is_concrete_type(env_t)) {
                language_tupletype_t *argt_typ = (language_tupletype_t*)argt.constant;
                Function *F, *specF;
                std::tie(F, specF) = get_oc_function(ctx, (language_method_t*)source.constant, (language_tupletype_t*)env_t, argt_typ, ub.constant);
                if (F) {
                    language_cgval_t jlcall_ptr = mark_language_type(ctx, F, false, language_voidpointer_type);
                    language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
                    Instruction *I = ctx.builder.CreateAlignedLoad(ctx.types().T_size, get_last_age_field(ctx), ctx.types().alignof_ptr);
                    language_cgval_t world_age = mark_language_type(ctx, ai.decorateInst(I), false, language_long_type);
                    language_cgval_t fptr;
                    if (specF)
                        fptr = mark_language_type(ctx, specF, false, language_voidpointer_type);
                    else
                        fptr = mark_language_type(ctx, Constant::getNullValue(ctx.types().T_size), false, language_voidpointer_type);

                    // TODO: Inline the env at the end of the opaque closure and generate a descriptor for GC
                    language_cgval_t env = emit_new_struct(ctx, env_t, nargs-4, ArrayRef<language_cgval_t>(argv).drop_front(4));

                    language_cgval_t closure_fields[5] = {
                        env,
                        world_age,
                        source,
                        jlcall_ptr,
                        fptr
                    };

                    closure_t = language_apply_type2((language_value_t*)language_opaque_closure_type, (language_value_t*)argt_typ, ub.constant);
                    language_cgval_t ret = emit_new_struct(ctx, closure_t, 5, closure_fields);

                    LANGUAGE_GC_POP();
                    return ret;
                }
            }
            LANGUAGE_GC_POP();
        }

        return mark_language_type(ctx,
                emit_jlcall(ctx, language_new_opaque_closure_jlcall_func, Constant::getNullValue(ctx.types().T_prjlvalue), argv, nargs, language_call),
                true, language_any_type);
    }
    else if (head == language_exc_sym) {
        assert(nargs == 0);
        return mark_language_type(ctx,
                ctx.builder.CreateCall(prepare_call(language_current_exception_func), {get_current_task(ctx)}),
                true, language_any_type);
    }
    else if (head == language_copyast_sym) {
        assert(nargs == 1);
        language_cgval_t ast = emit_expr(ctx, args[0]);
        if (ast.typ != (language_value_t*)language_expr_type && ast.typ != (language_value_t*)language_any_type) {
            // elide call to language_copy_ast when possible
            return ast;
        }
        return mark_language_type(ctx,
                ctx.builder.CreateCall(prepare_call(jlcopyast_func),
                                       boxed(ctx, ast)), true, language_expr_type);
    }
    else if (head == language_loopinfo_sym) {
        // parse Expr(:loopinfo, "julia.simdloop", ("llvm.loop.vectorize.width", 4))
        // to LLVM LoopID
        SmallVector<Metadata *, 8> MDs;

        // Reserve first location for self reference to the LoopID metadata node.
        TempMDTuple TempNode = MDNode::getTemporary(ctx.builder.getContext(), None);
        MDs.push_back(TempNode.get());

        for (int i = 0, ie = nargs; i < ie; ++i) {
            Metadata *MD = to_md_tree(args[i], ctx.builder.getContext());
            if (MD)
                MDs.push_back(MD);
        }

        ctx.LoopID = MDNode::getDistinct(ctx.builder.getContext(), MDs);
        // Replace the temporary node with a self-reference.
        ctx.LoopID->replaceOperandWith(0, ctx.LoopID);
        return language_cgval_t();
    }
    else if (head == language_leave_sym || head == language_coverageeffect_sym
            || head == language_pop_exception_sym || head == language_inbounds_sym
            || head == language_aliasscope_sym || head == language_popaliasscope_sym || head == language_inline_sym || head == language_noinline_sym) {
        language_errorf("Expr(:%s) in value position", language_symbol_name(head));
    }
    else if (head == language_boundscheck_sym) {
        language_value_t *def = (nargs == 0) ? language_true : args[0];
        return mark_language_const(ctx, bounds_check_enabled(ctx, def) ? language_true : language_false);
    }
    else if (head == language_gc_preserve_begin_sym) {
        SmallVector<language_cgval_t, 0> argv(nargs);
        for (size_t i = 0; i < nargs; ++i) {
            argv[i] = emit_expr(ctx, args[i]);
        }
        SmallVector<Value*, 0> vals;
        for (size_t i = 0; i < nargs; ++i) {
            vals.append(get_gc_roots_for(ctx, argv[i]));
        }
        Value *token = vals.empty()
            ? (Value*)ConstantTokenNone::get(ctx.builder.getContext())
            : ctx.builder.CreateCall(prepare_call(gc_preserve_begin_func), vals);
        language_cgval_t tok(token, (language_value_t*)language_nothing_type, NULL);
        return tok;
    }
    else if (head == language_gc_preserve_end_sym) {
        // We only support ssa values as the argument. Everything else will
        // fall back to the default behavior of preserving the argument value
        // until the end of the scope, which is correct, but not optimal.
        if (!language_is_ssavalue(args[0])) {
            return language_cgval_t((language_value_t*)language_nothing_type);
        }
        language_cgval_t token = emit_expr(ctx, args[0]);
        assert(token.V->getType()->isTokenTy());
        if (!isa<ConstantTokenNone>(token.V))
            ctx.builder.CreateCall(prepare_call(gc_preserve_end_func), {token.V});
        return language_cgval_t((language_value_t*)language_nothing_type);
    }
    else {
        if (language_is_toplevel_only_expr(expr) &&
            !language_is_method(ctx.linfo->def.method)) {
            // call interpreter to run a toplevel expr from inside a
            // compiled toplevel thunk.
            Value *args[2] = {
                literal_pointer_val(ctx, (language_value_t*)ctx.module),
                literal_pointer_val(ctx, expr)
            };
            ctx.builder.CreateCall(prepare_call(jltopeval_func), args);
            return ghostValue(ctx, language_nothing_type);
        }
        language_errorf("unsupported or misplaced expression \"%s\" in function %s",
                  language_symbol_name(head), ctx.name);
    }
    return language_cgval_t();
}
LANGUAGE_GCC_IGNORE_STOP

// --- generate function bodies ---

// gc frame emission
static void allocate_gc_frame(language_codectx_t &ctx, BasicBlock *b0, bool or_new=false)
{
    // allocate a placeholder gc instruction
    // this will require the runtime, but it gets deleted later if unused
    ctx.topalloca = ctx.builder.CreateCall(prepare_call(or_new ? jladoptthread_func : jlpgcstack_func));
    ctx.pgcstack = ctx.topalloca;
    ctx.pgcstack->setName("pgcstack");
}

static Value *get_current_task(language_codectx_t &ctx, Type *T)
{
    return emit_bitcast(ctx, get_current_task_from_pgcstack(ctx.builder, ctx.types().T_size, ctx.pgcstack), T);
}

static Value *get_current_task(language_codectx_t &ctx)
{
    return get_current_task(ctx, ctx.types().T_pjlvalue);
}

// Get PTLS through current task.
static Value *get_current_ptls(language_codectx_t &ctx)
{
    return get_current_ptls_from_task(ctx.builder, ctx.types().T_size, get_current_task(ctx), ctx.tbaa().tbaa_gcframe);
}

// Get the address of the world age of the current task
static Value *get_last_age_field(language_codectx_t &ctx)
{
    Value *ct = get_current_task(ctx, ctx.types().T_size->getPointerTo());
    return ctx.builder.CreateInBoundsGEP(
            ctx.types().T_size,
            ct,
            ConstantInt::get(ctx.types().T_size, offsetof(language_task_t, world_age) / ctx.types().sizeof_ptr),
            "world_age");
}

static Value *get_scope_field(language_codectx_t &ctx)
{
    Value *ct = get_current_task(ctx, ctx.types().T_prjlvalue->getPointerTo());
    return ctx.builder.CreateInBoundsGEP(
            ctx.types().T_prjlvalue,
            ct,
            ConstantInt::get(ctx.types().T_size, offsetof(language_task_t, scope) / ctx.types().sizeof_ptr),
            "current_scope");
}

static Function *emit_tojlinvoke(language_code_instance_t *codeinst, Module *M, language_codegen_params_t &params)
{
    ++EmittedToLANGUAGEInvokes;
    language_codectx_t ctx(M->getContext(), params, codeinst);
    std::string name;
    raw_string_ostream(name) << "tojlinvoke" << language_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
    Function *f = Function::Create(ctx.types().T_jlfunc,
            GlobalVariable::InternalLinkage,
            name, M);
    language_init_function(f, params.TargetTriple);
    language_name_jlfunc_args(params, f);
    //f->setAlwaysInline();
    ctx.f = f; // for language_Module
    BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", f);
    ctx.builder.SetInsertPoint(b0);
    Function *theFunc;
    Value *theFarg;
    auto invoke = language_atomic_load_relaxed(&codeinst->invoke);
    bool cache_valid = params.cache;

    if (cache_valid && invoke != NULL && invoke != &language_fptr_wait_for_compiled) {
        StringRef theFptrName = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)invoke, codeinst);
        theFunc = cast<Function>(
            M->getOrInsertFunction(theFptrName, jlinvoke_func->_type(ctx.builder.getContext())).getCallee());
        theFarg = literal_pointer_val(ctx, (language_value_t*)codeinst);
    }
    else {
        theFunc = prepare_call(jlinvoke_func);
        theFarg = literal_pointer_val(ctx, (language_value_t*)codeinst->def);
    }
    theFarg = track_pjlvalue(ctx, theFarg);
    auto args = f->arg_begin();
    CallInst *r = ctx.builder.CreateCall(theFunc, { &*args, &*++args, &*++args, theFarg });
    r->setAttributes(theFunc->getAttributes());
    ctx.builder.CreateRet(r);
    return f;
}

static Type *get_returnroots_type(language_codectx_t &ctx, unsigned rootcount) {
    return ArrayType::get(ctx.types().T_prjlvalue, rootcount);
}

static Type *get_unionbytes_type(LLVMContext &C, unsigned unionbytes) {
    return ArrayType::get(getInt8Ty(C), unionbytes);
}

static void emit_cfunc_invalidate(
        Function *gf_thunk, language_returninfo_t::CallingConv cc, unsigned return_roots,
        language_value_t *calltype, language_value_t *rettype, bool is_for_opaque_closure,
        size_t nargs,
        language_codegen_params_t &params,
        Function *target,
        size_t min_world, size_t max_world)
{
    ++EmittedCFuncInvalidates;
    language_codectx_t ctx(gf_thunk->getParent()->getContext(), params, min_world, max_world);
    ctx.f = gf_thunk;

    BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", gf_thunk);
    ctx.builder.SetInsertPoint(b0);
    DebugLoc noDbg;
    ctx.builder.SetCurrentDebugLocation(noDbg);
    allocate_gc_frame(ctx, b0);
    Function::arg_iterator AI = gf_thunk->arg_begin();
    SmallVector<language_cgval_t, 0> myargs(nargs);
    if (cc == language_returninfo_t::SRet || cc == language_returninfo_t::Union)
        ++AI;
    if (return_roots)
        ++AI;
    if (LANGUAGE_FEAT_TEST(ctx,gcstack_arg)){
        ++AI; // gcstack_arg
    }
    for (size_t i = 0; i < nargs; i++) {
        language_value_t *jt = language_nth_slot_type(calltype, i);
        // n.b. specTypes is required to be a datatype by construction for specsig
        bool isboxed = false;
        Type *et;
        if (i == 0 && is_for_opaque_closure) {
            et = PointerType::get(ctx.types().T_jlvalue, AddressSpace::Derived);
        }
        else if (deserves_argbox(jt)) {
            et = ctx.types().T_prjlvalue;
            isboxed = true;
        }
        else {
            et = language_type_to_llvm(ctx, jt);
        }
        if (is_uniquerep_Type(jt)) {
            myargs[i] = mark_language_const(ctx, language_tparam0(jt));
        }
        else if (type_is_ghost(et)) {
            assert(language_is_datatype(jt) && language_is_datatype_singleton((language_datatype_t*)jt));
            myargs[i] = mark_language_const(ctx, ((language_datatype_t*)jt)->instance);
        }
        else {
            Value *arg_v = &*AI;
            ++AI;
            Type *at = arg_v->getType();
            if ((i == 0 && is_for_opaque_closure) || (!isboxed && et->isAggregateType())) {
                myargs[i] = mark_language_slot(arg_v, jt, NULL, ctx.tbaa().tbaa_const);
            }
            else {
                assert(at == et);
                myargs[i] = mark_language_type(ctx, arg_v, isboxed, jt);
            }
            (void)at;
        }
    }
    assert(AI == gf_thunk->arg_end());
    Value *gf_ret = emit_jlcall(ctx, target, nullptr, myargs, nargs, language_call);
    language_cgval_t gf_retbox = mark_language_type(ctx, gf_ret, true, language_any_type);
    if (cc != language_returninfo_t::Boxed) {
        emit_typecheck(ctx, gf_retbox, rettype, "cfunction");
    }

    switch (cc) {
    case language_returninfo_t::Boxed:
        ctx.builder.CreateRet(gf_ret);
        break;
    case language_returninfo_t::Register: {
        Type *gfrt = gf_thunk->getReturnType();
        if (gfrt->isVoidTy()) {
            ctx.builder.CreateRetVoid();
        }
        else {
            gf_ret = emit_bitcast(ctx, gf_ret, gfrt->getPointerTo());
            ctx.builder.CreateRet(ctx.builder.CreateAlignedLoad(gfrt, gf_ret, Align(language_alignment(rettype))));
        }
        break;
    }
    case language_returninfo_t::SRet: {
        if (return_roots) {
            Value *root1 = gf_thunk->arg_begin() + 1; // root1 has type [n x {}*]*
            #if LANGUAGE_LLVM_VERSION < 170000
            assert(cast<PointerType>(root1->getType())->isOpaqueOrPointeeTypeMatches(get_returnroots_type(ctx, return_roots)));
            #endif
            root1 = ctx.builder.CreateConstInBoundsGEP2_32(get_returnroots_type(ctx, return_roots), root1, 0, 0);
            ctx.builder.CreateStore(gf_ret, root1);
        }
        emit_memcpy(ctx, &*gf_thunk->arg_begin(), language_aliasinfo_t::fromTBAA(ctx, nullptr), gf_ret,
                    language_aliasinfo_t::fromTBAA(ctx, nullptr), language_datatype_size(rettype), language_alignment(rettype), language_alignment(rettype));
        ctx.builder.CreateRetVoid();
        break;
    }
    case language_returninfo_t::Union: {
        Type *retty = gf_thunk->getReturnType();
        Value *gf_retval = UndefValue::get(retty);
        Value *tindex = compute_box_tindex(ctx, emit_typeof(ctx, gf_retbox, false, true), (language_value_t*)language_any_type, rettype);
        tindex = ctx.builder.CreateOr(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
        gf_retval = ctx.builder.CreateInsertValue(gf_retval, gf_ret, 0);
        gf_retval = ctx.builder.CreateInsertValue(gf_retval, tindex, 1);
        ctx.builder.CreateRet(gf_retval);
        break;
    }
    case language_returninfo_t::Ghosts: {
        Value *gf_retval = compute_tindex_unboxed(ctx, gf_retbox, rettype);
        ctx.builder.CreateRet(gf_retval);
        break;
    }
    }
}

static void emit_cfunc_invalidate(
        Function *gf_thunk, language_returninfo_t::CallingConv cc, unsigned return_roots,
        language_value_t *calltype, language_value_t *rettype, bool is_for_opaque_closure,
        size_t nargs, language_codegen_params_t &params,
        size_t min_world, size_t max_world)
{
    emit_cfunc_invalidate(gf_thunk, cc, return_roots, calltype, rettype, is_for_opaque_closure, nargs, params,
        prepare_call_in(gf_thunk->getParent(), jlapplygeneric_func), min_world, max_world);
}

static Function* gen_cfun_wrapper(
    Module *into, language_codegen_params_t &params,
    const function_sig_t &sig, language_value_t *ff, const char *aliasname,
    language_value_t *declrt, language_method_instance_t *lam,
    language_unionall_t *unionall_env, language_svec_t *sparam_vals, language_array_t **closure_types,
    size_t min_world, size_t max_world)
{
    ++GeneratedCFuncWrappers;
    // Generate a c-callable wrapper
    assert(into);
    size_t nargs = sig.nccallargs;
    const char *name = "cfunction";
    size_t world = language_atomic_load_acquire(&language_world_counter);
    language_code_instance_t *codeinst = NULL;
    bool nest = (!ff || unionall_env);
    language_value_t *astrt = (language_value_t*)language_any_type;
    void *callptr = NULL;
    int calltype = 0;
    if (aliasname)
        name = aliasname;
    else if (lam)
        name = language_symbol_name(lam->def.method->name);
    if (lam && params.cache) {
        // TODO: this isn't ideal to be unconditionally calling type inference (and compile) from here
        codeinst = language_compile_method_internal(lam, world);
        auto invoke = language_atomic_load_acquire(&codeinst->invoke);
        auto fptr = language_atomic_load_relaxed(&codeinst->specptr.fptr);
        assert(invoke);
        if (fptr) {
            while (!(language_atomic_load_acquire(&codeinst->specsigflags) & 0b10)) {
                language_cpu_pause();
            }
            invoke = language_atomic_load_relaxed(&codeinst->invoke);
        }
        // WARNING: this invoke load is protected by the codegen-lock. If that lock is removed, then the isspecsig load needs to be properly atomically sequenced with this.
        if (invoke == language_fptr_args_addr) {
            callptr = fptr;
            calltype = 1;
        }
        else if (invoke == language_fptr_const_return_addr) {
            // don't need the fptr
            callptr = (void*)codeinst->rettype_const;
            calltype = 2;
        }
        else if (language_atomic_load_relaxed(&codeinst->specsigflags) & 0b1) {
            callptr = fptr;
            calltype = 3;
        }
        astrt = codeinst->rettype;
        if (astrt != (language_value_t*)language_bottom_type &&
            language_type_intersection(astrt, declrt) == language_bottom_type) {
            // Do not warn if the function never returns since it is
            // occasionally required by the C API (typically error callbacks)
            // even though we're likely to encounter memory errors in that case
            language_printf(LANGUAGE_STDERR, "WARNING: cfunction: return type of %s does not match\n", name);
        }
    }

    std::string funcName;
    raw_string_ostream(funcName) << "jlcapi_" << name << "_" << language_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);

    Module *M = into; // Safe because ctx lock is held by params
    AttributeList attributes = sig.attributes;
    FunctionType *functype;
    if (nest) {
        // add nest parameter (pointer to language_value_t* data array) after sret arg
        assert(closure_types);
        SmallVector<Type*, 0> fargt_sig(sig.fargt_sig.begin(), sig.fargt_sig.end());

        fargt_sig.insert(fargt_sig.begin() + sig.sret, JuliaType::get_pprjlvalue_ty(M->getContext()));

        // Shift LLVM attributes for parameters one to the right, as
        // we are adding the extra nest parameter after sret arg.
        SmallVector<std::pair<unsigned, AttributeSet>, 0> newAttributes;
        newAttributes.reserve(attributes.getNumAttrSets() + 1);
        auto it = *attributes.indexes().begin();
        const auto it_end = *attributes.indexes().end();

        // Skip past FunctionIndex
        if (it == AttributeList::AttrIndex::FunctionIndex) {
            ++it;
        }

        // Move past ReturnValue and parameter return value
        for (;it < AttributeList::AttrIndex::FirstArgIndex + sig.sret; ++it) {
            if (hasAttributesAtIndex(attributes, it)) {
                newAttributes.emplace_back(it, attributes.getAttributes(it));
            }
        }

        // Add the new nest attribute
        AttrBuilder attrBuilder(M->getContext());
        attrBuilder.addAttribute(Attribute::Nest);
        newAttributes.emplace_back(it, AttributeSet::get(M->getContext(), attrBuilder));

        // Shift forward the rest of the attributes
        if (attributes.getNumAttrSets() > 0) { // without this check the loop range below is invalid
            for(; it != it_end; ++it) {
                if (hasAttributesAtIndex(attributes, it)) {
                    newAttributes.emplace_back(it + 1, attributes.getAttributes(it));
                }
            }
        }

        // Remember to add back FunctionIndex
        if (hasAttributesAtIndex(attributes, AttributeList::AttrIndex::FunctionIndex)) {
            newAttributes.emplace_back(AttributeList::AttrIndex::FunctionIndex,
                                       getFnAttrs(attributes));
        }

        // Create the new AttributeList
        attributes = AttributeList::get(M->getContext(), newAttributes);
        functype = FunctionType::get(sig.sret ? getVoidTy(M->getContext()) : sig.prt, fargt_sig, /*isVa*/false);
    }
    else {
        functype = sig.functype(M->getContext());
    }
    Function *cw = Function::Create(functype,
            GlobalVariable::ExternalLinkage,
            funcName, M);
    language_init_function(cw, params.TargetTriple);
    cw->setAttributes(AttributeList::get(M->getContext(), {attributes, cw->getAttributes()}));

    language_codectx_t ctx(M->getContext(), params, min_world, max_world);
    ctx.f = cw;
    ctx.name = name;
    ctx.funcName = name;

    BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", cw);
    ctx.builder.SetInsertPoint(b0);
    DebugLoc noDbg;
    ctx.builder.SetCurrentDebugLocation(noDbg);
    allocate_gc_frame(ctx, b0, true);

    Value *world_age_field = get_last_age_field(ctx);
    language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
    Value *last_age = ai.decorateInst(
            ctx.builder.CreateAlignedLoad(ctx.types().T_size, world_age_field, ctx.types().alignof_ptr));

    Value *world_v = ctx.builder.CreateAlignedLoad(ctx.types().T_size,
        prepare_global_in(language_Module, jlgetworld_global), ctx.types().alignof_ptr);
    cast<LoadInst>(world_v)->setOrdering(AtomicOrdering::Acquire);

    Value *age_ok = NULL;
    if (calltype) {
        LoadInst *lam_max = ctx.builder.CreateAlignedLoad(
                ctx.types().T_size,
                ctx.builder.CreateConstInBoundsGEP1_32(
                    ctx.types().T_size,
                    emit_bitcast(ctx, literal_pointer_val(ctx, (language_value_t*)codeinst), ctx.types().T_size->getPointerTo()),
                    offsetof(language_code_instance_t, max_world) / ctx.types().sizeof_ptr),
                ctx.types().alignof_ptr);
        age_ok = ctx.builder.CreateICmpUGE(lam_max, world_v);
    }
    ctx.builder.CreateStore(world_v, world_age_field);

    // first emit code to record the arguments
    Function::arg_iterator AI = cw->arg_begin();
    Value *sretPtr = sig.sret ? &*AI++ : NULL;
    Value *nestPtr = nest ? &*AI++ : NULL;
    SmallVector<language_cgval_t, 0> inputargs(nargs + 1);
    if (ff) {
        // we need to pass the function object even if (even though) it is a singleton
        inputargs[0] = mark_language_const(ctx, ff);
    }
    else {
        assert(nest && nestPtr);
        Value *ff = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, nestPtr, Align(sizeof(void*)));
        inputargs[0] = mark_language_type(ctx, ff, true, language_any_type);
    }
    // XXX: these values may need to be rooted until the end of the function
    language_value_t *rt1 = NULL;
    language_value_t *rt2 = NULL;
    LANGUAGE_GC_PUSH2(&rt1, &rt2);
    for (size_t i = 0; i < nargs; ++i, ++AI) {
        // figure out how to unpack this argument type
        Value *val = &*AI;
        assert(sig.fargt_sig[i + sig.sret] == val->getType());
        language_cgval_t &inputarg = inputargs[i + 1];
        language_value_t *jargty = language_svecref(sig.at, i);
        bool aref = language_is_abstract_ref_type(jargty);
        if (aref) // a pointer to a value
            jargty = language_tparam0(jargty);

        // if we know the outer function sparams, try to fill those in now
        // so that the language_to_native type checks are more likely to be doable (e.g. concrete types) at compile-time
        language_value_t *jargty_proper = jargty;
        bool static_at = !(unionall_env && language_has_typevar_from_unionall(jargty, unionall_env));
        if (!static_at) {
            if (sparam_vals) {
                jargty_proper = rt1 = language_instantiate_type_in_env(jargty, unionall_env, language_svec_data(sparam_vals));
                assert(jargty_proper != jargty);
                jargty = jargty_proper;
                static_at = true;
            }
            else {
                jargty_proper = rt1 = language_rewrap_unionall(jargty, (language_value_t*)unionall_env);
            }
        }

        if (aref) {
            if (jargty == (language_value_t*)language_any_type) {
                inputarg = mark_language_type(ctx,
                        ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, emit_bitcast(ctx, val, ctx.types().T_pprjlvalue), Align(sizeof(void*))),
                        true, language_any_type);
            }
            else if (static_at && language_is_concrete_immutable(jargty)) { // anything that could be stored unboxed
                bool isboxed;
                Type *T = language_type_to_llvm(ctx, jargty, &isboxed);
                assert(!isboxed);
                // a T* (of unknown origin)
                if (type_is_ghost(T)) {
                    inputarg = ghostValue(ctx, jargty);
                }
                else {
                    val = emit_bitcast(ctx, val, T->getPointerTo());
                    val = ctx.builder.CreateAlignedLoad(T, val, Align(1)); // make no alignment assumption about pointer from C
                    inputarg = mark_language_type(ctx, val, false, jargty);
                }
            }
            else if (static_at || (!language_is_typevar(jargty) && !language_is_immutable_datatype(jargty))) {
                // must be a language_value_t* (because it's mutable or contains gc roots)
                inputarg = mark_language_type(ctx, maybe_decay_untracked(ctx, emit_bitcast(ctx, val, ctx.types().T_prjlvalue)), true, jargty_proper);
            }
            else {
                // allocate val into a new box, if it might not be boxed
                // otherwise preserve / reuse the existing box identity
                // TODO: could inspect `jargty` and eliminate some of these cases
                if (!*closure_types)
                    *closure_types = language_alloc_vec_any(0);
                language_array_ptr_1d_push(*closure_types, jargty);
                Value *runtime_dt = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue,
                        ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, nestPtr, language_array_nrows(*closure_types)),
                        Align(sizeof(void*)));
                BasicBlock *boxedBB = BasicBlock::Create(ctx.builder.getContext(), "isboxed", cw);
                BasicBlock *loadBB = BasicBlock::Create(ctx.builder.getContext(), "need-load", cw);
                BasicBlock *unboxedBB = BasicBlock::Create(ctx.builder.getContext(), "maybe-unboxed", cw);
                BasicBlock *isanyBB = BasicBlock::Create(ctx.builder.getContext(), "any", cw);
                BasicBlock *afterBB = BasicBlock::Create(ctx.builder.getContext(), "after", cw);
                Value *isrtboxed = ctx.builder.CreateIsNull(val); // XXX: this is the wrong condition and should be inspecting runtime_dt instead
                ctx.builder.CreateCondBr(isrtboxed, boxedBB, loadBB);
                ctx.builder.SetInsertPoint(boxedBB);
                Value *p1 = ctx.builder.CreateBitCast(val, ctx.types().T_pjlvalue);
                p1 = track_pjlvalue(ctx, p1);
                ctx.builder.CreateBr(afterBB);
                ctx.builder.SetInsertPoint(loadBB);
                Value *isrtany = ctx.builder.CreateICmpEQ(
                        literal_pointer_val(ctx, (language_value_t*)language_any_type),
                        ctx.builder.CreateBitCast(val, ctx.types().T_pjlvalue));
                ctx.builder.CreateCondBr(isrtany, isanyBB, unboxedBB);
                ctx.builder.SetInsertPoint(isanyBB);
                Value *p2 = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, ctx.builder.CreateBitCast(val, ctx.types().T_pprjlvalue), Align(sizeof(void*)));
                ctx.builder.CreateBr(afterBB);
                ctx.builder.SetInsertPoint(unboxedBB);
                Value *p3 = emit_new_bits(ctx, runtime_dt, val);
                unboxedBB = ctx.builder.GetInsertBlock(); // could have changed
                ctx.builder.CreateBr(afterBB);
                ctx.builder.SetInsertPoint(afterBB);
                PHINode *p = ctx.builder.CreatePHI(ctx.types().T_prjlvalue, 3);
                p->addIncoming(p1, boxedBB);
                p->addIncoming(p2, isanyBB);
                p->addIncoming(p3, unboxedBB);
                inputarg = mark_language_type(ctx, p, true, jargty_proper);
            }
        }
        else {
            bool argboxed = sig.fargt_isboxed[i];
            if (argboxed) {
                // a language_value_t*, even when represented as a struct
                inputarg = mark_language_type(ctx, val, true, jargty_proper);
            }
            else {
                // something of type T
                // undo whatever we might have done to this poor argument
                assert(language_is_datatype(jargty));
                if (sig.byRefList[i]) {
                    val = ctx.builder.CreateAlignedLoad(sig.fargt[i], val, Align(1)); // unknown alignment from C
                }
                else {
                    bool issigned = language_signed_type && language_subtype(jargty_proper, (language_value_t*)language_signed_type);
                    val = llvm_type_rewrite(ctx, val, sig.fargt[i], issigned);
                }
                // passed an unboxed T, but may need something boxed (not valid to be unboxed)
                if (static_at) {
                    bool isboxed;
                    assert(jargty == jargty_proper);
                    (void)language_type_to_llvm(ctx, jargty, &isboxed);
                    if (isboxed)
                        inputarg = mark_language_type(ctx,
                                box_ccall_result(ctx, val, literal_pointer_val(ctx, jargty), jargty),
                                true, jargty_proper);
                    else
                        inputarg = mark_language_type(ctx, val, false, jargty);
                }
                else {
                    if (!*closure_types)
                        *closure_types = language_alloc_vec_any(0);
                    language_array_ptr_1d_push(*closure_types, jargty);
                    Value *runtime_dt = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue,
                            ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, nestPtr, language_array_nrows(*closure_types)),
                            Align(sizeof(void*)));
                    Value *strct = box_ccall_result(ctx, val, runtime_dt, jargty);
                    inputarg = mark_language_type(ctx, strct, true, jargty_proper);
                }
            }
        }
    }
    LANGUAGE_GC_POP();
    assert(AI == cw->arg_end());

    // Create the call
    bool jlfunc_sret;
    language_cgval_t retval;
    if (calltype == 2) {
        nargs = 0; // arguments not needed -- TODO: not really true, should emit an age_ok test and jlcall
        (void)nargs; // silence unused variable warning
        jlfunc_sret = false;
        retval = mark_language_const(ctx, (language_value_t*)callptr);
    }
    else if (calltype == 0 || calltype == 1) {
        // emit a jlcall
        jlfunc_sret = false;
        Function *theFptr = NULL;
        if (calltype == 1) {
            StringRef fname = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)callptr, codeinst);
            theFptr = cast_or_null<Function>(language_Module->getNamedValue(fname));
            if (!theFptr) {
                theFptr = Function::Create(ctx.types().T_jlfunc, GlobalVariable::ExternalLinkage,
                                           fname, language_Module);
                language_init_function(theFptr, ctx.emission_context.TargetTriple);
                language_name_jlfunc_args(ctx.emission_context, theFptr);
                addRetAttr(theFptr, Attribute::NonNull);
            }
            else {
                assert(theFptr->getFunctionType() == ctx.types().T_jlfunc);
            }
        }
        BasicBlock *b_generic, *b_jlcall, *b_after;
        Value *ret_jlcall;
        if (age_ok) {
            assert(theFptr);
            b_generic = BasicBlock::Create(ctx.builder.getContext(), "generic", cw);
            b_jlcall = BasicBlock::Create(ctx.builder.getContext(), "apply", cw);
            b_after = BasicBlock::Create(ctx.builder.getContext(), "after", cw);
            ctx.builder.CreateCondBr(age_ok, b_jlcall, b_generic);
            ctx.builder.SetInsertPoint(b_jlcall);
            // for jlcall, we need to pass the function object even if it is a ghost.
            Value *theF = boxed(ctx, inputargs[0]);
            assert(theF);
            ret_jlcall = emit_jlcall(ctx, theFptr, theF, ArrayRef<language_cgval_t>(inputargs).drop_front(), nargs, language_call);
            ctx.builder.CreateBr(b_after);
            ctx.builder.SetInsertPoint(b_generic);
        }
        Value *ret = emit_jlcall(ctx, jlapplygeneric_func, NULL, inputargs, nargs + 1, language_call);
        if (age_ok) {
            ctx.builder.CreateBr(b_after);
            ctx.builder.SetInsertPoint(b_after);
            PHINode *retphi = ctx.builder.CreatePHI(ctx.types().T_prjlvalue, 2);
            retphi->addIncoming(ret_jlcall, b_jlcall);
            retphi->addIncoming(ret, b_generic);
            ret = retphi;
        }
        retval = mark_language_type(ctx, ret, true, astrt);
    }
    else {
        bool is_opaque_closure = language_is_method(lam->def.value) && lam->def.method->is_for_opaque_closure;
        assert(calltype == 3);
        // emit a specsig call
        bool gcstack_arg = LANGUAGE_FEAT_TEST(ctx, gcstack_arg);
        StringRef protoname = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)callptr, codeinst);
        language_returninfo_t returninfo = get_specsig_function(ctx, M, NULL, protoname, lam->specTypes, astrt, is_opaque_closure, gcstack_arg);
        FunctionType *cft = returninfo.decl.getFunctionType();
        jlfunc_sret = (returninfo.cc == language_returninfo_t::SRet);

        // TODO: Can use use emit_call_specfun_other here?
        SmallVector<Value*, 0> args;
        Value *result = nullptr;
        if (jlfunc_sret || returninfo.cc == language_returninfo_t::Union) {
            // fuse the two sret together, or emit an alloca to hold it
            if (sig.sret && jlfunc_sret) {
                result = emit_bitcast(ctx, sretPtr, cft->getParamType(0));
            }
            else {
                if (jlfunc_sret) {
                    result = emit_static_alloca(ctx, getAttributeAtIndex(returninfo.attrs, 1, Attribute::StructRet).getValueAsType());
                    setName(ctx.emission_context, result, "sret");
                    #if LANGUAGE_LLVM_VERSION < 170000
                    assert(cast<PointerType>(result->getType())->hasSameElementTypeAs(cast<PointerType>(cft->getParamType(0))));
                    #endif
                } else {
                    result = emit_static_alloca(ctx, get_unionbytes_type(ctx.builder.getContext(), returninfo.union_bytes));
                    setName(ctx.emission_context, result, "result_union");
                    #if LANGUAGE_LLVM_VERSION < 170000
                    assert(cast<PointerType>(result->getType())->hasSameElementTypeAs(cast<PointerType>(cft->getParamType(0))));
                    #endif
                }
            }
            args.push_back(result);
        }
        if (returninfo.return_roots) {
            AllocaInst *return_roots = emit_static_alloca(ctx, get_returnroots_type(ctx, returninfo.return_roots));
            setName(ctx.emission_context, return_roots, "return_roots");
            args.push_back(return_roots);
        }
        if (gcstack_arg)
            args.push_back(ctx.pgcstack);
        for (size_t i = 0; i < nargs + 1; i++) {
            // figure out how to repack the arguments
            language_cgval_t &inputarg = inputargs[i];
            Value *arg;
            language_value_t *spect = (i == 0 && is_opaque_closure) ? (language_value_t*)language_any_type :
                language_nth_slot_type(lam->specTypes, i);
            // n.b. specTypes is required to be a datatype by construction for specsig
            bool isboxed = deserves_argbox(spect);
            Type *T = isboxed ? ctx.types().T_prjlvalue : language_type_to_llvm(ctx, spect);
            if (is_uniquerep_Type(spect)) {
                continue;
            }
            else if (isboxed) {
                arg = boxed(ctx, inputarg);
            }
            else if (type_is_ghost(T)) {
                continue; // ghost types are skipped by the specsig method signature
            }
            else if (T->isAggregateType()) {
                // aggregate types are passed by pointer
                inputarg = value_to_pointer(ctx, inputarg);
                arg = maybe_bitcast(ctx, decay_derived(ctx, data_pointer(ctx, inputarg)),
                    T->getPointerTo());
            }
            else {
                arg = emit_unbox(ctx, T, inputarg, spect);
                assert(!isa<UndefValue>(arg));
            }

            // add to argument list
            args.push_back(arg);
        }
        Value *theFptr = returninfo.decl.getCallee();
        assert(theFptr);
        if (age_ok) {
            funcName += "_gfthunk";
            Function *gf_thunk = Function::Create(returninfo.decl.getFunctionType(),
                    GlobalVariable::InternalLinkage, funcName, M);
            language_init_function(gf_thunk, ctx.emission_context.TargetTriple);
            gf_thunk->setAttributes(AttributeList::get(M->getContext(), {returninfo.attrs, gf_thunk->getAttributes()}));
            // build a  specsig -> language_apply_generic converter thunk
            // this builds a method that calls language_apply_generic (as a closure over a singleton function pointer),
            // but which has the signature of a specsig
            emit_cfunc_invalidate(gf_thunk, returninfo.cc, returninfo.return_roots, lam->specTypes, codeinst->rettype, is_opaque_closure, nargs + 1, ctx.emission_context,
                min_world, max_world);
            theFptr = ctx.builder.CreateSelect(age_ok, theFptr, gf_thunk);
        }

        #if LANGUAGE_LLVM_VERSION < 170000
        assert(cast<PointerType>(theFptr->getType())->isOpaqueOrPointeeTypeMatches(returninfo.decl.getFunctionType()));
        #endif
        CallInst *call = ctx.builder.CreateCall(
            returninfo.decl.getFunctionType(),
            theFptr, ArrayRef<Value*>(args));
        call->setAttributes(returninfo.attrs);
        if (gcstack_arg)
            call->setCallingConv(CallingConv::Swift);

        switch (returninfo.cc) {
            case language_returninfo_t::Boxed:
                retval = mark_language_type(ctx, call, true, astrt);
                break;
            case language_returninfo_t::Register:
                retval = mark_language_type(ctx, call, false, astrt);
                break;
            case language_returninfo_t::SRet:
                retval = mark_language_slot(result, astrt, NULL, ctx.tbaa().tbaa_stack);
                break;
            case language_returninfo_t::Union: {
                Value *box = ctx.builder.CreateExtractValue(call, 0);
                Value *tindex = ctx.builder.CreateExtractValue(call, 1);
                Value *derived = ctx.builder.CreateSelect(
                    ctx.builder.CreateICmpEQ(
                            ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                            ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0)),
                    decay_derived(ctx, ctx.builder.CreateBitCast(result, ctx.types().T_pjlvalue)),
                    decay_derived(ctx, box));
                retval = mark_language_slot(derived,
                                         astrt,
                                         tindex,
                                         ctx.tbaa().tbaa_stack);
                assert(box->getType() == ctx.types().T_prjlvalue);
                retval.Vboxed = box;
                break;
            }
            case language_returninfo_t::Ghosts:
                retval = mark_language_slot(NULL, astrt, call, ctx.tbaa().tbaa_stack);
                break;
        }
    }

    // inline a call to typeassert here, if required
    emit_typecheck(ctx, retval, declrt, "cfunction");
    retval = update_language_type(ctx, retval, declrt);

    // Prepare the return value
    Value *r;
    if (sig.retboxed) {
        assert(!sig.sret);
        // return a language_value_t*
        r = boxed(ctx, retval);
    }
    else if (sig.sret && jlfunc_sret) {
        // nothing to do
        r = NULL;
    }
    else if (!type_is_ghost(sig.lrt)) {
        Type *prt = sig.prt;
        bool issigned = language_signed_type && language_subtype(declrt, (language_value_t*)language_signed_type);
        Value *v = emit_unbox(ctx, sig.lrt, retval, retval.typ);
        r = llvm_type_rewrite(ctx, v, prt, issigned);
        if (sig.sret) {
            ctx.builder.CreateStore(r, sretPtr);
            r = NULL;
        }
    }
    else {
        r = NULL;
    }

    ctx.builder.CreateStore(last_age, world_age_field);
    ctx.builder.CreateRet(r);

    ctx.builder.SetCurrentDebugLocation(noDbg);
    ctx.builder.ClearInsertionPoint();

    if (aliasname) {
        GlobalAlias::create(cw->getValueType(), cw->getType()->getAddressSpace(),
                            GlobalValue::ExternalLinkage, aliasname, cw, M);
    }

    if (nest) {
        funcName += "make";
        Function *cw_make = Function::Create(
                FunctionType::get(getInt8PtrTy(ctx.builder.getContext()), { getInt8PtrTy(ctx.builder.getContext()), ctx.types().T_ppjlvalue }, false),
                GlobalVariable::ExternalLinkage,
                funcName, M);
        language_init_function(cw_make, ctx.emission_context.TargetTriple);
        cw_make->getArg(0)->setName("wrapper");
        cw_make->getArg(1)->setName("newval");
        BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", cw_make);
        IRBuilder<> cwbuilder(b0);
        Function::arg_iterator AI = cw_make->arg_begin();
        Argument *Tramp = &*AI; ++AI;
        Argument *NVal = &*AI; ++AI;
        Function *init_trampoline = Intrinsic::getDeclaration(cw_make->getParent(), Intrinsic::init_trampoline);
        Function *adjust_trampoline = Intrinsic::getDeclaration(cw_make->getParent(), Intrinsic::adjust_trampoline);
        cwbuilder.CreateCall(init_trampoline, {
                Tramp,
                cwbuilder.CreateBitCast(cw, getInt8PtrTy(ctx.builder.getContext())),
                cwbuilder.CreateBitCast(NVal, getInt8PtrTy(ctx.builder.getContext()))
            });
        cwbuilder.CreateRet(cwbuilder.CreateCall(adjust_trampoline, { Tramp }));
        cw = cw_make;
    }

    return cw;
}

// Get the LLVM Function* for the C-callable entry point for a certain function
// and argument types.
// here argt does not include the leading function type argument
static language_cgval_t emit_cfunction(language_codectx_t &ctx, language_value_t *output_type, const language_cgval_t &fexpr_rt, language_value_t *declrt, language_svec_t *argt)
{
    language_unionall_t *unionall_env = (language_is_method(ctx.linfo->def.method) && language_is_unionall(ctx.linfo->def.method->sig))
        ? (language_unionall_t*)ctx.linfo->def.method->sig
        : NULL;
    language_svec_t *sparam_vals = NULL;
    if (ctx.spvals_ptr == NULL && language_svec_len(ctx.linfo->sparam_vals) > 0)
        sparam_vals = ctx.linfo->sparam_vals;

    language_value_t *rt = declrt;
    if (language_is_abstract_ref_type(declrt)) {
        declrt = language_tparam0(declrt);
        if (!verify_ref_type(ctx, declrt, unionall_env, 0, "cfunction")) {
            return language_cgval_t();
        }
        if (unionall_env)
            declrt = language_rewrap_unionall(declrt, (language_value_t*)unionall_env);
        rt = (language_value_t*)language_any_type; // convert return type to language_value_t*
    }

    // some sanity checking and check whether there's a vararg
    size_t nargt = language_svec_len(argt);
    bool isVa = (nargt > 0 && language_is_vararg(language_svecref(argt, nargt - 1)));
    assert(!isVa); (void)isVa;

    language_array_t *closure_types = NULL;
    language_value_t *sigt = NULL; // dispatch-sig = type signature with Ref{} annotations removed and applied to the env
    LANGUAGE_GC_PUSH4(&declrt, &sigt, &rt, &closure_types);
    Type *lrt;
    bool retboxed;
    bool static_rt;
    const std::string err = verify_ccall_sig(
            /* inputs:  */
            rt, (language_value_t*)argt, unionall_env,
            sparam_vals,
            &ctx.emission_context,
            /* outputs: */
            lrt, ctx.builder.getContext(),
            retboxed, static_rt);
    if (!err.empty()) {
        emit_error(ctx, "cfunction " + err);
        LANGUAGE_GC_POP();
        return language_cgval_t();
    }
    if (rt != declrt && rt != (language_value_t*)language_any_type)
        rt = language_ensure_rooted(ctx, rt);

    function_sig_t sig("cfunction", lrt, rt, retboxed, argt, unionall_env, false, CallingConv::C, false, &ctx.emission_context);
    assert(sig.fargt.size() + sig.sret == sig.fargt_sig.size());
    if (!sig.err_msg.empty()) {
        emit_error(ctx, sig.err_msg);
        LANGUAGE_GC_POP();
        return language_cgval_t();
    }

    // compute+verify the dispatch signature, and see if it depends on the environment sparams
    bool approx = false;
    sigt = (language_value_t*)language_alloc_svec(nargt + 1);
    language_svecset(sigt, 0, fexpr_rt.typ);
    if (!fexpr_rt.constant && (!language_is_concrete_type(fexpr_rt.typ) || language_is_kind(fexpr_rt.typ)))
        approx = true;
    for (size_t i = 0; i < nargt; i++) {
        language_value_t *jargty = language_svecref(argt, i);
        if (language_is_abstract_ref_type(jargty)) {
            jargty = language_tparam0(jargty);
            if (!verify_ref_type(ctx, jargty, unionall_env, i + 1, "cfunction")) {
                LANGUAGE_GC_POP();
                return language_cgval_t();
            }
        }
        if (unionall_env && language_has_typevar_from_unionall(jargty, unionall_env)) {
            if (sparam_vals)
                jargty = language_instantiate_type_in_env(jargty, unionall_env, language_svec_data(sparam_vals));
            else
                approx = true;
        }
        language_svecset(sigt, i + 1, jargty);
    }
    if (approx) {
        sigt = NULL;
    }
    else {
        sigt = language_apply_tuple_type((language_svec_t*)sigt, 1);
    }
    if (sigt && !(unionall_env && language_has_typevar_from_unionall(rt, unionall_env))) {
        unionall_env = NULL;
    }

    bool nest = (!fexpr_rt.constant || unionall_env);
    if (ctx.emission_context.TargetTriple.isAArch64() || ctx.emission_context.TargetTriple.isARM() || ctx.emission_context.TargetTriple.isPPC64()) {
        if (nest) {
            emit_error(ctx, "cfunction: closures are not supported on this platform");
            LANGUAGE_GC_POP();
            return language_cgval_t();
        }
    }
    size_t world = language_atomic_load_acquire(&language_world_counter);
    size_t min_valid = 0;
    size_t max_valid = ~(size_t)0;
    // try to look up this function for direct invoking
    language_method_instance_t *lam = sigt ? language_get_specialization1((language_tupletype_t*)sigt, world, &min_valid, &max_valid, 0) : NULL;
    Value *F = gen_cfun_wrapper(
            language_Module, ctx.emission_context,
            sig, fexpr_rt.constant, NULL,
            declrt, lam,
            unionall_env, sparam_vals, &closure_types, min_valid, max_valid);
    bool outboxed;
    if (nest) {
        // F is actually an init_trampoline function that returns the real address
        // Now fill in the nest parameters
        Value *fobj = boxed(ctx, fexpr_rt);
        language_svec_t *fill = language_emptysvec;
        if (closure_types) {
            assert(ctx.spvals_ptr);
            size_t n = language_array_nrows(closure_types);
            language_svec_t *fill_i = language_alloc_svec_uninit(n);
            for (size_t i = 0; i < n; i++) {
                language_svecset(fill_i, i, language_array_ptr_ref(closure_types, i));
            }
            LANGUAGE_GC_PUSH1(&fill_i);
            fill = (language_svec_t*)language_ensure_rooted(ctx, (language_value_t*)fill_i);
            LANGUAGE_GC_POP();
        }
        Type *T_htable = ArrayType::get(ctx.types().T_size, sizeof(htable_t) / sizeof(void*));
        Value *cache = new GlobalVariable(*language_Module, T_htable, false,
                               GlobalVariable::PrivateLinkage,
                               ConstantAggregateZero::get(T_htable));
        F = ctx.builder.CreateCall(prepare_call(jlgetcfunctiontrampoline_func), {
                 fobj,
                 literal_pointer_val(ctx, output_type),
                 ctx.builder.CreateBitCast(cache, getInt8PtrTy(ctx.builder.getContext())),
                 literal_pointer_val(ctx, (language_value_t*)fill),
                 F,
                 closure_types ? literal_pointer_val(ctx, (language_value_t*)unionall_env) : Constant::getNullValue(ctx.types().T_pjlvalue),
                 closure_types ? ctx.spvals_ptr : ConstantPointerNull::get(cast<PointerType>(ctx.types().T_pprjlvalue))
             });
        outboxed = true;
    }
    else {
        F = ctx.builder.CreatePtrToInt(F, ctx.types().T_size);
        outboxed = (output_type != (language_value_t*)language_voidpointer_type);
        if (outboxed) {
            assert(language_datatype_size(output_type) == sizeof(void*) * 4);
            Value *strct = emit_allocobj(ctx, (language_datatype_t*)output_type, true);
            setName(ctx.emission_context, strct, "cfun_result");
            Value *derived_strct = emit_bitcast(ctx, decay_derived(ctx, strct), ctx.types().T_size->getPointerTo());
            MDNode *tbaa = best_tbaa(ctx.tbaa(), output_type);
            language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, tbaa);
            ai.decorateInst(ctx.builder.CreateStore(F, derived_strct));
            ai.decorateInst(ctx.builder.CreateStore(
                ctx.builder.CreatePtrToInt(literal_pointer_val(ctx, fexpr_rt.constant), ctx.types().T_size),
                ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_size, derived_strct, 1)));
            ai.decorateInst(ctx.builder.CreateStore(Constant::getNullValue(ctx.types().T_size),
                    ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_size, derived_strct, 2)));
            ai.decorateInst(ctx.builder.CreateStore(Constant::getNullValue(ctx.types().T_size),
                    ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_size, derived_strct, 3)));
            F = strct;
        }
    }
    LANGUAGE_GC_POP();
    return mark_language_type(ctx, F, outboxed, output_type);
}

// do codegen to create a C-callable alias/wrapper, or if sysimg_handle is set,
// restore one from a loaded system image.
const char *language_generate_ccallable(LLVMOrcThreadSafeModuleRef llvmmod, void *sysimg_handle, language_value_t *declrt, language_value_t *sigt, language_codegen_params_t &params)
{
    ++GeneratedCCallables;
    language_datatype_t *ft = (language_datatype_t*)language_tparam0(sigt);
    language_value_t *ff = ft->instance;
    assert(ff);
    const char *name = language_symbol_name(ft->name->mt->name);
    language_value_t *crt = declrt;
    if (language_is_abstract_ref_type(declrt)) {
        declrt = language_tparam0(declrt);
        crt = (language_value_t*)language_any_type;
    }
    bool toboxed;
    Type *lcrt = _language_struct_to_llvm(&params, *params.tsctx.getContext(), crt, &toboxed);
    if (toboxed)
        lcrt = JuliaType::get_prjlvalue_ty(lcrt->getContext());
    size_t nargs = language_nparams(sigt)-1;
    language_svec_t *argtypes = NULL;
    LANGUAGE_GC_PUSH1(&argtypes);
    argtypes = language_alloc_svec(nargs);
    for (size_t i = 0; i < nargs; i++) {
        language_svecset(argtypes, i, language_tparam(sigt, i+1));
    }
    language_value_t *err;
    { // scope block for sig
        function_sig_t sig("cfunction", lcrt, crt, toboxed,
                           argtypes, NULL, false, CallingConv::C, false, &params);
        if (sig.err_msg.empty()) {
            size_t world = language_atomic_load_acquire(&language_world_counter);
            size_t min_valid = 0;
            size_t max_valid = ~(size_t)0;
            if (sysimg_handle) {
                // restore a ccallable from the system image
                void *addr;
                int found = language_dlsym(sysimg_handle, name, &addr, 0);
                if (found)
                    add_named_global(name, addr);
                else {
                    err = language_get_exceptionf(language_errorexception_type, "%s not found in sysimg", name);
                    language_throw(err);
                }
            }
            else {
                language_method_instance_t *lam = language_get_specialization1((language_tupletype_t*)sigt, world, &min_valid, &max_valid, 0);
                //Safe b/c params holds context lock
                gen_cfun_wrapper(unwrap(llvmmod)->getModuleUnlocked(), params, sig, ff, name, declrt, lam, NULL, NULL, NULL, min_valid, max_valid);
            }
            LANGUAGE_GC_POP();
            return name;
        }
        err = language_get_exceptionf(language_errorexception_type, "%s", sig.err_msg.c_str());
    }
    language_throw(err);
}

// generate a julia-callable function that calls f (AKA lam)
static Function *gen_invoke_wrapper(language_method_instance_t *lam, language_value_t *jlretty, const language_returninfo_t &f, int retarg, StringRef funcName,
        Module *M, language_codegen_params_t &params)
{
    ++GeneratedInvokeWrappers;
    Function *w = Function::Create(get_func_sig(M->getContext()), GlobalVariable::ExternalLinkage, funcName, M);
    language_init_function(w, params.TargetTriple);
    language_name_jlfunc_args(params, w);
    w->setAttributes(AttributeList::get(M->getContext(), {get_func_attrs(M->getContext()), w->getAttributes()}));
    w->addFnAttr(Attribute::OptimizeNone);
    w->addFnAttr(Attribute::NoInline);
    Function::arg_iterator AI = w->arg_begin();
    Value *funcArg = &*AI++;
    Value *argArray = &*AI++;
    Value *argCount = &*AI++; (void)argCount; // unused
    //Value *mfunc = &*AI++; (void)mfunc; // unused
    assert(AI == w->arg_end());

    language_codectx_t ctx(M->getContext(), params, 0, 0);
    ctx.f = w;
    ctx.linfo = lam;
    ctx.rettype = jlretty;

    BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", w);
    ctx.builder.SetInsertPoint(b0);
    DebugLoc noDbg;
    ctx.builder.SetCurrentDebugLocation(noDbg);
    allocate_gc_frame(ctx, b0);

    // TODO: replace this with emit_call_specfun_other?
    FunctionType *ftype = const_cast<llvm::FunctionCallee&>(f.decl).getFunctionType();
    size_t nfargs = ftype->getNumParams();
    SmallVector<Value *, 0> args(nfargs);
    unsigned idx = 0;
    AllocaInst *result = NULL;
    switch (f.cc) {
    case language_returninfo_t::Boxed:
    case language_returninfo_t::Register:
    case language_returninfo_t::Ghosts:
        break;
    case language_returninfo_t::SRet:
        #if LANGUAGE_LLVM_VERSION < 170000
        assert(cast<PointerType>(ftype->getParamType(0))->isOpaqueOrPointeeTypeMatches(getAttributeAtIndex(f.attrs, 1, Attribute::StructRet).getValueAsType()));
        #endif
        result = ctx.builder.CreateAlloca(getAttributeAtIndex(f.attrs, 1, Attribute::StructRet).getValueAsType());
        setName(ctx.emission_context, result, "sret");
        args[idx] = result;
        idx++;
        break;
    case language_returninfo_t::Union:
        result = ctx.builder.CreateAlloca(ArrayType::get(getInt8Ty(ctx.builder.getContext()), f.union_bytes));
        if (f.union_align > 1)
            result->setAlignment(Align(f.union_align));
        args[idx] = result;
        idx++;
        setName(ctx.emission_context, result, "result_union");
        break;
    }
    if (f.return_roots) {
        AllocaInst *return_roots = emit_static_alloca(ctx, ArrayType::get(ctx.types().T_prjlvalue, f.return_roots));
        setName(ctx.emission_context, return_roots, "return_roots");
        args[idx] = return_roots;
        idx++;
    }
    bool gcstack_arg = LANGUAGE_FEAT_TEST(ctx, gcstack_arg);
    if (gcstack_arg) {
        args[idx] = ctx.pgcstack;
        idx++;
    }
    bool is_opaque_closure = language_is_method(lam->def.value) && lam->def.method->is_for_opaque_closure;
    for (size_t i = 0; i < language_nparams(lam->specTypes) && idx < nfargs; ++i) {
        language_value_t *ty = ((i == 0) && is_opaque_closure) ? (language_value_t*)language_any_type :
            language_nth_slot_type(lam->specTypes, i);
        // n.b. specTypes is required to be a datatype by construction for specsig
        bool isboxed = deserves_argbox(ty);
        Type *lty = isboxed ?  ctx.types().T_prjlvalue : language_type_to_llvm(ctx, ty);
        if (type_is_ghost(lty) || is_uniquerep_Type(ty))
            continue;
        Value *theArg;
        if (i == 0) {
            // This function adapts from generic jlcall to OC specsig. Generic jlcall pointers
            // come in as ::Tracked, but specsig expected ::Derived.
            if (is_opaque_closure)
                theArg = decay_derived(ctx, funcArg);
            else
                theArg = funcArg;
        }
        else {
            Value *argPtr = ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, argArray, i - 1);
            language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
            theArg = ai.decorateInst(maybe_mark_load_dereferenceable(
                    ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, argPtr, Align(sizeof(void*))),
                    false,
                    ty));
        }
        if (!isboxed) {
            theArg = decay_derived(ctx, emit_bitcast(ctx, theArg, PointerType::get(lty, 0)));
            if (!lty->isAggregateType()) // keep "aggregate" type values in place as pointers
                theArg = ctx.builder.CreateAlignedLoad(lty, theArg, Align(language_alignment(ty)));
        }
        assert(!isa<UndefValue>(theArg));
        args[idx] = theArg;
        idx++;
    }
    CallInst *call = ctx.builder.CreateCall(f.decl, args);
    call->setAttributes(f.attrs);
    if (gcstack_arg)
        call->setCallingConv(CallingConv::Swift);
    language_cgval_t retval;
    if (retarg != -1) {
        Value *theArg;
        if (retarg == 0)
            theArg = funcArg;
        else
            theArg = ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue,
                    ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, argArray, retarg - 1),
                    Align(sizeof(void*)));
        retval = mark_language_type(ctx, theArg, true, language_any_type);
    }
    else {
        switch (f.cc) {
        case language_returninfo_t::Boxed:
            retval = mark_language_type(ctx, call, true, jlretty);
            break;
        case language_returninfo_t::Register:
            retval = mark_language_type(ctx, call, false, jlretty);
            break;
        case language_returninfo_t::SRet:
            retval = mark_language_slot(result, jlretty, NULL, ctx.tbaa().tbaa_stack);
            break;
        case language_returninfo_t::Union:
            // result is technically not right here, but `boxed` will only look at it
            // for the unboxed values, so it's ok.
            retval = mark_language_slot(result,
                                     jlretty,
                                     ctx.builder.CreateExtractValue(call, 1),
                                     ctx.tbaa().tbaa_stack);
            retval.Vboxed = ctx.builder.CreateExtractValue(call, 0);
            assert(retval.Vboxed->getType() == ctx.types().T_prjlvalue);
            break;
        case language_returninfo_t::Ghosts:
            retval = mark_language_slot(NULL, jlretty, call, ctx.tbaa().tbaa_stack);
            break;
        }
    }
    ctx.builder.CreateRet(boxed(ctx, retval));
    return w;
}

static language_returninfo_t get_specsig_function(language_codectx_t &ctx, Module *M, Value *fval, StringRef name, language_value_t *sig, language_value_t *jlrettype, bool is_opaque_closure, bool gcstack_arg, BitVector *used_arguments, size_t *arg_offset)
{
    language_returninfo_t props = {};
    SmallVector<Type*, 8> fsig;
    SmallVector<std::string, 4> argnames;
    Type *rt = NULL;
    Type *srt = NULL;
    if (jlrettype == (language_value_t*)language_bottom_type) {
        rt = getVoidTy(ctx.builder.getContext());
        props.cc = language_returninfo_t::Register;
    }
    else if (language_is_structtype(jlrettype) && language_is_datatype_singleton((language_datatype_t*)jlrettype)) {
        rt = getVoidTy(ctx.builder.getContext());
        props.cc = language_returninfo_t::Register;
    }
    else if (language_is_uniontype(jlrettype)) {
        bool allunbox;
        union_alloca_type((language_uniontype_t*)jlrettype, allunbox, props.union_bytes, props.union_align, props.union_minalign);
        if (props.union_bytes) {
            props.cc = language_returninfo_t::Union;
            Type *AT = ArrayType::get(getInt8Ty(ctx.builder.getContext()), props.union_bytes);
            fsig.push_back(AT->getPointerTo());
            argnames.push_back("union_bytes_return");
            Type *pair[] = { ctx.types().T_prjlvalue, getInt8Ty(ctx.builder.getContext()) };
            rt = StructType::get(ctx.builder.getContext(), ArrayRef<Type*>(pair));
        }
        else if (allunbox) {
            props.cc = language_returninfo_t::Ghosts;
            rt = getInt8Ty(ctx.builder.getContext());
        }
        else {
            rt = ctx.types().T_prjlvalue;
        }
    }
    else if (!deserves_retbox(jlrettype)) {
        bool retboxed;
        rt = language_type_to_llvm(ctx, jlrettype, &retboxed);
        assert(!retboxed);
        if (rt != getVoidTy(ctx.builder.getContext()) && deserves_sret(jlrettype, rt)) {
            auto tracked = CountTrackedPointers(rt, true);
            assert(!tracked.derived);
            if (tracked.count && !tracked.all)
                props.return_roots = tracked.count;
            props.cc = language_returninfo_t::SRet;
            // sret is always passed from alloca
            assert(M);
            fsig.push_back(rt->getPointerTo(M->getDataLayout().getAllocaAddrSpace()));
            argnames.push_back("sret_return");
            srt = rt;
            rt = getVoidTy(ctx.builder.getContext());
        }
        else {
            props.cc = language_returninfo_t::Register;
        }
    }
    else {
        rt = ctx.types().T_prjlvalue;
    }

    SmallVector<AttributeSet, 8> attrs; // function declaration attributes
    if (props.cc == language_returninfo_t::SRet) {
        assert(srt);
        AttrBuilder param(ctx.builder.getContext());
        param.addStructRetAttr(srt);
        param.addAttribute(Attribute::NoAlias);
        param.addAttribute(Attribute::NoCapture);
        param.addAttribute(Attribute::NoUndef);
        attrs.push_back(AttributeSet::get(ctx.builder.getContext(), param));
        assert(fsig.size() == 1);
    }
    if (props.cc == language_returninfo_t::Union) {
        AttrBuilder param(ctx.builder.getContext());
        param.addAttribute(Attribute::NoAlias);
        param.addAttribute(Attribute::NoCapture);
        param.addAttribute(Attribute::NoUndef);
        attrs.push_back(AttributeSet::get(ctx.builder.getContext(), param));
        assert(fsig.size() == 1);
    }

    if (props.return_roots) {
        AttrBuilder param(ctx.builder.getContext());
        param.addAttribute(Attribute::NoAlias);
        param.addAttribute(Attribute::NoCapture);
        param.addAttribute(Attribute::NoUndef);
        attrs.push_back(AttributeSet::get(ctx.builder.getContext(), param));
        fsig.push_back(get_returnroots_type(ctx, props.return_roots)->getPointerTo(0));
        argnames.push_back("return_roots");
    }

    if (gcstack_arg){
        AttrBuilder param(ctx.builder.getContext());
        param.addAttribute(Attribute::SwiftSelf);
        param.addAttribute(Attribute::NonNull);
        attrs.push_back(AttributeSet::get(ctx.builder.getContext(), param));
        fsig.push_back(PointerType::get(JuliaType::get_ppjlvalue_ty(ctx.builder.getContext()), 0));
        argnames.push_back("pgcstack_arg");
    }

    if (arg_offset)
        *arg_offset = fsig.size();
    size_t nparams = language_nparams(sig);
    if (used_arguments)
        used_arguments->resize(nparams);

    for (size_t i = 0; i < nparams; i++) {
        language_value_t *jt = language_tparam(sig, i);
        bool isboxed = false;
        Type *ty = NULL;
        if (i == 0 && is_opaque_closure) {
            ty = PointerType::get(ctx.types().T_jlvalue, AddressSpace::Derived);
            isboxed = true; // true-ish anyway - we might not have the type tag
        }
        else {
            if (is_uniquerep_Type(jt))
                continue;
            isboxed = deserves_argbox(jt);
            ty = isboxed ? ctx.types().T_prjlvalue : language_type_to_llvm(ctx, jt);
        }
        if (type_is_ghost(ty))
            continue;
        AttrBuilder param(ctx.builder.getContext());
        if (ty->isAggregateType()) { // aggregate types are passed by pointer
            param.addAttribute(Attribute::NoCapture);
            param.addAttribute(Attribute::ReadOnly);
            ty = PointerType::get(ty, AddressSpace::Derived);
        }
        else if (isboxed && language_is_immutable_datatype(jt)) {
            param.addAttribute(Attribute::ReadOnly);
        }
        else if (language_is_primitivetype(jt) && ty->isIntegerTy()) {
            bool issigned = language_signed_type && language_subtype(jt, (language_value_t*)language_signed_type);
            Attribute::AttrKind attr = issigned ? Attribute::SExt : Attribute::ZExt;
            param.addAttribute(attr);
        }
        attrs.push_back(AttributeSet::get(ctx.builder.getContext(), param));
        fsig.push_back(ty);
        if (used_arguments)
            used_arguments->set(i);
    }

    AttributeSet FnAttrs;
    AttributeSet RetAttrs;
    if (jlrettype == (language_value_t*)language_bottom_type)
        FnAttrs = FnAttrs.addAttribute(ctx.builder.getContext(), Attribute::NoReturn);
    else if (rt == ctx.types().T_prjlvalue)
        RetAttrs = RetAttrs.addAttribute(ctx.builder.getContext(), Attribute::NonNull);
    AttributeList attributes = AttributeList::get(ctx.builder.getContext(), FnAttrs, RetAttrs, attrs);

    FunctionType *ftype = FunctionType::get(rt, fsig, false);
    if (fval == NULL) {
        Function *f = M ? cast_or_null<Function>(M->getNamedValue(name)) : NULL;
        if (f == NULL) {
            f = Function::Create(ftype, GlobalVariable::ExternalLinkage, name, M);
            language_init_function(f, ctx.emission_context.TargetTriple);
            if (ctx.emission_context.debug_level >= 2) {
                ios_t sigbuf;
                ios_mem(&sigbuf, 0);
                language_static_show_func_sig((LANGUAGE_STREAM*) &sigbuf, sig);
                f->setAttributes(AttributeList::get(f->getContext(), {attributes.addFnAttribute(ctx.builder.getContext(),"julia.fsig", StringRef(sigbuf.buf, sigbuf.size)), f->getAttributes()}));
                ios_close(&sigbuf);
            } else
                f->setAttributes(AttributeList::get(f->getContext(), {attributes, f->getAttributes()}));
        }
        else {
            assert(f->getFunctionType() == ftype);
        }
        fval = f;
    }
    else {
        if (fval->getType()->isIntegerTy())
            fval = emit_inttoptr(ctx, fval, ftype->getPointerTo());
        else
            fval = emit_bitcast(ctx, fval, ftype->getPointerTo());
    }
    if (auto F = dyn_cast<Function>(fval)) {
        if (gcstack_arg)
            F->setCallingConv(CallingConv::Swift);
        assert(F->arg_size() >= argnames.size());
        for (size_t i = 0; i < argnames.size(); i++) {
            F->getArg(i)->setName(argnames[i]);
        }
    }
    props.decl = FunctionCallee(ftype, fval);
    props.attrs = attributes;
    return props;
}

static void emit_sret_roots(language_codectx_t &ctx, bool isptr, Value *Src, Type *T, Value *Shadow, Type *ShadowT, unsigned count)
{
    unsigned emitted = TrackWithShadow(Src, T, isptr, Shadow, ShadowT, ctx.builder); //This comes from Late-GC-Lowering??
    assert(emitted == count); (void)emitted; (void)count;
}

static DISubroutineType *
get_specsig_di(language_codectx_t &ctx, language_debugcache_t &debuginfo, language_value_t *rt, language_value_t *sig, DIBuilder &dbuilder)
{
    #if LANGUAGE_LLVM_VERSION < 170000
    if (isptr && !cast<PointerType>(Src->getType())->isOpaqueOrPointeeTypeMatches(T))
         Src = ctx.builder.CreateBitCast(Src, T->getPointerTo(Src->getType()->getPointerAddressSpace()));
    #endif
    size_t nargs = language_nparams(sig); // TODO: if this is a Varargs function, our debug info for the `...` var may be misleading
    SmallVector<Metadata*, 0> ditypes(nargs + 1);
    ditypes[0] = language_type_to_di(ctx, debuginfo, rt, &dbuilder, false);
    for (size_t i = 0; i < nargs; i++) {
        language_value_t *jt = language_tparam(sig, i);
        ditypes[i + 1] = language_type_to_di(ctx, debuginfo, jt, &dbuilder, false);
    }
    return dbuilder.createSubroutineType(dbuilder.getOrCreateTypeArray(ditypes));
}

/* aka Core.Compiler.tuple_tfunc */
static language_datatype_t *compute_va_type(language_method_instance_t *lam, size_t nreq)
{
    size_t nvargs = language_nparams(lam->specTypes)-nreq;
    language_svec_t *tupargs = language_alloc_svec(nvargs);
    LANGUAGE_GC_PUSH1(&tupargs);
    for (size_t i = nreq; i < language_nparams(lam->specTypes); ++i) {
        language_value_t *argType = language_nth_slot_type(lam->specTypes, i);
        // n.b. specTypes is required to be a datatype by construction for specsig
        if (is_uniquerep_Type(argType))
            argType = language_typeof(language_tparam0(argType));
        else if (language_has_intersect_type_not_kind(argType)) {
            language_value_t *ts[2] = {argType, (language_value_t*)language_type_type};
            argType = language_type_union(ts, 2);
        }
        language_svecset(tupargs, i-nreq, argType);
    }
    language_value_t *typ = language_apply_tuple_type(tupargs, 1);
    LANGUAGE_GC_POP();
    return (language_datatype_t*)typ;
}

static std::string get_function_name(bool specsig, bool needsparams, const char *unadorned_name, const Triple &TargetTriple)
{
    std::string _funcName;
    raw_string_ostream funcName(_funcName);
    // try to avoid conflicts in the global symbol table
    if (specsig)
        funcName << "language_"; // api 5
    else if (needsparams)
        funcName << "japi3_";
    else
        funcName << "japi1_";
    if (TargetTriple.isOSLinux()) {
        if (unadorned_name[0] == '@')
            unadorned_name++;
    }
    funcName << unadorned_name << "_" << language_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
    return funcName.str();
}

// Compile to LLVM IR, using a specialized signature if applicable.
static language_llvm_functions_t
    emit_function(
        orc::ThreadSafeModule &TSM,
        language_method_instance_t *lam,
        language_code_info_t *src,
        language_value_t *jlrettype,
        language_codegen_params_t &params,
        size_t min_world, size_t max_world)
{
    ++EmittedFunctions;
    // step 1. unpack AST and allocate codegen context for this function
    language_llvm_functions_t declarations;
    language_codectx_t ctx(*params.tsctx.getContext(), params, min_world, max_world);
    language_datatype_t *vatyp = NULL;
    LANGUAGE_GC_PUSH2(&ctx.code, &vatyp);
    ctx.code = src->code;
    ctx.source = src;

    std::map<int, BasicBlock*> labels;
    bool toplevel = false;
    ctx.module = language_is_method(lam->def.method) ? lam->def.method->module : lam->def.module;
    ctx.linfo = lam;
    ctx.name = TSM.getModuleUnlocked()->getModuleIdentifier().data();
    size_t nreq = src->nargs;
    int va = src->isva;
    ctx.nargs = nreq;
    if (va) {
        assert(nreq > 0);
        nreq--;
    }
    if (language_is_method(lam->def.value)) {
        ctx.is_opaque_closure = lam->def.method->is_for_opaque_closure;
    }
    ctx.nReqArgs = nreq;
    if (va) {
        language_sym_t *vn = slot_symbol(ctx, ctx.nargs-1);
        if (vn != language_unused_sym)
            ctx.vaSlot = ctx.nargs - 1;
    }
    toplevel = !language_is_method(lam->def.method);
    ctx.rettype = jlrettype;
    ctx.funcName = ctx.name;
    ctx.spvals_ptr = NULL;
    language_array_t *stmts = ctx.code;
    size_t stmtslen = language_array_dim0(stmts);

    // step 1b. unpack debug information
    int coverage_mode = language_options.code_coverage;
    int malloc_log_mode = language_options.malloc_log;
    if (!LANGUAGE_FEAT_TEST(ctx, code_coverage))
        coverage_mode = LANGUAGE_LOG_NONE;
    if (!LANGUAGE_FEAT_TEST(ctx, track_allocations))
        malloc_log_mode = LANGUAGE_LOG_NONE;

    StringRef dbgFuncName = ctx.name;
    int toplineno = -1;
    if (lam && language_is_method(lam->def.method)) {
        toplineno = lam->def.method->line;
        ctx.file = language_symbol_name(lam->def.method->file);
    }
    else if ((language_value_t*)src->debuginfo != language_nothing) {
        // look for the file and line info of the original start of this block, as reported by lowering
        language_debuginfo_t *debuginfo = src->debuginfo;
        while ((language_value_t*)debuginfo->linetable != language_nothing)
            debuginfo = debuginfo->linetable;
        ctx.file = language_debuginfo_file(debuginfo);
        struct language_codeloc_t lineidx = language_uncompress1_codeloc(debuginfo->codelocs, 0);
        toplineno = std::max((int32_t)0, lineidx.line);
    }
    if (ctx.file.empty())
        ctx.file = "<missing>";
    // language_printf(LANGUAGE_STDERR, "\n*** compiling %s at %s:%d\n\n",
    //           language_symbol_name(ctx.name), ctx.file.str().c_str(), toplineno);

    bool debug_enabled = ctx.emission_context.debug_level != 0;
    if (dbgFuncName.empty()) // Should never happen anymore?
        debug_enabled = false;

    // step 2. process var-info lists to see what vars need boxing
    int n_ssavalues = language_is_long(src->ssavaluetypes) ? language_unbox_long(src->ssavaluetypes) : language_array_nrows(src->ssavaluetypes);
    size_t vinfoslen = language_array_dim0(src->slotflags);
    ctx.slots.resize(vinfoslen, language_varinfo_t(ctx.builder.getContext()));
    assert(lam->specTypes); // the specTypes field should always be assigned


    // create SAvalue locations for SSAValue objects
    ctx.ssavalue_assigned.assign(n_ssavalues, false);
    ctx.SAvalues.assign(n_ssavalues, language_cgval_t());
    ctx.ssavalue_usecount.assign(n_ssavalues, 0);

    bool specsig, needsparams;
    std::tie(specsig, needsparams) = uses_specsig(lam, jlrettype, params.params->prefer_specsig);

    // step 3. some variable analysis
    size_t i;
    for (i = 0; i < nreq && i < vinfoslen; i++) {
        language_varinfo_t &varinfo = ctx.slots[i];
        varinfo.isArgument = true;
        language_sym_t *argname = slot_symbol(ctx, i);
        if (argname == language_unused_sym)
            continue;
        language_value_t *ty = language_nth_slot_type(lam->specTypes, i);
        // TODO: language_nth_slot_type should call language_rewrap_unionall
        //  specTypes is required to be a datatype by construction for specsig, but maybe not otherwise
        // OpaqueClosure implicitly loads the env
        if (i == 0 && ctx.is_opaque_closure) {
            if (language_is_array(src->slottypes)) {
                ty = language_array_ptr_ref((language_array_t*)src->slottypes, i);
            }
            else {
                ty = (language_value_t*)language_any_type;
            }
        }
        varinfo.value = mark_language_type(ctx, (Value*)NULL, false, ty);
    }
    if (va && ctx.vaSlot != -1) {
        language_varinfo_t &varinfo = ctx.slots[ctx.vaSlot];
        varinfo.isArgument = true;
        vatyp = specsig ? compute_va_type(lam, nreq) : (language_tuple_type);
        varinfo.value = mark_language_type(ctx, (Value*)NULL, false, vatyp);
    }

    for (i = 0; i < vinfoslen; i++) {
        language_varinfo_t &varinfo = ctx.slots[i];
        uint8_t flags = language_array_uint8_ref(src->slotflags, i);
        varinfo.isSA = (language_vinfo_sa(flags) != 0) || varinfo.isArgument;
        varinfo.usedUndef = (language_vinfo_usedundef(flags) != 0) || !varinfo.isArgument;
        if (!varinfo.isArgument) {
            varinfo.value = mark_language_type(ctx, (Value*)NULL, false, (language_value_t*)language_any_type);
        }
    }

    // finish recording variable use info
    for (i = 0; i < stmtslen; i++)
        simple_use_analysis(ctx, language_array_ptr_ref(stmts, i));

    // determine which vars need to be volatile
    mark_volatile_vars(stmts, ctx.slots);

    // step 4. determine function signature
    if (!specsig)
        ctx.nReqArgs--;  // function not part of argArray in jlcall

    std::string _funcName = get_function_name(specsig, needsparams, ctx.name, ctx.emission_context.TargetTriple);
    declarations.specFunctionObject = _funcName;

    // allocate Function declarations and wrapper objects
    //Safe because params holds ctx lock
    Module *M = TSM.getModuleUnlocked();
    M->addModuleFlag(Module::Warning, "julia.debug_level", ctx.emission_context.debug_level);
    language_debugcache_t debugcache;
    debugcache.initialize(M);
    language_returninfo_t returninfo = {};
    Function *f = NULL;
    bool has_sret = false;
    if (specsig) { // assumes !va and !needsparams
        BitVector used_args;
        size_t args_begin;
        returninfo = get_specsig_function(ctx, M, NULL, declarations.specFunctionObject, lam->specTypes,
                                          jlrettype, ctx.is_opaque_closure, LANGUAGE_FEAT_TEST(ctx,gcstack_arg), &used_args, &args_begin);
        f = cast<Function>(returninfo.decl.getCallee());
        has_sret = (returninfo.cc == language_returninfo_t::SRet || returninfo.cc == language_returninfo_t::Union);
        language_init_function(f, ctx.emission_context.TargetTriple);
        if (ctx.emission_context.debug_level >= 2) {
            auto arg_typename = [&](size_t i) LANGUAGE_NOTSAFEPOINT {
                auto tp = language_tparam(lam->specTypes, i);
                return language_is_datatype(tp) ? language_symbol_name(((language_datatype_t*)tp)->name->name) : "<unknown type>";
            };
            size_t nreal = 0;
            for (size_t i = 0; i < std::min(nreq, static_cast<size_t>(used_args.size())); i++) {
                language_sym_t *argname = slot_symbol(ctx, i);
                if (argname == language_unused_sym)
                    continue;
                if (used_args.test(i)) {
                    auto &arg = *f->getArg(args_begin++);
                    nreal++;
                    auto name = language_symbol_name(argname);
                    if (!name[0]) {
                        arg.setName(StringRef("#") + Twine(nreal) + StringRef("::") + arg_typename(i));
                    } else {
                        arg.setName(name + StringRef("::") + arg_typename(i));
                    }
                }
            }
            if (va && ctx.vaSlot != -1) {
                size_t vidx = 0;
                for (size_t i = nreq; i < used_args.size(); i++) {
                    if (used_args.test(i)) {
                        auto &arg = *f->getArg(args_begin++);
                        auto type = arg_typename(i);
                        const char *name = language_symbol_name(slot_symbol(ctx, ctx.vaSlot));
                        if (!name[0])
                            name = "...";
                        vidx++;
                        arg.setName(name + StringRef("[") + Twine(vidx) + StringRef("]::") + type);
                    }
                }
            }
        }

        // common pattern: see if all return statements are an argument in that
        // case the apply-generic call can re-use the original box for the return
        int retarg = [stmts, nreq]() {
            int retarg = -1;
            for (size_t i = 0; i < language_array_nrows(stmts); ++i) {
                language_value_t *stmt = language_array_ptr_ref(stmts, i);
                if (language_is_returnnode(stmt)) {
                    stmt = language_returnnode_value(stmt);
                    if (stmt == NULL)
                        continue;
                    if (!language_is_argument(stmt))
                        return -1;
                    unsigned sl = language_slot_number(stmt) - 1;
                    if (sl >= nreq)
                        return -1;
                    if (retarg == -1)
                        retarg = sl;
                    else if ((unsigned)retarg != sl)
                        return -1;
                }
            }
            return retarg;
        }();

        std::string wrapName;
        raw_string_ostream(wrapName) << "jfptr_" << ctx.name << "_" << language_atomic_fetch_add_relaxed(&globalUniqueGeneratedNames, 1);
        declarations.functionObject = wrapName;
        (void)gen_invoke_wrapper(lam, jlrettype, returninfo, retarg, declarations.functionObject, M, ctx.emission_context);
        // TODO: add attributes: maybe_mark_argument_dereferenceable(Arg, argType)
        // TODO: add attributes: dereferenceable<sizeof(void*) * nreq>
        // TODO: (if needsparams) add attributes: dereferenceable<sizeof(void*) * length(sp)>, readonly, nocapture
    }
    else {
        f = Function::Create(needsparams ? ctx.types().T_jlfuncparams : ctx.types().T_jlfunc,
                             GlobalVariable::ExternalLinkage,
                             declarations.specFunctionObject, M);
        language_init_function(f, ctx.emission_context.TargetTriple);
        if (needsparams) {
            language_name_jlfuncparams_args(ctx.emission_context, f);
        } else {
            language_name_jlfunc_args(ctx.emission_context, f);
        }
        f->setAttributes(AttributeList::get(ctx.builder.getContext(), {get_func_attrs(ctx.builder.getContext()), f->getAttributes()}));
        returninfo.decl = f;
        declarations.functionObject = needsparams ? "language_fptr_sparam" : "language_fptr_args";
    }

    if (ctx.emission_context.debug_level >= 2 && lam->def.method && language_is_method(lam->def.method) && lam->specTypes != (language_value_t*)language_emptytuple_type) {
        ios_t sigbuf;
        ios_mem(&sigbuf, 0);
        language_static_show_func_sig((LANGUAGE_STREAM*) &sigbuf, (language_value_t*)lam->specTypes);
        f->addFnAttr("julia.fsig", StringRef(sigbuf.buf, sigbuf.size));
        ios_close(&sigbuf);
    }

    AttrBuilder FnAttrs(ctx.builder.getContext(), f->getAttributes().getFnAttrs());
    AttrBuilder RetAttrs(ctx.builder.getContext(), f->getAttributes().getRetAttrs());

    if (jlrettype == (language_value_t*)language_bottom_type)
        FnAttrs.addAttribute(Attribute::NoReturn);

#ifdef USE_POLLY
    if (!language_has_meta(stmts, language_polly_sym) || language_options.polly == LANGUAGE_OPTIONS_POLLY_OFF)
        FnAttrs.addAttribute(polly::PollySkipFnAttr);
#endif

    if (src->inlining == 2)
        FnAttrs.addAttribute(Attribute::NoInline);

#ifdef LANGUAGE_DEBUG_BUILD
    FnAttrs.addAttribute(Attribute::StackProtectStrong);
#endif

#ifdef _COMPILER_TSAN_ENABLED_
    // TODO: enable this only when a argument like `-race` is passed to Julia
    //       add a macro for no_sanitize_thread
    FnAttrs.addAttribute(llvm::Attribute::SanitizeThread);
#endif

    // add the optimization level specified for this module, if any
    int optlevel = language_get_module_optlevel(ctx.module);
    if (optlevel >= 0 && optlevel <= 3) {
        static const char* const optLevelStrings[] = { "0", "1", "2", "3" };
        FnAttrs.addAttribute("julia-optimization-level", optLevelStrings[optlevel]);
    }

    ctx.f = f;

    // Step 4b. determine debug info signature and other type info for locals
    DICompileUnit::DebugEmissionKind emissionKind = (DICompileUnit::DebugEmissionKind) ctx.params->debug_info_kind;
    DICompileUnit::DebugNameTableKind tableKind;
    if (LANGUAGE_FEAT_TEST(ctx, gnu_pubnames))
        tableKind = DICompileUnit::DebugNameTableKind::GNU;
    else
        tableKind = DICompileUnit::DebugNameTableKind::None;
    DIBuilder dbuilder(*M, true, debug_enabled ? getOrCreateJuliaCU(*M, emissionKind, tableKind) : NULL);
    DIFile *topfile = NULL;
    DISubprogram *SP = NULL;
    DebugLoc noDbg, topdebugloc;
    if (debug_enabled) {
        topfile = dbuilder.createFile(ctx.file, ".");
        DISubroutineType *subrty;
        if (ctx.emission_context.debug_level <= 1)
            subrty = debugcache.language_di_func_null_sig;
        else if (!specsig)
            subrty = debugcache.language_di_func_sig;
        else
            subrty = get_specsig_di(ctx, debugcache, jlrettype, lam->specTypes, dbuilder);
        SP = dbuilder.createFunction(nullptr
                                     ,dbgFuncName      // Name
                                     ,f->getName()     // LinkageName
                                     ,topfile          // File
                                     ,toplineno        // LineNo
                                     ,subrty           // Ty
                                     ,toplineno        // ScopeLine
                                     ,DINode::FlagZero // Flags
                                     ,DISubprogram::SPFlagDefinition | DISubprogram::SPFlagOptimized // SPFlags
                                     ,nullptr          // Template Parameters
                                     ,nullptr          // Template Declaration
                                     ,nullptr          // ThrownTypes
                                     );
        topdebugloc = DILocation::get(ctx.builder.getContext(), toplineno, 0, SP, NULL);
        f->setSubprogram(SP);
        if (ctx.emission_context.debug_level >= 2) {
            const bool AlwaysPreserve = true;
            // Go over all arguments and local variables and initialize their debug information
            for (i = 0; i < nreq; i++) {
                language_sym_t *argname = slot_symbol(ctx, i);
                if (argname == language_unused_sym)
                    continue;
                language_varinfo_t &varinfo = ctx.slots[i];
                varinfo.dinfo = dbuilder.createParameterVariable(
                    SP,                                 // Scope (current function will be fill in later)
                    language_symbol_name(argname),            // Variable name
                    has_sret + i + 1,                   // Argument number (1-based)
                    topfile,                            // File
                    toplineno == -1 ? 0 : toplineno,    // Line
                    // Variable type
                    language_type_to_di(ctx, debugcache, varinfo.value.typ, &dbuilder, false),
                    AlwaysPreserve,                     // May be deleted if optimized out
                    DINode::FlagZero);                  // Flags (TODO: Do we need any)
            }
            if (va && ctx.vaSlot != -1) {
                ctx.slots[ctx.vaSlot].dinfo = dbuilder.createParameterVariable(
                    SP,                                 // Scope (current function will be fill in later)
                    std::string(language_symbol_name(slot_symbol(ctx, ctx.vaSlot))) + "...",  // Variable name
                    has_sret + nreq + 1,                // Argument number (1-based)
                    topfile,                            // File
                    toplineno == -1 ? 0 : toplineno,    // Line (for now, use lineno of the function)
                    language_type_to_di(ctx, debugcache, ctx.slots[ctx.vaSlot].value.typ, &dbuilder, false),
                    AlwaysPreserve,                     // May be deleted if optimized out
                    DINode::FlagZero);                  // Flags (TODO: Do we need any)
            }
            for (i = 0; i < vinfoslen; i++) {
                language_sym_t *s = slot_symbol(ctx, i);
                language_varinfo_t &varinfo = ctx.slots[i];
                if (varinfo.isArgument || s == language_empty_sym || s == language_unused_sym)
                    continue;
                // LLVM 4.0: Assume the variable has default alignment
                varinfo.dinfo = dbuilder.createAutoVariable(
                    SP,                      // Scope (current function will be fill in later)
                    language_symbol_name(s),       // Variable name
                    topfile,                 // File
                    toplineno == -1 ? 0 : toplineno, // Line (for now, use lineno of the function)
                    language_type_to_di(ctx, debugcache, varinfo.value.typ, &dbuilder, false), // Variable type
                    AlwaysPreserve,          // May be deleted if optimized out
                    DINode::FlagZero         // Flags (TODO: Do we need any)
                    );
            }
        }
    }

    // step 5. create first basic block
    BasicBlock *b0 = BasicBlock::Create(ctx.builder.getContext(), "top", f);
    ctx.builder.SetInsertPoint(b0);
    ctx.builder.SetCurrentDebugLocation(noDbg);

    // spill arguments into stack slots
    // so it is more likely to be possible to find them when debugging
    Value *fArg=NULL, *argArray=NULL, *pargArray=NULL, *argCount=NULL;
    if (!specsig) {
        Function::arg_iterator AI = f->arg_begin();
        fArg = &*AI++;
        argArray = &*AI++;
        pargArray = ctx.builder.CreateAlloca(argArray->getType());
        setName(ctx.emission_context, pargArray, "stackargs");
        ctx.builder.CreateStore(argArray, pargArray, true/*volatile store to prevent removal of this alloca*/);
        argCount = &*AI++;
        ctx.argArray = argArray;
        ctx.argCount = argCount;
        if (needsparams) {
            ctx.spvals_ptr = &*AI++;
        }
    }
    // step 6. set up GC frame
    allocate_gc_frame(ctx, b0);
    Value *last_age = NULL;
    Value *world_age_field = get_last_age_field(ctx);
    if (toplevel || ctx.is_opaque_closure) {
        language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
        last_age = ai.decorateInst(ctx.builder.CreateAlignedLoad(
            ctx.types().T_size, world_age_field, ctx.types().alignof_ptr));
    }

    // step 7. allocate local variables slots
    // must be in the first basic block for the llvm mem2reg pass to work
    auto allocate_local = [&ctx, &dbuilder, &debugcache, topdebugloc, va, debug_enabled, M](language_varinfo_t &varinfo, language_sym_t *s, int i) {
        language_value_t *jt = varinfo.value.typ;
        assert(!varinfo.boxroot); // variables shouldn't have memory locs already
        if (varinfo.value.constant) {
            // no need to explicitly load/store a constant/ghost value
            alloc_def_flag(ctx, varinfo);
            return;
        }
        else if (varinfo.isArgument && (!va || ctx.vaSlot == -1 || i != ctx.vaSlot)) {
            // just use the input pointer, if we have it
            // (we will need to attach debuginfo later to it)
            return;
        }
        else if (language_is_uniontype(jt)) {
            bool allunbox;
            size_t align, nbytes;
            Value *lv = try_emit_union_alloca(ctx, (language_uniontype_t*)jt, allunbox, align, nbytes);
            if (lv) {
                lv->setName(language_symbol_name(s));
                varinfo.value = mark_language_slot(lv, jt, NULL, ctx.tbaa().tbaa_stack);
                varinfo.pTIndex = emit_static_alloca(ctx, getInt8Ty(ctx.builder.getContext()));
                setName(ctx.emission_context, varinfo.pTIndex, "tindex");
                // TODO: attach debug metadata to this variable
            }
            else if (allunbox) {
                // all ghost values just need a selector allocated
                AllocaInst *lv = emit_static_alloca(ctx, getInt8Ty(ctx.builder.getContext()));
                lv->setName(language_symbol_name(s));
                varinfo.pTIndex = lv;
                varinfo.value.tbaa = NULL;
                varinfo.value.isboxed = false;
                // TODO: attach debug metadata to this variable
            }
            if (lv || allunbox)
                alloc_def_flag(ctx, varinfo);
            if (allunbox)
                return;
        }
        else if (deserves_stack(jt)) {
            bool isboxed;
            Type *vtype = language_type_to_llvm(ctx, jt, &isboxed);
            assert(!isboxed);
            assert(!type_is_ghost(vtype) && "constants should already be handled");
            Value *lv = new AllocaInst(vtype, M->getDataLayout().getAllocaAddrSpace(), nullptr, Align(language_datatype_align(jt)), language_symbol_name(s), /*InsertBefore*/ctx.topalloca);
            if (CountTrackedPointers(vtype).count) {
                StoreInst *SI = new StoreInst(Constant::getNullValue(vtype), lv, false, Align(sizeof(void*)));
                SI->insertAfter(ctx.topalloca);
            }
            varinfo.value = mark_language_slot(lv, jt, NULL, ctx.tbaa().tbaa_stack);
            alloc_def_flag(ctx, varinfo);
            if (debug_enabled && varinfo.dinfo) {
                assert((Metadata*)varinfo.dinfo->getType() != debugcache.language_pvalue_dillvmt);
                dbuilder.insertDeclare(lv, varinfo.dinfo, dbuilder.createExpression(),
                                       topdebugloc,
                                       ctx.builder.GetInsertBlock());
            }
            return;
        }
        // otherwise give it a boxroot in this function
        AllocaInst *av = new AllocaInst(ctx.types().T_prjlvalue, M->getDataLayout().getAllocaAddrSpace(),
            nullptr, Align(sizeof(language_value_t*)), language_symbol_name(s), /*InsertBefore*/ctx.topalloca);
        StoreInst *SI = new StoreInst(Constant::getNullValue(ctx.types().T_prjlvalue), av, false, Align(sizeof(void*)));
        SI->insertAfter(ctx.topalloca);
        varinfo.boxroot = av;
        if (debug_enabled && varinfo.dinfo) {
            SmallVector<uint64_t, 1> addr;
            DIExpression *expr;
            if ((Metadata*)varinfo.dinfo->getType() != debugcache.language_pvalue_dillvmt)
                addr.push_back(llvm::dwarf::DW_OP_deref);
            expr = dbuilder.createExpression(addr);
            dbuilder.insertDeclare(av, varinfo.dinfo, expr,
                                        topdebugloc,
                            ctx.builder.GetInsertBlock());
        }
    };

    // get pointers for locals stored in the gc frame array (argTemp)
    for (i = 0; i < vinfoslen; i++) {
        language_sym_t *s = slot_symbol(ctx, i);
        if (s == language_unused_sym)
            continue;
        language_varinfo_t &varinfo = ctx.slots[i];
        if (!varinfo.used) {
            varinfo.usedUndef = false;
            continue;
        }
        allocate_local(varinfo, s, (int)i);
    }

    std::map<int, int> upsilon_to_phic;

    // Scan for PhiC nodes, emit their slots and record which upsilon nodes
    // yield to them.
    // Also count ssavalue uses.
    {
        for (size_t i = 0; i < language_array_nrows(stmts); ++i) {
            language_value_t *stmt = language_array_ptr_ref(stmts, i);

            auto scan_ssavalue = [&](language_value_t *val) {
                if (language_is_ssavalue(val)) {
                    size_t ssa_idx = ((language_ssavalue_t*)val)->id-1;
                    /*
                     * We technically allow out of bounds SSAValues in dead IR, so make
                     * sure to bounds check this here. It's still not *good* to leave
                     * dead code in the IR, because this will conservatively overcount
                     * it, but let's at least make it not crash.
                     */
                    if (ssa_idx < ctx.ssavalue_usecount.size()) {
                        ctx.ssavalue_usecount[ssa_idx] += 1;
                    }
                    return true;
                }
                return false;
            };
            general_use_analysis(ctx, stmt, scan_ssavalue);

            if (language_is_phicnode(stmt)) {
                language_array_t *values = (language_array_t*)language_fieldref_noalloc(stmt, 0);
                for (size_t j = 0; j < language_array_nrows(values); ++j) {
                    language_value_t *val = language_array_ptr_ref(values, j);
                    assert(language_is_ssavalue(val));
                    upsilon_to_phic[((language_ssavalue_t*)val)->id] = i;
                }
                language_varinfo_t &vi = (ctx.phic_slots.emplace(i, language_varinfo_t(ctx.builder.getContext())).first->second =
                                    language_varinfo_t(ctx.builder.getContext()));
                language_value_t *typ = language_array_ptr_ref(src->ssavaluetypes, i);
                vi.used = true;
                vi.isVolatile = true;
                vi.value = mark_language_type(ctx, (Value*)NULL, false, typ);
                allocate_local(vi, language_symbol("phic"), -1);
            }
        }
    }

    // step 8. move args into local variables
    Function::arg_iterator AI = f->arg_begin();
    SmallVector<AttributeSet, 0> attrs(f->arg_size()); // function declaration attributes

    auto get_specsig_arg = [&](language_value_t *argType, Type *llvmArgType, bool isboxed) {
        if (type_is_ghost(llvmArgType)) { // this argument is not actually passed
            return ghostValue(ctx, argType);
        }
        else if (is_uniquerep_Type(argType)) {
            return mark_language_const(ctx, language_tparam0(argType));
        }
        Argument *Arg = &*AI;
        ++AI;
        AttrBuilder param(ctx.builder.getContext(), f->getAttributes().getParamAttrs(Arg->getArgNo()));
        language_cgval_t theArg;
        if (llvmArgType->isAggregateType()) {
            maybe_mark_argument_dereferenceable(param, argType);
            theArg = mark_language_slot(Arg, argType, NULL, ctx.tbaa().tbaa_const); // this argument is by-pointer
        }
        else {
            if (isboxed) // e.g. is-pointer
                maybe_mark_argument_dereferenceable(param, argType);
            theArg = mark_language_type(ctx, Arg, isboxed, argType);
            if (theArg.tbaa == ctx.tbaa().tbaa_immut)
                theArg.tbaa = ctx.tbaa().tbaa_const;
        }
        attrs[Arg->getArgNo()] = AttributeSet::get(Arg->getContext(), param); // function declaration attributes
        return theArg;
    };

    if (has_sret) {
        Argument *Arg = &*AI;
        ++AI;
        AttrBuilder param(ctx.builder.getContext(), f->getAttributes().getParamAttrs(Arg->getArgNo()));
        if (returninfo.cc == language_returninfo_t::Union) {
            param.addAttribute(Attribute::NonNull);
            // The `dereferenceable` below does not imply `nonnull` for non addrspace(0) pointers.
            param.addDereferenceableAttr(returninfo.union_bytes);
            param.addAlignmentAttr(returninfo.union_align);
        }
        else {
            const DataLayout &DL = language_Module->getDataLayout();
            Type *RT = Arg->getParamStructRetType();
            TypeSize sz = DL.getTypeAllocSize(RT);
            Align al = DL.getPrefTypeAlign(RT);
            param.addAttribute(Attribute::NonNull);
            // The `dereferenceable` below does not imply `nonnull` for non addrspace(0) pointers.
            param.addDereferenceableAttr(sz);
            param.addAlignmentAttr(al);
        }
        attrs[Arg->getArgNo()] = AttributeSet::get(Arg->getContext(), param); // function declaration attributes
    }
    if (returninfo.return_roots) {
        Argument *Arg = &*AI;
        ++AI;
        AttrBuilder param(ctx.builder.getContext(), f->getAttributes().getParamAttrs(Arg->getArgNo()));
        param.addAttribute(Attribute::NonNull);
        // The `dereferenceable` below does not imply `nonnull` for non addrspace(0) pointers.
        size_t size = returninfo.return_roots * sizeof(language_value_t*);
        param.addDereferenceableAttr(size);
        param.addAlignmentAttr(Align(sizeof(language_value_t*)));
        attrs[Arg->getArgNo()] = AttributeSet::get(Arg->getContext(), param); // function declaration attributes
    }
    if (specsig && LANGUAGE_FEAT_TEST(ctx, gcstack_arg)){
        Argument *Arg = &*AI;
        ++AI;
        AttrBuilder param(ctx.builder.getContext());
        attrs[Arg->getArgNo()] = AttributeSet::get(Arg->getContext(), param);
    }
    for (i = 0; i < nreq && i < vinfoslen; i++) {
        language_sym_t *s = slot_symbol(ctx, i);
        language_value_t *argType = language_nth_slot_type(lam->specTypes, i);
        // TODO: language_nth_slot_type should call language_rewrap_unionall?
        //  specTypes is required to be a datatype by construction for specsig, but maybe not otherwise
        bool isboxed = deserves_argbox(argType);
        Type *llvmArgType = NULL;
        if (i == 0 && ctx.is_opaque_closure) {
            isboxed = true;
            llvmArgType = PointerType::get(ctx.types().T_jlvalue, AddressSpace::Derived);
            argType = (language_value_t*)language_any_type;
        }
        else {
            llvmArgType = isboxed ? ctx.types().T_prjlvalue : language_type_to_llvm(ctx, argType);
        }
        if (s == language_unused_sym) {
            if (specsig && !type_is_ghost(llvmArgType) && !is_uniquerep_Type(argType))
                ++AI;
            continue;
        }
        language_varinfo_t &vi = ctx.slots[i];
        language_cgval_t theArg;
        if (s == language_unused_sym || vi.value.constant) {
            assert(vi.boxroot == NULL);
            if (specsig && !type_is_ghost(llvmArgType) && !is_uniquerep_Type(argType))
                ++AI;
        }
        else {
            // If this is an opaque closure, implicitly load the env and switch
            // the world age.
            if (i == 0 && ctx.is_opaque_closure) {
                // Load closure world
                Value *oc_this = decay_derived(ctx, &*AI++);
                Value *argaddr = emit_bitcast(ctx, oc_this, getInt8PtrTy(ctx.builder.getContext()));
                Value *worldaddr = ctx.builder.CreateInBoundsGEP(
                        getInt8Ty(ctx.builder.getContext()), argaddr,
                        ConstantInt::get(ctx.types().T_size, offsetof(language_opaque_closure_t, world)));

                language_cgval_t closure_world = typed_load(ctx, worldaddr, NULL, (language_value_t*)language_long_type,
                    nullptr, nullptr, false, AtomicOrdering::NotAtomic, false, ctx.types().alignof_ptr.value());
                emit_unbox_store(ctx, closure_world, world_age_field, ctx.tbaa().tbaa_gcframe, ctx.types().alignof_ptr.value());

                // Load closure env
                Value *envaddr = ctx.builder.CreateInBoundsGEP(
                        getInt8Ty(ctx.builder.getContext()), argaddr,
                        ConstantInt::get(ctx.types().T_size, offsetof(language_opaque_closure_t, captures)));

                language_cgval_t closure_env = typed_load(ctx, envaddr, NULL, (language_value_t*)language_any_type,
                    nullptr, nullptr, true, AtomicOrdering::NotAtomic, false, sizeof(void*));
                theArg = update_language_type(ctx, closure_env, vi.value.typ);
            }
            else if (specsig) {
                theArg = get_specsig_arg(argType, llvmArgType, isboxed);
            }
            else {
                if (i == 0) {
                    // first (function) arg is separate in jlcall
                    theArg = mark_language_type(ctx, fArg, true, vi.value.typ);
                }
                else {
                    Value *argPtr = ctx.builder.CreateConstInBoundsGEP1_32(ctx.types().T_prjlvalue, argArray, i - 1);
                    language_aliasinfo_t ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_const);
                    Value *load = ai.decorateInst(maybe_mark_load_dereferenceable(
                            ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, argPtr, Align(sizeof(void*))),
                            false, vi.value.typ));
                    theArg = mark_language_type(ctx, load, true, vi.value.typ);
                    if (debug_enabled && vi.dinfo && !vi.boxroot) {
                        SmallVector<uint64_t, 8> addr;
                        addr.push_back(llvm::dwarf::DW_OP_deref);
                        addr.push_back(llvm::dwarf::DW_OP_plus_uconst);
                        addr.push_back((i - 1) * sizeof(void*));
                        if ((Metadata*)vi.dinfo->getType() != debugcache.language_pvalue_dillvmt)
                            addr.push_back(llvm::dwarf::DW_OP_deref);
                        dbuilder.insertDeclare(pargArray, vi.dinfo, dbuilder.createExpression(addr),
                                        topdebugloc,
                                        ctx.builder.GetInsertBlock());
                    }
                }
            }


            if (vi.boxroot == NULL) {
                assert(vi.value.V == NULL && "unexpected variable slot created for argument");
                // keep track of original (possibly boxed) value to avoid re-boxing or moving
                vi.value = theArg;
                if (debug_enabled && vi.dinfo && theArg.V) {
                    if (theArg.ispointer()) {
                        dbuilder.insertDeclare(theArg.V, vi.dinfo, dbuilder.createExpression(),
                                               topdebugloc, ctx.builder.GetInsertBlock());
                    }
                    else {
                        dbuilder.insertDbgValueIntrinsic(theArg.V, vi.dinfo, dbuilder.createExpression(),
                                                         topdebugloc, ctx.builder.GetInsertBlock());
                    }
                }
            }
            else {
                Value *argp = boxed(ctx, theArg);
                ctx.builder.CreateStore(argp, vi.boxroot);
            }
        }
    }

    // step 9. allocate rest argument
    CallInst *restTuple = NULL;
    if (va && ctx.vaSlot != -1) {
        language_varinfo_t &vi = ctx.slots[ctx.vaSlot];
        if (vi.value.constant || !vi.used) {
            assert(vi.boxroot == NULL);
        }
        else if (specsig) {
            ctx.nvargs = language_nparams(lam->specTypes) - nreq;
            SmallVector<language_cgval_t, 0> vargs(ctx.nvargs);
            for (size_t i = nreq; i < language_nparams(lam->specTypes); ++i) {
                language_value_t *argType = language_nth_slot_type(lam->specTypes, i);
                // n.b. specTypes is required to be a datatype by construction for specsig
                bool isboxed = deserves_argbox(argType);
                Type *llvmArgType = isboxed ?  ctx.types().T_prjlvalue : language_type_to_llvm(ctx, argType);
                vargs[i - nreq] = get_specsig_arg(argType, llvmArgType, isboxed);
            }
            if (language_is_concrete_type(vi.value.typ)) {
                language_cgval_t tuple = emit_new_struct(ctx, vi.value.typ, ctx.nvargs, vargs);
                emit_varinfo_assign(ctx, vi, tuple);
            }
            else {
                restTuple = emit_jlcall(ctx, jltuple_func, Constant::getNullValue(ctx.types().T_prjlvalue),
                    vargs, ctx.nvargs, language_call);
                language_cgval_t tuple = mark_language_type(ctx, restTuple, true, vi.value.typ);
                emit_varinfo_assign(ctx, vi, tuple);
            }
        }
        else {
            // restarg = language_f_tuple(NULL, &args[nreq], nargs - nreq)
            Function *F = prepare_call(jltuple_func);
            restTuple =
                ctx.builder.CreateCall(F,
                        { Constant::getNullValue(ctx.types().T_prjlvalue),
                          ctx.builder.CreateInBoundsGEP(ctx.types().T_prjlvalue, argArray,
                                  ConstantInt::get(ctx.types().T_size, nreq - 1)),
                          ctx.builder.CreateSub(argCount,
                                  ConstantInt::get(getInt32Ty(ctx.builder.getContext()), nreq - 1)) });
            restTuple->setAttributes(F->getAttributes());
            ctx.builder.CreateStore(restTuple, vi.boxroot);
        }
    }

    AttributeList attributes = AttributeList::get(ctx.builder.getContext(), AttributeSet::get(f->getContext(), FnAttrs), AttributeSet::get(f->getContext(), RetAttrs), attrs);
    // attributes should be a superset of f->getAttributes() based on how we constructed it, but we merge just in case it isn't
    f->setAttributes(AttributeList::get(ctx.builder.getContext(), {attributes, f->getAttributes()}));

    // step 10. Compute properties for each statements
    //     This needs to be computed by iterating in the IR order
    //     instead of control flow order.
    auto in_user_mod = [] (language_module_t *mod) {
        return (!language_is_submodule(mod, language_base_module) &&
                !language_is_submodule(mod, language_core_module));
    };
    auto in_tracked_path = [] (StringRef file) { // falls within an explicitly set file or directory
        return language_options.tracked_path != NULL && file.startswith(language_options.tracked_path);
    };
    bool mod_is_user_mod = in_user_mod(ctx.module);
    bool mod_is_tracked = in_tracked_path(ctx.file);
    struct DebugLineTable {
        DebugLoc loc;
        StringRef file;
        ssize_t line;
        ssize_t line0; // if this represents pc=1, then also cover the entry to the function (pc=0)
        bool is_user_code;
        int32_t edgeid;
        bool sameframe(const DebugLineTable &other) const {
            // detect if the line info for this frame is unchanged (equivalent to loc == other.loc ignoring the inlined_at field)
            return other.edgeid == edgeid && other.line == line;
        };
    };
    DebugLineTable topinfo;
    topinfo.file = ctx.file;
    topinfo.line = toplineno;
    topinfo.line0 = 0;
    topinfo.is_user_code = mod_is_user_mod;
    topinfo.loc = topdebugloc;
    topinfo.edgeid = 0;
    std::map<std::tuple<StringRef, StringRef>, DISubprogram*> subprograms;
    SmallVector<DebugLineTable, 0> prev_lineinfo, new_lineinfo;
    auto update_lineinfo = [&] (size_t pc) {
        std::function<bool(language_debuginfo_t*, language_value_t*, size_t, size_t)> append_lineinfo =
                [&] (language_debuginfo_t *debuginfo, language_value_t *func, size_t to, size_t pc) -> bool {
            while (1) {
                if (!language_is_symbol(debuginfo->def)) // this is a path
                    func = debuginfo->def; // this is inlined
                struct language_codeloc_t lineidx = language_uncompress1_codeloc(debuginfo->codelocs, pc);
                size_t i = lineidx.line;
                if (i < 0) // pc out of range: broken debuginfo?
                    return false;
                if (i == 0 && lineidx.to == 0) // no update
                    return false;
                if (pc > 0 && (language_value_t*)debuginfo->linetable != language_nothing) {
                    // indirection node
                    if (!append_lineinfo(debuginfo->linetable, func, to, i))
                        return false; // no update
                }
                else {
                    // actual node
                    DebugLineTable info;
                    info.edgeid = to;
                    language_module_t *modu = func ? language_debuginfo_module1(func) : NULL;
                    if (modu == NULL)
                        modu = ctx.module;
                    info.file = language_debuginfo_file1(debuginfo);
                    info.line = i;
                    info.line0 = 0;
                    if (pc == 1) {
                        struct language_codeloc_t lineidx = language_uncompress1_codeloc(debuginfo->codelocs, 0);
                        assert(lineidx.to == 0 && lineidx.pc == 0);
                        if (lineidx.line > 0 && info.line != lineidx.line)
                            info.line0 = lineidx.line;
                    }
                    if (info.file.empty())
                        info.file = "<missing>";
                    if (modu == ctx.module)
                        info.is_user_code = mod_is_user_mod;
                    else
                        info.is_user_code = in_user_mod(modu);
                    if (debug_enabled) {
                        StringRef fname = language_debuginfo_name(func);
                        if (new_lineinfo.empty() && info.file == ctx.file) { // if everything matches, emit a toplevel line number
                            info.loc = DILocation::get(ctx.builder.getContext(), info.line, 0, SP, NULL);
                        }
                        else { // otherwise, describe this as an inlining frame
                            DebugLoc inl_loc = new_lineinfo.empty() ? DebugLoc(DILocation::get(ctx.builder.getContext(), 0, 0, SP, NULL)) : new_lineinfo.back().loc;
                            DISubprogram *&inl_SP = subprograms[std::make_tuple(fname, info.file)];
                            if (inl_SP == NULL) {
                                DIFile *difile = dbuilder.createFile(info.file, ".");
                                inl_SP = dbuilder.createFunction(difile
                                                             ,std::string(fname) + ";" // Name
                                                             ,fname            // LinkageName
                                                             ,difile           // File
                                                             ,0                // LineNo
                                                             ,debugcache.language_di_func_null_sig // Ty
                                                             ,0                // ScopeLine
                                                             ,DINode::FlagZero // Flags
                                                             ,DISubprogram::SPFlagDefinition | DISubprogram::SPFlagOptimized // SPFlags
                                                             ,nullptr          // Template Parameters
                                                             ,nullptr          // Template Declaration
                                                             ,nullptr          // ThrownTypes
                                                             );
                            }
                            info.loc = DILocation::get(ctx.builder.getContext(), info.line, 0, inl_SP, inl_loc);
                        }
                    }
                    new_lineinfo.push_back(info);
                }
                to = lineidx.to;
                if (to == 0)
                    return true;
                pc = lineidx.pc;
                debuginfo = (language_debuginfo_t*)language_svecref(debuginfo->edges, to - 1);
                func = NULL;
            }
        };
        prev_lineinfo.resize(0);
        std::swap(prev_lineinfo, new_lineinfo);
        bool updated = append_lineinfo(src->debuginfo, (language_value_t*)lam, 0, pc + 1);
        if (!updated)
            std::swap(prev_lineinfo, new_lineinfo);
        else
            assert(new_lineinfo.size() > 0);
        return updated;
    };

    SmallVector<MDNode*, 0> aliasscopes;
    MDNode* current_aliasscope = nullptr;
    SmallVector<Metadata*, 0> scope_stack;
    SmallVector<MDNode*, 0> scope_list_stack;
    {
        size_t nstmts = language_array_nrows(stmts);
        aliasscopes.resize(nstmts + 1, nullptr);
        MDBuilder mbuilder(ctx.builder.getContext());
        MDNode *alias_domain = mbuilder.createAliasScopeDomain(ctx.name);
        for (i = 0; i < nstmts; i++) {
            language_value_t *stmt = language_array_ptr_ref(stmts, i);
            language_expr_t *expr = language_is_expr(stmt) ? (language_expr_t*)stmt : nullptr;
            if (expr) {
                if (expr->head == language_aliasscope_sym) {
                    MDNode *scope = mbuilder.createAliasScope("aliasscope", alias_domain);
                    scope_stack.push_back(scope);
                    MDNode *scope_list = MDNode::get(ctx.builder.getContext(), ArrayRef<Metadata*>(scope_stack));
                    scope_list_stack.push_back(scope_list);
                    current_aliasscope = scope_list;
                } else if (expr->head == language_popaliasscope_sym) {
                    scope_stack.pop_back();
                    scope_list_stack.pop_back();
                    if (scope_list_stack.empty()) {
                        current_aliasscope = NULL;
                    } else {
                        current_aliasscope = scope_list_stack.back();
                    }
                }
            }
            aliasscopes[i+1] = current_aliasscope;
        }
    }

    Instruction &prologue_end = ctx.builder.GetInsertBlock()->back();

    // step 11a. For top-level code, load the world age
    if (toplevel && !ctx.is_opaque_closure) {
        LoadInst *world = ctx.builder.CreateAlignedLoad(ctx.types().T_size,
            prepare_global_in(language_Module, jlgetworld_global), ctx.types().alignof_ptr);
        world->setOrdering(AtomicOrdering::Acquire);
        ctx.builder.CreateAlignedStore(world, world_age_field, ctx.types().alignof_ptr);
    }

    // step 11b. Emit the entry safepoint
    if (LANGUAGE_FEAT_TEST(ctx, safepoint_on_entry))
        emit_gc_safepoint(ctx.builder, ctx.types().T_size, get_current_ptls(ctx), ctx.tbaa().tbaa_const);

    // step 11c. Do codegen in control flow order
    SmallVector<int, 0> workstack;
    std::map<int, BasicBlock*> BB;
    std::map<size_t, BasicBlock*> come_from_bb;
    int cursor = 0;
    int current_label = 0;
    auto find_next_stmt = [&] (int seq_next) {
        // new style ir is always in dominance order, but frontend IR might not be
        // `seq_next` is the next statement we want to emit
        // i.e. if it exists, it's the next one following control flow and
        // should be emitted into the current insert point.
        if (seq_next >= 0 && (unsigned)seq_next < stmtslen) {
            workstack.push_back(seq_next);
        }
        else if (ctx.builder.GetInsertBlock() && !ctx.builder.GetInsertBlock()->getTerminator()) {
            CreateTrap(ctx.builder, false);
        }
        while (!workstack.empty()) {
            int item = workstack.back();
            workstack.pop_back();
            auto nextbb = BB.find(item + 1);
            if (nextbb == BB.end()) {
                // Not a BB
                cursor = item;
                return;
            }
            if (seq_next != -1 && ctx.builder.GetInsertBlock() && !ctx.builder.GetInsertBlock()->getTerminator()) {
                come_from_bb[cursor + 1] = ctx.builder.GetInsertBlock();
                ctx.builder.CreateBr(nextbb->second);
            }
            seq_next = -1;
            // if this BB is non-empty, we've visited it before so skip it
            if (!nextbb->second->getTerminator()) {
                // New BB
                ctx.builder.SetInsertPoint(nextbb->second);
                cursor = item;
                current_label = item;
                return;
            }
        }
        cursor = -1;
    };

    // If a pkgimage or sysimage is being generated, disable tracking.
    // This means sysimage build or pkgimage precompilation workloads aren't tracked.
    auto do_coverage = [&] (bool in_user_code, bool is_tracked) {
        return (language_generating_output() == 0 &&
                (coverage_mode == LANGUAGE_LOG_ALL ||
                (in_user_code && coverage_mode == LANGUAGE_LOG_USER) ||
                (is_tracked && coverage_mode == LANGUAGE_LOG_PATH)));
    };
    auto do_malloc_log = [&] (bool in_user_code, bool is_tracked) {
        return (language_generating_output() == 0 &&
                (malloc_log_mode == LANGUAGE_LOG_ALL ||
                (in_user_code && malloc_log_mode == LANGUAGE_LOG_USER) ||
                (is_tracked && malloc_log_mode == LANGUAGE_LOG_PATH)));
    };
    auto coverageVisitStmt = [&] () {
        // Visit frames which differ from previous statement as tracked in
        // prev_lineinfo (tracked outer frame first).
        size_t dbg;
        for (dbg = 0; dbg < new_lineinfo.size(); dbg++) {
            if (dbg >= prev_lineinfo.size() || !new_lineinfo[dbg].sameframe(prev_lineinfo[dbg]))
                break;
        }
        for (; dbg < new_lineinfo.size(); dbg++) {
            const auto &newdbg = new_lineinfo[dbg];
            bool is_tracked = in_tracked_path(newdbg.file);
            if (do_coverage(newdbg.is_user_code, is_tracked)) {
                if (newdbg.line0 != 0 && (dbg >= prev_lineinfo.size() || newdbg.edgeid != prev_lineinfo[dbg].edgeid || newdbg.line0 != prev_lineinfo[dbg].line))
                    coverageVisitLine(ctx, newdbg.file, newdbg.line0);
                coverageVisitLine(ctx, newdbg.file, newdbg.line);
            }
        }
    };
    auto mallocVisitStmt = [&] (Value *sync, bool have_dbg_update) {
        if (!do_malloc_log(mod_is_user_mod, mod_is_tracked) || !have_dbg_update) {
            // TODD: add || new_lineinfo[0].sameframe(prev_lineinfo[0])) above, but currently this breaks the test for it (by making an optimization better)
            if (do_malloc_log(true, mod_is_tracked) && sync)
                ctx.builder.CreateCall(prepare_call(sync_gc_total_bytes_func), {sync});
            return;
        }
        mallocVisitLine(ctx, new_lineinfo[0].file, new_lineinfo[0].line, sync);
    };
    if (coverage_mode != LANGUAGE_LOG_NONE) {
        // record all lines that could be covered
        std::function<void(language_debuginfo_t *debuginfo, language_value_t *func)> record_line_exists = [&](language_debuginfo_t *debuginfo, language_value_t *func) {
            if (!language_is_symbol(debuginfo->def)) // this is a path
                func = debuginfo->def; // this is inlined
            for (size_t i = 0; i < language_svec_len(debuginfo->edges); i++) {
                language_debuginfo_t *edge = (language_debuginfo_t*)language_svecref(debuginfo->edges, i);
                record_line_exists(edge, NULL);
            }
            while ((language_value_t*)debuginfo->linetable != language_nothing)
                debuginfo = debuginfo->linetable;
            language_module_t *modu = func ? language_debuginfo_module1(func) : NULL;
            if (modu == NULL)
                modu = ctx.module;
            StringRef file = language_debuginfo_file1(debuginfo);
            if (file.empty())
                file = "<missing>";
            bool is_user_code;
            if (modu == ctx.module)
                is_user_code = mod_is_user_mod;
            else
                is_user_code = in_user_mod(modu);
            bool is_tracked = in_tracked_path(file);
            if (do_coverage(is_user_code, is_tracked)) {
                for (size_t pc = 0; 1; pc++) {
                    struct language_codeloc_t lineidx = language_uncompress1_codeloc(debuginfo->codelocs, pc);
                    if (lineidx.line == -1)
                        break;
                    if (lineidx.line > 0)
                        language_coverage_alloc_line(file, lineidx.line);
                }
            }
        };
        record_line_exists(src->debuginfo, (language_value_t*)lam);
    }

    come_from_bb[0] = ctx.builder.GetInsertBlock();

    // First go through and collect all branch targets, so we know where to
    // split basic blocks.
    std::set<int> branch_targets; // 1-indexed
    {
        for (size_t i = 0; i < stmtslen; ++i) {
            language_value_t *stmt = language_array_ptr_ref(stmts, i);
            if (language_is_gotoifnot(stmt)) {
                int dest = language_gotoifnot_label(stmt);
                branch_targets.insert(dest);
                // The next 1-indexed statement
                branch_targets.insert(i + 2);
            } else if (language_is_returnnode(stmt)) {
                // We don't do dead branch elimination before codegen
                // so we need to make sure to start a BB after any
                // return node, even if they aren't otherwise branch
                // targets.
                if (i + 2 <= stmtslen)
                    branch_targets.insert(i + 2);
            } else if (language_is_enternode(stmt)) {
                branch_targets.insert(i + 1);
                if (i + 2 <= stmtslen)
                    branch_targets.insert(i + 2);
                size_t catch_dest = language_enternode_catch_dest(stmt);
                if (catch_dest)
                    branch_targets.insert(catch_dest);
            } else if (language_is_gotonode(stmt)) {
                int dest = language_gotonode_label(stmt);
                branch_targets.insert(dest);
                if (i + 2 <= stmtslen)
                    branch_targets.insert(i + 2);
            } else if (language_is_phinode(stmt)) {
                language_array_t *edges = (language_array_t*)language_fieldref_noalloc(stmt, 0);
                for (size_t j = 0; j < language_array_nrows(edges); ++j) {
                    size_t edge = language_array_data(edges, int32_t)[j];
                    if (edge == i)
                        branch_targets.insert(i + 1);
                }
            }
        }
    }

    for (int label : branch_targets) {
        BasicBlock *bb = BasicBlock::Create(ctx.builder.getContext(),
            "L" + std::to_string(label), f);
        BB[label] = bb;
    }

    new_lineinfo.push_back(topinfo);
    Value *sync_bytes = nullptr;
    if (do_malloc_log(true, mod_is_tracked))
        sync_bytes = ctx.builder.CreateCall(prepare_call(diff_gc_total_bytes_func), {});
    // coverage for the function definition line number (topinfo)
    coverageVisitStmt();

    find_next_stmt(0);
    while (cursor != -1) {
        bool have_dbg_update = update_lineinfo(cursor);
        if (have_dbg_update) {
            if (debug_enabled)
                ctx.builder.SetCurrentDebugLocation(new_lineinfo.back().loc);
            coverageVisitStmt();
        }
        ctx.noalias().aliasscope.current = aliasscopes[cursor];
        language_value_t *stmt = language_array_ptr_ref(stmts, cursor);
        if (language_is_returnnode(stmt)) {
            language_value_t *retexpr = language_returnnode_value(stmt);
            if (retexpr == NULL) {
                CreateTrap(ctx.builder, false);
                find_next_stmt(-1);
                continue;
            }
            // this is basically a copy of emit_assignment,
            // but where the assignment slot is the retval
            language_cgval_t retvalinfo = emit_expr(ctx, retexpr);

            if (ctx.is_opaque_closure) {
                emit_typecheck(ctx, retvalinfo, jlrettype, "OpaqueClosure");
            }

            retvalinfo = convert_language_type(ctx, retvalinfo, jlrettype);
            if (retvalinfo.typ == language_bottom_type) {
                CreateTrap(ctx.builder, false);
                find_next_stmt(-1);
                continue;
            }

            Value *isboxed_union = NULL;
            Value *retval = NULL;
            Value *sret = has_sret ? f->arg_begin() : NULL;
            Type *retty = f->getReturnType();
            switch (returninfo.cc) {
            case language_returninfo_t::Boxed:
                retval = boxed(ctx, retvalinfo); // skip the gcroot on the return path
                break;
            case language_returninfo_t::Register:
                if (type_is_ghost(retty))
                    retval = NULL;
                else
                    retval = emit_unbox(ctx, retty, retvalinfo, jlrettype);
                break;
            case language_returninfo_t::SRet:
                retval = NULL;
                break;
            case language_returninfo_t::Union: {
                Value *data, *tindex;
                if (retvalinfo.TIndex) {
                    tindex = retvalinfo.TIndex;
                    data = Constant::getNullValue(ctx.types().T_prjlvalue);
                    if (retvalinfo.V == NULL) {
                        // treat this as a simple Ghosts
                        sret = NULL;
                    }
                    else if (retvalinfo.Vboxed) {
                        // also need to account for the possibility the return object is boxed
                        // and avoid / skip copying it to the stack
                        isboxed_union = ctx.builder.CreateICmpNE(
                            ctx.builder.CreateAnd(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                            ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
                        data = ctx.builder.CreateSelect(isboxed_union, retvalinfo.Vboxed, data);
                    }
                }
                else {
                    // treat this as a simple boxed returninfo
                    //assert(retvalinfo.isboxed);
                    tindex = compute_tindex_unboxed(ctx, retvalinfo, jlrettype);
                    tindex = ctx.builder.CreateOr(tindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
                    data = boxed(ctx, retvalinfo);
                    sret = NULL;
                }
                retval = UndefValue::get(retty);
                retval = ctx.builder.CreateInsertValue(retval, data, 0);
                retval = ctx.builder.CreateInsertValue(retval, tindex, 1);
                break;
            }
            case language_returninfo_t::Ghosts:
                retval = compute_tindex_unboxed(ctx, retvalinfo, jlrettype);
                break;
            }
            if (sret) {
                if (retvalinfo.ispointer()) {
                    if (returninfo.return_roots) {
                        Type *store_ty = language_type_to_llvm(ctx, retvalinfo.typ);
                        emit_sret_roots(ctx, true, data_pointer(ctx, retvalinfo), store_ty, f->arg_begin() + 1, get_returnroots_type(ctx, returninfo.return_roots), returninfo.return_roots);
                    }
                    if (returninfo.cc == language_returninfo_t::SRet) {
                        assert(language_is_concrete_type(jlrettype));
                        emit_memcpy(ctx, sret, language_aliasinfo_t::fromTBAA(ctx, nullptr), retvalinfo,
                                    language_datatype_size(jlrettype), language_alignment(jlrettype), language_alignment(jlrettype));
                    }
                    else { // must be language_returninfo_t::Union
                        emit_unionmove(ctx, sret, nullptr, retvalinfo, /*skip*/isboxed_union);
                    }
                }
                else {
                    Type *store_ty = retvalinfo.V->getType();
                    Type *dest_ty = store_ty->getPointerTo();
                    Value *Val = retvalinfo.V;
                    if (returninfo.return_roots) {
                        assert(language_type_to_llvm(ctx, retvalinfo.typ) == store_ty);
                        emit_sret_roots(ctx, false, Val, store_ty, f->arg_begin() + 1, get_returnroots_type(ctx, returninfo.return_roots), returninfo.return_roots);
                    }
                    if (dest_ty != sret->getType())
                        sret = emit_bitcast(ctx, sret, dest_ty);
                    ctx.builder.CreateAlignedStore(Val, sret, Align(language_alignment(retvalinfo.typ)));
                    assert(retvalinfo.TIndex == NULL && "unreachable"); // unimplemented representation
                }
            }

            mallocVisitStmt(sync_bytes, have_dbg_update);
            if (toplevel || ctx.is_opaque_closure)
                ctx.builder.CreateStore(last_age, world_age_field);
            assert(type_is_ghost(retty) || returninfo.cc == language_returninfo_t::SRet ||
                retval->getType() == ctx.f->getReturnType());
            ctx.builder.CreateRet(retval);
            find_next_stmt(-1);
            continue;
        }
        if (language_is_gotonode(stmt)) {
            int lname = language_gotonode_label(stmt);
            come_from_bb[cursor+1] = ctx.builder.GetInsertBlock();
            auto br = ctx.builder.CreateBr(BB[lname]);
            // Check if backwards branch
            if (ctx.LoopID && lname <= current_label) {
                br->setMetadata(LLVMContext::MD_loop, ctx.LoopID);
                ctx.LoopID = NULL;
            }
            find_next_stmt(lname - 1);
            continue;
        }
        if (language_is_upsilonnode(stmt)) {
            emit_upsilonnode(ctx, upsilon_to_phic[cursor + 1], language_fieldref_noalloc(stmt, 0));
            find_next_stmt(cursor + 1);
            continue;
        }
        if (language_is_gotoifnot(stmt)) {
            language_value_t *cond = language_gotoifnot_cond(stmt);
            int lname = language_gotoifnot_label(stmt);
            Value *isfalse = emit_condition(ctx, cond, "if");
            mallocVisitStmt(nullptr, have_dbg_update);
            come_from_bb[cursor+1] = ctx.builder.GetInsertBlock();
            workstack.push_back(lname - 1);
            BasicBlock *ifnot = BB[lname];
            BasicBlock *ifso = BB[cursor+2];
            Instruction *br;
            if (ifnot == ifso)
                br = ctx.builder.CreateBr(ifnot);
            else
                br = ctx.builder.CreateCondBr(isfalse, ifnot, ifso);

            // Check if backwards branch
            if (ctx.LoopID && lname <= current_label) {
                br->setMetadata(LLVMContext::MD_loop, ctx.LoopID);
                ctx.LoopID = NULL;
            }
            find_next_stmt(cursor + 1);
            continue;
        }
        else if (language_is_enternode(stmt)) {
            // For the two-arg version of :enter, twiddle the scope
            Value *scope_ptr = NULL;
            Value *old_scope = NULL;
            language_aliasinfo_t scope_ai = language_aliasinfo_t::fromTBAA(ctx, ctx.tbaa().tbaa_gcframe);
            if (language_enternode_scope(stmt)) {
                language_cgval_t new_scope = emit_expr(ctx, language_enternode_scope(stmt));
                if (new_scope.typ == language_bottom_type) {
                    // Probably dead code, but let's be loud about it in case it isn't, so we fail
                    // at the point of the miscompile, rather than later when something attempts to
                    // read the scope.
                    emit_error(ctx, "(INTERNAL ERROR): Attempted to execute EnterNode with bad scope");
                    find_next_stmt(-1);
                    continue;
                }
                Value *new_scope_boxed = boxed(ctx, new_scope);
                scope_ptr = get_scope_field(ctx);
                old_scope = scope_ai.decorateInst(
                        ctx.builder.CreateAlignedLoad(ctx.types().T_prjlvalue, scope_ptr, ctx.types().alignof_ptr));
                scope_ai.decorateInst(
                    ctx.builder.CreateAlignedStore(new_scope_boxed, scope_ptr, ctx.types().alignof_ptr));
                ctx.scope_restore[cursor] = std::make_pair(old_scope, scope_ptr);
            }
            int lname = language_enternode_catch_dest(stmt);
            if (lname) {
                // Save exception stack depth at enter for use in pop_exception
                Value *excstack_state =
                    ctx.builder.CreateCall(prepare_call(language_excstack_state_func), {get_current_task(ctx)});
                assert(!ctx.ssavalue_assigned[cursor]);
                ctx.SAvalues[cursor] = language_cgval_t(excstack_state, (language_value_t*)language_ulong_type, NULL);
                ctx.ssavalue_assigned[cursor] = true;
                // Actually enter the exception frame
                CallInst *sj = ctx.builder.CreateCall(prepare_call(except_enter_func), {get_current_task(ctx)});
                // We need to mark this on the call site as well. See issue #6757
                sj->setCanReturnTwice();
                Value *isz = ctx.builder.CreateICmpEQ(sj, ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 0));
                BasicBlock *tryblk = BasicBlock::Create(ctx.builder.getContext(), "try", f);
                BasicBlock *catchpop = BasicBlock::Create(ctx.builder.getContext(), "catch_pop", f);
                BasicBlock *handlr = NULL;
                handlr = BB[lname];
                workstack.push_back(lname - 1);
                come_from_bb[cursor + 1] = ctx.builder.GetInsertBlock();
                ctx.builder.CreateCondBr(isz, tryblk, catchpop);
                ctx.builder.SetInsertPoint(catchpop);
                {
                    ctx.builder.CreateCall(prepare_call(jlleave_func), {get_current_task(ctx), ConstantInt::get(getInt32Ty(ctx.builder.getContext()), 1)});
                    if (old_scope) {
                        scope_ai.decorateInst(
                            ctx.builder.CreateAlignedStore(old_scope, scope_ptr, ctx.types().alignof_ptr));
                    }
                    ctx.builder.CreateBr(handlr);
                }
                ctx.builder.SetInsertPoint(tryblk);
            }
        }
        else {
            emit_stmtpos(ctx, stmt, cursor);
            mallocVisitStmt(nullptr, have_dbg_update);
        }
        find_next_stmt(cursor + 1);
    }

    // Delete any unreachable blocks
    for (auto &item : BB) {
        if (!item.second->getTerminator())
            item.second->eraseFromParent();
    }

    ctx.builder.SetCurrentDebugLocation(noDbg);
    ctx.builder.ClearInsertionPoint();

    // Codegen Phi nodes
    std::map<std::pair<BasicBlock*, BasicBlock*>, BasicBlock*> BB_rewrite_map;
    SmallVector<llvm::PHINode*, 0> ToDelete;
    for (auto &tup : ctx.PhiNodes) {
        language_cgval_t phi_result;
        PHINode *VN;
        language_value_t *r;
        AllocaInst *dest;
        BasicBlock *PhiBB;
        std::tie(phi_result, PhiBB, dest, VN, r) = tup;
        language_value_t *phiType = phi_result.typ;
        language_array_t *edges = (language_array_t*)language_fieldref_noalloc(r, 0);
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(r, 1);
        PHINode *TindexN = cast_or_null<PHINode>(phi_result.TIndex);
        DenseSet<BasicBlock*> preds;
        for (size_t i = 0; i < language_array_nrows(edges); ++i) {
            size_t edge = language_array_data(edges, int32_t)[i];
            language_value_t *value = language_array_ptr_ref(values, i);
            // This edge value is undef, handle it the same as if the edge wasn't listed at all
            if (!value)
                continue;
            BasicBlock *FromBB = come_from_bb[edge];
            // This edge was statically unreachable. Don't codegen it.
            if (!FromBB)
                continue;
            // see if this edge has already been rewritten
            // (we'll continue appending blocks to the current end)
            std::pair<BasicBlock*, BasicBlock*> LookupKey(FromBB, PhiBB);
            if (BB_rewrite_map.count(LookupKey)) {
                FromBB = BB_rewrite_map[LookupKey];
            }
            if (!preds.insert(FromBB).second) {
                // Only codegen this branch once for each PHI (the expression must be the same on all branches)
#ifndef NDEBUG
                for (size_t j = 0; j < i; ++j) {
                    size_t j_edge = language_array_data(edges, int32_t)[j];
                    if (j_edge == edge) {
                        assert(language_egal(value, language_array_ptr_ref(values, j)));
                    }
                }
#endif
                continue;
            }
            assert(std::find(pred_begin(PhiBB), pred_end(PhiBB), FromBB) != pred_end(PhiBB)); // consistency check
            TerminatorInst *terminator = FromBB->getTerminator();
            if (!terminator->getParent()->getUniqueSuccessor()) {
                // Can't use `llvm::SplitCriticalEdge` here because
                // we may have invalid phi nodes in the destination.
                BasicBlock *NewBB = BasicBlock::Create(terminator->getContext(),
                   FromBB->getName() + "." + PhiBB->getName() + "_crit_edge", FromBB->getParent(), FromBB->getNextNode()); // insert after existing block
                terminator->replaceSuccessorWith(PhiBB, NewBB);
                DebugLoc Loc = terminator->getDebugLoc();
                terminator = BranchInst::Create(PhiBB);
                terminator->setDebugLoc(Loc);
                ctx.builder.SetInsertPoint(NewBB);
            }
            else {
                terminator->removeFromParent();
                ctx.builder.SetInsertPoint(FromBB);
            }
            if (dest)
                ctx.builder.CreateLifetimeStart(dest);
            language_cgval_t val = emit_expr(ctx, value);
            if (val.constant)
                val = mark_language_const(ctx, val.constant); // be over-conservative at making sure `.typ` is set concretely, not tindex
            if (!language_is_uniontype(phiType) || !TindexN) {
                if (VN) {
                    Value *V;
                    if (val.typ == (language_value_t*)language_bottom_type) {
                        V = undef_value_for_type(VN->getType());
                    }
                    else if (VN->getType() == ctx.types().T_prjlvalue) {
                        // Includes the language_is_uniontype(phiType) && !TindexN case
                        // TODO: if convert_language_type says it is wasted effort and to skip it, is it worth using Constant::getNullValue(ctx.types().T_prjlvalue) (dynamically)?
                        V = boxed(ctx, val);
                    }
                    else {
                        // must be careful to emit undef here (rather than a bitcast or
                        // load of val) if the runtime type of val isn't phiType
                        Value *isvalid = emit_isa_and_defined(ctx, val, phiType);
                        V = emit_guarded_test(ctx, isvalid, undef_value_for_type(VN->getType()), [&] {
                            return emit_unbox(ctx, VN->getType(), val, phiType);
                        });
                    }
                    VN->addIncoming(V, ctx.builder.GetInsertBlock());
                    assert(!TindexN);
                }
                else if (dest && val.typ != (language_value_t*)language_bottom_type) {
                    // must be careful to emit undef here (rather than a bitcast or
                    // load of val) if the runtime type of val isn't phiType
                    Value *isvalid = emit_isa_and_defined(ctx, val, phiType);
                    emit_guarded_test(ctx, isvalid, nullptr, [&] {
                        emit_unbox_store(ctx, update_language_type(ctx, val, phiType), dest, ctx.tbaa().tbaa_stack, language_alignment(phiType));
                        return nullptr;
                    });
                }
            }
            else {
                Value *RTindex;
                // The branch below is a bit too complex for GCC to realize that
                // `V` is always initialized when it is used.
                // Ref https://gcc.gnu.org/bugzilla/show_bug.cgi?id=96629
                Value *V = nullptr;
                if (val.typ == (language_value_t*)language_bottom_type) {
                    if (VN)
                        V = undef_value_for_type(VN->getType());
                    RTindex = UndefValue::get(getInt8Ty(ctx.builder.getContext()));
                }
                else if (language_is_concrete_type(val.typ) || val.constant) {
                    size_t tindex = get_box_tindex((language_datatype_t*)val.typ, phiType);
                    if (tindex == 0) {
                        if (VN)
                            V = boxed(ctx, val);
                        RTindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER);
                    }
                    else {
                        if (VN)
                            V = Constant::getNullValue(ctx.types().T_prjlvalue);
                        if (dest)
                            emit_unbox_store(ctx, val, dest, ctx.tbaa().tbaa_stack, language_alignment(val.typ));
                        RTindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), tindex);
                    }
                }
                else {
                    Value *skip = NULL;
                    // must compute skip here, since the runtime type of val might not be in phiType
                    // caution: only Phi and PhiC are allowed to do this (and maybe sometimes Pi)
                    language_cgval_t new_union = convert_language_type(ctx, val, phiType, &skip);
                    RTindex = new_union.TIndex;
                    if (!RTindex) {
                        assert(new_union.isboxed && new_union.Vboxed && "convert_language_type failed");
                        RTindex = compute_tindex_unboxed(ctx, new_union, phiType, true);
                        if (dest) {
                            // If dest is not set, this is a ghost union, the recipient of which
                            // is often not prepared to handle a boxed representation of the ghost.
                            RTindex = ctx.builder.CreateOr(RTindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER));
                        }
                        new_union.TIndex = RTindex;
                    }
                    if (VN)
                        V = new_union.Vboxed ? new_union.Vboxed : Constant::getNullValue(ctx.types().T_prjlvalue);
                    if (dest) { // basically, if !ghost union
                        if (new_union.Vboxed != nullptr) {
                            Value *isboxed = ctx.builder.CreateICmpNE( // if UNION_BOX_MARKER is set, we won't select this slot anyways
                                    ctx.builder.CreateAnd(RTindex, ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER)),
                                    ConstantInt::get(getInt8Ty(ctx.builder.getContext()), 0));
                            skip = skip ? ctx.builder.CreateOr(isboxed, skip) : isboxed;
                        }
                        emit_unionmove(ctx, dest, ctx.tbaa().tbaa_arraybuf, new_union, skip);
                    }
                }
                if (VN)
                    VN->addIncoming(V, ctx.builder.GetInsertBlock());
                if (TindexN)
                    TindexN->addIncoming(RTindex, ctx.builder.GetInsertBlock());
            }
            // put the branch back at the end of our current basic block
            ctx.builder.Insert(terminator);
            // Record the current tail of this Phi edge in the rewrite map and
            // check any phi nodes in the Phi block to see if by emitting on the edges
            // we made things inconsistent.
            BasicBlock *NewBB = ctx.builder.GetInsertBlock();
            if (FromBB != NewBB) {
                BB_rewrite_map[LookupKey] = NewBB;
                preds.insert(NewBB);
                PhiBB->replacePhiUsesWith(FromBB, NewBB);
            }
            ctx.builder.ClearInsertionPoint();
        }
        // In LLVM IR it is illegal to have phi nodes without incoming values, even if
        // there are no operands (no incoming branches), so delete any such phi nodes
        if (pred_empty(PhiBB)) {
            if (VN)
                ToDelete.push_back(VN);
            if (TindexN)
                ToDelete.push_back(TindexN);
            continue;
        }
        // Julia PHINodes may be incomplete with respect to predecessors, LLVM's may not
        for (auto *FromBB : predecessors(PhiBB)) {
            if (preds.count(FromBB))
                continue;
            ctx.builder.SetInsertPoint(FromBB->getTerminator());
            // PHI is undef on this branch. But still may need to put a valid pointer in place.
            Value *RTindex = TindexN ? UndefValue::get(getInt8Ty(ctx.builder.getContext())) : NULL;
            if (VN) {
                Value *undef = undef_value_for_type(VN->getType());
                VN->addIncoming(undef, FromBB);
                if (TindexN) // let the runtime / optimizer know this is unknown / boxed / null, so that it won't try to union_move / copy it later
                    RTindex = ConstantInt::get(getInt8Ty(ctx.builder.getContext()), UNION_BOX_MARKER);
            }
            if (TindexN)
                TindexN->addIncoming(RTindex, FromBB);
            if (dest) {
                ctx.builder.CreateLifetimeStart(dest);
                if (CountTrackedPointers(dest->getAllocatedType()).count)
                    ctx.builder.CreateStore(Constant::getNullValue(dest->getAllocatedType()), dest);
            }
            ctx.builder.ClearInsertionPoint();
        }
    }

    for (PHINode *PN : ToDelete) {
        // This basic block is statically unreachable, thus so is this PHINode
        PN->replaceAllUsesWith(UndefValue::get(PN->getType()));
        PN->eraseFromParent();
    }

    // step 12. Perform any delayed instantiations
    bool in_prologue = true;
    for (auto &BB : *ctx.f) {
        for (auto &I : BB) {
            CallBase *call = dyn_cast<CallBase>(&I);
            if (call) {
                if (debug_enabled && !I.getDebugLoc()) {
                    // LLVM Verifier: inlinable function call in a function with debug info must have a !dbg location
                    // make sure that anything we attempt to call has some inlining info, just in case optimization messed up
                    // (except if we know that it is an intrinsic used in our prologue, which should never have its own debug subprogram)
                    Function *F = call->getCalledFunction();
                    if (!in_prologue || !F || !(F->isIntrinsic() || F->getName().startswith("julia.") || &I == restTuple)) {
                        I.setDebugLoc(topdebugloc);
                    }
                }
                if (toplevel && !ctx.is_opaque_closure && !in_prologue) {
                    // we're at toplevel; insert an atomic barrier between every instruction
                    // TODO: inference is invalid if this has any effect (which it often does)
                    LoadInst *world = new LoadInst(ctx.types().T_size,
                        prepare_global_in(language_Module, jlgetworld_global), Twine(),
                        /*isVolatile*/false, ctx.types().alignof_ptr, /*insertBefore*/&I);
                    world->setOrdering(AtomicOrdering::Acquire);
                    StoreInst *store_world = new StoreInst(world, world_age_field,
                        /*isVolatile*/false, ctx.types().alignof_ptr, /*insertBefore*/&I);
                    (void)store_world;
                }
            }
            if (&I == &prologue_end)
                in_prologue = false;
        }
    }
    if (debug_enabled)
        dbuilder.finalize();

    if (ctx.vaSlot > 0) {
        // remove VA allocation if we never referenced it
        Instruction *root = cast_or_null<Instruction>(ctx.slots[ctx.vaSlot].boxroot);
        if (root) {
            Instruction *store_value = NULL;
            bool have_real_use = false;
            for (Use &U : root->uses()) {
                User *RU = U.getUser();
                if (StoreInst *SRU = dyn_cast<StoreInst>(RU)) {
                    if (!store_value)
                        store_value = dyn_cast<Instruction>(SRU->getValueOperand());
                }
                else if (isa<DbgInfoIntrinsic>(RU)) {
                }
                else if (isa<LoadInst>(RU) && RU->use_empty()) {
                }
                else {
                    have_real_use = true;
                    break;
                }
            }
            if (!have_real_use) {
                Instruction *use = NULL;
                for (Use &U : root->uses()) {
                    if (use) // erase after the iterator moves on
                        use->eraseFromParent();
                    User *RU = U.getUser();
                    use = cast<Instruction>(RU);
                }
                if (use)
                    use->eraseFromParent();
                root->eraseFromParent();
                assert(!store_value || store_value == restTuple);
                restTuple->eraseFromParent();
            }
        }
    }

    // link the dependent llvmcall modules, but switch their function's linkage to internal
    // so that they don't conflict when they show up in the execution engine.
    Linker L(*language_Module);
    for (auto &Mod : ctx.llvmcall_modules) {
        SmallVector<std::string, 1> Exports;
        for (const auto &F: Mod->functions())
            if (!F.isDeclaration())
                Exports.push_back(F.getName().str());
        bool error = L.linkInModule(std::move(Mod));
        assert(!error && "linking llvmcall modules failed");
        (void)error;
        for (auto FN: Exports)
            language_Module->getFunction(FN)->setLinkage(GlobalVariable::InternalLinkage);
    }

    LANGUAGE_GC_POP();
    return declarations;
}

// --- entry point ---

void language_add_code_in_flight(StringRef name, language_code_instance_t *codeinst, const DataLayout &DL);

LANGUAGE_GCC_IGNORE_START("-Wclobbered")
language_llvm_functions_t language_emit_code(
        orc::ThreadSafeModule &m,
        language_method_instance_t *li,
        language_code_info_t *src,
        language_value_t *jlrettype,
        language_codegen_params_t &params,
        size_t min_world, size_t max_world)
{
    LANGUAGE_TIMING(CODEGEN, CODEGEN_LLVM);
    language_timing_show_func_sig((language_value_t *)li->specTypes, LANGUAGE_TIMING_DEFAULT_BLOCK);
    // caller must hold codegen_lock
    language_llvm_functions_t decls = {};
    assert((params.params == &language_default_cgparams /* fast path */ || !params.cache ||
        compare_cgparams(params.params, &language_default_cgparams)) &&
        "functions compiled with custom codegen params must not be cached");
    LANGUAGE_TRY {
        decls = emit_function(m, li, src, jlrettype, params, min_world, max_world);
        auto stream = *language_ExecutionEngine->get_dump_emitted_mi_name_stream();
        if (stream) {
            language_printf(stream, "%s\t", decls.specFunctionObject.c_str());
            // NOTE: We print the Type Tuple without surrounding quotes, because the quotes
            // break CSV parsing if there are any internal quotes in the Type name (e.g. in
            // Symbol("...")). The \t delineator should be enough to ensure whitespace is
            // handled correctly. (And we don't need to worry about any tabs in the printed
            // string, because tabs are printed as "\t" by `show`.)
            language_static_show(stream, li->specTypes);
            language_printf(stream, "\n");
        }
    }
    LANGUAGE_CATCH {
        // Something failed! This is very, very bad.
        // Try to pretend that it isn't and attempt to recover.
        std::string mname = m.getModuleUnlocked()->getModuleIdentifier();
        m = orc::ThreadSafeModule();
        decls.functionObject = "";
        decls.specFunctionObject = "";
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "Internal error: encountered unexpected error during compilation of %s:\n", mname.c_str());
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(language_current_task));
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
        jlbacktrace(); // written to STDERR_FILENO
#ifndef LANGUAGE_NDEBUG
        abort();
#endif
    }

    return decls;
}

static language_llvm_functions_t language_emit_oc_wrapper(orc::ThreadSafeModule &m, language_codegen_params_t &params, language_method_instance_t *mi, language_value_t *rettype)
{
    Module *M = m.getModuleUnlocked();
    language_codectx_t ctx(M->getContext(), params, 0, 0);
    ctx.name = M->getModuleIdentifier().data();
    std::string funcName = get_function_name(true, false, ctx.name, ctx.emission_context.TargetTriple);
    language_llvm_functions_t declarations;
    declarations.functionObject = "language_f_opaque_closure_call";
    if (uses_specsig(mi->specTypes, false, rettype, true)) {
        language_returninfo_t returninfo = get_specsig_function(ctx, M, NULL, funcName, mi->specTypes, rettype, true, LANGUAGE_FEAT_TEST(ctx,gcstack_arg));
        Function *gf_thunk = cast<Function>(returninfo.decl.getCallee());
        language_init_function(gf_thunk, ctx.emission_context.TargetTriple);
        size_t nrealargs = language_nparams(mi->specTypes);
        emit_cfunc_invalidate(gf_thunk, returninfo.cc, returninfo.return_roots, mi->specTypes, rettype, true, nrealargs, ctx.emission_context, ctx.min_world, ctx.max_world);
        declarations.specFunctionObject = funcName;
    }
    return declarations;
}

static int effects_foldable(uint32_t effects)
{
    // N.B.: This needs to be kept in sync with Core.Compiler.is_foldable(effects, true)
    return ((effects & 0x7) == 0) && // is_consistent(effects)
           (((effects >> 10) & 0x03) == 0) && // is_noub(effects)
           (((effects >> 3) & 0x03) == 0) && // is_effect_free(effects)
           ((effects >> 6) & 0x01); // is_terminates(effects)
}

language_llvm_functions_t language_emit_codeinst(
        orc::ThreadSafeModule &m,
        language_code_instance_t *codeinst,
        language_code_info_t *src,
        language_codegen_params_t &params)
{
    LANGUAGE_TIMING(CODEGEN, CODEGEN_Codeinst);
    language_timing_show_method_instance(codeinst->def, LANGUAGE_TIMING_DEFAULT_BLOCK);
    LANGUAGE_GC_PUSH1(&src);
    if (!src) {
        src = (language_code_info_t*)language_atomic_load_relaxed(&codeinst->inferred);
        language_method_t *def = codeinst->def->def.method;
        // Check if this is the generic method for opaque closure wrappers -
        // if so, generate the specsig -> invoke converter.
        if (def == language_opaque_closure_method) {
            LANGUAGE_GC_POP();
            return language_emit_oc_wrapper(m, params, codeinst->def, codeinst->rettype);
        }
        if (src && (language_value_t*)src != language_nothing && language_is_method(def))
            src = language_uncompress_ir(def, codeinst, (language_value_t*)src);
        if (!src || !language_is_code_info(src)) {
            LANGUAGE_GC_POP();
            m = orc::ThreadSafeModule();
            return language_llvm_functions_t(); // failed
        }
    }
    assert(language_egal((language_value_t*)language_atomic_load_relaxed(&codeinst->debuginfo), (language_value_t*)src->debuginfo) && "trying to generate code for a codeinst for an incompatible src");
    language_llvm_functions_t decls = language_emit_code(m, codeinst->def, src, codeinst->rettype, params,
        language_atomic_load_relaxed(&codeinst->min_world), language_atomic_load_relaxed(&codeinst->max_world));

    const std::string &specf = decls.specFunctionObject;
    const std::string &f = decls.functionObject;
    if (params.cache && !f.empty()) {
        // Prepare debug info to receive this function
        // record that this function name came from this linfo,
        // so we can build a reverse mapping for debug-info.
        bool toplevel = !language_is_method(codeinst->def->def.method);
        if (!toplevel) {
            //Safe b/c params holds context lock
            const DataLayout &DL = m.getModuleUnlocked()->getDataLayout();
            // but don't remember toplevel thunks because
            // they may not be rooted in the gc for the life of the program,
            // and the runtime doesn't notify us when the code becomes unreachable :(
            if (!specf.empty())
                language_add_code_in_flight(specf, codeinst, DL);
            if (!f.empty() && f != "language_fptr_args" && f != "language_fptr_sparam")
                language_add_code_in_flight(f, codeinst, DL);
        }

        language_value_t *inferred = language_atomic_load_relaxed(&codeinst->inferred);
        // don't change inferred state
        if (inferred) {
            language_method_t *def = codeinst->def->def.method;
            if (// keep code when keeping everything
                !(LANGUAGE_DELETE_NON_INLINEABLE) ||
                // aggressively keep code when debugging level >= 2
                // note that this uses the global language_options.debug_level, not the local emission_ctx.debug_level
                language_options.debug_level > 1) {
                // update the stored code
                if (inferred != (language_value_t*)src) {
                    // TODO: it is somewhat unclear what it means to be mutating this
                    if (language_is_method(def)) {
                        src = (language_code_info_t*)language_compress_ir(def, src);
                        assert(language_is_string(src));
                        codeinst->relocatability = language_string_data(src)[language_string_len(src)-1];
                    }
                    language_atomic_store_release(&codeinst->inferred, (language_value_t*)src);
                    language_gc_wb(codeinst, src);
                }
            }
            // delete non-inlineable code, since it won't be needed again
            // because we already emitted LLVM code from it and the native
            // Julia-level optimization will never need to see it
            else if (language_is_method(def) && // don't delete toplevel code
                        def->source != NULL && // don't delete code from optimized opaque closures that can't be reconstructed
                        inferred != language_nothing && // and there is something to delete (test this before calling language_ir_inlining_cost)
                        !effects_foldable(codeinst->ipo_purity_bits) && // don't delete code we may want for irinterp
                        ((language_ir_inlining_cost(inferred) == UINT16_MAX) || // don't delete inlineable code
                        language_atomic_load_relaxed(&codeinst->invoke) == language_fptr_const_return_addr) && // unless it is constant
                        !(params.imaging_mode || language_options.incremental)) { // don't delete code when generating a precompile file
                // Never end up in a situation where the codeinst has no invoke, but also no source, so we never fall
                // through the cracks of SOURCE_MODE_ABI.
                language_atomic_store_release(&codeinst->invoke, &language_fptr_wait_for_compiled);
                language_atomic_store_release(&codeinst->inferred, language_nothing);
            }
        }
    }
    LANGUAGE_GC_POP();
    return decls;
}


void language_compile_workqueue(
    language_codegen_params_t &params,
    CompilationPolicy policy)
{
    LANGUAGE_TIMING(CODEGEN, CODEGEN_Workqueue);
    language_code_info_t *src = NULL;
    LANGUAGE_GC_PUSH1(&src);
    while (!params.workqueue.empty()) {
        language_code_instance_t *codeinst;
        auto it = params.workqueue.back();
        codeinst = it.first;
        auto proto = it.second;
        params.workqueue.pop_back();
        // try to emit code for this item from the workqueue
        StringRef preal_decl = "";
        bool preal_specsig = false;
        auto invoke = language_atomic_load_acquire(&codeinst->invoke);
        bool cache_valid = params.cache;
        // WARNING: isspecsig is protected by the codegen-lock. If that lock is removed, then the isspecsig load needs to be properly atomically sequenced with this.
        if (cache_valid && invoke != NULL && invoke != &language_fptr_wait_for_compiled) {
            auto fptr = language_atomic_load_relaxed(&codeinst->specptr.fptr);
            if (fptr) {
                while (!(language_atomic_load_acquire(&codeinst->specsigflags) & 0b10)) {
                    language_cpu_pause();
                }
                // in case we are racing with another thread that is emitting this function
                invoke = language_atomic_load_relaxed(&codeinst->invoke);
            }
            if (invoke == language_fptr_args_addr) {
                preal_decl = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)fptr, codeinst);
            }
            else if (language_atomic_load_relaxed(&codeinst->specsigflags) & 0b1) {
                preal_decl = language_ExecutionEngine->getFunctionAtAddress((uintptr_t)fptr, codeinst);
                preal_specsig = true;
            }
        }
        else {
            auto it = params.compiled_functions.find(codeinst);
            if (it == params.compiled_functions.end()) {
                // Reinfer the function. The JIT came along and removed the inferred
                // method body. See #34993
                if (policy != CompilationPolicy::Default &&
                    language_atomic_load_relaxed(&codeinst->inferred) == language_nothing) {
                    // Codegen lock is held, so SOURCE_MODE_FORCE_SOURCE_UNCACHED is not required
                    codeinst = language_type_infer(codeinst->def, language_atomic_load_relaxed(&codeinst->max_world), 0, SOURCE_MODE_FORCE_SOURCE);
                }
                if (codeinst) {
                    orc::ThreadSafeModule result_m =
                        language_create_ts_module(name_from_method_instance(codeinst->def),
                            params.tsctx, params.DL, params.TargetTriple);
                    auto decls = language_emit_codeinst(result_m, codeinst, NULL, params);
                    if (result_m)
                        it = params.compiled_functions.insert(std::make_pair(codeinst, std::make_pair(std::move(result_m), std::move(decls)))).first;
                }
            }
            if (it != params.compiled_functions.end()) {
                auto &decls = it->second.second;
                if (decls.functionObject == "language_fptr_args") {
                    preal_decl = decls.specFunctionObject;
                }
                else if (decls.functionObject != "language_fptr_sparam") {
                    preal_decl = decls.specFunctionObject;
                    preal_specsig = true;
                }
            }
        }
        // patch up the prototype we emitted earlier
        Module *mod = proto.decl->getParent();
        assert(proto.decl->isDeclaration());
        if (proto.specsig) {
            // expected specsig
            if (!preal_specsig) {
                // emit specsig-to-(jl)invoke conversion
                Function *preal = emit_tojlinvoke(codeinst, mod, params);
                proto.decl->setLinkage(GlobalVariable::InternalLinkage);
                //protodecl->setAlwaysInline();
                language_init_function(proto.decl, params.TargetTriple);
                size_t nrealargs = language_nparams(codeinst->def->specTypes); // number of actual arguments being passed
                // TODO: maybe this can be cached in codeinst->specfptr?
                emit_cfunc_invalidate(proto.decl, proto.cc, proto.return_roots, codeinst->def->specTypes, codeinst->rettype, false, nrealargs, params, preal, 0, 0);
                preal_decl = ""; // no need to fixup the name
            }
            else {
                assert(!preal_decl.empty());
            }
        }
        else {
            // expected non-specsig
            if (preal_decl.empty() || preal_specsig) {
                // emit jlcall1-to-(jl)invoke conversion
                preal_decl = emit_tojlinvoke(codeinst, mod, params)->getName();
            }
        }
        if (!preal_decl.empty()) {
            // merge and/or rename this prototype to the real function
            if (Value *specfun = mod->getNamedValue(preal_decl)) {
                if (proto.decl != specfun)
                    proto.decl->replaceAllUsesWith(specfun);
            }
            else {
                proto.decl->setName(preal_decl);
            }
        }
    }
    LANGUAGE_GC_POP();
}


// --- initialization ---
SmallVector<std::pair<language_value_t**, JuliaVariable*>, 0> gv_for_global;
static void global_jlvalue_to_llvm(JuliaVariable *var, language_value_t **addr)
{
    gv_for_global.push_back(std::make_pair(addr, var));
}
static JuliaVariable *language_const_gv(language_value_t *val)
{
    for (auto &kv : gv_for_global) {
        if (*kv.first == val)
            return kv.second;
    }
    return nullptr;
}

static void init_jit_functions(void)
{
    add_named_global(language_small_typeof_var, &language_small_typeof);
    add_named_global(jlstack_chk_guard_var, &__stack_chk_guard);
    add_named_global(jlRTLD_DEFAULT_var, &language_RTLD_DEFAULT_handle);
    add_named_global(jlexe_var, &language_exe_handle);
    add_named_global(jldll_var, &language_liblanguage_handle);
    add_named_global(jldlli_var, &language_liblanguage_internal_handle);
    auto size2pjlvalue = [](Type *T_size) -> Type * {
        return get_pjlvalue(T_size->getContext());
    };
    global_jlvalue_to_llvm(new JuliaVariable{"language_true", true, size2pjlvalue}, &language_true);
    global_jlvalue_to_llvm(new JuliaVariable{"language_false", true, size2pjlvalue}, &language_false);
    global_jlvalue_to_llvm(new JuliaVariable{"language_nothing", true, size2pjlvalue}, &language_nothing);
    global_jlvalue_to_llvm(new JuliaVariable{"language_emptysvec", true, size2pjlvalue}, (language_value_t**)&language_emptysvec);
    global_jlvalue_to_llvm(new JuliaVariable{"language_emptytuple", true, size2pjlvalue}, &language_emptytuple);
    global_jlvalue_to_llvm(new JuliaVariable{"language_diverror_exception", true, size2pjlvalue}, &language_diverror_exception);
    global_jlvalue_to_llvm(new JuliaVariable{"language_undefref_exception", true, size2pjlvalue}, &language_undefref_exception);
    add_named_global(jlgetworld_global, &language_world_counter);
    add_named_global("__stack_chk_fail", &__stack_chk_fail);
    add_named_global(jlpgcstack_func, (void*)NULL);
    add_named_global(jlerror_func, &language_error);
    add_named_global(jlatomicerror_func, &language_atomic_error);
    add_named_global(jlthrow_func, &language_throw);
    add_named_global(jlundefvarerror_func, &language_undefined_var_error);
    add_named_global(jlhasnofield_func, &language_has_no_field_error);
    add_named_global(jlboundserrorv_func, &language_bounds_error_ints);
    add_named_global(jlboundserror_func, &language_bounds_error_int);
    add_named_global(jlvboundserror_func, &language_bounds_error_tuple_int);
    add_named_global(jluboundserror_func, &language_bounds_error_unboxed_int);
    add_named_global(jlnew_func, &language_new_structv);
    add_named_global(jlsplatnew_func, &language_new_structt);
    add_named_global(setjmp_func, &language_setjmp_f);
    add_named_global(memcmp_func, &memcmp);
    add_named_global(jltypeerror_func, &language_type_error);
    add_named_global(jlcheckassign_func, &language_checked_assignment);
    add_named_global(jldeclareconst_func, &language_declare_constant);
    add_named_global(jlgetbindingorerror_func, &language_get_binding_or_error);
    add_named_global(jlgetbindingwrorerror_func, &language_get_binding_wr);
    add_named_global(jlboundp_func, &language_boundp);
    for (auto it : builtin_func_map())
        add_named_global(it.second, it.first);
    add_named_global(jlintrinsic_func, &language_f_intrinsic_call);
    add_named_global(jlgetbuiltinfptr_func, &language_get_builtin_fptr);
    add_named_global(jlapplygeneric_func, &language_apply_generic);
    add_named_global(jlinvoke_func, &language_invoke);
    add_named_global(jltopeval_func, &language_toplevel_eval);
    add_named_global(jlcopyast_func, &language_copy_ast);
    //add_named_global(jlnsvec_func, &language_svec);
    add_named_global(jlmethod_func, &language_method_def);
    add_named_global(jlgenericfunction_func, &language_generic_function_def);
    add_named_global(jlenter_func, &language_enter_handler);
    add_named_global(language_current_exception_func, &language_current_exception);
    add_named_global(jlleave_noexcept_func, &language_pop_handler_noexcept);
    add_named_global(jlleave_func, &language_pop_handler);
    add_named_global(language_restore_excstack_func, &language_restore_excstack);
    add_named_global(language_excstack_state_func, &language_excstack_state);
    add_named_global(jlegalx_func, &language_egal__unboxed);
    add_named_global(jlisa_func, &language_isa);
    add_named_global(jlsubtype_func, &language_subtype);
    add_named_global(jltypeassert_func, &language_typeassert);
    add_named_global(jlapplytype_func, &language_instantiate_type_in_env);
    add_named_global(language_object_id__func, &language_object_id_);
    add_named_global(language_alloc_obj_func, (void*)NULL);
    add_named_global(language_newbits_func, (void*)language_new_bits);
    add_named_global(language_typeof_func, (void*)NULL);
    add_named_global(language_write_barrier_func, (void*)NULL);
    add_named_global(jldlsym_func, &language_load_and_lookup);
    add_named_global("language_adopt_thread", &language_adopt_thread);
    add_named_global(jlgetcfunctiontrampoline_func, &language_get_cfunction_trampoline);
    add_named_global(jlgetnthfieldchecked_func, &language_get_nth_field_checked);
    add_named_global(jlfieldindex_func, &language_field_index);
    add_named_global(diff_gc_total_bytes_func, &language_gc_diff_total_bytes);
    add_named_global(sync_gc_total_bytes_func, &language_gc_sync_total_bytes);
    add_named_global(language_allocgenericmemory, &language_alloc_genericmemory);
    add_named_global(gcroot_flush_func, (void*)NULL);
    add_named_global(gc_preserve_begin_func, (void*)NULL);
    add_named_global(gc_preserve_end_func, (void*)NULL);
    add_named_global(pointer_from_objref_func, (void*)NULL);
    add_named_global(except_enter_func, (void*)NULL);
    add_named_global(language_call, (void*)NULL);
    add_named_global(language_call2, (void*)NULL);
    add_named_global(jllockvalue_func, &language_lock_value);
    add_named_global(jlunlockvalue_func, &language_unlock_value);
    add_named_global(jllockfield_func, &language_lock_field);
    add_named_global(jlunlockfield_func, &language_unlock_field);

#ifdef _OS_WINDOWS_
#if defined(_CPU_X86_64_)
#if defined(_COMPILER_GCC_)
    add_named_global("___chkstk_ms", &___chkstk_ms);
#else
    add_named_global("__chkstk", &__chkstk);
#endif
#else
#if defined(_COMPILER_GCC_)
    add_named_global("_alloca", &_alloca);
#else
    add_named_global("_chkstk", &_chkstk);
#endif
#endif
#endif

#define BOX_F(ct) add_named_global(XSTR(language_box_##ct), &language_box_##ct);
    BOX_F(int8); BOX_F(uint8);
    BOX_F(int16); BOX_F(uint16);
    BOX_F(int32); BOX_F(uint32);
    BOX_F(int64); BOX_F(uint64);
    BOX_F(float32); BOX_F(float64);
    BOX_F(char); BOX_F(ssavalue);
#undef BOX_F
}

#ifdef LANGUAGE_USE_INTEL_JITEVENTS
char language_using_intel_jitevents; // Non-zero if running under Intel VTune Amplifier
#endif

#ifdef LANGUAGE_USE_OPROFILE_JITEVENTS
char language_using_oprofile_jitevents = 0; // Non-zero if running under OProfile
#endif

#ifdef LANGUAGE_USE_PERF_JITEVENTS
char language_using_perf_jitevents = 0;
#endif

int language_is_timing_passes = 0;

#if LANGUAGE_LLVM_VERSION < 170000
int language_opaque_ptrs_set = 0;
#endif

extern "C" void language_init_llvm(void)
{
    language_page_size = language_getpagesize();
    language_default_debug_info_kind = (int) DICompileUnit::DebugEmissionKind::FullDebug;
    language_default_cgparams.debug_info_level = (int) language_options.debug_level;
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    InitializeNativeTargetDisassembler();

    // Initialize passes
    PassRegistry &Registry = *PassRegistry::getPassRegistry();
    initializeCore(Registry);
    initializeScalarOpts(Registry);
    initializeVectorization(Registry);
    initializeAnalysis(Registry);
    initializeTransformUtils(Registry);
    initializeInstCombine(Registry);
#if LANGUAGE_LLVM_VERSION >= 160000
    // TODO
#else
    initializeAggressiveInstCombine(Registry);
    initializeInstrumentation(Registry);
#endif
    initializeTarget(Registry);
#ifdef USE_POLLY
    polly::initializePollyPasses(Registry);
#endif

    // Parse command line flags after initialization
    StringMap<cl::Option*> &llvmopts = cl::getRegisteredOptions();
    const char *const argv[1] = {"julia"};
    cl::ParseCommandLineOptions(1, argv, "", nullptr, "JULIA_LLVM_ARGS");

    // Set preferred non-default options
    cl::Option *clopt;
    clopt = llvmopts.lookup("enable-tail-merge"); // NOO TOUCHIE; NO TOUCH! See #922
    if (clopt->getNumOccurrences() == 0)
        cl::ProvidePositionalOption(clopt, "0", 1);
    // For parity with LoopUnswitch
    clopt = llvmopts.lookup("unswitch-threshold");
    if (clopt->getNumOccurrences() == 0)
        cl::ProvidePositionalOption(clopt, "100", 1);
    // if the patch adding this option has been applied, lower its limit to provide
    // better DAGCombiner performance.
    clopt = llvmopts.lookup("combiner-store-merge-dependence-limit");
    if (clopt && clopt->getNumOccurrences() == 0)
        cl::ProvidePositionalOption(clopt, "4", 1);

    #if LANGUAGE_LLVM_VERSION < 170000
    // we want the opaque-pointers to be opt-in, per LLVMContext, for this release
    // so change the default value back to pre-14.x, without changing the NumOccurrences flag for it
    clopt = llvmopts.lookup("opaque-pointers");
    if (clopt && clopt->getNumOccurrences() == 0) {
        clopt->addOccurrence(1, clopt->ArgStr, "false", true);
    } else {
        language_opaque_ptrs_set = 1;
    }
    #endif

    clopt = llvmopts.lookup("time-passes");
    if (clopt && clopt->getNumOccurrences() > 0)
        language_is_timing_passes = 1;

    language_ExecutionEngine = new JuliaOJIT();

    bool language_using_gdb_jitevents = false;
    // Register GDB event listener
#if defined(LANGUAGE_DEBUG_BUILD)
    language_using_gdb_jitevents = true;
#endif
    const char *jit_gdb = getenv("ENABLE_GDBLISTENER");
    if (jit_gdb) {
        language_using_gdb_jitevents = !!atoi(jit_gdb);
    }
    if (language_using_gdb_jitevents)
        language_ExecutionEngine->enableJITDebuggingSupport();

#if defined(LANGUAGE_USE_INTEL_JITEVENTS) || \
    defined(LANGUAGE_USE_OPROFILE_JITEVENTS) || \
    defined(LANGUAGE_USE_PERF_JITEVENTS)
#ifdef LANGUAGE_USE_JITLINK
#pragma message("JIT profiling support (LANGUAGE_USE_*_JITEVENTS) not yet available on platforms that use JITLink")
#else
    const char *jit_profiling = getenv("ENABLE_JITPROFILING");

#if defined(LANGUAGE_USE_INTEL_JITEVENTS)
    if (jit_profiling && atoi(jit_profiling)) {
        language_using_intel_jitevents = 1;
    }
#endif

#if defined(LANGUAGE_USE_OPROFILE_JITEVENTS)
    if (jit_profiling && atoi(jit_profiling)) {
        language_using_oprofile_jitevents = 1;
    }
#endif

#if defined(LANGUAGE_USE_PERF_JITEVENTS)
    if (jit_profiling && atoi(jit_profiling)) {
        language_using_perf_jitevents= 1;
    }
#endif

#ifdef LANGUAGE_USE_INTEL_JITEVENTS
    if (language_using_intel_jitevents)
        language_ExecutionEngine->RegisterJITEventListener(JITEventListener::createIntelJITEventListener());
#endif

#ifdef LANGUAGE_USE_OPROFILE_JITEVENTS
    if (language_using_oprofile_jitevents)
        language_ExecutionEngine->RegisterJITEventListener(JITEventListener::createOProfileJITEventListener());
#endif

#ifdef LANGUAGE_USE_PERF_JITEVENTS
    if (language_using_perf_jitevents)
        language_ExecutionEngine->RegisterJITEventListener(JITEventListener::createPerfJITEventListener());
#endif
#endif
#endif

    cl::PrintOptionValues();
}

extern "C" LANGUAGE_DLLEXPORT_CODEGEN void language_init_codegen_impl(void)
{
    language_init_llvm();
    // Now that the execution engine exists, initialize all modules
    init_jit_functions();
}

extern "C" LANGUAGE_DLLEXPORT_CODEGEN void language_teardown_codegen_impl() LANGUAGE_NOTSAFEPOINT
{
    // output LLVM timings and statistics
    // Guard against exits before we have initialized the ExecutionEngine
    if (language_ExecutionEngine)
        language_ExecutionEngine->printTimers();
    PrintStatistics();
    LANGUAGE_LOCK(&language_codegen_lock); // TODO: If this lock gets removed reconsider
                                    // LLVM global state/destructors (maybe a rwlock)
}

// the rest of this file are convenience functions
// that are exported for assisting with debugging from gdb
extern "C" void language_dump_llvm_value(void *v)
{
    llvm_dump((Value*)v);
}

extern "C" void language_dump_llvm_inst_function(void *v)
{
    llvm_dump(cast<Instruction>(((Value*)v))->getParent()->getParent());
}

extern "C" void language_dump_llvm_type(void *v)
{
    llvm_dump((Type*)v);
}

extern "C" void language_dump_llvm_module(void *v)
{
    llvm_dump((Module*)v);
}

extern "C" void language_dump_llvm_metadata(void *v)
{
    llvm_dump((Metadata*)v);
}

extern "C" void language_dump_llvm_debugloc(void *v)
{
    llvm_dump((DebugLoc*)v);
}

namespace llvm {
    class MachineBasicBlock;
    class MachineFunction;
    raw_ostream& operator<<(raw_ostream &OS, const MachineBasicBlock &MBB);
    void printMIR(raw_ostream &OS, const MachineFunction &MF);
}
extern "C" void language_dump_llvm_mbb(void *v)
{
    errs() << *(llvm::MachineBasicBlock*)v;
}
extern "C" void language_dump_llvm_mfunction(void *v)
{
    llvm::printMIR(errs(), *(llvm::MachineFunction*)v);
}


extern void language_write_bitcode_func(void *F, char *fname) {
    std::error_code EC;
    raw_fd_ostream OS(fname, EC, sys::fs::OF_None);
    llvm::WriteBitcodeToFile(*((llvm::Function*)F)->getParent(), OS);
}

extern void language_write_bitcode_module(void *M, char *fname) {
    std::error_code EC;
    raw_fd_ostream OS(fname, EC, sys::fs::OF_None);
    llvm::WriteBitcodeToFile(*(llvm::Module*)M, OS);
}

#ifdef _OS_WINDOWS_
#include <psapi.h>
#else
#include <dlfcn.h>
#endif

#include <llvm-c/Core.h>

extern "C" LANGUAGE_DLLEXPORT_CODEGEN language_value_t *language_get_libllvm_impl(void) LANGUAGE_NOTSAFEPOINT
{
#if defined(_OS_WINDOWS_)
    HMODULE mod;
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)&llvm::DebugFlag, &mod))
        return language_nothing;
    wchar_t path16[MAX_PATH];
    DWORD n16 = GetModuleFileNameW(mod, path16, MAX_PATH);
    if (n16 <= 0)
        return language_nothing;
    path16[n16++] = 0;
    char path8[MAX_PATH * 3];
    if (!WideCharToMultiByte(CP_UTF8, 0, path16, n16, path8, MAX_PATH * 3, NULL, NULL))
        return language_nothing;
    return (language_value_t*) language_symbol(path8);
#else
    Dl_info dli;
    if (!dladdr((void*)LLVMContextCreate, &dli))
        return language_nothing;
    return (language_value_t*) language_symbol(dli.dli_fname);
#endif
}
