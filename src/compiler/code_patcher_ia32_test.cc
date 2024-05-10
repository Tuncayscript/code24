// Copyright (c) 2011, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/globals.h"
#if defined(TARGET_ARCH_IA32)

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

  __ LoadObject(ECX, ic_data);
  __ Call(StubCode::OneArgCheckInlineCache());
  __ ret();
}

ASSEMBLER_TEST_RUN(IcDataAccess, test) {
  uword end = test->payload_start() + test->code().Size();
  uword return_address = end - 1;  // sizeof(ret)
  ICData& ic_data = ICData::Handle();
  CodePatcher::GetInstanceCallAt(return_address, test->code(), &ic_data);
  EXPECT_STREQ("targetFunction",
               String::Handle(ic_data.target_name()).ToCString());
  EXPECT_EQ(1, ic_data.NumArgsTested());
  EXPECT_EQ(0, ic_data.NumberOfChecks());
}

}  // namespace dart

#endif  // TARGET_ARCH_IA32
