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
#ifndef LLM_OS_Media_Streaming_Adaptive_H
#define LLM_OS_Media_Streaming_Adaptive_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Media.Core.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
#include "llm/impl/Windows.Media.Streaming.Adaptive.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::IsLive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_IsLive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredLiveOffset() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_DesiredLiveOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredLiveOffset(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->put_DesiredLiveOffset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::InitialBitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_InitialBitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::InitialBitrate(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->put_InitialBitrate(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::CurrentDownloadBitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_CurrentDownloadBitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::CurrentPlaybackBitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_CurrentPlaybackBitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::AvailableBitrates() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_AvailableBitrates(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredMinBitrate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_DesiredMinBitrate(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredMinBitrate(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->put_DesiredMinBitrate(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredMaxBitrate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_DesiredMaxBitrate(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DesiredMaxBitrate(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->put_DesiredMaxBitrate(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::AudioOnlyPlayback() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_AudioOnlyPlayback(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::InboundBitsPerSecond() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_InboundBitsPerSecond(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::InboundBitsPerSecondWindow() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->get_InboundBitsPerSecondWindow(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::InboundBitsPerSecondWindow(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->put_InboundBitsPerSecondWindow(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadBitrateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->add_DownloadBitrateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadBitrateChanged_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadBitrateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DownloadBitrateChanged_revoker>(this, DownloadBitrateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadBitrateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->remove_DownloadBitrateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::PlaybackBitrateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->add_PlaybackBitrateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::PlaybackBitrateChanged_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::PlaybackBitrateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PlaybackBitrateChanged_revoker>(this, PlaybackBitrateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::PlaybackBitrateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->remove_PlaybackBitrateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->add_DownloadRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadRequested_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DownloadRequested_revoker>(this, DownloadRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->remove_DownloadRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->add_DownloadCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadCompleted_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DownloadCompleted_revoker>(this, DownloadCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->remove_DownloadCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadFailed(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->add_DownloadFailed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadFailed_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadFailed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DownloadFailed_revoker>(this, DownloadFailed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource<D>::DownloadFailed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource)->remove_DownloadFailed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource2<D>::AdvancedSettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource2)->get_AdvancedSettings(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::MinLiveOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->get_MinLiveOffset(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::MaxSeekableWindowSize() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->get_MaxSeekableWindowSize(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::DesiredSeekableWindowSize() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->get_DesiredSeekableWindowSize(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::DesiredSeekableWindowSize(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->put_DesiredSeekableWindowSize(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::Diagnostics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->get_Diagnostics(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCorrelatedTimes) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSource3<D>::GetCorrelatedTimes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3)->GetCorrelatedTimes(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCorrelatedTimes{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::AllSegmentsIndependent() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->get_AllSegmentsIndependent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::AllSegmentsIndependent(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->put_AllSegmentsIndependent(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::DesiredBitrateHeadroomRatio() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->get_DesiredBitrateHeadroomRatio(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::DesiredBitrateHeadroomRatio(llm::OS::Foundation::IReference<double> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->put_DesiredBitrateHeadroomRatio(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::BitrateDowngradeTriggerRatio() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->get_BitrateDowngradeTriggerRatio(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceAdvancedSettings<D>::BitrateDowngradeTriggerRatio(llm::OS::Foundation::IReference<double> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings)->put_BitrateDowngradeTriggerRatio(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCorrelatedTimes<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes)->get_Position(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCorrelatedTimes<D>::PresentationTimeStamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes)->get_PresentationTimeStamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCorrelatedTimes<D>::ProgramDateTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes)->get_ProgramDateTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCreationResult<D>::Status() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCreationResult<D>::MediaSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult)->get_MediaSource(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCreationResult<D>::HttpResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult)->get_HttpResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceCreationResult2<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult2)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticType) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::DiagnosticType() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_DiagnosticType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::RequestId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_RequestId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_Position(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::SegmentId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_SegmentId(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::ResourceType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_ResourceType(&value));
        return llm::OS::Foundation::IReference<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::ResourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_ResourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::ResourceByteRangeOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_ResourceByteRangeOffset(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::ResourceByteRangeLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_ResourceByteRangeLength(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs<D>::Bitrate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs)->get_Bitrate(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs2<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs2)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs3<D>::ResourceDuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3)->get_ResourceDuration(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnosticAvailableEventArgs3<D>::ResourceContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3)->get_ResourceContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnostics<D>::DiagnosticAvailable(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticAvailableEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics)->add_DiagnosticAvailable(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnostics<D>::DiagnosticAvailable_revoker consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnostics<D>::DiagnosticAvailable(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticAvailableEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DiagnosticAvailable_revoker>(this, DiagnosticAvailable(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDiagnostics<D>::DiagnosticAvailable(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics)->remove_DiagnosticAvailable(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs<D>::OldValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs)->get_OldValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs<D>::NewValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs)->get_NewValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedReason) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2<D>::Reason() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>::ResourceType() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs)->get_ResourceType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>::ResourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs)->get_ResourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>::ResourceByteRangeOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs)->get_ResourceByteRangeOffset(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>::ResourceByteRangeLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs)->get_ResourceByteRangeLength(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs<D>::HttpResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs)->get_HttpResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs2<D>::RequestId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2)->get_RequestId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs2<D>::Statistics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2)->get_Statistics(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs2<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2)->get_Position(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs3<D>::ResourceDuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3)->get_ResourceDuration(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadCompletedEventArgs3<D>::ResourceContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3)->get_ResourceContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs<D>::ResourceType() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs)->get_ResourceType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs<D>::ResourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs)->get_ResourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs<D>::ResourceByteRangeOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs)->get_ResourceByteRangeOffset(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs<D>::ResourceByteRangeLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs)->get_ResourceByteRangeLength(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs<D>::HttpResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs)->get_HttpResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs2<D>::RequestId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2)->get_RequestId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs2<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs2<D>::Statistics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2)->get_Statistics(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs2<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2)->get_Position(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs3<D>::ResourceDuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3)->get_ResourceDuration(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadFailedEventArgs3<D>::ResourceContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3)->get_ResourceContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::ResourceType() const
    {
        llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->get_ResourceType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::ResourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->get_ResourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::ResourceByteRangeOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->get_ResourceByteRangeOffset(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::ResourceByteRangeLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->get_ResourceByteRangeLength(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::Result() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->get_Result(&value));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs)->GetDeferral(&deferral));
        return llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs2<D>::RequestId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2)->get_RequestId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs2<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2)->get_Position(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs3<D>::ResourceDuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3)->get_ResourceDuration(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadRequestedEventArgs3<D>::ResourceContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3)->get_ResourceContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ResourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->get_ResourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ResourceUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->put_ResourceUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::InputStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->get_InputStream(&value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::InputStream(llm::OS::Storage::Streams::IInputStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->put_InputStream(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::Buffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->get_Buffer(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::Buffer(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->put_Buffer(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->get_ContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ContentType(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->put_ContentType(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ExtendedStatus() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->get_ExtendedStatus(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult<D>::ExtendedStatus(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult)->put_ExtendedStatus(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult2<D>::ResourceByteRangeOffset() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2)->get_ResourceByteRangeOffset(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult2<D>::ResourceByteRangeOffset(llm::OS::Foundation::IReference<uint64_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2)->put_ResourceByteRangeOffset(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint64_t>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult2<D>::ResourceByteRangeLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2)->get_ResourceByteRangeLength(&value));
        return llm::OS::Foundation::IReference<uint64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadResult2<D>::ResourceByteRangeLength(llm::OS::Foundation::IReference<uint64_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2)->put_ResourceByteRangeLength(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadStatistics<D>::ContentBytesReceivedCount() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics)->get_ContentBytesReceivedCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadStatistics<D>::TimeToHeadersReceived() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics)->get_TimeToHeadersReceived(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadStatistics<D>::TimeToFirstByteReceived() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics)->get_TimeToFirstByteReceived(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceDownloadStatistics<D>::TimeToLastByteReceived() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics)->get_TimeToLastByteReceived(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs<D>::OldValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs)->get_OldValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs<D>::NewValue() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs)->get_NewValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs<D>::AudioOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs)->get_AudioOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceStatics<D>::IsContentTypeSupported(param::hstring const& contentType) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics)->IsContentTypeSupported(*(void**)(&contentType), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceStatics<D>::CreateFromUriAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics)->CreateFromUriAsync(*(void**)(&uri), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceStatics<D>::CreateFromUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::HttpClient const& httpClient) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics)->CreateFromUriWithDownloaderAsync(*(void**)(&uri), *(void**)(&httpClient), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceStatics<D>::CreateFromStreamAsync(llm::OS::Storage::Streams::IInputStream const& stream, llm::OS::Foundation::Uri const& uri, param::hstring const& contentType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics)->CreateFromStreamAsync(*(void**)(&stream), *(void**)(&uri), *(void**)(&contentType), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>) consume_Windows_Media_Streaming_Adaptive_IAdaptiveMediaSourceStatics<D>::CreateFromStreamAsync(llm::OS::Storage::Streams::IInputStream const& stream, llm::OS::Foundation::Uri const& uri, param::hstring const& contentType, llm::OS::Web::Http::HttpClient const& httpClient) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics)->CreateFromStreamWithDownloaderAsync(*(void**)(&stream), *(void**)(&uri), *(void**)(&contentType), *(void**)(&httpClient), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource>
    {
        int32_t __stdcall get_IsLive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsLive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredLiveOffset(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DesiredLiveOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredLiveOffset(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredLiveOffset(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialBitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().InitialBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialBitrate(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialBitrate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentDownloadBitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CurrentDownloadBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentPlaybackBitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CurrentPlaybackBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableBitrates(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().AvailableBitrates());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredMinBitrate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().DesiredMinBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredMinBitrate(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredMinBitrate(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredMaxBitrate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().DesiredMaxBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredMaxBitrate(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredMaxBitrate(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioOnlyPlayback(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AudioOnlyPlayback());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InboundBitsPerSecond(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().InboundBitsPerSecond());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InboundBitsPerSecondWindow(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().InboundBitsPerSecondWindow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InboundBitsPerSecondWindow(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InboundBitsPerSecondWindow(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DownloadBitrateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DownloadBitrateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DownloadBitrateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadBitrateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PlaybackBitrateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PlaybackBitrateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PlaybackBitrateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackBitrateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DownloadRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DownloadRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DownloadRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DownloadCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DownloadCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DownloadCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DownloadFailed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DownloadFailed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DownloadFailed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadFailed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource2>
    {
        int32_t __stdcall get_AdvancedSettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings>(this->shim().AdvancedSettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3>
    {
        int32_t __stdcall get_MinLiveOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().MinLiveOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxSeekableWindowSize(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().MaxSeekableWindowSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredSeekableWindowSize(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().DesiredSeekableWindowSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredSeekableWindowSize(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredSeekableWindowSize(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Diagnostics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics>(this->shim().Diagnostics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCorrelatedTimes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCorrelatedTimes>(this->shim().GetCorrelatedTimes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings>
    {
        int32_t __stdcall get_AllSegmentsIndependent(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllSegmentsIndependent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllSegmentsIndependent(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllSegmentsIndependent(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredBitrateHeadroomRatio(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().DesiredBitrateHeadroomRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredBitrateHeadroomRatio(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredBitrateHeadroomRatio(*reinterpret_cast<llm::OS::Foundation::IReference<double> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitrateDowngradeTriggerRatio(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().BitrateDowngradeTriggerRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BitrateDowngradeTriggerRatio(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitrateDowngradeTriggerRatio(*reinterpret_cast<llm::OS::Foundation::IReference<double> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes>
    {
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentationTimeStamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().PresentationTimeStamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProgramDateTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().ProgramDateTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource>(this->shim().MediaSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HttpResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().HttpResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult2>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs>
    {
        int32_t __stdcall get_DiagnosticType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticType>(this->shim().DiagnosticType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().RequestId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SegmentId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().SegmentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>>(this->shim().ResourceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ResourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bitrate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().Bitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs2>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3>
    {
        int32_t __stdcall get_ResourceDuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().ResourceDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResourceContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics>
    {
        int32_t __stdcall add_DiagnosticAvailable(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DiagnosticAvailable(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics, llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticAvailableEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DiagnosticAvailable(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiagnosticAvailable(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs>
    {
        int32_t __stdcall get_OldValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OldValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NewValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs>
    {
        int32_t __stdcall get_ResourceType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>(this->shim().ResourceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ResourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HttpResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().HttpResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2>
    {
        int32_t __stdcall get_RequestId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RequestId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Statistics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics>(this->shim().Statistics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3>
    {
        int32_t __stdcall get_ResourceDuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().ResourceDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResourceContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs>
    {
        int32_t __stdcall get_ResourceType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>(this->shim().ResourceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ResourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HttpResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().HttpResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2>
    {
        int32_t __stdcall get_RequestId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RequestId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Statistics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics>(this->shim().Statistics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3>
    {
        int32_t __stdcall get_ResourceDuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().ResourceDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResourceContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs>
    {
        int32_t __stdcall get_ResourceType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceResourceType>(this->shim().ResourceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ResourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2>
    {
        int32_t __stdcall get_RequestId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RequestId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3>
    {
        int32_t __stdcall get_ResourceDuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().ResourceDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResourceContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult>
    {
        int32_t __stdcall get_ResourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ResourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ResourceUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResourceUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().InputStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InputStream(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputStream(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Buffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Buffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Buffer(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Buffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContentType(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentType(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedStatus(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExtendedStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExtendedStatus(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendedStatus(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2>
    {
        int32_t __stdcall get_ResourceByteRangeOffset(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ResourceByteRangeOffset(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResourceByteRangeOffset(*reinterpret_cast<llm::OS::Foundation::IReference<uint64_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceByteRangeLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint64_t>>(this->shim().ResourceByteRangeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ResourceByteRangeLength(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResourceByteRangeLength(*reinterpret_cast<llm::OS::Foundation::IReference<uint64_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics>
    {
        int32_t __stdcall get_ContentBytesReceivedCount(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ContentBytesReceivedCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeToHeadersReceived(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().TimeToHeadersReceived());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeToFirstByteReceived(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().TimeToFirstByteReceived());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeToLastByteReceived(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().TimeToLastByteReceived());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>
    {
        int32_t __stdcall get_OldValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OldValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewValue(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NewValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AudioOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics> : produce_base<D, llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics>
    {
        int32_t __stdcall IsContentTypeSupported(void* contentType, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsContentTypeSupported(*reinterpret_cast<hstring const*>(&contentType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromUriAsync(void* uri, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>>(this->shim().CreateFromUriAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromUriWithDownloaderAsync(void* uri, void* httpClient, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>>(this->shim().CreateFromUriAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::HttpClient const*>(&httpClient)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromStreamAsync(void* stream, void* uri, void* contentType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>>(this->shim().CreateFromStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&stream), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<hstring const*>(&contentType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromStreamWithDownloaderAsync(void* stream, void* uri, void* contentType, void* httpClient, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult>>(this->shim().CreateFromStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&stream), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<hstring const*>(&contentType), *reinterpret_cast<llm::OS::Web::Http::HttpClient const*>(&httpClient)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Streaming::Adaptive
{
    inline auto AdaptiveMediaSource::IsContentTypeSupported(param::hstring const& contentType)
    {
        return impl::call_factory<AdaptiveMediaSource, IAdaptiveMediaSourceStatics>([&](IAdaptiveMediaSourceStatics const& f) { return f.IsContentTypeSupported(contentType); });
    }
    inline auto AdaptiveMediaSource::CreateFromUriAsync(llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<AdaptiveMediaSource, IAdaptiveMediaSourceStatics>([&](IAdaptiveMediaSourceStatics const& f) { return f.CreateFromUriAsync(uri); });
    }
    inline auto AdaptiveMediaSource::CreateFromUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::HttpClient const& httpClient)
    {
        return impl::call_factory<AdaptiveMediaSource, IAdaptiveMediaSourceStatics>([&](IAdaptiveMediaSourceStatics const& f) { return f.CreateFromUriAsync(uri, httpClient); });
    }
    inline auto AdaptiveMediaSource::CreateFromStreamAsync(llm::OS::Storage::Streams::IInputStream const& stream, llm::OS::Foundation::Uri const& uri, param::hstring const& contentType)
    {
        return impl::call_factory<AdaptiveMediaSource, IAdaptiveMediaSourceStatics>([&](IAdaptiveMediaSourceStatics const& f) { return f.CreateFromStreamAsync(stream, uri, contentType); });
    }
    inline auto AdaptiveMediaSource::CreateFromStreamAsync(llm::OS::Storage::Streams::IInputStream const& stream, llm::OS::Foundation::Uri const& uri, param::hstring const& contentType, llm::OS::Web::Http::HttpClient const& httpClient)
    {
        return impl::call_factory<AdaptiveMediaSource, IAdaptiveMediaSourceStatics>([&](IAdaptiveMediaSourceStatics const& f) { return f.CreateFromStreamAsync(stream, uri, contentType, httpClient); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSource3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceAdvancedSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCorrelatedTimes> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceCreationResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnosticAvailableEventArgs3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDiagnostics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadStatistics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceAdvancedSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCorrelatedTimes> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnosticAvailableEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDiagnostics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadStatistics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
