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
#ifndef LLM_OS_ApplicationModel_Preview_Holographic_H
#define LLM_OS_ApplicationModel_Preview_Holographic_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.ApplicationModel.Preview.Holographic.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicApplicationPreviewStatics<D>::IsCurrentViewPresentedOnHolographicDisplay() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicApplicationPreviewStatics)->IsCurrentViewPresentedOnHolographicDisplay(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicApplicationPreviewStatics<D>::IsHolographicActivation(llm::OS::ApplicationModel::Activation::IActivatedEventArgs const& activatedEventArgs) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicApplicationPreviewStatics)->IsHolographicActivation(*(void**)(&activatedEventArgs), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicKeyboardPlacementOverridePreview<D>::SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::float3 const& normal) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview)->SetPlacementOverride(*(void**)(&coordinateSystem), impl::bind_in(topCenterPosition), impl::bind_in(normal)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicKeyboardPlacementOverridePreview<D>::SetPlacementOverride(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& topCenterPosition, llm::OS::Foundation::Numerics::float3 const& normal, llm::OS::Foundation::Numerics::float2 const& maxSize) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview)->SetPlacementOverrideWithMaxSize(*(void**)(&coordinateSystem), impl::bind_in(topCenterPosition), impl::bind_in(normal), impl::bind_in(maxSize)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicKeyboardPlacementOverridePreview<D>::ResetPlacementOverride() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview)->ResetPlacementOverride());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Preview::Holographic::HolographicKeyboardPlacementOverridePreview) consume_Windows_ApplicationModel_Preview_Holographic_IHolographicKeyboardPlacementOverridePreviewStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreviewStatics)->GetForCurrentView(&result));
        return llm::OS::ApplicationModel::Preview::Holographic::HolographicKeyboardPlacementOverridePreview{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicApplicationPreviewStatics> : produce_base<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicApplicationPreviewStatics>
    {
        int32_t __stdcall IsCurrentViewPresentedOnHolographicDisplay(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsCurrentViewPresentedOnHolographicDisplay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsHolographicActivation(void* activatedEventArgs, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsHolographicActivation(*reinterpret_cast<llm::OS::ApplicationModel::Activation::IActivatedEventArgs const*>(&activatedEventArgs)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview> : produce_base<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview>
    {
        int32_t __stdcall SetPlacementOverride(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 topCenterPosition, llm::OS::Foundation::Numerics::float3 normal) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlacementOverride(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&topCenterPosition), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&normal));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPlacementOverrideWithMaxSize(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 topCenterPosition, llm::OS::Foundation::Numerics::float3 normal, llm::OS::Foundation::Numerics::float2 maxSize) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlacementOverride(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&topCenterPosition), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&normal), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&maxSize));
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
    struct produce<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreviewStatics> : produce_base<D, llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreviewStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Preview::Holographic::HolographicKeyboardPlacementOverridePreview>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Holographic
{
    inline auto HolographicApplicationPreview::IsCurrentViewPresentedOnHolographicDisplay()
    {
        return impl::call_factory_cast<bool(*)(IHolographicApplicationPreviewStatics const&), HolographicApplicationPreview, IHolographicApplicationPreviewStatics>([](IHolographicApplicationPreviewStatics const& f) { return f.IsCurrentViewPresentedOnHolographicDisplay(); });
    }
    inline auto HolographicApplicationPreview::IsHolographicActivation(llm::OS::ApplicationModel::Activation::IActivatedEventArgs const& activatedEventArgs)
    {
        return impl::call_factory<HolographicApplicationPreview, IHolographicApplicationPreviewStatics>([&](IHolographicApplicationPreviewStatics const& f) { return f.IsHolographicActivation(activatedEventArgs); });
    }
    inline auto HolographicKeyboardPlacementOverridePreview::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Preview::Holographic::HolographicKeyboardPlacementOverridePreview(*)(IHolographicKeyboardPlacementOverridePreviewStatics const&), HolographicKeyboardPlacementOverridePreview, IHolographicKeyboardPlacementOverridePreviewStatics>([](IHolographicKeyboardPlacementOverridePreviewStatics const& f) { return f.GetForCurrentView(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Preview::Holographic::IHolographicApplicationPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Holographic::HolographicApplicationPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Preview::Holographic::HolographicKeyboardPlacementOverridePreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
