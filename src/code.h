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

#ifndef CODE_H
#define CODE_H

#if defined(LANGUAGE_LIBRARY_EXPORTS_INTERNAL) || defined(LANGUAGE_LIBRARY_EXPORTS_CODEGEN)
#define CODE_LIBRARY_EXPORTS
#endif
#ifdef LANGUAGE_LIBRARY_EXPORTS
// Generated file, needs to be searched in include paths so that the builddir
// retains priority
#include <language_internal_funcs.inc>
#undef language_setjmp
#undef language_longjmp
#undef language_egal
#undef language_genericmemory_owner
#endif

#include "language_fasttls.h"
#include "libsupport.h"
#include <stdint.h>
#include <string.h>

#include "htable.h"
#include "arraylist.h"
#include "analyzer_annotations.h"

#include <setjmp.h>
#ifndef _OS_WINDOWS_
#  define language_jmp_buf sigjmp_buf
#  if defined(_CPU_ARM_) || defined(_CPU_PPC_) || defined(_CPU_WASM_)
#    define MAX_ALIGN 8
#  elif defined(_CPU_AARCH64_)
// int128 is 16 bytes aligned on aarch64
#    define MAX_ALIGN 16
#  elif defined(_P64)
// Generically we assume MAX_ALIGN is sizeof(void*)
#    define MAX_ALIGN 8
#  else
#    define MAX_ALIGN 4
#  endif
#else
#  include "win32_ucontext.h"
#  define language_jmp_buf jmp_buf
#  define MAX_ALIGN 8
#endif

// Define the largest size (bytes) of a properly aligned object that the
// processor family (MAX_ATOMIC_SIZE) and compiler (MAX_POINTERATOMIC_SIZE)
// typically supports without a lock (assumed to be at least a pointer size)
// with MAX_POINTERATOMIC_SIZE >= MAX_ATOMIC_SIZE.
#ifdef _P64
#define MAX_ATOMIC_SIZE 16
#define MAX_POINTERATOMIC_SIZE 16
#else
#define MAX_ATOMIC_SIZE 8
#define MAX_POINTERATOMIC_SIZE 8
#endif

#ifdef _P64
#define NWORDS(sz) (((sz)+7)>>3)
#else
#define NWORDS(sz) (((sz)+3)>>2)
#endif

#if defined(__GNUC__)
#  define LANGUAGE_NORETURN __attribute__ ((noreturn))
#  define LANGUAGE_CONST_FUNC __attribute__((const))
#  define LANGUAGE_USED_FUNC __attribute__((used))
#else
#  define LANGUAGE_NORETURN
#  define LANGUAGE_CONST_FUNC
#  define LANGUAGE_USED_FUNC
#endif

#define container_of(ptr, type, member) \
    ((type *) ((char *)(ptr) - offsetof(type, member)))

typedef struct _language_taggedvalue_t language_taggedvalue_t;
typedef struct _language_tls_states_t *language_ptls_t;

#ifdef LANGUAGE_LIBRARY_EXPORTS
#include "uv.h"
#endif
#include "language_atomics.h"
#include "language_threads.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// core data types ------------------------------------------------------------

// the common fields are hidden before the pointer, but the following macro is
// used to indicate which types below are subtypes of language_value_t
#define LANGUAGE_DATA_TYPE

typedef struct _language_value_t language_value_t;

struct _language_taggedvalue_bits {
    uintptr_t gc:2;
    uintptr_t in_image:1;
    uintptr_t unused:1;
#ifdef _P64
    uintptr_t tag:60;
#else
    uintptr_t tag:28;
#endif
};

LANGUAGE_EXTENSION struct _language_taggedvalue_t {
    union {
        uintptr_t header;
        language_taggedvalue_t *next;
        language_value_t *type; // 16-byte aligned
        struct _language_taggedvalue_bits bits;
    };
    // language_value_t value;
};

static inline language_value_t *language_to_typeof(uintptr_t t) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;
#ifdef __clang_gcanalyzer__
LANGUAGE_DLLEXPORT language_taggedvalue_t *_language_astaggedvalue(language_value_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
#define language_astaggedvalue(v) _language_astaggedvalue((language_value_t*)(v))
language_value_t *_language_valueof(language_taggedvalue_t *tv LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
#define language_valueof(v) _language_valueof((language_taggedvalue_t*)(v))
LANGUAGE_DLLEXPORT language_value_t *_language_typeof(language_value_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
#define language_typeof(v) (_language_typeof((language_value_t*)(v)))
#define language_typetagof(v) ((uintptr_t)_language_typeof((language_value_t*)(v)))
#else
#define language_astaggedvalue(v)                                             \
    ((language_taggedvalue_t*)((char*)(v) - sizeof(language_taggedvalue_t)))
#define language_valueof(v)                                                   \
    ((language_value_t*)((char*)(v) + sizeof(language_taggedvalue_t)))
#define language_typeof(v)                                                    \
    language_to_typeof(language_typetagof(v))
#define language_typetagof(v)                                                 \
    ((language_astaggedvalue(v)->header) & ~(uintptr_t)15)
#endif
static inline void language_set_typeof(void *v, void *t) LANGUAGE_NOTSAFEPOINT
{
    // Do not call this on a value that is already initialized.
    language_taggedvalue_t *tag = language_astaggedvalue(v);
    language_atomic_store_relaxed((_Atomic(language_value_t*)*)&tag->type, (language_value_t*)t);
}
#define language_typeis(v,t) (language_typeof(v)==(language_value_t*)(t))
#define language_typetagis(v,t) (language_typetagof(v)==(uintptr_t)(t))
#define language_set_typetagof(v,t,gc) (language_set_typeof((v), (void*)(((uintptr_t)(t) << 4) | (gc))))

// Symbols are interned strings (hash-consed) stored as an invasive binary tree.
// The string data is nul-terminated and hangs off the end of the struct.
typedef struct _language_sym_t {
    LANGUAGE_DATA_TYPE
    _Atomic(struct _language_sym_t*) left;
    _Atomic(struct _language_sym_t*) right;
    uintptr_t hash;    // precomputed hash value
    // LANGUAGE_ATTRIBUTE_ALIGN_PTRSIZE(char name[]);
} language_sym_t;

// A numbered SSA value, for optimized code analysis and generation
// the `id` is a unique, small number
typedef struct _language_ssavalue_t {
    LANGUAGE_DATA_TYPE
    ssize_t id;
} language_ssavalue_t;

// A SimpleVector is an immutable pointer array
// Data is stored at the end of this variable-length struct.
typedef struct {
    LANGUAGE_DATA_TYPE
    size_t length;
    // pointer size aligned
    // language_value_t *data[];
} language_svec_t;

LANGUAGE_EXTENSION typedef struct {
    LANGUAGE_DATA_TYPE
    size_t length;
    void *ptr;
    // followed by padding and inline data, or owner pointer
#ifdef _P64
    // union {
    //     language_value_t *owner;
    //     T inl[];
    // };
#else
    //
    // language_value_t *owner;
    // size_t padding[1];
    // T inl[];
#endif
} language_genericmemory_t;

LANGUAGE_EXTENSION typedef struct {
    LANGUAGE_DATA_TYPE
    void *ptr_or_offset;
    language_genericmemory_t *mem;
} language_genericmemoryref_t;

LANGUAGE_EXTENSION typedef struct {
    LANGUAGE_DATA_TYPE
    language_genericmemoryref_t ref;
    size_t dimsize[]; // length for 1-D, otherwise length is mem->length
} language_array_t;


typedef struct _language_datatype_t language_tupletype_t;
struct _language_code_instance_t;
typedef struct _language_method_instance_t language_method_instance_t;
typedef struct _language_globalref_t language_globalref_t;


// TypeMap is an implicitly defined type
// that can consist of any of the following nodes:
//   typedef TypeMap Union{TypeMapLevel, TypeMapEntry, Nothing}
// it forms a roughly tree-shaped structure, consisting of nodes of TypeMapLevels
// which split the tree when possible, for example based on the key into the tuple type at `offs`
// when key is a leaftype, (but only when the tree has enough entries for this to be
// more efficient than storing them sorted linearly)
// otherwise the leaf entries are stored sorted, linearly
typedef language_value_t language_typemap_t;

typedef language_value_t *(language_call_t)(language_value_t*, language_value_t**, uint32_t, struct _language_code_instance_t*);
typedef language_call_t *language_callptr_t;

// "speccall" calling convention signatures.
// This describes some of the special ABI used by compiled julia functions.
extern language_call_t language_fptr_args;
LANGUAGE_DLLEXPORT extern const language_callptr_t language_fptr_args_addr;
typedef language_value_t *(*language_fptr_args_t)(language_value_t*, language_value_t**, uint32_t);

extern language_call_t language_fptr_const_return;
LANGUAGE_DLLEXPORT extern const language_callptr_t language_fptr_const_return_addr;

extern language_call_t language_fptr_sparam;
LANGUAGE_DLLEXPORT extern const language_callptr_t language_fptr_sparam_addr;
typedef language_value_t *(*language_fptr_sparam_t)(language_value_t*, language_value_t**, uint32_t, language_svec_t*);

extern language_call_t language_fptr_interpret_call;
LANGUAGE_DLLEXPORT extern const language_callptr_t language_fptr_interpret_call_addr;

LANGUAGE_DLLEXPORT extern const language_callptr_t language_f_opaque_closure_call_addr;

typedef struct _language_line_info_node_t {
    struct _language_module_t *module;
    language_value_t *method; // may contain a language_symbol, language_method_t, or language_method_instance_t
    language_sym_t *file;
    int32_t line;
    int32_t inlined_at;
} language_line_info_node_t;

struct language_codeloc_t {
    int32_t line;
    int32_t to;
    int32_t pc;
};

typedef struct _language_debuginfo_t {
    language_value_t *def;
    struct _language_debuginfo_t *linetable; // or nothing
    language_svec_t *edges; // Memory{DebugInfo}
    language_value_t *codelocs; // String // Memory{UInt8} // compressed info
} language_debuginfo_t;

// the following mirrors `struct EffectsOverride` in `base/compiler/effects.jl`
typedef union __language_purity_overrides_t {
    struct {
        uint16_t ipo_consistent          : 1;
        uint16_t ipo_effect_free         : 1;
        uint16_t ipo_nothrow             : 1;
        uint16_t ipo_terminates_globally : 1;
        // Weaker form of `terminates` that asserts
        // that any control flow syntactically in the method
        // is guaranteed to terminate, but does not make
        // assertions about any called functions.
        uint16_t ipo_terminates_locally  : 1;
        uint16_t ipo_notaskstate         : 1;
        uint16_t ipo_inaccessiblememonly : 1;
        uint16_t ipo_noub                : 1;
        uint16_t ipo_noub_if_noinbounds  : 1;
    } overrides;
    uint16_t bits;
} _language_purity_overrides_t;

#define NUM_EFFECTS_OVERRIDES 9
#define NUM_IR_FLAGS 13

// This type describes a single function body
typedef struct _language_code_info_t {
    // ssavalue-indexed arrays of properties:
    language_array_t *code;  // Any array of statements
    language_debuginfo_t *debuginfo; // Table of edge data for each statement
    language_value_t *ssavaluetypes; // types of ssa values (or count of them)
    language_array_t *ssaflags; // 32 bits flags associated with each statement:
        // 1 << 0 = inbounds region
        // 1 << 1 = callsite inline region
        // 1 << 2 = callsite noinline region
        // 1 << 3 = throw block
        // 1 << 4 = refined statement
        // 1 << 5 = :consistent
        // 1 << 6 = :effect_free
        // 1 << 7 = :nothrow
        // 1 << 8 = :terminates
        // 1 << 9 = :noub
        // 1 << 10 = :effect_free_if_inaccessiblememonly
        // 1 << 11 = :inaccessiblemem_or_argmemonly
        // 1 << 12-19 = callsite effects overrides
    // miscellaneous data:
    language_array_t *slotnames; // names of local variables
    language_array_t *slotflags;  // local var bit flags
    // the following are optional transient properties (not preserved by compression--as they typically get stored elsewhere):
    language_value_t *slottypes; // inferred types of slots
    language_method_instance_t *parent; // context (after inference, otherwise nothing)

    // These may be used by generated functions to further constrain the resulting inputs.
    // They are not used by any other part of the system and may be moved elsewhere in the
    // future.
    language_value_t *method_for_inference_limit_heuristics; // optional method used during inference
    language_value_t *edges; // forward edges to method instances that must be invalidated (for copying to debuginfo)
    size_t min_world;
    size_t max_world;
    size_t nargs;

    // various boolean properties:
    uint8_t propagate_inbounds;
    uint8_t has_fcall;
    uint8_t nospecializeinfer;
    uint8_t isva;
    // uint8 settings
    uint8_t inlining; // 0 = default; 1 = @inline; 2 = @noinline
    uint8_t constprop; // 0 = use heuristic; 1 = aggressive; 2 = none
    _language_purity_overrides_t purity;
    // uint16 settings
    uint16_t inlining_cost;
} language_code_info_t;

// This type describes a single method definition, and stores data
// shared by the specializations of a function.
typedef struct _language_method_t {
    LANGUAGE_DATA_TYPE
    language_sym_t *name;  // for error reporting
    struct _language_module_t *module;
    language_sym_t *file;
    int32_t line;
    _Atomic(size_t) primary_world;
    _Atomic(size_t) deleted_world;

    // method's type signature. redundant with TypeMapEntry->specTypes
    language_value_t *sig;

    // table of all language_method_instance_t specializations we have
    _Atomic(language_value_t*) specializations; // allocated as [hashable, ..., NULL, linear, ....], or a single item
    _Atomic(language_genericmemory_t*) speckeyset; // index lookup by hash into specializations

    language_value_t *slot_syms; // compacted list of slot names (String)
    language_value_t *external_mt; // reference to the method table this method is part of, null if part of the internal table
    language_value_t *source;  // original code template (language_code_info_t, but may be compressed), null for builtins
    language_debuginfo_t *debuginfo;  // fixed linetable from the source argument, null if not available
    _Atomic(language_method_instance_t*) unspecialized;  // unspecialized executable method instance, or null
    language_value_t *generator;  // executable code-generating function if available
    language_array_t *roots;  // pointers in generated code (shared to reduce memory), or null
    // Identify roots by module-of-origin. We only track the module for roots added during incremental compilation.
    // May be NULL if no external roots have been added, otherwise it's a Vector{UInt64}
    language_array_t *root_blocks;   // RLE (build_id.lo, offset) pairs (even/odd indexing)
    int32_t nroots_sysimg;     // # of roots stored in the system image
    language_svec_t *ccallable; // svec(rettype, sig) if a ccallable entry point is requested for this

    // cache of specializations of this method for invoke(), i.e.
    // cases where this method was called even though it was not necessarily
    // the most specific for the argument types.
    _Atomic(language_typemap_t*) invokes;

    // A function that compares two specializations of this method, returning
    // `true` if the first signature is to be considered "smaller" than the
    // second for purposes of recursion analysis. Set to NULL to use
    // the default recursion relation.
    language_value_t *recursion_relation;

    uint32_t nargs;
    uint32_t called;        // bit flags: whether each of the first 8 arguments is called
    uint32_t nospecialize;  // bit flags: which arguments should not be specialized
    uint32_t nkw;           // # of leading arguments that are actually keyword arguments
                            // of another method.
    // various boolean properties
    uint8_t isva;
    uint8_t is_for_opaque_closure;
    uint8_t nospecializeinfer;
    // uint8 settings
    uint8_t constprop;      // 0x00 = use heuristic; 0x01 = aggressive; 0x02 = none
    uint8_t max_varargs;    // 0xFF = use heuristic; otherwise, max # of args to expand
                            // varargs when specializing.

    // Override the conclusions of inter-procedural effect analysis,
    // forcing the conclusion to always true.
    _language_purity_overrides_t purity;

// hidden fields:
    // lock for modifications to the method
    language_mutex_t writelock;
} language_method_t;

// This type is a placeholder to cache data for a specType signature specialization of a Method
// can can be used as a unique dictionary key representation of a call to a particular Method
// with a particular set of argument types
struct _language_method_instance_t {
    LANGUAGE_DATA_TYPE
    union {
        language_value_t *value; // generic accessor
        struct _language_module_t *module; // this is a toplevel thunk
        language_method_t *method; // method this is specialized from
    } def; // pointer back to the context for this code
    language_value_t *specTypes;  // argument types this was specialized for
    language_svec_t *sparam_vals; // static parameter values, indexed by def.method->sig
    language_array_t *backedges; // list of method-instances which call this method-instance; `invoke` records (invokesig, caller) pairs
    _Atomic(struct _language_code_instance_t*) cache;
    uint8_t inInference; // flags to tell if inference is running on this object
    uint8_t cache_with_orig; // !cache_with_specTypes
    _Atomic(uint8_t) precompiled; // true if this instance was generated by an explicit `precompile(...)` call
};

// OpaqueClosure
typedef struct _language_opaque_closure_t {
    LANGUAGE_DATA_TYPE
    language_value_t *captures;
    size_t world;
    language_method_t *source;
    language_fptr_args_t invoke;
    void *specptr;
} language_opaque_closure_t;

// This type represents an executable operation
typedef struct _language_code_instance_t {
    LANGUAGE_DATA_TYPE
    language_method_instance_t *def; // method this is specialized from
    language_value_t *owner; // Compiler token this belongs to, `language_nothing` is reserved for native
    _Atomic(struct _language_code_instance_t*) next; // pointer to the next cache entry

    // world range for which this object is valid to use
    _Atomic(size_t) min_world;
    _Atomic(size_t) max_world;

    // inference state cache
    language_value_t *rettype; // return type for fptr
    language_value_t *exctype; // thrown type for fptr
    language_value_t *rettype_const; // inferred constant return value, or null

    // Inferred result. When part of the runtime cache, either
    // - A language_code_info_t (may be compressed) containing the inferred IR
    // - language_nothing, indicating that inference was completed, but the result was
    //               deleted to save space.
    // - null, indicating that inference was not yet completed or did not succeed
    _Atomic(language_value_t *) inferred;
    _Atomic(language_debuginfo_t *) debuginfo; // stored information about edges from this object (set once, with a happens-before both source and invoke)
    //TODO: uint8_t absolute_max; // whether true max world is unknown

    // purity results
    // see also encode_effects() and decode_effects() in `base/compiler/effects.jl`,
    uint32_t ipo_purity_bits;
    // ipo_purity_flags:
    //     uint8_t ipo_consistent          : 2;
    //     uint8_t ipo_effect_free         : 2;
    //     uint8_t ipo_nothrow             : 2;
    //     uint8_t ipo_terminates          : 2;
    //     uint8_t ipo_nonoverlayed        : 1;
    //     uint8_t ipo_notaskstate         : 2;
    //     uint8_t ipo_inaccessiblememonly : 2;
    _Atomic(uint32_t) purity_bits;
    // purity_flags:
    //     uint8_t consistent          : 2;
    //     uint8_t effect_free         : 2;
    //     uint8_t nothrow             : 2;
    //     uint8_t terminates          : 2;
    //     uint8_t nonoverlayed        : 1;
    //     uint8_t notaskstate         : 2;
    //     uint8_t inaccessiblememonly : 2;
    language_value_t *analysis_results; // Analysis results about this code (IPO-safe)

    // compilation state cache
    _Atomic(uint8_t) specsigflags; // & 0b001 == specptr is a specialized function signature for specTypes->rettype
                                   // & 0b010 == invokeptr matches specptr
                                   // & 0b100 == From image
    _Atomic(uint8_t) precompile;  // if set, this will be added to the output system image
    uint8_t relocatability;  // nonzero if all roots are built into sysimg or tagged by module key
    _Atomic(language_callptr_t) invoke; // jlcall entry point
    union _language_generic_specptr_t {
        _Atomic(void*) fptr;
        _Atomic(language_fptr_args_t) fptr1;
        // 2 constant
        _Atomic(language_fptr_sparam_t) fptr3;
        // 4 interpreter
    } specptr; // private data for `jlcall entry point
} language_code_instance_t;

// all values are callable as Functions
typedef language_value_t language_function_t;

typedef struct {
    LANGUAGE_DATA_TYPE
    language_sym_t *name;
    language_value_t *lb;   // lower bound
    language_value_t *ub;   // upper bound
} language_tvar_t;

// UnionAll type (iterated union over all values of a variable in certain bounds)
// written `body where lb<:var<:ub`
typedef struct {
    LANGUAGE_DATA_TYPE
    language_tvar_t *var;
    language_value_t *body;
} language_unionall_t;

// represents the "name" part of a DataType, describing the syntactic structure
// of a type and storing all data common to different instantiations of the type,
// including a cache for hash-consed allocation of DataType objects.
typedef struct {
    LANGUAGE_DATA_TYPE
    language_sym_t *name;
    struct _language_module_t *module;
    language_svec_t *names;  // field names
    const uint32_t *atomicfields; // if any fields are atomic, we record them here
    const uint32_t *constfields; // if any fields are const, we record them here
    // `wrapper` is either the only instantiation of the type (if no parameters)
    // or a UnionAll accepting parameters to make an instantiation.
    language_value_t *wrapper;
    _Atomic(language_value_t*) Typeofwrapper;  // cache for Type{wrapper}
    _Atomic(language_svec_t*) cache;        // sorted array
    _Atomic(language_svec_t*) linearcache;  // unsorted array
    struct _language_methtable_t *mt;
    language_array_t *partial;     // incomplete instantiations of this type
    intptr_t hash;
    int32_t n_uninitialized;
    // type properties
    uint8_t abstract:1;
    uint8_t mutabl:1;
    uint8_t mayinlinealloc:1;
    uint8_t _reserved:5;
    uint8_t max_methods; // override for inference's max_methods setting (0 = no additional limit or relaxation)
} language_typename_t;

typedef struct {
    LANGUAGE_DATA_TYPE
    language_value_t *a;
    language_value_t *b;
} language_uniontype_t;

// in little-endian, isptr is always the first bit, avoiding the need for a branch in computing isptr
typedef struct {
    uint8_t isptr:1;
    uint8_t size:7;
    uint8_t offset;   // offset relative to data start, excluding type tag
} language_fielddesc8_t;

typedef struct {
    uint16_t isptr:1;
    uint16_t size:15;
    uint16_t offset;   // offset relative to data start, excluding type tag
} language_fielddesc16_t;

typedef struct {
    uint32_t isptr:1;
    uint32_t size:31;
    uint32_t offset;   // offset relative to data start, excluding type tag
} language_fielddesc32_t;

typedef struct {
    uint32_t size;
    uint32_t nfields;
    uint32_t npointers; // number of pointers embedded inside
    int32_t first_ptr; // index of the first pointer (or -1)
    uint16_t alignment; // strictest alignment over all fields
    struct { // combine these fields into a struct so that we can take addressof them
        uint16_t haspadding : 1; // has internal undefined bytes
        uint16_t fielddesc_type : 2; // 0 -> 8, 1 -> 16, 2 -> 32, 3 -> foreign type
        // metadata bit only for GenericMemory eltype layout
        uint16_t arrayelem_isboxed : 1;
        uint16_t arrayelem_isunion : 1;
        // If set, this type's egality can be determined entirely by comparing
        // the non-padding bits of this datatype.
        uint16_t isbitsegal : 1;
        uint16_t padding : 10;
    } flags;
    // union {
    //     language_fielddesc8_t field8[nfields];
    //     language_fielddesc16_t field16[nfields];
    //     language_fielddesc32_t field32[nfields];
    // };
    // union { // offsets relative to data start in words
    //     uint8_t ptr8[npointers];
    //     uint16_t ptr16[npointers];
    //     uint32_t ptr32[npointers];
    // };
} language_datatype_layout_t;

typedef struct _language_datatype_t {
    LANGUAGE_DATA_TYPE
    language_typename_t *name;
    struct _language_datatype_t *super;
    language_svec_t *parameters;
    language_svec_t *types;
    language_value_t *instance;  // for singletons
    const language_datatype_layout_t *layout;
    // memoized properties (set on construction)
    uint32_t hash;
    uint16_t hasfreetypevars:1; // majority part of isconcrete computation
    uint16_t isconcretetype:1; // whether this type can have instances
    uint16_t isdispatchtuple:1; // aka isleaftupletype
    uint16_t isbitstype:1; // relevant query for C-api and type-parameters
    uint16_t zeroinit:1; // if one or more fields requires zero-initialization
    uint16_t has_concrete_subtype:1; // If clear, no value will have this datatype
    uint16_t maybe_subtype_of_cache:1; // Computational bit for has_concrete_supertype. See description in types.c.
    uint16_t isprimitivetype:1; // whether this is declared with 'primitive type' keyword (sized, no fields, and immutable)
    uint16_t ismutationfree:1; // whether any mutable memory is reachable through this type (in the type or via fields)
    uint16_t isidentityfree:1; // whether this type or any object reachable through its fields has non-content-based identity
    uint16_t smalltag:6; // whether this type has a small-tag optimization
} language_datatype_t;

typedef struct _language_vararg_t {
    LANGUAGE_DATA_TYPE
    language_value_t *T;
    language_value_t *N;
} language_vararg_t;

typedef struct _language_weakref_t {
    LANGUAGE_DATA_TYPE
    language_value_t *value;
} language_weakref_t;

typedef struct _language_binding_t {
    LANGUAGE_DATA_TYPE
    _Atomic(language_value_t*) value;
    language_globalref_t *globalref;  // cached GlobalRef for this binding
    _Atomic(struct _language_binding_t*) owner;  // for individual imported bindings (NULL until 'resolved')
    _Atomic(language_value_t*) ty;  // binding type
    uint8_t constp:1;
    uint8_t exportp:1; // `public foo` sets `publicp`, `export foo` sets both `publicp` and `exportp`
    uint8_t publicp:1; // exportp without publicp is not allowed.
    uint8_t imported:1;
    uint8_t usingfailed:1;
    uint8_t deprecated:2; // 0=not deprecated, 1=renamed, 2=moved to another package
    uint8_t padding:1;
} language_binding_t;

typedef struct {
    uint64_t hi;
    uint64_t lo;
} language_uuid_t;

typedef struct _language_module_t {
    LANGUAGE_DATA_TYPE
    language_sym_t *name;
    struct _language_module_t *parent;
    _Atomic(language_svec_t*) bindings;
    _Atomic(language_genericmemory_t*) bindingkeyset; // index lookup by name into bindings
    // hidden fields:
    arraylist_t usings;  // modules with all bindings potentially imported
    language_uuid_t build_id;
    language_uuid_t uuid;
    _Atomic(uint32_t) counter;
    int32_t nospecialize;  // global bit flags: initialization for new methods
    int8_t optlevel;
    int8_t compile;
    int8_t infer;
    uint8_t istopmod;
    int8_t max_methods;
    language_mutex_t lock;
    intptr_t hash;
} language_module_t;

struct _language_globalref_t {
    language_module_t *mod;
    language_sym_t *name;
    language_binding_t *binding;
};

// one Type-to-Value entry
typedef struct _language_typemap_entry_t {
    LANGUAGE_DATA_TYPE
    _Atomic(struct _language_typemap_entry_t*) next; // invasive linked list
    language_tupletype_t *sig; // the type signature for this entry
    language_tupletype_t *simplesig; // a simple signature for fast rejection
    language_svec_t *guardsigs;
    _Atomic(size_t) min_world;
    _Atomic(size_t) max_world;
    union {
        language_value_t *value; // generic accessor
        language_method_instance_t *linfo; // [nullable] for guard entries
        language_method_t *method;
    } func;
    // memoized properties of sig:
    int8_t isleafsig; // isleaftype(sig) & !any(isType, sig) : unsorted and very fast
    int8_t issimplesig; // all(isleaftype | isAny | isType | isVararg, sig) : sorted and fast
    int8_t va; // isVararg(sig)
} language_typemap_entry_t;

// one level in a TypeMap tree (each level splits on a type at a given offset)
typedef struct _language_typemap_level_t {
    LANGUAGE_DATA_TYPE
    // these vectors contains vectors of more levels in their intended visit order
    // with an index that gives the functionality of a sorted dict.
    // next split may be on Type{T} as LeafTypes then TypeName's parents up to Any
    // next split may be on LeafType
    // next split may be on TypeName
    _Atomic(language_genericmemory_t*) arg1; // contains LeafType (in a map of non-abstract TypeName)
    _Atomic(language_genericmemory_t*) targ; // contains Type{LeafType} (in a map of non-abstract TypeName)
    _Atomic(language_genericmemory_t*) name1; // a map for a map for TypeName, for parents up to (excluding) Any
    _Atomic(language_genericmemory_t*) tname; // a map for Type{TypeName}, for parents up to (including) Any
    // next a linear list of things too complicated at this level for analysis (no more levels)
    _Atomic(language_typemap_entry_t*) linear;
    // finally, start a new level if the type at offs is Any
    _Atomic(language_typemap_t*) any;
} language_typemap_level_t;

// contains the TypeMap for one Type
typedef struct _language_methtable_t {
    LANGUAGE_DATA_TYPE
    language_sym_t *name; // sometimes used for debug printing
    _Atomic(language_typemap_t*) defs;
    _Atomic(language_genericmemory_t*) leafcache;
    _Atomic(language_typemap_t*) cache;
    _Atomic(intptr_t) max_args;  // max # of non-vararg arguments in a signature
    language_module_t *module; // sometimes used for debug printing
    language_array_t *backedges; // (sig, caller::MethodInstance) pairs
    language_mutex_t writelock;
    uint8_t offs;  // 0, or 1 to skip splitting typemap on first (function) argument
    uint8_t frozen; // whether this accepts adding new methods
} language_methtable_t;

typedef struct {
    LANGUAGE_DATA_TYPE
    language_sym_t *head;
    language_array_t *args;
} language_expr_t;

typedef struct {
    LANGUAGE_DATA_TYPE
    language_tupletype_t *spec_types;
    language_svec_t *sparams;
    language_method_t *method;
    // A bool on the julia side, but can be temporarily 0x2 as a sentinel
    // during construction.
    uint8_t fully_covers;
} language_method_match_t;

// constants and type objects -------------------------------------------------

#define LANGUAGE_SMALL_TYPEOF(XX) \
    /* kinds */ \
    XX(typeofbottom) \
    XX(datatype) \
    XX(unionall) \
    XX(uniontype) \
    /* type parameter objects */ \
    XX(vararg) \
    XX(tvar) \
    XX(symbol) \
    XX(module) \
    /* special GC objects */ \
    XX(simplevector) \
    XX(string) \
    XX(task) \
    /* bits types with special allocators */ \
    XX(bool) \
    XX(char) \
    /*XX(float16)*/ \
    /*XX(float32)*/ \
    /*XX(float64)*/ \
    XX(int16) \
    XX(int32) \
    XX(int64) \
    XX(int8) \
    XX(uint16) \
    XX(uint32) \
    XX(uint64) \
    XX(uint8) \
    /* AST objects */ \
    /* XX(argument) */ \
    /* XX(newvarnode) */ \
    /* XX(slotnumber) */ \
    /* XX(ssavalue) */ \
    /* end of LANGUAGE_SMALL_TYPEOF */
enum language_small_typeof_tags {
    language_null_tag = 0,
#define XX(name) code_##name##_tag,
    LANGUAGE_SMALL_TYPEOF(XX)
#undef XX
    language_tags_count,
    language_bitstags_first = language_char_tag, // n.b. bool is not considered a bitstype, since it can be compared by pointer
    language_max_tags = 64
};
extern LANGUAGE_DLLIMPORT language_datatype_t *language_small_typeof[(language_max_tags << 4) / sizeof(language_datatype_t*)];
#ifndef LANGUAGE_LIBRARY_EXPORTS_INTERNAL
static inline language_value_t *language_to_typeof(uintptr_t t)
{
    if (t < (language_max_tags << 4))
        return (language_value_t*)language_small_typeof[t / sizeof(*language_small_typeof)];
    return (language_value_t*)t;
}
#else
extern LANGUAGE_HIDDEN language_datatype_t *ilanguage_small_typeof[(language_max_tags << 4) / sizeof(language_datatype_t*)];
static inline language_value_t *language_to_typeof(uintptr_t t)
{
    if (t < (language_max_tags << 4))
        return (language_value_t*)ilanguage_small_typeof[t / sizeof(*ilanguage_small_typeof)];
    return (language_value_t*)t;
}
#endif


// kinds
extern LANGUAGE_DLLIMPORT language_datatype_t *language_typeofbottom_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_datatype_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uniontype_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_unionall_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_tvar_type LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_datatype_t *language_any_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_type_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_typename_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_type_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_symbol_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_ssavalue_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_slotnumber_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_argument_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_const_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_partial_struct_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_partial_opaque_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_interconditional_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_method_match_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_simplevector_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_tuple_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_vecelement_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_anytuple_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_emptytuple_type LANGUAGE_GLOBALLY_ROOTED;
#define language_tuple_type language_anytuple_type
extern LANGUAGE_DLLIMPORT language_unionall_t *language_anytuple_type_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_vararg_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_function_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_builtin_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_opaque_closure_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_opaque_closure_typename LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_value_t *language_bottom_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_method_instance_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_code_instance_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_code_info_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_debuginfo_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_method_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_module_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_addrspace_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_addrspace_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_addrspacecore_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_abstractarray_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_densearray_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_array_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_array_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_genericmemory_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_genericmemory_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_genericmemoryref_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_genericmemoryref_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_weakref_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_abstractstring_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_string_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_errorexception_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_argumenterror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_loaderror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_initerror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_typeerror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_methoderror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_undefvarerror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_atomicerror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_missingcodeerror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_lineinfonode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_stackovf_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_readonlymemory_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_diverror_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_undefref_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_interrupt_exception LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_precompilable_error LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_boundserror_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_an_empty_vec_any LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_an_empty_memory_any LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_an_empty_string LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_datatype_t *language_bool_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_char_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_int8_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uint8_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_int16_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uint16_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_int32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uint32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_int64_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uint64_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_float16_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_float32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_float64_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_bfloat16_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_floatingpoint_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_number_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_void_type LANGUAGE_GLOBALLY_ROOTED;  // deprecated
extern LANGUAGE_DLLIMPORT language_datatype_t *language_nothing_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_signed_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_voidpointer_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_uint8pointer_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_pointer_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_llvmpointer_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_ref_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_pointer_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_llvmpointer_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_typename_t *language_namedtuple_typename LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_unionall_t *language_namedtuple_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_task_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_pair_type LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_value_t *language_array_uint8_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_array_any_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_array_symbol_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_array_int32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_array_uint32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_array_uint64_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_uint8_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_uint16_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_uint32_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_uint64_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memory_any_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memoryref_uint8_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_memoryref_any_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_expr_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_binding_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_globalref_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_linenumbernode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_gotonode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_gotoifnot_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_enternode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_returnnode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_phinode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_pinode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_phicnode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_upsilonnode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_quotenode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_newvarnode_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_intrinsic_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_methtable_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_typemap_level_type LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_datatype_t *language_typemap_entry_type LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_svec_t *language_emptysvec LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_emptytuple LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_true LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_false LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_nothing LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_value_t *language_kwcall_func LANGUAGE_GLOBALLY_ROOTED;

extern LANGUAGE_DLLIMPORT language_value_t    *language_libdl_dlopen_func LANGUAGE_GLOBALLY_ROOTED;

// gc -------------------------------------------------------------------------

struct _language_gcframe_t {
    size_t nroots;
    struct _language_gcframe_t *prev;
    // actual roots go here
};

// NOTE: it is the caller's responsibility to make sure arguments are
// rooted such that the gc can see them on the stack.
// `foo(f(), g())` is not safe,
// since the result of `f()` is not rooted during the call to `g()`,
// and the arguments to foo are not gc-protected during the call to foo.
// foo can't do anything about it, so the caller must do:
// language_value_t *x=NULL, *y=NULL; LANGUAGE_GC_PUSH2(&x, &y);
// x = f(); y = g(); foo(x, y)

#define language_pgcstack (language_current_task->gcstack)

#define LANGUAGE_GC_ENCODE_PUSHARGS(n)   (((size_t)(n))<<2)
#define LANGUAGE_GC_ENCODE_PUSH(n)       ((((size_t)(n))<<2)|1)

#ifdef __clang_gcanalyzer__

// When running with the analyzer make these real function calls, that are
// easier to detect in the analyzer
extern void LANGUAGE_GC_PUSH1(void *) LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH2(void *, void *) LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH3(void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH4(void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH5(void *, void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH6(void *, void *, void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH7(void *, void *, void *, void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH8(void *, void *, void *, void *, void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void LANGUAGE_GC_PUSH9(void *, void *, void *, void *, void *, void *, void *, void *, void *)  LANGUAGE_NOTSAFEPOINT;
extern void _LANGUAGE_GC_PUSHARGS(language_value_t **, size_t) LANGUAGE_NOTSAFEPOINT;
// This is necessary, because otherwise the analyzer considers this undefined
// behavior and terminates the exploration
#define LANGUAGE_GC_PUSHARGS(rts_var, n)     \
  rts_var = (language_value_t **)alloca(sizeof(void*) * (n)); \
  memset(rts_var, 0, sizeof(void*) * (n)); \
  _LANGUAGE_GC_PUSHARGS(rts_var, (n));

extern void LANGUAGE_GC_POP() LANGUAGE_NOTSAFEPOINT;

#else

#define LANGUAGE_GC_PUSH1(arg1)                                                                               \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(1), language_pgcstack, arg1};                                 \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH2(arg1, arg2)                                                                         \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(2), language_pgcstack, arg1, arg2};                           \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH3(arg1, arg2, arg3)                                                                   \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(3), language_pgcstack, arg1, arg2, arg3};                     \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH4(arg1, arg2, arg3, arg4)                                                             \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(4), language_pgcstack, arg1, arg2, arg3, arg4};               \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH5(arg1, arg2, arg3, arg4, arg5)                                                       \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(5), language_pgcstack, arg1, arg2, arg3, arg4, arg5};         \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH6(arg1, arg2, arg3, arg4, arg5, arg6)                                                 \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(6), language_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6};   \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH7(arg1, arg2, arg3, arg4, arg5, arg6, arg7)                                           \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(7), language_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6, arg7}; \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH8(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)                                     \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(8), language_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8}; \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;

#define LANGUAGE_GC_PUSH9(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)                               \
  void *__gc_stkf[] = {(void*)LANGUAGE_GC_ENCODE_PUSH(9), language_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9}; \
  language_pgcstack = (language_gcframe_t*)__gc_stkf;


#define LANGUAGE_GC_PUSHARGS(rts_var,n)                                                                       \
  rts_var = ((language_value_t**)alloca(((n)+2)*sizeof(language_value_t*)))+2;                                      \
  ((void**)rts_var)[-2] = (void*)LANGUAGE_GC_ENCODE_PUSHARGS(n);                                              \
  ((void**)rts_var)[-1] = language_pgcstack;                                                                  \
  memset((void*)rts_var, 0, (n)*sizeof(language_value_t*));                                                   \
  language_pgcstack = (language_gcframe_t*)&(((void**)rts_var)[-2])

#define LANGUAGE_GC_POP() (language_pgcstack = language_pgcstack->prev)

#endif

LANGUAGE_DLLEXPORT int language_gc_enable(int on);
LANGUAGE_DLLEXPORT int language_gc_is_enabled(void);

typedef enum {
    LANGUAGE_GC_AUTO = 0,         // use heuristics to determine the collection type
    LANGUAGE_GC_FULL = 1,         // force a full collection
    LANGUAGE_GC_INCREMENTAL = 2,  // force an incremental collection
} language_gc_collection_t;

LANGUAGE_DLLEXPORT void language_gc_collect(language_gc_collection_t);

LANGUAGE_DLLEXPORT void language_gc_add_finalizer(language_value_t *v, language_function_t *f) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_add_ptr_finalizer(language_ptls_t ptls, language_value_t *v, void *f) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_add_quiescent(language_ptls_t ptls, void **v, void *f) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_finalize(language_value_t *o);
LANGUAGE_DLLEXPORT language_weakref_t *language_gc_new_weakref(language_value_t *value);
LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_0w(void);
LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_1w(void);
LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_2w(void);
LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc_3w(void);
LANGUAGE_DLLEXPORT language_value_t *language_gc_allocobj(size_t sz);
LANGUAGE_DLLEXPORT void *language_malloc_stack(size_t *bufsz, struct _language_task_t *owner) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_free_stack(void *stkbuf, size_t bufsz);
LANGUAGE_DLLEXPORT void language_gc_use(language_value_t *a);
// Set GC memory trigger in bytes for greedy memory collecting
LANGUAGE_DLLEXPORT void language_gc_set_max_memory(uint64_t max_mem);
LANGUAGE_DLLEXPORT uint64_t language_gc_get_max_memory(void);

LANGUAGE_DLLEXPORT void language_clear_malloc_data(void);

// GC write barriers
LANGUAGE_DLLEXPORT void language_gc_queue_root(const language_value_t *root) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_queue_multiroot(const language_value_t *root, const void *stored, language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT;

STATIC_INLINE void language_gc_wb(const void *parent, const void *ptr) LANGUAGE_NOTSAFEPOINT
{
    // parent and ptr isa language_value_t*
    if (__unlikely(language_astaggedvalue(parent)->bits.gc == 3 && // parent is old and not in remset
                   (language_astaggedvalue(ptr)->bits.gc & 1) == 0)) // ptr is young
        language_gc_queue_root((language_value_t*)parent);
}

STATIC_INLINE void language_gc_wb_back(const void *ptr) LANGUAGE_NOTSAFEPOINT // ptr isa language_value_t*
{
    // if ptr is old
    if (__unlikely(language_astaggedvalue(ptr)->bits.gc == 3)) {
        language_gc_queue_root((language_value_t*)ptr);
    }
}

STATIC_INLINE void language_gc_multi_wb(const void *parent, const language_value_t *ptr) LANGUAGE_NOTSAFEPOINT
{
    // 3 == GC_OLD_MARKED
    // ptr is an immutable object
    if (__likely(language_astaggedvalue(parent)->bits.gc != 3))
        return; // parent is young or in remset
    if (__likely(language_astaggedvalue(ptr)->bits.gc == 3))
        return; // ptr is old and not in remset (thus it does not point to young)
    language_datatype_t *dt = (language_datatype_t*)language_typeof(ptr);
    const language_datatype_layout_t *ly = dt->layout;
    if (ly->npointers)
        language_gc_queue_multiroot((language_value_t*)parent, ptr, dt);
}

LANGUAGE_DLLEXPORT void *language_gc_managed_malloc(size_t sz);
LANGUAGE_DLLEXPORT void *language_gc_managed_realloc(void *d, size_t sz, size_t oldsz,
                                         int isaligned, language_value_t *owner);
LANGUAGE_DLLEXPORT void language_gc_safepoint(void);
LANGUAGE_DLLEXPORT int language_safepoint_suspend_thread(int tid, int waitstate);
LANGUAGE_DLLEXPORT int language_safepoint_resume_thread(int tid) LANGUAGE_NOTSAFEPOINT;

void *mtarraylist_get(small_arraylist_t *_a, size_t idx) LANGUAGE_NOTSAFEPOINT;
size_t mtarraylist_length(small_arraylist_t *_a) LANGUAGE_NOTSAFEPOINT;
void mtarraylist_add(small_arraylist_t *_a, void *elt, size_t idx) LANGUAGE_NOTSAFEPOINT;
void mtarraylist_push(small_arraylist_t *_a, void *elt) LANGUAGE_NOTSAFEPOINT;

// object accessors -----------------------------------------------------------

#define language_svec_len(t)              (((language_svec_t*)(t))->length)
#define language_svec_set_len_unsafe(t,n) (((language_svec_t*)(t))->length=(n))
#define language_svec_data(t) ((language_value_t**)((char*)(t) + sizeof(language_svec_t)))

#ifdef __clang_gcanalyzer__
STATIC_INLINE language_value_t *language_svecref(void *t LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;
STATIC_INLINE language_value_t *language_svecset(
    void *t LANGUAGE_ROOTING_ARGUMENT LANGUAGE_PROPAGATES_ROOT,
    size_t i, void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT;
#else
STATIC_INLINE language_value_t *language_svecref(void *t LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    assert(language_typetagis(t,language_simplevector_tag << 4));
    assert(i < language_svec_len(t));
    // while svec is supposedly immutable, in practice we sometimes publish it first
    // and set the values lazily
    return language_atomic_load_relaxed((_Atomic(language_value_t*)*)language_svec_data(t) + i);
}
STATIC_INLINE language_value_t *language_svecset(
    void *t LANGUAGE_ROOTING_ARGUMENT LANGUAGE_PROPAGATES_ROOT,
    size_t i, void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT
{
    assert(language_typetagis(t,language_simplevector_tag << 4));
    assert(i < language_svec_len(t));
    // while svec is supposedly immutable, in practice we sometimes publish it
    // first and set the values lazily. Those users occasionally might need to
    // instead use language_atomic_store_release here.
    language_atomic_store_relaxed((_Atomic(language_value_t*)*)language_svec_data(t) + i, (language_value_t*)x);
    language_gc_wb(t, x);
    return (language_value_t*)x;
}
#endif

#define language_genericmemory_data_owner_field(a) (*(language_value_t**)((language_genericmemory_t*)(a) + 1))

#define language_nparams(t)  language_svec_len(((language_datatype_t*)(t))->parameters)
#define language_tparam0(t)  language_svecref(((language_datatype_t*)(t))->parameters, 0)
#define language_tparam1(t)  language_svecref(((language_datatype_t*)(t))->parameters, 1)
#define language_tparam2(t)  language_svecref(((language_datatype_t*)(t))->parameters, 2)
#define language_tparam(t,i) language_svecref(((language_datatype_t*)(t))->parameters, i)
#define language_array_data(a,t) ((t*)((language_array_t*)(a))->ref.ptr_or_offset)
#define language_array_data_(a) ((void*)((language_array_t*)(a))->ref.ptr_or_offset)
#define language_array_dim(a,i) (((language_array_t*)(a))->dimsize[i])
#define language_array_dim0(a)  (((language_array_t*)(a))->dimsize[0])
#define language_array_nrows(a) (((language_array_t*)(a))->dimsize[0])
#define language_array_ndims(a) (*(size_t*)language_tparam1(language_typetagof(a)))
#define language_array_maxsize(a) (((language_array_t*)(a))->ref.mem->length)
#define language_array_len(a)   (language_array_ndims(a) == 1 ? language_array_nrows(a) : language_array_maxsize(a))

/*
  how - allocation style
  0 = data is inlined
  1 = owns the gc-managed data, exclusively (will free it)
  2 = malloc-allocated pointer (does not own it)
  3 = has a pointer to the object that owns the data pointer
*/
STATIC_INLINE int language_genericmemory_how(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT
{
    if (m->ptr == (void*)((char*)m + 16)) // LANGUAGE_SMALL_BYTE_ALIGNMENT (from language_internal.h)
        return 0;
    language_value_t *owner = language_genericmemory_data_owner_field(m);
    if (owner == (language_value_t*)m)
        return 1;
    if (owner == NULL)
        return 2;
    return 3;
}

STATIC_INLINE language_value_t *language_genericmemory_owner(language_genericmemory_t *m LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    if (language_genericmemory_how(m) == 3)
        return language_genericmemory_data_owner_field(m);
    return (language_value_t*)m;
}

LANGUAGE_DLLEXPORT char *language_genericmemory_typetagdata(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT;

#ifdef __clang_gcanalyzer__
language_value_t **language_genericmemory_ptr_data(language_genericmemory_t *m LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
STATIC_INLINE language_value_t *language_genericmemory_ptr_ref(void *m LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;
STATIC_INLINE language_value_t *language_genericmemory_ptr_set(
    void *m LANGUAGE_ROOTING_ARGUMENT, size_t i,
    void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT;
#else
#define language_genericmemory_ptr_data(a)  ((language_value_t**)((language_genericmemory_t*)(a))->ptr)
STATIC_INLINE language_value_t *language_genericmemory_ptr_ref(void *m LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    language_genericmemory_t *m_ = (language_genericmemory_t*)m;
    assert(((language_datatype_t*)language_typetagof(m_))->layout->flags.arrayelem_isboxed);
    assert(i < m_->length);
    return language_atomic_load_relaxed(((_Atomic(language_value_t*)*)(m_->ptr)) + i);
}
STATIC_INLINE language_value_t *language_genericmemory_ptr_set(
    void *m LANGUAGE_ROOTING_ARGUMENT, size_t i,
    void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT
{
    language_genericmemory_t *m_ = (language_genericmemory_t*)m;
    assert(((language_datatype_t*)language_typetagof(m_))->layout->flags.arrayelem_isboxed);
    assert(i < m_->length);
    language_atomic_store_release(((_Atomic(language_value_t*)*)(m_->ptr)) + i, (language_value_t*)x);
    if (x) {
        if (language_genericmemory_how(m_) == 3)
            m = (void*)language_genericmemory_data_owner_field(m_);
        language_gc_wb(m, x);
    }
    return (language_value_t*)x;
}
#endif

STATIC_INLINE uint8_t language_memory_uint8_ref(void *m, size_t i) LANGUAGE_NOTSAFEPOINT
{
    language_genericmemory_t *m_ = (language_genericmemory_t*)m;
    assert(language_typetagis(m_, language_memory_uint8_type));
    assert(i < m_->length);
    return ((uint8_t*)m_->ptr)[i];
}
STATIC_INLINE void language_memory_uint8_set(void *m, size_t i, uint8_t x) LANGUAGE_NOTSAFEPOINT
{
    language_genericmemory_t *m_ = (language_genericmemory_t*)m;
    assert(language_typetagis(m_, language_memory_uint8_type));
    assert(i < m_->length);
    ((uint8_t*)m_->ptr)[i] = x;
}

STATIC_INLINE language_value_t *language_array_owner(language_array_t *a LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    return language_genericmemory_owner(a->ref.mem);
}

#ifdef __clang_gcanalyzer__
language_value_t **language_array_ptr_data(language_array_t *a LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
STATIC_INLINE language_value_t *language_array_ptr_ref(void *a LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;
STATIC_INLINE language_value_t *language_array_ptr_set(
    void *a LANGUAGE_ROOTING_ARGUMENT, size_t i,
    void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT;
#else
#define language_array_ptr_data(a) (language_array_data(a, language_value_t*))
STATIC_INLINE language_value_t *language_array_ptr_ref(void *a LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    assert(((language_datatype_t*)language_typetagof(((language_array_t*)a)->ref.mem))->layout->flags.arrayelem_isboxed);
    assert(i < language_array_len(a));
    return language_atomic_load_relaxed(language_array_data(a, _Atomic(language_value_t*)) + i);
}
STATIC_INLINE language_value_t *language_array_ptr_set(
    void *a LANGUAGE_ROOTING_ARGUMENT, size_t i,
    void *x LANGUAGE_ROOTED_ARGUMENT) LANGUAGE_NOTSAFEPOINT
{
    assert(((language_datatype_t*)language_typetagof(((language_array_t*)a)->ref.mem))->layout->flags.arrayelem_isboxed);
    assert(i < language_array_len(a));
    language_atomic_store_release(language_array_data(a, _Atomic(language_value_t*)) + i, (language_value_t*)x);
    if (x) {
        language_gc_wb(language_array_owner((language_array_t*)a), x);
    }
    return (language_value_t*)x;
}
#endif

STATIC_INLINE uint8_t language_array_uint8_ref(void *a, size_t i) LANGUAGE_NOTSAFEPOINT
{
    assert(language_typetagis(a, language_array_uint8_type));
    assert(i < language_array_len(a));
    return language_array_data(a, uint8_t)[i];
}
STATIC_INLINE void language_array_uint8_set(void *a, size_t i, uint8_t x) LANGUAGE_NOTSAFEPOINT
{
    assert(language_typetagis(a, language_array_uint8_type));
    assert(i < language_array_len(a));
    language_array_data(a, uint8_t)[i] = x;
}
STATIC_INLINE void language_array_uint32_set(void *a, size_t i, uint32_t x) LANGUAGE_NOTSAFEPOINT
{
    assert(i < language_array_len(a));
    assert(language_typetagis(a, language_array_uint32_type) || language_typetagis(a, language_array_int32_type));
    language_array_data(a, uint32_t)[i] = x;
}

#define language_exprarg(e,n) language_array_ptr_ref(((language_expr_t*)(e))->args, n)
#define language_exprargset(e, n, v) language_array_ptr_set(((language_expr_t*)(e))->args, n, v)
#define language_expr_nargs(e) language_array_nrows(((language_expr_t*)(e))->args)

#define language_fieldref(s,i) language_get_nth_field(((language_value_t*)(s)),i)
#define language_fieldref_noalloc(s,i) language_get_nth_field_noalloc(((language_value_t*)(s)),i)
#define language_nfields(v)    language_datatype_nfields(language_typeof(v))

// Not using language_fieldref to avoid allocations
#define language_linenode_line(x) (((intptr_t*)(x))[0])
#define language_linenode_file(x) (((language_value_t**)(x))[1])
#define language_slot_number(x) (((intptr_t*)(x))[0])
#define language_typedslot_get_type(x) (((language_value_t**)(x))[1])
#define language_gotonode_label(x) (((intptr_t*)(x))[0])
#define language_gotoifnot_cond(x) (((language_value_t**)(x))[0])
#define language_gotoifnot_label(x) (((intptr_t*)(x))[1])
#define language_enternode_catch_dest(x) (((intptr_t*)(x))[0])
#define language_enternode_scope(x) (((language_value_t**)(x))[1])
#define language_globalref_mod(s) (*(language_module_t**)(s))
#define language_globalref_name(s) (((language_sym_t**)(s))[1])
#define language_quotenode_value(x) (((language_value_t**)x)[0])
#define language_returnnode_value(x) (((language_value_t**)x)[0])

// get a pointer to the data in a datatype
#define language_data_ptr(v)  ((language_value_t**)v)

#define language_string_data(s) ((char*)s + sizeof(void*))
#define language_string_len(s)  (*(size_t*)s)

#define language_gf_ft_mtable(ft) (((language_datatype_t*)ft)->name->mt)
#define language_gf_mtable(f) (language_gf_ft_mtable(language_typeof(f)))
#define language_gf_name(f)   (language_gf_mtable(f)->name)

// struct type info
LANGUAGE_DLLEXPORT language_svec_t *language_compute_fieldtypes(language_datatype_t *st LANGUAGE_PROPAGATES_ROOT, void *stack, int cacheable);
#define language_get_fieldtypes(st) ((st)->types ? (st)->types : language_compute_fieldtypes((st), NULL, 0))
STATIC_INLINE language_svec_t *language_field_names(language_datatype_t *st) LANGUAGE_NOTSAFEPOINT
{
    return st->name->names;
}
STATIC_INLINE language_value_t *language_field_type(language_datatype_t *st LANGUAGE_PROPAGATES_ROOT, size_t i)
{
    return language_svecref(language_get_fieldtypes(st), i);
}
STATIC_INLINE language_value_t *language_field_type_concrete(language_datatype_t *st LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    assert(st->types);
    return language_svecref(st->types, i);
}

STATIC_INLINE int language_is_layout_opaque(const language_datatype_layout_t *l) LANGUAGE_NOTSAFEPOINT
{
    return l->nfields == 0 && l->npointers > 0;
}

LANGUAGE_DLLEXPORT language_value_t *language_unwrap_unionall(language_value_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;

#define language_inlinedatatype_layout(t) (((language_datatype_t*)t)->layout)
STATIC_INLINE const language_datatype_layout_t *language_datatype_layout(language_datatype_t *t) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_layout_opaque(t->layout)) // e.g. GenericMemory
        t = (language_datatype_t*)language_unwrap_unionall(t->name->wrapper);
    return t->layout;
}
#define language_datatype_size(t)    (language_datatype_layout((language_datatype_t*)(t))->size)
#define language_datatype_align(t)   (language_datatype_layout((language_datatype_t*)(t))->alignment)
#define language_datatype_nbits(t)   ((language_datatype_layout((language_datatype_t*)(t))->size)*8)
#define language_datatype_nfields(t) (language_datatype_layout((language_datatype_t*)(t))->nfields)

LANGUAGE_DLLEXPORT void *language_symbol_name(language_sym_t *s);
// inline version with strong type check to detect typos in a `->name` chain
STATIC_INLINE char *language_symbol_name_(language_sym_t *s) LANGUAGE_NOTSAFEPOINT
{
    return (char*)s + LLT_ALIGN(sizeof(language_sym_t), sizeof(void*));
}
#define language_symbol_name(s) language_symbol_name_(s)

static inline uint32_t language_fielddesc_size(int8_t fielddesc_type) LANGUAGE_NOTSAFEPOINT
{
    assert(fielddesc_type >= 0 && fielddesc_type <= 2);
    return 2 << fielddesc_type;
    //if (fielddesc_type == 0) {
    //    return sizeof(language_fielddesc8_t);
    //}
    //else if (fielddesc_type == 1) {
    //    return sizeof(language_fielddesc16_t);
    //}
    //else {
    //    return sizeof(language_fielddesc32_t);
    //}
}

#define language_dt_layout_fields(d) ((const char*)(d) + sizeof(language_datatype_layout_t))
static inline const char *language_dt_layout_ptrs(const language_datatype_layout_t *l) LANGUAGE_NOTSAFEPOINT
{
    return language_dt_layout_fields(l) + language_fielddesc_size(l->flags.fielddesc_type) * l->nfields;
}

#define DEFINE_FIELD_ACCESSORS(f)                                             \
    static inline uint32_t language_field_##f(language_datatype_t *st,                    \
                                        int i) LANGUAGE_NOTSAFEPOINT                \
    {                                                                         \
        const language_datatype_layout_t *ly = language_datatype_layout(st);              \
        assert(i >= 0 && (size_t)i < ly->nfields);                            \
        if (ly->flags.fielddesc_type == 0) {                                  \
            return ((const language_fielddesc8_t*)language_dt_layout_fields(ly))[i].f;    \
        }                                                                     \
        else if (ly->flags.fielddesc_type == 1) {                             \
            return ((const language_fielddesc16_t*)language_dt_layout_fields(ly))[i].f;   \
        }                                                                     \
        else {                                                                \
            assert(ly->flags.fielddesc_type == 2);                            \
            return ((const language_fielddesc32_t*)language_dt_layout_fields(ly))[i].f;   \
        }                                                                     \
    }                                                                         \

DEFINE_FIELD_ACCESSORS(offset)
DEFINE_FIELD_ACCESSORS(size)
#undef DEFINE_FIELD_ACCESSORS

static inline int language_field_isptr(language_datatype_t *st, int i) LANGUAGE_NOTSAFEPOINT
{
    const language_datatype_layout_t *ly = language_datatype_layout(st);
    assert(i >= 0 && (size_t)i < ly->nfields);
    return ((const language_fielddesc8_t*)(language_dt_layout_fields(ly) + language_fielddesc_size(ly->flags.fielddesc_type) * i))->isptr;
}

static inline uint32_t language_ptr_offset(language_datatype_t *st, int i) LANGUAGE_NOTSAFEPOINT
{
    const language_datatype_layout_t *ly = st->layout; // NOT language_datatype_layout(st)
    assert(i >= 0 && (size_t)i < ly->npointers);
    const void *ptrs = language_dt_layout_ptrs(ly);
    if (ly->flags.fielddesc_type == 0) {
        return ((const uint8_t*)ptrs)[i];
    }
    else if (ly->flags.fielddesc_type == 1) {
        return ((const uint16_t*)ptrs)[i];
    }
    else {
        assert(ly->flags.fielddesc_type == 2);
        return ((const uint32_t*)ptrs)[i];
    }
}

static inline int language_field_isatomic(language_datatype_t *st, int i) LANGUAGE_NOTSAFEPOINT
{
    const uint32_t *atomicfields = st->name->atomicfields;
    if (atomicfields != NULL) {
        if (atomicfields[i / 32] & (1 << (i % 32)))
            return 1;
    }
    return 0;
}

static inline int language_field_isconst(language_datatype_t *st, int i) LANGUAGE_NOTSAFEPOINT
{
    language_typename_t *tn = st->name;
    if (!tn->mutabl)
        return 1;
    const uint32_t *constfields = tn->constfields;
    if (constfields != NULL) {
        if (constfields[i / 32] & (1 << (i % 32)))
            return 1;
    }
    return 0;
}


// basic predicates -----------------------------------------------------------
#define language_is_nothing(v)     (((language_value_t*)(v)) == ((language_value_t*)language_nothing))
#define language_is_tuple(v)       (((language_datatype_t*)language_typeof(v))->name == language_tuple_typename)
#define language_is_namedtuple(v)  (((language_datatype_t*)language_typeof(v))->name == language_namedtuple_typename)
#define language_is_svec(v)        language_typetagis(v,language_simplevector_tag<<4)
#define language_is_simplevector(v) language_is_svec(v)
#define language_is_datatype(v)    language_typetagis(v,language_datatype_tag<<4)
#define language_is_mutable(t)     (((language_datatype_t*)t)->name->mutabl)
#define language_is_mutable_datatype(t) (language_is_datatype(t) && (((language_datatype_t*)t)->name->mutabl))
#define language_is_immutable(t)   (!((language_datatype_t*)t)->name->mutabl)
#define language_is_immutable_datatype(t) (language_is_datatype(t) && (!((language_datatype_t*)t)->name->mutabl))
#define language_is_uniontype(v)   language_typetagis(v,language_uniontype_tag<<4)
#define language_is_typevar(v)     language_typetagis(v,language_tvar_tag<<4)
#define language_is_unionall(v)    language_typetagis(v,language_unionall_tag<<4)
#define language_is_vararg(v)      language_typetagis(v,language_vararg_tag<<4)
#define language_is_typename(v)    language_typetagis(v,language_typename_type)
#define language_is_int8(v)        language_typetagis(v,language_int8_tag<<4)
#define language_is_int16(v)       language_typetagis(v,language_int16_tag<<4)
#define language_is_int32(v)       language_typetagis(v,language_int32_tag<<4)
#define language_is_int64(v)       language_typetagis(v,language_int64_tag<<4)
#define language_is_uint8(v)       language_typetagis(v,language_uint8_tag<<4)
#define language_is_uint16(v)      language_typetagis(v,language_uint16_tag<<4)
#define language_is_uint32(v)      language_typetagis(v,language_uint32_tag<<4)
#define language_is_uint64(v)      language_typetagis(v,language_uint64_tag<<4)
#define language_is_bool(v)        language_typetagis(v,language_bool_tag<<4)
#define language_is_symbol(v)      language_typetagis(v,language_symbol_tag<<4)
#define language_is_ssavalue(v)    language_typetagis(v,language_ssavalue_type)
#define language_is_slotnumber(v)  language_typetagis(v,language_slotnumber_type)
#define language_is_expr(v)        language_typetagis(v,language_expr_type)
#define language_is_binding(v)     language_typetagis(v,language_binding_type)
#define language_is_globalref(v)   language_typetagis(v,language_globalref_type)
#define language_is_gotonode(v)    language_typetagis(v,language_gotonode_type)
#define language_is_gotoifnot(v)   language_typetagis(v,language_gotoifnot_type)
#define language_is_returnnode(v)  language_typetagis(v,language_returnnode_type)
#define language_is_enternode(v)   language_typetagis(v,language_enternode_type)
#define language_is_argument(v)    language_typetagis(v,language_argument_type)
#define language_is_pinode(v)      language_typetagis(v,language_pinode_type)
#define language_is_phinode(v)     language_typetagis(v,language_phinode_type)
#define language_is_phicnode(v)    language_typetagis(v,language_phicnode_type)
#define language_is_upsilonnode(v) language_typetagis(v,language_upsilonnode_type)
#define language_is_quotenode(v)   language_typetagis(v,language_quotenode_type)
#define language_is_newvarnode(v)  language_typetagis(v,language_newvarnode_type)
#define language_is_linenode(v)    language_typetagis(v,language_linenumbernode_type)
#define language_is_method_instance(v) language_typetagis(v,language_method_instance_type)
#define language_is_code_instance(v) language_typetagis(v,language_code_instance_type)
#define language_is_code_info(v)   language_typetagis(v,language_code_info_type)
#define language_is_method(v)      language_typetagis(v,language_method_type)
#define language_is_module(v)      language_typetagis(v,language_module_tag<<4)
#define language_is_mtable(v)      language_typetagis(v,language_methtable_type)
#define language_is_task(v)        language_typetagis(v,language_task_tag<<4)
#define language_is_string(v)      language_typetagis(v,language_string_tag<<4)
#define language_is_cpointer(v)    language_is_cpointer_type(language_typeof(v))
#define language_is_pointer(v)     language_is_cpointer_type(language_typeof(v))
#define language_is_uint8pointer(v)language_typetagis(v,language_uint8pointer_type)
#define language_is_llvmpointer(v) (((language_datatype_t*)language_typeof(v))->name == language_llvmpointer_typename)
#define language_is_intrinsic(v)   language_typetagis(v,language_intrinsic_type)
#define language_is_addrspacecore(v) language_typetagis(v,language_addrspacecore_type)
#define language_genericmemory_isbitsunion(a) (((language_datatype_t*)language_typetagof(a))->layout->flags.arrayelem_isunion)

LANGUAGE_DLLEXPORT int language_subtype(language_value_t *a, language_value_t *b);

int is_leaf_bound(language_value_t *v) LANGUAGE_NOTSAFEPOINT;

STATIC_INLINE int language_is_kind(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return (v==(language_value_t*)language_uniontype_type || v==(language_value_t*)language_datatype_type ||
            v==(language_value_t*)language_unionall_type || v==(language_value_t*)language_typeofbottom_type);
}

STATIC_INLINE int language_is_kindtag(uintptr_t t) LANGUAGE_NOTSAFEPOINT
{
    t >>= 4;
    return (t==(uintptr_t)language_uniontype_tag || t==(uintptr_t)language_datatype_tag ||
            t==(uintptr_t)language_unionall_tag || t==(uintptr_t)language_typeofbottom_tag);
}

STATIC_INLINE int language_is_type(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return language_is_kindtag(language_typetagof(v));
}

STATIC_INLINE int language_is_primitivetype(void *v) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(v) && ((language_datatype_t*)(v))->isprimitivetype);
}

STATIC_INLINE int language_is_structtype(void *v) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(v) &&
            !((language_datatype_t*)(v))->name->abstract &&
            !((language_datatype_t*)(v))->isprimitivetype);
}

STATIC_INLINE int language_isbits(void *t) LANGUAGE_NOTSAFEPOINT // corresponding to isbitstype() in julia
{
    return language_is_datatype(t) && ((language_datatype_t*)t)->isbitstype;
}

STATIC_INLINE int language_is_datatype_singleton(language_datatype_t *d) LANGUAGE_NOTSAFEPOINT
{
    return d->instance != NULL && d->layout->size == 0 && d->layout->npointers == 0;
}

STATIC_INLINE int language_is_abstracttype(void *v) LANGUAGE_NOTSAFEPOINT
{
    return language_is_datatype(v) && ((language_datatype_t*)(v))->name->abstract;
}

STATIC_INLINE int language_is_array_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return language_is_datatype(t) &&
           ((language_datatype_t*)(t))->name == language_array_typename;
}

STATIC_INLINE int language_is_array(void *v) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *t = language_typeof(v);
    return language_is_array_type(t);
}

STATIC_INLINE int language_is_genericmemory_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_genericmemory_typename);
}

STATIC_INLINE int language_is_genericmemory(void *v) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *t = language_typeof(v);
    return language_is_genericmemory_type(t);
}

STATIC_INLINE int language_is_genericmemoryref_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_genericmemoryref_typename);
}

STATIC_INLINE int language_is_genericmemoryref(void *v) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *t = language_typeof(v);
    return language_is_genericmemoryref_type(t);
}

STATIC_INLINE int language_is_addrspace_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_addrspace_typename);
}

STATIC_INLINE int language_is_addrspace(void *v) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *t = language_typeof(v);
    return language_is_addrspace_type(t);
}


STATIC_INLINE int language_is_opaque_closure_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_opaque_closure_typename);
}

STATIC_INLINE int language_is_opaque_closure(void *v) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *t = language_typeof(v);
    return language_is_opaque_closure_type(t);
}

STATIC_INLINE int language_is_cpointer_type(language_value_t *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == ((language_datatype_t*)language_pointer_type->body)->name);
}

STATIC_INLINE int language_is_llvmpointer_type(language_value_t *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_llvmpointer_typename);
}

STATIC_INLINE int language_is_abstract_ref_type(language_value_t *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == ((language_datatype_t*)language_ref_type->body)->name);
}

STATIC_INLINE int language_is_tuple_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_tuple_typename);
}

STATIC_INLINE int language_is_namedtuple_type(void *t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_namedtuple_typename);
}

STATIC_INLINE int language_is_vecelement_type(language_value_t* t) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(t) &&
            ((language_datatype_t*)(t))->name == language_vecelement_typename);
}

STATIC_INLINE int language_is_type_type(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return (language_is_datatype(v) &&
            ((language_datatype_t*)(v))->name == ((language_datatype_t*)language_type_type->body)->name);
}

STATIC_INLINE int language_is_genericmemory_zeroinit(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT
{
    return ((language_datatype_t*)language_typeof(m))->zeroinit;
}

// object identity
LANGUAGE_DLLEXPORT int language_egal(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_egal__bits(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_egal__bitstag(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, uintptr_t dtag) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_egal__unboxed(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, uintptr_t dtag) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uintptr_t language_object_id(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uintptr_t language_type_hash(language_value_t *v) LANGUAGE_NOTSAFEPOINT;

STATIC_INLINE int language_egal__unboxed_(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, uintptr_t dtag) LANGUAGE_NOTSAFEPOINT
{
    if (dtag < language_max_tags << 4) {
        if (dtag == language_symbol_tag << 4 || dtag == language_bool_tag << 4)
            return 0;
    }
    else if (((language_datatype_t*)dtag)->name->mutabl)
        return 0;
    return language_egal__bitstag(a, b, dtag);
}

STATIC_INLINE int language_egal_(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED) LANGUAGE_NOTSAFEPOINT
{
    if (a == b)
        return 1;
    uintptr_t dtag = language_typetagof(a);
    if (dtag != language_typetagof(b))
        return 0;
    return language_egal__unboxed_(a, b, dtag);
}
#define language_egal(a, b) language_egal_((a), (b))

// type predicates and basic operations
LANGUAGE_DLLEXPORT int language_has_free_typevars(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_has_typevar(language_value_t *t, language_tvar_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_has_typevar_from_unionall(language_value_t *t, language_unionall_t *ua);
LANGUAGE_DLLEXPORT int language_subtype_env_size(language_value_t *t) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_subtype_env(language_value_t *x, language_value_t *y, language_value_t **env, int envsz);
LANGUAGE_DLLEXPORT int language_isa(language_value_t *a, language_value_t *t);
LANGUAGE_DLLEXPORT int language_types_equal(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT int language_is_not_broken_subtype(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_type_union(language_value_t **ts, size_t n);
LANGUAGE_DLLEXPORT language_value_t *language_type_intersection(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT int language_has_empty_intersection(language_value_t *x, language_value_t *y);
LANGUAGE_DLLEXPORT language_value_t *language_type_unionall(language_tvar_t *v, language_value_t *body);
LANGUAGE_DLLEXPORT const char *language_typename_str(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT const char *language_typeof_str(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_type_morespecific(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT int language_method_morespecific(language_method_t *ma, language_method_t *mb);

STATIC_INLINE int language_is_dispatch_tupletype(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return language_is_datatype(v) && ((language_datatype_t*)v)->isdispatchtuple;
}

STATIC_INLINE int language_is_concrete_type(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return language_is_datatype(v) && ((language_datatype_t*)v)->isconcretetype;
}

LANGUAGE_DLLEXPORT int language_isa_compileable_sig(language_tupletype_t *type, language_svec_t *sparams, language_method_t *definition);

// type constructors
LANGUAGE_DLLEXPORT language_typename_t *language_new_typename_in(language_sym_t *name, language_module_t *inmodule, int abstract, int mutabl);
LANGUAGE_DLLEXPORT language_tvar_t *language_new_typevar(language_sym_t *name, language_value_t *lb, language_value_t *ub);
LANGUAGE_DLLEXPORT language_value_t *language_instantiate_unionall(language_unionall_t *u, language_value_t *p);
LANGUAGE_DLLEXPORT language_value_t *language_apply_type(language_value_t *tc, language_value_t **params, size_t n);
LANGUAGE_DLLEXPORT language_value_t *language_apply_type1(language_value_t *tc, language_value_t *p1);
LANGUAGE_DLLEXPORT language_value_t *language_apply_type2(language_value_t *tc, language_value_t *p1, language_value_t *p2);
LANGUAGE_DLLEXPORT language_value_t *language_apply_type3(language_value_t *tc, language_value_t *p1, language_value_t *p2, language_value_t *p3);
LANGUAGE_DLLEXPORT language_datatype_t *language_apply_modify_type(language_value_t *dt);
LANGUAGE_DLLEXPORT language_datatype_t *language_apply_cmpswap_type(language_value_t *dt);
LANGUAGE_DLLEXPORT language_value_t *language_apply_tuple_type(language_svec_t *params, int check); // if uncertain, set check=1
LANGUAGE_DLLEXPORT language_value_t *language_apply_tuple_type_v(language_value_t **p, size_t np);
LANGUAGE_DLLEXPORT language_datatype_t *language_new_datatype(language_sym_t *name,
                                            language_module_t *module,
                                            language_datatype_t *super,
                                            language_svec_t *parameters,
                                            language_svec_t *fnames,
                                            language_svec_t *ftypes,
                                            language_svec_t *fattrs,
                                            int abstract, int mutabl,
                                            int ninitialized);
LANGUAGE_DLLEXPORT language_datatype_t *language_new_primitivetype(language_value_t *name,
                                                 language_module_t *module,
                                                 language_datatype_t *super,
                                                 language_svec_t *parameters, size_t nbits);

// constructors
LANGUAGE_DLLEXPORT language_value_t *language_new_bits(language_value_t *bt, const void *src);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_new_bits(language_value_t *dt, const char *src);
LANGUAGE_DLLEXPORT void language_atomic_store_bits(char *dst, const language_value_t *src, int nb) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_atomic_swap_bits(language_value_t *dt, char *dst, const language_value_t *src, int nb);
LANGUAGE_DLLEXPORT int language_atomic_bool_cmpswap_bits(char *dst, const language_value_t *expected, const language_value_t *src, int nb) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_atomic_cmpswap_bits(language_datatype_t *dt, language_value_t *y, char *dst, const language_value_t *expected, const language_value_t *src, int nb) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_atomic_storeonce_bits(language_datatype_t *dt, char *dst, const language_value_t *src, int nb) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_new_struct(language_datatype_t *type, ...);
LANGUAGE_DLLEXPORT language_value_t *language_new_structv(language_datatype_t *type, language_value_t **args, uint32_t na);
LANGUAGE_DLLEXPORT language_value_t *language_new_structt(language_datatype_t *type, language_value_t *tup);
LANGUAGE_DLLEXPORT language_value_t *language_new_struct_uninit(language_datatype_t *type);
LANGUAGE_DLLEXPORT language_method_instance_t *language_new_method_instance_uninit(void);
LANGUAGE_DLLEXPORT language_svec_t *language_svec(size_t n, ...) LANGUAGE_MAYBE_UNROOTED;
LANGUAGE_DLLEXPORT language_svec_t *language_svec1(void *a);
LANGUAGE_DLLEXPORT language_svec_t *language_svec2(void *a, void *b);
LANGUAGE_DLLEXPORT language_svec_t *language_alloc_svec(size_t n);
LANGUAGE_DLLEXPORT language_svec_t *language_alloc_svec_uninit(size_t n);
LANGUAGE_DLLEXPORT language_svec_t *language_svec_copy(language_svec_t *a);
LANGUAGE_DLLEXPORT language_svec_t *language_svec_fill(size_t n, language_value_t *x);
LANGUAGE_DLLEXPORT language_sym_t *language_symbol(const char *str) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_sym_t *language_symbol_lookup(const char *str) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_sym_t *language_symbol_n(const char *str, size_t len) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_sym_t *language_gensym(void);
LANGUAGE_DLLEXPORT language_sym_t *language_tagged_gensym(const char *str, size_t len);
LANGUAGE_DLLEXPORT language_sym_t *language_get_root_symbol(void);
LANGUAGE_DLLEXPORT language_value_t *language_generic_function_def(language_sym_t *name,
                                                 language_module_t *module,
                                                 _Atomic(language_value_t*) *bp,
                                                 language_binding_t *bnd);
LANGUAGE_DLLEXPORT language_method_t *language_method_def(language_svec_t *argdata, language_methtable_t *mt, language_code_info_t *f, language_module_t *module);
LANGUAGE_DLLEXPORT language_code_info_t *language_code_for_staged(language_method_instance_t *linfo, size_t world, language_code_instance_t **cache);
LANGUAGE_DLLEXPORT language_code_info_t *language_copy_code_info(language_code_info_t *src);
LANGUAGE_DLLEXPORT size_t language_get_world_counter(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_box_bool(int8_t x) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_box_int8(int8_t x) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_box_uint8(uint8_t x) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_box_int16(int16_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_uint16(uint16_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_int32(int32_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_uint32(uint32_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_char(uint32_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_int64(int64_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_uint64(uint64_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_float32(float x);
LANGUAGE_DLLEXPORT language_value_t *language_box_float64(double x);
LANGUAGE_DLLEXPORT language_value_t *language_box_voidpointer(void *x);
LANGUAGE_DLLEXPORT language_value_t *language_box_uint8pointer(uint8_t *x);
LANGUAGE_DLLEXPORT language_value_t *language_box_ssavalue(size_t x);
LANGUAGE_DLLEXPORT language_value_t *language_box_slotnumber(size_t x);
LANGUAGE_DLLEXPORT int8_t language_unbox_bool(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int8_t language_unbox_int8(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint8_t language_unbox_uint8(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int16_t language_unbox_int16(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint16_t language_unbox_uint16(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int32_t language_unbox_int32(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint32_t language_unbox_uint32(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int64_t language_unbox_int64(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint64_t language_unbox_uint64(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT float language_unbox_float32(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT double language_unbox_float64(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void *language_unbox_voidpointer(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint8_t *language_unbox_uint8pointer(language_value_t *v) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT int language_get_size(language_value_t *val, size_t *pnt);

#ifdef _P64
#define language_box_long(x)   language_box_int64(x)
#define language_box_ulong(x)  language_box_uint64(x)
#define language_unbox_long(x) language_unbox_int64(x)
#define language_unbox_ulong(x) language_unbox_uint64(x)
#define language_is_long(x)    language_is_int64(x)
#define language_is_ulong(x)   language_is_uint64(x)
#define language_long_type     language_int64_type
#define language_ulong_type    language_uint64_type
#else
#define language_box_long(x)   language_box_int32(x)
#define language_box_ulong(x)  language_box_uint32(x)
#define language_unbox_long(x) language_unbox_int32(x)
#define language_unbox_ulong(x) language_unbox_uint32(x)
#define language_is_long(x)    language_is_int32(x)
#define language_is_ulong(x)   language_is_uint32(x)
#define language_long_type     language_int32_type
#define language_ulong_type    language_uint32_type
#endif

// structs
LANGUAGE_DLLEXPORT int         language_field_index(language_datatype_t *t, language_sym_t *fld, int err);
LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field(language_value_t *v, size_t i);
// Like language_get_nth_field above, but asserts if it needs to allocate
LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field_noalloc(language_value_t *v LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field_checked(language_value_t *v, size_t i);
LANGUAGE_DLLEXPORT void        language_set_nth_field(language_value_t *v, size_t i, language_value_t *rhs);
LANGUAGE_DLLEXPORT int         language_field_isdefined(language_value_t *v, size_t i) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int         language_field_isdefined_checked(language_value_t *v, size_t i);
LANGUAGE_DLLEXPORT language_value_t *language_get_field(language_value_t *o, const char *fld);
LANGUAGE_DLLEXPORT language_value_t *language_value_ptr(language_value_t *a);
int language_uniontype_size(language_value_t *ty, size_t *sz);
LANGUAGE_DLLEXPORT int language_islayout_inline(language_value_t *eltype, size_t *fsz, size_t *al);

// arrays
LANGUAGE_DLLEXPORT language_array_t *language_ptr_to_array_1d(language_value_t *atype, void *data,
                                            size_t nel, int own_buffer);
LANGUAGE_DLLEXPORT language_array_t *language_ptr_to_array(language_value_t *atype, void *data,
                                         language_value_t *dims, int own_buffer);

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_1d(language_value_t *atype, size_t nr);
LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_2d(language_value_t *atype, size_t nr, size_t nc);
LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_3d(language_value_t *atype, size_t nr, size_t nc, size_t z);
LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_nd(language_value_t *atype, size_t *dims, size_t ndims);
LANGUAGE_DLLEXPORT language_array_t *language_pchar_to_array(const char *str, size_t len);
LANGUAGE_DLLEXPORT language_value_t *language_pchar_to_string(const char *str, size_t len);
LANGUAGE_DLLEXPORT language_value_t *language_cstr_to_string(const char *str);
LANGUAGE_DLLEXPORT language_value_t *language_alloc_string(size_t len);
LANGUAGE_DLLEXPORT language_value_t *language_array_to_string(language_array_t *a);
LANGUAGE_DLLEXPORT language_array_t *language_alloc_vec_any(size_t n);
LANGUAGE_DLLEXPORT void language_array_grow_end(language_array_t *a, size_t inc);
LANGUAGE_DLLEXPORT void language_array_del_end(language_array_t *a, size_t dec);
LANGUAGE_DLLEXPORT void language_array_ptr_1d_push(language_array_t *a, language_value_t *item);
LANGUAGE_DLLEXPORT void language_array_ptr_1d_append(language_array_t *a, language_array_t *a2);
LANGUAGE_DLLEXPORT language_value_t *language_apply_array_type(language_value_t *type, size_t dim);
// property access
LANGUAGE_DLLEXPORT void *language_array_ptr(language_array_t *a);
LANGUAGE_DLLEXPORT void *language_array_eltype(language_value_t *a);
LANGUAGE_DLLEXPORT int language_array_rank(language_value_t *a);

// genericmemory
LANGUAGE_DLLEXPORT language_genericmemory_t *language_new_genericmemory(language_value_t *mtype, language_value_t *dim);
LANGUAGE_DLLEXPORT language_genericmemory_t *language_ptr_to_genericmemory(language_value_t *mtype, void *data,
                                           size_t nel, int own_buffer);
LANGUAGE_DLLEXPORT language_genericmemory_t *language_alloc_genericmemory(language_value_t *mtype, size_t nel);
LANGUAGE_DLLEXPORT language_genericmemory_t *language_pchar_to_memory(const char *str, size_t len);
LANGUAGE_DLLEXPORT language_value_t *language_genericmemory_to_string(language_genericmemory_t *m, size_t len);
LANGUAGE_DLLEXPORT language_genericmemory_t *language_alloc_memory_any(size_t n);
LANGUAGE_DLLEXPORT language_value_t *language_genericmemoryref(language_genericmemory_t *m, size_t i);  // 0-indexed

LANGUAGE_DLLEXPORT language_genericmemoryref_t *language_new_memoryref(language_value_t *typ, language_genericmemory_t *mem, void *data);
LANGUAGE_DLLEXPORT language_value_t *language_memoryrefget(language_genericmemoryref_t m LANGUAGE_PROPAGATES_ROOT, int isatomic);
LANGUAGE_DLLEXPORT language_value_t *language_ptrmemoryrefget(language_genericmemoryref_t m LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_memoryref_isassigned(language_genericmemoryref_t m, int isatomic) LANGUAGE_GLOBALLY_ROOTED;
LANGUAGE_DLLEXPORT language_genericmemoryref_t language_memoryrefindex(language_genericmemoryref_t m LANGUAGE_PROPAGATES_ROOT, size_t idx) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_memoryrefset(language_genericmemoryref_t m LANGUAGE_ROOTING_ARGUMENT, language_value_t *v LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED, int isatomic);
LANGUAGE_DLLEXPORT language_value_t *language_memoryrefswap(language_genericmemoryref_t m, language_value_t *v, int isatomic);
LANGUAGE_DLLEXPORT language_value_t *language_memoryrefmodify(language_genericmemoryref_t m, language_value_t *op, language_value_t *v, int isatomic);
LANGUAGE_DLLEXPORT language_value_t *language_memoryrefreplace(language_genericmemoryref_t m, language_value_t *expected, language_value_t *v, int isatomic);
LANGUAGE_DLLEXPORT language_value_t *language_memoryrefsetonce(language_genericmemoryref_t m, language_value_t *v, int isatomic);

// strings
LANGUAGE_DLLEXPORT const char *language_string_ptr(language_value_t *s);

// modules and global variables
extern LANGUAGE_DLLIMPORT language_module_t *language_main_module LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_module_t *language_core_module LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_module_t *language_base_module LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_module_t *language_top_module LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_module_t *language_libdl_module LANGUAGE_GLOBALLY_ROOTED;
LANGUAGE_DLLEXPORT language_module_t *language_new_module(language_sym_t *name, language_module_t *parent);
LANGUAGE_DLLEXPORT void language_set_module_nospecialize(language_module_t *self, int on);
LANGUAGE_DLLEXPORT void language_set_module_optlevel(language_module_t *self, int lvl);
LANGUAGE_DLLEXPORT int language_get_module_optlevel(language_module_t *m);
LANGUAGE_DLLEXPORT void language_set_module_compile(language_module_t *self, int value);
LANGUAGE_DLLEXPORT int language_get_module_compile(language_module_t *m);
LANGUAGE_DLLEXPORT void language_set_module_infer(language_module_t *self, int value);
LANGUAGE_DLLEXPORT int language_get_module_infer(language_module_t *m);
LANGUAGE_DLLEXPORT void language_set_module_max_methods(language_module_t *self, int value);
LANGUAGE_DLLEXPORT int language_get_module_max_methods(language_module_t *m);
// get binding for reading
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var);
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_or_error(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT language_value_t *language_module_globalref(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT language_value_t *language_get_binding_type(language_module_t *m, language_sym_t *var);
// get binding for assignment
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_wr(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var);
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_for_method_def(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var);
LANGUAGE_DLLEXPORT int language_boundp(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT int language_defines_or_exports_p(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT int language_binding_resolved_p(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT int language_is_const(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT int language_globalref_is_const(language_globalref_t *gr);
LANGUAGE_DLLEXPORT int language_globalref_boundp(language_globalref_t *gr);
LANGUAGE_DLLEXPORT language_value_t *language_get_globalref_value(language_globalref_t *gr);
LANGUAGE_DLLEXPORT language_value_t *language_get_global(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var);
LANGUAGE_DLLEXPORT void language_set_global(language_module_t *m LANGUAGE_ROOTING_ARGUMENT, language_sym_t *var, language_value_t *val LANGUAGE_ROOTED_ARGUMENT);
LANGUAGE_DLLEXPORT void language_set_const(language_module_t *m LANGUAGE_ROOTING_ARGUMENT, language_sym_t *var, language_value_t *val LANGUAGE_ROOTED_ARGUMENT);
LANGUAGE_DLLEXPORT void language_checked_assignment(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_value_t *language_checked_swap(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_value_t *language_checked_replace(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *expected, language_value_t *rhs);
LANGUAGE_DLLEXPORT language_value_t *language_checked_modify(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *op, language_value_t *rhs);
LANGUAGE_DLLEXPORT language_value_t *language_checked_assignonce(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void language_declare_constant(language_binding_t *b, language_module_t *mod, language_sym_t *var);
LANGUAGE_DLLEXPORT void language_module_using(language_module_t *to, language_module_t *from);
LANGUAGE_DLLEXPORT void language_module_use(language_module_t *to, language_module_t *from, language_sym_t *s);
LANGUAGE_DLLEXPORT void language_module_use_as(language_module_t *to, language_module_t *from, language_sym_t *s, language_sym_t *asname);
LANGUAGE_DLLEXPORT void language_module_import(language_module_t *to, language_module_t *from, language_sym_t *s);
LANGUAGE_DLLEXPORT void language_module_import_as(language_module_t *to, language_module_t *from, language_sym_t *s, language_sym_t *asname);
LANGUAGE_DLLEXPORT void language_module_public(language_module_t *from, language_sym_t *s, int exported);
LANGUAGE_DLLEXPORT int language_is_imported(language_module_t *m, language_sym_t *s);
LANGUAGE_DLLEXPORT int language_module_exports_p(language_module_t *m, language_sym_t *var);
LANGUAGE_DLLEXPORT void language_add_standard_imports(language_module_t *m);
STATIC_INLINE language_function_t *language_get_function(language_module_t *m, const char *name)
{
    return (language_function_t*)language_get_global(m, language_symbol(name));
}

// eq hash tables
LANGUAGE_DLLEXPORT language_genericmemory_t *language_eqtable_put(language_genericmemory_t *h LANGUAGE_ROOTING_ARGUMENT, language_value_t *key, language_value_t *val LANGUAGE_ROOTED_ARGUMENT, int *inserted);
LANGUAGE_DLLEXPORT language_value_t *language_eqtable_get(language_genericmemory_t *h LANGUAGE_PROPAGATES_ROOT, language_value_t *key, language_value_t *deflt) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_eqtable_pop(language_genericmemory_t *h, language_value_t *key, language_value_t *deflt, int *found);
language_value_t *language_eqtable_getkey(language_genericmemory_t *h LANGUAGE_PROPAGATES_ROOT, language_value_t *key, language_value_t *deflt) LANGUAGE_NOTSAFEPOINT;

// system information
LANGUAGE_DLLEXPORT int language_errno(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_set_errno(int e) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int32_t language_stat(const char *path, char *statbuf) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_cpu_threads(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_effective_threads(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT long language_getpagesize(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT long language_getallocationgranularity(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_is_debugbuild(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_sym_t *language_get_UNAME(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_sym_t *language_get_ARCH(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLIMPORT language_value_t *language_get_libllvm(void) LANGUAGE_NOTSAFEPOINT;
extern LANGUAGE_DLLIMPORT int language_n_threadpools;
extern LANGUAGE_DLLIMPORT _Atomic(int) language_n_threads;
extern LANGUAGE_DLLIMPORT int language_n_gcthreads;
extern int language_n_markthreads;
extern int language_n_sweepthreads;
extern LANGUAGE_DLLIMPORT int *language_n_threads_per_pool;

// environment entries
LANGUAGE_DLLEXPORT language_value_t *language_environ(int i);

// throwing common exceptions
LANGUAGE_DLLEXPORT language_value_t *language_vexceptionf(language_datatype_t *exception_type,
                                        const char *fmt, va_list args);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_error(const char *str);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_errorf(const char *fmt, ...);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_exceptionf(language_datatype_t *ty,
                                            const char *fmt, ...);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_too_few_args(const char *fname, int min);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_too_many_args(const char *fname, int max);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_type_error(const char *fname,
                                            language_value_t *expected LANGUAGE_MAYBE_UNROOTED,
                                            language_value_t *got LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_type_error_rt(const char *fname,
                                               const char *context,
                                               language_value_t *ty LANGUAGE_MAYBE_UNROOTED,
                                               language_value_t *got LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_undefined_var_error(language_sym_t *var, language_value_t *scope LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_has_no_field_error(language_sym_t *type_name, language_sym_t *var);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_atomic_error(char *str);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error(language_value_t *v LANGUAGE_MAYBE_UNROOTED,
                                              language_value_t *t LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_v(language_value_t *v LANGUAGE_MAYBE_UNROOTED,
                                                language_value_t **idxs, size_t nidxs);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_int(language_value_t *v LANGUAGE_MAYBE_UNROOTED,
                                                  size_t i);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_tuple_int(language_value_t **v,
                                                        size_t nv, size_t i);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_unboxed_int(void *v, language_value_t *vt, size_t i);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_ints(language_value_t *v LANGUAGE_MAYBE_UNROOTED,
                                                   size_t *idxs, size_t nidxs);

#define LANGUAGE_NARGS(fname, min, max)                               \
    if (nargs < min) language_too_few_args(#fname, min);              \
    else if (nargs > max) language_too_many_args(#fname, max);

#define LANGUAGE_NARGSV(fname, min)                           \
    if (nargs < min) language_too_few_args(#fname, min);

#define LANGUAGE_TYPECHK(fname, type, v)                                 \
    if (!language_is_##type(v)) {                                        \
        language_type_error(#fname, (language_value_t*)code_##type##_type, (v)); \
    }
#define LANGUAGE_TYPECHKS(fname, type, v)                                     \
    if (!language_is_##type(v)) {                                             \
        language_type_error(fname, (language_value_t*)code_##type##_type, (v));       \
    }

// initialization functions
typedef enum {
    LANGUAGE_IMAGE_CWD = 0,
    LANGUAGE_IMAGE_JULIA_HOME = 1,
    LANGUAGE_IMAGE_IN_MEMORY = 2
} LANGUAGE_IMAGE_SEARCH;

LANGUAGE_DLLIMPORT const char *language_get_libdir(void);
LANGUAGE_DLLEXPORT void language_init(LANGUAGE_IMAGE_SEARCH rel);
LANGUAGE_DLLEXPORT void language_init(void);
LANGUAGE_DLLEXPORT void language_init_with_image(const char *language_bindir,
                                     const char *image_path);
LANGUAGE_DLLEXPORT const char *language_get_default_sysimg_path(void);
LANGUAGE_DLLEXPORT int language_is_initialized(void);
LANGUAGE_DLLEXPORT void language_atexit_hook(int status);
LANGUAGE_DLLEXPORT void language_task_wait_empty(void);
LANGUAGE_DLLEXPORT void language_postoutput_hook(void);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_exit(int status);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_raise(int signo);
LANGUAGE_DLLEXPORT const char *language_pathname_for_handle(void *handle);
LANGUAGE_DLLEXPORT language_gcframe_t **language_adopt_thread(void);

LANGUAGE_DLLEXPORT int language_deserialize_verify_header(ios_t *s);
LANGUAGE_DLLEXPORT void language_preload_sysimg_so(const char *fname);
LANGUAGE_DLLEXPORT void language_set_sysimg_so(void *handle);
LANGUAGE_DLLEXPORT void language_create_system_image(void **, language_array_t *worklist, bool_t emit_split, ios_t **s, ios_t **z, language_array_t **udeps, int64_t *srctextpos);
LANGUAGE_DLLEXPORT void language_restore_system_image(const char *fname);
LANGUAGE_DLLEXPORT void language_restore_system_image_data(const char *buf, size_t len);
LANGUAGE_DLLEXPORT language_value_t *language_restore_incremental(const char *fname, language_array_t *depmods, int complete, const char *pkgimage);
LANGUAGE_DLLEXPORT language_value_t *language_object_top_module(language_value_t* v) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_set_newly_inferred(language_value_t *newly_inferred);
LANGUAGE_DLLEXPORT void language_push_newly_inferred(language_value_t *ci);
LANGUAGE_DLLEXPORT void language_write_compiler_output(void);

// parsing
LANGUAGE_DLLEXPORT language_value_t *language_parse_all(const char *text, size_t text_len,
                                      const char *filename, size_t filename_len, size_t lineno);
LANGUAGE_DLLEXPORT language_value_t *language_parse_string(const char *text, size_t text_len,
                                         int offset, int greedy);
// lowering
LANGUAGE_DLLEXPORT language_value_t *language_expand(language_value_t *expr, language_module_t *inmodule);
LANGUAGE_DLLEXPORT language_value_t *language_expand_with_loc(language_value_t *expr, language_module_t *inmodule,
                                            const char *file, int line);
LANGUAGE_DLLEXPORT language_value_t *language_expand_with_loc_warn(language_value_t *expr, language_module_t *inmodule,
                                                 const char *file, int line);
LANGUAGE_DLLEXPORT language_value_t *language_expand_in_world(language_value_t *expr, language_module_t *inmodule,
                                            const char *file, int line, size_t world);
LANGUAGE_DLLEXPORT language_value_t *language_expand_stmt(language_value_t *expr, language_module_t *inmodule);
LANGUAGE_DLLEXPORT language_value_t *language_expand_stmt_with_loc(language_value_t *expr, language_module_t *inmodule,
                                                 const char *file, int line);
// deprecated; use language_parse_all
LANGUAGE_DLLEXPORT language_value_t *language_parse_input_line(const char *text, size_t text_len,
                                             const char *filename, size_t filename_len);

// external libraries
enum LANGUAGE_RTLD_CONSTANT {
     LANGUAGE_RTLD_LOCAL=1U,
     LANGUAGE_RTLD_GLOBAL=2U,
     LANGUAGE_RTLD_LAZY=4U,
     LANGUAGE_RTLD_NOW=8U,
     /* Linux/glibc and MacOS X: */
     LANGUAGE_RTLD_NODELETE=16U,
     LANGUAGE_RTLD_NOLOAD=32U,
     /* Linux/glibc: */
     LANGUAGE_RTLD_DEEPBIND=64U,
     /* MacOS X 10.5+: */
     LANGUAGE_RTLD_FIRST=128U
};
#define LANGUAGE_RTLD_DEFAULT (LANGUAGE_RTLD_LAZY | LANGUAGE_RTLD_DEEPBIND)

typedef void *language_libhandle; // compatible with dlopen (void*) / LoadLibrary (HMODULE)
LANGUAGE_DLLEXPORT language_libhandle language_load_dynamic_library(const char *fname, unsigned flags, int throw_err);
LANGUAGE_DLLEXPORT language_libhandle language_dlopen(const char *filename, unsigned flags) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_dlclose(language_libhandle handle) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_dlsym(language_libhandle handle, const char *symbol, void ** value, int throw_err) LANGUAGE_NOTSAFEPOINT;

// evaluation
LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval(language_module_t *m, language_value_t *v);
LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval_in(language_module_t *m, language_value_t *ex);
// code loading (parsing + evaluation)
LANGUAGE_DLLEXPORT language_value_t *language_eval_string(const char *str); // embedding interface
LANGUAGE_DLLEXPORT language_value_t *language_load_file_string(const char *text, size_t len,
                                             char *filename, language_module_t *module);
LANGUAGE_DLLEXPORT language_value_t *language_load(language_module_t *module, const char *fname);

LANGUAGE_DLLEXPORT language_module_t *language_base_relative_to(language_module_t *m LANGUAGE_PROPAGATES_ROOT);

// tracing
LANGUAGE_DLLEXPORT void language_register_newmeth_tracer(void (*callback)(language_method_t *tracee));

// AST access
LANGUAGE_DLLEXPORT language_value_t *language_copy_ast(language_value_t *expr LANGUAGE_MAYBE_UNROOTED);

// IR representation
LANGUAGE_DLLEXPORT language_value_t *language_compress_ir(language_method_t *m, language_code_info_t *code);
LANGUAGE_DLLEXPORT language_code_info_t *language_uncompress_ir(language_method_t *m, language_code_instance_t *metadata, language_value_t *data);
LANGUAGE_DLLEXPORT uint8_t language_ir_flag_inlining(language_value_t *data) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint8_t language_ir_flag_has_fcall(language_value_t *data) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint16_t language_ir_inlining_cost(language_value_t *data) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT ssize_t language_ir_nslots(language_value_t *data) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT uint8_t language_ir_slotflag(language_value_t *data, size_t i) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_compress_argnames(language_array_t *syms);
LANGUAGE_DLLEXPORT language_array_t *language_uncompress_argnames(language_value_t *syms);
LANGUAGE_DLLEXPORT language_value_t *language_uncompress_argname_n(language_value_t *syms, size_t i);
LANGUAGE_DLLEXPORT struct language_codeloc_t language_uncompress1_codeloc(language_value_t *cl, size_t pc) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_compress_codelocs(int32_t firstline, language_value_t *codelocs, size_t nstmts);
LANGUAGE_DLLEXPORT language_value_t *language_uncompress_codelocs(language_value_t *cl, size_t nstmts);

LANGUAGE_DLLEXPORT int language_is_operator(const char *sym);
LANGUAGE_DLLEXPORT int language_is_unary_operator(const char *sym);
LANGUAGE_DLLEXPORT int language_is_unary_and_binary_operator(const char *sym);
LANGUAGE_DLLEXPORT int language_is_syntactic_operator(const char *sym);
LANGUAGE_DLLEXPORT int language_operator_precedence(const char *sym);

STATIC_INLINE int language_vinfo_sa(uint8_t vi)
{
    return (vi&16)!=0;
}

STATIC_INLINE int language_vinfo_usedundef(uint8_t vi)
{
    return (vi&32)!=0;
}

// calling into julia ---------------------------------------------------------

LANGUAGE_DLLEXPORT language_value_t *language_apply_generic(language_value_t *F, language_value_t **args, uint32_t nargs);
LANGUAGE_DLLEXPORT language_value_t *language_invoke(language_value_t *F, language_value_t **args, uint32_t nargs, language_method_instance_t *meth);
LANGUAGE_DLLEXPORT int32_t language_invoke_api(language_code_instance_t *linfo);

STATIC_INLINE language_value_t *language_apply(language_value_t **args, uint32_t nargs)
{
    return language_apply_generic(args[0], &args[1], nargs - 1);
}

LANGUAGE_DLLEXPORT language_value_t *language_call(language_function_t *f LANGUAGE_MAYBE_UNROOTED, language_value_t **args, uint32_t nargs);
LANGUAGE_DLLEXPORT language_value_t *language_call0(language_function_t *f LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_value_t *language_call1(language_function_t *f LANGUAGE_MAYBE_UNROOTED, language_value_t *a LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_value_t *language_call2(language_function_t *f LANGUAGE_MAYBE_UNROOTED, language_value_t *a LANGUAGE_MAYBE_UNROOTED, language_value_t *b LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_value_t *language_call3(language_function_t *f LANGUAGE_MAYBE_UNROOTED, language_value_t *a LANGUAGE_MAYBE_UNROOTED,
                                  language_value_t *b LANGUAGE_MAYBE_UNROOTED, language_value_t *c LANGUAGE_MAYBE_UNROOTED);

// async signal handling ------------------------------------------------------

LANGUAGE_DLLEXPORT void language_install_sigint_handler(void);
LANGUAGE_DLLEXPORT void language_sigatomic_begin(void);
LANGUAGE_DLLEXPORT void language_sigatomic_end(void);

// tasks and exceptions -------------------------------------------------------

typedef struct _language_timing_block_t language_timing_block_t;
typedef struct _language_timing_event_t language_timing_event_t;
typedef struct _language_excstack_t language_excstack_t;

// info describing an exception handler
typedef struct _language_handler_t {
    language_jmp_buf eh_ctx;
    language_gcframe_t *gcstack;
    struct _language_handler_t *prev;
    int8_t gc_state;
    size_t locks_len;
    sig_atomic_t defer_signal;
    language_timing_block_t *timing_stack;
    size_t world_age;
} language_handler_t;

#define LANGUAGE_RNG_SIZE 5 // xoshiro 4 + splitmix 1

typedef struct _language_task_t {
    LANGUAGE_DATA_TYPE
    language_value_t *next; // invasive linked list for scheduler
    language_value_t *queue; // invasive linked list for scheduler
    language_value_t *tls;
    language_value_t *donenotify;
    language_value_t *result;
    language_value_t *scope;
    language_function_t *start;
    // 4 byte padding on 32-bit systems
    // uint32_t padding0;
    uint64_t rngState[LANGUAGE_RNG_SIZE];
    _Atomic(uint8_t) _state;
    uint8_t sticky; // record whether this Task can be migrated to a new thread
    _Atomic(uint8_t) _isexception; // set if `result` is an exception to throw or that we exited with
    // 1 byte padding
    // uint8_t padding1;
    // multiqueue priority
    uint16_t priority;

// hidden state:

    // id of owning thread - does not need to be defined until the task runs
    _Atomic(int16_t) tid;
    // threadpool id
    int8_t threadpoolid;
    // Reentrancy bits
    // Bit 0: 1 if we are currently running inference/codegen
    // Bit 1-2: 0-3 counter of how many times we've reentered inference
    // Bit 3: 1 if we are writing the image and inference is illegal
    uint8_t reentrant_timing;
    // 2 bytes of padding on 32-bit, 6 bytes on 64-bit
    // uint16_t padding2_32;
    // uint48_t padding2_64;
    // saved gc stack top for context switches
    language_gcframe_t *gcstack;
    size_t world_age;
    // quick lookup for current ptls
    language_ptls_t ptls; // == language_all_tls_states[tid]
#ifdef USE_TRACY
    const char *name;
#endif
    // saved exception stack
    language_excstack_t *excstack;
    // current exception handler
    language_handler_t *eh;
    // saved thread state
    language_ucontext_t ctx;
    void *stkbuf; // malloc'd memory (either copybuf or stack)
    size_t bufsz; // actual sizeof stkbuf
    unsigned int copy_stack:31; // sizeof stack for copybuf
    unsigned int started:1;
} language_task_t;

#define LANGUAGE_TASK_STATE_RUNNABLE 0
#define LANGUAGE_TASK_STATE_DONE     1
#define LANGUAGE_TASK_STATE_FAILED   2

LANGUAGE_DLLEXPORT language_task_t *language_new_task(language_function_t*, language_value_t*, size_t);
LANGUAGE_DLLEXPORT void language_switchto(language_task_t **pt);
LANGUAGE_DLLEXPORT int language_set_task_tid(language_task_t *task, int16_t tid) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_set_task_threadpoolid(language_task_t *task, int8_t tpid) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_throw(language_value_t *e LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_rethrow(void);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_sig_throw(void);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_rethrow_other(language_value_t *e LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_no_exc_handler(language_value_t *e, language_task_t *ct);
LANGUAGE_DLLEXPORT LANGUAGE_CONST_FUNC language_gcframe_t **(language_get_pgcstack)(void) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;
#define language_current_task (container_of(language_get_pgcstack(), language_task_t, gcstack))

extern LANGUAGE_DLLIMPORT int language_task_gcstack_offset;
extern LANGUAGE_DLLIMPORT int language_task_ptls_offset;

#include "language_locks.h"   // requires language_task_t definition

// Return the exception currently being handled, or `language_nothing`.
//
// The catch scope is determined dynamically so this works in functions called
// from a catch block.  The returned value is gc rooted until we exit the
// enclosing LANGUAGE_CATCH.
// FIXME: Teach the static analyzer about this rather than using
// LANGUAGE_GLOBALLY_ROOTED which is far too optimistic.
LANGUAGE_DLLEXPORT language_value_t *language_current_exception(language_task_t *ct) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_exception_occurred(void);
LANGUAGE_DLLEXPORT void language_exception_clear(void) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_enter_handler(language_task_t *ct, language_handler_t *eh) LANGUAGE_NOTSAFEPOINT ;
LANGUAGE_DLLEXPORT void language_eh_restore_state(language_task_t *ct, language_handler_t *eh);
LANGUAGE_DLLEXPORT void language_eh_restore_state_noexcept(language_task_t *ct, language_handler_t *eh) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_pop_handler(language_task_t *ct, int n) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_pop_handler_noexcept(language_task_t *ct, int n) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT size_t language_excstack_state(language_task_t *ct) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_restore_excstack(language_task_t *ct, size_t state) LANGUAGE_NOTSAFEPOINT;

#if defined(_OS_WINDOWS_)
#if defined(_COMPILER_GCC_)
LANGUAGE_DLLEXPORT int __attribute__ ((__nothrow__,__returns_twice__)) (language_setjmp)(jmp_buf _Buf);
__declspec(noreturn) __attribute__ ((__nothrow__)) void (language_longjmp)(jmp_buf _Buf, int _Value);
LANGUAGE_DLLEXPORT int __attribute__ ((__nothrow__,__returns_twice__)) (ilanguage_setjmp)(jmp_buf _Buf);
__declspec(noreturn) __attribute__ ((__nothrow__)) void (ilanguage_longjmp)(jmp_buf _Buf, int _Value);
#else
LANGUAGE_DLLEXPORT int (language_setjmp)(jmp_buf _Buf);
void (language_longjmp)(jmp_buf _Buf, int _Value);
LANGUAGE_DLLEXPORT int (ilanguage_setjmp)(jmp_buf _Buf);
void (ilanguage_longjmp)(jmp_buf _Buf, int _Value);
#endif
#ifdef LANGUAGE_LIBRARY_EXPORTS
#define language_setjmp_f ilanguage_setjmp
#define language_setjmp_name "ilanguage_setjmp"
#define language_setjmp(a,b) ilanguage_setjmp(a)
#define language_longjmp(a,b) ilanguage_longjmp(a,b)
#else
#define language_setjmp_f language_setjmp
#define language_setjmp_name "language_setjmp"
#define language_setjmp(a,b) language_setjmp(a)
#define language_longjmp(a,b) language_longjmp(a,b)
#endif
#elif defined(_OS_EMSCRIPTEN_)
#define language_setjmp(a,b) setjmp(a)
#define language_longjmp(a,b) longjmp(a,b)
#define language_setjmp_f    setjmp
#define language_setjmp_name "setjmp"
#else
// determine actual entry point name
#if defined(sigsetjmp)
#define language_setjmp_f    __sigsetjmp
#define language_setjmp_name "__sigsetjmp"
#else
#define language_setjmp_f    sigsetjmp
#define language_setjmp_name "sigsetjmp"
#endif
#define language_setjmp(a,b) sigsetjmp(a,b)
#if defined(_COMPILER_ASAN_ENABLED_) && defined(__GLIBC__)
extern void (*real_siglongjmp)(jmp_buf _Buf, int _Value);
#define language_longjmp(a,b) real_siglongjmp(a,b)
#else
#define language_longjmp(a,b) siglongjmp(a,b)
#endif
#endif


#ifdef __clang_gcanalyzer__

extern int had_exception;

// The analyzer assumes that the TRY block always executes to completion.
// This can lead to both false positives and false negatives, since it doesn't model the fact that throwing always leaves the try block early.
#define LANGUAGE_TRY                                                      \
    int i__try, i__catch; language_handler_t __eh; language_task_t *__eh_ct;    \
    __eh_ct = language_current_task;                                      \
    size_t __excstack_state = language_excstack_state(__eh_ct);           \
    language_enter_handler(__eh_ct, &__eh);                               \
    if (1)
    /* TRY BLOCK; */
#define LANGUAGE_CATCH                                                    \
    if (!had_exception)                                             \
        language_eh_restore_state_noexcept(__eh_ct, &__eh);               \
    else                                                            \
        for (i__catch=1, language_eh_restore_state(__eh_ct, &__eh); i__catch; i__catch=0, /* CATCH BLOCK; */ language_restore_excstack(__eh_ct, __excstack_state))

#else

#define LANGUAGE_TRY                                                      \
    int i__try, i__catch; language_handler_t __eh; language_task_t *__eh_ct;    \
    __eh_ct = language_current_task;                                      \
    size_t __excstack_state = language_excstack_state(__eh_ct);           \
    language_enter_handler(__eh_ct, &__eh);                               \
    if (!language_setjmp(__eh.eh_ctx, 0))                                 \
        for (i__try=1; i__try; i__try=0, /* TRY BLOCK; */  language_eh_restore_state_noexcept(__eh_ct, &__eh))

#define LANGUAGE_CATCH                                                    \
    else                                                            \
        for (i__catch=1, language_eh_restore_state(__eh_ct, &__eh); i__catch; i__catch=0, /* CATCH BLOCK; */ language_restore_excstack(__eh_ct, __excstack_state))

#endif

// I/O system -----------------------------------------------------------------

struct uv_loop_s;
struct uv_handle_s;
struct uv_stream_s;
#ifdef _OS_WINDOWS_
typedef HANDLE language_uv_os_fd_t;
#else
typedef int language_uv_os_fd_t;
#endif
#define LANGUAGE_STREAM struct uv_stream_s
#define LANGUAGE_STDOUT language_uv_stdout
#define LANGUAGE_STDERR language_uv_stderr
#define LANGUAGE_STDIN  language_uv_stdin

LANGUAGE_DLLEXPORT int language_process_events(void);

LANGUAGE_DLLEXPORT struct uv_loop_s *language_global_event_loop(void) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_close_uv(struct uv_handle_s *handle);

LANGUAGE_DLLEXPORT language_array_t *language_take_buffer(ios_t *s);

typedef struct {
    void *data;
    struct uv_loop_s *loop;
    int type; // enum uv_handle_type
    language_uv_os_fd_t file;
} language_uv_file_t;

#ifdef __GNUC__
#define _LANGUAGE_FORMAT_ATTR(type, str, arg) \
    __attribute__((format(type, str, arg)))
#else
#define _LANGUAGE_FORMAT_ATTR(type, str, arg)
#endif

LANGUAGE_DLLEXPORT void language_uv_puts(struct uv_stream_s *stream, const char *str, size_t n);
LANGUAGE_DLLEXPORT int language_printf(struct uv_stream_s *s, const char *format, ...)
    _LANGUAGE_FORMAT_ATTR(printf, 2, 3);
LANGUAGE_DLLEXPORT int language_vprintf(struct uv_stream_s *s, const char *format, va_list args)
    _LANGUAGE_FORMAT_ATTR(printf, 2, 0);
LANGUAGE_DLLEXPORT void language_safe_printf(const char *str, ...) LANGUAGE_NOTSAFEPOINT
    _LANGUAGE_FORMAT_ATTR(printf, 1, 2);

extern LANGUAGE_DLLEXPORT LANGUAGE_STREAM *LANGUAGE_STDIN;
extern LANGUAGE_DLLEXPORT LANGUAGE_STREAM *LANGUAGE_STDOUT;
extern LANGUAGE_DLLEXPORT LANGUAGE_STREAM *LANGUAGE_STDERR;

LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stdout_stream(void);
LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stdin_stream(void);
LANGUAGE_DLLEXPORT LANGUAGE_STREAM *language_stderr_stream(void);
LANGUAGE_DLLEXPORT int language_termios_size(void);

// showing and std streams
LANGUAGE_DLLEXPORT void language_flush_cstdio(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_stderr_obj(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT size_t language_static_show(LANGUAGE_STREAM *out, language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT size_t language_static_show_func_sig(LANGUAGE_STREAM *s, language_value_t *type) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_print_backtrace(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void jlbacktrace(void) LANGUAGE_NOTSAFEPOINT; // deprecated
// Mainly for debugging, use `void*` so that no type cast is needed in C++.
LANGUAGE_DLLEXPORT void code_(void *language_value) LANGUAGE_NOTSAFEPOINT;

// julia options -----------------------------------------------------------

#include "options.h"

extern LANGUAGE_DLLIMPORT language_options_t language_options;

LANGUAGE_DLLEXPORT ssize_t language_sizeof_language_options(void);

// Parse an argc/argv pair to extract general julia options, passing back out
// any arguments that should be passed on to the script.
LANGUAGE_DLLEXPORT void language_parse_opts(int *argcp, char ***argvp);
LANGUAGE_DLLEXPORT char *language_format_filename(const char *output_pattern);

// Set julia-level ARGS array according to the arguments provided in
// argc/argv
LANGUAGE_DLLEXPORT void language_set_ARGS(int argc, char **argv);

LANGUAGE_DLLEXPORT int language_generating_output(void) LANGUAGE_NOTSAFEPOINT;

// Settings for code_coverage and malloc_log
// NOTE: if these numbers change, test/cmdlineargs.jl will have to be updated
#define LANGUAGE_LOG_NONE 0
#define LANGUAGE_LOG_USER 1
#define LANGUAGE_LOG_ALL  2
#define LANGUAGE_LOG_PATH 3

#define LANGUAGE_OPTIONS_CHECK_BOUNDS_DEFAULT 0
#define LANGUAGE_OPTIONS_CHECK_BOUNDS_ON 1
#define LANGUAGE_OPTIONS_CHECK_BOUNDS_OFF 2

#define LANGUAGE_OPTIONS_COMPILE_DEFAULT 1
#define LANGUAGE_OPTIONS_COMPILE_OFF 0
#define LANGUAGE_OPTIONS_COMPILE_ON  1
#define LANGUAGE_OPTIONS_COMPILE_ALL 2
#define LANGUAGE_OPTIONS_COMPILE_MIN 3

#define LANGUAGE_OPTIONS_COLOR_AUTO 0
#define LANGUAGE_OPTIONS_COLOR_ON 1
#define LANGUAGE_OPTIONS_COLOR_OFF 2

#define LANGUAGE_OPTIONS_HISTORYFILE_ON 1
#define LANGUAGE_OPTIONS_HISTORYFILE_OFF 0

#define LANGUAGE_OPTIONS_STARTUPFILE_ON 1
#define LANGUAGE_OPTIONS_STARTUPFILE_OFF 2

#define LANGUAGE_LOGLEVEL_BELOWMIN -1000001
#define LANGUAGE_LOGLEVEL_DEBUG    -1000
#define LANGUAGE_LOGLEVEL_INFO      0
#define LANGUAGE_LOGLEVEL_WARN      1000
#define LANGUAGE_LOGLEVEL_ERROR     2000
#define LANGUAGE_LOGLEVEL_ABOVEMAX  1000001

#define LANGUAGE_OPTIONS_DEPWARN_OFF 0
#define LANGUAGE_OPTIONS_DEPWARN_ON 1
#define LANGUAGE_OPTIONS_DEPWARN_ERROR 2

#define LANGUAGE_OPTIONS_WARN_OVERWRITE_OFF 0
#define LANGUAGE_OPTIONS_WARN_OVERWRITE_ON 1

#define LANGUAGE_OPTIONS_WARN_SCOPE_OFF 0
#define LANGUAGE_OPTIONS_WARN_SCOPE_ON 1

#define LANGUAGE_OPTIONS_POLLY_ON 1
#define LANGUAGE_OPTIONS_POLLY_OFF 0

#define LANGUAGE_OPTIONS_FAST_MATH_ON 1
#define LANGUAGE_OPTIONS_FAST_MATH_OFF 2
#define LANGUAGE_OPTIONS_FAST_MATH_DEFAULT 0

#define LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON 1
#define LANGUAGE_OPTIONS_HANDLE_SIGNALS_OFF 0

#define LANGUAGE_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_YES 1
#define LANGUAGE_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_NO 0

#define LANGUAGE_OPTIONS_USE_COMPILED_MODULES_STRICT 3
#define LANGUAGE_OPTIONS_USE_COMPILED_MODULES_EXISTING 2
#define LANGUAGE_OPTIONS_USE_COMPILED_MODULES_YES 1
#define LANGUAGE_OPTIONS_USE_COMPILED_MODULES_NO 0

#define LANGUAGE_OPTIONS_USE_PKGIMAGES_EXISTING 2
#define LANGUAGE_OPTIONS_USE_PKGIMAGES_YES 1
#define LANGUAGE_OPTIONS_USE_PKGIMAGES_NO 0

// Version information
#include <language_version.h> // Generated file

LANGUAGE_DLLEXPORT extern int language_ver_major(void);
LANGUAGE_DLLEXPORT extern int language_ver_minor(void);
LANGUAGE_DLLEXPORT extern int language_ver_patch(void);
LANGUAGE_DLLEXPORT extern int language_ver_is_release(void);
LANGUAGE_DLLEXPORT extern const char *language_ver_string(void);

// nullable struct representations
typedef struct {
    uint8_t hasvalue;
    double value;
} language_nullable_float64_t;

typedef struct {
    uint8_t hasvalue;
    float value;
} language_nullable_float32_t;

#define language_root_task (language_current_task->ptls->root_task)

LANGUAGE_DLLEXPORT language_task_t *language_get_current_task(void) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;

// TODO: we need to pin the task while using this (set pure bit)
LANGUAGE_DLLEXPORT language_jmp_buf *language_get_safe_restore(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_set_safe_restore(language_jmp_buf *) LANGUAGE_NOTSAFEPOINT;

// codegen interface ----------------------------------------------------------
// The root propagation here doesn't have to be literal, but callers should
// ensure that the return value outlives the MethodInstance
typedef language_value_t *(*language_codeinstance_lookup_t)(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT,
    size_t min_world, size_t max_world);
typedef struct {
    int track_allocations;  // can we track allocations?
    int code_coverage;      // can we measure coverage?
    int prefer_specsig;     // are specialized function signatures preferred?

    // controls the emission of debug-info. mirrors the clang options
    int gnu_pubnames;       // can we emit the gnu pubnames debuginfo
    int debug_info_kind;    // Enum for line-table-only, line-directives-only,
                            // limited, standalone
    int debug_info_level;   // equivalent to the -g level from the cli
    int safepoint_on_entry; // Emit a safepoint on entry to each function
    int gcstack_arg; // Pass the ptls value as an argument with swiftself

    int use_jlplt; // Whether to use the Julia PLT mechanism or emit symbols directly
    // Cache access. Default: language_rettype_inferred_native.
    language_codeinstance_lookup_t lookup;
} language_cgparams_t;
extern LANGUAGE_DLLEXPORT int language_default_debug_info_kind;

typedef struct {
    int emit_metadata;
} language_emission_params_t;

#ifdef __cplusplus
}
#endif

#endif
