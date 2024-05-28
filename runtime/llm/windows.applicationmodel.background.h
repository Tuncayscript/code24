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
#ifndef LLM_OS_ApplicationModel_Background_H
#define LLM_OS_ApplicationModel_Background_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.ApplicationModel.Calls.Background.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Advertisement.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.Background.2.h"
#include "llm/impl/Windows.Devices.Bluetooth.GenericAttributeProfile.2.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Devices.Sensors.2.h"
#include "llm/impl/Windows.Devices.SmartCards.2.h"
#include "llm/impl/Windows.Devices.Sms.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Provider.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.Notifications.2.h"
#include "llm/impl/Windows.ApplicationModel.Background.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sensors::ActivityType>) consume_Windows_ApplicationModel_Background_IActivitySensorTrigger<D>::SubscribedActivities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IActivitySensorTrigger)->get_SubscribedActivities(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sensors::ActivityType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IActivitySensorTrigger<D>::ReportInterval() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IActivitySensorTrigger)->get_ReportInterval(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sensors::ActivityType>) consume_Windows_ApplicationModel_Background_IActivitySensorTrigger<D>::SupportedActivities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IActivitySensorTrigger)->get_SupportedActivities(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sensors::ActivityType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IActivitySensorTrigger<D>::MinimumReportInterval() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IActivitySensorTrigger)->get_MinimumReportInterval(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::ActivitySensorTrigger) consume_Windows_ApplicationModel_Background_IActivitySensorTriggerFactory<D>::Create(uint32_t reportIntervalInMilliseconds) const
    {
        void* activityTrigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IActivitySensorTriggerFactory)->Create(reportIntervalInMilliseconds, &activityTrigger));
        return llm::OS::ApplicationModel::Background::ActivitySensorTrigger{ activityTrigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::AlarmAccessStatus>) consume_Windows_ApplicationModel_Background_IAlarmApplicationManagerStatics<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAlarmApplicationManagerStatics)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::AlarmAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::AlarmAccessStatus) consume_Windows_ApplicationModel_Background_IAlarmApplicationManagerStatics<D>::GetAccessStatus() const
    {
        llm::OS::ApplicationModel::Background::AlarmAccessStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAlarmApplicationManagerStatics)->GetAccessStatus(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTrigger<D>::ProviderInfo(llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTrigger)->put_ProviderInfo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo) consume_Windows_ApplicationModel_Background_IAppBroadcastTrigger<D>::ProviderInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTrigger)->get_ProviderInfo(&value));
        return llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::AppBroadcastTrigger) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerFactory<D>::CreateAppBroadcastTrigger(param::hstring const& providerKey) const
    {
        void* broadcastTrigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerFactory)->CreateAppBroadcastTrigger(*(void**)(&providerKey), &broadcastTrigger));
        return llm::OS::ApplicationModel::Background::AppBroadcastTrigger{ broadcastTrigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::DisplayNameResource(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_DisplayNameResource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::DisplayNameResource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_DisplayNameResource(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::LogoResource(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_LogoResource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::LogoResource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_LogoResource(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::VideoKeyFrameInterval(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_VideoKeyFrameInterval(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::VideoKeyFrameInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_VideoKeyFrameInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoBitrate(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_MaxVideoBitrate(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoBitrate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_MaxVideoBitrate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoWidth(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_MaxVideoWidth(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_MaxVideoWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoHeight(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->put_MaxVideoHeight(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IAppBroadcastTriggerProviderInfo<D>::MaxVideoHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo)->get_MaxVideoHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>) consume_Windows_ApplicationModel_Background_IApplicationTrigger<D>::RequestAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IApplicationTrigger)->RequestAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>) consume_Windows_ApplicationModel_Background_IApplicationTrigger<D>::RequestAsync(llm::OS::Foundation::Collections::ValueSet const& arguments) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IApplicationTrigger)->RequestAsyncWithArguments(*(void**)(&arguments), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_Background_IApplicationTriggerDetails<D>::Arguments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IApplicationTriggerDetails)->get_Arguments(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::RequestAccessAsync(param::hstring const& applicationId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->RequestAccessForApplicationAsync(*(void**)(&applicationId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::RemoveAccess() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->RemoveAccess());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::RemoveAccess(param::hstring const& applicationId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->RemoveAccessForApplication(*(void**)(&applicationId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundAccessStatus) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::GetAccessStatus() const
    {
        llm::OS::ApplicationModel::Background::BackgroundAccessStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->GetAccessStatus(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundAccessStatus) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics<D>::GetAccessStatus(param::hstring const& applicationId) const
    {
        llm::OS::ApplicationModel::Background::BackgroundAccessStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics)->GetAccessStatusForApplication(*(void**)(&applicationId), reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics2<D>::RequestAccessKindAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics2)->RequestAccessKindAsync(static_cast<int32_t>(requestedAccess), *(void**)(&reason), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics3<D>::RequestAccessKindForModernStandbyAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3)->RequestAccessKindForModernStandbyAsync(static_cast<int32_t>(requestedAccess), *(void**)(&reason), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundAccessStatus) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics3<D>::GetAccessStatusForModernStandby() const
    {
        llm::OS::ApplicationModel::Background::BackgroundAccessStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3)->GetAccessStatusForModernStandby(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundAccessStatus) consume_Windows_ApplicationModel_Background_IBackgroundExecutionManagerStatics3<D>::GetAccessStatusForModernStandby(param::hstring const& applicationId) const
    {
        llm::OS::ApplicationModel::Background::BackgroundAccessStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3)->GetAccessStatusForModernStandbyForApplication(*(void**)(&applicationId), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTask<D>::Run(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const& taskInstance) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTask)->Run(*(void**)(&taskInstance)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::TaskEntryPoint(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->put_TaskEntryPoint(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::TaskEntryPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->get_TaskEntryPoint(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::SetTrigger(llm::OS::ApplicationModel::Background::IBackgroundTrigger const& trigger) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->SetTrigger(*(void**)(&trigger)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::AddCondition(llm::OS::ApplicationModel::Background::IBackgroundCondition const& condition) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->AddCondition(*(void**)(&condition)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder<D>::Register() const
    {
        void* task{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder)->Register(&task));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistration{ task, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder2<D>::CancelOnConditionLoss(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2)->put_CancelOnConditionLoss(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder2<D>::CancelOnConditionLoss() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2)->get_CancelOnConditionLoss(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder3<D>::IsNetworkRequested(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3)->put_IsNetworkRequested(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder3<D>::IsNetworkRequested() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3)->get_IsNetworkRequested(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder4<D>::TaskGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4)->get_TaskGroup(&value));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder4<D>::TaskGroup(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4)->put_TaskGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskBuilder5<D>::SetTaskEntryPointClsid(llm::guid const& TaskEntryPoint) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder5)->SetTaskEntryPointClsid(impl::bind_in(TaskEntryPoint)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Background_IBackgroundTaskCompletedEventArgs<D>::InstanceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs)->get_InstanceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskCompletedEventArgs<D>::CheckResult() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs)->CheckResult());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::InstanceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->get_InstanceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Task() const
    {
        void* task{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->get_Task(&task));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistration{ task, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Progress() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Progress(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->put_Progress(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::TriggerDetails() const
    {
        void* triggerDetails{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->get_TriggerDetails(&triggerDetails));
        return llm::OS::Foundation::IInspectable{ triggerDetails, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Canceled(llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler const& cancelHandler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->add_Canceled(*(void**)(&cancelHandler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Canceled_revoker consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Canceled(auto_revoke_t, llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler const& cancelHandler) const
    {
        return impl::make_event_revoker<D, Canceled_revoker>(this, Canceled(cancelHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::Canceled(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->remove_Canceled(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::SuspendedCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->get_SuspendedCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskDeferral) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance)->GetDeferral(&deferral));
        return llm::OS::ApplicationModel::Background::BackgroundTaskDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance2<D>::GetThrottleCount(llm::OS::ApplicationModel::Background::BackgroundTaskThrottleCounter const& counter) const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance2)->GetThrottleCount(static_cast<int32_t>(counter), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_ApplicationModel_Background_IBackgroundTaskInstance4<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance4)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Background_IBackgroundTaskProgressEventArgs<D>::InstanceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs)->get_InstanceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IBackgroundTaskProgressEventArgs<D>::Progress() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::TaskId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->get_TaskId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Progress(llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->add_Progress(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Progress_revoker consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Progress(auto_revoke_t, llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Progress_revoker>(this, Progress(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Progress(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->remove_Progress(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Completed(llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->add_Completed(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Completed_revoker consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Completed(auto_revoke_t, llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Completed_revoker>(this, Completed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Completed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->remove_Completed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration<D>::Unregister(bool cancelTask) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration)->Unregister(cancelTask));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::IBackgroundTrigger) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration2<D>::Trigger() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2)->get_Trigger(&value));
        return llm::OS::ApplicationModel::Background::IBackgroundTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistration3<D>::TaskGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3)->get_TaskGroup(&value));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::BackgroundActivated(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup, llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup)->add_BackgroundActivated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::BackgroundActivated_revoker consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::BackgroundActivated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup, llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BackgroundActivated_revoker>(this, BackgroundActivated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::BackgroundActivated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup)->remove_BackgroundActivated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::BackgroundTaskRegistration>) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroup<D>::AllTasks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup)->get_AllTasks(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::BackgroundTaskRegistration>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroupFactory<D>::Create(param::hstring const& id) const
    {
        void* group{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroupFactory)->Create(*(void**)(&id), &group));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup{ group, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationGroupFactory<D>::CreateWithName(param::hstring const& id, param::hstring const& name) const
    {
        void* group{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroupFactory)->CreateWithName(*(void**)(&id), *(void**)(&name), &group));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup{ group, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationStatics<D>::AllTasks() const
    {
        void* tasks{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics)->get_AllTasks(&tasks));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>{ tasks, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationStatics2<D>::AllTaskGroups() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics2)->get_AllTaskGroups(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup) consume_Windows_ApplicationModel_Background_IBackgroundTaskRegistrationStatics2<D>::GetTaskGroup(param::hstring const& groupId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics2)->GetTaskGroup(*(void**)(&groupId), &value));
        return llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::BackgroundWorkCostValue) consume_Windows_ApplicationModel_Background_IBackgroundWorkCostStatics<D>::CurrentBackgroundWorkCost() const
    {
        llm::OS::ApplicationModel::Background::BackgroundWorkCostValue value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBackgroundWorkCostStatics)->get_CurrentBackgroundWorkCost(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger<D>::Advertisement() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger)->get_Advertisement(&value));
        return llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int16_t>) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::PreferredTransmitPowerLevelInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->get_PreferredTransmitPowerLevelInDBm(&value));
        return llm::OS::Foundation::IReference<int16_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::PreferredTransmitPowerLevelInDBm(llm::OS::Foundation::IReference<int16_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->put_PreferredTransmitPowerLevelInDBm(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::UseExtendedFormat() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->get_UseExtendedFormat(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::UseExtendedFormat(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->put_UseExtendedFormat(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::IsAnonymous() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->get_IsAnonymous(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::IsAnonymous(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->put_IsAnonymous(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::IncludeTransmitPowerLevel() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->get_IncludeTransmitPowerLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementPublisherTrigger2<D>::IncludeTransmitPowerLevel(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2)->put_IncludeTransmitPowerLevel(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::MinSamplingInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_MinSamplingInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::MaxSamplingInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_MaxSamplingInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::MinOutOfRangeTimeout() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_MinOutOfRangeTimeout(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::MaxOutOfRangeTimeout() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_MaxOutOfRangeTimeout(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::SignalStrengthFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_SignalStrengthFilter(&value));
        return llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::SignalStrengthFilter(llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->put_SignalStrengthFilter(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::AdvertisementFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->get_AdvertisementFilter(&value));
        return llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger<D>::AdvertisementFilter(llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger)->put_AdvertisementFilter(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger2<D>::AllowExtendedAdvertisements() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2)->get_AllowExtendedAdvertisements(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IBluetoothLEAdvertisementWatcherTrigger2<D>::AllowExtendedAdvertisements(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2)->put_AllowExtendedAdvertisements(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Provider::CachedFileTarget) consume_Windows_ApplicationModel_Background_ICachedFileUpdaterTriggerDetails<D>::UpdateTarget() const
    {
        llm::OS::Storage::Provider::CachedFileTarget value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails)->get_UpdateTarget(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Provider::FileUpdateRequest) consume_Windows_ApplicationModel_Background_ICachedFileUpdaterTriggerDetails<D>::UpdateRequest() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails)->get_UpdateRequest(&value));
        return llm::OS::Storage::Provider::FileUpdateRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_ICachedFileUpdaterTriggerDetails<D>::CanRequestUserInput() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails)->get_CanRequestUserInput(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Background_IContentPrefetchTrigger<D>::WaitInterval() const
    {
        llm::OS::Foundation::TimeSpan waitInterval{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IContentPrefetchTrigger)->get_WaitInterval(put_abi(waitInterval)));
        return waitInterval;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::ContentPrefetchTrigger) consume_Windows_ApplicationModel_Background_IContentPrefetchTriggerFactory<D>::Create(llm::OS::Foundation::TimeSpan const& waitInterval) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IContentPrefetchTriggerFactory)->Create(impl::bind_in(waitInterval), &trigger));
        return llm::OS::ApplicationModel::Background::ContentPrefetchTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_ICustomSystemEventTrigger<D>::TriggerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger)->get_TriggerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence) consume_Windows_ApplicationModel_Background_ICustomSystemEventTrigger<D>::Recurrence() const
    {
        llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger)->get_Recurrence(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::CustomSystemEventTrigger) consume_Windows_ApplicationModel_Background_ICustomSystemEventTriggerFactory<D>::Create(param::hstring const& triggerId, llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence const& recurrence) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ICustomSystemEventTriggerFactory)->Create(*(void**)(&triggerId), static_cast<int32_t>(recurrence), &trigger));
        return llm::OS::ApplicationModel::Background::CustomSystemEventTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IDeviceConnectionChangeTrigger<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IDeviceConnectionChangeTrigger<D>::CanMaintainConnection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger)->get_CanMaintainConnection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IDeviceConnectionChangeTrigger<D>::MaintainConnection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger)->get_MaintainConnection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IDeviceConnectionChangeTrigger<D>::MaintainConnection(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger)->put_MaintainConnection(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceConnectionChangeTrigger>) consume_Windows_ApplicationModel_Background_IDeviceConnectionChangeTriggerStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* deviceChangeTrigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics)->FromIdAsync(*(void**)(&deviceId), &deviceChangeTrigger));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceConnectionChangeTrigger>{ deviceChangeTrigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IDeviceManufacturerNotificationTrigger<D>::TriggerQualifier() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger)->get_TriggerQualifier(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IDeviceManufacturerNotificationTrigger<D>::OneShot() const
    {
        bool oneShot{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger)->get_OneShot(&oneShot));
        return oneShot;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::DeviceManufacturerNotificationTrigger) consume_Windows_ApplicationModel_Background_IDeviceManufacturerNotificationTriggerFactory<D>::Create(param::hstring const& triggerQualifier, bool oneShot) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory)->Create(*(void**)(&triggerQualifier), oneShot, &trigger));
        return llm::OS::ApplicationModel::Background::DeviceManufacturerNotificationTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>) consume_Windows_ApplicationModel_Background_IDeviceServicingTrigger<D>::RequestAsync(param::hstring const& deviceId, llm::OS::Foundation::TimeSpan const& expectedDuration) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceServicingTrigger)->RequestAsyncSimple(*(void**)(&deviceId), impl::bind_in(expectedDuration), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>) consume_Windows_ApplicationModel_Background_IDeviceServicingTrigger<D>::RequestAsync(param::hstring const& deviceId, llm::OS::Foundation::TimeSpan const& expectedDuration, param::hstring const& arguments) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceServicingTrigger)->RequestAsyncWithArguments(*(void**)(&deviceId), impl::bind_in(expectedDuration), *(void**)(&arguments), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>) consume_Windows_ApplicationModel_Background_IDeviceUseTrigger<D>::RequestAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceUseTrigger)->RequestAsyncSimple(*(void**)(&deviceId), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>) consume_Windows_ApplicationModel_Background_IDeviceUseTrigger<D>::RequestAsync(param::hstring const& deviceId, param::hstring const& arguments) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IDeviceUseTrigger)->RequestAsyncWithArguments(*(void**)(&deviceId), *(void**)(&arguments), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic) consume_Windows_ApplicationModel_Background_IGattCharacteristicNotificationTrigger<D>::Characteristic() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger)->get_Characteristic(&value));
        return llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode) consume_Windows_ApplicationModel_Background_IGattCharacteristicNotificationTrigger2<D>::EventTriggeringMode() const
    {
        llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger2)->get_EventTriggeringMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger) consume_Windows_ApplicationModel_Background_IGattCharacteristicNotificationTriggerFactory<D>::Create(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic) const
    {
        void* gattCharacteristicNotificationTrigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory)->Create(*(void**)(&characteristic), &gattCharacteristicNotificationTrigger));
        return llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger{ gattCharacteristicNotificationTrigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger) consume_Windows_ApplicationModel_Background_IGattCharacteristicNotificationTriggerFactory2<D>::Create(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic, llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode const& eventTriggeringMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory2)->CreateWithEventTriggeringMode(*(void**)(&characteristic), static_cast<int32_t>(eventTriggeringMode), &result));
        return llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_IGattServiceProviderTrigger<D>::TriggerId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger)->get_TriggerId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService) consume_Windows_ApplicationModel_Background_IGattServiceProviderTrigger<D>::Service() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger)->get_Service(&value));
        return llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IGattServiceProviderTrigger<D>::AdvertisingParameters(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattServiceProviderAdvertisingParameters const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger)->put_AdvertisingParameters(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattServiceProviderAdvertisingParameters) consume_Windows_ApplicationModel_Background_IGattServiceProviderTrigger<D>::AdvertisingParameters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger)->get_AdvertisingParameters(&value));
        return llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattServiceProviderAdvertisingParameters{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::GattServiceProviderTrigger) consume_Windows_ApplicationModel_Background_IGattServiceProviderTriggerResult<D>::Trigger() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult)->get_Trigger(&value));
        return llm::OS::ApplicationModel::Background::GattServiceProviderTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::BluetoothError) consume_Windows_ApplicationModel_Background_IGattServiceProviderTriggerResult<D>::Error() const
    {
        llm::OS::Devices::Bluetooth::BluetoothError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::GattServiceProviderTriggerResult>) consume_Windows_ApplicationModel_Background_IGattServiceProviderTriggerStatics<D>::CreateAsync(param::hstring const& triggerId, llm::guid const& serviceUuid) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerStatics)->CreateAsync(*(void**)(&triggerId), impl::bind_in(serviceUuid), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::GattServiceProviderTriggerResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::VisitMonitoringScope) consume_Windows_ApplicationModel_Background_IGeovisitTrigger<D>::MonitoringScope() const
    {
        llm::OS::Devices::Geolocation::VisitMonitoringScope value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGeovisitTrigger)->get_MonitoringScope(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IGeovisitTrigger<D>::MonitoringScope(llm::OS::Devices::Geolocation::VisitMonitoringScope const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IGeovisitTrigger)->put_MonitoringScope(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::LocationTriggerType) consume_Windows_ApplicationModel_Background_ILocationTrigger<D>::TriggerType() const
    {
        llm::OS::ApplicationModel::Background::LocationTriggerType triggerType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ILocationTrigger)->get_TriggerType(reinterpret_cast<int32_t*>(&triggerType)));
        return triggerType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::LocationTrigger) consume_Windows_ApplicationModel_Background_ILocationTriggerFactory<D>::Create(llm::OS::ApplicationModel::Background::LocationTriggerType const& triggerType) const
    {
        void* locationTrigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ILocationTriggerFactory)->Create(static_cast<int32_t>(triggerType), &locationTrigger));
        return llm::OS::ApplicationModel::Background::LocationTrigger{ locationTrigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_IMaintenanceTrigger<D>::FreshnessTime() const
    {
        uint32_t freshnessTime{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IMaintenanceTrigger)->get_FreshnessTime(&freshnessTime));
        return freshnessTime;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IMaintenanceTrigger<D>::OneShot() const
    {
        bool oneShot{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IMaintenanceTrigger)->get_OneShot(&oneShot));
        return oneShot;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::MaintenanceTrigger) consume_Windows_ApplicationModel_Background_IMaintenanceTriggerFactory<D>::Create(uint32_t freshnessTime, bool oneShot) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IMaintenanceTriggerFactory)->Create(freshnessTime, oneShot, &trigger));
        return llm::OS::ApplicationModel::Background::MaintenanceTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>) consume_Windows_ApplicationModel_Background_IMediaProcessingTrigger<D>::RequestAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IMediaProcessingTrigger)->RequestAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>) consume_Windows_ApplicationModel_Background_IMediaProcessingTrigger<D>::RequestAsync(llm::OS::Foundation::Collections::ValueSet const& arguments) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IMediaProcessingTrigger)->RequestAsyncWithArguments(*(void**)(&arguments), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Background_INetworkOperatorNotificationTrigger<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::NetworkOperatorNotificationTrigger) consume_Windows_ApplicationModel_Background_INetworkOperatorNotificationTriggerFactory<D>::Create(param::hstring const& networkAccountId) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory)->Create(*(void**)(&networkAccountId), &trigger));
        return llm::OS::ApplicationModel::Background::NetworkOperatorNotificationTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IPhoneTrigger<D>::OneShot() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IPhoneTrigger)->get_OneShot(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType) consume_Windows_ApplicationModel_Background_IPhoneTrigger<D>::TriggerType() const
    {
        llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IPhoneTrigger)->get_TriggerType(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::PhoneTrigger) consume_Windows_ApplicationModel_Background_IPhoneTriggerFactory<D>::Create(llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType const& type, bool oneShot) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IPhoneTriggerFactory)->Create(static_cast<int32_t>(type), oneShot, &result));
        return llm::OS::ApplicationModel::Background::PhoneTrigger{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::PushNotificationTrigger) consume_Windows_ApplicationModel_Background_IPushNotificationTriggerFactory<D>::Create(param::hstring const& applicationId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IPushNotificationTriggerFactory)->Create(*(void**)(&applicationId), &value));
        return llm::OS::ApplicationModel::Background::PushNotificationTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Background::RfcommInboundConnectionInformation) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::InboundConnection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->get_InboundConnection(&value));
        return llm::OS::Devices::Bluetooth::Background::RfcommInboundConnectionInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::OutboundConnection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->get_OutboundConnection(&value));
        return llm::OS::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::AllowMultipleConnections() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->get_AllowMultipleConnections(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::AllowMultipleConnections(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->put_AllowMultipleConnections(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::SocketProtectionLevel) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::ProtectionLevel() const
    {
        llm::OS::Networking::Sockets::SocketProtectionLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->get_ProtectionLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::ProtectionLevel(llm::OS::Networking::Sockets::SocketProtectionLevel const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->put_ProtectionLevel(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::RemoteHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->get_RemoteHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Background_IRfcommConnectionTrigger<D>::RemoteHostName(llm::OS::Networking::HostName const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger)->put_RemoteHostName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SensorDataThresholdTrigger) consume_Windows_ApplicationModel_Background_ISensorDataThresholdTriggerFactory<D>::Create(llm::OS::Devices::Sensors::ISensorDataThreshold const& threshold) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISensorDataThresholdTriggerFactory)->Create(*(void**)(&threshold), &trigger));
        return llm::OS::ApplicationModel::Background::SensorDataThresholdTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardTriggerType) consume_Windows_ApplicationModel_Background_ISmartCardTrigger<D>::TriggerType() const
    {
        llm::OS::Devices::SmartCards::SmartCardTriggerType triggerType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISmartCardTrigger)->get_TriggerType(reinterpret_cast<int32_t*>(&triggerType)));
        return triggerType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SmartCardTrigger) consume_Windows_ApplicationModel_Background_ISmartCardTriggerFactory<D>::Create(llm::OS::Devices::SmartCards::SmartCardTriggerType const& triggerType) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISmartCardTriggerFactory)->Create(static_cast<int32_t>(triggerType), &trigger));
        return llm::OS::ApplicationModel::Background::SmartCardTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SmsMessageReceivedTrigger) consume_Windows_ApplicationModel_Background_ISmsMessageReceivedTriggerFactory<D>::Create(llm::OS::Devices::Sms::SmsFilterRules const& filterRules) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory)->Create(*(void**)(&filterRules), &value));
        return llm::OS::ApplicationModel::Background::SmsMessageReceivedTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_ISocketActivityTrigger<D>::IsWakeFromLowPowerSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISocketActivityTrigger)->get_IsWakeFromLowPowerSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::StorageLibraryChangeTrackerTrigger) consume_Windows_ApplicationModel_Background_IStorageLibraryChangeTrackerTriggerFactory<D>::Create(llm::OS::Storage::StorageLibraryChangeTracker const& tracker) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IStorageLibraryChangeTrackerTriggerFactory)->Create(*(void**)(&tracker), &result));
        return llm::OS::ApplicationModel::Background::StorageLibraryChangeTrackerTrigger{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger) consume_Windows_ApplicationModel_Background_IStorageLibraryContentChangedTriggerStatics<D>::Create(llm::OS::Storage::StorageLibrary const& storageLibrary) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics)->Create(*(void**)(&storageLibrary), &result));
        return llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger) consume_Windows_ApplicationModel_Background_IStorageLibraryContentChangedTriggerStatics<D>::CreateFromLibraries(param::iterable<llm::OS::Storage::StorageLibrary> const& storageLibraries) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics)->CreateFromLibraries(*(void**)(&storageLibraries), &result));
        return llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SystemConditionType) consume_Windows_ApplicationModel_Background_ISystemCondition<D>::ConditionType() const
    {
        llm::OS::ApplicationModel::Background::SystemConditionType conditionType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISystemCondition)->get_ConditionType(reinterpret_cast<int32_t*>(&conditionType)));
        return conditionType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SystemCondition) consume_Windows_ApplicationModel_Background_ISystemConditionFactory<D>::Create(llm::OS::ApplicationModel::Background::SystemConditionType const& conditionType) const
    {
        void* condition{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISystemConditionFactory)->Create(static_cast<int32_t>(conditionType), &condition));
        return llm::OS::ApplicationModel::Background::SystemCondition{ condition, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_ISystemTrigger<D>::OneShot() const
    {
        bool oneShot{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISystemTrigger)->get_OneShot(&oneShot));
        return oneShot;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SystemTriggerType) consume_Windows_ApplicationModel_Background_ISystemTrigger<D>::TriggerType() const
    {
        llm::OS::ApplicationModel::Background::SystemTriggerType triggerType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISystemTrigger)->get_TriggerType(reinterpret_cast<int32_t*>(&triggerType)));
        return triggerType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::SystemTrigger) consume_Windows_ApplicationModel_Background_ISystemTriggerFactory<D>::Create(llm::OS::ApplicationModel::Background::SystemTriggerType const& triggerType, bool oneShot) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ISystemTriggerFactory)->Create(static_cast<int32_t>(triggerType), oneShot, &trigger));
        return llm::OS::ApplicationModel::Background::SystemTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Background_ITimeTrigger<D>::FreshnessTime() const
    {
        uint32_t freshnessTime{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ITimeTrigger)->get_FreshnessTime(&freshnessTime));
        return freshnessTime;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Background_ITimeTrigger<D>::OneShot() const
    {
        bool oneShot{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ITimeTrigger)->get_OneShot(&oneShot));
        return oneShot;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::TimeTrigger) consume_Windows_ApplicationModel_Background_ITimeTriggerFactory<D>::Create(uint32_t freshnessTime, bool oneShot) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::ITimeTriggerFactory)->Create(freshnessTime, oneShot, &trigger));
        return llm::OS::ApplicationModel::Background::TimeTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::ToastNotificationActionTrigger) consume_Windows_ApplicationModel_Background_IToastNotificationActionTriggerFactory<D>::Create(param::hstring const& applicationId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IToastNotificationActionTriggerFactory)->Create(*(void**)(&applicationId), &value));
        return llm::OS::ApplicationModel::Background::ToastNotificationActionTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger) consume_Windows_ApplicationModel_Background_IToastNotificationHistoryChangedTriggerFactory<D>::Create(param::hstring const& applicationId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory)->Create(*(void**)(&applicationId), &value));
        return llm::OS::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::UserNotificationChangedTrigger) consume_Windows_ApplicationModel_Background_IUserNotificationChangedTriggerFactory<D>::Create(llm::OS::UI::Notifications::NotificationKinds const& notificationKinds) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Background::IUserNotificationChangedTriggerFactory)->Create(static_cast<uint32_t>(notificationKinds), &value));
        return llm::OS::ApplicationModel::Background::UserNotificationChangedTrigger{ value, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler, H> final : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, int32_t reason) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskCancellationReason const*>(&reason));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler, H> final : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* args) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventArgs const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler, H> final : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* args) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventArgs const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IActivitySensorTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IActivitySensorTrigger>
    {
        int32_t __stdcall get_SubscribedActivities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sensors::ActivityType>>(this->shim().SubscribedActivities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReportInterval(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ReportInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedActivities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sensors::ActivityType>>(this->shim().SupportedActivities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinimumReportInterval(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MinimumReportInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IActivitySensorTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IActivitySensorTriggerFactory>
    {
        int32_t __stdcall Create(uint32_t reportIntervalInMilliseconds, void** activityTrigger) noexcept final try
        {
            clear_abi(activityTrigger);
            typename D::abi_guard guard(this->shim());
            *activityTrigger = detach_from<llm::OS::ApplicationModel::Background::ActivitySensorTrigger>(this->shim().Create(reportIntervalInMilliseconds));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IAlarmApplicationManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IAlarmApplicationManagerStatics>
    {
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::AlarmAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatus(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::ApplicationModel::Background::AlarmAccessStatus>(this->shim().GetAccessStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IAppBroadcastTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IAppBroadcastTrigger>
    {
        int32_t __stdcall put_ProviderInfo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProviderInfo(*reinterpret_cast<llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo>(this->shim().ProviderInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IAppBroadcastTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IAppBroadcastTriggerFactory>
    {
        int32_t __stdcall CreateAppBroadcastTrigger(void* providerKey, void** broadcastTrigger) noexcept final try
        {
            clear_abi(broadcastTrigger);
            typename D::abi_guard guard(this->shim());
            *broadcastTrigger = detach_from<llm::OS::ApplicationModel::Background::AppBroadcastTrigger>(this->shim().CreateAppBroadcastTrigger(*reinterpret_cast<hstring const*>(&providerKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo> : produce_base<D, llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo>
    {
        int32_t __stdcall put_DisplayNameResource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayNameResource(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayNameResource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayNameResource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LogoResource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogoResource(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LogoResource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LogoResource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VideoKeyFrameInterval(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoKeyFrameInterval(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoKeyFrameInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().VideoKeyFrameInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxVideoBitrate(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxVideoBitrate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxVideoBitrate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxVideoBitrate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxVideoWidth(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxVideoWidth(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxVideoWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxVideoWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxVideoHeight(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxVideoHeight(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxVideoHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxVideoHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IApplicationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IApplicationTrigger>
    {
        int32_t __stdcall RequestAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>>(this->shim().RequestAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAsyncWithArguments(void* arguments, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::ApplicationTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&arguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IApplicationTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Background::IApplicationTriggerDetails>
    {
        int32_t __stdcall get_Arguments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Arguments());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger>
    {
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundCondition> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundCondition>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics>
    {
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessForApplicationAsync(void* applicationId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>>(this->shim().RequestAccessAsync(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAccess() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAccess();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAccessForApplication(void* applicationId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAccess(*reinterpret_cast<hstring const*>(&applicationId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatus(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>(this->shim().GetAccessStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatusForApplication(void* applicationId, int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>(this->shim().GetAccessStatus(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics2>
    {
        int32_t __stdcall RequestAccessKindAsync(int32_t requestedAccess, void* reason, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestAccessKindAsync(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const*>(&requestedAccess), *reinterpret_cast<hstring const*>(&reason)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3>
    {
        int32_t __stdcall RequestAccessKindForModernStandbyAsync(int32_t requestedAccess, void* reason, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestAccessKindForModernStandbyAsync(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const*>(&requestedAccess), *reinterpret_cast<hstring const*>(&reason)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatusForModernStandby(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>(this->shim().GetAccessStatusForModernStandby());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatusForModernStandbyForApplication(void* applicationId, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>(this->shim().GetAccessStatusForModernStandby(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTask> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTask>
    {
        int32_t __stdcall Run(void* taskInstance) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Run(*reinterpret_cast<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const*>(&taskInstance));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder>
    {
        int32_t __stdcall put_TaskEntryPoint(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TaskEntryPoint(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TaskEntryPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TaskEntryPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetTrigger(void* trigger) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTrigger(*reinterpret_cast<llm::OS::ApplicationModel::Background::IBackgroundTrigger const*>(&trigger));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddCondition(void* condition) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddCondition(*reinterpret_cast<llm::OS::ApplicationModel::Background::IBackgroundCondition const*>(&condition));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
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
        int32_t __stdcall Register(void** task) noexcept final try
        {
            clear_abi(task);
            typename D::abi_guard guard(this->shim());
            *task = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistration>(this->shim().Register());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2>
    {
        int32_t __stdcall put_CancelOnConditionLoss(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelOnConditionLoss(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CancelOnConditionLoss(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CancelOnConditionLoss());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3>
    {
        int32_t __stdcall put_IsNetworkRequested(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsNetworkRequested(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsNetworkRequested(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsNetworkRequested());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4>
    {
        int32_t __stdcall get_TaskGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(this->shim().TaskGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TaskGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TaskGroup(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder5> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder5>
    {
        int32_t __stdcall SetTaskEntryPointClsid(llm::guid TaskEntryPoint) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTaskEntryPointClsid(*reinterpret_cast<llm::guid const*>(&TaskEntryPoint));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs>
    {
        int32_t __stdcall get_InstanceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().InstanceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckResult() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CheckResult();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance>
    {
        int32_t __stdcall get_InstanceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().InstanceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Task(void** task) noexcept final try
        {
            clear_abi(task);
            typename D::abi_guard guard(this->shim());
            *task = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistration>(this->shim().Task());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Progress(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriggerDetails(void** triggerDetails) noexcept final try
        {
            clear_abi(triggerDetails);
            typename D::abi_guard guard(this->shim());
            *triggerDetails = detach_from<llm::OS::Foundation::IInspectable>(this->shim().TriggerDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Canceled(void* cancelHandler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Canceled(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskCanceledEventHandler const*>(&cancelHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Canceled(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Canceled(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_SuspendedCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SuspendedCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance2> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance2>
    {
        int32_t __stdcall GetThrottleCount(int32_t counter, uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().GetThrottleCount(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskThrottleCounter const*>(&counter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance4> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance4>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs>
    {
        int32_t __stdcall get_InstanceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().InstanceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>
    {
        int32_t __stdcall get_TaskId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().TaskId());
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
        int32_t __stdcall add_Progress(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Progress(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Progress(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_Completed(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Completed(*reinterpret_cast<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Completed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall Unregister(bool cancelTask) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister(cancelTask);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2>
    {
        int32_t __stdcall get_Trigger(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::IBackgroundTrigger>(this->shim().Trigger());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3>
    {
        int32_t __stdcall get_TaskGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(this->shim().TaskGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
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
        int32_t __stdcall add_BackgroundActivated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BackgroundActivated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup, llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BackgroundActivated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundActivated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_AllTasks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::BackgroundTaskRegistration>>(this->shim().AllTasks());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroupFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroupFactory>
    {
        int32_t __stdcall Create(void* id, void** group) noexcept final try
        {
            clear_abi(group);
            typename D::abi_guard guard(this->shim());
            *group = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(this->shim().Create(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithName(void* id, void* name, void** group) noexcept final try
        {
            clear_abi(group);
            typename D::abi_guard guard(this->shim());
            *group = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(this->shim().CreateWithName(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics>
    {
        int32_t __stdcall get_AllTasks(void** tasks) noexcept final try
        {
            clear_abi(tasks);
            typename D::abi_guard guard(this->shim());
            *tasks = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>>(this->shim().AllTasks());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics2> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics2>
    {
        int32_t __stdcall get_AllTaskGroups(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>>(this->shim().AllTaskGroups());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTaskGroup(void* groupId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(this->shim().GetTaskGroup(*reinterpret_cast<hstring const*>(&groupId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBackgroundWorkCostStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IBackgroundWorkCostStatics>
    {
        int32_t __stdcall get_CurrentBackgroundWorkCost(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::BackgroundWorkCostValue>(this->shim().CurrentBackgroundWorkCost());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger>
    {
        int32_t __stdcall get_Advertisement(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement>(this->shim().Advertisement());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2> : produce_base<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2>
    {
        int32_t __stdcall get_PreferredTransmitPowerLevelInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int16_t>>(this->shim().PreferredTransmitPowerLevelInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredTransmitPowerLevelInDBm(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredTransmitPowerLevelInDBm(*reinterpret_cast<llm::OS::Foundation::IReference<int16_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UseExtendedFormat(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().UseExtendedFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UseExtendedFormat(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UseExtendedFormat(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAnonymous(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAnonymous());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsAnonymous(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAnonymous(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeTransmitPowerLevel(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeTransmitPowerLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeTransmitPowerLevel(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeTransmitPowerLevel(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>
    {
        int32_t __stdcall get_MinSamplingInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().MinSamplingInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxSamplingInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().MaxSamplingInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinOutOfRangeTimeout(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().MinOutOfRangeTimeout());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxOutOfRangeTimeout(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().MaxOutOfRangeTimeout());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalStrengthFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter>(this->shim().SignalStrengthFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalStrengthFilter(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalStrengthFilter(*reinterpret_cast<llm::OS::Devices::Bluetooth::BluetoothSignalStrengthFilter const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdvertisementFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter>(this->shim().AdvertisementFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AdvertisementFilter(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvertisementFilter(*reinterpret_cast<llm::OS::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2> : produce_base<D, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2>
    {
        int32_t __stdcall get_AllowExtendedAdvertisements(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowExtendedAdvertisements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowExtendedAdvertisements(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowExtendedAdvertisements(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>
    {
        int32_t __stdcall get_UpdateTarget(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Provider::CachedFileTarget>(this->shim().UpdateTarget());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateRequest(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Provider::FileUpdateRequest>(this->shim().UpdateRequest());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanRequestUserInput(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanRequestUserInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IContentPrefetchTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IContentPrefetchTrigger>
    {
        int32_t __stdcall get_WaitInterval(int64_t* waitInterval) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(waitInterval);
            typename D::abi_guard guard(this->shim());
            *waitInterval = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().WaitInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IContentPrefetchTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IContentPrefetchTriggerFactory>
    {
        int32_t __stdcall Create(int64_t waitInterval, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::ContentPrefetchTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&waitInterval)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger>
    {
        int32_t __stdcall get_TriggerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TriggerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Recurrence(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence>(this->shim().Recurrence());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ICustomSystemEventTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ICustomSystemEventTriggerFactory>
    {
        int32_t __stdcall Create(void* triggerId, int32_t recurrence, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::CustomSystemEventTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&triggerId), *reinterpret_cast<llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence const*>(&recurrence)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanMaintainConnection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanMaintainConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaintainConnection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().MaintainConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaintainConnection(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaintainConnection(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics>
    {
        int32_t __stdcall FromIdAsync(void* deviceId, void** deviceChangeTrigger) noexcept final try
        {
            clear_abi(deviceChangeTrigger);
            typename D::abi_guard guard(this->shim());
            *deviceChangeTrigger = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceConnectionChangeTrigger>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger>
    {
        int32_t __stdcall get_TriggerQualifier(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TriggerQualifier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OneShot(bool* oneShot) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_from<bool>(this->shim().OneShot());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory>
    {
        int32_t __stdcall Create(void* triggerQualifier, bool oneShot, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::DeviceManufacturerNotificationTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&triggerQualifier), oneShot));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceServicingTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceServicingTrigger>
    {
        int32_t __stdcall RequestAsyncSimple(void* deviceId, int64_t expectedDuration, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&expectedDuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAsyncWithArguments(void* deviceId, int64_t expectedDuration, void* arguments, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&expectedDuration), *reinterpret_cast<hstring const*>(&arguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceUseTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceUseTrigger>
    {
        int32_t __stdcall RequestAsyncSimple(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAsyncWithArguments(void* deviceId, void* arguments, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::DeviceTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<hstring const*>(&arguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger>
    {
        int32_t __stdcall get_Characteristic(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic>(this->shim().Characteristic());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger2> : produce_base<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger2>
    {
        int32_t __stdcall get_EventTriggeringMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode>(this->shim().EventTriggeringMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory>
    {
        int32_t __stdcall Create(void* characteristic, void** gattCharacteristicNotificationTrigger) noexcept final try
        {
            clear_abi(gattCharacteristicNotificationTrigger);
            typename D::abi_guard guard(this->shim());
            *gattCharacteristicNotificationTrigger = detach_from<llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const*>(&characteristic)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory2> : produce_base<D, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory2>
    {
        int32_t __stdcall CreateWithEventTriggeringMode(void* characteristic, int32_t eventTriggeringMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const*>(&characteristic), *reinterpret_cast<llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode const*>(&eventTriggeringMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger>
    {
        int32_t __stdcall get_TriggerId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TriggerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Service(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattLocalService>(this->shim().Service());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AdvertisingParameters(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvertisingParameters(*reinterpret_cast<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattServiceProviderAdvertisingParameters const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdvertisingParameters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattServiceProviderAdvertisingParameters>(this->shim().AdvertisingParameters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult> : produce_base<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult>
    {
        int32_t __stdcall get_Trigger(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::GattServiceProviderTrigger>(this->shim().Trigger());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::BluetoothError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerStatics>
    {
        int32_t __stdcall CreateAsync(void* triggerId, llm::guid serviceUuid, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::GattServiceProviderTriggerResult>>(this->shim().CreateAsync(*reinterpret_cast<hstring const*>(&triggerId), *reinterpret_cast<llm::guid const*>(&serviceUuid)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IGeovisitTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IGeovisitTrigger>
    {
        int32_t __stdcall get_MonitoringScope(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Geolocation::VisitMonitoringScope>(this->shim().MonitoringScope());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MonitoringScope(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MonitoringScope(*reinterpret_cast<llm::OS::Devices::Geolocation::VisitMonitoringScope const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ILocationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ILocationTrigger>
    {
        int32_t __stdcall get_TriggerType(int32_t* triggerType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_from<llm::OS::ApplicationModel::Background::LocationTriggerType>(this->shim().TriggerType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ILocationTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ILocationTriggerFactory>
    {
        int32_t __stdcall Create(int32_t triggerType, void** locationTrigger) noexcept final try
        {
            clear_abi(locationTrigger);
            typename D::abi_guard guard(this->shim());
            *locationTrigger = detach_from<llm::OS::ApplicationModel::Background::LocationTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::ApplicationModel::Background::LocationTriggerType const*>(&triggerType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IMaintenanceTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IMaintenanceTrigger>
    {
        int32_t __stdcall get_FreshnessTime(uint32_t* freshnessTime) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *freshnessTime = detach_from<uint32_t>(this->shim().FreshnessTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OneShot(bool* oneShot) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_from<bool>(this->shim().OneShot());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IMaintenanceTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IMaintenanceTriggerFactory>
    {
        int32_t __stdcall Create(uint32_t freshnessTime, bool oneShot, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::MaintenanceTrigger>(this->shim().Create(freshnessTime, oneShot));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IMediaProcessingTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IMediaProcessingTrigger>
    {
        int32_t __stdcall RequestAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>>(this->shim().RequestAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAsyncWithArguments(void* arguments, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::MediaProcessingTriggerResult>>(this->shim().RequestAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&arguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger>
    {
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory>
    {
        int32_t __stdcall Create(void* networkAccountId, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::NetworkOperatorNotificationTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IPhoneTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IPhoneTrigger>
    {
        int32_t __stdcall get_OneShot(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().OneShot());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriggerType(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType>(this->shim().TriggerType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IPhoneTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IPhoneTriggerFactory>
    {
        int32_t __stdcall Create(int32_t type, bool oneShot, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::PhoneTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType const*>(&type), oneShot));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IPushNotificationTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IPushNotificationTriggerFactory>
    {
        int32_t __stdcall Create(void* applicationId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::PushNotificationTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger>
    {
        int32_t __stdcall get_InboundConnection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Background::RfcommInboundConnectionInformation>(this->shim().InboundConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutboundConnection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation>(this->shim().OutboundConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowMultipleConnections(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowMultipleConnections());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowMultipleConnections(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowMultipleConnections(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtectionLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Sockets::SocketProtectionLevel>(this->shim().ProtectionLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProtectionLevel(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectionLevel(*reinterpret_cast<llm::OS::Networking::Sockets::SocketProtectionLevel const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().RemoteHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemoteHostName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteHostName(*reinterpret_cast<llm::OS::Networking::HostName const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ISensorDataThresholdTriggerFactory>
    {
        int32_t __stdcall Create(void* threshold, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::SensorDataThresholdTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Sensors::ISensorDataThreshold const*>(&threshold)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISmartCardTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ISmartCardTrigger>
    {
        int32_t __stdcall get_TriggerType(int32_t* triggerType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_from<llm::OS::Devices::SmartCards::SmartCardTriggerType>(this->shim().TriggerType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISmartCardTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ISmartCardTriggerFactory>
    {
        int32_t __stdcall Create(int32_t triggerType, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::SmartCardTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::SmartCards::SmartCardTriggerType const*>(&triggerType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory>
    {
        int32_t __stdcall Create(void* filterRules, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::SmsMessageReceivedTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Sms::SmsFilterRules const*>(&filterRules)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISocketActivityTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ISocketActivityTrigger>
    {
        int32_t __stdcall get_IsWakeFromLowPowerSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsWakeFromLowPowerSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IStorageLibraryChangeTrackerTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IStorageLibraryChangeTrackerTriggerFactory>
    {
        int32_t __stdcall Create(void* tracker, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::StorageLibraryChangeTrackerTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Storage::StorageLibraryChangeTracker const*>(&tracker)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics> : produce_base<D, llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics>
    {
        int32_t __stdcall Create(void* storageLibrary, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::Storage::StorageLibrary const*>(&storageLibrary)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromLibraries(void* storageLibraries, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger>(this->shim().CreateFromLibraries(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Storage::StorageLibrary> const*>(&storageLibraries)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISystemCondition> : produce_base<D, llm::OS::ApplicationModel::Background::ISystemCondition>
    {
        int32_t __stdcall get_ConditionType(int32_t* conditionType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *conditionType = detach_from<llm::OS::ApplicationModel::Background::SystemConditionType>(this->shim().ConditionType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISystemConditionFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ISystemConditionFactory>
    {
        int32_t __stdcall Create(int32_t conditionType, void** condition) noexcept final try
        {
            clear_abi(condition);
            typename D::abi_guard guard(this->shim());
            *condition = detach_from<llm::OS::ApplicationModel::Background::SystemCondition>(this->shim().Create(*reinterpret_cast<llm::OS::ApplicationModel::Background::SystemConditionType const*>(&conditionType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISystemTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ISystemTrigger>
    {
        int32_t __stdcall get_OneShot(bool* oneShot) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_from<bool>(this->shim().OneShot());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TriggerType(int32_t* triggerType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *triggerType = detach_from<llm::OS::ApplicationModel::Background::SystemTriggerType>(this->shim().TriggerType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ISystemTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ISystemTriggerFactory>
    {
        int32_t __stdcall Create(int32_t triggerType, bool oneShot, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::SystemTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::ApplicationModel::Background::SystemTriggerType const*>(&triggerType), oneShot));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ITimeTrigger> : produce_base<D, llm::OS::ApplicationModel::Background::ITimeTrigger>
    {
        int32_t __stdcall get_FreshnessTime(uint32_t* freshnessTime) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *freshnessTime = detach_from<uint32_t>(this->shim().FreshnessTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OneShot(bool* oneShot) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *oneShot = detach_from<bool>(this->shim().OneShot());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::ITimeTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::ITimeTriggerFactory>
    {
        int32_t __stdcall Create(uint32_t freshnessTime, bool oneShot, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::TimeTrigger>(this->shim().Create(freshnessTime, oneShot));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IToastNotificationActionTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IToastNotificationActionTriggerFactory>
    {
        int32_t __stdcall Create(void* applicationId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::ToastNotificationActionTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory>
    {
        int32_t __stdcall Create(void* applicationId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger>(this->shim().Create(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Background::IUserNotificationChangedTriggerFactory> : produce_base<D, llm::OS::ApplicationModel::Background::IUserNotificationChangedTriggerFactory>
    {
        int32_t __stdcall Create(uint32_t notificationKinds, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::UserNotificationChangedTrigger>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Notifications::NotificationKinds const*>(&notificationKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Background
{
    inline ActivitySensorTrigger::ActivitySensorTrigger(uint32_t reportIntervalInMilliseconds) :
        ActivitySensorTrigger(impl::call_factory<ActivitySensorTrigger, IActivitySensorTriggerFactory>([&](IActivitySensorTriggerFactory const& f) { return f.Create(reportIntervalInMilliseconds); }))
    {
    }
    inline auto AlarmApplicationManager::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::AlarmAccessStatus>(*)(IAlarmApplicationManagerStatics const&), AlarmApplicationManager, IAlarmApplicationManagerStatics>([](IAlarmApplicationManagerStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto AlarmApplicationManager::GetAccessStatus()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Background::AlarmAccessStatus(*)(IAlarmApplicationManagerStatics const&), AlarmApplicationManager, IAlarmApplicationManagerStatics>([](IAlarmApplicationManagerStatics const& f) { return f.GetAccessStatus(); });
    }
    inline AppBroadcastTrigger::AppBroadcastTrigger(param::hstring const& providerKey) :
        AppBroadcastTrigger(impl::call_factory<AppBroadcastTrigger, IAppBroadcastTriggerFactory>([&](IAppBroadcastTriggerFactory const& f) { return f.CreateAppBroadcastTrigger(providerKey); }))
    {
    }
    inline ApplicationTrigger::ApplicationTrigger() :
        ApplicationTrigger(impl::call_factory_cast<ApplicationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ApplicationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ApplicationTrigger>(); }))
    {
    }
    inline AppointmentStoreNotificationTrigger::AppointmentStoreNotificationTrigger() :
        AppointmentStoreNotificationTrigger(impl::call_factory_cast<AppointmentStoreNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), AppointmentStoreNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AppointmentStoreNotificationTrigger>(); }))
    {
    }
    inline auto BackgroundExecutionManager::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Background::BackgroundAccessStatus>(*)(IBackgroundExecutionManagerStatics const&), BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([](IBackgroundExecutionManagerStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto BackgroundExecutionManager::RequestAccessAsync(param::hstring const& applicationId)
    {
        return impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([&](IBackgroundExecutionManagerStatics const& f) { return f.RequestAccessAsync(applicationId); });
    }
    inline auto BackgroundExecutionManager::RemoveAccess()
    {
        impl::call_factory_cast<void(*)(IBackgroundExecutionManagerStatics const&), BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([](IBackgroundExecutionManagerStatics const& f) { return f.RemoveAccess(); });
    }
    inline auto BackgroundExecutionManager::RemoveAccess(param::hstring const& applicationId)
    {
        impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([&](IBackgroundExecutionManagerStatics const& f) { return f.RemoveAccess(applicationId); });
    }
    inline auto BackgroundExecutionManager::GetAccessStatus()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Background::BackgroundAccessStatus(*)(IBackgroundExecutionManagerStatics const&), BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([](IBackgroundExecutionManagerStatics const& f) { return f.GetAccessStatus(); });
    }
    inline auto BackgroundExecutionManager::GetAccessStatus(param::hstring const& applicationId)
    {
        return impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics>([&](IBackgroundExecutionManagerStatics const& f) { return f.GetAccessStatus(applicationId); });
    }
    inline auto BackgroundExecutionManager::RequestAccessKindAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason)
    {
        return impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics2>([&](IBackgroundExecutionManagerStatics2 const& f) { return f.RequestAccessKindAsync(requestedAccess, reason); });
    }
    inline auto BackgroundExecutionManager::RequestAccessKindForModernStandbyAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason)
    {
        return impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics3>([&](IBackgroundExecutionManagerStatics3 const& f) { return f.RequestAccessKindForModernStandbyAsync(requestedAccess, reason); });
    }
    inline auto BackgroundExecutionManager::GetAccessStatusForModernStandby()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Background::BackgroundAccessStatus(*)(IBackgroundExecutionManagerStatics3 const&), BackgroundExecutionManager, IBackgroundExecutionManagerStatics3>([](IBackgroundExecutionManagerStatics3 const& f) { return f.GetAccessStatusForModernStandby(); });
    }
    inline auto BackgroundExecutionManager::GetAccessStatusForModernStandby(param::hstring const& applicationId)
    {
        return impl::call_factory<BackgroundExecutionManager, IBackgroundExecutionManagerStatics3>([&](IBackgroundExecutionManagerStatics3 const& f) { return f.GetAccessStatusForModernStandby(applicationId); });
    }
    inline BackgroundTaskBuilder::BackgroundTaskBuilder() :
        BackgroundTaskBuilder(impl::call_factory_cast<BackgroundTaskBuilder(*)(llm::OS::Foundation::IActivationFactory const&), BackgroundTaskBuilder>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BackgroundTaskBuilder>(); }))
    {
    }
    inline auto BackgroundTaskRegistration::AllTasks()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>(*)(IBackgroundTaskRegistrationStatics const&), BackgroundTaskRegistration, IBackgroundTaskRegistrationStatics>([](IBackgroundTaskRegistrationStatics const& f) { return f.AllTasks(); });
    }
    inline auto BackgroundTaskRegistration::AllTaskGroups()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup>(*)(IBackgroundTaskRegistrationStatics2 const&), BackgroundTaskRegistration, IBackgroundTaskRegistrationStatics2>([](IBackgroundTaskRegistrationStatics2 const& f) { return f.AllTaskGroups(); });
    }
    inline auto BackgroundTaskRegistration::GetTaskGroup(param::hstring const& groupId)
    {
        return impl::call_factory<BackgroundTaskRegistration, IBackgroundTaskRegistrationStatics2>([&](IBackgroundTaskRegistrationStatics2 const& f) { return f.GetTaskGroup(groupId); });
    }
    inline BackgroundTaskRegistrationGroup::BackgroundTaskRegistrationGroup(param::hstring const& id) :
        BackgroundTaskRegistrationGroup(impl::call_factory<BackgroundTaskRegistrationGroup, IBackgroundTaskRegistrationGroupFactory>([&](IBackgroundTaskRegistrationGroupFactory const& f) { return f.Create(id); }))
    {
    }
    inline BackgroundTaskRegistrationGroup::BackgroundTaskRegistrationGroup(param::hstring const& id, param::hstring const& name) :
        BackgroundTaskRegistrationGroup(impl::call_factory<BackgroundTaskRegistrationGroup, IBackgroundTaskRegistrationGroupFactory>([&](IBackgroundTaskRegistrationGroupFactory const& f) { return f.CreateWithName(id, name); }))
    {
    }
    inline auto BackgroundWorkCost::CurrentBackgroundWorkCost()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Background::BackgroundWorkCostValue(*)(IBackgroundWorkCostStatics const&), BackgroundWorkCost, IBackgroundWorkCostStatics>([](IBackgroundWorkCostStatics const& f) { return f.CurrentBackgroundWorkCost(); });
    }
    inline BluetoothLEAdvertisementPublisherTrigger::BluetoothLEAdvertisementPublisherTrigger() :
        BluetoothLEAdvertisementPublisherTrigger(impl::call_factory_cast<BluetoothLEAdvertisementPublisherTrigger(*)(llm::OS::Foundation::IActivationFactory const&), BluetoothLEAdvertisementPublisherTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BluetoothLEAdvertisementPublisherTrigger>(); }))
    {
    }
    inline BluetoothLEAdvertisementWatcherTrigger::BluetoothLEAdvertisementWatcherTrigger() :
        BluetoothLEAdvertisementWatcherTrigger(impl::call_factory_cast<BluetoothLEAdvertisementWatcherTrigger(*)(llm::OS::Foundation::IActivationFactory const&), BluetoothLEAdvertisementWatcherTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<BluetoothLEAdvertisementWatcherTrigger>(); }))
    {
    }
    inline CachedFileUpdaterTrigger::CachedFileUpdaterTrigger() :
        CachedFileUpdaterTrigger(impl::call_factory_cast<CachedFileUpdaterTrigger(*)(llm::OS::Foundation::IActivationFactory const&), CachedFileUpdaterTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CachedFileUpdaterTrigger>(); }))
    {
    }
    inline ChatMessageNotificationTrigger::ChatMessageNotificationTrigger() :
        ChatMessageNotificationTrigger(impl::call_factory_cast<ChatMessageNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ChatMessageNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ChatMessageNotificationTrigger>(); }))
    {
    }
    inline ChatMessageReceivedNotificationTrigger::ChatMessageReceivedNotificationTrigger() :
        ChatMessageReceivedNotificationTrigger(impl::call_factory_cast<ChatMessageReceivedNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ChatMessageReceivedNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ChatMessageReceivedNotificationTrigger>(); }))
    {
    }
    inline CommunicationBlockingAppSetAsActiveTrigger::CommunicationBlockingAppSetAsActiveTrigger() :
        CommunicationBlockingAppSetAsActiveTrigger(impl::call_factory_cast<CommunicationBlockingAppSetAsActiveTrigger(*)(llm::OS::Foundation::IActivationFactory const&), CommunicationBlockingAppSetAsActiveTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CommunicationBlockingAppSetAsActiveTrigger>(); }))
    {
    }
    inline ContactStoreNotificationTrigger::ContactStoreNotificationTrigger() :
        ContactStoreNotificationTrigger(impl::call_factory_cast<ContactStoreNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ContactStoreNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ContactStoreNotificationTrigger>(); }))
    {
    }
    inline ContentPrefetchTrigger::ContentPrefetchTrigger() :
        ContentPrefetchTrigger(impl::call_factory_cast<ContentPrefetchTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ContentPrefetchTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ContentPrefetchTrigger>(); }))
    {
    }
    inline ContentPrefetchTrigger::ContentPrefetchTrigger(llm::OS::Foundation::TimeSpan const& waitInterval) :
        ContentPrefetchTrigger(impl::call_factory<ContentPrefetchTrigger, IContentPrefetchTriggerFactory>([&](IContentPrefetchTriggerFactory const& f) { return f.Create(waitInterval); }))
    {
    }
    inline ConversationalAgentTrigger::ConversationalAgentTrigger() :
        ConversationalAgentTrigger(impl::call_factory_cast<ConversationalAgentTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ConversationalAgentTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ConversationalAgentTrigger>(); }))
    {
    }
    inline CustomSystemEventTrigger::CustomSystemEventTrigger(param::hstring const& triggerId, llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence const& recurrence) :
        CustomSystemEventTrigger(impl::call_factory<CustomSystemEventTrigger, ICustomSystemEventTriggerFactory>([&](ICustomSystemEventTriggerFactory const& f) { return f.Create(triggerId, recurrence); }))
    {
    }
    inline auto DeviceConnectionChangeTrigger::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<DeviceConnectionChangeTrigger, IDeviceConnectionChangeTriggerStatics>([&](IDeviceConnectionChangeTriggerStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline DeviceManufacturerNotificationTrigger::DeviceManufacturerNotificationTrigger(param::hstring const& triggerQualifier, bool oneShot) :
        DeviceManufacturerNotificationTrigger(impl::call_factory<DeviceManufacturerNotificationTrigger, IDeviceManufacturerNotificationTriggerFactory>([&](IDeviceManufacturerNotificationTriggerFactory const& f) { return f.Create(triggerQualifier, oneShot); }))
    {
    }
    inline DeviceServicingTrigger::DeviceServicingTrigger() :
        DeviceServicingTrigger(impl::call_factory_cast<DeviceServicingTrigger(*)(llm::OS::Foundation::IActivationFactory const&), DeviceServicingTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DeviceServicingTrigger>(); }))
    {
    }
    inline DeviceUseTrigger::DeviceUseTrigger() :
        DeviceUseTrigger(impl::call_factory_cast<DeviceUseTrigger(*)(llm::OS::Foundation::IActivationFactory const&), DeviceUseTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DeviceUseTrigger>(); }))
    {
    }
    inline EmailStoreNotificationTrigger::EmailStoreNotificationTrigger() :
        EmailStoreNotificationTrigger(impl::call_factory_cast<EmailStoreNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), EmailStoreNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<EmailStoreNotificationTrigger>(); }))
    {
    }
    inline GattCharacteristicNotificationTrigger::GattCharacteristicNotificationTrigger(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic) :
        GattCharacteristicNotificationTrigger(impl::call_factory<GattCharacteristicNotificationTrigger, IGattCharacteristicNotificationTriggerFactory>([&](IGattCharacteristicNotificationTriggerFactory const& f) { return f.Create(characteristic); }))
    {
    }
    inline GattCharacteristicNotificationTrigger::GattCharacteristicNotificationTrigger(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic, llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode const& eventTriggeringMode) :
        GattCharacteristicNotificationTrigger(impl::call_factory<GattCharacteristicNotificationTrigger, IGattCharacteristicNotificationTriggerFactory2>([&](IGattCharacteristicNotificationTriggerFactory2 const& f) { return f.Create(characteristic, eventTriggeringMode); }))
    {
    }
    inline auto GattServiceProviderTrigger::CreateAsync(param::hstring const& triggerId, llm::guid const& serviceUuid)
    {
        return impl::call_factory<GattServiceProviderTrigger, IGattServiceProviderTriggerStatics>([&](IGattServiceProviderTriggerStatics const& f) { return f.CreateAsync(triggerId, serviceUuid); });
    }
    inline GeovisitTrigger::GeovisitTrigger() :
        GeovisitTrigger(impl::call_factory_cast<GeovisitTrigger(*)(llm::OS::Foundation::IActivationFactory const&), GeovisitTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<GeovisitTrigger>(); }))
    {
    }
    inline LocationTrigger::LocationTrigger(llm::OS::ApplicationModel::Background::LocationTriggerType const& triggerType) :
        LocationTrigger(impl::call_factory<LocationTrigger, ILocationTriggerFactory>([&](ILocationTriggerFactory const& f) { return f.Create(triggerType); }))
    {
    }
    inline MaintenanceTrigger::MaintenanceTrigger(uint32_t freshnessTime, bool oneShot) :
        MaintenanceTrigger(impl::call_factory<MaintenanceTrigger, IMaintenanceTriggerFactory>([&](IMaintenanceTriggerFactory const& f) { return f.Create(freshnessTime, oneShot); }))
    {
    }
    inline MediaProcessingTrigger::MediaProcessingTrigger() :
        MediaProcessingTrigger(impl::call_factory_cast<MediaProcessingTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MediaProcessingTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaProcessingTrigger>(); }))
    {
    }
    inline MobileBroadbandDeviceServiceNotificationTrigger::MobileBroadbandDeviceServiceNotificationTrigger() :
        MobileBroadbandDeviceServiceNotificationTrigger(impl::call_factory_cast<MobileBroadbandDeviceServiceNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandDeviceServiceNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandDeviceServiceNotificationTrigger>(); }))
    {
    }
    inline MobileBroadbandPcoDataChangeTrigger::MobileBroadbandPcoDataChangeTrigger() :
        MobileBroadbandPcoDataChangeTrigger(impl::call_factory_cast<MobileBroadbandPcoDataChangeTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandPcoDataChangeTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandPcoDataChangeTrigger>(); }))
    {
    }
    inline MobileBroadbandPinLockStateChangeTrigger::MobileBroadbandPinLockStateChangeTrigger() :
        MobileBroadbandPinLockStateChangeTrigger(impl::call_factory_cast<MobileBroadbandPinLockStateChangeTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandPinLockStateChangeTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandPinLockStateChangeTrigger>(); }))
    {
    }
    inline MobileBroadbandRadioStateChangeTrigger::MobileBroadbandRadioStateChangeTrigger() :
        MobileBroadbandRadioStateChangeTrigger(impl::call_factory_cast<MobileBroadbandRadioStateChangeTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandRadioStateChangeTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandRadioStateChangeTrigger>(); }))
    {
    }
    inline MobileBroadbandRegistrationStateChangeTrigger::MobileBroadbandRegistrationStateChangeTrigger() :
        MobileBroadbandRegistrationStateChangeTrigger(impl::call_factory_cast<MobileBroadbandRegistrationStateChangeTrigger(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandRegistrationStateChangeTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandRegistrationStateChangeTrigger>(); }))
    {
    }
    inline NetworkOperatorDataUsageTrigger::NetworkOperatorDataUsageTrigger() :
        NetworkOperatorDataUsageTrigger(impl::call_factory_cast<NetworkOperatorDataUsageTrigger(*)(llm::OS::Foundation::IActivationFactory const&), NetworkOperatorDataUsageTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<NetworkOperatorDataUsageTrigger>(); }))
    {
    }
    inline NetworkOperatorHotspotAuthenticationTrigger::NetworkOperatorHotspotAuthenticationTrigger() :
        NetworkOperatorHotspotAuthenticationTrigger(impl::call_factory_cast<NetworkOperatorHotspotAuthenticationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), NetworkOperatorHotspotAuthenticationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<NetworkOperatorHotspotAuthenticationTrigger>(); }))
    {
    }
    inline NetworkOperatorNotificationTrigger::NetworkOperatorNotificationTrigger(param::hstring const& networkAccountId) :
        NetworkOperatorNotificationTrigger(impl::call_factory<NetworkOperatorNotificationTrigger, INetworkOperatorNotificationTriggerFactory>([&](INetworkOperatorNotificationTriggerFactory const& f) { return f.Create(networkAccountId); }))
    {
    }
    inline PaymentAppCanMakePaymentTrigger::PaymentAppCanMakePaymentTrigger() :
        PaymentAppCanMakePaymentTrigger(impl::call_factory_cast<PaymentAppCanMakePaymentTrigger(*)(llm::OS::Foundation::IActivationFactory const&), PaymentAppCanMakePaymentTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PaymentAppCanMakePaymentTrigger>(); }))
    {
    }
    inline PhoneTrigger::PhoneTrigger(llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType const& type, bool oneShot) :
        PhoneTrigger(impl::call_factory<PhoneTrigger, IPhoneTriggerFactory>([&](IPhoneTriggerFactory const& f) { return f.Create(type, oneShot); }))
    {
    }
    inline PushNotificationTrigger::PushNotificationTrigger() :
        PushNotificationTrigger(impl::call_factory_cast<PushNotificationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), PushNotificationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<PushNotificationTrigger>(); }))
    {
    }
    inline PushNotificationTrigger::PushNotificationTrigger(param::hstring const& applicationId) :
        PushNotificationTrigger(impl::call_factory<PushNotificationTrigger, IPushNotificationTriggerFactory>([&](IPushNotificationTriggerFactory const& f) { return f.Create(applicationId); }))
    {
    }
    inline RcsEndUserMessageAvailableTrigger::RcsEndUserMessageAvailableTrigger() :
        RcsEndUserMessageAvailableTrigger(impl::call_factory_cast<RcsEndUserMessageAvailableTrigger(*)(llm::OS::Foundation::IActivationFactory const&), RcsEndUserMessageAvailableTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RcsEndUserMessageAvailableTrigger>(); }))
    {
    }
    inline RfcommConnectionTrigger::RfcommConnectionTrigger() :
        RfcommConnectionTrigger(impl::call_factory_cast<RfcommConnectionTrigger(*)(llm::OS::Foundation::IActivationFactory const&), RfcommConnectionTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RfcommConnectionTrigger>(); }))
    {
    }
    inline SecondaryAuthenticationFactorAuthenticationTrigger::SecondaryAuthenticationFactorAuthenticationTrigger() :
        SecondaryAuthenticationFactorAuthenticationTrigger(impl::call_factory_cast<SecondaryAuthenticationFactorAuthenticationTrigger(*)(llm::OS::Foundation::IActivationFactory const&), SecondaryAuthenticationFactorAuthenticationTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SecondaryAuthenticationFactorAuthenticationTrigger>(); }))
    {
    }
    inline SensorDataThresholdTrigger::SensorDataThresholdTrigger(llm::OS::Devices::Sensors::ISensorDataThreshold const& threshold) :
        SensorDataThresholdTrigger(impl::call_factory<SensorDataThresholdTrigger, ISensorDataThresholdTriggerFactory>([&](ISensorDataThresholdTriggerFactory const& f) { return f.Create(threshold); }))
    {
    }
    inline SmartCardTrigger::SmartCardTrigger(llm::OS::Devices::SmartCards::SmartCardTriggerType const& triggerType) :
        SmartCardTrigger(impl::call_factory<SmartCardTrigger, ISmartCardTriggerFactory>([&](ISmartCardTriggerFactory const& f) { return f.Create(triggerType); }))
    {
    }
    inline SmsMessageReceivedTrigger::SmsMessageReceivedTrigger(llm::OS::Devices::Sms::SmsFilterRules const& filterRules) :
        SmsMessageReceivedTrigger(impl::call_factory<SmsMessageReceivedTrigger, ISmsMessageReceivedTriggerFactory>([&](ISmsMessageReceivedTriggerFactory const& f) { return f.Create(filterRules); }))
    {
    }
    inline SocketActivityTrigger::SocketActivityTrigger() :
        SocketActivityTrigger(impl::call_factory_cast<SocketActivityTrigger(*)(llm::OS::Foundation::IActivationFactory const&), SocketActivityTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SocketActivityTrigger>(); }))
    {
    }
    inline StorageLibraryChangeTrackerTrigger::StorageLibraryChangeTrackerTrigger(llm::OS::Storage::StorageLibraryChangeTracker const& tracker) :
        StorageLibraryChangeTrackerTrigger(impl::call_factory<StorageLibraryChangeTrackerTrigger, IStorageLibraryChangeTrackerTriggerFactory>([&](IStorageLibraryChangeTrackerTriggerFactory const& f) { return f.Create(tracker); }))
    {
    }
    inline auto StorageLibraryContentChangedTrigger::Create(llm::OS::Storage::StorageLibrary const& storageLibrary)
    {
        return impl::call_factory<StorageLibraryContentChangedTrigger, IStorageLibraryContentChangedTriggerStatics>([&](IStorageLibraryContentChangedTriggerStatics const& f) { return f.Create(storageLibrary); });
    }
    inline auto StorageLibraryContentChangedTrigger::CreateFromLibraries(param::iterable<llm::OS::Storage::StorageLibrary> const& storageLibraries)
    {
        return impl::call_factory<StorageLibraryContentChangedTrigger, IStorageLibraryContentChangedTriggerStatics>([&](IStorageLibraryContentChangedTriggerStatics const& f) { return f.CreateFromLibraries(storageLibraries); });
    }
    inline SystemCondition::SystemCondition(llm::OS::ApplicationModel::Background::SystemConditionType const& conditionType) :
        SystemCondition(impl::call_factory<SystemCondition, ISystemConditionFactory>([&](ISystemConditionFactory const& f) { return f.Create(conditionType); }))
    {
    }
    inline SystemTrigger::SystemTrigger(llm::OS::ApplicationModel::Background::SystemTriggerType const& triggerType, bool oneShot) :
        SystemTrigger(impl::call_factory<SystemTrigger, ISystemTriggerFactory>([&](ISystemTriggerFactory const& f) { return f.Create(triggerType, oneShot); }))
    {
    }
    inline TetheringEntitlementCheckTrigger::TetheringEntitlementCheckTrigger() :
        TetheringEntitlementCheckTrigger(impl::call_factory_cast<TetheringEntitlementCheckTrigger(*)(llm::OS::Foundation::IActivationFactory const&), TetheringEntitlementCheckTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<TetheringEntitlementCheckTrigger>(); }))
    {
    }
    inline TimeTrigger::TimeTrigger(uint32_t freshnessTime, bool oneShot) :
        TimeTrigger(impl::call_factory<TimeTrigger, ITimeTriggerFactory>([&](ITimeTriggerFactory const& f) { return f.Create(freshnessTime, oneShot); }))
    {
    }
    inline ToastNotificationActionTrigger::ToastNotificationActionTrigger() :
        ToastNotificationActionTrigger(impl::call_factory_cast<ToastNotificationActionTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ToastNotificationActionTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ToastNotificationActionTrigger>(); }))
    {
    }
    inline ToastNotificationActionTrigger::ToastNotificationActionTrigger(param::hstring const& applicationId) :
        ToastNotificationActionTrigger(impl::call_factory<ToastNotificationActionTrigger, IToastNotificationActionTriggerFactory>([&](IToastNotificationActionTriggerFactory const& f) { return f.Create(applicationId); }))
    {
    }
    inline ToastNotificationHistoryChangedTrigger::ToastNotificationHistoryChangedTrigger() :
        ToastNotificationHistoryChangedTrigger(impl::call_factory_cast<ToastNotificationHistoryChangedTrigger(*)(llm::OS::Foundation::IActivationFactory const&), ToastNotificationHistoryChangedTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ToastNotificationHistoryChangedTrigger>(); }))
    {
    }
    inline ToastNotificationHistoryChangedTrigger::ToastNotificationHistoryChangedTrigger(param::hstring const& applicationId) :
        ToastNotificationHistoryChangedTrigger(impl::call_factory<ToastNotificationHistoryChangedTrigger, IToastNotificationHistoryChangedTriggerFactory>([&](IToastNotificationHistoryChangedTriggerFactory const& f) { return f.Create(applicationId); }))
    {
    }
    inline UserNotificationChangedTrigger::UserNotificationChangedTrigger(llm::OS::UI::Notifications::NotificationKinds const& notificationKinds) :
        UserNotificationChangedTrigger(impl::call_factory<UserNotificationChangedTrigger, IUserNotificationChangedTriggerFactory>([&](IUserNotificationChangedTriggerFactory const& f) { return f.Create(notificationKinds); }))
    {
    }
    inline WiFiOnDemandHotspotConnectTrigger::WiFiOnDemandHotspotConnectTrigger() :
        WiFiOnDemandHotspotConnectTrigger(impl::call_factory_cast<WiFiOnDemandHotspotConnectTrigger(*)(llm::OS::Foundation::IActivationFactory const&), WiFiOnDemandHotspotConnectTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiOnDemandHotspotConnectTrigger>(); }))
    {
    }
    inline WiFiOnDemandHotspotUpdateMetadataTrigger::WiFiOnDemandHotspotUpdateMetadataTrigger() :
        WiFiOnDemandHotspotUpdateMetadataTrigger(impl::call_factory_cast<WiFiOnDemandHotspotUpdateMetadataTrigger(*)(llm::OS::Foundation::IActivationFactory const&), WiFiOnDemandHotspotUpdateMetadataTrigger>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiOnDemandHotspotUpdateMetadataTrigger>(); }))
    {
    }
    template <typename L> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(L handler) :
        BackgroundTaskCanceledEventHandler(impl::make_delegate<BackgroundTaskCanceledEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(F* handler) :
        BackgroundTaskCanceledEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(O* object, M method) :
        BackgroundTaskCanceledEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(com_ptr<O>&& object, M method) :
        BackgroundTaskCanceledEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCanceledEventHandler::BackgroundTaskCanceledEventHandler(weak_ref<O>&& object, M method) :
        BackgroundTaskCanceledEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto BackgroundTaskCanceledEventHandler::operator()(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskCancellationReason const& reason) const
    {
        check_hresult((*(impl::abi_t<BackgroundTaskCanceledEventHandler>**)this)->Invoke(*(void**)(&sender), static_cast<int32_t>(reason)));
    }
    template <typename L> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(L handler) :
        BackgroundTaskCompletedEventHandler(impl::make_delegate<BackgroundTaskCompletedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(F* handler) :
        BackgroundTaskCompletedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(O* object, M method) :
        BackgroundTaskCompletedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(com_ptr<O>&& object, M method) :
        BackgroundTaskCompletedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskCompletedEventHandler::BackgroundTaskCompletedEventHandler(weak_ref<O>&& object, M method) :
        BackgroundTaskCompletedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto BackgroundTaskCompletedEventHandler::operator()(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventArgs const& args) const
    {
        check_hresult((*(impl::abi_t<BackgroundTaskCompletedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&args)));
    }
    template <typename L> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(L handler) :
        BackgroundTaskProgressEventHandler(impl::make_delegate<BackgroundTaskProgressEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(F* handler) :
        BackgroundTaskProgressEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(O* object, M method) :
        BackgroundTaskProgressEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(com_ptr<O>&& object, M method) :
        BackgroundTaskProgressEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundTaskProgressEventHandler::BackgroundTaskProgressEventHandler(weak_ref<O>&& object, M method) :
        BackgroundTaskProgressEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto BackgroundTaskProgressEventHandler::operator()(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventArgs const& args) const
    {
        check_hresult((*(impl::abi_t<BackgroundTaskProgressEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&args)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Background::IActivitySensorTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IActivitySensorTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IAlarmApplicationManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IAppBroadcastTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IAppBroadcastTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IApplicationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IApplicationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundCondition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundExecutionManagerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroupFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBackgroundWorkCostStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IContentPrefetchTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IContentPrefetchTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ICustomSystemEventTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceServicingTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceUseTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IGeovisitTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ILocationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ILocationTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IMaintenanceTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IMaintenanceTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IMediaProcessingTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IPhoneTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IPhoneTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IPushNotificationTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISmartCardTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISmartCardTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISocketActivityTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IStorageLibraryChangeTrackerTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISystemCondition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISystemConditionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISystemTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ISystemTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ITimeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ITimeTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IToastNotificationActionTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::IUserNotificationChangedTriggerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ActivitySensorTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::AlarmApplicationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::AppBroadcastTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::AppBroadcastTriggerProviderInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ApplicationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ApplicationTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::AppointmentStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundExecutionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskBuilder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundTaskRegistrationGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BackgroundWorkCost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BluetoothLEAdvertisementPublisherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::BluetoothLEAdvertisementWatcherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::CachedFileUpdaterTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::CachedFileUpdaterTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ChatMessageNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ChatMessageReceivedNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::CommunicationBlockingAppSetAsActiveTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ContactStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ContentPrefetchTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ConversationalAgentTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::CustomSystemEventTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::DeviceConnectionChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::DeviceManufacturerNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::DeviceServicingTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::DeviceUseTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::DeviceWatcherTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::EmailStoreNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::GattCharacteristicNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::GattServiceProviderTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::GattServiceProviderTriggerResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::GeovisitTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::LocationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MaintenanceTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MediaProcessingTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MobileBroadbandDeviceServiceNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MobileBroadbandPcoDataChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MobileBroadbandPinLockStateChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MobileBroadbandRadioStateChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::MobileBroadbandRegistrationStateChangeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::NetworkOperatorDataUsageTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::NetworkOperatorHotspotAuthenticationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::NetworkOperatorNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::PaymentAppCanMakePaymentTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::PhoneTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::PushNotificationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::RcsEndUserMessageAvailableTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::RfcommConnectionTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SecondaryAuthenticationFactorAuthenticationTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SensorDataThresholdTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SmartCardTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SmsMessageReceivedTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SocketActivityTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::StorageLibraryChangeTrackerTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::StorageLibraryContentChangedTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SystemCondition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::SystemTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::TetheringEntitlementCheckTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::TimeTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ToastNotificationActionTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::UserNotificationChangedTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::WiFiOnDemandHotspotConnectTrigger> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Background::WiFiOnDemandHotspotUpdateMetadataTrigger> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
