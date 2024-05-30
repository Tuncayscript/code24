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
#ifndef LLM_OS_UI_Notifications_1_H
#define LLM_OS_UI_Notifications_1_H
#include "llm/impl/Windows.UI.Notifications.0.h"
LLM_EXPORT namespace llm:OS::UI::Notifications
{
    struct __declspec(empty_bases) IAdaptiveNotificationContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveNotificationContent>
    {
        IAdaptiveNotificationContent(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveNotificationContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveNotificationText :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveNotificationText>
    {
        IAdaptiveNotificationText(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveNotificationText(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeNotification>
    {
        IBadgeNotification(std::nullptr_t = nullptr) noexcept {}
        IBadgeNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeNotificationFactory>
    {
        IBadgeNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        IBadgeNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeUpdateManagerForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeUpdateManagerForUser>
    {
        IBadgeUpdateManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IBadgeUpdateManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeUpdateManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeUpdateManagerStatics>
    {
        IBadgeUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IBadgeUpdateManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeUpdateManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeUpdateManagerStatics2>
    {
        IBadgeUpdateManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IBadgeUpdateManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBadgeUpdater :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBadgeUpdater>
    {
        IBadgeUpdater(std::nullptr_t = nullptr) noexcept {}
        IBadgeUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownAdaptiveNotificationHintsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownAdaptiveNotificationHintsStatics>
    {
        IKnownAdaptiveNotificationHintsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownAdaptiveNotificationHintsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownAdaptiveNotificationTextStylesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownAdaptiveNotificationTextStylesStatics>
    {
        IKnownAdaptiveNotificationTextStylesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownAdaptiveNotificationTextStylesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownNotificationBindingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownNotificationBindingsStatics>
    {
        IKnownNotificationBindingsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownNotificationBindingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INotification>
    {
        INotification(std::nullptr_t = nullptr) noexcept {}
        INotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotificationBinding :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INotificationBinding>
    {
        INotificationBinding(std::nullptr_t = nullptr) noexcept {}
        INotificationBinding(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotificationData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INotificationData>
    {
        INotificationData(std::nullptr_t = nullptr) noexcept {}
        INotificationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotificationDataFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INotificationDataFactory>
    {
        INotificationDataFactory(std::nullptr_t = nullptr) noexcept {}
        INotificationDataFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INotificationVisual :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INotificationVisual>
    {
        INotificationVisual(std::nullptr_t = nullptr) noexcept {}
        INotificationVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledTileNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledTileNotification>
    {
        IScheduledTileNotification(std::nullptr_t = nullptr) noexcept {}
        IScheduledTileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledTileNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledTileNotificationFactory>
    {
        IScheduledTileNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        IScheduledTileNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotification>
    {
        IScheduledToastNotification(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotification2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotification2>
    {
        IScheduledToastNotification2(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotification2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotification3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotification3>
    {
        IScheduledToastNotification3(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotification3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotification4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotification4>
    {
        IScheduledToastNotification4(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotification4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotificationFactory>
    {
        IScheduledToastNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IScheduledToastNotificationShowingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IScheduledToastNotificationShowingEventArgs>
    {
        IScheduledToastNotificationShowingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IScheduledToastNotificationShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShownTileNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShownTileNotification>
    {
        IShownTileNotification(std::nullptr_t = nullptr) noexcept {}
        IShownTileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileFlyoutNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileFlyoutNotification>
    {
        ITileFlyoutNotification(std::nullptr_t = nullptr) noexcept {}
        ITileFlyoutNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileFlyoutNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileFlyoutNotificationFactory>
    {
        ITileFlyoutNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        ITileFlyoutNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileFlyoutUpdateManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileFlyoutUpdateManagerStatics>
    {
        ITileFlyoutUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ITileFlyoutUpdateManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileFlyoutUpdater :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileFlyoutUpdater>
    {
        ITileFlyoutUpdater(std::nullptr_t = nullptr) noexcept {}
        ITileFlyoutUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileNotification>
    {
        ITileNotification(std::nullptr_t = nullptr) noexcept {}
        ITileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileNotificationFactory>
    {
        ITileNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        ITileNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileUpdateManagerForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileUpdateManagerForUser>
    {
        ITileUpdateManagerForUser(std::nullptr_t = nullptr) noexcept {}
        ITileUpdateManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileUpdateManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileUpdateManagerStatics>
    {
        ITileUpdateManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ITileUpdateManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileUpdateManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileUpdateManagerStatics2>
    {
        ITileUpdateManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        ITileUpdateManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileUpdater :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileUpdater>
    {
        ITileUpdater(std::nullptr_t = nullptr) noexcept {}
        ITileUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileUpdater2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileUpdater2>
    {
        ITileUpdater2(std::nullptr_t = nullptr) noexcept {}
        ITileUpdater2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastActivatedEventArgs>
    {
        IToastActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IToastActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastActivatedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastActivatedEventArgs2>
    {
        IToastActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IToastActivatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastCollection>
    {
        IToastCollection(std::nullptr_t = nullptr) noexcept {}
        IToastCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastCollectionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastCollectionFactory>
    {
        IToastCollectionFactory(std::nullptr_t = nullptr) noexcept {}
        IToastCollectionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastCollectionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastCollectionManager>
    {
        IToastCollectionManager(std::nullptr_t = nullptr) noexcept {}
        IToastCollectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastDismissedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastDismissedEventArgs>
    {
        IToastDismissedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IToastDismissedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastFailedEventArgs>
    {
        IToastFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IToastFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotification>
    {
        IToastNotification(std::nullptr_t = nullptr) noexcept {}
        IToastNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotification2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotification2>
    {
        IToastNotification2(std::nullptr_t = nullptr) noexcept {}
        IToastNotification2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotification3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotification3>
    {
        IToastNotification3(std::nullptr_t = nullptr) noexcept {}
        IToastNotification3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotification4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotification4>
    {
        IToastNotification4(std::nullptr_t = nullptr) noexcept {}
        IToastNotification4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotification6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotification6>
    {
        IToastNotification6(std::nullptr_t = nullptr) noexcept {}
        IToastNotification6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationActionTriggerDetail :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationActionTriggerDetail>
    {
        IToastNotificationActionTriggerDetail(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationActionTriggerDetail(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationFactory>
    {
        IToastNotificationFactory(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationHistory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationHistory>
    {
        IToastNotificationHistory(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationHistory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationHistory2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationHistory2>
    {
        IToastNotificationHistory2(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationHistory2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationHistoryChangedTriggerDetail :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationHistoryChangedTriggerDetail>
    {
        IToastNotificationHistoryChangedTriggerDetail(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationHistoryChangedTriggerDetail(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationHistoryChangedTriggerDetail2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationHistoryChangedTriggerDetail2>
    {
        IToastNotificationHistoryChangedTriggerDetail2(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationHistoryChangedTriggerDetail2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerForUser>
    {
        IToastNotificationManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerForUser2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerForUser2>
    {
        IToastNotificationManagerForUser2(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerForUser2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerForUser3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerForUser3>
    {
        IToastNotificationManagerForUser3(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerForUser3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerStatics>
    {
        IToastNotificationManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerStatics2>
    {
        IToastNotificationManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerStatics4>
    {
        IToastNotificationManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationManagerStatics5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationManagerStatics5>
    {
        IToastNotificationManagerStatics5(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationManagerStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotifier :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotifier>
    {
        IToastNotifier(std::nullptr_t = nullptr) noexcept {}
        IToastNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotifier2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotifier2>
    {
        IToastNotifier2(std::nullptr_t = nullptr) noexcept {}
        IToastNotifier2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotifier3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IToastNotifier3>
    {
        IToastNotifier3(std::nullptr_t = nullptr) noexcept {}
        IToastNotifier3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserNotification>
    {
        IUserNotification(std::nullptr_t = nullptr) noexcept {}
        IUserNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserNotificationChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserNotificationChangedEventArgs>
    {
        IUserNotificationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserNotificationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
