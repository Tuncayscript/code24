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
#ifndef LLM_OS_Devices_Usb_2_H
#define LLM_OS_Devices_Usb_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.Usb.1.h"
LLM_EXPORT namespace llm::OS::Devices::Usb
{
    struct __declspec(empty_bases) UsbBulkInEndpointDescriptor : llm::OS::Devices::Usb::IUsbBulkInEndpointDescriptor
    {
        UsbBulkInEndpointDescriptor(std::nullptr_t) noexcept {}
        UsbBulkInEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbBulkInEndpointDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbBulkInPipe : llm::OS::Devices::Usb::IUsbBulkInPipe
    {
        UsbBulkInPipe(std::nullptr_t) noexcept {}
        UsbBulkInPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbBulkInPipe(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbBulkOutEndpointDescriptor : llm::OS::Devices::Usb::IUsbBulkOutEndpointDescriptor
    {
        UsbBulkOutEndpointDescriptor(std::nullptr_t) noexcept {}
        UsbBulkOutEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbBulkOutEndpointDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbBulkOutPipe : llm::OS::Devices::Usb::IUsbBulkOutPipe
    {
        UsbBulkOutPipe(std::nullptr_t) noexcept {}
        UsbBulkOutPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbBulkOutPipe(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbConfiguration : llm::OS::Devices::Usb::IUsbConfiguration
    {
        UsbConfiguration(std::nullptr_t) noexcept {}
        UsbConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbConfigurationDescriptor : llm::OS::Devices::Usb::IUsbConfigurationDescriptor
    {
        UsbConfigurationDescriptor(std::nullptr_t) noexcept {}
        UsbConfigurationDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbConfigurationDescriptor(ptr, take_ownership_from_abi) {}
        static auto TryParse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor, llm::OS::Devices::Usb::UsbConfigurationDescriptor& parsed);
        static auto Parse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor);
    };
    struct __declspec(empty_bases) UsbControlRequestType : llm::OS::Devices::Usb::IUsbControlRequestType
    {
        UsbControlRequestType(std::nullptr_t) noexcept {}
        UsbControlRequestType(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbControlRequestType(ptr, take_ownership_from_abi) {}
        UsbControlRequestType();
    };
    struct __declspec(empty_bases) UsbDescriptor : llm::OS::Devices::Usb::IUsbDescriptor
    {
        UsbDescriptor(std::nullptr_t) noexcept {}
        UsbDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbDevice : llm::OS::Devices::Usb::IUsbDevice
    {
        UsbDevice(std::nullptr_t) noexcept {}
        UsbDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(uint32_t vendorId, uint32_t productId, llm::guid const& winUsbInterfaceClass);
        static auto GetDeviceSelector(llm::guid const& winUsbInterfaceClass);
        static auto GetDeviceSelector(uint32_t vendorId, uint32_t productId);
        static auto GetDeviceClassSelector(llm::OS::Devices::Usb::UsbDeviceClass const& usbClass);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) UsbDeviceClass : llm::OS::Devices::Usb::IUsbDeviceClass
    {
        UsbDeviceClass(std::nullptr_t) noexcept {}
        UsbDeviceClass(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbDeviceClass(ptr, take_ownership_from_abi) {}
        UsbDeviceClass();
    };
    struct __declspec(empty_bases) UsbDeviceClasses : llm::OS::Devices::Usb::IUsbDeviceClasses
    {
        UsbDeviceClasses(std::nullptr_t) noexcept {}
        UsbDeviceClasses(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbDeviceClasses(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto CdcControl();
        [[nodiscard]] static auto Physical();
        [[nodiscard]] static auto PersonalHealthcare();
        [[nodiscard]] static auto ActiveSync();
        [[nodiscard]] static auto PalmSync();
        [[nodiscard]] static auto DeviceFirmwareUpdate();
        [[nodiscard]] static auto Irda();
        [[nodiscard]] static auto Measurement();
        [[nodiscard]] static auto VendorSpecific();
    };
    struct __declspec(empty_bases) UsbDeviceDescriptor : llm::OS::Devices::Usb::IUsbDeviceDescriptor
    {
        UsbDeviceDescriptor(std::nullptr_t) noexcept {}
        UsbDeviceDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbDeviceDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbEndpointDescriptor : llm::OS::Devices::Usb::IUsbEndpointDescriptor
    {
        UsbEndpointDescriptor(std::nullptr_t) noexcept {}
        UsbEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbEndpointDescriptor(ptr, take_ownership_from_abi) {}
        static auto TryParse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor, llm::OS::Devices::Usb::UsbEndpointDescriptor& parsed);
        static auto Parse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor);
    };
    struct __declspec(empty_bases) UsbInterface : llm::OS::Devices::Usb::IUsbInterface
    {
        UsbInterface(std::nullptr_t) noexcept {}
        UsbInterface(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterface(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterfaceDescriptor : llm::OS::Devices::Usb::IUsbInterfaceDescriptor
    {
        UsbInterfaceDescriptor(std::nullptr_t) noexcept {}
        UsbInterfaceDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterfaceDescriptor(ptr, take_ownership_from_abi) {}
        static auto TryParse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor, llm::OS::Devices::Usb::UsbInterfaceDescriptor& parsed);
        static auto Parse(llm::OS::Devices::Usb::UsbDescriptor const& descriptor);
    };
    struct __declspec(empty_bases) UsbInterfaceSetting : llm::OS::Devices::Usb::IUsbInterfaceSetting
    {
        UsbInterfaceSetting(std::nullptr_t) noexcept {}
        UsbInterfaceSetting(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterfaceSetting(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterruptInEndpointDescriptor : llm::OS::Devices::Usb::IUsbInterruptInEndpointDescriptor
    {
        UsbInterruptInEndpointDescriptor(std::nullptr_t) noexcept {}
        UsbInterruptInEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterruptInEndpointDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterruptInEventArgs : llm::OS::Devices::Usb::IUsbInterruptInEventArgs
    {
        UsbInterruptInEventArgs(std::nullptr_t) noexcept {}
        UsbInterruptInEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterruptInEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterruptInPipe : llm::OS::Devices::Usb::IUsbInterruptInPipe
    {
        UsbInterruptInPipe(std::nullptr_t) noexcept {}
        UsbInterruptInPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterruptInPipe(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterruptOutEndpointDescriptor : llm::OS::Devices::Usb::IUsbInterruptOutEndpointDescriptor
    {
        UsbInterruptOutEndpointDescriptor(std::nullptr_t) noexcept {}
        UsbInterruptOutEndpointDescriptor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterruptOutEndpointDescriptor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbInterruptOutPipe : llm::OS::Devices::Usb::IUsbInterruptOutPipe
    {
        UsbInterruptOutPipe(std::nullptr_t) noexcept {}
        UsbInterruptOutPipe(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbInterruptOutPipe(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UsbSetupPacket : llm::OS::Devices::Usb::IUsbSetupPacket
    {
        UsbSetupPacket(std::nullptr_t) noexcept {}
        UsbSetupPacket(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Usb::IUsbSetupPacket(ptr, take_ownership_from_abi) {}
        UsbSetupPacket();
        explicit UsbSetupPacket(llm::OS::Storage::Streams::IBuffer const& eightByteBuffer);
    };
}
#endif
