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
#ifndef LLM_OS_ApplicationModel_Contacts_Provider_2_H
#define LLM_OS_ApplicationModel_Contacts_Provider_2_H
#include "llm/impl/Windows.ApplicationModel.Contacts.Provider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts::Provider
{
    struct __declspec(empty_bases) ContactPickerUI : llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI,
        impl::require<ContactPickerUI, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2>
    {
        ContactPickerUI(std::nullptr_t) noexcept {}
        ContactPickerUI(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI::AddContact;
        using impl::consume_t<ContactPickerUI, llm::OS::ApplicationModel::Contacts::Provider::IContactPickerUI2>::AddContact;
    };
    struct __declspec(empty_bases) ContactRemovedEventArgs : llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs
    {
        ContactRemovedEventArgs(std::nullptr_t) noexcept {}
        ContactRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
