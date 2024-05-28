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
#ifndef LLM_OS_ApplicationModel_CommunicationBlocking_H
#define LLM_OS_ApplicationModel_CommunicationBlocking_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.ApplicationModel.CommunicationBlocking.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::IsBlockingActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->get_IsBlockingActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::IsBlockedNumberAsync(param::hstring const& number) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->IsBlockedNumberAsync(*(void**)(&number), &result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockNumbersUI(param::iterable<hstring> const& phoneNumbers) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->ShowBlockNumbersUI(*(void**)(&phoneNumbers), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::ShowUnblockNumbersUI(param::iterable<hstring> const& phoneNumbers) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->ShowUnblockNumbersUI(*(void**)(&phoneNumbers), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockedCallsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->ShowBlockedCallsUI());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAccessManagerStatics<D>::ShowBlockedMessagesUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics)->ShowBlockedMessagesUI());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics<D>::IsCurrentAppActiveBlockingApp() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics)->get_IsCurrentAppActiveBlockingApp(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics<D>::ShowCommunicationBlockingSettingsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics)->ShowCommunicationBlockingSettingsUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_CommunicationBlocking_ICommunicationBlockingAppManagerStatics2<D>::RequestSetAsActiveBlockingAppAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2)->RequestSetAsActiveBlockingAppAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> : produce_base<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
    {
        int32_t __stdcall get_IsBlockingActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBlockingActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsBlockedNumberAsync(void* number, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsBlockedNumberAsync(*reinterpret_cast<hstring const*>(&number)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowBlockNumbersUI(void* phoneNumbers, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowBlockNumbersUI(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&phoneNumbers)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowUnblockNumbersUI(void* phoneNumbers, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowUnblockNumbersUI(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&phoneNumbers)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowBlockedCallsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowBlockedCallsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowBlockedMessagesUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowBlockedMessagesUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> : produce_base<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
    {
        int32_t __stdcall get_IsCurrentAppActiveBlockingApp(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCurrentAppActiveBlockingApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowCommunicationBlockingSettingsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowCommunicationBlockingSettingsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> : produce_base<D, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
    {
        int32_t __stdcall RequestSetAsActiveBlockingAppAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestSetAsActiveBlockingAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::CommunicationBlocking
{
    inline auto CommunicationBlockingAccessManager::IsBlockingActive()
    {
        return impl::call_factory_cast<bool(*)(ICommunicationBlockingAccessManagerStatics const&), CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([](ICommunicationBlockingAccessManagerStatics const& f) { return f.IsBlockingActive(); });
    }
    inline auto CommunicationBlockingAccessManager::IsBlockedNumberAsync(param::hstring const& number)
    {
        return impl::call_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([&](ICommunicationBlockingAccessManagerStatics const& f) { return f.IsBlockedNumberAsync(number); });
    }
    inline auto CommunicationBlockingAccessManager::ShowBlockNumbersUI(param::iterable<hstring> const& phoneNumbers)
    {
        return impl::call_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([&](ICommunicationBlockingAccessManagerStatics const& f) { return f.ShowBlockNumbersUI(phoneNumbers); });
    }
    inline auto CommunicationBlockingAccessManager::ShowUnblockNumbersUI(param::iterable<hstring> const& phoneNumbers)
    {
        return impl::call_factory<CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([&](ICommunicationBlockingAccessManagerStatics const& f) { return f.ShowUnblockNumbersUI(phoneNumbers); });
    }
    inline auto CommunicationBlockingAccessManager::ShowBlockedCallsUI()
    {
        impl::call_factory_cast<void(*)(ICommunicationBlockingAccessManagerStatics const&), CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([](ICommunicationBlockingAccessManagerStatics const& f) { return f.ShowBlockedCallsUI(); });
    }
    inline auto CommunicationBlockingAccessManager::ShowBlockedMessagesUI()
    {
        impl::call_factory_cast<void(*)(ICommunicationBlockingAccessManagerStatics const&), CommunicationBlockingAccessManager, ICommunicationBlockingAccessManagerStatics>([](ICommunicationBlockingAccessManagerStatics const& f) { return f.ShowBlockedMessagesUI(); });
    }
    inline auto CommunicationBlockingAppManager::IsCurrentAppActiveBlockingApp()
    {
        return impl::call_factory_cast<bool(*)(ICommunicationBlockingAppManagerStatics const&), CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>([](ICommunicationBlockingAppManagerStatics const& f) { return f.IsCurrentAppActiveBlockingApp(); });
    }
    inline auto CommunicationBlockingAppManager::ShowCommunicationBlockingSettingsUI()
    {
        impl::call_factory_cast<void(*)(ICommunicationBlockingAppManagerStatics const&), CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics>([](ICommunicationBlockingAppManagerStatics const& f) { return f.ShowCommunicationBlockingSettingsUI(); });
    }
    inline auto CommunicationBlockingAppManager::RequestSetAsActiveBlockingAppAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<bool>(*)(ICommunicationBlockingAppManagerStatics2 const&), CommunicationBlockingAppManager, ICommunicationBlockingAppManagerStatics2>([](ICommunicationBlockingAppManagerStatics2 const& f) { return f.RequestSetAsActiveBlockingAppAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
