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
#ifndef LLM_OS_Services_Maps_1_H
#define LLM_OS_Services_Maps_1_H
#include "llm/impl/Windows.Services.Maps.0.h"
LLM_EXPORT namespace llm:OS::Services::Maps
{
    struct __declspec(empty_bases) IEnhancedWaypoint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEnhancedWaypoint>
    {
        IEnhancedWaypoint(std::nullptr_t = nullptr) noexcept {}
        IEnhancedWaypoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEnhancedWaypointFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEnhancedWaypointFactory>
    {
        IEnhancedWaypointFactory(std::nullptr_t = nullptr) noexcept {}
        IEnhancedWaypointFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManeuverWarning :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManeuverWarning>
    {
        IManeuverWarning(std::nullptr_t = nullptr) noexcept {}
        IManeuverWarning(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapAddress :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapAddress>
    {
        IMapAddress(std::nullptr_t = nullptr) noexcept {}
        IMapAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapAddress2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapAddress2>
    {
        IMapAddress2(std::nullptr_t = nullptr) noexcept {}
        IMapAddress2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapLocation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapLocation>
    {
        IMapLocation(std::nullptr_t = nullptr) noexcept {}
        IMapLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapLocationFinderResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapLocationFinderResult>
    {
        IMapLocationFinderResult(std::nullptr_t = nullptr) noexcept {}
        IMapLocationFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapLocationFinderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapLocationFinderStatics>
    {
        IMapLocationFinderStatics(std::nullptr_t = nullptr) noexcept {}
        IMapLocationFinderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapLocationFinderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapLocationFinderStatics2>
    {
        IMapLocationFinderStatics2(std::nullptr_t = nullptr) noexcept {}
        IMapLocationFinderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapManagerStatics>
    {
        IMapManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IMapManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRoute :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRoute>
    {
        IMapRoute(std::nullptr_t = nullptr) noexcept {}
        IMapRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRoute2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRoute2>
    {
        IMapRoute2(std::nullptr_t = nullptr) noexcept {}
        IMapRoute2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRoute3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRoute3>
    {
        IMapRoute3(std::nullptr_t = nullptr) noexcept {}
        IMapRoute3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRoute4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRoute4>
    {
        IMapRoute4(std::nullptr_t = nullptr) noexcept {}
        IMapRoute4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteDrivingOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteDrivingOptions>
    {
        IMapRouteDrivingOptions(std::nullptr_t = nullptr) noexcept {}
        IMapRouteDrivingOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteDrivingOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteDrivingOptions2>
    {
        IMapRouteDrivingOptions2(std::nullptr_t = nullptr) noexcept {}
        IMapRouteDrivingOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteFinderResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteFinderResult>
    {
        IMapRouteFinderResult(std::nullptr_t = nullptr) noexcept {}
        IMapRouteFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteFinderResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteFinderResult2>
    {
        IMapRouteFinderResult2(std::nullptr_t = nullptr) noexcept {}
        IMapRouteFinderResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteFinderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteFinderStatics>
    {
        IMapRouteFinderStatics(std::nullptr_t = nullptr) noexcept {}
        IMapRouteFinderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteFinderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteFinderStatics2>
    {
        IMapRouteFinderStatics2(std::nullptr_t = nullptr) noexcept {}
        IMapRouteFinderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteFinderStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteFinderStatics3>
    {
        IMapRouteFinderStatics3(std::nullptr_t = nullptr) noexcept {}
        IMapRouteFinderStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteLeg :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteLeg>
    {
        IMapRouteLeg(std::nullptr_t = nullptr) noexcept {}
        IMapRouteLeg(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteLeg2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteLeg2>
    {
        IMapRouteLeg2(std::nullptr_t = nullptr) noexcept {}
        IMapRouteLeg2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteManeuver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteManeuver>
    {
        IMapRouteManeuver(std::nullptr_t = nullptr) noexcept {}
        IMapRouteManeuver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteManeuver2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteManeuver2>
    {
        IMapRouteManeuver2(std::nullptr_t = nullptr) noexcept {}
        IMapRouteManeuver2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapRouteManeuver3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapRouteManeuver3>
    {
        IMapRouteManeuver3(std::nullptr_t = nullptr) noexcept {}
        IMapRouteManeuver3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapServiceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapServiceStatics>
    {
        IMapServiceStatics(std::nullptr_t = nullptr) noexcept {}
        IMapServiceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapServiceStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapServiceStatics2>
    {
        IMapServiceStatics2(std::nullptr_t = nullptr) noexcept {}
        IMapServiceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapServiceStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapServiceStatics3>
    {
        IMapServiceStatics3(std::nullptr_t = nullptr) noexcept {}
        IMapServiceStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMapServiceStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMapServiceStatics4>
    {
        IMapServiceStatics4(std::nullptr_t = nullptr) noexcept {}
        IMapServiceStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaceInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaceInfo>
    {
        IPlaceInfo(std::nullptr_t = nullptr) noexcept {}
        IPlaceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaceInfoCreateOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaceInfoCreateOptions>
    {
        IPlaceInfoCreateOptions(std::nullptr_t = nullptr) noexcept {}
        IPlaceInfoCreateOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaceInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaceInfoStatics>
    {
        IPlaceInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IPlaceInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaceInfoStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaceInfoStatics2>
    {
        IPlaceInfoStatics2(std::nullptr_t = nullptr) noexcept {}
        IPlaceInfoStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
