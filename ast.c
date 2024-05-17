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
  AST
  components of the front-end, for obtaining and translating syntax trees
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _OS_WINDOWS_
#include <malloc.h>
#endif
#include "code.h"
#include "language_internal.h"
#include "flisp.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// head symbols for each expression type
LANGUAGE_DLLEXPORT language_sym_t *language_call_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_invoke_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_invoke_modify_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_empty_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_top_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_module_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_slot_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_export_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_public_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_import_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_toplevel_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_quote_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_line_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_incomplete_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_goto_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_goto_ifnot_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_return_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_lineinfo_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_lambda_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_assign_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_globalref_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_do_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_method_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_core_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_enter_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_leave_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_pop_exception_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_exc_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_error_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_new_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_using_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_splatnew_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_block_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_new_opaque_closure_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_opaque_closure_method_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_const_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_thunk_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_foreigncall_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_as_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_global_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_local_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_list_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_dot_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_newvar_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_boundscheck_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_inbounds_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_copyast_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_cfunction_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_loopinfo_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_meta_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_inert_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_polly_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_unused_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_static_parameter_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_inline_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_noinline_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_generated_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_generated_only_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_isdefined_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_propagate_inbounds_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_specialize_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_aggressive_constprop_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_no_constprop_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_purity_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_nospecialize_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_nospecializeinfer_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_macrocall_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_colon_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_hygienicscope_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_throw_undef_if_not_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_getfield_undefref_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_gc_preserve_begin_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_gc_preserve_end_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_coverageeffect_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_escape_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_aliasscope_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_popaliasscope_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_optlevel_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_thismodule_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_eval_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_include_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_atom_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_statement_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_all_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_compile_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_force_compile_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_infer_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_max_methods_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_atomic_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_not_atomic_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_unordered_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_monotonic_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_acquire_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_release_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_acquire_release_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_sequentially_consistent_sym;
LANGUAGE_DLLEXPORT language_sym_t *language_uninferred_sym;

static const uint8_t flisp_system_image[] = {
#include <language_flisp.boot.inc>
};

typedef struct _language_ast_context_t {
    fl_context_t fl;
    fltype_t *jvtype;

    value_t true_sym;
    value_t false_sym;
    value_t error_sym;
    value_t null_sym;
    value_t ssavalue_sym;
    value_t slot_sym;
    language_module_t *module; // context module for `current-julia-module-counter`
    struct _language_ast_context_t *next; // invasive list pointer for getting free contexts
} language_ast_context_t;

static language_ast_context_t language_ast_main_ctx;

#ifdef __clang_gcanalyzer__
language_ast_context_t *language_ast_ctx(fl_context_t *fl) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT;
#else
#define language_ast_ctx(fl_ctx) container_of(fl_ctx, language_ast_context_t, fl)
#endif

struct macroctx_stack {
    language_module_t *m;
    struct macroctx_stack *parent;
};

static language_value_t *scm_to_julia(fl_context_t *fl_ctx, value_t e, language_module_t *mod);
static value_t language_to_scm(fl_context_t *fl_ctx, language_value_t *v);
static language_value_t *language_expand_macros(language_value_t *expr, language_module_t *inmodule, struct macroctx_stack *macroctx, int onelevel, size_t world, int throw_load_error);

static language_sym_t *scmsym_to_julia(fl_context_t *fl_ctx, value_t s)
{
    assert(issymbol(s));
    if (fl_isgensym(fl_ctx, s)) {
        char gsname[16];
        char *n = uint2str(&gsname[1], sizeof(gsname)-1,
                           ((gensym_t*)ptr(s))->id, 10);
        *(--n) = '#';
        return language_symbol(n);
    }
    return language_symbol(symbol_name(fl_ctx, s));
}

static value_t fl_defined_language_global(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    // tells whether a var is defined in and *by* the current module
    argcount(fl_ctx, "defined-julia-global", nargs, 1);
    (void)tosymbol(fl_ctx, args[0], "defined-julia-global");
    language_ast_context_t *ctx = language_ast_ctx(fl_ctx);
    language_sym_t *var = scmsym_to_julia(fl_ctx, args[0]);
    language_binding_t *b = language_get_module_binding(ctx->module, var, 0);
    return (b != NULL && language_atomic_load_relaxed(&b->owner) == b) ? fl_ctx->T : fl_ctx->F;
}

static value_t fl_nothrow_language_global(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    // tells whether a var is defined, in the sense that accessing it is nothrow
    // can take either a symbol or a module and a symbol
    language_ast_context_t *ctx = language_ast_ctx(fl_ctx);
    language_module_t *mod = ctx->module;
    language_sym_t *var = NULL;
    if (nargs == 1) {
        (void)tosymbol(fl_ctx, args[0], "nothrow-julia-global");
        var = scmsym_to_julia(fl_ctx, args[0]);
    }
    else {
        argcount(fl_ctx, "nothrow-julia-global", nargs, 2);
        value_t argmod = args[0];
        if (iscvalue(argmod) && cv_class((cvalue_t*)ptr(argmod)) == language_ast_ctx(fl_ctx)->jvtype) {
            mod = *(language_module_t**)cv_data((cvalue_t*)ptr(argmod));
            LANGUAGE_GC_PROMISE_ROOTED(mod);
        } else {
            (void)tosymbol(fl_ctx, argmod, "nothrow-julia-global");
            if (scmsym_to_julia(fl_ctx, argmod) != language_thismodule_sym) {
                lerrorf(fl_ctx, fl_ctx->ArgError, "nothrow-julia-global: Unknown globalref module kind");
            }
        }
        (void)tosymbol(fl_ctx, args[1], "nothrow-julia-global");
        var = scmsym_to_julia(fl_ctx, args[1]);
    }
    language_binding_t *b = language_get_module_binding(mod, var, 0);
    b = b ? language_atomic_load_relaxed(&b->owner) : NULL;
    return b != NULL && language_atomic_load_relaxed(&b->value) != NULL ? fl_ctx->T : fl_ctx->F;
}

static value_t fl_current_module_counter(fl_context_t *fl_ctx, value_t *args, uint32_t nargs) LANGUAGE_NOTSAFEPOINT
{
    language_ast_context_t *ctx = language_ast_ctx(fl_ctx);
    assert(ctx->module);
    return fixnum(language_module_next_counter(ctx->module));
}

static int language_is_number(language_value_t *v)
{
    language_datatype_t *t = (language_datatype_t*)language_typeof(v);
    for (; t->super != t; t = t->super)
        if (t == language_number_type)
            return 1;
    return 0;
}

// Check whether v is a scalar for purposes of inlining fused-broadcast
// arguments when lowering; should agree with broadcast.jl on what is a
// scalar.  When in doubt, return false, since this is only an optimization.
static value_t fl_language_scalar(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    argcount(fl_ctx, "julia-scalar?", nargs, 1);
    if (fl_isnumber(fl_ctx, args[0]) || fl_isstring(fl_ctx, args[0]))
        return fl_ctx->T;
    else if (iscvalue(args[0]) && fl_ctx->language_sym == cv_type((cvalue_t*)ptr(args[0]))) {
        language_value_t *v = *(language_value_t**)cptr(args[0]);
        if (language_is_number(v) || language_is_string(v))
            return fl_ctx->T;
    }
    return fl_ctx->F;
}

static language_value_t *scm_to_language_(fl_context_t *fl_ctx, value_t e, language_module_t *mod);

static const builtinspec_t language_flisp_ast_ext[] = {
    { "defined-julia-global", fl_defined_language_global }, // TODO: can we kill this safepoint
    { "nothrow-julia-global", fl_nothrow_language_global },
    { "current-julia-module-counter", fl_current_module_counter },
    { "julia-scalar?", fl_language_scalar },
    { NULL, NULL }
};

static void language_init_ast_ctx(language_ast_context_t *ctx) LANGUAGE_NOTSAFEPOINT
{
    fl_context_t *fl_ctx = &ctx->fl;
    fl_init(fl_ctx, 4*1024*1024);

    if (fl_load_system_image_str(fl_ctx, (char*)flisp_system_image,
                                 sizeof(flisp_system_image))) {
        language_error("fatal error loading system image");
    }

    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "__init_globals")));

    ctx->jvtype = define_opaque_type(fl_ctx->language_sym, sizeof(void*), NULL, NULL);
    assign_global_builtins(fl_ctx, language_flisp_ast_ext);
    ctx->true_sym = symbol(fl_ctx, "true");
    ctx->false_sym = symbol(fl_ctx, "false");
    ctx->error_sym = symbol(fl_ctx, "error");
    ctx->null_sym = symbol(fl_ctx, "null");
    ctx->ssavalue_sym = symbol(fl_ctx, "ssavalue");
    ctx->slot_sym = symbol(fl_ctx, "slot");
    ctx->module = NULL;
    set(symbol(fl_ctx, "*scopewarn-opt*"), fixnum(language_options.warn_scope));
}

// There should be no GC allocation while holding this lock
static uv_mutex_t flisp_lock;
static language_ast_context_t *language_ast_ctx_freed = NULL;

static language_ast_context_t *language_ast_ctx_enter(language_module_t *m) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT
{
    LANGUAGE_SIGATOMIC_BEGIN();
    uv_mutex_lock(&flisp_lock);
    language_ast_context_t *ctx = language_ast_ctx_freed;
    if (ctx != NULL) {
        language_ast_ctx_freed = ctx->next;
        ctx->next = NULL;
    }
    uv_mutex_unlock(&flisp_lock);
    if (ctx == NULL) {
        // Construct a new one if we can't find any
        ctx = (language_ast_context_t*)calloc(1, sizeof(language_ast_context_t));
        language_init_ast_ctx(ctx);
    }
    ctx->module = m;
    return ctx;
}

static void language_ast_ctx_leave(language_ast_context_t *ctx)
{
    uv_mutex_lock(&flisp_lock);
    ctx->module = NULL;
    ctx->next = language_ast_ctx_freed;
    language_ast_ctx_freed = ctx;
    uv_mutex_unlock(&flisp_lock);
    LANGUAGE_SIGATOMIC_END();
}

void language_init_flisp(void)
{
    if (language_ast_ctx_freed)
        return;
    uv_mutex_init(&flisp_lock);
    language_init_ast_ctx(&language_ast_main_ctx);
    // To match the one in language_ast_ctx_leave
    LANGUAGE_SIGATOMIC_BEGIN();
    language_ast_ctx_leave(&language_ast_main_ctx);
}

void language_init_common_symbols(void)
{
    language_empty_sym = language_symbol("");
    language_call_sym = language_symbol("call");
    language_invoke_sym = language_symbol("invoke");
    language_invoke_modify_sym = language_symbol("invoke_modify");
    language_foreigncall_sym = language_symbol("foreigncall");
    language_cfunction_sym = language_symbol("cfunction");
    language_quote_sym = language_symbol("quote");
    language_inert_sym = language_symbol("inert");
    language_top_sym = language_symbol("top");
    language_core_sym = language_symbol("core");
    language_globalref_sym = language_symbol("globalref");
    language_line_sym = language_symbol("line");
    language_lineinfo_sym = language_symbol("lineinfo");
    language_incomplete_sym = language_symbol("incomplete");
    language_error_sym = language_symbol("error");
    language_goto_sym = language_symbol("goto");
    language_goto_ifnot_sym = language_symbol("gotoifnot");
    language_return_sym = language_symbol("return");
    language_lambda_sym = language_symbol("lambda");
    language_module_sym = language_symbol("module");
    language_export_sym = language_symbol("export");
    language_public_sym = language_symbol("public");
    language_import_sym = language_symbol("import");
    language_using_sym = language_symbol("using");
    language_assign_sym = language_symbol("=");
    language_method_sym = language_symbol("method");
    language_exc_sym = language_symbol("the_exception");
    language_enter_sym = language_symbol("enter");
    language_leave_sym = language_symbol("leave");
    language_pop_exception_sym = language_symbol("pop_exception");
    language_new_sym = language_symbol("new");
    language_splatnew_sym = language_symbol("splatnew");
    language_new_opaque_closure_sym = language_symbol("new_opaque_closure");
    language_opaque_closure_method_sym = language_symbol("opaque_closure_method");
    language_const_sym = language_symbol("const");
    language_global_sym = language_symbol("global");
    language_local_sym = language_symbol("local");
    language_thunk_sym = language_symbol("thunk");
    language_toplevel_sym = language_symbol("toplevel");
    language_dot_sym = language_symbol(".");
    language_as_sym = language_symbol("as");
    language_colon_sym = language_symbol(":");
    language_boundscheck_sym = language_symbol("boundscheck");
    language_inbounds_sym = language_symbol("inbounds");
    language_newvar_sym = language_symbol("newvar");
    language_copyast_sym = language_symbol("copyast");
    language_loopinfo_sym = language_symbol("loopinfo");
    language_meta_sym = language_symbol("meta");
    language_list_sym = language_symbol("list");
    language_unused_sym = language_symbol("#unused#");
    language_slot_sym = language_symbol("slot");
    language_static_parameter_sym = language_symbol("static_parameter");
    language_inline_sym = language_symbol("inline");
    language_noinline_sym = language_symbol("noinline");
    language_polly_sym = language_symbol("polly");
    language_propagate_inbounds_sym = language_symbol("propagate_inbounds");
    language_aggressive_constprop_sym = language_symbol("aggressive_constprop");
    language_no_constprop_sym = language_symbol("no_constprop");
    language_purity_sym = language_symbol("purity");
    language_isdefined_sym = language_symbol("isdefined");
    language_nospecialize_sym = language_symbol("nospecialize");
    language_specialize_sym = language_symbol("specialize");
    language_nospecializeinfer_sym = language_symbol("nospecializeinfer");
    language_optlevel_sym = language_symbol("optlevel");
    language_compile_sym = language_symbol("compile");
    language_force_compile_sym = language_symbol("force_compile");
    language_infer_sym = language_symbol("infer");
    language_max_methods_sym = language_symbol("max_methods");
    language_macrocall_sym = language_symbol("macrocall");
    language_escape_sym = language_symbol("escape");
    language_hygienicscope_sym = language_symbol("hygienic-scope");
    language_gc_preserve_begin_sym = language_symbol("gc_preserve_begin");
    language_gc_preserve_end_sym = language_symbol("gc_preserve_end");
    language_generated_sym = language_symbol("generated");
    language_generated_only_sym = language_symbol("generated_only");
    language_throw_undef_if_not_sym = language_symbol("throw_undef_if_not");
    language_getfield_undefref_sym = language_symbol("##getfield##");
    language_do_sym = language_symbol("do");
    language_coverageeffect_sym = language_symbol("code_coverage_effect");
    language_aliasscope_sym = language_symbol("aliasscope");
    language_popaliasscope_sym = language_symbol("popaliasscope");
    language_thismodule_sym = language_symbol("thismodule");
    language_eval_sym = language_symbol("eval");
    language_include_sym = language_symbol("include");
    language_block_sym = language_symbol("block");
    language_atom_sym = language_symbol("atom");
    language_statement_sym = language_symbol("statement");
    language_all_sym = language_symbol("all");
    language_atomic_sym = language_symbol("atomic");
    language_not_atomic_sym = language_symbol("not_atomic");
    language_unordered_sym = language_symbol("unordered");
    language_monotonic_sym = language_symbol("monotonic");
    language_acquire_sym = language_symbol("acquire");
    language_release_sym = language_symbol("release");
    language_acquire_release_sym = language_symbol("acquire_release");
    language_sequentially_consistent_sym = language_symbol("sequentially_consistent");
    language_uninferred_sym = language_symbol("uninferred");
}

LANGUAGE_DLLEXPORT void language_lisp_prompt(void)
{
    // Make `--lisp` sigatomic in order to avoid triggering the sigint safepoint.
    // We don't have our signal handler registered in that case anyway...
    LANGUAGE_SIGATOMIC_BEGIN();
    language_init_flisp();
    language_ast_context_t *ctx = language_ast_ctx_enter(language_main_module);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "__start")), fl_cons(fl_ctx, fl_ctx->NIL,fl_ctx->NIL));
    language_ast_ctx_leave(ctx);
}

LANGUAGE_DLLEXPORT void fl_show_profile(void)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "show-profiles")));
    language_ast_ctx_leave(ctx);
}

LANGUAGE_DLLEXPORT void fl_clear_profile(void)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "clear-profiles")));
    language_ast_ctx_leave(ctx);
}

LANGUAGE_DLLEXPORT void fl_profile(const char *fname)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "profile-e")), symbol(fl_ctx, fname));
    language_ast_ctx_leave(ctx);
}

static language_value_t *scm_to_julia(fl_context_t *fl_ctx, value_t e, language_module_t *mod)
{
    language_value_t *v = NULL;
    LANGUAGE_GC_PUSH1(&v);
    LANGUAGE_TRY {
        v = scm_to_language_(fl_ctx, e, mod);
    }
    LANGUAGE_CATCH {
        // if expression cannot be converted, replace with error expr
        //code_(language_current_exception(ct));
        //jlbacktrace();
        language_expr_t *ex = language_exprn(language_error_sym, 1);
        v = (language_value_t*)ex;
        language_array_ptr_set(ex->args, 0, language_cstr_to_string("invalid AST"));
    }
    LANGUAGE_GC_POP();
    return v;
}

extern int64_t conv_to_int64(void *data, numerictype_t tag);

static language_value_t *scm_to_language_(fl_context_t *fl_ctx, value_t e, language_module_t *mod)
{
    if (fl_isnumber(fl_ctx, e)) {
        int64_t i64;
        if (isfixnum(e)) {
            i64 = numval(e);
        }
        else {
            assert(iscprim(e));
            cprim_t *cp = (cprim_t*)ptr(e);
            numerictype_t nt = cp_numtype(cp);
            switch (nt) {
            case T_DOUBLE:
                return (language_value_t*)language_box_float64(*(double*)cp_data(cp));
            case T_FLOAT:
                return (language_value_t*)language_box_float32(*(float*)cp_data(cp));
            case T_UINT8:
                return (language_value_t*)language_box_uint8(*(uint8_t*)cp_data(cp));
            case T_UINT16:
                return (language_value_t*)language_box_uint16(*(uint16_t*)cp_data(cp));
            case T_UINT32:
                return (language_value_t*)language_box_uint32(*(uint32_t*)cp_data(cp));
            case T_UINT64:
                return (language_value_t*)language_box_uint64(*(uint64_t*)cp_data(cp));
            default:
                ;
            }
            i64 = conv_to_int64(cp_data(cp), nt);
        }
#ifdef _P64
        return (language_value_t*)language_box_int64(i64);
#else
        if (i64 > (int64_t)S32_MAX || i64 < (int64_t)S32_MIN)
            return (language_value_t*)language_box_int64(i64);
        else
            return (language_value_t*)language_box_int32((int32_t)i64);
#endif
    }
    if (issymbol(e))
        return (language_value_t*)scmsym_to_julia(fl_ctx, e);
    if (fl_isstring(fl_ctx, e))
        return language_pchar_to_string((char*)cvalue_data(e), cvalue_len(e));
    if (iscons(e) || e == fl_ctx->NIL) {
        value_t hd;
        language_sym_t *sym;
        if (e == fl_ctx->NIL) {
            hd = e;
        }
        else {
            hd = car_(e);
            if (hd == language_ast_ctx(fl_ctx)->ssavalue_sym)
                return language_box_ssavalue(numval(car_(cdr_(e))));
            else if (hd == language_ast_ctx(fl_ctx)->slot_sym)
                return language_box_slotnumber(numval(car_(cdr_(e))));
            else if (hd == language_ast_ctx(fl_ctx)->null_sym && llength(e) == 1)
                return language_nothing;
            else if (hd == language_ast_ctx(fl_ctx)->true_sym && llength(e) == 1)
                return language_true;
            else if (hd == language_ast_ctx(fl_ctx)->false_sym && llength(e) == 1)
                return language_false;
            else if (hd == fl_ctx->language_char_sym && llength(e) == 2) {
                value_t v = car_(cdr_(e));
                if (!(iscprim(v) && cp_class((cprim_t*)ptr(v)) == fl_ctx->uint32type))
                    language_error("malformed julia char");
                uint32_t c = *(uint32_t*)cp_data((cprim_t*)ptr(v));
                return language_box_char(c);
            }
        }
        if (issymbol(hd))
            sym = scmsym_to_julia(fl_ctx, hd);
        else
            sym = language_list_sym;
        size_t n = llength(e)-1;
        if (issymbol(hd))
            e = cdr_(e);
        else
            n++;
        // nodes with special representations
        language_value_t *ex = NULL, *temp = NULL;
        if (sym == language_line_sym && (n == 1 || n == 2)) {
            language_value_t *linenum = scm_to_language_(fl_ctx, car_(e), mod);
            language_value_t *file = language_nothing;
            LANGUAGE_GC_PUSH2(&linenum, &file);
            if (n == 2)
                file = scm_to_language_(fl_ctx, car_(cdr_(e)), mod);
            temp = language_new_struct(language_linenumbernode_type, linenum, file);
            LANGUAGE_GC_POP();
            return temp;
        }
        else if (sym == language_lineinfo_sym && n == 3) {
            language_value_t *file=NULL, *linenum=NULL, *inlinedat=NULL;
            LANGUAGE_GC_PUSH3(&file, &linenum, &inlinedat);
            value_t lst = e;
            file = scm_to_language_(fl_ctx, car_(lst), mod);
            lst = cdr_(lst);
            linenum = scm_to_language_(fl_ctx, car_(lst), mod);
            lst = cdr_(lst);
            inlinedat = scm_to_language_(fl_ctx, car_(lst), mod);
            temp = language_new_struct(language_lineinfonode_type, file, linenum, inlinedat);
            LANGUAGE_GC_POP();
            return temp;
        }
        LANGUAGE_GC_PUSH2(&ex, &temp);
        if (sym == language_goto_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = language_new_struct(language_gotonode_type, ex);
        }
        else if (sym == language_goto_ifnot_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = scm_to_julia(fl_ctx, car_(cdr_(e)), mod);
            temp = language_new_struct(language_gotoifnot_type, ex, temp);
        }
        else if (sym == language_enter_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = language_new_struct_uninit(language_enternode_type);
            language_enternode_scope(temp) = NULL;
            language_enternode_catch_dest(temp) = language_unbox_long(ex);
            if (n == 2) {
                language_enternode_scope(temp) = scm_to_julia(fl_ctx, car_(cdr_(e)), mod);
            }
        }
        else if (sym == language_newvar_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = language_new_struct(language_newvarnode_type, ex);
        }
        else if (sym == language_globalref_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = scm_to_language_(fl_ctx, car_(cdr_(e)), mod);
            assert(language_is_module(ex));
            assert(language_is_symbol(temp));
            temp = language_module_globalref((language_module_t*)ex, (language_sym_t*)temp);
        }
        else if (sym == language_top_sym) {
            assert(mod && "top should not be generated by the parser");
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            assert(language_is_symbol(ex));
            temp = language_module_globalref(language_base_relative_to(mod), (language_sym_t*)ex);
        }
        else if (sym == language_core_sym) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            assert(language_is_symbol(ex));
            temp = language_module_globalref(language_core_module, (language_sym_t*)ex);
        }
        else if (sym == language_thismodule_sym) {
            temp = (language_value_t*)mod;
        }
        else if (iscons(e) && (sym == language_inert_sym || (sym == language_quote_sym && (!iscons(car_(e)))))) {
            ex = scm_to_language_(fl_ctx, car_(e), mod);
            temp = language_new_struct(language_quotenode_type, ex);
        }
        if (temp) {
            LANGUAGE_GC_POP();
            return temp;
        }
        ex = (language_value_t*)language_exprn(sym, n);
        size_t i;
        for (i = 0; i < n; i++) {
            assert(iscons(e));
            language_array_ptr_set(((language_expr_t*)ex)->args, i, scm_to_language_(fl_ctx, car_(e), mod));
            e = cdr_(e);
        }
        if (sym == language_lambda_sym)
            ex = (language_value_t*)language_new_code_info_from_ir((language_expr_t*)ex);
        LANGUAGE_GC_POP();
        if (sym == language_list_sym)
            return (language_value_t*)((language_expr_t*)ex)->args;
        return (language_value_t*)ex;
    }
    if (iscprim(e) && cp_class((cprim_t*)ptr(e)) == fl_ctx->wchartype) {
        uint32_t c, u = *(uint32_t*)cp_data((cprim_t*)ptr(e));
        if (u < 0x80) {
            c = u << 24;
        } else {
            c = ((u << 0) & 0x0000003f) | ((u << 2) & 0x00003f00) |
                ((u << 4) & 0x003f0000) | ((u << 6) & 0x3f000000);
            c = u < 0x00000800 ? (c << 16) | 0xc0800000 :
                u < 0x00010000 ? (c <<  8) | 0xe0808000 :
                                 (c <<  0) | 0xf0808080 ;
        }
        return language_box_char(c);
    }
    if (iscvalue(e) && cv_class((cvalue_t*)ptr(e)) == language_ast_ctx(fl_ctx)->jvtype) {
        return *(language_value_t**)cv_data((cvalue_t*)ptr(e));
    }
    language_error("malformed tree");
}

static value_t language_to_scm_(fl_context_t *fl_ctx, language_value_t *v, int check_valid);

static value_t language_to_scm(fl_context_t *fl_ctx, language_value_t *v)
{
    value_t temp;
    // need try/catch to reset GC handle stack in case of error
    FL_TRY_EXTERN(fl_ctx) {
        temp = language_to_scm_(fl_ctx, v, 1);
    }
    FL_CATCH_EXTERN(fl_ctx) {
        temp = fl_ctx->lasterror;
    }
    return temp;
}

static void array_to_list(fl_context_t *fl_ctx, language_array_t *a, value_t *pv, int check_valid)
{
    value_t temp;
    for (long i = language_array_nrows(a) - 1; i >= 0; i--) {
        *pv = fl_cons(fl_ctx, fl_ctx->NIL, *pv);
        temp = language_to_scm_(fl_ctx, language_array_ptr_ref(a, i), check_valid);
        // note: must be separate statement
        car_(*pv) = temp;
    }
}

static value_t language_to_list2(fl_context_t *fl_ctx, language_value_t *a, language_value_t *b, int check_valid)
{
    value_t sa = language_to_scm_(fl_ctx, a, check_valid);
    fl_gc_handle(fl_ctx, &sa);
    value_t sb = language_to_scm_(fl_ctx, b, check_valid);
    value_t l = fl_list2(fl_ctx, sa, sb);
    fl_free_gc_handles(fl_ctx, 1);
    return l;
}

static int language_to_scm_noalloc1(fl_context_t *fl_ctx, language_value_t *v, value_t *retval) LANGUAGE_NOTSAFEPOINT
{
    if (v == NULL)
        lerror(fl_ctx, symbol(fl_ctx, "error"), "undefined reference in AST");
    else if (language_is_symbol(v))
        *retval = symbol(fl_ctx, language_symbol_name((language_sym_t*)v));
    else if (v == language_true)
        *retval = fl_cons(fl_ctx, language_ast_ctx(fl_ctx)->true_sym, fl_ctx->NIL);
    else if (v == language_false)
        *retval = fl_cons(fl_ctx, language_ast_ctx(fl_ctx)->false_sym, fl_ctx->NIL);
    else if (v == language_nothing)
        *retval = fl_cons(fl_ctx, language_ast_ctx(fl_ctx)->null_sym, fl_ctx->NIL);
    else
        return 0;
    return 1;
}

static value_t language_to_scm_noalloc2(fl_context_t *fl_ctx, language_value_t *v, int check_valid) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_long(v)) {
        if (fits_fixnum(language_unbox_long(v))) {
            return fixnum(language_unbox_long(v));
        } else {
#ifdef _P64
            value_t prim = cprim(fl_ctx, fl_ctx->int64type, sizeof(int64_t));
            *((int64_t*)cp_data((cprim_t*)ptr(prim))) = language_unbox_long(v);
#else
            value_t prim = cprim(fl_ctx, fl_ctx->int32type, sizeof(int32_t));
            *((int32_t*)cp_data((cprim_t*)ptr(prim))) = language_unbox_long(v);
#endif
            return prim;
        }
    }
    if (check_valid) {
        if (language_is_ssavalue(v))
            lerror(fl_ctx, symbol(fl_ctx, "error"), "SSAValue objects should not occur in an AST");
        if (language_is_slotnumber(v))
            lerror(fl_ctx, symbol(fl_ctx, "error"), "SlotNumber objects should not occur in an AST");
    }
    value_t opaque = cvalue(fl_ctx, language_ast_ctx(fl_ctx)->jvtype, sizeof(void*));
    *(language_value_t**)cv_data((cvalue_t*)ptr(opaque)) = v;
    return opaque;
}

static value_t language_to_scm_noalloc(fl_context_t *fl_ctx, language_value_t *v, int check_valid) LANGUAGE_NOTSAFEPOINT
{
    value_t retval;
    if (language_to_scm_noalloc1(fl_ctx, v, &retval))
        return retval;
    assert(!language_is_expr(v) &&
           !language_typetagis(v, language_linenumbernode_type) &&
           !language_typetagis(v, language_gotonode_type) &&
           !language_typetagis(v, language_quotenode_type) &&
           !language_typetagis(v, language_newvarnode_type) &&
           !language_typetagis(v, language_globalref_type));
    return language_to_scm_noalloc2(fl_ctx, v, check_valid);
}

static value_t language_to_list2_noalloc(fl_context_t *fl_ctx, language_value_t *a, language_value_t *b, int check_valid) LANGUAGE_NOTSAFEPOINT
{
    value_t sa = language_to_scm_noalloc(fl_ctx, a, check_valid);
    fl_gc_handle(fl_ctx, &sa);
    value_t sb = language_to_scm_noalloc(fl_ctx, b, check_valid);
    value_t l = fl_list2(fl_ctx, sa, sb);
    fl_free_gc_handles(fl_ctx, 1);
    return l;
}

static value_t language_to_scm_(fl_context_t *fl_ctx, language_value_t *v, int check_valid)
{
    value_t retval;
    if (language_to_scm_noalloc1(fl_ctx, v, &retval))
        return retval;
    if (language_is_expr(v)) {
        language_expr_t *ex = (language_expr_t*)v;
        value_t args = fl_ctx->NIL;
        fl_gc_handle(fl_ctx, &args);
        if (language_expr_nargs(ex) > 520000 && ex->head != language_block_sym)
            lerror(fl_ctx, symbol(fl_ctx, "error"), "expression too large");
        array_to_list(fl_ctx, ex->args, &args, check_valid);
        value_t hd = language_to_scm_(fl_ctx, (language_value_t*)ex->head, check_valid);
        if (ex->head == language_lambda_sym && language_expr_nargs(ex)>0 && language_is_array(language_exprarg(ex,0))) {
            value_t llist = fl_ctx->NIL;
            fl_gc_handle(fl_ctx, &llist);
            array_to_list(fl_ctx, (language_array_t*)language_exprarg(ex,0), &llist, check_valid);
            car_(args) = llist;
            fl_free_gc_handles(fl_ctx, 1);
        }
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    // GC Note: language_fieldref(v, 0) allocates for GotoNode
    //          but we don't need a GC root here because language_to_list2_noalloc
    //          shouldn't allocate in this case.
    if (language_is_linenode(v)) {
        language_value_t *file = language_fieldref_noalloc(v,1);
        language_value_t *line = language_fieldref(v,0);
        value_t args = language_to_list2_noalloc(fl_ctx, line, file, check_valid);
        fl_gc_handle(fl_ctx, &args);
        value_t hd = language_to_scm_(fl_ctx, (language_value_t*)language_line_sym, check_valid);
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    if (language_typetagis(v, language_gotonode_type))
        return language_to_list2_noalloc(fl_ctx, (language_value_t*)language_goto_sym, language_fieldref(v,0), check_valid);
    if (language_typetagis(v, language_quotenode_type))
        return language_to_list2(fl_ctx, (language_value_t*)language_inert_sym, language_fieldref_noalloc(v,0), 0);
    if (language_typetagis(v, language_newvarnode_type))
        return language_to_list2_noalloc(fl_ctx, (language_value_t*)language_newvar_sym, language_fieldref(v,0), check_valid);
    if (language_typetagis(v, language_globalref_type)) {
        language_module_t *m = language_globalref_mod(v);
        language_sym_t *sym = language_globalref_name(v);
        if (m == language_core_module)
            return language_to_list2(fl_ctx, (language_value_t*)language_core_sym,
                                  (language_value_t*)sym, check_valid);
        value_t args = language_to_list2(fl_ctx, (language_value_t*)m, (language_value_t*)sym, check_valid);
        fl_gc_handle(fl_ctx, &args);
        value_t hd = language_to_scm_(fl_ctx, (language_value_t*)language_globalref_sym, check_valid);
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    return language_to_scm_noalloc2(fl_ctx, v, check_valid);
}

// Parse `text` starting at 0-based `offset` and attributing the content to
// `filename`. Return an svec of (parsed_expr, final_offset)
LANGUAGE_DLLEXPORT language_value_t *language_fl_parse(const char *text, size_t text_len,
                                     language_value_t *filename, size_t lineno,
                                     size_t offset, language_value_t *options)
{
    LANGUAGE_TIMING(PARSING, PARSING);
    language_timing_show_filename(language_string_data(filename), LANGUAGE_TIMING_DEFAULT_BLOCK);
    if (offset > text_len) {
        language_value_t *textstr = language_pchar_to_string(text, text_len);
        LANGUAGE_GC_PUSH1(&textstr);
        language_bounds_error(textstr, language_box_long(offset+1));
    }
    language_sym_t *rule = (language_sym_t*)options;
    if (rule != language_atom_sym && rule != language_statement_sym && rule != language_all_sym) {
        language_error("language_fl_parse: unrecognized parse options");
    }
    if (offset != 0 && rule == language_all_sym) {
        language_error("Parse `all`: offset not supported");
    }

    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t fl_text = cvalue_static_cstrn(fl_ctx, text, text_len);
    fl_gc_handle(fl_ctx, &fl_text);
    value_t fl_filename = cvalue_static_cstrn(fl_ctx, language_string_data(filename),
                                              language_string_len(filename));
    fl_gc_handle(fl_ctx, &fl_filename);
    value_t fl_expr;
    size_t offset1 = 0;
    if (rule == language_all_sym) {
        value_t e = fl_applyn(fl_ctx, 3, symbol_value(symbol(fl_ctx, "jl-parse-all")),
                              fl_text, fl_filename, fixnum(lineno));
        fl_expr = e;
        offset1 = e == fl_ctx->FL_EOF ? text_len : 0;
    }
    else {
        value_t greedy = rule == language_statement_sym ? fl_ctx->T : fl_ctx->F;
        value_t p = fl_applyn(fl_ctx, 5, symbol_value(symbol(fl_ctx, "jl-parse-one")),
                              fl_text, fl_filename, fixnum(offset), greedy, fixnum(lineno));
        fl_expr = car_(p);
        offset1 = tosize(fl_ctx, cdr_(p), "parse");
    }
    fl_free_gc_handles(fl_ctx, 2);

    // Convert to julia values
    language_value_t *expr = NULL, *end_offset = NULL;
    LANGUAGE_GC_PUSH2(&expr, &end_offset);
    expr = fl_expr == fl_ctx->FL_EOF ? language_nothing : scm_to_julia(fl_ctx, fl_expr, NULL);
    end_offset = language_box_long(offset1);
    language_ast_ctx_leave(ctx);
    language_value_t *result = (language_value_t*)language_svec2(expr, end_offset);
    LANGUAGE_GC_POP();
    return result;
}

// returns either an expression or a thunk
static language_value_t *language_call_scm_on_ast(const char *funcname, language_value_t *expr, language_module_t *inmodule)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = language_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, funcname)), arg);
    language_value_t *result = scm_to_julia(fl_ctx, e, inmodule);
    LANGUAGE_GC_PUSH1(&result);
    language_ast_ctx_leave(ctx);
    LANGUAGE_GC_POP();
    return result;
}

language_value_t *language_call_scm_on_ast_and_loc(const char *funcname, language_value_t *expr,
                                       language_module_t *inmodule, const char *file, int line)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = language_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 3, symbol_value(symbol(fl_ctx, funcname)), arg,
                          symbol(fl_ctx, file), fixnum(line));
    language_value_t *result = scm_to_julia(fl_ctx, e, inmodule);
    LANGUAGE_GC_PUSH1(&result);
    language_ast_ctx_leave(ctx);
    LANGUAGE_GC_POP();
    return result;
}

// syntax tree accessors

LANGUAGE_DLLEXPORT language_value_t *language_copy_ast(language_value_t *expr)
{
    if (!expr)
        return NULL;
    if (language_is_code_info(expr)) {
        language_code_info_t *new_ci = (language_code_info_t *)expr;
        language_array_t *new_code = NULL;
        LANGUAGE_GC_PUSH2(&new_ci, &new_code);
        new_ci = language_copy_code_info(new_ci);
        new_code = language_array_copy(new_ci->code);
        size_t clen = language_array_nrows(new_code);
        for (int i = 0; i < clen; ++i) {
            language_array_ptr_set(new_code, i, language_copy_ast(
                language_array_ptr_ref(new_code, i)
            ));
        }
        new_ci->code = new_code;
        language_gc_wb(new_ci, new_code);
        new_ci->slotnames = language_array_copy(new_ci->slotnames);
        language_gc_wb(new_ci, new_ci->slotnames);
        new_ci->slotflags = language_array_copy(new_ci->slotflags);
        language_gc_wb(new_ci, new_ci->slotflags);
        new_ci->ssaflags = language_array_copy(new_ci->ssaflags);
        language_gc_wb(new_ci, new_ci->ssaflags);

        if (language_is_array(new_ci->ssavaluetypes)) {
            new_ci->ssavaluetypes = (language_value_t*)language_array_copy((language_array_t*)new_ci->ssavaluetypes);
            language_gc_wb(new_ci, new_ci->ssavaluetypes);
        }
        LANGUAGE_GC_POP();
        return (language_value_t*)new_ci;
    }
    if (language_is_expr(expr)) {
        language_expr_t *e = (language_expr_t*)expr;
        size_t i, l = language_array_nrows(e->args);
        language_expr_t *ne = language_exprn(e->head, l);
        LANGUAGE_GC_PUSH2(&ne, &expr);
        for (i = 0; i < l; i++) {
            language_value_t *a = language_exprarg(e, i);
            language_exprargset(ne, i, language_copy_ast(a));
        }
        LANGUAGE_GC_POP();
        return (language_value_t*)ne;
    }
    if (language_is_phinode(expr)) {
        language_array_t *edges = (language_array_t*)language_fieldref_noalloc(expr, 0);
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(expr, 1);
        LANGUAGE_GC_PUSH2(&edges, &values);
        edges = language_array_copy(edges);
        values = language_array_copy(values);
        language_value_t *ret = language_new_struct(language_phinode_type, edges, values);
        LANGUAGE_GC_POP();
        return ret;
    }
    if (language_is_phicnode(expr)) {
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(expr, 0);
        LANGUAGE_GC_PUSH1(&values);
        values = language_array_copy(values);
        language_value_t *ret = language_new_struct(language_phicnode_type, values);
        LANGUAGE_GC_POP();
        return ret;
    }
    return expr;
}

LANGUAGE_DLLEXPORT int language_is_operator(const char *sym)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "operator?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    language_ast_ctx_leave(ctx);
    return res;
}

LANGUAGE_DLLEXPORT int language_is_unary_operator(const char *sym)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "unary-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    language_ast_ctx_leave(ctx);
    return res;
}

LANGUAGE_DLLEXPORT int language_is_unary_and_binary_operator(const char *sym)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "unary-and-binary-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    language_ast_ctx_leave(ctx);
    return res;
}

LANGUAGE_DLLEXPORT int language_is_syntactic_operator(const char *sym)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "syntactic-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    language_ast_ctx_leave(ctx);
    return res;
}

LANGUAGE_DLLEXPORT int language_operator_precedence(const char *sym)
{
    language_ast_context_t *ctx = language_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = numval(fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "operator-precedence")), symbol(fl_ctx, sym)));
    language_ast_ctx_leave(ctx);
    return res;
}

int language_has_meta(language_array_t *body, language_sym_t *sym) LANGUAGE_NOTSAFEPOINT
{
    size_t i, l = language_array_nrows(body);
    for (i = 0; i < l; i++) {
        language_expr_t *stmt = (language_expr_t*)language_array_ptr_ref(body, i);
        if (language_is_expr((language_value_t*)stmt) && stmt->head == language_meta_sym) {
            size_t i, l = language_array_nrows(stmt->args);
            for (i = 0; i < l; i++)
                if (language_array_ptr_ref(stmt->args, i) == (language_value_t*)sym)
                    return 1;
        }
    }
    return 0;
}

// Utility function to return whether `e` is any of the special AST types or
// will always evaluate to itself exactly unchanged. This corresponds to
// `is_self_quoting` in Core.Compiler utilities.
int language_is_ast_node(language_value_t *e) LANGUAGE_NOTSAFEPOINT
{
    return language_is_newvarnode(e)
        || language_is_code_info(e)
        || language_is_linenode(e)
        || language_is_gotonode(e)
        || language_is_gotoifnot(e)
        || language_is_returnnode(e)
        || language_is_ssavalue(e)
        || language_is_slotnumber(e)
        || language_is_argument(e)
        || language_is_quotenode(e)
        || language_is_globalref(e)
        || language_is_symbol(e)
        || language_is_pinode(e)
        || language_is_phinode(e)
        || language_is_phicnode(e)
        || language_is_upsilonnode(e)
        || language_is_expr(e);
}

static int is_self_quoting_expr(language_expr_t *e) LANGUAGE_NOTSAFEPOINT
{
    return (e->head == language_inert_sym ||
            e->head == language_core_sym ||
            e->head == language_line_sym ||
            e->head == language_lineinfo_sym ||
            e->head == language_meta_sym ||
            e->head == language_boundscheck_sym ||
            e->head == language_inline_sym ||
            e->head == language_noinline_sym);
}

// any AST, except those that cannot contain symbols
// and have no side effects
int need_esc_node(language_value_t *e) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_linenode(e)
        || language_is_ssavalue(e)
        || language_is_slotnumber(e)
        || language_is_argument(e)
        || language_is_quotenode(e))
        return 0;
    if (language_is_expr(e))
        return !is_self_quoting_expr((language_expr_t*)e);
    // note: language_is_globalref(e) is not included here, since we care a little about about having a line number for it
    return language_is_ast_node(e);
}

static language_value_t *language_invoke_language_macro(language_array_t *args, language_module_t *inmodule, language_module_t **ctx, language_value_t **lineinfo, size_t world, int throw_load_error)
{
    language_task_t *ct = language_current_task;
    LANGUAGE_TIMING(MACRO_INVOCATION, MACRO_INVOCATION);
    size_t nargs = language_array_nrows(args) + 1;
    LANGUAGE_NARGSV("macrocall", 3); // macro name, location, and module
    language_value_t **margs;
    LANGUAGE_GC_PUSHARGS(margs, nargs);
    int i;
    margs[0] = language_array_ptr_ref(args, 0);
    // __source__ argument
    language_value_t *lno = language_array_ptr_ref(args, 1);
    if (!language_is_linenode(lno))
        lno = language_new_struct(language_linenumbernode_type, language_box_long(0), language_nothing);
    margs[1] = lno;
    margs[2] = (language_value_t*)inmodule;
    for (i = 3; i < nargs; i++)
        margs[i] = language_array_ptr_ref(args, i - 1);

    size_t last_age = ct->world_age;
    ct->world_age = language_atomic_load_acquire(&language_world_counter);
    if (ct->world_age > world)
        ct->world_age = world;
    language_value_t *result;
    LANGUAGE_TRY {
        margs[0] = language_toplevel_eval(*ctx, margs[0]);
        language_method_instance_t *mfunc = language_method_lookup(margs, nargs, ct->world_age);
        LANGUAGE_GC_PROMISE_ROOTED(mfunc);
        if (mfunc == NULL) {
            language_method_error(margs[0], &margs[1], nargs, ct->world_age);
            // unreachable
        }
        language_timing_show_macro(mfunc, margs[1], inmodule, LANGUAGE_TIMING_DEFAULT_BLOCK);
        *ctx = mfunc->def.method->module;
        result = language_invoke(margs[0], &margs[1], nargs - 1, mfunc);
    }
    LANGUAGE_CATCH {
        if ((language_loaderror_type == NULL) || !throw_load_error) {
            language_rethrow();
        }
        else {
            language_value_t *lno = margs[1];
            language_value_t *file = language_fieldref(lno, 1);
            if (language_is_symbol(file))
                margs[0] = language_cstr_to_string(language_symbol_name((language_sym_t*)file));
            else
                margs[0] = language_cstr_to_string("<macrocall>");
            margs[1] = language_fieldref(lno, 0); // extract and allocate line number
            language_rethrow_other(language_new_struct(language_loaderror_type, margs[0], margs[1],
                                           language_current_exception(ct)));
        }
    }
    ct->world_age = last_age;
    *lineinfo = margs[1];
    LANGUAGE_GC_POP();
    return result;
}

static language_value_t *language_expand_macros(language_value_t *expr, language_module_t *inmodule, struct macroctx_stack *macroctx, int onelevel, size_t world, int throw_load_error)
{
    if (!expr || !language_is_expr(expr))
        return expr;
    language_expr_t *e = (language_expr_t*)expr;
    if (e->head == language_inert_sym ||
        e->head == language_module_sym ||
        e->head == language_toplevel_sym ||
        e->head == language_meta_sym) {
        return expr;
    }
    if (e->head == language_quote_sym && language_expr_nargs(e) == 1) {
        expr = language_call_scm_on_ast("julia-bq-macro", language_exprarg(e, 0), inmodule);
        LANGUAGE_GC_PUSH1(&expr);
        expr = language_expand_macros(expr, inmodule, macroctx, onelevel, world, throw_load_error);
        LANGUAGE_GC_POP();
        return expr;
    }
    if (e->head == language_hygienicscope_sym && language_expr_nargs(e) >= 2) {
        struct macroctx_stack newctx;
        newctx.m = (language_module_t*)language_exprarg(e, 1);
        LANGUAGE_TYPECHK(hygienic-scope, module, (language_value_t*)newctx.m);
        newctx.parent = macroctx;
        language_value_t *a = language_exprarg(e, 0);
        language_value_t *a2 = language_expand_macros(a, inmodule, &newctx, onelevel, world, throw_load_error);
        if (language_is_expr(a2) && ((language_expr_t*)a2)->head == language_escape_sym && !need_esc_node(language_exprarg(a2, 0)))
            expr = language_exprarg(a2, 0);
        else if (!need_esc_node(a2))
            expr = a2;
        else if (a != a2)
            language_array_ptr_set(e->args, 0, a2);
        return expr;
    }
    if (e->head == language_macrocall_sym) {
        struct macroctx_stack newctx;
        newctx.m = macroctx ? macroctx->m : inmodule;
        newctx.parent = macroctx;
        language_value_t *lineinfo = NULL;
        language_value_t *result = language_invoke_language_macro(e->args, inmodule, &newctx.m, &lineinfo, world, throw_load_error);
        if (!need_esc_node(result))
            return result;
        language_value_t *wrap = NULL;
        LANGUAGE_GC_PUSH4(&result, &wrap, &newctx.m, &lineinfo);
        // copy and wrap the result in `(hygienic-scope ,result ,newctx)
        if (language_is_expr(result) && ((language_expr_t*)result)->head == language_escape_sym)
            result = language_exprarg(result, 0);
        else
            wrap = (language_value_t*)language_exprn(language_hygienicscope_sym, 3);
        result = language_copy_ast(result);
        if (!onelevel)
            result = language_expand_macros(result, inmodule, wrap ? &newctx : macroctx, onelevel, world, throw_load_error);
        if (wrap && need_esc_node(result)) {
            language_exprargset(wrap, 0, result);
            language_exprargset(wrap, 1, newctx.m);
            language_exprargset(wrap, 2, lineinfo);
            if (language_is_expr(result) && ((language_expr_t*)result)->head == language_escape_sym)
                result = language_exprarg(result, 0);
            else
                result = wrap;
        }
        LANGUAGE_GC_POP();
        return result;
    }
    if (e->head == language_do_sym && language_expr_nargs(e) == 2 && language_is_expr(language_exprarg(e, 0)) &&
        ((language_expr_t*)language_exprarg(e, 0))->head == language_macrocall_sym) {
        language_expr_t *mc = (language_expr_t*)language_exprarg(e, 0);
        size_t nm = language_expr_nargs(mc);
        language_expr_t *mc2 = language_exprn(language_macrocall_sym, nm+1);
        LANGUAGE_GC_PUSH1(&mc2);
        language_exprargset(mc2, 0, language_exprarg(mc, 0));  // macro name
        language_exprargset(mc2, 1, language_exprarg(mc, 1));  // location
        language_exprargset(mc2, 2, language_exprarg(e, 1));   // function argument
        size_t j;
        for (j = 2; j < nm; j++) {
            language_exprargset(mc2, j+1, language_exprarg(mc, j));
        }
        language_value_t *ret = language_expand_macros((language_value_t*)mc2, inmodule, macroctx, onelevel, world, throw_load_error);
        LANGUAGE_GC_POP();
        return ret;
    }
    if (e->head == language_escape_sym && macroctx) {
        macroctx = macroctx->parent;
    }

    size_t i;
    for (i = 0; i < language_array_nrows(e->args); i++) {
        language_value_t *a = language_array_ptr_ref(e->args, i);
        language_value_t *a2 = language_expand_macros(a, inmodule, macroctx, onelevel, world, throw_load_error);
        if (a != a2)
            language_array_ptr_set(e->args, i, a2);
    }
    return expr;
}

LANGUAGE_DLLEXPORT language_value_t *language_macroexpand(language_value_t *expr, language_module_t *inmodule)
{
    LANGUAGE_TIMING(LOWERING, LOWERING);
    LANGUAGE_GC_PUSH1(&expr);
    expr = language_copy_ast(expr);
    expr = language_expand_macros(expr, inmodule, NULL, 0, language_atomic_load_acquire(&language_world_counter), 0);
    expr = language_call_scm_on_ast("jl-expand-macroscope", expr, inmodule);
    LANGUAGE_GC_POP();
    return expr;
}

LANGUAGE_DLLEXPORT language_value_t *language_macroexpand1(language_value_t *expr, language_module_t *inmodule)
{
    LANGUAGE_TIMING(LOWERING, LOWERING);
    LANGUAGE_GC_PUSH1(&expr);
    expr = language_copy_ast(expr);
    expr = language_expand_macros(expr, inmodule, NULL, 1, language_atomic_load_acquire(&language_world_counter), 0);
    expr = language_call_scm_on_ast("jl-expand-macroscope", expr, inmodule);
    LANGUAGE_GC_POP();
    return expr;
}

// Lower an expression tree into Julia's intermediate-representation.
LANGUAGE_DLLEXPORT language_value_t *language_expand(language_value_t *expr, language_module_t *inmodule)
{
    return language_expand_with_loc(expr, inmodule, "none", 0);
}

// Lowering, with starting program location specified
LANGUAGE_DLLEXPORT language_value_t *language_expand_with_loc(language_value_t *expr, language_module_t *inmodule,
                                            const char *file, int line)
{
    return language_expand_in_world(expr, inmodule, file, line, ~(size_t)0);
}

// Lowering, with starting program location and worldage specified
LANGUAGE_DLLEXPORT language_value_t *language_expand_in_world(language_value_t *expr, language_module_t *inmodule,
                                            const char *file, int line, size_t world)
{
    LANGUAGE_TIMING(LOWERING, LOWERING);
    language_timing_show_location(file, line, inmodule, LANGUAGE_TIMING_DEFAULT_BLOCK);
    LANGUAGE_GC_PUSH1(&expr);
    expr = language_copy_ast(expr);
    expr = language_expand_macros(expr, inmodule, NULL, 0, world, 1);
    expr = language_call_scm_on_ast_and_loc("jl-expand-to-thunk", expr, inmodule, file, line);
    LANGUAGE_GC_POP();
    return expr;
}

// Same as the above, but printing warnings when applicable
LANGUAGE_DLLEXPORT language_value_t *language_expand_with_loc_warn(language_value_t *expr, language_module_t *inmodule,
                                                 const char *file, int line)
{
    LANGUAGE_TIMING(LOWERING, LOWERING);
    language_timing_show_location(file, line, inmodule, LANGUAGE_TIMING_DEFAULT_BLOCK);
    language_array_t *kwargs = NULL;
    LANGUAGE_GC_PUSH2(&expr, &kwargs);
    expr = language_copy_ast(expr);
    expr = language_expand_macros(expr, inmodule, NULL, 0, ~(size_t)0, 1);
    language_ast_context_t *ctx = language_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = language_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 4, symbol_value(symbol(fl_ctx, "jl-expand-to-thunk-warn")), arg,
                          symbol(fl_ctx, file), fixnum(line), fl_ctx->F);
    expr = scm_to_julia(fl_ctx, e, inmodule);
    language_ast_ctx_leave(ctx);
    language_sym_t *warn_sym = language_symbol("warn");
    if (language_is_expr(expr) && ((language_expr_t*)expr)->head == warn_sym) {
        size_t nargs = language_expr_nargs(expr);
        for (int i = 0; i < nargs - 1; i++) {
            language_value_t *warning = language_exprarg(expr, i);
            size_t nargs = 0;
            if (language_is_expr(warning) && ((language_expr_t*)warning)->head == warn_sym)
                 nargs = language_expr_nargs(warning);
            int kwargs_len = (int)nargs - 6;
            if (nargs < 6 || kwargs_len % 2 != 0) {
                language_error("julia-logmsg: bad argument list - expected "
                         ":warn level (symbol) group (symbol) id file line msg . kwargs");
            }
            language_value_t *level = language_exprarg(warning, 0);
            language_value_t *group = language_exprarg(warning, 1);
            language_value_t *id = language_exprarg(warning, 2);
            language_value_t *file = language_exprarg(warning, 3);
            language_value_t *line = language_exprarg(warning, 4);
            language_value_t *msg = language_exprarg(warning, 5);
            kwargs = language_alloc_vec_any(kwargs_len);
            for (int i = 0; i < kwargs_len; ++i) {
                language_array_ptr_set(kwargs, i, language_exprarg(warning, i + 6));
            }
            LANGUAGE_TYPECHK(logmsg, long, level);
            language_log(language_unbox_long(level), NULL, group, id, file, line, (language_value_t*)kwargs, msg);
        }
        expr = language_exprarg(expr, nargs - 1);
    }
    LANGUAGE_GC_POP();
    return expr;
}

// expand in a context where the expression value is unused
LANGUAGE_DLLEXPORT language_value_t *language_expand_stmt_with_loc(language_value_t *expr, language_module_t *inmodule,
                                                 const char *file, int line)
{
    LANGUAGE_TIMING(LOWERING, LOWERING);
    LANGUAGE_GC_PUSH1(&expr);
    expr = language_copy_ast(expr);
    expr = language_expand_macros(expr, inmodule, NULL, 0, ~(size_t)0, 1);
    expr = language_call_scm_on_ast_and_loc("jl-expand-to-thunk-stmt", expr, inmodule, file, line);
    LANGUAGE_GC_POP();
    return expr;
}

LANGUAGE_DLLEXPORT language_value_t *language_expand_stmt(language_value_t *expr, language_module_t *inmodule)
{
    return language_expand_stmt_with_loc(expr, inmodule, "none", 0);
}


//------------------------------------------------------------------------------
// Parsing API and utils for calling parser from runtime

// Internal C entry point to parser
// `text` is passed as a pointer to allow raw non-String buffers to be used
// without copying.
language_value_t *language_parse(const char *text, size_t text_len, language_value_t *filename,
                     size_t lineno, size_t offset, language_value_t *options)
{
    language_value_t *core_parse = NULL;
    if (language_core_module) {
        core_parse = language_get_global(language_core_module, language_symbol("_parse"));
    }
    if (!core_parse || core_parse == language_nothing) {
        // In bootstrap, directly call the builtin parser.
        language_value_t *result = language_fl_parse(text, text_len, filename, lineno, offset, options);
        return result;
    }
    language_value_t **args;
    LANGUAGE_GC_PUSHARGS(args, 6);
    args[0] = core_parse;
    args[1] = (language_value_t*)language_alloc_svec(2);
    language_svecset(args[1], 0, language_box_uint8pointer((uint8_t*)text));
    language_svecset(args[1], 1, language_box_long(text_len));
    args[2] = filename;
    args[3] = language_box_long(lineno);
    args[4] = language_box_long(offset);
    args[5] = options;
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    ct->world_age = language_atomic_load_acquire(&language_world_counter);
    language_value_t *result = language_apply(args, 6);
    ct->world_age = last_age;
    args[0] = result; // root during error checks below
    LANGUAGE_TYPECHK(parse, simplevector, result);
    if (language_svec_len(result) != 2)
        language_error("Result from parser should be `svec(a::Expr, b::Int)`");
    LANGUAGE_TYPECHK(parse, expr, language_svecref(result, 0));
    LANGUAGE_TYPECHK(parse, long, language_svecref(result, 1));
    LANGUAGE_GC_POP();
    return result;
}

// parse an entire string as a file, reading multiple expressions
LANGUAGE_DLLEXPORT language_value_t *language_parse_all(const char *text, size_t text_len,
                                      const char *filename, size_t filename_len, size_t lineno)
{
    language_value_t *fname = language_pchar_to_string(filename, filename_len);
    LANGUAGE_GC_PUSH1(&fname);
    language_value_t *p = language_parse(text, text_len, fname, lineno, 0, (language_value_t*)language_all_sym);
    LANGUAGE_GC_POP();
    return language_svecref(p, 0);
}

// this is for parsing one expression out of a string, keeping track of
// the current position.
LANGUAGE_DLLEXPORT language_value_t *language_parse_string(const char *text, size_t text_len,
                                         int offset, int greedy)
{
    language_value_t *fname = language_cstr_to_string("none");
    LANGUAGE_GC_PUSH1(&fname);
    language_value_t *result = language_parse(text, text_len, fname, 1, offset,
                                  (language_value_t*)(greedy ? language_statement_sym : language_atom_sym));
    LANGUAGE_GC_POP();
    return result;
}

// deprecated
LANGUAGE_DLLEXPORT language_value_t *language_parse_input_line(const char *text, size_t text_len,
                                             const char *filename, size_t filename_len)
{
    return language_parse_all(text, text_len, filename, filename_len, 1);
}

#ifdef __cplusplus
}
#endif
