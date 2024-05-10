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
// Filename: analyser.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 8, 2024
// Purpose: Generally analyizing code
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <memory>
#include <unordered_map>

// Assuming your data type definitions
namespace Code {

enum class DataType {
  Unknown,
  Integer,
  Long,
  Single,
  Double,
  Currency,
  String,
  Boolean,
  Variant,
  Object,
  Empty,
  Error,
  Null,
  Nothing
};

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

enum class ControlFlowType {
    IfStatement               
    ThenBlock                 
    ElseBlock                 
    ForStatement              
    NextStatement             
    WhileStatement            
    WendStatement             
    DoWhileStatement          
    SelectStatement           
    CaseStatement             
    EndSelectStatement        
    DefaultStatement          
    StopStatement             
    GoToStatement             
    OnGoToStatement           
    GoSubStatement            
    ReturnStatement           
    WithStatement             
    EndWithStatement          
    VariableStatement         
    StaticStatement           
    ConstStatement            
    ReDimStatement            
    EraseStatement            
    MidStatement              
    SetStatement              
    GetStatement              
    LetStatement              
    OnErrorStatement          
    ResumeStatement           
    ImplementsStatement       
    PropertyStatement         
    PrivateStatement          
    PublicStatement           
    FriendStatement           
    GlobalStatement           
    EndStatement              
    SubStatement              
    FunctionStatement         
    AsStatement               
    CallStatement             
    OptionStatement           
    ExplictStatement          
    ImplicitStatement         
    DefaultStatement          
    SharedStatement           
    ByValStatement            
    ByRefStatement            
    OptionalStatement         
    ParamArrayStatement       
    PreserveStatement         
    TrueStatement             
    FalseStatement            
    EachStatement             
    InStatement               
    IsStatement               
    LikeStatement             
    NewStatement              
    ModStatement              
    EqvStatement              
    XorStatement              
    NotStatement              
    AndStatement              
    OrStatement               
    TypeOfStatement           
    AccessStatement           
    AddressOfStatement        
    VariantStatement          
    DeclareStatement          
    LibraryStatement          
    PtrSafeStatement          
    AliasStatement            
    AnyStatement              
    DefineStatement           
    ConstVarStatement         
    AutoObjectStatement       
    ClassEstablishStatement   
    ClassTerminationStatement 
    EndIfStatement            
    ModuleStatement           
    ModStatement              
    EndPropertyStatement
    EndFunctionStatement      
    OutputStatement      
    SwitchStatement

};

// Assuming your ParseTree class definition
void analyzeCode(std::unique_ptr<Tree>& tree);

// Function declarations for analysis functions
void analyzeVariableDeclarations(ParseTree* tree, SymbolTable& symbolTable);
void analyzeExpressions(ParseTree* expressionNode);
void analyzeControlFlow(ParseTree* controlFlowNode);
void analyzeStatement(ParseTree* statementNode, SymbolTable& symbolTable);

} // namespace Code

#endif // ANALYZER_HPP
