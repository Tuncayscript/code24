#ifndef RUNTIME_VM_PORT_H_
#define RUNTIME_VM_PORT_H_

#include <memory>

#include "include/code_api.h"
#include "src/allocation.h"
#include "src/globals.h"
#include "src/json_stream.h"
#include "src/port_set.h"
#include "src/random.h"

namespace Code {

class Isolate;
class Message;
class MessageHandler;
class Mutex;

class PortMap : public AllStatic {
 public:
  // Allocate a port for the provided handler and return its VM-global id.
  static CODE_Port CreatePort(MessageHandler* handler);

  // Close the port with id. All pending messages will be dropped.
  //
  // Returns true if the port is successfully closed.
  static bool ClosePort(CODE_Port id,
                        MessageHandler** message_handler = nullptr);

  // Close all the ports for the provided handler.
  static void ClosePorts(MessageHandler* handler);

  // Enqueues the message in the port with id. Returns false if the port is not
  // active any longer.
  //
  // Claims ownership of 'message'.
  static bool PostMessage(std::unique_ptr<Message> message,
                          bool before_events = false);

  // Returns the owning Isolate for port 'id'.
  static Isolate* GetIsolate(CODE_Port id);

  // Returns the origin id for port 'id'.
  static CODE_Port GetOriginId(CODE_Port id);

#if defined(TESTING)
  static bool PortExists(CODE_Port id);
  static bool HasPorts(MessageHandler* handler);
#endif

  // Whether the destination port's isolate is a member of [isolate_group].
  static bool IsReceiverInThisIsolateGroupOrClosed(CODE_Port receiver,
                                                   IsolateGroup* group);

  static void Init();
  static void Cleanup();

  static void PrintPortsForMessageHandler(MessageHandler* handler,
                                          JSONStream* stream);

  static void DebugDumpForMessageHandler(MessageHandler* handler);

 private:
  struct Entry : public PortSet<Entry>::Entry {
    Entry() : handler(nullptr) {}

    MessageHandler* handler;
  };

  // Allocate a new unique port.
  static CODE_Port AllocatePort();

  // Lock protecting access to the port map.
  static Mutex* mutex_;

  static PortSet<Entry>* ports_;

  static Random* prng_;
};

}  // namespace dart

#endif  // RUNTIME_VM_PORT_H_
