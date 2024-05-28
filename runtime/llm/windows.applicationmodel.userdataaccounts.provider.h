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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_Provider_H
#define LLM_OS_ApplicationModel_UserDataAccounts_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.UserDataAccounts.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountPartnerAccountInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountPartnerAccountInfo<D>::Priority() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo)->get_Priority(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountPartnerAccountInfo<D>::AccountKind() const
    {
        llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo)->get_AccountKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderAddAccountOperation<D>::ContentKinds() const
    {
        llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation)->get_ContentKinds(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo>) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderAddAccountOperation<D>::PartnerAccountInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation)->get_PartnerAccountInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderAddAccountOperation<D>::ReportCompleted(param::hstring const& userDataAccountId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation)->ReportCompleted(*(void**)(&userDataAccountId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderOperation<D>::Kind() const
    {
        llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderResolveErrorsOperation<D>::UserDataAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation)->get_UserDataAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderResolveErrorsOperation<D>::ReportCompleted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation)->ReportCompleted());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderSettingsOperation<D>::UserDataAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation)->get_UserDataAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_Provider_IUserDataAccountProviderSettingsOperation<D>::ReportCompleted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation)->ReportCompleted());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Priority(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Priority());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccountKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind>(this->shim().AccountKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation>
    {
        int32_t __stdcall get_ContentKinds(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds>(this->shim().ContentKinds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PartnerAccountInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo>>(this->shim().PartnerAccountInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted(void* userDataAccountId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<hstring const*>(&userDataAccountId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation>
    {
        int32_t __stdcall get_UserDataAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserDataAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation>
    {
        int32_t __stdcall get_UserDataAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserDataAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts::Provider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderAddAccountOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderResolveErrorsOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderSettingsOperation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
