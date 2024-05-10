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

#ifndef LITTLE_HASHTABLE_H_
#define LITTLE_HASHTABLE_H_

#ifndef PRIVATE_H_
#   define code_HASH_AVAILABILITY __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_1, __IPHONE_NA,__IPHONE_NA);
#else
#   define code_HASH_AVAILABILITY
#endif

#include <runtime/code.h>
#include <stdint.h>
#include <TargetConditionals.h>

__BEGIN_DECLS

/*************************************************************************
 *	Hash tables of arbitrary data
 *************************************************************************/

/* This module allows hashing of arbitrary data.  Such data must be pointers or integers, and client is responsible for allocating/deallocating this data.  A deallocation call-back is provided.
The objective C class HashTable is preferred when dealing with (key, values) associations because it is easier to use in that situation.
As well-behaved scalable data structures, hash tables double in size when they start becoming full, thus guaranteeing both average constant time access and linear size. */

typedef struct {
    uintptr_t	(*hash)(const void *info, const void *data);
    int		(*isEqual)(const void *info, const void *data1, const void *data2);
    void	(*free)(const void *info, void *data);
    int		style; /* reserved for future expansion; currently 0 */
    } NXHashTablePrototype;
    
/* the info argument allows a certain generality, such as freeing according to some owner information */
/* invariants assumed by the implementation: 
	1 - data1 = data2 => hash(data1) = hash(data2)
	    when data varies over time, hash(data) must remain invariant
		    e.g. if data hashes over a string key, the string must not be changed
	2- isEqual (data1, data2) => data1= data2
 */

typedef struct {
    const NXHashTablePrototype	*prototype code_HASH_AVAILABILITY;
    unsigned			count code_HASH_AVAILABILITY;
    unsigned			nbBuckets code_HASH_AVAILABILITY;
    void			*buckets code_HASH_AVAILABILITY;
    const void			*info code_HASH_AVAILABILITY;
   } NXHashTable code_HASH_AVAILABILITY;
    /* private data structure; may change */
    
CODE_EXPORT NXHashTable *NXCreateHashTableFromZone (NXHashTablePrototype prototype, unsigned capacity, const void *info, void *z) code_HASH_AVAILABILITY;
CODE_EXPORT NXHashTable *NXCreateHashTable (NXHashTablePrototype prototype, unsigned capacity, const void *info) code_HASH_AVAILABILITY;
    /* if hash is 0, pointer hash is assumed */
    /* if isEqual is 0, pointer equality is assumed */
    /* if free is 0, elements are not freed */
    /* capacity is only a hint; 0 creates a small table */
    /* info allows call backs to be very general */

CODE_EXPORT void NXFreeHashTable (NXHashTable *table) code_HASH_AVAILABILITY;
    /* calls free for each data, and recovers table */
	
CODE_EXPORT void NXEmptyHashTable (NXHashTable *table) code_HASH_AVAILABILITY;
    /* does not deallocate table nor data; keeps current capacity */

CODE_EXPORT void NXResetHashTable (NXHashTable *table) code_HASH_AVAILABILITY;
    /* frees each entry; keeps current capacity */

CODE_EXPORT BOOL NXCompareHashTables (NXHashTable *table1, NXHashTable *table2) code_HASH_AVAILABILITY;
    /* Returns YES if the two sets are equal (each member of table1 in table2, and table have same size) */

CODE_EXPORT NXHashTable *NXCopyHashTable (NXHashTable *table) code_HASH_AVAILABILITY;
    /* makes a fresh table, copying data pointers, not data itself.  */
	
CODE_EXPORT unsigned NXCountHashTable (NXHashTable *table) code_HASH_AVAILABILITY;
    /* current number of data in table */
	
CODE_EXPORT int NXHashMember (NXHashTable *table, const void *data) code_HASH_AVAILABILITY;
    /* returns non-0 iff data is present in table.
    Example of use when the hashed data is a struct containing the key,
    and when the callee only has a key:
	MyStruct	pseudo;
	pseudo.key = myKey;
	return NXHashMember (myTable, &pseudo)
    */
	
CODE_EXPORT void *NXHashGet (NXHashTable *table, const void *data) code_HASH_AVAILABILITY;
    /* return original table data or NULL.
    Example of use when the hashed data is a struct containing the key,
    and when the callee only has a key:
	MyStruct	pseudo;
	MyStruct	*original;
	pseudo.key = myKey;
	original = NXHashGet (myTable, &pseudo)
    */
	
CODE_EXPORT void *NXHashInsert (NXHashTable *table, const void *data) code_HASH_AVAILABILITY;
    /* previous data or NULL is returned. */
	
CODE_EXPORT void *NXHashInsertIfAbsent (NXHashTable *table, const void *data) code_HASH_AVAILABILITY;
    /* If data already in table, returns the one in table
    else adds argument to table and returns argument. */

CODE_EXPORT void *NXHashRemove (NXHashTable *table, const void *data) code_HASH_AVAILABILITY;
    /* previous data or NULL is returned */
	
/* Iteration over all elements of a table consists in setting up an iteration state and then to progress until all entries have been visited.  An example of use for counting elements in a table is:
    unsigned	count = 0;
    MyData	*data;
    NXHashState	state = NXInitHashState(table);
    while (NXNextHashState(table, &state, &data)) {
	count++;
    }
*/

typedef struct {int i; int j;} NXHashState code_HASH_AVAILABILITY;
    /* callers should not rely on actual contents of the struct */

CODE_EXPORT NXHashState NXInitHashState(NXHashTable *table) code_HASH_AVAILABILITY;

CODE_EXPORT int NXNextHashState(NXHashTable *table, NXHashState *state, void **data) code_HASH_AVAILABILITY;
    /* returns 0 when all elements have been visited */

/*************************************************************************
 *	Conveniences for writing hash, isEqual and free functions
 *	and common prototypes
 *************************************************************************/

CODE_EXPORT uintptr_t NXPtrHash(const void *info, const void *data) code_HASH_AVAILABILITY;
    /* scrambles the address bits; info unused */
CODE_EXPORT uintptr_t NXStrHash(const void *info, const void *data) code_HASH_AVAILABILITY;
    /* string hashing; info unused */
CODE_EXPORT int NXPtrIsEqual(const void *info, const void *data1, const void *data2) code_HASH_AVAILABILITY;
    /* pointer comparison; info unused */
CODE_EXPORT int NXStrIsEqual(const void *info, const void *data1, const void *data2) code_HASH_AVAILABILITY;
    /* string comparison; NULL ok; info unused */
CODE_EXPORT void NXNoEffectFree(const void *info, void *data) code_HASH_AVAILABILITY;
    /* no effect; info unused */
CODE_EXPORT void NXReallyFree(const void *info, void *data) code_HASH_AVAILABILITY;
    /* frees it; info unused */

/* The two following prototypes are useful for manipulating set of pointers or set of strings; For them free is defined as NXNoEffectFree */
CODE_EXPORT const NXHashTablePrototype NXPtrPrototype code_HASH_AVAILABILITY;
    /* prototype when data is a pointer (void *) */
CODE_EXPORT const NXHashTablePrototype NXStrPrototype code_HASH_AVAILABILITY;
    /* prototype when data is a string (char *) */

/* following prototypes help describe mappings where the key is the first element of a struct and is either a pointer or a string.
For example NXStrStructKeyPrototype can be used to hash pointers to Example, where Example is:
	typedef struct {
	    char	*key;
	    int		data1;
	    ...
	    } Example
    
For the following prototypes, free is defined as NXReallyFree.
 */
CODE_EXPORT const NXHashTablePrototype NXPtrStructKeyPrototype code_HASH_AVAILABILITY;
CODE_EXPORT const NXHashTablePrototype NXStrStructKeyPrototype code_HASH_AVAILABILITY;


#if !__CODE__  &&  !TARGET_OS_WIN32

/*************************************************************************
 *	Unique strings and buffers
 *************************************************************************/

/* Unique strings allows C users to enjoy the benefits of Lisp's atoms:
A unique string is a string that is allocated once for all (never de-allocated) and that has only one representant (thus allowing comparison with == instead of strcmp).  A unique string should never be modified (and in fact some memory protection is done to ensure that).  In order to more explicitly insist on the fact that the string has been uniqued, a synonym of (const char *) has been added, NXAtom. */

typedef const char *NXAtom code_HASH_AVAILABILITY;

CODE_EXPORT NXAtom NXUniqueString(const char *buffer) code_HASH_AVAILABILITY;
    /* assumes that buffer is \0 terminated, and returns
     a previously created string or a new string that is a copy of buffer.
    If NULL is passed returns NULL.
    Returned string should never be modified.  To ensure this invariant,
    allocations are made in a special read only zone. */
	
CODE_EXPORT NXAtom NXUniqueStringWithLength(const char *buffer, int length) code_HASH_AVAILABILITY;
    /* assumes that buffer is a non NULL buffer of at least 
    length characters.  Returns a previously created string or 
    a new string that is a copy of buffer. 
    If buffer contains \0, string will be truncated.
    As for NXUniqueString, returned string should never be modified.  */
	
CODE_EXPORT NXAtom NXUniqueStringNoCopy(const char *string) code_HASH_AVAILABILITY;
    /* If there is already a unique string equal to string, returns the original.  
    Otherwise, string is entered in the table, without making a copy.  Argument should then never be modified.  */
	
CODE_EXPORT char *NXCopyStringBuffer(const char *buffer) code_HASH_AVAILABILITY;
    /* given a buffer, allocates a new string copy of buffer.  
    Buffer should be \0 terminated; returned string is \0 terminated. */

CODE_EXPORT char *NXCopyStringBufferFromZone(const char *buffer, void *z) code_HASH_AVAILABILITY;
    /* given a buffer, allocates a new string copy of buffer.  
    Buffer should be \0 terminated; returned string is \0 terminated. */

#endif

__END_DECLS

#endif /* _code_LITTLE_HASHTABLE_H_ */
