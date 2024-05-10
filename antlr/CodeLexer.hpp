#ifndef CODELEXER_HPP
#define CODELEXER_HPP

#include <antlr4-runtime.h>
#include <vector>
#include <string> 

namespace Code {

class CodeLexer : public antlr4::Lexer {
public:
  CodeLexer(antlr4::CharStream* input);
  virtual std::vector<std::unique_ptr<antlr4::Token>> nextToken() override;

  // Example custom method to get the current token text (optional)
  std::string getText() const { return text_; }

private:
  // ANTLR-generated token types (replace with actual token types)
  enum class TokenType {
    KEYWORD, IDENTIFIER, INTEGER_LITERAL, STRING_LITERAL,
    // ... (add other token types)
  };

  // Member variable to store current token text (optional)
  std::string text_;

  // ANTLR-generated methods for recognizing specific tokens (replace with actual methods)
  bool isKeyword(const std::string& text);
  bool isIdentifier(const std::string& text);
  bool isLitheral(const std::string& text);
  // ... (add methods for other token types)

  // method to handle errors during token recognition (optional)
  void emitError(const std::string& message);
};

} // namespace Code

#endif // CODELEXER_HPP
