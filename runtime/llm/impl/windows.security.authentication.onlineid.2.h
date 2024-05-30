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
#ifndef LLM_OS_Security_Authentication_OnlineId_2_H
#define LLM_OS_Security_Authentication_OnlineId_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Security.Authentication.OnlineId.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::OnlineId
{
    struct __declspec(empty_bases) OnlineIdAuthenticator : llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator
    {
        OnlineIdAuthenticator(std::nullptr_t) noexcept {}
        OnlineIdAuthenticator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdAuthenticator(ptr, take_ownership_from_abi) {}
        OnlineIdAuthenticator();
    };
    struct __declspec(empty_bases) OnlineIdServiceTicket : llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket
    {
        OnlineIdServiceTicket(std::nullptr_t) noexcept {}
        OnlineIdServiceTicket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicket(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OnlineIdServiceTicketRequest : llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest
    {
        OnlineIdServiceTicketRequest(std::nullptr_t) noexcept {}
        OnlineIdServiceTicketRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest(ptr, take_ownership_from_abi) {}
        OnlineIdServiceTicketRequest(param::hstring const& service, param::hstring const& policy);
        explicit OnlineIdServiceTicketRequest(param::hstring const& service);
    };
    struct OnlineIdSystemAuthenticator
    {
        OnlineIdSystemAuthenticator() = delete;
        [[nodiscard]] static auto Default();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) OnlineIdSystemAuthenticatorForUser : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser
    {
        OnlineIdSystemAuthenticatorForUser(std::nullptr_t) noexcept {}
        OnlineIdSystemAuthenticatorForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemAuthenticatorForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OnlineIdSystemIdentity : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity
    {
        OnlineIdSystemIdentity(std::nullptr_t) noexcept {}
        OnlineIdSystemIdentity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemIdentity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OnlineIdSystemTicketResult : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult
    {
        OnlineIdSystemTicketResult(std::nullptr_t) noexcept {}
        OnlineIdSystemTicketResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IOnlineIdSystemTicketResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SignOutUserOperation : llm:OS::Foundation::IAsyncAction
    {
        SignOutUserOperation(std::nullptr_t) noexcept {}
        SignOutUserOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IAsyncAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserAuthenticationOperation : llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::OnlineId::UserIdentity>
    {
        UserAuthenticationOperation(std::nullptr_t) noexcept {}
        UserAuthenticationOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::OnlineId::UserIdentity>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserIdentity : llm:OS::Security::Authentication::OnlineId::IUserIdentity
    {
        UserIdentity(std::nullptr_t) noexcept {}
        UserIdentity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::OnlineId::IUserIdentity(ptr, take_ownership_from_abi) {}
    };
}
#endif
