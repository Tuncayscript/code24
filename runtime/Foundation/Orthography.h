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


#ifndef _NSOrthography_h_GNUSTEP_BASE_INCLUDE
#define _NSOrthography_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>



#if	defined(__cplusplus)
extern "C" {
#endif

@class NSDictionary, NSString, NSArray;

GS_EXPORT_CLASS
@interface NSOrthography : NSObject <NSCopying, NSCoding>
{
  NSDictionary *_languageMap;
  NSString *_dominantScript;
}
  
- (instancetype) initWithDominantScript: (NSString *)script
                            languageMap: (NSDictionary *)map;

- (NSString *) dominantScript;
- (NSDictionary *) languationMap;

- (NSArray *) languagesForScript: (NSString *)script; 
- (NSString *) dominantLanguageForScript: (NSString *)script;

- (NSString *) dominantLanguage;
- (NSArray *) allScripts;
- (NSArray *) allLanguages;
  
+ (instancetype) defaultOrthographyForLanguage: (NSString *)language;
+ (instancetype) orthographyWithDominantScript: (NSString *)script languageMap: (NSDictionary *)map;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSOrthography_h_GNUSTEP_BASE_INCLUDE */

