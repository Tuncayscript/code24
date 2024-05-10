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
 */// Copyright 1988-1996 NeXT Software, Inc.

#if !__CODE__

#include "code-private.h"
#include "code-runtime-old.h"
#include "code-file-old.h"

#if TARGET_OS_WIN32

/*
Module 
_getcodeModules(const header_info *hi, size_t *nmodules)
{
    if (nmodules) *nmodules = hi->moduleCount;
    return hi->modules;
}
*/
SEL *
_getcodeSelectorRefs(const header_info *hi, size_t *nmess)
{
    if (nmess) *nmess = hi->selrefCount;
    return hi->selrefs;
}

struct old_protocol **
_getcodeProtocols(const header_info *hi, size_t *nprotos)
{
    if (nprotos) *nprotos = hi->protocolCount;
    return hi->protocols;
}

Class*
_getcodeClassRefs(const header_info *hi, size_t *nclasses)
{
    if (nclasses) *nclasses = hi->clsrefCount;
    return (Class*)hi->clsrefs;
}

// __code,__class_names section only emitted by CodeWarrior  rdar://4951638
const char *
_getcodeClassNames(const header_info *hi, size_t *size)
{
    if (size) *size = 0;
    return NULL;
}

#else

#define GETSECT(name, type, sectname)                                   \
    type *name(const header_info *hi, size_t *outCount)  \
    {                                                                   \
        unsigned long byteCount = 0;                                    \
        type *data = (type *)                                           \
            getsectiondata(hi->mhdr, SEG_code, sectname, &byteCount);   \
        *outCount = byteCount / sizeof(type);                           \
        return data;                                                    \
    }

GETSECT(_getcodeModules,      struct code_module, "__module_info");
GETSECT(_getcodeSelectorRefs, SEL,                "__message_refs");
GETSECT(_getcodeClassRefs,    Class, "__cls_refs");
GETSECT(_getcodeClassNames,   const char,         "__class_names");
// __code,__class_names section only emitted by CodeWarrior  rdar://4951638


code_image_info *
_getcodeImageInfo(const headerType *mhdr, size_t *outBytes)
{
    unsigned long byteCount = 0;
    code_image_info *info = (code_image_info *)
        getsectiondata(mhdr, SEG_code, "__image_info", &byteCount);
    *outBytes = byteCount;
    return info;
}


struct old_protocol **
_getcodeProtocols(const header_info *hi, size_t *nprotos)
{
    unsigned long size = 0;
    struct old_protocol *protos = (struct old_protocol *)
        getsectiondata(hi->mhdr, SEG_code, "__protocol", &size);
    *nprotos = size / sizeof(struct old_protocol);
    
    if (!hi->proto_refs  &&  *nprotos) {
        size_t i;
        header_info *whi = (header_info *)hi;
        whi->proto_refs = (struct old_protocol **)
            malloc(*nprotos * sizeof(*hi->proto_refs));
        for (i = 0; i < *nprotos; i++) {
            hi->proto_refs[i] = protos+i;
        }
    }
    
    return hi->proto_refs;
}


static const segmentType *
getsegbynamefromheader(const headerType *head, const char *segname)
{
    const segmentType *sgp;
    unsigned long i;
    
    sgp = (const segmentType *) (head + 1);
    for (i = 0; i < head->ncmds; i++){
        if (sgp->cmd == SEGMENT_CMD) {
            if (strncmp(sgp->segname, segname, sizeof(sgp->segname)) == 0) {
                return sgp;
            }
        }
        sgp = (const segmentType *)((char *)sgp + sgp->cmdsize);
    }
    return NULL;
}

bool
_hascodeContents(const header_info *hi)
{
    // Look for an __code,* section other than __code,__image_info
    const segmentType *seg = getsegbynamefromheader(hi->mhdr, "__code");
    const sectionType *sect;
    uint32_t i;
    for (i = 0; i < seg->nsects; i++) {
        sect = ((const sectionType *)(seg+1))+i;
        if (0 != strncmp(sect->sectname, "__image_info", 12)) {
            return YES;
        }
    }

    return NO;
}


#endif

#endif
