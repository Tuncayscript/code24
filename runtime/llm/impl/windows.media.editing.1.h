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
#ifndef LLM_OS_Media_Editing_1_H
#define LLM_OS_Media_Editing_1_H
#include "llm/impl/Windows.Media.Editing.0.h"
LLM_EXPORT namespace llm:OS::Media::Editing
{
    struct __declspec(empty_bases) IBackgroundAudioTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundAudioTrack>
    {
        IBackgroundAudioTrack(std::nullptr_t = nullptr) noexcept {}
        IBackgroundAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundAudioTrackStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundAudioTrackStatics>
    {
        IBackgroundAudioTrackStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundAudioTrackStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmbeddedAudioTrack :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEmbeddedAudioTrack>
    {
        IEmbeddedAudioTrack(std::nullptr_t = nullptr) noexcept {}
        IEmbeddedAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaClip :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaClip>
    {
        IMediaClip(std::nullptr_t = nullptr) noexcept {}
        IMediaClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaClipStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaClipStatics>
    {
        IMediaClipStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaClipStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaClipStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaClipStatics2>
    {
        IMediaClipStatics2(std::nullptr_t = nullptr) noexcept {}
        IMediaClipStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaComposition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaComposition>
    {
        IMediaComposition(std::nullptr_t = nullptr) noexcept {}
        IMediaComposition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaComposition2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaComposition2>
    {
        IMediaComposition2(std::nullptr_t = nullptr) noexcept {}
        IMediaComposition2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCompositionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCompositionStatics>
    {
        IMediaCompositionStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaCompositionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaOverlay :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaOverlay>
    {
        IMediaOverlay(std::nullptr_t = nullptr) noexcept {}
        IMediaOverlay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaOverlayFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaOverlayFactory>
    {
        IMediaOverlayFactory(std::nullptr_t = nullptr) noexcept {}
        IMediaOverlayFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaOverlayLayer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaOverlayLayer>
    {
        IMediaOverlayLayer(std::nullptr_t = nullptr) noexcept {}
        IMediaOverlayLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaOverlayLayerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaOverlayLayerFactory>
    {
        IMediaOverlayLayerFactory(std::nullptr_t = nullptr) noexcept {}
        IMediaOverlayLayerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
