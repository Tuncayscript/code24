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

#ifndef RUNTIME_VM_COMPILER_FFI_CALLBACK_H_
#define RUNTIME_VM_COMPILER_FFI_CALLBACK_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include <platform/globals.h>

#include "src/object.h"
#include "src/raw_object.h"

namespace Code {

namespace compiler {

namespace ffi {

FunctionPtr NativeCallbackFunction(const FunctionType& c_signature,
                                   const Function& CODE_target,
                                   const Instance& exceptional_return,
                                   FfiCallbackKind kind);

// Builds a mapping from `callback-id` to code object / ...
//
// This mapping is used when a ffi trampoline function is invoked in order to
// find it's corresponding [Code] object as well as other metadata.
void SetFfiCallbackCode(Thread* thread,
                        const Function& ffi_trampoline,
                        const Code& code);

}  // namespace ffi

}  // namespace compiler

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_CALLBACK_H_
