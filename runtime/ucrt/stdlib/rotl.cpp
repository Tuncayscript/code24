//
// rotl.cpp
//
//      Copyright (c) ITGSS Corporation. All rights reserved.
//
// Defines _lrotl(), _rotl(), and _rotl64(), which perform a rotate-left on an
// integer.
//
#include <stdlib.h>
#include <limits.h>



#pragma function(_lrotl, _rotl, _rotl64)

#if UINT_MAX != 0xffffffff
    #error This source file assumes 32-bit integers
#endif

#if UINT_MAX != ULONG_MAX
    #error This source file assumes sizeof(int) == sizeof(long)
#endif



extern "C" unsigned long __cdecl _lrotl(unsigned long value, int shift)
{
    shift &= 0x1f;
    value = (value >> (0x20 - shift)) | (value << shift);
    return value;
}

extern "C" unsigned __cdecl _rotl(unsigned value, int shift)
{
    shift &= 0x1f;
    value = (value >> (0x20 - shift)) | (value << shift);
    return value;
}

extern "C" unsigned __int64 __cdecl _rotl64(unsigned __int64 value, int shift)
{
    shift &= 0x3f;
    value = (value >> (0x40 - shift)) | (value << shift);
    return value;
}
