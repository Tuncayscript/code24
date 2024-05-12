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

#ifndef __NSAffineTransform_h_GNUSTEP_BASE_INCLUDE
#define __NSAffineTransform_h_GNUSTEP_BASE_INCLUDE
#import <Base/VersionMacros.h>

#import <Object.h>
#import <Geometry.h>

typedef	struct {
  CGFloat	m11;
  CGFloat	m12;
  CGFloat	m21;
  CGFloat	m22;
  CGFloat	tX;
  CGFloat	tY;
} NSAffineTransformStruct;

GS_EXPORT_CLASS
@interface NSAffineTransform : NSObject <NSCopying, NSCoding>
{
#if GS_EXPOSE(NSAffineTransform)
@private
  NSAffineTransformStruct	_matrix;
  BOOL _isIdentity;	// special case: A=D=1 and B=C=0
  BOOL _isFlipY;	// special case: A=1 D=-1 and B=C=0
  BOOL _pad1 GS_UNUSED_IVAR;
  BOOL _pad2 GS_UNUSED_IVAR;
#endif
}

+ (NSAffineTransform*) transform;
- (void) appendTransform: (NSAffineTransform*)aTransform;
- (id) initWithTransform: (NSAffineTransform*)aTransform;
- (void) invert;
- (void) prependTransform: (NSAffineTransform*)aTransform;
- (void) rotateByDegrees: (CGFloat)angle;
- (void) rotateByRadians: (CGFloat)angleRad;
- (void) scaleBy: (CGFloat)scale;
- (void) scaleXBy: (CGFloat)scaleX yBy: (CGFloat)scaleY;
- (void) setTransformStruct: (NSAffineTransformStruct)val;
- (NSPoint) transformPoint: (NSPoint)aPoint;
- (NSSize) transformSize: (NSSize)aSize;
- (NSAffineTransformStruct) transformStruct;
- (void) translateXBy: (CGFloat)tranX yBy: (CGFloat)tranY;
@end

#endif /* __NSAffineTransform_h_GNUSTEP_BASE_INCLUDE */
