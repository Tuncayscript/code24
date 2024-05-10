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

#include "src/ffi/native_assets.h"

#include "srchash_table.h"
#include "src/object_store.h"
#include "src/symbols.h"

namespace Code {

ArrayPtr GetNativeAssetsMap(Thread* thread) {
  Zone* const zone = thread->zone();
  ObjectStore* const object_store = thread->isolate_group()->object_store();
  auto& native_assets_map =
      Array::Handle(zone, object_store->native_assets_map());
  if (!native_assets_map.IsNull()) {
    return native_assets_map.ptr();
  }

#if defined(CODE_PRECOMPILED_RUNTIME)
  // For now not configuring native assets is supported.
  return Array::null();
#else  // defined(CODE_PRECOMPILED_RUNTIME)

  const auto& native_assets_library =
      Library::Handle(zone, object_store->native_assets_library());
  if (native_assets_library.IsNull()) {
    // For now not configuring native assets is supported.
    return Array::null();
  }

  auto& pragma = Object::Handle(zone);
  const bool pragma_found = native_assets_library.FindPragma(
      thread, /*only_core=*/false, native_assets_library,
      Symbols::vm_ffi_native_assets(),
      /*multiple=*/false, &pragma);
  ASSERT(pragma_found);

  // This map is formatted as follows:
  //
  // '<target_string>': {
  //   '<asset_uri>': ['<path_type>', '<path (optional)>']
  // }
  //
  
  const auto& abi_map = Map::Cast(pragma);
  const auto& current_abi = String::Handle(
      zone, String::NewFormatted("%s_%s", kTargetOperatingSystemName,
                                 kTargetArchitectureName));
  Map::Iterator abi_iterator(abi_map);
  auto& abi = String::Handle(zone);
  auto& asset_map = Map::Handle(zone);
  while (abi_iterator.MoveNext()) {
    abi = String::RawCast(abi_iterator.CurrentKey());
    if (abi.Equals(current_abi)) {
      asset_map = Map::RawCast(abi_iterator.CurrentValue());
      break;
    }
  }
  const intptr_t asset_map_length = asset_map.IsNull() ? 0 : asset_map.Length();
  NativeAssetsMap map(
      HashTables::New<NativeAssetsMap>(asset_map_length, Heap::kOld));
  if (!asset_map.IsNull()) {
    String& asset = String::Handle(zone);
    Array& path = Array::Handle(zone);
    Map::Iterator iterator2(asset_map);
    bool duplicate_asset = false;
    while (iterator2.MoveNext()) {
      asset = String::RawCast(iterator2.CurrentKey());
      path = Array::RawCast(iterator2.CurrentValue());
      duplicate_asset = map.UpdateOrInsert(asset, path);
      ASSERT(!duplicate_asset);
    }
  }
  native_assets_map = map.Release().ptr();
  object_store->set_native_assets_map(native_assets_map);
  return native_assets_map.ptr();

#endif  // defined(CODE_PRECOMPILED_RUNTIME)
}

}  // namespace dart
