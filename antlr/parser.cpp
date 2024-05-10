#include <string>
#include <vector>
#include <unordered_map>

// Keyword enum
enum class Keyword
{
    If,
    Then,
    Else,
    EndIf,
    For,
    Next,
    While,
    Wend,
    Do,
    Loop,
    ExitFor,
    ExitDo,
    Select,
    Case,
    EndSelect,
    Default,
    Stop,
    GoTo,
    OnGoTo,
    GoSub,
    Return,
    OnGoSub,
    ExitSub,
    ExitFunction,
    ExitProperty,
    RaiseEvent,
    With,
    EndWith,
    Variable,
    Static,
    Const,
    ReDim,
    Erase,
    Mid,
    MidB,
    LSet,
    RSet,
    Let,
    Set,
    OnError,
    Resume,
    Error,
    Open,
    Close,
    Seek,
    Lock,
    Unlock,
    LineInput,
    Width,
    Write,
    Input,
    Put,
    Get,
    Class,
    EndClass,
    Implements,
    Property,
    Get,
    Set,
    Let,
    EndProperty,
    Private,
    Public,
    Friend,
    Global,
    End,
    Sub,
    Function,
    EndSub,
    EndFunction,
    Call,
    As,
    Option,
    Explicit,
    Implicit,
    Default,
    Shared,
    ByVal,
    ByRef,
    Optional,
    ParamArray,
    Preserve,
    True,
    False,
    Each,
    In,
    Is,
    Like,
    New,
    Mod,
    Eqv,
    Xor,
    Not,
    And,
    Or,
    TypeOf,
    Access,
    AddressOf,
    Class_Initialize,
    Class_Terminate,
    Variant,
    Date,
    Integer,
    String,
    Single,
    Double,
    Currency,
    Long,
    Boolean,
    Byte,
    Binary,
    Decimal,
    Declare,
    Lib,
    PtrSafe,
    Alias,
    Any,
    Define,
    ConstVar,
    AutoObject
};

enum class Identifiers {

};

// Built-in type enum
enum class BuiltInType
{
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
    Null
};

// Token struct
struct Token
{
    std::string value;
    Keyword keyword;
    BuiltInType builtInType;
    // Add more fields for other token types if needed
};

// Abstract Syntax Tree (AST) node 
struct ASTNode {
  enum class NodeType {
  // Statements
  IfStatement,
  ThenBlock,
  ElseBlock,
  EndIfStatement,
  ForStatement,
  NextStatement,
  WhileStatement,
  WendStatement,
  DoWhileStatement,
  LoopStatement,
  ExitForStatement,
  ExitDoStatement,
  SelectStatement,
  CaseStatement,
  EndSelectStatement,
  DefaultStatement,
  StopStatement,
  GoToStatement,
  OnGoToStatement,
  GoSubStatement,
  ReturnStatement,
  WithStatement,
  EndWithStatement,
  DimStatement,
  // ... other statements

  // Expressions
  BinaryExpression,
  UnaryExpression,
  Literal,
  Variable,
  FunctionCall,
  ArrayAccess,
  // ... other expressions

  // Other
  Program, // Represents the entire program
};

NodeType type;

union {
  ASTNode ParseIfStatement(const std::vector<Token>& tokens) {
  // Use parsing logic to identify tokens for condition, then block, and optional else block
  ASTNode ifNode = CreateASTNode(NodeType::IfStatement);
  ifNode.expression.condition = ParseExpression(tokens); // Parse condition expression
  // ... parse then block and optional else block
  return ifNode;
  };
  struct {
    std::vector<ASTNode> thenStatements;
    std::vector<ASTNode> elseStatements;
    ASTNode condition; // for IfStatement
    // ... other statement fields (e.g., loop counter for ForStatement)
  };

  // Expressions
  struct {
    std::string operatorValue; // for BinaryExpression and UnaryExpression
    std::variant<int, double, std::string> value; // Consider data types for Literal
    std::string name;          // for Variable
    std::vector<ASTNode> args; // for FunctionCall
    ASTNode arrayExpression;   // for ArrayAccess
    // ... other expression fields (e.g., function call arguments for FunctionCall)
  };

  // Others
  struct {
    std::vector<ASTNode> statements; // for Program
    // ... other program specific fields
  };
};


  // Helper functions for creating different node types
  static ASTNode CreateStatement(NodeType type) {
    ASTNode node;
    node.type = type;
    return node;
  }

  static ASTNode CreateBinaryExpression(const std::string& operatorValue, ASTNode left, ASTNode right) {
    ASTNode node = CreateStatement(NodeType::BinaryExpression);
    node.expression.operatorValue = operatorValue;
    node.expression.left = left;
    node.expression.right = right;
    return node;
  }

  static ASTNode CreateUnaryExpression(const std::string& operatorValue, ASTNode operand) {
    ASTNode node = CreateStatement(NodeType::UnaryExpression);
    node.expression.operatorValue = operatorValue;
    node.expression.right = operand; // Unary only has one operand (right)
    return node;
  }

  static ASTNode CreateLiteral(const std::string& value) {
    ASTNode node = CreateStatement(NodeType::Literal);
    node.expression.value = value;
    return node;
  }

  static ASTNode CreateVariable(const std::string& name) {
    ASTNode node = CreateStatement(NodeType::Variable);
    node.expression.name = name;
    return node;
  }

  static ASTNode CreateFunctionCall(const std::string& functionName, const std::vector<ASTNode>& args) {
    ASTNode node = CreateStatement(NodeType::FunctionCall);
    node.expression.name = functionName;
    node.expression.args = args;
    return node;
  }

  static ASTNode CreateArrayAccess(ASTNode arrayExpression, ASTNode index) {
    ASTNode node = CreateStatement(NodeType::ArrayAccess);
    node.expression.arrayExpression = arrayExpression;
    node.expression.right = index; // Array access uses right for the index
    return node;
  }

  template<typename T>
  T GetValue() const {
    if (type == NodeType::Literal) {
      return static_cast<T>(expression.value); // potential type conversion needed
    } else if (type == NodeType::Variable) {
      return static_cast<T>(expression.name); // potential type conversion needed
    } else {
      // Throw an exception or handle invalid type access
      throw std::runtime_error("Invalid node type for GetValue");
    }
  }
};


// Parser of the language
class Parser
{
public:
    Parser(const std::vector<Token> &tokens) : tokens_(tokens) {}

    // Function prototypes for statement parsing functions
    ASTNode ParseIfStatement               (const std::vector<Token> &tokens);
    ASTNode ParseThenBlock                 (const std::vector<Token> &tokens);
    ASTNode ParseElseBlock                 (const std::vector<Token> &tokens);
    ASTNode ParseForStatement              (const std::vector<Token> &tokens);
    ASTNode ParseNextStatement             (const std::vector<Token> &tokens);
    ASTNode ParseWhileStatement            (const std::vector<Token> &tokens);
    ASTNode ParseWendStatement             (const std::vector<Token> &tokens);
    ASTNode ParseDoWhileStatement          (const std::vector<Token> &tokens);
    ASTNode ParseSelectStatement           (const std::vector<Token> &tokens);
    ASTNode ParseCaseStatement             (const std::vector<Token> &tokens);
    ASTNode ParseEndSelectStatement        (const std::vector<Token> &tokens);
    ASTNode ParseDefaultStatement          (const std::vector<Token> &tokens);
    ASTNode ParseStopStatement             (const std::vector<Token> &tokens);
    ASTNode ParseGoToStatement             (const std::vector<Token> &tokens);
    ASTNode ParseOnGoToStatement           (const std::vector<Token> &tokens);
    ASTNode ParseGoSubStatement            (const std::vector<Token> &tokens);
    ASTNode ParseReturnStatement           (const std::vector<Token> &tokens);
    ASTNode ParseWithStatement             (const std::vector<Token> &tokens);
    ASTNode ParseEndWithStatement          (const std::vector<Token> &tokens);
    ASTNode ParseVariableStatement         (const std::vector<Token> &tokens);
    ASTNode ParseStaticStatement           (const std::vector<Token> &tokens);
    ASTNode ParseConstStatement            (const std::vector<Token> &tokens);
    ASTNode ParseReDimStatement            (const std::vector<Token> &tokens);
    ASTNode ParseEraseStatement            (const std::vector<Token> &tokens);
    ASTNode ParseMidStatement              (const std::vector<Token> &tokens);
    ASTNode ParseSetStatement              (const std::vector<Token> &tokens);
    ASTNode ParseGetStatement              (const std::vector<Token> &tokens);
    ASTNode ParseLetStatement              (const std::vector<Token> &tokens);
    ASTNode ParseOnErrorStatement          (const std::vector<Token> &tokens);
    ASTNode ParseResumeStatement           (const std::vector<Token> &tokens);
    ASTNode ParseImplementsStatement       (const std::vector<Token> &tokens);
    ASTNode ParsePropertyStatement         (const std::vector<Token> &tokens);
    ASTNode ParsePrivateStatement          (const std::vector<Token> &tokens);
    ASTNode ParsePublicStatement           (const std::vector<Token> &tokens);
    ASTNode ParseFriendStatement           (const std::vector<Token> &tokens);
    ASTNode ParseGlobalStatement           (const std::vector<Token> &tokens);
    ASTNode ParseEndStatement              (const std::vector<Token> &tokens);
    ASTNode ParseSubStatement              (const std::vector<Token> &tokens);
    ASTNode ParseFunctionStatement         (const std::vector<Token> &tokens);
    ASTNode ParseAsStatement               (const std::vector<Token> &tokens);
    ASTNode ParseCallStatement             (const std::vector<Token> &tokens);
    ASTNode ParseOptionStatement           (const std::vector<Token> &tokens);
    ASTNode ParseExplictStatement          (const std::vector<Token> &tokens);
    ASTNode ParseImplicitStatement         (const std::vector<Token> &tokens);
    ASTNode ParseDefaultStatement          (const std::vector<Token> &tokens);
    ASTNode ParseSharedStatement           (const std::vector<Token> &tokens);
    ASTNode ParseByValStatement            (const std::vector<Token> &tokens);
    ASTNode ParseByRefStatement            (const std::vector<Token> &tokens);
    ASTNode ParseOptionalStatement         (const std::vector<Token> &tokens);
    ASTNode ParseParamArrayStatement       (const std::vector<Token> &tokens);
    ASTNode ParsePreserveStatement         (const std::vector<Token>& tokens);
    ASTNode ParseTrueStatement             (const std::vector<Token>& tokens);
    ASTNode ParseFalseStatement            (const std::vector<Token>& tokens);
    ASTNode ParseEachStatement             (const std::vector<Token>& tokens);
    ASTNode ParseInStatement               (const std::vector<Token>& tokens);
    ASTNode ParseIsStatement               (const std::vector<Token>& tokens);
    ASTNode ParseLikeStatement             (const std::vector<Token>& tokens);
    ASTNode ParseNewStatement              (const std::vector<Token>& tokens);
    ASTNode ParseModStatement              (const std::vector<Token>& tokens);
    ASTNode ParseEqvStatement              (const std::vector<Token>& tokens);
    ASTNode ParseXorStatement              (const std::vector<Token>& tokens);
    ASTNode ParseNotStatement              (const std::vector<Token>& tokens);
    ASTNode ParseAndStatement              (const std::vector<Token>& tokens);
    ASTNode ParseOrStatement               (const std::vector<Token>& tokens);
    ASTNode ParseTypeOfStatement           (const std::vector<Token>& tokens);
    ASTNode ParseAccessStatement           (const std::vector<Token>& tokens);
    ASTNode ParseAddressOfStatement        (const std::vector<Token>& tokens);
    ASTNode ParseVariantStatement          (const std::vector<Token>& tokens);
    ASTNode ParseDeclareStatement          (const std::vector<Token>& tokens);
    ASTNode ParseLibraryStatement          (const std::vector<Token>& tokens);
    ASTNode ParsePtrSafeStatement          (const std::vector<Token>& tokens);
    ASTNode ParseAliasStatement            (const std::vector<Token>& tokens);
    ASTNode ParseAnyStatement              (const std::vector<Token>& tokens);
    ASTNode ParseDefineStatement           (const std::vector<Token>& tokens);
    ASTNode ParseConstVarStatement         (const std::vector<Token>& tokens);
    ASTNode ParseAutoObjectStatement       (const std::vector<Token>& tokens);
    ASTNode ParseClassEstablishStatement   (const std::vector<Token>& tokens);
    ASTNode ParseClassTerminationStatement (const std::vector<Token>& tokens);
    ASTNode ParseEndIfStatement            (const std::vector<Token>& tokens);
    ASTNode ParseModuleStatement           (const std::vector<Token>& tokens);
    ASTNode ParseModStatement              (const std::vector<Token>& tokens);
    ASTNode ParseEndPropertyStatement      (const std::vector<Token>& tokens);
    ASTNode ParseEndFunctionStatement      (const std::vector<Token>& tokens);
    ASTNode ParseOutputStatement           (const std::vector<Token>& tokens); // it's something like print in Swift, Pyhton, Julia.
    ASTNode ParseSwitchStatement           (const std::vector<Token>& tokens);

    // Data Types - Identifiers
    ASTNode ParseStringStatement           (const std::vector<Token>& tokens);
    ASTNode ParseIntegerStatement          (const std::vector<Token>& tokens);
    ASTNode ParseDoubleStatement           (const std::vector<Token>& tokens);
    ASTNode ParseDateStatement             (const std::vector<Token>& tokens);
    ASTNode ParseSingleStatement           (const std::vector<Token>& tokens);
    ASTNode ParseCurrencyStatement         (const std::vector<Token>& tokens);
    ASTNode ParseLongStatement             (const std::vector<Token>& tokens);
    ASTNode ParseBooleanStatement          (const std::vector<Token>& tokens);
    ASTNode ParseByteStatement             (const std::vector<Token>& tokens);
    ASTNode ParseBinaryStatement           (const std::vector<Token>& tokens);
    ASTNode ParseDecimalStatement          (const std::vector<Token>& tokens);
    ASTNode ParseIDStatement               (const std::vector<Token>& tokens);
    ASTNode ParseAppendStatement           (const std::vector<Token>& tokens);
    ASTNode ParseObjectStatement           (const std::vector<Token>& tokens);
    ASTNode ParseStepStatement             (const std::vector<Token>& tokens);
    ASTNode ParseCompareStatement          (const std::vector<Token>& tokens);
    ASTNode ParseLineStatement             (const std::vector<Token>& tokens);
    ASTNode ParseLongIntegerStatement      (const std::vector<Token>& tokens);
    ASTNode ParseAppendStatement           (const std::vector<Token>& tokens);
    ASTNode ParseRandomStatement           (const std::vector<Token>& tokens);
    ASTNode ParseReadStatement             (const std::vector<Token>& tokens);
    ASTNode ParseResetStatement            (const std::vector<Token>& tokens);

    ASTNode Parser::ParseIfStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::If)) {
                throw ParseError("Expected 'If' keyword");
            }

            ASTNode ifStatement = ASTNode::CreateStatement(NodeType::IfStatement);
            ifStatement.statement.condition = ParseExpression(tokens);

            if (Consume(Keyword::Then)) {
                ifStatement.statement.thenStatements = ParseStatementsUntil(Keyword::Else, Keyword::EndIf);
            }
            else {
                throw ParseError("Expected 'Then' keyword after 'If'");
            }

            ifStatement.statement.elseStatements = ParseElseBlock(tokens); // Call ParseElseBlock

            if (!Consume(Keyword::EndIf)) {
                throw ParseError("Expected 'EndIf' keyword");
            }

            return ifStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseForStatement(const std::vector<Token>& tokens)
    {
        try
        {
            if (!Consume(Keyword::For))
            {
                throw ParseError("Expected 'For' keyword");
            }

            ASTNode forStatement = ASTNode::CreateStatement(NodeType::ForStatement);

            // Parse the initialization expression (optional)
            if (GetCurrentToken().value != Keyword::Next)
            {
                if (GetCurrentToken().keyword == Keyword::Variable)
                {
                    const std::string& varName = GetCurrentToken().value;
                    // Check if variable is already declared
                    if (symbolTable_.GetVariableType(varName) == BuiltInType::Empty)
                    {
                        throw ParseError("Variable '" + varName + "' not declared before use in loop initialization");
                    }
                }
                forStatement.statement.forInit = ParseExpression(tokens);
            }

            if (!Consume(Keyword::To))
            {
                throw ParseError("Expected 'To' keyword after loop variable initialization");
            }

            forStatement.statement.forCondition = ParseExpression(tokens);

            if (!Consume(Keyword::Next))
            {
                throw ParseError("Expected 'Next' keyword after loop condition");
            }

            forStatement.statement.forStatements = ParseStatementsUntil(Keyword::Next, Keyword::EndFor);

            if (!Consume(Keyword::Next))
            {
                throw ParseError("Expected 'Next' keyword after loop body");
            }

            if (!Consume(Keyword::EndFor))
            {
                throw ParseError("Expected 'EndFor' keyword");
            }

            return forStatement;
        }
        catch (const ParseError& e)
        {
            // Handle parsing error as before
        }
    }

    ASTNode Parser::ParseElseBlock(const std::vector<Token>& tokens) {
        ASTNode elseBlock;

        // Check if the 'Else' keyword is present
        if (Consume(Keyword::Else)) {
            elseBlock = ParseStatements(tokens); // Parse statements within the else block
        }

        return elseBlock;
    }

    ASTNode Parser::ParseNextStatement(const std::vector<Token>& tokens) {
        if (currentTokenIndex_ >= tokens.size()) {
            throw ParseError("Reached end of token stream while expecting a statement");
        }

        // Check if the current token indicates the end of a statement sequence
        if (IsEndStatement(GetCurrentToken())) {
            throw ParseError("Unexpected end of statement sequence");
        }

        ASTNode statement = ParseStatement(tokens); // Parse the statement
        AdvanceToken(); // Move to the next token (optional)

        return statement;
    }

    ASTNode Parser::ParseWhileStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::While)) {
                throw ParseError("Expected 'While' keyword");
            }

            ASTNode whileStatement = ASTNode::CreateStatement(NodeType::WhileStatement);
            whileStatement.statement.whileCondition = ParseExpression(tokens);

            if (!Consume(Keyword::Do)) {
                throw ParseError("Expected 'Do' keyword after 'While' condition");
            }

            whileStatement.statement.whileBody = ParseStatementsUntil(Keyword::Wend);

            if (!Consume(Keyword::Wend)) {
                throw ParseError("Expected 'Wend' keyword after 'While' body");
            }

            return whileStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseWhileStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::While)) {
                throw ParseError("Expected 'While' keyword");
            }

            ASTNode whileStatement = ASTNode::CreateStatement(NodeType::WhileStatement);
            whileStatement.statement.whileCondition = ParseExpression(tokens);

            if (!Consume(Keyword::Do)) {
                throw ParseError("Expected 'Do' keyword after 'While' condition");
            }

            whileStatement.statement.whileBody = ParseStatementsUntil(Keyword::Wend);

            if (!Consume(Keyword::Wend)) {
                throw ParseError("Expected 'Wend' keyword after 'While' body"); // Error check for missing Wend
            }

            return whileStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseDoWhileStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Do)) {
                throw ParseError("Expected 'Do' keyword");
            }

            ASTNode doWhileStatement = ASTNode::CreateStatement(NodeType::DoWhileStatement);
            doWhileStatement.statement.doWhileBody = ParseStatementsUntil(Keyword::Loop); // Parse statements until 'Loop'

            if (!Consume(Keyword::Loop)) {
                throw ParseError("Expected 'Loop' keyword after 'Do' body");
            }

            if (!Consume(Keyword::While)) {
                throw ParseError("Expected 'While' keyword after 'Loop'");
            }

            doWhileStatement.statement.doWhileCondition = ParseExpression(tokens);

            return doWhileStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseSelectStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Select)) {
                throw ParseError("Expected 'Select' keyword");
            }

            ASTNode selectStatement = ASTNode::CreateStatement(NodeType::SelectStatement);

            // Parse select clause (list of expressions)
            selectStatement.select.selectList = ParseSelectClause(tokens);

            // Optional 'From' clause
            if (Consume(Keyword::From)) {
                selectStatement.select.fromClause = ParseFromClause(tokens);
            }
            else {
                throw ParseError("Expected 'From' keyword after 'Select'"); // Optional 'From' check
            }

            // Optional 'Where' clause
            if (Consume(Keyword::Where)) {
                selectStatement.select.whereClause = ParseExpression(tokens); // Parse WHERE condition
            }

            // Handle additional clauses like 'Order By', 'Group By', etc. (optional)
            // ...

            return selectStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseCaseStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Case)) {
                throw ParseError("Expected 'Case' keyword");
            }

            ASTNode caseStatement = ASTNode::CreateStatement(NodeType::CaseStatement);

            if (!Consume(Keyword::Expr)) { // Check for 'Expr' or similar keyword for expression
                throw ParseError("Expected expression after 'Case'");
            }

            caseStatement.caseStatement.caseExpr = ParseExpression(tokens); // Parse case expression

            // Parse 'When' branches
            while (Consume(Keyword::When)) {
                ASTNode caseWhen = ASTNode::CreateNode(NodeType::CaseWhen);
                caseWhen.caseWhen.caseExpr = ParseExpression(tokens); // Parse 'When' expression
                caseWhen.caseWhen.thenStatements = ParseStatementsUntil(Keyword::When, Keyword::EndCase); // Parse statements until next 'When' or 'EndCase'
                caseStatement.caseStatement.caseWhens.push_back(caseWhen);
            }

            // Optional 'Else' block
            if (Consume(Keyword::Else)) {
                caseStatement.caseStatement.elseStatements = ParseStatementsUntil(Keyword::EndCase); // Parse statements until 'EndCase'
            }

            if (!Consume(Keyword::EndCase)) {
                throw ParseError("Expected 'EndCase' keyword");
            }

            return caseStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseSelectStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Select)) {
                throw ParseError("Expected 'SELECT' keyword"); // Adjust for dialect
            }

            ASTNode selectStatement = ASTNode::CreateStatement(NodeType::SelectStatement);

            // Parse select clause (list of expressions)
            selectStatement.select.selectList = ParseSelectClause(tokens);

            // Optional 'From' clause
            if (Consume(Keyword::From)) {
                selectStatement.select.fromClause = ParseFromClause(tokens);
            }
            else {
                // Optional 'From' check (can be omitted if 'From' is mandatory for your dialect)
            }

            // Optional 'Where' clause
            if (Consume(Keyword::Where)) {
                selectStatement.select.whereClause = ParseExpression(tokens); // Parse WHERE condition
            }

            // Handle additional clauses (optional)
            bool hasOrderBy = false;
            bool hasGroupBy = false;

            while (Consume(Keyword::Order) && !hasOrderBy) { // Check for 'Order By' (adjust for dialect)
                if (!Consume(Keyword::By)) {
                    throw ParseError("Expected 'BY' keyword after 'ORDER'");
                }
                selectStatement.select.orderByClause = ParseOrderByClause(tokens); // Parse order by expressions
                hasOrderBy = true;
            }

            while (Consume(Keyword::Group) && !hasGroupBy) { // Check for 'Group By' (adjust for dialect)
                if (!Consume(Keyword::By)) {
                    throw ParseError("Expected 'BY' keyword after 'GROUP'");
                }
                selectStatement.select.groupByClause = ParseGroupByClause(tokens); // Parse group by expressions
                hasGroupBy = true;
            }

            // Implicit ending - parsing continues until end of statement or specific keywords
            // (consider dialect-specific ending keywords like ';' or 'END SELECT')

            return selectStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
            // ... (Implement specific error handling logic)
        }
    }

    ASTNode Parser::ParseSwitchStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Switch)) { // Replace with VB keyword (e.g., "Select Case")
                throw ParseError("Expected 'Switch' keyword");
            }

            ASTNode switchStatement = ASTNode::CreateStatement(NodeType::SwitchStatement);
            switchStatement.switchStatement.expression = ParseExpression(tokens); // Parse expression to switch on

            if (!Consume(Keyword::OpenBrace)) { // Replace with VB keyword (e.g., "{")
                throw ParseError("Expected opening brace '{'");
            }

            // Parse cases
            while (Consume(Keyword::Case)) { // Replace with VB keyword (e.g., "Case")
                ASTNode caseNode = ASTNode::CreateNode(NodeType::Case);
                caseNode.caseNode.expression = ParseExpression(tokens); // Parse case expression
                caseNode.caseNode.statements = ParseStatementsUntil(Keyword::Case, Keyword::CloseBrace); // Statements until next case or closing brace
                switchStatement.switchStatement.cases.push_back(caseNode);
            }

            // Default case (optional)
            if (Consume(Keyword::Default)) { // Replace with VB keyword (e.g., "Else")
                ASTNode defaultNode = ASTNode::CreateNode(NodeType::DefaultCase);
                defaultNode.defaultCase.statements = ParseStatementsUntil(Keyword::CloseBrace); // Statements until closing brace
                switchStatement.switchStatement.defaultCase = defaultNode;
            }

            if (!Consume(Keyword::CloseBrace)) { // Replace with VB keyword (e.g., "}")
                throw ParseError("Expected closing brace '}'");
            }

            return switchStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseConditionalStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::If)) { // Replace with VB keyword (e.g., "If")
                throw ParseError("Expected 'If' keyword");
            }

            ASTNode conditionalStatement = ASTNode::CreateStatement(NodeType::ConditionalStatement);

            conditionalStatement.conditionalStatement.condition = ParseExpression(tokens); // Parse condition

            if (!Consume(Keyword::Then)) { // Replace with VB keyword (e.g., "Then")
                throw ParseError("Expected 'Then' keyword");
            }

            conditionalStatement.conditionalStatement.thenStatements = ParseStatementsUntil(Keyword::Else, Keyword::EndIf); // Statements until "Else" or "EndIf"

            // Optional "Else" block
            if (Consume(Keyword::Else)) {
                conditionalStatement.conditionalStatement.elseStatements = ParseStatementsUntil(Keyword::EndIf); // Statements until "EndIf"
            }

            if (!Consume(Keyword::EndIf)) { // Replace with VB keyword (e.g., "End If")
                throw ParseError("Expected 'EndIf' keyword");
            }

            return conditionalStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error
        }
    }

    ASTNode Parser::ParseStopStatement(const std::vector<Token>& tokens) {
        try {
            if (!Consume(Keyword::Stop)) { // Replace with your desired keyword
                throw ParseError("Expected 'Stop' keyword");
            }

            // Throw a custom exception to signal stopping behavior
            throw StopProgramException(); // Replace with your exception class

            // This line will not be reached unless exception handling allows continuation
            return ASTNode::CreateStatement(NodeType::StopStatement);
        }
        catch (const ParseError& e) {
            // Handle parsing error (optional)
        }
        catch (const StopProgramException& e) {
            // Handle program stopping exception (clean up resources, etc.)
        }
    }

    class StopProgramException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "StopProgramException: Program Stopping Requested";
        }
    };

    // Helper function to check for a specific keyword (replace with your actual Consume function)
    bool ConsumeKeyword(const std::vector<token>& tokens, int index, const std::string& keyword) {
        if (index < tokens.size() && tokens[index].type == TokenType::Keyword &&
            tokens[index].value == keyword) {
            return true;
        }
        return false;
    }

    ASTNode Parser::ParseEraseStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Erase")) {
                throw ParseError("Expected 'Erase' keyword");
            }
            ++index;

            // Parse array identifier (replace with your logic)
            ASTNode arrayExpression = ParseExpression(tokens, index); // Could be a variable holding the array reference

            // Optional 'From' keyword (can be omitted)
            ConsumeKeyword(tokens, index, "From"); // Optional

            // Parse array index expression
            ASTNode indexExpression = ParseExpression(tokens, index);

            // Optional 'ShiftRemaining' flag (if supported in your VB-style language)
            bool shiftRemaining = false;
            if (ConsumeKeyword(tokens, index, "ShiftRemaining")) {
                shiftRemaining = true;
            }

            // Create an ASTNode for array erase (implementation details omitted)
            ASTNode arrayEraseStatement = CreateArrayEraseStatement(arrayExpression, indexExpression, shiftRemaining);
            return arrayEraseStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }


    ASTNode Parser::ParseGoToStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "GoTo")) {
                throw ParseError("Expected 'GoTo' keyword");
            }
            ++index; // Move to the label name

            // VBA requires a label name after 'GoTo'
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected label name after 'GoTo'");
            }

            // Create an ASTNode for the GoTo statement (implementation details omitted)
            ASTNode gotoStatement = CreateGotoStatement(tokens[index].value);

            return gotoStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseReturnStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Exit Sub") || // VBA: "Exit Sub" for function return
                !ConsumeKeyword(tokens, index, "Exit Function")) { // VBA: "Exit Function" for function return
                return ASTNode::CreateEmptyStatement(); // No return statement found
            }

            // Optional expression after 'Exit Sub' or 'Exit Function' (VBA allows expressions)
            ASTNode expression;
            if (index < tokens.size() && tokens[index].type != TokenType::EndOfStatement) {
                expression = ParseExpression(tokens, index); // Parse the expression (replace with your ParseExpression function)
            }

            // Create an ASTNode for the ReturnStatement (implementation details omitted)
            ASTNode returnStatement = CreateReturnStatement(expression);

            return returnStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    };

    ASTNode Parser::ParseWithStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "With")) {
                throw ParseError("Expected 'With' keyword");
            }
            ++index; // Move to the object name

            // Expect an object identifier after 'With'
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected object name after 'With'");
            }
            std::string objectName = tokens[index].value;
            ++index;

            // Create a WithBlock object to hold the object name
            WithBlock withBlock(objectName);

            // Parse statements within the 'With' block
            ASTNode withBlockNode = ParseStatementsUntil(tokens, index, TokenType::Keyword, "End With");

            // Check for 'End With' keyword
            if (!ConsumeKeyword(tokens, index, "End With")) {
                throw ParseError("Expected 'End With' keyword");
            }

            // Create an ASTNode for the 'With' statement (implementation details omitted)
            ASTNode withStatement = CreateWithStatement(withBlock, withBlockNode);

            return withStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }



    ASTNode Parser::ParseVariableStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            // Check for optional 'Dim' keyword (can be omitted)
            ConsumeKeyword(tokens, index, "Dim"); // Optional

            // Check for optional 'Static' keyword
            bool isStatic = ConsumeKeyword(tokens, index, "Static");

            // Handle 'Let' keyword (optional in C++)
            ConsumeKeyword(tokens, index, "Let"); // Optional (you can issue a warning if desired)

            // Expect a variable name
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected variable name after data type");
            }
            std::string variableName = tokens[index].value;
            ++index;

            // Optional data type (replace with your actual data type token checks)
            std::string dataType;
            if (index < tokens.size() && tokens[index].type == TokenType::Keyword &&
                (tokens[index].value == "Integer" || tokens[index].value == "String" || ...)) {
                dataType = tokens[index].value;
                ++index;
            }

            // Optional 'As' keyword (can be omitted before data type)
            ConsumeKeyword(tokens, index, "As"); // Optional

            // Optional initial value
            ASTNode expression;
            if (index < tokens.size() && tokens[index].value == "=") {
                ++index; // Skip '='
                expression = ParseExpression(tokens, index); // Parse the expression (replace with your ParseExpression function)
            }

            // Create an ASTNode for the variable declaration directly
            ASTNode variableDeclaration;
            variableDeclaration.type = ASTNodeType::VariableDeclaration;
            variableDeclaration.isStatic = isStatic;
            variableDeclaration.dataType = dataType;
            variableDeclaration.variableName = variableName;
            variableDeclaration.initializer = expression;

            return variableDeclaration;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }


    ASTNode Parser::ParseEraseStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Erase")) {
                throw ParseError("Expected 'Erase' keyword");
            }
            ++index;

            // Identify target based on your VB-style language syntax (replace with your logic)
            bool isArrayErase = /* Logic to identify array erase */;
            bool isMapErase = /* Logic to identify map erase */;

            if (isArrayErase) {
                // Parse array index for element removal (replace with your parsing logic)
                ASTNode indexExpression = ParseExpression(tokens, index);

                // Create an ASTNode for array erase (implementation details omitted)
                ASTNode arrayEraseStatement = CreateArrayEraseStatement(indexExpression);
                return arrayEraseStatement;
            }
            else if (isMapErase) {
                // Parse map key for element removal (replace with your parsing logic)
                ASTNode keyExpression = ParseExpression(tokens, index);

                // Create an ASTNode for map erase (implementation details omitted)
                ASTNode mapEraseStatement = CreateMapEraseStatement(keyExpression);
                return mapEraseStatement;
            }
            else {
                // Handle unsupported scenario (e.g., throw error or emit warning)
                throw ParseError("Unsupported 'Erase' target type");
            }
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseMidStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Mid")) {
                throw ParseError("Expected 'Mid' keyword");
            }
            ++index;

            // Parse string expression (replace with your parsing logic)
            ASTNode stringExpression = ParseExpression(tokens, index);

            // Parse starting index expression
            if (!ConsumeKeyword(tokens, index, "Start")) {
                throw ParseError("Expected 'Start' keyword after 'Mid'");
            }
            ++index;
            ASTNode startIndexExpression = ParseExpression(tokens, index);

            // Optional 'Length' parameter (can be omitted)
            int length = -1; // -1 indicates missing length
            if (ConsumeKeyword(tokens, index, "Length")) {
                ++index;
                lengthExpression = ParseExpression(tokens, index); // Parse length expression
            }

            // Create an ASTNode for the Mid operation (implementation details omitted)
            ASTNode midStatement = CreateMidStatement(stringExpression, startIndexExpression, lengthExpression);
            return midStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseSetStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Set")) {
                throw ParseError("Expected 'Set' keyword");
            }
            ++index;

            // Parse the expression representing the object name (replace with your logic)
            // This could be a variable holding a reference to the object, or a direct member access
            ASTNode objectExpression = ParseExpression(tokens, index);

            // Expect an assignment operator
            if (index >= tokens.size() || !IsAssignmentOperator(tokens[index].value)) {
                throw ParseError("Expected assignment operator after object name");
            }
            ++index;

            // Parse the expression on the right-hand side
            ASTNode expression = ParseExpression(tokens, index);

            // Create an ASTNode for the 'Set' statement (implementation details omitted)
            ASTNode setStatement = CreateSetStatement(objectExpression, expression);
            return setStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseGetStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Get")) {
                throw ParseError("Expected 'Get' keyword");
            }
            ++index;

            // Parse the variable name on the left-hand side (replace with your logic)
            ASTNode variableNameExpression = ParseExpression(tokens, index);

            // Optional expression after 'Get' (replace with specific parsing based on your VB-style syntax)
            ASTNode expression;
            if (index < tokens.size() && !IsAssignmentOperator(tokens[index].value)) {
                // Parse the expression (e.g., function call, property access)
                expression = ParseExpression(tokens, index);
            }

            // Create an ASTNode for the 'Get' statement (implementation details omitted)
            ASTNode getStatement = CreateGetStatement(variableNameExpression, expression);
            return getStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseOnErrorStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "OnError")) {
                throw ParseError("Expected 'OnError' keyword");
            }
            ++index;

            // Optional error code or condition (replace with your parsing logic)
            // This could be a string literal representing an error code
            // or an expression for the error condition
            ASTNode errorCondition;
            if (index < tokens.size() && (tokens[index].type == TokenType::StringLiteral || ...)) {
                errorCondition = ParseExpression(tokens, index); // Parse condition (replace with your logic)
                ++index;
            }

            // Expect a statement block representing the error handling code
            if (!ConsumeKeyword(tokens, index, "Then")) {
                throw ParseError("Expected 'Then' keyword after error condition");
            }
            ++index;

            // Parse the statement block representing the error handling code
            ASTNode errorHandlingBlock = ParseStatementBlock(tokens, index); // Replace with your block parsing logic

            // Create an ASTNode for the 'OnError' statement
            ASTNode onErrorStatement = CreateOnErrorStatement(errorCondition, errorHandlingBlock);
            return onErrorStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseResumeStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            if (!ConsumeKeyword(tokens, index, "Resume")) {
                throw ParseError("Expected 'Resume' keyword");
            }
            ++index;

            // Create an ASTNode for a 'continue' statement (implementation details)
            ASTNode continueStatement;
            continueStatement.type = ASTNodeType::ContinueStatement;

            return continueStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseClassStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            // Expect 'Class' keyword
            if (!ConsumeKeyword(tokens, index, "Class")) {
                throw ParseError("Expected 'Class' keyword");
            }
            ++index;

            // Parse class name (replace with your logic for identifier parsing)
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected class name after 'Class'");
            }
            std::string className = tokens[index].value;
            ++index;

            // Optional inheritance (replace with your parsing logic for base class)
            ASTNode baseClass;
            if (index < tokens.size() && tokens[index].value == "Inherits") {
                ++index; // Skip 'Inherits' keyword
                baseClass = ParseExpression(tokens, index); // Parse base class name (replace with your logic)
            }

            // Expect '{' for class body
            if (index >= tokens.size() || tokens[index].value != "{") {
                throw ParseError("Expected '{' after class declaration");
            }
            ++index;

            // Parse class member declarations (replace with your logic)
            std::vector<ASTNode> memberDeclarations;
            while (index < tokens.size() && tokens[index].value != "}") {
                memberDeclarations.push_back(ParseMemberDeclaration(tokens, index));
            }

            // Expect '}' for the end of class body
            if (index >= tokens.size() || tokens[index].value != "}") {
                throw ParseError("Expected '}' at the end of class declaration");
            }
            ++index;

            // Create an ASTNode for the class declaration
            ASTNode classDeclaration;
            classDeclaration.type = ASTNodeType::ClassDeclaration;
            classDeclaration.className = className;
            classDeclaration.baseClass = baseClass; // Optional base class information
            classDeclaration.memberDeclarations = memberDeclarations;

            return classDeclaration;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParsePropertyStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            // Expect identifier for property name
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected property name");
            }
            std::string propertyName = tokens[index].value;
            ++index;

            // Expect '=' for assignment
            if (index >= tokens.size() || tokens[index].value != "=") {
                throw ParseError("Expected '=' after property name");
            }
            ++index;

            // Parse property value (replace with your logic for expression parsing)
            ASTNode propertyValue = ParseExpression(tokens, index);

            // Create an ASTNode for the property statement (optional)
            // This could be useful if you need to perform specific actions
            // based on property definitions during code generation.
            ASTNode propertyStatement;
            propertyStatement.type = ASTNodeType::PropertyStatement; // (or a suitable type)
            propertyStatement.propertyName = propertyName;
            propertyStatement.propertyValue = propertyValue;

            return propertyStatement;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseMemberDeclaration(const std::vector<Token>& tokens, int index) {
        try {
            // Parse access specifiers (public, private, static)
            bool isPublic = ConsumeKeyword(tokens, index, "public");
            bool isPrivate = ConsumeKeyword(tokens, index, "private");
            bool isStatic = ConsumeKeyword(tokens, index, "static");
            bool isHybrid = ConsumeKeyword(tokens, index, "hybrid");
            bool isFriend = ConsumeKeyword(tokens, index, "friend");
            bool isProtected = ConsumeKeyword(token, index, "protected");
            bool isUnsafe = ConsumeKeyword(token, index, "unsafe");

            // Optional inheritance for visibility control
            ASTNode visibilityContext = ParseMemberVisibilityContext(tokens, index);

            // Parse the rest of the member declaration (type, name, etc.)
            ASTNode memberDeclaration = ParseSpecificMemberDeclaration(tokens, index);

            // Set access specifier information in the memberDeclaration node
            memberDeclaration.isPublic = isPublic;
            memberDeclaration.isPrivate = isPrivate;
            memberDeclaration.isStatic = isStatic;
            memberDeclaration.isHybrid = isHybrid;
            memberDeclaration.isFriend = isFriend;
            memberDeclaration.isProtected = isProtected;
            memberDeclaration.isUnsafe = isUnsafe;

            // Optionally, store inheritance information for code generation (if applicable)
            memberDeclaration.visibilityContext = visibilityContext; // (or a suitable field)

            return memberDeclaration;
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    // Optional function for inheritance-based visibility control
    ASTNode Parser::ParseMemberVisibilityContext(const std::vector<Token>& tokens, int index) {
        try {
            // Check for 'Inherits' keyword followed by base class name
            if (ConsumeKeyword(tokens, index, "Inherits") && tokens[index].type == TokenType::Identifier) {
                std::string baseClassName = tokens[index].value;
                ++index;

                // Create an ASTNode representing inheritance for visibility control (optional)
                ASTNode visibilityContext;
                visibilityContext.type = ASTNodeType::InheritanceVisibility; // (or a suitable type)
                visibilityContext.baseClassName = baseClassName;

                return visibilityContext;
            }

            // No inheritance specified, return an empty ASTNode (or null)
            return ASTNode(); // Replace with suitable empty node representation
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }

    ASTNode Parser::ParseGlobalStatement(const std::vector<Token>& tokens) {
        try {
            int index = 0; // Assuming index tracking for token access

            // Check for data type (replace with your logic for type parsing)
            DataType dataType = ParseDataType(tokens, index);

            // Parse variable or function declaration
            if (tokens[index].type == TokenType::Identifier) {
                std::string name = tokens[index].value;
                ++index;

                // Check for assignment (variable declaration with initializer)
                if (tokens[index].value == "=") {
                    ++index;
                    ASTNode initializer = ParseExpression(tokens, index); // Parse initializer expression

                    // Create ASTNode for variable declaration with initializer
                    ASTNode variableDeclaration;
                    variableDeclaration.type = ASTNodeType::VariableDeclaration;
                    variableDeclaration.dataType = dataType;
                    variableDeclaration.name = name;
                    variableDeclaration.initializer = initializer;

                    return variableDeclaration;
                }
                else {
                    // Create ASTNode for simple variable declaration
                    ASTNode variableDeclaration;
                    variableDeclaration.type = ASTNodeType::VariableDeclaration;
                    variableDeclaration.dataType = dataType;
                    variableDeclaration.name = name;

                    return variableDeclaration;
                }
            }
            else if (tokens[index].value == "(") { // Function signature starts with '('
                // Parse function declaration (replace with your logic)
                // This would involve parsing function name, arguments, return type, and body
                ASTNode functionDeclaration = ParseFunctionDeclaration(tokens, index);
                return functionDeclaration;
            }
            else {
                throw ParseError("Expected identifier or '(' after data type in global statement");
            }
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }
    ASTNode Parser::ParseSubStatement(const std::vector<Token>& tokens, int index) {
        try {
            // Check for variable declaration (replace with your logic for type parsing)
            if (IsVariableDeclarationStart(tokens, index)) {
                ASTNode variableDeclaration = ParseVariableDeclaration(tokens, index);
                return variableDeclaration;
            }
            else {
                // Check for assignment statement
                if (tokens[index].value == "=") {
                    ++index; // Skip '='

                    // Parse left value (variable)
                    ASTNode leftValue = ParseExpression(tokens, index); // Can be a variable or expression

                    // Parse right value (expression)
                    ASTNode rightValue = ParseExpression(tokens, index);

                    // Create ASTNode for assignment statement
                    ASTNode assignmentStatement;
                    assignmentStatement.type = ASTNodeType::AssignmentStatement; // (or a suitable type)
                    assignmentStatement.leftValue = leftValue;
                    assignmentStatement.rightValue = rightValue;

                    return assignmentStatement;
                }
                else {
                    // Check for control flow statements (If, While, For, etc.)
                    // Replace with logic for specific control flow statements
                    // This might involve parsing keyword, condition, and sub-statements within block
                    ASTNode controlFlowStatement = ParseControlFlowStatement(tokens, index);
                    return controlFlowStatement;
                }
            }
        }
        catch (const ParseError& e) {
            // Handle parsing error (log error, re-throw, etc.)
        }
    }
    
    ASTNode Parser::ParseFunctionStatement(const std::vector<Token>& tokens, int index) {
        try {
            // Expect 'Function' keyword
            if (!ConsumeKeyword(tokens, index, "Function")) {
                throw ParseError("Expected 'Function' keyword");
            }
            ++index;

            // Parse function name (replace with your logic for identifier parsing)
            if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                throw ParseError("Expected function name after 'Function'");
            }
            std::string functionName = tokens[index].value;
            ++index;

            // Optional argument list (replace with your logic for parsing arguments)
            std::vector<ASTNode> arguments;
            if (tokens[index].value == "(") {
                ++index; // Skip '('
                arguments = ParseArgumentList(tokens, index); // Parse arguments
                if (tokens[index].value != ")") {
                    throw ParseError("Expected ')' after argument list");
                }
                ++index; // Skip ')'
            }

            // Optional return type (replace with your logic for type parsing)
            ASTNode returnType;
            if (IsTypeStart(tokens, index)) {
                returnType = ParseType(tokens, index); // Parse return type
                ++index; // Skip return type
            }

            // Expect 'As' keyword before return type (optional in newer versions)
            if (returnType.type != ASTNodeType::None && ConsumeKeyword(tokens, index, "As")) {
                ++index;
            }

            // Function body (statements within function)
            ASTNode functionBody = ParseBlock(tokens, index); // Parse statements within function

            // Create ASTNode for function declaration
            ASTNode functionDeclaration;
            functionDeclaration.type = ASTNodeType::FunctionDeclaration; // (or a suitable type)
            functionDeclaration.name = functionName;
            functionDeclaration.arguments = arguments;
            functionDeclaration.returnType = returnType;
            functionDeclaration.body = functionBody;

            return functionDeclaration;
        }
        catch (const ParseError& e) {
            if (ConsumeKeyword(tokens, index, "If")) {
                ++index;

                // Parse condition (expression)
                ASTNode condition = ParseExpression(tokens, index);

                // Parse 'Then' keyword
                if (!ConsumeKeyword(tokens, index, "Then")) {
                    throw ParseError("Expected 'Then' keyword after 'If'");
                }
                ++index;

                // Parse statements within 'Then' block
                ASTNode thenBlock = ParseBlock(tokens, index); // Parse statements within block

                // Optional 'Else' block
                ASTNode elseBlock;
                if (ConsumeKeyword(tokens, index, "Else")) {
                    ++index;
                    elseBlock = ParseBlock(tokens, index); // Parse statements within block
                }

                // Create ASTNode for 'If' statement
                ASTNode ifStatement;
                ifStatement.type = ASTNodeType::IfStatement; // (or a suitable type)
                ifStatement.condition = condition;
                ifStatement.thenBlock = thenBlock;
                ifStatement.elseBlock = elseBlock;

                return ifStatement;
            }
        }

        ASTNode Parser::ParseCallStatement(const std::vector<Token>&tokens, int index) {
            try {
                // Parse function name (replace with your logic for identifier parsing)
                if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
                    throw ParseError("Expected function name");
                }
                std::string functionName = tokens[index].value;
                ++index;

                // Optional argument list (replace with your logic for parsing arguments)
                std::vector<ASTNode> arguments;
                if (tokens[index].value == "(") {
                    ++index; // Skip '('
                    arguments = ParseArgumentList(tokens, index); // Parse arguments
                    if (tokens[index].value != ")") {
                        throw ParseError("Expected ')' after argument list");
                    }
                    ++index; // Skip ')'
                }

                // Create ASTNode for function call statement
                ASTNode callStatement;
                callStatement.type = ASTNodeType::CallStatement; // (or a suitable type)
                callStatement.functionName = functionName;
                callStatement.arguments = arguments;

                return callStatement;
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
        }

        ASTNode Parser::ParseAsStatement(const std::vector<Token>& tokens, int index) {
            try {
                // Parse the expression to be cast (replace with your logic for parsing expressions)
                ASTNode expression = ParseExpression(tokens, index);

                // Expect 'As' keyword
                if (!ConsumeKeyword(tokens, index, "As")) {
                    throw ParseError("Expected 'As' keyword in type casting statement");
                }
                ++index;

                // Parse the target type (replace with your logic for type parsing)
                ASTNode targetType = ParseType(tokens, index); // Parse the desired type

                // Create ASTNode for the custom type casting statement
                ASTNode typeCastingStatement;
                typeCastingStatement.type = ASTNodeType::TypeCastingStatement; // (or a suitable type)
                typeCastingStatement.expression = expression;
                typeCastingStatement.targetType = targetType;

                return typeCastingStatement;
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
        }


        ASTNode Parser::ParseOptionStatement(const std::vector<Token>& tokens, int index) {
            try {
                // Expect 'Option' keyword
                if (!ConsumeKeyword(tokens, index, "Option")) {
                    return ASTNode::None; // Not an Option statement
                }
                ++index;

                // Handle potential options after 'Option' (replace with your logic)
                // You can define supported options in a separate configuration or enum
                if (tokens[index].value == "Explicit") {
                    // Delegate parsing to ParseExplictStatement
                    return ParseExplictStatement(tokens, index);
                }
                else {
                    throw ParseError("Unsupported option after 'Option'");
                }
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
        }

        ASTNode Parser::ParseExplictStatement(const std::vector<Token>& tokens, int index) {
            try {
                // Expect 'Explicit' keyword
                if (!ConsumeKeyword(tokens, index, "Explicit")) {
                    throw ParseError("Expected 'Explicit' after 'Option'");
                }
                ++index;

                // Create ASTNode for Option Explicit statement
                ASTNode explicitStatement;
                explicitStatement.type = ASTNodeType::OptionExplicitStatement; // (or a suitable type)

                return explicitStatement;
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
        }

    ASTNode Parser::ParseImplicitStatement(const std::vector<Token>& tokens, int index) {
            try {
                // Implicit variable usage check
                if (IsImplicitVariableUsage(tokens, index)) {
                    // ... existing logic to create implicit variable ASTNode ...
                }
                // ...
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
        }

    ASTNode Parser::ParseOrderingStatement(const std::vector<Token>& tokens, int index) {
            try {
                // ... existing parsing logic for procedure/function name and opening parenthesis ...

                // Check for optional 'ByVal' or 'ByRef' keyword
                bool isByVal = false;
                bool isByRef = false;
                if (index < tokens.size() && (tokens[index].value == "ByVal" || tokens[index].value == "ByRef")) {
                    if (tokens[index].value == "ByVal") {
                        isByVal = true;
                        ++index; // Skip 'ByVal' keyword
                    }
                    else {
                        isByRef = true;
                        ++index; // Skip 'ByRef' keyword
                    }
                }

                // Parse argument list
                std::vector<ASTNode> arguments = ParseArgumentList(tokens, index);

                // Expect closing parenthesis
                if (!ConsumeKeyword(tokens, index, ")")) {
                    throw ParseError("Expected ')' after argument list");
                }
                ++index;

                // Create ASTNode for procedure/function call
                ASTNode procedureCallNode;
                procedureCallNode.type = ASTNodeType::ProcedureCall; // (or suitable type)
                procedureCallNode.name = tokens[index - 2].value; // Procedure/function name
                procedureCallNode.arguments = arguments;

                // Update ASTNode with 'ByVal' or 'ByRef' information (optional)
                if (isByVal) {
                    procedureCallNode.byVal = true; // Add member for 'ByVal' (optional)
                }
                else if (isByRef) {
                    procedureCallNode.byRef = true; // Add member for 'ByRef' (optional)
                }

                return procedureCallNode;
            }
            catch (const ParseError& e) {
                // Handle parsing error (log error, re-throw, etc.)
            }
    }

    ASTNode ParseOptionalStatement(const std::vector<Token>& tokens, int index) {
      try {
        // Check for optional 'Optional' keyword (custom extension)
        bool isOptional = false;
        if (index < tokens.size() && tokens[index].value == "Optional") {
          isOptional = true;
          ++index; // Skip 'Optional' keyword
        }
    
        // Parse data type
        ASTNode parameterNode;
        if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
          throw ParseError("Expected data type for parameter");
        }
        parameterNode.dataType = tokens[index].value; // Store data type
        ++index;
    
        // Parse parameter name
        if (index >= tokens.size() || tokens[index].type != TokenType::Identifier) {
          throw ParseError("Expected parameter name");
        }
        parameterNode.name = tokens[index].value; // Store parameter name
        ++index;
    
        // Check for optional '=' and default value expression
        if (index < tokens.size() && tokens[index].value == "=") {
          ++index; // Skip '=' keyword
          ASTNode defaultValue = ParseExpression(tokens, index); // Parse default value expression
          parameterNode.defaultValue = defaultValue; // Update parameter ASTNode with default value
        }
    
        parameterNode.isOptional = isOptional; // Update parameter ASTNode with optional flag
    
        return parameterNode;
      } catch (const ParseError& e) {
        // Handle parsing error (log error, re-throw, etc.)
      }
    }

    ASTNode ParseTrueStatement(const std::vector<Token>& tokens, int index) {
      try {
        if (index >= tokens.size() || tokens[index].value != "True") {
          throw ParseError("Expected 'True' keyword");
        }
    
        ASTNode booleanLiteral;
        booleanLiteral.type = ASTNodeType::BooleanLiteral;
        booleanLiteral.value = "True"; // Or appropriate representation for true
    
        return booleanLiteral;
      } catch (const ParseError& e) {
        // Handle parsing error (log error, re-throw, etc.)
      }
    }
    
    ASTNode ParseFalseStatement(const std::vector<Token>& tokens, int index) {
      try {
        if (index >= tokens.size() || tokens[index].value != "False") {
          throw ParseError("Expected 'False' keyword");
        }
    
        ASTNode booleanLiteral;
        booleanLiteral.type = ASTNodeType::BooleanLiteral;
        booleanLiteral.value = "False"; // Or appropriate representation for false
    
        return booleanLiteral;
      } catch (const ParseError& e) {
        // Handle parsing error (log error, re-throw, etc.)
      }
    }


    // Function for parsing a sequence of statements (unchanged)
    ASTNode Parser::ParseStatements(const std::vector<Token>& tokens) {
        ASTNode statements = ASTNode::CreateBlock(NodeType::BlockStatement); // Create an AST node for the block

        while (!IsEndStatement(GetCurrentToken()) && currentTokenIndex_ < tokens.size()) {
            statements.blockStatements.push_back(ParseStatement(tokens)); // Parse a statement and add it to the block
            AdvanceToken(); // Move to the next token
        }

        return statements;
    }

    bool Parser::IsEndStatement(const Token& token) const {
        // Implement logic to check for keywords or tokens that mark the end of a statement sequence
        // This could include keywords like 'End', 'Else', 'EndIf', or reaching the end of the token stream
        return token.keyword == Keyword::End || token.keyword == Keyword::Else || token.keyword == Keyword::EndIf || currentTokenIndex_ == tokens.size() - 1;
    }


private:
    std::vector<Token> tokens_;

    // Helper functions for statement parsing and error handling
    bool IsEndOfBlockKeyword(const std::string &keyword) const;
    int GetStatementSpan(const std::vector<Token> &tokens) const;

    // Implementation for other statement parsing functions (similar to WhileStatement)

    ASTNode ParseNextStatement(const std::vector<Token> &tokens)
    {
        // ... (similar implementation as ParseForStatement)
    }

    ASTNode ParseWendStatement(const std::vector<Token> &tokens)
    {
        // ... (handle "Wend" keyword and potential error checking)
        return {};
    }

    ASTNode ParseDoWhileStatement(const std::vector<Token> &tokens)
    {
        // ... (similar implementation as WhileStatement with "Do" and "Loop" keywords)
    }

    // ... and so on for other statements
};

// Helper functions for expression parsing (example)
std::vector<ASTNode> ParseExpression(const std::vector<Token> &tokens);
ASTNode ParseSimpleExpression(const std::vector<Token> &tokens);

// Abstract Syntax Tree (AST) node (unchanged)

// Function to check for end of block keywords
bool Parser::IsEndOfBlockKeyword(const std::string &keyword) const
{
    static const std::unordered_map<std::string, NodeType> endOfBlockKeywords = {
        {"If", NodeType::EndIfStatement},
        {"For", NodeType::EndForStatement},
        {"Wend", NodeType::WendStatement},
        {"Loop", NodeType::LoopStatement}, // Handle Do While loop
        {"Next", NodeType::NextStatement},
        {"EndSelect", NodeType::EndSelectStatement},
        {"EndWith", NodeType::EndWithStatement},
        // ... add other end of block keywords
    };
    return endOfBlockKeywords.count(keyword) > 0;
}

// Function to estimate the span of a statement (heuristic)
int Parser::GetStatementSpan(const std::vector<Token> &tokens) const
{
    int span = 1; // Minimum span is 1 token
    for (const auto &token : tokens)
    {
        if (token.value == ";")
        {
            return span; // Statement ends with semicolon
        }
        span++;
    }
    return span;
