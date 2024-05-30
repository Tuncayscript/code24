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
#ifndef LLM_OS_UI_Xaml_Resources_1_H
#define LLM_OS_UI_Xaml_Resources_1_H
#include "llm/impl/Windows.UI.Xaml.Resources.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Resources
{
    struct __declspec(empty_bases) ICustomXamlResourceLoader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomXamlResourceLoader>
    {
        ICustomXamlResourceLoader(std::nullptr_t = nullptr) noexcept {}
        ICustomXamlResourceLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomXamlResourceLoaderFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomXamlResourceLoaderFactory>
    {
        ICustomXamlResourceLoaderFactory(std::nullptr_t = nullptr) noexcept {}
        ICustomXamlResourceLoaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomXamlResourceLoaderOverrides :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomXamlResourceLoaderOverrides>
    {
        ICustomXamlResourceLoaderOverrides(std::nullptr_t = nullptr) noexcept {}
        ICustomXamlResourceLoaderOverrides(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomXamlResourceLoaderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomXamlResourceLoaderStatics>
    {
        ICustomXamlResourceLoaderStatics(std::nullptr_t = nullptr) noexcept {}
        ICustomXamlResourceLoaderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
