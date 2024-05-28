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
#ifndef LLM_OS_Graphics_Imaging_H
#define LLM_OS_Graphics_Imaging_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Graphics_Imaging_IBitmapBuffer<D>::GetPlaneCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapBuffer)->GetPlaneCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPlaneDescription) consume_Windows_Graphics_Imaging_IBitmapBuffer<D>::GetPlaneDescription(int32_t index) const
    {
        llm::OS::Graphics::Imaging::BitmapPlaneDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapBuffer)->GetPlaneDescription(index, put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapCodecInformation<D>::CodecId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapCodecInformation)->get_CodecId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Graphics_Imaging_IBitmapCodecInformation<D>::FileExtensions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapCodecInformation)->get_FileExtensions(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Imaging_IBitmapCodecInformation<D>::FriendlyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapCodecInformation)->get_FriendlyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Graphics_Imaging_IBitmapCodecInformation<D>::MimeTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapCodecInformation)->get_MimeTypes(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPropertiesView) consume_Windows_Graphics_Imaging_IBitmapDecoder<D>::BitmapContainerProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoder)->get_BitmapContainerProperties(&value));
        return llm::OS::Graphics::Imaging::BitmapPropertiesView{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapCodecInformation) consume_Windows_Graphics_Imaging_IBitmapDecoder<D>::DecoderInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoder)->get_DecoderInformation(&value));
        return llm::OS::Graphics::Imaging::BitmapCodecInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapDecoder<D>::FrameCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoder)->get_FrameCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>) consume_Windows_Graphics_Imaging_IBitmapDecoder<D>::GetPreviewAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoder)->GetPreviewAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapFrame>) consume_Windows_Graphics_Imaging_IBitmapDecoder<D>::GetFrameAsync(uint32_t frameIndex) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoder)->GetFrameAsync(frameIndex, &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapFrame>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::BmpDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_BmpDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::JpegDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_JpegDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::PngDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_PngDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::TiffDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_TiffDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::GifDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_GifDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::JpegXRDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_JpegXRDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::IcoDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->get_IcoDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::GetDecoderInformationEnumerator() const
    {
        void* decoderInformationEnumerator{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->GetDecoderInformationEnumerator(&decoderInformationEnumerator));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>{ decoderInformationEnumerator, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::CreateAsync(llm::OS::Storage::Streams::IRandomAccessStream const& stream) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->CreateAsync(*(void**)(&stream), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics<D>::CreateAsync(llm::guid const& decoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics)->CreateWithIdAsync(impl::bind_in(decoderId), *(void**)(&stream), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics2<D>::HeifDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics2)->get_HeifDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapDecoderStatics2<D>::WebpDecoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapDecoderStatics2)->get_WebpDecoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapCodecInformation) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::EncoderInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_EncoderInformation(&value));
        return llm::OS::Graphics::Imaging::BitmapCodecInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapProperties) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::BitmapProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_BitmapProperties(&value));
        return llm::OS::Graphics::Imaging::BitmapProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapProperties) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::BitmapContainerProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_BitmapContainerProperties(&value));
        return llm::OS::Graphics::Imaging::BitmapProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::IsThumbnailGenerated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_IsThumbnailGenerated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::IsThumbnailGenerated(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->put_IsThumbnailGenerated(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GeneratedThumbnailWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_GeneratedThumbnailWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GeneratedThumbnailWidth(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->put_GeneratedThumbnailWidth(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GeneratedThumbnailHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_GeneratedThumbnailHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GeneratedThumbnailHeight(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->put_GeneratedThumbnailHeight(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapTransform) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::BitmapTransform() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->get_BitmapTransform(&value));
        return llm::OS::Graphics::Imaging::BitmapTransform{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::SetPixelData(llm::OS::Graphics::Imaging::BitmapPixelFormat const& pixelFormat, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, array_view<uint8_t const> pixels) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->SetPixelData(static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), width, height, dpiX, dpiY, pixels.size(), get_abi(pixels)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GoToNextFrameAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->GoToNextFrameAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::GoToNextFrameAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const& encodingOptions) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->GoToNextFrameWithEncodingOptionsAsync(*(void**)(&encodingOptions), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Imaging_IBitmapEncoder<D>::FlushAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoder)->FlushAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::BmpEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_BmpEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::JpegEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_JpegEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::PngEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_PngEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::TiffEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_TiffEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::GifEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_GifEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::JpegXREncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->get_JpegXREncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::GetEncoderInformationEnumerator() const
    {
        void* encoderInformationEnumerator{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->GetEncoderInformationEnumerator(&encoderInformationEnumerator));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>{ encoderInformationEnumerator, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::CreateAsync(llm::guid const& encoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->CreateAsync(impl::bind_in(encoderId), *(void**)(&stream), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::CreateAsync(llm::guid const& encoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream, param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const& encodingOptions) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->CreateWithEncodingOptionsAsync(impl::bind_in(encoderId), *(void**)(&stream), *(void**)(&encodingOptions), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::CreateForTranscodingAsync(llm::OS::Storage::Streams::IRandomAccessStream const& stream, llm::OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->CreateForTranscodingAsync(*(void**)(&stream), *(void**)(&bitmapDecoder), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics<D>::CreateForInPlacePropertyEncodingAsync(llm::OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics)->CreateForInPlacePropertyEncodingAsync(*(void**)(&bitmapDecoder), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Graphics_Imaging_IBitmapEncoderStatics2<D>::HeifEncoderId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderStatics2)->get_HeifEncoderId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapEncoderWithSoftwareBitmap<D>::SetSoftwareBitmap(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap)->SetSoftwareBitmap(*(void**)(&bitmap)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::GetThumbnailAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->GetThumbnailAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPropertiesView) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::BitmapProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_BitmapProperties(&value));
        return llm::OS::Graphics::Imaging::BitmapPropertiesView{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPixelFormat) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::BitmapPixelFormat() const
    {
        llm::OS::Graphics::Imaging::BitmapPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_BitmapPixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapAlphaMode) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::BitmapAlphaMode() const
    {
        llm::OS::Graphics::Imaging::BitmapAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_BitmapAlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::DpiX() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_DpiX(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::DpiY() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_DpiY(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::PixelWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_PixelWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::PixelHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_PixelHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::OrientedPixelWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_OrientedPixelWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::OrientedPixelHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->get_OrientedPixelHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::GetPixelDataAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->GetPixelDataAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>) consume_Windows_Graphics_Imaging_IBitmapFrame<D>::GetPixelDataAsync(llm::OS::Graphics::Imaging::BitmapPixelFormat const& pixelFormat, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alphaMode, llm::OS::Graphics::Imaging::BitmapTransform const& transform, llm::OS::Graphics::Imaging::ExifOrientationMode const& exifOrientationMode, llm::OS::Graphics::Imaging::ColorManagementMode const& colorManagementMode) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrame)->GetPixelDataTransformedAsync(static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), *(void**)(&transform), static_cast<int32_t>(exifOrientationMode), static_cast<int32_t>(colorManagementMode), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>) consume_Windows_Graphics_Imaging_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap)->GetSoftwareBitmapAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>) consume_Windows_Graphics_Imaging_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync(llm::OS::Graphics::Imaging::BitmapPixelFormat const& pixelFormat, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alphaMode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap)->GetSoftwareBitmapConvertedAsync(static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>) consume_Windows_Graphics_Imaging_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync(llm::OS::Graphics::Imaging::BitmapPixelFormat const& pixelFormat, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alphaMode, llm::OS::Graphics::Imaging::BitmapTransform const& transform, llm::OS::Graphics::Imaging::ExifOrientationMode const& exifOrientationMode, llm::OS::Graphics::Imaging::ColorManagementMode const& colorManagementMode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap)->GetSoftwareBitmapTransformedAsync(static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), *(void**)(&transform), static_cast<int32_t>(exifOrientationMode), static_cast<int32_t>(colorManagementMode), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Imaging_IBitmapProperties<D>::SetPropertiesAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const& propertiesToSet) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapProperties)->SetPropertiesAsync(*(void**)(&propertiesToSet), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapPropertySet>) consume_Windows_Graphics_Imaging_IBitmapPropertiesView<D>::GetPropertiesAsync(param::async_iterable<hstring> const& propertiesToRetrieve) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapPropertiesView)->GetPropertiesAsync(*(void**)(&propertiesToRetrieve), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapPropertySet>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::ScaledWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_ScaledWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::ScaledWidth(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_ScaledWidth(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::ScaledHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_ScaledHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::ScaledHeight(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_ScaledHeight(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapInterpolationMode) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::InterpolationMode() const
    {
        llm::OS::Graphics::Imaging::BitmapInterpolationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_InterpolationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::InterpolationMode(llm::OS::Graphics::Imaging::BitmapInterpolationMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_InterpolationMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapFlip) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Flip() const
    {
        llm::OS::Graphics::Imaging::BitmapFlip value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_Flip(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Flip(llm::OS::Graphics::Imaging::BitmapFlip const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_Flip(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapRotation) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Rotation() const
    {
        llm::OS::Graphics::Imaging::BitmapRotation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_Rotation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Rotation(llm::OS::Graphics::Imaging::BitmapRotation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_Rotation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapBounds) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Bounds() const
    {
        llm::OS::Graphics::Imaging::BitmapBounds value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->get_Bounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_IBitmapTransform<D>::Bounds(llm::OS::Graphics::Imaging::BitmapBounds const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTransform)->put_Bounds(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Graphics_Imaging_IBitmapTypedValue<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTypedValue)->get_Value(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::PropertyType) consume_Windows_Graphics_Imaging_IBitmapTypedValue<D>::Type() const
    {
        llm::OS::Foundation::PropertyType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTypedValue)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapTypedValue) consume_Windows_Graphics_Imaging_IBitmapTypedValueFactory<D>::Create(llm::OS::Foundation::IInspectable const& value, llm::OS::Foundation::PropertyType const& type) const
    {
        void* bitmapTypedValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IBitmapTypedValueFactory)->Create(*(void**)(&value), static_cast<int32_t>(type), &bitmapTypedValue));
        return llm::OS::Graphics::Imaging::BitmapTypedValue{ bitmapTypedValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<uint8_t>) consume_Windows_Graphics_Imaging_IPixelDataProvider<D>::DetachPixelData() const
    {
        uint32_t pixelData_impl_size{};
        uint8_t* pixelData{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::IPixelDataProvider)->DetachPixelData(&pixelData_impl_size, &pixelData));
        return com_array<uint8_t>{ pixelData, pixelData_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPixelFormat) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::BitmapPixelFormat() const
    {
        llm::OS::Graphics::Imaging::BitmapPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_BitmapPixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapAlphaMode) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::BitmapAlphaMode() const
    {
        llm::OS::Graphics::Imaging::BitmapAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_BitmapAlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::PixelWidth() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_PixelWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::PixelHeight() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_PixelHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::DpiX(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->put_DpiX(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::DpiX() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_DpiX(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::DpiY(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->put_DpiY(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::DpiY() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->get_DpiY(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapBuffer) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::LockBuffer(llm::OS::Graphics::Imaging::BitmapBufferAccessMode const& mode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->LockBuffer(static_cast<int32_t>(mode), &value));
        return llm::OS::Graphics::Imaging::BitmapBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::CopyTo(llm::OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->CopyTo(*(void**)(&bitmap)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::CopyFromBuffer(llm::OS::Storage::Streams::IBuffer const& buffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->CopyFromBuffer(*(void**)(&buffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::CopyToBuffer(llm::OS::Storage::Streams::IBuffer const& buffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->CopyToBuffer(*(void**)(&buffer)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmap<D>::GetReadOnlyView() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmap)->GetReadOnlyView(&value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapFactory<D>::Create(llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapFactory)->Create(static_cast<int32_t>(format), width, height, &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapFactory<D>::CreateWithAlpha(llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapFactory)->CreateWithAlpha(static_cast<int32_t>(format), width, height, static_cast<int32_t>(alpha), &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::Copy(llm::OS::Graphics::Imaging::SoftwareBitmap const& source) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->Copy(*(void**)(&source), &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::Convert(llm::OS::Graphics::Imaging::SoftwareBitmap const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->Convert(*(void**)(&source), static_cast<int32_t>(format), &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::Convert(llm::OS::Graphics::Imaging::SoftwareBitmap const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->ConvertWithAlpha(*(void**)(&source), static_cast<int32_t>(format), static_cast<int32_t>(alpha), &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::CreateCopyFromBuffer(llm::OS::Storage::Streams::IBuffer const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->CreateCopyFromBuffer(*(void**)(&source), static_cast<int32_t>(format), width, height, &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::CreateCopyFromBuffer(llm::OS::Storage::Streams::IBuffer const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->CreateCopyWithAlphaFromBuffer(*(void**)(&source), static_cast<int32_t>(format), width, height, static_cast<int32_t>(alpha), &value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::CreateCopyFromSurfaceAsync(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->CreateCopyFromSurfaceAsync(*(void**)(&surface), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>) consume_Windows_Graphics_Imaging_ISoftwareBitmapStatics<D>::CreateCopyFromSurfaceAsync(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Imaging::ISoftwareBitmapStatics)->CreateCopyWithAlphaFromSurfaceAsync(*(void**)(&surface), static_cast<int32_t>(alpha), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapBuffer> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapBuffer>
    {
        int32_t __stdcall GetPlaneCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().GetPlaneCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPlaneDescription(int32_t index, struct struct_Windows_Graphics_Imaging_BitmapPlaneDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapPlaneDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPlaneDescription>(this->shim().GetPlaneDescription(index));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapCodecInformation> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapCodecInformation>
    {
        int32_t __stdcall get_CodecId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().CodecId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FileExtensions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().FileExtensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FriendlyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FriendlyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MimeTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().MimeTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapDecoder> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapDecoder>
    {
        int32_t __stdcall get_BitmapContainerProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPropertiesView>(this->shim().BitmapContainerProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DecoderInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapCodecInformation>(this->shim().DecoderInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().FrameCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPreviewAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>>(this->shim().GetPreviewAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFrameAsync(uint32_t frameIndex, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapFrame>>(this->shim().GetFrameAsync(frameIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapDecoderStatics> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapDecoderStatics>
    {
        int32_t __stdcall get_BmpDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().BmpDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_JpegDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().JpegDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PngDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().PngDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TiffDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().TiffDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GifDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().GifDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_JpegXRDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().JpegXRDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IcoDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().IcoDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDecoderInformationEnumerator(void** decoderInformationEnumerator) noexcept final try
        {
            clear_abi(decoderInformationEnumerator);
            typename D::abi_guard guard(this->shim());
            *decoderInformationEnumerator = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>>(this->shim().GetDecoderInformationEnumerator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAsync(void* stream, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithIdAsync(llm::guid decoderId, void* stream, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapDecoder>>(this->shim().CreateAsync(*reinterpret_cast<llm::guid const*>(&decoderId), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapDecoderStatics2> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapDecoderStatics2>
    {
        int32_t __stdcall get_HeifDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().HeifDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WebpDecoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().WebpDecoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapEncoder> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapEncoder>
    {
        int32_t __stdcall get_EncoderInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapCodecInformation>(this->shim().EncoderInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapProperties>(this->shim().BitmapProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapContainerProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapProperties>(this->shim().BitmapContainerProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsThumbnailGenerated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsThumbnailGenerated());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsThumbnailGenerated(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsThumbnailGenerated(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GeneratedThumbnailWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().GeneratedThumbnailWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GeneratedThumbnailWidth(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedThumbnailWidth(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GeneratedThumbnailHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().GeneratedThumbnailHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GeneratedThumbnailHeight(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedThumbnailHeight(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapTransform(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapTransform>(this->shim().BitmapTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPixelData(int32_t pixelFormat, int32_t alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, uint32_t __pixelsSize, uint8_t* pixels) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPixelData(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alphaMode), width, height, dpiX, dpiY, array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(pixels), reinterpret_cast<uint8_t const *>(pixels) + __pixelsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GoToNextFrameAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().GoToNextFrameAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GoToNextFrameWithEncodingOptionsAsync(void* encodingOptions, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().GoToNextFrameAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const*>(&encodingOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FlushAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().FlushAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapEncoderStatics> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapEncoderStatics>
    {
        int32_t __stdcall get_BmpEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().BmpEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_JpegEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().JpegEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PngEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().PngEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TiffEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().TiffEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GifEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().GifEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_JpegXREncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().JpegXREncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetEncoderInformationEnumerator(void** encoderInformationEnumerator) noexcept final try
        {
            clear_abi(encoderInformationEnumerator);
            typename D::abi_guard guard(this->shim());
            *encoderInformationEnumerator = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>>(this->shim().GetEncoderInformationEnumerator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAsync(llm::guid encoderId, void* stream, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>>(this->shim().CreateAsync(*reinterpret_cast<llm::guid const*>(&encoderId), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithEncodingOptionsAsync(llm::guid encoderId, void* stream, void* encodingOptions, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>>(this->shim().CreateAsync(*reinterpret_cast<llm::guid const*>(&encoderId), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const*>(&encodingOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateForTranscodingAsync(void* stream, void* bitmapDecoder, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>>(this->shim().CreateForTranscodingAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&stream), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapDecoder const*>(&bitmapDecoder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateForInPlacePropertyEncodingAsync(void* bitmapDecoder, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapEncoder>>(this->shim().CreateForInPlacePropertyEncodingAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapDecoder const*>(&bitmapDecoder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapEncoderStatics2> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapEncoderStatics2>
    {
        int32_t __stdcall get_HeifEncoderId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().HeifEncoderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
    {
        int32_t __stdcall SetSoftwareBitmap(void* bitmap) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSoftwareBitmap(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&bitmap));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapFrame> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapFrame>
    {
        int32_t __stdcall GetThumbnailAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>>(this->shim().GetThumbnailAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPropertiesView>(this->shim().BitmapProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapPixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPixelFormat>(this->shim().BitmapPixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapAlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapAlphaMode>(this->shim().BitmapAlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DpiX(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DpiX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DpiY(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DpiY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PixelWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PixelHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OrientedPixelWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OrientedPixelWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OrientedPixelHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().OrientedPixelHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPixelDataAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>>(this->shim().GetPixelDataAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPixelDataTransformedAsync(int32_t pixelFormat, int32_t alphaMode, void* transform, int32_t exifOrientationMode, int32_t colorManagementMode, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::PixelDataProvider>>(this->shim().GetPixelDataAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alphaMode), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapTransform const*>(&transform), *reinterpret_cast<llm::OS::Graphics::Imaging::ExifOrientationMode const*>(&exifOrientationMode), *reinterpret_cast<llm::OS::Graphics::Imaging::ColorManagementMode const*>(&colorManagementMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
    {
        int32_t __stdcall GetSoftwareBitmapAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>>(this->shim().GetSoftwareBitmapAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSoftwareBitmapConvertedAsync(int32_t pixelFormat, int32_t alphaMode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>>(this->shim().GetSoftwareBitmapAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alphaMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSoftwareBitmapTransformedAsync(int32_t pixelFormat, int32_t alphaMode, void* transform, int32_t exifOrientationMode, int32_t colorManagementMode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>>(this->shim().GetSoftwareBitmapAsync(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alphaMode), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapTransform const*>(&transform), *reinterpret_cast<llm::OS::Graphics::Imaging::ExifOrientationMode const*>(&exifOrientationMode), *reinterpret_cast<llm::OS::Graphics::Imaging::ColorManagementMode const*>(&colorManagementMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapProperties> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapProperties>
    {
        int32_t __stdcall SetPropertiesAsync(void* propertiesToSet, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetPropertiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const*>(&propertiesToSet)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapPropertiesView> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapPropertiesView>
    {
        int32_t __stdcall GetPropertiesAsync(void* propertiesToRetrieve, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::BitmapPropertySet>>(this->shim().GetPropertiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapTransform> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapTransform>
    {
        int32_t __stdcall get_ScaledWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ScaledWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ScaledWidth(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaledWidth(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScaledHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ScaledHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ScaledHeight(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaledHeight(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InterpolationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapInterpolationMode>(this->shim().InterpolationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InterpolationMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InterpolationMode(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapInterpolationMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Flip(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapFlip>(this->shim().Flip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Flip(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Flip(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapFlip const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rotation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapRotation>(this->shim().Rotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rotation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapRotation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bounds(struct struct_Windows_Graphics_Imaging_BitmapBounds* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapBounds>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapBounds>(this->shim().Bounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Bounds(struct struct_Windows_Graphics_Imaging_BitmapBounds value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bounds(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapBounds const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapTypedValue> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapTypedValue>
    {
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::PropertyType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IBitmapTypedValueFactory> : produce_base<D, llm::OS::Graphics::Imaging::IBitmapTypedValueFactory>
    {
        int32_t __stdcall Create(void* value, int32_t type, void** bitmapTypedValue) noexcept final try
        {
            clear_abi(bitmapTypedValue);
            typename D::abi_guard guard(this->shim());
            *bitmapTypedValue = detach_from<llm::OS::Graphics::Imaging::BitmapTypedValue>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value), *reinterpret_cast<llm::OS::Foundation::PropertyType const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::IPixelDataProvider> : produce_base<D, llm::OS::Graphics::Imaging::IPixelDataProvider>
    {
        int32_t __stdcall DetachPixelData(uint32_t* __pixelDataSize, uint8_t** pixelData) noexcept final try
        {
            clear_abi(pixelData);
            typename D::abi_guard guard(this->shim());
            std::tie(*__pixelDataSize, *pixelData) = detach_abi(this->shim().DetachPixelData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::ISoftwareBitmap> : produce_base<D, llm::OS::Graphics::Imaging::ISoftwareBitmap>
    {
        int32_t __stdcall get_BitmapPixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPixelFormat>(this->shim().BitmapPixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapAlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapAlphaMode>(this->shim().BitmapAlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelWidth(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PixelWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelHeight(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PixelHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DpiX(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiX(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DpiX(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DpiX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DpiY(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiY(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DpiY(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DpiY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LockBuffer(int32_t mode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapBuffer>(this->shim().LockBuffer(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapBufferAccessMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyTo(void* bitmap) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyTo(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&bitmap));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyFromBuffer(void* buffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyFromBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&buffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CopyToBuffer(void* buffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyToBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&buffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetReadOnlyView(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().GetReadOnlyView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::ISoftwareBitmapFactory> : produce_base<D, llm::OS::Graphics::Imaging::ISoftwareBitmapFactory>
    {
        int32_t __stdcall Create(int32_t format, int32_t width, int32_t height, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().Create(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format), width, height));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAlpha(int32_t format, int32_t width, int32_t height, int32_t alpha, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().CreateWithAlpha(*reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format), width, height, *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alpha)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Imaging::ISoftwareBitmapStatics> : produce_base<D, llm::OS::Graphics::Imaging::ISoftwareBitmapStatics>
    {
        int32_t __stdcall Copy(void* source, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().Copy(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&source)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Convert(void* source, int32_t format, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().Convert(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&source), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConvertWithAlpha(void* source, int32_t format, int32_t alpha, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().Convert(*reinterpret_cast<llm::OS::Graphics::Imaging::SoftwareBitmap const*>(&source), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alpha)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCopyFromBuffer(void* source, int32_t format, int32_t width, int32_t height, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().CreateCopyFromBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&source), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format), width, height));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCopyWithAlphaFromBuffer(void* source, int32_t format, int32_t width, int32_t height, int32_t alpha, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().CreateCopyFromBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&source), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapPixelFormat const*>(&format), width, height, *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alpha)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCopyFromSurfaceAsync(void* surface, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>>(this->shim().CreateCopyFromSurfaceAsync(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&surface)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCopyWithAlphaFromSurfaceAsync(void* surface, int32_t alpha, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::SoftwareBitmap>>(this->shim().CreateCopyFromSurfaceAsync(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&surface), *reinterpret_cast<llm::OS::Graphics::Imaging::BitmapAlphaMode const*>(&alpha)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Graphics::Imaging
{
    inline auto BitmapDecoder::BmpDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.BmpDecoderId(); });
    }
    inline auto BitmapDecoder::JpegDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.JpegDecoderId(); });
    }
    inline auto BitmapDecoder::PngDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.PngDecoderId(); });
    }
    inline auto BitmapDecoder::TiffDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.TiffDecoderId(); });
    }
    inline auto BitmapDecoder::GifDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.GifDecoderId(); });
    }
    inline auto BitmapDecoder::JpegXRDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.JpegXRDecoderId(); });
    }
    inline auto BitmapDecoder::IcoDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.IcoDecoderId(); });
    }
    inline auto BitmapDecoder::GetDecoderInformationEnumerator()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>(*)(IBitmapDecoderStatics const&), BitmapDecoder, IBitmapDecoderStatics>([](IBitmapDecoderStatics const& f) { return f.GetDecoderInformationEnumerator(); });
    }
    inline auto BitmapDecoder::CreateAsync(llm::OS::Storage::Streams::IRandomAccessStream const& stream)
    {
        return impl::call_factory<BitmapDecoder, IBitmapDecoderStatics>([&](IBitmapDecoderStatics const& f) { return f.CreateAsync(stream); });
    }
    inline auto BitmapDecoder::CreateAsync(llm::guid const& decoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream)
    {
        return impl::call_factory<BitmapDecoder, IBitmapDecoderStatics>([&](IBitmapDecoderStatics const& f) { return f.CreateAsync(decoderId, stream); });
    }
    inline auto BitmapDecoder::HeifDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics2 const&), BitmapDecoder, IBitmapDecoderStatics2>([](IBitmapDecoderStatics2 const& f) { return f.HeifDecoderId(); });
    }
    inline auto BitmapDecoder::WebpDecoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapDecoderStatics2 const&), BitmapDecoder, IBitmapDecoderStatics2>([](IBitmapDecoderStatics2 const& f) { return f.WebpDecoderId(); });
    }
    inline auto BitmapEncoder::BmpEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.BmpEncoderId(); });
    }
    inline auto BitmapEncoder::JpegEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.JpegEncoderId(); });
    }
    inline auto BitmapEncoder::PngEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.PngEncoderId(); });
    }
    inline auto BitmapEncoder::TiffEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.TiffEncoderId(); });
    }
    inline auto BitmapEncoder::GifEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.GifEncoderId(); });
    }
    inline auto BitmapEncoder::JpegXREncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.JpegXREncoderId(); });
    }
    inline auto BitmapEncoder::GetEncoderInformationEnumerator()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::BitmapCodecInformation>(*)(IBitmapEncoderStatics const&), BitmapEncoder, IBitmapEncoderStatics>([](IBitmapEncoderStatics const& f) { return f.GetEncoderInformationEnumerator(); });
    }
    inline auto BitmapEncoder::CreateAsync(llm::guid const& encoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream)
    {
        return impl::call_factory<BitmapEncoder, IBitmapEncoderStatics>([&](IBitmapEncoderStatics const& f) { return f.CreateAsync(encoderId, stream); });
    }
    inline auto BitmapEncoder::CreateAsync(llm::guid const& encoderId, llm::OS::Storage::Streams::IRandomAccessStream const& stream, param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Graphics::Imaging::BitmapTypedValue>> const& encodingOptions)
    {
        return impl::call_factory<BitmapEncoder, IBitmapEncoderStatics>([&](IBitmapEncoderStatics const& f) { return f.CreateAsync(encoderId, stream, encodingOptions); });
    }
    inline auto BitmapEncoder::CreateForTranscodingAsync(llm::OS::Storage::Streams::IRandomAccessStream const& stream, llm::OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder)
    {
        return impl::call_factory<BitmapEncoder, IBitmapEncoderStatics>([&](IBitmapEncoderStatics const& f) { return f.CreateForTranscodingAsync(stream, bitmapDecoder); });
    }
    inline auto BitmapEncoder::CreateForInPlacePropertyEncodingAsync(llm::OS::Graphics::Imaging::BitmapDecoder const& bitmapDecoder)
    {
        return impl::call_factory<BitmapEncoder, IBitmapEncoderStatics>([&](IBitmapEncoderStatics const& f) { return f.CreateForInPlacePropertyEncodingAsync(bitmapDecoder); });
    }
    inline auto BitmapEncoder::HeifEncoderId()
    {
        return impl::call_factory_cast<llm::guid(*)(IBitmapEncoderStatics2 const&), BitmapEncoder, IBitmapEncoderStatics2>([](IBitmapEncoderStatics2 const& f) { return f.HeifEncoderId(); });
    }
    inline BitmapPropertySet::BitmapPropertySet() :
        BitmapPropertySet(impl::call_factory_cast<BitmapPropertySet(*)(llm::OS::Foundation::IActivationFactory const&), BitmapPropertySet>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BitmapPropertySet>(); }))
    {
    }
    inline BitmapTransform::BitmapTransform() :
        BitmapTransform(impl::call_factory_cast<BitmapTransform(*)(llm::OS::Foundation::IActivationFactory const&), BitmapTransform>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BitmapTransform>(); }))
    {
    }
    inline BitmapTypedValue::BitmapTypedValue(llm::OS::Foundation::IInspectable const& value, llm::OS::Foundation::PropertyType const& type) :
        BitmapTypedValue(impl::call_factory<BitmapTypedValue, IBitmapTypedValueFactory>([&](IBitmapTypedValueFactory const& f) { return f.Create(value, type); }))
    {
    }
    inline SoftwareBitmap::SoftwareBitmap(llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height) :
        SoftwareBitmap(impl::call_factory<SoftwareBitmap, ISoftwareBitmapFactory>([&](ISoftwareBitmapFactory const& f) { return f.Create(format, width, height); }))
    {
    }
    inline SoftwareBitmap::SoftwareBitmap(llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha) :
        SoftwareBitmap(impl::call_factory<SoftwareBitmap, ISoftwareBitmapFactory>([&](ISoftwareBitmapFactory const& f) { return f.CreateWithAlpha(format, width, height, alpha); }))
    {
    }
    inline auto SoftwareBitmap::Copy(llm::OS::Graphics::Imaging::SoftwareBitmap const& source)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.Copy(source); });
    }
    inline auto SoftwareBitmap::Convert(llm::OS::Graphics::Imaging::SoftwareBitmap const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.Convert(source, format); });
    }
    inline auto SoftwareBitmap::Convert(llm::OS::Graphics::Imaging::SoftwareBitmap const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.Convert(source, format, alpha); });
    }
    inline auto SoftwareBitmap::CreateCopyFromBuffer(llm::OS::Storage::Streams::IBuffer const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.CreateCopyFromBuffer(source, format, width, height); });
    }
    inline auto SoftwareBitmap::CreateCopyFromBuffer(llm::OS::Storage::Streams::IBuffer const& source, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, int32_t width, int32_t height, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.CreateCopyFromBuffer(source, format, width, height, alpha); });
    }
    inline auto SoftwareBitmap::CreateCopyFromSurfaceAsync(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.CreateCopyFromSurfaceAsync(surface); });
    }
    inline auto SoftwareBitmap::CreateCopyFromSurfaceAsync(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha)
    {
        return impl::call_factory<SoftwareBitmap, ISoftwareBitmapStatics>([&](ISoftwareBitmapStatics const& f) { return f.CreateCopyFromSurfaceAsync(surface, alpha); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapCodecInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapDecoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapDecoderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapDecoderStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapEncoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapEncoderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapEncoderStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapPropertiesView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapTypedValue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IBitmapTypedValueFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::IPixelDataProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::ISoftwareBitmap> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::ISoftwareBitmapFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::ISoftwareBitmapStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapCodecInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapDecoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapEncoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapPropertiesView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapPropertySet> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::BitmapTypedValue> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::ImageStream> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::PixelDataProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Imaging::SoftwareBitmap> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
