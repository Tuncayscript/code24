// Copyright (c) 2011, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "src/globals.h"
#if defined(TARGET_ARCH_X64)

#include "src/runtime_entry.h"

#if !defined(CODE_PRECOMPILED_RUNTIME)
#include "src/compiler/assembler/assembler.h"
#include "src/stub_code.h"
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

namespace Code {

#define __ assembler->

uword RuntimeEntry::GetEntryPoint() const {
  return reinterpret_cast<uword>(function());
}

}  // namespace dart

#endif  // defined TARGET_ARCH_X64
