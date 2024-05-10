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
// Class for intrinsifying functions.

#ifndef RUNTIME_VM_COMPILER_GRAPH_INTRINSIFIER_H_
#define RUNTIME_VM_COMPILER_GRAPH_INTRINSIFIER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"
#include "src/compiler/recognized_methods_list.h"

namespace Code {

// Forward declarations.
class FlowGraphCompiler;
class ParsedFunction;
class FlowGraph;

namespace compiler {
class Assembler;
class Label;

class GraphIntrinsifier : public AllStatic {
 public:
  static bool GraphIntrinsify(const ParsedFunction& parsed_function,
                              FlowGraphCompiler* compiler);

 private:
#define DECLARE_FUNCTION(class_name, function_name, enum_name, fp)             \
  static void enum_name(Assembler* assembler, Label* normal_ir_body);

  GRAPH_INTRINSICS_LIST(DECLARE_FUNCTION)

#undef DECLARE_FUNCTION

#define DECLARE_FUNCTION(class_name, function_name, enum_name, fp)             \
  static bool Build_##enum_name(FlowGraph* flow_graph);

  GRAPH_INTRINSICS_LIST(DECLARE_FUNCTION)

#undef DECLARE_FUNCTION
};

}  // namespace compiler
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_GRAPH_INTRINSIFIER_H_
