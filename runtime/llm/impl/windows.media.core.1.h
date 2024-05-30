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
#ifndef LLM_OS_Media_Core_1_H
#define LLM_OS_Media_Core_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.0.h"
#include "llm/impl/Windows.Media.Effects.0.h"
#include "llm/impl/Windows.Media.Playback.0.h"
#include "llm/impl/Windows.Media.Core.0.h"
LLM_EXPORT namespace llm:OS::Media::Core
{
    struct __declspec(empty_bases) IAudioStreamDescriptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStreamDescriptor>,
        impl::require<llm:OS::Media::Core::IAudioStreamDescriptor, llm:OS::Media::Core::IMediaStreamDescriptor>
    {
        IAudioStreamDescriptor(std::nullptr_t = nullptr) noexcept {}
        IAudioStreamDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioStreamDescriptor2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStreamDescriptor2>,
        impl::require<llm:OS::Media::Core::IAudioStreamDescriptor2, llm:OS::Media::Core::IMediaStreamDescriptor>
    {
        IAudioStreamDescriptor2(std::nullptr_t = nullptr) noexcept {}
        IAudioStreamDescriptor2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioStreamDescriptor3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStreamDescriptor3>
    {
        IAudioStreamDescriptor3(std::nullptr_t = nullptr) noexcept {}
        IAudioStreamDescriptor3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioStreamDescriptorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStreamDescriptorFactory>
    {
        IAudioStreamDescriptorFactory(std::nullptr_t = nullptr) noexcept {}
        IAudioStreamDescriptorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioTrack>
    {
        IAudioTrack(std::nullptr_t = nullptr) noexcept {}
        IAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioTrackOpenFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioTrackOpenFailedEventArgs>
    {
        IAudioTrackOpenFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAudioTrackOpenFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioTrackSupportInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioTrackSupportInfo>
    {
        IAudioTrackSupportInfo(std::nullptr_t = nullptr) noexcept {}
        IAudioTrackSupportInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IChapterCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IChapterCue>,
        impl::require<llm:OS::Media::Core::IChapterCue, llm:OS::Media::Core::IMediaCue>
    {
        IChapterCue(std::nullptr_t = nullptr) noexcept {}
        IChapterCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICodecInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICodecInfo>
    {
        ICodecInfo(std::nullptr_t = nullptr) noexcept {}
        ICodecInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICodecQuery :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICodecQuery>
    {
        ICodecQuery(std::nullptr_t = nullptr) noexcept {}
        ICodecQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICodecSubtypesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICodecSubtypesStatics>
    {
        ICodecSubtypesStatics(std::nullptr_t = nullptr) noexcept {}
        ICodecSubtypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataCue>,
        impl::require<llm:OS::Media::Core::IDataCue, llm:OS::Media::Core::IMediaCue>
    {
        IDataCue(std::nullptr_t = nullptr) noexcept {}
        IDataCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataCue2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataCue2>,
        impl::require<llm:OS::Media::Core::IDataCue2, llm:OS::Media::Core::IMediaCue, llm:OS::Media::Core::IDataCue>
    {
        IDataCue2(std::nullptr_t = nullptr) noexcept {}
        IDataCue2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFaceDetectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFaceDetectedEventArgs>
    {
        IFaceDetectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFaceDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFaceDetectionEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFaceDetectionEffect>,
        impl::require<llm:OS::Media::Core::IFaceDetectionEffect, llm:OS::Media::IMediaExtension>
    {
        IFaceDetectionEffect(std::nullptr_t = nullptr) noexcept {}
        IFaceDetectionEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFaceDetectionEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFaceDetectionEffectDefinition>,
        impl::require<llm:OS::Media::Core::IFaceDetectionEffectDefinition, llm:OS::Media::Effects::IVideoEffectDefinition>
    {
        IFaceDetectionEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IFaceDetectionEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFaceDetectionEffectFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFaceDetectionEffectFrame>,
        impl::require<llm:OS::Media::Core::IFaceDetectionEffectFrame, llm:OS::Foundation::IClosable, llm:OS::Media::IMediaFrame>
    {
        IFaceDetectionEffectFrame(std::nullptr_t = nullptr) noexcept {}
        IFaceDetectionEffectFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHighDynamicRangeControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHighDynamicRangeControl>
    {
        IHighDynamicRangeControl(std::nullptr_t = nullptr) noexcept {}
        IHighDynamicRangeControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHighDynamicRangeOutput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHighDynamicRangeOutput>
    {
        IHighDynamicRangeOutput(std::nullptr_t = nullptr) noexcept {}
        IHighDynamicRangeOutput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageCue>,
        impl::require<llm:OS::Media::Core::IImageCue, llm:OS::Media::Core::IMediaCue>
    {
        IImageCue(std::nullptr_t = nullptr) noexcept {}
        IImageCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInitializeMediaStreamSourceRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInitializeMediaStreamSourceRequestedEventArgs>
    {
        IInitializeMediaStreamSourceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInitializeMediaStreamSourceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLightFusionResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLightFusionResult>
    {
        ILowLightFusionResult(std::nullptr_t = nullptr) noexcept {}
        ILowLightFusionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLightFusionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLightFusionStatics>
    {
        ILowLightFusionStatics(std::nullptr_t = nullptr) noexcept {}
        ILowLightFusionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaBinder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaBinder>
    {
        IMediaBinder(std::nullptr_t = nullptr) noexcept {}
        IMediaBinder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaBindingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaBindingEventArgs>
    {
        IMediaBindingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaBindingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaBindingEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaBindingEventArgs2>
    {
        IMediaBindingEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IMediaBindingEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaBindingEventArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaBindingEventArgs3>
    {
        IMediaBindingEventArgs3(std::nullptr_t = nullptr) noexcept {}
        IMediaBindingEventArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCue>
    {
        IMediaCue(std::nullptr_t = nullptr) noexcept {}
        IMediaCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCueEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCueEventArgs>
    {
        IMediaCueEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaCueEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSource>
    {
        IMediaSource(std::nullptr_t = nullptr) noexcept {}
        IMediaSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSource2>,
        impl::require<llm:OS::Media::Core::IMediaSource2, llm:OS::Media::Playback::IMediaPlaybackSource, llm:OS::Foundation::IClosable>
    {
        IMediaSource2(std::nullptr_t = nullptr) noexcept {}
        IMediaSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSource3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSource3>,
        impl::require<llm:OS::Media::Core::IMediaSource3, llm:OS::Media::Playback::IMediaPlaybackSource, llm:OS::Foundation::IClosable, llm:OS::Media::Core::IMediaSource2>
    {
        IMediaSource3(std::nullptr_t = nullptr) noexcept {}
        IMediaSource3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSource4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSource4>,
        impl::require<llm:OS::Media::Core::IMediaSource4, llm:OS::Media::Playback::IMediaPlaybackSource, llm:OS::Foundation::IClosable, llm:OS::Media::Core::IMediaSource2, llm:OS::Media::Core::IMediaSource3>
    {
        IMediaSource4(std::nullptr_t = nullptr) noexcept {}
        IMediaSource4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSource5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSource5>
    {
        IMediaSource5(std::nullptr_t = nullptr) noexcept {}
        IMediaSource5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceAppServiceConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceAppServiceConnection>
    {
        IMediaSourceAppServiceConnection(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceAppServiceConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceAppServiceConnectionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceAppServiceConnectionFactory>
    {
        IMediaSourceAppServiceConnectionFactory(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceAppServiceConnectionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceError :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceError>
    {
        IMediaSourceError(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceError(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceOpenOperationCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceOpenOperationCompletedEventArgs>
    {
        IMediaSourceOpenOperationCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceOpenOperationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceStateChangedEventArgs>
    {
        IMediaSourceStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceStatics>
    {
        IMediaSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceStatics2>
    {
        IMediaSourceStatics2(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceStatics3>
    {
        IMediaSourceStatics3(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceStatics4>
    {
        IMediaSourceStatics4(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamDescriptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamDescriptor>
    {
        IMediaStreamDescriptor(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamDescriptor2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamDescriptor2>,
        impl::require<llm:OS::Media::Core::IMediaStreamDescriptor2, llm:OS::Media::Core::IMediaStreamDescriptor>
    {
        IMediaStreamDescriptor2(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamDescriptor2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSample :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSample>
    {
        IMediaStreamSample(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSample(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSample2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSample2>
    {
        IMediaStreamSample2(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSample2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSampleProtectionProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSampleProtectionProperties>
    {
        IMediaStreamSampleProtectionProperties(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSampleProtectionProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSampleStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSampleStatics>
    {
        IMediaStreamSampleStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSampleStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSampleStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSampleStatics2>
    {
        IMediaStreamSampleStatics2(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSampleStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSource>,
        impl::require<llm:OS::Media::Core::IMediaStreamSource, llm:OS::Media::Core::IMediaSource>
    {
        IMediaStreamSource(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSource2>,
        impl::require<llm:OS::Media::Core::IMediaStreamSource2, llm:OS::Media::Core::IMediaSource, llm:OS::Media::Core::IMediaStreamSource>
    {
        IMediaStreamSource2(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSource3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSource3>,
        impl::require<llm:OS::Media::Core::IMediaStreamSource3, llm:OS::Media::Core::IMediaSource, llm:OS::Media::Core::IMediaStreamSource>
    {
        IMediaStreamSource3(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSource3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSource4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSource4>,
        impl::require<llm:OS::Media::Core::IMediaStreamSource4, llm:OS::Media::Core::IMediaSource, llm:OS::Media::Core::IMediaStreamSource>
    {
        IMediaStreamSource4(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSource4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceClosedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceClosedEventArgs>
    {
        IMediaStreamSourceClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceClosedRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceClosedRequest>
    {
        IMediaStreamSourceClosedRequest(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceClosedRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceFactory>
    {
        IMediaStreamSourceFactory(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSampleRenderedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSampleRenderedEventArgs>
    {
        IMediaStreamSourceSampleRenderedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSampleRenderedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSampleRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSampleRequest>
    {
        IMediaStreamSourceSampleRequest(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSampleRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSampleRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSampleRequestDeferral>
    {
        IMediaStreamSourceSampleRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSampleRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSampleRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSampleRequestedEventArgs>
    {
        IMediaStreamSourceSampleRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSampleRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceStartingEventArgs>
    {
        IMediaStreamSourceStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceStartingRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceStartingRequest>
    {
        IMediaStreamSourceStartingRequest(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceStartingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceStartingRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceStartingRequestDeferral>
    {
        IMediaStreamSourceStartingRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceStartingRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSwitchStreamsRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSwitchStreamsRequest>
    {
        IMediaStreamSourceSwitchStreamsRequest(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSwitchStreamsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSwitchStreamsRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSwitchStreamsRequestDeferral>
    {
        IMediaStreamSourceSwitchStreamsRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSwitchStreamsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaStreamSourceSwitchStreamsRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaStreamSourceSwitchStreamsRequestedEventArgs>
    {
        IMediaStreamSourceSwitchStreamsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaStreamSourceSwitchStreamsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaTrack>
    {
        IMediaTrack(std::nullptr_t = nullptr) noexcept {}
        IMediaTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMseSourceBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMseSourceBuffer>
    {
        IMseSourceBuffer(std::nullptr_t = nullptr) noexcept {}
        IMseSourceBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMseSourceBufferList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMseSourceBufferList>
    {
        IMseSourceBufferList(std::nullptr_t = nullptr) noexcept {}
        IMseSourceBufferList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMseStreamSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMseStreamSource>,
        impl::require<llm:OS::Media::Core::IMseStreamSource, llm:OS::Media::Core::IMediaSource>
    {
        IMseStreamSource(std::nullptr_t = nullptr) noexcept {}
        IMseStreamSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMseStreamSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMseStreamSource2>
    {
        IMseStreamSource2(std::nullptr_t = nullptr) noexcept {}
        IMseStreamSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMseStreamSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMseStreamSourceStatics>
    {
        IMseStreamSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IMseStreamSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneAnalysisEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneAnalysisEffect>,
        impl::require<llm:OS::Media::Core::ISceneAnalysisEffect, llm:OS::Media::IMediaExtension>
    {
        ISceneAnalysisEffect(std::nullptr_t = nullptr) noexcept {}
        ISceneAnalysisEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneAnalysisEffectFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneAnalysisEffectFrame>,
        impl::require<llm:OS::Media::Core::ISceneAnalysisEffectFrame, llm:OS::Foundation::IClosable, llm:OS::Media::IMediaFrame>
    {
        ISceneAnalysisEffectFrame(std::nullptr_t = nullptr) noexcept {}
        ISceneAnalysisEffectFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneAnalysisEffectFrame2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneAnalysisEffectFrame2>,
        impl::require<llm:OS::Media::Core::ISceneAnalysisEffectFrame2, llm:OS::Foundation::IClosable, llm:OS::Media::IMediaFrame>
    {
        ISceneAnalysisEffectFrame2(std::nullptr_t = nullptr) noexcept {}
        ISceneAnalysisEffectFrame2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISceneAnalyzedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISceneAnalyzedEventArgs>
    {
        ISceneAnalyzedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISceneAnalyzedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISingleSelectMediaTrackList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISingleSelectMediaTrackList>
    {
        ISingleSelectMediaTrackList(std::nullptr_t = nullptr) noexcept {}
        ISingleSelectMediaTrackList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechCue>,
        impl::require<llm:OS::Media::Core::ISpeechCue, llm:OS::Media::Core::IMediaCue>
    {
        ISpeechCue(std::nullptr_t = nullptr) noexcept {}
        ISpeechCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataStreamDescriptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataStreamDescriptor>
    {
        ITimedMetadataStreamDescriptor(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataStreamDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataStreamDescriptorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataStreamDescriptorFactory>
    {
        ITimedMetadataStreamDescriptorFactory(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataStreamDescriptorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrack>,
        impl::require<llm:OS::Media::Core::ITimedMetadataTrack, llm:OS::Media::Core::IMediaTrack>
    {
        ITimedMetadataTrack(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrack2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrack2>,
        impl::require<llm:OS::Media::Core::ITimedMetadataTrack2, llm:OS::Media::Core::IMediaTrack, llm:OS::Media::Core::ITimedMetadataTrack>
    {
        ITimedMetadataTrack2(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrack2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrackError :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrackError>
    {
        ITimedMetadataTrackError(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrackError(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrackFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrackFactory>
    {
        ITimedMetadataTrackFactory(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrackFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrackFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrackFailedEventArgs>
    {
        ITimedMetadataTrackFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrackFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataTrackProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataTrackProvider>
    {
        ITimedMetadataTrackProvider(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataTrackProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextBouten :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextBouten>
    {
        ITimedTextBouten(std::nullptr_t = nullptr) noexcept {}
        ITimedTextBouten(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextCue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextCue>,
        impl::require<llm:OS::Media::Core::ITimedTextCue, llm:OS::Media::Core::IMediaCue>
    {
        ITimedTextCue(std::nullptr_t = nullptr) noexcept {}
        ITimedTextCue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextLine :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextLine>
    {
        ITimedTextLine(std::nullptr_t = nullptr) noexcept {}
        ITimedTextLine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextRegion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextRegion>
    {
        ITimedTextRegion(std::nullptr_t = nullptr) noexcept {}
        ITimedTextRegion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextRuby :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextRuby>
    {
        ITimedTextRuby(std::nullptr_t = nullptr) noexcept {}
        ITimedTextRuby(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextSource>
    {
        ITimedTextSource(std::nullptr_t = nullptr) noexcept {}
        ITimedTextSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextSourceResolveResultEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextSourceResolveResultEventArgs>
    {
        ITimedTextSourceResolveResultEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITimedTextSourceResolveResultEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextSourceStatics>
    {
        ITimedTextSourceStatics(std::nullptr_t = nullptr) noexcept {}
        ITimedTextSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextSourceStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextSourceStatics2>
    {
        ITimedTextSourceStatics2(std::nullptr_t = nullptr) noexcept {}
        ITimedTextSourceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextStyle :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextStyle>
    {
        ITimedTextStyle(std::nullptr_t = nullptr) noexcept {}
        ITimedTextStyle(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextStyle2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextStyle2>
    {
        ITimedTextStyle2(std::nullptr_t = nullptr) noexcept {}
        ITimedTextStyle2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextStyle3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextStyle3>
    {
        ITimedTextStyle3(std::nullptr_t = nullptr) noexcept {}
        ITimedTextStyle3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedTextSubformat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedTextSubformat>
    {
        ITimedTextSubformat(std::nullptr_t = nullptr) noexcept {}
        ITimedTextSubformat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStabilizationEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStabilizationEffect>,
        impl::require<llm:OS::Media::Core::IVideoStabilizationEffect, llm:OS::Media::IMediaExtension>
    {
        IVideoStabilizationEffect(std::nullptr_t = nullptr) noexcept {}
        IVideoStabilizationEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStabilizationEffectEnabledChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStabilizationEffectEnabledChangedEventArgs>
    {
        IVideoStabilizationEffectEnabledChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVideoStabilizationEffectEnabledChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStreamDescriptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStreamDescriptor>,
        impl::require<llm:OS::Media::Core::IVideoStreamDescriptor, llm:OS::Media::Core::IMediaStreamDescriptor>
    {
        IVideoStreamDescriptor(std::nullptr_t = nullptr) noexcept {}
        IVideoStreamDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStreamDescriptor2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStreamDescriptor2>
    {
        IVideoStreamDescriptor2(std::nullptr_t = nullptr) noexcept {}
        IVideoStreamDescriptor2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStreamDescriptorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStreamDescriptorFactory>
    {
        IVideoStreamDescriptorFactory(std::nullptr_t = nullptr) noexcept {}
        IVideoStreamDescriptorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTrack>
    {
        IVideoTrack(std::nullptr_t = nullptr) noexcept {}
        IVideoTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTrackOpenFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTrackOpenFailedEventArgs>
    {
        IVideoTrackOpenFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVideoTrackOpenFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTrackSupportInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTrackSupportInfo>
    {
        IVideoTrackSupportInfo(std::nullptr_t = nullptr) noexcept {}
        IVideoTrackSupportInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
