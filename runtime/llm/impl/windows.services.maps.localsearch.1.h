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
#ifndef LLM_OS_Services_Maps_LocalSearch_1_H
#define LLM_OS_Services_Maps_LocalSearch_1_H
#include "llm/impl/Windows.Services.Maps.LocalSearch.0.h"
LLM_EXPORT namespace llm:OS::Services::Maps::LocalSearch
{
    struct __declspec(empty_bases) ILocalCategoriesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalCategoriesStatics>
    {
        ILocalCategoriesStatics(std::nullptr_t = nullptr) noexcept {}
        ILocalCategoriesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocation>
    {
        ILocalLocation(std::nullptr_t = nullptr) noexcept {}
        ILocalLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocation2>
    {
        ILocalLocation2(std::nullptr_t = nullptr) noexcept {}
        ILocalLocation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocationFinderResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocationFinderResult>
    {
        ILocalLocationFinderResult(std::nullptr_t = nullptr) noexcept {}
        ILocalLocationFinderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocationFinderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocationFinderStatics>
    {
        ILocalLocationFinderStatics(std::nullptr_t = nullptr) noexcept {}
        ILocalLocationFinderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocationHoursOfOperationItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocationHoursOfOperationItem>
    {
        ILocalLocationHoursOfOperationItem(std::nullptr_t = nullptr) noexcept {}
        ILocalLocationHoursOfOperationItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocalLocationRatingInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILocalLocationRatingInfo>
    {
        ILocalLocationRatingInfo(std::nullptr_t = nullptr) noexcept {}
        ILocalLocationRatingInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaceInfoHelperStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaceInfoHelperStatics>
    {
        IPlaceInfoHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IPlaceInfoHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
