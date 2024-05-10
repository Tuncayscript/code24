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
#if defined(CODE_HOST_OS_ANDROID)

#include "src/cpuinfo.h"
#include "src/proccpuinfo.h"

#include "platform/assert.h"

namespace Code {

CpuInfoMethod CpuInfo::method_ = kCpuInfoDefault;
const char* CpuInfo::fields_[kCpuInfoMax] = {};

void CpuInfo::Init() {
#if defined(HOST_ARCH_IA32) || defined(HOST_ARCH_X64)
  fields_[kCpuInfoProcessor] = "vendor_id";
  fields_[kCpuInfoModel] = "model name";
  fields_[kCpuInfoHardware] = "model name";
  fields_[kCpuInfoFeatures] = "flags";
  fields_[kCpuInfoArchitecture] = "CPU architecture";
  method_ = kCpuInfoSystem;
  ProcCpuInfo::Init();
#elif defined(HOST_ARCH_ARM) || defined(HOST_ARCH_ARM64)
  fields_[kCpuInfoProcessor] = "Processor";
  fields_[kCpuInfoModel] = "model name";
  fields_[kCpuInfoHardware] = "Hardware";
  fields_[kCpuInfoFeatures] = "Features";
  fields_[kCpuInfoArchitecture] = "CPU architecture";
  method_ = kCpuInfoSystem;
  ProcCpuInfo::Init();
#elif defined(HOST_ARCH_RISCV64)
  // We only rely on the base Linux configuration of IMAFDC, so don't need
  // dynamic feature detection.
  method_ = kCpuInfoNone;
#else
#error Unrecognized target architecture
#endif
}

void CpuInfo::Cleanup() {
  if (method_ == kCpuInfoSystem) {
    ProcCpuInfo::Cleanup();
  } else {
    ASSERT(method_ == kCpuInfoNone);
  }
}

bool CpuInfo::FieldContains(CpuInfoIndices idx, const char* search_string) {
  if (method_ == kCpuInfoSystem) {
    return ProcCpuInfo::FieldContains(FieldName(idx), search_string);
  } else {
    UNREACHABLE();
  }
}

const char* CpuInfo::ExtractField(CpuInfoIndices idx) {
  if (method_ == kCpuInfoSystem) {
    return ProcCpuInfo::ExtractField(FieldName(idx));
  } else {
    UNREACHABLE();
  }
}

bool CpuInfo::HasField(const char* field) {
  if (method_ == kCpuInfoSystem) {
    return ProcCpuInfo::HasField(field);
  } else if (method_ == kCpuInfoNone) {
    return false;
  } else {
    UNREACHABLE();
  }
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_ANDROID)
