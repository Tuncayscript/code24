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
#ifndef LLM_OS_UI_Notifications_2_H
#define LLM_OS_UI_Notifications_2_H
#include "llm/impl/Windows.Data.Xml.Dom.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.Notifications.1.h"
LLM_EXPORT namespace llm:OS::UI::Notifications
{
    struct __declspec(empty_bases) AdaptiveNotificationText : llm:OS::UI::Notifications::IAdaptiveNotificationText,
        impl::require<AdaptiveNotificationText, llm:OS::UI::Notifications::IAdaptiveNotificationContent>
    {
        AdaptiveNotificationText(std::nullptr_t) noexcept {}
        AdaptiveNotificationText(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IAdaptiveNotificationText(ptr, take_ownership_from_abi) {}
        AdaptiveNotificationText();
    };
    struct __declspec(empty_bases) BadgeNotification : llm:OS::UI::Notifications::IBadgeNotification
    {
        BadgeNotification(std::nullptr_t) noexcept {}
        BadgeNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IBadgeNotification(ptr, take_ownership_from_abi) {}
        explicit BadgeNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content);
    };
    struct BadgeUpdateManager
    {
        BadgeUpdateManager() = delete;
        static auto CreateBadgeUpdaterForApplication();
        static auto CreateBadgeUpdaterForApplication(param::hstring const& applicationId);
        static auto CreateBadgeUpdaterForSecondaryTile(param::hstring const& tileId);
        static auto GetTemplateContent(llm:OS::UI::Notifications::BadgeTemplateType const& type);
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) BadgeUpdateManagerForUser : llm:OS::UI::Notifications::IBadgeUpdateManagerForUser
    {
        BadgeUpdateManagerForUser(std::nullptr_t) noexcept {}
        BadgeUpdateManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IBadgeUpdateManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BadgeUpdater : llm:OS::UI::Notifications::IBadgeUpdater
    {
        BadgeUpdater(std::nullptr_t) noexcept {}
        BadgeUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IBadgeUpdater(ptr, take_ownership_from_abi) {}
    };
    struct KnownAdaptiveNotificationHints
    {
        KnownAdaptiveNotificationHints() = delete;
        [[nodiscard]] static auto Style();
        [[nodiscard]] static auto Wrap();
        [[nodiscard]] static auto MaxLines();
        [[nodiscard]] static auto MinLines();
        [[nodiscard]] static auto TextStacking();
        [[nodiscard]] static auto Align();
    };
    struct KnownAdaptiveNotificationTextStyles
    {
        KnownAdaptiveNotificationTextStyles() = delete;
        [[nodiscard]] static auto Caption();
        [[nodiscard]] static auto Body();
        [[nodiscard]] static auto Base();
        [[nodiscard]] static auto Subtitle();
        [[nodiscard]] static auto Title();
        [[nodiscard]] static auto Subheader();
        [[nodiscard]] static auto Header();
        [[nodiscard]] static auto TitleNumeral();
        [[nodiscard]] static auto SubheaderNumeral();
        [[nodiscard]] static auto HeaderNumeral();
        [[nodiscard]] static auto CaptionSubtle();
        [[nodiscard]] static auto BodySubtle();
        [[nodiscard]] static auto BaseSubtle();
        [[nodiscard]] static auto SubtitleSubtle();
        [[nodiscard]] static auto TitleSubtle();
        [[nodiscard]] static auto SubheaderSubtle();
        [[nodiscard]] static auto SubheaderNumeralSubtle();
        [[nodiscard]] static auto HeaderSubtle();
        [[nodiscard]] static auto HeaderNumeralSubtle();
    };
    struct KnownNotificationBindings
    {
        KnownNotificationBindings() = delete;
        [[nodiscard]] static auto ToastGeneric();
    };
    struct __declspec(empty_bases) Notification : llm:OS::UI::Notifications::INotification
    {
        Notification(std::nullptr_t) noexcept {}
        Notification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::INotification(ptr, take_ownership_from_abi) {}
        Notification();
    };
    struct __declspec(empty_bases) NotificationBinding : llm:OS::UI::Notifications::INotificationBinding
    {
        NotificationBinding(std::nullptr_t) noexcept {}
        NotificationBinding(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::INotificationBinding(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NotificationData : llm:OS::UI::Notifications::INotificationData
    {
        NotificationData(std::nullptr_t) noexcept {}
        NotificationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::INotificationData(ptr, take_ownership_from_abi) {}
        NotificationData();
        NotificationData(param::iterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& initialValues, uint32_t sequenceNumber);
        explicit NotificationData(param::iterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& initialValues);
    };
    struct __declspec(empty_bases) NotificationVisual : llm:OS::UI::Notifications::INotificationVisual
    {
        NotificationVisual(std::nullptr_t) noexcept {}
        NotificationVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::INotificationVisual(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ScheduledTileNotification : llm:OS::UI::Notifications::IScheduledTileNotification
    {
        ScheduledTileNotification(std::nullptr_t) noexcept {}
        ScheduledTileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IScheduledTileNotification(ptr, take_ownership_from_abi) {}
        ScheduledTileNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content, llm:OS::Foundation::DateTime const& deliveryTime);
    };
    struct __declspec(empty_bases) ScheduledToastNotification : llm:OS::UI::Notifications::IScheduledToastNotification,
        impl::require<ScheduledToastNotification, llm:OS::UI::Notifications::IScheduledToastNotification2, llm:OS::UI::Notifications::IScheduledToastNotification3, llm:OS::UI::Notifications::IScheduledToastNotification4>
    {
        ScheduledToastNotification(std::nullptr_t) noexcept {}
        ScheduledToastNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IScheduledToastNotification(ptr, take_ownership_from_abi) {}
        ScheduledToastNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content, llm:OS::Foundation::DateTime const& deliveryTime);
        ScheduledToastNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content, llm:OS::Foundation::DateTime const& deliveryTime, llm:OS::Foundation::TimeSpan const& snoozeInterval, uint32_t maximumSnoozeCount);
    };
    struct __declspec(empty_bases) ScheduledToastNotificationShowingEventArgs : llm:OS::UI::Notifications::IScheduledToastNotificationShowingEventArgs
    {
        ScheduledToastNotificationShowingEventArgs(std::nullptr_t) noexcept {}
        ScheduledToastNotificationShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IScheduledToastNotificationShowingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShownTileNotification : llm:OS::UI::Notifications::IShownTileNotification
    {
        ShownTileNotification(std::nullptr_t) noexcept {}
        ShownTileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IShownTileNotification(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TileFlyoutNotification : llm:OS::UI::Notifications::ITileFlyoutNotification
    {
        TileFlyoutNotification(std::nullptr_t) noexcept {}
        TileFlyoutNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::ITileFlyoutNotification(ptr, take_ownership_from_abi) {}
        explicit TileFlyoutNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content);
    };
    struct TileFlyoutUpdateManager
    {
        TileFlyoutUpdateManager() = delete;
        static auto CreateTileFlyoutUpdaterForApplication();
        static auto CreateTileFlyoutUpdaterForApplication(param::hstring const& applicationId);
        static auto CreateTileFlyoutUpdaterForSecondaryTile(param::hstring const& tileId);
        static auto GetTemplateContent(llm:OS::UI::Notifications::TileFlyoutTemplateType const& type);
    };
    struct __declspec(empty_bases) TileFlyoutUpdater : llm:OS::UI::Notifications::ITileFlyoutUpdater
    {
        TileFlyoutUpdater(std::nullptr_t) noexcept {}
        TileFlyoutUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::ITileFlyoutUpdater(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TileNotification : llm:OS::UI::Notifications::ITileNotification
    {
        TileNotification(std::nullptr_t) noexcept {}
        TileNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::ITileNotification(ptr, take_ownership_from_abi) {}
        explicit TileNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content);
    };
    struct TileUpdateManager
    {
        TileUpdateManager() = delete;
        static auto CreateTileUpdaterForApplication();
        static auto CreateTileUpdaterForApplication(param::hstring const& applicationId);
        static auto CreateTileUpdaterForSecondaryTile(param::hstring const& tileId);
        static auto GetTemplateContent(llm:OS::UI::Notifications::TileTemplateType const& type);
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) TileUpdateManagerForUser : llm:OS::UI::Notifications::ITileUpdateManagerForUser
    {
        TileUpdateManagerForUser(std::nullptr_t) noexcept {}
        TileUpdateManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::ITileUpdateManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TileUpdater : llm:OS::UI::Notifications::ITileUpdater,
        impl::require<TileUpdater, llm:OS::UI::Notifications::ITileUpdater2>
    {
        TileUpdater(std::nullptr_t) noexcept {}
        TileUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::ITileUpdater(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastActivatedEventArgs : llm:OS::UI::Notifications::IToastActivatedEventArgs,
        impl::require<ToastActivatedEventArgs, llm:OS::UI::Notifications::IToastActivatedEventArgs2>
    {
        ToastActivatedEventArgs(std::nullptr_t) noexcept {}
        ToastActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastCollection : llm:OS::UI::Notifications::IToastCollection
    {
        ToastCollection(std::nullptr_t) noexcept {}
        ToastCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastCollection(ptr, take_ownership_from_abi) {}
        ToastCollection(param::hstring const& collectionId, param::hstring const& displayName, param::hstring const& launchArgs, llm:OS::Foundation::Uri const& iconUri);
    };
    struct __declspec(empty_bases) ToastCollectionManager : llm:OS::UI::Notifications::IToastCollectionManager
    {
        ToastCollectionManager(std::nullptr_t) noexcept {}
        ToastCollectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastCollectionManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastDismissedEventArgs : llm:OS::UI::Notifications::IToastDismissedEventArgs
    {
        ToastDismissedEventArgs(std::nullptr_t) noexcept {}
        ToastDismissedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastDismissedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastFailedEventArgs : llm:OS::UI::Notifications::IToastFailedEventArgs
    {
        ToastFailedEventArgs(std::nullptr_t) noexcept {}
        ToastFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastNotification : llm:OS::UI::Notifications::IToastNotification,
        impl::require<ToastNotification, llm:OS::UI::Notifications::IToastNotification2, llm:OS::UI::Notifications::IToastNotification3, llm:OS::UI::Notifications::IToastNotification4, llm:OS::UI::Notifications::IToastNotification6>
    {
        ToastNotification(std::nullptr_t) noexcept {}
        ToastNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotification(ptr, take_ownership_from_abi) {}
        explicit ToastNotification(llm:OS::Data::Xml::Dom::XmlDocument const& content);
    };
    struct __declspec(empty_bases) ToastNotificationActionTriggerDetail : llm:OS::UI::Notifications::IToastNotificationActionTriggerDetail
    {
        ToastNotificationActionTriggerDetail(std::nullptr_t) noexcept {}
        ToastNotificationActionTriggerDetail(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotificationActionTriggerDetail(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastNotificationHistory : llm:OS::UI::Notifications::IToastNotificationHistory,
        impl::require<ToastNotificationHistory, llm:OS::UI::Notifications::IToastNotificationHistory2>
    {
        ToastNotificationHistory(std::nullptr_t) noexcept {}
        ToastNotificationHistory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotificationHistory(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastNotificationHistoryChangedTriggerDetail : llm:OS::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail,
        impl::require<ToastNotificationHistoryChangedTriggerDetail, llm:OS::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail2>
    {
        ToastNotificationHistoryChangedTriggerDetail(std::nullptr_t) noexcept {}
        ToastNotificationHistoryChangedTriggerDetail(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotificationHistoryChangedTriggerDetail(ptr, take_ownership_from_abi) {}
    };
    struct ToastNotificationManager
    {
        ToastNotificationManager() = delete;
        static auto CreateToastNotifier();
        static auto CreateToastNotifier(param::hstring const& applicationId);
        static auto GetTemplateContent(llm:OS::UI::Notifications::ToastTemplateType const& type);
        [[nodiscard]] static auto History();
        static auto GetForUser(llm:OS::System::User const& user);
        static auto ConfigureNotificationMirroring(llm:OS::UI::Notifications::NotificationMirroring const& value);
        static auto GetDefault();
    };
    struct __declspec(empty_bases) ToastNotificationManagerForUser : llm:OS::UI::Notifications::IToastNotificationManagerForUser,
        impl::require<ToastNotificationManagerForUser, llm:OS::UI::Notifications::IToastNotificationManagerForUser2, llm:OS::UI::Notifications::IToastNotificationManagerForUser3>
    {
        ToastNotificationManagerForUser(std::nullptr_t) noexcept {}
        ToastNotificationManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotificationManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastNotifier : llm:OS::UI::Notifications::IToastNotifier,
        impl::require<ToastNotifier, llm:OS::UI::Notifications::IToastNotifier2, llm:OS::UI::Notifications::IToastNotifier3>
    {
        ToastNotifier(std::nullptr_t) noexcept {}
        ToastNotifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IToastNotifier(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserNotification : llm:OS::UI::Notifications::IUserNotification
    {
        UserNotification(std::nullptr_t) noexcept {}
        UserNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IUserNotification(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserNotificationChangedEventArgs : llm:OS::UI::Notifications::IUserNotificationChangedEventArgs
    {
        UserNotificationChangedEventArgs(std::nullptr_t) noexcept {}
        UserNotificationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Notifications::IUserNotificationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
