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

#include "compiler.hpp"
#include "llvm_util.h"
#include "codegen/jit_codegen.cpp"

#include <llvm/ADT/StringRef.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Transforms/Scalar.h>
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"

namespace CodeJITCompiler {

JITCompiler::JITCompiler(const std::string& module_name)
  : module_name_(module_name), llvm_module_(new llvm::Module(module_name, llvm::getGlobalContext())) {}

std::unique_ptr<void (*)(... )> JITCompiler::compile(const std::string& code) {
  if (!validateInput(code)) {
    // Handle invalid input (throw an exception, log an error)
    return nullptr;
  }

  llvm::ParseResult parse_result = parseInput(code);
  if (parse_result.hasBitcodeReaderError()) {
    // Handle parsing errors (throw an exception, log an error)
    return nullptr;
  }

  auto function = buildIR(parse_result);
  if (!function) {
    return nullptr; // Handle function extraction or verification errors
  }

  performOptimizations(function);
  execution_engine_ = createExecutionEngine();
  return generateMachineCode(function);
}

// Implementations of helper functions

bool JITCompiler::validateInput(const std::string& code) {
  // Implement security-focused validation on the C++ code snippet
  // (e.g., whitelist allowed patterns, basic syntax checks)
  return true; // Placeholder, replace with actual validation logic
}

llvm::ParseResult JITCompiler::parseInput(const std::string& code) {
  // Use a C++ parser (e.g., Clang) to convert code to LLVM IR
  // Return the ParseResult object indicating success or failure
  llvm::SMDiagnosticError error;
  llvm::StringRef code_str(code);
  return llvm::parseAssemblyString(code_str, error);
}

llvm::Function* JITCompiler::buildIR(llvm::ParseResult& parse_result) {
  if (parse_result.hasBitcodeReaderError()) {
    return nullptr; // Handle parsing errors
  }

  auto module = parse_result.getModulePtr();

  // Extract the desired function by name (assuming a single function)
  const std::string expected_function_name = "your_function_name"; // Replace with actual function name
  auto function = module->getFunction(expected_function_name);
  if (!function) {
    return nullptr; // Handle missing function
  }

  // Verify the generated IR for well-formedness
  if (llvm::verifyModule(*module, &llvm::errs())) {
    return nullptr; // Handle verification errors
  }

  return function;
}

void JITCompiler::performOptimizations(llvm::Function* function) {
  // Create a pass manager and add basic optimization passes
  llvm::legacy::FunctionPassManager pm(module_getGlobalContext());
  pm.addPass(llvm::createFunctionInliningPass());
  pm.addPass(llvm::createInstructionCombiningPass());
  pm.addPass(llvm::createDeadCodeEliminationPass());
  pm.addPass(llvm::createConstantPropagationPass());
  // ... (consider adding more optimizations if needed)

  // Run the pass manager on the function
  pm.run(*function);
}

std::unique_ptr<llvm::ExecutionEngine> JITCompiler::createExecutionEngine() {
  // Configure target selection and create an ExecutionEngine
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
