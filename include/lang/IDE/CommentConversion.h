//===--- CommentConversion.h - Conversion of comments to other formats ----===//
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

#ifndef CODE_IDE_COMMENT_CONVERSION_H
#define CODE_IDE_COMMENT_CONVERSION_H

#include "code/Basic/LLVM.h"
#include "code/AST/TypeOrExtensionDecl.h"
#include <memory>
#include <string>

namespace code {
class Decl;
class DocComment;

namespace ide {

/// If the declaration has a documentation comment, prints the comment to \p OS
/// in Clang-like XML format.
///
/// \returns true if the declaration has a documentation comment.
bool getDocumentationCommentAsXML(
  const Decl *D, raw_ostream &OS,
  TypeOrExtensionDecl SynthesizedTarget = TypeOrExtensionDecl());

/// If the declaration has a documentation comment and a localization key,
/// print it into the given output stream and return true. Else, return false.
bool getLocalizationKey(const Decl *D, raw_ostream &OS);

/// Converts the given comment to Doxygen.
void getDocumentationCommentAsDoxygen(const DocComment *DC, raw_ostream &OS);

/// Extract and normalize text from the given comment.
std::string extractPlainTextFromComment(const StringRef Text);

/// Given the raw text in markup format, convert its content to xml.
bool convertMarkupToXML(StringRef Text, raw_ostream &OS);

} // namespace ide
} // namespace code

#endif // CODE_IDE_COMMENT_CONVERSION_H

