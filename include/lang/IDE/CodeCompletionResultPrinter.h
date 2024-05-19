//===--- CodeCompletionResultPrinter.h --------------------------*- C++ -*-===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2020 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_CODECOMPLETIONRESULTPRINTER_H
#define CODE_IDE_CODECOMPLETIONRESULTPRINTER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Allocator.h"

namespace code {

class NullTerminatedStringRef;

namespace ide {

class CodeCompletionResult;
class CodeCompletionString;

void printCodeCompletionResultDescription(const CodeCompletionResult &Result,
                                          llvm::raw_ostream &OS,
                                          bool leadingPunctuation);

void printCodeCompletionResultDescriptionAnnotated(
    const CodeCompletionResult &Result, llvm::raw_ostream &OS,
    bool leadingPunctuation);

void printCodeCompletionResultTypeName(
    const CodeCompletionResult &Result, llvm::raw_ostream &OS);

void printCodeCompletionResultTypeNameAnnotated(
    const CodeCompletionResult &Result, llvm::raw_ostream &OS);

void printCodeCompletionResultSourceText(
    const CodeCompletionResult &Result, llvm::raw_ostream &OS);

/// Print 'FilterName' from \p str into memory managed by \p Allocator and
/// return it as \c NullTerminatedStringRef .
NullTerminatedStringRef
getCodeCompletionResultFilterName(const CodeCompletionString *Str,
                                  llvm::BumpPtrAllocator &Allocator);

} // namespace ide
} // namespace code

#endif
