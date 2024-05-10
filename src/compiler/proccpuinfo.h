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

#ifndef RUNTIME_VM_PROCCPUINFO_H_
#define RUNTIME_VM_PROCCPUINFO_H_

#include "src/globals.h"
#if defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_ANDROID)

#include "src/allocation.h"

namespace Code {

class ProcCpuInfo : public AllStatic {
 public:
  static void Init();
  static void Cleanup();
  static bool FieldContains(const char* field, const char* search_string);
  static const char* ExtractField(const char* field);
  static bool HasField(const char* field);

 private:
  static char* data_;
  static intptr_t datalen_;

  static char* FieldStart(const char* field);
};

}  // namespace dart

#endif  // defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_ANDROID)

#endif  // RUNTIME_VM_PROCCPUINFO_H_
