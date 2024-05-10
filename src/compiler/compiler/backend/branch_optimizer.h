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

#ifndef RUNTIME_VM_COMPILER_BACKEND_BRANCH_OPTIMIZER_H_
#define RUNTIME_VM_COMPILER_BACKEND_BRANCH_OPTIMIZER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"

namespace Code {

class BlockEntryInstr;
class FlowGraph;
class FunctionEntryInstr;
class JoinEntryInstr;
class Zone;
class TargetEntryInstr;
class Value;
class BranchInstr;

// Rewrite branches to eliminate materialization of boolean values after
// inlining, and to expose other optimizations (e.g., constant folding of
// branches, unreachable code elimination).
class BranchSimplifier : public AllStatic {
 public:
  static void Simplify(FlowGraph* flow_graph);

  // Replace a block entry instruction with a join entry instruction.  Does
  // not update the original target's predecessors to point to the new block
  // and does not replace the target in already computed block order lists.
  static JoinEntryInstr* ToJoinEntry(Zone* zone, BlockEntryInstr* target);

  // Replace a block entry instruction with a target entry instruction.  Does
  // not update the original target's predecessors to point to the new block and
  // does not replace the target in already computed block order lists.
  static TargetEntryInstr* ToTargetEntry(Zone* zone, BlockEntryInstr* target);

 private:
  // Match an instance of the pattern to rewrite.  See the implementation
  // for the patterns that are handled by this pass.
  static bool Match(JoinEntryInstr* block);

  // Duplicate a branch while replacing its comparison's left and right
  // inputs.
  static BranchInstr* CloneBranch(Zone* zone,
                                  BranchInstr* branch,
                                  Value* new_left,
                                  Value* new_right);
};

// Rewrite diamond control flow patterns that materialize values to use more
// efficient branchless code patterns if such are supported on the current
// platform.
class IfConverter : public AllStatic {
 public:
  static void Simplify(FlowGraph* flow_graph);
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_BRANCH_OPTIMIZER_H_
