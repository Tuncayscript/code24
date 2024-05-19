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

#include "gc-alloc-profiler.h"

#include "language_internal.h"
#include "gc.h"

#include "llvm/ADT/SmallVector.h"

#include <string>

using std::string;
using llvm::SmallVector;

struct language_raw_backtrace_t {
    language_bt_element_t *data;
    size_t size;
};

struct language_raw_alloc_t {
    language_datatype_t *type_address;
    language_raw_backtrace_t backtrace;
    size_t size;
    void *task;
    uint64_t timestamp;
};

// == These structs define the global singleton profile buffer that will be used by
// callbacks to store profile results. ==
struct language_per_thread_alloc_profile_t {
    SmallVector<language_raw_alloc_t, 0> allocs;
};

struct language_alloc_profile_t {
    double sample_rate;

    SmallVector<language_per_thread_alloc_profile_t, 0> per_thread_profiles;
};

struct language_combined_results {
    SmallVector<language_raw_alloc_t, 0> combined_allocs;
};

// == Global variables manipulated by callbacks ==

language_alloc_profile_t g_alloc_profile;
int g_alloc_profile_enabled = false;
language_combined_results g_combined_results; // Will live forever.

// === stack stuff ===

language_raw_backtrace_t get_raw_backtrace() LANGUAGE_NOTSAFEPOINT {
    // We first record the backtrace onto a MAX-sized buffer, so that we don't have to
    // allocate the buffer until we know the size. To ensure thread-safety, we use a
    // per-thread backtrace buffer.
    language_ptls_t ptls = language_current_task->ptls;
    language_bt_element_t *shared_bt_data_buffer = ptls->profiling_bt_buffer;
    if (shared_bt_data_buffer == NULL) {
        size_t size = sizeof(language_bt_element_t) * (LANGUAGE_MAX_BT_SIZE + 1);
        shared_bt_data_buffer = (language_bt_element_t*) malloc_s(size);
        ptls->profiling_bt_buffer = shared_bt_data_buffer;
    }

    size_t bt_size = rec_backtrace(shared_bt_data_buffer, LANGUAGE_MAX_BT_SIZE, 2);

    // Then we copy only the needed bytes out of the buffer into our profile.
    size_t bt_bytes = bt_size * sizeof(language_bt_element_t);
    language_bt_element_t *bt_data = (language_bt_element_t*) malloc_s(bt_bytes);
    memcpy(bt_data, shared_bt_data_buffer, bt_bytes);


    return language_raw_backtrace_t{
        bt_data,
        bt_size
    };
}

// == exported interface ==

extern "C" {  // Needed since these functions doesn't take any arguments.

LANGUAGE_DLLEXPORT void language_start_alloc_profile(double sample_rate) {
    // We only need to do this once, the first time this is called.
    size_t nthreads = language_atomic_load_acquire(&language_n_threads);
    while (g_alloc_profile.per_thread_profiles.size() < nthreads) {
        g_alloc_profile.per_thread_profiles.push_back(language_per_thread_alloc_profile_t{});
    }

    g_alloc_profile.sample_rate = sample_rate;
    g_alloc_profile_enabled = true;
}

LANGUAGE_DLLEXPORT language_profile_allocs_raw_results_t language_fetch_alloc_profile() {
    // combine allocs
    // TODO: interleave to preserve ordering
    for (auto& profile : g_alloc_profile.per_thread_profiles) {
        for (const auto& alloc : profile.allocs) {
            g_combined_results.combined_allocs.push_back(alloc);
        }

        profile.allocs.clear();
    }

    return language_profile_allocs_raw_results_t{
        g_combined_results.combined_allocs.data(),
        g_combined_results.combined_allocs.size(),
    };
}

LANGUAGE_DLLEXPORT void language_stop_alloc_profile() {
    g_alloc_profile_enabled = false;
}

LANGUAGE_DLLEXPORT void language_free_alloc_profile() {
    // Free any allocs that remain in the per-thread profiles, that haven't
    // been combined yet (which happens in fetch_alloc_profiles()).
    for (auto& profile : g_alloc_profile.per_thread_profiles) {
        for (auto alloc : profile.allocs) {
            free(alloc.backtrace.data);
        }
        profile.allocs.clear();
    }

    // Free the allocs that have been already combined into the combined results object.
    for (auto alloc : g_combined_results.combined_allocs) {
        free(alloc.backtrace.data);
    }

    g_combined_results.combined_allocs.clear();
}

// == callback called into by the outside ==

void _maybe_record_alloc_to_profile(language_value_t *val, size_t size, language_datatype_t *type) LANGUAGE_NOTSAFEPOINT {
    auto& global_profile = g_alloc_profile;
    size_t thread_id = language_atomic_load_relaxed(&language_current_task->tid);
    if (thread_id >= global_profile.per_thread_profiles.size())
        return; // ignore allocations on threads started after the alloc-profile started

    auto& profile = global_profile.per_thread_profiles[thread_id];

    auto sample_val = double(rand()) / double(RAND_MAX);
    auto should_record = sample_val <= global_profile.sample_rate;
    if (!should_record) {
        return;
    }

    profile.allocs.emplace_back(language_raw_alloc_t{
        type,
        get_raw_backtrace(),
        size,
        (void *)language_current_task,
        cycleclock()
    });
}

}  // extern "C"
