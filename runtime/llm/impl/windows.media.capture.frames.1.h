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
#ifndef LLM_OS_Media_Capture_Frames_1_H
#define LLM_OS_Media_Capture_Frames_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.Capture.Frames.0.h"
LLM_EXPORT namespace llm:OS::Media::Capture::Frames
{
    struct __declspec(empty_bases) IAudioMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioMediaFrame>
    {
        IAudioMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IAudioMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBufferMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBufferMediaFrame>
    {
        IBufferMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IBufferMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDepthMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDepthMediaFrame>
    {
        IDepthMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IDepthMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDepthMediaFrame2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDepthMediaFrame2>
    {
        IDepthMediaFrame2(std::nullptr_t = nullptr) noexcept {}
        IDepthMediaFrame2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDepthMediaFrameFormat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDepthMediaFrameFormat>
    {
        IDepthMediaFrameFormat(std::nullptr_t = nullptr) noexcept {}
        IDepthMediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInfraredMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInfraredMediaFrame>
    {
        IInfraredMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IInfraredMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameArrivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameArrivedEventArgs>
    {
        IMediaFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameFormat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameFormat>
    {
        IMediaFrameFormat(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameFormat2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameFormat2>
    {
        IMediaFrameFormat2(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameFormat2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameReader>,
        impl::require<llm:OS::Media::Capture::Frames::IMediaFrameReader, llm:OS::Foundation::IClosable>
    {
        IMediaFrameReader(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameReader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameReader2>
    {
        IMediaFrameReader2(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameReader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameReference>,
        impl::require<llm:OS::Media::Capture::Frames::IMediaFrameReference, llm:OS::Foundation::IClosable>
    {
        IMediaFrameReference(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameReference2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameReference2>
    {
        IMediaFrameReference2(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameReference2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSource>
    {
        IMediaFrameSource(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceController>
    {
        IMediaFrameSourceController(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceController2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceController2>
    {
        IMediaFrameSourceController2(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceController2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceController3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceController3>
    {
        IMediaFrameSourceController3(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceController3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceGetPropertyResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceGetPropertyResult>
    {
        IMediaFrameSourceGetPropertyResult(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceGetPropertyResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceGroup>
    {
        IMediaFrameSourceGroup(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceGroupStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceGroupStatics>
    {
        IMediaFrameSourceGroupStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceGroupStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceInfo>
    {
        IMediaFrameSourceInfo(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceInfo2>
    {
        IMediaFrameSourceInfo2(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceInfo3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceInfo3>
    {
        IMediaFrameSourceInfo3(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceInfo3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaFrameSourceInfo4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaFrameSourceInfo4>
    {
        IMediaFrameSourceInfo4(std::nullptr_t = nullptr) noexcept {}
        IMediaFrameSourceInfo4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMultiSourceMediaFrameArrivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMultiSourceMediaFrameArrivedEventArgs>
    {
        IMultiSourceMediaFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMultiSourceMediaFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMultiSourceMediaFrameReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMultiSourceMediaFrameReader>,
        impl::require<llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReader, llm:OS::Foundation::IClosable>
    {
        IMultiSourceMediaFrameReader(std::nullptr_t = nullptr) noexcept {}
        IMultiSourceMediaFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMultiSourceMediaFrameReader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMultiSourceMediaFrameReader2>
    {
        IMultiSourceMediaFrameReader2(std::nullptr_t = nullptr) noexcept {}
        IMultiSourceMediaFrameReader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMultiSourceMediaFrameReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMultiSourceMediaFrameReference>,
        impl::require<llm:OS::Media::Capture::Frames::IMultiSourceMediaFrameReference, llm:OS::Foundation::IClosable>
    {
        IMultiSourceMediaFrameReference(std::nullptr_t = nullptr) noexcept {}
        IMultiSourceMediaFrameReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoMediaFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoMediaFrame>
    {
        IVideoMediaFrame(std::nullptr_t = nullptr) noexcept {}
        IVideoMediaFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoMediaFrameFormat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoMediaFrameFormat>
    {
        IVideoMediaFrameFormat(std::nullptr_t = nullptr) noexcept {}
        IVideoMediaFrameFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
