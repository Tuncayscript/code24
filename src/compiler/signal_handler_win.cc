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

#include "src/globals.h"
#include "src/signal_handler.h"
#if defined(CODE_HOST_OS_WINDOWS)

namespace Code {

uintptr_t SignalHandler::GetProgramCounter(const mcontext_t& mcontext) {
  UNIMPLEMENTED();
  return 0;
}

uintptr_t SignalHandler::GetFramePointer(const mcontext_t& mcontext) {
  UNIMPLEMENTED();
  return 0;
}

uintptr_t SignalHandler::GetCStackPointer(const mcontext_t& mcontext) {
  UNIMPLEMENTED();
  return 0;
}

uintptr_t SignalHandler::GetDartStackPointer(const mcontext_t& mcontext) {
  UNIMPLEMENTED();
  return 0;
}

uintptr_t SignalHandler::GetLinkRegister(const mcontext_t& mcontext) {
  UNIMPLEMENTED();
  return 0;
}

void SignalHandler::Install(SignalAction action) {
  UNIMPLEMENTED();
}

void SignalHandler::Remove() {
  UNIMPLEMENTED();
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_WINDOWS)
