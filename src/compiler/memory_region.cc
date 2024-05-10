#include "src/memory_region.h"

namespace Code {

void MemoryRegion::CopyFrom(uword offset, const MemoryRegion& from) const {
  ASSERT(from.pointer() != nullptr && from.size() > 0);
  ASSERT(this->size() >= from.size());
  ASSERT(offset <= this->size() - from.size());
  memmove(reinterpret_cast<void*>(start() + offset), from.pointer(),
          from.size());
}

}  // namespace dart
