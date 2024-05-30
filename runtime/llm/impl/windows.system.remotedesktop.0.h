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
#ifndef LLM_OS_System_RemoteDesktop_0_H
#define LLM_OS_System_RemoteDesktop_0_H
LLM_EXPORT namespace llm:OS::System::RemoteDesktop
{
    struct IInteractiveSessionStatics;
    struct InteractiveSession;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::RemoteDesktop::IInteractiveSessionStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::RemoteDesktop::InteractiveSession>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::InteractiveSession> = L"Windows.System.RemoteDesktop.InteractiveSession";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::IInteractiveSessionStatics> = L"Windows.System.RemoteDesktop.IInteractiveSessionStatics";
    template <> inline constexpr guid guid_v<llm:OS::System::RemoteDesktop::IInteractiveSessionStatics>{ 0x60884631,0xDD3A,0x4576,{ 0x9C,0x8D,0xE8,0x02,0x76,0x18,0xBD,0xCE } }; // 60884631-DD3A-4576-9C8D-E8027618BDCE
    template <> struct abi<llm:OS::System::RemoteDesktop::IInteractiveSessionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsRemote(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_RemoteDesktop_IInteractiveSessionStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRemote() const;
    };
    template <> struct consume<llm:OS::System::RemoteDesktop::IInteractiveSessionStatics>
    {
        template <typename D> using type = consume_Windows_System_RemoteDesktop_IInteractiveSessionStatics<D>;
    };
}
#endif
