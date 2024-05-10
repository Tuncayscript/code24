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
// Filename: ParseTree.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Creating Methods of language
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef PARSETREE_HPP
#define PARSETREE_HPP

#include <string>
#include <vector>

class ParseTreeVisitor {
public:
  virtual ~ParseTreeVisitor() {}
  virtual void visit(const ParseTree* node) = 0;
  // Add virtual methods for each node type (e.g., visitVariableDeclaration, visitIfStatement)
};

class ParseTree {
public:
  // Constructor (implementation details depend on your parser library)
  ParseTree();

  // Destructor (implementation details depend on your parser library)
  ~ParseTree();

  // Accessors
  const std::string& getType() const { return type_; }
  const std::string& getText() const { return text_; }
  size_t getChildCount() const { return children_.size(); }
  ParseTree* getChild(size_t index) const;
  // (Optional) ParseTree* getParent() const; (if parent information is stored)

  // Navigation and Analysis
  bool isLeaf() const;
  ParseTree* findFirstChildByType(const std::string& type) const;
  std::vector<ParseTree*> findAllChildrenByType(const std::string& type) const;
  std::vector<ParseTree*> getDescendantsByType(const std::string& type) const;
  bool isDominatedBy(const ParseTree* other) const;

  // Code Analysis and Refactoring
  bool isConstantExpression() const;
  bool isSideEffectFree() const;
  ParseTree* extractSubtree(size_t start, size_t end) const;
  void replaceNode(const ParseTree* newNode);
  void insertNodeBefore(const ParseTree* newNode);
  void insertNodeAfter(const ParseTree* newNode);

  // Code Generation and Transformation
  std::string toCodeString() const;
  ParseTree* simplifyExpression() const;
  void inlineVariable(const std::string& varName);
  std::string convertToString(const ParseTree* node) const;

  // Integration and Advanced Functionality (Optional, requires additional implementation)
  Symbol* getSymbol(const std::string& name) const; // (requires symbol table integration)
  std::vector<ParseTree*> findUsages(const std::string& identifier) const;
  // ... (other advanced methods)

  // Allow visitors to perform analysis on the tree
  void accept(ParseTreeVisitor* visitor) const {
    visitor->visit(this);
    for (size_t i = 0; i < getChildCount(); ++i) {
      getChild(i)->accept(visitor);
    }
  }

private:
  std::string type_;  // Node type (e.g., "VariableDeclaration", "IfStatement")
  std::string text_;   // Text content of the node (e.g., variable name, operator)
  std::vector<ParseTree*> children_; // List of child nodes
  std::vector<ParseTree*> parent_;   // Pointer to parent node (if applicable)

  // Implementation details for member functions (to be implemented in a separate .cpp file)
};

#endif // PARSETREE_HPP

