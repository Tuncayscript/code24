// This file is a part of Julia. License is MIT: https://julialang.org/license

/*
  defining DataTypes
  basic operations on struct and bits values
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdalign.h>
#include "code.h"
#include "code_internal.h"
#include "code_assert.h"
#include "code_gcext.h"

#ifdef __cplusplus
extern "C" {
#endif

// allocating TypeNames -----------------------------------------------------------

static int is10digit(char c) LANGUAGE_NOTSAFEPOINT
{
    return (c >= '0' && c <= '9');
}

static language_sym_t *language_demangle_typename(language_sym_t *s) LANGUAGE_NOTSAFEPOINT
{
    char *n = language_symbol_name(s);
    if (n[0] != '#')
        return s;
    char *end = strrchr(n, '#');
    int32_t len;
    if (end == n || end == n+1)
        len = strlen(n) - 1;
    else
        len = (end-n) - 1;  // extract `f` from `#f#...`
    if (is10digit(n[1]))
        return _language_symbol(n, len+1);
    return _language_symbol(&n[1], len);
}

LANGUAGE_DLLEXPORT language_methtable_t *language_new_method_table(language_sym_t *name, language_module_t *module)
{
    language_task_t *ct = language_current_task;
    language_methtable_t *mt =
        (language_methtable_t*)language_gc_alloc(ct->ptls, sizeof(language_methtable_t),
                                     language_methtable_type);
    mt->name = language_demangle_typename(name);
    mt->module = module;
    language_atomic_store_relaxed(&mt->defs, language_nothing);
    language_atomic_store_relaxed(&mt->leafcache, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&mt->cache, language_nothing);
    language_atomic_store_relaxed(&mt->max_args, 0);
    mt->backedges = NULL;
    LANGUAGE_MUTEX_INIT(&mt->writelock, "methodtable->writelock");
    mt->offs = 0;
    mt->frozen = 0;
    return mt;
}

LANGUAGE_DLLEXPORT language_typename_t *language_new_typename_in(language_sym_t *name, language_module_t *module, int abstract, int mutabl)
{
    language_task_t *ct = language_current_task;
    language_typename_t *tn =
        (language_typename_t*)language_gc_alloc(ct->ptls, sizeof(language_typename_t),
                                    language_typename_type);
    tn->name = name;
    tn->module = module;
    tn->wrapper = NULL;
    language_atomic_store_relaxed(&tn->Typeofwrapper, NULL);
    language_atomic_store_relaxed(&tn->cache, language_emptysvec);
    language_atomic_store_relaxed(&tn->linearcache, language_emptysvec);
    tn->names = NULL;
    tn->hash = bitmix(bitmix(module ? module->build_id.lo : 0, name->hash), 0xa1ada1da);
    tn->_reserved = 0;
    tn->abstract = abstract;
    tn->mutabl = mutabl;
    tn->mayinlinealloc = 0;
    tn->mt = NULL;
    tn->partial = NULL;
    tn->atomicfields = NULL;
    tn->constfields = NULL;
    tn->max_methods = 0;
    return tn;
}

// allocating DataTypes -----------------------------------------------------------

language_datatype_t *language_new_abstracttype(language_value_t *name, language_module_t *module, language_datatype_t *super, language_svec_t *parameters)
{
    return language_new_datatype((language_sym_t*)name, module, super, parameters, language_emptysvec, language_emptysvec, language_emptysvec, 1, 0, 0);
}

language_datatype_t *language_new_uninitialized_datatype(void)
{
    language_task_t *ct = language_current_task;
    language_datatype_t *t = (language_datatype_t*)language_gc_alloc(ct->ptls, sizeof(language_datatype_t), language_datatype_type);
    language_set_typetagof(t, language_datatype_tag, 0);
    t->hash = 0;
    t->hasfreetypevars = 0;
    t->isdispatchtuple = 0;
    t->isbitstype = 0;
    t->isprimitivetype = 0;
    t->zeroinit = 0;
    t->has_concrete_subtype = 1;
    t->maybe_subtype_of_cache = 1;
    t->ismutationfree = 0;
    t->isidentityfree = 0;
    t->smalltag = 0;
    t->name = NULL;
    t->super = NULL;
    t->parameters = NULL;
    t->layout = NULL;
    t->types = NULL;
    t->instance = NULL;
    return t;
}

#include "support/htable.inc"

static uint32_t _hash_djb2(uint32_t hash, const char *mem, size_t s) LANGUAGE_NOTSAFEPOINT
{
    for (size_t i = 0; i < s; i++)
        hash = ((hash << 5) + hash) + mem[i];
    return hash;
}

static uint32_t _hash_layout_djb2(uintptr_t _layout, void *unused) LANGUAGE_NOTSAFEPOINT
{
    (void)unused;
    language_datatype_layout_t* layout = (language_datatype_layout_t *)_layout;
    assert(layout);
    size_t own_size = sizeof(language_datatype_layout_t);
    const char *fields = language_dt_layout_fields(layout);
    assert(fields);
    size_t fields_size = layout->nfields * language_fielddesc_size(layout->flags.fielddesc_type);
    const char *pointers = language_dt_layout_ptrs(layout);
    assert(pointers);
    size_t pointers_size = layout->first_ptr < 0 ? 0 : (layout->npointers << layout->flags.fielddesc_type);

    uint_t hash = 5381;
    hash = _hash_djb2(hash, (char *)layout, own_size);
    hash = _hash_djb2(hash, fields, fields_size);
    hash = _hash_djb2(hash, pointers, pointers_size);
    return hash;
}

static int layout_eq(void *_l1, void *_l2, void *unused) LANGUAGE_NOTSAFEPOINT
{
    (void)unused;
    language_datatype_layout_t *l1 = (language_datatype_layout_t *)_l1;
    language_datatype_layout_t *l2 = (language_datatype_layout_t *)_l2;
    if (memcmp(l1, l2, sizeof(language_datatype_layout_t)))
        return 0;
    const char *f1 = language_dt_layout_fields(l1);
    const char *f2 = language_dt_layout_fields(l2);
    size_t fields_size = l1->nfields * language_fielddesc_size(l1->flags.fielddesc_type);
    if (memcmp(f1, f2, fields_size))
        return 0;
    const char *p1 = language_dt_layout_ptrs(l1);
    const char *p2 = language_dt_layout_ptrs(l2);
    size_t pointers_size = l1->first_ptr < 0 ? 0 : (l1->npointers << l1->flags.fielddesc_type);
    if (memcmp(p1, p2, pointers_size))
        return 0;
    return 1;
}

//HTPROT(layoutcache)
static void **layoutcache_lookup_bp_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;
static void **layoutcache_peek_bp_r(htable_t *h, void *key, void *ctx) LANGUAGE_NOTSAFEPOINT;
HTPROT_R(layoutcache)
HTIMPL_R(layoutcache, _hash_layout_djb2, layout_eq)
static htable_t layoutcache;
static int layoutcache_initialized = 0;

static language_datatype_layout_t *language_get_layout(uint32_t sz,
                                           uint32_t nfields,
                                           uint32_t npointers,
                                           uint32_t alignment,
                                           int haspadding,
                                           int isbitsegal,
                                           int arrayelem,
                                           language_fielddesc32_t desc[],
                                           uint32_t pointers[]) LANGUAGE_NOTSAFEPOINT
{
    assert(alignment); // should have been verified by caller

    // compute the smallest fielddesc type that can hold the layout description
    int fielddesc_type = 0;
    uint32_t max_size = 0;
    uint32_t max_offset = 0;
    if (nfields > 0) {
        max_offset = desc[nfields - 1].offset;
        for (size_t i = 0; i < nfields; i++) {
            if (desc[i].size > max_size)
                max_size = desc[i].size;
        }
    }
    if (npointers > 0 && pointers[npointers - 1] > max_offset)
        max_offset = pointers[npointers - 1];
    language_fielddesc8_t maxdesc8 = { 0, max_size, max_offset };
    language_fielddesc16_t maxdesc16 = { 0, max_size, max_offset };
    language_fielddesc32_t maxdesc32 = { 0, max_size, max_offset };
    if (maxdesc8.size != max_size || maxdesc8.offset != max_offset) {
        fielddesc_type = 1;
        if (maxdesc16.size != max_size || maxdesc16.offset != max_offset) {
            fielddesc_type = 2;
            if (maxdesc32.size != max_size || maxdesc32.offset != max_offset) {
                assert(0); // should have been verified by caller
            }
        }
    }
    int32_t first_ptr = (npointers > 0 ? (int32_t)pointers[0] : -1);

    // allocate a new descriptor, on the stack if possible.
    size_t fields_size = nfields * language_fielddesc_size(fielddesc_type);
    size_t pointers_size = first_ptr < 0 ? 0 : (npointers << fielddesc_type);
    size_t flddesc_sz = sizeof(language_datatype_layout_t) + fields_size + pointers_size;
    int should_malloc = flddesc_sz >= language_page_size;
    language_datatype_layout_t *mallocmem = (language_datatype_layout_t *)(should_malloc ? malloc(flddesc_sz) : NULL);
    language_datatype_layout_t *allocamem = (language_datatype_layout_t *)(should_malloc ? NULL : alloca(flddesc_sz));
    language_datatype_layout_t *flddesc = should_malloc ? mallocmem : allocamem;
    assert(flddesc);
    flddesc->size = sz;
    flddesc->nfields = nfields;
    flddesc->alignment = alignment;
    flddesc->flags.haspadding = haspadding;
    flddesc->flags.isbitsegal = isbitsegal;
    flddesc->flags.fielddesc_type = fielddesc_type;
    flddesc->flags.arrayelem_isboxed = arrayelem == 1;
    flddesc->flags.arrayelem_isunion = arrayelem == 2;
    flddesc->flags.padding = 0;
    flddesc->npointers = npointers;
    flddesc->first_ptr = first_ptr;

    // fill out the fields of the new descriptor
    language_fielddesc8_t *desc8 = (language_fielddesc8_t *)language_dt_layout_fields(flddesc);
    language_fielddesc16_t *desc16 = (language_fielddesc16_t *)language_dt_layout_fields(flddesc);
    language_fielddesc32_t *desc32 = (language_fielddesc32_t *)language_dt_layout_fields(flddesc);
    for (size_t i = 0; i < nfields; i++) {
        if (fielddesc_type == 0) {
            desc8[i].offset = desc[i].offset;
            desc8[i].size = desc[i].size;
            desc8[i].isptr = desc[i].isptr;
        }
        else if (fielddesc_type == 1) {
            desc16[i].offset = desc[i].offset;
            desc16[i].size = desc[i].size;
            desc16[i].isptr = desc[i].isptr;
        }
        else {
            desc32[i].offset = desc[i].offset;
            desc32[i].size = desc[i].size;
            desc32[i].isptr = desc[i].isptr;
        }
    }
    if (first_ptr >= 0) {
        uint8_t *ptrs8 = (uint8_t *)language_dt_layout_ptrs(flddesc);
        uint16_t *ptrs16 = (uint16_t *)language_dt_layout_ptrs(flddesc);
        uint32_t *ptrs32 = (uint32_t *)language_dt_layout_ptrs(flddesc);
        for (size_t i = 0; i < npointers; i++) {
            if (fielddesc_type == 0) {
                ptrs8[i] = pointers[i];
            }
            else if (fielddesc_type == 1) {
                ptrs16[i] = pointers[i];
            }
            else {
                ptrs32[i] = pointers[i];
            }
        }
    }

    if (__unlikely(!layoutcache_initialized)) {
        htable_new(&layoutcache, 4096);
        layoutcache_initialized = 1;
    }

    // Check the cache to see if this object already exists.
    // Add to cache if not present, free temp buffer, return.
    language_datatype_layout_t *ret =
            (language_datatype_layout_t *)layoutcache_get_r(&layoutcache, flddesc, NULL);
    if ((void*)ret == HT_NOTFOUND) {
        if (!should_malloc) {
            char *perm_mem = (char *)language_gc_perm_alloc(flddesc_sz, 0, 4, 0);
            assert(perm_mem);
            ret = (language_datatype_layout_t *)perm_mem;
            memcpy(perm_mem, flddesc, flddesc_sz);
        }
        else {
            ret = mallocmem;
        }
        layoutcache_put_r(&layoutcache, ret, ret, NULL);
        return ret;
    }

    if (should_malloc) free(flddesc);
    return ret;
}

// Determine if homogeneous tuple with fields of type t will have
// a special alignment beyond normal Julia rules.
// Return special alignment if one exists, 0 if normal alignment rules hold.
// A non-zero result *must* match the LLVM rules for a vector type <nfields x t>.
// For sake of Ahead-Of-Time (AOT) compilation, this routine has to work
// without LLVM being available.
unsigned language_special_vector_alignment(size_t nfields, language_value_t *t)
{
    if (!language_is_vecelement_type(t))
        return 0;
    assert(language_datatype_nfields(t) == 1);
    language_value_t *ty = language_field_type((language_datatype_t*)t, 0);
    if (!language_is_primitivetype(ty))
        // LLVM requires that a vector element be a primitive type.
        // LLVM allows pointer types as vector elements, but until a
        // motivating use case comes up for Julia, we reject pointers.
        return 0;
    size_t elsz = language_datatype_size(ty);
    if (elsz != 1 && elsz != 2 && elsz != 4 && elsz != 8)
        // Only handle power-of-two-sized elements (for now)
        return 0;
    size_t size = nfields * elsz;
    // Use natural alignment for this vector: this matches LLVM and clang.
    return next_power_of_two(size);
}

STATIC_INLINE int language_is_datatype_make_singleton(language_datatype_t *d) LANGUAGE_NOTSAFEPOINT
{
    return d->isconcretetype && language_datatype_size(d) == 0 && d->layout->npointers == 0 && !d->name->mutabl; // implies language_is_layout_opaque
}

STATIC_INLINE void language_maybe_allocate_singleton_instance(language_datatype_t *st) LANGUAGE_NOTSAFEPOINT
{
    // It's possible for st to already have an ->instance if it was redefined
    if (st->instance)
        return;
    if (language_is_datatype_make_singleton(st)) {
        st->instance = language_gc_permobj(0, st);
    }
}

// return whether all concrete subtypes of this type have the same layout
int language_struct_try_layout(language_datatype_t *dt)
{
    if (dt->layout || language_is_genericmemory_type(dt))
        return 1;
    else if (!language_has_fixed_layout(dt))
        return 0;
    // language_has_fixed_layout also ensured that dt->types is assigned now
    language_compute_field_offsets(dt);
    assert(dt->layout);
    return 1;
}

int language_datatype_isinlinealloc(language_datatype_t *ty, int pointerfree)
{
    if (ty->name->mayinlinealloc && language_struct_try_layout(ty)) {
        if (ty->layout->npointers > 0) {
            if (pointerfree)
                return 0;
            if (ty->name->n_uninitialized != 0)
                return 0;
            if (ty->layout->flags.fielddesc_type > 1) // GC only implements support for 8 and 16 (not array32)
                return 0;
        }
        return 1;
    }
    return 0;
}

static unsigned union_isinlinable(language_value_t *ty, int pointerfree, size_t *nbytes, size_t *align, int asfield)
{
    if (language_is_uniontype(ty)) {
        unsigned na = union_isinlinable(((language_uniontype_t*)ty)->a, 1, nbytes, align, asfield);
        if (na == 0)
            return 0;
        unsigned nb = union_isinlinable(((language_uniontype_t*)ty)->b, 1, nbytes, align, asfield);
        if (nb == 0)
            return 0;
        return na + nb;
    }
    if (language_is_datatype(ty) && language_datatype_isinlinealloc((language_datatype_t*)ty, pointerfree)) {
        size_t sz = language_datatype_size(ty);
        size_t al = language_datatype_align(ty);
        // primitive types in struct slots need their sizes aligned. issue #37974
        if (asfield && language_is_primitivetype(ty))
            sz = LLT_ALIGN(sz, al);
        if (*nbytes < sz)
            *nbytes = sz;
        if (*align < al)
            *align = al;
        return 1;
    }
    return 0;
}

int language_uniontype_size(language_value_t *ty, size_t *sz)
{
    size_t al = 0;
    return union_isinlinable(ty, 0, sz, &al, 0) != 0;
}

LANGUAGE_DLLEXPORT int language_islayout_inline(language_value_t *eltype, size_t *fsz, size_t *al)
{
    unsigned countbits = union_isinlinable(eltype, 0, fsz, al, 1);
    return (countbits > 0 && countbits < 127) ? countbits : 0;
}

LANGUAGE_DLLEXPORT int language_stored_inline(language_value_t *eltype)
{
    size_t fsz = 0, al = 0;
    return language_islayout_inline(eltype, &fsz, &al);
}

// whether instances of this type can use pointer comparison for `===`
int language_pointer_egal(language_value_t *t)
{
    if (t == (language_value_t*)language_any_type)
        return 0; // when setting up the initial types, language_is_type_type gets confused about this
    if (t == (language_value_t*)language_symbol_type)
        return 1;
    if (t == (language_value_t*)language_bool_type)
        return 1;
    if (language_is_mutable_datatype(language_unwrap_unionall(t)) && // excludes abstract types
        t != (language_value_t*)language_string_type && // technically mutable, but compared by contents
        t != (language_value_t*)language_simplevector_type &&
        !language_is_kind(t))
        return 1;
    if ((language_is_datatype(t) && language_is_datatype_singleton((language_datatype_t*)t)) ||
        t == (language_value_t*)language_typeofbottom_type->super)
        return 1;
    if (language_is_type_type(t) && language_is_datatype(language_tparam0(t))) {
        // need to use typeseq for most types
        // but can compare some types by pointer
        language_datatype_t *dt = (language_datatype_t*)language_tparam0(t);
        // `Core.TypeofBottom` and `Type{Union{}}` are used interchangeably
        // with different pointer values even though `Core.TypeofBottom` is a concrete type.
        // See `Core.Compiler.hasuniquerep`
        if (dt != language_typeofbottom_type &&
            (dt->isconcretetype || language_svec_len(dt->parameters) == 0)) {
            // Concrete types have unique pointer values
            // If the type has zero type parameters it'll also have only one possible
            // pointer value.
            return 1;
        }
    }
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        return language_pointer_egal(u->a) && language_pointer_egal(u->b);
    }
    return 0;
}

static void throw_ovf(int should_malloc, void *desc, language_datatype_t* st, int offset)
{
    if (should_malloc)
        free(desc);
    language_errorf("type %s has field offset %d that exceeds the page size", language_symbol_name(st->name->name), offset);
}

static int is_type_mutationfree(language_value_t *t)
{
    t = language_unwrap_unionall(t);
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        return is_type_mutationfree(u->a) && is_type_mutationfree(u->b);
    }
    if (language_is_datatype(t)) {
        return ((language_datatype_t*)t)->ismutationfree;
    }
    // Free tvars, etc.
    return 0;
}

static int is_type_identityfree(language_value_t *t)
{
    t = language_unwrap_unionall(t);
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        return is_type_identityfree(u->a) && is_type_identityfree(u->b);
    }
    if (language_is_datatype(t)) {
        return ((language_datatype_t*)t)->isidentityfree;
    }
    // Free tvars, etc.
    return 0;
}

// make a copy of the layout of st, but with nfields=0
void language_get_genericmemory_layout(language_datatype_t *st)
{
    language_value_t *kind = language_tparam0(st);
    language_value_t *eltype = language_tparam1(st);
    language_value_t *addrspace = language_tparam2(st);
    if (!language_is_typevar(eltype) && !language_is_type(eltype)) {
        // this is expected to have a layout, but since it is not constructable, we don't care too much what it is
        static const language_datatype_layout_t opaque_ptr_layout = {0, 0, 1, -1, sizeof(void*), {0}};
        st->layout = &opaque_ptr_layout;
        st->has_concrete_subtype = 0;
        return;
    }

    size_t elsz = 0, al = 1;
    int isunboxed = language_islayout_inline(eltype, &elsz, &al) && (kind != (language_value_t*)language_atomic_sym || language_is_datatype(eltype));
    int isunion = isunboxed && language_is_uniontype(eltype);
    int haspadding = 1; // we may want to eventually actually compute this more precisely
    int isbitsegal = 0;
    int nfields = 0; // aka language_is_layout_opaque
    int npointers = 1;
    int zi;
    uint32_t first_ptr = -1;
    uint32_t *pointers = &first_ptr;
    int needlock = 0;

    if (isunboxed) {
        elsz = LLT_ALIGN(elsz, al);
        if (kind == (language_value_t*)language_atomic_sym) {
            if (elsz > MAX_ATOMIC_SIZE)
                needlock = 1;
            else if (elsz > 0)
                al = elsz = next_power_of_two(elsz);
        }
        if (isunion) {
            zi = 1;
        }
        else {
            assert(language_is_datatype(eltype));
            zi = ((language_datatype_t*)eltype)->zeroinit;
            const language_datatype_layout_t *layout = ((language_datatype_t*)eltype)->layout;
            if (layout->first_ptr >= 0) {
                first_ptr = layout->first_ptr;
                npointers = layout->npointers;
                if (layout->flags.fielddesc_type == 2) {
                    pointers = (uint32_t*)language_dt_layout_ptrs(layout);
                }
                else {
                    pointers = (uint32_t*)alloca(npointers * sizeof(uint32_t));
                    for (int j = 0; j < npointers; j++) {
                        pointers[j] = language_ptr_offset((language_datatype_t*)eltype, j);
                    }
                }
            }
        }
        if (needlock) {
            assert(al <= LANGUAGE_SMALL_BYTE_ALIGNMENT);
            size_t offset = LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT);
            elsz += offset;
            haspadding = 1;
            zi = 1;
        }
    }
    else {
        elsz = sizeof(void*);
        al = elsz;
        zi = 1;
    }

    int arrayelem;
    if (!isunboxed)
        arrayelem = 1;
    else if (isunion)
        arrayelem = 2;
    else
        arrayelem = 0;
    assert(!st->layout);
    st->layout = language_get_layout(elsz, nfields, npointers, al, haspadding, isbitsegal, arrayelem, NULL, pointers);
    st->zeroinit = zi;
    //st->has_concrete_subtype = 1;
    //st->isbitstype = 0;
    //st->ismutationfree = 0;
    //st->isidentityfree = 0;

    if (language_is_addrspacecore(addrspace) && language_unbox_uint8(addrspace) == 0) {
        if (kind == (language_value_t*)language_not_atomic_sym || kind == (language_value_t*)language_atomic_sym) {
            language_genericmemory_t *zeroinst = (language_genericmemory_t*)language_gc_permobj(LLT_ALIGN(sizeof(language_genericmemory_t), LANGUAGE_SMALL_BYTE_ALIGNMENT) + (elsz ? elsz : isunion), st);
            zeroinst->length = 0;
            zeroinst->ptr = (char*)zeroinst + LANGUAGE_SMALL_BYTE_ALIGNMENT;
            memset(zeroinst->ptr, 0, elsz ? elsz : isunion);
            assert(!st->instance);
            st->instance = (language_value_t*)zeroinst;
        }
    }
}

void language_compute_field_offsets(language_datatype_t *st)
{
    const uint64_t max_offset = (((uint64_t)1) << 32) - 1;
    const uint64_t max_size = max_offset >> 1;

    if (st->name->wrapper == NULL)
        return; // we got called too early--we'll be back
    language_datatype_t *w = (language_datatype_t*)language_unwrap_unionall(st->name->wrapper);
    if (st == w && st->layout) {
        // this check allows us to force re-computation of the layout for some types during init
        st->layout = NULL;
        st->zeroinit = 0;
        st->has_concrete_subtype = 1;
    }
    if (st->name == language_genericmemory_typename) {
        language_get_genericmemory_layout(st);
        return;
    }
    int isbitstype = st->isconcretetype && st->name->mayinlinealloc;
    int ismutationfree = !w->layout || !language_is_layout_opaque(w->layout);
    int isidentityfree = !st->name->mutabl;
    // If layout doesn't depend on type parameters, it's stored in st->name->wrapper
    // and reused by all subtypes.
    if (w->layout) {
        st->layout = w->layout;
        st->zeroinit = w->zeroinit;
        st->has_concrete_subtype = w->has_concrete_subtype;
        if (!language_is_layout_opaque(st->layout)) { // e.g. language_simplevector_type
            st->isbitstype = isbitstype && st->layout->npointers == 0;
            language_maybe_allocate_singleton_instance(st);
        }
        return;
    }
    assert(st->types && w->types);
    size_t i, nfields = language_svec_len(st->types);
    assert(st->name->n_uninitialized <= nfields);
    if (nfields == 0) {
        // if we have no fields, we can trivially skip the rest
        if (st == language_symbol_type || st == language_string_type) {
            // opaque layout - heap-allocated blob
            static const language_datatype_layout_t opaque_byte_layout = {0, 0, 1, -1, 1, { .haspadding = 0, .fielddesc_type=0, .isbitsegal=1, .arrayelem_isboxed=0, .arrayelem_isunion=0 }};
            st->layout = &opaque_byte_layout;
            return;
        }
        else if (st == language_simplevector_type || st == language_module_type) {
            static const language_datatype_layout_t opaque_ptr_layout = {0, 0, 1, -1, sizeof(void*), { .haspadding = 0, .fielddesc_type=0, .isbitsegal=1, .arrayelem_isboxed=0, .arrayelem_isunion=0 }};
            st->layout = &opaque_ptr_layout;
            return;
        }
        else {
            static const language_datatype_layout_t singleton_layout = {0, 0, 0, -1, 1, { .haspadding = 0, .fielddesc_type=0, .isbitsegal=1, .arrayelem_isboxed=0, .arrayelem_isunion=0 }};
            st->layout = &singleton_layout;
        }
    }
    else {
        // compute a conservative estimate of whether there could exist an instance of a subtype of this
        for (i = 0; st->has_concrete_subtype && i < nfields - st->name->n_uninitialized; i++) {
            language_value_t *fld = language_svecref(st->types, i);
            if (fld == language_bottom_type)
                st->has_concrete_subtype = 0;
            else
                st->has_concrete_subtype = !language_is_datatype(fld) || ((language_datatype_t *)fld)->has_concrete_subtype;
        }
        // compute layout for the wrapper object if the field types have no free variables
        if (!st->isconcretetype && !language_has_fixed_layout(st)) {
            assert(st == w); // otherwise caller should not have requested this layout
            return;
        }
    }

    for (i = 0; (isbitstype || isidentityfree || ismutationfree) && i < nfields; i++) {
        language_value_t *fld = language_field_type(st, i);
        isbitstype &= language_isbits(fld);
        ismutationfree &= (!st->name->mutabl || language_field_isconst(st, i)) && is_type_mutationfree(fld);
        isidentityfree &= is_type_identityfree(fld);
    }

    // if we didn't reuse the layout above, compute it now
    if (st->layout == NULL) {
        size_t descsz = nfields * sizeof(language_fielddesc32_t);
        language_fielddesc32_t *desc;
        uint32_t *pointers;
        int should_malloc = descsz >= language_page_size;
        if (should_malloc)
            desc = (language_fielddesc32_t*)malloc_s(descsz);
        else
            desc = (language_fielddesc32_t*)alloca(descsz);
        size_t sz = 0;
        size_t alignm = 1;
        int zeroinit = 0;
        int haspadding = 0;
        int isbitsegal = 1;
        int homogeneous = 1;
        int needlock = 0;
        uint32_t npointers = 0;
        language_value_t *firstty = language_field_type(st, 0);
        for (i = 0; i < nfields; i++) {
            language_value_t *fld = language_field_type(st, i);
            int isatomic = language_field_isatomic(st, i);
            size_t fsz = 0, al = 1;
            if (language_islayout_inline(fld, &fsz, &al) && (!isatomic || language_is_datatype(fld))) { // aka language_datatype_isinlinealloc
                if (__unlikely(fsz > max_size))
                    // Should never happen
                    throw_ovf(should_malloc, desc, st, fsz);
                desc[i].isptr = 0;
                if (language_is_uniontype(fld)) {
                    fsz += 1; // selector byte
                    zeroinit = 1;
                    // TODO: Some unions could be bits comparable.
                    isbitsegal = 0;
                }
                else {
                    uint32_t fld_npointers = ((language_datatype_t*)fld)->layout->npointers;
                    if (((language_datatype_t*)fld)->layout->flags.haspadding)
                        haspadding = 1;
                    if (!((language_datatype_t*)fld)->layout->flags.isbitsegal)
                        isbitsegal = 0;
                    if (i >= nfields - st->name->n_uninitialized && fld_npointers &&
                        fld_npointers * sizeof(void*) != fsz) {
                        // For field types that contain pointers, we allow inlinealloc
                        // as long as the field type itself is always fully initialized.
                        // In such a case, we use the first pointer in the inlined field
                        // as the #undef marker (if it is zero, we treat the whole inline
                        // struct as #undef). However, we do not zero-initialize the whole
                        // struct, so the non-pointer parts of the inline allocation may
                        // be arbitrary, but still need to compare egal (because all #undef)
                        // representations are egal. Because of this, we cannot bitscompare
                        // them.
                        // TODO: Consider zero-initializing the whole struct.
                        isbitsegal = 0;
                    }
                    if (!zeroinit)
                        zeroinit = ((language_datatype_t*)fld)->zeroinit;
                    npointers += fld_npointers;
                }
            }
            else {
                fsz = sizeof(void*);
                if (fsz > MAX_ALIGN)
                    fsz = MAX_ALIGN;
                al = fsz;
                desc[i].isptr = 1;
                zeroinit = 1;
                npointers++;
                if (!language_pointer_egal(fld)) {
                    isbitsegal = 0;
                }
            }
            if (isatomic && fsz > MAX_ATOMIC_SIZE)
                needlock = 1;
            if (isatomic && fsz <= MAX_ATOMIC_SIZE)
                al = fsz = next_power_of_two(fsz);
            if (al != 0) {
                size_t alsz = LLT_ALIGN(sz, al);
                if (alsz != sz)
                    haspadding = 1;
                sz = alsz;
                if (al > alignm)
                    alignm = al;
            }
            homogeneous &= firstty == fld;
            desc[i].offset = sz;
            desc[i].size = fsz;
            if (__unlikely(max_offset - sz < fsz))
                throw_ovf(should_malloc, desc, st, sz);
            sz += fsz;
        }
        if (needlock) {
            size_t offset = LLT_ALIGN(sizeof(language_mutex_t), alignm);
            for (i = 0; i < nfields; i++) {
                desc[i].offset += offset;
            }
            if (__unlikely(max_offset - sz < offset))
                throw_ovf(should_malloc, desc, st, sz);
            sz += offset;
            haspadding = 1;
        }
        if (homogeneous && language_is_tuple_type(st)) {
            // Some tuples become LLVM vectors with stronger alignment than what was calculated above.
            unsigned al = language_special_vector_alignment(nfields, firstty);
            assert(al % alignm == 0);
            if (al > alignm)
                alignm = al;
        }
        if (LLT_ALIGN(sz, alignm) > sz) {
            haspadding = 1;
            sz = LLT_ALIGN(sz, alignm);
        }
        if (should_malloc && npointers)
            pointers = (uint32_t*)malloc_s(npointers * sizeof(uint32_t));
        else
            pointers = (uint32_t*)alloca(npointers * sizeof(uint32_t));
        size_t ptr_i = 0;
        for (i = 0; i < nfields; i++) {
            language_value_t *fld = language_field_type(st, i);
            uint32_t offset = desc[i].offset / sizeof(language_value_t**);
            if (desc[i].isptr)
                pointers[ptr_i++] = offset;
            else if (language_is_datatype(fld)) {
                int j, npointers = ((language_datatype_t*)fld)->layout->npointers;
                for (j = 0; j < npointers; j++) {
                    pointers[ptr_i++] = offset + language_ptr_offset((language_datatype_t*)fld, j);
                }
            }
        }
        assert(ptr_i == npointers);
        st->layout = language_get_layout(sz, nfields, npointers, alignm, haspadding, isbitsegal, 0, desc, pointers);
        if (should_malloc) {
            free(desc);
            if (npointers)
                free(pointers);
        }
        st->zeroinit = zeroinit;
    }
    // now finish deciding if this instantiation qualifies for special properties
    assert(!isbitstype || st->layout->npointers == 0); // the definition of isbits
    st->isbitstype = isbitstype;
    st->ismutationfree = ismutationfree;
    st->isidentityfree = isidentityfree;
    language_maybe_allocate_singleton_instance(st);
    return;
}

LANGUAGE_DLLEXPORT language_datatype_t *language_new_datatype(
        language_sym_t *name,
        language_module_t *module,
        language_datatype_t *super,
        language_svec_t *parameters,
        language_svec_t *fnames,
        language_svec_t *ftypes,
        language_svec_t *fattrs,
        int abstract, int mutabl,
        int ninitialized)
{
    language_datatype_t *t = NULL;
    language_typename_t *tn = NULL;
    LANGUAGE_GC_PUSH2(&t, &tn);

    assert(parameters && fnames);

    // init enough before possibly calling language_new_typename_in
    t = language_new_uninitialized_datatype();
    t->super = super;
    if (super != NULL) language_gc_wb(t, t->super);
    t->parameters = parameters;
    language_gc_wb(t, t->parameters);
    t->types = ftypes;
    if (ftypes != NULL) language_gc_wb(t, t->types);

    t->name = NULL;
    if (language_is_typename(name)) {
        // This code-path is used by the Serialization module to bypass normal expectations
        tn = (language_typename_t*)name;
        tn->abstract = abstract;
        tn->mutabl = mutabl;
    }
    else {
        tn = language_new_typename_in((language_sym_t*)name, module, abstract, mutabl);
        if (super == language_function_type || super == language_builtin_type || is_anonfn_typename(language_symbol_name(name))) {
            // Callable objects (including compiler-generated closures) get independent method tables
            // as an optimization
            tn->mt = language_new_method_table(name, module);
            language_gc_wb(tn, tn->mt);
            if (language_svec_len(parameters) == 0 && !abstract)
                tn->mt->offs = 1;
        }
        else {
            // Everything else, gets to use the unified table
            tn->mt = language_nonfunction_mt;
        }
    }
    t->name = tn;
    language_gc_wb(t, t->name);
    t->name->names = fnames;
    language_gc_wb(t->name, t->name->names);
    tn->n_uninitialized = language_svec_len(fnames) - ninitialized;

    uint32_t *volatile atomicfields = NULL;
    uint32_t *volatile constfields = NULL;
    int i;
    LANGUAGE_TRY {
        for (i = 0; i + 1 < language_svec_len(fattrs); i += 2) {
            language_value_t *fldi = language_svecref(fattrs, i);
            language_sym_t *attr = (language_sym_t*)language_svecref(fattrs, i + 1);
            LANGUAGE_TYPECHK(typeassert, long, fldi);
            LANGUAGE_TYPECHK(typeassert, symbol, (language_value_t*)attr);
            size_t fldn = language_unbox_long(fldi);
            if (fldn < 1 || fldn > language_svec_len(fnames))
                language_errorf("invalid field attribute %lld", (long long)fldn);
            fldn--;
            if (attr == language_atomic_sym) {
                if (!mutabl)
                    language_errorf("invalid field attribute atomic for immutable struct");
                if (atomicfields == NULL) {
                    size_t nb = (language_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
                    atomicfields = (uint32_t*)malloc_s(nb);
                    memset(atomicfields, 0, nb);
                }
                atomicfields[fldn / 32] |= 1 << (fldn % 32);
            }
            else if (attr == language_const_sym) {
                if (!mutabl)
                    language_errorf("invalid field attribute const for immutable struct");
                if (constfields == NULL) {
                    size_t nb = (language_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
                    constfields = (uint32_t*)malloc_s(nb);
                    memset(constfields, 0, nb);
                }
                constfields[fldn / 32] |= 1 << (fldn % 32);
            }
            else {
                language_errorf("invalid field attribute %s", language_symbol_name(attr));
            }
        }
    }
    LANGUAGE_CATCH {
        free(atomicfields);
        free(constfields);
        language_rethrow();
    }
    tn->atomicfields = atomicfields;
    tn->constfields = constfields;

    if (t->name->wrapper == NULL) {
        t->name->wrapper = (language_value_t*)t;
        language_gc_wb(t->name, t);
        int i, np = language_svec_len(parameters);
        for (i = np - 1; i >= 0; i--) {
            t->name->wrapper = language_new_struct(language_unionall_type, language_svecref(parameters, i), t->name->wrapper);
            language_gc_wb(t->name, t->name->wrapper);
        }
        if (!mutabl && !abstract && ftypes != NULL)
            tn->mayinlinealloc = 1;
    }
    language_precompute_memoized_dt(t, 0);

    if (!abstract && t->types != NULL)
        language_compute_field_offsets(t);

    LANGUAGE_GC_POP();
    return t;
}

LANGUAGE_DLLEXPORT language_datatype_t *language_new_primitivetype(language_value_t *name, language_module_t *module,
                                                 language_datatype_t *super,
                                                 language_svec_t *parameters, size_t nbits)
{
    language_datatype_t *bt = language_new_datatype((language_sym_t*)name, module, super, parameters,
                                        language_emptysvec, language_emptysvec, language_emptysvec, 0, 0, 0);
    uint32_t nbytes = (nbits + 7) / 8;
    uint32_t alignm = next_power_of_two(nbytes);
    if (alignm > MAX_ALIGN)
        alignm = MAX_ALIGN;
    // memoize isprimitivetype, since it is much easier than checking
    // (dta->name->names == svec() && dta->layout && dta->layout->size != 0)
    // and we easily have a free bit for it in the DataType flags
    bt->isprimitivetype = 1;
    bt->ismutationfree = 1;
    bt->isidentityfree = 1;
    bt->isbitstype = (parameters == language_emptysvec);
    bt->layout = language_get_layout(nbytes, 0, 0, alignm, 0, 1, 0, NULL, NULL);
    bt->instance = NULL;
    return bt;
}

LANGUAGE_DLLEXPORT language_datatype_t * language_new_foreign_type(language_sym_t *name,
                                                 language_module_t *module,
                                                 language_datatype_t *super,
                                                 language_markfunc_t markfunc,
                                                 language_sweepfunc_t sweepfunc,
                                                 int haspointers,
                                                 int large)
{
    language_datatype_t *bt = language_new_datatype(name, module, super,
      language_emptysvec, language_emptysvec, language_emptysvec, language_emptysvec, 0, 1, 0);
    language_datatype_layout_t *layout = (language_datatype_layout_t *)
      language_gc_perm_alloc(sizeof(language_datatype_layout_t) + sizeof(language_fielddescdyn_t),
        0, 4, 0);
    layout->size = large ? GC_MAX_SZCLASS+1 : 0;
    layout->nfields = 0;
    layout->alignment = sizeof(void *);
    layout->npointers = haspointers;
    layout->flags.haspadding = 1;
    layout->flags.isbitsegal = 0;
    layout->flags.fielddesc_type = 3;
    layout->flags.padding = 0;
    layout->flags.arrayelem_isboxed = 0;
    layout->flags.arrayelem_isunion = 0;
    language_fielddescdyn_t * desc =
      (language_fielddescdyn_t *) ((char *)layout + sizeof(*layout));
    desc->markfunc = markfunc;
    desc->sweepfunc = sweepfunc;
    bt->layout = layout;
    bt->instance = NULL;
    return bt;
}

LANGUAGE_DLLEXPORT int language_reinit_foreign_type(language_datatype_t *dt,
                                        language_markfunc_t markfunc,
                                        language_sweepfunc_t sweepfunc)
{
    if (!language_is_foreign_type(dt))
        return 0;
    const language_datatype_layout_t *layout = dt->layout;
    language_fielddescdyn_t * desc =
      (language_fielddescdyn_t *) ((char *)layout + sizeof(*layout));
    assert(!desc->markfunc);
    assert(!desc->sweepfunc);
    desc->markfunc = markfunc;
    desc->sweepfunc = sweepfunc;
    return 1;
}

LANGUAGE_DLLEXPORT int language_is_foreign_type(language_datatype_t *dt)
{
    return language_is_datatype(dt) && dt->layout && dt->layout->flags.fielddesc_type == 3;
}

// bits constructors ----------------------------------------------------------

#if MAX_ATOMIC_SIZE > MAX_POINTERATOMIC_SIZE
#error MAX_ATOMIC_SIZE too large
#endif
#if MAX_ATOMIC_SIZE >= 16 && !defined(_P64)
#error 12 byte GC pool size alignment unimplemented for 32-bit
#endif
#if MAX_POINTERATOMIC_SIZE > 16
#error MAX_POINTERATOMIC_SIZE too large
#endif
#if BYTE_ORDER != LITTLE_ENDIAN
#error using masks for atomics (instead of memcpy like nb == 16) assumes little endian
#endif

#if MAX_POINTERATOMIC_SIZE >= 16
typedef struct _language_uint128_t {
    alignas(16) uint64_t a;
    uint64_t b;
} language_uint128_t;
#endif

static inline uint32_t zext_read32(const language_value_t *x, size_t nb) LANGUAGE_NOTSAFEPOINT
{
    uint32_t y = *(uint32_t*)x;
    if (nb == 4)
        return y;
    else // if (nb == 3)
        return 0xffffffu & y;
}

#if MAX_POINTERATOMIC_SIZE >= 8
static inline uint64_t zext_read64(const language_value_t *x, size_t nb) LANGUAGE_NOTSAFEPOINT
{
    uint64_t y = *(uint64_t*)x;
    if (nb == 8)
        return y;
    else if (nb == 7)
        return 0xffffffffffffffu & y;
    else if (nb == 6)
        return 0xffffffffffffu & y;
    else // if (nb == 5)
        return 0xffffffffffu & y;
}
#endif

#if MAX_POINTERATOMIC_SIZE >= 16
static inline language_uint128_t zext_read128(const language_value_t *x, size_t nb) LANGUAGE_NOTSAFEPOINT
{
    language_uint128_t y = {0};
    if (nb == 16)
        y = *(language_uint128_t*)x;
    else
        memcpy(&y, x, nb);
    return y;
}
#endif

LANGUAGE_DLLEXPORT language_value_t *language_new_bits(language_value_t *dt, const void *data)
{
    // data may not have the alignment required by the size
    // but will always have the alignment required by the datatype
    assert(language_is_datatype(dt));
    language_datatype_t *bt = (language_datatype_t*)dt;
    size_t nb = language_datatype_size(bt);
    // some types have special pools to minimize allocations
    if (nb == 0)               return language_new_struct_uninit(bt); // returns bt->instance
    if (bt == language_bool_type)    return (1 & *(int8_t*)data) ? language_true : language_false;
    if (bt == language_uint8_type)   return language_box_uint8(*(uint8_t*)data);
    if (bt == language_int64_type)   return language_box_int64(*(int64_t*)data);
    if (bt == language_int32_type)   return language_box_int32(*(int32_t*)data);
    if (bt == language_int8_type)    return language_box_int8(*(int8_t*)data);
    if (bt == language_int16_type)   return language_box_int16(*(int16_t*)data);
    if (bt == language_uint64_type)  return language_box_uint64(*(uint64_t*)data);
    if (bt == language_uint32_type)  return language_box_uint32(*(uint32_t*)data);
    if (bt == language_uint16_type)  return language_box_uint16(*(uint16_t*)data);
    if (bt == language_char_type)    return language_box_char(*(uint32_t*)data);

    assert(!bt->smalltag);
    language_task_t *ct = language_current_task;
    language_value_t *v = language_gc_alloc(ct->ptls, nb, bt);
    // TODO: make this a memmove_refs if relevant
    memcpy(language_assume_aligned(v, sizeof(void*)), data, nb);
    return v;
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_new_bits(language_value_t *dt, const char *data)
{
    // data must have the required alignment for an atomic of the given size
    assert(language_is_datatype(dt));
    language_datatype_t *bt = (language_datatype_t*)dt;
    size_t nb = language_datatype_size(bt);
    // some types have special pools to minimize allocations
    if (nb == 0)               return language_new_struct_uninit(bt); // returns bt->instance
    if (bt == language_bool_type)    return (1 & language_atomic_load((_Atomic(int8_t)*)data)) ? language_true : language_false;
    if (bt == language_uint8_type)   return language_box_uint8(language_atomic_load((_Atomic(uint8_t)*)data));
    if (bt == language_int64_type)   return language_box_int64(language_atomic_load((_Atomic(int64_t)*)data));
    if (bt == language_int32_type)   return language_box_int32(language_atomic_load((_Atomic(int32_t)*)data));
    if (bt == language_int8_type)    return language_box_int8(language_atomic_load((_Atomic(int8_t)*)data));
    if (bt == language_int16_type)   return language_box_int16(language_atomic_load((_Atomic(int16_t)*)data));
    if (bt == language_uint64_type)  return language_box_uint64(language_atomic_load((_Atomic(uint64_t)*)data));
    if (bt == language_uint32_type)  return language_box_uint32(language_atomic_load((_Atomic(uint32_t)*)data));
    if (bt == language_uint16_type)  return language_box_uint16(language_atomic_load((_Atomic(uint16_t)*)data));
    if (bt == language_char_type)    return language_box_char(language_atomic_load((_Atomic(uint32_t)*)data));

    assert(!bt->smalltag);
    language_task_t *ct = language_current_task;
    language_value_t *v = language_gc_alloc(ct->ptls, nb, bt);
    // data is aligned to the power of two,
    // we will write too much of v, but the padding should exist
    if (nb == 1)
        *(uint8_t*) v = language_atomic_load((_Atomic(uint8_t)*)data);
    else if (nb <= 2)
        *(uint16_t*)v = language_atomic_load((_Atomic(uint16_t)*)data);
    else if (nb <= 4)
        *(uint32_t*)v = language_atomic_load((_Atomic(uint32_t)*)data);
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8)
        *(uint64_t*)v = language_atomic_load((_Atomic(uint64_t)*)data);
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16)
        *(language_uint128_t*)v = language_atomic_load((_Atomic(language_uint128_t)*)data);
#endif
    else
        abort();
    return v;
}

LANGUAGE_DLLEXPORT void language_atomic_store_bits(char *dst, const language_value_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    // src must be aligned by the GC
    // we may therefore read too much from src, but will zero the excess bits
    // before the store (so that we can get faster cmpswap later)
    if (nb == 0)
        ;
    else if (nb == 1)
        language_atomic_store((_Atomic(uint8_t)*)dst, *(uint8_t*)src);
    else if (nb == 2)
        language_atomic_store((_Atomic(uint16_t)*)dst, *(uint16_t*)src);
    else if (nb <= 4)
        language_atomic_store((_Atomic(uint32_t)*)dst, zext_read32(src, nb));
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8)
        language_atomic_store((_Atomic(uint64_t)*)dst, zext_read64(src, nb));
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16)
        language_atomic_store((_Atomic(language_uint128_t)*)dst, zext_read128(src, nb));
#endif
    else
        abort();
}

LANGUAGE_DLLEXPORT language_value_t *language_atomic_swap_bits(language_value_t *dt, char *dst, const language_value_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    assert(language_is_datatype(dt));
    language_datatype_t *bt = (language_datatype_t*)dt;
    // some types have special pools to minimize allocations
    if (nb == 0)               return language_new_struct_uninit(bt); // returns bt->instance
    if (bt == language_bool_type)    return (1 & language_atomic_exchange((_Atomic(int8_t)*)dst, 1 & *(int8_t*)src)) ? language_true : language_false;
    if (bt == language_uint8_type)   return language_box_uint8(language_atomic_exchange((_Atomic(uint8_t)*)dst, *(int8_t*)src));
    if (bt == language_int64_type)   return language_box_int64(language_atomic_exchange((_Atomic(int64_t)*)dst, *(int64_t*)src));
    if (bt == language_int32_type)   return language_box_int32(language_atomic_exchange((_Atomic(int32_t)*)dst, *(int32_t*)src));
    if (bt == language_int8_type)    return language_box_int8(language_atomic_exchange((_Atomic(int8_t)*)dst, *(int8_t*)src));
    if (bt == language_int16_type)   return language_box_int16(language_atomic_exchange((_Atomic(int16_t)*)dst, *(int16_t*)src));
    if (bt == language_uint64_type)  return language_box_uint64(language_atomic_exchange((_Atomic(uint64_t)*)dst, *(uint64_t*)src));
    if (bt == language_uint32_type)  return language_box_uint32(language_atomic_exchange((_Atomic(uint32_t)*)dst, *(uint32_t*)src));
    if (bt == language_uint16_type)  return language_box_uint16(language_atomic_exchange((_Atomic(uint16_t)*)dst, *(uint16_t*)src));
    if (bt == language_char_type)    return language_box_char(language_atomic_exchange((_Atomic(uint32_t)*)dst, *(uint32_t*)src));

    assert(!bt->smalltag);
    language_task_t *ct = language_current_task;
    language_value_t *v = language_gc_alloc(ct->ptls, language_datatype_size(bt), bt);
    if (nb == 1)
        *(uint8_t*)v = language_atomic_exchange((_Atomic(uint8_t)*)dst, *(uint8_t*)src);
    else if (nb == 2)
        *(uint16_t*)v = language_atomic_exchange((_Atomic(uint16_t)*)dst, *(uint16_t*)src);
    else if (nb <= 4)
        *(uint32_t*)v = language_atomic_exchange((_Atomic(uint32_t)*)dst, zext_read32(src, nb));
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8)
        *(uint64_t*)v = language_atomic_exchange((_Atomic(uint64_t)*)dst, zext_read64(src, nb));
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16)
        *(language_uint128_t*)v = language_atomic_exchange((_Atomic(language_uint128_t)*)dst, zext_read128(src, nb));
#endif
    else
        abort();
    return v;
}

LANGUAGE_DLLEXPORT int language_atomic_bool_cmpswap_bits(char *dst, const language_value_t *expected, const language_value_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    // n.b.: this can spuriously fail if there are padding bits, the caller should deal with that
    int success;
    if (nb == 0) {
        success = 1;
    }
    else if (nb == 1) {
        uint8_t y = *(uint8_t*)expected;
        success = language_atomic_cmpswap((_Atomic(uint8_t)*)dst, &y, *(uint8_t*)src);
    }
    else if (nb == 2) {
        uint16_t y = *(uint16_t*)expected;
        success = language_atomic_cmpswap((_Atomic(uint16_t)*)dst, &y, *(uint16_t*)src);
    }
    else if (nb <= 4) {
        uint32_t y = zext_read32(expected, nb);
        uint32_t z = zext_read32(src, nb);
        success = language_atomic_cmpswap((_Atomic(uint32_t)*)dst, &y, z);
    }
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8) {
        uint64_t y = zext_read64(expected, nb);
        uint64_t z = zext_read64(src, nb);
        success = language_atomic_cmpswap((_Atomic(uint64_t)*)dst, &y, z);
    }
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16) {
        language_uint128_t y = zext_read128(expected, nb);
        language_uint128_t z = zext_read128(src, nb);
        success = language_atomic_cmpswap((_Atomic(language_uint128_t)*)dst, &y, z);
    }
#endif
    else {
        abort();
    }
    return success;
}

LANGUAGE_DLLEXPORT int language_atomic_cmpswap_bits(language_datatype_t *dt, language_value_t *y /* pre-allocated output */, char *dst, const language_value_t *expected, const language_value_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    // n.b.: this does not spuriously fail if there are padding bits
    int success;
    language_datatype_t *et = (language_datatype_t*)language_typeof(expected);
    if (nb == 0) {
        success = (dt == et);
    }
    else if (nb == 1) {
        uint8_t *y8 = (uint8_t*)y;
        assert(!dt->layout->flags.haspadding);
        if (dt == et) {
            *y8 = *(uint8_t*)expected;
            uint8_t z8 = *(uint8_t*)src;
            success = language_atomic_cmpswap((_Atomic(uint8_t)*)dst, y8, z8);
        }
        else {
            *y8 = language_atomic_load((_Atomic(uint8_t)*)dst);
            success = 0;
        }
    }
    else if (nb == 2) {
        uint16_t *y16 = (uint16_t*)y;
        assert(!dt->layout->flags.haspadding);
        if (dt == et) {
            *y16 = *(uint16_t*)expected;
            uint16_t z16 = *(uint16_t*)src;
            success = language_atomic_cmpswap((_Atomic(uint16_t)*)dst, y16, z16);
        }
        else {
            *y16 = language_atomic_load((_Atomic(uint16_t)*)dst);
            success = 0;
        }
    }
    else if (nb <= 4) {
        uint32_t *y32 = (uint32_t*)y;
        if (dt == et) {
            *y32 = zext_read32(expected, nb);
            uint32_t z32 = zext_read32(src, nb);
            while (1) {
                success = language_atomic_cmpswap((_Atomic(uint32_t)*)dst, y32, z32);
                if (success || !dt->layout->flags.haspadding || !language_egal__bits(y, expected, dt))
                    break;
            }
        }
        else {
            *y32 = language_atomic_load((_Atomic(uint32_t)*)dst);
            success = 0;
        }
    }
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8) {
        uint64_t *y64 = (uint64_t*)y;
        if (dt == et) {
            *y64 = zext_read64(expected, nb);
            uint64_t z64 = zext_read64(src, nb);
            while (1) {
                success = language_atomic_cmpswap((_Atomic(uint64_t)*)dst, y64, z64);
                if (success || !dt->layout->flags.haspadding || !language_egal__bits(y, expected, dt))
                    break;
            }
        }
        else {
            *y64 = language_atomic_load((_Atomic(uint64_t)*)dst);
            success = 0;
        }
    }
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16) {
        language_uint128_t *y128 = (language_uint128_t*)y;
        if (dt == et) {
            *y128 = zext_read128(expected, nb);
            language_uint128_t z128 = zext_read128(src, nb);
            while (1) {
                success = language_atomic_cmpswap((_Atomic(language_uint128_t)*)dst, y128, z128);
                if (success || !dt->layout->flags.haspadding || !language_egal__bits(y, expected, dt))
                    break;
            }
        }
        else {
            *y128 = language_atomic_load((_Atomic(language_uint128_t)*)dst);
            success = 0;
        }
    }
#endif
    else {
        abort();
    }
    return success;
}

LANGUAGE_DLLEXPORT int language_atomic_storeonce_bits(language_datatype_t *dt, char *dst, const language_value_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    // n.b.: this does not spuriously fail
    // n.b.: hasptr == 1 therefore nb >= sizeof(void*), because ((language_datatype_t*)ty)->layout->has_ptr >= 0
    int success;
#ifdef _P64
    if (nb <= 4) {
        uint32_t y32 = 0;
        uint32_t z32 = zext_read32(src, nb);
        success = language_atomic_cmpswap((_Atomic(uint32_t)*)dst, &y32, z32);
    }
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8) {
        uint64_t y64 = 0;
        uint64_t z64 = zext_read64(src, nb);
        while (1) {
            success = language_atomic_cmpswap((_Atomic(uint64_t)*)dst, &y64, z64);
            if (success || undefref_check(dt, (language_value_t*)&y64) != NULL)
                break;
        }
    }
#endif
#else
    if (nb <= 8) {
        uint64_t y64 = 0;
        uint64_t z64 = zext_read64(src, nb);
        success = language_atomic_cmpswap((_Atomic(uint64_t)*)dst, &y64, z64);
    }
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16) {
        language_uint128_t y128 = {0};
        language_uint128_t z128 = zext_read128(src, nb);
        while (1) {
            success = language_atomic_cmpswap((_Atomic(language_uint128_t)*)dst, &y128, z128);
            if (success || undefref_check(dt, (language_value_t*)&y128) != NULL)
                break;
        }
    }
#endif
    else {
        abort();
    }
    return success;
}

#define PERMBOXN_FUNC(nb)                                               \
    language_value_t *language_permbox##nb(language_datatype_t *t, uintptr_t tag, uint##nb##_t x) \
    {   /* n.b. t must be a concrete isbits datatype of the right size */ \
        language_value_t *v = language_gc_permobj(LLT_ALIGN(nb, sizeof(void*)), t); \
        if (tag) language_set_typetagof(v, tag, GC_OLD_MARKED);               \
        *(uint##nb##_t*)language_data_ptr(v) = x;                             \
        return v;                                                       \
    }
PERMBOXN_FUNC(8)
PERMBOXN_FUNC(16)
PERMBOXN_FUNC(32)
PERMBOXN_FUNC(64)

#define UNBOX_FUNC(j_type,c_type)                                       \
    LANGUAGE_DLLEXPORT c_type language_unbox_##j_type(language_value_t *v)                \
    {                                                                   \
        assert(language_is_primitivetype(language_typeof(v)));                      \
        assert(language_datatype_size(language_typeof(v)) == sizeof(c_type));       \
        return *(c_type*)language_data_ptr(v);                                \
    }
UNBOX_FUNC(int8,   int8_t)
UNBOX_FUNC(uint8,  uint8_t)
UNBOX_FUNC(int16,  int16_t)
UNBOX_FUNC(uint16, uint16_t)
UNBOX_FUNC(int32,  int32_t)
UNBOX_FUNC(uint32, uint32_t)
UNBOX_FUNC(int64,  int64_t)
UNBOX_FUNC(uint64, uint64_t)
UNBOX_FUNC(bool,   int8_t)
UNBOX_FUNC(float32, float)
UNBOX_FUNC(float64, double)
UNBOX_FUNC(voidpointer, void*)
UNBOX_FUNC(uint8pointer, uint8_t*)

#define BOX_FUNC(typ,c_type,pfx)                                        \
    LANGUAGE_DLLEXPORT language_value_t *pfx##_##typ(c_type x)                      \
    {                                                                   \
        language_task_t *ct = language_current_task;                                \
        language_value_t *v = language_gc_alloc(ct->ptls, LLT_ALIGN(sizeof(x), sizeof(void*)), \
                                    language_##typ##_type);                   \
        *(c_type*)language_data_ptr(v) = x;                                   \
        return v;                                                       \
    }
BOX_FUNC(float32, float,  language_box)
BOX_FUNC(float64, double, language_box)
BOX_FUNC(voidpointer, void*,  language_box)
BOX_FUNC(uint8pointer, uint8_t*,  language_box)

#define NBOX_C 1024

// some shims to support UIBOX_FUNC definition
#define language_ssavalue_tag (((uintptr_t)language_ssavalue_type) >> 4)
#define language_slotnumber_tag (((uintptr_t)language_slotnumber_type) >> 4)

#define SIBOX_FUNC(typ,c_type)                                          \
    static language_value_t *boxed_##typ##_cache[NBOX_C];                     \
    LANGUAGE_DLLEXPORT language_value_t *language_box_##typ(c_type x)                     \
    {                                                                   \
        language_task_t *ct = language_current_task;                                \
        c_type idx = x+NBOX_C/2;                                        \
        if ((u##c_type)idx < (u##c_type)NBOX_C)                         \
            return boxed_##typ##_cache[idx];                            \
        language_value_t *v = language_gc_alloc(ct->ptls, LLT_ALIGN(sizeof(x), sizeof(void*)), \
                                    language_##typ##_type);                   \
        language_set_typetagof(v, language_##typ##_tag, 0);                         \
        *(c_type*)language_data_ptr(v) = x;                                   \
        return v;                                                       \
    }
#define UIBOX_FUNC(typ,c_type)                                          \
    static language_value_t *boxed_##typ##_cache[NBOX_C];                     \
    LANGUAGE_DLLEXPORT language_value_t *language_box_##typ(c_type x)                     \
    {                                                                   \
        language_task_t *ct = language_current_task;                                \
        if (x < NBOX_C)                                                 \
            return boxed_##typ##_cache[x];                              \
        language_value_t *v = language_gc_alloc(ct->ptls, LLT_ALIGN(sizeof(x), sizeof(void*)), \
                                    language_##typ##_type);                   \
        language_set_typetagof(v, language_##typ##_tag, 0);                         \
        *(c_type*)language_data_ptr(v) = x;                                   \
        return v;                                                       \
    }
SIBOX_FUNC(int16,  int16_t)
SIBOX_FUNC(int32,  int32_t)
UIBOX_FUNC(uint16, uint16_t)
UIBOX_FUNC(uint32, uint32_t)
UIBOX_FUNC(ssavalue, size_t)
UIBOX_FUNC(slotnumber, size_t)
SIBOX_FUNC(int64,  int64_t)
UIBOX_FUNC(uint64, uint64_t)

static language_value_t *boxed_char_cache[128];
LANGUAGE_DLLEXPORT language_value_t *language_box_char(uint32_t x)
{
    language_task_t *ct = language_current_task;
    uint32_t u = bswap_32(x);
    if (u < 128)
        return boxed_char_cache[(uint8_t)u];
    language_value_t *v = language_gc_alloc(ct->ptls, sizeof(void*), language_char_type);
    language_set_typetagof(v, language_char_tag, 0);
    *(uint32_t*)language_data_ptr(v) = x;
    return v;
}

LANGUAGE_DLLEXPORT language_value_t *language_boxed_int8_cache[256];
LANGUAGE_DLLEXPORT language_value_t *language_box_int8(int8_t x)
{
    return language_boxed_int8_cache[(uint8_t)x];
}
LANGUAGE_DLLEXPORT language_value_t *language_boxed_uint8_cache[256];
LANGUAGE_DLLEXPORT language_value_t *language_box_uint8(uint8_t x)
{
    return language_boxed_uint8_cache[x];
}

void language_init_int32_int64_cache(void)
{
    int64_t i;
    for(i=0; i < NBOX_C; i++) {
        boxed_int32_cache[i]  = language_permbox32(language_int32_type, language_int32_tag, i-NBOX_C/2);
        boxed_int64_cache[i]  = language_permbox64(language_int64_type, language_int64_tag, i-NBOX_C/2);
        boxed_uint16_cache[i] = language_permbox16(language_uint16_type, language_uint16_tag, i);
        boxed_uint64_cache[i] = language_permbox64(language_uint64_type, language_uint64_tag, i);
        boxed_uint32_cache[i] = language_permbox32(language_uint32_type, language_uint32_tag, i);
#ifdef _P64
        boxed_ssavalue_cache[i] = language_permbox64(language_ssavalue_type, 0, i);
        boxed_slotnumber_cache[i] = language_permbox64(language_slotnumber_type, 0, i);
#else
        boxed_ssavalue_cache[i] = language_permbox32(language_ssavalue_type, 0, i);
        boxed_slotnumber_cache[i] = language_permbox32(language_slotnumber_type, 0, i);
#endif
    }
    for(i=0; i < 256; i++) {
        language_boxed_uint8_cache[i] = language_permbox8(language_uint8_type, language_uint8_tag, i);
    }
}

void language_init_box_caches(void)
{
    uint32_t i;
    for (i = 0; i < 128; i++) {
        boxed_char_cache[i] = language_permbox32(language_char_type, language_char_tag, i << 24);
    }
    for (i = 0; i < 256; i++) {
        language_boxed_int8_cache[i] = language_permbox8(language_int8_type, language_int8_tag, i);
    }
    for (i = 0; i < NBOX_C; i++) {
        boxed_int16_cache[i]  = language_permbox16(language_int16_type, language_int16_tag, i-NBOX_C/2);
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_box_bool(int8_t x)
{
    if (x)
        return language_true;
    return language_false;
}

// struct constructors --------------------------------------------------------

LANGUAGE_DLLEXPORT language_value_t *language_new_struct(language_datatype_t *type, ...)
{
    language_task_t *ct = language_current_task;
    if (!language_is_datatype(type) || !type->isconcretetype || type->layout == NULL || language_is_layout_opaque(type->layout)) {
        language_type_error("new", (language_value_t*)language_datatype_type, (language_value_t*)type);
    }
    if (type->instance != NULL)
        return type->instance;
    va_list args;
    size_t i, nf = language_datatype_nfields(type);
    va_start(args, type);
    language_value_t *jv = language_gc_alloc(ct->ptls, language_datatype_size(type), type);
    if (type->smalltag) // TODO: move to callers?
        language_set_typetagof(jv, type->smalltag, 0);
    if (nf > 0 && language_field_offset(type, 0) != 0) {
        memset(jv, 0, language_field_offset(type, 0));
    }
    for (i = 0; i < nf; i++) {
        set_nth_field(type, jv, i, va_arg(args, language_value_t*), 0);
    }
    va_end(args);
    return jv;
}

LANGUAGE_DLLEXPORT language_value_t *language_new_structv(language_datatype_t *type, language_value_t **args, uint32_t na)
{
    language_task_t *ct = language_current_task;
    if (!language_is_datatype(type) || !type->isconcretetype || type->layout == NULL || language_is_layout_opaque(type->layout)) {
        language_type_error("new", (language_value_t*)language_datatype_type, (language_value_t*)type);
    }
    size_t nf = language_datatype_nfields(type);
    if (nf - type->name->n_uninitialized > na || na > nf)
        language_error("invalid struct allocation");
    for (size_t i = 0; i < na; i++) {
        language_value_t *ft = language_field_type_concrete(type, i);
        if (!language_isa(args[i], ft))
            language_type_error("new", ft, args[i]);
    }
    if (type->instance != NULL)
        return type->instance;
    language_value_t *jv = language_gc_alloc(ct->ptls, language_datatype_size(type), type);
    if (type->smalltag) // TODO: do we need this?
        language_set_typetagof(jv, type->smalltag, 0);
    if (language_datatype_nfields(type) > 0) {
        if (language_field_offset(type, 0) != 0) {
            memset(language_data_ptr(jv), 0, language_field_offset(type, 0));
        }
        LANGUAGE_GC_PUSH1(&jv);
        for (size_t i = 0; i < na; i++) {
            set_nth_field(type, jv, i, args[i], 0);
        }
        if (na < language_datatype_nfields(type)) {
            char *data = (char*)language_data_ptr(jv);
            size_t offs = language_field_offset(type, na);
            memset(data + offs, 0, language_datatype_size(type) - offs);
        }
        LANGUAGE_GC_POP();
    }
    return jv;
}

LANGUAGE_DLLEXPORT language_value_t *language_new_structt(language_datatype_t *type, language_value_t *tup)
{
    language_task_t *ct = language_current_task;
    if (!language_is_tuple(tup))
        language_type_error("new", (language_value_t*)language_tuple_type, tup);
    if (!language_is_datatype(type) || !type->isconcretetype || type->layout == NULL || language_is_layout_opaque(type->layout))
        language_type_error("new", (language_value_t *)language_datatype_type, (language_value_t *)type);
    size_t nargs = language_nfields(tup);
    size_t nf = language_datatype_nfields(type);
    LANGUAGE_NARGS(new, nf, nf);
    if (type->instance != NULL) {
        language_datatype_t *tupt = (language_datatype_t*)language_typeof(tup);
        for (size_t i = 0; i < nargs; i++) {
            language_value_t *ft = language_field_type_concrete(type, i);
            language_value_t *et = language_field_type_concrete(tupt, i);
            assert(language_is_concrete_type(ft) && language_is_concrete_type(et));
            if (et != ft)
                language_type_error("new", ft, language_get_nth_field(tup, i));
        }
        return type->instance;
    }
    size_t size = language_datatype_size(type);
    language_value_t *jv = language_gc_alloc(ct->ptls, size, type);
    if (type->smalltag) // TODO: do we need this?
        language_set_typetagof(jv, type->smalltag, 0);
    if (nf == 0)
        return jv;
    language_value_t *fi = NULL;
    if (type->zeroinit) {
        // if there are references, zero the space first to prevent the GC
        // from seeing uninitialized references during language_get_nth_field and language_isa,
        // which can allocate.
        memset(language_data_ptr(jv), 0, size);
    }
    else if (language_field_offset(type, 0) != 0) {
        memset(language_data_ptr(jv), 0, language_field_offset(type, 0));
    }
    LANGUAGE_GC_PUSH2(&jv, &fi);
    for (size_t i = 0; i < nargs; i++) {
        language_value_t *ft = language_field_type_concrete(type, i);
        fi = language_get_nth_field(tup, i);
        if (!language_isa(fi, ft))
            language_type_error("new", ft, fi);
        set_nth_field(type, jv, i, fi, 0);
    }
    LANGUAGE_GC_POP();
    return jv;
}

LANGUAGE_DLLEXPORT language_value_t *language_new_struct_uninit(language_datatype_t *type)
{
    language_task_t *ct = language_current_task;
    if (!language_is_datatype(type) || !type->isconcretetype || type->layout == NULL || language_is_layout_opaque(type->layout)) {
        language_type_error("new", (language_value_t*)language_datatype_type, (language_value_t*)type);
    }
    if (type->instance != NULL)
        return type->instance;
    size_t size = language_datatype_size(type);
    language_value_t *jv = language_gc_alloc(ct->ptls, size, type);
    if (type->smalltag) // TODO: do we need this?
        language_set_typetagof(jv, type->smalltag, 0);
    if (size > 0)
        memset(language_data_ptr(jv), 0, size);
    return jv;
}

// field access ---------------------------------------------------------------

// TODO(jwn): these lock/unlock pairs must be full seq-cst fences
LANGUAGE_DLLEXPORT void language_lock_value(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT
{
    LANGUAGE_LOCK_NOGC(v);
}

LANGUAGE_DLLEXPORT void language_unlock_value(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT
{
    LANGUAGE_UNLOCK_NOGC(v);
}

LANGUAGE_DLLEXPORT void language_lock_field(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT
{
    LANGUAGE_LOCK_NOGC(v);
}

LANGUAGE_DLLEXPORT void language_unlock_field(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT
{
    LANGUAGE_UNLOCK_NOGC(v);
}

static inline char *lock(char *p, language_value_t *parent, int needlock, enum atomic_kind isatomic) LANGUAGE_NOTSAFEPOINT
{
    if (needlock) {
        if (isatomic == isatomic_object) {
            language_lock_value((language_mutex_t*)parent);
        }
        else {
            language_lock_field((language_mutex_t*)p);
            return p + LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT);
        }
    }
    return p;
}

static inline void unlock(char *p, language_value_t *parent, int needlock, enum atomic_kind isatomic) LANGUAGE_NOTSAFEPOINT
{
    if (needlock) {
        if (isatomic == isatomic_object) {
            language_unlock_value((language_mutex_t*)parent);
        }
        else {
            language_unlock_field((language_mutex_t*)p);
        }
    }
}

LANGUAGE_DLLEXPORT int language_field_index(language_datatype_t *t, language_sym_t *fld, int err)
{
    if (language_is_namedtuple_type(t)) {
        language_value_t *ns = language_tparam0(t);
        if (language_is_tuple(ns)) {
            size_t i, n = language_nfields(ns);
            for (i = 0; i < n; i++) {
                if (language_get_nth_field(ns, i) == (language_value_t*)fld) {
                    return (int)i;
                }
            }
        }
    }
    else {
        language_svec_t *fn = language_field_names(t);
        size_t i, n = language_svec_len(fn);
        for (i = 0; i < n; i++) {
            if (language_svecref(fn, i) == (language_value_t*)fld) {
                return (int)i;
            }
        }
    }
    if (err)
        language_has_no_field_error(t, fld);
    return -1;
}

LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field(language_value_t *v, size_t i)
{
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    if (i >= language_datatype_nfields(st))
        language_bounds_error_int(v, i + 1);
    size_t offs = language_field_offset(st, i);
    if (language_field_isptr(st, i)) {
        return language_atomic_load_relaxed((_Atomic(language_value_t*)*)((char*)v + offs));
    }
    language_value_t *ty = language_field_type_concrete(st, i);
    int isatomic = language_field_isatomic(st, i);
    if (language_is_uniontype(ty)) {
        assert(!isatomic);
        size_t fsz = language_field_size(st, i);
        uint8_t sel = ((uint8_t*)v)[offs + fsz - 1];
        ty = language_nth_union_component(ty, sel);
        if (language_is_datatype_singleton((language_datatype_t*)ty))
            return ((language_datatype_t*)ty)->instance;
    }
    language_value_t *r;
    size_t fsz = language_datatype_size(ty);
    int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
    if (isatomic && !needlock) {
        r = language_atomic_new_bits(ty, (char*)v + offs);
    }
    else if (needlock) {
        language_task_t *ct = language_current_task;
        r = language_gc_alloc(ct->ptls, fsz, ty);
        language_lock_value((language_mutex_t*)v);
        memcpy((char*)r, (char*)v + offs, fsz);
        language_unlock_value((language_mutex_t*)v);
    }
    else {
        // TODO: a finalizer here could make the isunion case not quite right
        r = language_new_bits(ty, (char*)v + offs);
    }
    return undefref_check((language_datatype_t*)ty, r);
}

LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field_noalloc(language_value_t *v LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    assert(i < language_datatype_nfields(st));
    size_t offs = language_field_offset(st,i);
    assert(language_field_isptr(st,i));
    return language_atomic_load_relaxed((_Atomic(language_value_t*)*)((char*)v + offs));
}

LANGUAGE_DLLEXPORT language_value_t *language_get_nth_field_checked(language_value_t *v, size_t i)
{
    language_value_t *r = language_get_nth_field(v, i);
    if (__unlikely(r == NULL))
        language_throw(language_undefref_exception);
    return r;
}

inline void set_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic) LANGUAGE_NOTSAFEPOINT
{
    size_t offs = language_field_offset(st, i);
    if (rhs == NULL) { // TODO: this should be invalid, but it happens frequently in ircode.c
        assert(language_field_isptr(st, i) && *(language_value_t**)((char*)v + offs) == NULL);
        return;
    }
    if (language_field_isptr(st, i)) {
        language_atomic_store_release((_Atomic(language_value_t*)*)((char*)v + offs), rhs);
        language_gc_wb(v, rhs);
    }
    else {
        language_value_t *ty = language_field_type_concrete(st, i);
        language_value_t *rty = language_typeof(rhs);
        int hasptr;
        int isunion = language_is_uniontype(ty);
        if (isunion) {
            assert(!isatomic);
            size_t fsz = language_field_size(st, i);
            uint8_t *psel = &((uint8_t*)v)[offs + fsz - 1];
            unsigned nth = 0;
            if (!language_find_union_component(ty, rty, &nth))
                assert(0 && "invalid field assignment to isbits union");
            *psel = nth;
            if (language_is_datatype_singleton((language_datatype_t*)rty))
                return;
            hasptr = 0;
        }
        else {
            hasptr = ((language_datatype_t*)ty)->layout->first_ptr >= 0;
        }
        size_t fsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the final copy
        assert(!isatomic || language_typeis(rhs, ty));
        int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
        if (isatomic && !needlock) {
            language_atomic_store_bits((char*)v + offs, rhs, fsz);
        }
        else if (needlock) {
            language_lock_value((language_mutex_t*)v);
            memcpy((char*)v + offs, (char*)rhs, fsz);
            language_unlock_value((language_mutex_t*)v);
        }
        else {
            memassign_safe(hasptr, (char*)v + offs, rhs, fsz);
        }
        if (hasptr)
            language_gc_multi_wb(v, rhs); // rhs is immutable
    }
}

inline language_value_t *swap_bits(language_value_t *ty, char *v, uint8_t *psel, language_value_t *parent, language_value_t *rhs, enum atomic_kind isatomic)
{
    language_value_t *rty = language_typeof(rhs);
    int hasptr;
    int isunion = psel != NULL;
    if (isunion) {
        assert(!isatomic);
        hasptr = 0;
    }
    else {
        hasptr = ((language_datatype_t*)ty)->layout->first_ptr >= 0;
    }
    size_t fsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the final copy
    int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
    assert(!isatomic || language_typeis(rhs, ty));
    language_value_t *r;
    if (isatomic && !needlock) {
        r = language_atomic_swap_bits(rty, v, rhs, fsz);
    }
    else {
        if (needlock) {
            language_task_t *ct = language_current_task;
            r = language_gc_alloc(ct->ptls, fsz, ty);
            char *px = lock(v, parent, needlock, isatomic);
            memcpy((char*)r, px, fsz);
            memcpy(px, (char*)rhs, fsz);
            unlock(v, parent, needlock, isatomic);
        }
        else {
            r = language_new_bits(isunion ? language_nth_union_component(ty, *psel) : ty, v);
            if (isunion) {
                unsigned nth = 0;
                if (!language_find_union_component(ty, rty, &nth))
                    assert(0 && "invalid field assignment to isbits union");
                *psel = nth;
                if (language_is_datatype_singleton((language_datatype_t*)rty))
                    return r;
            }
            memassign_safe(hasptr, v, rhs, fsz);
        }
    }
    if (!isunion)
        r = undefref_check((language_datatype_t*)ty, r);
    if (hasptr)
        language_gc_multi_wb(parent, rhs); // rhs is immutable
    if (__unlikely(r == NULL))
        language_throw(language_undefref_exception);
    return r;
}

language_value_t *swap_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic)
{
    language_value_t *ty = language_field_type_concrete(st, i);
    if (!language_isa(rhs, ty))
       language_type_error("swapfield!", ty, rhs);
    size_t offs = language_field_offset(st, i);
    language_value_t *r;
    char *p = (char*)v + offs;
    if (language_field_isptr(st, i)) {
        if (isatomic)
            r = language_atomic_exchange((_Atomic(language_value_t*)*)p, rhs);
        else
            r = language_atomic_exchange_release((_Atomic(language_value_t*)*)p, rhs);
        language_gc_wb(v, rhs);
        if (__unlikely(r == NULL))
            language_throw(language_undefref_exception);
        return r;
    }
    else {
        uint8_t *psel = language_is_uniontype(ty) ? (uint8_t*)&p[language_field_size(st, i) - 1] : NULL;
        return swap_bits(ty, p, psel, v, rhs, isatomic ? isatomic_object : isatomic_none);
    }
}

inline language_value_t *modify_value(language_value_t *ty, _Atomic(language_value_t*) *p, language_value_t *parent, language_value_t *op, language_value_t *rhs, int isatomic, language_module_t *mod, language_sym_t *name)
{
    language_value_t *r = isatomic ? language_atomic_load(p) : language_atomic_load_relaxed(p);
    if (__unlikely(r == NULL)) {
        if (mod && name)
            language_undefined_var_error(name, (language_value_t*)mod);
        language_throw(language_undefref_exception);
    }
    language_value_t **args;
    LANGUAGE_GC_PUSHARGS(args, 2);
    args[0] = r;
    while (1) {
        args[1] = rhs;
        language_value_t *y = language_apply_generic(op, args, 2);
        args[1] = y;
        if (!language_isa(y, ty)) {
            if (mod && name)
                language_errorf("cannot assign an incompatible value to the global %s.%s.", language_symbol_name(mod->name), language_symbol_name(name));
            language_type_error(language_is_genericmemory(parent) ? "memoryrefmodify!" : "modifyfield!", ty, y);
        }
        if (isatomic ? language_atomic_cmpswap(p, &r, y) : language_atomic_cmpswap_release(p, &r, y)) {
            language_gc_wb(parent, y);
            break;
        }
        args[0] = r;
        language_gc_safepoint();
    }
    // args[0] == r (old)
    // args[1] == y (new)
    language_datatype_t *rettyp = language_apply_modify_type(ty);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    args[0] = language_new_struct(rettyp, args[0], args[1]);
    LANGUAGE_GC_POP();
    return args[0];
}

inline language_value_t *modify_bits(language_value_t *ty, char *p, uint8_t *psel, language_value_t *parent, language_value_t *op, language_value_t *rhs, enum atomic_kind isatomic)
{
    int hasptr;
    int isunion = psel != NULL;
    if (isunion) {
        assert(!isatomic);
        hasptr = 0;
    }
    else {
        hasptr = ((language_datatype_t*)ty)->layout->first_ptr >= 0;
    }
    language_value_t **args;
    LANGUAGE_GC_PUSHARGS(args, 2);
    while (1) {
        language_value_t *r;
        language_value_t *rty = isunion ? language_nth_union_component(ty, *psel) : ty;
        size_t fsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the initial copy
        int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
        if (isatomic && !needlock) {
            r = language_atomic_new_bits(rty, p);
        }
        else if (needlock) {
            language_task_t *ct = language_current_task;
            r = language_gc_alloc(ct->ptls, fsz, rty);
            char *px = lock(p, parent, needlock, isatomic);
            memcpy((char*)r, px, fsz);
            unlock(p, parent, needlock, isatomic);
        }
        else {
            r = language_new_bits(rty, p);
        }
        r = undefref_check((language_datatype_t*)rty, r);
        if (__unlikely(r == NULL))
            language_throw(language_undefref_exception);
        args[0] = r;
        args[1] = rhs;
        language_value_t *y = language_apply_generic(op, args, 2);
        args[1] = y;
        if (!language_isa(y, ty)) {
            language_type_error(language_is_genericmemory(parent) ? "memoryrefmodify!" : "modifyfield!", ty, y);
        }
        language_value_t *yty = language_typeof(y);
        if (isatomic && !needlock) {
            assert(yty == rty);
            if (language_atomic_bool_cmpswap_bits(p, r, y, fsz)) {
                if (hasptr)
                    language_gc_multi_wb(parent, y); // y is immutable
                break;
            }
        }
        else {
            char *px = lock(p, parent, needlock, isatomic);
            int success = memcmp(px, (char*)r, fsz) == 0;
            if (!success && ((language_datatype_t*)rty)->layout->flags.haspadding)
                success = language_egal__bits((language_value_t*)px, r, (language_datatype_t*)rty);
            if (success) {
                if (isunion) {
                    success = (rty == language_nth_union_component(ty, *psel));
                    if (success) {
                        unsigned nth = 0;
                        if (!language_find_union_component(ty, yty, &nth))
                            assert(0 && "invalid field assignment to isbits union");
                        *psel = nth;
                        if (language_is_datatype_singleton((language_datatype_t*)yty))
                            break;
                    }
                    fsz = language_datatype_size((language_datatype_t*)yty); // need to shrink-wrap the final copy
                }
                else {
                    assert(yty == ty && rty == ty);
                }
                memassign_safe(hasptr, px, y, fsz);
            }
            unlock(p, parent, needlock, isatomic);
            if (success) {
                if (hasptr)
                    language_gc_multi_wb(parent, y); // y is immutable
                break;
            }
        }
        language_gc_safepoint();
    }
    // args[0] == r (old)
    // args[1] == y (new)
    language_datatype_t *rettyp = language_apply_modify_type(ty);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    args[0] = language_new_struct(rettyp, args[0], args[1]);
    LANGUAGE_GC_POP();
    return args[0];
}

language_value_t *modify_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *op, language_value_t *rhs, int isatomic)
{
    size_t offs = language_field_offset(st, i);
    language_value_t *ty = language_field_type_concrete(st, i);
    char *p = (char*)v + offs;
    if (language_field_isptr(st, i)) {
        return modify_value(ty, (_Atomic(language_value_t*)*)p, v, op, rhs, isatomic, NULL, NULL);
    }
    else {
        uint8_t *psel = language_is_uniontype(ty) ? (uint8_t*)&p[language_field_size(st, i) - 1] : NULL;
        return modify_bits(ty, p, psel, v, op, rhs, isatomic ? isatomic_object : isatomic_none);
    }
}

inline language_value_t *replace_value(language_value_t *ty, _Atomic(language_value_t*) *p, language_value_t *parent, language_value_t *expected, language_value_t *rhs, int isatomic, language_module_t *mod, language_sym_t *name)
{
    language_datatype_t *rettyp = language_apply_cmpswap_type(ty);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    language_value_t *r = expected;
    int success;
    while (1) {
        success = isatomic ? language_atomic_cmpswap(p, &r, rhs) : language_atomic_cmpswap_release(p, &r, rhs);
        if (success)
            language_gc_wb(parent, rhs);
        if (__unlikely(r == NULL)) {
            if (mod && name)
                language_undefined_var_error(name, (language_value_t*)mod);
            language_throw(language_undefref_exception);
        }
        if (success || !language_egal(r, expected))
            break;
    }
    LANGUAGE_GC_PUSH1(&r);
    r = language_new_struct(rettyp, r, success ? language_true : language_false);
    LANGUAGE_GC_POP();
    return r;
}

inline language_value_t *replace_bits(language_value_t *ty, char *p, uint8_t *psel, language_value_t *parent, language_value_t *expected, language_value_t *rhs, enum atomic_kind isatomic)
{
    language_datatype_t *rettyp = language_apply_cmpswap_type(ty);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    int hasptr;
    int isunion = psel != NULL;
    size_t fsz = language_field_size(rettyp, 0);
    int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
    assert(language_field_offset(rettyp, 1) == fsz);
    language_value_t *rty = ty;
    if (isunion) {
        assert(!isatomic);
        hasptr = 0;
        isatomic = isatomic_none; // this makes GCC happy
    }
    else {
        hasptr = ((language_datatype_t*)ty)->layout->first_ptr >= 0;
        assert(language_typeis(rhs, ty));
    }
    int success;
    language_task_t *ct = language_current_task;
    assert(!language_field_isptr(rettyp, 0));
    language_value_t *r = language_gc_alloc(ct->ptls, language_datatype_size(rettyp), rettyp);
    if (isatomic && !needlock) {
        size_t rsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the compare
        success = language_atomic_cmpswap_bits((language_datatype_t*)rty, r, p, expected, rhs, rsz);
        *((uint8_t*)r + fsz) = success ? 1 : 0;
    }
    else {
        char *px = lock(p, parent, needlock, isatomic);
        if (isunion)
            rty = language_nth_union_component(rty, *psel);
        size_t rsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the compare
        memcpy((char*)r, px, rsz); // copy field // TODO: make this a memmove_refs if relevant
        if (isunion)
            *((uint8_t*)r + fsz - 1) = *psel; // copy union bits
        success = (rty == language_typeof(expected));
        if (success) {
            success = memcmp((char*)r, (char*)expected, rsz) == 0;
            if (!success && ((language_datatype_t*)rty)->layout->flags.haspadding)
                success = language_egal__bits(r, expected, (language_datatype_t*)rty);
        }
        *((uint8_t*)r + fsz) = success ? 1 : 0;
        if (success) {
            language_value_t *rty = language_typeof(rhs);
            if (isunion) {
                rsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the final copy
                unsigned nth = 0;
                if (!language_find_union_component(ty, rty, &nth))
                    assert(0 && "invalid field assignment to isbits union");
                *psel = nth;
                if (language_is_datatype_singleton((language_datatype_t*)rty))
                    return r;
            }
            memassign_safe(hasptr, px, rhs, rsz);
        }
        unlock(p, parent, needlock, isatomic);
    }
    if (success && hasptr)
        language_gc_multi_wb(parent, rhs); // rhs is immutable
    if (!isunion) {
        r = undefref_check((language_datatype_t*)rty, r);
        if (__unlikely(r == NULL))
            language_throw(language_undefref_exception);
    }
    return r;
}

language_value_t *replace_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *expected, language_value_t *rhs, int isatomic)
{
    language_value_t *ty = language_field_type_concrete(st, i);
    if (!language_isa(rhs, ty))
        language_type_error("replacefield!", ty, rhs);
    size_t offs = language_field_offset(st, i);
    char *p = (char*)v + offs;
    if (language_field_isptr(st, i)) {
        return replace_value(ty, (_Atomic(language_value_t*)*)p, v, expected, rhs, isatomic, NULL, NULL);
    }
    else {
        size_t fsz = language_field_size(st, i);
        int isunion = language_is_uniontype(ty);
        uint8_t *psel = isunion ? (uint8_t*)&p[fsz - 1] : NULL;
        return replace_bits(ty, p, psel, v, expected, rhs, isatomic ? isatomic_object : isatomic_none);
    }
}

inline int setonce_bits(language_datatype_t *rty, char *p, language_value_t *parent, language_value_t *rhs, enum atomic_kind isatomic)
{
    size_t fsz = language_datatype_size((language_datatype_t*)rty); // need to shrink-wrap the final copy
    assert(rty->layout->first_ptr >= 0);
    int hasptr = 1;
    int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
    int success;
    if (isatomic && !needlock) {
        success = language_atomic_storeonce_bits(rty, p, rhs, fsz);
    }
    else {
        char *px = lock(p, parent, needlock, isatomic);
        success = undefref_check(rty, (language_value_t*)px) != NULL;
        if (success)
            memassign_safe(hasptr, px, rhs, fsz);
        unlock(p, parent, needlock, isatomic);
    }
    if (success)
        language_gc_multi_wb(parent, rhs); // rhs is immutable
    return success;
}

int set_nth_fieldonce(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic)
{
    language_value_t *ty = language_field_type_concrete(st, i);
    if (!language_isa(rhs, ty))
        language_type_error("setfieldonce!", ty, rhs);
    size_t offs = language_field_offset(st, i);
    int success;
    char *p = (char*)v + offs;
    if (language_field_isptr(st, i)) {
        _Atomic(language_value_t*) *px = (_Atomic(language_value_t*)*)p;
        language_value_t *r = NULL;
        success = isatomic ? language_atomic_cmpswap(px, &r, rhs) : language_atomic_cmpswap_release(px, &r, rhs);
        if (success)
            language_gc_wb(v, rhs);
    }
    else {
        int isunion = language_is_uniontype(ty);
        if (isunion)
            return 0;
        int hasptr = ((language_datatype_t*)ty)->layout->first_ptr >= 0;
        if (!hasptr)
            return 0;
        assert(ty == language_typeof(rhs));
        success = setonce_bits((language_datatype_t*)ty, p, v, rhs, isatomic ? isatomic_object : isatomic_none);
    }
    return success;
}

LANGUAGE_DLLEXPORT int language_field_isdefined(language_value_t *v, size_t i) LANGUAGE_NOTSAFEPOINT
{
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t offs = language_field_offset(st, i);
    _Atomic(language_value_t*) *fld = (_Atomic(language_value_t*)*)((char*)v + offs);
    if (!language_field_isptr(st, i)) {
        language_datatype_t *ft = (language_datatype_t*)language_field_type_concrete(st, i);
        if (!language_is_datatype(ft) || ft->layout->first_ptr < 0)
            return 2; // isbits are always defined
        fld += ft->layout->first_ptr;
    }
    language_value_t *fval = language_atomic_load_relaxed(fld);
    return fval != NULL ? 1 : 0;
}

LANGUAGE_DLLEXPORT int language_field_isdefined_checked(language_value_t *v, size_t i)
{
    if (language_is_module(v)) {
        language_type_error("isdefined", (language_value_t*)language_symbol_type, language_box_long(i + 1));
    }
    if (i >= language_nfields(v))
        return 0;
    return !!language_field_isdefined(v, i);
}

LANGUAGE_DLLEXPORT size_t language_get_field_offset(language_datatype_t *ty, int field)
{
    if (!language_struct_try_layout(ty) || field > language_datatype_nfields(ty) || field < 1)
        language_bounds_error_int((language_value_t*)ty, field);
    return language_field_offset(ty, field - 1);
}

language_value_t *get_nth_pointer(language_value_t *v, size_t i)
{
    language_datatype_t *dt = (language_datatype_t*)language_typeof(v);
    const language_datatype_layout_t *ly = dt->layout;
    uint32_t npointers = ly->npointers;
    if (i >= npointers)
        language_bounds_error_int(v, i);
    const uint8_t *ptrs8 = (const uint8_t *)language_dt_layout_ptrs(ly);
    const uint16_t *ptrs16 = (const uint16_t *)language_dt_layout_ptrs(ly);
    const uint32_t *ptrs32 = (const uint32_t*)language_dt_layout_ptrs(ly);
    uint32_t fld;
    if (ly->flags.fielddesc_type == 0)
        fld = ptrs8[i];
    else if (ly->flags.fielddesc_type == 1)
        fld = ptrs16[i];
    else
        fld = ptrs32[i];
    return language_atomic_load_relaxed((_Atomic(language_value_t*)*)(&((language_value_t**)v)[fld]));
}

LANGUAGE_DLLEXPORT language_value_t *language_get_nth_pointer(language_value_t *v, size_t i)
{
    language_value_t *ptrf = get_nth_pointer(v, i);
    if (__unlikely(ptrf == NULL))
        language_throw(language_undefref_exception);
    return ptrf;
}

LANGUAGE_DLLEXPORT int language_nth_pointer_isdefined(language_value_t *v, size_t i)
{
    return get_nth_pointer(v, i) != NULL;
}

#ifdef __cplusplus
}
#endif
