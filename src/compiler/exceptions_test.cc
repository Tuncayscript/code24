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

#include "include/CODE_api.h"
#include "platform/assert.h"
#include "src/CODE_api_impl.h"
#include "src/unit_test.h"

namespace Code {

#define FUNCTION_NAME(name) UnhandledExcp_##name
#define REGISTER_FUNCTION(name, count) {"" #name, FUNCTION_NAME(name), count},

void FUNCTION_NAME(Unhandled_equals)(CODE_NativeArguments args) {
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  TransitionNativeToVM transition(arguments->thread());
  Zone* zone = arguments->thread()->zone();
  const Instance& expected =
      Instance::CheckedHandle(zone, arguments->NativeArgAt(0));
  const Instance& actual =
      Instance::CheckedHandle(zone, arguments->NativeArgAt(1));
  if (!expected.CanonicalizeEquals(actual)) {
    OS::PrintErr("expected: '%s' actual: '%s'\n", expected.ToCString(),
                 actual.ToCString());
    FATAL("Unhandled_equals fails.\n");
  }
}

void FUNCTION_NAME(Unhandled_invoke)(CODE_NativeArguments args) {
  // Invoke the specified entry point.
  CODE_Handle cls = CODE_GetClass(TestCase::lib(), NewString("Second"));
  CODE_Handle result = CODE_Invoke(cls, NewString("method2"), 0, nullptr);
  ASSERT(CODE_IsError(result));
  ASSERT(CODE_ErrorHasException(result));
  return;
}

void FUNCTION_NAME(Unhandled_invoke2)(CODE_NativeArguments args) {
  // Invoke the specified entry point.
  CODE_Handle cls = CODE_GetClass(TestCase::lib(), NewString("Second"));
  CODE_Handle result = CODE_Invoke(cls, NewString("method2"), 0, nullptr);
  ASSERT(CODE_IsError(result));
  ASSERT(CODE_ErrorHasException(result));
  CODE_Handle exception = CODE_ErrorGetException(result);
  ASSERT(!CODE_IsError(exception));
  CODE_ThrowException(exception);
  UNREACHABLE();
  return;
}

// List all native functions implemented in the vm or core boot strap dart
// libraries so that we can resolve the native function to it's entry
// point.
#define UNHANDLED_NATIVE_LIST(V)                                               \
  V(Unhandled_equals, 2)                                                       \
  V(Unhandled_invoke, 0)                                                       \
  V(Unhandled_invoke2, 0)

static struct NativeEntries {
  const char* name_;
  CODE_NativeFunction function_;
  int argument_count_;
} BuiltinEntries[] = {UNHANDLED_NATIVE_LIST(REGISTER_FUNCTION)};

static CODE_NativeFunction native_lookup(CODE_Handle name,
                                         int argument_count,
                                         bool* auto_setup_scope) {
  ASSERT(auto_setup_scope != nullptr);
  *auto_setup_scope = true;
  TransitionNativeToVM transition(Thread::Current());
  const Object& obj = Object::Handle(Api::UnwrapHandle(name));
  ASSERT(obj.IsString());
  const char* function_name = obj.ToCString();
  ASSERT(function_name != nullptr);
  int num_entries = sizeof(BuiltinEntries) / sizeof(struct NativeEntries);
  for (int i = 0; i < num_entries; i++) {
    struct NativeEntries* entry = &(BuiltinEntries[i]);
    if ((strcmp(function_name, entry->name_) == 0) &&
        (argument_count == entry->argument_count_)) {
      return reinterpret_cast<CODE_NativeFunction>(entry->function_);
    }
  }
  return nullptr;
}

// Unit test case to verify unhandled exceptions.
TEST_CASE(UnhandledExceptions) {
  const char* kScriptChars =
      R"(
      class UnhandledExceptions {
        @pragma('vm:external-name', 'Unhandled_equals')
        external static equals(var obj1, var obj2);

        @pragma('vm:external-name', 'Unhandled_invoke')
        external static invoke();

        @pragma('vm:external-name', 'Unhandled_invoke2')
        external static invoke2();
      }
      class Second {
        Second() { }
        static int method1(int param) {
          UnhandledExceptions.invoke();
          return 2;
        }
        static int method2() {
          throw new Second();
        }
        static int method3(int param) {
          try {
            UnhandledExceptions.invoke2();
          } on Second catch (e) {
            return 3;
          }
          return 2;
        }
      }
      testMain() {
        UnhandledExceptions.equals(2, Second.method1(1));
        UnhandledExceptions.equals(3, Second.method3(1));
      }
      )";
  CODE_Handle lib = TestCase::LoadTestScript(kScriptChars, native_lookup);
  EXPECT_VALID(CODE_Invoke(lib, NewString("testMain"), 0, nullptr));
}

}  // namespace dart
