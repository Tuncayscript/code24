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

#ifndef RUNTIME_VM_COMPILER_FRONTEND_FLOW_GRAPH_BUILDER_H_
#define RUNTIME_VM_COMPILER_FRONTEND_FLOW_GRAPH_BUILDER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "platform/assert.h"
#include "platform/globals.h"
#include "src/allocation.h"
#include "src/compiler/backend/flow_graph.h"
#include "src/compiler/backend/il.h"
#include "src/growable_array.h"
#include "src/raw_object.h"

namespace Code {

// A class to collect the exits from an inlined function during graph
// construction so they can be plugged into the caller's flow graph.
class InlineExitCollector : public ZoneAllocated {
 public:
  InlineExitCollector(FlowGraph* caller_graph, Definition* call)
      : caller_graph_(caller_graph), call_(call), exits_(4) {}

  void AddExit(DartReturnInstr* exit);

  void Union(const InlineExitCollector* other);

  // Before replacing a call with a graph, the outer environment needs to be
  // attached to each instruction in the callee graph and the caller graph
  // needs to have its block and instruction ID state updated.
  // Additionally we need to remove all unreachable exits from the list of
  // collected exits.
  void PrepareGraphs(FlowGraph* callee_graph);

  // Inline a graph at a call site.
  //
  // Assumes the callee is in SSA with a correct dominator tree and use
  // lists.
  //
  // After inlining the caller graph will have correctly adjusted the use
  // lists.  The block orders will need to be recomputed.
  void ReplaceCall(BlockEntryInstr* callee_entry);

 private:
  struct Data {
    BlockEntryInstr* exit_block;
    DartReturnInstr* exit_return;
  };

  BlockEntryInstr* ExitBlockAt(intptr_t i) const {
    ASSERT(exits_[i].exit_block != nullptr);
    return exits_[i].exit_block;
  }

  Instruction* LastInstructionAt(intptr_t i) const {
    return ReturnAt(i)->previous();
  }

  Value* ValueAt(intptr_t i) const { return ReturnAt(i)->value(); }

  DartReturnInstr* ReturnAt(intptr_t i) const { return exits_[i].exit_return; }

  static int LowestBlockIdFirst(const Data* a, const Data* b);
  void SortExits();
  void RemoveUnreachableExits(FlowGraph* callee_graph);

  Definition* JoinReturns(BlockEntryInstr** exit_block,
                          Instruction** last_instruction,
                          intptr_t try_index);

  Zone* zone() const { return caller_graph_->zone(); }

  FlowGraph* caller_graph_;
  Definition* call_;
  GrowableArray<Data> exits_;
};

bool SimpleInstanceOfType(const AbstractType& type);
uword FindDoubleConstant(double value);

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FRONTEND_FLOW_GRAPH_BUILDER_H_
