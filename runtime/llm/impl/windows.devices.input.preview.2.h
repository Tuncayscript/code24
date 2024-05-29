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
#ifndef LLM_OS_Devices_Input_Preview_2_H
#define LLM_OS_Devices_Input_Preview_2_H
#include "llm/impl/Windows.Devices.Input.Preview.1.h"
LLM_EXPORT namespace llm::OS::Devices::Input::Preview
{
    struct __declspec(empty_bases) GazeDevicePreview : llm::OS::Devices::Input::Preview::IGazeDevicePreview
    {
        GazeDevicePreview(std::nullptr_t) noexcept {}
        GazeDevicePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeDevicePreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeDeviceWatcherAddedPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs
    {
        GazeDeviceWatcherAddedPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeDeviceWatcherAddedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherAddedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeDeviceWatcherPreview : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview
    {
        GazeDeviceWatcherPreview(std::nullptr_t) noexcept {}
        GazeDeviceWatcherPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeDeviceWatcherRemovedPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs
    {
        GazeDeviceWatcherRemovedPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeDeviceWatcherRemovedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherRemovedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeDeviceWatcherUpdatedPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs
    {
        GazeDeviceWatcherUpdatedPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeDeviceWatcherUpdatedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeDeviceWatcherUpdatedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeEnteredPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs
    {
        GazeEnteredPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeEnteredPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeEnteredPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeExitedPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs
    {
        GazeExitedPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeExitedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeExitedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazeInputSourcePreview : llm::OS::Devices::Input::Preview::IGazeInputSourcePreview
    {
        GazeInputSourcePreview(std::nullptr_t) noexcept {}
        GazeInputSourcePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeInputSourcePreview(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto CreateWatcher();
    };
    struct __declspec(empty_bases) GazeMovedPreviewEventArgs : llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs
    {
        GazeMovedPreviewEventArgs(std::nullptr_t) noexcept {}
        GazeMovedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazeMovedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GazePointPreview : llm::OS::Devices::Input::Preview::IGazePointPreview
    {
        GazePointPreview(std::nullptr_t) noexcept {}
        GazePointPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::Preview::IGazePointPreview(ptr, take_ownership_from_abi) {}
    };
}
#endif
