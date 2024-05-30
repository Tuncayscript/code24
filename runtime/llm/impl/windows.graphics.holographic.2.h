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
#ifndef LLM_OS_Graphics_Holographic_2_H
#define LLM_OS_Graphics_Holographic_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.Graphics.Holographic.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Holographic
{
    struct HolographicAdapterId
    {
        uint32_t LowPart;
        int32_t HighPart;
    };
    inline bool operator==(HolographicAdapterId const& left, HolographicAdapterId const& right) noexcept
    {
        return left.LowPart == right.LowPart && left.HighPart == right.HighPart;
    }
    inline bool operator!=(HolographicAdapterId const& left, HolographicAdapterId const& right) noexcept
    {
        return !(left == right);
    }
    struct HolographicFrameId
    {
        uint64_t Value;
    };
    inline bool operator==(HolographicFrameId const& left, HolographicFrameId const& right) noexcept
    {
        return left.Value == right.Value;
    }
    inline bool operator!=(HolographicFrameId const& left, HolographicFrameId const& right) noexcept
    {
        return !(left == right);
    }
    struct HolographicStereoTransform
    {
        llm:OS::Foundation::Numerics::float4x4 Left;
        llm:OS::Foundation::Numerics::float4x4 Right;
    };
    inline bool operator==(HolographicStereoTransform const& left, HolographicStereoTransform const& right) noexcept
    {
        return left.Left == right.Left && left.Right == right.Right;
    }
    inline bool operator!=(HolographicStereoTransform const& left, HolographicStereoTransform const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) HolographicCamera : llm:OS::Graphics::Holographic::IHolographicCamera,
        impl::require<HolographicCamera, llm:OS::Graphics::Holographic::IHolographicCamera2, llm:OS::Graphics::Holographic::IHolographicCamera3, llm:OS::Graphics::Holographic::IHolographicCamera4, llm:OS::Graphics::Holographic::IHolographicCamera5, llm:OS::Graphics::Holographic::IHolographicCamera6>
    {
        HolographicCamera(std::nullptr_t) noexcept {}
        HolographicCamera(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicCamera(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicCameraPose : llm:OS::Graphics::Holographic::IHolographicCameraPose,
        impl::require<HolographicCameraPose, llm:OS::Graphics::Holographic::IHolographicCameraPose2>
    {
        HolographicCameraPose(std::nullptr_t) noexcept {}
        HolographicCameraPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicCameraPose(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicCameraRenderingParameters : llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters,
        impl::require<HolographicCameraRenderingParameters, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters2, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters3, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters4>
    {
        HolographicCameraRenderingParameters(std::nullptr_t) noexcept {}
        HolographicCameraRenderingParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicCameraViewportParameters : llm:OS::Graphics::Holographic::IHolographicCameraViewportParameters
    {
        HolographicCameraViewportParameters(std::nullptr_t) noexcept {}
        HolographicCameraViewportParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicCameraViewportParameters(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicDisplay : llm:OS::Graphics::Holographic::IHolographicDisplay,
        impl::require<HolographicDisplay, llm:OS::Graphics::Holographic::IHolographicDisplay2, llm:OS::Graphics::Holographic::IHolographicDisplay3>
    {
        HolographicDisplay(std::nullptr_t) noexcept {}
        HolographicDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicDisplay(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) HolographicFrame : llm:OS::Graphics::Holographic::IHolographicFrame,
        impl::require<HolographicFrame, llm:OS::Graphics::Holographic::IHolographicFrame2, llm:OS::Graphics::Holographic::IHolographicFrame3>
    {
        HolographicFrame(std::nullptr_t) noexcept {}
        HolographicFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFramePrediction : llm:OS::Graphics::Holographic::IHolographicFramePrediction
    {
        HolographicFramePrediction(std::nullptr_t) noexcept {}
        HolographicFramePrediction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFramePrediction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFramePresentationMonitor : llm:OS::Graphics::Holographic::IHolographicFramePresentationMonitor
    {
        HolographicFramePresentationMonitor(std::nullptr_t) noexcept {}
        HolographicFramePresentationMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFramePresentationMonitor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFramePresentationReport : llm:OS::Graphics::Holographic::IHolographicFramePresentationReport
    {
        HolographicFramePresentationReport(std::nullptr_t) noexcept {}
        HolographicFramePresentationReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFramePresentationReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFrameRenderingReport : llm:OS::Graphics::Holographic::IHolographicFrameRenderingReport
    {
        HolographicFrameRenderingReport(std::nullptr_t) noexcept {}
        HolographicFrameRenderingReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFrameRenderingReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFrameScanoutMonitor : llm:OS::Graphics::Holographic::IHolographicFrameScanoutMonitor
    {
        HolographicFrameScanoutMonitor(std::nullptr_t) noexcept {}
        HolographicFrameScanoutMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFrameScanoutMonitor(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicFrameScanoutReport : llm:OS::Graphics::Holographic::IHolographicFrameScanoutReport
    {
        HolographicFrameScanoutReport(std::nullptr_t) noexcept {}
        HolographicFrameScanoutReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicFrameScanoutReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicQuadLayer : llm:OS::Graphics::Holographic::IHolographicQuadLayer,
        impl::require<HolographicQuadLayer, llm:OS::Foundation::IClosable>
    {
        HolographicQuadLayer(std::nullptr_t) noexcept {}
        HolographicQuadLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicQuadLayer(ptr, take_ownership_from_abi) {}
        explicit HolographicQuadLayer(llm:OS::Foundation::Size const& size);
        HolographicQuadLayer(llm:OS::Foundation::Size const& size, llm:OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat);
    };
    struct __declspec(empty_bases) HolographicQuadLayerUpdateParameters : llm:OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters,
        impl::require<HolographicQuadLayerUpdateParameters, llm:OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2>
    {
        HolographicQuadLayerUpdateParameters(std::nullptr_t) noexcept {}
        HolographicQuadLayerUpdateParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicSpace : llm:OS::Graphics::Holographic::IHolographicSpace,
        impl::require<HolographicSpace, llm:OS::Graphics::Holographic::IHolographicSpace2, llm:OS::Graphics::Holographic::IHolographicSpace3>
    {
        HolographicSpace(std::nullptr_t) noexcept {}
        HolographicSpace(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicSpace(ptr, take_ownership_from_abi) {}
        static auto CreateForCoreWindow(llm:OS::UI::Core::CoreWindow const& window);
        [[nodiscard]] static auto IsSupported();
        [[nodiscard]] static auto IsAvailable();
        static auto IsAvailableChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using IsAvailableChanged_revoker = impl::factory_event_revoker<llm:OS::Graphics::Holographic::IHolographicSpaceStatics2, &impl::abi_t<llm:OS::Graphics::Holographic::IHolographicSpaceStatics2>::remove_IsAvailableChanged>;
        [[nodiscard]] static IsAvailableChanged_revoker IsAvailableChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto IsAvailableChanged(llm::event_token const& token);
        [[nodiscard]] static auto IsConfigured();
    };
    struct __declspec(empty_bases) HolographicSpaceCameraAddedEventArgs : llm:OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs
    {
        HolographicSpaceCameraAddedEventArgs(std::nullptr_t) noexcept {}
        HolographicSpaceCameraAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicSpaceCameraRemovedEventArgs : llm:OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs
    {
        HolographicSpaceCameraRemovedEventArgs(std::nullptr_t) noexcept {}
        HolographicSpaceCameraRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HolographicViewConfiguration : llm:OS::Graphics::Holographic::IHolographicViewConfiguration,
        impl::require<HolographicViewConfiguration, llm:OS::Graphics::Holographic::IHolographicViewConfiguration2>
    {
        HolographicViewConfiguration(std::nullptr_t) noexcept {}
        HolographicViewConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Holographic::IHolographicViewConfiguration(ptr, take_ownership_from_abi) {}
    };
}
#endif
