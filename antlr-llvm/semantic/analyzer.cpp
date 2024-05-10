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
// Filename: analyser.cpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Generally analyizing the Code
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#include <iostream>
#include <memory>
#include <unordered_map> // For symbol table

#include "analyzer.hpp"
#include "ParseTree.hpp" // Assuming your ParseTree class definition

// Assuming your context types provide variable declaration and expression information
namespace Code {

struct SymbolTableEntry {
  std::string name;
  Code::DataType type;
};

class SymbolTable {
public:
  void addVariable(const std::string& name, Code::DataType type) {
    if (symbolTable_.count(name) > 0) {
      // Handle error: duplicate variable declaration
      std::cerr << "Error: Duplicate variable declaration: " << name << "\n";
    } else {
      symbolTable_[name] = {name, type};
    }
  }

  Code::DataType getVariableType(const std::string& name) {
    if (symbolTable_.count(name) == 0) {
      // Handle error: undeclared variable
      std::cerr << "Error: Undeclared variable: " << name << "\n";
      return Code::DataType::Unknown; // Or return a special value for unknown type
    } else {
      return symbolTable_[name].type;
    }
  }

private:
  std::unordered_map<std::string, SymbolTableEntry> symbolTable_;
};

void analyzeCode(std::unique_ptr<ParseTree>& tree) {
  SymbolTable symbolTable;

  // Analyze variable declarations
  analyzeVariableDeclarations(tree.get(), symbolTable);

  // Analyze statements
  for (size_t i = 0; i < tree->getChildCount(); ++i) {
    analyzeStatement(tree->getChild(i), symbolTable);
  }
}

void analyzeVariableDeclarations(ParseTree* tree, SymbolTable& symbolTable) {
  // Traverse relevant nodes (replace with actual node types in your grammar)
  if (tree->isType<VariableDeclarationContext>()) {
    auto varDeclContext = static_cast<VariableDeclarationContext*>(tree);
    std::string name = varDeclContext->variableName->getText();
    Code::DataType type = // Extract data type from context (implementation based on your grammar)
    symbolTable.addVariable(name, type);
  }
    // Recursive case: Traverse compound declaration nodes (replace with actual types)
  if (tree->isType<CompoundDeclarationContext>()) {
    auto compoundContext = static_cast<CompoundDeclarationContext*>(tree);
    for (size_t i = 0; i < compoundContext->declarationList()->size(); ++i) {
      analyzeVariableDeclarations(compoundContext->declarationList()->get(i), symbolTable);
    }
  }
}

void analyzeFunctionCall(ParseTree* callNode) {
  // Extract function name from the call node (replace with actual node type)
  std::string functionName = callNode->getChild(0)->getText(); // Assuming function name is the first child

  // Check if function is declared (assuming symbol table stores function declarations)
  const Code::FunctionDeclaration* functionDecl = symbolTable.getFunctionDeclaration(functionName);
  if (!functionDecl) {
    std::cerr << "Error: Undeclared function: " << functionName << "\n";
    return; // Early exit if function not declared
  }

  // Analyze arguments (assuming separate child nodes for arguments)
  size_t expectedArgCount = functionDecl->argumentTypes.size();
  if (callNode->getChildCount() - 1 != expectedArgCount) {
    std::cerr << "Error: Function '" << functionName << "' expected " << expectedArgCount 
              << " arguments, but received " << callNode->getChildCount() - 1 << "\n";
    return; // Early exit if argument count mismatch
  }

  for (size_t i = 1; i < callNode->getChildCount(); ++i) { // Skip the first child (function name)
    Code::DataType argType = analyzeExpressions(callNode->getChild(i));

    // Check argument type compatibility with function declaration
    if (i <= expectedArgCount && argType != functionDecl->argumentTypes[i - 1]) {
      std::cerr << "Error: Argument " << i << " type mismatch in call to '" << functionName << "'.\n";
      std::cerr << "Expected: " << functionDecl->argumentTypes[i - 1] << ", Received: " << argType << "\n";
    }
  }
}

void analyzeExpressions(ParseTree* expressionNode) {
  // Analyze binary expressions (replace with specific node types)
  if (expressionNode->isType<BinaryExpressionContext>()) {
    auto binaryContext = static_cast<BinaryExpressionContext*>(expressionNode);
    Code::DataType leftType = analyzeExpressions(binaryContext->leftExpr);
    Code::DataType rightType = analyzeExpressions(binaryContext->rightExpr);

    // Perform type compatibility check based on your data types (example)
    if (leftType != rightType && leftType != Code::DataType::Unknown && rightType != Code::DataType::Unknown) {
      std::cerr << "Error: Type mismatch in expression: " << leftType << " + " << rightType << "\n";
    }
  }
  if (expressionNode->isType<CastExpressionContext>()) {
    analyzeTypeCasting(expressionNode);
    // Return a special type for casts (optional)
    return Code::DataType::Casted; // Or return the target type if known
  }
}

void analyzeTypeCasting(ParseTree* castNode) {
  // Extract the target type from the cast node (replace with actual node type)
  Code::DataType targetType = // Extract target type from context (implementation based on your grammar)

  // Analyze the expression being cast
  Code::DataType exprType = analyzeExpressions(castNode->getChild(0));

  // Check for valid type conversion (implementation based on your data types)
  if (// Check if conversion is valid) {
    std::cerr << "Error: Invalid type casting: " << exprType << " to " << targetType << "\n";
  }
}


void analyzeStatement(ParseTree* statementNode, SymbolTable& symbolTable) {
  // Identify the type of statement using context types from your ANTLR grammar
  Code::ControlFlowType controlType;
  if (statementNode->isType<IfStatementContext>()) {
    controlType = Code::ControlFlowType::IfStatement;
  } else if (statementNode->isType<WhileStatementContext>()) {
    controlType = Code::ControlFlowType::WhileStatement;
  } else if (statementNode->isType<DoWhileStatementContext>()) {
    controlType = Code::ControlFlowType::DoWhileStatement;
  } else if (statementNode->isType<ForStatementContext>()) {
    controlType = Code::ControlFlowType::ForStatement;
  } else if (statementNode->isType<ForEachStatementContext>()) {
    controlType = Code::ControlFlowType::ForEachStatement;
  } else if (statementNode->isType<SelectStatementContext>()) {
    controlType = Code::ControlFlowType::SelectStatement;
  } else if (// Add checks for other statement types) {
    controlType = // Assign appropriate control flow type
  } else {
    // Handle unknown statement type (optional)
    std::cerr << "Warning: Encountered unknown statement type.\n";
  }

  // Analyze based on control flow type or statement type
  switch (controlType) {
    case Code::ControlFlowType::IfStatement:
    case Code::ControlFlowType::WhileStatement:
    case Code::ControlFlowType::DoWhileStatement:
    case Code::ControlFlowType::ForStatement:
    case Code::ControlFlowType::ForEachStatement:
    case Code::ControlFlowType:SelectStatement;
      analyzeControlFlow(statementNode);
      break;
    default:
      td::cerr << "Warning: Encountered unknown statement type: " << statementNode->getText() << "\n"
  }
}

void analyzeControlFlow(ParseTree* controlFlowNode) {
  // Identify the specific control flow statement context type from your ANTLR grammar
  if (controlFlowNode->isType<IfStatementContext>()) {
    auto ifContext = static_cast<IfStatementContext*>(controlFlowNode);

    // Analyze the condition expression
    analyzeExpressions(ifContext->condition);

    // Recursively analyze the then and else branches (if applicable)
    analyzeCode(ifContext->thenBranch);
    if (ifContext->elseBranch != nullptr) {
      analyzeCode(ifContext->elseBranch);
    }
  } else if (controlFlowNode->isType<WhileStatementContext>()) {
    auto whileContext = static_cast<WhileStatementContext*>(controlFlowNode);

    // Analyze the condition expression
    analyzeExpressions(whileContext->condition);

    // Recursively analyze the loop body
    analyzeCode(whileContext->loopBody);
  } else if (controlFlowNode->isType<DoWhileStatementContext>()) {
    auto doWhileContext = static_cast<DoWhileStatementContext*>(controlFlowNode);

    // Analyze the loop body
    analyzeCode(doWhileContext->loopBody);

    // Analyze the condition expression (often at the end)
    analyzeExpressions(doWhileContext->condition);
  } else if (controlFlowNode->isType<ForStatementContext>()) {
    auto forContext = static_cast<ForStatementContext*>(controlFlowNode);

    // Analyze the initialization, condition, and increment expressions (might be separate nodes)
    // ... (implementation based on your grammar structure for for loops)

    // Recursively analyze the loop body
    analyzeCode(forContext->loopBody);
  } else if (controlFlowNode->isType<ForEachStatementContext>()) {
    auto forEachContext = static_cast<ForEachStatementContext*>(controlFlowNode);

    // Analyze the loop variable and collection expression (might be separate nodes)
    // ... (implementation based on your grammar structure for for-each loops)

    // Recursively analyze the loop body
    analyzeCode(forEachContext->loopBody);
  } else if (controlFlowNode->isType<SelectStatementContext>()) {
    auto selectContext = static_cast<SelectStatementContext*>(controlFlowNode);

    // Analyze case expressions (optional)
    for (size_t i = 0; i < selectContext->caseList->size(); ++i) {
      auto caseContext = selectContext->caseList->get(i);
      // ... (implement analysis for case expressions based on your grammar)
      // This might involve analyzing expressions within the case claus

    // Optionally, analyze the Else block if present
    if (selectContext->elseBlock != nullptr) {
      analyzeCode(selectContext->elseBlock);
    }
  }
}

} // namespace Code
