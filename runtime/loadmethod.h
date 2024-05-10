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

/***********************************************************************
* code-loadmethod.h
* Support for +load methods.
**********************************************************************/

#ifndef LOADMETHOD_H
#define LOADMETHOD_H

#include "code-private.h"

__BEGIN_DECLS

extern void add_class_to_loadable_list(Class cls);
extern void add_category_to_loadable_list(Category cat);
extern void remove_class_from_loadable_list(Class cls);
extern void remove_category_from_loadable_list(Category cat);

extern void call_load_methods(void);

__END_DECLS

#endif
