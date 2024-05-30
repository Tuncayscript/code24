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
#ifndef LLM_OS_UI_Notifications_Preview_0_H
#define LLM_OS_UI_Notifications_Preview_0_H
LLM_EXPORT namespace llm:OS::UI
{
    struct WindowId;
}
LLM_EXPORT namespace llm:OS::UI::Notifications::Preview
{
    struct IToastOcclusionManagerPreviewStatics;
    struct ToastOcclusionManagerPreview;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Notifications::Preview::ToastOcclusionManagerPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Preview::ToastOcclusionManagerPreview> = L"Windows.UI.Notifications.Preview.ToastOcclusionManagerPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics> = L"Windows.UI.Notifications.Preview.IToastOcclusionManagerPreviewStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics>{ 0x507E5C83,0x50F9,0x5412,{ 0x89,0x53,0xB6,0x5C,0x18,0xCF,0xAB,0x12 } }; // 507E5C83-50F9-5412-8953-B65C18CFAB12
    template <> struct abi<llm:OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetToastWindowMargin(struct struct_Windows_UI_WindowId, double) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Notifications_Preview_IToastOcclusionManagerPreviewStatics
    {
        LLM_IMPL_AUTO(void) SetToastWindowMargin(llm:OS::UI::WindowId const& appWindowId, double margin) const;
    };
    template <> struct consume<llm:OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Notifications_Preview_IToastOcclusionManagerPreviewStatics<D>;
    };
}
#endif
