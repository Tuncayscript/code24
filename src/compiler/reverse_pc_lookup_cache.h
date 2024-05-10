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

#ifndef RUNTIME_VM_REVERSE_PC_LOOKUP_CACHE_H_
#define RUNTIME_VM_REVERSE_PC_LOOKUP_CACHE_H_

#include "src/allocation.h"
#include "src/globals.h"
#include "src/raw_object.h"
#include "src/tagged_pointer.h"

namespace Code {

class IsolateGroup;

// This class provides mechanism to find Code and CompressedStackMaps
// objects corresponding to the given PC.
// Can only be used in AOT runtime with bare instructions.
class ReversePc : public AllStatic {
 public:
  // Looks for Code object corresponding to |pc| in the
  // given isolate |group| and vm isolate group.
  static CodePtr Lookup(IsolateGroup* group, uword pc, bool is_return_address);

  static const UntaggedCompressedStackMaps::Payload* FindStackMap(
      IsolateGroup* group,
      uword pc,
      bool is_return_address,
      uword* code_start,
      const UntaggedCompressedStackMaps::Payload** global_table);

 private:
  static const UntaggedCompressedStackMaps::Payload* FindStackMapInGroup(
      IsolateGroup* group,
      uword pc,
      bool is_return_address,
      uword* code_start,
      const UntaggedCompressedStackMaps::Payload** global_table);

  static CodePtr FindCodeInGroup(IsolateGroup* group,
                                 uword pc,
                                 bool is_return_address);
  static CodePtr FindCode(IsolateGroup* group,
                          uword pc,
                          bool is_return_address);
};

}  // namespace dart

#endif  // RUNTIME_VM_REVERSE_PC_LOOKUP_CACHE_H_
