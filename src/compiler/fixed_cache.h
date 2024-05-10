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

#ifndef RUNTIME_VM_FIXED_CACHE_H_
#define RUNTIME_VM_FIXED_CACHE_H_

#include <stddef.h>
#include <stdint.h>

#include "src/lockers.h"

namespace Code {

// A simple sorted fixed size Key-Value storage.
//
// Assumes both Key and Value are default-constructible objects.
//
// Keys must be comparable with operator<.
//
// Duplicates are not allowed - check with Lookup before insertion.
//
template <class K, class V, intptr_t kCapacity>
class FixedCache {
 public:
  struct Entry {
    K key;
    V value;
  };

  FixedCache() : length_(0) {}

  ~FixedCache() { Clear(); }

  V* Lookup(K key) {
    MutexLocker ml(&mutex_);

    intptr_t i = LowerBound(key);
    if (i != length_ && pairs_[i].key == key) return &pairs_[i].value;
    return nullptr;
  }

  void Insert(K key, V value) {
    MutexLocker ml(&mutex_);

    intptr_t i = LowerBound(key);

    if (length_ == kCapacity) {
      length_ = kCapacity - 1;
      if (i == kCapacity) i = kCapacity - 1;
    }

    for (intptr_t j = length_ - 1; j >= i; j--) {
      pairs_[j + 1] = pairs_[j];
    }

    length_ += 1;
    pairs_[i].key = key;
    pairs_[i].value = value;
  }

  void Clear() {
    MutexLocker ml(&mutex_);
    length_ = 0;
  }

 private:
  intptr_t LowerBound(K key) {
    intptr_t low = 0, high = length_;
    while (low != high) {
      intptr_t mid = low + (high - low) / 2;
      if (key < pairs_[mid].key) {
        high = mid;
      } else if (key > pairs_[mid].key) {
        low = mid + 1;
      } else {
        low = high = mid;
      }
    }
    return low;
  }

  // We protect any operation on the [FixedCache] because multiple isolates from
  // the same [IsolateGroup] can access this cache concurrently (as can the GC
  // when it clears it).
  Mutex mutex_;
  Entry pairs_[kCapacity];  // Sorted array of pairs.
  intptr_t length_;
};

}  // namespace dart

#endif  // RUNTIME_VM_FIXED_CACHE_H_
