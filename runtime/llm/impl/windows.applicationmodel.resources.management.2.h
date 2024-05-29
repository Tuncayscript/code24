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
#ifndef LLM_OS_ApplicationModel_Resources_Management_2_H
#define LLM_OS_ApplicationModel_Resources_Management_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.ApplicationModel.Resources.Management.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources::Management
{
    struct __declspec(empty_bases) IndexedResourceCandidate : llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate
    {
        IndexedResourceCandidate(std::nullptr_t) noexcept {}
        IndexedResourceCandidate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Management::IIndexedResourceCandidate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IndexedResourceQualifier : llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier
    {
        IndexedResourceQualifier(std::nullptr_t) noexcept {}
        IndexedResourceQualifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Management::IIndexedResourceQualifier(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceIndexer : llm::OS::ApplicationModel::Resources::Management::IResourceIndexer
    {
        ResourceIndexer(std::nullptr_t) noexcept {}
        ResourceIndexer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Management::IResourceIndexer(ptr, take_ownership_from_abi) {}
        explicit ResourceIndexer(llm::OS::Foundation::Uri const& projectRoot);
        ResourceIndexer(llm::OS::Foundation::Uri const& projectRoot, llm::OS::Foundation::Uri const& extensionDllPath);
    };
}
#endif
