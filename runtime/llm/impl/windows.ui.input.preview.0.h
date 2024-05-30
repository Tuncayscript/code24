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
#ifndef LLM_OS_UI_Input_Preview_0_H
#define LLM_OS_UI_Input_Preview_0_H
LLM_EXPORT namespace llm:OS::UI::Input
{
    struct InputActivationListener;
}
LLM_EXPORT namespace llm:OS::UI::WindowManagement
{
    struct AppWindow;
}
LLM_EXPORT namespace llm:OS::UI::Input::Preview
{
    struct IInputActivationListenerPreviewStatics;
    struct InputActivationListenerPreview;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Input::Preview::IInputActivationListenerPreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Preview::InputActivationListenerPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Preview::InputActivationListenerPreview> = L"Windows.UI.Input.Preview.InputActivationListenerPreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Preview::IInputActivationListenerPreviewStatics> = L"Windows.UI.Input.Preview.IInputActivationListenerPreviewStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Preview::IInputActivationListenerPreviewStatics>{ 0xF0551CE5,0x0DE6,0x5BE0,{ 0xA5,0x89,0xF7,0x37,0x20,0x1A,0x45,0x82 } }; // F0551CE5-0DE6-5BE0-A589-F737201A4582
    template <> struct abi<llm:OS::UI::Input::Preview::IInputActivationListenerPreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateForApplicationWindow(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Input_Preview_IInputActivationListenerPreviewStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Input::InputActivationListener) CreateForApplicationWindow(llm:OS::UI::WindowManagement::AppWindow const& window) const;
    };
    template <> struct consume<llm:OS::UI::Input::Preview::IInputActivationListenerPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Input_Preview_IInputActivationListenerPreviewStatics<D>;
    };
}
#endif
