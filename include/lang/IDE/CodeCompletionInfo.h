//===--- SwiftCompletionInfo.h --------------------------------------------===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2023 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_SWIFTCOMPLETIONINFO_H
#define CODE_IDE_SWIFTCOMPLETIONINFO_H

#include "code/Frontend/Frontend.h"
#include "code/IDE/CodeCompletionContext.h"

namespace code {
namespace ide {

struct SwiftCompletionInfo {
  std::shared_ptr<CompilerInstance> compilerInstance = nullptr;
  CodeCompletionContext *completionContext = nullptr;
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_SWIFTCOMPLETIONINFO_H
