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
#include <setjmp.h>
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

typedef struct {
    language_code_info_t *src; // contains the names and number of slots
    language_method_instance_t *mi; // MethodInstance we're executing, or NULL if toplevel
    language_code_instance_t *ci; // CodeInstance we're executing (for generated functions)
    language_module_t *module; // context for globals
    language_value_t **locals; // slots for holding local slots and ssavalues
    language_svec_t *sparam_vals; // method static parameters, if eval-ing a method body
    size_t ip; // Leak the currently-evaluating statement index to backtrace capture
    int preevaluation; // use special rules for pre-evaluating expressions (deprecated--only for ccall handling)
    int continue_at; // statement index to jump to after leaving exception handler (0 if none)
} interpreter_state;


// general alloca rules are incompatible on C and C++, so define a macro that deals with the difference
#ifdef __cplusplus
#define LANGUAGE_CPPALLOCA(var,n)                                                         \
  var = (decltype(var))alloca((n))
#else
#define LANGUAGE_CPPALLOCA(var,n)                                                         \
  LANGUAGE_GCC_IGNORE_START("-Wc++-compat")                                               \
  var = alloca((n));                                                                \
  LANGUAGE_GCC_IGNORE_STOP
#endif

#ifdef __clang_gcanalyzer__

extern void LANGUAGE_GC_ENABLEFRAME(interpreter_state*) LANGUAGE_NOTSAFEPOINT;

// This is necessary, because otherwise the analyzer considers this undefined
// behavior and terminates the exploration
#define LANGUAGE_GC_PUSHFRAME(frame,locals,n)     \
  LANGUAGE_CPPALLOCA(frame, sizeof(*frame)+((n) * sizeof(language_value_t*)));  \
  memset(&frame[1], 0, sizeof(void*) * n); \
  _LANGUAGE_GC_PUSHARGS((language_value_t**)&frame[1], n); \
  locals = (language_value_t**)&frame[1];

#else

#define LANGUAGE_GC_ENCODE_PUSHFRAME(n)  ((((size_t)(n))<<2)|2)

#define LANGUAGE_GC_PUSHFRAME(frame,locals,n)                                             \
  LANGUAGE_CPPALLOCA(frame, sizeof(*frame)+(((n)+3)*sizeof(language_value_t*)));                \
  ((void**)&frame[1])[0] = NULL;                                                    \
  ((void**)&frame[1])[1] = (void*)LANGUAGE_GC_ENCODE_PUSHFRAME(n);                        \
  ((void**)&frame[1])[2] = language_pgcstack;                                             \
  memset(&((void**)&frame[1])[3], 0, (n)*sizeof(language_value_t*));                      \
  language_pgcstack = (language_gcframe_t*)&(((void**)&frame[1])[1]);                           \
  locals = &((language_value_t**)&frame[1])[3];

// we define this separately so that we can populate the frame before we add it to the backtrace
// it's recommended to mark the containing function with NOINLINE, though not essential
#define LANGUAGE_GC_ENABLEFRAME(frame) \
    language_signal_fence(); \
    ((void**)&frame[1])[0] = __builtin_frame_address(0);

#endif


static language_value_t *eval_value(language_value_t *e, interpreter_state *s);
static language_value_t *eval_body(language_array_t *stmts, interpreter_state *s, size_t ip, int toplevel);

// method definition form

static language_value_t *eval_methoddef(language_expr_t *ex, interpreter_state *s)
{
    language_value_t **args = language_array_ptr_data(ex->args);

    // generic function definition
    if (language_expr_nargs(ex) == 1) {
        language_value_t **args = language_array_ptr_data(ex->args);
        language_sym_t *fname = (language_sym_t*)args[0];
        language_module_t *modu = s->module;
        if (language_is_globalref(fname)) {
            modu = language_globalref_mod(fname);
            fname = language_globalref_name(fname);
        }
        if (!language_is_symbol(fname)) {
            language_error("method: invalid declaration");
        }
        language_binding_t *b = language_get_binding_for_method_def(modu, fname);
        _Atomic(language_value_t*) *bp = &b->value;
        language_value_t *gf = language_generic_function_def(fname, modu, bp, b);
        return gf;
    }

    language_value_t *atypes = NULL, *meth = NULL, *fname = NULL;
    LANGUAGE_GC_PUSH3(&atypes, &meth, &fname);

    fname = eval_value(args[0], s);
    language_methtable_t *mt = NULL;
    if (language_typetagis(fname, language_methtable_type)) {
        mt = (language_methtable_t*)fname;
    }
    atypes = eval_value(args[1], s);
    meth = eval_value(args[2], s);
    language_method_def((language_svec_t*)atypes, mt, (language_code_info_t*)meth, s->module);
    LANGUAGE_GC_POP();
    return language_nothing;
}

// expression evaluator

static language_value_t *do_call(language_value_t **args, size_t nargs, interpreter_state *s)
{
    language_value_t **argv;
    assert(nargs >= 1);
    LANGUAGE_GC_PUSHARGS(argv, nargs);
    size_t i;
    for (i = 0; i < nargs; i++)
        argv[i] = eval_value(args[i], s);
    language_value_t *result = language_apply(argv, nargs);
    LANGUAGE_GC_POP();
    return result;
}

static language_value_t *do_invoke(language_value_t **args, size_t nargs, interpreter_state *s)
{
    language_value_t **argv;
    assert(nargs >= 2);
    LANGUAGE_GC_PUSHARGS(argv, nargs - 1);
    size_t i;
    for (i = 1; i < nargs; i++)
        argv[i] = eval_value(args[i], s);
    language_method_instance_t *meth = (language_method_instance_t*)args[0];
    assert(language_is_method_instance(meth));
    language_value_t *result = language_invoke(argv[1], &argv[2], nargs - 2, meth);
    LANGUAGE_GC_POP();
    return result;
}

language_value_t *language_eval_global_var(language_module_t *m, language_sym_t *e)
{
    language_value_t *v = language_get_global(m, e);
    if (v == NULL)
        language_undefined_var_error(e, (language_value_t*)m);
    return v;
}

language_value_t *language_eval_globalref(language_globalref_t *g)
{
    language_value_t *v = language_get_globalref_value(g);
    if (v == NULL)
        language_undefined_var_error(g->name, (language_value_t*)g->mod);
    return v;
}

static int language_source_nslots(language_code_info_t *src) LANGUAGE_NOTSAFEPOINT
{
    return language_array_nrows(src->slotflags);
}

static int language_source_nssavalues(language_code_info_t *src) LANGUAGE_NOTSAFEPOINT
{
    return language_is_long(src->ssavaluetypes) ? language_unbox_long(src->ssavaluetypes) : language_array_nrows(src->ssavaluetypes);
}

static void eval_stmt_value(language_value_t *stmt, interpreter_state *s)
{
    language_value_t *res = eval_value(stmt, s);
    s->locals[language_source_nslots(s->src) + s->ip] = res;
}

static language_value_t *eval_value(language_value_t *e, interpreter_state *s)
{
    language_code_info_t *src = s->src;
    if (language_is_ssavalue(e)) {
        ssize_t id = ((language_ssavalue_t*)e)->id - 1;
        if (src == NULL || id >= language_source_nssavalues(src) || id < 0 || s->locals == NULL)
            language_error("access to invalid SSAValue");
        else
            return s->locals[language_source_nslots(src) + id];
    }
    if (language_is_slotnumber(e) || language_is_argument(e)) {
        ssize_t n = language_slot_number(e);
        if (src == NULL || n > language_source_nslots(src) || n < 1 || s->locals == NULL)
            language_error("access to invalid slot number");
        language_value_t *v = s->locals[n - 1];
        if (v == NULL)
            language_undefined_var_error((language_sym_t*)language_array_ptr_ref(src->slotnames, n - 1), (language_value_t*)language_local_sym);
        return v;
    }
    if (language_is_quotenode(e)) {
        return language_quotenode_value(e);
    }
    if (language_is_globalref(e)) {
        return language_eval_globalref((language_globalref_t*)e);
    }
    if (language_is_symbol(e)) {  // bare symbols appear in toplevel exprs not wrapped in `thunk`
        return language_eval_global_var(s->module, (language_sym_t*)e);
    }
    if (language_is_pinode(e)) {
        language_value_t *val = eval_value(language_fieldref_noalloc(e, 0), s);
#ifndef LANGUAGE_NDEBUG
        LANGUAGE_GC_PUSH1(&val);
        language_typeassert(val, language_fieldref_noalloc(e, 1));
        LANGUAGE_GC_POP();
#endif
        return val;
    }
    assert(!language_is_phinode(e) && !language_is_phicnode(e) && !language_is_upsilonnode(e) && "malformed IR");
    if (!language_is_expr(e))
        return e;
    language_expr_t *ex = (language_expr_t*)e;
    language_value_t **args = language_array_ptr_data(ex->args);
    size_t nargs = language_array_nrows(ex->args);
    language_sym_t *head = ex->head;
    if (head == language_call_sym) {
        return do_call(args, nargs, s);
    }
    else if (head == language_invoke_sym) {
        return do_invoke(args, nargs, s);
    }
    else if (head == language_invoke_modify_sym) {
        return do_call(args + 1, nargs - 1, s);
    }
    else if (head == language_isdefined_sym) {
        language_value_t *sym = args[0];
        int defined = 0;
        if (language_is_slotnumber(sym) || language_is_argument(sym)) {
            ssize_t n = language_slot_number(sym);
            if (src == NULL || n > language_source_nslots(src) || n < 1 || s->locals == NULL)
                language_error("access to invalid slot number");
            defined = s->locals[n - 1] != NULL;
        }
        else if (language_is_globalref(sym)) {
            defined = language_boundp(language_globalref_mod(sym), language_globalref_name(sym));
        }
        else if (language_is_symbol(sym)) {
            defined = language_boundp(s->module, (language_sym_t*)sym);
        }
        else if (language_is_expr(sym) && ((language_expr_t*)sym)->head == language_static_parameter_sym) {
            ssize_t n = language_unbox_long(language_exprarg(sym, 0));
            assert(n > 0);
            if (s->sparam_vals && n <= language_svec_len(s->sparam_vals)) {
                language_value_t *sp = language_svecref(s->sparam_vals, n - 1);
                defined = !language_is_typevar(sp);
            }
            else {
                // static parameter val unknown needs to be an error for ccall
                language_error("could not determine static parameter value");
            }
        }
        else {
            assert(0 && "malformed isdefined expression");
        }
        return defined ? language_true : language_false;
    }
    else if (head == language_throw_undef_if_not_sym) {
        language_value_t *cond = eval_value(args[1], s);
        assert(language_is_bool(cond));
        if (cond == language_false) {
            language_sym_t *var = (language_sym_t*)args[0];
            if (var == language_getfield_undefref_sym)
                language_throw(language_undefref_exception);
            else
                language_undefined_var_error(var, (language_value_t*)language_local_sym);
        }
        return language_nothing;
    }
    else if (head == language_new_sym) {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, nargs);
        for (size_t i = 0; i < nargs; i++)
            argv[i] = eval_value(args[i], s);
        language_value_t *v = language_new_structv((language_datatype_t*)argv[0], &argv[1], nargs - 1);
        LANGUAGE_GC_POP();
        return v;
    }
    else if (head == language_splatnew_sym) {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, 2);
        argv[0] = eval_value(args[0], s);
        argv[1] = eval_value(args[1], s);
        language_value_t *v = language_new_structt((language_datatype_t*)argv[0], argv[1]);
        LANGUAGE_GC_POP();
        return v;
    }
    else if (head == language_new_opaque_closure_sym) {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, nargs);
        for (size_t i = 0; i < nargs; i++)
            argv[i] = eval_value(args[i], s);
        LANGUAGE_NARGSV(new_opaque_closure, 4);
        language_value_t *ret = (language_value_t*)language_new_opaque_closure((language_tupletype_t*)argv[0], argv[1], argv[2],
            argv[3], argv+4, nargs-4, 1);
        LANGUAGE_GC_POP();
        return ret;
    }
    else if (head == language_static_parameter_sym) {
        ssize_t n = language_unbox_long(args[0]);
        assert(n > 0);
        if (s->sparam_vals && n <= language_svec_len(s->sparam_vals)) {
            language_value_t *sp = language_svecref(s->sparam_vals, n - 1);
            if (language_is_typevar(sp) && !s->preevaluation)
                language_undefined_var_error(((language_tvar_t*)sp)->name, (language_value_t*)language_static_parameter_sym);
            return sp;
        }
        // static parameter val unknown needs to be an error for ccall
        language_error("could not determine static parameter value");
    }
    else if (head == language_copyast_sym) {
        return language_copy_ast(eval_value(args[0], s));
    }
    else if (head == language_exc_sym) {
        return language_current_exception(language_current_task);
    }
    else if (head == language_boundscheck_sym) {
        return language_true;
    }
    else if (head == language_meta_sym || head == language_coverageeffect_sym || head == language_inbounds_sym || head == language_loopinfo_sym ||
             head == language_aliasscope_sym || head == language_popaliasscope_sym || head == language_inline_sym || head == language_noinline_sym) {
        return language_nothing;
    }
    else if (head == language_gc_preserve_begin_sym || head == language_gc_preserve_end_sym) {
        // The interpreter generally keeps values that were assigned in this scope
        // rooted. If the interpreter learns to be more aggressive here, we may
        // want to explicitly root these values.
        return language_nothing;
    }
    else if (head == language_method_sym && nargs == 1) {
        return eval_methoddef(ex, s);
    }
    else if (head == language_foreigncall_sym) {
        language_error("`ccall` requires the compiler");
    }
    else if (head == language_cfunction_sym) {
        language_error("`cfunction` requires the compiler");
    }
    language_errorf("unsupported or misplaced expression %s", language_symbol_name(head));
    abort();
}

// phi nodes don't behave like proper instructions, so we require a special interpreter to handle them
static size_t eval_phi(language_array_t *stmts, interpreter_state *s, size_t ns, size_t to)
{
    size_t from = s->ip;
    size_t ip = to;
    unsigned nphiblockstmts = 0;
    unsigned last_phi = 0;
    for (ip = to; ip < ns; ip++) {
        language_value_t *e = language_array_ptr_ref(stmts, ip);
        if (!language_is_phinode(e)) {
            if (language_is_expr(e) || language_is_returnnode(e) || language_is_gotoifnot(e) ||
                language_is_gotonode(e) || language_is_phicnode(e) || language_is_upsilonnode(e) ||
                language_is_ssavalue(e)) {
                break;
            }
            // Everything else is allowed in the phi-block for implementation
            // convenience - fall through.
        } else {
            last_phi = nphiblockstmts + 1;
        }
        nphiblockstmts += 1;
    }
    // Cut off the phi block at the last phi node. For global refs that are not
    // actually in the phi block, we want to evaluate them in the regular interpreter
    // loop instead to make sure exception state is set up properly in case they throw.
    nphiblockstmts = last_phi;
    ip = to + last_phi;
    if (nphiblockstmts) {
        language_value_t **dest = &s->locals[language_source_nslots(s->src) + to];
        language_value_t **phis; // = (language_value_t**)alloca(sizeof(language_value_t*) * nphiblockstmts);
        LANGUAGE_GC_PUSHARGS(phis, nphiblockstmts);
        for (unsigned i = 0; i < nphiblockstmts; i++) {
            language_value_t *e = language_array_ptr_ref(stmts, to + i);
            if (!language_is_phinode(e)) {
                // IR verification guarantees that the only thing that gets
                // evaluated here are constants, so it doesn't matter if we
                // update the locals or the phis, but let's be consistent
                // for simplicity.
                phis[i] = eval_value(e, s);
                continue;
            }
            language_array_t *edges = (language_array_t*)language_fieldref_noalloc(e, 0);
            ssize_t edge = -1;
            size_t closest = to; // implicit edge has `to <= edge - 1 < to + i`
            // this is because we could see the following IR (all 1-indexed):
            //   goto %3 unless %cond
            //   %2 = phi ...
            //   %3 = phi (1)[1 => %a], (2)[2 => %b]
            // from = 1, to = closest = 2, i = 1 --> edge = 2, edge_from = 2, from = 2
            for (unsigned j = 0; j < language_array_nrows(edges); ++j) {
                size_t edge_from = language_array_data(edges, int32_t)[j]; // 1-indexed
                if (edge_from == from + 1) {
                    if (edge == -1)
                        edge = j;
                }
                else if (closest < edge_from && edge_from < (to + i + 1)) {
                    // if we found a nearer implicit branch from fall-through,
                    // that occurred since the last explicit branch,
                    // we should use the value from that edge instead
                    edge = j;
                    closest = edge_from;
                }
            }
            language_value_t *val = NULL;
            unsigned n_oldphi = closest - to;
            if (n_oldphi) {
                // promote this implicit branch to a basic block start
                // and move all phi values to their position in edges
                // note that we might have already processed some phi nodes
                // in this basic block, so we need to be extra careful here
                // to ignore those
                for (unsigned j = 0; j < n_oldphi; j++) {
                    dest[j] = phis[j];
                }
                for (unsigned j = n_oldphi; j < i; j++) {
                    // move the rest to the start of phis
                    phis[j - n_oldphi] = phis[j];
                    phis[j] = NULL;
                }
                from = closest - 1;
                i -= n_oldphi;
                dest += n_oldphi;
                to += n_oldphi;
                nphiblockstmts -= n_oldphi;
            }
            if (edge != -1) {
                // if edges list doesn't contain last branch, or the value is explicitly undefined
                // then this value should be unused.
                language_array_t *values = (language_array_t*)language_fieldref_noalloc(e, 1);
                val = language_array_ptr_ref(values, edge);
                if (val)
                    val = eval_value(val, s);
            }
            phis[i] = val;
        }
        // now move all phi values to their position in edges
        for (unsigned j = 0; j < nphiblockstmts; j++) {
            dest[j] = phis[j];
        }
        LANGUAGE_GC_POP();
    }
    return ip;
}

static language_value_t *eval_body(language_array_t *stmts, interpreter_state *s, size_t ip, int toplevel)
{
    language_handler_t __eh;
    size_t ns = language_array_nrows(stmts);
    language_task_t *ct = language_current_task;

    while (1) {
        s->ip = ip;
        if (ip >= ns)
            language_error("`body` expression must terminate in `return`. Use `block` instead.");
        if (toplevel)
            ct->world_age = language_atomic_load_acquire(&language_world_counter);
        language_value_t *stmt = language_array_ptr_ref(stmts, ip);
        assert(!language_is_phinode(stmt));
        size_t next_ip = ip + 1;
        assert(!language_is_phinode(stmt) && !language_is_phicnode(stmt) && "malformed IR");
        if (language_is_gotonode(stmt)) {
            next_ip = language_gotonode_label(stmt) - 1;
        }
        else if (language_is_gotoifnot(stmt)) {
            language_value_t *cond = eval_value(language_gotoifnot_cond(stmt), s);
            if (cond == language_false) {
                next_ip = language_gotoifnot_label(stmt) - 1;
            }
            else if (cond != language_true) {
                language_type_error("if", (language_value_t*)language_bool_type, cond);
            }
        }
        else if (language_is_returnnode(stmt)) {
            return eval_value(language_returnnode_value(stmt), s);
        }
        else if (language_is_upsilonnode(stmt)) {
            language_value_t *val = language_fieldref_noalloc(stmt, 0);
            if (val)
                val = eval_value(val, s);
            language_value_t *phic = s->locals[language_source_nslots(s->src) + ip];
            assert(language_is_ssavalue(phic));
            ssize_t id = ((language_ssavalue_t*)phic)->id - 1;
            s->locals[language_source_nslots(s->src) + id] = val;
        }
        else if (language_is_enternode(stmt)) {
            language_enter_handler(ct, &__eh);
            // This is a bit tricky, but supports the implementation of PhiC nodes.
            // They are conceptually slots, but the slot to store to doesn't get explicitly
            // mentioned in the store (aka the "UpsilonNode") (this makes them integrate more
            // nicely with the rest of the SSA representation). In a compiler, we would figure
            // out which slot to store to at compile time when we encounter the statement. We
            // can't quite do that here, but we do something similar: We scan the catch entry
            // block (the only place where PhiC nodes may occur) to find all the Upsilons we
            // can possibly encounter. Then, we remember which slot they store to (we abuse the
            // SSA value result array for this purpose). TODO: We could do this only the first
            // time we encounter a given enter.
            size_t catch_ip = language_enternode_catch_dest(stmt);
            if (catch_ip) {
                catch_ip -= 1;
                while (catch_ip < ns) {
                    language_value_t *phicnode = language_array_ptr_ref(stmts, catch_ip);
                    if (!language_is_phicnode(phicnode))
                        break;
                    language_array_t *values = (language_array_t*)language_fieldref_noalloc(phicnode, 0);
                    for (size_t i = 0; i < language_array_nrows(values); ++i) {
                        language_value_t *val = language_array_ptr_ref(values, i);
                        assert(language_is_ssavalue(val));
                        size_t upsilon = ((language_ssavalue_t*)val)->id - 1;
                        assert(language_is_upsilonnode(language_array_ptr_ref(stmts, upsilon)));
                        s->locals[language_source_nslots(s->src) + upsilon] = language_box_ssavalue(catch_ip + 1);
                    }
                    s->locals[language_source_nslots(s->src) + catch_ip] = NULL;
                    catch_ip += 1;
                }
                // store current top of exception stack for restore in pop_exception.
            }
            s->locals[language_source_nslots(s->src) + ip] = language_box_ulong(language_excstack_state(ct));
            if (language_enternode_scope(stmt)) {
                language_value_t *old_scope = ct->scope;
                LANGUAGE_GC_PUSH1(&old_scope);
                language_value_t *new_scope = eval_value(language_enternode_scope(stmt), s);
                ct->scope = new_scope;
                if (!language_setjmp(__eh.eh_ctx, 1)) {
                    eval_body(stmts, s, next_ip, toplevel);
                    language_unreachable();
                }
                ct->scope = old_scope;
                LANGUAGE_GC_POP();
            }
            else {
                if (!language_setjmp(__eh.eh_ctx, 1)) {
                    eval_body(stmts, s, next_ip, toplevel);
                    language_unreachable();
                }
            }

            if (s->continue_at) { // means we reached a :leave expression
                language_eh_restore_state_noexcept(ct, &__eh);
                ip = s->continue_at;
                s->continue_at = 0;
                continue;
            }
            else { // a real exception
                language_eh_restore_state(ct, &__eh);
                ip = catch_ip;
                assert(language_enternode_catch_dest(stmt) != 0);
                continue;
            }
        }
        else if (language_is_expr(stmt)) {
            // Most exprs are allowed to end a BB by fall through
            language_sym_t *head = ((language_expr_t*)stmt)->head;
            if (head == language_assign_sym) {
                language_value_t *lhs = language_exprarg(stmt, 0);
                language_value_t *rhs = eval_value(language_exprarg(stmt, 1), s);
                if (language_is_slotnumber(lhs)) {
                    ssize_t n = language_slot_number(lhs);
                    assert(n <= language_source_nslots(s->src) && n > 0);
                    s->locals[n - 1] = rhs;
                }
                else {
                    language_module_t *modu;
                    language_sym_t *sym;
                    if (language_is_globalref(lhs)) {
                        modu = language_globalref_mod(lhs);
                        sym = language_globalref_name(lhs);
                    }
                    else {
                        assert(language_is_symbol(lhs));
                        modu = s->module;
                        sym = (language_sym_t*)lhs;
                    }
                    LANGUAGE_GC_PUSH1(&rhs);
                    language_binding_t *b = language_get_binding_wr(modu, sym);
                    language_checked_assignment(b, modu, sym, rhs);
                    LANGUAGE_GC_POP();
                }
            }
            else if (head == language_leave_sym) {
                int hand_n_leave = 0;
                for (int i = 0; i < language_expr_nargs(stmt); ++i) {
                    language_value_t *arg = language_exprarg(stmt, i);
                    if (arg == language_nothing)
                        continue;
                    assert(language_is_ssavalue(arg));
                    language_value_t *enter_stmt = language_array_ptr_ref(stmts, ((language_ssavalue_t*)arg)->id - 1);
                    if (enter_stmt == language_nothing)
                        continue;
                    hand_n_leave += 1;
                }
                if (hand_n_leave > 0) {
                    assert(hand_n_leave > 0);
                    // equivalent to language_pop_handler(hand_n_leave), longjmping
                    // to the :enter code above instead, which handles cleanup
                    language_handler_t *eh = ct->eh;
                    while (--hand_n_leave > 0)
                        eh = eh->prev;
                    // leave happens during normal control flow, but we must
                    // longjmp to pop the eval_body call for each enter.
                    s->continue_at = next_ip;
                    asan_unpoison_task_stack(ct, &eh->eh_ctx);
                    language_longjmp(eh->eh_ctx, 1);
                }
            }
            else if (head == language_pop_exception_sym) {
                size_t prev_state = language_unbox_ulong(eval_value(language_exprarg(stmt, 0), s));
                language_restore_excstack(ct, prev_state);
            }
            else if (toplevel) {
                if (head == language_method_sym && language_expr_nargs(stmt) > 1) {
                    eval_methoddef((language_expr_t*)stmt, s);
                }
                else if (head == language_toplevel_sym) {
                    language_value_t *res = language_toplevel_eval(s->module, stmt);
                    s->locals[language_source_nslots(s->src) + s->ip] = res;
                }
                else if (language_is_toplevel_only_expr(stmt)) {
                    language_toplevel_eval(s->module, stmt);
                }
                else if (head == language_meta_sym) {
                    if (language_expr_nargs(stmt) == 1 && language_exprarg(stmt, 0) == (language_value_t*)language_nospecialize_sym) {
                        language_set_module_nospecialize(s->module, 1);
                    }
                    if (language_expr_nargs(stmt) == 1 && language_exprarg(stmt, 0) == (language_value_t*)language_specialize_sym) {
                        language_set_module_nospecialize(s->module, 0);
                    }
                    if (language_expr_nargs(stmt) == 2) {
                        if (language_exprarg(stmt, 0) == (language_value_t*)language_optlevel_sym) {
                            if (language_is_long(language_exprarg(stmt, 1))) {
                                int n = language_unbox_long(language_exprarg(stmt, 1));
                                language_set_module_optlevel(s->module, n);
                            }
                        }
                        else if (language_exprarg(stmt, 0) == (language_value_t*)language_compile_sym) {
                            if (language_is_long(language_exprarg(stmt, 1))) {
                                language_set_module_compile(s->module, language_unbox_long(language_exprarg(stmt, 1)));
                            }
                        }
                        else if (language_exprarg(stmt, 0) == (language_value_t*)language_infer_sym) {
                            if (language_is_long(language_exprarg(stmt, 1))) {
                                language_set_module_infer(s->module, language_unbox_long(language_exprarg(stmt, 1)));
                            }
                        }
                        else if (language_exprarg(stmt, 0) == (language_value_t*)language_max_methods_sym) {
                            if (language_is_long(language_exprarg(stmt, 1))) {
                                language_set_module_max_methods(s->module, language_unbox_long(language_exprarg(stmt, 1)));
                            }
                        }
                    }
                }
                else {
                    eval_stmt_value(stmt, s);
                }
            }
            else {
                eval_stmt_value(stmt, s);
            }
        }
        else if (language_is_newvarnode(stmt)) {
            language_value_t *var = language_fieldref(stmt, 0);
            assert(language_is_slotnumber(var));
            ssize_t n = language_slot_number(var);
            assert(n <= language_source_nslots(s->src) && n > 0);
            s->locals[n - 1] = NULL;
        }
        else if (toplevel && language_is_linenode(stmt)) {
            language_lineno = language_linenode_line(stmt);
        }
        else {
            eval_stmt_value(stmt, s);
        }
        ip = eval_phi(stmts, s, ns, next_ip);
    }
    abort();
}

// preparing method IR for interpreter

language_value_t *language_code_or_ci_for_interpreter(language_method_instance_t *mi, size_t world)
{
    language_value_t *ret = NULL;
    language_code_info_t *src = NULL;
    if (language_is_method(mi->def.value)) {
        if (mi->def.method->source) {
            language_method_t *m = mi->def.method;
            src = (language_code_info_t*)m->source;
            if (!language_is_code_info(src)) {
                src = language_uncompress_ir(mi->def.method, NULL, (language_value_t*)src);
                // Replace the method source by the uncompressed version,
                // under the assumption that the interpreter may need to
                // access it frequently. TODO: Have some sort of usage-based
                // cache here.
                m->source = (language_value_t*)src;
                language_gc_wb(m, src);
            }
            ret = (language_value_t*)src;
        }
        else {
            language_code_instance_t *cache = language_atomic_load_relaxed(&mi->cache);
            language_code_instance_t *uninferred = language_cached_uninferred(cache, world);
            if (!uninferred) {
                assert(mi->def.method->generator);
                src = language_code_for_staged(mi, world, &uninferred);
            }
            ret = (language_value_t*)uninferred;
            src = (language_code_info_t*)language_atomic_load_relaxed(&uninferred->inferred);
        }
    }
    else {
        language_code_instance_t *uninferred = language_cached_uninferred(language_atomic_load_relaxed(&mi->cache), world);
        ret = (language_value_t*)uninferred;
        if (ret) {
            src = (language_code_info_t*)language_atomic_load_relaxed(&uninferred->inferred);
        }
    }
    if (!src || !language_is_code_info(src)) {
        language_throw(language_new_struct(language_missingcodeerror_type, (language_value_t*)mi));
    }
    return ret;
}

language_code_info_t *language_code_for_interpreter(language_method_instance_t *mi, size_t world)
{
    language_value_t *code_or_ci = language_code_or_ci_for_interpreter(mi, world);
    if (language_is_code_instance(code_or_ci))
        return (language_code_info_t*)language_atomic_load_relaxed(&((language_code_instance_t*)code_or_ci)->inferred);
    return (language_code_info_t*)code_or_ci;
}

// interpreter entry points

language_value_t *NOINLINE language_fptr_interpret_call(language_value_t *f, language_value_t **args, uint32_t nargs, language_code_instance_t *codeinst)
{
    interpreter_state *s;
    language_method_instance_t *mi = codeinst->def;
    language_task_t *ct = language_current_task;
    size_t world = ct->world_age;
    language_code_info_t *src = NULL;
    language_value_t *code = language_code_or_ci_for_interpreter(mi, world);
    language_code_instance_t *ci = NULL;
    if (language_is_code_instance(code)) {
        ci = (language_code_instance_t*)code;
        src = (language_code_info_t*)language_atomic_load_relaxed(&ci->inferred);
    } else {
        src = (language_code_info_t*)code;
    }
    language_array_t *stmts = src->code;
    assert(language_typetagis(stmts, language_array_any_type));
    unsigned nroots = language_source_nslots(src) + language_source_nssavalues(src) + 2;
    language_value_t **locals = NULL;
    LANGUAGE_GC_PUSHFRAME(s, locals, nroots);
    locals[0] = (language_value_t*)src;
    locals[1] = (language_value_t*)stmts;
    s->locals = locals + 2;
    s->src = src;
    if (language_is_module(mi->def.value)) {
        s->module = mi->def.module;
    }
    else {
        s->module = mi->def.method->module;
        size_t defargs = src->nargs;
        int isva = src->isva;
        size_t i;
        s->locals[0] = f;
        assert(isva ? nargs + 2 >= defargs : nargs + 1 == defargs);
        for (i = 1; i < defargs - isva; i++)
            s->locals[i] = args[i - 1];
        if (isva) {
            assert(defargs >= 2);
            s->locals[defargs - 1] = language_f_tuple(NULL, &args[defargs - 2], nargs + 2 - defargs);
        }
    }
    s->sparam_vals = mi->sparam_vals;
    s->preevaluation = 0;
    s->continue_at = 0;
    s->mi = mi;
    s->ci = ci;
    LANGUAGE_GC_ENABLEFRAME(s);
    language_value_t *r = eval_body(stmts, s, 0, 0);
    LANGUAGE_GC_POP();
    return r;
}

LANGUAGE_DLLEXPORT const language_callptr_t language_fptr_interpret_call_addr = &language_fptr_interpret_call;

language_value_t *language_interpret_opaque_closure(language_opaque_closure_t *oc, language_value_t **args, size_t nargs)
{
    language_method_t *source = oc->source;
    language_code_info_t *code = NULL;
    if (source->source) {
        code = language_uncompress_ir(source, NULL, (language_value_t*)source->source);
    }
    else {
        // OC constructed from optimized IR. It'll have a single specialization with optimized code
        // in it that we'll try to interpret.
        language_svec_t *specializations = (language_svec_t*)language_atomic_load_relaxed(&source->specializations);
        assert(language_is_method_instance(specializations));
        language_method_instance_t *mi = (language_method_instance_t *)specializations;
        language_code_instance_t *ci = language_atomic_load_relaxed(&mi->cache);
        code = language_uncompress_ir(source, ci, language_atomic_load_relaxed(&ci->inferred));
    }
    interpreter_state *s;
    unsigned nroots = language_source_nslots(code) + language_source_nssavalues(code) + 2;
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    ct->world_age = oc->world;
    language_value_t **locals = NULL;
    LANGUAGE_GC_PUSHFRAME(s, locals, nroots);
    locals[0] = (language_value_t*)oc;
    // The analyzer has some trouble with this
    locals[1] = (language_value_t*)code;
    LANGUAGE_GC_PROMISE_ROOTED(code);
    locals[2] = (language_value_t*)oc->captures;
    s->locals = locals + 2;
    s->src = code;
    s->module = source->module;
    s->sparam_vals = NULL;
    s->preevaluation = 0;
    s->continue_at = 0;
    s->mi = NULL;
    s->ci = NULL;
    size_t defargs = source->nargs;
    int isva = source->isva;
    assert(isva ? nargs + 2 >= defargs : nargs + 1 == defargs);
    for (size_t i = 1; i < defargs - isva; i++)
        s->locals[i] = args[i - 1];
    if (isva) {
        assert(defargs >= 2);
        s->locals[defargs - 1] = language_f_tuple(NULL, &args[defargs - 2], nargs + 2 - defargs);
    }
    LANGUAGE_GC_ENABLEFRAME(s);
    language_value_t *r = eval_body(code->code, s, 0, 0);
    locals[0] = r; // GC root
    LANGUAGE_GC_PROMISE_ROOTED(r);
    ct->world_age = last_age;
    language_typeassert(r, language_tparam1(language_typeof(oc)));
    LANGUAGE_GC_POP();
    return r;
}

language_value_t *NOINLINE language_interpret_toplevel_thunk(language_module_t *m, language_code_info_t *src)
{
    interpreter_state *s;
    unsigned nroots = language_source_nslots(src) + language_source_nssavalues(src);
    LANGUAGE_GC_PUSHFRAME(s, s->locals, nroots);
    language_array_t *stmts = src->code;
    assert(language_typetagis(stmts, language_array_any_type));
    s->src = src;
    s->module = m;
    s->sparam_vals = language_emptysvec;
    s->continue_at = 0;
    s->mi = NULL;
    s->ci = NULL;
    LANGUAGE_GC_ENABLEFRAME(s);
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    language_value_t *r = eval_body(stmts, s, 0, 1);
    ct->world_age = last_age;
    LANGUAGE_GC_POP();
    return r;
}

// deprecated: do not use this method in new code
// it uses special scoping / evaluation / error rules
// which should instead be handled in lowering
language_value_t *NOINLINE language_interpret_toplevel_expr_in(language_module_t *m, language_value_t *e, language_code_info_t *src, language_svec_t *sparam_vals)
{
    interpreter_state *s;
    language_value_t **locals;
    LANGUAGE_GC_PUSHFRAME(s, locals, 0);
    (void)locals;
    s->src = src;
    s->module = m;
    s->sparam_vals = sparam_vals;
    s->preevaluation = (sparam_vals != NULL);
    s->continue_at = 0;
    s->mi = NULL;
    s->ci = NULL;
    LANGUAGE_GC_ENABLEFRAME(s);
    language_value_t *v = eval_value(e, s);
    assert(v);
    LANGUAGE_GC_POP();
    return v;
}

LANGUAGE_DLLEXPORT size_t language_capture_interp_frame(language_bt_element_t *bt_entry,
        void *stateend, size_t space_remaining)
{
    interpreter_state *s = &((interpreter_state*)stateend)[-1];
    int need_module = !s->mi;
    int required_space = need_module ? 4 : 3;
    if (space_remaining < required_space)
        return 0; // Should not happen
    size_t njlvalues = need_module ? 2 : 1;
    uintptr_t entry_tags = language_bt_entry_descriptor(njlvalues, 0, LANGUAGE_BT_INTERP_FRAME_TAG, s->ip);
    bt_entry[0].uintptr = LANGUAGE_BT_NON_PTR_ENTRY;
    bt_entry[1].uintptr = entry_tags;
    bt_entry[2].jlvalue = s->ci  ? (language_value_t*)s->ci  :
                          s->mi  ? (language_value_t*)s->mi  :
                          s->src ? (language_value_t*)s->src : (language_value_t*)language_nothing;
    if (need_module) {
        // If we only have a CodeInfo (s->src), we are in a top level thunk and
        // need to record the module separately.
        bt_entry[3].jlvalue = (language_value_t*)s->module;
    }
    return required_space;
}


#ifdef __cplusplus
}
#endif
