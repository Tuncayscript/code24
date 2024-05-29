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
#ifndef LLM_OS_Devices_WiFiDirect_Services_1_H
#define LLM_OS_Devices_WiFiDirect_Services_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.WiFiDirect.Services.0.h"
LLM_EXPORT namespace llm::OS::Devices::WiFiDirect::Services
{
    struct __declspec(empty_bases) IWiFiDirectService :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectService>
    {
        IWiFiDirectService(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectService(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceAdvertiser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceAdvertiser>
    {
        IWiFiDirectServiceAdvertiser(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceAdvertiser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceAdvertiserFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceAdvertiserFactory>
    {
        IWiFiDirectServiceAdvertiserFactory(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceAdvertiserFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>
    {
        IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceProvisioningInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceProvisioningInfo>
    {
        IWiFiDirectServiceProvisioningInfo(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceProvisioningInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceRemotePortAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceRemotePortAddedEventArgs>
    {
        IWiFiDirectServiceRemotePortAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceRemotePortAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceSession>,
        impl::require<llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSession, llm::OS::Foundation::IClosable>
    {
        IWiFiDirectServiceSession(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceSessionDeferredEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceSessionDeferredEventArgs>
    {
        IWiFiDirectServiceSessionDeferredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceSessionDeferredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceSessionRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceSessionRequest>,
        impl::require<llm::OS::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest, llm::OS::Foundation::IClosable>
    {
        IWiFiDirectServiceSessionRequest(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceSessionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceSessionRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceSessionRequestedEventArgs>
    {
        IWiFiDirectServiceSessionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceSessionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWiFiDirectServiceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWiFiDirectServiceStatics>
    {
        IWiFiDirectServiceStatics(std::nullptr_t = nullptr) noexcept {}
        IWiFiDirectServiceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
