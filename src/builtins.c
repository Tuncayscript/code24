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

static int bits_equal(const void *a, const void *b, int sz) CODE_NOTSAFEPOINT
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

// The frequently used code_egal function deserves special attention when it
// comes to performance which is made challenging by the fact that the
// function has to handle quite a few different cases and because it is
// called recursively.  To optimize performance many special cases are
// handle with separate comparisons which can dramatically reduce the run
// time of the function.  The compiler can translate these simple tests
// with little effort, e.g., few registers are used.
//
// The complex cases require more effort and more registers to be translated
// efficiently.  The effected cases include comparing tuples and fields.  If
// the code to perform these operation would be inlined in the code_egal
// function then the compiler would generate at the or close to the top of
// the function a prologue which saves all the callee-save registers and at
// the end the respective epilogue.  The result is that even the fast cases
// are slowed down.
//
// The solution is to keep the code in code_egal simple and split out the
// (more) complex cases into their own functions which are marked with
// NOINLINE.
static int NOINLINE compare_svec(code_svec_t *a, code_svec_t *b) CODE_NOTSAFEPOINT
{
    size_t i, l = code_svec_len(a);
    if (l != code_svec_len(b))
        return 0;
    for (i = 0; i < l; i++) {
        if (!code_egal(code_svecref(a, i), code_svecref(b, i)))
            return 0;
    }
    return 1;
}

// See comment above for an explanation of NOINLINE.
static int NOINLINE compare_fields(const code_value_t *a, const code_value_t *b, code_datatype_t *dt) CODE_NOTSAFEPOINT
{
    size_t nf = code_datatype_nfields(dt);
    // npointers is used at end, but fetched here for locality with nfields.
    int npointers = ((code_datatype_t*)dt)->layout->npointers;
    for (size_t f = 0; f < nf; f++) {
        size_t offs = code_field_offset(dt, f);
        char *ao = (char*)a + offs;
        char *bo = (char*)b + offs;
        if (code_field_isptr(dt, f)) {
            // Save ptr recursion until the end -- only recurse if otherwise equal
            // Note that we also skip comparing the pointers for null here, because
            // null fields are rare so it can save CPU to delay this read too.
            continue;
        }
        else {
            code_datatype_t *ft = (code_datatype_t*)code_field_type_concrete(dt, f);
            if (code_is_uniontype(ft)) {
                size_t idx = code_field_size(dt, f) - 1;
                uint8_t asel = ((uint8_t*)ao)[idx];
                uint8_t bsel = ((uint8_t*)bo)[idx];
                if (asel != bsel)
                    return 0;
                ft = (code_datatype_t*)code_nth_union_component((code_value_t*)ft, asel);
            }
            else if (ft->layout->first_ptr >= 0) {
                // If the field is a inline immutable that can be undef
                // we need to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                int32_t idx = ft->layout->first_ptr;
                code_value_t *ptra = ((code_value_t**)ao)[idx];
                code_value_t *ptrb = ((code_value_t**)bo)[idx];
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
                assert(code_datatype_nfields(ft) > 0);
                if (!compare_fields((code_value_t*)ao, (code_value_t*)bo, ft))
                    return 0;
            }
        }
    }
    // If we've gotten here, the objects are bitwise equal, besides their pointer fields.
    // Now, we will recurse into code_egal for the pointed-to elements, which might be
    // arbitrarily expensive.
    for (size_t p = 0; p < npointers; p++) {
        size_t offs = code_ptr_offset(dt, p);
        code_value_t *af = ((code_value_t**)a)[offs];
        code_value_t *bf = ((code_value_t**)b)[offs];
        if (af != bf) {
            if (af == NULL || bf == NULL)
                return 0;
            if (!code_egal(af, bf))
                return 0;
        }
    }
    return 1;
}

static int egal_types(const code_value_t *a, const code_value_t *b, code_typeenv_t *env, int tvar_names) CODE_NOTSAFEPOINT
{
    if (a == b)
        return 1;
    uintptr_t dtag = code_typetagof(a);
    if (dtag != code_typetagof(b))
        return 0;
    if (dtag == code_datatype_tag << 4) {
        code_datatype_t *dta = (code_datatype_t*)a;
        code_datatype_t *dtb = (code_datatype_t*)b;
        if (dta->name != dtb->name)
            return 0;
        size_t i, l = code_nparams(dta);
        if (code_nparams(dtb) != l)
            return 0;
        for (i = 0; i < l; i++) {
            if (!egal_types(code_tparam(dta, i), code_tparam(dtb, i), env, tvar_names))
                return 0;
        }
        return 1;
    }
    if (dtag == code_tvar_tag << 4) {
        code_typeenv_t *pe = env;
        while (pe != NULL) {
            if (pe->var == (code_tvar_t*)a)
                return pe->val == b;
            pe = pe->prev;
        }
        return 0;
    }
    if (dtag == code_unionall_tag << 4) {
        code_unionall_t *ua = (code_unionall_t*)a;
        code_unionall_t *ub = (code_unionall_t*)b;
        if (tvar_names && ua->var->name != ub->var->name)
            return 0;
        if (!(egal_types(ua->var->lb, ub->var->lb, env, tvar_names) && egal_types(ua->var->ub, ub->var->ub, env, tvar_names)))
            return 0;
        code_typeenv_t e = { ua->var, (code_value_t*)ub->var, env };
        return egal_types(ua->body, ub->body, &e, tvar_names);
    }
    if (dtag == code_uniontype_tag << 4) {
        return egal_types(((code_uniontype_t*)a)->a, ((code_uniontype_t*)b)->a, env, tvar_names) &&
            egal_types(((code_uniontype_t*)a)->b, ((code_uniontype_t*)b)->b, env, tvar_names);
    }
    if (dtag == code_vararg_tag << 4) {
        code_vararg_t *vma = (code_vararg_t*)a;
        code_vararg_t *vmb = (code_vararg_t*)b;
        code_value_t *vmaT = vma->T ? vma->T : (code_value_t*)code_any_type;
        code_value_t *vmbT = vmb->T ? vmb->T : (code_value_t*)code_any_type;
        if (!egal_types(vmaT, vmbT, env, tvar_names))
            return 0;
        if (vma->N && vmb->N)
            return egal_types(vma->N, vmb->N, env, tvar_names);
        return !vma->N && !vmb->N;
    }
    assert(dtag == code_symbol_tag << 4 || dtag == code_module_tag << 4 || !((code_datatype_t*)code_typeof(a))->name->mutabl);
    return code_egal__bitstag(a, b, dtag);
}

CODE_DLLEXPORT int code_types_egal(code_value_t *a, code_value_t *b)
{
    return egal_types(a, b, NULL, 0);
}

CODE_DLLEXPORT int (code_egal)(const code_value_t *a CODE_MAYBE_UNROOTED, const code_value_t *b CODE_MAYBE_UNROOTED) CODE_NOTSAFEPOINT
{
    // warning: a,b may NOT have been gc-rooted by the caller
    return code_egal(a, b);
}

CODE_DLLEXPORT int code_egal__unboxed(const code_value_t *a CODE_MAYBE_UNROOTED, const code_value_t *b CODE_MAYBE_UNROOTED, uintptr_t dtag) CODE_NOTSAFEPOINT
{
    // warning: a,b may NOT have been gc-rooted by the caller
    return code_egal__unboxed_(a, b, dtag);
}

CODE_DLLEXPORT int code_egal__bitstag(const code_value_t *a CODE_MAYBE_UNROOTED, const code_value_t *b CODE_MAYBE_UNROOTED, uintptr_t dtag) CODE_NOTSAFEPOINT
{
    if (dtag < code_max_tags << 4) {
        switch ((enum code_small_typeof_tags)(dtag >> 4)) {
        case code_int8_tag:
        case code_uint8_tag:
            return *(uint8_t*)a == *(uint8_t*)b;
        case code_int16_tag:
        case code_uint16_tag:
            return *(uint16_t*)a == *(uint16_t*)b;
        case code_int32_tag:
        case code_uint32_tag:
        case code_char_tag:
            return *(uint32_t*)a == *(uint32_t*)b;
        case code_int64_tag:
        case code_uint64_tag:
            return *(uint64_t*)a == *(uint64_t*)b;
        case code_unionall_tag:
            return egal_types(a, b, NULL, 1);
        case code_uniontype_tag:
            return compare_fields(a, b, code_uniontype_type);
        case code_vararg_tag:
            return compare_fields(a, b, code_vararg_type);
        case code_task_tag:
        case code_tvar_tag:
        case code_symbol_tag:
        case code_module_tag:
        case code_bool_tag:
            return 0;
        case code_simplevector_tag:
            return compare_svec((code_svec_t*)a, (code_svec_t*)b);
        case code_string_tag: {
                size_t l = code_string_len(a);
                if (code_string_len(b) != l)
                    return 0;
                return !memcmp(code_string_data(a), code_string_data(b), l);
            }
        case code_datatype_tag: {
                code_datatype_t *dta = (code_datatype_t*)a;
                code_datatype_t *dtb = (code_datatype_t*)b;
                if (dta->name != dtb->name)
                    return 0;
                if (dta->name != code_tuple_typename && (dta->isconcretetype || dtb->isconcretetype))
                    return 0;
                return compare_svec(dta->parameters, dtb->parameters);
            }
#ifndef NDEBUG
        default:
#endif
        case code_max_tags:
        case code_null_tag:
        case code_typeofbottom_tag:
        case code_tags_count:
            abort();
        }
    }
    return code_egal__bits(a, b, (code_datatype_t*)dtag);
}

inline int code_egal__bits(const code_value_t *a CODE_MAYBE_UNROOTED, const code_value_t *b CODE_MAYBE_UNROOTED, code_datatype_t *dt) CODE_NOTSAFEPOINT
{
    size_t sz = code_datatype_size(dt);
    if (sz == 0)
        return 1;
    size_t nf = code_datatype_nfields(dt);
    if (nf == 0 || (!dt->layout->flags.haspadding && dt->layout->flags.isbitsegal))
        return bits_equal(a, b, sz);
    return compare_fields(a, b, dt);
}

// object_id ------------------------------------------------------------------

static uintptr_t bits_hash(const void *b, size_t sz) CODE_NOTSAFEPOINT
{
    switch (sz) {
    case 1:  return int32hash(*(const int8_t*)b);
    case 2:  return int32hash(code_load_unaligned_i16(b));
    case 4:  return int32hash(code_load_unaligned_i32(b));
#ifdef _P64
    case 8:  return int64hash(code_load_unaligned_i64(b));
#else
    case 8:  return int64to32hash(code_load_unaligned_i64(b));
#endif
    default:
#ifdef _P64
        return memhash((const char*)b, sz);
#else
        return memhash32((const char*)b, sz);
#endif
    }
}

static uintptr_t NOINLINE hash_svec(code_svec_t *v) CODE_NOTSAFEPOINT
{
    uintptr_t h = 0;
    size_t i, l = code_svec_len(v);
    for (i = 0; i < l; i++) {
        code_value_t *x = code_svecref(v, i);
        uintptr_t u = (x == NULL) ? 0 : code_object_id(x);
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t immut_id_(code_datatype_t *dt, code_value_t *v, uintptr_t h) CODE_NOTSAFEPOINT;

typedef struct _varidx {
    code_tvar_t *var;
    struct _varidx *prev;
} code_varidx_t;

static uintptr_t type_object_id_(code_value_t *v, code_varidx_t *env) CODE_NOTSAFEPOINT
{
    if (v == NULL)
        return 0;
    code_datatype_t *tv = (code_datatype_t*)code_typeof(v);
    if (tv == code_tvar_type) {
        code_varidx_t *pe = env;
        int i = 0;
        while (pe != NULL) {
            if (pe->var == (code_tvar_t*)v)
                return (i<<8) + 42;
            i++;
            pe = pe->prev;
        }
        uintptr_t bits = code_astaggedvalue(v)->header;
        if (bits & GC_IN_IMAGE)
            return ((uintptr_t*)v)[-2];
        return inthash((uintptr_t)v);
    }
    if (tv == code_uniontype_type) {
        return bitmix(bitmix(code_object_id((code_value_t*)tv),
                             type_object_id_(((code_uniontype_t*)v)->a, env)),
                      type_object_id_(((code_uniontype_t*)v)->b, env));
    }
    if (tv == code_unionall_type) {
        code_unionall_t *u = (code_unionall_t*)v;
        uintptr_t h = u->var->name->hash;
        h = bitmix(h, type_object_id_(u->var->lb, env));
        h = bitmix(h, type_object_id_(u->var->ub, env));
        code_varidx_t e = { u->var, env };
        return bitmix(h, type_object_id_(u->body, &e));
    }
    if (tv == code_datatype_type) {
        code_datatype_t *dtv = (code_datatype_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
        uintptr_t h = ~dtv->name->hash;
        size_t i, l = code_nparams(v);
        for (i = 0; i < l; i++) {
            h = bitmix(h, type_object_id_(code_tparam(v, i), env));
        }
        return h;
    }
    if (tv == code_vararg_type) {
        code_vararg_t *vm = (code_vararg_t*)v;
        code_value_t *t = vm->T ? vm->T : (code_value_t*)code_any_type;
        code_value_t *n = vm->N ? vm->N : code_nothing;
        return bitmix(type_object_id_(t, env),
            type_object_id_(n, env));
    }
    if (tv == code_symbol_type)
        return ((code_sym_t*)v)->hash;
    if (tv == code_module_type)
        return ((code_module_t*)v)->hash;
    assert(!tv->name->mutabl);
    return immut_id_(tv, v, tv->hash);
}

static uintptr_t immut_id_(code_datatype_t *dt, code_value_t *v, uintptr_t h) CODE_NOTSAFEPOINT
{
    size_t sz = code_datatype_size(dt);
    if (sz == 0)
        return ~h;
    size_t f, nf = code_datatype_nfields(dt);
    if (nf == 0 || (!dt->layout->flags.haspadding && dt->layout->flags.isbitsegal && dt->layout->npointers == 0)) {
        // operate element-wise if there are unused bits inside,
        // otherwise just take the whole data block at once
        // a few select pointers (notably symbol) also have special hash values
        // which may affect the stability of the objectid hash, even though
        // they don't affect egal comparison
        return bits_hash(v, sz) ^ h;
    }
    if (dt == code_unionall_type)
        return type_object_id_(v, NULL);
    for (f = 0; f < nf; f++) {
        size_t offs = code_field_offset(dt, f);
        char *vo = (char*)v + offs;
        uintptr_t u;
        if (code_field_isptr(dt, f)) {
            code_value_t *f = *(code_value_t**)vo;
            u = (f == NULL) ? 0 : code_object_id(f);
        }
        else {
            code_datatype_t *fieldtype = (code_datatype_t*)code_field_type_concrete(dt, f);
            if (code_is_uniontype(fieldtype)) {
                uint8_t sel = ((uint8_t*)vo)[code_field_size(dt, f) - 1];
                fieldtype = (code_datatype_t*)code_nth_union_component((code_value_t*)fieldtype, sel);
            }
            assert(code_is_datatype(fieldtype) && !fieldtype->name->abstract && !fieldtype->name->mutabl);
            int32_t first_ptr = fieldtype->layout->first_ptr;
            if (first_ptr >= 0 && ((code_value_t**)vo)[first_ptr] == NULL) {
                // If the field is a inline immutable that can be can be undef
                // we need to check to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                u = 0;
            }
            else {
                u = immut_id_(fieldtype, (code_value_t*)vo, 0);
            }
        }
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t NOINLINE code_object_id__cold(uintptr_t tv, code_value_t *v) CODE_NOTSAFEPOINT
{
    code_datatype_t *dt = (code_datatype_t*)code_to_typeof(tv);
    if (dt->name->mutabl) {
        if (dt == code_string_type) {
#ifdef _P64
            return memhash_seed(code_string_data(v), code_string_len(v), 0xedc3b677);
#else
            return memhash32_seed(code_string_data(v), code_string_len(v), 0xedc3b677);
#endif
        }
        if (dt == code_simplevector_type)
            return hash_svec((code_svec_t*)v);
        if (dt == code_datatype_type) {
            code_datatype_t *dtv = (code_datatype_t*)v;
            uintptr_t h = ~dtv->name->hash;
            return bitmix(h, hash_svec(dtv->parameters));
        }
        if (dt == code_module_type) {
            code_module_t *m = (code_module_t*)v;
            return m->hash;
        }
        uintptr_t bits = code_astaggedvalue(v)->header;
        if (bits & GC_IN_IMAGE)
            return ((uintptr_t*)v)[-2];
        return inthash((uintptr_t)v);
    }
    return immut_id_(dt, v, dt->hash);
}

CODE_DLLEXPORT inline uintptr_t code_object_id_(uintptr_t tv, code_value_t *v) CODE_NOTSAFEPOINT
{
    if (tv == code_symbol_tag << 4) {
        return ((code_sym_t*)v)->hash;
    }
    else if (tv == code_datatype_tag << 4) {
        code_datatype_t *dtv = (code_datatype_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
    }
    else if (tv == (uintptr_t)code_typename_type) {
        return ((code_typename_t*)v)->hash;
    }
    return code_object_id__cold(tv, v);
}


CODE_DLLEXPORT uintptr_t code_object_id(code_value_t *v) CODE_NOTSAFEPOINT
{
    return code_object_id_(code_typetagof(v), v);
}

// eq hash table --------------------------------------------------------------

#include "iddict.c"
#include "idset.c"

// object model and type primitives -------------------------------------------

CODE_CALLABLE(code_f_is)
{
    CODE_NARGS(===, 2, 2);
    return code_egal(args[0], args[1]) ? code_true : code_false;
}

CODE_CALLABLE(code_f_typeof)
{
    CODE_NARGS(typeof, 1, 1);
    return code_typeof(args[0]);
}

CODE_CALLABLE(code_f_sizeof)
{
    CODE_NARGS(sizeof, 1, 1);
    code_value_t *x = args[0];
    if (code_is_unionall(x) || code_is_uniontype(x)) {
        x = code_unwrap_unionall(x);
        size_t elsize = 0;
        int isinline = code_uniontype_size(x, &elsize);
        if (isinline)
            return code_box_long(elsize);
        if (!code_is_datatype(x))
            code_error("Argument is an abstract type and does not have a definite size.");
    }
    if (code_is_datatype(x)) {
        code_datatype_t *dx = (code_datatype_t*)x;
        if (!code_struct_try_layout(dx)) {
            if (dx->name->abstract)
                code_errorf("Abstract type %s does not have a definite size.", code_symbol_name(dx->name->name));
            else
                code_errorf("Argument is an incomplete %s type and does not have a definite size.", code_symbol_name(dx->name->name));
        }
        if (code_is_layout_opaque(dx->layout)) // includes all GenericMemory{kind,T}
            code_errorf("Type %s does not have a definite size.", code_symbol_name(dx->name->name));
        return code_box_long(code_datatype_size(x));
    }
    if (x == code_bottom_type)
        code_error("The empty type does not have a definite size since it does not have instances.");
    if (code_is_string(x))
        return code_box_long(code_string_len(x));
    if (code_is_symbol(x))
        return code_box_long(strlen(code_symbol_name((code_sym_t*)x)));
    if (code_is_svec(x))
        return code_box_long((1+code_svec_len(x))*sizeof(void*));
    code_datatype_t *dt = (code_datatype_t*)code_typeof(x);
    assert(code_is_datatype(dt));
    assert(!dt->name->abstract);
    size_t sz = dt->layout->size;
    if (code_is_genericmemory(x))
        sz = (sz + (dt->layout->flags.arrayelem_isunion ? 1 : 0)) * ((code_genericmemory_t*)x)->length;
    return code_box_long(sz);
}

CODE_CALLABLE(code_f_issubtype)
{
    CODE_NARGS(<:, 2, 2);
    code_value_t *a = args[0], *b = args[1];
    CODE_TYPECHK(<:, type, a);
    CODE_TYPECHK(<:, type, b);
    return (code_subtype(a,b) ? code_true : code_false);
}

CODE_CALLABLE(code_f_isa)
{
    CODE_NARGS(isa, 2, 2);
    CODE_TYPECHK(isa, type, args[1]);
    return (code_isa(args[0],args[1]) ? code_true : code_false);
}

CODE_CALLABLE(code_f_typeassert)
{
    CODE_NARGS(typeassert, 2, 2);
    CODE_TYPECHK(typeassert, type, args[1]);
    if (!code_isa(args[0],args[1]))
        code_type_error("typeassert", args[1], args[0]);
    return args[0];
}

CODE_CALLABLE(code_f_throw)
{
    CODE_NARGS(throw, 1, 1);
    code_throw(args[0]);
    return code_nothing;
}

CODE_CALLABLE(code_f_ifelse)
{
    CODE_NARGS(ifelse, 3, 3);
    CODE_TYPECHK(ifelse, bool, args[0]);
    return (args[0] == code_false ? args[2] : args[1]);
}

CODE_CALLABLE(code_f_current_scope)
{
    CODE_NARGS(current_scope, 0, 0);
    return code_current_task->scope;
}

// apply ----------------------------------------------------------------------

static NOINLINE code_svec_t *_copy_to(size_t newalloc, code_value_t **oldargs, size_t oldalloc)
{
    size_t j;
    code_svec_t *newheap = code_alloc_svec_uninit(newalloc);
    code_value_t **newargs = code_svec_data(newheap);
    for (j = 0; j < oldalloc; j++)
        newargs[j] = oldargs[j];
    for (; j < newalloc; j++)
        newargs[j] = NULL;
    return newheap;
}

STATIC_INLINE void _grow_to(code_value_t **root, code_value_t ***oldargs, code_svec_t **arg_heap, size_t *n_alloc, size_t newalloc, size_t extra)
{
    size_t oldalloc = *n_alloc;
    if (oldalloc >= newalloc)
        return;
    if (extra)
        // grow by an extra 50% if newalloc is still only a guess
        newalloc += oldalloc / 2 + 16;
    CODE_GC_PROMISE_ROOTED(*oldargs);
    code_svec_t *newheap = _copy_to(newalloc, *oldargs, oldalloc);
    *root = (code_value_t*)newheap;
    *arg_heap = newheap;
    *oldargs = code_svec_data(newheap);
    *n_alloc = newalloc;
}


static code_value_t *code_arrayref(code_array_t *a, size_t i)
{
    return code_memoryrefget(code_memoryrefindex(a->ref, i), 0);
}

static code_value_t *do_apply(code_value_t **args, uint32_t nargs, code_value_t *iterate)
{
    code_function_t *f = args[0];
    if (nargs == 2) {
        // some common simple cases
        if (f == code_builtin_svec) {
            if (code_is_svec(args[1]))
                return args[1];
            if (code_is_genericmemory(args[1])) {
                code_genericmemory_t *mem = (code_genericmemory_t*)args[1];
                size_t n = mem->length;
                code_svec_t *t = code_alloc_svec(n);
                CODE_GC_PUSH1(&t);
                for (size_t i = 0; i < n; i++) {
                    code_svecset(t, i, code_genericmemoryref(mem, i));
                }
                CODE_GC_POP();
                return (code_value_t*)t;
            }
            if (code_is_array(args[1])) {
                size_t n = code_array_len(args[1]);
                code_svec_t *t = code_alloc_svec(n);
                CODE_GC_PUSH1(&t);
                for (size_t i = 0; i < n; i++) {
                    code_svecset(t, i, code_arrayref((code_array_t*)args[1], i));
                }
                CODE_GC_POP();
                return (code_value_t*)t;
            }
        }
        else if (f == code_builtin_tuple && code_is_tuple(args[1])) {
            return args[1];
        }
    }
    // estimate how many real arguments we appear to have
    size_t precount = 1;
    size_t extra = 0;
    size_t i;
    for (i = 1; i < nargs; i++) {
        if (code_is_svec(args[i])) {
            precount += code_svec_len(args[i]);
        }
        else if (code_is_tuple(args[i]) || code_is_namedtuple(args[i])) {
            precount += code_nfields(args[i]);
        }
        else if (code_is_genericmemory(args[i])) {
            precount += ((code_genericmemory_t*)args[i])->length;
        }
        else if (code_is_array(args[i])) {
            precount += code_array_len(args[i]);
        }
        else {
            extra += 1;
        }
    }
    if (extra && iterate == NULL) {
        code_undefined_var_error(code_symbol("iterate"), NULL);
    }
    // allocate space for the argument array and gc roots for it
    // based on our previous estimates
    // use the stack if we have a good estimate that it is small
    // otherwise, use the heap and grow it incrementally
    // and if there are any extra elements, we'll also need a couple extra roots
    int onstack = (precount + 32 * extra < code_page_size / sizeof(code_value_t*));
    size_t stackalloc = onstack ? (precount + 4 * extra + (extra ? 16 : 0)) : 1;
    size_t n_alloc;
    code_value_t **roots;
    CODE_GC_PUSHARGS(roots, stackalloc + (extra ? 2 : 0));
    code_value_t **newargs;
    code_svec_t *arg_heap = NULL;
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
        arg_heap = code_alloc_svec(n_alloc);
        roots[0] = (code_value_t*)arg_heap;
        newargs = code_svec_data(arg_heap);
    }
    newargs[0] = f;
    precount -= 1;
    size_t n = 1;
    for (i = 1; i < nargs; i++) {
        code_value_t *ai = args[i];
        if (code_is_svec(ai)) {
            code_svec_t *t = (code_svec_t*)ai;
            size_t j, al = code_svec_len(t);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            for (j = 0; j < al; j++) {
                newargs[n++] = code_svecref(t, j);
                // GC Note: here we assume that the return value of `code_svecref`
                //          will not be young if `arg_heap` becomes old
                //          since they are allocated before `arg_heap`. Otherwise,
                //          we need to add write barrier for !onstack
            }
        }
        else if (code_is_tuple(ai) || code_is_namedtuple(ai)) {
            size_t j, al = code_nfields(ai);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            for (j = 0; j < al; j++) {
                // code_fieldref may allocate.
                newargs[n++] = code_fieldref(ai, j);
                if (arg_heap)
                    code_gc_wb(arg_heap, newargs[n - 1]);
            }
        }
        else if (code_is_genericmemory(ai)) {
            code_genericmemory_t *mem = (code_genericmemory_t*)ai;
            size_t j, al = mem->length;
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(mem))->layout;
            if (layout->flags.arrayelem_isboxed) {
                for (j = 0; j < al; j++) {
                    code_value_t *arg = code_genericmemory_ptr_ref(mem, j);
                    // apply with array splatting may have embedded NULL value (#11772)
                    if (__unlikely(arg == NULL))
                        code_throw(code_undefref_exception);
                    newargs[n++] = arg;
                    if (arg_heap)
                        code_gc_wb(arg_heap, arg);
                }
            }
            else {
                for (j = 0; j < al; j++) {
                    newargs[n++] = code_genericmemoryref(mem, j);
                    if (arg_heap)
                        code_gc_wb(arg_heap, newargs[n - 1]);
                }
            }
        }
        else if (code_is_array(ai)) {
            code_array_t *aai = (code_array_t*)ai;
            size_t j, al = code_array_len(aai);
            precount = (precount > al) ? precount - al : 0;
            _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + al, extra);
            assert(newargs != NULL); // inform GCChecker that we didn't write a NULL here
            const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(aai->ref.mem))->layout;
            if (layout->flags.arrayelem_isboxed) {
                for (j = 0; j < al; j++) {
                    code_value_t *arg = code_array_ptr_ref(aai, j);
                    // apply with array splatting may have embedded NULL value (#11772)
                    if (__unlikely(arg == NULL))
                        code_throw(code_undefref_exception);
                    newargs[n++] = arg;
                    if (arg_heap)
                        code_gc_wb(arg_heap, arg);
                }
            }
            else {
                for (j = 0; j < al; j++) {
                    newargs[n++] = code_arrayref(aai, j);
                    if (arg_heap)
                        code_gc_wb(arg_heap, newargs[n - 1]);
                }
            }
        }
        else {
            assert(extra > 0);
            code_value_t *args[2];
            args[0] = ai;
            code_value_t *next = code_apply_generic(iterate, args, 1);
            while (next != code_nothing) {
                roots[stackalloc] = next;
                code_value_t *value = code_get_nth_field_checked(next, 0);
                roots[stackalloc + 1] = value;
                code_value_t *state = code_get_nth_field_checked(next, 1);
                roots[stackalloc] = state;
                _grow_to(&roots[0], &newargs, &arg_heap, &n_alloc, n + precount + 1, extra);
                CODE_GC_ASSERT_LIVE(value);
                newargs[n++] = value;
                if (arg_heap)
                    code_gc_wb(arg_heap, value);
                roots[stackalloc + 1] = NULL;
                CODE_GC_ASSERT_LIVE(state);
                args[1] = state;
                next = code_apply_generic(iterate, args, 2);
            }
            roots[stackalloc] = NULL;
            extra -= 1;
        }
    }
    if (arg_heap) {
        // optimization: keep only the first root, free the others
#ifndef __clang_gcanalyzer__
        ((void**)roots)[-2] = (void*)CODE_GC_ENCODE_PUSHARGS(1);
#endif
    }
    code_value_t *result = code_apply(newargs, n);
    CODE_GC_POP();
    return result;
}

CODE_CALLABLE(code_f__apply_iterate)
{
    CODE_NARGSV(_apply_iterate, 2);
    return do_apply(args + 1, nargs - 1, args[0]);
}

// this is like `_apply`, but with quasi-exact checks to make sure it is pure
CODE_CALLABLE(code_f__apply_pure)
{
    code_task_t *ct = code_current_task;
    int last_in = ct->ptls->in_pure_callback;
    code_value_t *ret = NULL;
    CODE_TRY {
        ct->ptls->in_pure_callback = 1;
        // because this function was declared pure,
        // we should be allowed to run it in any world
        // so we run it in the newest world;
        // because, why not :)
        // and `promote` works better this way
        size_t last_age = ct->world_age;
        ct->world_age = code_atomic_load_acquire(&code_world_counter);
        ret = do_apply(args, nargs, NULL);
        ct->world_age = last_age;
        ct->ptls->in_pure_callback = last_in;
    }
    CODE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        code_rethrow();
    }
    return ret;
}

// this is like a regular call, but always runs in the newest world
CODE_CALLABLE(code_f__call_latest)
{
    code_task_t *ct = code_current_task;
    size_t last_age = ct->world_age;
    if (!ct->ptls->in_pure_callback)
        ct->world_age = code_atomic_load_acquire(&code_world_counter);
    code_value_t *ret = code_apply(args, nargs);
    ct->world_age = last_age;
    return ret;
}

// Like call_in_world, but runs in the specified world.
// If world > code_atomic_load_acquire(&code_world_counter), run in the latest world.
CODE_CALLABLE(code_f__call_in_world)
{
    CODE_NARGSV(_apply_in_world, 2);
    code_task_t *ct = code_current_task;
    size_t last_age = ct->world_age;
    CODE_TYPECHK(_apply_in_world, ulong, args[0]);
    size_t world = code_unbox_ulong(args[0]);
    if (!ct->ptls->in_pure_callback) {
        ct->world_age = code_atomic_load_acquire(&code_world_counter);
        if (ct->world_age > world)
            ct->world_age = world;
    }
    code_value_t *ret = code_apply(&args[1], nargs - 1);
    ct->world_age = last_age;
    return ret;
}

CODE_CALLABLE(code_f__call_in_world_total)
{
    CODE_NARGSV(_call_in_world_total, 2);
    CODE_TYPECHK(_apply_in_world, ulong, args[0]);
    code_task_t *ct = code_current_task;
    int last_in = ct->ptls->in_pure_callback;
    code_value_t *ret = NULL;
    size_t last_age = ct->world_age;
    CODE_TRY {
        ct->ptls->in_pure_callback = 1;
        size_t world = code_unbox_ulong(args[0]);
        ct->world_age = code_atomic_load_acquire(&code_world_counter);
        if (ct->world_age > world)
            ct->world_age = world;
        ret = code_apply(&args[1], nargs - 1);
        ct->world_age = last_age;
        ct->ptls->in_pure_callback = last_in;
    }
    CODE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        code_rethrow();
    }
    return ret;
}

// tuples ---------------------------------------------------------------------

CODE_CALLABLE(code_f_tuple)
{
    size_t i;
    if (nargs == 0)
        return (code_value_t*)code_emptytuple;
    code_datatype_t *tt = code_inst_arg_tuple_type(args[0], &args[1], nargs, 0);
    CODE_GC_PROMISE_ROOTED(tt); // it is a concrete type
    if (tt->instance != NULL)
        return tt->instance;
    code_task_t *ct = code_current_task;
    code_value_t *jv = code_gc_alloc(ct->ptls, code_datatype_size(tt), tt);
    for (i = 0; i < nargs; i++)
        set_nth_field(tt, jv, i, args[i], 0);
    return jv;
}

CODE_CALLABLE(code_f_svec)
{
    size_t i;
    if (nargs == 0)
        return (code_value_t*)code_emptysvec;
    code_svec_t *t = code_alloc_svec_uninit(nargs);
    for (i = 0; i < nargs; i++) {
        code_svecset(t, i, args[i]);
    }
    return (code_value_t*)t;
}

// struct operations ------------------------------------------------------------

enum code_memory_order code_get_atomic_order(code_sym_t *order, char loading, char storing)
{
    if (order == code_not_atomic_sym)
        return code_memory_order_notatomic;
    if (order == code_unordered_sym && (loading ^ storing))
        return code_memory_order_unordered;
    if (order == code_monotonic_sym && (loading || storing))
        return code_memory_order_monotonic;
    if (order == code_acquire_sym && loading)
        return code_memory_order_acquire;
    if (order == code_release_sym && storing)
        return code_memory_order_release;
    if (order == code_acquire_release_sym && loading && storing)
        return code_memory_order_acq_rel;
    if (order == code_sequentially_consistent_sym)
        return code_memory_order_seq_cst;
    return code_memory_order_invalid;
}

enum code_memory_order code_get_atomic_order_checked(code_sym_t *order, char loading, char storing)
{
    enum code_memory_order mo = code_get_atomic_order(order, loading, storing);
    if (mo < 0) // invalid
        code_atomic_error("invalid atomic ordering");
    return mo;
}

static inline size_t get_checked_fieldindex(const char *name, code_datatype_t *st, code_value_t *v, code_value_t *arg, int mutabl)
{
    if (mutabl) {
        if (st == code_module_type)
            code_error("cannot assign variables in other modules");
        if (!st->name->mutabl)
            code_errorf("%s: immutable struct of type %s cannot be changed", name, code_symbol_name(st->name->name));
    }
    size_t idx;
    if (code_is_long(arg)) {
        idx = code_unbox_long(arg) - 1;
        if (idx >= code_datatype_nfields(st))
            code_bounds_error(v, arg);
    }
    else if (code_is_symbol(arg)) {
        idx = code_field_index(st, (code_sym_t*)arg, 1);
    }
    else {
        code_value_t *ts[2] = {(code_value_t*)code_long_type, (code_value_t*)code_symbol_type};
        code_value_t *t = code_type_union(ts, 2);
        code_type_error("getfield", t, arg);
    }
    if (mutabl && code_field_isconst(st, idx)) {
        code_errorf("%s: const field .%s of type %s cannot be changed", name,
                code_symbol_name((code_sym_t*)code_svecref(code_field_names(st), idx)), code_symbol_name(st->name->name));
    }
    return idx;
}

CODE_CALLABLE(code_f_getfield)
{
    enum code_memory_order order = code_memory_order_unspecified;
    CODE_NARGS(getfield, 2, 4);
    if (nargs == 4) {
        CODE_TYPECHK(getfield, symbol, args[2]);
        CODE_TYPECHK(getfield, bool, args[3]);
        order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 0);
    }
    else if (nargs == 3) {
        if (!code_is_bool(args[2])) {
            CODE_TYPECHK(getfield, symbol, args[2]);
            order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 0);
        }
    }
    code_value_t *v = args[0];
    code_value_t *vt = code_typeof(v);
    if (vt == (code_value_t*)code_module_type)
        return code_f_getglobal(NULL, args, 2); // we just ignore the atomic order and boundschecks
    code_datatype_t *st = (code_datatype_t*)vt;
    size_t idx = get_checked_fieldindex("getfield", st, v, args[1], 0);
    int isatomic = code_field_isatomic(st, idx);
    if (!isatomic && order != code_memory_order_notatomic && order != code_memory_order_unspecified)
        code_atomic_error("getfield: non-atomic field cannot be accessed atomically");
    if (isatomic && order == code_memory_order_notatomic)
        code_atomic_error("getfield: atomic field cannot be accessed non-atomically");
    if (order >= code_memory_order_seq_cst)
        code_fence();
    v = code_get_nth_field_checked(v, idx); // `v` already had at least consume ordering
    if (order >= code_memory_order_acquire)
        code_fence();
    return v;
}

CODE_CALLABLE(code_f_setfield)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(setfield!, 3, 4);
    if (nargs == 4) {
        CODE_TYPECHK(setfield!, symbol, args[3]);
        order = code_get_atomic_order_checked((code_sym_t*)args[3], 0, 1);
    }
    code_value_t *v = args[0];
    code_datatype_t *st = (code_datatype_t*)code_typeof(v);
    size_t idx = get_checked_fieldindex("setfield!", st, v, args[1], 1);
    int isatomic = !!code_field_isatomic(st, idx);
    if (isatomic == (order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "setfield!: atomic field cannot be written non-atomically"
                                 : "setfield!: non-atomic field cannot be written atomically");
    code_value_t *ft = code_field_type_concrete(st, idx);
    if (!code_isa(args[2], ft))
        code_type_error("setfield!", ft, args[2]);
    if (order >= code_memory_order_release)
        code_fence(); // `st->[idx]` will have at least relaxed ordering
    set_nth_field(st, v, idx, args[2], isatomic);
    return args[2];
}

CODE_CALLABLE(code_f_swapfield)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(swapfield!, 3, 4);
    if (nargs == 4) {
        CODE_TYPECHK(swapfield!, symbol, args[3]);
        order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
    }
    code_value_t *v = args[0];
    code_datatype_t *st = (code_datatype_t*)code_typeof(v);
    size_t idx = get_checked_fieldindex("swapfield!", st, v, args[1], 1);
    int isatomic = !!code_field_isatomic(st, idx);
    if (isatomic == (order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "swapfield!: atomic field cannot be written non-atomically"
                                 : "swapfield!: non-atomic field cannot be written atomically");
    v = swap_nth_field(st, v, idx, args[2], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

CODE_CALLABLE(code_f_modifyfield)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(modifyfield!, 4, 5);
    if (nargs == 5) {
        CODE_TYPECHK(modifyfield!, symbol, args[4]);
        order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 1);
    }
    code_value_t *v = args[0];
    code_datatype_t *st = (code_datatype_t*)code_typeof(v);
    size_t idx = get_checked_fieldindex("modifyfield!", st, v, args[1], 1);
    int isatomic = !!code_field_isatomic(st, idx);
    if (isatomic == (order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "modifyfield!: atomic field cannot be written non-atomically"
                                 : "modifyfield!: non-atomic field cannot be written atomically");
    v = modify_nth_field(st, v, idx, args[2], args[3], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

CODE_CALLABLE(code_f_replacefield)
{
    enum code_memory_order success_order = code_memory_order_notatomic;
    CODE_NARGS(replacefield!, 4, 6);
    if (nargs >= 5) {
        CODE_TYPECHK(replacefield!, symbol, args[4]);
        success_order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 1);
    }
    enum code_memory_order failure_order = success_order;
    if (nargs == 6) {
        CODE_TYPECHK(replacefield!, symbol, args[5]);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[5], 1, 0);
    }
    if (failure_order > success_order)
        code_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    code_value_t *v = args[0];
    code_datatype_t *st = (code_datatype_t*)code_typeof(v);
    size_t idx = get_checked_fieldindex("replacefield!", st, v, args[1], 1);
    int isatomic = !!code_field_isatomic(st, idx);
    if (isatomic == (success_order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "replacefield!: atomic field cannot be written non-atomically"
                                 : "replacefield!: non-atomic field cannot be written atomically");
    if (isatomic == (failure_order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "replacefield!: atomic field cannot be accessed non-atomically"
                                 : "replacefield!: non-atomic field cannot be accessed atomically");
    v = replace_nth_field(st, v, idx, args[2], args[3], isatomic); // always seq_cst, if isatomic needed at all
    return v;
}

CODE_CALLABLE(code_f_setfieldonce)
{
    enum code_memory_order success_order = code_memory_order_notatomic;
    CODE_NARGS(setfieldonce!, 3, 5);
    if (nargs >= 4) {
        CODE_TYPECHK(setfieldonce!, symbol, args[3]);
        success_order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
    }
    enum code_memory_order failure_order = success_order;
    if (nargs == 5) {
        CODE_TYPECHK(setfieldonce!, symbol, args[4]);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 0);
    }
    if (failure_order > success_order)
        code_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    code_value_t *v = args[0];
    code_datatype_t *st = (code_datatype_t*)code_typeof(v);
    size_t idx = get_checked_fieldindex("setfieldonce!", st, v, args[1], 1);
    int isatomic = !!code_field_isatomic(st, idx);
    if (isatomic == (success_order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "setfieldonce!: atomic field cannot be written non-atomically"
                                 : "setfieldonce!: non-atomic field cannot be written atomically");
    if (isatomic == (failure_order == code_memory_order_notatomic))
        code_atomic_error(isatomic ? "setfieldonce!: atomic field cannot be accessed non-atomically"
                                 : "setfieldonce!: non-atomic field cannot be accessed atomically");
    int success = set_nth_fieldonce(st, v, idx, args[2], isatomic); // always seq_cst, if isatomic needed at all
    return success ? code_true : code_false;
}

static code_value_t *get_fieldtype(code_value_t *t, code_value_t *f, int dothrow)
{
    if (code_is_unionall(t)) {
        code_value_t *u = t;
        CODE_GC_PUSH1(&u);
        u = get_fieldtype(((code_unionall_t*)t)->body, f, dothrow);
        u = code_type_unionall(((code_unionall_t*)t)->var, u);
        CODE_GC_POP();
        return u;
    }
    if (code_is_uniontype(t)) {
        code_value_t **u;
        code_value_t *r;
        CODE_GC_PUSHARGS(u, 2);
        u[0] = get_fieldtype(((code_uniontype_t*)t)->a, f, 0);
        u[1] = get_fieldtype(((code_uniontype_t*)t)->b, f, 0);
        if (u[0] == code_bottom_type && u[1] == code_bottom_type && dothrow) {
            // error if all types in the union might have
            get_fieldtype(((code_uniontype_t*)t)->a, f, 1);
            get_fieldtype(((code_uniontype_t*)t)->b, f, 1);
        }
        r = code_type_union(u, 2);
        CODE_GC_POP();
        return r;
    }
    if (!code_is_datatype(t))
        code_type_error("fieldtype", (code_value_t*)code_datatype_type, t);
    code_datatype_t *st = (code_datatype_t*)t;
    int field_index;
    if (code_is_long(f)) {
        field_index = code_unbox_long(f) - 1;
    }
    else {
        CODE_TYPECHK(fieldtype, symbol, f);
        field_index = code_field_index(st, (code_sym_t*)f, dothrow);
        if (field_index == -1)
            return code_bottom_type;
    }
    if (st->name == code_namedtuple_typename) {
        code_value_t *nm = code_tparam0(st);
        if (code_is_tuple(nm)) {
            int nf = code_nfields(nm);
            if (field_index < 0 || field_index >= nf) {
                if (dothrow)
                    code_bounds_error(t, f);
                else
                    return code_bottom_type;
            }
        }
        code_value_t *tt = code_tparam1(st);
        while (code_is_typevar(tt))
            tt = ((code_tvar_t*)tt)->ub;
        if (tt == (code_value_t*)code_any_type)
            return (code_value_t*)code_any_type;
        if (tt == (code_value_t*)code_bottom_type)
            return (code_value_t*)code_bottom_type;
        CODE_GC_PUSH1(&f);
        if (code_is_symbol(f))
            f = code_box_long(field_index+1);
        code_value_t *ft = get_fieldtype(tt, f, dothrow);
        CODE_GC_POP();
        return ft;
    }
    code_svec_t *types = code_get_fieldtypes(st);
    int nf = code_svec_len(types);
    if (nf > 0 && field_index >= nf-1 && st->name == code_tuple_typename) {
        code_value_t *ft = code_field_type(st, nf-1);
        if (code_is_vararg(ft))
            return code_unwrap_vararg(ft);
    }
    if (field_index < 0 || field_index >= nf) {
        if (dothrow)
            code_bounds_error(t, f);
        else
            return code_bottom_type;
    }
    return code_field_type(st, field_index);
}

CODE_CALLABLE(code_f_fieldtype)
{
    CODE_NARGS(fieldtype, 2, 3);
    if (nargs == 3) {
        CODE_TYPECHK(fieldtype, bool, args[2]);
    }
    return get_fieldtype(args[0], args[1], 1);
}

CODE_CALLABLE(code_f_nfields)
{
    CODE_NARGS(nfields, 1, 1);
    code_datatype_t *xt = (code_datatype_t*)code_typeof(args[0]);
    return code_box_long(code_datatype_nfields(xt));
}

CODE_CALLABLE(code_f_isdefined)
{
    code_module_t *m = NULL;
    code_sym_t *s = NULL;
    CODE_NARGS(isdefined, 2, 3);
    enum code_memory_order order = code_memory_order_unspecified;
    if (nargs == 3) {
        CODE_TYPECHK(isdefined, symbol, args[2]);
        order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 0);
    }
    if (code_is_module(args[0])) {
        CODE_TYPECHK(isdefined, symbol, args[1]);
        m = (code_module_t*)args[0];
        s = (code_sym_t*)args[1];
        if (order == code_memory_order_unspecified)
            order = code_memory_order_unordered;
        if (order < code_memory_order_unordered)
            code_atomic_error("isdefined: module binding cannot be accessed non-atomically");
        int bound = code_boundp(m, s); // seq_cst always
        return bound ? code_true : code_false;
    }
    code_datatype_t *vt = (code_datatype_t*)code_typeof(args[0]);
    assert(code_is_datatype(vt));
    size_t idx;
    if (code_is_long(args[1])) {
        idx = code_unbox_long(args[1]) - 1;
        if (idx >= code_datatype_nfields(vt)) {
            if (order != code_memory_order_unspecified)
                code_atomic_error("isdefined: atomic ordering cannot be specified for nonexistent field");
            return code_false;
        }
    }
    else {
        CODE_TYPECHK(isdefined, symbol, args[1]);
        idx = code_field_index(vt, (code_sym_t*)args[1], 0);
        if ((int)idx == -1) {
            if (order != code_memory_order_unspecified)
                code_atomic_error("isdefined: atomic ordering cannot be specified for nonexistent field");
            return code_false;
        }
    }
    int isatomic = code_field_isatomic(vt, idx);
    if (!isatomic && order != code_memory_order_notatomic && order != code_memory_order_unspecified)
        code_atomic_error("isdefined: non-atomic field cannot be accessed atomically");
    if (isatomic && order == code_memory_order_notatomic)
        code_atomic_error("isdefined: atomic field cannot be accessed non-atomically");
    if (order >= code_memory_order_seq_cst)
        code_fence();
    int v = code_field_isdefined(args[0], idx); // relaxed ordering
    if (order >= code_memory_order_acquire)
        code_fence();
    return v ? code_true : code_false;
}


// module bindings

CODE_CALLABLE(code_f_getglobal)
{
    enum code_memory_order order = code_memory_order_monotonic;
    CODE_NARGS(getglobal, 2, 3);
    if (nargs == 3) {
        CODE_TYPECHK(getglobal, symbol, args[2]);
        order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 0);
    }
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *sym = (code_sym_t*)args[1];
    CODE_TYPECHK(getglobal, module, (code_value_t*)mod);
    CODE_TYPECHK(getglobal, symbol, (code_value_t*)sym);
    if (order == code_memory_order_notatomic)
        code_atomic_error("getglobal: module binding cannot be read non-atomically");
    else if (order >= code_memory_order_seq_cst)
        code_fence();
    code_value_t *v = code_eval_global_var(mod, sym); // relaxed load
    if (order >= code_memory_order_acquire)
        code_fence();
    return v;
}

CODE_CALLABLE(code_f_setglobal)
{
    enum code_memory_order order = code_memory_order_release;
    CODE_NARGS(setglobal!, 3, 4);
    if (nargs == 4) {
        CODE_TYPECHK(setglobal!, symbol, args[3]);
        order = code_get_atomic_order_checked((code_sym_t*)args[3], 0, 1);
    }
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(setglobal!, module, (code_value_t*)mod);
    CODE_TYPECHK(setglobal!, symbol, (code_value_t*)var);
    if (order == code_memory_order_notatomic)
        code_atomic_error("setglobal!: module binding cannot be written non-atomically");
    else if (order >= code_memory_order_seq_cst)
        code_fence();
    code_binding_t *b = code_get_binding_wr(mod, var, 0);
    code_checked_assignment(b, mod, var, args[2]); // release store
    if (order >= code_memory_order_seq_cst)
        code_fence();
    return args[2];
}

CODE_CALLABLE(code_f_get_binding_type)
{
    CODE_NARGS(get_binding_type, 2, 2);
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(get_binding_type, module, (code_value_t*)mod);
    CODE_TYPECHK(get_binding_type, symbol, (code_value_t*)var);
    code_value_t *ty = code_get_binding_type(mod, var);
    if (ty == (code_value_t*)code_nothing) {
        code_binding_t *b = code_get_module_binding(mod, var, 0);
        if (b == NULL)
            return (code_value_t*)code_any_type;
        code_binding_t *b2 = code_atomic_load_relaxed(&b->owner);
        if (b2 != b)
            return (code_value_t*)code_any_type;
        code_value_t *old_ty = NULL;
        code_atomic_cmpswap_relaxed(&b->ty, &old_ty, (code_value_t*)code_any_type);
        return code_atomic_load_relaxed(&b->ty);
    }
    return ty;
}

CODE_CALLABLE(code_f_swapglobal)
{
    enum code_memory_order order = code_memory_order_release;
    CODE_NARGS(swapglobal!, 3, 4);
    if (nargs == 4) {
        CODE_TYPECHK(swapglobal!, symbol, args[3]);
        order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
    }
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(swapglobal!, module, (code_value_t*)mod);
    CODE_TYPECHK(swapglobal!, symbol, (code_value_t*)var);
    if (order == code_memory_order_notatomic)
        code_atomic_error("swapglobal!: module binding cannot be written non-atomically");
    // is seq_cst already, no fence needed
    code_binding_t *b = code_get_binding_wr(mod, var, 0);
    return code_checked_swap(b, mod, var, args[2]);
}

CODE_CALLABLE(code_f_modifyglobal)
{
    enum code_memory_order order = code_memory_order_release;
    CODE_NARGS(modifyglobal!, 4, 5);
    if (nargs == 5) {
        CODE_TYPECHK(modifyglobal!, symbol, args[4]);
        order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 1);
    }
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(modifyglobal!, module, (code_value_t*)mod);
    CODE_TYPECHK(modifyglobal!, symbol, (code_value_t*)var);
    if (order == code_memory_order_notatomic)
        code_atomic_error("modifyglobal!: module binding cannot be written non-atomically");
    code_binding_t *b = code_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    return code_checked_modify(b, mod, var, args[2], args[3]);
}

CODE_CALLABLE(code_f_replaceglobal)
{
    enum code_memory_order success_order = code_memory_order_release;
    CODE_NARGS(replaceglobal!, 4, 6);
    if (nargs >= 5) {
        CODE_TYPECHK(replaceglobal!, symbol, args[4]);
        success_order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 1);
    }
    enum code_memory_order failure_order = success_order;
    if (nargs == 6) {
        CODE_TYPECHK(replaceglobal!, symbol, args[5]);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[5], 1, 0);
    }
    if (failure_order > success_order)
        code_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(replaceglobal!, module, (code_value_t*)mod);
    CODE_TYPECHK(replaceglobal!, symbol, (code_value_t*)var);
    if (success_order == code_memory_order_notatomic)
        code_atomic_error("replaceglobal!: module binding cannot be written non-atomically");
    if (failure_order == code_memory_order_notatomic)
        code_atomic_error("replaceglobal!: module binding cannot be accessed non-atomically");
    code_binding_t *b = code_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    return code_checked_replace(b, mod, var, args[2], args[3]);
}

CODE_CALLABLE(code_f_setglobalonce)
{
    enum code_memory_order success_order = code_memory_order_release;
    CODE_NARGS(setglobalonce!, 3, 5);
    if (nargs >= 4) {
        CODE_TYPECHK(setglobalonce!, symbol, args[3]);
        success_order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
    }
    enum code_memory_order failure_order = success_order;
    if (nargs == 5) {
        CODE_TYPECHK(setglobalonce!, symbol, args[4]);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 0);
    }
    if (failure_order > success_order)
        code_atomic_error("invalid atomic ordering");
    // TODO: filter more invalid ordering combinations?
    code_module_t *mod = (code_module_t*)args[0];
    code_sym_t *var = (code_sym_t*)args[1];
    CODE_TYPECHK(setglobalonce!, module, (code_value_t*)mod);
    CODE_TYPECHK(setglobalonce!, symbol, (code_value_t*)var);
    if (success_order == code_memory_order_notatomic)
        code_atomic_error("setglobalonce!: module binding cannot be written non-atomically");
    if (failure_order == code_memory_order_notatomic)
        code_atomic_error("setglobalonce!: module binding cannot be accessed non-atomically");
    code_binding_t *b = code_get_binding_wr(mod, var, 0);
    // is seq_cst already, no fence needed
    code_value_t *old = code_checked_assignonce(b, mod, var, args[2]);
    return old == NULL ? code_true : code_false;
}



// apply_type -----------------------------------------------------------------

static int is_nestable_type_param(code_value_t *t)
{
    if (code_is_namedtuple_type(t))
        t = code_tparam1(t);
    if (code_is_tuple_type(t)) {
        // NOTE: tuples of symbols are not currently bits types, but have been
        // allowed as type parameters. this is a bit ugly.
        size_t i, l = code_nparams(t);
        for (i = 0; i < l; i++) {
            code_value_t *pi = code_tparam(t, i);
            if (!(pi == (code_value_t*)code_symbol_type || code_isbits(pi) || is_nestable_type_param(pi) ||
        code_is_module(pi)))
                return 0;
        }
        return 1;
    }
    return 0;
}

int code_valid_type_param(code_value_t *v)
{
    if (code_is_tuple(v) || code_is_namedtuple(v))
        return is_nestable_type_param(code_typeof(v));
    if (code_is_vararg(v))
        return 0;
    // TODO: maybe more things
    return code_is_type(v) || code_is_typevar(v) || code_is_symbol(v) || code_isbits(code_typeof(v)) ||
        code_is_module(v);
}

CODE_CALLABLE(code_f_apply_type)
{
    CODE_NARGSV(apply_type, 1);
    int i;
    if (args[0] == (code_value_t*)code_anytuple_type) {
        for(i=1; i < nargs; i++) {
            code_value_t *pi = args[i];
            // TODO: should possibly only allow Types and TypeVars, but see
            // https://github.com/CodeLang/code/commit/85f45974a581ab9af955bac600b90d9ab00f093b#commitcomment-13041922
            if (code_is_vararg(pi)) {
                if (i != nargs-1)
                    code_type_error_rt("Tuple", "non-final parameter", (code_value_t*)code_type_type, pi);
            }
            else if (!code_valid_type_param(pi)) {
                code_type_error_rt("Tuple", "parameter", (code_value_t*)code_type_type, pi);
            }
        }
        return code_apply_tuple_type_v(&args[1], nargs-1);
    }
    else if (args[0] == (code_value_t*)code_uniontype_type) {
        // Union{} has extra restrictions, so it needs to be checked after
        // substituting typevars (a valid_type_param check here isn't sufficient).
        return (code_value_t*)code_type_union(&args[1], nargs-1);
    }
    else if (code_is_vararg(args[0])) {
        code_vararg_t *vm = (code_vararg_t*)args[0];
        if (!vm->T) {
            CODE_NARGS(apply_type, 2, 3);
            return (code_value_t*)code_wrap_vararg(args[1], nargs == 3 ? args[2] : NULL, 1, 0);
        }
        else if (!vm->N) {
            CODE_NARGS(apply_type, 2, 2);
            return (code_value_t*)code_wrap_vararg(vm->T, args[1], 1, 0);
        }
    }
    else if (code_is_unionall(args[0])) {
        for(i=1; i < nargs; i++) {
            code_value_t *pi = args[i];
            if (!code_valid_type_param(pi)) {
                code_type_error_rt("Type", "parameter",
                                 code_isa(pi, (code_value_t*)code_number_type) ?
                                 (code_value_t*)code_long_type : (code_value_t*)code_type_type,
                                 pi);
            }
        }
        return code_apply_type(args[0], &args[1], nargs-1);
    }
    code_type_error("Type{...} expression", (code_value_t*)code_unionall_type, args[0]);
}

// generic function reflection ------------------------------------------------

CODE_CALLABLE(code_f_applicable)
{
    CODE_NARGSV(applicable, 1);
    size_t world = code_current_task->world_age;
    return code_method_lookup(args, nargs, world) != NULL ? code_true : code_false;
}

CODE_CALLABLE(code_f_invoke)
{
    CODE_NARGSV(invoke, 2);
    code_value_t *argtypes = args[1];
    CODE_GC_PUSH1(&argtypes);
    if (!code_is_tuple_type(code_unwrap_unionall(args[1])))
        code_type_error("invoke", (code_value_t*)code_anytuple_type_type, args[1]);
    if (!code_tuple_isa(&args[2], nargs - 2, (code_datatype_t*)argtypes))
        code_type_error("invoke: argument type error", argtypes, code_f_tuple(NULL, &args[2], nargs - 2));
    code_value_t *res = code_gf_invoke(argtypes, args[0], &args[2], nargs - 1);
    CODE_GC_POP();
    return res;
}

// Expr constructor for internal use ------------------------------------------

code_expr_t *code_exprn(code_sym_t *head, size_t n)
{
    code_task_t *ct = code_current_task;
    code_array_t *ar = code_alloc_vec_any(n);
    CODE_GC_PUSH1(&ar);
    code_expr_t *ex = (code_expr_t*)code_gc_alloc(ct->ptls, sizeof(code_expr_t),
                                            code_expr_type);
    ex->head = head;
    ex->args = ar;
    CODE_GC_POP();
    return ex;
}

CODE_CALLABLE(code_f__expr)
{
    code_task_t *ct = code_current_task;
    CODE_NARGSV(Expr, 1);
    CODE_TYPECHK(Expr, symbol, args[0]);
    code_array_t *ar = code_alloc_vec_any(nargs-1);
    CODE_GC_PUSH1(&ar);
    for(size_t i=0; i < nargs-1; i++)
        code_array_ptr_set(ar, i, args[i+1]);
    code_expr_t *ex = (code_expr_t*)code_gc_alloc(ct->ptls, sizeof(code_expr_t),
                                            code_expr_type);
    ex->head = (code_sym_t*)args[0];
    ex->args = ar;
    CODE_GC_POP();
    return (code_value_t*)ex;
}

// Typevar constructor for internal use
CODE_DLLEXPORT code_tvar_t *code_new_typevar(code_sym_t *name, code_value_t *lb, code_value_t *ub)
{
    if (lb != code_bottom_type && !code_is_type(lb) && !code_is_typevar(lb))
        code_type_error_rt("TypeVar", "lower bound", (code_value_t *)code_type_type, lb);
    if (ub != (code_value_t *)code_any_type && !code_is_type(ub) && !code_is_typevar(ub))
        code_type_error_rt("TypeVar", "upper bound", (code_value_t *)code_type_type, ub);
    code_task_t *ct = code_current_task;
    code_tvar_t *tv = (code_tvar_t *)code_gc_alloc(ct->ptls, sizeof(code_tvar_t), code_tvar_type);
    code_set_typetagof(tv, code_tvar_tag, 0);
    tv->name = name;
    tv->lb = lb;
    tv->ub = ub;
    return tv;
}

CODE_CALLABLE(code_f__typevar)
{
    CODE_NARGS(TypeVar, 3, 3);
    CODE_TYPECHK(TypeVar, symbol, args[0]);
    return (code_value_t *)code_new_typevar((code_sym_t*)args[0], args[1], args[2]);
}

// genericmemory ---------------------------------------------------------------------

CODE_CALLABLE(code_f_memoryref)
{
    CODE_NARGS(memoryref, 1, 3);
    if (nargs == 1) {
        CODE_TYPECHK(memoryref, genericmemory, args[0]);
        code_genericmemory_t *m = (code_genericmemory_t*)args[0];
        code_value_t *typ = code_apply_type((code_value_t*)code_genericmemoryref_type, code_svec_data(((code_datatype_t*)code_typetagof(m))->parameters), 3);
        CODE_GC_PROMISE_ROOTED(typ); // it is a concrete type
        const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(m))->layout;
        if (layout->flags.arrayelem_isunion || layout->size == 0)
            return (code_value_t*)code_new_memoryref(typ, m, 0);
        return (code_value_t*)code_new_memoryref(typ, m, m->ptr);
    }
    else {
        CODE_TYPECHK(memoryref, genericmemoryref, args[0]);
        CODE_TYPECHK(memoryref, long, args[1]);
        if (nargs == 3)
            CODE_TYPECHK(memoryref, bool, args[2]);
        code_genericmemoryref_t *m = (code_genericmemoryref_t*)args[0];
        size_t i = code_unbox_long(args[1]) - 1;
        const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(m->mem))->layout;
        char *data = (char*)m->ptr_or_offset;
        if (layout->flags.arrayelem_isboxed) {
            if (((data - (char*)m->mem->ptr) / sizeof(code_value_t*)) + i >= m->mem->length)
                code_bounds_error((code_value_t*)m, args[1]);
            data += sizeof(code_value_t*) * i;
        }
        else if (layout->flags.arrayelem_isunion || layout->size == 0) {
            if ((size_t)data + i >= m->mem->length)
                code_bounds_error((code_value_t*)m, args[1]);
            data += i;
        }
        else {
            if (((data - (char*)m->mem->ptr) / layout->size) + i >= m->mem->length)
                code_bounds_error((code_value_t*)m, args[1]);
            data += layout->size * i;
        }
        return (code_value_t*)code_new_memoryref((code_value_t*)code_typetagof(m), m->mem, data);
    }
}

CODE_CALLABLE(code_f_memoryrefoffset)
{
    CODE_NARGS(memoryrefoffset, 1, 1);
    CODE_TYPECHK(memoryref, genericmemoryref, args[0]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(m.mem))->layout;
    size_t offset;
    if (layout->flags.arrayelem_isboxed) {
        offset = (((char*)m.ptr_or_offset - (char*)m.mem->ptr) / sizeof(code_value_t*));
    }
    else if (layout->flags.arrayelem_isunion || layout->size == 0) {
        offset = (size_t)m.ptr_or_offset;
    }
    else {
        offset = ((char*)m.ptr_or_offset - (char*)m.mem->ptr) / layout->size;
    }
    return (code_value_t*)code_box_long(offset + 1);
}

CODE_CALLABLE(code_f_memoryrefget)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefget, 3, 3);
    CODE_TYPECHK(memoryrefget, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefget, symbol, args[1]);
    CODE_TYPECHK(memoryrefget, bool, args[2]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[1] != kind) {
            order = code_get_atomic_order_checked((code_sym_t*)args[1], 1, 0);
            code_atomic_error("memoryrefget: non-atomic memory cannot be accessed atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        order = code_get_atomic_order_checked((code_sym_t*)args[1], 1, 0);
        if (order == code_memory_order_notatomic)
            code_atomic_error("memoryrefget: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    return code_memoryrefget(m, kind == (code_value_t*)code_atomic_sym);
}

CODE_CALLABLE(code_f_memoryrefset)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefset!, 4, 4);
    CODE_TYPECHK(memoryrefset!, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefset!, symbol, args[2]);
    CODE_TYPECHK(memoryrefset!, bool, args[3]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[2] != kind) {
            order = code_get_atomic_order_checked((code_sym_t*)args[2], 0, 1);
            code_atomic_error("memoryrefset!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        order = code_get_atomic_order_checked((code_sym_t*)args[2], 0, 1);
        if (order == code_memory_order_notatomic)
            code_atomic_error("memoryrefset!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    code_memoryrefset(m, args[1], kind == (code_value_t*)code_atomic_sym);
    return args[1];
}

CODE_CALLABLE(code_f_memoryref_isassigned)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(memoryref_isassigned, 3, 3);
    CODE_TYPECHK(memoryref_isassigned, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryref_isassigned, symbol, args[1]);
    CODE_TYPECHK(memoryref_isassigned, bool, args[2]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[1] != kind) {
            order = code_get_atomic_order_checked((code_sym_t*)args[1], 1, 0);
            code_atomic_error("memoryref_isassigned: non-atomic memory cannot be accessed atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        order = code_get_atomic_order_checked((code_sym_t*)args[1], 1, 0);
        if (order == code_memory_order_notatomic)
            code_atomic_error("memoryref_isassigned: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        // TODO(jwn): decide on the fences required for ordering here
        return code_false;
    return code_memoryref_isassigned(m, kind == (code_value_t*)code_atomic_sym);
}

CODE_CALLABLE(code_f_memoryrefswap)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefswap!, 4, 4);
    CODE_TYPECHK(memoryrefswap!, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefswap!, symbol, args[2]);
    CODE_TYPECHK(memoryrefswap!, bool, args[3]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[2] != kind) {
            order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 1);
            code_atomic_error("memoryrefswap!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 1);
        if (order == code_memory_order_notatomic)
            code_atomic_error("memoryrefswap!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    return code_memoryrefswap(m, args[1], kind == (code_value_t*)code_atomic_sym);
}

CODE_CALLABLE(code_f_memoryrefmodify)
{
    enum code_memory_order order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefmodify!, 5, 5);
    CODE_TYPECHK(memoryrefmodify!, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefmodify!, symbol, args[3]);
    CODE_TYPECHK(memoryrefmodify!, bool, args[4]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[3] != kind) {
            order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
            code_atomic_error("memoryrefmodify!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
        if (order == code_memory_order_notatomic)
            code_atomic_error("memoryrefmodify!: atomic memory cannot be written non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    return code_memoryrefmodify(m, args[1], args[2], kind == (code_value_t*)code_atomic_sym);
}

CODE_CALLABLE(code_f_memoryrefreplace)
{
    enum code_memory_order success_order = code_memory_order_notatomic;
    enum code_memory_order failure_order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefreplace!, 6, 6);
    CODE_TYPECHK(memoryrefreplace!, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefreplace!, symbol, args[3]);
    CODE_TYPECHK(memoryrefreplace!, symbol, args[4]);
    CODE_TYPECHK(memoryrefreplace!, bool, args[5]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[4] != kind)
            code_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (args[3] != kind) {
            success_order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
            code_atomic_error("memoryrefreplace!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        success_order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 1);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[4], 1, 0);
        if (failure_order > success_order)
            code_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (success_order == code_memory_order_notatomic)
            code_atomic_error("memoryrefreplace!: atomic memory cannot be written non-atomically");
        if (failure_order == code_memory_order_notatomic)
            code_atomic_error("memoryrefreplace!: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    return code_memoryrefreplace(m, args[1], args[2], kind == (code_value_t*)code_atomic_sym);
}

CODE_CALLABLE(code_f_memoryrefsetonce)
{
    enum code_memory_order success_order = code_memory_order_notatomic;
    enum code_memory_order failure_order = code_memory_order_notatomic;
    CODE_NARGS(memoryrefsetonce!, 5, 5);
    CODE_TYPECHK(memoryrefsetonce!, genericmemoryref, args[0]);
    CODE_TYPECHK(memoryrefsetonce!, symbol, args[2]);
    CODE_TYPECHK(memoryrefsetonce!, symbol, args[3]);
    CODE_TYPECHK(memoryrefsetonce!, bool, args[4]);
    code_genericmemoryref_t m = *(code_genericmemoryref_t*)args[0];
    code_value_t *kind = code_tparam0(code_typetagof(m.mem));
    if (kind == (code_value_t*)code_not_atomic_sym) {
        if (args[3] != kind)
            code_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (args[2] != kind) {
            success_order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 1);
            code_atomic_error("memoryrefsetonce!: non-atomic memory cannot be written atomically");
        }
    }
    else if (kind == (code_value_t*)code_atomic_sym) {
        success_order = code_get_atomic_order_checked((code_sym_t*)args[2], 1, 1);
        failure_order = code_get_atomic_order_checked((code_sym_t*)args[3], 1, 0);
        if (failure_order > success_order)
            code_atomic_error("invalid atomic ordering"); // because either it is invalid, or failure_order > success_order
        if (success_order == code_memory_order_notatomic)
            code_atomic_error("memoryrefsetonce!: atomic memory cannot be written non-atomically");
        if (failure_order == code_memory_order_notatomic)
            code_atomic_error("memoryrefsetonce!: atomic memory cannot be accessed non-atomically");
    }
    if (m.mem->length == 0)
        code_bounds_error_int((code_value_t*)m.mem, 1);
    return code_memoryrefsetonce(m, args[1], kind == (code_value_t*)code_atomic_sym);
}

// type definition ------------------------------------------------------------

CODE_CALLABLE(code_f__structtype)
{
    CODE_NARGS(_structtype, 7, 7);
    CODE_TYPECHK(_structtype, module, args[0]);
    CODE_TYPECHK(_structtype, symbol, args[1]);
    CODE_TYPECHK(_structtype, simplevector, args[2]);
    CODE_TYPECHK(_structtype, simplevector, args[3]);
    CODE_TYPECHK(_structtype, simplevector, args[4]);
    CODE_TYPECHK(_structtype, bool, args[5]);
    CODE_TYPECHK(_structtype, long, args[6]);
    code_value_t *fieldnames = args[3];
    code_value_t *fieldattrs = args[4];
    code_datatype_t *dt = NULL;
    dt = code_new_datatype((code_sym_t*)args[1], (code_module_t*)args[0], NULL, (code_svec_t*)args[2],
                         (code_svec_t*)fieldnames, NULL, (code_svec_t*)fieldattrs,
                         0, args[5]==code_true ? 1 : 0, code_unbox_long(args[6]));
    return dt->name->wrapper;
}

CODE_CALLABLE(code_f__abstracttype)
{
    CODE_NARGS(_abstracttype, 3, 3);
    CODE_TYPECHK(_abstracttype, module, args[0]);
    CODE_TYPECHK(_abstracttype, symbol, args[1]);
    CODE_TYPECHK(_abstracttype, simplevector, args[2]);
    code_datatype_t *dt = code_new_abstracttype(args[1], (code_module_t*)args[0], NULL, (code_svec_t*)args[2]);
    return dt->name->wrapper;
}

CODE_CALLABLE(code_f__primitivetype)
{
    CODE_NARGS(_primitivetype, 4, 4);
    CODE_TYPECHK(_primitivetype, module, args[0]);
    CODE_TYPECHK(_primitivetype, symbol, args[1]);
    CODE_TYPECHK(_primitivetype, simplevector, args[2]);
    code_sym_t *name = (code_sym_t*)args[1];
    code_value_t *vnb = args[3];
    if (!code_is_long(vnb))
        code_errorf("invalid declaration of primitive type %s",
                  code_symbol_name((code_sym_t*)name));
    ssize_t nb = code_unbox_long(vnb);
    if (nb < 1 || nb >= (1 << 23) || (nb & 7) != 0)
        code_errorf("invalid number of bits in primitive type %s",
                  code_symbol_name((code_sym_t*)name));
    code_datatype_t *dt = code_new_primitivetype(args[1], (code_module_t*)args[0], NULL, (code_svec_t*)args[2], nb);
    return dt->name->wrapper;
}

static void code_set_datatype_super(code_datatype_t *tt, code_value_t *super)
{
    const char *error = NULL;
    if (!code_is_datatype(super))
        error = "can only subtype data types";
    else if (tt->super != NULL)
        error = "type already has a supertype";
    else if (tt->name == ((code_datatype_t*)super)->name)
        error = "a type cannot subtype itself";
    else if (code_is_tuple_type(super))
        error = "cannot subtype a tuple type";
    else if (code_is_namedtuple_type(super))
        error = "cannot subtype a named tuple type";
    else if (code_subtype(super, (code_value_t*)code_type_type))
        error = "cannot add subtypes to Type";
    else if (code_subtype(super, (code_value_t*)code_builtin_type))
        error = "cannot add subtypes to Core.Builtin";
    else if (!code_is_abstracttype(super))
        error = "can only subtype abstract types";
    if (error)
         code_errorf("invalid subtyping in definition of %s: %s.", code_symbol_name(tt->name->name), error);
    tt->super = (code_datatype_t*)super;
    code_gc_wb(tt, tt->super);
}

CODE_CALLABLE(code_f__setsuper)
{
    CODE_NARGS(_setsuper!, 2, 2);
    code_datatype_t *dt = (code_datatype_t*)code_unwrap_unionall(args[0]);
    CODE_TYPECHK(_setsuper!, datatype, (code_value_t*)dt);
    code_set_datatype_super(dt, args[1]);
    return code_nothing;
}

CODE_CALLABLE(code_f_donotdelete)
{
    return code_nothing;
}

CODE_CALLABLE(code_f_compilerbarrier)
{
    CODE_NARGS(compilerbarrier, 2, 2);
    CODE_TYPECHK(compilerbarrier, symbol, args[0])
    code_sym_t *setting = (code_sym_t*)args[0];
    if (!(setting == code_symbol("type") ||
          setting == code_symbol("const") ||
          setting == code_symbol("conditional")))
        code_error("The first argument of `compilerbarrier` must be either of `:type`, `:const` or `:conditional`.");
    code_value_t *val = args[1];
    return val;
}

CODE_CALLABLE(code_f_finalizer)
{
    // NOTE the compiler may temporarily insert additional argument for the later inlining pass
    CODE_NARGS(finalizer, 2, 4);
    code_task_t *ct = code_current_task;
    code_gc_add_finalizer_(ct->ptls, args[1], args[0]);
    return code_nothing;
}

CODE_CALLABLE(code_f__compute_sparams)
{
    CODE_NARGSV(_compute_sparams, 1);
    code_method_t *m = (code_method_t*)args[0];
    CODE_TYPECHK(_compute_sparams, method, (code_value_t*)m);
    code_datatype_t *tt = code_inst_arg_tuple_type(args[1], &args[2], nargs-1, 1);
    code_svec_t *env = code_emptysvec;
    CODE_GC_PUSH2(&env, &tt);
    code_type_intersection_env((code_value_t*)tt, m->sig, &env);
    CODE_GC_POP();
    return (code_value_t*)env;
}

CODE_CALLABLE(code_f__svec_ref)
{
    CODE_NARGS(_svec_ref, 2, 2);
    code_svec_t *s = (code_svec_t*)args[0];
    code_value_t *i = (code_value_t*)args[1];
    CODE_TYPECHK(_svec_ref, simplevector, (code_value_t*)s);
    CODE_TYPECHK(_svec_ref, long, i);
    size_t len = code_svec_len(s);
    ssize_t idx = code_unbox_long(i);
    if (idx < 1 || idx > len) {
        code_bounds_error_int((code_value_t*)s, idx);
    }
    return code_svecref(s, idx-1);
}

static int equiv_field_types(code_value_t *old, code_value_t *ft)
{
    size_t nf = code_svec_len(ft);
    if (code_svec_len(old) != nf)
        return 0;
    size_t i;
    for (i = 0; i < nf; i++) {
        code_value_t *ta = code_svecref(old, i);
        code_value_t *tb = code_svecref(ft, i);
        if (code_has_free_typevars(ta)) {
            if (!code_has_free_typevars(tb) || !code_types_egal(ta, tb))
                return 0;
        }
        else if (code_has_free_typevars(tb) || code_typetagof(ta) != code_typetagof(tb) ||
                 !code_types_equal(ta, tb)) {
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
// freevars is a (conservative) analysis of what calling code_has_bound_typevars from name->wrapper gives (TODO: just call this instead?)
static int references_name(code_value_t *p, code_typename_t *name, int affects_layout, int freevars) CODE_NOTSAFEPOINT
{
    if (freevars && !code_has_free_typevars(p))
        freevars = 0;
    while (code_is_unionall(p)) {
        if (references_name((code_value_t*)((code_unionall_t*)p)->var->lb, name, 0, freevars) ||
            references_name((code_value_t*)((code_unionall_t*)p)->var->ub, name, 0, freevars))
            return 1;
       p = ((code_unionall_t*)p)->body;
    }
    if (code_is_uniontype(p)) {
        return references_name(((code_uniontype_t*)p)->a, name, affects_layout, freevars) ||
               references_name(((code_uniontype_t*)p)->b, name, affects_layout, freevars);
    }
    if (code_is_typevar(p))
        return 0; // already checked by unionall, if applicable
    if (code_is_datatype(p)) {
        code_datatype_t *dp = (code_datatype_t*)p;
        if (affects_layout && dp->name == name)
            return 1;
        affects_layout = code_is_genericmemory_type(dp) || ((code_datatype_t*)code_unwrap_unionall(dp->name->wrapper))->layout == NULL;
        // and even if it has a layout, the fields themselves might trigger layouts if they use tparam i
        // rather than checking this for each field, we just assume it applies
        if (!affects_layout && freevars && code_field_names(dp) != code_emptysvec) {
            code_svec_t *types = ((code_datatype_t*)code_unwrap_unionall(dp->name->wrapper))->types;
            size_t i, l = code_svec_len(types);
            for (i = 0; i < l; i++) {
                code_value_t *ft = code_svecref(types, i);
                if (!code_is_typevar(ft) && code_has_free_typevars(ft)) {
                    affects_layout = 1;
                    break;
                }
            }
        }
        size_t i, l = code_nparams(p);
        for (i = 0; i < l; i++) {
            if (references_name(code_tparam(p, i), name, affects_layout, freevars))
                return 1;
        }
    }
    return 0;
}


CODE_CALLABLE(code_f__typebody)
{
    CODE_NARGS(_typebody!, 1, 2);
    code_datatype_t *dt = (code_datatype_t*)code_unwrap_unionall(args[0]);
    CODE_TYPECHK(_typebody!, datatype, (code_value_t*)dt);
    if (nargs == 2) {
        code_value_t *ft = args[1];
        CODE_TYPECHK(_typebody!, simplevector, ft);
        size_t nf = code_svec_len(ft);
        for (size_t i = 0; i < nf; i++) {
            code_value_t *elt = code_svecref(ft, i);
            if (!code_is_type(elt) && !code_is_typevar(elt)) {
                code_type_error_rt(code_symbol_name(dt->name->name),
                                 "type definition",
                                 (code_value_t*)code_type_type, elt);
            }
        }
        if (dt->types != NULL) {
            if (!equiv_field_types((code_value_t*)dt->types, ft))
                code_errorf("invalid redefinition of type %s", code_symbol_name(dt->name->name));
        }
        else {
            dt->types = (code_svec_t*)ft;
            code_gc_wb(dt, ft);
            // If a supertype can reference the same type, then we may not be
            // able to compute the layout of the object before needing to
            // publish it, so we must assume it cannot be inlined, if that
            // check passes, then we also still need to check the fields too.
            if (!dt->name->mutabl && (nf == 0 || !references_name((code_value_t*)dt->super, dt->name, 0, 1))) {
                int mayinlinealloc = 1;
                size_t i;
                for (i = 0; i < nf; i++) {
                    code_value_t *fld = code_svecref(ft, i);
                    if (references_name(fld, dt->name, 1, 1)) {
                        mayinlinealloc = 0;
                        break;
                    }
                }
                dt->name->mayinlinealloc = mayinlinealloc;
            }
        }
    }

    CODE_TRY {
        code_reinstantiate_inner_types(dt);
    }
    CODE_CATCH {
        dt->name->partial = NULL;
        code_rethrow();
    }

    if (code_is_structtype(dt))
        code_compute_field_offsets(dt);
    return code_nothing;
}

// this is a heuristic for allowing "redefining" a type to something identical
static int equiv_type(code_value_t *ta, code_value_t *tb)
{
    code_datatype_t *dta = (code_datatype_t*)code_unwrap_unionall(ta);
    if (!code_is_datatype(dta))
        return 0;
    code_datatype_t *dtb = (code_datatype_t*)code_unwrap_unionall(tb);
    if (!(code_typetagof(dta) == code_typetagof(dtb) &&
          dta->name->name == dtb->name->name &&
          dta->name->abstract == dtb->name->abstract &&
          dta->name->mutabl == dtb->name->mutabl &&
          dta->name->n_uninitialized == dtb->name->n_uninitialized &&
          dta->isprimitivetype == dtb->isprimitivetype &&
          (!dta->isprimitivetype || dta->layout->size == dtb->layout->size) &&
          (dta->name->atomicfields == NULL
           ? dtb->name->atomicfields == NULL
           : (dtb->name->atomicfields != NULL &&
              memcmp(dta->name->atomicfields, dtb->name->atomicfields, (code_svec_len(dta->name->names) + 31) / 32 * sizeof(uint32_t)) == 0)) &&
          (dta->name->constfields == NULL
           ? dtb->name->constfields == NULL
           : (dtb->name->constfields != NULL &&
              memcmp(dta->name->constfields, dtb->name->constfields, (code_svec_len(dta->name->names) + 31) / 32 * sizeof(uint32_t)) == 0)) &&
          code_egal((code_value_t*)code_field_names(dta), (code_value_t*)code_field_names(dtb)) &&
          code_nparams(dta) == code_nparams(dtb)))
        return 0;
    code_value_t *a=NULL, *b=NULL;
    int ok = 1;
    CODE_GC_PUSH2(&a, &b);
    a = code_rewrap_unionall((code_value_t*)dta->super, dta->name->wrapper);
    b = code_rewrap_unionall((code_value_t*)dtb->super, dtb->name->wrapper);
    if (!code_types_equal(a, b))
        goto no;
    CODE_TRY {
        a = code_apply_type(dtb->name->wrapper, code_svec_data(dta->parameters), code_nparams(dta));
    }
    CODE_CATCH {
        ok = 0;
    }
    if (!ok)
        goto no;
    assert(code_is_datatype(a));
    a = dta->name->wrapper;
    b = dtb->name->wrapper;
    while (code_is_unionall(a)) {
        code_unionall_t *ua = (code_unionall_t*)a;
        code_unionall_t *ub = (code_unionall_t*)b;
        if (!code_types_egal(ua->var->lb, ub->var->lb) || !code_types_egal(ua->var->ub, ub->var->ub) ||
            ua->var->name != ub->var->name)
            goto no;
        a = code_instantiate_unionall(ua, (code_value_t*)ub->var);
        b = ub->body;
    }
    CODE_GC_POP();
    return 1;
 no:
    CODE_GC_POP();
    return 0;
}

CODE_CALLABLE(code_f__equiv_typedef)
{
    CODE_NARGS(_equiv_typedef, 2, 2);
    return equiv_type(args[0], args[1]) ? code_true : code_false;
}

// IntrinsicFunctions ---------------------------------------------------------

static void (*runtime_fp[num_intrinsics])(void);
static unsigned intrinsic_nargs[num_intrinsics];

CODE_CALLABLE(code_f_intrinsic_call)
{
    enum intrinsic f = (enum intrinsic)*(uint32_t*)code_data_ptr(F);
    if (f == cglobal && nargs == 1)
        f = cglobal_auto;
    unsigned fargs = intrinsic_nargs[f];
    if (!fargs)
        code_errorf("`%s` requires the compiler", code_intrinsic_name(f));
    CODE_NARGS(intrinsic_call, fargs, fargs);

    union {
        void (*fptr)(void);
        code_value_t *(*call1)(code_value_t*);
        code_value_t *(*call2)(code_value_t*, code_value_t*);
        code_value_t *(*call3)(code_value_t*, code_value_t*, code_value_t*);
        code_value_t *(*call4)(code_value_t*, code_value_t*, code_value_t*, code_value_t*);
        code_value_t *(*call5)(code_value_t*, code_value_t*, code_value_t*, code_value_t*, code_value_t*);
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
    code_gc_debug_critical_error();
    abort();
}

CODE_DLLEXPORT const char *code_intrinsic_name(int f)
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

unsigned code_intrinsic_nargs(int f)
{
    return intrinsic_nargs[f];
}

// init -----------------------------------------------------------------------

static void add_intrinsic_properties(enum intrinsic f, unsigned nargs, void (*pfunc)(void))
{
    assert(nargs <= 5 && "code_f_intrinsic_call only implements up to 5 args");
    intrinsic_nargs[f] = nargs;
    runtime_fp[f] = pfunc;
}

static void add_intrinsic(code_module_t *inm, const char *name, enum intrinsic f) CODE_GC_DISABLED
{
    code_value_t *i = code_permbox32(code_intrinsic_type, 0, (int32_t)f);
    code_sym_t *sym = code_symbol(name);
    code_set_const(inm, sym, i);
    code_module_public(inm, sym, 1);
}

void code_init_intrinsic_properties(void) CODE_GC_DISABLED
{
#define ADD_I(name, nargs) add_intrinsic_properties(name, nargs, (void(*)(void))&code_##name);
#define ADD_HIDDEN ADD_I
#define ALIAS(alias, base) add_intrinsic_properties(alias, intrinsic_nargs[base], runtime_fp[base]);
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
}

void code_init_intrinsic_functions(void) CODE_GC_DISABLED
{
    code_module_t *inm = code_new_module(code_symbol("Intrinsics"), NULL);
    inm->parent = code_core_module;
    code_set_const(code_core_module, code_symbol("Intrinsics"), (code_value_t*)inm);
    code_mk_builtin_func(code_intrinsic_type, "IntrinsicFunction", code_f_intrinsic_call);
    code_mk_builtin_func(
        (code_datatype_t*)code_unwrap_unionall((code_value_t*)code_opaque_closure_type),
        "OpaqueClosure", code_f_opaque_closure_call);

    // Save a reference to the just created OpaqueClosure method, so we can provide special
    // codegen for it later.
    code_opaque_closure_method = (code_method_t*)code_methtable_lookup(code_opaque_closure_typename->mt,
        (code_value_t*)code_anytuple_type, 1);

#define ADD_I(name, nargs) add_intrinsic(inm, #name, name);
#define ADD_HIDDEN(name, nargs)
#define ALIAS ADD_I
    INTRINSICS
#undef ADD_I
#undef ADD_HIDDEN
#undef ALIAS
}

static void add_builtin(const char *name, code_value_t *v)
{
    code_set_const(code_core_module, code_symbol(name), v);
}

code_fptr_args_t code_get_builtin_fptr(code_datatype_t *dt)
{
    assert(code_subtype((code_value_t*)dt, (code_value_t*)code_builtin_type));
    code_typemap_entry_t *entry = (code_typemap_entry_t*)code_atomic_load_relaxed(&dt->name->mt->defs);
    code_method_instance_t *mi = code_atomic_load_relaxed(&entry->func.method->unspecialized);
    code_code_instance_t *ci = code_atomic_load_relaxed(&mi->cache);
    assert(ci->owner == code_nothing);
    return code_atomic_load_relaxed(&ci->specptr.fptr1);
}

static code_value_t *add_builtin_func(const char *name, code_fptr_args_t fptr)
{
    return code_mk_builtin_func(NULL, name, fptr)->instance;
}

void code_init_primitives(void) CODE_GC_DISABLED
{
    code_builtin_is = add_builtin_func("===", code_f_is);
    code_builtin_typeof = add_builtin_func("typeof", code_f_typeof);
    code_builtin_sizeof = add_builtin_func("sizeof", code_f_sizeof);
    code_builtin_issubtype = add_builtin_func("<:", code_f_issubtype);
    code_builtin_isa = add_builtin_func("isa", code_f_isa);
    code_builtin_typeassert = add_builtin_func("typeassert", code_f_typeassert);
    code_builtin_throw = add_builtin_func("throw", code_f_throw);
    code_builtin_tuple = add_builtin_func("tuple", code_f_tuple);
    code_builtin_ifelse = add_builtin_func("ifelse", code_f_ifelse);

    // field access
    code_builtin_getfield = add_builtin_func("getfield",  code_f_getfield);
    code_builtin_setfield = add_builtin_func("setfield!",  code_f_setfield);
    code_builtin_setfieldonce = add_builtin_func("setfieldonce!",  code_f_setfieldonce);
    code_builtin_swapfield = add_builtin_func("swapfield!",  code_f_swapfield);
    code_builtin_modifyfield = add_builtin_func("modifyfield!",  code_f_modifyfield);
    code_builtin_replacefield = add_builtin_func("replacefield!",  code_f_replacefield);
    code_builtin_fieldtype = add_builtin_func("fieldtype", code_f_fieldtype);
    code_builtin_nfields = add_builtin_func("nfields", code_f_nfields);
    code_builtin_isdefined = add_builtin_func("isdefined", code_f_isdefined);

    // module bindings
    code_builtin_getglobal = add_builtin_func("getglobal", code_f_getglobal);
    code_builtin_setglobal = add_builtin_func("setglobal!", code_f_setglobal);
    add_builtin_func("get_binding_type", code_f_get_binding_type);
    code_builtin_swapglobal = add_builtin_func("swapglobal!", code_f_swapglobal);
    code_builtin_replaceglobal = add_builtin_func("replaceglobal!", code_f_replaceglobal);
    code_builtin_modifyglobal = add_builtin_func("modifyglobal!", code_f_modifyglobal);
    code_builtin_setglobalonce = add_builtin_func("setglobalonce!", code_f_setglobalonce);

    // memory primitives
    code_builtin_memoryref = add_builtin_func("memoryrefnew", code_f_memoryref);
    code_builtin_memoryrefoffset = add_builtin_func("memoryrefoffset", code_f_memoryrefoffset);
    code_builtin_memoryrefget = add_builtin_func("memoryrefget", code_f_memoryrefget);
    code_builtin_memoryrefset = add_builtin_func("memoryrefset!", code_f_memoryrefset);
    code_builtin_memoryref_isassigned = add_builtin_func("memoryref_isassigned", code_f_memoryref_isassigned);
    code_builtin_memoryrefswap = add_builtin_func("memoryrefswap!", code_f_memoryrefswap);
    code_builtin_memoryrefreplace = add_builtin_func("memoryrefreplace!", code_f_memoryrefreplace);
    code_builtin_memoryrefmodify = add_builtin_func("memoryrefmodify!", code_f_memoryrefmodify);
    code_builtin_memoryrefsetonce = add_builtin_func("memoryrefsetonce!", code_f_memoryrefsetonce);

    // method table utils
    code_builtin_applicable = add_builtin_func("applicable", code_f_applicable);
    code_builtin_invoke = add_builtin_func("invoke", code_f_invoke);

    // internal functions
    code_builtin_apply_type = add_builtin_func("apply_type", code_f_apply_type);
    code_builtin__apply_iterate = add_builtin_func("_apply_iterate", code_f__apply_iterate);
    code_builtin__expr = add_builtin_func("_expr", code_f__expr);
    code_builtin_svec = add_builtin_func("svec", code_f_svec);
    add_builtin_func("_apply_pure", code_f__apply_pure);
    add_builtin_func("_call_latest", code_f__call_latest);
    add_builtin_func("_call_in_world", code_f__call_in_world);
    add_builtin_func("_call_in_world_total", code_f__call_in_world_total);
    add_builtin_func("_typevar", code_f__typevar);
    add_builtin_func("_structtype", code_f__structtype);
    add_builtin_func("_abstracttype", code_f__abstracttype);
    add_builtin_func("_primitivetype", code_f__primitivetype);
    add_builtin_func("_setsuper!", code_f__setsuper);
    code_builtin__typebody = add_builtin_func("_typebody!", code_f__typebody);
    add_builtin_func("_equiv_typedef", code_f__equiv_typedef);
    code_builtin_donotdelete = add_builtin_func("donotdelete", code_f_donotdelete);
    code_builtin_compilerbarrier = add_builtin_func("compilerbarrier", code_f_compilerbarrier);
    add_builtin_func("finalizer", code_f_finalizer);
    add_builtin_func("_compute_sparams", code_f__compute_sparams);
    add_builtin_func("_svec_ref", code_f__svec_ref);
    add_builtin_func("current_scope", code_f_current_scope);

    // builtin types
    add_builtin("Any", (code_value_t*)code_any_type);
    add_builtin("Type", (code_value_t*)code_type_type);
    add_builtin("Nothing", (code_value_t*)code_nothing_type);
    add_builtin("nothing", (code_value_t*)code_nothing);
    add_builtin("TypeName", (code_value_t*)code_typename_type);
    add_builtin("DataType", (code_value_t*)code_datatype_type);
    add_builtin("TypeVar", (code_value_t*)code_tvar_type);
    add_builtin("UnionAll", (code_value_t*)code_unionall_type);
    add_builtin("Union", (code_value_t*)code_uniontype_type);
    add_builtin("TypeofBottom", (code_value_t*)code_typeofbottom_type);
    add_builtin("Tuple", (code_value_t*)code_anytuple_type);
    add_builtin("TypeofVararg", (code_value_t*)code_vararg_type);
    add_builtin("SimpleVector", (code_value_t*)code_simplevector_type);
    add_builtin("Vararg", (code_value_t*)code_wrap_vararg(NULL, NULL, 0, 0));

    add_builtin("Module", (code_value_t*)code_module_type);
    add_builtin("MethodTable", (code_value_t*)code_methtable_type);
    add_builtin("Method", (code_value_t*)code_method_type);
    add_builtin("CodeInstance", (code_value_t*)code_code_instance_type);
    add_builtin("TypeMapEntry", (code_value_t*)code_typemap_entry_type);
    add_builtin("TypeMapLevel", (code_value_t*)code_typemap_level_type);
    add_builtin("Symbol", (code_value_t*)code_symbol_type);
    add_builtin("SSAValue", (code_value_t*)code_ssavalue_type);
    add_builtin("SlotNumber", (code_value_t*)code_slotnumber_type);
    add_builtin("Argument", (code_value_t*)code_argument_type);
    add_builtin("Const", (code_value_t*)code_const_type);
    add_builtin("PartialStruct", (code_value_t*)code_partial_struct_type);
    add_builtin("PartialOpaque", (code_value_t*)code_partial_opaque_type);
    add_builtin("InterConditional", (code_value_t*)code_interconditional_type);
    add_builtin("MethodMatch", (code_value_t*)code_method_match_type);
    add_builtin("IntrinsicFunction", (code_value_t*)code_intrinsic_type);
    add_builtin("Function", (code_value_t*)code_function_type);
    add_builtin("Builtin", (code_value_t*)code_builtin_type);
    add_builtin("MethodInstance", (code_value_t*)code_method_instance_type);
    add_builtin("CodeInfo", (code_value_t*)code_code_info_type);
    add_builtin("LLVMPtr", (code_value_t*)code_llvmpointer_type);
    add_builtin("Task", (code_value_t*)code_task_type);
    add_builtin("OpaqueClosure", (code_value_t*)code_opaque_closure_type);

    add_builtin("AddrSpace", (code_value_t*)code_addrspace_type);
    add_builtin("Ref", (code_value_t*)code_ref_type);
    add_builtin("Ptr", (code_value_t*)code_pointer_type);
    //add_builtin("GenericPtr", (code_value_t*)code_genericpointer_type);
    add_builtin("AbstractArray", (code_value_t*)code_abstractarray_type);
    add_builtin("DenseArray", (code_value_t*)code_densearray_type);
    add_builtin("Array", (code_value_t*)code_array_type);
    add_builtin("GenericMemory", (code_value_t*)code_genericmemory_type);
    add_builtin("GenericMemoryRef", (code_value_t*)code_genericmemoryref_type);

    add_builtin("Expr", (code_value_t*)code_expr_type);
    add_builtin("LineNumberNode", (code_value_t*)code_linenumbernode_type);
    add_builtin("LegacyLineInfoNode", (code_value_t*)code_lineinfonode_type);
    add_builtin("DebugInfo", (code_value_t*)code_debuginfo_type);
    add_builtin("GotoNode", (code_value_t*)code_gotonode_type);
    add_builtin("GotoIfNot", (code_value_t*)code_gotoifnot_type);
    add_builtin("EnterNode", (code_value_t*)code_enternode_type);
    add_builtin("ReturnNode", (code_value_t*)code_returnnode_type);
    add_builtin("PiNode", (code_value_t*)code_pinode_type);
    add_builtin("PhiNode", (code_value_t*)code_phinode_type);
    add_builtin("PhiCNode", (code_value_t*)code_phicnode_type);
    add_builtin("UpsilonNode", (code_value_t*)code_upsilonnode_type);
    add_builtin("QuoteNode", (code_value_t*)code_quotenode_type);
    add_builtin("NewvarNode", (code_value_t*)code_newvarnode_type);
    add_builtin("Binding", (code_value_t*)code_binding_type);
    add_builtin("GlobalRef", (code_value_t*)code_globalref_type);
    add_builtin("NamedTuple", (code_value_t*)code_namedtuple_type);

    add_builtin("Bool", (code_value_t*)code_bool_type);
    add_builtin("UInt8", (code_value_t*)code_uint8_type);
    add_builtin("UInt16", (code_value_t*)code_uint16_type);
    add_builtin("UInt32", (code_value_t*)code_uint32_type);
    add_builtin("UInt64", (code_value_t*)code_uint64_type);
    add_builtin("Int32", (code_value_t*)code_int32_type);
    add_builtin("Int64", (code_value_t*)code_int64_type);
#ifdef _P64
    add_builtin("Int", (code_value_t*)code_int64_type);
#else
    add_builtin("Int", (code_value_t*)code_int32_type);
#endif

    add_builtin("AbstractString", (code_value_t*)code_abstractstring_type);
    add_builtin("String", (code_value_t*)code_string_type);
}

#ifdef __cplusplus
}
#endif
