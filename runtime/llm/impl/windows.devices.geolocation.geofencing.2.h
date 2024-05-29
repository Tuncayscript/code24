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
#ifndef LLM_OS_Devices_Geolocation_Geofencing_2_H
#define LLM_OS_Devices_Geolocation_Geofencing_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Geolocation.Geofencing.1.h"
LLM_EXPORT namespace llm::OS::Devices::Geolocation::Geofencing
{
    struct __declspec(empty_bases) Geofence : llm::OS::Devices::Geolocation::Geofencing::IGeofence
    {
        Geofence(std::nullptr_t) noexcept {}
        Geofence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::Geofencing::IGeofence(ptr, take_ownership_from_abi) {}
        Geofence(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape);
        Geofence(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse);
        Geofence(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse, llm::OS::Foundation::TimeSpan const& dwellTime);
        Geofence(param::hstring const& id, llm::OS::Devices::Geolocation::IGeoshape const& geoshape, llm::OS::Devices::Geolocation::Geofencing::MonitoredGeofenceStates const& monitoredStates, bool singleUse, llm::OS::Foundation::TimeSpan const& dwellTime, llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::TimeSpan const& duration);
    };
    struct __declspec(empty_bases) GeofenceMonitor : llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor
    {
        GeofenceMonitor(std::nullptr_t) noexcept {}
        GeofenceMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::Geofencing::IGeofenceMonitor(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) GeofenceStateChangeReport : llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport
    {
        GeofenceStateChangeReport(std::nullptr_t) noexcept {}
        GeofenceStateChangeReport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport(ptr, take_ownership_from_abi) {}
    };
}
#endif
