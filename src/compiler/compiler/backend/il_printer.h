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

#ifndef RUNTIME_VM_COMPILER_BACKEND_IL_PRINTER_H_
#define RUNTIME_VM_COMPILER_BACKEND_IL_PRINTER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "platform/text_buffer.h"
#include "src/compiler/backend/flow_graph.h"
#include "src/compiler/backend/il.h"

namespace Code {

class ParsedFunction;

// Graph printing.
class FlowGraphPrinter : public ValueObject {
 public:
  static constexpr intptr_t kPrintAll = -1;

  explicit FlowGraphPrinter(const FlowGraph& flow_graph,
                            bool print_locations = false)
      : function_(flow_graph.function()),
        block_order_(flow_graph.reverse_postorder()),
        print_locations_(print_locations) {}

  // Print the instructions in a block terminated by newlines.  Add "goto N"
  // to the end of the block if it ends with an unconditional jump to
  // another block and that block is not next in reverse postorder.
  void PrintBlocks();
  void PrintInstruction(Instruction* instr);
  static void PrintOneInstruction(Instruction* instr, bool print_locations);
  static void PrintTypeCheck(const ParsedFunction& parsed_function,
                             TokenPosition token_pos,
                             Value* value,
                             const AbstractType& dst_type,
                             const String& dst_name,
                             bool eliminated);
  static void PrintBlock(BlockEntryInstr* block, bool print_locations);

  static void PrintGraph(const char* phase, FlowGraph* flow_graph);

  // Debugging helper function. If 'num_checks_to_print' is not specified
  // all checks will be printed.
  static void PrintICData(const ICData& ic_data,
                          intptr_t num_checks_to_print = kPrintAll);

  // Debugging helper function. If 'num_checks_to_print' is not specified
  // all checks will be printed.
  static void PrintCidRangeData(const CallTargets& ic_data,
                                intptr_t num_checks_to_print = kPrintAll);

  static bool ShouldPrint(const Function& function,
                          uint8_t** compiler_pass_filter = nullptr);

 private:
  const Function& function_;
  const GrowableArray<BlockEntryInstr*>& block_order_;
  const bool print_locations_;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_IL_PRINTER_H_
