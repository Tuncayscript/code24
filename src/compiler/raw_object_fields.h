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
//
// This file (and "raw_object_fields.cc") provide a kind of reflection that
// allows us to identify the name of fields in hand-written "Raw..." classes
// (from "raw_object.h") given the class and the offset within the object. This
// is used for example by the snapshot profile writer ("v8_snapshot_writer.h")
// to show the property names of these built-in objects in the snapshot profile.

#ifndef RUNTIME_VM_RAW_OBJECT_FIELDS_H_
#define RUNTIME_VM_RAW_OBJECT_FIELDS_H_

#include <utility>

#include "src/hash_map.h"
#include "src/object.h"
#include "src/raw_object.h"

namespace Code {

#if defined(CODE_PRECOMPILER) || defined(CODE_ENABLE_HEAP_SNAPSHOT_WRITER)

class OffsetsTable : public ZoneAllocated {
 public:
  explicit OffsetsTable(Zone* zone);

  // Returns 'nullptr' if no offset was found.
  // Otherwise, the returned string is allocated in global static memory.
  const char* FieldNameForOffset(intptr_t cid, intptr_t offset);

  struct OffsetsTableEntry {
    intptr_t class_id;
    const char* field_name;
    bool is_compressed_pointer;
    intptr_t offset;
  };

  static const MallocGrowableArray<OffsetsTableEntry>& offsets_table();
  static void Init();
  static void Cleanup();

 private:
  struct IntAndIntToStringMapTraits {
    typedef std::pair<intptr_t, intptr_t> Key;
    typedef const char* Value;

    struct Pair {
      Key key;
      Value value;
      Pair() : key({-1, -1}), value(nullptr) {}
      Pair(Key k, Value v) : key(k), value(v) {}
    };

    static Value ValueOf(Pair pair) { return pair.value; }
    static Key KeyOf(Pair pair) { return pair.key; }
    static uword Hash(Key key) {
      return Utils::WordHash(key.first ^ key.second);
    }
    static bool IsKeyEqual(Pair x, Key y) {
      return x.key.first == y.first && x.key.second == y.second;
    }
  };

  DirectChainedHashMap<IntAndIntToStringMapTraits> cached_offsets_;
};

#else

class OffsetsTable : public ZoneAllocated {
 public:
  explicit OffsetsTable(Zone* zone) {}

  const char* FieldNameForOffset(intptr_t cid, intptr_t offset) {
    return nullptr;
  }

  static void Init() {}
  static void Cleanup() {}
};

#endif

}  // namespace dart

#endif  // RUNTIME_VM_RAW_OBJECT_FIELDS_H_
