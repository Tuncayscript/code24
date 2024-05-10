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
#if defined(TARGET_ARCH_ARM64)

#include "src/code_patcher.h"
#include "src/cpu.h"
#include "src/debugger.h"
#include "src/instructions.h"
#include "src/stub_code.h"

namespace Code {

#ifndef PRODUCT

CodePtr CodeBreakpoint::OrigStubAddress() const {
  return saved_value_;
}

void CodeBreakpoint::PatchCode() {
  ASSERT(!IsEnabled());
  const Code& code = Code::Handle(code_);
  switch (breakpoint_kind_) {
    case UntaggedPcDescriptors::kIcCall: {
      Object& data = Object::Handle();
      saved_value_ = CodePatcher::GetInstanceCallAt(pc_, code, &data);
      CodePatcher::PatchInstanceCallAt(pc_, code, data,
                                       StubCode::ICCallBreakpoint());
      break;
    }
    case UntaggedPcDescriptors::kUnoptStaticCall: {
      saved_value_ = CodePatcher::GetStaticCallTargetAt(pc_, code);
      CodePatcher::PatchPoolPointerCallAt(
          pc_, code, StubCode::UnoptStaticCallBreakpoint());
      break;
    }
    case UntaggedPcDescriptors::kRuntimeCall: {
      saved_value_ = CodePatcher::GetStaticCallTargetAt(pc_, code);
      CodePatcher::PatchPoolPointerCallAt(pc_, code,
                                          StubCode::RuntimeCallBreakpoint());
      break;
    }
    default:
      UNREACHABLE();
  }
}

void CodeBreakpoint::RestoreCode() {
  ASSERT(IsEnabled());
  const Code& code = Code::Handle(code_);
  switch (breakpoint_kind_) {
    case UntaggedPcDescriptors::kIcCall: {
      Object& data = Object::Handle();
      CodePatcher::GetInstanceCallAt(pc_, code, &data);
      CodePatcher::PatchInstanceCallAt(pc_, code, data,
                                       Code::Handle(saved_value_));
      break;
    }
    case UntaggedPcDescriptors::kUnoptStaticCall:
    case UntaggedPcDescriptors::kRuntimeCall: {
      CodePatcher::PatchPoolPointerCallAt(pc_, code,
                                          Code::Handle(saved_value_));
      break;
    }
    default:
      UNREACHABLE();
  }
}

#endif  // !PRODUCT

}  // namespace dart

#endif  // defined TARGET_ARCH_ARM64
