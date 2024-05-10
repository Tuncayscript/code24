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

#include <setjmp.h>  // NOLINT
#include <stdlib.h>

#include "src/globals.h"
#if defined(TARGET_ARCH_X64)

// Only build the simulator if not compiling for real X64 hardware.
#if defined(USING_SIMULATOR)

#include "src/simulator.h"

#include "src/heap/safepoint.h"
#include "src/isolate.h"

namespace Code {

// Get the active Simulator for the current isolate.
Simulator* Simulator::Current() {
  Isolate* isolate = Isolate::Current();
  Simulator* simulator = isolate->simulator();
  if (simulator == nullptr) {
    NoSafepointScope no_safepoint;
    simulator = new Simulator();
    isolate->set_simulator(simulator);
  }
  return simulator;
}

void Simulator::Init() {}

Simulator::Simulator() {}

Simulator::~Simulator() {
  Isolate* isolate = Isolate::Current();
  if (isolate != nullptr) {
    isolate->set_simulator(nullptr);
  }
}

int64_t Simulator::Call(int64_t entry,
                        int64_t parameter0,
                        int64_t parameter1,
                        int64_t parameter2,
                        int64_t parameter3,
                        bool fp_return,
                        bool fp_args) {
  UNIMPLEMENTED();
}

void Simulator::JumpToFrame(uword pc, uword sp, uword fp, Thread* thread) {
  UNIMPLEMENTED();
}

uword Simulator::RedirectExternalReference(uword function,
                                           CallKind call_kind,
                                           int argument_count) {
  return 0;
}

uword Simulator::FunctionForRedirect(uword redirect) {
  return 0;
}

}  // namespace dart

#endif  // !defined(USING_SIMULATOR)

#endif  // defined TARGET_ARCH_X64
