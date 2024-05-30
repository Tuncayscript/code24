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
#ifndef LLM_OS_Media_PlayTo_1_H
#define LLM_OS_Media_PlayTo_1_H
#include "llm/impl/Windows.Media.PlayTo.0.h"
LLM_EXPORT namespace llm:OS::Media::PlayTo
{
    struct __declspec(empty_bases) ICurrentTimeChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICurrentTimeChangeRequestedEventArgs>
    {
        ICurrentTimeChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICurrentTimeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMuteChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMuteChangeRequestedEventArgs>
    {
        IMuteChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMuteChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToConnection>
    {
        IPlayToConnection(std::nullptr_t = nullptr) noexcept {}
        IPlayToConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToConnectionErrorEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToConnectionErrorEventArgs>
    {
        IPlayToConnectionErrorEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlayToConnectionErrorEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToConnectionStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToConnectionStateChangedEventArgs>
    {
        IPlayToConnectionStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlayToConnectionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToConnectionTransferredEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToConnectionTransferredEventArgs>
    {
        IPlayToConnectionTransferredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlayToConnectionTransferredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToManager>
    {
        IPlayToManager(std::nullptr_t = nullptr) noexcept {}
        IPlayToManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToManagerStatics>
    {
        IPlayToManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPlayToManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToReceiver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToReceiver>
    {
        IPlayToReceiver(std::nullptr_t = nullptr) noexcept {}
        IPlayToReceiver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSource>
    {
        IPlayToSource(std::nullptr_t = nullptr) noexcept {}
        IPlayToSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSourceDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSourceDeferral>
    {
        IPlayToSourceDeferral(std::nullptr_t = nullptr) noexcept {}
        IPlayToSourceDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSourceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSourceRequest>
    {
        IPlayToSourceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayToSourceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSourceRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSourceRequestedEventArgs>
    {
        IPlayToSourceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlayToSourceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSourceSelectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSourceSelectedEventArgs>
    {
        IPlayToSourceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlayToSourceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayToSourceWithPreferredSourceUri :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayToSourceWithPreferredSourceUri>
    {
        IPlayToSourceWithPreferredSourceUri(std::nullptr_t = nullptr) noexcept {}
        IPlayToSourceWithPreferredSourceUri(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaybackRateChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaybackRateChangeRequestedEventArgs>
    {
        IPlaybackRateChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlaybackRateChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISourceChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISourceChangeRequestedEventArgs>
    {
        ISourceChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISourceChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVolumeChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVolumeChangeRequestedEventArgs>
    {
        IVolumeChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVolumeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
