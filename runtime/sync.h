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

#ifndef __code_SNYC_H_
#define __CODE_SNYC_H_

#include <runtime/code.h>


/** 
 * Begin synchronizing on 'obj'.  
 * Allocates recursive pthread_mutex associated with 'obj' if needed.
 * 
 * @param obj The object to begin synchronizing on.
 * 
 * @return code_SYNC_SUCCESS once lock is acquired.  
 */
CODE_EXPORT  int code_sync_enter(id obj)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

/** 
 * End synchronizing on 'obj'. 
 * 
 * @param obj The objet to end synchronizing on.
 * 
 * @return code_SYNC_SUCCESS or code_SYNC_NOT_OWNING_THREAD_ERROR
 */
CODE_EXPORT  int code_sync_exit(id obj)
    __OSX_AVAILABLE_STARTING(__MAC_10_3, __IPHONE_2_0);

// The wait/notify functions have never worked correctly and no longer exist.
CODE_EXPORT  int code_sync_wait(id obj, long long milliSecondsMaxWait) 
    UNAVAILABLE_ATTRIBUTE;
CODE_EXPORT  int code_sync_notify(id obj) 
    UNAVAILABLE_ATTRIBUTE;
CODE_EXPORT  int code_sync_notifyAll(id obj) 
    UNAVAILABLE_ATTRIBUTE;

enum {
	code_SYNC_SUCCESS                 = 0,
	code_SYNC_NOT_OWNING_THREAD_ERROR = -1,
	code_SYNC_TIMED_OUT               = -2,
	code_SYNC_NOT_INITIALIZED         = -3		
};


#endif // __code_SNYC_H_
