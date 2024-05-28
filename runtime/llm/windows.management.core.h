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
#ifndef LLM_OS_Management_Core_H
#define LLM_OS_Management_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Management.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Management.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::ApplicationData) consume_Windows_Management_Core_IApplicationDataManagerStatics<D>::CreateForPackageFamily(param::hstring const& packageFamilyName) const
    {
        void* applicationData{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Core::IApplicationDataManagerStatics)->CreateForPackageFamily(*(void**)(&packageFamilyName), &applicationData));
        return llm::OS::Storage::ApplicationData{ applicationData, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Core::IApplicationDataManager> : produce_base<D, llm::OS::Management::Core::IApplicationDataManager>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Core::IApplicationDataManagerStatics> : produce_base<D, llm::OS::Management::Core::IApplicationDataManagerStatics>
    {
        int32_t __stdcall CreateForPackageFamily(void* packageFamilyName, void** applicationData) noexcept final try
        {
            clear_abi(applicationData);
            typename D::abi_guard guard(this->shim());
            *applicationData = detach_from<llm::OS::Storage::ApplicationData>(this->shim().CreateForPackageFamily(*reinterpret_cast<hstring const*>(&packageFamilyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Management::Core
{
    inline auto ApplicationDataManager::CreateForPackageFamily(param::hstring const& packageFamilyName)
    {
        return impl::call_factory<ApplicationDataManager, IApplicationDataManagerStatics>([&](IApplicationDataManagerStatics const& f) { return f.CreateForPackageFamily(packageFamilyName); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Management::Core::IApplicationDataManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Core::IApplicationDataManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Core::ApplicationDataManager> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
