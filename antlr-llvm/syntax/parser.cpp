#include <antlr-llvm/syntax/CodeParser.g4.cpp> // Include ANTLR generated parser header

// Function to parse VBA source code and return the parse tree
ParseTree* parseCode(const std::string& source) {
  CharStream* stream = CharStreamFactory::createStringStream(source);
  codeLexer* lexer = new codeLexer(stream);
  CommonTokenStream* tokens = new CommonTokenStream(lexer);
  codeParser parser(tokens);
  return parser.compilationUnit(); // Replace with your root rule parsing call
}
