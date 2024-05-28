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
#ifndef LLM_OS_UI_UIAutomation_H
#define LLM_OS_UI_UIAutomation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.UI.UIAutomation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_IAutomationConnection<D>::IsRemoteSystem() const noexcept
    {
        bool value{};
        LLM_VERIFY_(0, LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationConnection)->get_IsRemoteSystem(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_IAutomationConnection<D>::AppUserModelId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationConnection)->get_AppUserModelId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_IAutomationConnection<D>::ExecutableFileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationConnection)->get_ExecutableFileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIAutomation::AutomationConnection) consume_Windows_UI_UIAutomation_IAutomationConnectionBoundObject<D>::Connection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationConnectionBoundObject)->get_Connection(&value));
        return llm::OS::UI::UIAutomation::AutomationConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_UIAutomation_IAutomationElement<D>::IsRemoteSystem() const noexcept
    {
        bool value{};
        LLM_VERIFY_(0, LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationElement)->get_IsRemoteSystem(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_IAutomationElement<D>::AppUserModelId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationElement)->get_AppUserModelId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_UIAutomation_IAutomationElement<D>::ExecutableFileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::UIAutomation::IAutomationElement)->get_ExecutableFileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::IAutomationConnection> : produce_base<D, llm::OS::UI::UIAutomation::IAutomationConnection>
    {
        int32_t __stdcall get_IsRemoteSystem(bool* value) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRemoteSystem());
            return 0;
        }
        int32_t __stdcall get_AppUserModelId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppUserModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExecutableFileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExecutableFileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::IAutomationConnectionBoundObject> : produce_base<D, llm::OS::UI::UIAutomation::IAutomationConnectionBoundObject>
    {
        int32_t __stdcall get_Connection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIAutomation::AutomationConnection>(this->shim().Connection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::IAutomationElement> : produce_base<D, llm::OS::UI::UIAutomation::IAutomationElement>
    {
        int32_t __stdcall get_IsRemoteSystem(bool* value) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRemoteSystem());
            return 0;
        }
        int32_t __stdcall get_AppUserModelId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppUserModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExecutableFileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExecutableFileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::UIAutomation::IAutomationTextRange> : produce_base<D, llm::OS::UI::UIAutomation::IAutomationTextRange>
    {
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::UIAutomation
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::UIAutomation::IAutomationConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::IAutomationConnectionBoundObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::IAutomationElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::IAutomationTextRange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::AutomationConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::AutomationConnectionBoundObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::AutomationElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::UIAutomation::AutomationTextRange> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
