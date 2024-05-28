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
#ifndef LLM_OS_Security_DataProtection_H
#define LLM_OS_Security_DataProtection_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Security.DataProtection.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Security_DataProtection_IUserDataAvailabilityStateChangedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::DataProtection::UserDataBufferUnprotectStatus) consume_Windows_Security_DataProtection_IUserDataBufferUnprotectResult<D>::Status() const
    {
        llm::OS::Security::DataProtection::UserDataBufferUnprotectStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataBufferUnprotectResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Security_DataProtection_IUserDataBufferUnprotectResult<D>::UnprotectedBuffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataBufferUnprotectResult)->get_UnprotectedBuffer(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionStatus>) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::ProtectStorageItemAsync(llm::OS::Storage::IStorageItem const& storageItem, llm::OS::Security::DataProtection::UserDataAvailability const& availability) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->ProtectStorageItemAsync(*(void**)(&storageItem), static_cast<int32_t>(availability), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionInfo>) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::GetStorageItemProtectionInfoAsync(llm::OS::Storage::IStorageItem const& storageItem) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->GetStorageItemProtectionInfoAsync(*(void**)(&storageItem), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::ProtectBufferAsync(llm::OS::Storage::Streams::IBuffer const& unprotectedBuffer, llm::OS::Security::DataProtection::UserDataAvailability const& availability) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->ProtectBufferAsync(*(void**)(&unprotectedBuffer), static_cast<int32_t>(availability), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataBufferUnprotectResult>) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::UnprotectBufferAsync(llm::OS::Storage::Streams::IBuffer const& protectedBuffer) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->UnprotectBufferAsync(*(void**)(&protectedBuffer), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataBufferUnprotectResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::IsContinuedDataAvailabilityExpected(llm::OS::Security::DataProtection::UserDataAvailability const& availability) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->IsContinuedDataAvailabilityExpected(static_cast<int32_t>(availability), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::DataAvailabilityStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Security::DataProtection::UserDataProtectionManager, llm::OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->add_DataAvailabilityStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::DataAvailabilityStateChanged_revoker consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::DataAvailabilityStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Security::DataProtection::UserDataProtectionManager, llm::OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DataAvailabilityStateChanged_revoker>(this, DataAvailabilityStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_DataProtection_IUserDataProtectionManager<D>::DataAvailabilityStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManager)->remove_DataAvailabilityStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::DataProtection::UserDataProtectionManager) consume_Windows_Security_DataProtection_IUserDataProtectionManagerStatics<D>::TryGetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManagerStatics)->TryGetDefault(&result));
        return llm::OS::Security::DataProtection::UserDataProtectionManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::DataProtection::UserDataProtectionManager) consume_Windows_Security_DataProtection_IUserDataProtectionManagerStatics<D>::TryGetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataProtectionManagerStatics)->TryGetForUser(*(void**)(&user), &result));
        return llm::OS::Security::DataProtection::UserDataProtectionManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::DataProtection::UserDataAvailability) consume_Windows_Security_DataProtection_IUserDataStorageItemProtectionInfo<D>::Availability() const
    {
        llm::OS::Security::DataProtection::UserDataAvailability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::DataProtection::IUserDataStorageItemProtectionInfo)->get_Availability(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs> : produce_base<D, llm::OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs>
    {
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::DataProtection::IUserDataBufferUnprotectResult> : produce_base<D, llm::OS::Security::DataProtection::IUserDataBufferUnprotectResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::DataProtection::UserDataBufferUnprotectStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnprotectedBuffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().UnprotectedBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::DataProtection::IUserDataProtectionManager> : produce_base<D, llm::OS::Security::DataProtection::IUserDataProtectionManager>
    {
        int32_t __stdcall ProtectStorageItemAsync(void* storageItem, int32_t availability, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionStatus>>(this->shim().ProtectStorageItemAsync(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&storageItem), *reinterpret_cast<llm::OS::Security::DataProtection::UserDataAvailability const*>(&availability)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStorageItemProtectionInfoAsync(void* storageItem, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataStorageItemProtectionInfo>>(this->shim().GetStorageItemProtectionInfoAsync(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&storageItem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProtectBufferAsync(void* unprotectedBuffer, int32_t availability, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>>(this->shim().ProtectBufferAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&unprotectedBuffer), *reinterpret_cast<llm::OS::Security::DataProtection::UserDataAvailability const*>(&availability)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprotectBufferAsync(void* protectedBuffer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::DataProtection::UserDataBufferUnprotectResult>>(this->shim().UnprotectBufferAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&protectedBuffer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsContinuedDataAvailabilityExpected(int32_t availability, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsContinuedDataAvailabilityExpected(*reinterpret_cast<llm::OS::Security::DataProtection::UserDataAvailability const*>(&availability)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DataAvailabilityStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DataAvailabilityStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Security::DataProtection::UserDataProtectionManager, llm::OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DataAvailabilityStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataAvailabilityStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::DataProtection::IUserDataProtectionManagerStatics> : produce_base<D, llm::OS::Security::DataProtection::IUserDataProtectionManagerStatics>
    {
        int32_t __stdcall TryGetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::DataProtection::UserDataProtectionManager>(this->shim().TryGetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::DataProtection::UserDataProtectionManager>(this->shim().TryGetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::DataProtection::IUserDataStorageItemProtectionInfo> : produce_base<D, llm::OS::Security::DataProtection::IUserDataStorageItemProtectionInfo>
    {
        int32_t __stdcall get_Availability(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::DataProtection::UserDataAvailability>(this->shim().Availability());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::DataProtection
{
    inline auto UserDataProtectionManager::TryGetDefault()
    {
        return impl::call_factory_cast<llm::OS::Security::DataProtection::UserDataProtectionManager(*)(IUserDataProtectionManagerStatics const&), UserDataProtectionManager, IUserDataProtectionManagerStatics>([](IUserDataProtectionManagerStatics const& f) { return f.TryGetDefault(); });
    }
    inline auto UserDataProtectionManager::TryGetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<UserDataProtectionManager, IUserDataProtectionManagerStatics>([&](IUserDataProtectionManagerStatics const& f) { return f.TryGetForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::DataProtection::IUserDataAvailabilityStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::IUserDataBufferUnprotectResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::IUserDataProtectionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::IUserDataProtectionManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::IUserDataStorageItemProtectionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::UserDataAvailabilityStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::UserDataBufferUnprotectResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::UserDataProtectionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::DataProtection::UserDataStorageItemProtectionInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
