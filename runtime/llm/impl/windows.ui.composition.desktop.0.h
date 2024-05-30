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
#ifndef LLM_OS_UI_Composition_Desktop_0_H
#define LLM_OS_UI_Composition_Desktop_0_H
LLM_EXPORT namespace llm:OS::UI::Composition::Desktop
{
    struct IDesktopWindowTarget;
    struct DesktopWindowTarget;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Composition::Desktop::IDesktopWindowTarget>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::Desktop::DesktopWindowTarget>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Desktop::DesktopWindowTarget> = L"Windows.UI.Composition.Desktop.DesktopWindowTarget";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Desktop::IDesktopWindowTarget> = L"Windows.UI.Composition.Desktop.IDesktopWindowTarget";
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::Desktop::IDesktopWindowTarget>{ 0x6329D6CA,0x3366,0x490E,{ 0x9D,0xB3,0x25,0x31,0x29,0x29,0xAC,0x51 } }; // 6329D6CA-3366-490E-9DB3-25312929AC51
    template <> struct default_interface<llm:OS::UI::Composition::Desktop::DesktopWindowTarget>{ using type = llm:OS::UI::Composition::Desktop::IDesktopWindowTarget; };
    template <> struct abi<llm:OS::UI::Composition::Desktop::IDesktopWindowTarget>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsTopmost(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Composition_Desktop_IDesktopWindowTarget
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTopmost() const;
    };
    template <> struct consume<llm:OS::UI::Composition::Desktop::IDesktopWindowTarget>
    {
        template <typename D> using type = consume_Windows_UI_Composition_Desktop_IDesktopWindowTarget<D>;
    };
}
#endif
