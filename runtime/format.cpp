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


// Implements a win32 API wrapper for <format>

#include <__msvc_xlocinfo_types.hpp>
#include <xfilesystem_abi.h>

#include <Windows.h>

static_assert(__std_code_page::_Acp == __std_code_page{CP_ACP});

extern "C" [[nodiscard]] __std_win_error __stdcall __std_get_cvt(
    const __std_code_page _Codepage, _Cvtvec* const _Pcvt) noexcept {
    // get conversion info for an arbitrary codepage
    *_Pcvt = {};

    CPINFOEXW _Info{};
    const DWORD _Flags = 0; // reserved, must be zero
    if (!GetCPInfoExW(static_cast<UINT>(_Codepage), _Flags, &_Info)) {
        // NB: the only documented failure mode for GetCPInfoExW is ERROR_INVALID_PARAMETER,
        // so in practice it should never fail for CP_ACP.
        return __std_win_error{GetLastError()};
    }

    _Pcvt->_Page     = _Info.CodePage;
    _Pcvt->_Mbcurmax = _Info.MaxCharSize;

    for (int _Idx = 0; _Idx < MAX_LEADBYTES; _Idx += 2) {
        if (_Info.LeadByte[_Idx] == 0 && _Info.LeadByte[_Idx + 1] == 0) {
            break;
        }

        for (unsigned char _First = _Info.LeadByte[_Idx], _Last = _Info.LeadByte[_Idx + 1]; _First != _Last; ++_First) {
            _Pcvt->_Isleadbyte[_First >> 3] |= 1u << (_First & 0b111u);
        }
    }

    return __std_win_error::_Success;
}
