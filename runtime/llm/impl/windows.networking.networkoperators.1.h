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
#ifndef LLM_OS_Networking_NetworkOperators_1_H
#define LLM_OS_Networking_NetworkOperators_1_H
#include "llm/impl/Windows.Networking.NetworkOperators.0.h"
LLM_EXPORT namespace llm:OS::Networking::NetworkOperators
{
    struct __declspec(empty_bases) IESim :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESim>
    {
        IESim(std::nullptr_t = nullptr) noexcept {}
        IESim(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESim2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESim2>
    {
        IESim2(std::nullptr_t = nullptr) noexcept {}
        IESim2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESim3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESim3>
    {
        IESim3(std::nullptr_t = nullptr) noexcept {}
        IESim3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimAddedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimAddedEventArgs>
    {
        IESimAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IESimAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimDiscoverEvent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimDiscoverEvent>
    {
        IESimDiscoverEvent(std::nullptr_t = nullptr) noexcept {}
        IESimDiscoverEvent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimDiscoverResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimDiscoverResult>
    {
        IESimDiscoverResult(std::nullptr_t = nullptr) noexcept {}
        IESimDiscoverResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimDownloadProfileMetadataResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimDownloadProfileMetadataResult>
    {
        IESimDownloadProfileMetadataResult(std::nullptr_t = nullptr) noexcept {}
        IESimDownloadProfileMetadataResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimManagerStatics>
    {
        IESimManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IESimManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimOperationResult>
    {
        IESimOperationResult(std::nullptr_t = nullptr) noexcept {}
        IESimOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimPolicy :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimPolicy>
    {
        IESimPolicy(std::nullptr_t = nullptr) noexcept {}
        IESimPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimProfile>
    {
        IESimProfile(std::nullptr_t = nullptr) noexcept {}
        IESimProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimProfileMetadata :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimProfileMetadata>
    {
        IESimProfileMetadata(std::nullptr_t = nullptr) noexcept {}
        IESimProfileMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimProfilePolicy :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimProfilePolicy>
    {
        IESimProfilePolicy(std::nullptr_t = nullptr) noexcept {}
        IESimProfilePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimRemovedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimRemovedEventArgs>
    {
        IESimRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IESimRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimServiceInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimServiceInfo>
    {
        IESimServiceInfo(std::nullptr_t = nullptr) noexcept {}
        IESimServiceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimUpdatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimUpdatedEventArgs>
    {
        IESimUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IESimUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IESimWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IESimWatcher>
    {
        IESimWatcher(std::nullptr_t = nullptr) noexcept {}
        IESimWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFdnAccessManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFdnAccessManagerStatics>
    {
        IFdnAccessManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IFdnAccessManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHotspotAuthenticationContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHotspotAuthenticationContext>
    {
        IHotspotAuthenticationContext(std::nullptr_t = nullptr) noexcept {}
        IHotspotAuthenticationContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHotspotAuthenticationContext2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHotspotAuthenticationContext2>
    {
        IHotspotAuthenticationContext2(std::nullptr_t = nullptr) noexcept {}
        IHotspotAuthenticationContext2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHotspotAuthenticationContextStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHotspotAuthenticationContextStatics>
    {
        IHotspotAuthenticationContextStatics(std::nullptr_t = nullptr) noexcept {}
        IHotspotAuthenticationContextStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHotspotAuthenticationEventDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHotspotAuthenticationEventDetails>
    {
        IHotspotAuthenticationEventDetails(std::nullptr_t = nullptr) noexcept {}
        IHotspotAuthenticationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHotspotCredentialsAuthenticationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHotspotCredentialsAuthenticationResult>
    {
        IHotspotCredentialsAuthenticationResult(std::nullptr_t = nullptr) noexcept {}
        IHotspotCredentialsAuthenticationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownCSimFilePathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownCSimFilePathsStatics>
    {
        IKnownCSimFilePathsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownCSimFilePathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownRuimFilePathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownRuimFilePathsStatics>
    {
        IKnownRuimFilePathsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownRuimFilePathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownSimFilePathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownSimFilePathsStatics>
    {
        IKnownSimFilePathsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownSimFilePathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownUSimFilePathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownUSimFilePathsStatics>
    {
        IKnownUSimFilePathsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownUSimFilePathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccount :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccount>
    {
        IMobileBroadbandAccount(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccount2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccount2>
    {
        IMobileBroadbandAccount2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccount2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccount3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccount3>
    {
        IMobileBroadbandAccount3(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccount3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccountEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccountEventArgs>
    {
        IMobileBroadbandAccountEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccountEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccountStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccountStatics>
    {
        IMobileBroadbandAccountStatics(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccountStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccountUpdatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccountUpdatedEventArgs>
    {
        IMobileBroadbandAccountUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccountUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAccountWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAccountWatcher>
    {
        IMobileBroadbandAccountWatcher(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAccountWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAntennaSar :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAntennaSar>
    {
        IMobileBroadbandAntennaSar(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAntennaSar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandAntennaSarFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandAntennaSarFactory>
    {
        IMobileBroadbandAntennaSarFactory(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandAntennaSarFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellCdma :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellCdma>
    {
        IMobileBroadbandCellCdma(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellCdma(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellGsm :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellGsm>
    {
        IMobileBroadbandCellGsm(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellGsm(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellLte :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellLte>
    {
        IMobileBroadbandCellLte(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellLte(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellNR :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellNR>
    {
        IMobileBroadbandCellNR(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellNR(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellTdscdma :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellTdscdma>
    {
        IMobileBroadbandCellTdscdma(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellTdscdma(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellUmts :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellUmts>
    {
        IMobileBroadbandCellUmts(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellUmts(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellsInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellsInfo>
    {
        IMobileBroadbandCellsInfo(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellsInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCellsInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCellsInfo2>
    {
        IMobileBroadbandCellsInfo2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCellsInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandCurrentSlotIndexChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandCurrentSlotIndexChangedEventArgs>
    {
        IMobileBroadbandCurrentSlotIndexChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandCurrentSlotIndexChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceInformation>
    {
        IMobileBroadbandDeviceInformation(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceInformation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceInformation2>
    {
        IMobileBroadbandDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceInformation3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceInformation3>
    {
        IMobileBroadbandDeviceInformation3(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceInformation3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceInformation4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceInformation4>
    {
        IMobileBroadbandDeviceInformation4(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceInformation4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceService :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceService>
    {
        IMobileBroadbandDeviceService(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceCommandResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceCommandResult>
    {
        IMobileBroadbandDeviceServiceCommandResult(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceCommandResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceCommandSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceCommandSession>
    {
        IMobileBroadbandDeviceServiceCommandSession(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceCommandSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceDataReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceDataReceivedEventArgs>
    {
        IMobileBroadbandDeviceServiceDataReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceDataSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceDataSession>
    {
        IMobileBroadbandDeviceServiceDataSession(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceDataSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceInformation>
    {
        IMobileBroadbandDeviceServiceInformation(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceTriggerDetails>
    {
        IMobileBroadbandDeviceServiceTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandDeviceServiceTriggerDetails2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandDeviceServiceTriggerDetails2>
    {
        IMobileBroadbandDeviceServiceTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandDeviceServiceTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModem>
    {
        IMobileBroadbandModem(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModem2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModem2>
    {
        IMobileBroadbandModem2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModem2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModem3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModem3>
    {
        IMobileBroadbandModem3(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModem3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModem4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModem4>
    {
        IMobileBroadbandModem4(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModem4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModemConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModemConfiguration>
    {
        IMobileBroadbandModemConfiguration(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModemConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModemConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModemConfiguration2>
    {
        IMobileBroadbandModemConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModemConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModemIsolation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModemIsolation>
    {
        IMobileBroadbandModemIsolation(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModemIsolation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModemIsolationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModemIsolationFactory>
    {
        IMobileBroadbandModemIsolationFactory(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModemIsolationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandModemStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandModemStatics>
    {
        IMobileBroadbandModemStatics(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandModemStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandNetwork :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandNetwork>
    {
        IMobileBroadbandNetwork(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandNetwork2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandNetwork2>
    {
        IMobileBroadbandNetwork2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandNetwork2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandNetwork3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandNetwork3>
    {
        IMobileBroadbandNetwork3(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandNetwork3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandNetworkRegistrationStateChange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandNetworkRegistrationStateChange>
    {
        IMobileBroadbandNetworkRegistrationStateChange(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandNetworkRegistrationStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails>
    {
        IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPco :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPco>
    {
        IMobileBroadbandPco(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPco(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPcoDataChangeTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPcoDataChangeTriggerDetails>
    {
        IMobileBroadbandPcoDataChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPcoDataChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPin :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPin>
    {
        IMobileBroadbandPin(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPin(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPinLockStateChange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPinLockStateChange>
    {
        IMobileBroadbandPinLockStateChange(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPinLockStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPinLockStateChangeTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPinLockStateChangeTriggerDetails>
    {
        IMobileBroadbandPinLockStateChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPinLockStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPinManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPinManager>
    {
        IMobileBroadbandPinManager(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPinManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandPinOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandPinOperationResult>
    {
        IMobileBroadbandPinOperationResult(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandPinOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandRadioStateChange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandRadioStateChange>
    {
        IMobileBroadbandRadioStateChange(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandRadioStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandRadioStateChangeTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandRadioStateChangeTriggerDetails>
    {
        IMobileBroadbandRadioStateChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandRadioStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandSarManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandSarManager>
    {
        IMobileBroadbandSarManager(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandSarManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandSlotInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandSlotInfo>
    {
        IMobileBroadbandSlotInfo(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandSlotInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandSlotInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandSlotInfo2>
    {
        IMobileBroadbandSlotInfo2(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandSlotInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandSlotInfoChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandSlotInfoChangedEventArgs>
    {
        IMobileBroadbandSlotInfoChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandSlotInfoChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandSlotManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandSlotManager>
    {
        IMobileBroadbandSlotManager(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandSlotManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandTransmissionStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandTransmissionStateChangedEventArgs>
    {
        IMobileBroadbandTransmissionStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandTransmissionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandUicc :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandUicc>
    {
        IMobileBroadbandUicc(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandUicc(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandUiccApp :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandUiccApp>
    {
        IMobileBroadbandUiccApp(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandUiccApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandUiccAppReadRecordResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandUiccAppReadRecordResult>
    {
        IMobileBroadbandUiccAppReadRecordResult(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandUiccAppReadRecordResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandUiccAppRecordDetailsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandUiccAppRecordDetailsResult>
    {
        IMobileBroadbandUiccAppRecordDetailsResult(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandUiccAppRecordDetailsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMobileBroadbandUiccAppsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMobileBroadbandUiccAppsResult>
    {
        IMobileBroadbandUiccAppsResult(std::nullptr_t = nullptr) noexcept {}
        IMobileBroadbandUiccAppsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorDataUsageTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorDataUsageTriggerDetails>
    {
        INetworkOperatorDataUsageTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorDataUsageTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorNotificationEventDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorNotificationEventDetails>
    {
        INetworkOperatorNotificationEventDetails(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorNotificationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringAccessPointConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringAccessPointConfiguration>
    {
        INetworkOperatorTetheringAccessPointConfiguration(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringAccessPointConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringAccessPointConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringAccessPointConfiguration2>
    {
        INetworkOperatorTetheringAccessPointConfiguration2(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringAccessPointConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringClient :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringClient>
    {
        INetworkOperatorTetheringClient(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringClient(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringClientManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringClientManager>
    {
        INetworkOperatorTetheringClientManager(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringClientManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringEntitlementCheck :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringEntitlementCheck>
    {
        INetworkOperatorTetheringEntitlementCheck(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringEntitlementCheck(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringManager>
    {
        INetworkOperatorTetheringManager(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringManagerStatics>
    {
        INetworkOperatorTetheringManagerStatics(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringManagerStatics2>
    {
        INetworkOperatorTetheringManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringManagerStatics3>
    {
        INetworkOperatorTetheringManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringManagerStatics4>
    {
        INetworkOperatorTetheringManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorTetheringOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorTetheringOperationResult>
    {
        INetworkOperatorTetheringOperationResult(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorTetheringOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProvisionFromXmlDocumentResults :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProvisionFromXmlDocumentResults>
    {
        IProvisionFromXmlDocumentResults(std::nullptr_t = nullptr) noexcept {}
        IProvisionFromXmlDocumentResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProvisionedProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProvisionedProfile>
    {
        IProvisionedProfile(std::nullptr_t = nullptr) noexcept {}
        IProvisionedProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProvisioningAgent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProvisioningAgent>
    {
        IProvisioningAgent(std::nullptr_t = nullptr) noexcept {}
        IProvisioningAgent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProvisioningAgentStaticMethods :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProvisioningAgentStaticMethods>
    {
        IProvisioningAgentStaticMethods(std::nullptr_t = nullptr) noexcept {}
        IProvisioningAgentStaticMethods(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITetheringEntitlementCheckTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITetheringEntitlementCheckTriggerDetails>
    {
        ITetheringEntitlementCheckTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ITetheringEntitlementCheckTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUssdMessage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUssdMessage>
    {
        IUssdMessage(std::nullptr_t = nullptr) noexcept {}
        IUssdMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUssdMessageFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUssdMessageFactory>
    {
        IUssdMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IUssdMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUssdReply :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUssdReply>
    {
        IUssdReply(std::nullptr_t = nullptr) noexcept {}
        IUssdReply(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUssdSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUssdSession>
    {
        IUssdSession(std::nullptr_t = nullptr) noexcept {}
        IUssdSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUssdSessionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUssdSessionStatics>
    {
        IUssdSessionStatics(std::nullptr_t = nullptr) noexcept {}
        IUssdSessionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
