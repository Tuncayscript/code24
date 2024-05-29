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
#ifndef LLM_OS_ApplicationModel_Background_1_H
#define LLM_OS_ApplicationModel_Background_1_H
#include "llm/impl/Windows.ApplicationModel.Background.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Background
{
    struct __declspec(empty_bases) IActivitySensorTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IActivitySensorTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IActivitySensorTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IActivitySensorTrigger(std::nullptr_t = nullptr) noexcept {}
        IActivitySensorTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActivitySensorTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IActivitySensorTriggerFactory>
    {
        IActivitySensorTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IActivitySensorTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAlarmApplicationManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAlarmApplicationManagerStatics>
    {
        IAlarmApplicationManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAlarmApplicationManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IAppBroadcastTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IAppBroadcastTrigger(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastTriggerFactory>
    {
        IAppBroadcastTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastTriggerProviderInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastTriggerProviderInfo>
    {
        IAppBroadcastTriggerProviderInfo(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastTriggerProviderInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IApplicationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IApplicationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IApplicationTrigger(std::nullptr_t = nullptr) noexcept {}
        IApplicationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IApplicationTriggerDetails>
    {
        IApplicationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IApplicationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IAppointmentStoreNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundCondition :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundCondition>
    {
        IBackgroundCondition(std::nullptr_t = nullptr) noexcept {}
        IBackgroundCondition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundExecutionManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundExecutionManagerStatics>
    {
        IBackgroundExecutionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundExecutionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundExecutionManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundExecutionManagerStatics2>
    {
        IBackgroundExecutionManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundExecutionManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundExecutionManagerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundExecutionManagerStatics3>
    {
        IBackgroundExecutionManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IBackgroundExecutionManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTask :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTask>
    {
        IBackgroundTask(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskBuilder :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskBuilder>
    {
        IBackgroundTaskBuilder(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskBuilder2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskBuilder2>
    {
        IBackgroundTaskBuilder2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskBuilder2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskBuilder3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskBuilder3>
    {
        IBackgroundTaskBuilder3(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskBuilder3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskBuilder4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskBuilder4>
    {
        IBackgroundTaskBuilder4(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskBuilder4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskBuilder5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskBuilder5>
    {
        IBackgroundTaskBuilder5(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskBuilder5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskCompletedEventArgs>
    {
        IBackgroundTaskCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskDeferral>
    {
        IBackgroundTaskDeferral(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskInstance :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskInstance>
    {
        IBackgroundTaskInstance(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskInstance(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskInstance2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskInstance2>,
        impl::require<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance2, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance>
    {
        IBackgroundTaskInstance2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskInstance2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskInstance4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskInstance4>,
        impl::require<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance4, llm::OS::ApplicationModel::Background::IBackgroundTaskInstance>
    {
        IBackgroundTaskInstance4(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskInstance4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskProgressEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskProgressEventArgs>
    {
        IBackgroundTaskProgressEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskProgressEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistration>
    {
        IBackgroundTaskRegistration(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistration2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistration2>,
        impl::require<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>
    {
        IBackgroundTaskRegistration2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistration2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistration3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistration3>,
        impl::require<llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration>
    {
        IBackgroundTaskRegistration3(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistration3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistrationGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistrationGroup>
    {
        IBackgroundTaskRegistrationGroup(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistrationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistrationGroupFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistrationGroupFactory>
    {
        IBackgroundTaskRegistrationGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistrationGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistrationStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistrationStatics>
    {
        IBackgroundTaskRegistrationStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistrationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTaskRegistrationStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTaskRegistrationStatics2>
    {
        IBackgroundTaskRegistrationStatics2(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTaskRegistrationStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundTrigger>
    {
        IBackgroundTrigger(std::nullptr_t = nullptr) noexcept {}
        IBackgroundTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundWorkCostStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundWorkCostStatics>
    {
        IBackgroundWorkCostStatics(std::nullptr_t = nullptr) noexcept {}
        IBackgroundWorkCostStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IBluetoothLEAdvertisementPublisherTrigger(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementPublisherTrigger2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementPublisherTrigger2>
    {
        IBluetoothLEAdvertisementPublisherTrigger2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementPublisherTrigger2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcherTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcherTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IBluetoothLEAdvertisementWatcherTrigger(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBluetoothLEAdvertisementWatcherTrigger2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBluetoothLEAdvertisementWatcherTrigger2>
    {
        IBluetoothLEAdvertisementWatcherTrigger2(std::nullptr_t = nullptr) noexcept {}
        IBluetoothLEAdvertisementWatcherTrigger2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileUpdaterTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ICachedFileUpdaterTrigger(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileUpdaterTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterTriggerDetails>
    {
        ICachedFileUpdaterTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IChatMessageNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IChatMessageNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IChatMessageNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IChatMessageNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IChatMessageReceivedNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IChatMessageReceivedNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IChatMessageReceivedNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IChatMessageReceivedNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommunicationBlockingAppSetAsActiveTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommunicationBlockingAppSetAsActiveTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ICommunicationBlockingAppSetAsActiveTrigger(std::nullptr_t = nullptr) noexcept {}
        ICommunicationBlockingAppSetAsActiveTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactStoreNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactStoreNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IContactStoreNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IContactStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentPrefetchTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContentPrefetchTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IContentPrefetchTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IContentPrefetchTrigger(std::nullptr_t = nullptr) noexcept {}
        IContentPrefetchTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentPrefetchTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContentPrefetchTriggerFactory>
    {
        IContentPrefetchTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IContentPrefetchTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSystemEventTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSystemEventTrigger>
    {
        ICustomSystemEventTrigger(std::nullptr_t = nullptr) noexcept {}
        ICustomSystemEventTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSystemEventTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSystemEventTriggerFactory>
    {
        ICustomSystemEventTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ICustomSystemEventTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceConnectionChangeTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceConnectionChangeTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IDeviceConnectionChangeTrigger(std::nullptr_t = nullptr) noexcept {}
        IDeviceConnectionChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceConnectionChangeTriggerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceConnectionChangeTriggerStatics>
    {
        IDeviceConnectionChangeTriggerStatics(std::nullptr_t = nullptr) noexcept {}
        IDeviceConnectionChangeTriggerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceManufacturerNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceManufacturerNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IDeviceManufacturerNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IDeviceManufacturerNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceManufacturerNotificationTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceManufacturerNotificationTriggerFactory>
    {
        IDeviceManufacturerNotificationTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IDeviceManufacturerNotificationTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceServicingTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceServicingTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IDeviceServicingTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IDeviceServicingTrigger(std::nullptr_t = nullptr) noexcept {}
        IDeviceServicingTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceUseTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceUseTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IDeviceUseTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IDeviceUseTrigger(std::nullptr_t = nullptr) noexcept {}
        IDeviceUseTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceWatcherTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceWatcherTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IDeviceWatcherTrigger(std::nullptr_t = nullptr) noexcept {}
        IDeviceWatcherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailStoreNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailStoreNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IEmailStoreNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IEmailStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IGattCharacteristicNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTrigger2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTrigger2>
    {
        IGattCharacteristicNotificationTrigger2(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTrigger2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTriggerFactory>
    {
        IGattCharacteristicNotificationTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattCharacteristicNotificationTriggerFactory2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattCharacteristicNotificationTriggerFactory2>
    {
        IGattCharacteristicNotificationTriggerFactory2(std::nullptr_t = nullptr) noexcept {}
        IGattCharacteristicNotificationTriggerFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderTrigger>
    {
        IGattServiceProviderTrigger(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderTriggerResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderTriggerResult>
    {
        IGattServiceProviderTriggerResult(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderTriggerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGattServiceProviderTriggerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGattServiceProviderTriggerStatics>
    {
        IGattServiceProviderTriggerStatics(std::nullptr_t = nullptr) noexcept {}
        IGattServiceProviderTriggerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeovisitTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGeovisitTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IGeovisitTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IGeovisitTrigger(std::nullptr_t = nullptr) noexcept {}
        IGeovisitTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILocationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ILocationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ILocationTrigger(std::nullptr_t = nullptr) noexcept {}
        ILocationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILocationTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILocationTriggerFactory>
    {
        ILocationTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ILocationTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMaintenanceTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMaintenanceTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IMaintenanceTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IMaintenanceTrigger(std::nullptr_t = nullptr) noexcept {}
        IMaintenanceTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMaintenanceTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMaintenanceTriggerFactory>
    {
        IMaintenanceTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IMaintenanceTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProcessingTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMediaProcessingTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IMediaProcessingTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IMediaProcessingTrigger(std::nullptr_t = nullptr) noexcept {}
        IMediaProcessingTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorHotspotAuthenticationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorHotspotAuthenticationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        INetworkOperatorHotspotAuthenticationTrigger(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorHotspotAuthenticationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorNotificationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorNotificationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        INetworkOperatorNotificationTrigger(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INetworkOperatorNotificationTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INetworkOperatorNotificationTriggerFactory>
    {
        INetworkOperatorNotificationTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        INetworkOperatorNotificationTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IPhoneTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IPhoneTrigger(std::nullptr_t = nullptr) noexcept {}
        IPhoneTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneTriggerFactory>
    {
        IPhoneTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IPhoneTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationTriggerFactory>
    {
        IPushNotificationTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRcsEndUserMessageAvailableTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRcsEndUserMessageAvailableTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IRcsEndUserMessageAvailableTrigger(std::nullptr_t = nullptr) noexcept {}
        IRcsEndUserMessageAvailableTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRfcommConnectionTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRfcommConnectionTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IRfcommConnectionTrigger(std::nullptr_t = nullptr) noexcept {}
        IRfcommConnectionTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthenticationTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthenticationTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ISecondaryAuthenticationFactorAuthenticationTrigger(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthenticationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISensorDataThresholdTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISensorDataThresholdTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ISensorDataThresholdTrigger(std::nullptr_t = nullptr) noexcept {}
        ISensorDataThresholdTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISensorDataThresholdTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISensorDataThresholdTriggerFactory>
    {
        ISensorDataThresholdTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ISensorDataThresholdTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ISmartCardTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ISmartCardTrigger(std::nullptr_t = nullptr) noexcept {}
        ISmartCardTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardTriggerFactory>
    {
        ISmartCardTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ISmartCardTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageReceivedTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageReceivedTriggerFactory>
    {
        ISmsMessageReceivedTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageReceivedTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityTrigger>
    {
        ISocketActivityTrigger(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeTrackerTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeTrackerTriggerFactory>
    {
        IStorageLibraryChangeTrackerTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeTrackerTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryContentChangedTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryContentChangedTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        IStorageLibraryContentChangedTrigger(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryContentChangedTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryContentChangedTriggerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryContentChangedTriggerStatics>
    {
        IStorageLibraryContentChangedTriggerStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryContentChangedTriggerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemCondition :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISystemCondition>,
        impl::require<llm::OS::ApplicationModel::Background::ISystemCondition, llm::OS::ApplicationModel::Background::IBackgroundCondition>
    {
        ISystemCondition(std::nullptr_t = nullptr) noexcept {}
        ISystemCondition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemConditionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISystemConditionFactory>
    {
        ISystemConditionFactory(std::nullptr_t = nullptr) noexcept {}
        ISystemConditionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISystemTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ISystemTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ISystemTrigger(std::nullptr_t = nullptr) noexcept {}
        ISystemTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISystemTriggerFactory>
    {
        ISystemTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ISystemTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimeTrigger :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITimeTrigger>,
        impl::require<llm::OS::ApplicationModel::Background::ITimeTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        ITimeTrigger(std::nullptr_t = nullptr) noexcept {}
        ITimeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimeTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITimeTriggerFactory>
    {
        ITimeTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        ITimeTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationActionTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationActionTriggerFactory>
    {
        IToastNotificationActionTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationActionTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationHistoryChangedTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationHistoryChangedTriggerFactory>
    {
        IToastNotificationHistoryChangedTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationHistoryChangedTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserNotificationChangedTriggerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserNotificationChangedTriggerFactory>
    {
        IUserNotificationChangedTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IUserNotificationChangedTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
