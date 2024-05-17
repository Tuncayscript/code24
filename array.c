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
  array constructors and primitives
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

#if defined(_P64) && defined(UINT128MAX)
typedef __uint128_t wideint_t;
#else
typedef uint64_t wideint_t;
#endif

#define MAXINTVAL (((size_t)-1)>>1)

LANGUAGE_DLLEXPORT int language_array_validate_dims(size_t *nel, uint32_t ndims, size_t *dims)
{
    size_t i;
    size_t _nel = 1;
    for (i = 0; i < ndims; i++) {
        size_t di = dims[i];
        wideint_t prod = (wideint_t)_nel * (wideint_t)di;
        if (prod >= (wideint_t) MAXINTVAL || di >= MAXINTVAL)
            return 1;
        _nel = prod;
    }
    *nel = _nel;
    return 0;
}

#ifndef LANGUAGE_NDEBUG
static inline int is_ntuple_long(language_value_t *v)
{
    if (!language_is_tuple(v))
        return 0;
    language_value_t *tt = (language_value_t*)language_typetagof(v);
    size_t i, nfields = language_nparams(tt);
    for (i = 0; i < nfields; i++) {
        if (language_tparam(tt, i) != (language_value_t*)language_long_type) {
            return 0;
        }
    }
    return 1;
}
#endif

#define language_array_elsize(a) (((language_datatype_t*)language_typetagof((a)->ref.mem))->layout->size)

static char *language_array_typetagdata(language_array_t *a) LANGUAGE_NOTSAFEPOINT
{
    assert(language_genericmemory_isbitsunion(a->ref.mem));
    return language_genericmemory_typetagdata(a->ref.mem) + (uintptr_t)a->ref.ptr_or_offset;
}

STATIC_INLINE language_array_t *_new_array(language_value_t *atype, language_genericmemory_t *mem, const language_datatype_layout_t *layout, uint32_t ndims, size_t *dims)
{
    language_task_t *ct = language_current_task;
    size_t i;
    int tsz = sizeof(language_array_t) + ndims*sizeof(size_t);
    language_array_t *a = (language_array_t*)language_gc_alloc(ct->ptls, tsz, atype);
    a->ref.mem = mem;
    if (layout->flags.arrayelem_isunion || layout->size == 0)
        a->ref.ptr_or_offset = 0;
    else
        a->ref.ptr_or_offset = mem->ptr;
    for (i = 0; i < ndims; i++)
        a->dimsize[i] = dims[i];
    return a;
}

STATIC_INLINE language_array_t *new_array(language_value_t *atype, uint32_t ndims, size_t *dims)
{
    size_t nel;
    if (language_array_validate_dims(&nel, ndims, dims))
        language_exceptionf(language_argumenterror_type, "invalid Array dimensions: too large for system address width");
    if (*(size_t*)language_tparam1(atype) != ndims)
        language_exceptionf(language_argumenterror_type, "invalid Array dimensions");
    language_value_t *mtype = language_field_type_concrete((language_datatype_t*)language_field_type_concrete((language_datatype_t*)atype, 0), 1);
    // extra byte for all julia allocated byte vectors
    language_genericmemory_t *mem = language_alloc_genericmemory(mtype, nel);
    LANGUAGE_GC_PUSH1(&mem);
    language_array_t *a = _new_array(atype, mem, ((language_datatype_t*)mtype)->layout, ndims, dims);
    LANGUAGE_GC_POP();
    return a;
}

language_genericmemory_t *_new_genericmemory_(language_value_t *mtype, size_t nel, int8_t isunion, int8_t zeroinit, size_t elsz);

LANGUAGE_DLLEXPORT language_genericmemory_t *language_string_to_genericmemory(language_value_t *str);

LANGUAGE_DLLEXPORT language_array_t *language_ptr_to_array_1d(language_value_t *atype, void *data,
                                            size_t nel, int own_buffer)
{
    if (*(size_t*)language_tparam1(atype) != 1)
        language_exceptionf(language_argumenterror_type, "invalid Array dimensions");
    language_value_t *mtype = language_field_type_concrete((language_datatype_t*)language_field_type_concrete((language_datatype_t*)atype, 0), 1);
    language_genericmemory_t *mem = language_ptr_to_genericmemory(mtype, data, nel, own_buffer);
    LANGUAGE_GC_PUSH1(&mem);
    language_array_t *a = _new_array(atype, mem, ((language_datatype_t*)mtype)->layout, 1, &nel);
    LANGUAGE_GC_POP();
    return a;
}

LANGUAGE_DLLEXPORT language_array_t *language_ptr_to_array(language_value_t *atype, void *data,
                                         language_value_t *_dims, int own_buffer)
{
    size_t ndims = language_nfields(_dims);
    assert(is_ntuple_long(_dims));
    size_t *dims = (size_t*)_dims;
    size_t nel;
    if (language_array_validate_dims(&nel, ndims, dims))
        language_exceptionf(language_argumenterror_type, "invalid Array dimensions: too large for system address width");
    if (*(size_t*)language_tparam1(atype) != ndims)
        language_exceptionf(language_argumenterror_type, "invalid Array dimensions");
    language_value_t *mtype = language_field_type_concrete((language_datatype_t*)language_field_type_concrete((language_datatype_t*)atype, 0), 1);
    language_genericmemory_t *mem = language_ptr_to_genericmemory(mtype, data, nel, own_buffer);
    LANGUAGE_GC_PUSH1(&mem);
    language_array_t *a = _new_array(atype, mem, ((language_datatype_t*)mtype)->layout, ndims, dims);
    LANGUAGE_GC_POP();
    return a;
}

LANGUAGE_DLLEXPORT language_value_t *language_array_to_string(language_array_t *a)
{
    size_t len = language_array_nrows(a); // only for Vector
    if (len == 0) {
        // this may seem like purely an optimization (which it also is), but it
        // also ensures that calling `String(a)` doesn't corrupt a previous
        // string also created the same way, where `a = StringVector(_)`.
        return language_an_empty_string;
    }
    language_value_t *str;
    if (a->ref.ptr_or_offset == a->ref.mem->ptr)
        str = language_genericmemory_to_string(a->ref.mem, len);
    else
        str = language_pchar_to_string(language_array_data(a, char), len);
    a->ref.mem = (language_genericmemory_t*)((language_datatype_t*)language_memory_uint8_type)->instance;
    a->ref.ptr_or_offset = a->ref.mem->ptr;
    a->dimsize[0] = 0;
    return str;
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_1d(language_value_t *atype, size_t nr)
{
    return new_array(atype, 1, &nr);
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_2d(language_value_t *atype, size_t nr, size_t nc)
{
    size_t dims[2] = {nr, nc};
    return new_array(atype, 2, &dims[0]);
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_3d(language_value_t *atype, size_t nr, size_t nc, size_t z)
{
    size_t dims[3] = {nr, nc, z};
    return new_array(atype, 3, &dims[0]);
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_nd(language_value_t *atype, size_t *dims, size_t ndims)
{
    return new_array(atype, ndims, dims);
}

LANGUAGE_DLLEXPORT language_array_t *language_pchar_to_array(const char *str, size_t len)
{
    language_array_t *a = language_alloc_array_1d(language_array_uint8_type, len);
    assert(language_array_data(a, char));
    memcpy(language_array_data(a, char), str, len);
    return a;
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_vec_any(size_t n)
{
    return language_alloc_array_1d(language_array_any_type, n);
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_array_type(language_value_t *type, size_t dim)
{
    language_value_t *boxed_dim = language_box_long(dim);
    LANGUAGE_GC_PUSH1(&boxed_dim);
    language_value_t *ret = language_apply_type2((language_value_t*)language_array_type, type, boxed_dim);
    LANGUAGE_GC_POP();
    return ret;
}

LANGUAGE_DLLEXPORT void language_array_grow_end(language_array_t *a, size_t inc)
{
    size_t n = language_array_nrows(a);
    size_t elsz = language_array_elsize(a);
    char *data = language_array_data(a,char);
    language_value_t *mtype = (language_value_t*)language_typetagof(a->ref.mem);
    int isbitsunion = language_genericmemory_isbitsunion(a->ref.mem);
    size_t newnrows = n + inc;
    if (!isbitsunion && elsz == 0) {
        language_genericmemory_t *newmem = language_alloc_genericmemory(mtype, MAXINTVAL - 1);
        a->ref.mem = newmem;
        language_gc_wb(a, newmem);
        a->dimsize[0] = newnrows;
        return;
    }
    size_t oldoffset = isbitsunion ? (size_t)data : (data - (char*)a->ref.mem->ptr) / elsz;
    if (isbitsunion)
        data = (char*)a->ref.mem->ptr + oldoffset * elsz;
    size_t oldmaxsize = a->ref.mem->length;
    size_t reqmaxsize = oldoffset + newnrows;
    if (__unlikely(reqmaxsize > oldmaxsize)) {
        size_t newmaxsize;
        if (oldmaxsize < 4) // typical sequence: 0, // 4, // 6, 9, 13, 19, 28, 42, // 50, 60, 72, ...
            newmaxsize = 4;
        else if (oldmaxsize < 48)
            newmaxsize = oldmaxsize*3/2; // grow by 50%
        else
            newmaxsize = oldmaxsize*6/5; // grow by 20%
        if (newmaxsize < reqmaxsize)
            newmaxsize = reqmaxsize;
        // TODO: round this up to newmaxsize < GC_MAX_SZCLASS ? language_gc_sizeclasses[language_gc_szclass(newmaxsize)] : LLT_ALIGN(newmaxsize, 4096), after accounting for the object header (24 bytes)
        language_genericmemory_t *newmem = language_alloc_genericmemory(mtype, newmaxsize);
        char *newdata = (char*)newmem->ptr + oldoffset * elsz;
        memcpy(newdata, data, n * elsz);
        if (isbitsunion) {
            char *typetagdata = language_array_typetagdata(a);
            char *newtypetagdata = (char*)newmem->ptr + newmaxsize * elsz + oldoffset;
            memcpy(newtypetagdata, typetagdata, n);
        }
        a->ref.mem = newmem;
        language_gc_wb(a, newmem);
        if (isbitsunion)
            a->ref.ptr_or_offset = (void*)oldoffset;
        else
            a->ref.ptr_or_offset = newdata;
    }
    a->dimsize[0] = newnrows;
}

LANGUAGE_DLLEXPORT void language_array_del_end(language_array_t *a, size_t dec)
{
    // assume inbounds, assume unshared
    size_t n = language_array_nrows(a);
    if (__unlikely(n < dec))
        language_bounds_error_int((language_value_t*)a, 0);
    if (__unlikely(dec == 0))
        return;
    n -= dec;
    a->dimsize[0] = n;
    // don't leave behind deleted data
    if (language_is_genericmemory_zeroinit(a->ref.mem) && !language_genericmemory_isbitsunion(a->ref.mem)) {
        size_t elsz = language_array_elsize(a);
        memset(language_array_data(a,char) + n * elsz, 0, elsz * dec);
    }
}

LANGUAGE_DLLEXPORT void language_array_ptr_1d_push(language_array_t *a, language_value_t *item)
{
    assert(language_typetagis(a, language_array_any_type));
    language_array_grow_end(a, 1);
    size_t n = language_array_nrows(a);
    language_array_ptr_set(a, n - 1, item);
}

LANGUAGE_DLLEXPORT void language_array_ptr_1d_append(language_array_t *a, language_array_t *a2)
{
    assert(language_typetagis(a, language_array_any_type));
    assert(language_typetagis(a2, language_array_any_type));
    size_t i;
    size_t n = language_array_nrows(a);
    size_t n2 = language_array_nrows(a2);
    language_array_grow_end(a, n2);
    for (i = 0; i < n2; i++) {
        language_array_ptr_set(a, n + i, language_array_ptr_ref(a2, i));
    }
}

LANGUAGE_DLLEXPORT language_genericmemory_t *language_genericmemory_copy_slice(language_genericmemory_t *mem, void *data, size_t len);

LANGUAGE_DLLEXPORT language_array_t *language_array_copy(language_array_t *ary)
{
    size_t len = language_array_len(ary);
    language_genericmemory_t *mem = language_genericmemory_copy_slice(ary->ref.mem, ary->ref.ptr_or_offset, len);
    LANGUAGE_GC_PUSH1(&mem);
    language_array_t *new_ary = _new_array((language_value_t*)language_typetagof(ary), mem, ((language_datatype_t*)language_typetagof(ary->ref.mem))->layout, language_array_ndims(ary), &ary->dimsize[0]);
    LANGUAGE_GC_POP();
    return new_ary;
}

LANGUAGE_DLLEXPORT language_value_t *language_alloc_string(size_t len)
{
    if (len == 0)
        return language_an_empty_string;
    size_t sz = sizeof(size_t) + len + 1; // add space for trailing \nul protector and size
    if (sz < len) // overflow
        language_throw(language_memory_exception);
    language_task_t *ct = language_current_task;
    language_value_t *s;
    language_ptls_t ptls = ct->ptls;
    const size_t allocsz = sz + sizeof(language_taggedvalue_t);
    if (sz <= GC_MAX_SZCLASS) {
        int pool_id = language_gc_szclass_align8(allocsz);
        language_gc_pool_t *p = &ptls->heap.norm_pools[pool_id];
        int osize = language_gc_sizeclasses[pool_id];
        // We call `language_gc_pool_alloc_noinline` instead of `language_gc_pool_alloc` to avoid double-counting in
        // the Allocations Profiler. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
        s = language_gc_pool_alloc_noinline(ptls, (char*)p - (char*)ptls, osize);
    }
    else {
        if (allocsz < sz) // overflow in adding offs, size was "negative"
            language_throw(language_memory_exception);
        s = language_gc_big_alloc_noinline(ptls, allocsz);
    }
    language_set_typetagof(s, language_string_tag, 0);
    maybe_record_alloc_to_profile(s, len, language_string_type);
    *(size_t*)s = len;
    language_string_data(s)[len] = 0;
    return s;
}

LANGUAGE_DLLEXPORT language_value_t *language_pchar_to_string(const char *str, size_t len)
{
    language_value_t *s = language_alloc_string(len);
    if (len > 0)
        memcpy(language_string_data(s), str, len);
    return s;
}

LANGUAGE_DLLEXPORT language_value_t *language_cstr_to_string(const char *str)
{
    return language_pchar_to_string(str, strlen(str));
}


// deprecated and unused internally, but some packages (notably OrderedCollections.jl) have not yet started to use the modern Base.unsetindex API
LANGUAGE_DLLEXPORT void language_arrayunset(language_array_t *a, size_t i)
{
    if (i >= language_array_len(a))
        language_bounds_error_int((language_value_t*)a, i + 1);
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(a->ref.mem))->layout;
    if (layout->flags.arrayelem_isboxed) {
        language_atomic_store_relaxed(language_array_data(a,_Atomic(language_value_t*)) + i, NULL);
    }
    else if (layout->first_ptr >= 0) {
        size_t elsize = layout->size;
        language_assume(elsize >= sizeof(void*) && elsize % sizeof(void*) == 0);
        memset(language_array_data(a,char) + elsize * i, 0, elsize);
    }
}

#ifdef __cplusplus
}
#endif
