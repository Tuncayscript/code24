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
#ifndef LLM_OS_System_RemoteDesktop_Input_H
#define LLM_OS_System_RemoteDesktop_Input_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.RemoteDesktop.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.System.RemoteDesktop.Input.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>::RegisterThread(uint32_t threadId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection)->RegisterThread(threadId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>::UnregisterThread(uint32_t threadId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection)->UnregisterThread(threadId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnection<D>::ReportDataReceived(array_view<uint8_t const> pduData) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection)->ReportDataReceived(pduData.size(), get_abi(pduData)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteDesktop::Input::RemoteTextConnection) consume_Windows_System_RemoteDesktop_Input_IRemoteTextConnectionFactory<D>::CreateInstance(llm::guid const& connectionId, llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler const& pduForwarder) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory)->CreateInstance(impl::bind_in(connectionId), *(void**)(&pduForwarder), &value));
        return llm::OS::System::RemoteDesktop::Input::RemoteTextConnection{ value, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler, H> final : implements_delegate<llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(uint32_t __pduDataSize, uint8_t* pduData, bool* result) noexcept final try
        {
            *result = detach_from<bool>((*this)(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(pduData), reinterpret_cast<uint8_t const *>(pduData) + __pduDataSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection> : produce_base<D, llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterThread(uint32_t threadId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RegisterThread(threadId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterThread(uint32_t threadId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterThread(threadId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportDataReceived(uint32_t __pduDataSize, uint8_t* pduData) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportDataReceived(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(pduData), reinterpret_cast<uint8_t const *>(pduData) + __pduDataSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory> : produce_base<D, llm::OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory>
    {
        int32_t __stdcall CreateInstance(llm::guid connectionId, void* pduForwarder, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteDesktop::Input::RemoteTextConnection>(this->shim().CreateInstance(*reinterpret_cast<llm::guid const*>(&connectionId), *reinterpret_cast<llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler const*>(&pduForwarder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::RemoteDesktop::Input
{
    inline RemoteTextConnection::RemoteTextConnection(llm::guid const& connectionId, llm::OS::System::RemoteDesktop::Input::RemoteTextConnectionDataHandler const& pduForwarder) :
        RemoteTextConnection(impl::call_factory<RemoteTextConnection, IRemoteTextConnectionFactory>([&](IRemoteTextConnectionFactory const& f) { return f.CreateInstance(connectionId, pduForwarder); }))
    {
    }
    template <typename L> RemoteTextConnectionDataHandler::RemoteTextConnectionDataHandler(L handler) :
        RemoteTextConnectionDataHandler(impl::make_delegate<RemoteTextConnectionDataHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> RemoteTextConnectionDataHandler::RemoteTextConnectionDataHandler(F* handler) :
        RemoteTextConnectionDataHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> RemoteTextConnectionDataHandler::RemoteTextConnectionDataHandler(O* object, M method) :
        RemoteTextConnectionDataHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> RemoteTextConnectionDataHandler::RemoteTextConnectionDataHandler(com_ptr<O>&& object, M method) :
        RemoteTextConnectionDataHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> RemoteTextConnectionDataHandler::RemoteTextConnectionDataHandler(weak_ref<O>&& object, M method) :
        RemoteTextConnectionDataHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto RemoteTextConnectionDataHandler::operator()(array_view<uint8_t const> pduData) const
    {
        bool result{};
        check_hresult((*(impl::abi_t<RemoteTextConnectionDataHandler>**)this)->Invoke(pduData.size(), get_abi(pduData), &result));
        return result;
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::RemoteDesktop::Input::IRemoteTextConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Input::IRemoteTextConnectionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::Input::RemoteTextConnection> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
