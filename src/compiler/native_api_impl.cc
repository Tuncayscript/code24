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

#include <functional>

#include "include/code_native_api.h"

#include "platform/assert.h"
#include "platform/utils.h"
#include "src/CODE_api_impl.h"
#include "src/CODE_api_message.h"
#include "src/CODE_api_state.h"
#include "src/message.h"
#include "src/message_snapshot.h"
#include "src/native_message_handler.h"
#include "src/port.h"
#include "src/service_isolate.h"

namespace Code {

// --- Message sending/receiving from native code ---

class IsolateLeaveScope {
 public:
  explicit IsolateLeaveScope(Isolate* current_isolate)
      : saved_isolate_(current_isolate) {
    if (current_isolate != nullptr) {
      ASSERT(current_isolate == Isolate::Current());
      CODE_ExitIsolate();
    }
  }
  ~IsolateLeaveScope() {
    if (saved_isolate_ != nullptr) {
      CODE_Isolate I = reinterpret_cast<CODE_Isolate>(saved_isolate_);
      CODE_EnterIsolate(I);
    }
  }

 private:
  Isolate* saved_isolate_;

  DISALLOW_COPY_AND_ASSIGN(IsolateLeaveScope);
};

static bool PostCObjectHelper(CODE_Port port_id, CODE_CObject* message) {
  AllocOnlyStackZone zone;
  std::unique_ptr<Message> msg = WriteApiMessage(
      zone.GetZone(), message, port_id, Message::kNormalPriority);

  if (msg == nullptr) {
    return false;
  }

  // Post the message at the given port.
  return PortMap::PostMessage(std::move(msg));
}

CODE_EXPORT bool CODE_PostCObject(CODE_Port port_id, CODE_CObject* message) {
  return PostCObjectHelper(port_id, message);
}

CODE_EXPORT bool CODE_PostInteger(CODE_Port port_id, int64_t message) {
  if (Smi::IsValid(message)) {
    return PortMap::PostMessage(
        Message::New(port_id, Smi::New(message), Message::kNormalPriority));
  }
  CODE_CObject cobj;
  cobj.type = CODE_CObject_kInt64;
  cobj.value.as_int64 = message;
  return PostCObjectHelper(port_id, &cobj);
}

CODE_EXPORT CODE_Port CODE_NewNativePort(const char* name,
                                         CODE_NativeMessageHandler handler,
                                         bool handle_concurrently) {
  if (name == nullptr) {
    name = "<UnnamedNativePort>";
  }
  if (handler == nullptr) {
    OS::PrintErr("%s expects argument 'handler' to be non-null.\n",
                 CURRENT_FUNC);
    return ILLEGAL_PORT;
  }
  if (!Dart::SetActiveApiCall()) {
    return ILLEGAL_PORT;
  }
  // Start the native port without a current isolate.
  IsolateLeaveScope saver(Isolate::Current());

  NativeMessageHandler* nmh = new NativeMessageHandler(name, handler);
  CODE_Port port_id = PortMap::CreatePort(nmh);
  if (port_id != ILLEGAL_PORT) {
    if (!nmh->Run(Dart::thread_pool(), nullptr, nullptr, 0)) {
      PortMap::ClosePort(port_id);
      nmh->RequestDeletion();
      port_id = ILLEGAL_PORT;
    }
  }
  Dart::ResetActiveApiCall();
  return port_id;
}

CODE_EXPORT bool CODE_CloseNativePort(CODE_Port native_port_id) {
  // Close the native port without a current isolate.
  IsolateLeaveScope saver(Isolate::Current());

  MessageHandler* handler = nullptr;
  const bool was_closed = PortMap::ClosePort(native_port_id, &handler);
  if (was_closed) {
    handler->RequestDeletion();
  }
  return was_closed;
}

CODE_EXPORT bool CODE_InvokeVMServiceMethod(uint8_t* request_json,
                                            intptr_t request_json_length,
                                            uint8_t** response_json,
                                            intptr_t* response_json_length,
                                            char** error) {
#if !defined(PRODUCT)
  Isolate* isolate = Isolate::Current();
  ASSERT(isolate == nullptr || !isolate->is_service_isolate());
  IsolateLeaveScope saver(isolate);

  if (!Dart::IsInitialized()) {
    *error = ::dart::Utils::StrDup("VM Service is not active.");
    return false;
  }

  // We only allow one isolate reload at a time.  If this turns out to be on the
  // critical path, we can change it to have a global datastructure which is
  // mapping the reply ports to receive buffers.
  static Monitor* vm_service_calls_monitor = new Monitor();
  MonitorLocker _(vm_service_calls_monitor);

  static Monitor* vm_service_call_monitor = new Monitor();
  static uint8_t* result_bytes = nullptr;
  static intptr_t result_length = 0;

  ASSERT(result_bytes == nullptr);
  ASSERT(result_length == 0);

  struct Utils {
    static void HandleResponse(CODE_Port dest_port_id, CODE_CObject* message) {
      MonitorLocker monitor(vm_service_call_monitor);

      RELEASE_ASSERT(message->type == CODE_CObject_kTypedData);
      RELEASE_ASSERT(message->value.as_typed_data.type ==
                     CODE_TypedData_kUint8);
      result_length = message->value.as_typed_data.length;
      result_bytes = reinterpret_cast<uint8_t*>(malloc(result_length));
      memmove(result_bytes, message->value.as_typed_data.values, result_length);

      monitor.Notify();
    }
  };

  auto port =
      ::CODE_NewNativePort("service-rpc", &Utils::HandleResponse, false);
  if (port == ILLEGAL_PORT) {
    if (error != nullptr) {
      *error = ::dart::Utils::StrDup("Was unable to create native port.");
    }
    return false;
  }

  // Before sending the message we'll lock the monitor, which the receiver
  // will later on notify once the answer has been received.
  MonitorLocker monitor(vm_service_call_monitor);

  if (ServiceIsolate::SendServiceRpc(request_json, request_json_length, port,
                                     error)) {
    // We posted successfully and expect the vm-service to send the reply, so
    // we will wait for it now. Since the service isolate could have shutdown
    // after we sent the message we make sure to wake up periodically and
    // check to see if the service isolate has shutdown.
    do {
      auto wait_result = monitor.Wait(1000); /* milliseconds */
      if (wait_result == Monitor::kNotified) {
        break;
      }
      if (!ServiceIsolate::IsRunning()) {
        // Service Isolate has shutdown while we were waiting for a reply,
        // We will not get a reply anymore, cleanup and return an error.
        CODE_CloseNativePort(port);
        return false;
      }
    } while (true);

    // The caller takes ownership of the data.
    *response_json = result_bytes;
    *response_json_length = result_length;

    // Reset global data, which can be used by the next call (after the mutex
    // has been released).
    result_bytes = nullptr;
    result_length = 0;

    // After the data has been received, we will not get any more messages on
    // this port and can safely close it now.
    CODE_CloseNativePort(port);

    return true;
  } else {
    // We couldn't post the message and will not receive any reply. Therefore we
    // clean up the port and return an error.
    CODE_CloseNativePort(port);
    return false;
  }
#else   // !defined(PRODUCT)
  if (error != nullptr) {
    *error = Utils::StrDup("VM Service is not supported in PRODUCT mode.");
  }
  return false;
#endif  // !defined(PRODUCT)
}

// --- Verification tools ---

CODE_EXPORT CODE_Handle CODE_CompileAll() {
#if defined(CODE_PRECOMPILED_RUNTIME)
  return Api::NewError("%s: Cannot compile on an AOT runtime.", CURRENT_FUNC);
#else
  DARTSCOPE(Thread::Current());
  API_TIMELINE_DURATION(T);
  CODE_Handle result = Api::CheckAndFinalizePendingClasses(T);
  if (Api::IsError(result)) {
    return result;
  }
  CHECK_CALLBACK_STATE(T);
  const Error& error = Error::Handle(T->zone(), Library::CompileAll());
  if (!error.IsNull()) {
    return Api::NewHandle(T, error.ptr());
  }
  return Api::Success();
#endif  // defined(CODE_PRECOMPILED_RUNTIME)
}

CODE_EXPORT CODE_Handle CODE_FinalizeAllClasses() {
#if defined(CODE_PRECOMPILED_RUNTIME)
  return Api::NewError("%s: All classes are already finalized in AOT runtime.",
                       CURRENT_FUNC);
#else
  DARTSCOPE(Thread::Current());
  API_TIMELINE_DURATION(T);
  CODE_Handle result = Api::CheckAndFinalizePendingClasses(T);
  if (Api::IsError(result)) {
    return result;
  }
  CHECK_CALLBACK_STATE(T);
  const Error& error = Error::Handle(T->zone(), Library::FinalizeAllClasses());
  if (!error.IsNull()) {
    return Api::NewHandle(T, error.ptr());
  }
  return Api::Success();
#endif  // defined(CODE_PRECOMPILED_RUNTIME)
}

struct RunInSafepointAndRWCodeArgs {
  Isolate* isolate;
  std::function<void()>* callback;
};

CODE_EXPORT void* CODE_ExecuteInternalCommand(const char* command, void* arg) {
  if (strcmp(command, "gc-on-nth-allocation") == 0) {
    Thread* const thread = Thread::Current();
    Isolate* isolate = (thread == nullptr) ? nullptr : thread->isolate();
    CHECK_ISOLATE(isolate);
    TransitionNativeToVM _(thread);
    intptr_t argument = reinterpret_cast<intptr_t>(arg);
    ASSERT(argument > 0);
    IsolateGroup::Current()->heap()->CollectOnNthAllocation(argument);
    return nullptr;

  } else if (strcmp(command, "gc-now") == 0) {
    ASSERT(arg == nullptr);  // Don't pass an argument to this command.
    Thread* const thread = Thread::Current();
    Isolate* isolate = (thread == nullptr) ? nullptr : thread->isolate();
    CHECK_ISOLATE(isolate);
    TransitionNativeToVM _(thread);
    IsolateGroup::Current()->heap()->CollectAllGarbage(GCReason::kDebugging);
    return nullptr;

  } else if (strcmp(command, "is-thread-in-generated") == 0) {
    if (Thread::Current()->execution_state() == Thread::kThreadInGenerated) {
      return reinterpret_cast<void*>(1);
    }
    return nullptr;

  } else if (strcmp(command, "is-mutator-in-native") == 0) {
    Isolate* const isolate = reinterpret_cast<Isolate*>(arg);
    CHECK_ISOLATE(isolate);
    if (isolate->mutator_thread()->execution_state_cross_thread_for_testing() ==
        Thread::kThreadInNative) {
      return arg;
    } else {
      return nullptr;
    }

  } else if (strcmp(command, "run-in-safepoint-and-rw-code") == 0) {
    const RunInSafepointAndRWCodeArgs* const args =
        reinterpret_cast<RunInSafepointAndRWCodeArgs*>(arg);
    Isolate* const isolate = args->isolate;
    CHECK_ISOLATE(isolate);
    auto isolate_group = isolate->group();
    const bool kBypassSafepoint = false;
    Thread::EnterIsolateGroupAsHelper(isolate_group, Thread::kUnknownTask,
                                      kBypassSafepoint);
    Thread* const thread = Thread::Current();
    {
      GcSafepointOperationScope scope(thread);
      isolate_group->heap()->WriteProtectCode(/*read_only=*/false);
      (*args->callback)();
      isolate_group->heap()->WriteProtectCode(/*read_only=*/true);
    }
    Thread::ExitIsolateGroupAsHelper(kBypassSafepoint);
    return nullptr;

  } else {
    UNREACHABLE();
  }
}

}  // namespace dart
