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
#ifndef LLM_OS_Devices_Portable_0_H
#define LLM_OS_Devices_Portable_0_H
LLM_EXPORT namespace llm::OS::Storage
{
    struct StorageFolder;
}
LLM_EXPORT namespace llm::OS::Devices::Portable
{
    enum class ServiceDeviceType : int32_t
    {
        CalendarService = 0,
        ContactsService = 1,
        DeviceStatusService = 2,
        NotesService = 3,
        RingtonesService = 4,
        SmsService = 5,
        TasksService = 6,
    };
    struct IServiceDeviceStatics;
    struct IStorageDeviceStatics;
    struct ServiceDevice;
    struct StorageDevice;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Portable::IServiceDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Portable::IStorageDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Portable::ServiceDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Portable::StorageDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Portable::ServiceDeviceType>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Portable::ServiceDevice> = L"Windows.Devices.Portable.ServiceDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Portable::StorageDevice> = L"Windows.Devices.Portable.StorageDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Portable::ServiceDeviceType> = L"Windows.Devices.Portable.ServiceDeviceType";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Portable::IServiceDeviceStatics> = L"Windows.Devices.Portable.IServiceDeviceStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Portable::IStorageDeviceStatics> = L"Windows.Devices.Portable.IStorageDeviceStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Portable::IServiceDeviceStatics>{ 0xA88214E1,0x59C7,0x4A20,{ 0xAB,0xA6,0x9F,0x67,0x07,0x93,0x72,0x30 } }; // A88214E1-59C7-4A20-ABA6-9F6707937230
    template <> inline constexpr guid guid_v<llm::OS::Devices::Portable::IStorageDeviceStatics>{ 0x5ECE44EE,0x1B23,0x4DD2,{ 0x86,0x52,0xBC,0x16,0x4F,0x00,0x31,0x28 } }; // 5ECE44EE-1B23-4DD2-8652-BC164F003128
    template <> struct abi<llm::OS::Devices::Portable::IServiceDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelectorFromServiceId(llm::guid, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Portable::IStorageDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Portable_IServiceDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(llm::OS::Devices::Portable::ServiceDeviceType const& serviceType) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelectorFromServiceId(llm::guid const& serviceId) const;
    };
    template <> struct consume<llm::OS::Devices::Portable::IServiceDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Portable_IServiceDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Portable_IStorageDeviceStatics
    {
        LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) FromId(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
    };
    template <> struct consume<llm::OS::Devices::Portable::IStorageDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Portable_IStorageDeviceStatics<D>;
    };
}
#endif
