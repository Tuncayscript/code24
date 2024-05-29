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
#ifndef LLM_OS_Devices_Bluetooth_Advertisement_1_H
#define LLM_OS_Devices_Bluetooth_Advertisement_1_H
#include "llm/impl/Windows.Devices.Bluetooth.Advertisement.0.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Advertisement
{
    struct __declspec(empty_bases) IBluetoothLEAdvertisement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisement>
    {
        IBluetoothLEAdvertisement(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementBytePattern :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementBytePattern>
    {
        IBluetoothLEAdvertisementBytePattern(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementBytePattern(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementBytePatternFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementBytePatternFactory>
    {
        IBluetoothLEAdvertisementBytePatternFactory(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementBytePatternFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementDataSection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementDataSection>
    {
        IBluetoothLEAdvertisementDataSection(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementDataSection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementDataSectionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementDataSectionFactory>
    {
        IBluetoothLEAdvertisementDataSectionFactory(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementDataSectionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementDataTypesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementDataTypesStatics>
    {
        IBluetoothLEAdvertisementDataTypesStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementDataTypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementFilter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementFilter>
    {
        IBluetoothLEAdvertisementFilter(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisher>
    {
        IBluetoothLEAdvertisementPublisher(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisher2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisher2>
    {
        IBluetoothLEAdvertisementPublisher2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisher2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherFactory>
    {
        IBluetoothLEAdvertisementPublisherFactory(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherStatusChangedEventArgs>
    {
        IBluetoothLEAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2>
    {
        IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherStatusChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementReceivedEventArgs>
    {
        IBluetoothLEAdvertisementReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementReceivedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementReceivedEventArgs2>
    {
        IBluetoothLEAdvertisementReceivedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementReceivedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcher>
    {
        IBluetoothLEAdvertisementWatcher(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcher2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcher2>
    {
        IBluetoothLEAdvertisementWatcher2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcher2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcherFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcherFactory>
    {
        IBluetoothLEAdvertisementWatcherFactory(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcherFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcherStoppedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcherStoppedEventArgs>
    {
        IBluetoothLEAdvertisementWatcherStoppedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcherStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEManufacturerData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEManufacturerData>
    {
        IBluetoothLEManufacturerData(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEManufacturerData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEManufacturerDataFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEManufacturerDataFactory>
    {
        IBluetoothLEManufacturerDataFactory(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEManufacturerDataFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
