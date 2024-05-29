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
#ifndef LLM_OS_Devices_Enumeration_1_H
#define LLM_OS_Devices_Enumeration_1_H
#include "llm/impl/Windows.Devices.Enumeration.0.h"
LLM_EXPORT namespace llm::OS::Devices::Enumeration
{
    struct __declspec(empty_bases) IDeviceAccessChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccessChangedEventArgs>
    {
        IDeviceAccessChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccessChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceAccessChangedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccessChangedEventArgs2>,
        impl::require<llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs>
    {
        IDeviceAccessChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccessChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceAccessInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccessInformation>
    {
        IDeviceAccessInformation(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccessInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceAccessInformationStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceAccessInformationStatics>
    {
        IDeviceAccessInformationStatics(std::nullptr_t = nullptr) noexcept {}
        IDeviceAccessInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceConnectionChangeTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceConnectionChangeTriggerDetails>
    {
        IDeviceConnectionChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IDeviceConnectionChangeTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceDisconnectButtonClickedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceDisconnectButtonClickedEventArgs>
    {
        IDeviceDisconnectButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDeviceDisconnectButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformation>
    {
        IDeviceInformation(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformation2>
    {
        IDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationCustomPairing :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationCustomPairing>
    {
        IDeviceInformationCustomPairing(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationCustomPairing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationPairing :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationPairing>
    {
        IDeviceInformationPairing(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationPairing(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationPairing2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationPairing2>
    {
        IDeviceInformationPairing2(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationPairing2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationPairingStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationPairingStatics>
    {
        IDeviceInformationPairingStatics(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationPairingStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationPairingStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationPairingStatics2>
    {
        IDeviceInformationPairingStatics2(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationPairingStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationStatics>
    {
        IDeviceInformationStatics(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationStatics2>
    {
        IDeviceInformationStatics2(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationUpdate :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationUpdate>
    {
        IDeviceInformationUpdate(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceInformationUpdate2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceInformationUpdate2>
    {
        IDeviceInformationUpdate2(std::nullptr_t = nullptr) noexcept {}
        IDeviceInformationUpdate2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePairingRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePairingRequestedEventArgs>
    {
        IDevicePairingRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDevicePairingRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePairingRequestedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePairingRequestedEventArgs2>
    {
        IDevicePairingRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IDevicePairingRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePairingResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePairingResult>
    {
        IDevicePairingResult(std::nullptr_t = nullptr) noexcept {}
        IDevicePairingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePairingSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePairingSettings>
    {
        IDevicePairingSettings(std::nullptr_t = nullptr) noexcept {}
        IDevicePairingSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePicker :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePicker>
    {
        IDevicePicker(std::nullptr_t = nullptr) noexcept {}
        IDevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePickerAppearance :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePickerAppearance>
    {
        IDevicePickerAppearance(std::nullptr_t = nullptr) noexcept {}
        IDevicePickerAppearance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePickerFilter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePickerFilter>
    {
        IDevicePickerFilter(std::nullptr_t = nullptr) noexcept {}
        IDevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceSelectedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceSelectedEventArgs>
    {
        IDeviceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceUnpairingResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceUnpairingResult>
    {
        IDeviceUnpairingResult(std::nullptr_t = nullptr) noexcept {}
        IDeviceUnpairingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceWatcher>
    {
        IDeviceWatcher(std::nullptr_t = nullptr) noexcept {}
        IDeviceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceWatcher2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceWatcher2>
    {
        IDeviceWatcher2(std::nullptr_t = nullptr) noexcept {}
        IDeviceWatcher2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceWatcherEvent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceWatcherEvent>
    {
        IDeviceWatcherEvent(std::nullptr_t = nullptr) noexcept {}
        IDeviceWatcherEvent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceWatcherTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceWatcherTriggerDetails>
    {
        IDeviceWatcherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IDeviceWatcherTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEnclosureLocation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEnclosureLocation>
    {
        IEnclosureLocation(std::nullptr_t = nullptr) noexcept {}
        IEnclosureLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEnclosureLocation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEnclosureLocation2>,
        impl::require<llm::OS::Devices::Enumeration::IEnclosureLocation2, llm::OS::Devices::Enumeration::IEnclosureLocation>
    {
        IEnclosureLocation2(std::nullptr_t = nullptr) noexcept {}
        IEnclosureLocation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
