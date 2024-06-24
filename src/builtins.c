/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: Implementations of built-in functions

#include "platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#if defined(_OS_WINDOWS_)
#include <malloc.h>
#else
#include <unistd.h>
#endif
#include <ctype.h>
#include "code.h"
#include "code_internal.h"
#include "builtin_proto.h"
#include "intrinsics.h"
#include "code_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// egal and object_id ---------------------------------------------------------

static int bits_equal(const void *a, const void *b, int sz) LANGUAGE_NOTSAFEPOINT
{
    switch (sz) {
    case 1:  return *(uint8_t*)a == *(uint8_t*)b;
        // Let compiler constant folds the following, though we may not know alignment of them
    case 2:  return memcmp(a, b, 2) == 0;
    case 4:  return memcmp(a, b, 4) == 0;
    case 8:  return memcmp(a, b, 8) == 0;
    default: return memcmp(a, b, sz) == 0;
    }
}

// The frequently used language_egal function deserves special attention when it
// comes to performance which is made challenging by the fact that the
// function has to handle quite a few different cases and because it is
// called recursively.  To optimize performance many special cases are
// handle with separate comparisons which can dramatically reduce the run
// time of the function.  The compiler can translate these simple tests
// with little effort, e.g., few registers are used.
//
// The complex cases require more effort and more registers to be translated
// efficiently.  The effected cases include comparing tuples and fields.  If
// the code to perform these operation would be inlined in the language_egal
// function then the compiler would generate at the or close to the top of
// the function a prologue which saves all the callee-save registers and at
// the end the respective epilogue.  The result is that even the fast cases
// are slowed down.
//
// The solution is to keep the code in language_egal simple and split out the
// (more) complex cases into their own functions which are marked with
// NOINLINE.
static int NOINLINE compare_svec(language_svec_t *a, language_svec_t *b) LANGUAGE_NOTSAFEPOINT
{
    size_t i, l = language_svec_len(a);
    if (l != language_svec_len(b))
        return 0;
    for (i = 0; i < l; i++) {
        if (!language_egal(language_svecref(a, i), language_svecref(b, i)))
            return 0;
    }
    return 1;
}

// See comment above for an explanation of NOINLINE.
static int NOINLINE compare_fields(const language_value_t *a, const language_value_t *b, language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT
{
    size_t nf = language_datatype_nfields(dt);
    // npointers is used at end, but fetched here for locality with nfields.
    int npointers = ((language_datatype_t*)dt)->layout->npointers;
    for (size_t f = 0; f < nf; f++) {
        size_t offs = language_field_offset(dt, f);
        char *ao = (char*)a + offs;
        char *bo = (char*)b + offs;
        if (language_field_isptr(dt, f)) {
            // Save ptr recursion until the end -- only recurse if otherwise equal
            // Note that we also skip comparing the pointers for null here, because
            // null fields are rare so it can save CPU to delay this read too.
            continue;
        }
        else {
            language_datatype_t *ft = (language_datatype_t*)language_field_type_concrete(dt, f);
            if (language_is_uniontype(ft)) {
                size_t idx = language_field_size(dt, f) - 1;
                uint8_t asel = ((uint8_t*)ao)[idx];
                uint8_t bsel = ((uint8_t*)bo)[idx];
                if (asel != bsel)
                    return 0;
                ft = (language_datatype_t*)language_nth_union_component((language_value_t*)ft, asel);
            }
            else if (ft->layout->first_ptr >= 0) {
                // If the field is a inline immutable that can be undef
                // we need to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                int32_t idx = ft->layout->first_ptr;
                language_value_t *ptra = ((language_value_t**)ao)[idx];
                language_value_t *ptrb = ((language_value_t**)bo)[idx];
                if ((ptra == NULL) != (ptrb == NULL)) {
                    return 0;
                }
                else if (ptra == NULL) { // implies ptrb == NULL
                    continue; // skip this field (it is #undef)
                }
            }
            if (!ft->layout->flags.haspadding && ft->layout->flags.isbitsegal) {
                if (!bits_equal(ao, bo, ft->layout->size))
                    return 0;
            }
            else {
                assert(language_datatype_nfields(ft) > 0);
                if (!compare_fields((language_value_t*)ao, (language_value_t*)bo, ft))
                    return 0;
            }
        }
    }
    // If we've gotten here, the objects are bitwise equal, besides their pointer fields.
    // Now, we will recurse into language_egal for the pointed-to elements, which might be
    // arbitrarily expensive.
    for (size_t p = 0; p < npointers; p++) {
        size_t offs = language_ptr_offset(dt, p);
        language_value_t *af = ((language_value_t**)a)[offs];
        language_value_t *bf = ((language_value_t**)b)[offs];
        if (af != bf) {
            if (af == NULL || bf == NULL)
                return 0;
            if (!language_egal(af, bf))
                return 0;
        }
    }
    return 1;
}

static int egal_types(const language_value_t *a, const language_value_t *b, language_typeenv_t *env, int tvar_names) LANGUAGE_NOTSAFEPOINT
{
    if (a == b)
        return 1;
    uintptr_t dtag = language_typetagof(a);
    if (dtag != language_typetagof(b))
        return 0;
    if (dtag == language_datatype_tag << 4) {
        language_datatype_t *dta = (language_datatype_t*)a;
        language_datatype_t *dtb = (language_datatype_t*)b;
        if (dta->name != dtb->name)
            return 0;
        size_t i, l = language_nparams(dta);
        if (language_nparams(dtb) != l)
            return 0;
        for (i = 0; i < l; i++) {
            if (!egal_types(language_tparam(dta, i), language_tparam(dtb, i), env, tvar_names))
                return 0;
        }
        return 1;
    }
    if (dtag == language_tvar_tag << 4) {
        language_typeenv_t *pe = env;
        while (pe != NULL) {
            if (pe->var == (language_tvar_t*)a)
                return pe->val == b;
            pe = pe->prev;
        }
        return 0;
    }
    if (dtag == language_unionall_tag << 4) {
        language_unionall_t *ua = (language_unionall_t*)a;
        language_unionall_t *ub = (language_unionall_t*)b;
        if (tvar_names && ua->var->name != ub->var->name)
            return 0;
        if (!(egal_types(ua->var->lb, ub->var->lb, env, tvar_names) && egal_types(ua->var->ub, ub->var->ub, env, tvar_names)))
            return 0;
        language_typeenv_t e = { ua->var, (language_value_t*)ub->var, env };
        return egal_types(ua->body, ub->body, &e, tvar_names);
    }
    if (dtag == language_uniontype_tag << 4) {
        return egal_types(((language_uniontype_t*)a)->a, ((language_uniontype_t*)b)->a, env, tvar_names) &&
            egal_types(((language_uniontype_t*)a)->b, ((language_uniontype_t*)b)->b, env, tvar_names);
    }
    if (dtag == language_vararg_tag << 4) {
        language_vararg_t *vma = (language_vararg_t*)a;
        language_vararg_t *vmb = (language_vararg_t*)b;
        language_value_t *vmaT = vma->T ? vma->T : (language_value_t*)language_any_type;
        language_value_t *vmbT = vmb->T ? vmb->T : (language_value_t*)language_any_type;
        if (!egal_types(vmaT, vmbT, env, tvar_names))
            return 0;
        if (vma->N && vmb->N)
            return egal_types(vma->N, vmb->N, env, tvar_names);
        return !vma->N && !vmb->N;
    }
    assert(dtag == language_symbol_tag << 4 || dtag == language_module_tag << 4 || !((language_datatype_t*)language_typeof(a))->name->mutabl);
    return language_egal__bitstag(a, b, dtag);
}

LANGUAGE_DLLEXPORT int language_types_egal(language_value_t *a, language_value_t *b)
{
    return egal_types(a, b, NULL, 0);
}

LANGUAGE_DLLEXPORT int (language_egal)(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED) LANGUAGE_NOTSAFEPOINT
{
    // warning: a,b may NOT have been gc-rooted by the caller
    return language_egal(a, b);
}

LANGUAGE_DLLEXPORT int language_egal__unboxed(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, uintptr_t dtag) LANGUAGE_NOTSAFEPOINT
{
    // warning: a,b may NOT have been gc-rooted by the caller
    return language_egal__unboxed_(a, b, dtag);
}

LANGUAGE_DLLEXPORT int language_egal__bitstag(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, uintptr_t dtag) LANGUAGE_NOTSAFEPOINT
{
    if (dtag < language_max_tags << 4) {
        switch ((enum language_small_typeof_tags)(dtag >> 4)) {
        case language_int8_tag:
        case language_uint8_tag:
            return *(uint8_t*)a == *(uint8_t*)b;
        case language_int16_tag:
        case language_uint16_tag:
            return *(uint16_t*)a == *(uint16_t*)b;
        case language_int32_tag:
        case language_uint32_tag:
        case language_char_tag:
            return *(uint32_t*)a == *(uint32_t*)b;
        case language_int64_tag:
        case language_uint64_tag:
            return *(uint64_t*)a == *(uint64_t*)b;
        case language_unionall_tag:
            return egal_types(a, b, NULL, 1);
        case language_uniontype_tag:
            return compare_fields(a, b, language_uniontype_type);
        case language_vararg_tag:
            return compare_fields(a, b, language_vararg_type);
        case language_task_tag:
        case language_tvar_tag:
        case language_symbol_tag:
        case language_module_tag:
        case language_bool_tag:
            return 0;
        case language_simplevector_tag:
            return compare_svec((language_svec_t*)a, (language_svec_t*)b);
        case language_string_tag: {
                size_t l = language_string_len(a);
                if (language_string_len(b) != l)
                    return 0;
                return !memcmp(language_string_data(a), language_string_data(b), l);
            }
        case language_datatype_tag: {
                language_datatype_t *dta = (language_datatype_t*)a;
                language_datatype_t *dtb = (language_datatype_t*)b;
                if (dta->name != dtb->name)
                    return 0;
                if (dta->name != language_tuple_typename && (dta->isconcretetype || dtb->isconcretetype))
                    return 0;
                return compare_svec(dta->parameters, dtb->parameters);
            }
#ifndef NDEBUG
        default:
#endif
        case language_max_tags:
        case language_null_tag:
        case language_typeofbottom_tag:
        case language_tags_count:
            abort();
        }
    }
    return language_egal__bits(a, b, (language_datatype_t*)dtag);
}

inline int language_egal__bits(const language_value_t *a LANGUAGE_MAYBE_UNROOTED, const language_value_t *b LANGUAGE_MAYBE_UNROOTED, language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT
{
    size_t sz = language_datatype_size(dt);
    if (sz == 0)
        return 1;
    size_t nf = language_datatype_nfields(dt);
    if (nf == 0 || (!dt->layout->flags.haspadding && dt->layout->flags.isbitsegal))
        return bits_equal(a, b, sz);
    return compare_fields(a, b, dt);
}

// object_id ------------------------------------------------------------------

static uintptr_t bits_hash(const void *b, size_t sz) LANGUAGE_NOTSAFEPOINT
{
    switch (sz) {
    case 1:  return int32hash(*(const int8_t*)b);
    case 2:  return int32hash(language_load_unaligned_i16(b));
    case 4:  return int32hash(language_load_unaligned_i32(b));
#ifdef _P64
    case 8:  return int64hash(language_load_unaligned_i64(b));
#else
    case 8:  return int64to32hash(language_load_unaligned_i64(b));
#endif
    default:
#ifdef _P64
        return memhash((const char*)b, sz);
#else
        return memhash32((const char*)b, sz);
#endif
    }
}

static uintptr_t NOINLINE hash_svec(language_svec_t *v) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t h = 0;
    size_t i, l = language_svec_len(v);
    for (i = 0; i < l; i++) {
        language_value_t *x = language_svecref(v, i);
        uintptr_t u = (x == NULL) ? 0 : language_object_id(x);
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t immut_id_(language_datatype_t *dt, language_value_t *v, uintptr_t h) LANGUAGE_NOTSAFEPOINT;

typedef struct _varidx {
    language_tvar_t *var;
    struct _varidx *prev;
} language_varidx_t;

static uintptr_t type_object_id_(language_value_t *v, language_varidx_t *env) LANGUAGE_NOTSAFEPOINT
{
    if (v == NULL)
        return 0;
    language_datatype_t *tv = (language_datatype_t*)language_typeof(v);
    if (tv == language_tvar_type) {
        language_varidx_t *pe = env;
        int i = 0;
        while (pe != NULL) {
            if (pe->var == (language_tvar_t*)v)
                return (i<<8) + 42;
            i++;
            pe = pe->prev;
        }
        uintptr_t bits = language_astaggedvalue(v)->header;
        if (bits & GC_IN_IMAGE)
            return ((uintptr_t*)v)[-2];
        return inthash((uintptr_t)v);
    }
    if (tv == language_uniontype_type) {
        return bitmix(bitmix(language_object_id((language_value_t*)tv),
                             type_object_id_(((language_uniontype_t*)v)->a, env)),
                      type_object_id_(((language_uniontype_t*)v)->b, env));
    }
    if (tv == language_unionall_type) {
        language_unionall_t *u = (language_unionall_t*)v;
        uintptr_t h = u->var->name->hash;
        h = bitmix(h, type_object_id_(u->var->lb, env));
        h = bitmix(h, type_object_id_(u->var->ub, env));
        language_varidx_t e = { u->var, env };
        return bitmix(h, type_object_id_(u->body, &e));
    }
    if (tv == language_datatype_type) {
        language_datatype_t *dtv = (language_datatype_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
        uintptr_t h = ~dtv->name->hash;
        size_t i, l = language_nparams(v);
        for (i = 0; i < l; i++) {
            h = bitmix(h, type_object_id_(language_tparam(v, i), env));
        }
        return h;
    }
    if (tv == language_vararg_type) {
        language_vararg_t *vm = (language_vararg_t*)v;
        language_value_t *t = vm->T ? vm->T : (language_value_t*)language_any_type;
        language_value_t *n = vm->N ? vm->N : language_nothing;
        return bitmix(type_object_id_(t, env),
            type_object_id_(n, env));
    }
    if (tv == language_symbol_type)
        return ((language_sym_t*)v)->hash;
    if (tv == language_module_type)
        return ((language_module_t*)v)->hash;
    assert(!tv->name->mutabl);
    return immut_id_(tv, v, tv->hash);
}

static uintptr_t immut_id_(language_datatype_t *dt, language_value_t *v, uintptr_t h) LANGUAGE_NOTSAFEPOINT
{
    size_t sz = language_datatype_size(dt);
    if (sz == 0)
        return ~h;
    size_t f, nf = language_datatype_nfields(dt);
    if (nf == 0 || (!dt->layout->flags.haspadding && dt->layout->flags.isbitsegal && dt->layout->npointers == 0)) {
        // operate element-wise if there are unused bits inside,
        // otherwise just take the whole data block at once
        // a few select pointers (notably symbol) also have special hash values
        // which may affect the stability of the objectid hash, even though
        // they don't affect egal comparison
        return bits_hash(v, sz) ^ h;
    }
    if (dt == language_unionall_type)
        return type_object_id_(v, NULL);
    for (f = 0; f < nf; f++) {
        size_t offs = language_field_offset(dt, f);
        char *vo = (char*)v + offs;
        uintptr_t u;
        if (language_field_isptr(dt, f)) {
            language_value_t *f = *(language_value_t**)vo;
            u = (f == NULL) ? 0 : language_object_id(f);
        }
        else {
            language_datatype_t *fieldtype = (language_datatype_t*)language_field_type_concrete(dt, f);
            if (language_is_uniontype(fieldtype)) {
                uint8_t sel = ((uint8_t*)vo)[language_field_size(dt, f) - 1];
                fieldtype = (language_datatype_t*)language_nth_union_component((language_value_t*)fieldtype, sel);
            }
            assert(language_is_datatype(fieldtype) && !fieldtype->name->abstract && !fieldtype->name->mutabl);
            int32_t first_ptr = fieldtype->layout->first_ptr;
            if (first_ptr >= 0 && ((language_value_t**)vo)[first_ptr] == NULL) {
                // If the field is a inline immutable that can be can be undef
                // we need to check to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                u = 0;
            }
            else {
                u = immut_id_(fieldtype, (language_value_t*)vo, 0);
            }
        }
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t NOINLINE language_object_id__cold(uintptr_t tv, language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    language_datatype_t *dt = (language_datatype_t*)language_to_typeof(tv);
    if (dt->name->mutabl) {
        if (dt == language_string_type) {
#ifdef _P64
            return memhash_seed(language_string_data(v), language_string_len(v), 0xedc3b677);
#else
            return memhash32_seed(language_string_data(v), language_string_len(v), 0xedc3b677);
#endif
        }
        if (dt == language_simplevector_type)
            return hash_svec((language_svec_t*)v);
        if (dt == language_datatype_type) {
            language_datatype_t *dtv = (language_datatype_t*)v;
            uintptr_t h = ~dtv->name->hash;
            return bitmix(h, hash_svec(dtv->parameters));
        }
        if (dt == language_module_type) {
            language_module_t *m = (language_module_t*)v;
            return m->hash;
        }
        uintptr_t bits = language_astaggedvalue(v)->header;
        if (bits & GC_IN_IMAGE)
            return ((uintptr_t*)v)[-2];
        return inthash((uintptr_t)v);
    }
    return immut_id_(dt, v, dt->hash);
}

LANGUAGE_DLLEXPORT inline uintptr_t language_object_id_(uintptr_t tv, language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    if (tv == language_symbol_tag << 4) {
        return ((language_sym_t*)v)->hash;
    }
    else if (tv == language_datatype_tag << 4) {
        language_datatype_t *dtv = (language_datatype_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
    }
    else if (tv == (uintptr_t)language_typename_type) {
        return ((language_typename_t*)v)->hash;
    }
    return language_object_id__cold(tv, v);
}


LANGUAGE_DLLEXPORT uintptr_t language_object_id(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return language_object_id_(language_typetagof(v), v);
}

// eq hash table --------------------------------------------------------------

#include "iddict.c"
#include "idset.c"

// object model and type primitives -------------------------------------------

LANGUAGE_CALLABLE(language_f_is)
{
    LANGUAGE_NARGS(===, 2, 2);
    return language_egal(args[0], args[1]) ? language_true : language_false;
}

LANGUAGE_CALLABLE(language_f_typeof)
{
    LANGUAGE_NARGS(typeof, 1, 1);
    return language_typeof(args[0]);
}

LANGUAGE_CALLABLE(language_f_sizeof)
{
    LANGUAGE_NARGS(sizeof, 1, 1);
    language_value_t *x = args[0];
    if (language_is_unionall(x) || language_is_uniontype(x)) {
        x = language_unwrap_unionall(x);
        size_t elsize = 0;
        int isinline = language_uniontype_size(x, &elsize);
        if (isinline)
            return language_box_long(elsize);
        if (!language_is_datatype(x))
            language_error("Argument is an abstract type and does not have a definite size.");
    }
    if (language_is_datatype(x)) {
        language_datatype_t *dx = (language_datatype_t*)x;
        if (!language_struct_try_layout(dx)) {
            if (dx->name->abstract)
                language_errorf("Abstract type %s does not have a definite size.", language_symbol_name(dx->name->name));
            else
                language_errorf("Argument is an incomplete %s type and does not have a definite size.", language_symbol_name(dx->name->name));
        }
        if (language_is_layout_opaque(dx->layout)) // includes all GenericMemory{kind,T}
            language_errorf("Type %s does not have a definite size.", language_symbol_name(dx->name->name));
        return language_box_long(language_datatype_size(x));
    }
    if (x == language_bottom_type)
        language_error("The empty type does not have a definite size since it does not have instances.");
    if (language_is_string(x))
        return language_box_long(language_string_len(x));
    if (language_is_symbol(x))
        return language_box_long(strlen(language_symbol_name((language_sym_t*)x)));
    if (language_is_svec(x))
        return language_box_long((1+language_svec_len(x))*sizeof(void*));
    language_datatype_t *dt = (language_datatype_t*)language_typeof(x);
    assert(language_is_datatype(dt));
    assert(!dt->name->abstract);
    size_t sz = dt->layout->size;
    if (language_is_genericmemory(x))
        sz = (sz + (dt->layout->flags.arrayelem_isunion ? 1 : 0)) * ((language_genericmemory_t*)x)->length;
    return language_box_long(sz);
}

LANGUAGE_CALLABLE(language_f_issubtype)
{
    LANGUAGE_NARGS(<:, 2, 2);
    language_value_t *a = args[0], *b = args[1];
    LANGUAGE_TYPECHK(<:, type, a);
    LANGUAGE_TYPECHK(<:, type, b);
    return (language_subtype(a,b) ? language_true : language_false);
}

LANGUAGE_CALLABLE(language_f_isa)
{
    LANGUAGE_NARGS(isa, 2, 2);
    LANGUAGE_TYPECHK(isa, type, args[1]);
    return (language_isa(args[0],args[1]) ? language_true : language_false);
}

LANGUAGE_CALLABLE(language_f_typeassert)
{
    LANGUAGE_NARGS(typeassert, 2, 2);
    LANGUAGE_TYPECHK(typeassert, type, args[1]);
    if (!language_isa(args[0],args[1]))
        language_type_error("typeassert", args[1], args[0]);
    return args[0];
}

LANGUAGE_CALLABLE(language_f_throw)
{
    LANGUAGE_NARGS(throw, 1, 1);
    language_throw(args[0]);
    return language_nothing;
}

LANGUAGE_CALLABLE(language_f_ifelse)
{
    LANGUAGE_NARGS(ifelse, 3, 3);
    LANGUAGE_TYPECHK(ifelse, bool, args[0]);
    return (args[0] == language_false ? args[2] : args[1]);
}

LANGUAGE_CALLABLE(language_f_current_scope)
{
    LANGUAGE_NARGS(current_scope, 0, 0);
    return language_current_task->scope;
}

// apply ----------------------------------------------------------------------

static NOINLINE language_svec_t *_copy_to(size_t newalloc, language_value_t **oldargs, size_t oldalloc)
{
    size_t j;
    language_svec_t *newheap = language_alloc_svec_uninit(newalloc);
    language_value_t **newargs = language_svec_data(newheap);
    for (j = 0; j < oldalloc; j++)
        newargs[j] = oldargs[j];
    for (; j < newalloc; j++)
        newargs[j] = NULL;
    return newheap;
}

STATIC_INLINE void _grow_to(language_value_t **root, language_value_t ***oldargs, language_svec_t **arg_heap, size_t *n_alloc, size_t newalloc, size_t extra)
{
    size_t oldalloc = *n_alloc;
    if (oldalloc >= newalloc)
        return;
    if (extra)
        // grow by an extra 50% if newalloc is still only a guess
        newalloc += oldalloc / 2 + 16;
    LANGUAGE_GC_PROMISE_ROOTED(*oldargs);
    language_svec_t *newheap = _copy_to(newalloc, *oldargs, oldalloc);
    *root = (language_value_t*)newheap;
    *arg_heap = newheap;
    *oldargs = language_svec_data(newheap);
    *n_alloc = newalloc;
}


static language_value_t *language_arrayref(language_array_t *a, size_t i)
{
    return language_memoryrefget(language_memoryrefindex(a->ref, i), 0);
}

static language_value_t *do_apply(language_value_t **args, uint32_t nargs, language_value_t *iterate)
{
    language_function_t *f = args[0];
    if (nargs == 2) {
        // some common simple cases
        if (f == language_builtin_svec) {
            if (language_is_svec(args[1]))
                return args[1];
            if (language_is_genericmemory(args[1])) {
                language_genericmemory_t *mem = (language_genericmemory_t*)args[1];
                size_t n = mem->length;
                language_svec_t *t = language_alloc_svec(n);
                LANGUAGE_GC_PUSH1(&t);
                for (size_t i = 0; i < n; i++) {
                    language_svecset(t, i, language_genericmemoryref(mem, i));
                }
                LANGUAGE_GC_POP();
                return (language_value_t*)t;
            }
            if (language_is_array(args[1])) {
                size_t n = language_array_len(args[1]);
                language_svec_t *t = language_alloc_svec(n);
                LANGUAGE_GC_PUSH1(&t);
                for (size_t i = 0; i < n; i++) {
                    language_svecset(t, i, language_arrayref((language_array_t*)args[1], i));
                }
                LANGUAGE_GC_POP();
                return (language_value_t*)t;
            }
        }
        else if (f == language_builtin_tuple && language_is_tuple(args[1])) {
            return args[1];
        }
    }
    // estimate how many real arguments we appear to have
    size_t precount = 1;
    size_t extra = 0;
    size_t i;
    for (i = 1; i < nargs; i++) {
        if (language_is_svec(args[i])) {
            precount += language_svec_len(args[i]);
        }
        else if (language_is_tuple(args[i]) || language_is_namedtuple(args[i])) {
            precount += language_nfields(args[i]);
        }
        else if (language_is_genericmemory(args[i])) {
            precount += ((language_genericmemory_t*)args[i])->length;
        }
        else if (language_is_array(args[i])) {
            precount += language_array_len(args[i]);
        }
        else {
            extra += 1;
        }
    }
    if (extra && iterate == NULL) {
        language_undefined_var_error(language_symbol("iterate"), NULL);
    }
    // allocate space for the argument array and gc roots for it
    // based on our previous estimates
    // use the stack if we have a good estimate that it is small
    // otherwise, use the heap and grow it incrementally
    // and if there are any extra elements, we'll also need a couple extra roots
    int onstack = (precount + 32 * extra < language_page_size / sizeof(language_value_t*));
    size_t stackalloc = onstack ? (precount + 4 * extra + (extra ? 16 : 0)) : 1;
    size_t n_alloc;
    language_value_t **roots;
    LANGUAGE_GC_PUSHARGS(roots, stackalloc + (extra ? 2 : 0));
    language_value_t **newargs;
    language_svec_t *arg_heap = NULL;
    if (onstack) {
        newargs = roots;
        n_alloc = stackalloc;
    }
    else {
        // put arguments on the heap if there are too many
        newargs = NULL;
        n_alloc = precount;
        if (extra)
            // grow by an extra 50% if newalloc is still only a guess
            n_alloc += n_alloc / 2 + 16;
        arg_heap = language_alloc_svec(n_alloc);
        roots[0] = (language_value_t*)arg_heap;
        newargs = language_svec_data(arg_heap);
    }
    newargs[0] = f;
    precount -= 1;
    size_t n = 1;
    for (i = 1; i < nargs; i++) {
        language_value_t *ai = args[i];
        if (language_is_svec(ai)) {
            language_svec_t *t = (language_svec_t*)ai;
            size_t j, al = language_svec_len(t);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            for (j = 0; j < al; j++) {
                newargs[n++] = language_svecref(t, j);
                // GC Note: here we assume that the return value of `language_svecref`
                //          will not be young if `arg_heap` becomes old
                //          since they are allocated before `arg_heap`. Otherwise,
                //          we need to add write barrier for !onstack
            }
        }
        else if (language_is_tuple(ai) || language_is_namedtuple(ai)) {
            size_t j, al = language_nfields(ai);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            for (j = 0; j < al; j++) {
                // language_fieldref may allocate.
                newargs[n++] = language_fieldref(ai, j);
                if (arg_heap)
                    language_gc_wb(arg_heap, newargs[n - 1]);
            }
        }
        else if (language_is_genericmemory(ai)) {
            language_genericmemory_t *mem = (language_genericmemory_t*)ai;
            size_t j, al = mem->length;
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(mem))->layout;
            if (layout->flags.arrayelem_isboxed) {
                for (j = 0; j < al; j++) {
                    language_value_t *arg = language_genericmemory_ptr_ref(mem, j);
                    // apply with array splatting may have embedded NULL value (#11772)
                    if (__unlikely(arg == NULL))
                        language_throw(language_undefref_exception);
                    newargs[n++] = arg;
                    if (arg_heap)
                        language_gc_wb(arg_heap, arg);
                }
            }
            else {
                for (j = 0; j < al; j++) {
                    newargs[n++] = language_genericmemoryref(mem, j);
                    if (arg_heap)
                        language_gc_wb(arg_heap, newargs[n - 1]);
                }
            }
        }
        else if (language_is_array(ai)) {
            language_array_t *aai = (language_array_t*)ai;
            size_t j, al = language_array_len(aai);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(aai->ref.mem))->layout;
            if (layout->flags.arrayelem_isboxed) {
                for (j = 0; j < al; j++) {
                    language_value_t *arg = language_array_ptr_ref(aai, j);
                    // apply with array splatting may have embedded NULL value (#11772)
                    if (__unlikely(arg == NULL))
                        language_throw(language_undefref_exception);
                    newargs[n++] = arg;
                    if (arg_heap)
                        language_gc_wb(arg_heap, arg);
                }
            }
            else {
                for (j = 0; j < al; j++) {
                    newargs[n++] = language_arrayref(aai, j);
                    if (arg_heap)
                        language_gc_wb(arg_heap, newargs[n - 1]);
                }
            }
        }
        else {
            assert(extra > 0);
            language_value_t *args[2];
            args[0] = ai;
            language_value_t *next = language_apply_generic(iterate, args, 1);
            while (next != language_nothing) {
                roots[stackalloc] = next;
                language_value_t *value = language_get_nth_field_checked(next, 0);
                roots[stackalloc + 1] = value;
                language_value_t *state = language_get_nth_field_checked(next, 1);
                roots[stackalloc] = state;
                _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + 1, extra);
                LANGUAGE_GC_ASSERT_LIVE(value);
                newargs[n++] = value;
                if (arg_heap)
                    language_gc_wb(arg_heap, value);
                roots[stackalloc + 1] = NULL;
                LANGUAGE_GC_ASSERT_LIVE(state);
                args[1] = state;
                next = language_apply_generic(iterate, args, 2);
            }
            roots[stackalloc] = NULL;
            extra -= 1;
        }
    }
    if (arg_heap) {
        // optimization: keep only the first root, free the others
#ifndef __clang_gcanalyzer__
        ((void**)roots)[-2] = (void*)LANGUAGE_GC_ENLANGUAGE_PUSHARGS(1);
#endif
    }
    language_value_t *result = language_apply(newargs, n);
    LANGUAGE_GC_POP();
    return result;
}

LANGUAGE_CALLABLE(language_f__apply_iterate)
{
    LANGUAGE_NARGSV(_apply_iterate, 2);
    return do_apply(args + 1, nargs - 1, args[0]);
}

// this is like `_apply`, but with quasi-exact checks to make sure it is pure
LANGUAGE_CALLABLE(language_f__apply_pure)
{
    language_task_t *ct = language_current_task;
    int last_in = ct->ptls->in_pure_callback;
    language_value_t *ret = NULL;
    LANGUAGE_TRY {
        ct->ptls->in_pure_callback = 1;
        // because this function was declared pure,
        // we should be allowed to run it in any world
        // so we run it in the newest world;
        // because, why not :)
        // and `promote` works better this way
        size_t last_age = ct->world_age;
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        ret = do_apply(args, nargs, NULL);
        ct->world_age = last_age;
        ct->ptls->in_pure_callback = last_in;
    }
    LANGUAGE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        language_rethrow();
    }
    return ret;
}

// this is like a regular call, but always runs in the newest world
LANGUAGE_CALLABLE(language_f__call_latest)
{
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    if (!ct->ptls->in_pure_callback)
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
    language_value_t *ret = language_apply(args, nargs);
    ct->world_age = last_age;
    return ret;
}

// Like call_in_world, but runs in the specified world.
// If world > language_atomic_load_acquire(&language_world_counter), run in the latest world.
LANGUAGE_CALLABLE(language_f__call_in_world)
{
    LANGUAGE_NARGSV(_apply_in_world, 2);
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    LANGUAGE_TYPECHK(_apply_in_world, ulong, args[0]);
    size_t world = language_unbox_ulong(args[0]);
    if (!ct->ptls->in_pure_callback) {
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        if (ct->world_age > world)
            ct->world_age = world;
    }
    language_value_t *ret = language_apply(&args[1], nargs - 1);
    ct->world_age = last_age;
    return ret;
}

LANGUAGE_CALLABLE(language_f__call_in_world_total)
{
    LANGUAGE_NARGSV(_call_in_world_total, 2);
    LANGUAGE_TYPECHK(_apply_in_world, ulong, args[0]);
    language_task_t *ct = language_current_task;
    int last_in = ct->ptls->in_pure_callback;
    language_value_t *ret = NULL;
    size_t last_age = ct->world_age;
    LANGUAGE_TRY {
        ct->ptls->in_pure_callback = 1;
        size_t world = language_unbox_ulong(args[0]);
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        if (ct->world_age > world)
            ct->world_age = world;
        ret = language_apply(&args[1], nargs - 1);
        ct->world_age = last_age;
        ct->ptls->in_pure_callback = last_in;
    }
    LANGUAGE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        language_rethrow();
    }
    return ret;
}

// tuples ---------------------------------------------------------------------

LANGUAGE_CALLABLE(language_f_tuple)
{
    size_t i;
    if (nargs == 0)
        return (language_value_t*)language_emptytuple;
    language_datatype_t *tt = language_inst_arg_tuple_type(args[0], &args[1], nargs, 0);
    LANGUAGE_GC_PROMISE_ROOTED(tt); // it is a concrete type
    if (tt->instance != NULL)
        return tt->instance;
    language_task_t *ct = language_current_task;
    language_value_t *jv = language_gc_alloc(ct->ptls, language_datatype_size(tt), tt);
    for (i = 0; i < nargs; i++)
        set_nth_field(tt, jv, i, args[i], 0);
    return jv;
}

LANGUAGE_CALLABLE(language_f_svec)
{
    size_t i;
    if (nargs == 0)
        return (language_value_t*)language_emptysvec;
    language_svec_t *t = language_alloc_svec_uninit(nargs);
    for (i = 0; i < nargs; i++) {
        language_svecset(t, i, args[i]);
    }
    return (language_value_t*)t;
}

// struct operations ------------------------------------------------------------

enum language_memory_order language_get_atomic_order(language_sym_t *order, char loading, char storing)
{
    if (order == language_not_atomic_sym)
        return language_memory_order_notatomic;
    if (order == language_unordered_sym && (loading ^ storing))
        return language_memory_order_unordered;
    if (order == language_monotonic_sym && (loading || storing))
        return language_memory_order_monotonic;
    if (order == language_acquire_sym && loading)
        return language_memory_order_acquire;
    if (order == language_release_sym && storing)
        return language_memory_order_release;
    if (order == language_acquire_release_sym && loading && storing)
        return language_memory_order_acq_rel;
    if (order == language_sequentially_consistent_sym)
        return language_memory_order_seq_cst;
    return language_memory_order_invalid;
}

enum language_memory_order language_get_atomic_order_checked(language_sym_t *order, char loading, char storing)
{
    enum language_memory_order mo = language_get_atomic_order(order, loading, storing);
    if (mo < 0) // invalid
        language_atomic_error("invalid atomic ordering");
    return mo;
}

static inline size_t get_checked_fieldindex(const char *name, language_datatype_t *st, language_value_t *v, language_value_t *arg, int mutabl)
{
    if (mutabl) {
        if (st == language_module_type)
            language_error("cannot assign variables in other modules");
        if (!st->name->mutabl)
            language_errorf("%s: immutable struct of type %s cannot be changed", name, language_symbol_name(st->name->name));
    }
    size_t idx;
    if (language_is_long(arg)) {
        idx = language_unbox_long(arg) - 1;
        if (idx >= language_datatype_nfields(st))
            language_bounds_error(v, arg);
    }
    else if (language_is_symbol(arg)) {
        idx = language_field_index(st, (language_sym_t*)arg, 1);
    }
    else {
        language_value_t *ts[2] = {(language_value_t*)language_long_type, (language_value_t*)language_symbol_type};
        language_value_t *t = language_type_union(ts, 2);
        language_type_error("getfield", t, arg);
    }
    if (mutabl && language_field_isconst(st, idx)) {
        language_errorf("%s: const field .%s of type %s cannot be changed", name,
                language_symbol_name((language_sym_t*)language_svecref(language_field_names(st), idx)), language_symbol_name(st->name->name));
    }
    return idx;
}

LANGUAGE_CALLABLE(language_f_getfield)
{
    enum language_memory_order order = language_memory_order_unspecified;
    LANGUAGE_NARGS(getfield, 2, 4);
    if (nargs == 4) {
        LANGUAGE_TYPECHK(getfield, symbol, args[2]);
        LANGUAGE_TYPECHK(getfield, bool, args[3]);
        order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 0);
    }
    else if (nargs == 3) {
        if (!language_is_bool(args[2])) {
            LANGUAGE_TYPECHK(getfield, symbol, args[2]);
            order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 0);
        }
    }
    language_value_t *v = args[0];
    language_value_t *vt = language_typeof(v);
    if (vt == (language_value_t*)language_module_type)
        return language_f_getglobal(NULL, args, 2); // we just ignore the atomic order and boundschecks
    language_datatype_t *st = (language_datatype_t*)vt;
    size_t idx = get_checked_fieldindex("getfield", st, v, args[1], 0);
    int isatomic = language_field_isatomic(st, idx);
    if (!isatomic && order != language_memory_order_notatomic && order != language_memory_order_unspecified)
        language_atomic_error("getfield: non-atomic field cannot be accessed atomically");
    if (isatomic && order == language_memory_order_notatomic)
        language_atomic_error("getfield: atomic field cannot be accessed non-atomically");
    if (order >= language_memory_order_seq_cst)
        language_fence();
    v = language_get_nth_field_checked(v, idx); // `v` already had at least consume ordering
    if (order >= language_memory_order_acquire)
        language_fence();
    return v;
}

LANGUAGE_CALLABLE(language_f_setfield)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(setfield!, 3, 4);
    if (nargs == 4) {
        LANGUAGE_TYPECHK(setfield!, symbol, args[3]);
        order = language_get_atomic_order_checked((language_sym_t*)args[3], 0, 1);
    }
    language_value_t *v = args[0];
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t idx = get_checked_fieldindex("setfield!", st, v, args[1], 1);
    int isatomic = !!language_field_isatomic(st, idx);
    if (isatomic == (order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "setfield!: atomic field cannot be written non-atomically"
                                 : "setfield!: non-atomic field cannot be written atomically");
    language_value_t *ft = language_field_type_concrete(st, idx);
    if (!language_isa(args[2], ft))
        language_type_error("setfield!", ft, args[2]);
    if (order >= language_memory_order_release)
        language_fence(); // `st->[idx]` will have at least relaxed ordering
    set_nth_field(st, v, idx, args[2], isatomic);
    return args[2];
}

LANGUAGE_CALLABLE(language_f_swapfield)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(swapfield!, 3, 4);
    if (nargs == 4) {
        LANGUAGE_TYPECHK(swapfield!, symbol, args[3]);
        order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
    }
    language_value_t *v = args[0];
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t idx = get_checked_fieldindex("swapfield!", st, v, args[1], 1);
    int isatomic = !!language_field_isatomic(st, idx);
    if (isatomic == (order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "swapfield!: atomic field cannot be written non-atomically"
                                 : "swapfield!: non-atomic field cannot be written atomically");
    v = swap_nth_field(st, v, idx, args[2], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

LANGUAGE_CALLABLE(language_f_modifyfield)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(modifyfield!, 4, 5);
    if (nargs == 5) {
        LANGUAGE_TYPECHK(modifyfield!, symbol, args[4]);
        order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 1);
    }
    language_value_t *v = args[0];
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t idx = get_checked_fieldindex("modifyfield!", st, v, args[1], 1);
    int isatomic = !!language_field_isatomic(st, idx);
    if (isatomic == (order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "modifyfield!: atomic field cannot be written non-atomically"
                                 : "modifyfield!: non-atomic field cannot be written atomically");
    v = modify_nth_field(st, v, idx, args[2], args[3], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

LANGUAGE_CALLABLE(language_f_replacefield)
{
    enum language_memory_order success_order = language_memory_order_notatomic;
    LANGUAGE_NARGS(replacefield!, 4, 6);
    if (nargs >= 5) {
        LANGUAGE_TYPECHK(replacefield!, symbol, args[4]);
        success_order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 1);
    }
    enum language_memory_order failure_order = success_order;
    if (nargs == 6) {
        LANGUAGE_TYPECHK(replacefield!, symbol, args[5]);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[5], 1, 0);
    }
    if (failure_order > success_order)
        language_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    language_value_t *v = args[0];
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t idx = get_checked_fieldindex("replacefield!", st, v, args[1], 1);
    int isatomic = !!language_field_isatomic(st, idx);
    if (isatomic == (success_order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "replacefield!: atomic field cannot be written non-atomically"
                                 : "replacefield!: non-atomic field cannot be written atomically");
    if (isatomic == (failure_order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "replacefield!: atomic field cannot be accessed non-atomically"
                                 : "replacefield!: non-atomic field cannot be accessed atomically");
    v = replace_nth_field(st, v, idx, args[2], args[3], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

LANGUAGE_CALLABLE(language_f_setfieldonce)
{
    enum language_memory_order success_order = language_memory_order_notatomic;
    LANGUAGE_NARGS(setfieldonce!, 3, 5);
    if (nargs >= 4) {
        LANGUAGE_TYPECHK(setfieldonce!, symbol, args[3]);
        success_order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
    }
    enum language_memory_order failure_order = success_order;
    if (nargs == 5) {
        LANGUAGE_TYPECHK(setfieldonce!, symbol, args[4]);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 0);
    }
    if (failure_order > success_order)
        language_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    language_value_t *v = args[0];
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    size_t idx = get_checked_fieldindex("setfieldonce!", st, v, args[1], 1);
    int isatomic = !!language_field_isatomic(st, idx);
    if (isatomic == (success_order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "setfieldonce!: atomic field cannot be written non-atomically"
                                 : "setfieldonce!: non-atomic field cannot be written atomically");
    if (isatomic == (failure_order == language_memory_order_notatomic))
        language_atomic_error(isatomic ? "setfieldonce!: atomic field cannot be accessed non-atomically"
                                 : "setfieldonce!: non-atomic field cannot be accessed atomically");
    int success = set_nth_fieldonce(st, v, idx, args[2], isatomic); // always seq_cst, if isatomic needed at all
    return success ? language_true : language_false;
}

static language_value_t *get_fieldtype(language_value_t *t, language_value_t *f, int dothrow)
{
    if (language_is_unionall(t)) {
        language_value_t *u = t;
        LANGUAGE_GC_PUSH1(&u);
        u = get_fieldtype(((language_unionall_t*)t)->body, f, dothrow);
        u = language_type_unionall(((language_unionall_t*)t)->var, u);
        LANGUAGE_GC_POP();
        return u;
    }
    if (language_is_uniontype(t)) {
        language_value_t **u;
        language_value_t *r;
        LANGUAGE_GC_PUSHARGS(u, 2);
        u[0] = get_fieldtype(((language_uniontype_t*)t)->a, f, 0);
        u[1] = get_fieldtype(((language_uniontype_t*)t)->b, f, 0);
        if (u[0] == language_bottom_type && u[1] == language_bottom_type && dothrow) {
            // error if all types in the union might have
            get_fieldtype(((language_uniontype_t*)t)->a, f, 1);
            get_fieldtype(((language_uniontype_t*)t)->b, f, 1);
        }
        r = language_type_union(u, 2);
        LANGUAGE_GC_POP();
        return r;
    }
    if (!language_is_datatype(t))
        language_type_error("fieldtype", (language_value_t*)language_datatype_type, t);
    language_datatype_t *st = (language_datatype_t*)t;
    int field_index;
    if (language_is_long(f)) {
        field_index = language_unbox_long(f) - 1;
    }
    else {
        LANGUAGE_TYPECHK(fieldtype, symbol, f);
        field_index = language_field_index(st, (language_sym_t*)f, dothrow);
        if (field_index == -1)
            return language_bottom_type;
    }
    if (st->name == language_namedtuple_typename) {
        language_value_t *nm = language_tparam0(st);
        if (language_is_tuple(nm)) {
            int nf = language_nfields(nm);
            if (field_index < 0 || field_index >= nf) {
                if (dothrow)
                    language_bounds_error(t, f);
                else
                    return language_bottom_type;
            }
        }
        language_value_t *tt = language_tparam1(st);
        while (language_is_typevar(tt))
            tt = ((language_tvar_t*)tt)->ub;
        if (tt == (language_value_t*)language_any_type)
            return (language_value_t*)language_any_type;
        if (tt == (language_value_t*)language_bottom_type)
            return (language_value_t*)language_bottom_type;
        LANGUAGE_GC_PUSH1(&f);
        if (language_is_symbol(f))
            f = language_box_long(field_index+1);
        language_value_t *ft = get_fieldtype(tt, f, dothrow);
        LANGUAGE_GC_POP();
        return ft;
    }
    language_svec_t *types = language_get_fieldtypes(st);
    int nf = language_svec_len(types);
    if (nf > 0 && field_index >= nf-1 && st->name == language_tuple_typename) {
        language_value_t *ft = language_field_type(st, nf-1);
        if (language_is_vararg(ft))
            return language_unwrap_vararg(ft);
    }
    if (field_index < 0 || field_index >= nf) {
        if (dothrow)
            language_bounds_error(t, f);
        else
            return language_bottom_type;
    }
    return language_field_type(st, field_index);
}

LANGUAGE_CALLABLE(language_f_fieldtype)
{
    LANGUAGE_NARGS(fieldtype, 2, 3);
    if (nargs == 3) {
        LANGUAGE_TYPECHK(fieldtype, bool, args[2]);
    }
    return get_fieldtype(args[0], args[1], 1);
}

LANGUAGE_CALLABLE(language_f_nfields)
{
    LANGUAGE_NARGS(nfields, 1, 1);
    language_datatype_t *xt = (language_datatype_t*)language_typeof(args[0]);
    return language_box_long(language_datatype_nfields(xt));
}

LANGUAGE_CALLABLE(language_f_isdefined)
{
    language_module_t *m = NULL;
    language_sym_t *s = NULL;
    LANGUAGE_NARGS(isdefined, 2, 3);
    enum language_memory_order order = language_memory_order_unspecified;
    if (nargs == 3) {
        LANGUAGE_TYPECHK(isdefined, symbol, args[2]);
        order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 0);
    }
    if (language_is_module(args[0])) {
        LANGUAGE_TYPECHK(isdefined, symbol, args[1]);
        m = (language_module_t*)args[0];
        s = (language_sym_t*)args[1];
        if (order == language_memory_order_unspecified)
            order = language_memory_order_unordered;
        if (order < language_memory_order_unordered)
            language_atomic_error("isdefined: module binding cannot be accessed non-atomically");
        int bound = language_boundp(m, s); // seq_cst always
        return bound ? language_true : language_false;
    }
    language_datatype_t *vt = (language_datatype_t*)language_typeof(args[0]);
    assert(language_is_datatype(vt));
    size_t idx;
    if (language_is_long(args[1])) {
        idx = language_unbox_long(args[1]) - 1;
        if (idx >= language_datatype_nfields(vt)) {
            if (order != language_memory_order_unspecified)
                language_atomic_error("isdefined: atomic ordering cannot be specified for nonexistent field");
            return language_false;
        }
    }
    else {
        LANGUAGE_TYPECHK(isdefined, symbol, args[1]);
        idx = language_field_index(vt, (language_sym_t*)args[1], 0);
        if ((int)idx == -1) {
            if (order != language_memory_order_unspecified)
                language_atomic_error("isdefined: atomic ordering cannot be specified for nonexistent field");
            return language_false;
        }
    }
    int isatomic = language_field_isatomic(vt, idx);
    if (!isatomic && order != language_memory_order_notatomic && order != language_memory_order_unspecified)
        language_atomic_error("isdefined: non-atomic field cannot be accessed atomically");
    if (isatomic && order == language_memory_order_notatomic)
        language_atomic_error("isdefined: atomic field cannot be accessed non-atomically");
    if (order >= language_memory_order_seq_cst)
        language_fence();
    int v = language_field_isdefined(args[0], idx); // relaxed ordering
    if (order >= language_memory_order_acquire)
        language_fence();
    return v ? language_true : language_false;
}


// module bindings

LANGUAGE_CALLABLE(language_f_getglobal)
{
    enum language_memory_order order = language_memory_order_monotonic;
    LANGUAGE_NARGS(getglobal, 2, 3);
    if (nargs == 3) {
        LANGUAGE_TYPECHK(getglobal, symbol, args[2]);
        order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 0);
    }
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *sym = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(getglobal, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(getglobal, symbol, (language_value_t*)sym);
    if (order == language_memory_order_notatomic)
        language_atomic_error("getglobal: module binding cannot be read non-atomically");
    else if (order >= language_memory_order_seq_cst)
        language_fence();
    language_value_t *v = language_eval_global_var(mod, sym); // relaxed load
    if (order >= language_memory_order_acquire)
        language_fence();
    return v;
}

LANGUAGE_CALLABLE(language_f_setglobal)
{
    enum language_memory_order order = language_memory_order_release;
    LANGUAGE_NARGS(setglobal!, 3, 4);
    if (nargs == 4) {
        LANGUAGE_TYPECHK(setglobal!, symbol, args[3]);
        order = language_get_atomic_order_checked((language_sym_t*)args[3], 0, 1);
    }
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(setglobal!, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(setglobal!, symbol, (language_value_t*)var);
    if (order == language_memory_order_notatomic)
        language_atomic_error("setglobal!: module binding cannot be written non-atomically");
    else if (order >= language_memory_order_seq_cst)
        language_fence();
    language_binding_t *b = language_get_binding_wr(mod, var, 0);
    language_checked_assignment(b, mod, var, args[2]); // release store
    if (order >= language_memory_order_seq_cst)
        language_fence();
    return args[2];
}

LANGUAGE_CALLABLE(language_f_get_binding_type)
{
    LANGUAGE_NARGS(get_binding_type, 2, 2);
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(get_binding_type, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(get_binding_type, symbol, (language_value_t*)var);
    language_value_t *ty = language_get_binding_type(mod, var);
    if (ty == (language_value_t*)language_nothing) {
        language_binding_t *b = language_get_module_binding(mod, var, 0);
        if (b == NULL)
            return (language_value_t*)language_any_type;
        language_binding_t *b2 = language_atomic_load_relaxed(&b->owner);
        if (b2 != b)
            return (language_value_t*)language_any_type;
        language_value_t *old_ty = NULL;
        language_atomic_cmpswap_relaxed(&b->ty, &old_ty, (language_value_t*)language_any_type);
        return language_atomic_load_relaxed(&b->ty);
    }
    return ty;
}

LANGUAGE_CALLABLE(language_f_swapglobal)
{
    enum language_memory_order order = language_memory_order_release;
    LANGUAGE_NARGS(swapglobal!, 3, 4);
    if (nargs == 4) {
        LANGUAGE_TYPECHK(swapglobal!, symbol, args[3]);
        order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
    }
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(swapglobal!, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(swapglobal!, symbol, (language_value_t*)var);
    if (order == language_memory_order_notatomic)
        language_atomic_error("swapglobal!: module binding cannot be written non-atomically");
    // is seq_cst already, no fence needed
    language_binding_t *b = language_get_binding_wr(mod, var, 0);
    return language_checked_swap(b, mod, var, args[2]);
}

LANGUAGE_CALLABLE(language_f_modifyglobal)
{
    enum language_memory_order order = language_memory_order_release;
    LANGUAGE_NARGS(modifyglobal!, 4, 5);
    if (nargs == 5) {
        LANGUAGE_TYPECHK(modifyglobal!, symbol, args[4]);
        order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 1);
    }
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(modifyglobal!, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(modifyglobal!, symbol, (language_value_t*)var);
    if (order == language_memory_order_notatomic)
        language_atomic_error("modifyglobal!: module binding cannot be written non-atomically");
    language_binding_t *b = language_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    return language_checked_modify(b, mod, var, args[2], args[3]);
}

LANGUAGE_CALLABLE(language_f_replaceglobal)
{
    enum language_memory_order success_order = language_memory_order_release;
    LANGUAGE_NARGS(replaceglobal!, 4, 6);
    if (nargs >= 5) {
        LANGUAGE_TYPECHK(replaceglobal!, symbol, args[4]);
        success_order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 1);
    }
    enum language_memory_order failure_order = success_order;
    if (nargs == 6) {
        LANGUAGE_TYPECHK(replaceglobal!, symbol, args[5]);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[5], 1, 0);
    }
    if (failure_order > success_order)
        language_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(replaceglobal!, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(replaceglobal!, symbol, (language_value_t*)var);
    if (success_order == language_memory_order_notatomic)
        language_atomic_error("replaceglobal!: module binding cannot be written non-atomically");
    if (failure_order == language_memory_order_notatomic)
        language_atomic_error("replaceglobal!: module binding cannot be accessed non-atomically");
    language_binding_t *b = language_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    return language_checked_replace(b, mod, var, args[2], args[3]);
}

LANGUAGE_CALLABLE(language_f_setglobalonce)
{
    enum language_memory_order success_order = language_memory_order_release;
    LANGUAGE_NARGS(setglobalonce!, 3, 5);
    if (nargs >= 4) {
        LANGUAGE_TYPECHK(setglobalonce!, symbol, args[3]);
        success_order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
    }
    enum language_memory_order failure_order = success_order;
    if (nargs == 5) {
        LANGUAGE_TYPECHK(setglobalonce!, symbol, args[4]);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 0);
    }
    if (failure_order > success_order)
        language_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    language_module_t *mod = (language_module_t*)args[0];
    language_sym_t *var = (language_sym_t*)args[1];
    LANGUAGE_TYPECHK(setglobalonce!, module, (language_value_t*)mod);
    LANGUAGE_TYPECHK(setglobalonce!, symbol, (language_value_t*)var);
    if (success_order == language_memory_order_notatomic)
        language_atomic_error("setglobalonce!: module binding cannot be written non-atomically");
    if (failure_order == language_memory_order_notatomic)
        language_atomic_error("setglobalonce!: module binding cannot be accessed non-atomically");
    language_binding_t *b = language_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    language_value_t *old = language_checked_assignonce(b, mod, var, args[2]);
    return old == NULL ? language_true : language_false;
}



// apply_type -----------------------------------------------------------------

static int is_nestable_type_param(language_value_t *t)
{
    if (language_is_namedtuple_type(t))
        t = language_tparam1(t);
    if (language_is_tuple_type(t)) {
        // NOTE: tuples of symbols are not currently bits types, but have been
        // allowed as type parameters. this is a bit ugly.
        size_t i, l = language_nparams(t);
        for (i = 0; i < l; i++) {
            language_value_t *pi = language_tparam(t, i);
            if (!(pi == (language_value_t*)language_symbol_type || language_isbits(pi) || is_nestable_type_param(pi) ||
        language_is_module(pi)))
                return 0;
        }
        return 1;
    }
    return 0;
}

int language_valid_type_param(language_value_t *v)
{
    if (language_is_tuple(v) || language_is_namedtuple(v))
        return is_nestable_type_param(language_typeof(v));
    if (language_is_vararg(v))
        return 0;
    // TODO: maybe more things
    return language_is_type(v) || language_is_typevar(v) || language_is_symbol(v) || language_isbits(language_typeof(v)) ||
        language_is_module(v);
}

LANGUAGE_CALLABLE(language_f_apply_type)
{
    LANGUAGE_NARGSV(apply_type, 1);
    int i;
    if (args[0] == (language_value_t*)language_anytuple_type) {
        for(i=1; i < nargs; i++) {
            language_value_t *pi = args[i];
            // TODO: should possibly only allow Types and TypeVars, but see
            // https://github.com/LanguageLang/code/commit/85f45974a581ab9af955bac600b90d9ab00f093b#commitcomment-13041922
            if (language_is_vararg(pi)) {
                if (i != nargs-1)
                    language_type_error_rt("Tuple", "non-final parameter", (language_value_t*)language_type_type, pi);
            }
            else if (!language_valid_type_param(pi)) {
                language_type_error_rt("Tuple", "parameter", (language_value_t*)language_type_type, pi);
            }
        }
        return language_apply_tuple_type_v(&args[1], nargs-1);
    }
    else if (args[0] == (language_value_t*)language_uniontype_type) {
        // Union{} has extra restrictions, so it needs to be checked after
        // substituting typevars (a valid_type_param check here isn't sufficient).
        return (language_value_t*)language_type_union(&args[1], nargs-1);
    }
    else if (language_is_vararg(args[0])) {
        language_vararg_t *vm = (language_vararg_t*)args[0];
        if (!vm->T) {
            LANGUAGE_NARGS(apply_type, 2, 3);
            return (language_value_t*)language_wrap_vararg(args[1], nargs == 3 ? args[2] : NULL, 1, 0);
        }
        else if (!vm->N) {
            LANGUAGE_NARGS(apply_type, 2, 2);
            return (language_value_t*)language_wrap_vararg(vm->T, args[1], 1, 0);
        }
    }
    else if (language_is_unionall(args[0])) {
        for(i=1; i < nargs; i++) {
            language_value_t *pi = args[i];
            if (!language_valid_type_param(pi)) {
                language_type_error_rt("Type", "parameter",
                                 language_isa(pi, (language_value_t*)language_number_type) ?
                                 (language_value_t*)language_long_type : (language_value_t*)language_type_type,
                                 pi);
            }
        }
        return language_apply_type(args[0], &args[1], nargs-1);
    }
    language_type_error("Type{...} expression", (language_value_t*)language_unionall_type, args[0]);
}

// generic function reflection ------------------------------------------------

LANGUAGE_CALLABLE(language_f_applicable)
{
    LANGUAGE_NARGSV(applicable, 1);
    size_t world = language_current_task->world_age;
    return language_method_lookup(args, nargs, world) != NULL ? language_true : language_false;
}

LANGUAGE_CALLABLE(language_f_invoke)
{
    LANGUAGE_NARGSV(invoke, 2);
    language_value_t *argtypes = args[1];
    LANGUAGE_GC_PUSH1(&argtypes);
    if (!language_is_tuple_type(language_unwrap_unionall(args[1])))
        language_type_error("invoke", (language_value_t*)language_anytuple_type_type, args[1]);
    if (!language_tuple_isa(&args[2], nargs - 2, (language_datatype_t*)argtypes))
        language_type_error("invoke: argument type error", argtypes, language_f_tuple(NULL, &args[2], nargs - 2));
    language_value_t *res = language_gf_invoke(argtypes, args[0], &args[2], nargs - 1);
    LANGUAGE_GC_POP();
    return res;
}

// Expr constructor for internal use ------------------------------------------

language_expr_t *language_exprn(language_sym_t *head, size_t n)
{
    language_task_t *ct = language_current_task;
    language_array_t *ar = language_alloc_vec_any(n);
    LANGUAGE_GC_PUSH1(&ar);
    language_expr_t *ex = (language_expr_t*)language_gc_alloc(ct->ptls, sizeof(language_expr_t),
                                            language_expr_type);
    ex->head = head;
    ex->args = ar;
    LANGUAGE_GC_POP();
    return ex;
}

LANGUAGE_CALLABLE(language_f__expr)
{
    language_task_t *ct = language_current_task;
    LANGUAGE_NARGSV(Expr, 1);
    LANGUAGE_TYPECHK(Expr, symbol, args[0]);
    language_array_t *ar = language_alloc_vec_any(nargs-1);
    LANGUAGE_GC_PUSH1(&ar);
    for(size_t i=0; i < nargs-1; i++)
        language_array_ptr_set(ar, i, args[i+1]);
    language_expr_t *ex = (language_expr_t*)language_gc_alloc(ct->ptls, sizeof(language_expr_t),
                                            language_expr_type);
    ex->head = (language_sym_t*)args[0];
    ex->args = ar;
    LANGUAGE_GC_POP();
    return (language_value_t*)ex;
}

// Typevar constructor for internal use
LANGUAGE_DLLEXPORT language_tvar_t *language_new_typevar(language_sym_t *name, language_value_t *lb, language_value_t *ub)
{
    if (lb != language_bottom_type && !language_is_type(lb) && !language_is_typevar(lb))
        language_type_error_rt("TypeVar", "lower bound", (language_value_t *)language_type_type, lb);
    if (ub != (language_value_t *)language_any_type && !language_is_type(ub) && !language_is_typevar(ub))
        language_type_error_rt("TypeVar", "upper bound", (language_value_t *)language_type_type, ub);
    language_task_t *ct = language_current_task;
    language_tvar_t *tv = (language_tvar_t *)language_gc_alloc(ct->ptls, sizeof(language_tvar_t), language_tvar_type);
    language_set_typetagof(tv, language_tvar_tag, 0);
    tv->name = name;
    tv->lb = lb;
    tv->ub = ub;
    return tv;
}

LANGUAGE_CALLABLE(language_f__typevar)
{
    LANGUAGE_NARGS(TypeVar, 3, 3);
    LANGUAGE_TYPECHK(TypeVar, symbol, args[0]);
    return (language_value_t *)language_new_typevar((language_sym_t*)args[0], args[1], args[2]);
}

// genericmemory ---------------------------------------------------------------------

LANGUAGE_CALLABLE(language_f_memoryref)
{
    LANGUAGE_NARGS(memoryref, 1, 3);
    if (nargs == 1) {
        LANGUAGE_TYPECHK(memoryref, genericmemory, args[0]);
        language_genericmemory_t *m = (language_genericmemory_t*)args[0];
        language_value_t *typ = language_apply_type((language_value_t*)language_genericmemoryref_type, language_svec_data(((language_datatype_t*)language_typetagof(m))->parameters), 3);
        LANGUAGE_GC_PROMISE_ROOTED(typ); // it is a concrete type
        const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m))->layout;
        if (layout->flags.arrayelem_isunion || layout->size == 0)
            return (language_value_t*)language_new_memoryref(typ, m, 0);
        return (language_value_t*)language_new_memoryref(typ, m, m->ptr);
    }
    else {
        LANGUAGE_TYPECHK(memoryref, genericmemoryref, args[0]);
        LANGUAGE_TYPECHK(memoryref, long, args[1]);
        if (nargs == 3)
            LANGUAGE_TYPECHK(memoryref, bool, args[2]);
        language_genericmemoryref_t *m = (language_genericmemoryref_t*)args[0];
        size_t i = language_unbox_long(args[1]) - 1;
        const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m->mem))->layout;
        char *data = (char*)m->ptr_or_offset;
        if (layout->flags.arrayelem_isboxed) {
            if (((data - (char*)m->mem->ptr) / sizeof(language_value_t*)) + i >= m->mem->length)
                language_bounds_error((language_value_t*)m, args[1]);
            data += sizeof(language_value_t*) * i;
        }
        else if (layout->flags.arrayelem_isunion || layout->size == 0) {
            if ((size_t)data + i >= m->mem->length)
                language_bounds_error((language_value_t*)m, args[1]);
            data += i;
        }
        else {
            if (((data - (char*)m->mem->ptr) / layout->size) + i >= m->mem->length)
                language_bounds_error((language_value_t*)m, args[1]);
            data += layout->size * i;
        }
        return (language_value_t*)language_new_memoryref((language_value_t*)language_typetagof(m), m->mem, data);
    }
}

LANGUAGE_CALLABLE(language_f_memoryrefoffset)
{
    LANGUAGE_NARGS(memoryrefoffset, 1, 1);
    LANGUAGE_TYPECHK(memoryref, genericmemoryref, args[0]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(m.mem))->layout;
    size_t offset;
    if (layout->flags.arrayelem_isboxed) {
        offset = (((char*)m.ptr_or_offset - (char*)m.mem->ptr) / sizeof(language_value_t*));
    }
    else if (layout->flags.arrayelem_isunion || layout->size == 0) {
        offset = (size_t)m.ptr_or_offset;
    }
    else {
        offset = ((char*)m.ptr_or_offset - (char*)m.mem->ptr) / layout->size;
    }
    return (language_value_t*)language_box_long(offset + 1);
}

LANGUAGE_CALLABLE(language_f_memoryrefget)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefget, 3, 3);
    LANGUAGE_TYPECHK(memoryrefget, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefget, symbol, args[1]);
    LANGUAGE_TYPECHK(memoryrefget, bool, args[2]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[1] != kind) {
            order = language_get_atomic_order_checked((language_sym_t*)args[1], 1, 0);
            language_atomic_error("memoryrefget: non-atomic memory cannot be accessed atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        order = language_get_atomic_order_checked((language_sym_t*)args[1], 1, 0);
        if (order == language_memory_order_notatomic)
            language_atomic_error("memoryrefget: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    return language_memoryrefget(m, kind == (language_value_t*)language_atomic_sym);
}

LANGUAGE_CALLABLE(language_f_memoryrefset)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefset!, 4, 4);
    LANGUAGE_TYPECHK(memoryrefset!, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefset!, symbol, args[2]);
    LANGUAGE_TYPECHK(memoryrefset!, bool, args[3]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[2] != kind) {
            order = language_get_atomic_order_checked((language_sym_t*)args[2], 0, 1);
            language_atomic_error("memoryrefset!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        order = language_get_atomic_order_checked((language_sym_t*)args[2], 0, 1);
        if (order == language_memory_order_notatomic)
            language_atomic_error("memoryrefset!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    language_memoryrefset(m, args[1], kind == (language_value_t*)language_atomic_sym);
    return args[1];
}

LANGUAGE_CALLABLE(language_f_memoryref_isassigned)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryref_isassigned, 3, 3);
    LANGUAGE_TYPECHK(memoryref_isassigned, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryref_isassigned, symbol, args[1]);
    LANGUAGE_TYPECHK(memoryref_isassigned, bool, args[2]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[1] != kind) {
            order = language_get_atomic_order_checked((language_sym_t*)args[1], 1, 0);
            language_atomic_error("memoryref_isassigned: non-atomic memory cannot be accessed atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        order = language_get_atomic_order_checked((language_sym_t*)args[1], 1, 0);
        if (order == language_memory_order_notatomic)
            language_atomic_error("memoryref_isassigned: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        // TODO(jwn): decide on the fences required for ordering here
        return language_false;
    return language_memoryref_isassigned(m, kind == (language_value_t*)language_atomic_sym);
}

LANGUAGE_CALLABLE(language_f_memoryrefswap)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefswap!, 4, 4);
    LANGUAGE_TYPECHK(memoryrefswap!, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefswap!, symbol, args[2]);
    LANGUAGE_TYPECHK(memoryrefswap!, bool, args[3]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[2] != kind) {
            order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 1);
            language_atomic_error("memoryrefswap!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 1);
        if (order == language_memory_order_notatomic)
            language_atomic_error("memoryrefswap!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    return language_memoryrefswap(m, args[1], kind == (language_value_t*)language_atomic_sym);
}

LANGUAGE_CALLABLE(language_f_memoryrefmodify)
{
    enum language_memory_order order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefmodify!, 5, 5);
    LANGUAGE_TYPECHK(memoryrefmodify!, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefmodify!, symbol, args[3]);
    LANGUAGE_TYPECHK(memoryrefmodify!, bool, args[4]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[3] != kind) {
            order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
            language_atomic_error("memoryrefmodify!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
        if (order == language_memory_order_notatomic)
            language_atomic_error("memoryrefmodify!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    return language_memoryrefmodify(m, args[1], args[2], kind == (language_value_t*)language_atomic_sym);
}

LANGUAGE_CALLABLE(language_f_memoryrefreplace)
{
    enum language_memory_order success_order = language_memory_order_notatomic;
    enum language_memory_order failure_order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefreplace!, 6, 6);
    LANGUAGE_TYPECHK(memoryrefreplace!, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefreplace!, symbol, args[3]);
    LANGUAGE_TYPECHK(memoryrefreplace!, symbol, args[4]);
    LANGUAGE_TYPECHK(memoryrefreplace!, bool, args[5]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[4] != kind)
            language_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (args[3] != kind) {
            success_order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
            language_atomic_error("memoryrefreplace!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        success_order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 1);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[4], 1, 0);
        if (failure_order > success_order)
            language_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (success_order == language_memory_order_notatomic)
            language_atomic_error("memoryrefreplace!: atomic memory cannot be written non-atomically");
        if (failure_order == language_memory_order_notatomic)
            language_atomic_error("memoryrefreplace!: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    return language_memoryrefreplace(m, args[1], args[2], kind == (language_value_t*)language_atomic_sym);
}

LANGUAGE_CALLABLE(language_f_memoryrefsetonce)
{
    enum language_memory_order success_order = language_memory_order_notatomic;
    enum language_memory_order failure_order = language_memory_order_notatomic;
    LANGUAGE_NARGS(memoryrefsetonce!, 5, 5);
    LANGUAGE_TYPECHK(memoryrefsetonce!, genericmemoryref, args[0]);
    LANGUAGE_TYPECHK(memoryrefsetonce!, symbol, args[2]);
    LANGUAGE_TYPECHK(memoryrefsetonce!, symbol, args[3]);
    LANGUAGE_TYPECHK(memoryrefsetonce!, bool, args[4]);
    language_genericmemoryref_t m = *(language_genericmemoryref_t*)args[0];
    language_value_t *kind = language_tparam0(language_typetagof(m.mem));
    if (kind == (language_value_t*)language_not_atomic_sym) {
        if (args[3] != kind)
            language_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (args[2] != kind) {
            success_order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 1);
            language_atomic_error("memoryrefsetonce!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (language_value_t*)language_atomic_sym) {
        success_order = language_get_atomic_order_checked((language_sym_t*)args[2], 1, 1);
        failure_order = language_get_atomic_order_checked((language_sym_t*)args[3], 1, 0);
        if (failure_order > success_order)
            language_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (success_order == language_memory_order_notatomic)
            language_atomic_error("memoryrefsetonce!: atomic memory cannot be written non-atomically");
        if (failure_order == language_memory_order_notatomic)
            language_atomic_error("memoryrefsetonce!: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        language_bounds_error_int((language_value_t*)m.mem, 1);
    return language_memoryrefsetonce(m, args[1], kind == (language_value_t*)language_atomic_sym);
}

// type definition ------------------------------------------------------------

LANGUAGE_CALLABLE(language_f__structtype)
{
    LANGUAGE_NARGS(_structtype, 7, 7);
    LANGUAGE_TYPECHK(_structtype, module, args[0]);
    LANGUAGE_TYPECHK(_structtype, symbol, args[1]);
    LANGUAGE_TYPECHK(_structtype, simplevector, args[2]);
    LANGUAGE_TYPECHK(_structtype, simplevector, args[3]);
    LANGUAGE_TYPECHK(_structtype, simplevector, args[4]);
    LANGUAGE_TYPECHK(_structtype, bool, args[5]);
    LANGUAGE_TYPECHK(_structtype, long, args[6]);
    language_value_t *fieldnames = args[3];
    language_value_t *fieldattrs = args[4];
    language_datatype_t *dt = NULL;
    dt = language_new_datatype((language_sym_t*)args[1], (language_module_t*)args[0], NULL, (language_svec_t*)args[2],
                         (language_svec_t*)fieldnames, NULL, (language_svec_t*)fieldattrs,
                         0, args[5]==language_true ? 1 : 0, language_unbox_long(args[6]));
    return dt->name->wrapper;
}

LANGUAGE_CALLABLE(language_f__abstracttype)
{
    LANGUAGE_NARGS(_abstracttype, 3, 3);
    LANGUAGE_TYPECHK(_abstracttype, module, args[0]);
    LANGUAGE_TYPECHK(_abstracttype, symbol, args[1]);
    LANGUAGE_TYPECHK(_abstracttype, simplevector, args[2]);
    language_datatype_t *dt = language_new_abstracttype(args[1], (language_module_t*)args[0], NULL, (language_svec_t*)args[2]);
    return dt->name->wrapper;
}

LANGUAGE_CALLABLE(language_f__primitivetype)
{
    LANGUAGE_NARGS(_primitivetype, 4, 4);
    LANGUAGE_TYPECHK(_primitivetype, module, args[0]);
    LANGUAGE_TYPECHK(_primitivetype, symbol, args[1]);
    LANGUAGE_TYPECHK(_primitivetype, simplevector, args[2]);
    language_sym_t *name = (language_sym_t*)args[1];
    language_value_t *vnb = args[3];
    if (!language_is_long(vnb))
        language_errorf("invalid declaration of primitive type %s",
                  language_symbol_name((language_sym_t*)name));
    ssize_t nb = language_unbox_long(vnb);
    if (nb < 1 || nb >= (1 << 23) || (nb & 7) != 0)
        language_errorf("invalid number of bits in primitive type %s",
                  language_symbol_name((language_sym_t*)name));
    language_datatype_t *dt = language_new_primitivetype(args[1], (language_module_t*)args[0], NULL, (language_svec_t*)args[2], nb);
    return dt->name->wrapper;
}

static void language_set_datatype_super(language_datatype_t *tt, language_value_t *super)
{
    const char *error = NULL;
    if (!language_is_datatype(super))
        error = "can only subtype data types";
    else if (tt->super != NULL)
        error = "type already has a supertype";
    else if (tt->name == ((language_datatype_t*)super)->name)
        error = "a type cannot subtype itself";
    else if (language_is_tuple_type(super))
        error = "cannot subtype a tuple type";
    else if (language_is_namedtuple_type(super))
        error = "cannot subtype a named tuple type";
    else if (language_subtype(super, (language_value_t*)language_type_type))
        error = "cannot add subtypes to Type";
    else if (language_subtype(super, (language_value_t*)language_builtin_type))
        error = "cannot add subtypes to Core.Builtin";
    else if (!language_is_abstracttype(super))
        error = "can only subtype abstract types";
    if (error)
         language_errorf("invalid subtyping in definition of %s: %s.", language_symbol_name(tt->name->name), error);
    tt->super = (language_datatype_t*)super;
    language_gc_wb(tt, tt->super);
}

LANGUAGE_CALLABLE(language_f__setsuper)
{
    LANGUAGE_NARGS(_setsuper!, 2, 2);
    language_datatype_t *dt = (language_datatype_t*)language_unwrap_unionall(args[0]);
    LANGUAGE_TYPECHK(_setsuper!, datatype, (language_value_t*)dt);
    language_set_datatype_super(dt, args[1]);
    return language_nothing;
}

LANGUAGE_CALLABLE(language_f_donotdelete)
{
    return language_nothing;
}

LANGUAGE_CALLABLE(language_f_compilerbarrier)
{
    LANGUAGE_NARGS(compilerbarrier, 2, 2);
    LANGUAGE_TYPECHK(compilerbarrier, symbol, args[0])
    language_sym_t *setting = (language_sym_t*)args[0];
    if (!(setting == language_symbol("type") ||
          setting == language_symbol("const") ||
          setting == language_symbol("conditional")))
        language_error("The first argument of `compilerbarrier` must be either of `:type`, `:const` or `:conditional`.");
    language_value_t *val = args[1];
    return val;
}

LANGUAGE_CALLABLE(language_f_finalizer)
{
    // NOTE the compiler may temporarily insert additional argument for the later inlining pass
    LANGUAGE_NARGS(finalizer, 2, 4);
    language_task_t *ct = language_current_task;
    language_gc_add_finalizer_(ct->ptls, args[1], args[0]);
    return language_nothing;
}

LANGUAGE_CALLABLE(language_f__compute_sparams)
{
    LANGUAGE_NARGSV(_compute_sparams, 1);
    language_method_t *m = (language_method_t*)args[0];
    LANGUAGE_TYPECHK(_compute_sparams, method, (language_value_t*)m);
    language_datatype_t *tt = language_inst_arg_tuple_type(args[1], &args[2], nargs-1, 1);
    language_svec_t *env = language_emptysvec;
    LANGUAGE_GC_PUSH2(&env, &tt);
    language_type_intersection_env((language_value_t*)tt, m->sig, &env);
    LANGUAGE_GC_POP();
    return (language_value_t*)env;
}

LANGUAGE_CALLABLE(language_f__svec_ref)
{
    LANGUAGE_NARGS(_svec_ref, 2, 2);
    language_svec_t *s = (language_svec_t*)args[0];
    language_value_t *i = (language_value_t*)args[1];
    LANGUAGE_TYPECHK(_svec_ref, simplevector, (language_value_t*)s);
    LANGUAGE_TYPECHK(_svec_ref, long, i);
    size_t len = language_svec_len(s);
    ssize_t idx = language_unbox_long(i);
    if (idx < 1 || idx > len) {
        language_bounds_error_int((language_value_t*)s, idx);
    }
    return language_svecref(s, idx-1);
}

static int equiv_field_types(language_value_t *old, language_value_t *ft)
{
    size_t nf = language_svec_len(ft);
    if (language_svec_len(old) != nf)
        return 0;
    size_t i;
    for (i = 0; i < nf; i++) {
        language_value_t *ta = language_svecref(old, i);
        language_value_t *tb = language_svecref(ft, i);
        if (language_has_free_typevars(ta)) {
            if (!language_has_free_typevars(tb) || !language_types_egal(ta, tb))
                return 0;
        }
        else if (language_has_free_typevars(tb) || language_typetagof(ta) != language_typetagof(tb) ||
                 !language_types_equal(ta, tb)) {
            return 0;
        }
    }
    return 1;
}

// If a field can reference its enclosing type, then the inlining
// recursive depth is not statically bounded for some layouts, so we cannot
// inline it. The only way fields can reference this type (due to
// syntax-enforced restrictions) is via being passed as a type parameter. Thus
// we can conservatively check this by examining only the parameters of the
// dependent types. Additionally, a field might have already observed this
// object for layout purposes before we got around to deciding if inlining
// would be possible, so we cannot change the layout now if so.
// affects_layout is a (conservative) analysis of layout_uses_free_typevars
// freevars is a (conservative) analysis of what calling language_has_bound_typevars from name->wrapper gives (TODO: just call this instead?)
static int references_name(language_value_t *p, language_typename_t *name, int affects_layout, int freevars) LANGUAGE_NOTSAFEPOINT
{
    if (freevars && !language_has_free_typevars(p))
        freevars = 0;
    while (language_is_unionall(p)) {
        if (references_name((language_value_t*)((language_unionall_t*)p)->var->lb, name, 0, freevars) ||
            references_name((language_value_t*)((language_unionall_t*)p)->var->ub, name, 0, freevars))
            return 1;
       p = ((language_unionall_t*)p)->body;
    }
    if (language_is_uniontype(p)) {
        return references_name(((language_uniontype_t*)p)->a, name, affects_layout, freevars) ||
               references_name(((language_uniontype_t*)p)->b, name, affects_layout, freevars);
    }
    if (language_is_typevar(p))
        return 0; // already checked by unionall, if applicable
    if (language_is_datatype(p)) {
        language_datatype_t *dp = (language_datatype_t*)p;
        if (affects_layout && dp->name == name)
            return 1;
        affects_layout = language_is_genericmemory_type(dp) || ((language_datatype_t*)language_unwrap_unionall(dp->name->wrapper))->layout == NULL;
        // and even if it has a layout, the fields themselves might trigger layouts if they use tparam i
        // rather than checking this for each field, we just assume it applies
        if (!affects_layout && freevars && language_field_names(dp) != language_emptysvec) {
            language_svec_t *types = ((language_datatype_t*)language_unwrap_unionall(dp->name->wrapper))->types;
            size_t i, l = language_svec_len(types);
            for (i = 0; i < l; i++) {
                language_value_t *ft = language_svecref(types, i);
                if (!language_is_typevar(ft) && language_has_free_typevars(ft)) {
                    affects_layout = 1;
                    break;
                }
            }
        }
        size_t i, l = language_nparams(p);
        for (i = 0; i < l; i++) {
            if (references_name(language_tparam(p, i), name, affects_layout, freevars))
                return 1;
        }
    }
    return 0;
}


LANGUAGE_CALLABLE(language_f__typebody)
{
    LANGUAGE_NARGS(_typebody!, 1, 2);
    language_datatype_t *dt = (language_datatype_t*)language_unwrap_unionall(args[0]);
    LANGUAGE_TYPECHK(_typebody!, datatype, (language_value_t*)dt);
    if (nargs == 2) {
        language_value_t *ft = args[1];
        LANGUAGE_TYPECHK(_typebody!, simplevector, ft);
        size_t nf = language_svec_len(ft);
        for (size_t i = 0; i < nf; i++) {
            language_value_t *elt = language_svecref(ft, i);
            if (!language_is_type(elt) && !language_is_typevar(elt)) {
                language_type_error_rt(language_symbol_name(dt->name->name),
                                 "type definition",
                                 (language_value_t*)language_type_type, elt);
            }
        }
        if (dt->types != NULL) {
            if (!equiv_field_types((language_value_t*)dt->types, ft))
                language_errorf("invalid redefinition of type %s", language_symbol_name(dt->name->name));
        }
        else {
            dt->types = (language_svec_t*)ft;
            language_gc_wb(dt, ft);
            // If a supertype can reference the same type, then we may not be
            // able to compute the layout of the object before needing to
            // publish it, so we must assume it cannot be inlined, if that
            // check passes, then we also still need to check the fields too.
            if (!dt->name->mutabl && (nf == 0 || !references_name((language_value_t*)dt->super, dt->name, 0, 1))) {
                int mayinlinealloc = 1;
                size_t i;
                for (i = 0; i < nf; i++) {
                    language_value_t *fld = language_svecref(ft, i);
                    if (references_name(fld, dt->name, 1, 1)) {
                        mayinlinealloc = 0;
                        break;
                    }
                }
                dt->name->mayinlinealloc = mayinlinealloc;
            }
        }
    }

    LANGUAGE_TRY {
        language_reinstantiate_inner_types(dt);
    }
    LANGUAGE_CATCH {
        dt->name->partial = NULL;
        language_rethrow();
    }

    if (language_is_structtype(dt))
        language_compute_field_offsets(dt);
    return language_nothing;
}

// this is a heuristic for allowing "redefining" a type to something identical
static int equiv_type(language_value_t *ta, language_value_t *tb)
{
    language_datatype_t *dta = (language_datatype_t*)language_unwrap_unionall(ta);
    if (!language_is_datatype(dta))
        return 0;
    language_datatype_t *dtb = (language_datatype_t*)language_unwrap_unionall(tb);
    if (!(language_typetagof(dta) == language_typetagof(dtb) &&
          dta->name->name == dtb->name->name &&
          dta->name->abstract == dtb->name->abstract &&
          dta->name->mutabl == dtb->name->mutabl &&
          dta->name->n_uninitialized == dtb->name->n_uninitialized &&
          dta->isprimitivetype == dtb->isprimitivetype &&
          (!dta->isprimitivetype || dta->layout->size == dtb->layout->size) &&
          (dta->name->atomicfields == NULL
           ? dtb->name->atomicfields == NULL
           : (dtb->name->atomicfields != NULL &&
              memcmp(dta->name->atomicfields, dtb->name->atomicfields, (language_svec_len(dta->name->names) + 31) / 32 * sizeof(uint32_t)) == 0)) &&
          (dta->name->constfields == NULL
           ? dtb->name->constfields == NULL
           : (dtb->name->constfields != NULL &&
              memcmp(dta->name->constfields, dtb->name->constfields, (language_svec_len(dta->name->names) + 31) / 32 * sizeof(uint32_t)) == 0)) &&
          language_egal((language_value_t*)language_field_names(dta), (language_value_t*)language_field_names(dtb)) &&
          language_nparams(dta) == language_nparams(dtb)))
        return 0;
    language_value_t *a=NULL, *b=NULL;
    int ok = 1;
    LANGUAGE_GC_PUSH2(&a, &b);
    a = language_rewrap_unionall((language_value_t*)dta->super, dta->name->wrapper);
    b = language_rewrap_unionall((language_value_t*)dtb->super, dtb->name->wrapper);
    if (!language_types_equal(a, b))
        goto no;
    LANGUAGE_TRY {
        a = language_apply_type(dtb->name->wrapper, language_svec_data(dta->parameters), language_nparams(dta));
    }
    LANGUAGE_CATCH {
        ok = 0;
    }
    if (!ok)
        goto no;
    assert(language_is_datatype(a));
    a = dta->name->wrapper;
    b = dtb->name->wrapper;
    while (language_is_unionall(a)) {
        language_unionall_t *ua = (language_unionall_t*)a;
        language_unionall_t *ub = (language_unionall_t*)b;
        if (!language_types_egal(ua->var->lb, ub->var->lb) || !language_types_egal(ua->var->ub, ub->var->ub) ||
            ua->var->name != ub->var->name)
            goto no;
        a = language_instantiate_unionall(ua, (language_value_t*)ub->var);
        b = ub->body;
    }
    LANGUAGE_GC_POP();
    return 1;
 no:
    LANGUAGE_GC_POP();
    return 0;
}

LANGUAGE_CALLABLE(language_f__equiv_typedef)
{
    LANGUAGE_NARGS(_equiv_typedef, 2, 2);
    return equiv_type(args[0], args[1]) ? language_true : language_false;
}

// IntrinsicFunctions ---------------------------------------------------------

static void (*runtime_fp[num_intrinsics])(void);
static unsigned intrinsic_nargs[num_intrinsics];

LANGUAGE_CALLABLE(language_f_intrinsic_call)
{
    enum intrinsic f = (enum intrinsic)*(uint32_t*)language_data_ptr(F);
    if (f == cglobal && nargs == 1)
        f = cglobal_auto;
    unsigned fargs = intrinsic_nargs[f];
    if (!fargs)
        language_errorf("`%s` requires the compiler", language_intrinsic_name(f));
    LANGUAGE_NARGS(intrinsic_call, fargs, fargs);

    union {
        void (*fptr)(void);
        language_value_t *(*call1)(language_value_t*);
        language_value_t *(*call2)(language_value_t*, language_value_t*);
        language_value_t *(*call3)(language_value_t*, language_value_t*, language_value_t*);
        language_value_t *(*call4)(language_value_t*, language_value_t*, language_value_t*, language_value_t*);
        language_value_t *(*call5)(language_value_t*, language_value_t*, language_value_t*, language_value_t*, language_value_t*);
    } fptr;
    fptr.fptr = runtime_fp[f];
    switch (fargs) {
        case 1:
            return fptr.call1(args[0]);
        case 2:
            return fptr.call2(args[0], args[1]);
        case 3:
            return fptr.call3(args[0], args[1], args[2]);
        case 4:
            return fptr.call4(args[0], args[1], args[2], args[3]);
        case 5:
            return fptr.call5(args[0], args[1], args[2], args[3], args[4]);
        default:
            assert(0 && "unexpected number of arguments to an intrinsic function");
    }
    language_gc_debug_critical_error();
    abort();
}

LANGUAGE_DLLEXPORT const char *language_intrinsic_name(int f)
{
    switch ((enum intrinsic)f) {
    default: return "invalid";
#define ADD_I(func, nargs) case func: return #func;
#define ADD_HIDDEN ADD_I
#define ALIAS ADD_I
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
    }
}

unsigned language_intrinsic_nargs(int f)
{
    return intrinsic_nargs[f];
}

// init -----------------------------------------------------------------------

static void add_intrinsic_properties(enum intrinsic f, unsigned nargs, void (*pfunc)(void))
{
    assert(nargs <= 5 && "language_f_intrinsic_call only implements up to 5 args");
    intrinsic_nargs[f] = nargs;
    runtime_fp[f] = pfunc;
}

static void add_intrinsic(language_module_t *inm, const char *name, enum intrinsic f) LANGUAGE_GC_DISABLED
{
    language_value_t *i = language_permbox32(language_intrinsic_type, 0, (int32_t)f);
    language_sym_t *sym = language_symbol(name);
    language_set_const(inm, sym, i);
    language_module_public(inm, sym, 1);
}

void language_init_intrinsic_properties(void) LANGUAGE_GC_DISABLED
{
#define ADD_I(name, nargs) add_intrinsic_properties(name, nargs, (void(*)(void))&language_##name);
#define ADD_HIDDEN ADD_I
#define ALIAS(alias, base) add_intrinsic_properties(alias, intrinsic_nargs[base], runtime_fp[base]);
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
}

void language_init_intrinsic_functions(void) LANGUAGE_GC_DISABLED
{
    language_module_t *inm = language_new_module(language_symbol("Intrinsics"), NULL);
    inm->parent = language_core_module;
    language_set_const(language_core_module, language_symbol("Intrinsics"), (language_value_t*)inm);
    language_mk_builtin_func(language_intrinsic_type, "IntrinsicFunction", language_f_intrinsic_call);
    language_mk_builtin_func(
        (language_datatype_t*)language_unwrap_unionall((language_value_t*)language_opaque_closure_type),
        "OpaqueClosure", language_f_opaque_closure_call);

    // Save a reference to the just created OpaqueClosure method, so we can provide special
    // codegen for it later.
    language_opaque_closure_method = (language_method_t*)language_methtable_lookup(language_opaque_closure_typename->mt,
        (language_value_t*)language_anytuple_type, 1);

#define ADD_I(name, nargs) add_intrinsic(inm, #name, name);
#define ADD_HIDDEN(name, nargs)
#define ALIAS ADD_I
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
}

static void add_builtin(const char *name, language_value_t *v)
{
    language_set_const(language_core_module, language_symbol(name), v);
}

language_fptr_args_t language_get_builtin_fptr(language_datatype_t *dt)
{
    assert(language_subtype((language_value_t*)dt, (language_value_t*)language_builtin_type));
    language_typemap_entry_t *entry = (language_typemap_entry_t*)language_atomic_load_relaxed(&dt->name->mt->defs);
    language_method_instance_t *mi = language_atomic_load_relaxed(&entry->func.method->unspecialized);
    language_language_instance_t *ci = language_atomic_load_relaxed(&mi->cache);
    assert(ci->owner == language_nothing);
    return language_atomic_load_relaxed(&ci->specptr.fptr1);
}

static language_value_t *add_builtin_func(const char *name, language_fptr_args_t fptr)
{
    return language_mk_builtin_func(NULL, name, fptr)->instance;
}

void language_init_primitives(void) LANGUAGE_GC_DISABLED
{
    language_builtin_is = add_builtin_func("===", language_f_is);
    language_builtin_typeof = add_builtin_func("typeof", language_f_typeof);
    language_builtin_sizeof = add_builtin_func("sizeof", language_f_sizeof);
    language_builtin_issubtype = add_builtin_func("<:", language_f_issubtype);
    language_builtin_isa = add_builtin_func("isa", language_f_isa);
    language_builtin_typeassert = add_builtin_func("typeassert", language_f_typeassert);
    language_builtin_throw = add_builtin_func("throw", language_f_throw);
    language_builtin_tuple = add_builtin_func("tuple", language_f_tuple);
    language_builtin_ifelse = add_builtin_func("ifelse", language_f_ifelse);

    // field access
    language_builtin_getfield = add_builtin_func("getfield",  language_f_getfield);
    language_builtin_setfield = add_builtin_func("setfield!",  language_f_setfield);
    language_builtin_setfieldonce = add_builtin_func("setfieldonce!",  language_f_setfieldonce);
    language_builtin_swapfield = add_builtin_func("swapfield!",  language_f_swapfield);
    language_builtin_modifyfield = add_builtin_func("modifyfield!",  language_f_modifyfield);
    language_builtin_replacefield = add_builtin_func("replacefield!",  language_f_replacefield);
    language_builtin_fieldtype = add_builtin_func("fieldtype", language_f_fieldtype);
    language_builtin_nfields = add_builtin_func("nfields", language_f_nfields);
    language_builtin_isdefined = add_builtin_func("isdefined", language_f_isdefined);

    // module bindings
    language_builtin_getglobal = add_builtin_func("getglobal", language_f_getglobal);
    language_builtin_setglobal = add_builtin_func("setglobal!", language_f_setglobal);
    add_builtin_func("get_binding_type", language_f_get_binding_type);
    language_builtin_swapglobal = add_builtin_func("swapglobal!", language_f_swapglobal);
    language_builtin_replaceglobal = add_builtin_func("replaceglobal!", language_f_replaceglobal);
    language_builtin_modifyglobal = add_builtin_func("modifyglobal!", language_f_modifyglobal);
    language_builtin_setglobalonce = add_builtin_func("setglobalonce!", language_f_setglobalonce);

    // memory primitives
    language_builtin_memoryref = add_builtin_func("memoryrefnew", language_f_memoryref);
    language_builtin_memoryrefoffset = add_builtin_func("memoryrefoffset", language_f_memoryrefoffset);
    language_builtin_memoryrefget = add_builtin_func("memoryrefget", language_f_memoryrefget);
    language_builtin_memoryrefset = add_builtin_func("memoryrefset!", language_f_memoryrefset);
    language_builtin_memoryref_isassigned = add_builtin_func("memoryref_isassigned", language_f_memoryref_isassigned);
    language_builtin_memoryrefswap = add_builtin_func("memoryrefswap!", language_f_memoryrefswap);
    language_builtin_memoryrefreplace = add_builtin_func("memoryrefreplace!", language_f_memoryrefreplace);
    language_builtin_memoryrefmodify = add_builtin_func("memoryrefmodify!", language_f_memoryrefmodify);
    language_builtin_memoryrefsetonce = add_builtin_func("memoryrefsetonce!", language_f_memoryrefsetonce);

    // method table utils
    language_builtin_applicable = add_builtin_func("applicable", language_f_applicable);
    language_builtin_invoke = add_builtin_func("invoke", language_f_invoke);

    // internal functions
    language_builtin_apply_type = add_builtin_func("apply_type", language_f_apply_type);
    language_builtin__apply_iterate = add_builtin_func("_apply_iterate", language_f__apply_iterate);
    language_builtin__expr = add_builtin_func("_expr", language_f__expr);
    language_builtin_svec = add_builtin_func("svec", language_f_svec);
    add_builtin_func("_apply_pure", language_f__apply_pure);
    add_builtin_func("_call_latest", language_f__call_latest);
    add_builtin_func("_call_in_world", language_f__call_in_world);
    add_builtin_func("_call_in_world_total", language_f__call_in_world_total);
    add_builtin_func("_typevar", language_f__typevar);
    add_builtin_func("_structtype", language_f__structtype);
    add_builtin_func("_abstracttype", language_f__abstracttype);
    add_builtin_func("_primitivetype", language_f__primitivetype);
    add_builtin_func("_setsuper!", language_f__setsuper);
    language_builtin__typebody = add_builtin_func("_typebody!", language_f__typebody);
    add_builtin_func("_equiv_typedef", language_f__equiv_typedef);
    language_builtin_donotdelete = add_builtin_func("donotdelete", language_f_donotdelete);
    language_builtin_compilerbarrier = add_builtin_func("compilerbarrier", language_f_compilerbarrier);
    add_builtin_func("finalizer", language_f_finalizer);
    add_builtin_func("_compute_sparams", language_f__compute_sparams);
    add_builtin_func("_svec_ref", language_f__svec_ref);
    add_builtin_func("current_scope", language_f_current_scope);

    // builtin types
    add_builtin("Any", (language_value_t*)language_any_type);
    add_builtin("Type", (language_value_t*)language_type_type);
    add_builtin("Nothing", (language_value_t*)language_nothing_type);
    add_builtin("nothing", (language_value_t*)language_nothing);
    add_builtin("TypeName", (language_value_t*)language_typename_type);
    add_builtin("DataType", (language_value_t*)language_datatype_type);
    add_builtin("TypeVar", (language_value_t*)language_tvar_type);
    add_builtin("UnionAll", (language_value_t*)language_unionall_type);
    add_builtin("Union", (language_value_t*)language_uniontype_type);
    add_builtin("TypeofBottom", (language_value_t*)language_typeofbottom_type);
    add_builtin("Tuple", (language_value_t*)language_anytuple_type);
    add_builtin("TypeofVararg", (language_value_t*)language_vararg_type);
    add_builtin("SimpleVector", (language_value_t*)language_simplevector_type);
    add_builtin("Vararg", (language_value_t*)language_wrap_vararg(NULL, NULL, 0, 0));

    add_builtin("Module", (language_value_t*)language_module_type);
    add_builtin("MethodTable", (language_value_t*)language_methtable_type);
    add_builtin("Method", (language_value_t*)language_method_type);
    add_builtin("LanguageInstance", (language_value_t*)language_language_instance_type);
    add_builtin("TypeMapEntry", (language_value_t*)language_typemap_entry_type);
    add_builtin("TypeMapLevel", (language_value_t*)language_typemap_level_type);
    add_builtin("Symbol", (language_value_t*)language_symbol_type);
    add_builtin("SSAValue", (language_value_t*)language_ssavalue_type);
    add_builtin("SlotNumber", (language_value_t*)language_slotnumber_type);
    add_builtin("Argument", (language_value_t*)language_argument_type);
    add_builtin("Const", (language_value_t*)language_const_type);
    add_builtin("PartialStruct", (language_value_t*)language_partial_struct_type);
    add_builtin("PartialOpaque", (language_value_t*)language_partial_opaque_type);
    add_builtin("InterConditional", (language_value_t*)language_interconditional_type);
    add_builtin("MethodMatch", (language_value_t*)language_method_match_type);
    add_builtin("IntrinsicFunction", (language_value_t*)language_intrinsic_type);
    add_builtin("Function", (language_value_t*)language_function_type);
    add_builtin("Builtin", (language_value_t*)language_builtin_type);
    add_builtin("MethodInstance", (language_value_t*)language_method_instance_type);
    add_builtin("LanguageInfo", (language_value_t*)language_language_info_type);
    add_builtin("LLVMPtr", (language_value_t*)language_llvmpointer_type);
    add_builtin("Task", (language_value_t*)language_task_type);
    add_builtin("OpaqueClosure", (language_value_t*)language_opaque_closure_type);

    add_builtin("AddrSpace", (language_value_t*)language_addrspace_type);
    add_builtin("Ref", (language_value_t*)language_ref_type);
    add_builtin("Ptr", (language_value_t*)language_pointer_type);
    //add_builtin("GenericPtr", (language_value_t*)language_genericpointer_type);
    add_builtin("AbstractArray", (language_value_t*)language_abstractarray_type);
    add_builtin("DenseArray", (language_value_t*)language_densearray_type);
    add_builtin("Array", (language_value_t*)language_array_type);
    add_builtin("GenericMemory", (language_value_t*)language_genericmemory_type);
    add_builtin("GenericMemoryRef", (language_value_t*)language_genericmemoryref_type);

    add_builtin("Expr", (language_value_t*)language_expr_type);
    add_builtin("LineNumberNode", (language_value_t*)language_linenumbernode_type);
    add_builtin("LegacyLineInfoNode", (language_value_t*)language_lineinfonode_type);
    add_builtin("DebugInfo", (language_value_t*)language_debuginfo_type);
    add_builtin("GotoNode", (language_value_t*)language_gotonode_type);
    add_builtin("GotoIfNot", (language_value_t*)language_gotoifnot_type);
    add_builtin("EnterNode", (language_value_t*)language_enternode_type);
    add_builtin("ReturnNode", (language_value_t*)language_returnnode_type);
    add_builtin("PiNode", (language_value_t*)language_pinode_type);
    add_builtin("PhiNode", (language_value_t*)language_phinode_type);
    add_builtin("PhiCNode", (language_value_t*)language_phicnode_type);
    add_builtin("UpsilonNode", (language_value_t*)language_upsilonnode_type);
    add_builtin("QuoteNode", (language_value_t*)language_quotenode_type);
    add_builtin("NewvarNode", (language_value_t*)language_newvarnode_type);
    add_builtin("Binding", (language_value_t*)language_binding_type);
    add_builtin("GlobalRef", (language_value_t*)language_globalref_type);
    add_builtin("NamedTuple", (language_value_t*)language_namedtuple_type);

    add_builtin("Boolean", (language_value_t*)language_bool_type);
    add_builtin("UInt8", (language_value_t*)language_uint8_type);
    add_builtin("UInt16", (language_value_t*)language_uint16_type);
    add_builtin("UInt32", (language_value_t*)language_uint32_type);
    add_builtin("UInt64", (language_value_t*)language_uint64_type);
    add_builtin("Int32", (language_value_t*)language_int32_type);
    add_builtin("Int64", (language_value_t*)language_int64_type);
#ifdef _P64
    add_builtin("Integer", (language_value_t*)language_int64_type);
#else
    add_builtin("Integer", (language_value_t*)language_int32_type);
#endif

    add_builtin("AbstractString", (language_value_t*)language_abstractstring_type);
    add_builtin("String", (language_value_t*)language_string_type);
}

#ifdef __cplusplus
}
#endif
