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
#ifndef LLM_OS_System_Diagnostics_DevicePortal_1_H
#define LLM_OS_System_Diagnostics_DevicePortal_1_H
#include "llm/impl/Windows.System.Diagnostics.DevicePortal.0.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics::DevicePortal
{
    struct __declspec(empty_bases) IDevicePortalConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalConnection>
    {
        IDevicePortalConnection(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePortalConnectionClosedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalConnectionClosedEventArgs>
    {
        IDevicePortalConnectionClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalConnectionClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePortalConnectionRequestReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalConnectionRequestReceivedEventArgs>
    {
        IDevicePortalConnectionRequestReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalConnectionRequestReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePortalConnectionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalConnectionStatics>
    {
        IDevicePortalConnectionStatics(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalConnectionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePortalWebSocketConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalWebSocketConnection>
    {
        IDevicePortalWebSocketConnection(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalWebSocketConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePortalWebSocketConnectionRequestReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        IDevicePortalWebSocketConnectionRequestReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDevicePortalWebSocketConnectionRequestReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
