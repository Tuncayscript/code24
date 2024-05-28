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
#ifndef LLM_OS_Security_Authorization_AppCapabilityAccess_H
#define LLM_OS_Security_Authorization_AppCapabilityAccess_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Security.Authorization.AppCapabilityAccess.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::CapabilityName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->get_CapabilityName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::CheckAccess() const
    {
        llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->CheckAccess(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::AccessChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->add_AccessChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::AccessChanged_revoker consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::AccessChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccessChanged_revoker>(this, AccessChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>::AccessChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability)->remove_AccessChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability2<D>::DisplayMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability2)->get_DisplayMessage(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability2<D>::DisplayMessage(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability2)->put_DisplayMessage(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics<D>::RequestAccessForCapabilitiesAsync(param::async_iterable<hstring> const& capabilityNames) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics)->RequestAccessForCapabilitiesAsync(*(void**)(&capabilityNames), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics<D>::RequestAccessForCapabilitiesForUserAsync(llm::OS::System::User const& user, param::async_iterable<hstring> const& capabilityNames) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics)->RequestAccessForCapabilitiesForUserAsync(*(void**)(&user), *(void**)(&capabilityNames), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics<D>::Create(param::hstring const& capabilityName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics)->Create(*(void**)(&capabilityName), &result));
        return llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability) consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics<D>::CreateWithProcessIdForUser(llm::OS::System::User const& user, param::hstring const& capabilityName, uint32_t pid) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics)->CreateWithProcessIdForUser(*(void**)(&user), *(void**)(&capabilityName), pid, &result));
        return llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability> : produce_base<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability>
    {
        int32_t __stdcall get_CapabilityName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CapabilityName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckAccess(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>(this->shim().CheckAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AccessChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AccessChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccessChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability2> : produce_base<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>
    {
        int32_t __stdcall get_DisplayMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayMessage(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayMessage(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs> : produce_base<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics> : produce_base<D, llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics>
    {
        int32_t __stdcall RequestAccessForCapabilitiesAsync(void* capabilityNames, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>>(this->shim().RequestAccessForCapabilitiesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&capabilityNames)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessForCapabilitiesForUserAsync(void* user, void* capabilityNames, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>>(this->shim().RequestAccessForCapabilitiesForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&capabilityNames)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Create(void* capabilityName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability>(this->shim().Create(*reinterpret_cast<hstring const*>(&capabilityName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithProcessIdForUser(void* user, void* capabilityName, uint32_t pid, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability>(this->shim().CreateWithProcessIdForUser(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&capabilityName), pid));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authorization::AppCapabilityAccess
{
    inline auto AppCapability::RequestAccessForCapabilitiesAsync(param::async_iterable<hstring> const& capabilityNames)
    {
        return impl::call_factory<AppCapability, IAppCapabilityStatics>([&](IAppCapabilityStatics const& f) { return f.RequestAccessForCapabilitiesAsync(capabilityNames); });
    }
    inline auto AppCapability::RequestAccessForCapabilitiesForUserAsync(llm::OS::System::User const& user, param::async_iterable<hstring> const& capabilityNames)
    {
        return impl::call_factory<AppCapability, IAppCapabilityStatics>([&](IAppCapabilityStatics const& f) { return f.RequestAccessForCapabilitiesForUserAsync(user, capabilityNames); });
    }
    inline auto AppCapability::Create(param::hstring const& capabilityName)
    {
        return impl::call_factory<AppCapability, IAppCapabilityStatics>([&](IAppCapabilityStatics const& f) { return f.Create(capabilityName); });
    }
    inline auto AppCapability::CreateWithProcessIdForUser(llm::OS::System::User const& user, param::hstring const& capabilityName, uint32_t pid)
    {
        return impl::call_factory<AppCapability, IAppCapabilityStatics>([&](IAppCapabilityStatics const& f) { return f.CreateWithProcessIdForUser(user, capabilityName, pid); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapability2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapability> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
