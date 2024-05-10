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
// Filename: CodeGenImpl.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Using CodeGen of LLVM for Language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef CODEGENIMPL_HPP
#define CODEGENIMPL_HPP

#include <memory>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Builder<>.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Constants.h>

class ParseTree; // Assuming you have a class representing the parse tree structure

class CodeGenImpl {
public:
  CodeGenImpl(llvm::Module& module) : builder_(module.getContext()) {}

  // Code generation methods for specific node types (examples)
  std::unique_ptr<llvm::Value> generateVariableDeclaration(const ParseTree* node) const;
  std::unique_ptr<llvm/Value> generateIntegerLiteral(const ParseTree* node) const;
  std::unique_ptr<llvm/Value> generateBinaryExpression(const ParseTree* node) const;
  std::unique_ptr<llvm/Value> generateAssignmentExpression(const ParseTree* node) const;

private:
  llvm::IRBuilder<> builder_;
};

#endif // CODEGENIMPL_HPP
