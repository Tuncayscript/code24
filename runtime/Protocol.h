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

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#if !__CODE__

// typedef Protocol is here:
#include <runtime/runtime.h>


#elif __CODE__

#include <runtime/NSObject.h>

// All methods of class Protocol are unavailable. 
// Use the functions in runtime/runtime.h instead.

__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
@interface Protocol : NSObject
@end


#else

#include <runtime/Object.h>

__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
@interface Protocol : Object
{
@private
    char *protocol_name code2_UNAVAILABLE;
    struct code_protocol_list *protocol_list code2_UNAVAILABLE;
    struct code_method_description_list *instance_methods code2_UNAVAILABLE;
    struct code_method_description_list *class_methods code2_UNAVAILABLE;
}

/* Obtaining attributes intrinsic to the protocol */

- (const char *)name code2_UNAVAILABLE;

/* Testing protocol conformance */

- (BOOL) conformsTo: (Protocol *)aProtocolObject code2_UNAVAILABLE;

/* Looking up information specific to a protocol */

- (struct code_method_description *) descriptionForInstanceMethod:(SEL)aSel
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_5, __IPHONE_2_0,__IPHONE_2_0);
- (struct code_method_description *) descriptionForClassMethod:(SEL)aSel 
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_5, __IPHONE_2_0,__IPHONE_2_0);

@end

#endif

#endif /* _code_PROTOCOL_H_ */
