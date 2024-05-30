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
#ifndef LLM_OS_Web_Syndication_2_H
#define LLM_OS_Web_Syndication_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.Web.Syndication.1.h"
LLM_EXPORT namespace llm::OS::Web::Syndication
{
    struct RetrievalProgress
    {
        uint32_t BytesRetrieved;
        uint32_t TotalBytesToRetrieve;
    };
    inline bool operator==(RetrievalProgress const& left, RetrievalProgress const& right) noexcept
    {
        return left.BytesRetrieved == right.BytesRetrieved && left.TotalBytesToRetrieve == right.TotalBytesToRetrieve;
    }
    inline bool operator!=(RetrievalProgress const& left, RetrievalProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct TransferProgress
    {
        uint32_t BytesSent;
        uint32_t TotalBytesToSend;
        uint32_t BytesRetrieved;
        uint32_t TotalBytesToRetrieve;
    };
    inline bool operator==(TransferProgress const& left, TransferProgress const& right) noexcept
    {
        return left.BytesSent == right.BytesSent && left.TotalBytesToSend == right.TotalBytesToSend && left.BytesRetrieved == right.BytesRetrieved && left.TotalBytesToRetrieve == right.TotalBytesToRetrieve;
    }
    inline bool operator!=(TransferProgress const& left, TransferProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) SyndicationAttribute : llm::OS::Web::Syndication::ISyndicationAttribute
    {
        SyndicationAttribute(std::nullptr_t) noexcept {}
        SyndicationAttribute(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationAttribute(ptr, take_ownership_from_abi) {}
        SyndicationAttribute();
        SyndicationAttribute(param::hstring const& attributeName, param::hstring const& attributeNamespace, param::hstring const& attributeValue);
    };
    struct __declspec(empty_bases) SyndicationCategory : llm::OS::Web::Syndication::ISyndicationCategory
    {
        SyndicationCategory(std::nullptr_t) noexcept {}
        SyndicationCategory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationCategory(ptr, take_ownership_from_abi) {}
        SyndicationCategory();
        explicit SyndicationCategory(param::hstring const& term);
        SyndicationCategory(param::hstring const& term, param::hstring const& scheme, param::hstring const& label);
    };
    struct __declspec(empty_bases) SyndicationClient : llm::OS::Web::Syndication::ISyndicationClient
    {
        SyndicationClient(std::nullptr_t) noexcept {}
        SyndicationClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationClient(ptr, take_ownership_from_abi) {}
        SyndicationClient();
        explicit SyndicationClient(llm::OS::Security::Credentials::PasswordCredential const& serverCredential);
    };
    struct __declspec(empty_bases) SyndicationContent : llm::OS::Web::Syndication::ISyndicationContent
    {
        SyndicationContent(std::nullptr_t) noexcept {}
        SyndicationContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationContent(ptr, take_ownership_from_abi) {}
        SyndicationContent();
        SyndicationContent(param::hstring const& text, llm::OS::Web::Syndication::SyndicationTextType const& type);
        explicit SyndicationContent(llm::OS::Foundation::Uri const& sourceUri);
    };
    struct SyndicationError
    {
        SyndicationError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) SyndicationFeed : llm::OS::Web::Syndication::ISyndicationFeed
    {
        SyndicationFeed(std::nullptr_t) noexcept {}
        SyndicationFeed(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationFeed(ptr, take_ownership_from_abi) {}
        SyndicationFeed();
        SyndicationFeed(param::hstring const& title, param::hstring const& subtitle, llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) SyndicationGenerator : llm::OS::Web::Syndication::ISyndicationGenerator,
        impl::require<SyndicationGenerator, llm::OS::Web::Syndication::ISyndicationNode>
    {
        SyndicationGenerator(std::nullptr_t) noexcept {}
        SyndicationGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationGenerator(ptr, take_ownership_from_abi) {}
        SyndicationGenerator();
        explicit SyndicationGenerator(param::hstring const& text);
    };
    struct __declspec(empty_bases) SyndicationItem : llm::OS::Web::Syndication::ISyndicationItem
    {
        SyndicationItem(std::nullptr_t) noexcept {}
        SyndicationItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationItem(ptr, take_ownership_from_abi) {}
        SyndicationItem();
        SyndicationItem(param::hstring const& title, llm::OS::Web::Syndication::SyndicationContent const& content, llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) SyndicationLink : llm::OS::Web::Syndication::ISyndicationLink
    {
        SyndicationLink(std::nullptr_t) noexcept {}
        SyndicationLink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationLink(ptr, take_ownership_from_abi) {}
        SyndicationLink();
        explicit SyndicationLink(llm::OS::Foundation::Uri const& uri);
        SyndicationLink(llm::OS::Foundation::Uri const& uri, param::hstring const& relationship, param::hstring const& title, param::hstring const& mediaType, uint32_t length);
    };
    struct __declspec(empty_bases) SyndicationNode : llm::OS::Web::Syndication::ISyndicationNode
    {
        SyndicationNode(std::nullptr_t) noexcept {}
        SyndicationNode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationNode(ptr, take_ownership_from_abi) {}
        SyndicationNode();
        SyndicationNode(param::hstring const& nodeName, param::hstring const& nodeNamespace, param::hstring const& nodeValue);
    };
    struct __declspec(empty_bases) SyndicationPerson : llm::OS::Web::Syndication::ISyndicationPerson
    {
        SyndicationPerson(std::nullptr_t) noexcept {}
        SyndicationPerson(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationPerson(ptr, take_ownership_from_abi) {}
        SyndicationPerson();
        explicit SyndicationPerson(param::hstring const& name);
        SyndicationPerson(param::hstring const& name, param::hstring const& email, llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) SyndicationText : llm::OS::Web::Syndication::ISyndicationText
    {
        SyndicationText(std::nullptr_t) noexcept {}
        SyndicationText(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Syndication::ISyndicationText(ptr, take_ownership_from_abi) {}
        SyndicationText();
        explicit SyndicationText(param::hstring const& text);
        SyndicationText(param::hstring const& text, llm::OS::Web::Syndication::SyndicationTextType const& type);
    };
}
#endif
