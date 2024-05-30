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
#ifndef LLM_OS_Media_Effects_1_H
#define LLM_OS_Media_Effects_1_H
#include "llm/impl/Windows.Media.0.h"
#include "llm/impl/Windows.Media.Effects.0.h"
LLM_EXPORT namespace llm:OS::Media::Effects
{
    struct __declspec(empty_bases) IAudioCaptureEffectsManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioCaptureEffectsManager>
    {
        IAudioCaptureEffectsManager(std::nullptr_t = nullptr) noexcept {}
        IAudioCaptureEffectsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEffect>
    {
        IAudioEffect(std::nullptr_t = nullptr) noexcept {}
        IAudioEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEffectDefinition>
    {
        IAudioEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IAudioEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEffectDefinitionFactory>
    {
        IAudioEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IAudioEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEffectsManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEffectsManagerStatics>
    {
        IAudioEffectsManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioEffectsManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioRenderEffectsManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioRenderEffectsManager>
    {
        IAudioRenderEffectsManager(std::nullptr_t = nullptr) noexcept {}
        IAudioRenderEffectsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioRenderEffectsManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioRenderEffectsManager2>
    {
        IAudioRenderEffectsManager2(std::nullptr_t = nullptr) noexcept {}
        IAudioRenderEffectsManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBasicAudioEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBasicAudioEffect>,
        impl::require<llm:OS::Media::Effects::IBasicAudioEffect, llm:OS::Media::IMediaExtension>
    {
        IBasicAudioEffect(std::nullptr_t = nullptr) noexcept {}
        IBasicAudioEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBasicVideoEffect :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBasicVideoEffect>,
        impl::require<llm:OS::Media::Effects::IBasicVideoEffect, llm:OS::Media::IMediaExtension>
    {
        IBasicVideoEffect(std::nullptr_t = nullptr) noexcept {}
        IBasicVideoEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompositeVideoFrameContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompositeVideoFrameContext>
    {
        ICompositeVideoFrameContext(std::nullptr_t = nullptr) noexcept {}
        ICompositeVideoFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessAudioFrameContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessAudioFrameContext>
    {
        IProcessAudioFrameContext(std::nullptr_t = nullptr) noexcept {}
        IProcessAudioFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProcessVideoFrameContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProcessVideoFrameContext>
    {
        IProcessVideoFrameContext(std::nullptr_t = nullptr) noexcept {}
        IProcessVideoFrameContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoCompositor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoCompositor>,
        impl::require<llm:OS::Media::Effects::IVideoCompositor, llm:OS::Media::IMediaExtension>
    {
        IVideoCompositor(std::nullptr_t = nullptr) noexcept {}
        IVideoCompositor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoCompositorDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoCompositorDefinition>
    {
        IVideoCompositorDefinition(std::nullptr_t = nullptr) noexcept {}
        IVideoCompositorDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoCompositorDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoCompositorDefinitionFactory>
    {
        IVideoCompositorDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IVideoCompositorDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEffectDefinition>
    {
        IVideoEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IVideoEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEffectDefinitionFactory>
    {
        IVideoEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IVideoEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTransformEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTransformEffectDefinition>,
        impl::require<llm:OS::Media::Effects::IVideoTransformEffectDefinition, llm:OS::Media::Effects::IVideoEffectDefinition>
    {
        IVideoTransformEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IVideoTransformEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTransformEffectDefinition2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTransformEffectDefinition2>
    {
        IVideoTransformEffectDefinition2(std::nullptr_t = nullptr) noexcept {}
        IVideoTransformEffectDefinition2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoTransformSphericalProjection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoTransformSphericalProjection>
    {
        IVideoTransformSphericalProjection(std::nullptr_t = nullptr) noexcept {}
        IVideoTransformSphericalProjection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
