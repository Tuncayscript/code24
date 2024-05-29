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
#ifndef LLM_OS_Devices_Bluetooth_1_H
#define LLM_OS_Devices_Bluetooth_1_H
#include "llm/impl/Windows.Devices.Bluetooth.0.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth
{
    struct __declspec(empty_bases) IBluetoothAdapter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothAdapter>
    {
        IBluetoothAdapter(std::nullptr_t = nullptr) noexcept {}
        IBluetoothAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothAdapter2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothAdapter2>
    {
        IBluetoothAdapter2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothAdapter2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothAdapter3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothAdapter3>
    {
        IBluetoothAdapter3(std::nullptr_t = nullptr) noexcept {}
        IBluetoothAdapter3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothAdapterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothAdapterStatics>
    {
        IBluetoothAdapterStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothAdapterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothClassOfDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothClassOfDevice>
    {
        IBluetoothClassOfDevice(std::nullptr_t = nullptr) noexcept {}
        IBluetoothClassOfDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothClassOfDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothClassOfDeviceStatics>
    {
        IBluetoothClassOfDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothClassOfDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDevice>
    {
        IBluetoothDevice(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDevice2>
    {
        IBluetoothDevice2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDevice3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDevice3>
    {
        IBluetoothDevice3(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDevice3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDevice4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDevice4>
    {
        IBluetoothDevice4(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDevice4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDevice5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDevice5>
    {
        IBluetoothDevice5(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDevice5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDeviceId :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDeviceId>
    {
        IBluetoothDeviceId(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDeviceId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDeviceIdStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDeviceIdStatics>
    {
        IBluetoothDeviceIdStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDeviceIdStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDeviceStatics>
    {
        IBluetoothDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothDeviceStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothDeviceStatics2>
    {
        IBluetoothDeviceStatics2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothDeviceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAppearance :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAppearance>
    {
        IBluetoothLEAppearance(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAppearance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAppearanceCategoriesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAppearanceCategoriesStatics>
    {
        IBluetoothLEAppearanceCategoriesStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAppearanceCategoriesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAppearanceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAppearanceStatics>
    {
        IBluetoothLEAppearanceStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAppearanceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAppearanceSubcategoriesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAppearanceSubcategoriesStatics>
    {
        IBluetoothLEAppearanceSubcategoriesStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAppearanceSubcategoriesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEConnectionParameters :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEConnectionParameters>
    {
        IBluetoothLEConnectionParameters(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEConnectionPhy :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEConnectionPhy>
    {
        IBluetoothLEConnectionPhy(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEConnectionPhy(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEConnectionPhyInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEConnectionPhyInfo>
    {
        IBluetoothLEConnectionPhyInfo(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEConnectionPhyInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice>
    {
        IBluetoothLEDevice(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice2>
    {
        IBluetoothLEDevice2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice3>
    {
        IBluetoothLEDevice3(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice4>
    {
        IBluetoothLEDevice4(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice5>
    {
        IBluetoothLEDevice5(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDevice6 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDevice6>
    {
        IBluetoothLEDevice6(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDevice6(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDeviceStatics>
    {
        IBluetoothLEDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEDeviceStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEDeviceStatics2>
    {
        IBluetoothLEDeviceStatics2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEDeviceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEPreferredConnectionParameters :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEPreferredConnectionParameters>
    {
        IBluetoothLEPreferredConnectionParameters(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEPreferredConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEPreferredConnectionParametersRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEPreferredConnectionParametersRequest>
    {
        IBluetoothLEPreferredConnectionParametersRequest(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEPreferredConnectionParametersRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEPreferredConnectionParametersStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEPreferredConnectionParametersStatics>
    {
        IBluetoothLEPreferredConnectionParametersStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEPreferredConnectionParametersStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothSignalStrengthFilter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothSignalStrengthFilter>
    {
        IBluetoothSignalStrengthFilter(std::nullptr_t = nullptr) noexcept {}
        IBluetoothSignalStrengthFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothUuidHelperStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothUuidHelperStatics>
    {
        IBluetoothUuidHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IBluetoothUuidHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
