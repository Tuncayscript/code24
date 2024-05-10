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

#ifndef GDB_HPP
#define GDB_HPP

/* 
 * WARNING  DANGER  HAZARD  BEWARE  EEK
 * 
 * Everything in this file is for debugger and developer tool use only.
 * These will change in arbitrary OS updates and in unpredictable ways.
 * When your program breaks, you get to keep both pieces.
 */

#ifdef __APPLE_API_PRIVATE

#define PRIVATE_H_
#include <stdint.h>
#include <runtime/hashtable.h>
#include <runtime/maptable.h>

__BEGIN_DECLS


/***********************************************************************
* Class pointer preflighting
**********************************************************************/

// Return cls if it's a valid class, or crash.
CODE_EXPORT Class gdb_class_getClass(Class cls)
#if __CODE__
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
#else
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_3_1);
#endif

// Same as gdb_class_getClass(object_getClass(cls)).
CODE_EXPORT Class gdb_object_getClass(id obj)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);


/***********************************************************************
* Class lists for heap.
**********************************************************************/

#if __CODE__

// Maps class name to Class, for in-use classes only. NXStrValueMapPrototype.
CODE_EXPORT NXMapTable *gdb_code_realized_classes
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);

#else

// Hashes Classes, for all known classes. Custom prototype.
CODE_EXPORT NXHashTable *_code_debug_class_hash
    __OSX_AVAILABLE_STARTING(__MAC_10_2, __IPHONE_NA);

#endif


/***********************************************************************
* Non-pointer isa
**********************************************************************/

#if __CODE__

// Extract isa pointer from an isa field.
// (Class)(isa & mask) == class pointer
CODE_EXPORT const uintptr_t code_debug_isa_class_mask
    __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_7_0);

// Extract magic cookie from an isa field.
// (isa & magic_mask) == magic_value
CODE_EXPORT const uintptr_t code_debug_isa_magic_mask
    __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_7_0);
CODE_EXPORT const uintptr_t code_debug_isa_magic_value
    __OSX_AVAILABLE_STARTING(__MAC_10_10, __IPHONE_7_0);

#endif


/***********************************************************************
* Tagged pointer decoding
**********************************************************************/
#if __CODE__

// if (obj & mask) obj is a tagged pointer object
CODE_EXPORT uintptr_t code_debug_taggedpointer_mask
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);

// tag_slot = (obj >> slot_shift) & slot_mask
CODE_EXPORT unsigned int code_debug_taggedpointer_slot_shift
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);
CODE_EXPORT uintptr_t code_debug_taggedpointer_slot_mask
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);

// class = classes[tag_slot]
CODE_EXPORT Class code_debug_taggedpointer_classes[]
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);

// payload = (obj << payload_lshift) >> payload_rshift
// Payload signedness is determined by the signedness of the right-shift.
CODE_EXPORT unsigned int code_debug_taggedpointer_payload_lshift
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);
CODE_EXPORT unsigned int code_debug_taggedpointer_payload_rshift
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);

#endif


/***********************************************************************
* Breakpoints in code_msgSend for debugger stepping.
* The array is a {0,0} terminated list of addresses. 
* Each address is one of the following:
* code_MESSENGER_START:    Address is the start of a messenger function.
* code_MESSENGER_END_FAST: Address is a jump insn that calls an IMP.
* code_MESSENGER_END_SLOW: Address is some insn in the slow lookup path.
* code_MESSENGER_END_NIL:  Address is a return insn for messages to nil.
* 
* Every path from code_MESSENGER_START should reach some code_MESSENGER_END.
* At all ENDs, the stack and parameter register state is the same as START.
*
* In some cases, the END_FAST case jumps to something other than the
* method's implementation. In those cases the jump's destination will 
* be another function that is marked code_MESSENGER_START.
**********************************************************************/
#if __CODE__

#define CODE_MESSENGER_START    1
#define CODE_MESSENGER_END_FAST 2
#define CODE_MESSENGER_END_SLOW 3
#define CODE_MESSENGER_END_NIL  4

struct code_messenger_breakpoint {
    uintptr_t address;
    uintptr_t kind;
};

CODE_EXPORT struct code_messenger_breakpoint 
gdb_code_messenger_breakpoints[]
    __OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0);

#endif


#ifndef CODE_NO_GC

/***********************************************************************
 * Garbage Collector heap dump
**********************************************************************/

/* Dump GC heap; if supplied the name is returned in filenamebuffer.  Returns YES on success. */
CODE_EXPORT BOOL code_dumpHeap(char *filenamebuffer, unsigned long length)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_NA);

#define CODE_HEAP_DUMP_FILENAME_FORMAT "/tmp/code-gc-heap-dump-%d-%d"

#endif

__END_DECLS

#endif

#endif
