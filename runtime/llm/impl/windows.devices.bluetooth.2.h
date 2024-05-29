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
#ifndef LLM_OS_Devices_Bluetooth_2_H
#define LLM_OS_Devices_Bluetooth_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Devices.Bluetooth.1.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth
{
    struct __declspec(empty_bases) BluetoothAdapter : llm::OS::Devices::Bluetooth::IBluetoothAdapter,
        impl::require<BluetoothAdapter, llm::OS::Devices::Bluetooth::IBluetoothAdapter2, llm::OS::Devices::Bluetooth::IBluetoothAdapter3>
    {
        BluetoothAdapter(std::nullptr_t) noexcept {}
        BluetoothAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothAdapter(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
    };
    struct __declspec(empty_bases) BluetoothClassOfDevice : llm::OS::Devices::Bluetooth::IBluetoothClassOfDevice
    {
        BluetoothClassOfDevice(std::nullptr_t) noexcept {}
        BluetoothClassOfDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothClassOfDevice(ptr, take_ownership_from_abi) {}
        static auto FromRawValue(uint32_t rawValue);
        static auto FromParts(llm::OS::Devices::Bluetooth::BluetoothMajorClass const& majorClass, llm::OS::Devices::Bluetooth::BluetoothMinorClass const& minorClass, llm::OS::Devices::Bluetooth::BluetoothServiceCapabilities const& serviceCapabilities);
    };
    struct __declspec(empty_bases) BluetoothDevice : llm::OS::Devices::Bluetooth::IBluetoothDevice,
        impl::require<BluetoothDevice, llm::OS::Devices::Bluetooth::IBluetoothDevice2, llm::OS::Devices::Bluetooth::IBluetoothDevice3, llm::OS::Devices::Bluetooth::IBluetoothDevice4, llm::OS::Devices::Bluetooth::IBluetoothDevice5, llm::OS::Foundation::IClosable>
    {
        BluetoothDevice(std::nullptr_t) noexcept {}
        BluetoothDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothDevice(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto FromHostNameAsync(llm::OS::Networking::HostName const& hostName);
        static auto FromBluetoothAddressAsync(uint64_t address);
        static auto GetDeviceSelector();
        static auto GetDeviceSelectorFromPairingState(bool pairingState);
        static auto GetDeviceSelectorFromConnectionStatus(llm::OS::Devices::Bluetooth::BluetoothConnectionStatus const& connectionStatus);
        static auto GetDeviceSelectorFromDeviceName(param::hstring const& deviceName);
        static auto GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress);
        static auto GetDeviceSelectorFromClassOfDevice(llm::OS::Devices::Bluetooth::BluetoothClassOfDevice const& classOfDevice);
    };
    struct __declspec(empty_bases) BluetoothDeviceId : llm::OS::Devices::Bluetooth::IBluetoothDeviceId
    {
        BluetoothDeviceId(std::nullptr_t) noexcept {}
        BluetoothDeviceId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothDeviceId(ptr, take_ownership_from_abi) {}
        static auto FromId(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) BluetoothLEAppearance : llm::OS::Devices::Bluetooth::IBluetoothLEAppearance
    {
        BluetoothLEAppearance(std::nullptr_t) noexcept {}
        BluetoothLEAppearance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEAppearance(ptr, take_ownership_from_abi) {}
        static auto FromRawValue(uint16_t rawValue);
        static auto FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory);
    };
    struct BluetoothLEAppearanceCategories
    {
        BluetoothLEAppearanceCategories() = delete;
        [[nodiscard]] static auto Uncategorized();
        [[nodiscard]] static auto Phone();
        [[nodiscard]] static auto Computer();
        [[nodiscard]] static auto Watch();
        [[nodiscard]] static auto Clock();
        [[nodiscard]] static auto Display();
        [[nodiscard]] static auto RemoteControl();
        [[nodiscard]] static auto EyeGlasses();
        [[nodiscard]] static auto Tag();
        [[nodiscard]] static auto Keyring();
        [[nodiscard]] static auto MediaPlayer();
        [[nodiscard]] static auto BarcodeScanner();
        [[nodiscard]] static auto Thermometer();
        [[nodiscard]] static auto HeartRate();
        [[nodiscard]] static auto BloodPressure();
        [[nodiscard]] static auto HumanInterfaceDevice();
        [[nodiscard]] static auto GlucoseMeter();
        [[nodiscard]] static auto RunningWalking();
        [[nodiscard]] static auto Cycling();
        [[nodiscard]] static auto PulseOximeter();
        [[nodiscard]] static auto WeightScale();
        [[nodiscard]] static auto OutdoorSportActivity();
    };
    struct BluetoothLEAppearanceSubcategories
    {
        BluetoothLEAppearanceSubcategories() = delete;
        [[nodiscard]] static auto Generic();
        [[nodiscard]] static auto SportsWatch();
        [[nodiscard]] static auto ThermometerEar();
        [[nodiscard]] static auto HeartRateBelt();
        [[nodiscard]] static auto BloodPressureArm();
        [[nodiscard]] static auto BloodPressureWrist();
        [[nodiscard]] static auto Keyboard();
        [[nodiscard]] static auto Mouse();
        [[nodiscard]] static auto Joystick();
        [[nodiscard]] static auto Gamepad();
        [[nodiscard]] static auto DigitizerTablet();
        [[nodiscard]] static auto CardReader();
        [[nodiscard]] static auto DigitalPen();
        [[nodiscard]] static auto BarcodeScanner();
        [[nodiscard]] static auto RunningWalkingInShoe();
        [[nodiscard]] static auto RunningWalkingOnShoe();
        [[nodiscard]] static auto RunningWalkingOnHip();
        [[nodiscard]] static auto CyclingComputer();
        [[nodiscard]] static auto CyclingSpeedSensor();
        [[nodiscard]] static auto CyclingCadenceSensor();
        [[nodiscard]] static auto CyclingPowerSensor();
        [[nodiscard]] static auto CyclingSpeedCadenceSensor();
        [[nodiscard]] static auto OximeterFingertip();
        [[nodiscard]] static auto OximeterWristWorn();
        [[nodiscard]] static auto LocationDisplay();
        [[nodiscard]] static auto LocationNavigationDisplay();
        [[nodiscard]] static auto LocationPod();
        [[nodiscard]] static auto LocationNavigationPod();
    };
    struct __declspec(empty_bases) BluetoothLEConnectionParameters : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionParameters
    {
        BluetoothLEConnectionParameters(std::nullptr_t) noexcept {}
        BluetoothLEConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionParameters(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEConnectionPhy : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionPhy
    {
        BluetoothLEConnectionPhy(std::nullptr_t) noexcept {}
        BluetoothLEConnectionPhy(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionPhy(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEConnectionPhyInfo : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionPhyInfo
    {
        BluetoothLEConnectionPhyInfo(std::nullptr_t) noexcept {}
        BluetoothLEConnectionPhyInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEConnectionPhyInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothLEDevice : llm::OS::Devices::Bluetooth::IBluetoothLEDevice,
        impl::require<BluetoothLEDevice, llm::OS::Devices::Bluetooth::IBluetoothLEDevice2, llm::OS::Devices::Bluetooth::IBluetoothLEDevice3, llm::OS::Devices::Bluetooth::IBluetoothLEDevice4, llm::OS::Devices::Bluetooth::IBluetoothLEDevice5, llm::OS::Devices::Bluetooth::IBluetoothLEDevice6, llm::OS::Foundation::IClosable>
    {
        BluetoothLEDevice(std::nullptr_t) noexcept {}
        BluetoothLEDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEDevice(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto FromBluetoothAddressAsync(uint64_t bluetoothAddress);
        static auto GetDeviceSelector();
        static auto GetDeviceSelectorFromPairingState(bool pairingState);
        static auto GetDeviceSelectorFromConnectionStatus(llm::OS::Devices::Bluetooth::BluetoothConnectionStatus const& connectionStatus);
        static auto GetDeviceSelectorFromDeviceName(param::hstring const& deviceName);
        static auto GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress);
        static auto GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, llm::OS::Devices::Bluetooth::BluetoothAddressType const& bluetoothAddressType);
        static auto GetDeviceSelectorFromAppearance(llm::OS::Devices::Bluetooth::BluetoothLEAppearance const& appearance);
        static auto FromBluetoothAddressAsync(uint64_t bluetoothAddress, llm::OS::Devices::Bluetooth::BluetoothAddressType const& bluetoothAddressType);
    };
    struct __declspec(empty_bases) BluetoothLEPreferredConnectionParameters : llm::OS::Devices::Bluetooth::IBluetoothLEPreferredConnectionParameters
    {
        BluetoothLEPreferredConnectionParameters(std::nullptr_t) noexcept {}
        BluetoothLEPreferredConnectionParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEPreferredConnectionParameters(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Balanced();
        [[nodiscard]] static auto ThroughputOptimized();
        [[nodiscard]] static auto PowerOptimized();
    };
    struct __declspec(empty_bases) BluetoothLEPreferredConnectionParametersRequest : llm::OS::Devices::Bluetooth::IBluetoothLEPreferredConnectionParametersRequest,
        impl::require<BluetoothLEPreferredConnectionParametersRequest, llm::OS::Foundation::IClosable>
    {
        BluetoothLEPreferredConnectionParametersRequest(std::nullptr_t) noexcept {}
        BluetoothLEPreferredConnectionParametersRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothLEPreferredConnectionParametersRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BluetoothSignalStrengthFilter : llm::OS::Devices::Bluetooth::IBluetoothSignalStrengthFilter
    {
        BluetoothSignalStrengthFilter(std::nullptr_t) noexcept {}
        BluetoothSignalStrengthFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Bluetooth::IBluetoothSignalStrengthFilter(ptr, take_ownership_from_abi) {}
        BluetoothSignalStrengthFilter();
    };
    struct BluetoothUuidHelper
    {
        BluetoothUuidHelper() = delete;
        static auto FromShortId(uint32_t shortId);
        static auto TryGetShortId(llm::guid const& uuid);
    };
}
#endif
