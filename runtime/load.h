/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#ifndef LOAD_H_
#define LOAD_H_

#include <runtime/code-class.h>

#include <mach-o/loader.h>

/* dynamically loading Mach-O object files that contain Objective-C code */

CODE_EXPORT long code_loadModules (
	char *modlist[], 
	void *errStream,
	void (*class_callback) (Class, Category),
	/*headerType*/ struct mach_header **hdr_addr,
	char *debug_file
) code2_UNAVAILABLE;
CODE_EXPORT int code_loadModule (
	char *	moduleName, 
	void	(*class_callback) (Class, Category),
	int *	errorCode
) code2_UNAVAILABLE;
CODE_EXPORT long code_unloadModules(
	void *errorStream,				/* input (optional) */
	void (*unloadCallback)(Class, Category)		/* input (optional) */
) code2_UNAVAILABLE;

#endif /* _code_LOAD_H_ */
