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
#ifndef LLM_OS_UI_Notifications_Management_0_H
#define LLM_OS_UI_Notifications_Management_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::UI::Notifications
{
    enum class NotificationKinds : uint32_t;
    struct UserNotification;
    struct UserNotificationChangedEventArgs;
}
LLM_EXPORT namespace llm:OS::UI::Notifications::Management
{
    enum class UserNotificationListenerAccessStatus : int32_t
    {
        Unspecified = 0,
        Allowed = 1,
        Denied = 2,
    };
    struct IUserNotificationListener;
    struct IUserNotificationListenerStatics;
    struct UserNotificationListener;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Notifications::Management::IUserNotificationListener>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Notifications::Management::IUserNotificationListenerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Notifications::Management::UserNotificationListener>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Management::UserNotificationListener> = L"Windows.UI.Notifications.Management.UserNotificationListener";
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Management::UserNotificationListenerAccessStatus> = L"Windows.UI.Notifications.Management.UserNotificationListenerAccessStatus";
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Management::IUserNotificationListener> = L"Windows.UI.Notifications.Management.IUserNotificationListener";
    template <> inline constexpr auto& name_v<llm:OS::UI::Notifications::Management::IUserNotificationListenerStatics> = L"Windows.UI.Notifications.Management.IUserNotificationListenerStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Notifications::Management::IUserNotificationListener>{ 0x62553E41,0x8A06,0x4CEF,{ 0x82,0x15,0x60,0x33,0xA5,0xBE,0x4B,0x03 } }; // 62553E41-8A06-4CEF-8215-6033A5BE4B03
    template <> inline constexpr guid guid_v<llm:OS::UI::Notifications::Management::IUserNotificationListenerStatics>{ 0xFF6123CF,0x4386,0x4AA3,{ 0xB7,0x3D,0xB8,0x04,0xE5,0xB6,0x3B,0x23 } }; // FF6123CF-4386-4AA3-B73D-B804E5B63B23
    template <> struct default_interface<llm:OS::UI::Notifications::Management::UserNotificationListener>{ using type = llm:OS::UI::Notifications::Management::IUserNotificationListener; };
    template <> struct abi<llm:OS::UI::Notifications::Management::IUserNotificationListener>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAccessStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_NotificationChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NotificationChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetNotificationsAsync(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetNotification(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ClearNotifications() noexcept = 0;
            virtual int32_t __stdcall RemoveNotification(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Notifications::Management::IUserNotificationListenerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Notifications_Management_IUserNotificationListener
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>) RequestAccessAsync() const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::Management::UserNotificationListenerAccessStatus) GetAccessStatus() const;
        LLM_IMPL_AUTO(llm::event_token) NotificationChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Notifications::Management::UserNotificationListener, llm:OS::UI::Notifications::UserNotificationChangedEventArgs> const& handler) const;
        using NotificationChanged_revoker = impl::event_revoker<llm:OS::UI::Notifications::Management::IUserNotificationListener, &impl::abi_t<llm:OS::UI::Notifications::Management::IUserNotificationListener>::remove_NotificationChanged>;
        [[nodiscard]] NotificationChanged_revoker NotificationChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Notifications::Management::UserNotificationListener, llm:OS::UI::Notifications::UserNotificationChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) NotificationChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::Notifications::UserNotification>>) GetNotificationsAsync(llm:OS::UI::Notifications::NotificationKinds const& kinds) const;
        LLM_IMPL_AUTO(llm:OS::UI::Notifications::UserNotification) GetNotification(uint32_t notificationId) const;
        LLM_IMPL_AUTO(void) ClearNotifications() const;
        LLM_IMPL_AUTO(void) RemoveNotification(uint32_t notificationId) const;
    };
    template <> struct consume<llm:OS::UI::Notifications::Management::IUserNotificationListener>
    {
        template <typename D> using type = consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Notifications_Management_IUserNotificationListenerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Notifications::Management::UserNotificationListener) Current() const;
    };
    template <> struct consume<llm:OS::UI::Notifications::Management::IUserNotificationListenerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Notifications_Management_IUserNotificationListenerStatics<D>;
    };
}
#endif
