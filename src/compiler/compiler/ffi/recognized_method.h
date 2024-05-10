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

#ifndef RUNTIME_VM_COMPILER_FFI_RECOGNIZED_METHOD_H_
#define RUNTIME_VM_COMPILER_FFI_RECOGNIZED_METHOD_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include <platform/globals.h>

#include "src/compiler/backend/il.h"
#include "src/compiler/method_recognizer.h"

namespace Code {

namespace compiler {

namespace ffi {

// TypedData class id for a NativeType type, except for Void and NativeFunction.
classid_t ElementTypedDataCid(classid_t class_id);

// ExternalTypedData class id for a NativeType type, except for Void,
// NativeFunction, IntPtr and Pointer.
classid_t ElementExternalTypedDataCid(classid_t class_id);

// Returns the kFFi<type>Cid for the recognized load/store method [kind].
classid_t RecognizedMethodTypeArgCid(MethodRecognizer::Kind kind);

AlignmentType RecognizedMethodAlignment(MethodRecognizer::Kind kind);

MethodRecognizer::Kind FfiLoad(const NativeType& native_type);
MethodRecognizer::Kind FfiStore(const NativeType& native_type);

}  // namespace ffi

}  // namespace compiler

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_RECOGNIZED_METHOD_H_
