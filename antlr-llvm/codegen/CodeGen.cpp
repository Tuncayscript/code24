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
// Filename: CodeGen.cpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Using CodeGen of LLVM for Language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#include "CodeGen.hpp"

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Constants.h>
#include <llvm/Support/raw_ostream.h>

class CodeGenImpl {
public:
  CodeGenImpl(llvm::Module& module) : builder_(module.getContext()) {}

  // Code generation methods for specific node types (examples)
  std::unique_ptr<llvm::Value> generateVariableDeclaration(const ParseTree* node) const;
  std::unique_ptr<llvm::Value> generateIntegerLiteral(const ParseTree* node) const;
  std::unique_ptr<llvm::Value> generateBinaryExpression(const ParseTree* node) const;

private:
  llvm::IRBuilder<> builder_;
};

CodeGen::CodeGen(llvm::Module& module) : impl_(std::make_unique<CodeGenImpl>(module)) {}

std::unique_ptr<llvm::Value> CodeGen::generateCode(const ParseTree* node) const {
  return generateIR(node);
}

std::unique_ptr<llvm::Value> CodeGen::generateIR(const ParseTree* node) const {
  if (node == nullptr) {
    return nullptr; // Handle empty tree
  }

  // Delegate to helper methods based on node type
  return impl_->generateVariableDeclaration(node)
         || impl_->generateIntegerLiteral(node)
         || impl_->generateBinaryExpression(node);
  // Add cases for other node types and delegate to helper methods
}

// Implementations of helper methods in CodeGenImpl.cpp (not shown here)
