#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

#include <runtime/lowruntime.h>

@interface Object
{
	Class isa;
}
@end
