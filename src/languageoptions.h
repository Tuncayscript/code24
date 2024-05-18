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

#ifndef LANGUAGEOPTIONS_H
#define LANGUAGEOPTIONS_H

// NOTE: This struct needs to be kept in sync with LANGUAGEOptions type in base/options.jl

typedef struct {
    int8_t quiet;
    int8_t banner;
    const char *language_bindir;
    const char *language_bin;
    const char **cmds;
    const char *image_file;
    const char *cpu_target;
    int8_t nthreadpools;
    int16_t nthreads;
    int16_t nmarkthreads;
    int8_t nsweepthreads;
    const int16_t *nthreads_per_pool;
    int32_t nprocs;
    const char *machine_file;
    const char *project;
    int8_t isinteractive;
    int8_t color;
    int8_t historyfile;
    int8_t startupfile;
    int8_t compile_enabled;
    int8_t code_coverage;
    int8_t malloc_log;
    const char *tracked_path;
    int8_t opt_level;
    int8_t opt_level_min;
    int8_t debug_level;
    int8_t check_bounds;
    int8_t depwarn;
    int8_t warn_overwrite;
    int8_t can_inline;
    int8_t polly;
    const char *trace_compile;
    int8_t fast_math;
    int8_t worker;
    const char *cookie;
    int8_t handle_signals;
    int8_t use_sysimage_native_code;
    int8_t use_compiled_modules;
    int8_t use_pkgimages;
    const char *bindto;
    const char *outputbc;
    const char *outputunoptbc;
    const char *outputo;
    const char *outputasm;
    const char *outputji;
    const char *output_code_coverage;
    int8_t incremental;
    int8_t image_file_specified;
    int8_t warn_scope;
    int8_t image_codegen;
    int8_t rr_detach;
    int8_t strip_metadata;
    int8_t strip_ir;
    int8_t permalloc_pkgimg;
    uint64_t heap_size_hint;
} language_options_t;

#endif
