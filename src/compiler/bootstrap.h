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

#ifndef RUNTIME_VM_BOOTSTRAP_H_
#define RUNTIME_VM_BOOTSTRAP_H_

#include "include/CODE_api.h"
#include "src/allocation.h"
#include "src/tagged_pointer.h"

namespace Code {

// Forward declarations.
namespace kernel {
class Program;
}

class Bootstrap : public AllStatic {
 public:
  // Compile the bootstrap libraries, either from sources or a Kernel program.
  // If program is nullptr, compile from sources or source paths linked into
  // the VM.  If it is non-null it represents the Kernel program to use for
  // bootstrapping.
  // The caller of this function is responsible for managing the kernel
  // program's memory.
  static ErrorPtr DoBootstrapping(const uint8_t* kernel_buffer,
                                  intptr_t kernel_buffer_size);

  static void SetupNativeResolver();
  static bool IsBootstrapResolver(CODE_NativeEntryResolver resolver);
};

}  // namespace dart

#endif  // RUNTIME_VM_BOOTSTRAP_H_
