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


// instantiations of iomanip

#include <iomanip>
_STD_BEGIN
static void __cdecl rsfun(ios_base& iostr, ios_base::fmtflags mask) { // reset specified format flags
    iostr.setf(ios_base::_Fmtzero, mask);
}

static void __cdecl sifun(ios_base& iostr, ios_base::fmtflags mask) { // set specified format flags
    iostr.setf(ios_base::_Fmtmask, mask);
}

static void __cdecl sbfun(ios_base& iostr, int base) { // set base
    iostr.setf(base == 8    ? ios_base::oct
               : base == 10 ? ios_base::dec
               : base == 16 ? ios_base::hex
                            : ios_base::_Fmtzero,
        ios_base::basefield);
}

static void __cdecl spfun(ios_base& iostr, streamsize prec) { // set precision
    iostr.precision(prec);
}

static void __cdecl swfun(ios_base& iostr, streamsize wide) { // set width
    iostr.width(wide);
}

_MRTIMP2 _Smanip<ios_base::fmtflags> __cdecl resetiosflags(
    ios_base::fmtflags mask) { // manipulator to reset format flags
    return _Smanip<ios_base::fmtflags>(&rsfun, mask);
}

_MRTIMP2 _Smanip<ios_base::fmtflags> __cdecl setiosflags(ios_base::fmtflags mask) { // manipulator to set format flags
    return _Smanip<ios_base::fmtflags>(&sifun, mask);
}

_MRTIMP2 _Smanip<int> __cdecl setbase(int base) { // manipulator to set base
    return _Smanip<int>(&sbfun, base);
}

_MRTIMP2 _Smanip<streamsize> __cdecl setprecision(streamsize prec) { // manipulator to set precision
    return _Smanip<streamsize>(&spfun, prec);
}

_MRTIMP2 _Smanip<streamsize> __cdecl setw(streamsize wide) { // manipulator to set width
    return _Smanip<streamsize>(&swfun, wide);
}
_STD_END
