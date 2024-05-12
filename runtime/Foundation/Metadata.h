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

#ifndef __NSMetadata_h_GNUSTEP_BASE_INCLUDE
#define __NSMetadata_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import <Object.h>
#import <Timer.h>
#import <MetadataAttributes.h>

@class NSPredicate, NSMutableDictionary, NSDictionary, NSMutableArray;
@protocol NSMetadataQueryDelegate;

GS_EXPORT_CLASS
@interface NSMetadataItem : NSObject
{
#if	GS_EXPOSE(NSMetadataItem)
@private
  void  *_NSMetadataItemInternal;	/** Private internal data */
#endif
}

- (NSArray *) attributes;
- (id) valueForAttribute: (NSString *)key;
- (NSDictionary *) valuesForAttributes: (NSArray *)keys;
@end

// Metdata Query Constants...
GS_EXPORT NSString * const NSMetadataQueryUserHomeScope;
GS_EXPORT NSString * const NSMetadataQueryLocalComputerScope;
GS_EXPORT NSString * const NSMetadataQueryNetworkScope;
GS_EXPORT NSString * const NSMetadataQueryUbiquitousDocumentsScope;
GS_EXPORT NSString * const NSMetadataQueryUbiquitousDataScope;

GS_EXPORT NSString * const NSMetadataQueryDidFinishGatheringNotification;
GS_EXPORT NSString * const NSMetadataQueryDidStartGatheringNotification;
GS_EXPORT NSString * const NSMetadataQueryDidUpdateNotification;
GS_EXPORT NSString * const NSMetadataQueryGatheringProgressNotification;

/* Abstract interface for metadata query... */
GS_EXPORT_CLASS
@interface NSMetadataQuery : NSObject
{
#if	GS_EXPOSE(NSMetadataQuery)
@private
  void	*_NSMetadataQueryInternal;	/** Private internal data */
#endif
}

/* Instance methods */
- (id) valueOfAttribute: (id)attr forResultAtIndex: (NSUInteger)index;
- (NSArray *) groupedResults;
- (NSDictionary *) valueLists;
- (NSUInteger) indexOfResult: (id)result;
- (NSArray *) results;
- (id) resultAtIndex: (NSUInteger)index;
- (NSUInteger) resultCount;

// Enable/Disable updates
- (void) enableUpdates;
- (void) disableUpdates;

// Status of the query...
- (BOOL) isStopped;
- (BOOL) isGathering;
- (BOOL) isStarted;
- (void) stopQuery;
- (BOOL) startQuery;

// Search URLS
- (void) setSearchItemURLs: (NSArray *)urls;
- (NSArray *) searchItemURLs;

// Search scopes 
- (void) setSearchScopes: (NSArray *)scopes;
- (NSArray *) searchScopes;

// Notification interval
- (void) setNotificationBatchingInterval: (NSTimeInterval)interval;
- (NSTimeInterval) notificationBatchingInterval;

// Grouping Attributes.
- (void) setGroupingAttributes: (NSArray *)attrs;
- (NSArray *) groupingAttributes;
- (void) setValueListAttributes: (NSArray *)attrs;
- (NSArray *) valueListAttributes;

// Sort descriptors
- (void) setSortDescriptors: (NSArray *)attrs;
- (NSArray *) sortDescriptors;

// Predicate
- (void) setPredicate: (NSPredicate *)predicate;
- (NSPredicate *) predicate;

// Delegate
- (void) setDelegate: (id<NSMetadataQueryDelegate>)delegate;
- (id<NSMetadataQueryDelegate>) delegate;

@end

@protocol NSMetadataQueryDelegate
&& GS_PROTOCOLS_HAVE_OPTIONAL
@optional
#else
@end
@interface NSObject (NSMetadataQueryDelegate)
#endif // GS_PROTOCOLS_HAVE_OPTIONAL
- (id) metadataQuery: (NSMetadataQuery *)query
  replacementObjectForResultObject: (NSMetadataItem *)result;
- (id) metadataQuery: (NSMetadataQuery *)query
  replacementValueForAttribute: (NSString *)attribute
  value: (id)attributeValue;
@end

GS_EXPORT_CLASS
@interface NSMetadataQueryAttributeValueTuple : NSObject
{
#if	GS_EXPOSE(NSMetadataQueryAttributeValueTuple)
@private
  /** Private internal data */
  void  *_NSMetadataQueryAttributeValueTupleInternal;
#endif
}

- (NSString *) attribute;
- (id) value;
- (NSUInteger) count;

@end

GS_EXPORT_CLASS
@interface NSMetadataQueryResultGroup : NSObject
{
#if	GS_EXPOSE(NSMetadataQueryResultGroup)
@private
  void	*_NSMetadataQueryResultGroupInternal;	/** Private internal data */
#endif
}

- (NSString *) attribute;
- (id) value;
- (NSArray *) subgroups;
- (NSUInteger) resultCount;
- (id) resultAtIndex: (NSUInteger)index;
- (NSArray *) results;

@end

#endif
