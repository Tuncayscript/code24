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
#ifndef LLM_OS_Devices_Geolocation_1_H
#define LLM_OS_Devices_Geolocation_1_H
#include "llm/impl/Windows.Devices.Geolocation.0.h"
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    struct __declspec(empty_bases) ICivicAddress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICivicAddress>
    {
        ICivicAddress(std::nullptr_t = nullptr) noexcept {}
        ICivicAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoboundingBox :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoboundingBox>,
        impl::require<llm::OS::Devices::Geolocation::IGeoboundingBox, llm::OS::Devices::Geolocation::IGeoshape>
    {
        IGeoboundingBox(std::nullptr_t = nullptr) noexcept {}
        IGeoboundingBox(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoboundingBoxFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoboundingBoxFactory>
    {
        IGeoboundingBoxFactory(std::nullptr_t = nullptr) noexcept {}
        IGeoboundingBoxFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoboundingBoxStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoboundingBoxStatics>
    {
        IGeoboundingBoxStatics(std::nullptr_t = nullptr) noexcept {}
        IGeoboundingBoxStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocircle :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocircle>,
        impl::require<llm::OS::Devices::Geolocation::IGeocircle, llm::OS::Devices::Geolocation::IGeoshape>
    {
        IGeocircle(std::nullptr_t = nullptr) noexcept {}
        IGeocircle(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocircleFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocircleFactory>
    {
        IGeocircleFactory(std::nullptr_t = nullptr) noexcept {}
        IGeocircleFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinate :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinate>
    {
        IGeocoordinate(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateSatelliteData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateSatelliteData>
    {
        IGeocoordinateSatelliteData(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateSatelliteData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateSatelliteData2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateSatelliteData2>
    {
        IGeocoordinateSatelliteData2(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateSatelliteData2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateWithPoint :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateWithPoint>
    {
        IGeocoordinateWithPoint(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateWithPoint(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateWithPositionData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateWithPositionData>,
        impl::require<llm::OS::Devices::Geolocation::IGeocoordinateWithPositionData, llm::OS::Devices::Geolocation::IGeocoordinate>
    {
        IGeocoordinateWithPositionData(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateWithPositionData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateWithPositionSourceTimestamp :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateWithPositionSourceTimestamp>
    {
        IGeocoordinateWithPositionSourceTimestamp(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateWithPositionSourceTimestamp(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeocoordinateWithRemoteSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeocoordinateWithRemoteSource>
    {
        IGeocoordinateWithRemoteSource(std::nullptr_t = nullptr) noexcept {}
        IGeocoordinateWithRemoteSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeolocator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeolocator>
    {
        IGeolocator(std::nullptr_t = nullptr) noexcept {}
        IGeolocator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeolocator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeolocator2>
    {
        IGeolocator2(std::nullptr_t = nullptr) noexcept {}
        IGeolocator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeolocatorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeolocatorStatics>
    {
        IGeolocatorStatics(std::nullptr_t = nullptr) noexcept {}
        IGeolocatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeolocatorStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeolocatorStatics2>
    {
        IGeolocatorStatics2(std::nullptr_t = nullptr) noexcept {}
        IGeolocatorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeolocatorWithScalarAccuracy :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeolocatorWithScalarAccuracy>,
        impl::require<llm::OS::Devices::Geolocation::IGeolocatorWithScalarAccuracy, llm::OS::Devices::Geolocation::IGeolocator>
    {
        IGeolocatorWithScalarAccuracy(std::nullptr_t = nullptr) noexcept {}
        IGeolocatorWithScalarAccuracy(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeopath :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeopath>,
        impl::require<llm::OS::Devices::Geolocation::IGeopath, llm::OS::Devices::Geolocation::IGeoshape>
    {
        IGeopath(std::nullptr_t = nullptr) noexcept {}
        IGeopath(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeopathFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeopathFactory>
    {
        IGeopathFactory(std::nullptr_t = nullptr) noexcept {}
        IGeopathFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeopoint :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeopoint>,
        impl::require<llm::OS::Devices::Geolocation::IGeopoint, llm::OS::Devices::Geolocation::IGeoshape>
    {
        IGeopoint(std::nullptr_t = nullptr) noexcept {}
        IGeopoint(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeopointFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeopointFactory>
    {
        IGeopointFactory(std::nullptr_t = nullptr) noexcept {}
        IGeopointFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoposition :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoposition>
    {
        IGeoposition(std::nullptr_t = nullptr) noexcept {}
        IGeoposition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoposition2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoposition2>,
        impl::require<llm::OS::Devices::Geolocation::IGeoposition2, llm::OS::Devices::Geolocation::IGeoposition>
    {
        IGeoposition2(std::nullptr_t = nullptr) noexcept {}
        IGeoposition2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeoshape :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeoshape>
    {
        IGeoshape(std::nullptr_t = nullptr) noexcept {}
        IGeoshape(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisit>
    {
        IGeovisit(std::nullptr_t = nullptr) noexcept {}
        IGeovisit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisitMonitor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisitMonitor>
    {
        IGeovisitMonitor(std::nullptr_t = nullptr) noexcept {}
        IGeovisitMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisitMonitorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisitMonitorStatics>
    {
        IGeovisitMonitorStatics(std::nullptr_t = nullptr) noexcept {}
        IGeovisitMonitorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisitStateChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisitStateChangedEventArgs>
    {
        IGeovisitStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGeovisitStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisitTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisitTriggerDetails>
    {
        IGeovisitTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IGeovisitTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPositionChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPositionChangedEventArgs>
    {
        IPositionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPositionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStatusChangedEventArgs>
    {
        IStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVenueData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVenueData>
    {
        IVenueData(std::nullptr_t = nullptr) noexcept {}
        IVenueData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
