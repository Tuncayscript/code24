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
#ifndef LLM_OS_Devices_Bluetooth_Background_2_H
#define LLM_OS_Devices_Bluetooth_Background_2_H
#include "llm/impl/Windows.Devices.Bluetooth.Background.1.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Background
{
    struct __declspec(empty_bases) BluetoothLEAdvertisementPublisherTriggerDetails : llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails,
        impl::require<BluetoothLEAdvertisementPublisherTriggerDetails, llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails2>
    {
        BluetoothLEAdvertisementPublisherTriggerDetails(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementPublisherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementPublisherTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementWatcherTriggerDetails : llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails
    {
        BluetoothLEAdvertisementWatcherTriggerDetails(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementWatcherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IBluetoothLEAdvertisementWatcherTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GattCharacteristicNotificationTriggerDetails : llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails,
        impl::require<GattCharacteristicNotificationTriggerDetails, llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails2>
    {
        GattCharacteristicNotificationTriggerDetails(std::nullptr_t) noexcept {}
        GattCharacteristicNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IGattCharacteristicNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GattServiceProviderConnection : llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection
    {
        GattServiceProviderConnection(std::nullptr_t) noexcept {}
        GattServiceProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IGattServiceProviderConnection(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AllServices();
    };
    struct __declspec(empty_bases) GattServiceProviderTriggerDetails : llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails
    {
        GattServiceProviderTriggerDetails(std::nullptr_t) noexcept {}
        GattServiceProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IGattServiceProviderTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RfcommConnectionTriggerDetails : llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails
    {
        RfcommConnectionTriggerDetails(std::nullptr_t) noexcept {}
        RfcommConnectionTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IRfcommConnectionTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RfcommInboundConnectionInformation : llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation
    {
        RfcommInboundConnectionInformation(std::nullptr_t) noexcept {}
        RfcommInboundConnectionInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RfcommOutboundConnectionInformation : llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation
    {
        RfcommOutboundConnectionInformation(std::nullptr_t) noexcept {}
        RfcommOutboundConnectionInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation(ptr, take_ownership_from_abi) {}
    };
}
#endif
