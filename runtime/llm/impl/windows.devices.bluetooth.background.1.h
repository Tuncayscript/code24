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
#ifndef LLM_OS_Devices_Bluetooth_Background_1_H
#define LLM_OS_Devices_Bluetooth_Background_1_H
#include "llm/impl/Windows.Devices.Bluetooth.Background.0.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Background
{
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherTriggerDetails>
    {
        IBluetoothLEAdvertisementPublisherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherTriggerDetails2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherTriggerDetails2>
    {
        IBluetoothLEAdvertisementPublisherTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcherTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcherTriggerDetails>
    {
        IBluetoothLEAdvertisementWatcherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTriggerDetails>
    {
        IGattCharacteristicNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTriggerDetails2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTriggerDetails2>
    {
        IGattCharacteristicNotificationTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderConnection>
    {
        IGattServiceProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderConnectionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderConnectionStatics>
    {
        IGattServiceProviderConnectionStatics(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderConnectionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderTriggerDetails>
    {
        IGattServiceProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommConnectionTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommConnectionTriggerDetails>
    {
        IRfcommConnectionTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IRfcommConnectionTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommInboundConnectionInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommInboundConnectionInformation>
    {
        IRfcommInboundConnectionInformation(std::nullptr_t = nullptr) noexcept {}
        IRfcommInboundConnectionInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommOutboundConnectionInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommOutboundConnectionInformation>
    {
        IRfcommOutboundConnectionInformation(std::nullptr_t = nullptr) noexcept {}
        IRfcommOutboundConnectionInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
