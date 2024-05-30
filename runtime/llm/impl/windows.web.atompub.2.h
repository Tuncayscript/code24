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
#ifndef LLM_OS_Web_AtomPub_2_H
#define LLM_OS_Web_AtomPub_2_H
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.Web.Syndication.1.h"
#include "llm/impl/Windows.Web.AtomPub.1.h"
LLM_EXPORT namespace llm::OS::Web::AtomPub
{
    struct __declspec(empty_bases) AtomPubClient : llm::OS::Web::AtomPub::IAtomPubClient
    {
        AtomPubClient(std::nullptr_t) noexcept {}
        AtomPubClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::AtomPub::IAtomPubClient(ptr, take_ownership_from_abi) {}
        AtomPubClient();
        explicit AtomPubClient(llm::OS::Security::Credentials::PasswordCredential const& serverCredential);
    };
    struct __declspec(empty_bases) ResourceCollection : llm::OS::Web::AtomPub::IResourceCollection
    {
        ResourceCollection(std::nullptr_t) noexcept {}
        ResourceCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::AtomPub::IResourceCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServiceDocument : llm::OS::Web::AtomPub::IServiceDocument
    {
        ServiceDocument(std::nullptr_t) noexcept {}
        ServiceDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::AtomPub::IServiceDocument(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Workspace : llm::OS::Web::AtomPub::IWorkspace
    {
        Workspace(std::nullptr_t) noexcept {}
        Workspace(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::AtomPub::IWorkspace(ptr, take_ownership_from_abi) {}
    };
}
#endif
