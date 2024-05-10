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

#ifndef RUNTIME_VM_MESSAGE_SNAPSHOT_H_
#define RUNTIME_VM_MESSAGE_SNAPSHOT_H_

#include <memory>

#include "include/code_native_api.h"
#include "src/message.h"
#include "src/object.h"

namespace Code {

std::unique_ptr<Message> WriteMessage(bool same_group,
                                      const Object& obj,
                                      CODE_Port dest_port,
                                      Message::Priority priority);

std::unique_ptr<Message> WriteApiMessage(Zone* zone,
                                         CODE_CObject* obj,
                                         CODE_Port dest_port,
                                         Message::Priority priority);

ObjectPtr ReadObjectGraphCopyMessage(Thread* thread, PersistentHandle* handle);

ObjectPtr ReadMessage(Thread* thread, Message* message);

CODE_CObject* ReadApiMessage(Zone* zone, Message* message);

}  // namespace dart

#endif  // RUNTIME_VM_MESSAGE_SNAPSHOT_H_
