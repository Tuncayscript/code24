#ifndef JIT_COMPILER_HPP
#define JIT_COMPILER_HPP

#include <memory>
#include <string>

class BackgroundCompilationQueue;
class Class;
class Code;
class CompilationWorkQueue;
class FlowGraph;
class Function;
class IndirectGotoInstr;
class Library;
class ParsedFunction;
class QueueElement;
class Script;
class SequenceNode;

namespace CodeJITCompiler {

class JITCompiler {
public:
  // Constructor (taking necessary arguments)
  explicit JITCompiler(const std::string& module_name);

  // Compile the input C++ code snippet and return a function pointer
  std::unique_ptr<void (*)(... )> compile(const std::string& code);

private:
  // Forward declarations for helper functions (prototypes)
  bool validateInput(const std::string& code);
  llvm::ParseResult parseInput(const std::string& code);
  llvm::Function* buildIR(llvm::ParseResult& parse_result);
  void performOptimizations();
  std::unique_ptr<llvm::ExecutionEngine> createExecutionEngine();
  std::unique_ptr<void (*)(... )> generateMachineCode(llvm::Function* function);

  // Members
  const std::string module_name_;
  std::unique_ptr<llvm::Module> llvm_module_;
  std::unique_ptr<llvm::ExecutionEngine> execution_engine_;
};

} // namespace CodeJITCompiler

#endif // JIT_COMPILER_HPP
