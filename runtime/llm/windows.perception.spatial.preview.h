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
#ifndef LLM_OS_Perception_Spatial_Preview_H
#define LLM_OS_Perception_Spatial_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Perception.Spatial.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.Perception.Spatial.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropFrameOfReferencePreview<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropFrameOfReferencePreview<D>::NodeId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview)->get_NodeId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropFrameOfReferencePreview<D>::CoordinateSystemToNodeTransform() const
    {
        llm::OS::Foundation::Numerics::float4x4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview)->get_CoordinateSystemToNodeTransform(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics<D>::CreateCoordinateSystemForNode(llm::guid const& nodeId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics)->CreateCoordinateSystemForNode(impl::bind_in(nodeId), &result));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics<D>::CreateCoordinateSystemForNode(llm::guid const& nodeId, llm::OS::Foundation::Numerics::float3 const& relativePosition) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics)->CreateCoordinateSystemForNodeWithPosition(impl::bind_in(nodeId), impl::bind_in(relativePosition), &result));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics<D>::CreateCoordinateSystemForNode(llm::guid const& nodeId, llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics)->CreateCoordinateSystemForNodeWithPositionAndOrientation(impl::bind_in(nodeId), impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), &result));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocator) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics<D>::CreateLocatorForNode(llm::guid const& nodeId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics)->CreateLocatorForNode(impl::bind_in(nodeId), &result));
        return llm::OS::Perception::Spatial::SpatialLocator{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics2<D>::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2)->TryCreateFrameOfReference(*(void**)(&coordinateSystem), &result));
        return llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics2<D>::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& relativePosition) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2)->TryCreateFrameOfReferenceWithPosition(*(void**)(&coordinateSystem), impl::bind_in(relativePosition), &result));
        return llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview) consume_Windows_Perception_Spatial_Preview_ISpatialGraphInteropPreviewStatics2<D>::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2)->TryCreateFrameOfReferenceWithPositionAndOrientation(*(void**)(&coordinateSystem), impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), &result));
        return llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview> : produce_base<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview>
    {
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NodeId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().NodeId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSystemToNodeTransform(llm::OS::Foundation::Numerics::float4x4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4x4>(this->shim().CoordinateSystemToNodeTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics> : produce_base<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics>
    {
        int32_t __stdcall CreateCoordinateSystemForNode(llm::guid nodeId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CreateCoordinateSystemForNode(*reinterpret_cast<llm::guid const*>(&nodeId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCoordinateSystemForNodeWithPosition(llm::guid nodeId, llm::OS::Foundation::Numerics::float3 relativePosition, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CreateCoordinateSystemForNode(*reinterpret_cast<llm::guid const*>(&nodeId), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCoordinateSystemForNodeWithPositionAndOrientation(llm::guid nodeId, llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CreateCoordinateSystemForNode(*reinterpret_cast<llm::guid const*>(&nodeId), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLocatorForNode(llm::guid nodeId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::SpatialLocator>(this->shim().CreateLocatorForNode(*reinterpret_cast<llm::guid const*>(&nodeId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2> : produce_base<D, llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2>
    {
        int32_t __stdcall TryCreateFrameOfReference(void* coordinateSystem, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview>(this->shim().TryCreateFrameOfReference(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateFrameOfReferenceWithPosition(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 relativePosition, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview>(this->shim().TryCreateFrameOfReference(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateFrameOfReferenceWithPositionAndOrientation(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview>(this->shim().TryCreateFrameOfReference(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception::Spatial::Preview
{
    inline auto SpatialGraphInteropPreview::CreateCoordinateSystemForNode(llm::guid const& nodeId)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics>([&](ISpatialGraphInteropPreviewStatics const& f) { return f.CreateCoordinateSystemForNode(nodeId); });
    }
    inline auto SpatialGraphInteropPreview::CreateCoordinateSystemForNode(llm::guid const& nodeId, llm::OS::Foundation::Numerics::float3 const& relativePosition)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics>([&](ISpatialGraphInteropPreviewStatics const& f) { return f.CreateCoordinateSystemForNode(nodeId, relativePosition); });
    }
    inline auto SpatialGraphInteropPreview::CreateCoordinateSystemForNode(llm::guid const& nodeId, llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics>([&](ISpatialGraphInteropPreviewStatics const& f) { return f.CreateCoordinateSystemForNode(nodeId, relativePosition, relativeOrientation); });
    }
    inline auto SpatialGraphInteropPreview::CreateLocatorForNode(llm::guid const& nodeId)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics>([&](ISpatialGraphInteropPreviewStatics const& f) { return f.CreateLocatorForNode(nodeId); });
    }
    inline auto SpatialGraphInteropPreview::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics2>([&](ISpatialGraphInteropPreviewStatics2 const& f) { return f.TryCreateFrameOfReference(coordinateSystem); });
    }
    inline auto SpatialGraphInteropPreview::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& relativePosition)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics2>([&](ISpatialGraphInteropPreviewStatics2 const& f) { return f.TryCreateFrameOfReference(coordinateSystem, relativePosition); });
    }
    inline auto SpatialGraphInteropPreview::TryCreateFrameOfReference(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation)
    {
        return impl::call_factory<SpatialGraphInteropPreview, ISpatialGraphInteropPreviewStatics2>([&](ISpatialGraphInteropPreviewStatics2 const& f) { return f.TryCreateFrameOfReference(coordinateSystem, relativePosition, relativeOrientation); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropFrameOfReferencePreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Preview::ISpatialGraphInteropPreviewStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Preview::SpatialGraphInteropFrameOfReferencePreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::Preview::SpatialGraphInteropPreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
