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

#ifndef RUNTIME_VM_UNIBROW_H_
#define RUNTIME_VM_UNIBROW_H_

#include <sys/types.h>

#include "src/globals.h"

/**
 * \file
 * Definitions and convenience functions for working with unicode.
 */

namespace unibrow {

// A cache used in case conversion.  It caches the value for characters
// that either have no mapping or map to a single character independent
// of context.  Characters that map to more than one character or that
// map differently depending on context are always looked up.
template <class T, intptr_t size = 256>
class Mapping {
 public:
  inline Mapping() {}
  inline intptr_t get(int32_t c, int32_t n, int32_t* result);

 private:
  friend class Test;
  intptr_t CalculateValue(int32_t c, int32_t n, int32_t* result);
  struct CacheEntry {
    inline CacheEntry() : code_point_(kNoChar), offset_(0) {}
    inline CacheEntry(int32_t code_point, signed offset)
        : code_point_(code_point), offset_(offset) {}
    int32_t code_point_;
    signed offset_;
    static constexpr intptr_t kNoChar = (1 << 21) - 1;
  };
  static constexpr intptr_t kSize = size;
  static constexpr intptr_t kMask = kSize - 1;
  CacheEntry entries_[kSize];
};

struct Letter {
  static bool Is(int32_t c);
};
struct Ecma262Canonicalize {
  static constexpr intptr_t kMaxWidth = 1;
  static intptr_t Convert(int32_t c,
                          int32_t n,
                          int32_t* result,
                          bool* allow_caching_ptr);
};
struct Ecma262UnCanonicalize {
  static constexpr intptr_t kMaxWidth = 4;
  static intptr_t Convert(int32_t c,
                          int32_t n,
                          int32_t* result,
                          bool* allow_caching_ptr);
};
struct CanonicalizationRange {
  static constexpr intptr_t kMaxWidth = 1;
  static intptr_t Convert(int32_t c,
                          int32_t n,
                          int32_t* result,
                          bool* allow_caching_ptr);
};

}  // namespace unibrow

#endif  // RUNTIME_VM_UNIBROW_H_
