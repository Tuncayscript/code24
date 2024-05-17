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
  api.c
  miscellaneous functions for users of libjulia.so, to handle initialization
  and the style of use where julia is not in control most of the time.
*/
#include "platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "code.h"
#include "options.h"
#include "language_assert.h"
#include "language_internal.h"

#ifdef USE_TRACY
#include "tracy/TracyC.h"
#endif

#ifdef __cplusplus
#include <cfenv>
extern "C" {
#else
#include <fenv.h>
#endif

/**
 * @brief Check if Julia is already initialized.
 *
 * Determine if Julia has been previously initialized
 * via `language_init` or `language_init_with_image`.
 *
 * @return Returns 1 if Julia is initialized, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int language_is_initialized(void)
{
    return language_main_module != NULL;
}

/**
 * @brief Set Julia command line arguments.
 *
 * Allows setting the command line arguments for Julia,
 * similar to arguments passed in the main function of a C program.
 *
 * @param argc The number of command line arguments.
 * @param argv Array of command line arguments.
 */
LANGUAGE_DLLEXPORT void language_set_ARGS(int argc, char **argv)
{
    if (language_core_module != NULL) {
        language_array_t *args = (language_array_t*)language_get_global(language_core_module, language_symbol("ARGS"));
        if (args == NULL) {
            args = language_alloc_vec_any(0);
            LANGUAGE_GC_PUSH1(&args);
            language_set_const(language_core_module, language_symbol("ARGS"), (language_value_t*)args);
            LANGUAGE_GC_POP();
        }
        assert(language_array_nrows(args) == 0);
        language_array_grow_end(args, argc);
        int i;
        for (i = 0; i < argc; i++) {
            language_value_t *s = (language_value_t*)language_cstr_to_string(argv[i]);
            language_array_ptr_set(args, i, s);
        }
    }
}

/**
 * @brief Initialize Julia with a specified system image file.
 *
 * Initializes Julia by specifying the usr/bin directory where the Julia binary is
 * and the path of a system image file (*.so). If the language_bindir is NULL, the function
 * attempts to guess the directory. The image_path is interpreted as a path to the system image
 * file. A non-absolute path for the system image is considered relative to language_bindir, or
 * relative to the default Julia home directory. The default system image is typically
 * something like ../lib/julia/sys.so.
 *
 * @param language_bindir The usr/bin directory where the Julia binary is located, or NULL to guess.
 * @param image_path The path of a system image file (*.so). Interpreted as relative to language_bindir
 *                   or the default Julia home directory if not an absolute path.
 */
LANGUAGE_DLLEXPORT void language_init_with_image(const char *language_bindir,
                                     const char *image_path)
{
    if (language_is_initialized())
        return;
    libsupport_init();
    language_options.language_bindir = language_bindir;
    if (image_path != NULL)
        language_options.image_file = image_path;
    else
        language_options.image_file = language_get_default_sysimg_path();
    language_init(LANGUAGE_IMAGE_JULIA_HOME);
    language_exception_clear();
}

/**
 * @brief Initialize the Julia runtime.
 *
 * Initializes the Julia runtime without any specific system image.
 * It must be called before any other Julia API functions.
 */
LANGUAGE_DLLEXPORT void language_init(void)
{
    char *libbindir = NULL;
#ifdef _OS_WINDOWS_
    libbindir = strdup(language_get_libdir());
#else
    (void)asprintf(&libbindir, "%s" PATHSEPSTRING ".." PATHSEPSTRING "%s", language_get_libdir(), "bin");
#endif
    if (!libbindir) {
        printf("language_init unable to find libjulia!\n");
        abort();
    }
    language_init_with_image(libbindir, language_get_default_sysimg_path());
    free(libbindir);
}

// HACK: remove this for Julia 1.8 (see <https://github.com/JuliaLang/julia/issues/40730>)
LANGUAGE_DLLEXPORT void language_init__threading(void)
{
    language_init();
}

// HACK: remove this for Julia 1.8 (see <https://github.com/JuliaLang/julia/issues/40730>)
LANGUAGE_DLLEXPORT void language_init_with_image__threading(const char *language_bindir,
                                     const char *image_relative_path)
{
    language_init_with_image(language_bindir, image_relative_path);
}

static void _language_exception_clear(language_task_t *ct) LANGUAGE_NOTSAFEPOINT
{
    ct->ptls->previous_exception = NULL;
}

/**
 * @brief Evaluate a Julia expression from a string.
 *
 * @param str A C string containing the Julia expression to be evaluated.
 * @return A pointer to `language_value_t` representing the result of the evaluation.
 *         Returns `NULL` if an error occurs during parsing or evaluation.
 */
LANGUAGE_DLLEXPORT language_value_t *language_eval_string(const char *str)
{
    language_value_t *r;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        const char filename[] = "none";
        language_value_t *ast = language_parse_all(str, strlen(str),
                filename, strlen(filename), 1);
        LANGUAGE_GC_PUSH1(&ast);
        r = language_toplevel_eval_in(language_main_module, ast);
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        r = NULL;
    }
    return r;
}

/**
 * @brief Get the current exception in the Julia context.
 *
 * @return A pointer to `language_value_t` representing the current exception.
 *         Returns `NULL` if no exception is currently thrown.
 */
LANGUAGE_DLLEXPORT language_value_t *language_current_exception(language_task_t *ct) LANGUAGE_GLOBALLY_ROOTED LANGUAGE_NOTSAFEPOINT
{
    language_excstack_t *s = ct->excstack;
    return s && s->top != 0 ? language_excstack_exception(s, s->top) : language_nothing;
}

/**
 * @brief Check if an exception has occurred in the Julia context.
 *
 * @return A pointer to `language_value_t` representing the exception that occurred.
 *         Returns `NULL` if no exception has occurred.
 */
LANGUAGE_DLLEXPORT language_value_t *language_exception_occurred(void)
{
    return language_current_task->ptls->previous_exception;
}

/**
 * @brief Clear the current exception in the Julia context.
 *
 */
LANGUAGE_DLLEXPORT void language_exception_clear(void)
{
    _language_exception_clear(language_current_task);
}

/**
 * @brief Get the type name of a Julia value.
 *
 * @param v A pointer to `language_value_t` representing the Julia value.
 * @return A C string containing the name of the type.
 */
LANGUAGE_DLLEXPORT const char *language_typename_str(language_value_t *v)
{
    if (!language_is_datatype(v))
        return NULL;
    return language_symbol_name(((language_datatype_t*)v)->name->name);
}

/**
 * @brief Get the string representation of a Julia value's type.
 *
 * @param v A pointer to `language_value_t` representing the Julia value.
 * @return A C string describing the type of the value.
 */
LANGUAGE_DLLEXPORT const char *language_typeof_str(language_value_t *v)
{
    return language_typename_str((language_value_t*)language_typeof(v));
}

/**
 * @brief Get the element type of a Julia array.
 *
 * @param a A pointer to `language_value_t` representing the Julia array.
 * @return A pointer to the type of the array elements.
 */
LANGUAGE_DLLEXPORT void *language_array_eltype(language_value_t *a)
{
    return language_tparam0(language_typeof(a));
}

/**
 * @brief Get the number of dimensions of a Julia array.
 *
 * Returns the rank (number of dimensions) of a Julia array.
 *
 * @param a A pointer to `language_value_t` representing the Julia array.
 * @return An integer representing the number of dimensions of the array.
 */
LANGUAGE_DLLEXPORT int language_array_rank(language_value_t *a)
{
    return language_array_ndims(a);
}

/**
 * @brief Get the size of a specific dimension of a Julia array.
 *
 * Returns the size (number of elements) of a specific dimension
 * of a Julia array.
 *
 * @param a A pointer to `language_array_t` representing the Julia array.
 * @param d The dimension for which the size is requested.
 * @return The size of the specified dimension of the array.
 */
LANGUAGE_DLLEXPORT size_t language_array_size(language_array_t *a, int d)
{
    // n.b this functions only use was to violate the vector abstraction, so we have to continue to emulate that
    if (d >= language_array_ndims(a))
        return a->ref.mem->length;
    return language_array_dim(a, d);
}

/**
 * @brief Get the C string pointer from a Julia string.
 *
 * @param s A pointer to `language_value_t` representing the Julia string.
 * @return A C string pointer containing the contents of the Julia string.
 */
LANGUAGE_DLLEXPORT const char *language_string_ptr(language_value_t *s)
{
    return language_string_data(s);
}

/**
 * @brief Call a Julia function with a specified number of arguments.
 *
 * @param f A pointer to `language_function_t` representing the Julia function to call.
 * @param args An array of pointers to `language_value_t` representing the arguments.
 * @param nargs The number of arguments in the array.
 * @return A pointer to `language_value_t` representing the result of the function call.
 */
LANGUAGE_DLLEXPORT language_value_t *language_call(language_function_t *f, language_value_t **args, uint32_t nargs)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    nargs++; // add f to args
    LANGUAGE_TRY {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, nargs);
        argv[0] = (language_value_t*)f;
        for (int i = 1; i < nargs; i++)
            argv[i] = args[i - 1];
        size_t last_age = ct->world_age;
        ct->world_age = language_get_world_counter();
        v = language_apply(argv, nargs);
        ct->world_age = last_age;
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Call a Julia function with no arguments.
 *
 * A specialized case of `language_call` for simpler scenarios.
 *
 * @param f A pointer to `language_function_t` representing the Julia function to call.
 * @return A pointer to `language_value_t` representing the result of the function call.
 */
LANGUAGE_DLLEXPORT language_value_t *language_call0(language_function_t *f)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        LANGUAGE_GC_PUSH1(&f);
        size_t last_age = ct->world_age;
        ct->world_age = language_get_world_counter();
        v = language_apply_generic(f, NULL, 0);
        ct->world_age = last_age;
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Call a Julia function with one argument.
 *
 * A specialized case of `language_call` for simpler scenarios.
 *
 * @param f A pointer to `language_function_t` representing the Julia function to call.
 * @param a A pointer to `language_value_t` representing the argument to the function.
 * @return A pointer to `language_value_t` representing the result of the function call.
 */
LANGUAGE_DLLEXPORT language_value_t *language_call1(language_function_t *f, language_value_t *a)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, 2);
        argv[0] = f;
        argv[1] = a;
        size_t last_age = ct->world_age;
        ct->world_age = language_get_world_counter();
        v = language_apply(argv, 2);
        ct->world_age = last_age;
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Call a Julia function with two arguments.
 *
 * A specialized case of `language_call` for simpler scenarios.
 *
 * @param f A pointer to `language_function_t` representing the Julia function to call.
 * @param a A pointer to `language_value_t` representing the first argument.
 * @param b A pointer to `language_value_t` representing the second argument.
 * @return A pointer to `language_value_t` representing the result of the function call.
 */
LANGUAGE_DLLEXPORT language_value_t *language_call2(language_function_t *f, language_value_t *a, language_value_t *b)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, 3);
        argv[0] = f;
        argv[1] = a;
        argv[2] = b;
        size_t last_age = ct->world_age;
        ct->world_age = language_get_world_counter();
        v = language_apply(argv, 3);
        ct->world_age = last_age;
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Call a Julia function with three arguments.
 *
 * A specialized case of `language_call` for simpler scenarios.
 *
 * @param f A pointer to `language_function_t` representing the Julia function to call.
 * @param a A pointer to `language_value_t` representing the first argument.
 * @param b A pointer to `language_value_t` representing the second argument.
 * @param c A pointer to `language_value_t` representing the third argument.
 * @return A pointer to `language_value_t` representing the result of the function call.
 */
LANGUAGE_DLLEXPORT language_value_t *language_call3(language_function_t *f, language_value_t *a,
                                  language_value_t *b, language_value_t *c)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        language_value_t **argv;
        LANGUAGE_GC_PUSHARGS(argv, 4);
        argv[0] = f;
        argv[1] = a;
        argv[2] = b;
        argv[3] = c;
        size_t last_age = ct->world_age;
        ct->world_age = language_get_world_counter();
        v = language_apply(argv, 4);
        ct->world_age = last_age;
        LANGUAGE_GC_POP();
        _language_exception_clear(ct);
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Get a field from a Julia object.
 *
 * @param o A pointer to `language_value_t` representing the Julia object.
 * @param fld A C string representing the name of the field to retrieve.
 * @return A pointer to `language_value_t` representing the value of the field.
 */
LANGUAGE_DLLEXPORT language_value_t *language_get_field(language_value_t *o, const char *fld)
{
    language_value_t *v;
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        language_value_t *s = (language_value_t*)language_symbol(fld);
        int i = language_field_index((language_datatype_t*)language_typeof(o), (language_sym_t*)s, 1);
        v = language_get_nth_field(o, i);
        language_exception_clear();
    }
    LANGUAGE_CATCH {
        ct->ptls->previous_exception = language_current_exception(ct);
        v = NULL;
    }
    return v;
}

/**
 * @brief Begin an atomic signal-protected region.
 *
 * Marks the start of a region of code that should be protected
 * from interruption by asynchronous signals.
 */
LANGUAGE_DLLEXPORT void language_sigatomic_begin(void)
{
    LANGUAGE_SIGATOMIC_BEGIN();
}

/**
 * @brief End an atomic signal-protected region.
 *
 * Marks the end of a region of code protected from asynchronous signals.
 * It should be used in conjunction with `language_sigatomic_begin` to define signal-protected regions.
 */
LANGUAGE_DLLEXPORT void language_sigatomic_end(void)
{
    language_task_t *ct = language_current_task;
    if (ct->ptls->defer_signal == 0)
        language_error("sigatomic_end called in non-sigatomic region");
    LANGUAGE_SIGATOMIC_END();
}

/**
 * @brief Check if Julia is running in debug build mode.
 *
 * @return Returns 1 if Julia is in debug build mode, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int language_is_debugbuild(void) LANGUAGE_NOTSAFEPOINT
{
#ifdef LANGUAGE_DEBUG_BUILD
    return 1;
#else
    return 0;
#endif
}

/**
 * @brief Check if Julia has been build with assertions enabled.
 *
 * @return Returns 1 if assertions are enabled, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int8_t language_is_assertsbuild(void) LANGUAGE_NOTSAFEPOINT {
#ifndef LANGUAGE_NDEBUG
    return 1;
#else
    return 0;
#endif
}

/**
 * @brief Check if Julia's memory debugging is enabled.
 *
 * @return Returns 1 if memory debugging is enabled, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int8_t language_is_memdebug(void) LANGUAGE_NOTSAFEPOINT {
#ifdef MEMDEBUG
    return 1;
#else
    return 0;
#endif
}

/**
 * @brief Get the directory path of the Julia binary.
 *
 * @return A pointer to `language_value_t` representing the directory path as a Julia string.
 */
LANGUAGE_DLLEXPORT language_value_t *language_get_language_bindir(void)
{
    return language_cstr_to_string(language_options.language_bindir);
}

/**
 * @brief Get the path to the Julia binary.
 *
 * @return A pointer to `language_value_t` representing the full path as a Julia string.
 */
LANGUAGE_DLLEXPORT language_value_t *language_get_language_bin(void)
{
    return language_cstr_to_string(language_options.language_bin);
}

/**
 * @brief Get the path to the Julia system image file.
 *
 * @return A pointer to `language_value_t` representing the system image file path as a Julia string.
 */
LANGUAGE_DLLEXPORT language_value_t *language_get_image_file(void)
{
    return language_cstr_to_string(language_options.image_file);
}

/**
 * @brief Get the major version number of Julia.
 *
 * @return The major version number as an integer.
 */
LANGUAGE_DLLEXPORT int language_ver_major(void)
{
    return JULIA_VERSION_MAJOR;
}

/**
 * @brief Get the minor version number of Julia.
 *
 * @return The minor version number as an integer.
 */
LANGUAGE_DLLEXPORT int language_ver_minor(void)
{
    return JULIA_VERSION_MINOR;
}

/**
 * @brief Get the patch version number of Julia.
 *
 * @return The patch version number as an integer.
 */
LANGUAGE_DLLEXPORT int language_ver_patch(void)
{
    return JULIA_VERSION_PATCH;
}

/**
 * @brief Check if the current Julia version is a release version.
 *
 * @return Returns 1 if it is a release version, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int language_ver_is_release(void)
{
    return JULIA_VERSION_IS_RELEASE;
}

/**
 * @brief Get the Julia version as a string.
 *
 * @return A C string containing the version information.
 */
LANGUAGE_DLLEXPORT const char *language_ver_string(void)
{
   return JULIA_VERSION_STRING;
}

/**
 * @brief Convert a Julia value to a tagged value.
 *
 * Converts a Julia value into its corresponding tagged value representation.
 * Tagged values include additional metadata used internally by the Julia runtime.
 *
 * @param v A pointer to `language_value_t` representing the Julia value.
 * @return A pointer to `language_taggedvalue_t` representing the tagged value.
 */
LANGUAGE_DLLEXPORT language_taggedvalue_t *(language_astaggedvalue)(language_value_t *v)
{
    return language_astaggedvalue(v);
}

/**
 * @brief Convert a tagged value back to a Julia value.
 *
 * Converts a tagged value back into its original Julia value.
 * It's the inverse operation of `language_astaggedvalue`.
 *
 * @param v A pointer to `language_taggedvalue_t` representing the tagged value.
 * @return A pointer to `language_value_t` representing the original Julia value.
 */
LANGUAGE_DLLEXPORT language_value_t *(language_valueof)(language_taggedvalue_t *v)
{
    return language_valueof(v);
}

/**
 * @brief Get the type of a Julia value.
 *
 * @param v A pointer to `language_value_t` representing the Julia value.
 * @return A pointer to `language_value_t` representing the type of the value.
 */
LANGUAGE_DLLEXPORT language_value_t *(language_typeof)(language_value_t *v)
{
    return language_typeof(v);
}

/**
 * @brief Get the field types of a Julia value.
 *
 * @param v A pointer to `language_value_t` representing the Julia value.
 * @return A pointer to `language_value_t` representing the field types.
 */
LANGUAGE_DLLEXPORT language_value_t *(language_get_fieldtypes)(language_value_t *v)
{
    return (language_value_t*)language_get_fieldtypes((language_datatype_t*)v);
}

/**
 * @brief Check equality of two Julia values.
 *
 * @param a A pointer to `language_value_t` representing the first Julia value.
 * @param b A pointer to `language_value_t` representing the second Julia value.
 * @return Returns 1 if the values are equal, 0 otherwise.
 */
LANGUAGE_DLLEXPORT int ilanguage_egal(language_value_t *a, language_value_t *b)
{
    return language_egal(a, b);
}


#ifndef __clang_gcanalyzer__
/**
 * @brief Enter a state where concurrent garbage collection (GC) is considered unsafe.
 *
 * Marks the beginning of a code region where garbage collection operations are unsafe.
 * Used to make it legal to access GC-managed state (almost anything)
 *
 * @return An `int8_t` state value representing the previous GC state.
 */
LANGUAGE_DLLEXPORT int8_t (language_gc_unsafe_enter)(void)
{
    language_task_t *ct = language_current_task;
    return language_gc_unsafe_enter(ct->ptls);
}

/**
 * @brief Leave the state where garbage collection is considered unsafe.
 *
 * Ends a code region where garbage collection was marked as unsafe.
 * It restores the previous GC state using the state value returned by `language_gc_unsafe_enter`.
 *
 * @param state The state value returned by `language_gc_unsafe_enter` to restore the previous GC state.
 */
LANGUAGE_DLLEXPORT void (language_gc_unsafe_leave)(int8_t state)
{
    language_task_t *ct = language_current_task;
    language_gc_unsafe_leave(ct->ptls, state);
}

/**
 * @brief Enter a state where garbage collection (GC) is considered safe.
 *
 * Marks the beginning of a code region where garbage collection operations are safe.
 * Used to enable GC in sections of code where it was previously marked as unsafe.
 *
 * @return An `int8_t` state value representing the previous GC state.
 */
LANGUAGE_DLLEXPORT int8_t (language_gc_safe_enter)(void)
{
    language_task_t *ct = language_current_task;
    return language_gc_safe_enter(ct->ptls);
}

/**
 * @brief Leave the state where garbage collection is considered safe.
 *
 * Ends a code region where garbage collection was marked as safe.
 * It restores the previous GC state using the state value returned by `language_gc_safe_enter`.
 *
 * @param state The state value returned by `language_gc_safe_enter` to restore the previous GC state.
 */
LANGUAGE_DLLEXPORT void (language_gc_safe_leave)(int8_t state)
{
    language_task_t *ct = language_current_task;
    language_gc_safe_leave(ct->ptls, state);
}
#endif

/**
 * @brief Trigger a garbage collection safepoint in a GC-unsafe region.
 *
 * Triggers a safepoint for garbage collection. Used to
 * ensure that the garbage collector can run at specific points in the code,
 * particularly in long-running operations or loops.
 */
LANGUAGE_DLLEXPORT void language_gc_safepoint(void)
{
    language_task_t *ct = language_current_task;
    language_gc_safepoint_(ct->ptls);
}

/**
 * @brief Pause CPU execution for a brief moment.
 *
 * Used to pause the CPU briefly, typically to reduce power consumption
 * or manage CPU resources more effectively in a tight loop or busy wait scenario.
 */
LANGUAGE_DLLEXPORT void (language_cpu_pause)(void)
{
    language_cpu_pause();
}

/**
 * @brief Suspend CPU execution.
 *
 * Suspends CPU execution until a specific condition or event occurs.
 */
LANGUAGE_DLLEXPORT void (language_cpu_suspend)(void)
{
    language_cpu_suspend();
}

/**
 * @brief Wake the CPU from a suspended state.
 *
 * Used to resume CPU execution after it has been suspended using `language_cpu_suspend`.
 */
LANGUAGE_DLLEXPORT void (language_cpu_wake)(void)
{
    language_cpu_wake();
}

/**
 * @brief Enable cumulative compile timing.
 */
LANGUAGE_DLLEXPORT void language_cumulative_compile_timing_enable(void)
{
    // Increment the flag to allow reentrant callers to `@time`.
    language_atomic_fetch_add(&language_measure_compile_time_enabled, 1);
}

/**
 * @brief Disable cumulative compile timing.
 */
LANGUAGE_DLLEXPORT void language_cumulative_compile_timing_disable(void)
{
    // Decrement the flag when done measuring, allowing other callers to continue measuring.
    language_atomic_fetch_add(&language_measure_compile_time_enabled, -1);
}

/**
 * @brief Get the cumulative compilation time in nanoseconds.
 *
 * @return The cumulative compilation time in nanoseconds.
 */
LANGUAGE_DLLEXPORT uint64_t language_cumulative_compile_time_ns(void)
{
    return language_atomic_load_relaxed(&language_cumulative_compile_time);
}

/**
 * @brief Get the cumulative recompilation time in nanoseconds.
 *
 * @return The cumulative recompilation time in nanoseconds.
 */
LANGUAGE_DLLEXPORT uint64_t language_cumulative_recompile_time_ns(void)
{
    return language_atomic_load_relaxed(&language_cumulative_recompile_time);
}

/**
 * @brief Retrieve floating-point environment constants.
 *
 * Populates an array with constants related to the floating-point environment,
 * such as rounding modes and exception flags.
 *
 * @param ret An array of integers to be populated with floating-point environment constants.
 */
LANGUAGE_DLLEXPORT void language_get_fenv_consts(int *ret)
{
    ret[0] = FE_INEXACT;
    ret[1] = FE_UNDERFLOW;
    ret[2] = FE_OVERFLOW;
    ret[3] = FE_DIVBYZERO;
    ret[4] = FE_INVALID;
    ret[5] = FE_TONEAREST;
    ret[6] = FE_UPWARD;
    ret[7] = FE_DOWNWARD;
    ret[8] = FE_TOWARDZERO;
}

// TODO: Windows binaries currently load msvcrt which doesn't have these C99 functions.
//       the mingw compiler ships additional definitions, but only for use in C code.
//       remove this when we switch to ucrt, make the version in openlibm portable,
//       or figure out how to reexport the defs from libmingwex (see JuliaLang/julia#38466).
LANGUAGE_DLLEXPORT int language_get_fenv_rounding(void)
{
    return fegetround();
}

/**
 * @brief Set the floating-point rounding mode.
 *
 * @param i An integer representing the desired floating-point rounding mode.
          See also "floating-point rounding" macros in `<fenv.h>`.
 * @return An integer indicating the success or failure of setting the rounding mode.
 */
LANGUAGE_DLLEXPORT int language_set_fenv_rounding(int i)
{
    return fesetround(i);
}

static int exec_program(char *program)
{
    language_task_t *ct = language_current_task;
    LANGUAGE_TRY {
        language_load(language_main_module, program);
    }
    LANGUAGE_CATCH {
        // TODO: It is possible for this output to be mangled due to `language_print_backtrace`
        //       printing directly to STDERR_FILENO.
        int shown_err = 0;
        language_printf(LANGUAGE_STDERR, "error during bootstrap:\n");
        language_value_t *exc = language_current_exception(ct);
        language_value_t *showf = language_base_module ? language_get_function(language_base_module, "show") : NULL;
        if (showf) {
            language_value_t *errs = language_stderr_obj();
            if (errs) {
                if (language_call2(showf, errs, exc)) {
                    language_printf(LANGUAGE_STDERR, "\n");
                    shown_err = 1;
                }
            }
        }
        if (!shown_err) {
            language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, exc);
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
        }
        language_print_backtrace(); // written to STDERR_FILENO
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
        return 1;
    }
    return 0;
}

static NOINLINE int true_main(int argc, char *argv[])
{
    language_set_ARGS(argc, argv);

    language_function_t *start_client = language_base_module ?
        (language_function_t*)language_get_global(language_base_module, language_symbol("_start")) : NULL;

    language_task_t *ct = language_current_task;
    if (start_client) {
        int ret = 1;
        LANGUAGE_TRY {
            size_t last_age = ct->world_age;
            ct->world_age = language_get_world_counter();
            language_value_t *r = language_apply(&start_client, 1);
            if (language_typeof(r) != (language_value_t*)language_int32_type)
                language_type_error("typeassert", (language_value_t*)language_int32_type, r);
            ret = language_unbox_int32(r);
            ct->world_age = last_age;
        }
        LANGUAGE_CATCH {
            language_no_exc_handler(language_current_exception(ct), ct);
        }
        return ret;
    }

    // run program if specified, otherwise enter REPL
    if (argc > 0) {
        if (strcmp(argv[0], "-")) {
            return exec_program(argv[0]);
        }
    }

    language_printf(LANGUAGE_STDOUT, "WARNING: Base._start not defined, falling back to economy mode repl.\n");
    if (!language_errorexception_type)
        language_printf(LANGUAGE_STDOUT, "WARNING: language_errorexception_type not defined; any errors will be fatal.\n");

    while (!ios_eof(ios_stdin)) {
        char *volatile line = NULL;
        LANGUAGE_TRY {
            ios_puts("\njulia> ", ios_stdout);
            ios_flush(ios_stdout);
            line = ios_readline(ios_stdin);
            language_value_t *val = (language_value_t*)language_eval_string(line);
            LANGUAGE_GC_PUSH1(&val);
            if (language_exception_occurred()) {
                language_printf(LANGUAGE_STDERR, "error during run:\n");
                language_static_show(LANGUAGE_STDERR, language_exception_occurred());
                language_exception_clear();
            }
            else if (val) {
                language_static_show(LANGUAGE_STDOUT, val);
            }
            LANGUAGE_GC_POP();
            language_printf(LANGUAGE_STDOUT, "\n");
            free(line);
            line = NULL;
            language_process_events();
        }
        LANGUAGE_CATCH {
            if (line) {
                free(line);
                line = NULL;
            }
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\nparser error:\n");
            language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
            language_print_backtrace(); // written to STDERR_FILENO
        }
    }
    return 0;
}

static void lock_low32(void)
{
#if defined(_OS_WINDOWS_) && defined(_P64) && defined(LANGUAGE_DEBUG_BUILD)
    // Prevent usage of the 32-bit address space on Win64, to catch pointer cast errors.
    char *const max32addr = (char*)0xffffffffL;
    SYSTEM_INFO info;
    MEMORY_BASIC_INFORMATION meminfo;
    GetNativeSystemInfo(&info);
    memset(&meminfo, 0, sizeof(meminfo));
    meminfo.BaseAddress = info.lpMinimumApplicationAddress;
    while ((char*)meminfo.BaseAddress < max32addr) {
        size_t nbytes = VirtualQuery(meminfo.BaseAddress, &meminfo, sizeof(meminfo));
        assert(nbytes == sizeof(meminfo));
        if (meminfo.State == MEM_FREE) { // reserve all free pages in the first 4GB of memory
            char *first = (char*)meminfo.BaseAddress;
            char *last = first + meminfo.RegionSize;
            if (last > max32addr)
                last = max32addr;
            // adjust first up to the first allocation granularity boundary
            // adjust last down to the last allocation granularity boundary
            first = (char*)(((long long)first + info.dwAllocationGranularity - 1) & ~(info.dwAllocationGranularity - 1));
            last = (char*)((long long)last & ~(info.dwAllocationGranularity - 1));
            if (last != first) {
                void *p = VirtualAlloc(first, last - first, MEM_RESERVE, PAGE_NOACCESS); // reserve all memory in between
                if ((char*)p != first)
                    // Wine and Windows10 seem to have issues with reporting memory access information correctly
                    // so we sometimes end up with unexpected results - this is just ignore those and continue
                    // this is just a debugging aid to help find accidental pointer truncation anyways,
                    // so it is not critical
                    VirtualFree(p, 0, MEM_RELEASE);
            }
        }
        meminfo.BaseAddress = (void*)((char*)meminfo.BaseAddress + meminfo.RegionSize);
    }
#endif
    return;
}

// Actual definition in `ast.c`
void language_lisp_prompt(void);

#ifdef _OS_LINUX_
static void rr_detach_teleport(void) {
#define RR_CALL_BASE 1000
#define SYS_rrcall_detach_teleport (RR_CALL_BASE + 9)
    int err = syscall(SYS_rrcall_detach_teleport, 0, 0, 0, 0, 0, 0);
    if (err < 0 || language_running_under_rr(1)) {
        language_error("Failed to detach from rr session");
    }
}
#endif

/**
 * @brief Entry point for the Julia REPL (Read-Eval-Print Loop).
 *
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return An integer indicating the exit status of the REPL session.
 */
LANGUAGE_DLLEXPORT int language_repl_entrypoint(int argc, char *argv[])
{
#ifdef USE_TRACY
    if (getenv("JULIA_WAIT_FOR_TRACY"))
        while (!TracyCIsConnected) language_cpu_pause(); // Wait for connection
#endif

    // no-op on Windows, note that the caller must have already converted
    // from `wchar_t` to `UTF-8` already if we're running on Windows.
    uv_setup_args(argc, argv);

    // No-op on non-windows
    lock_low32();

    libsupport_init();
    int lisp_prompt = (argc >= 2 && strcmp((char*)argv[1],"--lisp") == 0);
    if (lisp_prompt) {
        memmove(&argv[1], &argv[2], (argc-2)*sizeof(void*));
        argc--;
    }
    char **new_argv = argv;
    language_parse_opts(&argc, (char***)&new_argv);

    // The parent process requested that we detach from the rr session.
    // N.B.: In a perfect world, we would only do this for the portion of
    // the execution where we actually need to exclude rr (e.g. because we're
    // testing for the absence of a memory-model-dependent bug).
    if (language_options.rr_detach && language_running_under_rr(0)) {
#ifdef _OS_LINUX_
        rr_detach_teleport();
        execv("/proc/self/exe", argv);
#endif
        language_error("Failed to self-execute");
    }

    language_init(language_options.image_file_specified ? LANGUAGE_IMAGE_CWD : LANGUAGE_IMAGE_JULIA_HOME);
    if (lisp_prompt) {
        language_current_task->world_age = language_get_world_counter();
        language_lisp_prompt();
        return 0;
    }
    int ret = true_main(argc, (char**)new_argv);
    language_atexit_hook(ret);
    return ret;
}

#ifdef __cplusplus
}
#endif
