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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_2_H
#define LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.SystemAccess.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts::SystemAccess
{
    struct __declspec(empty_bases) DeviceAccountConfiguration : llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration,
        impl::require<DeviceAccountConfiguration, llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>
    {
        DeviceAccountConfiguration(std::nullptr_t) noexcept {}
        DeviceAccountConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration(ptr, take_ownership_from_abi) {}
        DeviceAccountConfiguration();
    };
    struct UserDataAccountSystemAccessManager
    {
        UserDataAccountSystemAccessManager() = delete;
        static auto AddAndShowDeviceAccountsAsync(param::async_iterable<llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> const& accounts);
        static auto SuppressLocalAccountWithAccountAsync(param::hstring const& userDataAccountId);
        static auto CreateDeviceAccountAsync(llm::OS::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration const& account);
        static auto DeleteDeviceAccountAsync(param::hstring const& accountId);
        static auto GetDeviceAccountConfigurationAsync(param::hstring const& accountId);
    };
}
#endif
