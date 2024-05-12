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


#ifndef _NSDictionary_h_GNUSTEP_BASE_INCLUDE
#define _NSDictionary_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>
#import <Base/Blocks.h>
#import	<Object.h>
#import	<Enumerator.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class GS_GENERIC_CLASS(NSArray, ElementT);
@class GS_GENERIC_CLASS(NSSet, ElementT);
@class NSString, NSURL;

GS_EXPORT_CLASS
@interface GS_GENERIC_CLASS(NSDictionary,
  __covariant KeyT:id<NSCopying>, __covariant ValT)
  : NSObject <NSCoding, NSCopying, NSMutableCopying, NSFastEnumeration>
+ (instancetype) dictionary;
+ (instancetype) dictionaryWithContentsOfFile: (NSString*)path;

+ (instancetype) dictionaryWithContentsOfURL: (NSURL*)aURL;
#endif
+ (instancetype) dictionaryWithDictionary: (NSDictionary*)otherDictionary;
+ (instancetype) dictionaryWithObject: (GS_GENERIC_TYPE(ValT))object
                               forKey: (GS_GENERIC_TYPE(KeyT))key;
+ (instancetype) dictionaryWithObjects: (GS_GENERIC_CLASS(NSArray,ValT)*)objects
                               forKeys: (GS_GENERIC_CLASS(NSArray,KeyT)*)keys;
+ (instancetype) dictionaryWithObjects: (const GS_GENERIC_TYPE(ValT)[])objects
  forKeys: (const GS_GENERIC_TYPE_F(KeyT,id<NSCopying>)[])keys
  count: (NSUInteger)count;
+ (instancetype) dictionaryWithObjectsAndKeys: (id)firstObject, ...;

- (GS_GENERIC_CLASS(NSArray,KeyT)*) allKeys;
- (GS_GENERIC_CLASS(NSArray,KeyT)*) allKeysForObject:
  (GS_GENERIC_TYPE(ValT))anObject;
- (GS_GENERIC_CLASS(NSArray,ValT)*) allValues;
- (NSUInteger) count;						// Primitive
- (NSString*) description;
- (NSString*) descriptionInStringsFileFormat;
- (NSString*) descriptionWithLocale: (id)locale;
- (NSString*) descriptionWithLocale: (id)locale
			     indent: (NSUInteger)level;


DEFINE_BLOCK_TYPE(GSKeysAndObjectsEnumeratorBlock, void, GS_GENERIC_TYPE_F(KeyT,id<NSCopying>), GS_GENERIC_TYPE(ValT), BOOL*);
- (void) enumerateKeysAndObjectsUsingBlock:
  (GSKeysAndObjectsEnumeratorBlock)aBlock;
- (void) enumerateKeysAndObjectsWithOptions: (NSEnumerationOptions)opts
  usingBlock: (GSKeysAndObjectsEnumeratorBlock)aBlock;
#endif

- (void) getObjects: (__unsafe_unretained GS_GENERIC_TYPE(ValT)[])objects
  andKeys: (__unsafe_unretained GS_GENERIC_TYPE_F(KeyT,id<NSCopying>)[])keys;
- (instancetype) init;
- (instancetype) initWithContentsOfFile: (NSString*)path;


- (instancetype) initWithContentsOfURL: (NSURL*)aURL;
#endif

- (instancetype) initWithDictionary:
    (GS_GENERIC_CLASS(NSDictionary,KeyT, ValT)*)otherDictionary;
- (id) initWithDictionary: (GS_GENERIC_CLASS(NSDictionary,KeyT, ValT)*)other
                copyItems: (BOOL)shouldCopy;
- (id) initWithObjects: (GS_GENERIC_CLASS(NSArray,KeyT)*)objects
               forKeys: (GS_GENERIC_CLASS(NSArray,ValT)*)keys;
- (id) initWithObjectsAndKeys: (GS_GENERIC_TYPE(ValT))firstObject, ...;
- (id) initWithObjects: (const GS_GENERIC_TYPE(ValT)[])objects
	       forKeys: (const GS_GENERIC_TYPE_F(KeyT,id<NSCopying>)[])keys
		 count: (NSUInteger)count; // Primitive
- (BOOL) isEqualToDictionary: (GS_GENERIC_CLASS(NSDictionary,KeyT, ValT)*)other;

- (GS_GENERIC_CLASS(NSEnumerator,KeyT)*) keyEnumerator;	// Primitive


DEFINE_BLOCK_TYPE(GSKeysAndObjectsPredicateBlock, BOOL, GS_GENERIC_TYPE_F(KeyT,id<NSCopying>), GS_GENERIC_TYPE(ValT), BOOL*);
- (GS_GENERIC_CLASS(NSSet,KeyT)*) keysOfEntriesPassingTest:
    (GSKeysAndObjectsPredicateBlock)aPredicate;
- (GS_GENERIC_CLASS(NSSet,KeyT)*) keysOfEntriesWithOptions:
  (NSEnumerationOptions)opts
  passingTest: (GSKeysAndObjectsPredicateBlock)aPredicate;
#endif

- (GS_GENERIC_CLASS(NSArray,ValT)*) keysSortedByValueUsingSelector: (SEL)comp;
- (GS_GENERIC_CLASS(NSArray,ValT)*) keysSortedByValueUsingComparator:(NSComparator)cmptr;
- (GS_GENERIC_CLASS(NSArray,ValT)*) keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;  
- (GS_GENERIC_CLASS(NSEnumerator,ValT)*) objectEnumerator;	// Primitive
- (GS_GENERIC_TYPE(ValT)) objectForKey:
  (GS_GENERIC_TYPE(KeyT))aKey;				// Primitive
- (GS_GENERIC_CLASS(NSArray,ValT)*) objectsForKeys:
  (GS_GENERIC_CLASS(NSArray,KeyT)*)keys
  notFoundMarker: (GS_GENERIC_TYPE(ValT))marker;


- (GS_GENERIC_TYPE(ValT)) valueForKey: (NSString*)key;
#endif

- (BOOL) writeToFile: (NSString*)path atomically: (BOOL)useAuxiliaryFile;


- (BOOL) writeToURL: (NSURL*)url atomically: (BOOL)useAuxiliaryFile;
#endif
/**
 * Method called by array subscripting.
 */
- (GS_GENERIC_TYPE(ValT)) objectForKeyedSubscript:
  (GS_GENERIC_TYPE(KeyT))aKey;
@end

GS_EXPORT_CLASS
@interface  GS_GENERIC_CLASS(NSMutableDictionary, KeyT:id<NSCopying>, ValT) :
  GS_GENERIC_CLASS(NSDictionary, KeyT, ValT)

+ (instancetype) dictionaryWithCapacity: (NSUInteger)numItems;

- (void) addEntriesFromDictionary:
    (GS_GENERIC_CLASS(NSDictionary, KeyT, ValT)*)otherDictionary;
- (instancetype) initWithCapacity: (NSUInteger)numItems;	// Primitive
- (void) removeAllObjects;
/**
 * Removes the object with the specified key from the receiver. This method
 * is primitive.
 */
- (void) removeObjectForKey: (GS_GENERIC_TYPE(KeyT))aKey;
- (void) removeObjectsForKeys: (GS_GENERIC_CLASS(NSArray, KeyT) *)keyArray;
- (void) setObject: (GS_GENERIC_TYPE(ValT))anObject
            forKey: (GS_GENERIC_TYPE(KeyT))aKey; // Primitive
- (void) setDictionary:
    (GS_GENERIC_CLASS(NSDictionary, KeyT, ValT)*)otherDictionary;

- (void) setValue: (GS_GENERIC_TYPE(ValT))value forKey: (NSString*)key;
- (void) takeStoredValue: (GS_GENERIC_TYPE(ValT))value forKey: (NSString*)key;
- (void) takeValue: (GS_GENERIC_TYPE(ValT))value forKey: (NSString*)key;
#endif
/**
 * Method called by array subscripting.
 */
- (void) setObject: (GS_GENERIC_TYPE(ValT))anObject
 forKeyedSubscript: (GS_GENERIC_TYPE(KeyT))aKey;

@end

#if	defined(__cplusplus)
}
#endif

#endif
