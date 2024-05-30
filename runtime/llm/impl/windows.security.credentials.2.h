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
#ifndef LLM_OS_Security_Credentials_2_H
#define LLM_OS_Security_Credentials_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
LLM_EXPORT namespace llm:OS::Security::Credentials
{
    struct __declspec(empty_bases) KeyCredential : llm:OS::Security::Credentials::IKeyCredential
    {
        KeyCredential(std::nullptr_t) noexcept {}
        KeyCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IKeyCredential(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyCredentialAttestationResult : llm:OS::Security::Credentials::IKeyCredentialAttestationResult
    {
        KeyCredentialAttestationResult(std::nullptr_t) noexcept {}
        KeyCredentialAttestationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IKeyCredentialAttestationResult(ptr, take_ownership_from_abi) {}
    };
    struct KeyCredentialManager
    {
        KeyCredentialManager() = delete;
        static auto IsSupportedAsync();
        static auto RenewAttestationAsync();
        static auto RequestCreateAsync(param::hstring const& name, llm:OS::Security::Credentials::KeyCredentialCreationOption const& option);
        static auto OpenAsync(param::hstring const& name);
        static auto DeleteAsync(param::hstring const& name);
    };
    struct __declspec(empty_bases) KeyCredentialOperationResult : llm:OS::Security::Credentials::IKeyCredentialOperationResult
    {
        KeyCredentialOperationResult(std::nullptr_t) noexcept {}
        KeyCredentialOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IKeyCredentialOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyCredentialRetrievalResult : llm:OS::Security::Credentials::IKeyCredentialRetrievalResult
    {
        KeyCredentialRetrievalResult(std::nullptr_t) noexcept {}
        KeyCredentialRetrievalResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IKeyCredentialRetrievalResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PasswordCredential : llm:OS::Security::Credentials::IPasswordCredential
    {
        PasswordCredential(std::nullptr_t) noexcept {}
        PasswordCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IPasswordCredential(ptr, take_ownership_from_abi) {}
        PasswordCredential();
        PasswordCredential(param::hstring const& resource, param::hstring const& userName, param::hstring const& password);
    };
    struct __declspec(empty_bases) PasswordCredentialPropertyStore : llm:OS::Foundation::Collections::IPropertySet
    {
        PasswordCredentialPropertyStore(std::nullptr_t) noexcept {}
        PasswordCredentialPropertyStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IPropertySet(ptr, take_ownership_from_abi) {}
        PasswordCredentialPropertyStore();
    };
    struct __declspec(empty_bases) PasswordVault : llm:OS::Security::Credentials::IPasswordVault
    {
        PasswordVault(std::nullptr_t) noexcept {}
        PasswordVault(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IPasswordVault(ptr, take_ownership_from_abi) {}
        PasswordVault();
    };
    struct __declspec(empty_bases) WebAccount : llm:OS::Security::Credentials::IWebAccount,
        impl::require<WebAccount, llm:OS::Security::Credentials::IWebAccount2>
    {
        WebAccount(std::nullptr_t) noexcept {}
        WebAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IWebAccount(ptr, take_ownership_from_abi) {}
        WebAccount(llm:OS::Security::Credentials::WebAccountProvider const& webAccountProvider, param::hstring const& userName, llm:OS::Security::Credentials::WebAccountState const& state);
    };
    struct __declspec(empty_bases) WebAccountProvider : llm:OS::Security::Credentials::IWebAccountProvider,
        impl::require<WebAccountProvider, llm:OS::Security::Credentials::IWebAccountProvider2, llm:OS::Security::Credentials::IWebAccountProvider3, llm:OS::Security::Credentials::IWebAccountProvider4>
    {
        WebAccountProvider(std::nullptr_t) noexcept {}
        WebAccountProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::IWebAccountProvider(ptr, take_ownership_from_abi) {}
        WebAccountProvider(param::hstring const& id, param::hstring const& displayName, llm:OS::Foundation::Uri const& iconUri);
    };
}
#endif
