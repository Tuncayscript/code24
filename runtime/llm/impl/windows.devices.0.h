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
#ifndef LLM_OS_Devices_0_H
#define LLM_OS_Devices_0_H
LLM_EXPORT namespace llm::OS::Devices::Adc::Provider
{
    struct IAdcControllerProvider;
}
LLM_EXPORT namespace llm::OS::Devices::Gpio::Provider
{
    struct IGpioControllerProvider;
}
LLM_EXPORT namespace llm::OS::Devices::I2c::Provider
{
    struct II2cControllerProvider;
}
LLM_EXPORT namespace llm::OS::Devices::Pwm::Provider
{
    struct IPwmControllerProvider;
}
LLM_EXPORT namespace llm::OS::Devices::Spi::Provider
{
    struct ISpiControllerProvider;
}
LLM_EXPORT namespace llm::OS::Devices
{
    struct ILowLevelDevicesAggregateProvider;
    struct ILowLevelDevicesAggregateProviderFactory;
    struct ILowLevelDevicesController;
    struct ILowLevelDevicesControllerStatics;
    struct LowLevelDevicesAggregateProvider;
    struct LowLevelDevicesController;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::ILowLevelDevicesAggregateProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::ILowLevelDevicesController>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::ILowLevelDevicesControllerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::LowLevelDevicesAggregateProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::LowLevelDevicesController>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::LowLevelDevicesAggregateProvider> = L"Windows.Devices.LowLevelDevicesAggregateProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::LowLevelDevicesController> = L"Windows.Devices.LowLevelDevicesController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::ILowLevelDevicesAggregateProvider> = L"Windows.Devices.ILowLevelDevicesAggregateProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory> = L"Windows.Devices.ILowLevelDevicesAggregateProviderFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::ILowLevelDevicesController> = L"Windows.Devices.ILowLevelDevicesController";
    template <> inline constexpr auto& name_v<llm::OS::Devices::ILowLevelDevicesControllerStatics> = L"Windows.Devices.ILowLevelDevicesControllerStatics";
    template <> inline constexpr guid guid_v<llm::OS::Devices::ILowLevelDevicesAggregateProvider>{ 0xA73E561C,0xAAC1,0x4EC7,{ 0xA8,0x52,0x47,0x9F,0x70,0x60,0xD0,0x1F } }; // A73E561C-AAC1-4EC7-A852-479F7060D01F
    template <> inline constexpr guid guid_v<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory>{ 0x9AC4AAF6,0x3473,0x465E,{ 0x96,0xD5,0x36,0x28,0x1A,0x2C,0x57,0xAF } }; // 9AC4AAF6-3473-465E-96D5-36281A2C57AF
    template <> inline constexpr guid guid_v<llm::OS::Devices::ILowLevelDevicesController>{ 0x2EC23DD4,0x179B,0x45DE,{ 0x9B,0x39,0x3A,0xE0,0x25,0x27,0xDE,0x52 } }; // 2EC23DD4-179B-45DE-9B39-3AE02527DE52
    template <> inline constexpr guid guid_v<llm::OS::Devices::ILowLevelDevicesControllerStatics>{ 0x093E926A,0xFCCB,0x4394,{ 0xA6,0x97,0x19,0xDE,0x63,0x7C,0x2D,0xB3 } }; // 093E926A-FCCB-4394-A697-19DE637C2DB3
    template <> struct default_interface<llm::OS::Devices::LowLevelDevicesAggregateProvider>{ using type = llm::OS::Devices::ILowLevelDevicesAggregateProvider; };
    template <> struct default_interface<llm::OS::Devices::LowLevelDevicesController>{ using type = llm::OS::Devices::ILowLevelDevicesController; };
    template <> struct abi<llm::OS::Devices::ILowLevelDevicesAggregateProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AdcControllerProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_PwmControllerProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_GpioControllerProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_I2cControllerProvider(void**) noexcept = 0;
            virtual int32_t __stdcall get_SpiControllerProvider(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::ILowLevelDevicesController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::Devices::ILowLevelDevicesControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DefaultProvider(void**) noexcept = 0;
            virtual int32_t __stdcall put_DefaultProvider(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_ILowLevelDevicesAggregateProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Adc::Provider::IAdcControllerProvider) AdcControllerProvider() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider) PwmControllerProvider() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::IGpioControllerProvider) GpioControllerProvider() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::I2c::Provider::II2cControllerProvider) I2cControllerProvider() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Spi::Provider::ISpiControllerProvider) SpiControllerProvider() const;
    };
    template <> struct consume<llm::OS::Devices::ILowLevelDevicesAggregateProvider>
    {
        template <typename D> using type = consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_ILowLevelDevicesAggregateProviderFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::LowLevelDevicesAggregateProvider) Create(llm::OS::Devices::Adc::Provider::IAdcControllerProvider const& adc, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider const& pwm, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider const& gpio, llm::OS::Devices::I2c::Provider::II2cControllerProvider const& i2c, llm::OS::Devices::Spi::Provider::ISpiControllerProvider const& spi) const;
    };
    template <> struct consume<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory>
    {
        template <typename D> using type = consume_Windows_Devices_ILowLevelDevicesAggregateProviderFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_ILowLevelDevicesController
    {
    };
    template <> struct consume<llm::OS::Devices::ILowLevelDevicesController>
    {
        template <typename D> using type = consume_Windows_Devices_ILowLevelDevicesController<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_ILowLevelDevicesControllerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::ILowLevelDevicesAggregateProvider) DefaultProvider() const;
        LLM_IMPL_AUTO(void) DefaultProvider(llm::OS::Devices::ILowLevelDevicesAggregateProvider const& value) const;
    };
    template <> struct consume<llm::OS::Devices::ILowLevelDevicesControllerStatics>
    {
        template <typename D> using type = consume_Windows_Devices_ILowLevelDevicesControllerStatics<D>;
    };
}
#endif
