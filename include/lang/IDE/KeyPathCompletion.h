//===--- KeyPathCompletion.h ----------------------------------------------===//
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

#ifndef CODE_IDE_KEYPATHCOMPLETION_H
#define CODE_IDE_KEYPATHCOMPLETION_H

#include "code/IDE/CodeCompletionConsumer.h"
#include "code/IDE/CodeCompletionContext.h"
#include "code/IDE/TypeCheckCompletionCallback.h"

namespace code {
namespace ide {

class KeyPathTypeCheckCompletionCallback : public TypeCheckCompletionCallback {
  struct Result {
    /// The type on which completion should occur, i.e. a result type of the
    /// previous component.
    Type BaseType;
    /// Whether code completion happens on the key path's root.
    bool OnRoot;
  };

  KeyPathExpr *KeyPath;
  SmallVector<Result, 4> Results;

  void sawSolutionImpl(const constraints::Solution &solution) override;

public:
  KeyPathTypeCheckCompletionCallback(KeyPathExpr *KeyPath) : KeyPath(KeyPath) {}

  void collectResults(DeclContext *DC, SourceLoc DotLoc,
                      ide::CodeCompletionContext &CompletionCtx);
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_KEYPATHCOMPLETION_H
