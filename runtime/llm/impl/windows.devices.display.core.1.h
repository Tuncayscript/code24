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
#ifndef LLM_OS_Devices_Display_Core_1_H
#define LLM_OS_Devices_Display_Core_1_H
#include "llm/impl/Windows.Devices.Display.Core.0.h"
LLM_EXPORT namespace llm::OS::Devices::Display::Core
{
    struct __declspec(empty_bases) IDisplayAdapter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayAdapter>
    {
        IDisplayAdapter(std::nullptr_t = nullptr) noexcept {}
        IDisplayAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayAdapterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayAdapterStatics>
    {
        IDisplayAdapterStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayAdapterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayDevice>
    {
        IDisplayDevice(std::nullptr_t = nullptr) noexcept {}
        IDisplayDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayDevice2>
    {
        IDisplayDevice2(std::nullptr_t = nullptr) noexcept {}
        IDisplayDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayFence :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayFence>
    {
        IDisplayFence(std::nullptr_t = nullptr) noexcept {}
        IDisplayFence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManager>
    {
        IDisplayManager(std::nullptr_t = nullptr) noexcept {}
        IDisplayManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerChangedEventArgs>
    {
        IDisplayManagerChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerDisabledEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerDisabledEventArgs>
    {
        IDisplayManagerDisabledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerDisabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerEnabledEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerEnabledEventArgs>
    {
        IDisplayManagerEnabledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerEnabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerPathsFailedOrInvalidatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerPathsFailedOrInvalidatedEventArgs>
    {
        IDisplayManagerPathsFailedOrInvalidatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerPathsFailedOrInvalidatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerResultWithState :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerResultWithState>
    {
        IDisplayManagerResultWithState(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerResultWithState(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayManagerStatics>
    {
        IDisplayManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayModeInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayModeInfo>
    {
        IDisplayModeInfo(std::nullptr_t = nullptr) noexcept {}
        IDisplayModeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayModeInfo2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayModeInfo2>
    {
        IDisplayModeInfo2(std::nullptr_t = nullptr) noexcept {}
        IDisplayModeInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPath :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPath>
    {
        IDisplayPath(std::nullptr_t = nullptr) noexcept {}
        IDisplayPath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPath2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPath2>
    {
        IDisplayPath2(std::nullptr_t = nullptr) noexcept {}
        IDisplayPath2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPrimaryDescription :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPrimaryDescription>
    {
        IDisplayPrimaryDescription(std::nullptr_t = nullptr) noexcept {}
        IDisplayPrimaryDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPrimaryDescriptionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPrimaryDescriptionFactory>
    {
        IDisplayPrimaryDescriptionFactory(std::nullptr_t = nullptr) noexcept {}
        IDisplayPrimaryDescriptionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayPrimaryDescriptionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayPrimaryDescriptionStatics>
    {
        IDisplayPrimaryDescriptionStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayPrimaryDescriptionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayScanout :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayScanout>
    {
        IDisplayScanout(std::nullptr_t = nullptr) noexcept {}
        IDisplayScanout(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplaySource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplaySource>
    {
        IDisplaySource(std::nullptr_t = nullptr) noexcept {}
        IDisplaySource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplaySource2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplaySource2>
    {
        IDisplaySource2(std::nullptr_t = nullptr) noexcept {}
        IDisplaySource2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayState :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayState>
    {
        IDisplayState(std::nullptr_t = nullptr) noexcept {}
        IDisplayState(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayStateOperationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayStateOperationResult>
    {
        IDisplayStateOperationResult(std::nullptr_t = nullptr) noexcept {}
        IDisplayStateOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplaySurface :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplaySurface>
    {
        IDisplaySurface(std::nullptr_t = nullptr) noexcept {}
        IDisplaySurface(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTarget :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTarget>
    {
        IDisplayTarget(std::nullptr_t = nullptr) noexcept {}
        IDisplayTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTask :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTask>
    {
        IDisplayTask(std::nullptr_t = nullptr) noexcept {}
        IDisplayTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTask2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTask2>
    {
        IDisplayTask2(std::nullptr_t = nullptr) noexcept {}
        IDisplayTask2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTaskPool :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTaskPool>
    {
        IDisplayTaskPool(std::nullptr_t = nullptr) noexcept {}
        IDisplayTaskPool(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTaskPool2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTaskPool2>
    {
        IDisplayTaskPool2(std::nullptr_t = nullptr) noexcept {}
        IDisplayTaskPool2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayTaskResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayTaskResult>
    {
        IDisplayTaskResult(std::nullptr_t = nullptr) noexcept {}
        IDisplayTaskResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayView>
    {
        IDisplayView(std::nullptr_t = nullptr) noexcept {}
        IDisplayView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayWireFormat :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayWireFormat>
    {
        IDisplayWireFormat(std::nullptr_t = nullptr) noexcept {}
        IDisplayWireFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayWireFormatFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayWireFormatFactory>
    {
        IDisplayWireFormatFactory(std::nullptr_t = nullptr) noexcept {}
        IDisplayWireFormatFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayWireFormatStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayWireFormatStatics>
    {
        IDisplayWireFormatStatics(std::nullptr_t = nullptr) noexcept {}
        IDisplayWireFormatStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
