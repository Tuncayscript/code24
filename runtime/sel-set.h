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

/*
 * code-sel-set.h
 * A set of SELs used for SEL uniquing.
 */

#ifndef SEL_SET_H_
#define SEL_SET_H_

#if !__CODE__

#include <stdint.h>
#include "code-os.h"

__BEGIN_DECLS

struct __code_sel_set;

extern struct __code_sel_set *__code_sel_set_create(size_t selrefCount);
extern SEL __code_sel_set_get(struct __code_sel_set *sset, SEL candidate);
extern void __code_sel_set_add(struct __code_sel_set *sset, SEL value);
            
__END_DECLS

#endif

#endif
