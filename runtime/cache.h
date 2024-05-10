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

#ifndef CACHE_H
#define CACHE_H

#include "code-private.h"

__BEGIN_DECLS

extern IMP cache_getImp(Class cls, SEL sel);

extern void cache_fill(Class cls, SEL sel, IMP imp, id receiver);

extern void cache_erase_nolock(Class cls);

extern void cache_delete(Class cls);

extern void cache_collect(bool collectALot);

__END_DECLS

#endif
