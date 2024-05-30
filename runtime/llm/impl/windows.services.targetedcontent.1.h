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
#ifndef LLM_OS_Services_TargetedContent_1_H
#define LLM_OS_Services_TargetedContent_1_H
#include "llm/impl/Windows.Storage.Streams.0.h"
#include "llm/impl/Windows.Services.TargetedContent.0.h"
LLM_EXPORT namespace llm:OS::Services::TargetedContent
{
    struct __declspec(empty_bases) ITargetedContentAction :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentAction>
    {
        ITargetedContentAction(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentAction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentAvailabilityChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentAvailabilityChangedEventArgs>
    {
        ITargetedContentAvailabilityChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentAvailabilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentChangedEventArgs>
    {
        ITargetedContentChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentCollection>
    {
        ITargetedContentCollection(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentContainer>
    {
        ITargetedContentContainer(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentContainerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentContainerStatics>
    {
        ITargetedContentContainerStatics(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentContainerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentImage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentImage>,
        impl::require<llm:OS::Services::TargetedContent::ITargetedContentImage, llm:OS::Storage::Streams::IRandomAccessStreamReference>
    {
        ITargetedContentImage(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentImage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentItem>
    {
        ITargetedContentItem(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentItemState :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentItemState>
    {
        ITargetedContentItemState(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentItemState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentObject :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentObject>
    {
        ITargetedContentObject(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentStateChangedEventArgs>
    {
        ITargetedContentStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentSubscription :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentSubscription>
    {
        ITargetedContentSubscription(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentSubscription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentSubscriptionOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentSubscriptionOptions>
    {
        ITargetedContentSubscriptionOptions(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentSubscriptionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentSubscriptionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentSubscriptionStatics>
    {
        ITargetedContentSubscriptionStatics(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentSubscriptionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITargetedContentValue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITargetedContentValue>
    {
        ITargetedContentValue(std::nullptr_t = nullptr) noexcept {}
        ITargetedContentValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
