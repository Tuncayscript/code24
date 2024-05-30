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
#ifndef LLM_OS_UI_Core_Preview_0_H
#define LLM_OS_UI_Core_Preview_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
LLM_EXPORT namespace llm:OS::UI::WindowManagement
{
    struct AppWindow;
}
LLM_EXPORT namespace llm:OS::UI::Core::Preview
{
    struct ICoreAppWindowPreview;
    struct ICoreAppWindowPreviewStatics;
    struct ISystemNavigationCloseRequestedPreviewEventArgs;
    struct ISystemNavigationManagerPreview;
    struct ISystemNavigationManagerPreviewStatics;
    struct CoreAppWindowPreview;
    struct SystemNavigationCloseRequestedPreviewEventArgs;
    struct SystemNavigationManagerPreview;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Core::Preview::ICoreAppWindowPreview>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Core::Preview::ICoreAppWindowPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Core::Preview::CoreAppWindowPreview>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Core::Preview::SystemNavigationManagerPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::CoreAppWindowPreview> = L"Windows.UI.Core.Preview.CoreAppWindowPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> = L"Windows.UI.Core.Preview.SystemNavigationCloseRequestedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::SystemNavigationManagerPreview> = L"Windows.UI.Core.Preview.SystemNavigationManagerPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::ICoreAppWindowPreview> = L"Windows.UI.Core.Preview.ICoreAppWindowPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::ICoreAppWindowPreviewStatics> = L"Windows.UI.Core.Preview.ICoreAppWindowPreviewStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs> = L"Windows.UI.Core.Preview.ISystemNavigationCloseRequestedPreviewEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview> = L"Windows.UI.Core.Preview.ISystemNavigationManagerPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics> = L"Windows.UI.Core.Preview.ISystemNavigationManagerPreviewStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Core::Preview::ICoreAppWindowPreview>{ 0xA4F6E665,0x365E,0x5FDE,{ 0x87,0xA5,0x95,0x43,0xC3,0xA1,0x5A,0xA8 } }; // A4F6E665-365E-5FDE-87A5-9543C3A15AA8
    template <> inline constexpr guid guid_v<llm:OS::UI::Core::Preview::ICoreAppWindowPreviewStatics>{ 0x33AC21BE,0x423B,0x5DB6,{ 0x8A,0x8E,0x4D,0xC8,0x73,0x53,0xB7,0x5B } }; // 33AC21BE-423B-5DB6-8A8E-4DC87353B75B
    template <> inline constexpr guid guid_v<llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>{ 0x83D00DE1,0xCBE5,0x4F31,{ 0x84,0x14,0x36,0x1D,0xA0,0x46,0x51,0x8F } }; // 83D00DE1-CBE5-4F31-8414-361DA046518F
    template <> inline constexpr guid guid_v<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview>{ 0xEC5F0488,0x6425,0x4777,{ 0xA5,0x36,0xCB,0x56,0x34,0x42,0x7F,0x0D } }; // EC5F0488-6425-4777-A536-CB5634427F0D
    template <> inline constexpr guid guid_v<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>{ 0x0E971360,0xDF74,0x4BCE,{ 0x84,0xCB,0xBD,0x11,0x81,0xAC,0x0A,0x71 } }; // 0E971360-DF74-4BCE-84CB-BD1181AC0A71
    template <> struct default_interface<llm:OS::UI::Core::Preview::CoreAppWindowPreview>{ using type = llm:OS::UI::Core::Preview::ICoreAppWindowPreview; };
    template <> struct default_interface<llm:OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs>{ using type = llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs; };
    template <> struct default_interface<llm:OS::UI::Core::Preview::SystemNavigationManagerPreview>{ using type = llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview; };
    template <> struct abi<llm:OS::UI::Core::Preview::ICoreAppWindowPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Core::Preview::ICoreAppWindowPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetIdFromWindow(void*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_CloseRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CloseRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ICoreAppWindowPreview
    {
    };
    template <> struct consume<llm:OS::UI::Core::Preview::ICoreAppWindowPreview>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ICoreAppWindowPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ICoreAppWindowPreviewStatics
    {
        LLM_IMPL_AUTO(int32_t) GetIdFromWindow(llm:OS::UI::WindowManagement::AppWindow const& window) const;
    };
    template <> struct consume<llm:OS::UI::Core::Preview::ICoreAppWindowPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ICoreAppWindowPreviewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview
    {
        LLM_IMPL_AUTO(llm::event_token) CloseRequested(llm:OS::Foundation::EventHandler<llm:OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const;
        using CloseRequested_revoker = impl::event_revoker<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview, &impl::abi_t<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview>::remove_CloseRequested>;
        [[nodiscard]] CloseRequested_revoker CloseRequested(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CloseRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreviewStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Core::Preview::SystemNavigationManagerPreview) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreviewStatics<D>;
    };
}
#endif
