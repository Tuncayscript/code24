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
#ifndef LLM_OS_Security_Cryptography_Core_1_H
#define LLM_OS_Security_Cryptography_Core_1_H
#include "llm/impl/Windows.Security.Cryptography.Core.0.h"
LLM_EXPORT namespace llm:OS::Security::Cryptography::Core
{
    struct __declspec(empty_bases) IAsymmetricAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAsymmetricAlgorithmNamesStatics>
    {
        IAsymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IAsymmetricAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAsymmetricAlgorithmNamesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAsymmetricAlgorithmNamesStatics2>
    {
        IAsymmetricAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
        IAsymmetricAlgorithmNamesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAsymmetricKeyAlgorithmProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAsymmetricKeyAlgorithmProvider>
    {
        IAsymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
        IAsymmetricKeyAlgorithmProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAsymmetricKeyAlgorithmProvider2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAsymmetricKeyAlgorithmProvider2>
    {
        IAsymmetricKeyAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
        IAsymmetricKeyAlgorithmProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAsymmetricKeyAlgorithmProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAsymmetricKeyAlgorithmProviderStatics>
    {
        IAsymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IAsymmetricKeyAlgorithmProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICryptographicEngineStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICryptographicEngineStatics>
    {
        ICryptographicEngineStatics(std::nullptr_t = nullptr) noexcept {}
        ICryptographicEngineStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICryptographicEngineStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICryptographicEngineStatics2>
    {
        ICryptographicEngineStatics2(std::nullptr_t = nullptr) noexcept {}
        ICryptographicEngineStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICryptographicKey :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICryptographicKey>
    {
        ICryptographicKey(std::nullptr_t = nullptr) noexcept {}
        ICryptographicKey(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEccCurveNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEccCurveNamesStatics>
    {
        IEccCurveNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IEccCurveNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEncryptedAndAuthenticatedData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEncryptedAndAuthenticatedData>
    {
        IEncryptedAndAuthenticatedData(std::nullptr_t = nullptr) noexcept {}
        IEncryptedAndAuthenticatedData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHashAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHashAlgorithmNamesStatics>
    {
        IHashAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IHashAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHashAlgorithmProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHashAlgorithmProvider>
    {
        IHashAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
        IHashAlgorithmProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHashAlgorithmProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHashAlgorithmProviderStatics>
    {
        IHashAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IHashAlgorithmProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHashComputation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHashComputation>
    {
        IHashComputation(std::nullptr_t = nullptr) noexcept {}
        IHashComputation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationAlgorithmNamesStatics>
    {
        IKeyDerivationAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationAlgorithmNamesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationAlgorithmNamesStatics2>
    {
        IKeyDerivationAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationAlgorithmNamesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationAlgorithmProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationAlgorithmProvider>
    {
        IKeyDerivationAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationAlgorithmProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationAlgorithmProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationAlgorithmProviderStatics>
    {
        IKeyDerivationAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationAlgorithmProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationParameters>
    {
        IKeyDerivationParameters(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationParameters2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationParameters2>
    {
        IKeyDerivationParameters2(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationParameters2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationParametersStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationParametersStatics>
    {
        IKeyDerivationParametersStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationParametersStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyDerivationParametersStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyDerivationParametersStatics2>
    {
        IKeyDerivationParametersStatics2(std::nullptr_t = nullptr) noexcept {}
        IKeyDerivationParametersStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMacAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMacAlgorithmNamesStatics>
    {
        IMacAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IMacAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMacAlgorithmProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMacAlgorithmProvider>
    {
        IMacAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
        IMacAlgorithmProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMacAlgorithmProvider2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMacAlgorithmProvider2>
    {
        IMacAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
        IMacAlgorithmProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMacAlgorithmProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMacAlgorithmProviderStatics>
    {
        IMacAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IMacAlgorithmProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPersistedKeyProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPersistedKeyProviderStatics>
    {
        IPersistedKeyProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IPersistedKeyProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISymmetricAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISymmetricAlgorithmNamesStatics>
    {
        ISymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        ISymmetricAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISymmetricKeyAlgorithmProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISymmetricKeyAlgorithmProvider>
    {
        ISymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
        ISymmetricKeyAlgorithmProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISymmetricKeyAlgorithmProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISymmetricKeyAlgorithmProviderStatics>
    {
        ISymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
        ISymmetricKeyAlgorithmProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
