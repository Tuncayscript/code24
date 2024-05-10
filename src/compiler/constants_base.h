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

#ifndef RUNTIME_VM_CONSTANTS_BASE_H_
#define RUNTIME_VM_CONSTANTS_BASE_H_

namespace Code {

// Alignment strategies for how to align values.
enum AlignmentStrategy {
  // Align to the size of the value.
  kAlignedToValueSize,
  // Align to the size of the value, but align 8 byte-sized values to 4 bytes.
  // Both double and int64.
  kAlignedToValueSizeBut8AlignedTo4,
  // Align to the architecture size.
  kAlignedToWordSize,
  // Align to the greater of architecture size or value size.
  kAlignedToWordSizeAndValueSize,
};

// Minimum size strategies for how to store values.
enum ExtensionStrategy {
  // Values can have arbitrary small size with the upper bits undefined.
  kNotExtended,
  // Values smaller than 4 bytes are passed around zero- or sign-extended to
  // 4 bytes.
  kExtendedTo4,
  // Values smaller than 8 bytes are passed around zero- or sign-extended to
  // 8 bytes.
  kExtendedTo8,
};

}  // namespace dart

#endif  // RUNTIME_VM_CONSTANTS_BASE_H_
