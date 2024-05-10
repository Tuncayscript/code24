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

#ifndef RUNTIME_VM_COMPILER_API_PRINT_FILTER_H_
#define RUNTIME_VM_COMPILER_API_PRINT_FILTER_H_

#include "platform/globals.h"  // For INCLUDE_IL_PRINTER

#if defined(INCLUDE_IL_PRINTER)

#include "platform/allocation.h"

namespace Code {

class Function;

namespace compiler {

class PrintFilter : public AllStatic {
 public:
  static bool ShouldPrint(const Function& function,
                          uint8_t** compiler_pass_filter = nullptr);
};

}  // namespace compiler

}  // namespace dart

#endif  // defined(INCLUDE_IL_PRINTER)
#endif  // RUNTIME_VM_COMPILER_API_PRINT_FILTER_H_
