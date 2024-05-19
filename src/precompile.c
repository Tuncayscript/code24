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
  precompile.c
  Generating compiler output artifacts (object files, etc.)
*/

#include <stdlib.h>

#include "code.h"
#include "language_internal.h"
#include "language_assert.h"
#include "serialize.h"

#ifdef __cplusplus
extern "C" {
#endif

LANGUAGE_DLLEXPORT int language_generating_output(void)
{
    return language_options.outputo || language_options.outputbc || language_options.outputunoptbc || language_options.outputji || language_options.outputasm;
}

void write_srctext(ios_t *f, language_array_t *udeps, int64_t srctextpos) {
    // Write the source-text for the dependent files
    if (udeps) {
        // Go back and update the source-text position to point to the current position
        int64_t posfile = ios_pos(f);
        ios_seek(f, srctextpos);
        write_uint64(f, posfile);
        ios_seek_end(f);
        // Each source-text file is written as
        //   int32: length of abspath
        //   char*: abspath
        //   uint64: length of src text
        //   char*: src text
        // At the end we write int32(0) as a terminal sentinel.
        size_t len = language_array_nrows(udeps);
        static language_value_t *replace_depot_func = NULL;
        if (!replace_depot_func)
            replace_depot_func = language_get_global(language_base_module, language_symbol("replace_depot_path"));
        ios_t srctext;
        language_value_t *deptuple = NULL;
        LANGUAGE_GC_PUSH2(&deptuple, &udeps);
        for (size_t i = 0; i < len; i++) {
            deptuple = language_array_ptr_ref(udeps, i);
            language_value_t *depmod = language_fieldref(deptuple, 0);  // module
            // Dependencies declared with `include_dependency` are excluded
            // because these may not be Julia code (and could be huge)
            if (depmod != (language_value_t*)language_main_module) {
                language_value_t *abspath = language_fieldref(deptuple, 1);  // file abspath
                const char *abspathstr = language_string_data(abspath);
                if (!abspathstr[0])
                    continue;
                ios_t *srctp = ios_file(&srctext, abspathstr, 1, 0, 0, 0);
                if (!srctp) {
                    language_printf(LANGUAGE_STDERR, "WARNING: could not cache source text for \"%s\".\n",
                              abspathstr);
                    continue;
                }

                language_value_t **replace_depot_args;
                LANGUAGE_GC_PUSHARGS(replace_depot_args, 2);
                replace_depot_args[0] = replace_depot_func;
                replace_depot_args[1] = abspath;
                language_task_t *ct = language_current_task;
                size_t last_age = ct->world_age;
                ct->world_age = language_atomic_load_acquire(&language_world_counter);
                language_value_t *depalias = (language_value_t*)language_apply(replace_depot_args, 2);
                ct->world_age = last_age;
                LANGUAGE_GC_POP();

                size_t slen = language_string_len(depalias);
                write_int32(f, slen);
                ios_write(f, language_string_data(depalias), slen);
                posfile = ios_pos(f);
                write_uint64(f, 0);   // placeholder for length of this file in bytes
                uint64_t filelen = (uint64_t) ios_copyall(f, &srctext);
                ios_close(&srctext);
                ios_seek(f, posfile);
                write_uint64(f, filelen);
                ios_seek_end(f);
            }
        }
        LANGUAGE_GC_POP();
    }
    write_int32(f, 0); // mark the end of the source text
}

LANGUAGE_DLLEXPORT void language_write_compiler_output(void)
{
    if (!language_generating_output()) {
        return;
    }

    language_task_wait_empty(); // wait for most work to finish (except possibly finalizers)
    language_gc_collect(LANGUAGE_GC_FULL);
    language_gc_collect(LANGUAGE_GC_INCREMENTAL); // sweep finalizers
    language_task_t *ct = language_current_task;
    language_gc_enable_finalizers(ct, 0); // now disable finalizers, as they could schedule more work or make other unexpected changes to reachability
    language_task_wait_empty(); // then make sure we are the only thread alive that could be running user code past here

    if (!language_module_init_order) {
        language_printf(LANGUAGE_STDERR, "WARNING: --output requested, but no modules defined during run\n");
        return;
    }

    language_array_t *worklist = language_module_init_order;
    language_array_t *udeps = NULL;
    LANGUAGE_GC_PUSH2(&worklist, &udeps);
    language_module_init_order = language_alloc_vec_any(0);
    int i, l = language_array_nrows(worklist);
    for (i = 0; i < l; i++) {
        language_value_t *m = language_array_ptr_ref(worklist, i);
        language_value_t *f = language_get_global((language_module_t*)m, language_symbol("__init__"));
        if (f) {
            language_array_ptr_1d_push(language_module_init_order, m);
            int setting = language_get_module_compile((language_module_t*)m);
            if (setting != LANGUAGE_OPTIONS_COMPILE_OFF &&
                setting != LANGUAGE_OPTIONS_COMPILE_MIN) {
                // TODO: this would be better handled if moved entirely to language_precompile
                // since it's a slightly duplication of effort
                language_value_t *tt = language_is_type(f) ? (language_value_t*)language_wrap_Type(f) : language_typeof(f);
                LANGUAGE_GC_PUSH1(&tt);
                tt = language_apply_tuple_type_v(&tt, 1);
                language_compile_hint((language_tupletype_t*)tt);
                LANGUAGE_GC_POP();
            }
        }
    }

    assert(language_precompile_toplevel_module == NULL);
    void *native_code = NULL;

    bool_t emit_native = language_options.outputo || language_options.outputbc || language_options.outputunoptbc || language_options.outputasm;

    const char *outputji = language_options.outputji;

    bool_t emit_split = outputji && emit_native;

    ios_t *s = NULL;
    ios_t *z = NULL;
    int64_t srctextpos = 0 ;
    language_create_system_image(emit_native ? &native_code : NULL,
                           language_options.incremental ? worklist : NULL,
                           emit_split, &s, &z, &udeps, &srctextpos);

    if (!emit_split)
        z = s;

    ios_t f;

    if (outputji) {
        if (ios_file(&f, outputji, 1, 1, 1, 1) == NULL)
            language_errorf("cannot open system image file \"%s\" for writing", outputji);
        ios_write(&f, (const char *)s->buf, (size_t)s->size);
        ios_close(s);
        free(s);
    }

    // language_dump_native writes the clone_targets into `s`
    // We need to postpone the srctext writing after that.
    if (native_code) {
        ios_t *targets = outputji ? &f : NULL;
        // language_dump_native will close and free z when appropriate
        // this is a horrible abstraction, but
        // this helps reduce live memory significantly
        language_dump_native(native_code,
                        language_options.outputbc,
                        language_options.outputunoptbc,
                        language_options.outputo,
                        language_options.outputasm,
                        z, targets, NULL);
        language_postoutput_hook();
    }

    if (outputji) {
        if (language_options.incremental) {
            write_srctext(&f, udeps, srctextpos);
        }
        ios_close(&f);
    }

    for (size_t i = 0; i < language_current_modules.size; i += 2) {
        if (language_current_modules.table[i + 1] != HT_NOTFOUND) {
            language_printf(LANGUAGE_STDERR, "\nWARNING: detected unclosed module: ");
            language_static_show(LANGUAGE_STDERR, (language_value_t*)language_current_modules.table[i]);
            language_printf(LANGUAGE_STDERR, "\n  ** incremental compilation may be broken for this module **\n\n");
        }
    }
    LANGUAGE_GC_POP();
    language_gc_enable_finalizers(ct, 1);
}

#ifdef __cplusplus
}
#endif
