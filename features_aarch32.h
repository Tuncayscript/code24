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
 */

// Copy values `from arch/arm/include/uapi/asm/hwcap.h` from linux kernel source tree
// and match LLVM names.

// LLVM features in `llvm/lib/Target/ARM/ARM.td`

// AArch32 features definition
// hwcap
LANGUAGE_FEATURE_DEF(neon, 12, 0)
LANGUAGE_FEATURE_DEF(vfp3, 13, 0)
// LANGUAGE_FEATURE_DEF(vfpv3d16, 14, 0) // -d32
LANGUAGE_FEATURE_DEF(vfp4, 16, 0)
LANGUAGE_FEATURE_DEF_NAME(hwdiv_arm, 17, 0, "hwdiv-arm")
LANGUAGE_FEATURE_DEF(hwdiv, 18, 0)
LANGUAGE_FEATURE_DEF(d32, 19, 0)

// hwcap2
LANGUAGE_FEATURE_DEF(crypto, 32 + 0, 0)
LANGUAGE_FEATURE_DEF(crc, 32 + 4, 0)
// LANGUAGE_FEATURE_DEF(ras, 32 + ???, 0)
// LANGUAGE_FEATURE_DEF(fullfp16, 32 + ???, 0)

// custom bits to match llvm model
LANGUAGE_FEATURE_DEF(aclass, 32 * 2 + 0, 0)
LANGUAGE_FEATURE_DEF(rclass, 32 * 2 + 1, 0)
LANGUAGE_FEATURE_DEF(mclass, 32 * 2 + 2, 0)
LANGUAGE_FEATURE_DEF(v7, 32 * 2 + 3, 0)
LANGUAGE_FEATURE_DEF(v8, 32 * 2 + 4, 0)
LANGUAGE_FEATURE_DEF(v8_1a, 32 * 2 + 5, 0)
LANGUAGE_FEATURE_DEF(v8_2a, 32 * 2 + 6, 0)
LANGUAGE_FEATURE_DEF(v8_3a, 32 * 2 + 7, 0)
LANGUAGE_FEATURE_DEF(v8_m_main, 32 * 2 + 8, 0)
LANGUAGE_FEATURE_DEF(v8_4a, 32 * 2 + 9, 0)
LANGUAGE_FEATURE_DEF(v8_5a, 32 * 2 + 10, 0)
LANGUAGE_FEATURE_DEF(v8_6a, 32 * 2 + 11, 110000)
