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
#ifndef LLM_OS_Devices_Adc_Provider_0_H
#define LLM_OS_Devices_Adc_Provider_0_H
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Adc::Provider
{
    enum class ProviderAdcChannelMode : int32_t
    {
        SingleEnded = 0,
        Differential = 1,
    };
    struct IAdcControllerProvider;
    struct IAdcProvider;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::Provider::IAdcProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode> = L"Windows.Devices.Adc.Provider.ProviderAdcChannelMode";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::Provider::IAdcControllerProvider> = L"Windows.Devices.Adc.Provider.IAdcControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Adc::Provider::IAdcProvider> = L"Windows.Devices.Adc.Provider.IAdcProvider";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>{ 0xBE545828,0x816D,0x4DE5,{ 0xA0,0x48,0xAB,0xA0,0x69,0x58,0xAA,0xA8 } }; // BE545828-816D-4DE5-A048-ABA06958AAA8
    template <> inline constexpr guid guid_v<llm::OS::Devices::Adc::Provider::IAdcProvider>{ 0x28953668,0x9359,0x4C57,{ 0xBC,0x88,0xE2,0x75,0xE8,0x16,0x38,0xC9 } }; // 28953668-9359-4C57-BC88-E275E81638C9
    template <> struct abi<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>
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
            virtual int32_t __stdcall AcquireChannel(int32_t) noexcept = 0;
            virtual int32_t __stdcall ReleaseChannel(int32_t) noexcept = 0;
            virtual int32_t __stdcall ReadValue(int32_t, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Adc::Provider::IAdcProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetControllers(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_Provider_IAdcControllerProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ChannelCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ResolutionInBits() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode) ChannelMode() const;
        LLM_IMPL_AUTO(void) ChannelMode(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const& value) const;
        LLM_IMPL_AUTO(bool) IsChannelModeSupported(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const& channelMode) const;
        LLM_IMPL_AUTO(void) AcquireChannel(int32_t channel) const;
        LLM_IMPL_AUTO(void) ReleaseChannel(int32_t channel) const;
        LLM_IMPL_AUTO(int32_t) ReadValue(int32_t channelNumber) const;
    };
    template <> struct consume<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Adc_Provider_IAdcProvider
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>) GetControllers() const;
    };
    template <> struct consume<llm::OS::Devices::Adc::Provider::IAdcProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Adc_Provider_IAdcProvider<D>;
    };
}
#endif
