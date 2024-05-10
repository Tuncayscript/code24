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

#ifndef ACCESSORS_H_
#define ACCESSORS_H_

#include <runtime/code.h>
#include <stddef.h>

__BEGIN_DECLS

#if SUPPORT_GC

extern void code_setProperty_non_gc(id self, SEL _cmd, ptrdiff_t offset, id newValue, BOOL atomic, signed char shouldCopy);
extern id code_getProperty_non_gc(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic);

extern void code_setProperty_gc(id self, SEL _cmd, ptrdiff_t offset, id newValue, BOOL atomic, signed char shouldCopy);
extern id code_getProperty_gc(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic);

#endif

__END_DECLS

#endif
