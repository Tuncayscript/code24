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
#ifndef LLM_OS_Devices_Power_H
#define LLM_OS_Devices_Power_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.Power.2.h"
#include "llm/impl/Windows.Devices.Power.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Power_IBattery<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBattery)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Power::BatteryReport) consume_Windows_Devices_Power_IBattery<D>::GetReport() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBattery)->GetReport(&result));
        return llm::OS::Devices::Power::BatteryReport{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Power::Battery, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBattery)->add_ReportUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Power_IBattery<D>::ReportUpdated_revoker consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Power::Battery, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ReportUpdated_revoker>(this, ReportUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Power::IBattery)->remove_ReportUpdated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::ChargeRateInMilliwatts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryReport)->get_ChargeRateInMilliwatts(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::DesignCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryReport)->get_DesignCapacityInMilliwattHours(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::FullChargeCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryReport)->get_FullChargeCapacityInMilliwattHours(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::RemainingCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryReport)->get_RemainingCapacityInMilliwattHours(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Power::BatteryStatus) consume_Windows_Devices_Power_IBatteryReport<D>::Status() const
    {
        llm::OS::System::Power::BatteryStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryReport)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Power::Battery) consume_Windows_Devices_Power_IBatteryStatics<D>::AggregateBattery() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryStatics)->get_AggregateBattery(&result));
        return llm::OS::Devices::Power::Battery{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Power::Battery>) consume_Windows_Devices_Power_IBatteryStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryStatics)->FromIdAsync(*(void**)(&deviceId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Power::Battery>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Power_IBatteryStatics<D>::GetDeviceSelector() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Power::IBatteryStatics)->GetDeviceSelector(&result));
        return hstring{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Power::IBattery> : produce_base<D, llm::OS::Devices::Power::IBattery>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetReport(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Power::BatteryReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ReportUpdated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ReportUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Power::Battery, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ReportUpdated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUpdated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Power::IBatteryReport> : produce_base<D, llm::OS::Devices::Power::IBatteryReport>
    {
        int32_t __stdcall get_ChargeRateInMilliwatts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChargeRateInMilliwatts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesignCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().DesignCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullChargeCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().FullChargeCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemainingCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().RemainingCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Power::BatteryStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Power::IBatteryStatics> : produce_base<D, llm::OS::Devices::Power::IBatteryStatics>
    {
        int32_t __stdcall get_AggregateBattery(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Power::Battery>(this->shim().AggregateBattery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Power::Battery>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Power
{
    inline auto Battery::AggregateBattery()
    {
        return impl::call_factory_cast<llm::OS::Devices::Power::Battery(*)(IBatteryStatics const&), Battery, IBatteryStatics>([](IBatteryStatics const& f) { return f.AggregateBattery(); });
    }
    inline auto Battery::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<Battery, IBatteryStatics>([&](IBatteryStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto Battery::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IBatteryStatics const&), Battery, IBatteryStatics>([](IBatteryStatics const& f) { return f.GetDeviceSelector(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Power::IBattery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Power::IBatteryReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Power::IBatteryStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Power::Battery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Power::BatteryReport> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
