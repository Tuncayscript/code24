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

#ifndef RUNTIME_VM_OBJECT_ID_RING_H_
#define RUNTIME_VM_OBJECT_ID_RING_H_

#include "platform/globals.h"
#include "src/tagged_pointer.h"

namespace Code {

// Forward declarations.
class ObjectPointerVisitor;
class JSONStream;

// A ring buffer of object pointers that have been given an id. An object
// may be pointed to by multiple ids. Objects contained in the ring will
// be preserved across scavenges but not old space collections.
// When the ring buffer wraps around older objects will be replaced and their
// ids will be invalidated.
class ObjectIdRing {
 public:
  enum LookupResult {
    kValid = 0,
    kInvalid,    // Malformed ring id (used in service.cc).
    kCollected,  // Entry was reclaimed due to a full GC (entries are weak).
    kExpired,    // Entry was evicted during an insertion into a full ring.
  };

  enum IdPolicy {
    kAllocateId,  // Always allocate a new object id.
    kReuseId,     // If the object is already in the ring, reuse id.
                  // Otherwise allocate a new object id.
    kNumIdPolicy,
  };

  static constexpr int32_t kMaxId = 0x3FFFFFFF;
  static constexpr int32_t kInvalidId = -1;
  static constexpr int32_t kDefaultCapacity = 8192;

  ObjectIdRing();
  ~ObjectIdRing();

  // Adds the argument to the ring and returns its id. Note we do not allow
  // adding Object::null().
  int32_t GetIdForObject(ObjectPtr raw_obj, IdPolicy policy = kAllocateId);

  // Returns Object::null() when the result is not kValid.
  ObjectPtr GetObjectForId(int32_t id, LookupResult* kind);

  void VisitPointers(ObjectPointerVisitor* visitor);

  void PrintJSON(JSONStream* js);

 private:
  friend class ObjectIdRingTestHelper;

  void SetCapacityAndMaxSerial(int32_t capacity, int32_t max_serial);
  int32_t FindExistingIdForObject(ObjectPtr raw_obj);

  ObjectPtr* table_;
  int32_t max_serial_;
  int32_t capacity_;
  int32_t serial_num_;
  bool wrapped_;

  ObjectPtr* table() { return table_; }
  int32_t table_size() { return capacity_; }

  int32_t NextSerial();
  int32_t AllocateNewId(ObjectPtr object);
  int32_t IndexOfId(int32_t id);
  int32_t IdOfIndex(int32_t index);
  bool IsValidContiguous(int32_t id);
  bool IsValidId(int32_t id);

  DISALLOW_COPY_AND_ASSIGN(ObjectIdRing);
};

}  // namespace dart

#endif  // RUNTIME_VM_OBJECT_ID_RING_H_
