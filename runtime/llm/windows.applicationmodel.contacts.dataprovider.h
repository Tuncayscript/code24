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
#ifndef LLM_OS_ApplicationModel_Contacts_DataProvider_H
#define LLM_OS_ApplicationModel_Contacts_DataProvider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Contacts.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.DataProvider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::SyncRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection)->add_SyncRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::SyncRequested_revoker consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::SyncRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SyncRequested_revoker>(this, SyncRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::SyncRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection)->remove_SyncRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection)->add_ServerSearchReadBatchRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested_revoker consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ServerSearchReadBatchRequested_revoker>(this, ServerSearchReadBatchRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection)->remove_ServerSearchReadBatchRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::CreateOrUpdateContactRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequestEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2)->add_CreateOrUpdateContactRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::CreateOrUpdateContactRequested_revoker consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::CreateOrUpdateContactRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequestEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CreateOrUpdateContactRequested_revoker>(this, CreateOrUpdateContactRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::CreateOrUpdateContactRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2)->remove_CreateOrUpdateContactRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::DeleteContactRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequestEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2)->add_DeleteContactRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::DeleteContactRequested_revoker consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::DeleteContactRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequestEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DeleteContactRequested_revoker>(this, DeleteContactRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderConnection2<D>::DeleteContactRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2)->remove_DeleteContactRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactDataProviderTriggerDetails<D>::Connection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails)->get_Connection(&value));
        return llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequest<D>::ContactListId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest)->get_ContactListId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequest<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequest<D>::ReportCompletedAsync(llm::OS::ApplicationModel::Contacts::Contact const& createdOrUpdatedContact) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest)->ReportCompletedAsync(*(void**)(&createdOrUpdatedContact), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequest<D>::ReportFailedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest)->ReportFailedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequest) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequestEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListCreateOrUpdateContactRequestEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequest<D>::ContactListId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest)->get_ContactListId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequest<D>::ContactId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest)->get_ContactId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequest<D>::ReportCompletedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest)->ReportCompletedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequest<D>::ReportFailedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest)->ReportFailedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequest) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequestEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListDeleteContactRequestEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::SessionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->get_SessionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::ContactListId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->get_ContactListId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQueryOptions) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::Options() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->get_Options(&value));
        return llm::OS::ApplicationModel::Contacts::ContactQueryOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::SuggestedBatchSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->get_SuggestedBatchSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::SaveContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->SaveContactAsync(*(void**)(&contact), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::ReportCompletedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->ReportCompletedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequest<D>::ReportFailedAsync(llm::OS::ApplicationModel::Contacts::ContactBatchStatus const& batchStatus) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest)->ReportFailedAsync(static_cast<int32_t>(batchStatus), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequestEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListServerSearchReadBatchRequestEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListSyncManagerSyncRequest<D>::ContactListId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest)->get_ContactListId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListSyncManagerSyncRequest<D>::ReportCompletedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest)->ReportCompletedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListSyncManagerSyncRequest<D>::ReportFailedAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest)->ReportFailedAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListSyncManagerSyncRequestEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_Contacts_DataProvider_IContactListSyncManagerSyncRequestEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>
    {
        int32_t __stdcall add_SyncRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SyncRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SyncRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ServerSearchReadBatchRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ServerSearchReadBatchRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ServerSearchReadBatchRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerSearchReadBatchRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2>
    {
        int32_t __stdcall add_CreateOrUpdateContactRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CreateOrUpdateContactRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequestEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CreateOrUpdateContactRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateOrUpdateContactRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DeleteContactRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DeleteContactRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequestEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DeleteContactRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteContactRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails>
    {
        int32_t __stdcall get_Connection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection>(this->shim().Connection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest>
    {
        int32_t __stdcall get_ContactListId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactListId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompletedAsync(void* createdOrUpdatedContact, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportCompletedAsync(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::Contact const*>(&createdOrUpdatedContact)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportFailedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportFailedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest>
    {
        int32_t __stdcall get_ContactListId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactListId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContactId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompletedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportCompletedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportFailedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportFailedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>
    {
        int32_t __stdcall get_SessionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SessionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContactListId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactListId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Options(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::ContactQueryOptions>(this->shim().Options());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SuggestedBatchSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SuggestedBatchSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveContactAsync(void* contact, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveContactAsync(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::Contact const*>(&contact)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompletedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportCompletedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportFailedAsync(int32_t batchStatus, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportFailedAsync(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::ContactBatchStatus const*>(&batchStatus)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest>
    {
        int32_t __stdcall get_ContactListId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContactListId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompletedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportCompletedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportFailedAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ReportFailedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs> : produce_base<D, llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts::DataProvider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactDataProviderTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListCreateOrUpdateContactRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListDeleteContactRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
