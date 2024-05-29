/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_Foundation_Numerics_0_H
#define LLM_OS_Foundation_Numerics_0_H
LLM_EXPORT namespace llm::OS::Foundation::Numerics
{
    struct Rational;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Foundation::Numerics::Rational>{ using type = struct_category<uint32_t, uint32_t>; };
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Numerics::Rational> = L"Windows.Foundation.Numerics.Rational";
    struct struct_Windows_Foundation_Numerics_Rational
    {
        uint32_t Numerator;
        uint32_t Denominator;
    };
    template <> struct abi<Windows::Foundation::Numerics::Rational>
    {
        using type = struct_Windows_Foundation_Numerics_Rational;
    };
}
#endif
