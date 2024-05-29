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
#ifndef LLM_OS_ApplicationModel_Resources_Core_1_H
#define LLM_OS_ApplicationModel_Resources_Core_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.ApplicationModel.Resources.Core.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources::Core
{
    struct __declspec(empty_bases) INamedResource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INamedResource>
    {
        INamedResource(std::nullptr_t = nullptr) noexcept {}
        INamedResource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceCandidate :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceCandidate>
    {
        IResourceCandidate(std::nullptr_t = nullptr) noexcept {}
        IResourceCandidate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceCandidate2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceCandidate2>
    {
        IResourceCandidate2(std::nullptr_t = nullptr) noexcept {}
        IResourceCandidate2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceCandidate3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceCandidate3>
    {
        IResourceCandidate3(std::nullptr_t = nullptr) noexcept {}
        IResourceCandidate3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceContext :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceContext>
    {
        IResourceContext(std::nullptr_t = nullptr) noexcept {}
        IResourceContext(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceContextStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceContextStatics>
    {
        IResourceContextStatics(std::nullptr_t = nullptr) noexcept {}
        IResourceContextStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceContextStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceContextStatics2>
    {
        IResourceContextStatics2(std::nullptr_t = nullptr) noexcept {}
        IResourceContextStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceContextStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceContextStatics3>
    {
        IResourceContextStatics3(std::nullptr_t = nullptr) noexcept {}
        IResourceContextStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceContextStatics4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceContextStatics4>
    {
        IResourceContextStatics4(std::nullptr_t = nullptr) noexcept {}
        IResourceContextStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceManager>
    {
        IResourceManager(std::nullptr_t = nullptr) noexcept {}
        IResourceManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceManager2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceManager2>
    {
        IResourceManager2(std::nullptr_t = nullptr) noexcept {}
        IResourceManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceManagerStatics>
    {
        IResourceManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IResourceManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceMap :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceMap>,
        impl::require<llm::OS::ApplicationModel::Resources::Core::IResourceMap, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::ApplicationModel::Resources::Core::NamedResource>>, llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Resources::Core::NamedResource>>
    {
        IResourceMap(std::nullptr_t = nullptr) noexcept {}
        IResourceMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceQualifier :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceQualifier>
    {
        IResourceQualifier(std::nullptr_t = nullptr) noexcept {}
        IResourceQualifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
