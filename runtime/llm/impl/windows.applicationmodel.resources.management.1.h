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
#ifndef LLM_OS_ApplicationModel_Resources_Management_1_H
#define LLM_OS_ApplicationModel_Resources_Management_1_H
#include "llm/impl/Windows.ApplicationModel.Resources.Management.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources::Management
{
    struct __declspec(empty_bases) IIndexedResourceCandidate :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIndexedResourceCandidate>
    {
        IIndexedResourceCandidate(std::nullptr_t = nullptr) noexcept {}
        IIndexedResourceCandidate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIndexedResourceQualifier :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIndexedResourceQualifier>
    {
        IIndexedResourceQualifier(std::nullptr_t = nullptr) noexcept {}
        IIndexedResourceQualifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceIndexer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceIndexer>
    {
        IResourceIndexer(std::nullptr_t = nullptr) noexcept {}
        IResourceIndexer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceIndexerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceIndexerFactory>
    {
        IResourceIndexerFactory(std::nullptr_t = nullptr) noexcept {}
        IResourceIndexerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceIndexerFactory2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceIndexerFactory2>
    {
        IResourceIndexerFactory2(std::nullptr_t = nullptr) noexcept {}
        IResourceIndexerFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
