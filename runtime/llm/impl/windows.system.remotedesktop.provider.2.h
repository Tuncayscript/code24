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
#ifndef LLM_OS_System_RemoteDesktop_Provider_2_H
#define LLM_OS_System_RemoteDesktop_Provider_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.System.RemoteDesktop.Provider.1.h"
LLM_EXPORT namespace llm:OS::System::RemoteDesktop::Provider
{
    struct __declspec(empty_bases) PerformLocalActionRequestedEventArgs : llm:OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs
    {
        PerformLocalActionRequestedEventArgs(std::nullptr_t) noexcept {}
        PerformLocalActionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteDesktopConnectionInfo : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo
    {
        RemoteDesktopConnectionInfo(std::nullptr_t) noexcept {}
        RemoteDesktopConnectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo(ptr, take_ownership_from_abi) {}
        static auto GetForLaunchUri(llm:OS::Foundation::Uri const& launchUri, llm:OS::UI::WindowId const& windowId);
    };
    struct __declspec(empty_bases) RemoteDesktopConnectionRemoteInfo : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo,
        impl::require<RemoteDesktopConnectionRemoteInfo, llm:OS::Foundation::IClosable>
    {
        RemoteDesktopConnectionRemoteInfo(std::nullptr_t) noexcept {}
        RemoteDesktopConnectionRemoteInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo(ptr, take_ownership_from_abi) {}
        static auto IsSwitchSupported();
        static auto GetForLaunchUri(llm:OS::Foundation::Uri const& launchUri);
    };
    struct __declspec(empty_bases) RemoteDesktopInfo : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo
    {
        RemoteDesktopInfo(std::nullptr_t) noexcept {}
        RemoteDesktopInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo(ptr, take_ownership_from_abi) {}
        RemoteDesktopInfo(param::hstring const& id, param::hstring const& displayName);
    };
    struct RemoteDesktopRegistrar
    {
        RemoteDesktopRegistrar() = delete;
        [[nodiscard]] static auto DesktopInfos();
        static auto IsSwitchToLocalSessionEnabled();
    };
}
#endif
