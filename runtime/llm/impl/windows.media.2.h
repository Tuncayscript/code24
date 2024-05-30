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
#ifndef LLM_OS_Media_2_H
#define LLM_OS_Media_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.1.h"
LLM_EXPORT namespace llm:OS::Media
{
    struct MediaTimeRange
    {
        llm:OS::Foundation::TimeSpan Start;
        llm:OS::Foundation::TimeSpan End;
    };
    inline bool operator==(MediaTimeRange const& left, MediaTimeRange const& right) noexcept
    {
        return left.Start == right.Start && left.End == right.End;
    }
    inline bool operator!=(MediaTimeRange const& left, MediaTimeRange const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AudioBuffer : llm:OS::Media::IAudioBuffer
    {
        AudioBuffer(std::nullptr_t) noexcept {}
        AudioBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IAudioBuffer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFrame : llm:OS::Media::IAudioFrame
    {
        AudioFrame(std::nullptr_t) noexcept {}
        AudioFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IAudioFrame(ptr, take_ownership_from_abi) {}
        explicit AudioFrame(uint32_t capacity);
    };
    struct __declspec(empty_bases) AutoRepeatModeChangeRequestedEventArgs : llm:OS::Media::IAutoRepeatModeChangeRequestedEventArgs
    {
        AutoRepeatModeChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        AutoRepeatModeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IAutoRepeatModeChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageDisplayProperties : llm:OS::Media::IImageDisplayProperties
    {
        ImageDisplayProperties(std::nullptr_t) noexcept {}
        ImageDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IImageDisplayProperties(ptr, take_ownership_from_abi) {}
    };
    struct MediaControl
    {
        MediaControl() = delete;
        static auto SoundLevelChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using SoundLevelChanged_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_SoundLevelChanged>;
        [[nodiscard]] static SoundLevelChanged_revoker SoundLevelChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto SoundLevelChanged(llm::event_token const& cookie);
        static auto PlayPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PlayPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_PlayPressed>;
        [[nodiscard]] static PlayPressed_revoker PlayPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PlayPressed(llm::event_token const& cookie);
        static auto PausePressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PausePressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_PausePressed>;
        [[nodiscard]] static PausePressed_revoker PausePressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PausePressed(llm::event_token const& cookie);
        static auto StopPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using StopPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_StopPressed>;
        [[nodiscard]] static StopPressed_revoker StopPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto StopPressed(llm::event_token const& cookie);
        static auto PlayPauseTogglePressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PlayPauseTogglePressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_PlayPauseTogglePressed>;
        [[nodiscard]] static PlayPauseTogglePressed_revoker PlayPauseTogglePressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PlayPauseTogglePressed(llm::event_token const& cookie);
        static auto RecordPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RecordPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_RecordPressed>;
        [[nodiscard]] static RecordPressed_revoker RecordPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RecordPressed(llm::event_token const& cookie);
        static auto NextTrackPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using NextTrackPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_NextTrackPressed>;
        [[nodiscard]] static NextTrackPressed_revoker NextTrackPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto NextTrackPressed(llm::event_token const& cookie);
        static auto PreviousTrackPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PreviousTrackPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_PreviousTrackPressed>;
        [[nodiscard]] static PreviousTrackPressed_revoker PreviousTrackPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PreviousTrackPressed(llm::event_token const& cookie);
        static auto FastForwardPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using FastForwardPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_FastForwardPressed>;
        [[nodiscard]] static FastForwardPressed_revoker FastForwardPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto FastForwardPressed(llm::event_token const& cookie);
        static auto RewindPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RewindPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_RewindPressed>;
        [[nodiscard]] static RewindPressed_revoker RewindPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RewindPressed(llm::event_token const& cookie);
        static auto ChannelUpPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using ChannelUpPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_ChannelUpPressed>;
        [[nodiscard]] static ChannelUpPressed_revoker ChannelUpPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto ChannelUpPressed(llm::event_token const& cookie);
        static auto ChannelDownPressed(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using ChannelDownPressed_revoker = impl::factory_event_revoker<llm:OS::Media::IMediaControl, &impl::abi_t<llm:OS::Media::IMediaControl>::remove_ChannelDownPressed>;
        [[nodiscard]] static ChannelDownPressed_revoker ChannelDownPressed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto ChannelDownPressed(llm::event_token const& cookie);
        [[nodiscard]] static auto SoundLevel();
        static auto TrackName(param::hstring const& value);
        [[nodiscard]] static auto TrackName();
        static auto ArtistName(param::hstring const& value);
        [[nodiscard]] static auto ArtistName();
        static auto IsPlaying(bool value);
        [[nodiscard]] static auto IsPlaying();
        static auto AlbumArt(llm:OS::Foundation::Uri const& value);
        [[nodiscard]] static auto AlbumArt();
    };
    struct __declspec(empty_bases) MediaExtensionManager : llm:OS::Media::IMediaExtensionManager,
        impl::require<MediaExtensionManager, llm:OS::Media::IMediaExtensionManager2>
    {
        MediaExtensionManager(std::nullptr_t) noexcept {}
        MediaExtensionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IMediaExtensionManager(ptr, take_ownership_from_abi) {}
        MediaExtensionManager();
    };
    struct MediaMarkerTypes
    {
        MediaMarkerTypes() = delete;
        [[nodiscard]] static auto Bookmark();
    };
    struct __declspec(empty_bases) MediaProcessingTriggerDetails : llm:OS::Media::IMediaProcessingTriggerDetails
    {
        MediaProcessingTriggerDetails(std::nullptr_t) noexcept {}
        MediaProcessingTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IMediaProcessingTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaTimelineController : llm:OS::Media::IMediaTimelineController,
        impl::require<MediaTimelineController, llm:OS::Media::IMediaTimelineController2>
    {
        MediaTimelineController(std::nullptr_t) noexcept {}
        MediaTimelineController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IMediaTimelineController(ptr, take_ownership_from_abi) {}
        MediaTimelineController();
    };
    struct __declspec(empty_bases) MediaTimelineControllerFailedEventArgs : llm:OS::Media::IMediaTimelineControllerFailedEventArgs
    {
        MediaTimelineControllerFailedEventArgs(std::nullptr_t) noexcept {}
        MediaTimelineControllerFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IMediaTimelineControllerFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MusicDisplayProperties : llm:OS::Media::IMusicDisplayProperties,
        impl::require<MusicDisplayProperties, llm:OS::Media::IMusicDisplayProperties2, llm:OS::Media::IMusicDisplayProperties3>
    {
        MusicDisplayProperties(std::nullptr_t) noexcept {}
        MusicDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IMusicDisplayProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackPositionChangeRequestedEventArgs : llm:OS::Media::IPlaybackPositionChangeRequestedEventArgs
    {
        PlaybackPositionChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        PlaybackPositionChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IPlaybackPositionChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackRateChangeRequestedEventArgs : llm:OS::Media::IPlaybackRateChangeRequestedEventArgs
    {
        PlaybackRateChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        PlaybackRateChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IPlaybackRateChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShuffleEnabledChangeRequestedEventArgs : llm:OS::Media::IShuffleEnabledChangeRequestedEventArgs
    {
        ShuffleEnabledChangeRequestedEventArgs(std::nullptr_t) noexcept {}
        ShuffleEnabledChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IShuffleEnabledChangeRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMediaTransportControls : llm:OS::Media::ISystemMediaTransportControls,
        impl::require<SystemMediaTransportControls, llm:OS::Media::ISystemMediaTransportControls2>
    {
        SystemMediaTransportControls(std::nullptr_t) noexcept {}
        SystemMediaTransportControls(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::ISystemMediaTransportControls(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) SystemMediaTransportControlsButtonPressedEventArgs : llm:OS::Media::ISystemMediaTransportControlsButtonPressedEventArgs
    {
        SystemMediaTransportControlsButtonPressedEventArgs(std::nullptr_t) noexcept {}
        SystemMediaTransportControlsButtonPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::ISystemMediaTransportControlsButtonPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMediaTransportControlsDisplayUpdater : llm:OS::Media::ISystemMediaTransportControlsDisplayUpdater
    {
        SystemMediaTransportControlsDisplayUpdater(std::nullptr_t) noexcept {}
        SystemMediaTransportControlsDisplayUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::ISystemMediaTransportControlsDisplayUpdater(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMediaTransportControlsPropertyChangedEventArgs : llm:OS::Media::ISystemMediaTransportControlsPropertyChangedEventArgs
    {
        SystemMediaTransportControlsPropertyChangedEventArgs(std::nullptr_t) noexcept {}
        SystemMediaTransportControlsPropertyChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::ISystemMediaTransportControlsPropertyChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMediaTransportControlsTimelineProperties : llm:OS::Media::ISystemMediaTransportControlsTimelineProperties
    {
        SystemMediaTransportControlsTimelineProperties(std::nullptr_t) noexcept {}
        SystemMediaTransportControlsTimelineProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::ISystemMediaTransportControlsTimelineProperties(ptr, take_ownership_from_abi) {}
        SystemMediaTransportControlsTimelineProperties();
    };
    struct __declspec(empty_bases) VideoDisplayProperties : llm:OS::Media::IVideoDisplayProperties,
        impl::require<VideoDisplayProperties, llm:OS::Media::IVideoDisplayProperties2>
    {
        VideoDisplayProperties(std::nullptr_t) noexcept {}
        VideoDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IVideoDisplayProperties(ptr, take_ownership_from_abi) {}
    };
    struct VideoEffects
    {
        VideoEffects() = delete;
        [[nodiscard]] static auto VideoStabilization();
    };
    struct __declspec(empty_bases) VideoFrame : llm:OS::Media::IVideoFrame,
        impl::require<VideoFrame, llm:OS::Media::IVideoFrame2>
    {
        VideoFrame(std::nullptr_t) noexcept {}
        VideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::IVideoFrame(ptr, take_ownership_from_abi) {}
        VideoFrame(llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height);
        VideoFrame(llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm:OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
        using llm:OS::Media::IVideoFrame::CopyToAsync;
        using impl::consume_t<VideoFrame, llm:OS::Media::IVideoFrame2>::CopyToAsync;
        static auto CreateAsDirect3D11SurfaceBacked(llm:OS::Graphics::DirectX::DirectXPixelFormat const& format, int32_t width, int32_t height);
        static auto CreateAsDirect3D11SurfaceBacked(llm:OS::Graphics::DirectX::DirectXPixelFormat const& format, int32_t width, int32_t height, llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device);
        static auto CreateWithSoftwareBitmap(llm:OS::Graphics::Imaging::SoftwareBitmap const& bitmap);
        static auto CreateWithDirect3D11Surface(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface);
    };
}
#endif
