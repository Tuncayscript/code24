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
#ifndef LLM_OS_Devices_Bluetooth_Rfcomm_2_H
#define LLM_OS_Devices_Bluetooth_Rfcomm_2_H
#include "llm/impl/Windows.Devices.Bluetooth.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Bluetooth.Rfcomm.1.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Rfcomm
{
    struct __declspec(empty_bases) RfcommDeviceService : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService,
        impl::require<RfcommDeviceService, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2, llm::OS::Foundation::IClosable, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>
    {
        RfcommDeviceService(std::nullptr_t) noexcept {}
        RfcommDeviceService(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId);
        static auto GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice);
        static auto GetDeviceSelectorForBluetoothDevice(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode);
        static auto GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId);
        static auto GetDeviceSelectorForBluetoothDeviceAndServiceId(llm::OS::Devices::Bluetooth::BluetoothDevice const& bluetoothDevice, llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId, llm::OS::Devices::Bluetooth::BluetoothCacheMode const& cacheMode);
    };
    struct __declspec(empty_bases) RfcommDeviceServicesResult : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult
    {
        RfcommDeviceServicesResult(std::nullptr_t) noexcept {}
        RfcommDeviceServicesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RfcommServiceId : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId
    {
        RfcommServiceId(std::nullptr_t) noexcept {}
        RfcommServiceId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceId(ptr, take_ownership_from_abi) {}
        static auto FromUuid(llm::guid const& uuid);
        static auto FromShortId(uint32_t shortId);
        [[nodiscard]] static auto SerialPort();
        [[nodiscard]] static auto ObexObjectPush();
        [[nodiscard]] static auto ObexFileTransfer();
        [[nodiscard]] static auto PhoneBookAccessPce();
        [[nodiscard]] static auto PhoneBookAccessPse();
        [[nodiscard]] static auto GenericFileTransfer();
    };
    struct __declspec(empty_bases) RfcommServiceProvider : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider,
        impl::require<RfcommServiceProvider, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>
    {
        RfcommServiceProvider(std::nullptr_t) noexcept {}
        RfcommServiceProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider::StartAdvertising;
        using impl::consume_t<RfcommServiceProvider, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>::StartAdvertising;
        static auto CreateAsync(llm::OS::Devices::Bluetooth::Rfcomm::RfcommServiceId const& serviceId);
    };
}
#endif
