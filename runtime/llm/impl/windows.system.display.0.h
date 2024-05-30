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
#ifndef LLM_OS_System_Display_0_H
#define LLM_OS_System_Display_0_H
LLM_EXPORT namespace llm:OS::System::Display
{
    struct IDisplayRequest;
    struct DisplayRequest;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Display::IDisplayRequest>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Display::DisplayRequest>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Display::DisplayRequest> = L"Windows.System.Display.DisplayRequest";
    template <> inline constexpr auto& name_v<llm:OS::System::Display::IDisplayRequest> = L"Windows.System.Display.IDisplayRequest";
    template <> inline constexpr guid guid_v<llm:OS::System::Display::IDisplayRequest>{ 0xE5732044,0xF49F,0x4B60,{ 0x8D,0xD4,0x5E,0x7E,0x3A,0x63,0x2A,0xC0 } }; // E5732044-F49F-4B60-8DD4-5E7E3A632AC0
    template <> struct default_interface<llm:OS::System::Display::DisplayRequest>{ using type = llm:OS::System::Display::IDisplayRequest; };
    template <> struct abi<llm:OS::System::Display::IDisplayRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestActive() noexcept = 0;
            virtual int32_t __stdcall RequestRelease() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Display_IDisplayRequest
    {
        LLM_IMPL_AUTO(void) RequestActive() const;
        LLM_IMPL_AUTO(void) RequestRelease() const;
    };
    template <> struct consume<llm:OS::System::Display::IDisplayRequest>
    {
        template <typename D> using type = consume_Windows_System_Display_IDisplayRequest<D>;
    };
}
#endif
