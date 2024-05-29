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
#ifndef LLM_OS_Devices_WiFi_1_H
#define LLM_OS_Devices_WiFi_1_H
#include "llm/impl/Windows.Devices.WiFi.0.h"
LLM_EXPORT namespace llm::OS::Devices::WiFi
{
    struct __declspec(empty_bases) IWiFiAdapter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiAdapter>
    {
        IWiFiAdapter(std::nullptr_t = nullptr) noexcept {}
        IWiFiAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiAdapter2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiAdapter2>
    {
        IWiFiAdapter2(std::nullptr_t = nullptr) noexcept {}
        IWiFiAdapter2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiAdapterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiAdapterStatics>
    {
        IWiFiAdapterStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiAdapterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiAvailableNetwork :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiAvailableNetwork>
    {
        IWiFiAvailableNetwork(std::nullptr_t = nullptr) noexcept {}
        IWiFiAvailableNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiConnectionResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiConnectionResult>
    {
        IWiFiConnectionResult(std::nullptr_t = nullptr) noexcept {}
        IWiFiConnectionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiNetworkReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiNetworkReport>
    {
        IWiFiNetworkReport(std::nullptr_t = nullptr) noexcept {}
        IWiFiNetworkReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiOnDemandHotspotConnectTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiOnDemandHotspotConnectTriggerDetails>
    {
        IWiFiOnDemandHotspotConnectTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IWiFiOnDemandHotspotConnectTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiOnDemandHotspotConnectionResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiOnDemandHotspotConnectionResult>
    {
        IWiFiOnDemandHotspotConnectionResult(std::nullptr_t = nullptr) noexcept {}
        IWiFiOnDemandHotspotConnectionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiOnDemandHotspotNetwork :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiOnDemandHotspotNetwork>
    {
        IWiFiOnDemandHotspotNetwork(std::nullptr_t = nullptr) noexcept {}
        IWiFiOnDemandHotspotNetwork(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiOnDemandHotspotNetworkProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiOnDemandHotspotNetworkProperties>
    {
        IWiFiOnDemandHotspotNetworkProperties(std::nullptr_t = nullptr) noexcept {}
        IWiFiOnDemandHotspotNetworkProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiOnDemandHotspotNetworkStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiOnDemandHotspotNetworkStatics>
    {
        IWiFiOnDemandHotspotNetworkStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiOnDemandHotspotNetworkStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiWpsConfigurationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiWpsConfigurationResult>
    {
        IWiFiWpsConfigurationResult(std::nullptr_t = nullptr) noexcept {}
        IWiFiWpsConfigurationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
