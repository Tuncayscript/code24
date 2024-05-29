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
#ifndef LLM_OS_Devices_WiFiDirect_1_H
#define LLM_OS_Devices_WiFiDirect_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.WiFiDirect.0.h"
LLM_EXPORT namespace llm::OS::Devices::WiFiDirect
{
    struct __declspec(empty_bases) IWiFiDirectAdvertisement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectAdvertisement>
    {
        IWiFiDirectAdvertisement(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectAdvertisement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectAdvertisement2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectAdvertisement2>
    {
        IWiFiDirectAdvertisement2(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectAdvertisement2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectAdvertisementPublisher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectAdvertisementPublisher>
    {
        IWiFiDirectAdvertisementPublisher(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectAdvertisementPublisher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectAdvertisementPublisherStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>
    {
        IWiFiDirectAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectAdvertisementPublisherStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionListener :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionListener>
    {
        IWiFiDirectConnectionListener(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionParameters :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionParameters>
    {
        IWiFiDirectConnectionParameters(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionParameters2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionParameters2>
    {
        IWiFiDirectConnectionParameters2(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionParameters2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionParametersStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionParametersStatics>
    {
        IWiFiDirectConnectionParametersStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionParametersStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionRequest>,
        impl::require<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest, llm::OS::Foundation::IClosable>
    {
        IWiFiDirectConnectionRequest(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectConnectionRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectConnectionRequestedEventArgs>
    {
        IWiFiDirectConnectionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectDevice>,
        impl::require<llm::OS::Devices::WiFiDirect::IWiFiDirectDevice, llm::OS::Foundation::IClosable>
    {
        IWiFiDirectDevice(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectDeviceStatics>
    {
        IWiFiDirectDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectDeviceStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectDeviceStatics2>
    {
        IWiFiDirectDeviceStatics2(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectDeviceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectInformationElement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectInformationElement>
    {
        IWiFiDirectInformationElement(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectInformationElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectInformationElementStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectInformationElementStatics>
    {
        IWiFiDirectInformationElementStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectInformationElementStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectLegacySettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectLegacySettings>
    {
        IWiFiDirectLegacySettings(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectLegacySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
