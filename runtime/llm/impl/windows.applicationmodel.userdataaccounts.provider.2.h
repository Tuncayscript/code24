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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_Provider_2_H
#define LLM_OS_ApplicationModel_UserDataAccounts_Provider_2_H
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.Provider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts::Provider
{
    struct __declspec(empty_bases) UserDataAccountPartnerAccountInfo : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo
    {
        UserDataAccountPartnerAccountInfo(std::nullptr_t) noexcept {}
        UserDataAccountPartnerAccountInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataAccountProviderAddAccountOperation : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation
    {
        UserDataAccountProviderAddAccountOperation(std::nullptr_t) noexcept {}
        UserDataAccountProviderAddAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataAccountProviderResolveErrorsOperation : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation
    {
        UserDataAccountProviderResolveErrorsOperation(std::nullptr_t) noexcept {}
        UserDataAccountProviderResolveErrorsOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataAccountProviderSettingsOperation : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation
    {
        UserDataAccountProviderSettingsOperation(std::nullptr_t) noexcept {}
        UserDataAccountProviderSettingsOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
