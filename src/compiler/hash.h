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

#ifndef RUNTIME_VM_HASH_H_
#define RUNTIME_VM_HASH_H_

#include "platform/globals.h"

namespace Code {

inline uint32_t CombineHashes(uint32_t hash, uint32_t other_hash) {
  // Keep in sync with AssemblerBase::CombineHashes.
  hash += other_hash;
  hash += hash << 10;
  hash ^= hash >> 6;  // Logical shift, unsigned hash.
  return hash;
}

inline uint32_t FinalizeHash(uint32_t hash, intptr_t hashbits = kBitsPerInt32) {
  // Keep in sync with AssemblerBase::FinalizeHash.
  hash += hash << 3;
  hash ^= hash >> 11;  // Logical shift, unsigned hash.
  hash += hash << 15;
  if (hashbits < kBitsPerInt32) {
    hash &= (static_cast<uint32_t>(1) << hashbits) - 1;
  }
  return (hash == 0) ? 1 : hash;
}

inline uint32_t HashBytes(const uint8_t* bytes, intptr_t size) {
  uint32_t hash = size;
  while (size > 0) {
    hash = CombineHashes(hash, *bytes);
    bytes++;
    size--;
  }
  return hash;
}

}  // namespace dart

#endif  // RUNTIME_VM_HASH_H_
