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
#ifndef LLM_OS_Management_Workplace_H
#define LLM_OS_Management_Workplace_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Management.h"
#include "llm/impl/Windows.Management.Workplace.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Workplace_IMdmAllowPolicyStatics<D>::IsBrowserAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IMdmAllowPolicyStatics)->IsBrowserAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Workplace_IMdmAllowPolicyStatics<D>::IsCameraAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IMdmAllowPolicyStatics)->IsCameraAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Workplace_IMdmAllowPolicyStatics<D>::IsMicrosoftAccountAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IMdmAllowPolicyStatics)->IsMicrosoftAccountAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Workplace_IMdmAllowPolicyStatics<D>::IsStoreAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IMdmAllowPolicyStatics)->IsStoreAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Workplace::MessagingSyncPolicy) consume_Windows_Management_Workplace_IMdmPolicyStatics2<D>::GetMessagingSyncPolicy() const
    {
        llm::OS::Management::Workplace::MessagingSyncPolicy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IMdmPolicyStatics2)->GetMessagingSyncPolicy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Workplace_IWorkplaceSettingsStatics<D>::IsMicrosoftAccountOptional() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Workplace::IWorkplaceSettingsStatics)->get_IsMicrosoftAccountOptional(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Workplace::IMdmAllowPolicyStatics> : produce_base<D, llm::OS::Management::Workplace::IMdmAllowPolicyStatics>
    {
        int32_t __stdcall IsBrowserAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBrowserAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCameraAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCameraAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsMicrosoftAccountAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMicrosoftAccountAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsStoreAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStoreAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Workplace::IMdmPolicyStatics2> : produce_base<D, llm::OS::Management::Workplace::IMdmPolicyStatics2>
    {
        int32_t __stdcall GetMessagingSyncPolicy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Workplace::MessagingSyncPolicy>(this->shim().GetMessagingSyncPolicy());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Workplace::IWorkplaceSettingsStatics> : produce_base<D, llm::OS::Management::Workplace::IWorkplaceSettingsStatics>
    {
        int32_t __stdcall get_IsMicrosoftAccountOptional(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMicrosoftAccountOptional());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Management::Workplace
{
    inline auto MdmPolicy::IsBrowserAllowed()
    {
        return impl::call_factory_cast<bool(*)(IMdmAllowPolicyStatics const&), MdmPolicy, IMdmAllowPolicyStatics>([](IMdmAllowPolicyStatics const& f) { return f.IsBrowserAllowed(); });
    }
    inline auto MdmPolicy::IsCameraAllowed()
    {
        return impl::call_factory_cast<bool(*)(IMdmAllowPolicyStatics const&), MdmPolicy, IMdmAllowPolicyStatics>([](IMdmAllowPolicyStatics const& f) { return f.IsCameraAllowed(); });
    }
    inline auto MdmPolicy::IsMicrosoftAccountAllowed()
    {
        return impl::call_factory_cast<bool(*)(IMdmAllowPolicyStatics const&), MdmPolicy, IMdmAllowPolicyStatics>([](IMdmAllowPolicyStatics const& f) { return f.IsMicrosoftAccountAllowed(); });
    }
    inline auto MdmPolicy::IsStoreAllowed()
    {
        return impl::call_factory_cast<bool(*)(IMdmAllowPolicyStatics const&), MdmPolicy, IMdmAllowPolicyStatics>([](IMdmAllowPolicyStatics const& f) { return f.IsStoreAllowed(); });
    }
    inline auto MdmPolicy::GetMessagingSyncPolicy()
    {
        return impl::call_factory_cast<llm::OS::Management::Workplace::MessagingSyncPolicy(*)(IMdmPolicyStatics2 const&), MdmPolicy, IMdmPolicyStatics2>([](IMdmPolicyStatics2 const& f) { return f.GetMessagingSyncPolicy(); });
    }
    inline auto WorkplaceSettings::IsMicrosoftAccountOptional()
    {
        return impl::call_factory_cast<bool(*)(IWorkplaceSettingsStatics const&), WorkplaceSettings, IWorkplaceSettingsStatics>([](IWorkplaceSettingsStatics const& f) { return f.IsMicrosoftAccountOptional(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Management::Workplace::IMdmAllowPolicyStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Workplace::IMdmPolicyStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Workplace::IWorkplaceSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Workplace::MdmPolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Workplace::WorkplaceSettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
