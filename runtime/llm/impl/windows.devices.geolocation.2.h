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
#ifndef LLM_OS_Devices_Geolocation_2_H
#define LLM_OS_Devices_Geolocation_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Devices.Geolocation.1.h"
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    struct BasicGeoposition
    {
        double Latitude;
        double Longitude;
        double Altitude;
    };
    inline bool operator==(BasicGeoposition const& left, BasicGeoposition const& right) noexcept
    {
        return left.Latitude == right.Latitude && left.Longitude == right.Longitude && left.Altitude == right.Altitude;
    }
    inline bool operator!=(BasicGeoposition const& left, BasicGeoposition const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) CivicAddress : llm::OS::Devices::Geolocation::ICivicAddress
    {
        CivicAddress(std::nullptr_t) noexcept {}
        CivicAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::ICivicAddress(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeoboundingBox : llm::OS::Devices::Geolocation::IGeoboundingBox
    {
        GeoboundingBox(std::nullptr_t) noexcept {}
        GeoboundingBox(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeoboundingBox(ptr, take_ownership_from_abi) {}
        GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner);
        GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
        static auto TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions);
        static auto TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem);
        static auto TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geocircle : llm::OS::Devices::Geolocation::IGeocircle
    {
        Geocircle(std::nullptr_t) noexcept {}
        Geocircle(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeocircle(ptr, take_ownership_from_abi) {}
        Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius);
        Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geocoordinate : llm::OS::Devices::Geolocation::IGeocoordinate,
        impl::require<Geocoordinate, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData, llm::OS::Devices::Geolocation::IGeocoordinateWithPoint, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp, llm::OS::Devices::Geolocation::IGeocoordinateWithRemoteSource>
    {
        Geocoordinate(std::nullptr_t) noexcept {}
        Geocoordinate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeocoordinate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeocoordinateSatelliteData : llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData,
        impl::require<GeocoordinateSatelliteData, llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2>
    {
        GeocoordinateSatelliteData(std::nullptr_t) noexcept {}
        GeocoordinateSatelliteData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Geolocator : llm::OS::Devices::Geolocation::IGeolocator,
        impl::require<Geolocator, llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy, llm::OS::Devices::Geolocation::IGeolocator2>
    {
        Geolocator(std::nullptr_t) noexcept {}
        Geolocator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeolocator(ptr, take_ownership_from_abi) {}
        Geolocator();
        static auto RequestAccessAsync();
        static auto GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime);
        static auto GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration);
        [[nodiscard]] static auto IsDefaultGeopositionRecommended();
        static auto DefaultGeoposition(llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition> const& value);
        [[nodiscard]] static auto DefaultGeoposition();
    };
    struct __declspec(empty_bases) Geopath : llm::OS::Devices::Geolocation::IGeopath
    {
        Geopath(std::nullptr_t) noexcept {}
        Geopath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeopath(ptr, take_ownership_from_abi) {}
        explicit Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions);
        Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geopoint : llm::OS::Devices::Geolocation::IGeopoint
    {
        Geopoint(std::nullptr_t) noexcept {}
        Geopoint(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeopoint(ptr, take_ownership_from_abi) {}
        explicit Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position);
        Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem);
        Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId);
    };
    struct __declspec(empty_bases) Geoposition : llm::OS::Devices::Geolocation::IGeoposition,
        impl::require<Geoposition, llm::OS::Devices::Geolocation::IGeoposition2>
    {
        Geoposition(std::nullptr_t) noexcept {}
        Geoposition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeoposition(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Geovisit : llm::OS::Devices::Geolocation::IGeovisit
    {
        Geovisit(std::nullptr_t) noexcept {}
        Geovisit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeovisit(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeovisitMonitor : llm::OS::Devices::Geolocation::IGeovisitMonitor
    {
        GeovisitMonitor(std::nullptr_t) noexcept {}
        GeovisitMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeovisitMonitor(ptr, take_ownership_from_abi) {}
        GeovisitMonitor();
        static auto GetLastReportAsync();
    };
    struct __declspec(empty_bases) GeovisitStateChangedEventArgs : llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs
    {
        GeovisitStateChangedEventArgs(std::nullptr_t) noexcept {}
        GeovisitStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeovisitTriggerDetails : llm::OS::Devices::Geolocation::IGeovisitTriggerDetails
    {
        GeovisitTriggerDetails(std::nullptr_t) noexcept {}
        GeovisitTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IGeovisitTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PositionChangedEventArgs : llm::OS::Devices::Geolocation::IPositionChangedEventArgs
    {
        PositionChangedEventArgs(std::nullptr_t) noexcept {}
        PositionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IPositionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StatusChangedEventArgs : llm::OS::Devices::Geolocation::IStatusChangedEventArgs
    {
        StatusChangedEventArgs(std::nullptr_t) noexcept {}
        StatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VenueData : llm::OS::Devices::Geolocation::IVenueData
    {
        VenueData(std::nullptr_t) noexcept {}
        VenueData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::IVenueData(ptr, take_ownership_from_abi) {}
    };
}
#endif
