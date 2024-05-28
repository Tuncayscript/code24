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
#ifndef LLM_OS_Management_Deployment_Preview_H
#define LLM_OS_Management_Deployment_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Management.Deployment.h"
#include "llm/impl/Windows.Management.Deployment.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Deployment::Preview::InstalledClassicAppInfo) consume_Windows_Management_Deployment_Preview_IClassicAppManagerStatics<D>::FindInstalledApp(param::hstring const& appUninstallKey) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Deployment::Preview::IClassicAppManagerStatics)->FindInstalledApp(*(void**)(&appUninstallKey), &result));
        return llm::OS::Management::Deployment::Preview::InstalledClassicAppInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Deployment_Preview_IInstalledClassicAppInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Deployment::Preview::IInstalledClassicAppInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Deployment_Preview_IInstalledClassicAppInfo<D>::DisplayVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Deployment::Preview::IInstalledClassicAppInfo)->get_DisplayVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Deployment::Preview::IClassicAppManagerStatics> : produce_base<D, llm::OS::Management::Deployment::Preview::IClassicAppManagerStatics>
    {
        int32_t __stdcall FindInstalledApp(void* appUninstallKey, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::Deployment::Preview::InstalledClassicAppInfo>(this->shim().FindInstalledApp(*reinterpret_cast<hstring const*>(&appUninstallKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Deployment::Preview::IInstalledClassicAppInfo> : produce_base<D, llm::OS::Management::Deployment::Preview::IInstalledClassicAppInfo>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayVersion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Management::Deployment::Preview
{
    inline auto ClassicAppManager::FindInstalledApp(param::hstring const& appUninstallKey)
    {
        return impl::call_factory<ClassicAppManager, IClassicAppManagerStatics>([&](IClassicAppManagerStatics const& f) { return f.FindInstalledApp(appUninstallKey); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Management::Deployment::Preview::IClassicAppManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Deployment::Preview::IInstalledClassicAppInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Deployment::Preview::ClassicAppManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Deployment::Preview::InstalledClassicAppInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
