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
#if defined(CODE_HOST_OS_WINDOWS)

#include "src/lockers.h"
#include "src/native_symbol.h"
#include "src/os.h"
#include "src/os_thread.h"

#include <dbghelp.h>  // NOLINT

namespace Code {

static bool running_ = false;
static Mutex* lock_ = nullptr;

void NativeSymbolResolver::Init() {
  ASSERT(running_ == false);
  if (lock_ == nullptr) {
    lock_ = new Mutex();
  }
  running_ = true;

// Symbol resolution API's used in this file are not supported
// when compiled in UWP.
#ifndef CODE_TARGET_OS_WINDOWS_UWP
  SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
  HANDLE hProcess = GetCurrentProcess();
  if (!SymInitialize(hProcess, nullptr, TRUE)) {
    DWORD error = GetLastError();
    OS::PrintErr("Failed to init NativeSymbolResolver (SymInitialize %" Pu32
                 ")\n",
                 error);
    return;
  }
#endif
}

void NativeSymbolResolver::Cleanup() {
  MutexLocker lock(lock_);
  if (!running_) {
    return;
  }
  running_ = false;
#ifndef CODE_TARGET_OS_WINDOWS_UWP
  HANDLE hProcess = GetCurrentProcess();
  if (!SymCleanup(hProcess)) {
    DWORD error = GetLastError();
    OS::PrintErr("Failed to shutdown NativeSymbolResolver (SymCleanup  %" Pu32
                 ")\n",
                 error);
  }
#endif
}

char* NativeSymbolResolver::LookupSymbolName(uword pc, uword* start) {
#ifdef CODE_TARGET_OS_WINDOWS_UWP
  return nullptr;
#else
  const intptr_t kMaxNameLength = 2048;
  const intptr_t kSymbolInfoSize = sizeof(SYMBOL_INFO);  // NOLINT.
  static char buffer[kSymbolInfoSize + kMaxNameLength];
  static char name_buffer[kMaxNameLength];
  MutexLocker lock(lock_);
  if (!running_) {
    return nullptr;
  }
  if (start != nullptr) {
    *start = 0;
  }
  memset(&buffer[0], 0, sizeof(buffer));
  HANDLE hProcess = GetCurrentProcess();
  DWORD64 address = static_cast<DWORD64>(pc);
  PSYMBOL_INFO pSymbol = reinterpret_cast<PSYMBOL_INFO>(&buffer[0]);
  pSymbol->SizeOfStruct = kSymbolInfoSize;
  pSymbol->MaxNameLen = kMaxNameLength;
  DWORD64 displacement;
  BOOL r = SymFromAddr(hProcess, address, &displacement, pSymbol);
  if (r == FALSE) {
    return nullptr;
  }
  if (start != nullptr) {
    *start = pc - displacement;
  }
  return Utils::StrDup(pSymbol->Name);
#endif  // ifdef CODE_TARGET_OS_WINDOWS_UWP
}

void NativeSymbolResolver::FreeSymbolName(char* name) {
  free(name);
}

bool NativeSymbolResolver::LookupSharedObject(uword pc,
                                              uword* dso_base,
                                              char** dso_name) {
  return false;
}

void NativeSymbolResolver::AddSymbols(const char* dso_name,
                                      void* buffer,
                                      size_t size) {
  OS::PrintErr("warning: CODE_AddSymbols has no effect on Windows\n");
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_WINDOWS)
