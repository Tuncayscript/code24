/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 12, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef _NSGarbageCollector_h_GNUSTEP_BASE_INCLUDE
#define _NSGarbageCollector_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>



#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif


GS_EXPORT_CLASS
@interface NSGarbageCollector : NSObject 

/** Obsolete ... returns nil because garbage collection no longer exists.
 */
+ (id) defaultCollector;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) collectIfNeeded;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) collectExhaustively;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) disable;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) disableCollectorForPointer: (void *)ptr;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) enable;

/** Obsolete ... does nothing because garbage collection no longer exists.
 */
- (void) enableCollectorForPointer: (void *)ptr;      

/** Obsolete ... returns NO because garbage collection no longer exists.
 */
- (BOOL) isCollecting;

/** Obsolete ... returns NO because garbage collection no longer exists.
 */
- (BOOL) isEnabled;

/** Returns the default zone.
 */
- (NSZone*) zone;
@end

#if	defined(__cplusplus)
}
#endif

#endif
#endif
