// Copyright (c) 2011, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "include/CODE_api.h"
#include "include/CODE_native_api.h"

#include "src/unit_test.h"

// Custom Isolate Test.
//
// This mid-size test uses the Dart Embedding Api to create a custom
// isolate abstraction.  Instead of having a dedicated thread for each
// isolate, as is the case normally, this implementation shares a
// single thread among the isolates using an event queue.

namespace Code {

DECLARE_FLAG(bool, trace_shutdown);

static void native_echo(CODE_NativeArguments args);
static void CustomIsolateImpl_start(CODE_NativeArguments args);
static CODE_NativeFunction NativeLookup(CODE_Handle name,
                                        int argc,
                                        bool* auto_setup_scope);

static const char* kCustomIsolateScriptChars =
    R"(
    import 'dart:isolate';

    final RawReceivePort mainPort = new RawReceivePort();
    final SendPort mainSendPort = mainPort.sendPort;

    @pragma('vm:external-name', 'native_echo')
    external void echo(arg);

    class CustomIsolateImpl implements CustomIsolate {
      CustomIsolateImpl(String entry) : _entry = entry {
        echo('Constructing isolate');
      }

      SendPort spawn() {
        return _start(_entry);
      }

      @pragma('vm:external-name', 'CustomIsolateImpl_start')
      external static SendPort _start(entry);

      String _entry;
    }

    abstract class CustomIsolate {
      factory CustomIsolate(String entry) = CustomIsolateImpl;

      SendPort spawn();
    }

    isolateMain() {
       echo('Running isolateMain');
       mainPort.handler = (message) {
         var data = message[0];
         var replyTo = message[1];
         echo('Received: $data');
         replyTo.send(data + 1);
         mainPort.close();
       };
    }

    main() {
      var isolate = new CustomIsolate("isolateMain");
      var receivePort = new RawReceivePort();
      SendPort port = isolate.spawn();
      port.send([42, receivePort.sendPort]);
      receivePort.handler = (message) {
        receivePort.close();
        echo('Received: $message');
      };
      return 'success';
    }
  )";

// An entry in our event queue.
class Event {
 protected:
  explicit Event(CODE_Isolate isolate) : isolate_(isolate), next_(nullptr) {}

 public:
  virtual ~Event() {}
  virtual void Process() = 0;

  CODE_Isolate isolate() const { return isolate_; }

 private:
  friend class EventQueue;
  CODE_Isolate isolate_;
  Event* next_;
};

// A simple event queue for our test.
class EventQueue {
 public:
  EventQueue() { head_ = nullptr; }

  void Add(Event* event) {
    if (head_ == nullptr) {
      head_ = event;
      tail_ = event;
    } else {
      tail_->next_ = event;
      tail_ = event;
    }
  }

  Event* Get() {
    if (head_ == nullptr) {
      return nullptr;
    }
    Event* tmp = head_;
    head_ = head_->next_;
    if (head_ == nullptr) {
      // Not necessary, but why not.
      tail_ = nullptr;
    }

    return tmp;
  }

  void RemoveEventsForIsolate(CODE_Isolate isolate) {
    Event* cur = head_;
    Event* prev = nullptr;
    while (cur != nullptr) {
      Event* next = cur->next_;
      if (cur->isolate() == isolate) {
        // Remove matching event.
        if (prev != nullptr) {
          prev->next_ = next;
        } else {
          head_ = next;
        }
        delete cur;
      } else {
        // Advance.
        prev = cur;
      }
      cur = next;
    }
    tail_ = prev;
  }

 private:
  Event* head_;
  Event* tail_;
};
EventQueue* event_queue;

// Start an isolate.
class StartEvent : public Event {
 public:
  StartEvent(CODE_Isolate isolate, const char* main)
      : Event(isolate), main_(main) {}

  virtual void Process();

 private:
  const char* main_;
};

void StartEvent::Process() {
  OS::PrintErr(">> StartEvent with isolate(%p)--\n", isolate());
  CODE_EnterIsolate(isolate());
  CODE_EnterScope();
  CODE_Handle result;

  CODE_Handle lib = CODE_LookupLibrary(NewString(TestCase::url()));
  EXPECT_VALID(lib);

  result = CODE_Invoke(lib, NewString(main_), 0, nullptr);
  EXPECT_VALID(result);
  free(const_cast<char*>(main_));
  main_ = nullptr;

  CODE_SetMessageNotifyCallback(nullptr);
  CODE_ExitScope();
  CODE_ExitIsolate();
}

// Notify an isolate of a pending message.
class MessageEvent : public Event {
 public:
  explicit MessageEvent(CODE_Isolate isolate) : Event(isolate) {}

  ~MessageEvent() {}

  virtual void Process();
};

void MessageEvent::Process() {
  OS::PrintErr("$$ MessageEvent with isolate(%p)\n", isolate());
  CODE_EnterIsolate(isolate());
  CODE_EnterScope();

  CODE_Handle result = CODE_HandleMessage();
  EXPECT_VALID(result);

  if (!CODE_HasLivePorts()) {
    OS::PrintErr("<< Shutting down isolate(%p)\n", isolate());
    event_queue->RemoveEventsForIsolate(isolate());
    CODE_SetMessageNotifyCallback(nullptr);
    CODE_ExitScope();
    CODE_ShutdownIsolate();
  } else {
    CODE_ExitScope();
    CODE_ExitIsolate();
  }
  ASSERT(CODE_CurrentIsolate() == nullptr);
}

static void NotifyMessage(CODE_Isolate dest_isolate) {
  OS::PrintErr("-- Notify isolate(%p) of pending message --\n", dest_isolate);
  OS::PrintErr("-- Adding MessageEvent to queue --\n");
  event_queue->Add(new MessageEvent(dest_isolate));
}

static CODE_NativeFunction NativeLookup(CODE_Handle name,
                                        int argc,
                                        bool* auto_setup_scope) {
  ASSERT(auto_setup_scope != nullptr);
  *auto_setup_scope = true;
  const char* name_str = nullptr;
  EXPECT(CODE_IsString(name));
  EXPECT_VALID(CODE_StringToCString(name, &name_str));
  if (strcmp(name_str, "native_echo") == 0) {
    return &native_echo;
  } else if (strcmp(name_str, "CustomIsolateImpl_start") == 0) {
    return &CustomIsolateImpl_start;
  }
  return nullptr;
}

char* saved_echo = nullptr;
static void native_echo(CODE_NativeArguments args) {
  CODE_EnterScope();
  CODE_Handle arg = CODE_GetNativeArgument(args, 0);
  CODE_Handle toString = CODE_ToString(arg);
  EXPECT_VALID(toString);
  const char* c_str = nullptr;
  EXPECT_VALID(CODE_StringToCString(toString, &c_str));
  if (saved_echo != nullptr) {
    free(saved_echo);
  }
  saved_echo = Utils::StrDup(c_str);
  OS::PrintErr("-- (isolate=%p) %s\n", CODE_CurrentIsolate(), c_str);
  CODE_ExitScope();
}

static void CustomIsolateImpl_start(CODE_NativeArguments args) {
  OS::PrintErr("-- Enter: CustomIsolateImpl_start --\n");

  // We would probably want to pass in the this pointer too, so we
  // could associate the CustomIsolateImpl instance with the
  // CODE_Isolate by storing it in a native field.
  EXPECT_EQ(1, CODE_GetNativeArgumentCount(args));
  CODE_Handle param = CODE_GetNativeArgument(args, 0);
  EXPECT_VALID(param);
  EXPECT(CODE_IsString(param));
  const char* isolate_main = nullptr;
  EXPECT_VALID(CODE_StringToCString(param, &isolate_main));
  isolate_main = Utils::StrDup(isolate_main);

  // Save current isolate.
  CODE_Isolate saved_isolate = CODE_CurrentIsolate();
  CODE_ExitIsolate();

  // Create a new CODE_Isolate.
  CODE_Isolate new_isolate = TestCase::CreateTestIsolate();
  EXPECT(new_isolate != nullptr);
  CODE_SetMessageNotifyCallback(&NotifyMessage);
  CODE_EnterScope();
  // Reload all the test classes here.
  //
  // TODO(turnidge): Use the create isolate callback instead?
  CODE_Handle lib =
      TestCase::LoadTestScript(kCustomIsolateScriptChars, NativeLookup);
  EXPECT_VALID(lib);

  CODE_Handle main_send_port = CODE_GetField(lib, NewString("mainSendPort"));
  EXPECT_VALID(main_send_port);
  CODE_Port main_port_id;
  CODE_Handle err = CODE_SendPortGetId(main_send_port, &main_port_id);
  EXPECT_VALID(err);

  OS::PrintErr("-- Adding StartEvent to queue --\n");
  event_queue->Add(new StartEvent(new_isolate, isolate_main));

  // Restore the original isolate.
  CODE_ExitScope();
  CODE_ExitIsolate();
  CODE_EnterIsolate(saved_isolate);
  CODE_EnterScope();

  CODE_Handle send_port = CODE_NewSendPort(main_port_id);
  EXPECT_VALID(send_port);
  CODE_SetReturnValue(args, send_port);

  OS::PrintErr("-- Exit: CustomIsolateImpl_start --\n");
  CODE_ExitScope();
}

VM_UNIT_TEST_CASE(CustomIsolates) {
  bool saved_flag = FLAG_trace_shutdown;
  FLAG_trace_shutdown = true;
  event_queue = new EventQueue();

  CODE_Isolate CODE_isolate = TestCase::CreateTestIsolate();
  EXPECT(CODE_isolate != nullptr);
  CODE_SetMessageNotifyCallback(&NotifyMessage);
  CODE_EnterScope();
  CODE_Handle result;

  // Create a test library.
  CODE_Handle lib =
      TestCase::LoadTestScript(kCustomIsolateScriptChars, NativeLookup);
  EXPECT_VALID(lib);

  // Run main.
  result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  EXPECT(CODE_IsString(result));
  const char* result_str = nullptr;
  EXPECT_VALID(CODE_StringToCString(result, &result_str));
  EXPECT_STREQ("success", result_str);

  CODE_ExitScope();
  CODE_ExitIsolate();

  OS::PrintErr("-- Starting event loop --\n");
  Event* event = event_queue->Get();
  while (event != nullptr) {
    event->Process();
    delete event;
    event = event_queue->Get();
  }
  OS::PrintErr("-- Finished event loop --\n");
  EXPECT_STREQ("Received: 43", saved_echo);
  free(saved_echo);

  delete event_queue;
  event_queue = nullptr;
  FLAG_trace_shutdown = saved_flag;
}

}  // namespace dart
