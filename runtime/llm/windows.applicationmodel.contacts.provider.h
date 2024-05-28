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
#ifndef LLM_OS_ApplicationModel_Contacts_Provider_H
#define LLM_OS_ApplicationModel_Contacts_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Contacts.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Provider::AddContactResult) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::AddContact(param::hstring const& id, llm::OS::ApplicationModel::Contacts::Contact const& contact) const
    {
        llm::OS::ApplicationModel::Contacts::Provider::AddContactResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->AddContact(*(void**)(&id), *(void**)(&contact), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::RemoveContact(param::hstring const& id) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->RemoveContact(*(void**)(&id)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::ContainsContact(param::hstring const& id) const
    {
        bool isContained{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->ContainsContact(*(void**)(&id), &isContained));
        return isContained;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::DesiredFields() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->get_DesiredFields(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactSelectionMode) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::SelectionMode() const
    {
        llm::OS::ApplicationModel::Contacts::ContactSelectionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->get_SelectionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::ContactRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI, llm::OS::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->add_ContactRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::ContactRemoved_revoker consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::ContactRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI, llm::OS::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ContactRemoved_revoker>(this, ContactRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI<D>::ContactRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI)->remove_ContactRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Provider::AddContactResult) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI2<D>::AddContact(llm::OS::ApplicationModel::Contacts::Contact const& contact) const
    {
        llm::OS::ApplicationModel::Contacts::Provider::AddContactResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2)->AddContact(*(void**)(&contact), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactFieldType>) consume_Windows_ApplicationModel_Contacts_Provider_IContactPickerUI2<D>::DesiredFieldsWithContactFieldType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2)->get_DesiredFieldsWithContactFieldType(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactFieldType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Contacts_Provider_IContactRemovedEventArgs<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI> : produce_base<D, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI>
    {
        int32_t __stdcall AddContact(void* id, void* contact, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Contacts::Provider::AddContactResult>(this->shim().AddContact(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::ApplicationModel::Contacts::Contact const*>(&contact)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveContact(void* id) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveContact(*reinterpret_cast<hstring const*>(&id));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ContainsContact(void* id, bool* isContained) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *isContained = detach_from<bool>(this->shim().ContainsContact(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredFields(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().DesiredFields());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::ContactSelectionMode>(this->shim().SelectionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ContactRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ContactRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI, llm::OS::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ContactRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2> : produce_base<D, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2>
    {
        int32_t __stdcall AddContact(void* contact, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Contacts::Provider::AddContactResult>(this->shim().AddContact(*reinterpret_cast<llm::OS::ApplicationModel::Contacts::Contact const*>(&contact)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredFieldsWithContactFieldType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactFieldType>>(this->shim().DesiredFieldsWithContactFieldType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts::Provider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
