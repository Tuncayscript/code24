//===--- CodeCompletionConsumer.h -----------------------------------------===//
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

#ifndef CODE_IDE_CODECOMPLETIONCONSUMER
#define CODE_IDE_CODECOMPLETIONCONSUMER

#include "code/IDE/CodeCompletionContext.h"
#include "code/Parse/IDEInspectionCallbacks.h"

namespace code {
namespace ide {

struct RequestedCachedModule;

/// An abstract base class for consumers of code completion results.
class CodeCompletionConsumer {
public:
  virtual ~CodeCompletionConsumer() {}
  /// Clients should override this method to receive \p Results.
  virtual void handleResults(CodeCompletionContext &context) = 0;
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_CODECOMPLETIONCONSUMER
