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
#ifndef LLM_OS_Media_Capture_Frames_2_H
#define LLM_OS_Media_Capture_Frames_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Capture.Frames.1.h"
LLM_EXPORT namespace llm:OS::Media::Capture::Frames
{
    struct __declspec(empty_bases) AudioMediaFrame : llm:OS::Media::Capture::Frames::IAudioMediaFrame
    {
        AudioMediaFrame(std::nullptr_t) noexcept {}
        AudioMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IAudioMediaFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BufferMediaFrame : llm:OS::Media::Capture::Frames::IBufferMediaFrame
    {
        BufferMediaFrame(std::nullptr_t) noexcept {}
        BufferMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IBufferMediaFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DepthMediaFrame : llm:OS::Media::Capture::Frames::IDepthMediaFrame,
        impl::require<DepthMediaFrame, llm:OS::Media::Capture::Frames::IDepthMediaFrame2>
    {
        DepthMediaFrame(std::nullptr_t) noexcept {}
        DepthMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IDepthMediaFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DepthMediaFrameFormat : llm:OS::Media::Capture::Frames::IDepthMediaFrameFormat
    {
        DepthMediaFrameFormat(std::nullptr_t) noexcept {}
        DepthMediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IDepthMediaFrameFormat(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InfraredMediaFrame : llm:OS::Media::Capture::Frames::IInfraredMediaFrame
    {
        InfraredMediaFrame(std::nullptr_t) noexcept {}
        InfraredMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IInfraredMediaFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameArrivedEventArgs : llm:OS::Media::Capture::Frames::IMediaFrameArrivedEventArgs
    {
        MediaFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        MediaFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameFormat : llm:OS::Media::Capture::Frames::IMediaFrameFormat,
        impl::require<MediaFrameFormat, llm:OS::Media::Capture::Frames::IMediaFrameFormat2>
    {
        MediaFrameFormat(std::nullptr_t) noexcept {}
        MediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameFormat(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameReader : llm:OS::Media::Capture::Frames::IMediaFrameReader,
        impl::require<MediaFrameReader, llm:OS::Media::Capture::Frames::IMediaFrameReader2>
    {
        MediaFrameReader(std::nullptr_t) noexcept {}
        MediaFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameReference : llm:OS::Media::Capture::Frames::IMediaFrameReference,
        impl::require<MediaFrameReference, llm:OS::Media::Capture::Frames::IMediaFrameReference2>
    {
        MediaFrameReference(std::nullptr_t) noexcept {}
        MediaFrameReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameReference(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameSource : llm:OS::Media::Capture::Frames::IMediaFrameSource
    {
        MediaFrameSource(std::nullptr_t) noexcept {}
        MediaFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameSource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameSourceController : llm:OS::Media::Capture::Frames::IMediaFrameSourceController,
        impl::require<MediaFrameSourceController, llm:OS::Media::Capture::Frames::IMediaFrameSourceController2, llm:OS::Media::Capture::Frames::IMediaFrameSourceController3>
    {
        MediaFrameSourceController(std::nullptr_t) noexcept {}
        MediaFrameSourceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameSourceController(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameSourceGetPropertyResult : llm:OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult
    {
        MediaFrameSourceGetPropertyResult(std::nullptr_t) noexcept {}
        MediaFrameSourceGetPropertyResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaFrameSourceGroup : llm:OS::Media::Capture::Frames::IMediaFrameSourceGroup
    {
        MediaFrameSourceGroup(std::nullptr_t) noexcept {}
        MediaFrameSourceGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameSourceGroup(ptr, take_ownership_from_abi) {}
        static auto FindAllAsync();
        static auto FromIdAsync(param::hstring const& id);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) MediaFrameSourceInfo : llm:OS::Media::Capture::Frames::IMediaFrameSourceInfo,
        impl::require<MediaFrameSourceInfo, llm:OS::Media::Capture::Frames::IMediaFrameSourceInfo2, llm:OS::Media::Capture::Frames::IMediaFrameSourceInfo3, llm:OS::Media::Capture::Frames::IMediaFrameSourceInfo4>
    {
        MediaFrameSourceInfo(std::nullptr_t) noexcept {}
        MediaFrameSourceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMediaFrameSourceInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MultiSourceMediaFrameArrivedEventArgs : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameArrivedEventArgs
    {
        MultiSourceMediaFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        MultiSourceMediaFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MultiSourceMediaFrameReader : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReader,
        impl::require<MultiSourceMediaFrameReader, llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2>
    {
        MultiSourceMediaFrameReader(std::nullptr_t) noexcept {}
        MultiSourceMediaFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MultiSourceMediaFrameReference : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReference
    {
        MultiSourceMediaFrameReference(std::nullptr_t) noexcept {}
        MultiSourceMediaFrameReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReference(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoMediaFrame : llm:OS::Media::Capture::Frames::IVideoMediaFrame
    {
        VideoMediaFrame(std::nullptr_t) noexcept {}
        VideoMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IVideoMediaFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoMediaFrameFormat : llm:OS::Media::Capture::Frames::IVideoMediaFrameFormat
    {
        VideoMediaFrameFormat(std::nullptr_t) noexcept {}
        VideoMediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::Frames::IVideoMediaFrameFormat(ptr, take_ownership_from_abi) {}
    };
}
#endif
