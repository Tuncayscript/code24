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
// Date: Wednesday, June 6, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: Components of the front-end, for obtaining and translating syntax trees

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _OS_WINDOWS_
#include <malloc.h>
#endif
#include "code.h"
#include "code_internal.h"
#include "flisp.h"
#include "code_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// head symbols for each expression type
CODE_DLLEXPORT code_sym_t *code_call_sym;
CODE_DLLEXPORT code_sym_t *code_invoke_sym;
CODE_DLLEXPORT code_sym_t *code_invoke_modify_sym;
CODE_DLLEXPORT code_sym_t *code_empty_sym;
CODE_DLLEXPORT code_sym_t *code_top_sym;
CODE_DLLEXPORT code_sym_t *code_module_sym;
CODE_DLLEXPORT code_sym_t *code_slot_sym;
CODE_DLLEXPORT code_sym_t *code_export_sym;
CODE_DLLEXPORT code_sym_t *code_public_sym;
CODE_DLLEXPORT code_sym_t *code_import_sym;
CODE_DLLEXPORT code_sym_t *code_toplevel_sym;
CODE_DLLEXPORT code_sym_t *code_quote_sym;
CODE_DLLEXPORT code_sym_t *code_line_sym;
CODE_DLLEXPORT code_sym_t *code_incomplete_sym;
CODE_DLLEXPORT code_sym_t *code_goto_sym;
CODE_DLLEXPORT code_sym_t *code_goto_ifnot_sym;
CODE_DLLEXPORT code_sym_t *code_return_sym;
CODE_DLLEXPORT code_sym_t *code_lineinfo_sym;
CODE_DLLEXPORT code_sym_t *code_lambda_sym;
CODE_DLLEXPORT code_sym_t *code_assign_sym;
CODE_DLLEXPORT code_sym_t *code_globalref_sym;
CODE_DLLEXPORT code_sym_t *code_do_sym;
CODE_DLLEXPORT code_sym_t *code_method_sym;
CODE_DLLEXPORT code_sym_t *code_core_sym;
CODE_DLLEXPORT code_sym_t *code_enter_sym;
CODE_DLLEXPORT code_sym_t *code_leave_sym;
CODE_DLLEXPORT code_sym_t *code_pop_exception_sym;
CODE_DLLEXPORT code_sym_t *code_exc_sym;
CODE_DLLEXPORT code_sym_t *code_error_sym;
CODE_DLLEXPORT code_sym_t *code_new_sym;
CODE_DLLEXPORT code_sym_t *code_using_sym;
CODE_DLLEXPORT code_sym_t *code_splatnew_sym;
CODE_DLLEXPORT code_sym_t *code_block_sym;
CODE_DLLEXPORT code_sym_t *code_new_opaque_closure_sym;
CODE_DLLEXPORT code_sym_t *code_opaque_closure_method_sym;
CODE_DLLEXPORT code_sym_t *code_const_sym;
CODE_DLLEXPORT code_sym_t *code_thunk_sym;
CODE_DLLEXPORT code_sym_t *code_foreigncall_sym;
CODE_DLLEXPORT code_sym_t *code_as_sym;
CODE_DLLEXPORT code_sym_t *code_global_sym;
CODE_DLLEXPORT code_sym_t *code_globaldecl_sym;
CODE_DLLEXPORT code_sym_t *code_local_sym;
CODE_DLLEXPORT code_sym_t *code_list_sym;
CODE_DLLEXPORT code_sym_t *code_dot_sym;
CODE_DLLEXPORT code_sym_t *code_newvar_sym;
CODE_DLLEXPORT code_sym_t *code_boundscheck_sym;
CODE_DLLEXPORT code_sym_t *code_inbounds_sym;
CODE_DLLEXPORT code_sym_t *code_copyast_sym;
CODE_DLLEXPORT code_sym_t *code_cfunction_sym;
CODE_DLLEXPORT code_sym_t *code_loopinfo_sym;
CODE_DLLEXPORT code_sym_t *code_meta_sym;
CODE_DLLEXPORT code_sym_t *code_inert_sym;
CODE_DLLEXPORT code_sym_t *code_polly_sym;
CODE_DLLEXPORT code_sym_t *code_unused_sym;
CODE_DLLEXPORT code_sym_t *code_static_parameter_sym;
CODE_DLLEXPORT code_sym_t *code_inline_sym;
CODE_DLLEXPORT code_sym_t *code_noinline_sym;
CODE_DLLEXPORT code_sym_t *code_generated_sym;
CODE_DLLEXPORT code_sym_t *code_generated_only_sym;
CODE_DLLEXPORT code_sym_t *code_isdefined_sym;
CODE_DLLEXPORT code_sym_t *code_propagate_inbounds_sym;
CODE_DLLEXPORT code_sym_t *code_specialize_sym;
CODE_DLLEXPORT code_sym_t *code_aggressive_constprop_sym;
CODE_DLLEXPORT code_sym_t *code_no_constprop_sym;
CODE_DLLEXPORT code_sym_t *code_purity_sym;
CODE_DLLEXPORT code_sym_t *code_nospecialize_sym;
CODE_DLLEXPORT code_sym_t *code_nospecializeinfer_sym;
CODE_DLLEXPORT code_sym_t *code_macrocall_sym;
CODE_DLLEXPORT code_sym_t *code_colon_sym;
CODE_DLLEXPORT code_sym_t *code_hygienicscope_sym;
CODE_DLLEXPORT code_sym_t *code_throw_undef_if_not_sym;
CODE_DLLEXPORT code_sym_t *code_getfield_undefref_sym;
CODE_DLLEXPORT code_sym_t *code_gc_preserve_begin_sym;
CODE_DLLEXPORT code_sym_t *code_gc_preserve_end_sym;
CODE_DLLEXPORT code_sym_t *code_coverageeffect_sym;
CODE_DLLEXPORT code_sym_t *code_escape_sym;
CODE_DLLEXPORT code_sym_t *code_aliasscope_sym;
CODE_DLLEXPORT code_sym_t *code_popaliasscope_sym;
CODE_DLLEXPORT code_sym_t *code_optlevel_sym;
CODE_DLLEXPORT code_sym_t *code_thismodule_sym;
CODE_DLLEXPORT code_sym_t *code_eval_sym;
CODE_DLLEXPORT code_sym_t *code_include_sym;
CODE_DLLEXPORT code_sym_t *code_atom_sym;
CODE_DLLEXPORT code_sym_t *code_statement_sym;
CODE_DLLEXPORT code_sym_t *code_all_sym;
CODE_DLLEXPORT code_sym_t *code_compile_sym;
CODE_DLLEXPORT code_sym_t *code_force_compile_sym;
CODE_DLLEXPORT code_sym_t *code_infer_sym;
CODE_DLLEXPORT code_sym_t *code_max_methods_sym;
CODE_DLLEXPORT code_sym_t *code_atomic_sym;
CODE_DLLEXPORT code_sym_t *code_not_atomic_sym;
CODE_DLLEXPORT code_sym_t *code_unordered_sym;
CODE_DLLEXPORT code_sym_t *code_monotonic_sym;
CODE_DLLEXPORT code_sym_t *code_acquire_sym;
CODE_DLLEXPORT code_sym_t *code_release_sym;
CODE_DLLEXPORT code_sym_t *code_acquire_release_sym;
CODE_DLLEXPORT code_sym_t *code_sequentially_consistent_sym;
CODE_DLLEXPORT code_sym_t *code_uninferred_sym;

static const uint8_t flisp_system_image[] = {
#include <code_flisp.boot.inc>
};

typedef struct _code_ast_context_t {
    fl_context_t fl;
    fltype_t *jvtype;

    value_t true_sym;
    value_t false_sym;
    value_t error_sym;
    value_t null_sym;
    value_t ssavalue_sym;
    value_t slot_sym;
    code_module_t *module; // context module for `current-code-module-counter`
    struct _code_ast_context_t *next; // invasive list pointer for getting free contexts
} code_ast_context_t;

static code_ast_context_t code_ast_main_ctx;

#ifdef __clang_gcanalyzer__
code_ast_context_t *code_ast_ctx(fl_context_t *fl) CODE_GLOBALLY_ROOTED CODE_NOTSAFEPOINT;
#else
#define code_ast_ctx(fl_ctx) container_of(fl_ctx, code_ast_context_t, fl)
#endif

struct macroctx_stack {
    code_module_t *m;
    struct macroctx_stack *parent;
};

static code_value_t *scm_to_code(fl_context_t *fl_ctx, value_t e, code_module_t *mod);
static value_t code_to_scm(fl_context_t *fl_ctx, code_value_t *v);
static code_value_t *code_expand_macros(code_value_t *expr, code_module_t *inmodule, struct macroctx_stack *macroctx, int onelevel, size_t world, int throw_load_error);

static code_sym_t *scmsym_to_code(fl_context_t *fl_ctx, value_t s)
{
    assert(issymbol(s));
    if (fl_isgensym(fl_ctx, s)) {
        char gsname[16];
        char *n = uint2str(&gsname[1], sizeof(gsname)-1,
                           ((gensym_t*)ptr(s))->id, 10);
        *(--n) = '#';
        return code_symbol(n);
    }
    return code_symbol(symbol_name(fl_ctx, s));
}

static value_t fl_defined_code_global(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    // tells whether a var is defined in and *by* the current module
    argcount(fl_ctx, "defined-code-global", nargs, 1);
    (void)tosymbol(fl_ctx, args[0], "defined-code-global");
    code_ast_context_t *ctx = code_ast_ctx(fl_ctx);
    code_sym_t *var = scmsym_to_code(fl_ctx, args[0]);
    code_binding_t *b = code_get_module_binding(ctx->module, var, 0);
    return (b != NULL && code_atomic_load_relaxed(&b->owner) == b) ? fl_ctx->T : fl_ctx->F;
}

static value_t fl_nothrow_code_global(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    // tells whether a var is defined, in the sense that accessing it is nothrow
    // can take either a symbol or a module and a symbol
    code_ast_context_t *ctx = code_ast_ctx(fl_ctx);
    code_module_t *mod = ctx->module;
    code_sym_t *var = NULL;
    if (nargs == 1) {
        (void)tosymbol(fl_ctx, args[0], "nothrow-code-global");
        var = scmsym_to_code(fl_ctx, args[0]);
    }
    else {
        argcount(fl_ctx, "nothrow-code-global", nargs, 2);
        value_t argmod = args[0];
        if (iscvalue(argmod) && cv_class((cvalue_t*)ptr(argmod)) == code_ast_ctx(fl_ctx)->jvtype) {
            mod = *(code_module_t**)cv_data((cvalue_t*)ptr(argmod));
            CODE_GC_PROMISE_ROOTED(mod);
        } else {
            if (!iscons(argmod) || !issymbol(car_(argmod)) || scmsym_to_code(fl_ctx, car_(argmod)) != code_thismodule_sym) {
                lerrorf(fl_ctx, fl_ctx->ArgError, "nothrow-code-global: Unknown globalref module kind");
            }
        }
        (void)tosymbol(fl_ctx, args[1], "nothrow-code-global");
        var = scmsym_to_code(fl_ctx, args[1]);
    }
    code_binding_t *b = code_get_module_binding(mod, var, 0);
    b = b ? code_atomic_load_relaxed(&b->owner) : NULL;
    return b != NULL && code_atomic_load_relaxed(&b->value) != NULL ? fl_ctx->T : fl_ctx->F;
}

static value_t fl_current_module_counter(fl_context_t *fl_ctx, value_t *args, uint32_t nargs) CODE_NOTSAFEPOINT
{
    code_ast_context_t *ctx = code_ast_ctx(fl_ctx);
    assert(ctx->module);
    return fixnum(code_module_next_counter(ctx->module));
}

static int code_is_number(code_value_t *v)
{
    code_datatype_t *t = (code_datatype_t*)code_typeof(v);
    for (; t->super != t; t = t->super)
        if (t == code_number_type)
            return 1;
    return 0;
}

// Check whether v is a scalar for purposes of inlining fused-broadcast
// arguments when lowering; should agree with broadcast.code on what is a
// scalar.  When in doubt, return false, since this is only an optimization.
static value_t fl_code_scalar(fl_context_t *fl_ctx, value_t *args, uint32_t nargs)
{
    argcount(fl_ctx, "code-scalar?", nargs, 1);
    if (fl_isnumber(fl_ctx, args[0]) || fl_isstring(fl_ctx, args[0]))
        return fl_ctx->T;
    else if (iscvalue(args[0]) && fl_ctx->code_sym == cv_type((cvalue_t*)ptr(args[0]))) {
        code_value_t *v = *(code_value_t**)cptr(args[0]);
        if (code_is_number(v) || code_is_string(v))
            return fl_ctx->T;
    }
    return fl_ctx->F;
}

static code_value_t *scm_to_code_(fl_context_t *fl_ctx, value_t e, code_module_t *mod);

static const builtinspec_t code_flisp_ast_ext[] = {
    { "defined-code-global", fl_defined_code_global }, // TODO: can we kill this safepoint
    { "nothrow-code-global", fl_nothrow_code_global },
    { "current-code-module-counter", fl_current_module_counter },
    { "code-scalar?", fl_code_scalar },
    { NULL, NULL }
};

static void code_init_ast_ctx(code_ast_context_t *ctx) CODE_NOTSAFEPOINT
{
    fl_context_t *fl_ctx = &ctx->fl;
    fl_init(fl_ctx, 4*1024*1024);

    if (fl_load_system_image_str(fl_ctx, (char*)flisp_system_image,
                                 sizeof(flisp_system_image))) {
        code_error("fatal error loading system image");
    }

    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "__init_globals")));

    ctx->jvtype = define_opaque_type(fl_ctx->code_sym, sizeof(void*), NULL, NULL);
    assign_global_builtins(fl_ctx, code_flisp_ast_ext);
    ctx->true_sym = symbol(fl_ctx, "true");
    ctx->false_sym = symbol(fl_ctx, "false");
    ctx->error_sym = symbol(fl_ctx, "error");
    ctx->null_sym = symbol(fl_ctx, "null");
    ctx->ssavalue_sym = symbol(fl_ctx, "ssavalue");
    ctx->slot_sym = symbol(fl_ctx, "slot");
    ctx->module = NULL;
    set(symbol(fl_ctx, "*scopewarn-opt*"), fixnum(code_options.warn_scope));
}

// There should be no GC allocation while holding this lock
static uv_mutex_t flisp_lock;
static code_ast_context_t *code_ast_ctx_freed = NULL;

static code_ast_context_t *code_ast_ctx_enter(code_module_t *m) CODE_GLOBALLY_ROOTED CODE_NOTSAFEPOINT
{
    CODE_SIGATOMIC_BEGIN();
    uv_mutex_lock(&flisp_lock);
    code_ast_context_t *ctx = code_ast_ctx_freed;
    if (ctx != NULL) {
        code_ast_ctx_freed = ctx->next;
        ctx->next = NULL;
    }
    uv_mutex_unlock(&flisp_lock);
    if (ctx == NULL) {
        // Construct a new one if we can't find any
        ctx = (code_ast_context_t*)calloc(1, sizeof(code_ast_context_t));
        code_init_ast_ctx(ctx);
    }
    ctx->module = m;
    return ctx;
}

static void code_ast_ctx_leave(code_ast_context_t *ctx)
{
    uv_mutex_lock(&flisp_lock);
    ctx->module = NULL;
    ctx->next = code_ast_ctx_freed;
    code_ast_ctx_freed = ctx;
    uv_mutex_unlock(&flisp_lock);
    CODE_SIGATOMIC_END();
}

void code_init_flisp(void)
{
    if (code_ast_ctx_freed)
        return;
    uv_mutex_init(&flisp_lock);
    code_init_ast_ctx(&code_ast_main_ctx);
    // To match the one in code_ast_ctx_leave
    CODE_SIGATOMIC_BEGIN();
    code_ast_ctx_leave(&code_ast_main_ctx);
}

void code_init_common_symbols(void)
{
    code_empty_sym = code_symbol("");
    code_call_sym = code_symbol("call");
    code_invoke_sym = code_symbol("invoke");
    code_invoke_modify_sym = code_symbol("invoke_modify");
    code_foreigncall_sym = code_symbol("foreigncall");
    code_cfunction_sym = code_symbol("cfunction");
    code_quote_sym = code_symbol("quote");
    code_inert_sym = code_symbol("inert");
    code_top_sym = code_symbol("top");
    code_core_sym = code_symbol("core");
    code_globalref_sym = code_symbol("globalref");
    code_line_sym = code_symbol("line");
    code_lineinfo_sym = code_symbol("lineinfo");
    code_incomplete_sym = code_symbol("incomplete");
    code_error_sym = code_symbol("error");
    code_goto_sym = code_symbol("goto");
    code_goto_ifnot_sym = code_symbol("gotoifnot");
    code_return_sym = code_symbol("return");
    code_lambda_sym = code_symbol("lambda");
    code_module_sym = code_symbol("module");
    code_export_sym = code_symbol("export");
    code_public_sym = code_symbol("public");
    code_import_sym = code_symbol("import");
    code_using_sym = code_symbol("using");
    code_assign_sym = code_symbol("=");
    code_method_sym = code_symbol("method");
    code_exc_sym = code_symbol("the_exception");
    code_enter_sym = code_symbol("enter");
    code_leave_sym = code_symbol("leave");
    code_pop_exception_sym = code_symbol("pop_exception");
    code_new_sym = code_symbol("new");
    code_splatnew_sym = code_symbol("splatnew");
    code_new_opaque_closure_sym = code_symbol("new_opaque_closure");
    code_opaque_closure_method_sym = code_symbol("opaque_closure_method");
    code_const_sym = code_symbol("const");
    code_global_sym = code_symbol("global");
    code_globaldecl_sym = code_symbol("globaldecl");
    code_local_sym = code_symbol("local");
    code_thunk_sym = code_symbol("thunk");
    code_toplevel_sym = code_symbol("toplevel");
    code_dot_sym = code_symbol(".");
    code_as_sym = code_symbol("as");
    code_colon_sym = code_symbol(":");
    code_boundscheck_sym = code_symbol("boundscheck");
    code_inbounds_sym = code_symbol("inbounds");
    code_newvar_sym = code_symbol("newvar");
    code_copyast_sym = code_symbol("copyast");
    code_loopinfo_sym = code_symbol("loopinfo");
    code_meta_sym = code_symbol("meta");
    code_list_sym = code_symbol("list");
    code_unused_sym = code_symbol("#unused#");
    code_slot_sym = code_symbol("slot");
    code_static_parameter_sym = code_symbol("static_parameter");
    code_inline_sym = code_symbol("inline");
    code_noinline_sym = code_symbol("noinline");
    code_polly_sym = code_symbol("polly");
    code_propagate_inbounds_sym = code_symbol("propagate_inbounds");
    code_aggressive_constprop_sym = code_symbol("aggressive_constprop");
    code_no_constprop_sym = code_symbol("no_constprop");
    code_purity_sym = code_symbol("purity");
    code_isdefined_sym = code_symbol("isdefined");
    code_nospecialize_sym = code_symbol("nospecialize");
    code_specialize_sym = code_symbol("specialize");
    code_nospecializeinfer_sym = code_symbol("nospecializeinfer");
    code_optlevel_sym = code_symbol("optlevel");
    code_compile_sym = code_symbol("compile");
    code_force_compile_sym = code_symbol("force_compile");
    code_infer_sym = code_symbol("infer");
    code_max_methods_sym = code_symbol("max_methods");
    code_macrocall_sym = code_symbol("macrocall");
    code_escape_sym = code_symbol("escape");
    code_hygienicscope_sym = code_symbol("hygienic-scope");
    code_gc_preserve_begin_sym = code_symbol("gc_preserve_begin");
    code_gc_preserve_end_sym = code_symbol("gc_preserve_end");
    code_generated_sym = code_symbol("generated");
    code_generated_only_sym = code_symbol("generated_only");
    code_throw_undef_if_not_sym = code_symbol("throw_undef_if_not");
    code_getfield_undefref_sym = code_symbol("##getfield##");
    code_do_sym = code_symbol("do");
    code_coverageeffect_sym = code_symbol("code_coverage_effect");
    code_aliasscope_sym = code_symbol("aliasscope");
    code_popaliasscope_sym = code_symbol("popaliasscope");
    code_thismodule_sym = code_symbol("thismodule");
    code_eval_sym = code_symbol("eval");
    code_include_sym = code_symbol("include");
    code_block_sym = code_symbol("block");
    code_atom_sym = code_symbol("atom");
    code_statement_sym = code_symbol("statement");
    code_all_sym = code_symbol("all");
    code_atomic_sym = code_symbol("atomic");
    code_not_atomic_sym = code_symbol("not_atomic");
    code_unordered_sym = code_symbol("unordered");
    code_monotonic_sym = code_symbol("monotonic");
    code_acquire_sym = code_symbol("acquire");
    code_release_sym = code_symbol("release");
    code_acquire_release_sym = code_symbol("acquire_release");
    code_sequentially_consistent_sym = code_symbol("sequentially_consistent");
    code_uninferred_sym = code_symbol("uninferred");
}

CODE_DLLEXPORT void code_lisp_prompt(void)
{
    // Make `--lisp` sigatomic in order to avoid triggering the sigint safepoint.
    // We don't have our signal handler registered in that case anyway...
    CODE_SIGATOMIC_BEGIN();
    code_init_flisp();
    code_ast_context_t *ctx = code_ast_ctx_enter(code_main_module);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "__start")), fl_cons(fl_ctx, fl_ctx->NIL,fl_ctx->NIL));
    code_ast_ctx_leave(ctx);
}

CODE_DLLEXPORT void fl_show_profile(void)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "show-profiles")));
    code_ast_ctx_leave(ctx);
}

CODE_DLLEXPORT void fl_clear_profile(void)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 0, symbol_value(symbol(fl_ctx, "clear-profiles")));
    code_ast_ctx_leave(ctx);
}

CODE_DLLEXPORT void fl_profile(const char *fname)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "profile-e")), symbol(fl_ctx, fname));
    code_ast_ctx_leave(ctx);
}

static code_value_t *scm_to_code(fl_context_t *fl_ctx, value_t e, code_module_t *mod)
{
    code_value_t *v = NULL;
    CODE_GC_PUSH1(&v);
    CODE_TRY {
        v = scm_to_code_(fl_ctx, e, mod);
    }
    CODE_CATCH {
        // if expression cannot be converted, replace with error expr
        //code_(code_current_exception(code_current_task));
        //codebacktrace();
        code_expr_t *ex = code_exprn(code_error_sym, 1);
        v = (code_value_t*)ex;
        code_array_ptr_set(ex->args, 0, code_cstr_to_string("invalid AST"));
    }
    CODE_GC_POP();
    return v;
}

extern int64_t conv_to_int64(void *data, numerictype_t tag);

static code_value_t *scm_to_code_(fl_context_t *fl_ctx, value_t e, code_module_t *mod)
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
                return (code_value_t*)code_box_float64(*(double*)cp_data(cp));
            case T_FLOAT:
                return (code_value_t*)code_box_float32(*(float*)cp_data(cp));
            case T_UINT8:
                return (code_value_t*)code_box_uint8(*(uint8_t*)cp_data(cp));
            case T_UINT16:
                return (code_value_t*)code_box_uint16(*(uint16_t*)cp_data(cp));
            case T_UINT32:
                return (code_value_t*)code_box_uint32(*(uint32_t*)cp_data(cp));
            case T_UINT64:
                return (code_value_t*)code_box_uint64(*(uint64_t*)cp_data(cp));
            default:
                ;
            }
            i64 = conv_to_int64(cp_data(cp), nt);
        }
#ifdef _P64
        return (code_value_t*)code_box_int64(i64);
#else
        if (i64 > (int64_t)S32_MAX || i64 < (int64_t)S32_MIN)
            return (code_value_t*)code_box_int64(i64);
        else
            return (code_value_t*)code_box_int32((int32_t)i64);
#endif
    }
    if (issymbol(e))
        return (code_value_t*)scmsym_to_code(fl_ctx, e);
    if (fl_isstring(fl_ctx, e))
        return code_pchar_to_string((char*)cvalue_data(e), cvalue_len(e));
    if (iscons(e) || e == fl_ctx->NIL) {
        value_t hd;
        code_sym_t *sym;
        if (e == fl_ctx->NIL) {
            hd = e;
        }
        else {
            hd = car_(e);
            if (hd == code_ast_ctx(fl_ctx)->ssavalue_sym)
                return code_box_ssavalue(numval(car_(cdr_(e))));
            else if (hd == code_ast_ctx(fl_ctx)->slot_sym)
                return code_box_slotnumber(numval(car_(cdr_(e))));
            else if (hd == code_ast_ctx(fl_ctx)->null_sym && llength(e) == 1)
                return code_nothing;
            else if (hd == code_ast_ctx(fl_ctx)->true_sym && llength(e) == 1)
                return code_true;
            else if (hd == code_ast_ctx(fl_ctx)->false_sym && llength(e) == 1)
                return code_false;
            else if (hd == fl_ctx->code_char_sym && llength(e) == 2) {
                value_t v = car_(cdr_(e));
                if (!(iscprim(v) && cp_class((cprim_t*)ptr(v)) == fl_ctx->uint32type))
                    code_error("malformed code char");
                uint32_t c = *(uint32_t*)cp_data((cprim_t*)ptr(v));
                return code_box_char(c);
            }
        }
        if (issymbol(hd))
            sym = scmsym_to_code(fl_ctx, hd);
        else
            sym = code_list_sym;
        size_t n = llength(e)-1;
        if (issymbol(hd))
            e = cdr_(e);
        else
            n++;
        // nodes with special representations
        code_value_t *ex = NULL, *temp = NULL;
        if (sym == code_line_sym && (n == 1 || n == 2)) {
            code_value_t *linenum = scm_to_code_(fl_ctx, car_(e), mod);
            code_value_t *file = code_nothing;
            CODE_GC_PUSH2(&linenum, &file);
            if (n == 2)
                file = scm_to_code_(fl_ctx, car_(cdr_(e)), mod);
            temp = code_new_struct(code_linenumbernode_type, linenum, file);
            CODE_GC_POP();
            return temp;
        }
        else if (sym == code_lineinfo_sym && n == 3) {
            code_value_t *file=NULL, *linenum=NULL, *inlinedat=NULL;
            CODE_GC_PUSH3(&file, &linenum, &inlinedat);
            value_t lst = e;
            file = scm_to_code_(fl_ctx, car_(lst), mod);
            lst = cdr_(lst);
            linenum = scm_to_code_(fl_ctx, car_(lst), mod);
            lst = cdr_(lst);
            inlinedat = scm_to_code_(fl_ctx, car_(lst), mod);
            temp = code_new_struct(code_lineinfonode_type, file, linenum, inlinedat);
            CODE_GC_POP();
            return temp;
        }
        CODE_GC_PUSH2(&ex, &temp);
        if (sym == code_goto_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = code_new_struct(code_gotonode_type, ex);
        }
        else if (sym == code_goto_ifnot_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = scm_to_code(fl_ctx, car_(cdr_(e)), mod);
            temp = code_new_struct(code_gotoifnot_type, ex, temp);
        }
        else if (sym == code_enter_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = code_new_struct_uninit(code_enternode_type);
            code_enternode_scope(temp) = NULL;
            code_enternode_catch_dest(temp) = code_unbox_long(ex);
            if (n == 2) {
                code_enternode_scope(temp) = scm_to_code(fl_ctx, car_(cdr_(e)), mod);
            }
        }
        else if (sym == code_newvar_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = code_new_struct(code_newvarnode_type, ex);
        }
        else if (sym == code_globalref_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = scm_to_code_(fl_ctx, car_(cdr_(e)), mod);
            assert(code_is_module(ex));
            assert(code_is_symbol(temp));
            temp = code_module_globalref((code_module_t*)ex, (code_sym_t*)temp);
        }
        else if (sym == code_top_sym) {
            assert(mod && "top should not be generated by the parser");
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            assert(code_is_symbol(ex));
            temp = code_module_globalref(code_base_relative_to(mod), (code_sym_t*)ex);
        }
        else if (sym == code_core_sym) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            assert(code_is_symbol(ex));
            temp = code_module_globalref(code_core_module, (code_sym_t*)ex);
        }
        else if (sym == code_thismodule_sym) {
            temp = (code_value_t*)mod;
        }
        else if (iscons(e) && (sym == code_inert_sym || (sym == code_quote_sym && (!iscons(car_(e)))))) {
            ex = scm_to_code_(fl_ctx, car_(e), mod);
            temp = code_new_struct(code_quotenode_type, ex);
        }
        if (temp) {
            CODE_GC_POP();
            return temp;
        }
        ex = (code_value_t*)code_exprn(sym, n);
        size_t i;
        for (i = 0; i < n; i++) {
            assert(iscons(e));
            code_array_ptr_set(((code_expr_t*)ex)->args, i, scm_to_code_(fl_ctx, car_(e), mod));
            e = cdr_(e);
        }
        if (sym == code_lambda_sym)
            ex = (code_value_t*)code_new_code_info_from_ir((code_expr_t*)ex);
        CODE_GC_POP();
        if (sym == code_list_sym)
            return (code_value_t*)((code_expr_t*)ex)->args;
        return (code_value_t*)ex;
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
        return code_box_char(c);
    }
    if (iscvalue(e) && cv_class((cvalue_t*)ptr(e)) == code_ast_ctx(fl_ctx)->jvtype) {
        return *(code_value_t**)cv_data((cvalue_t*)ptr(e));
    }
    code_error("malformed tree");
}

static value_t code_to_scm_(fl_context_t *fl_ctx, code_value_t *v, int check_valid);

static value_t code_to_scm(fl_context_t *fl_ctx, code_value_t *v)
{
    value_t temp;
    // need try/catch to reset GC handle stack in case of error
    FL_TRY_EXTERN(fl_ctx) {
        temp = code_to_scm_(fl_ctx, v, 1);
    }
    FL_CATCH_EXTERN(fl_ctx) {
        temp = fl_ctx->lasterror;
    }
    return temp;
}

static void array_to_list(fl_context_t *fl_ctx, code_array_t *a, value_t *pv, int check_valid)
{
    value_t temp;
    for (long i = code_array_nrows(a) - 1; i >= 0; i--) {
        *pv = fl_cons(fl_ctx, fl_ctx->NIL, *pv);
        temp = code_to_scm_(fl_ctx, code_array_ptr_ref(a, i), check_valid);
        // note: must be separate statement
        car_(*pv) = temp;
    }
}

static value_t code_to_list2(fl_context_t *fl_ctx, code_value_t *a, code_value_t *b, int check_valid)
{
    value_t sa = code_to_scm_(fl_ctx, a, check_valid);
    fl_gc_handle(fl_ctx, &sa);
    value_t sb = code_to_scm_(fl_ctx, b, check_valid);
    value_t l = fl_list2(fl_ctx, sa, sb);
    fl_free_gc_handles(fl_ctx, 1);
    return l;
}

static int code_to_scm_noalloc1(fl_context_t *fl_ctx, code_value_t *v, value_t *retval) CODE_NOTSAFEPOINT
{
    if (v == NULL)
        lerror(fl_ctx, symbol(fl_ctx, "error"), "undefined reference in AST");
    else if (code_is_symbol(v))
        *retval = symbol(fl_ctx, code_symbol_name((code_sym_t*)v));
    else if (v == code_true)
        *retval = fl_cons(fl_ctx, code_ast_ctx(fl_ctx)->true_sym, fl_ctx->NIL);
    else if (v == code_false)
        *retval = fl_cons(fl_ctx, code_ast_ctx(fl_ctx)->false_sym, fl_ctx->NIL);
    else if (v == code_nothing)
        *retval = fl_cons(fl_ctx, code_ast_ctx(fl_ctx)->null_sym, fl_ctx->NIL);
    else
        return 0;
    return 1;
}

static value_t code_to_scm_noalloc2(fl_context_t *fl_ctx, code_value_t *v, int check_valid) CODE_NOTSAFEPOINT
{
    if (code_is_long(v)) {
        if (fits_fixnum(code_unbox_long(v))) {
            return fixnum(code_unbox_long(v));
        } else {
#ifdef _P64
            value_t prim = cprim(fl_ctx, fl_ctx->int64type, sizeof(int64_t));
            *((int64_t*)cp_data((cprim_t*)ptr(prim))) = code_unbox_long(v);
#else
            value_t prim = cprim(fl_ctx, fl_ctx->int32type, sizeof(int32_t));
            *((int32_t*)cp_data((cprim_t*)ptr(prim))) = code_unbox_long(v);
#endif
            return prim;
        }
    }
    if (check_valid) {
        if (code_is_ssavalue(v))
            lerror(fl_ctx, symbol(fl_ctx, "error"), "SSAValue objects should not occur in an AST");
        if (code_is_slotnumber(v))
            lerror(fl_ctx, symbol(fl_ctx, "error"), "SlotNumber objects should not occur in an AST");
    }
    value_t opaque = cvalue(fl_ctx, code_ast_ctx(fl_ctx)->jvtype, sizeof(void*));
    *(code_value_t**)cv_data((cvalue_t*)ptr(opaque)) = v;
    return opaque;
}

static value_t code_to_scm_noalloc(fl_context_t *fl_ctx, code_value_t *v, int check_valid) CODE_NOTSAFEPOINT
{
    value_t retval;
    if (code_to_scm_noalloc1(fl_ctx, v, &retval))
        return retval;
    assert(!code_is_expr(v) &&
           !code_typetagis(v, code_linenumbernode_type) &&
           !code_typetagis(v, code_gotonode_type) &&
           !code_typetagis(v, code_quotenode_type) &&
           !code_typetagis(v, code_newvarnode_type) &&
           !code_typetagis(v, code_globalref_type));
    return code_to_scm_noalloc2(fl_ctx, v, check_valid);
}

static value_t code_to_list2_noalloc(fl_context_t *fl_ctx, code_value_t *a, code_value_t *b, int check_valid) CODE_NOTSAFEPOINT
{
    value_t sa = code_to_scm_noalloc(fl_ctx, a, check_valid);
    fl_gc_handle(fl_ctx, &sa);
    value_t sb = code_to_scm_noalloc(fl_ctx, b, check_valid);
    value_t l = fl_list2(fl_ctx, sa, sb);
    fl_free_gc_handles(fl_ctx, 1);
    return l;
}

static value_t code_to_scm_(fl_context_t *fl_ctx, code_value_t *v, int check_valid)
{
    value_t retval;
    if (code_to_scm_noalloc1(fl_ctx, v, &retval))
        return retval;
    if (code_is_expr(v)) {
        code_expr_t *ex = (code_expr_t*)v;
        value_t args = fl_ctx->NIL;
        fl_gc_handle(fl_ctx, &args);
        if (code_expr_nargs(ex) > 520000 && ex->head != code_block_sym)
            lerror(fl_ctx, symbol(fl_ctx, "error"), "expression too large");
        array_to_list(fl_ctx, ex->args, &args, check_valid);
        value_t hd = code_to_scm_(fl_ctx, (code_value_t*)ex->head, check_valid);
        if (ex->head == code_lambda_sym && code_expr_nargs(ex)>0 && code_is_array(code_exprarg(ex,0))) {
            value_t llist = fl_ctx->NIL;
            fl_gc_handle(fl_ctx, &llist);
            array_to_list(fl_ctx, (code_array_t*)code_exprarg(ex,0), &llist, check_valid);
            car_(args) = llist;
            fl_free_gc_handles(fl_ctx, 1);
        }
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    // GC Note: code_fieldref(v, 0) allocates for GotoNode
    //          but we don't need a GC root here because code_to_list2_noalloc
    //          shouldn't allocate in this case.
    if (code_is_linenode(v)) {
        code_value_t *file = code_fieldref_noalloc(v,1);
        code_value_t *line = code_fieldref(v,0);
        value_t args = code_to_list2_noalloc(fl_ctx, line, file, check_valid);
        fl_gc_handle(fl_ctx, &args);
        value_t hd = code_to_scm_(fl_ctx, (code_value_t*)code_line_sym, check_valid);
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    if (code_typetagis(v, code_gotonode_type))
        return code_to_list2_noalloc(fl_ctx, (code_value_t*)code_goto_sym, code_fieldref(v,0), check_valid);
    if (code_typetagis(v, code_quotenode_type))
        return code_to_list2(fl_ctx, (code_value_t*)code_inert_sym, code_fieldref_noalloc(v,0), 0);
    if (code_typetagis(v, code_newvarnode_type))
        return code_to_list2_noalloc(fl_ctx, (code_value_t*)code_newvar_sym, code_fieldref(v,0), check_valid);
    if (code_typetagis(v, code_globalref_type)) {
        code_module_t *m = code_globalref_mod(v);
        code_sym_t *sym = code_globalref_name(v);
        if (m == code_core_module)
            return code_to_list2(fl_ctx, (code_value_t*)code_core_sym,
                                  (code_value_t*)sym, check_valid);
        value_t args = code_to_list2(fl_ctx, (code_value_t*)m, (code_value_t*)sym, check_valid);
        fl_gc_handle(fl_ctx, &args);
        value_t hd = code_to_scm_(fl_ctx, (code_value_t*)code_globalref_sym, check_valid);
        value_t scmv = fl_cons(fl_ctx, hd, args);
        fl_free_gc_handles(fl_ctx, 1);
        return scmv;
    }
    return code_to_scm_noalloc2(fl_ctx, v, check_valid);
}

// Parse `text` starting at 0-based `offset` and attributing the content to
// `filename`. Return an svec of (parsed_expr, final_offset)
CODE_DLLEXPORT code_value_t *code_fl_parse(const char *text, size_t text_len,
                                     code_value_t *filename, size_t lineno,
                                     size_t offset, code_value_t *options)
{
    CODE_TIMING(PARSING, PARSING);
    code_timing_show_filename(code_string_data(filename), CODE_TIMING_DEFAULT_BLOCK);
    if (offset > text_len) {
        code_value_t *textstr = code_pchar_to_string(text, text_len);
        CODE_GC_PUSH1(&textstr);
        code_bounds_error(textstr, code_box_long(offset+1));
    }
    code_sym_t *rule = (code_sym_t*)options;
    if (rule != code_atom_sym && rule != code_statement_sym && rule != code_all_sym) {
        code_error("code_fl_parse: unrecognized parse options");
    }
    if (offset != 0 && rule == code_all_sym) {
        code_error("Parse `all`: offset not supported");
    }

    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t fl_text = cvalue_static_cstrn(fl_ctx, text, text_len);
    fl_gc_handle(fl_ctx, &fl_text);
    value_t fl_filename = cvalue_static_cstrn(fl_ctx, code_string_data(filename),
                                              code_string_len(filename));
    fl_gc_handle(fl_ctx, &fl_filename);
    value_t fl_expr;
    size_t offset1 = 0;
    if (rule == code_all_sym) {
        value_t e = fl_applyn(fl_ctx, 3, symbol_value(symbol(fl_ctx, "code-parse-all")),
                              fl_text, fl_filename, fixnum(lineno));
        fl_expr = e;
        offset1 = e == fl_ctx->FL_EOF ? text_len : 0;
    }
    else {
        value_t greedy = rule == code_statement_sym ? fl_ctx->T : fl_ctx->F;
        value_t p = fl_applyn(fl_ctx, 5, symbol_value(symbol(fl_ctx, "code-parse-one")),
                              fl_text, fl_filename, fixnum(offset), greedy, fixnum(lineno));
        fl_expr = car_(p);
        offset1 = tosize(fl_ctx, cdr_(p), "parse");
    }
    fl_free_gc_handles(fl_ctx, 2);

    // Convert to code values
    code_value_t *expr = NULL, *end_offset = NULL;
    CODE_GC_PUSH2(&expr, &end_offset);
    expr = fl_expr == fl_ctx->FL_EOF ? code_nothing : scm_to_code(fl_ctx, fl_expr, NULL);
    end_offset = code_box_long(offset1);
    code_ast_ctx_leave(ctx);
    code_value_t *result = (code_value_t*)code_svec2(expr, end_offset);
    CODE_GC_POP();
    return result;
}

// returns either an expression or a thunk
static code_value_t *code_call_scm_on_ast(const char *funcname, code_value_t *expr, code_module_t *inmodule)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = code_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, funcname)), arg);
    code_value_t *result = scm_to_code(fl_ctx, e, inmodule);
    CODE_GC_PUSH1(&result);
    code_ast_ctx_leave(ctx);
    CODE_GC_POP();
    return result;
}

code_value_t *code_call_scm_on_ast_and_loc(const char *funcname, code_value_t *expr,
                                       code_module_t *inmodule, const char *file, int line)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = code_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 3, symbol_value(symbol(fl_ctx, funcname)), arg,
                          symbol(fl_ctx, file), fixnum(line));
    code_value_t *result = scm_to_code(fl_ctx, e, inmodule);
    CODE_GC_PUSH1(&result);
    code_ast_ctx_leave(ctx);
    CODE_GC_POP();
    return result;
}

// syntax tree accessors

CODE_DLLEXPORT code_value_t *code_copy_ast(code_value_t *expr)
{
    if (!expr)
        return NULL;
    if (code_is_code_info(expr)) {
        code_code_info_t *new_ci = (code_code_info_t *)expr;
        code_array_t *new_code = NULL;
        CODE_GC_PUSH2(&new_ci, &new_code);
        new_ci = code_copy_code_info(new_ci);
        new_code = code_array_copy(new_ci->code);
        size_t clen = code_array_nrows(new_code);
        for (int i = 0; i < clen; ++i) {
            code_array_ptr_set(new_code, i, code_copy_ast(
                code_array_ptr_ref(new_code, i)
            ));
        }
        new_ci->code = new_code;
        code_gc_wb(new_ci, new_code);
        new_ci->slotnames = code_array_copy(new_ci->slotnames);
        code_gc_wb(new_ci, new_ci->slotnames);
        new_ci->slotflags = code_array_copy(new_ci->slotflags);
        code_gc_wb(new_ci, new_ci->slotflags);
        new_ci->ssaflags = code_array_copy(new_ci->ssaflags);
        code_gc_wb(new_ci, new_ci->ssaflags);

        if (code_is_array(new_ci->ssavaluetypes)) {
            new_ci->ssavaluetypes = (code_value_t*)code_array_copy((code_array_t*)new_ci->ssavaluetypes);
            code_gc_wb(new_ci, new_ci->ssavaluetypes);
        }
        CODE_GC_POP();
        return (code_value_t*)new_ci;
    }
    if (code_is_expr(expr)) {
        code_expr_t *e = (code_expr_t*)expr;
        size_t i, l = code_array_nrows(e->args);
        code_expr_t *ne = code_exprn(e->head, l);
        CODE_GC_PUSH2(&ne, &expr);
        for (i = 0; i < l; i++) {
            code_value_t *a = code_exprarg(e, i);
            code_exprargset(ne, i, code_copy_ast(a));
        }
        CODE_GC_POP();
        return (code_value_t*)ne;
    }
    if (code_is_phinode(expr)) {
        code_array_t *edges = (code_array_t*)code_fieldref_noalloc(expr, 0);
        code_array_t *values = (code_array_t*)code_fieldref_noalloc(expr, 1);
        CODE_GC_PUSH2(&edges, &values);
        edges = code_array_copy(edges);
        values = code_array_copy(values);
        code_value_t *ret = code_new_struct(code_phinode_type, edges, values);
        CODE_GC_POP();
        return ret;
    }
    if (code_is_phicnode(expr)) {
        code_array_t *values = (code_array_t*)code_fieldref_noalloc(expr, 0);
        CODE_GC_PUSH1(&values);
        values = code_array_copy(values);
        code_value_t *ret = code_new_struct(code_phicnode_type, values);
        CODE_GC_POP();
        return ret;
    }
    return expr;
}

CODE_DLLEXPORT int code_is_operator(const char *sym)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "operator?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    code_ast_ctx_leave(ctx);
    return res;
}

CODE_DLLEXPORT int code_is_unary_operator(const char *sym)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "unary-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    code_ast_ctx_leave(ctx);
    return res;
}

CODE_DLLEXPORT int code_is_unary_and_binary_operator(const char *sym)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "unary-and-binary-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    code_ast_ctx_leave(ctx);
    return res;
}

CODE_DLLEXPORT int code_is_syntactic_operator(const char *sym)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "syntactic-op?")), symbol(fl_ctx, sym)) == fl_ctx->T;
    code_ast_ctx_leave(ctx);
    return res;
}

CODE_DLLEXPORT int code_operator_precedence(const char *sym)
{
    code_ast_context_t *ctx = code_ast_ctx_enter(NULL);
    fl_context_t *fl_ctx = &ctx->fl;
    int res = numval(fl_applyn(fl_ctx, 1, symbol_value(symbol(fl_ctx, "operator-precedence")), symbol(fl_ctx, sym)));
    code_ast_ctx_leave(ctx);
    return res;
}

int code_has_meta(code_array_t *body, code_sym_t *sym) CODE_NOTSAFEPOINT
{
    size_t i, l = code_array_nrows(body);
    for (i = 0; i < l; i++) {
        code_expr_t *stmt = (code_expr_t*)code_array_ptr_ref(body, i);
        if (code_is_expr((code_value_t*)stmt) && stmt->head == code_meta_sym) {
            size_t i, l = code_array_nrows(stmt->args);
            for (i = 0; i < l; i++)
                if (code_array_ptr_ref(stmt->args, i) == (code_value_t*)sym)
                    return 1;
        }
    }
    return 0;
}

// Utility function to return whether `e` is any of the special AST types or
// will always evaluate to itself exactly unchanged. This corresponds to
// `is_self_quoting` in Core.Compiler utilities.
int code_is_ast_node(code_value_t *e) CODE_NOTSAFEPOINT
{
    return code_is_newvarnode(e)
        || code_is_code_info(e)
        || code_is_linenode(e)
        || code_is_gotonode(e)
        || code_is_gotoifnot(e)
        || code_is_returnnode(e)
        || code_is_ssavalue(e)
        || code_is_slotnumber(e)
        || code_is_argument(e)
        || code_is_quotenode(e)
        || code_is_globalref(e)
        || code_is_symbol(e)
        || code_is_pinode(e)
        || code_is_phinode(e)
        || code_is_phicnode(e)
        || code_is_upsilonnode(e)
        || code_is_expr(e);
}

static int is_self_quoting_expr(code_expr_t *e) CODE_NOTSAFEPOINT
{
    return (e->head == code_inert_sym ||
            e->head == code_core_sym ||
            e->head == code_line_sym ||
            e->head == code_lineinfo_sym ||
            e->head == code_meta_sym ||
            e->head == code_boundscheck_sym ||
            e->head == code_inline_sym ||
            e->head == code_noinline_sym);
}

// any AST, except those that cannot contain symbols
// and have no side effects
int need_esc_node(code_value_t *e) CODE_NOTSAFEPOINT
{
    if (code_is_linenode(e)
        || code_is_ssavalue(e)
        || code_is_slotnumber(e)
        || code_is_argument(e)
        || code_is_quotenode(e))
        return 0;
    if (code_is_expr(e))
        return !is_self_quoting_expr((code_expr_t*)e);
    // note: code_is_globalref(e) is not included here, since we care a little about about having a line number for it
    return code_is_ast_node(e);
}

static code_value_t *code_invoke_code_macro(code_array_t *args, code_module_t *inmodule, code_module_t **ctx, code_value_t **lineinfo, size_t world, int throw_load_error)
{
    code_task_t *ct = code_current_task;
    CODE_TIMING(MACRO_INVOCATION, MACRO_INVOCATION);
    size_t nargs = code_array_nrows(args) + 1;
    CODE_NARGSV("macrocall", 3); // macro name, location, and module
    code_value_t **margs;
    CODE_GC_PUSHARGS(margs, nargs);
    int i;
    margs[0] = code_array_ptr_ref(args, 0);
    // __source__ argument
    code_value_t *lno = code_array_ptr_ref(args, 1);
    if (!code_is_linenode(lno))
        lno = code_new_struct(code_linenumbernode_type, code_box_long(0), code_nothing);
    margs[1] = lno;
    margs[2] = (code_value_t*)inmodule;
    for (i = 3; i < nargs; i++)
        margs[i] = code_array_ptr_ref(args, i - 1);

    size_t last_age = ct->world_age;
    ct->world_age = code_atomic_load_acquire(&code_world_counter);
    if (ct->world_age > world)
        ct->world_age = world;
    code_value_t *result;
    CODE_TRY {
        margs[0] = code_toplevel_eval(*ctx, margs[0]);
        code_method_instance_t *mfunc = code_method_lookup(margs, nargs, ct->world_age);
        CODE_GC_PROMISE_ROOTED(mfunc);
        if (mfunc == NULL) {
            code_method_error(margs[0], &margs[1], nargs, ct->world_age);
            // unreachable
        }
        code_timing_show_macro(mfunc, margs[1], inmodule, CODE_TIMING_DEFAULT_BLOCK);
        *ctx = mfunc->def.method->module;
        result = code_invoke(margs[0], &margs[1], nargs - 1, mfunc);
    }
    CODE_CATCH {
        if ((code_loaderror_type == NULL) || !throw_load_error) {
            code_rethrow();
        }
        else {
            code_value_t *lno = margs[1];
            code_value_t *file = code_fieldref(lno, 1);
            if (code_is_symbol(file))
                margs[0] = code_cstr_to_string(code_symbol_name((code_sym_t*)file));
            else
                margs[0] = code_cstr_to_string("<macrocall>");
            margs[1] = code_fieldref(lno, 0); // extract and allocate line number
            code_rethrow_other(code_new_struct(code_loaderror_type, margs[0], margs[1],
                                           code_current_exception(ct)));
        }
    }
    ct->world_age = last_age;
    *lineinfo = margs[1];
    CODE_GC_POP();
    return result;
}

static code_value_t *code_expand_macros(code_value_t *expr, code_module_t *inmodule, struct macroctx_stack *macroctx, int onelevel, size_t world, int throw_load_error)
{
    if (!expr || !code_is_expr(expr))
        return expr;
    code_expr_t *e = (code_expr_t*)expr;
    if (e->head == code_inert_sym ||
        e->head == code_module_sym ||
        e->head == code_toplevel_sym ||
        e->head == code_meta_sym) {
        return expr;
    }
    if (e->head == code_quote_sym && code_expr_nargs(e) == 1) {
        expr = code_call_scm_on_ast("code-bq-macro", code_exprarg(e, 0), inmodule);
        CODE_GC_PUSH1(&expr);
        expr = code_expand_macros(expr, inmodule, macroctx, onelevel, world, throw_load_error);
        CODE_GC_POP();
        return expr;
    }
    if (e->head == code_hygienicscope_sym && code_expr_nargs(e) >= 2) {
        struct macroctx_stack newctx;
        newctx.m = (code_module_t*)code_exprarg(e, 1);
        CODE_TYPECHK(hygienic-scope, module, (code_value_t*)newctx.m);
        newctx.parent = macroctx;
        code_value_t *a = code_exprarg(e, 0);
        code_value_t *a2 = code_expand_macros(a, inmodule, &newctx, onelevel, world, throw_load_error);
        if (code_is_expr(a2) && ((code_expr_t*)a2)->head == code_escape_sym && !need_esc_node(code_exprarg(a2, 0)))
            expr = code_exprarg(a2, 0);
        else if (!need_esc_node(a2))
            expr = a2;
        else if (a != a2)
            code_array_ptr_set(e->args, 0, a2);
        return expr;
    }
    if (e->head == code_macrocall_sym) {
        struct macroctx_stack newctx;
        newctx.m = macroctx ? macroctx->m : inmodule;
        newctx.parent = macroctx;
        code_value_t *lineinfo = NULL;
        code_value_t *result = code_invoke_code_macro(e->args, inmodule, &newctx.m, &lineinfo, world, throw_load_error);
        if (!need_esc_node(result))
            return result;
        code_value_t *wrap = NULL;
        CODE_GC_PUSH4(&result, &wrap, &newctx.m, &lineinfo);
        // copy and wrap the result in `(hygienic-scope ,result ,newctx)
        if (code_is_expr(result) && ((code_expr_t*)result)->head == code_escape_sym)
            result = code_exprarg(result, 0);
        else
            wrap = (code_value_t*)code_exprn(code_hygienicscope_sym, 3);
        result = code_copy_ast(result);
        if (!onelevel)
            result = code_expand_macros(result, inmodule, wrap ? &newctx : macroctx, onelevel, world, throw_load_error);
        if (wrap && need_esc_node(result)) {
            code_exprargset(wrap, 0, result);
            code_exprargset(wrap, 1, newctx.m);
            code_exprargset(wrap, 2, lineinfo);
            if (code_is_expr(result) && ((code_expr_t*)result)->head == code_escape_sym)
                result = code_exprarg(result, 0);
            else
                result = wrap;
        }
        CODE_GC_POP();
        return result;
    }
    if (e->head == code_do_sym && code_expr_nargs(e) == 2 && code_is_expr(code_exprarg(e, 0)) &&
        ((code_expr_t*)code_exprarg(e, 0))->head == code_macrocall_sym) {
        code_expr_t *mc = (code_expr_t*)code_exprarg(e, 0);
        size_t nm = code_expr_nargs(mc);
        code_expr_t *mc2 = code_exprn(code_macrocall_sym, nm+1);
        CODE_GC_PUSH1(&mc2);
        code_exprargset(mc2, 0, code_exprarg(mc, 0));  // macro name
        code_exprargset(mc2, 1, code_exprarg(mc, 1));  // location
        code_exprargset(mc2, 2, code_exprarg(e, 1));   // function argument
        size_t j;
        for (j = 2; j < nm; j++) {
            code_exprargset(mc2, j+1, code_exprarg(mc, j));
        }
        code_value_t *ret = code_expand_macros((code_value_t*)mc2, inmodule, macroctx, onelevel, world, throw_load_error);
        CODE_GC_POP();
        return ret;
    }
    if (e->head == code_escape_sym && macroctx) {
        macroctx = macroctx->parent;
    }

    size_t i;
    for (i = 0; i < code_array_nrows(e->args); i++) {
        code_value_t *a = code_array_ptr_ref(e->args, i);
        code_value_t *a2 = code_expand_macros(a, inmodule, macroctx, onelevel, world, throw_load_error);
        if (a != a2)
            code_array_ptr_set(e->args, i, a2);
    }
    return expr;
}

CODE_DLLEXPORT code_value_t *code_macroexpand(code_value_t *expr, code_module_t *inmodule)
{
    CODE_TIMING(LOWERING, LOWERING);
    CODE_GC_PUSH1(&expr);
    expr = code_copy_ast(expr);
    expr = code_expand_macros(expr, inmodule, NULL, 0, code_atomic_load_acquire(&code_world_counter), 0);
    expr = code_call_scm_on_ast("code-expand-macroscope", expr, inmodule);
    CODE_GC_POP();
    return expr;
}

CODE_DLLEXPORT code_value_t *code_macroexpand1(code_value_t *expr, code_module_t *inmodule)
{
    CODE_TIMING(LOWERING, LOWERING);
    CODE_GC_PUSH1(&expr);
    expr = code_copy_ast(expr);
    expr = code_expand_macros(expr, inmodule, NULL, 1, code_atomic_load_acquire(&code_world_counter), 0);
    expr = code_call_scm_on_ast("code-expand-macroscope", expr, inmodule);
    CODE_GC_POP();
    return expr;
}

// Lower an expression tree into Code's intermediate-representation.
CODE_DLLEXPORT code_value_t *code_expand(code_value_t *expr, code_module_t *inmodule)
{
    return code_expand_with_loc(expr, inmodule, "none", 0);
}

// Lowering, with starting program location specified
CODE_DLLEXPORT code_value_t *code_expand_with_loc(code_value_t *expr, code_module_t *inmodule,
                                            const char *file, int line)
{
    return code_expand_in_world(expr, inmodule, file, line, ~(size_t)0);
}

// Lowering, with starting program location and worldage specified
CODE_DLLEXPORT code_value_t *code_expand_in_world(code_value_t *expr, code_module_t *inmodule,
                                            const char *file, int line, size_t world)
{
    CODE_TIMING(LOWERING, LOWERING);
    code_timing_show_location(file, line, inmodule, CODE_TIMING_DEFAULT_BLOCK);
    CODE_GC_PUSH1(&expr);
    expr = code_copy_ast(expr);
    expr = code_expand_macros(expr, inmodule, NULL, 0, world, 1);
    expr = code_call_scm_on_ast_and_loc("code-expand-to-thunk", expr, inmodule, file, line);
    CODE_GC_POP();
    return expr;
}

// Same as the above, but printing warnings when applicable
CODE_DLLEXPORT code_value_t *code_expand_with_loc_warn(code_value_t *expr, code_module_t *inmodule,
                                                 const char *file, int line)
{
    CODE_TIMING(LOWERING, LOWERING);
    code_timing_show_location(file, line, inmodule, CODE_TIMING_DEFAULT_BLOCK);
    code_array_t *kwargs = NULL;
    CODE_GC_PUSH2(&expr, &kwargs);
    expr = code_copy_ast(expr);
    expr = code_expand_macros(expr, inmodule, NULL, 0, ~(size_t)0, 1);
    code_ast_context_t *ctx = code_ast_ctx_enter(inmodule);
    fl_context_t *fl_ctx = &ctx->fl;
    value_t arg = code_to_scm(fl_ctx, expr);
    value_t e = fl_applyn(fl_ctx, 4, symbol_value(symbol(fl_ctx, "code-expand-to-thunk-warn")), arg,
                          symbol(fl_ctx, file), fixnum(line), fl_ctx->F);
    expr = scm_to_code(fl_ctx, e, inmodule);
    code_ast_ctx_leave(ctx);
    code_sym_t *warn_sym = code_symbol("warn");
    if (code_is_expr(expr) && ((code_expr_t*)expr)->head == warn_sym) {
        size_t nargs = code_expr_nargs(expr);
        for (int i = 0; i < nargs - 1; i++) {
            code_value_t *warning = code_exprarg(expr, i);
            size_t nargs = 0;
            if (code_is_expr(warning) && ((code_expr_t*)warning)->head == warn_sym)
                 nargs = code_expr_nargs(warning);
            int kwargs_len = (int)nargs - 6;
            if (nargs < 6 || kwargs_len % 2 != 0) {
                code_error("code-logmsg: bad argument list - expected "
                         ":warn level (symbol) group (symbol) id file line msg . kwargs");
            }
            code_value_t *level = code_exprarg(warning, 0);
            code_value_t *group = code_exprarg(warning, 1);
            code_value_t *id = code_exprarg(warning, 2);
            code_value_t *file = code_exprarg(warning, 3);
            code_value_t *line = code_exprarg(warning, 4);
            code_value_t *msg = code_exprarg(warning, 5);
            kwargs = code_alloc_vec_any(kwargs_len);
            for (int i = 0; i < kwargs_len; ++i) {
                code_array_ptr_set(kwargs, i, code_exprarg(warning, i + 6));
            }
            CODE_TYPECHK(logmsg, long, level);
            code_log(code_unbox_long(level), NULL, group, id, file, line, (code_value_t*)kwargs, msg);
        }
        expr = code_exprarg(expr, nargs - 1);
    }
    CODE_GC_POP();
    return expr;
}

// expand in a context where the expression value is unused
CODE_DLLEXPORT code_value_t *code_expand_stmt_with_loc(code_value_t *expr, code_module_t *inmodule,
                                                 const char *file, int line)
{
    CODE_TIMING(LOWERING, LOWERING);
    CODE_GC_PUSH1(&expr);
    expr = code_copy_ast(expr);
    expr = code_expand_macros(expr, inmodule, NULL, 0, ~(size_t)0, 1);
    expr = code_call_scm_on_ast_and_loc("code-expand-to-thunk-stmt", expr, inmodule, file, line);
    CODE_GC_POP();
    return expr;
}

CODE_DLLEXPORT code_value_t *code_expand_stmt(code_value_t *expr, code_module_t *inmodule)
{
    return code_expand_stmt_with_loc(expr, inmodule, "none", 0);
}


//------------------------------------------------------------------------------
// Parsing API and utils for calling parser from runtime

// Internal C entry point to parser
// `text` is passed as a pointer to allow raw non-String buffers to be used
// without copying.
code_value_t *code_parse(const char *text, size_t text_len, code_value_t *filename,
                     size_t lineno, size_t offset, code_value_t *options)
{
    code_value_t *core_parse = NULL;
    if (code_core_module) {
        core_parse = code_get_global(code_core_module, code_symbol("_parse"));
    }
    if (!core_parse || core_parse == code_nothing) {
        // In bootstrap, directly call the builtin parser.
        code_value_t *result = code_fl_parse(text, text_len, filename, lineno, offset, options);
        return result;
    }
    code_value_t **args;
    CODE_GC_PUSHARGS(args, 6);
    args[0] = core_parse;
    args[1] = (code_value_t*)code_alloc_svec(2);
    code_svecset(args[1], 0, code_box_uint8pointer((uint8_t*)text));
    code_svecset(args[1], 1, code_box_long(text_len));
    args[2] = filename;
    args[3] = code_box_long(lineno);
    args[4] = code_box_long(offset);
    args[5] = options;
    code_task_t *ct = code_current_task;
    size_t last_age = ct->world_age;
    ct->world_age = code_atomic_load_acquire(&code_world_counter);
    code_value_t *result = code_apply(args, 6);
    ct->world_age = last_age;
    args[0] = result; // root during error checks below
    CODE_TYPECHK(parse, simplevector, result);
    if (code_svec_len(result) != 2)
        code_error("Result from parser should be `svec(a::Expr, b::Int)`");
    CODE_TYPECHK(parse, expr, code_svecref(result, 0));
    CODE_TYPECHK(parse, long, code_svecref(result, 1));
    CODE_GC_POP();
    return result;
}

// parse an entire string as a file, reading multiple expressions
CODE_DLLEXPORT code_value_t *code_parse_all(const char *text, size_t text_len,
                                      const char *filename, size_t filename_len, size_t lineno)
{
    code_value_t *fname = code_pchar_to_string(filename, filename_len);
    CODE_GC_PUSH1(&fname);
    code_value_t *p = code_parse(text, text_len, fname, lineno, 0, (code_value_t*)code_all_sym);
    CODE_GC_POP();
    return code_svecref(p, 0);
}

// this is for parsing one expression out of a string, keeping track of
// the current position.
CODE_DLLEXPORT code_value_t *code_parse_string(const char *text, size_t text_len,
                                         int offset, int greedy)
{
    code_value_t *fname = code_cstr_to_string("none");
    CODE_GC_PUSH1(&fname);
    code_value_t *result = code_parse(text, text_len, fname, 1, offset,
                                  (code_value_t*)(greedy ? code_statement_sym : code_atom_sym));
    CODE_GC_POP();
    return result;
}

// deprecated
CODE_DLLEXPORT code_value_t *code_parse_input_line(const char *text, size_t text_len,
                                             const char *filename, size_t filename_len)
{
    return code_parse_all(text, text_len, filename, filename_len, 1);
}

#ifdef __cplusplus
}
#endif
