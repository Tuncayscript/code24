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

#include "src/globals.h"
#if defined(TARGET_ARCH_ARM64)

#include "src/code_patcher.h"
#include "src/compiler/assembler/assembler.h"
#include "src/CODE_entry.h"
#include "src/instructions.h"
#include "src/native_entry.h"
#include "src/native_entry_test.h"
#include "src/runtime_entry.h"
#include "src/stub_code.h"
#include "src/symbols.h"
#include "src/unit_test.h"

namespace Code {

#define __ assembler->

ASSEMBLER_TEST_GENERATE(IcDataAccess, assembler) {
  Thread* thread = Thread::Current();
  const String& class_name = String::Handle(Symbols::New(thread, "ownerClass"));
  const Script& script = Script::Handle();
  const Class& owner_class = Class::Handle(Class::New(
      Library::Handle(), class_name, script, TokenPosition::kNoSource));
  const String& function_name =
      String::Handle(Symbols::New(thread, "callerFunction"));
  const FunctionType& signature = FunctionType::ZoneHandle(FunctionType::New());
  const Function& function = Function::Handle(Function::New(
      signature, function_name, UntaggedFunction::kRegularFunction, true, false,
      false, false, false, owner_class, TokenPosition::kNoSource));

  const String& target_name =
      String::Handle(Symbols::New(thread, "targetFunction"));
  const intptr_t kTypeArgsLen = 0;
  const intptr_t kNumArgs = 1;
  const Array& args_descriptor = Array::Handle(ArgumentsDescriptor::NewBoxed(
      kTypeArgsLen, kNumArgs, Object::null_array()));
  const ICData& ic_data = ICData::ZoneHandle(ICData::New(
      function, target_name, args_descriptor, 15, 1, ICData::kInstance));
  const Code& stub = StubCode::OneArgCheckInlineCache();

  // Code is generated, but not executed. Just parsed with CodePatcher.
  __ set_constant_pool_allowed(true);  // Uninitialized pp is OK.
  SPILLS_LR_TO_FRAME({});              // Clobbered LR is OK.

  compiler::ObjectPoolBuilder& op = __ object_pool_builder();
  const intptr_t ic_data_index =
      op.AddObject(ic_data, ObjectPool::Patchability::kPatchable);
  const intptr_t stub_index =
      op.AddObject(stub, ObjectPool::Patchability::kPatchable);
  ASSERT((ic_data_index + 1) == stub_index);
  __ LoadDoubleWordFromPoolIndex(R5, CODE_REG, ic_data_index);
  __ Call(compiler::FieldAddress(
      CODE_REG, Code::entry_point_offset(Code::EntryKind::kMonomorphic)));
  RESTORES_LR_FROM_FRAME({});  // Clobbered LR is OK.
  __ ret();
}

ASSEMBLER_TEST_RUN(IcDataAccess, test) {
  uword end = test->payload_start() + test->code().Size();
  uword return_address = end - Instr::kInstrSize;
  ICData& ic_data = ICData::Handle();
  CodePatcher::GetInstanceCallAt(return_address, test->code(), &ic_data);
  EXPECT_STREQ("targetFunction",
               String::Handle(ic_data.target_name()).ToCString());
  EXPECT_EQ(1, ic_data.NumArgsTested());
  EXPECT_EQ(0, ic_data.NumberOfChecks());
}

}  // namespace dart

#endif  // defined TARGET_ARCH_ARM64
