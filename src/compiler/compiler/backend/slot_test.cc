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

#include "include/CODE_api.h"

#include "platform/globals.h"

#include "src/compiler/backend/slot.h"
#include "src/compiler/compiler_state.h"
#include "src/object.h"
#include "src/parser.h"
#include "src/symbols.h"
#include "src/unit_test.h"

namespace Code {

// This is a regression test for b/121271056: there might be a race between
// background compiler and mutator where mutator changes guarded state of
// the field after Slot was created from it. A situation is possible where we
// have a clone of a field with its guarded state set to unknown, however
// Slot::Get for this field returns a Slot created from the previous clone of
// the same field with a known guarded state. In this case we must add *old*
// clone from which the Slot was created to guarded fields and not the new
// clone, because new clone has no guarded state to begin with and thus
// ParsedFunction::AddToGuardedFields(...) would simply ignore it.
// Such slots with inconsistent guarded state that are not in the current
// list of guarded fields arise due to unsuccessful inlining attempts.
// If we built and discard the graph, then guarded fields associated with
// that graph are also discarded. However the slot itself stays behind in
// the global cache.
// Adding old clone would lead to correct rejection of the compilation
// attempt because Slot type information is different from the current guarded
// state of the field.
TEST_CASE(SlotFromGuardedField) {
  if (!FLAG_use_field_guards) {
    return;
  }

  TransitionNativeToVM transition(thread);
  Zone* zone = thread->zone();

  // Setup: create dummy class, function and a field.
  const Class& dummy_class = Class::Handle(Class::New(
      Library::Handle(), String::Handle(Symbols::New(thread, "DummyClass")),
      Script::Handle(), TokenPosition::kNoSource));
  dummy_class.set_is_synthesized_class_unsafe();

  const FunctionType& signature = FunctionType::ZoneHandle(FunctionType::New());
  const Function& dummy_function = Function::ZoneHandle(
      Function::New(signature, String::Handle(Symbols::New(thread, "foo")),
                    UntaggedFunction::kRegularFunction, false, false, false,
                    false, false, dummy_class, TokenPosition::kMinSource));

  const Field& field = Field::Handle(
      Field::New(String::Handle(Symbols::New(thread, "field")),
                 /*is_static=*/false, /*is_final=*/false, /*is_const=*/false,
                 /*is_reflectable=*/true, /*is_late=*/false, dummy_class,
                 Object::dynamic_type(), TokenPosition::kMinSource,
                 TokenPosition::kMinSource));

  // Set non-trivial guarded state on the field.
  field.set_guarded_cid_unsafe(kSmiCid);
  field.set_is_nullable_unsafe(false);

  // Enter compiler state.
  CompilerState compiler_state(thread, /*is_aot=*/false,
                               /*is_optimizing=*/true);

  const Field& field_clone_1 = Field::ZoneHandle(field.CloneFromOriginal());
  const Field& field_clone_2 = Field::ZoneHandle(field.CloneFromOriginal());

  // Check that Slot::Get() returns correctly canonicalized and configured
  // slot that matches properties of the field.
  ParsedFunction* parsed_function =
      new (zone) ParsedFunction(thread, dummy_function);
  const Slot& slot1 = Slot::Get(field_clone_1, parsed_function);
  const Slot& slot2 = Slot::Get(field_clone_2, parsed_function);
  EXPECT_EQ(&slot1, &slot2);
  EXPECT(slot1.is_guarded_field());
  EXPECT(!slot1.type().is_nullable());
  EXPECT_EQ(kSmiCid, slot1.type().ToCid());

  // Check that the field was added (once) to the list of guarded fields.
  EXPECT_EQ(1, parsed_function->guarded_fields()->Length());
  EXPECT(parsed_function->guarded_fields()->HasKey(&field_clone_1));

  // Change the guarded state of the field to "unknown" - emulating concurrent
  // modification of the guarded state in mutator) and create a new clone of
  // the field.
  field.set_guarded_cid_unsafe(kDynamicCid);
  field.set_is_nullable_unsafe(true);
  const Field& field_clone_3 = Field::ZoneHandle(field.CloneFromOriginal());

  // Slot::Get must return the same slot and add the field from which it
  // was created to the guarded fields list.
  ParsedFunction* parsed_function2 =
      new (zone) ParsedFunction(thread, dummy_function);
  const Slot& slot3 = Slot::Get(field_clone_3, parsed_function2);
  EXPECT_EQ(&slot1, &slot3);
  EXPECT_EQ(1, parsed_function2->guarded_fields()->Length());
  EXPECT(parsed_function2->guarded_fields()->HasKey(&field_clone_1));
}

}  // namespace dart
