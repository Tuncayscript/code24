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

#include <vector>

#include "src/compiler/backend/il.h"
#include "src/compiler/backend/il_printer.h"
#include "src/compiler/backend/il_test_helper.h"
#include "src/compiler/call_specializer.h"
#include "src/compiler/compiler_pass.h"
#include "src/object.h"
#include "src/unit_test.h"

namespace Code {

ISOLATE_UNIT_TEST_CASE(ReachabilityFence_Simple) {
  // clang-format off
  auto kScript =
      Utils::CStringUniquePtr(OS::SCreate(nullptr,
                                          R"(
      import 'dart:_internal' show reachabilityFence;

      int someGlobal = 0;

      class A {
        int%s a;
      }

      void someFunction(int arg) {
        someGlobal += arg;
      }

      main() {
        final object = A()..a = 10;
        someFunction(object.a%s);
        reachabilityFence(object);
      }
      )",
      TestCase::NullableTag(), TestCase::NullAssertTag()), std::free);
  // clang-format on

  const auto& root_library = Library::Handle(LoadTestScript(kScript.get()));

  Invoke(root_library, "main");

  const auto& function = Function::Handle(GetFunction(root_library, "main"));
  TestPipeline pipeline(function, CompilerPass::kJIT);
  FlowGraph* flow_graph = pipeline.RunPasses({});
  ASSERT(flow_graph != nullptr);

  auto entry = flow_graph->graph_entry()->normal_entry();
  EXPECT(entry != nullptr);

  //  v2 <- AllocateObject(A <not-aliased>) T{A}
  //  ...
  //  [use field of object v2]
  //  ReachabilityFence(v2)
  AllocateObjectInstr* allocate_object = nullptr;
  ReachabilityFenceInstr* fence = nullptr;

  ILMatcher cursor(flow_graph, entry);
  RELEASE_ASSERT(cursor.TryMatch({
      kMoveGlob,
      // Allocate the object.
      {kMatchAndMoveAllocateObject, &allocate_object},
      kMoveGlob,
      // The call.
      kMatchAndMoveStoreStaticField,
      // The fence should not be moved before the call.
      {kMatchAndMoveReachabilityFence, &fence},
  }));

  EXPECT(fence->value()->definition() == allocate_object);
}

ISOLATE_UNIT_TEST_CASE(ReachabilityFence_Loop) {
  // clang-format off
  auto kScript =
      Utils::CStringUniquePtr(OS::SCreate(nullptr, R"(
      import 'dart:_internal' show reachabilityFence;

      int someGlobal = 0;

      class A {
        int%s a;
      }

      @pragma('vm:never-inline')
      A makeSomeA() {
        return A()..a = 10;
      }

      void someFunction(int arg) {
        someGlobal += arg;
      }

      main() {
        final object = makeSomeA();
        for(int i = 0; i < 100000; i++) {
          someFunction(object.a%s);
          reachabilityFence(object);
        }
      }
      )", TestCase::NullableTag(), TestCase::NullAssertTag()), std::free);
  // clang-format on

  const auto& root_library = Library::Handle(LoadTestScript(kScript.get()));

  Invoke(root_library, "main");

  const auto& function = Function::Handle(GetFunction(root_library, "main"));
  TestPipeline pipeline(function, CompilerPass::kJIT);
  FlowGraph* flow_graph = pipeline.RunPasses({});
  ASSERT(flow_graph != nullptr);

  auto entry = flow_graph->graph_entry()->normal_entry();
  EXPECT(entry != nullptr);

  StaticCallInstr* object = nullptr;
  LoadFieldInstr* field_load = nullptr;
  ReachabilityFenceInstr* fence = nullptr;

  ILMatcher cursor(flow_graph, entry);
  RELEASE_ASSERT(cursor.TryMatch(
      {
          // Get the object from some method
          {kMatchAndMoveStaticCall, &object},
          // Load the field outside the loop.
          {kMatchAndMoveLoadField, &field_load},
          // Go into the loop.
          kMatchAndMoveBranchTrue,
          // The fence should not be moved outside of the loop.
          {kMatchAndMoveReachabilityFence, &fence},
      },
      /*insert_before=*/kMoveGlob));

  EXPECT(field_load->instance()->definition() == object);
  EXPECT(fence->value()->definition() == object);
}

ISOLATE_UNIT_TEST_CASE(ReachabilityFence_NoCanonicalize) {
  // clang-format off
  auto kScript =
      Utils::CStringUniquePtr(OS::SCreate(nullptr, R"(
      import 'dart:_internal' show reachabilityFence;

      int someGlobal = 0;

      class A {
        int%s a;
      }

      @pragma('vm:never-inline')
      A makeSomeA() {
        return A()..a = 10;
      }

      void someFunction(int arg) {
        someGlobal += arg;
      }

      main() {
        final object = makeSomeA();
        reachabilityFence(object);
        for(int i = 0; i < 100000; i++) {
          someFunction(object.a%s);
          reachabilityFence(object);
        }
        reachabilityFence(object);
        reachabilityFence(object);
      }
      )", TestCase::NullableTag(), TestCase::NullAssertTag()), std::free);
  // clang-format on

  const auto& root_library = Library::Handle(LoadTestScript(kScript.get()));

  Invoke(root_library, "main");

  const auto& function = Function::Handle(GetFunction(root_library, "main"));
  TestPipeline pipeline(function, CompilerPass::kJIT);
  FlowGraph* flow_graph = pipeline.RunPasses({});
  ASSERT(flow_graph != nullptr);

  auto entry = flow_graph->graph_entry()->normal_entry();
  EXPECT(entry != nullptr);

  StaticCallInstr* object = nullptr;
  ReachabilityFenceInstr* fence1 = nullptr;
  ReachabilityFenceInstr* fence2 = nullptr;
  ReachabilityFenceInstr* fence3 = nullptr;
  ReachabilityFenceInstr* fence4 = nullptr;

  ILMatcher cursor(flow_graph, entry);
  RELEASE_ASSERT(cursor.TryMatch(
      {
          {kMatchAndMoveStaticCall, &object},
          {kMatchAndMoveReachabilityFence, &fence1},
          kMatchAndMoveBranchTrue,
          {kMatchAndMoveReachabilityFence, &fence2},
          kMatchAndMoveBranchFalse,
          {kMatchAndMoveReachabilityFence, &fence3},
          {kMatchAndMoveReachabilityFence, &fence4},
      },
      /*insert_before=*/kMoveGlob));

  EXPECT(fence1->value()->definition() == object);
  EXPECT(fence2->value()->definition() == object);
  EXPECT(fence3->value()->definition() == object);
  EXPECT(fence4->value()->definition() == object);
}

}  // namespace dart
