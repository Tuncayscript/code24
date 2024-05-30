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
#ifndef LLM_OS_Services_Maps_2_H
#define LLM_OS_Services_Maps_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Services.Maps.1.h"
LLM_EXPORT namespace llm:OS::Services::Maps
{
    struct __declspec(empty_bases) EnhancedWaypoint : llm:OS::Services::Maps::IEnhancedWaypoint
    {
        EnhancedWaypoint(std::nullptr_t) noexcept {}
        EnhancedWaypoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IEnhancedWaypoint(ptr, take_ownership_from_abi) {}
        EnhancedWaypoint(llm:OS::Devices::Geolocation::Geopoint const& point, llm:OS::Services::Maps::WaypointKind const& kind);
    };
    struct __declspec(empty_bases) ManeuverWarning : llm:OS::Services::Maps::IManeuverWarning
    {
        ManeuverWarning(std::nullptr_t) noexcept {}
        ManeuverWarning(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IManeuverWarning(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapAddress : llm:OS::Services::Maps::IMapAddress,
        impl::require<MapAddress, llm:OS::Services::Maps::IMapAddress2>
    {
        MapAddress(std::nullptr_t) noexcept {}
        MapAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapAddress(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapLocation : llm:OS::Services::Maps::IMapLocation
    {
        MapLocation(std::nullptr_t) noexcept {}
        MapLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapLocation(ptr, take_ownership_from_abi) {}
    };
    struct MapLocationFinder
    {
        MapLocationFinder() = delete;
        static auto FindLocationsAtAsync(llm:OS::Devices::Geolocation::Geopoint const& queryPoint);
        static auto FindLocationsAsync(param::hstring const& searchText, llm:OS::Devices::Geolocation::Geopoint const& referencePoint);
        static auto FindLocationsAsync(param::hstring const& searchText, llm:OS::Devices::Geolocation::Geopoint const& referencePoint, uint32_t maxCount);
        static auto FindLocationsAtAsync(llm:OS::Devices::Geolocation::Geopoint const& queryPoint, llm:OS::Services::Maps::MapLocationDesiredAccuracy const& accuracy);
    };
    struct __declspec(empty_bases) MapLocationFinderResult : llm:OS::Services::Maps::IMapLocationFinderResult
    {
        MapLocationFinderResult(std::nullptr_t) noexcept {}
        MapLocationFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapLocationFinderResult(ptr, take_ownership_from_abi) {}
    };
    struct MapManager
    {
        MapManager() = delete;
        static auto ShowDownloadedMapsUI();
        static auto ShowMapsUpdateUI();
    };
    struct __declspec(empty_bases) MapRoute : llm:OS::Services::Maps::IMapRoute,
        impl::require<MapRoute, llm:OS::Services::Maps::IMapRoute2, llm:OS::Services::Maps::IMapRoute3, llm:OS::Services::Maps::IMapRoute4>
    {
        MapRoute(std::nullptr_t) noexcept {}
        MapRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapRoute(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapRouteDrivingOptions : llm:OS::Services::Maps::IMapRouteDrivingOptions,
        impl::require<MapRouteDrivingOptions, llm:OS::Services::Maps::IMapRouteDrivingOptions2>
    {
        MapRouteDrivingOptions(std::nullptr_t) noexcept {}
        MapRouteDrivingOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapRouteDrivingOptions(ptr, take_ownership_from_abi) {}
        MapRouteDrivingOptions();
    };
    struct MapRouteFinder
    {
        MapRouteFinder() = delete;
        static auto GetDrivingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint);
        static auto GetDrivingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint, llm:OS::Services::Maps::MapRouteOptimization const& optimization);
        static auto GetDrivingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint, llm:OS::Services::Maps::MapRouteOptimization const& optimization, llm:OS::Services::Maps::MapRouteRestrictions const& restrictions);
        static auto GetDrivingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint, llm:OS::Services::Maps::MapRouteOptimization const& optimization, llm:OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees);
        static auto GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm:OS::Devices::Geolocation::Geopoint> const& wayPoints);
        static auto GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm:OS::Devices::Geolocation::Geopoint> const& wayPoints, llm:OS::Services::Maps::MapRouteOptimization const& optimization);
        static auto GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm:OS::Devices::Geolocation::Geopoint> const& wayPoints, llm:OS::Services::Maps::MapRouteOptimization const& optimization, llm:OS::Services::Maps::MapRouteRestrictions const& restrictions);
        static auto GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm:OS::Devices::Geolocation::Geopoint> const& wayPoints, llm:OS::Services::Maps::MapRouteOptimization const& optimization, llm:OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees);
        static auto GetWalkingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint);
        static auto GetWalkingRouteFromWaypointsAsync(param::async_iterable<llm:OS::Devices::Geolocation::Geopoint> const& wayPoints);
        static auto GetDrivingRouteAsync(llm:OS::Devices::Geolocation::Geopoint const& startPoint, llm:OS::Devices::Geolocation::Geopoint const& endPoint, llm:OS::Services::Maps::MapRouteDrivingOptions const& options);
        static auto GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm:OS::Services::Maps::EnhancedWaypoint> const& waypoints);
        static auto GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm:OS::Services::Maps::EnhancedWaypoint> const& waypoints, llm:OS::Services::Maps::MapRouteDrivingOptions const& options);
    };
    struct __declspec(empty_bases) MapRouteFinderResult : llm:OS::Services::Maps::IMapRouteFinderResult,
        impl::require<MapRouteFinderResult, llm:OS::Services::Maps::IMapRouteFinderResult2>
    {
        MapRouteFinderResult(std::nullptr_t) noexcept {}
        MapRouteFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapRouteFinderResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapRouteLeg : llm:OS::Services::Maps::IMapRouteLeg,
        impl::require<MapRouteLeg, llm:OS::Services::Maps::IMapRouteLeg2>
    {
        MapRouteLeg(std::nullptr_t) noexcept {}
        MapRouteLeg(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapRouteLeg(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MapRouteManeuver : llm:OS::Services::Maps::IMapRouteManeuver,
        impl::require<MapRouteManeuver, llm:OS::Services::Maps::IMapRouteManeuver2, llm:OS::Services::Maps::IMapRouteManeuver3>
    {
        MapRouteManeuver(std::nullptr_t) noexcept {}
        MapRouteManeuver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IMapRouteManeuver(ptr, take_ownership_from_abi) {}
    };
    struct MapService
    {
        MapService() = delete;
        static auto ServiceToken(param::hstring const& value);
        [[nodiscard]] static auto ServiceToken();
        [[nodiscard]] static auto WorldViewRegionCode();
        [[nodiscard]] static auto DataAttributions();
        static auto DataUsagePreference(llm:OS::Services::Maps::MapServiceDataUsagePreference const& value);
        [[nodiscard]] static auto DataUsagePreference();
    };
    struct __declspec(empty_bases) PlaceInfo : llm:OS::Services::Maps::IPlaceInfo
    {
        PlaceInfo(std::nullptr_t) noexcept {}
        PlaceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IPlaceInfo(ptr, take_ownership_from_abi) {}
        static auto Create(llm:OS::Devices::Geolocation::Geopoint const& referencePoint);
        static auto Create(llm:OS::Devices::Geolocation::Geopoint const& referencePoint, llm:OS::Services::Maps::PlaceInfoCreateOptions const& options);
        static auto CreateFromIdentifier(param::hstring const& identifier);
        static auto CreateFromIdentifier(param::hstring const& identifier, llm:OS::Devices::Geolocation::Geopoint const& defaultPoint, llm:OS::Services::Maps::PlaceInfoCreateOptions const& options);
        static auto CreateFromMapLocation(llm:OS::Services::Maps::MapLocation const& location);
        [[nodiscard]] static auto IsShowSupported();
        static auto CreateFromAddress(param::hstring const& displayAddress);
        static auto CreateFromAddress(param::hstring const& displayAddress, param::hstring const& displayName);
    };
    struct __declspec(empty_bases) PlaceInfoCreateOptions : llm:OS::Services::Maps::IPlaceInfoCreateOptions
    {
        PlaceInfoCreateOptions(std::nullptr_t) noexcept {}
        PlaceInfoCreateOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::IPlaceInfoCreateOptions(ptr, take_ownership_from_abi) {}
        PlaceInfoCreateOptions();
    };
}
#endif
