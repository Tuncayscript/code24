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
#ifndef LLM_OS_Security_Cryptography_Certificates_1_H
#define LLM_OS_Security_Cryptography_Certificates_1_H
#include "llm/impl/Windows.Security.Cryptography.Certificates.0.h"
LLM_EXPORT namespace llm:OS::Security::Cryptography::Certificates
{
    struct __declspec(empty_bases) ICertificate :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificate>
    {
        ICertificate(std::nullptr_t = nullptr) noexcept {}
        ICertificate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificate2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificate2>
    {
        ICertificate2(std::nullptr_t = nullptr) noexcept {}
        ICertificate2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificate3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificate3>
    {
        ICertificate3(std::nullptr_t = nullptr) noexcept {}
        ICertificate3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateChain :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateChain>
    {
        ICertificateChain(std::nullptr_t = nullptr) noexcept {}
        ICertificateChain(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateEnrollmentManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateEnrollmentManagerStatics>
    {
        ICertificateEnrollmentManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICertificateEnrollmentManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateEnrollmentManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateEnrollmentManagerStatics2>
    {
        ICertificateEnrollmentManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        ICertificateEnrollmentManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateEnrollmentManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateEnrollmentManagerStatics3>
    {
        ICertificateEnrollmentManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        ICertificateEnrollmentManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateExtension :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateExtension>
    {
        ICertificateExtension(std::nullptr_t = nullptr) noexcept {}
        ICertificateExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateFactory>
    {
        ICertificateFactory(std::nullptr_t = nullptr) noexcept {}
        ICertificateFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateKeyUsages :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateKeyUsages>
    {
        ICertificateKeyUsages(std::nullptr_t = nullptr) noexcept {}
        ICertificateKeyUsages(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateQuery :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateQuery>
    {
        ICertificateQuery(std::nullptr_t = nullptr) noexcept {}
        ICertificateQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateQuery2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateQuery2>
    {
        ICertificateQuery2(std::nullptr_t = nullptr) noexcept {}
        ICertificateQuery2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateRequestProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateRequestProperties>
    {
        ICertificateRequestProperties(std::nullptr_t = nullptr) noexcept {}
        ICertificateRequestProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateRequestProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateRequestProperties2>
    {
        ICertificateRequestProperties2(std::nullptr_t = nullptr) noexcept {}
        ICertificateRequestProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateRequestProperties3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateRequestProperties3>
    {
        ICertificateRequestProperties3(std::nullptr_t = nullptr) noexcept {}
        ICertificateRequestProperties3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateRequestProperties4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateRequestProperties4>
    {
        ICertificateRequestProperties4(std::nullptr_t = nullptr) noexcept {}
        ICertificateRequestProperties4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateStore :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateStore>
    {
        ICertificateStore(std::nullptr_t = nullptr) noexcept {}
        ICertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateStore2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateStore2>
    {
        ICertificateStore2(std::nullptr_t = nullptr) noexcept {}
        ICertificateStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateStoresStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateStoresStatics>
    {
        ICertificateStoresStatics(std::nullptr_t = nullptr) noexcept {}
        ICertificateStoresStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICertificateStoresStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICertificateStoresStatics2>
    {
        ICertificateStoresStatics2(std::nullptr_t = nullptr) noexcept {}
        ICertificateStoresStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IChainBuildingParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IChainBuildingParameters>
    {
        IChainBuildingParameters(std::nullptr_t = nullptr) noexcept {}
        IChainBuildingParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IChainValidationParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IChainValidationParameters>
    {
        IChainValidationParameters(std::nullptr_t = nullptr) noexcept {}
        IChainValidationParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsAttachedSignature :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsAttachedSignature>
    {
        ICmsAttachedSignature(std::nullptr_t = nullptr) noexcept {}
        ICmsAttachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsAttachedSignatureFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsAttachedSignatureFactory>
    {
        ICmsAttachedSignatureFactory(std::nullptr_t = nullptr) noexcept {}
        ICmsAttachedSignatureFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsAttachedSignatureStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsAttachedSignatureStatics>
    {
        ICmsAttachedSignatureStatics(std::nullptr_t = nullptr) noexcept {}
        ICmsAttachedSignatureStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsDetachedSignature :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsDetachedSignature>
    {
        ICmsDetachedSignature(std::nullptr_t = nullptr) noexcept {}
        ICmsDetachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsDetachedSignatureFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsDetachedSignatureFactory>
    {
        ICmsDetachedSignatureFactory(std::nullptr_t = nullptr) noexcept {}
        ICmsDetachedSignatureFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsDetachedSignatureStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsDetachedSignatureStatics>
    {
        ICmsDetachedSignatureStatics(std::nullptr_t = nullptr) noexcept {}
        ICmsDetachedSignatureStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsSignerInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsSignerInfo>
    {
        ICmsSignerInfo(std::nullptr_t = nullptr) noexcept {}
        ICmsSignerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICmsTimestampInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICmsTimestampInfo>
    {
        ICmsTimestampInfo(std::nullptr_t = nullptr) noexcept {}
        ICmsTimestampInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyAlgorithmNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyAlgorithmNamesStatics>
    {
        IKeyAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyAlgorithmNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyAlgorithmNamesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyAlgorithmNamesStatics2>
    {
        IKeyAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
        IKeyAlgorithmNamesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyAttestationHelperStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyAttestationHelperStatics>
    {
        IKeyAttestationHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyAttestationHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyAttestationHelperStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyAttestationHelperStatics2>
    {
        IKeyAttestationHelperStatics2(std::nullptr_t = nullptr) noexcept {}
        IKeyAttestationHelperStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyStorageProviderNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyStorageProviderNamesStatics>
    {
        IKeyStorageProviderNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyStorageProviderNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyStorageProviderNamesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyStorageProviderNamesStatics2>
    {
        IKeyStorageProviderNamesStatics2(std::nullptr_t = nullptr) noexcept {}
        IKeyStorageProviderNamesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPfxImportParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPfxImportParameters>
    {
        IPfxImportParameters(std::nullptr_t = nullptr) noexcept {}
        IPfxImportParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStandardCertificateStoreNamesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStandardCertificateStoreNamesStatics>
    {
        IStandardCertificateStoreNamesStatics(std::nullptr_t = nullptr) noexcept {}
        IStandardCertificateStoreNamesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISubjectAlternativeNameInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISubjectAlternativeNameInfo>
    {
        ISubjectAlternativeNameInfo(std::nullptr_t = nullptr) noexcept {}
        ISubjectAlternativeNameInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISubjectAlternativeNameInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISubjectAlternativeNameInfo2>
    {
        ISubjectAlternativeNameInfo2(std::nullptr_t = nullptr) noexcept {}
        ISubjectAlternativeNameInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserCertificateEnrollmentManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserCertificateEnrollmentManager>
    {
        IUserCertificateEnrollmentManager(std::nullptr_t = nullptr) noexcept {}
        IUserCertificateEnrollmentManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserCertificateEnrollmentManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserCertificateEnrollmentManager2>
    {
        IUserCertificateEnrollmentManager2(std::nullptr_t = nullptr) noexcept {}
        IUserCertificateEnrollmentManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserCertificateStore :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserCertificateStore>
    {
        IUserCertificateStore(std::nullptr_t = nullptr) noexcept {}
        IUserCertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
