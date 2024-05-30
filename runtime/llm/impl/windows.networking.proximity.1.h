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
#ifndef LLM_OS_Networking_Proximity_1_H
#define LLM_OS_Networking_Proximity_1_H
#include "llm/impl/Windows.Networking.Proximity.0.h"
LLM_EXPORT namespace llm:OS::Networking::Proximity
{
    struct __declspec(empty_bases) IConnectionRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IConnectionRequestedEventArgs>
    {
        IConnectionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerFinderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerFinderStatics>
    {
        IPeerFinderStatics(std::nullptr_t = nullptr) noexcept {}
        IPeerFinderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerFinderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerFinderStatics2>
    {
        IPeerFinderStatics2(std::nullptr_t = nullptr) noexcept {}
        IPeerFinderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerInformation>
    {
        IPeerInformation(std::nullptr_t = nullptr) noexcept {}
        IPeerInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerInformation3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerInformation3>
    {
        IPeerInformation3(std::nullptr_t = nullptr) noexcept {}
        IPeerInformation3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerInformationWithHostAndService :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerInformationWithHostAndService>
    {
        IPeerInformationWithHostAndService(std::nullptr_t = nullptr) noexcept {}
        IPeerInformationWithHostAndService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPeerWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPeerWatcher>
    {
        IPeerWatcher(std::nullptr_t = nullptr) noexcept {}
        IPeerWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProximityDevice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProximityDevice>
    {
        IProximityDevice(std::nullptr_t = nullptr) noexcept {}
        IProximityDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProximityDeviceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProximityDeviceStatics>
    {
        IProximityDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IProximityDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProximityMessage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProximityMessage>
    {
        IProximityMessage(std::nullptr_t = nullptr) noexcept {}
        IProximityMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITriggeredConnectionStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITriggeredConnectionStateChangedEventArgs>
    {
        ITriggeredConnectionStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITriggeredConnectionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
