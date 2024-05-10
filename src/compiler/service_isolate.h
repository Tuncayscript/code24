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

#ifndef RUNTIME_VM_SERVICE_ISOLATE_H_
#define RUNTIME_VM_SERVICE_ISOLATE_H_

#include "include/CODE_api.h"

#include "src/allocation.h"
#include "src/object.h"
#include "src/os_thread.h"

namespace Code {

class Isolate;
class ObjectPointerVisitor;
class SendPort;

class ServiceIsolate : public AllStatic {
#if !defined(PRODUCT)

 public:
  static const char* kName;

  static bool Exists();
  static bool IsRunning();
  static bool IsServiceIsolate(const Isolate* isolate);
  static bool IsServiceIsolateDescendant(Isolate* isolate);
  static CODE_Port Port();
  static void WaitForServiceIsolateStartup();

  // Returns `true` if the request was successfully sent.  If it was, the
  // [reply_port] will receive a CODE_TypedData_kUint8 response json.
  //
  // If sending the rpc failed and [error] is not `nullptr` then [error] might
  // be set to a string containing the reason for the failure. If so, the
  // caller is responsible for free()ing the error.
  static bool SendServiceRpc(uint8_t* request_json,
                             intptr_t request_json_length,
                             CODE_Port reply_port,
                             char** error);

  static void Run();
  static bool SendIsolateStartupMessage();
  static bool SendIsolateShutdownMessage();
  static bool SendServiceControlMessage(Thread* thread,
                                        CODE_Port port_id,
                                        intptr_t code,
                                        const char* name);
  static void SendServiceExitMessage();
  static void Shutdown();

  static void BootVmServiceLibrary();

  static void RegisterRunningIsolates(
      const GrowableArray<CODE_Port>& isolate_ports,
      const GrowableArray<const String*>& isolate_names);

  static void RequestServerInfo(const SendPort& sp);
  static void ControlWebServer(const SendPort& sp,
                               bool enable,
                               const Bool& silenceOutput);

  static void SetServerAddress(const char* address);

  // Returns the server's web address or nullptr if none is running.
  static const char* server_address() { return server_address_; }

  static void VisitObjectPointers(ObjectPointerVisitor* visitor);

 private:
  static void KillServiceIsolate();

 protected:
  static void SetServicePort(CODE_Port port);
  static void SetServiceIsolate(Isolate* isolate);
  static void FinishedExiting();
  static void FinishedInitializing();
  static void InitializingFailed(char* error);
  static void MaybeMakeServiceIsolate(Isolate* isolate);
  static CODE_IsolateGroupCreateCallback create_group_callback() {
    return create_group_callback_;
  }

  static CODE_IsolateGroupCreateCallback create_group_callback_;
  static Monitor* monitor_;
  enum State{
      kStopped,
      kStarting,
      kStarted,
      kStopping,
  };
  static State state_;
  static Isolate* isolate_;
  static CODE_Port port_;
  static CODE_Port origin_;
  static char* server_address_;

  // If starting the service-isolate failed, this error might provide the reason
  // for the failure.
  static char* startup_failure_reason_;
#else

 public:
  static bool Exists() { return false; }
  static bool IsRunning() { return false; }
  static bool IsServiceIsolate(const Isolate* isolate) { return false; }
  static bool IsServiceIsolateDescendant(Isolate* isolate) { return false; }
  static void Run() {}
  static bool SendIsolateStartupMessage() { return false; }
  static bool SendIsolateShutdownMessage() { return false; }
  static void SendServiceExitMessage() {}
  static void Shutdown() {}
  static void RegisterRunningIsolate(Isolate* isolate) {}
  static void VisitObjectPointers(ObjectPointerVisitor* visitor) {}

 protected:
  static void SetServiceIsolate(Isolate* isolate) { UNREACHABLE(); }
#endif  // !defined(PRODUCT)

  friend class Dart;
  friend class Isolate;
  friend class RunServiceTask;
  friend class ServiceIsolateNatives;
};

}  // namespace dart

#endif  // RUNTIME_VM_SERVICE_ISOLATE_H_
