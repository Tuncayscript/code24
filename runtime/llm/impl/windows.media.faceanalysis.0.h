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
#ifndef LLM_OS_Media_FaceAnalysis_0_H
#define LLM_OS_Media_FaceAnalysis_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct BitmapBounds;
    enum class BitmapPixelFormat : int32_t;
    struct BitmapSize;
    struct SoftwareBitmap;
}
LLM_EXPORT namespace llm:OS::Media
{
    struct VideoFrame;
}
LLM_EXPORT namespace llm:OS::Media::FaceAnalysis
{
    struct IDetectedFace;
    struct IFaceDetector;
    struct IFaceDetectorStatics;
    struct IFaceTracker;
    struct IFaceTrackerStatics;
    struct DetectedFace;
    struct FaceDetector;
    struct FaceTracker;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::FaceAnalysis::IDetectedFace>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::IFaceDetector>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::IFaceDetectorStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::IFaceTracker>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::IFaceTrackerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::DetectedFace>{ using type = class_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::FaceDetector>{ using type = class_category; };
    template <> struct category<llm:OS::Media::FaceAnalysis::FaceTracker>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::DetectedFace> = L"Windows.Media.FaceAnalysis.DetectedFace";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::FaceDetector> = L"Windows.Media.FaceAnalysis.FaceDetector";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::FaceTracker> = L"Windows.Media.FaceAnalysis.FaceTracker";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::IDetectedFace> = L"Windows.Media.FaceAnalysis.IDetectedFace";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::IFaceDetector> = L"Windows.Media.FaceAnalysis.IFaceDetector";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::IFaceDetectorStatics> = L"Windows.Media.FaceAnalysis.IFaceDetectorStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::IFaceTracker> = L"Windows.Media.FaceAnalysis.IFaceTracker";
    template <> inline constexpr auto& name_v<llm:OS::Media::FaceAnalysis::IFaceTrackerStatics> = L"Windows.Media.FaceAnalysis.IFaceTrackerStatics";
    template <> inline constexpr guid guid_v<llm:OS::Media::FaceAnalysis::IDetectedFace>{ 0x8200D454,0x66BC,0x34DF,{ 0x94,0x10,0xE8,0x94,0x00,0x19,0x54,0x14 } }; // 8200D454-66BC-34DF-9410-E89400195414
    template <> inline constexpr guid guid_v<llm:OS::Media::FaceAnalysis::IFaceDetector>{ 0x16B672DC,0xFE6F,0x3117,{ 0x8D,0x95,0xC3,0xF0,0x4D,0x51,0x63,0x0C } }; // 16B672DC-FE6F-3117-8D95-C3F04D51630C
    template <> inline constexpr guid guid_v<llm:OS::Media::FaceAnalysis::IFaceDetectorStatics>{ 0xBC042D67,0x9047,0x33F6,{ 0x88,0x1B,0x67,0x46,0xC1,0xB2,0x18,0xB8 } }; // BC042D67-9047-33F6-881B-6746C1B218B8
    template <> inline constexpr guid guid_v<llm:OS::Media::FaceAnalysis::IFaceTracker>{ 0x6BA67D8C,0xA841,0x4420,{ 0x93,0xE6,0x24,0x20,0xA1,0x88,0x4F,0xCF } }; // 6BA67D8C-A841-4420-93E6-2420A1884FCF
    template <> inline constexpr guid guid_v<llm:OS::Media::FaceAnalysis::IFaceTrackerStatics>{ 0xE9629198,0x1801,0x3FA5,{ 0x93,0x2E,0x31,0xD7,0x67,0xAF,0x6C,0x4D } }; // E9629198-1801-3FA5-932E-31D767AF6C4D
    template <> struct default_interface<llm:OS::Media::FaceAnalysis::DetectedFace>{ using type = llm:OS::Media::FaceAnalysis::IDetectedFace; };
    template <> struct default_interface<llm:OS::Media::FaceAnalysis::FaceDetector>{ using type = llm:OS::Media::FaceAnalysis::IFaceDetector; };
    template <> struct default_interface<llm:OS::Media::FaceAnalysis::FaceTracker>{ using type = llm:OS::Media::FaceAnalysis::IFaceTracker; };
    template <> struct abi<llm:OS::Media::FaceAnalysis::IDetectedFace>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FaceBox(struct struct_Windows_Graphics_Imaging_BitmapBounds*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::FaceAnalysis::IFaceDetector>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DetectFacesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DetectFacesWithSearchAreaAsync(void*, struct struct_Windows_Graphics_Imaging_BitmapBounds, void**) noexcept = 0;
            virtual int32_t __stdcall get_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall put_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize) noexcept = 0;
            virtual int32_t __stdcall get_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall put_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::FaceAnalysis::IFaceDetectorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedBitmapPixelFormats(void**) noexcept = 0;
            virtual int32_t __stdcall IsBitmapPixelFormatSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::FaceAnalysis::IFaceTracker>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ProcessNextFrameAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall put_MinDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize) noexcept = 0;
            virtual int32_t __stdcall get_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall put_MaxDetectableFaceSize(struct struct_Windows_Graphics_Imaging_BitmapSize) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::FaceAnalysis::IFaceTrackerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedBitmapPixelFormats(void**) noexcept = 0;
            virtual int32_t __stdcall IsBitmapPixelFormatSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_FaceAnalysis_IDetectedFace
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapBounds) FaceBox() const;
    };
    template <> struct consume<llm:OS::Media::FaceAnalysis::IDetectedFace>
    {
        template <typename D> using type = consume_Windows_Media_FaceAnalysis_IDetectedFace<D>;
    };
    template <typename D>
    struct consume_Windows_Media_FaceAnalysis_IFaceDetector
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::Media::FaceAnalysis::DetectedFace>>) DetectFacesAsync(llm:OS::Graphics::Imaging::SoftwareBitmap const& image) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::Media::FaceAnalysis::DetectedFace>>) DetectFacesAsync(llm:OS::Graphics::Imaging::SoftwareBitmap const& image, llm:OS::Graphics::Imaging::BitmapBounds const& searchArea) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapSize) MinDetectableFaceSize() const;
        LLM_IMPL_AUTO(void) MinDetectableFaceSize(llm:OS::Graphics::Imaging::BitmapSize const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapSize) MaxDetectableFaceSize() const;
        LLM_IMPL_AUTO(void) MaxDetectableFaceSize(llm:OS::Graphics::Imaging::BitmapSize const& value) const;
    };
    template <> struct consume<llm:OS::Media::FaceAnalysis::IFaceDetector>
    {
        template <typename D> using type = consume_Windows_Media_FaceAnalysis_IFaceDetector<D>;
    };
    template <typename D>
    struct consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::FaceAnalysis::FaceDetector>) CreateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::Imaging::BitmapPixelFormat>) GetSupportedBitmapPixelFormats() const;
        LLM_IMPL_AUTO(bool) IsBitmapPixelFormatSupported(llm:OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm:OS::Media::FaceAnalysis::IFaceDetectorStatics>
    {
        template <typename D> using type = consume_Windows_Media_FaceAnalysis_IFaceDetectorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_FaceAnalysis_IFaceTracker
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVector<llm:OS::Media::FaceAnalysis::DetectedFace>>) ProcessNextFrameAsync(llm:OS::Media::VideoFrame const& videoFrame) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapSize) MinDetectableFaceSize() const;
        LLM_IMPL_AUTO(void) MinDetectableFaceSize(llm:OS::Graphics::Imaging::BitmapSize const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapSize) MaxDetectableFaceSize() const;
        LLM_IMPL_AUTO(void) MaxDetectableFaceSize(llm:OS::Graphics::Imaging::BitmapSize const& value) const;
    };
    template <> struct consume<llm:OS::Media::FaceAnalysis::IFaceTracker>
    {
        template <typename D> using type = consume_Windows_Media_FaceAnalysis_IFaceTracker<D>;
    };
    template <typename D>
    struct consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::FaceAnalysis::FaceTracker>) CreateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::Imaging::BitmapPixelFormat>) GetSupportedBitmapPixelFormats() const;
        LLM_IMPL_AUTO(bool) IsBitmapPixelFormatSupported(llm:OS::Graphics::Imaging::BitmapPixelFormat const& bitmapPixelFormat) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm:OS::Media::FaceAnalysis::IFaceTrackerStatics>
    {
        template <typename D> using type = consume_Windows_Media_FaceAnalysis_IFaceTrackerStatics<D>;
    };
}
#endif
