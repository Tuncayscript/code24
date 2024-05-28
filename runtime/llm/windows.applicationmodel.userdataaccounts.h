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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_H
#define LLM_OS_ApplicationModel_UserDataAccounts_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.Appointments.2.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.ApplicationModel.Email.2.h"
#include "llm/impl/Windows.ApplicationModel.UserDataTasks.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::UserDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_UserDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::UserDisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->put_UserDisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::OtherAppReadAccess() const
    {
        llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_OtherAppReadAccess(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::OtherAppReadAccess(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->put_OtherAppReadAccess(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::Icon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_Icon(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::DeviceAccountTypeId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_DeviceAccountTypeId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::SaveAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->SaveAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::DeleteAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->DeleteAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Appointments::AppointmentCalendar>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::FindAppointmentCalendarsAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->FindAppointmentCalendarsAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Appointments::AppointmentCalendar>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Email::EmailMailbox>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::FindEmailMailboxesAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->FindEmailMailboxesAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Email::EmailMailbox>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactList>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::FindContactListsAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->FindContactListsAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactList>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount<D>::FindContactAnnotationListsAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount)->FindContactAnnotationListsAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount2<D>::EnterpriseId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2)->get_EnterpriseId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount2<D>::IsProtectedUnderLock() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2)->get_IsProtectedUnderLock(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount3<D>::ExplictReadAccessPackageFamilyNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3)->get_ExplictReadAccessPackageFamilyNames(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount3<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount3<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::CanShowCreateContactGroup() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->get_CanShowCreateContactGroup(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::CanShowCreateContactGroup(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->put_CanShowCreateContactGroup(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::ProviderProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->get_ProviderProperties(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataTasks::UserDataTaskList>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::FindUserDataTaskListsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->FindUserDataTaskListsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataTasks::UserDataTaskList>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactGroup>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::FindContactGroupsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->FindContactGroupsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactGroup>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::TryShowCreateContactGroupAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->TryShowCreateContactGroupAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::IsProtectedUnderLock(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->put_IsProtectedUnderLock(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccount4<D>::Icon(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4)->put_Icon(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerForUser<D>::RequestStoreAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const& storeAccessType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser)->RequestStoreAsync(static_cast<int32_t>(storeAccessType), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerForUser<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerStatics<D>::RequestStoreAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const& storeAccessType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics)->RequestStoreAsync(static_cast<int32_t>(storeAccessType), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerStatics<D>::ShowAddAccountAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds const& contentKinds) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics)->ShowAddAccountAsync(static_cast<uint32_t>(contentKinds), &result));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerStatics<D>::ShowAccountSettingsAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics)->ShowAccountSettingsAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerStatics<D>::ShowAccountErrorResolverAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics)->ShowAccountErrorResolverAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountManagerStatics2<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2)->GetForUser(*(void**)(&user), &result));
        return llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore<D>::FindAccountsAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore)->FindAccountsAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore<D>::GetAccountAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore)->GetAccountAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore<D>::CreateAccountAsync(param::hstring const& userDisplayName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore)->CreateAccountAsync(*(void**)(&userDisplayName), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore2<D>::CreateAccountAsync(param::hstring const& userDisplayName, param::hstring const& packageRelativeAppId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2)->CreateAccountWithPackageRelativeAppIdAsync(*(void**)(&userDisplayName), *(void**)(&packageRelativeAppId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore2<D>::StoreChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2)->add_StoreChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore2<D>::StoreChanged_revoker consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore2<D>::StoreChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, StoreChanged_revoker>(this, StoreChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore2<D>::StoreChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2)->remove_StoreChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStore3<D>::CreateAccountAsync(param::hstring const& userDisplayName, param::hstring const& packageRelativeAppId, param::hstring const& enterpriseId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3)->CreateAccountWithPackageRelativeAppIdAndEnterpriseIdAsync(*(void**)(&userDisplayName), *(void**)(&packageRelativeAppId), *(void**)(&enterpriseId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_UserDataAccounts_IUserDataAccountStoreChangedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UserDisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserDisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OtherAppReadAccess(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess>(this->shim().OtherAppReadAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OtherAppReadAccess(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(*reinterpret_cast<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Icon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Icon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceAccountTypeId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceAccountTypeId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAppointmentCalendarsAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Appointments::AppointmentCalendar>>>(this->shim().FindAppointmentCalendarsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindEmailMailboxesAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Email::EmailMailbox>>>(this->shim().FindEmailMailboxesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindContactListsAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactList>>>(this->shim().FindContactListsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindContactAnnotationListsAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>>>(this->shim().FindContactAnnotationListsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2>
    {
        int32_t __stdcall get_EnterpriseId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnterpriseId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsProtectedUnderLock(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsProtectedUnderLock());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3>
    {
        int32_t __stdcall get_ExplictReadAccessPackageFamilyNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ExplictReadAccessPackageFamilyNames());
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
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4>
    {
        int32_t __stdcall get_CanShowCreateContactGroup(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanShowCreateContactGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CanShowCreateContactGroup(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanShowCreateContactGroup(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().ProviderProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindUserDataTaskListsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataTasks::UserDataTaskList>>>(this->shim().FindUserDataTaskListsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindContactGroupsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactGroup>>>(this->shim().FindContactGroupsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowCreateContactGroupAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().TryShowCreateContactGroupAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsProtectedUnderLock(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsProtectedUnderLock(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Icon(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Icon(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser>
    {
        int32_t __stdcall RequestStoreAsync(int32_t storeAccessType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>>(this->shim().RequestStoreAsync(*reinterpret_cast<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const*>(&storeAccessType)));
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics>
    {
        int32_t __stdcall RequestStoreAsync(int32_t storeAccessType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore>>(this->shim().RequestStoreAsync(*reinterpret_cast<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const*>(&storeAccessType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAddAccountAsync(uint32_t contentKinds, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().ShowAddAccountAsync(*reinterpret_cast<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds const*>(&contentKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAccountSettingsAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAccountSettingsAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAccountErrorResolverAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAccountErrorResolverAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2>
    {
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore>
    {
        int32_t __stdcall FindAccountsAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>>(this->shim().FindAccountsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccountAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>(this->shim().GetAccountAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAccountAsync(void* userDisplayName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>(this->shim().CreateAccountAsync(*reinterpret_cast<hstring const*>(&userDisplayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2>
    {
        int32_t __stdcall CreateAccountWithPackageRelativeAppIdAsync(void* userDisplayName, void* packageRelativeAppId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>(this->shim().CreateAccountAsync(*reinterpret_cast<hstring const*>(&userDisplayName), *reinterpret_cast<hstring const*>(&packageRelativeAppId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StoreChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StoreChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StoreChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StoreChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3>
    {
        int32_t __stdcall CreateAccountWithPackageRelativeAppIdAndEnterpriseIdAsync(void* userDisplayName, void* packageRelativeAppId, void* enterpriseId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount>>(this->shim().CreateAccountAsync(*reinterpret_cast<hstring const*>(&userDisplayName), *reinterpret_cast<hstring const*>(&packageRelativeAppId), *reinterpret_cast<hstring const*>(&enterpriseId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs>
    {
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts
{
    constexpr auto operator|(UserDataAccountContentKinds const left, UserDataAccountContentKinds const right) noexcept
    {
        return static_cast<UserDataAccountContentKinds>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(UserDataAccountContentKinds& left, UserDataAccountContentKinds const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(UserDataAccountContentKinds const left, UserDataAccountContentKinds const right) noexcept
    {
        return static_cast<UserDataAccountContentKinds>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(UserDataAccountContentKinds& left, UserDataAccountContentKinds const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(UserDataAccountContentKinds const value) noexcept
    {
        return static_cast<UserDataAccountContentKinds>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(UserDataAccountContentKinds const left, UserDataAccountContentKinds const right) noexcept
    {
        return static_cast<UserDataAccountContentKinds>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(UserDataAccountContentKinds& left, UserDataAccountContentKinds const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto UserDataAccountManager::RequestStoreAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const& storeAccessType)
    {
        return impl::call_factory<UserDataAccountManager, IUserDataAccountManagerStatics>([&](IUserDataAccountManagerStatics const& f) { return f.RequestStoreAsync(storeAccessType); });
    }
    inline auto UserDataAccountManager::ShowAddAccountAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds const& contentKinds)
    {
        return impl::call_factory<UserDataAccountManager, IUserDataAccountManagerStatics>([&](IUserDataAccountManagerStatics const& f) { return f.ShowAddAccountAsync(contentKinds); });
    }
    inline auto UserDataAccountManager::ShowAccountSettingsAsync(param::hstring const& id)
    {
        return impl::call_factory<UserDataAccountManager, IUserDataAccountManagerStatics>([&](IUserDataAccountManagerStatics const& f) { return f.ShowAccountSettingsAsync(id); });
    }
    inline auto UserDataAccountManager::ShowAccountErrorResolverAsync(param::hstring const& id)
    {
        return impl::call_factory<UserDataAccountManager, IUserDataAccountManagerStatics>([&](IUserDataAccountManagerStatics const& f) { return f.ShowAccountErrorResolverAsync(id); });
    }
    inline auto UserDataAccountManager::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<UserDataAccountManager, IUserDataAccountManagerStatics2>([&](IUserDataAccountManagerStatics2 const& f) { return f.GetForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccount> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
