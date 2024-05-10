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

#ifndef RUNTIME_VM_OBJECT_GRAPH_COPY_H_
#define RUNTIME_VM_OBJECT_GRAPH_COPY_H_

namespace Code {

class Isolate;
class Object;
class ObjectPtr;
class Zone;

// Whether the object can safely be shared across isolates due to it being
// deeply immutable.
bool CanShareObjectAcrossIsolates(ObjectPtr obj);

// Makes a transitive copy of the object graph referenced by [object]. Will not
// copy objects that can be safely shared - due to being immutable.
//
// The result will be an array of length 3 of the format
//
//   [
//     <message>,
//     <collection-lib-objects-to-rehash>,
//     <core-lib-objects-to-rehash>,
//   ]
//
// If the array of objects to rehash is not `null` the receiver should re-hash
// those objects.
ObjectPtr CopyMutableObjectGraph(const Object& root);

typedef enum {
  kInternalToIsolateGroup,
  kExternalBetweenIsolateGroups,
} TraversalRules;

// Returns a string representation of a retaining path from `from` to `to`,
// blank string if `to` is not reachable from `from`.
// Traversal doesn't follow all the object graph links, only those
// that makes sense isolate message passing.
const char* FindRetainingPath(Zone* zone,
                              Isolate* isolate,
                              const Object& from,
                              const Object& to,
                              TraversalRules traversal_rules);

}  // namespace dart

#endif  // RUNTIME_VM_OBJECT_GRAPH_COPY_H_
