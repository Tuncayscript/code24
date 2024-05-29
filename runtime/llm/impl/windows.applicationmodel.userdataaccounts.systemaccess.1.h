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
#ifndef LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_1_H
#define LLM_OS_ApplicationModel_UserDataAccounts_SystemAccess_1_H
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.SystemAccess.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataAccounts::SystemAccess
{
    struct __declspec(empty_bases) IDeviceAccountConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccountConfiguration>
    {
        IDeviceAccountConfiguration(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccountConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceAccountConfiguration2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccountConfiguration2>
    {
        IDeviceAccountConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccountConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountSystemAccessManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountSystemAccessManagerStatics>
    {
        IUserDataAccountSystemAccessManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountSystemAccessManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountSystemAccessManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountSystemAccessManagerStatics2>
    {
        IUserDataAccountSystemAccessManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountSystemAccessManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
