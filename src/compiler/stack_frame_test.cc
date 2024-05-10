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

#include "src/stack_frame.h"
#include "include/CODE_api.h"
#include "platform/assert.h"
#include "src/class_finalizer.h"
#include "src/compiler/jit/compiler.h"
#include "src/CODE_api_impl.h"
#include "src/CODE_entry.h"
#include "src/heap/verifier.h"
#include "src/resolver.h"
#include "src/unit_test.h"
#include "src/zone.h"

namespace Code {

// Unit test for empty stack frame iteration.
ISOLATE_UNIT_TEST_CASE(EmptyStackFrameIteration) {
  StackFrameIterator iterator(ValidationPolicy::kValidateFrames,
                              Thread::Current(),
                              StackFrameIterator::kNoCrossThreadIteration);
  EXPECT(!iterator.HasNextFrame());
  EXPECT(iterator.NextFrame() == nullptr);
  VerifyPointersVisitor::VerifyPointers("EmptyStackFrameIterationTest");
}

// Unit test for empty dart stack frame iteration.
ISOLATE_UNIT_TEST_CASE(EmptyDartStackFrameIteration) {
  DartFrameIterator iterator(Thread::Current(),
                             StackFrameIterator::kNoCrossThreadIteration);
  EXPECT(iterator.NextFrame() == nullptr);
  VerifyPointersVisitor::VerifyPointers("EmptyDartStackFrameIterationTest");
}

#define FUNCTION_NAME(name) StackFrame_##name
#define REGISTER_FUNCTION(name, count) {"" #name, FUNCTION_NAME(name), count},

void FUNCTION_NAME(StackFrame_equals)(CODE_NativeArguments args) {
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  TransitionNativeToVM transition(arguments->thread());
  Zone* zone = arguments->thread()->zone();
  const Instance& expected =
      Instance::CheckedHandle(zone, arguments->NativeArgAt(0));
  const Instance& actual =
      Instance::CheckedHandle(zone, arguments->NativeArgAt(1));
  if (!expected.OperatorEquals(actual)) {
    OS::PrintErr("expected: '%s' actual: '%s'\n", expected.ToCString(),
                 actual.ToCString());
    EXPECT(false);
  }
}

void FUNCTION_NAME(StackFrame_frameCount)(CODE_NativeArguments args) {
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  TransitionNativeToVM transition(arguments->thread());
  int count = 0;
  StackFrameIterator frames(ValidationPolicy::kValidateFrames,
                            arguments->thread(),
                            StackFrameIterator::kNoCrossThreadIteration);
  while (frames.NextFrame() != nullptr) {
    count += 1;  // Count the frame.
  }
  VerifyPointersVisitor::VerifyPointers("StackFrame_frameCount_Test");
  arguments->SetReturn(Object::Handle(Smi::New(count)));
}

void FUNCTION_NAME(StackFrame_dartFrameCount)(CODE_NativeArguments args) {
  TransitionNativeToVM transition(Thread::Current());
  int count = 0;
  DartFrameIterator frames(Thread::Current(),
                           StackFrameIterator::kNoCrossThreadIteration);
  while (frames.NextFrame() != nullptr) {
    count += 1;  // Count the dart frame.
  }
  VerifyPointersVisitor::VerifyPointers("StackFrame_dartFrameCount_Test");
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  arguments->SetReturn(Object::Handle(Smi::New(count)));
}

void FUNCTION_NAME(StackFrame_validateFrame)(CODE_NativeArguments args) {
  Thread* thread = Thread::Current();
  Zone* zone = thread->zone();

  CODE_Handle index = CODE_GetNativeArgument(args, 0);
  CODE_Handle name = CODE_GetNativeArgument(args, 1);

  TransitionNativeToVM transition(thread);
  const Smi& frame_index_smi =
      Smi::CheckedHandle(zone, Api::UnwrapHandle(index));
  const char* expected_name =
      String::CheckedHandle(zone, Api::UnwrapHandle(name)).ToCString();
  int frame_index = frame_index_smi.Value();
  int count = 0;
  DartFrameIterator frames(thread, StackFrameIterator::kNoCrossThreadIteration);
  StackFrame* frame = frames.NextFrame();
  while (frame != nullptr) {
    if (count == frame_index) {
      // Find the function corresponding to this frame and check if it
      // matches the function name passed in.
      const Function& function =
          Function::Handle(zone, frame->LookupDartFunction());
      if (function.IsNull()) {
        FATAL("StackFrame_validateFrame fails, invalid dart frame.\n");
      }
      const char* name = function.ToFullyQualifiedCString();
      // Currently all unit tests are loaded as being part of dart:core-lib.
      String& url = String::Handle(zone, String::New(TestCase::url()));
      const Library& lib =
          Library::Handle(zone, Library::LookupLibrary(thread, url));
      ASSERT(!lib.IsNull());
      const char* lib_name = String::Handle(zone, lib.url()).ToCString();
      char* full_name = OS::SCreate(zone, "%s_%s", lib_name, expected_name);
      EXPECT_STREQ(full_name, name);
      return;
    }
    count += 1;  // Count the dart frames.
    frame = frames.NextFrame();
  }
  FATAL("StackFrame_validateFrame fails, frame count < index passed in.\n");
}

// List all native functions implemented in the vm or core boot strap dart
// libraries so that we can resolve the native function to it's entry
// point.
#define STACKFRAME_NATIVE_LIST(V)                                              \
  V(StackFrame_equals, 2)                                                      \
  V(StackFrame_frameCount, 0)                                                  \
  V(StackFrame_dartFrameCount, 0)                                              \
  V(StackFrame_validateFrame, 2)

static struct NativeEntries {
  const char* name_;
  CODE_NativeFunction function_;
  int argument_count_;
} BuiltinEntries[] = {STACKFRAME_NATIVE_LIST(REGISTER_FUNCTION)};

static CODE_NativeFunction native_lookup(CODE_Handle name,
                                         int argument_count,
                                         bool* auto_setup_scope) {
  ASSERT(auto_setup_scope != nullptr);
  *auto_setup_scope = false;
  TransitionNativeToVM transition(Thread::Current());
  const Object& obj = Object::Handle(Api::UnwrapHandle(name));
  ASSERT(obj.IsString());
  const char* function_name = obj.ToCString();
  ASSERT(function_name != nullptr);
  int num_entries = sizeof(BuiltinEntries) / sizeof(struct NativeEntries);
  for (int i = 0; i < num_entries; i++) {
    struct NativeEntries* entry = &(BuiltinEntries[i]);
    if ((strcmp(function_name, entry->name_) == 0) &&
        (entry->argument_count_ == argument_count)) {
      return reinterpret_cast<CODE_NativeFunction>(entry->function_);
    }
  }
  return nullptr;
}

// Unit test case to verify stack frame iteration.
TEST_CASE(ValidateStackFrameIteration) {
  const char* nullable_tag = TestCase::NullableTag();
  // clang-format off
  auto kScriptChars = Utils::CStringUniquePtr(
      OS::SCreate(
          nullptr,
          "class StackFrame {"
          "  @pragma('vm:external-name', 'StackFrame_equals')\n"
          "  external static equals(var obj1, var obj2);\n"
          "  @pragma('vm:external-name', 'StackFrame_frameCount')\n"
          "  external static int frameCount();\n"
          "  @pragma('vm:external-name', 'StackFrame_dartFrameCount')\n"
          "  external static int dartFrameCount();\n"
          "  @pragma('vm:external-name', 'StackFrame_validateFrame')\n"
          "  external static validateFrame(int index, String name);"
          "} "
          "class First {"
          "  First() { }"
          "  int%s method1(int%s param) {"
          "    if (param == 1) {"
          "      param = method2(200);"
          "    } else {"
          "      param = method2(100);"
          "    }"
          "  }"
          "  int%s method2(int param) {"
          "    if (param == 200) {"
          "      First.staticmethod(this, param);"
          "    } else {"
          "      First.staticmethod(this, 10);"
          "    }"
          "  }"
          "  static int%s staticmethod(First obj, int param) {"
          "    if (param == 10) {"
          "      obj.method3(10);"
          "    } else {"
          "      obj.method3(200);"
          "    }"
          "  }"
          "  method3(int param) {"
          "    StackFrame.equals(9, StackFrame.frameCount());"
          "    StackFrame.equals(7, StackFrame.dartFrameCount());"
          "    StackFrame.validateFrame(0, \"StackFrame_validateFrame\");"
          "    StackFrame.validateFrame(1, \"First_method3\");"
          "    StackFrame.validateFrame(2, \"First_staticmethod\");"
          "    StackFrame.validateFrame(3, \"First_method2\");"
          "    StackFrame.validateFrame(4, \"First_method1\");"
          "    StackFrame.validateFrame(5, \"Second_method1\");"
          "    StackFrame.validateFrame(6, \"StackFrameTest_testMain\");"
          "  }"
          "}"
          "class Second {"
          "  Second() { }"
          "  int%s method1(int%s param) {"
          "    if (param == 1) {"
          "      param = method2(200);"
          "    } else {"
          "      First obj = new First();"
          "      param = obj.method1(1);"
          "      param = obj.method1(2);"
          "    }"
          "  }"
          "  int%s method2(int param) {"
          "    Second.staticmethod(this, param);"
          "  }"
          "  static int%s staticmethod(Second obj, int param) {"
          "    obj.method3(10);"
          "  }"
          "  method3(int param) {"
          "    StackFrame.equals(8, StackFrame.frameCount());"
          "    StackFrame.equals(6, StackFrame.dartFrameCount());"
          "    StackFrame.validateFrame(0, \"StackFrame_validateFrame\");"
          "    StackFrame.validateFrame(1, \"Second_method3\");"
          "    StackFrame.validateFrame(2, \"Second_staticmethod\");"
          "    StackFrame.validateFrame(3, \"Second_method2\");"
          "    StackFrame.validateFrame(4, \"Second_method1\");"
          "    StackFrame.validateFrame(5, \"StackFrameTest_testMain\");"
          "  }"
          "}"
          "class StackFrameTest {"
          "  static testMain() {"
          "    Second obj = new Second();"
          "    obj.method1(1);"
          "    obj.method1(2);"
          "  }"
          "}",
          nullable_tag, nullable_tag, nullable_tag, nullable_tag, nullable_tag,
          nullable_tag, nullable_tag, nullable_tag),
      std::free);
  // clang-format on
  CODE_Handle lib = TestCase::LoadTestScript(
      kScriptChars.get(),
      reinterpret_cast<CODE_NativeEntryResolver>(native_lookup));
  CODE_Handle cls = CODE_GetClass(lib, NewString("StackFrameTest"));
  EXPECT_VALID(CODE_Invoke(cls, NewString("testMain"), 0, nullptr));
}

// Unit test case to verify stack frame iteration.
TEST_CASE(ValidateNoSuchMethodStackFrameIteration) {
  const char* kScriptChars;
  // The true stack depends on which strategy we are using for noSuchMethod. The
  // stacktrace as seen by Dart is the same either way because dispatcher
  // methods are marked invisible.
  if (FLAG_lazy_dispatchers) {
    kScriptChars =
        "class StackFrame {"
        "  @pragma('vm:external-name', 'StackFrame_equals')\n"
        "  external static equals(var obj1, var obj2);\n"
        "  @pragma('vm:external-name', 'StackFrame_frameCount')\n"
        "  external static int frameCount();\n"
        "  @pragma('vm:external-name', 'StackFrame_dartFrameCount')\n"
        "  external static int dartFrameCount();\n"
        "  @pragma('vm:external-name', 'StackFrame_validateFrame')\n"
        "  external static validateFrame(int index, String name);"
        "} "
        "class StackFrame2Test {"
        "  StackFrame2Test() {}"
        "  noSuchMethod(Invocation im) {"
        "    /* We should have 6 general frames and 4 dart frames as follows:"
        "     * exit frame"
        "     * dart frame corresponding to StackFrame.frameCount"
        "     * dart frame corresponding to StackFrame2Test.noSuchMethod"
        "     * frame for instance function invocation stub calling "
        "noSuchMethod"
        "     * dart frame corresponding to StackFrame2Test.testMain"
        "     * entry frame"
        "     */"
        "    StackFrame.equals(6, StackFrame.frameCount());"
        "    StackFrame.equals(4, StackFrame.dartFrameCount());"
        "    StackFrame.validateFrame(0, \"StackFrame_validateFrame\");"
        "    StackFrame.validateFrame(1, \"StackFrame2Test_noSuchMethod\");"
        "    StackFrame.validateFrame(2, \"StackFrame2Test_foo\");"
        "    StackFrame.validateFrame(3, \"StackFrame2Test_testMain\");"
        "    return 5;"
        "  }"
        "  static testMain() {"
        "    /* Declare |obj| dynamic so that noSuchMethod can be"
        "     * called in strong mode. */"
        "    dynamic obj = new StackFrame2Test();"
        "    StackFrame.equals(5, obj.foo(101, 202));"
        "  }"
        "}";
  } else {
    kScriptChars =
        "class StackFrame {"
        "  @pragma('vm:external-name', 'StackFrame_equals')\n"
        "  external static equals(var obj1, var obj2);\n"
        "  @pragma('vm:external-name', 'StackFrame_frameCount')\n"
        "  external static int frameCount();\n"
        "  @pragma('vm:external-name', 'StackFrame_dartFrameCount')\n"
        "  external static int dartFrameCount();\n"
        "  @pragma('vm:external-name', 'StackFrame_validateFrame')\n"
        "  external static validateFrame(int index, String name);"
        "} "
        "class StackFrame2Test {"
        "  StackFrame2Test() {}"
        "  noSuchMethod(Invocation im) {"
        "    /* We should have 8 general frames and 3 dart frames as follows:"
        "     * exit frame"
        "     * dart frame corresponding to StackFrame.frameCount"
        "     * dart frame corresponding to StackFrame2Test.noSuchMethod"
        "     * entry frame"
        "     * exit frame (call to runtime NoSuchMethodFromCallStub)"
        "     * IC stub"
        "     * dart frame corresponding to StackFrame2Test.testMain"
        "     * entry frame"
        "     */"
        "    StackFrame.equals(8, StackFrame.frameCount());"
        "    StackFrame.equals(3, StackFrame.dartFrameCount());"
        "    StackFrame.validateFrame(0, \"StackFrame_validateFrame\");"
        "    StackFrame.validateFrame(1, \"StackFrame2Test_noSuchMethod\");"
        "    StackFrame.validateFrame(2, \"StackFrame2Test_testMain\");"
        "    return 5;"
        "  }"
        "  static testMain() {"
        "    /* Declare |obj| dynamic so that noSuchMethod can be"
        "     * called in strong mode. */"
        "    dynamic obj = new StackFrame2Test();"
        "    StackFrame.equals(5, obj.foo(101, 202));"
        "  }"
        "}";
  }
  CODE_Handle lib = TestCase::LoadTestScript(
      kScriptChars, reinterpret_cast<CODE_NativeEntryResolver>(native_lookup));
  CODE_Handle cls = CODE_GetClass(lib, NewString("StackFrame2Test"));
  EXPECT_VALID(CODE_Invoke(cls, NewString("testMain"), 0, nullptr));
}

}  // namespace dart
