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
#ifndef LLM_OS_ApplicationModel_Holographic_H
#define LLM_OS_ApplicationModel_Holographic_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.ApplicationModel.Holographic.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Holographic_IHolographicKeyboard<D>::SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::quaternion const& orientation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Holographic::IHolographicKeyboard)->SetPlacementOverride(*(void**)(&coordinateSystem), impl::bind_in(topCenterPosition), impl::bind_in(orientation)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Holographic_IHolographicKeyboard<D>::SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::quaternion const& orientation, llm::OS::Foundation::Numerics::float2 const& maxSize) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Holographic::IHolographicKeyboard)->SetPlacementOverrideWithMaxSize(*(void**)(&coordinateSystem), impl::bind_in(topCenterPosition), impl::bind_in(orientation), impl::bind_in(maxSize)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Holographic_IHolographicKeyboard<D>::ResetPlacementOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Holographic::IHolographicKeyboard)->ResetPlacementOverride());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Holographic::HolographicKeyboard) consume_Windows_ApplicationModel_Holographic_IHolographicKeyboardStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics)->GetDefault(&result));
        return llm::OS::ApplicationModel::Holographic::HolographicKeyboard{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Holographic::IHolographicKeyboard> : produce_base<D, llm::OS::ApplicationModel::Holographic::IHolographicKeyboard>
    {
        int32_t __stdcall SetPlacementOverride(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 topCenterPosition, llm::OS::Foundation::Numerics::quaternion orientation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlacementOverride(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&topCenterPosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&orientation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPlacementOverrideWithMaxSize(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 topCenterPosition, llm::OS::Foundation::Numerics::quaternion orientation, llm::OS::Foundation::Numerics::float2 maxSize) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlacementOverride(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&topCenterPosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&orientation), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&maxSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResetPlacementOverride() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetPlacementOverride();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics> : produce_base<D, llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Holographic::HolographicKeyboard>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Holographic
{
    inline auto HolographicKeyboard::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Holographic::HolographicKeyboard(*)(IHolographicKeyboardStatics const&), HolographicKeyboard, IHolographicKeyboardStatics>([](IHolographicKeyboardStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Holographic::IHolographicKeyboard> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Holographic::IHolographicKeyboardStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Holographic::HolographicKeyboard> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
