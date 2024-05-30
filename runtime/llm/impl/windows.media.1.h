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
#ifndef LLM_OS_Media_1_H
#define LLM_OS_Media_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.0.h"
LLM_EXPORT namespace llm:OS::Media
{
    struct __declspec(empty_bases) IAudioBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioBuffer>,
        impl::require<llm:OS::Media::IAudioBuffer, llm:OS::Foundation::IClosable, llm:OS::Foundation::IMemoryBuffer>
    {
        IAudioBuffer(std::nullptr_t = nullptr) noexcept {}
        IAudioBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFrame>,
        impl::require<llm:OS::Media::IAudioFrame, llm:OS::Foundation::IClosable, llm:OS::Media::IMediaFrame>
    {
        IAudioFrame(std::nullptr_t = nullptr) noexcept {}
        IAudioFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFrameFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFrameFactory>
    {
        IAudioFrameFactory(std::nullptr_t = nullptr) noexcept {}
        IAudioFrameFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAutoRepeatModeChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAutoRepeatModeChangeRequestedEventArgs>
    {
        IAutoRepeatModeChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAutoRepeatModeChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageDisplayProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageDisplayProperties>
    {
        IImageDisplayProperties(std::nullptr_t = nullptr) noexcept {}
        IImageDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaControl>
    {
        IMediaControl(std::nullptr_t = nullptr) noexcept {}
        IMediaControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaExtension :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaExtension>
    {
        IMediaExtension(std::nullptr_t = nullptr) noexcept {}
        IMediaExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaExtensionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaExtensionManager>
    {
        IMediaExtensionManager(std::nullptr_t = nullptr) noexcept {}
        IMediaExtensionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaExtensionManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaExtensionManager2>,
        impl::require<llm:OS::Media::IMediaExtensionManager2, llm:OS::Media::IMediaExtensionManager>
    {
        IMediaExtensionManager2(std::nullptr_t = nullptr) noexcept {}
        IMediaExtensionManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrame>,
        impl::require<llm:OS::Media::IMediaFrame, llm:OS::Foundation::IClosable>
    {
        IMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaMarker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaMarker>
    {
        IMediaMarker(std::nullptr_t = nullptr) noexcept {}
        IMediaMarker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaMarkerTypesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaMarkerTypesStatics>
    {
        IMediaMarkerTypesStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaMarkerTypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaMarkers :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaMarkers>
    {
        IMediaMarkers(std::nullptr_t = nullptr) noexcept {}
        IMediaMarkers(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProcessingTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProcessingTriggerDetails>
    {
        IMediaProcessingTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMediaProcessingTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaTimelineController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaTimelineController>
    {
        IMediaTimelineController(std::nullptr_t = nullptr) noexcept {}
        IMediaTimelineController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaTimelineController2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaTimelineController2>
    {
        IMediaTimelineController2(std::nullptr_t = nullptr) noexcept {}
        IMediaTimelineController2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaTimelineControllerFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaTimelineControllerFailedEventArgs>
    {
        IMediaTimelineControllerFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaTimelineControllerFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMusicDisplayProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMusicDisplayProperties>
    {
        IMusicDisplayProperties(std::nullptr_t = nullptr) noexcept {}
        IMusicDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMusicDisplayProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMusicDisplayProperties2>
    {
        IMusicDisplayProperties2(std::nullptr_t = nullptr) noexcept {}
        IMusicDisplayProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMusicDisplayProperties3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMusicDisplayProperties3>
    {
        IMusicDisplayProperties3(std::nullptr_t = nullptr) noexcept {}
        IMusicDisplayProperties3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaybackPositionChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaybackPositionChangeRequestedEventArgs>
    {
        IPlaybackPositionChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlaybackPositionChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaybackRateChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaybackRateChangeRequestedEventArgs>
    {
        IPlaybackRateChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlaybackRateChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShuffleEnabledChangeRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShuffleEnabledChangeRequestedEventArgs>
    {
        IShuffleEnabledChangeRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IShuffleEnabledChangeRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControls :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControls>
    {
        ISystemMediaTransportControls(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControls(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControls2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControls2>
    {
        ISystemMediaTransportControls2(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControls2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControlsButtonPressedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControlsButtonPressedEventArgs>
    {
        ISystemMediaTransportControlsButtonPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControlsButtonPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControlsDisplayUpdater :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControlsDisplayUpdater>
    {
        ISystemMediaTransportControlsDisplayUpdater(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControlsDisplayUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControlsPropertyChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControlsPropertyChangedEventArgs>
    {
        ISystemMediaTransportControlsPropertyChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControlsPropertyChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControlsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControlsStatics>
    {
        ISystemMediaTransportControlsStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControlsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaTransportControlsTimelineProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaTransportControlsTimelineProperties>
    {
        ISystemMediaTransportControlsTimelineProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaTransportControlsTimelineProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoDisplayProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoDisplayProperties>
    {
        IVideoDisplayProperties(std::nullptr_t = nullptr) noexcept {}
        IVideoDisplayProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoDisplayProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoDisplayProperties2>
    {
        IVideoDisplayProperties2(std::nullptr_t = nullptr) noexcept {}
        IVideoDisplayProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEffectsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEffectsStatics>
    {
        IVideoEffectsStatics(std::nullptr_t = nullptr) noexcept {}
        IVideoEffectsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoFrame>,
        impl::require<llm:OS::Media::IVideoFrame, llm:OS::Foundation::IClosable, llm:OS::Media::IMediaFrame>
    {
        IVideoFrame(std::nullptr_t = nullptr) noexcept {}
        IVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoFrame2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoFrame2>
    {
        IVideoFrame2(std::nullptr_t = nullptr) noexcept {}
        IVideoFrame2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoFrameFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoFrameFactory>
    {
        IVideoFrameFactory(std::nullptr_t = nullptr) noexcept {}
        IVideoFrameFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoFrameStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoFrameStatics>
    {
        IVideoFrameStatics(std::nullptr_t = nullptr) noexcept {}
        IVideoFrameStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
