//===--- CodeCompletion.h - Routines for code completion --------*- C++ -*-===//
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

#ifndef CODE_IDE_CODECOMPLETION_H
#define CODE_IDE_CODECOMPLETION_H

#include "code/IDE/CodeCompletionConsumer.h"
#include "code/IDE/CodeCompletionContext.h"
#include "code/IDE/CodeCompletionResult.h"
#include "code/IDE/CodeCompletionResultSink.h"
#include "code/IDE/CompletionLookup.h"

namespace code {
class IDEInspectionCallbacksFactory;
class Decl;
class DeclContext;
class FrontendOptions;
class ModuleDecl;
class SourceFile;

namespace ide {

class CodeCompletionCache;
struct RequestedCachedModule;

/// A routine to remove code completion tokens from code completion
/// tests.
///
/// \code
/// code-completion-token:
///     '#^' identifier '^#'
/// \endcode
///
/// \param Input test source code.
/// \param TokenName names the token whose position should be returned in
/// \p CompletionOffset.
/// \param CompletionOffset set to ~0U on error, or to a 0-based byte offset on
/// success.
///
/// \returns test source code without any code completion tokens.
std::string removeCodeCompletionTokens(StringRef Input,
                                       StringRef TokenName,
                                       unsigned *CompletionOffset);

template <typename T>
ArrayRef<T> copyArray(llvm::BumpPtrAllocator &Allocator,
                            ArrayRef<T> Arr) {
  T *Buffer = Allocator.Allocate<T>(Arr.size());
  std::copy(Arr.begin(), Arr.end(), Buffer);
  return llvm::makeArrayRef(Buffer, Arr.size());
}

bool isDynamicLookup(Type T);

void postProcessCompletionResults(
    MutableArrayRef<CodeCompletionResult *> results, CompletionKind Kind,
    const DeclContext *DC, CodeCompletionResultSink *Sink);

void collectCompletionResults(CodeCompletionContext &CompletionContext,
                              CompletionLookup &Lookup, DeclContext *DC,
                              const ExpectedTypeContext &TypeContext,
                              bool CanCurrDeclContextHandleAsync);

/// Create a factory for code completion callbacks.
IDEInspectionCallbacksFactory *
makeCodeCompletionCallbacksFactory(CodeCompletionContext &CompletionContext,
                                   CodeCompletionConsumer &Consumer);

/// Lookup the top-level code completions from \p module and store them in
/// \p targetSink.
///
/// Results are looked up as if in \p currDeclContext, which may be null.
void lookupCodeCompletionResultsFromModule(CodeCompletionResultSink &targetSink,
                                           const ModuleDecl *module,
                                           ArrayRef<std::string> accessPath,
                                           bool needLeadingDot,
                                           const SourceFile *SF);

void addExprKeywords(CodeCompletionResultSink &Sink, DeclContext *DC);

void addSuperKeyword(CodeCompletionResultSink &Sink, DeclContext *DC);

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_CODECOMPLETION_H
