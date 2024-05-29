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
#ifndef LLM_OS_Devices_Pwm_Provider_0_H
#define LLM_OS_Devices_Pwm_Provider_0_H
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Devices::Pwm::Provider
{
    struct IPwmControllerProvider;
    struct IPwmProvider;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::Pwm::Provider::IPwmProvider>{ using type = interface_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider> = L"Windows.Devices.Pwm.Provider.IPwmControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Devices::Pwm::Provider::IPwmProvider> = L"Windows.Devices.Pwm.Provider.IPwmProvider";
    template <> inline constexpr guid guid_v<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>{ 0x1300593B,0xE2E3,0x40A4,{ 0xB7,0xD9,0x48,0xDF,0xF0,0x37,0x7A,0x52 } }; // 1300593B-E2E3-40A4-B7D9-48DFF0377A52
    template <> inline constexpr guid guid_v<llm::OS::Devices::Pwm::Provider::IPwmProvider>{ 0xA3301228,0x52F1,0x47B0,{ 0x93,0x49,0x66,0xBA,0x43,0xD2,0x59,0x02 } }; // A3301228-52F1-47B0-9349-66BA43D25902
    template <> struct abi<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PinCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ActualFrequency(double*) noexcept = 0;
            virtual int32_t __stdcall SetDesiredFrequency(double, double*) noexcept = 0;
            virtual int32_t __stdcall get_MaxFrequency(double*) noexcept = 0;
            virtual int32_t __stdcall get_MinFrequency(double*) noexcept = 0;
            virtual int32_t __stdcall AcquirePin(int32_t) noexcept = 0;
            virtual int32_t __stdcall ReleasePin(int32_t) noexcept = 0;
            virtual int32_t __stdcall EnablePin(int32_t) noexcept = 0;
            virtual int32_t __stdcall DisablePin(int32_t) noexcept = 0;
            virtual int32_t __stdcall SetPulseParameters(int32_t, double, bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::Pwm::Provider::IPwmProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetControllers(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) PinCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) ActualFrequency() const;
        LLM_IMPL_AUTO(double) SetDesiredFrequency(double frequency) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MaxFrequency() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinFrequency() const;
        LLM_IMPL_AUTO(void) AcquirePin(int32_t pin) const;
        LLM_IMPL_AUTO(void) ReleasePin(int32_t pin) const;
        LLM_IMPL_AUTO(void) EnablePin(int32_t pin) const;
        LLM_IMPL_AUTO(void) DisablePin(int32_t pin) const;
        LLM_IMPL_AUTO(void) SetPulseParameters(int32_t pin, double dutyCycle, bool invertPolarity) const;
    };
    template <> struct consume<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_Pwm_Provider_IPwmProvider
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>) GetControllers() const;
    };
    template <> struct consume<llm::OS::Devices::Pwm::Provider::IPwmProvider>
    {
        template <typename D> using type = consume_Windows_Devices_Pwm_Provider_IPwmProvider<D>;
    };
}
#endif
