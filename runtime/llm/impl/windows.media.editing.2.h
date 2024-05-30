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
#ifndef LLM_OS_Media_Editing_2_H
#define LLM_OS_Media_Editing_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
#include "llm/impl/Windows.Media.Effects.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.Media.Editing.1.h"
LLM_EXPORT namespace llm:OS::Media::Editing
{
    struct __declspec(empty_bases) BackgroundAudioTrack : llm:OS::Media::Editing::IBackgroundAudioTrack
    {
        BackgroundAudioTrack(std::nullptr_t) noexcept {}
        BackgroundAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IBackgroundAudioTrack(ptr, take_ownership_from_abi) {}
        static auto CreateFromEmbeddedAudioTrack(llm:OS::Media::Editing::EmbeddedAudioTrack const& embeddedAudioTrack);
        static auto CreateFromFileAsync(llm:OS::Storage::IStorageFile const& file);
    };
    struct __declspec(empty_bases) EmbeddedAudioTrack : llm:OS::Media::Editing::IEmbeddedAudioTrack
    {
        EmbeddedAudioTrack(std::nullptr_t) noexcept {}
        EmbeddedAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IEmbeddedAudioTrack(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaClip : llm:OS::Media::Editing::IMediaClip
    {
        MediaClip(std::nullptr_t) noexcept {}
        MediaClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IMediaClip(ptr, take_ownership_from_abi) {}
        static auto CreateFromColor(llm:OS::UI::Color const& color, llm:OS::Foundation::TimeSpan const& originalDuration);
        static auto CreateFromFileAsync(llm:OS::Storage::IStorageFile const& file);
        static auto CreateFromImageFileAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Foundation::TimeSpan const& originalDuration);
        static auto CreateFromSurface(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm:OS::Foundation::TimeSpan const& originalDuration);
    };
    struct __declspec(empty_bases) MediaComposition : llm:OS::Media::Editing::IMediaComposition,
        impl::require<MediaComposition, llm:OS::Media::Editing::IMediaComposition2>
    {
        MediaComposition(std::nullptr_t) noexcept {}
        MediaComposition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IMediaComposition(ptr, take_ownership_from_abi) {}
        MediaComposition();
        static auto LoadAsync(llm:OS::Storage::StorageFile const& file);
    };
    struct __declspec(empty_bases) MediaOverlay : llm:OS::Media::Editing::IMediaOverlay
    {
        MediaOverlay(std::nullptr_t) noexcept {}
        MediaOverlay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IMediaOverlay(ptr, take_ownership_from_abi) {}
        explicit MediaOverlay(llm:OS::Media::Editing::MediaClip const& clip);
        MediaOverlay(llm:OS::Media::Editing::MediaClip const& clip, llm:OS::Foundation::Rect const& position, double opacity);
    };
    struct __declspec(empty_bases) MediaOverlayLayer : llm:OS::Media::Editing::IMediaOverlayLayer
    {
        MediaOverlayLayer(std::nullptr_t) noexcept {}
        MediaOverlayLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Editing::IMediaOverlayLayer(ptr, take_ownership_from_abi) {}
        MediaOverlayLayer();
        explicit MediaOverlayLayer(llm:OS::Media::Effects::IVideoCompositorDefinition const& compositorDefinition);
    };
}
#endif
