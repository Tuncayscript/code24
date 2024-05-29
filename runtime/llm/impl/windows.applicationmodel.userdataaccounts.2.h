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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_2_H
#define LLM_OS_ApplicationModel_UserDataAccounts_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts
{
    struct __declspec(empty_bases) UserDataAccount : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount,
        impl::require<UserDataAccount, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount3, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4>
    {
        UserDataAccount(std::nullptr_t) noexcept {}
        UserDataAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount::Icon;
        using impl::consume_t<UserDataAccount, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4>::Icon;
        using impl::consume_t<UserDataAccount, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2>::IsProtectedUnderLock;
        using impl::consume_t<UserDataAccount, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount4>::IsProtectedUnderLock;
    };
    struct UserDataAccountManager
    {
        UserDataAccountManager() = delete;
        static auto RequestStoreAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType const& storeAccessType);
        static auto ShowAddAccountAsync(llm::OS::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds const& contentKinds);
        static auto ShowAccountSettingsAsync(param::hstring const& id);
        static auto ShowAccountErrorResolverAsync(param::hstring const& id);
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) UserDataAccountManagerForUser : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser
    {
        UserDataAccountManagerForUser(std::nullptr_t) noexcept {}
        UserDataAccountManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataAccountStore : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore,
        impl::require<UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3>
    {
        UserDataAccountStore(std::nullptr_t) noexcept {}
        UserDataAccountStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore::CreateAccountAsync;
        using impl::consume_t<UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2>::CreateAccountAsync;
        using impl::consume_t<UserDataAccountStore, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3>::CreateAccountAsync;
    };
    struct __declspec(empty_bases) UserDataAccountStoreChangedEventArgs : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs
    {
        UserDataAccountStoreChangedEventArgs(std::nullptr_t) noexcept {}
        UserDataAccountStoreChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
