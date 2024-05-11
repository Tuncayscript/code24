/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#include "jit_compiler.h"

#include <llvm/ADT/StringRef.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>
#include <clang/Basic/DiagnosticOptions.h>
#include <clang/Basic/FileManager.h>
#include <clang/Driver/Compilation.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/ParseAST.h>
#include <clang/Lex/Lexer.h>

namespace CodeJITCompiler {

// Helper class for error handling during parsing
class MyASTConsumer : public clang::ASTConsumer {
public:
  void HandleDiagnostic(unsigned int, const clang::SourceLocation&, const std::string& message) override {
    error_ += message;
  }

  std::string getError() const { return error_; }

private:
  std::string error_;
};

JITCompiler::JITCompiler(const std::string& module_name)
    : module_name_(module_name), llvm_module_(new llvm::Module(module_name, llvm::getGlobalContext())) {}

bool JITCompiler::validateInput(const std::string& code) {
  // Implement basic security checks on the code (e.g., whitelist allowed constructs)
  // TODO: Replace this with your security validation logic
  return true;
}

llvm::ParseResult JITCompiler::parseInput(const std::string& code) {
  llvm::SMDiagnosticError error;
  llvm::StringRef code_str(code);

  // Use Clang for C++ code parsing
  clang::CompilerInstance instance;
  MyASTConsumer consumer;
  instance.setASTConsumer(&consumer);
  instance.getDiagnostics().setDiagnosticOptions(clang::DiagnosticOptions());
  instance.getTargetOpts().Triple = llvm::sys::getDefaultTargetTriple();

  llvm::MemoryBuffer *buffer = llvm::MemoryBuffer::getMemBuffer(code_str);
  instance.getLangOpts().CPlusPlus = true;
  if (!instance.createDiagnostics(nullptr, true)) {
    return llvm::ParseResult();
  }

  const clang::FileSystemOptions& fso = instance.getFileManager().getFileSystemOpts();
  clang::FileManager virtual_fs(fso);
  const clang::VirtualFileSystem *vfs = virtual_fs.createVirtualFileSystem();
  instance.setVirtualFileSystem(vfs);
  instance.getDiagnostics().getClient()->setTarget(vfs);

  clang::UniqueVirtualFileOverlay content(buffer, instance.getVirtualFileSystem());
  clang::FileEntry *file = virtual_fs.addFile("source.cpp", clang::FileEntryKind::RegularFile, content);
  instance.getSourceManager().setMainFileID(instance.getSourceManager().createFileID(file));
  instance.getASTContext().setLangOpts(instance.getLangOpts());

  if (!clang::ParseAST(instance, instance.getSourceManager().getMainFileID(), nullptr)) {
    error = llvm::ParseResult(consumer.getError());
  }

  instance.getDiagnostics().getClient()->flushDiagnostics();
  vfs->releaseOverlay(content);
  instance.getVirtualFileSystem()->~VirtualFileSystem();
  delete buffer;

  return error;
}

llvm::Function* JITCompiler::buildIR(llvm::ParseResult& parse_result) {
  if (parse_result.hasBitcodeReaderError()) {
    return nullptr;
  }

  // Extract the desired function by name (replace with actual function name)
  const std::string expected_function_name = "your_function_name";
  auto function = llvm_module_->getFunction(expected_function_name);
  if (!function) {
    return nullptr;
  }

  // Verify the generated IR for well-formedness
  if (llvm::verifyModule(*llvm_module_, &llvm::errs())) {
    return nullptr;
  }

  return function;
}

void JITCompiler::performOptimizations(llvm::Function* function, llvm::OptimizationLevel opt_level) {
  // Create a pass manager
  llvm::legacy::FunctionPassManager pm(llvm::getGlobalContext());

  // Add basic optimization passes based on the level
  switch (opt_level) {
    case llvm::OptimizationLevel::O0:
      // No optimizations
      break;
    case llvm::OptimizationLevel::O1:
      // Common optimizations (e.g., function inlining, dead code elimination)
      pm.addPass(llvm::createFunctionInliningPass());
      pm.addPass(llvm::createInstructionCombiningPass());
      pm.addPass(llvm::createDeadCodeEliminationPass());
      break;
    case llvm::OptimizationLevel::O2:
      // More aggressive optimizations (e.g., constant propagation, loop optimizations)
      pm.addPass(llvm::createFunctionInliningPass());
      pm.addPass(llvm::createInstructionCombiningPass());
      pm.addPass(llvm::createDeadCodeEliminationPass());
      pm.addPass(llvm::createConstantPropagationPass());
      // ... (consider adding more optimizations)
      break;
    case llvm::OptimizationLevel::O3:
      // Highest optimization level (may take longer)
      pm.addPass(llvm::createFunctionInliningPass());
      pm.addPass(llvm::createInstructionCombiningPass());
      pm.addPass(llvm::createDeadCodeEliminationPass());
      pm.addPass(llvm::createConstantPropagationPass());
      // ... (consider adding vectorization and other advanced optimizations)
      break;
    default:
      // Handle invalid optimization level
      break;
  }

  // Run the pass manager on the function
  pm.run(*function);
}

std::unique_ptr<llvm::ExecutionEngine> JITCompiler::createExecutionEngine() {
  // Configure target selection and create an Execution Engine
  llvm::EngineBuilder builder(std::unique_ptr<llvm::Module>(module_->clone()));
  builder.setErrorStr(&error_string_);
  std::unique_ptr<llvm::ExecutionEngine> engine = std::move(builder.create());
  if (!engine) {
    // Handle engine creation errors (log error message)
    return nullptr;
  }

  return engine;
}

std::unique_ptr<void (*)(... )> JITCompiler::generateMachineCode(llvm::Function* function) {
  // Use the Execution Engine to generate machine code for the function
  auto error = execution_engine_->addModule(module_.get());
  if (error) {
    // Handle errors adding the module to the Execution Engine (log error)
    return nullptr;
  }

  auto error_or_fptr = execution_engine_->getFunctionAddress(function->getName());
  if (error_or_fptr.getError()) {
    // Handle errors getting the function pointer (log error)
    return nullptr;
  }

  // Return the function pointer cast to the appropriate type
  return std::unique_ptr<void (*)(... )>(reinterpret_cast<void (*)(... )>(error_or_fptr.get()));
}

std::string JITCompiler::getLLVMIR() const {
  std::string error_info;
  llvm::raw_string_ostream stream(error_info);
  llvm_module_->print(stream, nullptr);
  return stream.str();
}

void JITCompiler::dumpMachineCode(const std::string& filename) const {
  if (!execution_engine_) {
    return; // Handle missing engine
  }
  execution_engine_->dumpFunction(llvm_module_->getFunctionList().front(), filename);
}

} // namespace CodeJITCompiler

