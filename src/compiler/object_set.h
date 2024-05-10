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

#ifndef RUNTIME_VM_OBJECT_SET_H_
#define RUNTIME_VM_OBJECT_SET_H_

#include "platform/utils.h"
#include "src/bit_vector.h"
#include "src/globals.h"
#include "src/raw_object.h"
#include "src/zone.h"

namespace Code {

class ObjectSetRegion : public ZoneAllocated {
 public:
  ObjectSetRegion(Zone* zone, uword start, uword end)
      : start_(start),
        end_(end),
        bit_vector_(zone, (end - start) >> kWordSizeLog2) {}

  bool ContainsAddress(uword address) const {
    return address >= start_ && address < end_;
  }

  intptr_t IndexForAddress(uword address) const {
    ASSERT(Utils::IsAligned(address, kWordSize));
    return (address - start_) >> kWordSizeLog2;
  }

  void AddObject(uword address) { bit_vector_.Add(IndexForAddress(address)); }

  bool ContainsObject(uword address) const {
    return bit_vector_.Contains(IndexForAddress(address));
  }

  uword start() const { return start_; }
  uword end() const { return end_; }

 private:
  uword start_;
  uword end_;
  BitVector bit_vector_;
};

class ObjectSet : public ZoneAllocated {
 public:
  explicit ObjectSet(Zone* zone) : zone_(zone), sorted_(true), regions_() {}

  void AddRegion(uword start, uword end) {
    if (start == end) {
      return;  // Ignore empty regions, such as semispaces in the vm-isolate.
    }
    ASSERT(start < end);
    ObjectSetRegion* region = new (zone_) ObjectSetRegion(zone_, start, end);
    regions_.Add(region);
    sorted_ = false;
  }

  void SortRegions() {
    regions_.Sort(CompareRegions);
    sorted_ = true;
  }

  bool Contains(ObjectPtr raw_obj) const {
    uword raw_addr = UntaggedObject::ToAddr(raw_obj);
    ObjectSetRegion* region;
    if (FindRegion(raw_addr, &region)) {
      return region->ContainsObject(raw_addr);
    }
    return false;
  }

  void Add(ObjectPtr raw_obj) {
    uword raw_addr = UntaggedObject::ToAddr(raw_obj);
    ObjectSetRegion* region;
    if (FindRegion(raw_addr, &region)) {
      return region->AddObject(raw_addr);
    }
    FATAL("Address not in any heap region");
  }

 private:
  static int CompareRegions(ObjectSetRegion* const* a,
                            ObjectSetRegion* const* b) {
    const uword a_start = (*a)->start();
    const uword b_start = (*b)->start();
    if (a_start < b_start) {
      return -1;
    } else if (a_start == b_start) {
      return 0;
    } else {
      return 1;
    }
  }

  bool FindRegion(uword addr, ObjectSetRegion** region) const {
    ASSERT(sorted_);
    intptr_t lo = 0;
    intptr_t hi = regions_.length() - 1;
    while (lo <= hi) {
      const intptr_t mid = (hi - lo + 1) / 2 + lo;
      ASSERT(mid >= lo);
      ASSERT(mid <= hi);
      *region = regions_[mid];
      if (addr < (*region)->start()) {
        hi = mid - 1;
      } else if (addr >= (*region)->end()) {
        lo = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }

  Zone* zone_;
  bool sorted_;
  GrowableArray<ObjectSetRegion*> regions_;
};

}  // namespace dart

#endif  // RUNTIME_VM_OBJECT_SET_H_
