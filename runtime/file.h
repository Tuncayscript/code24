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

#ifndef FILE_NEW_H
#define FILE_NEW_H

#if __CODE__

#include "code-runtime-new.h"

// classref_t is not fixed up at launch; use remapClass() to convert

extern SEL *_getcode2SelectorRefs(const header_info *hi, size_t *count);
extern message_ref_t *_getcode2MessageRefs(const header_info *hi, size_t *count);
extern Class*_getcode2ClassRefs(const header_info *hi, size_t *count);
extern Class*_getcode2SuperRefs(const header_info *hi, size_t *count);
extern classref_t *_getcode2ClassList(const header_info *hi, size_t *count);
extern classref_t *_getcode2NonlazyClassList(const header_info *hi, size_t *count);
extern category_t **_getcode2CategoryList(const header_info *hi, size_t *count);
extern category_t **_getcode2NonlazyCategoryList(const header_info *hi, size_t *count);
extern protocol_t **_getcode2ProtocolList(const header_info *hi, size_t *count);
extern protocol_t **_getcode2ProtocolRefs(const header_info *hi, size_t *count);
using Initializer = void(*)(void);
extern Initializer* getLibcodeInitializers(const header_info *hi, size_t *count);

extern classref_t *_getcode2NonlazyClassList(const headerType *mhdr, size_t *count);
extern category_t **_getcode2NonlazyCategoryList(const headerType *mhdr, size_t *count);
extern Initializer* getLibcodeInitializers(const headerType *mhdr, size_t *count);

#endif

#endif
