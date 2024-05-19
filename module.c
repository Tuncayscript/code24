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
//

/*
  modules and top-level bindings
*/
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

LANGUAGE_DLLEXPORT language_module_t *language_new_module_(language_sym_t *name, language_module_t *parent, uint8_t default_names)
{
    language_task_t *ct = language_current_task;
    const language_uuid_t uuid_zero = {0, 0};
    language_module_t *m = (language_module_t*)language_gc_alloc(ct->ptls, sizeof(language_module_t),
                                               language_module_type);
    language_set_typetagof(m, language_module_tag, 0);
    assert(language_is_symbol(name));
    m->name = name;
    m->parent = parent;
    m->istopmod = 0;
    m->uuid = uuid_zero;
    static unsigned int mcounter; // simple counter backup, in case hrtime is not incrementing
    m->build_id.lo = language_hrtime() + (++mcounter);
    if (!m->build_id.lo)
        m->build_id.lo++; // build id 0 is invalid
    m->build_id.hi = ~(uint64_t)0;
    language_atomic_store_relaxed(&m->counter, 1);
    m->nospecialize = 0;
    m->optlevel = -1;
    m->compile = -1;
    m->infer = -1;
    m->max_methods = -1;
    m->hash = parent == NULL ? bitmix(name->hash, language_module_type->hash) :
        bitmix(name->hash, parent->hash);
    LANGUAGE_MUTEX_INIT(&m->lock, "module->lock");
    language_atomic_store_relaxed(&m->bindings, language_emptysvec);
    language_atomic_store_relaxed(&m->bindingkeyset, (language_genericmemory_t*)language_an_empty_memory_any);
    arraylist_new(&m->usings, 0);
    if (language_core_module && default_names) {
        LANGUAGE_GC_PUSH1(&m);
        language_module_using(m, language_core_module);
        // export own name, so "using Foo" makes "Foo" itself visible
        language_set_const(m, name, (language_value_t*)m);
        language_module_public(m, name, 1);
        LANGUAGE_GC_POP();
    }
    return m;
}

LANGUAGE_DLLEXPORT language_module_t *language_new_module(language_sym_t *name, language_module_t *parent)
{
    return language_new_module_(name, parent, 1);
}

uint32_t language_module_next_counter(language_module_t *m)
{
    return language_atomic_fetch_add_relaxed(&m->counter, 1);
}

LANGUAGE_DLLEXPORT language_value_t *language_f_new_module(language_sym_t *name, uint8_t std_imports, uint8_t default_names)
{
    // TODO: should we prohibit this during incremental compilation?
    // TODO: the parent module is a lie
    language_module_t *m = language_new_module_(name, language_main_module, default_names);
    LANGUAGE_GC_PUSH1(&m);
    if (std_imports)
        language_add_standard_imports(m);
    LANGUAGE_GC_POP();
    // TODO: should we somehow try to gc-root this correctly?
    return (language_value_t*)m;
}

LANGUAGE_DLLEXPORT void language_set_module_nospecialize(language_module_t *self, int on)
{
    self->nospecialize = (on ? -1 : 0);
}

LANGUAGE_DLLEXPORT void language_set_module_optlevel(language_module_t *self, int lvl)
{
    self->optlevel = lvl;
}

LANGUAGE_DLLEXPORT int language_get_module_optlevel(language_module_t *m)
{
    int lvl = m->optlevel;
    while (lvl == -1 && m->parent != m && m != language_base_module) {
        m = m->parent;
        lvl = m->optlevel;
    }
    return lvl;
}

LANGUAGE_DLLEXPORT void language_set_module_compile(language_module_t *self, int value)
{
    self->compile = value;
}

LANGUAGE_DLLEXPORT int language_get_module_compile(language_module_t *m)
{
    int value = m->compile;
    while (value == -1 && m->parent != m && m != language_base_module) {
        m = m->parent;
        value = m->compile;
    }
    return value;
}

LANGUAGE_DLLEXPORT void language_set_module_infer(language_module_t *self, int value)
{
    self->infer = value;
    // no reason to specialize if inference is off
    if (!value)
        language_set_module_nospecialize(self, 1);
}

LANGUAGE_DLLEXPORT int language_get_module_infer(language_module_t *m)
{
    int value = m->infer;
    while (value == -1 && m->parent != m && m != language_base_module) {
        m = m->parent;
        value = m->infer;
    }
    return value;
}

LANGUAGE_DLLEXPORT void language_set_module_max_methods(language_module_t *self, int value)
{
    self->max_methods = value;
}

LANGUAGE_DLLEXPORT int language_get_module_max_methods(language_module_t *m)
{
    int value = m->max_methods;
    while (value == -1 && m->parent != m && m != language_base_module) {
        m = m->parent;
        value = m->max_methods;
    }
    return value;
}

LANGUAGE_DLLEXPORT void language_set_istopmod(language_module_t *self, uint8_t isprimary)
{
    self->istopmod = 1;
    if (isprimary) {
        language_top_module = self;
    }
}

LANGUAGE_DLLEXPORT uint8_t language_istopmod(language_module_t *mod)
{
    return mod->istopmod;
}

static language_globalref_t *language_new_globalref(language_module_t *mod, language_sym_t *name, language_binding_t *b)
{
    language_task_t *ct = language_current_task;
    language_globalref_t *g = (language_globalref_t*)language_gc_alloc(ct->ptls, sizeof(language_globalref_t), language_globalref_type);
    g->mod = mod;
    language_gc_wb(g, g->mod);
    g->name = name;
    g->binding = b;
    return g;
}

static language_binding_t *new_binding(language_module_t *mod, language_sym_t *name)
{
    language_task_t *ct = language_current_task;
    assert(language_is_module(mod) && language_is_symbol(name));
    language_binding_t *b = (language_binding_t*)language_gc_alloc(ct->ptls, sizeof(language_binding_t), language_binding_type);
    language_atomic_store_relaxed(&b->value, NULL);
    language_atomic_store_relaxed(&b->owner, NULL);
    language_atomic_store_relaxed(&b->ty, NULL);
    b->globalref = NULL;
    b->constp = 0;
    b->exportp = 0;
    b->publicp = 0;
    b->imported = 0;
    b->deprecated = 0;
    b->usingfailed = 0;
    b->padding = 0;
    LANGUAGE_GC_PUSH1(&b);
    b->globalref = language_new_globalref(mod, name, b);
    LANGUAGE_GC_POP();
    return b;
}

extern language_mutex_t language_modules_mutex;

static void check_safe_newbinding(language_module_t *m, language_sym_t *var)
{
    if (language_current_task->ptls->in_pure_callback)
        language_errorf("new globals cannot be created in a generated function");
    if (language_options.incremental && language_generating_output()) {
        LANGUAGE_LOCK(&language_modules_mutex);
        int open = ptrhash_has(&language_current_modules, (void*)m);
        if (!open && language_module_init_order != NULL) {
            size_t i, l = language_array_len(language_module_init_order);
            for (i = 0; i < l; i++) {
                if (m == (language_module_t*)language_array_ptr_ref(language_module_init_order, i)) {
                    open = 1;
                    break;
                }
            }
        }
        LANGUAGE_UNLOCK(&language_modules_mutex);
        if (!open) {
            language_errorf("Creating a new global in closed module `%s` (`%s`) breaks incremental compilation "
                      "because the side effects will not be permanent.",
                      language_symbol_name(m->name), language_symbol_name(var));
        }
    }
}

static language_module_t *language_binding_dbgmodule(language_binding_t *b, language_module_t *m, language_sym_t *var) LANGUAGE_GLOBALLY_ROOTED;

// get binding for assignment
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_wr(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 1);
    language_binding_t *b2 = language_atomic_load_relaxed(&b->owner);
    if (b2 != b) {
        if (b2 == NULL)
            check_safe_newbinding(m, var);
        if (b2 != NULL || (!language_atomic_cmpswap(&b->owner, &b2, b) && b2 != b)) {
            language_module_t *from = language_binding_dbgmodule(b, m, var);
            if (from == m)
                language_errorf("cannot assign a value to imported variable %s.%s",
                          language_symbol_name(from->name), language_symbol_name(var));
            else
                language_errorf("cannot assign a value to imported variable %s.%s from module %s",
                          language_symbol_name(from->name), language_symbol_name(var), language_symbol_name(m->name));
        }
    }
    return b;
}

// return module of binding
LANGUAGE_DLLEXPORT language_module_t *language_get_module_of_binding(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_binding(m, var);
    if (b == NULL)
        return NULL;
    return b->globalref->mod; // TODO: deprecate this?
}

// get binding for adding a method
// like language_get_binding_wr, but has different error paths and messages
LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_for_method_def(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 1);
    language_binding_t *b2 = language_atomic_load_relaxed(&b->owner);
    if (b2 != b) {
        if (b2 == NULL)
            check_safe_newbinding(m, var);
        if (b2 != NULL || (!language_atomic_cmpswap(&b->owner, &b2, b) && b2 != b)) {
            language_value_t *f = language_atomic_load_relaxed(&b2->value);
            language_module_t *from = language_binding_dbgmodule(b, m, var);
            if (f == NULL) {
                // we must have implicitly imported this with using, so call language_binding_dbgmodule to try to get the name of the module we got this from
                language_errorf("invalid method definition in %s: exported function %s.%s does not exist",
                          language_symbol_name(m->name), language_symbol_name(from->name), language_symbol_name(var));
            }
            // TODO: we might want to require explicitly importing types to add constructors
            //       or we might want to drop this error entirely
            if (!b->imported && !(b2->constp && language_is_type(f) && strcmp(language_symbol_name(var), "=>") != 0)) {
                language_errorf("invalid method definition in %s: function %s.%s must be explicitly imported to be extended",
                          language_symbol_name(m->name), language_symbol_name(from->name), language_symbol_name(var));
            }
            return b2;
        }
    }
    return b;
}

typedef struct _modstack_t {
    language_module_t *m;
    language_sym_t *var;
    struct _modstack_t *prev;
} modstack_t;

static language_binding_t *language_resolve_owner(language_binding_t *b/*optional*/, language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var, modstack_t *st);

static inline language_module_t *module_usings_getidx(language_module_t *m LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;

#ifndef __clang_gcanalyzer__
// The analyzer doesn't like looking through the arraylist, so just model the
// access for it using this function
static inline language_module_t *module_usings_getidx(language_module_t *m LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT {
    return (language_module_t*)m->usings.items[i];
}
#endif

static int eq_bindings(language_binding_t *owner, language_binding_t *alias)
{
    assert(owner == language_atomic_load_relaxed(&owner->owner));
    if (owner == alias)
        return 1;
    alias = language_atomic_load_relaxed(&alias->owner);
    if (owner == alias)
        return 1;
    if (owner->constp && alias->constp && language_atomic_load_relaxed(&owner->value) && language_atomic_load_relaxed(&alias->value) == language_atomic_load_relaxed(&owner->value))
        return 1;
    return 0;
}

// find a binding from a module's `usings` list
static language_binding_t *using_resolve_binding(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var, language_module_t **from, modstack_t *st, int warn)
{
    language_binding_t *b = NULL;
    language_module_t *owner = NULL;
    LANGUAGE_LOCK(&m->lock);
    int i = (int)m->usings.len - 1;
    LANGUAGE_UNLOCK(&m->lock);
    for (; i >= 0; --i) {
        LANGUAGE_LOCK(&m->lock);
        language_module_t *imp = module_usings_getidx(m, i);
        LANGUAGE_UNLOCK(&m->lock);
        language_binding_t *tempb = language_get_module_binding(imp, var, 0);
        if (tempb != NULL && tempb->exportp) {
            tempb = language_resolve_owner(NULL, imp, var, st); // find the owner for tempb
            if (tempb == NULL)
                // couldn't resolve; try next using (see issue #6105)
                continue;
            assert(language_atomic_load_relaxed(&tempb->owner) == tempb);
            if (b != NULL && !tempb->deprecated && !b->deprecated && !eq_bindings(tempb, b)) {
                if (warn) {
                    // set usingfailed=1 to avoid repeating this warning
                    // the owner will still be NULL, so it can be later imported or defined
                    tempb = language_get_module_binding(m, var, 1);
                    tempb->usingfailed = 1;
                    language_printf(LANGUAGE_STDERR,
                              "WARNING: both %s and %s export \"%s\"; uses of it in module %s must be qualified\n",
                              language_symbol_name(owner->name),
                              language_symbol_name(imp->name), language_symbol_name(var),
                              language_symbol_name(m->name));
                }
                return NULL;
            }
            if (owner == NULL || !tempb->deprecated) {
                owner = imp;
                b = tempb;
            }
        }
    }
    *from = owner;
    return b;
}

// for error message printing: look up the module that exported a binding to m as var
// this might not be the same as the owner of the binding, since the binding itself may itself have been imported from elsewhere
static language_module_t *language_binding_dbgmodule(language_binding_t *b, language_module_t *m, language_sym_t *var)
{
    language_binding_t *b2 = language_atomic_load_relaxed(&b->owner);
    if (b2 != b && !b->imported) {
        // for implicitly imported globals, try to re-resolve it to find the module we got it from most directly
        language_module_t *from = NULL;
        b = using_resolve_binding(m, var, &from, NULL, 0);
        if (b) {
            if (b2 == NULL || language_atomic_load_relaxed(&b->owner) == language_atomic_load_relaxed(&b2->owner))
                return from;
            // if we did not find it (or accidentally found a different one), ignore this
        }
    }
    return m;
}

static void language_binding_dep_message(language_module_t *m, language_sym_t *name, language_binding_t *b);

// get binding for reading. might return NULL for unbound.
static language_binding_t *language_resolve_owner(language_binding_t *b/*optional*/, language_module_t *m, language_sym_t *var, modstack_t *st)
{
    if (b == NULL)
        b = language_get_module_binding(m, var, 1);
    language_binding_t *b2 = language_atomic_load_relaxed(&b->owner);
    if (b2 == NULL) {
        if (b->usingfailed)
            return NULL;
        modstack_t top = { m, var, st };
        modstack_t *tmp = st;
        for (; tmp != NULL; tmp = tmp->prev) {
            if (tmp->m == m && tmp->var == var) {
                // import cycle without finding actual location
                return NULL;
            }
        }
        language_module_t *from = NULL; // for error message printing
        b2 = using_resolve_binding(m, var, &from, &top, 1);
        if (b2 == NULL)
            return NULL;
        assert(from);
        LANGUAGE_GC_PROMISE_ROOTED(from); // gc-analysis does not understand output parameters
        if (b2->deprecated) {
            if (language_atomic_load_relaxed(&b2->value) == language_nothing) {
                // silently skip importing deprecated values assigned to nothing (to allow later mutation)
                return NULL;
            }
        }
        // do a full import to prevent the result of this lookup from
        // changing, for example if this var is assigned to later.
        language_binding_t *owner = NULL;
        if (!language_atomic_cmpswap(&b->owner, &owner, b2)) {
            // concurrent import
            return owner;
        }
        if (b2->deprecated) {
            b->deprecated = 1; // we will warn about this below, but we might want to warn at the use sites too
            if (m != language_main_module && m != language_base_module &&
                language_options.depwarn != LANGUAGE_OPTIONS_DEPWARN_OFF) {
                /* with #22763, external packages wanting to replace
                   deprecated Base bindings should simply export the new
                   binding */
                language_printf(LANGUAGE_STDERR,
                          "WARNING: using deprecated binding %s.%s in %s.\n",
                          language_symbol_name(from->name), language_symbol_name(var),
                          language_symbol_name(m->name));
                language_binding_dep_message(from, var, b2);
            }
        }
    }
    assert(language_atomic_load_relaxed(&b2->owner) == b2);
    return b2;
}

// get the current likely owner of binding when accessing m.var, without resolving the binding (it may change later)
LANGUAGE_DLLEXPORT language_binding_t *language_binding_owner(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    language_module_t *from = m;
    if (b == NULL || (!b->usingfailed && language_atomic_load_relaxed(&b->owner) == NULL))
        b = using_resolve_binding(m, var, &from, NULL, 0);
    else
        b = language_atomic_load_relaxed(&b->owner);
    return b;
}

// get type of binding m.var, without resolving the binding
LANGUAGE_DLLEXPORT language_value_t *language_get_binding_type(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    if (b == NULL)
        return language_nothing;
    b = language_atomic_load_relaxed(&b->owner);
    if (b == NULL)
        return language_nothing;
    language_value_t *ty = language_atomic_load_relaxed(&b->ty);
    return ty ? ty : language_nothing;
}

LANGUAGE_DLLEXPORT language_binding_t *language_get_binding(language_module_t *m, language_sym_t *var)
{
    return language_resolve_owner(NULL, m, var, NULL);
}

LANGUAGE_DLLEXPORT language_binding_t *language_get_binding_or_error(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_binding(m, var);
    if (b == NULL)
        language_undefined_var_error(var, (language_value_t*)m);
    // XXX: this only considers if the original is deprecated, not the binding in m
    if (b->deprecated)
        language_binding_deprecation_warning(m, var, b);
    return b;
}

LANGUAGE_DLLEXPORT language_value_t *language_module_globalref(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 1);
    language_globalref_t *globalref = b->globalref;
    assert(globalref != NULL);
    return (language_value_t*)globalref;
}

// does module m explicitly import s?
LANGUAGE_DLLEXPORT int language_is_imported(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    return b && b->imported;
}

extern const char *language_filename;
extern int language_lineno;

static char const dep_message_prefix[] = "_dep_message_";

static void language_binding_dep_message(language_module_t *m, language_sym_t *name, language_binding_t *b)
{
    size_t prefix_len = strlen(dep_message_prefix);
    size_t name_len = strlen(language_symbol_name(name));
    char *dep_binding_name = (char*)alloca(prefix_len+name_len+1);
    memcpy(dep_binding_name, dep_message_prefix, prefix_len);
    memcpy(dep_binding_name + prefix_len, language_symbol_name(name), name_len);
    dep_binding_name[prefix_len+name_len] = '\0';
    language_binding_t *dep_message_binding = language_get_binding(m, language_symbol(dep_binding_name));
    language_value_t *dep_message = NULL;
    if (dep_message_binding != NULL)
        dep_message = language_atomic_load_relaxed(&dep_message_binding->value);
    LANGUAGE_GC_PUSH1(&dep_message);
    if (dep_message != NULL) {
        if (language_is_string(dep_message)) {
            language_uv_puts(LANGUAGE_STDERR, language_string_data(dep_message), language_string_len(dep_message));
        }
        else {
            language_static_show(LANGUAGE_STDERR, dep_message);
        }
    }
    else {
        language_value_t *v = language_atomic_load_relaxed(&b->value);
        dep_message = v; // use as gc-root
        if (v) {
            if (language_is_type(v) || language_is_module(v)) {
                language_printf(LANGUAGE_STDERR, ", use ");
                language_static_show(LANGUAGE_STDERR, v);
                language_printf(LANGUAGE_STDERR, " instead.");
            }
            else {
                language_methtable_t *mt = language_gf_mtable(v);
                if (mt != NULL) {
                    language_printf(LANGUAGE_STDERR, ", use ");
                    if (mt->module != language_core_module) {
                        language_static_show(LANGUAGE_STDERR, (language_value_t*)mt->module);
                        language_printf(LANGUAGE_STDERR, ".");
                    }
                    language_printf(LANGUAGE_STDERR, "%s", language_symbol_name(mt->name));
                    language_printf(LANGUAGE_STDERR, " instead.");
                }
            }
        }
    }
    language_printf(LANGUAGE_STDERR, "\n");
    LANGUAGE_GC_POP();
}

// NOTE: we use explici since explicit is a C++ keyword
static void module_import_(language_module_t *to, language_module_t *from, language_sym_t *asname, language_sym_t *s, int explici)
{
    language_binding_t *b = language_get_binding(from, s);
    if (b == NULL) {
        language_printf(LANGUAGE_STDERR,
                  "WARNING: could not import %s.%s into %s\n",
                  language_symbol_name(from->name), language_symbol_name(s),
                  language_symbol_name(to->name));
    }
    else {
        assert(language_atomic_load_relaxed(&b->owner) == b);
        if (b->deprecated) {
            if (language_atomic_load_relaxed(&b->value) == language_nothing) {
                // silently skip importing deprecated values assigned to nothing (to allow later mutation)
                return;
            }
            else if (to != language_main_module && to != language_base_module &&
                     language_options.depwarn != LANGUAGE_OPTIONS_DEPWARN_OFF) {
                /* with #22763, external packages wanting to replace
                   deprecated Base bindings should simply export the new
                   binding */
                language_printf(LANGUAGE_STDERR,
                          "WARNING: importing deprecated binding %s.%s into %s%s%s.\n",
                          language_symbol_name(from->name), language_symbol_name(s),
                          language_symbol_name(to->name),
                          asname == s ? "" : " as ",
                          asname == s ? "" : language_symbol_name(asname));
                language_binding_dep_message(from, s, b);
            }
        }

        language_binding_t *bto = language_get_module_binding(to, asname, 1);
        if (bto == b) {
            // importing a binding on top of itself. harmless.
            return;
        }
        language_binding_t *ownerto = NULL;
        if (language_atomic_cmpswap(&bto->owner, &ownerto, b)) {
            bto->imported |= (explici != 0);
            bto->deprecated |= b->deprecated; // we already warned about this above, but we might want to warn at the use sites too
        }
        else {
            if (eq_bindings(b, bto)) {
                // already imported
                bto->imported |= (explici != 0);
            }
            else if (ownerto != bto) {
                // already imported from somewhere else
                language_printf(LANGUAGE_STDERR,
                          "WARNING: ignoring conflicting import of %s.%s into %s\n",
                          language_symbol_name(from->name), language_symbol_name(s),
                          language_symbol_name(to->name));
            }
            else {
                // conflict with name owned by destination module
                language_printf(LANGUAGE_STDERR,
                          "WARNING: import of %s.%s into %s conflicts with an existing identifier; ignored.\n",
                          language_symbol_name(from->name), language_symbol_name(s),
                          language_symbol_name(to->name));
            }
        }
    }
}

LANGUAGE_DLLEXPORT void language_module_import(language_module_t *to, language_module_t *from, language_sym_t *s)
{
    module_import_(to, from, s, s, 1);
}

LANGUAGE_DLLEXPORT void language_module_import_as(language_module_t *to, language_module_t *from, language_sym_t *s, language_sym_t *asname)
{
    module_import_(to, from, asname, s, 1);
}

LANGUAGE_DLLEXPORT void language_module_use(language_module_t *to, language_module_t *from, language_sym_t *s)
{
    module_import_(to, from, s, s, 0);
}

LANGUAGE_DLLEXPORT void language_module_use_as(language_module_t *to, language_module_t *from, language_sym_t *s, language_sym_t *asname)
{
    module_import_(to, from, asname, s, 0);
}


LANGUAGE_DLLEXPORT void language_module_using(language_module_t *to, language_module_t *from)
{
    if (to == from)
        return;
    LANGUAGE_LOCK(&to->lock);
    for (size_t i = 0; i < to->usings.len; i++) {
        if (from == to->usings.items[i]) {
            LANGUAGE_UNLOCK(&to->lock);
            return;
        }
    }
    arraylist_push(&to->usings, from);
    language_gc_wb(to, from);
    LANGUAGE_UNLOCK(&to->lock);

    // print a warning if something visible via this "using" conflicts with
    // an existing identifier. note that an identifier added later may still
    // silently override a "using" name. see issue #2054.
    language_svec_t *table = language_atomic_load_relaxed(&from->bindings);
    for (size_t i = 0; i < language_svec_len(table); i++) {
        language_binding_t *b = (language_binding_t*)language_svecref(table, i);
        if ((void*)b == language_nothing)
            break;
        if (b->exportp && (language_atomic_load_relaxed(&b->owner) == b || b->imported)) {
            language_sym_t *var = b->globalref->name;
            language_binding_t *tob = language_get_module_binding(to, var, 0);
            if (tob && language_atomic_load_relaxed(&tob->owner) != NULL &&
                // don't warn for conflicts with the module name itself.
                // see issue #4715
                var != to->name &&
                !eq_bindings(language_atomic_load_relaxed(&tob->owner), b)) {
                language_printf(LANGUAGE_STDERR,
                          "WARNING: using %s.%s in module %s conflicts with an existing identifier.\n",
                          language_symbol_name(from->name), language_symbol_name(var),
                          language_symbol_name(to->name));
            }
        }
        table = language_atomic_load_relaxed(&from->bindings);
    }
}

LANGUAGE_DLLEXPORT void language_module_public(language_module_t *from, language_sym_t *s, int exported)
{
    language_binding_t *b = language_get_module_binding(from, s, 1);
    if (b->publicp) {
        // check for conflicting declarations
        if (b->exportp && !exported)
            language_errorf("cannot declare %s.%s public; it is already declared exported",
                      language_symbol_name(from->name), language_symbol_name(s));
        if (!b->exportp && exported)
            language_errorf("cannot declare %s.%s exported; it is already declared public",
                      language_symbol_name(from->name), language_symbol_name(s));
    }
    b->publicp = 1;
    b->exportp |= exported;
}

LANGUAGE_DLLEXPORT int language_boundp(language_module_t *m, language_sym_t *var) // unlike most queries here, this is currently seq_cst
{
    language_binding_t *b = language_get_binding(m, var);
    return b && (language_atomic_load(&b->value) != NULL);
}

LANGUAGE_DLLEXPORT int language_defines_or_exports_p(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    return b && (b->exportp || language_atomic_load_relaxed(&b->owner) == b);
}

LANGUAGE_DLLEXPORT int language_module_exports_p(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    return b && b->exportp;
}

LANGUAGE_DLLEXPORT int language_module_public_p(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    return b && b->publicp;
}

LANGUAGE_DLLEXPORT int language_binding_resolved_p(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_module_binding(m, var, 0);
    return b && language_atomic_load_relaxed(&b->owner) != NULL;
}

static uint_t bindingkey_hash(size_t idx, language_value_t *data)
{
    language_binding_t *b = (language_binding_t*)language_svecref(data, idx);
    language_sym_t *var = b->globalref->name;
    return var->hash;
}

static int bindingkey_eq(size_t idx, const void *var, language_value_t *data, uint_t hv)
{
    language_binding_t *b = (language_binding_t*)language_svecref(data, idx);
    language_sym_t *name = b->globalref->name;
    return var == name;
}

LANGUAGE_DLLEXPORT language_binding_t *language_get_module_binding(language_module_t *m, language_sym_t *var, int alloc)
{
    uint_t hv = var->hash;
    for (int locked = 0; ; locked++) {
        language_genericmemory_t *bindingkeyset = language_atomic_load_acquire(&m->bindingkeyset);
        language_svec_t *bindings = language_atomic_load_relaxed(&m->bindings);
        ssize_t idx = language_smallintset_lookup(bindingkeyset, bindingkey_eq, var, (language_value_t*)bindings, hv, 0); // acquire
        if (idx != -1) {
            language_binding_t *b = (language_binding_t*)language_svecref(bindings, idx); // relaxed
            if (locked)
                LANGUAGE_UNLOCK(&m->lock);
            return b;
        }
        if (!alloc) {
            return NULL;
        }
        else if (!locked) {
            LANGUAGE_LOCK(&m->lock);
        }
        else {
            size_t i, cl = language_svec_len(bindings);
            for (i = cl; i > 0; i--) {
                language_value_t *b = language_svecref(bindings, i - 1);
                if (b != language_nothing)
                    break;
            }
            if (i == cl) {
                size_t ncl = cl < 8 ? 8 : (cl*3)>>1; // grow 50%
                language_svec_t *nc = language_alloc_svec_uninit(ncl);
                if (i > 0)
                    memcpy((char*)language_svec_data(nc), language_svec_data(bindings), sizeof(void*) * i);
                for (size_t j = i; j < ncl; j++)
                    language_svec_data(nc)[j] = language_nothing;
                language_atomic_store_release(&m->bindings, nc);
                language_gc_wb(m, nc);
                bindings = nc;
            }
            language_binding_t *b = new_binding(m, var);
            assert(language_svecref(bindings, i) == language_nothing);
            language_svecset(bindings, i, b); // relaxed
            language_smallintset_insert(&m->bindingkeyset, (language_value_t*)m, bindingkey_hash, i, (language_value_t*)bindings); // release
            LANGUAGE_UNLOCK(&m->lock);
            return b;
        }
    }
}


LANGUAGE_DLLEXPORT language_value_t *language_get_globalref_value(language_globalref_t *gr)
{
    language_binding_t *b = gr->binding;
    b = language_resolve_owner(b, gr->mod, gr->name, NULL);
    // ignores b->deprecated
    return b == NULL ? NULL : language_atomic_load_relaxed(&b->value);
}

LANGUAGE_DLLEXPORT language_value_t *language_get_global(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_binding(m, var);
    if (b == NULL)
        return NULL;
    // XXX: this only considers if the original is deprecated, not the binding in m
    if (b->deprecated)
        language_binding_deprecation_warning(m, var, b);
    return language_atomic_load_relaxed(&b->value);
}

LANGUAGE_DLLEXPORT void language_set_global(language_module_t *m LANGUAGE_ROOTING_ARGUMENT, language_sym_t *var, language_value_t *val LANGUAGE_ROOTED_ARGUMENT)
{
    language_binding_t *bp = language_get_binding_wr(m, var);
    language_checked_assignment(bp, m, var, val);
}

LANGUAGE_DLLEXPORT void language_set_const(language_module_t *m LANGUAGE_ROOTING_ARGUMENT, language_sym_t *var, language_value_t *val LANGUAGE_ROOTED_ARGUMENT)
{
    // this function is mostly only used during initialization, so the data races here are not too important to us
    language_binding_t *bp = language_get_module_binding(m, var, 1);
    language_binding_t *b2 = NULL;
    if (!language_atomic_cmpswap(&bp->owner, &b2, bp) && b2 != bp)
        language_errorf("invalid redefinition of constant %s", language_symbol_name(var));
    if (language_atomic_load_relaxed(&bp->value) == NULL) {
        language_value_t *old_ty = NULL;
        language_atomic_cmpswap_relaxed(&bp->ty, &old_ty, (language_value_t*)language_any_type);
        uint8_t constp = 0;
        // if (language_atomic_cmpswap(&bp->constp, &constp, 1)) {
        if (constp = bp->constp, bp->constp = 1, constp == 0) {
            language_value_t *old = NULL;
            if (language_atomic_cmpswap(&bp->value, &old, val)) {
                language_gc_wb(bp, val);
                return;
            }
        }
    }
    language_errorf("invalid redefinition of constant %s", language_symbol_name(var));
}

LANGUAGE_DLLEXPORT int language_globalref_is_const(language_globalref_t *gr)
{
    language_binding_t *b = gr->binding;
    b = language_resolve_owner(b, gr->mod, gr->name, NULL);
    return b && b->constp;
}

LANGUAGE_DLLEXPORT int language_globalref_boundp(language_globalref_t *gr)
{
    language_binding_t *b = gr->binding;
    b = language_resolve_owner(b, gr->mod, gr->name, NULL);
    return b && language_atomic_load_relaxed(&b->value) != NULL;
}

LANGUAGE_DLLEXPORT int language_is_const(language_module_t *m, language_sym_t *var)
{
    language_binding_t *b = language_get_binding(m, var);
    return b && b->constp;
}

// set the deprecated flag for a binding:
//   0=not deprecated, 1=renamed, 2=moved to another package
LANGUAGE_DLLEXPORT void language_deprecate_binding(language_module_t *m, language_sym_t *var, int flag)
{
    // XXX: this deprecates the original value, which might be imported from elsewhere
    language_binding_t *b = language_get_binding(m, var);
    if (b) b->deprecated = flag;
}

LANGUAGE_DLLEXPORT int language_is_binding_deprecated(language_module_t *m, language_sym_t *var)
{
    if (language_binding_resolved_p(m, var)) {
        // XXX: this only considers if the original is deprecated, not this precise binding
        language_binding_t *b = language_get_binding(m, var);
        return b && b->deprecated;
    }
    return 0;
}

void language_binding_deprecation_warning(language_module_t *m, language_sym_t *s, language_binding_t *b)
{
    // Only print a warning for deprecated == 1 (renamed).
    // For deprecated == 2 (moved to a package) the binding is to a function
    // that throws an error, so we don't want to print a warning too.
    if (b->deprecated == 1 && language_options.depwarn) {
        if (language_options.depwarn != LANGUAGE_OPTIONS_DEPWARN_ERROR)
            language_printf(LANGUAGE_STDERR, "WARNING: ");
        assert(language_atomic_load_relaxed(&b->owner) == b);
        language_printf(LANGUAGE_STDERR, "%s.%s is deprecated",
                  language_symbol_name(m->name), language_symbol_name(s));
        language_binding_dep_message(m, s, b);

        if (language_options.depwarn != LANGUAGE_OPTIONS_DEPWARN_ERROR) {
            if (language_lineno != 0) {
                language_printf(LANGUAGE_STDERR, "  likely near %s:%d\n", language_filename, language_lineno);
            }
        }

        if (language_options.depwarn == LANGUAGE_OPTIONS_DEPWARN_ERROR) {
            language_errorf("use of deprecated variable: %s.%s",
                      language_symbol_name(m->name),
                      language_symbol_name(s));
        }
    }
}

language_value_t *language_check_binding_wr(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs LANGUAGE_MAYBE_UNROOTED, int reassign)
{
    language_value_t *old_ty = NULL;
    if (!language_atomic_cmpswap_relaxed(&b->ty, &old_ty, (language_value_t*)language_any_type)) {
        if (old_ty != (language_value_t*)language_any_type && language_typeof(rhs) != old_ty) {
            LANGUAGE_GC_PUSH1(&rhs); // callee-rooted
            if (!language_isa(rhs, old_ty))
                language_errorf("cannot assign an incompatible value to the global %s.%s.",
                          language_symbol_name(mod->name), language_symbol_name(var));
            LANGUAGE_GC_POP();
        }
    }
    else {
        old_ty = (language_value_t*)language_any_type;
    }
    if (b->constp) {
        if (reassign) {
            language_value_t *old = NULL;
            if (language_atomic_cmpswap(&b->value, &old, rhs)) {
                language_gc_wb(b, rhs);
                return NULL;
            }
            if (language_egal(rhs, old))
                return NULL;
            if (language_typeof(rhs) != language_typeof(old) || language_is_type(rhs) || language_is_module(rhs))
                reassign = 0;
            else
                language_safe_printf("WARNING: redefinition of constant %s.%s. This may fail, cause incorrect answers, or produce other errors.\n",
                               language_symbol_name(mod->name), language_symbol_name(var));
        }
        if (!reassign)
            language_errorf("invalid redefinition of constant %s.%s",
                      language_symbol_name(mod->name), language_symbol_name(var));
    }
    return old_ty;
}

LANGUAGE_DLLEXPORT void language_checked_assignment(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs)
{
    if (language_check_binding_wr(b, mod, var, rhs, 1) != NULL) {
        language_atomic_store_release(&b->value, rhs);
        language_gc_wb(b, rhs);
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_checked_swap(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs)
{
    language_check_binding_wr(b, mod, var, rhs, 0);
    language_value_t *old = language_atomic_exchange(&b->value, rhs);
    language_gc_wb(b, rhs);
    if (__unlikely(old == NULL))
        language_undefined_var_error(var, (language_value_t*)mod);
    return old;
}

LANGUAGE_DLLEXPORT language_value_t *language_checked_replace(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *expected, language_value_t *rhs)
{
    language_value_t *ty = language_check_binding_wr(b, mod, var, rhs, 0);
    return replace_value(ty, &b->value, (language_value_t*)b, expected, rhs, 1, mod, var);
}

LANGUAGE_DLLEXPORT language_value_t *language_checked_modify(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *op, language_value_t *rhs)
{
    language_value_t *ty = NULL;
    if (language_atomic_cmpswap_relaxed(&b->ty, &ty, (language_value_t*)language_any_type))
        ty = (language_value_t*)language_any_type;
    if (b->constp)
        language_errorf("invalid redefinition of constant %s.%s",
                  language_symbol_name(mod->name), language_symbol_name(var));
    return modify_value(ty, &b->value, (language_value_t*)b, op, rhs, 1, mod, var);
}

LANGUAGE_DLLEXPORT language_value_t *language_checked_assignonce(language_binding_t *b, language_module_t *mod, language_sym_t *var, language_value_t *rhs )
{
    language_check_binding_wr(b, mod, var, rhs, 0);
    language_value_t *old = NULL;
    if (language_atomic_cmpswap(&b->value, &old, rhs))
        language_gc_wb(b, rhs);
    return old;
}

LANGUAGE_DLLEXPORT void language_declare_constant(language_binding_t *b, language_module_t *mod, language_sym_t *var)
{
    // n.b. language_get_binding_wr should have ensured b->owner == b as mod.var
    if (language_atomic_load_relaxed(&b->owner) != b || (language_atomic_load_relaxed(&b->value) != NULL && !b->constp)) {
        language_errorf("cannot declare %s.%s constant; it already has a value",
                  language_symbol_name(mod->name), language_symbol_name(var));
    }
    b->constp = 1;
}

LANGUAGE_DLLEXPORT language_value_t *language_module_usings(language_module_t *m)
{
    LANGUAGE_LOCK(&m->lock);
    int j = m->usings.len;
    language_array_t *a = language_alloc_array_1d(language_array_any_type, j);
    LANGUAGE_GC_PUSH1(&a);
    for (int i = 0; j > 0; i++) {
        j--;
        language_module_t *imp = (language_module_t*)m->usings.items[i];
        language_array_ptr_set(a, j, (language_value_t*)imp);
    }
    LANGUAGE_UNLOCK(&m->lock); // may gc
    LANGUAGE_GC_POP();
    return (language_value_t*)a;
}

LANGUAGE_DLLEXPORT language_value_t *language_module_names(language_module_t *m, int all, int imported)
{
    language_array_t *a = language_alloc_array_1d(language_array_symbol_type, 0);
    LANGUAGE_GC_PUSH1(&a);
    language_svec_t *table = language_atomic_load_relaxed(&m->bindings);
    for (size_t i = 0; i < language_svec_len(table); i++) {
        language_binding_t *b = (language_binding_t*)language_svecref(table, i);
        if ((void*)b == language_nothing)
            break;
        language_sym_t *asname = b->globalref->name;
        int hidden = language_symbol_name(asname)[0]=='#';
        int main_public = (m == language_main_module && !(asname == language_eval_sym || asname == language_include_sym));
        if ((b->publicp ||
             (imported && b->imported) ||
             (language_atomic_load_relaxed(&b->owner) == b && !b->imported && (all || main_public))) &&
            (all || (!b->deprecated && !hidden))) {
            language_array_grow_end(a, 1);
            // n.b. change to language_arrayset if array storage allocation for Array{Symbols,1} changes:
            language_array_ptr_set(a, language_array_dim0(a)-1, (language_value_t*)asname);
        }
        table = language_atomic_load_relaxed(&m->bindings);
    }
    LANGUAGE_GC_POP();
    return (language_value_t*)a;
}

LANGUAGE_DLLEXPORT language_sym_t *language_module_name(language_module_t *m) { return m->name; }
LANGUAGE_DLLEXPORT language_module_t *language_module_parent(language_module_t *m) { return m->parent; }
language_module_t *language_module_root(language_module_t *m)
{
    while (1) {
        if (m->parent == NULL || m->parent == m)
            return m;
        m = m->parent;
    }
}

LANGUAGE_DLLEXPORT language_uuid_t language_module_build_id(language_module_t *m) { return m->build_id; }
LANGUAGE_DLLEXPORT language_uuid_t language_module_uuid(language_module_t* m) { return m->uuid; }

// TODO: make this part of the module constructor and read-only?
LANGUAGE_DLLEXPORT void language_set_module_uuid(language_module_t *m, language_uuid_t uuid) { m->uuid = uuid; }

int language_is_submodule(language_module_t *child, language_module_t *parent) LANGUAGE_NOTSAFEPOINT
{
    while (1) {
        if (parent == child)
            return 1;
        if (child == NULL || child == child->parent)
            return 0;
        child = child->parent;
    }
}

// Remove implicitly imported identifiers, effectively resetting all the binding
// resolution decisions for a module. This is dangerous, and should only be
// done for modules that are essentially empty anyway. The only use case for this
// is to leave `Main` as empty as possible in the default system image.
LANGUAGE_DLLEXPORT void language_clear_implicit_imports(language_module_t *m)
{
    LANGUAGE_LOCK(&m->lock);
    language_svec_t *table = language_atomic_load_relaxed(&m->bindings);
    for (size_t i = 0; i < language_svec_len(table); i++) {
        language_binding_t *b = (language_binding_t*)language_svecref(table, i);
        if ((void*)b == language_nothing)
            break;
        if (language_atomic_load_relaxed(&b->owner) && language_atomic_load_relaxed(&b->owner) != b && !b->imported)
            language_atomic_store_relaxed(&b->owner, NULL);
    }
    LANGUAGE_UNLOCK(&m->lock);
}

LANGUAGE_DLLEXPORT void language_init_restored_module(language_value_t *mod)
{
    if (!language_generating_output() || language_options.incremental) {
        language_module_run_initializer((language_module_t*)mod);
    }
    else {
        if (language_module_init_order == NULL)
            language_module_init_order = language_alloc_vec_any(0);
        language_array_ptr_1d_push(language_module_init_order, mod);
    }
}

#ifdef __cplusplus
}
#endif
