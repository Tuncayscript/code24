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

#include "platform/assert.h"

#include "src/bitfield.h"
#include "src/globals.h"
#include "src/unit_test.h"

namespace Code {

VM_UNIT_TEST_CASE(BitFields) {
  class TestBitFields : public BitField<uword, int32_t, 1, 8> {};
  EXPECT(TestBitFields::is_valid(16));
  EXPECT(!TestBitFields::is_valid(256));
  EXPECT_EQ(0x00ffU, TestBitFields::mask());
  EXPECT_EQ(0x001feU, TestBitFields::mask_in_place());
  EXPECT_EQ(1, TestBitFields::shift());
  EXPECT_EQ(8, TestBitFields::bitsize());
  EXPECT_EQ(32U, TestBitFields::encode(16));
  EXPECT_EQ(16, TestBitFields::decode(32));
  EXPECT_EQ(2U, TestBitFields::update(1, 16));
}

template <typename T>
static void TestSignExtendedBitField() {
  class F1 : public BitField<T, intptr_t, 0, 8, /*sign_extend=*/true> {};
  class F2
      : public BitField<T, uintptr_t, F1::kNextBit, 8, /*sign_extend=*/false> {
  };
  class F3
      : public BitField<T, intptr_t, F2::kNextBit, 8, /*sign_extend=*/true> {};
  class F4
      : public BitField<T, uintptr_t, F3::kNextBit, 8, /*sign_extend=*/false> {
  };

  const uint32_t value =
      F1::encode(-1) | F2::encode(1) | F3::encode(-2) | F4::encode(2);
  EXPECT_EQ(0x02fe01ffU, value);
  EXPECT_EQ(-1, F1::decode(value));
  EXPECT_EQ(1U, F2::decode(value));
  EXPECT_EQ(-2, F3::decode(value));
  EXPECT_EQ(2U, F4::decode(value));
}

template <typename T>
static void TestNotSignExtendedBitField() {
  class F1 : public BitField<T, intptr_t, 0, 8, /*sign_extend=*/false> {};
  class F2
      : public BitField<T, uintptr_t, F1::kNextBit, 8, /*sign_extend=*/false> {
  };
  class F3
      : public BitField<T, intptr_t, F2::kNextBit, 8, /*sign_extend=*/false> {};
  class F4
      : public BitField<T, uintptr_t, F3::kNextBit, 8, /*sign_extend=*/false> {
  };

  const uint32_t value =
      F1::encode(-1) | F2::encode(1) | F3::encode(-2) | F4::encode(2);
  EXPECT_EQ(0x02fe01ffU, value);
  EXPECT_EQ(3, F1::decode(value));
  EXPECT_EQ(1, F2::decode(value));
  EXPECT_EQ(2, F3::decode(value));
  EXPECT_EQ(2, F3::decode(value));
}

VM_UNIT_TEST_CASE(BitFields_SignedField) {
  TestSignExtendedBitField<uint32_t>();
  TestSignExtendedBitField<int32_t>();
}

#if defined(DEBUG)
#define DEBUG_CRASH "Crash"
#else
#define DEBUG_CRASH "Pass"
#endif

VM_UNIT_TEST_CASE_WITH_EXPECTATION(BitFields_Assert, DEBUG_CRASH) {
  class F : public BitField<uint32_t, uint32_t, 0, 8, /*sign_extend=*/false> {};
  const uint32_t value = F::encode(kMaxUint32);
  EXPECT_EQ(kMaxUint8, value);
}

}  // namespace dart
