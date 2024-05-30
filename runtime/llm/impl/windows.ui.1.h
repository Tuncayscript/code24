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
#ifndef LLM_OS_UI_1_H
#define LLM_OS_UI_1_H
#include "llm/impl/Windows.UI.0.h"
LLM_EXPORT namespace llm:OS::UI
{
    struct __declspec(empty_bases) IColorHelper :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorHelper>
    {
        IColorHelper(std::nullptr_t = nullptr) noexcept {}
        IColorHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColorHelperStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorHelperStatics>
    {
        IColorHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IColorHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColorHelperStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorHelperStatics2>
    {
        IColorHelperStatics2(std::nullptr_t = nullptr) noexcept {}
        IColorHelperStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColors :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColors>
    {
        IColors(std::nullptr_t = nullptr) noexcept {}
        IColors(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IColorsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IColorsStatics>
    {
        IColorsStatics(std::nullptr_t = nullptr) noexcept {}
        IColorsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUIContentRoot :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUIContentRoot>
    {
        IUIContentRoot(std::nullptr_t = nullptr) noexcept {}
        IUIContentRoot(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUIContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUIContext>
    {
        IUIContext(std::nullptr_t = nullptr) noexcept {}
        IUIContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
