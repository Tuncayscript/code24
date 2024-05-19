//===--- CursorInfo.h --- ---------------------------------------*- C++ -*-===//
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

#ifndef CODE_IDE_CURSORINFO_H
#define CODE_IDE_CURSORINFO_H

#include "code/AST/Type.h"
#include "code/Basic/LLVM.h"
#include "code/IDE/Utils.h"

namespace code {
class IDEInspectionCallbacksFactory;

namespace ide {

/// An abstract base class for consumers of context info results.
class CursorInfoConsumer {
public:
  virtual ~CursorInfoConsumer() {}
  virtual void handleResults(std::vector<ResolvedCursorInfoPtr>) = 0;
};

/// Create a factory for code completion callbacks.
IDEInspectionCallbacksFactory *
makeCursorInfoCallbacksFactory(CursorInfoConsumer &Consumer,
                               SourceLoc RequestedLoc);

} // namespace ide
} // namespace code

#endif // CODE_IDE_CURSORINFO_H
