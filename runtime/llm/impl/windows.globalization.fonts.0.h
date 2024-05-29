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
#ifndef LLM_OS_Globalization_Fonts_0_H
#define LLM_OS_Globalization_Fonts_0_H
LLM_EXPORT namespace llm:OS::UI::Text
{
    enum class FontStretch : int32_t;
    enum class FontStyle : int32_t;
    struct FontWeight;
}
LLM_EXPORT namespace llm:OS::Globalization::Fonts
{
    struct ILanguageFont;
    struct ILanguageFontGroup;
    struct ILanguageFontGroupFactory;
    struct LanguageFont;
    struct LanguageFontGroup;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Globalization::Fonts::ILanguageFont>{ using type = interface_category; };
    template <> struct category<llm:OS::Globalization::Fonts::ILanguageFontGroup>{ using type = interface_category; };
    template <> struct category<llm:OS::Globalization::Fonts::ILanguageFontGroupFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Globalization::Fonts::LanguageFont>{ using type = class_category; };
    template <> struct category<llm:OS::Globalization::Fonts::LanguageFontGroup>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Globalization::Fonts::LanguageFont> = L"Windows.Globalization.Fonts.LanguageFont";
    template <> inline constexpr auto& name_v<llm:OS::Globalization::Fonts::LanguageFontGroup> = L"Windows.Globalization.Fonts.LanguageFontGroup";
    template <> inline constexpr auto& name_v<llm:OS::Globalization::Fonts::ILanguageFont> = L"Windows.Globalization.Fonts.ILanguageFont";
    template <> inline constexpr auto& name_v<llm:OS::Globalization::Fonts::ILanguageFontGroup> = L"Windows.Globalization.Fonts.ILanguageFontGroup";
    template <> inline constexpr auto& name_v<llm:OS::Globalization::Fonts::ILanguageFontGroupFactory> = L"Windows.Globalization.Fonts.ILanguageFontGroupFactory";
    template <> inline constexpr guid guid_v<llm:OS::Globalization::Fonts::ILanguageFont>{ 0xB12E5C3A,0xB76D,0x459B,{ 0xBE,0xEB,0x90,0x11,0x51,0xCD,0x77,0xD1 } }; // B12E5C3A-B76D-459B-BEEB-901151CD77D1
    template <> inline constexpr guid guid_v<llm:OS::Globalization::Fonts::ILanguageFontGroup>{ 0xF33A7FC3,0x3A5C,0x4AEA,{ 0xB9,0xFF,0xB3,0x9F,0xB2,0x42,0xF7,0xF6 } }; // F33A7FC3-3A5C-4AEA-B9FF-B39FB242F7F6
    template <> inline constexpr guid guid_v<llm:OS::Globalization::Fonts::ILanguageFontGroupFactory>{ 0xFCAEAC67,0x4E77,0x49C7,{ 0xB8,0x56,0xDD,0xE9,0x34,0xFC,0x73,0x5B } }; // FCAEAC67-4E77-49C7-B856-DDE934FC735B
    template <> struct default_interface<llm:OS::Globalization::Fonts::LanguageFont>{ using type = llm:OS::Globalization::Fonts::ILanguageFont; };
    template <> struct default_interface<llm:OS::Globalization::Fonts::LanguageFontGroup>{ using type = llm:OS::Globalization::Fonts::ILanguageFontGroup; };
    template <> struct abi<llm:OS::Globalization::Fonts::ILanguageFont>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FontFamily(void**) noexcept = 0;
            virtual int32_t __stdcall get_FontWeight(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_FontStretch(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FontStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ScaleFactor(double*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Globalization::Fonts::ILanguageFontGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UITextFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_UIHeadingFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_UITitleFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_UICaptionFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_UINotificationHeadingFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_TraditionalDocumentFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_ModernDocumentFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentHeadingFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_FixedWidthTextFont(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentAlternate1Font(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentAlternate2Font(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Globalization::Fonts::ILanguageFontGroupFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateLanguageFontGroup(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Globalization_Fonts_ILanguageFont
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FontFamily() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) FontWeight() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStretch) FontStretch() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStyle) FontStyle() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) ScaleFactor() const;
    };
    template <> struct consume<llm:OS::Globalization::Fonts::ILanguageFont>
    {
        template <typename D> using type = consume_Windows_Globalization_Fonts_ILanguageFont<D>;
    };
    template <typename D>
    struct consume_Windows_Globalization_Fonts_ILanguageFontGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) UITextFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) UIHeadingFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) UITitleFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) UICaptionFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) UINotificationHeadingFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) TraditionalDocumentFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) ModernDocumentFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) DocumentHeadingFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) FixedWidthTextFont() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) DocumentAlternate1Font() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFont) DocumentAlternate2Font() const;
    };
    template <> struct consume<llm:OS::Globalization::Fonts::ILanguageFontGroup>
    {
        template <typename D> using type = consume_Windows_Globalization_Fonts_ILanguageFontGroup<D>;
    };
    template <typename D>
    struct consume_Windows_Globalization_Fonts_ILanguageFontGroupFactory
    {
        LLM_IMPL_AUTO(llm:OS::Globalization::Fonts::LanguageFontGroup) CreateLanguageFontGroup(param::hstring const& languageTag) const;
    };
    template <> struct consume<llm:OS::Globalization::Fonts::ILanguageFontGroupFactory>
    {
        template <typename D> using type = consume_Windows_Globalization_Fonts_ILanguageFontGroupFactory<D>;
    };
}
#endif
