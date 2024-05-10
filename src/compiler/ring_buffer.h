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

#ifndef RUNTIME_VM_RING_BUFFER_H_
#define RUNTIME_VM_RING_BUFFER_H_

#include "platform/assert.h"
#include "platform/utils.h"

namespace Code {

// Fixed-capacity ring buffer.
template <typename T, int N>
class RingBuffer {
 public:
  RingBuffer() : count_(0) {}

  void Add(const T& t) { data_[count_++ & kMask] = t; }

  // Returns the i'th most recently added element. Requires 0 <= i < Size().
  const T& Get(int i) const {
    ASSERT(0 <= i && i < Size());
    return data_[(count_ - i - 1) & kMask];
  }

  // Returns the number of elements currently stored in this buffer (at most N).
  int64_t Size() const {
    return Utils::Minimum(count_, static_cast<int64_t>(N));
  }

 private:
  static constexpr int kMask = N - 1;
  COMPILE_ASSERT((N & kMask) == 0);
  T data_[N];
  int64_t count_;
};

}  // namespace dart

#endif  // RUNTIME_VM_RING_BUFFER_H_
