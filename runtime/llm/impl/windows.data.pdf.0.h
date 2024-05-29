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
#ifndef LLM_OS_Data_Pdf_0_H
#define LLM_OS_Data_Pdf_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Rect;
    struct Size;
}
LLM_EXPORT namespace llm::OS::Storage
{
    struct IStorageFile;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::Data::Pdf
{
    enum class PdfPageRotation : int32_t
    {
        Normal = 0,
        Rotate90 = 1,
        Rotate180 = 2,
        Rotate270 = 3,
    };
    struct IPdfDocument;
    struct IPdfDocumentStatics;
    struct IPdfPage;
    struct IPdfPageDimensions;
    struct IPdfPageRenderOptions;
    struct PdfDocument;
    struct PdfPage;
    struct PdfPageDimensions;
    struct PdfPageRenderOptions;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Data::Pdf::IPdfDocument>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Pdf::IPdfDocumentStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Pdf::IPdfPage>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Pdf::IPdfPageDimensions>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Pdf::IPdfPageRenderOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::Data::Pdf::PdfDocument>{ using type = class_category; };
    template <> struct category<llm::OS::Data::Pdf::PdfPage>{ using type = class_category; };
    template <> struct category<llm::OS::Data::Pdf::PdfPageDimensions>{ using type = class_category; };
    template <> struct category<llm::OS::Data::Pdf::PdfPageRenderOptions>{ using type = class_category; };
    template <> struct category<llm::OS::Data::Pdf::PdfPageRotation>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::PdfDocument> = L"Windows.Data.Pdf.PdfDocument";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::PdfPage> = L"Windows.Data.Pdf.PdfPage";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::PdfPageDimensions> = L"Windows.Data.Pdf.PdfPageDimensions";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::PdfPageRenderOptions> = L"Windows.Data.Pdf.PdfPageRenderOptions";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::PdfPageRotation> = L"Windows.Data.Pdf.PdfPageRotation";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::IPdfDocument> = L"Windows.Data.Pdf.IPdfDocument";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::IPdfDocumentStatics> = L"Windows.Data.Pdf.IPdfDocumentStatics";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::IPdfPage> = L"Windows.Data.Pdf.IPdfPage";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::IPdfPageDimensions> = L"Windows.Data.Pdf.IPdfPageDimensions";
    template <> inline constexpr auto& name_v<llm::OS::Data::Pdf::IPdfPageRenderOptions> = L"Windows.Data.Pdf.IPdfPageRenderOptions";
    template <> inline constexpr guid guid_v<llm::OS::Data::Pdf::IPdfDocument>{ 0xAC7EBEDD,0x80FA,0x4089,{ 0x84,0x6E,0x81,0xB7,0x7F,0xF5,0xA8,0x6C } }; // AC7EBEDD-80FA-4089-846E-81B77FF5A86C
    template <> inline constexpr guid guid_v<llm::OS::Data::Pdf::IPdfDocumentStatics>{ 0x433A0B5F,0xC007,0x4788,{ 0x90,0xF2,0x08,0x14,0x3D,0x92,0x25,0x99 } }; // 433A0B5F-C007-4788-90F2-08143D922599
    template <> inline constexpr guid guid_v<llm::OS::Data::Pdf::IPdfPage>{ 0x9DB4B0C8,0x5320,0x4CFC,{ 0xAD,0x76,0x49,0x3F,0xDA,0xD0,0xE5,0x94 } }; // 9DB4B0C8-5320-4CFC-AD76-493FDAD0E594
    template <> inline constexpr guid guid_v<llm::OS::Data::Pdf::IPdfPageDimensions>{ 0x22170471,0x313E,0x44E8,{ 0x83,0x5D,0x63,0xA3,0xE7,0x62,0x4A,0x10 } }; // 22170471-313E-44E8-835D-63A3E7624A10
    template <> inline constexpr guid guid_v<llm::OS::Data::Pdf::IPdfPageRenderOptions>{ 0x3C98056F,0xB7CF,0x4C29,{ 0x9A,0x04,0x52,0xD9,0x02,0x67,0xF4,0x25 } }; // 3C98056F-B7CF-4C29-9A04-52D90267F425
    template <> struct default_interface<llm::OS::Data::Pdf::PdfDocument>{ using type = llm::OS::Data::Pdf::IPdfDocument; };
    template <> struct default_interface<llm::OS::Data::Pdf::PdfPage>{ using type = llm::OS::Data::Pdf::IPdfPage; };
    template <> struct default_interface<llm::OS::Data::Pdf::PdfPageDimensions>{ using type = llm::OS::Data::Pdf::IPdfPageDimensions; };
    template <> struct default_interface<llm::OS::Data::Pdf::PdfPageRenderOptions>{ using type = llm::OS::Data::Pdf::IPdfPageRenderOptions; };
    template <> struct abi<llm::OS::Data::Pdf::IPdfDocument>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetPage(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_PageCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsPasswordProtected(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Data::Pdf::IPdfDocumentStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LoadFromFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LoadFromFileWithPasswordAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LoadFromStreamAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LoadFromStreamWithPasswordAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Data::Pdf::IPdfPage>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RenderToStreamAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RenderWithOptionsToStreamAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall PreparePageAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Index(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Size(llm::OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall get_Dimensions(void**) noexcept = 0;
            virtual int32_t __stdcall get_Rotation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PreferredZoom(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Data::Pdf::IPdfPageDimensions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MediaBox(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_CropBox(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_BleedBox(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_TrimBox(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_ArtBox(llm::OS::Foundation::Rect*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Data::Pdf::IPdfPageRenderOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SourceRect(llm::OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_SourceRect(llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall get_DestinationWidth(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DestinationWidth(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_DestinationHeight(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DestinationHeight(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_IsIgnoringHighContrast(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsIgnoringHighContrast(bool) noexcept = 0;
            virtual int32_t __stdcall get_BitmapEncoderId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall put_BitmapEncoderId(llm::guid) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Data_Pdf_IPdfDocument
    {
        LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPage) GetPage(uint32_t pageIndex) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PageCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsPasswordProtected() const;
    };
    template <> struct consume<llm::OS::Data::Pdf::IPdfDocument>
    {
        template <typename D> using type = consume_Windows_Data_Pdf_IPdfDocument<D>;
    };
    template <typename D>
    struct consume_Windows_Data_Pdf_IPdfDocumentStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file, param::hstring const& password) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Data::Pdf::PdfDocument>) LoadFromStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& inputStream, param::hstring const& password) const;
    };
    template <> struct consume<llm::OS::Data::Pdf::IPdfDocumentStatics>
    {
        template <typename D> using type = consume_Windows_Data_Pdf_IPdfDocumentStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Data_Pdf_IPdfPage
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) RenderToStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& outputStream) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) RenderToStreamAsync(llm::OS::Storage::Streams::IRandomAccessStream const& outputStream, llm::OS::Data::Pdf::PdfPageRenderOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) PreparePageAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Index() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Size) Size() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPageDimensions) Dimensions() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Data::Pdf::PdfPageRotation) Rotation() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PreferredZoom() const;
    };
    template <> struct consume<llm::OS::Data::Pdf::IPdfPage>
    {
        template <typename D> using type = consume_Windows_Data_Pdf_IPdfPage<D>;
    };
    template <typename D>
    struct consume_Windows_Data_Pdf_IPdfPageDimensions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) MediaBox() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) CropBox() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) BleedBox() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) TrimBox() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) ArtBox() const;
    };
    template <> struct consume<llm::OS::Data::Pdf::IPdfPageDimensions>
    {
        template <typename D> using type = consume_Windows_Data_Pdf_IPdfPageDimensions<D>;
    };
    template <typename D>
    struct consume_Windows_Data_Pdf_IPdfPageRenderOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Rect) SourceRect() const;
        LLM_IMPL_AUTO(void) SourceRect(llm::OS::Foundation::Rect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DestinationWidth() const;
        LLM_IMPL_AUTO(void) DestinationWidth(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DestinationHeight() const;
        LLM_IMPL_AUTO(void) DestinationHeight(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) BackgroundColor() const;
        LLM_IMPL_AUTO(void) BackgroundColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsIgnoringHighContrast() const;
        LLM_IMPL_AUTO(void) IsIgnoringHighContrast(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) BitmapEncoderId() const;
        LLM_IMPL_AUTO(void) BitmapEncoderId(llm::guid const& value) const;
    };
    template <> struct consume<llm::OS::Data::Pdf::IPdfPageRenderOptions>
    {
        template <typename D> using type = consume_Windows_Data_Pdf_IPdfPageRenderOptions<D>;
    };
}
#endif
