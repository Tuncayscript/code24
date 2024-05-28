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
#ifndef LLM_OS_Media_AppBroadcasting_H
#define LLM_OS_Media_AppBroadcasting_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Media.AppBroadcasting.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>::IsCurrentAppBroadcasting() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor)->get_IsCurrentAppBroadcasting(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>::IsCurrentAppBroadcastingChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::AppBroadcasting::AppBroadcastingMonitor, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor)->add_IsCurrentAppBroadcastingChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>::IsCurrentAppBroadcastingChanged_revoker consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>::IsCurrentAppBroadcastingChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::AppBroadcasting::AppBroadcastingMonitor, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsCurrentAppBroadcastingChanged_revoker>(this, IsCurrentAppBroadcastingChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_AppBroadcasting_IAppBroadcastingMonitor<D>::IsCurrentAppBroadcastingChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor)->remove_IsCurrentAppBroadcastingChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus<D>::CanStartBroadcast() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatus)->get_CanStartBroadcast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppBroadcasting::AppBroadcastingStatusDetails) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatus<D>::Details() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatus)->get_Details(&value));
        return llm::OS::Media::AppBroadcasting::AppBroadcastingStatusDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsAnyAppBroadcasting() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsAnyAppBroadcasting(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsCaptureResourceUnavailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsCaptureResourceUnavailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsGameStreamInProgress() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsGameStreamInProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsGpuConstrained() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsGpuConstrained(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsAppInactive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsAppInactive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsBlockedForApp() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsBlockedForApp(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsDisabledByUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsDisabledByUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_AppBroadcasting_IAppBroadcastingStatusDetails<D>::IsDisabledBySystem() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails)->get_IsDisabledBySystem(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppBroadcasting::AppBroadcastingStatus) consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI<D>::GetStatus() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingUI)->GetStatus(&result));
        return llm::OS::Media::AppBroadcasting::AppBroadcastingStatus{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_AppBroadcasting_IAppBroadcastingUI<D>::ShowBroadcastUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingUI)->ShowBroadcastUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppBroadcasting::AppBroadcastingUI) consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingUIStatics)->GetDefault(&result));
        return llm::OS::Media::AppBroadcasting::AppBroadcastingUI{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AppBroadcasting::AppBroadcastingUI) consume_Windows_Media_AppBroadcasting_IAppBroadcastingUIStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::AppBroadcasting::IAppBroadcastingUIStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::Media::AppBroadcasting::AppBroadcastingUI{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor> : produce_base<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor>
    {
        int32_t __stdcall get_IsCurrentAppBroadcasting(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCurrentAppBroadcasting());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsCurrentAppBroadcastingChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsCurrentAppBroadcastingChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::AppBroadcasting::AppBroadcastingMonitor, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsCurrentAppBroadcastingChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCurrentAppBroadcastingChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingStatus> : produce_base<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingStatus>
    {
        int32_t __stdcall get_CanStartBroadcast(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanStartBroadcast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Details(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::AppBroadcasting::AppBroadcastingStatusDetails>(this->shim().Details());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails> : produce_base<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails>
    {
        int32_t __stdcall get_IsAnyAppBroadcasting(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAnyAppBroadcasting());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCaptureResourceUnavailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCaptureResourceUnavailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsGameStreamInProgress(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsGameStreamInProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsGpuConstrained(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsGpuConstrained());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAppInactive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAppInactive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsBlockedForApp(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBlockedForApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDisabledByUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDisabledByUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDisabledBySystem(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDisabledBySystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingUI> : produce_base<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingUI>
    {
        int32_t __stdcall GetStatus(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::AppBroadcasting::AppBroadcastingStatus>(this->shim().GetStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowBroadcastUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowBroadcastUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingUIStatics> : produce_base<D, llm::OS::Media::AppBroadcasting::IAppBroadcastingUIStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::AppBroadcasting::AppBroadcastingUI>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::AppBroadcasting::AppBroadcastingUI>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::AppBroadcasting
{
    inline AppBroadcastingMonitor::AppBroadcastingMonitor() :
        AppBroadcastingMonitor(impl::call_factory_cast<AppBroadcastingMonitor(*)(llm::OS::Foundation::IActivationFactory const&), AppBroadcastingMonitor>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AppBroadcastingMonitor>(); }))
    {
    }
    inline auto AppBroadcastingUI::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Media::AppBroadcasting::AppBroadcastingUI(*)(IAppBroadcastingUIStatics const&), AppBroadcastingUI, IAppBroadcastingUIStatics>([](IAppBroadcastingUIStatics const& f) { return f.GetDefault(); });
    }
    inline auto AppBroadcastingUI::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<AppBroadcastingUI, IAppBroadcastingUIStatics>([&](IAppBroadcastingUIStatics const& f) { return f.GetForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::AppBroadcasting::IAppBroadcastingMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::IAppBroadcastingStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::IAppBroadcastingStatusDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::IAppBroadcastingUI> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::IAppBroadcastingUIStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::AppBroadcastingMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::AppBroadcastingStatus> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::AppBroadcastingStatusDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::AppBroadcasting::AppBroadcastingUI> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
