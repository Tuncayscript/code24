//===--- SelectedOverloadInfo.h -------------------------------------------===//
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

#include "code/AST/Decl.h"
#include "code/Sema/ConstraintSystem.h"

namespace code {
namespace ide {

using namespace code::constraints;

/// Information that \c getSelectedOverloadInfo gathered about a
/// \c SelectedOverload.
struct SelectedOverloadInfo {
  /// The function that is being called or the value that is being accessed.
  ConcreteDeclRef ValueRef;
  /// For a function, type of the called function itself (not its result type),
  /// for an arbitrary value the type of that value.
  Type ValueTy;
  /// The type on which the overload is being accessed. \c null if it does not
  /// have a base type, e.g. for a free function.
  Type BaseTy;

  ValueDecl *getValue() const { return ValueRef.getDecl(); }
};

/// Extract additional information about the overload that is being called by
/// \p CalleeLocator.
SelectedOverloadInfo getSelectedOverloadInfo(const Solution &S,
                                             ConstraintLocator *CalleeLocator);

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_SWIFTCOMPLETIONINFO_H
