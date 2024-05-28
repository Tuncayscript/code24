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
#ifndef LLM_OS_ApplicationModel_AppExtensions_H
#define LLM_OS_ApplicationModel_AppExtensions_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.ApplicationModel.AppExtensions.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::AppInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->get_AppInfo(&value));
        return llm::OS::ApplicationModel::AppInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::GetExtensionPropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->GetExtensionPropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>) consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>::GetPublicFolderAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension)->GetPublicFolderAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtension2<D>::AppUserModelId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtension2)->get_AppUserModelId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::FindAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->FindAllAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::RequestRemovePackageAsync(param::hstring const& packageFullName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->RequestRemovePackageAsync(*(void**)(&packageFullName), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageInstalled(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->add_PackageInstalled(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageInstalled_revoker consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageInstalled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageInstalled_revoker>(this, PackageInstalled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageInstalled(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->remove_PackageInstalled(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->add_PackageUpdating(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdating_revoker consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageUpdating_revoker>(this, PackageUpdating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdating(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->remove_PackageUpdating(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->add_PackageUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdated_revoker consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageUpdated_revoker>(this, PackageUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUpdated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->remove_PackageUpdated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUninstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->add_PackageUninstalling(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUninstalling_revoker consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUninstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageUninstalling_revoker>(this, PackageUninstalling(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageUninstalling(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->remove_PackageUninstalling(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->add_PackageStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageStatusChanged_revoker consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageStatusChanged_revoker>(this, PackageStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>::PackageStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog)->remove_PackageStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalogStatics<D>::Open(param::hstring const& appExtensionName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics)->Open(*(void**)(&appExtensionName), &value));
        return llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageInstalledEventArgs<D>::AppExtensionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs)->get_AppExtensionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageInstalledEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageInstalledEventArgs<D>::Extensions() const
    {
        void* values{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs)->get_Extensions(&values));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>{ values, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageStatusChangedEventArgs<D>::AppExtensionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs)->get_AppExtensionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageStatusChangedEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUninstallingEventArgs<D>::AppExtensionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs)->get_AppExtensionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUninstallingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatedEventArgs<D>::AppExtensionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs)->get_AppExtensionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatedEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatedEventArgs<D>::Extensions() const
    {
        void* values{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs)->get_Extensions(&values));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>{ values, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatingEventArgs<D>::AppExtensionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs)->get_AppExtensionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtension> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtension>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInfo>(this->shim().AppInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetExtensionPropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>>(this->shim().GetExtensionPropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPublicFolderAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>>(this->shim().GetPublicFolderAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtension2> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtension2>
    {
        int32_t __stdcall get_AppUserModelId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppUserModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>
    {
        int32_t __stdcall FindAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestRemovePackageAsync(void* packageFullName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestRemovePackageAsync(*reinterpret_cast<hstring const*>(&packageFullName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PackageInstalled(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageInstalled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageInstalled(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageInstalled(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageUpdating(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageUpdating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageUpdating(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageUpdating(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageUpdated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageUpdated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageUpdated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageUninstalling(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageUninstalling(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageUninstalling(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageUninstalling(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>
    {
        int32_t __stdcall Open(void* appExtensionName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog>(this->shim().Open(*reinterpret_cast<hstring const*>(&appExtensionName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>
    {
        int32_t __stdcall get_AppExtensionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppExtensionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Extensions(void** values) noexcept final try
        {
            clear_abi(values);
            typename D::abi_guard guard(this->shim());
            *values = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>(this->shim().Extensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>
    {
        int32_t __stdcall get_AppExtensionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppExtensionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>
    {
        int32_t __stdcall get_AppExtensionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppExtensionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>
    {
        int32_t __stdcall get_AppExtensionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppExtensionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Extensions(void** values) noexcept final try
        {
            clear_abi(values);
            typename D::abi_guard guard(this->shim());
            *values = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>(this->shim().Extensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>
    {
        int32_t __stdcall get_AppExtensionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppExtensionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::AppExtensions
{
    inline auto AppExtensionCatalog::Open(param::hstring const& appExtensionName)
    {
        return impl::call_factory<AppExtensionCatalog, IAppExtensionCatalogStatics>([&](IAppExtensionCatalogStatics const& f) { return f.Open(appExtensionName); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtension> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtension2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtension> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
