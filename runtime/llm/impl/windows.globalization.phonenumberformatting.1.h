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
#ifndef LLM_OS_Globalization_PhoneNumberFormatting_1_H
#define LLM_OS_Globalization_PhoneNumberFormatting_1_H
#include "llm/impl/Windows.Globalization.PhoneNumberFormatting.0.h"
LLM_EXPORT namespace llm:OS::Globalization::PhoneNumberFormatting
{
    struct __declspec(empty_bases) IPhoneNumberFormatter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNumberFormatter>
    {
        IPhoneNumberFormatter(std::nullptr_t = nullptr) noexcept {}
        IPhoneNumberFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNumberFormatterStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNumberFormatterStatics>
    {
        IPhoneNumberFormatterStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneNumberFormatterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNumberInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNumberInfo>
    {
        IPhoneNumberInfo(std::nullptr_t = nullptr) noexcept {}
        IPhoneNumberInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNumberInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNumberInfoFactory>
    {
        IPhoneNumberInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IPhoneNumberInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNumberInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNumberInfoStatics>
    {
        IPhoneNumberInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneNumberInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
