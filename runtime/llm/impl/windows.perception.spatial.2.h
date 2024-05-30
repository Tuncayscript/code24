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
#ifndef LLM_OS_Perception_Spatial_2_H
#define LLM_OS_Perception_Spatial_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.RemoteSystems.2.h"
#include "llm/impl/Windows.Perception.Spatial.1.h"
LLM_EXPORT namespace llm:OS::Perception::Spatial
{
    struct SpatialBoundingBox
    {
        llm:OS::Foundation::Numerics::float3 Center;
        llm:OS::Foundation::Numerics::float3 Extents;
    };
    inline bool operator==(SpatialBoundingBox const& left, SpatialBoundingBox const& right) noexcept
    {
        return left.Center == right.Center && left.Extents == right.Extents;
    }
    inline bool operator!=(SpatialBoundingBox const& left, SpatialBoundingBox const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingFrustum
    {
        llm:OS::Foundation::Numerics::plane Near;
        llm:OS::Foundation::Numerics::plane Far;
        llm:OS::Foundation::Numerics::plane Right;
        llm:OS::Foundation::Numerics::plane Left;
        llm:OS::Foundation::Numerics::plane Top;
        llm:OS::Foundation::Numerics::plane Bottom;
    };
    inline bool operator==(SpatialBoundingFrustum const& left, SpatialBoundingFrustum const& right) noexcept
    {
        return left.Near == right.Near && left.Far == right.Far && left.Right == right.Right && left.Left == right.Left && left.Top == right.Top && left.Bottom == right.Bottom;
    }
    inline bool operator!=(SpatialBoundingFrustum const& left, SpatialBoundingFrustum const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingOrientedBox
    {
        llm:OS::Foundation::Numerics::float3 Center;
        llm:OS::Foundation::Numerics::float3 Extents;
        llm:OS::Foundation::Numerics::quaternion Orientation;
    };
    inline bool operator==(SpatialBoundingOrientedBox const& left, SpatialBoundingOrientedBox const& right) noexcept
    {
        return left.Center == right.Center && left.Extents == right.Extents && left.Orientation == right.Orientation;
    }
    inline bool operator!=(SpatialBoundingOrientedBox const& left, SpatialBoundingOrientedBox const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingSphere
    {
        llm:OS::Foundation::Numerics::float3 Center;
        float Radius;
    };
    inline bool operator==(SpatialBoundingSphere const& left, SpatialBoundingSphere const& right) noexcept
    {
        return left.Center == right.Center && left.Radius == right.Radius;
    }
    inline bool operator!=(SpatialBoundingSphere const& left, SpatialBoundingSphere const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialRay
    {
        llm:OS::Foundation::Numerics::float3 Origin;
        llm:OS::Foundation::Numerics::float3 Direction;
    };
    inline bool operator==(SpatialRay const& left, SpatialRay const& right) noexcept
    {
        return left.Origin == right.Origin && left.Direction == right.Direction;
    }
    inline bool operator!=(SpatialRay const& left, SpatialRay const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) SpatialAnchor : llm:OS::Perception::Spatial::ISpatialAnchor,
        impl::require<SpatialAnchor, llm:OS::Perception::Spatial::ISpatialAnchor2>
    {
        SpatialAnchor(std::nullptr_t) noexcept {}
        SpatialAnchor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialAnchor(ptr, take_ownership_from_abi) {}
        static auto TryCreateRelativeTo(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem);
        static auto TryCreateRelativeTo(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& position);
        static auto TryCreateRelativeTo(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Foundation::Numerics::float3 const& position, llm:OS::Foundation::Numerics::quaternion const& orientation);
    };
    struct __declspec(empty_bases) SpatialAnchorExportSufficiency : llm:OS::Perception::Spatial::ISpatialAnchorExportSufficiency
    {
        SpatialAnchorExportSufficiency(std::nullptr_t) noexcept {}
        SpatialAnchorExportSufficiency(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialAnchorExportSufficiency(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialAnchorExporter : llm:OS::Perception::Spatial::ISpatialAnchorExporter
    {
        SpatialAnchorExporter(std::nullptr_t) noexcept {}
        SpatialAnchorExporter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialAnchorExporter(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto RequestAccessAsync();
    };
    struct SpatialAnchorManager
    {
        SpatialAnchorManager() = delete;
        static auto RequestStoreAsync();
    };
    struct __declspec(empty_bases) SpatialAnchorRawCoordinateSystemAdjustedEventArgs : llm:OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs
    {
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(std::nullptr_t) noexcept {}
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialAnchorStore : llm:OS::Perception::Spatial::ISpatialAnchorStore
    {
        SpatialAnchorStore(std::nullptr_t) noexcept {}
        SpatialAnchorStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialAnchorStore(ptr, take_ownership_from_abi) {}
    };
    struct SpatialAnchorTransferManager
    {
        SpatialAnchorTransferManager() = delete;
        static auto TryImportAnchorsAsync(llm:OS::Storage::Streams::IInputStream const& stream);
        static auto TryExportAnchorsAsync(param::async_iterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, llm:OS::Perception::Spatial::SpatialAnchor>> const& anchors, llm:OS::Storage::Streams::IOutputStream const& stream);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) SpatialBoundingVolume : llm:OS::Perception::Spatial::ISpatialBoundingVolume
    {
        SpatialBoundingVolume(std::nullptr_t) noexcept {}
        SpatialBoundingVolume(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialBoundingVolume(ptr, take_ownership_from_abi) {}
        static auto FromBox(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::Spatial::SpatialBoundingBox const& box);
        static auto FromOrientedBox(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::Spatial::SpatialBoundingOrientedBox const& box);
        static auto FromSphere(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::Spatial::SpatialBoundingSphere const& sphere);
        static auto FromFrustum(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::Spatial::SpatialBoundingFrustum const& frustum);
    };
    struct __declspec(empty_bases) SpatialCoordinateSystem : llm:OS::Perception::Spatial::ISpatialCoordinateSystem
    {
        SpatialCoordinateSystem(std::nullptr_t) noexcept {}
        SpatialCoordinateSystem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialCoordinateSystem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialEntity : llm:OS::Perception::Spatial::ISpatialEntity
    {
        SpatialEntity(std::nullptr_t) noexcept {}
        SpatialEntity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntity(ptr, take_ownership_from_abi) {}
        explicit SpatialEntity(llm:OS::Perception::Spatial::SpatialAnchor const& spatialAnchor);
        SpatialEntity(llm:OS::Perception::Spatial::SpatialAnchor const& spatialAnchor, llm:OS::Foundation::Collections::ValueSet const& propertySet);
    };
    struct __declspec(empty_bases) SpatialEntityAddedEventArgs : llm:OS::Perception::Spatial::ISpatialEntityAddedEventArgs
    {
        SpatialEntityAddedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntityAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialEntityRemovedEventArgs : llm:OS::Perception::Spatial::ISpatialEntityRemovedEventArgs
    {
        SpatialEntityRemovedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntityRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialEntityStore : llm:OS::Perception::Spatial::ISpatialEntityStore
    {
        SpatialEntityStore(std::nullptr_t) noexcept {}
        SpatialEntityStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntityStore(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto IsSupported();
        static auto TryGet(llm:OS::System::RemoteSystems::RemoteSystemSession const& session);
    };
    struct __declspec(empty_bases) SpatialEntityUpdatedEventArgs : llm:OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs
    {
        SpatialEntityUpdatedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntityUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialEntityWatcher : llm:OS::Perception::Spatial::ISpatialEntityWatcher
    {
        SpatialEntityWatcher(std::nullptr_t) noexcept {}
        SpatialEntityWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialEntityWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialLocation : llm:OS::Perception::Spatial::ISpatialLocation,
        impl::require<SpatialLocation, llm:OS::Perception::Spatial::ISpatialLocation2>
    {
        SpatialLocation(std::nullptr_t) noexcept {}
        SpatialLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialLocation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialLocator : llm:OS::Perception::Spatial::ISpatialLocator
    {
        SpatialLocator(std::nullptr_t) noexcept {}
        SpatialLocator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialLocator(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) SpatialLocatorAttachedFrameOfReference : llm:OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference
    {
        SpatialLocatorAttachedFrameOfReference(std::nullptr_t) noexcept {}
        SpatialLocatorAttachedFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialLocatorPositionalTrackingDeactivatingEventArgs : llm:OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs
    {
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(std::nullptr_t) noexcept {}
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialStageFrameOfReference : llm:OS::Perception::Spatial::ISpatialStageFrameOfReference
    {
        SpatialStageFrameOfReference(std::nullptr_t) noexcept {}
        SpatialStageFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialStageFrameOfReference(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto CurrentChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using CurrentChanged_revoker = impl::factory_event_revoker<llm:OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics, &impl::abi_t<llm:OS::Perception::Spatial::ISpatialStageFrameOfReferenceStatics>::remove_CurrentChanged>;
        [[nodiscard]] static CurrentChanged_revoker CurrentChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto CurrentChanged(llm::event_token const& cookie);
        static auto RequestNewStageAsync();
    };
    struct __declspec(empty_bases) SpatialStationaryFrameOfReference : llm:OS::Perception::Spatial::ISpatialStationaryFrameOfReference
    {
        SpatialStationaryFrameOfReference(std::nullptr_t) noexcept {}
        SpatialStationaryFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Perception::Spatial::ISpatialStationaryFrameOfReference(ptr, take_ownership_from_abi) {}
    };
}
#endif
