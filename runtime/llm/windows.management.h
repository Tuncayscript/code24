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
#ifndef LLM_OS_Management_H
#define LLM_OS_Management_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Management.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_IMdmAlert<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Data(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Data(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Data(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::MdmAlertDataType) consume_Windows_Management_IMdmAlert<D>::Format() const
    {
        llm::OS::Management::MdmAlertDataType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Format(llm::OS::Management::MdmAlertDataType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Format(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::MdmAlertMark) consume_Windows_Management_IMdmAlert<D>::Mark() const
    {
        llm::OS::Management::MdmAlertMark value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Mark(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Mark(llm::OS::Management::MdmAlertMark const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Mark(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_IMdmAlert<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Source(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Source(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Management_IMdmAlert<D>::Status() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Status(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_IMdmAlert<D>::Target() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Target(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Target(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Target(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_IMdmAlert<D>::Type() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->get_Type(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmAlert<D>::Type(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmAlert)->put_Type(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::MdmAlert>) consume_Windows_Management_IMdmSession<D>::Alerts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->get_Alerts(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::MdmAlert>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Management_IMdmSession<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_IMdmSession<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::MdmSessionState) consume_Windows_Management_IMdmSession<D>::State() const
    {
        llm::OS::Management::MdmSessionState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Management_IMdmSession<D>::AttachAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->AttachAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmSession<D>::Delete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->Delete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Management_IMdmSession<D>::StartAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->StartAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Management_IMdmSession<D>::StartAsync(param::async_iterable<llm::OS::Management::MdmAlert> const& alerts) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSession)->StartWithAlertsAsync(*(void**)(&alerts), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Management_IMdmSessionManagerStatics<D>::SessionIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSessionManagerStatics)->get_SessionIds(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::MdmSession) consume_Windows_Management_IMdmSessionManagerStatics<D>::TryCreateSession() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSessionManagerStatics)->TryCreateSession(&result));
        return llm::OS::Management::MdmSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_IMdmSessionManagerStatics<D>::DeleteSessionById(param::hstring const& sessionId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSessionManagerStatics)->DeleteSessionById(*(void**)(&sessionId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::MdmSession) consume_Windows_Management_IMdmSessionManagerStatics<D>::GetSessionById(param::hstring const& sessionId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::IMdmSessionManagerStatics)->GetSessionById(*(void**)(&sessionId), &result));
        return llm::OS::Management::MdmSession{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::IMdmAlert> : produce_base<D, llm::OS::Management::IMdmAlert>
    {
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Data(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::MdmAlertDataType>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Format(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(*reinterpret_cast<llm::OS::Management::MdmAlertDataType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mark(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::MdmAlertMark>(this->shim().Mark());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mark(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mark(*reinterpret_cast<llm::OS::Management::MdmAlertMark const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Target(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Target());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Target(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Target(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Type(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::IMdmSession> : produce_base<D, llm::OS::Management::IMdmSession>
    {
        int32_t __stdcall get_Alerts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::MdmAlert>>(this->shim().Alerts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
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
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::MdmSessionState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AttachAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().AttachAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Delete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delete();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartWithAlertsAsync(void* alerts, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StartAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Management::MdmAlert> const*>(&alerts)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::IMdmSessionManagerStatics> : produce_base<D, llm::OS::Management::IMdmSessionManagerStatics>
    {
        int32_t __stdcall get_SessionIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().SessionIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateSession(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::MdmSession>(this->shim().TryCreateSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteSessionById(void* sessionId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteSessionById(*reinterpret_cast<hstring const*>(&sessionId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSessionById(void* sessionId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::MdmSession>(this->shim().GetSessionById(*reinterpret_cast<hstring const*>(&sessionId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Management
{
    inline MdmAlert::MdmAlert() :
        MdmAlert(impl::call_factory_cast<MdmAlert(*)(llm::OS::Foundation::IActivationFactory const&), MdmAlert>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MdmAlert>(); }))
    {
    }
    inline auto MdmSessionManager::SessionIds()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IMdmSessionManagerStatics const&), MdmSessionManager, IMdmSessionManagerStatics>([](IMdmSessionManagerStatics const& f) { return f.SessionIds(); });
    }
    inline auto MdmSessionManager::TryCreateSession()
    {
        return impl::call_factory_cast<llm::OS::Management::MdmSession(*)(IMdmSessionManagerStatics const&), MdmSessionManager, IMdmSessionManagerStatics>([](IMdmSessionManagerStatics const& f) { return f.TryCreateSession(); });
    }
    inline auto MdmSessionManager::DeleteSessionById(param::hstring const& sessionId)
    {
        impl::call_factory<MdmSessionManager, IMdmSessionManagerStatics>([&](IMdmSessionManagerStatics const& f) { return f.DeleteSessionById(sessionId); });
    }
    inline auto MdmSessionManager::GetSessionById(param::hstring const& sessionId)
    {
        return impl::call_factory<MdmSessionManager, IMdmSessionManagerStatics>([&](IMdmSessionManagerStatics const& f) { return f.GetSessionById(sessionId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Management::IMdmAlert> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::IMdmSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::IMdmSessionManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::MdmAlert> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::MdmSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::MdmSessionManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
