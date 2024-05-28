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
#ifndef LLM_OS_Security_Cryptography_DataProtection_H
#define LLM_OS_Security_Cryptography_DataProtection_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Security.Cryptography.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Security.Cryptography.DataProtection.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider<D>::ProtectAsync(llm::OS::Storage::Streams::IBuffer const& data) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider)->ProtectAsync(*(void**)(&data), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider<D>::UnprotectAsync(llm::OS::Storage::Streams::IBuffer const& data) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider)->UnprotectAsync(*(void**)(&data), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider<D>::ProtectStreamAsync(llm::OS::Storage::Streams::IInputStream const& src, llm::OS::Storage::Streams::IOutputStream const& dest) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider)->ProtectStreamAsync(*(void**)(&src), *(void**)(&dest), &value));
        return llm::OS::Foundation::IAsyncAction{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProvider<D>::UnprotectStreamAsync(llm::OS::Storage::Streams::IInputStream const& src, llm::OS::Storage::Streams::IOutputStream const& dest) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider)->UnprotectStreamAsync(*(void**)(&src), *(void**)(&dest), &value));
        return llm::OS::Foundation::IAsyncAction{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Cryptography::DataProtection::DataProtectionProvider) consume_Windows_Security_Cryptography_DataProtection_IDataProtectionProviderFactory<D>::CreateOverloadExplicit(param::hstring const& protectionDescriptor) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory)->CreateOverloadExplicit(*(void**)(&protectionDescriptor), &value));
        return llm::OS::Security::Cryptography::DataProtection::DataProtectionProvider{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider> : produce_base<D, llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider>
    {
        int32_t __stdcall ProtectAsync(void* data, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>>(this->shim().ProtectAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprotectAsync(void* data, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>>(this->shim().UnprotectAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProtectStreamAsync(void* src, void* dest, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ProtectStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&src), *reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&dest)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprotectStreamAsync(void* src, void* dest, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnprotectStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&src), *reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&dest)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory> : produce_base<D, llm::OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory>
    {
        int32_t __stdcall CreateOverloadExplicit(void* protectionDescriptor, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Cryptography::DataProtection::DataProtectionProvider>(this->shim().CreateOverloadExplicit(*reinterpret_cast<hstring const*>(&protectionDescriptor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Cryptography::DataProtection
{
    inline DataProtectionProvider::DataProtectionProvider() :
        DataProtectionProvider(impl::call_factory_cast<DataProtectionProvider(*)(llm::OS::Foundation::IActivationFactory const&), DataProtectionProvider>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DataProtectionProvider>(); }))
    {
    }
    inline DataProtectionProvider::DataProtectionProvider(param::hstring const& protectionDescriptor) :
        DataProtectionProvider(impl::call_factory<DataProtectionProvider, IDataProtectionProviderFactory>([&](IDataProtectionProviderFactory const& f) { return f.CreateOverloadExplicit(protectionDescriptor); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Cryptography::DataProtection::IDataProtectionProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Cryptography::DataProtection::IDataProtectionProviderFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Cryptography::DataProtection::DataProtectionProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
