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
#ifndef LLM_OS_ApplicationModel_1_H
#define LLM_OS_ApplicationModel_1_H
#include "llm/impl/Windows.ApplicationModel.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    struct __declspec(empty_bases) IAppDisplayInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppDisplayInfo>
    {
        IAppDisplayInfo(std::nullptr_t = nullptr) noexcept {}
        IAppDisplayInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInfo>
    {
        IAppInfo(std::nullptr_t = nullptr) noexcept {}
        IAppInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInfo2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInfo2>
    {
        IAppInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInfo3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInfo3>
    {
        IAppInfo3(std::nullptr_t = nullptr) noexcept {}
        IAppInfo3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInfo4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInfo4>
    {
        IAppInfo4(std::nullptr_t = nullptr) noexcept {}
        IAppInfo4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInfoStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInfoStatics>
    {
        IAppInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IAppInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstallerInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInstallerInfo>
    {
        IAppInstallerInfo(std::nullptr_t = nullptr) noexcept {}
        IAppInstallerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstallerInfo2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInstallerInfo2>
    {
        IAppInstallerInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppInstallerInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstance :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInstance>
    {
        IAppInstance(std::nullptr_t = nullptr) noexcept {}
        IAppInstance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppInstanceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppInstanceStatics>
    {
        IAppInstanceStatics(std::nullptr_t = nullptr) noexcept {}
        IAppInstanceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesignModeStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignModeStatics>
    {
        IDesignModeStatics(std::nullptr_t = nullptr) noexcept {}
        IDesignModeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesignModeStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignModeStatics2>
    {
        IDesignModeStatics2(std::nullptr_t = nullptr) noexcept {}
        IDesignModeStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEnteredBackgroundEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEnteredBackgroundEventArgs>
    {
        IEnteredBackgroundEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEnteredBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFindRelatedPackagesOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFindRelatedPackagesOptions>
    {
        IFindRelatedPackagesOptions(std::nullptr_t = nullptr) noexcept {}
        IFindRelatedPackagesOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFindRelatedPackagesOptionsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFindRelatedPackagesOptionsFactory>
    {
        IFindRelatedPackagesOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IFindRelatedPackagesOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFullTrustProcessLaunchResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFullTrustProcessLaunchResult>
    {
        IFullTrustProcessLaunchResult(std::nullptr_t = nullptr) noexcept {}
        IFullTrustProcessLaunchResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFullTrustProcessLauncherStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFullTrustProcessLauncherStatics>
    {
        IFullTrustProcessLauncherStatics(std::nullptr_t = nullptr) noexcept {}
        IFullTrustProcessLauncherStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFullTrustProcessLauncherStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFullTrustProcessLauncherStatics2>
    {
        IFullTrustProcessLauncherStatics2(std::nullptr_t = nullptr) noexcept {}
        IFullTrustProcessLauncherStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILeavingBackgroundEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILeavingBackgroundEventArgs>
    {
        ILeavingBackgroundEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILeavingBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILimitedAccessFeatureRequestResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILimitedAccessFeatureRequestResult>
    {
        ILimitedAccessFeatureRequestResult(std::nullptr_t = nullptr) noexcept {}
        ILimitedAccessFeatureRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILimitedAccessFeaturesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILimitedAccessFeaturesStatics>
    {
        ILimitedAccessFeaturesStatics(std::nullptr_t = nullptr) noexcept {}
        ILimitedAccessFeaturesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage>
    {
        IPackage(std::nullptr_t = nullptr) noexcept {}
        IPackage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage2>
    {
        IPackage2(std::nullptr_t = nullptr) noexcept {}
        IPackage2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage3>
    {
        IPackage3(std::nullptr_t = nullptr) noexcept {}
        IPackage3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage4>
    {
        IPackage4(std::nullptr_t = nullptr) noexcept {}
        IPackage4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage5>
    {
        IPackage5(std::nullptr_t = nullptr) noexcept {}
        IPackage5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage6 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage6>
    {
        IPackage6(std::nullptr_t = nullptr) noexcept {}
        IPackage6(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage7 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage7>
    {
        IPackage7(std::nullptr_t = nullptr) noexcept {}
        IPackage7(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage8 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage8>
    {
        IPackage8(std::nullptr_t = nullptr) noexcept {}
        IPackage8(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackage9 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackage9>
    {
        IPackage9(std::nullptr_t = nullptr) noexcept {}
        IPackage9(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalog :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalog>
    {
        IPackageCatalog(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalog(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalog2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalog2>
    {
        IPackageCatalog2(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalog2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalog3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalog3>
    {
        IPackageCatalog3(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalog3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalog4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalog4>
    {
        IPackageCatalog4(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalog4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogAddOptionalPackageResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogAddOptionalPackageResult>
    {
        IPackageCatalogAddOptionalPackageResult(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogAddOptionalPackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogAddResourcePackageResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogAddResourcePackageResult>
    {
        IPackageCatalogAddResourcePackageResult(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogAddResourcePackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogRemoveOptionalPackagesResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogRemoveOptionalPackagesResult>
    {
        IPackageCatalogRemoveOptionalPackagesResult(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogRemoveOptionalPackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogRemoveResourcePackagesResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogRemoveResourcePackagesResult>
    {
        IPackageCatalogRemoveResourcePackagesResult(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogRemoveResourcePackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogStatics>
    {
        IPackageCatalogStatics(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageCatalogStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageCatalogStatics2>
    {
        IPackageCatalogStatics2(std::nullptr_t = nullptr) noexcept {}
        IPackageCatalogStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageContentGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageContentGroup>
    {
        IPackageContentGroup(std::nullptr_t = nullptr) noexcept {}
        IPackageContentGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageContentGroupStagingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageContentGroupStagingEventArgs>
    {
        IPackageContentGroupStagingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageContentGroupStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageContentGroupStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageContentGroupStatics>
    {
        IPackageContentGroupStatics(std::nullptr_t = nullptr) noexcept {}
        IPackageContentGroupStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageId :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageId>
    {
        IPackageId(std::nullptr_t = nullptr) noexcept {}
        IPackageId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageIdWithMetadata :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageIdWithMetadata>
    {
        IPackageIdWithMetadata(std::nullptr_t = nullptr) noexcept {}
        IPackageIdWithMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageInstallingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageInstallingEventArgs>
    {
        IPackageInstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageInstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageStagingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageStagingEventArgs>
    {
        IPackageStagingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageStatics>
    {
        IPackageStatics(std::nullptr_t = nullptr) noexcept {}
        IPackageStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageStatus :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageStatus>
    {
        IPackageStatus(std::nullptr_t = nullptr) noexcept {}
        IPackageStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageStatus2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageStatus2>
    {
        IPackageStatus2(std::nullptr_t = nullptr) noexcept {}
        IPackageStatus2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageStatusChangedEventArgs>
    {
        IPackageStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageUninstallingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageUninstallingEventArgs>
    {
        IPackageUninstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageUpdateAvailabilityResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageUpdateAvailabilityResult>
    {
        IPackageUpdateAvailabilityResult(std::nullptr_t = nullptr) noexcept {}
        IPackageUpdateAvailabilityResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageUpdatingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageUpdatingEventArgs>
    {
        IPackageUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPackageWithMetadata :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPackageWithMetadata>
    {
        IPackageWithMetadata(std::nullptr_t = nullptr) noexcept {}
        IPackageWithMetadata(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartupTask :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStartupTask>
    {
        IStartupTask(std::nullptr_t = nullptr) noexcept {}
        IStartupTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartupTaskStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStartupTaskStatics>
    {
        IStartupTaskStatics(std::nullptr_t = nullptr) noexcept {}
        IStartupTaskStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISuspendingDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISuspendingDeferral>
    {
        ISuspendingDeferral(std::nullptr_t = nullptr) noexcept {}
        ISuspendingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISuspendingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISuspendingEventArgs>
    {
        ISuspendingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISuspendingOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISuspendingOperation>
    {
        ISuspendingOperation(std::nullptr_t = nullptr) noexcept {}
        ISuspendingOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
