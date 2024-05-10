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

#ifndef RUNTIME_VM_MEMORY_REGION_H_
#define RUNTIME_VM_MEMORY_REGION_H_

#include "platform/assert.h"
#include "platform/unaligned.h"
#include "src/allocation.h"
#include "src/globals.h"

namespace Code {

// Memory regions are useful for accessing memory with bounds check in
// debug mode. They can be safely passed by value and do not assume ownership
// of the region.
class MemoryRegion : public ValueObject {
 public:
  MemoryRegion() : pointer_(nullptr), size_(0) {}
  MemoryRegion(void* pointer, uword size) : pointer_(pointer), size_(size) {}
  MemoryRegion(const MemoryRegion& other) : ValueObject() { *this = other; }
  MemoryRegion& operator=(const MemoryRegion& other) {
    pointer_ = other.pointer_;
    size_ = other.size_;
    return *this;
  }

  void* pointer() const { return pointer_; }
  uword size() const { return size_; }
  void set_size(uword new_size) { size_ = new_size; }

  uword start() const { return reinterpret_cast<uword>(pointer_); }
  uword end() const { return start() + size_; }

  template <typename T>
  T Load(uword offset) const {
    return *ComputeInternalPointer<T>(offset);
  }

  template <typename T>
  void Store(uword offset, T value) const {
    *ComputeInternalPointer<T>(offset) = value;
  }

  template <typename T>
  void StoreUnaligned(uword offset, T value) const {
    dart::StoreUnaligned(ComputeInternalPointer<T>(offset), value);
  }

  template <typename T>
  T* PointerTo(uword offset) const {
    return ComputeInternalPointer<T>(offset);
  }

  bool Contains(uword address) const {
    return (address >= start()) && (address < end());
  }

  void CopyFrom(uword offset, const MemoryRegion& from) const;

  // Compute a sub memory region based on an existing one.
  void Subregion(const MemoryRegion& from, uword offset, uword size) {
    ASSERT(from.size() >= size);
    ASSERT(offset <= (from.size() - size));
    pointer_ = reinterpret_cast<void*>(from.start() + offset);
    size_ = size;
  }

  // Compute an extended memory region based on an existing one.
  void Extend(const MemoryRegion& region, uword extra) {
    pointer_ = region.pointer();
    size_ = (region.size() + extra);
  }

 private:
  template <typename T>
  T* ComputeInternalPointer(uword offset) const {
    ASSERT(size() >= sizeof(T));
    ASSERT(offset <= size() - sizeof(T));
    return reinterpret_cast<T*>(start() + offset);
  }

  void* pointer_;
  uword size_;
};

}  // namespace dart

#endif  // RUNTIME_VM_MEMORY_REGION_H_
