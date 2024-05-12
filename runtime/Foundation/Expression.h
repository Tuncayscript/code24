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


#ifndef __NSExpression_h_GNUSTEP_BASE_INCLUDE
#define __NSExpression_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#if	OS_API_VERSION(MAC_OS_X_VERSION_10_4, GS_API_LATEST)

#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSArray;
@class NSMutableDictionary;
@class NSString;

enum
{
  NSConstantValueExpressionType=0,
  NSEvaluatedObjectExpressionType,
  NSVariableExpressionType,
  NSKeyPathExpressionType,
  NSFunctionExpressionType,
  NSKeyPathCompositionExpressionType
};
typedef NSUInteger NSExpressionType;

GS_EXPORT_CLASS
@interface NSExpression : NSObject <NSCoding, NSCopying>
{
#if	GS_EXPOSE(NSExpression)
  NSExpressionType _type;
#endif
}

+ (NSExpression *) expressionForConstantValue: (id)obj;
+ (NSExpression *) expressionForEvaluatedObject;
+ (NSExpression *) expressionForFunction: (NSString *)name
			       arguments: (NSArray *)args;
+ (NSExpression *) expressionForKeyPath: (NSString *)path;
+ (NSExpression *) expressionForVariable: (NSString *)string;

- (NSArray *) arguments;
- (id) constantValue;
- (NSExpressionType) expressionType;
- (id) expressionValueWithObject: (id)object
			 context: (NSMutableDictionary *)context;
- (NSString *) function;
- (id) initWithExpressionType: (NSExpressionType) type;
- (NSString *) keyPath;
- (NSExpression *) operand;
- (NSString *) variable;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* 100400 */

#endif /* __NSExpression_h_GNUSTEP_BASE_INCLUDE */

