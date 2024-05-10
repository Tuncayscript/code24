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

#include "src/native_message_handler.h"

#include <memory>

#include "src/code_api_message.h"
#include "src/isolate.h"
#include "src/message.h"
#include "src/message_snapshot.h"
#include "src/snapshot.h"

namespace Code {

NativeMessageHandler::NativeMessageHandler(const char* name,
                                           CODE_NativeMessageHandler func)
    : name_(Utils::StrDup(name)), func_(func) {}

NativeMessageHandler::~NativeMessageHandler() {
  free(name_);
}

#if defined(DEBUG)
void NativeMessageHandler::CheckAccess() const {
  ASSERT(Isolate::Current() == nullptr);
}
#endif

MessageHandler::MessageStatus NativeMessageHandler::HandleMessage(
    std::unique_ptr<Message> message) {
  if (message->IsOOB()) {
    // We currently do not use OOB messages for native ports.
    UNREACHABLE();
  }
  // We create a native scope for handling the message.
  // All allocation of objects for decoding the message is done in the
  // zone associated with this scope.
  ApiNativeScope scope;
  CODE_CObject* object = ReadApiMessage(scope.zone(), message.get());
  (*func())(message->dest_port(), object);
  return kOK;
}

}  // namespace code
