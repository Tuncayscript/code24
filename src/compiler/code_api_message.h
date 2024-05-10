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

#ifndef RUNTIME_VM_CODE_API_MESSAGE_H_
#define RUNTIME_VM_CODE_API_MESSAGE_H_

#include "include/code_native_api.h"
#include "platform/utils.h"
#include "src/allocation.h"
#include "src/code_api_state.h"
#include "src/message.h"
#include "src/raw_object.h"
#include "src/snapshot.h"

namespace Code {

// This class handles translation of certain ObjectPtrs to CObjects for
// NativeMessageHandlers.
//
// TODO(zra): Expand to support not only null, but also other VM heap objects
// as well.
class ApiObjectConverter : public AllStatic {
 public:
  static bool CanConvert(const ObjectPtr raw_obj) {
    return !raw_obj->IsHeapObject() || (raw_obj == Object::null());
  }

  static bool Convert(const ObjectPtr raw_obj, CODE_CObject* c_obj) {
    if (!raw_obj->IsHeapObject()) {
      ConvertSmi(static_cast<const SmiPtr>(raw_obj), c_obj);
    } else if (raw_obj == Object::null()) {
      ConvertNull(c_obj);
    } else {
      return false;
    }
    return true;
  }

 private:
  static void ConvertSmi(const SmiPtr raw_smi, CODE_CObject* c_obj) {
    ASSERT(!raw_smi->IsHeapObject());
    intptr_t value = Smi::Value(raw_smi);
    if (Utils::IsInt(31, value)) {
      c_obj->type = CODE_CObject_kInt32;
      c_obj->value.as_int32 = static_cast<int32_t>(value);
    } else {
      c_obj->type = CODE_CObject_kInt64;
      c_obj->value.as_int64 = static_cast<int64_t>(value);
    }
  }

  static void ConvertNull(CODE_CObject* c_obj) {
    c_obj->type = CODE_CObject_kNull;
    c_obj->value.as_int64 = 0;
  }
};

}  // namespace dart

#endif  // RUNTIME_VM_CODE_API_MESSAGE_H_
