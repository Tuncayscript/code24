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
#ifndef LLM_OS_UI_Notifications_Management_H
#define LLM_OS_UI_Notifications_Management_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Notifications.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Notifications.2.h"
#include "llm/impl/Windows.UI.Notifications.Management.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::GetAccessStatus() const
    {
        llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->GetAccessStatus(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::NotificationChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Notifications::Management::UserNotificationListener, llm::OS::UI::Notifications::UserNotificationChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->add_NotificationChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::NotificationChanged_revoker consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::NotificationChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Notifications::Management::UserNotificationListener, llm::OS::UI::Notifications::UserNotificationChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, NotificationChanged_revoker>(this, NotificationChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::NotificationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->remove_NotificationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::UserNotification>>) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::GetNotificationsAsync(llm::OS::UI::Notifications::NotificationKinds const& kinds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->GetNotificationsAsync(static_cast<uint32_t>(kinds), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::UserNotification>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::UserNotification) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::GetNotification(uint32_t notificationId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->GetNotification(notificationId, &result));
        return llm::OS::UI::Notifications::UserNotification{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::ClearNotifications() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->ClearNotifications());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Notifications_Management_IUserNotificationListener<D>::RemoveNotification(uint32_t notificationId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListener)->RemoveNotification(notificationId));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Notifications::Management::UserNotificationListener) consume_Windows_UI_Notifications_Management_IUserNotificationListenerStatics<D>::Current() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Management::IUserNotificationListenerStatics)->get_Current(&value));
        return llm::OS::UI::Notifications::Management::UserNotificationListener{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Notifications::Management::IUserNotificationListener> : produce_base<D, llm::OS::UI::Notifications::Management::IUserNotificationListener>
    {
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessStatus(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Notifications::Management::UserNotificationListenerAccessStatus>(this->shim().GetAccessStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_NotificationChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NotificationChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Notifications::Management::UserNotificationListener, llm::OS::UI::Notifications::UserNotificationChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NotificationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotificationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetNotificationsAsync(uint32_t kinds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::UserNotification>>>(this->shim().GetNotificationsAsync(*reinterpret_cast<llm::OS::UI::Notifications::NotificationKinds const*>(&kinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNotification(uint32_t notificationId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Notifications::UserNotification>(this->shim().GetNotification(notificationId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearNotifications() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearNotifications();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveNotification(uint32_t notificationId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveNotification(notificationId);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Notifications::Management::IUserNotificationListenerStatics> : produce_base<D, llm::OS::UI::Notifications::Management::IUserNotificationListenerStatics>
    {
        int32_t __stdcall get_Current(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Notifications::Management::UserNotificationListener>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Notifications::Management
{
    inline auto UserNotificationListener::Current()
    {
        return impl::call_factory_cast<llm::OS::UI::Notifications::Management::UserNotificationListener(*)(IUserNotificationListenerStatics const&), UserNotificationListener, IUserNotificationListenerStatics>([](IUserNotificationListenerStatics const& f) { return f.Current(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Notifications::Management::IUserNotificationListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Notifications::Management::IUserNotificationListenerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Notifications::Management::UserNotificationListener> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
