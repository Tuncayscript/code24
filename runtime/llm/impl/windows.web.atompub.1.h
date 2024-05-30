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
#ifndef LLM_OS_Web_AtomPub_1_H
#define LLM_OS_Web_AtomPub_1_H
#include "llm/impl/Windows.Web.Syndication.0.h"
#include "llm/impl/Windows.Web.AtomPub.0.h"
LLM_EXPORT namespace llm::OS::Web::AtomPub
{
    struct __declspec(empty_bases) IAtomPubClient :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAtomPubClient>,
        impl::require<llm::OS::Web::AtomPub::IAtomPubClient, llm::OS::Web::Syndication::ISyndicationClient>
    {
        IAtomPubClient(std::nullptr_t = nullptr) noexcept {}
        IAtomPubClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAtomPubClientFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAtomPubClientFactory>
    {
        IAtomPubClientFactory(std::nullptr_t = nullptr) noexcept {}
        IAtomPubClientFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IResourceCollection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IResourceCollection>,
        impl::require<llm::OS::Web::AtomPub::IResourceCollection, llm::OS::Web::Syndication::ISyndicationNode>
    {
        IResourceCollection(std::nullptr_t = nullptr) noexcept {}
        IResourceCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServiceDocument :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IServiceDocument>,
        impl::require<llm::OS::Web::AtomPub::IServiceDocument, llm::OS::Web::Syndication::ISyndicationNode>
    {
        IServiceDocument(std::nullptr_t = nullptr) noexcept {}
        IServiceDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWorkspace :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWorkspace>,
        impl::require<llm::OS::Web::AtomPub::IWorkspace, llm::OS::Web::Syndication::ISyndicationNode>
    {
        IWorkspace(std::nullptr_t = nullptr) noexcept {}
        IWorkspace(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
