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
#ifndef LLM_OS_ApplicationModel_Store_Preview_InstallControl_2_H
#define LLM_OS_ApplicationModel_Store_Preview_InstallControl_2_H
#include "llm/impl/Windows.ApplicationModel.Store.Preview.InstallControl.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::Preview::InstallControl
{
    struct __declspec(empty_bases) AppInstallItem : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem,
        impl::require<AppInstallItem, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem3, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem4, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem5>
    {
        AppInstallItem(std::nullptr_t) noexcept {}
        AppInstallItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem::Cancel;
        using impl::consume_t<AppInstallItem, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>::Cancel;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem::Pause;
        using impl::consume_t<AppInstallItem, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>::Pause;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem::Restart;
        using impl::consume_t<AppInstallItem, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>::Restart;
    };
    struct __declspec(empty_bases) AppInstallManager : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager,
        impl::require<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager4, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager5, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager7>
    {
        AppInstallManager(std::nullptr_t) noexcept {}
        AppInstallManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager(ptr, take_ownership_from_abi) {}
        AppInstallManager();
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::Cancel;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::Cancel;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::GetIsAppAllowedToInstallAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::GetIsAppAllowedToInstallAsync;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::Pause;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::Pause;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::Restart;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::Restart;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::SearchForAllUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::SearchForAllUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::SearchForAllUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>::SearchForAllUpdatesForUserAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::SearchForAllUpdatesForUserAsync;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::SearchForUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::SearchForUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::SearchForUpdatesAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>::SearchForUpdatesForUserAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::SearchForUpdatesForUserAsync;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::StartAppInstallAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::StartAppInstallAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>::StartProductInstallAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::StartProductInstallAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>::StartProductInstallForUserAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager6>::StartProductInstallForUserAsync;
        using llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::UpdateAppByPackageFamilyNameAsync;
        using impl::consume_t<AppInstallManager, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>::UpdateAppByPackageFamilyNameAsync;
    };
    struct __declspec(empty_bases) AppInstallManagerItemEventArgs : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs
    {
        AppInstallManagerItemEventArgs(std::nullptr_t) noexcept {}
        AppInstallManagerItemEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppInstallOptions : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallOptions,
        impl::require<AppInstallOptions, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallOptions2>
    {
        AppInstallOptions(std::nullptr_t) noexcept {}
        AppInstallOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallOptions(ptr, take_ownership_from_abi) {}
        AppInstallOptions();
    };
    struct __declspec(empty_bases) AppInstallStatus : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus,
        impl::require<AppInstallStatus, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus3>
    {
        AppInstallStatus(std::nullptr_t) noexcept {}
        AppInstallStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppUpdateOptions : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppUpdateOptions,
        impl::require<AppUpdateOptions, llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppUpdateOptions2>
    {
        AppUpdateOptions(std::nullptr_t) noexcept {}
        AppUpdateOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IAppUpdateOptions(ptr, take_ownership_from_abi) {}
        AppUpdateOptions();
    };
    struct __declspec(empty_bases) GetEntitlementResult : llm::OS::ApplicationModel::Store::Preview::InstallControl::IGetEntitlementResult
    {
        GetEntitlementResult(std::nullptr_t) noexcept {}
        GetEntitlementResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::Preview::InstallControl::IGetEntitlementResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
