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
#ifndef LLM_OS_Gaming_UI_H
#define LLM_OS_Gaming_UI_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Gaming.UI.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_UI_IGameBarStatics<D>::VisibilityChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->add_VisibilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_UI_IGameBarStatics<D>::VisibilityChanged_revoker consume_Windows_Gaming_UI_IGameBarStatics<D>::VisibilityChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, VisibilityChanged_revoker>(this, VisibilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameBarStatics<D>::VisibilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->remove_VisibilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_UI_IGameBarStatics<D>::IsInputRedirectedChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->add_IsInputRedirectedChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_UI_IGameBarStatics<D>::IsInputRedirectedChanged_revoker consume_Windows_Gaming_UI_IGameBarStatics<D>::IsInputRedirectedChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsInputRedirectedChanged_revoker>(this, IsInputRedirectedChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameBarStatics<D>::IsInputRedirectedChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->remove_IsInputRedirectedChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_UI_IGameBarStatics<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Gaming_UI_IGameBarStatics<D>::IsInputRedirected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameBarStatics)->get_IsInputRedirected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_UI_IGameChatMessageReceivedEventArgs<D>::AppId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs)->get_AppId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_UI_IGameChatMessageReceivedEventArgs<D>::AppDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs)->get_AppDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_UI_IGameChatMessageReceivedEventArgs<D>::SenderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs)->get_SenderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_UI_IGameChatMessageReceivedEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs)->get_Message(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::UI::GameChatMessageOrigin) consume_Windows_Gaming_UI_IGameChatMessageReceivedEventArgs<D>::Origin() const
    {
        llm::OS::Gaming::UI::GameChatMessageOrigin value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs)->get_Origin(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::UI::GameChatOverlayPosition) consume_Windows_Gaming_UI_IGameChatOverlay<D>::DesiredPosition() const
    {
        llm::OS::Gaming::UI::GameChatOverlayPosition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlay)->get_DesiredPosition(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameChatOverlay<D>::DesiredPosition(llm::OS::Gaming::UI::GameChatOverlayPosition const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlay)->put_DesiredPosition(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameChatOverlay<D>::AddMessage(param::hstring const& sender, param::hstring const& message, llm::OS::Gaming::UI::GameChatMessageOrigin const& origin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlay)->AddMessage(*(void**)(&sender), *(void**)(&message), static_cast<int32_t>(origin)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Gaming_UI_IGameChatOverlayMessageSource<D>::MessageReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::UI::GameChatOverlayMessageSource, llm::OS::Gaming::UI::GameChatMessageReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlayMessageSource)->add_MessageReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Gaming_UI_IGameChatOverlayMessageSource<D>::MessageReceived_revoker consume_Windows_Gaming_UI_IGameChatOverlayMessageSource<D>::MessageReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::UI::GameChatOverlayMessageSource, llm::OS::Gaming::UI::GameChatMessageReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, MessageReceived_revoker>(this, MessageReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameChatOverlayMessageSource<D>::MessageReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlayMessageSource)->remove_MessageReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameChatOverlayMessageSource<D>::SetDelayBeforeClosingAfterMessageReceived(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlayMessageSource)->SetDelayBeforeClosingAfterMessageReceived(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Gaming::UI::GameChatOverlay) consume_Windows_Gaming_UI_IGameChatOverlayStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameChatOverlayStatics)->GetDefault(&value));
        return llm::OS::Gaming::UI::GameChatOverlay{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Gaming_UI_IGameUIProviderActivatedEventArgs<D>::GameUIArgs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameUIProviderActivatedEventArgs)->get_GameUIArgs(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Gaming_UI_IGameUIProviderActivatedEventArgs<D>::ReportCompleted(llm::OS::Foundation::Collections::ValueSet const& results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::UI::IGameUIProviderActivatedEventArgs)->ReportCompleted(*(void**)(&results)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameBarStatics> : produce_base<D, llm::OS::Gaming::UI::IGameBarStatics>
    {
        int32_t __stdcall add_VisibilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VisibilityChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisibilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_IsInputRedirectedChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsInputRedirectedChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsInputRedirectedChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputRedirectedChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Visible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Visible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInputRedirected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInputRedirected());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs> : produce_base<D, llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs>
    {
        int32_t __stdcall get_AppId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SenderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SenderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Origin(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::UI::GameChatMessageOrigin>(this->shim().Origin());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameChatOverlay> : produce_base<D, llm::OS::Gaming::UI::IGameChatOverlay>
    {
        int32_t __stdcall get_DesiredPosition(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::UI::GameChatOverlayPosition>(this->shim().DesiredPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DesiredPosition(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredPosition(*reinterpret_cast<llm::OS::Gaming::UI::GameChatOverlayPosition const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddMessage(void* sender, void* message, int32_t origin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddMessage(*reinterpret_cast<hstring const*>(&sender), *reinterpret_cast<hstring const*>(&message), *reinterpret_cast<llm::OS::Gaming::UI::GameChatMessageOrigin const*>(&origin));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameChatOverlayMessageSource> : produce_base<D, llm::OS::Gaming::UI::IGameChatOverlayMessageSource>
    {
        int32_t __stdcall add_MessageReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MessageReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::UI::GameChatOverlayMessageSource, llm::OS::Gaming::UI::GameChatMessageReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall SetDelayBeforeClosingAfterMessageReceived(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDelayBeforeClosingAfterMessageReceived(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameChatOverlayStatics> : produce_base<D, llm::OS::Gaming::UI::IGameChatOverlayStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Gaming::UI::GameChatOverlay>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::UI::IGameUIProviderActivatedEventArgs> : produce_base<D, llm::OS::Gaming::UI::IGameUIProviderActivatedEventArgs>
    {
        int32_t __stdcall get_GameUIArgs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().GameUIArgs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCompleted(void* results) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&results));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Gaming::UI
{
    inline auto GameBar::VisibilityChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<GameBar, IGameBarStatics>([&](IGameBarStatics const& f) { return f.VisibilityChanged(handler); });
    }
    inline GameBar::VisibilityChanged_revoker GameBar::VisibilityChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<GameBar, llm::OS::Gaming::UI::IGameBarStatics>();
        return { f, f.VisibilityChanged(handler) };
    }
    inline auto GameBar::VisibilityChanged(llm::event_token const& token)
    {
        impl::call_factory<GameBar, IGameBarStatics>([&](IGameBarStatics const& f) { return f.VisibilityChanged(token); });
    }
    inline auto GameBar::IsInputRedirectedChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<GameBar, IGameBarStatics>([&](IGameBarStatics const& f) { return f.IsInputRedirectedChanged(handler); });
    }
    inline GameBar::IsInputRedirectedChanged_revoker GameBar::IsInputRedirectedChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<GameBar, llm::OS::Gaming::UI::IGameBarStatics>();
        return { f, f.IsInputRedirectedChanged(handler) };
    }
    inline auto GameBar::IsInputRedirectedChanged(llm::event_token const& token)
    {
        impl::call_factory<GameBar, IGameBarStatics>([&](IGameBarStatics const& f) { return f.IsInputRedirectedChanged(token); });
    }
    inline auto GameBar::Visible()
    {
        return impl::call_factory_cast<bool(*)(IGameBarStatics const&), GameBar, IGameBarStatics>([](IGameBarStatics const& f) { return f.Visible(); });
    }
    inline auto GameBar::IsInputRedirected()
    {
        return impl::call_factory_cast<bool(*)(IGameBarStatics const&), GameBar, IGameBarStatics>([](IGameBarStatics const& f) { return f.IsInputRedirected(); });
    }
    inline auto GameChatOverlay::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Gaming::UI::GameChatOverlay(*)(IGameChatOverlayStatics const&), GameChatOverlay, IGameChatOverlayStatics>([](IGameChatOverlayStatics const& f) { return f.GetDefault(); });
    }
    inline GameChatOverlayMessageSource::GameChatOverlayMessageSource() :
        GameChatOverlayMessageSource(impl::call_factory_cast<GameChatOverlayMessageSource(*)(llm::OS::Foundation::IActivationFactory const&), GameChatOverlayMessageSource>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<GameChatOverlayMessageSource>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Gaming::UI::IGameBarStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::IGameChatMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::IGameChatOverlay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::IGameChatOverlayMessageSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::IGameChatOverlayStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::IGameUIProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::GameBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::GameChatMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::GameChatOverlay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::GameChatOverlayMessageSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::UI::GameUIProviderActivatedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
