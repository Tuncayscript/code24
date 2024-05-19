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
  subtyping predicate

  Uses the algorithm described in section 4.2.2 of https://github.com/JeffBezanson/phdthesis/
  This code adds the following features to the core algorithm:

  - Type variables can be restricted to range over only concrete types.
    This is done by returning false if such a variable's lower bound is not concrete.
  - Diagonal rule: a type variable is concrete if it occurs more than once in
    covariant position, and never in invariant position. This sounds like a syntactic
    property, but actually isn't since it depends on which occurrences of a type
    variable the algorithm actually uses.
  - Unconstrained type vars (Bottom<:T<:Any) can match non-type values.
  - Vararg types have an int-valued length parameter N (in `Vararg{T,N}`).
  - Type{T}<:S if isa(T,S). Existing code assumes this, but it's not strictly
    correct since a type can equal `T` without having the same representation.
  - Free type variables are tolerated. This can hopefully be removed after a
    deprecation period.
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

// stack of bits to keep track of which combination of Union components we are
// looking at (0 for Union.a, 1 for Union.b). forall_exists_subtype and
// exists_subtype loop over all combinations by updating a binary count in
// this structure.
// Union type decision points are discovered while the algorithm works.
// If a new Union decision is encountered, the `more` flag is set to tell
// the forall/exists loop to grow the stack.
// TODO: the stack probably needs to be artificially large because of some
// deeper problem (see #21191) and could be shrunk once that is fixed
typedef struct {
    int16_t depth;
    int16_t more;
    int16_t used;
    uint32_t stack[100];  // stack of bits represented as a bit vector
} language_unionstate_t;

typedef struct {
    int16_t depth;
    int16_t more;
    int16_t used;
    void *stack;
} language_saved_unionstate_t;

// Linked list storing the type variable environment. A new language_varbinding_t
// is pushed for each UnionAll type we encounter. `lb` and `ub` are updated
// during the computation.
// Most of the complexity is due to the "diagonal rule", requiring us to
// identify which type vars range over only concrete types.
typedef struct language_varbinding_t {
    language_tvar_t *var;
    language_value_t *lb;
    language_value_t *ub;
    int8_t right;       // whether this variable came from the right side of `A <: B`
    int8_t occurs;      // occurs in any position
    int8_t occurs_inv;  // occurs in invariant position
    int8_t occurs_cov;  // # of occurrences in covariant position
    int8_t concrete;    // 1 if another variable has a constraint forcing this one to be concrete
    int8_t max_offset;  // record the maximum positive offset of the variable (up to 32)
                        // max_offset < 0 if this variable occurs outside VarargNum.
    // constraintkind: in covariant position, we try three different ways to compute var ∩ type:
    // let ub = var.ub ∩ type
    // 0 - var.ub <: type ? var : ub
    // 1 - var.ub = ub; return var
    // 2 - var.lb = lb; return ub
    int8_t constraintkind;
    int8_t intvalued; // intvalued: must be integer-valued; i.e. occurs as N in Vararg{_,N}
    int8_t limited;
    int8_t intersected; // whether this variable has been intersected
    int16_t depth0;         // # of invariant constructors nested around the UnionAll type for this var
    // array of typevars that our bounds depend on, whose UnionAlls need to be
    // moved outside ours.
    language_array_t *innervars;
    struct language_varbinding_t *prev;
} language_varbinding_t;

typedef struct language_ivarbinding_t {
    language_tvar_t **var;
    language_value_t **lb;
    language_value_t **ub;
    language_varbinding_t *root;
    struct language_ivarbinding_t *next;
} language_ivarbinding_t;

// subtype algorithm state
typedef struct language_stenv_t {
    // N.B.: varbindings are created on the stack and rooted there
    language_varbinding_t *vars;    // type variable environment
    language_unionstate_t Lunions;  // union state for unions on the left of A <: B
    language_unionstate_t Runions;  // union state for unions on the right
    // N.B.: envout is gc-rooted
    language_value_t **envout;      // for passing caller the computed bounds of right-side variables
    int envsz;                // length of envout
    int envidx;               // current index in envout
    int invdepth;             // current number of invariant constructors we're nested in
    int ignore_free;          // treat free vars as black boxes; used during intersection
    int intersection;         // true iff subtype is being called from intersection
    int emptiness_only;       // true iff intersection only needs to test for emptiness
    int triangular;           // when intersecting Ref{X} with Ref{<:Y}
    // Used to represent the length difference between 2 vararg.
    // intersect(X, Y) ==> X = Y + Loffset
    int Loffset;
} language_stenv_t;

// state manipulation utilities

// look up a type variable in an environment
#ifdef __clang_gcanalyzer__
static language_varbinding_t *lookup(language_stenv_t *e, language_tvar_t *v) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;
#else
static language_varbinding_t *lookup(language_stenv_t *e, language_tvar_t *v) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT
{
    language_varbinding_t *b = e->vars;
    while (b != NULL) {
        if (b->var == v) return b;
        b = b->prev;
    }
    return b;
}
#endif

static int statestack_get(language_unionstate_t *st, int i) LANGUAGE_NOTSAFEPOINT
{
    assert(i >= 0 && i < sizeof(st->stack) * 8);
    // get the `i`th bit in an array of 32-bit words
    return (st->stack[i>>5] & (1u<<(i&31))) != 0;
}

static void statestack_set(language_unionstate_t *st, int i, int val) LANGUAGE_NOTSAFEPOINT
{
    assert(i >= 0 && i < sizeof(st->stack) * 8);
    if (val)
        st->stack[i>>5] |= (1u<<(i&31));
    else
        st->stack[i>>5] &= ~(1u<<(i&31));
}

#define push_unionstate(saved, src)                                     \
    do {                                                                \
        (saved)->depth = (src)->depth;                                  \
        (saved)->more = (src)->more;                                    \
        (saved)->used = (src)->used;                                    \
        (saved)->stack = alloca(((src)->used+7)/8);                     \
        memcpy((saved)->stack, &(src)->stack, ((src)->used+7)/8);       \
    } while (0);

#define pop_unionstate(dst, saved)                                      \
    do {                                                                \
        (dst)->depth = (saved)->depth;                                  \
        (dst)->more = (saved)->more;                                    \
        (dst)->used = (saved)->used;                                    \
        memcpy(&(dst)->stack, (saved)->stack, ((saved)->used+7)/8);     \
    } while (0);

static int current_env_length(language_stenv_t *e)
{
    language_varbinding_t *v = e->vars;
    int len = 0;
    while (v) {
        len++;
        v = v->prev;
    }
    return len;
}

typedef struct {
    int8_t *buf;
    int rdepth;
    int8_t _space[32]; // == 8 * 4
    language_gcframe_t gcframe;
    language_value_t *roots[24]; // == 8 * 3
} language_savedenv_t;

static void re_save_env(language_stenv_t *e, language_savedenv_t *se, int root)
{
    language_value_t **roots = NULL;
    int nroots = 0;
    if (root) {
        if (se->gcframe.nroots == LANGUAGE_GC_ENCODE_PUSHARGS(1)) {
            language_svec_t *sv = (language_svec_t*)se->roots[0];
            assert(language_is_svec(sv));
            roots = language_svec_data(sv);
            nroots = language_svec_len(sv);
        }
        else {
            roots = se->roots;
            nroots = se->gcframe.nroots >> 2;
        }
    }
    language_varbinding_t *v = e->vars;
    int i = 0, j = 0;
    while (v != NULL) {
        if (root) {
            roots[i++] = v->lb;
            roots[i++] = v->ub;
            roots[i++] = (language_value_t*)v->innervars;
        }
        se->buf[j++] = v->occurs;
        se->buf[j++] = v->occurs_inv;
        se->buf[j++] = v->occurs_cov;
        se->buf[j++] = v->max_offset;
        v = v->prev;
    }
    assert(i == nroots); (void)nroots;
    se->rdepth = e->Runions.depth;
}

static void alloc_env(language_stenv_t *e, language_savedenv_t *se, int root)
{
    language_task_t *ct = language_current_task;
    int len = current_env_length(e);
    se->gcframe.nroots = 0;
    se->gcframe.prev = NULL;
    se->roots[0] = NULL;
    if (len > 8) {
        if (root) {
            se->gcframe.nroots = LANGUAGE_GC_ENCODE_PUSHARGS(1);
            se->gcframe.prev = ct->gcstack;
            ct->gcstack = &se->gcframe;
            language_svec_t *sv = language_alloc_svec(len * 3);
            se->roots[0] = (language_value_t*)sv;
        }
    }
    else {
        if (root && len) {
            for (int i = 0; i < len * 3; i++)
                se->roots[i] = NULL;
            se->gcframe.nroots = LANGUAGE_GC_ENCODE_PUSHARGS(len * 3);
            se->gcframe.prev = ct->gcstack;
            ct->gcstack = &se->gcframe;
        }
    }
    se->buf = (len > 8 ? (int8_t*)malloc_s(len * 4) : se->_space);
#ifdef __clang_gcanalyzer__
    memset(se->buf, 0, len * 3);
#endif
}

static void save_env(language_stenv_t *e, language_savedenv_t *se, int root)
{
    alloc_env(e, se, root);
    re_save_env(e, se, root);
}

static void free_env(language_savedenv_t *se) LANGUAGE_NOTSAFEPOINT
{
    if (se->gcframe.nroots) {
        assert(language_current_task->gcstack == &se->gcframe);
        LANGUAGE_GC_POP();
    }
    if (se->buf != se->_space)
        free(se->buf);
    se->buf = NULL;
}

static void restore_env(language_stenv_t *e, language_savedenv_t *se, int root) LANGUAGE_NOTSAFEPOINT
{
    language_value_t **roots = NULL;
    int nroots = 0;
    if (root) {
        if (se->gcframe.nroots == LANGUAGE_GC_ENCODE_PUSHARGS(1)) {
            language_svec_t *sv = (language_svec_t*)se->roots[0];
            assert(language_is_svec(sv));
            roots = language_svec_data(sv);
            nroots = language_svec_len(sv);
        }
        else {
            roots = se->roots;
            nroots = se->gcframe.nroots >> 2;
        }
    }
    language_varbinding_t *v = e->vars;
    int i = 0, j = 0;
    while (v != NULL) {
        if (root) {
            v->lb = roots[i++];
            v->ub = roots[i++];
            v->innervars = (language_array_t*)roots[i++];
        }
        v->occurs = se->buf[j++];
        v->occurs_inv = se->buf[j++];
        v->occurs_cov = se->buf[j++];
        v->max_offset = se->buf[j++];
        v = v->prev;
    }
    assert(i == nroots); (void)nroots;
    e->Runions.depth = se->rdepth;
    if (e->envout && e->envidx < e->envsz)
        memset(&e->envout[e->envidx], 0, (e->envsz - e->envidx)*sizeof(void*));
}

static void clean_occurs(language_stenv_t *e)
{
    language_varbinding_t *v = e->vars;
    while (v) {
        v->occurs = 0;
        v = v->prev;
    }
}

#define flip_offset(e) ((e)->Loffset *= -1)

// type utilities

// quickly test that two types are identical
static int obviously_egal(language_value_t *a, language_value_t *b) LANGUAGE_NOTSAFEPOINT
{
    if (a == (language_value_t*)language_typeofbottom_type->super)
        a = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (b == (language_value_t*)language_typeofbottom_type->super)
        b = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (a == b) return 1;
    if (language_typeof(a) != language_typeof(b)) return 0;
    if (language_is_datatype(a)) {
        language_datatype_t *ad = (language_datatype_t*)a;
        language_datatype_t *bd = (language_datatype_t*)b;
        if (ad->name != bd->name) return 0;
        if (ad->isconcretetype || bd->isconcretetype) return 0;
        size_t i, np = language_nparams(ad);
        if (np != language_nparams(bd)) return 0;
        for (i = 0; i < np; i++) {
            if (!obviously_egal(language_tparam(ad,i), language_tparam(bd,i)))
                return 0;
        }
        return 1;
    }
    if (language_is_uniontype(a)) {
        return obviously_egal(((language_uniontype_t*)a)->a, ((language_uniontype_t*)b)->a) &&
            obviously_egal(((language_uniontype_t*)a)->b, ((language_uniontype_t*)b)->b);
    }
    if (language_is_unionall(a)) {
        return ((language_unionall_t*)a)->var == ((language_unionall_t*)b)->var &&
            obviously_egal(((language_unionall_t*)a)->body, ((language_unionall_t*)b)->body);
    }
    if (language_is_vararg(a)) {
        language_vararg_t *vma = (language_vararg_t *)a;
        language_vararg_t *vmb = (language_vararg_t *)b;
        return obviously_egal(language_unwrap_vararg(vma), language_unwrap_vararg(vmb)) &&
            ((!vma->N && !vmb->N) || (vma->N && vmb->N && obviously_egal(vma->N, vmb->N)));
    }
    if (language_is_typevar(a)) return 0;
    return !language_is_type(a) && language_egal(a,b);
}

static int obviously_unequal(language_value_t *a, language_value_t *b)
{
    if (a == (language_value_t*)language_typeofbottom_type->super)
        a = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (b == (language_value_t*)language_typeofbottom_type->super)
        b = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (a == b)
        return 0;
    if (language_is_unionall(a))
        a = language_unwrap_unionall(a);
    if (language_is_unionall(b))
        b = language_unwrap_unionall(b);
    if (language_is_datatype(a)) {
        if (b == language_bottom_type)
            return 1;
        if (language_is_datatype(b)) {
            language_datatype_t *ad = (language_datatype_t*)a;
            language_datatype_t *bd = (language_datatype_t*)b;
            if (a == (language_value_t*)language_typeofbottom_type && bd->name == language_type_typename)
                return obviously_unequal(language_bottom_type, language_tparam(bd, 0));
            if (ad->name == language_type_typename && b == (language_value_t*)language_typeofbottom_type)
                return obviously_unequal(language_tparam(ad, 0), language_bottom_type);
            if (ad->name != bd->name)
                return 1;
            int istuple = (ad->name == language_tuple_typename);
            if (language_type_equality_is_identity(a, b))
                return 1;
            size_t i, np;
            if (istuple) {
                size_t na = language_nparams(ad), nb = language_nparams(bd);
                if (language_is_va_tuple(ad)) {
                    na -= 1;
                    if (language_is_va_tuple(bd))
                        nb -= 1;
                }
                else if (language_is_va_tuple(bd)) {
                    nb -= 1;
                }
                else if (na != nb) {
                    return 1;
                }
                np = na < nb ? na : nb;
            }
            else {
                np = language_nparams(ad);
                if (np != language_nparams(bd))
                    return 1;
            }
            for (i = 0; i < np; i++) {
                if (obviously_unequal(language_tparam(ad, i), language_tparam(bd, i)))
                    return 1;
            }
        }
    }
    else if (a == language_bottom_type && language_is_datatype(b)) {
        return 1;
    }
    if (language_is_typevar(a) && language_is_typevar(b) && obviously_unequal(((language_tvar_t*)a)->ub, ((language_tvar_t*)b)->ub))
        return 1;
    if (language_is_long(a)) {
        if (language_is_long(b) && language_unbox_long(a) != language_unbox_long(b))
            return 1;
    }
    else if (language_is_long(b)) {
        return 1;
    }
    if ((language_is_symbol(a) || language_is_symbol(b)) && a != b)
        return 1;
    return 0;
}

int language_obviously_unequal(language_value_t *a, language_value_t *b)
{
    return obviously_unequal(a, b);
}

static int in_union(language_value_t *u, language_value_t *x) LANGUAGE_NOTSAFEPOINT
{
    if (u == x) return 1;
    if (!language_is_uniontype(u)) return 0;
    return in_union(((language_uniontype_t*)u)->a, x) || in_union(((language_uniontype_t*)u)->b, x);
}

static int obviously_in_union(language_value_t *u, language_value_t *x)
{
    language_value_t *a = NULL, *b = NULL;
    if (language_is_uniontype(x)) {
        a = ((language_uniontype_t*)x)->a;
        b = ((language_uniontype_t*)x)->b;
        LANGUAGE_GC_PUSH2(&a, &b);
        int res = obviously_in_union(u, a) && obviously_in_union(u, b);
        LANGUAGE_GC_POP();
        return res;
    }
    if (language_is_uniontype(u)) {
        a = ((language_uniontype_t*)u)->a;
        b = ((language_uniontype_t*)u)->b;
        LANGUAGE_GC_PUSH2(&a, &b);
        int res = obviously_in_union(a, x) || obviously_in_union(b, x);
        LANGUAGE_GC_POP();
        return res;
    }
    return obviously_egal(u, x);
}

int obviously_disjoint(language_value_t *a, language_value_t *b, int specificity)
{
    if (a == b || a == (language_value_t*)language_any_type || b == (language_value_t*)language_any_type)
        return 0;
    if (specificity && a == (language_value_t*)language_typeofbottom_type)
        return 0;
    if (language_is_concrete_type(a) && language_is_concrete_type(b) && language_type_equality_is_identity(a, b))
        return 1;
    if (language_is_unionall(a)) a = language_unwrap_unionall(a);
    if (language_is_unionall(b)) b = language_unwrap_unionall(b);
    if (language_is_uniontype(a))
        return obviously_disjoint(((language_uniontype_t *)a)->a, b, specificity) &&
               obviously_disjoint(((language_uniontype_t *)a)->b, b, specificity);
    if (language_is_uniontype(b))
        return obviously_disjoint(a, ((language_uniontype_t *)b)->a, specificity) &&
               obviously_disjoint(a, ((language_uniontype_t *)b)->b, specificity);
    if (language_is_datatype(a) && language_is_datatype(b)) {
        language_datatype_t *ad = (language_datatype_t*)a, *bd = (language_datatype_t*)b;
        if (ad->name != bd->name) {
            language_datatype_t *temp = ad;
            while (temp != language_any_type && temp->name != bd->name)
                temp = temp->super;
            if (temp == language_any_type) {
                temp = bd;
                while (temp != language_any_type && temp->name != ad->name)
                    temp = temp->super;
                if (temp == language_any_type)
                    return 1;
                bd = temp;
            }
            else {
                ad = temp;
            }
            if (specificity) {
                // account for declared subtypes taking priority (issue #21710)
                return 0;
            }
        }
        int istuple = (ad->name == language_tuple_typename);
        size_t np;
        if (istuple) {
            size_t na = language_nparams(ad), nb = language_nparams(bd);
            if (language_is_va_tuple(ad)) {
                na -= 1;
                if (language_is_va_tuple(bd))
                    nb -= 1;
            }
            else if (language_is_va_tuple(bd)) {
                nb -= 1;
            }
            else if (!specificity && na != nb) {
                // note: some disjoint types (e.g. tuples of different lengths) can be more specific
                return 1;
            }
            np = na < nb ? na : nb;
        }
        else {
            np = language_nparams(ad);
        }
        size_t i;
        for (i = 0; i < np; i++) {
            language_value_t *ai = language_tparam(ad, i);
            language_value_t *bi = language_tparam(bd, i);
            if (language_is_typevar(ai) || language_is_typevar(bi))
                continue; // it's possible that Union{} is in this intersection
            if (language_is_type(ai)) {
                if (language_is_type(bi)) {
                    if (istuple && (ai == language_bottom_type || bi == language_bottom_type))
                        ; // TODO: this can return 1 if and when Tuple{Union{}} === Union{}
                    else if (obviously_disjoint(ai, bi, specificity))
                        return 1;
                }
                else if (ai != (language_value_t*)language_any_type) {
                    return 1;
                }
            }
            else if (language_is_type(bi)) {
                if (bi != (language_value_t*)language_any_type)
                    return 1;
            }
            else if (!language_egal(ai, bi)) {
                return 1;
            }
        }
    }
    else if (a == language_bottom_type || b == language_bottom_type) {
        return 1;
    }
    return 0;
}

language_value_t *simple_union(language_value_t *a, language_value_t *b);
// compute a least upper bound of `a` and `b`
static language_value_t *simple_join(language_value_t *a, language_value_t *b)
{
    if (a == language_bottom_type || b == (language_value_t*)language_any_type || obviously_egal(a, b))
        return b;
    if (b == language_bottom_type || a == (language_value_t*)language_any_type)
        return a;
    if (!(language_is_type(a) || language_is_typevar(a)) || !(language_is_type(b) || language_is_typevar(b)))
        return (language_value_t*)language_any_type;
    if (language_is_kind(a) && language_is_type_type(b) && language_typeof(language_tparam0(b)) == a)
        return a;
    if (language_is_kind(b) && language_is_type_type(a) && language_typeof(language_tparam0(a)) == b)
        return b;
    if (language_is_typevar(a) && obviously_egal(b, ((language_tvar_t*)a)->lb))
        return a;
    if (language_is_typevar(b) && obviously_egal(a, ((language_tvar_t*)b)->lb))
        return b;
    return simple_union(a, b);
}

language_value_t *simple_intersect(language_value_t *a, language_value_t *b, int overesi);
// Compute a greatest lower bound of `a` and `b`
// For the subtype path, we need to over-estimate this by returning `b` in many cases.
// But for `merge_env`, we'd better under-estimate and return a `Union{}`
static language_value_t *simple_meet(language_value_t *a, language_value_t *b, int overesi)
{
    if (a == (language_value_t*)language_any_type || b == language_bottom_type || obviously_egal(a,b))
        return b;
    if (b == (language_value_t*)language_any_type || a == language_bottom_type)
        return a;
    if (!(language_is_type(a) || language_is_typevar(a)) || !(language_is_type(b) || language_is_typevar(b)))
        return language_bottom_type;
    if (language_is_kind(a) && language_is_type_type(b) && language_typeof(language_tparam0(b)) == a)
        return b;
    if (language_is_kind(b) && language_is_type_type(a) && language_typeof(language_tparam0(a)) == b)
        return a;
    if (language_is_typevar(a) && obviously_egal(b, ((language_tvar_t*)a)->ub))
        return a;
    if (language_is_typevar(b) && obviously_egal(a, ((language_tvar_t*)b)->ub))
        return b;
    return simple_intersect(a, b, overesi);
}

// main subtyping algorithm

static int subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param);

static int next_union_state(language_stenv_t *e, int8_t R) LANGUAGE_NOTSAFEPOINT
{
    language_unionstate_t *state = R ? &e->Runions : &e->Lunions;
    if (state->more == 0)
        return 0;
    // reset `used` and let `pick_union_decision` clean the stack.
    state->used = state->more;
    statestack_set(state, state->used - 1, 1);
    return 1;
}

static int pick_union_decision(language_stenv_t *e, int8_t R) LANGUAGE_NOTSAFEPOINT
{
    language_unionstate_t *state = R ? &e->Runions : &e->Lunions;
    if (state->depth >= state->used) {
        statestack_set(state, state->used, 0);
        state->used++;
    }
    int ui = statestack_get(state, state->depth);
    state->depth++;
    if (ui == 0)
        state->more = state->depth; // memorize that this was the deepest available choice
    return ui;
}

static language_value_t *pick_union_element(language_value_t *u LANGUAGE_PROPAGATES_ROOT, language_stenv_t *e, int8_t R) LANGUAGE_NOTSAFEPOINT
{
    do {
        if (pick_union_decision(e, R))
            u = ((language_uniontype_t*)u)->b;
        else
            u = ((language_uniontype_t*)u)->a;
    } while (language_is_uniontype(u));
    return u;
}

static int local_forall_exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param, int limit_slow);

// subtype for variable bounds consistency check. needs its own forall/exists environment.
static int subtype_ccheck(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    if (language_is_long(x) && language_is_long(y))
        return language_unbox_long(x) == language_unbox_long(y) + e->Loffset;
    if (x == y)
        return 1;
    if (x == language_bottom_type && language_is_type(y))
        return 1;
    if (y == (language_value_t*)language_any_type && language_is_type(x))
        return 1;
    if (language_is_uniontype(x) && language_egal(x, y))
        return 1;
    if (x == (language_value_t*)language_any_type && language_is_datatype(y))
        return 0;
    language_saved_unionstate_t oldLunions; push_unionstate(&oldLunions, &e->Lunions);
    int sub = local_forall_exists_subtype(x, y, e, 0, 1);
    pop_unionstate(&e->Lunions, &oldLunions);
    return sub;
}

static int subtype_left_var(language_value_t *x, language_value_t *y, language_stenv_t *e, int param)
{
    if (language_is_long(x) && language_is_long(y))
        return language_unbox_long(x) == language_unbox_long(y) + e->Loffset;
    if (x == y && !(language_is_unionall(y)))
        return 1;
    if (x == language_bottom_type && language_is_type(y))
        return 1;
    if (y == (language_value_t*)language_any_type && language_is_type(x))
        return 1;
    if (language_is_uniontype(x) && language_egal(x, y))
        return 1;
    if (x == (language_value_t*)language_any_type && language_is_datatype(y))
        return 0;
    return subtype(x, y, e, param);
}

// use the current context to record where a variable occurred, for the purpose
// of determining whether the variable is concrete.
static void record_var_occurrence(language_varbinding_t *vb, language_stenv_t *e, int param) LANGUAGE_NOTSAFEPOINT
{
    if (vb != NULL)
        vb->occurs = 1;
    if (vb != NULL && param) {
        // saturate counters at 2; we don't need values bigger than that
        if (param == 2 && e->invdepth > vb->depth0) {
            if (vb->occurs_inv < 2)
                vb->occurs_inv++;
        }
        else if (vb->occurs_cov < 2) {
            vb->occurs_cov++;
        }
        // Always set `max_offset` to `-1` during the 1st round intersection.
        // Would be recovered in `intersect_varargs`/`subtype_tuple_varargs` if needed.
        if (!vb->intersected)
            vb->max_offset = -1;
    }
}

// is var x's quantifier outside y's in nesting order
static int var_outside(language_stenv_t *e, language_tvar_t *x, language_tvar_t *y)
{
    language_varbinding_t *btemp = e->vars;
    while (btemp != NULL) {
        if (btemp->var == x) return 0;
        if (btemp->var == y) return 1;
        btemp = btemp->prev;
    }
    return 0;
}

static language_value_t *intersect_aside(language_value_t *x, language_value_t *y, language_stenv_t *e, int depth);

static int reachable_var(language_value_t *x, language_tvar_t *y, language_stenv_t *e);

// check that type var `b` is <: `a`, and update b's upper bound.
static int var_lt(language_tvar_t *b, language_value_t *a, language_stenv_t *e, int param)
{
    language_varbinding_t *bb = lookup(e, b);
    if (bb == NULL)
        return e->ignore_free || subtype_left_var(b->ub, a, e, param);
    record_var_occurrence(bb, e, param);
    assert(!language_is_long(a) || e->Loffset == 0);
    if (e->Loffset != 0 && !language_is_typevar(a) &&
        a != language_bottom_type && a != (language_value_t *)language_any_type)
        return 0;
    if (!bb->right)  // check ∀b . b<:a
        return subtype_left_var(bb->ub, a, e, param);
    if (bb->ub == a)
        return 1;
    if (!((bb->lb == language_bottom_type && !language_is_type(a) && !language_is_typevar(a)) || subtype_ccheck(bb->lb, a, e)))
        return 0;
    // for this to work we need to compute issub(left,right) before issub(right,left),
    // since otherwise the issub(a, bb.ub) check in var_gt becomes vacuous.
    if (e->intersection) {
        language_value_t *ub = intersect_aside(a, bb->ub, e, bb->depth0);
        LANGUAGE_GC_PUSH1(&ub);
        if (ub != (language_value_t*)b && (!language_is_typevar(ub) || !reachable_var(ub, b, e)))
            bb->ub = ub;
        LANGUAGE_GC_POP();
    }
    else {
        bb->ub = simple_meet(bb->ub, a, 1);
    }
    assert(bb->ub != (language_value_t*)b);
    if (language_is_typevar(a)) {
        language_varbinding_t *aa = lookup(e, (language_tvar_t*)a);
        if (aa && !aa->right && in_union(bb->lb, a) && bb->depth0 != aa->depth0 && var_outside(e, b, (language_tvar_t*)a)) {
            // an "exists" var cannot equal a "forall" var inside it unless the forall
            // var has equal bounds.
            return subtype_left_var(aa->ub, aa->lb, e, param);
        }
    }
    return 1;
}

// check that type var `b` is >: `a`, and update b's lower bound.
static int var_gt(language_tvar_t *b, language_value_t *a, language_stenv_t *e, int param)
{
    language_varbinding_t *bb = lookup(e, b);
    if (bb == NULL)
        return e->ignore_free || subtype_left_var(a, b->lb, e, param);
    record_var_occurrence(bb, e, param);
    assert(!language_is_long(a) || e->Loffset == 0);
    if (e->Loffset != 0 && !language_is_typevar(a) &&
        a != language_bottom_type && a != (language_value_t *)language_any_type)
        return 0;
    if (!bb->right)  // check ∀b . b>:a
        return subtype_left_var(a, bb->lb, e, param);
    if (bb->lb == a)
        return 1;
    if (!((bb->ub == (language_value_t*)language_any_type && !language_is_type(a) && !language_is_typevar(a)) || subtype_ccheck(a, bb->ub, e)))
        return 0;
    language_value_t *lb = simple_join(bb->lb, a);
    LANGUAGE_GC_PUSH1(&lb);
    if (!e->intersection || !language_is_typevar(lb) || !reachable_var(lb, b, e))
        bb->lb = lb;
    LANGUAGE_GC_POP();
    // this bound should not be directly circular
    assert(bb->lb != (language_value_t*)b);
    if (language_is_typevar(a)) {
        language_varbinding_t *aa = lookup(e, (language_tvar_t*)a);
        if (aa && !aa->right && bb->depth0 != aa->depth0 && param == 2 && var_outside(e, b, (language_tvar_t*)a))
            return subtype_left_var(aa->ub, aa->lb, e, param);
    }
    return 1;
}

static int subtype_var(language_tvar_t *b, language_value_t *a, language_stenv_t *e, int R, int param)
{
    if (e->intersection) {
        language_varbinding_t *bb = lookup(e, (language_tvar_t*)b);
        language_value_t *bub = bb ? bb->ub : ((language_tvar_t*)b)->ub;
        language_value_t *blb = bb ? bb->lb : ((language_tvar_t*)b)->lb;
        if (bub == blb && language_is_typevar(bub)) {
            int sub = subtype_var((language_tvar_t *)bub, a, e, R, param);
            return sub;
        }
    }
    if (e->Loffset != 0 && language_is_long(a)) {
        int old_offset = R ? -e->Loffset : e->Loffset;
        language_value_t *na = language_box_long(language_unbox_long(a) + old_offset);
        LANGUAGE_GC_PUSH1(&na);
        e->Loffset = 0;
        int sub = R ? var_gt(b, na, e, param) : var_lt(b, na, e, param);
        e->Loffset = R ? -old_offset : old_offset;
        LANGUAGE_GC_POP();
        return sub;
    }
    return R ? var_gt(b, a, e, param) : var_lt(b, a, e, param);
}

// check that a type is concrete or quasi-concrete (Type{T}).
// this is used to check concrete typevars:
// issubtype is false if the lower bound of a concrete type var is not concrete.
int is_leaf_bound(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    if (v == language_bottom_type)
        return 1;
    if (language_is_datatype(v)) {
        if (((language_datatype_t*)v)->name->abstract) {
            if (language_is_type_type(v))
                return 1;//!language_has_free_typevars(language_tparam0(v));
            return 0;
        }
        return ((language_datatype_t*)v)->isconcretetype;
    }
    return !language_is_type(v) && !language_is_typevar(v);
}

static int is_leaf_typevar(language_tvar_t *v) LANGUAGE_NOTSAFEPOINT
{
    return is_leaf_bound(v->lb);
}

static language_value_t *widen_Type(language_value_t *t LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_type_type(t) && !language_is_typevar(language_tparam0(t)))
        return language_typeof(language_tparam0(t));
    if (language_is_uniontype(t)) {
        language_value_t *a = widen_Type(((language_uniontype_t*)t)->a);
        language_value_t *b = widen_Type(((language_uniontype_t*)t)->b);
        if (a == b)
            return a;
    }
    return t;
}

// convert a type with free variables to a typevar bounded by a UnionAll-wrapped
// version of that type.
// TODO: This loses some inference precision. For example in a case where a
// variable bound is `Vector{_}`, we could potentially infer `Type{Vector{_}} where _`,
// but this causes us to infer the larger `Type{T} where T<:Vector` instead.
// However this is needed because many contexts check `isa(sp, TypeVar)` to determine
// when a static parameter value is not known exactly.
static language_value_t *fix_inferred_var_bound(language_tvar_t *var, language_value_t *ty LANGUAGE_MAYBE_UNROOTED)
{
    if (ty == NULL) // may happen if the user is intersecting with an incomplete type
        return (language_value_t*)var;
    if (!language_is_typevar(ty) && language_has_free_typevars(ty)) {
        language_value_t *ans = ty;
        language_array_t *vs = NULL;
        LANGUAGE_GC_PUSH2(&ans, &vs);
        vs = language_find_free_typevars(ty);
        int i;
        for (i = 0; i < language_array_nrows(vs); i++) {
            ans = language_type_unionall((language_tvar_t*)language_array_ptr_ref(vs, i), ans);
        }
        ans = (language_value_t*)language_new_typevar(var->name, language_bottom_type, ans);
        LANGUAGE_GC_POP();
        return ans;
    }
    return ty;
}

static int var_occurs_inside(language_value_t *v, language_tvar_t *var, int inside, int want_inv) LANGUAGE_NOTSAFEPOINT;

typedef int (*tvar_callback)(void*, int8_t, language_stenv_t *, int);

static int var_occurs_invariant(language_value_t *v, language_tvar_t *var) LANGUAGE_NOTSAFEPOINT
{
    return var_occurs_inside(v, var, 0, 1);
}

static language_unionall_t *unalias_unionall(language_unionall_t *u, language_stenv_t *e)
{
    language_varbinding_t *btemp = e->vars;
    // if the var for this unionall (based on identity) already appears somewhere
    // in the environment, rename to get a fresh var.
    LANGUAGE_GC_PUSH1(&u);
    while (btemp != NULL) {
        int aliased = btemp->var == u->var ||
            // outer var can only refer to inner var if bounds changed (mainly for subtyping path)
            (btemp->lb != btemp->var->lb && language_has_typevar(btemp->lb, u->var)) ||
            (btemp->ub != btemp->var->ub && language_has_typevar(btemp->ub, u->var));
        if (!aliased && btemp->innervars != NULL) {
            for (size_t i = 0; i < language_array_len(btemp->innervars); i++) {
                language_tvar_t *ivar = (language_tvar_t*)language_array_ptr_ref(btemp->innervars, i);
                if (ivar == u->var) {
                    aliased = 1;
                    break;
                }
            }
        }
        if (aliased) {
            u = language_rename_unionall(u);
            break;
        }
        btemp = btemp->prev;
    }
    LANGUAGE_GC_POP();
    return u;
}

static int subtype_unionall(language_value_t *t, language_unionall_t *u, language_stenv_t *e, int8_t R, int param)
{
    u = unalias_unionall(u, e);
    language_varbinding_t vb = { u->var, u->var->lb, u->var->ub, R, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           e->invdepth, NULL, e->vars };
    LANGUAGE_GC_PUSH4(&u, &vb.lb, &vb.ub, &vb.innervars);
    e->vars = &vb;
    int ans;
    if (R) {
        e->envidx++;
        ans = subtype(t, u->body, e, param);
        e->envidx--;
        // widen Type{x} to typeof(x) in argument position
        if (!vb.occurs_inv)
            vb.lb = widen_Type(vb.lb);
        }
    else
        ans = subtype(u->body, t, e, param);

    // handle the "diagonal dispatch" rule, which says that a type var occurring more
    // than once, and only in covariant position, is constrained to concrete types. E.g.
    //  ( Tuple{Int, Int}    <: Tuple{T, T} where T) but
    // !( Tuple{Int, String} <: Tuple{T, T} where T)
    // Then check concreteness by checking that the lower bound is not an abstract type.
    int diagonal = vb.occurs_cov > 1 && !var_occurs_invariant(u->body, u->var);
    if (ans && (vb.concrete || (diagonal && is_leaf_typevar(u->var)))) {
        if (vb.concrete && !diagonal && !is_leaf_bound(vb.ub)) {
            // a non-diagonal var can only be a subtype of a diagonal var if its
            // upper bound is concrete.
            ans = 0;
        }
        else if (language_is_typevar(vb.lb)) {
            language_tvar_t *v = (language_tvar_t*)vb.lb;
            language_varbinding_t *vlb = lookup(e, v);
            if (vlb)
                vlb->concrete = 1;
        }
        else if (!is_leaf_bound(vb.lb)) {
            ans = 0;
        }
    }

    e->vars = vb.prev;

    if (!ans) {
        LANGUAGE_GC_POP();
        return 0;
    }

    language_varbinding_t *btemp = e->vars;
    if (vb.lb != vb.ub) {
        while (btemp != NULL) {
            language_value_t *vu = btemp->ub;
            language_value_t *vl = btemp->lb;
            // TODO: this takes a significant amount of time
            if (btemp->depth0 != vb.depth0 &&
                ((vu != (language_value_t*)vb.var && btemp->var->ub != vu && var_occurs_inside(vu, vb.var, 0, 0)) ||
                 (vl != (language_value_t*)vb.var && btemp->var->lb != vl && var_occurs_inside(vl, vb.var, 0, 0)))) {
                ans = 0; break;
            }
            btemp = btemp->prev;
        }
    }

    // fill variable values into `envout` up to `envsz`
    if (R && ans && e->envidx < e->envsz) {
        language_value_t *val;
        if (vb.intvalued && vb.lb == (language_value_t*)language_any_type)
            val = (language_value_t*)language_wrap_vararg(NULL, NULL, 0, 0); // special token result that represents N::Int in the envout
        else if (!vb.occurs_inv && vb.lb != language_bottom_type)
            val = is_leaf_bound(vb.lb) ? vb.lb : (language_value_t*)language_new_typevar(u->var->name, language_bottom_type, vb.lb);
        else if (vb.lb == vb.ub)
            val = vb.lb;
        else if (vb.lb != language_bottom_type)
            // TODO: for now return the least solution, which is what
            // method parameters expect.
            val = vb.lb;
        else if (vb.lb == u->var->lb && vb.ub == u->var->ub)
            val = (language_value_t*)u->var;
        else
            val = (language_value_t*)language_new_typevar(u->var->name, vb.lb, vb.ub);
        language_value_t *oldval = e->envout[e->envidx];
        // if we try to assign different variable values (due to checking
        // multiple union members), consider the value unknown.
        if (oldval && !language_egal(oldval, val))
            e->envout[e->envidx] = (language_value_t*)u->var;
        else
            e->envout[e->envidx] = val;
        // TODO: substitute the value (if any) of this variable into previous envout entries
    }

    LANGUAGE_GC_POP();
    return ans;
}

// check n <: (length of vararg type v)
static int check_vararg_length(language_value_t *v, ssize_t n, language_stenv_t *e)
{
    language_value_t *N = language_unwrap_vararg_num(v);
    // only do the check if N is free in the tuple type's last parameter
    if (N) {
        language_value_t *nn = language_box_long(n);
        LANGUAGE_GC_PUSH1(&nn);
        e->invdepth++;
        int ans = subtype(nn, N, e, 2) && subtype(N, nn, e, 0);
        e->invdepth--;
        LANGUAGE_GC_POP();
        if (!ans)
            return 0;
    }
    return 1;
}

static int forall_exists_equal(language_value_t *x, language_value_t *y, language_stenv_t *e);

static int subtype_tuple_varargs(
    language_vararg_t *vtx, language_vararg_t *vty,
    size_t vx, size_t vy,
    language_stenv_t *e, int param)
{
    language_value_t *xp0 = language_unwrap_vararg(vtx); language_value_t *xp1 = language_unwrap_vararg_num(vtx);
    language_value_t *yp0 = language_unwrap_vararg(vty); language_value_t *yp1 = language_unwrap_vararg_num(vty);

    language_varbinding_t *xlv = NULL, *ylv = NULL;
    if (xp1 && language_is_typevar(xp1))
        xlv = lookup(e, (language_tvar_t*)xp1);
    if (yp1 && language_is_typevar(yp1))
        ylv = lookup(e, (language_tvar_t*)yp1);

    int8_t max_offsetx = xlv ? xlv->max_offset : 0;
    int8_t max_offsety = ylv ? ylv->max_offset : 0;

    language_value_t *xl = xlv ? xlv->lb : xp1;
    language_value_t *yl = ylv ? ylv->lb : yp1;

    if (!xp1) {
        // Unconstrained on the left, constrained on the right
        if (yl && language_is_long(yl))
            return 0;
    }
    else {
        if (language_is_long(xl)) {
            if (language_unbox_long(xl) + 1 == vx) {
                // LHS is exhausted. We're a subtype if the RHS is either
                // exhausted as well or unbounded (in which case we need to
                // set it to 0).
                if (yl) {
                    if (language_is_long(yl)) {
                        return language_unbox_long(yl) + 1 == vy;
                    }
                } else {
                    // We can skip the subtype check, but we still
                    // need to make sure to constrain the length of y
                    // to 0.
                    goto constrain_length;
                }
            }
        }
    }

    // in Vararg{T1} <: Vararg{T2}, need to check subtype twice to
    // simulate the possibility of multiple arguments, which is needed
    // to implement the diagonal rule correctly.
    if (!subtype(xp0, yp0, e, param)) return 0;
    if (!subtype(xp0, yp0, e, 1)) return 0;

constrain_length:
    if (!yp1) {
        return 1;
    }
    if (!xp1) {
        language_value_t *yl = yp1;
        language_varbinding_t *ylv = NULL;
        if (language_is_typevar(yl)) {
            ylv = lookup(e, (language_tvar_t*)yl);
            if (ylv)
                yl = ylv->lb;
        }
        if (language_is_long(yl)) {
            // The length of the x tuple is unconstrained, but the
            // length of the y tuple is now fixed (this could have happened
            // as a result of the subtype call above).
            return 0;
        }

        if (ylv) {
            if (ylv->depth0 != e->invdepth ||
                ylv->lb != language_bottom_type ||
                ylv->ub != (language_value_t *)language_any_type)
                return 0;
            ylv->intvalued = 1;
        }
        // set lb to Any. Since `intvalued` is set, we'll interpret that
        // appropriately.
        e->invdepth++;
        int ans = subtype((language_value_t*)language_any_type, yp1, e, 2);
        if (ylv && !ylv->intersected)
            ylv->max_offset = max_offsety;
        e->invdepth--;
        return ans;
    }

    // Vararg{T,N} <: Vararg{T2,N2}; equate N and N2
    e->invdepth++;
    LANGUAGE_GC_PUSH2(&xp1, &yp1);
    int ans;
    language_varbinding_t *bxp1 = language_is_typevar(xp1) ? lookup(e, (language_tvar_t *)xp1) : NULL;
    language_varbinding_t *byp1 = language_is_typevar(yp1) ? lookup(e, (language_tvar_t *)yp1) : NULL;
    if (bxp1) {
        if (bxp1->intvalued == 0)
            bxp1->intvalued = 1;
        if (language_is_long(bxp1->lb))
            xp1 = bxp1->lb;
    }
    if (byp1) {
        if (byp1->intvalued == 0)
            byp1->intvalued = 1;
        if (language_is_long(byp1->lb))
            yp1 = byp1->lb;
    }
    if (language_is_long(xp1) && language_is_long(yp1))
        ans = language_unbox_long(xp1) - vx == language_unbox_long(yp1) - vy;
    else {
        if (language_is_long(xp1) && vx != vy) {
            xp1 = language_box_long(language_unbox_long(xp1) + vy - vx);
            vx = vy;
        }
        if (language_is_long(yp1) && vy != vx) {
            yp1 = language_box_long(language_unbox_long(yp1) + vx - vy);
            vy = vx;
        }
        assert(e->Loffset == 0);
        e->Loffset = vx - vy;
        ans = forall_exists_equal(xp1, yp1, e);
        assert(e->Loffset == vx - vy);
        e->Loffset = 0;
    }
    LANGUAGE_GC_POP();
    if (ylv && !ylv->intersected)
        ylv->max_offset = max_offsety;
    if (xlv && !xlv->intersected)
        xlv->max_offset = max_offsetx;
    e->invdepth--;
    return ans;
}

static int subtype_tuple_tail(language_datatype_t *xd, language_datatype_t *yd, int8_t R, language_stenv_t *e, int param)
{
    size_t lx = language_nparams(xd);
    size_t ly = language_nparams(yd);
    size_t i = 0, j = 0, vx = 0, vy = 0, x_reps = 1;
    language_value_t *lastx = NULL, *lasty = NULL;
    language_value_t *xi = NULL, *yi = NULL;

    for (;;) {
        if (i < lx) {
            xi = language_tparam(xd, i);
            if (i == lx-1 && (vx || language_is_vararg(xi))) {
                vx += 1;
            }
        }

        if (j < ly) {
            yi = language_tparam(yd, j);
            if (j == ly-1 && (vy || language_is_vararg(yi))) {
                vy += 1;
            }
        }

        if (i >= lx)
            break;

        int all_varargs = vx && vy;
        if (!all_varargs && vy == 1) {
            if (language_unwrap_vararg(yi) == (language_value_t*)language_any_type) {
                // Tuple{...} <: Tuple{..., Vararg{Any, _}}
                // fast path all the type checks away
                xi = language_tparam(xd, lx-1);
                if (language_is_vararg(xi)) {
                    all_varargs = 1;
                    // count up to lx-2 rather than lx-1.
                    vy += lx - i - 1;
                    vx = 1;
                } else {
                    break;
                }
            }
        }

        if (all_varargs) {
            // Tuple{..., Vararg{xi, _}} <: Tuple{..., Vararg{yi, _}}
            return subtype_tuple_varargs(
                (language_vararg_t*)xi,
                (language_vararg_t*)yi,
                vx, vy, e, param);
        }

        if (j >= ly)
            return !!vx;

        xi = vx ? language_unwrap_vararg(xi) : xi;
        yi = vy ? language_unwrap_vararg(yi) : yi;
        int x_same = vx > 1 || (lastx && obviously_egal(xi, lastx));
        int y_same = vy > 1 || (lasty && obviously_egal(yi, lasty));
        // keep track of number of consecutive identical subtyping
        x_reps = y_same && x_same ? x_reps + 1 : 1;
        if (x_reps > 2) {
            // an identical type on the left doesn't need to be compared to the same
            // element type on the right more than twice.
        }
        else if (x_same && e->Runions.depth == 0 &&
            ((y_same && !language_has_free_typevars(xi) && !language_has_free_typevars(yi)) ||
             (yi == lastx && !vx && vy && language_is_concrete_type(xi)))) {
            // fast path for repeated elements
        }
        else if (e->Runions.depth == 0 && !language_has_free_typevars(xi) && !language_has_free_typevars(yi)) {
            // fast path for separable sub-formulas
            if (!language_subtype(xi, yi))
                return 0;
        }
        else if (!subtype(xi, yi, e, param)) {
            return 0;
        }
        lastx = xi; lasty = yi;
        if (i < lx-1 || !vx)
            i++;
        if (j < ly-1 || !vy)
            j++;
    }

    if (vy && !vx && lx+1 >= ly) {
        // in Tuple{...,tn} <: Tuple{...,Vararg{T,N}}, check (lx+1-ly) <: N
        if (!check_vararg_length(yi, lx+1-ly, e))
            return 0;
    }
    assert((lx + vx == ly + vy) || (vy && (lx >= (vx ? ly : (ly-1)))));
    return 1;
}

static int subtype_tuple(language_datatype_t *xd, language_datatype_t *yd, language_stenv_t *e, int param)
{
    // Check tuple compatibility based on tuple length only (fastpath)
    size_t lx = language_nparams(xd);
    size_t ly = language_nparams(yd);

    if (lx == 0 && ly == 0)
        return 1;

    language_vararg_kind_t vvx = LANGUAGE_VARARG_NONE;
    language_vararg_kind_t vvy = LANGUAGE_VARARG_NONE;
    language_varbinding_t *xbb = NULL;
    language_value_t *xva = NULL, *yva = NULL;
    if (lx > 0) {
        xva = language_tparam(xd, lx-1);
        vvx = language_vararg_kind(xva);
        if (vvx == LANGUAGE_VARARG_BOUND)
            xbb = lookup(e, (language_tvar_t *)language_unwrap_vararg_num(xva));
    }
    if (ly > 0) {
        yva = language_tparam(yd, ly-1);
        vvy = language_vararg_kind(yva);
    }
    if (vvx != LANGUAGE_VARARG_NONE && vvx != LANGUAGE_VARARG_INT &&
        (!xbb || !language_is_long(xbb->lb))) {
        if (vvx == LANGUAGE_VARARG_UNBOUND || (xbb && !xbb->right)) {
            // Unbounded on the LHS, bounded on the RHS
            if (vvy == LANGUAGE_VARARG_NONE || vvy == LANGUAGE_VARARG_INT)
                return 0;
            else if (lx < ly) // Unbounded includes N == 0
                return 0;
        }
        else if (vvy == LANGUAGE_VARARG_NONE && !check_vararg_length(xva, ly+1-lx, e)) {
            return 0;
        }
    }
    else {
        size_t nx = lx;
        if (vvx == LANGUAGE_VARARG_INT)
            nx += language_vararg_length(xva) - 1;
        else if (xbb && language_is_long(xbb->lb))
            nx += language_unbox_long(xbb->lb) - 1;
        else
            assert(vvx == LANGUAGE_VARARG_NONE);
        size_t ny = ly;
        if (vvy == LANGUAGE_VARARG_INT)
            ny += language_vararg_length(yva) - 1;
        else if (vvy != LANGUAGE_VARARG_NONE)
            ny -= 1;
        if (vvy == LANGUAGE_VARARG_NONE || vvy == LANGUAGE_VARARG_INT) {
            if (nx != ny)
                return 0;
        }
        else {
            if (ny > nx)
                return 0;
        }
    }

    param = (param == 0 ? 1 : param);
    int ans = subtype_tuple_tail(xd, yd, 0, e, param);
    return ans;
}

static int try_subtype_by_bounds(language_value_t *a, language_value_t *b, language_stenv_t *e);

// `param` means we are currently looking at a parameter of a type constructor
// (as opposed to being outside any type constructor, or comparing variable bounds).
// this is used to record the positions where type variables occur for the
// diagonal rule (record_var_occurrence).
static int subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param)
{
    if (language_is_uniontype(x)) {
        if (x == y) return 1;
        x = pick_union_element(x, e, 0);
    }
    if (language_is_uniontype(y)) {
        if (x == ((language_uniontype_t*)y)->a || x == ((language_uniontype_t*)y)->b)
            return 1;
        if (language_is_unionall(x))
            return subtype_unionall(y, (language_unionall_t*)x, e, 0, param);
        int ui = 1;
        if (language_is_typevar(x)) {
            // The `convert(Type{T},T)` pattern, where T is a Union, required changing priority
            // of unions and vars: if matching `typevar <: union`, first try to match the whole
            // union against the variable before trying to take it apart to see if there are any
            // variables lurking inside.
            // note: for forall var, there's no need to split y if it has no free typevars.
            language_varbinding_t *xx = lookup(e, (language_tvar_t *)x);
            ui = ((xx && xx->right) || language_has_free_typevars(y)) && pick_union_decision(e, 1);
        }
        if (ui == 1)
            y = pick_union_element(y, e, 1);
    }
    if (language_is_typevar(x)) {
        if (language_is_typevar(y)) {
            if (x == y) return 1;
            language_varbinding_t *xx = lookup(e, (language_tvar_t*)x);
            language_varbinding_t *yy = lookup(e, (language_tvar_t*)y);
            language_value_t *xub = xx ? xx->ub : ((language_tvar_t*)x)->ub;
            language_value_t *ylb = yy ? yy->lb : ((language_tvar_t*)y)->lb;
            if (e->intersection) {
                language_value_t *xlb = xx ? xx->lb : ((language_tvar_t*)x)->lb;
                language_value_t *yub = yy ? yy->ub : ((language_tvar_t*)y)->ub;
                // find equivalence class for typevars during intersection
                if (xub == xlb && language_is_typevar(xub))
                    return subtype(xub, y, e, param);
                if (yub == ylb && language_is_typevar(yub))
                    return subtype(x, yub, e, param);
            }
            int xr = xx && xx->right;  // treat free variables as "forall" (left)
            int yr = yy && yy->right;
            if (xr) {
                if (yy) record_var_occurrence(yy, e, param);
                if (yr) {
                    record_var_occurrence(xx, e, param);
                    int trysub = e->intersection ? try_subtype_by_bounds(xx->lb, yy->ub, e) : 0;
                    return trysub || subtype(xx->lb, yy->ub, e, 0);
                }
                return var_lt((language_tvar_t*)x, y, e, param);
            }
            else if (yr) {
                if (xx) record_var_occurrence(xx, e, param);
                return var_gt((language_tvar_t*)y, x, e, param);
            }
            // check ∀x,y . x<:y
            // the bounds of left-side variables never change, and can only lead
            // to other left-side variables, so using || here is safe.
            return subtype(xub, y, e, param) || subtype(x, ylb, e, param);
        }
        if (language_is_unionall(y)) {
            language_varbinding_t *xb = lookup(e, (language_tvar_t*)x);
            if (xb == NULL ? !e->ignore_free : !xb->right) {
                // We'd better unwrap `y::UnionAll` eagerly if `x` isa ∀-var.
                // This makes sure the following cases work correct:
                // 1) `∀T <: Union{∃S, SomeType{P}} where {P}`: `S == Any` ==> `S >: T`
                // 2) `∀T <: Union{∀T, SomeType{P}} where {P}`:
                return subtype_unionall(x, (language_unionall_t*)y, e, 1, param);
            }
        }
        return subtype_var((language_tvar_t*)x, y, e, 0, param);
    }
    if (language_is_typevar(y))
        return subtype_var((language_tvar_t*)y, x, e, 1, param);
    if (y == (language_value_t*)language_any_type && !language_has_free_typevars(x))
        return 1;
    if (x == language_bottom_type && !language_has_free_typevars(y))
        return 1;
    language_value_t *ux = language_unwrap_unionall(x);
    language_value_t *uy = language_unwrap_unionall(y);
    if ((x != ux || y != uy) && y != (language_value_t*)language_any_type && language_is_datatype(ux) && language_is_datatype(uy) &&
        !language_is_type_type(ux)) {
        assert(ux);
        if (uy == (language_value_t*)language_any_type)
            return 1;
        language_datatype_t *xd = (language_datatype_t*)ux, *yd = (language_datatype_t*)uy;
        while (xd != NULL && xd != language_any_type && xd->name != yd->name) {
            xd = xd->super;
        }
        if (xd == language_any_type)
            return 0;
    }
    // handle forall ("left") vars first
    if (language_is_unionall(x)) {
        if (x == y && !(e->envidx < e->envsz))
            return 1;
        return subtype_unionall(y, (language_unionall_t*)x, e, 0, param);
    }
    if (language_is_unionall(y))
        return subtype_unionall(x, (language_unionall_t*)y, e, 1, param);
    if (language_is_datatype(x) && language_is_datatype(y)) {
        if (x == y) return 1;
        if (y == (language_value_t*)language_any_type) return 1;
        language_datatype_t *xd = (language_datatype_t*)x, *yd = (language_datatype_t*)y;
        if (language_is_type_type(x) && !language_is_type_type(y)) {
            language_value_t *tp0 = language_tparam0(xd);
            if (!language_is_typevar(tp0)) {
                // TODO this is not strictly correct, but we don't yet have any other way for
                // e.g. the argument `Int` to match a `::DataType` slot. Most correct would be:
                // Int isa DataType, Int isa Type{Int}, Type{Int} more specific than DataType,
                // !(Type{Int} <: DataType), !isleaftype(Type{Int}), because non-DataTypes can
                // be type-equal to `Int`.
                return language_typeof(tp0) == (language_value_t*)yd;
            }
            return 0;
        }
        if (language_is_type_type(y) && !language_is_type_type(x) && x != (language_value_t*)language_typeofbottom_type) {
            language_value_t *tp0 = language_tparam0(yd);
            if (!language_is_typevar(tp0) || !language_is_kind(x))
                return 0;
            // DataType.super is special, so `DataType <: Type{T}` (T free) needs special handling.
            // The answer is true iff `T` has full bounds (as in `Type`), but this needs to
            // be checked at the same depth where `Type{T}` occurs --- the depth of the LHS
            // doesn't matter because it (e.g. `DataType`) doesn't actually contain the variable.
            int issub = subtype((language_value_t*)language_type_type, y, e, param);
            return issub;
        }
        while (xd != language_any_type && xd->name != yd->name) {
            if (xd->super == NULL) {
                assert(xd->parameters && language_is_typename(xd->name));
                language_errorf("circular type parameter constraint in definition of %s", language_symbol_name(xd->name->name));
            }
            xd = xd->super;
        }
        if (xd == language_any_type) return 0;
        if (xd->name == language_tuple_typename)
            return subtype_tuple(xd, yd, e, param);
        size_t i, np = language_nparams(xd);
        int ans = 1;
        e->invdepth++;
        for (i=0; i < np; i++) {
            language_value_t *xi = language_tparam(xd, i), *yi = language_tparam(yd, i);
            if (!(xi == yi || forall_exists_equal(xi, yi, e))) {
                ans = 0; break;
            }
        }
        e->invdepth--;
        return ans;
    }
    if (language_is_type(y))
        return x == language_bottom_type;
    if (language_is_long(x) && language_is_long(y))
        return language_unbox_long(x) == language_unbox_long(y) + e->Loffset;
    return language_egal(x, y);
}

static int is_indefinite_length_tuple_type(language_value_t *x)
{
    x = language_unwrap_unionall(x);
    if (!language_is_tuple_type(x))
        return 0;
    size_t n = language_nparams(x);
    return n > 0 && language_vararg_kind(language_tparam(x, n-1)) == LANGUAGE_VARARG_UNBOUND;
}

static int is_definite_length_tuple_type(language_value_t *x)
{
    if (language_is_typevar(x))
        x = ((language_tvar_t*)x)->ub;
    x = language_unwrap_unionall(x);
    if (!language_is_tuple_type(x))
        return 0;
    size_t n = language_nparams(x);
    if (n == 0)
        return 1;
    language_vararg_kind_t k = language_vararg_kind(language_tparam(x, n-1));
    return k == LANGUAGE_VARARG_NONE || k == LANGUAGE_VARARG_INT;
}

static int _forall_exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param, int *count, int *noRmore);

static int may_contain_union_decision(language_value_t *x, language_stenv_t *e, language_typeenv_t *log) LANGUAGE_NOTSAFEPOINT
{
    if (x == NULL || x == (language_value_t*)language_any_type || x == language_bottom_type)
        return 0;
    if (language_is_unionall(x))
        return may_contain_union_decision(((language_unionall_t *)x)->body, e, log);
    if (language_is_datatype(x)) {
        language_datatype_t *xd = (language_datatype_t *)x;
        for (int i = 0; i < language_nparams(xd); i++) {
            language_value_t *param = language_tparam(xd, i);
            if (language_is_vararg(param))
                param = language_unwrap_vararg(param);
            if (may_contain_union_decision(param, e, log))
                return 1;
        }
        return 0;
    }
    if (!language_is_typevar(x))
        return language_is_type(x);
    language_typeenv_t *t = log;
    while (t != NULL) {
        if (x == (language_value_t *)t->var)
            return 1;
        t = t->prev;
    }
    language_typeenv_t newlog = { (language_tvar_t*)x, NULL, log };
    language_varbinding_t *xb = lookup(e, (language_tvar_t *)x);
    return may_contain_union_decision(xb ? xb->lb : ((language_tvar_t *)x)->lb, e, &newlog) ||
           may_contain_union_decision(xb ? xb->ub : ((language_tvar_t *)x)->ub, e, &newlog);
}

static int has_exists_typevar(language_value_t *x, language_stenv_t *e) LANGUAGE_NOTSAFEPOINT
{
    language_typeenv_t *env = NULL;
    language_varbinding_t *v = e->vars;
    while (v != NULL) {
        if (v->right) {
            language_typeenv_t *newenv = (language_typeenv_t*)alloca(sizeof(language_typeenv_t));
            newenv->var = v->var;
            newenv->val = NULL;
            newenv->prev = env;
            env = newenv;
        }
        v = v->prev;
    }
    return env != NULL && language_has_bound_typevars(x, env);
}

static int local_forall_exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param, int limit_slow)
{
    int16_t oldRmore = e->Runions.more;
    int sub;
    // fast-path for #49857
    if (obviously_in_union(y, x))
        return 1;
    int kindx = !language_has_free_typevars(x);
    int kindy = !language_has_free_typevars(y);
    if (kindx && kindy)
        return language_subtype(x, y);
    if (may_contain_union_decision(y, e, NULL) && pick_union_decision(e, 1) == 0) {
        language_saved_unionstate_t oldRunions; push_unionstate(&oldRunions, &e->Runions);
        e->Lunions.used = e->Runions.used = 0;
        e->Lunions.depth = e->Runions.depth = 0;
        e->Lunions.more = e->Runions.more = 0;
        int count = 0, noRmore = 0;
        sub = _forall_exists_subtype(x, y, e, param, &count, &noRmore);
        pop_unionstate(&e->Runions, &oldRunions);
        // We could skip the slow path safely if
        // 1) `_∀_∃_subtype` has tested all cases
        // 2) `_∀_∃_subtype` returns 1 &&  `x` and `y` contain no ∃ typevar
        // Once `limit_slow == 1`, also skip it if
        // 1) `_∀_∃_subtype` returns 0
        // 2) the left `Union` looks big
        // TODO: `limit_slow` ignores complexity from inner `local_∀_exists_subtype`.
        if (limit_slow == -1)
            limit_slow = kindx || kindy;
        int skip = noRmore || (limit_slow && (count > 3 || !sub)) ||
                   (sub && (kindx || !has_exists_typevar(x, e)) &&
                           (kindy || !has_exists_typevar(y, e)));
        if (skip)
            e->Runions.more = oldRmore;
    }
    else {
        // slow path
        e->Lunions.used = 0;
        while (1) {
            e->Lunions.more = 0;
            e->Lunions.depth = 0;
            sub = subtype(x, y, e, param);
            if (!sub || !next_union_state(e, 0))
                break;
        }
    }
    return sub;
}

static int forall_exists_equal(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    if (obviously_egal(x, y)) return 1;

    if ((is_indefinite_length_tuple_type(x) && is_definite_length_tuple_type(y)) ||
        (is_definite_length_tuple_type(x) && is_indefinite_length_tuple_type(y)))
        return 0;

    if (language_is_datatype(x) && language_is_datatype(y)) {
        // Fastpath for nested constructor. Skip the unneeded `>:` check.
        // Note: since there is no changes to the environment or union stack implied by `x` or `y`, this will simply forward to calling
        // `forall_exists_equal(xi, yi, e)` on each parameter `(xi, yi)` of `(x, y)`,
        // which means this subtype call will give the same result for `subtype(x, y)` and `subtype(y, x)`.
        language_datatype_t *xd = (language_datatype_t*)x, *yd = (language_datatype_t*)y;
        if (xd->name != yd->name)
            return 0;
        if (xd->name != language_tuple_typename)
            return subtype(x, y, e, 2);
    }

    if ((language_is_uniontype(x) && language_is_uniontype(y))) {
        // For 2 unions, first try a more efficient greedy algorithm that compares the unions
        // componentwise. If failed, `exists_subtype` would memorize that this branch should be skipped.
        // Note: this is valid because the normal path checks `>:` locally.
        if (pick_union_decision(e, 1) == 0) {
            return forall_exists_equal(((language_uniontype_t *)x)->a, ((language_uniontype_t *)y)->a, e) &&
                   forall_exists_equal(((language_uniontype_t *)x)->b, ((language_uniontype_t *)y)->b, e);
        }
    }

    language_saved_unionstate_t oldLunions; push_unionstate(&oldLunions, &e->Lunions);

    int sub = local_forall_exists_subtype(x, y, e, 2, -1);
    if (sub) {
        flip_offset(e);
        sub = local_forall_exists_subtype(y, x, e, 0, 0);
        flip_offset(e);
    }
    pop_unionstate(&e->Lunions, &oldLunions);
    return sub;
}

static int exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, language_savedenv_t *se, int param)
{
    e->Runions.used = 0;
    while (1) {
        e->Runions.depth = 0;
        e->Runions.more = 0;
        e->Lunions.depth = 0;
        e->Lunions.more = 0;
        if (subtype(x, y, e, param))
            return 1;
        if (next_union_state(e, 1)) {
            // We preserve `envout` here as `subtype_unionall` needs previous assigned env values.
            int oldidx = e->envidx;
            e->envidx = e->envsz;
            restore_env(e, se, 1);
            e->envidx = oldidx;
        }
        else {
            restore_env(e, se, 1);
            return 0;
        }
    }
}

static int _forall_exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param, int *count, int *noRmore)
{
    // The depth recursion has the following shape, after simplification:
    // ∀₁
    //   ∃₁
    assert(e->Runions.depth == 0);
    assert(e->Lunions.depth == 0);
    language_savedenv_t se;
    save_env(e, &se, 1);

    e->Lunions.used = 0;
    int sub;
    if (count) *count = 0;
    if (noRmore) *noRmore = 1;
    while (1) {
        sub = exists_subtype(x, y, e, &se, param);
        if (count) *count = (*count < 4) ? *count + 1 : 4;
        if (noRmore) *noRmore = *noRmore && e->Runions.more == 0;
        if (!sub || !next_union_state(e, 0))
            break;
        re_save_env(e, &se, 1);
    }

    free_env(&se);
    return sub;
}

static int forall_exists_subtype(language_value_t *x, language_value_t *y, language_stenv_t *e, int param)
{
    return _forall_exists_subtype(x, y, e, param, NULL, NULL);
}

static void init_stenv(language_stenv_t *e, language_value_t **env, int envsz)
{
    e->vars = NULL;
    e->envsz = envsz;
    e->envout = env;
    if (envsz) {
        assert(env != NULL);
        memset(env, 0, envsz*sizeof(void*));
    }
    e->envidx = 0;
    e->invdepth = 0;
    e->ignore_free = 0;
    e->intersection = 0;
    e->emptiness_only = 0;
    e->triangular = 0;
    e->Loffset = 0;
    e->Lunions.depth = 0;      e->Runions.depth = 0;
    e->Lunions.more = 0;       e->Runions.more = 0;
    e->Lunions.used = 0;       e->Runions.used = 0;
}

// subtyping entry points

LANGUAGE_DLLEXPORT int language_subtype_env_size(language_value_t *t)
{
    int sz = 0;
    while (language_is_unionall(t)) {
        sz++;
        t = ((language_unionall_t*)t)->body;
    }
    return sz;
}

// compute the minimum bound on the number of concrete types that are subtypes of `t`
// returns 0, 1, or many (2+)
static int concrete_min(language_value_t *t)
{
    if (language_is_unionall(t))
        t = language_unwrap_unionall(t);
    if (t == (language_value_t*)language_bottom_type)
        return 1;
    if (language_is_datatype(t)) {
        if (language_is_type_type(t))
            return 0; // Type{T} may have the concrete supertype `typeof(T)`, so don't try to handle them here
        return language_is_concrete_type(t) ? 1 : 2;
    }
    if (language_is_vararg(t))
        return 0;
    if (language_is_typevar(t))
        return 0; // could be 0 or more, since we didn't track if it was unbound
    if (language_is_uniontype(t)) {
        int count = concrete_min(((language_uniontype_t*)t)->a);
        if (count > 1)
            return count;
        return count + concrete_min(((language_uniontype_t*)t)->b);
    }
    assert(!language_is_kind(t));
    return 1; // a non-Type is also considered concrete
}

static language_value_t *find_var_body(language_value_t *t, language_tvar_t *v)
{
    if (language_is_unionall(t)) {
        if (((language_unionall_t*)t)->var == v)
            return ((language_unionall_t*)t)->body;
        language_value_t *b = find_var_body(((language_unionall_t*)t)->var->lb, v);
        if (b) return b;
        b = find_var_body(((language_unionall_t*)t)->var->ub, v);
        if (b) return b;
        return find_var_body(((language_unionall_t*)t)->body, v);
    }
    else if (language_is_uniontype(t)) {
        language_value_t *b = find_var_body(((language_uniontype_t*)t)->a, v);
        if (b) return b;
        return find_var_body(((language_uniontype_t*)t)->b, v);
    }
    else if (language_is_vararg(t)) {
        language_vararg_t *vm = (language_vararg_t *)t;
        if (vm->T) {
            language_value_t *b = find_var_body(vm->T, v);
            if (b) return b;
            if (vm->N) {
                return find_var_body(vm->N, v);
            }
        }
    }
    else if (language_is_datatype(t)) {
        size_t i;
        for (i=0; i < language_nparams(t); i++) {
            language_value_t *b = find_var_body(language_tparam(t, i), v);
            if (b)
                return b;
        }
    }
    return NULL;
}

// quickly compute if x seems like a possible subtype of y
// especially optimized for x isa concrete type
// returns true if it could be easily determined, with the result in subtype
// the approximation widens typevar bounds under the assumption they are bound
// in the immediate caller--the caller must be conservative in handling the result
static int obvious_subtype(language_value_t *x, language_value_t *y, language_value_t *y0, int *subtype)
{
    if (x == y || y == (language_value_t*)language_any_type) {
        *subtype = 1;
        return 1;
    }
    while (language_is_unionall(x)) {
        if (!language_is_unionall(y)) {
            if (obvious_subtype(language_unwrap_unionall(x), y, y0, subtype) && !*subtype)
                return 1;
            return 0;
        }
        x = ((language_unionall_t*)x)->body;
        y = ((language_unionall_t*)y)->body;
    }
    if (language_is_unionall(y))
        y = language_unwrap_unionall(y);
    if (x == (language_value_t*)language_typeofbottom_type->super)
        x = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (y == (language_value_t*)language_typeofbottom_type->super)
        y = (language_value_t*)language_typeofbottom_type; // supertype(typeof(Union{})) is equal to, although distinct from, itself
    if (x == y || y == (language_value_t*)language_any_type) {
        *subtype = 1;
        return 1;
    }
    if (language_is_typevar(x)) {
        if (((language_tvar_t*)x)->lb != (language_value_t*)language_bottom_type)
            return 0;
        if (obvious_subtype(((language_tvar_t*)x)->ub, y, y0, subtype) && *subtype)
            return 1;
        return 0;
    }
    if (language_is_typevar(y)) {
        if (((language_tvar_t*)y)->lb != (language_value_t*)language_bottom_type)
            return 0;
        if (obvious_subtype(x, ((language_tvar_t*)y)->ub, y0, subtype) && !*subtype)
            return 1;
        return 0;
    }
    if (x == (language_value_t*)language_bottom_type) {
        *subtype = 1;
        return 1;
    }
    if (y == (language_value_t*)language_bottom_type) {
        *subtype = 0;
        return 1;
    }
    if (language_is_vararg(x)) {
        if (!language_is_vararg(y)) {
            *subtype = 0;
            return 1;
        }
        return 0;
    }
    if (!language_is_type(x) || !language_is_type(y)) {
        *subtype = language_egal(x, y);
        return 1;
    }
    if (language_is_uniontype(x)) {
        // TODO: consider handling more LHS unions, being wary of covariance
        if (obvious_subtype(((language_uniontype_t*)x)->a, y, y0, subtype) && *subtype) {
            if (obvious_subtype(((language_uniontype_t*)x)->b, y, y0, subtype) && *subtype)
                return 1;
        }
        //if (obvious_subtype(((language_uniontype_t*)x)->a, y, y0, subtype)) {
        //    if (!*subtype)
        //        return 1;
        //    if (obvious_subtype(((language_uniontype_t*)x)->b, y, y0, subtype))
        //        return 1;
        //}
        //else if (obvious_subtype(((language_uniontype_t*)x)->b, y, y0, subtype)) {
        //    if (!*subtype)
        //        return 1;
        //}
        return 0;
    }
    if (language_is_uniontype(y)) {
        if (obvious_subtype(x, ((language_uniontype_t*)y)->a, y0, subtype)) {
            if (*subtype)
                return 1;
            if (obvious_subtype(x, ((language_uniontype_t*)y)->b, y0, subtype))
                return 1;
        }
        else if (obvious_subtype(x, ((language_uniontype_t*)y)->b, y0, subtype)) {
            if (*subtype)
                return 1;
        }
        return 0;
    }
    if (x == (language_value_t*)language_any_type) {
        *subtype = 0;
        return 1;
    }
    if (language_is_datatype(y)) {
        int istuple = (((language_datatype_t*)y)->name == language_tuple_typename);
        int iscov = istuple;
        // TODO: this would be a nice fast-path to have, unfortunately,
        //       datatype allocation fails to correctly hash-cons them
        //       and the subtyping tests include tests for this case
        //if (!iscov && ((language_datatype_t*)y)->isconcretetype && !language_is_type_type(x)) {
        //    *subtype = 0;
        //    return 1;
        //}
        if (language_is_datatype(x)) {
            // Weaker version of above, but runs into the same problem
            //if (((language_datatype_t*)x)->isconcretetype && ((language_datatype_t*)y)->isconcretetype && (!istuple || !istuple_x)) {
            //    *subtype = 0;
            //    return 1;
            //}
            int uncertain = 0;
            if (((language_datatype_t*)x)->name != ((language_datatype_t*)y)->name) {
                if (language_is_type_type(x) && language_is_kind(y)) {
                    language_value_t *t0 = language_tparam0(x);
                    if (language_is_typevar(t0))
                        return 0;
                    *subtype = language_typeof(t0) == y;
                    return 1;
                }
                if (language_is_type_type(y)) {
                    language_value_t *t0 = language_tparam0(y);
                    assert(!language_is_type_type(x));
                    if (language_is_kind(x) && language_is_typevar(t0))
                        return 0;
                    *subtype = 0;
                    return 1;
                }
                language_datatype_t *temp = (language_datatype_t*)x;
                while (temp->name != ((language_datatype_t*)y)->name) {
                    temp = temp->super;
                    if (temp == NULL) // invalid state during type declaration
                        return 0;
                    if (temp == language_any_type) {
                        *subtype = 0;
                        return 1;
                    }
                }
                if (obvious_subtype((language_value_t*)temp, y, y0, subtype) && *subtype)
                    return 1;
                return 0;
            }
            if (!iscov && !((language_datatype_t*)x)->hasfreetypevars) {
                // by transitivity, if `wrapper <: y`, then `x <: y` if x is a leaf type of its name
                if (obvious_subtype(((language_datatype_t*)x)->name->wrapper, y, y0, subtype) && *subtype)
                    return 1;
            }
            int i, npx = language_nparams(x), npy = language_nparams(y);
            language_vararg_kind_t vx = LANGUAGE_VARARG_NONE;
            language_vararg_kind_t vy = LANGUAGE_VARARG_NONE;
            language_value_t *vxt = NULL;
            int nparams_expanded_x = npx;
            int nparams_expanded_y = npy;
            if (istuple) {
                if (npx > 0) {
                    language_value_t *xva = language_tparam(x, npx - 1);
                    vx = language_vararg_kind(xva);
                    if (vx != LANGUAGE_VARARG_NONE) {
                        vxt = language_unwrap_vararg(xva);
                        nparams_expanded_x -= 1;
                        if (vx == LANGUAGE_VARARG_INT)
                            nparams_expanded_x += language_vararg_length(xva);
                    }
                }
                if (npy > 0) {
                    language_value_t *yva = language_tparam(y, npy - 1);
                    vy = language_vararg_kind(yva);
                    if (vy != LANGUAGE_VARARG_NONE) {
                        nparams_expanded_y -= 1;
                        if (vy == LANGUAGE_VARARG_INT)
                            nparams_expanded_y += language_vararg_length(yva);
                    }
                }
                // if the nparams aren't equal, or at least one of them is a typevar (uncertain), they may be obviously disjoint
                if (nparams_expanded_x != nparams_expanded_y || (vx != LANGUAGE_VARARG_NONE && vx != LANGUAGE_VARARG_INT) || (vy != LANGUAGE_VARARG_NONE && vy != LANGUAGE_VARARG_INT)) {
                    // we have a stronger bound on x if:
                    if (vy == LANGUAGE_VARARG_NONE || vy == LANGUAGE_VARARG_INT) { // the bound on y is certain
                        if (vx == LANGUAGE_VARARG_NONE || vx == LANGUAGE_VARARG_INT || vx == LANGUAGE_VARARG_UNBOUND || // and the bound on x is also certain
                            nparams_expanded_x > nparams_expanded_y || npx > nparams_expanded_y) { // or x is unknown, but definitely longer than y
                            *subtype = 0;
                            return 1; // number of fixed parameters in x are more than declared in y
                        }
                    }
                    if (nparams_expanded_x < nparams_expanded_y) {
                        *subtype = 0;
                        return 1; // number of fixed parameters in x could be fewer than in y
                    }
                    uncertain = 1;
                }
            }
            else if (npx != npy) {
                *subtype = 0;
                return 1;
            }

            // inspect the fixed parameters in y against x
            for (i = 0; i < npy - (vy == LANGUAGE_VARARG_NONE ? 0 : 1); i++) {
                language_value_t *a = i >= (npx - (vx == LANGUAGE_VARARG_NONE ? 0 : 1)) ? vxt : language_tparam(x, i);
                language_value_t *b = language_tparam(y, i);
                if (iscov || language_is_typevar(b)) {
                    if (obvious_subtype(a, b, y0, subtype)) {
                        if (!*subtype)
                            return 1;
                        if (language_has_free_typevars(b)) // b is actually more constrained that this
                            uncertain = 1;
                    }
                    else {
                        uncertain = 1;
                    }
                }
                else {
                    if (!obviously_egal(a, b)) {
                        if (obvious_subtype(a, b, y0, subtype)) {
                            if (!*subtype)
                                return 1;
                            if (language_has_free_typevars(b)) // b is actually more constrained that this
                                uncertain = 1;
                        }
                        else {
                            uncertain = 1;
                        }
                        if (!language_has_free_typevars(b) && obvious_subtype(b, a, y0, subtype)) {
                            if (!*subtype)
                                return 1;
                            if (language_has_free_typevars(a)) // a is actually more constrained that this
                                uncertain = 1;
                        }
                        else {
                            uncertain = 1;
                        }
                    }
                }
            }
            if (i < nparams_expanded_x) {
                // there are elements left in x (possibly just a Vararg), check them against the Vararg tail of y too
                assert(vy != LANGUAGE_VARARG_NONE && istuple && iscov);
                language_value_t *a1 = (vx != LANGUAGE_VARARG_NONE && i >= npx - 1) ? vxt : language_tparam(x, i);
                language_value_t *b = language_unwrap_vararg(language_tparam(y, i));
                if (language_is_typevar(b)) {
                    language_value_t *body = find_var_body(y0, (language_tvar_t*)b);
                    if (body == NULL)
                        body = y0;
                    if (var_occurs_invariant(body, (language_tvar_t*)b))
                        return 0;
                }
                if (nparams_expanded_x > npy && language_is_typevar(b) && is_leaf_typevar((language_tvar_t *)b) && concrete_min(a1) > 1) {
                    // diagonal rule for 2 or more elements: they must all be concrete on the LHS
                    *subtype = 0;
                    return 1;
                }
                language_value_t *a1u = language_unwrap_unionall(a1);
                if (language_is_type_type(a1u) && language_is_type(language_tparam0(a1u))) {
                    a1 = language_typeof(language_tparam0(a1u));
                }
                for (; i < nparams_expanded_x; i++) {
                    language_value_t *a = (vx != LANGUAGE_VARARG_NONE && i >= npx - 1) ? vxt : language_tparam(x, i);
                    if (i > npy && language_is_typevar(b) && is_leaf_typevar((language_tvar_t *)b)) { // i == npy implies a == a1
                        // diagonal rule: all the later parameters are also constrained to be type-equal to the first
                        language_value_t *a2 = a;
                        language_value_t *au = language_unwrap_unionall(a);
                        if (language_is_type_type(au) && language_is_type(language_tparam0(au))) {
                            // if a is exactly Type{T}, then use the concrete typeof(T) instead here
                            a2 = language_typeof(language_tparam0(au));
                        }
                        if (!obviously_egal(a1, a2)) {
                            if (obvious_subtype(a2, a1, y0, subtype)) {
                                if (!*subtype)
                                    return 1;
                                if (language_has_free_typevars(a1)) // a1 is actually more constrained that this
                                    uncertain = 1;
                            }
                            else {
                                uncertain = 1;
                            }
                            if (obvious_subtype(a1, a2, y0, subtype)) {
                                if (!*subtype)
                                    return 1;
                                if (language_has_free_typevars(a2)) // a2 is actually more constrained that this
                                    uncertain = 1;
                            }
                            else {
                                uncertain = 1;
                            }
                        }
                    }
                    if (obvious_subtype(a, b, y0, subtype)) {
                        if (!*subtype)
                            return 1;
                        if (language_has_free_typevars(b)) // b is actually more constrained that this
                            uncertain = 1;
                    }
                    else {
                        uncertain = 1;
                    }
                }
            }
            if (uncertain)
                return 0;
            *subtype = 1;
            return 1;
        }
    }
    return 0;
}

LANGUAGE_DLLEXPORT int language_obvious_subtype(language_value_t *x, language_value_t *y, int *subtype)
{
    return obvious_subtype(x, y, y, subtype);
}

// `env` is NULL if no typevar information is requested, or otherwise
// points to a rooted array of length `language_subtype_env_size(y)`.
// This will be populated with the values of variables from unionall
// types at the outer level of `y`.
LANGUAGE_DLLEXPORT int language_subtype_env(language_value_t *x, language_value_t *y, language_value_t **env, int envsz)
{
    language_stenv_t e;
    if (y == (language_value_t*)language_any_type || x == language_bottom_type)
        return 1;
    if (x == y ||
        (language_typeof(x) == language_typeof(y) &&
         (language_is_unionall(y) || language_is_uniontype(y)) &&
         language_types_egal(x, y))) {
        if (envsz != 0) { // quickly copy env from x
            language_unionall_t *ua = (language_unionall_t*)x;
            int i;
            for (i = 0; i < envsz; i++) {
                assert(language_is_unionall(ua));
                env[i] = (language_value_t*)ua->var;
                ua = (language_unionall_t*)ua->body;
            }
        }
        return 1;
    }
    int obvious_subtype = 2;
    if (language_obvious_subtype(x, y, &obvious_subtype)) {
#ifdef NDEBUG
        if (obvious_subtype == 0)
            return obvious_subtype;
        else if (envsz == 0)
            return obvious_subtype;
#endif
    }
    else {
        obvious_subtype = 3;
    }
    init_stenv(&e, env, envsz);
    int subtype = forall_exists_subtype(x, y, &e, 0);
    assert(obvious_subtype == 3 || obvious_subtype == subtype || language_has_free_typevars(x) || language_has_free_typevars(y));
#ifndef NDEBUG
    if (obvious_subtype == 0 || (obvious_subtype == 1 && envsz == 0))
        subtype = obvious_subtype; // this ensures that running in a debugger doesn't change the result
#endif
    if (env) {
        language_unionall_t *ub = (language_unionall_t*)y;
        int i;
        for (i = 0; i < envsz; i++) {
            assert(language_is_unionall(ub));
            language_tvar_t *var = ub->var;
            env[i] = fix_inferred_var_bound(var, env[i]);
            ub = (language_unionall_t*)ub->body;
        }
    }
    return subtype;
}

static int subtype_in_env(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    language_stenv_t e2;
    init_stenv(&e2, NULL, 0);
    e2.vars = e->vars;
    e2.intersection = e->intersection;
    e2.ignore_free = e->ignore_free;
    e2.invdepth = e->invdepth;
    e2.envsz = e->envsz;
    e2.envout = e->envout;
    e2.envidx = e->envidx;
    e2.Loffset = e->Loffset;
    return forall_exists_subtype(x, y, &e2, 0);
}

LANGUAGE_DLLEXPORT int language_subtype(language_value_t *x, language_value_t *y)
{
    return language_subtype_env(x, y, NULL, 0);
}

LANGUAGE_DLLEXPORT int language_types_equal(language_value_t *a, language_value_t *b)
{
    if (a == b)
        return 1;
    if (language_typeof(a) == language_typeof(b) && language_types_egal(a, b))
        return 1;
    if (obviously_unequal(a, b))
        return 0;
    // the following is an interleaved version of:
    //   return language_subtype(a, b) && language_subtype(b, a)
    // where we try to do the fast checks before the expensive ones
    if (language_is_datatype(a) && !language_is_concrete_type(b)) {
        // if one type looks simpler, check it on the right
        // first in order to reject more quickly.
        language_value_t *temp = a;
        a = b;
        b = temp;
    }
    // first check if a <: b has an obvious answer
    int subtype_ab = 2;
    if (b == (language_value_t*)language_any_type || a == language_bottom_type) {
        subtype_ab = 1;
    }
    else if (language_obvious_subtype(a, b, &subtype_ab)) {
#ifdef NDEBUG
        if (subtype_ab == 0)
            return 0;
#endif
    }
    else {
        subtype_ab = 3;
    }
    // next check if b <: a has an obvious answer
    int subtype_ba = 2;
    if (a == (language_value_t*)language_any_type || b == language_bottom_type) {
        subtype_ba = 1;
    }
    else if (language_obvious_subtype(b, a, &subtype_ba)) {
#ifdef NDEBUG
        if (subtype_ba == 0)
            return 0;
#endif
    }
    else {
        subtype_ba = 3;
    }
    // finally, do full subtyping for any inconclusive test
    language_stenv_t e;
#ifdef NDEBUG
    if (subtype_ab != 1)
#endif
    {
        init_stenv(&e, NULL, 0);
        int subtype = forall_exists_subtype(a, b, &e, 0);
        assert(subtype_ab == 3 || subtype_ab == subtype || language_has_free_typevars(a) || language_has_free_typevars(b));
#ifndef NDEBUG
        if (subtype_ab != 0 && subtype_ab != 1) // ensures that running in a debugger doesn't change the result
#endif
        subtype_ab = subtype;
#ifdef NDEBUG
        if (subtype_ab == 0)
            return 0;
#endif
    }
#ifdef NDEBUG
    if (subtype_ba != 1)
#endif
    {
        init_stenv(&e, NULL, 0);
        int subtype = forall_exists_subtype(b, a, &e, 0);
        assert(subtype_ba == 3 || subtype_ba == subtype || language_has_free_typevars(a) || language_has_free_typevars(b));
#ifndef NDEBUG
        if (subtype_ba != 0 && subtype_ba != 1) // ensures that running in a debugger doesn't change the result
#endif
        subtype_ba = subtype;
    }
    // all tests successful
    return subtype_ab && subtype_ba;
}

LANGUAGE_DLLEXPORT int language_is_not_broken_subtype(language_value_t *a, language_value_t *b)
{
    // TODO: the final commented out check here isn't correct; it should be closer to the
    // `issingletype` check used by `isnotbrokensubtype` in `base/compiler/typeutils.jl`
    return !language_is_kind(b) || !language_is_type_type(a); // || language_is_datatype_singleton((language_datatype_t*)language_tparam0(a));
}

int language_tuple1_isa(language_value_t *child1, language_value_t **child, size_t cl, language_datatype_t *pdt)
{
    if (language_is_tuple_type(pdt) && !language_is_va_tuple(pdt)) {
        if (cl != language_nparams(pdt))
            return 0;
        size_t i;
        if (!language_isa(child1, language_tparam(pdt, 0)))
            return 0;
        for (i = 1; i < cl; i++) {
            if (!language_isa(child[i - 1], language_tparam(pdt, i)))
                return 0;
        }
        return 1;
    }
    language_value_t *tu = (language_value_t*)arg_type_tuple(child1, child, cl);
    int ans;
    LANGUAGE_GC_PUSH1(&tu);
    ans = language_subtype(tu, (language_value_t*)pdt);
    LANGUAGE_GC_POP();
    return ans;
}

int language_tuple_isa(language_value_t **child, size_t cl, language_datatype_t *pdt)
{
    if (cl == 0) {
        if (pdt == language_emptytuple_type)
            return 1;
        if (language_is_tuple_type(pdt) && (language_nparams(pdt) != 1 || !language_is_va_tuple(pdt)))
            return 0;
        return language_isa(language_emptytuple, (language_value_t*)pdt);
    }
    return language_tuple1_isa(child[0], &child[1], cl, pdt);
}

// returns true if the intersection of `t` and `Type` is non-empty and not a kind
// this is sufficient to determine if `isa(x, T)` can instead simply check for `typeof(x) <: T`
int language_has_intersect_type_not_kind(language_value_t *t)
{
    t = language_unwrap_unionall(t);
    if (t == (language_value_t*)language_any_type)
        return 1;
    assert(!language_is_vararg(t));
    if (language_is_uniontype(t))
        return language_has_intersect_type_not_kind(((language_uniontype_t*)t)->a) ||
               language_has_intersect_type_not_kind(((language_uniontype_t*)t)->b);
    if (language_is_typevar(t))
        return language_has_intersect_type_not_kind(((language_tvar_t*)t)->ub);
    if (language_is_datatype(t))
        if (((language_datatype_t*)t)->name == language_type_typename)
            return 1;
    return 0;
}

// compute if DataType<:t || Union<:t || UnionAll<:t etc.
int language_has_intersect_kind_not_type(language_value_t *t)
{
    t = language_unwrap_unionall(t);
    if (t == (language_value_t*)language_any_type || language_is_kind(t))
        return 1;
    assert(!language_is_vararg(t));
    if (language_is_uniontype(t))
        return language_has_intersect_kind_not_type(((language_uniontype_t*)t)->a) ||
               language_has_intersect_kind_not_type(((language_uniontype_t*)t)->b);
    if (language_is_typevar(t))
        return language_has_intersect_kind_not_type(((language_tvar_t*)t)->ub);
    return 0;
}


LANGUAGE_DLLEXPORT int language_isa(language_value_t *x, language_value_t *t)
{
    if (t == (language_value_t*)language_any_type || language_typetagis(x,t))
        return 1;
    if (language_typetagof(x) < (language_max_tags << 4) && language_is_datatype(t) && language_typetagis(x,((language_datatype_t*)t)->smalltag << 4))
        return 1;
    if (language_is_type(x)) {
        if (t == (language_value_t*)language_type_type)
            return 1;
        if (!language_has_free_typevars(x)) {
            if (language_is_concrete_type(t))
                return 0;
            if (language_is_type_type(t))
                return language_types_equal(x, language_tparam0(t));
            language_value_t *t2 = language_unwrap_unionall(t);
            if (language_is_datatype(t2)) {
                if (((language_datatype_t*)t2)->name == language_type_typename) {
                    language_value_t *tp = language_tparam0(t2);
                    if (language_is_typevar(tp)) {
                        if (((language_tvar_t*)tp)->lb == language_bottom_type) {
                            while (language_is_typevar(tp))
                                tp = ((language_tvar_t*)tp)->ub;
                            if (!language_has_free_typevars(tp))
                                return language_subtype(x, tp);
                        }
                        else if (((language_tvar_t*)tp)->ub == (language_value_t*)language_any_type) {
                            while (language_is_typevar(tp))
                                tp = ((language_tvar_t*)tp)->lb;
                            if (!language_has_free_typevars(tp))
                                return language_subtype(tp, x);
                        }
                    }
                }
                else {
                    return 0;
                }
            }
            if (language_subtype(language_typeof(x), t))
                return 1;
            if (language_has_intersect_type_not_kind(t2)) {
                LANGUAGE_GC_PUSH1(&x);
                x = (language_value_t*)language_wrap_Type(x);  // TODO jb/subtype avoid language_wrap_Type
                int ans = language_subtype(x, t);
                LANGUAGE_GC_POP();
                return ans;
            }
            return 0;
        }
    }
    if (language_is_concrete_type(t))
        return 0;
    return language_subtype(language_typeof(x), t);
}

// type intersection

static language_value_t *intersect(language_value_t *x, language_value_t *y, language_stenv_t *e, int param);

static language_value_t *intersect_all(language_value_t *x, language_value_t *y, language_stenv_t *e);

// intersect in nested union environment, similar to subtype_ccheck
static language_value_t *intersect_aside(language_value_t *x, language_value_t *y, language_stenv_t *e, int depth)
{
    // band-aid for #30335
    if (x == (language_value_t*)language_any_type && !language_is_typevar(y))
        return y;
    if (y == (language_value_t*)language_any_type && !language_is_typevar(x))
        return x;
    // band-aid for #46736
    if (obviously_egal(x, y))
        return x;

    language_saved_unionstate_t oldRunions; push_unionstate(&oldRunions, &e->Runions);
    int savedepth = e->invdepth;
    e->invdepth = depth;
    language_value_t *res = intersect_all(x, y, e);
    e->invdepth = savedepth;
    pop_unionstate(&e->Runions, &oldRunions);
    return res;
}

static language_value_t *intersect_union(language_value_t *x, language_uniontype_t *u, language_stenv_t *e, int8_t R, int param)
{
    if (param == 2 || (!language_has_free_typevars(x) && !language_has_free_typevars((language_value_t*)u))) {
        language_value_t *a=NULL, *b=NULL;
        LANGUAGE_GC_PUSH2(&a, &b);
        language_saved_unionstate_t oldRunions; push_unionstate(&oldRunions, &e->Runions);
        a = R ? intersect_all(x, u->a, e) : intersect_all(u->a, x, e);
        b = R ? intersect_all(x, u->b, e) : intersect_all(u->b, x, e);
        pop_unionstate(&e->Runions, &oldRunions);
        language_value_t *i = simple_join(a,b);
        LANGUAGE_GC_POP();
        return i;
    }
    language_value_t *choice = pick_union_element((language_value_t*)u, e, 1);
    // try all possible choices in covariant position; union them all together at the top level
    return R ? intersect(x, choice, e, param) : intersect(choice, x, e, param);
}

// set a variable to a non-type constant
static language_value_t *set_var_to_const(language_varbinding_t *bb, language_value_t *v LANGUAGE_MAYBE_UNROOTED, language_stenv_t *e, int R)
{
    int offset = R ? -e->Loffset : e->Loffset;
    if (bb->lb == language_bottom_type && bb->ub == (language_value_t*)language_any_type) {
        if (offset == 0)
            bb->lb = bb->ub = v;
        else if (language_is_long(v)) {
            size_t iv = language_unbox_long(v);
            v = language_box_long(iv + offset);
            bb->lb = bb->ub = v;
            // Here we always return the shorter `Vararg`'s length.
            if (offset > 0)
                return language_box_long(iv);
        }
        else
            return language_bottom_type;
    }
    else if (language_is_long(v) && language_is_long(bb->lb)) {
        if (language_unbox_long(v) + offset != language_unbox_long(bb->lb))
            return language_bottom_type;
        // Here we always return the shorter `Vararg`'s length.
        if (offset < 0) return bb->lb;
    }
    else if (!language_egal(v, bb->lb)) {
        return language_bottom_type;
    }
    return v;
}

static language_value_t *bound_var_below(language_tvar_t *tv, language_varbinding_t *bb, language_stenv_t *e, int R) {
    if (!bb)
        return (language_value_t*)tv;
    if (bb->depth0 != e->invdepth)
        return language_bottom_type;
    e->invdepth++;
    record_var_occurrence(bb, e, 2);
    e->invdepth--;
    int offset = R ? -e->Loffset : e->Loffset;
    if (language_is_long(bb->lb)) {
        ssize_t blb = language_unbox_long(bb->lb);
        if (blb < offset || blb < 0)
            return language_bottom_type;
        // Here we always return the shorter `Vararg`'s length.
        if (offset <= 0)
            return bb->lb;
        return language_box_long(blb - offset);
    }
    if (offset > 0) {
        if (bb->innervars == NULL)
            bb->innervars = language_alloc_array_1d(language_array_any_type, 0);
        language_value_t *ntv = NULL;
        LANGUAGE_GC_PUSH1(&ntv);
        ntv = (language_value_t *)language_new_typevar(tv->name, language_bottom_type, (language_value_t *)language_any_type);
        language_array_ptr_1d_push(bb->innervars, ntv);
        LANGUAGE_GC_POP();
        return ntv;
    }
    return (language_value_t*)tv;
}

static int subtype_by_bounds(language_value_t *x, language_value_t *y, language_stenv_t *e) LANGUAGE_NOTSAFEPOINT;

// similar to `subtype_by_bounds`, used to avoid stack-overflow caused by circular constraints.
static int try_subtype_by_bounds(language_value_t *a, language_value_t *b, language_stenv_t *e)
{
    if (language_is_uniontype(a))
        return try_subtype_by_bounds(((language_uniontype_t *)a)->a, b, e) &&
               try_subtype_by_bounds(((language_uniontype_t *)a)->b, b, e);
    else if (language_is_uniontype(b))
        return try_subtype_by_bounds(a, ((language_uniontype_t *)b)->a, e) ||
               try_subtype_by_bounds(a, ((language_uniontype_t *)b)->b, e);
    else if (a == language_bottom_type || b == (language_value_t *)language_any_type || obviously_egal(a, b))
        return 1;
    else if (!language_is_typevar(b))
        return 0;
    else if (language_is_typevar(a) && subtype_by_bounds(a, b, e))
        return 1;
    // check if `Union{a, ...} <: b`.
    language_varbinding_t *vb = lookup(e, (language_tvar_t *)b);
    language_value_t *blb = vb ? vb->lb : ((language_tvar_t *)b)->lb;
    return obviously_in_union(a, blb);
}

static int try_subtype_in_env(language_value_t *a, language_value_t *b, language_stenv_t *e)
{
    if (try_subtype_by_bounds(a, b, e))
        return 1;
    language_savedenv_t se;
    save_env(e, &se, 1);
    int ret = subtype_in_env(a, b, e);
    restore_env(e, &se, 1);
    free_env(&se);
    return ret;
}

static void set_bound(language_value_t **bound, language_value_t *val, language_tvar_t *v, language_stenv_t *e) LANGUAGE_NOTSAFEPOINT
{
    if (in_union(val, (language_value_t*)v))
        return;
    language_varbinding_t *btemp = e->vars;
    while (btemp != NULL) {
        if ((btemp->lb == (language_value_t*)v || btemp->ub == (language_value_t*)v) &&
            in_union(val, (language_value_t*)btemp->var))
            return;
        btemp = btemp->prev;
    }
    *bound = val;
}

// subtype, treating all vars as existential
static int subtype_in_env_existential(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    language_varbinding_t *v = e->vars;
    int len = 0;
    if (x == language_bottom_type || y == (language_value_t*)language_any_type)
        return 1;
    while (v != NULL) {
        len++;
        v = v->prev;
    }
    int8_t *rs = (int8_t*)malloc_s(len);
    int n = 0;
    v = e->vars;
    while (n < len) {
        assert(v != NULL);
        rs[n++] = v->right;
        v->right = 1;
        v = v->prev;
    }
    int issub = subtype_in_env(x, y, e);
    n = 0; v = e->vars;
    while (n < len) {
        assert(v != NULL);
        v->right = rs[n++];
        v = v->prev;
    }
    free(rs);
    return issub;
}

// See if var y is reachable from x via bounds; used to avoid cycles.
static int _reachable_var(language_value_t *x, language_tvar_t *y, language_stenv_t *e, language_typeenv_t *log)
{
    if (in_union(x, (language_value_t*)y))
        return 1;
    if (language_is_uniontype(x))
        return _reachable_var(((language_uniontype_t *)x)->a, y, e, log) ||
               _reachable_var(((language_uniontype_t *)x)->b, y, e, log);
    if (!language_is_typevar(x))
        return 0;
    language_typeenv_t *t = log;
    while (t != NULL) {
        if (x == (language_value_t *)t->var)
            return 0;
        t = t->prev;
    }
    language_varbinding_t *xv = lookup(e, (language_tvar_t*)x);
    language_value_t *lb = xv == NULL ? ((language_tvar_t*)x)->lb : xv->lb;
    language_value_t *ub = xv == NULL ? ((language_tvar_t*)x)->ub : xv->ub;
    language_typeenv_t newlog = { (language_tvar_t*)x, NULL, log };
    return _reachable_var(ub, y, e, &newlog) || _reachable_var(lb, y, e, &newlog);
}

static int reachable_var(language_value_t *x, language_tvar_t *y, language_stenv_t *e)
{
    return _reachable_var(x, y, e, NULL);
}

// check whether setting v == t implies v == SomeType{v}, which is unsatisfiable.
static int check_unsat_bound(language_value_t *t, language_tvar_t *v, language_stenv_t *e) LANGUAGE_NOTSAFEPOINT
{
    if (var_occurs_inside(t, v, 0, 0))
        return 1;
    language_varbinding_t *btemp = e->vars;
    while (btemp != NULL) {
        if (btemp->lb == (language_value_t*)v && btemp->ub == (language_value_t*)v &&
            var_occurs_inside(t, btemp->var, 0, 0))
            return 1;
        btemp = btemp->prev;
    }
    return 0;
}


static language_value_t *intersect_var(language_tvar_t *b, language_value_t *a, language_stenv_t *e, int8_t R, int param)
{
    language_varbinding_t *bb = lookup(e, b);
    if (bb == NULL)
        return R ? intersect_aside(a, b->ub, e, 0) : intersect_aside(b->ub, a, e, 0);
    if (reachable_var(bb->lb, b, e) || reachable_var(bb->ub, b, e))
        return a;
    if (bb->lb == bb->ub && language_is_typevar(bb->lb))
        return R ? intersect(a, bb->lb, e, param) : intersect(bb->lb, a, e, param);
    if (!language_is_type(a) && !language_is_typevar(a))
        return set_var_to_const(bb, a, e, R);
    language_savedenv_t se;
    if (param == 2) {
        language_value_t *ub = NULL;
        LANGUAGE_GC_PUSH1(&ub);
        if (!language_has_free_typevars(a)) {
            save_env(e, &se, 1);
            int issub = subtype_in_env_existential(bb->lb, a, e);
            restore_env(e, &se, 1);
            if (issub) {
                issub = subtype_in_env_existential(a, bb->ub, e);
                restore_env(e, &se, 1);
            }
            free_env(&se);
            if (!issub) {
                LANGUAGE_GC_POP();
                return language_bottom_type;
            }
            ub = a;
        }
        else {
            e->triangular++;
            ub = R ? intersect_aside(a, bb->ub, e, bb->depth0) : intersect_aside(bb->ub, a, e, bb->depth0);
            e->triangular--;
            save_env(e, &se, 1);
            int issub = subtype_in_env_existential(bb->lb, ub, e);
            restore_env(e, &se, 1);
            free_env(&se);
            if (!issub) {
                LANGUAGE_GC_POP();
                return language_bottom_type;
            }
        }
        if (ub != (language_value_t*)b) {
            if (language_has_free_typevars(ub)) {
                if (check_unsat_bound(ub, b, e)) {
                    LANGUAGE_GC_POP();
                    return language_bottom_type;
                }
            }
            bb->ub = ub;
            if ((language_is_uniontype(ub) && !language_is_uniontype(a)) ||
                (language_is_unionall(ub) && !language_is_unionall(a)))
                ub = (language_value_t*)b;
            else
                bb->lb = ub;
        }
        LANGUAGE_GC_POP();
        return ub;
    }
    language_value_t *ub = R ? intersect_aside(a, bb->ub, e, bb->depth0) : intersect_aside(bb->ub, a, e, bb->depth0);
    if (ub == language_bottom_type)
        return language_bottom_type;
    if (bb->constraintkind == 1 || e->triangular) {
        if (e->triangular && check_unsat_bound(ub, b, e))
            return language_bottom_type;
        set_bound(&bb->ub, ub, b, e);
        return (language_value_t*)b;
    }
    else if (bb->constraintkind == 0) {
        LANGUAGE_GC_PUSH1(&ub);
        if (!language_is_typevar(a) && try_subtype_in_env(bb->ub, a, e)) {
            LANGUAGE_GC_POP();
            return (language_value_t*)b;
        }
        LANGUAGE_GC_POP();
        return ub;
    }
    assert(bb->constraintkind == 2);
    if (ub == a && bb->lb != language_bottom_type)
        return ub;
    if (language_egal(bb->ub, bb->lb))
        return ub;
    if (is_leaf_bound(ub))
        set_bound(&bb->lb, ub, b, e);
    // TODO: can we improve this bound by pushing a new variable into the environment
    // and adding that to the lower bound of our variable?
    //language_value_t *ntv = NULL;
    //LANGUAGE_GC_PUSH2(&ntv, &ub);
    //if (bb->innervars == NULL)
    //    bb->innervars = language_alloc_array_1d(language_array_any_type, 0);
    //ntv = (language_value_t*)language_new_typevar(b->name, bb->lb, ub);
    //language_array_ptr_1d_push(bb->innervars, ntv);
    //language_value_t *lb = simple_join(b->lb, ntv);
    //LANGUAGE_GC_POP();
    //bb->lb = lb;
    return ub;
}

// test whether `var` occurs inside constructors. `want_inv` tests only inside
// invariant constructors. `inside` means we are currently inside a constructor of the
// requested kind.
static int var_occurs_inside(language_value_t *v, language_tvar_t *var, int inside, int want_inv) LANGUAGE_NOTSAFEPOINT
{
    if (v == (language_value_t*)var) {
        return inside;
    }
    else if (language_is_uniontype(v)) {
        return var_occurs_inside(((language_uniontype_t*)v)->a, var, inside, want_inv) ||
            var_occurs_inside(((language_uniontype_t*)v)->b, var, inside, want_inv);
    }
    else if (language_is_unionall(v)) {
        language_unionall_t *ua = (language_unionall_t*)v;
        if (ua->var == var)
            return 0;
        if (var_occurs_inside(ua->var->lb, var, inside, want_inv) || var_occurs_inside(ua->var->ub, var, inside, want_inv))
            return 1;
        return var_occurs_inside(ua->body, var, inside, want_inv);
    }
    else if (language_is_vararg(v)) {
        language_vararg_t *vm = (language_vararg_t*)v;
        if (vm->T) {
            if (var_occurs_inside(vm->T, var, inside || !want_inv, want_inv))
                return 1;
            return vm->N && var_occurs_inside(vm->N, var, 1, want_inv);
        }
    }
    else if (language_is_datatype(v)) {
        size_t i;
        int istuple = language_is_tuple_type(v);
        for (i=0; i < language_nparams(v); i++) {
            int ins_i = inside || !want_inv || !istuple;
            if (var_occurs_inside(language_tparam(v,i), var, ins_i, want_inv))
                return 1;
        }
    }
    return 0;
}

static language_value_t *omit_bad_union(language_value_t *u, language_tvar_t *t)
{
    if (!language_has_typevar(u, t))
        return u; // return u if possible as many checks use `==`.
    language_value_t *res = NULL;
    if (language_is_unionall(u)) {
        language_tvar_t *var = ((language_unionall_t *)u)->var;
        language_value_t *ub = var->ub, *body = ((language_unionall_t *)u)->body;
        assert(var != t);
        LANGUAGE_GC_PUSH3(&ub, &body, &var);
        body = omit_bad_union(body, t);
        if (!language_has_typevar(body, var)) {
            res = body;
        }
        else if (language_has_typevar(var->lb, t)) {
            res = language_bottom_type;
        }
        else {
            ub = omit_bad_union(ub, t);
            if (ub == language_bottom_type && var->lb != ub) {
                res = language_bottom_type;
            }
            else if (obviously_egal(var->lb, ub)) {
                res = language_substitute_var_nothrow(body, var, ub);
                if (res == NULL)
                    res = language_bottom_type;
            }
            else {
                if (ub != var->ub) {
                    var = language_new_typevar(var->name, var->lb, ub);
                    body = language_substitute_var(body, ((language_unionall_t *)u)->var, (language_value_t *)var);
                }
                res = language_new_struct(language_unionall_type, var, body);
            }
        }
        LANGUAGE_GC_POP();
    }
    else if (language_is_uniontype(u)) {
        language_value_t *a = ((language_uniontype_t *)u)->a;
        language_value_t *b = ((language_uniontype_t *)u)->b;
        LANGUAGE_GC_PUSH2(&a, &b);
        a = omit_bad_union(a, t);
        b = omit_bad_union(b, t);
        res = simple_join(a, b);
        LANGUAGE_GC_POP();
    }
    else {
        res = language_bottom_type;
    }
    assert(res != NULL);
    return res;
}

// Caller might not have rooted `res`
static language_value_t *finish_unionall(language_value_t *res LANGUAGE_MAYBE_UNROOTED, language_varbinding_t *vb, language_unionall_t *u, language_stenv_t *e)
{
    language_value_t *varval = NULL, *ilb = NULL, *iub = NULL, *nivar = NULL;
    language_tvar_t *newvar = vb->var, *ivar = NULL;
    LANGUAGE_GC_PUSH6(&res, &newvar, &ivar, &nivar, &ilb, &iub);
    // try to reduce var to a single value
    if (language_is_long(vb->ub) && language_is_typevar(vb->lb)) {
        varval = vb->ub;
    }
    else if (obviously_egal(vb->lb, vb->ub)) {
        // given x<:T<:x, substitute x for T
        varval = vb->ub;
    }
    // TODO: `vb.occurs_cov == 1`, we could also substitute Tuple{<:X} => Tuple{X},
    // but it may change some ambiguity errors so we don't need to do it yet.
    else if (vb->occurs_cov && is_leaf_bound(vb->ub) && !language_has_free_typevars(vb->ub)) {
        // replace T<:x with x in covariant position when possible
        varval = vb->ub;
    }

    if (vb->intvalued) {
        if ((varval && language_is_long(varval)) ||
            (vb->lb == language_bottom_type && vb->ub == (language_value_t*)language_any_type) ||
            (language_is_typevar(vb->lb) && vb->ub == vb->lb)) {
            // int-valued typevar must either be an Int, or have Bottom-Any bounds,
            // or be set equal to another typevar.
        }
        else {
            LANGUAGE_GC_POP();
            return language_bottom_type;
        }
    }

    // TODO: this can prevent us from matching typevar identities later
    if (!varval && (vb->lb != vb->var->lb || vb->ub != vb->var->ub))
        newvar = language_new_typevar(vb->var->name, vb->lb, vb->ub);

    // flatten all innervar into a (reversed) list
    size_t icount = 0;
    if (vb->innervars)
        icount += language_array_nrows(vb->innervars);
    for (language_varbinding_t *btemp = e->vars; btemp != NULL; btemp = btemp->prev) {
        if (btemp->innervars != NULL)
            icount += language_array_nrows(btemp->innervars);
    }
    language_svec_t *p = NULL;
    language_value_t **iparams;
    language_value_t **roots;
    LANGUAGE_GC_PUSHARGS(roots, icount < 22 ? 3*icount : 1);
    if (icount < 22) {
        iparams = roots;
    }
    else {
        p = language_alloc_svec(3*icount);
        roots[0] = (language_value_t*)p;
        iparams = language_svec_data(p);
    }
    language_ivarbinding_t *allvars = NULL;
    size_t niparams = 0;
    if (vb->innervars) {
        for (size_t i = 0; i < language_array_nrows(vb->innervars); i++) {
            language_tvar_t *ivar = (language_tvar_t *)language_array_ptr_ref(vb->innervars, i);
            language_ivarbinding_t *inew = (language_ivarbinding_t *)alloca(sizeof(language_ivarbinding_t));
            inew->var = (language_tvar_t **)&iparams[niparams++]; *inew->var = ivar;
            inew->lb = &iparams[niparams++]; *inew->lb = ivar->lb;
            inew->ub = &iparams[niparams++]; *inew->ub = ivar->ub;
            inew->root = vb;
            inew->next = allvars;
            allvars = inew;
        }
    }
    for (language_varbinding_t *btemp = e->vars; btemp != NULL; btemp = btemp->prev) {
        language_ivarbinding_t *inew = (language_ivarbinding_t *)alloca(sizeof(language_ivarbinding_t));
        inew->var = &btemp->var;
        inew->lb = &btemp->lb;
        inew->ub = &btemp->ub;
        inew->root = btemp;
        inew->next = allvars;
        allvars = inew;
        if (btemp->innervars) {
            for (size_t i = 0; i < language_array_nrows(btemp->innervars); i++) {
                language_tvar_t *ivar = (language_tvar_t *)language_array_ptr_ref(btemp->innervars, i);
                language_ivarbinding_t *inew = (language_ivarbinding_t *)alloca(sizeof(language_ivarbinding_t));
                inew->var = (language_tvar_t **)&iparams[niparams++]; *inew->var = ivar;
                inew->lb = &iparams[niparams++]; *inew->lb = ivar->lb;
                inew->ub = &iparams[niparams++]; *inew->ub = ivar->ub;
                inew->root = btemp;
                inew->next = allvars;
                allvars = inew;
            }
        }
    }

    // remove/replace/rewrap free occurrences of this var in the environment
    int wrapped = 0;
    language_ivarbinding_t *pwrap = NULL;
    for (language_ivarbinding_t *btemp = allvars, *pbtemp = NULL; btemp != NULL; btemp = btemp->next) {
        int bdepth0 = btemp->root->depth0;
        ivar = *btemp->var;
        ilb = *btemp->lb;
        iub = *btemp->ub;
        if (language_has_typevar(ilb, vb->var)) {
            assert(btemp->root->var == ivar || bdepth0 == vb->depth0);
            if (vb->lb == (language_value_t*)ivar) {
                LANGUAGE_GC_POP();
                LANGUAGE_GC_POP();
                return language_bottom_type;
            }
            if (varval) {
                LANGUAGE_TRY {
                    *btemp->lb = language_substitute_var(ilb, vb->var, varval);
                }
                LANGUAGE_CATCH {
                    res = language_bottom_type;
                }
            }
            else if (ilb == (language_value_t*)vb->var) {
                *btemp->lb = vb->lb;
            }
            else if (bdepth0 == vb->depth0 && !language_has_typevar(vb->lb, ivar) && !language_has_typevar(vb->ub, ivar)) {
                // if our variable is T, and some outer variable has constraint S = Ref{T},
                // move the `where T` outside `where S` instead of putting it here. issue #21243.
                if (newvar != vb->var)
                    *btemp->lb = language_substitute_var(ilb, vb->var, (language_value_t*)newvar);
                if (!wrapped) pwrap = pbtemp;
                wrapped = 1;
            }
            else {
                *btemp->lb = language_new_struct(language_unionall_type, vb->var, ilb);
            }
            assert((language_value_t*)ivar != *btemp->lb);
        }
        if (language_has_typevar(iub, vb->var)) {
            assert(btemp->root->var == ivar || bdepth0 == vb->depth0);
            if (vb->ub == (language_value_t*)ivar) {
                *btemp->ub = omit_bad_union(iub, vb->var);
                if (*btemp->ub == language_bottom_type && *btemp->ub != *btemp->lb) {
                    LANGUAGE_GC_POP();
                    LANGUAGE_GC_POP();
                    return language_bottom_type;
                }
            }
            if (varval) {
                *btemp->ub = language_substitute_var_nothrow(iub, vb->var, varval);
                if (*btemp->ub == NULL)
                    res = language_bottom_type;
            }
            else if (iub == (language_value_t*)vb->var) {
                // TODO: this loses some constraints, such as in this test, where we replace T4<:S3 (e.g. T4==S3 since T4 only appears covariantly once) with T4<:Any
                // a = Tuple{Float64,T3,T4} where T4 where T3
                // b = Tuple{S2,Tuple{S3},S3} where S2 where S3
                // Tuple{Float64, T3, T4} where {S3, T3<:Tuple{S3}, T4<:S3}
                *btemp->ub = vb->ub;
            }
            else if (bdepth0 == vb->depth0 && !language_has_typevar(vb->lb, ivar) && !language_has_typevar(vb->ub, ivar)) {
                if (newvar != vb->var)
                    *btemp->ub = language_substitute_var(iub, vb->var, (language_value_t*)newvar);
                if (!wrapped) pwrap = pbtemp;
                wrapped = 1;
            }
            else
                *btemp->ub = language_new_struct(language_unionall_type, vb->var, iub);
            assert((language_value_t*)ivar != *btemp->ub);
        }
        pbtemp = btemp;
    }

    // Insert the newvar into the (reversed) var list if needed.
    if (wrapped) {
        language_ivarbinding_t *wrap = pwrap == NULL ? allvars : pwrap->next;
        language_ivarbinding_t *inew = (language_ivarbinding_t *)alloca(sizeof(language_ivarbinding_t));
        inew->var = &newvar;
        inew->lb = &newvar->lb;
        inew->ub = &newvar->ub;;
        inew->root = wrap->root;
        inew->next = wrap;
        if (pwrap != NULL)
            pwrap->next = inew;
        else
            allvars = inew;
    }

    // Re-sort the innervar inside the (reversed) var list.
    // `language_has_typevar` is used as the partial-ordering predicate.
    // If this is slow, we could possibly switch to a simpler graph sort, such as Tarjan's SCC.
    if (icount > 0) {
        language_ivarbinding_t *pib1 = NULL;
        while (1) {
            language_ivarbinding_t *ib1 = pib1 == NULL ? allvars : pib1->next;
            if (ib1 == NULL) break;
            if (language_has_free_typevars(*ib1->lb) || language_has_free_typevars(*ib1->ub)) {
                int changed = 0;
                language_ivarbinding_t *pib2 = ib1, *ib2 = ib1->next;
                while (ib2 != NULL) {
                    int isinnervar = ib2->root->var != *ib2->var;
                    if (isinnervar && ib1->root->depth0 == ib2->root->depth0 &&
                        (language_has_typevar(*ib1->lb, *ib2->var) ||
                        language_has_typevar(*ib1->ub, *ib2->var))) {
                        pib2->next = ib2->next;
                        ib2->next = ib1;
                        ib2->root = ib1->root;
                        if (pib1)
                            pib1->next = ib2;
                        else
                            allvars = ib2;
                        changed = 1;
                        break;
                    }
                    pib2 = ib2;
                    ib2 = ib2->next;
                }
                if (changed) continue;
            }
            pib1 = ib1;
        }
    }

    // Freeze the innervars' lb/ub and perform substitution if needed.
    for (language_ivarbinding_t *btemp1 = allvars; btemp1 != NULL; btemp1 = btemp1->next) {
        ivar = *btemp1->var;
        ilb = *btemp1->lb;
        iub = *btemp1->ub;
        int isinnervar = btemp1->root->var != ivar;
        if (isinnervar && (ivar->lb != ilb || ivar->ub != iub)) {
            nivar = (language_value_t *)language_new_typevar(ivar->name, ilb, iub);
            if (language_has_typevar(res, ivar))
                res = language_substitute_var(res, ivar, nivar);
            for (language_ivarbinding_t *btemp2 = btemp1->next; btemp2 != NULL; btemp2 = btemp2->next) {
                ilb = *btemp2->lb;
                iub = *btemp2->ub;
                if (language_has_typevar(ilb, ivar))
                    *btemp2->lb = language_substitute_var(ilb, ivar, nivar);
                if (language_has_typevar(iub, ivar))
                    *btemp2->ub = language_substitute_var(iub, ivar, nivar);
            }
            *btemp1->var = (language_tvar_t *)nivar;
        }
    }

    // Switch back the innervars' storage.
    while (1) {
        language_ivarbinding_t *btemp = allvars;
        language_varbinding_t *root = btemp ? btemp->root : vb;
        size_t icount = 0;
        while (btemp && btemp->root == root) {
            btemp = btemp->next;
            icount++;
        }
        if (root != vb) icount--;
        if (root->innervars != NULL) {
            size_t len = language_array_nrows(root->innervars);
            if (icount > len)
                language_array_grow_end(root->innervars, icount - len);
            if (icount < len)
                language_array_del_end(root->innervars, len - icount);
        }
        else if (icount > 0) {
            root->innervars = language_alloc_array_1d(language_array_any_type, icount);
        }
        btemp = allvars;
        for (size_t i = icount; i > 0; i--) {
            language_array_ptr_set(root->innervars, i - 1, (language_value_t*)*btemp->var);
            btemp = btemp->next;
        }
        if (root == vb) break;
        assert(*btemp->var == root->var);
        allvars = btemp->next;
        assert(allvars == NULL || allvars->root != root);
    }
    LANGUAGE_GC_POP();

    // if `v` still occurs, re-wrap body in `UnionAll v` or eliminate the UnionAll
    if (language_has_typevar(res, vb->var)) {
        if (varval) {
            // you can construct `T{x} where x` even if T's parameter is actually
            // limited. in that case we might get an invalid instantiation here.
            res = language_substitute_var_nothrow(res, vb->var, varval);
            // simplify chains of UnionAlls where bounds become equal
            while (res != NULL && language_is_unionall(res) && obviously_egal(((language_unionall_t*)res)->var->lb,
                                                         ((language_unionall_t*)res)->var->ub)) {
                language_unionall_t * ures = (language_unionall_t *)res;
                res = language_substitute_var_nothrow(ures->body, ures->var, ures->var->lb);
            }
            if (res == NULL)
                res = language_bottom_type;
        }
        else {
            if (newvar != vb->var)
                res = language_substitute_var(res, vb->var, (language_value_t*)newvar);
            varval = (language_value_t*)newvar;
            if (!wrapped)
                res = language_type_unionall((language_tvar_t*)newvar, res);
        }
    }

    if (vb->innervars != NULL) {
        for (size_t i = 0; i < language_array_nrows(vb->innervars); i++) {
            language_tvar_t *var = (language_tvar_t*)language_array_ptr_ref(vb->innervars, i);
            res = language_type_unionall(var, res);
        }
    }

    if (vb->right && e->envidx < e->envsz) {
        language_value_t *oldval = e->envout[e->envidx];
        if (!varval || (!is_leaf_bound(varval) && !vb->occurs_inv))
            e->envout[e->envidx] = (language_value_t*)vb->var;
        else if (!(oldval && language_is_typevar(oldval) && language_is_long(varval)))
            e->envout[e->envidx] = varval;
    }

    LANGUAGE_GC_POP();
    return res;
}

static language_value_t *intersect_unionall_(language_value_t *t, language_unionall_t *u, language_stenv_t *e, int8_t R, int param, language_varbinding_t *vb)
{
    language_varbinding_t *btemp = e->vars;
    int envsize = 0;
    while (btemp != NULL) {
        envsize++;
        if (envsize > 120) {
            vb->limited = 1;
            return t;
        }
        btemp = btemp->prev;
    }
    u = unalias_unionall(u, e);
    LANGUAGE_GC_PUSH1(&u);
    vb->var = u->var;
    e->vars = vb;
    language_value_t *res;
    if (R) {
        e->envidx++;
        res = intersect(t, u->body, e, param);
        e->envidx--;
    }
    else {
        res = intersect(u->body, t, e, param);
    }
    vb->concrete |= (vb->occurs_cov > 1 && is_leaf_typevar(u->var) &&
                     !var_occurs_invariant(u->body, u->var));

    // handle the "diagonal dispatch" rule, which says that a type var occurring more
    // than once, and only in covariant position, is constrained to concrete types. E.g.
    //  ( Tuple{Int, Int}    <: Tuple{T, T} where T) but
    // !( Tuple{Int, String} <: Tuple{T, T} where T)
    // Then check concreteness by checking that the lower bound is not an abstract type.
    if (res != language_bottom_type && vb->concrete) {
        if (language_is_typevar(vb->lb)) {
        }
        else if (!is_leaf_bound(vb->lb)) {
            res = language_bottom_type;
        }
    }

    e->vars = vb->prev;

    if (res != language_bottom_type) {
        if (vb->ub == language_bottom_type && vb->occurs_cov) {
            // T=Bottom in covariant position
            res = language_bottom_type;
        }
        else if (language_has_typevar(vb->lb, u->var)) {
            // fail on circular constraints
            res = language_bottom_type;
        }
        else {
            LANGUAGE_GC_PUSH1(&res);
            vb->ub = omit_bad_union(vb->ub, u->var);
            LANGUAGE_GC_POP();
            if (vb->ub == language_bottom_type && vb->ub != vb->lb)
                res = language_bottom_type;
        }
    }
    if (res != language_bottom_type)
        // res is rooted by callee
        res = finish_unionall(res, vb, u, e);
    LANGUAGE_GC_POP();
    return res;
}

static int always_occurs_cov(language_value_t *v, language_tvar_t *var, int param) LANGUAGE_NOTSAFEPOINT
{
    if (param > 1) {
        return 0;
    }
    else if (v == (language_value_t*)var) {
        return param == 1;
    }
    else if (language_is_uniontype(v)) {
        return always_occurs_cov(((language_uniontype_t*)v)->a, var, param) &&
               always_occurs_cov(((language_uniontype_t*)v)->b, var, param);
    }
    else if (language_is_unionall(v)) {
        language_unionall_t *ua = (language_unionall_t*)v;
        return ua->var != var && (
            always_occurs_cov(ua->var->ub, var, 0) ||
            always_occurs_cov(ua->body, var, param));
    }
    else if (language_is_vararg(v)) {
        language_vararg_t *vm = (language_vararg_t*)v;
        return vm->T && always_occurs_cov(vm->T, var, param);
    }
    else if (language_is_datatype(v)) {
        int nparam = language_is_tuple_type(v) ? 1 : param;
        for (size_t i = 0; i < language_nparams(v); i++) {
            if (always_occurs_cov(language_tparam(v, i), var, nparam))
                return 1;
        }
    }
    return 0;
}

static language_value_t *intersect_unionall(language_value_t *t, language_unionall_t *u, language_stenv_t *e, int8_t R, int param)
{
    language_value_t *res = NULL;
    language_savedenv_t se;
    language_varbinding_t vb = { u->var, u->var->lb, u->var->ub, R, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           e->invdepth, NULL, e->vars };
    LANGUAGE_GC_PUSH4(&res, &vb.lb, &vb.ub, &vb.innervars);
    save_env(e, &se, 1);
    int noinv = !var_occurs_invariant(u->body, u->var);
    if (is_leaf_typevar(u->var) && noinv && always_occurs_cov(u->body, u->var, param))
        vb.constraintkind = 1;
    res = intersect_unionall_(t, u, e, R, param, &vb);
    vb.intersected = 1;
    if (vb.limited) {
        // if the environment got too big, avoid tree recursion and propagate the flag
        if (e->vars)
            e->vars->limited = 1;
    }
    else if (res != language_bottom_type) {
        int constraint1 = vb.constraintkind;
        if (vb.concrete || vb.occurs_inv>1 || (vb.occurs_inv && vb.occurs_cov))
            vb.constraintkind = vb.concrete ? 1 : 2;
        else if (u->var->lb != language_bottom_type)
            vb.constraintkind = 2;
        else if (vb.occurs_cov && noinv)
            vb.constraintkind = 1;
        int reintersection = constraint1 != vb.constraintkind || vb.concrete;
        if (reintersection) {
            if (constraint1 == 1) {
                vb.lb = vb.var->lb;
                vb.ub = vb.var->ub;
            }
            restore_env(e, &se, vb.constraintkind == 1 ? 1 : 0);
            vb.occurs = vb.occurs_cov = vb.occurs_inv = 0;
            res = intersect_unionall_(t, u, e, R, param, &vb);
        }
    }
    free_env(&se);
    LANGUAGE_GC_POP();
    return res;
}

static language_value_t *intersect_invariant(language_value_t *x, language_value_t *y, language_stenv_t *e);

// check n = (length of vararg type v)
static int intersect_vararg_length(language_value_t *v, ssize_t n, language_stenv_t *e, int8_t R)
{
    language_value_t *N = language_unwrap_vararg_num(v);
    // only do the check if N is free in the tuple type's last parameter
    if (N && language_is_typevar(N)) {
        language_value_t *len = language_box_long(n);
        LANGUAGE_GC_PUSH1(&len);
        language_value_t *il = R ? intersect_invariant(len, N, e) : intersect_invariant(N, len, e);
        LANGUAGE_GC_POP();
        if (il == NULL || il == language_bottom_type)
            return 0;
    }
    return 1;
}

static language_value_t *intersect_varargs(language_vararg_t *vmx, language_vararg_t *vmy, ssize_t offset, language_stenv_t *e, int param)
{
    // Vararg: covariant in first parameter, invariant in second
    language_value_t *xp1=language_unwrap_vararg(vmx), *xp2=language_unwrap_vararg_num(vmx),
                *yp1=language_unwrap_vararg(vmy), *yp2=language_unwrap_vararg_num(vmy);
    // in Vararg{T1} <: Vararg{T2}, need to check subtype twice to
    // simulate the possibility of multiple arguments, which is needed
    // to implement the diagonal rule correctly.
    if (intersect(xp1, yp1, e, param==0 ? 1 : param) == language_bottom_type)
        return language_bottom_type;
    language_value_t *i2=NULL, *ii = intersect(xp1, yp1, e, 1);
    if (ii == language_bottom_type)
        return language_bottom_type;
    if (!xp2 && !yp2) {
        if (obviously_egal(xp1, ii))
            ii = (language_value_t*)vmx;
        else if (obviously_egal(yp1, ii))
            ii = (language_value_t*)vmy;
        else {
            LANGUAGE_GC_PUSH1(&ii);
            ii = (language_value_t*)language_wrap_vararg(ii, NULL, 1, 0);
            LANGUAGE_GC_POP();
        }
        return ii;
    }
    LANGUAGE_GC_PUSH2(&ii, &i2);
    assert(e->Loffset == 0);
    e->Loffset = offset;
    language_varbinding_t *xb = NULL, *yb = NULL;
    int8_t max_offsetx = 0, max_offsety = 0;
    if (xp2) {
        assert(language_is_typevar(xp2));
        xb = lookup(e, (language_tvar_t*)xp2);
        if (xb) xb->intvalued = 1;
        if (xb) max_offsetx = xb->max_offset;
        if (!yp2)
            i2 = bound_var_below((language_tvar_t*)xp2, xb, e, 0);
    }
    if (yp2) {
        assert(language_is_typevar(yp2));
        yb = lookup(e, (language_tvar_t*)yp2);
        if (yb) yb->intvalued = 1;
        if (yb) max_offsety = yb->max_offset;
        if (!xp2)
            i2 = bound_var_below((language_tvar_t*)yp2, yb, e, 1);
    }
    if (xp2 && yp2) {
        // Vararg{T,N} <: Vararg{T2,N2}; equate N and N2
        i2 = intersect_invariant(xp2, yp2, e);
        if (i2 == NULL || i2 == language_bottom_type || (language_is_long(i2) && language_unbox_long(i2) < 0) ||
            !((language_is_typevar(i2) && ((language_tvar_t*)i2)->lb == language_bottom_type &&
                ((language_tvar_t*)i2)->ub == (language_value_t*)language_any_type) || language_is_long(i2))) {
            i2 = language_bottom_type;
        }
    }
    assert(e->Loffset == offset);
    e->Loffset = 0;
    if (i2 == language_bottom_type) {
        ii = (language_value_t*)language_bottom_type;
    }
    else {
        if (xb && !xb->intersected) {
            xb->max_offset = max_offsetx;
            if (offset > xb->max_offset && xb->max_offset >= 0)
                xb->max_offset = offset > 32 ? 32 : offset;
        }
        if (yb && !yb->intersected) {
            yb->max_offset = max_offsety;
            if (-offset > yb->max_offset && yb->max_offset >= 0)
                yb->max_offset = -offset > 32 ? 32 : -offset;
        }
        if (xp2 && obviously_egal(xp1, ii) && obviously_egal(xp2, i2))
            ii = (language_value_t*)vmx;
        else if (yp2 && obviously_egal(yp1, ii) && obviously_egal(yp2, i2))
            ii = (language_value_t*)vmy;
        else
            ii = (language_value_t*)language_wrap_vararg(ii, i2, 1, 0);
    }
    LANGUAGE_GC_POP();
    return ii;
}


static language_value_t *intersect_tuple(language_datatype_t *xd, language_datatype_t *yd, language_stenv_t *e, int param)
{
    size_t lx = language_nparams(xd), ly = language_nparams(yd);
    size_t llx = lx, lly = ly;
    if (lx == 0 && ly == 0)
        return (language_value_t*)yd;
    int vx=0, vy=0;
    language_vararg_kind_t vvx = lx > 0 ? language_vararg_kind(language_tparam(xd, lx-1)) : LANGUAGE_VARARG_NONE;
    language_vararg_kind_t vvy = ly > 0 ? language_vararg_kind(language_tparam(yd, ly-1)) : LANGUAGE_VARARG_NONE;
    if (vvx == LANGUAGE_VARARG_INT)
        llx += language_unbox_long(language_unwrap_vararg_num((language_vararg_t *)language_tparam(xd, lx-1))) - 1;
    if (vvy == LANGUAGE_VARARG_INT)
        lly += language_unbox_long(language_unwrap_vararg_num((language_vararg_t *)language_tparam(yd, ly-1))) - 1;
    if (vvx == LANGUAGE_VARARG_BOUND && (vvy == LANGUAGE_VARARG_BOUND || vvy == LANGUAGE_VARARG_UNBOUND)) {
        language_value_t *xlen = language_unwrap_vararg_num((language_vararg_t*)language_tparam(xd, lx-1));
        assert(xlen && language_is_typevar(xlen));
        language_varbinding_t *xb = lookup(e, (language_tvar_t*)xlen);
        if (xb && xb->intersected && xb->max_offset > 0) {
            assert(xb->max_offset <= 32);
            llx += xb->max_offset;
        }
    }
    if (vvy == LANGUAGE_VARARG_BOUND && (vvx == LANGUAGE_VARARG_BOUND || vvx == LANGUAGE_VARARG_UNBOUND)) {
        language_value_t *ylen = language_unwrap_vararg_num((language_vararg_t*)language_tparam(yd, ly-1));
        assert(ylen && language_is_typevar(ylen));
        language_varbinding_t *yb = lookup(e, (language_tvar_t*)ylen);
        if (yb && yb->intersected && yb->max_offset > 0) {
            assert(yb->max_offset <= 32);
            lly += yb->max_offset;
        }
    }

    if ((vvx == LANGUAGE_VARARG_NONE || vvx == LANGUAGE_VARARG_INT) &&
        (vvy == LANGUAGE_VARARG_NONE || vvy == LANGUAGE_VARARG_INT)) {
        if (llx != lly)
            return language_bottom_type;
    }

    size_t np = llx > lly ? llx : lly;
    language_value_t *res = NULL;
    language_svec_t *p = NULL;
    language_value_t **params;
    language_value_t **roots;
    LANGUAGE_GC_PUSHARGS(roots, np < 64 ? np : 1);
    if (np < 64) {
        params = roots;
    }
    else {
        p = language_alloc_svec(np);
        roots[0] = (language_value_t*)p;
        params = language_svec_data(p);
    }
    size_t i=0, j=0;
    language_value_t *xi, *yi;
    int isx = 1, isy = 1; // try to reuse the object x or y as res whenever we can (e.g. when it is the supertype) instead of allocating a copy
    while (1) {
        vx = vy = 0;
        xi = i < llx ? language_tparam(xd, i < lx ? i : lx - 1) : NULL;
        yi = j < lly ? language_tparam(yd, j < ly ? j : ly - 1) : NULL;
        if (xi == NULL && yi == NULL) {
            assert(i == j && i == np);
            break;
        }
        if (xi && language_is_vararg(xi)) vx = vvx == LANGUAGE_VARARG_UNBOUND || (vvx == LANGUAGE_VARARG_BOUND && i == llx - 1);
        if (yi && language_is_vararg(yi)) vy = vvy == LANGUAGE_VARARG_UNBOUND || (vvy == LANGUAGE_VARARG_BOUND && j == lly - 1);
        if (xi == NULL || yi == NULL) {
            if (vx && intersect_vararg_length(xi, lly+1-llx, e, 0)) {
                np = j;
                p = NULL;
            }
            else if (vy && intersect_vararg_length(yi, llx+1-lly, e, 1)) {
                np = i;
                p = NULL;
            }
            else {
                res = language_bottom_type;
            }
            break;
        }
        language_value_t *ii = NULL;
        if (vx && vy) {
            ii = intersect_varargs((language_vararg_t*)xi,
                                   (language_vararg_t*)yi,
                                   lly - llx, // xi's offset: {A^n...,Vararg{T,N}} ∩ {Vararg{S,M}}
                                            // {(A∩S)^n...,Vararg{T∩S,N}} plus N = M-n
                                   e,
                                   param);
        }
        else {
            ii = intersect(language_is_vararg(xi) ? language_unwrap_vararg(xi) : xi,
                           language_is_vararg(yi) ? language_unwrap_vararg(yi) : yi,
                           e,
                           param == 0 ? 1 : param);
        }
        if (ii == language_bottom_type) {
            if (vx && vy) {
                language_varbinding_t *xb=NULL, *yb=NULL;
                language_value_t *xlen = language_unwrap_vararg_num(xi);
                assert(xlen == NULL || language_is_typevar(xlen));
                if (xlen) xb = lookup(e, (language_tvar_t*)xlen);
                language_value_t *ylen = language_unwrap_vararg_num(yi);
                assert(ylen == NULL || language_is_typevar(ylen));
                if (ylen) yb = lookup(e, (language_tvar_t*)ylen);
                int len = i > j ? i : j;
                if ((xb && language_is_long(xb->lb) && llx-1+language_unbox_long(xb->lb) != len) ||
                    (yb && language_is_long(yb->lb) && lly-1+language_unbox_long(yb->lb) != len)) {
                    res = language_bottom_type;
                }
                else {
                    assert(e->Loffset == 0);
                    if (xb) set_var_to_const(xb, language_box_long(len-llx+1), e, 0);
                    if (yb) set_var_to_const(yb, language_box_long(len-lly+1), e, 1);
                    np = len;
                    p = NULL;
                }
            }
            else {
                res = language_bottom_type;
            }
            break;
        }
        isx = isx && ii == xi;
        isy = isy && ii == yi;
        if (p)
            language_svecset(p, (i > j ? i : j), ii);
        else
            params[i > j ? i : j] = ii;
        if (vx && vy)
            break;
        if (!vx) i++;
        if (!vy) j++;
    }
    // TODO: handle Vararg with explicit integer length parameter
    if (res == NULL) {
        assert(!p || np == language_svec_len(p));
        isx = isx && lx == np;
        isy = isy && ly == np;
        if (!isx && !isy) {
            // do a more careful check now for equivalence
            if (lx == np) {
                isx = 1;
                for (i = 0; i < np; i++)
                    isx = isx && obviously_egal(params[i], language_tparam(xd, i));
            }
            if (!isx && ly == np) {
                isy = 1;
                for (i = 0; i < np; i++)
                    isy = isy && obviously_egal(params[i], language_tparam(yd, i));
            }
        }
        if (isx)
            res = (language_value_t*)xd;
        else if (isy)
            res = (language_value_t*)yd;
        else if (p)
            res = language_apply_tuple_type(p, 1);
        else
            res = language_apply_tuple_type_v(params, np);
    }
    LANGUAGE_GC_POP();
    return res;
}

static void flip_vars(language_stenv_t *e)
{
    language_varbinding_t *btemp = e->vars;
    while (btemp != NULL) {
        btemp->right = !btemp->right;
        btemp = btemp->prev;
    }
}

// intersection where xd nominally inherits from yd
static language_value_t *intersect_sub_datatype(language_datatype_t *xd, language_datatype_t *yd, language_stenv_t *e, int R, int param)
{
    // attempt to populate additional constraints into `e`
    // if that attempt fails, then return bottom
    // otherwise return xd (finish_unionall will later handle propagating those constraints)
    assert(e->Loffset == 0);
    language_value_t *isuper = R ? intersect((language_value_t*)yd, (language_value_t*)xd->super, e, param) :
                             intersect((language_value_t*)xd->super, (language_value_t*)yd, e, param);
    if (isuper == language_bottom_type)
        return language_bottom_type;
    return (language_value_t*)xd;
}

static language_value_t *intersect_invariant(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    if (e->Loffset == 0 && !language_has_free_typevars(x) && !language_has_free_typevars(y)) {
        return (language_subtype(x,y) && language_subtype(y,x)) ? y : NULL;
    }
    e->invdepth++;
    language_value_t *ii = intersect(x, y, e, 2);
    e->invdepth--;
    if (language_is_typevar(x) && language_is_typevar(y) && language_is_typevar(ii))
        return ii; // skip the following check due to possible circular constraints.
    if (ii == language_bottom_type) {
        if (!subtype_in_env(x, language_bottom_type, e))
            return NULL;
        flip_vars(e); flip_offset(e);
        if (!subtype_in_env(y, language_bottom_type, e)) {
            flip_vars(e); flip_offset(e);
            return NULL;
        }
        flip_vars(e); flip_offset(e);
        return language_bottom_type;
    }
    language_savedenv_t se;
    LANGUAGE_GC_PUSH1(&ii);
    save_env(e, &se, 1);
    if (!subtype_in_env_existential(x, y, e))
        ii = NULL;
    else {
        restore_env(e, &se, 1);
        flip_offset(e);
        if (!subtype_in_env_existential(y, x, e))
            ii = NULL;
        flip_offset(e);
    }
    restore_env(e, &se, 1);
    free_env(&se);
    LANGUAGE_GC_POP();
    return ii;
}

// intersection where x == Type{...} and y is not
static language_value_t *intersect_type_type(language_value_t *x, language_value_t *y, language_stenv_t *e, int8_t R)
{
    assert(e->Loffset == 0);
    language_value_t *p0 = language_tparam0(x);
    if (!language_is_typevar(p0))
        return (language_typeof(p0) == y) ? x : language_bottom_type;
    if (!language_is_kind(y)) return language_bottom_type;
    if (y == (language_value_t*)language_typeofbottom_type && ((language_tvar_t*)p0)->lb == language_bottom_type)
        return (language_value_t*)language_wrap_Type(language_bottom_type);
    if (((language_tvar_t*)p0)->ub == (language_value_t*)language_any_type)
        return y;
    return x;
    /*
    language_value_t *ii = R ? intersect_invariant(y, language_tparam0(x), e) : intersect_invariant(language_tparam0(x), y, e);
    // NOTE: we cannot express e.g. DataType ∩ (UnionAll T<:Integer Type{T}), so returning `x`
    // here is a conservative over-estimate.
    if (ii == NULL || ii == language_bottom_type) return x;
    if (ii == y) return ii;
    return (language_value_t*)language_wrap_Type(ii);
    */
}

// cmp <= 0: is x already <= y in this environment
// cmp >= 0: is x already >= y in this environment
static int compareto_var(language_value_t *x, language_tvar_t *y, language_stenv_t *e, int cmp) LANGUAGE_NOTSAFEPOINT
{
    if (x == (language_value_t*)y)
        return 1;
    if (!language_is_typevar(x))
        return 0;
    language_varbinding_t *xv = lookup(e, (language_tvar_t*)x);
    if (xv == NULL)
        return 0;
    int ans = 1;
    if (cmp <= 0)
        ans &= compareto_var(xv->ub, y, e, cmp);
    if (cmp >= 0)
        ans &= compareto_var(xv->lb, y, e, cmp);
    return ans;
}

// Check whether the environment already asserts x <: y via recorded bounds.
// This is used to avoid adding redundant constraints that lead to cycles.
// Note this is a semi-predicate: 1 => is a subtype, 0 => unknown
static int subtype_by_bounds(language_value_t *x, language_value_t *y, language_stenv_t *e) LANGUAGE_NOTSAFEPOINT
{
    if (!language_is_typevar(x) || !language_is_typevar(y))
        return 0;
    return compareto_var(x, (language_tvar_t*)y, e, -1) || compareto_var(y, (language_tvar_t*)x, e, 1);
}

static int has_typevar_via_env(language_value_t *x, language_tvar_t *t, language_stenv_t *e)
{
    if (e->Loffset == 0) {
        language_varbinding_t *temp = e->vars;
        while (temp != NULL) {
            if (temp->var == t)
                break;
            if (temp->lb == temp->ub &&
                temp->lb == (language_value_t *)t &&
                language_has_typevar(x, temp->var))
                return 1;
            temp = temp->prev;
        }
    }
    return language_has_typevar(x, t);
}

// `param` means we are currently looking at a parameter of a type constructor
// (as opposed to being outside any type constructor, or comparing variable bounds).
// this is used to record the positions where type variables occur for the
// diagonal rule (record_var_occurrence).
static language_value_t *intersect(language_value_t *x, language_value_t *y, language_stenv_t *e, int param)
{
    if (x == y) return y;
    if (language_is_typevar(x)) {
        if (language_is_typevar(y)) {
            language_varbinding_t *xx = lookup(e, (language_tvar_t*)x);
            language_varbinding_t *yy = lookup(e, (language_tvar_t*)y);
            int R = 0;
            if (xx && yy && var_outside(e, (language_tvar_t*)x, (language_tvar_t*)y)) {
                // to preserve variable identities correctly, always accumulate bounds
                // on the outer variable, return the outer variable, and set the inner
                // variable equal to the outer variable.
                language_value_t *temp; language_varbinding_t *tvb;
                temp = x; x = y; y = temp;
                tvb = xx; xx = yy; yy = tvb;
                R = 1;
            }
            if (param == 2) {
                language_value_t *xlb = xx ? xx->lb : ((language_tvar_t*)x)->lb;
                language_value_t *xub = xx ? xx->ub : ((language_tvar_t*)x)->ub;
                language_value_t *ylb = yy ? yy->lb : ((language_tvar_t*)y)->lb;
                language_value_t *yub = yy ? yy->ub : ((language_tvar_t*)y)->ub;
                if (xx && yy && xx->depth0 != yy->depth0) {
                    record_var_occurrence(xx, e, param);
                    record_var_occurrence(yy, e, param);
                    return subtype_in_env(yy->ub, yy->lb, e) ? y : language_bottom_type;
                }
                if (xub == xlb && language_is_typevar(xub)) {
                    record_var_occurrence(xx, e, param);
                    if (y == xub) {
                        record_var_occurrence(yy, e, param);
                        return y;
                    }
                    if (R) flip_offset(e);
                    language_value_t *res = intersect(xub, y, e, param);
                    if (R) flip_offset(e);
                    return res;
                }
                if (yub == ylb && language_is_typevar(yub)) {
                    record_var_occurrence(yy, e, param);
                    if (R) flip_offset(e);
                    language_value_t *res = intersect(x, yub, e, param);
                    if (R) flip_offset(e);
                    return res;
                }
                if (xub == xlb && language_is_typevar(xub)) {
                    record_var_occurrence(xx, e, param);
                    if (y == xub) {
                        record_var_occurrence(yy, e, param);
                        return y;
                    }
                    if (R) flip_offset(e);
                    language_value_t *res = intersect(xub, y, e, param);
                    if (R) flip_offset(e);
                    return res;
                }
                if (yub == ylb && language_is_typevar(yub)) {
                    record_var_occurrence(yy, e, param);
                    if (R) flip_offset(e);
                    language_value_t *res = intersect(x, yub, e, param);
                    if (R) flip_offset(e);
                    return res;
                }
                record_var_occurrence(xx, e, param);
                record_var_occurrence(yy, e, param);
                int xoffset = R ? -e->Loffset : e->Loffset;
                if (!language_is_type(ylb) && !language_is_typevar(ylb)) {
                    if (xx)
                        return set_var_to_const(xx, ylb, e, R);
                    if ((xlb == language_bottom_type && xub == (language_value_t*)language_any_type) || language_egal(xlb, ylb)) {
                        if (xoffset == 0)
                            return ylb;
                        else if (language_is_long(ylb)) {
                            if (xoffset > 0)
                                return ylb;
                            else
                                return language_box_long(language_unbox_long(ylb) + xoffset);
                        }
                    }
                    return language_bottom_type;
                }
                if (!language_is_type(xlb) && !language_is_typevar(xlb)) {
                    if (yy)
                        return set_var_to_const(yy, xlb, e, !R);
                    if (ylb == language_bottom_type && yub == (language_value_t*)language_any_type) {
                        if (xoffset == 0)
                            return xlb;
                        else if (language_is_long(xlb)) {
                            if (xoffset < 0)
                                return xlb;
                            else
                                return language_box_long(language_unbox_long(ylb) - xoffset);
                        }
                    }
                    return language_bottom_type;
                }
                int ccheck;
                if (R) flip_offset(e);
                if (xlb == xub && ylb == yub &&
                    language_has_typevar(xlb, (language_tvar_t *)y) &&
                    language_has_typevar(ylb, (language_tvar_t *)x)) {
                    // special case for e.g.
                    // 1) Val{Y}<:X<:Val{Y} && Val{X}<:Y<:Val{X}
                    // 2) Y<:X<:Y && Val{X}<:Y<:Val{X} => Val{Y}<:Y<:Val{Y}
                    ccheck = 0;
                }
                else if (yub == xub ||
                    (subtype_by_bounds(xlb, yub, e) && subtype_by_bounds(ylb, xub, e))) {
                    ccheck = 1;
                }
                else {
                    if (R) flip_vars(e);
                    ccheck = subtype_in_env(xlb, yub, e);
                    if (ccheck) {
                        flip_offset(e);
                        ccheck = subtype_in_env(ylb, xub, e);
                        flip_offset(e);
                    }
                    if (R) flip_vars(e);
                }
                if (R) flip_offset(e);
                if (!ccheck)
                    return language_bottom_type;
                if ((has_typevar_via_env(xub, (language_tvar_t*)y, e) || has_typevar_via_env(xub, (language_tvar_t*)x, e)) &&
                    (has_typevar_via_env(yub, (language_tvar_t*)x, e) || has_typevar_via_env(yub, (language_tvar_t*)y, e))) {
                    // TODO: This doesn't make much sense.
                    // circular constraint. the result will be Bottom, but in the meantime
                    // we need to avoid computing intersect(xub, yub) since it won't terminate.
                    return y;
                }
                language_value_t *ub=NULL, *lb=NULL;
                LANGUAGE_GC_PUSH2(&lb, &ub);
                int d = xx ? xx->depth0 : yy ? yy->depth0 : 0;
                ub = R ? intersect_aside(yub, xub, e, d) : intersect_aside(xub, yub, e, d);
                if (reachable_var(xlb, (language_tvar_t*)y, e))
                    lb = ylb;
                else
                    lb = simple_join(xlb, ylb);
                if (yy && xoffset == 0) {
                    yy->lb = lb;
                    if (!reachable_var(ub, (language_tvar_t*)y, e))
                        yy->ub = ub;
                    assert(yy->ub != y);
                    assert(yy->lb != y);
                }
                if (xx && xoffset == 0 && !reachable_var(y, (language_tvar_t*)x, e)) {
                    xx->lb = y;
                    xx->ub = y;
                    assert(xx->ub != x);
                }
                LANGUAGE_GC_POP();
                // Here we always return the shorter `Vararg`'s length.
                return xoffset < 0 ? x : y;
            }
            assert(e->Loffset == 0);
            record_var_occurrence(xx, e, param);
            record_var_occurrence(yy, e, param);
            if (xx && yy && xx->concrete && !yy->concrete) {
                return intersect_var((language_tvar_t*)x, y, e, R, param);
            }
            return intersect_var((language_tvar_t*)y, x, e, !R, param);
        }
        record_var_occurrence(lookup(e, (language_tvar_t*)x), e, param);
        return intersect_var((language_tvar_t*)x, y, e, 0, param);
    }
    if (language_is_typevar(y)) {
        record_var_occurrence(lookup(e, (language_tvar_t*)y), e, param);
        return intersect_var((language_tvar_t*)y, x, e, 1, param);
    }
    if (e->Loffset == 0 && !language_has_free_typevars(x) && !language_has_free_typevars(y)) {
        if (language_subtype(x, y)) return x;
        if (language_subtype(y, x)) return y;
    }
    if (language_is_uniontype(x)) {
        if (y == ((language_uniontype_t*)x)->a || y == ((language_uniontype_t*)x)->b)
            return y;
        return intersect_union(y, (language_uniontype_t*)x, e, 0, param);
    }
    if (language_is_uniontype(y)) {
        if (x == ((language_uniontype_t*)y)->a || x == ((language_uniontype_t*)y)->b)
            return x;
        if (language_is_unionall(x) && (language_has_free_typevars(x) || language_has_free_typevars(y)))
            return intersect_unionall(y, (language_unionall_t*)x, e, 0, param);
        return intersect_union(x, (language_uniontype_t*)y, e, 1, param);
    }
    if (y == (language_value_t*)language_any_type) return x;
    if (x == (language_value_t*)language_any_type) return y;
    if (language_is_unionall(x)) {
        if (language_is_unionall(y)) {
            language_value_t *a=NULL, *b=language_bottom_type, *res=NULL;
            LANGUAGE_GC_PUSH2(&a, &b);
            language_savedenv_t se;
            save_env(e, &se, 0);
            a = intersect_unionall(y, (language_unionall_t*)x, e, 0, param);
            if (language_is_unionall(a)) {
                language_unionall_t *ua = (language_unionall_t*)a;
                if (language_is_unionall(ua->body)) {
                    language_unionall_t *ub = (language_unionall_t*)ua->body;
                    if (language_has_typevar(ub->var->ub, ua->var) ||
                        language_has_typevar(ub->var->lb, ua->var)) {
                        restore_env(e, &se, 0); // restore counts
                        b = intersect_unionall(x, (language_unionall_t*)y, e, 1, param);
                    }
                }
            }
            free_env(&se);
            if (!language_has_free_typevars(a) && !language_has_free_typevars(b)) {
                if (language_subtype(a, b))
                    res = b;
                else if (language_subtype(b, a))
                    res = a;
            }
            if (!res) res = simple_join(a, b);
            LANGUAGE_GC_POP();
            return res;
        }
        return intersect_unionall(y, (language_unionall_t*)x, e, 0, param);
    }
    if (language_is_unionall(y))
        return intersect_unionall(x, (language_unionall_t*)y, e, 1, param);
    if (language_is_datatype(x) && language_is_datatype(y)) {
        language_datatype_t *xd = (language_datatype_t*)x, *yd = (language_datatype_t*)y;
        if (param < 2) {
            if (language_is_type_type(x)) {
                if (!language_is_type_type(y))
                    return intersect_type_type(x, y, e, 0);
            }
            else if (language_is_type_type(y)) {
                return intersect_type_type(y, x, e, 1);
            }
        }
        if (xd->name == yd->name) {
            if (language_is_tuple_type(xd))
                return intersect_tuple(xd, yd, e, param);
            size_t i, np = language_nparams(xd);
            language_value_t **newparams;
            LANGUAGE_GC_PUSHARGS(newparams, np);
            int isx = 1, isy = 1; // try to reuse the object x or y as res whenever we can (e.g. when it is the supertype) instead of allocating a copy
            for (i = 0; i < np; i++) {
                language_value_t *xi = language_tparam(xd, i), *yi = language_tparam(yd, i);
                language_value_t *ii = intersect_invariant(xi, yi, e);
                if (ii == NULL)
                    break;
                isx = isx && ii == xi;
                isy = isy && ii == yi;
                newparams[i] = ii;
            }
            language_value_t *res = language_bottom_type;
            if (i == np) {
                if (!isx && !isy) {
                    // do a more careful check now for equivalence
                    isx = 1;
                    for (i = 0; i < np; i++)
                        isx = isx && obviously_egal(newparams[i], language_tparam(xd, i));
                    if (!isx) {
                        isy = 1;
                        for (i = 0; i < np; i++)
                            isy = isy && obviously_egal(newparams[i], language_tparam(yd, i));
                    }
                }
                if (isx)
                    res = x;
                else if (isy)
                    res = y;
                else {
                    LANGUAGE_TRY {
                        res = language_apply_type(xd->name->wrapper, newparams, np);
                    }
                    LANGUAGE_CATCH {
                        res = language_bottom_type;
                    }
                }
            }
            LANGUAGE_GC_POP();
            return res;
        }
        if (param == 2) return language_bottom_type;
        while (xd != language_any_type && xd->name != yd->name)
            xd = xd->super;
        if (xd == language_any_type) {
            xd = (language_datatype_t*)x;
            while (yd != language_any_type && yd->name != xd->name)
                yd = yd->super;
            if (yd == language_any_type)
                return language_bottom_type;
            return intersect_sub_datatype((language_datatype_t*)y, xd, e, 1, param);
        }
        return intersect_sub_datatype((language_datatype_t*)x, yd, e, 0, param);
    }
    if (language_egal(x, y)) return y;
    return language_bottom_type;
}

static int merge_env(language_stenv_t *e, language_savedenv_t *se, int count)
{
    if (count == 0)
        alloc_env(e, se, 1);
    language_value_t **roots = NULL;
    int nroots = 0;
    if (se->gcframe.nroots == LANGUAGE_GC_ENCODE_PUSHARGS(1)) {
        language_svec_t *sv = (language_svec_t*)se->roots[0];
        assert(language_is_svec(sv));
        roots = language_svec_data(sv);
        nroots = language_svec_len(sv);
    }
    else {
        roots = se->roots;
        nroots = se->gcframe.nroots >> 2;
    }
    int m = 0, n = 0;
    language_varbinding_t *v = e->vars;
    while (v != NULL) {
        if (count == 0) {
            // need to initialize this
            se->buf[m] = 0;
            se->buf[m+1] = 0;
            se->buf[m+2] = 0;
            se->buf[m+3] = v->max_offset;
        }
        language_value_t *b1, *b2;
        if (v->occurs) {
            // only merge lb/ub if this var occurs.
            b1 = roots[n];
            LANGUAGE_GC_PROMISE_ROOTED(b1); // clang-sagc doesn't know this came from our GC frame
            b2 = v->lb;
            LANGUAGE_GC_PROMISE_ROOTED(b2); // clang-sagc doesn't know the fields of this are stack GC roots
            roots[n] = b1 ? simple_meet(b1, b2, 0) : b2;
            b1 = roots[n+1];
            LANGUAGE_GC_PROMISE_ROOTED(b1); // clang-sagc doesn't know this came from our GC frame
            b2 = v->ub;
            LANGUAGE_GC_PROMISE_ROOTED(b2); // clang-sagc doesn't know the fields of this are stack GC roots
            roots[n+1] = b1 ? simple_join(b1, b2) : b2;
            // record the meeted vars.
            se->buf[m] = 1;
        }
        // `innervars` might be re-sorted inside `finish_unionall`.
        // We'd better always merge it.
        b1 = roots[n+2];
        LANGUAGE_GC_PROMISE_ROOTED(b1); // clang-sagc doesn't know this came from our GC frame
        b2 = (language_value_t*)v->innervars;
        LANGUAGE_GC_PROMISE_ROOTED(b2); // clang-sagc doesn't know the fields of this are stack GC roots
        if (b2 && b1 != b2) {
            if (b1)
                language_array_ptr_1d_append((language_array_t*)b1, (language_array_t*)b2);
            else
                roots[n+2] = b2;
        }
        // always merge occurs_inv/cov by max (never decrease)
        if (v->occurs_inv > se->buf[m+1])
            se->buf[m+1] = v->occurs_inv;
        if (v->occurs_cov > se->buf[m+2])
            se->buf[m+2] = v->occurs_cov;
        // always merge max_offset by min
        if (!v->intersected && v->max_offset < se->buf[m+3])
            se->buf[m+3] = v->max_offset;
        m = m + 4;
        n = n + 3;
        v = v->prev;
    }
    assert(n == nroots); (void)nroots;
    return count + 1;
}

// merge untouched vars' info.
static void final_merge_env(language_stenv_t *e, language_savedenv_t *me, language_savedenv_t *se)
{
    language_value_t **merged = NULL;
    language_value_t **saved = NULL;
    int nroots = 0;
    assert(se->gcframe.nroots == me->gcframe.nroots);
    if (se->gcframe.nroots == LANGUAGE_GC_ENCODE_PUSHARGS(1)) {
        language_svec_t *sv = (language_svec_t*)se->roots[0];
        assert(language_is_svec(sv));
        saved = language_svec_data(sv);
        nroots = language_svec_len(sv);
        sv = (language_svec_t*)me->roots[0];
        assert(language_is_svec(sv));
        merged = language_svec_data(sv);
        assert(nroots == language_svec_len(sv));
    }
    else {
        saved = se->roots;
        merged = me->roots;
        nroots = se->gcframe.nroots >> 2;
    }
    assert(nroots == current_env_length(e) * 3);
    assert(nroots % 3 == 0);
    for (int n = 0, m = 0; n < nroots; n += 3, m += 4) {
        if (merged[n] == NULL)
            merged[n] = saved[n];
        if (merged[n+1] == NULL)
            merged[n+1] = saved[n+1];
        language_value_t *b1, *b2;
        b1 = merged[n+2];
        LANGUAGE_GC_PROMISE_ROOTED(b1); // clang-sagc doesn't know this came from our GC frame
        b2 = saved[n+2];
        LANGUAGE_GC_PROMISE_ROOTED(b2); // clang-sagc doesn't know this came from our GC frame
        if (b2 && b1 != b2) {
            if (b1)
                language_array_ptr_1d_append((language_array_t*)b1, (language_array_t*)b2);
            else
                merged[n+2] = b2;
        }
        me->buf[m] |= se->buf[m];
    }
}

static void expand_local_env(language_stenv_t *e, language_value_t *res)
{
    language_varbinding_t *v = e->vars;
    // Here we pull in some typevar missed in fastpath.
    while (v != NULL) {
        v->occurs = v->occurs || language_has_typevar(res, v->var);
        assert(v->occurs == 0 || v->occurs == 1);
        v = v->prev;
    }
    v = e->vars;
    while (v != NULL) {
        if (v->occurs == 1) {
            language_varbinding_t *v2 = e->vars;
            while (v2 != NULL) {
                if (v2 != v && v2->occurs == 0)
                    v2->occurs = -(language_has_typevar(v->lb, v2->var) || language_has_typevar(v->ub, v2->var));
                v2 = v2->prev;
            }
        }
        v = v->prev;
    }
}

static language_value_t *intersect_all(language_value_t *x, language_value_t *y, language_stenv_t *e)
{
    e->Runions.depth = 0;
    e->Runions.more = 0;
    e->Runions.used = 0;
    language_value_t **is;
    LANGUAGE_GC_PUSHARGS(is, 2);
    language_savedenv_t se, me;
    save_env(e, &se, 1);
    int niter = 0, total_iter = 0;
    clean_occurs(e);
    is[0] = intersect(x, y, e, 0); // root
    if (is[0] != language_bottom_type) {
        expand_local_env(e, is[0]);
        niter = merge_env(e, &me, niter);
    }
    restore_env(e, &se, 1);
    while (next_union_state(e, 1)) {
        if (e->emptiness_only && is[0] != language_bottom_type)
            break;
        e->Runions.depth = 0;
        e->Runions.more = 0;

        clean_occurs(e);
        is[1] = intersect(x, y, e, 0);
        if (is[1] != language_bottom_type) {
            expand_local_env(e, is[1]);
            niter = merge_env(e, &me, niter);
        }
        restore_env(e, &se, 1);
        if (is[0] == language_bottom_type)
            is[0] = is[1];
        else if (is[1] != language_bottom_type) {
            // TODO: the repeated subtype checks in here can get expensive
            is[0] = language_type_union(is, 2);
        }
        total_iter++;
        if (niter > 4 || total_iter > 400000) {
            is[0] = y;
            break;
        }
    }
    if (niter) {
        final_merge_env(e, &me, &se);
        restore_env(e, &me, 1);
        free_env(&me);
    }
    free_env(&se);
    LANGUAGE_GC_POP();
    return is[0];
}

// type intersection entry points

static language_value_t *intersect_types(language_value_t *x, language_value_t *y, int emptiness_only)
{
    language_stenv_t e;
    if (obviously_disjoint(x, y, 0))
        return language_bottom_type;
    if (language_is_dispatch_tupletype(x) || language_is_dispatch_tupletype(y)) {
        if (language_subtype(x, y))
            return x;
        else if (language_subtype(y, x))
            return y;
        else
            return language_bottom_type;
    }
    init_stenv(&e, NULL, 0);
    e.intersection = e.ignore_free = 1;
    e.emptiness_only = emptiness_only;
    return intersect_all(x, y, &e);
}

LANGUAGE_DLLEXPORT language_value_t *language_intersect_types(language_value_t *x, language_value_t *y)
{
    return intersect_types(x, y, 0);
}

// TODO: this can probably be done more efficiently
LANGUAGE_DLLEXPORT int language_has_empty_intersection(language_value_t *x, language_value_t *y)
{
    return intersect_types(x, y, 1) == language_bottom_type;
}

// return a SimpleVector of all vars from UnionAlls wrapping a given type
language_svec_t *language_outer_unionall_vars(language_value_t *u)
{
    int ntvars = language_subtype_env_size((language_value_t*)u);
    language_svec_t *vec = language_alloc_svec_uninit(ntvars);
    language_unionall_t *ua = (language_unionall_t*)u;
    int i;
    for (i = 0; i < ntvars; i++) {
        assert(language_is_unionall(ua));
        language_svecset(vec, i, ua->var);
        ua = (language_unionall_t*)ua->body;
    }
    return vec;
}

// For (possibly unions or unionalls of) tuples `a` and `b`, return the tuple of
// pointwise unions. Note that this may in general be wider than `Union{a,b}`.
// If `a` and `b` are not (non va-)tuples of equal length (or unions or unionalls
// of such), return NULL.
static language_value_t *switch_union_tuple(language_value_t *a, language_value_t *b)
{
    if (language_is_unionall(a)) {
        language_unionall_t *ua = (language_unionall_t*)a;
        if (language_is_unionall(b)) {
            language_unionall_t *ub = (language_unionall_t*)b;
            if (ub->var->lb == ua->var->lb && ub->var->ub == ua->var->ub) {
                language_value_t *ub2 = language_instantiate_unionall(ub, (language_value_t*)ua->var);
                language_value_t *ans = NULL;
                LANGUAGE_GC_PUSH2(&ub2, &ans);
                ans = switch_union_tuple(ua->body, ub2);
                if (ans != NULL)
                    ans = language_type_unionall(ua->var, ans);
                LANGUAGE_GC_POP();
                return ans;
            }
        }
        language_value_t *ans = switch_union_tuple(ua->body, b);
        if (ans == NULL)
            return NULL;
        LANGUAGE_GC_PUSH1(&ans);
        ans = language_type_unionall(ua->var, ans);
        LANGUAGE_GC_POP();
        return ans;
    }
    if (language_is_unionall(b)) {
        language_value_t *ans = switch_union_tuple(a, ((language_unionall_t*)b)->body);
        if (ans == NULL)
            return NULL;
        LANGUAGE_GC_PUSH1(&ans);
        ans = language_type_unionall(((language_unionall_t*)b)->var, ans);
        LANGUAGE_GC_POP();
        return ans;
    }
    if (language_is_uniontype(a)) {
        a = switch_union_tuple(((language_uniontype_t*)a)->a, ((language_uniontype_t*)a)->b);
        if (a == NULL)
            return NULL;
        LANGUAGE_GC_PUSH1(&a);
        language_value_t *ans = switch_union_tuple(a, b);
        LANGUAGE_GC_POP();
        return ans;
    }
    if (language_is_uniontype(b)) {
        b = switch_union_tuple(((language_uniontype_t*)b)->a, ((language_uniontype_t*)b)->b);
        if (b == NULL)
            return NULL;
        LANGUAGE_GC_PUSH1(&b);
        language_value_t *ans = switch_union_tuple(a, b);
        LANGUAGE_GC_POP();
        return ans;
    }
    if (!language_is_tuple_type(a) || !language_is_tuple_type(b)) {
        return NULL;
    }
    if (language_nparams(a) != language_nparams(b) || language_is_va_tuple((language_datatype_t*)a) ||
            language_is_va_tuple((language_datatype_t*)b)) {
        return NULL;
    }
    language_svec_t *vec = language_alloc_svec(language_nparams(a));
    LANGUAGE_GC_PUSH1(&vec);
    for (int i = 0; i < language_nparams(a); i++) {
        language_value_t *ts[2];
        ts[0] = language_tparam(a, i);
        ts[1] = language_tparam(b, i);
        language_svecset(vec, i, language_type_union(ts, 2));
    }
    language_value_t *ans = language_apply_tuple_type(vec, 1);
    LANGUAGE_GC_POP();
    return ans;
}

// `a` might have a non-empty intersection with some concrete type b even if !(a<:b) and !(b<:a)
// For example a=`Tuple{Type{<:Vector}}` and b=`Tuple{DataType}`
// TODO: this query is partly available memoized as language_type_equality_is_identity
static int might_intersect_concrete(language_value_t *a)
{
    if (language_is_unionall(a))
        a = language_unwrap_unionall(a);
    if (language_is_typevar(a))
        return 1; // (maybe)
    if (language_is_uniontype(a))
        return might_intersect_concrete(((language_uniontype_t*)a)->a) ||
               might_intersect_concrete(((language_uniontype_t*)a)->b);
    if (language_is_vararg(a))
        return might_intersect_concrete(language_unwrap_vararg(a));
    if (language_is_type_type(a))
        return 1;
    if (language_is_datatype(a)) {
        int tpl = language_is_tuple_type(a);
        int i, n = language_nparams(a);
        for (i = 0; i < n; i++) {
            language_value_t *p = language_tparam(a, i);
            if (language_is_typevar(p))
                return 1;
            if (tpl && p == language_bottom_type)
                return 1;
            if (tpl && might_intersect_concrete(p))
                return 1;
        }
    }
    return 0;
}

// sets *issubty to 1 iff `a` is a subtype of `b`
language_value_t *language_type_intersection_env_s(language_value_t *a, language_value_t *b, language_svec_t **penv, int *issubty)
{
    if (issubty) *issubty = 0;
    if (obviously_disjoint(a, b, 0)) {
        if (issubty && a == language_bottom_type) *issubty = 1;
        return language_bottom_type;
    }
    int szb = language_subtype_env_size(b);
    int sz = 0, i = 0;
    language_value_t **env, **ans;
    LANGUAGE_GC_PUSHARGS(env, szb+1);
    ans = &env[szb];
    *ans = language_bottom_type;
    int lta = language_is_concrete_type(a);
    int ltb = language_is_concrete_type(b);
    if (language_subtype_env(a, b, env, szb)) {
        *ans = a; sz = szb;
        if (issubty) *issubty = 1;
    }
    // else if (lta && ltb) { // !language_type_equality_is_identity known in this case because obviously_disjoint returned false
    //     goto bot;
    // }
    else if (language_subtype(b, a)) {
        *ans = b;
    }
    else {
        // TODO: these tests could probably be ordered better with above
        if (lta && !might_intersect_concrete(b))
            goto bot;
        if (ltb && !might_intersect_concrete(a))
            goto bot;
        language_stenv_t e;
        init_stenv(&e, NULL, 0);
        e.intersection = e.ignore_free = 1;
        e.envout = env;
        if (szb)
            memset(env, 0, szb*sizeof(void*));
        e.envsz = szb;
        *ans = intersect_all(a, b, &e);
        if (*ans == language_bottom_type) goto bot;
        // TODO: code dealing with method signatures is not able to handle unions, so if
        // `a` and `b` are both tuples, we need to be careful and may not return a union,
        // even if `intersect` produced one
        int env_from_subtype = 1;
        if (language_is_tuple_type(language_unwrap_unionall(a)) && language_is_tuple_type(language_unwrap_unionall(b)) &&
            !language_is_datatype(language_unwrap_unionall(*ans))) {
            language_value_t *ans_unwrapped = language_unwrap_unionall(*ans);
            LANGUAGE_GC_PUSH1(&ans_unwrapped);
            if (language_is_uniontype(ans_unwrapped)) {
                ans_unwrapped = switch_union_tuple(((language_uniontype_t*)ans_unwrapped)->a, ((language_uniontype_t*)ans_unwrapped)->b);
                if (ans_unwrapped != NULL) {
                    *ans = language_rewrap_unionall_(ans_unwrapped, *ans);
                }
            }
            LANGUAGE_GC_POP();
            if (!language_is_datatype(language_unwrap_unionall(*ans))) {
                *ans = b;
                env_from_subtype = 0;
            }
        }
        if (env_from_subtype) {
            sz = szb;
            // TODO: compute better `env` directly during intersection.
            // for now, we attempt to compute env by using subtype on the intersection result
            if (szb > 0 && !language_types_equal(b, (language_value_t*)language_type_type)) {
                if (!language_subtype_env(*ans, b, env, szb)) {
                    sz = 0;
                }
            }
        }
    }
    if (sz == 0 && szb > 0) {
        language_unionall_t *ub = (language_unionall_t*)b;
        while (language_is_unionall(ub)) {
            env[i++] = (language_value_t*)ub->var;
            ub = (language_unionall_t*)ub->body;
        }
        sz = szb;
    }
    if (penv) {
        language_svec_t *e = language_alloc_svec(sz);
        for (i = 0; i < sz; i++) {
            assert(env[i]);
            language_svecset(e, i, env[i]);
        }
        *penv = e;
    }
 bot:
    LANGUAGE_GC_POP();
    return *ans;
}

language_value_t *language_type_intersection_env(language_value_t *a, language_value_t *b, language_svec_t **penv)
{
    return language_type_intersection_env_s(a, b, penv, NULL);
}

LANGUAGE_DLLEXPORT language_value_t *language_type_intersection(language_value_t *a, language_value_t *b)
{
    return language_type_intersection_env(a, b, NULL);
}

LANGUAGE_DLLEXPORT language_svec_t *language_type_intersection_with_env(language_value_t *a, language_value_t *b)
{
    language_svec_t *env = language_emptysvec;
    language_value_t *ti = NULL;
    LANGUAGE_GC_PUSH2(&env, &ti);
    ti = language_type_intersection_env(a, b, &env);
    language_svec_t *pair = language_svec2(ti, env);
    LANGUAGE_GC_POP();
    return pair;
}

int language_subtype_matching(language_value_t *a, language_value_t *b, language_svec_t **penv)
{
    int szb = penv ? language_subtype_env_size(b) : 0;
    if (szb == 0)
        return language_subtype_env(a, b, NULL, szb);

    language_value_t **env;
    LANGUAGE_GC_PUSHARGS(env, szb);
    int sub = language_subtype_env(a, b, env, szb);
    if (sub) {
        // copy env to svec for return
        int i = 0;
        language_svec_t *e = language_alloc_svec(szb);
        for (i = 0; i < szb; i++) {
            assert(env[i]);
            language_svecset(e, i, env[i]);
        }
        *penv = e;
    }
    LANGUAGE_GC_POP();
    return sub;
}

// type utils
static void check_diagonal(language_value_t *t, language_varbinding_t *troot, int param)
{
    if (language_is_uniontype(t)) {
        int i, len = 0;
        language_varbinding_t *v;
        for (v = troot; v != NULL; v = v->prev)
            len++;
        int8_t *occurs = (int8_t *)alloca(len);
        for (v = troot, i = 0; v != NULL; v = v->prev, i++)
            occurs[i] = v->occurs_inv | (v->occurs_cov << 2);
        check_diagonal(((language_uniontype_t *)t)->a, troot, param);
        for (v = troot, i = 0; v != NULL; v = v->prev, i++) {
            int8_t occurs_inv = occurs[i] & 3;
            int8_t occurs_cov = occurs[i] >> 2;
            occurs[i] = v->occurs_inv | (v->occurs_cov << 2);
            v->occurs_inv = occurs_inv;
            v->occurs_cov = occurs_cov;
        }
        check_diagonal(((language_uniontype_t *)t)->b, troot, param);
        for (v = troot, i = 0; v != NULL; v = v->prev, i++) {
            if (v->occurs_inv < (occurs[i] & 3))
                v->occurs_inv = occurs[i] & 3;
            if (v->occurs_cov < (occurs[i] >> 2))
                v->occurs_cov = occurs[i] >> 2;
        }
    }
    else if (language_is_unionall(t)) {
        assert(troot != NULL);
        language_varbinding_t *v1 = troot, *v2 = troot->prev;
        while (v2 != NULL) {
            if (v2->var == ((language_unionall_t *)t)->var) {
                v1->prev = v2->prev;
                break;
            }
            v1 = v2;
            v2 = v2->prev;
        }
        check_diagonal(((language_unionall_t *)t)->body, troot, param);
        v1->prev = v2;
    }
    else if (language_is_datatype(t)) {
        int nparam = language_is_tuple_type(t) ? 1 : 2;
        if (nparam < param) nparam = param;
        for (size_t i = 0; i < language_nparams(t); i++) {
            check_diagonal(language_tparam(t, i), troot, nparam);
        }
    }
    else if (language_is_vararg(t)) {
        language_value_t *T = language_unwrap_vararg(t);
        language_value_t *N = language_unwrap_vararg_num(t);
        int n = (N && language_is_long(N)) ? language_unbox_long(N) : 2;
        if (T && n > 0) check_diagonal(T, troot, param);
        if (T && n > 1) check_diagonal(T, troot, param);
        if (N)          check_diagonal(N, troot, 2);
    }
    else if (language_is_typevar(t)) {
        language_varbinding_t *v = troot;
        for (; v != NULL; v = v->prev) {
            if (v->var == (language_tvar_t *)t) {
                if (param == 1 && v->occurs_cov < 2) v->occurs_cov++;
                if (param == 2 && v->occurs_inv < 2) v->occurs_inv++;
                break;
            }
        }
        if (v == NULL)
            check_diagonal(((language_tvar_t *)t)->ub, troot, 0);
    }
}

static language_value_t *insert_nondiagonal(language_value_t *type, language_varbinding_t *troot, int widen2ub)
{
    if (language_is_typevar(type)) {
        int concretekind = widen2ub > 1 ? 0 : 1;
        language_varbinding_t *v = troot;
        for (; v != NULL; v = v->prev) {
            if (v->occurs_inv == 0 &&
                v->occurs_cov > concretekind &&
                v->var == (language_tvar_t *)type)
                break;
        }
        if (v != NULL) {
            if (widen2ub) {
                type = insert_nondiagonal(((language_tvar_t *)type)->ub, troot, 2);
            }
            else {
                // we must replace each covariant occurrence of newvar with a different newvar2<:newvar (diagonal rule)
                if (v->innervars == NULL)
                    v->innervars = language_alloc_array_1d(language_array_any_type, 0);
                language_value_t *newvar = NULL, *lb = v->var->lb, *ub = (language_value_t *)v->var;
                language_array_t *innervars = v->innervars;
                LANGUAGE_GC_PUSH4(&newvar, &lb, &ub, &innervars);
                newvar = (language_value_t *)language_new_typevar(v->var->name, lb, ub);
                language_array_ptr_1d_push(innervars, newvar);
                LANGUAGE_GC_POP();
                type = newvar;
            }
        }
    }
    else if (language_is_unionall(type)) {
        language_value_t *body = ((language_unionall_t*)type)->body;
        language_tvar_t *var = ((language_unionall_t*)type)->var;
        language_varbinding_t *v = troot;
        for (; v != NULL; v = v->prev) {
            if (v->var == var)
                break;
        }
        if (v) v->var = NULL; // Temporarily remove `type->var` from binding list.
        language_value_t *newbody = insert_nondiagonal(body, troot, widen2ub);
        if (v) v->var = var; // And restore it after inner insertation.
        language_value_t *newvar = NULL;
        LANGUAGE_GC_PUSH3(&newbody, &newvar, &type);
        if (body == newbody || language_has_typevar(newbody, var)) {
            if (body != newbody)
                type = language_new_struct(language_unionall_type, var, newbody);
            // n.b. we do not widen lb, since that would be the wrong direction
            newvar = insert_nondiagonal(var->ub, troot, widen2ub);
            if (newvar != var->ub) {
                newvar = (language_value_t*)language_new_typevar(var->name, var->lb, newvar);
                newbody = language_apply_type1(type, newvar);
                type = language_type_unionall((language_tvar_t*)newvar, newbody);
            }
        }
        LANGUAGE_GC_POP();
    }
    else if (language_is_uniontype(type)) {
        language_value_t *a = ((language_uniontype_t*)type)->a;
        language_value_t *b = ((language_uniontype_t*)type)->b;
        language_value_t *newa = NULL;
        language_value_t *newb = NULL;
        LANGUAGE_GC_PUSH2(&newa, &newb);
        newa = insert_nondiagonal(a, troot, widen2ub);
        newb = insert_nondiagonal(b, troot, widen2ub);
        if (newa != a || newb != b)
            type = simple_union(newa, newb);
        LANGUAGE_GC_POP();
    }
    else if (language_is_vararg(type)) {
        // As for Vararg we'd better widen it's var to ub as otherwise they are still diagonal
        language_value_t *t = language_unwrap_vararg(type);
        language_value_t *n = language_unwrap_vararg_num(type);
        if (widen2ub == 0)
            widen2ub = !(n && language_is_long(n)) || language_unbox_long(n) > 1;
        language_value_t *newt;
        LANGUAGE_GC_PUSH2(&newt, &n);
        newt = insert_nondiagonal(t, troot, widen2ub);
        if (t != newt)
            type = (language_value_t *)language_wrap_vararg(newt, n, 0, 0);
        LANGUAGE_GC_POP();
    }
    else if (language_is_datatype(type)) {
        if (language_is_tuple_type(type)) {
            language_svec_t *newparams = NULL;
            language_value_t *newelt = NULL;
            LANGUAGE_GC_PUSH2(&newparams, &newelt);
            for (size_t i = 0; i < language_nparams(type); i++) {
                language_value_t *elt = language_tparam(type, i);
                newelt = insert_nondiagonal(elt, troot, widen2ub);
                if (elt != newelt) {
                    if (!newparams)
                        newparams = language_svec_copy(((language_datatype_t*)type)->parameters);
                    language_svecset(newparams, i, newelt);
                }
            }
            if (newparams)
                type = (language_value_t*)language_apply_tuple_type(newparams, 1);
            LANGUAGE_GC_POP();
        }
    }
    return type;
}

static language_value_t *_widen_diagonal(language_value_t *t, language_varbinding_t *troot) {
    check_diagonal(t, troot, 0);
    int any_concrete = 0;
    for (language_varbinding_t *v = troot; v != NULL; v = v->prev)
        any_concrete |= v->occurs_cov > 1 && v->occurs_inv == 0;
    if (!any_concrete)
        return t; // no diagonal
    return insert_nondiagonal(t, troot, 0);
}

static language_value_t *widen_diagonal(language_value_t *t, language_unionall_t *u, language_varbinding_t *troot)
{
    language_varbinding_t vb = { u->var, NULL, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, troot };
    language_value_t *nt;
    LANGUAGE_GC_PUSH2(&vb.innervars, &nt);
    if (language_is_unionall(u->body))
        nt = widen_diagonal(t, (language_unionall_t *)u->body, &vb);
    else
        nt = _widen_diagonal(t, &vb);
    if (vb.innervars != NULL) {
        for (size_t i = 0; i < language_array_nrows(vb.innervars); i++) {
            language_tvar_t *var = (language_tvar_t*)language_array_ptr_ref(vb.innervars, i);
            nt = language_type_unionall(var, nt);
        }
    }
    LANGUAGE_GC_POP();
    return nt;
}

LANGUAGE_DLLEXPORT language_value_t *language_widen_diagonal(language_value_t *t, language_unionall_t *ua)
{
    return widen_diagonal(t, ua, NULL);
}

// specificity comparison

static int eq_msp(language_value_t *a, language_value_t *b, language_value_t *a0, language_value_t *b0, language_typeenv_t *env)
{
    if (!(language_is_type(a) || language_is_typevar(a)) ||
        !(language_is_type(b) || language_is_typevar(b)))
        return language_egal(a, b);
    if (a == b) // assume the TypeVar env is the same??
        return 1;
    if (language_typeof(a) == language_typeof(b) && language_types_egal(a, b))
        return 1;
    if (obviously_unequal(a, b))
        return 0;
    // the following is an interleaved version of:
    //   return language_type_equal(a, b)
    // where we try to do the fast checks before the expensive ones
    if (language_is_datatype(a) && !language_is_concrete_type(b)) {
        // if one type looks simpler, check it on the right
        // first in order to reject more quickly.
        language_value_t *temp = a;
        a = b;
        b = temp;
    }
    // first check if a <: b has an obvious answer
    int subtype_ab = 2;
    if (b == (language_value_t*)language_any_type || a == language_bottom_type) {
        subtype_ab = 1;
    }
    else if (obvious_subtype(a, b, b0, &subtype_ab)) {
#ifdef NDEBUG
        if (subtype_ab == 0)
            return 0;
#endif
    }
    else {
        subtype_ab = 3;
    }
    // next check if b <: a has an obvious answer
    int subtype_ba = 2;
    if (a == (language_value_t*)language_any_type || b == language_bottom_type) {
        subtype_ba = 1;
    }
    else if (obvious_subtype(b, a, a0, &subtype_ba)) {
#ifdef NDEBUG
        if (subtype_ba == 0)
            return 0;
#endif
    }
    else {
        subtype_ba = 3;
    }
    // finally, do full subtyping for any inconclusive test
    LANGUAGE_GC_PUSH2(&a, &b);
    language_typeenv_t *env2 = env;
    while (env2 != NULL) {
        a = language_type_unionall(env2->var, a);
        b = language_type_unionall(env2->var, b);
        env2 = env2->prev;
    }
    language_stenv_t e;
#ifdef NDEBUG
    if (subtype_ab != 1)
#endif
    {
        init_stenv(&e, NULL, 0);
        int subtype = forall_exists_subtype(a, b, &e, 0);
        assert(subtype_ab == 3 || subtype_ab == subtype || language_has_free_typevars(a) || language_has_free_typevars(b));
#ifndef NDEBUG
        if (subtype_ab != 0 && subtype_ab != 1) // ensures that running in a debugger doesn't change the result
#endif
        subtype_ab = subtype;
#ifdef NDEBUG
        if (subtype_ab == 0) {
            LANGUAGE_GC_POP();
            return 0;
        }
#endif
    }
#ifdef NDEBUG
    if (subtype_ba != 1)
#endif
    {
        init_stenv(&e, NULL, 0);
        int subtype = forall_exists_subtype(b, a, &e, 0);
        assert(subtype_ba == 3 || subtype_ba == subtype || language_has_free_typevars(a) || language_has_free_typevars(b));
#ifndef NDEBUG
        if (subtype_ba != 0 && subtype_ba != 1) // ensures that running in a debugger doesn't change the result
#endif
        subtype_ba = subtype;
    }
    LANGUAGE_GC_POP();
    // all tests successful
    return subtype_ab && subtype_ba;
}

static int sub_msp(language_value_t *x, language_value_t *y, language_value_t *y0, language_typeenv_t *env)
{
    language_stenv_t e;
    if (y == (language_value_t*)language_any_type || x == language_bottom_type)
        return 1;
    if (x == y ||
        (language_typeof(x) == language_typeof(y) &&
         (language_is_unionall(y) || language_is_uniontype(y)) &&
         language_types_egal(x, y))) {
        return 1;
    }
    int obvious_sub = 2;
    if (obvious_subtype(x, y, y0, &obvious_sub)) {
#ifdef NDEBUG
        return obvious_sub;
#endif
    }
    else {
        obvious_sub = 3;
    }
    LANGUAGE_GC_PUSH2(&x, &y);
    while (env != NULL) {
        if (language_is_type(x) || language_is_typevar(x))
            x = language_type_unionall(env->var, x);
        if (language_is_type(y) || language_is_typevar(y))
            y = language_type_unionall(env->var, y);
        env = env->prev;
    }
    init_stenv(&e, NULL, 0);
    int subtype = forall_exists_subtype(x, y, &e, 0);
    assert(obvious_sub == 3 || obvious_sub == subtype || language_has_free_typevars(x) || language_has_free_typevars(y));
#ifndef NDEBUG
    if (obvious_sub == 0 || obvious_sub == 1)
        subtype = obvious_sub; // this ensures that running in a debugger doesn't change the result
#endif
    LANGUAGE_GC_POP();
    return subtype;
}

static int type_morespecific_(language_value_t *a, language_value_t *b, language_value_t *a0, language_value_t *b0, int invariant, language_typeenv_t *env);

static int num_occurs(language_tvar_t *v, language_typeenv_t *env);

static language_value_t *nth_tuple_elt(language_datatype_t *t LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT
{
    size_t len = language_nparams(t);
    if (len == 0)
        return NULL;
    if (i < len-1)
        return language_tparam(t, i);
    language_value_t *last = language_unwrap_unionall(language_tparam(t, len-1));
    if (language_is_vararg(last)) {
        language_value_t *n = language_unwrap_vararg_num(last);
        if (n && language_is_long(n) && i >= len-1+language_unbox_long(n))
            return NULL;
        return language_unwrap_vararg(last);
    }
    if (i == len-1)
        return language_tparam(t, i);
    return NULL;
}

static int tuple_morespecific(language_datatype_t *cdt, language_datatype_t *pdt, language_value_t *c0, language_value_t *p0, int invariant, language_typeenv_t *env)
{
    size_t plen = language_nparams(pdt);
    if (plen == 0) return 0;
    size_t clen = language_nparams(cdt);
    if (clen == 0) return 1;
    int i = 0;
    language_value_t *clast = language_tparam(cdt,clen-1);
    language_vararg_kind_t ckind = language_vararg_kind(clast);
    int cva = ckind > LANGUAGE_VARARG_INT;
    int pva = language_vararg_kind(language_tparam(pdt,plen-1)) > LANGUAGE_VARARG_INT;
    int cdiag = 0, pdiag = 0;
    int some_morespecific = 0;
    while (1) {
        if (cva && pva && i >= clen && i >= plen)
            break;

        language_value_t *ce = nth_tuple_elt(cdt, i);
        language_value_t *pe = nth_tuple_elt(pdt, i);

        if (ce == NULL) {
            if (pe == NULL) break;
            return 1;
        }
        if (pe == NULL) {
            if (!cva && !some_morespecific)
                return 0;
            break;
        }

        if (type_morespecific_(pe, ce, p0, c0, invariant, env)) {
            assert(!type_morespecific_(ce, pe, c0, p0, invariant, env));
            return 0;
        }

        if (!cdiag && language_is_typevar(ce) && num_occurs((language_tvar_t*)ce,env) > 1)
            cdiag = 1;
        if (!pdiag && language_is_typevar(pe) && num_occurs((language_tvar_t*)pe,env) > 1)
            pdiag = 1;

        // in Tuple{a,b...} and Tuple{c,d...} allow b and d to be disjoint
        if (cva && pva && i >= clen-1 && i >= plen-1 && (some_morespecific || (cdiag && !pdiag)))
            return 1;

        int cms = type_morespecific_(ce, pe, c0, p0, invariant, env);

        if (!cms && !sub_msp(ce, pe, p0, env)) {
            /*
              A bound vararg tuple can be more specific despite disjoint elements in order to
              preserve transitivity. For example in
              A = Tuple{Array{T,N}, Vararg{Int,N}} where {T,N}
              B = Tuple{Array, Int}
              C = Tuple{AbstractArray, Int, Array}
              we need A < B < C and A < C.
            */
            return some_morespecific && cva && ckind == LANGUAGE_VARARG_BOUND && num_occurs((language_tvar_t*)language_unwrap_vararg_num(clast), env) > 1;
        }

        // Tuple{..., T} not more specific than Tuple{..., Vararg{S}} if S is diagonal
        if (!cms && i == clen-1 && clen == plen && !cva && pva && eq_msp(ce, pe, c0, p0, env) &&
            language_is_typevar(ce) && language_is_typevar(pe) && !cdiag && pdiag)
            return 0;

        if (cms) some_morespecific = 1;
        i++;
    }
    if (cva && pva && clen > plen && (!pdiag || cdiag))
        return 1;
    if (cva && !pva && !some_morespecific)
        return 0;
    return some_morespecific || (cdiag && !pdiag);
}

static size_t tuple_full_length(language_value_t *t)
{
    size_t n = language_nparams(t);
    if (n == 0) return 0;
    language_value_t *last = language_unwrap_unionall(language_tparam(t,n-1));
    if (language_is_vararg(last)) {
        language_value_t *N = language_unwrap_vararg_num(last);
        if (language_is_long(N))
            n += language_unbox_long(N)-1;
    }
    return n;
}

// Called when a is a bound-vararg and b is not a vararg. Sets the vararg length
// in a to match b, as long as this makes some earlier argument more specific.
static int args_morespecific_fix1(language_value_t *a, language_value_t *b, language_value_t *a0, language_value_t *b0, int swap, language_typeenv_t *env)
{
    size_t n = language_nparams(a);
    int taillen = tuple_full_length(b)-n+1;
    if (taillen <= 0)
        return -1;
    assert(language_is_va_tuple((language_datatype_t*)a));
    language_datatype_t *new_a = NULL;
    language_value_t *e[2] = { language_unwrap_vararg_num(language_unwrap_unionall(language_tparam(a, n-1))), language_box_long(taillen) };
    LANGUAGE_GC_PUSH2(&new_a, &e[1]);
    new_a = (language_datatype_t*)language_instantiate_type_with((language_value_t*)a, e, 1);
    int changed = 0;
    for (size_t i = 0; i < n-1; i++) {
        if (language_tparam(a, i) != language_tparam(new_a, i)) {
            changed = 1;
            break;
        }
    }
    int ret = -1;
    if (changed) {
        if (eq_msp(b, (language_value_t*)new_a, b0, a0, env))
            ret = swap;
        else if (swap)
            ret = type_morespecific_(b, (language_value_t*)new_a, b0, a0, 0, env);
        else
            ret = type_morespecific_((language_value_t*)new_a, b, a0, b0, 0, env);
    }
    LANGUAGE_GC_POP();
    return ret;
}

static int count_occurs(language_value_t *t, language_tvar_t *v)
{
    if (t == (language_value_t*)v)
        return 1;
    if (language_is_uniontype(t)) {
        int a = count_occurs(((language_uniontype_t*)t)->a, v);
        int b = count_occurs(((language_uniontype_t*)t)->b, v);
        return a > b ? a : b;
    }
    if (language_is_unionall(t)) {
        if (((language_unionall_t*)t)->var == v)
            return 0;
        return count_occurs(((language_unionall_t*)t)->body, v);
    }
    if (language_is_vararg(t)) {
        language_vararg_t *vm = (language_vararg_t*)t;
        if (vm->T) {
            return count_occurs(vm->T, v) + (vm->N ? count_occurs(vm->N, v) : 0);
        }
    }
    if (language_is_datatype(t)) {
        int i, c=0;
        for(i=0; i < language_nparams(t); i++)
            c += count_occurs(language_tparam(t,i), v);
        return c;
    }
    return 0;
}

static int num_occurs(language_tvar_t *v, language_typeenv_t *env)
{
    while (env != NULL) {
        if (env->var == v)
            return (int)(ssize_t)env->val;
        env = env->prev;
    }
    return 0;
}

int tuple_cmp_typeofbottom(language_datatype_t *a, language_datatype_t *b)
{
    size_t i, la = language_nparams(a), lb = language_nparams(b);
    for (i = 0; i < la || i < lb; i++) {
        language_value_t *pa = i < la ? language_tparam(a, i) : NULL;
        language_value_t *pb = i < lb ? language_tparam(b, i) : NULL;
        assert(language_typeofbottom_type); // for clang-sa
        int xa = pa == (language_value_t*)language_typeofbottom_type || pa == (language_value_t*)language_typeofbottom_type->super;
        int xb = pb == (language_value_t*)language_typeofbottom_type || pb == (language_value_t*)language_typeofbottom_type->super;
        if (xa != xb)
            return xa - xb;
    }
    return 0;
}


#define HANDLE_UNIONALL_A                                               \
    language_unionall_t *ua = (language_unionall_t*)a;                              \
    language_typeenv_t newenv = { ua->var, 0x0, env };                        \
    newenv.val = (language_value_t*)(intptr_t)count_occurs(ua->body, ua->var); \
    return type_morespecific_(ua->body, b, a0, b0, invariant, &newenv)

#define HANDLE_UNIONALL_B                                               \
    language_unionall_t *ub = (language_unionall_t*)b;                              \
    language_typeenv_t newenv = { ub->var, 0x0, env };                        \
    newenv.val = (language_value_t*)(intptr_t)count_occurs(ub->body, ub->var); \
    return type_morespecific_(a, ub->body, a0, b0, invariant, &newenv)

static int type_morespecific_(language_value_t *a, language_value_t *b, language_value_t *a0, language_value_t *b0, int invariant, language_typeenv_t *env)
{
    if (a == b)
        return 0;

    if (language_is_tuple_type(a) && language_is_tuple_type(b)) {
        // compare whether a and b have Type{Union{}} included,
        // which makes them instantly the most specific, regardless of all else,
        // for whichever is left most (the left-to-right behavior here ensures
        // we do not need to keep track of conflicts with multiple methods).
        int msp = tuple_cmp_typeofbottom((language_datatype_t*)a, (language_datatype_t*)b);
        if (msp)
            return msp > 0;
        // When one is LANGUAGE_VARARG_BOUND and the other has fixed length,
        // allow the argument length to fix the tvar
        language_vararg_kind_t akind = language_va_tuple_kind((language_datatype_t*)a);
        language_vararg_kind_t bkind = language_va_tuple_kind((language_datatype_t*)b);
        int ans = -1;
        if (akind == LANGUAGE_VARARG_BOUND && bkind < LANGUAGE_VARARG_BOUND) {
            ans = args_morespecific_fix1(a, b, a0, b0, 0, env);
            if (ans == 1) return 1;
        }
        if (bkind == LANGUAGE_VARARG_BOUND && akind < LANGUAGE_VARARG_BOUND) {
            ans = args_morespecific_fix1(b, a, b0, a0, 1, env);
            if (ans == 0) return 0;
        }
        return tuple_morespecific((language_datatype_t*)a, (language_datatype_t*)b, a0, b0, invariant, env);
    }

    if (!invariant) {
        if ((language_datatype_t*)a == language_any_type) return 0;
        if ((language_datatype_t*)b == language_any_type && !language_is_typevar(a)) return 1;
    }

    if (language_is_uniontype(a)) {
        if (language_is_unionall(b)) {
            HANDLE_UNIONALL_B;
        }
        // Union a is more specific than b if some element of a is more specific than b, but
        // not vice-versa.
        if (sub_msp(b, a, a0, env))
            return 0;
        language_uniontype_t *u = (language_uniontype_t*)a;
        if (type_morespecific_(u->a, b, a0, b0, invariant, env) || type_morespecific_(u->b, b, a0, b0, invariant, env)) {
            if (language_is_uniontype(b)) {
                language_uniontype_t *v = (language_uniontype_t*)b;
                if (type_morespecific_(v->a, a, b0, a0, invariant, env) || type_morespecific_(v->b, a, b0, a0, invariant, env))
                    return 0;
            }
            return 1;
        }
        return 0;
    }

    if (language_is_type_type(a) && !invariant) {
        if (b == (language_value_t*)language_typeofbottom_type)
            return 0;
        language_value_t *tp0a = language_tparam0(a);
        if (language_is_typevar(tp0a)) {
            language_value_t *ub = ((language_tvar_t*)tp0a)->ub;
            if (language_is_kind(b) && !sub_msp((language_value_t*)language_any_type, ub, b0, env))
                return 1;
        }
        else if (tp0a == language_bottom_type) {
            if (sub_msp(b, (language_value_t*)language_type_type, (language_value_t*)language_type_type, env))
                return 1;
        }
        else if (b == (language_value_t*)language_datatype_type || b == (language_value_t*)language_unionall_type ||
                 b == (language_value_t*)language_uniontype_type) {
            return 1;
        }
    }

    if (language_is_uniontype(b)) {
        if (language_is_unionall(a)) {
            HANDLE_UNIONALL_A;
        }
        language_uniontype_t *u = (language_uniontype_t*)b;
        if (type_morespecific_(a, u->a, a0, b0, invariant, env) || type_morespecific_(a, u->b, a0, b0, invariant, env))
            return !type_morespecific_(b, a, b0, a0, invariant, env);
        return 0;
    }

    if (language_is_datatype(a) && language_is_datatype(b)) {
        language_datatype_t *tta = (language_datatype_t*)a, *ttb = (language_datatype_t*)b;
        // Type{Union{}} is more specific than other types, so TypeofBottom must be too
        if (tta == language_typeofbottom_type && (language_is_kind(b) || language_is_type_type(b)))
            return 1;
        int super = 0;
        while (tta != language_any_type) {
            if (tta->name == ttb->name) {
                if (super) {
                    if (tta->name != language_type_typename) return 1;
                    language_value_t *tp0 = language_tparam0(b);
                    if (language_is_typevar(tp0)) {
                        if (sub_msp((language_value_t*)language_any_type, ((language_tvar_t*)tp0)->ub, b0, env))
                            return 1;
                    }
                }
                assert(language_nparams(tta) == language_nparams(ttb));
                int ascore=0, bscore=0, ascore1=0, bscore1=0, adiag=0, bdiag=0;
                for(size_t i=0; i < language_nparams(tta); i++) {
                    language_value_t *apara = language_tparam(tta,i);
                    language_value_t *bpara = language_tparam(ttb,i);
                    int afree = language_has_free_typevars(apara);
                    int bfree = language_has_free_typevars(bpara);
                    if (!afree && !bfree && !language_types_equal(apara, bpara))
                        return 0;
                    if (type_morespecific_(apara, bpara, a0, b0, 1, env) && (language_is_typevar(apara) || !afree || bfree))
                        ascore += 1;
                    else if (type_morespecific_(bpara, apara, b0, a0, 1, env) && (language_is_typevar(bpara) || !bfree || afree))
                        bscore += 1;
                    else if (eq_msp(apara, bpara, a0, b0, env)) {
                        if (!afree && bfree)
                            ascore += 1;
                        else if (afree && !bfree)
                            bscore += 1;
                    }
                    if (language_is_typevar(bpara) && !language_is_typevar(apara) && !language_is_type(apara))
                        ascore1 = 1;
                    else if (language_is_typevar(apara) && !language_is_typevar(bpara) && !language_is_type(bpara))
                        bscore1 = 1;
                    if (!adiag && language_is_typevar(apara)) {
                        for(int j=i+1; j < language_nparams(tta); j++) {
                            if (language_has_typevar(language_tparam(tta,j), (language_tvar_t*)apara)) {
                                adiag = 1; break;
                            }
                        }
                    }
                    if (!bdiag && language_is_typevar(bpara)) {
                        for(int j=i+1; j < language_nparams(ttb); j++) {
                            if (language_has_typevar(language_tparam(ttb,j), (language_tvar_t*)bpara)) {
                                bdiag = 1; break;
                            }
                        }
                    }
                }
                if (ascore1 > bscore1)
                    return 1;
                if (bscore1 > ascore1 || bscore > ascore || bdiag > adiag)
                    return 0;
                return ascore > bscore || adiag > bdiag;
            }
            tta = tta->super; super = 1;
        }
        return 0;
    }

    if (language_is_typevar(a)) {
        if (language_is_typevar(b)) {
            return (( type_morespecific_((language_value_t*)((language_tvar_t*)a)->ub,
                                         (language_value_t*)((language_tvar_t*)b)->ub, a0, b0, 0, env) &&
                     !type_morespecific_((language_value_t*)((language_tvar_t*)a)->lb,
                                         (language_value_t*)((language_tvar_t*)b)->lb, a0, b0, 0, env)) ||
                    ( type_morespecific_((language_value_t*)((language_tvar_t*)b)->lb,
                                         (language_value_t*)((language_tvar_t*)a)->lb, b0, a0, 0, env) &&
                     !type_morespecific_((language_value_t*)((language_tvar_t*)b)->ub,
                                         (language_value_t*)((language_tvar_t*)a)->ub, b0, a0, 0, env)));
        }
        if (!language_is_type(b))
            return 0;
        if (invariant) {
            if (((language_tvar_t*)a)->ub == language_bottom_type)
                return 1;
            if (!language_has_free_typevars(b))
                return 0;
            if (eq_msp(((language_tvar_t*)a)->ub, b, a0, b0, env))
                return num_occurs((language_tvar_t*)a, env) >= 2;
        }
        else {
            // need `{T,T} where T` more specific than `{Any, Any}`
            if (b == (language_value_t*)language_any_type && ((language_tvar_t*)a)->ub == (language_value_t*)language_any_type &&
                num_occurs((language_tvar_t*)a, env) >= 2)
                return 1;
        }
        return type_morespecific_(((language_tvar_t*)a)->ub, b, a0, b0, 0, env);
    }
    if (language_is_typevar(b)) {
        if (!language_is_type(a))
            return 1;
        if (invariant) {
            if (((language_tvar_t*)b)->ub == language_bottom_type)
                return 0;
            if (language_has_free_typevars(a)) {
                if (type_morespecific_(a, ((language_tvar_t*)b)->ub, a0, b0, 0, env))
                    return 1;
                if (eq_msp(a, ((language_tvar_t*)b)->ub, a0, b0, env))
                    return num_occurs((language_tvar_t*)b, env) < 2;
                return 0;
            }
            else {
                if (obviously_disjoint(a, ((language_tvar_t*)b)->ub, 1))
                    return 0;
                if (type_morespecific_(((language_tvar_t*)b)->ub, a, b0, a0, 0, env))
                    return 0;
                return 1;
            }
        }
        return type_morespecific_(a, ((language_tvar_t*)b)->ub, a0, b0, 0, env);
    }

    if (language_is_unionall(a)) {
        HANDLE_UNIONALL_A;
    }
    if (language_is_unionall(b)) {
        HANDLE_UNIONALL_B;
    }

    return 0;
}

LANGUAGE_DLLEXPORT int language_type_morespecific(language_value_t *a, language_value_t *b)
{
    if (obviously_disjoint(a, b, 1))
        return 0;
    if (language_has_free_typevars(a) || language_has_free_typevars(b))
        return 0;
    if (language_subtype(b, a))
        return 0;
    if (language_subtype(a, b))
        return 1;
    return type_morespecific_(a, b, a, b, 0, NULL);
}

LANGUAGE_DLLEXPORT int language_type_morespecific_no_subtype(language_value_t *a, language_value_t *b)
{
    return type_morespecific_(a, b, a, b, 0, NULL);
}

// Equivalent to `language_type_morespecific` of the signatures, except that more recent
// methods are more specific, iff the methods signatures are type-equal
LANGUAGE_DLLEXPORT int language_method_morespecific(language_method_t *ma, language_method_t *mb)
{
    language_value_t *a = (language_value_t*)ma->sig;
    language_value_t *b = (language_value_t*)mb->sig;
    if (obviously_disjoint(a, b, 1))
        return 0;
    if (language_has_free_typevars(a) || language_has_free_typevars(b))
        return 0;
    if (language_subtype(b, a)) {
        if (language_types_equal(a, b))
            return language_atomic_load_relaxed(&ma->primary_world) > language_atomic_load_relaxed(&mb->primary_world);
        return 0;
    }
    if (language_subtype(a, b))
        return 1;
    return type_morespecific_(a, b, a, b, 0, NULL);
}

#ifdef __cplusplus
}
#endif
