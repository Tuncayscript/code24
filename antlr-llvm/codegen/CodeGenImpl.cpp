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
// Filename: CodeGenImpl.cpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Implementation of LLVM CodeGen for Language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#include "CodeGenImpl.hpp"

#include <llvm/IR/Type.h>
#include <sstream> // for error messages

#include "CodeGenImpl.hpp"

#include <llvm/IR/Type.h>
#include <sstream> // for error messages

std::unique_ptr<llvm::Value> CodeGenImpl::generateVariableDeclaration(const ParseTree* node) const {
  // Assuming identifier is stored in the text field of the node
  std::string variableName = node->getText();

  // Get the data type (replace with your logic to determine type from the parse tree)
  llvm::Type* type = determineVariableType(node); // Replace with your type lookup logic

  // Check if type information is available
  if (!type) {
    std::cerr << "Error: Missing type information for variable: " << variableName << std::endl;
    return nullptr;
  }

  // Create an alloca instruction to allocate memory for the variable
  return builder_.CreateAlloca(type, nullptr, variableName);
}

std::unique_ptr<llvm::Value> CodeGenImpl::generateIntegerLiteral(const ParseTree* node) const {
  // Assuming text field of the node stores the integer value as a string
  int value;
  try {
    value = std::stoi(node->getText());
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: Invalid integer literal: " << node->getText() << std::endl;
    return nullptr;
  }

  // Create an integer constant
  return llvm::ConstantInt::get(builder_.getInt32Ty(), value);
}

std::unique_ptr<llvm::Value> CodeGenImpl::generateBinaryExpression(const ParseTree* node) const {
  // Get left and right operands by generating IR for child nodes
  std::unique_ptr<llvm::Value> left = generateIR(node->getChild(0));
  std::unique_ptr<llvm::Value> right = generateIR(node->getChild(1));

  // Check if either operand generation failed or types are incompatible
  if (!left || !right || left->getType() != right->getType()) {
    std::stringstream ss;
    ss << "Error: Incompatible operand types in expression: ";
    if (left) {
      ss << left->getType()->getName();
    } else {
      ss << "(failed to generate left operand)";
    }
    ss << " vs ";
    if (right) {
      ss << right->getType()->getName();
    } else {
      ss << "(failed to generate right operand)";
    }
    ss << std::endl;
    std::cerr << ss.str();
    return nullptr;
  }

  // Get the operator from the text field of the node (replace with your logic)
  std::string op = node->getText();

  // Create instructions based on the operator (implement other operators)
  if (op == "+") {
    return builder_.CreateAdd(left.get(), right.get(), "addtmp");
  } else if (op == "-") {
    return builder_.CreateSub(left.get(), right.get(), "subtmp");
  } else {
    // Handle unsupported operators (optional: throw an exception or log an error)
    std::cerr << "Error: Unsupported operator: " << op << std::endl;
    return nullptr;
  }
}

// Function to generate code for assignment expressions
std::unique_ptr<llvm::Value> CodeGenImpl::generateAssignmentExpression(const ParseTree* node) const {
  // Get the left and right operands (assuming left side is a variable)
  std::unique_ptr<llvm::Value> variable = generateIR(node->getChild(0));
  std::unique_ptr<llvm::Value> value = generateIR(node->getChild(1));

  // Check if left side is a valid variable (allocation instruction)
  if (!variable || !variable->getAllocatedType()) {
    std::cerr << "Error: Invalid left side of assignment (not a variable)" << std::endl;
    return nullptr;
  }

  // Check for type compatibility between variable and value
  if (variable->getType() != value->getType()) {
    std::cerr << "Error: Incompatible types in assignment: " << variable->getType()->getName()
              << " vs " << value->getType()->getName() << std::endl;
    return nullptr;
  }

  // Generate a store instruction to assign the value to the variable
  builder_.CreateStore(value.get(), variable.get());

  // Assignment expressions usually don't return a value, but you can return the value being assigned if needed
  return value; // Optional: return value;
}
