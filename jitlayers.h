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

#include <llvm/ADT/MapVector.h>
#include <llvm/ADT/StringSet.h>
#include <llvm/Support/AllocatorBase.h>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/PassTimingInfo.h>

#include <llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include <llvm/ExecutionEngine/Orc/IRTransformLayer.h>
#include <llvm/ExecutionEngine/JITEventListener.h>

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Passes/StandardInstrumentations.h>

#include <llvm/Target/TargetMachine.h>
#include "language_assert.h"
#include "code.h"
#include "language_internal.h"
#include "platform.h"
#include "llvm-codegen-shared.h"
#include <stack>
#include <queue>



// As of LLVM 13, there are two runtime JIT linker implementations, the older
// RuntimeDyld (used via orc::RTDyldObjectLinkingLayer) and the newer JITLink
// (used via orc::ObjectLinkingLayer).
//
// JITLink is not only more flexible (which isn't of great importance for us, as
// we do only single-threaded in-process codegen), but crucially supports using
// the Small code model, where the linker needs to fix up relocations between
// object files that end up far apart in address space. RuntimeDyld can't do
// that and relies on the Large code model instead, which is broken on
// aarch64-darwin (macOS on ARM64), and not likely to ever be supported there
// (see https://bugs.llvm.org/show_bug.cgi?id=52029).
//
// However, JITLink is a relatively young library and lags behind in platform
// and feature support (e.g. Windows, JITEventListeners for various profilers,
// etc.). Thus, we currently only use JITLink where absolutely required, that is,
// for Mac/aarch64 and Linux/aarch64.
// #define LANGUAGE_FORCE_JITLINK

#if defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_MSAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_)
# define HAS_SANITIZER
#endif
// The sanitizers don't play well with our memory manager

#if defined(LANGUAGE_FORCE_JITLINK) || defined(_CPU_AARCH64_) || defined(HAS_SANITIZER)
# define LANGUAGE_USE_JITLINK
#endif

# include <llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h>
# include <llvm/ExecutionEngine/RTDyldMemoryManager.h>
# include <llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>

using namespace llvm;

extern "C" language_cgparams_t language_default_cgparams;

DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::ThreadSafeContext, LLVMOrcThreadSafeContextRef)
DEFINE_SIMPLE_CONVERSION_FUNCTIONS(orc::ThreadSafeModule, LLVMOrcThreadSafeModuleRef)

void addTargetPasses(legacy::PassManagerBase *PM, const Triple &triple, TargetIRAnalysis analysis) LANGUAGE_NOTSAFEPOINT;
void language_merge_module(orc::ThreadSafeModule &dest, orc::ThreadSafeModule src) LANGUAGE_NOTSAFEPOINT;
GlobalVariable *language_emit_RTLD_DEFAULT_var(Module *M) LANGUAGE_NOTSAFEPOINT;
DataLayout language_create_datalayout(TargetMachine &TM) LANGUAGE_NOTSAFEPOINT;

static inline bool imaging_default() LANGUAGE_NOTSAFEPOINT {
    return language_options.image_codegen || (language_generating_output() && (!language_options.incremental || language_options.use_pkgimages));
}

struct OptimizationOptions {
    bool lower_intrinsics;
    bool dump_native;
    bool external_use;
    bool llvm_only;
    bool always_inline;
    bool enable_early_simplifications;
    bool enable_early_optimizations;
    bool enable_scalar_optimizations;
    bool enable_loop_optimizations;
    bool enable_vector_pipeline;
    bool remove_ni;
    bool cleanup;

    static constexpr OptimizationOptions defaults(
        bool lower_intrinsics=true,
        bool dump_native=false,
        bool external_use=false,
        bool llvm_only=false,
        bool always_inline=true,
        bool enable_early_simplifications=true,
        bool enable_early_optimizations=true,
        bool enable_scalar_optimizations=true,
        bool enable_loop_optimizations=true,
        bool enable_vector_pipeline=true,
        bool remove_ni=true,
        bool cleanup=true) {
        return {lower_intrinsics, dump_native, external_use, llvm_only,
                always_inline, enable_early_simplifications,
                enable_early_optimizations, enable_scalar_optimizations,
                enable_loop_optimizations, enable_vector_pipeline,
                remove_ni, cleanup};
    }
};

struct NewPM {
    std::unique_ptr<TargetMachine> TM;
    OptimizationLevel O;
    OptimizationOptions options;
    TimePassesHandler TimePasses;
    NewPM(std::unique_ptr<TargetMachine> TM, OptimizationLevel O, OptimizationOptions options = OptimizationOptions::defaults()) LANGUAGE_NOTSAFEPOINT;
    ~NewPM() LANGUAGE_NOTSAFEPOINT;

    void run(Module &M) LANGUAGE_NOTSAFEPOINT;

    void printTimers() LANGUAGE_NOTSAFEPOINT;
};

struct AnalysisManagers {
    LoopAnalysisManager LAM;
    FunctionAnalysisManager FAM;
    CGSCCAnalysisManager CGAM;
    ModuleAnalysisManager MAM;

    AnalysisManagers(PassBuilder &PB) LANGUAGE_NOTSAFEPOINT;
    AnalysisManagers(TargetMachine &TM, PassBuilder &PB, OptimizationLevel O) LANGUAGE_NOTSAFEPOINT;
    ~AnalysisManagers() LANGUAGE_NOTSAFEPOINT;
};

OptimizationLevel getOptLevel(int optlevel) LANGUAGE_NOTSAFEPOINT;

struct language_locked_stream {
    ios_t *stream = nullptr;
    std::mutex mutex;

    struct lock {
        std::unique_lock<std::mutex> lck;
        ios_t *&stream;

        lock(std::mutex &mutex, ios_t *&stream) LANGUAGE_NOTSAFEPOINT
            : lck(mutex), stream(stream) {}
        lock(lock&) = delete;
        lock(lock&&) LANGUAGE_NOTSAFEPOINT = default;
        ~lock() LANGUAGE_NOTSAFEPOINT = default;

        ios_t *&operator*() LANGUAGE_NOTSAFEPOINT {
            return stream;
        }

        explicit operator bool() LANGUAGE_NOTSAFEPOINT {
            return !!stream;
        }

        operator ios_t *() LANGUAGE_NOTSAFEPOINT {
            return stream;
        }

        operator LANGUAGE_STREAM *() LANGUAGE_NOTSAFEPOINT {
            return (LANGUAGE_STREAM*)stream;
        }
    };

    language_locked_stream() LANGUAGE_NOTSAFEPOINT = default;
    ~language_locked_stream() LANGUAGE_NOTSAFEPOINT = default;

    lock operator*() LANGUAGE_NOTSAFEPOINT {
        return lock(mutex, stream);
    }
};

typedef struct _language_llvm_functions_t {
    std::string functionObject;     // jlcall llvm Function name
    std::string specFunctionObject; // specialized llvm Function name
} language_llvm_functions_t;

struct language_returninfo_t {
    llvm::FunctionCallee decl;
    llvm::AttributeList attrs;
    enum CallingConv {
        Boxed = 0,
        Register,
        SRet,
        Union,
        Ghosts
    } cc;
    size_t union_bytes;
    size_t union_align;
    size_t union_minalign;
    unsigned return_roots;
};

struct language_codegen_call_target_t {
    language_returninfo_t::CallingConv cc;
    unsigned return_roots;
    llvm::Function *decl;
    bool specsig;
};

typedef SmallVector<std::pair<language_code_instance_t*, language_codegen_call_target_t>, 0> language_workqueue_t;
// TODO DenseMap?
typedef std::map<language_code_instance_t*, std::pair<orc::ThreadSafeModule, language_llvm_functions_t>> language_compiled_functions_t;

struct language_codegen_params_t {
    orc::ThreadSafeContext tsctx;
    orc::ThreadSafeContext::Lock tsctx_lock;
    DataLayout DL;
    Triple TargetTriple;

    inline LLVMContext &getContext() {
        return *tsctx.getContext();
    }
    typedef StringMap<GlobalVariable*> SymMapGV;
    // outputs
    language_workqueue_t workqueue;
    language_compiled_functions_t compiled_functions;
    std::map<void*, GlobalVariable*> global_targets;
    std::map<std::tuple<language_code_instance_t*,bool>, GlobalVariable*> external_fns;
    std::map<language_datatype_t*, DIType*> ditypes;
    std::map<language_datatype_t*, Type*> llvmtypes;
    DenseMap<Constant*, GlobalVariable*> mergedConstants;
    // Map from symbol name (in a certain library) to its GV in sysimg and the
    // DL handle address in the current session.
    StringMap<std::pair<GlobalVariable*,SymMapGV>> libMapGV;
    SymMapGV symMapDefault;
    // These symMaps are Windows-only
    SymMapGV symMapExe;
    SymMapGV symMapDll;
    SymMapGV symMapDlli;
    // Map from distinct callee's to its GOT entry.
    // In principle the attribute, function type and calling convention
    // don't need to be part of the key but it seems impossible to forward
    // all the arguments without writing assembly directly.
    // This doesn't matter too much in reality since a single function is usually
    // not called with multiple signatures.
    DenseMap<AttributeList, std::map<
        std::tuple<GlobalVariable*, FunctionType*, CallingConv::ID>,
        GlobalVariable*>> allPltMap;
    std::unique_ptr<Module> _shared_module;
    inline Module &shared_module();
    // inputs
    const language_cgparams_t *params = &language_default_cgparams;
    bool cache = false;
    bool external_linkage = false;
    bool imaging_mode;
    int debug_level;
    language_codegen_params_t(orc::ThreadSafeContext ctx, DataLayout DL, Triple triple)
        : tsctx(std::move(ctx)), tsctx_lock(tsctx.getLock()),
            DL(std::move(DL)), TargetTriple(std::move(triple)), imaging_mode(imaging_default()) {}
};

language_llvm_functions_t language_emit_code(
        orc::ThreadSafeModule &M,
        language_method_instance_t *mi,
        language_code_info_t *src,
        language_value_t *jlrettype,
        language_codegen_params_t &params,
        size_t min_world, size_t max_world);

language_llvm_functions_t language_emit_codeinst(
        orc::ThreadSafeModule &M,
        language_code_instance_t *codeinst,
        language_code_info_t *src,
        language_codegen_params_t &params);

enum CompilationPolicy {
    Default = 0,
    Extern = 1,
};

void language_compile_workqueue(
    language_codegen_params_t &params,
    CompilationPolicy policy);

Function *language_cfunction_object(language_function_t *f, language_value_t *rt, language_tupletype_t *argt,
    language_codegen_params_t &params);

void add_named_global(StringRef name, void *addr) LANGUAGE_NOTSAFEPOINT;

static inline Constant *literal_static_pointer_val(const void *p, Type *T) LANGUAGE_NOTSAFEPOINT
{
    // this function will emit a static pointer into the generated code
    // the generated code will only be valid during the current session,
    // and thus, this should typically be avoided in new API's
#if defined(_P64)
    return ConstantExpr::getIntToPtr(ConstantInt::get(Type::getInt64Ty(T->getContext()), (uint64_t)p), T);
#else
    return ConstantExpr::getIntToPtr(ConstantInt::get(Type::getInt32Ty(T->getContext()), (uint32_t)p), T);
#endif
}

static const inline char *name_from_method_instance(language_method_instance_t *li) LANGUAGE_NOTSAFEPOINT
{
    return language_is_method(li->def.method) ? language_symbol_name(li->def.method->name) : "top-level scope";
}

template <size_t offset = 0>
class MaxAlignedAllocImpl
    : public AllocatorBase<MaxAlignedAllocImpl<offset>> {

public:
    MaxAlignedAllocImpl() LANGUAGE_NOTSAFEPOINT = default;

    static Align alignment(size_t Size) LANGUAGE_NOTSAFEPOINT {
        // Define the maximum alignment we expect to require, from offset bytes off
        // the returned pointer, this is >= alignof(std::max_align_t), which is too
        // small often to actually use.
        const size_t MaxAlignment = LANGUAGE_CACHE_BYTE_ALIGNMENT;
        if (Size <= offset)
            return Align(1);
        return Align(std::min((size_t)llvm::PowerOf2Ceil(Size - offset), MaxAlignment));
    }

    LLVM_ATTRIBUTE_RETURNS_NONNULL void *Allocate(size_t Size, Align Alignment) {
        Align MaxAlign = alignment(Size);
        assert(Alignment < MaxAlign); (void)Alignment;
        return language_gc_perm_alloc(Size, 0, MaxAlign.value(), offset);
    }

    inline LLVM_ATTRIBUTE_RETURNS_NONNULL
    void * Allocate(size_t Size, size_t Alignment) {
        return Allocate(Size, Align(Alignment));
    }

    // Pull in base class overloads.
    using AllocatorBase<MaxAlignedAllocImpl>::Allocate;

    void Deallocate(const void *Ptr, size_t Size, size_t /*Alignment*/) { abort(); }

    // Pull in base class overloads.
    using AllocatorBase<MaxAlignedAllocImpl>::Deallocate;

private:
};
using MaxAlignedAlloc = MaxAlignedAllocImpl<>;

#if LANGUAGE_LLVM_VERSION < 170000
typedef JITSymbol LANGUAGE_JITSymbol;
// The type that is similar to SymbolInfo on LLVM 4.0 is actually
// `JITEvaluatedSymbol`. However, we only use this type when a JITSymbol
// is expected.
typedef JITSymbol LANGUAGE_SymbolInfo;
#endif

using CompilerResultT = Expected<std::unique_ptr<llvm::MemoryBuffer>>;
using OptimizerResultT = Expected<orc::ThreadSafeModule>;
using SharedBytesT = StringSet<MaxAlignedAllocImpl<sizeof(StringSet<>::MapEntryTy)>>;

class JuliaOJIT {
public:
#ifdef LANGUAGE_USE_JITLINK
    typedef orc::ObjectLinkingLayer ObjLayerT;
#else
    typedef orc::RTDyldObjectLinkingLayer ObjLayerT;
#endif
    struct LockLayerT : public orc::ObjectLayer {

        LockLayerT(orc::ObjectLayer &BaseLayer) LANGUAGE_NOTSAFEPOINT : orc::ObjectLayer(BaseLayer.getExecutionSession()), BaseLayer(BaseLayer) {}
        ~LockLayerT() LANGUAGE_NOTSAFEPOINT = default;

        void emit(std::unique_ptr<orc::MaterializationResponsibility> R,
                            std::unique_ptr<MemoryBuffer> O) override {
            LANGUAGE_TIMING(LLVM_JIT, JIT_Link);
#ifndef LANGUAGE_USE_JITLINK
            std::lock_guard<std::mutex> lock(EmissionMutex);
#endif
            BaseLayer.emit(std::move(R), std::move(O));
        }
    private:
        orc::ObjectLayer &BaseLayer;
        std::mutex EmissionMutex;
    };
    typedef orc::IRCompileLayer CompileLayerT;
    typedef orc::IRTransformLayer JITPointersLayerT;
    typedef orc::IRTransformLayer OptimizeLayerT;
    typedef orc::IRTransformLayer OptSelLayerT;
    typedef orc::IRTransformLayer DepsVerifyLayerT;
    typedef object::OwningBinary<object::ObjectFile> OwningObj;
    template
    <typename ResourceT, size_t max = 0,
        typename BackingT = std::stack<ResourceT,
            std::conditional_t<max == 0,
                SmallVector<ResourceT, 0>,
                SmallVector<ResourceT, max>
            >
        >
    >
    struct ResourcePool {
        public:
        ResourcePool(std::function<ResourceT()> creator) LANGUAGE_NOTSAFEPOINT : creator(std::move(creator)), mutex(std::make_unique<WNMutex>()) {}
        ResourcePool(ResourcePool&) = delete;
        ResourcePool(ResourcePool&&) LANGUAGE_NOTSAFEPOINT = default;
        ~ResourcePool() LANGUAGE_NOTSAFEPOINT = default;
        class OwningResource {
            public:
            OwningResource(ResourcePool &pool, ResourceT resource) LANGUAGE_NOTSAFEPOINT // _ENTER
                : pool(pool), resource(std::move(resource)) {}
            OwningResource(const OwningResource &) = delete;
            OwningResource &operator=(const OwningResource &) = delete;
            OwningResource(OwningResource &&) LANGUAGE_NOTSAFEPOINT = default;
            OwningResource &operator=(OwningResource &&) LANGUAGE_NOTSAFEPOINT = default;
            ~OwningResource() LANGUAGE_NOTSAFEPOINT { // _LEAVE
                if (resource)
                    pool.release(std::move(*resource));
            }
            ResourceT release() LANGUAGE_NOTSAFEPOINT {
                ResourceT res(std::move(*resource));
                resource.reset();
                return res;
            }
            void reset(ResourceT res) LANGUAGE_NOTSAFEPOINT {
                *resource = std::move(res);
            }
            ResourceT &operator*() LANGUAGE_NOTSAFEPOINT {
                return *resource;
            }
            ResourceT *operator->() LANGUAGE_NOTSAFEPOINT {
                return get();
            }
            ResourceT *get() LANGUAGE_NOTSAFEPOINT {
                return resource.getPointer();
            }
            const ResourceT &operator*() const LANGUAGE_NOTSAFEPOINT {
                return *resource;
            }
            const ResourceT *operator->() const LANGUAGE_NOTSAFEPOINT {
                return get();
            }
            const ResourceT *get() const LANGUAGE_NOTSAFEPOINT {
                return resource.getPointer();
            }
            explicit operator bool() const LANGUAGE_NOTSAFEPOINT {
                return resource;
            }
            private:
            ResourcePool &pool;
            Optional<ResourceT> resource;
        };

        OwningResource operator*() LANGUAGE_NOTSAFEPOINT {
            return OwningResource(*this, acquire());
        }

        OwningResource get() {
            return **this;
        }

        ResourceT acquire() LANGUAGE_NOTSAFEPOINT { // _ENTER
            std::unique_lock<std::mutex> lock(mutex->mutex);
            if (!pool.empty()) {
                return pop(pool);
            }
            if (!max || created < max) {
                created++;
                return creator();
            }
            mutex->empty.wait(lock, [&](){ return !pool.empty(); });
            assert(!pool.empty() && "Expected resource pool to have a value!");
            return pop(pool);
        }
        void release(ResourceT &&resource) LANGUAGE_NOTSAFEPOINT { // _LEAVE
            std::lock_guard<std::mutex> lock(mutex->mutex);
            pool.push(std::move(resource));
            mutex->empty.notify_one();
        }
        private:
        template<typename T, typename Container>
        static ResourceT pop(std::queue<T, Container> &pool) LANGUAGE_NOTSAFEPOINT {
            ResourceT top = std::move(pool.front());
            pool.pop();
            return top;
        }
        template<typename PoolT>
        static ResourceT pop(PoolT &pool) LANGUAGE_NOTSAFEPOINT {
            ResourceT top = std::move(pool.top());
            pool.pop();
            return top;
        }
        std::function<ResourceT()> creator;
        size_t created = 0;
        BackingT pool;
        struct WNMutex {
            std::mutex mutex;
            std::condition_variable empty;
        };

        std::unique_ptr<WNMutex> mutex;
    };

    struct DLSymOptimizer;

private:
    // Custom object emission notification handler for the JuliaOJIT
    template <typename ObjT, typename LoadResult>
    void registerObject(const ObjT &Obj, const LoadResult &LO);

public:

    JuliaOJIT() LANGUAGE_NOTSAFEPOINT;
    ~JuliaOJIT() LANGUAGE_NOTSAFEPOINT;

    void enableJITDebuggingSupport() LANGUAGE_NOTSAFEPOINT;
#ifndef LANGUAGE_USE_JITLINK
    // JITLink doesn't support old JITEventListeners (yet).
    void RegisterJITEventListener(JITEventListener *L) LANGUAGE_NOTSAFEPOINT;
#endif

    orc::SymbolStringPtr mangle(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    void addGlobalMapping(StringRef Name, uint64_t Addr) LANGUAGE_NOTSAFEPOINT;
    void addModule(orc::ThreadSafeModule M) LANGUAGE_NOTSAFEPOINT;

    //Methods for the C API
    Error addExternalModule(orc::JITDylib &JD, orc::ThreadSafeModule TSM,
                            bool ShouldOptimize = false) LANGUAGE_NOTSAFEPOINT;
    Error addObjectFile(orc::JITDylib &JD,
                        std::unique_ptr<MemoryBuffer> Obj) LANGUAGE_NOTSAFEPOINT;
    orc::IRCompileLayer &getIRCompileLayer() LANGUAGE_NOTSAFEPOINT { return ExternalCompileLayer; };
    orc::ExecutionSession &getExecutionSession() LANGUAGE_NOTSAFEPOINT { return ES; }
    orc::JITDylib &getExternalJITDylib() LANGUAGE_NOTSAFEPOINT { return ExternalJD; }

    #if LANGUAGE_LLVM_VERSION >= 170000
    Expected<llvm::orc::ExecutorSymbolDef> findSymbol(StringRef Name, bool ExportedSymbolsOnly) LANGUAGE_NOTSAFEPOINT;
    Expected<llvm::orc::ExecutorSymbolDef> findUnmangledSymbol(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    Expected<llvm::orc::ExecutorSymbolDef> findExternalJDSymbol(StringRef Name, bool ExternalJDOnly) LANGUAGE_NOTSAFEPOINT;
    #else
    JITEvaluatedSymbol findSymbol(StringRef Name, bool ExportedSymbolsOnly) LANGUAGE_NOTSAFEPOINT;
    JITEvaluatedSymbol findUnmangledSymbol(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    Expected<JITEvaluatedSymbol> findExternalJDSymbol(StringRef Name, bool ExternalJDOnly) LANGUAGE_NOTSAFEPOINT;
    #endif
    uint64_t getGlobalValueAddress(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    uint64_t getFunctionAddress(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    StringRef getFunctionAtAddress(uint64_t Addr, language_code_instance_t *codeinst) LANGUAGE_NOTSAFEPOINT;
    auto getContext() LANGUAGE_NOTSAFEPOINT {
        return *ContextPool;
    }
    orc::ThreadSafeContext acquireContext() { // LANGUAGE_NOTSAFEPOINT_ENTER?
        return ContextPool.acquire();
    }
    void releaseContext(orc::ThreadSafeContext &&ctx) { // LANGUAGE_NOTSAFEPOINT_LEAVE?
        ContextPool.release(std::move(ctx));
    }
    const DataLayout& getDataLayout() const LANGUAGE_NOTSAFEPOINT;

    // TargetMachine pass-through methods
    std::unique_ptr<TargetMachine> cloneTargetMachine() const LANGUAGE_NOTSAFEPOINT;
    const Triple& getTargetTriple() const LANGUAGE_NOTSAFEPOINT;
    StringRef getTargetFeatureString() const LANGUAGE_NOTSAFEPOINT;
    StringRef getTargetCPU() const LANGUAGE_NOTSAFEPOINT;
    const TargetOptions &getTargetOptions() const LANGUAGE_NOTSAFEPOINT;
    const Target &getTarget() const LANGUAGE_NOTSAFEPOINT;
    TargetIRAnalysis getTargetIRAnalysis() const LANGUAGE_NOTSAFEPOINT;

    size_t getTotalBytes() const LANGUAGE_NOTSAFEPOINT;
    void printTimers() LANGUAGE_NOTSAFEPOINT;

    language_locked_stream &get_dump_emitted_mi_name_stream() LANGUAGE_NOTSAFEPOINT {
        return dump_emitted_mi_name_stream;
    }
    language_locked_stream &get_dump_compiles_stream() LANGUAGE_NOTSAFEPOINT {
        return dump_compiles_stream;
    }
    language_locked_stream &get_dump_llvm_opt_stream() LANGUAGE_NOTSAFEPOINT {
        return dump_llvm_opt_stream;
    }
    std::string getMangledName(StringRef Name) LANGUAGE_NOTSAFEPOINT;
    std::string getMangledName(const GlobalValue *GV) LANGUAGE_NOTSAFEPOINT;

    // Note that this is a safepoint due to language_get_library_ and language_dlsym calls
    void optimizeDLSyms(Module &M);

private:

    const std::unique_ptr<TargetMachine> TM;
    const DataLayout DL;

    orc::ExecutionSession ES;
    orc::JITDylib &GlobalJD;
    orc::JITDylib &JD;
    orc::JITDylib &ExternalJD;
    //Map and inc are guarded by RLST_mutex
    std::mutex RLST_mutex{};
    int RLST_inc = 0;
    DenseMap<void*, std::string> ReverseLocalSymbolTable;
    SharedBytesT SharedBytes;

    std::unique_ptr<DLSymOptimizer> DLSymOpt;

    //Compilation streams
    language_locked_stream dump_emitted_mi_name_stream;
    language_locked_stream dump_compiles_stream;
    language_locked_stream dump_llvm_opt_stream;

    std::mutex llvm_printing_mutex{};
    SmallVector<std::function<void()>, 0> PrintLLVMTimers;

    ResourcePool<orc::ThreadSafeContext, 0, std::queue<orc::ThreadSafeContext>> ContextPool;

#ifndef LANGUAGE_USE_JITLINK
    const std::shared_ptr<RTDyldMemoryManager> MemMgr;
#else
    std::atomic<size_t> total_size{0};
    const std::unique_ptr<jitlink::JITLinkMemoryManager> MemMgr;
#endif
    ObjLayerT ObjectLayer;
    LockLayerT LockLayer;
    CompileLayerT CompileLayer;
    JITPointersLayerT JITPointersLayer;
    OptimizeLayerT OptimizeLayer;
    OptSelLayerT OptSelLayer;
    DepsVerifyLayerT DepsVerifyLayer;
    CompileLayerT ExternalCompileLayer;
};
extern JuliaOJIT *language_ExecutionEngine;
std::unique_ptr<Module> language_create_llvm_module(StringRef name, LLVMContext &ctx, const DataLayout &DL = language_ExecutionEngine->getDataLayout(), const Triple &triple = language_ExecutionEngine->getTargetTriple()) LANGUAGE_NOTSAFEPOINT;
inline orc::ThreadSafeModule language_create_ts_module(StringRef name, orc::ThreadSafeContext ctx, const DataLayout &DL = language_ExecutionEngine->getDataLayout(), const Triple &triple = language_ExecutionEngine->getTargetTriple()) LANGUAGE_NOTSAFEPOINT {
    auto lock = ctx.getLock();
    return orc::ThreadSafeModule(language_create_llvm_module(name, *ctx.getContext(), DL, triple), ctx);
}

Module &language_codegen_params_t::shared_module() LANGUAGE_NOTSAFEPOINT {
    if (!_shared_module) {
        _shared_module = language_create_llvm_module("globals", getContext(), DL, TargetTriple);
    }
    return *_shared_module;
}
void fixupTM(TargetMachine &TM) LANGUAGE_NOTSAFEPOINT;

#if LANGUAGE_LLVM_VERSION < 170000
void SetOpaquePointer(LLVMContext &ctx) LANGUAGE_NOTSAFEPOINT;
#endif

void optimizeDLSyms(Module &M);

// NewPM
#include "passes.h"

CodeGenOpt::Level CodeGenOptLevelFor(int optlevel) LANGUAGE_NOTSAFEPOINT;
