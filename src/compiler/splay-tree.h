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

#ifndef RUNTIME_VM_SPLAY_TREE_H_
#define RUNTIME_VM_SPLAY_TREE_H_

#include "platform/splay-tree.h"
#include "src/zone.h"

namespace Code {

// A zone splay tree.  The config type parameter encapsulates the
// different configurations of a concrete splay tree (see
// platform/splay-tree.h). The tree itself and all its elements are allocated
// in the Zone.
template <typename Config>
class ZoneSplayTree final : public SplayTree<Config, ZoneAllocated, Zone> {
 public:
  explicit ZoneSplayTree(Zone* zone)
      : SplayTree<Config, ZoneAllocated, Zone>(ASSERT_NOTNULL(zone)) {}
  ~ZoneSplayTree() {
    // Reset the root to avoid unneeded iteration over all tree nodes
    // in the destructor.  For a zone-allocated tree, nodes will be
    // freed by the Zone.
    SplayTree<Config, ZoneAllocated, Zone>::ResetRoot();
  }
};

}  // namespace dart

#endif  // RUNTIME_VM_SPLAY_TREE_H_
