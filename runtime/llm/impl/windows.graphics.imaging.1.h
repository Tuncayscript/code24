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
#ifndef LLM_OS_Graphics_Imaging_1_H
#define LLM_OS_Graphics_Imaging_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Graphics.Imaging.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct __declspec(empty_bases) IBitmapBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapBuffer>,
        impl::require<llm:OS::Graphics::Imaging::IBitmapBuffer, llm:OS::Foundation::IClosable, llm:OS::Foundation::IMemoryBuffer>
    {
        IBitmapBuffer(std::nullptr_t = nullptr) noexcept {}
        IBitmapBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapCodecInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapCodecInformation>
    {
        IBitmapCodecInformation(std::nullptr_t = nullptr) noexcept {}
        IBitmapCodecInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapDecoder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapDecoder>
    {
        IBitmapDecoder(std::nullptr_t = nullptr) noexcept {}
        IBitmapDecoder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapDecoderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapDecoderStatics>
    {
        IBitmapDecoderStatics(std::nullptr_t = nullptr) noexcept {}
        IBitmapDecoderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapDecoderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapDecoderStatics2>
    {
        IBitmapDecoderStatics2(std::nullptr_t = nullptr) noexcept {}
        IBitmapDecoderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapEncoder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapEncoder>
    {
        IBitmapEncoder(std::nullptr_t = nullptr) noexcept {}
        IBitmapEncoder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapEncoderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapEncoderStatics>
    {
        IBitmapEncoderStatics(std::nullptr_t = nullptr) noexcept {}
        IBitmapEncoderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapEncoderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapEncoderStatics2>
    {
        IBitmapEncoderStatics2(std::nullptr_t = nullptr) noexcept {}
        IBitmapEncoderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapEncoderWithSoftwareBitmap :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapEncoderWithSoftwareBitmap>
    {
        IBitmapEncoderWithSoftwareBitmap(std::nullptr_t = nullptr) noexcept {}
        IBitmapEncoderWithSoftwareBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapFrame>
    {
        IBitmapFrame(std::nullptr_t = nullptr) noexcept {}
        IBitmapFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapFrameWithSoftwareBitmap :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapFrameWithSoftwareBitmap>,
        impl::require<llm:OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap, llm:OS::Graphics::Imaging::IBitmapFrame>
    {
        IBitmapFrameWithSoftwareBitmap(std::nullptr_t = nullptr) noexcept {}
        IBitmapFrameWithSoftwareBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapProperties>,
        impl::require<llm:OS::Graphics::Imaging::IBitmapProperties, llm:OS::Graphics::Imaging::IBitmapPropertiesView>
    {
        IBitmapProperties(std::nullptr_t = nullptr) noexcept {}
        IBitmapProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapPropertiesView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapPropertiesView>
    {
        IBitmapPropertiesView(std::nullptr_t = nullptr) noexcept {}
        IBitmapPropertiesView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapTransform :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapTransform>
    {
        IBitmapTransform(std::nullptr_t = nullptr) noexcept {}
        IBitmapTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapTypedValue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapTypedValue>
    {
        IBitmapTypedValue(std::nullptr_t = nullptr) noexcept {}
        IBitmapTypedValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBitmapTypedValueFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBitmapTypedValueFactory>
    {
        IBitmapTypedValueFactory(std::nullptr_t = nullptr) noexcept {}
        IBitmapTypedValueFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPixelDataProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPixelDataProvider>
    {
        IPixelDataProvider(std::nullptr_t = nullptr) noexcept {}
        IPixelDataProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISoftwareBitmap :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISoftwareBitmap>,
        impl::require<llm:OS::Graphics::Imaging::ISoftwareBitmap, llm:OS::Foundation::IClosable>
    {
        ISoftwareBitmap(std::nullptr_t = nullptr) noexcept {}
        ISoftwareBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISoftwareBitmapFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISoftwareBitmapFactory>
    {
        ISoftwareBitmapFactory(std::nullptr_t = nullptr) noexcept {}
        ISoftwareBitmapFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISoftwareBitmapStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISoftwareBitmapStatics>
    {
        ISoftwareBitmapStatics(std::nullptr_t = nullptr) noexcept {}
        ISoftwareBitmapStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
