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
#ifndef LLM_OS_Web_Syndication_1_H
#define LLM_OS_Web_Syndication_1_H
#include "llm/impl/Windows.Web.Syndication.0.h"
LLM_EXPORT namespace llm::OS::Web::Syndication
{
    struct __declspec(empty_bases) ISyndicationAttribute :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationAttribute>
    {
        ISyndicationAttribute(std::nullptr_t = nullptr) noexcept {}
        ISyndicationAttribute(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationAttributeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationAttributeFactory>
    {
        ISyndicationAttributeFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationAttributeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationCategory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationCategory>,
        impl::require<llm::OS::Web::Syndication::ISyndicationCategory, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationCategory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationCategory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationCategoryFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationCategoryFactory>
    {
        ISyndicationCategoryFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationCategoryFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationClient :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationClient>
    {
        ISyndicationClient(std::nullptr_t = nullptr) noexcept {}
        ISyndicationClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationClientFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationClientFactory>
    {
        ISyndicationClientFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationClientFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationContent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationContent>,
        impl::require<llm::OS::Web::Syndication::ISyndicationContent, llm::OS::Web::Syndication::ISyndicationNode, llm::OS::Web::Syndication::ISyndicationText>
    {
        ISyndicationContent(std::nullptr_t = nullptr) noexcept {}
        ISyndicationContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationContentFactory>
    {
        ISyndicationContentFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationErrorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationErrorStatics>
    {
        ISyndicationErrorStatics(std::nullptr_t = nullptr) noexcept {}
        ISyndicationErrorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationFeed :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationFeed>,
        impl::require<llm::OS::Web::Syndication::ISyndicationFeed, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationFeed(std::nullptr_t = nullptr) noexcept {}
        ISyndicationFeed(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationFeedFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationFeedFactory>
    {
        ISyndicationFeedFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationFeedFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationGenerator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationGenerator>
    {
        ISyndicationGenerator(std::nullptr_t = nullptr) noexcept {}
        ISyndicationGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationGeneratorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationGeneratorFactory>
    {
        ISyndicationGeneratorFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationGeneratorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationItem>,
        impl::require<llm::OS::Web::Syndication::ISyndicationItem, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationItem(std::nullptr_t = nullptr) noexcept {}
        ISyndicationItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationItemFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationItemFactory>
    {
        ISyndicationItemFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationItemFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationLink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationLink>,
        impl::require<llm::OS::Web::Syndication::ISyndicationLink, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationLink(std::nullptr_t = nullptr) noexcept {}
        ISyndicationLink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationLinkFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationLinkFactory>
    {
        ISyndicationLinkFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationLinkFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationNode :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationNode>
    {
        ISyndicationNode(std::nullptr_t = nullptr) noexcept {}
        ISyndicationNode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationNodeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationNodeFactory>
    {
        ISyndicationNodeFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationNodeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationPerson :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationPerson>,
        impl::require<llm::OS::Web::Syndication::ISyndicationPerson, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationPerson(std::nullptr_t = nullptr) noexcept {}
        ISyndicationPerson(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationPersonFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationPersonFactory>
    {
        ISyndicationPersonFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationPersonFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationText :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationText>,
        impl::require<llm::OS::Web::Syndication::ISyndicationText, llm::OS::Web::Syndication::ISyndicationNode>
    {
        ISyndicationText(std::nullptr_t = nullptr) noexcept {}
        ISyndicationText(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISyndicationTextFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISyndicationTextFactory>
    {
        ISyndicationTextFactory(std::nullptr_t = nullptr) noexcept {}
        ISyndicationTextFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
