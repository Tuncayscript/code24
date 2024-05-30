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
#ifndef LLM_OS_Media_Ocr_0_H
#define LLM_OS_Media_Ocr_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Rect;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Globalization
{
    struct Language;
}
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct SoftwareBitmap;
}
LLM_EXPORT namespace llm:OS::Media::Ocr
{
    struct IOcrEngine;
    struct IOcrEngineStatics;
    struct IOcrLine;
    struct IOcrResult;
    struct IOcrWord;
    struct OcrEngine;
    struct OcrLine;
    struct OcrResult;
    struct OcrWord;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Ocr::IOcrEngine>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Ocr::IOcrEngineStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Ocr::IOcrLine>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Ocr::IOcrResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Ocr::IOcrWord>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Ocr::OcrEngine>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Ocr::OcrLine>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Ocr::OcrResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Ocr::OcrWord>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::OcrEngine> = L"Windows.Media.Ocr.OcrEngine";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::OcrLine> = L"Windows.Media.Ocr.OcrLine";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::OcrResult> = L"Windows.Media.Ocr.OcrResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::OcrWord> = L"Windows.Media.Ocr.OcrWord";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::IOcrEngine> = L"Windows.Media.Ocr.IOcrEngine";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::IOcrEngineStatics> = L"Windows.Media.Ocr.IOcrEngineStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::IOcrLine> = L"Windows.Media.Ocr.IOcrLine";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::IOcrResult> = L"Windows.Media.Ocr.IOcrResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Ocr::IOcrWord> = L"Windows.Media.Ocr.IOcrWord";
    template <> inline constexpr guid guid_v<llm:OS::Media::Ocr::IOcrEngine>{ 0x5A14BC41,0x5B76,0x3140,{ 0xB6,0x80,0x88,0x25,0x56,0x26,0x83,0xAC } }; // 5A14BC41-5B76-3140-B680-8825562683AC
    template <> inline constexpr guid guid_v<llm:OS::Media::Ocr::IOcrEngineStatics>{ 0x5BFFA85A,0x3384,0x3540,{ 0x99,0x40,0x69,0x91,0x20,0xD4,0x28,0xA8 } }; // 5BFFA85A-3384-3540-9940-699120D428A8
    template <> inline constexpr guid guid_v<llm:OS::Media::Ocr::IOcrLine>{ 0x0043A16F,0xE31F,0x3A24,{ 0x89,0x9C,0xD4,0x44,0xBD,0x08,0x81,0x24 } }; // 0043A16F-E31F-3A24-899C-D444BD088124
    template <> inline constexpr guid guid_v<llm:OS::Media::Ocr::IOcrResult>{ 0x9BD235B2,0x175B,0x3D6A,{ 0x92,0xE2,0x38,0x8C,0x20,0x6E,0x2F,0x63 } }; // 9BD235B2-175B-3D6A-92E2-388C206E2F63
    template <> inline constexpr guid guid_v<llm:OS::Media::Ocr::IOcrWord>{ 0x3C2A477A,0x5CD9,0x3525,{ 0xBA,0x2A,0x23,0xD1,0xE0,0xA6,0x8A,0x1D } }; // 3C2A477A-5CD9-3525-BA2A-23D1E0A68A1D
    template <> struct default_interface<llm:OS::Media::Ocr::OcrEngine>{ using type = llm:OS::Media::Ocr::IOcrEngine; };
    template <> struct default_interface<llm:OS::Media::Ocr::OcrLine>{ using type = llm:OS::Media::Ocr::IOcrLine; };
    template <> struct default_interface<llm:OS::Media::Ocr::OcrResult>{ using type = llm:OS::Media::Ocr::IOcrResult; };
    template <> struct default_interface<llm:OS::Media::Ocr::OcrWord>{ using type = llm:OS::Media::Ocr::IOcrWord; };
    template <> struct abi<llm:OS::Media::Ocr::IOcrEngine>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RecognizeAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_RecognizerLanguage(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Ocr::IOcrEngineStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxImageDimension(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AvailableRecognizerLanguages(void**) noexcept = 0;
            virtual int32_t __stdcall IsLanguageSupported(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall TryCreateFromLanguage(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryCreateFromUserProfileLanguages(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Ocr::IOcrLine>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Words(void**) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Ocr::IOcrResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Lines(void**) noexcept = 0;
            virtual int32_t __stdcall get_TextAngle(void**) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Ocr::IOcrWord>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BoundingRect(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Ocr_IOcrEngine
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Ocr::OcrResult>) RecognizeAsync(llm:OS::Graphics::Imaging::SoftwareBitmap const& bitmap) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Language) RecognizerLanguage() const;
    };
    template <> struct consume<llm:OS::Media::Ocr::IOcrEngine>
    {
        template <typename D> using type = consume_Windows_Media_Ocr_IOcrEngine<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Ocr_IOcrEngineStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxImageDimension() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Globalization::Language>) AvailableRecognizerLanguages() const;
        LLM_IMPL_AUTO(bool) IsLanguageSupported(llm:OS::Globalization::Language const& language) const;
        LLM_IMPL_AUTO(llm:OS::Media::Ocr::OcrEngine) TryCreateFromLanguage(llm:OS::Globalization::Language const& language) const;
        LLM_IMPL_AUTO(llm:OS::Media::Ocr::OcrEngine) TryCreateFromUserProfileLanguages() const;
    };
    template <> struct consume<llm:OS::Media::Ocr::IOcrEngineStatics>
    {
        template <typename D> using type = consume_Windows_Media_Ocr_IOcrEngineStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Ocr_IOcrLine
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Ocr::OcrWord>) Words() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
    };
    template <> struct consume<llm:OS::Media::Ocr::IOcrLine>
    {
        template <typename D> using type = consume_Windows_Media_Ocr_IOcrLine<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Ocr_IOcrResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Ocr::OcrLine>) Lines() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<double>) TextAngle() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
    };
    template <> struct consume<llm:OS::Media::Ocr::IOcrResult>
    {
        template <typename D> using type = consume_Windows_Media_Ocr_IOcrResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Ocr_IOcrWord
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) BoundingRect() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
    };
    template <> struct consume<llm:OS::Media::Ocr::IOcrWord>
    {
        template <typename D> using type = consume_Windows_Media_Ocr_IOcrWord<D>;
    };
}
#endif
