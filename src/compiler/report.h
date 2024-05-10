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

#ifndef RUNTIME_VM_REPORT_H_
#define RUNTIME_VM_REPORT_H_

#include "src/allocation.h"
#include "src/tagged_pointer.h"
#include "src/token_position.h"

namespace Code {

// Forward declarations.
class Error;
class ICData;
class Script;
class StackFrame;
class String;

class Report : AllStatic {
 public:
  enum Kind {
    kWarning,
    kError,
    kBailout,
  };

  static constexpr bool AtLocation = false;
  static constexpr bool AfterLocation = true;

  // Report an already formatted error via a long jump.
  CODE_NORETURN static void LongJump(const Error& error);

  // Concatenate and report an already formatted error and a new error message.
  CODE_NORETURN static void LongJumpF(const Error& prev_error,
                                      const Script& script,
                                      TokenPosition token_pos,
                                      const char* format,
                                      ...) PRINTF_ATTRIBUTE(4, 5);
  CODE_NORETURN static void LongJumpV(const Error& prev_error,
                                      const Script& script,
                                      TokenPosition token_pos,
                                      const char* format,
                                      va_list args);

  // Report a warning/jswarning/error/bailout message.
  static void MessageF(Kind kind,
                       const Script& script,
                       TokenPosition token_pos,
                       bool report_after_token,
                       const char* format,
                       ...) PRINTF_ATTRIBUTE(5, 6);
  static void MessageV(Kind kind,
                       const Script& script,
                       TokenPosition token_pos,
                       bool report_after_token,
                       const char* format,
                       va_list args);

  // Prepend a source snippet to the message.
  // A null script means no source and a negative token_pos means no position.
  static StringPtr PrependSnippet(Kind kind,
                                  const Script& script,
                                  TokenPosition token_pos,
                                  bool report_after_token,
                                  const String& message);

 private:
  DISALLOW_COPY_AND_ASSIGN(Report);
};

}  // namespace dart

#endif  // RUNTIME_VM_REPORT_H_
