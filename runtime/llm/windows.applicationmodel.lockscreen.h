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
#ifndef LLM_OS_ApplicationModel_LockScreen_H
#define LLM_OS_ApplicationModel_LockScreen_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.LockScreen.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>::RequestUnlock() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockApplicationHost)->RequestUnlock());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>::Unlocking(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockApplicationHost, llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockApplicationHost)->add_Unlocking(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>::Unlocking_revoker consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>::Unlocking(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockApplicationHost, llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Unlocking_revoker>(this, Unlocking(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockApplicationHost<D>::Unlocking(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockApplicationHost)->remove_Unlocking(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::LockScreen::LockApplicationHost) consume_Windows_ApplicationModel_LockScreen_ILockApplicationHostStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics)->GetForCurrentView(&result));
        return llm::OS::ApplicationModel::LockScreen::LockApplicationHost{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>::Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenBadge)->get_Logo(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>::Glyph() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenBadge)->get_Glyph(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>::Number() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenBadge)->get_Number(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>::AutomationName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenBadge)->get_AutomationName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenBadge<D>::LaunchApp() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenBadge)->LaunchApp());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::LockScreenImageChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->add_LockScreenImageChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::LockScreenImageChanged_revoker consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::LockScreenImageChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, LockScreenImageChanged_revoker>(this, LockScreenImageChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::LockScreenImageChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->remove_LockScreenImageChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::LockScreenImage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->get_LockScreenImage(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::BadgesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->add_BadgesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::BadgesChanged_revoker consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::BadgesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, BadgesChanged_revoker>(this, BadgesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::BadgesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->remove_BadgesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::Badges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->get_Badges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::DetailTextChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->add_DetailTextChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::DetailTextChanged_revoker consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::DetailTextChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, DetailTextChanged_revoker>(this, DetailTextChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::DetailTextChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->remove_DetailTextChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::DetailText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->get_DetailText(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::AlarmIconChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->add_AlarmIconChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::AlarmIconChanged_revoker consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::AlarmIconChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AlarmIconChanged_revoker>(this, AlarmIconChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::AlarmIconChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->remove_AlarmIconChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_ApplicationModel_LockScreen_ILockScreenInfo<D>::AlarmIcon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenInfo)->get_AlarmIcon(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral) consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingEventArgs<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs)->GetDeferral(&deferral));
        return llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_LockScreen_ILockScreenUnlockingEventArgs<D>::Deadline() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs)->get_Deadline(put_abi(value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockApplicationHost> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockApplicationHost>
    {
        int32_t __stdcall RequestUnlock() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestUnlock();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Unlocking(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Unlocking(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockApplicationHost, llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Unlocking(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unlocking(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::LockScreen::LockApplicationHost>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockScreenBadge> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockScreenBadge>
    {
        int32_t __stdcall get_Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Glyph(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().Glyph());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Number(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().Number());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutomationName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AutomationName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchApp() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LaunchApp();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockScreenInfo> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockScreenInfo>
    {
        int32_t __stdcall add_LockScreenImageChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LockScreenImageChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LockScreenImageChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LockScreenImageChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_LockScreenImage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().LockScreenImage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_BadgesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BadgesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BadgesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BadgesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Badges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::LockScreen::LockScreenBadge>>(this->shim().Badges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DetailTextChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DetailTextChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DetailTextChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DetailTextChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_DetailText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().DetailText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AlarmIconChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AlarmIconChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::LockScreen::LockScreenInfo, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AlarmIconChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlarmIconChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_AlarmIcon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().AlarmIcon());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>
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
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs> : produce_base<D, llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>
    {
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral>(this->shim().GetDeferral());
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
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::LockScreen
{
    inline auto LockApplicationHost::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::LockScreen::LockApplicationHost(*)(ILockApplicationHostStatics const&), LockApplicationHost, ILockApplicationHostStatics>([](ILockApplicationHostStatics const& f) { return f.GetForCurrentView(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockApplicationHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockApplicationHostStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockScreenBadge> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockScreenInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::LockApplicationHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::LockScreenBadge> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::LockScreenInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
