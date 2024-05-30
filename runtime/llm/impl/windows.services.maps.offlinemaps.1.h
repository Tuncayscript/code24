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
#ifndef LLM_OS_Services_Maps_OfflineMaps_1_H
#define LLM_OS_Services_Maps_OfflineMaps_1_H
#include "llm/impl/Windows.Services.Maps.OfflineMaps.0.h"
LLM_EXPORT namespace llm:OS::Services::Maps::OfflineMaps
{
    struct __declspec(empty_bases) IOfflineMapPackage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOfflineMapPackage>
    {
        IOfflineMapPackage(std::nullptr_t = nullptr) noexcept {}
        IOfflineMapPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOfflineMapPackageQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOfflineMapPackageQueryResult>
    {
        IOfflineMapPackageQueryResult(std::nullptr_t = nullptr) noexcept {}
        IOfflineMapPackageQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOfflineMapPackageStartDownloadResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOfflineMapPackageStartDownloadResult>
    {
        IOfflineMapPackageStartDownloadResult(std::nullptr_t = nullptr) noexcept {}
        IOfflineMapPackageStartDownloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOfflineMapPackageStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOfflineMapPackageStatics>
    {
        IOfflineMapPackageStatics(std::nullptr_t = nullptr) noexcept {}
        IOfflineMapPackageStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
