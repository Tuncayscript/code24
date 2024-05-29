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
#ifndef LLM_OS_Devices_Display_Core_2_H
#define LLM_OS_Devices_Display_Core_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Devices.Display.Core.1.h"
LLM_EXPORT namespace llm::OS::Devices::Display::Core
{
    struct DisplayPresentationRate
    {
        llm::OS::Foundation::Numerics::Rational VerticalSyncRate;
        int32_t VerticalSyncsPerPresentation;
    };
    inline bool operator==(DisplayPresentationRate const& left, DisplayPresentationRate const& right) noexcept
    {
        return left.VerticalSyncRate == right.VerticalSyncRate && left.VerticalSyncsPerPresentation == right.VerticalSyncsPerPresentation;
    }
    inline bool operator!=(DisplayPresentationRate const& left, DisplayPresentationRate const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) DisplayAdapter : llm::OS::Devices::Display::Core::IDisplayAdapter
    {
        DisplayAdapter(std::nullptr_t) noexcept {}
        DisplayAdapter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayAdapter(ptr, take_ownership_from_abi) {}
        static auto FromId(llm::OS::Graphics::DisplayAdapterId const& id);
    };
    struct __declspec(empty_bases) DisplayDevice : llm::OS::Devices::Display::Core::IDisplayDevice,
        impl::require<DisplayDevice, llm::OS::Devices::Display::Core::IDisplayDevice2>
    {
        DisplayDevice(std::nullptr_t) noexcept {}
        DisplayDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayDevice(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayFence : llm::OS::Devices::Display::Core::IDisplayFence
    {
        DisplayFence(std::nullptr_t) noexcept {}
        DisplayFence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayFence(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayManager : llm::OS::Devices::Display::Core::IDisplayManager,
        impl::require<DisplayManager, llm::OS::Foundation::IClosable>
    {
        DisplayManager(std::nullptr_t) noexcept {}
        DisplayManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManager(ptr, take_ownership_from_abi) {}
        static auto Create(llm::OS::Devices::Display::Core::DisplayManagerOptions const& options);
    };
    struct __declspec(empty_bases) DisplayManagerChangedEventArgs : llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs
    {
        DisplayManagerChangedEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayManagerDisabledEventArgs : llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs
    {
        DisplayManagerDisabledEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerDisabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayManagerEnabledEventArgs : llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs
    {
        DisplayManagerEnabledEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerEnabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayManagerPathsFailedOrInvalidatedEventArgs : llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs
    {
        DisplayManagerPathsFailedOrInvalidatedEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerPathsFailedOrInvalidatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayManagerResultWithState : llm::OS::Devices::Display::Core::IDisplayManagerResultWithState
    {
        DisplayManagerResultWithState(std::nullptr_t) noexcept {}
        DisplayManagerResultWithState(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayManagerResultWithState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayModeInfo : llm::OS::Devices::Display::Core::IDisplayModeInfo,
        impl::require<DisplayModeInfo, llm::OS::Devices::Display::Core::IDisplayModeInfo2>
    {
        DisplayModeInfo(std::nullptr_t) noexcept {}
        DisplayModeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayModeInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayPath : llm::OS::Devices::Display::Core::IDisplayPath,
        impl::require<DisplayPath, llm::OS::Devices::Display::Core::IDisplayPath2>
    {
        DisplayPath(std::nullptr_t) noexcept {}
        DisplayPath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayPath(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayPrimaryDescription : llm::OS::Devices::Display::Core::IDisplayPrimaryDescription
    {
        DisplayPrimaryDescription(std::nullptr_t) noexcept {}
        DisplayPrimaryDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayPrimaryDescription(ptr, take_ownership_from_abi) {}
        DisplayPrimaryDescription(uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription);
        static auto CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription);
    };
    struct __declspec(empty_bases) DisplayScanout : llm::OS::Devices::Display::Core::IDisplayScanout
    {
        DisplayScanout(std::nullptr_t) noexcept {}
        DisplayScanout(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayScanout(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplaySource : llm::OS::Devices::Display::Core::IDisplaySource,
        impl::require<DisplaySource, llm::OS::Devices::Display::Core::IDisplaySource2>
    {
        DisplaySource(std::nullptr_t) noexcept {}
        DisplaySource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplaySource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayState : llm::OS::Devices::Display::Core::IDisplayState
    {
        DisplayState(std::nullptr_t) noexcept {}
        DisplayState(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayStateOperationResult : llm::OS::Devices::Display::Core::IDisplayStateOperationResult
    {
        DisplayStateOperationResult(std::nullptr_t) noexcept {}
        DisplayStateOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayStateOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplaySurface : llm::OS::Devices::Display::Core::IDisplaySurface
    {
        DisplaySurface(std::nullptr_t) noexcept {}
        DisplaySurface(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplaySurface(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayTarget : llm::OS::Devices::Display::Core::IDisplayTarget
    {
        DisplayTarget(std::nullptr_t) noexcept {}
        DisplayTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayTarget(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayTask : llm::OS::Devices::Display::Core::IDisplayTask,
        impl::require<DisplayTask, llm::OS::Devices::Display::Core::IDisplayTask2>
    {
        DisplayTask(std::nullptr_t) noexcept {}
        DisplayTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayTask(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayTaskPool : llm::OS::Devices::Display::Core::IDisplayTaskPool,
        impl::require<DisplayTaskPool, llm::OS::Devices::Display::Core::IDisplayTaskPool2>
    {
        DisplayTaskPool(std::nullptr_t) noexcept {}
        DisplayTaskPool(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayTaskPool(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayTaskResult : llm::OS::Devices::Display::Core::IDisplayTaskResult
    {
        DisplayTaskResult(std::nullptr_t) noexcept {}
        DisplayTaskResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayTaskResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayView : llm::OS::Devices::Display::Core::IDisplayView
    {
        DisplayView(std::nullptr_t) noexcept {}
        DisplayView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DisplayWireFormat : llm::OS::Devices::Display::Core::IDisplayWireFormat
    {
        DisplayWireFormat(std::nullptr_t) noexcept {}
        DisplayWireFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Display::Core::IDisplayWireFormat(ptr, take_ownership_from_abi) {}
        DisplayWireFormat(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata);
        static auto CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata);
    };
}
#endif
