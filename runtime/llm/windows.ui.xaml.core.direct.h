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
#ifndef LLM_OS_UI_Xaml_Core_Direct_H
#define LLM_OS_UI_Xaml_Core_Direct_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Media.2.h"
#include "llm/impl/Windows.UI.Xaml.Media.Media3D.2.h"
#include "llm/impl/Windows.UI.Xaml.Core.Direct.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetObject(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetObject(*(void**)(&xamlDirectObject), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetXamlDirectObject(llm::OS::Foundation::IInspectable const& object) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetXamlDirectObject(*(void**)(&object), &result));
        return llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::CreateInstance(llm::OS::UI::Xaml::Core::Direct::XamlTypeIndex const& typeIndex) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->CreateInstance(static_cast<int32_t>(typeIndex), &result));
        return llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetObjectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetObjectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetXamlDirectObjectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetXamlDirectObjectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetBooleanProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetBooleanProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetDoubleProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetDoubleProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetInt32Property(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetInt32Property(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetStringProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetStringProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetDateTimeProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::DateTime const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetDateTimeProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetPointProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::Point const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetPointProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetRectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetRectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetSizeProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetSizeProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetTimeSpanProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetTimeSpanProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetColorProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetColorProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetCornerRadiusProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::CornerRadius const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetCornerRadiusProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetDurationProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::Duration const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetDurationProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetGridLengthProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::GridLength const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetGridLengthProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetThicknessProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::Thickness const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetThicknessProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetMatrixProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::Media::Matrix const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetMatrixProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetMatrix3DProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, llm::OS::UI::Xaml::Media::Media3D::Matrix3D const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetMatrix3DProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::SetEnumProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex, uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->SetEnumProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetObjectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetObjectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetXamlDirectObjectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetXamlDirectObjectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetBooleanProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetBooleanProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetDoubleProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        double result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetDoubleProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetInt32Property(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetInt32Property(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetStringProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetStringProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetDateTimeProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::Foundation::DateTime result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetDateTimeProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetPointProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetPointProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetRectProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::Foundation::Rect result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetRectProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetSizeProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::Foundation::Size result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetSizeProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetTimeSpanProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::Foundation::TimeSpan result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetTimeSpanProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetColorProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Color result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetColorProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::CornerRadius) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetCornerRadiusProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::CornerRadius result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetCornerRadiusProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Duration) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetDurationProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::Duration result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetDurationProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::GridLength) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetGridLengthProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::GridLength result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetGridLengthProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Thickness) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetThicknessProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::Thickness result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetThicknessProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Matrix) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetMatrixProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::Media::Matrix result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetMatrixProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Media::Media3D::Matrix3D) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetMatrix3DProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        llm::OS::UI::Xaml::Media::Media3D::Matrix3D result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetMatrix3DProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetEnumProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        uint32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetEnumProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::ClearProperty(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const& propertyIndex) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->ClearProperty(*(void**)(&xamlDirectObject), static_cast<int32_t>(propertyIndex)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetCollectionCount(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject) const
    {
        uint32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetCollectionCount(*(void**)(&xamlDirectObject), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::GetXamlDirectObjectFromCollectionAt(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, uint32_t index) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->GetXamlDirectObjectFromCollectionAt(*(void**)(&xamlDirectObject), index, &result));
        return llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::AddToCollection(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->AddToCollection(*(void**)(&xamlDirectObject), *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::InsertIntoCollectionAt(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, uint32_t index, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->InsertIntoCollectionAt(*(void**)(&xamlDirectObject), index, *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::RemoveFromCollection(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& value) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->RemoveFromCollection(*(void**)(&xamlDirectObject), *(void**)(&value), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::RemoveFromCollectionAt(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, uint32_t index) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->RemoveFromCollectionAt(*(void**)(&xamlDirectObject), index));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::ClearCollection(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->ClearCollection(*(void**)(&xamlDirectObject)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::AddEventHandler(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const& eventIndex, llm::OS::Foundation::IInspectable const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->AddEventHandler(*(void**)(&xamlDirectObject), static_cast<int32_t>(eventIndex), *(void**)(&handler)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::AddEventHandler(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const& eventIndex, llm::OS::Foundation::IInspectable const& handler, bool handledEventsToo) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->AddEventHandler_HandledEventsToo(*(void**)(&xamlDirectObject), static_cast<int32_t>(eventIndex), *(void**)(&handler), handledEventsToo));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Core_Direct_IXamlDirect<D>::RemoveEventHandler(llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const& xamlDirectObject, llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const& eventIndex, llm::OS::Foundation::IInspectable const& handler) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirect)->RemoveEventHandler(*(void**)(&xamlDirectObject), static_cast<int32_t>(eventIndex), *(void**)(&handler)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Core::Direct::XamlDirect) consume_Windows_UI_Xaml_Core_Direct_IXamlDirectStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Core::Direct::IXamlDirectStatics)->GetDefault(&result));
        return llm::OS::UI::Xaml::Core::Direct::XamlDirect{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirect> : produce_base<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirect>
    {
        int32_t __stdcall GetObject(void* xamlDirectObject, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetObject(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetXamlDirectObject(void* object, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject>(this->shim().GetXamlDirectObject(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&object)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInstance(int32_t typeIndex, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlTypeIndex const*>(&typeIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetObjectProperty(void* xamlDirectObject, int32_t propertyIndex, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetObjectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetXamlDirectObjectProperty(void* xamlDirectObject, int32_t propertyIndex, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetXamlDirectObjectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetBooleanProperty(void* xamlDirectObject, int32_t propertyIndex, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBooleanProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDoubleProperty(void* xamlDirectObject, int32_t propertyIndex, double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDoubleProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInt32Property(void* xamlDirectObject, int32_t propertyIndex, int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInt32Property(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetStringProperty(void* xamlDirectObject, int32_t propertyIndex, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStringProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDateTimeProperty(void* xamlDirectObject, int32_t propertyIndex, int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDateTimeProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::DateTime const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPointProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Point value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::Point const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetRectProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSizeProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSizeProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetTimeSpanProperty(void* xamlDirectObject, int32_t propertyIndex, int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTimeSpanProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCornerRadiusProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_CornerRadius value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCornerRadiusProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::CornerRadius const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDurationProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Duration value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDurationProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::Duration const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetGridLengthProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_GridLength value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetGridLengthProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::GridLength const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetThicknessProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Thickness value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetThicknessProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::Thickness const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMatrixProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Media_Matrix value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrixProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::Media::Matrix const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMatrix3DProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Media_Media3D_Matrix3D value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrix3DProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), *reinterpret_cast<llm::OS::UI::Xaml::Media::Media3D::Matrix3D const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEnumProperty(void* xamlDirectObject, int32_t propertyIndex, uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEnumProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetObjectProperty(void* xamlDirectObject, int32_t propertyIndex, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetObjectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetXamlDirectObjectProperty(void* xamlDirectObject, int32_t propertyIndex, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject>(this->shim().GetXamlDirectObjectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBooleanProperty(void* xamlDirectObject, int32_t propertyIndex, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().GetBooleanProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDoubleProperty(void* xamlDirectObject, int32_t propertyIndex, double* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<double>(this->shim().GetDoubleProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInt32Property(void* xamlDirectObject, int32_t propertyIndex, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetInt32Property(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStringProperty(void* xamlDirectObject, int32_t propertyIndex, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetStringProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDateTimeProperty(void* xamlDirectObject, int32_t propertyIndex, int64_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::DateTime>(this->shim().GetDateTimeProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPointProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().GetPointProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRectProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Rect* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Rect>(this->shim().GetRectProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSizeProperty(void* xamlDirectObject, int32_t propertyIndex, llm::OS::Foundation::Size* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Size>(this->shim().GetSizeProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTimeSpanProperty(void* xamlDirectObject, int32_t propertyIndex, int64_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().GetTimeSpanProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetColorProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Color* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Color>(this->shim().GetColorProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCornerRadiusProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_CornerRadius* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::CornerRadius>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::CornerRadius>(this->shim().GetCornerRadiusProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDurationProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Duration* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Duration>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Duration>(this->shim().GetDurationProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGridLengthProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_GridLength* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::GridLength>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::GridLength>(this->shim().GetGridLengthProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetThicknessProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Thickness* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Thickness>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Thickness>(this->shim().GetThicknessProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMatrixProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Media_Matrix* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Media::Matrix>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Media::Matrix>(this->shim().GetMatrixProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMatrix3DProperty(void* xamlDirectObject, int32_t propertyIndex, struct struct_Windows_UI_Xaml_Media_Media3D_Matrix3D* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Media::Media3D::Matrix3D>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Media::Media3D::Matrix3D>(this->shim().GetMatrix3DProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetEnumProperty(void* xamlDirectObject, int32_t propertyIndex, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<uint32_t>(this->shim().GetEnumProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearProperty(void* xamlDirectObject, int32_t propertyIndex) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearProperty(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlPropertyIndex const*>(&propertyIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCollectionCount(void* xamlDirectObject, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<uint32_t>(this->shim().GetCollectionCount(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetXamlDirectObjectFromCollectionAt(void* xamlDirectObject, uint32_t index, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject>(this->shim().GetXamlDirectObjectFromCollectionAt(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), index));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddToCollection(void* xamlDirectObject, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToCollection(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertIntoCollectionAt(void* xamlDirectObject, uint32_t index, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertIntoCollectionAt(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), index, *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveFromCollection(void* xamlDirectObject, void* value, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().RemoveFromCollection(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveFromCollectionAt(void* xamlDirectObject, uint32_t index) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFromCollectionAt(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), index);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearCollection(void* xamlDirectObject) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearCollection(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddEventHandler(void* xamlDirectObject, int32_t eventIndex, void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEventHandler(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const*>(&eventIndex), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddEventHandler_HandledEventsToo(void* xamlDirectObject, int32_t eventIndex, void* handler, bool handledEventsToo) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddEventHandler(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const*>(&eventIndex), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&handler), handledEventsToo);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveEventHandler(void* xamlDirectObject, int32_t eventIndex, void* handler) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveEventHandler(*reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject const*>(&xamlDirectObject), *reinterpret_cast<llm::OS::UI::Xaml::Core::Direct::XamlEventIndex const*>(&eventIndex), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&handler));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject> : produce_base<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirectStatics> : produce_base<D, llm::OS::UI::Xaml::Core::Direct::IXamlDirectStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Core::Direct::XamlDirect>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Core::Direct
{
    inline auto XamlDirect::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::Core::Direct::XamlDirect(*)(IXamlDirectStatics const&), XamlDirect, IXamlDirectStatics>([](IXamlDirectStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Core::Direct::IXamlDirect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Core::Direct::IXamlDirectObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Core::Direct::IXamlDirectStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Core::Direct::XamlDirect> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
