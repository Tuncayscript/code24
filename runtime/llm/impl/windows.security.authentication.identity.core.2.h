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
#ifndef LLM_OS_Security_Authentication_Identity_Core_2_H
#define LLM_OS_Security_Authentication_Identity_Core_2_H
#include "llm/impl/Windows.Security.Authentication.Identity.Core.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Core
{
    struct __declspec(empty_bases) MicrosoftAccountMultiFactorAuthenticationManager : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager
    {
        MicrosoftAccountMultiFactorAuthenticationManager(std::nullptr_t) noexcept {}
        MicrosoftAccountMultiFactorAuthenticationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) MicrosoftAccountMultiFactorGetSessionsResult : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult
    {
        MicrosoftAccountMultiFactorGetSessionsResult(std::nullptr_t) noexcept {}
        MicrosoftAccountMultiFactorGetSessionsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MicrosoftAccountMultiFactorOneTimeCodedInfo : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo
    {
        MicrosoftAccountMultiFactorOneTimeCodedInfo(std::nullptr_t) noexcept {}
        MicrosoftAccountMultiFactorOneTimeCodedInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MicrosoftAccountMultiFactorSessionInfo : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo
    {
        MicrosoftAccountMultiFactorSessionInfo(std::nullptr_t) noexcept {}
        MicrosoftAccountMultiFactorSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
    {
        MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(std::nullptr_t) noexcept {}
        MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
