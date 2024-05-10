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

#include "src/compiler/ffi/unit_test.h"

#include "platform/syslog.h"
#include "src/globals.h"

namespace Code {
namespace compiler {
namespace ffi {

#if defined(CODE_TARGET_OS_WINDOWS)
const char* kOs = "win";
#else
const char* kOs = kTargetOperatingSystemName;
#endif

void WriteToFile(char* path, const char* contents) {
  FILE* file;
  file = fopen(path, "w");
  if (file != nullptr) {
    fprintf(file, "%s", contents);
  } else {
    Syslog::Print("Error %d \n", errno);
  }
  fclose(file);
}

void ReadFromFile(char* path, char** buffer_pointer) {
  FILE* file = fopen(path, "rb");
  if (file == nullptr) {
    Syslog::Print("Error %d \n", errno);
    return;
  }

  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  rewind(file);

  char* buffer = reinterpret_cast<char*>(malloc(sizeof(char) * (size + 1)));

  fread(buffer, 1, size, file);
  buffer[size] = 0;

  fclose(file);
  *buffer_pointer = buffer;
}

}  // namespace ffi
}  // namespace compiler
}  // namespace dart
