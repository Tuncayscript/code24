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

#include "code.h"
#include "language_internal.h"

language_value_t *language_fptr_const_opaque_closure(language_opaque_closure_t *oc, language_value_t **args, size_t nargs)
{
    return oc->captures;
}

language_value_t *language_fptr_const_opaque_closure_typeerror(language_opaque_closure_t *oc, language_value_t **args, size_t nargs)
{
    language_type_error("OpaqueClosure", language_tparam1(language_typeof(oc)), oc->captures);
}

// determine whether `argt` is a valid argument type tuple for the given opaque closure method
LANGUAGE_DLLEXPORT int language_is_valid_oc_argtype(language_tupletype_t *argt, language_method_t *source)
{
    if (!source->isva) {
        if (language_is_va_tuple(argt))
            return 0;
        if (language_nparams(argt)+1 > source->nargs)
            return 0;
    }
    if (language_nparams(argt) + 1 - language_is_va_tuple(argt) < source->nargs - source->isva)
        return 0;
    return 1;
}

static language_opaque_closure_t *new_opaque_closure(language_tupletype_t *argt, language_value_t *rt_lb, language_value_t *rt_ub,
    language_value_t *source_, language_value_t *captures, int do_compile)
{
    if (!language_is_tuple_type((language_value_t*)argt)) {
        language_error("OpaqueClosure argument tuple must be a tuple type");
    }
    LANGUAGE_TYPECHK(new_opaque_closure, type, rt_lb);
    LANGUAGE_TYPECHK(new_opaque_closure, type, rt_ub);
    LANGUAGE_TYPECHK(new_opaque_closure, method, source_);
    language_method_t *source = (language_method_t*)source_;
    if (!source->isva) {
        if (language_is_va_tuple(argt))
            language_error("Argument type tuple is vararg but method is not");
        if (language_nparams(argt)+1 > source->nargs)
            language_error("Argument type tuple has too many required arguments for method");
    }
    if (language_nparams(argt) + 1 - language_is_va_tuple(argt) < source->nargs - source->isva)
        language_error("Argument type tuple has too few required arguments for method");
    language_value_t *sigtype = NULL;
    language_value_t *selected_rt = rt_ub;
    LANGUAGE_GC_PUSH2(&sigtype, &selected_rt);
    sigtype = language_argtype_with_function(captures, (language_value_t*)argt);

    language_method_instance_t *mi = language_specializations_get_linfo(source, sigtype, language_emptysvec);
    language_task_t *ct = language_current_task;
    size_t world = ct->world_age;
    language_code_instance_t *ci = NULL;
    if (do_compile) {
        ci = language_compile_method_internal(mi, world);
    }

    language_fptr_args_t invoke = (language_fptr_args_t)language_interpret_opaque_closure;
    void *specptr = NULL;

    if (ci) {
        invoke = (language_fptr_args_t)language_atomic_load_relaxed(&ci->invoke);
        specptr = language_atomic_load_relaxed(&ci->specptr.fptr);

        selected_rt = ci->rettype;
        // If we're not allowed to generate a specsig with this, rt, fall
        // back to the invoke wrapper. We could instead generate a specsig->specsig
        // wrapper, but lets leave that for later.
        if (!language_subtype(rt_lb, selected_rt)) {
            // TODO: It would be better to try to get a specialization with the
            // correct rt check here (or we could codegen a wrapper).
            specptr = NULL; invoke = (language_fptr_args_t)language_interpret_opaque_closure;
            language_value_t *ts[2] = {rt_lb, (language_value_t*)ci->rettype};
            selected_rt = language_type_union(ts, 2);
        }
        if (!language_subtype(ci->rettype, rt_ub)) {
            // TODO: It would be better to try to get a specialization with the
            // correct rt check here (or we could codegen a wrapper).
            specptr = NULL; invoke = (language_fptr_args_t)language_interpret_opaque_closure;
            selected_rt = language_type_intersection(rt_ub, selected_rt);
        }

        if (invoke == (language_fptr_args_t) language_fptr_interpret_call) {
            invoke = (language_fptr_args_t)language_interpret_opaque_closure;
        }
        else if (invoke == (language_fptr_args_t)language_fptr_args && specptr) {
            invoke = (language_fptr_args_t)specptr;
        }
        else if (invoke == (language_fptr_args_t)language_fptr_const_return) {
            invoke = language_isa(ci->rettype_const, selected_rt) ?
                (language_fptr_args_t)language_fptr_const_opaque_closure :
                (language_fptr_args_t)language_fptr_const_opaque_closure_typeerror;
            captures = ci->rettype_const;
        }
    }

    language_value_t *oc_type LANGUAGE_ALWAYS_LEAFTYPE = language_apply_type2((language_value_t*)language_opaque_closure_type, (language_value_t*)argt, selected_rt);
    LANGUAGE_GC_PROMISE_ROOTED(oc_type);

    if (!specptr) {
        sigtype = language_argtype_with_function_type((language_value_t*)oc_type, (language_value_t*)argt);
        language_method_instance_t *mi_generic = language_specializations_get_linfo(language_opaque_closure_method, sigtype, language_emptysvec);

        // OC wrapper methods are not world dependent
        ci = language_get_method_inferred(mi_generic, selected_rt, 1, ~(size_t)0, NULL);
        if (!language_atomic_load_acquire(&ci->invoke))
            language_compile_codeinst(ci);
        specptr = language_atomic_load_relaxed(&ci->specptr.fptr);
    }
    language_opaque_closure_t *oc = (language_opaque_closure_t*)language_gc_alloc(ct->ptls, sizeof(language_opaque_closure_t), oc_type);
    oc->source = source;
    oc->captures = captures;
    oc->world = world;
    oc->invoke = invoke;
    oc->specptr = specptr;

    LANGUAGE_GC_POP();
    return oc;
}

language_opaque_closure_t *language_new_opaque_closure(language_tupletype_t *argt, language_value_t *rt_lb, language_value_t *rt_ub,
    language_value_t *source_, language_value_t **env, size_t nenv, int do_compile)
{
    language_value_t *captures = language_f_tuple(NULL, env, nenv);
    LANGUAGE_GC_PUSH1(&captures);
    language_opaque_closure_t *oc = new_opaque_closure(argt, rt_lb, rt_ub, source_, captures, do_compile);
    LANGUAGE_GC_POP();
    return oc;
}

LANGUAGE_DLLEXPORT language_opaque_closure_t *language_new_opaque_closure_from_code_info(language_tupletype_t *argt, language_value_t *rt_lb, language_value_t *rt_ub,
    language_module_t *mod, language_code_info_t *ci, int lineno, language_value_t *file, int nargs, int isva, language_value_t *env, int do_compile, int isinferred)
{
    language_value_t *root = NULL, *sigtype = NULL;
    language_code_instance_t *inst = NULL;
    LANGUAGE_GC_PUSH3(&root, &sigtype, &inst);
    root = language_box_long(lineno);
    root = language_new_struct(language_linenumbernode_type, root, file);
    language_method_t *meth = language_make_opaque_closure_method(mod, language_nothing, nargs, root, ci, isva, isinferred);
    root = (language_value_t*)meth;
    size_t world = language_current_task->world_age;
    // these are only legal in the current world since they are not in any tables
    language_atomic_store_release(&meth->primary_world, world);
    language_atomic_store_release(&meth->deleted_world, world);

    if (isinferred) {
        sigtype = language_argtype_with_function(env, (language_value_t*)argt);
        language_method_instance_t *mi = language_specializations_get_linfo((language_method_t*)root, sigtype, language_emptysvec);
        inst = language_new_codeinst(mi, language_nothing, rt_ub, (language_value_t*)language_any_type, NULL, (language_value_t*)ci,
            0, world, world, 0, 0, language_nothing, 0, ci->debuginfo);
        language_mi_cache_insert(mi, inst);
    }

    language_opaque_closure_t *oc = new_opaque_closure(argt, rt_lb, rt_ub, root, env, do_compile);
    LANGUAGE_GC_POP();
    return oc;
}

LANGUAGE_CALLABLE(language_new_opaque_closure_jlcall)
{
    if (nargs < 4)
        language_error("new_opaque_closure: Not enough arguments");
    return (language_value_t*)language_new_opaque_closure((language_tupletype_t*)args[0],
        args[1], args[2], args[3], &args[4], nargs-4, 1);
}

// check whether the specified number of arguments is compatible with the
// specified number of parameters of the tuple type
int language_tupletype_length_compat(language_value_t *v, size_t nargs)
{
    v = language_unwrap_unionall(v);
    assert(language_is_tuple_type(v));
    size_t nparams = language_nparams(v);
    if (nparams == 0)
        return nargs == 0;
    language_value_t *va = language_tparam(v,nparams-1);
    if (language_is_vararg(va)) {
        language_value_t *len = language_unwrap_vararg_num(va);
        if (len &&language_is_long(len))
            return nargs == nparams - 1 + language_unbox_long(len);
        return nargs >= nparams - 1;
    }
    return nparams == nargs;
}

LANGUAGE_CALLABLE(language_f_opaque_closure_call)
{
    language_opaque_closure_t* oc = (language_opaque_closure_t*)F;
    language_value_t *argt = language_tparam0(language_typeof(oc));
    if (!language_tupletype_length_compat(argt, nargs))
        language_method_error(F, args, nargs + 1, oc->world);
    argt = language_unwrap_unionall(argt);
    assert(language_is_datatype(argt));
    language_svec_t *types = language_get_fieldtypes((language_datatype_t*)argt);
    size_t ntypes = language_svec_len(types);
    for (int i = 0; i < nargs; ++i) {
        language_value_t *typ = i >= ntypes ? language_svecref(types, ntypes-1) : language_svecref(types, i);
        if (language_is_vararg(typ))
            typ = language_unwrap_vararg(typ);
        language_typeassert(args[i], typ);
    }
    return oc->invoke(F, args, nargs);
}
