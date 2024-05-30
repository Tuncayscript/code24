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
#ifndef LLM_OS_Services_Cortana_2_H
#define LLM_OS_Services_Cortana_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Services.Cortana.1.h"
LLM_EXPORT namespace llm:OS::Services::Cortana
{
    struct __declspec(empty_bases) CortanaActionableInsights : llm:OS::Services::Cortana::ICortanaActionableInsights
    {
        CortanaActionableInsights(std::nullptr_t) noexcept {}
        CortanaActionableInsights(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Cortana::ICortanaActionableInsights(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) CortanaActionableInsightsOptions : llm:OS::Services::Cortana::ICortanaActionableInsightsOptions
    {
        CortanaActionableInsightsOptions(std::nullptr_t) noexcept {}
        CortanaActionableInsightsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Cortana::ICortanaActionableInsightsOptions(ptr, take_ownership_from_abi) {}
        CortanaActionableInsightsOptions();
    };
    struct __declspec(empty_bases) CortanaPermissionsManager : llm:OS::Services::Cortana::ICortanaPermissionsManager
    {
        CortanaPermissionsManager(std::nullptr_t) noexcept {}
        CortanaPermissionsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Cortana::ICortanaPermissionsManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) CortanaSettings : llm:OS::Services::Cortana::ICortanaSettings
    {
        CortanaSettings(std::nullptr_t) noexcept {}
        CortanaSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Services::Cortana::ICortanaSettings(ptr, take_ownership_from_abi) {}
        static auto IsSupported();
        static auto GetDefault();
    };
}
#endif
