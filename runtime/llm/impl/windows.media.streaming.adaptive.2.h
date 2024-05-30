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
#ifndef LLM_OS_Media_Streaming_Adaptive_2_H
#define LLM_OS_Media_Streaming_Adaptive_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Core.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Web.Http.1.h"
#include "llm/impl/Windows.Media.Streaming.Adaptive.1.h"
LLM_EXPORT namespace llm:OS::Media::Streaming::Adaptive
{
    struct __declspec(empty_bases) AdaptiveMediaSource : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSource,
        impl::require<AdaptiveMediaSource, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSource2, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3, llm:OS::Foundation::IClosable>
    {
        AdaptiveMediaSource(std::nullptr_t) noexcept {}
        AdaptiveMediaSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSource(ptr, take_ownership_from_abi) {}
        static auto IsContentTypeSupported(param::hstring const& contentType);
        static auto CreateFromUriAsync(llm:OS::Foundation::Uri const& uri);
        static auto CreateFromUriAsync(llm:OS::Foundation::Uri const& uri, llm:OS::Web::Http::HttpClient const& httpClient);
        static auto CreateFromStreamAsync(llm:OS::Storage::Streams::IInputStream const& stream, llm:OS::Foundation::Uri const& uri, param::hstring const& contentType);
        static auto CreateFromStreamAsync(llm:OS::Storage::Streams::IInputStream const& stream, llm:OS::Foundation::Uri const& uri, param::hstring const& contentType, llm:OS::Web::Http::HttpClient const& httpClient);
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceAdvancedSettings : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings
    {
        AdaptiveMediaSourceAdvancedSettings(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceAdvancedSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceCorrelatedTimes : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes
    {
        AdaptiveMediaSourceCorrelatedTimes(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceCorrelatedTimes(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceCreationResult : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult,
        impl::require<AdaptiveMediaSourceCreationResult, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult2>
    {
        AdaptiveMediaSourceCreationResult(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDiagnosticAvailableEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs,
        impl::require<AdaptiveMediaSourceDiagnosticAvailableEventArgs, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs2, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3>
    {
        AdaptiveMediaSourceDiagnosticAvailableEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDiagnosticAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDiagnostics : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics
    {
        AdaptiveMediaSourceDiagnostics(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDiagnostics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadBitrateChangedEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs,
        impl::require<AdaptiveMediaSourceDownloadBitrateChangedEventArgs, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2>
    {
        AdaptiveMediaSourceDownloadBitrateChangedEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadBitrateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadCompletedEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs,
        impl::require<AdaptiveMediaSourceDownloadCompletedEventArgs, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3>
    {
        AdaptiveMediaSourceDownloadCompletedEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadFailedEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs,
        impl::require<AdaptiveMediaSourceDownloadFailedEventArgs, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3>
    {
        AdaptiveMediaSourceDownloadFailedEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadRequestedDeferral : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral
    {
        AdaptiveMediaSourceDownloadRequestedDeferral(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadRequestedEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs,
        impl::require<AdaptiveMediaSourceDownloadRequestedEventArgs, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3>
    {
        AdaptiveMediaSourceDownloadRequestedEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadResult : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult,
        impl::require<AdaptiveMediaSourceDownloadResult, llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>
    {
        AdaptiveMediaSourceDownloadResult(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourceDownloadStatistics : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics
    {
        AdaptiveMediaSourceDownloadStatistics(std::nullptr_t) noexcept {}
        AdaptiveMediaSourceDownloadStatistics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdaptiveMediaSourcePlaybackBitrateChangedEventArgs : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs
    {
        AdaptiveMediaSourcePlaybackBitrateChangedEventArgs(std::nullptr_t) noexcept {}
        AdaptiveMediaSourcePlaybackBitrateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
