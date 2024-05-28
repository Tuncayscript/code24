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
#ifndef LLM_OS_Devices_Radios_H
#define LLM_OS_Devices_Radios_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Radios.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>) consume_Windows_Devices_Radios_IRadio<D>::SetStateAsync(llm::OS::Devices::Radios::RadioState const& value) const
    {
        void* retval{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->SetStateAsync(static_cast<int32_t>(value), &retval));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>{ retval, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Radios_IRadio<D>::StateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Radios::Radio, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->add_StateChanged(*(void**)(&handler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_Radios_IRadio<D>::StateChanged_revoker consume_Windows_Devices_Radios_IRadio<D>::StateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Radios::Radio, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StateChanged_revoker>(this, StateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Radios_IRadio<D>::StateChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->remove_StateChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Radios::RadioState) consume_Windows_Devices_Radios_IRadio<D>::State() const
    {
        llm::OS::Devices::Radios::RadioState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Radios_IRadio<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Radios::RadioKind) consume_Windows_Devices_Radios_IRadio<D>::Kind() const
    {
        llm::OS::Devices::Radios::RadioKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadio)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Radios::Radio>>) consume_Windows_Devices_Radios_IRadioStatics<D>::GetRadiosAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadioStatics)->GetRadiosAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Radios::Radio>>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Radios_IRadioStatics<D>::GetDeviceSelector() const
    {
        void* deviceSelector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadioStatics)->GetDeviceSelector(&deviceSelector));
        return hstring{ deviceSelector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::Radio>) consume_Windows_Devices_Radios_IRadioStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadioStatics)->FromIdAsync(*(void**)(&deviceId), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::Radio>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>) consume_Windows_Devices_Radios_IRadioStatics<D>::RequestAccessAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Radios::IRadioStatics)->RequestAccessAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Radios::IRadio> : produce_base<D, llm::OS::Devices::Radios::IRadio>
    {
        int32_t __stdcall SetStateAsync(int32_t value, void** retval) noexcept final try
        {
            clear_abi(retval);
            typename D::abi_guard guard(this->shim());
            *retval = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>>(this->shim().SetStateAsync(*reinterpret_cast<llm::OS::Devices::Radios::RadioState const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StateChanged(void* handler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().StateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Radios::Radio, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StateChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Radios::RadioState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Radios::RadioKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Radios::IRadioStatics> : produce_base<D, llm::OS::Devices::Radios::IRadioStatics>
    {
        int32_t __stdcall GetRadiosAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Radios::Radio>>>(this->shim().GetRadiosAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** deviceSelector) noexcept final try
        {
            clear_abi(deviceSelector);
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::Radio>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Radios
{
    inline auto Radio::GetRadiosAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Radios::Radio>>(*)(IRadioStatics const&), Radio, IRadioStatics>([](IRadioStatics const& f) { return f.GetRadiosAsync(); });
    }
    inline auto Radio::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IRadioStatics const&), Radio, IRadioStatics>([](IRadioStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto Radio::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<Radio, IRadioStatics>([&](IRadioStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto Radio::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Radios::RadioAccessStatus>(*)(IRadioStatics const&), Radio, IRadioStatics>([](IRadioStatics const& f) { return f.RequestAccessAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Radios::IRadio> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Radios::IRadioStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Radios::Radio> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
