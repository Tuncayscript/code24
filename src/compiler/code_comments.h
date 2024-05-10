/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#ifndef RUNTIME_VM_CODE_COMMENTS_H_
#define RUNTIME_VM_CODE_COMMENTS_H_

#include "src/globals.h"  // For INCLUDE_IL_PRINTER
#if defined(INCLUDE_IL_PRINTER)

namespace Code {

// An abstract representation of comments associated with the given code
// object. We assume that comments are sorted by PCOffset.
class CodeComments {
 public:
  CodeComments() = default;
  virtual ~CodeComments() = default;

  virtual intptr_t Length() const = 0;
  virtual intptr_t PCOffsetAt(intptr_t index) const = 0;
  virtual const char* CommentAt(intptr_t index) const = 0;
};

#if !defined(CODE_PRECOMPILED_RUNTIME)
namespace compiler {
class Assembler;
}
const CodeComments& CreateCommentsFrom(compiler::Assembler* assembler);
#endif

}  // namespace dart

#endif  // defined(INCLUDE_IL_PRINTER)
#endif  // RUNTIME_VM_CODE_COMMENTS_H_
