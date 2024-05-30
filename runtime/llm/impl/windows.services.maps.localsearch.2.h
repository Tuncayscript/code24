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
#ifndef LLM_OS_Services_Maps_LocalSearch_2_H
#define LLM_OS_Services_Maps_LocalSearch_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Services.Maps.LocalSearch.1.h"
LLM_EXPORT namespace llm:OS::Services::Maps::LocalSearch
{
    struct LocalCategories
    {
        LocalCategories() = delete;
        [[nodiscard]] static auto BankAndCreditUnions();
        [[nodiscard]] static auto EatDrink();
        [[nodiscard]] static auto Hospitals();
        [[nodiscard]] static auto HotelsAndMotels();
        [[nodiscard]] static auto All();
        [[nodiscard]] static auto Parking();
        [[nodiscard]] static auto SeeDo();
        [[nodiscard]] static auto Shop();
    };
    struct __declspec(empty_bases) LocalLocation : llm:OS::Services::Maps::LocalSearch::ILocalLocation,
        impl::require<LocalLocation, llm:OS::Services::Maps::LocalSearch::ILocalLocation2>
    {
        LocalLocation(std::nullptr_t) noexcept {}
        LocalLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::LocalSearch::ILocalLocation(ptr, take_ownership_from_abi) {}
    };
    struct LocalLocationFinder
    {
        LocalLocationFinder() = delete;
        static auto FindLocalLocationsAsync(param::hstring const& searchTerm, llm:OS::Devices::Geolocation::Geocircle const& searchArea, param::hstring const& localCategory, uint32_t maxResults);
    };
    struct __declspec(empty_bases) LocalLocationFinderResult : llm:OS::Services::Maps::LocalSearch::ILocalLocationFinderResult
    {
        LocalLocationFinderResult(std::nullptr_t) noexcept {}
        LocalLocationFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::LocalSearch::ILocalLocationFinderResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LocalLocationHoursOfOperationItem : llm:OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem
    {
        LocalLocationHoursOfOperationItem(std::nullptr_t) noexcept {}
        LocalLocationHoursOfOperationItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LocalLocationRatingInfo : llm:OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo
    {
        LocalLocationRatingInfo(std::nullptr_t) noexcept {}
        LocalLocationRatingInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Maps::LocalSearch::ILocalLocationRatingInfo(ptr, take_ownership_from_abi) {}
    };
    struct PlaceInfoHelper
    {
        PlaceInfoHelper() = delete;
        static auto CreateFromLocalLocation(llm:OS::Services::Maps::LocalSearch::LocalLocation const& location);
    };
}
#endif
