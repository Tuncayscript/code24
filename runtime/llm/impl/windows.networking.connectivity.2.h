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
#ifndef LLM_OS_Networking_Connectivity_2_H
#define LLM_OS_Networking_Connectivity_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Networking.Connectivity.1.h"
LLM_EXPORT namespace llm:OS::Networking::Connectivity
{
    struct NetworkStatusChangedEventHandler : llm:OS::Foundation::IUnknown
    {
        NetworkStatusChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NetworkStatusChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NetworkStatusChangedEventHandler(L lambda);
        template <typename F> NetworkStatusChangedEventHandler(F* function);
        template <typename O, typename M> NetworkStatusChangedEventHandler(O* object, M method);
        template <typename O, typename M> NetworkStatusChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NetworkStatusChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender) const;
    };
    struct NetworkUsageStates
    {
        llm:OS::Networking::Connectivity::TriStates Roaming;
        llm:OS::Networking::Connectivity::TriStates Shared;
    };
    inline bool operator==(NetworkUsageStates const& left, NetworkUsageStates const& right) noexcept
    {
        return left.Roaming == right.Roaming && left.Shared == right.Shared;
    }
    inline bool operator!=(NetworkUsageStates const& left, NetworkUsageStates const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AttributedNetworkUsage : llm:OS::Networking::Connectivity::IAttributedNetworkUsage
    {
        AttributedNetworkUsage(std::nullptr_t) noexcept {}
        AttributedNetworkUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IAttributedNetworkUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CellularApnContext : llm:OS::Networking::Connectivity::ICellularApnContext,
        impl::require<CellularApnContext, llm:OS::Networking::Connectivity::ICellularApnContext2>
    {
        CellularApnContext(std::nullptr_t) noexcept {}
        CellularApnContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::ICellularApnContext(ptr, take_ownership_from_abi) {}
        CellularApnContext();
    };
    struct __declspec(empty_bases) ConnectionCost : llm:OS::Networking::Connectivity::IConnectionCost,
        impl::require<ConnectionCost, llm:OS::Networking::Connectivity::IConnectionCost2>
    {
        ConnectionCost(std::nullptr_t) noexcept {}
        ConnectionCost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IConnectionCost(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConnectionProfile : llm:OS::Networking::Connectivity::IConnectionProfile,
        impl::require<ConnectionProfile, llm:OS::Networking::Connectivity::IConnectionProfile2, llm:OS::Networking::Connectivity::IConnectionProfile3, llm:OS::Networking::Connectivity::IConnectionProfile4, llm:OS::Networking::Connectivity::IConnectionProfile5, llm:OS::Networking::Connectivity::IConnectionProfile6>
    {
        ConnectionProfile(std::nullptr_t) noexcept {}
        ConnectionProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IConnectionProfile(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConnectionProfileFilter : llm:OS::Networking::Connectivity::IConnectionProfileFilter,
        impl::require<ConnectionProfileFilter, llm:OS::Networking::Connectivity::IConnectionProfileFilter2, llm:OS::Networking::Connectivity::IConnectionProfileFilter3>
    {
        ConnectionProfileFilter(std::nullptr_t) noexcept {}
        ConnectionProfileFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IConnectionProfileFilter(ptr, take_ownership_from_abi) {}
        ConnectionProfileFilter();
    };
    struct __declspec(empty_bases) ConnectionSession : llm:OS::Networking::Connectivity::IConnectionSession
    {
        ConnectionSession(std::nullptr_t) noexcept {}
        ConnectionSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IConnectionSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConnectivityInterval : llm:OS::Networking::Connectivity::IConnectivityInterval
    {
        ConnectivityInterval(std::nullptr_t) noexcept {}
        ConnectivityInterval(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IConnectivityInterval(ptr, take_ownership_from_abi) {}
    };
    struct ConnectivityManager
    {
        ConnectivityManager() = delete;
        static auto AcquireConnectionAsync(llm:OS::Networking::Connectivity::CellularApnContext const& cellularApnContext);
        static auto AddHttpRoutePolicy(llm:OS::Networking::Connectivity::RoutePolicy const& routePolicy);
        static auto RemoveHttpRoutePolicy(llm:OS::Networking::Connectivity::RoutePolicy const& routePolicy);
    };
    struct __declspec(empty_bases) DataPlanStatus : llm:OS::Networking::Connectivity::IDataPlanStatus
    {
        DataPlanStatus(std::nullptr_t) noexcept {}
        DataPlanStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IDataPlanStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataPlanUsage : llm:OS::Networking::Connectivity::IDataPlanUsage
    {
        DataPlanUsage(std::nullptr_t) noexcept {}
        DataPlanUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IDataPlanUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataUsage : llm:OS::Networking::Connectivity::IDataUsage
    {
        DataUsage(std::nullptr_t) noexcept {}
        DataUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IDataUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPInformation : llm:OS::Networking::Connectivity::IIPInformation
    {
        IPInformation(std::nullptr_t) noexcept {}
        IPInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IIPInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LanIdentifier : llm:OS::Networking::Connectivity::ILanIdentifier
    {
        LanIdentifier(std::nullptr_t) noexcept {}
        LanIdentifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::ILanIdentifier(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LanIdentifierData : llm:OS::Networking::Connectivity::ILanIdentifierData
    {
        LanIdentifierData(std::nullptr_t) noexcept {}
        LanIdentifierData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::ILanIdentifierData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkAdapter : llm:OS::Networking::Connectivity::INetworkAdapter
    {
        NetworkAdapter(std::nullptr_t) noexcept {}
        NetworkAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::INetworkAdapter(ptr, take_ownership_from_abi) {}
    };
    struct NetworkInformation
    {
        NetworkInformation() = delete;
        static auto GetConnectionProfiles();
        static auto GetInternetConnectionProfile();
        static auto GetLanIdentifiers();
        static auto GetHostNames();
        static auto GetProxyConfigurationAsync(llm:OS::Foundation::Uri const& uri);
        static auto GetSortedEndpointPairs(param::iterable<llm:OS::Networking::EndpointPair> const& destinationList, llm:OS::Networking::HostNameSortOptions const& sortOptions);
        static auto NetworkStatusChanged(llm:OS::Networking::Connectivity::NetworkStatusChangedEventHandler const& networkStatusHandler);
        using NetworkStatusChanged_revoker = impl::factory_event_revoker<llm:OS::Networking::Connectivity::INetworkInformationStatics, &impl::abi_t<llm:OS::Networking::Connectivity::INetworkInformationStatics>::remove_NetworkStatusChanged>;
        [[nodiscard]] static NetworkStatusChanged_revoker NetworkStatusChanged(auto_revoke_t, llm:OS::Networking::Connectivity::NetworkStatusChangedEventHandler const& networkStatusHandler);
        static auto NetworkStatusChanged(llm::event_token const& eventCookie);
        static auto FindConnectionProfilesAsync(llm:OS::Networking::Connectivity::ConnectionProfileFilter const& pProfileFilter);
    };
    struct __declspec(empty_bases) NetworkItem : llm:OS::Networking::Connectivity::INetworkItem
    {
        NetworkItem(std::nullptr_t) noexcept {}
        NetworkItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::INetworkItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkSecuritySettings : llm:OS::Networking::Connectivity::INetworkSecuritySettings
    {
        NetworkSecuritySettings(std::nullptr_t) noexcept {}
        NetworkSecuritySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::INetworkSecuritySettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkStateChangeEventDetails : llm:OS::Networking::Connectivity::INetworkStateChangeEventDetails,
        impl::require<NetworkStateChangeEventDetails, llm:OS::Networking::Connectivity::INetworkStateChangeEventDetails2>
    {
        NetworkStateChangeEventDetails(std::nullptr_t) noexcept {}
        NetworkStateChangeEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::INetworkStateChangeEventDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NetworkUsage : llm:OS::Networking::Connectivity::INetworkUsage
    {
        NetworkUsage(std::nullptr_t) noexcept {}
        NetworkUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::INetworkUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProviderNetworkUsage : llm:OS::Networking::Connectivity::IProviderNetworkUsage
    {
        ProviderNetworkUsage(std::nullptr_t) noexcept {}
        ProviderNetworkUsage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IProviderNetworkUsage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProxyConfiguration : llm:OS::Networking::Connectivity::IProxyConfiguration
    {
        ProxyConfiguration(std::nullptr_t) noexcept {}
        ProxyConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IProxyConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RoutePolicy : llm:OS::Networking::Connectivity::IRoutePolicy
    {
        RoutePolicy(std::nullptr_t) noexcept {}
        RoutePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IRoutePolicy(ptr, take_ownership_from_abi) {}
        RoutePolicy(llm:OS::Networking::Connectivity::ConnectionProfile const& connectionProfile, llm:OS::Networking::HostName const& hostName, llm:OS::Networking::DomainNameType const& type);
    };
    struct __declspec(empty_bases) WlanConnectionProfileDetails : llm:OS::Networking::Connectivity::IWlanConnectionProfileDetails
    {
        WlanConnectionProfileDetails(std::nullptr_t) noexcept {}
        WlanConnectionProfileDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IWlanConnectionProfileDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WwanConnectionProfileDetails : llm:OS::Networking::Connectivity::IWwanConnectionProfileDetails,
        impl::require<WwanConnectionProfileDetails, llm:OS::Networking::Connectivity::IWwanConnectionProfileDetails2>
    {
        WwanConnectionProfileDetails(std::nullptr_t) noexcept {}
        WwanConnectionProfileDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Connectivity::IWwanConnectionProfileDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
