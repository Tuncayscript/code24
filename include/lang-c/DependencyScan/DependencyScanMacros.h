#ifdef  __cplusplus
# define LANGSCAN_BEGIN_DECLS  extern "C" {
# define LANGSCAN_END_DECLS    }
#else
# define LANGSCAN_BEGIN_DECLS
# define LANGSCAN_END_DECLS
#endif

#ifndef LANGSCAN_PUBLIC
# ifdef _WIN32
#  ifdef libLangScan_EXPORTS
#    define LANGSCAN_PUBLIC __declspec(dllexport)
#  else
#    define LANGSCAN_PUBLIC __declspec(dllimport)
#  endif
# else
#  define LANGSCAN_PUBLIC
# endif
#endif
