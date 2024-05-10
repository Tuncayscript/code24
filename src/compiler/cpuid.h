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

#ifndef RUNTIME_VM_CPUID_H_
#define RUNTIME_VM_CPUID_H_

#include "src/globals.h"
#if !defined(CODE_HOST_OS_MACOS)
#include "src/allocation.h"
#include "src/cpuinfo.h"

namespace Code {

class CpuId : public AllStatic {
 public:
#if defined(HOST_ARCH_IA32) || defined(HOST_ARCH_X64)
  static void Init();
  static void Cleanup();

  // Caller must free the result of field.
  static const char* field(CpuInfoIndices idx);
#else
  static void Init() {}
  static void Cleanup() {}
  static const char* field(CpuInfoIndices idx) { return nullptr; }
#endif

 private:
  // Caller must free the result of id_string and brand_string.
  static const char* id_string();
  static const char* brand_string();

  static bool sse2() { return sse2_; }
  static bool sse41() { return sse41_; }
  static bool popcnt() { return popcnt_; }
  static bool abm() { return abm_; }

  static bool sse2_;
  static bool sse41_;
  static bool popcnt_;
  static bool abm_;
  static const char* id_string_;
  static const char* brand_string_;
};

}  // namespace dart

#endif  // !defined(CODE_HOST_OS_MACOS)
#endif  // RUNTIME_VM_CPUID_H_
