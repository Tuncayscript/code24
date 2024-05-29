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
#ifndef LLM_OS_ApplicationModel_Resources_1_H
#define LLM_OS_ApplicationModel_Resources_1_H
#include "llm/impl/Windows.ApplicationModel.Resources.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources
{
    struct __declspec(empty_bases) IResourceLoader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoader>
    {
        IResourceLoader(std::nullptr_t = nullptr) noexcept {}
        IResourceLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoader2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoader2>
    {
        IResourceLoader2(std::nullptr_t = nullptr) noexcept {}
        IResourceLoader2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoaderFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoaderFactory>
    {
        IResourceLoaderFactory(std::nullptr_t = nullptr) noexcept {}
        IResourceLoaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoaderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoaderStatics>
    {
        IResourceLoaderStatics(std::nullptr_t = nullptr) noexcept {}
        IResourceLoaderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoaderStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoaderStatics2>
    {
        IResourceLoaderStatics2(std::nullptr_t = nullptr) noexcept {}
        IResourceLoaderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoaderStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoaderStatics3>
    {
        IResourceLoaderStatics3(std::nullptr_t = nullptr) noexcept {}
        IResourceLoaderStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceLoaderStatics4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceLoaderStatics4>
    {
        IResourceLoaderStatics4(std::nullptr_t = nullptr) noexcept {}
        IResourceLoaderStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
