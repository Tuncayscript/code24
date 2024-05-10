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

#include "src/compiler/ffi/native_type.h"

#include "src/compiler/backend/il_test_helper.h"
#include "src/unit_test.h"

namespace Code {
namespace compiler {
namespace ffi {

ISOLATE_UNIT_TEST_CASE(Ffi_NativeType_Primitive_FromAbstractType) {
  Zone* Z = thread->zone();

  const auto& ffi_library = Library::Handle(Library::FfiLibrary());
  const auto& int8_class = Class::Handle(GetClass(ffi_library, "Int8"));
  const auto& int8_type = Type::Handle(int8_class.DeclarationType());
  const char* error = nullptr;
  const auto& native_type = *NativeType::FromAbstractType(Z, int8_type, &error);
  EXPECT_NULLPTR(error);

  EXPECT_EQ(1, native_type.SizeInBytes());
  EXPECT_STREQ("int8", native_type.ToCString());
  EXPECT(native_type.IsInt());
  EXPECT(native_type.IsPrimitive());
}

// In all calling conventions `bool` behaves as `uint8_t` when it comes to:
// - size
// - alignment in structs
// - alignment on stack
// - upper bytes in cpu registers.
ISOLATE_UNIT_TEST_CASE(Ffi_NativeType_Bool_FromAbstractType) {
  Zone* Z = thread->zone();

  const auto& ffi_library = Library::Handle(Library::FfiLibrary());
  const auto& bool_class = Class::Handle(GetClass(ffi_library, "Bool"));
  const auto& bool_type = Type::Handle(bool_class.DeclarationType());
  const char* error = nullptr;
  const auto& bool_native_type =
      *NativeType::FromAbstractType(Z, bool_type, &error);
  EXPECT_NULLPTR(error);

  const auto& uint8_native_type = *new (Z) NativePrimitiveType(kUint8);

  EXPECT(bool_native_type.Equals(uint8_native_type));
  EXPECT_EQ(1, bool_native_type.SizeInBytes());
  EXPECT_STREQ("uint8", bool_native_type.ToCString());
  EXPECT(bool_native_type.IsInt());
  EXPECT(bool_native_type.IsPrimitive());
}

// Test that we construct `NativeType` correctly from `Type`.
ISOLATE_UNIT_TEST_CASE(Ffi_NativeType_Struct_FromAbstractType) {
  Zone* Z = thread->zone();

  const char* kScript =
      R"(
      import 'dart:ffi';

      final class MyStruct extends Struct {
        @Int8()
        external int a0;

        external Pointer<Int8> a1;
      }
      )";

  const auto& root_library = Library::Handle(LoadTestScript(kScript));
  const auto& struct_class = Class::Handle(GetClass(root_library, "MyStruct"));
  const auto& struct_type = Type::Handle(struct_class.DeclarationType());

  const char* error = nullptr;
  const auto& native_type =
      NativeType::FromAbstractType(Z, struct_type, &error)->AsCompound();
  EXPECT_NULLPTR(error);

  EXPECT_EQ(2, native_type.members().length());

  const auto& int8_type = *new (Z) NativePrimitiveType(kInt8);
  EXPECT(int8_type.Equals(*native_type.members()[0]));

  EXPECT_EQ(compiler::target::kWordSize,
            native_type.members()[1]->SizeInBytes());
}

}  // namespace ffi
}  // namespace compiler
}  // namespace dart
