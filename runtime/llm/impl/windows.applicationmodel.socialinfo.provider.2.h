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
#ifndef LLM_OS_ApplicationModel_SocialInfo_Provider_2_H
#define LLM_OS_ApplicationModel_SocialInfo_Provider_2_H
#include "llm/impl/Windows.ApplicationModel.SocialInfo.1.h"
#include "llm/impl/Windows.ApplicationModel.SocialInfo.Provider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo::Provider
{
    struct __declspec(empty_bases) SocialDashboardItemUpdater : llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater
    {
        SocialDashboardItemUpdater(std::nullptr_t) noexcept {}
        SocialDashboardItemUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SocialFeedUpdater : llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater
    {
        SocialFeedUpdater(std::nullptr_t) noexcept {}
        SocialFeedUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater(ptr, take_ownership_from_abi) {}
    };
    struct SocialInfoProviderManager
    {
        SocialInfoProviderManager() = delete;
        static auto CreateSocialFeedUpdaterAsync(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind, llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode const& mode, param::hstring const& ownerRemoteId);
        static auto CreateDashboardItemUpdaterAsync(param::hstring const& ownerRemoteId);
        static auto UpdateBadgeCountValue(param::hstring const& itemRemoteId, int32_t newCount);
        static auto ReportNewContentAvailable(param::hstring const& contactRemoteId, llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind);
        static auto ProvisionAsync();
        static auto DeprovisionAsync();
    };
}
#endif
