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

#include <stdlib.h>
#include <string.h>
#include "code.h"
#include "language_internal.h"
#ifndef _OS_WINDOWS_
#include <unistd.h>
#endif
#include "language_assert.h"

#define MAX_METHLIST_COUNT 6 // this helps configure the sysimg size and speed.

#ifdef __cplusplus
extern "C" {
#endif

// compute whether the specificity of this type is equivalent to Any in the sort order
static int language_is_any(language_value_t *t1)
{
    while (language_is_typevar(t1))
        t1 = ((language_tvar_t*)t1)->ub;
    return t1 == (language_value_t*)language_any_type;
}

static language_value_t *language_type_extract_name(language_value_t *t1 LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_unionall(t1))
        t1 = language_unwrap_unionall(t1);
    if (language_is_vararg(t1)) {
        return language_type_extract_name(language_unwrap_vararg(t1));
    }
    else if (language_is_typevar(t1)) {
        return language_type_extract_name(((language_tvar_t*)t1)->ub);
    }
    else if (t1 == language_bottom_type || t1 == (language_value_t*)language_typeofbottom_type || t1 == (language_value_t*)language_typeofbottom_type->super) {
        return (language_value_t*)language_typeofbottom_type->name; // put Union{} and typeof(Union{}) and Type{Union{}} together for convenience
    }
    else if (language_is_datatype(t1)) {
        language_datatype_t *dt = (language_datatype_t*)t1;
        if (!language_is_kind(t1))
            return (language_value_t*)dt->name;
        return NULL;
    }
    else if (language_is_uniontype(t1)) {
        language_uniontype_t *u1 = (language_uniontype_t*)t1;
        language_value_t *tn1 = language_type_extract_name(u1->a);
        language_value_t *tn2 = language_type_extract_name(u1->b);
        if (tn1 == tn2)
            return tn1;
        // TODO: if invariant is false, instead find the nearest common ancestor
        return NULL;
    }
    return NULL;
}

// return false if the name extracted above is an over-approximation
// (such that intersection also needs to consider the subtypes)
static int language_type_extract_name_precise(language_value_t *t1, int invariant)
{
    if (language_is_unionall(t1))
        t1 = language_unwrap_unionall(t1);
    if (language_is_vararg(t1)) {
        return language_type_extract_name_precise(language_unwrap_vararg(t1), invariant);
    }
    else if (language_is_typevar(t1)) {
        return language_type_extract_name_precise(((language_tvar_t*)t1)->ub, 0);
    }
    else if (t1 == language_bottom_type || t1 == (language_value_t*)language_typeofbottom_type || t1 == (language_value_t*)language_typeofbottom_type->super) {
        return 1;
    }
    else if (language_is_datatype(t1)) {
        language_datatype_t *dt = (language_datatype_t*)t1;
        if ((invariant || !dt->name->abstract) && !language_is_kind(t1))
            return 1;
        return 0;
    }
    else if (language_is_uniontype(t1)) {
        language_uniontype_t *u1 = (language_uniontype_t*)t1;
        if (!language_type_extract_name_precise(u1->a, invariant))
            return 0;
        if (!language_type_extract_name_precise(u1->b, invariant))
            return 0;
        language_value_t *tn1 = language_type_extract_name(u1->a);
        language_value_t *tn2 = language_type_extract_name(u1->b);
        if (tn1 == tn2)
            return 1;
        return 0;
    }
    return 1;
}

// return whether Type{Union{}} is a subtype of Type{t1} (which may have free typevars)
static int language_parameter_includes_bottom(language_value_t *t1)
{
    if (language_is_typevar(t1) || t1 == language_bottom_type)
        return 1;
    else if (language_is_uniontype(t1)) {
        language_uniontype_t *u1 = (language_uniontype_t*)t1;
        return language_parameter_includes_bottom(u1->a) && language_parameter_includes_bottom(u1->b);
    }
    return 0;
}


// ----- Type Signature Subtype Testing ----- //

static int sig_match_by_type_leaf(language_value_t **types, language_tupletype_t *sig, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        language_value_t *decl = language_tparam(sig, i);
        language_value_t *a = types[i];
        if (language_is_type_type(a)) // decl is not Type, because it wouldn't be leafsig
            a = language_typeof(language_tparam0(a));
        if (!language_types_equal(a, decl))
            return 0;
    }
    return 1;
}

static int sig_match_by_type_simple(language_value_t **types, size_t n, language_tupletype_t *sig, size_t lensig, int va)
{
    size_t i;
    if (va) lensig -= 1;
    for (i = 0; i < lensig; i++) {
        language_value_t *decl = language_tparam(sig, i);
        language_value_t *a = types[i];
        language_value_t *unw = language_is_unionall(decl) ? ((language_unionall_t*)decl)->body : decl;
        if (language_is_vararg(a))
            return 0;
        if (language_is_type_type(unw)) {
            language_value_t *tp0 = language_tparam0(unw);
            if (language_is_type_type(a)) {
                if (language_is_typevar(tp0)) {
                    // in the case of Type{_}, the types don't have to match exactly.
                    // this is cached as `Type{T} where T`.
                    if (((language_tvar_t*)tp0)->ub != (language_value_t*)language_any_type &&
                        !language_subtype(language_tparam0(a), ((language_tvar_t*)tp0)->ub))
                        return 0;
                }
                else if (!language_types_equal(language_tparam0(a), tp0)) {
                    return 0;
                }
            }
            else if (!language_is_kind(a) || !language_is_typevar(tp0) || ((language_tvar_t*)tp0)->ub != (language_value_t*)language_any_type) {
                // manually unroll language_subtype(a, decl)
                // where `a` can be a subtype and decl is Type{T}
                return 0;
            }
        }
        else if (decl == (language_value_t*)language_any_type) {
        }
        else {
            if (language_is_type_type(a)) // decl is not Type, because it would be caught above
                a = language_typeof(language_tparam0(a));
            if (!language_types_equal(a, decl))
                return 0;
        }
    }
    if (va) {
        language_value_t *decl = language_unwrap_unionall(language_tparam(sig, i));
        if (language_vararg_kind(decl) == LANGUAGE_VARARG_INT) {
            if (n - i != language_unbox_long(language_tparam1(decl)))
                return 0;
        }
        language_value_t *t = language_unwrap_vararg(decl);
        if (language_is_typevar(t))
            t = ((language_tvar_t*)t)->ub;
        for (; i < n; i++) {
            language_value_t *ti = types[i];
            if (i == n - 1 && language_is_vararg(ti))
                ti = language_unwrap_vararg(ti);
            if (!language_subtype(ti, t))
                return 0;
        }
        return 1;
    }
    return 1;
}

static inline int sig_match_leaf(language_value_t *arg1, language_value_t **args, language_value_t **sig, size_t n)
{
    // NOTE: This function is a huge performance hot spot!!
    size_t i;
    if (language_typeof(arg1) != sig[0])
        return 0;
    for (i = 1; i < n; i++) {
        language_value_t *decl = sig[i];
        language_value_t *a = args[i - 1];
        if (language_typeof(a) != decl) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            return 0;
        }
    }
    return 1;
}

static inline int sig_match_simple(language_value_t *arg1, language_value_t **args, size_t n, language_value_t **sig,
                                   int va, size_t lensig)
{
    // NOTE: This function is a performance hot spot!!
    size_t i;
    if (va)
        lensig -= 1;
    for (i = 0; i < lensig; i++) {
        language_value_t *decl = sig[i];
        language_value_t *a = (i == 0 ? arg1 : args[i - 1]);
        if (language_typeof(a) == decl || decl == (language_value_t*)language_any_type) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            continue;
        }
        language_value_t *unw = language_is_unionall(decl) ? ((language_unionall_t*)decl)->body : decl;
        if (language_is_type_type(unw) && language_is_type(a)) {
            language_value_t *tp0 = language_tparam0(unw);
            if (language_is_typevar(tp0)) {
                // in the case of Type{_}, the types don't have to match exactly.
                // this is cached as `Type{T} where T`.
                if (((language_tvar_t*)tp0)->ub != (language_value_t*)language_any_type &&
                    !language_subtype(a, ((language_tvar_t*)tp0)->ub))
                    return 0;
            }
            else {
                if (a != tp0) {
                    language_datatype_t *da = (language_datatype_t*)a;
                    language_datatype_t *dt = (language_datatype_t*)tp0;
                    while (language_is_unionall(da))
                        da = (language_datatype_t*)((language_unionall_t*)da)->body;
                    while (language_is_unionall(dt))
                        dt = (language_datatype_t*)((language_unionall_t*)dt)->body;
                    if (language_is_datatype(da) && language_is_datatype(dt) && da->name != dt->name)
                        return 0;
                    if (!language_types_equal(a, tp0))
                        return 0;
                }
            }
        }
        else {
            return 0;
        }
    }
    if (va) {
        language_value_t *decl = sig[i];
        if (language_vararg_kind(decl) == LANGUAGE_VARARG_INT) {
            if (n - i != language_unbox_long(language_tparam1(decl)))
                return 0;
        }
        language_value_t *t = language_unwrap_vararg(decl);
        for (; i < n; i++) {
            language_value_t *a = (i == 0 ? arg1 : args[i - 1]);
            if (!language_isa(a, t))
                return 0;
        }
        return 1;
    }
    return 1;
}


// ----- MethodCache helper functions ----- //

// predicate to fast-test if this type is a leaf type that can exist in the cache
// and does not need a more expensive linear scan to find all intersections
// we try not to put non-leaf types or DataType/UnionAll/Union in the
// argument cache, since they should have a lower priority and so will go in some
// later list
static int is_cache_leaf(language_value_t *ty, int tparam)
{
    if (ty == language_bottom_type)
        return 1;
    return (language_is_concrete_type(ty) && (tparam || !language_is_kind(ty)));
}

static _Atomic(language_value_t*) *mtcache_hash_lookup_bp(language_genericmemory_t *cache LANGUAGE_PROPAGATES_ROOT, language_value_t *ty) LANGUAGE_NOTSAFEPOINT
{
    if (cache == (language_genericmemory_t*)language_an_empty_memory_any)
        return NULL;
    _Atomic(language_value_t*) *pml = language_table_peek_bp(cache, ty);
    LANGUAGE_GC_PROMISE_ROOTED(pml); // clang-sa doesn't trust our LANGUAGE_PROPAGATES_ROOT claim
    return pml;
}

static void mtcache_hash_insert(_Atomic(language_genericmemory_t*) *cache, language_value_t *parent, language_value_t *key, language_typemap_t *val)
{
    int inserted = 0;
    language_genericmemory_t *a = language_atomic_load_relaxed(cache);
    if (a == (language_genericmemory_t*)language_an_empty_memory_any) {
        a = language_alloc_memory_any(16);
        language_atomic_store_release(cache, a);
        if (parent)
            language_gc_wb(parent, a);
    }
    a = language_eqtable_put(a, key, val, &inserted);
    assert(inserted);
    if (a != language_atomic_load_relaxed(cache)) {
        language_atomic_store_release(cache, a);
        if (parent)
            language_gc_wb(parent, a);
    }
}

static language_typemap_t *mtcache_hash_lookup(language_genericmemory_t *cache LANGUAGE_PROPAGATES_ROOT, language_value_t *ty) LANGUAGE_NOTSAFEPOINT
{
    if (cache == (language_genericmemory_t*)language_an_empty_memory_any)
        return (language_typemap_t*)language_nothing;
    language_typemap_t *ml = (language_typemap_t*)language_eqtable_get(cache, ty, language_nothing);
    return ml;
}

// ----- Sorted Type Signature Lookup Matching ----- //

static int language_typemap_memory_visitor(language_genericmemory_t *a, language_typemap_visitor_fptr fptr, void *closure)
{
    size_t i, l = a->length;
    _Atomic(language_typemap_t*) *data = (_Atomic(language_typemap_t*)*) a->ptr;
    for (i = 1; i < l; i += 2) {
        language_value_t *d = language_atomic_load_relaxed(&data[i]);
        LANGUAGE_GC_PROMISE_ROOTED(d);
        if (d == NULL)
            continue;
        if (language_is_genericmemory(d)) {
            if (!language_typemap_memory_visitor((language_genericmemory_t*)d, fptr, closure))
                return 0;
        }
        else {
            if (!language_typemap_visitor(d, fptr, closure))
                return 0;
        }
    }
    return 1;
}


// calls fptr on each language_typemap_entry_t in cache in sort order, until fptr return false
static int language_typemap_node_visitor(language_typemap_entry_t *ml, language_typemap_visitor_fptr fptr, void *closure)
{
    while (ml != (void*)language_nothing) {
        if (!fptr(ml, closure))
            return 0;
        ml = language_atomic_load_relaxed(&ml->next);
    }
    return 1;
}

int language_typemap_visitor(language_typemap_t *cache, language_typemap_visitor_fptr fptr, void *closure)
{
    if (language_typeof(cache) == (language_value_t*)language_typemap_level_type) {
        language_typemap_level_t *node = (language_typemap_level_t*)cache;
        language_genericmemory_t *a;
        LANGUAGE_GC_PUSH1(&a);
        a = language_atomic_load_relaxed(&node->targ);
        if (a != (language_genericmemory_t*)language_an_empty_memory_any)
            if (!language_typemap_memory_visitor(a, fptr, closure))
                goto exit;
        a = language_atomic_load_relaxed(&node->arg1);
        if (a != (language_genericmemory_t*)language_an_empty_memory_any)
            if (!language_typemap_memory_visitor(a, fptr, closure))
                goto exit;
        a = language_atomic_load_relaxed(&node->tname);
        if (a != (language_genericmemory_t*)language_an_empty_memory_any)
            if (!language_typemap_memory_visitor(a, fptr, closure))
                goto exit;
        a = language_atomic_load_relaxed(&node->name1);
        if (a != (language_genericmemory_t*)language_an_empty_memory_any)
            if (!language_typemap_memory_visitor(a, fptr, closure))
                goto exit;
        if (!language_typemap_node_visitor(language_atomic_load_relaxed(&node->linear), fptr, closure))
            goto exit;
        if (!language_typemap_visitor(language_atomic_load_relaxed(&node->any), fptr, closure))
            goto exit;
        LANGUAGE_GC_POP();
        return 1;
exit:
        LANGUAGE_GC_POP();
        return 0;
    }
    else {
        return language_typemap_node_visitor((language_typemap_entry_t*)cache, fptr, closure);
    }
}

static unsigned language_supertype_height(language_datatype_t *dt) LANGUAGE_NOTSAFEPOINT
{
    unsigned height = 1;
    while (dt != language_any_type) {
        height++;
        dt = dt->super;
    }
    return height;
}

// return true if a and b might intersect in the type domain (over just their type-names)
static int tname_intersection_dt(language_datatype_t *a, language_typename_t *bname, unsigned ha) LANGUAGE_NOTSAFEPOINT
{
    if (a == language_any_type)
        return 1;
    language_datatype_t *b = (language_datatype_t*)language_unwrap_unionall(bname->wrapper);
    unsigned hb = 1;
    while (b != language_any_type) {
        if (a->name == b->name)
            return 1;
        hb++;
        b = b->super;
    }
    while (ha > hb) {
        a = a->super;
        ha--;
    }
    return a->name == bname;
}

static int tname_intersection(language_value_t *a, language_typename_t *bname, int8_t tparam) LANGUAGE_NOTSAFEPOINT
{
    if (a == (language_value_t*)language_any_type)
        return 1;
    a = language_unwrap_unionall(a);
    assert(!language_is_vararg(a));
    if (language_is_uniontype(a))
        return tname_intersection(((language_uniontype_t*)a)->a, bname, tparam) ||
               tname_intersection(((language_uniontype_t*)a)->b, bname, tparam);
    if (language_is_typevar(a))
        return tname_intersection(((language_tvar_t*)a)->ub, bname, tparam);
    if (language_is_datatype(a)) {
        if (tparam) {
            if (!language_is_type_type(a))
                return 0;
            a = language_unwrap_unionall(language_tparam0(a));
            if (!language_is_datatype(a))
                return tname_intersection(a, bname, 0);
        }
        return tname_intersection_dt((language_datatype_t*)a, bname, language_supertype_height((language_datatype_t*)a));
    }
    return 0;
}

static int concrete_intersects(language_value_t *t, language_value_t *ty, int8_t tparam)
{
    if (ty == (language_value_t*)language_any_type) // easy case: Any always matches
        return 1;
    if (tparam & 1)
        return language_isa(t, ty); // (Type{t} <: ty), where is_leaf_type(t) => isa(t, ty)
    else
        return t == ty || language_subtype(t, ty);
}

// tparam bit 0 is ::Type{T} (vs. T)
// tparam bit 1 is typename(T) (vs. T)
static int language_typemap_intersection_memory_visitor(language_genericmemory_t *a, language_value_t *ty, int8_t tparam,
                                                 int8_t offs, struct typemap_intersection_env *closure)
{
    LANGUAGE_GC_PUSH1(&a);
    size_t i, l = a->length;
    _Atomic(language_typemap_t*) *data = (_Atomic(language_typemap_t*)*) a->ptr;
    unsigned height = 0;
    language_datatype_t *tydt = language_any_type;
    if (tparam & 2) {
        // try to extract a description of ty for intersections, but since we
        language_value_t *ttype = language_unwrap_unionall(ty);
        if (tparam & 1)
            // extract T from Type{T} (if possible)
            ttype = language_is_type_type(ttype) ? language_tparam0(ttype) : NULL;
        if (ttype && language_is_datatype(ttype)) {
            tydt = (language_datatype_t*)ttype;
        }
        else if (ttype) {
            ttype = language_type_extract_name(ttype);
            tydt = ttype ? (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)ttype)->wrapper) : NULL;
        }
        if (tydt == language_any_type)
            ty = (language_value_t*)language_any_type;
        else if (tydt == NULL)
            tydt = language_any_type;
        else
            height = language_supertype_height(tydt);
    }
    for (i = 0; i < l; i += 2) {
        language_value_t *t = language_atomic_load_relaxed(&data[i]);
        LANGUAGE_GC_PROMISE_ROOTED(t);
        if (t == language_nothing || t == NULL)
            continue;
        if (tparam & 2) {
            language_typemap_t *ml = language_atomic_load_relaxed(&data[i + 1]);
            LANGUAGE_GC_PROMISE_ROOTED(ml);
            if (tydt == language_any_type ?
                    tname_intersection(ty, (language_typename_t*)t, tparam & 1) :
                    tname_intersection_dt(tydt, (language_typename_t*)t, height)) {
                if ((tparam & 1) && t == (language_value_t*)language_typeofbottom_type->name) // skip Type{Union{}} and Type{typeof(Union{})}, since the caller should have already handled those
                    continue;
                if (language_is_genericmemory(ml)) {
                    if (!language_typemap_intersection_memory_visitor((language_genericmemory_t*)ml, ty, tparam & ~2, offs, closure))
                        goto exit;
                }
                else {
                    if (!language_typemap_intersection_visitor(ml, offs + 1, closure))
                        goto exit;
                }
            }
        }
        else {
            // `t` is a leaftype, so intersection test becomes subtype (after excluding kinds)
            if (concrete_intersects(t, ty, tparam)) {
                language_typemap_t *ml = language_atomic_load_relaxed(&data[i + 1]);
                LANGUAGE_GC_PROMISE_ROOTED(ml);
                // NOTE: ml might be NULL if we're racing with the thread that's inserting the item
                if (ml != NULL && !language_typemap_intersection_visitor(ml, offs + 1, closure))
                    goto exit;
            }
        }
    }
    LANGUAGE_GC_POP();
    return 1;

exit:
    LANGUAGE_GC_POP();
    return 0;
}


// calls fptr on each language_typemap_entry_t in cache in sort order
// for which type ∩ ml->type != Union{}, until fptr return false
static int language_typemap_intersection_node_visitor(language_typemap_entry_t *ml, struct typemap_intersection_env *closure)
{
    // slow-path scan everything in ml
    // mark this `register` because (for branch prediction)
    // that can be absolutely critical for speed
    register language_typemap_intersection_visitor_fptr fptr = closure->fptr;
    for (;  ml != (void*)language_nothing; ml = language_atomic_load_relaxed(&ml->next)) {
        if (closure->max_valid < language_atomic_load_relaxed(&ml->min_world))
            continue;
        if (closure->min_valid > language_atomic_load_relaxed(&ml->max_world))
            continue;
        language_svec_t **penv = NULL;
        if (closure->env) {
            closure->env = language_emptysvec;
            penv = &closure->env;
        }
        closure->ti = language_type_intersection_env_s(closure->type, (language_value_t*)ml->sig, penv, &closure->issubty);
        if (closure->ti != (language_value_t*)language_bottom_type) {
            // In some corner cases type intersection is conservative and returns something
            // for intersect(A, B) even though A is a dispatch tuple and !(A <: B).
            // For dispatch purposes in such a case we know there's no match. This check
            // fixes issue #30394.
            if (closure->issubty || !language_is_dispatch_tupletype(closure->type))
                if (!fptr(ml, closure))
                    return 0;
        }
    }
    return 1;
}

int language_has_intersect_type_not_kind(language_value_t *t);
int language_has_intersect_kind_not_type(language_value_t *t);

// if TypeVar tv is used covariantly, it cannot be Union{}
int has_covariant_var(language_datatype_t *ttypes, language_tvar_t *tv)
{
    size_t i, l = language_nparams(ttypes);
    for (i = 0; i < l; i++)
        if (language_tparam(ttypes, i) == (language_value_t*)tv)
            return 1;
    return 0;
}

void typemap_slurp_search(language_typemap_entry_t *ml, struct typemap_intersection_env *closure)
{
    // n.b. we could consider mt->max_args here too, so this optimization
    //      usually works even if the user forgets the `slurp...` argument, but
    //      there is discussion that parameter may be going away? (and it is
    //      already not accurately up-to-date for all tables currently anyways)
    if (closure->search_slurp && ml->va) {
        language_value_t *sig = language_unwrap_unionall((language_value_t*)ml->sig);
        size_t nargs = language_nparams(sig);
        if (nargs > 1 && nargs - 1 == closure->search_slurp) {
            language_vararg_t *va = (language_vararg_t*)language_tparam(sig, nargs - 1);
            assert(language_is_vararg((language_value_t*)va));
            if (va->T == (language_value_t*)language_any_type && va->N == NULL) {
                // instruct typemap it can set exclude_typeofbottom on parameter nargs
                // since we found the necessary slurp argument
                closure->search_slurp = 0;
            }
        }
    }
}

int language_typemap_intersection_visitor(language_typemap_t *map, int offs,
                                    struct typemap_intersection_env *closure)
{
    language_value_t *ttypes = language_unwrap_unionall(closure->type);
    assert(language_is_datatype(ttypes));
    //TODO: fast-path for leaf-type tuples?
    //if (ttypes->isdispatchtuple) {
    //    register language_typemap_intersection_visitor_fptr fptr = closure->fptr;
    //    struct language_typemap_assoc search = {(language_value_t*)closure->type, world, closure->env, 0, ~(size_t)0};
    //    language_typemap_entry_t *ml = language_typemap_assoc_by_type(map, search, offs, /*subtype*/1);
    //    if (ml) {
    //        closure->env = search->env;
    //        if (!fptr(ml, closure))
    //            return 0;
    //    }
    //    return 1;
    //}
    if (language_typeof(map) == (language_value_t *)language_typemap_level_type) {
        language_typemap_level_t *cache = (language_typemap_level_t*)map;
        language_value_t *ty;
        size_t l = language_nparams(ttypes);
        if (closure->va && l <= offs + 1) {
            ty = closure->va;
        }
        else if (l > offs) {
            ty = language_tparam(ttypes, offs);
        }
        else {
            ty = NULL;
        }
        if (ty == (language_value_t*)language_typeofbottom_type)
            ty = (language_value_t*)language_assume(language_typeofbottom_type)->super;
        if (ty) {
            while (language_is_typevar(ty))
                ty = ((language_tvar_t*)ty)->ub;
            // approxify the tparam until we have a valid type
            if (language_has_free_typevars(ty))
                ty = language_rewrap_unionall(ty, closure->type);
            LANGUAGE_GC_PUSH1(&ty);
            language_genericmemory_t *targ = language_atomic_load_relaxed(&cache->targ);
            language_genericmemory_t *tname = language_atomic_load_relaxed(&cache->tname);
            int maybe_type = 0;
            int maybe_kind = 0;
            int exclude_typeofbottom = 0;
            language_value_t *typetype = NULL;
            language_value_t *name = NULL;
            // pre-check: optimized pre-intersection test to see if `ty` could intersect with any Type or Kind
            if (targ != (language_genericmemory_t*)language_an_empty_memory_any || tname != (language_genericmemory_t*)language_an_empty_memory_any) {
                maybe_kind = language_has_intersect_kind_not_type(ty);
                maybe_type = maybe_kind || language_has_intersect_type_not_kind(ty);
                if (maybe_type && !maybe_kind) {
                    typetype = language_unwrap_unionall(ty);
                    typetype = language_is_type_type(typetype) ? language_tparam0(typetype) : NULL;
                    name = typetype ? language_type_extract_name(typetype) : NULL;
                    if (!typetype)
                        exclude_typeofbottom = !language_subtype((language_value_t*)language_typeofbottom_type, ty);
                    else if (language_is_typevar(typetype))
                        exclude_typeofbottom = has_covariant_var((language_datatype_t*)ttypes, (language_tvar_t*)typetype);
                    else
                        exclude_typeofbottom = !language_parameter_includes_bottom(typetype);
                }
            }
            // First check for intersections with methods defined on Type{T}, where T was a concrete type
            if (targ != (language_genericmemory_t*)language_an_empty_memory_any && maybe_type &&
                    (!typetype || language_has_free_typevars(typetype) || is_cache_leaf(typetype, 1))) { // otherwise cannot contain this particular kind, so don't bother with checking
                if (!exclude_typeofbottom) {
                    // detect Type{Union{}}, Type{Type{Union{}}}, and Type{typeof(Union{}} and do those early here
                    // otherwise the possibility of encountering `Type{Union{}}` in this intersection may
                    // be forcing us to do some extra work here whenever we see a typevar, even though
                    // the likelihood of that value actually occurring is frequently likely to be
                    // zero (or result in an ambiguous match)
                    targ = language_atomic_load_relaxed(&cache->targ); // may be GC'd during type-intersection
                    language_value_t *ml = mtcache_hash_lookup(targ, (language_value_t*)language_typeofbottom_type->name);
                    if (ml != language_nothing) {
                        size_t search_slurp = closure->search_slurp;
                        closure->search_slurp = offs + 1;
                        if (!language_typemap_intersection_visitor((language_typemap_t*)ml, offs+1, closure)) {
                            closure->search_slurp = search_slurp;
                            LANGUAGE_GC_POP();
                            return 0;
                        }
                        if (closure->search_slurp == 0)
                            exclude_typeofbottom = 1;
                        closure->search_slurp = search_slurp;
                    }
                }
                if (name != (language_value_t*)language_typeofbottom_type->name) {
                    targ = language_atomic_load_relaxed(&cache->targ); // may be GC'd earlier
                    if (exclude_typeofbottom && name && language_type_extract_name_precise(typetype, 1)) {
                        // attempt semi-direct lookup of types via their names
                        // consider the type name first
                        language_value_t *ml = mtcache_hash_lookup(targ, (language_value_t*)name);
                        if (language_is_genericmemory(ml)) {
                            if (typetype && !language_has_free_typevars(typetype)) {
                                // direct lookup of leaf types
                                if (is_cache_leaf(typetype, 1)) {
                                    ml = mtcache_hash_lookup((language_genericmemory_t*)ml, typetype);
                                    if (ml != language_nothing) {
                                        if (!language_typemap_intersection_visitor((language_typemap_t*)ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                                    }
                                }
                            }
                            else {
                                if (!language_typemap_intersection_memory_visitor((language_genericmemory_t*)ml, ty, 1, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                            }
                        }
                        else if (ml != language_nothing) {
                            if (!language_typemap_intersection_visitor((language_typemap_t*)ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                        }
                    }
                    else {
                        // else a scan is required to consider all the possible subtypes
                        if (!language_typemap_intersection_memory_visitor(targ, exclude_typeofbottom && !maybe_kind ? ty : (language_value_t*)language_any_type, 3, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                    }
                }
            }
            language_genericmemory_t *cachearg1 = language_atomic_load_relaxed(&cache->arg1);
            if (cachearg1 != (language_genericmemory_t*)language_an_empty_memory_any) {
                if (is_cache_leaf(ty, 0)) {
                    language_typename_t *name = ty == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)ty)->name;
                    // direct lookup of leaf types
                    language_value_t *ml = mtcache_hash_lookup(cachearg1, (language_value_t*)name);
                    if (language_is_genericmemory(ml))
                        ml = mtcache_hash_lookup((language_genericmemory_t*)ml, ty);
                    if (ml != language_nothing) {
                        if (!language_typemap_intersection_visitor(ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                    }
                }
                else {
                    language_value_t *name = language_type_extract_name(ty);
                    if (name && language_type_extract_name_precise(ty, 0)) {
                        // direct lookup of leaf types
                        language_value_t *ml = mtcache_hash_lookup(cachearg1, name);
                        if (language_is_genericmemory(ml)) {
                            if (!language_typemap_intersection_memory_visitor((language_genericmemory_t*)ml, ty, 0, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                        }
                        else {
                            if (!language_typemap_intersection_visitor((language_typemap_t*)ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                        }
                    }
                    else {
                        // else a scan is required to check subtypes
                        if (!language_typemap_intersection_memory_visitor(cachearg1, ty, 2, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                    }
                }
            }
            // Next check for intersections with methods defined on Type{T}, where T was not concrete (it might even have been a TypeVar), but had an extractable TypeName
            if (tname != (language_genericmemory_t*)language_an_empty_memory_any && maybe_type) {
                if (!exclude_typeofbottom || (!typetype && language_isa((language_value_t*)language_typeofbottom_type, ty))) {
                    // detect Type{Union{}}, Type{Type{Union{}}}, and Type{typeof(Union{}} and do those early here
                    // otherwise the possibility of encountering `Type{Union{}}` in this intersection may
                    // be forcing us to do some extra work here whenever we see a typevar, even though
                    // the likelihood of that value actually occurring is frequently likely to be
                    // zero (or result in an ambiguous match)
                    tname = language_atomic_load_relaxed(&cache->tname);  // may be GC'd earlier
                    language_value_t *ml = mtcache_hash_lookup(tname, (language_value_t*)language_typeofbottom_type->name);
                    if (ml != language_nothing) {
                        size_t search_slurp = closure->search_slurp;
                        closure->search_slurp = offs + 1;
                        if (!language_typemap_intersection_visitor((language_typemap_t*)ml, offs+1, closure)) {
                            closure->search_slurp = search_slurp;
                            LANGUAGE_GC_POP();
                            return 0;
                        }
                        if (closure->search_slurp == 0)
                            exclude_typeofbottom = 1;
                        closure->search_slurp = search_slurp;
                    }
                }
                if (exclude_typeofbottom && name && language_type_extract_name_precise(typetype, 1)) {
                    // semi-direct lookup of types
                    // just consider the type and its direct super types
                    language_datatype_t *super = (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)name)->wrapper);
                    if (super->name == language_typeofbottom_type->name)
                        super = super->super; // this was handled above
                    while (1) {
                        tname = language_atomic_load_relaxed(&cache->tname); // reload after callback
                        language_typemap_t *ml = mtcache_hash_lookup(tname, (language_value_t*)super->name);
                        if (ml != language_nothing) {
                            if (!language_typemap_intersection_visitor(ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                        }
                        if (super == language_any_type)
                            break;
                        super = super->super;
                    }
                }
                else {
                    // else a scan is required to check subtypes of typetype too
                    tname = language_atomic_load_relaxed(&cache->tname);  // may be GC'd earlier
                    if (!language_typemap_intersection_memory_visitor(tname, exclude_typeofbottom && !maybe_kind ? ty : (language_value_t*)language_any_type, 3, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                }
            }
            language_genericmemory_t *name1 = language_atomic_load_relaxed(&cache->name1);
            if (name1 != (language_genericmemory_t*)language_an_empty_memory_any) {
                language_value_t *name = language_type_extract_name(ty);
                if (name && language_type_extract_name_precise(ty, 0)) {
                    language_datatype_t *super = (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)name)->wrapper);
                    // direct lookup of concrete types
                    while (1) {
                        name1 = language_atomic_load_relaxed(&cache->name1); // reload after callback
                        language_typemap_t *ml = mtcache_hash_lookup(name1, (language_value_t*)super->name);
                        if (ml != language_nothing) {
                            if (!language_typemap_intersection_visitor(ml, offs+1, closure)) { LANGUAGE_GC_POP(); return 0; }
                        }
                        if (super == language_any_type)
                            break;
                        super = super->super;
                    }
                }
                else {
                    // else a scan is required to check subtypes
                    if (!language_typemap_intersection_memory_visitor(name1, ty, 2, offs, closure)) { LANGUAGE_GC_POP(); return 0; }
                }
            }
            LANGUAGE_GC_POP();
        }
        if (!language_typemap_intersection_node_visitor(language_atomic_load_relaxed(&cache->linear), closure))
            return 0;
        return language_typemap_intersection_visitor(language_atomic_load_relaxed(&cache->any), offs+1, closure);
    }
    else {
        return language_typemap_intersection_node_visitor(
            (language_typemap_entry_t*)map, closure);
    }
}


/*
  Method caches are divided into three parts: one for signatures where
  the first argument is a singleton kind (Type{Foo}), one indexed by the
  UID of the first argument's type in normal cases, and a fallback
  table of everything else.

  Note that the "primary key" is the type of the first *argument*, since
  there tends to be lots of variation there. The type of the 0th argument
  (the function) is always the same for most functions.
*/
static language_typemap_entry_t *language_typemap_entry_assoc_by_type(
        language_typemap_entry_t *ml,
        struct language_typemap_assoc *search)
{
    language_value_t *types = search->types;
    LANGUAGE_GC_PROMISE_ROOTED(types);
    language_value_t *unw = language_unwrap_unionall((language_value_t*)types);
    int isua = language_is_unionall(types);
    size_t n = language_nparams(unw);
    int typesisva = n == 0 ? 0 : language_is_vararg(language_tparam(unw, n-1));
    for (; ml != (void*)language_nothing; ml = language_atomic_load_relaxed(&ml->next)) {
        if (search->world < language_atomic_load_relaxed(&ml->min_world) || search->world > language_atomic_load_relaxed(&ml->max_world))
            continue;
        size_t lensig = language_nparams(language_unwrap_unionall((language_value_t*)ml->sig));
        if (lensig == n || (ml->va && lensig <= n+1)) {
            int resetenv = 0, ismatch = 1;
            if (ml->simplesig != (void*)language_nothing && !isua) {
                size_t lensimplesig = language_nparams(ml->simplesig);
                int isva = lensimplesig > 0 && language_is_vararg(language_tparam(ml->simplesig, lensimplesig - 1));
                if (lensig == n || (isva && lensimplesig <= n + 1))
                    ismatch = sig_match_by_type_simple(language_svec_data(((language_datatype_t*)types)->parameters), n,
                                                       ml->simplesig, lensimplesig, isva);
                else
                    ismatch = 0;
            }

            if (ismatch == 0)
                ; // nothing
            else if (ml->isleafsig && !typesisva && !isua)
                ismatch = sig_match_by_type_leaf(language_svec_data(((language_datatype_t*)types)->parameters),
                                                 ml->sig, lensig);
            else if (ml->issimplesig && !typesisva && !isua)
                ismatch = sig_match_by_type_simple(language_svec_data(((language_datatype_t*)types)->parameters), n,
                                                   ml->sig, lensig, ml->va);
            else {
                ismatch = language_subtype_matching(types, (language_value_t*)ml->sig, search->env ? &search->env : NULL);
                if (ismatch && search->env)
                    resetenv = 1;
            }

            if (ismatch) {
                size_t i, l;
                for (i = 0, l = language_svec_len(ml->guardsigs); i < l; i++) {
                    // see corresponding code in language_typemap_entry_assoc_exact
                    if (language_subtype(types, language_svecref(ml->guardsigs, i))) {
                        ismatch = 0;
                        break;
                    }
                }
                if (ismatch) {
                    return ml;
                }
            }
            if (resetenv)
                search->env = language_emptysvec;
        }
    }
    return NULL;
}

static language_typemap_entry_t *language_typemap_entry_lookup_by_type(
        language_typemap_entry_t *ml, struct language_typemap_assoc *search)
{
    for (; ml != (void*)language_nothing; ml = language_atomic_load_relaxed(&ml->next)) {
        if (search->world < language_atomic_load_relaxed(&ml->min_world) || search->world > language_atomic_load_relaxed(&ml->max_world))
            continue;
        // unroll the first few cases here, to the extent that is possible to do fast and easily
        language_value_t *types = search->types;
        LANGUAGE_GC_PROMISE_ROOTED(types);
        language_value_t *a = language_unwrap_unionall(types);
        language_value_t *b = language_unwrap_unionall((language_value_t*)ml->sig);
        size_t na = language_nparams(a);
        size_t nb = language_nparams(b);
        int va_a = na > 0 && language_is_vararg(language_tparam(a, na - 1));
        int va_b = nb > 0 && language_is_vararg(language_tparam(b, nb - 1));
        if (!va_a && !va_b) {
            if (na != nb)
                continue;
        }
        if (na - va_a > 0 && nb - va_b > 0) {
            if (language_obviously_unequal(language_tparam(a, 0), language_tparam(b, 0)))
                continue;
            if (na - va_a > 1 && nb - va_b > 1) {
                if (language_obviously_unequal(language_tparam(a, 1), language_tparam(b, 1)))
                    continue;
                if (na - va_a > 2 && nb - va_b > 2) {
                    if (language_obviously_unequal(language_tparam(a, 2), language_tparam(b, 2)))
                        continue;
                }
            }
        }
        if (language_types_equal(types, (language_value_t*)ml->sig))
            return ml;
    }
    return NULL;
}


// this is the general entry point for looking up a type in the cache
// as a subtype, or with type_equal
language_typemap_entry_t *language_typemap_assoc_by_type(
        language_typemap_t *ml_or_cache,
        struct language_typemap_assoc *search,
        int8_t offs, uint8_t subtype)
{
    if (language_typeof(ml_or_cache) == (language_value_t *)language_typemap_level_type) {
        language_typemap_level_t *cache = (language_typemap_level_t*)ml_or_cache;
        // called object is the primary key for constructors, otherwise first argument
        language_value_t *ty;
        language_value_t *ttypes = language_unwrap_unionall((language_value_t*)search->types);
        LANGUAGE_GC_PROMISE_ROOTED(ttypes);
        assert(language_is_datatype(ttypes));
        size_t l = language_nparams(ttypes);
        int isva = 0;
        // compute the type at offset `offs` into `types`, which may be a Vararg
        if (l <= offs + 1) {
            ty = language_tparam(ttypes, l - 1);
            if (language_is_vararg(ty)) {
                ty = language_unwrap_vararg(ty);
                isva = 1;
            }
            else if (l <= offs) {
                ty = NULL;
            }
        }
        else if (l > offs) {
            ty = language_tparam(ttypes, offs);
        }
        else {
            ty = NULL;
        }
        if (ty == (language_value_t*)language_typeofbottom_type)
            ty = (language_value_t*)language_assume(language_typeofbottom_type)->super;
        // If there is a type at offs, look in the optimized leaf type caches
        if (ty && !subtype) {
            if (language_is_any(ty))
                return language_typemap_assoc_by_type(language_atomic_load_relaxed(&cache->any), search, offs + 1, subtype);
            if (isva) // in lookup mode, want to match Vararg exactly, not as a subtype
                ty = NULL;
        }
        if (ty) {
            // now look at the optimized leaftype caches
            if (language_is_type_type(ty)) {
                language_value_t *a0 = language_tparam0(ty);
                if (is_cache_leaf(a0, 1)) {
                    language_genericmemory_t *targ = language_atomic_load_relaxed(&cache->targ);
                    if (targ != (language_genericmemory_t*)language_an_empty_memory_any) {
                        language_typename_t *name = a0 == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)a0)->name;
                        language_value_t *ml = mtcache_hash_lookup(targ, (language_value_t*)name);
                        if (language_is_genericmemory(ml))
                            ml = mtcache_hash_lookup((language_genericmemory_t*)ml, a0);
                        if (ml != language_nothing) {
                            language_typemap_entry_t *li = language_typemap_assoc_by_type((language_typemap_t*)ml, search, offs + 1, subtype);
                            if (li) return li;
                        }
                    }
                    if (!subtype) return NULL;
                }
            }
            if (is_cache_leaf(ty, 0)) {
                language_genericmemory_t *cachearg1 = language_atomic_load_relaxed(&cache->arg1);
                if (cachearg1 != (language_genericmemory_t*)language_an_empty_memory_any) {
                    language_typename_t *name = ty == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)ty)->name;
                    language_value_t *ml = mtcache_hash_lookup(cachearg1, (language_value_t*)name);
                    if (language_is_genericmemory(ml))
                        ml = mtcache_hash_lookup((language_genericmemory_t*)ml, ty);
                    if (ml != language_nothing) {
                        language_typemap_entry_t *li = language_typemap_assoc_by_type((language_typemap_t*)ml, search, offs + 1, subtype);
                        if (li) return li;
                    }
                }
                if (!subtype) return NULL;
            }
        }
        if (ty || subtype) {
            // now look at the optimized TypeName caches
            language_genericmemory_t *tname = language_atomic_load_relaxed(&cache->tname);
            if (tname != (language_genericmemory_t*)language_an_empty_memory_any) {
                language_value_t *a0 = ty && language_is_type_type(ty) ? language_type_extract_name(language_tparam0(ty)) : NULL;
                if (a0) { // TODO: if we start analyzing Union types in language_type_extract_name, then a0 might be over-approximated here, leading us to miss possible subtypes
                    language_datatype_t *super = (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)a0)->wrapper);
                    while (1) {
                        tname = language_atomic_load_relaxed(&cache->tname); // reload after tree descent (which may hit safepoints)
                        language_typemap_t *ml = mtcache_hash_lookup(tname, (language_value_t*)super->name);
                        if (ml != (void*)language_nothing) {
                            language_typemap_entry_t *li = language_typemap_assoc_by_type(ml, search, offs + 1, subtype);
                            if (li) return li;
                        }
                        if (super == language_any_type || !subtype)
                            break;
                        super = super->super;
                    }
                }
                else {
                    if (!ty || !language_has_empty_intersection((language_value_t*)language_type_type, ty)) {
                        language_genericmemory_t *tname = language_atomic_load_relaxed(&cache->tname); // reload after type-intersect
                        // couldn't figure out unique `a0` initial point, so scan all for matches
                        size_t i, l = tname->length;
                        _Atomic(language_typemap_t*) *data = (_Atomic(language_typemap_t*)*) language_genericmemory_ptr_data(tname);
                        LANGUAGE_GC_PUSH1(&tname);
                        for (i = 1; i < l; i += 2) {
                            language_typemap_t *ml = language_atomic_load_relaxed(&data[i]);
                            if (ml == NULL || ml == language_nothing)
                                continue;
                            language_typemap_entry_t *li = language_typemap_assoc_by_type(ml, search, offs + 1, subtype);
                            if (li) {
                                LANGUAGE_GC_POP();
                                return li;
                            }
                        }
                        LANGUAGE_GC_POP();
                    }
                }
            }
            language_genericmemory_t *name1 = language_atomic_load_relaxed(&cache->name1);
            if (name1 != (language_genericmemory_t*)language_an_empty_memory_any) {
                if (ty) {
                    language_value_t *a0 = language_type_extract_name(ty);
                    if (a0) { // TODO: if we start analyzing Union types in language_type_extract_name, then a0 might be over-approximated here, leading us to miss possible subtypes
                        language_datatype_t *super = (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)a0)->wrapper);
                        while (1) {
                            name1 = language_atomic_load_relaxed(&cache->name1); // reload after tree descent (which may hit safepoints)
                            language_typemap_t *ml = mtcache_hash_lookup(name1, (language_value_t*)super->name);
                            if (ml != (void*)language_nothing) {
                                language_typemap_entry_t *li =
                                    language_typemap_assoc_by_type(ml, search, offs + 1, subtype);
                                if (li) return li;
                            }
                            if (super == language_any_type || !subtype)
                                break;
                            super = super->super;
                        }
                    }
                }
                else {
                    // doing subtype, but couldn't figure out unique `ty`, so scan all for supertypes
                    size_t i, l = name1->length;
                    _Atomic(language_typemap_t*) *data = (_Atomic(language_typemap_t*)*) language_genericmemory_ptr_data(name1);
                    LANGUAGE_GC_PUSH1(&name1);
                    for (i = 1; i < l; i += 2) {
                        language_typemap_t *ml = language_atomic_load_relaxed(&data[i]);
                        if (ml == NULL || ml == language_nothing)
                            continue;
                        language_typemap_entry_t *li = language_typemap_assoc_by_type(ml, search, offs + 1, subtype);
                        if (li) {
                            LANGUAGE_GC_POP();
                            return li;
                        }
                    }
                    LANGUAGE_GC_POP();
                }
            }
        }
        // Always check the list (since offs doesn't always start at 0)
        if (subtype) {
            language_typemap_entry_t *li = language_typemap_entry_assoc_by_type(language_atomic_load_relaxed(&cache->linear), search);
            if (li) return li;
            return language_typemap_assoc_by_type(language_atomic_load_relaxed(&cache->any), search, offs + 1, subtype);
        }
        else {
            return language_typemap_entry_lookup_by_type(language_atomic_load_relaxed(&cache->linear), search);
        }
    }
    else {
        language_typemap_entry_t *leaf = (language_typemap_entry_t*)ml_or_cache;
        return subtype ?
            language_typemap_entry_assoc_by_type(leaf, search) :
            language_typemap_entry_lookup_by_type(leaf, search);
    }
}

language_typemap_entry_t *language_typemap_entry_assoc_exact(language_typemap_entry_t *ml, language_value_t *arg1, language_value_t **args, size_t n, size_t world)
{
    // some manually-unrolled common special cases
    while (ml->simplesig == (void*)language_nothing && ml->guardsigs == language_emptysvec && ml->isleafsig) {
        // use a tight loop for as long as possible
        if (world >= language_atomic_load_relaxed(&ml->min_world) && world <= language_atomic_load_relaxed(&ml->max_world)) {
            if (n == language_nparams(ml->sig) && language_typeof(arg1) == language_tparam(ml->sig, 0)) {
                if (n == 1)
                    return ml;
                if (n == 2) {
                    if (language_typeof(args[0]) == language_tparam(ml->sig, 1))
                        return ml;
                }
                else if (n == 3) {
                    if (language_typeof(args[0]) == language_tparam(ml->sig, 1) &&
                        language_typeof(args[1]) == language_tparam(ml->sig, 2))
                        return ml;
                }
                else {
                    if (sig_match_leaf(arg1, args, language_svec_data(ml->sig->parameters), n))
                        return ml;
                }
            }
        }
        ml = language_atomic_load_relaxed(&ml->next);
        if (ml == (void*)language_nothing)
            return NULL;
    }

    for (; ml != (void*)language_nothing; ml = language_atomic_load_relaxed(&ml->next)) {
        if (world < language_atomic_load_relaxed(&ml->min_world) || world > language_atomic_load_relaxed(&ml->max_world))
            continue; // ignore replaced methods
        size_t lensig = language_nparams(ml->sig);
        if (lensig == n || (ml->va && lensig <= n+1)) {
            if (ml->simplesig != (void*)language_nothing) {
                size_t lensimplesig = language_nparams(ml->simplesig);
                int isva = lensimplesig > 0 && language_is_vararg(language_tparam(ml->simplesig, lensimplesig - 1));
                if (lensig == n || (isva && lensimplesig <= n + 1)) {
                    if (!sig_match_simple(arg1, args, n, language_svec_data(ml->simplesig->parameters), isva, lensimplesig))
                        continue;
                }
                else {
                    continue;
                }
            }

            if (ml->isleafsig) {
                if (!sig_match_leaf(arg1, args, language_svec_data(ml->sig->parameters), n))
                    continue;
            }
            else if (ml->issimplesig) {
                if (!sig_match_simple(arg1, args, n, language_svec_data(ml->sig->parameters), ml->va, lensig))
                    continue;
            }
            else {
                if (!language_tuple1_isa(arg1, args, n, ml->sig))
                    continue;
            }

            size_t i, l;
            if (ml->guardsigs != language_emptysvec) {
                for (i = 0, l = language_svec_len(ml->guardsigs); i < l; i++) {
                    // checking guard entries require a more
                    // expensive subtype check, since guard entries added for @nospecialize might be
                    // abstract. this fixed issue #12967.
                    if (language_tuple1_isa(arg1, args, n, (language_tupletype_t*)language_svecref(ml->guardsigs, i))) {
                        goto nomatch;
                    }
                }
            }
            return ml;
nomatch:
            continue;
        }
    }
    return NULL;
}

language_typemap_entry_t *language_typemap_level_assoc_exact(language_typemap_level_t *cache, language_value_t *arg1, language_value_t **args, size_t n, int8_t offs, size_t world)
{
    if (n > offs) {
        language_value_t *a1 = (offs == 0 ? arg1 : args[offs - 1]);
        language_value_t *ty = language_typeof(a1);
        assert(language_is_datatype(ty));
        language_genericmemory_t *targ = language_atomic_load_relaxed(&cache->targ);
        if (targ != (language_genericmemory_t*)language_an_empty_memory_any && is_cache_leaf(a1, 1)) {
            language_typename_t *name = a1 == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)a1)->name;
            language_value_t *ml_or_cache = mtcache_hash_lookup(targ, (language_value_t*)name);
            if (language_is_genericmemory(ml_or_cache))
                ml_or_cache = mtcache_hash_lookup((language_genericmemory_t*)ml_or_cache, a1);
            language_typemap_entry_t *ml = language_typemap_assoc_exact(ml_or_cache, arg1, args, n, offs+1, world);
            if (ml) return ml;
        }
        language_genericmemory_t *cachearg1 = language_atomic_load_relaxed(&cache->arg1);
        if (cachearg1 != (language_genericmemory_t*)language_an_empty_memory_any && is_cache_leaf(ty, 0)) {
            language_typename_t *name = ty == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)ty)->name;
            language_value_t *ml_or_cache = mtcache_hash_lookup(cachearg1, (language_value_t*)name);
            if (language_is_genericmemory(ml_or_cache))
                ml_or_cache = mtcache_hash_lookup((language_genericmemory_t*)ml_or_cache, ty);
            language_typemap_entry_t *ml = language_typemap_assoc_exact((language_typemap_t*)ml_or_cache, arg1, args, n, offs+1, world);
            if (ml) return ml;
        }
        language_genericmemory_t *tname = language_atomic_load_relaxed(&cache->tname);
        if (language_is_kind(ty) && tname != (language_genericmemory_t*)language_an_empty_memory_any) {
            language_value_t *name = language_type_extract_name(a1);
            if (name) {
                if (ty != (language_value_t*)language_datatype_type)
                    a1 = language_unwrap_unionall(((language_typename_t*)name)->wrapper);
                while (1) {
                    tname = language_atomic_load_relaxed(&cache->tname); // reload after tree descent (which may hit safepoints)
                    language_typemap_t *ml_or_cache = mtcache_hash_lookup(
                            tname, (language_value_t*)((language_datatype_t*)a1)->name);
                    language_typemap_entry_t *ml = language_typemap_assoc_exact(ml_or_cache, arg1, args, n, offs+1, world);
                    if (ml) return ml;
                    if (a1 == (language_value_t*)language_any_type)
                        break;
                    a1 = (language_value_t*)((language_datatype_t*)a1)->super;
                }
            }
            else {
                // couldn't figure out unique `name` initial point, so must scan all for matches
                size_t i, l = tname->length;
                _Atomic(language_typemap_t*) *data = (_Atomic(language_typemap_t*)*) language_genericmemory_ptr_data(tname);
                LANGUAGE_GC_PUSH1(&tname);
                for (i = 1; i < l; i += 2) {
                    language_typemap_t *ml_or_cache = language_atomic_load_relaxed(&data[i]);
                    if (ml_or_cache == NULL || ml_or_cache == language_nothing)
                        continue;
                    language_typemap_entry_t *ml = language_typemap_assoc_exact(ml_or_cache, arg1, args, n, offs + 1, world);
                    if (ml) {
                        LANGUAGE_GC_POP();
                        return ml;
                    }
                }
                LANGUAGE_GC_POP();
            }
        }
        language_genericmemory_t *name1 = language_atomic_load_relaxed(&cache->name1);
        if (name1 != (language_genericmemory_t*)language_an_empty_memory_any) {
            while (1) {
                name1 = language_atomic_load_relaxed(&cache->name1); // reload after tree descent (which may hit safepoints)
                language_typemap_t *ml_or_cache = mtcache_hash_lookup(
                        name1, (language_value_t*)((language_datatype_t*)ty)->name);
                language_typemap_entry_t *ml = language_typemap_assoc_exact(ml_or_cache, arg1, args, n, offs+1, world);
                if (ml) return ml;
                if (ty == (language_value_t*)language_any_type)
                    break;
                ty = (language_value_t*)((language_datatype_t*)ty)->super;
            }
        }
    }
    language_typemap_entry_t *linear = language_atomic_load_relaxed(&cache->linear);
    if (linear != (language_typemap_entry_t*)language_nothing) {
        language_typemap_entry_t *ml = language_typemap_entry_assoc_exact(linear, arg1, args, n, world);
        if (ml) return ml;
    }
    language_typemap_t *cacheany = language_atomic_load_relaxed(&cache->any);
    if (cacheany != (language_typemap_t*)language_nothing)
        return language_typemap_assoc_exact(cacheany, arg1, args, n, offs+1, world);
    return NULL;
}


// ----- Method List Insertion Management ----- //

static unsigned language_typemap_list_count_locked(language_typemap_entry_t *ml) LANGUAGE_NOTSAFEPOINT
{
    unsigned count = 0;
    while (ml != (void*)language_nothing) {
        count++;
        ml = language_atomic_load_relaxed(&ml->next);
    }
    return count;
}

static void language_typemap_level_insert_(language_typemap_t *map, language_typemap_level_t *cache, language_typemap_entry_t *newrec, int8_t offs);

static language_typemap_level_t *language_new_typemap_level(void)
{
    language_task_t *ct = language_current_task;
    language_typemap_level_t *cache =
        (language_typemap_level_t*)language_gc_alloc(ct->ptls, sizeof(language_typemap_level_t),
                                         language_typemap_level_type);
    language_atomic_store_relaxed(&cache->arg1, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&cache->targ, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&cache->name1, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&cache->tname, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&cache->linear, (language_typemap_entry_t*)language_nothing);
    language_atomic_store_relaxed(&cache->any, language_nothing);
    return cache;
}

static void language_typemap_memory_insert_(
        language_typemap_t *map, _Atomic(language_genericmemory_t*) *pcache, language_value_t *key, language_typemap_entry_t *newrec,
        language_value_t *parent, int8_t tparam, int8_t offs, language_value_t *doublesplit);

static language_value_t *language_method_convert_list_to_cache(
        language_typemap_t *map, language_typemap_entry_t *ml, int8_t tparam, int8_t offs, int8_t doublesplit)
{
    language_value_t *cache = doublesplit ? language_an_empty_memory_any : (language_value_t*)language_new_typemap_level();
    language_typemap_entry_t *next = NULL;
    LANGUAGE_GC_PUSH3(&cache, &next, &ml);
    while (ml != (void*)language_nothing) {
        next = language_atomic_load_relaxed(&ml->next);
        language_atomic_store_relaxed(&ml->next, (language_typemap_entry_t*)language_nothing);
        // n.b. this is being done concurrently with lookups!
        // TODO: is it safe to be doing this concurrently with lookups?
        if (doublesplit) {
            language_value_t *key = language_unwrap_unionall((language_value_t*)ml->sig);
            size_t len = language_nparams(key);
            if (offs < len-1)
                key = language_tparam(key, offs);
            else
                key = language_tparam(key, len-1);
            if (language_is_vararg(key))
                key = language_unwrap_vararg(key);
            if (key == (language_value_t*)language_typeofbottom_type)
                key = (language_value_t*)language_assume(language_typeofbottom_type)->super;
            if (tparam) {
                assert(language_is_type_type(key));
                key = language_tparam0(key);
            }
            language_typemap_memory_insert_(map, (_Atomic(language_genericmemory_t*)*)&cache, key, ml, NULL, 0, offs, NULL);
        }
        else
            language_typemap_level_insert_(map, (language_typemap_level_t*)cache, ml, offs);
        ml = next;
    }
    LANGUAGE_GC_POP();
    return cache;
}

static void language_typemap_list_insert_(
        language_typemap_t *map, _Atomic(language_typemap_entry_t*) *pml, language_value_t *parent,
        language_typemap_entry_t *newrec)
{
    language_typemap_entry_t *l = language_atomic_load_relaxed(pml);
    while ((language_value_t*)l != language_nothing) {
        if (newrec->isleafsig || !l->isleafsig)
            if (newrec->issimplesig || !l->issimplesig)
                break;
        pml = &l->next;
        parent = (language_value_t*)l;
        l = language_atomic_load_relaxed(&l->next);
    }
    language_atomic_store_relaxed(&newrec->next, l);
    language_gc_wb(newrec, l);
    language_atomic_store_release(pml, newrec);
    language_gc_wb(parent, newrec);
}

// n.b. tparam value only needed if doublesplit is set (for language_method_convert_list_to_cache)
static void language_typemap_insert_generic(
        language_typemap_t *map, _Atomic(language_value_t*) *pml, language_value_t *parent,
        language_typemap_entry_t *newrec, int8_t tparam, int8_t offs, language_value_t *doublesplit)
{
    language_value_t *ml = language_atomic_load_relaxed(pml);
    if (language_is_genericmemory(ml)) {
        assert(doublesplit);
        language_typemap_memory_insert_(map, (_Atomic(language_genericmemory_t*)*)pml, doublesplit, newrec, parent, 0, offs, NULL);
        return;
    }
    if (language_typeof(ml) == (language_value_t*)language_typemap_level_type) {
        assert(!doublesplit);
        language_typemap_level_insert_(map, (language_typemap_level_t*)ml, newrec, offs);
        return;
    }

    unsigned count = language_typemap_list_count_locked((language_typemap_entry_t*)ml);
    if (count > MAX_METHLIST_COUNT) {
        ml = language_method_convert_list_to_cache(
            map, (language_typemap_entry_t*)ml, tparam, offs, doublesplit != NULL);
        language_atomic_store_release(pml, ml);
        language_gc_wb(parent, ml);
        if (doublesplit)
            language_typemap_memory_insert_(map, (_Atomic(language_genericmemory_t*)*)pml, doublesplit, newrec, parent, 0, offs, NULL);
        else
            language_typemap_level_insert_(map, (language_typemap_level_t*)ml, newrec, offs);
        return;
    }

    language_typemap_list_insert_(map, (_Atomic(language_typemap_entry_t*)*)pml,
        parent, newrec);
}

static void language_typemap_memory_insert_(
        language_typemap_t *map, _Atomic(language_genericmemory_t*) *pcache, language_value_t *key, language_typemap_entry_t *newrec,
        language_value_t *parent, int8_t tparam, int8_t offs, language_value_t *doublesplit)
{
    language_genericmemory_t *cache = language_atomic_load_relaxed(pcache);
    _Atomic(language_value_t*) *pml = mtcache_hash_lookup_bp(cache, key);
    if (pml == NULL)
        mtcache_hash_insert(pcache, parent, key, (language_typemap_t*)newrec);
    else
        language_typemap_insert_generic(map, pml, (language_value_t*) cache, newrec, tparam, offs + (doublesplit ? 0 : 1), doublesplit);
}

static void language_typemap_level_insert_(
        language_typemap_t *map, language_typemap_level_t *cache, language_typemap_entry_t *newrec, int8_t offs)
{
    language_value_t *ttypes = language_unwrap_unionall((language_value_t*)newrec->sig);
    size_t l = language_nparams(ttypes);
    // compute the type at offset `offs` into `sig`, which may be a Vararg
    language_value_t *t1;
    int isva = 0;
    if (l <= offs + 1) {
        t1 = language_tparam(ttypes, l - 1);
        if (language_is_vararg(t1)) {
            isva = 1;
            t1 = language_unwrap_vararg(t1);
        }
        else if (l <= offs) {
            t1 = NULL;
        }
    }
    else if (l > offs) {
        t1 = language_tparam(ttypes, offs);
    }
    else {
        t1 = NULL;
    }
    if (t1 == (language_value_t*)language_typeofbottom_type)
        t1 = (language_value_t*)language_assume(language_typeofbottom_type)->super;
    // If the type at `offs` is Any, put it in the Any list
    if (t1 && language_is_any(t1)) {
        language_typemap_insert_generic(map, &cache->any, (language_value_t*)cache, newrec, 0, offs+1, NULL);
        return;
    }
    // Don't put Varargs in the optimized caches (too hard to handle in lookup and bp)
    if (t1 && !isva) {
        // try to put in leaf type caches
        if (language_is_type_type(t1)) {
            // if the argument is Type{...}, this method has specializations for singleton kinds
            // and we use the table indexed for that purpose.
            language_value_t *a0 = language_tparam0(t1);
            if (is_cache_leaf(a0, 1)) {
                language_typename_t *name = a0 == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)a0)->name;
                language_typemap_memory_insert_(map, &cache->targ, (language_value_t*)name, newrec, (language_value_t*)cache, 1, offs, language_is_datatype(name->wrapper) ? NULL : a0);
                return;
            }
        }
        if (is_cache_leaf(t1, 0)) {
            language_typename_t *name = t1 == language_bottom_type ? language_typeofbottom_type->name : ((language_datatype_t*)t1)->name;
            language_typemap_memory_insert_(map, &cache->arg1, (language_value_t*)name, newrec, (language_value_t*)cache, 0, offs, language_is_datatype(name->wrapper) ? NULL : t1);
            return;
        }

        // try to put in TypeName caches
        language_value_t *a0;
        t1 = language_unwrap_unionall(t1);
        if (language_is_type_type(t1)) {
            a0 = language_type_extract_name(language_tparam0(t1));
            language_datatype_t *super = a0 ? (language_datatype_t*)language_unwrap_unionall(((language_typename_t*)a0)->wrapper) : language_any_type;
            language_typemap_memory_insert_(map, &cache->tname, (language_value_t*)super->name, newrec, (language_value_t*)cache, 1, offs, NULL);
            return;
        }
        a0 = language_type_extract_name(t1);
        if (a0 && a0 != (language_value_t*)language_any_type->name) {
            language_typemap_memory_insert_(map, &cache->name1, a0, newrec, (language_value_t*)cache, 0, offs, NULL);
            return;
        }
    }
    language_typemap_list_insert_(map, &cache->linear, (language_value_t*)cache, newrec);
}

language_typemap_entry_t *language_typemap_alloc(
        language_tupletype_t *type, language_tupletype_t *simpletype, language_svec_t *guardsigs,
        language_value_t *newvalue, size_t min_world, size_t max_world)
{
    language_task_t *ct = language_current_task;
    assert(min_world > 0 && max_world > 0);
    if (!simpletype)
        simpletype = (language_tupletype_t*)language_nothing;
    language_value_t *ttype = language_unwrap_unionall((language_value_t*)type);
    assert(language_is_tuple_type(ttype));
    // compute the complexity of this type signature
    int isva = language_is_va_tuple((language_datatype_t*)ttype);
    int issimplesig = !language_is_unionall(type); // a TypeVar environment needs a complex matching test
    int isleafsig = issimplesig && !isva; // entirely leaf types don't need to be sorted
    size_t i, l;
    for (i = 0, l = language_nparams(ttype); i < l && issimplesig; i++) {
        language_value_t *decl = language_tparam(ttype, i);
        if (language_is_kind(decl))
            isleafsig = 0; // Type{} may have a higher priority than a kind
        else if (language_is_type_type(decl))
            isleafsig = 0; // Type{} may need special processing to compute the match
        else if (language_is_vararg(decl))
            isleafsig = 0; // makes iteration easier when the endpoints are the same
        else if (decl == (language_value_t*)language_any_type)
            isleafsig = 0; // Any needs to go in the general cache
        else if (!language_is_concrete_type(decl)) // anything else needs to go through the general subtyping test
            isleafsig = issimplesig = 0;
    }

    language_typemap_entry_t *newrec =
        (language_typemap_entry_t*)language_gc_alloc(ct->ptls, sizeof(language_typemap_entry_t),
                                         language_typemap_entry_type);
    newrec->sig = type;
    newrec->simplesig = simpletype;
    newrec->func.value = newvalue;
    newrec->guardsigs = guardsigs;
    language_atomic_store_relaxed(&newrec->next, (language_typemap_entry_t*)language_nothing);
    language_atomic_store_relaxed(&newrec->min_world, min_world);
    language_atomic_store_relaxed(&newrec->max_world, max_world);
    newrec->va = isva;
    newrec->issimplesig = issimplesig;
    newrec->isleafsig = isleafsig;
    return newrec;
}

void language_typemap_insert(_Atomic(language_typemap_t *) *pcache, language_value_t *parent,
        language_typemap_entry_t *newrec, int8_t offs)
{
    language_typemap_t *cache = language_atomic_load_relaxed(pcache);
    language_typemap_insert_generic(cache, pcache, parent, newrec, 0, offs, NULL);
}

#ifdef __cplusplus
}
#endif
