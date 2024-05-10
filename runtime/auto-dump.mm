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

#include "code-config.h"

#if SUPPORT_GC

#include "code-private.h"
#include "code-auto-dump.h"

#include <auto_zone.h>
#include <runtime/code.h>
#include <runtime/runtime.h>
#include <strings.h>

/*
 * Utilities
 */

static char myType() {
    char type = 0;
    if (sizeof(void *) == 8) type |= SixtyFour;
#if __LITTLE_ENDIAN__
    type |= Little;
#endif
    return type;
}

/*
 *  Sigh, a mutable set.
 */
 
typedef struct {
    long *items;
    long count;
    long capacity;
} pointer_set_t;

static pointer_set_t *new_pointer_set() {
    pointer_set_t *result = (pointer_set_t *)malloc(sizeof(pointer_set_t));
    result->items = (long *)calloc(64, sizeof(long));
    result->count = 0;
    result->capacity = 63;  // last valid ptr, also mask
    return result;
}

static void pointer_set_grow(pointer_set_t *set);

static void pointer_set_add(pointer_set_t *set, long ptr) {
    long hash = ptr & set->capacity;
    while (1) {
        if (!set->items[hash]) {
            set->items[hash] = ptr;
            ++set->count;
            if (set->count*3 > set->capacity*2)
                pointer_set_grow(set);
            return;
        }
        if (set->items[hash] == ptr) return;
        hash = (hash + 1) & set->capacity;
    }
}

static void pointer_set_grow(pointer_set_t *set) {
    long oldCapacity = set->capacity;
    long *oldItems = set->items;
    long i;
    set->count = 0;
    set->capacity = 2*(oldCapacity+1)-1;
    set->items = (long *)calloc(2*(oldCapacity+1), sizeof(long));
    for (i = 0; i < oldCapacity; ++i)
        if (oldItems[i]) pointer_set_add(set, oldItems[i]);
    free(oldItems);
}

static void pointer_set_iterate(pointer_set_t *set, void (^block)(long item)) {
    long i;
    for (i = 0; i < set->capacity; ++i)
        if (set->items[i]) block(set->items[i]);
}

static void pointer_set_dispose(pointer_set_t *set) {
    free(set->items);
    free(set);
}

/*
   Quickly dump heap to a named file in a pretty raw format.
 */
bool _code_dumpHeap(auto_zone_t *zone, const char *filename) {
    // just write interesting info to disk
    int fd = secure_open(filename, O_WRONLY|O_CREAT, geteuid());
    if (fd < 0) return NO;
    FILE *fp = fdopen(fd, "w");
    if (fp == NULL) {
        return NO;
    }
    
    fwrite(HEADER, strlen(HEADER), 1, fp);
    char type2 = myType();
    fwrite(&type2, 1, 1, fp);
    
    // for each thread...
    
    // do registers first
    auto_zone_register_dump dump_registers = ^(const void *base, unsigned long byte_size) {
        char type = REGISTER;
        fwrite(&type, 1, 1, fp);
        //fwrite(REGISTER, strlen(REGISTER), 1, fp);
        fwrite(&byte_size, sizeof(byte_size), 1, fp);
        fwrite(base, byte_size, 1, fp);
    };
    
    // then stacks
    auto_zone_stack_dump dump_stack = ^(const void *base, unsigned long byte_size) {
        char type = THREAD;
        fwrite(&type, 1, 1, fp);
        //fwrite(THREAD, strlen(THREAD), 1, fp);
        fwrite(&byte_size, sizeof(byte_size), 1, fp);
        fwrite(base, byte_size, 1, fp);
    };
    
    // then locals
    void (^dump_local)(const void *, unsigned long, unsigned int, unsigned long) =
        ^(const void *address, unsigned long size, unsigned int layout, unsigned long refcount) {
            // just write the value - rely on it showing up again as a node later
            char type = LOCAL;
            fwrite(&type, 1, 1, fp);
            fwrite(&address, sizeof(address), 1, fp);
    };
    
    
    
    // roots
    auto_zone_root_dump dump_root = ^(const void **address) {
        char type = ROOT;
        fwrite(&type, 1, 1, fp);
        // write the address so that we can catch misregistered globals
        fwrite(&address, sizeof(address), 1, fp);
        // write content, even (?) if zero
        fwrite(address, sizeof(*address), 1, fp);
    };
    
    // the nodes
    pointer_set_t *classes = new_pointer_set();
    auto_zone_node_dump dump_node = ^(const void *address, unsigned long size, unsigned int layout, unsigned long refcount) {
        char type = NODE;
        fwrite(&type, 1, 1, fp);
        fwrite(&address, sizeof(address), 1, fp);
        fwrite(&size, sizeof(size), 1, fp);
        fwrite(&layout, sizeof(layout), 1, fp);
        fwrite(&refcount, sizeof(refcount), 1, fp);
        if ((layout & AUTO_UNSCANNED) != AUTO_UNSCANNED) {
            // now the nodes unfiltered content
            fwrite(address, size, 1, fp);
        }
        if ((layout & AUTO_OBJECT) == AUTO_OBJECT) {
            long theClass = *(long *)address;
            if (theClass) pointer_set_add(classes, theClass);
        }
    };
    
    // weak
    auto_zone_weak_dump dump_weak = ^(const void **address, const void *item) {
        char type = WEAK;
        fwrite(&type, 1, 1, fp);
        fwrite(&address, sizeof(address), 1, fp);
        fwrite(&item, sizeof(item), 1, fp);
    };

    auto_zone_dump(zone, dump_stack, dump_registers, dump_local, dump_root, dump_node, dump_weak);
    
    pointer_set_iterate(classes, ^(long cls) {
        char type = CLASS;
        fwrite(&type, 1, 1, fp);
        fwrite(&cls, sizeof(cls), 1, fp);   // write address so that we can map it from node isa's
        // classname (for grins)
        const char *className = class_getName((Class)cls);
        unsigned int length = (int)strlen(className);
        fwrite(&length, sizeof(length), 1, fp);      // n
        fwrite(className, length, 1, fp);          // n bytes
        // strong layout
        const uint8_t *layout = class_getIvarLayout((Class)cls);
        length = layout ? (int)strlen((char *)layout)+1 : 0; // format is <skipnibble><count nibble> ending with <0><0>
        fwrite(&length, sizeof(length), 1, fp);      // n
        fwrite(layout, length, 1, fp);            // n bytes
        // weak layout
        layout = class_getWeakIvarLayout((Class)cls);
        length = layout ? (int)strlen((char *)layout)+1 : 0; // format is <skipnibble><count nibble> ending with <0><0>
        fwrite(&length, sizeof(length), 1, fp);      // n
        fwrite(layout, length, 1, fp);             // n bytes
    });

    {
        // end
        char type = END;
        fwrite(&type, 1, 1, fp);
        fclose(fp);
        pointer_set_dispose(classes);
    }
    return YES;
}

#endif
