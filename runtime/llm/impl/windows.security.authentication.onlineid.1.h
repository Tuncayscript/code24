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
#ifndef LLM_OS_Security_Authentication_OnlineId_1_H
#define LLM_OS_Security_Authentication_OnlineId_1_H
#include "llm/impl/Windows.Security.Authentication.OnlineId.0.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::OnlineId
{
    struct __declspec(empty_bases) IOnlineIdAuthenticator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdAuthenticator>
    {
        IOnlineIdAuthenticator(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdAuthenticator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdServiceTicket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdServiceTicket>
    {
        IOnlineIdServiceTicket(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdServiceTicket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdServiceTicketRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdServiceTicketRequest>
    {
        IOnlineIdServiceTicketRequest(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdServiceTicketRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdServiceTicketRequestFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdServiceTicketRequestFactory>
    {
        IOnlineIdServiceTicketRequestFactory(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdServiceTicketRequestFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdSystemAuthenticatorForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdSystemAuthenticatorForUser>
    {
        IOnlineIdSystemAuthenticatorForUser(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdSystemAuthenticatorForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdSystemAuthenticatorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdSystemAuthenticatorStatics>
    {
        IOnlineIdSystemAuthenticatorStatics(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdSystemAuthenticatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdSystemIdentity :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdSystemIdentity>
    {
        IOnlineIdSystemIdentity(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdSystemIdentity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOnlineIdSystemTicketResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOnlineIdSystemTicketResult>
    {
        IOnlineIdSystemTicketResult(std::nullptr_t = nullptr) noexcept {}
        IOnlineIdSystemTicketResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserIdentity :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserIdentity>
    {
        IUserIdentity(std::nullptr_t = nullptr) noexcept {}
        IUserIdentity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
