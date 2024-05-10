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

#ifndef RUNTIME_VM_NATIVE_MESSAGE_HANDLER_H_
#define RUNTIME_VM_NATIVE_MESSAGE_HANDLER_H_

#include <memory>

#include "include/code_api.h"
#include "include/code_native_api.h"
#include "src/message_handler.h"

namespace Code {

// A NativeMessageHandler accepts messages and dispatches them to
// native C handlers.
class NativeMessageHandler : public MessageHandler {
 public:
  NativeMessageHandler(const char* name, CODE_NativeMessageHandler func);
  ~NativeMessageHandler();

  const char* name() const { return name_; }
  CODE_NativeMessageHandler func() const { return func_; }

  MessageStatus HandleMessage(std::unique_ptr<Message> message);

#if defined(DEBUG)
  // Check that it is safe to access this handler.
  void CheckAccess() const;
#endif

 private:
  char* name_;
  CODE_NativeMessageHandler func_;
};

}  // namespace dart

#endif  // RUNTIME_VM_NATIVE_MESSAGE_HANDLER_H_
