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

#ifndef RUNTIME_VM_CPU_RISCV_H_
#define RUNTIME_VM_CPU_RISCV_H_

#if !defined(RUNTIME_VM_CPU_H_)
#error Do not include cpu_riscv.h directly; use cpu.h instead.
#endif

#include "src/allocation.h"
#include "src/simulator.h"

namespace Code {

// TargetCPUFeatures gives CPU features for the architecture that we are
// generating code for. HostCPUFeatures gives the CPU features for the
// architecture that we are actually running on. When the architectures
// are the same, TargetCPUFeatures will query HostCPUFeatures. When they are
// different (i.e. we are running in a simulator), HostCPUFeatures will
// additionally mock the options needed for the target architecture so that
// they may be altered for testing.

class HostCPUFeatures : public AllStatic {
 public:
  static void Init();
  static void Cleanup();
  static const char* hardware() {
    DEBUG_ASSERT(initialized_);
    return hardware_;
  }

 private:
  static const char* hardware_;
#if defined(DEBUG)
  static bool initialized_;
#endif
};

class TargetCPUFeatures : public AllStatic {
 public:
  static void Init() { HostCPUFeatures::Init(); }
  static void Cleanup() { HostCPUFeatures::Cleanup(); }
  static const char* hardware() { return HostCPUFeatures::hardware(); }
  static bool double_truncate_round_supported() { return false; }
};

}  // namespace dart

#endif  // RUNTIME_VM_CPU_RISCV_H_
