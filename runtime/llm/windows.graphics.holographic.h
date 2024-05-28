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
#ifndef LLM_OS_Graphics_Holographic_H
#define LLM_OS_Graphics_Holographic_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Perception.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.Graphics.Holographic.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::RenderTargetSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->get_RenderTargetSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::ViewportScaleFactor() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->get_ViewportScaleFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::ViewportScaleFactor(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->put_ViewportScaleFactor(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::Id() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->get_Id(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::SetNearPlaneDistance(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->SetNearPlaneDistance(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCamera<D>::SetFarPlaneDistance(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera)->SetFarPlaneDistance(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCameraViewportParameters) consume_Windows_Graphics_Holographic_IHolographicCamera2<D>::LeftViewportParameters() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera2)->get_LeftViewportParameters(&result));
        return llm::OS::Graphics::Holographic::HolographicCameraViewportParameters{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCameraViewportParameters) consume_Windows_Graphics_Holographic_IHolographicCamera2<D>::RightViewportParameters() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera2)->get_RightViewportParameters(&result));
        return llm::OS::Graphics::Holographic::HolographicCameraViewportParameters{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicDisplay) consume_Windows_Graphics_Holographic_IHolographicCamera2<D>::Display() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera2)->get_Display(&result));
        return llm::OS::Graphics::Holographic::HolographicDisplay{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCamera3<D>::IsPrimaryLayerEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera3)->get_IsPrimaryLayerEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCamera3<D>::IsPrimaryLayerEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera3)->put_IsPrimaryLayerEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicCamera3<D>::MaxQuadLayerCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera3)->get_MaxQuadLayerCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicQuadLayer>) consume_Windows_Graphics_Holographic_IHolographicCamera3<D>::QuadLayers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera3)->get_QuadLayers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicQuadLayer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCamera4<D>::CanOverrideViewport() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera4)->get_CanOverrideViewport(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCamera5<D>::IsHardwareContentProtectionSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera5)->get_IsHardwareContentProtectionSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCamera5<D>::IsHardwareContentProtectionEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera5)->get_IsHardwareContentProtectionEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCamera5<D>::IsHardwareContentProtectionEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera5)->put_IsHardwareContentProtectionEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicViewConfiguration) consume_Windows_Graphics_Holographic_IHolographicCamera6<D>::ViewConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCamera6)->get_ViewConfiguration(&value));
        return llm::OS::Graphics::Holographic::HolographicViewConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCamera) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::HolographicCamera() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->get_HolographicCamera(&value));
        return llm::OS::Graphics::Holographic::HolographicCamera{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::Viewport() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->get_Viewport(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::Holographic::HolographicStereoTransform>) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::TryGetViewTransform(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->TryGetViewTransform(*(void**)(&coordinateSystem), &value));
        return llm::OS::Foundation::IReference<llm::OS::Graphics::Holographic::HolographicStereoTransform>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicStereoTransform) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::ProjectionTransform() const
    {
        llm::OS::Graphics::Holographic::HolographicStereoTransform value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->get_ProjectionTransform(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::TryGetCullingFrustum(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->TryGetCullingFrustum(*(void**)(&coordinateSystem), &value));
        return llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::TryGetVisibleFrustum(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->TryGetVisibleFrustum(*(void**)(&coordinateSystem), &value));
        return llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::NearPlaneDistance() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->get_NearPlaneDistance(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Holographic_IHolographicCameraPose<D>::FarPlaneDistance() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose)->get_FarPlaneDistance(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraPose2<D>::OverrideViewTransform(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Graphics::Holographic::HolographicStereoTransform const& coordinateSystemToViewTransform) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose2)->OverrideViewTransform(*(void**)(&coordinateSystem), impl::bind_in(coordinateSystemToViewTransform)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraPose2<D>::OverrideProjectionTransform(llm::OS::Graphics::Holographic::HolographicStereoTransform const& projectionTransform) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose2)->OverrideProjectionTransform(impl::bind_in(projectionTransform)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraPose2<D>::OverrideViewport(llm::OS::Foundation::Rect const& leftViewport, llm::OS::Foundation::Rect const& rightViewport) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraPose2)->OverrideViewport(impl::bind_in(leftViewport), impl::bind_in(rightViewport)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters<D>::SetFocusPoint(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters)->SetFocusPoint(*(void**)(&coordinateSystem), impl::bind_in(position)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters<D>::SetFocusPoint(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::float3 const& normal) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters)->SetFocusPointWithNormal(*(void**)(&coordinateSystem), impl::bind_in(position), impl::bind_in(normal)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters<D>::SetFocusPoint(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::float3 const& normal, llm::OS::Foundation::Numerics::float3 const& linearVelocity) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters)->SetFocusPointWithNormalLinearVelocity(*(void**)(&coordinateSystem), impl::bind_in(position), impl::bind_in(normal), impl::bind_in(linearVelocity)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters<D>::Direct3D11Device() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters)->get_Direct3D11Device(&value));
        return llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters<D>::Direct3D11BackBuffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters)->get_Direct3D11BackBuffer(&value));
        return llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicReprojectionMode) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters2<D>::ReprojectionMode() const
    {
        llm::OS::Graphics::Holographic::HolographicReprojectionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2)->get_ReprojectionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters2<D>::ReprojectionMode(llm::OS::Graphics::Holographic::HolographicReprojectionMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2)->put_ReprojectionMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters2<D>::CommitDirect3D11DepthBuffer(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2)->CommitDirect3D11DepthBuffer(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters3<D>::IsContentProtectionEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters3)->get_IsContentProtectionEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters3<D>::IsContentProtectionEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters3)->put_IsContentProtectionEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters4<D>::DepthReprojectionMethod() const
    {
        llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters4)->get_DepthReprojectionMethod(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicCameraRenderingParameters4<D>::DepthReprojectionMethod(llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters4)->put_DepthReprojectionMethod(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(com_array<llm::OS::Foundation::Numerics::float2>) consume_Windows_Graphics_Holographic_IHolographicCameraViewportParameters<D>::HiddenAreaMesh() const
    {
        uint32_t value_impl_size{};
        llm::OS::Foundation::Numerics::float2* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraViewportParameters)->get_HiddenAreaMesh(&value_impl_size, &value));
        return com_array<llm::OS::Foundation::Numerics::float2>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<llm::OS::Foundation::Numerics::float2>) consume_Windows_Graphics_Holographic_IHolographicCameraViewportParameters<D>::VisibleAreaMesh() const
    {
        uint32_t value_impl_size{};
        llm::OS::Foundation::Numerics::float2* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicCameraViewportParameters)->get_VisibleAreaMesh(&value_impl_size, &value));
        return com_array<llm::OS::Foundation::Numerics::float2>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::MaxViewportSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_MaxViewportSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::IsOpaque() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_IsOpaque(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicAdapterId) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::AdapterId() const
    {
        llm::OS::Graphics::Holographic::HolographicAdapterId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_AdapterId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocator) consume_Windows_Graphics_Holographic_IHolographicDisplay<D>::SpatialLocator() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay)->get_SpatialLocator(&value));
        return llm::OS::Perception::Spatial::SpatialLocator{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Holographic_IHolographicDisplay2<D>::RefreshRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay2)->get_RefreshRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicViewConfiguration) consume_Windows_Graphics_Holographic_IHolographicDisplay3<D>::TryGetViewConfiguration(llm::OS::Graphics::Holographic::HolographicViewConfigurationKind const& kind) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplay3)->TryGetViewConfiguration(static_cast<int32_t>(kind), &result));
        return llm::OS::Graphics::Holographic::HolographicViewConfiguration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicDisplay) consume_Windows_Graphics_Holographic_IHolographicDisplayStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicDisplayStatics)->GetDefault(&result));
        return llm::OS::Graphics::Holographic::HolographicDisplay{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::AddedCameras() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->get_AddedCameras(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::RemovedCameras() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->get_RemovedCameras(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCameraRenderingParameters) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::GetRenderingParameters(llm::OS::Graphics::Holographic::HolographicCameraPose const& cameraPose) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->GetRenderingParameters(*(void**)(&cameraPose), &value));
        return llm::OS::Graphics::Holographic::HolographicCameraRenderingParameters{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFramePrediction) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::CurrentPrediction() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->get_CurrentPrediction(&value));
        return llm::OS::Graphics::Holographic::HolographicFramePrediction{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::UpdateCurrentPrediction() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->UpdateCurrentPrediction());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFramePresentResult) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::PresentUsingCurrentPrediction() const
    {
        llm::OS::Graphics::Holographic::HolographicFramePresentResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->PresentUsingCurrentPrediction(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFramePresentResult) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::PresentUsingCurrentPrediction(llm::OS::Graphics::Holographic::HolographicFramePresentWaitBehavior const& waitBehavior) const
    {
        llm::OS::Graphics::Holographic::HolographicFramePresentResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->PresentUsingCurrentPredictionWithBehavior(static_cast<int32_t>(waitBehavior), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicFrame<D>::WaitForFrameToFinish() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame)->WaitForFrameToFinish());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicQuadLayerUpdateParameters) consume_Windows_Graphics_Holographic_IHolographicFrame2<D>::GetQuadLayerUpdateParameters(llm::OS::Graphics::Holographic::HolographicQuadLayer const& layer) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame2)->GetQuadLayerUpdateParameters(*(void**)(&layer), &value));
        return llm::OS::Graphics::Holographic::HolographicQuadLayerUpdateParameters{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFrameId) consume_Windows_Graphics_Holographic_IHolographicFrame3<D>::Id() const
    {
        llm::OS::Graphics::Holographic::HolographicFrameId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrame3)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCameraPose>) consume_Windows_Graphics_Holographic_IHolographicFramePrediction<D>::CameraPoses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePrediction)->get_CameraPoses(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCameraPose>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::PerceptionTimestamp) consume_Windows_Graphics_Holographic_IHolographicFramePrediction<D>::Timestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePrediction)->get_Timestamp(&value));
        return llm::OS::Perception::PerceptionTimestamp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicFramePresentationReport>) consume_Windows_Graphics_Holographic_IHolographicFramePresentationMonitor<D>::ReadReports() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationMonitor)->ReadReports(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicFramePresentationReport>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFramePresentationReport<D>::CompositorGpuDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationReport)->get_CompositorGpuDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFramePresentationReport<D>::AppGpuDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationReport)->get_AppGpuDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFramePresentationReport<D>::AppGpuOverrun() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationReport)->get_AppGpuOverrun(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicFramePresentationReport<D>::MissedPresentationOpportunityCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationReport)->get_MissedPresentationOpportunityCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicFramePresentationReport<D>::PresentationCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFramePresentationReport)->get_PresentationCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFrameId) consume_Windows_Graphics_Holographic_IHolographicFrameRenderingReport<D>::FrameId() const
    {
        llm::OS::Graphics::Holographic::HolographicFrameId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport)->get_FrameId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicFrameRenderingReport<D>::MissedLatchCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport)->get_MissedLatchCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameRenderingReport<D>::SystemRelativeFrameReadyTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport)->get_SystemRelativeFrameReadyTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameRenderingReport<D>::SystemRelativeActualGpuFinishTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport)->get_SystemRelativeActualGpuFinishTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameRenderingReport<D>::SystemRelativeTargetLatchTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport)->get_SystemRelativeTargetLatchTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicFrameScanoutReport>) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutMonitor<D>::ReadReports() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutMonitor)->ReadReports(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicFrameScanoutReport>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFrameRenderingReport) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutReport<D>::RenderingReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport)->get_RenderingReport(&value));
        return llm::OS::Graphics::Holographic::HolographicFrameRenderingReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutReport<D>::MissedScanoutCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport)->get_MissedScanoutCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutReport<D>::SystemRelativeLatchTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport)->get_SystemRelativeLatchTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutReport<D>::SystemRelativeScanoutStartTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport)->get_SystemRelativeScanoutStartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Graphics_Holographic_IHolographicFrameScanoutReport<D>::SystemRelativePhotonTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport)->get_SystemRelativePhotonTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Graphics_Holographic_IHolographicQuadLayer<D>::PixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayer)->get_PixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicQuadLayer<D>::Size() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayer)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicQuadLayer) consume_Windows_Graphics_Holographic_IHolographicQuadLayerFactory<D>::Create(llm::OS::Foundation::Size const& size) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerFactory)->Create(impl::bind_in(size), &value));
        return llm::OS::Graphics::Holographic::HolographicQuadLayer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicQuadLayer) consume_Windows_Graphics_Holographic_IHolographicQuadLayerFactory<D>::CreateWithPixelFormat(llm::OS::Foundation::Size const& size, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerFactory)->CreateWithPixelFormat(impl::bind_in(size), static_cast<int32_t>(pixelFormat), &value));
        return llm::OS::Graphics::Holographic::HolographicQuadLayer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::AcquireBufferToUpdateContent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->AcquireBufferToUpdateContent(&value));
        return llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::UpdateViewport(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->UpdateViewport(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::UpdateContentProtectionEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->UpdateContentProtectionEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::UpdateExtents(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->UpdateExtents(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::UpdateLocationWithStationaryMode(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::quaternion const& orientation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->UpdateLocationWithStationaryMode(*(void**)(&coordinateSystem), impl::bind_in(position), impl::bind_in(orientation)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters<D>::UpdateLocationWithDisplayRelativeMode(llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::quaternion const& orientation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters)->UpdateLocationWithDisplayRelativeMode(impl::bind_in(position), impl::bind_in(orientation)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters2<D>::CanAcquireWithHardwareProtection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2)->get_CanAcquireWithHardwareProtection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface) consume_Windows_Graphics_Holographic_IHolographicQuadLayerUpdateParameters2<D>::AcquireBufferToUpdateContentWithHardwareProtection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2)->AcquireBufferToUpdateContentWithHardwareProtection(&value));
        return llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicAdapterId) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::PrimaryAdapterId() const
    {
        llm::OS::Graphics::Holographic::HolographicAdapterId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->get_PrimaryAdapterId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::SetDirect3D11Device(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->SetDirect3D11Device(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->add_CameraAdded(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraAdded_revoker consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CameraAdded_revoker>(this, CameraAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraAdded(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->remove_CameraAdded(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->add_CameraRemoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraRemoved_revoker consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CameraRemoved_revoker>(this, CameraRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CameraRemoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->remove_CameraRemoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFrame) consume_Windows_Graphics_Holographic_IHolographicSpace<D>::CreateNextFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace)->CreateNextFrame(&value));
        return llm::OS::Graphics::Holographic::HolographicFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicSpaceUserPresence) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::UserPresence() const
    {
        llm::OS::Graphics::Holographic::HolographicSpaceUserPresence value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->get_UserPresence(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::UserPresenceChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->add_UserPresenceChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::UserPresenceChanged_revoker consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::UserPresenceChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, UserPresenceChanged_revoker>(this, UserPresenceChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::UserPresenceChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->remove_UserPresenceChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::WaitForNextFrameReady() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->WaitForNextFrameReady());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::WaitForNextFrameReadyWithHeadStart(llm::OS::Foundation::TimeSpan const& requestedHeadStartDuration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->WaitForNextFrameReadyWithHeadStart(impl::bind_in(requestedHeadStartDuration)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFramePresentationMonitor) consume_Windows_Graphics_Holographic_IHolographicSpace2<D>::CreateFramePresentationMonitor(uint32_t maxQueuedReports) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace2)->CreateFramePresentationMonitor(maxQueuedReports, &result));
        return llm::OS::Graphics::Holographic::HolographicFramePresentationMonitor{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicFrameScanoutMonitor) consume_Windows_Graphics_Holographic_IHolographicSpace3<D>::CreateFrameScanoutMonitor(uint32_t maxQueuedReports) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpace3)->CreateFrameScanoutMonitor(maxQueuedReports, &result));
        return llm::OS::Graphics::Holographic::HolographicFrameScanoutMonitor{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCamera) consume_Windows_Graphics_Holographic_IHolographicSpaceCameraAddedEventArgs<D>::Camera() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs)->get_Camera(&value));
        return llm::OS::Graphics::Holographic::HolographicCamera{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Graphics_Holographic_IHolographicSpaceCameraAddedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicCamera) consume_Windows_Graphics_Holographic_IHolographicSpaceCameraRemovedEventArgs<D>::Camera() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs)->get_Camera(&value));
        return llm::OS::Graphics::Holographic::HolographicCamera{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicSpace) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics<D>::CreateForCoreWindow(llm::OS::UI::Core::CoreWindow const& window) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics)->CreateForCoreWindow(*(void**)(&window), &value));
        return llm::OS::Graphics::Holographic::HolographicSpace{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics2)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics2)->get_IsAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsAvailableChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics2)->add_IsAvailableChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsAvailableChanged_revoker consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsAvailableChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsAvailableChanged_revoker>(this, IsAvailableChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics2<D>::IsAvailableChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics2)->remove_IsAvailableChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicSpaceStatics3<D>::IsConfigured() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicSpaceStatics3)->get_IsConfigured(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::NativeRenderTargetSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_NativeRenderTargetSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::RenderTargetSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_RenderTargetSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::RequestRenderTargetSize(llm::OS::Foundation::Size const& size) const
    {
        llm::OS::Foundation::Size result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->RequestRenderTargetSize(impl::bind_in(size), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::SupportedPixelFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_SupportedPixelFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::PixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_PixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::PixelFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->put_PixelFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::RefreshRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_RefreshRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicViewConfigurationKind) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::Kind() const
    {
        llm::OS::Graphics::Holographic::HolographicViewConfigurationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Holographic::HolographicDisplay) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::Display() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_Display(&value));
        return llm::OS::Graphics::Holographic::HolographicDisplay{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod>) consume_Windows_Graphics_Holographic_IHolographicViewConfiguration2<D>::SupportedDepthReprojectionMethods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Holographic::IHolographicViewConfiguration2)->get_SupportedDepthReprojectionMethods(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera>
    {
        int32_t __stdcall get_RenderTargetSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().RenderTargetSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ViewportScaleFactor(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().ViewportScaleFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewportScaleFactor(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewportScaleFactor(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetNearPlaneDistance(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNearPlaneDistance(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFarPlaneDistance(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFarPlaneDistance(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera2>
    {
        int32_t __stdcall get_LeftViewportParameters(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicCameraViewportParameters>(this->shim().LeftViewportParameters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RightViewportParameters(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicCameraViewportParameters>(this->shim().RightViewportParameters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Display(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicDisplay>(this->shim().Display());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera3>
    {
        int32_t __stdcall get_IsPrimaryLayerEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPrimaryLayerEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPrimaryLayerEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPrimaryLayerEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxQuadLayerCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxQuadLayerCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QuadLayers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicQuadLayer>>(this->shim().QuadLayers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera4> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera4>
    {
        int32_t __stdcall get_CanOverrideViewport(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanOverrideViewport());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera5> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera5>
    {
        int32_t __stdcall get_IsHardwareContentProtectionSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsHardwareContentProtectionSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsHardwareContentProtectionEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsHardwareContentProtectionEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsHardwareContentProtectionEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHardwareContentProtectionEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCamera6> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCamera6>
    {
        int32_t __stdcall get_ViewConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicViewConfiguration>(this->shim().ViewConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraPose> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraPose>
    {
        int32_t __stdcall get_HolographicCamera(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicCamera>(this->shim().HolographicCamera());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Viewport(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().Viewport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetViewTransform(void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Graphics::Holographic::HolographicStereoTransform>>(this->shim().TryGetViewTransform(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProjectionTransform(struct struct_Windows_Graphics_Holographic_HolographicStereoTransform* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Holographic::HolographicStereoTransform>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicStereoTransform>(this->shim().ProjectionTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetCullingFrustum(void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>>(this->shim().TryGetCullingFrustum(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetVisibleFrustum(void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingFrustum>>(this->shim().TryGetVisibleFrustum(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NearPlaneDistance(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().NearPlaneDistance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FarPlaneDistance(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().FarPlaneDistance());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraPose2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraPose2>
    {
        int32_t __stdcall OverrideViewTransform(void* coordinateSystem, struct struct_Windows_Graphics_Holographic_HolographicStereoTransform coordinateSystemToViewTransform) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OverrideViewTransform(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Graphics::Holographic::HolographicStereoTransform const*>(&coordinateSystemToViewTransform));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OverrideProjectionTransform(struct struct_Windows_Graphics_Holographic_HolographicStereoTransform projectionTransform) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OverrideProjectionTransform(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicStereoTransform const*>(&projectionTransform));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OverrideViewport(llm::OS::Foundation::Rect leftViewport, llm::OS::Foundation::Rect rightViewport) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OverrideViewport(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&leftViewport), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&rightViewport));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters>
    {
        int32_t __stdcall SetFocusPoint(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocusPointWithNormal(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position, llm::OS::Foundation::Numerics::float3 normal) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&normal));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocusPointWithNormalLinearVelocity(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position, llm::OS::Foundation::Numerics::float3 normal, llm::OS::Foundation::Numerics::float3 linearVelocity) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&normal), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&linearVelocity));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direct3D11Device(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice>(this->shim().Direct3D11Device());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direct3D11BackBuffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>(this->shim().Direct3D11BackBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2>
    {
        int32_t __stdcall get_ReprojectionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicReprojectionMode>(this->shim().ReprojectionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReprojectionMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReprojectionMode(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicReprojectionMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CommitDirect3D11DepthBuffer(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitDirect3D11DepthBuffer(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters3>
    {
        int32_t __stdcall get_IsContentProtectionEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsContentProtectionEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsContentProtectionEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsContentProtectionEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters4> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters4>
    {
        int32_t __stdcall get_DepthReprojectionMethod(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod>(this->shim().DepthReprojectionMethod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DepthReprojectionMethod(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DepthReprojectionMethod(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicCameraViewportParameters> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicCameraViewportParameters>
    {
        int32_t __stdcall get_HiddenAreaMesh(uint32_t* __valueSize, llm::OS::Foundation::Numerics::float2** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().HiddenAreaMesh());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VisibleAreaMesh(uint32_t* __valueSize, llm::OS::Foundation::Numerics::float2** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().VisibleAreaMesh());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicDisplay> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicDisplay>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxViewportSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MaxViewportSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOpaque(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOpaque());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdapterId(struct struct_Windows_Graphics_Holographic_HolographicAdapterId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Holographic::HolographicAdapterId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicAdapterId>(this->shim().AdapterId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpatialLocator(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocator>(this->shim().SpatialLocator());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicDisplay2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicDisplay2>
    {
        int32_t __stdcall get_RefreshRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().RefreshRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicDisplay3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicDisplay3>
    {
        int32_t __stdcall TryGetViewConfiguration(int32_t kind, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicViewConfiguration>(this->shim().TryGetViewConfiguration(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicViewConfigurationKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicDisplayStatics> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicDisplayStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicDisplay>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrame> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrame>
    {
        int32_t __stdcall get_AddedCameras(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>>(this->shim().AddedCameras());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemovedCameras(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCamera>>(this->shim().RemovedCameras());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRenderingParameters(void* cameraPose, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicCameraRenderingParameters>(this->shim().GetRenderingParameters(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicCameraPose const*>(&cameraPose)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentPrediction(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicFramePrediction>(this->shim().CurrentPrediction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateCurrentPrediction() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateCurrentPrediction();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PresentUsingCurrentPrediction(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicFramePresentResult>(this->shim().PresentUsingCurrentPrediction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PresentUsingCurrentPredictionWithBehavior(int32_t waitBehavior, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicFramePresentResult>(this->shim().PresentUsingCurrentPrediction(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicFramePresentWaitBehavior const*>(&waitBehavior)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForFrameToFinish() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForFrameToFinish();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrame2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrame2>
    {
        int32_t __stdcall GetQuadLayerUpdateParameters(void* layer, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicQuadLayerUpdateParameters>(this->shim().GetQuadLayerUpdateParameters(*reinterpret_cast<llm::OS::Graphics::Holographic::HolographicQuadLayer const*>(&layer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrame3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrame3>
    {
        int32_t __stdcall get_Id(struct struct_Windows_Graphics_Holographic_HolographicFrameId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Holographic::HolographicFrameId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicFrameId>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFramePrediction> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFramePrediction>
    {
        int32_t __stdcall get_CameraPoses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicCameraPose>>(this->shim().CameraPoses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::PerceptionTimestamp>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFramePresentationMonitor> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFramePresentationMonitor>
    {
        int32_t __stdcall ReadReports(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicFramePresentationReport>>(this->shim().ReadReports());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFramePresentationReport> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFramePresentationReport>
    {
        int32_t __stdcall get_CompositorGpuDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().CompositorGpuDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppGpuDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().AppGpuDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppGpuOverrun(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().AppGpuOverrun());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MissedPresentationOpportunityCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MissedPresentationOpportunityCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentationCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PresentationCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport>
    {
        int32_t __stdcall get_FrameId(struct struct_Windows_Graphics_Holographic_HolographicFrameId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Holographic::HolographicFrameId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicFrameId>(this->shim().FrameId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MissedLatchCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MissedLatchCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeFrameReadyTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeFrameReadyTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeActualGpuFinishTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeActualGpuFinishTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeTargetLatchTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeTargetLatchTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrameScanoutMonitor> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrameScanoutMonitor>
    {
        int32_t __stdcall ReadReports(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Holographic::HolographicFrameScanoutReport>>(this->shim().ReadReports());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport>
    {
        int32_t __stdcall get_RenderingReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicFrameRenderingReport>(this->shim().RenderingReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MissedScanoutCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MissedScanoutCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeLatchTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeLatchTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeScanoutStartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativeScanoutStartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativePhotonTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SystemRelativePhotonTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicQuadLayer> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicQuadLayer>
    {
        int32_t __stdcall get_PixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().PixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerFactory> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerFactory>
    {
        int32_t __stdcall Create(llm::OS::Foundation::Size size, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicQuadLayer>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithPixelFormat(llm::OS::Foundation::Size size, int32_t pixelFormat, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicQuadLayer>(this->shim().CreateWithPixelFormat(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters>
    {
        int32_t __stdcall AcquireBufferToUpdateContent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>(this->shim().AcquireBufferToUpdateContent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateViewport(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateViewport(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateContentProtectionEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateContentProtectionEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateExtents(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateExtents(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateLocationWithStationaryMode(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position, llm::OS::Foundation::Numerics::quaternion orientation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateLocationWithStationaryMode(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&orientation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateLocationWithDisplayRelativeMode(llm::OS::Foundation::Numerics::float3 position, llm::OS::Foundation::Numerics::quaternion orientation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateLocationWithDisplayRelativeMode(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&orientation));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2>
    {
        int32_t __stdcall get_CanAcquireWithHardwareProtection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanAcquireWithHardwareProtection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireBufferToUpdateContentWithHardwareProtection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>(this->shim().AcquireBufferToUpdateContentWithHardwareProtection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpace> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpace>
    {
        int32_t __stdcall get_PrimaryAdapterId(struct struct_Windows_Graphics_Holographic_HolographicAdapterId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Holographic::HolographicAdapterId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicAdapterId>(this->shim().PrimaryAdapterId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDirect3D11Device(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDirect3D11Device(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CameraAdded(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CameraAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CameraAdded(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraAdded(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_CameraRemoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CameraRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CameraRemoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraRemoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall CreateNextFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicFrame>(this->shim().CreateNextFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpace2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpace2>
    {
        int32_t __stdcall get_UserPresence(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicSpaceUserPresence>(this->shim().UserPresence());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_UserPresenceChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().UserPresenceChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Holographic::HolographicSpace, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_UserPresenceChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserPresenceChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall WaitForNextFrameReady() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForNextFrameReady();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForNextFrameReadyWithHeadStart(int64_t requestedHeadStartDuration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForNextFrameReadyWithHeadStart(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&requestedHeadStartDuration));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFramePresentationMonitor(uint32_t maxQueuedReports, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicFramePresentationMonitor>(this->shim().CreateFramePresentationMonitor(maxQueuedReports));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpace3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpace3>
    {
        int32_t __stdcall CreateFrameScanoutMonitor(uint32_t maxQueuedReports, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Holographic::HolographicFrameScanoutMonitor>(this->shim().CreateFrameScanoutMonitor(maxQueuedReports));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs>
    {
        int32_t __stdcall get_Camera(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicCamera>(this->shim().Camera());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs>
    {
        int32_t __stdcall get_Camera(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicCamera>(this->shim().Camera());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics>
    {
        int32_t __stdcall CreateForCoreWindow(void* window, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicSpace>(this->shim().CreateForCoreWindow(*reinterpret_cast<llm::OS::UI::Core::CoreWindow const*>(&window)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics2>
    {
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsAvailableChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsAvailableChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsAvailableChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAvailableChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics3> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicSpaceStatics3>
    {
        int32_t __stdcall get_IsConfigured(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConfigured());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicViewConfiguration> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicViewConfiguration>
    {
        int32_t __stdcall get_NativeRenderTargetSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().NativeRenderTargetSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RenderTargetSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().RenderTargetSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestRenderTargetSize(llm::OS::Foundation::Size size, llm::OS::Foundation::Size* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Size>(this->shim().RequestRenderTargetSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedPixelFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>>(this->shim().SupportedPixelFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().PixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PixelFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PixelFormat(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RefreshRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().RefreshRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicViewConfigurationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Display(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Holographic::HolographicDisplay>(this->shim().Display());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Holographic::IHolographicViewConfiguration2> : produce_base<D, llm::OS::Graphics::Holographic::IHolographicViewConfiguration2>
    {
        int32_t __stdcall get_SupportedDepthReprojectionMethods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Holographic::HolographicDepthReprojectionMethod>>(this->shim().SupportedDepthReprojectionMethods());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Graphics::Holographic
{
    inline auto HolographicDisplay::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Holographic::HolographicDisplay(*)(IHolographicDisplayStatics const&), HolographicDisplay, IHolographicDisplayStatics>([](IHolographicDisplayStatics const& f) { return f.GetDefault(); });
    }
    inline HolographicQuadLayer::HolographicQuadLayer(llm::OS::Foundation::Size const& size) :
        HolographicQuadLayer(impl::call_factory<HolographicQuadLayer, IHolographicQuadLayerFactory>([&](IHolographicQuadLayerFactory const& f) { return f.Create(size); }))
    {
    }
    inline HolographicQuadLayer::HolographicQuadLayer(llm::OS::Foundation::Size const& size, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat) :
        HolographicQuadLayer(impl::call_factory<HolographicQuadLayer, IHolographicQuadLayerFactory>([&](IHolographicQuadLayerFactory const& f) { return f.CreateWithPixelFormat(size, pixelFormat); }))
    {
    }
    inline auto HolographicSpace::CreateForCoreWindow(llm::OS::UI::Core::CoreWindow const& window)
    {
        return impl::call_factory<HolographicSpace, IHolographicSpaceStatics>([&](IHolographicSpaceStatics const& f) { return f.CreateForCoreWindow(window); });
    }
    inline auto HolographicSpace::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IHolographicSpaceStatics2 const&), HolographicSpace, IHolographicSpaceStatics2>([](IHolographicSpaceStatics2 const& f) { return f.IsSupported(); });
    }
    inline auto HolographicSpace::IsAvailable()
    {
        return impl::call_factory_cast<bool(*)(IHolographicSpaceStatics2 const&), HolographicSpace, IHolographicSpaceStatics2>([](IHolographicSpaceStatics2 const& f) { return f.IsAvailable(); });
    }
    inline auto HolographicSpace::IsAvailableChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<HolographicSpace, IHolographicSpaceStatics2>([&](IHolographicSpaceStatics2 const& f) { return f.IsAvailableChanged(handler); });
    }
    inline HolographicSpace::IsAvailableChanged_revoker HolographicSpace::IsAvailableChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<HolographicSpace, llm::OS::Graphics::Holographic::IHolographicSpaceStatics2>();
        return { f, f.IsAvailableChanged(handler) };
    }
    inline auto HolographicSpace::IsAvailableChanged(llm::event_token const& token)
    {
        impl::call_factory<HolographicSpace, IHolographicSpaceStatics2>([&](IHolographicSpaceStatics2 const& f) { return f.IsAvailableChanged(token); });
    }
    inline auto HolographicSpace::IsConfigured()
    {
        return impl::call_factory_cast<bool(*)(IHolographicSpaceStatics3 const&), HolographicSpace, IHolographicSpaceStatics3>([](IHolographicSpaceStatics3 const& f) { return f.IsConfigured(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCamera6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraPose2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraRenderingParameters4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicCameraViewportParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicDisplay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicDisplay2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicDisplay3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicDisplayStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrame2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrame3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFramePrediction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFramePresentationMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFramePresentationReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrameRenderingReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrameScanoutMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicFrameScanoutReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicQuadLayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicQuadLayerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicQuadLayerUpdateParameters2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpace> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpace2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpace3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpaceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpaceStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicSpaceStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicViewConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::IHolographicViewConfiguration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicCamera> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicCameraPose> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicCameraRenderingParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicCameraViewportParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicDisplay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFramePrediction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFramePresentationMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFramePresentationReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFrameRenderingReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFrameScanoutMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicFrameScanoutReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicQuadLayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicQuadLayerUpdateParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicSpace> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Holographic::HolographicViewConfiguration> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
