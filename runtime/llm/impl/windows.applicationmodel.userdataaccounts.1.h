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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_1_H
#define LLM_OS_ApplicationModel_UserDataAccounts_1_H
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts
{
    struct __declspec(empty_bases) IUserDataAccount :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccount>
    {
        IUserDataAccount(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccount2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccount2>,
        impl::require<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount2, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccount>
    {
        IUserDataAccount2(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccount2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccount3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccount3>
    {
        IUserDataAccount3(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccount3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccount4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccount4>
    {
        IUserDataAccount4(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccount4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountManagerForUser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountManagerForUser>
    {
        IUserDataAccountManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountManagerStatics>
    {
        IUserDataAccountManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountManagerStatics2>
    {
        IUserDataAccountManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountStore>
    {
        IUserDataAccountStore(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountStore2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountStore2>,
        impl::require<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore2, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore>
    {
        IUserDataAccountStore2(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IUserDataAccountStore2, IUserDataAccountStore2>::CreateAccountAsync;
        using impl::consume_t<IUserDataAccountStore2, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore>::CreateAccountAsync;
    };
    struct __declspec(empty_bases) IUserDataAccountStore3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountStore3>,
        impl::require<llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore3, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore>
    {
        IUserDataAccountStore3(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountStore3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IUserDataAccountStore3, IUserDataAccountStore3>::CreateAccountAsync;
        using impl::consume_t<IUserDataAccountStore3, llm::OS::ApplicationModel::UserDataAccounts::IUserDataAccountStore>::CreateAccountAsync;
    };
    struct __declspec(empty_bases) IUserDataAccountStoreChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountStoreChangedEventArgs>
    {
        IUserDataAccountStoreChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountStoreChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
