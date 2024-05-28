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
#ifndef LLM_OS_ApplicationModel_Wallet_System_H
#define LLM_OS_ApplicationModel_Wallet_System_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.Wallet.h"
#include "llm/impl/Windows.ApplicationModel.Wallet.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.Wallet.System.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>::GetItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore)->GetItemsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>::DeleteAsync(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore)->DeleteAsync(*(void**)(&item), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>::ImportItemAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& stream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore)->ImportItemAsync(*(void**)(&stream), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>::GetAppStatusForItem(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const
    {
        llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore)->GetAppStatusForItem(*(void**)(&item), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>::LaunchAppForItemAsync(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore)->LaunchAppForItemAsync(*(void**)(&item), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2<D>::ItemsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2)->add_ItemsChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2<D>::ItemsChanged_revoker consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2<D>::ItemsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ItemsChanged_revoker>(this, ItemsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2<D>::ItemsChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2)->remove_ItemsChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>) consume_Windows_ApplicationModel_Wallet_System_IWalletManagerSystemStatics<D>::RequestStoreAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics)->RequestStoreAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore> : produce_base<D, llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore>
    {
        int32_t __stdcall GetItemsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>>(this->shim().GetItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteAsync(void* item, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteAsync(*reinterpret_cast<llm::OS::ApplicationModel::Wallet::WalletItem const*>(&item)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ImportItemAsync(void* stream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>>(this->shim().ImportItemAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&stream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAppStatusForItem(void* item, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation>(this->shim().GetAppStatusForItem(*reinterpret_cast<llm::OS::ApplicationModel::Wallet::WalletItem const*>(&item)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LaunchAppForItemAsync(void* item, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().LaunchAppForItemAsync(*reinterpret_cast<llm::OS::ApplicationModel::Wallet::WalletItem const*>(&item)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2> : produce_base<D, llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
    {
        int32_t __stdcall add_ItemsChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().ItemsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemsChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemsChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> : produce_base<D, llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>
    {
        int32_t __stdcall RequestStoreAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>>(this->shim().RequestStoreAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet::System
{
    inline auto WalletManagerSystem::RequestStoreAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>(*)(IWalletManagerSystemStatics const&), WalletManagerSystem, IWalletManagerSystemStatics>([](IWalletManagerSystemStatics const& f) { return f.RequestStoreAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Wallet::System::WalletManagerSystem> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
