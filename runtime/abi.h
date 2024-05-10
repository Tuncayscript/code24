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


#ifndef ABI_H
#define ABI_H

/* 
 * WARNING  DANGER  HAZARD  BEWARE  EEK
 * 
 * Everything in this file is for Apple Internal use only.
 * These will change in arbitrary OS updates and in unpredictable ways.
 * When your program breaks, you get to keep both pieces.
 */

/*
 * code-abi.h: Declarations for functions used by compiler codegen.
 */

#include <malloc/malloc.h>
#include <runtime/code.h>
#include <runtime/runtime.h>
#include <runtime/message.h>

/* Runtime startup. */

// Old static initializer. Used by old crt1.o and old bug workarounds.
CODE_EXPORT void _codeInit(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/* Images */

// Description of an Objective-C image.
// __DATA,__code_imageinfo stores one of these.
typedef struct code_image_info {
    uint32_t version; // currently 0
    uint32_t flags;
} code_image_info;

// Values for code_image_info.flags
#define CODE_IMAGE_IS_REPLACEMENT (1<<0)
#define CODE_IMAGE_SUPPORTS_GC (1<<1)
#define CODE_IMAGE_REQUIRES_GC (1<<2)
#define CODE_IMAGE_OPTIMIZED_BY_DYLD (1<<3)
#define CODE_IMAGE_SUPPORTS_COMPACTION (1<<4)  // might be re-assignable


/* Properties */

// Read or write an object property. Not all object properties use these.
CODE_EXPORT id code_getProperty(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
CODE_EXPORT void code_setProperty(id self, SEL _cmd, ptrdiff_t offset, id newValue, BOOL atomic, signed char shouldCopy)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

CODE_EXPORT void code_setProperty_atomic(id self, SEL _cmd, id newValue, ptrdiff_t offset)
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0)
    code_GC_UNAVAILABLE;
CODE_EXPORT void code_setProperty_nonatomic(id self, SEL _cmd, id newValue, ptrdiff_t offset)
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0)
    code_GC_UNAVAILABLE;
CODE_EXPORT void code_setProperty_atomic_copy(id self, SEL _cmd, id newValue, ptrdiff_t offset)
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0)
    code_GC_UNAVAILABLE;
CODE_EXPORT void code_setProperty_nonatomic_copy(id self, SEL _cmd, id newValue, ptrdiff_t offset)
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0)
    code_GC_UNAVAILABLE;


// Read or write a non-object property. Not all uses are C structs, 
// and not all C struct properties use this.
CODE_EXPORT void code_copyStruct(void *dest, const void *src, ptrdiff_t size, BOOL atomic, BOOL hasStrong)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

// Perform a copy of a C++ object using striped locks. Used by non-POD C++ typed atomic properties.
CODE_EXPORT void code_copyCppObjectAtomic(void *dest, const void *src, void (*copyHelper) (void *dest, const void *source))
    __OSX_AVAILABLE_STARTING(__MAC_10_8, __IPHONE_6_0);

/* Classes. */
#if __CODE__
CODE_EXPORT IMP _code_empty_vtable
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
#endif
CODE_EXPORT struct code_cache _code_empty_cache
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


/* Messages */

#if __CODE__
// code_msgSendSuper2() takes the current search class, not its superclass.
CODE_EXPORT id code_msgSendSuper2(struct code_super *super, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_2_0);
CODE_EXPORT void code_msgSendSuper2_stret(struct code_super *super, SEL op,...)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_2_0)
    code_ARM64_UNAVAILABLE;

// code_msgSend_noarg() may be faster for methods with no additional arguments.
CODE_EXPORT id code_msgSend_noarg(id self, SEL _cmd)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
#endif

#if __CODE__
// Debug messengers. Messengers used by the compiler have a debug flavor that 
// may perform extra sanity checking. 
// Old code_msgSendSuper() does not have a debug version; this is code2 only.
// *_fixup() do not have debug versions; use non-fixup only for debug mode.
CODE_EXPORT id code_msgSend_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
CODE_EXPORT id code_msgSendSuper2_debug(struct code_super *super, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
CODE_EXPORT void code_msgSend_stret_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
    code_ARM64_UNAVAILABLE;
CODE_EXPORT void code_msgSendSuper2_stret_debug(struct code_super *super, SEL op,...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
    code_ARM64_UNAVAILABLE;

# if defined(__i386__)
CODE_EXPORT double code_msgSend_fpret_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
# elif defined(__x86_64__)
CODE_EXPORT long double code_msgSend_fpret_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
#  if __STDC_VERSION__ >= 199901L
CODE_EXPORT _Complex long double code_msgSend_fp2ret_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
#  else
CODE_EXPORT void code_msgSend_fp2ret_debug(id self, SEL op, ...)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);
#  endif
# endif

#endif

#if defined(__x86_64__)  &&  TARGET_OS_MAC  &&  !TARGET_IPHONE_SIMULATOR
// code_msgSend_fixup() is used for vtable-dispatchable call sites.
CODE_EXPORT void code_msgSend_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
CODE_EXPORT void code_msgSend_stret_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
CODE_EXPORT void code_msgSendSuper2_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
CODE_EXPORT void code_msgSendSuper2_stret_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
CODE_EXPORT void code_msgSend_fpret_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
CODE_EXPORT void code_msgSend_fp2ret_fixup(void)
     __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5, __MAC_10_8, __IPHONE_NA, __IPHONE_NA);
#endif

/* C++-compatible exception handling. */
#if __CODE__

// fixme these conflict with C++ compiler's internal definitions
#if !defined(__cplusplus)

// Vtable for C++ exception typeinfo for Objective-C types.
CODE_EXPORT const void *code_ehtype_vtable[]
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

// C++ exception typeinfo for type `id`.
CODE_EXPORT struct code_typeinfo code_EHTYPE_id
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

#endif

// Exception personality function for Objective-C and Objective-C++ code.
struct _Unwind_Exception;
struct _Unwind_Context;
CODE_EXPORT int
__code_personality_v0(int version,
                      int actions,
                      uint64_t exceptionClass,
                      struct _Unwind_Exception *exceptionObject,
                      struct _Unwind_Context *context)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

#endif

/* ARR */

CODE_EXPORT id code_retainBlock(id)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0);

#endif
