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

#ifndef _NSLinguisticTagger_h_GNUSTEP_BASE_INCLUDE
#define _NSLinguisticTagger_h_GNUSTEP_BASE_INCLUDE

#include <Foundation/Object.h>
#include <Foundation/Range.h>
#include <Foundation/String.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSString, NSArray, NSOrthography;
  
typedef NSString* NSLinguisticTagScheme;

GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeTokenType;            
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeLexicalClass;         
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeNameType;             
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeNameTypeOrLexicalClass;
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeLemma;                 
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeLanguage;              
GS_EXPORT NSLinguisticTagScheme const NSLinguisticTagSchemeScript;                

typedef NSString* NSLinguisticTag;

/* Tags for NSLinguisticTagSchemeTokenType */
GS_EXPORT NSLinguisticTag const NSLinguisticTagWord;                          
GS_EXPORT NSLinguisticTag const NSLinguisticTagPunctuation;                   
GS_EXPORT NSLinguisticTag const NSLinguisticTagWhitespace;                    
GS_EXPORT NSLinguisticTag const NSLinguisticTagOther;                         

/* Tags for NSLinguisticTagSchemeLexicalClass */
GS_EXPORT NSLinguisticTag const NSLinguisticTagNoun;
GS_EXPORT NSLinguisticTag const NSLinguisticTagVerb;
GS_EXPORT NSLinguisticTag const NSLinguisticTagAdjective;
GS_EXPORT NSLinguisticTag const NSLinguisticTagAdverb;
GS_EXPORT NSLinguisticTag const NSLinguisticTagPronoun;
GS_EXPORT NSLinguisticTag const NSLinguisticTagDeterminer;
GS_EXPORT NSLinguisticTag const NSLinguisticTagParticle;
GS_EXPORT NSLinguisticTag const NSLinguisticTagPreposition;
GS_EXPORT NSLinguisticTag const NSLinguisticTagNumber;
GS_EXPORT NSLinguisticTag const NSLinguisticTagConjunction;
GS_EXPORT NSLinguisticTag const NSLinguisticTagInterjection;
GS_EXPORT NSLinguisticTag const NSLinguisticTagClassifier;
GS_EXPORT NSLinguisticTag const NSLinguisticTagIdiom;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOtherWord;
GS_EXPORT NSLinguisticTag const NSLinguisticTagSentenceTerminator;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOpenQuote;
GS_EXPORT NSLinguisticTag const NSLinguisticTagCloseQuote;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOpenParenthesis;
GS_EXPORT NSLinguisticTag const NSLinguisticTagCloseParenthesis;
GS_EXPORT NSLinguisticTag const NSLinguisticTagWordJoiner;
GS_EXPORT NSLinguisticTag const NSLinguisticTagDash;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOtherPunctuation;
GS_EXPORT NSLinguisticTag const NSLinguisticTagParagraphBreak;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOtherWhitespace;

/* Tags for NSLinguisticTagSchemeNameType */
GS_EXPORT NSLinguisticTag const NSLinguisticTagPersonalName;
GS_EXPORT NSLinguisticTag const NSLinguisticTagPlaceName;
GS_EXPORT NSLinguisticTag const NSLinguisticTagOrganizationName;

enum
{
    NSLinguisticTaggerUnitWord,        
    NSLinguisticTaggerUnitSentence,    
    NSLinguisticTaggerUnitParagraph,   
    NSLinguisticTaggerUnitDocument     
};
typedef NSUInteger NSLinguisticTaggerUnit;

enum
{ 
    NSLinguisticTaggerOmitWords         = 1 << 0, 
    NSLinguisticTaggerOmitPunctuation   = 1 << 1, 
    NSLinguisticTaggerOmitWhitespace    = 1 << 2, 
    NSLinguisticTaggerOmitOther         = 1 << 3, 
    NSLinguisticTaggerJoinNames         = 1 << 4  
};
typedef NSUInteger NSLinguisticTaggerOptions;

DEFINE_BLOCK_TYPE(GSLinguisticTagRangeBoolBlock, void, NSLinguisticTag, NSRange, BOOL);
DEFINE_BLOCK_TYPE(GSLinguisticTagRangeRangeBoolBlock, void, NSLinguisticTag, NSRange, NSRange, BOOL);

GS_EXPORT_CLASS
@interface NSLinguisticTagger : NSObject
{
  NSArray *_schemes;
  NSString *_string;
  NSString *_dominantLanguage;
  NSArray *_tokenArray;
  NSArray *_orthographyArray;
  NSUInteger _options;
}
  
- (instancetype) initWithTagSchemes: (NSArray *)tagSchemes
                            options: (NSUInteger)opts;

- (NSArray *) tagSchemes;

- (NSString *) string;
- (void) setString: (NSString *)string;
  
+ (NSArray *) availableTagSchemesForUnit: (NSLinguisticTaggerUnit)unit
                                language: (NSString *)language;

+ (NSArray *) availableTagSchemesForLanguage: (NSString *)language;

- (void) setOrthography: (NSOrthography *)orthography
                  range: (NSRange)range;
  
- (NSOrthography *) orthographyAtIndex: (NSUInteger)charIndex
                        effectiveRange: (NSRangePointer)effectiveRange; 

- (void) stringEditedInRange: (NSRange)newRange
              changeInLength: (NSInteger)delta;
  
- (NSRange) tokenRangeAtIndex: (NSUInteger)charIndex
                         unit: (NSLinguisticTaggerUnit)unit;
  
- (NSRange) sentenceRangeForRange: (NSRange)range;

- (void) enumerateTagsInRange: (NSRange)range
                         unit: (NSLinguisticTaggerUnit)unit
                       scheme: (NSLinguisticTagScheme)scheme
                      options: (NSLinguisticTaggerOptions)options
                   usingBlock: (GSLinguisticTagRangeBoolBlock)block;
  
- (NSLinguisticTag) tagAtIndex: (NSUInteger)charIndex
                          unit: (NSLinguisticTaggerUnit)unit
                        scheme: (NSLinguisticTagScheme)scheme
                    tokenRange: (NSRangePointer)tokenRange;

- (NSArray *) tagsInRange: (NSRange)range
                     unit: (NSLinguisticTaggerUnit)unit
                   scheme: (NSLinguisticTagScheme)scheme
                  options: (NSLinguisticTaggerOptions)options
              tokenRanges: (NSArray **)tokenRanges;

- (void) enumerateTagsInRange: (NSRange)range
                       scheme: (NSLinguisticTagScheme)tagScheme
                      options: (NSLinguisticTaggerOptions)opts
                   usingBlock: (GSLinguisticTagRangeRangeBoolBlock)block;

- (NSLinguisticTag) tagAtIndex: (NSUInteger)charIndex
                        scheme: (NSLinguisticTagScheme)scheme
                    tokenRange: (NSRangePointer)tokenRange
                 sentenceRange: (NSRangePointer)sentenceRange;
  
- (NSArray *) tagsInRange: (NSRange)range
                   scheme: (NSString *)tagScheme
                  options: (NSLinguisticTaggerOptions)opts
              tokenRanges: (NSArray **)tokenRanges;

- (NSString *) dominantLanguage;

+ (NSString *) dominantLanguageForString: (NSString *)string;

+ (NSLinguisticTag) tagForString: (NSString *)string
                         atIndex: (NSUInteger)charIndex
                            unit: (NSLinguisticTaggerUnit)unit
                          scheme: (NSLinguisticTagScheme)scheme
                     orthography: (NSOrthography *)orthography
                      tokenRange: (NSRangePointer)tokenRange;
  
+ (NSArray *)tagsForString: (NSString *)string
                     range: (NSRange)range
                      unit: (NSLinguisticTaggerUnit)unit
                    scheme: (NSLinguisticTagScheme)scheme
                   options: (NSLinguisticTaggerOptions)options
               orthography: (NSOrthography *)orthography
               tokenRanges: (NSArray **)tokenRanges;

+ (void) enumerateTagsForString: (NSString *)string
                          range: (NSRange)range
                           unit: (NSLinguisticTaggerUnit)unit
                         scheme: (NSLinguisticTagScheme)scheme
                        options: (NSLinguisticTaggerOptions)options
                    orthography: (NSOrthography *)orthography
                     usingBlock: (GSLinguisticTagRangeBoolBlock)block;
  

- (NSArray *) possibleTagsAtIndex: (NSUInteger)charIndex
                           scheme: (NSString *)tagScheme
                       tokenRange: (NSRangePointer)tokenRange
                    sentenceRange: (NSRangePointer)sentenceRange
                           scores: (NSArray **)scores;

@end

@interface NSString (NSLinguisticAnalysis)

- (NSArray *) linguisticTagsInRange: (NSRange)range
                             scheme: (NSLinguisticTagScheme)scheme
                            options: (NSLinguisticTaggerOptions)options
                        orthography: (NSOrthography *)orthography
                        tokenRanges: (NSArray **)tokenRanges;

- (void) enumerateLinguisticTagsInRange: (NSRange)range
                                 scheme: (NSLinguisticTagScheme)scheme
                                options: (NSLinguisticTaggerOptions)options
                            orthography: (NSOrthography *)orthography
                             usingBlock: (GSLinguisticTagRangeRangeBoolBlock)block;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSLinguisticTagger_h_GNUSTEP_BASE_INCLUDE */

