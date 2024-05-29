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
#ifndef LLM_OS_Globalization_NumberFormatting_2_H
#define LLM_OS_Globalization_NumberFormatting_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.NumberFormatting.1.h"
LLM_EXPORT namespace llm:OS::Globalization::NumberFormatting
{
    struct __declspec(empty_bases) CurrencyFormatter : llm:OS::Globalization::NumberFormatting::ICurrencyFormatter,
        impl::require<CurrencyFormatter, llm:OS::Globalization::NumberFormatting::ICurrencyFormatter2, llm:OS::Globalization::NumberFormatting::ISignificantDigitsOption, llm:OS::Globalization::NumberFormatting::INumberRounderOption, llm:OS::Globalization::NumberFormatting::ISignedZeroOption>
    {
        CurrencyFormatter(std::nullptr_t) noexcept {}
        CurrencyFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::ICurrencyFormatter(ptr, take_ownership_from_abi) {}
        explicit CurrencyFormatter(param::hstring const& currencyCode);
        CurrencyFormatter(param::hstring const& currencyCode, param::iterable<hstring> const& languages, param::hstring const& geographicRegion);
    };
    struct __declspec(empty_bases) DecimalFormatter : llm:OS::Globalization::NumberFormatting::INumberFormatter,
        impl::require<DecimalFormatter, llm:OS::Globalization::NumberFormatting::INumberFormatterOptions, llm:OS::Globalization::NumberFormatting::INumberFormatter2, llm:OS::Globalization::NumberFormatting::INumberParser, llm:OS::Globalization::NumberFormatting::ISignificantDigitsOption, llm:OS::Globalization::NumberFormatting::INumberRounderOption, llm:OS::Globalization::NumberFormatting::ISignedZeroOption>
    {
        DecimalFormatter(std::nullptr_t) noexcept {}
        DecimalFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumberFormatter(ptr, take_ownership_from_abi) {}
        DecimalFormatter();
        DecimalFormatter(param::iterable<hstring> const& languages, param::hstring const& geographicRegion);
    };
    struct __declspec(empty_bases) IncrementNumberRounder : llm:OS::Globalization::NumberFormatting::INumberRounder,
        impl::require<IncrementNumberRounder, llm:OS::Globalization::NumberFormatting::IIncrementNumberRounder>
    {
        IncrementNumberRounder(std::nullptr_t) noexcept {}
        IncrementNumberRounder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumberRounder(ptr, take_ownership_from_abi) {}
        IncrementNumberRounder();
    };
    struct __declspec(empty_bases) NumeralSystemTranslator : llm:OS::Globalization::NumberFormatting::INumeralSystemTranslator
    {
        NumeralSystemTranslator(std::nullptr_t) noexcept {}
        NumeralSystemTranslator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumeralSystemTranslator(ptr, take_ownership_from_abi) {}
        NumeralSystemTranslator();
        explicit NumeralSystemTranslator(param::iterable<hstring> const& languages);
    };
    struct __declspec(empty_bases) PercentFormatter : llm:OS::Globalization::NumberFormatting::INumberFormatter,
        impl::require<PercentFormatter, llm:OS::Globalization::NumberFormatting::INumberFormatterOptions, llm:OS::Globalization::NumberFormatting::INumberFormatter2, llm:OS::Globalization::NumberFormatting::INumberParser, llm:OS::Globalization::NumberFormatting::ISignificantDigitsOption, llm:OS::Globalization::NumberFormatting::INumberRounderOption, llm:OS::Globalization::NumberFormatting::ISignedZeroOption>
    {
        PercentFormatter(std::nullptr_t) noexcept {}
        PercentFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumberFormatter(ptr, take_ownership_from_abi) {}
        PercentFormatter();
        PercentFormatter(param::iterable<hstring> const& languages, param::hstring const& geographicRegion);
    };
    struct __declspec(empty_bases) PermilleFormatter : llm:OS::Globalization::NumberFormatting::INumberFormatter,
        impl::require<PermilleFormatter, llm:OS::Globalization::NumberFormatting::INumberFormatterOptions, llm:OS::Globalization::NumberFormatting::INumberFormatter2, llm:OS::Globalization::NumberFormatting::INumberParser, llm:OS::Globalization::NumberFormatting::ISignificantDigitsOption, llm:OS::Globalization::NumberFormatting::INumberRounderOption, llm:OS::Globalization::NumberFormatting::ISignedZeroOption>
    {
        PermilleFormatter(std::nullptr_t) noexcept {}
        PermilleFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumberFormatter(ptr, take_ownership_from_abi) {}
        PermilleFormatter();
        PermilleFormatter(param::iterable<hstring> const& languages, param::hstring const& geographicRegion);
    };
    struct __declspec(empty_bases) SignificantDigitsNumberRounder : llm:OS::Globalization::NumberFormatting::INumberRounder,
        impl::require<SignificantDigitsNumberRounder, llm:OS::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>
    {
        SignificantDigitsNumberRounder(std::nullptr_t) noexcept {}
        SignificantDigitsNumberRounder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::NumberFormatting::INumberRounder(ptr, take_ownership_from_abi) {}
        SignificantDigitsNumberRounder();
    };
}
#endif
