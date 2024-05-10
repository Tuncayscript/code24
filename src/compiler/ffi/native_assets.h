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

#ifndef RUNTIME_VM_FFI_NATIVE_ASSETS_H_
#define RUNTIME_VM_FFI_NATIVE_ASSETS_H_

#include "src/hash_table.h"
#include "src/tagged_pointer.h"
#include "src/thread.h"

namespace Code {

class NativeAssetsMapTraits {
 public:
  static const char* Name() { return "NativeAssetsMapTraits"; }
  static bool ReportStats() { return false; }

  static bool IsMatch(const Object& a, const Object& b) {
    const String& a_str = String::Cast(a);
    const String& b_str = String::Cast(b);

    ASSERT(a_str.HasHash() && b_str.HasHash());
    return a_str.Equals(b_str);
  }

  static uword Hash(const Object& key) { return String::Cast(key).Hash(); }

  static ObjectPtr NewKey(const String& str) { return str.ptr(); }
};
typedef UnorderedHashMap<NativeAssetsMapTraits> NativeAssetsMap;

// In JIT: Populates object_store->native_assets_map with the right info from
// object_store->native_assets_library.
//
// In AOT: The object_store->native_assets_library should have been
// pre-populated from the aotsnapshot.
ArrayPtr GetNativeAssetsMap(Thread* thread);

}  // namespace dart

#endif  // RUNTIME_VM_FFI_NATIVE_ASSETS_H_
