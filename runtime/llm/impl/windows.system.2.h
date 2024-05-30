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
#ifndef LLM_OS_System_2_H
#define LLM_OS_System_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.System.RemoteSystems.1.h"
#include "llm/impl/Windows.System.1.h"
LLM_EXPORT namespace llm:OS::System
{
    struct DispatcherQueueHandler : llm:OS::Foundation::IUnknown
    {
        DispatcherQueueHandler(std::nullptr_t = nullptr) noexcept {}
        DispatcherQueueHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DispatcherQueueHandler(L lambda);
        template <typename F> DispatcherQueueHandler(F* function);
        template <typename O, typename M> DispatcherQueueHandler(O* object, M method);
        template <typename O, typename M> DispatcherQueueHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DispatcherQueueHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct __declspec(empty_bases) AppActivationResult : llm:OS::System::IAppActivationResult
    {
        AppActivationResult(std::nullptr_t) noexcept {}
        AppActivationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppActivationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppDiagnosticInfo : llm:OS::System::IAppDiagnosticInfo,
        impl::require<AppDiagnosticInfo, llm:OS::System::IAppDiagnosticInfo2, llm:OS::System::IAppDiagnosticInfo3>
    {
        AppDiagnosticInfo(std::nullptr_t) noexcept {}
        AppDiagnosticInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppDiagnosticInfo(ptr, take_ownership_from_abi) {}
        static auto RequestInfoAsync();
        static auto CreateWatcher();
        static auto RequestAccessAsync();
        static auto RequestInfoForPackageAsync(param::hstring const& packageFamilyName);
        static auto RequestInfoForAppAsync();
        static auto RequestInfoForAppAsync(param::hstring const& appUserModelId);
    };
    struct __declspec(empty_bases) AppDiagnosticInfoWatcher : llm:OS::System::IAppDiagnosticInfoWatcher
    {
        AppDiagnosticInfoWatcher(std::nullptr_t) noexcept {}
        AppDiagnosticInfoWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppDiagnosticInfoWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppDiagnosticInfoWatcherEventArgs : llm:OS::System::IAppDiagnosticInfoWatcherEventArgs
    {
        AppDiagnosticInfoWatcherEventArgs(std::nullptr_t) noexcept {}
        AppDiagnosticInfoWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppDiagnosticInfoWatcherEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppExecutionStateChangeResult : llm:OS::System::IAppExecutionStateChangeResult
    {
        AppExecutionStateChangeResult(std::nullptr_t) noexcept {}
        AppExecutionStateChangeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppExecutionStateChangeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppMemoryReport : llm:OS::System::IAppMemoryReport,
        impl::require<AppMemoryReport, llm:OS::System::IAppMemoryReport2>
    {
        AppMemoryReport(std::nullptr_t) noexcept {}
        AppMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppMemoryReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppMemoryUsageLimitChangingEventArgs : llm:OS::System::IAppMemoryUsageLimitChangingEventArgs
    {
        AppMemoryUsageLimitChangingEventArgs(std::nullptr_t) noexcept {}
        AppMemoryUsageLimitChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppMemoryUsageLimitChangingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupBackgroundTaskReport : llm:OS::System::IAppResourceGroupBackgroundTaskReport
    {
        AppResourceGroupBackgroundTaskReport(std::nullptr_t) noexcept {}
        AppResourceGroupBackgroundTaskReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupBackgroundTaskReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupInfo : llm:OS::System::IAppResourceGroupInfo,
        impl::require<AppResourceGroupInfo, llm:OS::System::IAppResourceGroupInfo2>
    {
        AppResourceGroupInfo(std::nullptr_t) noexcept {}
        AppResourceGroupInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupInfoWatcher : llm:OS::System::IAppResourceGroupInfoWatcher
    {
        AppResourceGroupInfoWatcher(std::nullptr_t) noexcept {}
        AppResourceGroupInfoWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupInfoWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupInfoWatcherEventArgs : llm:OS::System::IAppResourceGroupInfoWatcherEventArgs
    {
        AppResourceGroupInfoWatcherEventArgs(std::nullptr_t) noexcept {}
        AppResourceGroupInfoWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupInfoWatcherEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupInfoWatcherExecutionStateChangedEventArgs : llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs
    {
        AppResourceGroupInfoWatcherExecutionStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppResourceGroupInfoWatcherExecutionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupInfoWatcherExecutionStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupMemoryReport : llm:OS::System::IAppResourceGroupMemoryReport
    {
        AppResourceGroupMemoryReport(std::nullptr_t) noexcept {}
        AppResourceGroupMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupMemoryReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppResourceGroupStateReport : llm:OS::System::IAppResourceGroupStateReport
    {
        AppResourceGroupStateReport(std::nullptr_t) noexcept {}
        AppResourceGroupStateReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppResourceGroupStateReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppUriHandlerHost : llm:OS::System::IAppUriHandlerHost,
        impl::require<AppUriHandlerHost, llm:OS::System::IAppUriHandlerHost2>
    {
        AppUriHandlerHost(std::nullptr_t) noexcept {}
        AppUriHandlerHost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppUriHandlerHost(ptr, take_ownership_from_abi) {}
        AppUriHandlerHost();
        explicit AppUriHandlerHost(param::hstring const& name);
    };
    struct __declspec(empty_bases) AppUriHandlerRegistration : llm:OS::System::IAppUriHandlerRegistration,
        impl::require<AppUriHandlerRegistration, llm:OS::System::IAppUriHandlerRegistration2>
    {
        AppUriHandlerRegistration(std::nullptr_t) noexcept {}
        AppUriHandlerRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppUriHandlerRegistration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppUriHandlerRegistrationManager : llm:OS::System::IAppUriHandlerRegistrationManager,
        impl::require<AppUriHandlerRegistrationManager, llm:OS::System::IAppUriHandlerRegistrationManager2>
    {
        AppUriHandlerRegistrationManager(std::nullptr_t) noexcept {}
        AppUriHandlerRegistrationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IAppUriHandlerRegistrationManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
        static auto GetForPackage(param::hstring const& packageFamilyName);
        static auto GetForPackageForUser(param::hstring const& packageFamilyName, llm:OS::System::User const& user);
    };
    struct DateTimeSettings
    {
        DateTimeSettings() = delete;
        static auto SetSystemDateTime(llm:OS::Foundation::DateTime const& utcDateTime);
    };
    struct __declspec(empty_bases) DispatcherQueue : llm:OS::System::IDispatcherQueue,
        impl::require<DispatcherQueue, llm:OS::System::IDispatcherQueue2>
    {
        DispatcherQueue(std::nullptr_t) noexcept {}
        DispatcherQueue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IDispatcherQueue(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentThread();
    };
    struct __declspec(empty_bases) DispatcherQueueController : llm:OS::System::IDispatcherQueueController
    {
        DispatcherQueueController(std::nullptr_t) noexcept {}
        DispatcherQueueController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IDispatcherQueueController(ptr, take_ownership_from_abi) {}
        static auto CreateOnDedicatedThread();
    };
    struct __declspec(empty_bases) DispatcherQueueShutdownStartingEventArgs : llm:OS::System::IDispatcherQueueShutdownStartingEventArgs
    {
        DispatcherQueueShutdownStartingEventArgs(std::nullptr_t) noexcept {}
        DispatcherQueueShutdownStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IDispatcherQueueShutdownStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DispatcherQueueTimer : llm:OS::System::IDispatcherQueueTimer
    {
        DispatcherQueueTimer(std::nullptr_t) noexcept {}
        DispatcherQueueTimer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IDispatcherQueueTimer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FolderLauncherOptions : llm:OS::System::IFolderLauncherOptions,
        impl::require<FolderLauncherOptions, llm:OS::System::ILauncherViewOptions>
    {
        FolderLauncherOptions(std::nullptr_t) noexcept {}
        FolderLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IFolderLauncherOptions(ptr, take_ownership_from_abi) {}
        FolderLauncherOptions();
    };
    struct KnownUserProperties
    {
        KnownUserProperties() = delete;
        [[nodiscard]] static auto DisplayName();
        [[nodiscard]] static auto FirstName();
        [[nodiscard]] static auto LastName();
        [[nodiscard]] static auto ProviderName();
        [[nodiscard]] static auto AccountName();
        [[nodiscard]] static auto GuestHost();
        [[nodiscard]] static auto PrincipalName();
        [[nodiscard]] static auto DomainName();
        [[nodiscard]] static auto SessionInitiationProtocolUri();
        [[nodiscard]] static auto AgeEnforcementRegion();
    };
    struct __declspec(empty_bases) LaunchUriResult : llm:OS::System::ILaunchUriResult
    {
        LaunchUriResult(std::nullptr_t) noexcept {}
        LaunchUriResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::ILaunchUriResult(ptr, take_ownership_from_abi) {}
    };
    struct Launcher
    {
        Launcher() = delete;
        static auto LaunchFileAsync(llm:OS::Storage::IStorageFile const& file);
        static auto LaunchFileAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::System::LauncherOptions const& options);
        static auto LaunchUriAsync(llm:OS::Foundation::Uri const& uri);
        static auto LaunchUriAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options);
        static auto LaunchUriForResultsAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options);
        static auto LaunchUriForResultsAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData);
        static auto LaunchUriAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData);
        static auto QueryUriSupportAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType);
        static auto QueryUriSupportAsync(llm:OS::Foundation::Uri const& uri, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType, param::hstring const& packageFamilyName);
        static auto QueryFileSupportAsync(llm:OS::Storage::StorageFile const& file);
        static auto QueryFileSupportAsync(llm:OS::Storage::StorageFile const& file, param::hstring const& packageFamilyName);
        static auto FindUriSchemeHandlersAsync(param::hstring const& scheme);
        static auto FindUriSchemeHandlersAsync(param::hstring const& scheme, llm:OS::System::LaunchQuerySupportType const& launchQuerySupportType);
        static auto FindFileHandlersAsync(param::hstring const& extension);
        static auto LaunchFolderAsync(llm:OS::Storage::IStorageFolder const& folder);
        static auto LaunchFolderAsync(llm:OS::Storage::IStorageFolder const& folder, llm:OS::System::FolderLauncherOptions const& options);
        static auto QueryAppUriSupportAsync(llm:OS::Foundation::Uri const& uri);
        static auto QueryAppUriSupportAsync(llm:OS::Foundation::Uri const& uri, param::hstring const& packageFamilyName);
        static auto FindAppUriHandlersAsync(llm:OS::Foundation::Uri const& uri);
        static auto LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri);
        static auto LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options);
        static auto LaunchUriForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData);
        static auto LaunchUriForResultsForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options);
        static auto LaunchUriForResultsForUserAsync(llm:OS::System::User const& user, llm:OS::Foundation::Uri const& uri, llm:OS::System::LauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData);
        static auto LaunchFolderPathAsync(param::hstring const& path);
        static auto LaunchFolderPathAsync(param::hstring const& path, llm:OS::System::FolderLauncherOptions const& options);
        static auto LaunchFolderPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path);
        static auto LaunchFolderPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path, llm:OS::System::FolderLauncherOptions const& options);
    };
    struct __declspec(empty_bases) LauncherOptions : llm:OS::System::ILauncherOptions,
        impl::require<LauncherOptions, llm:OS::System::ILauncherOptions2, llm:OS::System::ILauncherOptions3, llm:OS::System::ILauncherOptions4, llm:OS::System::ILauncherViewOptions>
    {
        LauncherOptions(std::nullptr_t) noexcept {}
        LauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::ILauncherOptions(ptr, take_ownership_from_abi) {}
        LauncherOptions();
    };
    struct __declspec(empty_bases) LauncherUIOptions : llm:OS::System::ILauncherUIOptions
    {
        LauncherUIOptions(std::nullptr_t) noexcept {}
        LauncherUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::ILauncherUIOptions(ptr, take_ownership_from_abi) {}
    };
    struct MemoryManager
    {
        MemoryManager() = delete;
        [[nodiscard]] static auto AppMemoryUsage();
        [[nodiscard]] static auto AppMemoryUsageLimit();
        [[nodiscard]] static auto AppMemoryUsageLevel();
        static auto AppMemoryUsageIncreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using AppMemoryUsageIncreased_revoker = impl::factory_event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageIncreased>;
        [[nodiscard]] static AppMemoryUsageIncreased_revoker AppMemoryUsageIncreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto AppMemoryUsageIncreased(llm::event_token const& token);
        static auto AppMemoryUsageDecreased(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using AppMemoryUsageDecreased_revoker = impl::factory_event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageDecreased>;
        [[nodiscard]] static AppMemoryUsageDecreased_revoker AppMemoryUsageDecreased(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto AppMemoryUsageDecreased(llm::event_token const& token);
        static auto AppMemoryUsageLimitChanging(llm:OS::Foundation::EventHandler<llm:OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler);
        using AppMemoryUsageLimitChanging_revoker = impl::factory_event_revoker<llm:OS::System::IMemoryManagerStatics, &impl::abi_t<llm:OS::System::IMemoryManagerStatics>::remove_AppMemoryUsageLimitChanging>;
        [[nodiscard]] static AppMemoryUsageLimitChanging_revoker AppMemoryUsageLimitChanging(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::System::AppMemoryUsageLimitChangingEventArgs> const& handler);
        static auto AppMemoryUsageLimitChanging(llm::event_token const& token);
        static auto GetAppMemoryReport();
        static auto GetProcessMemoryReport();
        static auto TrySetAppMemoryUsageLimit(uint64_t value);
        [[nodiscard]] static auto ExpectedAppMemoryUsageLimit();
    };
    struct ProcessLauncher
    {
        ProcessLauncher() = delete;
        static auto RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args);
        static auto RunToCompletionAsync(param::hstring const& fileName, param::hstring const& args, llm:OS::System::ProcessLauncherOptions const& options);
    };
    struct __declspec(empty_bases) ProcessLauncherOptions : llm:OS::System::IProcessLauncherOptions
    {
        ProcessLauncherOptions(std::nullptr_t) noexcept {}
        ProcessLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IProcessLauncherOptions(ptr, take_ownership_from_abi) {}
        ProcessLauncherOptions();
    };
    struct __declspec(empty_bases) ProcessLauncherResult : llm:OS::System::IProcessLauncherResult
    {
        ProcessLauncherResult(std::nullptr_t) noexcept {}
        ProcessLauncherResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IProcessLauncherResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProcessMemoryReport : llm:OS::System::IProcessMemoryReport
    {
        ProcessMemoryReport(std::nullptr_t) noexcept {}
        ProcessMemoryReport(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IProcessMemoryReport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtocolForResultsOperation : llm:OS::System::IProtocolForResultsOperation
    {
        ProtocolForResultsOperation(std::nullptr_t) noexcept {}
        ProtocolForResultsOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IProtocolForResultsOperation(ptr, take_ownership_from_abi) {}
    };
    struct RemoteLauncher
    {
        RemoteLauncher() = delete;
        static auto LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri);
        static auto LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri, llm:OS::System::RemoteLauncherOptions const& options);
        static auto LaunchUriAsync(llm:OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest, llm:OS::Foundation::Uri const& uri, llm:OS::System::RemoteLauncherOptions const& options, llm:OS::Foundation::Collections::ValueSet const& inputData);
    };
    struct __declspec(empty_bases) RemoteLauncherOptions : llm:OS::System::IRemoteLauncherOptions
    {
        RemoteLauncherOptions(std::nullptr_t) noexcept {}
        RemoteLauncherOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IRemoteLauncherOptions(ptr, take_ownership_from_abi) {}
        RemoteLauncherOptions();
    };
    struct ShutdownManager
    {
        ShutdownManager() = delete;
        static auto BeginShutdown(llm:OS::System::ShutdownKind const& shutdownKind, llm:OS::Foundation::TimeSpan const& timeout);
        static auto CancelShutdown();
        static auto IsPowerStateSupported(llm:OS::System::PowerState const& powerState);
        static auto EnterPowerState(llm:OS::System::PowerState const& powerState);
        static auto EnterPowerState(llm:OS::System::PowerState const& powerState, llm:OS::Foundation::TimeSpan const& wakeUpAfter);
    };
    struct TimeZoneSettings
    {
        TimeZoneSettings() = delete;
        [[nodiscard]] static auto CurrentTimeZoneDisplayName();
        [[nodiscard]] static auto SupportedTimeZoneDisplayNames();
        [[nodiscard]] static auto CanChangeTimeZone();
        static auto ChangeTimeZoneByDisplayName(param::hstring const& timeZoneDisplayName);
        static auto AutoUpdateTimeZoneAsync(llm:OS::Foundation::TimeSpan const& timeout);
    };
    struct __declspec(empty_bases) User : llm:OS::System::IUser,
        impl::require<User, llm:OS::System::IUser2>
    {
        User(std::nullptr_t) noexcept {}
        User(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUser(ptr, take_ownership_from_abi) {}
        static auto CreateWatcher();
        static auto FindAllAsync();
        static auto FindAllAsync(llm:OS::System::UserType const& type);
        static auto FindAllAsync(llm:OS::System::UserType const& type, llm:OS::System::UserAuthenticationStatus const& status);
        static auto GetFromId(param::hstring const& nonRoamableId);
        static auto GetDefault();
    };
    struct __declspec(empty_bases) UserAuthenticationStatusChangeDeferral : llm:OS::System::IUserAuthenticationStatusChangeDeferral
    {
        UserAuthenticationStatusChangeDeferral(std::nullptr_t) noexcept {}
        UserAuthenticationStatusChangeDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserAuthenticationStatusChangeDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserAuthenticationStatusChangingEventArgs : llm:OS::System::IUserAuthenticationStatusChangingEventArgs
    {
        UserAuthenticationStatusChangingEventArgs(std::nullptr_t) noexcept {}
        UserAuthenticationStatusChangingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserAuthenticationStatusChangingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserChangedEventArgs : llm:OS::System::IUserChangedEventArgs,
        impl::require<UserChangedEventArgs, llm:OS::System::IUserChangedEventArgs2>
    {
        UserChangedEventArgs(std::nullptr_t) noexcept {}
        UserChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct UserDeviceAssociation
    {
        UserDeviceAssociation() = delete;
        static auto FindUserFromDeviceId(param::hstring const& deviceId);
        static auto UserDeviceAssociationChanged(llm:OS::Foundation::EventHandler<llm:OS::System::UserDeviceAssociationChangedEventArgs> const& handler);
        using UserDeviceAssociationChanged_revoker = impl::factory_event_revoker<llm:OS::System::IUserDeviceAssociationStatics, &impl::abi_t<llm:OS::System::IUserDeviceAssociationStatics>::remove_UserDeviceAssociationChanged>;
        [[nodiscard]] static UserDeviceAssociationChanged_revoker UserDeviceAssociationChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::System::UserDeviceAssociationChangedEventArgs> const& handler);
        static auto UserDeviceAssociationChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) UserDeviceAssociationChangedEventArgs : llm:OS::System::IUserDeviceAssociationChangedEventArgs
    {
        UserDeviceAssociationChangedEventArgs(std::nullptr_t) noexcept {}
        UserDeviceAssociationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserDeviceAssociationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserPicker : llm:OS::System::IUserPicker
    {
        UserPicker(std::nullptr_t) noexcept {}
        UserPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserPicker(ptr, take_ownership_from_abi) {}
        UserPicker();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) UserWatcher : llm:OS::System::IUserWatcher
    {
        UserWatcher(std::nullptr_t) noexcept {}
        UserWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::IUserWatcher(ptr, take_ownership_from_abi) {}
    };
}
#endif
