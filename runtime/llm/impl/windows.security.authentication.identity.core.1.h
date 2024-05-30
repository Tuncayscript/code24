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
#ifndef LLM_OS_Security_Authentication_Identity_Core_1_H
#define LLM_OS_Security_Authentication_Identity_Core_1_H
#include "llm/impl/Windows.Security.Authentication.Identity.Core.0.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Core
{
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorAuthenticationManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorAuthenticationManager>
    {
        IMicrosoftAccountMultiFactorAuthenticationManager(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorAuthenticationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorAuthenticatorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorAuthenticatorStatics>
    {
        IMicrosoftAccountMultiFactorAuthenticatorStatics(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorAuthenticatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorGetSessionsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorGetSessionsResult>
    {
        IMicrosoftAccountMultiFactorGetSessionsResult(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorGetSessionsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorOneTimeCodedInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorOneTimeCodedInfo>
    {
        IMicrosoftAccountMultiFactorOneTimeCodedInfo(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorOneTimeCodedInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorSessionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorSessionInfo>
    {
        IMicrosoftAccountMultiFactorSessionInfo(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
    {
        IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(std::nullptr_t = nullptr) noexcept {}
        IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
