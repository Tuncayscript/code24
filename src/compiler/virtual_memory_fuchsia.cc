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

#include "src/globals.h"
#if defined(CODE_HOST_OS_FUCHSIA)

#include "src/virtual_memory.h"

#include <zircon/process.h>
#include <zircon/status.h>
#include <zircon/syscalls.h>

#include "platform/assert.h"
#include "src/allocation.h"
#include "src/growable_array.h"
#include "src/isolate.h"
#include "src/lockers.h"
#include "src/memory_region.h"
#include "src/os.h"
#include "src/os_thread.h"
#include "src/virtual_memory_compressed.h"

// #define VIRTUAL_MEMORY_LOGGING 1
#if defined(VIRTUAL_MEMORY_LOGGING)
#define LOG_ERR(msg, ...)                                                      \
  OS::PrintErr("VMVM: %s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_INFO(msg, ...)                                                     \
  OS::PrintErr("VMVM: %s:%d: " msg, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_ERR(msg, ...)
#define LOG_INFO(msg, ...)
#endif  // defined(VIRTUAL_MEMORY_LOGGING)

namespace Code {

DECLARE_FLAG(bool, write_protect_code);

uword VirtualMemory::page_size_ = 0;

#if defined(CODE_COMPRESSED_POINTERS)
static zx_handle_t compressed_heap_vmar_ = ZX_HANDLE_INVALID;
static uword compressed_heap_base_ = 0;
#endif  // defined(CODE_COMPRESSED_POINTERS)
static zx_handle_t vmex_resource_ = ZX_HANDLE_INVALID;

intptr_t VirtualMemory::CalculatePageSize() {
  const intptr_t page_size = getpagesize();
  ASSERT(page_size != 0);
  ASSERT(Utils::IsPowerOfTwo(page_size));
  return page_size;
}

void VirtualMemory::Init(zx_handle_t vmex_resource) {
  if (FLAG_old_gen_heap_size < 0 || FLAG_old_gen_heap_size > kMaxAddrSpaceMB) {
    OS::PrintErr(
        "warning: value specified for --old_gen_heap_size %d is larger than"
        " the physically addressable range, using 0(unlimited) instead.`\n",
        FLAG_old_gen_heap_size);
    FLAG_old_gen_heap_size = 0;
  }
  if (FLAG_new_gen_semi_max_size < 0 ||
      FLAG_new_gen_semi_max_size > kMaxAddrSpaceMB) {
    OS::PrintErr(
        "warning: value specified for --new_gen_semi_max_size %d is larger"
        " than the physically addressable range, using %" Pd " instead.`\n",
        FLAG_new_gen_semi_max_size, kDefaultNewGenSemiMaxSize);
    FLAG_new_gen_semi_max_size = kDefaultNewGenSemiMaxSize;
  }

#if defined(CODE_COMPRESSED_POINTERS)
  if (compressed_heap_vmar_ == ZX_HANDLE_INVALID) {
    const zx_vm_option_t align_flag =
        Utils::ShiftForPowerOfTwo(kCompressedHeapAlignment) << ZX_VM_ALIGN_BASE;
    const zx_vm_option_t options = ZX_VM_CAN_MAP_READ | ZX_VM_CAN_MAP_WRITE |
                                   ZX_VM_CAN_MAP_SPECIFIC | align_flag;
    zx_vaddr_t region;
    zx_status_t status =
        zx_vmar_allocate(zx_vmar_root_self(), options, 0, kCompressedHeapSize,
                         &compressed_heap_vmar_, &region);
    if (status != ZX_OK) {
      LOG_ERR("zx_vmar_allocate(0x%lx) failed: %s\n", kCompressedHeapSize,
              zx_status_get_string(status));
    } else {
      compressed_heap_base_ = reinterpret_cast<uword>(region);
      ASSERT(Utils::IsAligned(compressed_heap_base_, kCompressedHeapAlignment));
    }
  }
#endif  // defined(CODE_COMPRESSED_POINTERS)

  page_size_ = CalculatePageSize();
  vmex_resource_ = vmex_resource;
}

void VirtualMemory::Cleanup() {
  vmex_resource_ = ZX_HANDLE_INVALID;
  page_size_ = 0;

#if defined(CODE_COMPRESSED_POINTERS)
  zx_vmar_destroy(compressed_heap_vmar_);
  compressed_heap_vmar_ = ZX_HANDLE_INVALID;
  compressed_heap_base_ = 0;
#endif  // defined(CODE_COMPRESSED_POINTERS)
}

static zx_handle_t getVmarForAddress(uword address) {
#if defined(CODE_COMPRESSED_POINTERS)
  if (address - compressed_heap_base_ < kCompressedHeapSize) {
    return compressed_heap_vmar_;
  }
#endif  // defined(CODE_COMPRESSED_POINTERS)
  return zx_vmar_root_self();
}

static void Unmap(zx_handle_t vmar, uword start, uword end) {
  ASSERT(start <= end);
  const uword size = end - start;
  if (size == 0) {
    return;
  }

  zx_status_t status = zx_vmar_unmap(vmar, start, size);
  if (status != ZX_OK) {
    FATAL("zx_vmar_unmap failed: %s\n", zx_status_get_string(status));
  }
}

VirtualMemory* VirtualMemory::AllocateAligned(intptr_t size,
                                              intptr_t alignment,
                                              bool is_executable,
                                              bool is_compressed,
                                              const char* name) {
  // When FLAG_write_protect_code is active, code memory (indicated by
  // is_executable = true) is allocated as non-executable and later
  // changed to executable via VirtualMemory::Protect, which requires
  // ZX_RIGHT_EXECUTE on the underlying VMO.
  ASSERT(Utils::IsAligned(size, page_size_));
  ASSERT(Utils::IsPowerOfTwo(alignment));
  ASSERT(Utils::IsAligned(alignment, page_size_));

  const zx_vm_option_t align_flag = Utils::ShiftForPowerOfTwo(alignment)
                                    << ZX_VM_ALIGN_BASE;
  ASSERT((ZX_VM_ALIGN_1KB <= align_flag) && (align_flag <= ZX_VM_ALIGN_4GB));

#if defined(CODE_COMPRESSED_POINTERS)
  zx_handle_t vmar;
  if (is_compressed) {
    RELEASE_ASSERT(!is_executable);
    vmar = compressed_heap_vmar_;
  } else {
    vmar = zx_vmar_root_self();
  }
#else
  zx_handle_t vmar = zx_vmar_root_self();
#endif  // defined(CODE_COMPRESSED_POINTERS)
  zx_handle_t vmo = ZX_HANDLE_INVALID;
  zx_status_t status = zx_vmo_create(size, 0u, &vmo);
  if (status == ZX_ERR_NO_MEMORY) {
    LOG_ERR("zx_vmo_create(0x%lx) failed: %s\n", size,
            zx_status_get_string(status));
    return nullptr;
  } else if (status != ZX_OK) {
    FATAL("zx_vmo_create(0x%lx) failed: %s\n", size,
          zx_status_get_string(status));
  }

  if (name != nullptr) {
    zx_object_set_property(vmo, ZX_PROP_NAME, name, strlen(name));
  }

  if (is_executable) {
    // Add ZX_RIGHT_EXECUTE permission to VMO, so it can be mapped
    // into memory as executable (now or later).
    status = zx_vmo_replace_as_executable(vmo, vmex_resource_, &vmo);
    if (status == ZX_ERR_NO_MEMORY) {
      LOG_ERR("zx_vmo_replace_as_executable() failed: %s\n",
              zx_status_get_string(status));
      zx_handle_close(vmo);
      return nullptr;
    } else if (status != ZX_OK) {
      FATAL("zx_vmo_replace_as_executable() failed: %s\n",
            zx_status_get_string(status));
    }
  }

  const zx_vm_option_t region_options =
      ZX_VM_PERM_READ | ZX_VM_PERM_WRITE | align_flag |
      ((is_executable && !FLAG_write_protect_code) ? ZX_VM_PERM_EXECUTE : 0);
  uword base;
  status = zx_vmar_map(vmar, region_options, 0, vmo, 0u, size, &base);
  LOG_INFO("zx_vmar_map(%u, 0x%lx, 0x%lx)\n", region_options, base, size);
  if (status != ZX_OK) {
    LOG_ERR("zx_vmar_map(%u, 0x%lx, 0x%lx) failed: %s\n", region_options, base,
            size, zx_status_get_string(status));
    zx_handle_close(vmo);
    return nullptr;
  }
  void* region_ptr = reinterpret_cast<void*>(base);
  MemoryRegion region(region_ptr, size);
  VirtualMemory* result = new VirtualMemory(region, region);
  zx_handle_close(vmo);

#if defined(CODE_COMPRESSED_POINTERS)
  if (!is_executable) {
    uword offset = result->start() - compressed_heap_base_;
    ASSERT(offset < kCompressedHeapSize);
  }
#endif  // defined(CODE_COMPRESSED_POINTERS)

  return result;
}

VirtualMemory::~VirtualMemory() {
  // Reserved region may be empty due to VirtualMemory::Truncate.
  if (vm_owns_region() && reserved_.size() != 0) {
    Unmap(getVmarForAddress(reserved_.start()), reserved_.start(),
          reserved_.end());
    LOG_INFO("zx_vmar_unmap(0x%lx, 0x%lx) success\n", reserved_.start(),
             reserved_.size());
  }
}

bool VirtualMemory::FreeSubSegment(void* address, intptr_t size) {
  const uword start = reinterpret_cast<uword>(address);
  Unmap(getVmarForAddress(start), start, start + size);
  LOG_INFO("zx_vmar_unmap(0x%p, 0x%lx) success\n", address, size);
  return true;
}

void VirtualMemory::Protect(void* address, intptr_t size, Protection mode) {
#if defined(DEBUG)
  Thread* thread = Thread::Current();
  ASSERT(thread == nullptr || thread->IsDartMutatorThread() ||
         thread->isolate() == nullptr ||
         thread->isolate()->mutator_thread()->IsAtSafepoint());
#endif
  const uword start_address = reinterpret_cast<uword>(address);
  const uword end_address = start_address + size;
  const uword page_address = Utils::RoundDown(start_address, PageSize());
  uint32_t prot = 0;
  switch (mode) {
    case kNoAccess:
      prot = 0;
      break;
    case kReadOnly:
      prot = ZX_VM_PERM_READ;
      break;
    case kReadWrite:
      prot = ZX_VM_PERM_READ | ZX_VM_PERM_WRITE;
      break;
    case kReadExecute:
      prot = ZX_VM_PERM_READ | ZX_VM_PERM_EXECUTE;
      break;
    case kReadWriteExecute:
      prot = ZX_VM_PERM_READ | ZX_VM_PERM_WRITE | ZX_VM_PERM_EXECUTE;
      break;
  }
  zx_status_t status =
      zx_vmar_protect(getVmarForAddress(page_address), prot, page_address,
                      end_address - page_address);
  LOG_INFO("zx_vmar_protect(%u, 0x%lx, 0x%lx)\n", prot, page_address,
           end_address - page_address);
  if (status != ZX_OK) {
    FATAL("zx_vmar_protect(0x%lx, 0x%lx) failed: %s\n", page_address,
          end_address - page_address, zx_status_get_string(status));
  }
}

void VirtualMemory::DontNeed(void* address, intptr_t size) {
  uword start_address = reinterpret_cast<uword>(address);
  uword end_address = start_address + size;
  uword page_address = Utils::RoundDown(start_address, PageSize());
  zx_status_t status = zx_vmar_op_range(
      getVmarForAddress(reinterpret_cast<uword>(address)), ZX_VMAR_OP_DONT_NEED,
      page_address, end_address - page_address, nullptr, 0);
  LOG_INFO("zx_vmar_op_range(DONTNEED, 0x%lx, 0x%lx)\n", page_address,
           end_address - page_address);
  if (status != ZX_OK) {
    FATAL("zx_vmar_op_range(DONTNEED, 0x%lx, 0x%lx) failed: %s\n", page_address,
          end_address - page_address, zx_status_get_string(status));
  }
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_FUCHSIA)
