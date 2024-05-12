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


#ifndef __NSMethodSignature_h_GNUSTEP_BASE_INCLUDE
#define __NSMethodSignature_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

/**
 * <p>Class encapsulating type information for method arguments and return
 * value.  It is used as a component of [NSInvocation] to implement message
 * forwarding, such as within the distributed objects framework.  Instances
 * can be obtained from the [NSObject] method
 * [NSObject-methodSignatureForSelector:].</p>
 *
 * <p>Basically, types are represented as Objective-C <code>@encode(...)</code>
 * compatible strings.  The arguments are
 * numbered starting from 0, including the implicit arguments
 * <code><em>self</em></code> (type <code>id</code>, at position 0) and
 * <code><em>_cmd</em></code> (type <code>SEL</code>, at position 1).</p>
 */
GS_EXPORT_CLASS
@interface NSMethodSignature : NSObject
{
#if	GS_EXPOSE(NSMethodSignature)
@private
  const char		*_methodTypes;
  NSUInteger		_argFrameLength;
  NSUInteger		_numArgs;
  void			*_info;
#endif
}

/**
 * Build a method signature directly from string description of return type and
 * argument types, using the Objective-C <code>@encode(...)</code> type codes.
 */
+ (NSMethodSignature*) signatureWithObjCTypes: (const char*)t;

/**
 * Number of bytes that the full set of arguments occupies on the stack, which
 * is platform(hardware)-dependent.
 */
- (NSUInteger) frameLength;

/**
 * Returns Objective-C <code>@encode(...)</code> compatible string.  Arguments
 * are numbered starting from 0, including the implicit arguments
 * <code><em>self</em></code> (type <code>id</code>, at position 0) and
 * <code><em>_cmd</em></code> (type <code>SEL</code>, at position 1).<br />
 * Type strings may include leading type qualifiers.
 */
- (const char*) getArgumentTypeAtIndex: (NSUInteger)index;

/**
 * Pertains to distributed objects; method is asynchronous when invoked and
 * return should not be waited for.
 */
- (BOOL) isOneway;

/**
 * Number of bytes that the return value occupies on the stack, which is
 * platform(hardware)-dependent.
 */
- (NSUInteger) methodReturnLength;

/**
 * Returns an Objective-C <code>@encode(...)</code> compatible string
 * describing the return type of the method.  This may include type
 * qualifiers.
 */
- (const char*) methodReturnType;

/**
 * Returns number of arguments to method, including the implicit
 * <code><em>self</em></code> and <code><em>_cmd</em></code>.
 */
- (NSUInteger) numberOfArguments;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSMethodSignature_h_GNUSTEP_BASE_INCLUDE */
