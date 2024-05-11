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
// Filename: AGSHtml.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 11, 2024
// Purpose: Zone Allocator for Language
// Technology: C++20 - ISO/IEC 14882:2020(E)
// Description: A Class to output html for a gsdoc file</title>

#import "Foundation/NSObject.h"
#import "AGSIndex.h"

@class	NSMutableString;
@class	NSString;

@interface AGSHtml : NSObject
{
  NSString		*project;
  AGSIndex		*localRefs;
  AGSIndex		*globalRefs;
  AGSIndex		*projectRefs;
  NSMutableString	*indent;
  NSString		*base;	// Not retained
  NSString		*unit;	// Not retained
  NSString		*category;	// Not retained
  NSString		*classname;	// Not retained
  NSString		*heading;	// Not retained
  NSString		*nextFile;	// Not retained
  NSString		*prevFile;	// Not retained
  NSString		*upFile;	// Not retained
  NSString		*fileName;
  unsigned		chap;
  unsigned		sect;
  unsigned		ssect;
  unsigned		sssect;
  BOOL			isContentsDoc;
  BOOL			ivarsAtEnd;
  BOOL			verbose;
  BOOL			warn;
}
- (void) decIndent;
- (void) incIndent;
- (NSString*) makeAnchor: (NSString*)r
		  ofType: (NSString*)t
		    name: (NSString*)n;
- (NSString*) makeLink: (NSString*)r
		ofType: (NSString*)t
		 isRef: (BOOL)f;
- (NSString*) makeLink: (NSString*)r
		ofType: (NSString*)t
		inUnit: (NSString*)u
		 isRef: (BOOL)f;
- (void) outputIndex: (NSString*)type
	       scope: (NSString*)scope
	       title: (NSString*)title
	       style: (NSString*)style
              target: (NSString*)target
                  to: (NSMutableString*)buf;
- (NSString*) outputDocument: (GSXMLNode*)node name: (NSString*)file;
- (void) outputNode: (GSXMLNode*)node to: (NSMutableString*)buf;
- (void) outputNodeList: (GSXMLNode*)node to: (NSMutableString*)buf;
- (GSXMLNode*) outputBlock: (GSXMLNode*)node
			to: (NSMutableString*)buf
		    inPara: (BOOL)flag;
- (GSXMLNode*) outputList: (GSXMLNode*)node to: (NSMutableString*)buf;
- (GSXMLNode*) outputText: (GSXMLNode*)node to: (NSMutableString*)buf;
- (void) outputUnit: (GSXMLNode*)node to: (NSMutableString*)buf;
- (void) outputVersion: (NSDictionary*)prop to: (NSMutableString*)buf;
- (NSString*) protocolRef: (NSString*)t;
- (void) setGlobalRefs: (AGSIndex*)r;
- (void) setLocalRefs: (AGSIndex*)r;
- (void) setProjectRefs: (AGSIndex*)r;
- (void) setInstanceVariablesAtEnd: (BOOL)val;
- (NSString*) typeRef: (NSString*)t;
@end
#endif
#endif 
