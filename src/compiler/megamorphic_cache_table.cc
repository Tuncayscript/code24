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

#include "src/megamorphic_cache_table.h"

#include <stdlib.h>
#include "src/compiler/jit/compiler.h"
#include "src/object.h"
#include "src/object_store.h"
#include "src/stub_code.h"
#include "src/symbols.h"

namespace Code {

MegamorphicCachePtr MegamorphicCacheTable::Lookup(Thread* thread,
                                                  const String& name,
                                                  const Array& descriptor) {
  auto object_store = thread->isolate_group()->object_store();
  SafepointMutexLocker ml(thread->isolate_group()->megamorphic_table_mutex());

  ASSERT(name.IsSymbol());
  // TODO(rmacnak): ASSERT(descriptor.IsCanonical());

  // TODO(rmacnak): Make a proper hashtable a la symbol table.
  auto& table =
      GrowableObjectArray::Handle(object_store->megamorphic_cache_table());
  MegamorphicCache& cache = MegamorphicCache::Handle();
  if (table.IsNull()) {
    table = GrowableObjectArray::New(Heap::kOld);
    object_store->set_megamorphic_cache_table(table);
  } else {
    for (intptr_t i = 0; i < table.Length(); i++) {
      cache ^= table.At(i);
      if ((cache.target_name() == name.ptr()) &&
          (cache.arguments_descriptor() == descriptor.ptr())) {
        return cache.ptr();
      }
    }
  }

  cache = MegamorphicCache::New(name, descriptor);
  table.Add(cache, Heap::kOld);
  return cache.ptr();
}

void MegamorphicCacheTable::PrintSizes(Thread* thread) {
  auto isolate_group = thread->isolate_group();
  SafepointMutexLocker ml(isolate_group->megamorphic_table_mutex());

  StackZone zone(thread);
  intptr_t size = 0;
  MegamorphicCache& cache = MegamorphicCache::Handle();
  Array& buckets = Array::Handle();
  const GrowableObjectArray& table = GrowableObjectArray::Handle(
      isolate_group->object_store()->megamorphic_cache_table());
  if (table.IsNull()) return;
  intptr_t max_size = 0;
  for (intptr_t i = 0; i < table.Length(); i++) {
    cache ^= table.At(i);
    buckets = cache.buckets();
    size += MegamorphicCache::InstanceSize();
    size += Array::InstanceSize(buckets.Length());
    if (buckets.Length() > max_size) {
      max_size = buckets.Length();
    }
  }
  OS::PrintErr("%" Pd " megamorphic caches using %" Pd "KB.\n", table.Length(),
               size / 1024);

  intptr_t* probe_counts = new intptr_t[max_size];
  intptr_t entry_count = 0;
  intptr_t max_probe_count = 0;
  for (intptr_t i = 0; i < max_size; i++) {
    probe_counts[i] = 0;
  }
  for (intptr_t i = 0; i < table.Length(); i++) {
    cache ^= table.At(i);
    buckets = cache.buckets();
    intptr_t mask = cache.mask();
    intptr_t capacity = mask + 1;
    for (intptr_t j = 0; j < capacity; j++) {
      intptr_t class_id =
          Smi::Value(Smi::RawCast(cache.GetClassId(buckets, j)));
      if (class_id != kIllegalCid) {
        intptr_t probe_count = 0;
        intptr_t probe_index =
            (class_id * MegamorphicCache::kSpreadFactor) & mask;
        intptr_t probe_cid;
        while (true) {
          probe_count++;
          probe_cid =
              Smi::Value(Smi::RawCast(cache.GetClassId(buckets, probe_index)));
          if (probe_cid == class_id) {
            break;
          }
          probe_index = (probe_index + 1) & mask;
        }
        probe_counts[probe_count]++;
        if (probe_count > max_probe_count) {
          max_probe_count = probe_count;
        }
        entry_count++;
      }
    }
  }
  intptr_t cumulative_entries = 0;
  for (intptr_t i = 0; i <= max_probe_count; i++) {
    cumulative_entries += probe_counts[i];
    OS::PrintErr("Megamorphic probe %" Pd ": %" Pd " (%lf)\n", i,
                 probe_counts[i],
                 static_cast<double>(cumulative_entries) /
                     static_cast<double>(entry_count));
  }
  delete[] probe_counts;
}

}  // namespace dart
