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
#ifndef LLM_OS_Devices_Perception_2_H
#define LLM_OS_Devices_Perception_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Perception.1.h"
LLM_EXPORT namespace llm::OS::Devices::Perception
{
    struct KnownCameraIntrinsicsProperties
    {
        KnownCameraIntrinsicsProperties() = delete;
        [[nodiscard]] static auto FocalLength();
        [[nodiscard]] static auto PrincipalPoint();
        [[nodiscard]] static auto RadialDistortion();
        [[nodiscard]] static auto TangentialDistortion();
    };
    struct KnownPerceptionColorFrameSourceProperties
    {
        KnownPerceptionColorFrameSourceProperties() = delete;
        [[nodiscard]] static auto Exposure();
        [[nodiscard]] static auto AutoExposureEnabled();
        [[nodiscard]] static auto ExposureCompensation();
    };
    struct KnownPerceptionDepthFrameSourceProperties
    {
        KnownPerceptionDepthFrameSourceProperties() = delete;
        [[nodiscard]] static auto MinDepth();
        [[nodiscard]] static auto MaxDepth();
    };
    struct KnownPerceptionFrameSourceProperties
    {
        KnownPerceptionFrameSourceProperties() = delete;
        [[nodiscard]] static auto Id();
        [[nodiscard]] static auto PhysicalDeviceIds();
        [[nodiscard]] static auto FrameKind();
        [[nodiscard]] static auto DeviceModelVersion();
        [[nodiscard]] static auto EnclosureLocation();
        [[nodiscard]] static auto DeviceId();
    };
    struct KnownPerceptionInfraredFrameSourceProperties
    {
        KnownPerceptionInfraredFrameSourceProperties() = delete;
        [[nodiscard]] static auto Exposure();
        [[nodiscard]] static auto AutoExposureEnabled();
        [[nodiscard]] static auto ExposureCompensation();
        [[nodiscard]] static auto ActiveIlluminationEnabled();
        [[nodiscard]] static auto AmbientSubtractionEnabled();
        [[nodiscard]] static auto StructureLightPatternEnabled();
        [[nodiscard]] static auto InterleavedIlluminationEnabled();
    };
    struct KnownPerceptionVideoFrameSourceProperties
    {
        KnownPerceptionVideoFrameSourceProperties() = delete;
        [[nodiscard]] static auto VideoProfile();
        [[nodiscard]] static auto SupportedVideoProfiles();
        [[nodiscard]] static auto AvailableVideoProfiles();
        [[nodiscard]] static auto IsMirrored();
        [[nodiscard]] static auto CameraIntrinsics();
    };
    struct KnownPerceptionVideoProfileProperties
    {
        KnownPerceptionVideoProfileProperties() = delete;
        [[nodiscard]] static auto BitmapPixelFormat();
        [[nodiscard]] static auto BitmapAlphaMode();
        [[nodiscard]] static auto Width();
        [[nodiscard]] static auto Height();
        [[nodiscard]] static auto FrameDuration();
    };
    struct __declspec(empty_bases) PerceptionColorFrame : llm::OS::Devices::Perception::IPerceptionColorFrame
    {
        PerceptionColorFrame(std::nullptr_t) noexcept {}
        PerceptionColorFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionColorFrameArrivedEventArgs : llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs
    {
        PerceptionColorFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        PerceptionColorFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionColorFrameReader : llm::OS::Devices::Perception::IPerceptionColorFrameReader
    {
        PerceptionColorFrameReader(std::nullptr_t) noexcept {}
        PerceptionColorFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionColorFrameSource : llm::OS::Devices::Perception::IPerceptionColorFrameSource,
        impl::require<PerceptionColorFrameSource, llm::OS::Devices::Perception::IPerceptionColorFrameSource2>
    {
        PerceptionColorFrameSource(std::nullptr_t) noexcept {}
        PerceptionColorFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameSource(ptr, take_ownership_from_abi) {}
        static auto CreateWatcher();
        static auto FindAllAsync();
        static auto FromIdAsync(param::hstring const& id);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) PerceptionColorFrameSourceAddedEventArgs : llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs
    {
        PerceptionColorFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
        PerceptionColorFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionColorFrameSourceRemovedEventArgs : llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs
    {
        PerceptionColorFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
        PerceptionColorFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionColorFrameSourceWatcher : llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher
    {
        PerceptionColorFrameSourceWatcher(std::nullptr_t) noexcept {}
        PerceptionColorFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionControlSession : llm::OS::Devices::Perception::IPerceptionControlSession
    {
        PerceptionControlSession(std::nullptr_t) noexcept {}
        PerceptionControlSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionControlSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthCorrelatedCameraIntrinsics : llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics
    {
        PerceptionDepthCorrelatedCameraIntrinsics(std::nullptr_t) noexcept {}
        PerceptionDepthCorrelatedCameraIntrinsics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthCorrelatedCoordinateMapper : llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper
    {
        PerceptionDepthCorrelatedCoordinateMapper(std::nullptr_t) noexcept {}
        PerceptionDepthCorrelatedCoordinateMapper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrame : llm::OS::Devices::Perception::IPerceptionDepthFrame
    {
        PerceptionDepthFrame(std::nullptr_t) noexcept {}
        PerceptionDepthFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrameArrivedEventArgs : llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs
    {
        PerceptionDepthFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        PerceptionDepthFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrameReader : llm::OS::Devices::Perception::IPerceptionDepthFrameReader
    {
        PerceptionDepthFrameReader(std::nullptr_t) noexcept {}
        PerceptionDepthFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrameSource : llm::OS::Devices::Perception::IPerceptionDepthFrameSource,
        impl::require<PerceptionDepthFrameSource, llm::OS::Devices::Perception::IPerceptionDepthFrameSource2>
    {
        PerceptionDepthFrameSource(std::nullptr_t) noexcept {}
        PerceptionDepthFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameSource(ptr, take_ownership_from_abi) {}
        static auto CreateWatcher();
        static auto FindAllAsync();
        static auto FromIdAsync(param::hstring const& id);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) PerceptionDepthFrameSourceAddedEventArgs : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs
    {
        PerceptionDepthFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
        PerceptionDepthFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrameSourceRemovedEventArgs : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs
    {
        PerceptionDepthFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
        PerceptionDepthFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionDepthFrameSourceWatcher : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher
    {
        PerceptionDepthFrameSourceWatcher(std::nullptr_t) noexcept {}
        PerceptionDepthFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionFrameSourcePropertiesChangedEventArgs : llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs
    {
        PerceptionFrameSourcePropertiesChangedEventArgs(std::nullptr_t) noexcept {}
        PerceptionFrameSourcePropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionFrameSourcePropertyChangeResult : llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult
    {
        PerceptionFrameSourcePropertyChangeResult(std::nullptr_t) noexcept {}
        PerceptionFrameSourcePropertyChangeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrame : llm::OS::Devices::Perception::IPerceptionInfraredFrame
    {
        PerceptionInfraredFrame(std::nullptr_t) noexcept {}
        PerceptionInfraredFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameArrivedEventArgs : llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs
    {
        PerceptionInfraredFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameReader : llm::OS::Devices::Perception::IPerceptionInfraredFrameReader
    {
        PerceptionInfraredFrameReader(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameSource : llm::OS::Devices::Perception::IPerceptionInfraredFrameSource,
        impl::require<PerceptionInfraredFrameSource, llm::OS::Devices::Perception::IPerceptionInfraredFrameSource2>
    {
        PerceptionInfraredFrameSource(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameSource(ptr, take_ownership_from_abi) {}
        static auto CreateWatcher();
        static auto FindAllAsync();
        static auto FromIdAsync(param::hstring const& id);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameSourceAddedEventArgs : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs
    {
        PerceptionInfraredFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameSourceRemovedEventArgs : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs
    {
        PerceptionInfraredFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionInfraredFrameSourceWatcher : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher
    {
        PerceptionInfraredFrameSourceWatcher(std::nullptr_t) noexcept {}
        PerceptionInfraredFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionVideoProfile : llm::OS::Devices::Perception::IPerceptionVideoProfile
    {
        PerceptionVideoProfile(std::nullptr_t) noexcept {}
        PerceptionVideoProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::IPerceptionVideoProfile(ptr, take_ownership_from_abi) {}
    };
}
#endif
