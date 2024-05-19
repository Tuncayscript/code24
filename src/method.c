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
  Defining and adding methods
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

extern language_value_t *language_builtin_getfield;
extern language_value_t *language_builtin_tuple;
language_methtable_t *language_kwcall_mt;
language_method_t *language_opaque_closure_method;

static void check_c_types(const char *where, language_value_t *rt, language_value_t *at)
{
    if (language_is_svec(rt))
        language_errorf("%s: missing return type", where);
    LANGUAGE_TYPECHKS(where, type, rt);
    if (!language_type_mappable_to_c(rt))
        language_errorf("%s: return type doesn't correspond to a C type", where);
    LANGUAGE_TYPECHKS(where, simplevector, at);
    int i, l = language_svec_len(at);
    for (i = 0; i < l; i++) {
        language_value_t *ati = language_svecref(at, i);
        if (language_is_vararg(ati))
            language_errorf("%s: Vararg not allowed for argument list", where);
        LANGUAGE_TYPECHKS(where, type, ati);
        if (!language_type_mappable_to_c(ati))
            language_errorf("%s: argument %d type doesn't correspond to a C type", where, i + 1);
    }
}

// Resolve references to non-locally-defined variables to become references to global
// variables in `module` (unless the rvalue is one of the type parameters in `sparam_vals`).
static language_value_t *resolve_globals(language_value_t *expr, language_module_t *module, language_svec_t *sparam_vals,
                                   int binding_effects, int eager_resolve)
{
    if (language_is_symbol(expr)) {
        if (module == NULL)
            return expr;
        return language_module_globalref(module, (language_sym_t*)expr);
    }
    else if (language_is_returnnode(expr)) {
        language_value_t *retval = language_returnnode_value(expr);
        if (retval) {
            language_value_t *val = resolve_globals(retval, module, sparam_vals, binding_effects, eager_resolve);
            if (val != retval) {
                LANGUAGE_GC_PUSH1(&val);
                expr = language_new_struct(language_returnnode_type, val);
                LANGUAGE_GC_POP();
            }
        }
        return expr;
    }
    else if (language_is_enternode(expr)) {
        language_value_t *scope = language_enternode_scope(expr);
        if (scope) {
            language_value_t *val = resolve_globals(scope, module, sparam_vals, binding_effects, eager_resolve);
            if (val != scope) {
                intptr_t catch_dest = language_enternode_catch_dest(expr);
                LANGUAGE_GC_PUSH1(&val);
                expr = language_new_struct_uninit(language_enternode_type);
                language_enternode_catch_dest(expr) = catch_dest;
                language_enternode_scope(expr) = val;
                LANGUAGE_GC_POP();
            }
        }
        return expr;
    }
    else if (language_is_gotoifnot(expr)) {
        language_value_t *cond = resolve_globals(language_gotoifnot_cond(expr), module, sparam_vals, binding_effects, eager_resolve);
        if (cond != language_gotoifnot_cond(expr)) {
            intptr_t label = language_gotoifnot_label(expr);
            LANGUAGE_GC_PUSH1(&cond);
            expr = language_new_struct_uninit(language_gotoifnot_type);
            set_nth_field(language_gotoifnot_type, expr, 0, cond, 0);
            language_gotoifnot_label(expr) = label;
            LANGUAGE_GC_POP();
        }
        return expr;
    }
    else if (language_is_expr(expr)) {
        language_expr_t *e = (language_expr_t*)expr;
        if (e->head == language_global_sym && binding_effects) {
            // execute the side-effects of "global x" decl immediately:
            // creates uninitialized mutable binding in module for each global
            language_eval_global_expr(module, e, 1);
            expr = language_nothing;
        }
        if (language_is_toplevel_only_expr(expr) || e->head == language_const_sym ||
            e->head == language_coverageeffect_sym || e->head == language_copyast_sym ||
            e->head == language_quote_sym || e->head == language_inert_sym ||
            e->head == language_meta_sym || e->head == language_inbounds_sym ||
            e->head == language_boundscheck_sym || e->head == language_loopinfo_sym ||
            e->head == language_aliasscope_sym || e->head == language_popaliasscope_sym ||
            e->head == language_inline_sym || e->head == language_noinline_sym) {
            // ignore these
        }
        else {
            size_t i = 0, nargs = language_array_nrows(e->args);
            if (e->head == language_opaque_closure_method_sym) {
                if (nargs != 5) {
                    language_error("opaque_closure_method: invalid syntax");
                }
                language_value_t *name = language_exprarg(e, 0);
                language_value_t *oc_nargs = language_exprarg(e, 1);
                int isva = language_exprarg(e, 2) == language_true;
                language_value_t *functionloc = language_exprarg(e, 3);
                language_value_t *ci = language_exprarg(e, 4);
                if (!language_is_code_info(ci)) {
                    language_error("opaque_closure_method: lambda should be a CodeInfo");
                } else if (!language_is_long(oc_nargs)) {
                    language_type_error("opaque_closure_method", (language_value_t*)language_long_type, oc_nargs);
                }
                language_method_t *m = language_make_opaque_closure_method(module, name,
                    language_unbox_long(oc_nargs), functionloc, (language_code_info_t*)ci, isva, /*isinferred*/0);
                return (language_value_t*)m;
            }
            if (e->head == language_cfunction_sym) {
                LANGUAGE_NARGS(cfunction method definition, 5, 5); // (type, func, rt, at, cc)
                language_task_t *ct = language_current_task;
                language_value_t *typ = language_exprarg(e, 0);
                if (!language_is_type(typ))
                    language_error("first parameter to :cfunction must be a type");
                if (typ == (language_value_t*)language_voidpointer_type) {
                    language_value_t *a = language_exprarg(e, 1);
                    LANGUAGE_TYPECHK(cfunction method definition, quotenode, a);
                    *(language_value_t**)a = language_toplevel_eval(module, *(language_value_t**)a);
                    language_gc_wb(a, *(language_value_t**)a);
                }
                language_value_t *rt = language_exprarg(e, 2);
                language_value_t *at = language_exprarg(e, 3);
                if (!language_is_type(rt)) {
                    LANGUAGE_TRY {
                        rt = language_interpret_toplevel_expr_in(module, rt, NULL, sparam_vals);
                    }
                    LANGUAGE_CATCH {
                        if (language_typetagis(language_current_exception(ct), language_errorexception_type))
                            language_error("could not evaluate cfunction return type (it might depend on a local variable)");
                        else
                            language_rethrow();
                    }
                    language_exprargset(e, 2, rt);
                }
                if (!language_is_svec(at)) {
                    LANGUAGE_TRY {
                        at = language_interpret_toplevel_expr_in(module, at, NULL, sparam_vals);
                    }
                    LANGUAGE_CATCH {
                        if (language_typetagis(language_current_exception(ct), language_errorexception_type))
                            language_error("could not evaluate cfunction argument type (it might depend on a local variable)");
                        else
                            language_rethrow();
                    }
                    language_exprargset(e, 3, at);
                }
                check_c_types("cfunction method definition", rt, at);
                LANGUAGE_TYPECHK(cfunction method definition, quotenode, language_exprarg(e, 4));
                LANGUAGE_TYPECHK(cfunction method definition, symbol, *(language_value_t**)language_exprarg(e, 4));
                return expr;
            }
            if (e->head == language_foreigncall_sym) {
                LANGUAGE_NARGSV(ccall method definition, 5); // (fptr, rt, at, nreq, (cc, effects))
                language_task_t *ct = language_current_task;
                language_value_t *rt = language_exprarg(e, 1);
                language_value_t *at = language_exprarg(e, 2);
                if (!language_is_type(rt)) {
                    LANGUAGE_TRY {
                        rt = language_interpret_toplevel_expr_in(module, rt, NULL, sparam_vals);
                    }
                    LANGUAGE_CATCH {
                        if (language_typetagis(language_current_exception(ct), language_errorexception_type))
                            language_error("could not evaluate ccall return type (it might depend on a local variable)");
                        else
                            language_rethrow();
                    }
                    language_exprargset(e, 1, rt);
                }
                if (!language_is_svec(at)) {
                    LANGUAGE_TRY {
                        at = language_interpret_toplevel_expr_in(module, at, NULL, sparam_vals);
                    }
                    LANGUAGE_CATCH {
                        if (language_typetagis(language_current_exception(ct), language_errorexception_type))
                            language_error("could not evaluate ccall argument type (it might depend on a local variable)");
                        else
                            language_rethrow();
                    }
                    language_exprargset(e, 2, at);
                }
                check_c_types("ccall method definition", rt, at);
                LANGUAGE_TYPECHK(ccall method definition, long, language_exprarg(e, 3));
                LANGUAGE_TYPECHK(ccall method definition, quotenode, language_exprarg(e, 4));
                language_value_t *cc = language_quotenode_value(language_exprarg(e, 4));
                if (!language_is_symbol(cc)) {
                    LANGUAGE_TYPECHK(ccall method definition, tuple, cc);
                    if (language_nfields(cc) != 2) {
                        language_error("In ccall calling convention, expected two argument tuple or symbol.");
                    }
                    LANGUAGE_TYPECHK(ccall method definition, symbol, language_get_nth_field(cc, 0));
                    LANGUAGE_TYPECHK(ccall method definition, uint16, language_get_nth_field(cc, 1));
                }
                language_exprargset(e, 0, resolve_globals(language_exprarg(e, 0), module, sparam_vals, binding_effects, 1));
                i++;
            }
            if (e->head == language_method_sym || e->head == language_module_sym || e->head == language_throw_undef_if_not_sym) {
                i++;
            }
            for (; i < nargs; i++) {
                // TODO: this should be making a copy, not mutating the source
                language_exprargset(e, i, resolve_globals(language_exprarg(e, i), module, sparam_vals, binding_effects, eager_resolve));
            }
            if (e->head == language_call_sym && language_expr_nargs(e) == 3 &&
                    language_is_globalref(language_exprarg(e, 0)) &&
                    language_is_globalref(language_exprarg(e, 1)) &&
                    language_is_quotenode(language_exprarg(e, 2))) {
                // replace module_expr.sym with GlobalRef(module, sym)
                // for expressions pattern-matching to `getproperty(module_expr, :sym)` in a top-module
                // (this is expected to help inference performance)
                // TODO: this was broken by linear-IR
                language_value_t *s = language_fieldref(language_exprarg(e, 2), 0);
                language_value_t *me = language_exprarg(e, 1);
                language_value_t *fe = language_exprarg(e, 0);
                language_module_t *fe_mod = language_globalref_mod(fe);
                language_sym_t *fe_sym = language_globalref_name(fe);
                language_module_t *me_mod = language_globalref_mod(me);
                language_sym_t *me_sym = language_globalref_name(me);
                if (fe_mod->istopmod && !strcmp(language_symbol_name(fe_sym), "getproperty") && language_is_symbol(s)) {
                    if (eager_resolve || language_binding_resolved_p(me_mod, me_sym)) {
                        language_binding_t *b = language_get_binding(me_mod, me_sym);
                        if (b && b->constp) {
                            language_value_t *v = language_atomic_load_relaxed(&b->value);
                            if (v && language_is_module(v))
                                return language_module_globalref((language_module_t*)v, (language_sym_t*)s);
                        }
                    }
                }
            }
            if (e->head == language_call_sym && nargs > 0 &&
                    language_is_globalref(language_exprarg(e, 0))) {
                // TODO: this hack should be deleted once llvmcall is fixed
                language_value_t *fe = language_exprarg(e, 0);
                language_module_t *fe_mod = language_globalref_mod(fe);
                language_sym_t *fe_sym = language_globalref_name(fe);
                if (language_binding_resolved_p(fe_mod, fe_sym)) {
                    // look at some known called functions
                    language_binding_t *b = language_get_binding(fe_mod, fe_sym);
                    if (b && b->constp && language_atomic_load_relaxed(&b->value) == language_builtin_tuple) {
                        size_t j;
                        for (j = 1; j < nargs; j++) {
                            if (!language_is_quotenode(language_exprarg(e, j)))
                                break;
                        }
                        if (j == nargs) {
                            language_value_t *val = NULL;
                            LANGUAGE_TRY {
                                val = language_interpret_toplevel_expr_in(module, (language_value_t*)e, NULL, sparam_vals);
                            }
                            LANGUAGE_CATCH {
                                val = NULL; // To make the analyzer happy see #define LANGUAGE_TRY
                            }
                            if (val)
                                return val;
                        }
                    }
                }
            }
        }
    }
    return expr;
}

LANGUAGE_DLLEXPORT void language_resolve_globals_in_ir(language_array_t *stmts, language_module_t *m, language_svec_t *sparam_vals,
                              int binding_effects)
{
    size_t i, l = language_array_nrows(stmts);
    for (i = 0; i < l; i++) {
        language_value_t *stmt = language_array_ptr_ref(stmts, i);
        language_array_ptr_set(stmts, i, resolve_globals(stmt, m, sparam_vals, binding_effects, 0));
    }
}

language_value_t *expr_arg1(language_value_t *expr) {
    language_array_t *args = ((language_expr_t*)expr)->args;
    return language_array_ptr_ref(args, 0);
}

static language_value_t *alloc_edges(arraylist_t *edges_list)
{
    language_value_t *jledges = (language_value_t*)language_alloc_svec(edges_list->len);
    language_value_t *jledges2 = NULL;
    language_value_t *codelocs = NULL;
    LANGUAGE_GC_PUSH3(&jledges, &jledges2, &codelocs);
    size_t i;
    for (i = 0; i < edges_list->len; i++) {
        arraylist_t *edge = (arraylist_t*)edges_list->items[i];
        language_value_t *file = (language_value_t*)edge->items[0];
        int32_t line = 0; // not preserved by lowering (and probably lost even before that)
        arraylist_t *edges_list2 = (arraylist_t*)edge->items[1];
        size_t j, nlocs = (edge->len - 2) / 3;
        codelocs = (language_value_t*)language_alloc_array_1d(language_array_int32_type, nlocs * 3);
        for (j = 0; j < nlocs; j++) {
            language_array_data(codelocs,int32_t)[3 * j + 0] = (intptr_t)edge->items[3 * j + 0 + 2];
            language_array_data(codelocs,int32_t)[3 * j + 1] = (intptr_t)edge->items[3 * j + 1 + 2];
            language_array_data(codelocs,int32_t)[3 * j + 2] = (intptr_t)edge->items[3 * j + 2 + 2];
        }
        codelocs = (language_value_t*)language_compress_codelocs(line, codelocs, nlocs);
        jledges2 = alloc_edges(edges_list2);
        language_value_t *debuginfo = language_new_struct(language_debuginfo_type, file, language_nothing, jledges2, codelocs);
        jledges2 = NULL;
        language_svecset(jledges, i, debuginfo);
        free(edges_list2);
        free(edge);
    }
    LANGUAGE_GC_POP();
    return jledges;
}

static void add_edge(arraylist_t *edges_list, arraylist_t *inlinestack, int32_t *p_to, int32_t *p_pc)
{
    language_value_t *locinfo = (language_value_t*)arraylist_pop(inlinestack);
    language_sym_t *filesym = (language_sym_t*)language_fieldref_noalloc(locinfo, 0);
    int32_t line = language_unbox_int32(language_fieldref(locinfo, 1));
    size_t i;
    arraylist_t *edge = NULL;
    for (i = 0; i < edges_list->len; i++) {
        edge = (arraylist_t*)edges_list->items[i];
        if (edge->items[0] == filesym)
            break;
    }
    if (i == edges_list->len) {
        edge = (arraylist_t*)malloc(sizeof(arraylist_t));
        arraylist_t *edge_list2 = (arraylist_t*)malloc(sizeof(arraylist_t));
        arraylist_new(edge, 0);
        arraylist_new(edge_list2, 0);
        arraylist_push(edge, (void*)filesym);
        arraylist_push(edge, (void*)edge_list2);
        arraylist_push(edges_list, (void*)edge);
    }
    *p_to = i + 1;
    int32_t to = 0, pc = 0;
    if (inlinestack->len) {
        arraylist_t *edge_list2 = (arraylist_t*)edge->items[1];
        add_edge(edge_list2, inlinestack, &to, &pc);
    }
    for (i = 2; i < edge->len; i += 3) {
        if ((intptr_t)edge->items[i + 0] == line &&
            (intptr_t)edge->items[i + 1] == to &&
            (intptr_t)edge->items[i + 2] == pc) {
            break;
        }
    }
    if (i == edge->len) {
        arraylist_push(edge, (void*)(intptr_t)line);
        arraylist_push(edge, (void*)(intptr_t)to);
        arraylist_push(edge, (void*)(intptr_t)pc);
    }
    *p_pc = (i - 2) / 3 + 1;
}

language_debuginfo_t *language_linetable_to_debuginfo(language_array_t *codelocs_any, language_array_t *linetable)
{
    size_t nlocs = language_array_nrows(codelocs_any);
    language_value_t *toplocinfo = language_array_ptr_ref(linetable, 0);
    language_sym_t *topfile = (language_sym_t*)language_fieldref_noalloc(toplocinfo, 0);
    int32_t topline = language_unbox_int32(language_fieldref(toplocinfo, 1));
    arraylist_t inlinestack;
    arraylist_new(&inlinestack, 0);
    arraylist_t edges_list;
    arraylist_new(&edges_list, 0);
    language_value_t *jledges = NULL;
    language_value_t *codelocs = (language_value_t*)language_alloc_array_1d(language_array_int32_type, nlocs * 3);
    language_debuginfo_t *debuginfo = NULL;
    LANGUAGE_GC_PUSH3(&jledges, &codelocs, &debuginfo);
    int32_t *codelocs32 = language_array_data(codelocs,int32_t);
    size_t j;
    for (j = 0; j < nlocs; j++) {
        size_t lineidx = language_unbox_long(language_array_ptr_ref((language_array_t*)codelocs_any, j)); // 1 indexed!
        while (lineidx != 0) {
            language_value_t *locinfo = language_array_ptr_ref(linetable, lineidx - 1);
            lineidx = language_unbox_int32(language_fieldref(locinfo, 2));
            arraylist_push(&inlinestack, locinfo);
        }
        int32_t line = 0, to = 0, pc = 0;
        if (inlinestack.len) {
            language_value_t *locinfo = (language_value_t*)arraylist_pop(&inlinestack);
            language_sym_t *filesym = (language_sym_t*)language_fieldref_noalloc(locinfo, 0);
            if (filesym == topfile)
                line = language_unbox_int32(language_fieldref(locinfo, 1));
            else
                arraylist_push(&inlinestack, locinfo);
            if (inlinestack.len) {
                add_edge(&edges_list, &inlinestack, &to, &pc);
            }
        }
        codelocs32[j * 3 + 0] = line;
        codelocs32[j * 3 + 1] = to;
        codelocs32[j * 3 + 2] = pc;
    }
    codelocs = (language_value_t*)language_compress_codelocs(topline, codelocs, nlocs);
    jledges = alloc_edges(&edges_list);
    debuginfo = (language_debuginfo_t*)language_new_struct(language_debuginfo_type, topfile, language_nothing, jledges, codelocs);
    LANGUAGE_GC_POP();
    return debuginfo;
}

// copy a :lambda Expr into its CodeInfo representation,
// including popping of known meta nodes
language_code_info_t *language_new_code_info_from_ir(language_expr_t *ir)
{
    language_code_info_t *li = NULL;
    LANGUAGE_GC_PUSH1(&li);
    li = language_new_code_info_uninit();

    language_expr_t *arglist = (language_expr_t*)language_exprarg(ir, 0);
    li->nargs = language_array_len(arglist);

    assert(language_is_expr(ir));
    language_expr_t *bodyex = (language_expr_t*)language_exprarg(ir, 2);

    language_array_t *codelocs_any = (language_array_t*)language_exprarg(ir, 3);
    language_array_t *linetable = (language_array_t*)language_exprarg(ir, 4);
    li->debuginfo = language_linetable_to_debuginfo(codelocs_any, linetable);
    language_gc_wb(li, li->debuginfo);

    assert(language_is_expr(bodyex));
    language_array_t *body = bodyex->args;
    li->code = body;
    language_gc_wb(li, li->code);
    size_t n = language_array_nrows(body);
    language_value_t **bd = (language_value_t**)language_array_ptr_data((language_array_t*)li->code);
    li->ssaflags = language_alloc_array_1d(language_array_uint32_type, n);
    language_gc_wb(li, li->ssaflags);
    int inbounds_depth = 0; // number of stacked inbounds
    // isempty(inline_flags): no user callsite inline annotation
    // last(inline_flags) == 1: callsite inline region
    // last(inline_flags) == 0: callsite noinline region
    arraylist_t *inline_flags = arraylist_new((arraylist_t*)malloc_s(sizeof(arraylist_t)), 0);
    arraylist_t *purity_exprs = arraylist_new((arraylist_t*)malloc_s(sizeof(arraylist_t)), 0);
    size_t j;
    for (j = 0; j < n; j++) {
        language_value_t *st = bd[j];
        int is_flag_stmt = 0;
        // check :meta expression
        if (language_is_expr(st) && ((language_expr_t*)st)->head == language_meta_sym) {
            size_t k, ins = 0, na = language_expr_nargs(st);
            language_array_t *meta = ((language_expr_t*)st)->args;
            for (k = 0; k < na; k++) {
                language_value_t *ma = language_array_ptr_ref(meta, k);
                if (ma == (language_value_t*)language_inline_sym)
                    li->inlining = 1;
                else if (ma == (language_value_t*)language_noinline_sym)
                    li->inlining = 2;
                else if (ma == (language_value_t*)language_propagate_inbounds_sym)
                    li->propagate_inbounds = 1;
                else if (ma == (language_value_t*)language_nospecializeinfer_sym)
                    li->nospecializeinfer = 1;
                else if (ma == (language_value_t*)language_aggressive_constprop_sym)
                    li->constprop = 1;
                else if (ma == (language_value_t*)language_no_constprop_sym)
                    li->constprop = 2;
                else if (language_is_expr(ma) && ((language_expr_t*)ma)->head == language_purity_sym) {
                    if (language_expr_nargs(ma) == NUM_EFFECTS_OVERRIDES) {
                        li->purity.overrides.ipo_consistent = language_unbox_bool(language_exprarg(ma, 0));
                        li->purity.overrides.ipo_effect_free = language_unbox_bool(language_exprarg(ma, 1));
                        li->purity.overrides.ipo_nothrow = language_unbox_bool(language_exprarg(ma, 2));
                        li->purity.overrides.ipo_terminates_globally = language_unbox_bool(language_exprarg(ma, 3));
                        li->purity.overrides.ipo_terminates_locally = language_unbox_bool(language_exprarg(ma, 4));
                        li->purity.overrides.ipo_notaskstate = language_unbox_bool(language_exprarg(ma, 5));
                        li->purity.overrides.ipo_inaccessiblememonly = language_unbox_bool(language_exprarg(ma, 6));
                        li->purity.overrides.ipo_noub = language_unbox_bool(language_exprarg(ma, 7));
                        li->purity.overrides.ipo_noub_if_noinbounds = language_unbox_bool(language_exprarg(ma, 8));
                    }
                }
                else
                    language_array_ptr_set(meta, ins++, ma);
            }
            if (ins == 0)
                bd[j] = language_nothing;
            else
                language_array_del_end(meta, na - ins);
        }
        // check other flag expressions
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_inbounds_sym) {
            is_flag_stmt = 1;
            language_value_t *arg1 = expr_arg1(st);
            if (arg1 == (language_value_t*)language_true)       // push
                inbounds_depth += 1;
            else if (arg1 == (language_value_t*)language_false) // clear
                inbounds_depth = 0;
            else if (inbounds_depth > 0)            // pop
                inbounds_depth -= 1;
            bd[j] = language_nothing;
        }
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_inline_sym) {
            is_flag_stmt = 1;
            language_value_t *arg1 = expr_arg1(st);
            if (arg1 == (language_value_t*)language_true) // enter inline region
                arraylist_push(inline_flags, (void*)1);
            else {                            // exit inline region
                assert(arg1 == (language_value_t*)language_false);
                arraylist_pop(inline_flags);
            }
            bd[j] = language_nothing;
        }
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_noinline_sym) {
            is_flag_stmt = 1;
            language_value_t *arg1 = expr_arg1(st);
            if (arg1 == (language_value_t*)language_true) // enter noinline region
                arraylist_push(inline_flags, (void*)0);
            else {                             // exit noinline region
                assert(arg1 == (language_value_t*)language_false);
                arraylist_pop(inline_flags);
            }
            bd[j] = language_nothing;
        }
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_purity_sym) {
            is_flag_stmt = 1;
            size_t na = language_expr_nargs(st);
            if (na == NUM_EFFECTS_OVERRIDES)
                arraylist_push(purity_exprs, (void*)st);
            else {
                assert(na == 0);
                arraylist_pop(purity_exprs);
            }
            bd[j] = language_nothing;
        }
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_boundscheck_sym)
            // Don't set IR_FLAG_INBOUNDS on boundscheck at the same level
            is_flag_stmt = 1;
        else if (language_is_expr(st) && ((language_expr_t*)st)->head == language_return_sym)
            language_array_ptr_set(body, j, language_new_struct(language_returnnode_type, language_exprarg(st, 0)));
        else if (language_is_expr(st) && (((language_expr_t*)st)->head == language_foreigncall_sym || ((language_expr_t*)st)->head == language_cfunction_sym))
            li->has_fcall = 1;
        if (is_flag_stmt)
            language_array_uint32_set(li->ssaflags, j, 0);
        else {
            uint32_t flag = 0;
            if (inbounds_depth > 0)
                flag |= IR_FLAG_INBOUNDS;
            if (inline_flags->len > 0) {
                void* inline_flag = inline_flags->items[inline_flags->len-1];
                flag |= 1 << (inline_flag ? 1 : 2);
            }
            int n_purity_exprs = purity_exprs->len;
            if (n_purity_exprs > 0) {
                // apply all purity overrides
                for (int i = 0; i < n_purity_exprs; i++) {
                    void* purity_expr = purity_exprs->items[i];
                    for (int j = 0; j < NUM_EFFECTS_OVERRIDES; j++) {
                        flag |= language_unbox_bool(language_exprarg((language_value_t*)purity_expr, j)) ? (1 << (NUM_IR_FLAGS+j)) : 0;
                    }
                }
            }
            language_array_uint32_set(li->ssaflags, j, flag);
        }
    }
    assert(inline_flags->len == 0 && purity_exprs->len == 0); // malformed otherwise
    arraylist_free(inline_flags); arraylist_free(purity_exprs);
    free(inline_flags); free(purity_exprs);
    language_array_t *vinfo = (language_array_t*)language_exprarg(ir, 1);
    language_array_t *vis = (language_array_t*)language_array_ptr_ref(vinfo, 0);
    size_t nslots = language_array_nrows(vis);
    language_value_t *ssavalue_types = language_array_ptr_ref(vinfo, 2);
    assert(language_is_long(ssavalue_types));
    size_t nssavalue = language_unbox_long(ssavalue_types);
    li->slotnames = language_alloc_array_1d(language_array_symbol_type, nslots);
    language_gc_wb(li, li->slotnames);
    li->slotflags = language_alloc_array_1d(language_array_uint8_type, nslots);
    language_gc_wb(li, li->slotflags);
    li->ssavaluetypes = language_box_long(nssavalue);
    language_gc_wb(li, li->ssavaluetypes);

    // Flags that need to be copied to slotflags
    const uint8_t vinfo_mask = 8 | 16 | 32 | 64;
    int i;
    for (i = 0; i < nslots; i++) {
        language_value_t *vi = language_array_ptr_ref(vis, i);
        language_sym_t *name = (language_sym_t*)language_array_ptr_ref(vi, 0);
        assert(language_is_symbol(name));
        char *str = language_symbol_name(name);
        if (i > 0 && name != language_unused_sym) {
            if (str[0] == '#') {
                // convention for renamed variables: #...#original_name
                char *nxt = strchr(str + 1, '#');
                if (nxt)
                    name = language_symbol(nxt+1);
                else if (str[1] == 's')  // compiler-generated temporaries, #sXXX
                    name = language_empty_sym;
            }
        }
        language_array_ptr_set(li->slotnames, i, name);
        language_array_uint8_set(li->slotflags, i, vinfo_mask & language_unbox_long(language_array_ptr_ref(vi, 2)));
    }
    LANGUAGE_GC_POP();
    return li;
}

LANGUAGE_DLLEXPORT language_method_instance_t *language_new_method_instance_uninit(void)
{
    language_task_t *ct = language_current_task;
    language_method_instance_t *mi =
        (language_method_instance_t*)language_gc_alloc(ct->ptls, sizeof(language_method_instance_t),
                                           language_method_instance_type);
    mi->def.value = NULL;
    mi->specTypes = NULL;
    mi->sparam_vals = language_emptysvec;
    mi->backedges = NULL;
    language_atomic_store_relaxed(&mi->cache, NULL);
    mi->inInference = 0;
    mi->cache_with_orig = 0;
    language_atomic_store_relaxed(&mi->precompiled, 0);
    return mi;
}

LANGUAGE_DLLEXPORT language_code_info_t *language_new_code_info_uninit(void)
{
    language_task_t *ct = language_current_task;
    language_code_info_t *src =
        (language_code_info_t*)language_gc_alloc(ct->ptls, sizeof(language_code_info_t),
                                       language_code_info_type);
    src->code = NULL;
    src->debuginfo = NULL;
    src->ssavaluetypes = NULL;
    src->ssaflags = NULL;
    src->method_for_inference_limit_heuristics = language_nothing;
    src->slotflags = NULL;
    src->slotnames = NULL;
    src->slottypes = language_nothing;
    src->parent = (language_method_instance_t*)language_nothing;
    src->min_world = 1;
    src->max_world = ~(size_t)0;
    src->edges = language_nothing;
    src->propagate_inbounds = 0;
    src->has_fcall = 0;
    src->nospecializeinfer = 0;
    src->constprop = 0;
    src->inlining = 0;
    src->purity.bits = 0;
    src->nargs = 0;
    src->isva = 0;
    src->inlining_cost = UINT16_MAX;
    return src;
}

// invoke (compiling if necessary) the jlcall function pointer for a method template
static language_value_t *language_call_staged(language_method_t *def, language_value_t *generator,
        size_t world, language_svec_t *sparam_vals, language_value_t **args, uint32_t nargs)
{
    size_t n_sparams = language_svec_len(sparam_vals);
    language_value_t **gargs;
    size_t totargs = 2 + n_sparams + def->nargs;
    LANGUAGE_GC_PUSHARGS(gargs, totargs);
    gargs[0] = language_box_ulong(world);
    gargs[1] = language_box_long(def->line);
    gargs[1] = language_new_struct(language_linenumbernode_type, gargs[1], def->file);
    memcpy(&gargs[2], language_svec_data(sparam_vals), n_sparams * sizeof(void*));
    memcpy(&gargs[2 + n_sparams], args, (def->nargs - def->isva) * sizeof(void*));
    if (def->isva)
        gargs[totargs - 1] = language_f_tuple(NULL, &args[def->nargs - 1], nargs - def->nargs + 1);
    language_value_t *code = language_apply_generic(generator, gargs, totargs);
    LANGUAGE_GC_POP();
    return code;
}

// Lower `ex` into Julia IR, and (if it expands into a CodeInfo) resolve global-variable
// references in light of the provided type parameters.
// Like `language_expand`, if there is an error expanding the provided expression, the return value
// will be an error expression (an `Expr` with `error_sym` as its head), which should be eval'd
// in the caller's context.
LANGUAGE_DLLEXPORT language_code_info_t *language_expand_and_resolve(language_value_t *ex, language_module_t *module,
                                                   language_svec_t *sparam_vals) {
    language_code_info_t *func = (language_code_info_t*)language_expand((language_value_t*)ex, module);
    LANGUAGE_GC_PUSH1(&func);
    if (language_is_code_info(func)) {
        language_array_t *stmts = (language_array_t*)func->code;
        language_resolve_globals_in_ir(stmts, module, sparam_vals, 1);
    }
    LANGUAGE_GC_POP();
    return func;
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_cached_uninferred(language_code_instance_t *codeinst, size_t world)
{
    for (; codeinst; codeinst = language_atomic_load_relaxed(&codeinst->next)) {
        if (codeinst->owner != (void*)language_uninferred_sym)
            continue;
        if (language_atomic_load_relaxed(&codeinst->min_world) <= world && world <= language_atomic_load_relaxed(&codeinst->max_world)) {
            return codeinst;
        }
    }
    return NULL;
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_cache_uninferred(language_method_instance_t *mi, language_code_instance_t *checked, size_t world, language_code_instance_t *newci)
{
    while (!language_mi_try_insert(mi, checked, newci)) {
        language_code_instance_t *new_checked = language_atomic_load_relaxed(&mi->cache);
        // Check if another thread inserted a CodeInstance that covers this world
        language_code_instance_t *other = language_cached_uninferred(new_checked, world);
        if (other)
            return other;
        checked = new_checked;
    }
    // Successfully inserted
    return newci;
}



// Return a newly allocated CodeInfo for the function signature
// effectively described by the tuple (specTypes, env, Method) inside linfo
LANGUAGE_DLLEXPORT language_code_info_t *language_code_for_staged(language_method_instance_t *mi, size_t world, language_code_instance_t **cache)
{
    language_code_instance_t *cache_ci = language_atomic_load_relaxed(&mi->cache);
    language_code_instance_t *uninferred_ci = language_cached_uninferred(cache_ci, world);
    if (uninferred_ci) {
        // The uninferred code is in `inferred`, but that is a bit of a misnomer here.
        // This is the cached output the generated function (or top-level thunk).
        // This cache has a non-standard owner (indicated by `->owner === :uninferred`),
        // so it doesn't get confused for inference results.
        language_code_info_t *src = (language_code_info_t*)language_atomic_load_relaxed(&uninferred_ci->inferred);
        assert(language_is_code_info(src)); // make sure this did not get `nothing` put here
        return (language_code_info_t*)language_copy_ast((language_value_t*)src);
    }

    LANGUAGE_TIMING(STAGED_FUNCTION, STAGED_FUNCTION);
    language_value_t *tt = mi->specTypes;
    language_method_t *def = mi->def.method;
    language_timing_show_method_instance(mi, LANGUAGE_TIMING_DEFAULT_BLOCK);
    language_value_t *generator = def->generator;
    assert(generator != NULL);
    assert(language_is_method(def));
    language_code_info_t *func = NULL;
    language_value_t *ex = NULL;
    language_code_info_t *uninferred = NULL;
    language_code_instance_t *ci = NULL;
    LANGUAGE_GC_PUSH4(&ex, &func, &uninferred, &ci);
    language_task_t *ct = language_current_task;
    int last_lineno = language_lineno;
    int last_in = ct->ptls->in_pure_callback;
    size_t last_age = ct->world_age;

    LANGUAGE_TRY {
        ct->ptls->in_pure_callback = 1;
        ct->world_age = language_atomic_load_relaxed(&def->primary_world);
        if (ct->world_age > language_atomic_load_acquire(&language_world_counter) || language_atomic_load_relaxed(&def->deleted_world) < ct->world_age)
            language_error("The generator method cannot run until it is added to a method table.");

        // invoke code generator
        language_tupletype_t *ttdt = (language_tupletype_t*)language_unwrap_unionall(tt);
        ex = language_call_staged(def, generator, world, mi->sparam_vals, language_svec_data(ttdt->parameters), language_nparams(ttdt));

        // do some post-processing
        if (language_is_code_info(ex)) {
            func = (language_code_info_t*)ex;
            language_array_t *stmts = (language_array_t*)func->code;
            language_resolve_globals_in_ir(stmts, def->module, mi->sparam_vals, 1);
        }
        else {
            // Lower the user's expression and resolve references to the type parameters
            func = language_expand_and_resolve(ex, def->module, mi->sparam_vals);
            if (!language_is_code_info(func)) {
                if (language_is_expr(func) && ((language_expr_t*)func)->head == language_error_sym) {
                    ct->ptls->in_pure_callback = 0;
                    language_toplevel_eval(def->module, (language_value_t*)func);
                }
                language_error("The function body AST defined by this @generated function is not pure. This likely means it contains a closure, a comprehension or a generator.");
            }
            // TODO: This should ideally be in the lambda expression,
            // but currently our isva determination is non-syntactic
            func->isva = def->isva;
        }

        // If this generated function has an opaque closure, cache it for
        // correctness of method identity
        int needs_cache_for_correctness = 0;
        for (int i = 0; i < language_array_nrows(func->code); ++i) {
            language_value_t *stmt = language_array_ptr_ref(func->code, i);
            if (language_is_expr(stmt) && ((language_expr_t*)stmt)->head == language_new_opaque_closure_sym) {
                if (language_options.incremental && language_generating_output())
                    language_error("Impossible to correctly handle OpaqueClosure inside @generated returned during precompile process.");
                needs_cache_for_correctness = 1;
                break;
            }
        }

        if (cache || needs_cache_for_correctness) {
            uninferred = (language_code_info_t*)language_copy_ast((language_value_t*)func);
            ci = language_new_codeinst_for_uninferred(mi, uninferred);

            if (uninferred->edges != language_nothing) {
                // N.B.: This needs to match `store_backedges` on the julia side
                language_array_t *edges = (language_array_t*)uninferred->edges;
                for (size_t i = 0; i < language_array_len(edges); ++i) {
                    language_value_t *kind = language_array_ptr_ref(edges, i);
                    if (language_is_method_instance(kind)) {
                        language_method_instance_add_backedge((language_method_instance_t*)kind, language_nothing, mi);
                    } else if (language_is_mtable(kind)) {
                        language_method_table_add_backedge((language_methtable_t*)kind, language_array_ptr_ref(edges, ++i), (language_value_t*)mi);
                    } else {
                        language_method_instance_add_backedge((language_method_instance_t*)language_array_ptr_ref(edges, ++i), kind, mi);
                    }
                }
            }

            language_code_instance_t *cached_ci = language_cache_uninferred(mi, cache_ci, world, ci);
            if (cached_ci != ci) {
                func = (language_code_info_t*)language_copy_ast(language_atomic_load_relaxed(&cached_ci->inferred));
                assert(language_is_code_info(func));
            }
            if (cache)
                *cache = cached_ci;
        }

        ct->ptls->in_pure_callback = last_in;
        language_lineno = last_lineno;
        ct->world_age = last_age;
    }
    LANGUAGE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        language_lineno = last_lineno;
        language_rethrow();
    }
    LANGUAGE_GC_POP();
    return func;
}

LANGUAGE_DLLEXPORT language_code_info_t *language_copy_code_info(language_code_info_t *src)
{
    language_task_t *ct = language_current_task;
    language_code_info_t *newsrc =
        (language_code_info_t*)language_gc_alloc(ct->ptls, sizeof(language_code_info_t),
                                       language_code_info_type);
    *newsrc = *src;
    return newsrc;
}

// return a new lambda-info that has some extra static parameters merged in
language_method_instance_t *language_get_specialized(language_method_t *m, language_value_t *types, language_svec_t *sp)
{
    assert((size_t)language_subtype_env_size(m->sig) == language_svec_len(sp) || sp == language_emptysvec);
    language_method_instance_t *new_linfo = language_new_method_instance_uninit();
    new_linfo->def.method = m;
    new_linfo->specTypes = types;
    new_linfo->sparam_vals = sp;
    return new_linfo;
}

LANGUAGE_DLLEXPORT void language_method_set_source(language_method_t *m, language_code_info_t *src)
{
    uint8_t j;
    uint8_t called = 0;
    int gen_only = 0;
    for (j = 1; j < m->nargs && j <= sizeof(m->nospecialize) * 8; j++) {
        language_value_t *ai = language_array_ptr_ref(src->slotnames, j);
        if (ai == (language_value_t*)language_unused_sym) {
            // TODO: enable this. currently it triggers a bug on arguments like
            // ::Type{>:Missing}
            //int sn = j-1;
            //m->nospecialize |= (1 << sn);
            continue;
        }
        if (j <= 8) {
            if (language_array_uint8_ref(src->slotflags, j) & 64)
                called |= (1 << (j - 1));
        }
    }
    m->called = called;
    m->nospecializeinfer = src->nospecializeinfer;
    m->constprop = src->constprop;
    m->purity.bits = src->purity.bits;

    language_array_t *copy = NULL;
    language_svec_t *sparam_vars = language_outer_unionall_vars(m->sig);
    LANGUAGE_GC_PUSH3(&copy, &sparam_vars, &src);
    assert(language_typetagis(src->code, language_array_any_type));
    language_array_t *stmts = (language_array_t*)src->code;
    size_t i, n = language_array_nrows(stmts);
    copy = language_alloc_vec_any(n);
    for (i = 0; i < n; i++) {
        language_value_t *st = language_array_ptr_ref(stmts, i);
        if (language_is_expr(st) && ((language_expr_t*)st)->head == language_meta_sym) {
            size_t nargs = language_expr_nargs(st);
            if (nargs >= 1 && language_exprarg(st, 0) == (language_value_t*)language_nospecialize_sym) {
                if (nargs == 1) // bare `@nospecialize` is special: it prevents specialization on all args
                    m->nospecialize = -1;
                size_t j;
                for (j = 1; j < nargs; j++) {
                    language_value_t *aj = language_exprarg(st, j);
                    if (!language_is_slotnumber(aj) && !language_is_argument(aj))
                        continue;
                    int sn = (int)language_slot_number(aj) - 2;
                    if (sn < 0) // @nospecialize on self is valid but currently ignored
                        continue;
                    if (sn > (m->nargs - 2)) {
                        language_error("@nospecialize annotation applied to a non-argument");
                    }
                    if (sn >= sizeof(m->nospecialize) * 8) {
                        language_printf(LANGUAGE_STDERR,
                                  "WARNING: @nospecialize annotation only supported on the first %d arguments.\n",
                                  (int)(sizeof(m->nospecialize) * 8));
                        continue;
                    }
                    m->nospecialize |= (1 << sn);
                }
                st = language_nothing;
            }
            else if (nargs >= 1 && language_exprarg(st, 0) == (language_value_t*)language_specialize_sym) {
                if (nargs == 1) // bare `@specialize` is special: it causes specialization on all args
                    m->nospecialize = 0;
                for (j = 1; j < nargs; j++) {
                    language_value_t *aj = language_exprarg(st, j);
                    if (!language_is_slotnumber(aj) && !language_is_argument(aj))
                        continue;
                    int sn = (int)language_slot_number(aj) - 2;
                    if (sn < 0) // @specialize on self is valid but currently ignored
                        continue;
                    if (sn > (m->nargs - 2)) {
                        language_error("@specialize annotation applied to a non-argument");
                    }
                    if (sn >= sizeof(m->nospecialize) * 8) {
                        language_printf(LANGUAGE_STDERR,
                                  "WARNING: @specialize annotation only supported on the first %d arguments.\n",
                                  (int)(sizeof(m->nospecialize) * 8));
                        continue;
                    }
                    m->nospecialize &= ~(1 << sn);
                }
                st = language_nothing;
            }
            else if (nargs == 2 && language_exprarg(st, 0) == (language_value_t*)language_generated_sym) {
                if (m->generator != NULL)
                    language_error("duplicate @generated function body");
                language_value_t *gexpr = language_exprarg(st, 1);
                // the frontend would put (new (core GeneratedFunctionStub) funcname argnames sp) here, for example
                m->generator = language_toplevel_eval(m->module, gexpr);
                language_gc_wb(m, m->generator);
                st = language_nothing;
            }
            else if (nargs == 1 && language_exprarg(st, 0) == (language_value_t*)language_generated_only_sym) {
                gen_only = 1;
                st = language_nothing;
            }
            else if (nargs == 2 && language_exprarg(st, 0) == (language_value_t*)language_symbol("nkw")) {
                m->nkw = language_unbox_long(language_exprarg(st, 1));
                st = language_nothing;
            }
        }
        else {
            st = resolve_globals(st, m->module, sparam_vars, 1, 0);
        }
        language_array_ptr_set(copy, i, st);
    }
    src = language_copy_code_info(src);
    src->isva = m->isva; // TODO: It would be nice to reverse this
    assert(m->nargs == src->nargs);
    src->code = copy;
    language_gc_wb(src, copy);
    m->slot_syms = language_compress_argnames(src->slotnames);
    language_gc_wb(m, m->slot_syms);
    if (gen_only) {
        m->source = NULL;
    }
    else {
        m->debuginfo = src->debuginfo;
        language_gc_wb(m, m->debuginfo);
        m->source = (language_value_t*)src;
        language_gc_wb(m, m->source);
        m->source = (language_value_t*)language_compress_ir(m, NULL);
        language_gc_wb(m, m->source);
    }
    LANGUAGE_GC_POP();
}

LANGUAGE_DLLEXPORT language_method_t *language_new_method_uninit(language_module_t *module)
{
    language_task_t *ct = language_current_task;
    language_method_t *m =
        (language_method_t*)language_gc_alloc(ct->ptls, sizeof(language_method_t), language_method_type);
    language_atomic_store_relaxed(&m->specializations, (language_value_t*)language_emptysvec);
    language_atomic_store_relaxed(&m->speckeyset, (language_genericmemory_t*)language_an_empty_memory_any);
    m->sig = NULL;
    m->slot_syms = NULL;
    m->roots = NULL;
    m->root_blocks = NULL;
    m->nroots_sysimg = 0;
    m->ccallable = NULL;
    m->module = module;
    m->external_mt = NULL;
    m->source = NULL;
    m->debuginfo = NULL;
    language_atomic_store_relaxed(&m->unspecialized, NULL);
    m->generator = NULL;
    m->name = NULL;
    m->file = language_empty_sym;
    m->line = 0;
    m->called = 0xff;
    m->nospecialize = module->nospecialize;
    m->nkw = 0;
    language_atomic_store_relaxed(&m->invokes, language_nothing);
    m->recursion_relation = NULL;
    m->isva = 0;
    m->nargs = 0;
    language_atomic_store_relaxed(&m->primary_world, ~(size_t)0);
    language_atomic_store_relaxed(&m->deleted_world, 1);
    m->is_for_opaque_closure = 0;
    m->nospecializeinfer = 0;
    m->constprop = 0;
    m->purity.bits = 0;
    m->max_varargs = UINT8_MAX;
    LANGUAGE_MUTEX_INIT(&m->writelock, "method->writelock");
    return m;
}

// backedges ------------------------------------------------------------------

// Use this in a `while` loop to iterate over the backedges in a MethodInstance.
// `*invokesig` will be NULL if the call was made by ordinary dispatch, otherwise
// it will be the signature supplied in an `invoke` call.
// If you don't need `invokesig`, you can set it to NULL on input.
// Initialize iteration with `i = 0`. Returns `i` for the next backedge to be extracted.
int get_next_edge(language_array_t *list, int i, language_value_t** invokesig, language_method_instance_t **caller) LANGUAGE_NOTSAFEPOINT
{
    language_value_t *item = language_array_ptr_ref(list, i);
    if (language_is_method_instance(item)) {
        // Not an `invoke` call, it's just the MethodInstance
        if (invokesig != NULL)
            *invokesig = NULL;
        *caller = (language_method_instance_t*)item;
        return i + 1;
    }
    assert(language_is_type(item));
    // An `invoke` call, it's a (sig, MethodInstance) pair
    if (invokesig != NULL)
        *invokesig = item;
    *caller = (language_method_instance_t*)language_array_ptr_ref(list, i + 1);
    if (*caller)
        assert(language_is_method_instance(*caller));
    return i + 2;
}

int set_next_edge(language_array_t *list, int i, language_value_t *invokesig, language_method_instance_t *caller)
{
    if (invokesig)
        language_array_ptr_set(list, i++, invokesig);
    language_array_ptr_set(list, i++, caller);
    return i;
}

void push_edge(language_array_t *list, language_value_t *invokesig, language_method_instance_t *caller)
{
    if (invokesig)
        language_array_ptr_1d_push(list, invokesig);
    language_array_ptr_1d_push(list, (language_value_t*)caller);
    return;
}

// method definition ----------------------------------------------------------

language_method_t *language_make_opaque_closure_method(language_module_t *module, language_value_t *name,
    int nargs, language_value_t *functionloc, language_code_info_t *ci, int isva, int isinferred)
{
    language_method_t *m = language_new_method_uninit(module);
    LANGUAGE_GC_PUSH1(&m);
    // TODO: Maybe have a signature of (parent method, stmt#)?
    m->sig = (language_value_t*)language_anytuple_type;
    m->isva = isva;
    m->is_for_opaque_closure = 1;
    if (name == language_nothing) {
        m->name = language_symbol("opaque closure");
    } else {
        assert(language_is_symbol(name));
        m->name = (language_sym_t*)name;
    }
    m->nargs = nargs + 1;
    assert(language_is_linenode(functionloc));
    language_value_t *file = language_linenode_file(functionloc);
    m->file = language_is_symbol(file) ? (language_sym_t*)file : language_empty_sym;
    m->line = language_linenode_line(functionloc);
    if (isinferred) {
        m->slot_syms = language_compress_argnames(ci->slotnames);
        language_gc_wb(m, m->slot_syms);
    } else {
        language_method_set_source(m, ci);
    }
    LANGUAGE_GC_POP();
    return m;
}

// empty generic function def
LANGUAGE_DLLEXPORT language_value_t *language_generic_function_def(language_sym_t *name,
                                                 language_module_t *module,
                                                 _Atomic(language_value_t*) *bp,
                                                 language_binding_t *bnd)
{
    language_value_t *gf = NULL;

    assert(name && bp);
    if (bnd && language_atomic_load_relaxed(&bnd->value) != NULL && !bnd->constp)
        language_errorf("cannot define function %s; it already has a value", language_symbol_name(name));
    gf = language_atomic_load_relaxed(bp);
    if (gf != NULL) {
        if (!language_is_datatype_singleton((language_datatype_t*)language_typeof(gf)) && !language_is_type(gf))
            language_errorf("cannot define function %s; it already has a value", language_symbol_name(name));
    }
    if (bnd)
        bnd->constp = 1; // XXX: use language_declare_constant and language_checked_assignment
    if (gf == NULL) {
        gf = (language_value_t*)language_new_generic_function(name, module);
        language_atomic_store(bp, gf); // TODO: fix constp assignment data race
        if (bnd) language_gc_wb(bnd, gf);
    }
    return gf;
}

static language_methtable_t *nth_methtable(language_value_t *a LANGUAGE_PROPAGATES_ROOT, int n) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_datatype(a)) {
        if (n == 0) {
            language_methtable_t *mt = ((language_datatype_t*)a)->name->mt;
            if (mt != NULL)
                return mt;
        }
        else if (language_is_tuple_type(a)) {
            if (language_nparams(a) >= n)
                return nth_methtable(language_tparam(a, n - 1), 0);
        }
    }
    else if (language_is_typevar(a)) {
        return nth_methtable(((language_tvar_t*)a)->ub, n);
    }
    else if (language_is_unionall(a)) {
        return nth_methtable(((language_unionall_t*)a)->body, n);
    }
    else if (language_is_uniontype(a)) {
        language_uniontype_t *u = (language_uniontype_t*)a;
        language_methtable_t *m1 = nth_methtable(u->a, n);
        if ((language_value_t*)m1 != language_nothing) {
            language_methtable_t *m2 = nth_methtable(u->b, n);
            if (m1 == m2)
                return m1;
        }
    }
    return (language_methtable_t*)language_nothing;
}

// get the MethodTable for dispatch, or `nothing` if cannot be determined
LANGUAGE_DLLEXPORT language_methtable_t *language_method_table_for(language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    return nth_methtable(argtypes, 1);
}

language_methtable_t *language_kwmethod_table_for(language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    language_methtable_t *kwmt = nth_methtable(argtypes, 3);
    if ((language_value_t*)kwmt == language_nothing)
        return NULL;
    return kwmt;
}

LANGUAGE_DLLEXPORT language_methtable_t *language_method_get_table(language_method_t *method LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    return method->external_mt ? (language_methtable_t*)method->external_mt : language_method_table_for(method->sig);
}

LANGUAGE_DLLEXPORT language_method_t* language_method_def(language_svec_t *argdata,
                                        language_methtable_t *mt,
                                        language_code_info_t *f,
                                        language_module_t *module)
{
    // argdata is svec(svec(types...), svec(typevars...), functionloc)
    language_svec_t *atypes = (language_svec_t*)language_svecref(argdata, 0);
    language_svec_t *tvars = (language_svec_t*)language_svecref(argdata, 1);
    language_value_t *functionloc = language_svecref(argdata, 2);
    assert(language_is_svec(atypes));
    assert(language_is_svec(tvars));
    size_t nargs = language_svec_len(atypes);
    assert(nargs > 0);
    int isva = language_is_vararg(language_svecref(atypes, nargs - 1));
    if (!language_is_type(language_svecref(atypes, 0)) || (isva && nargs == 1))
        language_error("function type in method definition is not a type");
    language_sym_t *name;
    language_method_t *m = NULL;
    language_value_t *argtype = NULL;
    LANGUAGE_GC_PUSH3(&f, &m, &argtype);
    size_t i, na = language_svec_len(atypes);

    argtype = language_apply_tuple_type(atypes, 1);
    if (!language_is_datatype(argtype))
        language_error("invalid type in method definition (Union{})");

    language_methtable_t *external_mt = mt;
    if (!mt)
        mt = language_method_table_for(argtype);
    if ((language_value_t*)mt == language_nothing)
        language_error("Method dispatch is unimplemented currently for this method signature");
    if (mt->frozen)
        language_error("cannot add methods to a builtin function");

    assert(language_is_linenode(functionloc));
    language_sym_t *file = (language_sym_t*)language_linenode_file(functionloc);
    if (!language_is_symbol(file))
        file = language_empty_sym;
    int32_t line = language_linenode_line(functionloc);

    // TODO: derive our debug name from the syntax instead of the type
    language_methtable_t *kwmt = mt == language_kwcall_mt ? language_kwmethod_table_for(argtype) : mt;
    // if we have a kwcall, try to derive the name from the callee argument method table
    name = (kwmt ? kwmt : mt)->name;
    if (kwmt == language_type_type_mt || kwmt == language_nonfunction_mt || external_mt) {
        // our value for `name` is bad, try to guess what the syntax might have had,
        // like `language_static_show_func_sig` might have come up with
        language_datatype_t *dt = language_nth_argument_datatype(argtype, mt == language_kwcall_mt ? 3 : 1);
        if (dt != NULL) {
            name = dt->name->name;
            if (language_is_type_type((language_value_t*)dt)) {
                dt = (language_datatype_t*)language_argument_datatype(language_tparam0(dt));
                if ((language_value_t*)dt != language_nothing) {
                    name = dt->name->name;
                }
            }
        }
    }

    if (!language_is_code_info(f)) {
        // this occurs when there is a closure being added to an out-of-scope function
        // the user should only do this at the toplevel
        // the result is that the closure variables get interpolated directly into the IR
        f = language_new_code_info_from_ir((language_expr_t*)f);
    }

    for (i = 0; i < na; i++) {
        language_value_t *elt = language_svecref(atypes, i);
        if (language_is_vararg(elt)) {
            if (i < na-1)
                language_exceptionf(language_argumenterror_type,
                              "Vararg on non-final argument in method definition for %s at %s:%d",
                              language_symbol_name(name),
                              language_symbol_name(file),
                              line);
            elt = language_unwrap_vararg(elt);
        }
        int isvalid = (language_is_type(elt) || language_is_typevar(elt) || language_is_vararg(elt)) && elt != language_bottom_type;
        if (!isvalid) {
            language_sym_t *argname = (language_sym_t*)language_array_ptr_ref(f->slotnames, i);
            if (argname == language_unused_sym)
                language_exceptionf(language_argumenterror_type,
                              "invalid type for argument number %d in method definition for %s at %s:%d",
                              i,
                              language_symbol_name(name),
                              language_symbol_name(file),
                              line);
            else
                language_exceptionf(language_argumenterror_type,
                              "invalid type for argument %s in method definition for %s at %s:%d",
                              language_symbol_name(argname),
                              language_symbol_name(name),
                              language_symbol_name(file),
                              line);
        }
    }
    for (i = language_svec_len(tvars); i > 0; i--) {
        language_value_t *tv = language_svecref(tvars, i - 1);
        if (!language_is_typevar(tv))
            language_type_error("method signature", (language_value_t*)language_tvar_type, tv);
        if (!language_has_typevar(argtype, (language_tvar_t*)tv)) // deprecate this to an error in v2
            language_printf(LANGUAGE_STDERR,
                      "WARNING: method definition for %s at %s:%d declares type variable %s but does not use it.\n",
                      language_symbol_name(name),
                      language_symbol_name(file),
                      line,
                      language_symbol_name(((language_tvar_t*)tv)->name));
        argtype = language_new_struct(language_unionall_type, tv, argtype);
    }
    if (language_has_free_typevars(argtype)) {
        language_exceptionf(language_argumenterror_type,
                      "method definition for %s at %s:%d has free type variables",
                      language_symbol_name(name),
                      language_symbol_name(file),
                      line);
    }

    m = language_new_method_uninit(module);
    m->external_mt = (language_value_t*)external_mt;
    if (external_mt)
        language_gc_wb(m, external_mt);
    m->sig = argtype;
    m->name = name;
    m->isva = isva;
    m->nargs = nargs;
    m->file = file;
    m->line = line;
    language_method_set_source(m, f);

    language_method_table_insert(mt, m, NULL);
    if (language_newmeth_tracer)
        language_call_tracer(language_newmeth_tracer, (language_value_t*)m);
    LANGUAGE_GC_POP();

    return m;
}

// root blocks

// This section handles method roots. Roots are GC-preserved items needed to
// represent lowered, type-inferred, and/or compiled code. These items are
// stored in a flat list (`m.roots`), and during serialization and
// deserialization of code we replace C-pointers to these items with a
// relocatable reference. We use a bipartite reference, `(key, index)` pair,
// where `key` identifies the module that added the root and `index` numbers
// just those roots with the same `key`.
//
// During precompilation (serialization), we save roots that were added to
// methods that are tagged with this package's module-key, even for "external"
// methods not owned by a module currently being precompiled. During
// deserialization, we load the new roots and append them to the method. When
// code is deserialized (see ircode.c), we replace the bipartite reference with
// the pointer to the memory address in the current session. The bipartite
// reference allows us to cache both roots and references in precompilation .ji
// files using a naming scheme that is independent of which packages are loaded
// in arbitrary order.
//
// To track the module-of-origin for each root, methods also have a
// `root_blocks` field that uses run-length encoding (RLE) storing `key` and the
// (absolute) integer index within `roots` at which a block of roots with that
// key begins. This makes it possible to look up an individual `(key, index)`
// pair fairly efficiently. A given `key` may possess more than one block; the
// `index` continues to increment regardless of block boundaries.
//
// Roots with `key = 0` are considered to be of unknown origin, and
// CodeInstances referencing such roots will remain unserializable unless all
// such roots were added at the time of system image creation. To track this
// additional data, we use two fields:
//
// - methods have an `nroots_sysimg` field to count the number of roots defined
//   at the time of writing the system image (such occur first in the list of
//   roots). These are the cases with `key = 0` that do not prevent
//   serialization.
// - CodeInstances have a `relocatability` field which when 1 indicates that
//   every root is "safe," meaning it was either added at sysimg creation or is
//   tagged with a non-zero `key`. Even a single unsafe root will cause this to
//   have value 0.

// Get the key of the current (final) block of roots
static uint64_t current_root_id(language_array_t *root_blocks)
{
    if (!root_blocks)
        return 0;
    assert(language_is_array(root_blocks));
    size_t nx2 = language_array_nrows(root_blocks);
    if (nx2 == 0)
        return 0;
    uint64_t *blocks = language_array_data(root_blocks, uint64_t);
    return blocks[nx2-2];
}

// Add a new block of `len` roots with key `modid` (module id)
static void add_root_block(language_array_t *root_blocks, uint64_t modid, size_t len)
{
    assert(language_is_array(root_blocks));
    language_array_grow_end(root_blocks, 2);
    uint64_t *blocks = language_array_data(root_blocks, uint64_t);
    int nx2 = language_array_nrows(root_blocks);
    blocks[nx2-2] = modid;
    blocks[nx2-1] = len;
}

// Allocate storage for roots
static void prepare_method_for_roots(language_method_t *m, uint64_t modid)
{
    if (!m->roots) {
        m->roots = language_alloc_vec_any(0);
        language_gc_wb(m, m->roots);
    }
    if (!m->root_blocks && modid != 0) {
        m->root_blocks = language_alloc_array_1d(language_array_uint64_type, 0);
        language_gc_wb(m, m->root_blocks);
    }
}

// Add a single root with owner `mod` to a method
LANGUAGE_DLLEXPORT void language_add_method_root(language_method_t *m, language_module_t *mod, language_value_t* root)
{
    LANGUAGE_GC_PUSH2(&m, &root);
    uint64_t modid = 0;
    if (mod) {
        assert(language_is_module(mod));
        modid = mod->build_id.lo;
    }
    assert(language_is_method(m));
    prepare_method_for_roots(m, modid);
    if (current_root_id(m->root_blocks) != modid)
        add_root_block(m->root_blocks, modid, language_array_nrows(m->roots));
    language_array_ptr_1d_push(m->roots, root);
    LANGUAGE_GC_POP();
}

// Add a list of roots with key `modid` to a method
void language_append_method_roots(language_method_t *m, uint64_t modid, language_array_t* roots)
{
    LANGUAGE_GC_PUSH2(&m, &roots);
    assert(language_is_method(m));
    assert(language_is_array(roots));
    prepare_method_for_roots(m, modid);
    add_root_block(m->root_blocks, modid, language_array_nrows(m->roots));
    language_array_ptr_1d_append(m->roots, roots);
    LANGUAGE_GC_POP();
}

// given the absolute index i of a root, retrieve its relocatable reference
// returns 1 if the root is relocatable
int get_root_reference(rle_reference *rr, language_method_t *m, size_t i)
{
    if (!m->root_blocks) {
        rr->key = 0;
        rr->index = i;
        return i < m->nroots_sysimg;
    }
    rle_index_to_reference(rr, i, language_array_data(m->root_blocks, uint64_t), language_array_nrows(m->root_blocks), 0);
    if (rr->key)
        return 1;
    return i < m->nroots_sysimg;
}

// get a root, given its key and index relative to the key
// this is the relocatable way to get a root from m->roots
language_value_t *lookup_root(language_method_t *m, uint64_t key, int index)
{
    if (!m->root_blocks) {
        assert(key == 0);
        return language_array_ptr_ref(m->roots, index);
    }
    rle_reference rr = {key, index};
    size_t i = rle_reference_to_index(&rr, language_array_data(m->root_blocks, uint64_t), language_array_nrows(m->root_blocks), 0);
    return language_array_ptr_ref(m->roots, i);
}

// Count the number of roots added by module with id `key`
int nroots_with_key(language_method_t *m, uint64_t key)
{
    size_t nroots = 0;
    if (m->roots)
        nroots = language_array_nrows(m->roots);
    if (!m->root_blocks)
        return key == 0 ? nroots : 0;
    uint64_t *rletable = language_array_data(m->root_blocks, uint64_t);
    size_t j, nblocks2 = language_array_nrows(m->root_blocks);
    int nwithkey = 0;
    for (j = 0; j < nblocks2; j+=2) {
        if (rletable[j] == key)
            nwithkey += (j+3 < nblocks2 ? rletable[j+3] : nroots) - rletable[j+1];
    }
    return nwithkey;
}

#ifdef __cplusplus
}
#endif
