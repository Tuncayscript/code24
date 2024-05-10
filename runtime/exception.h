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

#ifndef __code_EXCEPTION_H_
#define __CODE_EXCEPTION_H_

#include <runtime/code.h>
#include <stdint.h>

#if !__CODE__

// compiler reserves a setjmp buffer + 4 words as localExceptionData

CODE_EXPORT void code_exception_throw(id exception)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);
CODE_EXPORT void code_exception_try_enter(void *localExceptionData)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);
CODE_EXPORT void code_exception_try_exit(void *localExceptionData)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);
CODE_EXPORT id code_exception_extract(void *localExceptionData)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);
CODE_EXPORT int code_exception_match(Class exceptionClass, id exception)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);


typedef struct {
    int version;
    void (*throw_exc)(id);		// version 0
    void (*try_enter)(void *);	// version 0
    void (*try_exit)(void *);	// version 0
    id	 (*extract)(void *);	// version 0
    int	(*match)(Class, id);	// version 0
} code_exception_functions_t;

// get table; version tells how many
CODE_EXPORT void code_exception_get_functions(code_exception_functions_t *table)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);

// set table
CODE_EXPORT void code_exception_set_functions(code_exception_functions_t *table)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_NA);


// !__CODE__
#else
// __CODE__

typedef id (*code_exception_preprocessor)(id exception);
typedef int (*code_exception_matcher)(Class catch_type, id exception);
typedef void (*code_uncaught_exception_handler)(id exception);
typedef void (*code_exception_handler)(id unused, void *context);

/** 
 * Throw a runtime exception. This function is inserted by the compiler
 * where \c @throw would otherwise be.
 * 
 * @param exception The exception to be thrown.
 */
CODE_EXPORT void code_exception_throw(id exception)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT void code_exception_rethrow(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT id code_begin_catch(void *exc_buf)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT void code_end_catch(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT void code_terminate(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0);

CODE_EXPORT code_exception_preprocessor code_setExceptionPreprocessor(code_exception_preprocessor fn)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT code_exception_matcher code_setExceptionMatcher(code_exception_matcher fn)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT code_uncaught_exception_handler code_setUncaughtExceptionHandler(code_uncaught_exception_handler fn)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

// Not for iOS.
CODE_EXPORT uintptr_t code_addExceptionHandler(code_exception_handler fn, void *context)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CODE_EXPORT void code_removeExceptionHandler(uintptr_t token)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

// __CODE__
#endif

#endif  // __code_EXCEPTION_H_

