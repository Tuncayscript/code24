/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


// values used by math functions -- IEEE 754 float version

#if defined(_M_CEE_PURE)
#if defined(MRTDLL)
#undef MRTDLL
#endif
#endif

#include "xmath.hpp"
// macros
#define NBITS (16 + _FOFF)

#define INIT(w0) \
    { 0, w0 }
#define INIT2(w0, w1) \
    { w1, w0 }

_EXTERN_C_UNLESS_PURE

// static data
extern /* const */ _Dconst _FDenorm = {INIT2(0, 1)};
extern const _Dconst _FEps          = {INIT((_FBIAS - NBITS - 1) << _FOFF)};
extern /* const */ _Dconst _FInf    = {INIT(_FMAX << _FOFF)};
extern /* const */ _Dconst _FNan    = {INIT((_FMAX << _FOFF) | (1 << (_FOFF - 1)))};
extern /* const */ _Dconst _FSnan   = {INIT2(_FMAX << _FOFF, 1)};
extern const _Dconst _FRteps        = {INIT((_FBIAS - NBITS / 2) << _FOFF)};

extern const float _FXbig = (NBITS + 2) * 0.347f;

_END_EXTERN_C_UNLESS_PURE
