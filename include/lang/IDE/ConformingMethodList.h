//===--- ConformingMethodList.h --- -----------------------------*- C++ -*-===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2019 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_CONFORMINGMETHODLIST_H
#define CODE_IDE_CONFORMINGMETHODLIST_H

#include "code/AST/Type.h"
#include "code/Basic/LLVM.h"

namespace code {
class IDEInspectionCallbacksFactory;

namespace ide {

/// A result item for context info query.
class ConformingMethodListResult {
public:
  /// The decl context of the parsed expression.
  DeclContext *DC;

  /// The resolved type of the expression.
  Type ExprType;

  /// Methods which satisfy the criteria.
  SmallVector<ValueDecl *, 0> Members;

  ConformingMethodListResult(DeclContext *DC, Type ExprType)
      : DC(DC), ExprType(ExprType) {}
};

/// An abstract base class for consumers of context info results.
class ConformingMethodListConsumer {
public:
  virtual ~ConformingMethodListConsumer() {}
  virtual void handleResult(const ConformingMethodListResult &result) = 0;
};

/// Create a factory for code completion callbacks.
IDEInspectionCallbacksFactory *makeConformingMethodListCallbacksFactory(
    ArrayRef<const char *> expectedTypeNames,
    ConformingMethodListConsumer &Consumer);

} // namespace ide
} // namespace code

#endif // CODE_IDE_CONFORMINGMETHODLIST_H
