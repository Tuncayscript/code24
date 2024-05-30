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
#ifndef LLM_OS_Services_Cortana_1_H
#define LLM_OS_Services_Cortana_1_H
#include "llm/impl/Windows.Services.Cortana.0.h"
LLM_EXPORT namespace llm:OS::Services::Cortana
{
    struct __declspec(empty_bases) ICortanaActionableInsights :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaActionableInsights>
    {
        ICortanaActionableInsights(std::nullptr_t = nullptr) noexcept {}
        ICortanaActionableInsights(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaActionableInsightsOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaActionableInsightsOptions>
    {
        ICortanaActionableInsightsOptions(std::nullptr_t = nullptr) noexcept {}
        ICortanaActionableInsightsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaActionableInsightsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaActionableInsightsStatics>
    {
        ICortanaActionableInsightsStatics(std::nullptr_t = nullptr) noexcept {}
        ICortanaActionableInsightsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaPermissionsManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaPermissionsManager>
    {
        ICortanaPermissionsManager(std::nullptr_t = nullptr) noexcept {}
        ICortanaPermissionsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaPermissionsManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaPermissionsManagerStatics>
    {
        ICortanaPermissionsManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICortanaPermissionsManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaSettings>
    {
        ICortanaSettings(std::nullptr_t = nullptr) noexcept {}
        ICortanaSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICortanaSettingsStatics>
    {
        ICortanaSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        ICortanaSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
