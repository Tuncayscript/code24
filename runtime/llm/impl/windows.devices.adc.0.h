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
#ifndef LLM_OS_Devices_Adc_0_H
#define LLM_OS_Devices_Adc_0_H
LLM_EXPORT namespace llm::OS::Devices::Adc::Provider
{
    struct IAdcProvider;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Adc
{
    enum class AdcChannelMode : int32_t
    {
        SingleEnded = 0,
        Differential = 1,
    };
    struct IAdcChannel;
    struct IAdcController;
    struct IAdcControllerStatics;
    struct IAdcControllerStatics2;
    struct AdcChannel;
    struct AdcController;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Adc::IAdcChannel>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::IAdcController>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::IAdcControllerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::IAdcControllerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::AdcChannel>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Adc::AdcController>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Adc::AdcChannelMode>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::AdcChannel> = L"Windows.Devices.Adc.AdcChannel";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::AdcController> = L"Windows.Devices.Adc.AdcController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::AdcChannelMode> = L"Windows.Devices.Adc.AdcChannelMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::IAdcChannel> = L"Windows.Devices.Adc.IAdcChannel";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::IAdcController> = L"Windows.Devices.Adc.IAdcController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::IAdcControllerStatics> = L"Windows.Devices.Adc.IAdcControllerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::IAdcControllerStatics2> = L"Windows.Devices.Adc.IAdcControllerStatics2";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::IAdcChannel>{ 0x040BF414,0x2588,0x4A56,{ 0xAB,0xEF,0x73,0xA2,0x60,0xAC,0xC6,0x0A } }; // 040BF414-2588-4A56-ABEF-73A260ACC60A
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::IAdcController>{ 0x2A76E4B0,0xA896,0x4219,{ 0x86,0xB6,0xEA,0x8C,0xDC,0xE9,0x8F,0x56 } }; // 2A76E4B0-A896-4219-86B6-EA8CDCE98F56
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::IAdcControllerStatics>{ 0xCCE98E0C,0x01F8,0x4891,{ 0xBC,0x3B,0xBE,0x53,0xEF,0x27,0x9C,0xA4 } }; // CCE98E0C-01F8-4891-BC3B-BE53EF279CA4
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::IAdcControllerStatics2>{ 0xA2B93B1D,0x977B,0x4F5A,{ 0xA5,0xFE,0xA6,0xAB,0xAF,0xFE,0x64,0x84 } }; // A2B93B1D-977B-4F5A-A5FE-A6ABAFFE6484
    template <> struct default_interface<llm::OS::Devices::Adc::AdcChannel>{ using type = llm::OS::Devices::Adc::IAdcChannel; };
    template <> struct default_interface<llm::OS::Devices::Adc::AdcController>{ using type = llm::OS::Devices::Adc::IAdcController; };
    template <> struct abi<llm::OS::Devices::Adc::IAdcChannel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Controller(void**) noexcept = 0;
            virtual int32_t __stdcall ReadValue(int32_t*) noexcept = 0;
            virtual int32_t __stdcall ReadRatio(double*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Adc::IAdcController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChannelCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ResolutionInBits(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinValue(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxValue(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ChannelMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ChannelMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall IsChannelModeSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall OpenChannel(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Adc::IAdcControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetControllersAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Adc::IAdcControllerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_IAdcChannel
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Adc::AdcController) Controller() const;
        LLM_IMPL_AUTO(int32_t) ReadValue() const;
        LLM_IMPL_AUTO(double) ReadRatio() const;
    };
    template <> struct consume<llm::OS::Devices::Adc::IAdcChannel>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_IAdcChannel<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_IAdcController
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ChannelCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ResolutionInBits() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Adc::AdcChannelMode) ChannelMode() const;
        LLM_IMPL_AUTO(void) ChannelMode(llm::OS::Devices::Adc::AdcChannelMode const& value) const;
        LLM_IMPL_AUTO(bool) IsChannelModeSupported(llm::OS::Devices::Adc::AdcChannelMode const& channelMode) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Adc::AdcChannel) OpenChannel(int32_t channelNumber) const;
    };
    template <> struct consume<llm::OS::Devices::Adc::IAdcController>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_IAdcController<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_IAdcControllerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Adc::AdcController>>) GetControllersAsync(llm::OS::Devices::Adc::Provider::IAdcProvider const& provider) const;
    };
    template <> struct consume<llm::OS::Devices::Adc::IAdcControllerStatics>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_IAdcControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_IAdcControllerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Adc::AdcController>) GetDefaultAsync() const;
    };
    template <> struct consume<llm::OS::Devices::Adc::IAdcControllerStatics2>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_IAdcControllerStatics2<D>;
    };
}
#endif
