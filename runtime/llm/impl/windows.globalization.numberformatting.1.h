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
#ifndef LLM_OS_Globalization_NumberFormatting_1_H
#define LLM_OS_Globalization_NumberFormatting_1_H
#include "llm/impl/Windows.Globalization.NumberFormatting.0.h"
LLM_EXPORT namespace llm:OS::Globalization::NumberFormatting
{
    struct __declspec(empty_bases) ICurrencyFormatter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICurrencyFormatter>,
        impl::require<llm:OS::Globalization::NumberFormatting::ICurrencyFormatter, llm:OS::Globalization::NumberFormatting::INumberFormatterOptions, llm:OS::Globalization::NumberFormatting::INumberFormatter, llm:OS::Globalization::NumberFormatting::INumberFormatter2, llm:OS::Globalization::NumberFormatting::INumberParser>
    {
        ICurrencyFormatter(std::nullptr_t = nullptr) noexcept {}
        ICurrencyFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrencyFormatter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICurrencyFormatter2>
    {
        ICurrencyFormatter2(std::nullptr_t = nullptr) noexcept {}
        ICurrencyFormatter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICurrencyFormatterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICurrencyFormatterFactory>
    {
        ICurrencyFormatterFactory(std::nullptr_t = nullptr) noexcept {}
        ICurrencyFormatterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDecimalFormatterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDecimalFormatterFactory>
    {
        IDecimalFormatterFactory(std::nullptr_t = nullptr) noexcept {}
        IDecimalFormatterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIncrementNumberRounder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIncrementNumberRounder>
    {
        IIncrementNumberRounder(std::nullptr_t = nullptr) noexcept {}
        IIncrementNumberRounder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberFormatter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberFormatter>
    {
        INumberFormatter(std::nullptr_t = nullptr) noexcept {}
        INumberFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberFormatter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberFormatter2>
    {
        INumberFormatter2(std::nullptr_t = nullptr) noexcept {}
        INumberFormatter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberFormatterOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberFormatterOptions>
    {
        INumberFormatterOptions(std::nullptr_t = nullptr) noexcept {}
        INumberFormatterOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberParser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberParser>
    {
        INumberParser(std::nullptr_t = nullptr) noexcept {}
        INumberParser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberRounder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberRounder>
    {
        INumberRounder(std::nullptr_t = nullptr) noexcept {}
        INumberRounder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumberRounderOption :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumberRounderOption>
    {
        INumberRounderOption(std::nullptr_t = nullptr) noexcept {}
        INumberRounderOption(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumeralSystemTranslator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumeralSystemTranslator>
    {
        INumeralSystemTranslator(std::nullptr_t = nullptr) noexcept {}
        INumeralSystemTranslator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INumeralSystemTranslatorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INumeralSystemTranslatorFactory>
    {
        INumeralSystemTranslatorFactory(std::nullptr_t = nullptr) noexcept {}
        INumeralSystemTranslatorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPercentFormatterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPercentFormatterFactory>
    {
        IPercentFormatterFactory(std::nullptr_t = nullptr) noexcept {}
        IPercentFormatterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPermilleFormatterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPermilleFormatterFactory>
    {
        IPermilleFormatterFactory(std::nullptr_t = nullptr) noexcept {}
        IPermilleFormatterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISignedZeroOption :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISignedZeroOption>
    {
        ISignedZeroOption(std::nullptr_t = nullptr) noexcept {}
        ISignedZeroOption(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISignificantDigitsNumberRounder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISignificantDigitsNumberRounder>
    {
        ISignificantDigitsNumberRounder(std::nullptr_t = nullptr) noexcept {}
        ISignificantDigitsNumberRounder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISignificantDigitsOption :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISignificantDigitsOption>
    {
        ISignificantDigitsOption(std::nullptr_t = nullptr) noexcept {}
        ISignificantDigitsOption(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
