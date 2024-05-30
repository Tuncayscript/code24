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
#ifndef LLM_OS_Media_Streaming_Adaptive_1_H
#define LLM_OS_Media_Streaming_Adaptive_1_H
#include "llm/impl/Windows.Media.Core.0.h"
#include "llm/impl/Windows.Media.Streaming.Adaptive.0.h"
LLM_EXPORT namespace llm:OS::Media::Streaming::Adaptive
{
    struct __declspec(empty_bases) IAdaptiveMediaSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSource>,
        impl::require<llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSource, llm:OS::Media::Core::IMediaSource>
    {
        IAdaptiveMediaSource(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSource2>
    {
        IAdaptiveMediaSource2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSource3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSource3>
    {
        IAdaptiveMediaSource3(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSource3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceAdvancedSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceAdvancedSettings>
    {
        IAdaptiveMediaSourceAdvancedSettings(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceAdvancedSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceCorrelatedTimes :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceCorrelatedTimes>
    {
        IAdaptiveMediaSourceCorrelatedTimes(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceCorrelatedTimes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceCreationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceCreationResult>
    {
        IAdaptiveMediaSourceCreationResult(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceCreationResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceCreationResult2>
    {
        IAdaptiveMediaSourceCreationResult2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceCreationResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDiagnosticAvailableEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDiagnosticAvailableEventArgs>
    {
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDiagnosticAvailableEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDiagnosticAvailableEventArgs2>
    {
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDiagnosticAvailableEventArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDiagnosticAvailableEventArgs3>
    {
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs3(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDiagnosticAvailableEventArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDiagnostics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDiagnostics>
    {
        IAdaptiveMediaSourceDiagnostics(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDiagnostics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadBitrateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadBitrateChangedEventArgs>
    {
        IAdaptiveMediaSourceDownloadBitrateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadBitrateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2>
    {
        IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadCompletedEventArgs>
    {
        IAdaptiveMediaSourceDownloadCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadCompletedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadCompletedEventArgs2>
    {
        IAdaptiveMediaSourceDownloadCompletedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadCompletedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadCompletedEventArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadCompletedEventArgs3>
    {
        IAdaptiveMediaSourceDownloadCompletedEventArgs3(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadCompletedEventArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadFailedEventArgs>
    {
        IAdaptiveMediaSourceDownloadFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadFailedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadFailedEventArgs2>
    {
        IAdaptiveMediaSourceDownloadFailedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadFailedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadFailedEventArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadFailedEventArgs3>
    {
        IAdaptiveMediaSourceDownloadFailedEventArgs3(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadFailedEventArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadRequestedDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadRequestedDeferral>
    {
        IAdaptiveMediaSourceDownloadRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadRequestedEventArgs>
    {
        IAdaptiveMediaSourceDownloadRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadRequestedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadRequestedEventArgs2>
    {
        IAdaptiveMediaSourceDownloadRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadRequestedEventArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadRequestedEventArgs3>
    {
        IAdaptiveMediaSourceDownloadRequestedEventArgs3(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadRequestedEventArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadResult>
    {
        IAdaptiveMediaSourceDownloadResult(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadResult2>
    {
        IAdaptiveMediaSourceDownloadResult2(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceDownloadStatistics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceDownloadStatistics>
    {
        IAdaptiveMediaSourceDownloadStatistics(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceDownloadStatistics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>
    {
        IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveMediaSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveMediaSourceStatics>
    {
        IAdaptiveMediaSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveMediaSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
