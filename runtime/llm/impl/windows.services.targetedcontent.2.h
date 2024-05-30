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
#ifndef LLM_OS_Services_TargetedContent_2_H
#define LLM_OS_Services_TargetedContent_2_H
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Services.TargetedContent.1.h"
LLM_EXPORT namespace llm:OS::Services::TargetedContent
{
    struct __declspec(empty_bases) TargetedContentAction : llm:OS::Services::TargetedContent::ITargetedContentAction
    {
        TargetedContentAction(std::nullptr_t) noexcept {}
        TargetedContentAction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentAvailabilityChangedEventArgs : llm:OS::Services::TargetedContent::ITargetedContentAvailabilityChangedEventArgs
    {
        TargetedContentAvailabilityChangedEventArgs(std::nullptr_t) noexcept {}
        TargetedContentAvailabilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentAvailabilityChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentChangedEventArgs : llm:OS::Services::TargetedContent::ITargetedContentChangedEventArgs
    {
        TargetedContentChangedEventArgs(std::nullptr_t) noexcept {}
        TargetedContentChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentCollection : llm:OS::Services::TargetedContent::ITargetedContentCollection
    {
        TargetedContentCollection(std::nullptr_t) noexcept {}
        TargetedContentCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentContainer : llm:OS::Services::TargetedContent::ITargetedContentContainer
    {
        TargetedContentContainer(std::nullptr_t) noexcept {}
        TargetedContentContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentContainer(ptr, take_ownership_from_abi) {}
        static auto GetAsync(param::hstring const& contentId);
    };
    struct __declspec(empty_bases) TargetedContentFile : llm:OS::Storage::Streams::IRandomAccessStreamReference
    {
        TargetedContentFile(std::nullptr_t) noexcept {}
        TargetedContentFile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStreamReference(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentImage : llm:OS::Services::TargetedContent::ITargetedContentImage
    {
        TargetedContentImage(std::nullptr_t) noexcept {}
        TargetedContentImage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentImage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentItem : llm:OS::Services::TargetedContent::ITargetedContentItem
    {
        TargetedContentItem(std::nullptr_t) noexcept {}
        TargetedContentItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentItemState : llm:OS::Services::TargetedContent::ITargetedContentItemState
    {
        TargetedContentItemState(std::nullptr_t) noexcept {}
        TargetedContentItemState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentItemState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentObject : llm:OS::Services::TargetedContent::ITargetedContentObject
    {
        TargetedContentObject(std::nullptr_t) noexcept {}
        TargetedContentObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentObject(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentStateChangedEventArgs : llm:OS::Services::TargetedContent::ITargetedContentStateChangedEventArgs
    {
        TargetedContentStateChangedEventArgs(std::nullptr_t) noexcept {}
        TargetedContentStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentSubscription : llm:OS::Services::TargetedContent::ITargetedContentSubscription
    {
        TargetedContentSubscription(std::nullptr_t) noexcept {}
        TargetedContentSubscription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentSubscription(ptr, take_ownership_from_abi) {}
        static auto GetAsync(param::hstring const& subscriptionId);
        static auto GetOptions(param::hstring const& subscriptionId);
    };
    struct __declspec(empty_bases) TargetedContentSubscriptionOptions : llm:OS::Services::TargetedContent::ITargetedContentSubscriptionOptions
    {
        TargetedContentSubscriptionOptions(std::nullptr_t) noexcept {}
        TargetedContentSubscriptionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentSubscriptionOptions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TargetedContentValue : llm:OS::Services::TargetedContent::ITargetedContentValue
    {
        TargetedContentValue(std::nullptr_t) noexcept {}
        TargetedContentValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::TargetedContent::ITargetedContentValue(ptr, take_ownership_from_abi) {}
    };
}
#endif
