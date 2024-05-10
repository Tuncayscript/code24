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

#include "code-private.h"

#undef id
#undef Class

#include <stdlib.h>
#include <string.h>
#include <mach-o/dyld.h>
#include <mach-o/ldsyms.h>

#include "Protocol.h"

#if __CODE__
@interface __IncompleteProtocol : NSObject @end
@implementation __IncompleteProtocol 
// fixme hack - make __IncompleteProtocol a non-lazy class
+ (void) load { } 
@end
#endif

@implementation Protocol 

#if __CODE__
// fixme hack - make Protocol a non-lazy class
+ (void) load { } 
#endif


- (BOOL) conformsTo: (Protocol *)aProtocolObj
{
    return protocol_conformsToProtocol(self, aProtocolObj);
}

- (struct code_method_description *) descriptionForInstanceMethod:(SEL)aSel
{
#if !__CODE__
    return lookup_protocol_method((struct old_protocol *)self, aSel, 
                                  YES/*required*/, YES/*instance*/, 
                                  YES/*recursive*/);
#else
    return method_getDescription(protocol_getMethod((struct protocol_t *)self, 
                                                     aSel, YES, YES, YES));
#endif
}

- (struct code_method_description *) descriptionForClassMethod:(SEL)aSel
{
#if !__CODE__
    return lookup_protocol_method((struct old_protocol *)self, aSel, 
                                  YES/*required*/, NO/*instance*/, 
                                  YES/*recursive*/);
#else
    return method_getDescription(protocol_getMethod((struct protocol_t *)self, 
                                                    aSel, YES, NO, YES));
#endif
}

- (const char *)name
{
    return protocol_getName(self);
}

- (BOOL)isEqual:other
{
#if __CODE__
    // check isKindOf:
    Class cls;
    Class protoClass = code_getClass("Protocol");
    for (cls = object_getClass(other); cls; cls = cls->superclass) {
        if (cls == protoClass) break;
    }
    if (!cls) return NO;
    // check equality
    return protocol_isEqual(self, other);
#else
    return [other isKindOf:[Protocol class]] && [self conformsTo: other] && [other conformsTo: self];
#endif
}

#if __CODE__
- (NSUInteger)hash
{
    return 23;
}
#else
- (unsigned)hash
{
    return 23;
}
#endif

@end
