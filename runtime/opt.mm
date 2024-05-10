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
  code-opt.mm
  Management of optimizations in the dyld shared cache 
*/

#include "code-private.h"


#if !SUPPORT_PREOPT
// Preoptimization not supported on this platform.

struct code_selopt_t;

bool isPreoptimized(void) 
{
    return false;
}

bool header_info::isPreoptimized() const
{
    return false;
}

code_selopt_t *preoptimizedSelectors(void) 
{
    return nil;
}

Protocol *getPreoptimizedProtocol(const char *name)
{
    return nil;
}

Class getPreoptimizedClass(const char *name)
{
    return nil;
}

Class* copyPreoptimizedClasses(const char *name, int *outCount)
{
    *outCount = 0;
    return nil;
}

header_info *preoptimizedHinfoForHeader(const headerType *mhdr)
{
    return nil;
}

void preopt_init(void)
{
    disableSharedCacheOptimizations();
    
    if (PrintPreopt) {
        _code_inform("PREOPTIMIZATION: is DISABLED "
                     "(not supported on ths platform)");
    }
}


// !SUPPORT_PREOPT
#else
// SUPPORT_PREOPT

#include <code-shared-cache.h>

using code_opt::code_stringhash_offset_t;
using code_opt::code_protocolopt_t;
using code_opt::code_clsopt_t;
using code_opt::code_headeropt_t;
using code_opt::code_opt_t;

__BEGIN_DECLS

// preopt: the actual opt used at runtime (nil or &_code_opt_data)
// _code_opt_data: opt data possibly written by dyld
// opt is initialized to ~0 to detect incorrect use before preopt_init()

static const code_opt_t *opt = (code_opt_t *)~0;
static bool preoptimized;

extern const code_opt_t _code_opt_data;  // in __TEXT, __code_opt_ro

bool isPreoptimized(void) 
{
    return preoptimized;
}


/***********************************************************************
* Return YES if this image's dyld shared cache optimizations are valid.
**********************************************************************/
bool header_info::isPreoptimized() const
{
    // preoptimization disabled for some reason
    if (!preoptimized) return NO;

    // image not from shared cache, or not fixed inside shared cache
    if (!_codeHeaderOptimizedByDyld(this)) return NO;

    return YES;
}


code_selopt_t *preoptimizedSelectors(void) 
{
    return opt ? opt->selopt() : nil;
}


Protocol *getPreoptimizedProtocol(const char *name)
{
    code_protocolopt_t *protocols = opt ? opt->protocolopt() : nil;
    if (!protocols) return nil;

    return (Protocol *)protocols->getProtocol(name);
}


Class getPreoptimizedClass(const char *name)
{
    code_clsopt_t *classes = opt ? opt->clsopt() : nil;
    if (!classes) return nil;

    void *cls;
    void *hi;
    uint32_t count = classes->getClassAndHeader(name, cls, hi);
    if (count == 1  &&  ((header_info *)hi)->isLoaded()) {
        // exactly one matching class, and its image is loaded
        return (Class)cls;
    } 
    else if (count > 1) {
        // more than one matching class - find one that is loaded
        void *clslist[count];
        void *hilist[count];
        classes->getClassesAndHeaders(name, clslist, hilist);
        for (uint32_t i = 0; i < count; i++) {
            if (((header_info *)hilist[i])->isLoaded()) {
                return (Class)clslist[i];
            }
        }
    }

    // no match that is loaded
    return nil;
}


Class* copyPreoptimizedClasses(const char *name, int *outCount)
{
    *outCount = 0;

    code_clsopt_t *classes = opt ? opt->clsopt() : nil;
    if (!classes) return nil;

    void *cls;
    void *hi;
    uint32_t count = classes->getClassAndHeader(name, cls, hi);
    if (count == 0) return nil;

    Class *result = (Class *)calloc(count, sizeof(Class));
    if (count == 1  &&  ((header_info *)hi)->isLoaded()) {
        // exactly one matching class, and its image is loaded
        result[(*outCount)++] = (Class)cls;
        return result;
    } 
    else if (count > 1) {
        // more than one matching class - find those that are loaded
        void *clslist[count];
        void *hilist[count];
        classes->getClassesAndHeaders(name, clslist, hilist);
        for (uint32_t i = 0; i < count; i++) {
            if (((header_info *)hilist[i])->isLoaded()) {
                result[(*outCount)++] = (Class)clslist[i];
            }
        }

        if (*outCount == 0) {
            // found multiple classes with that name, but none are loaded
            free(result);
            result = nil;
        }
        return result;
    }

    // no match that is loaded
    return nil;
}

namespace code_opt {
struct code_headeropt_t {
    uint32_t count;
    uint32_t entsize;
    header_info headers[0];  // sorted by mhdr address

    header_info *get(const headerType *mhdr) 
    {
        assert(entsize == sizeof(header_info));

        int32_t start = 0;
        int32_t end = count;
        while (start <= end) {
            int32_t i = (start+end)/2;
            header_info *hi = headers+i;
            if (mhdr == hi->mhdr) return hi;
            else if (mhdr < hi->mhdr) end = i-1;
            else start = i+1;
        }

#if DEBUG
        for (uint32_t i = 0; i < count; i++) {
            header_info *hi = headers+i;
            if (mhdr == hi->mhdr) {
                _code_fatal("failed to find header %p (%d/%d)", 
                            mhdr, i, count);
            }
        }
#endif

        return nil;
    }
};
};


header_info *preoptimizedHinfoForHeader(const headerType *mhdr)
{
    code_headeropt_t *hinfos = opt ? opt->headeropt() : nil;
    if (hinfos) return hinfos->get(mhdr);
    else return nil;
}


void preopt_init(void)
{
    // `opt` not set at compile time in order to detect too-early usage
    const char *failure = nil;
    opt = &_code_opt_data;

    if (DisablePreopt) {
        // code_DISABLE_PREOPTIMIZATION is set
        // If opt->version != VERSION then you continue at your own risk.
        failure = "(by code_DISABLE_PREOPTIMIZATION)";
    } 
    else if (opt->version != code_opt::VERSION) {
        // This shouldn't happen. You probably forgot to edit code-sel-table.s.
        // If dyld really did write the wrong optimization version, 
        // then we must halt because we don't know what bits dyld twiddled.
        _code_fatal("bad code preopt version (want %d, got %d)", 
                    code_opt::VERSION, opt->version);
    }
    else if (!opt->selopt()  ||  !opt->headeropt()) {
        // One of the tables is missing. 
        failure = "(dyld shared cache is absent or out of date)";
    }
#if SUPPORT_IGNORED_SELECTOR_CONSTANT
    else if (UseGC) {
        // GC is on, which renames some selectors
        // Non-selector optimizations are still valid, but we don't have
        // any of those yet
        failure = "(GC is on)";
    }
#endif

    if (failure) {
        // All preoptimized selector references are invalid.
        preoptimized = NO;
        opt = nil;
        disableSharedCacheOptimizations();

        if (PrintPreopt) {
            _code_inform("PREOPTIMIZATION: is DISABLED %s", failure);
        }
    }
    else {
        // Valid optimization data written by dyld shared cache
        preoptimized = YES;

        if (PrintPreopt) {
            _code_inform("PREOPTIMIZATION: is ENABLED "
                         "(version %d)", opt->version);
        }
    }
}


__END_DECLS

// SUPPORT_PREOPT
#endif
