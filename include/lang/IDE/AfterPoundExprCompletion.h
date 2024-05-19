//===--- AfterPoundExprCompletion.h ---------------------------------------===//
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

#ifndef CODE_IDE_AFTERPOUNDEXPRCOMPLETION_H
#define CODE_IDE_AFTERPOUNDEXPRCOMPLETION_H

#include "code/IDE/CodeCompletionConsumer.h"
#include "code/IDE/CodeCompletionContext.h"
#include "code/IDE/TypeCheckCompletionCallback.h"

namespace code {
namespace ide {

/// Used to collect and store information needed to perform unresolved member
/// completion (\c CompletionKind::UnresolvedMember ) from the solutions
/// formed during expression type-checking.
class AfterPoundExprCompletion : public TypeCheckCompletionCallback {
  struct Result {
    Type ExpectedTy;
    bool IsImplicitSingleExpressionReturn;

    /// Whether the surrounding context is async and thus calling async
    /// functions is supported.
    bool IsInAsyncContext;
  };

  CodeCompletionExpr *CompletionExpr;
  DeclContext *DC;
  llvm::Optional<StmtKind> ParentStmtKind;

  SmallVector<Result, 4> Results;

  void sawSolutionImpl(const constraints::Solution &solution) override;

public:
  AfterPoundExprCompletion(CodeCompletionExpr *CompletionExpr, DeclContext *DC,
                           llvm::Optional<StmtKind> ParentStmtKind)
      : CompletionExpr(CompletionExpr), DC(DC), ParentStmtKind(ParentStmtKind) {
  }

  void collectResults(ide::CodeCompletionContext &CompletionCtx);
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_AFTERPOUNDEXPRCOMPLETION_H
