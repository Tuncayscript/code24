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


#ifndef __NSDistributedLock_h_GNUSTEP_BASE_INCLUDE
#define __NSDistributedLock_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>

@class	NSDate;
@class	NSLock;
@class	NSString;

#if	defined(__cplusplus)
extern "C" {
#endif

GS_EXPORT_CLASS
@interface NSDistributedLock : NSObject
{
#if	GS_EXPOSE(NSDistributedLock)
  NSString	*_lockPath;
  NSDate	*_lockTime;
  NSLock	*_localLock;
#endif
#if     GS_NONFRAGILE
#else
  /* Pointer to private additional data used to avoid breaking ABI
   * when we don't have the non-fragile ABI available.
   * Use this mechanism rather than changing the instance variable
   * layout (see Source/GSInternal.h for details).
   */
  @private id _internal GS_UNUSED_IVAR;
#endif
}

+ (NSDistributedLock*) lockWithPath: (NSString*)aPath;
- (id) initWithPath: (NSString*)aPath;

- (void) breakLock;
- (NSDate*) lockDate;
- (BOOL) tryLock;
- (void) unlock;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSDistributedLock_h_GNUSTEP_BASE_INCLUDE */
