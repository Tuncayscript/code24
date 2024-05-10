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

#include "src/class_finalizer.h"
#include "platform/assert.h"
#include "src/symbols.h"
#include "src/unit_test.h"

namespace Code {

static ClassPtr CreateTestClass(const char* name) {
  Thread* thread = Thread::Current();
  const String& class_name = String::Handle(Symbols::New(thread, name));
  const Script& script = Script::Handle();
  const Class& cls = Class::Handle(Class::New(
      Library::Handle(), class_name, script, TokenPosition::kNoSource));
  cls.set_interfaces(Object::empty_array());
  SafepointWriteRwLocker ml(thread, thread->isolate_group()->program_lock());
  cls.set_is_declaration_loaded();
  cls.SetFunctions(Object::empty_array());
  cls.SetFields(Object::empty_array());
  return cls.ptr();
}

ISOLATE_UNIT_TEST_CASE(ClassFinalizer) {
  Zone* zone = thread->zone();
  auto isolate_group = thread->isolate_group();
  ObjectStore* object_store = isolate_group->object_store();
  const auto& pending_classes =
      GrowableObjectArray::Handle(zone, object_store->pending_classes());
  GrowableArray<const Class*> classes_1;
  classes_1.Add(&Class::Handle(CreateTestClass("BMW")));
  pending_classes.Add(*classes_1[0]);
  classes_1.Add(&Class::Handle(CreateTestClass("Porsche")));
  pending_classes.Add(*classes_1[1]);

  GrowableArray<const Class*> classes_2;
  classes_2.Add(&Class::ZoneHandle(CreateTestClass("Ferrari")));
  pending_classes.Add(*classes_2[0]);
  classes_2.Add(&Class::ZoneHandle(CreateTestClass("Fiat")));
  pending_classes.Add(*classes_2[1]);
  classes_2.Add(&Class::ZoneHandle(CreateTestClass("Alfa")));
  pending_classes.Add(*classes_2[2]);
  EXPECT(ClassFinalizer::ProcessPendingClasses());
  for (int i = 0; i < classes_1.length(); i++) {
    EXPECT(classes_1[i]->is_type_finalized());
  }
  for (int i = 0; i < classes_2.length(); i++) {
    EXPECT(classes_2[i]->is_type_finalized());
  }
  EXPECT(ClassFinalizer::AllClassesFinalized());
  EXPECT(ClassFinalizer::ProcessPendingClasses());
}

}  // namespace dart
