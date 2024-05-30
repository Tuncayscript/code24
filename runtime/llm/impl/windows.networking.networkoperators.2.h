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
#ifndef LLM_OS_Networking_NetworkOperators_2_H
#define LLM_OS_Networking_NetworkOperators_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Networking.Connectivity.2.h"
#include "llm/impl/Windows.Networking.NetworkOperators.1.h"
LLM_EXPORT namespace llm:OS::Networking::NetworkOperators
{
    struct ESimProfileInstallProgress
    {
        int32_t TotalSizeInBytes;
        int32_t InstalledSizeInBytes;
    };
    inline bool operator==(ESimProfileInstallProgress const& left, ESimProfileInstallProgress const& right) noexcept
    {
        return left.TotalSizeInBytes == right.TotalSizeInBytes && left.InstalledSizeInBytes == right.InstalledSizeInBytes;
    }
    inline bool operator!=(ESimProfileInstallProgress const& left, ESimProfileInstallProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct ProfileUsage
    {
        uint32_t UsageInMegabytes;
        llm:OS::Foundation::DateTime LastSyncTime;
    };
    inline bool operator==(ProfileUsage const& left, ProfileUsage const& right) noexcept
    {
        return left.UsageInMegabytes == right.UsageInMegabytes && left.LastSyncTime == right.LastSyncTime;
    }
    inline bool operator!=(ProfileUsage const& left, ProfileUsage const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ESim : llm:OS::Networking::NetworkOperators::IESim,
        impl::require<ESim, llm:OS::Networking::NetworkOperators::IESim2, llm:OS::Networking::NetworkOperators::IESim3>
    {
        ESim(std::nullptr_t) noexcept {}
        ESim(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESim(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimAddedEventArgs : llm:OS::Networking::NetworkOperators::IESimAddedEventArgs
    {
        ESimAddedEventArgs(std::nullptr_t) noexcept {}
        ESimAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimDiscoverEvent : llm:OS::Networking::NetworkOperators::IESimDiscoverEvent
    {
        ESimDiscoverEvent(std::nullptr_t) noexcept {}
        ESimDiscoverEvent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimDiscoverEvent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimDiscoverResult : llm:OS::Networking::NetworkOperators::IESimDiscoverResult
    {
        ESimDiscoverResult(std::nullptr_t) noexcept {}
        ESimDiscoverResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimDiscoverResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimDownloadProfileMetadataResult : llm:OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult
    {
        ESimDownloadProfileMetadataResult(std::nullptr_t) noexcept {}
        ESimDownloadProfileMetadataResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult(ptr, take_ownership_from_abi) {}
    };
    struct ESimManager
    {
        ESimManager() = delete;
        [[nodiscard]] static auto ServiceInfo();
        static auto TryCreateESimWatcher();
        static auto ServiceInfoChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using ServiceInfoChanged_revoker = impl::factory_event_revoker<llm:OS::Networking::NetworkOperators::IESimManagerStatics, &impl::abi_t<llm:OS::Networking::NetworkOperators::IESimManagerStatics>::remove_ServiceInfoChanged>;
        [[nodiscard]] static ServiceInfoChanged_revoker ServiceInfoChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto ServiceInfoChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) ESimOperationResult : llm:OS::Networking::NetworkOperators::IESimOperationResult
    {
        ESimOperationResult(std::nullptr_t) noexcept {}
        ESimOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimPolicy : llm:OS::Networking::NetworkOperators::IESimPolicy
    {
        ESimPolicy(std::nullptr_t) noexcept {}
        ESimPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimPolicy(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimProfile : llm:OS::Networking::NetworkOperators::IESimProfile
    {
        ESimProfile(std::nullptr_t) noexcept {}
        ESimProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimProfile(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimProfileMetadata : llm:OS::Networking::NetworkOperators::IESimProfileMetadata
    {
        ESimProfileMetadata(std::nullptr_t) noexcept {}
        ESimProfileMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimProfileMetadata(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimProfilePolicy : llm:OS::Networking::NetworkOperators::IESimProfilePolicy
    {
        ESimProfilePolicy(std::nullptr_t) noexcept {}
        ESimProfilePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimProfilePolicy(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimRemovedEventArgs : llm:OS::Networking::NetworkOperators::IESimRemovedEventArgs
    {
        ESimRemovedEventArgs(std::nullptr_t) noexcept {}
        ESimRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimServiceInfo : llm:OS::Networking::NetworkOperators::IESimServiceInfo
    {
        ESimServiceInfo(std::nullptr_t) noexcept {}
        ESimServiceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimServiceInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimUpdatedEventArgs : llm:OS::Networking::NetworkOperators::IESimUpdatedEventArgs
    {
        ESimUpdatedEventArgs(std::nullptr_t) noexcept {}
        ESimUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ESimWatcher : llm:OS::Networking::NetworkOperators::IESimWatcher
    {
        ESimWatcher(std::nullptr_t) noexcept {}
        ESimWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IESimWatcher(ptr, take_ownership_from_abi) {}
    };
    struct FdnAccessManager
    {
        FdnAccessManager() = delete;
        static auto RequestUnlockAsync(param::hstring const& contactListId);
    };
    struct __declspec(empty_bases) HotspotAuthenticationContext : llm:OS::Networking::NetworkOperators::IHotspotAuthenticationContext,
        impl::require<HotspotAuthenticationContext, llm:OS::Networking::NetworkOperators::IHotspotAuthenticationContext2>
    {
        HotspotAuthenticationContext(std::nullptr_t) noexcept {}
        HotspotAuthenticationContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IHotspotAuthenticationContext(ptr, take_ownership_from_abi) {}
        static auto TryGetAuthenticationContext(param::hstring const& evenToken, llm:OS::Networking::NetworkOperators::HotspotAuthenticationContext& context);
    };
    struct __declspec(empty_bases) HotspotAuthenticationEventDetails : llm:OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails
    {
        HotspotAuthenticationEventDetails(std::nullptr_t) noexcept {}
        HotspotAuthenticationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HotspotCredentialsAuthenticationResult : llm:OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult
    {
        HotspotCredentialsAuthenticationResult(std::nullptr_t) noexcept {}
        HotspotCredentialsAuthenticationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult(ptr, take_ownership_from_abi) {}
    };
    struct KnownCSimFilePaths
    {
        KnownCSimFilePaths() = delete;
        [[nodiscard]] static auto EFSpn();
        [[nodiscard]] static auto Gid1();
        [[nodiscard]] static auto Gid2();
    };
    struct KnownRuimFilePaths
    {
        KnownRuimFilePaths() = delete;
        [[nodiscard]] static auto EFSpn();
        [[nodiscard]] static auto Gid1();
        [[nodiscard]] static auto Gid2();
    };
    struct KnownSimFilePaths
    {
        KnownSimFilePaths() = delete;
        [[nodiscard]] static auto EFOns();
        [[nodiscard]] static auto EFSpn();
        [[nodiscard]] static auto Gid1();
        [[nodiscard]] static auto Gid2();
    };
    struct KnownUSimFilePaths
    {
        KnownUSimFilePaths() = delete;
        [[nodiscard]] static auto EFSpn();
        [[nodiscard]] static auto EFOpl();
        [[nodiscard]] static auto EFPnn();
        [[nodiscard]] static auto Gid1();
        [[nodiscard]] static auto Gid2();
    };
    struct __declspec(empty_bases) MobileBroadbandAccount : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccount,
        impl::require<MobileBroadbandAccount, llm:OS::Networking::NetworkOperators::IMobileBroadbandAccount2, llm:OS::Networking::NetworkOperators::IMobileBroadbandAccount3>
    {
        MobileBroadbandAccount(std::nullptr_t) noexcept {}
        MobileBroadbandAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccount(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AvailableNetworkAccountIds();
        static auto CreateFromNetworkAccountId(param::hstring const& networkAccountId);
    };
    struct __declspec(empty_bases) MobileBroadbandAccountEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs
    {
        MobileBroadbandAccountEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandAccountEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandAccountUpdatedEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs
    {
        MobileBroadbandAccountUpdatedEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandAccountUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandAccountWatcher : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher
    {
        MobileBroadbandAccountWatcher(std::nullptr_t) noexcept {}
        MobileBroadbandAccountWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher(ptr, take_ownership_from_abi) {}
        MobileBroadbandAccountWatcher();
    };
    struct __declspec(empty_bases) MobileBroadbandAntennaSar : llm:OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar
    {
        MobileBroadbandAntennaSar(std::nullptr_t) noexcept {}
        MobileBroadbandAntennaSar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar(ptr, take_ownership_from_abi) {}
        MobileBroadbandAntennaSar(int32_t antennaIndex, int32_t sarBackoffIndex);
    };
    struct __declspec(empty_bases) MobileBroadbandCellCdma : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellCdma
    {
        MobileBroadbandCellCdma(std::nullptr_t) noexcept {}
        MobileBroadbandCellCdma(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellCdma(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellGsm : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellGsm
    {
        MobileBroadbandCellGsm(std::nullptr_t) noexcept {}
        MobileBroadbandCellGsm(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellGsm(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellLte : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellLte
    {
        MobileBroadbandCellLte(std::nullptr_t) noexcept {}
        MobileBroadbandCellLte(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellLte(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellNR : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellNR
    {
        MobileBroadbandCellNR(std::nullptr_t) noexcept {}
        MobileBroadbandCellNR(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellNR(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellTdscdma : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma
    {
        MobileBroadbandCellTdscdma(std::nullptr_t) noexcept {}
        MobileBroadbandCellTdscdma(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellUmts : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellUmts
    {
        MobileBroadbandCellUmts(std::nullptr_t) noexcept {}
        MobileBroadbandCellUmts(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellUmts(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCellsInfo : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo,
        impl::require<MobileBroadbandCellsInfo, llm:OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2>
    {
        MobileBroadbandCellsInfo(std::nullptr_t) noexcept {}
        MobileBroadbandCellsInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandCurrentSlotIndexChangedEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs
    {
        MobileBroadbandCurrentSlotIndexChangedEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandCurrentSlotIndexChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceInformation : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation,
        impl::require<MobileBroadbandDeviceInformation, llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2, llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3, llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation4>
    {
        MobileBroadbandDeviceInformation(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceService : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceService
    {
        MobileBroadbandDeviceService(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceService(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceCommandResult : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult
    {
        MobileBroadbandDeviceServiceCommandResult(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceCommandResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceCommandSession : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession
    {
        MobileBroadbandDeviceServiceCommandSession(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceCommandSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceDataReceivedEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs
    {
        MobileBroadbandDeviceServiceDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceDataSession : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession
    {
        MobileBroadbandDeviceServiceDataSession(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceDataSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceInformation : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation
    {
        MobileBroadbandDeviceServiceInformation(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceTriggerDetails : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails,
        impl::require<MobileBroadbandDeviceServiceTriggerDetails, llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails2>
    {
        MobileBroadbandDeviceServiceTriggerDetails(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandModem : llm:OS::Networking::NetworkOperators::IMobileBroadbandModem,
        impl::require<MobileBroadbandModem, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem2, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem3, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem4>
    {
        MobileBroadbandModem(std::nullptr_t) noexcept {}
        MobileBroadbandModem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandModem(ptr, take_ownership_from_abi) {}
        using impl::consume_t<MobileBroadbandModem, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem2>::GetIsPassthroughEnabledAsync;
        using impl::consume_t<MobileBroadbandModem, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem4>::GetIsPassthroughEnabledAsync;
        using impl::consume_t<MobileBroadbandModem, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem2>::SetIsPassthroughEnabledAsync;
        using impl::consume_t<MobileBroadbandModem, llm:OS::Networking::NetworkOperators::IMobileBroadbandModem4>::SetIsPassthroughEnabledAsync;
        static auto GetDeviceSelector();
        static auto FromId(param::hstring const& deviceId);
        static auto GetDefault();
    };
    struct __declspec(empty_bases) MobileBroadbandModemConfiguration : llm:OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration,
        impl::require<MobileBroadbandModemConfiguration, llm:OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration2>
    {
        MobileBroadbandModemConfiguration(std::nullptr_t) noexcept {}
        MobileBroadbandModemConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandModemIsolation : llm:OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation
    {
        MobileBroadbandModemIsolation(std::nullptr_t) noexcept {}
        MobileBroadbandModemIsolation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation(ptr, take_ownership_from_abi) {}
        MobileBroadbandModemIsolation(param::hstring const& modemDeviceId, param::hstring const& ruleGroupId);
    };
    struct __declspec(empty_bases) MobileBroadbandNetwork : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetwork,
        impl::require<MobileBroadbandNetwork, llm:OS::Networking::NetworkOperators::IMobileBroadbandNetwork2, llm:OS::Networking::NetworkOperators::IMobileBroadbandNetwork3>
    {
        MobileBroadbandNetwork(std::nullptr_t) noexcept {}
        MobileBroadbandNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetwork(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandNetworkRegistrationStateChange : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange
    {
        MobileBroadbandNetworkRegistrationStateChange(std::nullptr_t) noexcept {}
        MobileBroadbandNetworkRegistrationStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandNetworkRegistrationStateChangeTriggerDetails : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails
    {
        MobileBroadbandNetworkRegistrationStateChangeTriggerDetails(std::nullptr_t) noexcept {}
        MobileBroadbandNetworkRegistrationStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPco : llm:OS::Networking::NetworkOperators::IMobileBroadbandPco
    {
        MobileBroadbandPco(std::nullptr_t) noexcept {}
        MobileBroadbandPco(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPco(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPcoDataChangeTriggerDetails : llm:OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails
    {
        MobileBroadbandPcoDataChangeTriggerDetails(std::nullptr_t) noexcept {}
        MobileBroadbandPcoDataChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPin : llm:OS::Networking::NetworkOperators::IMobileBroadbandPin
    {
        MobileBroadbandPin(std::nullptr_t) noexcept {}
        MobileBroadbandPin(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPin(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPinLockStateChange : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange
    {
        MobileBroadbandPinLockStateChange(std::nullptr_t) noexcept {}
        MobileBroadbandPinLockStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPinLockStateChangeTriggerDetails : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails
    {
        MobileBroadbandPinLockStateChangeTriggerDetails(std::nullptr_t) noexcept {}
        MobileBroadbandPinLockStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPinManager : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinManager
    {
        MobileBroadbandPinManager(std::nullptr_t) noexcept {}
        MobileBroadbandPinManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandPinOperationResult : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult
    {
        MobileBroadbandPinOperationResult(std::nullptr_t) noexcept {}
        MobileBroadbandPinOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandRadioStateChange : llm:OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange
    {
        MobileBroadbandRadioStateChange(std::nullptr_t) noexcept {}
        MobileBroadbandRadioStateChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandRadioStateChangeTriggerDetails : llm:OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails
    {
        MobileBroadbandRadioStateChangeTriggerDetails(std::nullptr_t) noexcept {}
        MobileBroadbandRadioStateChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandSarManager : llm:OS::Networking::NetworkOperators::IMobileBroadbandSarManager
    {
        MobileBroadbandSarManager(std::nullptr_t) noexcept {}
        MobileBroadbandSarManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandSarManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandSlotInfo : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo,
        impl::require<MobileBroadbandSlotInfo, llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo2>
    {
        MobileBroadbandSlotInfo(std::nullptr_t) noexcept {}
        MobileBroadbandSlotInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandSlotInfoChangedEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs
    {
        MobileBroadbandSlotInfoChangedEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandSlotInfoChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandSlotManager : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotManager
    {
        MobileBroadbandSlotManager(std::nullptr_t) noexcept {}
        MobileBroadbandSlotManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandSlotManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandTransmissionStateChangedEventArgs : llm:OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs
    {
        MobileBroadbandTransmissionStateChangedEventArgs(std::nullptr_t) noexcept {}
        MobileBroadbandTransmissionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandUicc : llm:OS::Networking::NetworkOperators::IMobileBroadbandUicc
    {
        MobileBroadbandUicc(std::nullptr_t) noexcept {}
        MobileBroadbandUicc(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandUicc(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandUiccApp : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccApp
    {
        MobileBroadbandUiccApp(std::nullptr_t) noexcept {}
        MobileBroadbandUiccApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccApp(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandUiccAppReadRecordResult : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult
    {
        MobileBroadbandUiccAppReadRecordResult(std::nullptr_t) noexcept {}
        MobileBroadbandUiccAppReadRecordResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandUiccAppRecordDetailsResult : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult
    {
        MobileBroadbandUiccAppRecordDetailsResult(std::nullptr_t) noexcept {}
        MobileBroadbandUiccAppRecordDetailsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MobileBroadbandUiccAppsResult : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult
    {
        MobileBroadbandUiccAppsResult(std::nullptr_t) noexcept {}
        MobileBroadbandUiccAppsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkOperatorDataUsageTriggerDetails : llm:OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails
    {
        NetworkOperatorDataUsageTriggerDetails(std::nullptr_t) noexcept {}
        NetworkOperatorDataUsageTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkOperatorNotificationEventDetails : llm:OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails,
        impl::require<NetworkOperatorNotificationEventDetails, llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck>
    {
        NetworkOperatorNotificationEventDetails(std::nullptr_t) noexcept {}
        NetworkOperatorNotificationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkOperatorTetheringAccessPointConfiguration : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration,
        impl::require<NetworkOperatorTetheringAccessPointConfiguration, llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2>
    {
        NetworkOperatorTetheringAccessPointConfiguration(std::nullptr_t) noexcept {}
        NetworkOperatorTetheringAccessPointConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration(ptr, take_ownership_from_abi) {}
        NetworkOperatorTetheringAccessPointConfiguration();
    };
    struct __declspec(empty_bases) NetworkOperatorTetheringClient : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringClient
    {
        NetworkOperatorTetheringClient(std::nullptr_t) noexcept {}
        NetworkOperatorTetheringClient(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringClient(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkOperatorTetheringManager : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringManager,
        impl::require<NetworkOperatorTetheringManager, llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringClientManager>
    {
        NetworkOperatorTetheringManager(std::nullptr_t) noexcept {}
        NetworkOperatorTetheringManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringManager(ptr, take_ownership_from_abi) {}
        static auto GetTetheringCapability(param::hstring const& networkAccountId);
        static auto CreateFromNetworkAccountId(param::hstring const& networkAccountId);
        static auto GetTetheringCapabilityFromConnectionProfile(llm:OS::Networking::Connectivity::ConnectionProfile const& profile);
        static auto CreateFromConnectionProfile(llm:OS::Networking::Connectivity::ConnectionProfile const& profile);
        static auto CreateFromConnectionProfile(llm:OS::Networking::Connectivity::ConnectionProfile const& profile, llm:OS::Networking::Connectivity::NetworkAdapter const& adapter);
        static auto IsNoConnectionsTimeoutEnabled();
        static auto EnableNoConnectionsTimeout();
        static auto EnableNoConnectionsTimeoutAsync();
        static auto DisableNoConnectionsTimeout();
        static auto DisableNoConnectionsTimeoutAsync();
    };
    struct __declspec(empty_bases) NetworkOperatorTetheringOperationResult : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult
    {
        NetworkOperatorTetheringOperationResult(std::nullptr_t) noexcept {}
        NetworkOperatorTetheringOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProvisionFromXmlDocumentResults : llm:OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults
    {
        ProvisionFromXmlDocumentResults(std::nullptr_t) noexcept {}
        ProvisionFromXmlDocumentResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProvisionedProfile : llm:OS::Networking::NetworkOperators::IProvisionedProfile
    {
        ProvisionedProfile(std::nullptr_t) noexcept {}
        ProvisionedProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IProvisionedProfile(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProvisioningAgent : llm:OS::Networking::NetworkOperators::IProvisioningAgent
    {
        ProvisioningAgent(std::nullptr_t) noexcept {}
        ProvisioningAgent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IProvisioningAgent(ptr, take_ownership_from_abi) {}
        ProvisioningAgent();
        static auto CreateFromNetworkAccountId(param::hstring const& networkAccountId);
    };
    struct __declspec(empty_bases) TetheringEntitlementCheckTriggerDetails : llm:OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails
    {
        TetheringEntitlementCheckTriggerDetails(std::nullptr_t) noexcept {}
        TetheringEntitlementCheckTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UssdMessage : llm:OS::Networking::NetworkOperators::IUssdMessage
    {
        UssdMessage(std::nullptr_t) noexcept {}
        UssdMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IUssdMessage(ptr, take_ownership_from_abi) {}
        explicit UssdMessage(param::hstring const& messageText);
    };
    struct __declspec(empty_bases) UssdReply : llm:OS::Networking::NetworkOperators::IUssdReply
    {
        UssdReply(std::nullptr_t) noexcept {}
        UssdReply(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IUssdReply(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UssdSession : llm:OS::Networking::NetworkOperators::IUssdSession
    {
        UssdSession(std::nullptr_t) noexcept {}
        UssdSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::NetworkOperators::IUssdSession(ptr, take_ownership_from_abi) {}
        static auto CreateFromNetworkAccountId(param::hstring const& networkAccountId);
        static auto CreateFromNetworkInterfaceId(param::hstring const& networkInterfaceId);
    };
}
#endif
