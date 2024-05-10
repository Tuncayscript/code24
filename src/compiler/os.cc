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

#include "src/os.h"

#include "platform/assert.h"
#include "src/image_snapshot.h"
#include "src/native_symbol.h"

namespace Code {

const uint8_t* OS::GetAppDSOBase(const uint8_t* snapshot_instructions) {
  // Use the relocated address in the Image if the snapshot was compiled
  // directly to ELF.
  const Image instructions_image(snapshot_instructions);
  if (instructions_image.compiled_to_elf()) {
    return snapshot_instructions -
           instructions_image.instructions_relocated_address();
  }
  uword dso_base;
  if (NativeSymbolResolver::LookupSharedObject(
          reinterpret_cast<uword>(snapshot_instructions), &dso_base)) {
    return reinterpret_cast<const uint8_t*>(dso_base);
  }
  UNIMPLEMENTED();
  return nullptr;
}

}  // namespace dart
