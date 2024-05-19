//===--- DependencyScan.h - C API for Lang Dependency Scanning ---*- C -*-===//
//
// This source file is part of the Lang.org open source project
//
// Copyright (c) 2014 - 2020 Apple Inc. and the Lang project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://lang.org/LICENSE.txt for license information
// See https://lang.org/CONTRIBUTORS.txt for the list of Lang project authors
//
//===----------------------------------------------------------------------===//
//
// This C API is primarily intended to serve as the Lang Driver's
// dependency scanning facility (https://github.com/apple/lang-driver).
//
//===----------------------------------------------------------------------===//

#ifndef LANG_C_DEPENDENCY_SCAN_H
#define LANG_C_DEPENDENCY_SCAN_H

#include "DependencyScanMacros.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// The version constants for the LangDependencyScan C API.
/// LANGSCAN_VERSION_MINOR should increase when there are API additions.
/// LANGSCAN_VERSION_MAJOR is intended for "major" source/ABI breaking changes.
#define LANGSCAN_VERSION_MAJOR 0
#define LANGSCAN_VERSION_MINOR 2

LANGSCAN_BEGIN_DECLS

//=== Public Scanner Data Types -------------------------------------------===//

/**
 * A character string used to pass around dependency scan result metadata.
 * Lifetime of the string is strictly tied to the object whose field it
 * represents. When the owning object is released, string memory is freed.
 */
typedef struct {
  const void *data;
  size_t length;
} langscan_string_ref_t;

typedef struct {
  langscan_string_ref_t *strings;
  size_t count;
} langscan_string_set_t;

typedef enum {
  // This dependency info encodes two ModuleDependencyKind types:
  // LangInterface and LangSource.
  LANGSCAN_DEPENDENCY_INFO_LANG_TEXTUAL = 0,
  LANGSCAN_DEPENDENCY_INFO_LANG_BINARY = 1,
  LANGSCAN_DEPENDENCY_INFO_LANG_PLACEHOLDER = 2,
  LANGSCAN_DEPENDENCY_INFO_CLANG = 3
} langscan_dependency_info_kind_t;

/// Opaque container of the details specific to a given module dependency.
typedef struct langscan_module_details_s *langscan_module_details_t;

/// Opaque container to a dependency info of a given module.
typedef struct langscan_dependency_info_s *langscan_dependency_info_t;

/// Opaque container to an overall result of a dependency scan.
typedef struct langscan_dependency_graph_s *langscan_dependency_graph_t;

/// Opaque container to contain the result of a dependency prescan.
typedef struct langscan_import_set_s *langscan_import_set_t;

/// Full Dependency Graph (Result)
typedef struct {
  langscan_dependency_info_t *modules;
  size_t count;
} langscan_dependency_set_t;

//=== Batch Scan Input Specification --------------------------------------===//

/// Opaque container to a container of batch scan entry information.
typedef struct langscan_batch_scan_entry_s *langscan_batch_scan_entry_t;

typedef struct {
  langscan_batch_scan_entry_t *modules;
  size_t count;
} langscan_batch_scan_input_t;

typedef struct {
  langscan_dependency_graph_t *results;
  size_t count;
} langscan_batch_scan_result_t;

//=== Scanner Invocation Specification ------------------------------------===//

/// Opaque container of all relevant context required to launch a dependency
/// scan (command line arguments, working directory, etc.)
typedef struct langscan_scan_invocation_s *langscan_scan_invocation_t;

//=== Dependency Result Functions -----------------------------------------===//

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_dependency_graph_get_main_module_name(
    langscan_dependency_graph_t result);

LANGSCAN_PUBLIC langscan_dependency_set_t *
langscan_dependency_graph_get_dependencies(
    langscan_dependency_graph_t result);

//=== Dependency Module Info Functions ------------------------------------===//

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_module_info_get_module_name(langscan_dependency_info_t info);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_module_info_get_module_path(langscan_dependency_info_t info);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_module_info_get_source_files(langscan_dependency_info_t info);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_module_info_get_direct_dependencies(langscan_dependency_info_t info);

LANGSCAN_PUBLIC langscan_module_details_t
langscan_module_info_get_details(langscan_dependency_info_t info);

//=== Dependency Module Info Details Functions ----------------------------===//

LANGSCAN_PUBLIC langscan_dependency_info_kind_t
langscan_module_detail_get_kind(langscan_module_details_t details);

//=== Lang Textual Module Details query APIs -----------------------------===//
LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_textual_detail_get_module_interface_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_lang_textual_detail_get_compiled_module_candidates(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_textual_detail_get_bridging_header_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_lang_textual_detail_get_bridging_source_files(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_lang_textual_detail_get_bridging_module_dependencies(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_lang_textual_detail_get_command_line(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_lang_textual_detail_get_extra_pcm_args(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_textual_detail_get_context_hash(
    langscan_module_details_t details);

LANGSCAN_PUBLIC bool langscan_lang_textual_detail_get_is_framework(
    langscan_module_details_t details);

//=== Lang Binary Module Details query APIs ------------------------------===//

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_binary_detail_get_compiled_module_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_binary_detail_get_module_doc_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_binary_detail_get_module_source_info_path(
    langscan_module_details_t details);

//=== Lang Placeholder Module Details query APIs -------------------------===//

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_placeholder_detail_get_compiled_module_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_placeholder_detail_get_module_doc_path(
    langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_lang_placeholder_detail_get_module_source_info_path(
    langscan_module_details_t details);

//=== Clang Module Details query APIs -------------------------------------===//

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_clang_detail_get_module_map_path(langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_clang_detail_get_context_hash(langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_clang_detail_get_command_line(langscan_module_details_t details);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_clang_detail_get_captured_pcm_args(langscan_module_details_t details);

//=== Batch Scan Input Functions ------------------------------------------===//

/// Create an \c langscan_batch_scan_input_t instance.
/// The returned \c langscan_batch_scan_input_t is owned by the caller and must be disposed
/// of using \c langscan_batch_scan_input_dispose .
LANGSCAN_PUBLIC langscan_batch_scan_input_t *
langscan_batch_scan_input_create();

LANGSCAN_PUBLIC void
langscan_batch_scan_input_set_modules(langscan_batch_scan_input_t *input,
                                       int count,
                                       langscan_batch_scan_entry_t *modules);

//=== Batch Scan Entry Functions ------------------------------------------===//

/// Create an \c langscan_batch_scan_entry_t instance.
/// The returned \c langscan_batch_scan_entry_t is owned by the caller and must be disposed
/// of using \c langscan_batch_scan_entry_dispose .
LANGSCAN_PUBLIC langscan_batch_scan_entry_t
langscan_batch_scan_entry_create();

LANGSCAN_PUBLIC void
langscan_batch_scan_entry_set_module_name(langscan_batch_scan_entry_t entry,
                                           const char *name);

LANGSCAN_PUBLIC void
langscan_batch_scan_entry_set_arguments(langscan_batch_scan_entry_t entry,
                                         const char *arguments);

LANGSCAN_PUBLIC void
langscan_batch_scan_entry_set_is_lang(langscan_batch_scan_entry_t entry,
                                        bool is_lang);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_batch_scan_entry_get_module_name(langscan_batch_scan_entry_t entry);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_batch_scan_entry_get_arguments(langscan_batch_scan_entry_t entry);

LANGSCAN_PUBLIC bool
langscan_batch_scan_entry_get_is_lang(langscan_batch_scan_entry_t entry);

//=== Prescan Result Functions --------------------------------------------===//

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_import_set_get_imports(langscan_import_set_t result);

//=== Scanner Invocation Functions ----------------------------------------===//

/// Create an \c langscan_scan_invocation_t instance.
/// The returned \c langscan_scan_invocation_t is owned by the caller and must be disposed
/// of using \c langscan_scan_invocation_dispose .
LANGSCAN_PUBLIC langscan_scan_invocation_t langscan_scan_invocation_create();

LANGSCAN_PUBLIC void langscan_scan_invocation_set_working_directory(
    langscan_scan_invocation_t invocation, const char *working_directory);

LANGSCAN_PUBLIC void
langscan_scan_invocation_set_argv(langscan_scan_invocation_t invocation,
                                   int argc, const char **argv);

LANGSCAN_PUBLIC langscan_string_ref_t
langscan_scan_invocation_get_working_directory(
    langscan_scan_invocation_t invocation);

LANGSCAN_PUBLIC int
langscan_scan_invocation_get_argc(langscan_scan_invocation_t invocation);

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_scan_invocation_get_argv(langscan_scan_invocation_t invocation);

//=== Cleanup Functions ---------------------------------------------------===//

LANGSCAN_PUBLIC void
langscan_string_set_dispose(langscan_string_set_t *set);

LANGSCAN_PUBLIC void
langscan_dependency_graph_dispose(langscan_dependency_graph_t result);

LANGSCAN_PUBLIC void
langscan_import_set_dispose(langscan_import_set_t result);

LANGSCAN_PUBLIC void
langscan_batch_scan_entry_dispose(langscan_batch_scan_entry_t entry);

LANGSCAN_PUBLIC void
langscan_batch_scan_input_dispose(langscan_batch_scan_input_t *input);

LANGSCAN_PUBLIC void
langscan_batch_scan_result_dispose(langscan_batch_scan_result_t *result);

LANGSCAN_PUBLIC void
langscan_scan_invocation_dispose(langscan_scan_invocation_t invocation);

//=== Feature-Query Functions -----------------------------------------===//
LANGSCAN_PUBLIC langscan_string_set_t *
langscan_compiler_supported_arguments_query();

LANGSCAN_PUBLIC langscan_string_set_t *
langscan_compiler_supported_features_query();

//=== Scanner Functions ---------------------------------------------------===//

/// Container of the configuration state and shared cache for dependency
/// scanning.
typedef void *langscan_scanner_t;

/// Create an \c langscan_scanner_t instance.
/// The returned \c langscan_scanner_t is owned by the caller and must be disposed
/// of using \c langscan_scanner_dispose .
LANGSCAN_PUBLIC langscan_scanner_t langscan_scanner_create(void);
LANGSCAN_PUBLIC void langscan_scanner_dispose(langscan_scanner_t);

/// Invoke a dependency scan using arguments specified in the \c
/// langscan_scan_invocation_t argument. The returned \c
/// langscan_dependency_graph_t is owned by the caller and must be disposed of
/// using \c langscan_dependency_graph_dispose .
LANGSCAN_PUBLIC langscan_dependency_graph_t langscan_dependency_graph_create(
    langscan_scanner_t scanner, langscan_scan_invocation_t invocation);

/// Invoke the scan for an input batch of modules specified in the
/// \c langscan_batch_scan_input_t argument. The returned
/// \c langscan_batch_scan_result_t is owned by the caller and must be disposed
/// of using \c langscan_batch_scan_result_dispose .
LANGSCAN_PUBLIC langscan_batch_scan_result_t *
langscan_batch_scan_result_create(langscan_scanner_t scanner,
                                   langscan_batch_scan_input_t *batch_input,
                                   langscan_scan_invocation_t invocation);

/// Invoke the import prescan using arguments specified in the \c
/// langscan_scan_invocation_t argument. The returned \c langscan_import_set_t
/// is owned by the caller and must be disposed of using \c
/// langscan_import_set_dispose .
LANGSCAN_PUBLIC langscan_import_set_t langscan_import_set_create(
    langscan_scanner_t scanner, langscan_scan_invocation_t invocation);

//=== Scanner Cache Operations --------------------------------------------===//
// The following operations expose an implementation detail of the dependency
// scanner: its module dependencies cache. This is done in order
// to allow clients to perform incremental dependency scans by having the
// scanner's state be serializable and re-usable.

/// For the specified \c scanner instance, serialize its state to the specified file-system \c path .
LANGSCAN_PUBLIC void
langscan_scanner_cache_serialize(langscan_scanner_t scanner,
                                  const char * path);

/// For the specified \c scanner instance, load in scanner state from a file at
/// the specified file-system \c path .
LANGSCAN_PUBLIC bool
langscan_scanner_cache_load(langscan_scanner_t scanner,
                             const char * path);

/// For the specified \c scanner instance, reset its internal state, ensuring subsequent
/// scanning queries are done "from-scratch".
LANGSCAN_PUBLIC void
langscan_scanner_cache_reset(langscan_scanner_t scanner);

/// An entry point to invoke the compiler via a library call.
LANGSCAN_PUBLIC int invoke_lang_compiler(int argc, const char **argv);

//===----------------------------------------------------------------------===//

LANGSCAN_END_DECLS

#endif // LANG_C_DEPENDENCY_SCAN_H
