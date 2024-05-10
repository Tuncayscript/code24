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

#include "src/heap/weak_code.h"

#include "platform/assert.h"

#include "src/code_patcher.h"
#include "src/hash_table.h"
#include "src/object.h"
#include "src/runtime_entry.h"
#include "src/stack_frame.h"

namespace Code {

class CodeTraits {
 public:
  static const char* Name() { return "CodeTraits"; }
  static bool ReportStats() { return false; }
  static bool IsMatch(const Object& a, const Object& b) {
    return a.ptr() == b.ptr();
  }
  static uword Hash(const Object& key) { return Code::Cast(key).Hash(); }
};

typedef UnorderedHashSet<CodeTraits, WeakArrayStorageTraits> WeakCodeSet;

bool WeakCodeReferences::HasCodes() const {
  return !array_.IsNull() && (array_.Length() > 0);
}

void WeakCodeReferences::Register(const Code& value) {
  WeakCodeSet set(array_.IsNull() ? HashTables::New<WeakCodeSet>(4, Heap::kOld)
                                  : array_.ptr());
  set.Insert(value);
  UpdateArrayTo(set.Release());
}

void WeakCodeReferences::DisableCode(bool are_mutators_stopped) {
#if defined(CODE_PRECOMPILED_RUNTIME)
  ASSERT(array_.IsNull());
  return;
#else
  // Ensure mutators see empty code_objects only after code was deoptimized.
  DEBUG_ASSERT(
      IsolateGroup::Current()->program_lock()->IsCurrentThreadWriter());

  if (array_.IsNull()) {
    return;
  }

  WeakCodeSet set(array_.ptr());

  auto isolate_group = IsolateGroup::Current();
  auto disable_code_fun = [&]() {
    Code& code = Code::Handle();
    isolate_group->ForEachIsolate(
        [&](Isolate* isolate) {
          auto mutator_thread = isolate->mutator_thread();
          if (mutator_thread == nullptr) {
            return;
          }
          DartFrameIterator iterator(
              mutator_thread, StackFrameIterator::kAllowCrossThreadIteration);
          StackFrame* frame = iterator.NextFrame();
          while (frame != nullptr) {
            code = frame->LookupDartCode();

            if (set.ContainsKey(code)) {
              ReportDeoptimization(code);
              DeoptimizeAt(mutator_thread, code, frame);
            }
            frame = iterator.NextFrame();
          }
        },
        /*at_safepoint=*/true);

    // Switch functions that use dependent code to unoptimized code.
    Object& owner = Object::Handle();
    Function& function = Function::Handle();
    WeakCodeSet::Iterator it(&set);
    while (it.MoveNext()) {
      code ^= set.GetKey(it.Current());
      if (code.IsNull()) {
        // Code was garbage collected already.
        continue;
      }
      owner = code.owner();
      if (owner.IsFunction()) {
        function ^= owner.ptr();
      } else if (owner.IsClass()) {
        Class& cls = Class::Handle();
        cls ^= owner.ptr();
        cls.DisableAllocationStub();
        continue;
      } else if (owner.IsNull()) {
        code.Print();
        continue;
      }

      // Only optimized code can make dependencies (assumptions) about CHA /
      // field guards and might need to be deoptimized if those assumptions no
      // longer hold.
      // See similar assertions when code gets registered in
      // `Field::RegisterDependentCode` and `Class::RegisterCHACode`.
      ASSERT(code.is_optimized());
      ASSERT(function.unoptimized_code() != code.ptr());

      // If function uses dependent code switch it to unoptimized.
      if (function.CurrentCode() == code.ptr()) {
        ReportSwitchingCode(code);
        function.SwitchToUnoptimizedCode();
      } else {
        // Make non-OSR code non-entrant.
        if (!code.IsDisabled()) {
          ReportSwitchingCode(code);
          code.DisableDartCode();
        }
      }
    }

    UpdateArrayTo(WeakArray::Handle());
  };

  // Deoptimize stacks and disable code (with mutators stopped if they are not
  // stopped yet).
  if (are_mutators_stopped) {
    disable_code_fun();
  } else {
    isolate_group->RunWithStoppedMutators(disable_code_fun);
  }

  set.Release();

#endif  // defined(CODE_PRECOMPILED_RUNTIME)
}

}  // namespace dart
