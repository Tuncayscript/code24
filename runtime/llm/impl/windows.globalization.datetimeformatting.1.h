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
#ifndef LLM_OS_Globalization_DateTimeFormatting_1_H
#define LLM_OS_Globalization_DateTimeFormatting_1_H
#include "llm/impl/Windows.Globalization.DateTimeFormatting.0.h"
LLM_EXPORT namespace llm:OS::Globalization::DateTimeFormatting
{
    struct __declspec(empty_bases) IDateTimeFormatter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDateTimeFormatter>
    {
        IDateTimeFormatter(std::nullptr_t = nullptr) noexcept {}
        IDateTimeFormatter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDateTimeFormatter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDateTimeFormatter2>
    {
        IDateTimeFormatter2(std::nullptr_t = nullptr) noexcept {}
        IDateTimeFormatter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDateTimeFormatterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDateTimeFormatterFactory>
    {
        IDateTimeFormatterFactory(std::nullptr_t = nullptr) noexcept {}
        IDateTimeFormatterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDateTimeFormatterStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDateTimeFormatterStatics>
    {
        IDateTimeFormatterStatics(std::nullptr_t = nullptr) noexcept {}
        IDateTimeFormatterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
