#ifndef CODEPARSER_HPP
#define CODEPARSER_HPP

#include "CodeLexer.hpp"
#include <antlr4-runtime.h>
#include <memory> // For std::unique_ptr (optional)

namespace Code {

class CodeParser : public antlr4::Parser {
public:
  CodeParser(antlr4::TokenStream* input);
  virtual ParseTree* compilationUnit() override; // Replace with your root rule method

private:
  // ANTLR-generated context types (should be defined in your parser class)
  using ContextType = antlr4::ParserRuleContext; // Use existing context type

  // ANTLR-generated parsing methods for specific grammar rules (should already be implemented)
  // (These method names and functionalities depend on your specific grammar)
  // ... (don't modify these lines)

  // Example custom method to parse an integer literal (optional)
  int parseIntegerLiteral(); // Demonstrate a custom parsing method (optional)
};

} // namespace vba

#endif // CODEPARSER_HPP
