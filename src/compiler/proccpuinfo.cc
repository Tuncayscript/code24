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
#if defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_ANDROID)

#include "src/proccpuinfo.h"

#include <ctype.h>   // NOLINT
#include <string.h>  // NOLINT

#include "platform/assert.h"

namespace Code {

char* ProcCpuInfo::data_ = nullptr;
intptr_t ProcCpuInfo::datalen_ = 0;

void ProcCpuInfo::Init() {
  // Get the size of the cpuinfo file by reading it until the end. This is
  // required because files under /proc do not always return a valid size
  // when using fseek(0, SEEK_END) + ftell(). Nor can they be mmap()-ed.
  static const char PATHNAME[] = "/proc/cpuinfo";
  FILE* fp = fopen(PATHNAME, "r");
  if (fp != nullptr) {
    for (;;) {
      char buffer[256];
      size_t n = fread(buffer, 1, sizeof(buffer), fp);
      if (n == 0) {
        break;
      }
      datalen_ += n;
    }
    fclose(fp);
  }

  // Read the contents of the cpuinfo file.
  data_ = reinterpret_cast<char*>(malloc(datalen_ + 1));
  fp = fopen(PATHNAME, "r");
  if (fp != nullptr) {
    for (intptr_t offset = 0; offset < datalen_;) {
      size_t n = fread(data_ + offset, 1, datalen_ - offset, fp);
      if (n == 0) {
        break;
      }
      offset += n;
    }
    fclose(fp);
  }

  // Zero-terminate the data.
  data_[datalen_] = '\0';
}

void ProcCpuInfo::Cleanup() {
  ASSERT(data_);
  free(data_);
  data_ = nullptr;
}

char* ProcCpuInfo::FieldStart(const char* field) {
  // Look for first field occurrence, and ensure it starts the line.
  size_t fieldlen = strlen(field);
  char* p = data_;
  for (;;) {
    p = strstr(p, field);
    if (p == nullptr) {
      return nullptr;
    }
    if (p == data_ || p[-1] == '\n') {
      break;
    }
    p += fieldlen;
  }

  // Skip to the first colon followed by a space.
  p = strchr(p + fieldlen, ':');
  if (p == nullptr || (isspace(p[1]) == 0)) {
    return nullptr;
  }
  p += 2;

  return p;
}

bool ProcCpuInfo::FieldContains(const char* field, const char* search_string) {
  ASSERT(data_ != nullptr);
  ASSERT(search_string != nullptr);

  char* p = FieldStart(field);
  if (p == nullptr) {
    return false;
  }

  // Find the end of the line.
  char* q = strchr(p, '\n');
  if (q == nullptr) {
    q = data_ + datalen_;
  }

  char saved_end = *q;
  *q = '\0';
  bool ret = (strcasestr(p, search_string) != nullptr);
  *q = saved_end;

  return ret;
}

// Extract the content of a the first occurrence of a given field in
// the content of the cpuinfo file and return it as a heap-allocated
// string that must be freed by the caller using free.
// Return nullptr if not found.
const char* ProcCpuInfo::ExtractField(const char* field) {
  ASSERT(field != nullptr);
  ASSERT(data_ != nullptr);

  char* p = FieldStart(field);
  if (p == nullptr) {
    return nullptr;
  }

  // Find the end of the line.
  char* q = strchr(p, '\n');
  if (q == nullptr) {
    q = data_ + datalen_;
  }

  intptr_t len = q - p;
  char* result = reinterpret_cast<char*>(malloc(len + 1));
  // Copy the line into result, leaving enough room for a null-terminator.
  char saved_end = *q;
  *q = '\0';
  strncpy(result, p, len);
  result[len] = '\0';
  *q = saved_end;

  return result;
}

bool ProcCpuInfo::HasField(const char* field) {
  ASSERT(field != nullptr);
  ASSERT(data_ != nullptr);
  return (FieldStart(field) != nullptr);
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_ANDROID)
