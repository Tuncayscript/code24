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
#ifndef LLM_OS_Services_Maps_H
#define LLM_OS_Services_Maps_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.Services.Maps.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Services_Maps_IEnhancedWaypoint<D>::Point() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IEnhancedWaypoint)->get_Point(&value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::WaypointKind) consume_Windows_Services_Maps_IEnhancedWaypoint<D>::Kind() const
    {
        llm::OS::Services::Maps::WaypointKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IEnhancedWaypoint)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::EnhancedWaypoint) consume_Windows_Services_Maps_IEnhancedWaypointFactory<D>::Create(llm::OS::Devices::Geolocation::Geopoint const& point, llm::OS::Services::Maps::WaypointKind const& kind) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IEnhancedWaypointFactory)->Create(*(void**)(&point), static_cast<int32_t>(kind), &value));
        return llm::OS::Services::Maps::EnhancedWaypoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::ManeuverWarningKind) consume_Windows_Services_Maps_IManeuverWarning<D>::Kind() const
    {
        llm::OS::Services::Maps::ManeuverWarningKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IManeuverWarning)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::ManeuverWarningSeverity) consume_Windows_Services_Maps_IManeuverWarning<D>::Severity() const
    {
        llm::OS::Services::Maps::ManeuverWarningSeverity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IManeuverWarning)->get_Severity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::BuildingName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_BuildingName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::BuildingFloor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_BuildingFloor(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::BuildingRoom() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_BuildingRoom(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::BuildingWing() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_BuildingWing(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::StreetNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_StreetNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Street() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Street(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Neighborhood() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Neighborhood(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::District() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_District(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Town() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Town(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Region() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Region(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::RegionCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_RegionCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Country() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Country(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::CountryCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_CountryCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::PostCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_PostCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress<D>::Continent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress)->get_Continent(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapAddress2<D>::FormattedAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapAddress2)->get_FormattedAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Services_Maps_IMapLocation<D>::Point() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocation)->get_Point(&value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapLocation<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocation)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapLocation<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocation)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapAddress) consume_Windows_Services_Maps_IMapLocation<D>::Address() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocation)->get_Address(&value));
        return llm::OS::Services::Maps::MapAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapLocation>) consume_Windows_Services_Maps_IMapLocationFinderResult<D>::Locations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderResult)->get_Locations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapLocation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapLocationFinderStatus) consume_Windows_Services_Maps_IMapLocationFinderResult<D>::Status() const
    {
        llm::OS::Services::Maps::MapLocationFinderStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>) consume_Windows_Services_Maps_IMapLocationFinderStatics<D>::FindLocationsAtAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderStatics)->FindLocationsAtAsync(*(void**)(&queryPoint), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>) consume_Windows_Services_Maps_IMapLocationFinderStatics<D>::FindLocationsAsync(param::hstring const& searchText, llm::OS::Devices::Geolocation::Geopoint const& referencePoint) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderStatics)->FindLocationsAsync(*(void**)(&searchText), *(void**)(&referencePoint), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>) consume_Windows_Services_Maps_IMapLocationFinderStatics<D>::FindLocationsAsync(param::hstring const& searchText, llm::OS::Devices::Geolocation::Geopoint const& referencePoint, uint32_t maxCount) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderStatics)->FindLocationsWithMaxCountAsync(*(void**)(&searchText), *(void**)(&referencePoint), maxCount, &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>) consume_Windows_Services_Maps_IMapLocationFinderStatics2<D>::FindLocationsAtAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint, llm::OS::Services::Maps::MapLocationDesiredAccuracy const& accuracy) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapLocationFinderStatics2)->FindLocationsAtWithAccuracyAsync(*(void**)(&queryPoint), static_cast<int32_t>(accuracy), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapManagerStatics<D>::ShowDownloadedMapsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapManagerStatics)->ShowDownloadedMapsUI());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapManagerStatics<D>::ShowMapsUpdateUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapManagerStatics)->ShowMapsUpdateUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Services_Maps_IMapRoute<D>::BoundingBox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_BoundingBox(&value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Services_Maps_IMapRoute<D>::LengthInMeters() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_LengthInMeters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_IMapRoute<D>::EstimatedDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_EstimatedDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopath) consume_Windows_Services_Maps_IMapRoute<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_Path(&value));
        return llm::OS::Devices::Geolocation::Geopath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteLeg>) consume_Windows_Services_Maps_IMapRoute<D>::Legs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_Legs(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteLeg>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Maps_IMapRoute<D>::IsTrafficBased() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute)->get_IsTrafficBased(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRouteRestrictions) consume_Windows_Services_Maps_IMapRoute2<D>::ViolatedRestrictions() const
    {
        llm::OS::Services::Maps::MapRouteRestrictions value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute2)->get_ViolatedRestrictions(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Maps_IMapRoute2<D>::HasBlockedRoads() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute2)->get_HasBlockedRoads(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_IMapRoute3<D>::DurationWithoutTraffic() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute3)->get_DurationWithoutTraffic(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::TrafficCongestion) consume_Windows_Services_Maps_IMapRoute3<D>::TrafficCongestion() const
    {
        llm::OS::Services::Maps::TrafficCongestion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute3)->get_TrafficCongestion(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Maps_IMapRoute4<D>::IsScenic() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRoute4)->get_IsScenic(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::MaxAlternateRouteCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->get_MaxAlternateRouteCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::MaxAlternateRouteCount(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->put_MaxAlternateRouteCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::InitialHeading() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->get_InitialHeading(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::InitialHeading(llm::OS::Foundation::IReference<double> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->put_InitialHeading(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRouteOptimization) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::RouteOptimization() const
    {
        llm::OS::Services::Maps::MapRouteOptimization value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->get_RouteOptimization(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::RouteOptimization(llm::OS::Services::Maps::MapRouteOptimization const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->put_RouteOptimization(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRouteRestrictions) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::RouteRestrictions() const
    {
        llm::OS::Services::Maps::MapRouteRestrictions value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->get_RouteRestrictions(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapRouteDrivingOptions<D>::RouteRestrictions(llm::OS::Services::Maps::MapRouteRestrictions const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions)->put_RouteRestrictions(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Services_Maps_IMapRouteDrivingOptions2<D>::DepartureTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions2)->get_DepartureTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapRouteDrivingOptions2<D>::DepartureTime(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteDrivingOptions2)->put_DepartureTime(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRoute) consume_Windows_Services_Maps_IMapRouteFinderResult<D>::Route() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderResult)->get_Route(&value));
        return llm::OS::Services::Maps::MapRoute{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRouteFinderStatus) consume_Windows_Services_Maps_IMapRouteFinderResult<D>::Status() const
    {
        llm::OS::Services::Maps::MapRouteFinderStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRoute>) consume_Windows_Services_Maps_IMapRouteFinderResult2<D>::AlternateRoutes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderResult2)->get_AlternateRoutes(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteAsync(*(void**)(&startPoint), *(void**)(&endPoint), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteWithOptimizationAsync(*(void**)(&startPoint), *(void**)(&endPoint), static_cast<int32_t>(optimization), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteWithOptimizationAndRestrictionsAsync(*(void**)(&startPoint), *(void**)(&endPoint), static_cast<int32_t>(optimization), static_cast<uint32_t>(restrictions), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteWithOptimizationRestrictionsAndHeadingAsync(*(void**)(&startPoint), *(void**)(&endPoint), static_cast<int32_t>(optimization), static_cast<uint32_t>(restrictions), headingInDegrees, &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteFromWaypointsAsync(*(void**)(&wayPoints), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteFromWaypointsAndOptimizationAsync(*(void**)(&wayPoints), static_cast<int32_t>(optimization), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync(*(void**)(&wayPoints), static_cast<int32_t>(optimization), static_cast<uint32_t>(restrictions), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync(*(void**)(&wayPoints), static_cast<int32_t>(optimization), static_cast<uint32_t>(restrictions), headingInDegrees, &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetWalkingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetWalkingRouteAsync(*(void**)(&startPoint), *(void**)(&endPoint), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics<D>::GetWalkingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics)->GetWalkingRouteFromWaypointsAsync(*(void**)(&wayPoints), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics2<D>::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteDrivingOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics2)->GetDrivingRouteWithOptionsAsync(*(void**)(&startPoint), *(void**)(&endPoint), *(void**)(&options), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics3<D>::GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm::OS::Services::Maps::EnhancedWaypoint> const& waypoints) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics3)->GetDrivingRouteFromEnhancedWaypointsAsync(*(void**)(&waypoints), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>) consume_Windows_Services_Maps_IMapRouteFinderStatics3<D>::GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm::OS::Services::Maps::EnhancedWaypoint> const& waypoints, llm::OS::Services::Maps::MapRouteDrivingOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteFinderStatics3)->GetDrivingRouteFromEnhancedWaypointsWithOptionsAsync(*(void**)(&waypoints), *(void**)(&options), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Services_Maps_IMapRouteLeg<D>::BoundingBox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg)->get_BoundingBox(&value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopath) consume_Windows_Services_Maps_IMapRouteLeg<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg)->get_Path(&value));
        return llm::OS::Devices::Geolocation::Geopath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Services_Maps_IMapRouteLeg<D>::LengthInMeters() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg)->get_LengthInMeters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_IMapRouteLeg<D>::EstimatedDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg)->get_EstimatedDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteManeuver>) consume_Windows_Services_Maps_IMapRouteLeg<D>::Maneuvers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg)->get_Maneuvers(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteManeuver>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Services_Maps_IMapRouteLeg2<D>::DurationWithoutTraffic() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg2)->get_DurationWithoutTraffic(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::TrafficCongestion) consume_Windows_Services_Maps_IMapRouteLeg2<D>::TrafficCongestion() const
    {
        llm::OS::Services::Maps::TrafficCongestion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteLeg2)->get_TrafficCongestion(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Services_Maps_IMapRouteManeuver<D>::StartingPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_StartingPoint(&value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Services_Maps_IMapRouteManeuver<D>::LengthInMeters() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_LengthInMeters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapRouteManeuver<D>::InstructionText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_InstructionText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapRouteManeuverKind) consume_Windows_Services_Maps_IMapRouteManeuver<D>::Kind() const
    {
        llm::OS::Services::Maps::MapRouteManeuverKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapRouteManeuver<D>::ExitNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_ExitNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapManeuverNotices) consume_Windows_Services_Maps_IMapRouteManeuver<D>::ManeuverNotices() const
    {
        llm::OS::Services::Maps::MapManeuverNotices value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver)->get_ManeuverNotices(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Services_Maps_IMapRouteManeuver2<D>::StartHeading() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver2)->get_StartHeading(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Services_Maps_IMapRouteManeuver2<D>::EndHeading() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver2)->get_EndHeading(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapRouteManeuver2<D>::StreetName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver2)->get_StreetName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::ManeuverWarning>) consume_Windows_Services_Maps_IMapRouteManeuver3<D>::Warnings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapRouteManeuver3)->get_Warnings(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::ManeuverWarning>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapServiceStatics<D>::ServiceToken(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics)->put_ServiceToken(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapServiceStatics<D>::ServiceToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics)->get_ServiceToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapServiceStatics2<D>::WorldViewRegionCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics2)->get_WorldViewRegionCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IMapServiceStatics3<D>::DataAttributions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics3)->get_DataAttributions(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IMapServiceStatics4<D>::DataUsagePreference(llm::OS::Services::Maps::MapServiceDataUsagePreference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics4)->put_DataUsagePreference(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::MapServiceDataUsagePreference) consume_Windows_Services_Maps_IMapServiceStatics4<D>::DataUsagePreference() const
    {
        llm::OS::Services::Maps::MapServiceDataUsagePreference value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IMapServiceStatics4)->get_DataUsagePreference(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IPlaceInfo<D>::Show(llm::OS::Foundation::Rect const& selection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->Show(impl::bind_in(selection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IPlaceInfo<D>::Show(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->ShowWithPreferredPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IPlaceInfo<D>::Identifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->get_Identifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IPlaceInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IPlaceInfo<D>::DisplayAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->get_DisplayAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::IGeoshape) consume_Windows_Services_Maps_IPlaceInfo<D>::Geoshape() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfo)->get_Geoshape(&value));
        return llm::OS::Devices::Geolocation::IGeoshape{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IPlaceInfoCreateOptions<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoCreateOptions)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IPlaceInfoCreateOptions<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoCreateOptions)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_IPlaceInfoCreateOptions<D>::DisplayAddress(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoCreateOptions)->put_DisplayAddress(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_IPlaceInfoCreateOptions<D>::DisplayAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoCreateOptions)->get_DisplayAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::Create(llm::OS::Devices::Geolocation::Geopoint const& referencePoint) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->Create(*(void**)(&referencePoint), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::Create(llm::OS::Devices::Geolocation::Geopoint const& referencePoint, llm::OS::Services::Maps::PlaceInfoCreateOptions const& options) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->CreateWithGeopointAndOptions(*(void**)(&referencePoint), *(void**)(&options), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::CreateFromIdentifier(param::hstring const& identifier) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->CreateFromIdentifier(*(void**)(&identifier), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::CreateFromIdentifier(param::hstring const& identifier, llm::OS::Devices::Geolocation::Geopoint const& defaultPoint, llm::OS::Services::Maps::PlaceInfoCreateOptions const& options) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->CreateFromIdentifierWithOptions(*(void**)(&identifier), *(void**)(&defaultPoint), *(void**)(&options), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::CreateFromMapLocation(llm::OS::Services::Maps::MapLocation const& location) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->CreateFromMapLocation(*(void**)(&location), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Services_Maps_IPlaceInfoStatics<D>::IsShowSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics)->get_IsShowSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics2<D>::CreateFromAddress(param::hstring const& displayAddress) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics2)->CreateFromAddress(*(void**)(&displayAddress), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::PlaceInfo) consume_Windows_Services_Maps_IPlaceInfoStatics2<D>::CreateFromAddress(param::hstring const& displayAddress, param::hstring const& displayName) const
    {
        void* resultValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::IPlaceInfoStatics2)->CreateFromAddressWithName(*(void**)(&displayAddress), *(void**)(&displayName), &resultValue));
        return llm::OS::Services::Maps::PlaceInfo{ resultValue, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IEnhancedWaypoint> : produce_base<D, llm::OS::Services::Maps::IEnhancedWaypoint>
    {
        int32_t __stdcall get_Point(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().Point());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::WaypointKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IEnhancedWaypointFactory> : produce_base<D, llm::OS::Services::Maps::IEnhancedWaypointFactory>
    {
        int32_t __stdcall Create(void* point, int32_t kind, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::EnhancedWaypoint>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&point), *reinterpret_cast<llm::OS::Services::Maps::WaypointKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IManeuverWarning> : produce_base<D, llm::OS::Services::Maps::IManeuverWarning>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::ManeuverWarningKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Severity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::ManeuverWarningSeverity>(this->shim().Severity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapAddress> : produce_base<D, llm::OS::Services::Maps::IMapAddress>
    {
        int32_t __stdcall get_BuildingName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BuildingName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BuildingFloor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BuildingFloor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BuildingRoom(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BuildingRoom());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BuildingWing(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BuildingWing());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StreetNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StreetNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Street(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Street());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Neighborhood(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Neighborhood());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_District(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().District());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Town(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Town());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Region(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Region());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegionCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RegionCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Country(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Country());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CountryCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CountryCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PostCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PostCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Continent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Continent());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapAddress2> : produce_base<D, llm::OS::Services::Maps::IMapAddress2>
    {
        int32_t __stdcall get_FormattedAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FormattedAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapLocation> : produce_base<D, llm::OS::Services::Maps::IMapLocation>
    {
        int32_t __stdcall get_Point(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().Point());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Address(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapAddress>(this->shim().Address());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapLocationFinderResult> : produce_base<D, llm::OS::Services::Maps::IMapLocationFinderResult>
    {
        int32_t __stdcall get_Locations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapLocation>>(this->shim().Locations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapLocationFinderStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapLocationFinderStatics> : produce_base<D, llm::OS::Services::Maps::IMapLocationFinderStatics>
    {
        int32_t __stdcall FindLocationsAtAsync(void* queryPoint, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>>(this->shim().FindLocationsAtAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&queryPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindLocationsAsync(void* searchText, void* referencePoint, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>>(this->shim().FindLocationsAsync(*reinterpret_cast<hstring const*>(&searchText), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&referencePoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindLocationsWithMaxCountAsync(void* searchText, void* referencePoint, uint32_t maxCount, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>>(this->shim().FindLocationsAsync(*reinterpret_cast<hstring const*>(&searchText), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&referencePoint), maxCount));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapLocationFinderStatics2> : produce_base<D, llm::OS::Services::Maps::IMapLocationFinderStatics2>
    {
        int32_t __stdcall FindLocationsAtWithAccuracyAsync(void* queryPoint, int32_t accuracy, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapLocationFinderResult>>(this->shim().FindLocationsAtAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&queryPoint), *reinterpret_cast<llm::OS::Services::Maps::MapLocationDesiredAccuracy const*>(&accuracy)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapManagerStatics> : produce_base<D, llm::OS::Services::Maps::IMapManagerStatics>
    {
        int32_t __stdcall ShowDownloadedMapsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowDownloadedMapsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowMapsUpdateUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowMapsUpdateUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRoute> : produce_base<D, llm::OS::Services::Maps::IMapRoute>
    {
        int32_t __stdcall get_BoundingBox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().BoundingBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LengthInMeters(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().LengthInMeters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EstimatedDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().EstimatedDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopath>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Legs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteLeg>>(this->shim().Legs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTrafficBased(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTrafficBased());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRoute2> : produce_base<D, llm::OS::Services::Maps::IMapRoute2>
    {
        int32_t __stdcall get_ViolatedRestrictions(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRouteRestrictions>(this->shim().ViolatedRestrictions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasBlockedRoads(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasBlockedRoads());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRoute3> : produce_base<D, llm::OS::Services::Maps::IMapRoute3>
    {
        int32_t __stdcall get_DurationWithoutTraffic(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DurationWithoutTraffic());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrafficCongestion(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::TrafficCongestion>(this->shim().TrafficCongestion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRoute4> : produce_base<D, llm::OS::Services::Maps::IMapRoute4>
    {
        int32_t __stdcall get_IsScenic(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsScenic());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteDrivingOptions> : produce_base<D, llm::OS::Services::Maps::IMapRouteDrivingOptions>
    {
        int32_t __stdcall get_MaxAlternateRouteCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxAlternateRouteCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxAlternateRouteCount(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAlternateRouteCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialHeading(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().InitialHeading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialHeading(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialHeading(*reinterpret_cast<llm::OS::Foundation::IReference<double> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RouteOptimization(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRouteOptimization>(this->shim().RouteOptimization());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RouteOptimization(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RouteOptimization(*reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RouteRestrictions(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRouteRestrictions>(this->shim().RouteRestrictions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RouteRestrictions(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RouteRestrictions(*reinterpret_cast<llm::OS::Services::Maps::MapRouteRestrictions const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteDrivingOptions2> : produce_base<D, llm::OS::Services::Maps::IMapRouteDrivingOptions2>
    {
        int32_t __stdcall get_DepartureTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().DepartureTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DepartureTime(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DepartureTime(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteFinderResult> : produce_base<D, llm::OS::Services::Maps::IMapRouteFinderResult>
    {
        int32_t __stdcall get_Route(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRoute>(this->shim().Route());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRouteFinderStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteFinderResult2> : produce_base<D, llm::OS::Services::Maps::IMapRouteFinderResult2>
    {
        int32_t __stdcall get_AlternateRoutes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRoute>>(this->shim().AlternateRoutes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteFinderStatics> : produce_base<D, llm::OS::Services::Maps::IMapRouteFinderStatics>
    {
        int32_t __stdcall GetDrivingRouteAsync(void* startPoint, void* endPoint, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteWithOptimizationAsync(void* startPoint, void* endPoint, int32_t optimization, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteWithOptimizationAndRestrictionsAsync(void* startPoint, void* endPoint, int32_t optimization, uint32_t restrictions, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization), *reinterpret_cast<llm::OS::Services::Maps::MapRouteRestrictions const*>(&restrictions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteWithOptimizationRestrictionsAndHeadingAsync(void* startPoint, void* endPoint, int32_t optimization, uint32_t restrictions, double headingInDegrees, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization), *reinterpret_cast<llm::OS::Services::Maps::MapRouteRestrictions const*>(&restrictions), headingInDegrees));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteFromWaypointsAsync(void* wayPoints, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::Geopoint> const*>(&wayPoints)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteFromWaypointsAndOptimizationAsync(void* wayPoints, int32_t optimization, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::Geopoint> const*>(&wayPoints), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync(void* wayPoints, int32_t optimization, uint32_t restrictions, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::Geopoint> const*>(&wayPoints), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization), *reinterpret_cast<llm::OS::Services::Maps::MapRouteRestrictions const*>(&restrictions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync(void* wayPoints, int32_t optimization, uint32_t restrictions, double headingInDegrees, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::Geopoint> const*>(&wayPoints), *reinterpret_cast<llm::OS::Services::Maps::MapRouteOptimization const*>(&optimization), *reinterpret_cast<llm::OS::Services::Maps::MapRouteRestrictions const*>(&restrictions), headingInDegrees));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetWalkingRouteAsync(void* startPoint, void* endPoint, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetWalkingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetWalkingRouteFromWaypointsAsync(void* wayPoints, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetWalkingRouteFromWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::Geopoint> const*>(&wayPoints)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteFinderStatics2> : produce_base<D, llm::OS::Services::Maps::IMapRouteFinderStatics2>
    {
        int32_t __stdcall GetDrivingRouteWithOptionsAsync(void* startPoint, void* endPoint, void* options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&startPoint), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&endPoint), *reinterpret_cast<llm::OS::Services::Maps::MapRouteDrivingOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteFinderStatics3> : produce_base<D, llm::OS::Services::Maps::IMapRouteFinderStatics3>
    {
        int32_t __stdcall GetDrivingRouteFromEnhancedWaypointsAsync(void* waypoints, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromEnhancedWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Maps::EnhancedWaypoint> const*>(&waypoints)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrivingRouteFromEnhancedWaypointsWithOptionsAsync(void* waypoints, void* options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::MapRouteFinderResult>>(this->shim().GetDrivingRouteFromEnhancedWaypointsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Services::Maps::EnhancedWaypoint> const*>(&waypoints), *reinterpret_cast<llm::OS::Services::Maps::MapRouteDrivingOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteLeg> : produce_base<D, llm::OS::Services::Maps::IMapRouteLeg>
    {
        int32_t __stdcall get_BoundingBox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().BoundingBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopath>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LengthInMeters(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().LengthInMeters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EstimatedDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().EstimatedDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Maneuvers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::MapRouteManeuver>>(this->shim().Maneuvers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteLeg2> : produce_base<D, llm::OS::Services::Maps::IMapRouteLeg2>
    {
        int32_t __stdcall get_DurationWithoutTraffic(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DurationWithoutTraffic());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrafficCongestion(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::TrafficCongestion>(this->shim().TrafficCongestion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteManeuver> : produce_base<D, llm::OS::Services::Maps::IMapRouteManeuver>
    {
        int32_t __stdcall get_StartingPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().StartingPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LengthInMeters(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().LengthInMeters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstructionText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InstructionText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapRouteManeuverKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExitNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExitNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ManeuverNotices(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapManeuverNotices>(this->shim().ManeuverNotices());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteManeuver2> : produce_base<D, llm::OS::Services::Maps::IMapRouteManeuver2>
    {
        int32_t __stdcall get_StartHeading(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().StartHeading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndHeading(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().EndHeading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StreetName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StreetName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapRouteManeuver3> : produce_base<D, llm::OS::Services::Maps::IMapRouteManeuver3>
    {
        int32_t __stdcall get_Warnings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::ManeuverWarning>>(this->shim().Warnings());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapServiceStatics> : produce_base<D, llm::OS::Services::Maps::IMapServiceStatics>
    {
        int32_t __stdcall put_ServiceToken(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceToken(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapServiceStatics2> : produce_base<D, llm::OS::Services::Maps::IMapServiceStatics2>
    {
        int32_t __stdcall get_WorldViewRegionCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().WorldViewRegionCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapServiceStatics3> : produce_base<D, llm::OS::Services::Maps::IMapServiceStatics3>
    {
        int32_t __stdcall get_DataAttributions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DataAttributions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IMapServiceStatics4> : produce_base<D, llm::OS::Services::Maps::IMapServiceStatics4>
    {
        int32_t __stdcall put_DataUsagePreference(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataUsagePreference(*reinterpret_cast<llm::OS::Services::Maps::MapServiceDataUsagePreference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataUsagePreference(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::MapServiceDataUsagePreference>(this->shim().DataUsagePreference());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IPlaceInfo> : produce_base<D, llm::OS::Services::Maps::IPlaceInfo>
    {
        int32_t __stdcall Show(llm::OS::Foundation::Rect selection) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowWithPreferredPlacement(llm::OS::Foundation::Rect selection, int32_t preferredPlacement) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&preferredPlacement));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Identifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Identifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Geoshape(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::IGeoshape>(this->shim().Geoshape());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IPlaceInfoCreateOptions> : produce_base<D, llm::OS::Services::Maps::IPlaceInfoCreateOptions>
    {
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayAddress(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayAddress(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IPlaceInfoStatics> : produce_base<D, llm::OS::Services::Maps::IPlaceInfoStatics>
    {
        int32_t __stdcall Create(void* referencePoint, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&referencePoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithGeopointAndOptions(void* referencePoint, void* options, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&referencePoint), *reinterpret_cast<llm::OS::Services::Maps::PlaceInfoCreateOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromIdentifier(void* identifier, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromIdentifier(*reinterpret_cast<hstring const*>(&identifier)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromIdentifierWithOptions(void* identifier, void* defaultPoint, void* options, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromIdentifier(*reinterpret_cast<hstring const*>(&identifier), *reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&defaultPoint), *reinterpret_cast<llm::OS::Services::Maps::PlaceInfoCreateOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromMapLocation(void* location, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromMapLocation(*reinterpret_cast<llm::OS::Services::Maps::MapLocation const*>(&location)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsShowSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsShowSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::IPlaceInfoStatics2> : produce_base<D, llm::OS::Services::Maps::IPlaceInfoStatics2>
    {
        int32_t __stdcall CreateFromAddress(void* displayAddress, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromAddress(*reinterpret_cast<hstring const*>(&displayAddress)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromAddressWithName(void* displayAddress, void* displayName, void** resultValue) noexcept final try
        {
            clear_abi(resultValue);
            typename D::abi_guard guard(this->shim());
            *resultValue = detach_from<llm::OS::Services::Maps::PlaceInfo>(this->shim().CreateFromAddress(*reinterpret_cast<hstring const*>(&displayAddress), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Services::Maps
{
    constexpr auto operator|(MapManeuverNotices const left, MapManeuverNotices const right) noexcept
    {
        return static_cast<MapManeuverNotices>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(MapManeuverNotices& left, MapManeuverNotices const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(MapManeuverNotices const left, MapManeuverNotices const right) noexcept
    {
        return static_cast<MapManeuverNotices>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(MapManeuverNotices& left, MapManeuverNotices const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(MapManeuverNotices const value) noexcept
    {
        return static_cast<MapManeuverNotices>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(MapManeuverNotices const left, MapManeuverNotices const right) noexcept
    {
        return static_cast<MapManeuverNotices>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(MapManeuverNotices& left, MapManeuverNotices const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(MapRouteRestrictions const left, MapRouteRestrictions const right) noexcept
    {
        return static_cast<MapRouteRestrictions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(MapRouteRestrictions& left, MapRouteRestrictions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(MapRouteRestrictions const left, MapRouteRestrictions const right) noexcept
    {
        return static_cast<MapRouteRestrictions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(MapRouteRestrictions& left, MapRouteRestrictions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(MapRouteRestrictions const value) noexcept
    {
        return static_cast<MapRouteRestrictions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(MapRouteRestrictions const left, MapRouteRestrictions const right) noexcept
    {
        return static_cast<MapRouteRestrictions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(MapRouteRestrictions& left, MapRouteRestrictions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline EnhancedWaypoint::EnhancedWaypoint(llm::OS::Devices::Geolocation::Geopoint const& point, llm::OS::Services::Maps::WaypointKind const& kind) :
        EnhancedWaypoint(impl::call_factory<EnhancedWaypoint, IEnhancedWaypointFactory>([&](IEnhancedWaypointFactory const& f) { return f.Create(point, kind); }))
    {
    }
    inline auto MapLocationFinder::FindLocationsAtAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint)
    {
        return impl::call_factory<MapLocationFinder, IMapLocationFinderStatics>([&](IMapLocationFinderStatics const& f) { return f.FindLocationsAtAsync(queryPoint); });
    }
    inline auto MapLocationFinder::FindLocationsAsync(param::hstring const& searchText, llm::OS::Devices::Geolocation::Geopoint const& referencePoint)
    {
        return impl::call_factory<MapLocationFinder, IMapLocationFinderStatics>([&](IMapLocationFinderStatics const& f) { return f.FindLocationsAsync(searchText, referencePoint); });
    }
    inline auto MapLocationFinder::FindLocationsAsync(param::hstring const& searchText, llm::OS::Devices::Geolocation::Geopoint const& referencePoint, uint32_t maxCount)
    {
        return impl::call_factory<MapLocationFinder, IMapLocationFinderStatics>([&](IMapLocationFinderStatics const& f) { return f.FindLocationsAsync(searchText, referencePoint, maxCount); });
    }
    inline auto MapLocationFinder::FindLocationsAtAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint, llm::OS::Services::Maps::MapLocationDesiredAccuracy const& accuracy)
    {
        return impl::call_factory<MapLocationFinder, IMapLocationFinderStatics2>([&](IMapLocationFinderStatics2 const& f) { return f.FindLocationsAtAsync(queryPoint, accuracy); });
    }
    inline auto MapManager::ShowDownloadedMapsUI()
    {
        impl::call_factory_cast<void(*)(IMapManagerStatics const&), MapManager, IMapManagerStatics>([](IMapManagerStatics const& f) { return f.ShowDownloadedMapsUI(); });
    }
    inline auto MapManager::ShowMapsUpdateUI()
    {
        impl::call_factory_cast<void(*)(IMapManagerStatics const&), MapManager, IMapManagerStatics>([](IMapManagerStatics const& f) { return f.ShowMapsUpdateUI(); });
    }
    inline MapRouteDrivingOptions::MapRouteDrivingOptions() :
        MapRouteDrivingOptions(impl::call_factory_cast<MapRouteDrivingOptions(*)(llm::OS::Foundation::IActivationFactory const&), MapRouteDrivingOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MapRouteDrivingOptions>(); }))
    {
    }
    inline auto MapRouteFinder::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteAsync(startPoint, endPoint); });
    }
    inline auto MapRouteFinder::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteAsync(startPoint, endPoint, optimization); });
    }
    inline auto MapRouteFinder::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteAsync(startPoint, endPoint, optimization, restrictions); });
    }
    inline auto MapRouteFinder::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteAsync(startPoint, endPoint, optimization, restrictions, headingInDegrees); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteFromWaypointsAsync(wayPoints); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteFromWaypointsAsync(wayPoints, optimization); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteFromWaypointsAsync(wayPoints, optimization, restrictions); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints, llm::OS::Services::Maps::MapRouteOptimization const& optimization, llm::OS::Services::Maps::MapRouteRestrictions const& restrictions, double headingInDegrees)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetDrivingRouteFromWaypointsAsync(wayPoints, optimization, restrictions, headingInDegrees); });
    }
    inline auto MapRouteFinder::GetWalkingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetWalkingRouteAsync(startPoint, endPoint); });
    }
    inline auto MapRouteFinder::GetWalkingRouteFromWaypointsAsync(param::async_iterable<llm::OS::Devices::Geolocation::Geopoint> const& wayPoints)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics>([&](IMapRouteFinderStatics const& f) { return f.GetWalkingRouteFromWaypointsAsync(wayPoints); });
    }
    inline auto MapRouteFinder::GetDrivingRouteAsync(llm::OS::Devices::Geolocation::Geopoint const& startPoint, llm::OS::Devices::Geolocation::Geopoint const& endPoint, llm::OS::Services::Maps::MapRouteDrivingOptions const& options)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics2>([&](IMapRouteFinderStatics2 const& f) { return f.GetDrivingRouteAsync(startPoint, endPoint, options); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm::OS::Services::Maps::EnhancedWaypoint> const& waypoints)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics3>([&](IMapRouteFinderStatics3 const& f) { return f.GetDrivingRouteFromEnhancedWaypointsAsync(waypoints); });
    }
    inline auto MapRouteFinder::GetDrivingRouteFromEnhancedWaypointsAsync(param::async_iterable<llm::OS::Services::Maps::EnhancedWaypoint> const& waypoints, llm::OS::Services::Maps::MapRouteDrivingOptions const& options)
    {
        return impl::call_factory<MapRouteFinder, IMapRouteFinderStatics3>([&](IMapRouteFinderStatics3 const& f) { return f.GetDrivingRouteFromEnhancedWaypointsAsync(waypoints, options); });
    }
    inline auto MapService::ServiceToken(param::hstring const& value)
    {
        impl::call_factory<MapService, IMapServiceStatics>([&](IMapServiceStatics const& f) { return f.ServiceToken(value); });
    }
    inline auto MapService::ServiceToken()
    {
        return impl::call_factory_cast<hstring(*)(IMapServiceStatics const&), MapService, IMapServiceStatics>([](IMapServiceStatics const& f) { return f.ServiceToken(); });
    }
    inline auto MapService::WorldViewRegionCode()
    {
        return impl::call_factory_cast<hstring(*)(IMapServiceStatics2 const&), MapService, IMapServiceStatics2>([](IMapServiceStatics2 const& f) { return f.WorldViewRegionCode(); });
    }
    inline auto MapService::DataAttributions()
    {
        return impl::call_factory_cast<hstring(*)(IMapServiceStatics3 const&), MapService, IMapServiceStatics3>([](IMapServiceStatics3 const& f) { return f.DataAttributions(); });
    }
    inline auto MapService::DataUsagePreference(llm::OS::Services::Maps::MapServiceDataUsagePreference const& value)
    {
        impl::call_factory<MapService, IMapServiceStatics4>([&](IMapServiceStatics4 const& f) { return f.DataUsagePreference(value); });
    }
    inline auto MapService::DataUsagePreference()
    {
        return impl::call_factory_cast<llm::OS::Services::Maps::MapServiceDataUsagePreference(*)(IMapServiceStatics4 const&), MapService, IMapServiceStatics4>([](IMapServiceStatics4 const& f) { return f.DataUsagePreference(); });
    }
    inline auto PlaceInfo::Create(llm::OS::Devices::Geolocation::Geopoint const& referencePoint)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics>([&](IPlaceInfoStatics const& f) { return f.Create(referencePoint); });
    }
    inline auto PlaceInfo::Create(llm::OS::Devices::Geolocation::Geopoint const& referencePoint, llm::OS::Services::Maps::PlaceInfoCreateOptions const& options)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics>([&](IPlaceInfoStatics const& f) { return f.Create(referencePoint, options); });
    }
    inline auto PlaceInfo::CreateFromIdentifier(param::hstring const& identifier)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics>([&](IPlaceInfoStatics const& f) { return f.CreateFromIdentifier(identifier); });
    }
    inline auto PlaceInfo::CreateFromIdentifier(param::hstring const& identifier, llm::OS::Devices::Geolocation::Geopoint const& defaultPoint, llm::OS::Services::Maps::PlaceInfoCreateOptions const& options)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics>([&](IPlaceInfoStatics const& f) { return f.CreateFromIdentifier(identifier, defaultPoint, options); });
    }
    inline auto PlaceInfo::CreateFromMapLocation(llm::OS::Services::Maps::MapLocation const& location)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics>([&](IPlaceInfoStatics const& f) { return f.CreateFromMapLocation(location); });
    }
    inline auto PlaceInfo::IsShowSupported()
    {
        return impl::call_factory_cast<bool(*)(IPlaceInfoStatics const&), PlaceInfo, IPlaceInfoStatics>([](IPlaceInfoStatics const& f) { return f.IsShowSupported(); });
    }
    inline auto PlaceInfo::CreateFromAddress(param::hstring const& displayAddress)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics2>([&](IPlaceInfoStatics2 const& f) { return f.CreateFromAddress(displayAddress); });
    }
    inline auto PlaceInfo::CreateFromAddress(param::hstring const& displayAddress, param::hstring const& displayName)
    {
        return impl::call_factory<PlaceInfo, IPlaceInfoStatics2>([&](IPlaceInfoStatics2 const& f) { return f.CreateFromAddress(displayAddress, displayName); });
    }
    inline PlaceInfoCreateOptions::PlaceInfoCreateOptions() :
        PlaceInfoCreateOptions(impl::call_factory_cast<PlaceInfoCreateOptions(*)(llm::OS::Foundation::IActivationFactory const&), PlaceInfoCreateOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PlaceInfoCreateOptions>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Services::Maps::IEnhancedWaypoint> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IEnhancedWaypointFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IManeuverWarning> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapAddress2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapLocationFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapLocationFinderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapLocationFinderStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRoute> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRoute2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRoute3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRoute4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteDrivingOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteDrivingOptions2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteFinderResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteFinderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteFinderStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteFinderStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteLeg> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteLeg2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteManeuver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteManeuver2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapRouteManeuver3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapServiceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapServiceStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapServiceStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IMapServiceStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IPlaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IPlaceInfoCreateOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IPlaceInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::IPlaceInfoStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::EnhancedWaypoint> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::ManeuverWarning> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapLocationFinder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapLocationFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRoute> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRouteDrivingOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRouteFinder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRouteFinderResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRouteLeg> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapRouteManeuver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::MapService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::PlaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::PlaceInfoCreateOptions> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
