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

#include "src/handles.h"
#include "platform/assert.h"
#include "src/CODE_api_state.h"
#include "src/flags.h"
#include "src/object.h"
#include "src/unit_test.h"
#include "src/zone.h"

namespace Code {

// Unit test for Zone handle allocation.
ISOLATE_UNIT_TEST_CASE(AllocateZoneHandle) {
#if defined(DEBUG)
  FLAG_trace_handles = true;
#endif
  // The previously run stub code generation may have created zone handles.
  int initial_count = VMHandles::ZoneHandleCount();
  const int kNumHandles = 65;
  // Create some zone handles.
  for (int i = 0; i < kNumHandles; i++) {
    const Smi& handle = Smi::ZoneHandle(Smi::New(i));
    EXPECT(handle.IsSmi());
    EXPECT_EQ(i, handle.Value());
  }
  EXPECT_EQ(kNumHandles + initial_count, VMHandles::ZoneHandleCount());
  // Create some more zone handles.
  for (int i = kNumHandles; i < (2 * kNumHandles); i++) {
    const Smi& handle = Smi::ZoneHandle(Smi::New(i));
    EXPECT(handle.IsSmi());
    EXPECT_EQ(i, handle.Value());
  }
  EXPECT_EQ((2 * kNumHandles) + initial_count, VMHandles::ZoneHandleCount());
}

// Unit test for Scope handle allocation.
ISOLATE_UNIT_TEST_CASE(AllocateScopeHandle) {
#if defined(DEBUG)
  FLAG_trace_handles = true;
#endif
  int32_t handle_count = VMHandles::ScopedHandleCount();
  const int kNumHandles = 65;
  // Create some scoped handles.
  {
    Thread* thread = Thread::Current();
    HANDLESCOPE(thread);
    for (int i = 0; i < kNumHandles; i++) {
      const Smi& handle = Smi::Handle(Smi::New(i));
      EXPECT(handle.IsSmi());
      EXPECT_EQ(i, handle.Value());
    }
    EXPECT_EQ((handle_count + kNumHandles), VMHandles::ScopedHandleCount());
    // Create lots of scoped handles in a loop with a nested scope.
    for (int loop = 0; loop < 1000; loop++) {
      HANDLESCOPE(thread);
      for (int i = 0; i < 2; i++) {
        const Smi& handle = Smi::Handle(Smi::New(i + loop));
        EXPECT(handle.IsSmi());
        EXPECT_EQ(i + loop, handle.Value());
      }
      EXPECT_EQ((handle_count + kNumHandles + 2),
                VMHandles::ScopedHandleCount());
    }
    EXPECT_EQ((handle_count + kNumHandles), VMHandles::ScopedHandleCount());
    for (int i = 0; i < kNumHandles; i++) {
      const Smi& handle = Smi::Handle(Smi::New(i));
      EXPECT(handle.IsSmi());
      EXPECT_EQ(i, handle.Value());
    }
    EXPECT_EQ((handle_count + (2 * kNumHandles)),
              VMHandles::ScopedHandleCount());
  }
  EXPECT_EQ(handle_count, VMHandles::ScopedHandleCount());
}

static void NoopCallback(void* isolate_callback_data, void* peer) {}

// Unit test for handle validity checks.
TEST_CASE(CheckHandleValidity) {
#if defined(DEBUG)
  FLAG_trace_handles = true;
#endif
  CODE_Handle handle = nullptr;
  // Check validity using zone handles.
  {
    TransitionNativeToVM transition(thread);
    StackZone sz(thread);
    handle = reinterpret_cast<CODE_Handle>(&Smi::ZoneHandle(Smi::New(1)));
    {
      TransitionVMToNative to_native(thread);
      EXPECT_VALID(handle);
    }
  }
  EXPECT(!Api::IsValid(handle));

  // Check validity using scoped handles.
  {
    CODE_EnterScope();
    {
      TransitionNativeToVM transition(thread);
      HANDLESCOPE(thread);
      handle = reinterpret_cast<CODE_Handle>(&Smi::Handle(Smi::New(1)));
      {
        TransitionVMToNative to_native(thread);
        EXPECT_VALID(handle);
      }
    }
    CODE_ExitScope();
  }
  EXPECT(!Api::IsValid(handle));

  // Check validity using persistent handle.
  CODE_Handle scoped_handle;
  {
    TransitionNativeToVM transition(thread);
    scoped_handle = Api::NewHandle(thread, Smi::New(1));
  }
  CODE_PersistentHandle persistent_handle =
      CODE_NewPersistentHandle(scoped_handle);
  EXPECT_VALID(persistent_handle);

  CODE_DeletePersistentHandle(persistent_handle);
  EXPECT(!Api::IsValid(persistent_handle));

  // Check validity using weak persistent handle.
  handle = reinterpret_cast<CODE_Handle>(CODE_NewWeakPersistentHandle(
      CODE_NewStringFromCString("foo"), nullptr, 0, NoopCallback));

  EXPECT_NOTNULL(handle);
  EXPECT_VALID(handle);

  CODE_DeleteWeakPersistentHandle(
      reinterpret_cast<CODE_WeakPersistentHandle>(handle));
  EXPECT(!Api::IsValid(handle));
}

}  // namespace dart
