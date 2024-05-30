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
#ifndef LLM_OS_Media_AppBroadcasting_2_H
#define LLM_OS_Media_AppBroadcasting_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Media.AppBroadcasting.1.h"
LLM_EXPORT namespace llm:OS::Media::AppBroadcasting
{
    struct __declspec(empty_bases) AppBroadcastingMonitor : llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor
    {
        AppBroadcastingMonitor(std::nullptr_t) noexcept {}
        AppBroadcastingMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppBroadcasting::IAppBroadcastingMonitor(ptr, take_ownership_from_abi) {}
        AppBroadcastingMonitor();
    };
    struct __declspec(empty_bases) AppBroadcastingStatus : llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus
    {
        AppBroadcastingStatus(std::nullptr_t) noexcept {}
        AppBroadcastingStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppBroadcasting::IAppBroadcastingStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastingStatusDetails : llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails
    {
        AppBroadcastingStatusDetails(std::nullptr_t) noexcept {}
        AppBroadcastingStatusDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastingUI : llm:OS::Media::AppBroadcasting::IAppBroadcastingUI
    {
        AppBroadcastingUI(std::nullptr_t) noexcept {}
        AppBroadcastingUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppBroadcasting::IAppBroadcastingUI(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
}
#endif
