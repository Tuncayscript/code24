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
 *
 */

#ifndef RUNTIME_VM_HEAP_SPACES_H_
#define RUNTIME_VM_HEAP_SPACES_H_

#include "platform/atomic.h"
#include "platform/globals.h"

// This file contains utilities shared by old and new space.
// TODO(koda): Create Space base class with Space::CurrentUsage().

namespace Code {

// Usage statistics for a space/generation at a particular moment in time.
class SpaceUsage {
 public:
  SpaceUsage() : capacity_in_words(0), used_in_words(0), external_in_words(0) {}
  RelaxedAtomic<intptr_t> capacity_in_words;
  RelaxedAtomic<intptr_t> used_in_words;
  RelaxedAtomic<intptr_t> external_in_words;

  intptr_t CombinedCapacityInWords() const {
    return capacity_in_words + external_in_words;
  }
  intptr_t CombinedUsedInWords() const {
    return used_in_words + external_in_words;
  }
};

enum class GCType {
  kScavenge,
  kEvacuate,
  kStartConcurrentMark,
  kMarkSweep,
  kMarkCompact,
};

enum class GCReason {
  kNewSpace,     // New space is full.
  kStoreBuffer,  // Store buffer is too big.
  kPromotion,    // Old space limit crossed after a scavenge.
  kOldSpace,     // Old space limit crossed, or old space allocation failed.
  kFinalize,     // Concurrent marking finished.
  kFull,         // Heap::CollectAllGarbage
  kExternal,     // CODE_NewFinalizableHandle CODE_NewWeakPersistentHandle
  kIdle,         // CODE_NotifyIdle
  kDestroyed,    // CODE_NotifyDestroyed
  kDebugging,    // service request, etc.
  kCatchUp,      // End of ForceGrowthScope or CODE_PerformanceMode_Latency.
};

static constexpr intptr_t kNewAllocatableSize = 256 * KB;
static constexpr intptr_t kAllocatablePageSize = 64 * KB;

inline bool IsAllocatableInNewSpace(intptr_t size) {
  return size <= kNewAllocatableSize;
}
inline bool IsAllocatableViaFreeLists(intptr_t size) {
  return size < kAllocatablePageSize;
}

}  // namespace dart

#endif  // RUNTIME_VM_HEAP_SPACES_H_
