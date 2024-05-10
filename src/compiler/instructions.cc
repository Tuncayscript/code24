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

#include "src/instructions.h"

#include "src/object.h"
#if defined(CODE_PRECOMPILER)
#include "src/compiler/aot/precompiler.h"
#endif

namespace Code {

bool ObjectAtPoolIndex(const Code& code, intptr_t index, Object* obj) {
#if defined(CODE_PRECOMPILER)
  if (FLAG_precompiled_mode) {
    Precompiler* precompiler = Precompiler::Instance();
    if (precompiler != nullptr) {
      compiler::ObjectPoolBuilder* pool =
          precompiler->global_object_pool_builder();
      if (index < pool->CurrentLength()) {
        compiler::ObjectPoolBuilderEntry& entry = pool->EntryAt(index);
        if (entry.type() == compiler::ObjectPoolBuilderEntry::kTaggedObject) {
          *obj = entry.obj_->ptr();
          return true;
        }
      }
    }
    return false;
  }
#endif
  const ObjectPool& pool = ObjectPool::Handle(code.GetObjectPool());
  if (!pool.IsNull() && (index < pool.Length()) &&
      (pool.TypeAt(index) == ObjectPool::EntryType::kTaggedObject)) {
    *obj = pool.ObjectAt(index);
    return true;
  }
  return false;
}

}  // namespace dart
