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

#ifndef CACHE_OLD_H
#define CACHE_OLD_H

#include "code-private.h"

__BEGIN_DECLS

extern IMP _cache_getImp(Class cls, SEL sel);
extern Method _cache_getMethod(Class cls, SEL sel, IMP code_msgForward_internal_imp);

extern void flush_cache(Class cls);
extern bool _cache_fill(Class cls, Method meth, SEL sel);
extern void _cache_addForwardEntry(Class cls, SEL sel);
extern IMP  _cache_addIgnoredEntry(Class cls, SEL sel);
extern void _cache_free(Cache cache);
extern void _cache_collect(bool collectALot);

__END_DECLS

#endif
