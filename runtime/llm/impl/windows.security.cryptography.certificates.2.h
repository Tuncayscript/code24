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
#ifndef LLM_OS_Security_Cryptography_Certificates_2_H
#define LLM_OS_Security_Cryptography_Certificates_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Security.Cryptography.Certificates.1.h"
LLM_EXPORT namespace llm:OS::Security::Cryptography::Certificates
{
    struct __declspec(empty_bases) Certificate : llm:OS::Security::Cryptography::Certificates::ICertificate,
        impl::require<Certificate, llm:OS::Security::Cryptography::Certificates::ICertificate2, llm:OS::Security::Cryptography::Certificates::ICertificate3>
    {
        Certificate(std::nullptr_t) noexcept {}
        Certificate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificate(ptr, take_ownership_from_abi) {}
        explicit Certificate(llm:OS::Storage::Streams::IBuffer const& certBlob);
    };
    struct __declspec(empty_bases) CertificateChain : llm:OS::Security::Cryptography::Certificates::ICertificateChain
    {
        CertificateChain(std::nullptr_t) noexcept {}
        CertificateChain(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateChain(ptr, take_ownership_from_abi) {}
    };
    struct CertificateEnrollmentManager
    {
        CertificateEnrollmentManager() = delete;
        static auto CreateRequestAsync(llm:OS::Security::Cryptography::Certificates::CertificateRequestProperties const& request);
        static auto InstallCertificateAsync(param::hstring const& certificate, llm:OS::Security::Cryptography::Certificates::InstallOptions const& installOption);
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, llm:OS::Security::Cryptography::Certificates::ExportOption const& exportable, llm:OS::Security::Cryptography::Certificates::KeyProtectionLevel const& keyProtectionLevel, llm:OS::Security::Cryptography::Certificates::InstallOptions const& installOption, param::hstring const& friendlyName);
        [[nodiscard]] static auto UserCertificateEnrollmentManager();
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, llm:OS::Security::Cryptography::Certificates::ExportOption const& exportable, llm:OS::Security::Cryptography::Certificates::KeyProtectionLevel const& keyProtectionLevel, llm:OS::Security::Cryptography::Certificates::InstallOptions const& installOption, param::hstring const& friendlyName, param::hstring const& keyStorageProvider);
        static auto ImportPfxDataAsync(param::hstring const& pfxData, param::hstring const& password, llm:OS::Security::Cryptography::Certificates::PfxImportParameters const& pfxImportParameters);
    };
    struct __declspec(empty_bases) CertificateExtension : llm:OS::Security::Cryptography::Certificates::ICertificateExtension
    {
        CertificateExtension(std::nullptr_t) noexcept {}
        CertificateExtension(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateExtension(ptr, take_ownership_from_abi) {}
        CertificateExtension();
    };
    struct __declspec(empty_bases) CertificateKeyUsages : llm:OS::Security::Cryptography::Certificates::ICertificateKeyUsages
    {
        CertificateKeyUsages(std::nullptr_t) noexcept {}
        CertificateKeyUsages(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateKeyUsages(ptr, take_ownership_from_abi) {}
        CertificateKeyUsages();
    };
    struct __declspec(empty_bases) CertificateQuery : llm:OS::Security::Cryptography::Certificates::ICertificateQuery,
        impl::require<CertificateQuery, llm:OS::Security::Cryptography::Certificates::ICertificateQuery2>
    {
        CertificateQuery(std::nullptr_t) noexcept {}
        CertificateQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateQuery(ptr, take_ownership_from_abi) {}
        CertificateQuery();
    };
    struct __declspec(empty_bases) CertificateRequestProperties : llm:OS::Security::Cryptography::Certificates::ICertificateRequestProperties,
        impl::require<CertificateRequestProperties, llm:OS::Security::Cryptography::Certificates::ICertificateRequestProperties2, llm:OS::Security::Cryptography::Certificates::ICertificateRequestProperties3, llm:OS::Security::Cryptography::Certificates::ICertificateRequestProperties4>
    {
        CertificateRequestProperties(std::nullptr_t) noexcept {}
        CertificateRequestProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateRequestProperties(ptr, take_ownership_from_abi) {}
        CertificateRequestProperties();
    };
    struct __declspec(empty_bases) CertificateStore : llm:OS::Security::Cryptography::Certificates::ICertificateStore,
        impl::require<CertificateStore, llm:OS::Security::Cryptography::Certificates::ICertificateStore2>
    {
        CertificateStore(std::nullptr_t) noexcept {}
        CertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICertificateStore(ptr, take_ownership_from_abi) {}
    };
    struct CertificateStores
    {
        CertificateStores() = delete;
        static auto FindAllAsync();
        static auto FindAllAsync(llm:OS::Security::Cryptography::Certificates::CertificateQuery const& query);
        [[nodiscard]] static auto TrustedRootCertificationAuthorities();
        [[nodiscard]] static auto IntermediateCertificationAuthorities();
        static auto GetStoreByName(param::hstring const& storeName);
        static auto GetUserStoreByName(param::hstring const& storeName);
    };
    struct __declspec(empty_bases) ChainBuildingParameters : llm:OS::Security::Cryptography::Certificates::IChainBuildingParameters
    {
        ChainBuildingParameters(std::nullptr_t) noexcept {}
        ChainBuildingParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::IChainBuildingParameters(ptr, take_ownership_from_abi) {}
        ChainBuildingParameters();
    };
    struct __declspec(empty_bases) ChainValidationParameters : llm:OS::Security::Cryptography::Certificates::IChainValidationParameters
    {
        ChainValidationParameters(std::nullptr_t) noexcept {}
        ChainValidationParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::IChainValidationParameters(ptr, take_ownership_from_abi) {}
        ChainValidationParameters();
    };
    struct __declspec(empty_bases) CmsAttachedSignature : llm:OS::Security::Cryptography::Certificates::ICmsAttachedSignature
    {
        CmsAttachedSignature(std::nullptr_t) noexcept {}
        CmsAttachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICmsAttachedSignature(ptr, take_ownership_from_abi) {}
        explicit CmsAttachedSignature(llm:OS::Storage::Streams::IBuffer const& inputBlob);
        static auto GenerateSignatureAsync(llm:OS::Storage::Streams::IBuffer const& data, param::async_iterable<llm:OS::Security::Cryptography::Certificates::CmsSignerInfo> const& signers, param::async_iterable<llm:OS::Security::Cryptography::Certificates::Certificate> const& certificates);
    };
    struct __declspec(empty_bases) CmsDetachedSignature : llm:OS::Security::Cryptography::Certificates::ICmsDetachedSignature
    {
        CmsDetachedSignature(std::nullptr_t) noexcept {}
        CmsDetachedSignature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICmsDetachedSignature(ptr, take_ownership_from_abi) {}
        explicit CmsDetachedSignature(llm:OS::Storage::Streams::IBuffer const& inputBlob);
        static auto GenerateSignatureAsync(llm:OS::Storage::Streams::IInputStream const& data, param::async_iterable<llm:OS::Security::Cryptography::Certificates::CmsSignerInfo> const& signers, param::async_iterable<llm:OS::Security::Cryptography::Certificates::Certificate> const& certificates);
    };
    struct __declspec(empty_bases) CmsSignerInfo : llm:OS::Security::Cryptography::Certificates::ICmsSignerInfo
    {
        CmsSignerInfo(std::nullptr_t) noexcept {}
        CmsSignerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICmsSignerInfo(ptr, take_ownership_from_abi) {}
        CmsSignerInfo();
    };
    struct __declspec(empty_bases) CmsTimestampInfo : llm:OS::Security::Cryptography::Certificates::ICmsTimestampInfo
    {
        CmsTimestampInfo(std::nullptr_t) noexcept {}
        CmsTimestampInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ICmsTimestampInfo(ptr, take_ownership_from_abi) {}
    };
    struct KeyAlgorithmNames
    {
        KeyAlgorithmNames() = delete;
        [[nodiscard]] static auto Rsa();
        [[nodiscard]] static auto Dsa();
        [[nodiscard]] static auto Ecdh256();
        [[nodiscard]] static auto Ecdh384();
        [[nodiscard]] static auto Ecdh521();
        [[nodiscard]] static auto Ecdsa256();
        [[nodiscard]] static auto Ecdsa384();
        [[nodiscard]] static auto Ecdsa521();
        [[nodiscard]] static auto Ecdsa();
        [[nodiscard]] static auto Ecdh();
    };
    struct KeyAttestationHelper
    {
        KeyAttestationHelper() = delete;
        static auto DecryptTpmAttestationCredentialAsync(param::hstring const& credential);
        static auto GetTpmAttestationCredentialId(param::hstring const& credential);
        static auto DecryptTpmAttestationCredentialAsync(param::hstring const& credential, param::hstring const& containerName);
    };
    struct KeyStorageProviderNames
    {
        KeyStorageProviderNames() = delete;
        [[nodiscard]] static auto SoftwareKeyStorageProvider();
        [[nodiscard]] static auto SmartcardKeyStorageProvider();
        [[nodiscard]] static auto PlatformKeyStorageProvider();
        [[nodiscard]] static auto PassportKeyStorageProvider();
    };
    struct __declspec(empty_bases) PfxImportParameters : llm:OS::Security::Cryptography::Certificates::IPfxImportParameters
    {
        PfxImportParameters(std::nullptr_t) noexcept {}
        PfxImportParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::IPfxImportParameters(ptr, take_ownership_from_abi) {}
        PfxImportParameters();
    };
    struct StandardCertificateStoreNames
    {
        StandardCertificateStoreNames() = delete;
        [[nodiscard]] static auto Personal();
        [[nodiscard]] static auto TrustedRootCertificationAuthorities();
        [[nodiscard]] static auto IntermediateCertificationAuthorities();
    };
    struct __declspec(empty_bases) SubjectAlternativeNameInfo : llm:OS::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,
        impl::require<SubjectAlternativeNameInfo, llm:OS::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2>
    {
        SubjectAlternativeNameInfo(std::nullptr_t) noexcept {}
        SubjectAlternativeNameInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo(ptr, take_ownership_from_abi) {}
        SubjectAlternativeNameInfo();
    };
    struct __declspec(empty_bases) UserCertificateEnrollmentManager : llm:OS::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,
        impl::require<UserCertificateEnrollmentManager, llm:OS::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>
    {
        UserCertificateEnrollmentManager(std::nullptr_t) noexcept {}
        UserCertificateEnrollmentManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager(ptr, take_ownership_from_abi) {}
        using llm:OS::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager::ImportPfxDataAsync;
        using impl::consume_t<UserCertificateEnrollmentManager, llm:OS::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>::ImportPfxDataAsync;
    };
    struct __declspec(empty_bases) UserCertificateStore : llm:OS::Security::Cryptography::Certificates::IUserCertificateStore
    {
        UserCertificateStore(std::nullptr_t) noexcept {}
        UserCertificateStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Cryptography::Certificates::IUserCertificateStore(ptr, take_ownership_from_abi) {}
    };
}
#endif
