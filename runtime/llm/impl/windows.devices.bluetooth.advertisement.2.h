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
#ifndef LLM_OS_Devices_Bluetooth_Advertisement_2_H
#define LLM_OS_Devices_Bluetooth_Advertisement_2_H
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.Bluetooth.Advertisement.1.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Advertisement
{
    struct __declspec(empty_bases) BluetoothLEAdvertisement : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement
    {
        BluetoothLEAdvertisement(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisement();
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementBytePattern : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern
    {
        BluetoothLEAdvertisementBytePattern(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementBytePattern(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePattern(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementBytePattern();
        BluetoothLEAdvertisementBytePattern(uint8_t dataType, int16_t offset, llm::OS::Storage::Streams::IBuffer const& data);
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementDataSection : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection
    {
        BluetoothLEAdvertisementDataSection(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementDataSection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSection(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementDataSection();
        BluetoothLEAdvertisementDataSection(uint8_t dataType, llm::OS::Storage::Streams::IBuffer const& data);
    };
    struct BluetoothLEAdvertisementDataTypes
    {
        BluetoothLEAdvertisementDataTypes() = delete;
        [[nodiscard]] static auto Flags();
        [[nodiscard]] static auto IncompleteService16BitUuids();
        [[nodiscard]] static auto CompleteService16BitUuids();
        [[nodiscard]] static auto IncompleteService32BitUuids();
        [[nodiscard]] static auto CompleteService32BitUuids();
        [[nodiscard]] static auto IncompleteService128BitUuids();
        [[nodiscard]] static auto CompleteService128BitUuids();
        [[nodiscard]] static auto ShortenedLocalName();
        [[nodiscard]] static auto CompleteLocalName();
        [[nodiscard]] static auto TxPowerLevel();
        [[nodiscard]] static auto PeripheralConnectionIntervalRange();
        [[nodiscard]] static auto ServiceSolicitation16BitUuids();
        [[nodiscard]] static auto ServiceSolicitation32BitUuids();
        [[nodiscard]] static auto ServiceSolicitation128BitUuids();
        [[nodiscard]] static auto ServiceData16BitUuids();
        [[nodiscard]] static auto ServiceData32BitUuids();
        [[nodiscard]] static auto ServiceData128BitUuids();
        [[nodiscard]] static auto PublicTargetAddress();
        [[nodiscard]] static auto RandomTargetAddress();
        [[nodiscard]] static auto Appearance();
        [[nodiscard]] static auto AdvertisingInterval();
        [[nodiscard]] static auto ManufacturerSpecificData();
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementFilter : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter
    {
        BluetoothLEAdvertisementFilter(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementFilter();
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementPublisher : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher,
        impl::require<BluetoothLEAdvertisementPublisher, llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher2>
    {
        BluetoothLEAdvertisementPublisher(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementPublisher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementPublisher();
        explicit BluetoothLEAdvertisementPublisher(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement const& advertisement);
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementPublisherStatusChangedEventArgs : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs,
        impl::require<BluetoothLEAdvertisementPublisherStatusChangedEventArgs, llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        BluetoothLEAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementPublisherStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementReceivedEventArgs : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs,
        impl::require<BluetoothLEAdvertisementReceivedEventArgs, llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        BluetoothLEAdvertisementReceivedEventArgs(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementWatcher : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher,
        impl::require<BluetoothLEAdvertisementWatcher, llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher2>
    {
        BluetoothLEAdvertisementWatcher(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementWatcher();
        explicit BluetoothLEAdvertisementWatcher(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter const& advertisementFilter);
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementWatcherStoppedEventArgs : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs
    {
        BluetoothLEAdvertisementWatcherStoppedEventArgs(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementWatcherStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEManufacturerData : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData
    {
        BluetoothLEManufacturerData(std::nullptr_t) noexcept {}
        BluetoothLEManufacturerData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerData(ptr, take_ownership_from_abi) {}
        BluetoothLEManufacturerData();
        BluetoothLEManufacturerData(uint16_t companyId, llm::OS::Storage::Streams::IBuffer const& data);
    };
}
#endif
