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
#ifndef LLM_OS_Devices_Spi_0_H
#define LLM_OS_Devices_Spi_0_H
LLM_EXPORT namespace llm::OS::Devices::Spi::Provider
{
    struct ISpiProvider;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Spi
{
    enum class SpiMode : int32_t
    {
        Mode0 = 0,
        Mode1 = 1,
        Mode2 = 2,
        Mode3 = 3,
    };
    enum class SpiSharingMode : int32_t
    {
        Exclusive = 0,
        Shared = 1,
    };
    struct ISpiBusInfo;
    struct ISpiConnectionSettings;
    struct ISpiConnectionSettingsFactory;
    struct ISpiController;
    struct ISpiControllerStatics;
    struct ISpiDevice;
    struct ISpiDeviceStatics;
    struct SpiBusInfo;
    struct SpiConnectionSettings;
    struct SpiController;
    struct SpiDevice;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Spi::ISpiBusInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiConnectionSettings>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiController>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiControllerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::ISpiDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiBusInfo>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiConnectionSettings>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiController>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiDevice>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Spi::SpiSharingMode>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiBusInfo> = L"Windows.Devices.Spi.SpiBusInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiConnectionSettings> = L"Windows.Devices.Spi.SpiConnectionSettings";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiController> = L"Windows.Devices.Spi.SpiController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiDevice> = L"Windows.Devices.Spi.SpiDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiMode> = L"Windows.Devices.Spi.SpiMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::SpiSharingMode> = L"Windows.Devices.Spi.SpiSharingMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiBusInfo> = L"Windows.Devices.Spi.ISpiBusInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiConnectionSettings> = L"Windows.Devices.Spi.ISpiConnectionSettings";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory> = L"Windows.Devices.Spi.ISpiConnectionSettingsFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiController> = L"Windows.Devices.Spi.ISpiController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiControllerStatics> = L"Windows.Devices.Spi.ISpiControllerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiDevice> = L"Windows.Devices.Spi.ISpiDevice";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Spi::ISpiDeviceStatics> = L"Windows.Devices.Spi.ISpiDeviceStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiBusInfo>{ 0x9929444A,0x54F2,0x48C6,{ 0xB9,0x52,0x9C,0x32,0xFC,0x02,0xC6,0x69 } }; // 9929444A-54F2-48C6-B952-9C32FC02C669
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiConnectionSettings>{ 0x5283A37F,0xF935,0x4B9F,{ 0xA7,0xA7,0x3A,0x78,0x90,0xAF,0xA5,0xCE } }; // 5283A37F-F935-4B9F-A7A7-3A7890AFA5CE
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory>{ 0xFF99081E,0x10C4,0x44B7,{ 0x9F,0xEA,0xA7,0x48,0xB5,0xA4,0x6F,0x31 } }; // FF99081E-10C4-44B7-9FEA-A748B5A46F31
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiController>{ 0xA8D3C829,0x9895,0x4159,{ 0xA9,0x34,0x87,0x41,0xF1,0xEE,0x6D,0x27 } }; // A8D3C829-9895-4159-A934-8741F1EE6D27
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiControllerStatics>{ 0x0D5229E2,0x138B,0x4E48,{ 0xB9,0x64,0x4F,0x2F,0x79,0xB9,0xC5,0xA2 } }; // 0D5229E2-138B-4E48-B964-4F2F79B9C5A2
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiDevice>{ 0x05D5356D,0x11B6,0x4D39,{ 0x84,0xD5,0x95,0xDF,0xB4,0xC9,0xF2,0xCE } }; // 05D5356D-11B6-4D39-84D5-95DFB4C9F2CE
    template <> inline constexpr guid guid_v<llm::OS::Devices::Spi::ISpiDeviceStatics>{ 0xA278E559,0x5720,0x4D3F,{ 0xBD,0x93,0x56,0xF5,0xFF,0x5A,0x58,0x79 } }; // A278E559-5720-4D3F-BD93-56F5FF5A5879
    template <> struct default_interface<llm::OS::Devices::Spi::SpiBusInfo>{ using type = llm::OS::Devices::Spi::ISpiBusInfo; };
    template <> struct default_interface<llm::OS::Devices::Spi::SpiConnectionSettings>{ using type = llm::OS::Devices::Spi::ISpiConnectionSettings; };
    template <> struct default_interface<llm::OS::Devices::Spi::SpiController>{ using type = llm::OS::Devices::Spi::ISpiController; };
    template <> struct default_interface<llm::OS::Devices::Spi::SpiDevice>{ using type = llm::OS::Devices::Spi::ISpiDevice; };
    template <> struct abi<llm::OS::Devices::Spi::ISpiBusInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChipSelectLineCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinClockFrequency(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxClockFrequency(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedDataBitLengths(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiConnectionSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChipSelectLine(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ChipSelectLine(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DataBitLength(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DataBitLength(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ClockFrequency(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ClockFrequency(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SharingMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SharingMode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDevice(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetControllersAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectionSettings(void**) noexcept = 0;
            virtual int32_t __stdcall Write(uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall Read(uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall TransferSequential(uint32_t, uint8_t*, uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall TransferFullDuplex(uint32_t, uint8_t*, uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Spi::ISpiDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelectorFromFriendlyName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetBusInfo(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiBusInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ChipSelectLineCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinClockFrequency() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxClockFrequency() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<int32_t>) SupportedDataBitLengths() const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiBusInfo>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiBusInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiConnectionSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ChipSelectLine() const;
        LLM_IMPL_AUTO(void) ChipSelectLine(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm::OS::Devices::Spi::SpiMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) DataBitLength() const;
        LLM_IMPL_AUTO(void) DataBitLength(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ClockFrequency() const;
        LLM_IMPL_AUTO(void) ClockFrequency(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiSharingMode) SharingMode() const;
        LLM_IMPL_AUTO(void) SharingMode(llm::OS::Devices::Spi::SpiSharingMode const& value) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiConnectionSettings>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiConnectionSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiConnectionSettingsFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiConnectionSettings) Create(int32_t chipSelectLine) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiConnectionSettingsFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiConnectionSettingsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiController
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiDevice) GetDevice(llm::OS::Devices::Spi::SpiConnectionSettings const& settings) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiController>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiController<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiControllerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiController>) GetDefaultAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Spi::SpiController>>) GetControllersAsync(llm::OS::Devices::Spi::Provider::ISpiProvider const& provider) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiControllerStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiConnectionSettings) ConnectionSettings() const;
        LLM_IMPL_AUTO(void) Write(array_view<uint8_t const> buffer) const;
        LLM_IMPL_AUTO(void) Read(array_view<uint8_t> buffer) const;
        LLM_IMPL_AUTO(void) TransferSequential(array_view<uint8_t const> writeBuffer, array_view<uint8_t> readBuffer) const;
        LLM_IMPL_AUTO(void) TransferFullDuplex(array_view<uint8_t const> writeBuffer, array_view<uint8_t> readBuffer) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiDevice>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Spi_ISpiDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(param::hstring const& friendlyName) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Spi::SpiBusInfo) GetBusInfo(param::hstring const& busId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Spi::SpiDevice>) FromIdAsync(param::hstring const& busId, llm::OS::Devices::Spi::SpiConnectionSettings const& settings) const;
    };
    template <> struct consume<llm::OS::Devices::Spi::ISpiDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Spi_ISpiDeviceStatics<D>;
    };
}
#endif
