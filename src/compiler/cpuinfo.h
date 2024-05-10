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

#ifndef RUNTIME_VM_CPUINFO_H_
#define RUNTIME_VM_CPUINFO_H_

#include "platform/assert.h"
#include "platform/utils.h"
#include "src/allocation.h"

namespace Code {

// Indices into cpuinfo field name arrays.
enum CpuInfoIndices {
  kCpuInfoProcessor = 0,
  kCpuInfoModel = 1,
  kCpuInfoHardware = 2,
  kCpuInfoFeatures = 3,
  kCpuInfoArchitecture = 4,
  kCpuInfoMax = 5,
};

// For Intel architectures, the method to use to get CPU information.
enum CpuInfoMethod {
  // Use the cpuid instruction.
  kCpuInfoCpuId,

  // Use system calls.
  kCpuInfoSystem,

  // Don't query anything.
  kCpuInfoNone,

  // Use whatever the default is for a particular OS:
  // Linux, Windows -> CpuId,
  // Android, MacOS -> System.
  kCpuInfoDefault,
};

class CpuInfo : public AllStatic {
 public:
  static void Init();
  static void Cleanup();

  static const char* FieldName(CpuInfoIndices idx) {
    ASSERT((idx >= 0) && (idx < kCpuInfoMax));
    return fields_[idx];
  }

  // Returns true if the cpuinfo field contains the string.
  static bool FieldContains(CpuInfoIndices idx, const char* search_string);

  // Returns true if the cpuinfo field [field] exists and is non-empty.
  static bool HasField(const char* field);

  // Returns the field describing the CPU model. Caller is responsible for
  // freeing the result.
  static const char* GetCpuModel() {
    if (HasField(FieldName(kCpuInfoHardware))) {
      return ExtractField(kCpuInfoHardware);
    } else {
      return Utils::StrDup("Unknown");
    }
  }

 private:
  // Returns the field. Caller is responsible for freeing the result.
  static const char* ExtractField(CpuInfoIndices idx);

  // The method to use to acquire info about the CPU.
  static CpuInfoMethod method_;

  // Cpuinfo field names.
  static const char* fields_[kCpuInfoMax];
};

}  // namespace dart

#endif  // RUNTIME_VM_CPUINFO_H_
