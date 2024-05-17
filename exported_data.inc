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

// Pointers that are exposed through the public libjulia
#define LANGUAGE_EXPORTED_DATA_POINTERS(XX) \
    XX(language_abstractarray_type) \
    XX(language_abstractstring_type) \
    XX(language_addrspace_type) \
    XX(language_addrspace_typename) \
    XX(language_addrspacecore_type) \
    XX(language_an_empty_string) \
    XX(language_an_empty_vec_any) \
    XX(language_an_empty_memory_any) \
    XX(language_anytuple_type) \
    XX(language_anytuple_type_type) \
    XX(language_any_type) \
    XX(language_argumenterror_type) \
    XX(language_argument_type) \
    XX(language_array_any_type) \
    XX(language_array_int32_type) \
    XX(language_array_symbol_type) \
    XX(language_array_type) \
    XX(language_array_typename) \
    XX(language_array_uint8_type) \
    XX(language_array_uint32_type) \
    XX(language_array_uint64_type) \
    XX(language_atomicerror_type) \
    XX(language_base_module) \
    XX(language_bool_type) \
    XX(language_bottom_type) \
    XX(language_boundserror_type) \
    XX(language_builtin_type) \
    XX(language_char_type) \
    XX(language_code_info_type) \
    XX(language_code_instance_type) \
    XX(language_const_type) \
    XX(language_core_module) \
    XX(language_datatype_type) \
    XX(language_debuginfo_type) \
    XX(language_densearray_type) \
    XX(language_diverror_exception) \
    XX(language_emptysvec) \
    XX(language_emptytuple) \
    XX(language_emptytuple_type) \
    XX(language_errorexception_type) \
    XX(language_expr_type) \
    XX(language_false) \
    XX(language_float16_type) \
    XX(language_float32_type) \
    XX(language_float64_type) \
    XX(language_bfloat16_type) \
    XX(language_floatingpoint_type) \
    XX(language_function_type) \
    XX(language_binding_type) \
    XX(language_globalref_type) \
    XX(language_gotoifnot_type) \
    XX(language_enternode_type) \
    XX(language_gotonode_type) \
    XX(language_initerror_type) \
    XX(language_int16_type) \
    XX(language_int32_type) \
    XX(language_int64_type) \
    XX(language_int8_type) \
    XX(language_interconditional_type) \
    XX(language_interrupt_exception) \
    XX(language_intrinsic_type) \
    XX(language_kwcall_func) \
    XX(language_lineinfonode_type) \
    XX(language_linenumbernode_type) \
    XX(language_llvmpointer_type) \
    XX(language_llvmpointer_typename) \
    XX(language_loaderror_type) \
    XX(language_main_module) \
    XX(language_memory_any_type) \
    XX(language_memory_exception) \
    XX(language_genericmemory_type) \
    XX(language_genericmemory_typename) \
    XX(language_memory_uint8_type) \
    XX(language_memory_uint16_type) \
    XX(language_memory_uint32_type) \
    XX(language_memory_uint64_type) \
    XX(language_memoryref_any_type) \
    XX(language_genericmemoryref_type) \
    XX(language_genericmemoryref_typename) \
    XX(language_memoryref_uint8_type) \
    XX(language_methoderror_type) \
    XX(language_method_instance_type) \
    XX(language_method_match_type) \
    XX(language_method_type) \
    XX(language_methtable_type) \
    XX(language_missingcodeerror_type) \
    XX(language_module_type) \
    XX(language_n_threads_per_pool) \
    XX(language_namedtuple_type) \
    XX(language_namedtuple_typename) \
    XX(language_newvarnode_type) \
    XX(language_nonfunction_mt) \
    XX(language_nothing) \
    XX(language_nothing_type) \
    XX(language_number_type) \
    XX(language_opaque_closure_type) \
    XX(language_opaque_closure_typename) \
    XX(language_pair_type) \
    XX(language_partial_opaque_type) \
    XX(language_partial_struct_type) \
    XX(language_phicnode_type) \
    XX(language_phinode_type) \
    XX(language_pinode_type) \
    XX(language_pointer_type) \
    XX(language_pointer_typename) \
    XX(language_quotenode_type) \
    XX(language_readonlymemory_exception) \
    XX(language_ref_type) \
    XX(language_returnnode_type) \
    XX(language_signed_type) \
    XX(language_simplevector_type) \
    XX(language_slotnumber_type) \
    XX(language_ssavalue_type) \
    XX(language_stackovf_exception) \
    XX(language_string_type) \
    XX(language_symbol_type) \
    XX(language_task_type) \
    XX(language_top_module) \
    XX(language_true) \
    XX(language_tuple_typename) \
    XX(language_tvar_type) \
    XX(language_typeerror_type) \
    XX(language_typemap_entry_type) \
    XX(language_typemap_level_type) \
    XX(language_typename_type) \
    XX(language_typeofbottom_type) \
    XX(language_type_type) \
    XX(language_type_type_mt) \
    XX(language_type_typename) \
    XX(language_uint16_type) \
    XX(language_uint32_type) \
    XX(language_uint64_type) \
    XX(language_uint8pointer_type) \
    XX(language_uint8_type) \
    XX(language_undefref_exception) \
    XX(language_undefvarerror_type) \
    XX(language_unionall_type) \
    XX(language_uniontype_type) \
    XX(language_upsilonnode_type) \
    XX(language_vararg_type) \
    XX(language_vecelement_typename) \
    XX(language_voidpointer_type) \
    XX(language_void_type) \
    XX(language_weakref_type) \
    XX(language_libdl_module) \
    XX(language_libdl_dlopen_func) \
    XX(language_precompilable_error) \

// Data symbols that are defined inside the public libjulia
#define LANGUAGE_EXPORTED_DATA_SYMBOLS(XX) \
    XX(language_n_threadpools, int) \
    XX(language_n_threads, _Atomic(int)) \
    XX(language_n_gcthreads, int) \
    XX(language_options, language_options_t) \
    XX(language_task_gcstack_offset, int) \
    XX(language_task_ptls_offset, int) \

// end of file
