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


#ifndef __NSFileVersion_h_GNUSTEP_BASE_INCLUDE
#define __NSFileVersion_h_GNUSTEP_BASE_INCLUDE

#import <Object.h>

@class NSArray, NSDate, NSDictionary, NSError, NSString, NSURL, NSPersonNameComponents;



enum {
    NSFileVersionReplacingByMoving = 1 << 0
};
typedef NSUInteger NSFileVersionReplacingOptions;

enum {
    NSFileVersionAddingByMoving = 1 << 0
};
typedef NSUInteger NSFileVersionAddingOptions;

GS_EXPORT_CLASS
@interface NSFileVersion : NSObject
{
@private
    NSURL *_fileURL;
    NSURL *_contentsURL;
    id _persistentIdentifier;
    id _nonLocalVersion;
    BOOL _isResolved;
    BOOL _isDiscardable;
    BOOL _hasThumbnail;
    BOOL _hasLocalContents;
    BOOL _conflict;
    NSString *_localizedName;
    NSString *_localizedNameOfSavingComputer;
    NSDate *_modificationDate;
}

// Initializers
+ (NSFileVersion *)currentVersionOfItemAtURL: (NSURL *)url;
+ (NSArray *)otherVersionsOfItemAtURL: (NSURL *)url;
+ (NSFileVersion *)versionOfItemAtURL: (NSURL *)url 
              forPersistentIdentifier: (id)persistentIdentifier;
+ (NSURL *)temporaryDirectoryURLForNewVersionOfItemAtURL: (NSURL *)url;
+ (NSFileVersion *)addVersionOfItemAtURL: (NSURL *)url 
                       withContentsOfURL: (NSURL *)contentsURL 
                                 options: (NSFileVersionAddingOptions)options 
                                   error: (NSError **)outError;
+ (NSArray *)unresolvedConflictVersionsOfItemAtURL: (NSURL *)url;
+ (BOOL)removeOtherVersionsOfItemAtURL: (NSURL *)url 
                                 error: (NSError **)outError;

// instance methods...
- (BOOL) isDiscardable;
- (void) setDiscardable: (BOOL)flag;
- (BOOL) isResolved;
- (void) setResolved: (BOOL)flag;
- (NSDate *) modificationDate;
- (NSPersonNameComponents *) originatorNameComponents; 
- (NSString *) localizedName;
- (NSString *) localizedNameOfSavingComputer;
- (BOOL) hasLocalContents; 
- (BOOL) hasThumbnail; 
- (NSURL *) URL;
- (BOOL) conflict;
- (id<NSCoding>) persistentIdentifier;

- (BOOL) removeAndReturnError: (NSError **)outError;
- (NSURL *) replaceItemAtURL: (NSURL *)url
                     options: (NSFileVersionReplacingOptions)options
                       error: (NSError **)error;

@end

#endif
#endif
