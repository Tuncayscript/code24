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

#ifndef RUNTIME_VM_COMPILER_FRONTEND_KERNEL_FINGERPRINTS_H_
#define RUNTIME_VM_COMPILER_FRONTEND_KERNEL_FINGERPRINTS_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "platform/allocation.h"
#include "src/object.h"

namespace Code {
namespace kernel {

class KernelSourceFingerprintHelper : public AllStatic {
 public:
  static uint32_t CalculateClassFingerprint(const Class& klass);
  static uint32_t CalculateFieldFingerprint(const Field& field);
  static uint32_t CalculateFunctionFingerprint(const Function& func);
};

}  // namespace kernel
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FRONTEND_KERNEL_FINGERPRINTS_H_
