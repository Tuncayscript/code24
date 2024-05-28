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
#ifndef LLM_OS_Devices_Sensors_Custom_H
#define LLM_OS_Devices_Sensors_Custom_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Sensors.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Sensors.Custom.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sensors::Custom::CustomSensorReading) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::GetCurrentReading() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->GetCurrentReading(&value));
        return llm::OS::Devices::Sensors::Custom::CustomSensorReading{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::MinimumReportInterval() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->get_MinimumReportInterval(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReportInterval(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->put_ReportInterval(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReportInterval() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->get_ReportInterval(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReadingChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sensors::Custom::CustomSensor, llm::OS::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->add_ReadingChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReadingChanged_revoker consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReadingChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sensors::Custom::CustomSensor, llm::OS::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ReadingChanged_revoker>(this, ReadingChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sensors_Custom_ICustomSensor<D>::ReadingChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor)->remove_ReadingChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sensors_Custom_ICustomSensor2<D>::ReportLatency(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor2)->put_ReportLatency(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sensors_Custom_ICustomSensor2<D>::ReportLatency() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor2)->get_ReportLatency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sensors_Custom_ICustomSensor2<D>::MaxBatchSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensor2)->get_MaxBatchSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sensors_Custom_ICustomSensorReading<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorReading)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Sensors_Custom_ICustomSensorReading<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorReading)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Devices_Sensors_Custom_ICustomSensorReading2<D>::PerformanceCount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorReading2)->get_PerformanceCount(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sensors::Custom::CustomSensorReading) consume_Windows_Devices_Sensors_Custom_ICustomSensorReadingChangedEventArgs<D>::Reading() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs)->get_Reading(&value));
        return llm::OS::Devices::Sensors::Custom::CustomSensorReading{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sensors_Custom_ICustomSensorStatics<D>::GetDeviceSelector(llm::guid const& interfaceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorStatics)->GetDeviceSelector(impl::bind_in(interfaceId), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sensors::Custom::CustomSensor>) consume_Windows_Devices_Sensors_Custom_ICustomSensorStatics<D>::FromIdAsync(param::hstring const& sensorId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sensors::Custom::ICustomSensorStatics)->FromIdAsync(*(void**)(&sensorId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sensors::Custom::CustomSensor>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensor> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensor>
    {
        int32_t __stdcall GetCurrentReading(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sensors::Custom::CustomSensorReading>(this->shim().GetCurrentReading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinimumReportInterval(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MinimumReportInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReportInterval(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportInterval(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReportInterval(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ReportInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ReadingChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ReadingChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sensors::Custom::CustomSensor, llm::OS::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ReadingChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadingChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensor2> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensor2>
    {
        int32_t __stdcall put_ReportLatency(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportLatency(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReportLatency(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ReportLatency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxBatchSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxBatchSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReading> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReading>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReading2> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReading2>
    {
        int32_t __stdcall get_PerformanceCount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().PerformanceCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs>
    {
        int32_t __stdcall get_Reading(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sensors::Custom::CustomSensorReading>(this->shim().Reading());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sensors::Custom::ICustomSensorStatics> : produce_base<D, llm::OS::Devices::Sensors::Custom::ICustomSensorStatics>
    {
        int32_t __stdcall GetDeviceSelector(llm::guid interfaceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::guid const*>(&interfaceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* sensorId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sensors::Custom::CustomSensor>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&sensorId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Sensors::Custom
{
    inline auto CustomSensor::GetDeviceSelector(llm::guid const& interfaceId)
    {
        return impl::call_factory<CustomSensor, ICustomSensorStatics>([&](ICustomSensorStatics const& f) { return f.GetDeviceSelector(interfaceId); });
    }
    inline auto CustomSensor::FromIdAsync(param::hstring const& sensorId)
    {
        return impl::call_factory<CustomSensor, ICustomSensorStatics>([&](ICustomSensorStatics const& f) { return f.FromIdAsync(sensorId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensor2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensorReading> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensorReading2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::ICustomSensorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::CustomSensor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::CustomSensorReading> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
