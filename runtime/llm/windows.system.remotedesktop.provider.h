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
#ifndef LLM_OS_System_RemoteDesktop_Provider_H
#define LLM_OS_System_RemoteDesktop_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.RemoteDesktop.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.System.RemoteDesktop.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteDesktop::Provider::RemoteDesktopLocalAction) consume_Windows_System_RemoteDesktop_Provider_IPerformLocalActionRequestedEventArgs<D>::Action() const
    {
        llm::OS::System::RemoteDesktop::Provider::RemoteDesktopLocalAction value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs)->get_Action(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionInfo<D>::SetConnectionStatus(llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionStatus const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo)->SetConnectionStatus(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionInfo<D>::SwitchToLocalSession() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo)->SwitchToLocalSession());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionInfo) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionInfoStatics<D>::GetForLaunchUri(llm::OS::Foundation::Uri const& launchUri, llm::OS::UI::WindowId const& windowId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfoStatics)->GetForLaunchUri(*(void**)(&launchUri), impl::bind_in(windowId), &result));
        return llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::ReportSwitched() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo)->ReportSwitched());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::SwitchToLocalSessionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo)->add_SwitchToLocalSessionRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::SwitchToLocalSessionRequested_revoker consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::SwitchToLocalSessionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SwitchToLocalSessionRequested_revoker>(this, SwitchToLocalSessionRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::SwitchToLocalSessionRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo)->remove_SwitchToLocalSessionRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::PerformLocalActionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::System::RemoteDesktop::Provider::PerformLocalActionRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo)->add_PerformLocalActionRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::PerformLocalActionRequested_revoker consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::PerformLocalActionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::System::RemoteDesktop::Provider::PerformLocalActionRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PerformLocalActionRequested_revoker>(this, PerformLocalActionRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfo<D>::PerformLocalActionRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo)->remove_PerformLocalActionRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfoStatics<D>::IsSwitchSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfoStatics)->IsSwitchSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopConnectionRemoteInfoStatics<D>::GetForLaunchUri(llm::OS::Foundation::Uri const& launchUri) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfoStatics)->GetForLaunchUri(*(void**)(&launchUri), &result));
        return llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopInfo<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopInfoFactory<D>::CreateInstance(param::hstring const& id, param::hstring const& displayName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfoFactory)->CreateInstance(*(void**)(&id), *(void**)(&displayName), &value));
        return llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo>) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopRegistrarStatics<D>::DesktopInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopRegistrarStatics)->get_DesktopInfos(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteDesktop_Provider_IRemoteDesktopRegistrarStatics<D>::IsSwitchToLocalSessionEnabled() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopRegistrarStatics)->IsSwitchToLocalSessionEnabled(&result));
        return result;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs>
    {
        int32_t __stdcall get_Action(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopLocalAction>(this->shim().Action());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo>
    {
        int32_t __stdcall SetConnectionStatus(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetConnectionStatus(*reinterpret_cast<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionStatus const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SwitchToLocalSession() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SwitchToLocalSession();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfoStatics> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfoStatics>
    {
        int32_t __stdcall GetForLaunchUri(void* launchUri, struct struct_Windows_UI_WindowId windowId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionInfo>(this->shim().GetForLaunchUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&launchUri), *reinterpret_cast<llm::OS::UI::WindowId const*>(&windowId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo>
    {
        int32_t __stdcall ReportSwitched() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportSwitched();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SwitchToLocalSessionRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SwitchToLocalSessionRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SwitchToLocalSessionRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SwitchToLocalSessionRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PerformLocalActionRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PerformLocalActionRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo, llm::OS::System::RemoteDesktop::Provider::PerformLocalActionRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PerformLocalActionRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PerformLocalActionRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfoStatics> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfoStatics>
    {
        int32_t __stdcall IsSwitchSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSwitchSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForLaunchUri(void* launchUri, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo>(this->shim().GetForLaunchUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&launchUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfoFactory> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfoFactory>
    {
        int32_t __stdcall CreateInstance(void* id, void* displayName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopRegistrarStatics> : produce_base<D, llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopRegistrarStatics>
    {
        int32_t __stdcall get_DesktopInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo>>(this->shim().DesktopInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSwitchToLocalSessionEnabled(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSwitchToLocalSessionEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::RemoteDesktop::Provider
{
    inline auto RemoteDesktopConnectionInfo::GetForLaunchUri(llm::OS::Foundation::Uri const& launchUri, llm::OS::UI::WindowId const& windowId)
    {
        return impl::call_factory<RemoteDesktopConnectionInfo, IRemoteDesktopConnectionInfoStatics>([&](IRemoteDesktopConnectionInfoStatics const& f) { return f.GetForLaunchUri(launchUri, windowId); });
    }
    inline auto RemoteDesktopConnectionRemoteInfo::IsSwitchSupported()
    {
        return impl::call_factory_cast<bool(*)(IRemoteDesktopConnectionRemoteInfoStatics const&), RemoteDesktopConnectionRemoteInfo, IRemoteDesktopConnectionRemoteInfoStatics>([](IRemoteDesktopConnectionRemoteInfoStatics const& f) { return f.IsSwitchSupported(); });
    }
    inline auto RemoteDesktopConnectionRemoteInfo::GetForLaunchUri(llm::OS::Foundation::Uri const& launchUri)
    {
        return impl::call_factory<RemoteDesktopConnectionRemoteInfo, IRemoteDesktopConnectionRemoteInfoStatics>([&](IRemoteDesktopConnectionRemoteInfoStatics const& f) { return f.GetForLaunchUri(launchUri); });
    }
    inline RemoteDesktopInfo::RemoteDesktopInfo(param::hstring const& id, param::hstring const& displayName) :
        RemoteDesktopInfo(impl::call_factory<RemoteDesktopInfo, IRemoteDesktopInfoFactory>([&](IRemoteDesktopInfoFactory const& f) { return f.CreateInstance(id, displayName); }))
    {
    }
    inline auto RemoteDesktopRegistrar::DesktopInfos()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVector<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo>(*)(IRemoteDesktopRegistrarStatics const&), RemoteDesktopRegistrar, IRemoteDesktopRegistrarStatics>([](IRemoteDesktopRegistrarStatics const& f) { return f.DesktopInfos(); });
    }
    inline auto RemoteDesktopRegistrar::IsSwitchToLocalSessionEnabled()
    {
        return impl::call_factory_cast<bool(*)(IRemoteDesktopRegistrarStatics const&), RemoteDesktopRegistrar, IRemoteDesktopRegistrarStatics>([](IRemoteDesktopRegistrarStatics const& f) { return f.IsSwitchToLocalSessionEnabled(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IPerformLocalActionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopConnectionRemoteInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopInfoFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::IRemoteDesktopRegistrarStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::PerformLocalActionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopConnectionRemoteInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Provider::RemoteDesktopRegistrar> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
