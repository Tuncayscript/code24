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
#ifndef LLM_OS_Devices_Gpio_Provider_0_H
#define LLM_OS_Devices_Gpio_Provider_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Gpio::Provider
{
    enum class ProviderGpioPinDriveMode : int32_t
    {
        Input = 0,
        Output = 1,
        InputPullUp = 2,
        InputPullDown = 3,
        OutputOpenDrain = 4,
        OutputOpenDrainPullUp = 5,
        OutputOpenSource = 6,
        OutputOpenSourcePullDown = 7,
    };
    enum class ProviderGpioPinEdge : int32_t
    {
        FallingEdge = 0,
        RisingEdge = 1,
    };
    enum class ProviderGpioPinValue : int32_t
    {
        Low = 0,
        High = 1,
    };
    enum class ProviderGpioSharingMode : int32_t
    {
        Exclusive = 0,
        SharedReadOnly = 1,
    };
    struct IGpioControllerProvider;
    struct IGpioPinProvider;
    struct IGpioPinProviderValueChangedEventArgs;
    struct IGpioPinProviderValueChangedEventArgsFactory;
    struct IGpioProvider;
    struct GpioPinProviderValueChangedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::IGpioProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> = L"Windows.Devices.Gpio.Provider.GpioPinProviderValueChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode> = L"Windows.Devices.Gpio.Provider.ProviderGpioPinDriveMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge> = L"Windows.Devices.Gpio.Provider.ProviderGpioPinEdge";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue> = L"Windows.Devices.Gpio.Provider.ProviderGpioPinValue";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode> = L"Windows.Devices.Gpio.Provider.ProviderGpioSharingMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider> = L"Windows.Devices.Gpio.Provider.IGpioControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::IGpioPinProvider> = L"Windows.Devices.Gpio.Provider.IGpioPinProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> = L"Windows.Devices.Gpio.Provider.IGpioPinProviderValueChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory> = L"Windows.Devices.Gpio.Provider.IGpioPinProviderValueChangedEventArgsFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Gpio::Provider::IGpioProvider> = L"Windows.Devices.Gpio.Provider.IGpioProvider";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>{ 0xAD11CEC7,0x19EA,0x4B21,{ 0x87,0x4F,0xB9,0x1A,0xED,0x4A,0x25,0xDB } }; // AD11CEC7-19EA-4B21-874F-B91AED4A25DB
    template <> inline constexpr guid guid_v<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>{ 0x42344CB7,0x6ABC,0x40FF,{ 0x9C,0xE7,0x73,0xB8,0x53,0x01,0xB9,0x00 } }; // 42344CB7-6ABC-40FF-9CE7-73B85301B900
    template <> inline constexpr guid guid_v<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>{ 0x32A6D6F2,0x3D5B,0x44CD,{ 0x8F,0xBE,0x13,0xA6,0x9F,0x2E,0xDB,0x24 } }; // 32A6D6F2-3D5B-44CD-8FBE-13A69F2EDB24
    template <> inline constexpr guid guid_v<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>{ 0x3ECB0B59,0x568C,0x4392,{ 0xB2,0x4A,0x8A,0x59,0xA9,0x02,0xB1,0xF1 } }; // 3ECB0B59-568C-4392-B24A-8A59A902B1F1
    template <> inline constexpr guid guid_v<llm::OS::Devices::Gpio::Provider::IGpioProvider>{ 0x44E82707,0x08CA,0x434A,{ 0xAF,0xE0,0xD6,0x15,0x80,0x44,0x6F,0x7E } }; // 44E82707-08CA-434A-AFE0-D61580446F7E
    template <> struct default_interface<llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs>{ using type = llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs; };
    template <> struct abi<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PinCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall OpenPinProvider(int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ValueChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ValueChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_DebounceTimeout(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_DebounceTimeout(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_PinNumber(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SharingMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall IsDriveModeSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall GetDriveMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetDriveMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall Write(int32_t) noexcept = 0;
            virtual int32_t __stdcall Read(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Edge(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Gpio::Provider::IGpioProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetControllers(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Gpio_Provider_IGpioControllerProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) PinCount() const;
        LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::IGpioPinProvider) OpenPinProvider(int32_t pin, llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode const& sharingMode) const;
    };
    template <> struct consume<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Gpio_Provider_IGpioControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Gpio_Provider_IGpioPinProvider
    {
        LLM_IMPL_AUTO(llm::event_token) ValueChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> const& handler) const;
        using ValueChanged_revoker = impl::event_revoker<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, &impl::abi_t<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>::remove_ValueChanged>;
        [[nodiscard]] ValueChanged_revoker ValueChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ValueChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) DebounceTimeout() const;
        LLM_IMPL_AUTO(void) DebounceTimeout(llm::OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) PinNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode) SharingMode() const;
        LLM_IMPL_AUTO(bool) IsDriveModeSupported(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const& driveMode) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode) GetDriveMode() const;
        LLM_IMPL_AUTO(void) SetDriveMode(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const& value) const;
        LLM_IMPL_AUTO(void) Write(llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue const& value) const;
        LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue) Read() const;
    };
    template <> struct consume<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge) Edge() const;
    };
    template <> struct consume<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgsFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs) Create(llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge const& edge) const;
    };
    template <> struct consume<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
    {
        template <typename D> using type = consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Gpio_Provider_IGpioProvider
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>) GetControllers() const;
    };
    template <> struct consume<llm::OS::Devices::Gpio::Provider::IGpioProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Gpio_Provider_IGpioProvider<D>;
    };
}
#endif
