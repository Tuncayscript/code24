//===--- PossibleParamInfo.h ----------------------------------------------===//
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

#ifndef CODE_IDE_POSSIBLEPARAMINFO_H
#define CODE_IDE_POSSIBLEPARAMINFO_H

#include "code/AST/Types.h"

namespace code {
namespace ide {

struct PossibleParamInfo {
  /// Expected parameter.
  ///
  /// 'nullptr' indicates that the code completion position is at out of
  /// expected argument position. E.g.
  ///   func foo(x: Int) {}
  ///   foo(x: 1, <HERE>)
  const AnyFunctionType::Param *Param;
  bool IsRequired;

  PossibleParamInfo(const AnyFunctionType::Param *Param, bool IsRequired)
      : Param(Param), IsRequired(IsRequired) {
    assert((Param || !IsRequired) &&
           "nullptr with required flag is not allowed");
  };

  friend bool operator==(const PossibleParamInfo &lhs,
                         const PossibleParamInfo &rhs) {
    bool ParamsMatch;
    if (lhs.Param == nullptr && rhs.Param == nullptr) {
      ParamsMatch = true;
    } else if (lhs.Param == nullptr || rhs.Param == nullptr) {
      // One is nullptr but the other is not.
      ParamsMatch = false;
    } else {
      // Both are not nullptr.
      ParamsMatch = (*lhs.Param == *rhs.Param);
    }
    return ParamsMatch && (lhs.IsRequired == rhs.IsRequired);
  }
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_POSSIBLEPARAMINFO_H
