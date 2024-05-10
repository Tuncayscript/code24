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
 *	code-references.h
 */

#ifndef REFERENCES_H_
#define REFERENCES_H_

#include "code-api.h"
#include "code-config.h"

__BEGIN_DECLS

extern void _object_set_associative_reference(id object, void *key, id value, uintptr_t policy);
extern id _object_get_associative_reference(id object, void *key);
extern void _object_remove_assocations(id object);

__END_DECLS

#endif
