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
#ifndef LLM_OS_Graphics_Printing3D_H
#define LLM_OS_Graphics_Printing3D_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Graphics.Printing3D.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing3D_IPrint3DManager<D>::TaskRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DManager, llm::OS::Graphics::Printing3D::Print3DTaskRequestedEventArgs> const& eventHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DManager)->add_TaskRequested(*(void**)(&eventHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Graphics_Printing3D_IPrint3DManager<D>::TaskRequested_revoker consume_Windows_Graphics_Printing3D_IPrint3DManager<D>::TaskRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DManager, llm::OS::Graphics::Printing3D::Print3DTaskRequestedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, TaskRequested_revoker>(this, TaskRequested(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrint3DManager<D>::TaskRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DManager)->remove_TaskRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Print3DManager) consume_Windows_Graphics_Printing3D_IPrint3DManagerStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DManagerStatics)->GetForCurrentView(&result));
        return llm::OS::Graphics::Printing3D::Print3DManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Printing3D_IPrint3DManagerStatics<D>::ShowPrintUIAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DManagerStatics)->ShowPrintUIAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3D3MFPackage) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->get_Source(&value));
        return llm::OS::Graphics::Printing3D::Printing3D3MFPackage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Submitting(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->add_Submitting(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Submitting_revoker consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Submitting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        return impl::make_event_revoker<D, Submitting_revoker>(this, Submitting(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Submitting(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->remove_Submitting(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Completed(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskCompletedEventArgs> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->add_Completed(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Completed_revoker consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Completed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskCompletedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, Completed_revoker>(this, Completed(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::Completed(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->remove_Completed(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::SourceChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->add_SourceChanged(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::SourceChanged_revoker consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::SourceChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, SourceChanged_revoker>(this, SourceChanged(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrint3DTask<D>::SourceChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTask)->remove_SourceChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Print3DTaskCompletion) consume_Windows_Graphics_Printing3D_IPrint3DTaskCompletedEventArgs<D>::Completion() const
    {
        llm::OS::Graphics::Printing3D::Print3DTaskCompletion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs)->get_Completion(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Print3DTaskDetail) consume_Windows_Graphics_Printing3D_IPrint3DTaskCompletedEventArgs<D>::ExtendedStatus() const
    {
        llm::OS::Graphics::Printing3D::Print3DTaskDetail value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs)->get_ExtendedStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Print3DTask) consume_Windows_Graphics_Printing3D_IPrint3DTaskRequest<D>::CreateTask(param::hstring const& title, param::hstring const& printerId, llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedHandler const& handler) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskRequest)->CreateTask(*(void**)(&title), *(void**)(&printerId), *(void**)(&handler), &result));
        return llm::OS::Graphics::Printing3D::Print3DTask{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Print3DTaskRequest) consume_Windows_Graphics_Printing3D_IPrint3DTaskRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs)->get_Request(&value));
        return llm::OS::Graphics::Printing3D::Print3DTaskRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3D3MFPackage) consume_Windows_Graphics_Printing3D_IPrint3DTaskSourceChangedEventArgs<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs)->get_Source(&value));
        return llm::OS::Graphics::Printing3D::Printing3D3MFPackage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrint3DTaskSourceRequestedArgs<D>::SetSource(llm::OS::Graphics::Printing3D::Printing3D3MFPackage const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs)->SetSource(*(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::SaveAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->SaveAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::PrintTicket() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->get_PrintTicket(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::PrintTicket(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->put_PrintTicket(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::ModelPart() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->get_ModelPart(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::ModelPart(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->put_ModelPart(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTextureResource) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->get_Thumbnail(&value));
        return llm::OS::Graphics::Printing3D::Printing3DTextureResource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::Thumbnail(llm::OS::Graphics::Printing3D::Printing3DTextureResource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTextureResource>) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::Textures() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->get_Textures(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTextureResource>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DModel>) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::LoadModelFromPackageAsync(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->LoadModelFromPackageAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DModel>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage<D>::SaveModelToPackageAsync(llm::OS::Graphics::Printing3D::Printing3DModel const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage)->SaveModelToPackageAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DPackageCompression) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage2<D>::Compression() const
    {
        llm::OS::Graphics::Printing3D::Printing3DPackageCompression value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage2)->get_Compression(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackage2<D>::Compression(llm::OS::Graphics::Printing3D::Printing3DPackageCompression const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage2)->put_Compression(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3D3MFPackage>) consume_Windows_Graphics_Printing3D_IPrinting3D3MFPackageStatics<D>::LoadAsync(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3D3MFPackageStatics)->LoadAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3D3MFPackage>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterial<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterial<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DColorMaterial) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterial<D>::Color() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial)->get_Color(&value));
        return llm::OS::Graphics::Printing3D::Printing3DColorMaterial{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterial<D>::Color(llm::OS::Graphics::Printing3D::Printing3DColorMaterial const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial)->put_Color(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterial>) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterialGroup<D>::Bases() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroup)->get_Bases(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterial>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterialGroup<D>::MaterialGroupId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroup)->get_MaterialGroupId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory)->Create(MaterialGroupId, &result));
        return llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterialStatics<D>::Abs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialStatics)->get_Abs(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DBaseMaterialStatics<D>::Pla() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialStatics)->get_Pla(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterial<D>::Value() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial)->get_Value(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterial<D>::Value(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial)->put_Value(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterial2<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial2)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterial2<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial2)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterial>) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterialGroup<D>::Colors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroup)->get_Colors(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterial>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterialGroup<D>::MaterialGroupId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroup)->get_MaterialGroupId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DColorMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory)->Create(MaterialGroupId, &result));
        return llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DMesh) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Mesh() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_Mesh(&value));
        return llm::OS::Graphics::Printing3D::Printing3DMesh{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Mesh(llm::OS::Graphics::Printing3D::Printing3DMesh const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->put_Mesh(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponentWithMatrix>) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Components() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_Components(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponentWithMatrix>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTextureResource) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Thumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_Thumbnail(&value));
        return llm::OS::Graphics::Printing3D::Printing3DTextureResource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Thumbnail(llm::OS::Graphics::Printing3D::Printing3DTextureResource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->put_Thumbnail(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DObjectType) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Type() const
    {
        llm::OS::Graphics::Printing3D::Printing3DObjectType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Type(llm::OS::Graphics::Printing3D::Printing3DObjectType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->put_Type(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::PartNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->get_PartNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponent<D>::PartNumber(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponent)->put_PartNumber(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DComponent) consume_Windows_Graphics_Printing3D_IPrinting3DComponentWithMatrix<D>::Component() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix)->get_Component(&value));
        return llm::OS::Graphics::Printing3D::Printing3DComponent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponentWithMatrix<D>::Component(llm::OS::Graphics::Printing3D::Printing3DComponent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix)->put_Component(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) consume_Windows_Graphics_Printing3D_IPrinting3DComponentWithMatrix<D>::Matrix() const
    {
        llm::OS::Foundation::Numerics::float4x4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix)->get_Matrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DComponentWithMatrix<D>::Matrix(llm::OS::Foundation::Numerics::float4x4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix)->put_Matrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<double>) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterial<D>::Values() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterial)->get_Values(&value));
        return llm::OS::Foundation::Collections::IVector<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterial>) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroup<D>::Composites() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup)->get_Composites(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterial>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroup<D>::MaterialGroupId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup)->get_MaterialGroupId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<uint32_t>) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroup<D>::MaterialIndices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup)->get_MaterialIndices(&value));
        return llm::OS::Foundation::Collections::IVector<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroup2<D>::BaseMaterialGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2)->get_BaseMaterialGroup(&value));
        return llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroup2<D>::BaseMaterialGroup(llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2)->put_BaseMaterialGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DCompositeMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory)->Create(MaterialGroupId, &result));
        return llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::MaxReductionArea() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->get_MaxReductionArea(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::MaxReductionArea(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->put_MaxReductionArea(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::TargetTriangleCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->get_TargetTriangleCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::TargetTriangleCount(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->put_TargetTriangleCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::MaxEdgeLength() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->get_MaxEdgeLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DFaceReductionOptions<D>::MaxEdgeLength(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions)->put_MaxEdgeLength(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup>) consume_Windows_Graphics_Printing3D_IPrinting3DMaterial<D>::BaseGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMaterial)->get_BaseGroups(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup>) consume_Windows_Graphics_Printing3D_IPrinting3DMaterial<D>::ColorGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMaterial)->get_ColorGroups(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup>) consume_Windows_Graphics_Printing3D_IPrinting3DMaterial<D>::Texture2CoordGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMaterial)->get_Texture2CoordGroups(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup>) consume_Windows_Graphics_Printing3D_IPrinting3DMaterial<D>::CompositeGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMaterial)->get_CompositeGroups(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup>) consume_Windows_Graphics_Printing3D_IPrinting3DMaterial<D>::MultiplePropertyGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMaterial)->get_MultiplePropertyGroups(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_VertexCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexCount(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_VertexCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::IndexCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_IndexCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::IndexCount(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_IndexCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBufferDescription) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexPositionsDescription() const
    {
        llm::OS::Graphics::Printing3D::Printing3DBufferDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_VertexPositionsDescription(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexPositionsDescription(llm::OS::Graphics::Printing3D::Printing3DBufferDescription const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_VertexPositionsDescription(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBufferDescription) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexNormalsDescription() const
    {
        llm::OS::Graphics::Printing3D::Printing3DBufferDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_VertexNormalsDescription(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VertexNormalsDescription(llm::OS::Graphics::Printing3D::Printing3DBufferDescription const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_VertexNormalsDescription(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBufferDescription) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::TriangleIndicesDescription() const
    {
        llm::OS::Graphics::Printing3D::Printing3DBufferDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_TriangleIndicesDescription(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::TriangleIndicesDescription(llm::OS::Graphics::Printing3D::Printing3DBufferDescription const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_TriangleIndicesDescription(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DBufferDescription) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::TriangleMaterialIndicesDescription() const
    {
        llm::OS::Graphics::Printing3D::Printing3DBufferDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_TriangleMaterialIndicesDescription(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::TriangleMaterialIndicesDescription(llm::OS::Graphics::Printing3D::Printing3DBufferDescription const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->put_TriangleMaterialIndicesDescription(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::GetVertexPositions() const
    {
        void* buffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->GetVertexPositions(&buffer));
        return llm::OS::Storage::Streams::IBuffer{ buffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::CreateVertexPositions(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->CreateVertexPositions(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::GetVertexNormals() const
    {
        void* buffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->GetVertexNormals(&buffer));
        return llm::OS::Storage::Streams::IBuffer{ buffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::CreateVertexNormals(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->CreateVertexNormals(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::GetTriangleIndices() const
    {
        void* buffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->GetTriangleIndices(&buffer));
        return llm::OS::Storage::Streams::IBuffer{ buffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::CreateTriangleIndices(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->CreateTriangleIndices(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::GetTriangleMaterialIndices() const
    {
        void* buffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->GetTriangleMaterialIndices(&buffer));
        return llm::OS::Storage::Streams::IBuffer{ buffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::CreateTriangleMaterialIndices(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->CreateTriangleMaterialIndices(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::BufferDescriptionSet() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_BufferDescriptionSet(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::BufferSet() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->get_BufferSet(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DMeshVerificationResult>) consume_Windows_Graphics_Printing3D_IPrinting3DMesh<D>::VerifyAsync(llm::OS::Graphics::Printing3D::Printing3DMeshVerificationMode const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMesh)->VerifyAsync(static_cast<int32_t>(value), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DMeshVerificationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Graphics_Printing3D_IPrinting3DMeshVerificationResult<D>::IsValid() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult)->get_IsValid(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Graphics_Printing3D_IPrinting3DMeshVerificationResult<D>::NonmanifoldTriangles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult)->get_NonmanifoldTriangles(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Graphics_Printing3D_IPrinting3DMeshVerificationResult<D>::ReversedNormalTriangles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult)->get_ReversedNormalTriangles(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DModelUnit) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Unit() const
    {
        llm::OS::Graphics::Printing3D::Printing3DModelUnit value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Unit(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Unit(llm::OS::Graphics::Printing3D::Printing3DModelUnit const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->put_Unit(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DModelTexture>) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Textures() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Textures(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DModelTexture>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMesh>) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Meshes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Meshes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMesh>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponent>) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Components() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Components(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponent>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DMaterial) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Material() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Material(&value));
        return llm::OS::Graphics::Printing3D::Printing3DMaterial{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Material(llm::OS::Graphics::Printing3D::Printing3DMaterial const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->put_Material(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DComponent) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Build() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Build(&value));
        return llm::OS::Graphics::Printing3D::Printing3DComponent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Build(llm::OS::Graphics::Printing3D::Printing3DComponent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->put_Build(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Version() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Version(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Version(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->put_Version(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::RequiredExtensions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_RequiredExtensions(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Metadata() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->get_Metadata(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::RepairAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->RepairAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DModel) consume_Windows_Graphics_Printing3D_IPrinting3DModel<D>::Clone() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel)->Clone(&value));
        return llm::OS::Graphics::Printing3D::Printing3DModel{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::TryPartialRepairAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->TryPartialRepairAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::TryPartialRepairAsync(llm::OS::Foundation::TimeSpan const& maxWaitTime) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->TryPartialRepairWithTimeAsync(impl::bind_in(maxWaitTime), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::TryReduceFacesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->TryReduceFacesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::TryReduceFacesAsync(llm::OS::Graphics::Printing3D::Printing3DFaceReductionOptions const& printing3DFaceReductionOptions) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->TryReduceFacesWithOptionsAsync(*(void**)(&printing3DFaceReductionOptions), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::TryReduceFacesAsync(llm::OS::Graphics::Printing3D::Printing3DFaceReductionOptions const& printing3DFaceReductionOptions, llm::OS::Foundation::TimeSpan const& maxWait) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->TryReduceFacesWithOptionsAndTimeAsync(*(void**)(&printing3DFaceReductionOptions), impl::bind_in(maxWait), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>) consume_Windows_Graphics_Printing3D_IPrinting3DModel2<D>::RepairWithProgressAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModel2)->RepairWithProgressAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTextureResource) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TextureResource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->get_TextureResource(&value));
        return llm::OS::Graphics::Printing3D::Printing3DTextureResource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TextureResource(llm::OS::Graphics::Printing3D::Printing3DTextureResource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->put_TextureResource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TileStyleU() const
    {
        llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->get_TileStyleU(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TileStyleU(llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->put_TileStyleU(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TileStyleV() const
    {
        llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->get_TileStyleV(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DModelTexture<D>::TileStyleV(llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DModelTexture)->put_TileStyleV(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<uint32_t>) consume_Windows_Graphics_Printing3D_IPrinting3DMultiplePropertyMaterial<D>::MaterialIndices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial)->get_MaterialIndices(&value));
        return llm::OS::Foundation::Collections::IVector<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterial>) consume_Windows_Graphics_Printing3D_IPrinting3DMultiplePropertyMaterialGroup<D>::MultipleProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup)->get_MultipleProperties(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterial>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<uint32_t>) consume_Windows_Graphics_Printing3D_IPrinting3DMultiplePropertyMaterialGroup<D>::MaterialGroupIndices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup)->get_MaterialGroupIndices(&value));
        return llm::OS::Foundation::Collections::IVector<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DMultiplePropertyMaterialGroup<D>::MaterialGroupId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup)->get_MaterialGroupId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DMultiplePropertyMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory)->Create(MaterialGroupId, &result));
        return llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DModelTexture) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::Texture() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->get_Texture(&value));
        return llm::OS::Graphics::Printing3D::Printing3DModelTexture{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::Texture(llm::OS::Graphics::Printing3D::Printing3DModelTexture const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->put_Texture(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::U() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->get_U(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::U(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->put_U(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::V() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->get_V(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterial<D>::V(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial)->put_V(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterial>) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterialGroup<D>::Texture2Coords() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup)->get_Texture2Coords(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterial>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterialGroup<D>::MaterialGroupId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup)->get_MaterialGroupId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DModelTexture) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterialGroup2<D>::Texture() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2)->get_Texture(&value));
        return llm::OS::Graphics::Printing3D::Printing3DModelTexture{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterialGroup2<D>::Texture(llm::OS::Graphics::Printing3D::Printing3DModelTexture const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2)->put_Texture(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup) consume_Windows_Graphics_Printing3D_IPrinting3DTexture2CoordMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory)->Create(MaterialGroupId, &result));
        return llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType) consume_Windows_Graphics_Printing3D_IPrinting3DTextureResource<D>::TextureData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTextureResource)->get_TextureData(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamWithContentType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTextureResource<D>::TextureData(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTextureResource)->put_TextureData(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Printing3D_IPrinting3DTextureResource<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTextureResource)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Printing3D_IPrinting3DTextureResource<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Printing3D::IPrinting3DTextureResource)->put_Name(*(void**)(&value)));
    }
    template <typename H> struct delegate<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedHandler, H> final : implements_delegate<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* args) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedArgs const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DManager> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DManager>
    {
        int32_t __stdcall add_TaskRequested(void* eventHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TaskRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DManager, llm::OS::Graphics::Printing3D::Print3DTaskRequestedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TaskRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TaskRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DManagerStatics> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DManagerStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Print3DManager>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowPrintUIAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ShowPrintUIAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTask> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTask>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3D3MFPackage>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Submitting(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().Submitting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Foundation::IInspectable> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Submitting(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Submitting(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_Completed(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskCompletedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Completed(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_SourceChanged(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().SourceChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Graphics::Printing3D::Print3DTask, llm::OS::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs>
    {
        int32_t __stdcall get_Completion(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Print3DTaskCompletion>(this->shim().Completion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Print3DTaskDetail>(this->shim().ExtendedStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTaskRequest> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTaskRequest>
    {
        int32_t __stdcall CreateTask(void* title, void* printerId, void* handler, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Print3DTask>(this->shim().CreateTask(*reinterpret_cast<hstring const*>(&title), *reinterpret_cast<hstring const*>(&printerId), *reinterpret_cast<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Print3DTaskRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3D3MFPackage>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs> : produce_base<D, llm::OS::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs>
    {
        int32_t __stdcall SetSource(void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3D3MFPackage const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage>
    {
        int32_t __stdcall SaveAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStream>>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrintTicket(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().PrintTicket());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PrintTicket(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintTicket(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ModelPart(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().ModelPart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ModelPart(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ModelPart(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DTextureResource>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Thumbnail(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DTextureResource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Textures(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTextureResource>>(this->shim().Textures());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadModelFromPackageAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DModel>>(this->shim().LoadModelFromPackageAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveModelToPackageAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveModelToPackageAsync(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DModel const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage2> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage2>
    {
        int32_t __stdcall get_Compression(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DPackageCompression>(this->shim().Compression());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Compression(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Compression(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DPackageCompression const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackageStatics> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3D3MFPackageStatics>
    {
        int32_t __stdcall LoadAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3D3MFPackage>>(this->shim().LoadAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Color(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DColorMaterial>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DColorMaterial const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroup>
    {
        int32_t __stdcall get_Bases(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterial>>(this->shim().Bases());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaterialGroupId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory>
    {
        int32_t __stdcall Create(uint32_t MaterialGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup>(this->shim().Create(MaterialGroupId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialStatics>
    {
        int32_t __stdcall get_Abs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Abs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Pla(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Pla());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial>
    {
        int32_t __stdcall get_Value(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial2> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial2>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroup> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroup>
    {
        int32_t __stdcall get_Colors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterial>>(this->shim().Colors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaterialGroupId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory>
    {
        int32_t __stdcall Create(uint32_t MaterialGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup>(this->shim().Create(MaterialGroupId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DComponent> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DComponent>
    {
        int32_t __stdcall get_Mesh(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DMesh>(this->shim().Mesh());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mesh(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mesh(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DMesh const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Components(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponentWithMatrix>>(this->shim().Components());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Thumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DTextureResource>(this->shim().Thumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Thumbnail(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DTextureResource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DObjectType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Type(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DObjectType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PartNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PartNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PartNumber(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PartNumber(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix>
    {
        int32_t __stdcall get_Component(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DComponent>(this->shim().Component());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Component(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Component(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DComponent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Matrix(llm::OS::Foundation::Numerics::float4x4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4x4>(this->shim().Matrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Matrix(llm::OS::Foundation::Numerics::float4x4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Matrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float4x4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterial>
    {
        int32_t __stdcall get_Values(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<double>>(this->shim().Values());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup>
    {
        int32_t __stdcall get_Composites(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterial>>(this->shim().Composites());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaterialGroupId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialIndices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<uint32_t>>(this->shim().MaterialIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2>
    {
        int32_t __stdcall get_BaseMaterialGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup>(this->shim().BaseMaterialGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BaseMaterialGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaseMaterialGroup(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory>
    {
        int32_t __stdcall Create(uint32_t MaterialGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup>(this->shim().Create(MaterialGroupId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions>
    {
        int32_t __stdcall get_MaxReductionArea(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MaxReductionArea());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxReductionArea(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxReductionArea(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetTriangleCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TargetTriangleCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TargetTriangleCount(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetTriangleCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxEdgeLength(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MaxEdgeLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxEdgeLength(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxEdgeLength(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMaterial>
    {
        int32_t __stdcall get_BaseGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup>>(this->shim().BaseGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup>>(this->shim().ColorGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Texture2CoordGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup>>(this->shim().Texture2CoordGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CompositeGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup>>(this->shim().CompositeGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MultiplePropertyGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup>>(this->shim().MultiplePropertyGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMesh> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMesh>
    {
        int32_t __stdcall get_VertexCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().VertexCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VertexCount(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IndexCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().IndexCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IndexCount(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndexCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexPositionsDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(this->shim().VertexPositionsDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VertexPositionsDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexPositionsDescription(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DBufferDescription const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VertexNormalsDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(this->shim().VertexNormalsDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VertexNormalsDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexNormalsDescription(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DBufferDescription const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriangleIndicesDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(this->shim().TriangleIndicesDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TriangleIndicesDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleIndicesDescription(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DBufferDescription const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriangleMaterialIndicesDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DBufferDescription>(this->shim().TriangleMaterialIndicesDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TriangleMaterialIndicesDescription(struct struct_Windows_Graphics_Printing3D_Printing3DBufferDescription value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleMaterialIndicesDescription(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DBufferDescription const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVertexPositions(void** buffer) noexcept final try
        {
            clear_abi(buffer);
            typename D::abi_guard guard(this->shim());
            *buffer = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetVertexPositions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVertexPositions(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateVertexPositions(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVertexNormals(void** buffer) noexcept final try
        {
            clear_abi(buffer);
            typename D::abi_guard guard(this->shim());
            *buffer = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetVertexNormals());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVertexNormals(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateVertexNormals(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTriangleIndices(void** buffer) noexcept final try
        {
            clear_abi(buffer);
            typename D::abi_guard guard(this->shim());
            *buffer = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetTriangleIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTriangleIndices(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateTriangleIndices(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTriangleMaterialIndices(void** buffer) noexcept final try
        {
            clear_abi(buffer);
            typename D::abi_guard guard(this->shim());
            *buffer = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetTriangleMaterialIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTriangleMaterialIndices(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateTriangleMaterialIndices(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferDescriptionSet(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().BufferDescriptionSet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferSet(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().BufferSet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall VerifyAsync(int32_t value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Printing3D::Printing3DMeshVerificationResult>>(this->shim().VerifyAsync(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DMeshVerificationMode const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult>
    {
        int32_t __stdcall get_IsValid(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsValid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NonmanifoldTriangles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().NonmanifoldTriangles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReversedNormalTriangles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().ReversedNormalTriangles());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DModel> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DModel>
    {
        int32_t __stdcall get_Unit(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DModelUnit>(this->shim().Unit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Unit(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unit(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DModelUnit const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Textures(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DModelTexture>>(this->shim().Textures());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Meshes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMesh>>(this->shim().Meshes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Components(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DComponent>>(this->shim().Components());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Material(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DMaterial>(this->shim().Material());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Material(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Material(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DMaterial const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Build(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DComponent>(this->shim().Build());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Build(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Build(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DComponent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Version(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Version());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Version(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Version(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequiredExtensions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().RequiredExtensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Metadata(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().Metadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RepairAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RepairAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DModel>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DModel2> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DModel2>
    {
        int32_t __stdcall TryPartialRepairAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryPartialRepairAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryPartialRepairWithTimeAsync(int64_t maxWaitTime, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryPartialRepairAsync(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&maxWaitTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReduceFacesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>>(this->shim().TryReduceFacesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReduceFacesWithOptionsAsync(void* printing3DFaceReductionOptions, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>>(this->shim().TryReduceFacesAsync(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DFaceReductionOptions const*>(&printing3DFaceReductionOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReduceFacesWithOptionsAndTimeAsync(void* printing3DFaceReductionOptions, int64_t maxWait, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>>(this->shim().TryReduceFacesAsync(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DFaceReductionOptions const*>(&printing3DFaceReductionOptions), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&maxWait)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RepairWithProgressAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<bool, double>>(this->shim().RepairWithProgressAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DModelTexture> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DModelTexture>
    {
        int32_t __stdcall get_TextureResource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DTextureResource>(this->shim().TextureResource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TextureResource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextureResource(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DTextureResource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TileStyleU(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior>(this->shim().TileStyleU());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TileStyleU(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileStyleU(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TileStyleV(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior>(this->shim().TileStyleV());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TileStyleV(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileStyleV(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DTextureEdgeBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial>
    {
        int32_t __stdcall get_MaterialIndices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<uint32_t>>(this->shim().MaterialIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup>
    {
        int32_t __stdcall get_MultipleProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterial>>(this->shim().MultipleProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupIndices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<uint32_t>>(this->shim().MaterialGroupIndices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaterialGroupId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory>
    {
        int32_t __stdcall Create(uint32_t MaterialGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup>(this->shim().Create(MaterialGroupId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>
    {
        int32_t __stdcall get_Texture(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DModelTexture>(this->shim().Texture());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Texture(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Texture(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DModelTexture const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_U(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().U());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_U(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().U(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_V(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().V());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_V(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().V(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup>
    {
        int32_t __stdcall get_Texture2Coords(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterial>>(this->shim().Texture2Coords());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaterialGroupId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaterialGroupId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2>
    {
        int32_t __stdcall get_Texture(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Printing3D::Printing3DModelTexture>(this->shim().Texture());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Texture(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Texture(*reinterpret_cast<llm::OS::Graphics::Printing3D::Printing3DModelTexture const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory>
    {
        int32_t __stdcall Create(uint32_t MaterialGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup>(this->shim().Create(MaterialGroupId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Graphics::Printing3D::IPrinting3DTextureResource> : produce_base<D, llm::OS::Graphics::Printing3D::IPrinting3DTextureResource>
    {
        int32_t __stdcall get_TextureData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>(this->shim().TextureData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TextureData(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextureData(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Graphics::Printing3D
{
    inline auto Print3DManager::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::Graphics::Printing3D::Print3DManager(*)(IPrint3DManagerStatics const&), Print3DManager, IPrint3DManagerStatics>([](IPrint3DManagerStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto Print3DManager::ShowPrintUIAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<bool>(*)(IPrint3DManagerStatics const&), Print3DManager, IPrint3DManagerStatics>([](IPrint3DManagerStatics const& f) { return f.ShowPrintUIAsync(); });
    }
    inline Printing3D3MFPackage::Printing3D3MFPackage() :
        Printing3D3MFPackage(impl::call_factory_cast<Printing3D3MFPackage(*)(llm::OS::Foundation::IActivationFactory const&), Printing3D3MFPackage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3D3MFPackage>(); }))
    {
    }
    inline auto Printing3D3MFPackage::LoadAsync(llm::OS::Storage::Streams::IRandomAccessStream const& value)
    {
        return impl::call_factory<Printing3D3MFPackage, IPrinting3D3MFPackageStatics>([&](IPrinting3D3MFPackageStatics const& f) { return f.LoadAsync(value); });
    }
    inline Printing3DBaseMaterial::Printing3DBaseMaterial() :
        Printing3DBaseMaterial(impl::call_factory_cast<Printing3DBaseMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DBaseMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DBaseMaterial>(); }))
    {
    }
    inline auto Printing3DBaseMaterial::Abs()
    {
        return impl::call_factory_cast<hstring(*)(IPrinting3DBaseMaterialStatics const&), Printing3DBaseMaterial, IPrinting3DBaseMaterialStatics>([](IPrinting3DBaseMaterialStatics const& f) { return f.Abs(); });
    }
    inline auto Printing3DBaseMaterial::Pla()
    {
        return impl::call_factory_cast<hstring(*)(IPrinting3DBaseMaterialStatics const&), Printing3DBaseMaterial, IPrinting3DBaseMaterialStatics>([](IPrinting3DBaseMaterialStatics const& f) { return f.Pla(); });
    }
    inline Printing3DBaseMaterialGroup::Printing3DBaseMaterialGroup(uint32_t MaterialGroupId) :
        Printing3DBaseMaterialGroup(impl::call_factory<Printing3DBaseMaterialGroup, IPrinting3DBaseMaterialGroupFactory>([&](IPrinting3DBaseMaterialGroupFactory const& f) { return f.Create(MaterialGroupId); }))
    {
    }
    inline Printing3DColorMaterial::Printing3DColorMaterial() :
        Printing3DColorMaterial(impl::call_factory_cast<Printing3DColorMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DColorMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DColorMaterial>(); }))
    {
    }
    inline Printing3DColorMaterialGroup::Printing3DColorMaterialGroup(uint32_t MaterialGroupId) :
        Printing3DColorMaterialGroup(impl::call_factory<Printing3DColorMaterialGroup, IPrinting3DColorMaterialGroupFactory>([&](IPrinting3DColorMaterialGroupFactory const& f) { return f.Create(MaterialGroupId); }))
    {
    }
    inline Printing3DComponent::Printing3DComponent() :
        Printing3DComponent(impl::call_factory_cast<Printing3DComponent(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DComponent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DComponent>(); }))
    {
    }
    inline Printing3DComponentWithMatrix::Printing3DComponentWithMatrix() :
        Printing3DComponentWithMatrix(impl::call_factory_cast<Printing3DComponentWithMatrix(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DComponentWithMatrix>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DComponentWithMatrix>(); }))
    {
    }
    inline Printing3DCompositeMaterial::Printing3DCompositeMaterial() :
        Printing3DCompositeMaterial(impl::call_factory_cast<Printing3DCompositeMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DCompositeMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DCompositeMaterial>(); }))
    {
    }
    inline Printing3DCompositeMaterialGroup::Printing3DCompositeMaterialGroup(uint32_t MaterialGroupId) :
        Printing3DCompositeMaterialGroup(impl::call_factory<Printing3DCompositeMaterialGroup, IPrinting3DCompositeMaterialGroupFactory>([&](IPrinting3DCompositeMaterialGroupFactory const& f) { return f.Create(MaterialGroupId); }))
    {
    }
    inline Printing3DFaceReductionOptions::Printing3DFaceReductionOptions() :
        Printing3DFaceReductionOptions(impl::call_factory_cast<Printing3DFaceReductionOptions(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DFaceReductionOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DFaceReductionOptions>(); }))
    {
    }
    inline Printing3DMaterial::Printing3DMaterial() :
        Printing3DMaterial(impl::call_factory_cast<Printing3DMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DMaterial>(); }))
    {
    }
    inline Printing3DMesh::Printing3DMesh() :
        Printing3DMesh(impl::call_factory_cast<Printing3DMesh(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DMesh>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DMesh>(); }))
    {
    }
    inline Printing3DModel::Printing3DModel() :
        Printing3DModel(impl::call_factory_cast<Printing3DModel(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DModel>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DModel>(); }))
    {
    }
    inline Printing3DModelTexture::Printing3DModelTexture() :
        Printing3DModelTexture(impl::call_factory_cast<Printing3DModelTexture(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DModelTexture>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DModelTexture>(); }))
    {
    }
    inline Printing3DMultiplePropertyMaterial::Printing3DMultiplePropertyMaterial() :
        Printing3DMultiplePropertyMaterial(impl::call_factory_cast<Printing3DMultiplePropertyMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DMultiplePropertyMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DMultiplePropertyMaterial>(); }))
    {
    }
    inline Printing3DMultiplePropertyMaterialGroup::Printing3DMultiplePropertyMaterialGroup(uint32_t MaterialGroupId) :
        Printing3DMultiplePropertyMaterialGroup(impl::call_factory<Printing3DMultiplePropertyMaterialGroup, IPrinting3DMultiplePropertyMaterialGroupFactory>([&](IPrinting3DMultiplePropertyMaterialGroupFactory const& f) { return f.Create(MaterialGroupId); }))
    {
    }
    inline Printing3DTexture2CoordMaterial::Printing3DTexture2CoordMaterial() :
        Printing3DTexture2CoordMaterial(impl::call_factory_cast<Printing3DTexture2CoordMaterial(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DTexture2CoordMaterial>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DTexture2CoordMaterial>(); }))
    {
    }
    inline Printing3DTexture2CoordMaterialGroup::Printing3DTexture2CoordMaterialGroup(uint32_t MaterialGroupId) :
        Printing3DTexture2CoordMaterialGroup(impl::call_factory<Printing3DTexture2CoordMaterialGroup, IPrinting3DTexture2CoordMaterialGroupFactory>([&](IPrinting3DTexture2CoordMaterialGroupFactory const& f) { return f.Create(MaterialGroupId); }))
    {
    }
    inline Printing3DTextureResource::Printing3DTextureResource() :
        Printing3DTextureResource(impl::call_factory_cast<Printing3DTextureResource(*)(llm::OS::Foundation::IActivationFactory const&), Printing3DTextureResource>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Printing3DTextureResource>(); }))
    {
    }
    template <typename L> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(L handler) :
        Print3DTaskSourceRequestedHandler(impl::make_delegate<Print3DTaskSourceRequestedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(F* handler) :
        Print3DTaskSourceRequestedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(O* object, M method) :
        Print3DTaskSourceRequestedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(com_ptr<O>&& object, M method) :
        Print3DTaskSourceRequestedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(weak_ref<O>&& object, M method) :
        Print3DTaskSourceRequestedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto Print3DTaskSourceRequestedHandler::operator()(llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedArgs const& args) const
    {
        check_hresult((*(impl::abi_t<Print3DTaskSourceRequestedHandler>**)this)->Invoke(*(void**)(&args)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTaskRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3D3MFPackage2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3D3MFPackageStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DColorMaterial2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DComponentWithMatrix> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DFaceReductionOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMeshVerificationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DModel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DModel2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DModelTexture> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::IPrinting3DTextureResource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTaskCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTaskRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTaskRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Print3DTaskSourceRequestedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3D3MFPackage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DBaseMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DBaseMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DColorMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DColorMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DComponent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DComponentWithMatrix> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DCompositeMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DFaceReductionOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DMesh> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DMeshVerificationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DModel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DModelTexture> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterial> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Printing3D::Printing3DTextureResource> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
