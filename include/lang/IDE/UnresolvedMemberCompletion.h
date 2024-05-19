//===--- UnresolvedMemberCompletion.h -------------------------------------===//
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

#ifndef CODE_IDE_UNRESOLVEDMEMBERCOMPLETION_H
#define CODE_IDE_UNRESOLVEDMEMBERCOMPLETION_H

#include "code/IDE/CodeCompletionConsumer.h"
#include "code/IDE/CodeCompletionContext.h"
#include "code/IDE/TypeCheckCompletionCallback.h"

namespace code {
namespace ide {

/// Used to collect and store information needed to perform unresolved member
/// completion (\c CompletionKind::UnresolvedMember ) from the solutions
/// formed during expression type-checking.
class UnresolvedMemberTypeCheckCompletionCallback
    : public TypeCheckCompletionCallback {
  struct Result {
    Type ExpectedTy;
    bool IsImplicitSingleExpressionReturn;

    /// Whether the surrounding context is async and thus calling async
    /// functions is supported.
    bool IsInAsyncContext;

    /// Checks whether this result has the same \c BaseTy and \c BaseDecl as
    /// \p Other and if the two can thus be merged to be one value lookup in
    /// \c deliverResults.
    bool canBeMergedWith(const Result &Other, DeclContext &DC) const;

    /// Merge this result with \p Other. Assumes that they can be merged.
    void merge(const Result &Other, DeclContext &DC);
  };

  CodeCompletionExpr *CompletionExpr;
  DeclContext *DC;

  SmallVector<Result, 4> ExprResults;
  SmallVector<Result, 1> EnumPatternTypes;

  /// Add a result to \c Results, merging it with an existing result, if
  /// possible.
  void addExprResult(const Result &Res);

  void sawSolutionImpl(const constraints::Solution &solution) override;

public:
  UnresolvedMemberTypeCheckCompletionCallback(
      CodeCompletionExpr *CompletionExpr, DeclContext *DC)
      : CompletionExpr(CompletionExpr), DC(DC) {}

  void collectResults(DeclContext *DC, SourceLoc DotLoc,
                      ide::CodeCompletionContext &CompletionCtx);
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_UNRESOLVEDMEMBERCOMPLETION_H
