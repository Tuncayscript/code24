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
#ifndef LLM_OS_Services_Maps_Guidance_2_H
#define LLM_OS_Services_Maps_Guidance_2_H
#include "llm/impl/Windows.Services.Maps.1.h"
#include "llm/impl/Windows.Services.Maps.Guidance.1.h"
LLM_EXPORT namespace llm:OS::Services::Maps::Guidance
{
    struct __declspec(empty_bases) GuidanceAudioNotificationRequestedEventArgs : llm:OS::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs
    {
        GuidanceAudioNotificationRequestedEventArgs(std::nullptr_t) noexcept {}
        GuidanceAudioNotificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceLaneInfo : llm:OS::Services::Maps::Guidance::IGuidanceLaneInfo
    {
        GuidanceLaneInfo(std::nullptr_t) noexcept {}
        GuidanceLaneInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceLaneInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceManeuver : llm:OS::Services::Maps::Guidance::IGuidanceManeuver
    {
        GuidanceManeuver(std::nullptr_t) noexcept {}
        GuidanceManeuver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceManeuver(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceMapMatchedCoordinate : llm:OS::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate
    {
        GuidanceMapMatchedCoordinate(std::nullptr_t) noexcept {}
        GuidanceMapMatchedCoordinate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceNavigator : llm:OS::Services::Maps::Guidance::IGuidanceNavigator,
        impl::require<GuidanceNavigator, llm:OS::Services::Maps::Guidance::IGuidanceNavigator2>
    {
        GuidanceNavigator(std::nullptr_t) noexcept {}
        GuidanceNavigator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceNavigator(ptr, take_ownership_from_abi) {}
        static auto GetCurrent();
        [[nodiscard]] static auto UseAppProvidedVoice();
    };
    struct __declspec(empty_bases) GuidanceReroutedEventArgs : llm:OS::Services::Maps::Guidance::IGuidanceReroutedEventArgs
    {
        GuidanceReroutedEventArgs(std::nullptr_t) noexcept {}
        GuidanceReroutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceReroutedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceRoadSegment : llm:OS::Services::Maps::Guidance::IGuidanceRoadSegment,
        impl::require<GuidanceRoadSegment, llm:OS::Services::Maps::Guidance::IGuidanceRoadSegment2>
    {
        GuidanceRoadSegment(std::nullptr_t) noexcept {}
        GuidanceRoadSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceRoadSegment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceRoadSignpost : llm:OS::Services::Maps::Guidance::IGuidanceRoadSignpost
    {
        GuidanceRoadSignpost(std::nullptr_t) noexcept {}
        GuidanceRoadSignpost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceRoadSignpost(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GuidanceRoute : llm:OS::Services::Maps::Guidance::IGuidanceRoute
    {
        GuidanceRoute(std::nullptr_t) noexcept {}
        GuidanceRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceRoute(ptr, take_ownership_from_abi) {}
        static auto CanCreateFromMapRoute(llm:OS::Services::Maps::MapRoute const& mapRoute);
        static auto TryCreateFromMapRoute(llm:OS::Services::Maps::MapRoute const& mapRoute);
    };
    struct __declspec(empty_bases) GuidanceTelemetryCollector : llm:OS::Services::Maps::Guidance::IGuidanceTelemetryCollector
    {
        GuidanceTelemetryCollector(std::nullptr_t) noexcept {}
        GuidanceTelemetryCollector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceTelemetryCollector(ptr, take_ownership_from_abi) {}
        static auto GetCurrent();
    };
    struct __declspec(empty_bases) GuidanceUpdatedEventArgs : llm:OS::Services::Maps::Guidance::IGuidanceUpdatedEventArgs
    {
        GuidanceUpdatedEventArgs(std::nullptr_t) noexcept {}
        GuidanceUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::Guidance::IGuidanceUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
