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
#ifndef LLM_OS_ApplicationModel_Store_LicenseManagement_H
#define LLM_OS_ApplicationModel_Store_LicenseManagement_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Store.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.Store.LicenseManagement.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics<D>::AddLicenseAsync(llm::OS::Storage::Streams::IBuffer const& license) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics)->AddLicenseAsync(*(void**)(&license), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics<D>::GetSatisfactionInfosAsync(param::async_iterable<hstring> const& contentIds, param::async_iterable<hstring> const& keyIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics)->GetSatisfactionInfosAsync(*(void**)(&contentIds), *(void**)(&keyIds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseManagerStatics2<D>::RefreshLicensesAsync(llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption const& refreshOption) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2)->RefreshLicensesAsync(static_cast<int32_t>(refreshOption), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedByDevice() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedByDevice(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedByOpenLicense() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedByOpenLicense(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedByTrial() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedByTrial(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedByPass() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedByPass(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedByInstallMedia() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedByInstallMedia(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::SatisfiedBySignedInUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_SatisfiedBySignedInUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionInfo<D>::IsSatisfied() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo)->get_IsSatisfied(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionResult<D>::LicenseSatisfactionInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult)->get_LicenseSatisfactionInfos(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_Store_LicenseManagement_ILicenseSatisfactionResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>
    {
        int32_t __stdcall AddLicenseAsync(void* license, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().AddLicenseAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&license)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSatisfactionInfosAsync(void* contentIds, void* keyIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>>(this->shim().GetSatisfactionInfosAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&contentIds), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&keyIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2>
    {
        int32_t __stdcall RefreshLicensesAsync(int32_t refreshOption, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RefreshLicensesAsync(*reinterpret_cast<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption const*>(&refreshOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo> : produce_base<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>
    {
        int32_t __stdcall get_SatisfiedByDevice(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedByDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatisfiedByOpenLicense(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedByOpenLicense());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatisfiedByTrial(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedByTrial());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatisfiedByPass(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedByPass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatisfiedByInstallMedia(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedByInstallMedia());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatisfiedBySignedInUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SatisfiedBySignedInUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSatisfied(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSatisfied());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> : produce_base<D, llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>
    {
        int32_t __stdcall get_LicenseSatisfactionInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>>(this->shim().LicenseSatisfactionInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::LicenseManagement
{
    inline auto LicenseManager::AddLicenseAsync(llm::OS::Storage::Streams::IBuffer const& license)
    {
        return impl::call_factory<LicenseManager, ILicenseManagerStatics>([&](ILicenseManagerStatics const& f) { return f.AddLicenseAsync(license); });
    }
    inline auto LicenseManager::GetSatisfactionInfosAsync(param::async_iterable<hstring> const& contentIds, param::async_iterable<hstring> const& keyIds)
    {
        return impl::call_factory<LicenseManager, ILicenseManagerStatics>([&](ILicenseManagerStatics const& f) { return f.GetSatisfactionInfosAsync(contentIds, keyIds); });
    }
    inline auto LicenseManager::RefreshLicensesAsync(llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption const& refreshOption)
    {
        return impl::call_factory<LicenseManager, ILicenseManagerStatics2>([&](ILicenseManagerStatics2 const& f) { return f.RefreshLicensesAsync(refreshOption); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
