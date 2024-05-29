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
#ifndef LLM_OS_Devices_Custom_0_H
#define LLM_OS_Devices_Custom_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IBuffer;
    struct IInputStream;
    struct IOutputStream;
}
LLM_EXPORT namespace llm::OS::Devices::Custom
{
    enum class DeviceAccessMode : int32_t
    {
        Read = 0,
        Write = 1,
        ReadWrite = 2,
    };
    enum class DeviceSharingMode : int32_t
    {
        Shared = 0,
        Exclusive = 1,
    };
    enum class IOControlAccessMode : int32_t
    {
        Any = 0,
        Read = 1,
        Write = 2,
        ReadWrite = 3,
    };
    enum class IOControlBufferingMethod : int32_t
    {
        Buffered = 0,
        DirectInput = 1,
        DirectOutput = 2,
        Neither = 3,
    };
    struct ICustomDevice;
    struct ICustomDeviceStatics;
    struct IIOControlCode;
    struct IIOControlCodeFactory;
    struct IKnownDeviceTypesStatics;
    struct CustomDevice;
    struct IOControlCode;
    struct KnownDeviceTypes;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Custom::ICustomDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Custom::ICustomDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Custom::IIOControlCode>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Custom::IIOControlCodeFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Custom::IKnownDeviceTypesStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Custom::CustomDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Custom::IOControlCode>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Custom::KnownDeviceTypes>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Custom::DeviceAccessMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Custom::DeviceSharingMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Custom::IOControlAccessMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Custom::IOControlBufferingMethod>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::CustomDevice> = L"Windows.Devices.Custom.CustomDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IOControlCode> = L"Windows.Devices.Custom.IOControlCode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::KnownDeviceTypes> = L"Windows.Devices.Custom.KnownDeviceTypes";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::DeviceAccessMode> = L"Windows.Devices.Custom.DeviceAccessMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::DeviceSharingMode> = L"Windows.Devices.Custom.DeviceSharingMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IOControlAccessMode> = L"Windows.Devices.Custom.IOControlAccessMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IOControlBufferingMethod> = L"Windows.Devices.Custom.IOControlBufferingMethod";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::ICustomDevice> = L"Windows.Devices.Custom.ICustomDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::ICustomDeviceStatics> = L"Windows.Devices.Custom.ICustomDeviceStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IIOControlCode> = L"Windows.Devices.Custom.IIOControlCode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IIOControlCodeFactory> = L"Windows.Devices.Custom.IIOControlCodeFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Custom::IKnownDeviceTypesStatics> = L"Windows.Devices.Custom.IKnownDeviceTypesStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Custom::ICustomDevice>{ 0xDD30251F,0xC48B,0x43BD,{ 0xBC,0xB1,0xDE,0xC8,0x8F,0x15,0x14,0x3E } }; // DD30251F-C48B-43BD-BCB1-DEC88F15143E
    template <> inline constexpr guid guid_v<llm::OS::Devices::Custom::ICustomDeviceStatics>{ 0xC8220312,0xEF4C,0x46B1,{ 0xA5,0x8E,0xEE,0xB3,0x08,0xDC,0x89,0x17 } }; // C8220312-EF4C-46B1-A58E-EEB308DC8917
    template <> inline constexpr guid guid_v<llm::OS::Devices::Custom::IIOControlCode>{ 0x0E9559E7,0x60C8,0x4375,{ 0xA7,0x61,0x7F,0x88,0x08,0x06,0x6C,0x60 } }; // 0E9559E7-60C8-4375-A761-7F8808066C60
    template <> inline constexpr guid guid_v<llm::OS::Devices::Custom::IIOControlCodeFactory>{ 0x856A7CF0,0x4C11,0x44AE,{ 0xAF,0xC6,0xB8,0xD4,0xA2,0x12,0x78,0x8F } }; // 856A7CF0-4C11-44AE-AFC6-B8D4A212788F
    template <> inline constexpr guid guid_v<llm::OS::Devices::Custom::IKnownDeviceTypesStatics>{ 0xEE5479C2,0x5448,0x45DA,{ 0xAD,0x1B,0x24,0x94,0x8C,0x23,0x90,0x94 } }; // EE5479C2-5448-45DA-AD1B-24948C239094
    template <> struct default_interface<llm::OS::Devices::Custom::CustomDevice>{ using type = llm::OS::Devices::Custom::ICustomDevice; };
    template <> struct default_interface<llm::OS::Devices::Custom::IOControlCode>{ using type = llm::OS::Devices::Custom::IIOControlCode; };
    template <> struct abi<llm::OS::Devices::Custom::ICustomDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InputStream(void**) noexcept = 0;
            virtual int32_t __stdcall get_OutputStream(void**) noexcept = 0;
            virtual int32_t __stdcall SendIOControlAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall TrySendIOControlAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Custom::ICustomDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(llm::guid, void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Custom::IIOControlCode>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AccessMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_BufferingMethod(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Function(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceType(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_ControlCode(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Custom::IIOControlCodeFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateIOControlCode(uint16_t, uint16_t, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Custom::IKnownDeviceTypesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Unknown(uint16_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Custom_ICustomDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) InputStream() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) OutputStream() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) SendIOControlAsync(llm::OS::Devices::Custom::IIOControlCode const& ioControlCode, llm::OS::Storage::Streams::IBuffer const& inputBuffer, llm::OS::Storage::Streams::IBuffer const& outputBuffer) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TrySendIOControlAsync(llm::OS::Devices::Custom::IIOControlCode const& ioControlCode, llm::OS::Storage::Streams::IBuffer const& inputBuffer, llm::OS::Storage::Streams::IBuffer const& outputBuffer) const;
    };
    template <> struct consume<llm::OS::Devices::Custom::ICustomDevice>
    {
        template <typename D> using type = consume_Windows_Devices_Custom_ICustomDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Custom_ICustomDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(llm::guid const& classGuid) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Custom::CustomDevice>) FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::Custom::DeviceAccessMode const& desiredAccess, llm::OS::Devices::Custom::DeviceSharingMode const& sharingMode) const;
    };
    template <> struct consume<llm::OS::Devices::Custom::ICustomDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Custom_ICustomDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Custom_IIOControlCode
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlAccessMode) AccessMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlBufferingMethod) BufferingMethod() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) Function() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) DeviceType() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ControlCode() const;
    };
    template <> struct consume<llm::OS::Devices::Custom::IIOControlCode>
    {
        template <typename D> using type = consume_Windows_Devices_Custom_IIOControlCode<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Custom_IIOControlCodeFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlCode) CreateIOControlCode(uint16_t deviceType, uint16_t function, llm::OS::Devices::Custom::IOControlAccessMode const& accessMode, llm::OS::Devices::Custom::IOControlBufferingMethod const& bufferingMethod) const;
    };
    template <> struct consume<llm::OS::Devices::Custom::IIOControlCodeFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Custom_IIOControlCodeFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Custom_IKnownDeviceTypesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) Unknown() const;
    };
    template <> struct consume<llm::OS::Devices::Custom::IKnownDeviceTypesStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Custom_IKnownDeviceTypesStatics<D>;
    };
}
#endif
