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
#ifndef LLM_OS_System_Power_0_H
#define LLM_OS_System_Power_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
LLM_EXPORT namespace llm:OS::System::Power
{
    enum class BatteryStatus : int32_t
    {
        NotPresent = 0,
        Discharging = 1,
        Idle = 2,
        Charging = 3,
    };
    enum class EnergySaverStatus : int32_t
    {
        Disabled = 0,
        Off = 1,
        On = 2,
    };
    enum class PowerSupplyStatus : int32_t
    {
        NotPresent = 0,
        Inadequate = 1,
        Adequate = 2,
    };
    struct IBackgroundEnergyManagerStatics;
    struct IForegroundEnergyManagerStatics;
    struct IPowerManagerStatics;
    struct BackgroundEnergyManager;
    struct ForegroundEnergyManager;
    struct PowerManager;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Power::IBackgroundEnergyManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Power::IForegroundEnergyManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Power::IPowerManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Power::BackgroundEnergyManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::Power::ForegroundEnergyManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::Power::PowerManager>{ using type = class_category; };
    template <> struct category<llm:OS::System::Power::BatteryStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::Power::EnergySaverStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::System::Power::PowerSupplyStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Power::BackgroundEnergyManager> = L"Windows.System.Power.BackgroundEnergyManager";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::ForegroundEnergyManager> = L"Windows.System.Power.ForegroundEnergyManager";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::PowerManager> = L"Windows.System.Power.PowerManager";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::BatteryStatus> = L"Windows.System.Power.BatteryStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::EnergySaverStatus> = L"Windows.System.Power.EnergySaverStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::PowerSupplyStatus> = L"Windows.System.Power.PowerSupplyStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::IBackgroundEnergyManagerStatics> = L"Windows.System.Power.IBackgroundEnergyManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::IForegroundEnergyManagerStatics> = L"Windows.System.Power.IForegroundEnergyManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::Power::IPowerManagerStatics> = L"Windows.System.Power.IPowerManagerStatics";
    template <> inline constexpr guid guid_v<llm:OS::System::Power::IBackgroundEnergyManagerStatics>{ 0xB3161D95,0x1180,0x4376,{ 0x96,0xE1,0x40,0x95,0x56,0x81,0x47,0xCE } }; // B3161D95-1180-4376-96E1-4095568147CE
    template <> inline constexpr guid guid_v<llm:OS::System::Power::IForegroundEnergyManagerStatics>{ 0x9FF86872,0xE677,0x4814,{ 0x9A,0x20,0x53,0x37,0xCA,0x73,0x2B,0x98 } }; // 9FF86872-E677-4814-9A20-5337CA732B98
    template <> inline constexpr guid guid_v<llm:OS::System::Power::IPowerManagerStatics>{ 0x1394825D,0x62CE,0x4364,{ 0x98,0xD5,0xAA,0x28,0xC7,0xFB,0xD1,0x5B } }; // 1394825D-62CE-4364-98D5-AA28C7FBD15B
    template <> struct abi<llm:OS::System::Power::IBackgroundEnergyManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LowUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_NearMaxAcceptableUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxAcceptableUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExcessiveUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_NearTerminationUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TerminationUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RecentEnergyUsage(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RecentEnergyUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall add_RecentEnergyUsageIncreased(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RecentEnergyUsageIncreased(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RecentEnergyUsageReturnedToLow(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RecentEnergyUsageReturnedToLow(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Power::IForegroundEnergyManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LowUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_NearMaxAcceptableUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxAcceptableUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExcessiveUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RecentEnergyUsage(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RecentEnergyUsageLevel(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall add_RecentEnergyUsageIncreased(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RecentEnergyUsageIncreased(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RecentEnergyUsageReturnedToLow(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RecentEnergyUsageReturnedToLow(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Power::IPowerManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnergySaverStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_EnergySaverStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnergySaverStatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_BatteryStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_BatteryStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_BatteryStatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_PowerSupplyStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_PowerSupplyStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PowerSupplyStatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_RemainingChargePercent(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_RemainingChargePercentChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RemainingChargePercentChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_RemainingDischargeTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall add_RemainingDischargeTimeChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RemainingDischargeTimeChanged(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Power_IBackgroundEnergyManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) LowUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) NearMaxAcceptableUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxAcceptableUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ExcessiveUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) NearTerminationUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TerminationUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) RecentEnergyUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) RecentEnergyUsageLevel() const;
        LLM_IMPL_AUTO(llm::event_token) RecentEnergyUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RecentEnergyUsageIncreased_revoker = impl::event_revoker<llm:OS::System::Power::IBackgroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IBackgroundEnergyManagerStatics>::remove_RecentEnergyUsageIncreased>;
        [[nodiscard]] RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RecentEnergyUsageIncreased(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RecentEnergyUsageReturnedToLow(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RecentEnergyUsageReturnedToLow_revoker = impl::event_revoker<llm:OS::System::Power::IBackgroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IBackgroundEnergyManagerStatics>::remove_RecentEnergyUsageReturnedToLow>;
        [[nodiscard]] RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RecentEnergyUsageReturnedToLow(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Power::IBackgroundEnergyManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Power_IForegroundEnergyManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) LowUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) NearMaxAcceptableUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxAcceptableUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ExcessiveUsageLevel() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) RecentEnergyUsage() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) RecentEnergyUsageLevel() const;
        LLM_IMPL_AUTO(llm::event_token) RecentEnergyUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RecentEnergyUsageIncreased_revoker = impl::event_revoker<llm:OS::System::Power::IForegroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IForegroundEnergyManagerStatics>::remove_RecentEnergyUsageIncreased>;
        [[nodiscard]] RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RecentEnergyUsageIncreased(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RecentEnergyUsageReturnedToLow(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RecentEnergyUsageReturnedToLow_revoker = impl::event_revoker<llm:OS::System::Power::IForegroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IForegroundEnergyManagerStatics>::remove_RecentEnergyUsageReturnedToLow>;
        [[nodiscard]] RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RecentEnergyUsageReturnedToLow(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Power::IForegroundEnergyManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Power_IPowerManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Power::EnergySaverStatus) EnergySaverStatus() const;
        LLM_IMPL_AUTO(llm::event_token) EnergySaverStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using EnergySaverStatusChanged_revoker = impl::event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_EnergySaverStatusChanged>;
        [[nodiscard]] EnergySaverStatusChanged_revoker EnergySaverStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnergySaverStatusChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Power::BatteryStatus) BatteryStatus() const;
        LLM_IMPL_AUTO(llm::event_token) BatteryStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using BatteryStatusChanged_revoker = impl::event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_BatteryStatusChanged>;
        [[nodiscard]] BatteryStatusChanged_revoker BatteryStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) BatteryStatusChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Power::PowerSupplyStatus) PowerSupplyStatus() const;
        LLM_IMPL_AUTO(llm::event_token) PowerSupplyStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using PowerSupplyStatusChanged_revoker = impl::event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_PowerSupplyStatusChanged>;
        [[nodiscard]] PowerSupplyStatusChanged_revoker PowerSupplyStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) PowerSupplyStatusChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) RemainingChargePercent() const;
        LLM_IMPL_AUTO(llm::event_token) RemainingChargePercentChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RemainingChargePercentChanged_revoker = impl::event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_RemainingChargePercentChanged>;
        [[nodiscard]] RemainingChargePercentChanged_revoker RemainingChargePercentChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RemainingChargePercentChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) RemainingDischargeTime() const;
        LLM_IMPL_AUTO(llm::event_token) RemainingDischargeTimeChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RemainingDischargeTimeChanged_revoker = impl::event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_RemainingDischargeTimeChanged>;
        [[nodiscard]] RemainingDischargeTimeChanged_revoker RemainingDischargeTimeChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RemainingDischargeTimeChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Power::IPowerManagerStatics>
    {
        template <typename D> using type = consume_Windows_System_Power_IPowerManagerStatics<D>;
    };
}
#endif
