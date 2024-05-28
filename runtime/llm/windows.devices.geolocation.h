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
#ifndef LLM_OS_Devices_Geolocation_H
#define LLM_OS_Devices_Geolocation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_ICivicAddress<D>::Country() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::ICivicAddress)->get_Country(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_ICivicAddress<D>::State() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::ICivicAddress)->get_State(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_ICivicAddress<D>::City() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::ICivicAddress)->get_City(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_ICivicAddress<D>::PostalCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::ICivicAddress)->get_PostalCode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Geolocation_ICivicAddress<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::ICivicAddress)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) consume_Windows_Devices_Geolocation_IGeoboundingBox<D>::NorthwestCorner() const
    {
        llm::OS::Devices::Geolocation::BasicGeoposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBox)->get_NorthwestCorner(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) consume_Windows_Devices_Geolocation_IGeoboundingBox<D>::SoutheastCorner() const
    {
        llm::OS::Devices::Geolocation::BasicGeoposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBox)->get_SoutheastCorner(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) consume_Windows_Devices_Geolocation_IGeoboundingBox<D>::Center() const
    {
        llm::OS::Devices::Geolocation::BasicGeoposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBox)->get_Center(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeoboundingBox<D>::MinAltitude() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBox)->get_MinAltitude(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeoboundingBox<D>::MaxAltitude() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBox)->get_MaxAltitude(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxFactory<D>::Create(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxFactory)->Create(impl::bind_in(northwestCorner), impl::bind_in(southeastCorner), &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxFactory<D>::CreateWithAltitudeReference(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxFactory)->CreateWithAltitudeReference(impl::bind_in(northwestCorner), impl::bind_in(southeastCorner), static_cast<int32_t>(altitudeReferenceSystem), &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxFactory<D>::CreateWithAltitudeReferenceAndSpatialReference(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxFactory)->CreateWithAltitudeReferenceAndSpatialReference(impl::bind_in(northwestCorner), impl::bind_in(southeastCorner), static_cast<int32_t>(altitudeReferenceSystem), spatialReferenceId, &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxStatics<D>::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxStatics)->TryCompute(*(void**)(&positions), &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxStatics<D>::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxStatics)->TryComputeWithAltitudeReference(*(void**)(&positions), static_cast<int32_t>(altitudeRefSystem), &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoboundingBox) consume_Windows_Devices_Geolocation_IGeoboundingBoxStatics<D>::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem, uint32_t spatialReferenceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoboundingBoxStatics)->TryComputeWithAltitudeReferenceAndSpatialReference(*(void**)(&positions), static_cast<int32_t>(altitudeRefSystem), spatialReferenceId, &value));
        return llm::OS::Devices::Geolocation::GeoboundingBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) consume_Windows_Devices_Geolocation_IGeocircle<D>::Center() const
    {
        llm::OS::Devices::Geolocation::BasicGeoposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocircle)->get_Center(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeocircle<D>::Radius() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocircle)->get_Radius(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geocircle) consume_Windows_Devices_Geolocation_IGeocircleFactory<D>::Create(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocircleFactory)->Create(impl::bind_in(position), radius, &value));
        return llm::OS::Devices::Geolocation::Geocircle{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geocircle) consume_Windows_Devices_Geolocation_IGeocircleFactory<D>::CreateWithAltitudeReferenceSystem(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocircleFactory)->CreateWithAltitudeReferenceSystem(impl::bind_in(position), radius, static_cast<int32_t>(altitudeReferenceSystem), &value));
        return llm::OS::Devices::Geolocation::Geocircle{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geocircle) consume_Windows_Devices_Geolocation_IGeocircleFactory<D>::CreateWithAltitudeReferenceSystemAndSpatialReferenceId(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocircleFactory)->CreateWithAltitudeReferenceSystemAndSpatialReferenceId(impl::bind_in(position), radius, static_cast<int32_t>(altitudeReferenceSystem), spatialReferenceId, &value));
        return llm::OS::Devices::Geolocation::Geocircle{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Latitude() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Latitude(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Longitude() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Longitude(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Altitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Altitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Accuracy() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Accuracy(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::AltitudeAccuracy() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_AltitudeAccuracy(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Heading() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Heading(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Speed() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Speed(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Geolocation_IGeocoordinate<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinate)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinateSatelliteData<D>::PositionDilutionOfPrecision() const
    {
        void* ppValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData)->get_PositionDilutionOfPrecision(&ppValue));
        return llm::OS::Foundation::IReference<double>{ ppValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinateSatelliteData<D>::HorizontalDilutionOfPrecision() const
    {
        void* ppValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData)->get_HorizontalDilutionOfPrecision(&ppValue));
        return llm::OS::Foundation::IReference<double>{ ppValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinateSatelliteData<D>::VerticalDilutionOfPrecision() const
    {
        void* ppValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData)->get_VerticalDilutionOfPrecision(&ppValue));
        return llm::OS::Foundation::IReference<double>{ ppValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinateSatelliteData2<D>::GeometricDilutionOfPrecision() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2)->get_GeometricDilutionOfPrecision(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Devices_Geolocation_IGeocoordinateSatelliteData2<D>::TimeDilutionOfPrecision() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2)->get_TimeDilutionOfPrecision(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Devices_Geolocation_IGeocoordinateWithPoint<D>::Point() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateWithPoint)->get_Point(&value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::PositionSource) consume_Windows_Devices_Geolocation_IGeocoordinateWithPositionData<D>::PositionSource() const
    {
        llm::OS::Devices::Geolocation::PositionSource pValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData)->get_PositionSource(reinterpret_cast<int32_t*>(&pValue)));
        return pValue;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeocoordinateSatelliteData) consume_Windows_Devices_Geolocation_IGeocoordinateWithPositionData<D>::SatelliteData() const
    {
        void* ppValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData)->get_SatelliteData(&ppValue));
        return llm::OS::Devices::Geolocation::GeocoordinateSatelliteData{ ppValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Devices_Geolocation_IGeocoordinateWithPositionSourceTimestamp<D>::PositionSourceTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp)->get_PositionSourceTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Geolocation_IGeocoordinateWithRemoteSource<D>::IsRemoteSource() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeocoordinateWithRemoteSource)->get_IsRemoteSource(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::PositionAccuracy) consume_Windows_Devices_Geolocation_IGeolocator<D>::DesiredAccuracy() const
    {
        llm::OS::Devices::Geolocation::PositionAccuracy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->get_DesiredAccuracy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator<D>::DesiredAccuracy(llm::OS::Devices::Geolocation::PositionAccuracy const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->put_DesiredAccuracy(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Geolocation_IGeolocator<D>::MovementThreshold() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->get_MovementThreshold(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator<D>::MovementThreshold(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->put_MovementThreshold(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Geolocation_IGeolocator<D>::ReportInterval() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->get_ReportInterval(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator<D>::ReportInterval(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->put_ReportInterval(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::PositionStatus) consume_Windows_Devices_Geolocation_IGeolocator<D>::LocationStatus() const
    {
        llm::OS::Devices::Geolocation::PositionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->get_LocationStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>) consume_Windows_Devices_Geolocation_IGeolocator<D>::GetGeopositionAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->GetGeopositionAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>) consume_Windows_Devices_Geolocation_IGeolocator<D>::GetGeopositionAsync(llm::OS::Foundation::TimeSpan const& maximumAge, llm::OS::Foundation::TimeSpan const& timeout) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->GetGeopositionAsyncWithAgeAndTimeout(impl::bind_in(maximumAge), impl::bind_in(timeout), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Geolocation_IGeolocator<D>::PositionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::PositionChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->add_PositionChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Geolocation_IGeolocator<D>::PositionChanged_revoker consume_Windows_Devices_Geolocation_IGeolocator<D>::PositionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::PositionChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PositionChanged_revoker>(this, PositionChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator<D>::PositionChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->remove_PositionChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Geolocation_IGeolocator<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::StatusChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->add_StatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Geolocation_IGeolocator<D>::StatusChanged_revoker consume_Windows_Devices_Geolocation_IGeolocator<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::StatusChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocator2<D>::AllowFallbackToConsentlessPositions() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocator2)->AllowFallbackToConsentlessPositions());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::GeolocationAccessStatus>) consume_Windows_Devices_Geolocation_IGeolocatorStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::GeolocationAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>) consume_Windows_Devices_Geolocation_IGeolocatorStatics<D>::GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics)->GetGeopositionHistoryAsync(impl::bind_in(startTime), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>) consume_Windows_Devices_Geolocation_IGeolocatorStatics<D>::GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics)->GetGeopositionHistoryWithDurationAsync(impl::bind_in(startTime), impl::bind_in(duration), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Geolocation_IGeolocatorStatics2<D>::IsDefaultGeopositionRecommended() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics2)->get_IsDefaultGeopositionRecommended(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocatorStatics2<D>::DefaultGeoposition(llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics2)->put_DefaultGeoposition(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition>) consume_Windows_Devices_Geolocation_IGeolocatorStatics2<D>::DefaultGeoposition() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorStatics2)->get_DefaultGeoposition(&value));
        return llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Devices_Geolocation_IGeolocatorWithScalarAccuracy<D>::DesiredAccuracyInMeters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy)->get_DesiredAccuracyInMeters(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeolocatorWithScalarAccuracy<D>::DesiredAccuracyInMeters(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy)->put_DesiredAccuracyInMeters(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::BasicGeoposition>) consume_Windows_Devices_Geolocation_IGeopath<D>::Positions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopath)->get_Positions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::BasicGeoposition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopath) consume_Windows_Devices_Geolocation_IGeopathFactory<D>::Create(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopathFactory)->Create(*(void**)(&positions), &value));
        return llm::OS::Devices::Geolocation::Geopath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopath) consume_Windows_Devices_Geolocation_IGeopathFactory<D>::CreateWithAltitudeReference(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopathFactory)->CreateWithAltitudeReference(*(void**)(&positions), static_cast<int32_t>(altitudeReferenceSystem), &value));
        return llm::OS::Devices::Geolocation::Geopath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopath) consume_Windows_Devices_Geolocation_IGeopathFactory<D>::CreateWithAltitudeReferenceAndSpatialReference(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopathFactory)->CreateWithAltitudeReferenceAndSpatialReference(*(void**)(&positions), static_cast<int32_t>(altitudeReferenceSystem), spatialReferenceId, &value));
        return llm::OS::Devices::Geolocation::Geopath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) consume_Windows_Devices_Geolocation_IGeopoint<D>::Position() const
    {
        llm::OS::Devices::Geolocation::BasicGeoposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopoint)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Devices_Geolocation_IGeopointFactory<D>::Create(llm::OS::Devices::Geolocation::BasicGeoposition const& position) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopointFactory)->Create(impl::bind_in(position), &value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Devices_Geolocation_IGeopointFactory<D>::CreateWithAltitudeReferenceSystem(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopointFactory)->CreateWithAltitudeReferenceSystem(impl::bind_in(position), static_cast<int32_t>(altitudeReferenceSystem), &value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geopoint) consume_Windows_Devices_Geolocation_IGeopointFactory<D>::CreateWithAltitudeReferenceSystemAndSpatialReferenceId(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeopointFactory)->CreateWithAltitudeReferenceSystemAndSpatialReferenceId(impl::bind_in(position), static_cast<int32_t>(altitudeReferenceSystem), spatialReferenceId, &value));
        return llm::OS::Devices::Geolocation::Geopoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geocoordinate) consume_Windows_Devices_Geolocation_IGeoposition<D>::Coordinate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoposition)->get_Coordinate(&value));
        return llm::OS::Devices::Geolocation::Geocoordinate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::CivicAddress) consume_Windows_Devices_Geolocation_IGeoposition<D>::CivicAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoposition)->get_CivicAddress(&value));
        return llm::OS::Devices::Geolocation::CivicAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::VenueData) consume_Windows_Devices_Geolocation_IGeoposition2<D>::VenueData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoposition2)->get_VenueData(&value));
        return llm::OS::Devices::Geolocation::VenueData{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::GeoshapeType) consume_Windows_Devices_Geolocation_IGeoshape<D>::GeoshapeType() const
    {
        llm::OS::Devices::Geolocation::GeoshapeType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoshape)->get_GeoshapeType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Geolocation_IGeoshape<D>::SpatialReferenceId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoshape)->get_SpatialReferenceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::AltitudeReferenceSystem) consume_Windows_Devices_Geolocation_IGeoshape<D>::AltitudeReferenceSystem() const
    {
        llm::OS::Devices::Geolocation::AltitudeReferenceSystem value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeoshape)->get_AltitudeReferenceSystem(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geoposition) consume_Windows_Devices_Geolocation_IGeovisit<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisit)->get_Position(&value));
        return llm::OS::Devices::Geolocation::Geoposition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::VisitStateChange) consume_Windows_Devices_Geolocation_IGeovisit<D>::StateChange() const
    {
        llm::OS::Devices::Geolocation::VisitStateChange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisit)->get_StateChange(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Geolocation_IGeovisit<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisit)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::VisitMonitoringScope) consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::MonitoringScope() const
    {
        llm::OS::Devices::Geolocation::VisitMonitoringScope value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitor)->get_MonitoringScope(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::Start(llm::OS::Devices::Geolocation::VisitMonitoringScope const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitor)->Start(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitor)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::VisitStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::GeovisitMonitor, llm::OS::Devices::Geolocation::GeovisitStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitor)->add_VisitStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::VisitStateChanged_revoker consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::VisitStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::GeovisitMonitor, llm::OS::Devices::Geolocation::GeovisitStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, VisitStateChanged_revoker>(this, VisitStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Geolocation_IGeovisitMonitor<D>::VisitStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitor)->remove_VisitStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geovisit>) consume_Windows_Devices_Geolocation_IGeovisitMonitorStatics<D>::GetLastReportAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitMonitorStatics)->GetLastReportAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geovisit>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geovisit) consume_Windows_Devices_Geolocation_IGeovisitStateChangedEventArgs<D>::Visit() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs)->get_Visit(&value));
        return llm::OS::Devices::Geolocation::Geovisit{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geovisit>) consume_Windows_Devices_Geolocation_IGeovisitTriggerDetails<D>::ReadReports() const
    {
        void* values{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IGeovisitTriggerDetails)->ReadReports(&values));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geovisit>{ values, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::Geoposition) consume_Windows_Devices_Geolocation_IPositionChangedEventArgs<D>::Position() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IPositionChangedEventArgs)->get_Position(&value));
        return llm::OS::Devices::Geolocation::Geoposition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::PositionStatus) consume_Windows_Devices_Geolocation_IStatusChangedEventArgs<D>::Status() const
    {
        llm::OS::Devices::Geolocation::PositionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IStatusChangedEventArgs)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_IVenueData<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IVenueData)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Geolocation_IVenueData<D>::Level() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Geolocation::IVenueData)->get_Level(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::ICivicAddress> : produce_base<D, llm::OS::Devices::Geolocation::ICivicAddress>
    {
        int32_t __stdcall get_Country(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Country());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_City(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().City());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PostalCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PostalCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoboundingBox> : produce_base<D, llm::OS::Devices::Geolocation::IGeoboundingBox>
    {
        int32_t __stdcall get_NorthwestCorner(struct struct_Windows_Devices_Geolocation_BasicGeoposition* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Geolocation::BasicGeoposition>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::BasicGeoposition>(this->shim().NorthwestCorner());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SoutheastCorner(struct struct_Windows_Devices_Geolocation_BasicGeoposition* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Geolocation::BasicGeoposition>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::BasicGeoposition>(this->shim().SoutheastCorner());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Center(struct struct_Windows_Devices_Geolocation_BasicGeoposition* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Geolocation::BasicGeoposition>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::BasicGeoposition>(this->shim().Center());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinAltitude(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MinAltitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAltitude(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MaxAltitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoboundingBoxFactory> : produce_base<D, llm::OS::Devices::Geolocation::IGeoboundingBoxFactory>
    {
        int32_t __stdcall Create(struct struct_Windows_Devices_Geolocation_BasicGeoposition northwestCorner, struct struct_Windows_Devices_Geolocation_BasicGeoposition southeastCorner, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&northwestCorner), *reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&southeastCorner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReference(struct struct_Windows_Devices_Geolocation_BasicGeoposition northwestCorner, struct struct_Windows_Devices_Geolocation_BasicGeoposition southeastCorner, int32_t altitudeReferenceSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().CreateWithAltitudeReference(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&northwestCorner), *reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&southeastCorner), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceAndSpatialReference(struct struct_Windows_Devices_Geolocation_BasicGeoposition northwestCorner, struct struct_Windows_Devices_Geolocation_BasicGeoposition southeastCorner, int32_t altitudeReferenceSystem, uint32_t spatialReferenceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().CreateWithAltitudeReferenceAndSpatialReference(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&northwestCorner), *reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&southeastCorner), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem), spatialReferenceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoboundingBoxStatics> : produce_base<D, llm::OS::Devices::Geolocation::IGeoboundingBoxStatics>
    {
        int32_t __stdcall TryCompute(void* positions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().TryCompute(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryComputeWithAltitudeReference(void* positions, int32_t altitudeRefSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().TryCompute(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeRefSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryComputeWithAltitudeReferenceAndSpatialReference(void* positions, int32_t altitudeRefSystem, uint32_t spatialReferenceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoboundingBox>(this->shim().TryCompute(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeRefSystem), spatialReferenceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocircle> : produce_base<D, llm::OS::Devices::Geolocation::IGeocircle>
    {
        int32_t __stdcall get_Center(struct struct_Windows_Devices_Geolocation_BasicGeoposition* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Geolocation::BasicGeoposition>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::BasicGeoposition>(this->shim().Center());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Radius(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Radius());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocircleFactory> : produce_base<D, llm::OS::Devices::Geolocation::IGeocircleFactory>
    {
        int32_t __stdcall Create(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, double radius, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geocircle>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position), radius));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceSystem(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, double radius, int32_t altitudeReferenceSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geocircle>(this->shim().CreateWithAltitudeReferenceSystem(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position), radius, *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceSystemAndSpatialReferenceId(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, double radius, int32_t altitudeReferenceSystem, uint32_t spatialReferenceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geocircle>(this->shim().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position), radius, *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem), spatialReferenceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinate> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinate>
    {
        int32_t __stdcall get_Latitude(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Latitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Longitude(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Longitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Altitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Altitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Accuracy(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Accuracy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AltitudeAccuracy(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().AltitudeAccuracy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Heading(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Heading());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Speed(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().Speed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData>
    {
        int32_t __stdcall get_PositionDilutionOfPrecision(void** ppValue) noexcept final try
        {
            clear_abi(ppValue);
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().PositionDilutionOfPrecision());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HorizontalDilutionOfPrecision(void** ppValue) noexcept final try
        {
            clear_abi(ppValue);
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().HorizontalDilutionOfPrecision());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VerticalDilutionOfPrecision(void** ppValue) noexcept final try
        {
            clear_abi(ppValue);
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().VerticalDilutionOfPrecision());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2>
    {
        int32_t __stdcall get_GeometricDilutionOfPrecision(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().GeometricDilutionOfPrecision());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeDilutionOfPrecision(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().TimeDilutionOfPrecision());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPoint> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPoint>
    {
        int32_t __stdcall get_Point(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().Point());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData>
    {
        int32_t __stdcall get_PositionSource(int32_t* pValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pValue = detach_from<llm::OS::Devices::Geolocation::PositionSource>(this->shim().PositionSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SatelliteData(void** ppValue) noexcept final try
        {
            clear_abi(ppValue);
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_from<llm::OS::Devices::Geolocation::GeocoordinateSatelliteData>(this->shim().SatelliteData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>
    {
        int32_t __stdcall get_PositionSourceTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().PositionSourceTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeocoordinateWithRemoteSource> : produce_base<D, llm::OS::Devices::Geolocation::IGeocoordinateWithRemoteSource>
    {
        int32_t __stdcall get_IsRemoteSource(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRemoteSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeolocator> : produce_base<D, llm::OS::Devices::Geolocation::IGeolocator>
    {
        int32_t __stdcall get_DesiredAccuracy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::PositionAccuracy>(this->shim().DesiredAccuracy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredAccuracy(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredAccuracy(*reinterpret_cast<llm::OS::Devices::Geolocation::PositionAccuracy const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MovementThreshold(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MovementThreshold());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MovementThreshold(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MovementThreshold(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReportInterval(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ReportInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReportInterval(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportInterval(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocationStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::PositionStatus>(this->shim().LocationStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGeopositionAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>>(this->shim().GetGeopositionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGeopositionAsyncWithAgeAndTimeout(int64_t maximumAge, int64_t timeout, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geoposition>>(this->shim().GetGeopositionAsync(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&maximumAge), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeout)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PositionChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PositionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::PositionChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PositionChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_StatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::Geolocator, llm::OS::Devices::Geolocation::StatusChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeolocator2> : produce_base<D, llm::OS::Devices::Geolocation::IGeolocator2>
    {
        int32_t __stdcall AllowFallbackToConsentlessPositions() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowFallbackToConsentlessPositions();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeolocatorStatics> : produce_base<D, llm::OS::Devices::Geolocation::IGeolocatorStatics>
    {
        int32_t __stdcall RequestAccessAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::GeolocationAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGeopositionHistoryAsync(int64_t startTime, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>>(this->shim().GetGeopositionHistoryAsync(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&startTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGeopositionHistoryWithDurationAsync(int64_t startTime, int64_t duration, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geoposition>>>(this->shim().GetGeopositionHistoryAsync(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&startTime), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&duration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeolocatorStatics2> : produce_base<D, llm::OS::Devices::Geolocation::IGeolocatorStatics2>
    {
        int32_t __stdcall get_IsDefaultGeopositionRecommended(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDefaultGeopositionRecommended());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultGeoposition(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultGeoposition(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultGeoposition(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition>>(this->shim().DefaultGeoposition());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy> : produce_base<D, llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy>
    {
        int32_t __stdcall get_DesiredAccuracyInMeters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().DesiredAccuracyInMeters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredAccuracyInMeters(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredAccuracyInMeters(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeopath> : produce_base<D, llm::OS::Devices::Geolocation::IGeopath>
    {
        int32_t __stdcall get_Positions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::BasicGeoposition>>(this->shim().Positions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeopathFactory> : produce_base<D, llm::OS::Devices::Geolocation::IGeopathFactory>
    {
        int32_t __stdcall Create(void* positions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopath>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReference(void* positions, int32_t altitudeReferenceSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopath>(this->shim().CreateWithAltitudeReference(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceAndSpatialReference(void* positions, int32_t altitudeReferenceSystem, uint32_t spatialReferenceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopath>(this->shim().CreateWithAltitudeReferenceAndSpatialReference(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Geolocation::BasicGeoposition> const*>(&positions), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem), spatialReferenceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeopoint> : produce_base<D, llm::OS::Devices::Geolocation::IGeopoint>
    {
        int32_t __stdcall get_Position(struct struct_Windows_Devices_Geolocation_BasicGeoposition* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Geolocation::BasicGeoposition>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::BasicGeoposition>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeopointFactory> : produce_base<D, llm::OS::Devices::Geolocation::IGeopointFactory>
    {
        int32_t __stdcall Create(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceSystem(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, int32_t altitudeReferenceSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().CreateWithAltitudeReferenceSystem(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithAltitudeReferenceSystemAndSpatialReferenceId(struct struct_Windows_Devices_Geolocation_BasicGeoposition position, int32_t altitudeReferenceSystem, uint32_t spatialReferenceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geopoint>(this->shim().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*reinterpret_cast<llm::OS::Devices::Geolocation::BasicGeoposition const*>(&position), *reinterpret_cast<llm::OS::Devices::Geolocation::AltitudeReferenceSystem const*>(&altitudeReferenceSystem), spatialReferenceId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoposition> : produce_base<D, llm::OS::Devices::Geolocation::IGeoposition>
    {
        int32_t __stdcall get_Coordinate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geocoordinate>(this->shim().Coordinate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CivicAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::CivicAddress>(this->shim().CivicAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoposition2> : produce_base<D, llm::OS::Devices::Geolocation::IGeoposition2>
    {
        int32_t __stdcall get_VenueData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::VenueData>(this->shim().VenueData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeoshape> : produce_base<D, llm::OS::Devices::Geolocation::IGeoshape>
    {
        int32_t __stdcall get_GeoshapeType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::GeoshapeType>(this->shim().GeoshapeType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpatialReferenceId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SpatialReferenceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AltitudeReferenceSystem(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::AltitudeReferenceSystem>(this->shim().AltitudeReferenceSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeovisit> : produce_base<D, llm::OS::Devices::Geolocation::IGeovisit>
    {
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geoposition>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StateChange(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::VisitStateChange>(this->shim().StateChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeovisitMonitor> : produce_base<D, llm::OS::Devices::Geolocation::IGeovisitMonitor>
    {
        int32_t __stdcall get_MonitoringScope(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::VisitMonitoringScope>(this->shim().MonitoringScope());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<llm::OS::Devices::Geolocation::VisitMonitoringScope const*>(&value));
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
        int32_t __stdcall add_VisitStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VisitStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Geolocation::GeovisitMonitor, llm::OS::Devices::Geolocation::GeovisitStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisitStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisitStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeovisitMonitorStatics> : produce_base<D, llm::OS::Devices::Geolocation::IGeovisitMonitorStatics>
    {
        int32_t __stdcall GetLastReportAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geovisit>>(this->shim().GetLastReportAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs> : produce_base<D, llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs>
    {
        int32_t __stdcall get_Visit(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geovisit>(this->shim().Visit());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IGeovisitTriggerDetails> : produce_base<D, llm::OS::Devices::Geolocation::IGeovisitTriggerDetails>
    {
        int32_t __stdcall ReadReports(void** values) noexcept final try
        {
            clear_abi(values);
            typename D::abi_guard guard(this->shim());
            *values = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Geolocation::Geovisit>>(this->shim().ReadReports());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IPositionChangedEventArgs> : produce_base<D, llm::OS::Devices::Geolocation::IPositionChangedEventArgs>
    {
        int32_t __stdcall get_Position(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::Geoposition>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IStatusChangedEventArgs> : produce_base<D, llm::OS::Devices::Geolocation::IStatusChangedEventArgs>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::PositionStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Geolocation::IVenueData> : produce_base<D, llm::OS::Devices::Geolocation::IVenueData>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Level(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Level());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    inline GeoboundingBox::GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner) :
        GeoboundingBox(impl::call_factory<GeoboundingBox, IGeoboundingBoxFactory>([&](IGeoboundingBoxFactory const& f) { return f.Create(northwestCorner, southeastCorner); }))
    {
    }
    inline GeoboundingBox::GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) :
        GeoboundingBox(impl::call_factory<GeoboundingBox, IGeoboundingBoxFactory>([&](IGeoboundingBoxFactory const& f) { return f.CreateWithAltitudeReference(northwestCorner, southeastCorner, altitudeReferenceSystem); }))
    {
    }
    inline GeoboundingBox::GeoboundingBox(llm::OS::Devices::Geolocation::BasicGeoposition const& northwestCorner, llm::OS::Devices::Geolocation::BasicGeoposition const& southeastCorner, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) :
        GeoboundingBox(impl::call_factory<GeoboundingBox, IGeoboundingBoxFactory>([&](IGeoboundingBoxFactory const& f) { return f.CreateWithAltitudeReferenceAndSpatialReference(northwestCorner, southeastCorner, altitudeReferenceSystem, spatialReferenceId); }))
    {
    }
    inline auto GeoboundingBox::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions)
    {
        return impl::call_factory<GeoboundingBox, IGeoboundingBoxStatics>([&](IGeoboundingBoxStatics const& f) { return f.TryCompute(positions); });
    }
    inline auto GeoboundingBox::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem)
    {
        return impl::call_factory<GeoboundingBox, IGeoboundingBoxStatics>([&](IGeoboundingBoxStatics const& f) { return f.TryCompute(positions, altitudeRefSystem); });
    }
    inline auto GeoboundingBox::TryCompute(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeRefSystem, uint32_t spatialReferenceId)
    {
        return impl::call_factory<GeoboundingBox, IGeoboundingBoxStatics>([&](IGeoboundingBoxStatics const& f) { return f.TryCompute(positions, altitudeRefSystem, spatialReferenceId); });
    }
    inline Geocircle::Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius) :
        Geocircle(impl::call_factory<Geocircle, IGeocircleFactory>([&](IGeocircleFactory const& f) { return f.Create(position, radius); }))
    {
    }
    inline Geocircle::Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) :
        Geocircle(impl::call_factory<Geocircle, IGeocircleFactory>([&](IGeocircleFactory const& f) { return f.CreateWithAltitudeReferenceSystem(position, radius, altitudeReferenceSystem); }))
    {
    }
    inline Geocircle::Geocircle(llm::OS::Devices::Geolocation::BasicGeoposition const& position, double radius, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) :
        Geocircle(impl::call_factory<Geocircle, IGeocircleFactory>([&](IGeocircleFactory const& f) { return f.CreateWithAltitudeReferenceSystemAndSpatialReferenceId(position, radius, altitudeReferenceSystem, spatialReferenceId); }))
    {
    }
    inline Geolocator::Geolocator() :
        Geolocator(impl::call_factory_cast<Geolocator(*)(llm::OS::Foundation::IActivationFactory const&), Geolocator>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Geolocator>(); }))
    {
    }
    inline auto Geolocator::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::GeolocationAccessStatus>(*)(IGeolocatorStatics const&), Geolocator, IGeolocatorStatics>([](IGeolocatorStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto Geolocator::GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime)
    {
        return impl::call_factory<Geolocator, IGeolocatorStatics>([&](IGeolocatorStatics const& f) { return f.GetGeopositionHistoryAsync(startTime); });
    }
    inline auto Geolocator::GetGeopositionHistoryAsync(llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration)
    {
        return impl::call_factory<Geolocator, IGeolocatorStatics>([&](IGeolocatorStatics const& f) { return f.GetGeopositionHistoryAsync(startTime, duration); });
    }
    inline auto Geolocator::IsDefaultGeopositionRecommended()
    {
        return impl::call_factory_cast<bool(*)(IGeolocatorStatics2 const&), Geolocator, IGeolocatorStatics2>([](IGeolocatorStatics2 const& f) { return f.IsDefaultGeopositionRecommended(); });
    }
    inline auto Geolocator::DefaultGeoposition(llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition> const& value)
    {
        impl::call_factory<Geolocator, IGeolocatorStatics2>([&](IGeolocatorStatics2 const& f) { return f.DefaultGeoposition(value); });
    }
    inline auto Geolocator::DefaultGeoposition()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IReference<llm::OS::Devices::Geolocation::BasicGeoposition>(*)(IGeolocatorStatics2 const&), Geolocator, IGeolocatorStatics2>([](IGeolocatorStatics2 const& f) { return f.DefaultGeoposition(); });
    }
    inline Geopath::Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions) :
        Geopath(impl::call_factory<Geopath, IGeopathFactory>([&](IGeopathFactory const& f) { return f.Create(positions); }))
    {
    }
    inline Geopath::Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) :
        Geopath(impl::call_factory<Geopath, IGeopathFactory>([&](IGeopathFactory const& f) { return f.CreateWithAltitudeReference(positions, altitudeReferenceSystem); }))
    {
    }
    inline Geopath::Geopath(param::iterable<llm::OS::Devices::Geolocation::BasicGeoposition> const& positions, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) :
        Geopath(impl::call_factory<Geopath, IGeopathFactory>([&](IGeopathFactory const& f) { return f.CreateWithAltitudeReferenceAndSpatialReference(positions, altitudeReferenceSystem, spatialReferenceId); }))
    {
    }
    inline Geopoint::Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position) :
        Geopoint(impl::call_factory<Geopoint, IGeopointFactory>([&](IGeopointFactory const& f) { return f.Create(position); }))
    {
    }
    inline Geopoint::Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem) :
        Geopoint(impl::call_factory<Geopoint, IGeopointFactory>([&](IGeopointFactory const& f) { return f.CreateWithAltitudeReferenceSystem(position, altitudeReferenceSystem); }))
    {
    }
    inline Geopoint::Geopoint(llm::OS::Devices::Geolocation::BasicGeoposition const& position, llm::OS::Devices::Geolocation::AltitudeReferenceSystem const& altitudeReferenceSystem, uint32_t spatialReferenceId) :
        Geopoint(impl::call_factory<Geopoint, IGeopointFactory>([&](IGeopointFactory const& f) { return f.CreateWithAltitudeReferenceSystemAndSpatialReferenceId(position, altitudeReferenceSystem, spatialReferenceId); }))
    {
    }
    inline GeovisitMonitor::GeovisitMonitor() :
        GeovisitMonitor(impl::call_factory_cast<GeovisitMonitor(*)(llm::OS::Foundation::IActivationFactory const&), GeovisitMonitor>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<GeovisitMonitor>(); }))
    {
    }
    inline auto GeovisitMonitor::GetLastReportAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Geolocation::Geovisit>(*)(IGeovisitMonitorStatics const&), GeovisitMonitor, IGeovisitMonitorStatics>([](IGeovisitMonitorStatics const& f) { return f.GetLastReportAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Geolocation::ICivicAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoboundingBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoboundingBoxFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoboundingBoxStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocircle> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocircleFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateSatelliteData2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateWithPoint> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeocoordinateWithRemoteSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeolocator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeolocator2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeolocatorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeolocatorStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeopath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeopathFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeopoint> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeopointFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoposition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoposition2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeoshape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeovisit> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeovisitMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeovisitMonitorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeovisitStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IGeovisitTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IPositionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::IVenueData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::CivicAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::GeoboundingBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geocircle> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geocoordinate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::GeocoordinateSatelliteData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geolocator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geopath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geopoint> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geoposition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::Geovisit> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::GeovisitMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::GeovisitStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::GeovisitTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::PositionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::StatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Geolocation::VenueData> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
