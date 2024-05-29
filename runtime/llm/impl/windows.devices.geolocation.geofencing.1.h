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
#ifndef LLM_OS_Devices_Geolocation_Geofencing_1_H
#define LLM_OS_Devices_Geolocation_Geofencing_1_H
#include "llm/impl/Windows.Devices.Geolocation.Geofencing.0.h"
LLM_EXPORT namespace llm::OS::Devices::Geolocation::Geofencing
{
    struct __declspec(empty_bases) IGeofence :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeofence>
    {
        IGeofence(std::nullptr_t = nullptr) noexcept {}
        IGeofence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeofenceFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeofenceFactory>
    {
        IGeofenceFactory(std::nullptr_t = nullptr) noexcept {}
        IGeofenceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeofenceMonitor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeofenceMonitor>
    {
        IGeofenceMonitor(std::nullptr_t = nullptr) noexcept {}
        IGeofenceMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeofenceMonitorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeofenceMonitorStatics>
    {
        IGeofenceMonitorStatics(std::nullptr_t = nullptr) noexcept {}
        IGeofenceMonitorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeofenceStateChangeReport :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeofenceStateChangeReport>
    {
        IGeofenceStateChangeReport(std::nullptr_t = nullptr) noexcept {}
        IGeofenceStateChangeReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
