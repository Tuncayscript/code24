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
#ifndef LLM_OS_ApplicationModel_0_H
#define LLM_OS_ApplicationModel_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::Activation
{
    struct IActivatedEventArgs;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Core
{
    struct AppListEntry;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct HResult;
    struct IAsyncAction;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Size;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Storage
{
    struct StorageFolder;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct RandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::System
{
    enum class ProcessorArchitecture : int32_t;
    struct User;
}
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    enum class AddResourcePackageOptions : uint32_t
    {
        None = 0,
        ForceTargetAppShutdown = 0x1,
        ApplyUpdateIfAvailable = 0x2,
    };
    enum class AppExecutionContext : int32_t
    {
        Unknown = 0,
        Host = 1,
        Guest = 2,
    };
    enum class AppInstallerPolicySource : int32_t
    {
        Default = 0,
        System = 1,
    };
    enum class FullTrustLaunchResult : int32_t
    {
        Success = 0,
        AccessDenied = 1,
        FileNotFound = 2,
        Unknown = 3,
    };
    enum class LimitedAccessFeatureStatus : int32_t
    {
        Unavailable = 0,
        Available = 1,
        AvailableWithoutToken = 2,
        Unknown = 3,
    };
    enum class PackageContentGroupState : int32_t
    {
        NotStaged = 0,
        Queued = 1,
        Staging = 2,
        Staged = 3,
    };
    enum class PackageRelationship : int32_t
    {
        Dependencies = 0,
        Dependents = 1,
        All = 2,
    };
    enum class PackageSignatureKind : int32_t
    {
        None = 0,
        Developer = 1,
        Enterprise = 2,
        Store = 3,
        System = 4,
    };
    enum class PackageUpdateAvailability : int32_t
    {
        Unknown = 0,
        NoUpdates = 1,
        Available = 2,
        Required = 3,
        Error = 4,
    };
    enum class StartupTaskState : int32_t
    {
        Disabled = 0,
        DisabledByUser = 1,
        Enabled = 2,
        DisabledByPolicy = 3,
        EnabledByPolicy = 4,
    };
    struct IAppDisplayInfo;
    struct IAppInfo;
    struct IAppInfo2;
    struct IAppInfo3;
    struct IAppInfo4;
    struct IAppInfoStatics;
    struct IAppInstallerInfo;
    struct IAppInstallerInfo2;
    struct IAppInstance;
    struct IAppInstanceStatics;
    struct IDesignModeStatics;
    struct IDesignModeStatics2;
    struct IEnteredBackgroundEventArgs;
    struct IFindRelatedPackagesOptions;
    struct IFindRelatedPackagesOptionsFactory;
    struct IFullTrustProcessLaunchResult;
    struct IFullTrustProcessLauncherStatics;
    struct IFullTrustProcessLauncherStatics2;
    struct ILeavingBackgroundEventArgs;
    struct ILimitedAccessFeatureRequestResult;
    struct ILimitedAccessFeaturesStatics;
    struct IPackage;
    struct IPackage2;
    struct IPackage3;
    struct IPackage4;
    struct IPackage5;
    struct IPackage6;
    struct IPackage7;
    struct IPackage8;
    struct IPackage9;
    struct IPackageCatalog;
    struct IPackageCatalog2;
    struct IPackageCatalog3;
    struct IPackageCatalog4;
    struct IPackageCatalogAddOptionalPackageResult;
    struct IPackageCatalogAddResourcePackageResult;
    struct IPackageCatalogRemoveOptionalPackagesResult;
    struct IPackageCatalogRemoveResourcePackagesResult;
    struct IPackageCatalogStatics;
    struct IPackageCatalogStatics2;
    struct IPackageContentGroup;
    struct IPackageContentGroupStagingEventArgs;
    struct IPackageContentGroupStatics;
    struct IPackageId;
    struct IPackageIdWithMetadata;
    struct IPackageInstallingEventArgs;
    struct IPackageStagingEventArgs;
    struct IPackageStatics;
    struct IPackageStatus;
    struct IPackageStatus2;
    struct IPackageStatusChangedEventArgs;
    struct IPackageUninstallingEventArgs;
    struct IPackageUpdateAvailabilityResult;
    struct IPackageUpdatingEventArgs;
    struct IPackageWithMetadata;
    struct IStartupTask;
    struct IStartupTaskStatics;
    struct ISuspendingDeferral;
    struct ISuspendingEventArgs;
    struct ISuspendingOperation;
    struct AppDisplayInfo;
    struct AppInfo;
    struct AppInstallerInfo;
    struct AppInstance;
    struct DesignMode;
    struct EnteredBackgroundEventArgs;
    struct FindRelatedPackagesOptions;
    struct FullTrustProcessLaunchResult;
    struct FullTrustProcessLauncher;
    struct LeavingBackgroundEventArgs;
    struct LimitedAccessFeatureRequestResult;
    struct LimitedAccessFeatures;
    struct Package;
    struct PackageCatalog;
    struct PackageCatalogAddOptionalPackageResult;
    struct PackageCatalogAddResourcePackageResult;
    struct PackageCatalogRemoveOptionalPackagesResult;
    struct PackageCatalogRemoveResourcePackagesResult;
    struct PackageContentGroup;
    struct PackageContentGroupStagingEventArgs;
    struct PackageId;
    struct PackageInstallingEventArgs;
    struct PackageStagingEventArgs;
    struct PackageStatus;
    struct PackageStatusChangedEventArgs;
    struct PackageUninstallingEventArgs;
    struct PackageUpdateAvailabilityResult;
    struct PackageUpdatingEventArgs;
    struct StartupTask;
    struct SuspendingDeferral;
    struct SuspendingEventArgs;
    struct SuspendingOperation;
    struct PackageInstallProgress;
    struct PackageVersion;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::IAppDisplayInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInfo2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInfo3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInfo4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInfoStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInstallerInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInstallerInfo2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInstance>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IAppInstanceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IDesignModeStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IDesignModeStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IFindRelatedPackagesOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage5>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage6>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage7>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage8>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackage9>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalog>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalog2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalog3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalog4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageCatalogStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageContentGroup>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageContentGroupStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageId>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageIdWithMetadata>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageInstallingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageStagingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageStatus>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageStatus2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageUninstallingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageUpdatingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IPackageWithMetadata>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IStartupTask>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::IStartupTaskStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ISuspendingDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ISuspendingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ISuspendingOperation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppDisplayInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppInstallerInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppInstance>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::DesignMode>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::EnteredBackgroundEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::FindRelatedPackagesOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::FullTrustProcessLauncher>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LeavingBackgroundEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::LimitedAccessFeatures>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Package>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageCatalog>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageContentGroup>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageId>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageInstallingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageStagingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageStatus>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageStatusChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageUninstallingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageUpdatingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::StartupTask>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SuspendingDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SuspendingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SuspendingOperation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AddResourcePackageOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExecutionContext>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::AppInstallerPolicySource>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::FullTrustLaunchResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::LimitedAccessFeatureStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageContentGroupState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageRelationship>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageSignatureKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageUpdateAvailability>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::StartupTaskState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::PackageInstallProgress>{ using type = struct_category<uint32_t>; };
    template <> struct category<llm::OS::ApplicationModel::PackageVersion>{ using type = struct_category<uint16_t, uint16_t, uint16_t, uint16_t>; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppDisplayInfo> = L"Windows.ApplicationModel.AppDisplayInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppInfo> = L"Windows.ApplicationModel.AppInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppInstallerInfo> = L"Windows.ApplicationModel.AppInstallerInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppInstance> = L"Windows.ApplicationModel.AppInstance";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::DesignMode> = L"Windows.ApplicationModel.DesignMode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::EnteredBackgroundEventArgs> = L"Windows.ApplicationModel.EnteredBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::FindRelatedPackagesOptions> = L"Windows.ApplicationModel.FindRelatedPackagesOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::FullTrustProcessLaunchResult> = L"Windows.ApplicationModel.FullTrustProcessLaunchResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::FullTrustProcessLauncher> = L"Windows.ApplicationModel.FullTrustProcessLauncher";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LeavingBackgroundEventArgs> = L"Windows.ApplicationModel.LeavingBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult> = L"Windows.ApplicationModel.LimitedAccessFeatureRequestResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LimitedAccessFeatures> = L"Windows.ApplicationModel.LimitedAccessFeatures";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Package> = L"Windows.ApplicationModel.Package";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageCatalog> = L"Windows.ApplicationModel.PackageCatalog";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult> = L"Windows.ApplicationModel.PackageCatalogAddOptionalPackageResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult> = L"Windows.ApplicationModel.PackageCatalogAddResourcePackageResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult> = L"Windows.ApplicationModel.PackageCatalogRemoveOptionalPackagesResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult> = L"Windows.ApplicationModel.PackageCatalogRemoveResourcePackagesResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageContentGroup> = L"Windows.ApplicationModel.PackageContentGroup";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> = L"Windows.ApplicationModel.PackageContentGroupStagingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageId> = L"Windows.ApplicationModel.PackageId";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageInstallingEventArgs> = L"Windows.ApplicationModel.PackageInstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageStagingEventArgs> = L"Windows.ApplicationModel.PackageStagingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageStatus> = L"Windows.ApplicationModel.PackageStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageStatusChangedEventArgs> = L"Windows.ApplicationModel.PackageStatusChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageUninstallingEventArgs> = L"Windows.ApplicationModel.PackageUninstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult> = L"Windows.ApplicationModel.PackageUpdateAvailabilityResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageUpdatingEventArgs> = L"Windows.ApplicationModel.PackageUpdatingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::StartupTask> = L"Windows.ApplicationModel.StartupTask";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SuspendingDeferral> = L"Windows.ApplicationModel.SuspendingDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SuspendingEventArgs> = L"Windows.ApplicationModel.SuspendingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SuspendingOperation> = L"Windows.ApplicationModel.SuspendingOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AddResourcePackageOptions> = L"Windows.ApplicationModel.AddResourcePackageOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExecutionContext> = L"Windows.ApplicationModel.AppExecutionContext";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppInstallerPolicySource> = L"Windows.ApplicationModel.AppInstallerPolicySource";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::FullTrustLaunchResult> = L"Windows.ApplicationModel.FullTrustLaunchResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::LimitedAccessFeatureStatus> = L"Windows.ApplicationModel.LimitedAccessFeatureStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageContentGroupState> = L"Windows.ApplicationModel.PackageContentGroupState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageRelationship> = L"Windows.ApplicationModel.PackageRelationship";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageSignatureKind> = L"Windows.ApplicationModel.PackageSignatureKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageUpdateAvailability> = L"Windows.ApplicationModel.PackageUpdateAvailability";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::StartupTaskState> = L"Windows.ApplicationModel.StartupTaskState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageInstallProgress> = L"Windows.ApplicationModel.PackageInstallProgress";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::PackageVersion> = L"Windows.ApplicationModel.PackageVersion";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppDisplayInfo> = L"Windows.ApplicationModel.IAppDisplayInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInfo> = L"Windows.ApplicationModel.IAppInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInfo2> = L"Windows.ApplicationModel.IAppInfo2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInfo3> = L"Windows.ApplicationModel.IAppInfo3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInfo4> = L"Windows.ApplicationModel.IAppInfo4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInfoStatics> = L"Windows.ApplicationModel.IAppInfoStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInstallerInfo> = L"Windows.ApplicationModel.IAppInstallerInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInstallerInfo2> = L"Windows.ApplicationModel.IAppInstallerInfo2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInstance> = L"Windows.ApplicationModel.IAppInstance";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IAppInstanceStatics> = L"Windows.ApplicationModel.IAppInstanceStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IDesignModeStatics> = L"Windows.ApplicationModel.IDesignModeStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IDesignModeStatics2> = L"Windows.ApplicationModel.IDesignModeStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs> = L"Windows.ApplicationModel.IEnteredBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IFindRelatedPackagesOptions> = L"Windows.ApplicationModel.IFindRelatedPackagesOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory> = L"Windows.ApplicationModel.IFindRelatedPackagesOptionsFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult> = L"Windows.ApplicationModel.IFullTrustProcessLaunchResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics> = L"Windows.ApplicationModel.IFullTrustProcessLauncherStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2> = L"Windows.ApplicationModel.IFullTrustProcessLauncherStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs> = L"Windows.ApplicationModel.ILeavingBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult> = L"Windows.ApplicationModel.ILimitedAccessFeatureRequestResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics> = L"Windows.ApplicationModel.ILimitedAccessFeaturesStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage> = L"Windows.ApplicationModel.IPackage";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage2> = L"Windows.ApplicationModel.IPackage2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage3> = L"Windows.ApplicationModel.IPackage3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage4> = L"Windows.ApplicationModel.IPackage4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage5> = L"Windows.ApplicationModel.IPackage5";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage6> = L"Windows.ApplicationModel.IPackage6";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage7> = L"Windows.ApplicationModel.IPackage7";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage8> = L"Windows.ApplicationModel.IPackage8";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackage9> = L"Windows.ApplicationModel.IPackage9";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalog> = L"Windows.ApplicationModel.IPackageCatalog";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalog2> = L"Windows.ApplicationModel.IPackageCatalog2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalog3> = L"Windows.ApplicationModel.IPackageCatalog3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalog4> = L"Windows.ApplicationModel.IPackageCatalog4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult> = L"Windows.ApplicationModel.IPackageCatalogAddOptionalPackageResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult> = L"Windows.ApplicationModel.IPackageCatalogAddResourcePackageResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult> = L"Windows.ApplicationModel.IPackageCatalogRemoveOptionalPackagesResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult> = L"Windows.ApplicationModel.IPackageCatalogRemoveResourcePackagesResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogStatics> = L"Windows.ApplicationModel.IPackageCatalogStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageCatalogStatics2> = L"Windows.ApplicationModel.IPackageCatalogStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageContentGroup> = L"Windows.ApplicationModel.IPackageContentGroup";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs> = L"Windows.ApplicationModel.IPackageContentGroupStagingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageContentGroupStatics> = L"Windows.ApplicationModel.IPackageContentGroupStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageId> = L"Windows.ApplicationModel.IPackageId";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageIdWithMetadata> = L"Windows.ApplicationModel.IPackageIdWithMetadata";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageInstallingEventArgs> = L"Windows.ApplicationModel.IPackageInstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageStagingEventArgs> = L"Windows.ApplicationModel.IPackageStagingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageStatics> = L"Windows.ApplicationModel.IPackageStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageStatus> = L"Windows.ApplicationModel.IPackageStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageStatus2> = L"Windows.ApplicationModel.IPackageStatus2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs> = L"Windows.ApplicationModel.IPackageStatusChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageUninstallingEventArgs> = L"Windows.ApplicationModel.IPackageUninstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult> = L"Windows.ApplicationModel.IPackageUpdateAvailabilityResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageUpdatingEventArgs> = L"Windows.ApplicationModel.IPackageUpdatingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IPackageWithMetadata> = L"Windows.ApplicationModel.IPackageWithMetadata";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IStartupTask> = L"Windows.ApplicationModel.IStartupTask";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::IStartupTaskStatics> = L"Windows.ApplicationModel.IStartupTaskStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ISuspendingDeferral> = L"Windows.ApplicationModel.ISuspendingDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ISuspendingEventArgs> = L"Windows.ApplicationModel.ISuspendingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ISuspendingOperation> = L"Windows.ApplicationModel.ISuspendingOperation";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppDisplayInfo>{ 0x1AEB1103,0xE4D4,0x41AA,{ 0xA4,0xF6,0xC4,0xA2,0x76,0xE7,0x9E,0xAC } }; // 1AEB1103-E4D4-41AA-A4F6-C4A276E79EAC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInfo>{ 0xCF7F59B3,0x6A09,0x4DE8,{ 0xA6,0xC0,0x57,0x92,0xD5,0x68,0x80,0xD1 } }; // CF7F59B3-6A09-4DE8-A6C0-5792D56880D1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInfo2>{ 0xBE4B1F5A,0x2098,0x431B,{ 0xBD,0x25,0xB3,0x08,0x78,0x74,0x8D,0x47 } }; // BE4B1F5A-2098-431B-BD25-B30878748D47
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInfo3>{ 0x09A78E46,0x93A4,0x46DE,{ 0x93,0x97,0x08,0x43,0xB5,0x71,0x15,0xEA } }; // 09A78E46-93A4-46DE-9397-0843B57115EA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInfo4>{ 0x2F34BDEB,0x1609,0x4554,{ 0x9F,0x33,0x12,0xE1,0xE8,0x03,0xE0,0xD4 } }; // 2F34BDEB-1609-4554-9F33-12E1E803E0D4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInfoStatics>{ 0xCF1F782A,0xE48B,0x4F0C,{ 0x9B,0x0B,0x79,0xC3,0xF8,0x95,0x7D,0xD7 } }; // CF1F782A-E48B-4F0C-9B0B-79C3F8957DD7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInstallerInfo>{ 0x29AB2AC0,0xD4F6,0x42A3,{ 0xAD,0xCD,0xD6,0x58,0x3C,0x65,0x95,0x08 } }; // 29AB2AC0-D4F6-42A3-ADCD-D6583C659508
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInstallerInfo2>{ 0xD20F1388,0x8256,0x597C,{ 0x85,0x11,0xC8,0x4E,0xC5,0x0D,0x5E,0x2B } }; // D20F1388-8256-597C-8511-C84EC50D5E2B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInstance>{ 0x675F2B47,0xF25F,0x4532,{ 0x9F,0xD6,0x36,0x33,0xE0,0x63,0x4D,0x01 } }; // 675F2B47-F25F-4532-9FD6-3633E0634D01
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IAppInstanceStatics>{ 0x9D11E77F,0x9EA6,0x47AF,{ 0xA6,0xEC,0x46,0x78,0x4C,0x5B,0xA2,0x54 } }; // 9D11E77F-9EA6-47AF-A6EC-46784C5BA254
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IDesignModeStatics>{ 0x2C3893CC,0xF81A,0x4E7A,{ 0xB8,0x57,0x76,0xA8,0x08,0x87,0xE1,0x85 } }; // 2C3893CC-F81A-4E7A-B857-76A80887E185
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IDesignModeStatics2>{ 0x80CF8137,0xB064,0x4858,{ 0xBE,0xC8,0x3E,0xBA,0x22,0x35,0x75,0x35 } }; // 80CF8137-B064-4858-BEC8-3EBA22357535
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs>{ 0xF722DCC2,0x9827,0x403D,{ 0xAA,0xED,0xEC,0xCA,0x9A,0xC1,0x73,0x98 } }; // F722DCC2-9827-403D-AAED-ECCA9AC17398
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IFindRelatedPackagesOptions>{ 0x41DD7EEA,0xB335,0x521F,{ 0xB9,0x6C,0x5E,0xA0,0x7F,0x5B,0x73,0x29 } }; // 41DD7EEA-B335-521F-B96C-5EA07F5B7329
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory>{ 0xD7D17254,0xA4FD,0x55C4,{ 0x98,0xCF,0xF2,0x71,0x0B,0x7D,0x8B,0xE2 } }; // D7D17254-A4FD-55C4-98CF-F2710B7D8BE2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult>{ 0x8917D888,0xEDFB,0x515F,{ 0x8E,0x22,0x5E,0xBC,0xEB,0x69,0xDF,0xD9 } }; // 8917D888-EDFB-515F-8E22-5EBCEB69DFD9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics>{ 0xD784837F,0x1100,0x3C6B,{ 0xA4,0x55,0xF6,0x26,0x2C,0xC3,0x31,0xB6 } }; // D784837F-1100-3C6B-A455-F6262CC331B6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2>{ 0x8B8ED72F,0xB65C,0x56CF,{ 0xA1,0xA7,0x2B,0xF7,0x7C,0xBC,0x6E,0xA8 } }; // 8B8ED72F-B65C-56CF-A1A7-2BF77CBC6EA8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs>{ 0x39C6EC9A,0xAE6E,0x46F9,{ 0xA0,0x7A,0xCF,0xC2,0x3F,0x88,0x73,0x3E } }; // 39C6EC9A-AE6E-46F9-A07A-CFC23F88733E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult>{ 0xD45156A6,0x1E24,0x5DDD,{ 0xAB,0xB4,0x61,0x88,0xAB,0xA4,0xD5,0xBF } }; // D45156A6-1E24-5DDD-ABB4-6188ABA4D5BF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics>{ 0x8BE612D4,0x302B,0x5FBF,{ 0xA6,0x32,0x1A,0x99,0xE4,0x3E,0x89,0x25 } }; // 8BE612D4-302B-5FBF-A632-1A99E43E8925
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage>{ 0x163C792F,0xBD75,0x413C,{ 0xBF,0x23,0xB1,0xFE,0x7B,0x95,0xD8,0x25 } }; // 163C792F-BD75-413C-BF23-B1FE7B95D825
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage2>{ 0xA6612FB6,0x7688,0x4ACE,{ 0x95,0xFB,0x35,0x95,0x38,0xE7,0xAA,0x01 } }; // A6612FB6-7688-4ACE-95FB-359538E7AA01
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage3>{ 0x5F738B61,0xF86A,0x4917,{ 0x93,0xD1,0xF1,0xEE,0x9D,0x3B,0x35,0xD9 } }; // 5F738B61-F86A-4917-93D1-F1EE9D3B35D9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage4>{ 0x65AED1AE,0xB95B,0x450C,{ 0x88,0x2B,0x62,0x55,0x18,0x7F,0x39,0x7E } }; // 65AED1AE-B95B-450C-882B-6255187F397E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage5>{ 0x0E842DD4,0xD9AC,0x45ED,{ 0x9A,0x1E,0x74,0xCE,0x05,0x6B,0x26,0x35 } }; // 0E842DD4-D9AC-45ED-9A1E-74CE056B2635
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage6>{ 0x8B1AD942,0x12D7,0x4754,{ 0xAE,0x4E,0x63,0x8C,0xBC,0x0E,0x3A,0x2E } }; // 8B1AD942-12D7-4754-AE4E-638CBC0E3A2E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage7>{ 0x86FF8D31,0xA2E4,0x45E0,{ 0x97,0x32,0x28,0x3A,0x6D,0x88,0xFD,0xE1 } }; // 86FF8D31-A2E4-45E0-9732-283A6D88FDE1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage8>{ 0x2C584F7B,0xCE2A,0x4BE6,{ 0xA0,0x93,0x77,0xCF,0xBB,0x2A,0x7E,0xA1 } }; // 2C584F7B-CE2A-4BE6-A093-77CFBB2A7EA1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackage9>{ 0xD5AB224F,0xD7E1,0x49EC,{ 0x90,0xCE,0x72,0x0C,0xDB,0xD0,0x2E,0x9C } }; // D5AB224F-D7E1-49EC-90CE-720CDBD02E9C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalog>{ 0x230A3751,0x9DE3,0x4445,{ 0xBE,0x74,0x91,0xFB,0x32,0x5A,0xBE,0xFE } }; // 230A3751-9DE3-4445-BE74-91FB325ABEFE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalog2>{ 0x96A60C36,0x8FF7,0x4344,{ 0xB6,0xBF,0xEE,0x64,0xC2,0x20,0x7E,0xD2 } }; // 96A60C36-8FF7-4344-B6BF-EE64C2207ED2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalog3>{ 0x96DD5C88,0x8837,0x43F9,{ 0x90,0x15,0x03,0x34,0x34,0xBA,0x14,0xF3 } }; // 96DD5C88-8837-43F9-9015-033434BA14F3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalog4>{ 0xC37C399B,0x44CC,0x4B7B,{ 0x8B,0xAF,0x79,0x6C,0x04,0xEA,0xD3,0xB9 } }; // C37C399B-44CC-4B7B-8BAF-796C04EAD3B9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult>{ 0x3BF10CD4,0xB4DF,0x47B3,{ 0xA9,0x63,0xE2,0xFA,0x83,0x2F,0x7D,0xD3 } }; // 3BF10CD4-B4DF-47B3-A963-E2FA832F7DD3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult>{ 0x9636CE0D,0x3E17,0x493F,{ 0xAA,0x08,0xCC,0xEC,0x6F,0xDE,0xF6,0x99 } }; // 9636CE0D-3E17-493F-AA08-CCEC6FDEF699
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult>{ 0x29D2F97B,0xD974,0x4E64,{ 0x93,0x59,0x22,0xCA,0xDF,0xD7,0x98,0x28 } }; // 29D2F97B-D974-4E64-9359-22CADFD79828
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult>{ 0xAE719709,0x1A52,0x4321,{ 0x87,0xB3,0xE5,0xA1,0xA1,0x79,0x81,0xA7 } }; // AE719709-1A52-4321-87B3-E5A1A17981A7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogStatics>{ 0xA18C9696,0xE65B,0x4634,{ 0xBA,0x21,0x5E,0x63,0xEB,0x72,0x44,0xA7 } }; // A18C9696-E65B-4634-BA21-5E63EB7244A7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageCatalogStatics2>{ 0x4C11C159,0x9A28,0x598C,{ 0xB1,0x85,0x55,0xE1,0x89,0x9B,0x2B,0xE4 } }; // 4C11C159-9A28-598C-B185-55E1899B2BE4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageContentGroup>{ 0x8F62695D,0x120A,0x4798,{ 0xB5,0xE1,0x58,0x00,0xDD,0xA8,0xF2,0xE1 } }; // 8F62695D-120A-4798-B5E1-5800DDA8F2E1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs>{ 0x3D7BC27E,0x6F27,0x446C,{ 0x98,0x6E,0xD4,0x73,0x3D,0x4D,0x91,0x13 } }; // 3D7BC27E-6F27-446C-986E-D4733D4D9113
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageContentGroupStatics>{ 0x70EE7619,0x5F12,0x4B92,{ 0xB9,0xEA,0x6C,0xCA,0xDA,0x13,0xBC,0x75 } }; // 70EE7619-5F12-4B92-B9EA-6CCADA13BC75
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageId>{ 0x1ADB665E,0x37C7,0x4790,{ 0x99,0x80,0xDD,0x7A,0xE7,0x4E,0x8B,0xB2 } }; // 1ADB665E-37C7-4790-9980-DD7AE74E8BB2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageIdWithMetadata>{ 0x40577A7C,0x0C9E,0x443D,{ 0x90,0x74,0x85,0x5F,0x5C,0xE0,0xA0,0x8D } }; // 40577A7C-0C9E-443D-9074-855F5CE0A08D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageInstallingEventArgs>{ 0x97741EB7,0xAB7A,0x401A,{ 0x8B,0x61,0xEB,0x0E,0x7F,0xAF,0xF2,0x37 } }; // 97741EB7-AB7A-401A-8B61-EB0E7FAFF237
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageStagingEventArgs>{ 0x1041682D,0x54E2,0x4F51,{ 0xB8,0x28,0x9E,0xF7,0x04,0x6C,0x21,0x0F } }; // 1041682D-54E2-4F51-B828-9EF7046C210F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageStatics>{ 0x4E534BDF,0x2960,0x4878,{ 0x97,0xA4,0x96,0x24,0xDE,0xB7,0x2F,0x2D } }; // 4E534BDF-2960-4878-97A4-9624DEB72F2D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageStatus>{ 0x5FE74F71,0xA365,0x4C09,{ 0xA0,0x2D,0x04,0x6D,0x52,0x5E,0xA1,0xDA } }; // 5FE74F71-A365-4C09-A02D-046D525EA1DA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageStatus2>{ 0xF428FA93,0x7C56,0x4862,{ 0xAC,0xFA,0xAB,0xAE,0xDC,0xC0,0x69,0x4D } }; // F428FA93-7C56-4862-ACFA-ABAEDCC0694D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs>{ 0x437D714D,0xBD80,0x4A70,{ 0xBC,0x50,0xF6,0xE7,0x96,0x50,0x95,0x75 } }; // 437D714D-BD80-4A70-BC50-F6E796509575
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageUninstallingEventArgs>{ 0x4443AA52,0xAB22,0x44CD,{ 0x82,0xBB,0x4E,0xC9,0xB8,0x27,0x36,0x7A } }; // 4443AA52-AB22-44CD-82BB-4EC9B827367A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult>{ 0x114E5009,0x199A,0x48A1,{ 0xA0,0x79,0x31,0x3C,0x45,0x63,0x4A,0x71 } }; // 114E5009-199A-48A1-A079-313C45634A71
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageUpdatingEventArgs>{ 0xCD7B4228,0xFD74,0x443E,{ 0xB1,0x14,0x23,0xE6,0x77,0xB0,0xE8,0x6F } }; // CD7B4228-FD74-443E-B114-23E677B0E86F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IPackageWithMetadata>{ 0x95949780,0x1DE9,0x40F2,{ 0xB4,0x52,0x0D,0xE9,0xF1,0x91,0x00,0x12 } }; // 95949780-1DE9-40F2-B452-0DE9F1910012
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IStartupTask>{ 0xF75C23C8,0xB5F2,0x4F6C,{ 0x88,0xDD,0x36,0xCB,0x1D,0x59,0x9D,0x17 } }; // F75C23C8-B5F2-4F6C-88DD-36CB1D599D17
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::IStartupTaskStatics>{ 0xEE5B60BD,0xA148,0x41A7,{ 0xB2,0x6E,0xE8,0xB8,0x8A,0x1E,0x62,0xF8 } }; // EE5B60BD-A148-41A7-B26E-E8B88A1E62F8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ISuspendingDeferral>{ 0x59140509,0x8BC9,0x4EB4,{ 0xB6,0x36,0xDA,0xBD,0xC4,0xF4,0x6F,0x66 } }; // 59140509-8BC9-4EB4-B636-DABDC4F46F66
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ISuspendingEventArgs>{ 0x96061C05,0x2DBA,0x4D08,{ 0xB0,0xBD,0x2B,0x30,0xA1,0x31,0xC6,0xAA } }; // 96061C05-2DBA-4D08-B0BD-2B30A131C6AA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ISuspendingOperation>{ 0x9DA4CA41,0x20E1,0x4E9B,{ 0x9F,0x65,0xA9,0xF4,0x35,0x34,0x0C,0x3A } }; // 9DA4CA41-20E1-4E9B-9F65-A9F435340C3A
    template <> struct default_interface<llm::OS::ApplicationModel::AppDisplayInfo>{ using type = llm::OS::ApplicationModel::IAppDisplayInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppInfo>{ using type = llm::OS::ApplicationModel::IAppInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppInstallerInfo>{ using type = llm::OS::ApplicationModel::IAppInstallerInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppInstance>{ using type = llm::OS::ApplicationModel::IAppInstance; };
    template <> struct default_interface<llm::OS::ApplicationModel::EnteredBackgroundEventArgs>{ using type = llm::OS::ApplicationModel::IEnteredBackgroundEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::FindRelatedPackagesOptions>{ using type = llm::OS::ApplicationModel::IFindRelatedPackagesOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>{ using type = llm::OS::ApplicationModel::IFullTrustProcessLaunchResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::LeavingBackgroundEventArgs>{ using type = llm::OS::ApplicationModel::ILeavingBackgroundEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult>{ using type = llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::Package>{ using type = llm::OS::ApplicationModel::IPackage; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageCatalog>{ using type = llm::OS::ApplicationModel::IPackageCatalog; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>{ using type = llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult>{ using type = llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>{ using type = llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>{ using type = llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageContentGroup>{ using type = llm::OS::ApplicationModel::IPackageContentGroup; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs>{ using type = llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageId>{ using type = llm::OS::ApplicationModel::IPackageId; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageInstallingEventArgs>{ using type = llm::OS::ApplicationModel::IPackageInstallingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageStagingEventArgs>{ using type = llm::OS::ApplicationModel::IPackageStagingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageStatus>{ using type = llm::OS::ApplicationModel::IPackageStatus; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageStatusChangedEventArgs>{ using type = llm::OS::ApplicationModel::IPackageStatusChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageUninstallingEventArgs>{ using type = llm::OS::ApplicationModel::IPackageUninstallingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>{ using type = llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::PackageUpdatingEventArgs>{ using type = llm::OS::ApplicationModel::IPackageUpdatingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::StartupTask>{ using type = llm::OS::ApplicationModel::IStartupTask; };
    template <> struct default_interface<llm::OS::ApplicationModel::SuspendingDeferral>{ using type = llm::OS::ApplicationModel::ISuspendingDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::SuspendingEventArgs>{ using type = llm::OS::ApplicationModel::ISuspendingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::SuspendingOperation>{ using type = llm::OS::ApplicationModel::ISuspendingOperation; };
    template <> struct abi<llm::OS::ApplicationModel::IAppDisplayInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall GetLogo(llm::OS::Foundation::Size, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_AppUserModelId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayInfo(void**) noexcept = 0;
            virtual int32_t __stdcall get_PackageFamilyName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInfo3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExecutionContext(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInfo4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportedFileExtensions(uint32_t* __valueSize, void***) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
            virtual int32_t __stdcall GetFromAppUserModelId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetFromAppUserModelIdForUser(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInstallerInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInstallerInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OnLaunch(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HoursBetweenUpdateChecks(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ShowPrompt(bool*) noexcept = 0;
            virtual int32_t __stdcall get_UpdateBlocksActivation(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AutomaticBackgroundTask(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ForceUpdateFromAnyVersion(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsAutoRepairEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Version(struct struct_Windows_ApplicationModel_PackageVersion*) noexcept = 0;
            virtual int32_t __stdcall get_LastChecked(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PausedUntil(void**) noexcept = 0;
            virtual int32_t __stdcall get_UpdateUris(void**) noexcept = 0;
            virtual int32_t __stdcall get_RepairUris(void**) noexcept = 0;
            virtual int32_t __stdcall get_DependencyPackageUris(void**) noexcept = 0;
            virtual int32_t __stdcall get_OptionalPackageUris(void**) noexcept = 0;
            virtual int32_t __stdcall get_PolicySource(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInstance>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Key(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsCurrentInstance(bool*) noexcept = 0;
            virtual int32_t __stdcall RedirectActivationTo() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IAppInstanceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RecommendedInstance(void**) noexcept = 0;
            virtual int32_t __stdcall GetActivatedEventArgs(void**) noexcept = 0;
            virtual int32_t __stdcall FindOrRegisterInstanceForKey(void*, void**) noexcept = 0;
            virtual int32_t __stdcall Unregister() noexcept = 0;
            virtual int32_t __stdcall GetInstances(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IDesignModeStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesignModeEnabled(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IDesignModeStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesignMode2Enabled(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IFindRelatedPackagesOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Relationship(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Relationship(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IncludeFrameworks(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeFrameworks(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncludeHostRuntimes(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeHostRuntimes(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncludeOptionals(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeOptionals(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncludeResources(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeResources(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LaunchResult(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchFullTrustProcessForCurrentAppAsync(void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFullTrustProcessForCurrentAppWithParametersAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFullTrustProcessForAppAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFullTrustProcessForAppWithParametersAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LaunchFullTrustProcessForAppWithArgumentsAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FeatureId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_EstimatedRemovalDate(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryUnlockFeature(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstalledLocation(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsFramework(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Dependencies(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_PublisherDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Logo(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsResourcePackage(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsBundle(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDevelopmentMode(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstalledDate(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetAppListEntriesAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SignatureKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsOptional(bool*) noexcept = 0;
            virtual int32_t __stdcall VerifyContentIntegrityAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetContentGroupsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContentGroupAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall StageContentGroupsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall StageContentGroupsWithPriorityAsync(void*, bool, void**) noexcept = 0;
            virtual int32_t __stdcall SetInUseAsync(bool, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAppInstallerInfo(void**) noexcept = 0;
            virtual int32_t __stdcall CheckUpdateAvailabilityAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MutableLocation(void**) noexcept = 0;
            virtual int32_t __stdcall get_EffectiveLocation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EffectiveExternalLocation(void**) noexcept = 0;
            virtual int32_t __stdcall get_MachineExternalLocation(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserExternalLocation(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstalledPath(void**) noexcept = 0;
            virtual int32_t __stdcall get_MutablePath(void**) noexcept = 0;
            virtual int32_t __stdcall get_EffectivePath(void**) noexcept = 0;
            virtual int32_t __stdcall get_EffectiveExternalPath(void**) noexcept = 0;
            virtual int32_t __stdcall get_MachineExternalPath(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserExternalPath(void**) noexcept = 0;
            virtual int32_t __stdcall GetLogoAsRandomAccessStreamReference(llm::OS::Foundation::Size, void**) noexcept = 0;
            virtual int32_t __stdcall GetAppListEntries(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsStub(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackage9>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindRelatedPackages(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_SourceUriSchemeName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalog>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_PackageStaging(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageStaging(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageInstalling(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageInstalling(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageUpdating(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageUpdating(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageUninstalling(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageUninstalling(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageStatusChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalog2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_PackageContentGroupStaging(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageContentGroupStaging(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall AddOptionalPackageAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalog3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RemoveOptionalPackagesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalog4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddResourcePackageAsync(void*, void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveResourcePackagesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PackagesRemoved(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PackagesRemoved(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenForCurrentPackage(void**) noexcept = 0;
            virtual int32_t __stdcall OpenForCurrentUser(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageCatalogStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OpenForPackage(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageContentGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsRequired(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_ContentGroupName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsContentGroupRequired(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageContentGroupStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequiredGroupName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageId>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Version(struct struct_Windows_ApplicationModel_PackageVersion*) noexcept = 0;
            virtual int32_t __stdcall get_Architecture(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ResourceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Publisher(void**) noexcept = 0;
            virtual int32_t __stdcall get_PublisherId(void**) noexcept = 0;
            virtual int32_t __stdcall get_FullName(void**) noexcept = 0;
            virtual int32_t __stdcall get_FamilyName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageIdWithMetadata>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProductId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Author(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageInstallingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageStagingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageStatus>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall VerifyIsOK(bool*) noexcept = 0;
            virtual int32_t __stdcall get_NotAvailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_PackageOffline(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DataOffline(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Disabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_NeedsRemediation(bool*) noexcept = 0;
            virtual int32_t __stdcall get_LicenseIssue(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Modified(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Tampered(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DependencyIssue(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Servicing(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DeploymentInProgress(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageStatus2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsPartiallyStaged(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageUninstallingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Availability(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageUpdatingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivityId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_SourcePackage(void**) noexcept = 0;
            virtual int32_t __stdcall get_TargetPackage(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
            virtual int32_t __stdcall get_IsComplete(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ErrorCode(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IPackageWithMetadata>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InstallDate(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetThumbnailToken(void**) noexcept = 0;
            virtual int32_t __stdcall Launch(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IStartupTask>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestEnableAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Disable() noexcept = 0;
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TaskId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::IStartupTaskStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentPackageAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ISuspendingDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ISuspendingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SuspendingOperation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ISuspendingOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppDisplayInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) GetLogo(llm::OS::Foundation::Size const& size) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppDisplayInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppDisplayInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppUserModelId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppDisplayInfo) DisplayInfo() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageFamilyName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInfo2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInfo3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppExecutionContext) ExecutionContext() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInfo3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInfo3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInfo4
    {
        [[nodiscard]] LLM_IMPL_AUTO(com_array<hstring>) SupportedFileExtensions() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInfo4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInfo4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInfoStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) Current() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) GetFromAppUserModelId(param::hstring const& appUserModelId) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) GetFromAppUserModelIdForUser(llm::OS::System::User const& user, param::hstring const& appUserModelId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInfoStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInfoStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInstallerInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInstallerInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInstallerInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInstallerInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) OnLaunch() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) HoursBetweenUpdateChecks() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ShowPrompt() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) UpdateBlocksActivation() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutomaticBackgroundTask() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ForceUpdateFromAnyVersion() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAutoRepairEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageVersion) Version() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) LastChecked() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) PausedUntil() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) UpdateUris() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) RepairUris() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) DependencyPackageUris() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) OptionalPackageUris() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstallerPolicySource) PolicySource() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInstallerInfo2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInstallerInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInstance
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Key() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCurrentInstance() const;
        LLM_IMPL_AUTO(void) RedirectActivationTo() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInstance>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInstance<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IAppInstanceStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstance) RecommendedInstance() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::IActivatedEventArgs) GetActivatedEventArgs() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstance) FindOrRegisterInstanceForKey(param::hstring const& key) const;
        LLM_IMPL_AUTO(void) Unregister() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::AppInstance>) GetInstances() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IAppInstanceStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IAppInstanceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IDesignModeStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) DesignModeEnabled() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IDesignModeStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IDesignModeStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IDesignModeStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) DesignMode2Enabled() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IDesignModeStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IDesignModeStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IEnteredBackgroundEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IEnteredBackgroundEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IFindRelatedPackagesOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageRelationship) Relationship() const;
        LLM_IMPL_AUTO(void) Relationship(llm::OS::ApplicationModel::PackageRelationship const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeFrameworks() const;
        LLM_IMPL_AUTO(void) IncludeFrameworks(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeHostRuntimes() const;
        LLM_IMPL_AUTO(void) IncludeHostRuntimes(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeOptionals() const;
        LLM_IMPL_AUTO(void) IncludeOptionals(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeResources() const;
        LLM_IMPL_AUTO(void) IncludeResources(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IFindRelatedPackagesOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IFindRelatedPackagesOptionsFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::FindRelatedPackagesOptions) CreateInstance(llm::OS::ApplicationModel::PackageRelationship const& Relationship) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IFindRelatedPackagesOptionsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IFullTrustProcessLaunchResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::FullTrustLaunchResult) LaunchResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IFullTrustProcessLaunchResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) LaunchFullTrustProcessForCurrentAppAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) LaunchFullTrustProcessForCurrentAppAsync(param::hstring const& parameterGroupId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& parameterGroupId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>) LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(param::hstring const& commandLine) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>) LaunchFullTrustProcessForAppWithArgumentsAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& commandLine) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ILeavingBackgroundEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ILeavingBackgroundEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ILimitedAccessFeatureRequestResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FeatureId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::LimitedAccessFeatureStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) EstimatedRemovalDate() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ILimitedAccessFeatureRequestResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ILimitedAccessFeaturesStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult) TryUnlockFeature(param::hstring const& featureId, param::hstring const& token, param::hstring const& attestation) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ILimitedAccessFeaturesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageId) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) InstalledLocation() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFramework() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) Dependencies() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PublisherDisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) Logo() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsResourcePackage() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsBundle() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDevelopmentMode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) InstalledDate() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>>) GetAppListEntriesAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageSignatureKind) SignatureKind() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOptional() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) VerifyContentIntegrityAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage5
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) GetContentGroupsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageContentGroup>) GetContentGroupAsync(param::hstring const& name) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) StageContentGroupsAsync(param::async_iterable<hstring> const& names) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) StageContentGroupsAsync(param::async_iterable<hstring> const& names, bool moveToHeadOfQueue) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) SetInUseAsync(bool inUse) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage5>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage5<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage6
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstallerInfo) GetAppInstallerInfo() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>) CheckUpdateAvailabilityAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage6>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage6<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage7
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) MutableLocation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) EffectiveLocation() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage7>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage7<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage8
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) EffectiveExternalLocation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) MachineExternalLocation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) UserExternalLocation() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) InstalledPath() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MutablePath() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EffectivePath() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EffectiveExternalPath() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MachineExternalPath() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserExternalPath() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) GetLogoAsRandomAccessStreamReference(llm::OS::Foundation::Size const& size) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>) GetAppListEntries() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsStub() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage8>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage8<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackage9
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Package>) FindRelatedPackages(llm::OS::ApplicationModel::FindRelatedPackagesOptions const& options) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourceUriSchemeName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackage9>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackage9<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalog
    {
        LLM_IMPL_AUTO(llm::event_token) PackageStaging(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStagingEventArgs> const& handler) const;
        using PackageStaging_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog>::remove_PackageStaging>;
        [[nodiscard]] PackageStaging_revoker PackageStaging(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStagingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageStaging(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageInstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageInstallingEventArgs> const& handler) const;
        using PackageInstalling_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog>::remove_PackageInstalling>;
        [[nodiscard]] PackageInstalling_revoker PackageInstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageInstallingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageInstalling(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUpdatingEventArgs> const& handler) const;
        using PackageUpdating_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog>::remove_PackageUpdating>;
        [[nodiscard]] PackageUpdating_revoker PackageUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUpdatingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageUpdating(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageUninstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUninstallingEventArgs> const& handler) const;
        using PackageUninstalling_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog>::remove_PackageUninstalling>;
        [[nodiscard]] PackageUninstalling_revoker PackageUninstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUninstallingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageUninstalling(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStatusChangedEventArgs> const& handler) const;
        using PackageStatusChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog>::remove_PackageStatusChanged>;
        [[nodiscard]] PackageStatusChanged_revoker PackageStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStatusChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageStatusChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalog>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalog<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalog2
    {
        LLM_IMPL_AUTO(llm::event_token) PackageContentGroupStaging(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> const& handler) const;
        using PackageContentGroupStaging_revoker = impl::event_revoker<llm::OS::ApplicationModel::IPackageCatalog2, &impl::abi_t<llm::OS::ApplicationModel::IPackageCatalog2>::remove_PackageContentGroupStaging>;
        [[nodiscard]] PackageContentGroupStaging_revoker PackageContentGroupStaging(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageContentGroupStaging(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>) AddOptionalPackageAsync(param::hstring const& optionalPackageFamilyName) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalog2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalog2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalog3
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>) RemoveOptionalPackagesAsync(param::async_iterable<hstring> const& optionalPackageFamilyNames) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalog3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalog3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalog4
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult, llm::OS::ApplicationModel::PackageInstallProgress>) AddResourcePackageAsync(param::hstring const& resourcePackageFamilyName, param::hstring const& resourceID, llm::OS::ApplicationModel::AddResourcePackageOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>) RemoveResourcePackagesAsync(param::async_iterable<llm::OS::ApplicationModel::Package> const& resourcePackages) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalog4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalog4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogAddOptionalPackageResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogAddOptionalPackageResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogAddResourcePackageResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogAddResourcePackageResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogRemoveOptionalPackagesResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) PackagesRemoved() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogRemoveOptionalPackagesResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogRemoveResourcePackagesResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) PackagesRemoved() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogRemoveResourcePackagesResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) OpenForCurrentPackage() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) OpenForCurrentUser() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageCatalogStatics2
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) OpenForPackage(llm::OS::ApplicationModel::Package const& package) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageCatalogStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageCatalogStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageContentGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageContentGroupState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRequired() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageContentGroup>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageContentGroup<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContentGroupName() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsContentGroupRequired() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageContentGroupStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RequiredGroupName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageContentGroupStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageContentGroupStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageId
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageVersion) Version() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::ProcessorArchitecture) Architecture() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ResourceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Publisher() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PublisherId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FullName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FamilyName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageId>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageId<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageIdWithMetadata
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProductId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Author() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageIdWithMetadata>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageIdWithMetadata<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageInstallingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageInstallingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageStagingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageStagingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Current() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageStatus
    {
        LLM_IMPL_AUTO(bool) VerifyIsOK() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) NotAvailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) PackageOffline() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DataOffline() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Disabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) NeedsRemediation() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) LicenseIssue() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Modified() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Tampered() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DependencyIssue() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Servicing() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DeploymentInProgress() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageStatus>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageStatus<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageStatus2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsPartiallyStaged() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageStatus2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageStatus2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageStatusChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageStatusChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageUninstallingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageUninstallingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageUpdateAvailabilityResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageUpdateAvailability) Availability() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageUpdateAvailabilityResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageUpdatingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) ActivityId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) SourcePackage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) TargetPackage() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsComplete() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ErrorCode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageUpdatingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IPackageWithMetadata
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) InstallDate() const;
        LLM_IMPL_AUTO(hstring) GetThumbnailToken() const;
        LLM_IMPL_AUTO(void) Launch(param::hstring const& parameters) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IPackageWithMetadata>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IPackageWithMetadata<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IStartupTask
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTaskState>) RequestEnableAsync() const;
        LLM_IMPL_AUTO(void) Disable() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::StartupTaskState) State() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TaskId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IStartupTask>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IStartupTask<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_IStartupTaskStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::StartupTask>>) GetForCurrentPackageAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTask>) GetAsync(param::hstring const& taskId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::IStartupTaskStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_IStartupTaskStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ISuspendingDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ISuspendingDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ISuspendingDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ISuspendingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SuspendingOperation) SuspendingOperation() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ISuspendingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ISuspendingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ISuspendingOperation
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::SuspendingDeferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ISuspendingOperation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ISuspendingOperation<D>;
    };
    struct struct_Windows_ApplicationModel_PackageInstallProgress
    {
        uint32_t PercentComplete;
    };
    template <> struct abi<Windows::ApplicationModel::PackageInstallProgress>
    {
        using type = struct_Windows_ApplicationModel_PackageInstallProgress;
    };
    struct struct_Windows_ApplicationModel_PackageVersion
    {
        uint16_t Major;
        uint16_t Minor;
        uint16_t Build;
        uint16_t Revision;
    };
    template <> struct abi<Windows::ApplicationModel::PackageVersion>
    {
        using type = struct_Windows_ApplicationModel_PackageVersion;
    };
}
#endif
