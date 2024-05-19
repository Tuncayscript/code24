//===--- TypeContextInfo.h --------------------------------------*- C++ -*-===//
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

#ifndef CODE_IDE_TYPECONTEXTINFO_H
#define CODE_IDE_TYPECONTEXTINFO_H

#include "code/AST/Type.h"
#include "code/Basic/LLVM.h"

namespace code {
class IDEInspectionCallbacksFactory;

namespace ide {

/// A result item for context info query.
class TypeContextInfoItem {
public:
  /// Possible expected type.
  Type ExpectedTy;
  /// Members of \c ExpectedTy which can be referenced by "Implicit Member
  /// Expression".
  SmallVector<ValueDecl *, 0> ImplicitMembers;

  TypeContextInfoItem(Type ExpectedTy) : ExpectedTy(ExpectedTy) {}
};

/// An abstract base class for consumers of context info results.
class TypeContextInfoConsumer {
public:
  virtual ~TypeContextInfoConsumer() {}
  virtual void handleResults(ArrayRef<TypeContextInfoItem>) = 0;
};

/// Create a factory for code completion callbacks.
IDEInspectionCallbacksFactory *
makeTypeContextInfoCallbacksFactory(TypeContextInfoConsumer &Consumer);

} // namespace ide
} // namespace code

#endif // CODE_IDE_TYPECONTEXTINFO_H
