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
#if __CODE__

#include "code-private.h"
#include "code-file.h"

// Segment and section names are 16 bytes and may be un-terminated.
bool segnameEquals(const char *lhs, const char *rhs) {
    return 0 == strncmp(lhs, rhs, 16);
}

bool segnameStartsWith(const char *segname, const char *prefix) {
    return 0 == strncmp(segname, prefix, strlen(prefix));
}

bool sectnameEquals(const char *lhs, const char *rhs) {
    return segnameEquals(lhs, rhs);
}

bool sectnameStartsWith(const char *sectname, const char *prefix) {
    return segnameStartsWith(sectname, prefix);
}


// Look for a __DATA or __DATA_CONST or __DATA_DIRTY section 
// with the given name that stores an array of T.
template <typename T>
T* getDataSection(const headerType *mhdr, const char *sectname, 
                  size_t *outBytes, size_t *outCount)
{
    unsigned long byteCount = 0;
    T* data = (T*)getsectiondata(mhdr, "__DATA", sectname, &byteCount);
    if (!data) {
        data = (T*)getsectiondata(mhdr, "__DATA_CONST", sectname, &byteCount);
    }
    if (!data) {
        data = (T*)getsectiondata(mhdr, "__DATA_DIRTY", sectname, &byteCount);
    }
    if (outBytes) *outBytes = byteCount;
    if (outCount) *outCount = byteCount / sizeof(T);
    return data;
}

#define GETSECT(name, type, sectname)                                   \
    type *name(const headerType *mhdr, size_t *outCount) {              \
        return getDataSection<type>(mhdr, sectname, nil, outCount);     \
    }                                                                   \
    type *name(const header_info *hi, size_t *outCount) {               \
        return getDataSection<type>(hi->mhdr, sectname, nil, outCount); \
    }

//      function name                 content type     section name
GETSECT(_getcode2SelectorRefs,        SEL,             "__code_selrefs"); 
GETSECT(_getcode2MessageRefs,         message_ref_t,   "__code_msgrefs"); 
GETSECT(_getcode2ClassRefs,           Class,           "__code_classrefs");
GETSECT(_getcode2SuperRefs,           Class,           "__code_superrefs");
GETSECT(_getcode2ClassList,           classref_t,      "__code_classlist");
GETSECT(_getcode2NonlazyClassList,    classref_t,      "__code_nlclslist");
GETSECT(_getcode2CategoryList,        category_t *,    "__code_catlist");
GETSECT(_getcode2NonlazyCategoryList, category_t *,    "__code_nlcatlist");
GETSECT(_getcode2ProtocolList,        protocol_t *,    "__code_protolist");
GETSECT(_getcode2ProtocolRefs,        protocol_t *,    "__code_protorefs");
GETSECT(getLibcodeInitializers,       Initializer,   "__code_init_func");


code_image_info *
_getcodeImageInfo(const headerType *mhdr, size_t *outBytes)
{
    return getDataSection<code_image_info>(mhdr, "__code_imageinfo", 
                                           outBytes, nil);
}


static const segmentType *
getsegbynamefromheader(const headerType *mhdr, const char *segname)
{
    const segmentType *seg = (const segmentType *) (mhdr + 1);
    for (unsigned long i = 0; i < mhdr->ncmds; i++){
        if (seg->cmd == SEGMENT_CMD  &&  segnameEquals(seg->segname, segname)) {
            return seg;
        }
        seg = (const segmentType *)((char *)seg + seg->cmdsize);
    }
    return nil;
}

// Look for an __code* section other than __code_imageinfo
static bool segmentHascodeContents(const segmentType *seg)
{
    if (seg) {
        for (uint32_t i = 0; i < seg->nsects; i++) {
            const sectionType *sect = ((const sectionType *)(seg+1))+i;
            if (sectnameStartsWith(sect->sectname, "__code_")  &&  
                !sectnameEquals(sect->sectname, "__code_imageinfo")) 
            {
                return true;
            }
        }
    }

    return false;
}

// Look for an __code* section other than __code_imageinfo
bool
_hascodeContents(const header_info *hi)
{
    const segmentType *data = 
        getsegbynamefromheader(hi->mhdr, "__DATA");
    const segmentType *data_const = 
        getsegbynamefromheader(hi->mhdr, "__DATA_CONST");
    const segmentType *data_dirty = 
        getsegbynamefromheader(hi->mhdr, "__DATA_CONST");
    
    return segmentHascodeContents(data) 
        || segmentHascodeContents(data_const) 
        || segmentHascodeContents(data_dirty);
}

#endif
