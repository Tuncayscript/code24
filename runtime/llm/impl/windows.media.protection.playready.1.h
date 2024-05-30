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
#ifndef LLM_OS_Media_Protection_PlayReady_1_H
#define LLM_OS_Media_Protection_PlayReady_1_H
#include "llm/impl/Windows.Media.Protection.0.h"
#include "llm/impl/Windows.Media.Protection.PlayReady.0.h"
LLM_EXPORT namespace llm:OS::Media::Protection::PlayReady
{
    struct __declspec(empty_bases) INDClient :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDClient>
    {
        INDClient(std::nullptr_t = nullptr) noexcept {}
        INDClient(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDClientFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDClientFactory>
    {
        INDClientFactory(std::nullptr_t = nullptr) noexcept {}
        INDClientFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDClosedCaptionDataReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDClosedCaptionDataReceivedEventArgs>
    {
        INDClosedCaptionDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INDClosedCaptionDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDCustomData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDCustomData>
    {
        INDCustomData(std::nullptr_t = nullptr) noexcept {}
        INDCustomData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDCustomDataFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDCustomDataFactory>
    {
        INDCustomDataFactory(std::nullptr_t = nullptr) noexcept {}
        INDCustomDataFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDDownloadEngine :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDDownloadEngine>
    {
        INDDownloadEngine(std::nullptr_t = nullptr) noexcept {}
        INDDownloadEngine(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDDownloadEngineNotifier :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDDownloadEngineNotifier>
    {
        INDDownloadEngineNotifier(std::nullptr_t = nullptr) noexcept {}
        INDDownloadEngineNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDLicenseFetchCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDLicenseFetchCompletedEventArgs>
    {
        INDLicenseFetchCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INDLicenseFetchCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDLicenseFetchDescriptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDLicenseFetchDescriptor>
    {
        INDLicenseFetchDescriptor(std::nullptr_t = nullptr) noexcept {}
        INDLicenseFetchDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDLicenseFetchDescriptorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDLicenseFetchDescriptorFactory>
    {
        INDLicenseFetchDescriptorFactory(std::nullptr_t = nullptr) noexcept {}
        INDLicenseFetchDescriptorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDLicenseFetchResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDLicenseFetchResult>
    {
        INDLicenseFetchResult(std::nullptr_t = nullptr) noexcept {}
        INDLicenseFetchResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDMessenger :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDMessenger>
    {
        INDMessenger(std::nullptr_t = nullptr) noexcept {}
        INDMessenger(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDProximityDetectionCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDProximityDetectionCompletedEventArgs>
    {
        INDProximityDetectionCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INDProximityDetectionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDRegistrationCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDRegistrationCompletedEventArgs>
    {
        INDRegistrationCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INDRegistrationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDSendResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDSendResult>
    {
        INDSendResult(std::nullptr_t = nullptr) noexcept {}
        INDSendResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDStartResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDStartResult>
    {
        INDStartResult(std::nullptr_t = nullptr) noexcept {}
        INDStartResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDStorageFileHelper :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDStorageFileHelper>
    {
        INDStorageFileHelper(std::nullptr_t = nullptr) noexcept {}
        INDStorageFileHelper(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDStreamParser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDStreamParser>
    {
        INDStreamParser(std::nullptr_t = nullptr) noexcept {}
        INDStreamParser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDStreamParserNotifier :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDStreamParserNotifier>
    {
        INDStreamParserNotifier(std::nullptr_t = nullptr) noexcept {}
        INDStreamParserNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDTCPMessengerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDTCPMessengerFactory>
    {
        INDTCPMessengerFactory(std::nullptr_t = nullptr) noexcept {}
        INDTCPMessengerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INDTransmitterProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INDTransmitterProperties>
    {
        INDTransmitterProperties(std::nullptr_t = nullptr) noexcept {}
        INDTransmitterProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyContentHeader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyContentHeader>
    {
        IPlayReadyContentHeader(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyContentHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyContentHeader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyContentHeader2>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyContentHeader2, llm:OS::Media::Protection::PlayReady::IPlayReadyContentHeader>
    {
        IPlayReadyContentHeader2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyContentHeader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyContentHeaderFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyContentHeaderFactory>
    {
        IPlayReadyContentHeaderFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyContentHeaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyContentHeaderFactory2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyContentHeaderFactory2>
    {
        IPlayReadyContentHeaderFactory2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyContentHeaderFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyContentResolver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyContentResolver>
    {
        IPlayReadyContentResolver(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyContentResolver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyDomain :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyDomain>
    {
        IPlayReadyDomain(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyDomain(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyDomainIterableFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyDomainIterableFactory>
    {
        IPlayReadyDomainIterableFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyDomainIterableFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyDomainJoinServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyDomainJoinServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyDomainJoinServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyDomainJoinServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyDomainJoinServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyDomainLeaveServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyDomainLeaveServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyDomainLeaveServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyDomainLeaveServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyDomainLeaveServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyITADataGenerator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyITADataGenerator>
    {
        IPlayReadyITADataGenerator(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyITADataGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyIndividualizationServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyIndividualizationServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyIndividualizationServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyIndividualizationServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyIndividualizationServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicense :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicense>
    {
        IPlayReadyLicense(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicense(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicense2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicense2>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyLicense2, llm:OS::Media::Protection::PlayReady::IPlayReadyLicense>
    {
        IPlayReadyLicense2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicense2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseAcquisitionServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseAcquisitionServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyLicenseAcquisitionServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseAcquisitionServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseAcquisitionServiceRequest2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseAcquisitionServiceRequest2>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest2, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest>
    {
        IPlayReadyLicenseAcquisitionServiceRequest2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseAcquisitionServiceRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseAcquisitionServiceRequest3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseAcquisitionServiceRequest3>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest3, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseAcquisitionServiceRequest2>
    {
        IPlayReadyLicenseAcquisitionServiceRequest3(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseAcquisitionServiceRequest3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseIterableFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseIterableFactory>
    {
        IPlayReadyLicenseIterableFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseIterableFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseManagement :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseManagement>
    {
        IPlayReadyLicenseManagement(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseManagement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseSession>
    {
        IPlayReadyLicenseSession(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseSession2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseSession2>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseSession2, llm:OS::Media::Protection::PlayReady::IPlayReadyLicenseSession>
    {
        IPlayReadyLicenseSession2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseSession2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyLicenseSessionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyLicenseSessionFactory>
    {
        IPlayReadyLicenseSessionFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyLicenseSessionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyMeteringReportServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyMeteringReportServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyMeteringReportServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyMeteringReportServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyMeteringReportServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyRevocationServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyRevocationServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyRevocationServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadyRevocationServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyRevocationServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadySecureStopIterableFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadySecureStopIterableFactory>
    {
        IPlayReadySecureStopIterableFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadySecureStopIterableFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadySecureStopServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadySecureStopServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadySecureStopServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest, llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest>
    {
        IPlayReadySecureStopServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadySecureStopServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadySecureStopServiceRequestFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadySecureStopServiceRequestFactory>
    {
        IPlayReadySecureStopServiceRequestFactory(std::nullptr_t = nullptr) noexcept {}
        IPlayReadySecureStopServiceRequestFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyServiceRequest>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyServiceRequest, llm:OS::Media::Protection::IMediaProtectionServiceRequest>
    {
        IPlayReadyServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadySoapMessage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadySoapMessage>
    {
        IPlayReadySoapMessage(std::nullptr_t = nullptr) noexcept {}
        IPlayReadySoapMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyStatics>
    {
        IPlayReadyStatics(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyStatics2>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyStatics2, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics>
    {
        IPlayReadyStatics2(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyStatics3>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyStatics3, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics2>
    {
        IPlayReadyStatics3(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyStatics4>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyStatics4, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics2, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics3>
    {
        IPlayReadyStatics4(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlayReadyStatics5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlayReadyStatics5>,
        impl::require<llm:OS::Media::Protection::PlayReady::IPlayReadyStatics5, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics2, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics3, llm:OS::Media::Protection::PlayReady::IPlayReadyStatics4>
    {
        IPlayReadyStatics5(std::nullptr_t = nullptr) noexcept {}
        IPlayReadyStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
