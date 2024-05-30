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
#ifndef LLM_OS_Media_Protection_PlayReady_2_H
#define LLM_OS_Media_Protection_PlayReady_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Media.Protection.1.h"
#include "llm/impl/Windows.Media.Protection.PlayReady.1.h"
LLM_EXPORT namespace llm:OS::Media::Protection::PlayReady
{
    struct __declspec(empty_bases) NDClient : llm:OS::Media::Protection::PlayReady::INDClient
    {
        NDClient(std::nullptr_t) noexcept {}
        NDClient(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDClient(ptr, take_ownership_from_abi) {}
        NDClient(llm:OS::Media::Protection::PlayReady::INDDownloadEngine const& downloadEngine, llm:OS::Media::Protection::PlayReady::INDStreamParser const& streamParser, llm:OS::Media::Protection::PlayReady::INDMessenger const& pMessenger);
    };
    struct __declspec(empty_bases) NDCustomData : llm:OS::Media::Protection::PlayReady::INDCustomData
    {
        NDCustomData(std::nullptr_t) noexcept {}
        NDCustomData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDCustomData(ptr, take_ownership_from_abi) {}
        NDCustomData(array_view<uint8_t const> customDataTypeIDBytes, array_view<uint8_t const> customDataBytes);
    };
    struct __declspec(empty_bases) NDDownloadEngineNotifier : llm:OS::Media::Protection::PlayReady::INDDownloadEngineNotifier
    {
        NDDownloadEngineNotifier(std::nullptr_t) noexcept {}
        NDDownloadEngineNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDDownloadEngineNotifier(ptr, take_ownership_from_abi) {}
        NDDownloadEngineNotifier();
    };
    struct __declspec(empty_bases) NDLicenseFetchDescriptor : llm:OS::Media::Protection::PlayReady::INDLicenseFetchDescriptor
    {
        NDLicenseFetchDescriptor(std::nullptr_t) noexcept {}
        NDLicenseFetchDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDLicenseFetchDescriptor(ptr, take_ownership_from_abi) {}
        NDLicenseFetchDescriptor(llm:OS::Media::Protection::PlayReady::NDContentIDType const& contentIDType, array_view<uint8_t const> contentIDBytes, llm:OS::Media::Protection::PlayReady::INDCustomData const& licenseFetchChallengeCustomData);
    };
    struct __declspec(empty_bases) NDStorageFileHelper : llm:OS::Media::Protection::PlayReady::INDStorageFileHelper
    {
        NDStorageFileHelper(std::nullptr_t) noexcept {}
        NDStorageFileHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDStorageFileHelper(ptr, take_ownership_from_abi) {}
        NDStorageFileHelper();
    };
    struct __declspec(empty_bases) NDStreamParserNotifier : llm:OS::Media::Protection::PlayReady::INDStreamParserNotifier
    {
        NDStreamParserNotifier(std::nullptr_t) noexcept {}
        NDStreamParserNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDStreamParserNotifier(ptr, take_ownership_from_abi) {}
        NDStreamParserNotifier();
    };
    struct __declspec(empty_bases) NDTCPMessenger : llm:OS::Media::Protection::PlayReady::INDMessenger
    {
        NDTCPMessenger(std::nullptr_t) noexcept {}
        NDTCPMessenger(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::INDMessenger(ptr, take_ownership_from_abi) {}
        NDTCPMessenger(param::hstring const& remoteHostName, uint32_t remoteHostPort);
    };
    struct __declspec(empty_bases) PlayReadyContentHeader : llm:OS::Media::Protection::PlayReady::IPlayReadyContentHeader,
        impl::require<PlayReadyContentHeader, llm:OS::Media::Protection::PlayReady::IPlayReadyContentHeader2>
    {
        PlayReadyContentHeader(std::nullptr_t) noexcept {}
        PlayReadyContentHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyContentHeader(ptr, take_ownership_from_abi) {}
        PlayReadyContentHeader(array_view<uint8_t const> headerBytes, llm:OS::Foundation::Uri const& licenseAcquisitionUrl, llm:OS::Foundation::Uri const& licenseAcquisitionUserInterfaceUrl, param::hstring const& customAttributes, llm::guid const& domainServiceId);
        PlayReadyContentHeader(llm::guid const& contentKeyId, param::hstring const& contentKeyIdString, llm:OS::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm const& contentEncryptionAlgorithm, llm:OS::Foundation::Uri const& licenseAcquisitionUrl, llm:OS::Foundation::Uri const& licenseAcquisitionUserInterfaceUrl, param::hstring const& customAttributes, llm::guid const& domainServiceId);
        explicit PlayReadyContentHeader(array_view<uint8_t const> headerBytes);
        PlayReadyContentHeader(uint32_t dwFlags, array_view<llm::guid const> contentKeyIds, array_view<hstring const> contentKeyIdStrings, llm:OS::Media::Protection::PlayReady::PlayReadyEncryptionAlgorithm const& contentEncryptionAlgorithm, llm:OS::Foundation::Uri const& licenseAcquisitionUrl, llm:OS::Foundation::Uri const& licenseAcquisitionUserInterfaceUrl, param::hstring const& customAttributes, llm::guid const& domainServiceId);
    };
    struct PlayReadyContentResolver
    {
        PlayReadyContentResolver() = delete;
        static auto ServiceRequest(llm:OS::Media::Protection::PlayReady::PlayReadyContentHeader const& contentHeader);
    };
    struct __declspec(empty_bases) PlayReadyDomain : llm:OS::Media::Protection::PlayReady::IPlayReadyDomain
    {
        PlayReadyDomain(std::nullptr_t) noexcept {}
        PlayReadyDomain(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyDomain(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayReadyDomainIterable : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadyDomain>
    {
        PlayReadyDomainIterable(std::nullptr_t) noexcept {}
        PlayReadyDomainIterable(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadyDomain>(ptr, take_ownership_from_abi) {}
        explicit PlayReadyDomainIterable(llm::guid const& domainAccountId);
    };
    struct __declspec(empty_bases) PlayReadyDomainIterator : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadyDomain>
    {
        PlayReadyDomainIterator(std::nullptr_t) noexcept {}
        PlayReadyDomainIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadyDomain>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayReadyDomainJoinServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest
    {
        PlayReadyDomainJoinServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyDomainJoinServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyDomainJoinServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadyDomainLeaveServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest
    {
        PlayReadyDomainLeaveServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyDomainLeaveServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyDomainLeaveServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadyITADataGenerator : llm:OS::Media::Protection::PlayReady::IPlayReadyITADataGenerator
    {
        PlayReadyITADataGenerator(std::nullptr_t) noexcept {}
        PlayReadyITADataGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyITADataGenerator(ptr, take_ownership_from_abi) {}
        PlayReadyITADataGenerator();
    };
    struct __declspec(empty_bases) PlayReadyIndividualizationServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyIndividualizationServiceRequest
    {
        PlayReadyIndividualizationServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyIndividualizationServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyIndividualizationServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyIndividualizationServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadyLicense : llm:OS::Media::Protection::PlayReady::IPlayReadyLicense,
        impl::require<PlayReadyLicense, llm:OS::Media::Protection::PlayReady::IPlayReadyLicense2>
    {
        PlayReadyLicense(std::nullptr_t) noexcept {}
        PlayReadyLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyLicense(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayReadyLicenseAcquisitionServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest,
        impl::require<PlayReadyLicenseAcquisitionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest2, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest3>
    {
        PlayReadyLicenseAcquisitionServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyLicenseAcquisitionServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyLicenseAcquisitionServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadyLicenseIterable : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadyLicense>
    {
        PlayReadyLicenseIterable(std::nullptr_t) noexcept {}
        PlayReadyLicenseIterable(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadyLicense>(ptr, take_ownership_from_abi) {}
        PlayReadyLicenseIterable();
        PlayReadyLicenseIterable(llm:OS::Media::Protection::PlayReady::PlayReadyContentHeader const& contentHeader, bool fullyEvaluated);
    };
    struct __declspec(empty_bases) PlayReadyLicenseIterator : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadyLicense>
    {
        PlayReadyLicenseIterator(std::nullptr_t) noexcept {}
        PlayReadyLicenseIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadyLicense>(ptr, take_ownership_from_abi) {}
    };
    struct PlayReadyLicenseManagement
    {
        PlayReadyLicenseManagement() = delete;
        static auto DeleteLicenses(llm:OS::Media::Protection::PlayReady::PlayReadyContentHeader const& contentHeader);
    };
    struct __declspec(empty_bases) PlayReadyLicenseSession : llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseSession,
        impl::require<PlayReadyLicenseSession, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseSession2>
    {
        PlayReadyLicenseSession(std::nullptr_t) noexcept {}
        PlayReadyLicenseSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseSession(ptr, take_ownership_from_abi) {}
        explicit PlayReadyLicenseSession(llm:OS::Foundation::Collections::IPropertySet const& configuration);
    };
    struct __declspec(empty_bases) PlayReadyMeteringReportServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest
    {
        PlayReadyMeteringReportServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyMeteringReportServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyMeteringReportServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadyRevocationServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadyRevocationServiceRequest
    {
        PlayReadyRevocationServiceRequest(std::nullptr_t) noexcept {}
        PlayReadyRevocationServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadyRevocationServiceRequest(ptr, take_ownership_from_abi) {}
        PlayReadyRevocationServiceRequest();
    };
    struct __declspec(empty_bases) PlayReadySecureStopIterable : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>
    {
        PlayReadySecureStopIterable(std::nullptr_t) noexcept {}
        PlayReadySecureStopIterable(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterable<llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(ptr, take_ownership_from_abi) {}
        explicit PlayReadySecureStopIterable(array_view<uint8_t const> publisherCertBytes);
    };
    struct __declspec(empty_bases) PlayReadySecureStopIterator : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>
    {
        PlayReadySecureStopIterator(std::nullptr_t) noexcept {}
        PlayReadySecureStopIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IIterator<llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlayReadySecureStopServiceRequest : llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest
    {
        PlayReadySecureStopServiceRequest(std::nullptr_t) noexcept {}
        PlayReadySecureStopServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest(ptr, take_ownership_from_abi) {}
        explicit PlayReadySecureStopServiceRequest(array_view<uint8_t const> publisherCertBytes);
        PlayReadySecureStopServiceRequest(llm::guid const& sessionID, array_view<uint8_t const> publisherCertBytes);
    };
    struct __declspec(empty_bases) PlayReadySoapMessage : llm:OS::Media::Protection::PlayReady::IPlayReadySoapMessage
    {
        PlayReadySoapMessage(std::nullptr_t) noexcept {}
        PlayReadySoapMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::PlayReady::IPlayReadySoapMessage(ptr, take_ownership_from_abi) {}
    };
    struct PlayReadyStatics
    {
        PlayReadyStatics() = delete;
        [[nodiscard]] static auto DomainJoinServiceRequestType();
        [[nodiscard]] static auto DomainLeaveServiceRequestType();
        [[nodiscard]] static auto IndividualizationServiceRequestType();
        [[nodiscard]] static auto LicenseAcquirerServiceRequestType();
        [[nodiscard]] static auto MeteringReportServiceRequestType();
        [[nodiscard]] static auto RevocationServiceRequestType();
        [[nodiscard]] static auto MediaProtectionSystemId();
        [[nodiscard]] static auto PlayReadySecurityVersion();
        [[nodiscard]] static auto PlayReadyCertificateSecurityLevel();
        [[nodiscard]] static auto SecureStopServiceRequestType();
        static auto CheckSupportedHardware(llm:OS::Media::Protection::PlayReady::PlayReadyHardwareDRMFeatures const& hwdrmFeature);
        [[nodiscard]] static auto InputTrustAuthorityToCreate();
        [[nodiscard]] static auto ProtectionSystemId();
        [[nodiscard]] static auto HardwareDRMDisabledAtTime();
        [[nodiscard]] static auto HardwareDRMDisabledUntilTime();
        static auto ResetHardwareDRMDisabled();
    };
}
#endif
