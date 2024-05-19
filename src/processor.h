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

#ifndef LANGUAGE_PROCESSOR_H
#define LANGUAGE_PROCESSOR_H

#include "support/dtypes.h"

#include "code.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Image metadata
// Every image exports a `language_image_pointers_t` as a global symbol `language_image_pointers`.
// This symbol acts as a root for all other code-related symbols in the image.

enum {
    LANGUAGE_TARGET_VEC_CALL = 1 << 0,
    // Clone all functions
    LANGUAGE_TARGET_CLONE_ALL = 1 << 1,
    // Clone when there's scalar math operations that can benefit from target-specific
    // optimizations. This includes `muladd`, `fma`, `fast`/`contract` flags.
    LANGUAGE_TARGET_CLONE_MATH = 1 << 2,
    // Clone when the function has a loop
    LANGUAGE_TARGET_CLONE_LOOP = 1 << 3,
    // Clone when the function uses any vectors
    // When this is specified, the cloning pass should also record if any of the cloned functions
    // used this in any function call (including the signature of the function itself)
    LANGUAGE_TARGET_CLONE_SIMD = 1 << 4,
    // The CPU name is unknown
    LANGUAGE_TARGET_UNKNOWN_NAME = 1 << 5,
    // Optimize for size for this target
    LANGUAGE_TARGET_OPTSIZE = 1 << 6,
    // Only optimize for size for this target
    LANGUAGE_TARGET_MINSIZE = 1 << 7,
    // Clone when the function queries CPU features
    LANGUAGE_TARGET_CLONE_CPU = 1 << 8,
    // Clone when the function uses fp16
    LANGUAGE_TARGET_CLONE_FLOAT16 = 1 << 9,
    // Clone when the function uses bf16
    LANGUAGE_TARGET_CLONE_BFLOAT16 = 1 << 10,
};

#define LANGUAGE_FEATURE_DEF_NAME(name, bit, llvmver, str) LANGUAGE_FEATURE_DEF(name, bit, llvmver)
typedef enum {
#define LANGUAGE_FEATURE_DEF(name, bit, llvmver) LANGUAGE_X86_##name = bit,
#include "features_x86.h"
#undef LANGUAGE_FEATURE_DEF
#define LANGUAGE_FEATURE_DEF(name, bit, llvmver) LANGUAGE_AArch32_##name = bit,
#include "features_aarch32.h"
#undef LANGUAGE_FEATURE_DEF
#define LANGUAGE_FEATURE_DEF(name, bit, llvmver) LANGUAGE_AArch64_##name = bit,
#include "features_aarch64.h"
#undef LANGUAGE_FEATURE_DEF
} language_cpu_feature_t;
#undef LANGUAGE_FEATURE_DEF_NAME

LANGUAGE_DLLEXPORT int language_test_cpu_feature(language_cpu_feature_t feature);

static const uint32_t language_sysimg_tag_mask = 0x80000000u;
static const uint32_t language_sysimg_val_mask = ~((uint32_t)0x80000000u);

typedef struct _language_image_fptrs_t {
    // number of functions
    uint32_t nptrs;
    // function pointers
    void **ptrs;

    // Following fields contains the information about the selected target.
    // All of these fields are 0 if the selected targets have all the functions cloned.
    // Instead the offsets are stored in `nptrs` and `ptrs`.

    // number of cloned functions
    uint32_t nclones;
    // function pointer of cloned functions
    void **clone_ptrs;
    // sorted indices of the cloned functions (including the tag bit)
    const uint32_t *clone_idxs;
} language_image_fptrs_t;

typedef struct {
    uint64_t base;
    const char *gvars_base;
    const int32_t *gvars_offsets;
    uint32_t ngvars;
    language_image_fptrs_t fptrs;
    void **language_small_typeof;
} language_image_t;

// The header for each image
// Details important counts about the image
typedef struct {
    // The version of the image format
    // Most up-to-date version is 1
    uint32_t version;
    // The number of shards in this image
    uint32_t nshards;
    // The total number of fvars in this image among all shards
    uint32_t nfvars;
    // The total number of gvars in this image among all shards
    uint32_t ngvars;
} language_image_header_t;

// Per-shard data for image shards. Each image contains header->nshards of these.
typedef struct {
    // The array of function pointers (`void*`).
    // This includes all julia functions in sysimg as well as all other functions that are cloned.
    // The default function pointer is used if the function is cloned.
    // The first element is the size of the array, which should **NOT** be used is the number
    // of julia functions in the sysimg.
    // Each entry in this array uniquely identifies a function we are interested in
    // (the function may have multiple function pointers corresponding to different versions).
    const uintptr_t *fvar_count;
    void **fvar_ptrs;
    // This is the mapping of shard function index -> global function index
    // staticdata.c relies on the same order of functions in the global function array being
    // the same as what it saw when serializing the global function array. However, partitioning
    // into multiple shards will cause functions to be reordered. This array is used to map
    // back to the original function array for loading.
    const uint32_t *fvar_idxs;
    // This array of global variable offsets (`int32_t`) from the base pointer.
    // Similar to fvar_offsets, but for gvars
    // This is also the base data pointer
    // (all data pointers in this shard are stored as offsets to this address)
    const int32_t *gvar_offsets;
    // This is the mapping of shard global variable index -> global global variable index
    // Similar to fvar_idxs, but for gvars
    const uint32_t *gvar_idxs;
    // location and index of relocation slots.
    // Stored as pairs of function indices and `int32_t` offsets from `language_sysimg_gvars_base`.
    // The first element is an `uint32_t` giving the number of relocations.
    // This is needed for functions whose address is used in a way that requires dispatch.
    // We currently only support one type of relocation (i.e. absolute pointer) which is enough
    // for all use in functions as well as GOT slot (for "PLT" callback).
    // Note that not all functions being cloned are assigned a slot.
    // This array is sorted by the function indices.
    // There can be more than one slot per-function,
    // i.e. there can be duplicated function indices.
    const int32_t *clone_slots;
    //  Target-specific function pointer offsets.
    //  This contains all the cloned functions that we are interested in and it needs to be decoded
    //  and used along with `language_dispatch_fvars_idxs`.
    //  For the default target, there's no entries in this variable, if there's any relocations
    //  needed for the default target, the function pointers are taken from the global offset
    //  arrays directly.
    //  For a `clone_all` target (i.e. with the length in `language_dispatch_fvars_idxs` tagged), this
    //  variable contains an offset array of the same length as the global one. Only the indices
    //  appearing in `language_dispatch_fvars_idxs` need relocation and the dispatch code should return
    //  this array as the original/base function offsets.
    //  For other targets, this variable contains an offset array with the length defined in
    //  `language_dispatch_fvars_idxs`. Tagged indices need relocations.
    void **clone_ptrs;
    //  Target-specific function indices.
    //  For each target, this includes a tagged `uint32_t` length, an optional `uint32_t` index
    //  of the base target followed by an array of tagged function indices.
    //  The base target index is required to be smaller than the index of the current target
    //  and must be the default (`0`) or a `clone_all` target.
    //  The tag bits for both the length and the indices are the top bit.
    //  A tagged length indicates that all of the functions are cloned and the indices follows
    //  are the ones that requires relocation. The base target index is omitted in this case.
    //  Otherwise, the length is the total number of functions that we are interested in
    //  for this target, which includes all cloned julia functions and
    //  all other cloned functions that requires relocation.
    //  A tagged index means that the function pointer should be filled into the GOT slots
    //  identified by `language_dispatch_reloc_slots`. There could be more than one slot per function.
    //  (Note that a tagged index could corresponds to a function's pointer that's the same as
    //  the base one since this is the only way we currently represent relocations.)
    const uint32_t *clone_idxs;
} language_image_shard_t;

// The TLS data for each image
typedef struct {
    void *pgcstack_func_slot;
    void *pgcstack_key_slot;
    size_t *tls_offset;
} language_image_ptls_t;

//The root struct for images, points to all the other globals
typedef struct {
    // The image header, contains numerical global data
    const language_image_header_t *header;
    // The shard table, contains per-shard data
    const language_image_shard_t *shards; // points to header->nshards length array
    // The TLS data pointer
    const language_image_ptls_t *ptls;
    // A copy of language_small_typeof[]
    void **language_small_typeof;

    //  serialized target data
    //  This contains the number of targets
    //  in addition to the name and feature set of each target.
    const void *target_data;
} language_image_pointers_t;

/**
 * Initialize the processor dispatch system with sysimg `hdl` (also initialize the sysimg itself).
 * The dispatch system will find the best implementation to be used in this session.
 * The decision will be based on the host CPU and features as well as the `cpu_target`
 * option. This must be called before initializing JIT and should only be called once.
 * An error will be raised if this is called more than once or none of the implementation
 * supports the current system.
 *
 * Return the data about the function pointers selected.
 */
language_image_t language_init_processor_sysimg(void *hdl);
language_image_t language_init_processor_pkgimg(void *hdl);

// Return the name of the host CPU as a julia string.
LANGUAGE_DLLEXPORT language_value_t *language_get_cpu_name(void);
// Return the features of the host CPU as a julia string.
LANGUAGE_DLLEXPORT language_value_t *language_get_cpu_features(void);
// Dump the name and feature set of the host CPU
LANGUAGE_DLLEXPORT language_value_t *language_cpu_has_fma(int bits);
// Check if the CPU has native FMA instructions;
// For debugging only
LANGUAGE_DLLEXPORT void language_dump_host_cpu(void);
LANGUAGE_DLLEXPORT language_value_t* language_check_pkgimage_clones(char* data);

LANGUAGE_DLLEXPORT int32_t language_set_zero_subnormals(int8_t isZero);
LANGUAGE_DLLEXPORT int32_t language_get_zero_subnormals(void);
LANGUAGE_DLLEXPORT int32_t language_set_default_nans(int8_t isDefault);
LANGUAGE_DLLEXPORT int32_t language_get_default_nans(void);
#ifdef __cplusplus
}

#include <utility>
#include <string>
#include <vector>

extern LANGUAGE_DLLEXPORT bool language_processor_print_help;
// NOLINTBEGIN(clang-diagnostic-return-type-c-linkage)
/**
 * Returns the CPU name and feature string to be used by LLVM JIT.
 *
 * If the detected/specified CPU name is not available on the LLVM version specified,
 * a fallback CPU name will be used. Unsupported features will be ignored.
 */
extern "C" LANGUAGE_DLLEXPORT std::pair<std::string,llvm::SmallVector<std::string, 0>> language_get_llvm_target(bool imaging, uint32_t &flags) LANGUAGE_NOTSAFEPOINT;

/**
 * Returns the CPU name and feature string to be used by LLVM disassembler.
 *
 * This will return a generic CPU name and a full feature string.
 */
extern "C" LANGUAGE_DLLEXPORT const std::pair<std::string,std::string> &language_get_llvm_disasm_target(void) LANGUAGE_NOTSAFEPOINT;

struct language_target_spec_t {
    // LLVM target name
    std::string cpu_name;
    // LLVM feature string
    std::string cpu_features;
    // serialized identification data
    llvm::SmallVector<uint8_t, 0> data;
    // Clone condition.
    uint32_t flags;
    // Base target index.
    int base;
};
/**
 * Return the list of targets to clone
 */
extern "C" LANGUAGE_DLLEXPORT llvm::SmallVector<language_target_spec_t, 0> language_get_llvm_clone_targets(void) LANGUAGE_NOTSAFEPOINT;
// NOLINTEND(clang-diagnostic-return-type-c-linkage)
struct FeatureName {
    const char *name;
    uint32_t bit; // bit index into a `uint32_t` array;
    uint32_t llvmver; // 0 if it is available on the oldest LLVM version we support
};

extern "C" LANGUAGE_DLLEXPORT language_value_t* language_reflect_clone_targets();
extern "C" LANGUAGE_DLLEXPORT void language_reflect_feature_names(const FeatureName **feature_names, size_t *nfeatures);
#endif

#endif