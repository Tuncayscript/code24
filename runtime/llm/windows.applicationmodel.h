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
#ifndef LLM_OS_ApplicationModel_H
#define LLM_OS_ApplicationModel_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.ApplicationModel.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppDisplayInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppDisplayInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppDisplayInfo<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppDisplayInfo)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) consume_Windows_ApplicationModel_IAppDisplayInfo<D>::GetLogo(llm::OS::Foundation::Size const& size) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppDisplayInfo)->GetLogo(impl::bind_in(size), &value));
        return llm::OS::Storage::Streams::RandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppInfo<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppInfo<D>::AppUserModelId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo)->get_AppUserModelId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppDisplayInfo) consume_Windows_ApplicationModel_IAppInfo<D>::DisplayInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo)->get_DisplayInfo(&value));
        return llm::OS::ApplicationModel::AppDisplayInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppInfo<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IAppInfo2<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo2)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppExecutionContext) consume_Windows_ApplicationModel_IAppInfo3<D>::ExecutionContext() const
    {
        llm::OS::ApplicationModel::AppExecutionContext value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo3)->get_ExecutionContext(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(com_array<hstring>) consume_Windows_ApplicationModel_IAppInfo4<D>::SupportedFileExtensions() const
    {
        uint32_t value_impl_size{};
        void** value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfo4)->get_SupportedFileExtensions(&value_impl_size, &value));
        return com_array<hstring>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) consume_Windows_ApplicationModel_IAppInfoStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfoStatics)->get_Current(&value));
        return llm::OS::ApplicationModel::AppInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) consume_Windows_ApplicationModel_IAppInfoStatics<D>::GetFromAppUserModelId(param::hstring const& appUserModelId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfoStatics)->GetFromAppUserModelId(*(void**)(&appUserModelId), &result));
        return llm::OS::ApplicationModel::AppInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) consume_Windows_ApplicationModel_IAppInfoStatics<D>::GetFromAppUserModelIdForUser(llm::OS::System::User const& user, param::hstring const& appUserModelId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInfoStatics)->GetFromAppUserModelIdForUser(*(void**)(&user), *(void**)(&appUserModelId), &result));
        return llm::OS::ApplicationModel::AppInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_IAppInstallerInfo<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::OnLaunch() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_OnLaunch(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::HoursBetweenUpdateChecks() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_HoursBetweenUpdateChecks(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::ShowPrompt() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_ShowPrompt(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::UpdateBlocksActivation() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_UpdateBlocksActivation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::AutomaticBackgroundTask() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_AutomaticBackgroundTask(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::ForceUpdateFromAnyVersion() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_ForceUpdateFromAnyVersion(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::IsAutoRepairEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_IsAutoRepairEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageVersion) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::Version() const
    {
        llm::OS::ApplicationModel::PackageVersion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_Version(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::LastChecked() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_LastChecked(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::PausedUntil() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_PausedUntil(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::UpdateUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_UpdateUris(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::RepairUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_RepairUris(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::DependencyPackageUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_DependencyPackageUris(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::OptionalPackageUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_OptionalPackageUris(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstallerPolicySource) consume_Windows_ApplicationModel_IAppInstallerInfo2<D>::PolicySource() const
    {
        llm::OS::ApplicationModel::AppInstallerPolicySource value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstallerInfo2)->get_PolicySource(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IAppInstance<D>::Key() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstance)->get_Key(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IAppInstance<D>::IsCurrentInstance() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstance)->get_IsCurrentInstance(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IAppInstance<D>::RedirectActivationTo() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstance)->RedirectActivationTo());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstance) consume_Windows_ApplicationModel_IAppInstanceStatics<D>::RecommendedInstance() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstanceStatics)->get_RecommendedInstance(&value));
        return llm::OS::ApplicationModel::AppInstance{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::IActivatedEventArgs) consume_Windows_ApplicationModel_IAppInstanceStatics<D>::GetActivatedEventArgs() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstanceStatics)->GetActivatedEventArgs(&result));
        return llm::OS::ApplicationModel::Activation::IActivatedEventArgs{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstance) consume_Windows_ApplicationModel_IAppInstanceStatics<D>::FindOrRegisterInstanceForKey(param::hstring const& key) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstanceStatics)->FindOrRegisterInstanceForKey(*(void**)(&key), &result));
        return llm::OS::ApplicationModel::AppInstance{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IAppInstanceStatics<D>::Unregister() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstanceStatics)->Unregister());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::AppInstance>) consume_Windows_ApplicationModel_IAppInstanceStatics<D>::GetInstances() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IAppInstanceStatics)->GetInstances(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::AppInstance>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IDesignModeStatics<D>::DesignModeEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IDesignModeStatics)->get_DesignModeEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IDesignModeStatics2<D>::DesignMode2Enabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IDesignModeStatics2)->get_DesignMode2Enabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_IEnteredBackgroundEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IEnteredBackgroundEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageRelationship) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::Relationship() const
    {
        llm::OS::ApplicationModel::PackageRelationship value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->get_Relationship(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::Relationship(llm::OS::ApplicationModel::PackageRelationship const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->put_Relationship(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeFrameworks() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->get_IncludeFrameworks(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeFrameworks(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->put_IncludeFrameworks(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeHostRuntimes() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->get_IncludeHostRuntimes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeHostRuntimes(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->put_IncludeHostRuntimes(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeOptionals() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->get_IncludeOptionals(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeOptionals(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->put_IncludeOptionals(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeResources() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->get_IncludeResources(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IFindRelatedPackagesOptions<D>::IncludeResources(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptions)->put_IncludeResources(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::FindRelatedPackagesOptions) consume_Windows_ApplicationModel_IFindRelatedPackagesOptionsFactory<D>::CreateInstance(llm::OS::ApplicationModel::PackageRelationship const& Relationship) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory)->CreateInstance(static_cast<int32_t>(Relationship), &value));
        return llm::OS::ApplicationModel::FindRelatedPackagesOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::FullTrustLaunchResult) consume_Windows_ApplicationModel_IFullTrustProcessLaunchResult<D>::LaunchResult() const
    {
        llm::OS::ApplicationModel::FullTrustLaunchResult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLaunchResult)->get_LaunchResult(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IFullTrustProcessLaunchResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLaunchResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics<D>::LaunchFullTrustProcessForCurrentAppAsync() const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics)->LaunchFullTrustProcessForCurrentAppAsync(&asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics<D>::LaunchFullTrustProcessForCurrentAppAsync(param::hstring const& parameterGroupId) const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics)->LaunchFullTrustProcessForCurrentAppWithParametersAsync(*(void**)(&parameterGroupId), &asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics<D>::LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId) const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics)->LaunchFullTrustProcessForAppAsync(*(void**)(&fullTrustPackageRelativeAppId), &asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics<D>::LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& parameterGroupId) const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics)->LaunchFullTrustProcessForAppWithParametersAsync(*(void**)(&fullTrustPackageRelativeAppId), *(void**)(&parameterGroupId), &asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics2<D>::LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(param::hstring const& commandLine) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2)->LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(*(void**)(&commandLine), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>) consume_Windows_ApplicationModel_IFullTrustProcessLauncherStatics2<D>::LaunchFullTrustProcessForAppWithArgumentsAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& commandLine) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2)->LaunchFullTrustProcessForAppWithArgumentsAsync(*(void**)(&fullTrustPackageRelativeAppId), *(void**)(&commandLine), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_ILeavingBackgroundEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ILeavingBackgroundEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ILimitedAccessFeatureRequestResult<D>::FeatureId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult)->get_FeatureId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::LimitedAccessFeatureStatus) consume_Windows_ApplicationModel_ILimitedAccessFeatureRequestResult<D>::Status() const
    {
        llm::OS::ApplicationModel::LimitedAccessFeatureStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_ApplicationModel_ILimitedAccessFeatureRequestResult<D>::EstimatedRemovalDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult)->get_EstimatedRemovalDate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult) consume_Windows_ApplicationModel_ILimitedAccessFeaturesStatics<D>::TryUnlockFeature(param::hstring const& featureId, param::hstring const& token, param::hstring const& attestation) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics)->TryUnlockFeature(*(void**)(&featureId), *(void**)(&token), *(void**)(&attestation), &result));
        return llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageId) consume_Windows_ApplicationModel_IPackage<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage)->get_Id(&value));
        return llm::OS::ApplicationModel::PackageId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage<D>::InstalledLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage)->get_InstalledLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage<D>::IsFramework() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage)->get_IsFramework(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) consume_Windows_ApplicationModel_IPackage<D>::Dependencies() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage)->get_Dependencies(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage2<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage2<D>::PublisherDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_PublisherDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage2<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_IPackage2<D>::Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage2<D>::IsResourcePackage() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_IsResourcePackage(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage2<D>::IsBundle() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_IsBundle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage2<D>::IsDevelopmentMode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage2)->get_IsDevelopmentMode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageStatus) consume_Windows_ApplicationModel_IPackage3<D>::Status() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage3)->get_Status(&value));
        return llm::OS::ApplicationModel::PackageStatus{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_IPackage3<D>::InstalledDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage3)->get_InstalledDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>>) consume_Windows_ApplicationModel_IPackage3<D>::GetAppListEntriesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage3)->GetAppListEntriesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageSignatureKind) consume_Windows_ApplicationModel_IPackage4<D>::SignatureKind() const
    {
        llm::OS::ApplicationModel::PackageSignatureKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage4)->get_SignatureKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage4<D>::IsOptional() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage4)->get_IsOptional(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_IPackage4<D>::VerifyContentIntegrityAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage4)->VerifyContentIntegrityAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) consume_Windows_ApplicationModel_IPackage5<D>::GetContentGroupsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage5)->GetContentGroupsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageContentGroup>) consume_Windows_ApplicationModel_IPackage5<D>::GetContentGroupAsync(param::hstring const& name) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage5)->GetContentGroupAsync(*(void**)(&name), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageContentGroup>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) consume_Windows_ApplicationModel_IPackage5<D>::StageContentGroupsAsync(param::async_iterable<hstring> const& names) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage5)->StageContentGroupsAsync(*(void**)(&names), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>) consume_Windows_ApplicationModel_IPackage5<D>::StageContentGroupsAsync(param::async_iterable<hstring> const& names, bool moveToHeadOfQueue) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage5)->StageContentGroupsWithPriorityAsync(*(void**)(&names), moveToHeadOfQueue, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_IPackage5<D>::SetInUseAsync(bool inUse) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage5)->SetInUseAsync(inUse, &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInstallerInfo) consume_Windows_ApplicationModel_IPackage6<D>::GetAppInstallerInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage6)->GetAppInstallerInfo(&value));
        return llm::OS::ApplicationModel::AppInstallerInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>) consume_Windows_ApplicationModel_IPackage6<D>::CheckUpdateAvailabilityAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage6)->CheckUpdateAvailabilityAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage7<D>::MutableLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage7)->get_MutableLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage7<D>::EffectiveLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage7)->get_EffectiveLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage8<D>::EffectiveExternalLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_EffectiveExternalLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage8<D>::MachineExternalLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_MachineExternalLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_IPackage8<D>::UserExternalLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_UserExternalLocation(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::InstalledPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_InstalledPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::MutablePath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_MutablePath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::EffectivePath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_EffectivePath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::EffectiveExternalPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_EffectiveExternalPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::MachineExternalPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_MachineExternalPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage8<D>::UserExternalPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_UserExternalPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::RandomAccessStreamReference) consume_Windows_ApplicationModel_IPackage8<D>::GetLogoAsRandomAccessStreamReference(llm::OS::Foundation::Size const& size) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->GetLogoAsRandomAccessStreamReference(impl::bind_in(size), &result));
        return llm::OS::Storage::Streams::RandomAccessStreamReference{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>) consume_Windows_ApplicationModel_IPackage8<D>::GetAppListEntries() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->GetAppListEntries(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackage8<D>::IsStub() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage8)->get_IsStub(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Package>) consume_Windows_ApplicationModel_IPackage9<D>::FindRelatedPackages(llm::OS::ApplicationModel::FindRelatedPackagesOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage9)->FindRelatedPackages(*(void**)(&options), &result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Package>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackage9<D>::SourceUriSchemeName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackage9)->get_SourceUriSchemeName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStaging(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStagingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->add_PackageStaging(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStaging_revoker consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStaging(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStagingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageStaging_revoker>(this, PackageStaging(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStaging(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->remove_PackageStaging(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageInstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageInstallingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->add_PackageInstalling(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageInstalling_revoker consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageInstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageInstallingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageInstalling_revoker>(this, PackageInstalling(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageInstalling(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->remove_PackageInstalling(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUpdatingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->add_PackageUpdating(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUpdating_revoker consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUpdatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageUpdating_revoker>(this, PackageUpdating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUpdating(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->remove_PackageUpdating(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUninstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUninstallingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->add_PackageUninstalling(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUninstalling_revoker consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUninstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUninstallingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageUninstalling_revoker>(this, PackageUninstalling(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageUninstalling(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->remove_PackageUninstalling(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStatusChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->add_PackageStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStatusChanged_revoker consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStatusChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageStatusChanged_revoker>(this, PackageStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog<D>::PackageStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog)->remove_PackageStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_IPackageCatalog2<D>::PackageContentGroupStaging(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog2)->add_PackageContentGroupStaging(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_IPackageCatalog2<D>::PackageContentGroupStaging_revoker consume_Windows_ApplicationModel_IPackageCatalog2<D>::PackageContentGroupStaging(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PackageContentGroupStaging_revoker>(this, PackageContentGroupStaging(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageCatalog2<D>::PackageContentGroupStaging(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog2)->remove_PackageContentGroupStaging(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>) consume_Windows_ApplicationModel_IPackageCatalog2<D>::AddOptionalPackageAsync(param::hstring const& optionalPackageFamilyName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog2)->AddOptionalPackageAsync(*(void**)(&optionalPackageFamilyName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>) consume_Windows_ApplicationModel_IPackageCatalog3<D>::RemoveOptionalPackagesAsync(param::async_iterable<hstring> const& optionalPackageFamilyNames) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog3)->RemoveOptionalPackagesAsync(*(void**)(&optionalPackageFamilyNames), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult, llm::OS::ApplicationModel::PackageInstallProgress>) consume_Windows_ApplicationModel_IPackageCatalog4<D>::AddResourcePackageAsync(param::hstring const& resourcePackageFamilyName, param::hstring const& resourceID, llm::OS::ApplicationModel::AddResourcePackageOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog4)->AddResourcePackageAsync(*(void**)(&resourcePackageFamilyName), *(void**)(&resourceID), static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult, llm::OS::ApplicationModel::PackageInstallProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>) consume_Windows_ApplicationModel_IPackageCatalog4<D>::RemoveResourcePackagesAsync(param::async_iterable<llm::OS::ApplicationModel::Package> const& resourcePackages) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalog4)->RemoveResourcePackagesAsync(*(void**)(&resourcePackages), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageCatalogAddOptionalPackageResult<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageCatalogAddOptionalPackageResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageCatalogAddResourcePackageResult<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageCatalogAddResourcePackageResult<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageCatalogAddResourcePackageResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) consume_Windows_ApplicationModel_IPackageCatalogRemoveOptionalPackagesResult<D>::PackagesRemoved() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult)->get_PackagesRemoved(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageCatalogRemoveOptionalPackagesResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>) consume_Windows_ApplicationModel_IPackageCatalogRemoveResourcePackagesResult<D>::PackagesRemoved() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult)->get_PackagesRemoved(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageCatalogRemoveResourcePackagesResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) consume_Windows_ApplicationModel_IPackageCatalogStatics<D>::OpenForCurrentPackage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogStatics)->OpenForCurrentPackage(&value));
        return llm::OS::ApplicationModel::PackageCatalog{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) consume_Windows_ApplicationModel_IPackageCatalogStatics<D>::OpenForCurrentUser() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogStatics)->OpenForCurrentUser(&value));
        return llm::OS::ApplicationModel::PackageCatalog{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageCatalog) consume_Windows_ApplicationModel_IPackageCatalogStatics2<D>::OpenForPackage(llm::OS::ApplicationModel::Package const& package) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageCatalogStatics2)->OpenForPackage(*(void**)(&package), &result));
        return llm::OS::ApplicationModel::PackageCatalog{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageContentGroup<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroup)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageContentGroup<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroup)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageContentGroupState) consume_Windows_ApplicationModel_IPackageContentGroup<D>::State() const
    {
        llm::OS::ApplicationModel::PackageContentGroupState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroup)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageContentGroup<D>::IsRequired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroup)->get_IsRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::ErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_ErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::ContentGroupName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_ContentGroupName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageContentGroupStagingEventArgs<D>::IsContentGroupRequired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs)->get_IsContentGroupRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageContentGroupStatics<D>::RequiredGroupName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageContentGroupStatics)->get_RequiredGroupName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageVersion) consume_Windows_ApplicationModel_IPackageId<D>::Version() const
    {
        llm::OS::ApplicationModel::PackageVersion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_Version(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::ProcessorArchitecture) consume_Windows_ApplicationModel_IPackageId<D>::Architecture() const
    {
        llm::OS::System::ProcessorArchitecture value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_Architecture(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::ResourceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_ResourceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::Publisher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_Publisher(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::PublisherId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_PublisherId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::FullName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_FullName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageId<D>::FamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageId)->get_FamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageIdWithMetadata<D>::ProductId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageIdWithMetadata)->get_ProductId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageIdWithMetadata<D>::Author() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageIdWithMetadata)->get_Author(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageInstallingEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageInstallingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageInstallingEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageInstallingEventArgs)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageInstallingEventArgs<D>::ErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageInstallingEventArgs)->get_ErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStagingEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStagingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStagingEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStagingEventArgs)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageStagingEventArgs<D>::ErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStagingEventArgs)->get_ErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatics)->get_Current(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::VerifyIsOK() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->VerifyIsOK(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::NotAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_NotAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::PackageOffline() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_PackageOffline(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::DataOffline() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_DataOffline(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::Disabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_Disabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::NeedsRemediation() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_NeedsRemediation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::LicenseIssue() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_LicenseIssue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::Modified() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_Modified(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::Tampered() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_Tampered(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::DependencyIssue() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_DependencyIssue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::Servicing() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_Servicing(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus<D>::DeploymentInProgress() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus)->get_DeploymentInProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageStatus2<D>::IsPartiallyStaged() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatus2)->get_IsPartiallyStaged(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageStatusChangedEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageStatusChangedEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUninstallingEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>::Package() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUninstallingEventArgs)->get_Package(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUninstallingEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUninstallingEventArgs)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageUninstallingEventArgs<D>::ErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUninstallingEventArgs)->get_ErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::PackageUpdateAvailability) consume_Windows_ApplicationModel_IPackageUpdateAvailabilityResult<D>::Availability() const
    {
        llm::OS::ApplicationModel::PackageUpdateAvailability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult)->get_Availability(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageUpdateAvailabilityResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::SourcePackage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_SourcePackage(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::TargetPackage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_TargetPackage(&value));
        return llm::OS::ApplicationModel::Package{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::IsComplete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_IsComplete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_ApplicationModel_IPackageUpdatingEventArgs<D>::ErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageUpdatingEventArgs)->get_ErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_IPackageWithMetadata<D>::InstallDate() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageWithMetadata)->get_InstallDate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IPackageWithMetadata<D>::GetThumbnailToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageWithMetadata)->GetThumbnailToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IPackageWithMetadata<D>::Launch(param::hstring const& parameters) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IPackageWithMetadata)->Launch(*(void**)(&parameters)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTaskState>) consume_Windows_ApplicationModel_IStartupTask<D>::RequestEnableAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTask)->RequestEnableAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTaskState>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_IStartupTask<D>::Disable() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTask)->Disable());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::StartupTaskState) consume_Windows_ApplicationModel_IStartupTask<D>::State() const
    {
        llm::OS::ApplicationModel::StartupTaskState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTask)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_IStartupTask<D>::TaskId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTask)->get_TaskId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::StartupTask>>) consume_Windows_ApplicationModel_IStartupTaskStatics<D>::GetForCurrentPackageAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTaskStatics)->GetForCurrentPackageAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::StartupTask>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTask>) consume_Windows_ApplicationModel_IStartupTaskStatics<D>::GetAsync(param::hstring const& taskId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::IStartupTaskStatics)->GetAsync(*(void**)(&taskId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTask>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ISuspendingDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ISuspendingDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SuspendingOperation) consume_Windows_ApplicationModel_ISuspendingEventArgs<D>::SuspendingOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ISuspendingEventArgs)->get_SuspendingOperation(&value));
        return llm::OS::ApplicationModel::SuspendingOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::SuspendingDeferral) consume_Windows_ApplicationModel_ISuspendingOperation<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ISuspendingOperation)->GetDeferral(&deferral));
        return llm::OS::ApplicationModel::SuspendingDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_ISuspendingOperation<D>::Deadline() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ISuspendingOperation)->get_Deadline(put_abi(value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppDisplayInfo> : produce_base<D, llm::OS::ApplicationModel::IAppDisplayInfo>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLogo(llm::OS::Foundation::Size size, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::RandomAccessStreamReference>(this->shim().GetLogo(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInfo> : produce_base<D, llm::OS::ApplicationModel::IAppInfo>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppUserModelId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppUserModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppDisplayInfo>(this->shim().DisplayInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInfo2> : produce_base<D, llm::OS::ApplicationModel::IAppInfo2>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInfo3> : produce_base<D, llm::OS::ApplicationModel::IAppInfo3>
    {
        int32_t __stdcall get_ExecutionContext(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppExecutionContext>(this->shim().ExecutionContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInfo4> : produce_base<D, llm::OS::ApplicationModel::IAppInfo4>
    {
        int32_t __stdcall get_SupportedFileExtensions(uint32_t* __valueSize, void*** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().SupportedFileExtensions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInfoStatics> : produce_base<D, llm::OS::ApplicationModel::IAppInfoStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInfo>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFromAppUserModelId(void* appUserModelId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::AppInfo>(this->shim().GetFromAppUserModelId(*reinterpret_cast<hstring const*>(&appUserModelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFromAppUserModelIdForUser(void* user, void* appUserModelId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::AppInfo>(this->shim().GetFromAppUserModelIdForUser(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&appUserModelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInstallerInfo> : produce_base<D, llm::OS::ApplicationModel::IAppInstallerInfo>
    {
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInstallerInfo2> : produce_base<D, llm::OS::ApplicationModel::IAppInstallerInfo2>
    {
        int32_t __stdcall get_OnLaunch(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().OnLaunch());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HoursBetweenUpdateChecks(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().HoursBetweenUpdateChecks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowPrompt(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowPrompt());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateBlocksActivation(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().UpdateBlocksActivation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutomaticBackgroundTask(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutomaticBackgroundTask());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForceUpdateFromAnyVersion(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ForceUpdateFromAnyVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAutoRepairEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAutoRepairEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Version(struct struct_Windows_ApplicationModel_PackageVersion* value) noexcept final try
        {
            zero_abi<llm::OS::ApplicationModel::PackageVersion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageVersion>(this->shim().Version());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastChecked(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().LastChecked());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PausedUntil(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().PausedUntil());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>>(this->shim().UpdateUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RepairUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>>(this->shim().RepairUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DependencyPackageUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>>(this->shim().DependencyPackageUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OptionalPackageUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>>(this->shim().OptionalPackageUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PolicySource(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInstallerPolicySource>(this->shim().PolicySource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInstance> : produce_base<D, llm::OS::ApplicationModel::IAppInstance>
    {
        int32_t __stdcall get_Key(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Key());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCurrentInstance(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCurrentInstance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RedirectActivationTo() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RedirectActivationTo();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IAppInstanceStatics> : produce_base<D, llm::OS::ApplicationModel::IAppInstanceStatics>
    {
        int32_t __stdcall get_RecommendedInstance(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInstance>(this->shim().RecommendedInstance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetActivatedEventArgs(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Activation::IActivatedEventArgs>(this->shim().GetActivatedEventArgs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindOrRegisterInstanceForKey(void* key, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::AppInstance>(this->shim().FindOrRegisterInstanceForKey(*reinterpret_cast<hstring const*>(&key)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Unregister() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInstances(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::AppInstance>>(this->shim().GetInstances());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IDesignModeStatics> : produce_base<D, llm::OS::ApplicationModel::IDesignModeStatics>
    {
        int32_t __stdcall get_DesignModeEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DesignModeEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IDesignModeStatics2> : produce_base<D, llm::OS::ApplicationModel::IDesignModeStatics2>
    {
        int32_t __stdcall get_DesignMode2Enabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DesignMode2Enabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IEnteredBackgroundEventArgs> : produce_base<D, llm::OS::ApplicationModel::IEnteredBackgroundEventArgs>
    {
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IFindRelatedPackagesOptions> : produce_base<D, llm::OS::ApplicationModel::IFindRelatedPackagesOptions>
    {
        int32_t __stdcall get_Relationship(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageRelationship>(this->shim().Relationship());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Relationship(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Relationship(*reinterpret_cast<llm::OS::ApplicationModel::PackageRelationship const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeFrameworks(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeFrameworks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeFrameworks(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeFrameworks(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeHostRuntimes(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeHostRuntimes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeHostRuntimes(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeHostRuntimes(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeOptionals(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeOptionals());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeOptionals(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeOptionals(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeResources(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeResources());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeResources(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeResources(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory> : produce_base<D, llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory>
    {
        int32_t __stdcall CreateInstance(int32_t Relationship, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::FindRelatedPackagesOptions>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::ApplicationModel::PackageRelationship const*>(&Relationship)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IFullTrustProcessLaunchResult> : produce_base<D, llm::OS::ApplicationModel::IFullTrustProcessLaunchResult>
    {
        int32_t __stdcall get_LaunchResult(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::FullTrustLaunchResult>(this->shim().LaunchResult());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics> : produce_base<D, llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics>
    {
        int32_t __stdcall LaunchFullTrustProcessForCurrentAppAsync(void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().LaunchFullTrustProcessForCurrentAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFullTrustProcessForCurrentAppWithParametersAsync(void* parameterGroupId, void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().LaunchFullTrustProcessForCurrentAppAsync(*reinterpret_cast<hstring const*>(&parameterGroupId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFullTrustProcessForAppAsync(void* fullTrustPackageRelativeAppId, void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().LaunchFullTrustProcessForAppAsync(*reinterpret_cast<hstring const*>(&fullTrustPackageRelativeAppId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFullTrustProcessForAppWithParametersAsync(void* fullTrustPackageRelativeAppId, void* parameterGroupId, void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().LaunchFullTrustProcessForAppAsync(*reinterpret_cast<hstring const*>(&fullTrustPackageRelativeAppId), *reinterpret_cast<hstring const*>(&parameterGroupId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2> : produce_base<D, llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2>
    {
        int32_t __stdcall LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(void* commandLine, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>>(this->shim().LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(*reinterpret_cast<hstring const*>(&commandLine)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchFullTrustProcessForAppWithArgumentsAsync(void* fullTrustPackageRelativeAppId, void* commandLine, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::FullTrustProcessLaunchResult>>(this->shim().LaunchFullTrustProcessForAppWithArgumentsAsync(*reinterpret_cast<hstring const*>(&fullTrustPackageRelativeAppId), *reinterpret_cast<hstring const*>(&commandLine)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ILeavingBackgroundEventArgs> : produce_base<D, llm::OS::ApplicationModel::ILeavingBackgroundEventArgs>
    {
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult> : produce_base<D, llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult>
    {
        int32_t __stdcall get_FeatureId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FeatureId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::LimitedAccessFeatureStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EstimatedRemovalDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().EstimatedRemovalDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics> : produce_base<D, llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics>
    {
        int32_t __stdcall TryUnlockFeature(void* featureId, void* token, void* attestation, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult>(this->shim().TryUnlockFeature(*reinterpret_cast<hstring const*>(&featureId), *reinterpret_cast<hstring const*>(&token), *reinterpret_cast<hstring const*>(&attestation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage> : produce_base<D, llm::OS::ApplicationModel::IPackage>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageId>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstalledLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().InstalledLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFramework(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFramework());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Dependencies(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>>(this->shim().Dependencies());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage2> : produce_base<D, llm::OS::ApplicationModel::IPackage2>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PublisherDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PublisherDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsResourcePackage(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsResourcePackage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBundle(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBundle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDevelopmentMode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDevelopmentMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage3> : produce_base<D, llm::OS::ApplicationModel::IPackage3>
    {
        int32_t __stdcall get_Status(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstalledDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().InstalledDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppListEntriesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>>>(this->shim().GetAppListEntriesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage4> : produce_base<D, llm::OS::ApplicationModel::IPackage4>
    {
        int32_t __stdcall get_SignatureKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageSignatureKind>(this->shim().SignatureKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOptional(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOptional());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall VerifyContentIntegrityAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().VerifyContentIntegrityAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage5> : produce_base<D, llm::OS::ApplicationModel::IPackage5>
    {
        int32_t __stdcall GetContentGroupsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>>(this->shim().GetContentGroupsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetContentGroupAsync(void* name, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageContentGroup>>(this->shim().GetContentGroupAsync(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StageContentGroupsAsync(void* names, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>>(this->shim().StageContentGroupsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&names)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StageContentGroupsWithPriorityAsync(void* names, bool moveToHeadOfQueue, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::PackageContentGroup>>>(this->shim().StageContentGroupsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&names), moveToHeadOfQueue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInUseAsync(bool inUse, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SetInUseAsync(inUse));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage6> : produce_base<D, llm::OS::ApplicationModel::IPackage6>
    {
        int32_t __stdcall GetAppInstallerInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppInstallerInfo>(this->shim().GetAppInstallerInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckUpdateAvailabilityAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult>>(this->shim().CheckUpdateAvailabilityAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage7> : produce_base<D, llm::OS::ApplicationModel::IPackage7>
    {
        int32_t __stdcall get_MutableLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().MutableLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EffectiveLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().EffectiveLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage8> : produce_base<D, llm::OS::ApplicationModel::IPackage8>
    {
        int32_t __stdcall get_EffectiveExternalLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().EffectiveExternalLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MachineExternalLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().MachineExternalLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserExternalLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().UserExternalLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InstalledPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InstalledPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MutablePath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MutablePath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EffectivePath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EffectivePath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EffectiveExternalPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EffectiveExternalPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MachineExternalPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MachineExternalPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserExternalPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserExternalPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLogoAsRandomAccessStreamReference(llm::OS::Foundation::Size size, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Streams::RandomAccessStreamReference>(this->shim().GetLogoAsRandomAccessStreamReference(*reinterpret_cast<llm::OS::Foundation::Size const*>(&size)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppListEntries(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Core::AppListEntry>>(this->shim().GetAppListEntries());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStub(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStub());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackage9> : produce_base<D, llm::OS::ApplicationModel::IPackage9>
    {
        int32_t __stdcall FindRelatedPackages(void* options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Package>>(this->shim().FindRelatedPackages(*reinterpret_cast<llm::OS::ApplicationModel::FindRelatedPackagesOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceUriSchemeName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SourceUriSchemeName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalog> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalog>
    {
        int32_t __stdcall add_PackageStaging(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageStaging(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStagingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageStaging(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageStaging(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageInstalling(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageInstalling(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageInstallingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageInstalling(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageInstalling(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageUpdating(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageUpdating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUpdatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageUpdating(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageUpdating(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageUninstalling(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageUninstalling(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageUninstallingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageUninstalling(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageUninstalling(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PackageStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageStatusChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalog2> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalog2>
    {
        int32_t __stdcall add_PackageContentGroupStaging(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PackageContentGroupStaging(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::PackageCatalog, llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PackageContentGroupStaging(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageContentGroupStaging(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall AddOptionalPackageAsync(void* optionalPackageFamilyName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult>>(this->shim().AddOptionalPackageAsync(*reinterpret_cast<hstring const*>(&optionalPackageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalog3> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalog3>
    {
        int32_t __stdcall RemoveOptionalPackagesAsync(void* optionalPackageFamilyNames, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult>>(this->shim().RemoveOptionalPackagesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&optionalPackageFamilyNames)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalog4> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalog4>
    {
        int32_t __stdcall AddResourcePackageAsync(void* resourcePackageFamilyName, void* resourceID, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult, llm::OS::ApplicationModel::PackageInstallProgress>>(this->shim().AddResourcePackageAsync(*reinterpret_cast<hstring const*>(&resourcePackageFamilyName), *reinterpret_cast<hstring const*>(&resourceID), *reinterpret_cast<llm::OS::ApplicationModel::AddResourcePackageOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveResourcePackagesAsync(void* resourcePackages, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult>>(this->shim().RemoveResourcePackagesAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::ApplicationModel::Package> const*>(&resourcePackages)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult>
    {
        int32_t __stdcall get_PackagesRemoved(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>>(this->shim().PackagesRemoved());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult>
    {
        int32_t __stdcall get_PackagesRemoved(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Package>>(this->shim().PackagesRemoved());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogStatics> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogStatics>
    {
        int32_t __stdcall OpenForCurrentPackage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageCatalog>(this->shim().OpenForCurrentPackage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenForCurrentUser(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageCatalog>(this->shim().OpenForCurrentUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageCatalogStatics2> : produce_base<D, llm::OS::ApplicationModel::IPackageCatalogStatics2>
    {
        int32_t __stdcall OpenForPackage(void* package, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::PackageCatalog>(this->shim().OpenForPackage(*reinterpret_cast<llm::OS::ApplicationModel::Package const*>(&package)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageContentGroup> : produce_base<D, llm::OS::ApplicationModel::IPackageContentGroup>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageContentGroupState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRequired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRequired());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentGroupName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContentGroupName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsContentGroupRequired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsContentGroupRequired());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageContentGroupStatics> : produce_base<D, llm::OS::ApplicationModel::IPackageContentGroupStatics>
    {
        int32_t __stdcall get_RequiredGroupName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RequiredGroupName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageId> : produce_base<D, llm::OS::ApplicationModel::IPackageId>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Version(struct struct_Windows_ApplicationModel_PackageVersion* value) noexcept final try
        {
            zero_abi<llm::OS::ApplicationModel::PackageVersion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageVersion>(this->shim().Version());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Architecture(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::ProcessorArchitecture>(this->shim().Architecture());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResourceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResourceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Publisher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Publisher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PublisherId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PublisherId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FullName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageIdWithMetadata> : produce_base<D, llm::OS::ApplicationModel::IPackageIdWithMetadata>
    {
        int32_t __stdcall get_ProductId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProductId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Author(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Author());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageInstallingEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageInstallingEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageStagingEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageStagingEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageStatics> : produce_base<D, llm::OS::ApplicationModel::IPackageStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageStatus> : produce_base<D, llm::OS::ApplicationModel::IPackageStatus>
    {
        int32_t __stdcall VerifyIsOK(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().VerifyIsOK());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NotAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NotAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageOffline(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().PackageOffline());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataOffline(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DataOffline());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Disabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Disabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeedsRemediation(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NeedsRemediation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LicenseIssue(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().LicenseIssue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Modified(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Modified());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Tampered(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Tampered());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DependencyIssue(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DependencyIssue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Servicing(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Servicing());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeploymentInProgress(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DeploymentInProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageStatus2> : produce_base<D, llm::OS::ApplicationModel::IPackageStatus2>
    {
        int32_t __stdcall get_IsPartiallyStaged(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPartiallyStaged());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageStatusChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageStatusChangedEventArgs>
    {
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageUninstallingEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageUninstallingEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Package(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().Package());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult> : produce_base<D, llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult>
    {
        int32_t __stdcall get_Availability(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::PackageUpdateAvailability>(this->shim().Availability());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageUpdatingEventArgs> : produce_base<D, llm::OS::ApplicationModel::IPackageUpdatingEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePackage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().SourcePackage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetPackage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Package>(this->shim().TargetPackage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IPackageWithMetadata> : produce_base<D, llm::OS::ApplicationModel::IPackageWithMetadata>
    {
        int32_t __stdcall get_InstallDate(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().InstallDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetThumbnailToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetThumbnailToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Launch(void* parameters) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Launch(*reinterpret_cast<hstring const*>(&parameters));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IStartupTask> : produce_base<D, llm::OS::ApplicationModel::IStartupTask>
    {
        int32_t __stdcall RequestEnableAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTaskState>>(this->shim().RequestEnableAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Disable() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disable();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::StartupTaskState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TaskId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TaskId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::IStartupTaskStatics> : produce_base<D, llm::OS::ApplicationModel::IStartupTaskStatics>
    {
        int32_t __stdcall GetForCurrentPackageAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::StartupTask>>>(this->shim().GetForCurrentPackageAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsync(void* taskId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::StartupTask>>(this->shim().GetAsync(*reinterpret_cast<hstring const*>(&taskId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ISuspendingDeferral> : produce_base<D, llm::OS::ApplicationModel::ISuspendingDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ISuspendingEventArgs> : produce_base<D, llm::OS::ApplicationModel::ISuspendingEventArgs>
    {
        int32_t __stdcall get_SuspendingOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::SuspendingOperation>(this->shim().SuspendingOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ISuspendingOperation> : produce_base<D, llm::OS::ApplicationModel::ISuspendingOperation>
    {
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::ApplicationModel::SuspendingDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Deadline(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Deadline());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    constexpr auto operator|(AddResourcePackageOptions const left, AddResourcePackageOptions const right) noexcept
    {
        return static_cast<AddResourcePackageOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(AddResourcePackageOptions& left, AddResourcePackageOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(AddResourcePackageOptions const left, AddResourcePackageOptions const right) noexcept
    {
        return static_cast<AddResourcePackageOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(AddResourcePackageOptions& left, AddResourcePackageOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(AddResourcePackageOptions const value) noexcept
    {
        return static_cast<AddResourcePackageOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(AddResourcePackageOptions const left, AddResourcePackageOptions const right) noexcept
    {
        return static_cast<AddResourcePackageOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(AddResourcePackageOptions& left, AddResourcePackageOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto AppInfo::Current()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::AppInfo(*)(IAppInfoStatics const&), AppInfo, IAppInfoStatics>([](IAppInfoStatics const& f) { return f.Current(); });
    }
    inline auto AppInfo::GetFromAppUserModelId(param::hstring const& appUserModelId)
    {
        return impl::call_factory<AppInfo, IAppInfoStatics>([&](IAppInfoStatics const& f) { return f.GetFromAppUserModelId(appUserModelId); });
    }
    inline auto AppInfo::GetFromAppUserModelIdForUser(llm::OS::System::User const& user, param::hstring const& appUserModelId)
    {
        return impl::call_factory<AppInfo, IAppInfoStatics>([&](IAppInfoStatics const& f) { return f.GetFromAppUserModelIdForUser(user, appUserModelId); });
    }
    inline auto AppInstance::RecommendedInstance()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::AppInstance(*)(IAppInstanceStatics const&), AppInstance, IAppInstanceStatics>([](IAppInstanceStatics const& f) { return f.RecommendedInstance(); });
    }
    inline auto AppInstance::GetActivatedEventArgs()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Activation::IActivatedEventArgs(*)(IAppInstanceStatics const&), AppInstance, IAppInstanceStatics>([](IAppInstanceStatics const& f) { return f.GetActivatedEventArgs(); });
    }
    inline auto AppInstance::FindOrRegisterInstanceForKey(param::hstring const& key)
    {
        return impl::call_factory<AppInstance, IAppInstanceStatics>([&](IAppInstanceStatics const& f) { return f.FindOrRegisterInstanceForKey(key); });
    }
    inline auto AppInstance::Unregister()
    {
        impl::call_factory_cast<void(*)(IAppInstanceStatics const&), AppInstance, IAppInstanceStatics>([](IAppInstanceStatics const& f) { return f.Unregister(); });
    }
    inline auto AppInstance::GetInstances()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::AppInstance>(*)(IAppInstanceStatics const&), AppInstance, IAppInstanceStatics>([](IAppInstanceStatics const& f) { return f.GetInstances(); });
    }
    inline auto DesignMode::DesignModeEnabled()
    {
        return impl::call_factory_cast<bool(*)(IDesignModeStatics const&), DesignMode, IDesignModeStatics>([](IDesignModeStatics const& f) { return f.DesignModeEnabled(); });
    }
    inline auto DesignMode::DesignMode2Enabled()
    {
        return impl::call_factory_cast<bool(*)(IDesignModeStatics2 const&), DesignMode, IDesignModeStatics2>([](IDesignModeStatics2 const& f) { return f.DesignMode2Enabled(); });
    }
    inline FindRelatedPackagesOptions::FindRelatedPackagesOptions(llm::OS::ApplicationModel::PackageRelationship const& Relationship) :
        FindRelatedPackagesOptions(impl::call_factory<FindRelatedPackagesOptions, IFindRelatedPackagesOptionsFactory>([&](IFindRelatedPackagesOptionsFactory const& f) { return f.CreateInstance(Relationship); }))
    {
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForCurrentAppAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(IFullTrustProcessLauncherStatics const&), FullTrustProcessLauncher, IFullTrustProcessLauncherStatics>([](IFullTrustProcessLauncherStatics const& f) { return f.LaunchFullTrustProcessForCurrentAppAsync(); });
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForCurrentAppAsync(param::hstring const& parameterGroupId)
    {
        return impl::call_factory<FullTrustProcessLauncher, IFullTrustProcessLauncherStatics>([&](IFullTrustProcessLauncherStatics const& f) { return f.LaunchFullTrustProcessForCurrentAppAsync(parameterGroupId); });
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId)
    {
        return impl::call_factory<FullTrustProcessLauncher, IFullTrustProcessLauncherStatics>([&](IFullTrustProcessLauncherStatics const& f) { return f.LaunchFullTrustProcessForAppAsync(fullTrustPackageRelativeAppId); });
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForAppAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& parameterGroupId)
    {
        return impl::call_factory<FullTrustProcessLauncher, IFullTrustProcessLauncherStatics>([&](IFullTrustProcessLauncherStatics const& f) { return f.LaunchFullTrustProcessForAppAsync(fullTrustPackageRelativeAppId, parameterGroupId); });
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(param::hstring const& commandLine)
    {
        return impl::call_factory<FullTrustProcessLauncher, IFullTrustProcessLauncherStatics2>([&](IFullTrustProcessLauncherStatics2 const& f) { return f.LaunchFullTrustProcessForCurrentAppWithArgumentsAsync(commandLine); });
    }
    inline auto FullTrustProcessLauncher::LaunchFullTrustProcessForAppWithArgumentsAsync(param::hstring const& fullTrustPackageRelativeAppId, param::hstring const& commandLine)
    {
        return impl::call_factory<FullTrustProcessLauncher, IFullTrustProcessLauncherStatics2>([&](IFullTrustProcessLauncherStatics2 const& f) { return f.LaunchFullTrustProcessForAppWithArgumentsAsync(fullTrustPackageRelativeAppId, commandLine); });
    }
    inline auto LimitedAccessFeatures::TryUnlockFeature(param::hstring const& featureId, param::hstring const& token, param::hstring const& attestation)
    {
        return impl::call_factory<LimitedAccessFeatures, ILimitedAccessFeaturesStatics>([&](ILimitedAccessFeaturesStatics const& f) { return f.TryUnlockFeature(featureId, token, attestation); });
    }
    inline auto Package::Current()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Package(*)(IPackageStatics const&), Package, IPackageStatics>([](IPackageStatics const& f) { return f.Current(); });
    }
    inline auto PackageCatalog::OpenForCurrentPackage()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::PackageCatalog(*)(IPackageCatalogStatics const&), PackageCatalog, IPackageCatalogStatics>([](IPackageCatalogStatics const& f) { return f.OpenForCurrentPackage(); });
    }
    inline auto PackageCatalog::OpenForCurrentUser()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::PackageCatalog(*)(IPackageCatalogStatics const&), PackageCatalog, IPackageCatalogStatics>([](IPackageCatalogStatics const& f) { return f.OpenForCurrentUser(); });
    }
    inline auto PackageCatalog::OpenForPackage(llm::OS::ApplicationModel::Package const& package)
    {
        return impl::call_factory<PackageCatalog, IPackageCatalogStatics2>([&](IPackageCatalogStatics2 const& f) { return f.OpenForPackage(package); });
    }
    inline auto PackageContentGroup::RequiredGroupName()
    {
        return impl::call_factory_cast<hstring(*)(IPackageContentGroupStatics const&), PackageContentGroup, IPackageContentGroupStatics>([](IPackageContentGroupStatics const& f) { return f.RequiredGroupName(); });
    }
    inline auto StartupTask::GetForCurrentPackageAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::StartupTask>>(*)(IStartupTaskStatics const&), StartupTask, IStartupTaskStatics>([](IStartupTaskStatics const& f) { return f.GetForCurrentPackageAsync(); });
    }
    inline auto StartupTask::GetAsync(param::hstring const& taskId)
    {
        return impl::call_factory<StartupTask, IStartupTaskStatics>([&](IStartupTaskStatics const& f) { return f.GetAsync(taskId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::IAppDisplayInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInfo3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInfo4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInstallerInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInstallerInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInstance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IAppInstanceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IDesignModeStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IDesignModeStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IFindRelatedPackagesOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IFindRelatedPackagesOptionsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IFullTrustProcessLaunchResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IFullTrustProcessLauncherStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ILimitedAccessFeatureRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ILimitedAccessFeaturesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage7> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage8> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackage9> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalog2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalog3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalog4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogAddOptionalPackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogAddResourcePackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageCatalogStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageContentGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageContentGroupStagingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageContentGroupStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageIdWithMetadata> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageInstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageStagingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageStatus2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageUninstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageUpdateAvailabilityResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IPackageWithMetadata> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IStartupTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::IStartupTaskStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ISuspendingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ISuspendingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ISuspendingOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppDisplayInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppInstallerInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppInstance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::DesignMode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::EnteredBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::FindRelatedPackagesOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::FullTrustProcessLaunchResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::FullTrustProcessLauncher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LeavingBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LimitedAccessFeatureRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LimitedAccessFeatures> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Package> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageCatalog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageCatalogAddOptionalPackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageCatalogAddResourcePackageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageCatalogRemoveOptionalPackagesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageCatalogRemoveResourcePackagesResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageContentGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageContentGroupStagingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageInstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageStagingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageUninstallingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageUpdateAvailabilityResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::PackageUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::StartupTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SuspendingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SuspendingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::SuspendingOperation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
