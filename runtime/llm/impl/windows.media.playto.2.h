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
#ifndef LLM_OS_Media_PlayTo_2_H
#define LLM_OS_Media_PlayTo_2_H
#include "llm/impl/Windows.Media.PlayTo.1.h"
LLM_EXPORT namespace llm:OS::Media::PlayTo
{
    struct __declspec(empty_bases) CurrentTimeChangeRequestedEventArgs : llm:OS::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs
    {
        CurrentTimeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        CurrentTimeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MuteChangeRequestedEventArgs : llm:OS::Media::PlayTo::IMuteChangeRequestedEventArgs
    {
        MuteChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        MuteChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IMuteChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToConnection : llm:OS::Media::PlayTo::IPlayToConnection
    {
        PlayToConnection(std::nullptr_t) noexcept {}
        PlayToConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToConnectionErrorEventArgs : llm:OS::Media::PlayTo::IPlayToConnectionErrorEventArgs
    {
        PlayToConnectionErrorEventArgs(std::nullptr_t) noexcept {}
        PlayToConnectionErrorEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToConnectionErrorEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToConnectionStateChangedEventArgs : llm:OS::Media::PlayTo::IPlayToConnectionStateChangedEventArgs
    {
        PlayToConnectionStateChangedEventArgs(std::nullptr_t) noexcept {}
        PlayToConnectionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToConnectionStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToConnectionTransferredEventArgs : llm:OS::Media::PlayTo::IPlayToConnectionTransferredEventArgs
    {
        PlayToConnectionTransferredEventArgs(std::nullptr_t) noexcept {}
        PlayToConnectionTransferredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToConnectionTransferredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToManager : llm:OS::Media::PlayTo::IPlayToManager
    {
        PlayToManager(std::nullptr_t) noexcept {}
        PlayToManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto ShowPlayToUI();
    };
    struct __declspec(empty_bases) PlayToReceiver : llm:OS::Media::PlayTo::IPlayToReceiver
    {
        PlayToReceiver(std::nullptr_t) noexcept {}
        PlayToReceiver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToReceiver(ptr, take_ownership_from_abi) {}
        PlayToReceiver();
    };
    struct __declspec(empty_bases) PlayToSource : llm:OS::Media::PlayTo::IPlayToSource,
        impl::require<PlayToSource, llm:OS::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>
    {
        PlayToSource(std::nullptr_t) noexcept {}
        PlayToSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToSource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToSourceDeferral : llm:OS::Media::PlayTo::IPlayToSourceDeferral
    {
        PlayToSourceDeferral(std::nullptr_t) noexcept {}
        PlayToSourceDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToSourceDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToSourceRequest : llm:OS::Media::PlayTo::IPlayToSourceRequest
    {
        PlayToSourceRequest(std::nullptr_t) noexcept {}
        PlayToSourceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToSourceRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToSourceRequestedEventArgs : llm:OS::Media::PlayTo::IPlayToSourceRequestedEventArgs
    {
        PlayToSourceRequestedEventArgs(std::nullptr_t) noexcept {}
        PlayToSourceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToSourceRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayToSourceSelectedEventArgs : llm:OS::Media::PlayTo::IPlayToSourceSelectedEventArgs
    {
        PlayToSourceSelectedEventArgs(std::nullptr_t) noexcept {}
        PlayToSourceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlayToSourceSelectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackRateChangeRequestedEventArgs : llm:OS::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs
    {
        PlaybackRateChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        PlaybackRateChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SourceChangeRequestedEventArgs : llm:OS::Media::PlayTo::ISourceChangeRequestedEventArgs
    {
        SourceChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        SourceChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::ISourceChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VolumeChangeRequestedEventArgs : llm:OS::Media::PlayTo::IVolumeChangeRequestedEventArgs
    {
        VolumeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        VolumeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::PlayTo::IVolumeChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
