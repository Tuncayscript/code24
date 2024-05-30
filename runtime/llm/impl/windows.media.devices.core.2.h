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
#ifndef LLM_OS_Media_Devices_Core_2_H
#define LLM_OS_Media_Devices_Core_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Numerics.1.h"
#include "llm/impl/Windows.Media.Devices.Core.1.h"
LLM_EXPORT namespace llm:OS::Media::Devices::Core
{
    struct __declspec(empty_bases) CameraIntrinsics : llm:OS::Media::Devices::Core::ICameraIntrinsics,
        impl::require<CameraIntrinsics, llm:OS::Media::Devices::Core::ICameraIntrinsics2>
    {
        CameraIntrinsics(std::nullptr_t) noexcept {}
        CameraIntrinsics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::ICameraIntrinsics(ptr, take_ownership_from_abi) {}
        CameraIntrinsics(llm:OS::Foundation::Numerics::float2 const& focalLength, llm:OS::Foundation::Numerics::float2 const& principalPoint, llm:OS::Foundation::Numerics::float3 const& radialDistortion, llm:OS::Foundation::Numerics::float2 const& tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight);
    };
    struct __declspec(empty_bases) DepthCorrelatedCoordinateMapper : llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper
    {
        DepthCorrelatedCoordinateMapper(std::nullptr_t) noexcept {}
        DepthCorrelatedCoordinateMapper(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameControlCapabilities : llm:OS::Media::Devices::Core::IFrameControlCapabilities,
        impl::require<FrameControlCapabilities, llm:OS::Media::Devices::Core::IFrameControlCapabilities2>
    {
        FrameControlCapabilities(std::nullptr_t) noexcept {}
        FrameControlCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameControlCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameController : llm:OS::Media::Devices::Core::IFrameController,
        impl::require<FrameController, llm:OS::Media::Devices::Core::IFrameController2>
    {
        FrameController(std::nullptr_t) noexcept {}
        FrameController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameController(ptr, take_ownership_from_abi) {}
        FrameController();
    };
    struct __declspec(empty_bases) FrameExposureCapabilities : llm:OS::Media::Devices::Core::IFrameExposureCapabilities
    {
        FrameExposureCapabilities(std::nullptr_t) noexcept {}
        FrameExposureCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameExposureCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameExposureCompensationCapabilities : llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities
    {
        FrameExposureCompensationCapabilities(std::nullptr_t) noexcept {}
        FrameExposureCompensationCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameExposureCompensationCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameExposureCompensationControl : llm:OS::Media::Devices::Core::IFrameExposureCompensationControl
    {
        FrameExposureCompensationControl(std::nullptr_t) noexcept {}
        FrameExposureCompensationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameExposureCompensationControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameExposureControl : llm:OS::Media::Devices::Core::IFrameExposureControl
    {
        FrameExposureControl(std::nullptr_t) noexcept {}
        FrameExposureControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameExposureControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameFlashCapabilities : llm:OS::Media::Devices::Core::IFrameFlashCapabilities
    {
        FrameFlashCapabilities(std::nullptr_t) noexcept {}
        FrameFlashCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameFlashCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameFlashControl : llm:OS::Media::Devices::Core::IFrameFlashControl
    {
        FrameFlashControl(std::nullptr_t) noexcept {}
        FrameFlashControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameFlashControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameFocusCapabilities : llm:OS::Media::Devices::Core::IFrameFocusCapabilities
    {
        FrameFocusCapabilities(std::nullptr_t) noexcept {}
        FrameFocusCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameFocusCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameFocusControl : llm:OS::Media::Devices::Core::IFrameFocusControl
    {
        FrameFocusControl(std::nullptr_t) noexcept {}
        FrameFocusControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameFocusControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameIsoSpeedCapabilities : llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities
    {
        FrameIsoSpeedCapabilities(std::nullptr_t) noexcept {}
        FrameIsoSpeedCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameIsoSpeedCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FrameIsoSpeedControl : llm:OS::Media::Devices::Core::IFrameIsoSpeedControl
    {
        FrameIsoSpeedControl(std::nullptr_t) noexcept {}
        FrameIsoSpeedControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IFrameIsoSpeedControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VariablePhotoSequenceController : llm:OS::Media::Devices::Core::IVariablePhotoSequenceController
    {
        VariablePhotoSequenceController(std::nullptr_t) noexcept {}
        VariablePhotoSequenceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::Core::IVariablePhotoSequenceController(ptr, take_ownership_from_abi) {}
    };
}
#endif
