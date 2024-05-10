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

#ifndef RUNTIME_VM_CPU_X64_H_
#define RUNTIME_VM_CPU_X64_H_

#if !defined(RUNTIME_VM_CPU_H_)
#error Do not include cpu_x64.h directly; use cpu.h instead.
#endif

#include "src/allocation.h"
#include "src/flags.h"

namespace Code {

DECLARE_FLAG(bool, use_sse41);

class HostCPUFeatures : public AllStatic {
 public:
  static void Init();
  static void Cleanup();
  static const char* hardware() {
    DEBUG_ASSERT(initialized_);
    return hardware_;
  }
  static bool sse2_supported() {
    DEBUG_ASSERT(initialized_);
    return sse2_supported_;
  }
  static bool sse4_1_supported() {
    DEBUG_ASSERT(initialized_);
    return sse4_1_supported_ && FLAG_use_sse41 && !FLAG_target_unknown_cpu;
  }
  static bool popcnt_supported() {
    DEBUG_ASSERT(initialized_);
    return popcnt_supported_ && !FLAG_target_unknown_cpu;
  }
  static bool abm_supported() {
    DEBUG_ASSERT(initialized_);
    return abm_supported_ && !FLAG_target_unknown_cpu;
  }

 private:
  static const char* hardware_;
  static bool sse2_supported_;
  static bool sse4_1_supported_;
  static bool popcnt_supported_;
  static bool abm_supported_;
#if defined(DEBUG)
  static bool initialized_;
#endif
};

class TargetCPUFeatures : public AllStatic {
 public:
  static void Init() { HostCPUFeatures::Init(); }
  static void Cleanup() { HostCPUFeatures::Cleanup(); }
  static const char* hardware() { return HostCPUFeatures::hardware(); }
  static bool sse2_supported() { return HostCPUFeatures::sse2_supported(); }
  static bool sse4_1_supported() { return HostCPUFeatures::sse4_1_supported(); }
  static bool popcnt_supported() { return HostCPUFeatures::popcnt_supported(); }
  static bool abm_supported() { return HostCPUFeatures::abm_supported(); }
  static bool double_truncate_round_supported() {
    return HostCPUFeatures::sse4_1_supported();
  }
};

}  // namespace dart

#endif  // RUNTIME_VM_CPU_X64_H_
