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

#ifndef RUNTIME_VM_DOUBLE_INTERNALS_H_
#define RUNTIME_VM_DOUBLE_INTERNALS_H_

#include "platform/utils.h"

namespace Code {

// We assume that doubles and uint64_t have the same endianness.
static uint64_t double_to_uint64(double d) {
  return bit_cast<uint64_t>(d);
}

// Helper functions for doubles.
class DoubleInternals {
 public:
  static constexpr int kSignificandSize = 53;

  explicit DoubleInternals(double d) : d64_(double_to_uint64(d)) {}

  // Returns the double's bit as uint64.
  uint64_t AsUint64() const { return d64_; }

  int Exponent() const {
    if (IsDenormal()) return kDenormalExponent;

    uint64_t d64 = AsUint64();
    int biased_e =
        static_cast<int>((d64 & kExponentMask) >> kPhysicalSignificandSize);
    return biased_e - kExponentBias;
  }

  uint64_t Significand() const {
    uint64_t d64 = AsUint64();
    uint64_t significand = d64 & kSignificandMask;
    if (!IsDenormal()) {
      return significand + kHiddenBit;
    } else {
      return significand;
    }
  }

  // Returns true if the double is a denormal.
  bool IsDenormal() const {
    uint64_t d64 = AsUint64();
    return (d64 & kExponentMask) == 0;
  }

  // We consider denormals not to be special.
  // Hence only Infinity and NaN are special.
  bool IsSpecial() const {
    uint64_t d64 = AsUint64();
    return (d64 & kExponentMask) == kExponentMask;
  }

  int Sign() const {
    uint64_t d64 = AsUint64();
    return (d64 & kSignMask) == 0 ? 1 : -1;
  }

 private:
  static constexpr uint64_t kSignMask =
      CODE_2PART_UINT64_C(0x80000000, 00000000);
  static constexpr uint64_t kExponentMask =
      CODE_2PART_UINT64_C(0x7FF00000, 00000000);
  static constexpr uint64_t kSignificandMask =
      CODE_2PART_UINT64_C(0x000FFFFF, FFFFFFFF);
  static constexpr uint64_t kHiddenBit =
      CODE_2PART_UINT64_C(0x00100000, 00000000);
  static constexpr int kPhysicalSignificandSize =
      52;  // Excludes the hidden bit.
  static constexpr int kExponentBias = 0x3FF + kPhysicalSignificandSize;
  static constexpr int kDenormalExponent = -kExponentBias + 1;

  const uint64_t d64_;
};

}  // namespace dart

#endif  // RUNTIME_VM_DOUBLE_INTERNALS_H_
