//===--- CompilerInvocation.h ---------------------------------------------===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2022 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_COMPILERINVOCATION_H
#define CODE_IDE_COMPILERINVOCATION_H

#include "code/Frontend/Frontend.h"

namespace code {

class CompilerInvocation;

namespace ide {

bool initCompilerInvocation(
    CompilerInvocation &Invocation, ArrayRef<const char *> OrigArgs,
    FrontendOptions::ActionType Action, DiagnosticEngine &Diags,
    StringRef UnresolvedPrimaryFile,
    llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FileSystem,
    const std::string &swiftExecutablePath,
    const std::string &runtimeResourcePath,
    const std::string &diagnosticDocumentationPath, time_t sessionTimestamp,
    std::string &Error);

bool initInvocationByClangArguments(ArrayRef<const char *> ArgList,
                                    CompilerInvocation &Invok,
                                    std::string &Error);

} // namespace ide
} // namespace code

#endif // CODE_IDE_COMPILERINVOCATION_H
