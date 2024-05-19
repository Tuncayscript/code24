//===--- CodeCompletionStringPrinter.h ------------------------------------===//
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

#ifndef CODE_IDE_CODECOMPLETIONRESULTSTRINGPRINTER_H
#define CODE_IDE_CODECOMPLETIONRESULTSTRINGPRINTER_H

#include "code/AST/ASTPrinter.h"
#include "code/IDE/CodeCompletionString.h"

namespace code {
namespace ide {

/// 'ASTPrinter' printing to 'CodeCompletionString' with appropriate ChunkKind.
/// This is mainly used for printing types and override completions.
class CodeCompletionStringPrinter : public ASTPrinter {
protected:
  using ChunkKind = CodeCompletionString::Chunk::ChunkKind;

private:
  CodeCompletionResultBuilder &Builder;
  SmallString<16> Buffer;
  ChunkKind CurrChunkKind = ChunkKind::Text;
  ChunkKind NextChunkKind = ChunkKind::Text;
  SmallVector<PrintStructureKind, 2> StructureStack;
  unsigned int TypeDepth = 0;
  bool InPreamble = false;

  bool isCurrentStructureKind(PrintStructureKind Kind) const {
    return !StructureStack.empty() && StructureStack.back() == Kind;
  }

  bool isInType() const { return TypeDepth > 0; }

  llvm::Optional<ChunkKind>
  getChunkKindForPrintNameContext(PrintNameContext context) const;

  llvm::Optional<ChunkKind>
  getChunkKindForStructureKind(PrintStructureKind Kind) const;

  void startNestedGroup(ChunkKind Kind);

  void endNestedGroup();

protected:
  void setNextChunkKind(ChunkKind Kind) { NextChunkKind = Kind; }

public:
  CodeCompletionStringPrinter(CodeCompletionResultBuilder &Builder)
      : Builder(Builder) {}

  ~CodeCompletionStringPrinter() {
    // Flush the remainings.
    flush();
  }

  void flush();

  /// Start \c AttributeAndModifierListBegin group. This must be called before
  /// any attributes/modifiers printed to the output when printing an override
  /// compleion.
  void startPreamble();

  /// End the current \c AttributeAndModifierListBegin group if it's still open.
  /// This is automatically called before the main part of the signature.
  void endPremable();

  /// Implement \c ASTPrinter .
public:
  void printText(StringRef Text) override;

  void printTypeRef(
      Type T, const TypeDecl *TD, Identifier Name,
      PrintNameContext NameContext = PrintNameContext::Normal) override;

  void printDeclLoc(const Decl *D) override;

  void printDeclNameEndLoc(const Decl *D) override;

  void printNamePre(PrintNameContext context) override;

  void printNamePost(PrintNameContext context) override;

  void printTypePre(const TypeLoc &TL) override;

  void printTypePost(const TypeLoc &TL) override;

  void printStructurePre(PrintStructureKind Kind, const Decl *D) override;

  void printStructurePost(PrintStructureKind Kind, const Decl *D) override;
};

} // end namespace ide
} // end namespace code

#endif // CODE_IDE_CODECOMPLETIONRESULTSTRINGPRINTER_H
