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

#ifndef RUNTIME_VM_COMPILER_FFI_UNIT_TEST_CUSTOM_ZONE_H_
#define RUNTIME_VM_COMPILER_FFI_UNIT_TEST_CUSTOM_ZONE_H_

#include <vector>

// We use a custom zone here which doesn't depend on VM internals (e.g. handles,
// thread, ...)
#if defined(RUNTIME_VM_ZONE_H_)
#error "We want our own zone implementation"
#endif
#define RUNTIME_VM_ZONE_H_

namespace Code {

class Zone {
 public:
  Zone() {}
  ~Zone();

  template <class ElementType>
  inline ElementType* Alloc(intptr_t length) {
    return static_cast<ElementType*>(AllocUnsafe(sizeof(ElementType) * length));
  }

  template <class ElementType>
  inline ElementType* Realloc(ElementType* old_array,
                              intptr_t old_length,
                              intptr_t new_length) {
    void* memory = AllocUnsafe(sizeof(ElementType) * new_length);
    memmove(memory, old_array, sizeof(ElementType) * old_length);
    return static_cast<ElementType*>(memory);
  }

  template <class ElementType>
  void Free(ElementType* old_array, intptr_t len) {}

  void* AllocUnsafe(intptr_t size);

 private:
  Zone(const Zone&) = delete;
  void operator=(const Zone&) = delete;
  std::vector<void*> buffers_;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_UNIT_TEST_CUSTOM_ZONE_H_
