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
#ifndef JIT_COMPILER_H
#define JIT_COMPILER_H

#include "compiler.hpp" // Assuming compiler declarations (e.g., AST nodes)
#include "llvm_util.h"   // Assuming utility functions for working with LLVM

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

class JITCompiler {
public:
  JITCompiler(const std::string& module_name);

  // Compile C++ code (replace with AOT if needed)
  std::unique_ptr<void (*)(... )> compile(const std::string& code);

  // Additional functionalities:

  // Set optimization level (optional)
  void setOptimizationLevel(llvm::OptimizationLevel level);

  // Get the generated LLVM IR (optional)
  std::string getLLVMIR() const;

  // Dump the generated machine code (for debugging, optional)
  void dumpMachineCode(const std::string& filename) const;

private:
  // Helper functions (implementations assumed in jit_compiler.cpp)
  bool validateInput(const std::string& code);
  llvm::ParseResult parseInput(const std::string& code);
  llvm::Function* buildIR(llvm::ParseResult& parse_result);
  void performOptimizations(llvm::Function* function);
  std::unique_ptr<llvm::ExecutionEngine> createExecutionEngine();
  std::unique_ptr<void (*)(... )> generateMachineCode(llvm::Function* function);

  std::string module_name_;
  std::unique_ptr<llvm::Module> llvm_module_;
  std::unique_ptr<llvm::ExecutionEngine> execution_engine_;
  std::string error_string_;
  llvm::OptimizationLevel opt_level_; // Optional optimization level
};

} // namespace CodeJITCompiler

#endif // JIT_COMPILER_H
