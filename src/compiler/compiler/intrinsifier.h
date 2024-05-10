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

#ifndef RUNTIME_VM_COMPILER_INTRINSIFIER_H_
#define RUNTIME_VM_COMPILER_INTRINSIFIER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"
#include "src/compiler/asm_intrinsifier.h"
#include "src/compiler/graph_intrinsifier.h"
#include "src/compiler/method_recognizer.h"

namespace Code {

// Forward declarations.
class FlowGraphCompiler;
class Function;
class ParsedFunction;

namespace compiler {
class Assembler;
class Label;

class Intrinsifier : public AllStatic {
 public:
  static bool Intrinsify(const ParsedFunction& parsed_function,
                         FlowGraphCompiler* compiler);

  static void InitializeState();

 private:
  static bool CanIntrinsify(const ParsedFunction& parsed_function);
};

}  // namespace compiler
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_INTRINSIFIER_H_
