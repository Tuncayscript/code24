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

#include "code-private.h"

#include <malloc/malloc.h>
#include <assert.h>
#include "runtime.h"
#include "code-os.h"
#include "message.h"
#if SUPPORT_GC
#include "auto_zone.h"
#endif

enum {
    // external references to data segment objects all use this type
    code_XREF_TYPE_STATIC = 3,
    
    code_XREF_TYPE_MASK = 3
};

// Macros to encode/decode reference values and types.
#define encode_pointer_and_type(pointer, type) (~((uintptr_t)(pointer) | type))
#define decode_pointer(encoded) ((id)((~(encoded)) & (~code_XREF_TYPE_MASK)))
#define decode_type(encoded) ((~(encoded)) & code_XREF_TYPE_MASK)
#define encode_index_and_type(index, type) (~((index<<3) | type))
#define decode_index(encoded) ((~encoded)>>3)

#if SUPPORT_GC

typedef struct {
    code_xref_type_t    _type;         // type of list.
    dispatch_queue_t    _synchronizer; // a reader/write lock
    __strong void       **_buffer;     // a retained all pointers block
    size_t              _size;         // number of pointers that fit in _list (buffer size)
    size_t              _count;        // count of pointers in _list (in use count)
    size_t              _search;       // lowest index in list which *might* be unused
} external_ref_list;

static external_ref_list _xref_lists[2];

#define is_strong(list) (list->_type == code_XREF_STRONG)
#define is_weak(list) (list->_type == code_XREF_WEAK)

inline static size_t _index_for_type(code_xref_type_t ref_type) {
    assert(ref_type == code_XREF_STRONG || ref_type == code_XREF_WEAK);
    return (ref_type - 1);
}

static void _initialize_gc() {
    static dispatch_once_t init_guard;
    dispatch_once(&init_guard, ^{
        external_ref_list *_strong_list = &_xref_lists[_index_for_type(code_XREF_STRONG)];
        _strong_list->_type = code_XREF_STRONG;
        _strong_list->_synchronizer = dispatch_queue_create("code_XREF_STRONG synchronizer", DISPATCH_QUEUE_CONCURRENT);
        
        external_ref_list *_weak_list = &_xref_lists[_index_for_type(code_XREF_WEAK)];
        _weak_list->_type = code_XREF_WEAK;
        _weak_list->_synchronizer = dispatch_queue_create("code_XREF_WEAK synchronizer", DISPATCH_QUEUE_CONCURRENT);
    });
}

#define EMPTY_SLOT ((void*)0x1)

// grow the buffer by one page
static bool _grow_list(external_ref_list *list) {
    auto_memory_type_t memory_type = (is_strong(list) ? AUTO_MEMORY_ALL_POINTERS : AUTO_MEMORY_ALL_WEAK_POINTERS);
    size_t new_size = list->_size + PAGE_MAX_SIZE / sizeof(void *);
    // auto_realloc() has been enhanced to handle strong and weak memory.
    void **new_list = (void **)(list->_buffer ? malloc_zone_realloc(gc_zone, list->_buffer, new_size * sizeof(void *)) : auto_zone_allocate_object(gc_zone, new_size * sizeof(void *), memory_type, false, false));
    if (!new_list) _code_fatal("unable to allocate, size = %ld\n", new_size);
    
    list->_search = list->_size;
    // Fill the newly allocated space with empty slot tokens.
    for (size_t index = list->_size; index < new_size; ++index)
        new_list[index] = EMPTY_SLOT;
    list->_size = new_size;
    auto_zone_root_write_barrier(gc_zone, &list->_buffer, new_list);
    return true;
}


// find an unused slot in the list, growing the list if necessary
static size_t _find_unused_index(external_ref_list *list) {
    size_t index;
    if (list->_size == list->_count) {
        _grow_list(list);
    }
    // find the lowest unused index in _list
    index = list->_search;
    while (list->_buffer[index] != EMPTY_SLOT)
        index++;
    // mark the slot as no longer empty, good form for weak slots.
    list->_buffer[index] = NULL;
    return index;
}


// return the strong or weak list
inline static external_ref_list *_list_for_type(code_xref_type_t ref_type) {
    return &_xref_lists[_index_for_type(ref_type)];
}


// create a GC external reference
code_xref_t _object_addExternalReference_gc(id obj, code_xref_type_t ref_type) {
    _initialize_gc();
    __block size_t index;
    code_xref_t xref;
    
    if (auto_zone_is_valid_pointer(gc_zone, obj)) {
        external_ref_list *list = _list_for_type(ref_type);
        
        // writer lock
        dispatch_barrier_sync(list->_synchronizer, (dispatch_block_t)^{
            index = _find_unused_index(list);
            if (ref_type == code_XREF_STRONG) {
                auto_zone_set_write_barrier(gc_zone, &list->_buffer[index], obj);
            } else {
                auto_assign_weak_reference(gc_zone, obj, (const void **)&list->_buffer[index], NULL);
            }
            list->_count++;
        });
        xref = encode_index_and_type(index, ref_type);
    } else {
        // data segment object
        xref = encode_pointer_and_type(obj, code_XREF_TYPE_STATIC);
    }
    return xref;
}


id _object_readExternalReference_gc(code_xref_t ref) {
    _initialize_gc();
    __block id result;
    code_xref_type_t ref_type = decode_type(ref);
    if (ref_type != code_XREF_TYPE_STATIC) {
        size_t index = decode_index(ref);
        external_ref_list *list = _list_for_type(ref_type);
        
        dispatch_sync(list->_synchronizer, ^{
            if (index >= list->_size) {
                _code_fatal("attempted to resolve invalid external reference\n");
            }
            if (ref_type == code_XREF_STRONG)
                result = (id)list->_buffer[index];
            else
                result = (id)auto_read_weak_reference(gc_zone, &list->_buffer[index]);
            if (result == (id)EMPTY_SLOT)
                _code_fatal("attempted to resolve unallocated external reference\n");
        });
    } else {
        // data segment object
        result = decode_pointer(ref);
    }
    return result;
}


void _object_removeExternalReference_gc(code_xref_t ref) {
    _initialize_gc();
    code_xref_type_t ref_type = decode_type(ref);
    if (ref_type != code_XREF_TYPE_STATIC) {
        size_t index = decode_index(ref);
        external_ref_list *list = _list_for_type(ref_type);
        
        dispatch_barrier_sync(list->_synchronizer, ^{
            if (index >= list->_size) {
                _code_fatal("attempted to destroy invalid external reference\n");
            }
            id old_value;
            if (ref_type == code_XREF_STRONG) {
                old_value = (id)list->_buffer[index];
            } else {
                old_value = (id)auto_read_weak_reference(gc_zone, &list->_buffer[index]);
                auto_assign_weak_reference(gc_zone, NULL, (const void **)&list->_buffer[index], NULL);
            }
            list->_buffer[index] = EMPTY_SLOT;
            if (old_value == (id)EMPTY_SLOT)
                _code_fatal("attempted to destroy unallocated external reference\n");
            list->_count--;
            if (list->_search > index)
                list->_search = index;
        });
    } else {
        // nothing for data segment object
    }
}


// SUPPORT_GC
#endif


code_xref_t _object_addExternalReference_non_gc(id obj, code_xref_type_t ref_type) {
    switch (ref_type) {
        case code_XREF_STRONG:
            ((id(*)(id, SEL))code_msgSend)(obj, SEL_retain);
            break;
        case code_XREF_WEAK:
            break;
        default:
            _code_fatal("invalid external reference type: %d", (int)ref_type);
            break;
    }
    return encode_pointer_and_type(obj, ref_type);
}


id _object_readExternalReference_non_gc(code_xref_t ref) {
    id obj = decode_pointer(ref);
    return obj;
}


void _object_removeExternalReference_non_gc(code_xref_t ref) {
    id obj = decode_pointer(ref);
    code_xref_type_t ref_type = decode_type(ref);
    switch (ref_type) {
        case code_XREF_STRONG:
            ((void(*)(id, SEL))code_msgSend)(obj, SEL_release);
            break;
        case code_XREF_WEAK:
            break;
        default:
            _code_fatal("invalid external reference type: %d", (int)ref_type);
            break;
    }
}


uintptr_t _object_getExternalHash(id object) {
    return (uintptr_t)object;
}


#if SUPPORT_GC

// These functions are resolver functions in code-auto.mm.

#else

code_xref_t 
_object_addExternalReference(id obj, code_xref_t type) 
{
    return _object_addExternalReference_non_gc(obj, type);
}


id 
_object_readExternalReference(code_xref_t ref) 
{
    return _object_readExternalReference_non_gc(ref);
}


void 
_object_removeExternalReference(code_xref_t ref) 
{
    _object_removeExternalReference_non_gc(ref);
}

#endif
