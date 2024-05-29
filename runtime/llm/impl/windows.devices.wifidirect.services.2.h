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
#ifndef LLM_OS_Devices_WiFiDirect_Services_2_H
#define LLM_OS_Devices_WiFiDirect_Services_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.WiFiDirect.Services.1.h"
LLM_EXPORT namespace llm::OS::Devices::WiFiDirect::Services
{
    struct __declspec(empty_bases) WiFiDirectService : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectService
    {
        WiFiDirectService(std::nullptr_t) noexcept {}
        WiFiDirectService(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectService(ptr, take_ownership_from_abi) {}
        static auto GetSelector(param::hstring const& serviceName);
        static auto GetSelector(param::hstring const& serviceName, llm::OS::Storage::Streams::IBuffer const& serviceInfoFilter);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) WiFiDirectServiceAdvertiser : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser
    {
        WiFiDirectServiceAdvertiser(std::nullptr_t) noexcept {}
        WiFiDirectServiceAdvertiser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser(ptr, take_ownership_from_abi) {}
        explicit WiFiDirectServiceAdvertiser(param::hstring const& serviceName);
    };
    struct __declspec(empty_bases) WiFiDirectServiceAutoAcceptSessionConnectedEventArgs : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs
    {
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceProvisioningInfo : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo
    {
        WiFiDirectServiceProvisioningInfo(std::nullptr_t) noexcept {}
        WiFiDirectServiceProvisioningInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceRemotePortAddedEventArgs : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs
    {
        WiFiDirectServiceRemotePortAddedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceRemotePortAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceSession : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSession
    {
        WiFiDirectServiceSession(std::nullptr_t) noexcept {}
        WiFiDirectServiceSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionDeferredEventArgs : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs
    {
        WiFiDirectServiceSessionDeferredEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionDeferredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionRequest : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest
    {
        WiFiDirectServiceSessionRequest(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionRequestedEventArgs : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs
    {
        WiFiDirectServiceSessionRequestedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
