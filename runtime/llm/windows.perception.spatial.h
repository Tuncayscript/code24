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
#ifndef LLM_OS_Perception_Spatial_H
#define LLM_OS_Perception_Spatial_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Perception.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Perception.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.RemoteSystems.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialAnchor<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchor)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialAnchor<D>::RawCoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchor)->get_RawCoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialAnchor, llm::OS::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchor)->add_RawCoordinateSystemAdjusted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialAnchor<D>::RawCoordinateSystemAdjusted_revoker consume_Windows_Perception_Spatial_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialAnchor, llm::OS::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RawCoordinateSystemAdjusted_revoker>(this, RawCoordinateSystemAdjusted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchor)->remove_RawCoordinateSystemAdjusted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_ISpatialAnchor2<D>::RemovedByUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchor2)->get_RemovedByUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_ISpatialAnchorExportSufficiency<D>::IsMinimallySufficient() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency)->get_IsMinimallySufficient(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Perception_Spatial_ISpatialAnchorExportSufficiency<D>::SufficiencyLevel() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency)->get_SufficiencyLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Perception_Spatial_ISpatialAnchorExportSufficiency<D>::RecommendedSufficiencyLevel() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency)->get_RecommendedSufficiencyLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorExportSufficiency>) consume_Windows_Perception_Spatial_ISpatialAnchorExporter<D>::GetAnchorExportSufficiencyAsync(llm::OS::Perception::Spatial::SpatialAnchor const& anchor, llm::OS::Perception::Spatial::SpatialAnchorExportPurpose const& purpose) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExporter)->GetAnchorExportSufficiencyAsync(*(void**)(&anchor), static_cast<int32_t>(purpose), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorExportSufficiency>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Perception_Spatial_ISpatialAnchorExporter<D>::TryExportAnchorAsync(llm::OS::Perception::Spatial::SpatialAnchor const& anchor, llm::OS::Perception::Spatial::SpatialAnchorExportPurpose const& purpose, llm::OS::Storage::Streams::IOutputStream const& stream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExporter)->TryExportAnchorAsync(*(void**)(&anchor), static_cast<int32_t>(purpose), *(void**)(&stream), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialAnchorExporter) consume_Windows_Perception_Spatial_ISpatialAnchorExporterStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExporterStatics)->GetDefault(&value));
        return llm::OS::Perception::Spatial::SpatialAnchorExporter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>) consume_Windows_Perception_Spatial_ISpatialAnchorExporterStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorExporterStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorStore>) consume_Windows_Perception_Spatial_ISpatialAnchorManagerStatics<D>::RequestStoreAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorManagerStatics)->RequestStoreAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorStore>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) consume_Windows_Perception_Spatial_ISpatialAnchorRawCoordinateSystemAdjustedEventArgs<D>::OldRawCoordinateSystemToNewRawCoordinateSystemTransform() const
    {
        llm::OS::Foundation::Numerics::float4x4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs)->get_OldRawCoordinateSystemToNewRawCoordinateSystemTransform(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialAnchor) consume_Windows_Perception_Spatial_ISpatialAnchorStatics<D>::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStatics)->TryCreateRelativeTo(*(void**)(&coordinateSystem), &value));
        return llm::OS::Perception::Spatial::SpatialAnchor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialAnchor) consume_Windows_Perception_Spatial_ISpatialAnchorStatics<D>::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStatics)->TryCreateWithPositionRelativeTo(*(void**)(&coordinateSystem), impl::bind_in(position), &value));
        return llm::OS::Perception::Spatial::SpatialAnchor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialAnchor) consume_Windows_Perception_Spatial_ISpatialAnchorStatics<D>::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::quaternion const& orientation) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStatics)->TryCreateWithPositionAndOrientationRelativeTo(*(void**)(&coordinateSystem), impl::bind_in(position), impl::bind_in(orientation), &value));
        return llm::OS::Perception::Spatial::SpatialAnchor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>) consume_Windows_Perception_Spatial_ISpatialAnchorStore<D>::GetAllSavedAnchors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStore)->GetAllSavedAnchors(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_ISpatialAnchorStore<D>::TrySave(param::hstring const& id, llm::OS::Perception::Spatial::SpatialAnchor const& anchor) const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStore)->TrySave(*(void**)(&id), *(void**)(&anchor), &succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialAnchorStore<D>::Remove(param::hstring const& id) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStore)->Remove(*(void**)(&id)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialAnchorStore<D>::Clear() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorStore)->Clear());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>>) consume_Windows_Perception_Spatial_ISpatialAnchorTransferManagerStatics<D>::TryImportAnchorsAsync(llm::OS::Storage::Streams::IInputStream const& stream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics)->TryImportAnchorsAsync(*(void**)(&stream), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Perception_Spatial_ISpatialAnchorTransferManagerStatics<D>::TryExportAnchorsAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Perception::Spatial::SpatialAnchor>> const& anchors, llm::OS::Storage::Streams::IOutputStream const& stream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics)->TryExportAnchorsAsync(*(void**)(&anchors), *(void**)(&stream), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>) consume_Windows_Perception_Spatial_ISpatialAnchorTransferManagerStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialBoundingVolume) consume_Windows_Perception_Spatial_ISpatialBoundingVolumeStatics<D>::FromBox(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingBox const& box) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics)->FromBox(*(void**)(&coordinateSystem), impl::bind_in(box), &value));
        return llm::OS::Perception::Spatial::SpatialBoundingVolume{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialBoundingVolume) consume_Windows_Perception_Spatial_ISpatialBoundingVolumeStatics<D>::FromOrientedBox(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingOrientedBox const& box) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics)->FromOrientedBox(*(void**)(&coordinateSystem), impl::bind_in(box), &value));
        return llm::OS::Perception::Spatial::SpatialBoundingVolume{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialBoundingVolume) consume_Windows_Perception_Spatial_ISpatialBoundingVolumeStatics<D>::FromSphere(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingSphere const& sphere) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics)->FromSphere(*(void**)(&coordinateSystem), impl::bind_in(sphere), &value));
        return llm::OS::Perception::Spatial::SpatialBoundingVolume{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialBoundingVolume) consume_Windows_Perception_Spatial_ISpatialBoundingVolumeStatics<D>::FromFrustum(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingFrustum const& frustum) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics)->FromFrustum(*(void**)(&coordinateSystem), impl::bind_in(frustum), &value));
        return llm::OS::Perception::Spatial::SpatialBoundingVolume{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float4x4>) consume_Windows_Perception_Spatial_ISpatialCoordinateSystem<D>::TryGetTransformTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& target) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialCoordinateSystem)->TryGetTransformTo(*(void**)(&target), &value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float4x4>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Perception_Spatial_ISpatialEntity<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntity)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialAnchor) consume_Windows_Perception_Spatial_ISpatialEntity<D>::Anchor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntity)->get_Anchor(&value));
        return llm::OS::Perception::Spatial::SpatialAnchor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Perception_Spatial_ISpatialEntity<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntity)->get_Properties(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntity) consume_Windows_Perception_Spatial_ISpatialEntityAddedEventArgs<D>::Entity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityAddedEventArgs)->get_Entity(&value));
        return llm::OS::Perception::Spatial::SpatialEntity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntity) consume_Windows_Perception_Spatial_ISpatialEntityFactory<D>::CreateWithSpatialAnchor(llm::OS::Perception::Spatial::SpatialAnchor const& spatialAnchor) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityFactory)->CreateWithSpatialAnchor(*(void**)(&spatialAnchor), &value));
        return llm::OS::Perception::Spatial::SpatialEntity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntity) consume_Windows_Perception_Spatial_ISpatialEntityFactory<D>::CreateWithSpatialAnchorAndProperties(llm::OS::Perception::Spatial::SpatialAnchor const& spatialAnchor, llm::OS::Foundation::Collections::ValueSet const& propertySet) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityFactory)->CreateWithSpatialAnchorAndProperties(*(void**)(&spatialAnchor), *(void**)(&propertySet), &value));
        return llm::OS::Perception::Spatial::SpatialEntity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntity) consume_Windows_Perception_Spatial_ISpatialEntityRemovedEventArgs<D>::Entity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityRemovedEventArgs)->get_Entity(&value));
        return llm::OS::Perception::Spatial::SpatialEntity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Perception_Spatial_ISpatialEntityStore<D>::SaveAsync(llm::OS::Perception::Spatial::SpatialEntity const& entity) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityStore)->SaveAsync(*(void**)(&entity), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Perception_Spatial_ISpatialEntityStore<D>::RemoveAsync(llm::OS::Perception::Spatial::SpatialEntity const& entity) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityStore)->RemoveAsync(*(void**)(&entity), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntityWatcher) consume_Windows_Perception_Spatial_ISpatialEntityStore<D>::CreateEntityWatcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityStore)->CreateEntityWatcher(&value));
        return llm::OS::Perception::Spatial::SpatialEntityWatcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_ISpatialEntityStoreStatics<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityStoreStatics)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntityStore) consume_Windows_Perception_Spatial_ISpatialEntityStoreStatics<D>::TryGet(llm::OS::System::RemoteSystems::RemoteSystemSession const& session) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityStoreStatics)->TryGetForRemoteSystemSession(*(void**)(&session), &value));
        return llm::OS::Perception::Spatial::SpatialEntityStore{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntity) consume_Windows_Perception_Spatial_ISpatialEntityUpdatedEventArgs<D>::Entity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs)->get_Entity(&value));
        return llm::OS::Perception::Spatial::SpatialEntity{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialEntityWatcherStatus) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Status() const
    {
        llm::OS::Perception::Spatial::SpatialEntityWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Added_revoker consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityUpdatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Updated_revoker consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Removed_revoker consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::EnumerationCompleted_revoker consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialEntityWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialEntityWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocation<D>::Position() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Perception_Spatial_ISpatialLocation<D>::Orientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_Orientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocation<D>::AbsoluteLinearVelocity() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_AbsoluteLinearVelocity(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocation<D>::AbsoluteLinearAcceleration() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_AbsoluteLinearAcceleration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Perception_Spatial_ISpatialLocation<D>::AbsoluteAngularVelocity() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_AbsoluteAngularVelocity(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Perception_Spatial_ISpatialLocation<D>::AbsoluteAngularAcceleration() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation)->get_AbsoluteAngularAcceleration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocation2<D>::AbsoluteAngularVelocityAxisAngle() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation2)->get_AbsoluteAngularVelocityAxisAngle(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocation2<D>::AbsoluteAngularAccelerationAxisAngle() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocation2)->get_AbsoluteAngularAccelerationAxisAngle(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocatability) consume_Windows_Perception_Spatial_ISpatialLocator<D>::Locatability() const
    {
        llm::OS::Perception::Spatial::SpatialLocatability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->get_Locatability(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialLocator<D>::LocatabilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->add_LocatabilityChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialLocator<D>::LocatabilityChanged_revoker consume_Windows_Perception_Spatial_ISpatialLocator<D>::LocatabilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, LocatabilityChanged_revoker>(this, LocatabilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocator<D>::LocatabilityChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->remove_LocatabilityChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialLocator<D>::PositionalTrackingDeactivating(llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->add_PositionalTrackingDeactivating(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialLocator<D>::PositionalTrackingDeactivating_revoker consume_Windows_Perception_Spatial_ISpatialLocator<D>::PositionalTrackingDeactivating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PositionalTrackingDeactivating_revoker>(this, PositionalTrackingDeactivating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocator<D>::PositionalTrackingDeactivating(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->remove_PositionalTrackingDeactivating(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocation) consume_Windows_Perception_Spatial_ISpatialLocator<D>::TryLocateAtTimestamp(llm::OS::Perception::PerceptionTimestamp const& timestamp, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->TryLocateAtTimestamp(*(void**)(&timestamp), *(void**)(&coordinateSystem), &value));
        return llm::OS::Perception::Spatial::SpatialLocation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateAttachedFrameOfReferenceAtCurrentHeading(&value));
        return llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(llm::OS::Foundation::Numerics::float3 const& relativePosition) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPosition(impl::bind_in(relativePosition), &value));
        return llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation(impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), &value));
        return llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation, double relativeHeadingInRadians) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading(impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), relativeHeadingInRadians, &value));
        return llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateStationaryFrameOfReferenceAtCurrentLocation(&value));
        return llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(llm::OS::Foundation::Numerics::float3 const& relativePosition) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateStationaryFrameOfReferenceAtCurrentLocationWithPosition(impl::bind_in(relativePosition), &value));
        return llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation(impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), &value));
        return llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference) consume_Windows_Perception_Spatial_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(llm::OS::Foundation::Numerics::float3 const& relativePosition, llm::OS::Foundation::Numerics::quaternion const& relativeOrientation, double relativeHeadingInRadians) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocator)->CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading(impl::bind_in(relativePosition), impl::bind_in(relativeOrientation), relativeHeadingInRadians, &value));
        return llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::RelativePosition() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->get_RelativePosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::RelativePosition(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->put_RelativePosition(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::RelativeOrientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->get_RelativeOrientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::RelativeOrientation(llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->put_RelativeOrientation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::AdjustHeading(double headingOffsetInRadians) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->AdjustHeading(headingOffsetInRadians));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::GetStationaryCoordinateSystemAtTimestamp(llm::OS::Perception::PerceptionTimestamp const& timestamp) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->GetStationaryCoordinateSystemAtTimestamp(*(void**)(&timestamp), &value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Perception_Spatial_ISpatialLocatorAttachedFrameOfReference<D>::TryGetRelativeHeadingAtTimestamp(llm::OS::Perception::PerceptionTimestamp const& timestamp) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference)->TryGetRelativeHeadingAtTimestamp(*(void**)(&timestamp), &value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Perception_Spatial_ISpatialLocatorPositionalTrackingDeactivatingEventArgs<D>::Canceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs)->get_Canceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialLocatorPositionalTrackingDeactivatingEventArgs<D>::Canceled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs)->put_Canceled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLocator) consume_Windows_Perception_Spatial_ISpatialLocatorStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialLocatorStatics)->GetDefault(&value));
        return llm::OS::Perception::Spatial::SpatialLocator{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReference<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReference)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialMovementRange) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReference<D>::MovementRange() const
    {
        llm::OS::Perception::Spatial::SpatialMovementRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReference)->get_MovementRange(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialLookDirectionRange) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReference<D>::LookDirectionRange() const
    {
        llm::OS::Perception::Spatial::SpatialLookDirectionRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReference)->get_LookDirectionRange(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReference<D>::GetCoordinateSystemAtCurrentLocation(llm::OS::Perception::Spatial::SpatialLocator const& locator) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReference)->GetCoordinateSystemAtCurrentLocation(*(void**)(&locator), &result));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<llm::OS::Foundation::Numerics::float3>) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReference<D>::TryGetMovementBounds(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        uint32_t value_impl_size{};
        llm::OS::Foundation::Numerics::float3* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReference)->TryGetMovementBounds(*(void**)(&coordinateSystem), &value_impl_size, &value));
        return com_array<llm::OS::Foundation::Numerics::float3>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialStageFrameOfReference) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics)->get_Current(&value));
        return llm::OS::Perception::Spatial::SpatialStageFrameOfReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::CurrentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics)->add_CurrentChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::CurrentChanged_revoker consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::CurrentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CurrentChanged_revoker>(this, CurrentChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::CurrentChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics)->remove_CurrentChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialStageFrameOfReference>) consume_Windows_Perception_Spatial_ISpatialStageFrameOfReferenceStatics<D>::RequestNewStageAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics)->RequestNewStageAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialStageFrameOfReference>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Perception_Spatial_ISpatialStationaryFrameOfReference<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Spatial::ISpatialStationaryFrameOfReference)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchor> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchor>
    {
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawCoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().RawCoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RawCoordinateSystemAdjusted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().RawCoordinateSystemAdjusted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialAnchor, llm::OS::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RawCoordinateSystemAdjusted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawCoordinateSystemAdjusted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchor2> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchor2>
    {
        int32_t __stdcall get_RemovedByUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RemovedByUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency>
    {
        int32_t __stdcall get_IsMinimallySufficient(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMinimallySufficient());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SufficiencyLevel(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().SufficiencyLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecommendedSufficiencyLevel(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().RecommendedSufficiencyLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorExporter> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorExporter>
    {
        int32_t __stdcall GetAnchorExportSufficiencyAsync(void* anchor, int32_t purpose, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorExportSufficiency>>(this->shim().GetAnchorExportSufficiencyAsync(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchor const*>(&anchor), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchorExportPurpose const*>(&purpose)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryExportAnchorAsync(void* anchor, int32_t purpose, void* stream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryExportAnchorAsync(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchor const*>(&anchor), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchorExportPurpose const*>(&purpose), *reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorExporterStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorExporterStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialAnchorExporter>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorManagerStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorManagerStatics>
    {
        int32_t __stdcall RequestStoreAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorStore>>(this->shim().RequestStoreAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs>
    {
        int32_t __stdcall get_OldRawCoordinateSystemToNewRawCoordinateSystemTransform(llm::OS::Foundation::Numerics::float4x4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4x4>(this->shim().OldRawCoordinateSystemToNewRawCoordinateSystemTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorStatics>
    {
        int32_t __stdcall TryCreateRelativeTo(void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialAnchor>(this->shim().TryCreateRelativeTo(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateWithPositionRelativeTo(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialAnchor>(this->shim().TryCreateRelativeTo(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateWithPositionAndOrientationRelativeTo(void* coordinateSystem, llm::OS::Foundation::Numerics::float3 position, llm::OS::Foundation::Numerics::quaternion orientation, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialAnchor>(this->shim().TryCreateRelativeTo(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&position), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&orientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorStore> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorStore>
    {
        int32_t __stdcall GetAllSavedAnchors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>>(this->shim().GetAllSavedAnchors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySave(void* id, void* anchor, bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().TrySave(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchor const*>(&anchor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* id) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<hstring const*>(&id));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clear() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics>
    {
        int32_t __stdcall TryImportAnchorsAsync(void* stream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Perception::Spatial::SpatialAnchor>>>(this->shim().TryImportAnchorsAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryExportAnchorsAsync(void* anchors, void* stream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryExportAnchorsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Perception::Spatial::SpatialAnchor>> const*>(&anchors), *reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::Perception::Spatial::ISpatialBoundingVolume> : produce_base<D, llm::OS::Perception::Spatial::ISpatialBoundingVolume>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics>
    {
        int32_t __stdcall FromBox(void* coordinateSystem, struct struct_Windows_Perception_Spatial_SpatialBoundingBox box, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialBoundingVolume>(this->shim().FromBox(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialBoundingBox const*>(&box)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromOrientedBox(void* coordinateSystem, struct struct_Windows_Perception_Spatial_SpatialBoundingOrientedBox box, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialBoundingVolume>(this->shim().FromOrientedBox(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialBoundingOrientedBox const*>(&box)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromSphere(void* coordinateSystem, struct struct_Windows_Perception_Spatial_SpatialBoundingSphere sphere, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialBoundingVolume>(this->shim().FromSphere(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialBoundingSphere const*>(&sphere)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromFrustum(void* coordinateSystem, struct struct_Windows_Perception_Spatial_SpatialBoundingFrustum frustum, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialBoundingVolume>(this->shim().FromFrustum(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialBoundingFrustum const*>(&frustum)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialCoordinateSystem> : produce_base<D, llm::OS::Perception::Spatial::ISpatialCoordinateSystem>
    {
        int32_t __stdcall TryGetTransformTo(void* target, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float4x4>>(this->shim().TryGetTransformTo(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntity> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntity>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Anchor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialAnchor>(this->shim().Anchor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityAddedEventArgs> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityAddedEventArgs>
    {
        int32_t __stdcall get_Entity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntity>(this->shim().Entity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityFactory> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityFactory>
    {
        int32_t __stdcall CreateWithSpatialAnchor(void* spatialAnchor, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntity>(this->shim().CreateWithSpatialAnchor(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchor const*>(&spatialAnchor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithSpatialAnchorAndProperties(void* spatialAnchor, void* propertySet, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntity>(this->shim().CreateWithSpatialAnchorAndProperties(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialAnchor const*>(&spatialAnchor), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&propertySet)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityRemovedEventArgs> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityRemovedEventArgs>
    {
        int32_t __stdcall get_Entity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntity>(this->shim().Entity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityStore> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityStore>
    {
        int32_t __stdcall SaveAsync(void* entity, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialEntity const*>(&entity)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAsync(void* entity, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RemoveAsync(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialEntity const*>(&entity)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEntityWatcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntityWatcher>(this->shim().CreateEntityWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityStoreStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityStoreStatics>
    {
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetForRemoteSystemSession(void* session, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntityStore>(this->shim().TryGet(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSession const*>(&session)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs>
    {
        int32_t __stdcall get_Entity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntity>(this->shim().Entity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialEntityWatcher> : produce_base<D, llm::OS::Perception::Spatial::ISpatialEntityWatcher>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialEntityWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Perception::Spatial::SpatialEntityRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialEntityWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocation> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocation>
    {
        int32_t __stdcall get_Position(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Orientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AbsoluteLinearVelocity(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().AbsoluteLinearVelocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AbsoluteLinearAcceleration(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().AbsoluteLinearAcceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AbsoluteAngularVelocity(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().AbsoluteAngularVelocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AbsoluteAngularAcceleration(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().AbsoluteAngularAcceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocation2> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocation2>
    {
        int32_t __stdcall get_AbsoluteAngularVelocityAxisAngle(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().AbsoluteAngularVelocityAxisAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AbsoluteAngularAccelerationAxisAngle(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().AbsoluteAngularAccelerationAxisAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocator> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocator>
    {
        int32_t __stdcall get_Locatability(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocatability>(this->shim().Locatability());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_LocatabilityChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().LocatabilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LocatabilityChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocatabilityChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PositionalTrackingDeactivating(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PositionalTrackingDeactivating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Perception::Spatial::SpatialLocator, llm::OS::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PositionalTrackingDeactivating(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionalTrackingDeactivating(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall TryLocateAtTimestamp(void* timestamp, void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocation>(this->shim().TryLocateAtTimestamp(*reinterpret_cast<llm::OS::Perception::PerceptionTimestamp const*>(&timestamp), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAttachedFrameOfReferenceAtCurrentHeading(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference>(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAttachedFrameOfReferenceAtCurrentHeadingWithPosition(llm::OS::Foundation::Numerics::float3 relativePosition, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference>(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation(llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference>(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading(llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, double relativeHeadingInRadians, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference>(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation), relativeHeadingInRadians));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStationaryFrameOfReferenceAtCurrentLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference>(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStationaryFrameOfReferenceAtCurrentLocationWithPosition(llm::OS::Foundation::Numerics::float3 relativePosition, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference>(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation(llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference>(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading(llm::OS::Foundation::Numerics::float3 relativePosition, llm::OS::Foundation::Numerics::quaternion relativeOrientation, double relativeHeadingInRadians, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference>(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&relativePosition), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&relativeOrientation), relativeHeadingInRadians));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>
    {
        int32_t __stdcall get_RelativePosition(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().RelativePosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RelativePosition(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativePosition(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RelativeOrientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().RelativeOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RelativeOrientation(llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeOrientation(*reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AdjustHeading(double headingOffsetInRadians) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdjustHeading(headingOffsetInRadians);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStationaryCoordinateSystemAtTimestamp(void* timestamp, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().GetStationaryCoordinateSystemAtTimestamp(*reinterpret_cast<llm::OS::Perception::PerceptionTimestamp const*>(&timestamp)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetRelativeHeadingAtTimestamp(void* timestamp, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().TryGetRelativeHeadingAtTimestamp(*reinterpret_cast<llm::OS::Perception::PerceptionTimestamp const*>(&timestamp)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs>
    {
        int32_t __stdcall get_Canceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Canceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Canceled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Canceled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialLocatorStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialLocatorStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLocator>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialStageFrameOfReference> : produce_base<D, llm::OS::Perception::Spatial::ISpatialStageFrameOfReference>
    {
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MovementRange(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialMovementRange>(this->shim().MovementRange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LookDirectionRange(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialLookDirectionRange>(this->shim().LookDirectionRange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCoordinateSystemAtCurrentLocation(void* locator, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().GetCoordinateSystemAtCurrentLocation(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialLocator const*>(&locator)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetMovementBounds(void* coordinateSystem, uint32_t* __valueSize, llm::OS::Foundation::Numerics::float3** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().TryGetMovementBounds(*reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics> : produce_base<D, llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialStageFrameOfReference>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CurrentChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CurrentChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CurrentChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall RequestNewStageAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialStageFrameOfReference>>(this->shim().RequestNewStageAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Spatial::ISpatialStationaryFrameOfReference> : produce_base<D, llm::OS::Perception::Spatial::ISpatialStationaryFrameOfReference>
    {
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception::Spatial
{
    inline auto SpatialAnchor::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem)
    {
        return impl::call_factory<SpatialAnchor, ISpatialAnchorStatics>([&](ISpatialAnchorStatics const& f) { return f.TryCreateRelativeTo(coordinateSystem); });
    }
    inline auto SpatialAnchor::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position)
    {
        return impl::call_factory<SpatialAnchor, ISpatialAnchorStatics>([&](ISpatialAnchorStatics const& f) { return f.TryCreateRelativeTo(coordinateSystem, position); });
    }
    inline auto SpatialAnchor::TryCreateRelativeTo(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::quaternion const& orientation)
    {
        return impl::call_factory<SpatialAnchor, ISpatialAnchorStatics>([&](ISpatialAnchorStatics const& f) { return f.TryCreateRelativeTo(coordinateSystem, position, orientation); });
    }
    inline auto SpatialAnchorExporter::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Perception::Spatial::SpatialAnchorExporter(*)(ISpatialAnchorExporterStatics const&), SpatialAnchorExporter, ISpatialAnchorExporterStatics>([](ISpatialAnchorExporterStatics const& f) { return f.GetDefault(); });
    }
    inline auto SpatialAnchorExporter::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>(*)(ISpatialAnchorExporterStatics const&), SpatialAnchorExporter, ISpatialAnchorExporterStatics>([](ISpatialAnchorExporterStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto SpatialAnchorManager::RequestStoreAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialAnchorStore>(*)(ISpatialAnchorManagerStatics const&), SpatialAnchorManager, ISpatialAnchorManagerStatics>([](ISpatialAnchorManagerStatics const& f) { return f.RequestStoreAsync(); });
    }
    inline auto SpatialAnchorTransferManager::TryImportAnchorsAsync(llm::OS::Storage::Streams::IInputStream const& stream)
    {
        return impl::call_factory<SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>([&](ISpatialAnchorTransferManagerStatics const& f) { return f.TryImportAnchorsAsync(stream); });
    }
    inline auto SpatialAnchorTransferManager::TryExportAnchorsAsync(param::async_iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::Perception::Spatial::SpatialAnchor>> const& anchors, llm::OS::Storage::Streams::IOutputStream const& stream)
    {
        return impl::call_factory<SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>([&](ISpatialAnchorTransferManagerStatics const& f) { return f.TryExportAnchorsAsync(anchors, stream); });
    }
    inline auto SpatialAnchorTransferManager::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialPerceptionAccessStatus>(*)(ISpatialAnchorTransferManagerStatics const&), SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>([](ISpatialAnchorTransferManagerStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto SpatialBoundingVolume::FromBox(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingBox const& box)
    {
        return impl::call_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>([&](ISpatialBoundingVolumeStatics const& f) { return f.FromBox(coordinateSystem, box); });
    }
    inline auto SpatialBoundingVolume::FromOrientedBox(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingOrientedBox const& box)
    {
        return impl::call_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>([&](ISpatialBoundingVolumeStatics const& f) { return f.FromOrientedBox(coordinateSystem, box); });
    }
    inline auto SpatialBoundingVolume::FromSphere(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingSphere const& sphere)
    {
        return impl::call_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>([&](ISpatialBoundingVolumeStatics const& f) { return f.FromSphere(coordinateSystem, sphere); });
    }
    inline auto SpatialBoundingVolume::FromFrustum(llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm::OS::Perception::Spatial::SpatialBoundingFrustum const& frustum)
    {
        return impl::call_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>([&](ISpatialBoundingVolumeStatics const& f) { return f.FromFrustum(coordinateSystem, frustum); });
    }
    inline SpatialEntity::SpatialEntity(llm::OS::Perception::Spatial::SpatialAnchor const& spatialAnchor) :
        SpatialEntity(impl::call_factory<SpatialEntity, ISpatialEntityFactory>([&](ISpatialEntityFactory const& f) { return f.CreateWithSpatialAnchor(spatialAnchor); }))
    {
    }
    inline SpatialEntity::SpatialEntity(llm::OS::Perception::Spatial::SpatialAnchor const& spatialAnchor, llm::OS::Foundation::Collections::ValueSet const& propertySet) :
        SpatialEntity(impl::call_factory<SpatialEntity, ISpatialEntityFactory>([&](ISpatialEntityFactory const& f) { return f.CreateWithSpatialAnchorAndProperties(spatialAnchor, propertySet); }))
    {
    }
    inline auto SpatialEntityStore::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(ISpatialEntityStoreStatics const&), SpatialEntityStore, ISpatialEntityStoreStatics>([](ISpatialEntityStoreStatics const& f) { return f.IsSupported(); });
    }
    inline auto SpatialEntityStore::TryGet(llm::OS::System::RemoteSystems::RemoteSystemSession const& session)
    {
        return impl::call_factory<SpatialEntityStore, ISpatialEntityStoreStatics>([&](ISpatialEntityStoreStatics const& f) { return f.TryGet(session); });
    }
    inline auto SpatialLocator::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Perception::Spatial::SpatialLocator(*)(ISpatialLocatorStatics const&), SpatialLocator, ISpatialLocatorStatics>([](ISpatialLocatorStatics const& f) { return f.GetDefault(); });
    }
    inline auto SpatialStageFrameOfReference::Current()
    {
        return impl::call_factory_cast<llm::OS::Perception::Spatial::SpatialStageFrameOfReference(*)(ISpatialStageFrameOfReferenceStatics const&), SpatialStageFrameOfReference, ISpatialStageFrameOfReferenceStatics>([](ISpatialStageFrameOfReferenceStatics const& f) { return f.Current(); });
    }
    inline auto SpatialStageFrameOfReference::CurrentChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<SpatialStageFrameOfReference, ISpatialStageFrameOfReferenceStatics>([&](ISpatialStageFrameOfReferenceStatics const& f) { return f.CurrentChanged(handler); });
    }
    inline SpatialStageFrameOfReference::CurrentChanged_revoker SpatialStageFrameOfReference::CurrentChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<SpatialStageFrameOfReference, llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics>();
        return { f, f.CurrentChanged(handler) };
    }
    inline auto SpatialStageFrameOfReference::CurrentChanged(llm::event_token const& cookie)
    {
        impl::call_factory<SpatialStageFrameOfReference, ISpatialStageFrameOfReferenceStatics>([&](ISpatialStageFrameOfReferenceStatics const& f) { return f.CurrentChanged(cookie); });
    }
    inline auto SpatialStageFrameOfReference::RequestNewStageAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Perception::Spatial::SpatialStageFrameOfReference>(*)(ISpatialStageFrameOfReferenceStatics const&), SpatialStageFrameOfReference, ISpatialStageFrameOfReferenceStatics>([](ISpatialStageFrameOfReferenceStatics const& f) { return f.RequestNewStageAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchor2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorExportSufficiency> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorExporter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorExporterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialAnchorTransferManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialBoundingVolume> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialBoundingVolumeStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialCoordinateSystem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntity> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityStoreStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialEntityWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialLocatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialStageFrameOfReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::ISpatialStationaryFrameOfReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorExportSufficiency> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorExporter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialAnchorTransferManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialBoundingVolume> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialCoordinateSystem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntity> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntityAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntityRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntityStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntityUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialEntityWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialLocator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialLocatorAttachedFrameOfReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialStageFrameOfReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Spatial::SpatialStationaryFrameOfReference> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
