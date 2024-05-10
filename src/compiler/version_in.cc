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

#include "src/version.h"

#include "src/globals.h"

namespace Code {

const char* Version::String() {
  return str_;
}

const char* Version::SnapshotString() {
  return snapshot_hash_;
}

const char* Version::CommitString() {
  return commit_;
}

const char* Version::SdkHash() {
  return git_short_hash_;
}

const char* Version::snapshot_hash_ = "{{SNAPSHOT_HASH}}";
const char* Version::str_ =
    "{{VERSION_STR}} ({{CHANNEL}}) ({{COMMIT_TIME}})"
    " on \"" kHostOperatingSystemName
    "_"
#if defined(USING_SIMULATOR)
    "sim"
#endif
    kTargetArchitectureName "\"";
const char* Version::commit_ = "{{VERSION_STR}}";
const char* Version::git_short_hash_ = "{{GIT_HASH}}";

}  // namespace dart
