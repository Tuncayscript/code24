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
  Types
  . type union, type cache, and instantiation
  . builtin type definitions
*/
#include <stdlib.h>
#include <string.h>
#ifdef _OS_WINDOWS_
#include <malloc.h>
#endif
#include "code.h"
#include "language_internal.h"
#include "builtin_proto.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

_Atomic(language_value_t*) cmpswap_names LANGUAGE_GLOBALLY_ROOTED;
language_datatype_t *ilanguage_small_typeof[(language_max_tags << 4) / sizeof(*ilanguage_small_typeof)]; // 16-bit aligned, like the GC

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)((hv) & ((sz)-1))

// --- type properties and predicates ---

static int typeenv_has(language_typeenv_t *env, language_tvar_t *v) LANGUAGE_NOTSAFEPOINT
{
    while (env != NULL) {
        if (env->var == v)
            return 1;
        env = env->prev;
    }
    return 0;
}

static int typeenv_has_ne(language_typeenv_t *env, language_tvar_t *v) LANGUAGE_NOTSAFEPOINT
{
    while (env != NULL) {
        if (env->var == v)
            return env->val != (language_value_t*)v; // consider it actually not present if it is bound to itself unchanging
        env = env->prev;
    }
    return 0;
}


static int layout_uses_free_typevars(language_value_t *v, language_typeenv_t *env)
{
    while (1) {
        if (language_is_typevar(v))
            return !typeenv_has(env, (language_tvar_t*)v);
        while (language_is_unionall(v)) {
            language_unionall_t *ua = (language_unionall_t*)v;
            language_typeenv_t *newenv = (language_typeenv_t*)alloca(sizeof(language_typeenv_t));
            newenv->var = ua->var;
            newenv->val = NULL;
            newenv->prev = env;
            env = newenv;
            v = ua->body;
        }
        if (language_is_datatype(v)) {
            language_datatype_t *dt = (language_datatype_t*)v;
            if (dt->isconcretetype)
                return 0;
            if (dt->layout || !dt->name->mayinlinealloc)
                return 0;
            if (dt->name == language_namedtuple_typename)
                return layout_uses_free_typevars(language_tparam0(dt), env) || layout_uses_free_typevars(language_tparam1(dt), env);
            if (dt->name == language_tuple_typename)
                // conservative, since we don't want to inline an abstract tuple,
                // and we currently declare !has_fixed_layout for these, but that
                // means we also won't be able to inline a tuple which is concrete
                // except for the use of free type-vars
                return 1;
            language_svec_t *types = language_get_fieldtypes(dt);
            size_t i, l = language_svec_len(types);
            for (i = 0; i < l; i++) {
                language_value_t *ft = language_svecref(types, i);
                if (layout_uses_free_typevars(ft, env))
                    // This might be inline-alloc, but we don't know the layout
                    return 1;
            }
            return 0;
        }
        else if (language_is_uniontype(v)) {
            if (layout_uses_free_typevars(((language_uniontype_t*)v)->a, env))
                return 1;
           v = ((language_uniontype_t*)v)->b;
        }
        else if (language_is_vararg(v)) {
            language_vararg_t *vm = (language_vararg_t*)v;
            if (!vm->T)
                return 0;
            if (vm->N && layout_uses_free_typevars(vm->N, env))
                return 1;
            v = vm->T;
        }
        else {
            return 0;
        }
    }
}

static int has_free_typevars(language_value_t *v, language_typeenv_t *env) LANGUAGE_NOTSAFEPOINT
{
    while (1) {
        if (language_is_typevar(v)) {
            return !typeenv_has(env, (language_tvar_t*)v);
        }
        while (language_is_unionall(v)) {
            language_unionall_t *ua = (language_unionall_t*)v;
            if (ua->var->lb != language_bottom_type && has_free_typevars(ua->var->lb, env))
                return 1;
            if (ua->var->ub != (language_value_t*)language_any_type && has_free_typevars(ua->var->ub, env))
                return 1;
            language_typeenv_t *newenv = (language_typeenv_t*)alloca(sizeof(language_typeenv_t));
            newenv->var = ua->var;
            newenv->val = NULL;
            newenv->prev = env;
            env = newenv;
            v = ua->body;
        }
        if (language_is_datatype(v)) {
            int expect = ((language_datatype_t*)v)->hasfreetypevars;
            if (expect == 0 || env == NULL)
                return expect;
            size_t i;
            for (i = 0; i < language_nparams(v); i++) {
                if (has_free_typevars(language_tparam(v, i), env))
                    return 1;
            }
            return 0;
        }
        else if (language_is_uniontype(v)) {
            if (has_free_typevars(((language_uniontype_t*)v)->a, env))
                return 1;
           v = ((language_uniontype_t*)v)->b;
        }
        else if (language_is_vararg(v)) {
            language_vararg_t *vm = (language_vararg_t*)v;
            if (!vm->T)
                return 0;
            if (vm->N && has_free_typevars(vm->N, env))
                return 1;
            v = vm->T;
        }
        else {
            return 0;
        }
    }
}

LANGUAGE_DLLEXPORT int language_has_free_typevars(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    return has_free_typevars(v, NULL);
}

static void find_free_typevars(language_value_t *v, language_typeenv_t *env, language_array_t *out)
{
    while (1) {
        if (language_is_typevar(v)) {
            if (!typeenv_has(env, (language_tvar_t*)v))
                language_array_ptr_1d_push(out, v);
            return;
        }
        while (language_is_unionall(v)) {
            language_unionall_t *ua = (language_unionall_t*)v;
            if (ua->var->lb != language_bottom_type)
                find_free_typevars(ua->var->lb, env, out);
            if (ua->var->ub != (language_value_t*)language_any_type)
                find_free_typevars(ua->var->ub, env, out);
            language_typeenv_t *newenv = (language_typeenv_t*)alloca(sizeof(language_typeenv_t));
            newenv->var = ua->var;
            newenv->val = NULL;
            newenv->prev = env;
            env = newenv;
            v = ua->body;
        }
        if (language_is_datatype(v)) {
            if (!((language_datatype_t*)v)->hasfreetypevars)
                return;
            size_t i;
            for (i = 0; i < language_nparams(v); i++)
                find_free_typevars(language_tparam(v, i), env, out);
            return;
        }
        else if (language_is_uniontype(v)) {
            find_free_typevars(((language_uniontype_t*)v)->a, env, out);
            v = ((language_uniontype_t*)v)->b;
        }
        else if (language_is_vararg(v)) {
            language_vararg_t *vm = (language_vararg_t *)v;
            if (!vm->T)
                return;
            if (vm->N) // this swap the visited order, but we don't mind it
                find_free_typevars(vm->N, env, out);
            v = vm->T;
        }
        else {
            return;
        }
    }
}

LANGUAGE_DLLEXPORT language_array_t *language_find_free_typevars(language_value_t *v)
{
    language_array_t *out = language_alloc_vec_any(0);
    LANGUAGE_GC_PUSH1(&out);
    find_free_typevars(v, NULL, out);
    LANGUAGE_GC_POP();
    return out;
}

// test whether a type has vars bound by the given environment
int language_has_bound_typevars(language_value_t *v, language_typeenv_t *env) LANGUAGE_NOTSAFEPOINT
{
    while (1) {
        if (language_is_typevar(v)) {
            return typeenv_has_ne(env, (language_tvar_t*)v);
        }
        while (language_is_unionall(v)) {
            language_unionall_t *ua = (language_unionall_t*)v;
            if (ua->var->lb != language_bottom_type && language_has_bound_typevars(ua->var->lb, env))
                return 1;
            if (ua->var->ub != (language_value_t*)language_any_type && language_has_bound_typevars(ua->var->ub, env))
                return 1;
            // Temporarily remove this var from env if necessary
            // Note that te might be bound more than once in the env, so
            // we remove it by setting it to itself in a new env.
            if (typeenv_has_ne(env, ua->var)) {
                language_typeenv_t *newenv = (language_typeenv_t*)alloca(sizeof(language_typeenv_t));
                newenv->var = ua->var;
                newenv->val = (language_value_t*)ua->var;
                newenv->prev = env;
                env = newenv;
            }
            v = ua->body;
        }
        if (language_is_datatype(v)) {
            if (!((language_datatype_t*)v)->hasfreetypevars)
                return 0;
            size_t i;
            for (i = 0; i < language_nparams(v); i++) {
                if (language_has_bound_typevars(language_tparam(v, i), env))
                    return 1;
            }
            return 0;
        }
        else if (language_is_uniontype(v)) {
            if (language_has_bound_typevars(((language_uniontype_t*)v)->a, env))
                return 1;
           v = ((language_uniontype_t*)v)->b;
        }
        else if (language_is_vararg(v)) {
            language_vararg_t *vm = (language_vararg_t *)v;
            if (!vm->T)
                return 0;
            if (vm->N && language_has_bound_typevars(vm->N, env))
                return 1;
            v = vm->T;
        }
        else {
            return 0;
        }
    }
}

LANGUAGE_DLLEXPORT int language_has_typevar(language_value_t *t, language_tvar_t *v) LANGUAGE_NOTSAFEPOINT
{
    language_typeenv_t env = { v, NULL, NULL };
    return language_has_bound_typevars(t, &env);
}

static int _language_has_typevar_from_ua(language_value_t *t, language_unionall_t *ua, language_typeenv_t *prev)
{
    language_typeenv_t env = { ua->var, NULL, prev };
    if (language_is_unionall(ua->body))
        return _language_has_typevar_from_ua(t, (language_unionall_t*)ua->body, &env);
    else
        return language_has_bound_typevars(t, &env);
}

LANGUAGE_DLLEXPORT int language_has_typevar_from_unionall(language_value_t *t, language_unionall_t *ua)
{
    return _language_has_typevar_from_ua(t, ua, NULL);
}

int language_has_fixed_layout(language_datatype_t *dt)
{
    if (dt->isconcretetype)
        return 1;
    if (language_is_genericmemory_type(dt)) { // GenericMemory{kind,addrspace,T} uses T for final layout, which is a parameter not a field however
        // optionally: return !layout_uses_free_typevars(language_tparam1(dt), env);
        return 0;
    }
    if (dt->layout)
        return 1;
    if (dt->name->abstract)
        return 0;
    if (dt->name == language_namedtuple_typename)
        return !layout_uses_free_typevars(language_tparam0(dt), NULL) && !layout_uses_free_typevars(language_tparam1(dt), NULL);
    if (dt->name == language_tuple_typename)
        return 0;
    language_svec_t *types = language_get_fieldtypes(dt);
    size_t i, l = language_svec_len(types);
    for (i = 0; i < l; i++) {
        language_value_t *ft = language_svecref(types, i);
        if (layout_uses_free_typevars(ft, NULL)) {
            // This might be inline-alloc, but we don't know the layout
            return 0;
        }
    }
    return 1;
}

int language_type_mappable_to_c(language_value_t *ty)
{
    assert(!language_is_typevar(ty) && language_is_type(ty));
    if (language_is_array_type(ty) || language_is_genericmemory_type(ty) ||
        (language_is_datatype(ty) && ((language_datatype_t*)ty)->layout != NULL &&
            language_is_layout_opaque(((language_datatype_t*)ty)->layout)))
        return 1; // as boxed
    if (language_is_structtype(ty))
        return language_has_fixed_layout((language_datatype_t*)ty) && ((language_datatype_t*)ty)->name->atomicfields == NULL;
    if (language_is_primitivetype(ty))
        return 1; // as isbits
    if (ty == (language_value_t*)language_any_type || ty == (language_value_t*)language_bottom_type || language_is_abstract_ref_type(ty))
        return 1; // as boxed
    return 0; // refuse to map Union and UnionAll to C
}

// Return true for any type (Integer or Unsigned) that can fit in a
// size_t and pass back value, else return false
LANGUAGE_DLLEXPORT int language_get_size(language_value_t *val, size_t *pnt)
{
    if (language_is_long(val)) {
        ssize_t slen = language_unbox_long(val);
        if (slen < 0)
            language_errorf("size or dimension is negative: %zd", slen);
        *pnt = slen;
        return 1;
    }
    return 0;
}

// --- type union ---

int language_count_union_components(language_value_t *v)
{
    size_t c = 0;
    while (language_is_uniontype(v)) {
        language_uniontype_t *u = (language_uniontype_t*)v;
        c += language_count_union_components(u->a);
        v = u->b;
    }
    return c + 1;
}

// Return the `*pi`th element of a nested type union, according to a
// standard traversal order. Anything that is not itself a `Union` is
// considered an "element". `*pi` is destroyed in the process.
static language_value_t *nth_union_component(language_value_t *v, int *pi) LANGUAGE_NOTSAFEPOINT
{
    while (language_is_uniontype(v)) {
        language_uniontype_t *u = (language_uniontype_t*)v;
        language_value_t *a = nth_union_component(u->a, pi);
        if (a) return a;
        v = u->b;
    }
    if (*pi == 0)
        return v;
    (*pi)--;
    return NULL;
}

language_value_t *language_nth_union_component(language_value_t *v, int i) LANGUAGE_NOTSAFEPOINT
{
    return nth_union_component(v, &i);
}

// inverse of language_nth_union_component
int language_find_union_component(language_value_t *haystack, language_value_t *needle, unsigned *nth) LANGUAGE_NOTSAFEPOINT
{
    while (language_is_uniontype(haystack)) {
        language_uniontype_t *u = (language_uniontype_t*)haystack;
        if (language_find_union_component(u->a, needle, nth))
            return 1;
        haystack = u->b;
    }
    if (needle == haystack)
        return 1;
    (*nth)++;
    return 0;
}

STATIC_INLINE const char *datatype_module_name(language_value_t *t) LANGUAGE_NOTSAFEPOINT
{
    if (((language_datatype_t*)t)->name->module == NULL)
        return NULL;
    return language_symbol_name(((language_datatype_t*)t)->name->module->name);
}

STATIC_INLINE const char *str_(const char *s) LANGUAGE_NOTSAFEPOINT
{
    return s == NULL ? "" : s;
}

STATIC_INLINE int cmp_(int a, int b) LANGUAGE_NOTSAFEPOINT
{
    return a < b ? -1 : a > b;
}

// a/b are language_datatype_t* & not NULL
static int datatype_name_cmp(language_value_t *a, language_value_t *b) LANGUAGE_NOTSAFEPOINT
{
    if (!language_is_datatype(a))
        return language_is_datatype(b) ? 1 : 0;
    if (!language_is_datatype(b))
        return -1;
    int cmp = strcmp(str_(datatype_module_name(a)), str_(datatype_module_name(b)));
    if (cmp != 0)
        return cmp;
    cmp = strcmp(str_(language_typename_str(a)), str_(language_typename_str(b)));
    if (cmp != 0)
        return cmp;
    cmp = cmp_(language_nparams(a), language_nparams(b));
    if (cmp != 0)
        return cmp;
    // compare up to 3 type parameters
    for (int i = 0; i < 3 && i < language_nparams(a); i++) {
        language_value_t *ap = language_tparam(a, i);
        language_value_t *bp = language_tparam(b, i);
        if (ap == bp) {
            continue;
        }
        else if (language_is_datatype(ap) && language_is_datatype(bp)) {
            cmp = datatype_name_cmp(ap, bp);
            if (cmp != 0)
                return cmp;
        }
        else if (language_is_unionall(ap) && language_is_unionall(bp)) {
            cmp = datatype_name_cmp(language_unwrap_unionall(ap), language_unwrap_unionall(bp));
            if (cmp != 0)
                return cmp;
        }
        else {
            // give up
            cmp = 0;
        }
    }
    return cmp;
}

// sort singletons first, then DataTypes, then UnionAlls,
// ties broken alphabetically including module name & type parameters
static int union_sort_cmp(language_value_t *a, language_value_t *b) LANGUAGE_NOTSAFEPOINT
{
    if (a == NULL)
        return b == NULL ? 0 : 1;
    if (b == NULL)
        return -1;
    if (language_is_datatype(a)) {
        if (!language_is_datatype(b))
            return -1;
        if (language_is_datatype_singleton((language_datatype_t*)a)) {
            if (language_is_datatype_singleton((language_datatype_t*)b))
                return datatype_name_cmp(a, b);
            return -1;
        }
        else if (language_is_datatype_singleton((language_datatype_t*)b)) {
            return 1;
        }
        else if (language_isbits(a)) {
            if (language_isbits(b))
                return datatype_name_cmp(a, b);
            return -1;
        }
        else if (language_isbits(b)) {
            return 1;
        }
        else {
            return datatype_name_cmp(a, b);
        }
    }
    else {
        if (language_is_datatype(b))
            return 1;
        return datatype_name_cmp(language_unwrap_unionall(a), language_unwrap_unionall(b));
    }
}

static int count_union_components(language_value_t **types, size_t n, int widen)
{
    size_t i, c = 0;
    for (i = 0; i < n; i++) {
        language_value_t *e = types[i];
        while (language_is_uniontype(e)) {
            language_uniontype_t *u = (language_uniontype_t*)e;
            c += count_union_components(&u->a, 1, widen);
            e = u->b;
        }
        if (widen && language_is_unionall(e) && language_is_uniontype(language_unwrap_unionall(e))) {
            language_uniontype_t *u = (language_uniontype_t*)language_unwrap_unionall(e);
            c += count_union_components(&u->a, 2, widen);
        }
        else {
            c++;
        }
    }
    return c;
}

static void flatten_type_union(language_value_t **types, size_t n, language_value_t **out, size_t *idx, int widen)
{
    size_t i;
    for (i = 0; i < n; i++) {
        language_value_t *e = types[i];
        while (language_is_uniontype(e)) {
            language_uniontype_t *u = (language_uniontype_t*)e;
            flatten_type_union(&u->a, 1, out, idx, widen);
            e = u->b;
        }
        if (widen && language_is_unionall(e) && language_is_uniontype(language_unwrap_unionall(e))) {
            // flatten this UnionAll into place by switching the union and unionall
            language_uniontype_t *u = (language_uniontype_t*)language_unwrap_unionall(e);
            size_t old_idx = 0;
            flatten_type_union(&u->a, 2, out, idx, widen);
            for (; old_idx < *idx; old_idx++)
                out[old_idx] = language_rewrap_unionall(out[old_idx], e);
        }
        else {
            out[*idx] = e;
            (*idx)++;
        }
    }
}


static void isort_union(language_value_t **a, size_t len) LANGUAGE_NOTSAFEPOINT
{
    size_t i, j;
    for (i = 1; i < len; i++) {
        language_value_t *x = a[i];
        for (j = i; j > 0; j--) {
            language_value_t *y = a[j - 1];
            if (!(union_sort_cmp(x, y) < 0))
                break;
            a[j] = y;
        }
        a[j] = x;
    }
}

static int simple_subtype(language_value_t *a, language_value_t *b, int hasfree, int isUnion)
{
    assert(hasfree == (language_has_free_typevars(a) | (language_has_free_typevars(b) << 1)));
    if (a == language_bottom_type || b == (language_value_t*)language_any_type)
        return 1;
    if (language_egal(a, b))
        return 1;
    if (hasfree == 0) {
        int mergeable = isUnion;
        if (!mergeable) // issue #24521: don't merge Type{T} where typeof(T) varies
            mergeable = !(language_is_type_type(a) && language_is_type_type(b) &&
             language_typeof(language_tparam0(a)) != language_typeof(language_tparam0(b)));
        return mergeable && language_subtype(a, b);
    }
    if (language_is_typevar(a)) {
        language_value_t *na = ((language_tvar_t*)a)->ub;
        hasfree &= (language_has_free_typevars(na) | 2);
        return simple_subtype(na, b, hasfree, isUnion);
    }
    if (language_is_typevar(b)) {
        language_value_t *nb = ((language_tvar_t*)b)->lb;
        // This branch is not valid if `b` obeys diagonal rule,
        // as it might normalize `Union` into a single `TypeVar`, e.g.
        // Tuple{Union{Int,T},T} where {T>:Int} != Tuple{T,T} where {T>:Int}
        if (is_leaf_bound(nb))
            return 0;
        hasfree &= ((language_has_free_typevars(nb) << 1) | 1);
        return simple_subtype(a, nb, hasfree, isUnion);
    }
    if (b==(language_value_t*)language_datatype_type || b==(language_value_t*)language_typeofbottom_type) {
        // This branch is not valid for `Union`/`UnionAll`, e.g.
        // (Type{Union{Int,T2} where {T2<:T1}} where {T1}){Int} == Type{Int64}
        // (Type{Union{Int,T1}} where {T1}){Int} == Type{Int64}
        return language_is_type_type(a) && language_typeof(language_tparam0(a)) == b;
    }
    return 0;
}

LANGUAGE_DLLEXPORT language_value_t *language_type_union(language_value_t **ts, size_t n)
{
    if (n == 0)
        return (language_value_t*)language_bottom_type;
    size_t i;
    for (i = 0; i < n; i++) {
        language_value_t *pi = ts[i];
        if (!(language_is_type(pi) || language_is_typevar(pi)))
            language_type_error("Union", (language_value_t*)language_type_type, pi);
    }
    if (n == 1)
        return ts[0];

    size_t nt = count_union_components(ts, n, 1);
    language_value_t **temp;
    LANGUAGE_GC_PUSHARGS(temp, nt+1);
    size_t count = 0;
    flatten_type_union(ts, n, temp, &count, 1);
    assert(count == nt);
    size_t j;
    for (i = 0; i < nt; i++) {
        int has_free = temp[i] != NULL && language_has_free_typevars(temp[i]);
        for (j = 0; j < nt; j++) {
            if (j != i && temp[i] && temp[j]) {
                int has_free2 = has_free | (language_has_free_typevars(temp[j]) << 1);
                if (simple_subtype(temp[i], temp[j], has_free2, 1))
                    temp[i] = NULL;
            }
        }
    }
    isort_union(temp, nt);
    language_value_t **ptu = &temp[nt];
    *ptu = language_bottom_type;
    int k;
    for (k = (int)nt-1; k >= 0; --k) {
        if (temp[k] != NULL) {
            if (*ptu == language_bottom_type)
                *ptu = temp[k];
            else
                *ptu = language_new_struct(language_uniontype_type, temp[k], *ptu);
        }
    }
    assert(*ptu != NULL);
    language_value_t *tu = *ptu;
    LANGUAGE_GC_POP();
    return tu;
}

static int simple_subtype2(language_value_t *a, language_value_t *b, int hasfree, int isUnion)
{
    assert(hasfree == (language_has_free_typevars(a) | (language_has_free_typevars(b) << 1)));
    int subab = 0, subba = 0;
    if (language_egal(a, b)) {
        subab = subba = 1;
    }
    else if (a == language_bottom_type || b == (language_value_t*)language_any_type) {
        subab = 1;
    }
    else if (b == language_bottom_type || a == (language_value_t*)language_any_type) {
        subba = 1;
    }
    else if (hasfree != 0) {
        subab = simple_subtype(a, b, hasfree, isUnion);
        subba = simple_subtype(b, a, ((hasfree & 2) >> 1) | ((hasfree & 1) << 1), isUnion);
    }
    else if (language_is_type_type(a) && language_is_type_type(b) &&
             language_typeof(language_tparam0(a)) != language_typeof(language_tparam0(b))) {
        // issue #24521: don't merge Type{T} where typeof(T) varies
    }
    else if (language_typeof(a) == language_typeof(b) && language_types_egal(a, b)) {
        subab = subba = 1;
    }
    else {
        subab = language_subtype(a, b);
        subba = language_subtype(b, a);
    }
    return subab | (subba<<1);
}

language_value_t *simple_union(language_value_t *a, language_value_t *b)
{
    size_t nta = count_union_components(&a, 1, 1);
    size_t ntb = count_union_components(&b, 1, 1);
    size_t nt = nta + ntb;
    language_value_t **temp;
    LANGUAGE_GC_PUSHARGS(temp, nt+1);
    size_t count = 0;
    flatten_type_union(&a, 1, temp, &count, 1);
    flatten_type_union(&b, 1, temp, &count, 1);
    assert(count == nt);
    size_t i, j;
    size_t ra = nta, rb = ntb;
    // first remove cross-redundancy and check if `a >: b` or `a <: b`.
    for (i = 0; i < nta; i++) {
        if (temp[i] == NULL) continue;
        int has_free = language_has_free_typevars(temp[i]);
        for (j = nta; j < nt; j++) {
            if (temp[j] == NULL) continue;
            int has_free2 = has_free | (language_has_free_typevars(temp[j]) << 1);
            int subs = simple_subtype2(temp[i], temp[j], has_free2, 0);
            int subab = subs & 1, subba = subs >> 1;
            if (subab) {
                temp[i] = NULL;
                if (!subba) ra = 0;
                count--;
                break;
            }
            else if (subba) {
                temp[j] = NULL;
                rb = 0;
                count--;
            }
        }
    }
    if (count == ra) {
        LANGUAGE_GC_POP();
        return a;
    }
    if (count == rb) {
        LANGUAGE_GC_POP();
        return b;
    }
    // then remove self-redundancy
    for (i = 0; i < nt; i++) {
        int has_free = temp[i] != NULL && language_has_free_typevars(temp[i]);
        size_t jmin = i < nta ? 0 : nta;
        size_t jmax = i < nta ? nta : nt;
        for (j = jmin; j < jmax; j++) {
            if (j != i && temp[i] && temp[j]) {
                int has_free2 = has_free | (language_has_free_typevars(temp[j]) << 1);
                if (simple_subtype(temp[i], temp[j], has_free2, 0))
                    temp[i] = NULL;
            }
        }
    }
    isort_union(temp, nt);
    temp[nt] = language_bottom_type;
    size_t k;
    for (k = nt; k-- > 0; ) {
        if (temp[k] != NULL) {
            if (temp[nt] == language_bottom_type)
                temp[nt] = temp[k];
            else
                temp[nt] = language_new_struct(language_uniontype_type, temp[k], temp[nt]);
        }
    }
    assert(temp[nt] != NULL);
    language_value_t *tu = temp[nt];
    LANGUAGE_GC_POP();
    return tu;
}

int obviously_disjoint(language_value_t *a, language_value_t *b, int specificity);

language_value_t *simple_intersect(language_value_t *a, language_value_t *b, int overesi)
{
    // Unlike `Union`, we don't unwrap `UnionAll` here to avoid possible widening.
    size_t nta = count_union_components(&a, 1, 0);
    size_t ntb = count_union_components(&b, 1, 0);
    size_t nt = nta + ntb;
    language_value_t **temp;
    LANGUAGE_GC_PUSHARGS(temp, nt+1);
    size_t count = 0;
    flatten_type_union(&a, 1, temp, &count, 0);
    flatten_type_union(&b, 1, temp, &count, 0);
    assert(count == nt);
    size_t i, j;
    int8_t *stemp = (int8_t *)alloca(count);
    // first remove disjoint elements.
    memset(stemp, 0, count);
    for (i = 0; i < nta; i++) {
        int hasfree = language_has_free_typevars(temp[i]);
        for (j = nta; j < nt; j++) {
            if (!stemp[i] || !stemp[j]) {
                int intersect = !hasfree && !language_has_free_typevars(temp[j]);
                if (!(intersect ? language_has_empty_intersection(temp[i], temp[j]) : obviously_disjoint(temp[i], temp[j], 0)))
                    stemp[i] = stemp[j] = 1;
            }
        }
    }
    for (i = 0; i < nt; i++) {
        temp[i] = stemp[i] ? temp[i] : NULL;
    }
    // then check subtyping.
    // stemp[k] == -1 : ∃i temp[k] >:ₛ temp[i]
    // stemp[k] == 1 : ∃i temp[k] == temp[i]
    // stemp[k] == 2 : ∃i temp[k] <:ₛ temp[i]
    memset(stemp, 0, count);
    int all_disjoint = 1, subs[2] = {1, 1}, rs[2] = {1, 1};
    for (i = 0; i < nta; i++) {
        if (temp[i] == NULL) continue;
        all_disjoint = 0;
        int has_free = language_has_free_typevars(temp[i]);
        for (j = nta; j < nt; j++) {
            if (temp[j] == NULL) continue;
            int has_free2 = has_free | (language_has_free_typevars(temp[j]) << 1);
            int subs = simple_subtype2(temp[i], temp[j], has_free2, 0);
            int subab = subs & 1, subba = subs >> 1;
            if (subba && !subab) {
                stemp[i] = -1;
                if (stemp[j] >= 0) stemp[j] = 2;
            }
            else if (subab && !subba) {
                stemp[j] = -1;
                if (stemp[i] >= 0) stemp[i] = 2;
            }
            else if (subs) {
                if (stemp[i] == 0) stemp[i] = 1;
                if (stemp[j] == 0) stemp[j] = 1;
            }
        }
    }
    if (!all_disjoint) {
        for (i = 0; i < nt; i++) {
            subs[i >= nta] &= (temp[i] == NULL || stemp[i] > 0);
            rs[i >= nta] &= (temp[i] != NULL && stemp[i] > 0);
        }
        // return a(b) if a(b) <: b(a)
        if (rs[0]) {
            LANGUAGE_GC_POP();
            return a;
        }
        if (rs[1]) {
            LANGUAGE_GC_POP();
            return b;
        }
    }
    // return `Union{}` for `merge_env` if we can't prove `<:` or `>:`
    if (all_disjoint || (!overesi && !subs[0] && !subs[1])) {
        LANGUAGE_GC_POP();
        return language_bottom_type;
    }
    nt = subs[0] ? nta : subs[1] ? nt  : nt;
    i  = subs[0] ? 0   : subs[1] ? nta : 0;
    count = nt - i;
    if (!subs[0] && !subs[1]) {
        // prepare for over estimation
        // only preserve `a` with strict <:, but preserve `b` without strict >:
        for (j = 0; j < nt; j++) {
            if (stemp[j] < (j < nta ? 2 : 0))
                temp[j] = NULL;
        }
    }
    isort_union(&temp[i], count);
    temp[nt] = language_bottom_type;
    size_t k;
    for (k = nt; k-- > i; ) {
        if (temp[k] != NULL) {
            if (temp[nt] == language_bottom_type)
                temp[nt] = temp[k];
            else
                temp[nt] = language_new_struct(language_uniontype_type, temp[k], temp[nt]);
        }
    }
    assert(temp[nt] != NULL);
    language_value_t *tu = temp[nt];
    LANGUAGE_GC_POP();
    return tu;
}

// unionall types -------------------------------------------------------------

LANGUAGE_DLLEXPORT language_value_t *language_type_unionall(language_tvar_t *v, language_value_t *body)
{
    if (language_is_vararg(body)) {
        if (language_options.depwarn) {
            if (language_options.depwarn == LANGUAGE_OPTIONS_DEPWARN_ERROR)
                language_error("Wrapping `Vararg` directly in UnionAll is deprecated (wrap the tuple instead).\nYou may need to write `f(x::Vararg{T})` rather than `f(x::Vararg{<:T})` or `f(x::Vararg{T}) where T` instead of `f(x::Vararg{T} where T)`.");
            language_printf(LANGUAGE_STDERR, "WARNING: Wrapping `Vararg` directly in UnionAll is deprecated (wrap the tuple instead).\nYou may need to write `f(x::Vararg{T})` rather than `f(x::Vararg{<:T})` or `f(x::Vararg{T}) where T` instead of `f(x::Vararg{T} where T)`.\n");
        }
        language_vararg_t *vm = (language_vararg_t*)body;
        int T_has_tv = vm->T && language_has_typevar(vm->T, v);
        int N_has_tv = vm->N && language_has_typevar(vm->N, v);
        if (!T_has_tv && !N_has_tv) {
            return body;
        }
        if (T_has_tv && N_has_tv) {
            language_error("Wrapping `Vararg` directly in UnionAll is disallowed if the typevar occurs in both `T` and `N`");
        }
        if (T_has_tv) {
            language_value_t *wrapped = language_type_unionall(v, vm->T);
            LANGUAGE_GC_PUSH1(&wrapped);
            wrapped = (language_value_t*)language_wrap_vararg(wrapped, vm->N, 1, 0);
            LANGUAGE_GC_POP();
            return wrapped;
        }
        else {
            assert(N_has_tv);
            assert(vm->N == (language_value_t*)v);
            return (language_value_t*)language_wrap_vararg(vm->T, NULL, 1, 0);
        }
    }
    if (!language_is_type(body) && !language_is_typevar(body))
        language_type_error("UnionAll", (language_value_t*)language_type_type, body);
    // normalize `T where T<:S` => S
    if (body == (language_value_t*)v)
        return v->ub;
    // where var doesn't occur in body just return body
    if (!language_has_typevar(body, v))
        return body;
    //if (v->lb == v->ub)  // TODO maybe
    //    return language_substitute_var(body, v, v->ub);
    return language_new_struct(language_unionall_type, v, body);
}

// --- type instantiation and cache ---

static int typekey_eq(language_datatype_t *tt, language_value_t **key, size_t n)
{
    size_t j;
    // TODO: This shouldn't be necessary
    LANGUAGE_GC_PROMISE_ROOTED(tt);
    size_t tnp = language_nparams(tt);
    if (n != tnp)
        return 0;
    if (tt->name == language_type_typename) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something.
        // this should work because `Type`s don't need unique pointers, and aren't the
        // direct tags of values (concrete) so we don't rely on pointer equality.
        language_value_t *kj = key[0];
        language_value_t *tj = language_tparam0(tt);
        return (kj == tj || (language_typeof(tj) == language_typeof(kj) && language_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        language_value_t *kj = key[j];
        language_value_t *tj = language_svecref(tt->parameters, j);
        if (tj != kj) {
            if (tt->name == language_tuple_typename) {
                // require exact same Type{T} in covariant context. see e.g. issue #22842
                // this should work because `Tuple{Type}`s don't need unique pointers, and aren't the
                // direct tags of values (concrete) so we don't rely on pointer equality.
                if (language_is_type_type(tj) || language_is_type_type(kj))
                    return 0;
            }
            if (language_type_equality_is_identity(tj, kj))
                return 0;
            if (!language_types_equal(tj, kj))
                return 0;
        }
    }
    return 1;
}

// These `value` functions return the same values as the primary functions,
// but operate on the typeof/Typeof each object in an array
static int typekeyvalue_eq(language_datatype_t *tt, language_value_t *key1, language_value_t **key, size_t n, int leaf)
{
    size_t j;
    // TODO: This shouldn't be necessary
    LANGUAGE_GC_PROMISE_ROOTED(tt);
    size_t tnp = language_nparams(tt);
    if (n != tnp)
        return 0;
    if (leaf && tt->name == language_type_typename) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something.
        // this should work because `Type`s don't have uids, and aren't the
        // direct tags of values so we don't rely on pointer equality.
        language_value_t *kj = key1;
        language_value_t *tj = language_tparam0(tt);
        return (kj == tj || (language_typeof(tj) == language_typeof(kj) && language_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        language_value_t *kj = j == 0 ? key1 : key[j - 1];
        language_value_t *tj = language_svecref(tt->parameters, j);
        if (leaf && language_is_type_type(tj)) {
            language_value_t *tp0 = language_tparam0(tj);
            if (!(kj == tp0 || (language_typeof(tp0) == language_typeof(kj) && language_types_equal(tp0, kj))))
                return 0;
        }
        else if (language_typeof(kj) != tj) {
            return 0;
        }
        else if (leaf && language_is_kind(tj)) {
            return 0;
        }
    }
    return 1;
}

static unsigned typekey_hash(language_typename_t *tn, language_value_t **key, size_t n, int nofail) LANGUAGE_NOTSAFEPOINT;
static unsigned typekeyvalue_hash(language_typename_t *tn, language_value_t *key1, language_value_t **key, size_t n, int leaf) LANGUAGE_NOTSAFEPOINT;

/* returns val if key is in hash, otherwise NULL */
static language_datatype_t *lookup_type_set(language_svec_t *cache, language_value_t **key, size_t n, uint_t hv)
{
    size_t sz = language_svec_len(cache);
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(language_datatype_t*) *tab = (_Atomic(language_datatype_t*)*)language_svec_data(cache);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        language_datatype_t *val = language_atomic_load_relaxed(&tab[index]);
        if ((language_value_t*)val == language_nothing)
            return NULL;
        if (val->hash == hv && typekey_eq(val, key, n))
            return val;
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return NULL;
}

/* returns val if key is in hash, otherwise NULL */
static language_datatype_t *lookup_type_setvalue(language_svec_t *cache, language_value_t *key1, language_value_t **key, size_t n, uint_t hv, int leaf)
{
    size_t sz = language_svec_len(cache);
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(language_datatype_t*) *tab = (_Atomic(language_datatype_t*)*)language_svec_data(cache);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        language_datatype_t *val = language_atomic_load_relaxed(&tab[index]);
        if ((language_value_t*)val == language_nothing)
            return NULL;
        if (val->hash == hv && typekeyvalue_eq(val, key1, key, n, leaf))
            return val;
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return NULL;
}

// look up a type in a cache by binary or linear search.
// if found, returns the index of the found item. if not found, returns
// ~n, where n is the index where the type should be inserted.
static ssize_t lookup_type_idx_linear(language_svec_t *cache, language_value_t **key, size_t n)
{
    if (n == 0)
        return -1;
    _Atomic(language_datatype_t*) *data = (_Atomic(language_datatype_t*)*)language_svec_data(cache);
    size_t cl = language_svec_len(cache);
    ssize_t i;
    for (i = 0; i < cl; i++) {
        language_datatype_t *tt = language_atomic_load_relaxed(&data[i]);
        if ((language_value_t*)tt == language_nothing)
            return ~i;
        if (typekey_eq(tt, key, n))
            return i;
    }
    return ~cl;
}

static ssize_t lookup_type_idx_linearvalue(language_svec_t *cache, language_value_t *key1, language_value_t **key, size_t n)
{
    if (n == 0)
        return -1;
    _Atomic(language_datatype_t*) *data = (_Atomic(language_datatype_t*)*)language_svec_data(cache);
    size_t cl = language_svec_len(cache);
    ssize_t i;
    for (i = 0; i < cl; i++) {
        language_datatype_t *tt = language_atomic_load_relaxed(&data[i]);
        if ((language_value_t*)tt == language_nothing)
            return ~i;
        if (typekeyvalue_eq(tt, key1, key, n, 1))
            return i;
    }
    return ~cl;
}

static language_value_t *lookup_type(language_typename_t *tn LANGUAGE_PROPAGATES_ROOT, language_value_t **key, size_t n)
{
    LANGUAGE_TIMING(TYPE_CACHE_LOOKUP, TYPE_CACHE_LOOKUP);
    if (tn == language_type_typename) {
        assert(n == 1);
        language_value_t *uw = language_unwrap_unionall(key[0]);
        if (language_is_datatype(uw) && key[0] == ((language_datatype_t*)uw)->name->wrapper)
            return language_atomic_load_acquire(&((language_datatype_t*)uw)->name->Typeofwrapper);
    }
    unsigned hv = typekey_hash(tn, key, n, 0);
    if (hv) {
        language_svec_t *cache = language_atomic_load_relaxed(&tn->cache);
        return (language_value_t*)lookup_type_set(cache, key, n, hv);
    }
    else {
        language_svec_t *linearcache = language_atomic_load_relaxed(&tn->linearcache);
        ssize_t idx = lookup_type_idx_linear(linearcache, key, n);
        return (idx < 0) ? NULL : language_svecref(linearcache, idx);
    }
}

static language_value_t *lookup_typevalue(language_typename_t *tn, language_value_t *key1, language_value_t **key, size_t n, int leaf)
{
    LANGUAGE_TIMING(TYPE_CACHE_LOOKUP, TYPE_CACHE_LOOKUP);
    unsigned hv = typekeyvalue_hash(tn, key1, key, n, leaf);
    if (hv) {
        language_svec_t *cache = language_atomic_load_relaxed(&tn->cache);
        return (language_value_t*)lookup_type_setvalue(cache, key1, key, n, hv, leaf);
    }
    else {
        assert(leaf);
        language_svec_t *linearcache = language_atomic_load_relaxed(&tn->linearcache);
        ssize_t idx = lookup_type_idx_linearvalue(linearcache, key1, key, n);
        return (idx < 0) ? NULL : language_svecref(linearcache, idx);
    }
}

static int cache_insert_type_set_(language_svec_t *a, language_datatype_t *val, uint_t hv, int atomic)
{
    _Atomic(language_value_t*) *tab = (_Atomic(language_value_t*)*)language_svec_data(a);
    size_t sz = language_svec_len(a);
    if (sz <= 1)
        return 0;
    size_t orig, index, iter;
    iter = 0;
    index = h2index(hv, sz);
    orig = index;
    size_t maxprobe = max_probe(sz);
    do {
        language_value_t *tab_i = language_atomic_load_relaxed(&tab[index]);
        if (tab_i == language_nothing) {
            if (atomic)
                language_atomic_store_release(&tab[index], (language_value_t*)val);
            else
                language_atomic_store_relaxed(&tab[index], (language_value_t*)val);
            language_gc_wb(a, val);
            return 1;
        }
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);

    return 0;
}

static void cache_insert_type_set(language_datatype_t *val, uint_t hv)
{
    language_svec_t *a = language_atomic_load_relaxed(&val->name->cache);
    while (1) {
        LANGUAGE_GC_PROMISE_ROOTED(a);
        if (cache_insert_type_set_(a, val, hv, 1))
            return;

        /* table full */
        /* rehash to grow and retry the insert */
        /* it's important to grow the table really fast; otherwise we waste */
        /* lots of time rehashing all the keys over and over. */
        size_t newsz;
        size_t sz = language_svec_len(a);
        if (sz < HT_N_INLINE)
            newsz = HT_N_INLINE;
        else if (sz >= (1 << 19) || (sz <= (1 << 8)))
            newsz = sz << 1;
        else
            newsz = sz << 2;
        a = cache_rehash_set(a, newsz);
        language_atomic_store_release(&val->name->cache, a);
        language_gc_wb(val->name, a);
    }
}

language_svec_t *cache_rehash_set(language_svec_t *a, size_t newsz)
{
    newsz = newsz ? next_power_of_two(newsz) : 0;
    language_value_t **ol = language_svec_data(a);
    size_t sz = language_svec_len(a);
    while (1) {
        size_t i;
        language_svec_t *newa = language_svec_fill(newsz, language_nothing);
        LANGUAGE_GC_PUSH1(&newa);
        for (i = 0; i < sz; i += 1) {
            language_value_t *val = ol[i];
            if (val != language_nothing) {
                uint_t hv = ((language_datatype_t*)val)->hash;
                if (!cache_insert_type_set_(newa, (language_datatype_t*)val, hv, 0)) {
                    break;
                }
            }
        }
        LANGUAGE_GC_POP();
        if (i == sz)
            return newa;
        newsz <<= 1;
    }
}

static void cache_insert_type_linear(language_datatype_t *type, ssize_t insert_at)
{
    language_svec_t *cache = language_atomic_load_relaxed(&type->name->linearcache);
    assert(language_is_svec(cache));
    size_t n = language_svec_len(cache);
    if (n == 0 || language_svecref(cache, n - 1) != language_nothing) {
        language_svec_t *nc = language_svec_fill(n < 4 ? 4 : n * 2, language_nothing);
        memcpy(language_svec_data(nc), language_svec_data(cache), sizeof(void*) * n);
        language_atomic_store_release(&type->name->linearcache, nc);
        language_gc_wb(type->name, nc);
        cache = nc;
    }
    assert(language_svecref(cache, insert_at) == language_nothing);
    language_svecset(cache, insert_at, (language_value_t*)type); // todo: make this an atomic-store
}

#ifndef NDEBUG
static int is_cacheable(language_datatype_t *type)
{
    // ensure cache only contains types whose behavior will not depend on the
    // identities of contained TypeVars
    return !language_has_free_typevars((language_value_t*)type);
}
#endif


void language_cache_type_(language_datatype_t *type)
{
    LANGUAGE_TIMING(TYPE_CACHE_INSERT, TYPE_CACHE_INSERT);
    assert(is_cacheable(type));
    language_value_t **key = language_svec_data(type->parameters);
    int n = language_svec_len(type->parameters);
    if (type->name == language_type_typename) {
        assert(n == 1);
        language_value_t *uw = language_unwrap_unionall(key[0]);
        if (language_is_datatype(uw) && key[0] == ((language_datatype_t*)uw)->name->wrapper) {
            language_typename_t *tn2 = ((language_datatype_t*)uw)->name;
            language_atomic_store_release(&tn2->Typeofwrapper, (language_value_t*)type);
            language_gc_wb(tn2, type);
            return;
        }
    }
    unsigned hv = typekey_hash(type->name, key, n, 0);
    if (hv) {
        assert(hv == type->hash);
        cache_insert_type_set(type, hv);
    }
    else {
        ssize_t idx = lookup_type_idx_linear(language_atomic_load_relaxed(&type->name->linearcache), key, n);
        assert(idx < 0);
        cache_insert_type_linear(type, ~idx);
    }
}

language_datatype_t *language_lookup_cache_type_(language_datatype_t *type)
{
    assert(is_cacheable(type));
    language_value_t **key = language_svec_data(type->parameters);
    int n = language_svec_len(type->parameters);
    return (language_datatype_t*)lookup_type(type->name, key, n);
}

// compute whether kj might actually be a subtype of something in the cache
// (which otherwise would normally be comparable with pointer-egal)
static int maybe_subtype_of_cache(language_value_t *kj, int covariant) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *uw = language_is_unionall(kj) ? language_unwrap_unionall(kj) : kj;
    if (language_is_datatype(uw)) {
        language_datatype_t *dt = (language_datatype_t*)uw;
        return dt->maybe_subtype_of_cache;
    }
    else if (language_is_uniontype(uw)) {
        int ca = maybe_subtype_of_cache(((language_uniontype_t*)uw)->a, covariant);
        int cb = maybe_subtype_of_cache(((language_uniontype_t*)uw)->b, covariant);
        return ca && cb;
    }
    else if (uw == language_bottom_type) {
        return 1;
    }
    else if (language_is_typevar(uw) && !covariant) { // assume Tuple's bounds are always degenerate
        // TODO: improve this bound if we can prove that typeintersect(lb,ub) is a leaftype
        language_tvar_t *tv = (language_tvar_t*)uw;
        return tv->lb == tv->ub ||
               tv->lb != language_bottom_type;
    }
    return 1;
}

// compute whether kj might have a supertype which is actually concrete
static int has_concrete_supertype(language_value_t *kj) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *uw = language_is_unionall(kj) ? language_unwrap_unionall(kj) : kj;
    if (language_is_datatype(uw)) {
        language_datatype_t *dt = (language_datatype_t*)uw;
        if (dt->name->abstract && dt->name != language_type_typename)
            return 0;
        if (!dt->maybe_subtype_of_cache)
            return 0;
        if (dt->name == language_tuple_typename) {
            // check tuple parameters recursively for has_concrete_supertype
            size_t i, n = language_nparams(dt);
            for (i = 0; i < n; i++) {
                language_value_t *p = language_tparam(dt, i);
                if (language_is_vararg(p))
                    p = language_unwrap_vararg(p);
                if (!has_concrete_supertype(p))
                    return 0;
            }
        }
        return 1;
    }
    else if (language_is_uniontype(uw)) {
        int ca = has_concrete_supertype(((language_uniontype_t*)uw)->a);
        int cb = has_concrete_supertype(((language_uniontype_t*)uw)->b);
        return ca && cb;
    }
    else if (uw == language_bottom_type) {
        return 1;
    }
    else if (language_is_typevar(uw)) {
        language_tvar_t *tv = (language_tvar_t*)uw;
        return has_concrete_supertype(tv->ub);
    }
    return 0;
}

int language_type_equality_is_identity(language_value_t *t1, language_value_t *t2) LANGUAGE_NOTSAFEPOINT
{
    int c1 = language_is_concrete_type(t1);
    int c2 = language_is_concrete_type(t2);
    if (c1 && c2) {
        if (((language_datatype_t*)t1)->name != language_tuple_typename)
            return 1;
        if (((language_datatype_t*)t2)->name != language_tuple_typename)
            return 1;
        if (((language_datatype_t*)t1)->has_concrete_subtype && ((language_datatype_t*)t2)->has_concrete_subtype)
            return 1;
        // e.g. Tuple{Union{}} and Tuple{Int} are both concrete!
    }
    if (c1 && !has_concrete_supertype(t2))
        return 1;
    if (c2 && !has_concrete_supertype(t1))
        return 1;
    return 0;
}

// type instantiation

static int within_typevar(language_value_t *t, language_value_t *vlb, language_value_t *vub)
{
    language_value_t *lb = t, *ub = t;
    if (language_is_typevar(t) || language_has_free_typevars(t)) {
        // TODO: automatically restrict typevars in method definitions based on
        // types they are used in.
        return 1;
        //lb = ((language_tvar_t*)t)->lb;
        //ub = ((language_tvar_t*)t)->ub;
    }
    else if (!language_is_type(t)) {
        return vlb == language_bottom_type && vub == (language_value_t*)language_any_type;
    }
    return ((language_has_free_typevars(vlb) || language_subtype(vlb, lb)) &&
            (language_has_free_typevars(vub) || language_subtype(ub, vub)));
}

struct _language_typestack_t;
typedef struct _language_typestack_t language_typestack_t;

static language_value_t *inst_datatype_inner(language_datatype_t *dt, language_svec_t *p, language_value_t **iparams, size_t ntp,
                                       language_typestack_t *stack, language_typeenv_t *env, int check, int nothrow);

// Build an environment mapping a TypeName's parameters to parameter values.
// This is the environment needed for instantiating a type's supertype and field types.
static language_value_t *inst_datatype_env(language_value_t *dt, language_svec_t *p, language_value_t **iparams, size_t ntp,
                                     language_typestack_t *stack, language_typeenv_t *env, int c)
{
    if (language_is_datatype(dt))
        return inst_datatype_inner((language_datatype_t*)dt, p, iparams, ntp, stack, env, 1, 0);
    assert(language_is_unionall(dt));
    language_unionall_t *ua = (language_unionall_t*)dt;
    language_typeenv_t e = { ua->var, iparams[c], env };
    return inst_datatype_env(ua->body, p, iparams, ntp, stack, &e, c + 1);
}

language_value_t *language_apply_type(language_value_t *tc, language_value_t **params, size_t n)
{
    if (tc == (language_value_t*)language_anytuple_type)
        return language_apply_tuple_type_v(params, n);
    if (tc == (language_value_t*)language_uniontype_type)
        return (language_value_t*)language_type_union(params, n);
    size_t i;
    if (n > 1) {
        // detect common case of applying a wrapper, where we know that all parameters will
        // end up as direct parameters of a certain datatype, which can be optimized.
        language_value_t *u = language_unwrap_unionall(tc);
        if (language_is_datatype(u) && n == language_nparams((language_datatype_t*)u) &&
            ((language_datatype_t*)u)->name->wrapper == tc) {
            return inst_datatype_env(tc, NULL, params, n, NULL, NULL, 0);
        }
    }
    LANGUAGE_GC_PUSH1(&tc);
    language_value_t *tc0 = tc;
    for (i=0; i < n; i++) {
        if (!language_is_unionall(tc0)){
            char *typ = "";
            if (language_is_datatype(tc0))
                typ = language_symbol_name_(((language_datatype_t*)tc0)->name->name);
            language_errorf("too many parameters for type %s", typ);
        }
        language_value_t *pi = params[i];

        tc0 = ((language_unionall_t*)tc0)->body;
        // doing a substitution can cause later UnionAlls to be dropped,
        // as in `NTuple{0,T} where T` => `Tuple{}`. allow values to be
        // substituted for these missing parameters.
        // TODO: figure out how to get back a type error for e.g.
        // S = Tuple{Vararg{T,N}} where T<:NTuple{N} where N
        // S{0,Int}
        if (!language_is_unionall(tc)) continue;

        language_unionall_t *ua = (language_unionall_t*)tc;
        if (!language_has_free_typevars(ua->var->lb) && !language_has_free_typevars(ua->var->ub) &&
            !within_typevar(pi, ua->var->lb, ua->var->ub)) {
            language_datatype_t *inner = (language_datatype_t*)language_unwrap_unionall(tc);
            int iswrapper = 0;
            if (language_is_datatype(inner)) {
                language_value_t *temp = inner->name->wrapper;
                while (language_is_unionall(temp)) {
                    if (temp == tc) {
                        iswrapper = 1;
                        break;
                    }
                    temp = ((language_unionall_t*)temp)->body;
                }
            }
            // if this is a wrapper, let check_datatype_parameters give the error
            if (!iswrapper)
                language_type_error_rt(language_is_datatype(inner) ? language_symbol_name(inner->name->name) : "Type",
                                 language_symbol_name(ua->var->name), (language_value_t*)ua->var, pi);
        }

        tc = language_instantiate_unionall(ua, pi);
    }
    LANGUAGE_GC_POP();
    return tc;
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_type1(language_value_t *tc, language_value_t *p1)
{
    return language_apply_type(tc, &p1, 1);
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_type2(language_value_t *tc, language_value_t *p1, language_value_t *p2)
{
    language_value_t *args[2];
    args[0] = p1;
    args[1] = p2;
    return language_apply_type(tc, args, 2);
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_type3(language_value_t *tc, language_value_t *p1, language_value_t *p2, language_value_t *p3)
{
    language_value_t *args[3];
    args[0] = p1;
    args[1] = p2;
    args[2] = p3;
    return language_apply_type(tc, args, 3);
}

language_datatype_t *language_apply_modify_type(language_value_t *dt)
{
    language_datatype_t *rettyp = (language_datatype_t*)language_apply_type2(language_pair_type, dt, dt);
    LANGUAGE_GC_PROMISE_ROOTED(rettyp); // (LANGUAGE_ALWAYS_LEAFTYPE)
    return rettyp;
}

language_datatype_t *language_apply_cmpswap_type(language_value_t *ty)
{
    language_value_t *params[2];
    language_value_t *names = language_atomic_load_relaxed(&cmpswap_names);
    if (names == NULL) {
        params[0] = (language_value_t*)language_symbol("old");
        params[1] = (language_value_t*)language_symbol("success");
        language_value_t *lnames = language_f_tuple(NULL, params, 2);
        if (language_atomic_cmpswap(&cmpswap_names, &names, lnames))
            names = language_atomic_load_relaxed(&cmpswap_names); // == lnames
    }
    params[0] = ty;
    params[1] = (language_value_t*)language_bool_type;
    language_value_t *tuptyp = language_apply_tuple_type_v(params, 2);
    LANGUAGE_GC_PUSH1(&tuptyp);
    language_datatype_t *rettyp = (language_datatype_t*)language_apply_type2((language_value_t*)language_namedtuple_type, names, tuptyp);
    LANGUAGE_GC_POP();
    return rettyp;
}

LANGUAGE_EXTENSION struct _language_typestack_t {
    language_datatype_t *tt;
    struct _language_typestack_t *prev;
};

static language_value_t *inst_type_w_(language_value_t *t, language_typeenv_t *env, language_typestack_t *stack, int check, int nothrow);
static language_svec_t *inst_ftypes(language_svec_t *p, language_typeenv_t *env, language_typestack_t *stack, int cacheable);

LANGUAGE_DLLEXPORT language_value_t *language_instantiate_unionall(language_unionall_t *u, language_value_t *p)
{
    language_typeenv_t env = { u->var, p, NULL };
    return inst_type_w_(u->body, &env, NULL, 1, 0);
}

language_unionall_t *language_rename_unionall(language_unionall_t *u)
{
    language_tvar_t *v = language_new_typevar(u->var->name, u->var->lb, u->var->ub);
    language_value_t *t = NULL;
    LANGUAGE_GC_PUSH2(&v, &t);
    language_typeenv_t env = { u->var, (language_value_t *)v, NULL };
    t = inst_type_w_(u->body, &env, NULL, 0, 0);
    t = language_new_struct(language_unionall_type, v, t);
    LANGUAGE_GC_POP();
    return (language_unionall_t*)t;
}

language_value_t *language_substitute_var_nothrow(language_value_t *t, language_tvar_t *var, language_value_t *val)
{
    if (val == (language_value_t*)var)
        return t;
    int nothrow = language_is_typevar(val) ? 0 : 1;
    language_typeenv_t env = { var, val, NULL };
    return inst_type_w_(t, &env, NULL, 1, nothrow);
}

language_value_t *language_substitute_var(language_value_t *t, language_tvar_t *var, language_value_t *val)
{
    if (val == (language_value_t*)var)
        return t;
    language_typeenv_t env = { var, val, NULL };
    return inst_type_w_(t, &env, NULL, 1, 0);
}

language_value_t *language_unwrap_unionall(language_value_t *v)
{
    while (language_is_unionall(v))
        v = ((language_unionall_t*)v)->body;
    return v;
}

// wrap `t` in the same unionalls that surround `u`
// where `t` is derived from `u`, so the error checks in language_type_unionall are unnecessary
language_value_t *language_rewrap_unionall(language_value_t *t, language_value_t *u)
{
    if (!language_is_unionall(u))
        return t;
    t = language_rewrap_unionall(t, ((language_unionall_t*)u)->body);
    language_tvar_t *v = ((language_unionall_t*)u)->var;
    // normalize `T where T<:S` => S
    if (t == (language_value_t*)v)
        return v->ub;
    // where var doesn't occur in body just return body
    if (!language_has_typevar(t, v))
        return t;
    LANGUAGE_GC_PUSH1(&t);
    //if (v->lb == v->ub)  // TODO maybe
    //    t = language_substitute_var(body, v, v->ub);
    //else
    t = language_new_struct(language_unionall_type, v, t);
    LANGUAGE_GC_POP();
    return t;
}

// wrap `t` in the same unionalls that surround `u`
// where `t` is extended from `u`, so the checks in language_rewrap_unionall are unnecessary
language_value_t *language_rewrap_unionall_(language_value_t *t, language_value_t *u)
{
    if (!language_is_unionall(u))
        return t;
    t = language_rewrap_unionall_(t, ((language_unionall_t*)u)->body);
    LANGUAGE_GC_PUSH1(&t);
    t = language_new_struct(language_unionall_type, ((language_unionall_t*)u)->var, t);
    LANGUAGE_GC_POP();
    return t;
}

static language_value_t *lookup_type_stack(language_typestack_t *stack, language_datatype_t *tt, size_t ntp,
                                     language_value_t **iparams)
{
    // if an identical instantiation is already in process somewhere up the
    // stack, return it. this computes a fixed point for recursive types.
    language_typename_t *tn = tt->name;
    while (stack != NULL) {
        LANGUAGE_GC_PROMISE_ROOTED(stack->tt);
        if (stack->tt->name == tn &&
            ntp == language_svec_len(stack->tt->parameters) &&
            typekey_eq(stack->tt, iparams, ntp)) {
            return (language_value_t*)stack->tt;
        }
        stack = stack->prev;
    }
    return NULL;
}

// stable numbering for types--starts with name->hash, then falls back to objectid
// sets *failed if the hash value isn't stable (if this param not set on entry)
static unsigned type_hash(language_value_t *kj, int *failed) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *uw = language_is_unionall(kj) ? language_unwrap_unionall(kj) : kj;
    if (language_is_datatype(uw)) {
        language_datatype_t *dt = (language_datatype_t*)uw;
        unsigned hash = dt->hash;
        if (!hash) {
            if (!*failed) {
                *failed = 1;
                return 0;
            }
            // compute a hash now, only for the parent object we are putting in the cache
            hash = typekey_hash(dt->name, language_svec_data(dt->parameters), language_svec_len(dt->parameters), *failed);
        }
        return hash;
    }
    else if (language_is_typevar(uw)) {
        // ignore var and lb, since those might get normalized out in equality testing
        return type_hash(((language_tvar_t*)uw)->ub, failed);
    }
    else if (language_is_uniontype(uw)) {
        if (!*failed) {
            *failed = 1;
            return 0;
        }
        // compute a hash now, only for the parent object we are putting in the cache
        unsigned hasha = type_hash(((language_uniontype_t*)uw)->a, failed);
        unsigned hashb = type_hash(((language_uniontype_t*)uw)->b, failed);
        // use a associative mixing function, with well-defined overflow
        // since Union is associative
        return hasha + hashb;
    }
    else {
        return language_object_id(uw);
    }
}

LANGUAGE_DLLEXPORT uintptr_t language_type_hash(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    // NOTE: The value of `failed` is purposefully ignored here. The parameter is relevant
    // for other parts of the internal algorithm but not for exposing to the Julia side.
    int failed = 0;
    return type_hash(v, &failed);
}

static unsigned typekey_hash(language_typename_t *tn, language_value_t **key, size_t n, int nofail) LANGUAGE_NOTSAFEPOINT
{
    if (tn == language_type_typename && key[0] == language_bottom_type)
        return language_typeofbottom_type->hash;
    size_t j;
    unsigned hash = 3;
    int failed = nofail;
    for (j = 0; j < n; j++) {
        language_value_t *p = key[j];
        size_t repeats = 1;
        if (language_is_vararg(p)) {
            language_vararg_t *vm = (language_vararg_t*)p;
            if (vm->N && language_is_long(vm->N))
                repeats = language_unbox_long(vm->N);
            else
                hash = bitmix(0x064eeaab, hash); // 0x064eeaab is just a randomly chosen constant
            p = vm->T ? vm->T : (language_value_t*)language_any_type;
        }
        unsigned hashp = type_hash(p, &failed);
        if (failed && !nofail)
            return 0;
        while (repeats--)
            hash = bitmix(hashp, hash);
    }
    hash = bitmix(~tn->hash, hash);
    return hash ? hash : 1;
}

static unsigned typekeyvalue_hash(language_typename_t *tn, language_value_t *key1, language_value_t **key, size_t n, int leaf) LANGUAGE_NOTSAFEPOINT
{
    size_t j;
    unsigned hash = 3;
    for (j = 0; j < n; j++) {
        language_value_t *kj = j == 0 ? key1 : key[j - 1];
        uint_t hj;
        if (leaf && language_is_kind(language_typeof(kj))) {
            hj = typekey_hash(language_type_typename, &kj, 1, 0);
            if (hj == 0)
                return 0;
        }
        else {
            hj = ((language_datatype_t*)language_typeof(kj))->hash;
        }
        hash = bitmix(hj, hash);
    }
    hash = bitmix(~tn->hash, hash);
    return hash ? hash : 1;
}

void language_precompute_memoized_dt(language_datatype_t *dt, int cacheable)
{
    int istuple = (dt->name == language_tuple_typename);
    dt->hasfreetypevars = 0;
    dt->maybe_subtype_of_cache = 1;
    dt->isconcretetype = !dt->name->abstract;
    dt->isdispatchtuple = istuple;
    size_t i, l = language_nparams(dt);
    for (i = 0; i < l; i++) {
        language_value_t *p = language_tparam(dt, i);
        if (!dt->hasfreetypevars) {
            dt->hasfreetypevars = language_has_free_typevars(p);
            if (dt->hasfreetypevars)
                dt->isconcretetype = 0;
        }
        if (istuple) {
            if (dt->isconcretetype)
                dt->isconcretetype = (language_is_datatype(p) && ((language_datatype_t*)p)->isconcretetype) || p == language_bottom_type;
            if (dt->isdispatchtuple) {
                dt->isdispatchtuple = language_is_datatype(p) &&
                    ((!language_is_kind(p) && ((language_datatype_t*)p)->isconcretetype) ||
                     (p == (language_value_t*)language_typeofbottom_type) || // == Type{Union{}}, so needs to be consistent
                     (((language_datatype_t*)p)->name == language_type_typename && !((language_datatype_t*)p)->hasfreetypevars));
            }
        }
        if (language_is_vararg(p))
            p = ((language_vararg_t*)p)->T;
        if (istuple && dt->has_concrete_subtype) {
            // tuple types like Tuple{:x} and Tuple{Union{}} cannot have instances
            if (p && !language_is_type(p) && !language_is_typevar(p))
                dt->has_concrete_subtype = 0;
            if (p == language_bottom_type)
                dt->has_concrete_subtype = 0;
        }
        if (dt->maybe_subtype_of_cache) {
            dt->maybe_subtype_of_cache = !p || maybe_subtype_of_cache(p, istuple) || !language_has_free_typevars(p);
        }
    }
    assert(dt->isconcretetype || dt->isdispatchtuple ? dt->maybe_subtype_of_cache : 1);
    if (dt->name == language_type_typename) {
        language_value_t *p = language_tparam(dt, 0);
        if (!language_is_type(p) && !language_is_typevar(p)) // Type{v} has no subtypes, if v is not a Type
            dt->has_concrete_subtype = 0;
        dt->maybe_subtype_of_cache = 1;
        language_value_t *uw = language_unwrap_unionall(p);
        // n.b. the cache for Type ignores parameter normalization except for Typeofwrapper, so it can't be used to make a stable hash value
        if (!language_is_datatype(uw) || ((language_datatype_t*)uw)->name->wrapper != p)
            cacheable = 0;
    }
    dt->hash = typekey_hash(dt->name, language_svec_data(dt->parameters), l, cacheable);
}

static void check_datatype_parameters(language_typename_t *tn, language_value_t **params, size_t np)
{
    language_value_t *wrapper = tn->wrapper;
    language_value_t **bounds;
    LANGUAGE_GC_PUSHARGS(bounds, np*2);
    int i = 0;
    while (language_is_unionall(wrapper)) {
        language_tvar_t *tv = ((language_unionall_t*)wrapper)->var;
        bounds[i++] = tv->lb;
        bounds[i++] = tv->ub;
        wrapper = ((language_unionall_t*)wrapper)->body;
    }
    assert(i == np*2);
    wrapper = tn->wrapper;
    for (i = 0; i < np; i++) {
        assert(language_is_unionall(wrapper));
        language_tvar_t *tv = ((language_unionall_t*)wrapper)->var;
        if (!within_typevar(params[i], bounds[2*i], bounds[2*i+1])) {
            if (tv->lb != bounds[2*i] || tv->ub != bounds[2*i+1])
                // pass a new version of `tv` containing the instantiated bounds
                tv = language_new_typevar(tv->name, bounds[2*i], bounds[2*i+1]);
            LANGUAGE_GC_PUSH1(&tv);
            language_type_error_rt(language_symbol_name(tn->name), language_symbol_name(tv->name), (language_value_t*)tv, params[i]);
        }
        int j;
        for (j = 2*i + 2; j < 2*np; j++) {
            language_value_t *bj = bounds[j];
            if (bj != (language_value_t*)language_any_type && bj != language_bottom_type)
                bounds[j] = language_substitute_var(bj, tv, params[i]);
        }
        wrapper = ((language_unionall_t*)wrapper)->body;
    }
    LANGUAGE_GC_POP();
}

static language_value_t *extract_wrapper(language_value_t *t LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT LANGUAGE_GLOBALLY_ROOTED
{
    t = language_unwrap_unionall(t);
    if (language_is_datatype(t))
        return ((language_datatype_t*)t)->name->wrapper;
    if (language_is_uniontype(t)) {
        language_value_t *n1 = extract_wrapper(((language_uniontype_t*)t)->a);
        if (n1 != NULL) return n1;
        return extract_wrapper(((language_uniontype_t*)t)->b);
    }
    if (language_is_typevar(t))
        return extract_wrapper(((language_tvar_t*)t)->ub);
    return NULL;
}

static int _may_substitute_ub(language_value_t *v, language_tvar_t *var, int inside_inv, int *cov_count) LANGUAGE_NOTSAFEPOINT
{
    while (1) {
        if (v == (language_value_t*)var) {
            if (inside_inv) {
                return 0;
            }
            else {
                (*cov_count)++;
                return *cov_count <= 1 || language_is_concrete_type(var->ub);
            }
        }
        while (language_is_unionall(v)) {
            language_unionall_t *ua = (language_unionall_t*)v;
            if (ua->var == var)
                return 1;
            if (ua->var->lb != language_bottom_type && !_may_substitute_ub(ua->var->lb, var, inside_inv, cov_count))
                return 0;
            if (ua->var->ub != (language_value_t*)language_any_type && !_may_substitute_ub(ua->var->ub, var, inside_inv, cov_count))
                return 0;
            v = ua->body;
        }
        if (language_is_datatype(v)) {
            int invar = inside_inv || !language_is_tuple_type(v);
            for (size_t i = 0; i < language_nparams(v); i++) {
                if (!_may_substitute_ub(language_tparam(v, i), var, invar, cov_count))
                    return 0;
            }
            return 1;
        }
        else if (language_is_uniontype(v)) {
            // TODO: is !inside_inv, these don't have to share the changes to cov_count
            if (!_may_substitute_ub(((language_uniontype_t*)v)->a, var, inside_inv, cov_count))
                return 0;
            v = ((language_uniontype_t*)v)->b;
        }
        else if (language_is_vararg(v)) {
            language_vararg_t *va = (language_vararg_t*)v;
            if (!va->T)
                return 1;
            if (va->N && !_may_substitute_ub(va->N, var, 1, cov_count))
                return 0;
            if (!language_is_concrete_type(var->ub))
                inside_inv = 1; // treat as invariant inside vararg, for the sake of this algorithm
            v = va->T;
        }
        else {
            return 1;
        }
    }
}

// Check whether `var` may be replaced with its upper bound `ub` in `v where var<:ub`
// Conditions:
//  * `var` does not appear in invariant position
//  * `var` appears at most once (in covariant position) and not in a `Vararg`
//    unless the upper bound is concrete (diagonal rule)
static int may_substitute_ub(language_value_t *v, language_tvar_t *var) LANGUAGE_NOTSAFEPOINT
{
    int cov_count = 0;
    return _may_substitute_ub(v, var, 0, &cov_count);
}

static language_value_t *normalize_unionalls(language_value_t *t)
{
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        language_value_t *a = NULL;
        language_value_t *b = NULL;
        LANGUAGE_GC_PUSH2(&a, &b);
        a = normalize_unionalls(u->a);
        b = normalize_unionalls(u->b);
        if (a != u->a || b != u->b) {
            t = language_new_struct(language_uniontype_type, a, b);
        }
        LANGUAGE_GC_POP();
    }
    else if (language_is_unionall(t)) {
        language_unionall_t *u = (language_unionall_t*)t;
        language_value_t *body = normalize_unionalls(u->body);
        LANGUAGE_GC_PUSH2(&body, &t);
        if (body != u->body) {
            t = language_new_struct(language_unionall_type, u->var, body);
            u = (language_unionall_t*)t;
        }

        if (u->var->lb == u->var->ub || may_substitute_ub(body, u->var)) {
            body = (language_value_t*)u;
            LANGUAGE_TRY {
                t = language_instantiate_unionall(u, u->var->ub);
            }
            LANGUAGE_CATCH {
                // just skip normalization
                // (may happen for bounds inconsistent with the wrapper's bounds)
            }
        }
        LANGUAGE_GC_POP();
    }
    return t;
}

// used to expand an NTuple to a flat representation
static language_value_t *language_tupletype_fill(size_t n, language_value_t *t, int check, int nothrow)
{
    language_value_t *p = NULL;
    LANGUAGE_GC_PUSH1(&p);
    if (check) {
        // Since we are skipping making the Vararg and skipping checks later,
        // we inline the checks from language_wrap_vararg here now
        if (!language_valid_type_param(t)) {
            if (nothrow) {
                LANGUAGE_GC_POP();
                return NULL;
            }
            language_type_error_rt("Vararg", "type", (language_value_t*)language_type_type, t);
        }
        // language_wrap_vararg sometimes simplifies the type, so we only do this 1 time, instead of for each n later
        t = normalize_unionalls(t);
        p = t;
        language_value_t *tw = extract_wrapper(t);
        if (tw && t != tw && language_types_equal(t, tw))
            t = tw;
        p = t;
        check = 0; // remember that checks are already done now
    }
    p = (language_value_t*)language_svec_fill(n, t);
    p = language_apply_tuple_type((language_svec_t*)p, check);
    LANGUAGE_GC_POP();
    return p;
}

static language_value_t *_language_instantiate_type_in_env(language_value_t *ty, language_unionall_t *env, language_value_t **vals, language_typeenv_t *prev, language_typestack_t *stack);

static language_value_t *inst_datatype_inner(language_datatype_t *dt, language_svec_t *p, language_value_t **iparams, size_t ntp,
                                       language_typestack_t *stack, language_typeenv_t *env, int check, int nothrow)
{
    language_typestack_t top;
    language_typename_t *tn = dt->name;
    int istuple = (tn == language_tuple_typename);
    int isnamedtuple = (tn == language_namedtuple_typename);

    // check if type cache will be applicable
    int cacheable = 1;
    if (istuple) {
        size_t i;
        for (i = 0; i < ntp; i++) {
            language_value_t *pi = iparams[i];
            if (language_is_vararg(pi) && language_unwrap_vararg(pi) == language_bottom_type) {
                language_value_t *va1 = language_unwrap_vararg_num(pi);
                if (va1 && language_is_long(va1)) {
                    ssize_t nt = language_unbox_long(va1);
                    if (nt == 0)
                        va1 = NULL;
                    else
                        pi = language_bottom_type; // trigger errorf below
                }
                // This imposes an implicit constraint that va1==0,
                // so we keep the Vararg if it has a TypeVar
                if (va1 == NULL) {
                    p = NULL;
                    ntp -= 1;
                    assert(i == ntp);
                    break;
                }
            }
            if (pi == language_bottom_type) {
                if (nothrow)
                    return NULL;
                language_errorf("Tuple field type cannot be Union{}");
            }
            if (cacheable && !language_is_concrete_type(pi))
                cacheable = 0;
        }
    }
    else {
        size_t i;
        for (i = 0; cacheable && i < ntp; i++)
            if (language_has_free_typevars(iparams[i]))
                cacheable = 0;
    }
    // if applicable, check the cache first for a match
    if (cacheable) {
        language_value_t *lkup = (language_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL)
            return lkup;
    }
    // if some normalization might be needed, do that now
    // it is probably okay to mutate iparams, and we only store globally rooted objects here
    if (check) {
        size_t i;
        for (i = 0; i < ntp; i++) {
            language_value_t *pi = iparams[i];
            if (pi == language_bottom_type)
                continue;
            if (language_is_datatype(pi))
                continue;
            if (language_is_vararg(pi))
                // This is already handled in language_wrap_vararg instead
                continue;
            if (!cacheable && language_has_free_typevars(pi))
                continue;
            // normalize types equal to wrappers (prepare for Typeofwrapper)
            language_value_t *tw = extract_wrapper(pi);
            if (tw && tw != pi && (tn != language_type_typename || language_typeof(pi) == language_typeof(tw)) &&
                    language_types_equal(pi, tw)) {
                iparams[i] = tw;
                if (p) language_gc_wb(p, tw);
            }
        }
        if (tn == language_type_typename && language_is_datatype(iparams[0]) && ((language_datatype_t*)iparams[0])->name == language_type_typename &&
            language_tparam0(iparams[0]) == language_bottom_type) {
            // normalize Type{Type{Union{}}} to Type{TypeofBottom}
            iparams[0] = (language_value_t*)language_typeofbottom_type;
        }
    }
    // then check the cache again, if applicable
    if (cacheable) {
        language_value_t *lkup = (language_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL)
            return lkup;
    }
    language_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
    if (stack_lkup)
        return stack_lkup;

    // check parameters against bounds in type definition
    // for whether this is even valid
    if (check && !istuple) {
        assert(ntp > 0);
        LANGUAGE_TRY {
            check_datatype_parameters(tn, iparams, ntp);
        }
        LANGUAGE_CATCH {
            if (!nothrow) language_rethrow();
            return NULL;
        }
    }
    else if (ntp == 0 && language_emptytuple_type != NULL) {
        // empty tuple type case
        assert(istuple);
        return (language_value_t*)language_emptytuple_type;
    }

    language_datatype_t *ndt = NULL;
    LANGUAGE_GC_PUSH2(&p, &ndt);

    language_value_t *last = iparams[ntp - 1];
    if (istuple && ntp > 0 && language_is_vararg(last)) {
        // normalize Tuple{..., Vararg{Int, 3}} to Tuple{..., Int, Int, Int}
        language_value_t *va = language_unwrap_unionall(last);
        language_value_t *va0 = language_unwrap_vararg(va), *va1 = language_unwrap_vararg_num(va);
        // return same `Tuple` object for types equal to it
        if (ntp == 1 && va0 == (language_value_t*)language_any_type && !va1) {
            LANGUAGE_GC_POP();
            return (language_value_t*)language_anytuple_type;
        }
        if (va1 && language_is_long(va1)) {
            ssize_t nt = language_unbox_long(va1);
            assert(nt >= 0);
            if (nt == 0 || !language_has_free_typevars(va0)) {
                if (ntp == 1) {
                    LANGUAGE_GC_POP();
                    return language_tupletype_fill(nt, va0, 0, 0);
                }
                size_t i, l;
                p = language_alloc_svec(ntp - 1 + nt);
                for (i = 0, l = ntp - 1; i < l; i++)
                    language_svecset(p, i, iparams[i]);
                l = ntp - 1 + nt;
                for (; i < l; i++)
                    language_svecset(p, i, va0);
                size_t np = language_svec_len(p);
                language_value_t **pp = language_svec_data(p);
                language_value_t *ndt = inst_datatype_inner(language_anytuple_type, p, pp, np, NULL, NULL, check, nothrow);
                LANGUAGE_GC_POP();
                return ndt;
            }
        }
    }

    // try to simplify some type parameters
    if (check && tn != language_type_typename) {
        int changed = 0;
        if (istuple) // normalization might change Tuple's, but not other types's, cacheable status
            cacheable = 1;
        size_t i;
        for (i = 0; i < ntp; i++) {
            language_value_t *pi = iparams[i];
            language_value_t *newp = normalize_unionalls(pi);
            if (newp != pi) {
                iparams[i] = newp;
                if (p) language_gc_wb(p, newp);
                changed = 1;
            }
            if (istuple && cacheable && !language_is_concrete_type(newp))
                cacheable = 0;
        }
        if (changed) {
            // If this changed something, we need to check the cache again, in
            // case we missed the match earlier before the normalizations
            //
            // e.g. return inst_datatype_inner(dt, p, iparams, ntp, stack, env, 0);
            if (cacheable) {
                language_value_t *lkup = (language_value_t*)lookup_type(tn, iparams, ntp);
                if (lkup != NULL) {
                    LANGUAGE_GC_POP();
                    return lkup;
                }
            }
            language_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
            if (stack_lkup) {
                LANGUAGE_GC_POP();
                return stack_lkup;
            }
        }
    }

    // try to reduce duplication in objects (if the caller didn't already check) by
    // comparing them against a list of objects already known to be globally rooted and
    // swapping them as possible
    if (check && language_global_roots_list != NULL) {
        for (size_t i = 0; i < ntp; i++) {
            language_value_t *pi = iparams[i];
            if (cacheable || !language_has_free_typevars(pi)) {
                pi = language_as_global_root(pi, cacheable);
                if (pi != NULL) {
                    iparams[i] = pi;
                    if (p) language_gc_wb(p, pi);
                }
            }
        }
    }

    // move array of instantiated parameters to heap; we need to keep it
    if (p == NULL) {
        p = language_alloc_svec_uninit(ntp);
        for (size_t i = 0; i < ntp; i++) {
            language_svecset(p, i, iparams[i]);
        }
    }

    ndt = language_new_uninitialized_datatype();

    // now that most allocations are done
    // acquire the write lock now that we know we need a new object
    // since we're going to immediately leak it globally via the instantiation stack
    if (cacheable) {
        LANGUAGE_LOCK(&typecache_lock); // Might GC
        language_value_t *lkup = (language_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup) {
            LANGUAGE_UNLOCK(&typecache_lock); // Might GC
            LANGUAGE_GC_POP();
            return lkup;
        }
    }

    // create and initialize new type
    ndt->isprimitivetype = dt->isprimitivetype;
    // Usually dt won't have ismutationfree set at this point, but it is
    // overridden for `Type`, which we handle here.
    ndt->ismutationfree = dt->ismutationfree;
    // associate these parameters with the new type on
    // the stack, in case one of its field types references it.
    top.tt = (language_datatype_t*)ndt;
    top.prev = stack;
    stack = &top;
    ndt->name = tn;
    language_gc_wb(ndt, ndt->name);
    ndt->super = NULL;
    ndt->parameters = p;
    language_gc_wb(ndt, ndt->parameters);
    ndt->types = NULL; // to be filled in below
    int invalid = 0;
    if (istuple) {
        ndt->types = p; // TODO: this may need to filter out certain types
    }
    else if (isnamedtuple) {
        language_value_t *names_tup = language_svecref(p, 0);
        language_value_t *values_tt = language_svecref(p, 1);
        if (!language_has_free_typevars(names_tup) && !language_has_free_typevars(values_tt)) {
            if (!language_is_tuple(names_tup)) {
                if (!nothrow)
                    language_type_error_rt("NamedTuple", "names", (language_value_t*)language_anytuple_type, names_tup);
                invalid = 1;
            }
            size_t nf = language_nfields(names_tup);
            for (size_t i = 0; i < nf; i++) {
                language_value_t *ni = language_fieldref(names_tup, i);
                if (!language_is_symbol(ni)) {
                    if (!nothrow)
                        language_type_error_rt("NamedTuple", "name", (language_value_t*)language_symbol_type, ni);
                    invalid = 1; break;
                }
                for (size_t j = 0; j < i; j++) {
                    if (ni == language_fieldref_noalloc(names_tup, j)) {
                        if (!nothrow)
                            language_errorf("duplicate field name in NamedTuple: \"%s\" is not unique", language_symbol_name((language_sym_t*)ni));
                        invalid = 1; break;
                    }
                }
                if (invalid) break;
            }
            if (values_tt == language_bottom_type && nf > 0) {
                ndt->types = language_svec_fill(nf, language_bottom_type);
            }
            else {
                if (!language_is_datatype(values_tt)) {
                    // should have been checked within `check_datatype_parameters`.
                    language_error("NamedTuple field type must be a tuple datatype");
                }
                if (language_is_va_tuple((language_datatype_t*)values_tt) || language_nparams(values_tt) != nf) {
                    if (!nothrow)
                        language_error("NamedTuple names and field types must have matching lengths");
                    invalid = 1;
                }
                ndt->types = ((language_datatype_t*)values_tt)->parameters;
            }
            language_gc_wb(ndt, ndt->types);
        }
        else {
            ndt->types = language_emptysvec; // XXX: this is essentially always incorrect
        }
    }
    else if (tn == language_genericmemoryref_typename || tn == language_genericmemory_typename) {
        language_value_t *isatomic = language_svecref(p, 0);
        if (!language_is_typevar(isatomic) && !language_is_symbol(isatomic)) {
            if (!nothrow)
                language_type_error_rt("GenericMemory", "isatomic parameter", (language_value_t*)language_symbol_type, isatomic);
            invalid = 1;
        }
        language_value_t *addrspace = language_svecref(p, 2);
        if (!language_is_typevar(addrspace) && !language_is_addrspace(addrspace)) {
            if (!nothrow)
                language_type_error_rt("GenericMemory", "addrspace parameter", (language_value_t*)language_addrspace_type, addrspace);
            invalid = 1;
        }
    }

    if (nothrow && invalid) {
        if (cacheable)
            LANGUAGE_UNLOCK(&typecache_lock);
        LANGUAGE_GC_POP();
        return NULL;
    }
    language_datatype_t *primarydt = ((language_datatype_t*)language_unwrap_unionall(tn->wrapper));
    language_precompute_memoized_dt(ndt, cacheable);
    if (primarydt->layout)
        language_compute_field_offsets(ndt);

    if (istuple || isnamedtuple) {
        ndt->super = language_any_type;
    }
    else if (dt->super) {
        language_value_t *super = inst_type_w_((language_value_t*)dt->super, env, stack, check, nothrow);
        if (nothrow && super == NULL) {
            if (cacheable)
                LANGUAGE_UNLOCK(&typecache_lock);
            LANGUAGE_GC_POP();
            return NULL;
        }
        ndt->super = (language_datatype_t *)super;
        language_gc_wb(ndt, ndt->super);
    }
    language_svec_t *ftypes = dt->types;
    if (ftypes == NULL)
        ftypes = primarydt->types;
    if (ftypes == NULL || dt->super == NULL) {
        // in the process of creating this type definition:
        // need to instantiate the super and types fields later
        if (tn->partial == NULL) {
            tn->partial = language_alloc_vec_any(0);
            language_gc_wb(tn, tn->partial);
        }
        language_array_ptr_1d_push(tn->partial, (language_value_t*)ndt);
    }
    else if (!isnamedtuple && !istuple) {
        assert(ftypes != language_emptysvec || language_field_names(ndt) == language_emptysvec);
        assert(ftypes == language_emptysvec || !ndt->name->abstract);
        if (ftypes == language_emptysvec) {
            ndt->types = ftypes;
        }
        else if (cacheable) {
            // recursively instantiate the types of the fields
            if (dt->types == NULL)
                ndt->types = language_compute_fieldtypes(ndt, stack, cacheable);
            else
                ndt->types = inst_ftypes(ftypes, env, stack, cacheable);
            language_gc_wb(ndt, ndt->types);
        }
    }

    // now publish the finished result
    // XXX: if the stack was used, this will publish in the wrong order,
    // leading to incorrect layouts and data races (#40050: the A{T} should be
    // an isbitstype singleton of size 0)
    if (cacheable) {
        if (ndt->layout == NULL && ndt->types != NULL && ndt->isconcretetype)
            language_compute_field_offsets(ndt);
        language_cache_type_(ndt);
        LANGUAGE_UNLOCK(&typecache_lock); // Might GC
    }

    LANGUAGE_GC_POP();
    return (language_value_t*)ndt;
}

static language_value_t *language_apply_tuple_type_v_(language_value_t **p, size_t np, language_svec_t *params, int check)
{
    return inst_datatype_inner(language_anytuple_type, params, p, np, NULL, NULL, check, 0);
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_tuple_type(language_svec_t *params, int check)
{
    return language_apply_tuple_type_v_(language_svec_data(params), language_svec_len(params), params, check);
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_tuple_type_v(language_value_t **p, size_t np)
{
    return language_apply_tuple_type_v_(p, np, NULL, 1);
}

language_tupletype_t *language_lookup_arg_tuple_type(language_value_t *arg1, language_value_t **args, size_t nargs, int leaf)
{
    return (language_datatype_t*)lookup_typevalue(language_tuple_typename, arg1, args, nargs, leaf);
}

language_tupletype_t *language_inst_arg_tuple_type(language_value_t *arg1, language_value_t **args, size_t nargs, int leaf)
{
    language_tupletype_t *tt = (language_datatype_t*)lookup_typevalue(language_tuple_typename, arg1, args, nargs, leaf);
    if (tt == NULL) {
        size_t i;
        language_svec_t *params = language_alloc_svec(nargs);
        LANGUAGE_GC_PUSH1(&params);
        for (i = 0; i < nargs; i++) {
            language_value_t *ai = (i == 0 ? arg1 : args[i - 1]);
            if (leaf && language_is_type(ai)) {
                // if `ai` has free type vars this will not be a valid (concrete) type.
                // TODO: it would be really nice to only dispatch and cache those as
                // `language_typeof(ai)`, but that will require some redesign of the caching
                // logic.
                ai = (language_value_t*)language_wrap_Type(ai);
            }
            else {
                ai = language_typeof(ai);
            }
            language_svecset(params, i, ai);
        }
        tt = (language_datatype_t*)inst_datatype_inner(language_anytuple_type, params, language_svec_data(params), nargs, NULL, NULL, 1, 0);
        LANGUAGE_GC_POP();
    }
    return tt;
}

static language_svec_t *inst_ftypes(language_svec_t *p, language_typeenv_t *env, language_typestack_t *stack, int cacheable)
{
    size_t i;
    size_t lp = language_svec_len(p);
    language_svec_t *np = language_alloc_svec(lp);
    language_value_t *pi = NULL;
    LANGUAGE_GC_PUSH2(&np, &pi);
    for (i = 0; i < lp; i++) {
        pi = language_svecref(p, i);
        LANGUAGE_TRY {
            pi = inst_type_w_(pi, env, stack, 1, 0);
            if (!language_is_type(pi) && !language_is_typevar(pi)) {
                pi = language_bottom_type;
            }
        }
        LANGUAGE_CATCH {
            pi = language_bottom_type;
        }
        language_value_t *globalpi = language_as_global_root(pi, cacheable);
        language_svecset(np, i, globalpi ? globalpi : pi);
    }
    LANGUAGE_GC_POP();
    return np;
}

static language_value_t *inst_tuple_w_(language_value_t *t, language_typeenv_t *env, language_typestack_t *stack, int check, int nothrow)
{
    language_datatype_t *tt = (language_datatype_t*)t;
    language_svec_t *tp = tt->parameters;
    size_t ntp = language_svec_len(tp);
    // Instantiate Tuple{Vararg{T,N}} where T is fixed and N is known, such as Dims{3}
    // And avoiding allocating the intermediate steps
    // Note this does not instantiate Tuple{Vararg{Int,3}}; that's done in inst_datatype_inner
    // Note this does not instantiate NTuple{N,T}, since it is unnecessary and inefficient to expand that now
    if (language_is_va_tuple(tt) && ntp == 1) {
        // If this is a Tuple{Vararg{T,N}} with known N and T, expand it to
        // a fixed-length tuple
        language_value_t *T=NULL, *N=NULL;
        language_value_t *va = language_tparam0(tt);
        language_value_t *ttT = language_unwrap_vararg(va);
        language_value_t *ttN = language_unwrap_vararg_num(va);
        language_typeenv_t *e = env;
        while (e != NULL) {
            if ((language_value_t*)e->var == ttT)
                T = e->val;
            else if ((language_value_t*)e->var == ttN)
                N = e->val;
            e = e->prev;
        }
        if (T != NULL && N != NULL && language_is_long(N)) { // TODO: && !language_has_free_typevars(T) to match inst_datatype_inner, or even && language_is_concrete_type(T)
            // Since this is skipping language_wrap_vararg, we inline the checks from it here
            ssize_t nt = language_unbox_long(N);
            if (nt >= 0)
                return language_tupletype_fill(nt, T, check, nothrow);
            if (nothrow)
                return NULL;
            language_errorf("Vararg length is negative: %zd", nt);
        }
    }
    language_value_t **iparams;
    int onstack = ntp < language_page_size/sizeof(language_value_t*);
    LANGUAGE_GC_PUSHARGS(iparams, onstack ? ntp : 1);
    language_svec_t *ip_heap = NULL;
    if (!onstack) {
        ip_heap = language_alloc_svec(ntp);
        iparams[0] = (language_value_t*)ip_heap;
        iparams = language_svec_data(ip_heap);
    }
    int i, bound = 0;
    for (i = 0; i < ntp; i++) {
        language_value_t *elt = language_svecref(tp, i);
        language_value_t *pi = inst_type_w_(elt, env, stack, check, nothrow);
        if (pi == NULL) {
            if (i == ntp-1 && language_is_vararg(elt)) {
                t = NULL;
                break;
            }
            else {
                pi = language_bottom_type;
            }
        }
        iparams[i] = pi;
        if (ip_heap)
            language_gc_wb(ip_heap, pi);
        bound |= (pi != elt);
    }
    if (t != NULL && bound)
        t = inst_datatype_inner(tt, ip_heap, iparams, ntp, stack, env, check, nothrow);
    LANGUAGE_GC_POP();
    return t;
}

static language_value_t *inst_type_w_(language_value_t *t, language_typeenv_t *env, language_typestack_t *stack, int check, int nothrow)
{
    size_t i;
    if (language_is_typevar(t)) {
        language_typeenv_t *e = env;
        while (e != NULL) {
            if (e->var == (language_tvar_t*)t) {
                language_value_t *val = e->val;
                return val;
            }
            e = e->prev;
        }
        return t;
    }
    if (language_is_unionall(t)) {
        language_unionall_t *ua = (language_unionall_t*)t;
        language_value_t *lb = NULL;
        language_value_t *var = NULL;
        language_value_t *newbody = NULL;
        LANGUAGE_GC_PUSH3(&lb, &var, &newbody);
        LANGUAGE_TRY {
            lb = inst_type_w_(ua->var->lb, env, stack, check, 0);
        }
        LANGUAGE_CATCH {
            if (!nothrow) language_rethrow();
            t = NULL;
        }
        if (t != NULL) {
            var = inst_type_w_(ua->var->ub, env, stack, check, nothrow);
            if (var == NULL) {
                if (lb == language_bottom_type)
                    var = language_bottom_type;
                else
                    t = NULL;
            }
            else if (lb != ua->var->lb || var != ua->var->ub) {
                var = (language_value_t*)language_new_typevar(ua->var->name, lb, var);
            }
            else {
                var = (language_value_t*)ua->var;
            }
        }
        if (t != NULL) {
            language_typeenv_t newenv = { ua->var, var, env };
            newbody = inst_type_w_(ua->body, &newenv, stack, check, nothrow);
            if (newbody == NULL) {
                t = NULL;
            }
            else if (newbody == (language_value_t*)language_emptytuple_type) {
                // NTuple{0} => Tuple{} can make a typevar disappear
                t = (language_value_t*)language_emptytuple_type;
            }
            else if (nothrow && !language_has_typevar(newbody, (language_tvar_t *)var)) {
                t = newbody;
            }
            else if (newbody != ua->body || var != (language_value_t*)ua->var) {
                // if t's parameters are not bound in the environment, return it uncopied (#9378)
                t = language_new_struct(language_unionall_type, var, newbody);
            }
        }
        LANGUAGE_GC_POP();
        return t;
    }
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        language_value_t *a = inst_type_w_(u->a, env, stack, check, nothrow);
        language_value_t *b = NULL;
        LANGUAGE_GC_PUSH2(&a, &b);
        b = inst_type_w_(u->b, env, stack, check, nothrow);
        if (a != u->a || b != u->b) {
            if (!check) {
                // fast path for `language_rename_unionall`.
                t = language_new_struct(language_uniontype_type, a, b);
            }
            else if (nothrow && a == NULL) {
                t = b;
            }
            else if (nothrow && b == NULL) {
                t = a;
            }
            else {
                assert(a != NULL && b != NULL);
                language_value_t *uargs[2] = {a, b};
                t = language_type_union(uargs, 2);
            }
        }
        LANGUAGE_GC_POP();
        return t;
    }
    if (language_is_vararg(t)) {
        language_vararg_t *v = (language_vararg_t*)t;
        language_value_t *T = NULL;
        language_value_t *N = NULL;
        LANGUAGE_GC_PUSH2(&T, &N);
        if (v->T) {
            T = inst_type_w_(v->T, env, stack, check, nothrow);
            if (T == NULL)
                T = language_bottom_type;
            if (v->N) // This branch should never throw.
                N = inst_type_w_(v->N, env, stack, check, 0);
        }
        if (T != v->T || N != v->N) {
            // `Vararg` is special, we'd better handle inner error at Tuple level.
            t = (language_value_t*)language_wrap_vararg(T, N, check, nothrow);
        }
        LANGUAGE_GC_POP();
        return t;
    }
    if (!language_is_datatype(t))
        return t;
    language_datatype_t *tt = (language_datatype_t*)t;
    language_svec_t *tp = tt->parameters;
    if (tp == language_emptysvec)
        return t;
    language_typename_t *tn = tt->name;
    if (tn == language_tuple_typename)
        return inst_tuple_w_(t, env, stack, check, nothrow);
    size_t ntp = language_svec_len(tp);
    language_value_t **iparams;
    LANGUAGE_GC_PUSHARGS(iparams, ntp);
    int bound = 0;
    for (i = 0; i < ntp; i++) {
        language_value_t *elt = language_svecref(tp, i);
        LANGUAGE_TRY {
            language_value_t *pi = inst_type_w_(elt, env, stack, check, 0);
            iparams[i] = pi;
            bound |= (pi != elt);
        }
        LANGUAGE_CATCH {
            if (!nothrow) language_rethrow();
            t = NULL;
        }
        if (t == NULL) break;
    }
    // if t's parameters are not bound in the environment, return it uncopied (#9378)
    if (t != NULL && bound)
        t = inst_datatype_inner(tt, NULL, iparams, ntp, stack, env, check, nothrow);
    LANGUAGE_GC_POP();
    return t;
}

static language_value_t *instantiate_with(language_value_t *t, language_value_t **env, size_t n, language_typeenv_t *te)
{
    if (n > 0) {
        language_typeenv_t en = { (language_tvar_t*)env[0], env[1], te };
        return instantiate_with(t, &env[2], n-1, &en );
    }
    return inst_type_w_(t, te, NULL, 1, 0);
}

language_value_t *language_instantiate_type_with(language_value_t *t, language_value_t **env, size_t n)
{
    return instantiate_with(t, env, n, NULL);
}

static language_value_t *_language_instantiate_type_in_env(language_value_t *ty, language_unionall_t *env, language_value_t **vals, language_typeenv_t *prev, language_typestack_t *stack)
{
    language_typeenv_t en = { env->var, vals[0], prev };
    if (language_is_unionall(env->body))
        return _language_instantiate_type_in_env(ty, (language_unionall_t*)env->body, vals + 1, &en, stack);
    else
        return inst_type_w_(ty, &en, stack, 1, 0);
}

LANGUAGE_DLLEXPORT language_value_t *language_instantiate_type_in_env(language_value_t *ty, language_unionall_t *env, language_value_t **vals)
{
    language_value_t *typ = ty;
    if (language_is_unionall(env)) {
        LANGUAGE_TRY {
            typ = _language_instantiate_type_in_env(ty, env, vals, NULL, NULL);
        }
        LANGUAGE_CATCH {
            typ = language_bottom_type;
        }
    }
    return typ;
}

language_datatype_t *language_wrap_Type(language_value_t *t)
{
    return (language_datatype_t*)language_instantiate_unionall(language_type_type, t);
}

language_vararg_t *language_wrap_vararg(language_value_t *t, language_value_t *n, int check, int nothrow)
{
    int valid = 1;
    language_vararg_t *vm = NULL;
    language_task_t *ct = language_current_task;
    LANGUAGE_GC_PUSH1(&t);
    if (check) {
        if (n) {
            if (language_is_typevar(n) || language_is_uniontype(language_unwrap_unionall(n))) {
                // TODO: this is disabled due to #39698; it is also inconsistent
                // with other similar checks, where we usually only check substituted
                // values and not the bounds of variables.
                /*
                language_tvar_t *N = (language_tvar_t*)n;
                if (valid && !(N->lb == language_bottom_type && N->ub == (language_value_t*)language_any_type)) {
                    if (!nothrow)
                        language_error("TypeVar in Vararg length must have bounds Union{} and Any");
                    invalid = 1;
                }
                */
            }
            else if (valid && !language_is_long(n)) {
                if (!nothrow)
                    language_type_error_rt("Vararg", "count", (language_value_t*)language_long_type, n);
                valid = 0;
            }
            else if (valid && language_unbox_long(n) < 0) {
                if (!nothrow)
                    language_errorf("Vararg length is negative: %zd", language_unbox_long(n));
                valid = 0;
            }
        }
        if (t) {
            if (valid && !language_valid_type_param(t)) {
                if (!nothrow)
                    language_type_error_rt("Vararg", "type", (language_value_t*)language_type_type, t);
                valid = 0;
            }
            if (valid) {
                t = normalize_unionalls(t);
                language_value_t *tw = extract_wrapper(t);
                if (tw && t != tw && language_types_equal(t, tw))
                    t = tw;
            }
        }
    }
    if (valid) {
        vm = (language_vararg_t *)language_gc_alloc(ct->ptls, sizeof(language_vararg_t), language_vararg_type);
        language_set_typetagof(vm, language_vararg_tag, 0);
        vm->T = t;
        vm->N = n;
    }
    LANGUAGE_GC_POP();
    return vm;
}

LANGUAGE_DLLEXPORT language_svec_t *language_compute_fieldtypes(language_datatype_t *st LANGUAGE_PROPAGATES_ROOT, void *stack, int cacheable)
{
    assert(st->name != language_namedtuple_typename && st->name != language_tuple_typename);
    language_datatype_t *wt = (language_datatype_t*)language_unwrap_unionall(st->name->wrapper);
    size_t i, n = language_svec_len(wt->parameters);
    assert(n > 0 && "expected empty case to be handled during construction");
    //if (n == 0)
    //    return ((st->types = language_emptysvec));
    if (wt->types == NULL)
        language_errorf("cannot determine field types of incomplete type %s",
                  language_symbol_name(st->name->name));
    language_typeenv_t *env = (language_typeenv_t*)alloca(n * sizeof(language_typeenv_t));
    for (i = 0; i < n; i++) {
        env[i].var = (language_tvar_t*)language_svecref(wt->parameters, i);
        env[i].val = language_svecref(st->parameters, i);
        env[i].prev = i == 0 ? NULL : &env[i - 1];
    }
    language_typestack_t top;
    top.tt = st;
    top.prev = (language_typestack_t*)stack;
    st->types = inst_ftypes(wt->types, &env[n - 1], &top, cacheable);
    language_gc_wb(st, st->types);
    return st->types;
}


void language_reinstantiate_inner_types(language_datatype_t *t) // can throw!
{
    assert(language_is_datatype(t));
    language_typestack_t top;
    top.tt = t;
    top.prev = NULL;
    size_t i, j, n = language_svec_len(t->parameters);
    language_array_t *partial = t->name->partial;
    if (partial == NULL)
        return;
    if (n == 0) {
        assert(language_array_nrows(partial) == 0);
        return;
    }

    language_typeenv_t *env = (language_typeenv_t*)alloca(n * sizeof(language_typeenv_t));
    for (i = 0; i < n; i++) {
        env[i].var = (language_tvar_t*)language_svecref(t->parameters, i);
        env[i].val = NULL;
        env[i].prev = i == 0 ? NULL : &env[i - 1];
    }

    for (j = 0; j < language_array_nrows(partial); j++) {
        language_datatype_t *ndt = (language_datatype_t*)language_array_ptr_ref(partial, j);
        if (ndt == NULL)
            continue;
        assert(language_unwrap_unionall(ndt->name->wrapper) == (language_value_t*)t);
        for (i = 0; i < n; i++)
            env[i].val = language_svecref(ndt->parameters, i);

        ndt->super = (language_datatype_t*)inst_type_w_((language_value_t*)t->super, &env[n - 1], &top, 1, 0);
        language_gc_wb(ndt, ndt->super);
    }

    if (t->types != language_emptysvec) {
        for (j = 0; j < language_array_nrows(partial); j++) {
            language_datatype_t *ndt = (language_datatype_t*)language_array_ptr_ref(partial, j);
            if (ndt == NULL)
                continue;
            for (i = 0; i < n; i++)
                env[i].val = language_svecref(ndt->parameters, i);
            assert(ndt->types == NULL);
            ndt->types = inst_ftypes(t->types, &env[n - 1], &top, 1);
            language_gc_wb(ndt, ndt->types);
            if (ndt->isconcretetype) { // cacheable
                language_compute_field_offsets(ndt);
            }
            language_array_ptr_set(partial, j, NULL);
        }
        t->name->partial = NULL;
    }
    else {
        assert(language_field_names(t) == language_emptysvec);
    }
}

// initialization -------------------------------------------------------------

static language_tvar_t *tvar(const char *name)
{
    return language_new_typevar(language_symbol(name), (language_value_t*)language_bottom_type,
                          (language_value_t*)language_any_type);
}

void export_language_small_typeof(void)
{
    memcpy(&language_small_typeof, &ilanguage_small_typeof, sizeof(language_small_typeof));
}

#define XX(name) \
    ilanguage_small_typeof[(code_##name##_tag << 4) / sizeof(*ilanguage_small_typeof)] = code_##name##_type; \
    code_##name##_type->smalltag = code_##name##_tag;
void language_init_types(void) LANGUAGE_GC_DISABLED
{
    language_module_t *core = NULL; // will need to be assigned later

    // create base objects
    language_datatype_type = language_new_uninitialized_datatype();
    XX(datatype);
    language_typename_type = language_new_uninitialized_datatype();
    language_symbol_type = language_new_uninitialized_datatype();
    XX(symbol);
    language_simplevector_type = language_new_uninitialized_datatype();
    XX(simplevector);
    language_methtable_type = language_new_uninitialized_datatype();

    language_emptysvec = (language_svec_t*)language_gc_permobj(sizeof(void*), language_simplevector_type);
    language_set_typetagof(language_emptysvec, language_simplevector_tag, GC_OLD_MARKED);
    language_svec_set_len_unsafe(language_emptysvec, 0);

    language_any_type = (language_datatype_t*)language_new_abstracttype((language_value_t*)language_symbol("Any"), core, NULL, language_emptysvec);
    language_any_type->super = language_any_type;
    language_nonfunction_mt = language_any_type->name->mt;
    language_any_type->name->mt = NULL;

    language_datatype_t *type_type = language_new_abstracttype((language_value_t*)language_symbol("Type"), core, language_any_type, language_emptysvec);
    language_type_type = (language_unionall_t*)type_type;
    language_type_typename = type_type->name;
    language_type_type_mt = language_new_method_table(language_type_typename->name, core);
    language_type_typename->mt = language_type_type_mt;

    // initialize them. lots of cycles.
    // NOTE: types are not actually mutable, but we want to ensure they are heap-allocated with stable addresses
    language_datatype_type->name = language_new_typename_in(language_symbol("DataType"), core, 0, 1);
    language_datatype_type->name->wrapper = (language_value_t*)language_datatype_type;
    language_datatype_type->super = type_type;
    language_datatype_type->parameters = language_emptysvec;
    language_datatype_type->name->n_uninitialized = 8 - 3;
    language_datatype_type->name->names = language_perm_symsvec(8,
            "name",
            "super",
            "parameters",
            "types",
            "instance",
            "layout",
            "hash",
            "flags"); // "hasfreetypevars", "isconcretetype", "isdispatchtuple", "isbitstype", "zeroinit", "has_concrete_subtype", "maybe_subtype_of_cache"
    language_datatype_type->types = language_svec(8,
            language_typename_type,
            language_datatype_type,
            language_simplevector_type,
            language_simplevector_type,
            language_any_type, // instance
            language_any_type /*language_voidpointer_type*/,
            language_any_type /*language_int32_type*/,
            language_any_type /*language_uint16_type*/);
    const static uint32_t datatype_constfields[1] = { 0x00000057 }; // (1<<0)|(1<<1)|(1<<2)|(1<<4)|(1<<6)
    const static uint32_t datatype_atomicfields[1] = { 0x00000028 }; // (1<<3)|(1<<5)
    language_datatype_type->name->constfields = datatype_constfields;
    language_datatype_type->name->atomicfields = datatype_atomicfields;
    language_precompute_memoized_dt(language_datatype_type, 1);

    language_typename_type->name = language_new_typename_in(language_symbol("TypeName"), core, 0, 1);
    language_typename_type->name->wrapper = (language_value_t*)language_typename_type;
    language_typename_type->name->mt = language_nonfunction_mt;
    language_typename_type->super = language_any_type;
    language_typename_type->parameters = language_emptysvec;
    language_typename_type->name->n_uninitialized = 15 - 2;
    language_typename_type->name->names = language_perm_symsvec(15, "name", "module",
                                                    "names", "atomicfields", "constfields",
                                                    "wrapper", "Typeofwrapper", "cache", "linearcache",
                                                    "mt", "partial",
                                                    "hash", "n_uninitialized",
                                                    "flags", // "abstract", "mutable", "mayinlinealloc",
                                                    "max_methods");
    const static uint32_t typename_constfields[1] = { 0x00003a27 }; // (1<<0)|(1<<1)|(1<<2)|(1<<5)|(1<<9)|(1<<11)|(1<<12)|(1<<13) ; TODO: put back (1<<3)|(1<<4) in this list
    const static uint32_t typename_atomicfields[1] = { 0x00000180 }; // (1<<7)|(1<<8)
    language_typename_type->name->constfields = typename_constfields;
    language_typename_type->name->atomicfields = typename_atomicfields;
    language_precompute_memoized_dt(language_typename_type, 1);
    language_typename_type->types = language_svec(15, language_symbol_type, language_any_type /*language_module_type*/,
                                      language_simplevector_type, language_any_type/*language_voidpointer_type*/, language_any_type/*language_voidpointer_type*/,
                                      language_type_type, language_type_type, language_simplevector_type, language_simplevector_type,
                                      language_methtable_type, language_any_type,
                                      language_any_type /*language_long_type*/, language_any_type /*language_int32_type*/,
                                      language_any_type /*language_uint8_type*/,
                                      language_any_type /*language_uint8_type*/);

    language_methtable_type->name = language_new_typename_in(language_symbol("MethodTable"), core, 0, 1);
    language_methtable_type->name->wrapper = (language_value_t*)language_methtable_type;
    language_methtable_type->name->mt = language_nonfunction_mt;
    language_methtable_type->super = language_any_type;
    language_methtable_type->parameters = language_emptysvec;
    language_methtable_type->name->n_uninitialized = 11 - 6;
    language_methtable_type->name->names = language_perm_symsvec(11, "name", "defs",
                                                     "leafcache", "cache", "max_args",
                                                     "module", "backedges",
                                                     "", "", "offs", "");
    const static uint32_t methtable_constfields[1] = { 0x00000020 }; // (1<<5);
    const static uint32_t methtable_atomicfields[1] = { 0x0000001e }; // (1<<1)|(1<<2)|(1<<3)|(1<<4);
    language_methtable_type->name->constfields = methtable_constfields;
    language_methtable_type->name->atomicfields = methtable_atomicfields;
    language_precompute_memoized_dt(language_methtable_type, 1);
    language_methtable_type->types = language_svec(11, language_symbol_type, language_any_type, language_any_type,
                                       language_any_type, language_any_type/*language_long*/,
                                       language_any_type/*module*/, language_any_type/*any vector*/,
                                       language_any_type/*voidpointer*/, language_any_type/*int32*/,
                                       language_any_type/*uint8*/, language_any_type/*uint8*/);

    language_symbol_type->name = language_new_typename_in(language_symbol("Symbol"), core, 0, 1);
    language_symbol_type->name->wrapper = (language_value_t*)language_symbol_type;
    language_symbol_type->name->mt = language_nonfunction_mt;
    language_symbol_type->super = language_any_type;
    language_symbol_type->parameters = language_emptysvec;
    language_symbol_type->name->n_uninitialized = 0;
    language_symbol_type->name->names = language_emptysvec;
    language_symbol_type->types = language_emptysvec;
    language_precompute_memoized_dt(language_symbol_type, 1);

    language_simplevector_type->name = language_new_typename_in(language_symbol("SimpleVector"), core, 0, 1);
    language_simplevector_type->name->wrapper = (language_value_t*)language_simplevector_type;
    language_simplevector_type->name->mt = language_nonfunction_mt;
    language_simplevector_type->super = language_any_type;
    language_simplevector_type->parameters = language_emptysvec;
    language_simplevector_type->name->n_uninitialized = 0;
    language_simplevector_type->name->names = language_emptysvec;
    language_simplevector_type->types = language_emptysvec;
    language_precompute_memoized_dt(language_simplevector_type, 1);

    // now they can be used to create the remaining base kinds and types
    language_nothing_type = language_new_datatype(language_symbol("Nothing"), core, language_any_type, language_emptysvec,
                                      language_emptysvec, language_emptysvec, language_emptysvec, 0, 0, 0);
    language_void_type = language_nothing_type; // deprecated alias
    language_astaggedvalue(language_nothing)->header = ((uintptr_t)language_nothing_type) | GC_OLD_MARKED;
    language_nothing_type->instance = language_nothing;

    language_tvar_type = language_new_datatype(language_symbol("TypeVar"), core, language_any_type, language_emptysvec,
                                   language_perm_symsvec(3, "name", "lb", "ub"),
                                   language_svec(3, language_symbol_type, language_any_type, language_any_type),
                                   language_emptysvec, 0, 1, 3);
    XX(tvar);
    const static uint32_t tvar_constfields[1] = { 0x00000007 }; // all fields are constant, even though TypeVar itself has identity
    language_tvar_type->name->constfields = tvar_constfields;

    language_typeofbottom_type = language_new_datatype(language_symbol("TypeofBottom"), core, type_type, language_emptysvec,
                                           language_emptysvec, language_emptysvec, language_emptysvec, 0, 0, 0);
    XX(typeofbottom);
    language_bottom_type = language_gc_permobj(0, language_typeofbottom_type);
    language_set_typetagof(language_bottom_type, language_typeofbottom_tag, GC_OLD_MARKED);
    language_typeofbottom_type->instance = language_bottom_type;

    language_unionall_type = language_new_datatype(language_symbol("UnionAll"), core, type_type, language_emptysvec,
                                       language_perm_symsvec(2, "var", "body"),
                                       language_svec(2, language_tvar_type, language_any_type),
                                       language_emptysvec, 0, 0, 2);
    XX(unionall);
    // It seems like we probably usually end up needing the box for kinds (often used in an Any context), so force it to exist
    language_unionall_type->name->mayinlinealloc = 0;

    language_uniontype_type = language_new_datatype(language_symbol("Union"), core, type_type, language_emptysvec,
                                        language_perm_symsvec(2, "a", "b"),
                                        language_svec(2, language_any_type, language_any_type),
                                        language_emptysvec, 0, 0, 2);
    XX(uniontype);
    // It seems like we probably usually end up needing the box for kinds (often used in an Any context), so force it to exist
    language_uniontype_type->name->mayinlinealloc = 0;

    language_tvar_t *tttvar = tvar("T");
    type_type->parameters = language_svec(1, tttvar);
    language_precompute_memoized_dt(type_type, 0); // update the hash value ASAP
    type_type->hasfreetypevars = 1;
    type_type->ismutationfree = 1;
    language_type_typename->wrapper = language_new_struct(language_unionall_type, tttvar, (language_value_t*)language_type_type);
    language_type_type = (language_unionall_t*)language_type_typename->wrapper;

    language_vararg_type = language_new_datatype(language_symbol("TypeofVararg"), core, language_any_type, language_emptysvec,
                                            language_perm_symsvec(2, "T", "N"),
                                            language_svec(2, language_any_type, language_any_type),
                                            language_emptysvec, 0, 0, 0);
    XX(vararg);
    // It seems like we probably usually end up needing the box for kinds (often used in an Any context), so force it to exist
    language_vararg_type->name->mayinlinealloc = 0;
    language_vararg_type->ismutationfree = 1;

    language_svec_t *anytuple_params = language_svec(1, language_wrap_vararg((language_value_t*)language_any_type, (language_value_t*)NULL, 0, 0));
    language_anytuple_type = language_new_datatype(language_symbol("Tuple"), core, language_any_type, anytuple_params,
                                       language_emptysvec, anytuple_params, language_emptysvec, 0, 0, 0);
    language_tuple_typename = language_anytuple_type->name;
    // fix some miscomputed values, since we didn't know this was going to be a Tuple in language_precompute_memoized_dt
    language_tuple_typename->wrapper = (language_value_t*)language_anytuple_type; // remove UnionAll wrappers
    language_anytuple_type->isconcretetype = 0;
    language_anytuple_type->maybe_subtype_of_cache = 0;
    language_anytuple_type->layout = NULL;

    language_typeofbottom_type->super = language_wrap_Type(language_bottom_type);
    language_emptytuple_type = (language_datatype_t*)language_apply_tuple_type(language_emptysvec, 0);
    language_emptytuple = language_gc_permobj(0, language_emptytuple_type);
    language_emptytuple_type->instance = language_emptytuple;

    // non-primitive definitions follow
    language_int32_type = language_new_primitivetype((language_value_t*)language_symbol("Int32"), core,
                                         language_any_type, language_emptysvec, 32);
    XX(int32);
    language_int64_type = language_new_primitivetype((language_value_t*)language_symbol("Int64"), core,
                                         language_any_type, language_emptysvec, 64);
    XX(int64);
    language_uint32_type = language_new_primitivetype((language_value_t*)language_symbol("UInt32"), core,
                                          language_any_type, language_emptysvec, 32);
    XX(uint32);
    language_uint64_type = language_new_primitivetype((language_value_t*)language_symbol("UInt64"), core,
                                          language_any_type, language_emptysvec, 64);
    XX(uint64);
    language_uint8_type = language_new_primitivetype((language_value_t*)language_symbol("UInt8"), core,
                                         language_any_type, language_emptysvec, 8);
    XX(uint8);
    language_uint16_type = language_new_primitivetype((language_value_t*)language_symbol("UInt16"), core,
                                          language_any_type, language_emptysvec, 16);
    XX(uint16);

    language_ssavalue_type = language_new_datatype(language_symbol("SSAValue"), core, language_any_type, language_emptysvec,
                                       language_perm_symsvec(1, "id"),
                                       language_svec1(language_long_type),
                                       language_emptysvec, 0, 0, 1);

    language_slotnumber_type = language_new_datatype(language_symbol("SlotNumber"), core, language_any_type, language_emptysvec,
                                         language_perm_symsvec(1, "id"),
                                         language_svec1(language_long_type),
                                         language_emptysvec, 0, 0, 1);

    language_argument_type = language_new_datatype(language_symbol("Argument"), core, language_any_type, language_emptysvec,
                                       language_perm_symsvec(1, "n"),
                                       language_svec1(language_long_type),
                                       language_emptysvec, 0, 0, 1);

    language_init_int32_int64_cache();

    language_bool_type = NULL;
    language_bool_type = language_new_primitivetype((language_value_t*)language_symbol("Bool"), core,
                                        language_any_type, language_emptysvec, 8);
    XX(bool);
    language_false = language_permbox8(language_bool_type, language_bool_tag, 0);
    language_true  = language_permbox8(language_bool_type, language_bool_tag, 1);

    language_abstractstring_type = language_new_abstracttype((language_value_t*)language_symbol("AbstractString"), core, language_any_type, language_emptysvec);
    language_string_type = language_new_datatype(language_symbol("String"), core, language_abstractstring_type, language_emptysvec,
                                     language_emptysvec, language_emptysvec, language_emptysvec, 0, 1, 0);
    XX(string);
    language_string_type->instance = NULL;
    language_compute_field_offsets(language_string_type); // re-compute now that we assigned language_string_type
    language_an_empty_string = language_pchar_to_string("\0", 1);
    *(size_t*)language_an_empty_string = 0;

    language_typemap_level_type =
        language_new_datatype(language_symbol("TypeMapLevel"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(6,
                            "arg1",
                            "targ",
                            "name1",
                            "tname",
                            "list",
                            "any"),
                        language_svec(6,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_any_type),
                        language_emptysvec,
                        0, 1, 6);
    const static uint32_t typemap_level_atomicfields[1] = { 0x0000003f }; // (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)
    language_typemap_level_type->name->atomicfields = typemap_level_atomicfields;

    language_typemap_entry_type =
        language_new_datatype(language_symbol("TypeMapEntry"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(10,
                            "next",
                            "sig",
                            "simplesig",
                            "guardsigs",
                            "min_world",
                            "max_world",
                            "func",
                            "isleafsig",
                            "issimplesig",
                            "va"),
                        language_svec(10,
                            language_any_type, // Union{TypeMapEntry, Nothing}
                            language_type_type, // TupleType
                            language_any_type, // TupleType
                            language_any_type, // SimpleVector{TupleType}
                            language_ulong_type, // UInt
                            language_ulong_type, // UInt
                            language_any_type, // Any
                            language_bool_type,
                            language_bool_type,
                            language_bool_type),
                        language_emptysvec,
                        0, 1, 4);
    const static uint32_t typemap_entry_constfields[1] = { 0x000003ce }; // (1<<1)|(1<<2)|(1<<3)|(1<<6)|(1<<7)|(1<<8)|(1<<9)
    const static uint32_t typemap_entry_atomicfields[1] = { 0x00000031 }; // (1<<0)|(1<<4)|(1<<5)
    language_typemap_entry_type->name->constfields = typemap_entry_constfields;
    language_typemap_entry_type->name->atomicfields = typemap_entry_atomicfields;

    language_function_type = language_new_abstracttype((language_value_t*)language_symbol("Function"), core, language_any_type, language_emptysvec);
    language_builtin_type  = language_new_abstracttype((language_value_t*)language_symbol("Builtin"), core, language_function_type, language_emptysvec);
    language_function_type->name->mt = NULL; // subtypes of Function have independent method tables
    language_builtin_type->name->mt = NULL;  // so they don't share the Any type table

    language_svec_t *tv;

    language_module_type =
        language_new_datatype(language_symbol("Module"), core, language_any_type, language_emptysvec,
                        language_emptysvec, language_emptysvec, language_emptysvec, 0, 1, 0);
    XX(module);
    assert(language_module_type->instance == NULL);
    language_compute_field_offsets(language_module_type);

    language_binding_type =
        language_new_datatype(language_symbol("Binding"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(5, "value", "globalref", "owner", "ty", "flags"),
                        language_svec(5, language_any_type, language_any_type/*language_globalref_type*/, language_any_type/*language_binding_type*/, language_type_type, language_uint8_type),
                        language_emptysvec, 0, 1, 0);
    const static uint32_t binding_atomicfields[] = { 0x0015 }; // Set fields 1, 3, 4 as atomic
    language_binding_type->name->atomicfields = binding_atomicfields;
    const static uint32_t binding_constfields[] = { 0x0002 }; // Set fields 2 as constant
    language_binding_type->name->constfields = binding_constfields;

    language_globalref_type =
        language_new_datatype(language_symbol("GlobalRef"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(3, "mod", "name", "binding"),
                        language_svec(3, language_module_type, language_symbol_type, language_binding_type),
                        language_emptysvec, 0, 0, 3);

    core = language_new_module(language_symbol("Core"), NULL);
    core->parent = core;
    language_type_typename->mt->module = core;
    language_core_module = core;
    core = NULL; // not ready yet to use

    tv = language_svec1(tvar("Backend"));
    language_addrspace_typename =
        language_new_primitivetype((language_value_t*)language_symbol("AddrSpace"), core, language_any_type, tv, 8)->name;
    language_addrspace_type = (language_unionall_t*)language_addrspace_typename->wrapper;
    language_addrspacecore_type = (language_datatype_t*)language_apply_type1((language_value_t*)language_addrspace_type, (language_value_t*)language_core_module);
    language_value_t *cpumem = language_permbox8(language_addrspacecore_type, 0, 0);

    tv = language_svec1(tvar("T"));
    language_ref_type = (language_unionall_t*)
        language_new_abstracttype((language_value_t*)language_symbol("Ref"), core, language_any_type, tv)->name->wrapper;

    tv = language_svec1(tvar("T"));
    language_pointer_typename =
        language_new_primitivetype((language_value_t*)language_symbol("Ptr"), core,
                             (language_datatype_t*)language_apply_type((language_value_t*)language_ref_type, language_svec_data(tv), 1),
                             tv,
                             sizeof(void*) * 8)->name;
    language_pointer_type = (language_unionall_t*)language_pointer_typename->wrapper;
    language_value_t *pointer_void = language_apply_type1((language_value_t*)language_pointer_type, (language_value_t*)language_nothing_type);
    language_voidpointer_type = (language_datatype_t*)pointer_void;

    tv = language_svec2(tvar("T"), tvar("N"));
    language_abstractarray_type = (language_unionall_t*)
        language_new_abstracttype((language_value_t*)language_symbol("AbstractArray"), core,
                            language_any_type, tv)->name->wrapper;

    tv = language_svec2(tvar("T"), tvar("N"));
    language_densearray_type = (language_unionall_t*)
        language_new_abstracttype((language_value_t*)language_symbol("DenseArray"), core,
                            (language_datatype_t*)language_apply_type((language_value_t*)language_abstractarray_type, language_svec_data(tv), 2),
                            tv)->name->wrapper;

    tv = language_svec(3, tvar("isatomic"), tvar("T"), tvar("addrspace"));
    language_datatype_t *language_memory_supertype = (language_datatype_t*)language_apply_type2((language_value_t*)language_densearray_type, language_svecref(tv, 1), language_box_long(1));
    language_datatype_t *memory_datatype =
        language_new_datatype(language_symbol("GenericMemory"), core, language_memory_supertype, tv,
                        language_perm_symsvec(2, "length", "ptr"),
                        language_svec(2, language_long_type, pointer_void),
                        language_emptysvec, 0, 1, 2);
    language_genericmemory_typename = memory_datatype->name;
    language_genericmemory_type = (language_unionall_t*)language_genericmemory_typename->wrapper;
    const static uint32_t memory_constfields[1] = { 0x00000003 }; // (1<<1)|(1<<0)
    memory_datatype->name->constfields = memory_constfields;
    memory_datatype->ismutationfree = 0;

    language_datatype_t *language_memoryref_supertype = (language_datatype_t*)language_apply_type1((language_value_t*)language_ref_type, language_svecref(tv, 1));
    language_datatype_t *memoryref_datatype =
        language_new_datatype(language_symbol("GenericMemoryRef"), core, language_memoryref_supertype, tv,
                        language_perm_symsvec(2, "ptr_or_offset", "mem"),
                        language_svec(2, pointer_void, memory_datatype),
                        language_emptysvec, 0, 0, 2);
    language_genericmemoryref_typename = memoryref_datatype->name;
    language_genericmemoryref_type = (language_unionall_t*)language_genericmemoryref_typename->wrapper;
    memoryref_datatype->ismutationfree = 0;

    language_memory_any_type = language_apply_type3((language_value_t*)language_genericmemory_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_any_type, cpumem);
    language_memory_uint8_type = language_apply_type3((language_value_t*)language_genericmemory_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_uint8_type, cpumem);
    language_memory_uint16_type = language_apply_type3((language_value_t*)language_genericmemory_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_uint16_type, cpumem);
    language_memory_uint32_type = language_apply_type3((language_value_t*)language_genericmemory_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_uint32_type, cpumem);
    language_memory_uint64_type = language_apply_type3((language_value_t*)language_genericmemory_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_uint64_type, cpumem);
    language_memoryref_any_type = language_apply_type3((language_value_t*)language_genericmemoryref_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_any_type, cpumem);
    language_memoryref_uint8_type = language_apply_type3((language_value_t*)language_genericmemoryref_type, (language_value_t*)language_not_atomic_sym, (language_value_t*)language_uint8_type, cpumem);

    tv = language_svec2(tvar("T"), tvar("N"));
    language_array_typename = language_new_datatype(language_symbol("Array"), core,
                        (language_datatype_t*)language_apply_type((language_value_t*)language_densearray_type, language_svec_data(tv), 2),
                        tv,
                        language_perm_symsvec(2, "ref", "size"),
                        language_svec(2,
                            language_apply_type3((language_value_t*)language_genericmemoryref_type, (language_value_t*)language_not_atomic_sym, language_svecref(tv, 0), cpumem),
                            language_apply_type1((language_value_t*)language_tuple_type, (language_value_t*)language_wrap_vararg((language_value_t*)language_long_type, language_svecref(tv, 1), 0, 0))),
                            language_emptysvec, 0, 1, 2)->name;
    language_array_type = (language_unionall_t*)language_array_typename->wrapper;

    language_array_any_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_any_type, language_box_long(1));
    language_array_symbol_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_symbol_type, language_box_long(1));
    language_array_uint8_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_uint8_type, language_box_long(1));
    language_array_uint32_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_uint32_type, language_box_long(1));
    language_array_int32_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_int32_type, language_box_long(1));
    language_array_uint64_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_uint64_type, language_box_long(1));
    language_an_empty_vec_any = (language_value_t*)language_alloc_vec_any(0); // used internally
    language_an_empty_memory_any = (language_value_t*)language_alloc_memory_any(0); // used internally
    language_atomic_store_relaxed(&language_nonfunction_mt->leafcache, (language_genericmemory_t*)language_an_empty_memory_any);
    language_atomic_store_relaxed(&language_type_type_mt->leafcache, (language_genericmemory_t*)language_an_empty_memory_any);

    // finish initializing module Core
    core = language_core_module;
    language_atomic_store_relaxed(&core->bindingkeyset, (language_genericmemory_t*)language_an_empty_memory_any);
    // export own name, so "using Foo" makes "Foo" itself visible
    language_set_const(core, core->name, (language_value_t*)core);
    language_module_public(core, core->name, 1);
    language_set_const(core, language_symbol("CPU"), (language_value_t*)cpumem);
    core = NULL;

    language_expr_type =
        language_new_datatype(language_symbol("Expr"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "head", "args"),
                        language_svec(2, language_symbol_type, language_array_any_type),
                        language_emptysvec, 0, 1, 2);

    language_value_t *symornothing[2] = { (language_value_t*)language_symbol_type, (language_value_t*)language_void_type };
    language_linenumbernode_type =
        language_new_datatype(language_symbol("LineNumberNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "line", "file"),
                        language_svec(2, language_long_type, language_type_union(symornothing, 2)),
                        language_emptysvec, 0, 0, 2);

    language_lineinfonode_type =
        language_new_datatype(language_symbol("LegacyLineInfoNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(3, "file", "line", "inlined_at"),
                        language_svec(3, language_symbol_type, language_int32_type, language_int32_type),
                        language_emptysvec, 0, 0, 3);

    language_gotonode_type =
        language_new_datatype(language_symbol("GotoNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "label"),
                        language_svec(1, language_long_type),
                        language_emptysvec, 0, 0, 1);

    language_gotoifnot_type =
        language_new_datatype(language_symbol("GotoIfNot"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "cond", "dest"),
                        language_svec(2, language_any_type, language_long_type),
                        language_emptysvec, 0, 0, 2);

    language_enternode_type =
        language_new_datatype(language_symbol("EnterNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "catch_dest", "scope"),
                        language_svec(2, language_long_type, language_any_type),
                        language_emptysvec, 0, 0, 1);

    language_returnnode_type =
        language_new_datatype(language_symbol("ReturnNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "val"),
                        language_svec(1, language_any_type),
                        language_emptysvec, 0, 0, 0);

    language_pinode_type =
        language_new_datatype(language_symbol("PiNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "val", "typ"),
                        language_svec(2, language_any_type, language_any_type),
                        language_emptysvec, 0, 0, 2);

    language_phinode_type =
        language_new_datatype(language_symbol("PhiNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(2, "edges", "values"),
                        language_svec(2, language_array_int32_type, language_array_any_type),
                        language_emptysvec, 0, 0, 2);

    language_phicnode_type =
        language_new_datatype(language_symbol("PhiCNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "values"),
                        language_svec(1, language_array_any_type),
                        language_emptysvec, 0, 0, 1);

    language_upsilonnode_type =
        language_new_datatype(language_symbol("UpsilonNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "val"),
                        language_svec(1, language_any_type),
                        language_emptysvec, 0, 0, 0);

    language_quotenode_type =
        language_new_datatype(language_symbol("QuoteNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "value"),
                        language_svec(1, language_any_type),
                        language_emptysvec, 0, 0, 1);

    language_newvarnode_type =
        language_new_datatype(language_symbol("NewvarNode"), core, language_any_type, language_emptysvec,
                        language_perm_symsvec(1, "slot"),
                        language_svec(1, language_slotnumber_type),
                        language_emptysvec, 0, 0, 1);

    language_debuginfo_type =
        language_new_datatype(language_symbol("DebugInfo"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(4,
                            "def",
                            "linetable",
                            "edges",
                            "codelocs"),
                        language_svec(4,
                            language_any_type, // union(language_method_instance_type, language_method_type, language_symbol_type),
                            language_any_type, // union(language_nothing, language_debuginfo_type)
                            language_simplevector_type, // memory{debuginfo}
                            language_string_type),
                        language_emptysvec, 0, 0, 4);
    language_debuginfo_type->name->mayinlinealloc = 0;

    language_code_info_type =
        language_new_datatype(language_symbol("CodeInfo"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(21,
                            "code",
                            "debuginfo",
                            "ssavaluetypes",
                            "ssaflags",
                            "slotnames",
                            "slotflags",
                            "slottypes",
                            "parent",
                            "method_for_inference_limit_heuristics",
                            "edges",
                            "min_world",
                            "max_world",
                            "nargs",
                            "propagate_inbounds",
                            "has_fcall",
                            "nospecializeinfer",
                            "isva",
                            "inlining",
                            "constprop",
                            "purity",
                            "inlining_cost"),
                        language_svec(21,
                            language_array_any_type,
                            language_debuginfo_type,
                            language_any_type,
                            language_array_uint32_type,
                            language_array_symbol_type,
                            language_array_uint8_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_ulong_type,
                            language_ulong_type,
                            language_ulong_type,
                            language_bool_type,
                            language_bool_type,
                            language_bool_type,
                            language_bool_type,
                            language_uint8_type,
                            language_uint8_type,
                            language_uint16_type,
                            language_uint16_type),
                        language_emptysvec,
                        0, 1, 21);

    language_method_type =
        language_new_datatype(language_symbol("Method"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(31,
                            "name",
                            "module",
                            "file",
                            "line",
                            "primary_world", // atomic
                            "deleted_world", // atomic
                            "sig",
                            "specializations", // !const
                            "speckeyset", // !const
                            "slot_syms",
                            "external_mt",
                            "source", // !const
                            "debuginfo", // !const
                            "unspecialized", // !const
                            "generator", // !const
                            "roots", // !const
                            "root_blocks", // !const
                            "nroots_sysimg",
                            "ccallable", // !const
                            "invokes", // !const
                            "recursion_relation", // !const
                            "nargs",
                            "called",
                            "nospecialize",
                            "nkw",
                            "isva",
                            "is_for_opaque_closure",
                            "nospecializeinfer",
                            "constprop",
                            "max_varargs",
                            "purity"),
                        language_svec(31,
                            language_symbol_type,
                            language_module_type,
                            language_symbol_type,
                            language_int32_type,
                            language_ulong_type,
                            language_ulong_type,
                            language_type_type,
                            language_any_type, // union(language_simplevector_type, language_method_instance_type),
                            language_genericmemory_type, // union(language_memory_uint8_type, language_memory_uint16_type, language_memory_uint32_type, language_memory_uint64_type, language_memory_any_type)
                            language_string_type,
                            language_any_type,
                            language_any_type,
                            language_debuginfo_type,
                            language_any_type, // language_method_instance_type
                            language_any_type,
                            language_array_any_type,
                            language_array_uint64_type,
                            language_int32_type,
                            language_simplevector_type,
                            language_any_type,
                            language_any_type,
                            language_int32_type,
                            language_int32_type,
                            language_int32_type,
                            language_int32_type,
                            language_bool_type,
                            language_bool_type,
                            language_bool_type,
                            language_uint8_type,
                            language_uint8_type,
                            language_uint16_type),
                        language_emptysvec,
                        0, 1, 10);
    //const static uint32_t method_constfields[1] = { 0b0 }; // (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<6)|(1<<9)|(1<<10)|(1<<17)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25)|(1<<26)|(1<<27)|(1<<28)|(1<<29)|(1<<30);
    //language_method_type->name->constfields = method_constfields;
    const static uint32_t method_atomicfields[1] = { 0x00000030 }; // (1<<4)|(1<<5)
    language_method_type->name->atomicfields = method_atomicfields;

    language_method_instance_type =
        language_new_datatype(language_symbol("MethodInstance"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(8,
                            "def",
                            "specTypes",
                            "sparam_vals",
                            "backedges",
                            "cache",
                            "inInference",
                            "cache_with_orig",
                            "precompiled"),
                        language_svec(8,
                            language_new_struct(language_uniontype_type, language_method_type, language_module_type),
                            language_any_type,
                            language_simplevector_type,
                            language_array_any_type,
                            language_any_type/*language_code_instance_type*/,
                            language_bool_type,
                            language_bool_type,
                            language_bool_type),
                        language_emptysvec,
                        0, 1, 3);
    // These fields should be constant, but Serialization wants to mutate them in initialization
    //const static uint32_t method_instance_constfields[1] = { 0x00000007 }; // (1<<0)|(1<<1)|(1<<2);
    const static uint32_t method_instance_atomicfields[1] = { 0x0000090 }; // (1<<4)|(1<<7);
    //Fields 4 and 5 must be protected by method->write_lock, and thus all operations on language_method_instance_t are threadsafe. TODO: except inInference
    //language_method_instance_type->name->constfields = method_instance_constfields;
    language_method_instance_type->name->atomicfields = method_instance_atomicfields;

    language_code_instance_type =
        language_new_datatype(language_symbol("CodeInstance"), core,
                        language_any_type, language_emptysvec,
                        language_perm_symsvec(18,
                            "def",
                            "owner",
                            "next",
                            "min_world",
                            "max_world",
                            "rettype",
                            "exctype",
                            "rettype_const",
                            "inferred",
                            "debuginfo", // TODO: rename to edges?
                            //"absolute_max",
                            "ipo_purity_bits", "purity_bits",
                            "analysis_results",
                            "specsigflags", "precompile", "relocatability",
                            "invoke", "specptr"), // function object decls
                        language_svec(18,
                            language_method_instance_type,
                            language_any_type,
                            language_any_type,
                            language_ulong_type,
                            language_ulong_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_any_type,
                            language_debuginfo_type,
                            //language_bool_type,
                            language_uint32_type, language_uint32_type,
                            language_any_type,
                            language_bool_type,
                            language_bool_type,
                            language_uint8_type,
                            language_any_type, language_any_type), // fptrs
                        language_emptysvec,
                        0, 1, 1);
    language_svecset(language_code_instance_type->types, 2, language_code_instance_type);
    const static uint32_t code_instance_constfields[1]  = { 0b000001010011100011 }; // Set fields 1, 2, 6-8, 11, 13 as const
    const static uint32_t code_instance_atomicfields[1] = { 0b110110101100011100 }; // Set fields 3-5, 9, 10, 12, 14-15, 17-18 as atomic
    //Fields 4-5 are only operated on by construction and deserialization, so are const at runtime
    //Fields 13 and 17 must be protected by locks, and thus all operations on language_code_instance_t are threadsafe
    //Except for field 9 (inferred), which is volatile unless you know which other places are currently using it
    language_code_instance_type->name->constfields = code_instance_constfields;
    language_code_instance_type->name->atomicfields = code_instance_atomicfields;

    language_const_type = language_new_datatype(language_symbol("Const"), core, language_any_type, language_emptysvec,
                                       language_perm_symsvec(1, "val"),
                                       language_svec1(language_any_type),
                                       language_emptysvec, 0, 0, 1);

    language_partial_struct_type = language_new_datatype(language_symbol("PartialStruct"), core, language_any_type, language_emptysvec,
                                       language_perm_symsvec(2, "typ", "fields"),
                                       language_svec2(language_any_type, language_array_any_type),
                                       language_emptysvec, 0, 0, 2);

    language_interconditional_type = language_new_datatype(language_symbol("InterConditional"), core, language_any_type, language_emptysvec,
                                          language_perm_symsvec(3, "slot", "thentype", "elsetype"),
                                          language_svec(3, language_long_type, language_any_type, language_any_type),
                                          language_emptysvec, 0, 0, 3);

    language_method_match_type = language_new_datatype(language_symbol("MethodMatch"), core, language_any_type, language_emptysvec,
                                       language_perm_symsvec(4, "spec_types", "sparams", "method", "fully_covers"),
                                       language_svec(4, language_type_type, language_simplevector_type, language_method_type, language_bool_type),
                                       language_emptysvec, 0, 0, 4);

    // all Kinds share the Type method table (not the nonfunction one)
    language_unionall_type->name->mt = language_uniontype_type->name->mt = language_datatype_type->name->mt =
        language_type_type_mt;

    language_intrinsic_type = language_new_primitivetype((language_value_t*)language_symbol("IntrinsicFunction"), core,
                                             language_builtin_type, language_emptysvec, 32);

    // LLVMPtr{T, AS} where {T, AS}
    language_tvar_t *elvar = tvar("T");
    tv = language_svec2(elvar, tvar("AS"));
    language_svec_t *tv_base = language_svec1(elvar);
    language_llvmpointer_type = (language_unionall_t*)
        language_new_primitivetype((language_value_t*)language_symbol("LLVMPtr"), core,
                             (language_datatype_t*)language_apply_type((language_value_t*)language_ref_type, language_svec_data(tv_base), 1), tv,
                             sizeof(void*)*8)->name->wrapper;
    language_llvmpointer_typename = ((language_datatype_t*)language_unwrap_unionall((language_value_t*)language_llvmpointer_type))->name;

    // Type{T} where T<:Tuple
    tttvar = language_new_typevar(language_symbol("T"),
                            (language_value_t*)language_bottom_type,
                            (language_value_t*)language_anytuple_type);
    language_anytuple_type_type = (language_unionall_t*)language_new_struct(language_unionall_type,
                                                          tttvar, (language_value_t*)language_wrap_Type((language_value_t*)tttvar));

    language_tvar_t *ntval_var = language_new_typevar(language_symbol("T"), (language_value_t*)language_bottom_type,
                                          (language_value_t*)language_anytuple_type);
    tv = language_svec2(tvar("names"), ntval_var);
    language_datatype_t *ntt = language_new_datatype(language_symbol("NamedTuple"), core, language_any_type, tv,
                                         language_emptysvec, language_emptysvec, language_emptysvec, 0, 0, 0);
    language_namedtuple_type = (language_unionall_t*)ntt->name->wrapper;
    ((language_datatype_t*)language_unwrap_unionall((language_value_t*)language_namedtuple_type))->layout = NULL;
    language_namedtuple_typename = ntt->name;

    language_task_type = (language_datatype_t*)
        language_new_datatype(language_symbol("Task"),
                        NULL,
                        language_any_type,
                        language_emptysvec,
                        language_perm_symsvec(16,
                                        "next",
                                        "queue",
                                        "storage",
                                        "donenotify",
                                        "result",
                                        "scope",
                                        "code",
                                        "rngState0",
                                        "rngState1",
                                        "rngState2",
                                        "rngState3",
                                        "rngState4",
                                        "_state",
                                        "sticky",
                                        "_isexception",
                                        "priority"),
                        language_svec(16,
                                language_any_type,
                                language_any_type,
                                language_any_type,
                                language_any_type,
                                language_any_type,
                                language_any_type,
                                language_any_type,
                                language_uint64_type,
                                language_uint64_type,
                                language_uint64_type,
                                language_uint64_type,
                                language_uint64_type,
                                language_uint8_type,
                                language_bool_type,
                                language_bool_type,
                                language_uint16_type),
                        language_emptysvec,
                        0, 1, 6);
    XX(task);
    language_value_t *listt = language_new_struct(language_uniontype_type, language_task_type, language_nothing_type);
    language_svecset(language_task_type->types, 0, listt);

    tv = language_svec2(tvar("A"), tvar("R"));
    language_opaque_closure_type = (language_unionall_t*)language_new_datatype(language_symbol("OpaqueClosure"), core, language_function_type, tv,
        // N.B.: OpaqueClosure call code relies on specptr being field 5.
        // Update that code if you change this.
        language_perm_symsvec(5, "captures", "world", "source", "invoke", "specptr"),
        language_svec(5, language_any_type, language_long_type, language_any_type, pointer_void, pointer_void),
        language_emptysvec, 0, 0, 5)->name->wrapper;
    language_opaque_closure_typename = ((language_datatype_t*)language_unwrap_unionall((language_value_t*)language_opaque_closure_type))->name;
    language_compute_field_offsets((language_datatype_t*)language_unwrap_unionall((language_value_t*)language_opaque_closure_type));

    language_partial_opaque_type = language_new_datatype(language_symbol("PartialOpaque"), core, language_any_type, language_emptysvec,
        language_perm_symsvec(4, "typ", "env", "parent", "source"),
        language_svec(4, language_type_type, language_any_type, language_method_instance_type, language_any_type),
        language_emptysvec, 0, 0, 4);

    // complete builtin type metadata
    language_uint8pointer_type = (language_datatype_t*)language_apply_type1((language_value_t*)language_pointer_type, (language_value_t*)language_uint8_type);
    language_svecset(language_datatype_type->types, 5, language_voidpointer_type);
    language_svecset(language_datatype_type->types, 6, language_int32_type);
    language_svecset(language_datatype_type->types, 7, language_uint16_type);
    language_svecset(language_typename_type->types, 1, language_module_type);
    language_svecset(language_typename_type->types, 3, language_voidpointer_type);
    language_svecset(language_typename_type->types, 4, language_voidpointer_type);
    language_svecset(language_typename_type->types, 5, language_type_type);
    language_svecset(language_typename_type->types, 6, language_type_type);
    language_svecset(language_typename_type->types, 11, language_long_type);
    language_svecset(language_typename_type->types, 12, language_int32_type);
    language_svecset(language_typename_type->types, 13, language_uint8_type);
    language_svecset(language_typename_type->types, 14, language_uint8_type);
    language_svecset(language_methtable_type->types, 4, language_long_type);
    language_svecset(language_methtable_type->types, 5, language_module_type);
    language_svecset(language_methtable_type->types, 6, language_array_any_type);
    language_svecset(language_methtable_type->types, 7, language_long_type); // voidpointer
    language_svecset(language_methtable_type->types, 8, language_long_type); // uint32_t plus alignment
    language_svecset(language_methtable_type->types, 9, language_uint8_type);
    language_svecset(language_methtable_type->types, 10, language_uint8_type);
    language_svecset(language_method_type->types, 13, language_method_instance_type);
    //language_svecset(language_debuginfo_type->types, 0, language_method_instance_type); // union(language_method_instance_type, language_method_type, language_symbol_type)
    language_svecset(language_method_instance_type->types, 4, language_code_instance_type);
    language_svecset(language_code_instance_type->types, 16, language_voidpointer_type);
    language_svecset(language_code_instance_type->types, 17, language_voidpointer_type);
    language_svecset(language_binding_type->types, 1, language_globalref_type);
    language_svecset(language_binding_type->types, 2, language_binding_type);

    language_compute_field_offsets(language_datatype_type);
    language_compute_field_offsets(language_typename_type);
    language_compute_field_offsets(language_uniontype_type);
    language_compute_field_offsets(language_tvar_type);
    language_compute_field_offsets(language_methtable_type);
    language_compute_field_offsets(language_method_instance_type);
    language_compute_field_offsets(language_code_instance_type);
    language_compute_field_offsets(language_unionall_type);
    language_compute_field_offsets(language_simplevector_type);
    language_compute_field_offsets(language_symbol_type);

    // override ismutationfree for builtin types that are mutable for identity
    language_string_type->ismutationfree = language_string_type->isidentityfree = 1;
    language_symbol_type->ismutationfree = language_symbol_type->isidentityfree = 1;
    language_simplevector_type->ismutationfree = language_simplevector_type->isidentityfree = 1;
    language_datatype_type->ismutationfree = 1;
    assert(((language_datatype_t*)language_array_any_type)->ismutationfree == 0);
    assert(((language_datatype_t*)language_array_uint8_type)->ismutationfree == 0);

    // Technically not ismutationfree, but there's a separate system to deal
    // with mutations for global state.
    language_module_type->ismutationfree = 1;
    // Module object identity is determined by its name and parent name.
    language_module_type->isidentityfree = 1;

    export_language_small_typeof();
}

static language_value_t *core(const char *name)
{
    return language_get_global(language_core_module, language_symbol(name));
}

language_debuginfo_t *language_nulldebuginfo;

// fetch references to things defined in boot.jl
void post_boot_hooks(void)
{
    language_char_type    = (language_datatype_t*)core("Char");
    XX(char);
    language_int8_type    = (language_datatype_t*)core("Int8");
    XX(int8);
    language_int16_type   = (language_datatype_t*)core("Int16");
    XX(int16);
    language_float16_type = (language_datatype_t*)core("Float16");
    //XX(float16);
    language_float32_type = (language_datatype_t*)core("Float32");
    //XX(float32);
    language_float64_type = (language_datatype_t*)core("Float64");
    //XX(float64);
    language_bfloat16_type = (language_datatype_t*)core("BFloat16");
    //XX(bfloat16);
    language_floatingpoint_type = (language_datatype_t*)core("AbstractFloat");
    language_number_type  = (language_datatype_t*)core("Number");
    language_signed_type  = (language_datatype_t*)core("Signed");
    language_datatype_t *language_unsigned_type = (language_datatype_t*)core("Unsigned");
    language_datatype_t *language_integer_type = (language_datatype_t*)core("Integer");

    language_bool_type->super = language_integer_type;
    language_uint8_type->super = language_unsigned_type;
    language_uint16_type->super = language_unsigned_type;
    language_uint32_type->super = language_unsigned_type;
    language_uint64_type->super = language_unsigned_type;
    language_int32_type->super = language_signed_type;
    language_int64_type->super = language_signed_type;

    language_errorexception_type = (language_datatype_t*)core("ErrorException");
    language_stackovf_exception  = language_new_struct_uninit((language_datatype_t*)core("StackOverflowError"));
    language_diverror_exception  = language_new_struct_uninit((language_datatype_t*)core("DivideError"));
    language_undefref_exception  = language_new_struct_uninit((language_datatype_t*)core("UndefRefError"));
    language_undefvarerror_type  = (language_datatype_t*)core("UndefVarError");
    language_atomicerror_type    = (language_datatype_t*)core("ConcurrencyViolationError");
    language_interrupt_exception = language_new_struct_uninit((language_datatype_t*)core("InterruptException"));
    language_boundserror_type    = (language_datatype_t*)core("BoundsError");
    language_memory_exception    = language_new_struct_uninit((language_datatype_t*)core("OutOfMemoryError"));
    language_readonlymemory_exception = language_new_struct_uninit((language_datatype_t*)core("ReadOnlyMemoryError"));
    language_typeerror_type      = (language_datatype_t*)core("TypeError");
    language_argumenterror_type  = (language_datatype_t*)core("ArgumentError");
    language_methoderror_type    = (language_datatype_t*)core("MethodError");
    language_loaderror_type      = (language_datatype_t*)core("LoadError");
    language_initerror_type      = (language_datatype_t*)core("InitError");
    language_missingcodeerror_type = (language_datatype_t*)core("MissingCodeError");
    language_precompilable_error = language_new_struct_uninit((language_datatype_t*)core("PrecompilableError"));
    language_pair_type           = core("Pair");
    language_kwcall_func         = core("kwcall");
    language_kwcall_mt           = ((language_datatype_t*)language_typeof(language_kwcall_func))->name->mt;
    language_atomic_store_relaxed(&language_kwcall_mt->max_args, 0);

    language_weakref_type = (language_datatype_t*)core("WeakRef");
    language_vecelement_typename = ((language_datatype_t*)language_unwrap_unionall(core("VecElement")))->name;
    language_nulldebuginfo = (language_debuginfo_t*)core("NullDebugInfo");

    language_init_box_caches();

    // set module field of primitive types
    language_svec_t *bindings = language_atomic_load_relaxed(&language_core_module->bindings);
    language_value_t **table = language_svec_data(bindings);
    for (size_t i = 0; i < language_svec_len(bindings); i++) {
        if (table[i] != language_nothing) {
            language_binding_t *b = (language_binding_t*)table[i];
            language_value_t *v = language_atomic_load_relaxed(&b->value);
            if (v) {
                if (language_is_unionall(v))
                    v = language_unwrap_unionall(v);
                if (language_is_datatype(v)) {
                    language_datatype_t *tt = (language_datatype_t*)v;
                    tt->name->module = language_core_module;
                    if (tt->name->mt)
                        tt->name->mt->module = language_core_module;
                }
            }
        }
    }

    export_language_small_typeof();
}

void post_image_load_hooks(void) {
    // Ensure that `Base` has been loaded.
    assert(language_base_module != NULL);

    language_libdl_module = (language_module_t *)language_get_global(
        ((language_module_t *)language_get_global(language_base_module, language_symbol("Libc"))),
        language_symbol("Libdl")
    );
    language_libdl_dlopen_func = language_get_global(
        language_libdl_module,
        language_symbol("dlopen")
    );
}
#undef XX

#ifdef __cplusplus
}
#endif
