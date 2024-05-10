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
#include "src/object.h"
#include "src/symbols.h"

namespace Code {

// Add function to a class and that class to the class dictionary so that
// frame walking can be used.
const Function& RegisterFakeFunction(const char* name, const Code& code) {
  Thread* thread = Thread::Current();
  const String& class_name = String::Handle(Symbols::New(thread, "ownerClass"));
  const Script& script = Script::Handle();
  const Library& lib = Library::Handle(Library::CoreLibrary());
  const Class& owner_class = Class::Handle(
      Class::New(lib, class_name, script, TokenPosition::kNoSource));
  const String& function_name = String::ZoneHandle(Symbols::New(thread, name));
  const FunctionType& signature = FunctionType::ZoneHandle(FunctionType::New());
  Function& function = Function::ZoneHandle(Function::New(
      signature, function_name, UntaggedFunction::kRegularFunction, true, false,
      false, false, false, owner_class, TokenPosition::kNoSource));
  const Array& functions = Array::Handle(Array::New(1));
  functions.SetAt(0, function);
  {
    SafepointWriteRwLocker ml(thread, thread->isolate_group()->program_lock());
    owner_class.SetFunctions(functions);
  }
  lib.AddClass(owner_class);
  function.AttachCode(code);
  return function;
}

}  // namespace dart
