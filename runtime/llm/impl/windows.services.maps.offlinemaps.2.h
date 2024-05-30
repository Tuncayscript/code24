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
#ifndef LLM_OS_Services_Maps_OfflineMaps_2_H
#define LLM_OS_Services_Maps_OfflineMaps_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Services.Maps.OfflineMaps.1.h"
LLM_EXPORT namespace llm:OS::Services::Maps::OfflineMaps
{
    struct __declspec(empty_bases) OfflineMapPackage : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackage
    {
        OfflineMapPackage(std::nullptr_t) noexcept {}
        OfflineMapPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackage(ptr, take_ownership_from_abi) {}
        static auto FindPackagesAsync(llm:OS::Devices::Geolocation::Geopoint const& queryPoint);
        static auto FindPackagesInBoundingBoxAsync(llm:OS::Devices::Geolocation::GeoboundingBox const& queryBoundingBox);
        static auto FindPackagesInGeocircleAsync(llm:OS::Devices::Geolocation::Geocircle const& queryCircle);
    };
    struct __declspec(empty_bases) OfflineMapPackageQueryResult : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult
    {
        OfflineMapPackageQueryResult(std::nullptr_t) noexcept {}
        OfflineMapPackageQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OfflineMapPackageStartDownloadResult : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult
    {
        OfflineMapPackageStartDownloadResult(std::nullptr_t) noexcept {}
        OfflineMapPackageStartDownloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
