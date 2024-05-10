#include <llvm/IR/Module.h>

#include <iostream>
#include <fstream>
#include <memory>
#include "CodeLexer.hpp"
#include "CodeParser.hpp"
#include "codegen.hpp" // Assuming your code generation header

namespace Code {

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Error: Please provide Code source code as argument\n";
    return 1;
  }

  // Read Code source code from file (optional)
  std::string source;
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file '" << argv[1] << "'\n";
    return 1;
  }
  std::getline(file, source, std::string::npos); // Read entire file into source string
  file.close();

  // Create ANTLR character stream from the source code
  antlr4::ANTLRInputStream stream(source);

  // Create lexer and token stream
  CodeLexer lexer(&stream);
  std::unique_ptr<antlr4::CommonTokenStream> tokenStream(
      std::make_unique<antlr4::CommonTokenStream>(&lexer));

  // Create parser and parse the code
  CodeParser parser(tokenStream.get());
  std::unique_ptr<ParseTree> tree =
      std::unique_ptr<ParseTree>(parser.compilationUnit()); // Replace with your root rule method

  if (parser.hasErrors()) {
    std::cerr << "Error: Parsing errors encountered\n";
    return 1;
  }

  // Generate LLVM IR (assuming codegen.cpp is implemented)
  std::unique_ptr<llvm::Module> module = std::make_unique<llvm::Module>("code_module", llvm::getGlobalContext());
  generateLLVMIR(tree.get(), module.get()); // Call your code generation function

  // **Output Options**
  // 1. Print to console
  // module->print(outs(), nullptr); // Uncomment to print IR to console (outs() is a standard stream)

  // 2. Write to a file (replace "ir.ll" with your desired filename)
  std::error_code EC;
  llvm::raw_fd_ostream outFile("ir.ll", EC, llvm::sys::fs::OpenFlags::F_Text);
  if (EC) {
    std::cerr << "Error: Could not open file for writing IR: " << EC.message() << "\n";
    return 1;
  }
  module->print(outFile, nullptr);
  outFile.close();

  return 0;
}

} // namespace Code
