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
#ifndef LLM_OS_Media_Effects_2_H
#define LLM_OS_Media_Effects_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Media.1.h"
#include "llm/impl/Windows.Media.Capture.1.h"
#include "llm/impl/Windows.Media.Render.1.h"
#include "llm/impl/Windows.Media.Effects.1.h"
LLM_EXPORT namespace llm:OS::Media::Effects
{
    struct __declspec(empty_bases) AudioCaptureEffectsManager : llm:OS::Media::Effects::IAudioCaptureEffectsManager
    {
        AudioCaptureEffectsManager(std::nullptr_t) noexcept {}
        AudioCaptureEffectsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IAudioCaptureEffectsManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioEffect : llm:OS::Media::Effects::IAudioEffect
    {
        AudioEffect(std::nullptr_t) noexcept {}
        AudioEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IAudioEffect(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioEffectDefinition : llm:OS::Media::Effects::IAudioEffectDefinition
    {
        AudioEffectDefinition(std::nullptr_t) noexcept {}
        AudioEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IAudioEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit AudioEffectDefinition(param::hstring const& activatableClassId);
        AudioEffectDefinition(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props);
    };
    struct AudioEffectsManager
    {
        AudioEffectsManager() = delete;
        static auto CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm:OS::Media::Render::AudioRenderCategory const& category);
        static auto CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm:OS::Media::Render::AudioRenderCategory const& category, llm:OS::Media::AudioProcessing const& mode);
        static auto CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm:OS::Media::Capture::MediaCategory const& category);
        static auto CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm:OS::Media::Capture::MediaCategory const& category, llm:OS::Media::AudioProcessing const& mode);
    };
    struct __declspec(empty_bases) AudioRenderEffectsManager : llm:OS::Media::Effects::IAudioRenderEffectsManager,
        impl::require<AudioRenderEffectsManager, llm:OS::Media::Effects::IAudioRenderEffectsManager2>
    {
        AudioRenderEffectsManager(std::nullptr_t) noexcept {}
        AudioRenderEffectsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IAudioRenderEffectsManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CompositeVideoFrameContext : llm:OS::Media::Effects::ICompositeVideoFrameContext
    {
        CompositeVideoFrameContext(std::nullptr_t) noexcept {}
        CompositeVideoFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::ICompositeVideoFrameContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessAudioFrameContext : llm:OS::Media::Effects::IProcessAudioFrameContext
    {
        ProcessAudioFrameContext(std::nullptr_t) noexcept {}
        ProcessAudioFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IProcessAudioFrameContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessVideoFrameContext : llm:OS::Media::Effects::IProcessVideoFrameContext
    {
        ProcessVideoFrameContext(std::nullptr_t) noexcept {}
        ProcessVideoFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IProcessVideoFrameContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoCompositorDefinition : llm:OS::Media::Effects::IVideoCompositorDefinition
    {
        VideoCompositorDefinition(std::nullptr_t) noexcept {}
        VideoCompositorDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IVideoCompositorDefinition(ptr, take_ownership_from_abi) {}
        explicit VideoCompositorDefinition(param::hstring const& activatableClassId);
        VideoCompositorDefinition(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props);
    };
    struct __declspec(empty_bases) VideoEffectDefinition : llm:OS::Media::Effects::IVideoEffectDefinition
    {
        VideoEffectDefinition(std::nullptr_t) noexcept {}
        VideoEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IVideoEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit VideoEffectDefinition(param::hstring const& activatableClassId);
        VideoEffectDefinition(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props);
    };
    struct __declspec(empty_bases) VideoTransformEffectDefinition : llm:OS::Media::Effects::IVideoEffectDefinition,
        impl::require<VideoTransformEffectDefinition, llm:OS::Media::Effects::IVideoTransformEffectDefinition, llm:OS::Media::Effects::IVideoTransformEffectDefinition2>
    {
        VideoTransformEffectDefinition(std::nullptr_t) noexcept {}
        VideoTransformEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IVideoEffectDefinition(ptr, take_ownership_from_abi) {}
        VideoTransformEffectDefinition();
    };
    struct __declspec(empty_bases) VideoTransformSphericalProjection : llm:OS::Media::Effects::IVideoTransformSphericalProjection
    {
        VideoTransformSphericalProjection(std::nullptr_t) noexcept {}
        VideoTransformSphericalProjection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Effects::IVideoTransformSphericalProjection(ptr, take_ownership_from_abi) {}
    };
}
#endif
