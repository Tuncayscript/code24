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
 */

/*
  GenericMemory{kind, T} constructors and primitives
*/
#include <stdlib.h>
#include <string.h>
#ifdef _OS_WINDOWS_
#include <malloc.h>
#endif
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// genericmemory constructors ---------------------------------------------------------
LANGUAGE_DLLEXPORT char *language_genericmemory_typetagdata(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT
{
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m))->layout;
    assert(layout->flags.arrayelem_isunion);
    return (char*)m->ptr + m->length * layout->size;
}

#if defined(_P64) && defined(UINT128MAX)
typedef __uint128_t wideint_t;
#else
typedef uint64_t wideint_t;
#endif

#define MAXINTVAL (((size_t)-1)>>1)

language_genericmemory_t *_new_genericmemory_(language_value_t *mtype, size_t nel, int8_t isunion, int8_t zeroinit, size_t elsz)
{
    language_task_t *ct = language_current_task;
    char *data;
    language_genericmemory_t *m;
    if (nel == 0) // zero-sized allocation optimization
        return (language_genericmemory_t*)((language_datatype_t*)mtype)->instance;
    wideint_t prod = (wideint_t)nel * elsz;
    if (isunion) {
        // an extra byte for each isbits union memory element, stored at m->ptr + m->length
        prod += nel;
    }
    if (nel >= MAXINTVAL || prod >= (wideint_t) MAXINTVAL)
        language_exceptionf(language_argumenterror_type, "invalid GenericMemory size: too large for system address width");
    size_t tot = (size_t)prod + LLT_ALIGN(sizeof(language_genericmemory_t),LANGUAGE_SMALL_BYTE_ALIGNMENT);

    int pooled = tot <= GC_MAX_SZCLASS;
    if (!pooled) {
        data = (char*)language_gc_managed_malloc(prod);
        tot = sizeof(language_genericmemory_t) + sizeof(void*);
    }
    m = (language_genericmemory_t*)language_gc_alloc(ct->ptls, tot, mtype);
    if (pooled) {
        data = (char*)m + LANGUAGE_SMALL_BYTE_ALIGNMENT;
    }
    else {
        int isaligned = 1; // language_gc_managed_malloc is always aligned
        language_gc_track_malloced_genericmemory(ct->ptls, m, isaligned);
        language_genericmemory_data_owner_field(m) = (language_value_t*)m;
    }
    m->length = nel;
    m->ptr = data;

    if (zeroinit)
        memset(data, 0, (size_t)prod);
    return m;
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_alloc_genericmemory(language_value_t *mtype, size_t nel)
{
    assert(language_is_datatype(mtype));
    language_genericmemory_t *m = (language_genericmemory_t*)((language_datatype_t*)mtype)->instance;
    const language_datatype_layout_t *layout = ((language_datatype_t*)mtype)->layout;
    if (m == NULL) {
        language_value_t *kind = language_tparam0((language_datatype_t*)mtype);
        if (kind != (language_value_t*)language_not_atomic_sym && kind != (language_value_t*)language_atomic_sym)
            language_error("GenericMemory kind must be :not_atomic or :atomic");
        language_value_t *addrspace = language_tparam2((language_datatype_t*)mtype);
        if (!language_is_addrspacecore(addrspace) || language_unbox_uint8(addrspace) != 0)
            language_error("GenericMemory addrspace must be Core.CPU");
        if (!((language_datatype_t*)mtype)->has_concrete_subtype || layout == NULL)
            language_type_error_rt("GenericMemory", "element type", (language_value_t*)language_type_type, language_tparam1(mtype));
        abort(); // this is checked already by language_get_genericmemory_layout
    }
    assert(((language_datatype_t*)mtype)->has_concrete_subtype && layout != NULL);
    if (nel == 0) // zero-sized allocation optimization fast path
        return m;

    size_t elsz = layout->size;
    int isboxed = layout->flags.arrayelem_isboxed;
    int isunion = layout->flags.arrayelem_isunion;
    int zi = ((language_datatype_t*)mtype)->zeroinit;
    if (isboxed)
        elsz = sizeof(void*);
    return _new_genericmemory_(mtype, nel, isunion, zi, elsz);
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_string_to_genericmemory(language_value_t *str)
{
    if (language_string_len(str) == 0)
        return (language_genericmemory_t*)((language_datatype_t*)language_memory_uint8_type)->instance;
    language_task_t *ct = language_current_task;
    int tsz = sizeof(language_genericmemory_t) + sizeof(void*);
    language_genericmemory_t *m = (language_genericmemory_t*)language_gc_alloc(ct->ptls, tsz, language_memory_uint8_type);
    m->length = language_string_len(str);
    m->ptr = language_string_data(str);
    language_genericmemory_data_owner_field(m) = str;
    return m;
}

// own_buffer != 0 iff GC should call free() on this pointer eventually
LANGUAGE_DLLEXPORT language_genericmemory_t *language_ptr_to_genericmemory(language_value_t *mtype, void *data,
                                                         size_t nel, int own_buffer)
{
    language_task_t *ct = language_current_task;
    assert(language_is_datatype(mtype));
    language_genericmemory_t *m = (language_genericmemory_t*)((language_datatype_t*)mtype)->instance;
    const language_datatype_layout_t *layout = ((language_datatype_t*)mtype)->layout;
    if (m == NULL) {
        language_value_t *kind = language_tparam0((language_datatype_t*)mtype);
        if (kind != (language_value_t*)language_not_atomic_sym && kind != (language_value_t*)language_atomic_sym)
            language_error("GenericMemory kind must be :not_atomic or :atomic");
        language_value_t *addrspace = language_tparam2((language_datatype_t*)mtype);
        if (!language_is_addrspacecore(addrspace) || language_unbox_uint8(addrspace) != 0)
            language_error("GenericMemory addrspace must be Core.CPU");
        if (!((language_datatype_t*)mtype)->has_concrete_subtype || layout == NULL)
            language_type_error_rt("GenericMemory", "element type", (language_value_t*)language_type_type, language_tparam1(mtype));
        abort();
    }
    assert(((language_datatype_t*)mtype)->has_concrete_subtype && layout != NULL);
    //if (nel == 0) {// zero-sized allocation optimization fast path
    //    if (own_buffer)
    //        free(data);
    //    return m;
    //}

    size_t elsz = layout->size;
    size_t align = layout->alignment;
    int isboxed = layout->flags.arrayelem_isboxed;
    int isunion = layout->flags.arrayelem_isunion;
    if (isboxed)
        elsz = sizeof(void*);
    if (isunion)
        language_exceptionf(language_argumenterror_type,
                      "unsafe_wrap: unspecified layout for union element type");
    if (((uintptr_t)data) & ((align > LANGUAGE_HEAP_ALIGNMENT ? LANGUAGE_HEAP_ALIGNMENT : align) - 1))
        language_exceptionf(language_argumenterror_type,
                      "unsafe_wrap: pointer %p is not properly aligned to %u bytes", data, align);
    wideint_t prod = (wideint_t)nel * elsz;
    if (isunion) {
        // an extra byte for each isbits union memory element, stored at m->ptr + m->length
        prod += nel;
    }
    if (nel >= MAXINTVAL || prod >= (wideint_t) MAXINTVAL)
        language_exceptionf(language_argumenterror_type, "invalid GenericMemory size: too large for system address width");
    int tsz = sizeof(language_genericmemory_t) + sizeof(void*);
    m = (language_genericmemory_t*)language_gc_alloc(ct->ptls, tsz, mtype);
    m->ptr = data;
    m->length = nel;
    language_genericmemory_data_owner_field(m) = own_buffer ? (language_value_t*)m : NULL;
    if (own_buffer) {
        int isaligned = 0;  // TODO: allow passing memalign'd buffers
        language_gc_track_malloced_genericmemory(ct->ptls, m, isaligned);
        language_gc_count_allocd(nel*elsz);
    }
    return m;
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_new_genericmemory(language_value_t *mtype, language_value_t *nel)
{
    return language_alloc_genericmemory(mtype, language_unbox_long(nel));
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_pchar_to_genericmemory(const char *str, size_t len)
{
    language_genericmemory_t *m = language_alloc_genericmemory(language_memory_uint8_type, len);
    memcpy(m->ptr, str, len);
    return m;
}

LANGUAGE_DLLEXPORT language_value_t *language_genericmemory_to_string(language_genericmemory_t *m, size_t len)
{
    assert(len <= m->length);
    if (len == 0) {
        // this may seem like purely an optimization (which it also is), but it
        // also ensures that calling `String(m)` doesn't corrupt a previous
        // string also created the same way, where `m = StringVector(_)`.
        return language_an_empty_string;
    }
    int how = language_genericmemory_how(m);
    size_t mlength = m->length;
    m->length = 0;
    if (how != 0) {
        language_value_t *o = language_genericmemory_data_owner_field(m);
        language_genericmemory_data_owner_field(m) = NULL;
        if (how == 3 &&
             ((mlength + sizeof(void*) + 1 <= GC_MAX_SZCLASS) == (len + sizeof(void*) + 1 <= GC_MAX_SZCLASS))) {
            if (language_string_data(o)[len] != '\0')
                language_string_data(o)[len] = '\0';
            if (*(size_t*)o != len)
                *(size_t*)o = len;
            return o;
        }
        LANGUAGE_GC_PUSH1(&o);
        language_value_t *str = language_pchar_to_string((const char*)m->ptr, len);
        LANGUAGE_GC_POP();
        if (how == 1) // TODO: we might like to early-call language_gc_free_memory here instead actually, but hopefully `m` will die soon
            language_gc_count_freed(mlength);
        return str;
    }
    // n.b. how == 0 is always pool-allocated, so the freed bytes are computed from the pool not the object
    return language_pchar_to_string((const char*)m->ptr, len);
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_alloc_memory_any(size_t n)
{
    return language_alloc_genericmemory(language_memory_any_type, n);
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_genericmemory_slice(language_genericmemory_t *mem, void *data, size_t len)
{
    // Given a GenericMemoryRef represented as `language_genericmemory_ref ref = {data, mem}`,
    // return a new GenericMemory that only accesses the slice from the given GenericMemoryRef to
    // the given length if this is possible to return. This allows us to make
    // `length(Array)==length(Array.ref.mem)`, for simplification of this.
    language_datatype_t *dt = (language_datatype_t*)language_typetagof(mem);
    const language_datatype_layout_t *layout = dt->layout;
    // repeated checks here ensure the values cannot overflow, since we know mem->length is a reasonable value
    if (len > mem->length)
        language_exceptionf(language_argumenterror_type, "invalid GenericMemory slice"); // TODO: make a BoundsError
    if (layout->flags.arrayelem_isunion) {
        if (!((size_t)data == 0 && mem->length == len))
            language_exceptionf(language_argumenterror_type, "invalid GenericMemory slice"); // only exact slices are supported
        data = mem->ptr;
    }
    else if (layout->size == 0) {
        if ((size_t)data > mem->length || (size_t)data + len > mem->length)
            language_exceptionf(language_argumenterror_type, "invalid GenericMemory slice"); // TODO: make a BoundsError
        data = mem->ptr;
    }
    else {
        if (data < mem->ptr || (char*)data > (char*)mem->ptr + mem->length * layout->size || (char*)data + len * layout->size > (char*)mem->ptr + mem->length * layout->size)
            language_exceptionf(language_argumenterror_type, "invalid GenericMemory slice"); // TODO: make a BoundsError
    }
    language_task_t *ct = language_current_task;
    language_genericmemory_t *newmem = (language_genericmemory_t*)language_gc_alloc(ct->ptls, sizeof(language_genericmemory_t) + sizeof(void*), dt);
    newmem->length = len;
    newmem->ptr = data;
    language_genericmemory_data_owner_field(newmem) = language_genericmemory_owner(mem);
    return newmem;
}

LANGUAGE_DLLEXPORT void language_genericmemory_copyto(language_genericmemory_t *dest, char* destdata,
                                          language_genericmemory_t *src, char* srcdata,
                                          size_t n) LANGUAGE_NOTSAFEPOINT
{
    language_datatype_t *dt = (language_datatype_t*)language_typetagof(dest);
    if (dt != (language_datatype_t*)language_typetagof(src))
        language_exceptionf(language_argumenterror_type, "language_genericmemory_copyto requires source and dest to have same type");
    const language_datatype_layout_t *layout = dt->layout;
    if (layout->flags.arrayelem_isboxed) {
        _Atomic(void*) * dest_p = (_Atomic(void*)*)destdata;
        _Atomic(void*) * src_p = (_Atomic(void*)*)srcdata;
        language_value_t *owner = language_genericmemory_owner(dest);
        if (__unlikely(language_astaggedvalue(owner)->bits.gc == GC_OLD_MARKED)) {
            language_value_t *src_owner = language_genericmemory_owner(src);
            ssize_t done = 0;
            if (language_astaggedvalue(src_owner)->bits.gc != GC_OLD_MARKED) {
                if (dest_p < src_p || dest_p > src_p + n) {
                    for (; done < n; done++) { // copy forwards
                        void *val = language_atomic_load_relaxed(src_p + done);
                        language_atomic_store_release(dest_p + done, val);
                        // `val` is young or old-unmarked
                        if (val && !(language_astaggedvalue(val)->bits.gc & GC_MARKED)) {
                            language_gc_queue_root(owner);
                            break;
                        }
                    }
                    src_p += done;
                    dest_p += done;
                } else {
                    for (; done < n; done++) { // copy backwards
                        void *val = language_atomic_load_relaxed(src_p + n - done - 1);
                        language_atomic_store_release(dest_p + n - done - 1, val);
                        // `val` is young or old-unmarked
                        if (val && !(language_astaggedvalue(val)->bits.gc & GC_MARKED)) {
                            language_gc_queue_root(owner);
                            break;
                        }
                    }
                }
                n -= done;
            }
        }
        return memmove_refs(dest_p, src_p, n);
    }
    size_t elsz = layout->size;
    char *src_p = srcdata;
    int isbitsunion = layout->flags.arrayelem_isunion;
    if (isbitsunion) {
        char *sourcetypetagdata = language_genericmemory_typetagdata(src);
        char *desttypetagdata = language_genericmemory_typetagdata(dest);
        memmove(desttypetagdata+(size_t)destdata, sourcetypetagdata+(size_t)srcdata, n);
        srcdata = (char*)src->ptr + elsz*(size_t)srcdata;
        destdata = (char*)dest->ptr + elsz*(size_t)destdata;
    }
    if (layout->first_ptr != -1) {
        memmove_refs((_Atomic(void*)*)destdata, (_Atomic(void*)*)srcdata, n * elsz / sizeof(void*));
        language_value_t *owner = language_genericmemory_owner(dest);
        if (__unlikely(language_astaggedvalue(owner)->bits.gc == GC_OLD_MARKED)) {
            language_value_t *src_owner = language_genericmemory_owner(src);
            if (language_astaggedvalue(src_owner)->bits.gc != GC_OLD_MARKED) {
                dt = (language_datatype_t*)language_tparam1(dt);
                for (size_t done = 0; done < n; done++) { // copy forwards
                    char* s = (char*)src_p+done*elsz;
                    if (*((language_value_t**)s+layout->first_ptr) != NULL)
                        language_gc_queue_multiroot(owner, s, dt);
                }
            }
        }
    }
    else {
        memmove(destdata, srcdata, n * elsz);
    }
}


// genericmemory primitives -----------------------------------------------------------

LANGUAGE_DLLEXPORT language_value_t *language_genericmemoryref(language_genericmemory_t *mem, size_t i)
{
    int isatomic = (language_tparam0(language_typetagof(mem)) == (language_value_t*)language_atomic_sym);
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(mem))->layout;
    language_genericmemoryref_t m;
    m.mem = mem;
    m.ptr_or_offset = (layout->flags.arrayelem_isunion || layout->size == 0) ? (void*)i : (void*)((char*)mem->ptr + layout->size * i);
    return language_memoryrefget(m, isatomic);
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_genericmemory_copy_slice(language_genericmemory_t *mem, void *data, size_t len)
{
    language_value_t *mtype = (language_value_t*)language_typetagof(mem);
    const language_datatype_layout_t *layout = ((language_datatype_t*)mtype)->layout;
    size_t elsz = layout->size;
    int isunion = layout->flags.arrayelem_isunion;
    language_genericmemory_t *new_mem = _new_genericmemory_(mtype, len, isunion, 0, elsz);
    if (isunion) {
        memcpy(new_mem->ptr, (char*)mem->ptr + (size_t)data * elsz, len * elsz);
        memcpy(language_genericmemory_typetagdata(new_mem), language_genericmemory_typetagdata(mem) + (size_t)data, len);
    }
    else if (layout->first_ptr != -1) {
        memmove_refs((_Atomic(void*)*)new_mem->ptr, (_Atomic(void*)*)data, len * elsz / sizeof(void*));
    }
    else if (data != NULL) {
        memcpy(new_mem->ptr, data, len * elsz);
    }
    return new_mem;
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_genericmemory_copy(language_genericmemory_t *mem)
{
    language_value_t *mtype = (language_value_t*)language_typetagof(mem);
    const language_datatype_layout_t *layout = ((language_datatype_t*)mtype)->layout;
    return language_genericmemory_copy_slice(mem, layout->flags.arrayelem_isunion || layout->size == 0 ? (void*)0 : mem->ptr, mem->length);
}

LANGUAGE_DLLEXPORT language_value_t *(language_genericmemory_data_owner)(language_genericmemory_t *m) LANGUAGE_NOTSAFEPOINT
{
    return language_genericmemory_data_owner_field(m);
}

language_genericmemoryref_t *language_new_memoryref(language_value_t *typ, language_genericmemory_t *mem, void *data)
{
    language_task_t *ct = language_current_task;
    language_genericmemoryref_t *m = (language_genericmemoryref_t*)language_gc_alloc(ct->ptls, sizeof(language_genericmemoryref_t), typ);
    m->mem = mem;
    m->ptr_or_offset = data;
    return m;
}

// memoryref primitives
LANGUAGE_DLLEXPORT language_genericmemoryref_t language_memoryrefindex(language_genericmemoryref_t m LANGUAGE_ROOTING_ARGUMENT, size_t idx)
{
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    if ((layout->flags.arrayelem_isboxed || !layout->flags.arrayelem_isunion) && layout->size != 0) {
        m.ptr_or_offset = (void*)((char*)m.ptr_or_offset + idx * layout->size);
        assert((char*)m.ptr_or_offset - (char*)m.mem->ptr < layout->size * m.mem->length);
    }
    else {
        m.ptr_or_offset = (void*)((size_t)m.ptr_or_offset + idx);
        assert((size_t)m.ptr_or_offset < m.mem->length);
    }
    return m;
}

static language_value_t *language_ptrmemrefget(language_genericmemoryref_t m LANGUAGE_PROPAGATES_ROOT, int isatomic) LANGUAGE_NOTSAFEPOINT
{
    assert((char*)m.ptr_or_offset - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
    assert(((language_datatype_t*)language_typetagof(m.mem))->layout->flags.arrayelem_isboxed);
    _Atomic(language_value_t*) *ptr = (_Atomic(language_value_t*)*)m.ptr_or_offset;
    language_value_t *elt = isatomic ? language_atomic_load(ptr) : language_atomic_load_relaxed(ptr);
    if (elt == NULL)
        language_throw(language_undefref_exception);
    return elt;
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryrefget(language_genericmemoryref_t m, int isatomic)
{
    assert(isatomic == (language_tparam0(language_typetagof(m.mem)) == (language_value_t*)language_atomic_sym));
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    if (layout->flags.arrayelem_isboxed)
        return language_ptrmemrefget(m, isatomic);
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    char *data = (char*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isunion) {
        assert(!isatomic);
        assert(language_is_uniontype(eltype));
        size_t i = (size_t)data;
        assert(i < m.mem->length);
        // isbits union selector bytes are always stored directly after the last memory element
        uint8_t sel = language_genericmemory_typetagdata(m.mem)[i];
        eltype = language_nth_union_component(eltype, sel);
        data = (char*)m.mem->ptr + i * layout->size;
    }
    if (layout->size == 0) {
        assert(language_is_datatype_singleton((language_datatype_t*)eltype));
        return ((language_datatype_t*)eltype)->instance;
    }
    assert(data - (char*)m.mem->ptr < layout->size * m.mem->length);
    language_value_t *r;
    size_t fsz = language_datatype_size(eltype);
    int needlock = isatomic && fsz > MAX_ATOMIC_SIZE;
    if (isatomic && !needlock) {
        r = language_atomic_new_bits(eltype, data);
    }
    else if (needlock) {
        language_task_t *ct = language_current_task;
        r = language_gc_alloc(ct->ptls, fsz, eltype);
        language_lock_field((language_mutex_t*)data);
        memcpy((char*)r, data + LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT), fsz);
        language_unlock_field((language_mutex_t*)data);
    }
    else {
        // TODO: a finalizer here could make the isunion case not quite right
        r = language_new_bits(eltype, data);
    }
    r = undefref_check((language_datatype_t*)eltype, r);
    if (__unlikely(r == NULL))
        language_throw(language_undefref_exception);
    return r;
}

static int _language_memoryref_isassigned(language_genericmemoryref_t m, int isatomic)
{
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    _Atomic(language_value_t*) *elem = (_Atomic(language_value_t*)*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isboxed) {
    }
    else if (layout->first_ptr >= 0) {
        int needlock = isatomic && layout->size > MAX_ATOMIC_SIZE;
        if (needlock)
            elem = elem + LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT) / sizeof(language_value_t*);
        elem = &elem[layout->first_ptr];
    }
    else {
        return 1;
    }
    return (isatomic ? language_atomic_load(elem) : language_atomic_load_relaxed(elem)) != NULL;
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryref_isassigned(language_genericmemoryref_t m, int isatomic)
{
    return _language_memoryref_isassigned(m, isatomic) ? language_true : language_false;
}

LANGUAGE_DLLEXPORT void language_memoryrefset(language_genericmemoryref_t m LANGUAGE_ROOTING_ARGUMENT, language_value_t *rhs LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED, int isatomic)
{
    assert(isatomic == (language_tparam0(language_typetagof(m.mem)) == (language_value_t*)language_atomic_sym));
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    if (eltype != (language_value_t*)language_any_type && !language_typeis(rhs, eltype)) {
        LANGUAGE_GC_PUSH1(&rhs);
        if (!language_isa(rhs, eltype))
            language_type_error("memoryrefset!", eltype, rhs);
        LANGUAGE_GC_POP();
    }
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    if (layout->flags.arrayelem_isboxed) {
        assert((char*)m.ptr_or_offset - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
        if (isatomic)
            language_atomic_store((_Atomic(language_value_t*)*)m.ptr_or_offset, rhs);
        else
            language_atomic_store_release((_Atomic(language_value_t*)*)m.ptr_or_offset, rhs);
        language_gc_wb(language_genericmemory_owner(m.mem), rhs);
        return;
    }
    int hasptr;
    char *data = (char*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isunion) {
        assert(!isatomic);
        assert(language_is_uniontype(eltype));
        size_t i = (size_t)data;
        assert(i < m.mem->length);
        uint8_t *psel = (uint8_t*)language_genericmemory_typetagdata(m.mem) + i;
        unsigned nth = 0;
        if (!language_find_union_component(eltype, language_typeof(rhs), &nth))
            assert(0 && "invalid genericmemoryset to isbits union");
        *psel = nth;
        hasptr = 0;
        data = (char*)m.mem->ptr + i * layout->size;
    }
    else {
        hasptr = layout->first_ptr >= 0;
    }
    if (layout->size != 0) {
        assert(data - (char*)m.mem->ptr < layout->size * m.mem->length);
        int needlock = isatomic && layout->size > MAX_ATOMIC_SIZE;
        size_t fsz = language_datatype_size((language_datatype_t*)language_typeof(rhs)); // need to shrink-wrap the final copy
        if (isatomic && !needlock) {
            language_atomic_store_bits(data, rhs, fsz);
        }
        else if (needlock) {
            language_lock_field((language_mutex_t*)data);
            memassign_safe(hasptr, data + LLT_ALIGN(sizeof(language_mutex_t), LANGUAGE_SMALL_BYTE_ALIGNMENT), rhs, fsz);
            language_unlock_field((language_mutex_t*)data);
        }
        else {
            memassign_safe(hasptr, data, rhs, fsz);
        }
        if (hasptr)
            language_gc_multi_wb(language_genericmemory_owner(m.mem), rhs); // rhs is immutable
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryrefswap(language_genericmemoryref_t m, language_value_t *rhs, int isatomic)
{
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    if (eltype != (language_value_t*)language_any_type && !language_typeis(rhs, eltype)) {
        if (!language_isa(rhs, eltype))
            language_type_error("memoryrefswap!", eltype, rhs);
    }
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    language_value_t *owner = language_genericmemory_owner(m.mem);
    char *data = (char*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isboxed) {
        assert(data - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
        language_value_t *r;
        if (isatomic)
            r = language_atomic_exchange((_Atomic(language_value_t*)*)data, rhs);
        else
            r = language_atomic_exchange_release((_Atomic(language_value_t*)*)data, rhs);
        language_gc_wb(owner, rhs);
        if (__unlikely(r == NULL))
            language_throw(language_undefref_exception);
        return r;
    }
    uint8_t *psel = NULL;
    if (layout->flags.arrayelem_isunion) {
        assert(!isatomic);
        assert(language_is_uniontype(eltype));
        size_t i = (size_t)data;
        assert(i < m.mem->length);
        psel = (uint8_t*)language_genericmemory_typetagdata(m.mem) + i;
        data = (char*)m.mem->ptr + i * layout->size;
    }
    return swap_bits(eltype, data, psel, owner, rhs, isatomic ? isatomic_field : isatomic_none);
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryrefmodify(language_genericmemoryref_t m, language_value_t *op, language_value_t *rhs, int isatomic)
{
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    language_value_t *owner = language_genericmemory_owner(m.mem);
    char *data = (char*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isboxed) {
        assert(data - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
        return modify_value(eltype, (_Atomic(language_value_t*)*)data, owner, op, rhs, isatomic, NULL, NULL);
    }
    size_t fsz = layout->size;
    uint8_t *psel = NULL;
    if (layout->flags.arrayelem_isunion) {
        assert(!isatomic);
        assert(language_is_uniontype(eltype));
        size_t i = (size_t)data;
        assert(i < m.mem->length);
        psel = (uint8_t*)language_genericmemory_typetagdata(m.mem) + i;
        data = (char*)m.mem->ptr + i * fsz;
    }
    return modify_bits(eltype, data, psel, owner, op, rhs, isatomic ? isatomic_field : isatomic_none);
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryrefreplace(language_genericmemoryref_t m, language_value_t *expected, language_value_t *rhs, int isatomic)
{
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    if (eltype != (language_value_t*)language_any_type && !language_typeis(rhs, eltype)) {
        if (!language_isa(rhs, eltype))
            language_type_error("memoryrefreplace!", eltype, rhs);
    }
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    language_value_t *owner = language_genericmemory_owner(m.mem);
    char *data = (char*)m.ptr_or_offset;
    if (layout->flags.arrayelem_isboxed) {
        assert(data - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
        return replace_value(eltype, (_Atomic(language_value_t*)*)data, owner, expected, rhs, isatomic, NULL, NULL);
    }
    uint8_t *psel = NULL;
    if (layout->flags.arrayelem_isunion) {
        assert(!isatomic);
        assert(language_is_uniontype(eltype));
        size_t i = (size_t)data;
        assert(i < m.mem->length);
        psel = (uint8_t*)language_genericmemory_typetagdata(m.mem) + i;
        data = (char*)m.mem->ptr + i * layout->size;
    }
    return replace_bits(eltype, data, psel, owner, expected, rhs, isatomic ? isatomic_field : isatomic_none);
}

LANGUAGE_DLLEXPORT language_value_t *language_memoryrefsetonce(language_genericmemoryref_t m, language_value_t *rhs, int isatomic)
{
    language_value_t *eltype = language_tparam1(language_typetagof(m.mem));
    if (eltype != (language_value_t*)language_any_type && !language_typeis(rhs, eltype)) {
        if (!language_isa(rhs, eltype))
            language_type_error("memoryrefsetonce!", eltype, rhs);
    }
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    language_value_t *owner = language_genericmemory_owner(m.mem);
    char *data = (char*)m.ptr_or_offset;
    int success;
    if (layout->flags.arrayelem_isboxed) {
        assert(data - (char*)m.mem->ptr < sizeof(language_value_t*) * m.mem->length);
        language_value_t *r = NULL;
        _Atomic(language_value_t*) *px = (_Atomic(language_value_t*)*)data;
        success = isatomic ? language_atomic_cmpswap(px, &r, rhs) : language_atomic_cmpswap_release(px, &r, rhs);
        if (success)
            language_gc_wb(owner, rhs);
    }
    else {
        if (layout->flags.arrayelem_isunion) {
            assert(!isatomic);
            assert(language_is_uniontype(eltype));
            size_t i = (size_t)data;
            assert(i < m.mem->length);
            (void)i;
            success = 0;
        }
        else if (layout->first_ptr < 0) {
            success = 0;
        }
        else {
            success = setonce_bits((language_datatype_t*)eltype, data, owner, rhs, isatomic ? isatomic_field : isatomic_none);
        }
    }
    return success ? language_true : language_false;
}

LANGUAGE_DLLEXPORT language_value_t *ilanguage_genericmemory_owner(language_genericmemory_t *m LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    return language_genericmemory_owner(m);
}
#ifdef __cplusplus
}
#endif
