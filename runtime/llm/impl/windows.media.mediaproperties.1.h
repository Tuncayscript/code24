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
#ifndef LLM_OS_Media_MediaProperties_1_H
#define LLM_OS_Media_MediaProperties_1_H
#include "llm/impl/Windows.Media.MediaProperties.0.h"
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct __declspec(empty_bases) IAudioEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingProperties>,
        impl::require<llm:OS::Media::MediaProperties::IAudioEncodingProperties, llm:OS::Media::MediaProperties::IMediaEncodingProperties>
    {
        IAudioEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEncodingProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingProperties2>
    {
        IAudioEncodingProperties2(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEncodingProperties3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingProperties3>
    {
        IAudioEncodingProperties3(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingProperties3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEncodingPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingPropertiesStatics>
    {
        IAudioEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEncodingPropertiesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingPropertiesStatics2>
    {
        IAudioEncodingPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingPropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioEncodingPropertiesWithFormatUserData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioEncodingPropertiesWithFormatUserData>
    {
        IAudioEncodingPropertiesWithFormatUserData(std::nullptr_t = nullptr) noexcept {}
        IAudioEncodingPropertiesWithFormatUserData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAv1ProfileIdsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAv1ProfileIdsStatics>
    {
        IAv1ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IAv1ProfileIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContainerEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContainerEncodingProperties>,
        impl::require<llm:OS::Media::MediaProperties::IContainerEncodingProperties, llm:OS::Media::MediaProperties::IMediaEncodingProperties>
    {
        IContainerEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        IContainerEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContainerEncodingProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContainerEncodingProperties2>
    {
        IContainerEncodingProperties2(std::nullptr_t = nullptr) noexcept {}
        IContainerEncodingProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IH264ProfileIdsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IH264ProfileIdsStatics>
    {
        IH264ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IH264ProfileIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHevcProfileIdsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHevcProfileIdsStatics>
    {
        IHevcProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IHevcProfileIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageEncodingProperties>,
        impl::require<llm:OS::Media::MediaProperties::IImageEncodingProperties, llm:OS::Media::MediaProperties::IMediaEncodingProperties>
    {
        IImageEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        IImageEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageEncodingProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageEncodingProperties2>
    {
        IImageEncodingProperties2(std::nullptr_t = nullptr) noexcept {}
        IImageEncodingProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageEncodingPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageEncodingPropertiesStatics>
    {
        IImageEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IImageEncodingPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageEncodingPropertiesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageEncodingPropertiesStatics2>
    {
        IImageEncodingPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IImageEncodingPropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageEncodingPropertiesStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageEncodingPropertiesStatics3>
    {
        IImageEncodingPropertiesStatics3(std::nullptr_t = nullptr) noexcept {}
        IImageEncodingPropertiesStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfile>
    {
        IMediaEncodingProfile(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfile2>
    {
        IMediaEncodingProfile2(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfile3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfile3>
    {
        IMediaEncodingProfile3(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfile3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfileStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfileStatics>
    {
        IMediaEncodingProfileStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfileStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfileStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfileStatics2>
    {
        IMediaEncodingProfileStatics2(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfileStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfileStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfileStatics3>
    {
        IMediaEncodingProfileStatics3(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfileStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProfileStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProfileStatics4>
    {
        IMediaEncodingProfileStatics4(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProfileStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingProperties>
    {
        IMediaEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics>
    {
        IMediaEncodingSubtypesStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics2>
    {
        IMediaEncodingSubtypesStatics2(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics3>
    {
        IMediaEncodingSubtypesStatics3(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics4>
    {
        IMediaEncodingSubtypesStatics4(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics5>
    {
        IMediaEncodingSubtypesStatics5(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics6>
    {
        IMediaEncodingSubtypesStatics6(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaEncodingSubtypesStatics7 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaEncodingSubtypesStatics7>
    {
        IMediaEncodingSubtypesStatics7(std::nullptr_t = nullptr) noexcept {}
        IMediaEncodingSubtypesStatics7(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaRatio :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaRatio>
    {
        IMediaRatio(std::nullptr_t = nullptr) noexcept {}
        IMediaRatio(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMpeg2ProfileIdsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMpeg2ProfileIdsStatics>
    {
        IMpeg2ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IMpeg2ProfileIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataEncodingProperties>
    {
        ITimedMetadataEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimedMetadataEncodingPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimedMetadataEncodingPropertiesStatics>
    {
        ITimedMetadataEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        ITimedMetadataEncodingPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingProperties>,
        impl::require<llm:OS::Media::MediaProperties::IVideoEncodingProperties, llm:OS::Media::MediaProperties::IMediaEncodingProperties>
    {
        IVideoEncodingProperties(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingProperties2>
    {
        IVideoEncodingProperties2(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingProperties3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingProperties3>
    {
        IVideoEncodingProperties3(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingProperties3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingProperties4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingProperties4>
    {
        IVideoEncodingProperties4(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingProperties4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingProperties5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingProperties5>
    {
        IVideoEncodingProperties5(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingProperties5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingPropertiesStatics>
    {
        IVideoEncodingPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingPropertiesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingPropertiesStatics2>
    {
        IVideoEncodingPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingPropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoEncodingPropertiesStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoEncodingPropertiesStatics3>
    {
        IVideoEncodingPropertiesStatics3(std::nullptr_t = nullptr) noexcept {}
        IVideoEncodingPropertiesStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVp9ProfileIdsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVp9ProfileIdsStatics>
    {
        IVp9ProfileIdsStatics(std::nullptr_t = nullptr) noexcept {}
        IVp9ProfileIdsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
