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
#ifndef LLM_OS_Graphics_Imaging_2_H
#define LLM_OS_Graphics_Imaging_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Graphics.Imaging.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct BitmapBounds
    {
        uint32_t X;
        uint32_t Y;
        uint32_t Width;
        uint32_t Height;
    };
    inline bool operator==(BitmapBounds const& left, BitmapBounds const& right) noexcept
    {
        return left.X == right.X && left.Y == right.Y && left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(BitmapBounds const& left, BitmapBounds const& right) noexcept
    {
        return !(left == right);
    }
    struct BitmapPlaneDescription
    {
        int32_t StartIndex;
        int32_t Width;
        int32_t Height;
        int32_t Stride;
    };
    inline bool operator==(BitmapPlaneDescription const& left, BitmapPlaneDescription const& right) noexcept
    {
        return left.StartIndex == right.StartIndex && left.Width == right.Width && left.Height == right.Height && left.Stride == right.Stride;
    }
    inline bool operator!=(BitmapPlaneDescription const& left, BitmapPlaneDescription const& right) noexcept
    {
        return !(left == right);
    }
    struct BitmapSize
    {
        uint32_t Width;
        uint32_t Height;
    };
    inline bool operator==(BitmapSize const& left, BitmapSize const& right) noexcept
    {
        return left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(BitmapSize const& left, BitmapSize const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) BitmapBuffer : llm:OS::Graphics::Imaging::IBitmapBuffer
    {
        BitmapBuffer(std::nullptr_t) noexcept {}
        BitmapBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapBuffer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BitmapCodecInformation : llm:OS::Graphics::Imaging::IBitmapCodecInformation
    {
        BitmapCodecInformation(std::nullptr_t) noexcept {}
        BitmapCodecInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapCodecInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BitmapDecoder : llm:OS::Graphics::Imaging::IBitmapDecoder,
        impl::require<BitmapDecoder, llm:OS::Graphics::Imaging::IBitmapFrame, llm:OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
    {
        BitmapDecoder(std::nullptr_t) noexcept {}
        BitmapDecoder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapDecoder(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto BmpDecoderId();
        [[nodiscard]] static auto JpegDecoderId();
        [[nodiscard]] static auto PngDecoderId();
        [[nodiscard]] static auto TiffDecoderId();
        [[nodiscard]] static auto GifDecoderId();
        [[nodiscard]] static auto JpegXRDecoderId();
        [[nodiscard]] static auto IcoDecoderId();
        static auto GetDecoderInformationEnumerator();
        static auto CreateAsync(llm:OS::Storage::Streams::IRandomAccessStream const& stream);
        static auto CreateAsync(llm::guid const& decoderId, llm:OS::Storage::Streams::IRandomAccessStream const& stream);
        [[nodiscard]] static auto HeifDecoderId();
        [[nodiscard]] static auto WebpDecoderId();
    };
    struct __declspec(empty_bases) BitmapEncoder : llm:OS::Graphics::Imaging::IBitmapEncoder,
        impl::require<BitmapEncoder, llm:OS::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
    {
        BitmapEncoder(std::nullptr_t) noexcept {}
        BitmapEncoder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapEncoder(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto BmpEncoderId();
        [[nodiscard]] static auto JpegEncoderId();
        [[nodiscard]] static auto PngEncoderId();
        [[nodiscard]] static auto TiffEncoderId();
        [[nodiscard]] static auto GifEncoderId();
        [[nodiscard]] static auto JpegXREncoderId();
        static auto GetEncoderInformationEnumerator();
        static auto CreateAsync(llm::guid const& encoderId, llm:OS::Storage::Streams::IRandomAccessStream const& stream);
        static auto CreateAsync(llm::guid const& encoderId, llm:OS::Storage::Streams::IRandomAccessStream const& stream, param::async_iterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, llm:OS::Graphics::Imaging::BitmapTypedValue>> const& encodingOptions);
        static auto CreateForTranscodingAsync(llm:OS::Storage::Streams::IRandomAccessStream const& stream, llm:OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder);
        static auto CreateForInPlacePropertyEncodingAsync(llm:OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder);
        [[nodiscard]] static auto HeifEncoderId();
    };
    struct __declspec(empty_bases) BitmapFrame : llm:OS::Graphics::Imaging::IBitmapFrame,
        impl::require<BitmapFrame, llm:OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
    {
        BitmapFrame(std::nullptr_t) noexcept {}
        BitmapFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BitmapProperties : llm:OS::Graphics::Imaging::IBitmapProperties
    {
        BitmapProperties(std::nullptr_t) noexcept {}
        BitmapProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BitmapPropertiesView : llm:OS::Graphics::Imaging::IBitmapPropertiesView
    {
        BitmapPropertiesView(std::nullptr_t) noexcept {}
        BitmapPropertiesView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapPropertiesView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BitmapPropertySet : llm:OS::Foundation::Collections::IMap<hstring, llm:OS::Graphics::Imaging::BitmapTypedValue>
    {
        BitmapPropertySet(std::nullptr_t) noexcept {}
        BitmapPropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IMap<hstring, llm:OS::Graphics::Imaging::BitmapTypedValue>(ptr, take_ownership_from_abi) {}
        BitmapPropertySet();
    };
    struct __declspec(empty_bases) BitmapTransform : llm:OS::Graphics::Imaging::IBitmapTransform
    {
        BitmapTransform(std::nullptr_t) noexcept {}
        BitmapTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapTransform(ptr, take_ownership_from_abi) {}
        BitmapTransform();
    };
    struct __declspec(empty_bases) BitmapTypedValue : llm:OS::Graphics::Imaging::IBitmapTypedValue
    {
        BitmapTypedValue(std::nullptr_t) noexcept {}
        BitmapTypedValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IBitmapTypedValue(ptr, take_ownership_from_abi) {}
        BitmapTypedValue(llm:OS::Foundation::IInspectable const& value, llm:OS::Foundation::PropertyType const& type);
    };
    struct __declspec(empty_bases) ImageStream : llm:OS::Storage::Streams::IRandomAccessStreamWithContentType
    {
        ImageStream(std::nullptr_t) noexcept {}
        ImageStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStreamWithContentType(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PixelDataProvider : llm:OS::Graphics::Imaging::IPixelDataProvider
    {
        PixelDataProvider(std::nullptr_t) noexcept {}
        PixelDataProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::IPixelDataProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SoftwareBitmap : llm:OS::Graphics::Imaging::ISoftwareBitmap
    {
        SoftwareBitmap(std::nullptr_t) noexcept {}
        SoftwareBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Imaging::ISoftwareBitmap(ptr, take_ownership_from_abi) {}
        SoftwareBitmap(llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height);
        SoftwareBitmap(llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm:OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
        static auto Copy(llm:OS::Graphics::Imaging::SoftwareBitmap const& source);
        static auto Convert(llm:OS::Graphics::Imaging::SoftwareBitmap const& source, llm:OS::Graphics::Imaging::BitmapPixelFormat const& format);
        static auto Convert(llm:OS::Graphics::Imaging::SoftwareBitmap const& source, llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, llm:OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
        static auto CreateCopyFromBuffer(llm:OS::Storage::Streams::IBuffer const& source, llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height);
        static auto CreateCopyFromBuffer(llm:OS::Storage::Streams::IBuffer const& source, llm:OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm:OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
        static auto CreateCopyFromSurfaceAsync(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface);
        static auto CreateCopyFromSurfaceAsync(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm:OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
    };
}
#endif
