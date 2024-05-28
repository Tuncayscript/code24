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
#ifndef LLM_OS_Security_Authentication_Identity_H
#define LLM_OS_Security_Authentication_Identity_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Authentication.Identity.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationInfo<D>::TenantId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo)->get_TenantId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationInfo<D>::TenantName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo)->get_TenantName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationInfo<D>::Subject() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo)->get_Subject(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationInfo<D>::KeyId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo)->get_KeyId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationInfo<D>::KeyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo)->get_KeyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>>) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationManager<D>::GetRegistrationsAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager)->GetRegistrationsAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager) consume_Windows_Security_Authentication_Identity_IEnterpriseKeyCredentialRegistrationManagerStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics)->get_Current(&value));
        return llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo> : produce_base<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>
    {
        int32_t __stdcall get_TenantId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TenantId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TenantName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TenantName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Subject(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Subject());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().KeyId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().KeyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager> : produce_base<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager>
    {
        int32_t __stdcall GetRegistrationsAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>>>(this->shim().GetRegistrationsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics> : produce_base<D, llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authentication::Identity
{
    inline auto EnterpriseKeyCredentialRegistrationManager::Current()
    {
        return impl::call_factory_cast<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager(*)(IEnterpriseKeyCredentialRegistrationManagerStatics const&), EnterpriseKeyCredentialRegistrationManager, IEnterpriseKeyCredentialRegistrationManagerStatics>([](IEnterpriseKeyCredentialRegistrationManagerStatics const& f) { return f.Current(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
