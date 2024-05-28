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
#ifndef LLM_OS_System_Power_H
#define LLM_OS_System_Power_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.Power.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::LowUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_LowUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::NearMaxAcceptableUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_NearMaxAcceptableUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::MaxAcceptableUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_MaxAcceptableUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::ExcessiveUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_ExcessiveUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::NearTerminationUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_NearTerminationUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::TerminationUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_TerminationUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsage() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_RecentEnergyUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->get_RecentEnergyUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->add_RecentEnergyUsageIncreased(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased_revoker consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RecentEnergyUsageIncreased_revoker>(this, RecentEnergyUsageIncreased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->remove_RecentEnergyUsageIncreased(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->add_RecentEnergyUsageReturnedToLow(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow_revoker consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RecentEnergyUsageReturnedToLow_revoker>(this, RecentEnergyUsageReturnedToLow(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IBackgroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IBackgroundEnergyManagerStatics)->remove_RecentEnergyUsageReturnedToLow(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::LowUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_LowUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::NearMaxAcceptableUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_NearMaxAcceptableUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::MaxAcceptableUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_MaxAcceptableUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::ExcessiveUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_ExcessiveUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsage() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_RecentEnergyUsage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageLevel() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->get_RecentEnergyUsageLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->add_RecentEnergyUsageIncreased(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased_revoker consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RecentEnergyUsageIncreased_revoker>(this, RecentEnergyUsageIncreased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageIncreased(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->remove_RecentEnergyUsageIncreased(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->add_RecentEnergyUsageReturnedToLow(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow_revoker consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RecentEnergyUsageReturnedToLow_revoker>(this, RecentEnergyUsageReturnedToLow(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IForegroundEnergyManagerStatics<D>::RecentEnergyUsageReturnedToLow(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IForegroundEnergyManagerStatics)->remove_RecentEnergyUsageReturnedToLow(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Power::EnergySaverStatus) consume_Windows_System_Power_IPowerManagerStatics<D>::EnergySaverStatus() const
    {
        llm::OS::System::Power::EnergySaverStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->get_EnergySaverStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IPowerManagerStatics<D>::EnergySaverStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->add_EnergySaverStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IPowerManagerStatics<D>::EnergySaverStatusChanged_revoker consume_Windows_System_Power_IPowerManagerStatics<D>::EnergySaverStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnergySaverStatusChanged_revoker>(this, EnergySaverStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IPowerManagerStatics<D>::EnergySaverStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->remove_EnergySaverStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Power::BatteryStatus) consume_Windows_System_Power_IPowerManagerStatics<D>::BatteryStatus() const
    {
        llm::OS::System::Power::BatteryStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->get_BatteryStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IPowerManagerStatics<D>::BatteryStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->add_BatteryStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IPowerManagerStatics<D>::BatteryStatusChanged_revoker consume_Windows_System_Power_IPowerManagerStatics<D>::BatteryStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, BatteryStatusChanged_revoker>(this, BatteryStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IPowerManagerStatics<D>::BatteryStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->remove_BatteryStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Power::PowerSupplyStatus) consume_Windows_System_Power_IPowerManagerStatics<D>::PowerSupplyStatus() const
    {
        llm::OS::System::Power::PowerSupplyStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->get_PowerSupplyStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IPowerManagerStatics<D>::PowerSupplyStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->add_PowerSupplyStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IPowerManagerStatics<D>::PowerSupplyStatusChanged_revoker consume_Windows_System_Power_IPowerManagerStatics<D>::PowerSupplyStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, PowerSupplyStatusChanged_revoker>(this, PowerSupplyStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IPowerManagerStatics<D>::PowerSupplyStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->remove_PowerSupplyStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingChargePercent() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->get_RemainingChargePercent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingChargePercentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->add_RemainingChargePercentChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingChargePercentChanged_revoker consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingChargePercentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RemainingChargePercentChanged_revoker>(this, RemainingChargePercentChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingChargePercentChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->remove_RemainingChargePercentChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingDischargeTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->get_RemainingDischargeTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingDischargeTimeChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->add_RemainingDischargeTimeChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingDischargeTimeChanged_revoker consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingDischargeTimeChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, RemainingDischargeTimeChanged_revoker>(this, RemainingDischargeTimeChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Power_IPowerManagerStatics<D>::RemainingDischargeTimeChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Power::IPowerManagerStatics)->remove_RemainingDischargeTimeChanged(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Power::IBackgroundEnergyManagerStatics> : produce_base<D, llm::OS::System::Power::IBackgroundEnergyManagerStatics>
    {
        int32_t __stdcall get_LowUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().LowUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NearMaxAcceptableUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NearMaxAcceptableUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAcceptableUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxAcceptableUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExcessiveUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExcessiveUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NearTerminationUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NearTerminationUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TerminationUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TerminationUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecentEnergyUsage(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RecentEnergyUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecentEnergyUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RecentEnergyUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RecentEnergyUsageIncreased(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RecentEnergyUsageIncreased(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RecentEnergyUsageIncreased(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecentEnergyUsageIncreased(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RecentEnergyUsageReturnedToLow(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RecentEnergyUsageReturnedToLow(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RecentEnergyUsageReturnedToLow(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecentEnergyUsageReturnedToLow(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Power::IForegroundEnergyManagerStatics> : produce_base<D, llm::OS::System::Power::IForegroundEnergyManagerStatics>
    {
        int32_t __stdcall get_LowUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().LowUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NearMaxAcceptableUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NearMaxAcceptableUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAcceptableUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxAcceptableUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExcessiveUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ExcessiveUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecentEnergyUsage(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RecentEnergyUsage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecentEnergyUsageLevel(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RecentEnergyUsageLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RecentEnergyUsageIncreased(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RecentEnergyUsageIncreased(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RecentEnergyUsageIncreased(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecentEnergyUsageIncreased(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RecentEnergyUsageReturnedToLow(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RecentEnergyUsageReturnedToLow(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RecentEnergyUsageReturnedToLow(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecentEnergyUsageReturnedToLow(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Power::IPowerManagerStatics> : produce_base<D, llm::OS::System::Power::IPowerManagerStatics>
    {
        int32_t __stdcall get_EnergySaverStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Power::EnergySaverStatus>(this->shim().EnergySaverStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_EnergySaverStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnergySaverStatusChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnergySaverStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnergySaverStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_BatteryStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Power::BatteryStatus>(this->shim().BatteryStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_BatteryStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BatteryStatusChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BatteryStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BatteryStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_PowerSupplyStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Power::PowerSupplyStatus>(this->shim().PowerSupplyStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PowerSupplyStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PowerSupplyStatusChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PowerSupplyStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PowerSupplyStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_RemainingChargePercent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RemainingChargePercent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RemainingChargePercentChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RemainingChargePercentChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemainingChargePercentChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemainingChargePercentChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_RemainingDischargeTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().RemainingDischargeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RemainingDischargeTimeChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RemainingDischargeTimeChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemainingDischargeTimeChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemainingDischargeTimeChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Power
{
    inline auto BackgroundEnergyManager::LowUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.LowUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::NearMaxAcceptableUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.NearMaxAcceptableUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::MaxAcceptableUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.MaxAcceptableUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::ExcessiveUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.ExcessiveUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::NearTerminationUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.NearTerminationUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::TerminationUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.TerminationUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsage()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsage(); });
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IBackgroundEnergyManagerStatics const&), BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageLevel(); });
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([&](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageIncreased(handler); });
    }
    inline BackgroundEnergyManager::RecentEnergyUsageIncreased_revoker BackgroundEnergyManager::RecentEnergyUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<BackgroundEnergyManager, llm::OS::System::Power::IBackgroundEnergyManagerStatics>();
        return { f, f.RecentEnergyUsageIncreased(handler) };
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsageIncreased(llm::event_token const& token)
    {
        impl::call_factory<BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([&](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageIncreased(token); });
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsageReturnedToLow(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([&](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageReturnedToLow(handler); });
    }
    inline BackgroundEnergyManager::RecentEnergyUsageReturnedToLow_revoker BackgroundEnergyManager::RecentEnergyUsageReturnedToLow(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<BackgroundEnergyManager, llm::OS::System::Power::IBackgroundEnergyManagerStatics>();
        return { f, f.RecentEnergyUsageReturnedToLow(handler) };
    }
    inline auto BackgroundEnergyManager::RecentEnergyUsageReturnedToLow(llm::event_token const& token)
    {
        impl::call_factory<BackgroundEnergyManager, IBackgroundEnergyManagerStatics>([&](IBackgroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageReturnedToLow(token); });
    }
    inline auto ForegroundEnergyManager::LowUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.LowUsageLevel(); });
    }
    inline auto ForegroundEnergyManager::NearMaxAcceptableUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.NearMaxAcceptableUsageLevel(); });
    }
    inline auto ForegroundEnergyManager::MaxAcceptableUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.MaxAcceptableUsageLevel(); });
    }
    inline auto ForegroundEnergyManager::ExcessiveUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.ExcessiveUsageLevel(); });
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsage()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsage(); });
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsageLevel()
    {
        return impl::call_factory_cast<uint32_t(*)(IForegroundEnergyManagerStatics const&), ForegroundEnergyManager, IForegroundEnergyManagerStatics>([](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageLevel(); });
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsageIncreased(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<ForegroundEnergyManager, IForegroundEnergyManagerStatics>([&](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageIncreased(handler); });
    }
    inline ForegroundEnergyManager::RecentEnergyUsageIncreased_revoker ForegroundEnergyManager::RecentEnergyUsageIncreased(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<ForegroundEnergyManager, llm::OS::System::Power::IForegroundEnergyManagerStatics>();
        return { f, f.RecentEnergyUsageIncreased(handler) };
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsageIncreased(llm::event_token const& token)
    {
        impl::call_factory<ForegroundEnergyManager, IForegroundEnergyManagerStatics>([&](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageIncreased(token); });
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsageReturnedToLow(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<ForegroundEnergyManager, IForegroundEnergyManagerStatics>([&](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageReturnedToLow(handler); });
    }
    inline ForegroundEnergyManager::RecentEnergyUsageReturnedToLow_revoker ForegroundEnergyManager::RecentEnergyUsageReturnedToLow(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<ForegroundEnergyManager, llm::OS::System::Power::IForegroundEnergyManagerStatics>();
        return { f, f.RecentEnergyUsageReturnedToLow(handler) };
    }
    inline auto ForegroundEnergyManager::RecentEnergyUsageReturnedToLow(llm::event_token const& token)
    {
        impl::call_factory<ForegroundEnergyManager, IForegroundEnergyManagerStatics>([&](IForegroundEnergyManagerStatics const& f) { return f.RecentEnergyUsageReturnedToLow(token); });
    }
    inline auto PowerManager::EnergySaverStatus()
    {
        return impl::call_factory_cast<llm::OS::System::Power::EnergySaverStatus(*)(IPowerManagerStatics const&), PowerManager, IPowerManagerStatics>([](IPowerManagerStatics const& f) { return f.EnergySaverStatus(); });
    }
    inline auto PowerManager::EnergySaverStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.EnergySaverStatusChanged(handler); });
    }
    inline PowerManager::EnergySaverStatusChanged_revoker PowerManager::EnergySaverStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerManager, llm::OS::System::Power::IPowerManagerStatics>();
        return { f, f.EnergySaverStatusChanged(handler) };
    }
    inline auto PowerManager::EnergySaverStatusChanged(llm::event_token const& token)
    {
        impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.EnergySaverStatusChanged(token); });
    }
    inline auto PowerManager::BatteryStatus()
    {
        return impl::call_factory_cast<llm::OS::System::Power::BatteryStatus(*)(IPowerManagerStatics const&), PowerManager, IPowerManagerStatics>([](IPowerManagerStatics const& f) { return f.BatteryStatus(); });
    }
    inline auto PowerManager::BatteryStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.BatteryStatusChanged(handler); });
    }
    inline PowerManager::BatteryStatusChanged_revoker PowerManager::BatteryStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerManager, llm::OS::System::Power::IPowerManagerStatics>();
        return { f, f.BatteryStatusChanged(handler) };
    }
    inline auto PowerManager::BatteryStatusChanged(llm::event_token const& token)
    {
        impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.BatteryStatusChanged(token); });
    }
    inline auto PowerManager::PowerSupplyStatus()
    {
        return impl::call_factory_cast<llm::OS::System::Power::PowerSupplyStatus(*)(IPowerManagerStatics const&), PowerManager, IPowerManagerStatics>([](IPowerManagerStatics const& f) { return f.PowerSupplyStatus(); });
    }
    inline auto PowerManager::PowerSupplyStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.PowerSupplyStatusChanged(handler); });
    }
    inline PowerManager::PowerSupplyStatusChanged_revoker PowerManager::PowerSupplyStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerManager, llm::OS::System::Power::IPowerManagerStatics>();
        return { f, f.PowerSupplyStatusChanged(handler) };
    }
    inline auto PowerManager::PowerSupplyStatusChanged(llm::event_token const& token)
    {
        impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.PowerSupplyStatusChanged(token); });
    }
    inline auto PowerManager::RemainingChargePercent()
    {
        return impl::call_factory_cast<int32_t(*)(IPowerManagerStatics const&), PowerManager, IPowerManagerStatics>([](IPowerManagerStatics const& f) { return f.RemainingChargePercent(); });
    }
    inline auto PowerManager::RemainingChargePercentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.RemainingChargePercentChanged(handler); });
    }
    inline PowerManager::RemainingChargePercentChanged_revoker PowerManager::RemainingChargePercentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerManager, llm::OS::System::Power::IPowerManagerStatics>();
        return { f, f.RemainingChargePercentChanged(handler) };
    }
    inline auto PowerManager::RemainingChargePercentChanged(llm::event_token const& token)
    {
        impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.RemainingChargePercentChanged(token); });
    }
    inline auto PowerManager::RemainingDischargeTime()
    {
        return impl::call_factory_cast<llm::OS::Foundation::TimeSpan(*)(IPowerManagerStatics const&), PowerManager, IPowerManagerStatics>([](IPowerManagerStatics const& f) { return f.RemainingDischargeTime(); });
    }
    inline auto PowerManager::RemainingDischargeTimeChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.RemainingDischargeTimeChanged(handler); });
    }
    inline PowerManager::RemainingDischargeTimeChanged_revoker PowerManager::RemainingDischargeTimeChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerManager, llm::OS::System::Power::IPowerManagerStatics>();
        return { f, f.RemainingDischargeTimeChanged(handler) };
    }
    inline auto PowerManager::RemainingDischargeTimeChanged(llm::event_token const& token)
    {
        impl::call_factory<PowerManager, IPowerManagerStatics>([&](IPowerManagerStatics const& f) { return f.RemainingDischargeTimeChanged(token); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Power::IBackgroundEnergyManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::IForegroundEnergyManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::IPowerManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::BackgroundEnergyManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::ForegroundEnergyManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Power::PowerManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
