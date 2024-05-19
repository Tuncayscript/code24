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

#include <limits.h>
#include <errno.h>

#include "code.h"
#include "language_internal.h"

#include <unistd.h>
#include <getopt.h>

#include "language_assert.h"

#ifdef _OS_WINDOWS_
char *shlib_ext = ".dll";
#elif defined(_OS_DARWIN_)
char *shlib_ext = ".dylib";
#else
char *shlib_ext = ".so";
#endif

/* This simple hand-crafted tolower exists to avoid locale-dependent effects in
 * behaviors (and utf8proc_tolower wasn't linking properly on all platforms) */
static char ascii_tolower(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

static const char system_image_path[256] = "\0" LANGUAGE_SYSTEM_IMAGE_PATH;
LANGUAGE_DLLEXPORT const char *language_get_default_sysimg_path(void)
{
    return &system_image_path[1];
}

static int language_options_initialized = 0;

LANGUAGE_DLLEXPORT void language_init_options(void)
{
    if (language_options_initialized)
        return;
    language_options =
        (language_options_t){ 0,    // quiet
                        -1,   // banner
                        NULL, // language_bindir
                        NULL, // language_bin
                        NULL, // cmds
                        NULL, // image_file (will be filled in below)
                        NULL, // cpu_target ("native", "core2", etc...)
                        0,    // nthreadpools
                        0,    // nthreads
                        0,    // nmarkthreads
                        0,    // nsweepthreads
                        NULL, // nthreads_per_pool
                        0,    // nprocs
                        NULL, // machine_file
                        NULL, // project
                        0,    // isinteractive
                        0,    // color
                        LANGUAGE_OPTIONS_HISTORYFILE_ON, // history file
                        0,    // startup file
                        LANGUAGE_OPTIONS_COMPILE_DEFAULT, // compile_enabled
                        0,    // code_coverage
                        0,    // malloc_log
                        NULL, // tracked_path
                        2,    // opt_level
                        0,    // opt_level_min
#ifdef LANGUAGE_DEBUG_BUILD
                        2,    // debug_level [debug build]
#else
                        1,    // debug_level [release build]
#endif
                        LANGUAGE_OPTIONS_CHECK_BOUNDS_DEFAULT, // check_bounds
                        LANGUAGE_OPTIONS_DEPWARN_OFF,    // deprecation warning
                        0,    // method overwrite warning
                        1,    // can_inline
                        LANGUAGE_OPTIONS_POLLY_ON, // polly
                        NULL, // trace_compile
                        LANGUAGE_OPTIONS_FAST_MATH_DEFAULT,
                        0,    // worker
                        NULL, // cookie
                        LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON,
                        LANGUAGE_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_YES,
                        LANGUAGE_OPTIONS_USE_COMPILED_MODULES_YES,
                        LANGUAGE_OPTIONS_USE_PKGIMAGES_YES,
                        NULL, // bind-to
                        NULL, // output-bc
                        NULL, // output-unopt-bc
                        NULL, // output-o
                        NULL, // output-asm
                        NULL, // output-ji
                        NULL, // output-code_coverage
                        0, // incremental
                        0, // image_file_specified
                        LANGUAGE_OPTIONS_WARN_SCOPE_ON,  // ambiguous scope warning
                        0, // image-codegen
                        0, // rr-detach
                        0, // strip-metadata
                        0, // strip-ir
                        0, // permalloc_pkgimg
                        0, // heap-size-hint
    };
    language_options_initialized = 1;
}

static const char usage[] = "\n    julia [switches] -- [programfile] [args...]\n\n";
static const char opts[]  =
    "Switches (a '*' marks the default value, if applicable; settings marked '($)' may trigger package\n"
    "precompilation):\n\n"
    " Option                                        Description\n"
    " ---------------------------------------------------------------------------------------------------\n"
    " -v, --version                                 Display version information\n"
    " -h, --help                                    Print command-line options (this message)\n"
    " --help-hidden                                 Print uncommon options not shown by `-h`\n\n"

    // startup options
    " --project[={<dir>|@.}]                        Set <dir> as the active project/environment.\n"
    "                                               The default @. option will search through parent\n"
    "                                               directories until a Project.toml or JuliaProject.toml\n"
    "                                               file is found.\n"
    " -J, --sysimage <file>                         Start up with the given system image file\n"
    " -H, --home <dir>                              Set location of `julia` executable\n"
    " --startup-file={yes*|no}                      Load `JULIA_DEPOT_PATH/config/startup.jl`; \n"
    "                                               if `JULIA_DEPOT_PATH` environment variable is unset,\n"
    "                                               load `~/.julia/config/startup.jl`\n"
    " --handle-signals={yes*|no}                    Enable or disable Julia's default signal handlers\n"
    " --sysimage-native-code={yes*|no}              Use native code from system image if available\n"
    " --compiled-modules={yes*|no|existing|strict}  Enable or disable incremental precompilation of\n"
    "                                               modules. The `existing` option allows use of existing\n"
    "                                               compiled modules that were previously precompiled,\n"
    "                                               but disallows creation of new precompile files.\n"
    "                                               The `strict` option is similar, but will error if no\n"
    "                                               precompile file is found.\n"
    " --pkgimages={yes*|no|existing}                Enable or disable usage of native code caching in the\n"
    "                                               form of pkgimages. The `existing` option allows use\n"
    "                                               of existing pkgimages but disallows creation of new\n"
    "                                               ones ($)\n\n"

    // actions
    " -e, --eval <expr>                             Evaluate <expr>\n"
    " -E, --print <expr>                            Evaluate <expr> and display the result\n"
    " -m, --module <Package> [args]                 Run entry point of `Package` (`@main` function) with\n"
    "                                               `args'.\n"
    " -L, --load <file>                             Load <file> immediately on all processors\n\n"

    // parallel options
    " -t, --threads {auto|N[,auto|M]}               Enable N[+M] threads; N threads are assigned to the\n"
    "                                               `default` threadpool, and if M is specified, M\n"
    "                                               threads are assigned to the `interactive`\n"
    "                                               threadpool; `auto` tries to infer a useful\n"
    "                                               default number of threads to use but the exact\n"
    "                                               behavior might change in the future. Currently sets\n"
    "                                               N to the number of CPUs assigned to this Julia\n"
    "                                               process based on the OS-specific affinity assignment\n"
    "                                               interface if supported (Linux and Windows) or to the\n"
    "                                               number of CPU threads if not supported (MacOS) or if\n"
    "                                               process affinity is not configured, and sets M to 1.\n"
    " --gcthreads=N[,M]                             Use N threads for the mark phase of GC and M (0 or 1)\n"
    "                                               threads for the concurrent sweeping phase of GC.\n"
    "                                               N is set to half of the number of compute threads and\n"
    "                                               M is set to 0 if unspecified.\n"
    " -p, --procs {N|auto}                          Integer value N launches N additional local worker\n"
    "                                               processes `auto` launches as many workers as the\n"
    "                                               number of local CPU threads (logical cores).\n"
    " --machine-file <file>                         Run processes on hosts listed in <file>\n\n"

    // interactive options
    " -i, --interactive                             Interactive mode; REPL runs and\n"
    "                                               `isinteractive()` is true.\n"
    " -q, --quiet                                   Quiet startup: no banner, suppress REPL warnings\n"
    " --banner={yes|no|short|auto*}                 Enable or disable startup banner\n"
    " --color={yes|no|auto*}                        Enable or disable color text\n"
    " --history-file={yes*|no}                      Load or save history\n\n"

    // error and warning options
    " --depwarn={yes|no*|error}                     Enable or disable syntax and method deprecation\n"
    "                                               warnings (`error` turns warnings into errors)\n"
    " --warn-overwrite={yes|no*}                    Enable or disable method overwrite warnings\n"
    " --warn-scope={yes*|no}                        Enable or disable warning for ambiguous top-level\n"
    "                                               scope\n\n"

    // code generation options
    " -C, --cpu-target <target>                     Limit usage of CPU features up to <target>; set to\n"
    "                                               `help` to see the available options\n"
    " -O, --optimize={0|1|2*|3}                     Set the optimization level (level 3 if `-O` is used\n"
    "                                               without a level) ($)\n"
    " --min-optlevel={0*|1|2|3}                     Set a lower bound on the optimization level\n"
#ifdef LANGUAGE_DEBUG_BUILD
    " -g, --debug-info=[{0|1|2*}]                   Set the level of debug info generation in the\n"
    "                                               julia-debug build ($)\n"
#else
    " -g, --debug-info=[{0|1*|2}]                   Set the level of debug info generation (level 2 if\n"
    "                                               `-g` is used without a level) ($)\n"
#endif
    " --inline={yes*|no}                            Control whether inlining is permitted, including\n"
    "                                               overriding @inline declarations\n"
    " --check-bounds={yes|no|auto*}                 Emit bounds checks always, never, or respect\n"
    "                                               @inbounds declarations ($)\n"
    " --math-mode={ieee|user*}                      Always follow `ieee` floating point semantics or\n"
    "                                               respect `@fastmath` declarations\n\n"
#ifdef USE_POLLY
    " --polly={yes*|no}                             Enable or disable the polyhedral optimizer Polly\n"
    "                                               (overrides @polly declaration)\n"
#endif

    // instrumentation options
    " --code-coverage[={none*|user|all}]            Count executions of source lines (omitting setting is\n"
    "                                               equivalent to `user`)\n"
    " --code-coverage=@<path>                       Count executions but only in files that fall under\n"
    "                                               the given file path/directory. The `@` prefix is\n"
    "                                               required to select this option. A `@` with no path\n"
    "                                               will track the current directory.\n"

    " --code-coverage=tracefile.info                Append coverage information to the LCOV tracefile\n"
    "                                               (filename supports format tokens)\n"
// TODO: These TOKENS are defined in `runtime_ccall.cpp`. A more verbose `--help` should include that list here.
    " --track-allocation[={none*|user|all}]         Count bytes allocated by each source line (omitting\n"
    "                                               setting is equivalent to `user`)\n"
    " --track-allocation=@<path>                    Count bytes but only in files that fall under the\n"
    "                                               given file path/directory. The `@` prefix is required\n"
    "                                               to select this option. A `@` with no path will track\n"
    "                                               the current directory.\n"
    " --bug-report=KIND                             Launch a bug report session. It can be used to start\n"
    "                                               a REPL, run a script, or evaluate expressions. It\n"
    "                                               first tries to use BugReporting.jl installed in\n"
    "                                               current environment and fallbacks to the latest\n"
    "                                               compatible BugReporting.jl if not. For more\n"
    "                                               information, see --bug-report=help.\n\n"
    " --heap-size-hint=<size>                       Forces garbage collection if memory usage is higher\n"
    "                                               than the given value. The value may be specified as a\n"
    "                                               number of bytes, optionally in units of KB, MB, GB,\n"
    "                                               or TB, or as a percentage of physical memory with %.\n\n"
;

static const char opts_hidden[]  =
    "Switches (a '*' marks the default value, if applicable):\n\n"
    " Option                                        Description\n"
    " ---------------------------------------------------------------------------------------------------\n"
    // code generation options
    " --compile={yes*|no|all|min}                   Enable or disable JIT compiler, or request exhaustive\n"
    "                                               or minimal compilation\n\n"

    // compiler output options
    " --output-o <name>                             Generate an object file (including system image data)\n"
    " --output-ji <name>                            Generate a system image data file (.ji)\n"
    " --strip-metadata                              Remove docstrings and source location info from\n"
    "                                               system image\n"
    " --strip-ir                                    Remove IR (intermediate representation) of compiled\n"
    "                                               functions\n\n"

    // compiler debugging (see the devdocs for tips on using these options)
    " --output-unopt-bc <name>                      Generate unoptimized LLVM bitcode (.bc)\n"
    " --output-bc <name>                            Generate LLVM bitcode (.bc)\n"
    " --output-asm <name>                           Generate an assembly file (.s)\n"
    " --output-incremental={yes|no*}                Generate an incremental output file (rather than\n"
    "                                               complete)\n"
    " --trace-compile={stderr|name}                 Print precompile statements for methods compiled\n"
    "                                               during execution or save to a path\n"
    " --image-codegen                               Force generate code in imaging mode\n"
    " --permalloc-pkgimg={yes|no*}                  Copy the data section of package images into memory\n"
;

LANGUAGE_DLLEXPORT void language_parse_opts(int *argcp, char ***argvp)
{
    enum { opt_machinefile = 300,
           opt_color,
           opt_history_file,
           opt_startup_file,
           opt_compile,
           opt_code_coverage,
           opt_track_allocation,
           opt_check_bounds,
           opt_output_unopt_bc,
           opt_output_bc,
           opt_depwarn,
           opt_warn_overwrite,
           opt_warn_scope,
           opt_inline,
           opt_polly,
           opt_trace_compile,
           opt_math_mode,
           opt_worker,
           opt_bind_to,
           opt_handle_signals,
           opt_optlevel_min,
           opt_output_o,
           opt_output_asm,
           opt_output_ji,
           opt_use_precompiled,
           opt_use_compilecache,
           opt_incremental,
           opt_help_hidden,
           opt_banner,
           opt_sysimage_native_code,
           opt_compiled_modules,
           opt_pkgimages,
           opt_machine_file,
           opt_project,
           opt_bug_report,
           opt_image_codegen,
           opt_rr_detach,
           opt_strip_metadata,
           opt_strip_ir,
           opt_heap_size_hint,
           opt_gc_threads,
           opt_permalloc_pkgimg
    };
    static const char* const shortopts = "+vhqH:e:E:L:J:C:it:p:O:g:m:";
    static const struct option longopts[] = {
        // exposed command line options
        // NOTE: This set of required arguments need to be kept in sync
        // with the required arguments defined in base/options.jl `struct LANGUAGEOptions`
        { "version",         no_argument,       0, 'v' },
        { "help",            no_argument,       0, 'h' },
        { "help-hidden",     no_argument,       0, opt_help_hidden },
        { "interactive",     no_argument,       0, 'i' },
        { "quiet",           no_argument,       0, 'q' },
        { "banner",          required_argument, 0, opt_banner },
        { "home",            required_argument, 0, 'H' },
        { "eval",            required_argument, 0, 'e' },
        { "module",          required_argument, 0, 'm' },
        { "print",           required_argument, 0, 'E' },
        { "load",            required_argument, 0, 'L' },
        { "bug-report",      required_argument, 0, opt_bug_report },
        { "sysimage",        required_argument, 0, 'J' },
        { "sysimage-native-code", required_argument, 0, opt_sysimage_native_code },
        { "compiled-modules",required_argument, 0, opt_compiled_modules },
        { "pkgimages",       required_argument, 0, opt_pkgimages },
        { "cpu-target",      required_argument, 0, 'C' },
        { "procs",           required_argument, 0, 'p' },
        { "threads",         required_argument, 0, 't' },
        { "gcthreads",       required_argument, 0, opt_gc_threads },
        { "machine-file",    required_argument, 0, opt_machine_file },
        { "project",         optional_argument, 0, opt_project },
        { "color",           required_argument, 0, opt_color },
        { "history-file",    required_argument, 0, opt_history_file },
        { "startup-file",    required_argument, 0, opt_startup_file },
        { "compile",         required_argument, 0, opt_compile },
        { "code-coverage",   optional_argument, 0, opt_code_coverage },
        { "track-allocation",optional_argument, 0, opt_track_allocation },
        { "optimize",        optional_argument, 0, 'O' },
        { "min-optlevel",    optional_argument, 0, opt_optlevel_min },
        { "debug-info",      optional_argument, 0, 'g' },
        { "check-bounds",    required_argument, 0, opt_check_bounds },
        { "output-bc",       required_argument, 0, opt_output_bc },
        { "output-unopt-bc", required_argument, 0, opt_output_unopt_bc },
        { "output-o",        required_argument, 0, opt_output_o },
        { "output-asm",      required_argument, 0, opt_output_asm },
        { "output-ji",       required_argument, 0, opt_output_ji },
        { "output-incremental",required_argument, 0, opt_incremental },
        { "depwarn",         required_argument, 0, opt_depwarn },
        { "warn-overwrite",  required_argument, 0, opt_warn_overwrite },
        { "warn-scope",      required_argument, 0, opt_warn_scope },
        { "inline",          required_argument, 0, opt_inline },
        { "polly",           required_argument, 0, opt_polly },
        { "trace-compile",   required_argument, 0, opt_trace_compile },
        { "math-mode",       required_argument, 0, opt_math_mode },
        { "handle-signals",  required_argument, 0, opt_handle_signals },
        // hidden command line options
        { "worker",          optional_argument, 0, opt_worker },
        { "bind-to",         required_argument, 0, opt_bind_to },
        { "lisp",            no_argument,       0, 1 },
        { "image-codegen",   no_argument,       0, opt_image_codegen },
        { "rr-detach",       no_argument,       0, opt_rr_detach },
        { "strip-metadata",  no_argument,       0, opt_strip_metadata },
        { "strip-ir",        no_argument,       0, opt_strip_ir },
        { "permalloc-pkgimg",required_argument, 0, opt_permalloc_pkgimg },
        { "heap-size-hint",  required_argument, 0, opt_heap_size_hint },
        { 0, 0, 0, 0 }
    };

    // If CPUID specific binaries are enabled, this varies between runs, so initialize
    // it here, rather than as part of the static initialization above.
    language_options.image_file = language_get_default_sysimg_path();
    language_options.cmds = NULL;

    int ncmds = 0;
    const char **cmds = NULL;
    int codecov = LANGUAGE_LOG_NONE;
    int malloclog = LANGUAGE_LOG_NONE;
    int argc = *argcp;
    char **argv = *argvp;
    char *endptr;
    opterr = 0; // suppress getopt warning messages
    while (1) {
        int lastind = optind;
        int c = getopt_long(argc, argv, shortopts, longopts, 0);
        if (c == -1) break;
restart_switch:
        switch (c) {
        case 0:
            break;
        case 1:
            language_errorf("--lisp must be specified as the first argument");
            break;
        case '?':
        case ':':
            if (optopt) {
                if (optopt == 'g') {
                    c = 'g';
                    goto restart_switch;
                }
                for (const struct option *o = longopts; o->val; o++) {
                    if (optopt == o->val) {
                        if (o->has_arg == optional_argument) {
                            c = o->val;
                            goto restart_switch;
                        }
                        else {
                            const char *problem = o->has_arg ? "is missing an argument" : "does not accept an argument";
                            if (o->val <= 0xff && strchr(shortopts, o->val)) {
                                language_errorf("option `-%c/--%s` %s", o->val, o->name, problem);
                            }
                            else {
                                language_errorf("option `--%s` %s", o->name, problem);
                            }
                        }
                    }
                }
                language_errorf("unknown option `-%c`", optopt);
            }
            else {
                language_errorf("unknown option `%s`", argv[lastind]);
            }
            break;
        case 'v': // version
            language_printf(LANGUAGE_STDOUT, "julia version %s\n", JULIA_VERSION_STRING);
            exit(0);
        case 'h': // help
            language_printf(LANGUAGE_STDOUT, "%s%s", usage, opts);
            exit(0);
        case opt_help_hidden:
            language_printf(LANGUAGE_STDOUT, "%s%s", usage, opts_hidden);
            exit(0);
        case 'g': // debug info
            if (optarg != NULL) {
                if (!strcmp(optarg,"0"))
                    language_options.debug_level = 0;
                else if (!strcmp(optarg,"1"))
                    language_options.debug_level = 1;
                else if (!strcmp(optarg,"2"))
                    language_options.debug_level = 2;
                else
                    language_errorf("julia: invalid argument to -g (%s)", optarg);
                break;
            }
            else {
                language_options.debug_level = 2;
            }
            break;
        case 'H': // home
            language_options.language_bindir = strdup(optarg);
            if (!language_options.language_bindir)
                language_errorf("fatal error: failed to allocate memory: %s", strerror(errno));
            break;
        case 'e': // eval
        case 'E': // print
        case 'L': // load
        case 'm': // module
        case opt_bug_report: // bug
        {
            size_t sz = strlen(optarg) + 1;
            char *arg = (char*)malloc_s(sz + 1);
            const char **newcmds;
            arg[0] = c == opt_bug_report ? 'B' : c;
            memcpy(arg + 1, optarg, sz);
            newcmds = (const char**)realloc_s(cmds, (ncmds + 2) * sizeof(char*));
            cmds = newcmds;
            cmds[ncmds] = arg;
            ncmds++;
            cmds[ncmds] = 0;
            language_options.cmds = cmds;
            if (c == 'm') {
                optind -= 1;
                goto parsing_args_done;
            }
            break;
        }
        case 'J': // sysimage
            language_options.image_file = strdup(optarg);
            if (!language_options.image_file)
                language_errorf("fatal error: failed to allocate memory: %s", strerror(errno));
            language_options.image_file_specified = 1;
            break;
        case 'q': // quiet
            language_options.quiet = 1;
            if (language_options.banner < 0)
                language_options.banner = 0;
            break;
        case opt_banner: // banner
            if (!strcmp(optarg, "yes"))
                language_options.banner = 1;
            else if (!strcmp(optarg, "no"))
                language_options.banner = 0;
            else if (!strcmp(optarg, "auto"))
                language_options.banner = -1;
            else if (!strcmp(optarg, "short"))
                language_options.banner = 2;
            else
                language_errorf("julia: invalid argument to --banner={yes|no|auto|short} (%s)", optarg);
            break;
        case opt_sysimage_native_code:
            if (!strcmp(optarg,"yes"))
                language_options.use_sysimage_native_code = LANGUAGE_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_YES;
            else if (!strcmp(optarg,"no"))
                language_options.use_sysimage_native_code = LANGUAGE_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_NO;
            else
                language_errorf("julia: invalid argument to --sysimage-native-code={yes|no} (%s)", optarg);
            break;
        case opt_compiled_modules:
            if (!strcmp(optarg,"yes"))
                language_options.use_compiled_modules = LANGUAGE_OPTIONS_USE_COMPILED_MODULES_YES;
            else if (!strcmp(optarg,"no"))
                language_options.use_compiled_modules = LANGUAGE_OPTIONS_USE_COMPILED_MODULES_NO;
            else if (!strcmp(optarg,"existing"))
                language_options.use_compiled_modules = LANGUAGE_OPTIONS_USE_COMPILED_MODULES_EXISTING;
            else if (!strcmp(optarg,"strict"))
                language_options.use_compiled_modules = LANGUAGE_OPTIONS_USE_COMPILED_MODULES_STRICT;
            else
                language_errorf("julia: invalid argument to --compiled-modules={yes|no|existing|strict} (%s)", optarg);
            break;
        case opt_pkgimages:
            if (!strcmp(optarg,"yes"))
                language_options.use_pkgimages = LANGUAGE_OPTIONS_USE_PKGIMAGES_YES;
            else if (!strcmp(optarg,"no"))
                language_options.use_pkgimages = LANGUAGE_OPTIONS_USE_PKGIMAGES_NO;
            else if (!strcmp(optarg,"existing"))
                language_options.use_pkgimages = LANGUAGE_OPTIONS_USE_PKGIMAGES_EXISTING;
            else
                language_errorf("julia: invalid argument to --pkgimages={yes|no} (%s)", optarg);
            break;
        case 'C': // cpu-target
            language_options.cpu_target = strdup(optarg);
            if (!language_options.cpu_target)
                language_error("julia: failed to allocate memory");
            break;
        case 't': // threads
            errno = 0;
            language_options.nthreadpools = 1;
            long nthreads = -1, nthreadsi = 0;
            if (!strncmp(optarg, "auto", 4)) {
                language_options.nthreads = -1;
                if (optarg[4] == ',') {
                    if (!strncmp(&optarg[5], "auto", 4))
                        nthreadsi = 1;
                    else {
                        errno = 0;
                        nthreadsi = strtol(&optarg[5], &endptr, 10);
                        if (errno != 0 || endptr == &optarg[5] || *endptr != 0 || nthreadsi < 1 || nthreadsi >= INT16_MAX)
                            language_errorf("julia: -t,--threads=auto,<m>; m must be an integer >= 1");
                    }
                    language_options.nthreadpools++;
                }
            }
            else {
                nthreads = strtol(optarg, &endptr, 10);
                if (errno != 0 || optarg == endptr || nthreads < 1 || nthreads >= INT16_MAX)
                    language_errorf("julia: -t,--threads=<n>[,auto|<m>]; n must be an integer >= 1");
                if (*endptr == ',') {
                    if (!strncmp(&endptr[1], "auto", 4))
                        nthreadsi = 1;
                    else {
                        errno = 0;
                        char *endptri;
                        nthreadsi = strtol(&endptr[1], &endptri, 10);
                        if (errno != 0 || endptri == &endptr[1] || *endptri != 0 || nthreadsi < 1 || nthreadsi >= INT16_MAX)
                            language_errorf("julia: -t,--threads=<n>,<m>; n and m must be integers >= 1");
                    }
                    language_options.nthreadpools++;
                }
                language_options.nthreads = nthreads + nthreadsi;
            }
            int16_t *ntpp = (int16_t *)malloc_s(language_options.nthreadpools * sizeof(int16_t));
            ntpp[0] = (int16_t)nthreads;
            if (language_options.nthreadpools == 2)
                ntpp[1] = (int16_t)nthreadsi;
            language_options.nthreads_per_pool = ntpp;
            break;
        case 'p': // procs
            errno = 0;
            if (!strcmp(optarg,"auto")) {
                language_options.nprocs = language_effective_threads();
            }
            else {
                long nprocs = strtol(optarg, &endptr, 10);
                if (errno != 0 || optarg == endptr || *endptr != 0 || nprocs < 1 || nprocs >= INT16_MAX)
                    language_errorf("julia: -p,--procs=<n> must be an integer >= 1");
                language_options.nprocs = (int)nprocs;
            }
            break;
        case opt_machine_file:
            language_options.machine_file = strdup(optarg);
            if (!language_options.machine_file)
                language_error("julia: failed to allocate memory");
            break;
        case opt_project:
            language_options.project = optarg ? strdup(optarg) : "@.";
            break;
        case opt_color:
            if (!strcmp(optarg, "yes"))
                language_options.color = LANGUAGE_OPTIONS_COLOR_ON;
            else if (!strcmp(optarg, "no"))
                language_options.color = LANGUAGE_OPTIONS_COLOR_OFF;
            else if (!strcmp(optarg, "auto"))
                language_options.color = LANGUAGE_OPTIONS_COLOR_AUTO;
            else
                language_errorf("julia: invalid argument to --color={yes|no|auto} (%s)", optarg);
            break;
        case opt_history_file:
            if (!strcmp(optarg,"yes"))
                language_options.historyfile = LANGUAGE_OPTIONS_HISTORYFILE_ON;
            else if (!strcmp(optarg,"no"))
                language_options.historyfile = LANGUAGE_OPTIONS_HISTORYFILE_OFF;
            else
                language_errorf("julia: invalid argument to --history-file={yes|no} (%s)", optarg);
            break;
        case opt_startup_file:
            if (!strcmp(optarg,"yes"))
                language_options.startupfile = LANGUAGE_OPTIONS_STARTUPFILE_ON;
            else if (!strcmp(optarg,"no"))
                language_options.startupfile = LANGUAGE_OPTIONS_STARTUPFILE_OFF;
            else
                language_errorf("julia: invalid argument to --startup-file={yes|no} (%s)", optarg);
            break;
        case opt_compile:
            if (!strcmp(optarg,"yes"))
                language_options.compile_enabled = LANGUAGE_OPTIONS_COMPILE_ON;
            else if (!strcmp(optarg,"no"))
                language_options.compile_enabled = LANGUAGE_OPTIONS_COMPILE_OFF;
            else if (!strcmp(optarg,"all"))
                language_options.compile_enabled = LANGUAGE_OPTIONS_COMPILE_ALL;
            else if (!strcmp(optarg,"min"))
                language_options.compile_enabled = LANGUAGE_OPTIONS_COMPILE_MIN;
            else
                language_errorf("julia: invalid argument to --compile (%s)", optarg);
            break;
        case opt_code_coverage:
            if (optarg != NULL) {
                size_t endof = strlen(optarg);
                if (!strcmp(optarg, "user"))
                    codecov = LANGUAGE_LOG_USER;
                else if (!strcmp(optarg, "all"))
                    codecov = LANGUAGE_LOG_ALL;
                else if (!strcmp(optarg, "none"))
                    codecov = LANGUAGE_LOG_NONE;
                else if (endof > 5 && !strcmp(optarg + endof - 5, ".info")) {
                    if (codecov == LANGUAGE_LOG_NONE)
                        codecov = LANGUAGE_LOG_ALL;
                    language_options.output_code_coverage = optarg;
                }
                else if (!strncmp(optarg, "@", 1)) {
                    codecov = LANGUAGE_LOG_PATH;
                    language_options.tracked_path = optarg + 1; // skip `@`
                }
                else
                    language_errorf("julia: invalid argument to --code-coverage (%s)", optarg);
                break;
            }
            else {
                codecov = LANGUAGE_LOG_USER;
            }
            break;
        case opt_track_allocation:
            if (optarg != NULL) {
                if (!strcmp(optarg,"user"))
                    malloclog = LANGUAGE_LOG_USER;
                else if (!strcmp(optarg,"all"))
                    malloclog = LANGUAGE_LOG_ALL;
                else if (!strcmp(optarg,"none"))
                    malloclog = LANGUAGE_LOG_NONE;
                else if (!strncmp(optarg, "@", 1)) {
                    malloclog = LANGUAGE_LOG_PATH;
                    language_options.tracked_path = optarg + 1; // skip `@`
                }
                else
                    language_errorf("julia: invalid argument to --track-allocation (%s)", optarg);
                break;
            }
            else {
                malloclog = LANGUAGE_LOG_USER;
            }
            break;
        case 'O': // optimize
            if (optarg != NULL) {
                if (!strcmp(optarg,"0"))
                    language_options.opt_level = 0;
                else if (!strcmp(optarg,"1"))
                    language_options.opt_level = 1;
                else if (!strcmp(optarg,"2"))
                    language_options.opt_level = 2;
                else if (!strcmp(optarg,"3"))
                    language_options.opt_level = 3;
                else
                    language_errorf("julia: invalid argument to -O (%s)", optarg);
                break;
            }
            else {
                language_options.opt_level = 3;
            }
            break;
        case opt_optlevel_min: // minimum module optimize level
            if (optarg != NULL) {
                if (!strcmp(optarg,"0"))
                    language_options.opt_level_min = 0;
                else if (!strcmp(optarg,"1"))
                    language_options.opt_level_min = 1;
                else if (!strcmp(optarg,"2"))
                    language_options.opt_level_min = 2;
                else if (!strcmp(optarg,"3"))
                    language_options.opt_level_min = 3;
                else
                    language_errorf("julia: invalid argument to --min-optlevel (%s)", optarg);
                break;
            }
            else {
                language_options.opt_level_min = 0;
            }
            break;
        case 'i': // isinteractive
            language_options.isinteractive = 1;
            break;
        case opt_check_bounds:
            if (!strcmp(optarg,"yes"))
                language_options.check_bounds = LANGUAGE_OPTIONS_CHECK_BOUNDS_ON;
            else if (!strcmp(optarg,"no"))
                language_options.check_bounds = LANGUAGE_OPTIONS_CHECK_BOUNDS_OFF;
            else if (!strcmp(optarg,"auto"))
                language_options.check_bounds = LANGUAGE_OPTIONS_CHECK_BOUNDS_DEFAULT;
            else
                language_errorf("julia: invalid argument to --check-bounds={yes|no|auto} (%s)", optarg);
            break;
        case opt_output_bc:
            language_options.outputbc = optarg;
            if (!language_options.image_file_specified) language_options.image_file = NULL;
            break;
        case opt_output_unopt_bc:
            language_options.outputunoptbc = optarg;
            if (!language_options.image_file_specified) language_options.image_file = NULL;
            break;
        case opt_output_o:
            language_options.outputo = optarg;
            if (!language_options.image_file_specified) language_options.image_file = NULL;
            break;
        case opt_output_asm:
            language_options.outputasm = optarg;
            if (!language_options.image_file_specified) language_options.image_file = NULL;
            break;
        case opt_output_ji:
            language_options.outputji = optarg;
            if (!language_options.image_file_specified) language_options.image_file = NULL;
            break;
        case opt_incremental:
            if (!strcmp(optarg,"yes"))
                language_options.incremental = 1;
            else if (!strcmp(optarg,"no"))
                language_options.incremental = 0;
            else
                language_errorf("julia: invalid argument to --output-incremental={yes|no} (%s)", optarg);
            break;
        case opt_depwarn:
            if (!strcmp(optarg,"yes"))
                language_options.depwarn = LANGUAGE_OPTIONS_DEPWARN_ON;
            else if (!strcmp(optarg,"no"))
                language_options.depwarn = LANGUAGE_OPTIONS_DEPWARN_OFF;
            else if (!strcmp(optarg,"error"))
                language_options.depwarn = LANGUAGE_OPTIONS_DEPWARN_ERROR;
            else
                language_errorf("julia: invalid argument to --depwarn={yes|no|error} (%s)", optarg);
            break;
        case opt_warn_overwrite:
            if (!strcmp(optarg,"yes"))
                language_options.warn_overwrite = LANGUAGE_OPTIONS_WARN_OVERWRITE_ON;
            else if (!strcmp(optarg,"no"))
                language_options.warn_overwrite = LANGUAGE_OPTIONS_WARN_OVERWRITE_OFF;
            else
                language_errorf("julia: invalid argument to --warn-overwrite={yes|no} (%s)", optarg);
            break;
        case opt_warn_scope:
            if (!strcmp(optarg,"yes"))
                language_options.warn_scope = LANGUAGE_OPTIONS_WARN_SCOPE_ON;
            else if (!strcmp(optarg,"no"))
                language_options.warn_scope = LANGUAGE_OPTIONS_WARN_SCOPE_OFF;
            else
                language_errorf("julia: invalid argument to --warn-scope={yes|no} (%s)", optarg);
            break;
        case opt_inline:
            if (!strcmp(optarg,"yes"))
                language_options.can_inline = 1;
            else if (!strcmp(optarg,"no"))
                language_options.can_inline = 0;
            else {
                language_errorf("julia: invalid argument to --inline (%s)", optarg);
            }
            break;
       case opt_polly:
            if (!strcmp(optarg,"yes"))
                language_options.polly = LANGUAGE_OPTIONS_POLLY_ON;
            else if (!strcmp(optarg,"no"))
                language_options.polly = LANGUAGE_OPTIONS_POLLY_OFF;
            else {
                language_errorf("julia: invalid argument to --polly (%s)", optarg);
            }
            break;
         case opt_trace_compile:
            language_options.trace_compile = strdup(optarg);
            if (!language_options.trace_compile)
                language_errorf("fatal error: failed to allocate memory: %s", strerror(errno));
            break;
        case opt_math_mode:
            if (!strcmp(optarg,"ieee"))
                language_options.fast_math = LANGUAGE_OPTIONS_FAST_MATH_OFF;
            else if (!strcmp(optarg,"fast"))
                language_options.fast_math = LANGUAGE_OPTIONS_FAST_MATH_DEFAULT;
            else if (!strcmp(optarg,"user"))
                language_options.fast_math = LANGUAGE_OPTIONS_FAST_MATH_DEFAULT;
            else
                language_errorf("julia: invalid argument to --math-mode={ieee|user} (%s)", optarg);
            break;
        case opt_worker:
            language_options.worker = 1;
            if (optarg != NULL) {
                language_options.cookie = strdup(optarg);
                if (!language_options.cookie)
                    language_error("julia: failed to allocate memory");
            }
            break;
        case opt_bind_to:
            language_options.bindto = strdup(optarg);
            if (!language_options.bindto)
                language_error("julia: failed to allocate memory");
            break;
        case opt_handle_signals:
            if (!strcmp(optarg,"yes"))
                language_options.handle_signals = LANGUAGE_OPTIONS_HANDLE_SIGNALS_ON;
            else if (!strcmp(optarg,"no"))
                language_options.handle_signals = LANGUAGE_OPTIONS_HANDLE_SIGNALS_OFF;
            else
                language_errorf("julia: invalid argument to --handle-signals (%s)", optarg);
            break;
        case opt_image_codegen:
            language_options.image_codegen = 1;
            break;
        case opt_rr_detach:
            language_options.rr_detach = 1;
            break;
        case opt_strip_metadata:
            language_options.strip_metadata = 1;
            break;
        case opt_strip_ir:
            language_options.strip_ir = 1;
            break;
        case opt_heap_size_hint:
            if (optarg != NULL) {
                long double value = 0.0;
                char unit[4] = {0};
                int nparsed = sscanf(optarg, "%Lf%3s", &value, unit);
                if (nparsed == 0 || strlen(unit) > 2 || (strlen(unit) == 2 && ascii_tolower(unit[1]) != 'b')) {
                    language_errorf("julia: invalid argument to --heap-size-hint (%s)", optarg);
                }
                uint64_t multiplier = 1ull;
                switch (ascii_tolower(unit[0])) {
                    case '\0':
                    case 'b':
                        break;
                    case 'k':
                        multiplier <<= 10;
                        break;
                    case 'm':
                        multiplier <<= 20;
                        break;
                    case 'g':
                        multiplier <<= 30;
                        break;
                    case 't':
                        multiplier <<= 40;
                        break;
                    case '%':
                        if (value > 100)
                            language_errorf("julia: invalid percentage specified in --heap-size-hint");
                        uint64_t mem = uv_get_total_memory();
                        uint64_t cmem = uv_get_constrained_memory();
                        if (cmem > 0 && cmem < mem)
                            mem = cmem;
                        multiplier = mem/100;
                        break;
                    default:
                        language_errorf("julia: invalid argument to --heap-size-hint (%s)", optarg);
                        break;
                }
                long double sz = value * multiplier;
                if (isnan(sz) || sz < 0) {
                    language_errorf("julia: invalid argument to --heap-size-hint (%s)", optarg);
                }
                const long double limit = ldexpl(1.0, 64); // UINT64_MAX + 1
                language_options.heap_size_hint = sz < limit ? (uint64_t)sz : UINT64_MAX;
            }
            if (language_options.heap_size_hint == 0)
                language_errorf("julia: invalid memory size specified in --heap-size-hint");

            break;
        case opt_gc_threads:
            errno = 0;
            long nmarkthreads = strtol(optarg, &endptr, 10);
            if (errno != 0 || optarg == endptr || nmarkthreads < 1 || nmarkthreads >= INT16_MAX) {
                language_errorf("julia: --gcthreads=<n>[,<m>]; n must be an integer >= 1");
            }
            language_options.nmarkthreads = (int16_t)nmarkthreads;
            if (*endptr == ',') {
                errno = 0;
                char *endptri;
                long nsweepthreads = strtol(&endptr[1], &endptri, 10);
                if (errno != 0 || endptri == &endptr[1] || *endptri != 0 || nsweepthreads < 0 || nsweepthreads > 1)
                    language_errorf("julia: --gcthreads=<n>,<m>; m must be 0 or 1");
                language_options.nsweepthreads = (int8_t)nsweepthreads;
            }
            break;
        case opt_permalloc_pkgimg:
            if (!strcmp(optarg,"yes"))
                language_options.permalloc_pkgimg = 1;
            else if (!strcmp(optarg,"no"))
                language_options.permalloc_pkgimg = 0;
            else
                language_errorf("julia: invalid argument to --permalloc-pkgimg={yes|no} (%s)", optarg);
            break;
        default:
            language_errorf("julia: unhandled option -- %c\n"
                      "This is a bug, please report it.", c);
        }
    }
    parsing_args_done:
    language_options.code_coverage = codecov;
    language_options.malloc_log = malloclog;
    int proc_args = *argcp < optind ? *argcp : optind;
    *argvp += proc_args;
    *argcp -= proc_args;
}

LANGUAGE_DLLEXPORT ssize_t language_sizeof_language_options(void)
{
    return sizeof(language_options_t);
}
