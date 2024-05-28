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
#ifndef LLM_OS_Devices_Geolocation_Provider_H
#define LLM_OS_Devices_Geolocation_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Geolocation.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Devices.Geolocation.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::IsOverridden() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::Provider::IGeolocationProvider)->get_IsOverridden(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus) consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::SetOverridePosition(llm::OS::Devices::Geolocation::BasicGeoposition const& newPosition, llm::OS::Devices::Geolocation::PositionSource const& positionSource, double accuracyInMeters) const
    {
        llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::Provider::IGeolocationProvider)->SetOverridePosition(impl::bind_in(newPosition), static_cast<int32_t>(positionSource), accuracyInMeters, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::ClearOverridePosition() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::Provider::IGeolocationProvider)->ClearOverridePosition());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::IsOverriddenChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::Provider::IGeolocationProvider)->add_IsOverriddenChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::IsOverriddenChanged_revoker consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::IsOverriddenChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsOverriddenChanged_revoker>(this, IsOverriddenChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_Provider_IGeolocationProvider<D>::IsOverriddenChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::Provider::IGeolocationProvider)->remove_IsOverriddenChanged(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::Provider::IGeolocationProvider> : produce_base<D, llm::OS::Devices::Geolocation::Provider::IGeolocationProvider>
    {
        int32_t __stdcall get_IsOverridden(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOverridden());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetOverridePosition(struct struct_Windows_Devices_Geolocation_BasicGeoposition newPosition, int32_t positionSource, double accuracyInMeters, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Geolocation::Provider::LocationOverrideStatus>(this->shim().SetOverridePosition(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&newPosition), *reinterpret_cast<llm::OS::Devices::Geolocation::PositionSource const*>(&positionSource), accuracyInMeters));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearOverridePosition() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearOverridePosition();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsOverriddenChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsOverriddenChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsOverriddenChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOverriddenChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Geolocation::Provider
{
    inline GeolocationProvider::GeolocationProvider() :
        GeolocationProvider(impl::call_factory_cast<GeolocationProvider(*)(llm::OS::Foundation::IActivationFactory const&), GeolocationProvider>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<GeolocationProvider>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Geolocation::Provider::IGeolocationProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Provider::GeolocationProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
