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
#ifndef LLM_OS_Devices_Enumeration_2_H
#define LLM_OS_Devices_Enumeration_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.Enumeration.1.h"
LLM_EXPORT namespace llm::OS::Devices::Enumeration
{
    struct __declspec(empty_bases) DeviceAccessChangedEventArgs : llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs,
        impl::require<DeviceAccessChangedEventArgs, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2>
    {
        DeviceAccessChangedEventArgs(std::nullptr_t) noexcept {}
        DeviceAccessChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceAccessInformation : llm::OS::Devices::Enumeration::IDeviceAccessInformation
    {
        DeviceAccessInformation(std::nullptr_t) noexcept {}
        DeviceAccessInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceAccessInformation(ptr, take_ownership_from_abi) {}
        static auto CreateFromId(param::hstring const& deviceId);
        static auto CreateFromDeviceClassId(llm::guid const& deviceClassId);
        static auto CreateFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass);
    };
    struct __declspec(empty_bases) DeviceConnectionChangeTriggerDetails : llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails
    {
        DeviceConnectionChangeTriggerDetails(std::nullptr_t) noexcept {}
        DeviceConnectionChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceDisconnectButtonClickedEventArgs : llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs
    {
        DeviceDisconnectButtonClickedEventArgs(std::nullptr_t) noexcept {}
        DeviceDisconnectButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceInformation : llm::OS::Devices::Enumeration::IDeviceInformation,
        impl::require<DeviceInformation, llm::OS::Devices::Enumeration::IDeviceInformation2>
    {
        DeviceInformation(std::nullptr_t) noexcept {}
        DeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceInformation(ptr, take_ownership_from_abi) {}
        static auto CreateFromIdAsync(param::hstring const& deviceId);
        static auto CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties);
        static auto FindAllAsync();
        static auto FindAllAsync(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass);
        static auto FindAllAsync(param::hstring const& aqsFilter);
        static auto FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties);
        static auto CreateWatcher();
        static auto CreateWatcher(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass);
        static auto CreateWatcher(param::hstring const& aqsFilter);
        static auto CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties);
        static auto GetAqsFilterFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass);
        static auto CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind);
        static auto FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind);
        static auto CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind);
    };
    struct __declspec(empty_bases) DeviceInformationCollection : llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::DeviceInformation>
    {
        DeviceInformationCollection(std::nullptr_t) noexcept {}
        DeviceInformationCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::DeviceInformation>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceInformationCustomPairing : llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing
    {
        DeviceInformationCustomPairing(std::nullptr_t) noexcept {}
        DeviceInformationCustomPairing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceInformationPairing : llm::OS::Devices::Enumeration::IDeviceInformationPairing,
        impl::require<DeviceInformationPairing, llm::OS::Devices::Enumeration::IDeviceInformationPairing2>
    {
        DeviceInformationPairing(std::nullptr_t) noexcept {}
        DeviceInformationPairing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceInformationPairing(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::Enumeration::IDeviceInformationPairing::PairAsync;
        using impl::consume_t<DeviceInformationPairing, llm::OS::Devices::Enumeration::IDeviceInformationPairing2>::PairAsync;
        static auto TryRegisterForAllInboundPairingRequests(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported);
        static auto TryRegisterForAllInboundPairingRequestsWithProtectionLevel(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported, llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel);
    };
    struct __declspec(empty_bases) DeviceInformationUpdate : llm::OS::Devices::Enumeration::IDeviceInformationUpdate,
        impl::require<DeviceInformationUpdate, llm::OS::Devices::Enumeration::IDeviceInformationUpdate2>
    {
        DeviceInformationUpdate(std::nullptr_t) noexcept {}
        DeviceInformationUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceInformationUpdate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePairingRequestedEventArgs : llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs,
        impl::require<DevicePairingRequestedEventArgs, llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs2>
    {
        DevicePairingRequestedEventArgs(std::nullptr_t) noexcept {}
        DevicePairingRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePairingResult : llm::OS::Devices::Enumeration::IDevicePairingResult
    {
        DevicePairingResult(std::nullptr_t) noexcept {}
        DevicePairingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDevicePairingResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePicker : llm::OS::Devices::Enumeration::IDevicePicker
    {
        DevicePicker(std::nullptr_t) noexcept {}
        DevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDevicePicker(ptr, take_ownership_from_abi) {}
        DevicePicker();
    };
    struct __declspec(empty_bases) DevicePickerAppearance : llm::OS::Devices::Enumeration::IDevicePickerAppearance
    {
        DevicePickerAppearance(std::nullptr_t) noexcept {}
        DevicePickerAppearance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDevicePickerAppearance(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePickerFilter : llm::OS::Devices::Enumeration::IDevicePickerFilter
    {
        DevicePickerFilter(std::nullptr_t) noexcept {}
        DevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDevicePickerFilter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceSelectedEventArgs : llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs
    {
        DeviceSelectedEventArgs(std::nullptr_t) noexcept {}
        DeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceThumbnail : llm::OS::Storage::Streams::IRandomAccessStreamWithContentType
    {
        DeviceThumbnail(std::nullptr_t) noexcept {}
        DeviceThumbnail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Storage::Streams::IRandomAccessStreamWithContentType(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceUnpairingResult : llm::OS::Devices::Enumeration::IDeviceUnpairingResult
    {
        DeviceUnpairingResult(std::nullptr_t) noexcept {}
        DeviceUnpairingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceUnpairingResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceWatcher : llm::OS::Devices::Enumeration::IDeviceWatcher,
        impl::require<DeviceWatcher, llm::OS::Devices::Enumeration::IDeviceWatcher2>
    {
        DeviceWatcher(std::nullptr_t) noexcept {}
        DeviceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceWatcherEvent : llm::OS::Devices::Enumeration::IDeviceWatcherEvent
    {
        DeviceWatcherEvent(std::nullptr_t) noexcept {}
        DeviceWatcherEvent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceWatcherEvent(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceWatcherTriggerDetails : llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails
    {
        DeviceWatcherTriggerDetails(std::nullptr_t) noexcept {}
        DeviceWatcherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EnclosureLocation : llm::OS::Devices::Enumeration::IEnclosureLocation,
        impl::require<EnclosureLocation, llm::OS::Devices::Enumeration::IEnclosureLocation2>
    {
        EnclosureLocation(std::nullptr_t) noexcept {}
        EnclosureLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::IEnclosureLocation(ptr, take_ownership_from_abi) {}
    };
}
#endif
