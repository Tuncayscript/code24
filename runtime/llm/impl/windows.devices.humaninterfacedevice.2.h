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
#ifndef LLM_OS_Devices_HumanInterfaceDevice_2_H
#define LLM_OS_Devices_HumanInterfaceDevice_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Devices.HumanInterfaceDevice.1.h"
LLM_EXPORT namespace llm::OS::Devices::HumanInterfaceDevice
{
    struct __declspec(empty_bases) HidBooleanControl : llm::OS::Devices::HumanInterfaceDevice::IHidBooleanControl
    {
        HidBooleanControl(std::nullptr_t) noexcept {}
        HidBooleanControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidBooleanControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidBooleanControlDescription : llm::OS::Devices::HumanInterfaceDevice::IHidBooleanControlDescription,
        impl::require<HidBooleanControlDescription, llm::OS::Devices::HumanInterfaceDevice::IHidBooleanControlDescription2>
    {
        HidBooleanControlDescription(std::nullptr_t) noexcept {}
        HidBooleanControlDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidBooleanControlDescription(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidCollection : llm::OS::Devices::HumanInterfaceDevice::IHidCollection
    {
        HidCollection(std::nullptr_t) noexcept {}
        HidCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidDevice : llm::OS::Devices::HumanInterfaceDevice::IHidDevice
    {
        HidDevice(std::nullptr_t) noexcept {}
        HidDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(uint16_t usagePage, uint16_t usageId);
        static auto GetDeviceSelector(uint16_t usagePage, uint16_t usageId, uint16_t vendorId, uint16_t productId);
        static auto FromIdAsync(param::hstring const& deviceId, llm::OS::Storage::FileAccessMode const& accessMode);
    };
    struct __declspec(empty_bases) HidFeatureReport : llm::OS::Devices::HumanInterfaceDevice::IHidFeatureReport
    {
        HidFeatureReport(std::nullptr_t) noexcept {}
        HidFeatureReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidFeatureReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidInputReport : llm::OS::Devices::HumanInterfaceDevice::IHidInputReport
    {
        HidInputReport(std::nullptr_t) noexcept {}
        HidInputReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidInputReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidInputReportReceivedEventArgs : llm::OS::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs
    {
        HidInputReportReceivedEventArgs(std::nullptr_t) noexcept {}
        HidInputReportReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidNumericControl : llm::OS::Devices::HumanInterfaceDevice::IHidNumericControl
    {
        HidNumericControl(std::nullptr_t) noexcept {}
        HidNumericControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidNumericControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidNumericControlDescription : llm::OS::Devices::HumanInterfaceDevice::IHidNumericControlDescription
    {
        HidNumericControlDescription(std::nullptr_t) noexcept {}
        HidNumericControlDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidNumericControlDescription(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidOutputReport : llm::OS::Devices::HumanInterfaceDevice::IHidOutputReport
    {
        HidOutputReport(std::nullptr_t) noexcept {}
        HidOutputReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::HumanInterfaceDevice::IHidOutputReport(ptr, take_ownership_from_abi) {}
    };
}
#endif
