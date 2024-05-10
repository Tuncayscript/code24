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

#ifndef RUNTIME_VM_UNIBROW_INL_H_
#define RUNTIME_VM_UNIBROW_INL_H_

#include "src/unibrow.h"

#include "platform/assert.h"

namespace unibrow {

template <class T, intptr_t s>
intptr_t Mapping<T, s>::get(int32_t c, int32_t n, int32_t* result) {
  CacheEntry entry = entries_[c & kMask];
  if (entry.code_point_ == c) {
    if (entry.offset_ == 0) {
      return 0;
    } else {
      result[0] = c + entry.offset_;
      return 1;
    }
  } else {
    return CalculateValue(c, n, result);
  }
}

template <class T, intptr_t s>
intptr_t Mapping<T, s>::CalculateValue(int32_t c, int32_t n, int32_t* result) {
  bool allow_caching = true;
  intptr_t length = T::Convert(c, n, result, &allow_caching);
  if (allow_caching) {
    if (length == 1) {
      entries_[c & kMask] = CacheEntry(c, result[0] - c);
      return 1;
    } else {
      entries_[c & kMask] = CacheEntry(c, 0);
      return 0;
    }
  } else {
    return length;
  }
}

}  // namespace unibrow

#endif  // RUNTIME_VM_UNIBROW_INL_H_
