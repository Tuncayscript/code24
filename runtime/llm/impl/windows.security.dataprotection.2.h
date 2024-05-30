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
#ifndef LLM_OS_Security_DataProtection_2_H
#define LLM_OS_Security_DataProtection_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Security.DataProtection.1.h"
LLM_EXPORT namespace llm:OS::Security::DataProtection
{
    struct __declspec(empty_bases) UserDataAvailabilityStateChangedEventArgs : llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs
    {
        UserDataAvailabilityStateChangedEventArgs(std::nullptr_t) noexcept {}
        UserDataAvailabilityStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataBufferUnprotectResult : llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult
    {
        UserDataBufferUnprotectResult(std::nullptr_t) noexcept {}
        UserDataBufferUnprotectResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::DataProtection::IUserDataBufferUnprotectResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataProtectionManager : llm:OS::Security::DataProtection::IUserDataProtectionManager
    {
        UserDataProtectionManager(std::nullptr_t) noexcept {}
        UserDataProtectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::DataProtection::IUserDataProtectionManager(ptr, take_ownership_from_abi) {}
        static auto TryGetDefault();
        static auto TryGetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) UserDataStorageItemProtectionInfo : llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo
    {
        UserDataStorageItemProtectionInfo(std::nullptr_t) noexcept {}
        UserDataStorageItemProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::DataProtection::IUserDataStorageItemProtectionInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
