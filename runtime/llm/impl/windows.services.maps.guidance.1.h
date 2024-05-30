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
#ifndef LLM_OS_Services_Maps_Guidance_1_H
#define LLM_OS_Services_Maps_Guidance_1_H
#include "llm/impl/Windows.Services.Maps.Guidance.0.h"
LLM_EXPORT namespace llm:OS::Services::Maps::Guidance
{
    struct __declspec(empty_bases) IGuidanceAudioNotificationRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceAudioNotificationRequestedEventArgs>
    {
        IGuidanceAudioNotificationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGuidanceAudioNotificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceLaneInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceLaneInfo>
    {
        IGuidanceLaneInfo(std::nullptr_t = nullptr) noexcept {}
        IGuidanceLaneInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceManeuver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceManeuver>
    {
        IGuidanceManeuver(std::nullptr_t = nullptr) noexcept {}
        IGuidanceManeuver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceMapMatchedCoordinate :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceMapMatchedCoordinate>
    {
        IGuidanceMapMatchedCoordinate(std::nullptr_t = nullptr) noexcept {}
        IGuidanceMapMatchedCoordinate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceNavigator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceNavigator>
    {
        IGuidanceNavigator(std::nullptr_t = nullptr) noexcept {}
        IGuidanceNavigator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceNavigator2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceNavigator2>
    {
        IGuidanceNavigator2(std::nullptr_t = nullptr) noexcept {}
        IGuidanceNavigator2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceNavigatorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceNavigatorStatics>
    {
        IGuidanceNavigatorStatics(std::nullptr_t = nullptr) noexcept {}
        IGuidanceNavigatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceNavigatorStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceNavigatorStatics2>
    {
        IGuidanceNavigatorStatics2(std::nullptr_t = nullptr) noexcept {}
        IGuidanceNavigatorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceReroutedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceReroutedEventArgs>
    {
        IGuidanceReroutedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGuidanceReroutedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceRoadSegment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceRoadSegment>
    {
        IGuidanceRoadSegment(std::nullptr_t = nullptr) noexcept {}
        IGuidanceRoadSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceRoadSegment2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceRoadSegment2>
    {
        IGuidanceRoadSegment2(std::nullptr_t = nullptr) noexcept {}
        IGuidanceRoadSegment2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceRoadSignpost :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceRoadSignpost>
    {
        IGuidanceRoadSignpost(std::nullptr_t = nullptr) noexcept {}
        IGuidanceRoadSignpost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceRoute :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceRoute>
    {
        IGuidanceRoute(std::nullptr_t = nullptr) noexcept {}
        IGuidanceRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceRouteStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceRouteStatics>
    {
        IGuidanceRouteStatics(std::nullptr_t = nullptr) noexcept {}
        IGuidanceRouteStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceTelemetryCollector :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceTelemetryCollector>
    {
        IGuidanceTelemetryCollector(std::nullptr_t = nullptr) noexcept {}
        IGuidanceTelemetryCollector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceTelemetryCollectorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceTelemetryCollectorStatics>
    {
        IGuidanceTelemetryCollectorStatics(std::nullptr_t = nullptr) noexcept {}
        IGuidanceTelemetryCollectorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGuidanceUpdatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGuidanceUpdatedEventArgs>
    {
        IGuidanceUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGuidanceUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
