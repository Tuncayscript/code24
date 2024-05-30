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
#ifndef LLM_OS_Security_Authorization_AppCapabilityAccess_2_H
#define LLM_OS_Security_Authorization_AppCapabilityAccess_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Security.Authorization.AppCapabilityAccess.1.h"
LLM_EXPORT namespace llm:OS::Security::Authorization::AppCapabilityAccess
{
    struct __declspec(empty_bases) AppCapability : llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability,
        impl::require<AppCapability, llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>
    {
        AppCapability(std::nullptr_t) noexcept {}
        AppCapability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability(ptr, take_ownership_from_abi) {}
        static auto RequestAccessForCapabilitiesAsync(param::async_iterable<hstring> const& capabilityNames);
        static auto RequestAccessForCapabilitiesForUserAsync(llm:OS::System::User const& user, param::async_iterable<hstring> const& capabilityNames);
        static auto Create(param::hstring const& capabilityName);
        static auto CreateWithProcessIdForUser(llm:OS::System::User const& user, param::hstring const& capabilityName, uint32_t pid);
    };
    struct __declspec(empty_bases) AppCapabilityAccessChangedEventArgs : llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs
    {
        AppCapabilityAccessChangedEventArgs(std::nullptr_t) noexcept {}
        AppCapabilityAccessChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
