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

#ifndef RUNTIME_VM_VERSION_H_
#define RUNTIME_VM_VERSION_H_

#include "src/allocation.h"

namespace Code {

class Version : public AllStatic {
 public:
  static const char* String();
  static const char* SnapshotString();
  static const char* CommitString();
  static const char* SdkHash();

 private:
  static const char* str_;
  static const char* snapshot_hash_;
  static const char* commit_;
  static const char* git_short_hash_;
};

}  // namespace dart

#endif  // RUNTIME_VM_VERSION_H_
