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
#ifndef LLM_OS_System_RemoteDesktop_Provider_1_H
#define LLM_OS_System_RemoteDesktop_Provider_1_H
#include "llm/impl/Windows.System.RemoteDesktop.Provider.0.h"
LLM_EXPORT namespace llm:OS::System::RemoteDesktop::Provider
{
    struct __declspec(empty_bases) IPerformLocalActionRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPerformLocalActionRequestedEventArgs>
    {
        IPerformLocalActionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerformLocalActionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopConnectionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopConnectionInfo>
    {
        IRemoteDesktopConnectionInfo(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopConnectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopConnectionInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopConnectionInfoStatics>
    {
        IRemoteDesktopConnectionInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopConnectionInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopConnectionRemoteInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopConnectionRemoteInfo>
    {
        IRemoteDesktopConnectionRemoteInfo(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopConnectionRemoteInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopConnectionRemoteInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopConnectionRemoteInfoStatics>
    {
        IRemoteDesktopConnectionRemoteInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopConnectionRemoteInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopInfo>
    {
        IRemoteDesktopInfo(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopInfoFactory>
    {
        IRemoteDesktopInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteDesktopRegistrarStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteDesktopRegistrarStatics>
    {
        IRemoteDesktopRegistrarStatics(std::nullptr_t = nullptr) noexcept {}
        IRemoteDesktopRegistrarStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
