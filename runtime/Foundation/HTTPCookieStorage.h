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

#ifndef __NSHTTPCookieStorage_h_GNUSTEP_BASE_INCLUDE
#define __NSHTTPCookieStorage_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

&& GS_API_VERSION( 11300,GS_API_LATEST)

#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSArray;
@class NSHTTPCookie;
@class NSURL;

enum {
  NSHTTPCookieAcceptPolicyAlways,
  NSHTTPCookieAcceptPolicyNever,
  NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain
};
/**
 * NSHTTPCookieAcceptPolicyAlways Accept all cookies
 * NSHTTPCookieAcceptPolicyNever Reject all cookies
 * NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain Accept cookies
 * only from the main document domain
 */
typedef NSUInteger NSHTTPCookieAcceptPolicy;

/**
 * Posted to the distributed notification center when the cookie
 * accept policy is changed.
 */
GS_EXPORT NSString * const NSHTTPCookieManagerAcceptPolicyChangedNotification;

/**
 * Posted when the set of cookies changes
 */
GS_EXPORT NSString * const NSHTTPCookieManagerCookiesChangedNotification;


/**
 * The NSHTTPCookieStorage class provides a shared instance which handles
 * the shared cookie store.<br />
 */
GS_EXPORT_CLASS
@interface NSHTTPCookieStorage :  NSObject
{
#if	GS_EXPOSE(NSHTTPCookieStorage)
@private
  void	*_NSHTTPCookieStorageInternal;
#endif
}

/**
 * Returns the shared instance.
 */
+ (NSHTTPCookieStorage *) sharedHTTPCookieStorage;

/**
 * Returns the current cookie accept policy.
 */
- (NSHTTPCookieAcceptPolicy) cookieAcceptPolicy;

/**
 * Returns an array of all managed cookies.
 */
- (NSArray *) cookies;

/**
 *  Returns an array of all known cookies to send to URL.
 */
- (NSArray *) cookiesForURL: (NSURL *)URL;

/**
 * Deletes cookie from the shared store.
 */
- (void) deleteCookie: (NSHTTPCookie *)cookie;

/**
 * Sets a cookie in the store, replacing any existing cookie with the
 * same name, domain and path.
 */
- (void) setCookie: (NSHTTPCookie *)cookie;

/**
 * Sets the current cookie accept policy.
 */
- (void) setCookieAcceptPolicy: (NSHTTPCookieAcceptPolicy)cookieAcceptPolicy;

/**
 * Adds to the shared store following the policy for
 * NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain
 */
- (void) setCookies: (NSArray *)cookies
	     forURL: (NSURL *)URL
    mainDocumentURL: (NSURL *)mainDocumentURL;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* 100200 */

#endif	/* __NSHTTPCookieStorage_h_GNUSTEP_BASE_INCLUDE */
