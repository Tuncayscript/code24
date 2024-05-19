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
  evaluating top-level expressions, loading source files
*/
#include "platform.h"

#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#if defined(_OS_WINDOWS_)
#include <malloc.h>
#else
#include <unistd.h>
#endif
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"
#include "intrinsics.h"
#include "builtin_proto.h"

#ifdef __cplusplus
extern "C" {
#endif

// current line number in a file
LANGUAGE_DLLEXPORT int language_lineno = 0; // need to update language_critical_error if this is TLS
// current file name
LANGUAGE_DLLEXPORT const char *language_filename = "none"; // need to update language_critical_error if this is TLS

htable_t language_current_modules;
language_mutex_t language_modules_mutex;

// During incremental compilation, the following gets set
LANGUAGE_DLLEXPORT language_module_t *language_precompile_toplevel_module = NULL;   // the toplevel module currently being defined

LANGUAGE_DLLEXPORT void language_add_standard_imports(language_module_t *m)
{
    language_module_t *base_module = language_base_relative_to(m);
    assert(base_module != NULL);
    // using Base
    language_module_using(m, base_module);
}

// create a new top-level module
void language_init_main_module(void)
{
    assert(language_main_module == NULL);
    language_main_module = language_new_module(language_symbol("Main"), NULL);
    language_main_module->parent = language_main_module;
    language_set_const(language_main_module, language_symbol("Core"),
                 (language_value_t*)language_core_module);
    language_set_const(language_core_module, language_symbol("Main"),
                 (language_value_t*)language_main_module);
}

static language_function_t *language_module_get_initializer(language_module_t *m LANGUAGE_PROPAGATES_ROOT)
{
    return (language_function_t*)language_get_global(m, language_symbol("__init__"));
}


void language_module_run_initializer(language_module_t *m)
{
    LANGUAGE_TIMING(INIT_MODULE, INIT_MODULE);
    language_timing_show_module(m, LANGUAGE_TIMING_DEFAULT_BLOCK);
    language_function_t *f = language_module_get_initializer(m);
    if (f == NULL)
        return;
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    LANGUAGE_TRY {
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        language_apply(&f, 1);
        ct->world_age = last_age;
    }
    LANGUAGE_CATCH {
        if (language_initerror_type == NULL) {
            language_rethrow();
        }
        else {
            language_rethrow_other(language_new_struct(language_initerror_type, m->name,
                                           language_current_exception(ct)));
        }
    }
}

static void language_register_root_module(language_module_t *m)
{
    static language_value_t *register_module_func = NULL;
    assert(language_base_module);
    if (register_module_func == NULL)
        register_module_func = language_get_global(language_base_module, language_symbol("register_root_module"));
    assert(register_module_func);
    language_value_t *args[2];
    args[0] = register_module_func;
    args[1] = (language_value_t*)m;
    language_apply(args, 2);
}

language_array_t *language_get_loaded_modules(void)
{
    static language_value_t *loaded_modules_array = NULL;
    if (loaded_modules_array == NULL && language_base_module != NULL)
        loaded_modules_array = language_get_global(language_base_module, language_symbol("loaded_modules_array"));
    if (loaded_modules_array != NULL)
        return (language_array_t*)language_call0((language_function_t*)loaded_modules_array);
    return NULL;
}

static int language_is__toplevel__mod(language_module_t *mod)
{
    return language_base_module &&
        (language_value_t*)mod == language_get_global(language_base_module, language_symbol("__toplevel__"));
}

// TODO: add locks around global state mutation operations
static language_value_t *language_eval_module_expr(language_module_t *parent_module, language_expr_t *ex)
{
    language_task_t *ct = language_current_task;
    assert(ex->head == language_module_sym);
    if (language_array_nrows(ex->args) != 3 || !language_is_expr(language_exprarg(ex, 2))) {
        language_error("syntax: malformed module expression");
    }

    if (((language_expr_t *)(language_exprarg(ex, 2)))->head != language_symbol("block")) {
        language_error("syntax: module expression third argument must be a block");
    }

    int std_imports = (language_exprarg(ex, 0) == language_true);
    language_sym_t *name = (language_sym_t*)language_exprarg(ex, 1);
    if (!language_is_symbol(name)) {
        language_type_error("module", (language_value_t*)language_symbol_type, (language_value_t*)name);
    }

    int is_parent__toplevel__ = language_is__toplevel__mod(parent_module);
    language_module_t *newm = language_new_module(name, is_parent__toplevel__ ? NULL : parent_module);
    language_value_t *form = (language_value_t*)newm;
    LANGUAGE_GC_PUSH1(&form);
    LANGUAGE_LOCK(&language_modules_mutex);
    ptrhash_put(&language_current_modules, (void*)newm, (void*)((uintptr_t)HT_NOTFOUND + 1));
    LANGUAGE_UNLOCK(&language_modules_mutex);

    language_module_t *old_toplevel_module = language_precompile_toplevel_module;

    // copy parent environment info into submodule
    newm->uuid = parent_module->uuid;
    if (is_parent__toplevel__) {
        newm->parent = newm;
        language_register_root_module(newm);
        if (language_options.incremental) {
            language_precompile_toplevel_module = newm;
        }
    }
    else {
        language_binding_t *b = language_get_binding_wr(parent_module, name);
        language_declare_constant(b, parent_module, name);
        language_value_t *old = NULL;
        if (!language_atomic_cmpswap(&b->value, &old, (language_value_t*)newm)) {
            if (!language_is_module(old)) {
                language_errorf("invalid redefinition of constant %s", language_symbol_name(name));
            }
            if (language_generating_output())
                language_errorf("cannot replace module %s during compilation", language_symbol_name(name));
            language_printf(LANGUAGE_STDERR, "WARNING: replacing module %s.\n", language_symbol_name(name));
            old = language_atomic_exchange(&b->value, (language_value_t*)newm);
        }
        language_gc_wb(b, newm);
        if (old != NULL) {
            // create a hidden gc root for the old module
            LANGUAGE_LOCK(&language_modules_mutex);
            uintptr_t *refcnt = (uintptr_t*)ptrhash_bp(&language_current_modules, (void*)old);
            *refcnt += 1;
            LANGUAGE_UNLOCK(&language_modules_mutex);
        }
    }

    if (parent_module == language_main_module && name == language_symbol("Base")) {
        // pick up Base module during bootstrap
        language_base_module = newm;
    }

    size_t last_age = ct->world_age;

    // add standard imports unless baremodule
    language_array_t *exprs = ((language_expr_t*)language_exprarg(ex, 2))->args;
    int lineno = 0;
    const char *filename = "none";
    if (language_array_nrows(exprs) > 0) {
        language_value_t *lineex = language_array_ptr_ref(exprs, 0);
        if (language_is_linenode(lineex)) {
            lineno = language_linenode_line(lineex);
            language_value_t *file = language_linenode_file(lineex);
            if (language_is_symbol(file))
                filename = language_symbol_name((language_sym_t*)file);
        }
    }
    if (std_imports) {
        if (language_base_module != NULL) {
            language_add_standard_imports(newm);
        }
        // add `eval` function
        form = language_call_scm_on_ast_and_loc("module-default-defs", (language_value_t*)name, newm, filename, lineno);
        language_toplevel_eval_flex(newm, form, 0, 1, &filename, &lineno);
        form = NULL;
    }

    for (int i = 0; i < language_array_nrows(exprs); i++) {
        // process toplevel form
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        form = language_expand_stmt_with_loc(language_array_ptr_ref(exprs, i), newm, filename, lineno);
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        (void)language_toplevel_eval_flex(newm, form, 1, 1, &filename, &lineno);
    }
    ct->world_age = last_age;

#if 0
    // some optional post-processing steps
    size_t i;
    language_svec_t *table = language_atomic_load_relaxed(&newm->bindings);
    for (size_t i = 0; i < language_svec_len(table); i++) {
        language_binding_t *b = (language_binding_t*)language_svecref(table, i);
        if ((void*)b != language_nothing) {
            // remove non-exported macros
            if (language_symbol_name(b->name)[0]=='@' &&
                !b->exportp && b->owner == b)
                b->value = NULL;
            // error for unassigned exports
            /*
            if (b->exportp && b->owner==b && b->value==NULL)
                language_errorf("identifier %s exported from %s is not initialized",
                          language_symbol_name(b->name), language_symbol_name(newm->name));
            */
        }
    }
#endif

    LANGUAGE_LOCK(&language_modules_mutex);
    uintptr_t *refcnt = (uintptr_t*)ptrhash_bp(&language_current_modules, (void*)newm);
    assert(*refcnt > (uintptr_t)HT_NOTFOUND);
    *refcnt -= 1;
    // newm should be reachable from somewhere else by now

    if (language_module_init_order == NULL)
        language_module_init_order = language_alloc_vec_any(0);
    language_array_ptr_1d_push(language_module_init_order, (language_value_t*)newm);

    // defer init of children until parent is done being defined
    // then initialize all in definition-finished order
    // at build time, don't run them at all (defer for runtime)
    form = NULL;
    if (!language_generating_output()) {
        if (!ptrhash_has(&language_current_modules, (void*)newm->parent)) {
            size_t i, l = language_array_nrows(language_module_init_order);
            size_t ns = 0;
            form = (language_value_t*)language_alloc_vec_any(0);
            for (i = 0; i < l; i++) {
                language_module_t *m = (language_module_t*)language_array_ptr_ref(language_module_init_order, i);
                if (language_is_submodule(m, newm)) {
                    language_array_ptr_1d_push((language_array_t*)form, (language_value_t*)m);
                }
                else if (ns++ != i) {
                    language_array_ptr_set(language_module_init_order, ns - 1, (language_value_t*)m);
                }
            }
            if (ns < l)
                language_array_del_end(language_module_init_order, l - ns);
        }
    }
    LANGUAGE_UNLOCK(&language_modules_mutex);

    if (form) {
        size_t i, l = language_array_nrows(form);
        for (i = 0; i < l; i++) {
            language_module_t *m = (language_module_t*)language_array_ptr_ref(form, i);
            LANGUAGE_GC_PROMISE_ROOTED(m);
            language_module_run_initializer(m);
        }
    }

    language_precompile_toplevel_module = old_toplevel_module;

    LANGUAGE_GC_POP();
    return (language_value_t*)newm;
}

static language_value_t *language_eval_dot_expr(language_module_t *m, language_value_t *x, language_value_t *f, int fast, const char **toplevel_filename, int *toplevel_lineno)
{
    language_task_t *ct = language_current_task;
    language_value_t **args;
    LANGUAGE_GC_PUSHARGS(args, 3);
    args[1] = language_toplevel_eval_flex(m, x, fast, 0, toplevel_filename, toplevel_lineno);
    args[2] = language_toplevel_eval_flex(m, f, fast, 0, toplevel_filename, toplevel_lineno);
    if (language_is_module(args[1])) {
        LANGUAGE_TYPECHK(getglobal, symbol, args[2]);
        args[0] = language_eval_global_var((language_module_t*)args[1], (language_sym_t*)args[2]);
    }
    else {
        args[0] = language_eval_global_var(language_base_relative_to(m), language_symbol("getproperty"));
        size_t last_age = ct->world_age;
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        args[0] = language_apply(args, 3);
        ct->world_age = last_age;
    }
    LANGUAGE_GC_POP();
    return args[0];
}

void language_eval_global_expr(language_module_t *m, language_expr_t *ex, int set_type) {
    // create uninitialized mutable binding for "global x" decl sometimes or probably
    size_t i, l = language_array_nrows(ex->args);
    for (i = 0; i < l; i++) {
        language_value_t *arg = language_exprarg(ex, i);
        language_module_t *gm;
        language_sym_t *gs;
        if (language_is_globalref(arg)) {
            gm = language_globalref_mod(arg);
            gs = language_globalref_name(arg);
        }
        else {
            assert(language_is_symbol(arg));
            gm = m;
            gs = (language_sym_t*)arg;
        }
        if (!language_binding_resolved_p(gm, gs)) {
            language_binding_t *b = language_get_binding_wr(gm, gs);
            if (set_type) {
                language_value_t *old_ty = NULL;
                // maybe set the type too, perhaps
                language_atomic_cmpswap_relaxed(&b->ty, &old_ty, (language_value_t*)language_any_type);
            }
        }
    }
}

// module referenced by (top ...) from within m
// this is only needed because of the bootstrapping process:
// - initially Base doesn't exist and top === Core
// - later, it refers to either old Base or new Base
LANGUAGE_DLLEXPORT language_module_t *language_base_relative_to(language_module_t *m)
{
    for (;;) {
        if (m->istopmod)
            return m;
        if (m == m->parent)
            break;
        m = m->parent;
    }
    return language_top_module;
}

static void expr_attributes(language_value_t *v, language_array_t *body, int *has_ccall, int *has_defs, int *has_opaque)
{
    if (!language_is_expr(v))
        return;
    language_expr_t *e = (language_expr_t*)v;
    language_sym_t *head = e->head;
    if (head == language_toplevel_sym || head == language_thunk_sym) {
        return;
    }
    else if (head == language_global_sym) {
        // this could be considered has_defs, but loops that assign to globals
        // might still need to be optimized.
        return;
    }
    else if (head == language_const_sym || head == language_copyast_sym) {
        // Note: `copyast` is included here since it indicates the presence of
        // `quote` and probably `eval`.
        *has_defs = 1;
        return;
    }
    else if (head == language_method_sym || language_is_toplevel_only_expr(v)) {
        *has_defs = 1;
    }
    else if (head == language_cfunction_sym) {
        *has_ccall = 1;
        return;
    }
    else if (head == language_foreigncall_sym) {
        *has_ccall = 1;
        return;
    }
    else if (head == language_new_opaque_closure_sym) {
        *has_opaque = 1;
        return;
    }
    else if (head == language_call_sym && language_expr_nargs(e) > 0) {
        language_value_t *called = NULL;
        language_value_t *f = language_exprarg(e, 0);
        if (language_is_ssavalue(f)) {
            f = language_array_ptr_ref(body, ((language_ssavalue_t*)f)->id - 1);
        }
        if (language_is_globalref(f)) {
            language_module_t *mod = language_globalref_mod(f);
            language_sym_t *name = language_globalref_name(f);
            if (language_binding_resolved_p(mod, name)) {
                language_binding_t *b = language_get_binding(mod, name);
                if (b && b->constp) {
                    called = language_atomic_load_relaxed(&b->value);
                }
            }
        }
        else if (language_is_quotenode(f)) {
            called = language_quotenode_value(f);
        }
        if (called != NULL) {
            if (language_is_intrinsic(called) && language_unbox_int32(called) == (int)llvmcall) {
                *has_ccall = 1;
            }
            if (called == language_builtin__typebody) {
                *has_defs = 1;
            }
        }
        return;
    }
    int i;
    for (i = 0; i < language_array_nrows(e->args); i++) {
        language_value_t *a = language_exprarg(e, i);
        if (language_is_expr(a))
            expr_attributes(a, body, has_ccall, has_defs, has_opaque);
    }
}

int language_code_requires_compiler(language_code_info_t *src, int include_force_compile)
{
    language_array_t *body = src->code;
    assert(language_typetagis(body, language_array_any_type));
    size_t i;
    int has_ccall = 0, has_defs = 0, has_opaque = 0;
    if (include_force_compile && language_has_meta(body, language_force_compile_sym))
        return 1;
    for(i=0; i < language_array_nrows(body); i++) {
        language_value_t *stmt = language_array_ptr_ref(body,i);
        expr_attributes(stmt, body, &has_ccall, &has_defs, &has_opaque);
        if (has_ccall)
            return 1;
    }
    return 0;
}

static void body_attributes(language_array_t *body, int *has_ccall, int *has_defs, int *has_loops, int *has_opaque, int *forced_compile)
{
    size_t i;
    *has_loops = 0;
    for(i=0; i < language_array_nrows(body); i++) {
        language_value_t *stmt = language_array_ptr_ref(body,i);
        if (!*has_loops) {
            if (language_is_gotonode(stmt)) {
                if (language_gotonode_label(stmt) <= i)
                    *has_loops = 1;
            }
            else if (language_is_gotoifnot(stmt)) {
                if (language_gotoifnot_label(stmt) <= i)
                    *has_loops = 1;
            }
        }
        expr_attributes(stmt, body, has_ccall, has_defs, has_opaque);
    }
    *forced_compile = language_has_meta(body, language_force_compile_sym);
}

size_t language_require_world = ~(size_t)0;
static language_module_t *call_require(language_module_t *mod, language_sym_t *var) LANGUAGE_GLOBALLY_ROOTED
{
    LANGUAGE_TIMING(LOAD_IMAGE, LOAD_Require);
    language_timing_printf(LANGUAGE_TIMING_DEFAULT_BLOCK, "%s", language_symbol_name(var));

    int build_mode = language_options.incremental && language_generating_output();
    language_module_t *m = NULL;
    language_task_t *ct = language_current_task;
    static language_value_t *require_func = NULL;
    if (require_func == NULL && language_base_module != NULL) {
        require_func = language_get_global(language_base_module, language_symbol("require"));
    }
    if (require_func != NULL) {
        size_t last_age = ct->world_age;
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        if (build_mode && language_require_world < ct->world_age)
            ct->world_age = language_require_world;
        language_value_t *reqargs[3];
        reqargs[0] = require_func;
        reqargs[1] = (language_value_t*)mod;
        reqargs[2] = (language_value_t*)var;
        m = (language_module_t*)language_apply(reqargs, 3);
        ct->world_age = last_age;
    }
    if (m == NULL || !language_is_module(m)) {
        language_errorf("failed to load module %s", language_symbol_name(var));
    }
    return m;
}

// either:
//   - sets *name and returns the module to import *name from
//   - sets *name to NULL and returns a module to import
static language_module_t *eval_import_path(language_module_t *where, language_module_t *from LANGUAGE_PROPAGATES_ROOT,
                                     language_array_t *args, language_sym_t **name, const char *keyword) LANGUAGE_GLOBALLY_ROOTED
{
    if (language_array_nrows(args) == 0)
        language_errorf("malformed \"%s\" statement", keyword);
    language_sym_t *var = (language_sym_t*)language_array_ptr_ref(args, 0);
    size_t i = 1;
    language_module_t *m = NULL;
    *name = NULL;
    if (!language_is_symbol(var))
        language_type_error(keyword, (language_value_t*)language_symbol_type, (language_value_t*)var);

    if (from != NULL) {
        m = from;
        i = 0;
    }
    else if (var != language_dot_sym) {
        // `A.B`: call the loader to obtain the root A in the current environment.
        if (language_core_module && var == language_core_module->name) {
            m = language_core_module;
        }
        else if (language_base_module && var == language_base_module->name) {
            m = language_base_module;
        }
        else {
            m = call_require(where, var);
        }
        if (i == language_array_nrows(args))
            return m;
    }
    else {
        // `.A.B.C`: strip off leading dots by following parent links
        m = where;
        while (1) {
            if (i >= language_array_nrows(args))
                language_error("invalid module path");
            var = (language_sym_t*)language_array_ptr_ref(args, i);
            if (var != language_dot_sym)
                break;
            i++;
            assert(m);
            m = m->parent;
        }
    }

    while (1) {
        var = (language_sym_t*)language_array_ptr_ref(args, i);
        if (!language_is_symbol(var))
            language_type_error(keyword, (language_value_t*)language_symbol_type, (language_value_t*)var);
        if (var == language_dot_sym)
            language_errorf("invalid %s path: \".\" in identifier path", keyword);
        if (i == language_array_nrows(args)-1)
            break;
        m = (language_module_t*)language_eval_global_var(m, var);
        LANGUAGE_GC_PROMISE_ROOTED(m);
        if (!language_is_module(m))
            language_errorf("invalid %s path: \"%s\" does not name a module", keyword, language_symbol_name(var));
        i++;
    }
    *name = var;
    return m;
}

int language_is_toplevel_only_expr(language_value_t *e) LANGUAGE_NOTSAFEPOINT
{
    return language_is_expr(e) &&
        (((language_expr_t*)e)->head == language_module_sym ||
         ((language_expr_t*)e)->head == language_import_sym ||
         ((language_expr_t*)e)->head == language_using_sym ||
         ((language_expr_t*)e)->head == language_export_sym ||
         ((language_expr_t*)e)->head == language_public_sym ||
         ((language_expr_t*)e)->head == language_thunk_sym ||
         ((language_expr_t*)e)->head == language_global_sym ||
         ((language_expr_t*)e)->head == language_const_sym ||
         ((language_expr_t*)e)->head == language_toplevel_sym ||
         ((language_expr_t*)e)->head == language_error_sym ||
         ((language_expr_t*)e)->head == language_incomplete_sym);
}

int language_needs_lowering(language_value_t *e) LANGUAGE_NOTSAFEPOINT
{
    if (!language_is_expr(e))
        return 0;
    language_expr_t *ex = (language_expr_t*)e;
    language_sym_t *head = ex->head;
    if (head == language_module_sym || head == language_import_sym || head == language_using_sym ||
        head == language_export_sym || head == language_public_sym || head == language_thunk_sym ||
        head == language_toplevel_sym || head == language_error_sym || head == language_incomplete_sym ||
        head == language_method_sym) {
        return 0;
    }
    if (head == language_global_sym || head == language_const_sym) {
        size_t i, l = language_array_nrows(ex->args);
        for (i = 0; i < l; i++) {
            language_value_t *a = language_exprarg(ex, i);
            if (!language_is_symbol(a) && !language_is_globalref(a))
                return 1;
        }
        return 0;
    }
    return 1;
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_new_codeinst_for_uninferred(language_method_instance_t *mi, language_code_info_t *src)
{
    // Do not compress this, we expect it to be shortlived.
    language_code_instance_t *ci = language_new_codeinst(mi, (language_value_t*)language_uninferred_sym,
        (language_value_t*)language_any_type, (language_value_t*)language_any_type, language_nothing,
        (language_value_t*)src, 0, src->min_world, src->max_world,
        0, 0, NULL, 1, NULL);
    return ci;
}

LANGUAGE_DLLEXPORT language_method_instance_t *language_method_instance_for_thunk(language_code_info_t *src, language_module_t *module)
{
    language_method_instance_t *mi = language_new_method_instance_uninit();
    mi->specTypes = (language_value_t*)language_emptytuple_type;
    mi->def.module = module;
    LANGUAGE_GC_PUSH1(&mi);

    language_code_instance_t *ci = language_new_codeinst_for_uninferred(mi, src);
    language_atomic_store_relaxed(&mi->cache, ci);
    language_gc_wb(mi, ci);

    LANGUAGE_GC_POP();
    return mi;
}

static void import_module(language_module_t *LANGUAGE_NONNULL m, language_module_t *import, language_sym_t *asname)
{
    assert(m);
    language_sym_t *name = asname ? asname : import->name;
    // TODO: this is a bit race-y with what error message we might print
    language_binding_t *b = language_get_module_binding(m, name, 0);
    language_binding_t *b2;
    if (b != NULL && (b2 = language_atomic_load_relaxed(&b->owner)) != NULL) {
        if (b2->constp && language_atomic_load_relaxed(&b2->value) == (language_value_t*)import)
            return;
        if (b2 != b)
            language_errorf("importing %s into %s conflicts with an existing global",
                      language_symbol_name(name), language_symbol_name(m->name));
    }
    else {
        b = language_get_binding_wr(m, name);
    }
    language_declare_constant(b, m, name);
    language_checked_assignment(b, m, name, (language_value_t*)import);
    b->imported = 1;
}

// in `import A.B: x, y, ...`, evaluate the `A.B` part if it exists
static language_module_t *eval_import_from(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_expr_t *ex, const char *keyword)
{
    if (language_expr_nargs(ex) == 1 && language_is_expr(language_exprarg(ex, 0))) {
        language_expr_t *fr = (language_expr_t*)language_exprarg(ex, 0);
        if (fr->head == language_colon_sym) {
            if (language_expr_nargs(fr) > 0 && language_is_expr(language_exprarg(fr, 0))) {
                language_expr_t *path = (language_expr_t*)language_exprarg(fr, 0);
                if (((language_expr_t*)path)->head == language_dot_sym) {
                    language_sym_t *name = NULL;
                    language_module_t *from = eval_import_path(m, NULL, path->args, &name, keyword);
                    if (name != NULL) {
                        from = (language_module_t*)language_eval_global_var(from, name);
                        if (!language_is_module(from))
                            language_errorf("invalid %s path: \"%s\" does not name a module", keyword, language_symbol_name(name));
                    }
                    return from;
                }
            }
            language_errorf("malformed \"%s:\" statement", keyword);
        }
    }
    return NULL;
}

static void check_macro_rename(language_sym_t *from, language_sym_t *to, const char *keyword)
{
    char *n1 = language_symbol_name(from), *n2 = language_symbol_name(to);
    if (n1[0] == '@' && n2[0] != '@')
        language_errorf("cannot rename macro \"%s\" to non-macro \"%s\" in \"%s\"", n1, n2, keyword);
    if (n1[0] != '@' && n2[0] == '@')
        language_errorf("cannot rename non-macro \"%s\" to macro \"%s\" in \"%s\"", n1, n2, keyword);
}

// Eval `throw(ErrorException(msg)))` in module `m`.
// Used in `language_toplevel_eval_flex` instead of `language_throw` so that the error
// location in julia code gets into the backtrace.
static void language_eval_throw(language_module_t *m, language_value_t *exc, const char *filename, int lineno)
{
    language_value_t *throw_ex = (language_value_t*)language_exprn(language_call_sym, 2);
    LANGUAGE_GC_PUSH1(&throw_ex);
    language_exprargset(throw_ex, 0, language_builtin_throw);
    language_exprargset(throw_ex, 1, exc);
    language_toplevel_eval_flex(m, throw_ex, 0, 0, &filename, &lineno);
    LANGUAGE_GC_POP();
}

// Format error message and call language_eval
static void language_eval_errorf(language_module_t *m, const char *filename, int lineno, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    language_value_t *exc = language_vexceptionf(language_errorexception_type, fmt, args);
    va_end(args);
    LANGUAGE_GC_PUSH1(&exc);
    language_eval_throw(m, exc, filename, lineno);
    LANGUAGE_GC_POP();
}

LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval_flex(language_module_t *LANGUAGE_NONNULL m, language_value_t *e, int fast, int expanded, const char **toplevel_filename, int *toplevel_lineno)
{
    language_task_t *ct = language_current_task;
    if (!language_is_expr(e)) {
        if (language_is_linenode(e)) {
            *toplevel_lineno = language_linenode_line(e);
            language_value_t *file = language_linenode_file(e);
            if (file != language_nothing) {
                assert(language_is_symbol(file));
                *toplevel_filename = language_symbol_name((language_sym_t*)file);
            }
            // Not thread safe. For debugging and last resort error messages (language_critical_error) only.
            language_filename = *toplevel_filename;
            language_lineno = *toplevel_lineno;
            return language_nothing;
        }
        if (language_is_symbol(e)) {
            char *n = language_symbol_name((language_sym_t*)e), *n0 = n;
            while (*n == '_') ++n;
            if (*n == 0 && n > n0)
                language_eval_errorf(m, *toplevel_filename, *toplevel_lineno, "all-underscore identifiers are write-only and their values cannot be used in expressions");
        }
        return language_interpret_toplevel_expr_in(m, e, NULL, NULL);
    }

    language_expr_t *ex = (language_expr_t*)e;

    if (ex->head == language_dot_sym && language_expr_nargs(ex) != 1) {
        if (language_expr_nargs(ex) != 2)
            language_eval_errorf(m, *toplevel_filename, *toplevel_lineno, "syntax: malformed \".\" expression");
        language_value_t *lhs = language_exprarg(ex, 0);
        language_value_t *rhs = language_exprarg(ex, 1);
        // only handle `a.b` syntax here, so qualified names can be eval'd in pure contexts
        if (language_is_quotenode(rhs) && language_is_symbol(language_fieldref(rhs, 0))) {
            return language_eval_dot_expr(m, lhs, rhs, fast, toplevel_filename, toplevel_lineno);
        }
    }

    if (ct->ptls->in_pure_callback) {
        language_error("eval cannot be used in a generated function");
    }

    language_method_instance_t *mfunc = NULL;
    language_code_info_t *thk = NULL;
    LANGUAGE_GC_PUSH3(&mfunc, &thk, &ex);

    size_t last_age = ct->world_age;
    if (!expanded && language_needs_lowering(e)) {
        ct->world_age = language_atomic_load_acquire(&language_world_counter);
        ex = (language_expr_t*)language_expand_with_loc_warn(e, m, *toplevel_filename, *toplevel_lineno);
        ct->world_age = last_age;
    }
    language_sym_t *head = language_is_expr(ex) ? ex->head : NULL;

    if (head == language_module_sym) {
        language_value_t *val = language_eval_module_expr(m, ex);
        LANGUAGE_GC_POP();
        return val;
    }
    else if (head == language_using_sym) {
        language_sym_t *name = NULL;
        language_module_t *from = eval_import_from(m, ex, "using");
        size_t i = 0;
        if (from) {
            i = 1;
            ex = (language_expr_t*)language_exprarg(ex, 0);
        }
        for (; i < language_expr_nargs(ex); i++) {
            language_value_t *a = language_exprarg(ex, i);
            if (language_is_expr(a) && ((language_expr_t*)a)->head == language_dot_sym) {
                name = NULL;
                language_module_t *import = eval_import_path(m, from, ((language_expr_t*)a)->args, &name, "using");
                language_module_t *u = import;
                if (name != NULL)
                    u = (language_module_t*)language_eval_global_var(import, name);
                if (from) {
                    // `using A: B` and `using A: B.c` syntax
                    language_module_use(m, import, name);
                }
                else {
                    if (!language_is_module(u))
                        language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                            "invalid using path: \"%s\" does not name a module",
                                       language_symbol_name(name));
                    // `using A` and `using A.B` syntax
                    language_module_using(m, u);
                    if (m == language_main_module && name == NULL) {
                        // TODO: for now, `using A` in Main also creates an explicit binding for `A`
                        // This will possibly be extended to all modules.
                        import_module(m, u, NULL);
                    }
                }
                continue;
            }
            else if (from && language_is_expr(a) && ((language_expr_t*)a)->head == language_as_sym && language_expr_nargs(a) == 2 &&
                     language_is_expr(language_exprarg(a, 0)) && ((language_expr_t*)language_exprarg(a, 0))->head == language_dot_sym) {
                language_sym_t *asname = (language_sym_t*)language_exprarg(a, 1);
                if (language_is_symbol(asname)) {
                    language_expr_t *path = (language_expr_t*)language_exprarg(a, 0);
                    name = NULL;
                    language_module_t *import = eval_import_path(m, from, ((language_expr_t*)path)->args, &name, "using");
                    assert(name);
                    check_macro_rename(name, asname, "using");
                    // `using A: B as C` syntax
                    language_module_use_as(m, import, name, asname);
                    continue;
                }
            }
            language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                "syntax: malformed \"using\" statement");
        }
        LANGUAGE_GC_POP();
        return language_nothing;
    }
    else if (head == language_import_sym) {
        language_sym_t *name = NULL;
        language_module_t *from = eval_import_from(m, ex, "import");
        size_t i = 0;
        if (from) {
            i = 1;
            ex = (language_expr_t*)language_exprarg(ex, 0);
        }
        for (; i < language_expr_nargs(ex); i++) {
            language_value_t *a = language_exprarg(ex, i);
            if (language_is_expr(a) && ((language_expr_t*)a)->head == language_dot_sym) {
                name = NULL;
                language_module_t *import = eval_import_path(m, from, ((language_expr_t*)a)->args, &name, "import");
                if (name == NULL) {
                    // `import A` syntax
                    import_module(m, import, NULL);
                }
                else {
                    // `import A.B` or `import A: B` syntax
                    language_module_import(m, import, name);
                }
                continue;
            }
            else if (language_is_expr(a) && ((language_expr_t*)a)->head == language_as_sym && language_expr_nargs(a) == 2 &&
                     language_is_expr(language_exprarg(a, 0)) && ((language_expr_t*)language_exprarg(a, 0))->head == language_dot_sym) {
                language_sym_t *asname = (language_sym_t*)language_exprarg(a, 1);
                if (language_is_symbol(asname)) {
                    language_expr_t *path = (language_expr_t*)language_exprarg(a, 0);
                    name = NULL;
                    language_module_t *import = eval_import_path(m, from, ((language_expr_t*)path)->args, &name, "import");
                    if (name == NULL) {
                        // `import A as B` syntax
                        import_module(m, import, asname);
                    }
                    else {
                        check_macro_rename(name, asname, "import");
                        // `import A.B as C` syntax
                        language_module_import_as(m, import, name, asname);
                    }
                    continue;
                }
            }
            language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                "syntax: malformed \"import\" statement");
        }
        LANGUAGE_GC_POP();
        return language_nothing;
    }
    else if (head == language_export_sym || head == language_public_sym) {
        int exp = (head == language_export_sym);
        for (size_t i = 0; i < language_array_nrows(ex->args); i++) {
            language_sym_t *name = (language_sym_t*)language_array_ptr_ref(ex->args, i);
            if (!language_is_symbol(name))
                language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                     exp ? "syntax: malformed \"export\" statement" :
                           "syntax: malformed \"public\" statement");
            language_module_public(m, name, exp);
        }
        LANGUAGE_GC_POP();
        return language_nothing;
    }
    else if (head == language_global_sym) {
        language_eval_global_expr(m, ex, 0);
        LANGUAGE_GC_POP();
        return language_nothing;
    }
    else if (head == language_const_sym) {
        language_sym_t *arg = (language_sym_t*)language_exprarg(ex, 0);
        language_module_t *gm;
        language_sym_t *gs;
        if (language_is_globalref(arg)) {
            gm = language_globalref_mod(arg);
            gs = language_globalref_name(arg);
        }
        else {
            assert(language_is_symbol(arg));
            gm = m;
            gs = (language_sym_t*)arg;
        }
        language_binding_t *b = language_get_binding_wr(gm, gs);
        language_declare_constant(b, gm, gs);
        LANGUAGE_GC_POP();
        return language_nothing;
    }
    else if (head == language_toplevel_sym) {
        language_value_t *res = language_nothing;
        int i;
        for (i = 0; i < language_array_nrows(ex->args); i++) {
            res = language_toplevel_eval_flex(m, language_array_ptr_ref(ex->args, i), fast, 0, toplevel_filename, toplevel_lineno);
        }
        LANGUAGE_GC_POP();
        return res;
    }
    else if (head == language_error_sym || head == language_incomplete_sym) {
        if (language_expr_nargs(ex) == 0)
            language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                "malformed \"%s\" expression", language_symbol_name(head));
        if (language_is_string(language_exprarg(ex, 0)))
            language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
                "syntax: %s", language_string_data(language_exprarg(ex, 0)));
        language_eval_throw(m, language_exprarg(ex, 0), *toplevel_filename, *toplevel_lineno);
    }
    else if (language_is_symbol(ex)) {
        LANGUAGE_GC_POP();
        return language_eval_global_var(m, (language_sym_t*)ex);
    }
    else if (head == NULL) {
        LANGUAGE_GC_POP();
        return (language_value_t*)ex;
    }

    int has_ccall = 0, has_defs = 0, has_loops = 0, has_opaque = 0, forced_compile = 0;
    assert(head == language_thunk_sym);
    thk = (language_code_info_t*)language_exprarg(ex, 0);
    if (!language_is_code_info(thk) || !language_typetagis(thk->code, language_array_any_type)) {
        language_eval_errorf(m, *toplevel_filename, *toplevel_lineno,
            "malformed \"thunk\" statement");
    }
    body_attributes((language_array_t*)thk->code, &has_ccall, &has_defs, &has_loops, &has_opaque, &forced_compile);

    language_value_t *result;
    if (has_ccall ||
            ((forced_compile || (!has_defs && fast && has_loops)) &&
            language_options.compile_enabled != LANGUAGE_OPTIONS_COMPILE_OFF &&
            language_options.compile_enabled != LANGUAGE_OPTIONS_COMPILE_MIN &&
            language_get_module_compile(m) != LANGUAGE_OPTIONS_COMPILE_OFF &&
            language_get_module_compile(m) != LANGUAGE_OPTIONS_COMPILE_MIN)) {
        // use codegen
        mfunc = language_method_instance_for_thunk(thk, m);
        language_resolve_globals_in_ir((language_array_t*)thk->code, m, NULL, 0);
        // Don't infer blocks containing e.g. method definitions, since it's probably not
        // worthwhile and also unsound (see #24316).
        // TODO: This is still not correct since an `eval` can happen elsewhere, but it
        // helps in common cases.
        size_t world = language_atomic_load_acquire(&language_world_counter);
        ct->world_age = world;
        if (!has_defs && language_get_module_infer(m) != 0) {
            (void)language_type_infer(mfunc, world, 0, SOURCE_MODE_NOT_REQUIRED);
        }
        result = language_invoke(/*func*/NULL, /*args*/NULL, /*nargs*/0, mfunc);
        ct->world_age = last_age;
    }
    else {
        // use interpreter
        assert(thk);
        if (has_opaque) {
            language_resolve_globals_in_ir((language_array_t*)thk->code, m, NULL, 0);
        }
        result = language_interpret_toplevel_thunk(m, thk);
    }

    LANGUAGE_GC_POP();
    return result;
}

LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval(language_module_t *m, language_value_t *v)
{
    const char *filename = language_filename;
    int lieno = language_lineno;
    return language_toplevel_eval_flex(m, v, 1, 0, &filename, &lieno);
}

// Check module `m` is open for `eval/include`, or throw an error.
LANGUAGE_DLLEXPORT void language_check_top_level_effect(language_module_t *m, char *fname)
{
    if (language_current_task->ptls->in_pure_callback)
        language_errorf("%s cannot be used in a generated function", fname);
    if (language_options.incremental && language_generating_output()) {
        if (m != language_main_module) { // TODO: this was grand-fathered in
            LANGUAGE_LOCK(&language_modules_mutex);
            int open = ptrhash_has(&language_current_modules, (void*)m);
            if (!open && language_module_init_order != NULL) {
                size_t i, l = language_array_nrows(language_module_init_order);
                for (i = 0; i < l; i++) {
                    if (m == (language_module_t*)language_array_ptr_ref(language_module_init_order, i)) {
                        open = 1;
                        break;
                    }
                }
            }
            LANGUAGE_UNLOCK(&language_modules_mutex);
            if (!open && !language_is__toplevel__mod(m)) {
                const char* name = language_symbol_name(m->name);
                language_errorf("Evaluation into the closed module `%s` breaks incremental compilation "
                          "because the side effects will not be permanent. "
                          "This is likely due to some other module mutating `%s` with `%s` during "
                          "precompilation - don't do this.", name, name, fname);
            }
        }
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval_in(language_module_t *m, language_value_t *ex)
{
    language_check_top_level_effect(m, "eval");
    language_value_t *v = NULL;
    int last_lineno = language_lineno;
    const char *last_filename = language_filename;
    language_lineno = 1;
    language_filename = "none";
    LANGUAGE_TRY {
        v = language_toplevel_eval(m, ex);
    }
    LANGUAGE_CATCH {
        language_lineno = last_lineno;
        language_filename = last_filename;
        language_rethrow();
    }
    language_lineno = last_lineno;
    language_filename = last_filename;
    assert(v);
    return v;
}

LANGUAGE_DLLEXPORT language_value_t *language_infer_thunk(language_code_info_t *thk, language_module_t *m)
{
    language_method_instance_t *li = language_method_instance_for_thunk(thk, m);
    LANGUAGE_GC_PUSH1(&li);
    language_resolve_globals_in_ir((language_array_t*)thk->code, m, NULL, 0);
    language_task_t *ct = language_current_task;
    language_code_instance_t *ci = language_type_infer(li, ct->world_age, 0, SOURCE_MODE_NOT_REQUIRED);
    LANGUAGE_GC_POP();
    if (ci)
        return ci->rettype;
    return (language_value_t*)language_any_type;
}


//------------------------------------------------------------------------------
// Code loading: combined parse+eval for include()

// Parse julia code from the string `text` at top level, attributing it to
// `filename`. This is used during bootstrap, but the real Base.include() is
// implemented in Julia code.
static language_value_t *language_parse_eval_all(language_module_t *module, language_value_t *text,
                                     language_value_t *filename)
{
    if (!language_is_string(text) || !language_is_string(filename)) {
        language_errorf("Expected `String`s for `text` and `filename`");
    }
    language_check_top_level_effect(module, "include");

    language_value_t *result = language_nothing;
    language_value_t *ast = NULL;
    language_value_t *expression = NULL;
    LANGUAGE_GC_PUSH3(&ast, &result, &expression);

    ast = language_svecref(language_parse(language_string_data(text), language_string_len(text),
                              filename, 1, 0, (language_value_t*)language_all_sym), 0);
    if (!language_is_expr(ast) || ((language_expr_t*)ast)->head != language_toplevel_sym) {
        language_errorf("language_parse_all() must generate a top level expression");
    }

    language_task_t *ct = language_current_task;
    int last_lineno = language_lineno;
    const char *last_filename = language_filename;
    size_t last_age = ct->world_age;
    int lineno = 0;
    language_lineno = 0;
    const char *filename_str = language_string_data(filename);
    language_filename = filename_str;
    int err = 0;

    LANGUAGE_TRY {
        for (size_t i = 0; i < language_expr_nargs(ast); i++) {
            expression = language_exprarg(ast, i);
            if (language_is_linenode(expression)) {
                // filename is already set above.
                lineno = language_linenode_line(expression);
                language_lineno = lineno;
                continue;
            }
            expression = language_expand_with_loc_warn(expression, module,
                                                 language_string_data(filename), lineno);
            ct->world_age = language_atomic_load_acquire(&language_world_counter);
            result = language_toplevel_eval_flex(module, expression, 1, 1, &filename_str, &lineno);
        }
    }
    LANGUAGE_CATCH {
        result = language_box_long(language_lineno); // (ab)use result to root error line
        err = 1;
        goto finally; // skip language_restore_excstack
    }
finally:
    ct->world_age = last_age;
    language_lineno = last_lineno;
    language_filename = last_filename;
    if (err) {
        if (language_loaderror_type == NULL)
            language_rethrow();
        else
            language_rethrow_other(language_new_struct(language_loaderror_type, filename, result,
                                           language_current_exception(ct)));
    }
    LANGUAGE_GC_POP();
    return result;
}

// Synchronously read content of entire file into a julia String
static language_value_t *language_file_content_as_string(language_value_t *filename)
{
    const char *fname = language_string_data(filename);
    ios_t f;
    if (ios_file(&f, fname, 1, 0, 0, 0) == NULL)
        language_errorf("File \"%s\" not found", fname);
    ios_bufmode(&f, bm_none);
    ios_seek_end(&f);
    size_t len = ios_pos(&f);
    language_value_t *text = language_alloc_string(len);
    ios_seek(&f, 0);
    if (ios_readall(&f, language_string_data(text), len) != len)
        language_errorf("Error reading file \"%s\"", fname);
    ios_close(&f);
    return text;
}

// Load and parse julia code from the file `filename`. Eval the resulting
// statements into `module` after applying `mapexpr` to each one.
LANGUAGE_DLLEXPORT language_value_t *language_load_(language_module_t *module, language_value_t *filename)
{
    language_value_t *text = language_file_content_as_string(filename);
    LANGUAGE_GC_PUSH1(&text);
    language_value_t *result = language_parse_eval_all(module, text, filename);
    LANGUAGE_GC_POP();
    return result;
}

// Code loading - code.h C API with native C types

// Parse julia code from `filename` and eval into `module`.
LANGUAGE_DLLEXPORT language_value_t *language_load(language_module_t *module, const char *filename)
{
    language_value_t *filename_ = NULL;
    LANGUAGE_GC_PUSH1(&filename_);
    filename_ = language_cstr_to_string(filename);
    language_value_t *result = language_load_(module, filename_);
    LANGUAGE_GC_POP();
    return result;
}

// Parse julia code from the string `text` of length `len`, attributing it to
// `filename`. Eval the resulting statements into `module`.
LANGUAGE_DLLEXPORT language_value_t *language_load_file_string(const char *text, size_t len,
                                             char *filename, language_module_t *module)
{
    language_value_t *text_ = NULL;
    language_value_t *filename_ = NULL;
    LANGUAGE_GC_PUSH2(&text_, &filename_);
    text_ = language_pchar_to_string(text, len);
    filename_ = language_cstr_to_string(filename);
    language_value_t *result = language_parse_eval_all(module, text_, filename_);
    LANGUAGE_GC_POP();
    return result;
}


//--------------------------------------------------
// Code loading helpers for bootstrap

LANGUAGE_DLLEXPORT language_value_t *language_prepend_cwd(language_value_t *str)
{
    size_t sz = 1024;
    char path[1024];
    int c = uv_cwd(path, &sz);
    if (c < 0) {
        language_errorf("could not get current directory");
    }
    path[sz] = '/';  // fix later with normpath if Windows
    const char *fstr = (const char*)language_string_data(str);
    if (strlen(fstr) + sz >= 1024) {
        language_errorf("use a bigger buffer for language_fullpath");
    }
    strcpy(path + sz + 1, fstr);
    return language_cstr_to_string(path);
}

#ifdef __cplusplus
}
#endif
