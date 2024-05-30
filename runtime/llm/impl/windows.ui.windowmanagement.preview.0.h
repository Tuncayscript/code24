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
#ifndef LLM_OS_UI_WindowManagement_Preview_0_H
#define LLM_OS_UI_WindowManagement_Preview_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Size;
}
LLM_EXPORT namespace llm::OS::UI::WindowManagement
{
    struct AppWindow;
}
LLM_EXPORT namespace llm::OS::UI::WindowManagement::Preview
{
    struct IWindowManagementPreview;
    struct IWindowManagementPreviewStatics;
    struct WindowManagementPreview;
}
namespace llm::impl
{
    template <> struct category<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::WindowManagement::Preview::WindowManagementPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::Preview::WindowManagementPreview> = L"Windows.UI.WindowManagement.Preview.WindowManagementPreview";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview> = L"Windows.UI.WindowManagement.Preview.IWindowManagementPreview";
    template <> inline constexpr auto& name_v<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics> = L"Windows.UI.WindowManagement.Preview.IWindowManagementPreviewStatics";
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview>{ 0x4EF55B0D,0x561D,0x513C,{ 0xA6,0x7C,0x2C,0x02,0xB6,0x9C,0xEF,0x41 } }; // 4EF55B0D-561D-513C-A67C-2C02B69CEF41
    template <> inline constexpr guid guid_v<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics>{ 0x0F9725C6,0xC004,0x5A23,{ 0x8F,0xD2,0x8D,0x09,0x2C,0xE2,0x70,0x4A } }; // 0F9725C6-C004-5A23-8FD2-8D092CE2704A
    template <> struct default_interface<llm::OS::UI::WindowManagement::Preview::WindowManagementPreview>{ using type = llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview; };
    template <> struct abi<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetPreferredMinSize(void*, llm::OS::Foundation::Size) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_Preview_IWindowManagementPreview
    {
    };
    template <> struct consume<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_Preview_IWindowManagementPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WindowManagement_Preview_IWindowManagementPreviewStatics
    {
        LLM_IMPL_AUTO(void) SetPreferredMinSize(llm::OS::UI::WindowManagement::AppWindow const& window, llm::OS::Foundation::Size const& preferredFrameMinSize) const;
    };
    template <> struct consume<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_WindowManagement_Preview_IWindowManagementPreviewStatics<D>;
    };
}
#endif
