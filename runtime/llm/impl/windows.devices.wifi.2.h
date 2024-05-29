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
#ifndef LLM_OS_Devices_WiFi_2_H
#define LLM_OS_Devices_WiFi_2_H
#include "llm/impl/Windows.Devices.WiFi.1.h"
LLM_EXPORT namespace llm::OS::Devices::WiFi
{
    struct __declspec(empty_bases) WiFiAdapter : llm::OS::Devices::WiFi::IWiFiAdapter,
        impl::require<WiFiAdapter, llm::OS::Devices::WiFi::IWiFiAdapter2>
    {
        WiFiAdapter(std::nullptr_t) noexcept {}
        WiFiAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiAdapter(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::WiFi::IWiFiAdapter::ConnectAsync;
        using impl::consume_t<WiFiAdapter, llm::OS::Devices::WiFi::IWiFiAdapter2>::ConnectAsync;
        static auto FindAllAdaptersAsync();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) WiFiAvailableNetwork : llm::OS::Devices::WiFi::IWiFiAvailableNetwork
    {
        WiFiAvailableNetwork(std::nullptr_t) noexcept {}
        WiFiAvailableNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiAvailableNetwork(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiConnectionResult : llm::OS::Devices::WiFi::IWiFiConnectionResult
    {
        WiFiConnectionResult(std::nullptr_t) noexcept {}
        WiFiConnectionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiConnectionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiNetworkReport : llm::OS::Devices::WiFi::IWiFiNetworkReport
    {
        WiFiNetworkReport(std::nullptr_t) noexcept {}
        WiFiNetworkReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiNetworkReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotConnectTriggerDetails : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails
    {
        WiFiOnDemandHotspotConnectTriggerDetails(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotConnectTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotConnectionResult : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult
    {
        WiFiOnDemandHotspotConnectionResult(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotConnectionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotNetwork : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork
    {
        WiFiOnDemandHotspotNetwork(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork(ptr, take_ownership_from_abi) {}
        static auto GetOrCreateById(llm::guid const& networkId);
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotNetworkProperties : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties
    {
        WiFiOnDemandHotspotNetworkProperties(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotNetworkProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiWpsConfigurationResult : llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult
    {
        WiFiWpsConfigurationResult(std::nullptr_t) noexcept {}
        WiFiWpsConfigurationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
