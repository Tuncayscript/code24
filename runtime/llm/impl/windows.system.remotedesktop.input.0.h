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
#ifndef LLM_OS_System_RemoteDesktop_Input_0_H
#define LLM_OS_System_RemoteDesktop_Input_0_H
LLM_EXPORT namespace llm:OS::System::RemoteDesktop::Input
{
    struct IRemoteTextConnection;
    struct IRemoteTextConnectionFactory;
    struct RemoteTextConnection;
    struct RemoteTextConnectionDataHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::System::RemoteDesktop::Input::RemoteTextConnection>{ using type = class_category; };
    template <> struct category<llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::Input::RemoteTextConnection> = L"Windows.System.RemoteDesktop.Input.RemoteTextConnection";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection> = L"Windows.System.RemoteDesktop.Input.IRemoteTextConnection";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory> = L"Windows.System.RemoteDesktop.Input.IRemoteTextConnectionFactory";
    template <> inline constexpr auto& name_v<llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler> = L"Windows.System.RemoteDesktop.Input.RemoteTextConnectionDataHandler";
    template <> inline constexpr guid guid_v<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection>{ 0x4E7BB02A,0x183E,0x5E66,{ 0xB5,0xE4,0x3E,0x6E,0x5C,0x57,0x0C,0xF1 } }; // 4E7BB02A-183E-5E66-B5E4-3E6E5C570CF1
    template <> inline constexpr guid guid_v<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory>{ 0x88E075C2,0x0CAE,0x596C,{ 0x85,0x0F,0x78,0xD3,0x45,0xCD,0x72,0x8B } }; // 88E075C2-0CAE-596C-850F-78D345CD728B
    template <> inline constexpr guid guid_v<llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler>{ 0x099FFBC8,0x8BCB,0x41B5,{ 0xB0,0x56,0x57,0xE7,0x70,0x21,0xBF,0x1B } }; // 099FFBC8-8BCB-41B5-B056-57E77021BF1B
    template <> struct default_interface<llm:OS::System::RemoteDesktop::Input::RemoteTextConnection>{ using type = llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection; };
    template <> struct abi<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall RegisterThread(uint32_t) noexcept = 0;
            virtual int32_t __stdcall UnregisterThread(uint32_t) noexcept = 0;
            virtual int32_t __stdcall ReportDataReceived(uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(llm::guid, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(uint32_t, uint8_t*, bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
        LLM_IMPL_AUTO(void) RegisterThread(uint32_t threadId) const;
        LLM_IMPL_AUTO(void) UnregisterThread(uint32_t threadId) const;
        LLM_IMPL_AUTO(void) ReportDataReceived(array_view<uint8_t const> pduData) const;
    };
    template <> struct consume<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnection>
    {
        template <typename D> using type = consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>;
    };
    template <typename D>
    struct consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnectionFactory
    {
        LLM_IMPL_AUTO(llm:OS::System::RemoteDesktop::Input::RemoteTextConnection) CreateInstance(llm::guid const& connectionId, llm:OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler const& pduForwarder) const;
    };
    template <> struct consume<llm:OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory>
    {
        template <typename D> using type = consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnectionFactory<D>;
    };
}
#endif
