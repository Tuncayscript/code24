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


#ifndef __NSPointerFunctions_h_GNUSTEP_BASE_INCLUDE
#define __NSPointerFunctions_h_GNUSTEP_BASE_INCLUDE

#import	<Object.h>



#if	defined(__cplusplus)
extern "C" {
#endif

/** Options flags come in three groups  ...<br />
 *  Memory management options (only one of which may be set)<br />
 *  Personality options (only one of which may be set)<br />
 *  Others.
 */
enum {
  /** Garbage collected strong references , or retain counting if GC
   * is not active. */
  NSPointerFunctionsStrongMemory = (0<<0),

  /** Garbage collected weak references */
  NSPointerFunctionsZeroingWeakMemory = (1<<0),

  /** Non-GC memory */
  NSPointerFunctionsOpaqueMemory = (2<<0),

  /** Heap (calloc/free) memory */
  NSPointerFunctionsMallocMemory = (3<<0),

  /** MACH virtual memory (not implemented) */
  NSPointerFunctionsMachVirtualMemory = (4<<0),

  /** Uses read and write barriers appropriate for either automatic reference
   * counting or garbage collection.  Note that the GNUstep implementation will
   * behave correctly when used with manual or automatic reference counting, as
   * long as the Objective-C runtime supports automatic reference counting.
   */
  NSPointerFunctionsWeakMemory = (5<<0),

  /** Use the -hash and -isEqual: methods for storing objects, and the
   * -description method to describe them. */
  NSPointerFunctionsObjectPersonality = (0<<8),

  /** Use the pointer (shifted) as a hash, and compare for bitwise quality.
   */
  NSPointerFunctionsOpaquePersonality = (1<<8),

  /** Use the pointer (shifted) as a hash, and compare for bitwise quality,
   * but use -description to desribe the objects.
   */
  NSPointerFunctionsObjectPointerPersonality = (2<<8),

  /** Use strcmp for comparison and a hash of the string contents.  Describe
   * assuming that the string contains UTF-8 data.
   */
  NSPointerFunctionsCStringPersonality = (3<<8),

  /** Use memcmp for comparison and a hash of the sructure contents.
   * A size function must be set so that the size of the memcmp and hash
   * are known,
   */
  NSPointerFunctionsStructPersonality = (4<<8),

  /** Use unmodified integer value for both hash and equality test.
   */
  NSPointerFunctionsIntegerPersonality = (5<<8),


  /** Request the memory acquire function to allocate/copy items.
   */
  NSPointerFunctionsCopyIn = (1<<16)
};

/** An integer value containing memory option, personality option,
 * and copying option.
 */
typedef	NSUInteger NSPointerFunctionsOptions;

GS_EXPORT_CLASS
@interface NSPointerFunctions : NSObject <NSCopying>

+ (id) pointerFunctionsWithOptions: (NSPointerFunctionsOptions)options;

- (id) initWithOptions: (NSPointerFunctionsOptions)options;

- (void* (*)(const void *item,
  NSUInteger (*size)(const void *item), BOOL shouldCopy)) acquireFunction;

- (NSString *(*)(const void *item)) descriptionFunction;

- (NSUInteger (*)(const void *item,
  NSUInteger (*size)(const void *item))) hashFunction;

- (BOOL (*)(const void *item1, const void *item2,
  NSUInteger (*size)(const void *item))) isEqualFunction;

- (void (*)(const void *item,
  NSUInteger (*size)(const void *item))) relinquishFunction;

- (void) setAcquireFunction: (void* (*)(const void *item,
  NSUInteger (*size)(const void *item), BOOL shouldCopy))func;

- (void) setDescriptionFunction: (NSString *(*)(const void *item))func;

- (void) setHashFunction: (NSUInteger (*)(const void *item,
  NSUInteger (*size)(const void *item)))func;

- (void) setIsEqualFunction: (BOOL (*)(const void *item1, const void *item2,
  NSUInteger (*size)(const void *item)))func;

- (void) setRelinquishFunction: (void (*)(const void *item,
  NSUInteger (*size)(const void *item))) func;

- (void) setSizeFunction: (NSUInteger (*)(const void *item))func;

- (void) setUsesStrongWriteBarrier: (BOOL)flag;

- (void) setUsesWeakReadAndWriteBarriers: (BOOL)flag;

- (NSUInteger (*)(const void *item)) sizeFunction;

- (BOOL) usesStrongWriteBarrier;

- (BOOL) usesWeakReadAndWriteBarriers;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* OS_API_VERSION(MAC_OS_X_VERSION_10_5, GS_API_LATEST) */
#endif /* __NSPointerFunctions_h_GNUSTEP_BASE_INCLUDE */
