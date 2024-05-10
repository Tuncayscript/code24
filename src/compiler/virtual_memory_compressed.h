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

#ifndef RUNTIME_VM_VIRTUAL_MEMORY_COMPRESSED_H_
#define RUNTIME_VM_VIRTUAL_MEMORY_COMPRESSED_H_

#include "src/globals.h"
#include "src/heap/page.h"
#include "src/memory_region.h"

namespace Code {

#if defined(CODE_COMPRESSED_POINTERS)
static constexpr intptr_t kCompressedHeapSize = 4 * GB;
static constexpr intptr_t kCompressedHeapAlignment = 4 * GB;
static constexpr intptr_t kCompressedPageSize = kPageSize;
static constexpr intptr_t kCompressedHeapNumPages =
    kCompressedHeapSize / kPageSize;
static constexpr intptr_t kCompressedHeapBitmapSize =
    kCompressedHeapNumPages / 8;

#if !defined(CODE_HOST_OS_FUCHSIA)
#define CODE_COMPRESSED_HEAP
#endif  // !defined(CODE_HOST_OS_FUCHSIA)
#endif  // defined(CODE_COMPRESSED_POINTERS)

#if defined(CODE_COMPRESSED_HEAP)

// Utilities for allocating memory within a contiguous region of memory, for use
// with compressed pointers.
class VirtualMemoryCompressedHeap : public AllStatic {
 public:
  // Initializes the compressed heap. The callee must allocate a region of
  // kCompressedHeapSize bytes, aligned to kCompressedHeapSize.
  static void Init(void* compressed_heap_region, size_t size);

  // Cleans up the compressed heap. The callee is responsible for freeing the
  // region's memory.
  static void Cleanup();

  // Allocates a segment of the compressed heap with the given size. Returns a
  // heap memory region if a large enough free segment can't be found.
  static MemoryRegion Allocate(intptr_t size, intptr_t alignment);

  // Frees a segment.
  static void Free(void* address, intptr_t size);

  // Returns whether the address is within the compressed heap.
  static bool Contains(void* address);

  // Returns a pointer to the compressed heap region.
  static void* GetRegion();

 private:
  static bool IsPageUsed(uword page_id);
  static void SetPageUsed(uword page_id);
  static void ClearPageUsed(uword page_id);

  static uword base_;
  static uword size_;
  static uint8_t* pages_;
  static uword minimum_free_page_id_;
  static Mutex* mutex_;
};

#endif  // defined(CODE_COMPRESSED_HEAP)

}  // namespace dart

#endif  // RUNTIME_VM_VIRTUAL_MEMORY_COMPRESSED_H_
