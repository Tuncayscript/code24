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
#ifndef LLM_OS_ApplicationModel_2_H
#define LLM_OS_ApplicationModel_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    struct PackageInstallProgress
    {
        uint32_t PercentComplete;
    };
    inline bool operator==(PackageInstallProgress const& left, PackageInstallProgress const& right) noexcept
    {
        return left.PercentComplete == right.PercentComplete;
    }
    inline bool operator!=(PackageInstallProgress const& left, PackageInstallProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct PackageVersion
    {
        uint16_t Major;
        uint16_t Minor;
        uint16_t Build;
        uint16_t Revision;
    };
    inline bool operator==(PackageVersion const& left, PackageVersion const& right) noexcept
    {
        return left.Major == right.Major && left.Minor == right.Minor && left.Build == right.Build && left.Revision == right.Revision;
    }
    inline bool operator!=(PackageVersion const& left, PackageVersion const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AppDisplayInfo : llm::OS::ApplicationModel::IAppDisplayInfo
    {
        AppDisplayInfo(std::nullptr_t) noexcept {}
        AppDisplayInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IAppDisplayInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppInfo : llm::OS::ApplicationModel::IAppInfo,
        impl::require<AppInfo, llm::OS::ApplicationModel::IAppInfo2, llm::OS::ApplicationModel::IAppInfo3, llm::OS::ApplicationModel::IAppInfo4>
    {
        AppInfo(std::nullptr_t) noexcept {}
        AppInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IAppInfo(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto GetFromAppUserModelId(param::hstring const& appUserModelId);
        static auto GetFromAppUserModelIdForUser(llm::OS::System::User const& user, param::hstring const& appUserModelId);
    };
    struct __declspec(empty_bases) AppInstallerInfo : llm::OS::ApplicationModel::IAppInstallerInfo,
        impl::require<AppInstallerInfo, llm::OS::ApplicationModel::IAppInstallerInfo2>
    {
        AppInstallerInfo(std::nullptr_t) noexcept {}
        AppInstallerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IAppInstallerInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppInstance : llm::OS::ApplicationModel::IAppInstance
    {
        AppInstance(std::nullptr_t) noexcept {}
        AppInstance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IAppInstance(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto RecommendedInstance();
        static auto GetActivatedEventArgs();
        static auto FindOrRegisterInstanceForKey(param::hstring const& key);
        static auto Unregister();
        static auto GetInstances();
    };
    struct DesignMode
    {
        DesignMode() = delete;
        [[nodiscard]] static auto DesignModeEnabled();
        [[nodiscard]] static auto DesignMode2Enabled();
    };
    struct __declspec(empty_bases) EnteredBackgroundEventArgs : llm::OS::ApplicationModel::IEnteredBackgroundEventArgs
    {
        EnteredBackgroundEventArgs(std::nullptr_t) noexcept {}
        EnteredBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IEnteredBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FindRelatedPackagesOptions : llm::OS::ApplicationModel::IFindRelatedPackagesOptions
    {
        FindRelatedPackagesOptions(std::nullptr_t) noexcept {}
        FindRelatedPackagesOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IFindRelatedPackagesOptions(ptr, take_ownership_from_abi) {}
        explicit FindRelatedPackagesOptions(llm::OS::ApplicationModel::PackageRelationship const& Relationship);
    };
    struct __declspec(empty_bases) FullTrustProcessLaunchResult : llm::OS::ApplicationModel::IFullTrustProcessLaunchResult
    {
        FullTrustProcessLaunchResult(std::nullptr_t) noexcept {}
        FullTrustProcessLaunchResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IFullTrustProcessLaunchResult(ptr, take_ownership_from_abi) {}
    };
    struct FullTrustProcessLauncher
    {
        FullTrustProcessLauncher() = delete;
        static auto LaunchFullTrustProcessForCurrentAppAsync();
        static auto LaunchFullTrustProcessForCurrentAppAsync(param::hstring const& parameterGroupId);
        static auto LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId);
        static auto LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& parameterGroupId);
        static auto LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(param::hstring const& commandLine);
        static auto LaunchFullTrustProcessForAppWithArgumentsAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& commandLine);
    };
    struct __declspec(empty_bases) LeavingBackgroundEventArgs : llm::OS::ApplicationModel::ILeavingBackgroundEventArgs
    {
        LeavingBackgroundEventArgs(std::nullptr_t) noexcept {}
        LeavingBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ILeavingBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LimitedAccessFeatureRequestResult : llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult
    {
        LimitedAccessFeatureRequestResult(std::nullptr_t) noexcept {}
        LimitedAccessFeatureRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct LimitedAccessFeatures
    {
        LimitedAccessFeatures() = delete;
        static auto TryUnlockFeature(param::hstring const& featureId, param::hstring const& token, param::hstring const& attestation);
    };
    struct __declspec(empty_bases) Package : llm::OS::ApplicationModel::IPackage,
        impl::require<Package, llm::OS::ApplicationModel::IPackage2, llm::OS::ApplicationModel::IPackage3, llm::OS::ApplicationModel::IPackageWithMetadata, llm::OS::ApplicationModel::IPackage4, llm::OS::ApplicationModel::IPackage5, llm::OS::ApplicationModel::IPackage6, llm::OS::ApplicationModel::IPackage7, llm::OS::ApplicationModel::IPackage8, llm::OS::ApplicationModel::IPackage9>
    {
        Package(std::nullptr_t) noexcept {}
        Package(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackage(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) PackageCatalog : llm::OS::ApplicationModel::IPackageCatalog,
        impl::require<PackageCatalog, llm::OS::ApplicationModel::IPackageCatalog2, llm::OS::ApplicationModel::IPackageCatalog3, llm::OS::ApplicationModel::IPackageCatalog4>
    {
        PackageCatalog(std::nullptr_t) noexcept {}
        PackageCatalog(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageCatalog(ptr, take_ownership_from_abi) {}
        static auto OpenForCurrentPackage();
        static auto OpenForCurrentUser();
        static auto OpenForPackage(llm::OS::ApplicationModel::Package const& package);
    };
    struct __declspec(empty_bases) PackageCatalogAddOptionalPackageResult : llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult
    {
        PackageCatalogAddOptionalPackageResult(std::nullptr_t) noexcept {}
        PackageCatalogAddOptionalPackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageCatalogAddResourcePackageResult : llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult
    {
        PackageCatalogAddResourcePackageResult(std::nullptr_t) noexcept {}
        PackageCatalogAddResourcePackageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageCatalogRemoveOptionalPackagesResult : llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult
    {
        PackageCatalogRemoveOptionalPackagesResult(std::nullptr_t) noexcept {}
        PackageCatalogRemoveOptionalPackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageCatalogRemoveResourcePackagesResult : llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult
    {
        PackageCatalogRemoveResourcePackagesResult(std::nullptr_t) noexcept {}
        PackageCatalogRemoveResourcePackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageContentGroup : llm::OS::ApplicationModel::IPackageContentGroup
    {
        PackageContentGroup(std::nullptr_t) noexcept {}
        PackageContentGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageContentGroup(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto RequiredGroupName();
    };
    struct __declspec(empty_bases) PackageContentGroupStagingEventArgs : llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs
    {
        PackageContentGroupStagingEventArgs(std::nullptr_t) noexcept {}
        PackageContentGroupStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageId : llm::OS::ApplicationModel::IPackageId,
        impl::require<PackageId, llm::OS::ApplicationModel::IPackageIdWithMetadata>
    {
        PackageId(std::nullptr_t) noexcept {}
        PackageId(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageId(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageInstallingEventArgs : llm::OS::ApplicationModel::IPackageInstallingEventArgs
    {
        PackageInstallingEventArgs(std::nullptr_t) noexcept {}
        PackageInstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageInstallingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageStagingEventArgs : llm::OS::ApplicationModel::IPackageStagingEventArgs
    {
        PackageStagingEventArgs(std::nullptr_t) noexcept {}
        PackageStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageStagingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageStatus : llm::OS::ApplicationModel::IPackageStatus,
        impl::require<PackageStatus, llm::OS::ApplicationModel::IPackageStatus2>
    {
        PackageStatus(std::nullptr_t) noexcept {}
        PackageStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageStatusChangedEventArgs : llm::OS::ApplicationModel::IPackageStatusChangedEventArgs
    {
        PackageStatusChangedEventArgs(std::nullptr_t) noexcept {}
        PackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageUninstallingEventArgs : llm::OS::ApplicationModel::IPackageUninstallingEventArgs
    {
        PackageUninstallingEventArgs(std::nullptr_t) noexcept {}
        PackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageUninstallingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageUpdateAvailabilityResult : llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult
    {
        PackageUpdateAvailabilityResult(std::nullptr_t) noexcept {}
        PackageUpdateAvailabilityResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PackageUpdatingEventArgs : llm::OS::ApplicationModel::IPackageUpdatingEventArgs
    {
        PackageUpdatingEventArgs(std::nullptr_t) noexcept {}
        PackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IPackageUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StartupTask : llm::OS::ApplicationModel::IStartupTask
    {
        StartupTask(std::nullptr_t) noexcept {}
        StartupTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::IStartupTask(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentPackageAsync();
        static auto GetAsync(param::hstring const& taskId);
    };
    struct __declspec(empty_bases) SuspendingDeferral : llm::OS::ApplicationModel::ISuspendingDeferral
    {
        SuspendingDeferral(std::nullptr_t) noexcept {}
        SuspendingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ISuspendingDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SuspendingEventArgs : llm::OS::ApplicationModel::ISuspendingEventArgs
    {
        SuspendingEventArgs(std::nullptr_t) noexcept {}
        SuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ISuspendingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SuspendingOperation : llm::OS::ApplicationModel::ISuspendingOperation
    {
        SuspendingOperation(std::nullptr_t) noexcept {}
        SuspendingOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ISuspendingOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
