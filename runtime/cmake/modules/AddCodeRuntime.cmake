include(AddCode)
include(CodeSource)
include(CompatibilityLibs)

function(add_dependencies_multiple_targets)
  cmake_parse_arguments(
      ADMT # prefix
      "" # options
      "" # single-value args
      "TARGETS;DEPENDS" # multi-value args
      ${ARGN})
  precondition(ADMT_UNPARSED_ARGUMENTS NEGATE MESSAGE "unrecognized arguments: ${ADMT_UNPARSED_ARGUMENTS}")

  if(NOT "${ADMT_DEPENDS}" STREQUAL "")
    foreach(target ${ADMT_TARGETS})
      add_dependencies("${target}" ${ADMT_DEPENDS})
    endforeach()
  endif()
endfunction()

# Usage:
# _add_target_variant_c_compile_link_flags(
#   SDK sdk
#   ARCH arch
#   BUILD_TYPE build_type
#   ENABLE_LTO enable_lto
#   ANALYZE_CODE_COVERAGE analyze_code_coverage
#   RESULT_VAR_NAME result_var_name
#   DEPLOYMENT_VERSION_OSX version # If provided, overrides the default value of the OSX deployment target set by the Code project for this compilation only.
#   DEPLOYMENT_VERSION_MACCATALYST version
#   DEPLOYMENT_VERSION_IOS version
#   DEPLOYMENT_VERSION_TVOS version
#   DEPLOYMENT_VERSION_WATCHOS version
#   DEPLOYMENT_VERSION_XROS version
#
# )
function(_add_target_variant_c_compile_link_flags)
  set(oneValueArgs SDK ARCH BUILD_TYPE RESULT_VAR_NAME ENABLE_LTO ANALYZE_CODE_COVERAGE
    DEPLOYMENT_VERSION_OSX DEPLOYMENT_VERSION_MACCATALYST DEPLOYMENT_VERSION_IOS DEPLOYMENT_VERSION_TVOS DEPLOYMENT_VERSION_WATCHOS
    DEPLOYMENT_VERSION_XROS
    MACCATALYST_BUILD_FLAVOR
  )
  cmake_parse_arguments(CFLAGS
    ""
    "${oneValueArgs}"
    ""
    ${ARGN})

  get_maccatalyst_build_flavor(maccatalyst_build_flavor
      "${CFLAGS_SDK}" "${CFLAGS_MACCATALYST_BUILD_FLAVOR}")

  set(result ${${CFLAGS_RESULT_VAR_NAME}})

  if("${CFLAGS_SDK}" IN_LIST CODE_DARWIN_PLATFORMS)
    # Check if there's a specific OS deployment version needed for this invocation
    if("${CFLAGS_SDK}" STREQUAL "OSX")
      if(DEFINED maccatalyst_build_flavor)
        set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_MACCATALYST})
      else()
        set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_OSX})
      endif()
    elseif("${CFLAGS_SDK}" STREQUAL "IOS" OR "${CFLAGS_SDK}" STREQUAL "IOS_SIMULATOR")
      set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_IOS})
    elseif("${CFLAGS_SDK}" STREQUAL "TVOS" OR "${CFLAGS_SDK}" STREQUAL "TVOS_SIMULATOR")
      set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_TVOS})
    elseif("${CFLAGS_SDK}" STREQUAL "WATCHOS" OR "${CFLAGS_SDK}" STREQUAL "WATCHOS_SIMULATOR")
      set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_WATCHOS})
    elseif("${CFLAGS_SDK}" STREQUAL "XROS" OR "${CFLAGS_SDK}" STREQUAL "XROS_SIMULATOR")
      set(DEPLOYMENT_VERSION ${CFLAGS_DEPLOYMENT_VERSION_XROS})
    endif()

    if("${DEPLOYMENT_VERSION}" STREQUAL "")
      set(DEPLOYMENT_VERSION "${CODE_SDK_${CFLAGS_SDK}_DEPLOYMENT_VERSION}")
    endif()
  endif()

  if("${CFLAGS_SDK}" STREQUAL "ANDROID")
    set(DEPLOYMENT_VERSION ${CODE_ANDROID_API_LEVEL})
  endif()

  # MSVC, clang-cl, gcc don't understand -target.
  if(CMAKE_C_COMPILER_ID MATCHES "^Clang|AppleClang$" AND
      NOT CODE_COMPILER_IS_MSVC_LIKE)
    get_target_triple(target target_variant "${CFLAGS_SDK}" "${CFLAGS_ARCH}"
      MACCATALYST_BUILD_FLAVOR "${maccatalyst_build_flavor}"
      DEPLOYMENT_VERSION "${DEPLOYMENT_VERSION}")
    list(APPEND result "-target" "${target}")
    if(target_variant)
      # Check if the C compiler supports `-target-variant` flag
      # TODO (etcwilde): This is a massive hack to deal with the fact that we
      # are lying to cmake about what compiler is being used. Normally we could
      # use `check_compiler_flag(C ...)` here. Unfortunately, that uses a
      # different compiler since we swap out the C/CXX compiler part way through
      # the build.
      file(WRITE "${CMAKE_BINARY_DIR}/runtime/empty" "")
      execute_process(
        COMMAND
          "${CMAKE_C_COMPILER}"
          -Wno-unused-command-line-argument
          -target-variant x86_64-apple-ios14.5-macabi -x c -c - -o /dev/null
        INPUT_FILE
          "${CMAKE_BINARY_DIR}/runtime/empty"
        OUTPUT_QUIET ERROR_QUIET
        RESULT_VARIABLE
          SUPPORTS_TARGET_VARIANT)

      if(NOT SUPPORTS_TARGET_VARIANT)
        list(APPEND result "-target-variant" "${target_variant}")
      else()
        list(APPEND result "-darwin-target-variant" "${target_variant}")
      endif()
    endif()
  endif()

  set(_sysroot "${CODE_SDK_${CFLAGS_SDK}_ARCH_${CFLAGS_ARCH}_PATH}")
  if(CODE_SDK_${CFLAGS_SDK}_USE_ISYSROOT)
    list(APPEND result "-isysroot" "${_sysroot}")
  elseif(NOT CODE_COMPILER_IS_MSVC_LIKE AND NOT "${_sysroot}" STREQUAL "/")
    list(APPEND result "--sysroot=${_sysroot}")
  endif()

  if("${CFLAGS_SDK}" STREQUAL "LINUX_STATIC")
    list(APPEND result "-isystem" "${CODE_MUSL_PATH}/${CFLAGS_ARCH}/usr/include/c++/v1")
    list(APPEND result "-DCODE_LIBC_IS_MUSL")
  endif()


  if("${CFLAGS_SDK}" STREQUAL "ANDROID")
    # Make sure the Android NDK lld is used.
    code_android_tools_path(${CFLAGS_ARCH} tools_path)
    list(APPEND result "-B" "${tools_path}")
  endif()

  if("${CFLAGS_SDK}" IN_LIST CODE_DARWIN_PLATFORMS)
    # We collate -F with the framework path to avoid unwanted deduplication
    # of options by target_compile_options -- this way no undesired
    # side effects are introduced should a new search path be added.
    list(APPEND result
      "-F${CODE_SDK_${CFLAGS_SDK}_PATH}/../../../Developer/Library/Frameworks")
  endif()

  if(CFLAGS_ANALYZE_CODE_COVERAGE)
    list(APPEND result "-fprofile-instr-generate"
                       "-fcoverage-mapping")
  endif()

  # Use frame pointers on Linux
  if("${CFLAGS_SDK}" STREQUAL "LINUX")
    list(APPEND result "-fno-omit-frame-pointer")
  endif()

  _compute_lto_flag("${CFLAGS_ENABLE_LTO}" _lto_flag_out)
  if (_lto_flag_out)
    list(APPEND result "${_lto_flag_out}")
    # Disable opaque pointers in lto mode.
    #list(APPEND result "-Xclang")
    #list(APPEND result "-no-opaque-pointers")
  endif()

  set("${CFLAGS_RESULT_VAR_NAME}" "${result}" PARENT_SCOPE)
endfunction()


function(_add_target_variant_c_compile_flags)
  set(oneValueArgs SDK ARCH BUILD_TYPE ENABLE_ASSERTIONS ANALYZE_CODE_COVERAGE
    DEPLOYMENT_VERSION_OSX DEPLOYMENT_VERSION_MACCATALYST DEPLOYMENT_VERSION_IOS DEPLOYMENT_VERSION_TVOS DEPLOYMENT_VERSION_WATCHOS
    DEPLOYMENT_VERSION_XROS
    RESULT_VAR_NAME ENABLE_LTO
    MACCATALYST_BUILD_FLAVOR)
  cmake_parse_arguments(CFLAGS
    ""
    "${oneValueArgs}"
    ""
    ${ARGN})

  set(result ${${CFLAGS_RESULT_VAR_NAME}})

  list(APPEND result
    "-DCODE_RUNTIME"
    "-DCODE_LIB_SUBDIR=\"${CODE_SDK_${CFLAGS_SDK}_LIB_SUBDIR}\""
    "-DCODE_ARCH=\"${CFLAGS_ARCH}\""
    )

  if ("${CFLAGS_ARCH}" STREQUAL "arm64" OR
      "${CFLAGS_ARCH}" STREQUAL "arm64_32")
    if (CODE_ENABLE_GLOBAL_ISEL_ARM64)
      list(APPEND result "-fglobal-isel")
    endif()
  endif()

  _add_target_variant_c_compile_link_flags(
    SDK "${CFLAGS_SDK}"
    ARCH "${CFLAGS_ARCH}"
    BUILD_TYPE "${CFLAGS_BUILD_TYPE}"
    ENABLE_ASSERTIONS "${CFLAGS_ENABLE_ASSERTIONS}"
    ENABLE_LTO "${CFLAGS_ENABLE_LTO}"
    ANALYZE_CODE_COVERAGE FALSE
    DEPLOYMENT_VERSION_OSX "${CFLAGS_DEPLOYMENT_VERSION_OSX}"
    DEPLOYMENT_VERSION_MACCATALYST "${CFLAGS_DEPLOYMENT_VERSION_MACCATALYST}"
    DEPLOYMENT_VERSION_IOS "${CFLAGS_DEPLOYMENT_VERSION_IOS}"
    DEPLOYMENT_VERSION_TVOS "${CFLAGS_DEPLOYMENT_VERSION_TVOS}"
    DEPLOYMENT_VERSION_WATCHOS "${CFLAGS_DEPLOYMENT_VERSION_WATCHOS}"
    DEPLOYMENT_VERSION_XROS "${CFLAGS_DEPLOYMENT_VERSION_XROS}"
    RESULT_VAR_NAME result
    MACCATALYST_BUILD_FLAVOR "${CFLAGS_MACCATALYST_BUILD_FLAVOR}")

  is_build_type_optimized("${CFLAGS_BUILD_TYPE}" optimized)
  if(optimized)
    if("${CFLAGS_BUILD_TYPE}" STREQUAL "MinSizeRel")
      list(APPEND result "-Os")
    else()
      list(APPEND result "-O2")
    endif()

    # Omit leaf frame pointers on x86 production builds (optimized, no debug
    # info, and no asserts).
    is_build_type_with_debuginfo("${CFLAGS_BUILD_TYPE}" debug)
    if(NOT debug AND NOT CFLAGS_ENABLE_ASSERTIONS)
      if("${CFLAGS_ARCH}" STREQUAL "i386" OR "${CFLAGS_ARCH}" STREQUAL "i686")
        if(NOT CODE_COMPILER_IS_MSVC_LIKE)
          list(APPEND result "-momit-leaf-frame-pointer")
        else()
          list(APPEND result "/Oy")
        endif()
      endif()
    endif()
  else()
    if(NOT CODE_COMPILER_IS_MSVC_LIKE)
      list(APPEND result "-O0")
    else()
      list(APPEND result "/Od")
    endif()
  endif()

  # CMake automatically adds the flags for debug info if we use MSVC/clang-cl.
  if(NOT CODE_COMPILER_IS_MSVC_LIKE)
    is_build_type_with_debuginfo("${CFLAGS_BUILD_TYPE}" debuginfo)
    if(debuginfo)
      _compute_lto_flag("${CFLAGS_ENABLE_LTO}" _lto_flag_out)
      if(_lto_flag_out)
        list(APPEND result "-gline-tables-only")
      else()
        list(APPEND result "-g")
      endif()
    elseif("${CFLAGS_BUILD_TYPE}" STREQUAL "MinSizeRel")
      # MinSizeRel builds of runtime (but not the compiler) should get debug info
      list(APPEND result "-g")
    else()
      list(APPEND result "-g0")
    endif()
  endif()

  if("${CFLAGS_SDK}" STREQUAL "WINDOWS")
    # MSVC/clang-cl don't support -fno-pic or -fms-compatibility-version.
    if(NOT CODE_COMPILER_IS_MSVC_LIKE)
      list(APPEND result -fno-pic)
      list(APPEND result "-fms-compatibility-version=1900")
    endif()

    list(APPEND result "-DLLVM_ON_WIN32")
    list(APPEND result "-D_CRT_SECURE_NO_WARNINGS")
    list(APPEND result "-D_CRT_NONSTDC_NO_WARNINGS")
    list(APPEND result "-D_CRT_USE_BUILTIN_OFFSETOF")
    # TODO(compnerd) permit building for different families
    list(APPEND result "-D_CRT_USE_WINAPI_FAMILY_DESKTOP_APP")
    if("${CFLAGS_ARCH}" MATCHES arm)
      list(APPEND result "-D_ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE")
    endif()
    list(APPEND result "-D_MT")
    # TODO(compnerd) handle /MT
    list(APPEND result "-D_DLL")
    # NOTE: We assume that we are using VS 2015 U2+
    list(APPEND result "-D_ENABLE_ATOMIC_ALIGNMENT_FIX")
    # NOTE: We use over-aligned values for the RefCount side-table
    # (see revision d913eefcc93f8c80d6d1a6de4ea898a2838d8b6f)
    # This is required to build with VS2017 15.8+
    list(APPEND result "-D_ENABLE_EXTENDED_ALIGNED_STORAGE=1")

    # msvcprt's std::function requires RTTI, but we do not want RTTI data.
    # Emulate /GR-.
    # TODO(compnerd) when moving up to VS 2017 15.3 and newer, we can disable
    # RTTI again
    if(CODE_COMPILER_IS_MSVC_LIKE)
      list(APPEND result /GR-)
    else()
      list(APPEND result -frtti)
      list(APPEND result -Xclang;-fno-rtti-data)
    endif()

    # NOTE: VS 2017 15.3 introduced this to disable the static components of
    # RTTI as well.  This requires a newer SDK though and we do not have
    # guarantees on the SDK version currently.
    list(APPEND result "-D_HAS_STATIC_RTTI=0")

    # NOTE(compnerd) workaround LLVM invoking `add_definitions(-D_DEBUG)` which
    # causes failures for the runtime library when cross-compiling due to
    # undefined symbols from the standard library.
    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
      list(APPEND result "-U_DEBUG")
    endif()
  endif()

  # The concurrency library uses double-word atomics.  MSVC's std::atomic
  # uses a spin lock for this, so to get reasonable behavior we have to
  # implement it ourselves using _InterlockedCompareExchange128.
  # clang-cl requires us to enable the `cx16` feature to use this intrinsic.
  if(CFLAGS_ARCH STREQUAL "x86_64")
    if(CODE_COMPILER_IS_MSVC_LIKE)
      list(APPEND result /clang:-mcx16)
    else()
      list(APPEND result -mcx16)
    endif()
  endif()

  if(CFLAGS_ENABLE_ASSERTIONS)
    list(APPEND result "-UNDEBUG")
  else()
    list(APPEND result "-DNDEBUG")
  endif()

  if(CODE_ENABLE_RUNTIME_FUNCTION_COUNTERS)
    list(APPEND result "-DCODE_ENABLE_RUNTIME_FUNCTION_COUNTERS")
  endif()

  if(CFLAGS_ANALYZE_CODE_COVERAGE)
    list(APPEND result "-fprofile-instr-generate"
                       "-fcoverage-mapping")
  endif()

  # Use frame pointers on Linux
  if("${CFLAGS_SDK}" STREQUAL "LINUX")
    list(APPEND result "-fno-omit-frame-pointer")
  endif()

  if((CFLAGS_ARCH STREQUAL "armv7" OR CFLAGS_ARCH STREQUAL "aarch64") AND
     (CFLAGS_SDK STREQUAL "LINUX" OR CFLAGS_SDK STREQUAL "ANDROID"))
     list(APPEND result -funwind-tables)
  endif()

  if("${CFLAGS_SDK}" STREQUAL "LINUX")
    if("${CFLAGS_ARCH}" STREQUAL "x86_64")
      # this is the minimum architecture that supports 16 byte CAS, which is necessary to avoid a dependency to libatomic
      list(APPEND result "-march=core2")
    endif()
  endif()

  if("${CFLAGS_SDK}" STREQUAL "WASI")
    list(APPEND result "-D_WASI_EMULATED_MMAN" "-D_WASI_EMULATED_PROCESS_CLOCKS" "-D_WASI_EMULATED_SIGNAL")
  endif()

  if(NOT CODE_RUNTIME_ENABLE_OBJC_INTEROP)
    list(APPEND result "-DCODE_OBJC_INTEROP=0")
  endif()

  if(CODE_RUNTIME_COMPACT_ABSOLUTE_FUNCTION_POINTER)
    list(APPEND result "-DCODE_COMPACT_ABSOLUTE_FUNCTION_POINTER=1")
  endif()

  if(CODE_RUNTIME_STABLE_ABI)
    list(APPEND result "-DCODE_LIBRARY_EVOLUTION=1")
  else()
    list(APPEND result "-DCODE_LIBRARY_EVOLUTION=0")
  endif()

  if(CODE_RUNTIME_SUPPORT_BACK_DEPLOYMENT)
    list(APPEND result "-DCODE_RUNTIME_SUPPORT_BACK_DEPLOYMENT")
  endif()

  if(CODE_ENABLE_REFLECTION)
    list(APPEND result "-DCODE_ENABLE_REFLECTION")
  endif()

  if(CODE_RUNTIME_HAS_DLADDR)
    list(APPEND result "-DCODE_RUNTIME_HAS_DLADDR")
  endif()

  if(CODE_RUNTIME_HAS_DLSYM)
    list(APPEND result "-DCODE_RUNTIME_HAS_DLSYM=1")
  else()
    list(APPEND result "-DCODE_RUNTIME_HAS_DLSYM=0")
  endif()

  if(CODE_RUNTIME_HAS_FILESYSTEM)
    list(APPEND result "-DCODE_RUNTIME_HAS_FILESYSTEM")
  endif()

  if(CODE_RUNTIME_STATIC_IMAGE_INSPECTION)
    list(APPEND result "-DCODE_RUNTIME_STATIC_IMAGE_INSPECTION")
  endif()

  if(CODE_RUNTIME_HAS_DARWIN_LIBMALLOC)
    list(APPEND result "-DCODE_RUNTIME_HAS_DARWIN_LIBMALLOC=1")
  else()
    list(APPEND result "-DCODE_RUNTIME_HAS_DARWIN_LIBMALLOC=0")
  endif()

  if(CODE_RUNTIME_HAS_ASL)
    list(APPEND result "-DCODE_RUNTIME_HAS_ASL")
  endif()

  if(CODE_RUNTIME_HAS_STDIN)
    list(APPEND result "-DCODE_RUNTIME_HAS_STDIN")
  endif()

  if(CODE_RUNTIME_HAS_ENVIRON)
    list(APPEND result "-DCODE_RUNTIME_HAS_ENVIRON")
  endif()

  if(CODE_RUNTIME_HAS_LOCALE)
    list(APPEND result "-DCODE_RUNTIME_HAS_LOCALE")
  endif()

  if(CODE_RUNTIME_SINGLE_THREADED_CONCURRENCY)
    list(APPEND result "-DCODE_RUNTIME_SINGLE_THREADED_CONCURRENCY")
  endif()

  if(CODE_RUNTIME_TASK_TO_THREAD_MODEL_CONCURRENCY)
    list(APPEND result "-DCODE_RUNTIME_TASK_TO_THREAD_MODEL_CONCURRENCY")
  endif()

  if (CODE_CONCURRENCY_USES_DISPATCH)
    list(APPEND result "-DCODE_CONCURRENCY_USES_DISPATCH")
  endif()

  string(TOUPPER "${CODE_SDK_${CFLAGS_SDK}_THREADING_PACKAGE}" _threading_package)
  list(APPEND result "-DCODE_THREADING_${_threading_package}")

  if(CODE_RUNTIME_OS_VERSIONING)
    list(APPEND result "-DCODE_RUNTIME_OS_VERSIONING")
  endif()

  if(CODE_RUNTIME_PASSTHROUGH_METADATA_ALLOCATOR)
    list(APPEND result "-DCODE_RUNTIME_PASSTHROUGH_METADATA_ALLOCATOR")
  endif()

  if(CODE_RUNTIME_SHORT_MANGLING_LOOKUPS)
    list(APPEND result "-DCODE_RUNTIME_SHORT_MANGLING_LOOKUPS")
  endif()

  if(CODE_RUNTIME_ENABLE_VECTOR_TYPES)
    list(APPEND result "-DCODE_RUNTIME_ENABLE_VECTOR_TYPES")
  endif()

  if(CODE_RUNTIME_HAS_TYPE_PRINTING)
    list(APPEND result "-DCODE_RUNTIME_HAS_TYPE_PRINTING")
  endif()

  if(CODE_RUNTIME_SUPPORTS_BACKTRACE_REPORTING)
    list(APPEND result "-DCODE_RUNTIME_SUPPORTS_BACKTRACE_REPORTING")
  endif()

  if(CODE_RUNTIME_ENABLE_UNICODE_DATA)
    list(APPEND result "-DCODE_RUNTIME_ENABLE_UNICODE_DATA")
  endif()

  if(CODE_RUNTIME_TRACING)
    list(APPEND result "-DCODE_RUNTIME_TRACING")
  endif()

  if(CODE_RUNTIME_CONCURRENCY_TRACING)
    list(APPEND result "-DCODE_RUNTIME_CONCURRENCY_TRACING")
  endif()

  if(CODE_RUNTIME_USE_RELATIVE_PROTOCOL_WITNESS_TABLES)
    list(APPEND result "-DCODE_RUNTIME_USE_RELATIVE_PROTOCOL_WITNESS_TABLES")
  endif()

  if(CODE_RUNTIME_USE_FRAGILE_RESILIENT_PROTOCOL_WITNESS_TABLES)
    list(APPEND result "-DCODE_RUNTIME_USE_FRAGILE_RESILIENT_PROTOCOL_WITNESS_TABLES")
  endif()

  if(CODE_RUNTIME_OVERRIDABLE_RETAIN_RELEASE)
    list(APPEND result "-DCODE_RUNTIME_OVERRIDABLE_RETAIN_RELEASE")
  endif()

  if(CODE_USE_OS_TRACE_LAZY_INIT)
    list(APPEND result "-DCODE_USE_OS_TRACE_LAZY_INIT")
  endif()

  list(APPEND result ${CODE_RUNTIME_EXTRA_C_COMPILE_FLAGS})

  set("${CFLAGS_RESULT_VAR_NAME}" "${result}" PARENT_SCOPE)
endfunction()

function(_add_target_variant_link_flags)
  set(oneValueArgs SDK ARCH BUILD_TYPE ENABLE_ASSERTIONS ANALYZE_CODE_COVERAGE
  DEPLOYMENT_VERSION_OSX DEPLOYMENT_VERSION_MACCATALYST DEPLOYMENT_VERSION_IOS DEPLOYMENT_VERSION_TVOS DEPLOYMENT_VERSION_WATCHOS
  DEPLOYMENT_VERSION_XROS
  RESULT_VAR_NAME ENABLE_LTO LTO_OBJECT_NAME LINK_LIBRARIES_VAR_NAME LIBRARY_SEARCH_DIRECTORIES_VAR_NAME
  MACCATALYST_BUILD_FLAVOR
  )
  cmake_parse_arguments(LFLAGS
    ""
    "${oneValueArgs}"
    ""
    ${ARGN})

  precondition(LFLAGS_SDK MESSAGE "Should specify an SDK")
  precondition(LFLAGS_ARCH MESSAGE "Should specify an architecture")

  set(result ${${LFLAGS_RESULT_VAR_NAME}})
  set(link_libraries ${${LFLAGS_LINK_LIBRARIES_VAR_NAME}})
  set(library_search_directories ${${LFLAGS_LIBRARY_SEARCH_DIRECTORIES_VAR_NAME}})

  _add_target_variant_c_compile_link_flags(
    SDK "${LFLAGS_SDK}"
    ARCH "${LFLAGS_ARCH}"
    BUILD_TYPE "${LFLAGS_BUILD_TYPE}"
    ENABLE_ASSERTIONS "${LFLAGS_ENABLE_ASSERTIONS}"
    ENABLE_LTO "${LFLAGS_ENABLE_LTO}"
    ANALYZE_CODE_COVERAGE "${LFLAGS_ANALYZE_CODE_COVERAGE}"
    DEPLOYMENT_VERSION_OSX "${LFLAGS_DEPLOYMENT_VERSION_OSX}"
    DEPLOYMENT_VERSION_MACCATALYST "${LFLAGS_DEPLOYMENT_VERSION_MACCATALYST}"
    DEPLOYMENT_VERSION_IOS "${LFLAGS_DEPLOYMENT_VERSION_IOS}"
    DEPLOYMENT_VERSION_TVOS "${LFLAGS_DEPLOYMENT_VERSION_TVOS}"
    DEPLOYMENT_VERSION_WATCHOS "${LFLAGS_DEPLOYMENT_VERSION_WATCHOS}"
    DEPLOYMENT_VERSION_XROS "${LFLAGS_DEPLOYMENT_VERSION_XROS}"
    RESULT_VAR_NAME result
    MACCATALYST_BUILD_FLAVOR  "${LFLAGS_MACCATALYST_BUILD_FLAVOR}")
  if("${LFLAGS_SDK}" STREQUAL "LINUX")
    list(APPEND link_libraries "pthread" "dl")
    if("${LFLAGS_ARCH}" MATCHES "armv5|armv6|armv7|i686")
      list(APPEND link_libraries "atomic")
    endif()
  elseif("${LFLAGS_SDK}" STREQUAL "LINUX_STATIC")
    list(APPEND link_libraries "pthread" "dl")
  elseif("${LFLAGS_SDK}" STREQUAL "FREEBSD")
    list(APPEND link_libraries "pthread")
  elseif("${LFLAGS_SDK}" STREQUAL "OPENBSD")
    list(APPEND link_libraries "pthread")
  elseif("${LFLAGS_SDK}" STREQUAL "CYGWIN")
    # No extra libraries required.
  elseif("${LFLAGS_SDK}" STREQUAL "WINDOWS")
    # We don't need to add -noruntime using MSVC or clang-cl, as MSVC and clang-cl rely on auto-linking entirely.
    if(NOT CODE_COMPILER_IS_MSVC_LIKE)
      # NOTE: we do not use "/MD" or "/MDd" and select the runtime via linker
      # options. This causes conflicts.
      list(APPEND result "-noruntime")
    endif()
    if(NOT CMAKE_HOST_SYSTEM MATCHES Windows)
      code_windows_lib_for_arch(${LFLAGS_ARCH} ${LFLAGS_ARCH}_LIB)
      list(APPEND library_search_directories ${${LFLAGS_ARCH}_LIB})
    endif()

    # NOTE(compnerd) workaround incorrectly extensioned import libraries from
    # the Windows SDK on case sensitive file systems.
    list(APPEND library_search_directories
         ${CMAKE_BINARY_DIR}/winsdk_lib_${LFLAGS_ARCH}_symlinks)
  elseif("${LFLAGS_SDK}" STREQUAL "HAIKU")
    list(APPEND link_libraries "bsd")
    list(APPEND result "-Wl,-Bsymbolic")
  elseif("${LFLAGS_SDK}" STREQUAL "ANDROID")
    list(APPEND link_libraries "dl" "log")
    # We need to add the math library, which is linked implicitly by libc++
    list(APPEND result "-lm")
    if(NOT "${CODE_ANDROID_NDK_PATH}" STREQUAL "")
      if("${CODE_ANDROID_NDK_PATH}" MATCHES "r26")
        file(GLOB RESOURCE_DIR ${CODE_SDK_ANDROID_ARCH_${LFLAGS_ARCH}_PATH}/../lib/clang/*)
      else()
        file(GLOB RESOURCE_DIR ${CODE_SDK_ANDROID_ARCH_${LFLAGS_ARCH}_PATH}/../lib64/clang/*)
      endif()
      list(APPEND result "-resource-dir=${RESOURCE_DIR}")
    endif()

    # link against the custom C++ library
    code_android_cxx_libraries_for_arch(${LFLAGS_ARCH} cxx_link_libraries)
    list(APPEND link_libraries ${cxx_link_libraries})
  else()
    # If lto is enabled, we need to add the object path flag so that the LTO code
    # generator leaves the intermediate object file in a place where it will not
    # be touched. The reason why this must be done is that on OS X, debug info is
    # left in object files. So if the object file is removed when we go to
    # generate a dsym, the debug info is gone.
    if (LFLAGS_ENABLE_LTO)
      precondition(LFLAGS_LTO_OBJECT_NAME
        MESSAGE "Should specify a unique name for the lto object")
      set(lto_object_dir ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR})
      set(lto_object ${lto_object_dir}/${LFLAGS_LTO_OBJECT_NAME}-lto.o)
        list(APPEND result "-Wl,-object_path_lto,${lto_object}")
      endif()
  endif()

  if(CODE_USE_LINKER AND NOT CODE_COMPILER_IS_MSVC_LIKE)
    # The linker is normally chosen based on the host, but the Android NDK only
    # uses lld now.
    if("${LFLAGS_SDK}" STREQUAL "ANDROID")
      set(linker "lld")
    else()
      set(linker "${CODE_USE_LINKER}")
    endif()
    if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
      list(APPEND result "-fuse-ld=${linker}.exe")
    else()
      list(APPEND result "-fuse-ld=${linker}")
    endif()
  endif()

  # Enable dead stripping. Portions of this logic were copied from llvm's
  # `add_link_opts` function (which, perhaps, should have been used here in the
  # first place, but at this point it's hard to say whether that's feasible).
  #
  # TODO: Evaluate/enable -f{function,data}-sections --gc-sections for bfd,
  # gold, and lld.
  if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
      # See rdar://48283130: This gives 6MB+ size reductions for code and
      # SourceKitService, and much larger size reductions for sil-opt etc.
      list(APPEND result "-Wl,-dead_strip")
    endif()
  endif()

  get_maccatalyst_build_flavor(maccatalyst_build_flavor
    "${LFLAGS_SDK}" "${LFLAGS_MACCATALYST_BUILD_FLAVOR}")

  set("${LFLAGS_RESULT_VAR_NAME}" "${result}" PARENT_SCOPE)
  set("${LFLAGS_LINK_LIBRARIES_VAR_NAME}" "${link_libraries}" PARENT_SCOPE)
  set("${LFLAGS_LIBRARY_SEARCH_DIRECTORIES_VAR_NAME}" "${library_search_directories}" PARENT_SCOPE)
endfunction()

# Add a universal binary target created from the output of the given
# set of targets by running 'lipo'.
#
# Usage:
#   _add_code_lipo_target(
#     sdk                 # The name of the SDK the target was created for.
#                         # Examples include "OSX", "IOS", "ANDROID", etc.
#     target              # The name of the target to create
#     output              # The file to be created by this target
#     source_targets...   # The source targets whose outputs will be
#                         # lipo'd into the output.
#   )
function(_add_code_lipo_target)
  cmake_parse_arguments(
    LIPO                # prefix
    "CODESIGN"          # options
    "SDK;TARGET;OUTPUT" # single-value args
    ""                  # multi-value args
    ${ARGN})

  precondition(LIPO_SDK MESSAGE "sdk is required")
  precondition(LIPO_TARGET MESSAGE "target is required")
  precondition(LIPO_OUTPUT MESSAGE "output is required")
  precondition(LIPO_UNPARSED_ARGUMENTS MESSAGE "one or more inputs are required")

  set(source_targets ${LIPO_UNPARSED_ARGUMENTS})

  # Gather the source binaries.
  set(source_binaries)
  foreach(source_target ${source_targets})
    list(APPEND source_binaries $<TARGET_FILE:${source_target}>)
  endforeach()

  if("${CODE_SDK_${LIPO_SDK}_OBJECT_FORMAT}" STREQUAL "MACHO")
    if(LIPO_CODESIGN)
      set(codesign_command COMMAND "codesign" "-f" "-s" "-" "${LIPO_OUTPUT}")
    endif()

    set(lipo_lto_env)
    # When lipo-ing LTO-based libraries with lipo on Darwin, the tool uses
    # libLTO.dylib to inspect the bitcode files. However, by default the "host"
    # libLTO.dylib is loaded, which might be too old and not understand the
    # just-built bitcode format. Let's ask lipo to use the just-built
    # libLTO.dylib from the toolchain that we're using to build.
    if(APPLE AND CODE_NATIVE_CLANG_TOOLS_PATH)
      set(lipo_lto_env "LIBLTO_PATH=${CODE_NATIVE_CLANG_TOOLS_PATH}/../lib/libLTO.dylib")
    endif()

    # Use lipo to create the final binary.
    add_custom_command_target(unused_var
        COMMAND "${CMAKE_COMMAND}" "-E" "env" ${lipo_lto_env} "${CODE_LIPO}" "-create" "-output" "${LIPO_OUTPUT}" ${source_binaries}
        ${codesign_command}
        CUSTOM_TARGET_NAME "${LIPO_TARGET}"
        OUTPUT "${LIPO_OUTPUT}"
        DEPENDS ${source_targets})
  else()
    # We don't know how to create fat binaries for other platforms.
    add_custom_command_target(unused_var
        COMMAND "${CMAKE_COMMAND}" "-E" "copy" "${source_binaries}" "${LIPO_OUTPUT}"
        CUSTOM_TARGET_NAME "${LIPO_TARGET}"
        OUTPUT "${LIPO_OUTPUT}"
        DEPENDS ${source_targets})
  endif()
endfunction()
 
# Add a single variant of a new Code library.
#
# Usage:
#   add_code_target_library_single(
#     target
#     name
#     [MODULE_TARGETS]
#     [SHARED]
#     [STATIC]
#     [SDK sdk]
#     [ARCHITECTURE architecture]
#     [DEPENDS dep1 ...]
#     [LINK_LIBRARIES dep1 ...]
#     [FRAMEWORK_DEPENDS dep1 ...]
#     [FRAMEWORK_DEPENDS_WEAK dep1 ...]
#     [C_COMPILE_FLAGS flag1...]
#     [CODE_COMPILE_FLAGS flag1...]
#     [LINK_FLAGS flag1...]
#     [FILE_DEPENDS target1 ...]
#     [DONT_EMBED_BITCODE]
#     [IS_STDLIB]
#     [IS_RUNTIME_CORE]
#     [IS_SDK_OVERLAY]
#     [IS_FRAGILE]
#     INSTALL_IN_COMPONENT comp
#     MACCATALYST_BUILD_FLAVOR flavor
#     source1 [source2 source3 ...])
#
# target
#   Name of the target (e.g., codeParse-IOS-armv7).
#
# name
#   Name of the library (e.g., codeParse).
#
# MODULE_TARGETS
#   Names of the module target (e.g., codeParse-codemodule-IOS-armv7).
#
# SHARED
#   Build a shared library.
#
# STATIC
#   Build a static library.
#
# ONLY_CODEMODULE
#   Do not build either static or shared, build just the .codemodule.
#
# SDK sdk
#   SDK to build for.
#
# ARCHITECTURE
#   Architecture to build for.
#
# DEPENDS
#   Targets that this library depends on.
#
# LINK_LIBRARIES
#   Libraries this library depends on.
#
# FRAMEWORK_DEPENDS
#   System frameworks this library depends on.
#
# FRAMEWORK_DEPENDS_WEAK
#   System frameworks this library depends on that should be weakly-linked.
#
# C_COMPILE_FLAGS
#   Extra compile flags (C, C++, ObjC).
#
# CODE_COMPILE_FLAGS
#   Extra compile flags (Code).
#
# LINK_FLAGS
#   Extra linker flags.
#
# FILE_DEPENDS
#   Additional files this library depends on.
#
# DONT_EMBED_BITCODE
#   Don't embed LLVM bitcode in this target, even if it is enabled globally.
#
# IS_STDLIB
#   Install library dylib and code module files to lib/code.
#
# IS_RUNTIME_CORE
#   Compile as the standard library core.
#
# IS_SDK_OVERLAY
#   Treat the library as a part of the Code SDK overlay.
#
# INSTALL_IN_COMPONENT comp
#   The Code installation component that this library belongs to.
#
# MACCATALYST_BUILD_FLAVOR
#   Possible values are 'ios-like', 'macos-like', 'zippered', 'unzippered-twin'

# IS_FRAGILE
#   Disable library evolution even
#   if this library is part of the SDK.

#
# source1 ...
#   Sources to add into this library
function(add_code_target_library_single target name)
  set(CODELIB_SINGLE_options
        DONT_EMBED_BITCODE
        IS_SDK_OVERLAY
        IS_STDLIB
        IS_RUNTIME_CORE
        NOCODERT
        OBJECT_LIBRARY
        SHARED
        STATIC
        ONLY_CODEMODULE
        NO_LINK_NAME
        INSTALL_WITH_SHARED
        IS_FRAGILE)
  set(CODELIB_SINGLE_single_parameter_options
        ARCHITECTURE
        DEPLOYMENT_VERSION_IOS
        DEPLOYMENT_VERSION_OSX
        DEPLOYMENT_VERSION_TVOS
        DEPLOYMENT_VERSION_WATCHOS
        DEPLOYMENT_VERSION_XROS
        INSTALL_IN_COMPONENT
        DARWIN_INSTALL_NAME_DIR
        SDK
        DEPLOYMENT_VERSION_MACCATALYST
        MACCATALYST_BUILD_FLAVOR
        BACK_DEPLOYMENT_LIBRARY
        ENABLE_LTO
        MODULE_DIR
        BOOTSTRAPPING
        INSTALL_BINARY_CODEMODULE)
  set(CODELIB_SINGLE_multiple_parameter_options
        C_COMPILE_FLAGS
        DEPENDS
        FILE_DEPENDS
        FRAMEWORK_DEPENDS
        FRAMEWORK_DEPENDS_WEAK
        GYB_SOURCES
        INCORPORATE_OBJECT_LIBRARIES
        INCORPORATE_OBJECT_LIBRARIES_SHARED_ONLY
        LINK_FLAGS
        LINK_LIBRARIES
        PRIVATE_LINK_LIBRARIES
        PREFIX_INCLUDE_DIRS
        CODE_COMPILE_FLAGS
        MODULE_TARGETS)

  cmake_parse_arguments(CODELIB_SINGLE
                        "${CODELIB_SINGLE_options}"
                        "${CODELIB_SINGLE_single_parameter_options}"
                        "${CODELIB_SINGLE_multiple_parameter_options}"
                        ${ARGN})

  translate_flag(${CODELIB_SINGLE_STATIC} "STATIC"
                 CODELIB_SINGLE_STATIC_keyword)
  translate_flag(${CODELIB_SINGLE_NO_LINK_NAME} "NO_LINK_NAME"
                 CODELIB_SINGLE_NO_LINK_NAME_keyword)
  if(DEFINED CODELIB_SINGLE_BOOTSTRAPPING)
    set(BOOTSTRAPPING_arg "BOOTSTRAPPING" ${CODELIB_SINGLE_BOOTSTRAPPING})
  endif()

  get_bootstrapping_path(out_bin_dir
      ${CODE_RUNTIME_OUTPUT_INTDIR} "${CODELIB_SINGLE_BOOTSTRAPPING}")
  get_bootstrapping_path(out_lib_dir
      ${CODE_LIBRARY_OUTPUT_INTDIR} "${CODELIB_SINGLE_BOOTSTRAPPING}")
  get_bootstrapping_path(lib_dir
      ${CODELIB_DIR} "${CODELIB_SINGLE_BOOTSTRAPPING}")
  get_bootstrapping_path(static_lib_dir
      ${CODESTATICLIB_DIR} "${CODELIB_SINGLE_BOOTSTRAPPING}")

  # Determine macCatalyst build flavor
  get_maccatalyst_build_flavor(maccatalyst_build_flavor
    "${CODELIB_SINGLE_SDK}" "${CODELIB_SINGLE_MACCATALYST_BUILD_FLAVOR}")

  set(CODELIB_SINGLE_SOURCES ${CODELIB_SINGLE_UNPARSED_ARGUMENTS})

  translate_flags(CODELIB_SINGLE "${CODELIB_SINGLE_options}")

  # Check arguments.
  precondition(CODELIB_SINGLE_SDK MESSAGE "Should specify an SDK")
  precondition(CODELIB_SINGLE_ARCHITECTURE MESSAGE "Should specify an architecture")
  precondition(CODELIB_SINGLE_INSTALL_IN_COMPONENT MESSAGE "INSTALL_IN_COMPONENT is required")

  if(NOT CODELIB_SINGLE_SHARED AND
     NOT CODELIB_SINGLE_STATIC AND
     NOT CODELIB_SINGLE_OBJECT_LIBRARY AND
     NOT CODELIB_SINGLE_ONLY_CODEMODULE)
    message(FATAL_ERROR
        "Either SHARED, STATIC, or OBJECT_LIBRARY must be specified")
  endif()

  if(NOT DEFINED CODELIB_INSTALL_BINARY_CODEMODULE)
    set(CODELIB_INSTALL_BINARY_CODEMODULE TRUE)
  endif()

  # Determine the subdirectory where this library will be installed.
  set(CODELIB_SINGLE_SUBDIR
      "${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}/${CODELIB_SINGLE_ARCHITECTURE}")

  # macCatalyst ios-like builds are installed in the maccatalyst/x86_64 directory
  if(maccatalyst_build_flavor STREQUAL "ios-like")
    set(CODELIB_SINGLE_SUBDIR
        "${CODE_SDK_MACCATALYST_LIB_SUBDIR}/${CODELIB_SINGLE_ARCHITECTURE}")
  endif()

  if ("${CODELIB_SINGLE_BOOTSTRAPPING}" STREQUAL "")
    set(output_sub_dir ${CODELIB_SINGLE_SUBDIR})
  else()
    # In the bootstrapping builds, we only have the single host architecture.
    # So generated the library directly in the parent SDK specific directory
    # (avoiding to lipo/copy the library).
    set(output_sub_dir ${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR})
  endif()

  # Include LLVM Bitcode slices for iOS, Watch OS, and Apple TV OS device libraries.
  set(embed_bitcode_arg)
  if(CODE_EMBED_BITCODE_SECTION AND NOT CODELIB_SINGLE_DONT_EMBED_BITCODE)
    if("${CODELIB_SINGLE_SDK}" STREQUAL "IOS" OR
       "${CODELIB_SINGLE_SDK}" STREQUAL "TVOS" OR
       "${CODELIB_SINGLE_SDK}" STREQUAL "XROS" OR
       "${CODELIB_SINGLE_SDK}" STREQUAL "WATCHOS")
      list(APPEND CODELIB_SINGLE_C_COMPILE_FLAGS "-fembed-bitcode")
      set(embed_bitcode_arg EMBED_BITCODE)
    endif()
  endif()

  if(XCODE)
    string(REGEX MATCHALL "/[^/]+" split_path ${CMAKE_CURRENT_SOURCE_DIR})
    list(GET split_path -1 dir)
    file(GLOB_RECURSE CODELIB_SINGLE_HEADERS
      ${CODE_SOURCE_DIR}/include/code${dir}/*.h
      ${CODE_SOURCE_DIR}/include/code${dir}/*.def
      ${CMAKE_CURRENT_SOURCE_DIR}/*.def)

    file(GLOB_RECURSE CODELIB_SINGLE_TDS
      ${CODE_SOURCE_DIR}/include/code${dir}/*.td)

    set_source_files_properties(${CODELIB_SINGLE_HEADERS} ${CODELIB_SINGLE_TDS}
      PROPERTIES
      HEADER_FILE_ONLY true)
    source_group("TableGen descriptions" FILES ${CODELIB_SINGLE_TDS})

    set(CODELIB_SINGLE_SOURCES ${CODELIB_SINGLE_SOURCES} ${CODELIB_SINGLE_HEADERS} ${CODELIB_SINGLE_TDS})
  endif()

  if(MODULE)
    set(libkind MODULE)
  elseif(CODELIB_SINGLE_OBJECT_LIBRARY)
    set(libkind OBJECT)
  # If both SHARED and STATIC are specified, we add the SHARED library first.
  # The STATIC library is handled further below.
  elseif(CODELIB_SINGLE_SHARED)
    set(libkind SHARED)
  elseif(CODELIB_SINGLE_STATIC)
    set(libkind STATIC)
  elseif(CODELIB_SINGLE_ONLY_CODEMODULE)
    set(libkind NONE)
  else()
    message(FATAL_ERROR
        "Either SHARED, STATIC, or OBJECT_LIBRARY must be specified")
  endif()

  if(CODELIB_SINGLE_GYB_SOURCES)
    handle_gyb_sources(
        gyb_dependency_targets
        CODELIB_SINGLE_GYB_SOURCES
        ARCH "${CODELIB_SINGLE_ARCHITECTURE}")
    set(CODELIB_SINGLE_SOURCES ${CODELIB_SINGLE_SOURCES}
      ${CODELIB_SINGLE_GYB_SOURCES})
  endif()

  # Remove the "code" prefix from the name to determine the module name.
  if(CODELIB_SINGLE_IS_RUNTIME_CORE)
    set(module_name "Code")
  else()
    string(REPLACE code "" module_name "${name}")
  endif()

  if("${CODELIB_SINGLE_SDK}" STREQUAL "WINDOWS")
    if(NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
      code_windows_get_sdk_vfs_overlay(CODELIB_SINGLE_VFS_OVERLAY)
      list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS
        -Xcc;-Xclang;-Xcc;-ivfsoverlay;-Xcc;-Xclang;-Xcc;${CODELIB_SINGLE_VFS_OVERLAY})
    endif()
    list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS
      -vfsoverlay;"${CODE_WINDOWS_VFS_OVERLAY}";-strict-implicit-module-context;-Xcc;-Xclang;-Xcc;-fbuiltin-headers-in-system-modules)
    if(NOT CMAKE_HOST_SYSTEM MATCHES Windows)
      code_windows_include_for_arch(${CODELIB_SINGLE_ARCHITECTURE} CODELIB_INCLUDE)
      foreach(directory ${CODELIB_INCLUDE})
        list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS -Xcc;-isystem;-Xcc;${directory})
      endforeach()
    endif()
    if("${CODELIB_SINGLE_ARCHITECTURE}" MATCHES arm)
      list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS -Xcc;-D_ARM_WINAPI_PARTITION_DESKTOP_SDK_AVAILABLE)
    endif()
    list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS
      -libc;${CODE_RUNTIME_MSVC_RUNTIME_LIBRARY})
  endif()

  # Define availability macros.
  foreach(def ${CODE_RUNTIME_AVAILABILITY_DEFINITIONS})
    list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS "-Xfrontend" "-define-availability" "-Xfrontend" "${def}")
  endforeach()

  # Enable -target-min-inlining-version
  list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS "-Xfrontend" "-target-min-inlining-version" "-Xfrontend" "min")

  # Don't install the Code module content for back-deployment libraries.
  if (CODELIB_SINGLE_BACK_DEPLOYMENT_LIBRARY)
    set(install_in_component "never_install")
  else()
    set(install_in_component "${CODELIB_SINGLE_INSTALL_IN_COMPONENT}")
  endif()

  # Use frame pointers on Linux
  if ("${CODELIB_SINGLE_SDK}" STREQUAL "LINUX")
    list(APPEND CODELIB_SINGLE_CODE_COMPILE_FLAGS "-Xcc" "-fno-omit-frame-pointer")
  endif()

  # FIXME: don't actually depend on the libraries in CODELIB_SINGLE_LINK_LIBRARIES,
  # just any codemodule files that are associated with them.
  handle_code_sources(
      code_object_dependency_target
      code_module_dependency_target
      code_sib_dependency_target
      code_sibopt_dependency_target
      code_sibgen_dependency_target
      CODELIB_SINGLE_SOURCES
      CODELIB_SINGLE_EXTERNAL_SOURCES ${name}
      DEPENDS
        ${gyb_dependency_targets}
        ${CODELIB_SINGLE_DEPENDS}
        ${CODELIB_SINGLE_FILE_DEPENDS}
        ${CODELIB_SINGLE_LINK_LIBRARIES}
      SDK ${CODELIB_SINGLE_SDK}
      ARCHITECTURE ${CODELIB_SINGLE_ARCHITECTURE}
      MODULE_NAME ${module_name}
      MODULE_DIR ${CODELIB_SINGLE_MODULE_DIR}
      COMPILE_FLAGS ${CODELIB_SINGLE_CODE_COMPILE_FLAGS}
      ${CODELIB_SINGLE_IS_RUNTIME_keyword}
      ${CODELIB_SINGLE_IS_RUNTIME_CORE_keyword}
      ${CODELIB_SINGLE_IS_SDK_OVERLAY_keyword}
      ${CODELIB_SINGLE_IS_FRAGILE_keyword}
      ${CODELIB_SINGLE_ONLY_CODEMODULE_keyword}
      ${embed_bitcode_arg}
      ${CODELIB_SINGLE_STATIC_keyword}
      ${CODELIB_SINGLE_NO_LINK_NAME_keyword}
      ENABLE_LTO "${CODELIB_SINGLE_ENABLE_LTO}"
      INSTALL_IN_COMPONENT "${install_in_component}"
      DEPLOYMENT_VERSION_OSX ${CODELIB_SINGLE_DEPLOYMENT_VERSION_OSX}
      DEPLOYMENT_VERSION_IOS ${CODELIB_SINGLE_DEPLOYMENT_VERSION_IOS}
      DEPLOYMENT_VERSION_TVOS ${CODELIB_SINGLE_DEPLOYMENT_VERSION_TVOS}
      DEPLOYMENT_VERSION_WATCHOS ${CODELIB_SINGLE_DEPLOYMENT_VERSION_WATCHOS}
      MACCATALYST_BUILD_FLAVOR "${CODELIB_SINGLE_MACCATALYST_BUILD_FLAVOR}"
      ${BOOTSTRAPPING_arg}
      INSTALL_BINARY_CODEMODULE ${CODELIB_INSTALL_BINARY_CODEMODULE})
  add_code_source_group("${CODELIB_SINGLE_EXTERNAL_SOURCES}")

  # If there were any code sources, then a .codemodule may have been created.
  # If that is the case, then add a target which is an alias of the module files.
  set(VARIANT_SUFFIX "-${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}-${CODELIB_SINGLE_ARCHITECTURE}")
  if(maccatalyst_build_flavor STREQUAL "ios-like")
    set(VARIANT_SUFFIX "-${CODE_SDK_MACCATALYST_LIB_SUBDIR}-${CODELIB_SINGLE_ARCHITECTURE}")
  endif()

  if(NOT "${CODELIB_SINGLE_MODULE_TARGETS}" STREQUAL "" AND NOT "${code_module_dependency_target}" STREQUAL "")
    foreach(module_target ${CODELIB_SINGLE_MODULE_TARGETS})
      add_custom_target("${module_target}"
        DEPENDS ${code_module_dependency_target})
      set_target_properties("${module_target}" PROPERTIES
        FOLDER "Code libraries/Modules")
    endforeach()
  endif()

  # For standalone overlay builds to work
  if(NOT BUILD_STANDALONE AND "${CODELIB_SINGLE_BOOTSTRAPPING}" STREQUAL "")
    if (EXISTS code_sib_dependency_target AND NOT "${code_sib_dependency_target}" STREQUAL "")
      add_dependencies(code-runtime${VARIANT_SUFFIX}-sib ${code_sib_dependency_target})
    endif()

    if (EXISTS code_sibopt_dependency_target AND NOT "${code_sibopt_dependency_target}" STREQUAL "")
      add_dependencies(code-runtime${VARIANT_SUFFIX}-sibopt ${code_sibopt_dependency_target})
    endif()

    if (EXISTS code_sibgen_dependency_target AND NOT "${code_sibgen_dependency_target}" STREQUAL "")
      add_dependencies(code-runtime${VARIANT_SUFFIX}-sibgen ${code_sibgen_dependency_target})
    endif()
  endif()

  # Only build the modules for any arch listed in the *_MODULE_ARCHITECTURES.
  if(CODELIB_SINGLE_SDK IN_LIST CODE_DARWIN_PLATFORMS
      AND CODELIB_SINGLE_ARCHITECTURE IN_LIST CODE_SDK_${CODELIB_SINGLE_SDK}_MODULE_ARCHITECTURES)
    # Create dummy target to hook up the module target dependency.
    add_custom_target("${target}"
      DEPENDS
        "${code_module_dependency_target}")
    if(TARGET "${install_in_component}")
      add_dependencies("${install_in_component}" "${target}")
    endif()

    return()
  endif()

  set(CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS)
  foreach(object_library ${CODELIB_SINGLE_INCORPORATE_OBJECT_LIBRARIES})
    list(APPEND CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS
        $<TARGET_OBJECTS:${object_library}${VARIANT_SUFFIX}>)
  endforeach()

  set(CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS_SHARED_ONLY)
  foreach(object_library ${CODELIB_SINGLE_INCORPORATE_OBJECT_LIBRARIES_SHARED_ONLY})
    list(APPEND CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS_SHARED_ONLY
        $<TARGET_OBJECTS:${object_library}${VARIANT_SUFFIX}>)
  endforeach()

  set(CODELIB_SINGLE_XCODE_WORKAROUND_SOURCES)
  if(XCODE)
    set(CODELIB_SINGLE_XCODE_WORKAROUND_SOURCES
        # Note: the dummy.cpp source file provides no definitions. However,
        # it forces Xcode to properly link the static library.
        ${CODE_SOURCE_DIR}/cmake/dummy.cpp)
  endif()

  set(INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS ${CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS})
  if(libkind STREQUAL "SHARED")
    list(APPEND INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS
         ${CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS_SHARED_ONLY})
  endif()

  if (CODELIB_SINGLE_ONLY_CODEMODULE)
    add_custom_target("${target}"
      DEPENDS "${code_module_dependency_target}")
    if(TARGET "${install_in_component}")
      add_dependencies("${install_in_component}" "${target}")
    endif()
    return()
  endif()

  add_library("${target}" ${libkind}
              ${CODELIB_SINGLE_SOURCES}
              ${CODELIB_SINGLE_EXTERNAL_SOURCES}
              ${INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS}
              ${CODELIB_SINGLE_XCODE_WORKAROUND_SOURCES})
  if (NOT CODELIB_SINGLE_OBJECT_LIBRARY AND TARGET "${install_in_component}")
    add_dependencies("${install_in_component}" "${target}")
  endif()
  # NOTE: always inject the LLVMSupport directory before anything else.  We want
  # to ensure that the runtime is built with our local copy of LLVMSupport
  target_include_directories(${target} BEFORE PRIVATE
    ${CODE_SOURCE_DIR}/runtime/include)
  target_include_directories(${target} BEFORE PRIVATE
    ${CODELIB_SINGLE_PREFIX_INCLUDE_DIRS})
  if(("${CODE_SDK_${CODELIB_SINGLE_SDK}_OBJECT_FORMAT}" STREQUAL "ELF" OR
      "${CODE_SDK_${CODELIB_SINGLE_SDK}_OBJECT_FORMAT}" STREQUAL "COFF"))
    if("${libkind}" STREQUAL "SHARED" AND NOT CODELIB_SINGLE_NOCODERT)
      # TODO(compnerd) switch to the generator expression when cmake is upgraded
      # to a version which supports it.
      # target_sources(${target}
      #                PRIVATE
      #                  $<TARGET_OBJECTS:codeImageRegistrationObject${CODE_SDK_${CODELIB_SINGLE_SDK}_OBJECT_FORMAT}-${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}-${CODELIB_SINGLE_ARCHITECTURE}>)
      if(CODELIB_SINGLE_SDK STREQUAL "WINDOWS")
        set(extension .obj)
      else()
        set(extension .o)
      endif()
      target_sources(${target}
                     PRIVATE
                       "${CODELIB_DIR}/${CODELIB_SINGLE_SUBDIR}/codert${extension}")
      set_source_files_properties("${CODELIB_DIR}/${CODELIB_SINGLE_SUBDIR}/codert${extension}"
                                  PROPERTIES
                                    GENERATED 1)
    endif()
  endif()
  _set_target_prefix_and_suffix("${target}" "${libkind}" "${CODELIB_SINGLE_SDK}")

  # Target libraries that include libDemangling must define the name to use for
  # the inline namespace to distinguish symbols from those built for the
  # compiler, in order to avoid possible ODR violations if both are statically
  # linked into the same binary.
  target_compile_definitions("${target}" PRIVATE
                             CODE_INLINE_NAMESPACE=__runtime)

  if("${CODELIB_SINGLE_SDK}" STREQUAL "WINDOWS")
    if(NOT CMAKE_HOST_SYSTEM MATCHES Windows)
      code_windows_include_for_arch(${CODELIB_SINGLE_ARCHITECTURE} CODELIB_INCLUDE)
      target_include_directories("${target}" SYSTEM PRIVATE
        ${CODELIB_INCLUDE})
    endif()
    if(libkind STREQUAL STATIC)
      set_property(TARGET "${target}" PROPERTY
        PREFIX lib)
    endif()
  endif()

  if("${CODELIB_SINGLE_SDK}" STREQUAL "WINDOWS" AND NOT "${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    if("${libkind}" STREQUAL "SHARED")
      # Each dll has an associated .lib (import library); since we may be
      # building on a non-DLL platform (not windows), create an imported target
      # for the library which created implicitly by the dll.
      add_custom_command_target(${target}_IMPORT_LIBRARY
                                OUTPUT "${CODELIB_DIR}/${CODELIB_SINGLE_SUBDIR}/${name}.lib"
                                DEPENDS "${target}")
      add_library(${target}_IMPLIB SHARED IMPORTED GLOBAL)
      set_property(TARGET "${target}_IMPLIB" PROPERTY
          IMPORTED_LOCATION "${CODELIB_DIR}/${CODELIB_SINGLE_SUBDIR}/${name}.lib")
      add_dependencies(${target}_IMPLIB ${${target}_IMPORT_LIBRARY})
    endif()
    set_property(TARGET "${target}" PROPERTY NO_SONAME ON)
  endif()

  llvm_update_compile_flags(${target})

  set_output_directory(${target}
      BINARY_DIR ${out_bin_dir} LIBRARY_DIR ${out_lib_dir})

  if(MODULE)
    set_target_properties("${target}" PROPERTIES
        PREFIX ""
        SUFFIX ${LLVM_PLUGIN_EXT})
  endif()

  # For back-deployed libraries, install into lib/code-<version>.
  if (CODELIB_SINGLE_BACK_DEPLOYMENT_LIBRARY)
    set(codelib_prefix "${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib/code-${CODELIB_SINGLE_BACK_DEPLOYMENT_LIBRARY}")
  else()
    set(codelib_prefix ${lib_dir})
  endif()

  # Install runtime libraries to lib/code instead of lib. This works around
  # the fact that -isysroot prevents linking to libraries in the system
  # /usr/lib if Code is installed in /usr.
  set_target_properties("${target}" PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${codelib_prefix}/${output_sub_dir}
    ARCHIVE_OUTPUT_DIRECTORY ${codelib_prefix}/${output_sub_dir})
  if(CODELIB_SINGLE_SDK STREQUAL "WINDOWS" AND CODELIB_SINGLE_IS_RUNTIME_CORE
      AND libkind STREQUAL "SHARED")
    add_custom_command(TARGET ${target} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${target}> ${codelib_prefix}/${output_sub_dir})
  endif()

  foreach(config ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${config} config_upper)
    escape_path_for_xcode("${config}" "${codelib_prefix}" config_lib_dir)
    set_target_properties(${target} PROPERTIES
      LIBRARY_OUTPUT_DIRECTORY_${config_upper} ${config_lib_dir}/${output_sub_dir}
      ARCHIVE_OUTPUT_DIRECTORY_${config_upper} ${config_lib_dir}/${output_sub_dir})
  endforeach()

  if(CODELIB_SINGLE_SDK IN_LIST CODE_DARWIN_PLATFORMS)
    set(install_name_dir "@rpath")

    if(CODELIB_SINGLE_IS_STDLIB)
      set(install_name_dir "${CODE_DARWIN_RUNTIME_INSTALL_NAME_DIR}")

      # iOS-like overlays are installed in a separate directory so that
      # unzippered twins do not conflict.
      if(maccatalyst_build_flavor STREQUAL "ios-like"
          AND DEFINED CODE_DARWIN_MACCATALYST_RUNTIME_INSTALL_NAME_DIR)
        set(install_name_dir "${CODE_DARWIN_MACCATALYST_RUNTIME_INSTALL_NAME_DIR}")
      endif()
    endif()

    if(CODELIB_SINGLE_DARWIN_INSTALL_NAME_DIR)
      set(install_name_dir "${CODELIB_SINGLE_DARWIN_INSTALL_NAME_DIR}")
    endif()

    set_target_properties("${target}"
      PROPERTIES
      INSTALL_NAME_DIR "${install_name_dir}")
  elseif("${CODELIB_SINGLE_SDK}" STREQUAL "LINUX")
    set_target_properties("${target}"
      PROPERTIES
      INSTALL_RPATH "$ORIGIN")
  elseif("${CODELIB_SINGLE_SDK}" STREQUAL "CYGWIN")
    set_target_properties("${target}"
      PROPERTIES
      INSTALL_RPATH "$ORIGIN:/usr/lib/code/cygwin")
  elseif("${CODELIB_SINGLE_SDK}" STREQUAL "ANDROID")
    # CMake generates an incorrect rule `$SONAME_FLAG $INSTALLNAME_DIR$SONAME`
    # for an Android cross-build from a macOS host. Construct the proper linker
    # flags manually in add_code_target_library instead, see there with
    # variable `codelib_link_flags_all`.
    set_target_properties("${target}" PROPERTIES NO_SONAME TRUE)
    # Only set the install RPATH if the toolchain and runtime will be in Termux
    # or some other native sysroot on Android.
    if(NOT "${CODE_ANDROID_NATIVE_SYSROOT}" STREQUAL "")
      set_target_properties("${target}"
        PROPERTIES
        INSTALL_RPATH "$ORIGIN")
    endif()

    set_target_properties(${target} PROPERTIES
      POSITION_INDEPENDENT_CODE YES)
  elseif("${CODELIB_SINGLE_SDK}" STREQUAL "OPENBSD")
    set_target_properties("${target}"
      PROPERTIES
      INSTALL_RPATH "$ORIGIN")
  elseif("${CODELIB_SINGLE_SDK}" STREQUAL "FREEBSD")
    set_target_properties("${target}"
      PROPERTIES
      INSTALL_RPATH "$ORIGIN")
  endif()

  set_target_properties("${target}" PROPERTIES BUILD_WITH_INSTALL_RPATH YES)
  set_target_properties("${target}" PROPERTIES FOLDER "Code libraries")

  # Configure the static library target.
  # Set compile and link flags for the non-static target.
  # Do these LAST.
  set(target_static)
  if(CODELIB_SINGLE_IS_STDLIB AND CODELIB_SINGLE_STATIC AND NOT CODELIB_SINGLE_INSTALL_WITH_SHARED)
    set(target_static "${target}-static")

    # We have already compiled Code sources.  Link everything into a static
    # library.
    add_library(${target_static} STATIC
        ${CODELIB_SINGLE_SOURCES}
        ${CODELIB_INCORPORATED_OBJECT_LIBRARIES_EXPRESSIONS}
        ${CODELIB_SINGLE_XCODE_WORKAROUND_SOURCES})

    set_output_directory(${target_static}
        BINARY_DIR ${out_bin_dir}
        LIBRARY_DIR ${out_lib_dir})

    if(CODELIB_INSTALL_WITH_SHARED)
      set(code_lib_dir ${lib_dir})
    else()
      set(code_lib_dir ${static_lib_dir})
    endif()

    foreach(config ${CMAKE_CONFIGURATION_TYPES})
      string(TOUPPER ${config} config_upper)
      escape_path_for_xcode(
          "${config}" "${code_lib_dir}" config_lib_dir)
      set_target_properties(${target_static} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY_${config_upper} ${config_lib_dir}/${output_sub_dir}
        ARCHIVE_OUTPUT_DIRECTORY_${config_upper} ${config_lib_dir}/${output_sub_dir})
    endforeach()

    set_target_properties(${target_static} PROPERTIES
      LIBRARY_OUTPUT_DIRECTORY ${code_lib_dir}/${output_sub_dir}
      ARCHIVE_OUTPUT_DIRECTORY ${code_lib_dir}/${output_sub_dir})
  endif()

  set_target_properties(${target}
      PROPERTIES
      # Library name (without the variant information)
      OUTPUT_NAME ${name})
  if(target_static)
    set_target_properties(${target_static}
        PROPERTIES
        OUTPUT_NAME ${name})
  endif()

  # Don't build standard libraries by default.  We will enable building
  # standard libraries that the user requested; the rest can be built on-demand.
  foreach(t "${target}" ${target_static})
    set_target_properties(${t} PROPERTIES EXCLUDE_FROM_ALL TRUE)
  endforeach()

  # Handle linking and dependencies.
  add_dependencies_multiple_targets(
      TARGETS "${target}" ${target_static}
      DEPENDS
        ${CODELIB_SINGLE_DEPENDS}
        ${gyb_dependency_targets}
        "${code_object_dependency_target}"
        "${code_module_dependency_target}"
        ${LLVM_COMMON_DEPENDS})

  if("${libkind}" STREQUAL "SHARED")
    target_link_libraries("${target}" PRIVATE ${CODELIB_SINGLE_LINK_LIBRARIES})
  elseif("${libkind}" STREQUAL "OBJECT")
    precondition_list_empty(
        "${CODELIB_SINGLE_LINK_LIBRARIES}"
        "OBJECT_LIBRARY may not link to anything")
  else()
    target_link_libraries("${target}" INTERFACE ${CODELIB_SINGLE_LINK_LIBRARIES})
  endif()

  if(target_static)
    set(target_static_depends)
    foreach(dep ${CODELIB_SINGLE_LINK_LIBRARIES})
      if (NOT "${dep}" MATCHES "^(icucore|dispatch|BlocksRuntime)($|-.*)$")
        list(APPEND target_static_depends "${dep}-static")
      endif()
    endforeach()


    # FIXME: should this be target_link_libraries?
    add_dependencies_multiple_targets(
        TARGETS "${target_static}"
        DEPENDS ${target_static_depends})
  endif()

  # Link against system frameworks.
  foreach(FRAMEWORK ${CODELIB_SINGLE_FRAMEWORK_DEPENDS})
    foreach(t "${target}" ${target_static})
      target_link_libraries("${t}" PUBLIC "-framework ${FRAMEWORK}")
    endforeach()
  endforeach()
  foreach(FRAMEWORK ${CODELIB_SINGLE_FRAMEWORK_DEPENDS_WEAK})
    foreach(t "${target}" ${target_static})
      target_link_libraries("${t}" PUBLIC "-weak_framework ${FRAMEWORK}")
    endforeach()
  endforeach()

  # Collect compile and link flags for the static and non-static targets.
  # Don't set PROPERTY COMPILE_FLAGS or LINK_FLAGS directly.
  set(c_compile_flags
      ${CODELIB_SINGLE_C_COMPILE_FLAGS}  "-DCODE_TARGET_LIBRARY_NAME=${name}")
  set(link_flags ${CODELIB_SINGLE_LINK_FLAGS})

  set(library_search_subdir "${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}")
  set(library_search_directories
      "${lib_dir}/${output_sub_dir}"
      "${CODE_NATIVE_CODE_TOOLS_PATH}/../lib/code/${CODELIB_SINGLE_SUBDIR}"
      "${CODE_NATIVE_CODE_TOOLS_PATH}/../lib/code/${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}")

  # In certain cases when building, the environment variable SDKROOT is set to override
  # where the sdk root is located in the system. If that environment variable has been
  # set by the user, respect it and add the specified SDKROOT directory to the
  # library_search_directories so we are able to link against those libraries
  if(DEFINED ENV{SDKROOT} AND EXISTS "$ENV{SDKROOT}/usr/lib/code")
      list(APPEND library_search_directories "$ENV{SDKROOT}/usr/lib/code")
  endif()

  list(APPEND library_search_directories "${CODE_SDK_${sdk}_ARCH_${arch}_PATH}/usr/lib/code")

  # Add variant-specific flags.
  set(build_type "${CODE_RUNTIME_BUILD_TYPE}")
  set(enable_assertions "${CODE_RUNTIME_ASSERTIONS}")
  set(lto_type "${CODE_RUNTIME_ENABLE_LTO}")

  _add_target_variant_c_compile_flags(
    SDK "${CODELIB_SINGLE_SDK}"
    ARCH "${CODELIB_SINGLE_ARCHITECTURE}"
    BUILD_TYPE "${build_type}"
    ENABLE_ASSERTIONS "${enable_assertions}"
    ANALYZE_CODE_COVERAGE "${analyze_code_coverage}"
    ENABLE_LTO "${lto_type}"
    DEPLOYMENT_VERSION_OSX "${CODELIB_DEPLOYMENT_VERSION_OSX}"
    DEPLOYMENT_VERSION_MACCATALYST "${CODELIB_DEPLOYMENT_VERSION_MACCATALYST}"
    DEPLOYMENT_VERSION_IOS "${CODELIB_DEPLOYMENT_VERSION_IOS}"
    DEPLOYMENT_VERSION_TVOS "${CODELIB_DEPLOYMENT_VERSION_TVOS}"
    DEPLOYMENT_VERSION_WATCHOS "${CODELIB_DEPLOYMENT_VERSION_WATCHOS}"
    DEPLOYMENT_VERSION_XROS "${CODELIB_DEPLOYMENT_VERSION_XROS}"
    RESULT_VAR_NAME c_compile_flags
    MACCATALYST_BUILD_FLAVOR "${CODELIB_SINGLE_MACCATALYST_BUILD_FLAVOR}"
    )

  if(CODELIB_SINGLE_SDK STREQUAL "WINDOWS")
    if(libkind STREQUAL "SHARED")
      list(APPEND c_compile_flags -D_WINDLL)
    endif()
  endif()
  _add_target_variant_link_flags(
    SDK "${CODELIB_SINGLE_SDK}"
    ARCH "${CODELIB_SINGLE_ARCHITECTURE}"
    BUILD_TYPE "${build_type}"
    ENABLE_ASSERTIONS "${enable_assertions}"
    ANALYZE_CODE_COVERAGE "${analyze_code_coverage}"
    ENABLE_LTO "${lto_type}"
    LTO_OBJECT_NAME "${target}-${CODELIB_SINGLE_SDK}-${CODELIB_SINGLE_ARCHITECTURE}"
    DEPLOYMENT_VERSION_OSX "${CODELIB_DEPLOYMENT_VERSION_OSX}"
    DEPLOYMENT_VERSION_MACCATALYST "${CODELIB_DEPLOYMENT_VERSION_MACCATALYST}"
    DEPLOYMENT_VERSION_IOS "${CODELIB_DEPLOYMENT_VERSION_IOS}"
    DEPLOYMENT_VERSION_TVOS "${CODELIB_DEPLOYMENT_VERSION_TVOS}"
    DEPLOYMENT_VERSION_WATCHOS "${CODELIB_DEPLOYMENT_VERSION_WATCHOS}"
    DEPLOYMENT_VERSION_XROS "${CODELIB_DEPLOYMENT_VERSION_XROS}"
    RESULT_VAR_NAME link_flags
    LINK_LIBRARIES_VAR_NAME link_libraries
    LIBRARY_SEARCH_DIRECTORIES_VAR_NAME library_search_directories
    MACCATALYST_BUILD_FLAVOR "${CODELIB_SINGLE_MACCATALYST_BUILD_FLAVOR}"
      )

  # Configure plist creation for OS X.
  set(PLIST_INFO_PLIST "Info.plist" CACHE STRING "Plist name")
  if("${CODELIB_SINGLE_SDK}" IN_LIST CODE_DARWIN_PLATFORMS AND CODELIB_SINGLE_IS_STDLIB)
    set(PLIST_INFO_NAME ${name})

    # Underscores aren't permitted in the bundle identifier.
    string(REPLACE "_" "" PLIST_INFO_UTI "com.apple.dt.runtime.${name}")
    set(PLIST_INFO_VERSION "${CODE_VERSION}")
    if (CODE_COMPILER_VERSION)
      set(PLIST_INFO_BUILD_VERSION
        "${CODE_COMPILER_VERSION}")
    endif()

    set(PLIST_INFO_PLIST_OUT "${PLIST_INFO_PLIST}")
    list(APPEND link_flags
         "-Wl,-sectcreate,__TEXT,__info_plist,${CMAKE_CURRENT_BINARY_DIR}/${PLIST_INFO_PLIST_OUT}")
    configure_file(
        "${CODE_SOURCE_DIR}/runtime/${PLIST_INFO_PLIST}.in"
        "${PLIST_INFO_PLIST_OUT}"
        @ONLY
        NEWLINE_STYLE UNIX)
    set_property(TARGET ${target} APPEND PROPERTY LINK_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${PLIST_INFO_PLIST_OUT}")

    # If Application Extensions are enabled, pass the linker flag marking
    # the dylib as safe.
    if (CXX_SUPPORTS_FAPPLICATION_EXTENSION AND (NOT DISABLE_APPLICATION_EXTENSION))
      list(APPEND link_flags "-Wl,-application_extension")
    endif()

    set(PLIST_INFO_UTI)
    set(PLIST_INFO_NAME)
    set(PLIST_INFO_VERSION)
    set(PLIST_INFO_BUILD_VERSION)
  endif()

  # Set compilation and link flags.
  if(CODELIB_SINGLE_SDK STREQUAL "WINDOWS")
    if(NOT CMAKE_HOST_SYSTEM MATCHES Windows)
      code_windows_include_for_arch(${CODELIB_SINGLE_ARCHITECTURE}
        ${CODELIB_SINGLE_ARCHITECTURE}_INCLUDE)
      target_include_directories(${target} SYSTEM PRIVATE
        ${${CODELIB_SINGLE_ARCHITECTURE}_INCLUDE})
    endif()

    if(NOT CMAKE_C_COMPILER_ID STREQUAL "MSVC")
      code_windows_get_sdk_vfs_overlay(CODELIB_SINGLE_VFS_OVERLAY)
      target_compile_options(${target} PRIVATE
        "SHELL:-Xclang -ivfsoverlay -Xclang ${CODELIB_SINGLE_VFS_OVERLAY}")

      # MSVC doesn't support -Xclang. We don't need to manually specify
      # the dependent libraries as `cl` does so.
      target_compile_options(${target} PRIVATE
        "SHELL:-Xclang --dependent-lib=oldnames"
        # TODO(compnerd) handle /MT, /MTd
        "SHELL:-Xclang --dependent-lib=msvcrt$<$<CONFIG:Debug>:d>")
    endif()
  endif()

  target_compile_options(${target} PRIVATE
    ${c_compile_flags})
  target_link_options(${target} PRIVATE
    ${link_flags})
  if(CODELIB_SINGLE_SDK IN_LIST CODE_DARWIN_PLATFORMS)
    target_link_options(${target} PRIVATE
      "LINKER:-compatibility_version,1")
    if(CODE_COMPILER_VERSION)
      target_link_options(${target} PRIVATE
        "LINKER:-current_version,${CODE_COMPILER_VERSION}")
    endif()
    # Include LLVM Bitcode slices for iOS, Watch OS, and Apple TV OS device libraries.
    if(CODE_EMBED_BITCODE_SECTION AND NOT CODELIB_SINGLE_DONT_EMBED_BITCODE)
      if("${CODELIB_SINGLE_SDK}" STREQUAL "IOS" OR
         "${CODELIB_SINGLE_SDK}" STREQUAL "TVOS" OR
         "${CODELIB_SINGLE_SDK}" STREQUAL "XROS" OR
         "${CODELIB_SINGLE_SDK}" STREQUAL "WATCHOS")
        # Please note that using a generator expression to fit
        # this in a single target_link_options does not work
        # (at least in CMake 3.15 and 3.16),
        # since that seems not to allow the LINKER: prefix to be
        # evaluated (i.e. it will be added as-is to the linker parameters)
        target_link_options(${target} PRIVATE
          "LINKER:-bitcode_bundle"
          "LINKER:-lto_library,${LLVM_LIBRARY_DIR}/libLTO.dylib")

        if(CODE_EMBED_BITCODE_SECTION_HIDE_SYMBOLS)
          target_link_options(${target} PRIVATE
            "LINKER:-bitcode_hide_symbols")
        endif()
      endif()
    endif()

    # Silence warnings about global initializers. We already have clang
    # emitting warnings about global initializers when it compiles the code.
    list(APPEND codelib_link_flags_all "-Xlinker -no_warn_inits")
  endif()

  if(CODELIB_SINGLE_SDK IN_LIST CODE_APPLE_PLATFORMS)
    # In the past, we relied on unsetting globally
    # CMAKE_OSX_ARCHITECTURES to ensure that CMake
    # would not add the -arch flag. This is no longer
    # the case  when running on Apple Silicon, when
    # CMake will enforce a default (see
    # https://gitlab.kitware.com/cmake/cmake/-/merge_requests/5291)
    set_property(TARGET ${target} PROPERTY OSX_ARCHITECTURES "${CODELIB_SINGLE_ARCHITECTURE}")
    if(TARGET "${target_static}")
      set_property(TARGET ${target_static} PROPERTY OSX_ARCHITECTURES "${CODELIB_SINGLE_ARCHITECTURE}")
    endif()
  endif()

  target_link_libraries(${target} PRIVATE
    ${link_libraries})
  target_link_directories(${target} PRIVATE
    ${library_search_directories})

  # Adjust the linked libraries for windows targets.  On Windows, the link is
  # performed against the import library, and the runtime uses the dll.  Not
  # doing so will result in incorrect symbol resolution and linkage.  We created
  # import library targets when the library was added.  Use that to adjust the
  # link libraries.
  if(CODELIB_SINGLE_SDK STREQUAL "WINDOWS" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    foreach(library_list LINK_LIBRARIES PRIVATE_LINK_LIBRARIES)
      set(import_libraries)
      foreach(library ${CODELIB_SINGLE_${library_list}})
        # Ensure that the library is a target.  If an absolute path was given,
        # then we do not have an import library associated with it.  This occurs
        # primarily with ICU (which will be an import library).  Import
        # libraries are only associated with shared libraries, so add an
        # additional check for that as well.
        set(import_library ${library})
        if(TARGET ${library})
          get_target_property(type ${library} TYPE)
          if(type STREQUAL "SHARED_LIBRARY")
            set(import_library ${library}_IMPLIB)
          endif()
        endif()
        list(APPEND import_libraries ${import_library})
      endforeach()
      set(CODELIB_SINGLE_${library_list} ${import_libraries})
    endforeach()
  endif()

  if("${libkind}" STREQUAL "OBJECT")
    precondition_list_empty(
        "${CODELIB_SINGLE_PRIVATE_LINK_LIBRARIES}"
        "OBJECT_LIBRARY may not link to anything")
  else()
    target_link_libraries("${target}" PRIVATE
        ${CODELIB_SINGLE_PRIVATE_LINK_LIBRARIES})
  endif()

  # NOTE(compnerd) use the C linker language to invoke `clang` rather than
  # `clang++` as we explicitly link against the C++ runtime.  We were previously
  # actually passing `-noruntime++` to avoid the C++ runtime linkage.
  if("${CODELIB_SINGLE_SDK}" STREQUAL "ANDROID")
    set_property(TARGET "${target}" PROPERTY
      LINKER_LANGUAGE "C")
  else()
    set_property(TARGET "${target}" PROPERTY
      LINKER_LANGUAGE "CXX")
  endif()

  if(target_static)
    target_compile_options(${target_static} PRIVATE
      ${c_compile_flags})
    # FIXME: The fallback paths here are going to be dynamic libraries.

    if(CODELIB_INSTALL_WITH_SHARED)
      set(search_base_dir ${lib_dir})
    else()
      set(search_base_dir ${static_lib_dir})
    endif()
    set(library_search_directories
        "${search_base_dir}/${CODELIB_SINGLE_SUBDIR}"
        "${CODE_NATIVE_CODE_TOOLS_PATH}/../lib/code/${CODELIB_SINGLE_SUBDIR}"
        "${CODE_NATIVE_CODE_TOOLS_PATH}/../lib/code/${CODE_SDK_${CODELIB_SINGLE_SDK}_LIB_SUBDIR}")
    target_link_directories(${target_static} PRIVATE
      ${library_search_directories})

    _list_add_string_suffix(
        "${CODELIB_SINGLE_PRIVATE_LINK_LIBRARIES}"
        "-static"
        target_private_libs)

    target_link_libraries("${target_static}" PRIVATE
        ${target_private_libs})

    # Force executables linker language to be CXX so that we do not link using the
    # host toolchain codec.
    if("${CODELIB_SINGLE_SDK}" STREQUAL "ANDROID")
      set_property(TARGET "${target_static}" PROPERTY
        LINKER_LANGUAGE "C")
    else()
      set_property(TARGET "${target_static}" PROPERTY
        LINKER_LANGUAGE "CXX")
    endif()
  endif()

  # Do not add code here.
endfunction()

# Add a new Code target library.
#
# NOTE: This has not had the code host code debrided from it yet. That will be
# in a forthcoming commit.
#
# Usage:
#   add_code_target_library(name
#     [SHARED]
#     [STATIC]
#     [DEPENDS dep1 ...]
#     [LINK_LIBRARIES dep1 ...]
#     [CODE_MODULE_DEPENDS dep1 ...]
#     [FRAMEWORK_DEPENDS dep1 ...]
#     [FRAMEWORK_DEPENDS_WEAK dep1 ...]
#     [FILE_DEPENDS target1 ...]
#     [TARGET_SDKS sdk1...]
#     [C_COMPILE_FLAGS flag1...]
#     [CODE_COMPILE_FLAGS flag1...]
#     [LINK_FLAGS flag1...]
#     [DONT_EMBED_BITCODE]
#     [INSTALL]
#     [IS_STDLIB]
#     [IS_RUNTIME_CORE]
#     [INSTALL_WITH_SHARED]
#     INSTALL_IN_COMPONENT comp
#     DEPLOYMENT_VERSION_OSX version
#     DEPLOYMENT_VERSION_MACCATALYST version
#     DEPLOYMENT_VERSION_IOS version
#     DEPLOYMENT_VERSION_TVOS version
#     DEPLOYMENT_VERSION_WATCHOS version
#     DEPLOYMENT_VERSION_XROS version
#     MACCATALYST_BUILD_FLAVOR flavor
#     BACK_DEPLOYMENT_LIBRARY version
#     source1 [source2 source3 ...])
#
# name
#   Name of the library (e.g., codeParse).
#
# SHARED
#   Build a shared library.
#
# STATIC
#   Build a static library.
#
# DEPENDS
#   Targets that this library depends on.
#
# LINK_LIBRARIES
#   Libraries this library depends on.
#
# CODE_MODULE_DEPENDS
#   Code modules this library depends on.
#
# CODE_MODULE_DEPENDS_OSX
#   Code modules this library depends on when built for OS X.
#
# CODE_MODULE_DEPENDS_MACCATALYST
#   Zippered Code modules this library depends on when built for macCatalyst.
#   For example, Foundation.
#
# CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED
#   Unzippered Code modules this library depends on when built for macCatalyst.
#   For example, UIKit
#
# CODE_MODULE_DEPENDS_IOS
#   Code modules this library depends on when built for iOS.
#
# CODE_MODULE_DEPENDS_TVOS
#   Code modules this library depends on when built for tvOS.
#
# CODE_MODULE_DEPENDS_WATCHOS
#   Code modules this library depends on when built for watchOS.
#
# CODE_MODULE_DEPENDS_XROS
#   Code modules this library depends on when built for xrOS.
#
# CODE_MODULE_DEPENDS_FREESTANDING
#   Code modules this library depends on when built for Freestanding.
#
# CODE_MODULE_DEPENDS_FREEBSD
#   Code modules this library depends on when built for FreeBSD.
#
# CODE_MODULE_DEPENDS_OPENBSD
#   Code modules this library depends on when built for OpenBSD.
#
# CODE_MODULE_DEPENDS_LINUX
#   Code modules this library depends on when built for Linux.
#
# CODE_MODULE_DEPENDS_CYGWIN
#   Code modules this library depends on when built for Cygwin.
#
# CODE_MODULE_DEPENDS_HAIKU
#   Code modules this library depends on when built for Haiku.
#
# CODE_MODULE_DEPENDS_WASI
#   Code modules this library depends on when built for WASI.
#
# FRAMEWORK_DEPENDS
#   System frameworks this library depends on.
#
# FRAMEWORK_DEPENDS_WEAK
#   System frameworks this library depends on that should be weak-linked
#
# FILE_DEPENDS
#   Additional files this library depends on.
#
# TARGET_SDKS
#   The set of SDKs in which this library is included. If empty, the library
#   is included in all SDKs.
#
# C_COMPILE_FLAGS
#   Extra compiler flags (C, C++, ObjC).
#
# CODE_COMPILE_FLAGS
#   Extra compiler flags (Code).
#
# LINK_FLAGS
#   Extra linker flags.
#
# DONT_EMBED_BITCODE
#   Don't embed LLVM bitcode in this target, even if it is enabled globally.
#
# IS_STDLIB
#   Treat the library as a part of the Code standard library.
#
# IS_RUNTIME_CORE
#   Compile as the Code standard library core.
#
# IS_SDK_OVERLAY
#   Treat the library as a part of the Code SDK overlay.
#
# BACK_DEPLOYMENT_LIBRARY
#   Treat this as a back-deployment library to the given Code version
#
# INSTALL_IN_COMPONENT comp
#   The Code installation component that this library belongs to.
#
# DEPLOYMENT_VERSION_OSX
#   The minimum deployment version to build for if this is an OSX library.
#
# DEPLOYMENT_VERSION_MACCATALYST
#   The minimum deployment version to build for if this is an macCatalyst library.
#
# DEPLOYMENT_VERSION_IOS
#   The minimum deployment version to build for if this is an iOS library.
#
# DEPLOYMENT_VERSION_TVOS
#   The minimum deployment version to build for if this is an TVOS library.
#
# DEPLOYMENT_VERSION_WATCHOS
#   The minimum deployment version to build for if this is an WATCHOS library.
#
# DEPLOYMENT_VERSION_XROS
#   The minimum deployment version to build for if this is an XROS library.
#
# INSTALL_WITH_SHARED
#   Install a static library target alongside shared libraries
#
# MACCATALYST_BUILD_FLAVOR
#   Possible values are 'ios-like', 'macos-like', 'zippered', 'unzippered-twin'
#   Presence of a build flavor requires CODE_MODULE_DEPENDS_MACCATALYST to be
#   defined and have values.
#
# CODE_SOURCES_DEPENDS_MACOS
#   Sources that are built when this library is being built for macOS
#
# CODE_SOURCES_DEPENDS_IOS
#   Sources that are built when this library is being built for iOS
#
# CODE_SOURCES_DEPENDS_TVOS
#   Sources that are built when this library is being built for tvOS
#
# CODE_SOURCES_DEPENDS_WATCHOS
#   Sources that are built when this library is being built for watchOS
#
# CODE_SOURCES_DEPENDS_VISIONOS
#   Sources that are built when this library is being built for visionOS
#
# CODE_SOURCES_DEPENDS_FREESTANDING
#   Sources that are built when this library is being built for freestanding
#
# CODE_SOURCES_DEPENDS_FREEBSD
#   Sources that are built when this library is being built for FreeBSD
#
# CODE_SOURCES_DEPENDS_OPENBSD
#   Sources that are built when this library is being built for OpenBSD
#
# CODE_SOURCES_DEPENDS_LINUX
#   Sources that are built when this library is being built for Linux
#
# CODE_SOURCES_DEPENDS_CYGWIN
#   Sources that are built when this library is being built for Cygwin
#
# CODE_SOURCES_DEPENDS_HAIKU
#   Sources that are built when this library is being built for Haiku
#
# CODE_SOURCES_DEPENDS_WASI
#   Sources that are built when this library is being built for WASI
#
# CODE_SOURCES_DEPENDS_WINDOWS
#   Sources that are built when this library is being built for Windows
#
# source1 ...
#   Sources to add into this library.
function(add_code_target_library name)
  set(CODELIB_options
        DONT_EMBED_BITCODE
        HAS_CODE_CONTENT
        IS_SDK_OVERLAY
        IS_STDLIB
        IS_RUNTIME_CORE
        IS_CODE_ONLY
        NOCODERT
        OBJECT_LIBRARY
        SHARED
        STATIC
        NO_LINK_NAME
        INSTALL_WITH_SHARED)
  set(CODELIB_single_parameter_options
        DEPLOYMENT_VERSION_IOS
        DEPLOYMENT_VERSION_OSX
        DEPLOYMENT_VERSION_TVOS
        DEPLOYMENT_VERSION_WATCHOS
        DEPLOYMENT_VERSION_XROS
        INSTALL_IN_COMPONENT
        INSTALL_BINARY_CODEMODULE
        DARWIN_INSTALL_NAME_DIR
        DEPLOYMENT_VERSION_MACCATALYST
        MACCATALYST_BUILD_FLAVOR
        BACK_DEPLOYMENT_LIBRARY)
  set(CODELIB_multiple_parameter_options
        C_COMPILE_FLAGS
        C_COMPILE_FLAGS_IOS
        C_COMPILE_FLAGS_OSX
        C_COMPILE_FLAGS_TVOS
        C_COMPILE_FLAGS_WATCHOS
        C_COMPILE_FLAGS_LINUX
        C_COMPILE_FLAGS_WINDOWS
        DEPENDS
        FILE_DEPENDS
        FRAMEWORK_DEPENDS
        FRAMEWORK_DEPENDS_IOS_TVOS
        FRAMEWORK_DEPENDS_OSX
        FRAMEWORK_DEPENDS_WEAK
        GYB_SOURCES
        INCORPORATE_OBJECT_LIBRARIES
        INCORPORATE_OBJECT_LIBRARIES_SHARED_ONLY
        LINK_FLAGS
        LINK_LIBRARIES
        PREFIX_INCLUDE_DIRS
        PRIVATE_LINK_LIBRARIES
        CODE_COMPILE_FLAGS
        CODE_COMPILE_FLAGS_IOS
        CODE_COMPILE_FLAGS_OSX
        CODE_COMPILE_FLAGS_TVOS
        CODE_COMPILE_FLAGS_WATCHOS
        CODE_COMPILE_FLAGS_XROS
        CODE_COMPILE_FLAGS_LINUX
        CODE_MODULE_DEPENDS
        CODE_MODULE_DEPENDS_CYGWIN
        CODE_MODULE_DEPENDS_FREEBSD
        CODE_MODULE_DEPENDS_FREESTANDING
        CODE_MODULE_DEPENDS_OPENBSD
        CODE_MODULE_DEPENDS_HAIKU
        CODE_MODULE_DEPENDS_IOS
        CODE_MODULE_DEPENDS_LINUX
        CODE_MODULE_DEPENDS_LINUX_STATIC
        CODE_MODULE_DEPENDS_OSX
        CODE_MODULE_DEPENDS_TVOS
        CODE_MODULE_DEPENDS_WASI
        CODE_MODULE_DEPENDS_WATCHOS
        CODE_MODULE_DEPENDS_XROS
        CODE_MODULE_DEPENDS_WINDOWS
        CODE_MODULE_DEPENDS_FROM_SDK
        TARGET_SDKS
        CODE_COMPILE_FLAGS_MACCATALYST
        CODE_MODULE_DEPENDS_MACCATALYST
        CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED
        CODE_SOURCES_DEPENDS_MACOS
        CODE_SOURCES_DEPENDS_IOS
        CODE_SOURCES_DEPENDS_TVOS
        CODE_SOURCES_DEPENDS_WATCHOS
        CODE_SOURCES_DEPENDS_VISIONOS
        CODE_SOURCES_DEPENDS_FREESTANDING
        CODE_SOURCES_DEPENDS_FREEBSD
        CODE_SOURCES_DEPENDS_OPENBSD
        CODE_SOURCES_DEPENDS_LINUX
        CODE_SOURCES_DEPENDS_CYGWIN
        CODE_SOURCES_DEPENDS_HAIKU
        CODE_SOURCES_DEPENDS_WASI
        CODE_SOURCES_DEPENDS_WINDOWS)

  cmake_parse_arguments(CODELIB
                        "${CODELIB_options}"
                        "${CODELIB_single_parameter_options}"
                        "${CODELIB_multiple_parameter_options}"
                        ${ARGN})
  set(CODELIB_SOURCES ${CODELIB_UNPARSED_ARGUMENTS})

  # Ensure it's impossible to build for macCatalyst without module dependencies
  if(CODE_ENABLE_MACCATALYST AND CODELIB_MACCATALYST_BUILD_FLAVOR)
    if((NOT CODELIB_MACCATALYST_BUILD_FLAVOR STREQUAL "zippered") OR
       CODELIB_CODE_MODULE_DEPENDS_OSX)
      precondition(CODELIB_CODE_MODULE_DEPENDS_MACCATALYST
        MESSAGE "CODE_MODULE_DEPENDS_MACCATALYST is required when building for macCatalyst")
    endif()
  endif()

  # Infer arguments.

  if(CODELIB_IS_SDK_OVERLAY)
    set(CODELIB_HAS_CODE_CONTENT TRUE)
    set(CODELIB_IS_STDLIB TRUE)
  endif()

  # Standard library is always a target library.
  if(CODELIB_IS_STDLIB)
    set(CODELIB_HAS_CODE_CONTENT TRUE)
  endif()

  # If target SDKs are not specified, build for all known SDKs.
  if("${CODELIB_TARGET_SDKS}" STREQUAL "")
    set(CODELIB_TARGET_SDKS ${CODE_SDKS})
  endif()
  list_replace(CODELIB_TARGET_SDKS ALL_APPLE_PLATFORMS "${CODE_DARWIN_PLATFORMS}")

  # Support adding a "NOT" on the front to mean all SDKs except the following
  list(LENGTH CODELIB_TARGET_SDKS number_of_target_sdks)
  if(number_of_target_sdks GREATER_EQUAL "1")
    list(GET CODELIB_TARGET_SDKS 0 first_sdk)
    if("${first_sdk}" STREQUAL "NOT")
        list(REMOVE_AT CODELIB_TARGET_SDKS 0)
        list_subtract("${CODE_SDKS}" "${CODELIB_TARGET_SDKS}"
        "CODELIB_TARGET_SDKS")
    endif()
  endif()

  list_intersect(
    "${CODELIB_TARGET_SDKS}" "${CODE_SDKS}" CODELIB_TARGET_SDKS)

  # All Code code depends on the standard library, except for the standard
  # library itself.
  if(CODELIB_HAS_CODE_CONTENT AND NOT CODELIB_IS_RUNTIME_CORE)
    list(APPEND CODELIB_CODE_MODULE_DEPENDS Core)

    # codeCodeOnoneSupport does not depend on itself, obviously.
    if(NOT name STREQUAL "codeCodeOnoneSupport")
      # All Code code depends on the CodeOnoneSupport in non-optimized mode,
      # except for the standard library itself.
      is_build_type_optimized("${CODE_RUNTIME_BUILD_TYPE}" optimized)
      if(NOT optimized)
        list(APPEND CODELIB_CODE_MODULE_DEPENDS CodeOnoneSupport)
      endif()
    endif()
  endif()

  if((NOT "${CODE_BUILD_STDLIB}") AND
     (NOT "${CODELIB_CODE_MODULE_DEPENDS}" STREQUAL ""))
    list(REMOVE_ITEM CODELIB_CODE_MODULE_DEPENDS Core CodeOnoneSupport)
  endif()

  translate_flags(CODELIB "${CODELIB_options}")
  precondition(CODELIB_INSTALL_IN_COMPONENT MESSAGE "INSTALL_IN_COMPONENT is required")

  if(NOT CODELIB_SHARED AND
     NOT CODELIB_STATIC AND
     NOT CODELIB_OBJECT_LIBRARY)
    message(FATAL_ERROR
        "Either SHARED, STATIC, or OBJECT_LIBRARY must be specified")
  endif()

  # In the standard library and overlays, warn about implicit overrides
  # as a reminder to consider when inherited protocols need different
  # behavior for their requirements.
  if (CODELIB_IS_STDLIB)
    list(APPEND CODELIB_CODE_COMPILE_FLAGS "-warn-implicit-overrides")
    list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-enable-ossa-modules")
    list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-enable-lexical-lifetimes=false")
  endif()

  if(NOT DEFINED CODELIB_INSTALL_BINARY_CODEMODULE)
    set(CODELIB_INSTALL_BINARY_CODEMODULE TRUE)
  endif()

  if(NOT CODE_BUILD_RUNTIME_WITH_HOST_COMPILER AND NOT BUILD_STANDALONE AND
     NOT CODE_PREBUILT_CLANG AND NOT CODELIB_IS_CODE_ONLY)
    list(APPEND CODELIB_DEPENDS clang)
  endif()

  # Turn off implicit import of _Concurrency when building libraries
  list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-disable-implicit-concurrency-module-import")

  # Turn off implicit import of _StringProcessing when building libraries
  list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-disable-implicit-string-processing-module-import")

  # Turn off implicit import of _Backtracing when building libraries
  if(CODE_COMPILER_SUPPORTS_BACKTRACING)
    list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-disable-implicit-backtracing-module-import")
  endif()

  if(CODELIB_IS_STDLIB AND CODE_RUNTIME_ENABLE_PRESPECIALIZATION)
    list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-prespecialize-generic-metadata")
  endif()

  if(CODE_RUNTIME_TASK_TO_THREAD_MODEL_CONCURRENCY)
      list(APPEND CODELIB_CODE_COMPILE_FLAGS "-Xfrontend;-concurrency-model=task-to-thread")
  endif()

  # If we are building this library for targets, loop through the various
  # SDKs building the variants of this library.
  list_intersect(
      "${CODELIB_TARGET_SDKS}" "${CODE_SDKS}" CODELIB_TARGET_SDKS)

  foreach(sdk ${CODELIB_TARGET_SDKS})
    if(NOT CODE_SDK_${sdk}_ARCHITECTURES)
      # CODE_SDK_${sdk}_ARCHITECTURES is empty, so just continue
      continue()
    endif()

    # Skip building library for macOS if macCatalyst support is not enabled and the
    # library only builds for macOS when macCatalyst is enabled.
    if(NOT CODE_ENABLE_MACCATALYST AND
        sdk STREQUAL "OSX" AND
        CODELIB_MACCATALYST_BUILD_FLAVOR STREQUAL "ios-like")
      message(STATUS "Skipping OSX SDK for module ${name}")
      continue()
    endif()

    # Determine if/what macCatalyst build flavor we are
    get_maccatalyst_build_flavor(maccatalyst_build_flavor
      "${sdk}" "${CODELIB_MACCATALYST_BUILD_FLAVOR}")

    set(maccatalyst_build_flavors)
    if(NOT DEFINED maccatalyst_build_flavor)
       list(APPEND maccatalyst_build_flavors "none")
    elseif(maccatalyst_build_flavor STREQUAL "unzippered-twin")
      list(APPEND maccatalyst_build_flavors "macos-like" "ios-like")
    else()
      list(APPEND maccatalyst_build_flavors "${maccatalyst_build_flavor}")
    endif()

    # Loop over the build flavors for the this library. If it is an unzippered
    # twin we'll build it twice: once for "macos-like" and once for "ios-like"
    # flavors.
    foreach(maccatalyst_build_flavor ${maccatalyst_build_flavors})
    if(maccatalyst_build_flavor STREQUAL "none")
      unset(maccatalyst_build_flavor)
    endif()

    set(THIN_INPUT_TARGETS)

    # Collect architecture agnostic SDK module dependencies
    set(codelib_module_depends_flattened ${CODELIB_CODE_MODULE_DEPENDS})
    if(sdk STREQUAL "OSX")
       if(DEFINED maccatalyst_build_flavor AND NOT maccatalyst_build_flavor STREQUAL "macos-like")
          list(APPEND codelib_module_depends_flattened
            ${CODELIB_CODE_MODULE_DEPENDS_MACCATALYST})
          list(APPEND codelib_module_depends_flattened
            ${CODELIB_CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED})
        else()
          list(APPEND codelib_module_depends_flattened
            ${CODELIB_CODE_MODULE_DEPENDS_OSX})
        endif()
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_OSX})
    elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_IOS})
    elseif(sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_TVOS})
    elseif(sdk STREQUAL "WATCHOS" OR sdk STREQUAL "WATCHOS_SIMULATOR")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_WATCHOS})
    elseif("${sdk}" STREQUAL "XROS" OR "${sdk}" STREQUAL "XROS_SIMULATOR")
        list(APPEND codelib_module_depends_flattened
            ${CODELIB_CODE_MODULE_DEPENDS_XROS})
    elseif(sdk STREQUAL "FREESTANDING")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_FREESTANDING})
    elseif(sdk STREQUAL "FREEBSD")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_FREEBSD})
    elseif(sdk STREQUAL "OPENBSD")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_OPENBSD})
    elseif(sdk STREQUAL "LINUX" OR sdk STREQUAL "ANDROID")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_LINUX})
    elseif(sdk STREQUAL "LINUX_STATIC")
      list(APPEND codelib_module_depends_flattened
          ${CODELIB_CODE_MODULE_DEPENDS_LINUX_STATIC})
    elseif(sdk STREQUAL "CYGWIN")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_CYGWIN})
    elseif(sdk STREQUAL "HAIKU")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_HAIKU})
    elseif(sdk STREQUAL "WASI")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_WASI})
    elseif(sdk STREQUAL "WINDOWS")
      list(APPEND codelib_module_depends_flattened
           ${CODELIB_CODE_MODULE_DEPENDS_WINDOWS})
    endif()

    # Collect architecture agnostic SDK framework dependencies
    set(codelib_framework_depends_flattened ${CODELIB_FRAMEWORK_DEPENDS})
    if(sdk STREQUAL "OSX")
      list(APPEND codelib_framework_depends_flattened
           ${CODELIB_FRAMEWORK_DEPENDS_OSX})
    elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR" OR
           sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
      list(APPEND codelib_framework_depends_flattened
           ${CODELIB_FRAMEWORK_DEPENDS_IOS_TVOS})
    endif()

    # Collect architecture agnostic code compiler flags
    set(codelib_code_compile_flags_all ${CODELIB_CODE_COMPILE_FLAGS})
    if(sdk STREQUAL "OSX")
      list(APPEND codelib_code_compile_flags_all
           ${CODELIB_CODE_COMPILE_FLAGS_OSX})
    elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR")
      list(APPEND codelib_code_compile_flags_all
           ${CODELIB_CODE_COMPILE_FLAGS_IOS})
    elseif(sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
      list(APPEND codelib_code_compile_flags_all
           ${CODELIB_CODE_COMPILE_FLAGS_TVOS})
    elseif(sdk STREQUAL "WATCHOS" OR sdk STREQUAL "WATCHOS_SIMULATOR")
      list(APPEND codelib_code_compile_flags_all
           ${CODELIB_CODE_COMPILE_FLAGS_WATCHOS})
    elseif("${sdk}" STREQUAL "XROS" OR "${sdk}" STREQUAL "XROS_SIMULATOR")
        list(APPEND codelib_code_compile_flags_all
            ${CODELIB_CODE_COMPILE_FLAGS_XROS})
    elseif(sdk STREQUAL "LINUX")
      list(APPEND codelib_code_compile_flags_all
           ${CODELIB_CODE_COMPILE_FLAGS_LINUX})
    elseif(sdk STREQUAL "WINDOWS")
      # FIXME: https://github.com/apple/code/issues/44614
      # static and shared are not mutually exclusive; however since we do a
      # single build of the sources, this doesn't work for building both
      # simultaneously.  Effectively, only shared builds are supported on
      # windows currently.
      if(CODELIB_SHARED)
        list(APPEND codelib_code_compile_flags_all -D_WINDLL)
        if(CODELIB_IS_RUNTIME_CORE)
          list(APPEND codelib_code_compile_flags_all -DcodeCore_EXPORTS)
        endif()
      elseif(CODELIB_STATIC)
        list(APPEND codelib_code_compile_flags_all -D_LIB)
      endif()
    endif()


    # Collect architecture agnostic SDK linker flags
    set(codelib_link_flags_all ${CODELIB_LINK_FLAGS})
    if(sdk STREQUAL "IOS_SIMULATOR" AND name STREQUAL "codeMediaPlayer")
      # message("DISABLING AUTOLINK FOR codeMediaPlayer")
      list(APPEND codelib_link_flags_all "-Xlinker" "-ignore_auto_link")
    endif()

    # Append SDK specific sources to the full list of sources
    set(sources ${CODELIB_SOURCES})
    if(sdk STREQUAL "OSX")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_MACOS})
    elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_IOS})
    elseif(sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_TVOS})
    elseif(sdk STREQUAL "WATCHOS" OR sdk STREQUAL "WATCHOS_SIMULATOR")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_WATCHOS})
    elseif(sdk STREQUAL "XROS" OR sdk STREQUAL "XROS_SIMULATOR")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_VISIONOS})
    elseif(sdk STREQUAL "FREESTANDING")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_FREESTANDING})
    elseif(sdk STREQUAL "FREEBSD")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_FREEBSD})
    elseif(sdk STREQUAL "OPENBSD")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_OPENBSD})
    elseif(sdk STREQUAL "LINUX" OR sdk STREQUAL "ANDROID")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_LINUX})
    elseif(sdk STREQUAL "CYGWIN")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_CYGWIN})
    elseif(sdk STREQUAL "HAIKU")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_HAIKU})
    elseif(sdk STREQUAL "WASI")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_WASI})
    elseif(sdk STREQUAL "WINDOWS")
      list(APPEND sources ${CODELIB_CODE_SOURCES_DEPENDS_WINDOWS})
    endif()

    # We unconditionally removed "-z,defs" from CMAKE_SHARED_LINKER_FLAGS in
    # code_common_standalone_build_config_llvm within
    # CodeSharedCMakeConfig.cmake, where it was added by a call to
    # HandleLLVMOptions.
    #
    # Rather than applying it to all targets and libraries, we here add it
    # back to supported targets and libraries only.  This is needed for ELF
    # targets only; however, RemoteMirror needs to build with undefined
    # symbols.
    if(CODE_SDK_${sdk}_OBJECT_FORMAT STREQUAL "ELF" AND
       NOT name STREQUAL "codeRemoteMirror")
      list(APPEND codelib_link_flags_all "-Wl,-z,defs")
    endif()
    # Setting back linker flags which are not supported when making Android build on macOS cross-compile host.
    if(CODELIB_SHARED AND sdk IN_LIST CODE_DARWIN_PLATFORMS)
      list(APPEND codelib_link_flags_all "-dynamiclib -Wl,-headerpad_max_install_names")
    endif()

    set(sdk_supported_archs
      ${CODE_SDK_${sdk}_ARCHITECTURES}
      ${CODE_SDK_${sdk}_MODULE_ARCHITECTURES})
    list(REMOVE_DUPLICATES sdk_supported_archs)

    # For each architecture supported by this SDK
    foreach(arch ${sdk_supported_archs})
      # Configure variables for this subdirectory.
      set(VARIANT_SUFFIX "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
      set(VARIANT_NAME "${name}${VARIANT_SUFFIX}")
      set(MODULE_VARIANT_SUFFIX "-codemodule${VARIANT_SUFFIX}")
      set(MODULE_VARIANT_NAME "${name}${MODULE_VARIANT_SUFFIX}")

      # Configure macCatalyst flavor variables
      if(DEFINED maccatalyst_build_flavor)
        set(maccatalyst_variant_suffix "-${CODE_SDK_MACCATALYST_LIB_SUBDIR}-${arch}")
        set(maccatalyst_variant_name "${name}${maccatalyst_variant_suffix}")

        set(maccatalyst_module_variant_suffix "-codemodule${maccatalyst_variant_suffix}")
        set(maccatalyst_module_variant_name "${name}${maccatalyst_module_variant_suffix}")
      endif()

      # Map dependencies over to the appropriate variants.
      set(codelib_link_libraries)
      foreach(lib ${CODELIB_LINK_LIBRARIES})
        if(TARGET "${lib}${VARIANT_SUFFIX}")
          list(APPEND codelib_link_libraries "${lib}${VARIANT_SUFFIX}")
        else()
          list(APPEND codelib_link_libraries "${lib}")
        endif()
      endforeach()

      # Code compiles depend on code modules, while links depend on
      # linked libraries.  Find targets for both of these here.
      set(codelib_module_dependency_targets)
      set(codelib_private_link_libraries_targets)

      if(NOT BUILD_STANDALONE)
        foreach(mod ${codelib_module_depends_flattened})
          if(DEFINED maccatalyst_build_flavor)
            if(maccatalyst_build_flavor STREQUAL "zippered")
              # Zippered libraries are dependent on both the macCatalyst and normal macOS
              # modules of their dependencies (which themselves must be zippered).
              list(APPEND codelib_module_dependency_targets
                   "code${mod}${maccatalyst_module_variant_suffix}")
              list(APPEND codelib_module_dependency_targets
                   "code${mod}${MODULE_VARIANT_SUFFIX}")

              # Zippered libraries link against their zippered library targets, which
              # live (and are built in) the same location as normal macOS libraries.
              list(APPEND codelib_private_link_libraries_targets
                "code${mod}${VARIANT_SUFFIX}")
            elseif(maccatalyst_build_flavor STREQUAL "ios-like")
              # iOS-like libraries depend on the macCatalyst modules of their dependencies
              # regardless of whether the target is zippered or macCatalyst only.
              list(APPEND codelib_module_dependency_targets
                   "code${mod}${maccatalyst_module_variant_suffix}")

              # iOS-like libraries can link against either iOS-like library targets
              # or zippered targets.
              if(mod IN_LIST CODELIB_CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED)
                list(APPEND codelib_private_link_libraries_targets
                    "code${mod}${maccatalyst_variant_suffix}")
              else()
                list(APPEND codelib_private_link_libraries_targets
                    "code${mod}${VARIANT_SUFFIX}")
              endif()
            else()
              list(APPEND codelib_module_dependency_targets
                   "code${mod}${MODULE_VARIANT_SUFFIX}")

              list(APPEND codelib_private_link_libraries_targets
                 "code${mod}${VARIANT_SUFFIX}")
            endif()
            continue()
          endif()

          list(APPEND codelib_module_dependency_targets
              "code${mod}${MODULE_VARIANT_SUFFIX}")

          list(APPEND codelib_private_link_libraries_targets
              "code${mod}${VARIANT_SUFFIX}")
        endforeach()
      endif()

      foreach(lib ${CODELIB_PRIVATE_LINK_LIBRARIES})
        if(TARGET "${lib}${VARIANT_SUFFIX}")
          list(APPEND codelib_private_link_libraries_targets
              "${lib}${VARIANT_SUFFIX}")
        else()
          list(APPEND codelib_private_link_libraries_targets "${lib}")
        endif()
      endforeach()

      # Add PrivateFrameworks, rdar://28466433
      set(codelib_c_compile_flags_all ${CODELIB_C_COMPILE_FLAGS})
      set(codelib_link_flags_all ${CODELIB_LINK_FLAGS})

      # Collect architecture agnostic c compiler flags
      if(sdk STREQUAL "OSX")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_OSX})
      elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_IOS})
      elseif(sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_TVOS})
      elseif(sdk STREQUAL "WATCHOS" OR sdk STREQUAL "WATCHOS_SIMULATOR")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_WATCHOS})
      elseif(sdk STREQUAL "LINUX")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_LINUX})
      elseif(sdk STREQUAL "WINDOWS")
        list(APPEND codelib_c_compile_flags_all
             ${CODELIB_C_COMPILE_FLAGS_WINDOWS})
      endif()

      # Add flags to prepend framework search paths for the parallel framework
      # hierarchy rooted at /System/iOSSupport/...
      # These paths must come before their normal counterparts so that when compiling
      # macCatalyst-only or unzippered-twin overlays the macCatalyst version
      # of a framework is found and not the Mac version.
      if(maccatalyst_build_flavor STREQUAL "ios-like")

        # The path to find iOS-only frameworks (such as UIKit) under macCatalyst.
        set(ios_support_frameworks_path "${CODE_SDK_${sdk}_PATH}/System/iOSSupport/System/Library/Frameworks/")

        list(APPEND codelib_code_compile_flags_all "-Fsystem" "${ios_support_frameworks_path}")
        list(APPEND codelib_c_compile_flags_all "-iframework" "${ios_support_frameworks_path}")
        # We collate -F with the framework path to avoid unwanted deduplication
        # of options by target_compile_options -- this way no undesired
        # side effects are introduced should a new search path be added.
        list(APPEND codelib_link_flags_all "-F${ios_support_frameworks_path}")
      endif()

      if(sdk IN_LIST CODE_DARWIN_PLATFORMS AND CODELIB_IS_SDK_OVERLAY)
        set(codelib_code_compile_private_frameworks_flag "-Fsystem" "${CODE_SDK_${sdk}_ARCH_${arch}_PATH}/System/Library/PrivateFrameworks/")
        foreach(tbd_lib ${CODELIB_CODE_MODULE_DEPENDS_FROM_SDK})
          list(APPEND codelib_link_flags_all "${CODE_SDK_${sdk}_ARCH_${arch}_PATH}/usr/lib/code/libcode${tbd_lib}.tbd")
        endforeach()
      endif()

      set(variant_name "${VARIANT_NAME}")
      set(module_variant_names "${MODULE_VARIANT_NAME}")
      if(maccatalyst_build_flavor STREQUAL "ios-like")
        set(variant_name "${maccatalyst_variant_name}")
        set(module_variant_names "${maccatalyst_module_variant_name}")
      elseif(maccatalyst_build_flavor STREQUAL "zippered")
        # Zippered libraries produce two modules: one for macCatalyst and one for macOS
        # and so need two module targets.
        list(APPEND module_variant_names "${maccatalyst_module_variant_name}")
      endif()

      # Setting back linker flags which are not supported when making Android build on macOS cross-compile host.
      if(CODELIB_SHARED AND sdk STREQUAL "ANDROID")
        list(APPEND codelib_link_flags_all "-shared")
        # TODO: Instead of `lib${name}.so` find variable or target property which already have this value.
        list(APPEND codelib_link_flags_all "-Wl,-soname,lib${name}.so")
      endif()

      if (CODELIB_BACK_DEPLOYMENT_LIBRARY)
        set(back_deployment_library_option BACK_DEPLOYMENT_LIBRARY ${CODELIB_BACK_DEPLOYMENT_LIBRARY})
      else()
        set(back_deployment_library_option)
      endif()

      # If the SDK is static only, always build static instead of dynamic
      if(CODE_SDK_${sdk}_STATIC_ONLY AND CODELIB_SHARED)
        set(shared_keyword)
        set(static_keyword STATIC)
      else()
        set(shared_keyword ${CODELIB_SHARED_keyword})
        set(static_keyword ${CODELIB_STATIC_keyword})
      endif()

      # Add this library variant.
      add_code_target_library_single(
        ${variant_name}
        ${name}
        ${shared_keyword}
        ${static_keyword}
        ${CODELIB_NO_LINK_NAME_keyword}
        ${CODELIB_OBJECT_LIBRARY_keyword}
        ${CODELIB_INSTALL_WITH_SHARED_keyword}
        ${sources}
        MODULE_TARGETS ${module_variant_names}
        SDK ${sdk}
        ARCHITECTURE ${arch}
        DEPENDS ${CODELIB_DEPENDS}
        LINK_LIBRARIES ${codelib_link_libraries}
        FRAMEWORK_DEPENDS ${codelib_framework_depends_flattened}
        FRAMEWORK_DEPENDS_WEAK ${CODELIB_FRAMEWORK_DEPENDS_WEAK}
        FILE_DEPENDS ${CODELIB_FILE_DEPENDS} ${codelib_module_dependency_targets}
        C_COMPILE_FLAGS ${codelib_c_compile_flags_all}
        CODE_COMPILE_FLAGS ${codelib_code_compile_flags_all} ${codelib_code_compile_flags_arch} ${codelib_code_compile_private_frameworks_flag}
        LINK_FLAGS ${codelib_link_flags_all}
        PRIVATE_LINK_LIBRARIES ${codelib_private_link_libraries_targets}
        INCORPORATE_OBJECT_LIBRARIES ${CODELIB_INCORPORATE_OBJECT_LIBRARIES}
        INCORPORATE_OBJECT_LIBRARIES_SHARED_ONLY ${CODELIB_INCORPORATE_OBJECT_LIBRARIES_SHARED_ONLY}
        ${CODELIB_DONT_EMBED_BITCODE_keyword}
        ${CODELIB_IS_RUNTIME_keyword}
        ${CODELIB_IS_RUNTIME_CORE_keyword}
        ${CODELIB_IS_SDK_OVERLAY_keyword}
        ${CODELIB_NOCODERT_keyword}
        DARWIN_INSTALL_NAME_DIR "${CODELIB_DARWIN_INSTALL_NAME_DIR}"
        INSTALL_IN_COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
        DEPLOYMENT_VERSION_OSX "${CODELIB_DEPLOYMENT_VERSION_OSX}"
        DEPLOYMENT_VERSION_MACCATALYST "${CODELIB_DEPLOYMENT_VERSION_MACCATALYST}"
        DEPLOYMENT_VERSION_IOS "${CODELIB_DEPLOYMENT_VERSION_IOS}"
        DEPLOYMENT_VERSION_TVOS "${CODELIB_DEPLOYMENT_VERSION_TVOS}"
        DEPLOYMENT_VERSION_WATCHOS "${CODELIB_DEPLOYMENT_VERSION_WATCHOS}"
        DEPLOYMENT_VERSION_XROS "${CODELIB_DEPLOYMENT_VERSION_XROS}"
        MACCATALYST_BUILD_FLAVOR "${maccatalyst_build_flavor}"
        ${back_deployment_library_option}
        ENABLE_LTO "${CODE_RUNTIME_ENABLE_LTO}"
        GYB_SOURCES ${CODELIB_GYB_SOURCES}
        PREFIX_INCLUDE_DIRS ${CODELIB_PREFIX_INCLUDE_DIRS}
        INSTALL_BINARY_CODEMODULE ${CODELIB_INSTALL_BINARY_CODEMODULE}
      )
    if(NOT CODE_BUILT_STANDALONE AND NOT "${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
      add_dependencies(${VARIANT_NAME} clang)
    endif()

      if(sdk STREQUAL "WINDOWS")
        if(CODE_COMPILER_IS_MSVC_LIKE)
          if (CODE_RUNTIME_MSVC_RUNTIME_LIBRARY MATCHES MultiThreadedDebugDLL)
            target_compile_options(${VARIANT_NAME} PRIVATE /MDd /D_DLL /D_DEBUG)
          elseif (CODE_RUNTIME_MSVC_RUNTIME_LIBRARY MATCHES MultiThreadedDebug)
            target_compile_options(${VARIANT_NAME} PRIVATE /MTd /U_DLL /D_DEBUG)
          elseif (CODE_RUNTIME_MSVC_RUNTIME_LIBRARY MATCHES MultiThreadedDLL)
            target_compile_options(${VARIANT_NAME} PRIVATE /MD /D_DLL /U_DEBUG)
          elseif (CODE_RUNTIME_MSVC_RUNTIME_LIBRARY MATCHES MultiThreaded)
            target_compile_options(${VARIANT_NAME} PRIVATE /MT /U_DLL /U_DEBUG)
          endif()
        endif()
      endif()

      if(NOT CODELIB_OBJECT_LIBRARY)
        # Add dependencies on the (not-yet-created) custom lipo target.
        foreach(DEP ${CODELIB_LINK_LIBRARIES})
          if (NOT "${DEP}" MATCHES "^icucore($|-.*)$" AND
              NOT "${DEP}" MATCHES "^dispatch($|-.*)$" AND
              NOT "${DEP}" MATCHES "^BlocksRuntime($|-.*)$")
            add_dependencies(${VARIANT_NAME}
              "${DEP}-${CODE_SDK_${sdk}_LIB_SUBDIR}")
          endif()
        endforeach()

        if (CODELIB_IS_STDLIB AND CODELIB_STATIC)
          # Add dependencies on the (not-yet-created) custom lipo target.
          foreach(DEP ${CODELIB_LINK_LIBRARIES})
            if (NOT "${DEP}" MATCHES "^icucore($|-.*)$" AND
                NOT "${DEP}" MATCHES "^dispatch($|-.*)$" AND
                NOT "${DEP}" MATCHES "^BlocksRuntime($|-.*)$")
              add_dependencies("${VARIANT_NAME}-static"
                "${DEP}-${CODE_SDK_${sdk}_LIB_SUBDIR}-static")
            endif()
          endforeach()
        endif()

        if(arch IN_LIST CODE_SDK_${sdk}_ARCHITECTURES)
          # Note this thin library.
          list(APPEND THIN_INPUT_TARGETS ${VARIANT_NAME})
        endif()
      endif()
    endforeach()

    # Configure module-only targets
    if(NOT CODE_SDK_${sdk}_ARCHITECTURES
        AND CODE_SDK_${sdk}_MODULE_ARCHITECTURES)
      set(_target "${name}-${CODE_SDK_${sdk}_LIB_SUBDIR}")

      # Create unified sdk target
      add_custom_target("${_target}")

      foreach(_arch ${CODE_SDK_${sdk}_MODULE_ARCHITECTURES})
        set(_variant_suffix "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${_arch}")
        set(_module_variant_name "${name}-codemodule-${_variant_suffix}")

        add_dependencies("${_target}" ${_module_variant_name})

        # Add Code standard library targets as dependencies to the top-level
        # convenience target.
        if(TARGET "code-runtime${_variant_suffix}")
          add_dependencies("code-runtime${_variant_suffix}"
            "${_target}")
        endif()
      endforeach()

      return()
    endif()

    set(library_subdir "${CODE_SDK_${sdk}_LIB_SUBDIR}")
    if(maccatalyst_build_flavor STREQUAL "ios-like")
      set(library_subdir "${CODE_SDK_MACCATALYST_LIB_SUBDIR}")
    endif()

    if(NOT CODELIB_OBJECT_LIBRARY)
      # Determine the name of the universal library.
      if(CODELIB_SHARED AND NOT CODE_SDK_${sdk}_STATIC_ONLY)
        if("${sdk}" STREQUAL "WINDOWS")
          set(UNIVERSAL_LIBRARY_NAME
            "${CODELIB_DIR}/${library_subdir}/${name}.dll")
        elseif(CODELIB_BACK_DEPLOYMENT_LIBRARY)
          set(UNIVERSAL_LIBRARY_NAME
            "${CMAKE_BINARY_DIR}/${CMAKE_CFG_INTDIR}/lib/code-${CODELIB_BACK_DEPLOYMENT_LIBRARY}/${library_subdir}/${CMAKE_SHARED_LIBRARY_PREFIX}${name}${CMAKE_SHARED_LIBRARY_SUFFIX}")
        else()
          set(UNIVERSAL_LIBRARY_NAME
            "${CODELIB_DIR}/${library_subdir}/${CMAKE_SHARED_LIBRARY_PREFIX}${name}${CMAKE_SHARED_LIBRARY_SUFFIX}")
        endif()
      else()
        if(CODE_SDK_${sdk}_STATIC_ONLY)
          set(lib_dir "${CODESTATICLIB_DIR}")
        else()
          set(lib_dir "${CODELIB_DIR}")
        endif()

        if("${sdk}" STREQUAL "WINDOWS")
          set(UNIVERSAL_LIBRARY_NAME
            "${lib_dir}/${library_subdir}/${name}.lib")
        else()
          set(UNIVERSAL_LIBRARY_NAME
            "${lib_dir}/${library_subdir}/${CMAKE_STATIC_LIBRARY_PREFIX}${name}${CMAKE_STATIC_LIBRARY_SUFFIX}")
        endif()
      endif()

      set(lipo_target "${name}-${library_subdir}")
      if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin" AND CODELIB_SHARED)
        set(codesign_arg CODESIGN)
      endif()
      precondition(THIN_INPUT_TARGETS)
      _add_code_lipo_target(SDK
                               ${sdk}
                             TARGET
                               ${lipo_target}
                             OUTPUT
                               ${UNIVERSAL_LIBRARY_NAME}
                             ${codesign_arg}
                             ${THIN_INPUT_TARGETS})

      # Cache universal libraries for dependency purposes
      set(UNIVERSAL_LIBRARY_NAMES_${library_subdir}
        ${UNIVERSAL_LIBRARY_NAMES_${library_subdir}}
        ${lipo_target}
        CACHE INTERNAL "UNIVERSAL_LIBRARY_NAMES_${library_subdir}")

      # Determine the subdirectory where this library will be installed.
      set(resource_dir_sdk_subdir "${CODE_SDK_${sdk}_LIB_SUBDIR}")
      if(maccatalyst_build_flavor STREQUAL "ios-like")
        set(resource_dir_sdk_subdir "${CODE_SDK_MACCATALYST_LIB_SUBDIR}")
      endif()

      precondition(resource_dir_sdk_subdir)

      if((CODELIB_SHARED AND NOT CODE_SDK_${sdk}_STATIC_ONLY)
          OR CODELIB_INSTALL_WITH_SHARED)
        set(resource_dir "code")
        set(file_permissions
            OWNER_READ OWNER_WRITE OWNER_EXECUTE
            GROUP_READ GROUP_EXECUTE
            WORLD_READ WORLD_EXECUTE)
      else()
        set(resource_dir "code_static")
        set(file_permissions
            OWNER_READ OWNER_WRITE
            GROUP_READ
            WORLD_READ)
      endif()

      set(optional_arg)
      if(sdk IN_LIST CODE_DARWIN_PLATFORMS)
        # Allow installation of runtime without building all variants on Darwin.
        set(optional_arg "OPTIONAL")
      endif()

      if(sdk STREQUAL "WINDOWS" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
        add_dependencies(${CODELIB_INSTALL_IN_COMPONENT} ${name}-windows-${CODE_PRIMARY_VARIANT_ARCH})
        code_install_in_component(TARGETS ${name}-windows-${CODE_PRIMARY_VARIANT_ARCH}
                                   RUNTIME
                                     DESTINATION "bin"
                                     COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
                                   LIBRARY
                                     DESTINATION "lib${LLVM_LIBDIR_SUFFIX}/${resource_dir}/${resource_dir_sdk_subdir}/${CODE_PRIMARY_VARIANT_ARCH}"
                                     COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
                                   ARCHIVE
                                     DESTINATION "lib${LLVM_LIBDIR_SUFFIX}/${resource_dir}/${resource_dir_sdk_subdir}/${CODE_PRIMARY_VARIANT_ARCH}"
                                     COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
                                   PERMISSIONS ${file_permissions})
      else()
        # NOTE: ${UNIVERSAL_LIBRARY_NAME} is the output associated with the target
        # ${lipo_target}
        add_dependencies(${CODELIB_INSTALL_IN_COMPONENT} ${lipo_target})

        if (CODELIB_BACK_DEPLOYMENT_LIBRARY)
          # Back-deployment libraries get installed into a versioned directory.
          set(install_dest "lib${LLVM_LIBDIR_SUFFIX}/${resource_dir}-${CODELIB_BACK_DEPLOYMENT_LIBRARY}/${resource_dir_sdk_subdir}")
        else()
          set(install_dest "lib${LLVM_LIBDIR_SUFFIX}/${resource_dir}/${resource_dir_sdk_subdir}")
        endif()

        code_install_in_component(FILES "${UNIVERSAL_LIBRARY_NAME}"
                                   DESTINATION ${install_dest}
                                   COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
                                   PERMISSIONS ${file_permissions}
                                   "${optional_arg}")
      endif()
      if(sdk STREQUAL "WINDOWS")
        foreach(arch ${CODE_SDK_WINDOWS_ARCHITECTURES})
          if(TARGET ${name}-windows-${arch}_IMPLIB)
            get_target_property(import_library ${name}-windows-${arch}_IMPLIB IMPORTED_LOCATION)
            add_dependencies(${CODELIB_INSTALL_IN_COMPONENT} ${name}-windows-${arch}_IMPLIB)
            code_install_in_component(FILES ${import_library}
                                       DESTINATION "lib${LLVM_LIBDIR_SUFFIX}/${resource_dir}/${resource_dir_sdk_subdir}/${arch}"
                                       COMPONENT ${CODELIB_INSTALL_IN_COMPONENT}
                                       PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
          endif()
        endforeach()
      endif()

      code_is_installing_component(
        "${CODELIB_INSTALL_IN_COMPONENT}"
        is_installing)

      # Add the arch-specific library targets to the global exports.
      foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
        set(_variant_name "${name}-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
        if(maccatalyst_build_flavor STREQUAL "ios-like")
          set(_variant_name "${name}-${CODE_SDK_MACCATALYST_LIB_SUBDIR}-${arch}")
        endif()

        if(NOT TARGET "${_variant_name}")
          continue()
        endif()

        if(is_installing)
          set_property(GLOBAL APPEND
            PROPERTY CODE_EXPORTS ${_variant_name})
        else()
          set_property(GLOBAL APPEND
            PROPERTY CODE_BUILDTREE_EXPORTS ${_variant_name})
        endif()
      endforeach()

      # Add the codemodule-only targets to the lipo target dependencies.
      foreach(arch ${CODE_SDK_${sdk}_MODULE_ARCHITECTURES})
        set(_variant_name "${name}-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
        if(maccatalyst_build_flavor STREQUAL "ios-like")
          set(_variant_name "${name}-${CODE_SDK_MACCATALYST_LIB_SUBDIR}-${arch}")
        endif()

        if(NOT TARGET "${_variant_name}")
          continue()
        endif()

        add_dependencies("${lipo_target}" "${_variant_name}")
      endforeach()

      # If we built static variants of the library, create a lipo target for
      # them.
      set(lipo_target_static)
      if (CODELIB_IS_STDLIB AND CODELIB_STATIC AND NOT CODELIB_INSTALL_WITH_SHARED)
        set(THIN_INPUT_TARGETS_STATIC)
        foreach(TARGET ${THIN_INPUT_TARGETS})
          list(APPEND THIN_INPUT_TARGETS_STATIC "${TARGET}-static")
        endforeach()

        set(install_subdir "code_static")
        set(universal_subdir ${CODESTATICLIB_DIR})

        set(lipo_target_static
            "${name}-${library_subdir}-static")
        set(UNIVERSAL_LIBRARY_NAME
            "${universal_subdir}/${library_subdir}/${CMAKE_STATIC_LIBRARY_PREFIX}${name}${CMAKE_STATIC_LIBRARY_SUFFIX}")
        _add_code_lipo_target(SDK
                                 ${sdk}
                               TARGET
                                 ${lipo_target_static}
                               OUTPUT
                                 "${UNIVERSAL_LIBRARY_NAME}"
                               ${THIN_INPUT_TARGETS_STATIC})
        add_dependencies(${CODELIB_INSTALL_IN_COMPONENT} ${lipo_target_static})
        code_install_in_component(FILES "${UNIVERSAL_LIBRARY_NAME}"
                                   DESTINATION "lib${LLVM_LIBDIR_SUFFIX}/${install_subdir}/${resource_dir_sdk_subdir}"
                                   PERMISSIONS
                                     OWNER_READ OWNER_WRITE
                                     GROUP_READ
                                     WORLD_READ
                                   COMPONENT "${CODELIB_INSTALL_IN_COMPONENT}"
                                   "${optional_arg}")
      endif()

      # Add Code standard library targets as dependencies to the top-level
      # convenience target.
      set(FILTERED_UNITTESTS
            codeStdlibCollectionUnittest
            codeStdlibUnicodeUnittest)

      foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
        set(VARIANT_SUFFIX "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
        if(TARGET "code-runtime${VARIANT_SUFFIX}" AND
           TARGET "code-test-runtime${VARIANT_SUFFIX}")
          add_dependencies("code-runtime${VARIANT_SUFFIX}"
              ${lipo_target}
              ${lipo_target_static})
          if(NOT "${name}" IN_LIST FILTERED_UNITTESTS)
            add_dependencies("code-test-runtime${VARIANT_SUFFIX}"
                ${lipo_target}
                ${lipo_target_static})
          endif()
        endif()
      endforeach()
    endif()
  endforeach() # maccatalyst_build_flavors
  endforeach()
endfunction()

# Add an executable compiled for a given variant.
#
# Don't use directly, use add_code_executable and add_code_target_executable
# instead.
#
# See add_code_executable for detailed documentation.
#
# Additional parameters:
#   [SDK sdk]
#     SDK to build for.
#
#   [ARCHITECTURE architecture]
#     Architecture to build for.
#
#   [INSTALL_IN_COMPONENT component]
#     The Code installation component that this executable belongs to.
#     Defaults to never_install.
function(_add_code_target_executable_single name)
  set(options
    NOCODERT)
  set(single_parameter_options
    ARCHITECTURE
    SDK
    INSTALL_IN_COMPONENT)
  set(multiple_parameter_options
    COMPILE_FLAGS
    DEPENDS)
  cmake_parse_arguments(CODEEXE_SINGLE
    "${options}"
    "${single_parameter_options}"
    "${multiple_parameter_options}"
    ${ARGN})

  set(CODEEXE_SINGLE_SOURCES ${CODEEXE_SINGLE_UNPARSED_ARGUMENTS})

  # Check arguments.
  precondition(CODEEXE_SINGLE_SDK MESSAGE "Should specify an SDK")
  precondition(CODEEXE_SINGLE_ARCHITECTURE MESSAGE "Should specify an architecture")

  # Determine compiler flags.
  set(c_compile_flags)
  set(link_flags)

  # Prepare linker search directories.
  set(library_search_directories
        "${CODELIB_DIR}/${CODE_SDK_${CODEEXE_SINGLE_SDK}_LIB_SUBDIR}")

  # Add variant-specific flags.
  _add_target_variant_c_compile_flags(
    SDK "${CODEEXE_SINGLE_SDK}"
    ARCH "${CODEEXE_SINGLE_ARCHITECTURE}"
    BUILD_TYPE "${CMAKE_BUILD_TYPE}"
    ENABLE_ASSERTIONS "${LLVM_ENABLE_ASSERTIONS}"
    ENABLE_LTO "${CODE_RUNTIME_ENABLE_LTO}"
    ANALYZE_CODE_COVERAGE "${CODE_ANALYZE_CODE_COVERAGE}"
    RESULT_VAR_NAME c_compile_flags)
  _add_target_variant_link_flags(
    SDK "${CODEEXE_SINGLE_SDK}"
    ARCH "${CODEEXE_SINGLE_ARCHITECTURE}"
    BUILD_TYPE "${CMAKE_BUILD_TYPE}"
    ENABLE_ASSERTIONS "${LLVM_ENABLE_ASSERTIONS}"
    ENABLE_LTO "${CODE_RUNTIME_ENABLE_LTO}"
    LTO_OBJECT_NAME "${name}-${CODEEXE_SINGLE_SDK}-${CODEEXE_SINGLE_ARCHITECTURE}"
    ANALYZE_CODE_COVERAGE "${CODE_ANALYZE_CODE_COVERAGE}"
    RESULT_VAR_NAME link_flags
    LINK_LIBRARIES_VAR_NAME link_libraries
    LIBRARY_SEARCH_DIRECTORIES_VAR_NAME library_search_directories)

  string(MAKE_C_IDENTIFIER "${name}" module_name)

  if(CODEEXE_SINGLE_SDK STREQUAL "WINDOWS")
    list(APPEND CODEEXE_SINGLE_COMPILE_FLAGS
      -vfsoverlay;"${CODE_WINDOWS_VFS_OVERLAY}";-strict-implicit-module-context;-Xcc;-Xclang;-Xcc;-fbuiltin-headers-in-system-modules)
  endif()

  if ("${CODEEXE_SINGLE_SDK}" STREQUAL "LINUX")
    list(APPEND CODEEXE_SINGLE_COMPILE_FLAGS "-Xcc" "-fno-omit-frame-pointer")
  endif()

  handle_code_sources(
      dependency_target
      unused_module_dependency_target
      unused_sib_dependency_target
      unused_sibopt_dependency_target
      unused_sibgen_dependency_target
      CODEEXE_SINGLE_SOURCES CODEEXE_SINGLE_EXTERNAL_SOURCES ${name}
      DEPENDS
        ${CODEEXE_SINGLE_DEPENDS}
      MODULE_NAME ${module_name}
      SDK ${CODEEXE_SINGLE_SDK}
      ARCHITECTURE ${CODEEXE_SINGLE_ARCHITECTURE}
      COMPILE_FLAGS ${CODEEXE_SINGLE_COMPILE_FLAGS}
      ENABLE_LTO "${CODE_RUNTIME_ENABLE_LTO}"
      INSTALL_IN_COMPONENT "${install_in_component}"
      IS_MAIN)
  add_code_source_group("${CODEEXE_SINGLE_EXTERNAL_SOURCES}")

  add_executable(${name}
      ${CODEEXE_SINGLE_SOURCES}
      ${CODEEXE_SINGLE_EXTERNAL_SOURCES})

  # Darwin may need the compatibility libraries
  set(compatibility_libs)
  if(CODEEXE_SINGLE_SDK IN_LIST CODE_DARWIN_PLATFORMS)
    get_compatibility_libs(
      "${CODEEXE_SINGLE_SDK}"
      "${CODEEXE_SINGLE_ARCHITECTURE}"
      compatibility_libs)
  endif()

  # ELF and COFF need codert
  if(("${CODE_SDK_${CODEEXE_SINGLE_SDK}_OBJECT_FORMAT}" STREQUAL "ELF" OR
      "${CODE_SDK_${CODEEXE_SINGLE_SDK}_OBJECT_FORMAT}" STREQUAL "COFF")
     AND NOT CODEEXE_SINGLE_NOCODERT)
    target_sources(${name}
      PRIVATE
      $<TARGET_OBJECTS:codeImageRegistrationObject${CODE_SDK_${CODEEXE_SINGLE_SDK}_OBJECT_FORMAT}-${CODE_SDK_${CODEEXE_SINGLE_SDK}_LIB_SUBDIR}-${CODEEXE_SINGLE_ARCHITECTURE}>)
  endif()

  add_dependencies_multiple_targets(
      TARGETS "${name}"
      DEPENDS
        ${dependency_target}
        ${compatibility_libs}
        ${LLVM_COMMON_DEPENDS}
        ${CODEEXE_SINGLE_DEPENDS})
  llvm_update_compile_flags("${name}")

  if(CODEEXE_SINGLE_SDK STREQUAL "WINDOWS")
    if(NOT CMAKE_HOST_SYSTEM MATCHES Windows)
      code_windows_include_for_arch(${CODEEXE_SINGLE_ARCHITECTURE}
        ${CODEEXE_SINGLE_ARCHITECTURE}_INCLUDE)
      target_include_directories(${name} SYSTEM PRIVATE
        ${${CODEEXE_SINGLE_ARCHITECTURE}_INCLUDE})
    endif()
    if(NOT CMAKE_C_COMPILER_ID STREQUAL "MSVC")
      # MSVC doesn't support -Xclang. We don't need to manually specify
      # the dependent libraries as `cl` does so.
      target_compile_options(${name} PRIVATE
        "SHELL:-Xclang --dependent-lib=oldnames"
        # TODO(compnerd) handle /MT, /MTd
        "SHELL:-Xclang --dependent-lib=msvcrt$<$<CONFIG:Debug>:d>")
    endif()
  endif()

  target_compile_options(${name} PRIVATE
    ${c_compile_flags})
  target_link_directories(${name} PRIVATE
    ${library_search_directories})
  target_link_options(${name} PRIVATE
    ${link_flags})
  target_link_libraries(${name} PRIVATE
    ${link_libraries})
  if (CODE_PARALLEL_LINK_JOBS)
    set_property(TARGET ${name} PROPERTY JOB_POOL_LINK code_link_job_pool)
  endif()
  if(CODEEXE_SINGLE_SDK IN_LIST CODE_DARWIN_PLATFORMS)
    set_target_properties(${name} PROPERTIES
      BUILD_WITH_INSTALL_RPATH YES
      INSTALL_RPATH "@executable_path/../lib/code/${CODE_SDK_${CODEEXE_SINGLE_SDK}_LIB_SUBDIR};@executable_path/../../../lib/code/${CODE_SDK_${CODEEXE_SINGLE_SDK}_LIB_SUBDIR}")
  elseif(CODE_HOST_VARIANT_SDK STREQUAL "LINUX")
    set_target_properties(${name} PROPERTIES
      BUILD_WITH_INSTALL_RPATH YES
      INSTALL_RPATH "$ORIGIN/../../../lib/code/${CODE_SDK_${CODEEXE_SINGLE_SDK}_LIB_SUBDIR}")
  endif()
  set_output_directory(${name}
      BINARY_DIR ${CODE_RUNTIME_OUTPUT_INTDIR}
      LIBRARY_DIR ${CODE_LIBRARY_OUTPUT_INTDIR})

  # NOTE(compnerd) use the C linker language to invoke `clang` rather than
  # `clang++` as we explicitly link against the C++ runtime.  We were previously
  # actually passing `-noruntime++` to avoid the C++ runtime linkage.
  if(CODEEXE_SINGLE_SDK STREQUAL "ANDROID")
    set_property(TARGET "${name}" PROPERTY
      LINKER_LANGUAGE "C")
  else()
    set_property(TARGET "${name}" PROPERTY
      LINKER_LANGUAGE "CXX")
  endif()

  set_target_properties(${name} PROPERTIES FOLDER "Code executables")
endfunction()

# Conditionally append -static to a name, if that variant is a valid target
function(append_static name result_var_name)
  cmake_parse_arguments(APPEND_TARGET
    "STATIC_CODE_STDLIB"
    ""
    ""
    ${ARGN})
  if(STATIC_CODE_STDLIB)
    if(TARGET "${name}-static")
      set("${result_var_name}" "${name}-static" PARENT_SCOPE)
    else()
      set("${result_var_name}" "${name}" PARENT_SCOPE)
    endif()
  else()
    set("${result_var_name}" "${name}" PARENT_SCOPE)
  endif()
endfunction()

# Add an executable for each target variant. Executables are given suffixes
# with the variant SDK and ARCH.
#
# See add_code_executable for detailed documentation.
function(add_code_target_executable name)
  set(CODEEXE_options
    EXCLUDE_FROM_ALL
    BUILD_WITH_STDLIB
    BUILD_WITH_LIBEXEC
    PREFER_STATIC
    NOCODERT)
  set(CODEEXE_single_parameter_options
    INSTALL_IN_COMPONENT)
  set(CODEEXE_multiple_parameter_options
    DEPENDS
    LINK_LIBRARIES
    CODE_MODULE_DEPENDS
    CODE_MODULE_DEPENDS_CYGWIN
    CODE_MODULE_DEPENDS_FREEBSD
    CODE_MODULE_DEPENDS_FREESTANDING
    CODE_MODULE_DEPENDS_OPENBSD
    CODE_MODULE_DEPENDS_HAIKU
    CODE_MODULE_DEPENDS_IOS
    CODE_MODULE_DEPENDS_LINUX
    CODE_MODULE_DEPENDS_LINUX_STATIC
    CODE_MODULE_DEPENDS_OSX
    CODE_MODULE_DEPENDS_TVOS
    CODE_MODULE_DEPENDS_WASI
    CODE_MODULE_DEPENDS_WATCHOS
    CODE_MODULE_DEPENDS_WINDOWS
    CODE_MODULE_DEPENDS_FROM_SDK
    CODE_MODULE_DEPENDS_MACCATALYST
    CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED
    TARGET_SDKS
    COMPILE_FLAGS
  )

  # Parse the arguments we were given.
  cmake_parse_arguments(CODEEXE_TARGET
    "${CODEEXE_options}"
    "${CODEEXE_single_parameter_options}"
    "${CODEEXE_multiple_parameter_options}"
    ${ARGN})

  set(CODEEXE_TARGET_SOURCES ${CODEEXE_TARGET_UNPARSED_ARGUMENTS})

  if(CODEEXE_TARGET_EXCLUDE_FROM_ALL)
    message(SEND_ERROR "${name} is using EXCLUDE_FROM_ALL which is deprecated.")
  endif()

  if("${CODEEXE_TARGET_INSTALL_IN_COMPONENT}" STREQUAL "")
    set(install_in_component "never_install")
  else()
    set(install_in_component "${CODEEXE_TARGET_INSTALL_IN_COMPONENT}")
  endif()

  # Turn off implicit imports
  list(APPEND CODEEXE_TARGET_COMPILE_FLAGS "-Xfrontend;-disable-implicit-concurrency-module-import")

  if(CODE_ENABLE_EXPERIMENTAL_STRING_PROCESSING)
    list(APPEND CODEEXE_TARGET_COMPILE_FLAGS
                      "-Xfrontend;-disable-implicit-string-processing-module-import")
  endif()

  if(CODE_IMPLICIT_BACKTRACING_IMPORT)
    list(APPEND CODEEXE_TARGET_COMPILE_FLAGS "-Xfrontend;-disable-implicit-backtracing-module-import")
  endif()

  if(CODE_BUILD_STDLIB)
    # All Code executables depend on the standard library.
    list(APPEND CODEEXE_TARGET_CODE_MODULE_DEPENDS Core)
    # All Code executables depend on the codeCodeOnoneSupport library.
    list(APPEND CODEEXE_TARGET_CODE_MODULE_DEPENDS CodeOnoneSupport)
  endif()

  # If target SDKs are not specified, build for all known SDKs.
  if("${CODEEXE_TARGET_TARGET_SDKS}" STREQUAL "")
    set(CODEEXE_TARGET_TARGET_SDKS ${CODE_SDKS})
  endif()
  list_replace(CODEEXE_TARGET_TARGET_SDKS ALL_APPLE_PLATFORMS "${CODE_DARWIN_PLATFORMS}")

  # Support adding a "NOT" on the front to mean all SDKs except the following
  list(LENGTH CODEEXE_TARGET_TARGET_SDKS number_of_target_sdks)
  if(number_of_target_sdks GREATER_EQUAL "1")
    list(GET CODEEXE_TARGET_TARGET_SDKS 0 first_sdk)
    if("${first_sdk}" STREQUAL "NOT")
        list(REMOVE_AT CODEEXE_TARGET_TARGET_SDKS 0)
        list_subtract("${CODE_SDKS}" "${CODEEXE_TARGET_TARGET_SDKS}"
        "CODEEXE_TARGET_TARGET_SDKS")
    endif()
  endif()

  list_intersect(
    "${CODEEXE_TARGET_TARGET_SDKS}" "${CODE_SDKS}" CODEEXE_TARGET_TARGET_SDKS)

  foreach(sdk ${CODEEXE_TARGET_TARGET_SDKS})
    set(THIN_INPUT_TARGETS)

    # Collect architecture agnostic SDK module dependencies
    set(codeexe_module_depends_flattened ${CODEEXE_TARGET_CODE_MODULE_DEPENDS})
    if(sdk STREQUAL "OSX")
      if(DEFINED maccatalyst_build_flavor AND NOT maccatalyst_build_flavor STREQUAL "macos-like")
        list(APPEND codeexe_module_depends_flattened
          ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_MACCATALYST})
        list(APPEND codeexe_module_depends_flattened
          ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED})
      else()
        list(APPEND codeexe_module_depends_flattened
          ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_OSX})
      endif()
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_OSX})
    elseif(sdk STREQUAL "IOS" OR sdk STREQUAL "IOS_SIMULATOR")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_IOS})
    elseif(sdk STREQUAL "TVOS" OR sdk STREQUAL "TVOS_SIMULATOR")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_TVOS})
    elseif(sdk STREQUAL "WATCHOS" OR sdk STREQUAL "WATCHOS_SIMULATOR")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_WATCHOS})
    elseif(sdk STREQUAL "FREESTANDING")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_FREESTANDING})
    elseif(sdk STREQUAL "FREEBSD")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_FREEBSD})
    elseif(sdk STREQUAL "OPENBSD")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_OPENBSD})
    elseif(sdk STREQUAL "LINUX" OR sdk STREQUAL "ANDROID")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_LINUX})
    elseif(sdk STREQUAL "LINUX_STATIC")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_LINUX_STATIC})
    elseif(sdk STREQUAL "CYGWIN")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_CYGWIN})
    elseif(sdk STREQUAL "HAIKU")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_HAIKU})
    elseif(sdk STREQUAL "WASI")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_WASI})
    elseif(sdk STREQUAL "WINDOWS")
      list(APPEND codeexe_module_depends_flattened
        ${CODEEXE_TARGET_CODE_MODULE_DEPENDS_WINDOWS})
    endif()

    foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
      set(VARIANT_SUFFIX "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
      set(VARIANT_NAME "${name}${VARIANT_SUFFIX}")
      set(MODULE_VARIANT_SUFFIX "-codemodule${VARIANT_SUFFIX}")
      set(MODULE_VARIANT_NAME "${name}${MODULE_VARIANT_SUFFIX}")

      # Configure macCatalyst flavor variables
      if(DEFINED maccatalyst_build_flavor)
        set(maccatalyst_variant_suffix "-${CODE_SDK_MACCATALYST_LIB_SUBDIR}-${arch}")
        set(maccatalyst_variant_name "${name}${maccatalyst_variant_suffix}")

        set(maccatalyst_module_variant_suffix "-codemodule${maccatalyst_variant_suffix}")
        set(maccatalyst_module_variant_name "${name}${maccatalyst_module_variant_suffix}")
      endif()

      # Code compiles depend on code modules, while links depend on
      # linked libraries.  Find targets for both of these here.
      set(codeexe_module_dependency_targets)
      set(codeexe_link_libraries_targets)
      foreach(mod ${codeexe_module_depends_flattened})
        if(DEFINED maccatalyst_build_flavor)
          if(maccatalyst_build_flavor STREQUAL "zippered")
            # Zippered libraries are dependent on both the macCatalyst and normal macOS
            # modules of their dependencies (which themselves must be zippered).
            list(APPEND codeexe_module_dependency_targets
              "code${mod}${maccatalyst_module_variant_suffix}")
            list(APPEND codeexe_module_dependency_targets
              "code${mod}${MODULE_VARIANT_SUFFIX}")

            # Zippered libraries link against their zippered library targets, which
            # live (and are built in) the same location as normal macOS libraries.
            list(APPEND codeexe_link_libraries_targets
              "code${mod}${VARIANT_SUFFIX}")
          elseif(maccatalyst_build_flavor STREQUAL "ios-like")
            # iOS-like libraries depend on the macCatalyst modules of their dependencies
            # regardless of whether the target is zippered or macCatalyst only.
            list(APPEND codeexe_module_dependency_targets
              "code${mod}${maccatalyst_module_variant_suffix}")

            # iOS-like libraries can link against either iOS-like library targets
            # or zippered targets.
            if(mod IN_LIST CODEEXE_TARGET_CODE_MODULE_DEPENDS_MACCATALYST_UNZIPPERED)
              list(APPEND codeexe_link_libraries_targets
                "code${mod}${maccatalyst_variant_suffix}")
            else()
              list(APPEND codeexe_link_libraries_targets
                "code${mod}${VARIANT_SUFFIX}")
            endif()
          else()
            list(APPEND codeexe_module_dependency_targets
              "code${mod}${MODULE_VARIANT_SUFFIX}")

            list(APPEND codeexe_link_libraries_targets
              "code${mod}${VARIANT_SUFFIX}")
          endif()
          continue()
        endif()

        list(APPEND codeexe_module_dependency_targets
          "code${mod}${MODULE_VARIANT_SUFFIX}")

        set(library_target "code${mod}${VARIANT_SUFFIX}")
        if(CODEEXE_TARGET_PREFER_STATIC AND TARGET "${library_target}-static")
          set(library_target "${library_target}-static")
        endif()

        list(APPEND codeexe_link_libraries_targets "${library_target}")
      endforeach()

      # Don't add the ${arch} to the suffix.  We want to link against fat
      # libraries.
      _list_add_string_suffix(
          "${CODEEXE_TARGET_DEPENDS}"
          "-${CODE_SDK_${sdk}_LIB_SUBDIR}"
          CODEEXE_TARGET_DEPENDS_with_suffix)

      # Note: we add ${codeexe_link_libraries_targets} to the DEPENDS
      # below because when --bootstrapping=bootstrapping with
      # skip-early-codesyntax, the build system builds the Code compiler
      # but not the standard library during the bootstrap, and then when
      # it tries to build code-backtrace it fails because *the compiler*
      # refers to a libcodeCore.so that can't be found.

      _add_code_target_executable_single(
          ${VARIANT_NAME}
          ${CODEEXE_TARGET_NOCODERT_keyword}
          ${CODEEXE_TARGET_SOURCES}
          DEPENDS
            ${CODEEXE_TARGET_DEPENDS_with_suffix}
            ${codeexe_module_dependency_targets}
            ${codeexe_link_libraries_targets}
          SDK "${sdk}"
          ARCHITECTURE "${arch}"
          COMPILE_FLAGS
            ${CODEEXE_TARGET_COMPILE_FLAGS}
          INSTALL_IN_COMPONENT ${install_in_component})

      _list_add_string_suffix(
          "${CODEEXE_TARGET_LINK_LIBRARIES}"
          "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}"
          CODEEXE_TARGET_LINK_LIBRARIES_TARGETS)
      target_link_libraries(${VARIANT_NAME} PRIVATE
        ${CODEEXE_TARGET_LINK_LIBRARIES_TARGETS}
        ${codeexe_link_libraries_targets})

      if(NOT "${VARIANT_SUFFIX}" STREQUAL "${CODE_PRIMARY_VARIANT_SUFFIX}")
        # By default, don't build executables for target SDKs to avoid building
        # target runtimes.
        set_target_properties(${VARIANT_NAME} PROPERTIES
          EXCLUDE_FROM_ALL TRUE)
      endif()

      if(sdk IN_LIST CODE_APPLE_PLATFORMS)
        # In the past, we relied on unsetting globally
        # CMAKE_OSX_ARCHITECTURES to ensure that CMake would
        # not add the -arch flag
        # This is no longer the case when running on Apple Silicon,
        # when CMake will enforce a default (see
        # https://gitlab.kitware.com/cmake/cmake/-/merge_requests/5291)
        set_property(TARGET ${VARIANT_NAME} PROPERTY OSX_ARCHITECTURES "${arch}")

        add_custom_command(TARGET ${VARIANT_NAME}
          POST_BUILD
          COMMAND "codesign" "-f" "-s" "-" "${CODE_RUNTIME_OUTPUT_INTDIR}/${VARIANT_NAME}")
      endif()

      list(APPEND THIN_INPUT_TARGETS ${VARIANT_NAME})
    endforeach()

    if(CODEEXE_TARGET_BUILD_WITH_LIBEXEC)
      set(library_subdir "${CODE_SDK_${sdk}_LIB_SUBDIR}")
      if(maccatalyst_build_flavor STREQUAL "ios-like")
        set(library_subdir "${CODE_SDK_MACCATALYST_LIB_SUBDIR}")
      endif()

      set(lipo_target_dir "${CODELIBEXEC_DIR}/${library_subdir}")
      set(lipo_suffix "")
    else()
      set(lipo_target_dir "${CODE_RUNTIME_OUTPUT_INTDIR}")
      set(lipo_suffix "-${sdk}")
    endif()

    if("${sdk}" STREQUAL "WINDOWS")
      set(UNIVERSAL_NAME "${lipo_target_dir}/${name}${lipo_suffix}.exe")
    else()
      set(UNIVERSAL_NAME "${lipo_target_dir}/${name}${lipo_suffix}")
    endif()

    set(lipo_target "${name}-${sdk}")
    if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
      set(codesign_arg CODESIGN)
    endif()
    precondition(THIN_INPUT_TARGETS)
    _add_code_lipo_target(SDK
                             ${sdk}
                           TARGET
                             ${lipo_target}
                           OUTPUT
                             ${UNIVERSAL_NAME}
                           ${codesign_arg}
                           ${THIN_INPUT_TARGETS})

    # Determine the subdirectory where this executable will be installed
    set(resource_dir_sdk_subdir "${CODE_SDK_${sdk}_LIB_SUBDIR}")
    if(maccatalyst_build_flavor STREQUAL "ios-like")
      set(resource_dir_sdk_subdir "${CODE_SDK_MACCATALYST_LIB_SUBDIR}")
    endif()

    precondition(resource_dir_sdk_subdir)

    if(sdk STREQUAL "WINDOWS" AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
      add_dependencies(${install_in_component} ${name}-windows-${CODE_PRIMARY_VARIANT_ARCH})
      code_install_in_component(TARGETS ${name}-windows-${CODE_PRIMARY_VARIANT_ARCH}
                                 RUNTIME
                                   DESTINATION "bin"
                                   COMPONENT "${install_in_component}"
                                 LIBRARY
                                   DESTINATION "libexec${LLVM_LIBDIR_SUFFIX}/code/${resource_dir_sdk_subdir}/${CODE_PRIMARY_VARIANT_ARCH}"
                                   COMPONENT "${install_in_component}"
                                 ARCHIVE
                                   DESTINATION "libexec${LLVM_LIBDIR_SUFFIX}/code/${resource_dir_sdk_subdir}/${CODE_PRIMARY_VARIANT_ARCH}"
                                   COMPONENT "${install_in_component}"
                                 PERMISSIONS
                                   OWNER_READ OWNER_WRITE OWNER_EXECUTE
                                   GROUP_READ GROUP_EXECUTE
                                   WORLD_READ WORLD_EXECUTE)
    else()
      add_dependencies(${install_in_component} ${lipo_target})

      set(install_dest "libexec${LLVM_LIBDIR_SUFFIX}/code/${resource_dir_sdk_subdir}")
      code_install_in_component(FILES "${UNIVERSAL_NAME}"
                                   DESTINATION ${install_dest}
                                   COMPONENT "${install_in_component}"
                                 PERMISSIONS
                                   OWNER_READ OWNER_WRITE OWNER_EXECUTE
                                   GROUP_READ GROUP_EXECUTE
                                   WORLD_READ WORLD_EXECUTE
                                 "${optional_arg}")
    endif()

    code_is_installing_component(
      "${install_in_component}"
      is_installing)

    # Add the arch-specific executable targets to the global exports
    foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
      set(VARIANT_SUFFIX "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
      set(VARIANT_NAME "${name}${VARIANT_SUFFIX}")

      if(is_installing)
        set_property(GLOBAL APPEND
          PROPERTY CODE_EXPORTS ${VARIANT_NAME})
      else()
        set_property(GLOBAL APPEND
          PROPERTY CODE_BUILDTREE_EXPORTS ${VARIANT_NAME})
      endif()
    endforeach()

    # Add the lipo target to the top-level convenience targets
    if(CODEEXE_TARGET_BUILD_WITH_STDLIB)
      foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
        set(variant "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
        if(TARGET "code-runtime${VARIANT_SUFFIX}" AND
           TARGET "code-test-runtime${VARIANT_SUFFIX}")
          add_dependencies("code-runtime${variant}" ${lipo_target})
          add_dependencies("code-test-runtime${variant}" ${lipo_target})
        endif()
      endforeach()
    endif()

    if(CODEEXE_TARGET_BUILD_WITH_LIBEXEC)
      foreach(arch ${CODE_SDK_${sdk}_ARCHITECTURES})
        set(variant "-${CODE_SDK_${sdk}_LIB_SUBDIR}-${arch}")
        if(TARGET "code-libexec${variant}")
          add_dependencies("code-libexec${variant}" ${lipo_target})
        endif()
      endforeach()
    endif()

  endforeach()
endfunction()
