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
#ifndef LLM_OS_Perception_Spatial_Surfaces_H
#define LLM_OS_Perception_Spatial_Surfaces_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Perception.Spatial.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Perception.Spatial.Surfaces.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceInfo<D>::Id() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceInfo<D>::UpdateTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo)->get_UpdateTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingOrientedBox>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceInfo<D>::TryGetBounds(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo)->TryGetBounds(*(void**)(&coordinateSystem), &value));
        return llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingOrientedBox>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceInfo<D>::TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo)->TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter, &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceInfo<D>::TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions const& options) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo)->TryComputeLatestMeshWithOptionsAsync(maxTrianglesPerCubicMeter, *(void**)(&options), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::SurfaceInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_SurfaceInfo(&value));
        return llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::TriangleIndices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_TriangleIndices(&value));
        return llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::VertexPositions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_VertexPositions(&value));
        return llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::VertexPositionScale() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_VertexPositionScale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMesh<D>::VertexNormals() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh)->get_VertexNormals(&value));
        return llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshBuffer<D>::Format() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshBuffer<D>::Stride() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer)->get_Stride(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshBuffer<D>::ElementCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer)->get_ElementCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshBuffer<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer)->get_Data(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::VertexPositionFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->get_VertexPositionFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::VertexPositionFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->put_VertexPositionFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::TriangleIndexFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->get_TriangleIndexFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::TriangleIndexFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->put_TriangleIndexFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::VertexNormalFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->get_VertexNormalFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::VertexNormalFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->put_VertexNormalFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::IncludeVertexNormals() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->get_IncludeVertexNormals(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptions<D>::IncludeVertexNormals(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions)->put_IncludeVertexNormals(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptionsStatics<D>::SupportedVertexPositionFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics)->get_SupportedVertexPositionFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptionsStatics<D>::SupportedTriangleIndexFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics)->get_SupportedTriangleIndexFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceMeshOptionsStatics<D>::SupportedVertexNormalFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics)->get_SupportedVertexNormalFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::GetObservedSurfaces() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver)->GetObservedSurfaces(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::SetBoundingVolume(llm::OS::Perception::Spatial::SpatialBoundingVolume const& bounds) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver)->SetBoundingVolume(*(void**)(&bounds)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::SetBoundingVolumes(param::iterable<llm::OS::Perception::Spatial::SpatialBoundingVolume> const& bounds) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver)->SetBoundingVolumes(*(void**)(&bounds)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceObserver, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver)->add_ObservedSurfacesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged_revoker consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceObserver, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ObservedSurfacesChanged_revoker>(this, ObservedSurfacesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver)->remove_ObservedSurfacesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserverStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_Surfaces_ISpatialSurfaceObserverStatics2<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics2)->IsSupported(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>
    {
        int32_t __stdcall get_Id(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().UpdateTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetBounds(void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingOrientedBox>>(this->shim().TryGetBounds(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>>(this->shim().TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryComputeLatestMeshWithOptionsAsync(double maxTrianglesPerCubicMeter, void* options, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh>>(this->shim().TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter, *reinterpret_cast<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>
    {
        int32_t __stdcall get_SurfaceInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo>(this->shim().SurfaceInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriangleIndices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer>(this->shim().TriangleIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexPositions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer>(this->shim().VertexPositions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexPositionScale(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().VertexPositionScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexNormals(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer>(this->shim().VertexNormals());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>
    {
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Stride(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Stride());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ElementCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ElementCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>
    {
        int32_t __stdcall get_VertexPositionFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().VertexPositionFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VertexPositionFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexPositionFormat(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriangleIndexFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().TriangleIndexFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TriangleIndexFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleIndexFormat(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexNormalFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().VertexNormalFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VertexNormalFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexNormalFormat(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeVertexNormals(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeVertexNormals());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeVertexNormals(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeVertexNormals(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics>
    {
        int32_t __stdcall get_SupportedVertexPositionFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>>(this->shim().SupportedVertexPositionFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedTriangleIndexFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>>(this->shim().SupportedTriangleIndexFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedVertexNormalFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>>(this->shim().SupportedVertexNormalFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>
    {
        int32_t __stdcall GetObservedSurfaces(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo>>(this->shim().GetObservedSurfaces());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetBoundingVolume(void* bounds) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBoundingVolume(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialBoundingVolume const*>(&bounds));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetBoundingVolumes(void* bounds) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBoundingVolumes(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Perception::Spatial::SpatialBoundingVolume> const*>(&bounds));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ObservedSurfacesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ObservedSurfacesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceObserver, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ObservedSurfacesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ObservedSurfacesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics>
    {
        int32_t __stdcall RequestAccessAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics2> : produce_base<D, llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics2>
    {
        int32_t __stdcall IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception::Spatial::Surfaces
{
    inline SpatialSurfaceMeshOptions::SpatialSurfaceMeshOptions() :
        SpatialSurfaceMeshOptions(impl::call_factory_cast<SpatialSurfaceMeshOptions(*)(llm::OS::Foundation::IActivationFactory const&), SpatialSurfaceMeshOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SpatialSurfaceMeshOptions>(); }))
    {
    }
    inline auto SpatialSurfaceMeshOptions::SupportedVertexPositionFormats()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>(*)(ISpatialSurfaceMeshOptionsStatics const&), SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>([](ISpatialSurfaceMeshOptionsStatics const& f) { return f.SupportedVertexPositionFormats(); });
    }
    inline auto SpatialSurfaceMeshOptions::SupportedTriangleIndexFormats()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>(*)(ISpatialSurfaceMeshOptionsStatics const&), SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>([](ISpatialSurfaceMeshOptionsStatics const& f) { return f.SupportedTriangleIndexFormats(); });
    }
    inline auto SpatialSurfaceMeshOptions::SupportedVertexNormalFormats()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::DirectXPixelFormat>(*)(ISpatialSurfaceMeshOptionsStatics const&), SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>([](ISpatialSurfaceMeshOptionsStatics const& f) { return f.SupportedVertexNormalFormats(); });
    }
    inline SpatialSurfaceObserver::SpatialSurfaceObserver() :
        SpatialSurfaceObserver(impl::call_factory_cast<SpatialSurfaceObserver(*)(llm::OS::Foundation::IActivationFactory const&), SpatialSurfaceObserver>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SpatialSurfaceObserver>(); }))
    {
    }
    inline auto SpatialSurfaceObserver::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>(*)(ISpatialSurfaceObserverStatics const&), SpatialSurfaceObserver, ISpatialSurfaceObserverStatics>([](ISpatialSurfaceObserverStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto SpatialSurfaceObserver::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(ISpatialSurfaceObserverStatics2 const&), SpatialSurfaceObserver, ISpatialSurfaceObserverStatics2>([](ISpatialSurfaceObserverStatics2 const& f) { return f.IsSupported(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Surfaces::SpatialSurfaceObserver> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
