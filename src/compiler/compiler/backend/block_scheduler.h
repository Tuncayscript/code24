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

#ifndef RUNTIME_VM_COMPILER_BACKEND_BLOCK_SCHEDULER_H_
#define RUNTIME_VM_COMPILER_BACKEND_BLOCK_SCHEDULER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"

namespace Code {

class FlowGraph;

class BlockScheduler : public AllStatic {
 public:
  static void AssignEdgeWeights(FlowGraph* flow_graph);
  static void ReorderBlocks(FlowGraph* flow_graph);

 private:
  static void ReorderBlocksAOT(FlowGraph* flow_graph);
  static void ReorderBlocksJIT(FlowGraph* flow_graph);
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_BLOCK_SCHEDULER_H_
