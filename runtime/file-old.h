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

#ifndef FILE_OLD_H
#define FILE_OLD_H

#if !__CODE__

#include "code-os.h"

struct code_module;
struct old_protocol;
struct old_class;

__BEGIN_DECLS

extern struct code_module *_getcodeModules(const header_info *hi, size_t *nmodules);
extern SEL *_getcodeSelectorRefs(const header_info *hi, size_t *nmess);
extern struct old_protocol **_getcodeProtocols(const header_info *hi, size_t *nprotos);
extern Class *_getcodeClassRefs(const header_info *hi, size_t *nclasses);
extern const char *_getcodeClassNames(const header_info *hi, size_t *size);

__END_DECLS

#endif

#endif
