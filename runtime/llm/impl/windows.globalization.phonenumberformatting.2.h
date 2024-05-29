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
#ifndef LLM_OS_Globalization_PhoneNumberFormatting_2_H
#define LLM_OS_Globalization_PhoneNumberFormatting_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Globalization.PhoneNumberFormatting.1.h"
LLM_EXPORT namespace llm:OS::Globalization::PhoneNumberFormatting
{
    struct __declspec(empty_bases) PhoneNumberFormatter : llm:OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter
    {
        PhoneNumberFormatter(std::nullptr_t) noexcept {}
        PhoneNumberFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter(ptr, take_ownership_from_abi) {}
        PhoneNumberFormatter();
        static auto TryCreate(param::hstring const& regionCode, llm:OS::Globalization::PhoneNumberFormatting::PhoneNumberFormatter& phoneNumber);
        static auto GetCountryCodeForRegion(param::hstring const& regionCode);
        static auto GetNationalDirectDialingPrefixForRegion(param::hstring const& regionCode, bool stripNonDigit);
        static auto WrapWithLeftToRightMarkers(param::hstring const& number);
    };
    struct __declspec(empty_bases) PhoneNumberInfo : llm:OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo,
        impl::require<PhoneNumberInfo, llm:OS::Foundation::IStringable>
    {
        PhoneNumberInfo(std::nullptr_t) noexcept {}
        PhoneNumberInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::PhoneNumberFormatting::IPhoneNumberInfo(ptr, take_ownership_from_abi) {}
        explicit PhoneNumberInfo(param::hstring const& number);
        static auto TryParse(param::hstring const& input, llm:OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber);
        static auto TryParse(param::hstring const& input, param::hstring const& regionCode, llm:OS::Globalization::PhoneNumberFormatting::PhoneNumberInfo& phoneNumber);
    };
}
#endif
