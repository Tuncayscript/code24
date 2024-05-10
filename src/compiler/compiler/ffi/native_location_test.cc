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

#include "src/compiler/ffi/unit_test.h"

#include "src/compiler/ffi/native_location.h"

namespace Code {
namespace compiler {
namespace ffi {

UNIT_TEST_CASE_WITH_ZONE(NativeStackLocation) {
  const auto& native_type = *new (Z) NativePrimitiveType(kInt8);

  const int kUnalignedStackLocation = 17;

  const auto& native_location = *new (Z) NativeStackLocation(
      native_type, native_type, SPREG, kUnalignedStackLocation);

  EXPECT_EQ(kUnalignedStackLocation + native_type.SizeInBytes(),
            native_location.StackTopInBytes());
}

UNIT_TEST_CASE_WITH_ZONE(NativeStackLocation_Split) {
  const auto& native_type = *new (Z) NativePrimitiveType(kInt64);

  const auto& native_location =
      *new (Z) NativeStackLocation(native_type, native_type, SPREG, 0);

  const auto& half_0 = native_location.Split(Z, 2, 0);
  const auto& half_1 = native_location.Split(Z, 2, 1);

  EXPECT_EQ(0, half_0.offset_in_bytes());
  EXPECT_EQ(4, half_1.offset_in_bytes());
}

// Regression test for NativeFpuRegistersLocation::Equals not considering kind
// when comparing.
UNIT_TEST_CASE_WITH_ZONE(NativeStackLocation_Equals) {
  const auto& native_type = *new (Z) NativePrimitiveType(kInt8);

  // Two FPU registers of the same kind and number are equal.
  {
    const auto& native_location1 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kQuadFpuReg,
        /*fpu_register=*/0);

    const auto& native_location2 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kQuadFpuReg,
        /*fpu_register=*/0);

    EXPECT(native_location1.Equals(native_location2));
  }

  // Two FPU registers with different numbers are NOT equal.
  {
    const auto& native_location1 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kQuadFpuReg,
        /*fpu_register=*/2);

    const auto& native_location2 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kQuadFpuReg,
        /*fpu_register=*/4);

    EXPECT(!native_location1.Equals(native_location2));
  }

  // Two FPU registers with different kinds are NOT equal.
  {
    const auto& native_location1 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kQuadFpuReg,
        /*fpu_register=*/3);

    const auto& native_location2 = *new (Z) NativeFpuRegistersLocation(
        native_type, native_type, kDoubleFpuReg,
        /*fpu_register=*/3);

    EXPECT(!native_location1.Equals(native_location2));
  }
}

}  // namespace ffi
}  // namespace compiler
}  // namespace dart
