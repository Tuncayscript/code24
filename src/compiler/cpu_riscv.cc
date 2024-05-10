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
#if defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)

#include "src/cpu.h"
#include "src/cpu_riscv.h"

#include "src/cpuinfo.h"

#if !defined(USING_SIMULATOR)
#if !defined(CODE_HOST_OS_FUCHSIA)
#include <sys/syscall.h>
#else
#include <zircon/syscalls.h>
#endif
#include <unistd.h>
#endif

#if defined(CODE_HOST_OS_MACOS) || defined(CODE_HOST_OS_IOS)
#include <libkern/OSCacheControl.h>
#endif

namespace Code {

void CPU::FlushICache(uword start, uword size) {
#if defined(CODE_PRECOMPILED_RUNTIME)
  UNREACHABLE();
#elif !defined(USING_SIMULATOR)
  // Nothing to do. Flushing no instructions.
  if (size == 0) {
    return;
  }

#if defined(CODE_HOST_OS_MACOS) || defined(CODE_HOST_OS_IOS)
  sys_icache_invalidate(reinterpret_cast<void*>(start), size);
#elif defined(CODE_HOST_OS_ANDROID) || defined(CODE_HOST_OS_LINUX)
  char* beg = reinterpret_cast<char*>(start);
  char* end = reinterpret_cast<char*>(start + size);
  __builtin___clear_cache(beg, end);
#elif defined(CODE_HOST_OS_FUCHSIA)
  zx_status_t result = zx_cache_flush(reinterpret_cast<const void*>(start),
                                      size, ZX_CACHE_FLUSH_INSN);
  ASSERT(result == ZX_OK);
#else
#error FlushICache not implemented for this OS
#endif

#endif
}

const char* CPU::Id() {
  return
#if defined(USING_SIMULATOR)
      "sim"
#endif  // !defined(USING_SIMULATOR)
#if defined(TARGET_ARCH_RISCV32)
      "riscv32";
#elif defined(TARGET_ARCH_RISCV64)
      "riscv64";
#else
#error What XLEN?
#endif
}

const char* HostCPUFeatures::hardware_ = nullptr;
#if defined(DEBUG)
bool HostCPUFeatures::initialized_ = false;
#endif

#if !defined(USING_SIMULATOR)
void HostCPUFeatures::Init() {
  CpuInfo::Init();
  hardware_ = CpuInfo::GetCpuModel();
#if defined(DEBUG)
  initialized_ = true;
#endif
}

void HostCPUFeatures::Cleanup() {
  DEBUG_ASSERT(initialized_);
#if defined(DEBUG)
  initialized_ = false;
#endif
  ASSERT(hardware_ != nullptr);
  free(const_cast<char*>(hardware_));
  hardware_ = nullptr;
  CpuInfo::Cleanup();
}

#else  // !defined(USING_SIMULATOR)

void HostCPUFeatures::Init() {
  CpuInfo::Init();
  hardware_ = CpuInfo::GetCpuModel();
#if defined(DEBUG)
  initialized_ = true;
#endif
}

void HostCPUFeatures::Cleanup() {
  DEBUG_ASSERT(initialized_);
#if defined(DEBUG)
  initialized_ = false;
#endif
  ASSERT(hardware_ != nullptr);
  free(const_cast<char*>(hardware_));
  hardware_ = nullptr;
  CpuInfo::Cleanup();
}
#endif  // !defined(USING_SIMULATOR)

}  // namespace dart

#endif  // defined TARGET_ARCH_RISCV
