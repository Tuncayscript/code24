/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, June 6, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef CODE_RUNTIME_ACCESSIBLE_FUNCTION_H
#define CODE_RUNTIME_ACCESSIBLE_FUNCTION_H

#include "code/ABI/Metadata.h"

#include <cstdint>

namespace code {
namespace runtime {

SWIFT_RUNTIME_STDLIB_SPI
const AccessibleFunctionRecord *
code_findAccessibleFunction(const char *targetNameStart,
                             size_t targetNameLength);

} // end namespace runtime
} // end namespace code

#endif
