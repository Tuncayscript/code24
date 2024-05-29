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
#ifndef LLM_OS_Devices_Bluetooth_Rfcomm_1_H
#define LLM_OS_Devices_Bluetooth_Rfcomm_1_H
#include "llm/impl/Windows.Devices.Bluetooth.Rfcomm.0.h"
LLM_EXPORT namespace llm::OS::Devices::Bluetooth::Rfcomm
{
    struct __declspec(empty_bases) IRfcommDeviceService :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceService>
    {
        IRfcommDeviceService(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceService(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommDeviceService2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceService2>,
        impl::require<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>
    {
        IRfcommDeviceService2(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceService2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommDeviceService3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceService3>,
        impl::require<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2>
    {
        IRfcommDeviceService3(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceService3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommDeviceServiceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceServiceStatics>
    {
        IRfcommDeviceServiceStatics(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceServiceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommDeviceServiceStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceServiceStatics2>,
        impl::require<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics>
    {
        IRfcommDeviceServiceStatics2(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceServiceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommDeviceServicesResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommDeviceServicesResult>
    {
        IRfcommDeviceServicesResult(std::nullptr_t = nullptr) noexcept {}
        IRfcommDeviceServicesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommServiceId :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommServiceId>
    {
        IRfcommServiceId(std::nullptr_t = nullptr) noexcept {}
        IRfcommServiceId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommServiceIdStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommServiceIdStatics>
    {
        IRfcommServiceIdStatics(std::nullptr_t = nullptr) noexcept {}
        IRfcommServiceIdStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommServiceProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommServiceProvider>
    {
        IRfcommServiceProvider(std::nullptr_t = nullptr) noexcept {}
        IRfcommServiceProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommServiceProvider2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommServiceProvider2>,
        impl::require<llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>
    {
        IRfcommServiceProvider2(std::nullptr_t = nullptr) noexcept {}
        IRfcommServiceProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IRfcommServiceProvider2, IRfcommServiceProvider2>::StartAdvertising;
        using impl::consume_t<IRfcommServiceProvider2, llm::OS::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>::StartAdvertising;
    };
    struct __declspec(empty_bases) IRfcommServiceProviderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommServiceProviderStatics>
    {
        IRfcommServiceProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IRfcommServiceProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
