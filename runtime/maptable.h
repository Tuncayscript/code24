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
/*	maptable.h
	Scalable hash table of mappings.
	Bertrand, August 1990
	Copyright 1990-1996 NeXT Software, Inc.
*/

#ifndef MAPTABLE_H_
#define MAPTABLE_H_

#ifndef PRIVATE_H_
#   define code_MAP_AVAILABILITY __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_0,__MAC_10_1, __IPHONE_NA,__IPHONE_NA);
#else
#   define code_MAP_AVAILABILITY
#endif

#include <runtime/code.h>

__BEGIN_DECLS

/***************	Definitions		***************/

    /* This module allows hashing of arbitrary associations [key -> value].  Keys and values must be pointers or integers, and client is responsible for allocating/deallocating this data.  A deallocation call-back is provided.
    NX_MAPNOTAKEY (-1) is used internally as a marker, and therefore keys must always be different from -1.
    As well-behaved scalable data structures, hash tables double in size when they start becoming full, thus guaranteeing both average constant time access and linear size. */

typedef struct _NXMapTable {
    /* private data structure; may change */
    const struct _NXMapTablePrototype	*prototype;
    unsigned	count;
    unsigned	nbBucketsMinusOne;
    void	*buckets;
} NXMapTable code_MAP_AVAILABILITY;

typedef struct _NXMapTablePrototype {
    unsigned	(*hash)(NXMapTable *, const void *key);
    int		(*isEqual)(NXMapTable *, const void *key1, const void *key2);
    void	(*free)(NXMapTable *, void *key, void *value);
    int		style; /* reserved for future expansion; currently 0 */
} NXMapTablePrototype code_MAP_AVAILABILITY;
    
    /* invariants assumed by the implementation: 
	A - key != -1
	B - key1 == key2 => hash(key1) == hash(key2)
	    when key varies over time, hash(key) must remain invariant
	    e.g. if string key, the string must not be changed
	C - isEqual(key1, key2) => key1 == key2
    */

#define NX_MAPNOTAKEY	((void *)(-1))

/***************	Functions		***************/

CODE_EXPORT NXMapTable *NXCreateMapTableFromZone(NXMapTablePrototype prototype, unsigned capacity, void *z) code_MAP_AVAILABILITY;
CODE_EXPORT NXMapTable *NXCreateMapTable(NXMapTablePrototype prototype, unsigned capacity) code_MAP_AVAILABILITY;
    /* capacity is only a hint; 0 creates a small table */

CODE_EXPORT void NXFreeMapTable(NXMapTable *table) code_MAP_AVAILABILITY;
    /* call free for each pair, and recovers table */
	
CODE_EXPORT void NXResetMapTable(NXMapTable *table) code_MAP_AVAILABILITY;
    /* free each pair; keep current capacity */

CODE_EXPORT BOOL NXCompareMapTables(NXMapTable *table1, NXMapTable *table2) code_MAP_AVAILABILITY;
    /* Returns YES if the two sets are equal (each member of table1 in table2, and table have same size) */

CODE_EXPORT unsigned NXCountMapTable(NXMapTable *table) code_MAP_AVAILABILITY;
    /* current number of data in table */
	
CODE_EXPORT void *NXMapMember(NXMapTable *table, const void *key, void **value) code_MAP_AVAILABILITY;
    /* return original table key or NX_MAPNOTAKEY.  If key is found, value is set */
	
CODE_EXPORT void *NXMapGet(NXMapTable *table, const void *key) code_MAP_AVAILABILITY;
    /* return original corresponding value or NULL.  When NULL need be stored as value, NXMapMember can be used to test for presence */
	
CODE_EXPORT void *NXMapInsert(NXMapTable *table, const void *key, const void *value) code_MAP_AVAILABILITY;
    /* override preexisting pair; Return previous value or NULL. */
	
CODE_EXPORT void *NXMapRemove(NXMapTable *table, const void *key) code_MAP_AVAILABILITY;
    /* previous value or NULL is returned */
	
/* Iteration over all elements of a table consists in setting up an iteration state and then to progress until all entries have been visited.  An example of use for counting elements in a table is:
    unsigned	count = 0;
    const MyKey	*key;
    const MyValue	*value;
    NXMapState	state = NXInitMapState(table);
    while(NXNextMapState(table, &state, &key, &value)) {
	count++;
    }
*/

typedef struct {int index;} NXMapState code_MAP_AVAILABILITY;
    /* callers should not rely on actual contents of the struct */

CODE_EXPORT NXMapState NXInitMapState(NXMapTable *table) code_MAP_AVAILABILITY;

CODE_EXPORT int NXNextMapState(NXMapTable *table, NXMapState *state, const void **key, const void **value) code_MAP_AVAILABILITY;
    /* returns 0 when all elements have been visited */

/***************	Conveniences		***************/

CODE_EXPORT const NXMapTablePrototype NXPtrValueMapPrototype code_MAP_AVAILABILITY;
    /* hashing is pointer/integer hashing;
      isEqual is identity;
      free is no-op. */
CODE_EXPORT const NXMapTablePrototype NXStrValueMapPrototype code_MAP_AVAILABILITY;
    /* hashing is string hashing;
      isEqual is strcmp;
      free is no-op. */
CODE_EXPORT const NXMapTablePrototype NXObjectMapPrototype  code2_UNAVAILABLE;
    /* for objects; uses methods: hash, isEqual:, free, all for key. */

__END_DECLS

#endif /* _code_MAPTABLE_H_ */
