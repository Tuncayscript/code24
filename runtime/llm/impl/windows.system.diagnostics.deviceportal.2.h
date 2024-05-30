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
#ifndef LLM_OS_System_Diagnostics_DevicePortal_2_H
#define LLM_OS_System_Diagnostics_DevicePortal_2_H
#include "llm/impl/Windows.ApplicationModel.AppService.1.h"
#include "llm/impl/Windows.System.Diagnostics.DevicePortal.1.h"
LLM_EXPORT namespace llm:OS::System::Diagnostics::DevicePortal
{
    struct __declspec(empty_bases) DevicePortalConnection : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection,
        impl::require<DevicePortalConnection, llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        DevicePortalConnection(std::nullptr_t) noexcept {}
        DevicePortalConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection(ptr, take_ownership_from_abi) {}
        static auto GetForAppServiceConnection(llm:OS::ApplicationModel::AppService::AppServiceConnection const& appServiceConnection);
    };
    struct __declspec(empty_bases) DevicePortalConnectionClosedEventArgs : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs
    {
        DevicePortalConnectionClosedEventArgs(std::nullptr_t) noexcept {}
        DevicePortalConnectionClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePortalConnectionRequestReceivedEventArgs : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs,
        impl::require<DevicePortalConnectionRequestReceivedEventArgs, llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        DevicePortalConnectionRequestReceivedEventArgs(std::nullptr_t) noexcept {}
        DevicePortalConnectionRequestReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
