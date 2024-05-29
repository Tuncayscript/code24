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
#ifndef LLM_OS_Devices_HumanInterfaceDevice_1_H
#define LLM_OS_Devices_HumanInterfaceDevice_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.HumanInterfaceDevice.0.h"
LLM_EXPORT namespace llm::OS::Devices::HumanInterfaceDevice
{
    struct __declspec(empty_bases) IHidBooleanControl :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidBooleanControl>
    {
        IHidBooleanControl(std::nullptr_t = nullptr) noexcept {}
        IHidBooleanControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidBooleanControlDescription :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidBooleanControlDescription>
    {
        IHidBooleanControlDescription(std::nullptr_t = nullptr) noexcept {}
        IHidBooleanControlDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidBooleanControlDescription2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidBooleanControlDescription2>
    {
        IHidBooleanControlDescription2(std::nullptr_t = nullptr) noexcept {}
        IHidBooleanControlDescription2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidCollection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidCollection>
    {
        IHidCollection(std::nullptr_t = nullptr) noexcept {}
        IHidCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidDevice>,
        impl::require<llm::OS::Devices::HumanInterfaceDevice::IHidDevice, llm::OS::Foundation::IClosable>
    {
        IHidDevice(std::nullptr_t = nullptr) noexcept {}
        IHidDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidDeviceStatics>
    {
        IHidDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IHidDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidFeatureReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidFeatureReport>
    {
        IHidFeatureReport(std::nullptr_t = nullptr) noexcept {}
        IHidFeatureReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidInputReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidInputReport>
    {
        IHidInputReport(std::nullptr_t = nullptr) noexcept {}
        IHidInputReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidInputReportReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidInputReportReceivedEventArgs>
    {
        IHidInputReportReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHidInputReportReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidNumericControl :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidNumericControl>
    {
        IHidNumericControl(std::nullptr_t = nullptr) noexcept {}
        IHidNumericControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidNumericControlDescription :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidNumericControlDescription>
    {
        IHidNumericControlDescription(std::nullptr_t = nullptr) noexcept {}
        IHidNumericControlDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidOutputReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidOutputReport>
    {
        IHidOutputReport(std::nullptr_t = nullptr) noexcept {}
        IHidOutputReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
