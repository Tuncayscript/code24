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

#import "Object.h"

@class NSData;
@class NSError;
@class NSInputStream;
@class NSOutputStream;

enum
{
  /**
   * Collection classes created from reading a JSON stream will be mutable.
   */
  NSJSONReadingMutableContainers = (1UL << 0),
  /**
   * Strings in a JSON tree will be mutable.
   */
  NSJSONReadingMutableLeaves     = (1UL << 1),
  /**
   * The parser will read a single value, not just a 
   */
  NSJSONReadingAllowFragments    = (1UL << 2)
};
enum
{
  /**
   * When writing JSON, produce indented output intended for humans to read.
   * If this is not set, then the writer will not generate any superfluous
   * whitespace, producing space-efficient but not very human-friendly JSON.
   */
  NSJSONWritingPrettyPrinted = (1UL << 0)
};
/**
 * A bitmask containing flags from the NSJSONWriting* set, specifying options
 * to use when writing JSON.
 */
typedef NSUInteger NSJSONWritingOptions;
/**
 * A bitmask containing flags from the NSJSONReading* set, specifying options
 * to use when reading JSON.
 */
typedef NSUInteger NSJSONReadingOptions;


/**
 * NSJSONSerialization implements serializing and deserializing acyclic object
 * graphs in JSON.
 */
GS_EXPORT_CLASS
@interface NSJSONSerialization : NSObject
+ (NSData*) dataWithJSONObject: (id)obj
                       options: (NSJSONWritingOptions)opt
                         error: (NSError **)error;
+ (BOOL) isValidJSONObject: (id)obj;
+ (id) JSONObjectWithData: (NSData *)data
                  options: (NSJSONReadingOptions)opt
                    error: (NSError **)error;
+ (id) JSONObjectWithStream: (NSInputStream *)stream
                    options: (NSJSONReadingOptions)opt
                      error: (NSError **)error;
+ (NSInteger) writeJSONObject: (id)obj
                     toStream: (NSOutputStream *)stream
                      options: (NSJSONWritingOptions)opt
                        error: (NSError **)error;
@end
