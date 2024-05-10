#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

#include "runtime/visibility.h"

#ifdef STRICT_MACOS_X
#	define CODE_NONPORTABLE __attribute__((error("Function not supported by the runtime")))
#else
#	define CODE_NONPORTABLE
#endif

#if !defined(__DEPRECATE_DIRECT_ACCESS) || defined(__CODE_LEGACY_GNU_MODE__) || defined(__CODE_RUNTIME_INTERNAL__)
#	define CODE_DEPRECATED
#else
#	define CODE_DEPRECATED __attribute__((deprecated))
#endif

#ifdef ERROR_UNSUPPORTED_RUNTIME_FUNCTIONS
#	define CODE_RUNTIME_UNSUPPORTED(x) \
		__attribute__((error(x " not supported by this runtime")))
#else
#	define OBJC_GNUSTEP_RUNTIME_UNSUPPORTED(x)
#endif

