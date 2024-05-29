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
#ifndef LLM_OS_Devices_Usb_1_H
#define LLM_OS_Devices_Usb_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Usb.0.h"
LLM_EXPORT namespace llm::OS::Devices::Usb
{
    struct __declspec(empty_bases) IUsbBulkInEndpointDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbBulkInEndpointDescriptor>
    {
        IUsbBulkInEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbBulkInEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbBulkInPipe :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbBulkInPipe>
    {
        IUsbBulkInPipe(std::nullptr_t = nullptr) noexcept {}
        IUsbBulkInPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbBulkOutEndpointDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbBulkOutEndpointDescriptor>
    {
        IUsbBulkOutEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbBulkOutEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbBulkOutPipe :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbBulkOutPipe>
    {
        IUsbBulkOutPipe(std::nullptr_t = nullptr) noexcept {}
        IUsbBulkOutPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbConfiguration>
    {
        IUsbConfiguration(std::nullptr_t = nullptr) noexcept {}
        IUsbConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbConfigurationDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbConfigurationDescriptor>
    {
        IUsbConfigurationDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbConfigurationDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbConfigurationDescriptorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbConfigurationDescriptorStatics>
    {
        IUsbConfigurationDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
        IUsbConfigurationDescriptorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbControlRequestType :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbControlRequestType>
    {
        IUsbControlRequestType(std::nullptr_t = nullptr) noexcept {}
        IUsbControlRequestType(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDescriptor>
    {
        IUsbDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDevice>,
        impl::require<llm::OS::Devices::Usb::IUsbDevice, llm::OS::Foundation::IClosable>
    {
        IUsbDevice(std::nullptr_t = nullptr) noexcept {}
        IUsbDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDeviceClass :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDeviceClass>
    {
        IUsbDeviceClass(std::nullptr_t = nullptr) noexcept {}
        IUsbDeviceClass(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDeviceClasses :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDeviceClasses>
    {
        IUsbDeviceClasses(std::nullptr_t = nullptr) noexcept {}
        IUsbDeviceClasses(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDeviceClassesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDeviceClassesStatics>
    {
        IUsbDeviceClassesStatics(std::nullptr_t = nullptr) noexcept {}
        IUsbDeviceClassesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDeviceDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDeviceDescriptor>
    {
        IUsbDeviceDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbDeviceDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbDeviceStatics>
    {
        IUsbDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IUsbDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbEndpointDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbEndpointDescriptor>
    {
        IUsbEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbEndpointDescriptorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbEndpointDescriptorStatics>
    {
        IUsbEndpointDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
        IUsbEndpointDescriptorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterface :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterface>
    {
        IUsbInterface(std::nullptr_t = nullptr) noexcept {}
        IUsbInterface(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterfaceDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterfaceDescriptor>
    {
        IUsbInterfaceDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbInterfaceDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterfaceDescriptorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterfaceDescriptorStatics>
    {
        IUsbInterfaceDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
        IUsbInterfaceDescriptorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterfaceSetting :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterfaceSetting>
    {
        IUsbInterfaceSetting(std::nullptr_t = nullptr) noexcept {}
        IUsbInterfaceSetting(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterruptInEndpointDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterruptInEndpointDescriptor>
    {
        IUsbInterruptInEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbInterruptInEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterruptInEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterruptInEventArgs>
    {
        IUsbInterruptInEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUsbInterruptInEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterruptInPipe :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterruptInPipe>
    {
        IUsbInterruptInPipe(std::nullptr_t = nullptr) noexcept {}
        IUsbInterruptInPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterruptOutEndpointDescriptor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterruptOutEndpointDescriptor>
    {
        IUsbInterruptOutEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
        IUsbInterruptOutEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbInterruptOutPipe :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbInterruptOutPipe>
    {
        IUsbInterruptOutPipe(std::nullptr_t = nullptr) noexcept {}
        IUsbInterruptOutPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbSetupPacket :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbSetupPacket>
    {
        IUsbSetupPacket(std::nullptr_t = nullptr) noexcept {}
        IUsbSetupPacket(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUsbSetupPacketFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUsbSetupPacketFactory>
    {
        IUsbSetupPacketFactory(std::nullptr_t = nullptr) noexcept {}
        IUsbSetupPacketFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
