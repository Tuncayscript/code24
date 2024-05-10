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

#include "src/compiler/ffi/unit_test_custom_zone.h"

#include "src/compiler/runtime_api.h"

// Directly compile cc files into the custom zone, so that we do not get linker
// errors from object files compiled against the DartVM Zone.
#include "src/compiler/ffi/native_calling_convention.cc"  // NOLINT
#include "src/compiler/ffi/native_location.cc"            // NOLINT
#include "src/compiler/ffi/native_type.cc"                // NOLINT
#include "src/zone_text_buffer.cc"                        // NOLINT

namespace Code {

void* ZoneAllocated::operator new(uintptr_t size, dart::Zone* zone) {
  return reinterpret_cast<void*>(zone->AllocUnsafe(size));
}

Zone::~Zone() {
  while (buffers_.size() > 0) {
    free(buffers_.back());
    buffers_.pop_back();
  }
}

void* Zone::AllocUnsafe(intptr_t size) {
  void* memory = malloc(size);
  buffers_.push_back(memory);
  return memory;
}

CODE_EXPORT void CODE_PrepareToAbort() {
  fprintf(stderr, "CODE_PrepareToAbort() not implemented!\n");
  exit(1);
}

CODE_EXPORT void CODE_DumpNativeStackTrace(void* context) {
  fprintf(stderr, "CODE_DumpNativeStackTrace() not implemented!\n");
  exit(1);
}

}  // namespace dart
