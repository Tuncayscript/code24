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
#ifndef LLM_OS_Security_Credentials_1_H
#define LLM_OS_Security_Credentials_1_H
#include "llm/impl/Windows.Security.Credentials.0.h"
LLM_EXPORT namespace llm:OS::Security::Credentials
{
    struct __declspec(empty_bases) ICredentialFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialFactory>
    {
        ICredentialFactory(std::nullptr_t = nullptr) noexcept {}
        ICredentialFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyCredential :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyCredential>
    {
        IKeyCredential(std::nullptr_t = nullptr) noexcept {}
        IKeyCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyCredentialAttestationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyCredentialAttestationResult>
    {
        IKeyCredentialAttestationResult(std::nullptr_t = nullptr) noexcept {}
        IKeyCredentialAttestationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyCredentialManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyCredentialManagerStatics>
    {
        IKeyCredentialManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyCredentialManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyCredentialOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyCredentialOperationResult>
    {
        IKeyCredentialOperationResult(std::nullptr_t = nullptr) noexcept {}
        IKeyCredentialOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyCredentialRetrievalResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyCredentialRetrievalResult>
    {
        IKeyCredentialRetrievalResult(std::nullptr_t = nullptr) noexcept {}
        IKeyCredentialRetrievalResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPasswordCredential :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPasswordCredential>
    {
        IPasswordCredential(std::nullptr_t = nullptr) noexcept {}
        IPasswordCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPasswordVault :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPasswordVault>
    {
        IPasswordVault(std::nullptr_t = nullptr) noexcept {}
        IPasswordVault(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccount :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccount>
    {
        IWebAccount(std::nullptr_t = nullptr) noexcept {}
        IWebAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccount2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccount2>,
        impl::require<llm:OS::Security::Credentials::IWebAccount2, llm:OS::Security::Credentials::IWebAccount>
    {
        IWebAccount2(std::nullptr_t = nullptr) noexcept {}
        IWebAccount2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountFactory>
    {
        IWebAccountFactory(std::nullptr_t = nullptr) noexcept {}
        IWebAccountFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProvider>
    {
        IWebAccountProvider(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProvider2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProvider2>,
        impl::require<llm:OS::Security::Credentials::IWebAccountProvider2, llm:OS::Security::Credentials::IWebAccountProvider>
    {
        IWebAccountProvider2(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProvider3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProvider3>,
        impl::require<llm:OS::Security::Credentials::IWebAccountProvider3, llm:OS::Security::Credentials::IWebAccountProvider, llm:OS::Security::Credentials::IWebAccountProvider2>
    {
        IWebAccountProvider3(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProvider3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProvider4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProvider4>
    {
        IWebAccountProvider4(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProvider4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderFactory>
    {
        IWebAccountProviderFactory(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
