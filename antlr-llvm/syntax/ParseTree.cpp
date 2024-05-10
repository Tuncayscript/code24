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
// Filename: ParseTree.cpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Creating methods of language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#include "ParseTree.hpp"
#include "antlr4-runtime.h"

using namespace antlr4;

ParseTree::ParseTree(const std::string& type, Ref<tree::Tree> tree) : type_(type), tree_(tree) {}

bool ParseTree::isType(const std::string& expectedType) const {
  return type_ == expectedType;
}

std::string ParseTree::getText() const {
  if (tree_ == nullptr) {
    return "";
  }
  return tree_->getText();
}

int ParseTree::getChildCount() const {
  if (tree_ == nullptr) {
    return 0;
  }
  return tree_->getChildCount();
}

ParseTree* ParseTree::getChild(size_t index) const {
  if (tree_ == nullptr || index >= tree_->getChildCount()) {
    return nullptr;
  }
  return new ParseTree(tree_->getChild(index)->getText(), tree_->getChild(index));
}

int ParseTree::getLine() const {
  if (tree_ == nullptr || !tree_->getSourceInterval().isPresent()) {
    return -1;
  }
  return tree_->getSourceInterval().get().a + 1; // Adjust for 1-based indexing
}

ParseTree* ParseTree::getParent() const {
  if (tree_ == nullptr || !tree_->getParent().isNonnull()) {
    return nullptr;
  }
  return new ParseTree(tree_->getParent()->getText(), tree_->getParent());
}

bool ParseTree::simplifyExpression() const {
  // Example: Constant folding for binary operators
  if (type_ == "+" || type_ == "-" || type_ == "*" || type_ == "/") {
    if (getChild(0)->isConstantExpression() && getChild(1)->isConstantExpression()) {
      // Extract constant values and perform the operation, replacing the node with the result
      int value1 = std::stoi(getChild(0)->getText());
      int value2 = std::stoi(getChild(1)->getText());
      int result = (type_ == "+") ? value1 + value2 : (type_ == "-") ? value1 - value2 : 
                     (type_ == "*") ? value1 * value2 : value1 / value2;
      // Replace the current node with a new leaf containing the result
      // (Implementation details depend on your parser library for node creation)
      return true;
    }
  }
  return false;
}


bool ParseTree::isSideEffectFree() const {
  // 1. Base cases (known side-effecting nodes)
  if (type_.find("Assignment") != std::string::npos || 
      type_.find("Call") != std::string::npos || 
      type_ == "Increment" || type_ == "Decrement") {
    return false;
  }

  // 2. Language-specific checks (optional)
  // - Handle constructs that modify state (e.g., pointer arithmetic, I/O operations)
  //   based on the specific language being parsed.

  // 3. Recursively check children
  for (size_t i = 0; i < getChildCount(); ++i) {
    if (!getChild(i)->isSideEffectFree()) {
      return false;
    }
  }

  // 4. Special cases (optional)
  // - Handle specific function calls known to be side-effect free
  //   based on external information (e.g., library documentation).

  return true;
}

ParseTree* ParseTree::findFirstChildByType(const std::string& type) const {
  for (size_t i = 0; i < getChildCount(); ++i) {
    ParseTree* child = getChild(i);
    if (child->isType(type)) {
      return child;
    }
  }
  return nullptr;
}


void ParseTree::inlineVariable(const std::string& varName) {
  // 1. Find the variable declaration within the subtree (optional)
  // - This might require traversing the tree to locate the declaration of the variable.
  // - You can skip this step if variable information is readily available elsewhere.

  // 2. Replace usages of the variable with its value
  for (size_t i = 0; i < getChildCount(); ++i) {
    ParseTree* child = getChild(i);
    if (child->getText() == varName) {
      // Replace the child node with a new leaf containing the declaration value (implementation details depend on your parser library)
    } else {
      child->inlineVariable(varName); // Recursively inline in child subtrees
    }
  }
}

std::string ParseTree::convertToString(const ParseTree* node) const {
  if (node == nullptr) {
    return "";
  }

  // 1. Base case: Leaf node
  if (node->getChildCount() == 0) {
    return node->getText();
  }

  // 2. Build string with node type and child representations
  std::string str = node->type_ + "(";
  for (size_t i = 0; i < node->getChildCount(); ++i) {
    str += convertToString(node->getChild(i));
    if (i < node->getChildCount() - 1) {
      str += ", ";
    }
  }
  str += ")";
  return str;
}

void ParseTree::replaceNode(const ParseTree* newNode) {
  // Check for null pointer or invalid new node
  if (newNode == nullptr) {
    return; // Handle potential errors gracefully
  }

  // Get parent node (assuming parent information is stored)
  ParseTree* parent = getParent();

  // Check if the current node has a parent
  if (parent == nullptr) {
    return; // Handle cases where the node is the root (might require special handling)
  }

  // Find the index of the current node among its parent's children
  size_t index = 0;
  for (; index < parent->getChildCount(); ++index) {
    if (parent->getChild(index) == this) {
      break;
    }
  }

  // Update the parent's child list to replace the current node with the new one
  parent->children_[index] = newNode;

  // Update the new node's parent (assuming the `newNode` has a parent setter)
  newNode->setParent(parent);

  // Detach the current node from its children (optional, if the node has ownership of its children)
  // ... (implementation details depend on your parser library's memory management)
}

