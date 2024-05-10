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

// A simple interpreter for the Irregexp byte code.

#ifndef RUNTIME_VM_REGEXP_INTERPRETER_H_
#define RUNTIME_VM_REGEXP_INTERPRETER_H_

#include "src/allocation.h"
#include "src/object.h"
#include "src/zone.h"

namespace Code {

class IrregexpInterpreter : public AllStatic {
 public:
  // Returns True in case of a success, False in case of a failure,
  // Null in case of internal exception,
  // Error in case VM error has to propagated up to the caller.
  static ObjectPtr Match(const TypedData& bytecode,
                         const String& subject,
                         int32_t* captures,
                         int32_t start_position);
};

}  // namespace dart

#endif  // RUNTIME_VM_REGEXP_INTERPRETER_H_
