/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Filename: CodeGen.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Using CodeGen of LLVM for Language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include <memory>
#include <llvm/IR/Module.h>

class ParseTree; // Assuming you have a class representing the parse tree structure

class CodeGen {
public:
  CodeGen(llvm::Module& module);
  std::unique_ptr<llvm::Value> generateCode(const ParseTree* node) const;

private:
  std::unique_ptr<llvm::Value> generateIR(const ParseTree* node) const;
  std::unique_ptr<CodeGenImpl> impl_;
};

#endif // CODEGEN_HPP
