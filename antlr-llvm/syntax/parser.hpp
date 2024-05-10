#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory> // For std::unique_ptr

// Include headers specific to ANTLR-generated parser classes
#include "antlr/CodeLexer.hpp" 
#include "antlr/CodeParser.hpp" 

namespace Code {

class Parser {
public:
  // Constructor (assuming ANTLR parser class has a constructor)
  Parser();

  // Function to parse Code source code and return the parse tree (replace with actual implementation)
  std::unique_ptr<ParseTree> parse(const std::string& source);

private:
  // Members to store the ANTLR-generated lexer and parser objects (replace with actual names)
  codeLexer* lexer_;
  codeParser* parser_;
};

} // namespace Code

#endif // VBA_PARSER_HPP
