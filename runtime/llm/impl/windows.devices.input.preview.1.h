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
#ifndef LLM_OS_Devices_Input_Preview_1_H
#define LLM_OS_Devices_Input_Preview_1_H
#include "llm/impl/Windows.Devices.Input.Preview.0.h"
LLM_EXPORT namespace llm::OS::Devices::Input::Preview
{
    struct __declspec(empty_bases) IGazeDevicePreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeDevicePreview>
    {
        IGazeDevicePreview(std::nullptr_t = nullptr) noexcept {}
        IGazeDevicePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeDeviceWatcherAddedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeDeviceWatcherAddedPreviewEventArgs>
    {
        IGazeDeviceWatcherAddedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeDeviceWatcherAddedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeDeviceWatcherPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeDeviceWatcherPreview>
    {
        IGazeDeviceWatcherPreview(std::nullptr_t = nullptr) noexcept {}
        IGazeDeviceWatcherPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeDeviceWatcherRemovedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeDeviceWatcherRemovedPreviewEventArgs>
    {
        IGazeDeviceWatcherRemovedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeDeviceWatcherRemovedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeDeviceWatcherUpdatedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeDeviceWatcherUpdatedPreviewEventArgs>
    {
        IGazeDeviceWatcherUpdatedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeDeviceWatcherUpdatedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeEnteredPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeEnteredPreviewEventArgs>
    {
        IGazeEnteredPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeEnteredPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeExitedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeExitedPreviewEventArgs>
    {
        IGazeExitedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeExitedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeInputSourcePreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeInputSourcePreview>
    {
        IGazeInputSourcePreview(std::nullptr_t = nullptr) noexcept {}
        IGazeInputSourcePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeInputSourcePreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeInputSourcePreviewStatics>
    {
        IGazeInputSourcePreviewStatics(std::nullptr_t = nullptr) noexcept {}
        IGazeInputSourcePreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazeMovedPreviewEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazeMovedPreviewEventArgs>
    {
        IGazeMovedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGazeMovedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGazePointPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGazePointPreview>
    {
        IGazePointPreview(std::nullptr_t = nullptr) noexcept {}
        IGazePointPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
