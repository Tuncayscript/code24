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

#include "jl_exported_funcs.inc"
#include "trampolines/common.h"
#define XX(x) --strip-symbol=CNAME(x)
LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
#undef XX
