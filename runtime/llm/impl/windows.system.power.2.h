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
#ifndef LLM_OS_System_Power_2_H
#define LLM_OS_System_Power_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.Power.1.h"
LLM_EXPORT namespace llm:OS::System::Power
{
    struct BackgroundEnergyManager
    {
        BackgroundEnergyManager() = delete;
        [[nodiscard]] static auto LowUsageLevel();
        [[nodiscard]] static auto NearMaxAcceptableUsageLevel();
        [[nodiscard]] static auto MaxAcceptableUsageLevel();
        [[nodiscard]] static auto ExcessiveUsageLevel();
        [[nodiscard]] static auto NearTerminationUsageLevel();
        [[nodiscard]] static auto TerminationUsageLevel();
        [[nodiscard]] static auto RecentEnergyUsage();
        [[nodiscard]] static auto RecentEnergyUsageLevel();
        static auto RecentEnergyUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RecentEnergyUsageIncreased_revoker = impl::factory_event_revoker<llm:OS::System::Power::IBackgroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IBackgroundEnergyManagerStatics>::remove_RecentEnergyUsageIncreased>;
        [[nodiscard]] static RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RecentEnergyUsageIncreased(llm::event_token const& token);
        static auto RecentEnergyUsageReturnedToLow(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RecentEnergyUsageReturnedToLow_revoker = impl::factory_event_revoker<llm:OS::System::Power::IBackgroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IBackgroundEnergyManagerStatics>::remove_RecentEnergyUsageReturnedToLow>;
        [[nodiscard]] static RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RecentEnergyUsageReturnedToLow(llm::event_token const& token);
    };
    struct ForegroundEnergyManager
    {
        ForegroundEnergyManager() = delete;
        [[nodiscard]] static auto LowUsageLevel();
        [[nodiscard]] static auto NearMaxAcceptableUsageLevel();
        [[nodiscard]] static auto MaxAcceptableUsageLevel();
        [[nodiscard]] static auto ExcessiveUsageLevel();
        [[nodiscard]] static auto RecentEnergyUsage();
        [[nodiscard]] static auto RecentEnergyUsageLevel();
        static auto RecentEnergyUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RecentEnergyUsageIncreased_revoker = impl::factory_event_revoker<llm:OS::System::Power::IForegroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IForegroundEnergyManagerStatics>::remove_RecentEnergyUsageIncreased>;
        [[nodiscard]] static RecentEnergyUsageIncreased_revoker RecentEnergyUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RecentEnergyUsageIncreased(llm::event_token const& token);
        static auto RecentEnergyUsageReturnedToLow(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RecentEnergyUsageReturnedToLow_revoker = impl::factory_event_revoker<llm:OS::System::Power::IForegroundEnergyManagerStatics, &impl::abi_t<llm:OS::System::Power::IForegroundEnergyManagerStatics>::remove_RecentEnergyUsageReturnedToLow>;
        [[nodiscard]] static RecentEnergyUsageReturnedToLow_revoker RecentEnergyUsageReturnedToLow(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RecentEnergyUsageReturnedToLow(llm::event_token const& token);
    };
    struct PowerManager
    {
        PowerManager() = delete;
        [[nodiscard]] static auto EnergySaverStatus();
        static auto EnergySaverStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using EnergySaverStatusChanged_revoker = impl::factory_event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_EnergySaverStatusChanged>;
        [[nodiscard]] static EnergySaverStatusChanged_revoker EnergySaverStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto EnergySaverStatusChanged(llm::event_token const& token);
        [[nodiscard]] static auto BatteryStatus();
        static auto BatteryStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using BatteryStatusChanged_revoker = impl::factory_event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_BatteryStatusChanged>;
        [[nodiscard]] static BatteryStatusChanged_revoker BatteryStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto BatteryStatusChanged(llm::event_token const& token);
        [[nodiscard]] static auto PowerSupplyStatus();
        static auto PowerSupplyStatusChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PowerSupplyStatusChanged_revoker = impl::factory_event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_PowerSupplyStatusChanged>;
        [[nodiscard]] static PowerSupplyStatusChanged_revoker PowerSupplyStatusChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PowerSupplyStatusChanged(llm::event_token const& token);
        [[nodiscard]] static auto RemainingChargePercent();
        static auto RemainingChargePercentChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RemainingChargePercentChanged_revoker = impl::factory_event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_RemainingChargePercentChanged>;
        [[nodiscard]] static RemainingChargePercentChanged_revoker RemainingChargePercentChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RemainingChargePercentChanged(llm::event_token const& token);
        [[nodiscard]] static auto RemainingDischargeTime();
        static auto RemainingDischargeTimeChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using RemainingDischargeTimeChanged_revoker = impl::factory_event_revoker<llm:OS::System::Power::IPowerManagerStatics, &impl::abi_t<llm:OS::System::Power::IPowerManagerStatics>::remove_RemainingDischargeTimeChanged>;
        [[nodiscard]] static RemainingDischargeTimeChanged_revoker RemainingDischargeTimeChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto RemainingDischargeTimeChanged(llm::event_token const& token);
    };
}
#endif
