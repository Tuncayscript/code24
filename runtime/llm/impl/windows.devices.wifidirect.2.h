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
#ifndef LLM_OS_Devices_WiFiDirect_2_H
#define LLM_OS_Devices_WiFiDirect_2_H
#include "llm/impl/Windows.Devices.Enumeration.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.WiFiDirect.1.h"
LLM_EXPORT namespace llm::OS::Devices::WiFiDirect
{
    struct __declspec(empty_bases) WiFiDirectAdvertisement : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement,
        impl::require<WiFiDirectAdvertisement, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement2>
    {
        WiFiDirectAdvertisement(std::nullptr_t) noexcept {}
        WiFiDirectAdvertisement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectAdvertisementPublisher : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher
    {
        WiFiDirectAdvertisementPublisher(std::nullptr_t) noexcept {}
        WiFiDirectAdvertisementPublisher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher(ptr, take_ownership_from_abi) {}
        WiFiDirectAdvertisementPublisher();
    };
    struct __declspec(empty_bases) WiFiDirectAdvertisementPublisherStatusChangedEventArgs : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs
    {
        WiFiDirectAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectAdvertisementPublisherStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectConnectionListener : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener
    {
        WiFiDirectConnectionListener(std::nullptr_t) noexcept {}
        WiFiDirectConnectionListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener(ptr, take_ownership_from_abi) {}
        WiFiDirectConnectionListener();
    };
    struct __declspec(empty_bases) WiFiDirectConnectionParameters : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters,
        impl::require<WiFiDirectConnectionParameters, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2, llm::OS::Devices::Enumeration::IDevicePairingSettings>
    {
        WiFiDirectConnectionParameters(std::nullptr_t) noexcept {}
        WiFiDirectConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters(ptr, take_ownership_from_abi) {}
        WiFiDirectConnectionParameters();
        static auto GetDevicePairingKinds(llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod const& configurationMethod);
    };
    struct __declspec(empty_bases) WiFiDirectConnectionRequest : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest
    {
        WiFiDirectConnectionRequest(std::nullptr_t) noexcept {}
        WiFiDirectConnectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectConnectionRequestedEventArgs : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs
    {
        WiFiDirectConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectDevice : llm::OS::Devices::WiFiDirect::IWiFiDirectDevice
    {
        WiFiDirectDevice(std::nullptr_t) noexcept {}
        WiFiDirectDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector(llm::OS::Devices::WiFiDirect::WiFiDirectDeviceSelectorType const& type);
        static auto FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionParameters const& connectionParameters);
    };
    struct __declspec(empty_bases) WiFiDirectInformationElement : llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement
    {
        WiFiDirectInformationElement(std::nullptr_t) noexcept {}
        WiFiDirectInformationElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement(ptr, take_ownership_from_abi) {}
        WiFiDirectInformationElement();
        static auto CreateFromBuffer(llm::OS::Storage::Streams::IBuffer const& buffer);
        static auto CreateFromDeviceInformation(llm::OS::Devices::Enumeration::DeviceInformation const& deviceInformation);
    };
    struct __declspec(empty_bases) WiFiDirectLegacySettings : llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings
    {
        WiFiDirectLegacySettings(std::nullptr_t) noexcept {}
        WiFiDirectLegacySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings(ptr, take_ownership_from_abi) {}
    };
}
#endif
