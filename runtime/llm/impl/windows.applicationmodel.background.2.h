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
#ifndef LLM_OS_ApplicationModel_Background_2_H
#define LLM_OS_ApplicationModel_Background_2_H
#include "llm/impl/Windows.ApplicationModel.Calls.Background.1.h"
#include "llm/impl/Windows.Devices.Bluetooth.Background.1.h"
#include "llm/impl/Windows.Devices.Bluetooth.GenericAttributeProfile.1.h"
#include "llm/impl/Windows.Devices.Sensors.1.h"
#include "llm/impl/Windows.Devices.SmartCards.1.h"
#include "llm/impl/Windows.Devices.Sms.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.UI.Notifications.1.h"
#include "llm/impl/Windows.ApplicationModel.Background.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Background
{
    struct BackgroundTaskCanceledEventHandler : llm::OS::Foundation::IUnknown
    {
        BackgroundTaskCanceledEventHandler(std::nullptr_t = nullptr) noexcept {}
        BackgroundTaskCanceledEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BackgroundTaskCanceledEventHandler(L lambda);
        template <typename F> BackgroundTaskCanceledEventHandler(F* function);
        template <typename O, typename M> BackgroundTaskCanceledEventHandler(O* object, M method);
        template <typename O, typename M> BackgroundTaskCanceledEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BackgroundTaskCanceledEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskCancellationReason const& reason) const;
    };
    struct BackgroundTaskCompletedEventHandler : llm::OS::Foundation::IUnknown
    {
        BackgroundTaskCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BackgroundTaskCompletedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BackgroundTaskCompletedEventHandler(L lambda);
        template <typename F> BackgroundTaskCompletedEventHandler(F* function);
        template <typename O, typename M> BackgroundTaskCompletedEventHandler(O* object, M method);
        template <typename O, typename M> BackgroundTaskCompletedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BackgroundTaskCompletedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskCompletedEventArgs const& args) const;
    };
    struct BackgroundTaskProgressEventHandler : llm::OS::Foundation::IUnknown
    {
        BackgroundTaskProgressEventHandler(std::nullptr_t = nullptr) noexcept {}
        BackgroundTaskProgressEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BackgroundTaskProgressEventHandler(L lambda);
        template <typename F> BackgroundTaskProgressEventHandler(F* function);
        template <typename O, typename M> BackgroundTaskProgressEventHandler(O* object, M method);
        template <typename O, typename M> BackgroundTaskProgressEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BackgroundTaskProgressEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::ApplicationModel::Background::BackgroundTaskRegistration const& sender, llm::OS::ApplicationModel::Background::BackgroundTaskProgressEventArgs const& args) const;
    };
    struct __declspec(empty_bases) ActivitySensorTrigger : llm::OS::ApplicationModel::Background::IActivitySensorTrigger
    {
        ActivitySensorTrigger(std::nullptr_t) noexcept {}
        ActivitySensorTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IActivitySensorTrigger(ptr, take_ownership_from_abi) {}
        explicit ActivitySensorTrigger(uint32_t reportIntervalInMilliseconds);
    };
    struct AlarmApplicationManager
    {
        AlarmApplicationManager() = delete;
        static auto RequestAccessAsync();
        static auto GetAccessStatus();
    };
    struct __declspec(empty_bases) AppBroadcastTrigger : llm::OS::ApplicationModel::Background::IAppBroadcastTrigger
    {
        AppBroadcastTrigger(std::nullptr_t) noexcept {}
        AppBroadcastTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IAppBroadcastTrigger(ptr, take_ownership_from_abi) {}
        explicit AppBroadcastTrigger(param::hstring const& providerKey);
    };
    struct __declspec(empty_bases) AppBroadcastTriggerProviderInfo : llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo
    {
        AppBroadcastTriggerProviderInfo(std::nullptr_t) noexcept {}
        AppBroadcastTriggerProviderInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IAppBroadcastTriggerProviderInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ApplicationTrigger : llm::OS::ApplicationModel::Background::IApplicationTrigger
    {
        ApplicationTrigger(std::nullptr_t) noexcept {}
        ApplicationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IApplicationTrigger(ptr, take_ownership_from_abi) {}
        ApplicationTrigger();
    };
    struct __declspec(empty_bases) ApplicationTriggerDetails : llm::OS::ApplicationModel::Background::IApplicationTriggerDetails
    {
        ApplicationTriggerDetails(std::nullptr_t) noexcept {}
        ApplicationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IApplicationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreNotificationTrigger : llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger
    {
        AppointmentStoreNotificationTrigger(std::nullptr_t) noexcept {}
        AppointmentStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IAppointmentStoreNotificationTrigger(ptr, take_ownership_from_abi) {}
        AppointmentStoreNotificationTrigger();
    };
    struct BackgroundExecutionManager
    {
        BackgroundExecutionManager() = delete;
        static auto RequestAccessAsync();
        static auto RequestAccessAsync(param::hstring const& applicationId);
        static auto RemoveAccess();
        static auto RemoveAccess(param::hstring const& applicationId);
        static auto GetAccessStatus();
        static auto GetAccessStatus(param::hstring const& applicationId);
        static auto RequestAccessKindAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason);
        static auto RequestAccessKindForModernStandbyAsync(llm::OS::ApplicationModel::Background::BackgroundAccessRequestKind const& requestedAccess, param::hstring const& reason);
        static auto GetAccessStatusForModernStandby();
        static auto GetAccessStatusForModernStandby(param::hstring const& applicationId);
    };
    struct __declspec(empty_bases) BackgroundTaskBuilder : llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder,
        impl::require<BackgroundTaskBuilder, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder2, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder3, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder4, llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder5>
    {
        BackgroundTaskBuilder(std::nullptr_t) noexcept {}
        BackgroundTaskBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskBuilder(ptr, take_ownership_from_abi) {}
        BackgroundTaskBuilder();
    };
    struct __declspec(empty_bases) BackgroundTaskCompletedEventArgs : llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs
    {
        BackgroundTaskCompletedEventArgs(std::nullptr_t) noexcept {}
        BackgroundTaskCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundTaskDeferral : llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral
    {
        BackgroundTaskDeferral(std::nullptr_t) noexcept {}
        BackgroundTaskDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundTaskProgressEventArgs : llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs
    {
        BackgroundTaskProgressEventArgs(std::nullptr_t) noexcept {}
        BackgroundTaskProgressEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskProgressEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundTaskRegistration : llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration,
        impl::require<BackgroundTaskRegistration, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration2, llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration3>
    {
        BackgroundTaskRegistration(std::nullptr_t) noexcept {}
        BackgroundTaskRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskRegistration(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AllTasks();
        [[nodiscard]] static auto AllTaskGroups();
        static auto GetTaskGroup(param::hstring const& groupId);
    };
    struct __declspec(empty_bases) BackgroundTaskRegistrationGroup : llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup
    {
        BackgroundTaskRegistrationGroup(std::nullptr_t) noexcept {}
        BackgroundTaskRegistrationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTaskRegistrationGroup(ptr, take_ownership_from_abi) {}
        explicit BackgroundTaskRegistrationGroup(param::hstring const& id);
        BackgroundTaskRegistrationGroup(param::hstring const& id, param::hstring const& name);
    };
    struct BackgroundWorkCost
    {
        BackgroundWorkCost() = delete;
        [[nodiscard]] static auto CurrentBackgroundWorkCost();
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementPublisherTrigger : llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger,
        impl::require<BluetoothLEAdvertisementPublisherTrigger, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger2>
    {
        BluetoothLEAdvertisementPublisherTrigger(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementPublisherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementPublisherTrigger();
    };
    struct __declspec(empty_bases) BluetoothLEAdvertisementWatcherTrigger : llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger,
        impl::require<BluetoothLEAdvertisementWatcherTrigger, llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger2>
    {
        BluetoothLEAdvertisementWatcherTrigger(std::nullptr_t) noexcept {}
        BluetoothLEAdvertisementWatcherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger(ptr, take_ownership_from_abi) {}
        BluetoothLEAdvertisementWatcherTrigger();
    };
    struct __declspec(empty_bases) CachedFileUpdaterTrigger : llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger
    {
        CachedFileUpdaterTrigger(std::nullptr_t) noexcept {}
        CachedFileUpdaterTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ICachedFileUpdaterTrigger(ptr, take_ownership_from_abi) {}
        CachedFileUpdaterTrigger();
    };
    struct __declspec(empty_bases) CachedFileUpdaterTriggerDetails : llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails
    {
        CachedFileUpdaterTriggerDetails(std::nullptr_t) noexcept {}
        CachedFileUpdaterTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageNotificationTrigger : llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger
    {
        ChatMessageNotificationTrigger(std::nullptr_t) noexcept {}
        ChatMessageNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IChatMessageNotificationTrigger(ptr, take_ownership_from_abi) {}
        ChatMessageNotificationTrigger();
    };
    struct __declspec(empty_bases) ChatMessageReceivedNotificationTrigger : llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger
    {
        ChatMessageReceivedNotificationTrigger(std::nullptr_t) noexcept {}
        ChatMessageReceivedNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger(ptr, take_ownership_from_abi) {}
        ChatMessageReceivedNotificationTrigger();
    };
    struct __declspec(empty_bases) CommunicationBlockingAppSetAsActiveTrigger : llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger
    {
        CommunicationBlockingAppSetAsActiveTrigger(std::nullptr_t) noexcept {}
        CommunicationBlockingAppSetAsActiveTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger(ptr, take_ownership_from_abi) {}
        CommunicationBlockingAppSetAsActiveTrigger();
    };
    struct __declspec(empty_bases) ContactStoreNotificationTrigger : llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger
    {
        ContactStoreNotificationTrigger(std::nullptr_t) noexcept {}
        ContactStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IContactStoreNotificationTrigger(ptr, take_ownership_from_abi) {}
        ContactStoreNotificationTrigger();
    };
    struct __declspec(empty_bases) ContentPrefetchTrigger : llm::OS::ApplicationModel::Background::IContentPrefetchTrigger
    {
        ContentPrefetchTrigger(std::nullptr_t) noexcept {}
        ContentPrefetchTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IContentPrefetchTrigger(ptr, take_ownership_from_abi) {}
        ContentPrefetchTrigger();
        explicit ContentPrefetchTrigger(llm::OS::Foundation::TimeSpan const& waitInterval);
    };
    struct __declspec(empty_bases) ConversationalAgentTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        ConversationalAgentTrigger(std::nullptr_t) noexcept {}
        ConversationalAgentTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        ConversationalAgentTrigger();
    };
    struct __declspec(empty_bases) CustomSystemEventTrigger : llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger,
        impl::require<CustomSystemEventTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        CustomSystemEventTrigger(std::nullptr_t) noexcept {}
        CustomSystemEventTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ICustomSystemEventTrigger(ptr, take_ownership_from_abi) {}
        CustomSystemEventTrigger(param::hstring const& triggerId, llm::OS::ApplicationModel::Background::CustomSystemEventTriggerRecurrence const& recurrence);
    };
    struct __declspec(empty_bases) DeviceConnectionChangeTrigger : llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger
    {
        DeviceConnectionChangeTrigger(std::nullptr_t) noexcept {}
        DeviceConnectionChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IDeviceConnectionChangeTrigger(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) DeviceManufacturerNotificationTrigger : llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger
    {
        DeviceManufacturerNotificationTrigger(std::nullptr_t) noexcept {}
        DeviceManufacturerNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger(ptr, take_ownership_from_abi) {}
        DeviceManufacturerNotificationTrigger(param::hstring const& triggerQualifier, bool oneShot);
    };
    struct __declspec(empty_bases) DeviceServicingTrigger : llm::OS::ApplicationModel::Background::IDeviceServicingTrigger
    {
        DeviceServicingTrigger(std::nullptr_t) noexcept {}
        DeviceServicingTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IDeviceServicingTrigger(ptr, take_ownership_from_abi) {}
        DeviceServicingTrigger();
    };
    struct __declspec(empty_bases) DeviceUseTrigger : llm::OS::ApplicationModel::Background::IDeviceUseTrigger
    {
        DeviceUseTrigger(std::nullptr_t) noexcept {}
        DeviceUseTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IDeviceUseTrigger(ptr, take_ownership_from_abi) {}
        DeviceUseTrigger();
    };
    struct __declspec(empty_bases) DeviceWatcherTrigger : llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger
    {
        DeviceWatcherTrigger(std::nullptr_t) noexcept {}
        DeviceWatcherTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IDeviceWatcherTrigger(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailStoreNotificationTrigger : llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger
    {
        EmailStoreNotificationTrigger(std::nullptr_t) noexcept {}
        EmailStoreNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IEmailStoreNotificationTrigger(ptr, take_ownership_from_abi) {}
        EmailStoreNotificationTrigger();
    };
    struct __declspec(empty_bases) GattCharacteristicNotificationTrigger : llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger,
        impl::require<GattCharacteristicNotificationTrigger, llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger2>
    {
        GattCharacteristicNotificationTrigger(std::nullptr_t) noexcept {}
        GattCharacteristicNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IGattCharacteristicNotificationTrigger(ptr, take_ownership_from_abi) {}
        explicit GattCharacteristicNotificationTrigger(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic);
        GattCharacteristicNotificationTrigger(llm::OS::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic const& characteristic, llm::OS::Devices::Bluetooth::Background::BluetoothEventTriggeringMode const& eventTriggeringMode);
    };
    struct __declspec(empty_bases) GattServiceProviderTrigger : llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger,
        impl::require<GattServiceProviderTrigger, llm::OS::ApplicationModel::Background::IBackgroundTrigger>
    {
        GattServiceProviderTrigger(std::nullptr_t) noexcept {}
        GattServiceProviderTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IGattServiceProviderTrigger(ptr, take_ownership_from_abi) {}
        static auto CreateAsync(param::hstring const& triggerId, llm::guid const& serviceUuid);
    };
    struct __declspec(empty_bases) GattServiceProviderTriggerResult : llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult
    {
        GattServiceProviderTriggerResult(std::nullptr_t) noexcept {}
        GattServiceProviderTriggerResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IGattServiceProviderTriggerResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GeovisitTrigger : llm::OS::ApplicationModel::Background::IGeovisitTrigger
    {
        GeovisitTrigger(std::nullptr_t) noexcept {}
        GeovisitTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IGeovisitTrigger(ptr, take_ownership_from_abi) {}
        GeovisitTrigger();
    };
    struct __declspec(empty_bases) LocationTrigger : llm::OS::ApplicationModel::Background::ILocationTrigger
    {
        LocationTrigger(std::nullptr_t) noexcept {}
        LocationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ILocationTrigger(ptr, take_ownership_from_abi) {}
        explicit LocationTrigger(llm::OS::ApplicationModel::Background::LocationTriggerType const& triggerType);
    };
    struct __declspec(empty_bases) MaintenanceTrigger : llm::OS::ApplicationModel::Background::IMaintenanceTrigger
    {
        MaintenanceTrigger(std::nullptr_t) noexcept {}
        MaintenanceTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IMaintenanceTrigger(ptr, take_ownership_from_abi) {}
        MaintenanceTrigger(uint32_t freshnessTime, bool oneShot);
    };
    struct __declspec(empty_bases) MediaProcessingTrigger : llm::OS::ApplicationModel::Background::IMediaProcessingTrigger
    {
        MediaProcessingTrigger(std::nullptr_t) noexcept {}
        MediaProcessingTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IMediaProcessingTrigger(ptr, take_ownership_from_abi) {}
        MediaProcessingTrigger();
    };
    struct __declspec(empty_bases) MobileBroadbandDeviceServiceNotificationTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        MobileBroadbandDeviceServiceNotificationTrigger(std::nullptr_t) noexcept {}
        MobileBroadbandDeviceServiceNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        MobileBroadbandDeviceServiceNotificationTrigger();
    };
    struct __declspec(empty_bases) MobileBroadbandPcoDataChangeTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        MobileBroadbandPcoDataChangeTrigger(std::nullptr_t) noexcept {}
        MobileBroadbandPcoDataChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        MobileBroadbandPcoDataChangeTrigger();
    };
    struct __declspec(empty_bases) MobileBroadbandPinLockStateChangeTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        MobileBroadbandPinLockStateChangeTrigger(std::nullptr_t) noexcept {}
        MobileBroadbandPinLockStateChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        MobileBroadbandPinLockStateChangeTrigger();
    };
    struct __declspec(empty_bases) MobileBroadbandRadioStateChangeTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        MobileBroadbandRadioStateChangeTrigger(std::nullptr_t) noexcept {}
        MobileBroadbandRadioStateChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        MobileBroadbandRadioStateChangeTrigger();
    };
    struct __declspec(empty_bases) MobileBroadbandRegistrationStateChangeTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        MobileBroadbandRegistrationStateChangeTrigger(std::nullptr_t) noexcept {}
        MobileBroadbandRegistrationStateChangeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        MobileBroadbandRegistrationStateChangeTrigger();
    };
    struct __declspec(empty_bases) NetworkOperatorDataUsageTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        NetworkOperatorDataUsageTrigger(std::nullptr_t) noexcept {}
        NetworkOperatorDataUsageTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        NetworkOperatorDataUsageTrigger();
    };
    struct __declspec(empty_bases) NetworkOperatorHotspotAuthenticationTrigger : llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger
    {
        NetworkOperatorHotspotAuthenticationTrigger(std::nullptr_t) noexcept {}
        NetworkOperatorHotspotAuthenticationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger(ptr, take_ownership_from_abi) {}
        NetworkOperatorHotspotAuthenticationTrigger();
    };
    struct __declspec(empty_bases) NetworkOperatorNotificationTrigger : llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger
    {
        NetworkOperatorNotificationTrigger(std::nullptr_t) noexcept {}
        NetworkOperatorNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::INetworkOperatorNotificationTrigger(ptr, take_ownership_from_abi) {}
        explicit NetworkOperatorNotificationTrigger(param::hstring const& networkAccountId);
    };
    struct __declspec(empty_bases) PaymentAppCanMakePaymentTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        PaymentAppCanMakePaymentTrigger(std::nullptr_t) noexcept {}
        PaymentAppCanMakePaymentTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        PaymentAppCanMakePaymentTrigger();
    };
    struct __declspec(empty_bases) PhoneTrigger : llm::OS::ApplicationModel::Background::IPhoneTrigger
    {
        PhoneTrigger(std::nullptr_t) noexcept {}
        PhoneTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IPhoneTrigger(ptr, take_ownership_from_abi) {}
        PhoneTrigger(llm::OS::ApplicationModel::Calls::Background::PhoneTriggerType const& type, bool oneShot);
    };
    struct __declspec(empty_bases) PushNotificationTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        PushNotificationTrigger(std::nullptr_t) noexcept {}
        PushNotificationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        PushNotificationTrigger();
        explicit PushNotificationTrigger(param::hstring const& applicationId);
    };
    struct __declspec(empty_bases) RcsEndUserMessageAvailableTrigger : llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger
    {
        RcsEndUserMessageAvailableTrigger(std::nullptr_t) noexcept {}
        RcsEndUserMessageAvailableTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger(ptr, take_ownership_from_abi) {}
        RcsEndUserMessageAvailableTrigger();
    };
    struct __declspec(empty_bases) RfcommConnectionTrigger : llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger
    {
        RfcommConnectionTrigger(std::nullptr_t) noexcept {}
        RfcommConnectionTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IRfcommConnectionTrigger(ptr, take_ownership_from_abi) {}
        RfcommConnectionTrigger();
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorAuthenticationTrigger : llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger
    {
        SecondaryAuthenticationFactorAuthenticationTrigger(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorAuthenticationTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger(ptr, take_ownership_from_abi) {}
        SecondaryAuthenticationFactorAuthenticationTrigger();
    };
    struct __declspec(empty_bases) SensorDataThresholdTrigger : llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger
    {
        SensorDataThresholdTrigger(std::nullptr_t) noexcept {}
        SensorDataThresholdTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ISensorDataThresholdTrigger(ptr, take_ownership_from_abi) {}
        explicit SensorDataThresholdTrigger(llm::OS::Devices::Sensors::ISensorDataThreshold const& threshold);
    };
    struct __declspec(empty_bases) SmartCardTrigger : llm::OS::ApplicationModel::Background::ISmartCardTrigger
    {
        SmartCardTrigger(std::nullptr_t) noexcept {}
        SmartCardTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ISmartCardTrigger(ptr, take_ownership_from_abi) {}
        explicit SmartCardTrigger(llm::OS::Devices::SmartCards::SmartCardTriggerType const& triggerType);
    };
    struct __declspec(empty_bases) SmsMessageReceivedTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        SmsMessageReceivedTrigger(std::nullptr_t) noexcept {}
        SmsMessageReceivedTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        explicit SmsMessageReceivedTrigger(llm::OS::Devices::Sms::SmsFilterRules const& filterRules);
    };
    struct __declspec(empty_bases) SocketActivityTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger,
        impl::require<SocketActivityTrigger, llm::OS::ApplicationModel::Background::ISocketActivityTrigger>
    {
        SocketActivityTrigger(std::nullptr_t) noexcept {}
        SocketActivityTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        SocketActivityTrigger();
    };
    struct __declspec(empty_bases) StorageLibraryChangeTrackerTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        StorageLibraryChangeTrackerTrigger(std::nullptr_t) noexcept {}
        StorageLibraryChangeTrackerTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        explicit StorageLibraryChangeTrackerTrigger(llm::OS::Storage::StorageLibraryChangeTracker const& tracker);
    };
    struct __declspec(empty_bases) StorageLibraryContentChangedTrigger : llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger
    {
        StorageLibraryContentChangedTrigger(std::nullptr_t) noexcept {}
        StorageLibraryContentChangedTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IStorageLibraryContentChangedTrigger(ptr, take_ownership_from_abi) {}
        static auto Create(llm::OS::Storage::StorageLibrary const& storageLibrary);
        static auto CreateFromLibraries(param::iterable<llm::OS::Storage::StorageLibrary> const& storageLibraries);
    };
    struct __declspec(empty_bases) SystemCondition : llm::OS::ApplicationModel::Background::ISystemCondition
    {
        SystemCondition(std::nullptr_t) noexcept {}
        SystemCondition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ISystemCondition(ptr, take_ownership_from_abi) {}
        explicit SystemCondition(llm::OS::ApplicationModel::Background::SystemConditionType const& conditionType);
    };
    struct __declspec(empty_bases) SystemTrigger : llm::OS::ApplicationModel::Background::ISystemTrigger
    {
        SystemTrigger(std::nullptr_t) noexcept {}
        SystemTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ISystemTrigger(ptr, take_ownership_from_abi) {}
        SystemTrigger(llm::OS::ApplicationModel::Background::SystemTriggerType const& triggerType, bool oneShot);
    };
    struct __declspec(empty_bases) TetheringEntitlementCheckTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        TetheringEntitlementCheckTrigger(std::nullptr_t) noexcept {}
        TetheringEntitlementCheckTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        TetheringEntitlementCheckTrigger();
    };
    struct __declspec(empty_bases) TimeTrigger : llm::OS::ApplicationModel::Background::ITimeTrigger
    {
        TimeTrigger(std::nullptr_t) noexcept {}
        TimeTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::ITimeTrigger(ptr, take_ownership_from_abi) {}
        TimeTrigger(uint32_t freshnessTime, bool oneShot);
    };
    struct __declspec(empty_bases) ToastNotificationActionTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        ToastNotificationActionTrigger(std::nullptr_t) noexcept {}
        ToastNotificationActionTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        ToastNotificationActionTrigger();
        explicit ToastNotificationActionTrigger(param::hstring const& applicationId);
    };
    struct __declspec(empty_bases) ToastNotificationHistoryChangedTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        ToastNotificationHistoryChangedTrigger(std::nullptr_t) noexcept {}
        ToastNotificationHistoryChangedTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        ToastNotificationHistoryChangedTrigger();
        explicit ToastNotificationHistoryChangedTrigger(param::hstring const& applicationId);
    };
    struct __declspec(empty_bases) UserNotificationChangedTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        UserNotificationChangedTrigger(std::nullptr_t) noexcept {}
        UserNotificationChangedTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        explicit UserNotificationChangedTrigger(llm::OS::UI::Notifications::NotificationKinds const& notificationKinds);
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotConnectTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        WiFiOnDemandHotspotConnectTrigger(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotConnectTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        WiFiOnDemandHotspotConnectTrigger();
    };
    struct __declspec(empty_bases) WiFiOnDemandHotspotUpdateMetadataTrigger : llm::OS::ApplicationModel::Background::IBackgroundTrigger
    {
        WiFiOnDemandHotspotUpdateMetadataTrigger(std::nullptr_t) noexcept {}
        WiFiOnDemandHotspotUpdateMetadataTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Background::IBackgroundTrigger(ptr, take_ownership_from_abi) {}
        WiFiOnDemandHotspotUpdateMetadataTrigger();
    };
}
#endif
