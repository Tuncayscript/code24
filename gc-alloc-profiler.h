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

#ifndef LANGUAGE_GC_ALLOC_PROFILER_H
#define LANGUAGE_GC_ALLOC_PROFILER_H

#include "code.h"
#include "ios.h"

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
// The public interface to call from Julia for allocations profiling
// ---------------------------------------------------------------------

// Forward-declaration to avoid dependency in header file.
struct language_raw_alloc_t;  // Defined in gc-alloc-profiler.cpp

typedef struct {
    struct language_raw_alloc_t *allocs;
    size_t num_allocs;
} language_profile_allocs_raw_results_t;

LANGUAGE_DLLEXPORT void language_start_alloc_profile(double sample_rate);
LANGUAGE_DLLEXPORT language_profile_allocs_raw_results_t language_fetch_alloc_profile(void);
LANGUAGE_DLLEXPORT void language_stop_alloc_profile(void);
LANGUAGE_DLLEXPORT void language_free_alloc_profile(void);

// ---------------------------------------------------------------------
// Functions to call from GC when alloc profiling is enabled
// ---------------------------------------------------------------------

void _maybe_record_alloc_to_profile(language_value_t *val, size_t size, language_datatype_t *typ) LANGUAGE_NOTSAFEPOINT;

extern int g_alloc_profile_enabled;

// This should only be used from _deprecated_ code paths. We shouldn't see UNKNOWN anymore.
#define language_gc_unknown_type_tag ((language_datatype_t*)0xdeadaa03)

static inline void maybe_record_alloc_to_profile(language_value_t *val, size_t size, language_datatype_t *typ) LANGUAGE_NOTSAFEPOINT {
    if (__unlikely(g_alloc_profile_enabled)) {
        _maybe_record_alloc_to_profile(val, size, typ);
    }
}

#ifdef __cplusplus
}
#endif


#endif  // LANGUAGE_GC_ALLOC_PROFILER_H
