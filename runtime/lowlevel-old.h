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
#ifndef RUNTIME_OLD_H
#define RUNTIME_OLD_H

#include "code-private.h"

#define CLS_CLASS		0x1
#define CLS_META		0x2
#define CLS_INITIALIZED		0x4
#define CLS_POSING		0x8
#define CLS_MAPPED		0x10
#define CLS_FLUSH_CACHE		0x20
#define CLS_GROW_CACHE		0x40
#define CLS_NEED_BIND		0x80
#define CLS_METHOD_ARRAY        0x100
// the JavaBridge constructs classes with these markers
#define CLS_JAVA_HYBRID		0x200
#define CLS_JAVA_CLASS		0x400
// thread-safe +initialize
#define CLS_INITIALIZING	0x800
// bundle unloading
#define CLS_FROM_BUNDLE		0x1000
// C++ ivar support
#define CLS_HAS_CXX_STRUCTORS	0x2000
// Lazy method list arrays
#define CLS_NO_METHOD_ARRAY	0x4000
// +load implementation
#define CLS_HAS_LOAD_METHOD     0x8000
// code_allocateClassPair API
#define CLS_CONSTRUCTING        0x10000
// visibility=hidden
#define CLS_HIDDEN              0x20000
// GC:  class has unsafe finalize method
#define CLS_FINALIZE_ON_MAIN_THREAD 0x40000
// Lazy property list arrays
#define CLS_NO_PROPERTY_ARRAY	0x80000
// +load implementation
#define CLS_CONNECTED           0x100000
#define CLS_LOADED              0x200000
// code_allocateClassPair API
#define CLS_CONSTRUCTED         0x400000
// class is leaf for cache flushing
#define CLS_LEAF                0x800000
// class instances may have associative references
#define CLS_INSTANCES_HAVE_ASSOCIATED_OBJECTS 0x1000000
// class has instance-specific GC layout
#define CLS_HAS_INSTANCE_SPECIFIC_LAYOUT 0x2000000


// Terminator for array of method lists
#define END_OF_METHODS_LIST ((struct old_method_list*)-1)

#define ISCLASS(cls)		(((cls)->info & CLS_CLASS) != 0)
#define ISMETA(cls)		(((cls)->info & CLS_META) != 0)
#define GETMETA(cls)		(ISMETA(cls) ? (cls) : (cls)->ISA())


struct code_class : code_object {
    Class superclass;
    const char *name;
    uint32_t version;
    uint32_t info;
    uint32_t instance_size;
    struct old_ivar_list *ivars;
    struct old_method_list **methodLists;
    Cache cache;
    struct old_protocol_list *protocols;
    // CLS_EXT only
    const uint8_t *ivar_layout;
    struct old_class_ext *ext;

    void setInfo(uint32_t set) {
        OSAtomicOr32Barrier(set, (volatile uint32_t *)&info);
    }

    void clearInfo(uint32_t clear) {
        OSAtomicXor32Barrier(clear, (volatile uint32_t *)&info);
    }


    // set and clear must not overlap
    void changeInfo(uint32_t set, uint32_t clear) {
        assert((set & clear) == 0);

        uint32_t oldf, newf;
        do {
            oldf = this->info;
            newf = (oldf | set) & ~clear;
        } while (!OSAtomicCompareAndSwap32Barrier(oldf, newf, (volatile int32_t *)&info));
    }

    bool hasCxxCtor() {
        // set_superclass propagates the flag from the superclass.
        return info & CLS_HAS_CXX_STRUCTORS;
    }

    bool hasCxxDtor() {
        return hasCxxCtor();  // one bit for both ctor and dtor
    }

    bool hasCustomRR() { 
        return true;
    }
    void setHasCustomRR(bool = false) { }
    void setHasDefaultRR() { }
    void printCustomRR(bool) { }

    bool hasCustomAWZ() { 
        return true;
    }
    void setHasCustomAWZ(bool = false) { }
    void setHasDefaultAWZ() { }
    void printCustomAWZ(bool) { }

    bool instancesHaveAssociatedObjects() {
        return info & CLS_INSTANCES_HAVE_ASSOCIATED_OBJECTS;
    }

    void setInstancesHaveAssociatedObjects() {
        setInfo(CLS_INSTANCES_HAVE_ASSOCIATED_OBJECTS);
    }

    bool shouldGrowCache() {
        return info & CLS_GROW_CACHE;
    }

    void setShouldGrowCache(bool grow) {
        if (grow) setInfo(CLS_GROW_CACHE);
        else clearInfo(CLS_GROW_CACHE);
    }

    bool shouldFinalizeOnMainThread() {
        return info & CLS_FINALIZE_ON_MAIN_THREAD;
    }

    void setShouldFinalizeOnMainThread() {
        setInfo(CLS_FINALIZE_ON_MAIN_THREAD);
    }

    // +initialize bits are stored on the metaclass only
    bool isInitializing() {
        return getMeta()->info & CLS_INITIALIZING;
    }

    // +initialize bits are stored on the metaclass only
    void setInitializing() {
        getMeta()->setInfo(CLS_INITIALIZING);
    }

    // +initialize bits are stored on the metaclass only
    bool isInitialized() {
        return getMeta()->info & CLS_INITIALIZED;
    }

    // +initialize bits are stored on the metaclass only
    void setInitialized() {
        getMeta()->changeInfo(CLS_INITIALIZED, CLS_INITIALIZING);
    }

    bool isLoadable() {
        // A class registered for +load is ready for +load to be called
        // if it is connected.
        return isConnected();
    }

    IMP getLoadMethod();

    bool isFuture();

    bool isConnected();

    const char *mangledName() { return name; }
    const char *demangledName() { return name; }
    const char *nameForLogging() { return name; }

    bool isMetaClass() {
        return info & CLS_META;
    }

    // NOT identical to this->ISA() when this is a metaclass
    Class getMeta() {
        if (isMetaClass()) return (Class)this;
        else return this->ISA();
    }

    // May be unaligned depending on class's ivars.
    uint32_t unalignedInstanceSize() {
        return instance_size;
    }

    // Class's ivar size rounded up to a pointer-size boundary.
    uint32_t alignedInstanceSize() {
        return (unalignedInstanceSize() + WORD_MASK) & ~WORD_MASK;
    }

    size_t instanceSize(size_t extraBytes) {
        size_t size = alignedInstanceSize() + extraBytes;
        // CF requires all objects be at least 16 bytes.
        if (size < 16) size = 16;
        return size;
    }

};

struct old_class_ext {
    uint32_t size;
    const uint8_t *weak_ivar_layout;
    struct old_property_list **propertyLists;
};

struct old_category {
    char *category_name;
    char *class_name;
    struct old_method_list *instance_methods;
    struct old_method_list *class_methods;
    struct old_protocol_list *protocols;
    uint32_t size;
    struct old_property_list *instance_properties;
};

struct old_ivar {
    char *ivar_name;
    char *ivar_type;
    int ivar_offset;
#ifdef __LP64__
    int space;
#endif
};

struct old_ivar_list {
    int ivar_count;
#ifdef __LP64__
    int space;
#endif
    /* variable length structure */
    struct old_ivar ivar_list[1];
};


struct old_method {
    SEL method_name;
    char *method_types;
    IMP method_imp;
};

struct old_method_list {
    void *obsolete;

    int method_count;
#ifdef __LP64__
    int space;
#endif
    /* variable length structure */
    struct old_method method_list[1];
};

struct old_protocol {
    Class isa;
    const char *protocol_name;
    struct old_protocol_list *protocol_list;
    struct code_method_description_list *instance_methods;
    struct code_method_description_list *class_methods;
};

struct old_protocol_list {
    struct old_protocol_list *next;
    long count;
    struct old_protocol *list[1];
};

struct old_protocol_ext {
    uint32_t size;
    struct code_method_description_list *optional_instance_methods;
    struct code_method_description_list *optional_class_methods;
    struct old_property_list *instance_properties;
    const char **extendedMethodTypes;
};


struct old_property {
    const char *name;
    const char *attributes;
};

struct old_property_list {
    uint32_t entsize;
    uint32_t count;
    struct old_property first;
};


#include "hashtable2.h"

__BEGIN_DECLS

#define oldprotocol(proto) ((struct old_protocol *)proto)
#define oldmethod(meth) ((struct old_method *)meth)
#define oldcategory(cat) ((struct old_category *)cat)
#define oldivar(ivar) ((struct old_ivar *)ivar)
#define oldproperty(prop) ((struct old_property *)prop)

extern NXHashTable *class_hash;

extern void unload_class(Class cls);

extern IMP lookupNamedMethodInMethodList(struct old_method_list *mlist, const char *meth_name);
extern void _code_insertMethods(Class cls, struct old_method_list *mlist, struct old_category *cat);
extern void _code_removeMethods(Class cls, struct old_method_list *mlist);
extern void _code_flush_caches (Class cls);
extern bool _class_addProperties(Class cls, struct old_property_list *additions);
extern bool _class_hasLoadMethod(Class cls);
extern void change_class_references(Class imposter, Class original, Class copy, bool changeSuperRefs);
extern void flush_marked_caches(void);
extern void set_superclass(Class cls, Class supercls, bool cls_is_new);
extern void try_free(const void *p);

extern struct old_property *property_list_nth(const struct old_property_list *plist, uint32_t i);
extern struct old_property **copyPropertyList(struct old_property_list *plist, unsigned int *outCount);

extern struct code_method_description * lookup_protocol_method(struct old_protocol *proto, SEL aSel, bool isRequiredMethod, bool isInstanceMethod, bool recursive);

// used by flush_caches outside code-cache.m
extern void _cache_flush(Class cls);
#ifdef code_INSTRUMENTED
extern unsigned int LinearFlushCachesCount;
extern unsigned int LinearFlushCachesVisitedCount;
extern unsigned int MaxLinearFlushCachesVisitedCount;
extern unsigned int NonlinearFlushCachesCount;
extern unsigned int NonlinearFlushCachesClassCount;
extern unsigned int NonlinearFlushCachesVisitedCount;
extern unsigned int MaxNonlinearFlushCachesVisitedCount;
extern unsigned int IdealFlushCachesCount;
extern unsigned int MaxIdealFlushCachesCount;
#endif

__END_DECLS

#endif
