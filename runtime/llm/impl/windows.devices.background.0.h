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
#ifndef LLM_OS_Devices_Background_0_H
#define LLM_OS_Devices_Background_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
}
LLM_EXPORT namespace llm::OS::Devices::Background
{
    struct IDeviceServicingDetails;
    struct IDeviceUseDetails;
    struct DeviceServicingDetails;
    struct DeviceUseDetails;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Background::IDeviceServicingDetails>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Background::IDeviceUseDetails>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Background::DeviceServicingDetails>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Background::DeviceUseDetails>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Background::DeviceServicingDetails> = L"Windows.Devices.Background.DeviceServicingDetails";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Background::DeviceUseDetails> = L"Windows.Devices.Background.DeviceUseDetails";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Background::IDeviceServicingDetails> = L"Windows.Devices.Background.IDeviceServicingDetails";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Background::IDeviceUseDetails> = L"Windows.Devices.Background.IDeviceUseDetails";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Background::IDeviceServicingDetails>{ 0x4AABEE29,0x2344,0x4AC4,{ 0x85,0x27,0x4A,0x8E,0xF6,0x90,0x56,0x45 } }; // 4AABEE29-2344-4AC4-8527-4A8EF6905645
    template <> inline constexpr guid guid_v<llm::OS::Devices::Background::IDeviceUseDetails>{ 0x7D565141,0x557E,0x4154,{ 0xB9,0x94,0xE4,0xF7,0xA1,0x1F,0xB3,0x23 } }; // 7D565141-557E-4154-B994-E4F7A11FB323
    template <> struct default_interface<llm::OS::Devices::Background::DeviceServicingDetails>{ using type = llm::OS::Devices::Background::IDeviceServicingDetails; };
    template <> struct default_interface<llm::OS::Devices::Background::DeviceUseDetails>{ using type = llm::OS::Devices::Background::IDeviceUseDetails; };
    template <> struct abi<llm::OS::Devices::Background::IDeviceServicingDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Arguments(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExpectedDuration(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Background::IDeviceUseDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Arguments(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Background_IDeviceServicingDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Arguments() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) ExpectedDuration() const;
    };
    template <> struct consume<llm::OS::Devices::Background::IDeviceServicingDetails>
    {
        template <typename D> using type = consume_Windows_Devices_Background_IDeviceServicingDetails<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Background_IDeviceUseDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Arguments() const;
    };
    template <> struct consume<llm::OS::Devices::Background::IDeviceUseDetails>
    {
        template <typename D> using type = consume_Windows_Devices_Background_IDeviceUseDetails<D>;
    };
}
#endif
