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
#ifndef LLM_OS_Devices_Display_0_H
#define LLM_OS_Devices_Display_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Point;
    struct Size;
}
LLM_EXPORT namespace llm::OS::Graphics
{
    struct DisplayAdapterId;
    struct SizeInt32;
}
LLM_EXPORT namespace llm::OS::Devices::Display
{
    enum class DisplayMonitorConnectionKind : int32_t
    {
        Internal = 0,
        Wired = 1,
        Wireless = 2,
        Virtual = 3,
    };
    enum class DisplayMonitorDescriptorKind : int32_t
    {
        Edid = 0,
        DisplayId = 1,
    };
    enum class DisplayMonitorPhysicalConnectorKind : int32_t
    {
        Unknown = 0,
        HD15 = 1,
        AnalogTV = 2,
        Dvi = 3,
        Hdmi = 4,
        Lvds = 5,
        Sdi = 6,
        DisplayPort = 7,
    };
    enum class DisplayMonitorUsageKind : int32_t
    {
        Standard = 0,
        HeadMounted = 1,
        SpecialPurpose = 2,
    };
    struct IDisplayMonitor;
    struct IDisplayMonitor2;
    struct IDisplayMonitorStatics;
    struct DisplayMonitor;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Display::IDisplayMonitor>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::IDisplayMonitor2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::IDisplayMonitorStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Display::DisplayMonitor>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Display::DisplayMonitorConnectionKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::DisplayMonitorDescriptorKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Display::DisplayMonitorUsageKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::DisplayMonitor> = L"Windows.Devices.Display.DisplayMonitor";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::DisplayMonitorConnectionKind> = L"Windows.Devices.Display.DisplayMonitorConnectionKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::DisplayMonitorDescriptorKind> = L"Windows.Devices.Display.DisplayMonitorDescriptorKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind> = L"Windows.Devices.Display.DisplayMonitorPhysicalConnectorKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::DisplayMonitorUsageKind> = L"Windows.Devices.Display.DisplayMonitorUsageKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::IDisplayMonitor> = L"Windows.Devices.Display.IDisplayMonitor";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::IDisplayMonitor2> = L"Windows.Devices.Display.IDisplayMonitor2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Display::IDisplayMonitorStatics> = L"Windows.Devices.Display.IDisplayMonitorStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::IDisplayMonitor>{ 0x1F6B15D4,0x1D01,0x4C51,{ 0x87,0xE2,0x6F,0x95,0x4A,0x77,0x2B,0x59 } }; // 1F6B15D4-1D01-4C51-87E2-6F954A772B59
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::IDisplayMonitor2>{ 0x023018E6,0xCB23,0x5830,{ 0x96,0xDF,0xA7,0xBF,0x6E,0x60,0x25,0x77 } }; // 023018E6-CB23-5830-96DF-A7BF6E602577
    template <> inline constexpr guid guid_v<llm::OS::Devices::Display::IDisplayMonitorStatics>{ 0x6EAE698F,0xA228,0x4C05,{ 0x82,0x1D,0xB6,0x95,0xD6,0x67,0xDE,0x8E } }; // 6EAE698F-A228-4C05-821D-B695D667DE8E
    template <> struct default_interface<llm::OS::Devices::Display::DisplayMonitor>{ using type = llm::OS::Devices::Display::IDisplayMonitor; };
    template <> struct abi<llm::OS::Devices::Display::IDisplayMonitor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectionKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhysicalConnector(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayAdapterDeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayAdapterId(struct struct_Windows_Graphics_DisplayAdapterId*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayAdapterTargetId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UsageKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_NativeResolutionInRawPixels(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall get_PhysicalSizeInInches(void**) noexcept = 0;
            virtual int32_t __stdcall get_RawDpiX(float*) noexcept = 0;
            virtual int32_t __stdcall get_RawDpiY(float*) noexcept = 0;
            virtual int32_t __stdcall get_RedPrimary(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_GreenPrimary(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_BluePrimary(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_WhitePoint(llm::OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall get_MaxLuminanceInNits(float*) noexcept = 0;
            virtual int32_t __stdcall get_MinLuminanceInNits(float*) noexcept = 0;
            virtual int32_t __stdcall get_MaxAverageFullFrameLuminanceInNits(float*) noexcept = 0;
            virtual int32_t __stdcall GetDescriptor(int32_t, uint32_t* __resultSize, uint8_t**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::IDisplayMonitor2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsDolbyVisionSupportedInHdrMode(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Display::IDisplayMonitorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FromInterfaceIdAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Display_IDisplayMonitor
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorConnectionKind) ConnectionKind() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind) PhysicalConnector() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayAdapterDeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) DisplayAdapterId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DisplayAdapterTargetId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorUsageKind) UsageKind() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) NativeResolutionInRawPixels() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Size>) PhysicalSizeInInches() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RawDpiX() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RawDpiY() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) RedPrimary() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) GreenPrimary() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) BluePrimary() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Point) WhitePoint() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxLuminanceInNits() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MinLuminanceInNits() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxAverageFullFrameLuminanceInNits() const;
        LLM_IMPL_AUTO(com_array<uint8_t>) GetDescriptor(llm::OS::Devices::Display::DisplayMonitorDescriptorKind const& descriptorKind) const;
    };
    template <> struct consume<llm::OS::Devices::Display::IDisplayMonitor>
    {
        template <typename D> using type = consume_Windows_Devices_Display_IDisplayMonitor<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_IDisplayMonitor2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDolbyVisionSupportedInHdrMode() const;
    };
    template <> struct consume<llm::OS::Devices::Display::IDisplayMonitor2>
    {
        template <typename D> using type = consume_Windows_Devices_Display_IDisplayMonitor2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Display_IDisplayMonitorStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>) FromIdAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>) FromInterfaceIdAsync(param::hstring const& deviceInterfaceId) const;
    };
    template <> struct consume<llm::OS::Devices::Display::IDisplayMonitorStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Display_IDisplayMonitorStatics<D>;
    };
}
#endif
