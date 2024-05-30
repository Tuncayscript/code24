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
#ifndef LLM_OS_Graphics_Holographic_1_H
#define LLM_OS_Graphics_Holographic_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Graphics.Holographic.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Holographic
{
    struct __declspec(empty_bases) IHolographicCamera :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera>
    {
        IHolographicCamera(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCamera2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera2>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicCamera2, llm:OS::Graphics::Holographic::IHolographicCamera>
    {
        IHolographicCamera2(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCamera3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera3>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicCamera3, llm:OS::Graphics::Holographic::IHolographicCamera, llm:OS::Graphics::Holographic::IHolographicCamera2>
    {
        IHolographicCamera3(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCamera4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera4>
    {
        IHolographicCamera4(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCamera5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera5>
    {
        IHolographicCamera5(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCamera6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCamera6>
    {
        IHolographicCamera6(std::nullptr_t = nullptr) noexcept {}
        IHolographicCamera6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraPose :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraPose>
    {
        IHolographicCameraPose(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraPose2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraPose2>
    {
        IHolographicCameraPose2(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraPose2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraRenderingParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraRenderingParameters>
    {
        IHolographicCameraRenderingParameters(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraRenderingParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraRenderingParameters2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraRenderingParameters2>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters2, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters>
    {
        IHolographicCameraRenderingParameters2(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraRenderingParameters2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraRenderingParameters3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraRenderingParameters3>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters3, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters, llm:OS::Graphics::Holographic::IHolographicCameraRenderingParameters2>
    {
        IHolographicCameraRenderingParameters3(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraRenderingParameters3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraRenderingParameters4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraRenderingParameters4>
    {
        IHolographicCameraRenderingParameters4(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraRenderingParameters4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicCameraViewportParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicCameraViewportParameters>
    {
        IHolographicCameraViewportParameters(std::nullptr_t = nullptr) noexcept {}
        IHolographicCameraViewportParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicDisplay :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicDisplay>
    {
        IHolographicDisplay(std::nullptr_t = nullptr) noexcept {}
        IHolographicDisplay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicDisplay2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicDisplay2>
    {
        IHolographicDisplay2(std::nullptr_t = nullptr) noexcept {}
        IHolographicDisplay2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicDisplay3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicDisplay3>
    {
        IHolographicDisplay3(std::nullptr_t = nullptr) noexcept {}
        IHolographicDisplay3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicDisplayStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicDisplayStatics>
    {
        IHolographicDisplayStatics(std::nullptr_t = nullptr) noexcept {}
        IHolographicDisplayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrame>
    {
        IHolographicFrame(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrame2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrame2>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicFrame2, llm:OS::Graphics::Holographic::IHolographicFrame>
    {
        IHolographicFrame2(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrame2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrame3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrame3>
    {
        IHolographicFrame3(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrame3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFramePrediction :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFramePrediction>
    {
        IHolographicFramePrediction(std::nullptr_t = nullptr) noexcept {}
        IHolographicFramePrediction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFramePresentationMonitor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFramePresentationMonitor>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicFramePresentationMonitor, llm:OS::Foundation::IClosable>
    {
        IHolographicFramePresentationMonitor(std::nullptr_t = nullptr) noexcept {}
        IHolographicFramePresentationMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFramePresentationReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFramePresentationReport>
    {
        IHolographicFramePresentationReport(std::nullptr_t = nullptr) noexcept {}
        IHolographicFramePresentationReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrameRenderingReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrameRenderingReport>
    {
        IHolographicFrameRenderingReport(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrameRenderingReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrameScanoutMonitor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrameScanoutMonitor>,
        impl::require<llm:OS::Graphics::Holographic::IHolographicFrameScanoutMonitor, llm:OS::Foundation::IClosable>
    {
        IHolographicFrameScanoutMonitor(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrameScanoutMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicFrameScanoutReport :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicFrameScanoutReport>
    {
        IHolographicFrameScanoutReport(std::nullptr_t = nullptr) noexcept {}
        IHolographicFrameScanoutReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicQuadLayer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicQuadLayer>
    {
        IHolographicQuadLayer(std::nullptr_t = nullptr) noexcept {}
        IHolographicQuadLayer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicQuadLayerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicQuadLayerFactory>
    {
        IHolographicQuadLayerFactory(std::nullptr_t = nullptr) noexcept {}
        IHolographicQuadLayerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicQuadLayerUpdateParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicQuadLayerUpdateParameters>
    {
        IHolographicQuadLayerUpdateParameters(std::nullptr_t = nullptr) noexcept {}
        IHolographicQuadLayerUpdateParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicQuadLayerUpdateParameters2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicQuadLayerUpdateParameters2>
    {
        IHolographicQuadLayerUpdateParameters2(std::nullptr_t = nullptr) noexcept {}
        IHolographicQuadLayerUpdateParameters2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpace :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpace>
    {
        IHolographicSpace(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpace(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpace2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpace2>
    {
        IHolographicSpace2(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpace2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpace3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpace3>
    {
        IHolographicSpace3(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpace3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpaceCameraAddedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpaceCameraAddedEventArgs>
    {
        IHolographicSpaceCameraAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpaceCameraAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpaceCameraRemovedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpaceCameraRemovedEventArgs>
    {
        IHolographicSpaceCameraRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpaceCameraRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpaceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpaceStatics>
    {
        IHolographicSpaceStatics(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpaceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpaceStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpaceStatics2>
    {
        IHolographicSpaceStatics2(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpaceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicSpaceStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicSpaceStatics3>
    {
        IHolographicSpaceStatics3(std::nullptr_t = nullptr) noexcept {}
        IHolographicSpaceStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicViewConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicViewConfiguration>
    {
        IHolographicViewConfiguration(std::nullptr_t = nullptr) noexcept {}
        IHolographicViewConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicViewConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHolographicViewConfiguration2>
    {
        IHolographicViewConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IHolographicViewConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
