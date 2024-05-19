// inverse of backedges graph (caller=>callees hash)
language_genericmemory_t *edges_map LANGUAGE_GLOBALLY_ROOTED = NULL; // rooted for the duration of our uses of this

static void write_float64(ios_t *s, double x) LANGUAGE_NOTSAFEPOINT
{
    write_uint64(s, *((uint64_t*)&x));
}

// Decide if `t` must be new, because it points to something new.
// If it is new, the object (in particular, the super field) might not be entirely
// valid for the cache, so we want to finish transforming it before attempting
// to look in the cache for it
int must_be_new_dt(language_value_t *t, htable_t *news, char *image_base, size_t sizeof_sysimg)
{
    //if (language_object_in_image(t))
    //    return 0; // fast-path for rejection
    assert(ptrhash_get(news, (void*)t) != (void*)t);
    if (ptrhash_has(news, (void*)t) || ptrhash_has(news, (void*)language_typeof(t)))
        return 1;
    if (!(image_base < (char*)t && (char*)t <= image_base + sizeof_sysimg))
        return 0; // fast-path for rejection
    if (language_is_uniontype(t)) {
        language_uniontype_t *u = (language_uniontype_t*)t;
        return must_be_new_dt(u->a, news, image_base, sizeof_sysimg) ||
               must_be_new_dt(u->b, news, image_base, sizeof_sysimg);
    }
    else if (language_is_unionall(t)) {
        language_unionall_t *ua = (language_unionall_t*)t;
        return must_be_new_dt((language_value_t*)ua->var, news, image_base, sizeof_sysimg) ||
               must_be_new_dt(ua->body, news, image_base, sizeof_sysimg);
    }
    else if (language_is_typevar(t)) {
        language_tvar_t *tv = (language_tvar_t*)t;
        return must_be_new_dt(tv->lb, news, image_base, sizeof_sysimg) ||
               must_be_new_dt(tv->ub, news, image_base, sizeof_sysimg);
    }
    else if (language_is_vararg(t)) {
        language_vararg_t *tv = (language_vararg_t*)t;
        if (tv->T && must_be_new_dt(tv->T, news, image_base, sizeof_sysimg))
            return 1;
        if (tv->N && must_be_new_dt(tv->N, news, image_base, sizeof_sysimg))
            return 1;
    }
    else if (language_is_datatype(t)) {
        language_datatype_t *dt = (language_datatype_t*)t;
        assert(language_object_in_image((language_value_t*)dt->name) && "type_in_worklist mistake?");
        language_datatype_t *super = dt->super;
        // fast-path: check if super is in news, since then we must be new also
        // (it is also possible that super is indeterminate or NULL right now,
        // waiting for `t` to be resolved, then will be determined later as
        // soon as possible afterwards).
        while (super != NULL && super != language_any_type) {
            if (ptrhash_has(news, (void*)super))
                return 1;
            if (!(image_base < (char*)super && (char*)super <= image_base + sizeof_sysimg))
               break; // the rest must all be non-new
            // otherwise super might be something that was not cached even though a later supertype might be
            // for example while handling `Type{Mask{4, U} where U}`, if we have `Mask{4, U} <: AbstractSIMDVector{4}`
            super = super->super;
        }
        language_svec_t *tt = dt->parameters;
        size_t i, l = language_svec_len(tt);
        for (i = 0; i < l; i++)
            if (must_be_new_dt(language_tparam(dt, i), news, image_base, sizeof_sysimg))
                return 1;
    }
    else {
        return must_be_new_dt(language_typeof(t), news, image_base, sizeof_sysimg);
    }
    return 0;
}

static uint64_t language_worklist_key(language_array_t *worklist) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_array(worklist));
    size_t len = language_array_nrows(worklist);
    if (len > 0) {
        language_module_t *topmod = (language_module_t*)language_array_ptr_ref(worklist, len-1);
        assert(language_is_module(topmod));
        return topmod->build_id.lo;
    }
    return 0;
}

static language_array_t *newly_inferred LANGUAGE_GLOBALLY_ROOTED /*FIXME*/;
// Mutex for newly_inferred
language_mutex_t newly_inferred_mutex;
extern language_mutex_t world_counter_lock;

// Register array of newly-inferred MethodInstances
// This gets called as the first step of Base.include_package_for_output
LANGUAGE_DLLEXPORT void language_set_newly_inferred(language_value_t* _newly_inferred)
{
    assert(_newly_inferred == NULL || language_is_array(_newly_inferred));
    newly_inferred = (language_array_t*) _newly_inferred;
}

LANGUAGE_DLLEXPORT void language_push_newly_inferred(language_value_t* ci)
{
    LANGUAGE_LOCK(&newly_inferred_mutex);
    size_t end = language_array_nrows(newly_inferred);
    language_array_grow_end(newly_inferred, 1);
    language_array_ptr_set(newly_inferred, end, ci);
    LANGUAGE_UNLOCK(&newly_inferred_mutex);
}


// compute whether a type references something internal to worklist
// and thus could not have existed before deserialize
// and thus does not need delayed unique-ing
static int type_in_worklist(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    if (language_object_in_image(v))
        return 0; // fast-path for rejection
    if (language_is_uniontype(v)) {
        language_uniontype_t *u = (language_uniontype_t*)v;
        return type_in_worklist(u->a) ||
               type_in_worklist(u->b);
    }
    else if (language_is_unionall(v)) {
        language_unionall_t *ua = (language_unionall_t*)v;
        return type_in_worklist((language_value_t*)ua->var) ||
               type_in_worklist(ua->body);
    }
    else if (language_is_typevar(v)) {
        language_tvar_t *tv = (language_tvar_t*)v;
        return type_in_worklist(tv->lb) ||
               type_in_worklist(tv->ub);
    }
    else if (language_is_vararg(v)) {
        language_vararg_t *tv = (language_vararg_t*)v;
        if (tv->T && type_in_worklist(tv->T))
            return 1;
        if (tv->N && type_in_worklist(tv->N))
            return 1;
    }
    else if (language_is_datatype(v)) {
        language_datatype_t *dt = (language_datatype_t*)v;
        if (!language_object_in_image((language_value_t*)dt->name))
            return 1;
        language_svec_t *tt = dt->parameters;
        size_t i, l = language_svec_len(tt);
        for (i = 0; i < l; i++)
            if (type_in_worklist(language_tparam(dt, i)))
                return 1;
    }
    else {
        return type_in_worklist(language_typeof(v));
    }
    return 0;
}

// When we infer external method instances, ensure they link back to the
// package. Otherwise they might be, e.g., for external macros.
// Implements Tarjan's SCC (strongly connected components) algorithm, simplified to remove the count variable
static int has_backedge_to_worklist(language_method_instance_t *mi, htable_t *visited, arraylist_t *stack)
{
    language_module_t *mod = mi->def.module;
    if (language_is_method(mod))
        mod = ((language_method_t*)mod)->module;
    assert(language_is_module(mod));
    if (language_atomic_load_relaxed(&mi->precompiled) || !language_object_in_image((language_value_t*)mod) || type_in_worklist(mi->specTypes)) {
        return 1;
    }
    if (!mi->backedges) {
        return 0;
    }
    void **bp = ptrhash_bp(visited, mi);
    // HT_NOTFOUND: not yet analyzed
    // HT_NOTFOUND + 1: no link back
    // HT_NOTFOUND + 2: does link back
    // HT_NOTFOUND + 3: does link back, and included in new_ext_cis already
    // HT_NOTFOUND + 4 + depth: in-progress
    int found = (char*)*bp - (char*)HT_NOTFOUND;
    if (found)
        return found - 1;
    arraylist_push(stack, (void*)mi);
    int depth = stack->len;
    *bp = (void*)((char*)HT_NOTFOUND + 4 + depth); // preliminarily mark as in-progress
    size_t i = 0, n = language_array_nrows(mi->backedges);
    int cycle = depth;
    while (i < n) {
        language_method_instance_t *be;
        i = get_next_edge(mi->backedges, i, NULL, &be);
        int child_found = has_backedge_to_worklist(be, visited, stack);
        if (child_found == 1 || child_found == 2) {
            // found what we were looking for, so terminate early
            found = 1;
            break;
        }
        else if (child_found >= 3 && child_found - 3 < cycle) {
            // record the cycle will resolve at depth "cycle"
            cycle = child_found - 3;
            assert(cycle);
        }
    }
    if (!found && cycle != depth)
        return cycle + 3;
    // If we are the top of the current cycle, now mark all other parts of
    // our cycle with what we found.
    // Or if we found a backedge, also mark all of the other parts of the
    // cycle as also having an backedge.
    while (stack->len >= depth) {
        void *mi = arraylist_pop(stack);
        bp = ptrhash_bp(visited, mi);
        assert((char*)*bp - (char*)HT_NOTFOUND == 5 + stack->len);
        *bp = (void*)((char*)HT_NOTFOUND + 1 + found);
    }
    return found;
}

// Given the list of CodeInstances that were inferred during the build, select
// those that are (1) external, (2) still valid, (3) are inferred to be called
// from the worklist or explicitly added by a `precompile` statement, and
// (4) are the most recently computed result for that method.
// These will be preserved in the image.
static language_array_t *queue_external_cis(language_array_t *list)
{
    if (list == NULL)
        return NULL;
    size_t i;
    htable_t visited;
    arraylist_t stack;
    assert(language_is_array(list));
    size_t n0 = language_array_nrows(list);
    htable_new(&visited, n0);
    arraylist_new(&stack, 0);
    language_array_t *new_ext_cis = language_alloc_vec_any(0);
    LANGUAGE_GC_PUSH1(&new_ext_cis);
    for (i = n0; i-- > 0; ) {
        language_code_instance_t *ci = (language_code_instance_t*)language_array_ptr_ref(list, i);
        assert(language_is_code_instance(ci));
        if (!ci->relocatability)
            continue;
        language_method_instance_t *mi = ci->def;
        language_method_t *m = mi->def.method;
        if (language_atomic_load_relaxed(&ci->inferred) && language_is_method(m) && language_object_in_image((language_value_t*)m->module)) {
            int found = has_backedge_to_worklist(mi, &visited, &stack);
            assert(found == 0 || found == 1 || found == 2);
            assert(stack.len == 0);
            if (found == 1 && language_atomic_load_relaxed(&ci->max_world) == ~(size_t)0) {
                language_array_ptr_1d_push(new_ext_cis, (language_value_t*)ci);
            }
        }
    }
    htable_free(&visited);
    arraylist_free(&stack);
    LANGUAGE_GC_POP();
    // reverse new_ext_cis
    n0 = language_array_nrows(new_ext_cis);
    language_value_t **news = language_array_data(new_ext_cis, language_value_t*);
    for (i = 0; i < n0; i++) {
        language_value_t *temp = news[i];
        news[i] = news[n0 - i - 1];
        news[n0 - i - 1] = temp;
    }
    return new_ext_cis;
}

// New roots for external methods
static void language_collect_new_roots(language_array_t *roots, language_array_t *new_ext_cis, uint64_t key)
{
    htable_t mset;
    htable_new(&mset, 0);
    size_t l = new_ext_cis ? language_array_nrows(new_ext_cis) : 0;
    for (size_t i = 0; i < l; i++) {
        language_code_instance_t *ci = (language_code_instance_t*)language_array_ptr_ref(new_ext_cis, i);
        assert(language_is_code_instance(ci));
        language_method_t *m = ci->def->def.method;
        assert(language_is_method(m));
        ptrhash_put(&mset, (void*)m, (void*)m);
    }
    int nwithkey;
    void *const *table = mset.table;
    language_array_t *newroots = NULL;
    LANGUAGE_GC_PUSH1(&newroots);
    for (size_t i = 0; i < mset.size; i += 2) {
        if (table[i+1] != HT_NOTFOUND) {
            language_method_t *m = (language_method_t*)table[i];
            assert(language_is_method(m));
            nwithkey = nroots_with_key(m, key);
            if (nwithkey) {
                language_array_ptr_1d_push(roots, (language_value_t*)m);
                newroots = language_alloc_vec_any(nwithkey);
                language_array_ptr_1d_push(roots, (language_value_t*)newroots);
                rle_iter_state rootiter = rle_iter_init(0);
                uint64_t *rletable = NULL;
                size_t nblocks2 = 0, nroots = language_array_nrows(m->roots), k = 0;
                if (m->root_blocks) {
                    rletable = language_array_data(m->root_blocks, uint64_t);
                    nblocks2 = language_array_nrows(m->root_blocks);
                }
                while (rle_iter_increment(&rootiter, nroots, rletable, nblocks2))
                    if (rootiter.key == key)
                        language_array_ptr_set(newroots, k++, language_array_ptr_ref(m->roots, rootiter.i));
                assert(k == nwithkey);
            }
        }
    }
    LANGUAGE_GC_POP();
    htable_free(&mset);
}

// Create the forward-edge map (caller => callees)
// the intent of these functions is to invert the backedges tree
// for anything that points to a method not part of the worklist
//
// from MethodTables
static void language_collect_missing_backedges(language_methtable_t *mt)
{
    language_array_t *backedges = mt->backedges;
    if (backedges) {
        size_t i, l = language_array_nrows(backedges);
        for (i = 1; i < l; i += 2) {
            language_method_instance_t *caller = (language_method_instance_t*)language_array_ptr_ref(backedges, i);
            language_value_t *missing_callee = language_array_ptr_ref(backedges, i - 1);  // signature of abstract callee
            language_array_t *edges = (language_array_t*)language_eqtable_get(edges_map, (language_value_t*)caller, NULL);
            if (edges == NULL) {
                edges = language_alloc_vec_any(0);
                LANGUAGE_GC_PUSH1(&edges);
                edges_map = language_eqtable_put(edges_map, (language_value_t*)caller, (language_value_t*)edges, NULL);
                LANGUAGE_GC_POP();
            }
            language_array_ptr_1d_push(edges, NULL);
            language_array_ptr_1d_push(edges, missing_callee);
        }
    }
}


// from MethodInstances
static void collect_backedges(language_method_instance_t *callee, int internal)
{
    language_array_t *backedges = callee->backedges;
    if (backedges) {
        size_t i = 0, l = language_array_nrows(backedges);
        while (i < l) {
            language_value_t *invokeTypes;
            language_method_instance_t *caller;
            i = get_next_edge(backedges, i, &invokeTypes, &caller);
            language_array_t *edges = (language_array_t*)language_eqtable_get(edges_map, (language_value_t*)caller, NULL);
            if (edges == NULL) {
                edges = language_alloc_vec_any(0);
                LANGUAGE_GC_PUSH1(&edges);
                edges_map = language_eqtable_put(edges_map, (language_value_t*)caller, (language_value_t*)edges, NULL);
                LANGUAGE_GC_POP();
            }
            language_array_ptr_1d_push(edges, invokeTypes);
            language_array_ptr_1d_push(edges, (language_value_t*)callee);
        }
    }
}


// For functions owned by modules not on the worklist, call this on each method.
// - if the method is owned by a worklist module, add it to the list of things to be
//   fully serialized
// - Collect all backedges (may be needed later when we invert this list).
static int language_collect_methcache_from_mod(language_typemap_entry_t *ml, void *closure)
{
    language_array_t *s = (language_array_t*)closure;
    language_method_t *m = ml->func.method;
    if (s && !language_object_in_image((language_value_t*)m->module)) {
        language_array_ptr_1d_push(s, (language_value_t*)m);
    }
    if (edges_map == NULL)
        return 1;
    language_value_t *specializations = language_atomic_load_relaxed(&m->specializations);
    if (!language_is_svec(specializations)) {
        language_method_instance_t *callee = (language_method_instance_t*)specializations;
        collect_backedges(callee, !s);
    }
    else {
        size_t i, l = language_svec_len(specializations);
        for (i = 0; i < l; i++) {
            language_method_instance_t *callee = (language_method_instance_t*)language_svecref(specializations, i);
            if ((language_value_t*)callee != language_nothing)
                collect_backedges(callee, !s);
        }
    }
    return 1;
}

static int language_collect_methtable_from_mod(language_methtable_t *mt, void *env)
{
    if (!language_object_in_image((language_value_t*)mt))
        env = NULL; // do not collect any methods from here
    language_typemap_visitor(language_atomic_load_relaxed(&mt->defs), language_collect_methcache_from_mod, env);
    if (env && edges_map)
        language_collect_missing_backedges(mt);
    return 1;
}

// Collect methods of external functions defined by modules in the worklist
// "extext" = "extending external"
// Also collect relevant backedges
static void language_collect_extext_methods_from_mod(language_array_t *s, language_module_t *m)
{
    foreach_mtable_in_module(m, language_collect_methtable_from_mod, s);
}

static void language_record_edges(language_method_instance_t *caller, arraylist_t *wq, language_array_t *edges)
{
    language_array_t *callees = NULL;
    LANGUAGE_GC_PUSH2(&caller, &callees);
    callees = (language_array_t*)language_eqtable_pop(edges_map, (language_value_t*)caller, NULL, NULL);
    if (callees != NULL) {
        language_array_ptr_1d_push(edges, (language_value_t*)caller);
        language_array_ptr_1d_push(edges, (language_value_t*)callees);
        size_t i, l = language_array_nrows(callees);
        for (i = 1; i < l; i += 2) {
            language_method_instance_t *c = (language_method_instance_t*)language_array_ptr_ref(callees, i);
            if (c && language_is_method_instance(c)) {
                arraylist_push(wq, c);
            }
        }
    }
    LANGUAGE_GC_POP();
}


// Extract `edges` and `ext_targets` from `edges_map`
// `edges` = [caller1, targets_indexes1, ...], the list of methods and their edges
// `ext_targets` is [invokesig1, callee1, matches1, ...], the edges for each target
static void language_collect_edges(language_array_t *edges, language_array_t *ext_targets, language_array_t *external_cis, size_t world)
{
    htable_t external_mis;
    htable_new(&external_mis, 0);
    if (external_cis) {
        for (size_t i = 0; i < language_array_nrows(external_cis); i++) {
            language_code_instance_t *ci = (language_code_instance_t*)language_array_ptr_ref(external_cis, i);
            language_method_instance_t *mi = ci->def;
            ptrhash_put(&external_mis, (void*)mi, (void*)mi);
        }
    }
    arraylist_t wq;
    arraylist_new(&wq, 0);
    void **table = (void**) edges_map->ptr;    // edges_map is caller => callees
    size_t table_size = edges_map->length;
    for (size_t i = 0; i < table_size; i += 2) {
        assert(table == edges_map->ptr && table_size == edges_map->length &&
               "edges_map changed during iteration");
        language_method_instance_t *caller = (language_method_instance_t*)table[i];
        language_array_t *callees = (language_array_t*)table[i + 1];
        if (callees == NULL)
            continue;
        assert(language_is_method_instance(caller) && language_is_method(caller->def.method));
        if (!language_object_in_image((language_value_t*)caller->def.method->module) ||
            ptrhash_get(&external_mis, caller) != HT_NOTFOUND) {
            language_record_edges(caller, &wq, edges);
        }
    }
    htable_free(&external_mis);
    while (wq.len) {
        language_method_instance_t *caller = (language_method_instance_t*)arraylist_pop(&wq);
        language_record_edges(caller, &wq, edges);
    }
    arraylist_free(&wq);
    edges_map = NULL;
    htable_t edges_map2;
    htable_new(&edges_map2, 0);
    htable_t edges_ids;
    size_t l = edges ? language_array_nrows(edges) : 0;
    htable_new(&edges_ids, l);
    for (size_t i = 0; i < l / 2; i++) {
        language_method_instance_t *caller = (language_method_instance_t*)language_array_ptr_ref(edges, i * 2);
        void *target = (void*)((char*)HT_NOTFOUND + i + 1);
        ptrhash_put(&edges_ids, (void*)caller, target);
    }
    // process target list to turn it into a memoized validity table
    // and compute the old methods list, ready for serialization
    language_value_t *matches = NULL;
    language_array_t *callee_ids = NULL;
    language_value_t *sig = NULL;
    LANGUAGE_GC_PUSH3(&matches, &callee_ids, &sig);
    for (size_t i = 0; i < l; i += 2) {
        language_array_t *callees = (language_array_t*)language_array_ptr_ref(edges, i + 1);
        size_t l = language_array_nrows(callees);
        callee_ids = language_alloc_array_1d(language_array_int32_type, l + 1);
        int32_t *idxs = language_array_data(callee_ids, int32_t);
        idxs[0] = 0;
        size_t nt = 0;
        for (size_t j = 0; j < l; j += 2) {
            language_value_t *invokeTypes = language_array_ptr_ref(callees, j);
            language_value_t *callee = language_array_ptr_ref(callees, j + 1);
            assert(callee && "unsupported edge");

            if (language_is_method_instance(callee)) {
                language_methtable_t *mt = language_method_get_table(((language_method_instance_t*)callee)->def.method);
                if (!language_object_in_image((language_value_t*)mt))
                    continue;
            }

            // (nullptr, c) => call
            // (invokeTypes, c) => invoke
            // (nullptr, invokeTypes) => missing call
            // (invokeTypes, nullptr) => missing invoke (unused--inferred as Any)
            void *target = ptrhash_get(&edges_map2, invokeTypes ? (void*)invokeTypes : (void*)callee);
            if (target == HT_NOTFOUND) {
                size_t min_valid = 0;
                size_t max_valid = ~(size_t)0;
                if (invokeTypes) {
                    assert(language_is_method_instance(callee));
                    language_method_t *m = ((language_method_instance_t*)callee)->def.method;
                    matches = (language_value_t*)m; // valid because there is no method replacement permitted
#ifndef NDEBUG
                    language_methtable_t *mt = language_method_get_table(m);
                    if ((language_value_t*)mt != language_nothing) {
                        language_value_t *matches = language_gf_invoke_lookup_worlds(invokeTypes, (language_value_t*)mt, world, &min_valid, &max_valid);
                        if (matches != language_nothing) {
                            assert(m == ((language_method_match_t*)matches)->method);
                        }
                    }
#endif
                }
                else {
                    if (language_is_method_instance(callee)) {
                        language_method_instance_t *mi = (language_method_instance_t*)callee;
                        sig = language_type_intersection(mi->def.method->sig, (language_value_t*)mi->specTypes);
                    }
                    else {
                        sig = callee;
                    }
                    int ambig = 0;
                    matches = language_matching_methods((language_tupletype_t*)sig, language_nothing,
                            INT32_MAX, 0, world, &min_valid, &max_valid, &ambig);
                    sig = NULL;
                    if (matches == language_nothing) {
                        callee_ids = NULL; // invalid
                        break;
                    }
                    size_t k;
                    for (k = 0; k < language_array_nrows(matches); k++) {
                        language_method_match_t *match = (language_method_match_t *)language_array_ptr_ref(matches, k);
                        language_array_ptr_set(matches, k, match->method);
                    }
                }
                language_array_ptr_1d_push(ext_targets, invokeTypes);
                language_array_ptr_1d_push(ext_targets, callee);
                language_array_ptr_1d_push(ext_targets, matches);
                target = (void*)((char*)HT_NOTFOUND + language_array_nrows(ext_targets) / 3);
                ptrhash_put(&edges_map2, (void*)callee, target);
            }
            idxs[++nt] = (char*)target - (char*)HT_NOTFOUND - 1;
        }
        language_array_ptr_set(edges, i + 1, callee_ids); // swap callees for ids
        if (!callee_ids)
            continue;
        idxs[0] = nt;
        // record place of every method in edges
        // add method edges to the callee_ids list
        for (size_t j = 0; j < l; j += 2) {
            language_value_t *callee = language_array_ptr_ref(callees, j + 1);
            if (callee && language_is_method_instance(callee)) {
                void *target = ptrhash_get(&edges_ids, (void*)callee);
                if (target != HT_NOTFOUND) {
                    idxs[++nt] = (char*)target - (char*)HT_NOTFOUND - 1;
                }
            }
        }
        language_array_del_end(callee_ids, l - nt);
    }
    LANGUAGE_GC_POP();
    htable_free(&edges_map2);
}

// Headers

// serialize information about all loaded modules
static void write_mod_list(ios_t *s, language_array_t *a)
{
    size_t i;
    size_t len = language_array_nrows(a);
    for (i = 0; i < len; i++) {
        language_module_t *m = (language_module_t*)language_array_ptr_ref(a, i);
        assert(language_is_module(m));
        if (language_object_in_image((language_value_t*)m)) {
            const char *modname = language_symbol_name(m->name);
            size_t l = strlen(modname);
            write_int32(s, l);
            ios_write(s, modname, l);
            write_uint64(s, m->uuid.hi);
            write_uint64(s, m->uuid.lo);
            write_uint64(s, m->build_id.hi);
            write_uint64(s, m->build_id.lo);
        }
    }
    write_int32(s, 0);
}

// OPT_LEVEL should always be the upper bits
#define OPT_LEVEL 6

LANGUAGE_DLLEXPORT uint8_t language_cache_flags(void)
{
    // OOICCDDP
    uint8_t flags = 0;
    flags |= (language_options.use_pkgimages & 1); // 0-bit
    flags |= (language_options.debug_level & 3) << 1; // 1-2 bit
    flags |= (language_options.check_bounds & 3) << 3; // 3-4 bit
    flags |= (language_options.can_inline & 1) << 5; // 5-bit
    flags |= (language_options.opt_level & 3) << OPT_LEVEL; // 6-7 bit
    return flags;
}


LANGUAGE_DLLEXPORT uint8_t language_match_cache_flags(uint8_t requested_flags, uint8_t actual_flags)
{
    uint8_t supports_pkgimage = (requested_flags & 1);
    uint8_t is_pkgimage = (actual_flags & 1);

    // For .ji packages ignore other flags
    if (!supports_pkgimage && !is_pkgimage) {
        return 1;
    }

    // If package images are optional, ignore that bit (it will be unset in requested_flags)
    if (language_options.use_pkgimages == LANGUAGE_OPTIONS_USE_PKGIMAGES_EXISTING) {
        actual_flags &= ~1;
    }

    // 2. Check all flags, except opt level must be exact
    uint8_t mask = (1 << OPT_LEVEL)-1;
    if ((actual_flags & mask) != (requested_flags & mask))
        return 0;
    // 3. allow for higher optimization flags in cache
    actual_flags >>= OPT_LEVEL;
    requested_flags >>= OPT_LEVEL;
    return actual_flags >= requested_flags;
}

LANGUAGE_DLLEXPORT uint8_t language_match_cache_flags_current(uint8_t flags)
{
    return language_match_cache_flags(language_cache_flags(), flags);
}

// return char* from String field in Base.GIT_VERSION_INFO
static const char *git_info_string(const char *fld)
{
    static language_value_t *GIT_VERSION_INFO = NULL;
    if (!GIT_VERSION_INFO)
        GIT_VERSION_INFO = language_get_global(language_base_module, language_symbol("GIT_VERSION_INFO"));
    language_value_t *f = language_get_field(GIT_VERSION_INFO, fld);
    assert(language_is_string(f));
    return language_string_data(f);
}

static const char *language_git_branch(void)
{
    static const char *branch = NULL;
    if (!branch) branch = git_info_string("branch");
    return branch;
}

static const char *language_git_commit(void)
{
    static const char *commit = NULL;
    if (!commit) commit = git_info_string("commit");
    return commit;
}


// "magic" string and version header of .ji file
static const int JI_FORMAT_VERSION = 12;
static const char JI_MAGIC[] = "\373jli\r\n\032\n"; // based on PNG signature
static const uint16_t BOM = 0xFEFF; // byte-order marker
static int64_t write_header(ios_t *s, uint8_t pkgimage)
{
    ios_write(s, JI_MAGIC, strlen(JI_MAGIC));
    write_uint16(s, JI_FORMAT_VERSION);
    ios_write(s, (char *) &BOM, 2);
    write_uint8(s, sizeof(void*));
    ios_write(s, LANGUAGE_BUILD_UNAME, strlen(LANGUAGE_BUILD_UNAME)+1);
    ios_write(s, LANGUAGE_BUILD_ARCH, strlen(LANGUAGE_BUILD_ARCH)+1);
    ios_write(s, JULIA_VERSION_STRING, strlen(JULIA_VERSION_STRING)+1);
    const char *branch = language_git_branch(), *commit = language_git_commit();
    ios_write(s, branch, strlen(branch)+1);
    ios_write(s, commit, strlen(commit)+1);
    write_uint8(s, pkgimage);
    int64_t checksumpos = ios_pos(s);
    write_uint64(s, 0); // eventually will hold checksum for the content portion of this (build_id.hi)
    write_uint64(s, 0); // eventually will hold dataendpos
    write_uint64(s, 0); // eventually will hold datastartpos
    return checksumpos;
}

// serialize information about the result of deserializing this file
static void write_worklist_for_header(ios_t *s, language_array_t *worklist)
{
    int i, l = language_array_nrows(worklist);
    for (i = 0; i < l; i++) {
        language_module_t *workmod = (language_module_t*)language_array_ptr_ref(worklist, i);
        if (workmod->parent == language_main_module || workmod->parent == workmod) {
            size_t l = strlen(language_symbol_name(workmod->name));
            write_int32(s, l);
            ios_write(s, language_symbol_name(workmod->name), l);
            write_uint64(s, workmod->uuid.hi);
            write_uint64(s, workmod->uuid.lo);
            write_uint64(s, workmod->build_id.lo);
        }
    }
    write_int32(s, 0);
}

static void write_module_path(ios_t *s, language_module_t *depmod) LANGUAGE_NOTSAFEPOINT
{
    if (depmod->parent == language_main_module || depmod->parent == depmod)
        return;
    const char *mname = language_symbol_name(depmod->name);
    size_t slen = strlen(mname);
    write_module_path(s, depmod->parent);
    write_int32(s, slen);
    ios_write(s, mname, slen);
}

// Cache file header
// Serialize the global Base._require_dependencies array of pathnames that
// are include dependencies. Also write Preferences and return
// the location of the srctext "pointer" in the header index.
static int64_t write_dependency_list(ios_t *s, language_array_t* worklist, language_array_t **udepsp)
{
    int64_t initial_pos = 0;
    int64_t pos = 0;
    static language_array_t *deps = NULL;
    if (!deps)
        deps = (language_array_t*)language_get_global(language_base_module, language_symbol("_require_dependencies"));

    // unique(deps) to eliminate duplicates while preserving order:
    // we preserve order so that the topmost included .jl file comes first
    static language_value_t *unique_func = NULL;
    if (!unique_func)
        unique_func = language_get_global(language_base_module, language_symbol("unique"));
    language_value_t *uniqargs[2] = {unique_func, (language_value_t*)deps};
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    ct->world_age = language_atomic_load_acquire(&language_world_counter);
    language_array_t *udeps = (*udepsp = deps && unique_func ? (language_array_t*)language_apply(uniqargs, 2) : NULL);
    ct->world_age = last_age;

    static language_value_t *replace_depot_func = NULL;
    if (!replace_depot_func)
        replace_depot_func = language_get_global(language_base_module, language_symbol("replace_depot_path"));

    // write a placeholder for total size so that we can quickly seek past all of the
    // dependencies if we don't need them
    initial_pos = ios_pos(s);
    write_uint64(s, 0);
    size_t i, l = udeps ? language_array_nrows(udeps) : 0;
    for (i = 0; i < l; i++) {
        language_value_t *deptuple = language_array_ptr_ref(udeps, i);
        language_value_t *deppath = language_fieldref(deptuple, 1);

        if (replace_depot_func) {
            language_value_t **replace_depot_args;
            LANGUAGE_GC_PUSHARGS(replace_depot_args, 2);
            replace_depot_args[0] = replace_depot_func;
            replace_depot_args[1] = deppath;
            ct = language_current_task;
            size_t last_age = ct->world_age;
            ct->world_age = language_atomic_load_acquire(&language_world_counter);
            deppath = (language_value_t*)language_apply(replace_depot_args, 2);
            ct->world_age = last_age;
            LANGUAGE_GC_POP();
        }

        size_t slen = language_string_len(deppath);
        write_int32(s, slen);
        ios_write(s, language_string_data(deppath), slen);
        write_uint64(s, language_unbox_uint64(language_fieldref(deptuple, 2)));    // fsize
        write_uint32(s, language_unbox_uint32(language_fieldref(deptuple, 3)));    // hash
        write_float64(s, language_unbox_float64(language_fieldref(deptuple, 4)));  // mtime
        language_module_t *depmod = (language_module_t*)language_fieldref(deptuple, 0);  // evaluating module
        language_module_t *depmod_top = depmod;
        while (depmod_top->parent != language_main_module && depmod_top->parent != depmod_top)
            depmod_top = depmod_top->parent;
        unsigned provides = 0;
        size_t j, lj = language_array_nrows(worklist);
        for (j = 0; j < lj; j++) {
            language_module_t *workmod = (language_module_t*)language_array_ptr_ref(worklist, j);
            if (workmod->parent == language_main_module || workmod->parent == workmod) {
                ++provides;
                if (workmod == depmod_top) {
                    write_int32(s, provides);
                    write_module_path(s, depmod);
                    break;
                }
            }
        }
        write_int32(s, 0);
    }
    write_int32(s, 0); // terminator, for ease of reading

    // Calculate Preferences hash for current package.
    language_value_t *prefs_hash = NULL;
    language_value_t *prefs_list = NULL;
    LANGUAGE_GC_PUSH1(&prefs_list);
    if (language_base_module) {
        // Toplevel module is the module we're currently compiling, use it to get our preferences hash
        language_value_t * toplevel = (language_value_t*)language_get_global(language_base_module, language_symbol("__toplevel__"));
        language_value_t * prefs_hash_func = language_get_global(language_base_module, language_symbol("get_preferences_hash"));
        language_value_t * get_compiletime_prefs_func = language_get_global(language_base_module, language_symbol("get_compiletime_preferences"));

        if (toplevel && prefs_hash_func && get_compiletime_prefs_func) {
            // Temporary invoke in newest world age
            size_t last_age = ct->world_age;
            ct->world_age = language_atomic_load_acquire(&language_world_counter);

            // call get_compiletime_prefs(__toplevel__)
            language_value_t *args[3] = {get_compiletime_prefs_func, (language_value_t*)toplevel, NULL};
            prefs_list = (language_value_t*)language_apply(args, 2);

            // Call get_preferences_hash(__toplevel__, prefs_list)
            args[0] = prefs_hash_func;
            args[2] = prefs_list;
            prefs_hash = (language_value_t*)language_apply(args, 3);

            // Reset world age to normal
            ct->world_age = last_age;
        }
    }

    // If we successfully got the preferences, write it out, otherwise write `0` for this `.ji` file.
    if (prefs_hash != NULL && prefs_list != NULL) {
        size_t i, l = language_array_nrows(prefs_list);
        for (i = 0; i < l; i++) {
            language_value_t *pref_name = language_array_ptr_ref(prefs_list, i);
            size_t slen = language_string_len(pref_name);
            write_int32(s, slen);
            ios_write(s, language_string_data(pref_name), slen);
        }
        write_int32(s, 0); // terminator
        write_uint64(s, language_unbox_uint64(prefs_hash));
    }
    else {
        // This is an error path, but let's at least generate a valid `.ji` file.
        // We declare an empty list of preference names, followed by a zero-hash.
        // The zero-hash is not what would be generated for an empty set of preferences,
        // and so this `.ji` file will be invalidated by a future non-erroring pass
        // through this function.
        write_int32(s, 0);
        write_uint64(s, 0);
    }
    LANGUAGE_GC_POP(); // for prefs_list

    // write a dummy file position to indicate the beginning of the source-text
    pos = ios_pos(s);
    ios_seek(s, initial_pos);
    write_uint64(s, pos - initial_pos);
    ios_seek(s, pos);
    write_uint64(s, 0);
    return pos;
}


// Deserialization

// Add methods to external (non-worklist-owned) functions
// mutating external to point at the new methodtable entry instead of the new method
static void language_add_methods(language_array_t *external)
{
    size_t i, l = language_array_nrows(external);
    for (i = 0; i < l; i++) {
        language_method_t *meth = (language_method_t*)language_array_ptr_ref(external, i);
        assert(language_is_method(meth));
        assert(!meth->is_for_opaque_closure);
        language_methtable_t *mt = language_method_get_table(meth);
        assert((language_value_t*)mt != language_nothing);
        language_typemap_entry_t *entry = language_method_table_add(mt, meth, NULL);
        language_array_ptr_set(external, i, entry);
    }
}

static void language_activate_methods(language_array_t *external, language_array_t *internal, size_t world)
{
    size_t i, l = language_array_nrows(internal);
    for (i = 0; i < l; i++) {
        language_value_t *obj = language_array_ptr_ref(internal, i);
        if (language_typetagis(obj, language_typemap_entry_type)) {
            language_typemap_entry_t *entry = (language_typemap_entry_t*)obj;
            assert(language_atomic_load_relaxed(&entry->min_world) == ~(size_t)0);
            assert(language_atomic_load_relaxed(&entry->max_world) == WORLD_AGE_REVALIDATION_SENTINEL);
            language_atomic_store_release(&entry->min_world, world);
            language_atomic_store_release(&entry->max_world, ~(size_t)0);
        }
        else if (language_is_method(obj)) {
            language_method_t *m = (language_method_t*)obj;
            assert(language_atomic_load_relaxed(&m->primary_world) == ~(size_t)0);
            assert(language_atomic_load_relaxed(&m->deleted_world) == WORLD_AGE_REVALIDATION_SENTINEL);
            language_atomic_store_release(&m->primary_world, world);
            language_atomic_store_release(&m->deleted_world, ~(size_t)0);
        }
        else if (language_is_code_instance(obj)) {
            language_code_instance_t *ci = (language_code_instance_t*)obj;
            assert(language_atomic_load_relaxed(&ci->min_world) == ~(size_t)0);
            assert(language_atomic_load_relaxed(&ci->max_world) == WORLD_AGE_REVALIDATION_SENTINEL);
            language_atomic_store_relaxed(&ci->min_world, world);
            // n.b. ci->max_world is not updated until edges are verified
        }
        else {
            abort();
        }
    }
    l = language_array_nrows(external);
    for (i = 0; i < l; i++) {
        language_typemap_entry_t *entry = (language_typemap_entry_t*)language_array_ptr_ref(external, i);
        language_methtable_t *mt = language_method_get_table(entry->func.method);
        assert((language_value_t*)mt != language_nothing);
        language_method_table_activate(mt, entry);
    }
}

static void language_copy_roots(language_array_t *method_roots_list, uint64_t key)
{
    size_t i, l = language_array_nrows(method_roots_list);
    for (i = 0; i < l; i+=2) {
        language_method_t *m = (language_method_t*)language_array_ptr_ref(method_roots_list, i);
        language_array_t *roots = (language_array_t*)language_array_ptr_ref(method_roots_list, i+1);
        if (roots) {
            assert(language_is_array(roots));
            language_append_method_roots(m, key, roots);
        }
    }
}


// verify that these edges intersect with the same methods as before
static language_array_t *language_verify_edges(language_array_t *targets, size_t minworld)
{
    LANGUAGE_TIMING(VERIFY_IMAGE, VERIFY_Edges);
    size_t i, l = language_array_nrows(targets) / 3;
    static language_value_t *ulong_array LANGUAGE_ALWAYS_LEAFTYPE = NULL;
    if (ulong_array == NULL)
        ulong_array = language_apply_array_type((language_value_t*)language_ulong_type, 1);
    language_array_t *maxvalids = language_alloc_array_1d(ulong_array, l);
    memset(language_array_data(maxvalids, size_t), 0, l * sizeof(size_t));
    language_value_t *loctag = NULL;
    language_value_t *matches = NULL;
    language_value_t *sig = NULL;
    LANGUAGE_GC_PUSH4(&maxvalids, &matches, &sig, &loctag);
    for (i = 0; i < l; i++) {
        language_value_t *invokesig = language_array_ptr_ref(targets, i * 3);
        language_value_t *callee = language_array_ptr_ref(targets, i * 3 + 1);
        language_value_t *expected = language_array_ptr_ref(targets, i * 3 + 2);
        size_t min_valid = 0;
        size_t max_valid = ~(size_t)0;
        if (invokesig) {
            assert(callee && "unsupported edge");
            language_method_t *m = ((language_method_instance_t*)callee)->def.method;
            if (language_egal(invokesig, m->sig)) {
                // the invoke match is `m` for `m->sig`, unless `m` is invalid
                if (language_atomic_load_relaxed(&m->deleted_world) < max_valid)
                    max_valid = 0;
            }
            else {
                language_methtable_t *mt = language_method_get_table(m);
                if ((language_value_t*)mt == language_nothing) {
                    max_valid = 0;
                }
                else {
                    matches = language_gf_invoke_lookup_worlds(invokesig, (language_value_t*)mt, minworld, &min_valid, &max_valid);
                    if (matches == language_nothing) {
                         max_valid = 0;
                    }
                    else {
                        matches = (language_value_t*)((language_method_match_t*)matches)->method;
                        if (matches != expected) {
                            max_valid = 0;
                        }
                    }
                }
            }
        }
        else {
            if (language_is_method_instance(callee)) {
                language_method_instance_t *mi = (language_method_instance_t*)callee;
                sig = language_type_intersection(mi->def.method->sig, (language_value_t*)mi->specTypes);
            }
            else {
                sig = callee;
            }
            assert(language_is_array(expected));
            int ambig = 0;
            // TODO: possibly need to included ambiguities too (for the optimizer correctness)?
            // len + 1 is to allow us to log causes of invalidation (SnoopCompile's @snoopr)
            matches = language_matching_methods((language_tupletype_t*)sig, language_nothing,
                    _language_debug_method_invalidation ? INT32_MAX : language_array_nrows(expected),
                    0, minworld, &min_valid, &max_valid, &ambig);
            sig = NULL;
            if (matches == language_nothing) {
                max_valid = 0;
            }
            else {
                // setdiff!(matches, expected)
                size_t j, k, ins = 0;
                if (language_array_nrows(matches) != language_array_nrows(expected)) {
                    max_valid = 0;
                }
                for (k = 0; k < language_array_nrows(matches); k++) {
                    language_method_t *match = ((language_method_match_t*)language_array_ptr_ref(matches, k))->method;
                    size_t l = language_array_nrows(expected);
                    for (j = 0; j < l; j++)
                        if (match == (language_method_t*)language_array_ptr_ref(expected, j))
                            break;
                    if (j == l) {
                        // intersection has a new method or a method was
                        // deleted--this is now probably no good, just invalidate
                        // everything about it now
                        max_valid = 0;
                        if (!_language_debug_method_invalidation)
                            break;
                        language_array_ptr_set(matches, ins++, match);
                    }
                }
                if (max_valid != ~(size_t)0 && _language_debug_method_invalidation)
                    language_array_del_end((language_array_t*)matches, language_array_nrows(matches) - ins);
            }
        }
        language_array_data(maxvalids, size_t)[i] = max_valid;
        if (max_valid != ~(size_t)0 && _language_debug_method_invalidation) {
            language_array_ptr_1d_push(_language_debug_method_invalidation, invokesig ? (language_value_t*)invokesig : callee);
            loctag = language_cstr_to_string("insert_backedges_callee");
            language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
            loctag = language_box_int32((int32_t)i);
            language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
            language_array_ptr_1d_push(_language_debug_method_invalidation, matches);
        }
        //language_static_show((LANGUAGE_STREAM*)ios_stderr, (language_value_t*)invokesig);
        //language_static_show((LANGUAGE_STREAM*)ios_stderr, (language_value_t*)callee);
        //ios_puts(max_valid == ~(size_t)0 ? "valid\n" : "INVALID\n", ios_stderr);
    }
    LANGUAGE_GC_POP();
    return maxvalids;
}

// Combine all edges relevant to a method to initialize the maxvalids list
static language_array_t *language_verify_methods(language_array_t *edges, language_array_t *maxvalids)
{
    LANGUAGE_TIMING(VERIFY_IMAGE, VERIFY_Methods);
    language_value_t *loctag = NULL;
    language_array_t *maxvalids2 = NULL;
    LANGUAGE_GC_PUSH2(&loctag, &maxvalids2);
    size_t i, l = language_array_nrows(edges) / 2;
    maxvalids2 = language_alloc_array_1d(language_typeof(maxvalids), l);
    size_t *maxvalids2_data = language_array_data(maxvalids2, size_t);
    memset(maxvalids2_data, 0, l * sizeof(size_t));
    for (i = 0; i < l; i++) {
        language_method_instance_t *caller = (language_method_instance_t*)language_array_ptr_ref(edges, 2 * i);
        assert(language_is_method_instance(caller) && language_is_method(caller->def.method));
        language_array_t *callee_ids = (language_array_t*)language_array_ptr_ref(edges, 2 * i + 1);
        assert(language_typetagis((language_value_t*)callee_ids, language_array_int32_type));
        if (callee_ids == NULL) {
            // serializing the edges had failed
            maxvalids2_data[i] = 0;
        }
        else {
            int32_t *idxs = language_array_data(callee_ids, int32_t);
            size_t j;
            maxvalids2_data[i] = ~(size_t)0;
            for (j = 0; j < idxs[0]; j++) {
                int32_t idx = idxs[j + 1];
                size_t max_valid = language_array_data(maxvalids, size_t)[idx];
                if (max_valid != ~(size_t)0 && _language_debug_method_invalidation) {
                    language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)caller);
                    loctag = language_cstr_to_string("verify_methods");
                    language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
                    loctag = language_box_int32((int32_t)idx);
                    language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
                }
                if (max_valid < maxvalids2_data[i])
                    maxvalids2_data[i] = max_valid;
                if (max_valid == 0)
                    break;
            }
        }
        //language_static_show((LANGUAGE_STREAM*)ios_stderr, (language_value_t*)caller);
        //ios_puts(maxvalids2_data[i] == ~(size_t)0 ? "valid\n" : "INVALID\n", ios_stderr);
    }
    LANGUAGE_GC_POP();
    return maxvalids2;
}


// Visit the entire call graph, starting from edges[idx] to determine if that method is valid
// Implements Tarjan's SCC (strongly connected components) algorithm, simplified to remove the count variable
// and slightly modified with an early termination option once the computation reaches its minimum
static int language_verify_graph_edge(size_t *maxvalids2_data, language_array_t *edges, size_t idx, arraylist_t *visited, arraylist_t *stack)
{
    if (maxvalids2_data[idx] == 0) {
        visited->items[idx] = (void*)1;
        return 0;
    }
    size_t cycle = (size_t)visited->items[idx];
    if (cycle != 0)
        return cycle - 1; // depth remaining
    language_value_t *cause = NULL;
    arraylist_push(stack, (void*)idx);
    size_t depth = stack->len;
    visited->items[idx] = (void*)(1 + depth);
    language_array_t *callee_ids = (language_array_t*)language_array_ptr_ref(edges, idx * 2 + 1);
    assert(language_typetagis((language_value_t*)callee_ids, language_array_int32_type));
    int32_t *idxs = language_array_data(callee_ids, int32_t);
    size_t i, n = language_array_nrows(callee_ids);
    cycle = depth;
    for (i = idxs[0] + 1; i < n; i++) {
        int32_t childidx = idxs[i];
        int child_cycle = language_verify_graph_edge(maxvalids2_data, edges, childidx, visited, stack);
        size_t child_max_valid = maxvalids2_data[childidx];
        if (child_max_valid < maxvalids2_data[idx]) {
            maxvalids2_data[idx] = child_max_valid;
            cause = language_array_ptr_ref(edges, childidx * 2);
        }
        if (child_max_valid == 0) {
            // found what we were looking for, so terminate early
            break;
        }
        else if (child_cycle && child_cycle < cycle) {
            // record the cycle will resolve at depth "cycle"
            cycle = child_cycle;
        }
    }
    size_t max_valid = maxvalids2_data[idx];
    if (max_valid != 0 && cycle != depth)
        return cycle;
    // If we are the top of the current cycle, now mark all other parts of
    // our cycle with what we found.
    // Or if we found a failed edge, also mark all of the other parts of the
    // cycle as also having an failed edge.
    while (stack->len >= depth) {
        size_t childidx = (size_t)arraylist_pop(stack);
        assert(visited->items[childidx] == (void*)(2 + stack->len));
        if (idx != childidx) {
            if (max_valid < maxvalids2_data[childidx])
                maxvalids2_data[childidx] = max_valid;
        }
        visited->items[childidx] = (void*)1;
        if (_language_debug_method_invalidation && max_valid != ~(size_t)0) {
            language_method_instance_t *mi = (language_method_instance_t*)language_array_ptr_ref(edges, childidx * 2);
            language_value_t *loctag = NULL;
            LANGUAGE_GC_PUSH1(&loctag);
            language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)mi);
            loctag = language_cstr_to_string("verify_methods");
            language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
            language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)cause);
            LANGUAGE_GC_POP();
        }
    }
    return 0;
}

// Visit all entries in edges, verify if they are valid
static void language_verify_graph(language_array_t *edges, language_array_t *maxvalids2)
{
    LANGUAGE_TIMING(VERIFY_IMAGE, VERIFY_Graph);
    arraylist_t stack, visited;
    arraylist_new(&stack, 0);
    size_t i, n = language_array_nrows(edges) / 2;
    arraylist_new(&visited, n);
    memset(visited.items, 0, n * sizeof(size_t));
    size_t *maxvalids2_data = language_array_data(maxvalids2, size_t);
    for (i = 0; i < n; i++) {
        assert(visited.items[i] == (void*)0 || visited.items[i] == (void*)1);
        int child_cycle = language_verify_graph_edge(maxvalids2_data, edges, i, &visited, &stack);
        assert(child_cycle == 0); (void)child_cycle;
        assert(stack.len == 0);
        assert(visited.items[i] == (void*)1);
    }
    arraylist_free(&stack);
    arraylist_free(&visited);
}

// Restore backedges to external targets
// `edges` = [caller1, targets_indexes1, ...], the list of worklist-owned methods calling external methods.
// `ext_targets` is [invokesig1, callee1, matches1, ...], the global set of non-worklist callees of worklist-owned methods.
static void language_insert_backedges(language_array_t *edges, language_array_t *ext_targets, language_array_t *ext_ci_list, size_t minworld)
{
    // determine which CodeInstance objects are still valid in our image
    language_array_t *valids = language_verify_edges(ext_targets, minworld);
    LANGUAGE_GC_PUSH1(&valids);
    valids = language_verify_methods(edges, valids); // consumes edges valids, initializes methods valids
    language_verify_graph(edges, valids); // propagates methods valids for each edge

    size_t n_ext_cis = ext_ci_list ? language_array_nrows(ext_ci_list) : 0;
    htable_t cis_pending_validation;
    htable_new(&cis_pending_validation, n_ext_cis);

    // next build a map from external MethodInstances to their CodeInstance for insertion
    for (size_t i = 0; i < n_ext_cis; i++) {
        language_code_instance_t *ci = (language_code_instance_t*)language_array_ptr_ref(ext_ci_list, i);
        if (language_atomic_load_relaxed(&ci->max_world) == WORLD_AGE_REVALIDATION_SENTINEL) {
            assert(language_atomic_load_relaxed(&ci->min_world) == minworld);
            void **bp = ptrhash_bp(&cis_pending_validation, (void*)ci->def);
            assert(!language_atomic_load_relaxed(&ci->next));
            if (*bp == HT_NOTFOUND)
                *bp = (void*)ci;
            else {
                // Do ci->owner bifurcates the cache, we temporarily
                // form a linked list of all the CI that need to be connected later
                language_code_instance_t *prev_ci = (language_code_instance_t *)*bp;
                language_atomic_store_relaxed(&ci->next, prev_ci);
                *bp = (void*)ci;
            }
        }
        else {
            assert(language_atomic_load_relaxed(&ci->min_world) == 1);
            assert(language_atomic_load_relaxed(&ci->max_world) == ~(size_t)0);
            language_method_instance_t *caller = ci->def;
            if (language_atomic_load_relaxed(&ci->inferred) && language_rettype_inferred(ci->owner, caller, minworld, ~(size_t)0) == language_nothing) {
                language_mi_cache_insert(caller, ci);
            }
            //language_static_show((LANGUAGE_STREAM*)ios_stderr, (language_value_t*)caller);
            //ios_puts("free\n", ios_stderr);
        }
    }

    // next enable any applicable new codes
    size_t nedges = language_array_nrows(edges) / 2;
    for (size_t i = 0; i < nedges; i++) {
        language_method_instance_t *caller = (language_method_instance_t*)language_array_ptr_ref(edges, 2 * i);
        size_t maxvalid = language_array_data(valids, size_t)[i];
        if (maxvalid == ~(size_t)0) {
            // if this callee is still valid, add all the backedges
            language_array_t *callee_ids = (language_array_t*)language_array_ptr_ref(edges, 2 * i + 1);
            int32_t *idxs = language_array_data(callee_ids, int32_t);
            for (size_t j = 0; j < idxs[0]; j++) {
                int32_t idx = idxs[j + 1];
                language_value_t *invokesig = language_array_ptr_ref(ext_targets, idx * 3);
                language_value_t *callee = language_array_ptr_ref(ext_targets, idx * 3 + 1);
                if (callee && language_is_method_instance(callee)) {
                    language_method_instance_add_backedge((language_method_instance_t*)callee, invokesig, caller);
                }
                else {
                    language_value_t *sig = callee == NULL ? invokesig : callee;
                    language_methtable_t *mt = language_method_table_for(sig);
                    // FIXME: rarely, `callee` has an unexpected `Union` signature,
                    // see https://github.com/JuliaLang/julia/pull/43990#issuecomment-1030329344
                    // Fix the issue and turn this back into an `assert((language_value_t*)mt != language_nothing)`
                    // This workaround exposes us to (rare) 265-violations.
                    if ((language_value_t*)mt != language_nothing)
                        language_method_table_add_backedge(mt, sig, (language_value_t*)caller);
                }
            }
        }
        // then enable any methods associated with it
        void *ci = ptrhash_get(&cis_pending_validation, (void*)caller);
        //assert(ci != HT_NOTFOUND);
        if (ci != HT_NOTFOUND) {
            // Update any external CIs and add them to the cache.
            assert(language_is_code_instance(ci));
            language_code_instance_t *codeinst = (language_code_instance_t*)ci;
            while (codeinst) {
                language_code_instance_t *next_ci = language_atomic_load_relaxed(&codeinst->next);
                language_atomic_store_relaxed(&codeinst->next, NULL);

                language_value_t *owner = codeinst->owner;
                LANGUAGE_GC_PROMISE_ROOTED(owner);

                assert(language_atomic_load_relaxed(&codeinst->min_world) == minworld);
                // See #53586, #53109
                // assert(language_atomic_load_relaxed(&codeinst->max_world) == WORLD_AGE_REVALIDATION_SENTINEL);
                assert(language_atomic_load_relaxed(&codeinst->inferred));
                language_atomic_store_relaxed(&codeinst->max_world, maxvalid);

                if (language_rettype_inferred(owner, caller, minworld, maxvalid) != language_nothing) {
                    // We already got a code instance for this world age range from somewhere else - we don't need
                    // this one.
                } else {
                    language_mi_cache_insert(caller, codeinst);
                }
                codeinst = next_ci;
            }
        }
        else {
            // Likely internal. Find the CI already in the cache hierarchy.
            for (language_code_instance_t *codeinst = language_atomic_load_relaxed(&caller->cache); codeinst; codeinst = language_atomic_load_relaxed(&codeinst->next)) {
                if (language_atomic_load_relaxed(&codeinst->min_world) == minworld && language_atomic_load_relaxed(&codeinst->max_world) == WORLD_AGE_REVALIDATION_SENTINEL) {
                    language_atomic_store_relaxed(&codeinst->max_world, maxvalid);
                }
            }
        }
    }
    htable_free(&cis_pending_validation);

    LANGUAGE_GC_POP();
}

static void classify_callers(htable_t *callers_with_edges, language_array_t *edges)
{
    size_t l = edges ? language_array_nrows(edges) / 2 : 0;
    for (size_t i = 0; i < l; i++) {
        language_method_instance_t *caller = (language_method_instance_t*)language_array_ptr_ref(edges, 2 * i);
        ptrhash_put(callers_with_edges, (void*)caller, (void*)caller);
    }
}

static language_value_t *read_verify_mod_list(ios_t *s, language_array_t *depmods)
{
    if (!language_main_module->build_id.lo) {
        return language_get_exceptionf(language_errorexception_type,
                "Main module uuid state is invalid for module deserialization.");
    }
    size_t i, l = language_array_nrows(depmods);
    for (i = 0; ; i++) {
        size_t len = read_int32(s);
        if (len == 0 && i == l)
            return NULL; // success
        if (len == 0 || i == l)
            return language_get_exceptionf(language_errorexception_type, "Wrong number of entries in module list.");
        char *name = (char*)alloca(len + 1);
        ios_readall(s, name, len);
        name[len] = '\0';
        language_uuid_t uuid;
        uuid.hi = read_uint64(s);
        uuid.lo = read_uint64(s);
        language_uuid_t build_id;
        build_id.hi = read_uint64(s);
        build_id.lo = read_uint64(s);
        language_sym_t *sym = _language_symbol(name, len);
        language_module_t *m = (language_module_t*)language_array_ptr_ref(depmods, i);
        if (!m || !language_is_module(m) || m->uuid.hi != uuid.hi || m->uuid.lo != uuid.lo || m->name != sym ||
                m->build_id.hi != build_id.hi || m->build_id.lo != build_id.lo) {
            return language_get_exceptionf(language_errorexception_type,
                "Invalid input in module list: expected %s.", name);
        }
    }
}

static int readstr_verify(ios_t *s, const char *str, int include_null)
{
    size_t i, len = strlen(str) + include_null;
    for (i = 0; i < len; ++i)
        if ((char)read_uint8(s) != str[i])
            return 0;
    return 1;
}

LANGUAGE_DLLEXPORT uint64_t language_read_verify_header(ios_t *s, uint8_t *pkgimage, int64_t *dataendpos, int64_t *datastartpos)
{
    uint16_t bom;
    uint64_t checksum = 0;
    if (readstr_verify(s, JI_MAGIC, 0) &&
        read_uint16(s) == JI_FORMAT_VERSION &&
        ios_read(s, (char *) &bom, 2) == 2 && bom == BOM &&
        read_uint8(s) == sizeof(void*) &&
        readstr_verify(s, LANGUAGE_BUILD_UNAME, 1) &&
        readstr_verify(s, LANGUAGE_BUILD_ARCH, 1) &&
        readstr_verify(s, JULIA_VERSION_STRING, 1) &&
        readstr_verify(s, language_git_branch(), 1) &&
        readstr_verify(s, language_git_commit(), 1))
    {
        *pkgimage = read_uint8(s);
        checksum = read_uint64(s);
        *datastartpos = (int64_t)read_uint64(s);
        *dataendpos = (int64_t)read_uint64(s);
    }
    return checksum;
}

// Returns `depmodidxs` where `j = depmodidxs[i]` corresponds to the blob `depmods[j]` in `write_mod_list`
static language_array_t *image_to_depmodidx(language_array_t *depmods)
{
    if (!depmods)
        return NULL;
    assert(language_array_nrows(depmods) < INT32_MAX && "too many dependencies to serialize");
    size_t lbids = n_linkage_blobs();
    size_t ldeps = language_array_nrows(depmods);
    language_array_t *depmodidxs = language_alloc_array_1d(language_array_int32_type, lbids);
    int32_t *dmidxs = language_array_data(depmodidxs, int32_t);
    memset(dmidxs, -1, lbids * sizeof(int32_t));
    dmidxs[0] = 0; // the sysimg can also be found at idx 0, by construction
    for (size_t i = 0, j = 0; i < ldeps; i++) {
        language_value_t *depmod = language_array_ptr_ref(depmods, i);
        size_t idx = external_blob_index(depmod);
        if (idx < lbids) { // language_object_in_image
            j++;
            if (dmidxs[idx] == -1)
                dmidxs[idx] = j;
        }
    }
    return depmodidxs;
}

// Returns `imageidxs` where `j = imageidxs[i]` is the blob corresponding to `depmods[j]`
static language_array_t *depmod_to_imageidx(language_array_t *depmods)
{
    if (!depmods)
        return NULL;
    size_t ldeps = language_array_nrows(depmods);
    language_array_t *imageidxs = language_alloc_array_1d(language_array_int32_type, ldeps + 1);
    int32_t *imgidxs = language_array_data(imageidxs, int32_t);
    imgidxs[0] = 0;
    for (size_t i = 0; i < ldeps; i++) {
        language_value_t *depmod = language_array_ptr_ref(depmods, i);
        size_t j = external_blob_index(depmod);
        assert(j < INT32_MAX);
        imgidxs[i + 1] = (int32_t)j;
    }
    return imageidxs;
}
