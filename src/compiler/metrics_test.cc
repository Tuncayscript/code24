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

#include "platform/assert.h"

#include "include/code_api.h"
#include "include/code_tools_api.h"

#include "src/code_api_impl.h"
#include "src/code_api_state.h"
#include "src/globals.h"
#include "src/json_stream.h"
#include "src/metrics.h"
#include "src/unit_test.h"
#include "src/heap.h"

namespace Code {

#if !defined(PRODUCT)
VM_UNIT_TEST_CASE(Metric_Simple) {
  TestCase::CreateTestIsolate();
  {
    Metric metric;

    // Initialize metric.
    metric.InitInstance(Isolate::Current(), "a.b.c", "foobar",
                        Metric::kCounter);
    EXPECT_EQ(0, metric.value());
    metric.increment();
    EXPECT_EQ(1, metric.value());
    metric.set_value(44);
    EXPECT_EQ(44, metric.value());
  }
  CODE_ShutdownIsolate();
}

class MyMetric : public Metric {
 protected:
  int64_t Value() const {
    // 99 bytes.
    return 99;
  }

 public:
  // Just used for testing.
  int64_t LeakyValue() const { return Value(); }
};

VM_UNIT_TEST_CASE(Metric_OnDemand) {
  TestCase::CreateTestIsolate();
  {
    Thread* thread = Thread::Current();
    TransitionNativeToVM transition(thread);
    StackZone zone(thread);
    MyMetric metric;

    metric.InitInstance(Isolate::Current(), "a.b.c", "foobar", Metric::kByte);
    // value is still the default value.
    EXPECT_EQ(0, metric.value());
    // Call LeakyValue to confirm that Value returns constant 99.
    EXPECT_EQ(99, metric.LeakyValue());

    // Serialize to JSON.
    JSONStream js;
    metric.PrintJSON(&js);
    const char* json = js.ToCString();
    EXPECT_STREQ(
        "{\"type\":\"Counter\",\"name\":\"a.b.c\",\"description\":"
        "\"foobar\",\"unit\":\"byte\","
        "\"fixedId\":true,\"id\":\"metrics\\/native\\/a.b.c\""
        ",\"value\":99.0}",
        json);
  }
  CODE_ShutdownIsolate();
}
#endif  // !defined(PRODUCT)

ISOLATE_UNIT_TEST_CASE(Metric_EmbedderAPI) {
  {
    TransitionVMToNative transition(thread);

    const char* kScript = "void main() {}";
    CODE_Handle api_lib = TestCase::LoadTestScript(
        kScript, /*resolver=*/nullptr, RESOLVED_USER_TEST_URI);
    EXPECT_VALID(api_lib);
  }

  // Ensure we've done new/old GCs to ensure max metrics are initialized.
  String::New("<land-in-new-space>", Heap::kNew);
  thread->heap()->CollectGarbage(thread, GCType::kScavenge,
                                 GCReason::kDebugging);
  thread->heap()->CollectGarbage(thread, GCType::kMarkCompact,
                                 GCReason::kDebugging);

  // Ensure we've something live in new space.
  String::New("<land-in-new-space2>", Heap::kNew);

  EXPECT(thread->isolate_group()->GetHeapOldUsedMaxMetric()->Value() > 0);
  EXPECT(thread->isolate_group()->GetHeapOldCapacityMaxMetric()->Value() > 0);
  EXPECT(thread->isolate_group()->GetHeapNewUsedMaxMetric()->Value() > 0);
  EXPECT(thread->isolate_group()->GetHeapNewCapacityMaxMetric()->Value() > 0);
  EXPECT(thread->isolate_group()->GetHeapGlobalUsedMetric()->Value() > 0);
  EXPECT(thread->isolate_group()->GetHeapGlobalUsedMaxMetric()->Value() > 0);

  {
    TransitionVMToNative transition(thread);

    CODE_IsolateGroup isolate_group = CODE_CurrentIsolateGroup();
    EXPECT(CODE_IsolateGroupHeapOldUsedMetric(isolate_group) > 0);
    EXPECT(CODE_IsolateGroupHeapOldCapacityMetric(isolate_group) > 0);
    EXPECT(CODE_IsolateGroupHeapNewUsedMetric(isolate_group) > 0);
    EXPECT(CODE_IsolateGroupHeapNewCapacityMetric(isolate_group) > 0);
  }
}

}  // namespace dart
