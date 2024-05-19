// f{<:Union{...}}(...) is a common pattern
// and expanding the Union may give a leaf function
static void _compile_all_tvar_union(language_value_t *methsig)
{
    int tvarslen = language_subtype_env_size(methsig);
    language_value_t *sigbody = methsig;
    language_value_t **roots;
    LANGUAGE_GC_PUSHARGS(roots, 1 + 2 * tvarslen);
    language_value_t **env = roots + 1;
    int *idx = (int*)alloca(sizeof(int) * tvarslen);
    int i;
    for (i = 0; i < tvarslen; i++) {
        assert(language_is_unionall(sigbody));
        idx[i] = 0;
        env[2 * i] = (language_value_t*)((language_unionall_t*)sigbody)->var;
        env[2 * i + 1] = language_bottom_type; // initialize the list with Union{}, since T<:Union{} is always a valid option
        sigbody = ((language_unionall_t*)sigbody)->body;
    }

    for (i = 0; i < tvarslen; /* incremented by inner loop */) {
        language_value_t **sig = &roots[0];
        LANGUAGE_TRY {
            // TODO: wrap in UnionAll for each tvar in env[2*i + 1] ?
            // currently doesn't matter much, since language_compile_hint doesn't work on abstract types
            *sig = (language_value_t*)language_instantiate_type_with(sigbody, env, tvarslen);
        }
        LANGUAGE_CATCH {
            goto getnext; // sigh, we found an invalid type signature. should we warn the user?
        }
        if (!language_has_concrete_subtype(*sig))
            goto getnext; // signature wouldn't be callable / is invalid -- skip it
        if (language_is_concrete_type(*sig)) {
            if (language_compile_hint((language_tupletype_t *)*sig))
                goto getnext; // success
        }

    getnext:
        for (i = 0; i < tvarslen; i++) {
            language_tvar_t *tv = (language_tvar_t*)env[2 * i];
            if (language_is_uniontype(tv->ub)) {
                size_t l = language_count_union_components(tv->ub);
                size_t j = idx[i];
                if (j == l) {
                    env[2 * i + 1] = language_bottom_type;
                    idx[i] = 0;
                }
                else {
                    language_value_t *ty = language_nth_union_component(tv->ub, j);
                    if (!language_is_concrete_type(ty))
                        ty = (language_value_t*)language_new_typevar(tv->name, tv->lb, ty);
                    env[2 * i + 1] = ty;
                    idx[i] = j + 1;
                    break;
                }
            }
            else {
                env[2 * i + 1] = (language_value_t*)tv;
            }
        }
    }
    LANGUAGE_GC_POP();
}

// f(::Union{...}, ...) is a common pattern
// and expanding the Union may give a leaf function
static void _compile_all_union(language_value_t *sig)
{
    language_tupletype_t *sigbody = (language_tupletype_t*)language_unwrap_unionall(sig);
    size_t count_unions = 0;
    size_t i, l = language_svec_len(sigbody->parameters);
    language_svec_t *p = NULL;
    language_value_t *methsig = NULL;

    for (i = 0; i < l; i++) {
        language_value_t *ty = language_svecref(sigbody->parameters, i);
        if (language_is_uniontype(ty))
            ++count_unions;
        else if (ty == language_bottom_type)
            return; // why does this method exist?
        else if (language_is_datatype(ty) && !language_has_free_typevars(ty) &&
                 ((!language_is_kind(ty) && ((language_datatype_t*)ty)->isconcretetype) ||
                  ((language_datatype_t*)ty)->name == language_type_typename))
            return; // no amount of union splitting will make this a leaftype signature
    }

    if (count_unions == 0 || count_unions >= 6) {
        _compile_all_tvar_union(sig);
        return;
    }

    int *idx = (int*)alloca(sizeof(int) * count_unions);
    for (i = 0; i < count_unions; i++) {
        idx[i] = 0;
    }

    LANGUAGE_GC_PUSH2(&p, &methsig);
    int idx_ctr = 0, incr = 0;
    while (!incr) {
        p = language_alloc_svec_uninit(l);
        for (i = 0, idx_ctr = 0, incr = 1; i < l; i++) {
            language_value_t *ty = language_svecref(sigbody->parameters, i);
            if (language_is_uniontype(ty)) {
                assert(idx_ctr < count_unions);
                size_t l = language_count_union_components(ty);
                size_t j = idx[idx_ctr];
                language_svecset(p, i, language_nth_union_component(ty, j));
                ++j;
                if (incr) {
                    if (j == l) {
                        idx[idx_ctr] = 0;
                    }
                    else {
                        idx[idx_ctr] = j;
                        incr = 0;
                    }
                }
                ++idx_ctr;
            }
            else {
                language_svecset(p, i, ty);
            }
        }
        methsig = language_apply_tuple_type(p, 1);
        methsig = language_rewrap_unionall(methsig, sig);
        _compile_all_tvar_union(methsig);
    }

    LANGUAGE_GC_POP();
}

static int compile_all_collect__(language_typemap_entry_t *ml, void *env)
{
    language_array_t *allmeths = (language_array_t*)env;
    language_method_t *m = ml->func.method;
    if (m->external_mt)
        return 1;
    if (m->source) {
        // method has a non-generated definition; can be compiled generically
        language_array_ptr_1d_push(allmeths, (language_value_t*)m);
    }
    return 1;
}

static int compile_all_collect_(language_methtable_t *mt, void *env)
{
    language_typemap_visitor(language_atomic_load_relaxed(&mt->defs), compile_all_collect__, env);
    return 1;
}

static void language_compile_all_defs(language_array_t *mis)
{
    language_array_t *allmeths = language_alloc_vec_any(0);
    LANGUAGE_GC_PUSH1(&allmeths);

    language_foreach_reachable_mtable(compile_all_collect_, allmeths);

    size_t i, l = language_array_nrows(allmeths);
    for (i = 0; i < l; i++) {
        language_method_t *m = (language_method_t*)language_array_ptr_ref(allmeths, i);
        if (language_is_datatype(m->sig) && language_isa_compileable_sig((language_tupletype_t*)m->sig, language_emptysvec, m)) {
            // method has a single compilable specialization, e.g. its definition
            // signature is concrete. in this case we can just hint it.
            language_compile_hint((language_tupletype_t*)m->sig);
        }
        else {
            // first try to create leaf signatures from the signature declaration and compile those
            _compile_all_union(m->sig);

            // finally, compile a fully generic fallback that can work for all arguments
            language_method_instance_t *unspec = language_get_unspecialized(m);
            if (unspec)
                language_array_ptr_1d_push(mis, (language_value_t*)unspec);
        }
    }

    LANGUAGE_GC_POP();
}

static int precompile_enq_specialization_(language_method_instance_t *mi, void *closure)
{
    assert(language_is_method_instance(mi));
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    while (codeinst) {
        int do_compile = 0;
        if (codeinst->owner != language_nothing) {
            // TODO(vchuravy) native code caching for foreign interpreters
        }
        else if (language_atomic_load_relaxed(&codeinst->invoke) != language_fptr_const_return) {
            language_value_t *inferred = language_atomic_load_relaxed(&codeinst->inferred);
            if (inferred &&
                inferred != language_nothing &&
                (language_options.compile_enabled != LANGUAGE_OPTIONS_COMPILE_ALL && language_ir_inlining_cost(inferred) == UINT16_MAX)) {
                do_compile = 1;
            }
            else if (language_atomic_load_relaxed(&codeinst->invoke) != NULL || language_atomic_load_relaxed(&codeinst->precompile)) {
                do_compile = 1;
            }
        }
        if (do_compile) {
            language_array_ptr_1d_push((language_array_t*)closure, (language_value_t*)mi);
            return 1;
        }
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    return 1;
}

static int precompile_enq_all_specializations__(language_typemap_entry_t *def, void *closure)
{
    language_method_t *m = def->func.method;
    if (m->external_mt)
        return 1;
    if ((m->name == language_symbol("__init__") || m->ccallable) && language_is_dispatch_tupletype(m->sig)) {
        // ensure `__init__()` and @ccallables get strongly-hinted, specialized, and compiled
        language_method_instance_t *mi = language_specializations_get_linfo(m, m->sig, language_emptysvec);
        language_array_ptr_1d_push((language_array_t*)closure, (language_value_t*)mi);
    }
    else {
        language_value_t *specializations = language_atomic_load_relaxed(&def->func.method->specializations);
        if (!language_is_svec(specializations)) {
            precompile_enq_specialization_((language_method_instance_t*)specializations, closure);
        }
        else {
            size_t i, l = language_svec_len(specializations);
            for (i = 0; i < l; i++) {
                language_value_t *mi = language_svecref(specializations, i);
                if (mi != language_nothing)
                    precompile_enq_specialization_((language_method_instance_t*)mi, closure);
            }
        }
    }
    if (m->ccallable)
        language_array_ptr_1d_push((language_array_t*)closure, (language_value_t*)m->ccallable);
    return 1;
}

static int precompile_enq_all_specializations_(language_methtable_t *mt, void *env)
{
    return language_typemap_visitor(language_atomic_load_relaxed(&mt->defs), precompile_enq_all_specializations__, env);
}

static void *language_precompile_(language_array_t *m, int external_linkage)
{
    language_array_t *m2 = NULL;
    language_method_instance_t *mi = NULL;
    LANGUAGE_GC_PUSH2(&m2, &mi);
    m2 = language_alloc_vec_any(0);
    for (size_t i = 0; i < language_array_nrows(m); i++) {
        language_value_t *item = language_array_ptr_ref(m, i);
        if (language_is_method_instance(item)) {
            mi = (language_method_instance_t*)item;
            size_t min_world = 0;
            size_t max_world = ~(size_t)0;
            if (mi != language_atomic_load_relaxed(&mi->def.method->unspecialized) && !language_isa_compileable_sig((language_tupletype_t*)mi->specTypes, mi->sparam_vals, mi->def.method))
                mi = language_get_specialization1((language_tupletype_t*)mi->specTypes, language_atomic_load_acquire(&language_world_counter), &min_world, &max_world, 0);
            if (mi)
                language_array_ptr_1d_push(m2, (language_value_t*)mi);
        }
        else {
            assert(language_is_simplevector(item));
            assert(language_svec_len(item) == 2);
            language_array_ptr_1d_push(m2, item);
        }
    }
    void *native_code = language_create_native(m2, NULL, NULL, 0, 1, external_linkage,
                                         language_atomic_load_acquire(&language_world_counter));
    LANGUAGE_GC_POP();
    return native_code;
}

static void *language_precompile(int all)
{
    // array of MethodInstances and ccallable aliases to include in the output
    language_array_t *m = language_alloc_vec_any(0);
    LANGUAGE_GC_PUSH1(&m);
    if (all)
        language_compile_all_defs(m);
    language_foreach_reachable_mtable(precompile_enq_all_specializations_, m);
    void *native_code = language_precompile_(m, 0);
    LANGUAGE_GC_POP();
    return native_code;
}

static void *language_precompile_worklist(language_array_t *worklist, language_array_t *extext_methods, language_array_t *new_ext_cis)
{
    if (!worklist)
        return NULL;
    // this "found" array will contain function
    // type signatures that were inferred but haven't been compiled
    language_array_t *m = language_alloc_vec_any(0);
    LANGUAGE_GC_PUSH1(&m);
    size_t i, n = language_array_nrows(worklist);
    for (i = 0; i < n; i++) {
        language_module_t *mod = (language_module_t*)language_array_ptr_ref(worklist, i);
        assert(language_is_module(mod));
        foreach_mtable_in_module(mod, precompile_enq_all_specializations_, m);
    }
    n = language_array_nrows(extext_methods);
    for (i = 0; i < n; i++) {
        language_method_t *method = (language_method_t*)language_array_ptr_ref(extext_methods, i);
        assert(language_is_method(method));
        language_value_t *specializations = language_atomic_load_relaxed(&method->specializations);
        if (!language_is_svec(specializations)) {
            precompile_enq_specialization_((language_method_instance_t*)specializations, m);
        }
        else {
            size_t j, l = language_svec_len(specializations);
            for (j = 0; j < l; j++) {
                language_value_t *mi = language_svecref(specializations, j);
                if (mi != language_nothing)
                    precompile_enq_specialization_((language_method_instance_t*)mi, m);
            }
        }
    }
    n = language_array_nrows(new_ext_cis);
    for (i = 0; i < n; i++) {
        language_code_instance_t *ci = (language_code_instance_t*)language_array_ptr_ref(new_ext_cis, i);
        precompile_enq_specialization_(ci->def, m);
    }
    void *native_code = language_precompile_(m, 1);
    LANGUAGE_GC_POP();
    return native_code;
}
