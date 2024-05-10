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

#ifndef RUNTIME_VM_COMPILER_BACKEND_CONSTANT_PROPAGATOR_H_
#define RUNTIME_VM_COMPILER_BACKEND_CONSTANT_PROPAGATOR_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/backend/flow_graph.h"
#include "src/compiler/backend/il.h"

namespace Code {

// Sparse conditional constant propagation and unreachable code elimination.
// Assumes that use lists are computed and preserves them.
class ConstantPropagator : public FlowGraphVisitor {
 public:
  ConstantPropagator(FlowGraph* graph,
                     const GrowableArray<BlockEntryInstr*>& ignored);

  static void Optimize(FlowGraph* graph);

  // (1) Visit branches to optimize away unreachable blocks discovered  by range
  // analysis.
  // (2) Eliminate branches that have the same true- and false-target: For
  // example, this occurs after expressions like
  //
  // if (a == null || b == null) {
  //   ...
  // }
  //
  // where b is known to be null.
  static void OptimizeBranches(FlowGraph* graph);

  // Used to initialize the abstract value of definitions.
  static ObjectPtr Unknown() { return Object::unknown_constant().ptr(); }

 private:
  void InsertRedefinitionsAfterEqualityComparisons();
  void Analyze();
  void Transform();
  // Tries to replace uses of [defn] with a constant, returns true if
  // successful. The [value] is used as a temporary handle.
  bool TransformDefinition(Definition* defn);
  void EliminateRedundantBranches();

  void SetReachable(BlockEntryInstr* block);
  bool SetValue(Definition* definition, const Object& value);

  // Phi might be viewed as redundant based on current reachability of
  // predecessor blocks (i.e. the same definition is flowing from all
  // reachable predecessors). We can use this information to constant
  // fold phi(x) == x and phi(x) != x comparisons.
  Definition* UnwrapPhi(Definition* defn);
  void MarkUnwrappedPhi(Definition* defn);

  // Assign the join (least upper bound) of a pair of abstract values to the
  // first one.
  void Join(Object* left, const Object& right);

  bool IsUnknown(const Object& value) { return value.ptr() == unknown_.ptr(); }
  bool IsNonConstant(const Object& value) {
    return value.ptr() == non_constant_.ptr();
  }
  bool IsConstant(const Object& value) {
    return !IsNonConstant(value) && !IsUnknown(value);
  }

  void VisitBinaryIntegerOp(BinaryIntegerOpInstr* binary_op);
  void VisitUnaryIntegerOp(UnaryIntegerOpInstr* unary_op);

  virtual void VisitBlocks() { UNREACHABLE(); }

#define DECLARE_VISIT(type, attrs) virtual void Visit##type(type##Instr* instr);
  FOR_EACH_INSTRUCTION(DECLARE_VISIT)

#undef DECLARE_VISIT
  // Structure tracking visit counts for phis. Used to detect infinite loops.
  struct PhiInfo {
    PhiInstr* phi;
    intptr_t visit_count;
  };

  // Returns PhiInfo associated with the given phi. Note that this
  // pointer can be invalidated by subsequent call to GetPhiInfo and
  // thus should not be stored anywhere.
  PhiInfo* GetPhiInfo(PhiInstr* phi);

  FlowGraph* graph_;

  // Sentinels for unknown constant and non-constant values.
  const Object& unknown_;
  const Object& non_constant_;

  // Temporary handle used in [TransformDefinition].
  Object& constant_value_;

  // Analysis results. For each block, a reachability bit.  Indexed by
  // preorder number.
  BitVector* reachable_;

  // Bitvector of phis that were "unwrapped" into one of their inputs
  // when visiting one of their uses. These uses of these phis
  // should be revisited if reachability of the predecessor blocks
  // changes even if that does not change constant value of the phi.
  BitVector* unwrapped_phis_;

  // List of visited phis indexed by their id (stored as pass specific id on
  // a phi instruction).
  GrowableArray<PhiInfo> phis_;

  // Worklists of blocks and definitions.
  GrowableArray<BlockEntryInstr*> block_worklist_;
  DefinitionWorklist definition_worklist_;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_CONSTANT_PROPAGATOR_H_
