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

#ifndef __NSKeyValueObserving_h_GNUSTEP_BASE_INCLUDE
#define __NSKeyValueObserving_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>
#import	<Foundation/Array.h>
#import	<Foundation/Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSIndexSet;
@class NSSet;
@class NSString;

enum {
  NSKeyValueObservingOptionNew = 1,
  NSKeyValueObservingOptionOld = 2

,  NSKeyValueObservingOptionInitial = 4,
  NSKeyValueObservingOptionPrior = 8
#endif
};
typedef UInteger NSKeyValueObservingOptions;

enum {
  NSKeyValueChangeSetting = 1,
  NSKeyValueChangeInsertion = 2,
  NSKeyValueChangeRemoval = 3,
  NSKeyValueChangeReplacement = 4
};
typedef UInteger NSKeyValueChange;

enum {
  NSKeyValueUnionSetMutation = 1,
  NSKeyValueMinusSetMutation = 2,
  NSKeyValueIntersectSetMutation = 3,
  NSKeyValueSetSetMutation = 4
};
typedef UInteger NSKeyValueSetMutationKind;

GS_EXPORT String *const NSKeyValueChangeIndexesKey;
GS_EXPORT String *const NSKeyValueChangeKindKey;
GS_EXPORT String *const NSKeyValueChangeNewKey;
GS_EXPORT String *const NSKeyValueChangeOldKey;
GS_EXPORT String *const NSKeyValueChangeNotificationIsPriorKey;

/* Given that the receiver has been registered as an observer
 * of the value at a key path relative to an object,
 * be notified that the value has changed.
 * The change dictionary always contains an NSKeyValueChangeKindKey entry
 * whose value is an NSNumber wrapping an NSKeyValueChange
 * (use [NSNumber-intValue]). The meaning of NSKeyValueChange
 * depends on what sort of property is identified by the key path:
 *
 * For any sort of property (attribute, to-one relationship,
 * or ordered or unordered to-many relationship) NSKeyValueChangeSetting
 * indicates that the observed object has received a -setValue:forKey:
 * message, or that the key-value coding-compliant set method for the
 * key has been invoked, or that a -willChangeValueForKey: or
 * -didChangeValueForKey: pair has otherwise been invoked.
 *
 * For an _ordered_ to-many relationship, NSKeyValueChangeInsertion,
 * NSKeyValueChangeRemoval, and NSKeyValueChangeReplacement indicate
 * that a mutating message has been sent to the array returned by
 * a -mutableArrayValueForKey: message sent to the object, or that
 * one of the key-value coding-compliant array mutation methods for
 * the key has been invoked, or that a -willChange:valuesAtIndexes:forKey:
 * or -didChange:valuesAtIndexes:forKey: pair has otherwise been invoked.
 *
 * For an _unordered_ to-many relationship (introduced in Mac OS 10.4),
 * NSKeyValueChangeInsertion, NSKeyValueChangeRemoval,
 * and NSKeyValueChangeReplacement indicate that a mutating
 * message has been sent to the set returned by a -mutableSetValueForKey:
 * message sent to the object, or that one of the key-value
 * coding-compliant set mutation methods for the key has been invoked,
 * or that a -willChangeValueForKey:withSetMutation:usingObjects:
 * or -didChangeValueForKey:withSetMutation:usingObjects: pair has
 * otherwise been invoked.
 *
 * For any sort of property, the change dictionary always contains
 * an NSKeyValueChangeNewKey entry if NSKeyValueObservingOptionNew
 * was specified at observer-registration time, likewise for
 * NSKeyValueChangeOldKey if NSKeyValueObservingOptionOld was specified.
 * See the comments for the NSKeyValueObserverNotification informal
 * protocol methods for what the values of those entries will be.
 * For an _ordered_ to-many relationship, the change dictionary
 * always contains an NSKeyValueChangeIndexesKey entry whose value
 * is an NSIndexSet containing the indexes of the inserted, removed,
 * or replaced objects, unless the change is an NSKeyValueChangeSetting.
 * context is always the same pointer that was passed in at
 * observer-registration time.
 */

@interface NSObject (NSKeyValueObserving)
- (void) observeValueForKeyPath: (NSString*)aPath
		       ofObject: (id)anObject
			 change: (NSDictionary*)aChange
		        context: (void*)aContext;

@end

@interface NSObject (NSKeyValueObserverRegistration)

- (void) addObserver: (NSObject*)anObserver
	  forKeyPath: (NSString*)aPath
	     options: (NSKeyValueObservingOptions)options
	     context: (void*)aContext;

- (void) removeObserver: (NSObject*)anObserver
	     forKeyPath: (NSString*)aPath;


- (void) removeObserver: (NSObject*)anObserver
             forKeyPath: (NSString*)aPath
                context: (void *)context;
#endif
@end

@interface NSArray (NSKeyValueObserverRegistration)

- (void) addObserver: (NSObject*)anObserver
  toObjectsAtIndexes: (NSIndexSet*)indexes
	  forKeyPath: (NSString*)aPath
	     options: (NSKeyValueObservingOptions)options
	     context: (void*)aContext;

- (void) removeObserver: (NSObject*)anObserver
   fromObjectsAtIndexes: (NSIndexSet*)indexes
	     forKeyPath: (NSString*)aPath;


- (void) removeObserver: (NSObject*)anObserver
   fromObjectsAtIndexes: (NSIndexSet *)indexes
             forKeyPath: (NSString*)aPath
                context: (void *)context;
#endif
@end

/**
 * These methods are sent to the receiver when observing it active
 * for a key and the key is about to be (or has just been) changed.
 */
@interface NSObject (NSKeyValueObserverNotification)

/** <override-dummy />
 */
- (void) didChangeValueForKey: (NSString*)aKey;

/** <override-dummy />
 */
- (void) didChange: (NSKeyValueChange)changeKind
   valuesAtIndexes: (NSIndexSet*)indexes
	    forKey: (NSString*)aKey;

/** <override-dummy />
 */
- (void) willChangeValueForKey: (NSString*)aKey;

/** <override-dummy />
 */
- (void) willChange: (NSKeyValueChange)changeKind
    valuesAtIndexes: (NSIndexSet*)indexes
	     forKey: (NSString*)aKey;



/** <override-dummy />
 */
- (void) didChangeValueForKey: (NSString*)aKey
	      withSetMutation: (NSKeyValueSetMutationKind)mutationKind
		 usingObjects: (NSSet*)objects;

/** <override-dummy />
 */
- (void) willChangeValueForKey: (NSString*)aKey
	       withSetMutation: (NSKeyValueSetMutationKind)mutationKind
		  usingObjects: (NSSet*)objects;

#endif

@end

/**
 * These methods permit modifications to the observing system.
 */
@interface NSObject(NSKeyValueObservingCustomization)
/**
 * Specifies whether the class should send the notification methods of
 * the NSKeyValueObserverNotification protocol when instances of the
 * class receive messages to change the value for the key.<br />
 * The default implementation returns YES.
 */
+ (BOOL) automaticallyNotifiesObserversForKey: (NSString*)aKey;

/**
 * Tells the observing system that when NSKeyValueObserverNotification
 * protocol messages are sent for any key in the triggerKeys array,
 * they should also be sent for dependentKey.
 */
+ (void) setKeys: (NSArray*)triggerKeys
triggerChangeNotificationsForDependentKey: (NSString*)dependentKey;



/**
 * Returns a set of key paths for properties whose values affect the value
 * of the specified dependentKey.
 */
+ (NSSet*) keyPathsForValuesAffectingValueForKey: (NSString*)dependentKey;
#endif

/**
 * Returns a reference to the observation information for the receiver
 * as stored using the -setObservationInfo: method.<br />
 * The default implementation returns information from a global table.
 */
- (void*) observationInfo;

/**
 * Stores observation information for the receiver.  By default this is
 * done in a global table, but classes may implement storage in an instance
 * variable or some other scheme (for improved performance).
 */
- (void) setObservationInfo: (void*)observationInfo;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* 100300 */

#endif	/* __NSKeyValueObserving_h_GNUSTEP_BASE_INCLUDE */

