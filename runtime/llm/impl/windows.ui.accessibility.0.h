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
#ifndef LLM_OS_UI_Accessibility_0_H
#define LLM_OS_UI_Accessibility_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::UI::Accessibility
{
    struct IScreenReaderPositionChangedEventArgs;
    struct IScreenReaderService;
    struct ScreenReaderPositionChangedEventArgs;
    struct ScreenReaderService;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Accessibility::IScreenReaderService>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Accessibility::ScreenReaderService>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> = L"Windows.UI.Accessibility.ScreenReaderPositionChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Accessibility::ScreenReaderService> = L"Windows.UI.Accessibility.ScreenReaderService";
    template <> inline constexpr auto& name_v<llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs> = L"Windows.UI.Accessibility.IScreenReaderPositionChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Accessibility::IScreenReaderService> = L"Windows.UI.Accessibility.IScreenReaderService";
    template <> inline constexpr guid guid_v<llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs>{ 0x557EB5E5,0x54D0,0x5CCD,{ 0x9F,0xC5,0xED,0x33,0x35,0x7F,0x8A,0x9F } }; // 557EB5E5-54D0-5CCD-9FC5-ED33357F8A9F
    template <> inline constexpr guid guid_v<llm:OS::UI::Accessibility::IScreenReaderService>{ 0x19475427,0xEAC0,0x50D3,{ 0xBD,0xD9,0x9B,0x48,0x7A,0x22,0x62,0x56 } }; // 19475427-EAC0-50D3-BDD9-9B487A226256
    template <> struct default_interface<llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs>{ using type = llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Accessibility::ScreenReaderService>{ using type = llm:OS::UI::Accessibility::IScreenReaderService; };
    template <> struct abi<llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ScreenPositionInRawPixels(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_IsReadingText(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Accessibility::IScreenReaderService>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CurrentScreenReaderPosition(void**) noexcept = 0;
            virtual int32_t __stdcall add_ScreenReaderPositionChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ScreenReaderPositionChanged(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Accessibility_IScreenReaderPositionChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) ScreenPositionInRawPixels() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsReadingText() const;
    };
    template <> struct consume<llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Accessibility_IScreenReaderPositionChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Accessibility_IScreenReaderService
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs) CurrentScreenReaderPosition() const;
        LLM_IMPL_AUTO(llm::event_token) ScreenReaderPositionChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Accessibility::ScreenReaderService, llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> const& handler) const;
        using ScreenReaderPositionChanged_revoker = impl::event_revoker<llm:OS::UI::Accessibility::IScreenReaderService, &impl::abi_t<llm:OS::UI::Accessibility::IScreenReaderService>::remove_ScreenReaderPositionChanged>;
        [[nodiscard]] ScreenReaderPositionChanged_revoker ScreenReaderPositionChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Accessibility::ScreenReaderService, llm:OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ScreenReaderPositionChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Accessibility::IScreenReaderService>
    {
        template <typename D> using type = consume_Windows_UI_Accessibility_IScreenReaderService<D>;
    };
}
#endif
