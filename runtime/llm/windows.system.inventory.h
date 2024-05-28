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
#ifndef LLM_OS_System_Inventory_H
#define LLM_OS_System_Inventory_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.Inventory.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Inventory_IInstalledDesktopApp<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Inventory::IInstalledDesktopApp)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Inventory_IInstalledDesktopApp<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Inventory::IInstalledDesktopApp)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Inventory_IInstalledDesktopApp<D>::Publisher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Inventory::IInstalledDesktopApp)->get_Publisher(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Inventory_IInstalledDesktopApp<D>::DisplayVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Inventory::IInstalledDesktopApp)->get_DisplayVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Inventory::InstalledDesktopApp>>) consume_Windows_System_Inventory_IInstalledDesktopAppStatics<D>::GetInventoryAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Inventory::IInstalledDesktopAppStatics)->GetInventoryAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Inventory::InstalledDesktopApp>>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Inventory::IInstalledDesktopApp> : produce_base<D, llm::OS::System::Inventory::IInstalledDesktopApp>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Publisher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Publisher());
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
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Inventory::IInstalledDesktopAppStatics> : produce_base<D, llm::OS::System::Inventory::IInstalledDesktopAppStatics>
    {
        int32_t __stdcall GetInventoryAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Inventory::InstalledDesktopApp>>>(this->shim().GetInventoryAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Inventory
{
    inline auto InstalledDesktopApp::GetInventoryAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::Inventory::InstalledDesktopApp>>(*)(IInstalledDesktopAppStatics const&), InstalledDesktopApp, IInstalledDesktopAppStatics>([](IInstalledDesktopAppStatics const& f) { return f.GetInventoryAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Inventory::IInstalledDesktopApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Inventory::IInstalledDesktopAppStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Inventory::InstalledDesktopApp> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
    template<> struct formatter<llm::OS::System::Inventory::InstalledDesktopApp, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
#endif
}
#endif
