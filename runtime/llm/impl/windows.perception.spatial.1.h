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
#ifndef LLM_OS_Perception_Spatial_1_H
#define LLM_OS_Perception_Spatial_1_H
#include "llm/impl/Windows.Perception.Spatial.0.h"
LLM_EXPORT namespace llm:OS::Perception::Spatial
{
    struct __declspec(empty_bases) ISpatialAnchor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchor>
    {
        ISpatialAnchor(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchor2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchor2>
    {
        ISpatialAnchor2(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchor2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorExportSufficiency :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorExportSufficiency>
    {
        ISpatialAnchorExportSufficiency(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorExportSufficiency(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorExporter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorExporter>
    {
        ISpatialAnchorExporter(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorExporter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorExporterStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorExporterStatics>
    {
        ISpatialAnchorExporterStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorExporterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorManagerStatics>
    {
        ISpatialAnchorManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorRawCoordinateSystemAdjustedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorRawCoordinateSystemAdjustedEventArgs>
    {
        ISpatialAnchorRawCoordinateSystemAdjustedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorRawCoordinateSystemAdjustedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorStatics>
    {
        ISpatialAnchorStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorStore :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorStore>
    {
        ISpatialAnchorStore(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAnchorTransferManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAnchorTransferManagerStatics>
    {
        ISpatialAnchorTransferManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAnchorTransferManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialBoundingVolume :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialBoundingVolume>
    {
        ISpatialBoundingVolume(std::nullptr_t = nullptr) noexcept {}
        ISpatialBoundingVolume(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialBoundingVolumeStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialBoundingVolumeStatics>
    {
        ISpatialBoundingVolumeStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialBoundingVolumeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialCoordinateSystem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialCoordinateSystem>
    {
        ISpatialCoordinateSystem(std::nullptr_t = nullptr) noexcept {}
        ISpatialCoordinateSystem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntity :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntity>
    {
        ISpatialEntity(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntity(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityAddedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityAddedEventArgs>
    {
        ISpatialEntityAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityFactory>
    {
        ISpatialEntityFactory(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityRemovedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityRemovedEventArgs>
    {
        ISpatialEntityRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityStore :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityStore>
    {
        ISpatialEntityStore(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityStore(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityStoreStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityStoreStatics>
    {
        ISpatialEntityStoreStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityStoreStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityUpdatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityUpdatedEventArgs>
    {
        ISpatialEntityUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialEntityWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialEntityWatcher>
    {
        ISpatialEntityWatcher(std::nullptr_t = nullptr) noexcept {}
        ISpatialEntityWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocation>
    {
        ISpatialLocation(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocation2>
    {
        ISpatialLocation2(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocator>
    {
        ISpatialLocator(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocatorAttachedFrameOfReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocatorAttachedFrameOfReference>
    {
        ISpatialLocatorAttachedFrameOfReference(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocatorAttachedFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocatorPositionalTrackingDeactivatingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocatorPositionalTrackingDeactivatingEventArgs>
    {
        ISpatialLocatorPositionalTrackingDeactivatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocatorPositionalTrackingDeactivatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialLocatorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialLocatorStatics>
    {
        ISpatialLocatorStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialLocatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialStageFrameOfReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialStageFrameOfReference>
    {
        ISpatialStageFrameOfReference(std::nullptr_t = nullptr) noexcept {}
        ISpatialStageFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialStageFrameOfReferenceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialStageFrameOfReferenceStatics>
    {
        ISpatialStageFrameOfReferenceStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialStageFrameOfReferenceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialStationaryFrameOfReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialStationaryFrameOfReference>
    {
        ISpatialStationaryFrameOfReference(std::nullptr_t = nullptr) noexcept {}
        ISpatialStationaryFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
