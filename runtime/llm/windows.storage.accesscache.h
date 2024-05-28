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
#ifndef LLM_OS_Storage_AccessCache_H
#define LLM_OS_Storage_AccessCache_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Storage.AccessCache.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::AccessListEntry) consume_Windows_Storage_AccessCache_IItemRemovedEventArgs<D>::RemovedEntry() const
    {
        llm::OS::Storage::AccessCache::AccessListEntry value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IItemRemovedEventArgs)->get_RemovedEntry(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::StorageItemAccessList) consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics<D>::FutureAccessList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics)->get_FutureAccessList(&value));
        return llm::OS::Storage::AccessCache::StorageItemAccessList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList) consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics<D>::MostRecentlyUsedList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics)->get_MostRecentlyUsedList(&value));
        return llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::StorageItemAccessList) consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics2<D>::GetFutureAccessListForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics2)->GetFutureAccessListForUser(*(void**)(&user), &value));
        return llm::OS::Storage::AccessCache::StorageItemAccessList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList) consume_Windows_Storage_AccessCache_IStorageApplicationPermissionsStatics2<D>::GetMostRecentlyUsedListForUser(llm::OS::System::User const& user) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics2)->GetMostRecentlyUsedListForUser(*(void**)(&user), &value));
        return llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Add(llm::OS::Storage::IStorageItem const& file) const
    {
        void* token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->AddOverloadDefaultMetadata(*(void**)(&file), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Add(llm::OS::Storage::IStorageItem const& file, param::hstring const& metadata) const
    {
        void* token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->Add(*(void**)(&file), *(void**)(&metadata), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::AddOrReplace(param::hstring const& token, llm::OS::Storage::IStorageItem const& file) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->AddOrReplaceOverloadDefaultMetadata(*(void**)(&token), *(void**)(&file)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::AddOrReplace(param::hstring const& token, llm::OS::Storage::IStorageItem const& file, param::hstring const& metadata) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->AddOrReplace(*(void**)(&token), *(void**)(&file), *(void**)(&metadata)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetItemAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetItemAsync(*(void**)(&token), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFileAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetFileAsync(*(void**)(&token), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFolderAsync(param::hstring const& token) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetFolderAsync(*(void**)(&token), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetItemAsync(param::hstring const& token, llm::OS::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetItemWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFileAsync(param::hstring const& token, llm::OS::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetFileWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::GetFolderAsync(param::hstring const& token, llm::OS::Storage::AccessCache::AccessCacheOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->GetFolderWithOptionsAsync(*(void**)(&token), static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Remove(param::hstring const& token) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->Remove(*(void**)(&token)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::ContainsItem(param::hstring const& token) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->ContainsItem(*(void**)(&token), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Clear() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->Clear());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::CheckAccess(llm::OS::Storage::IStorageItem const& file) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->CheckAccess(*(void**)(&file), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::AccessCache::AccessListEntryView) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::Entries() const
    {
        void* entries{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->get_Entries(&entries));
        return llm::OS::Storage::AccessCache::AccessListEntryView{ entries, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Storage_AccessCache_IStorageItemAccessList<D>::MaximumItemsAllowed() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemAccessList)->get_MaximumItemsAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList, llm::OS::Storage::AccessCache::ItemRemovedEventArgs> const& handler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList)->add_ItemRemoved(*(void**)(&handler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved_revoker consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList, llm::OS::Storage::AccessCache::ItemRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ItemRemoved_revoker>(this, ItemRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList)->remove_ItemRemoved(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList2<D>::Add(llm::OS::Storage::IStorageItem const& file, param::hstring const& metadata, llm::OS::Storage::AccessCache::RecentStorageItemVisibility const& visibility) const
    {
        void* token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2)->AddWithMetadataAndVisibility(*(void**)(&file), *(void**)(&metadata), static_cast<int32_t>(visibility), &token));
        return hstring{ token, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_AccessCache_IStorageItemMostRecentlyUsedList2<D>::AddOrReplace(param::hstring const& token, llm::OS::Storage::IStorageItem const& file, param::hstring const& metadata, llm::OS::Storage::AccessCache::RecentStorageItemVisibility const& visibility) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2)->AddOrReplaceWithMetadataAndVisibility(*(void**)(&token), *(void**)(&file), *(void**)(&metadata), static_cast<int32_t>(visibility)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IItemRemovedEventArgs> : produce_base<D, llm::OS::Storage::AccessCache::IItemRemovedEventArgs>
    {
        int32_t __stdcall get_RemovedEntry(struct struct_Windows_Storage_AccessCache_AccessListEntry* value) noexcept final try
        {
            zero_abi<llm::OS::Storage::AccessCache::AccessListEntry>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::AccessCache::AccessListEntry>(this->shim().RemovedEntry());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics> : produce_base<D, llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics>
    {
        int32_t __stdcall get_FutureAccessList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::AccessCache::StorageItemAccessList>(this->shim().FutureAccessList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MostRecentlyUsedList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList>(this->shim().MostRecentlyUsedList());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics2> : produce_base<D, llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics2>
    {
        int32_t __stdcall GetFutureAccessListForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::AccessCache::StorageItemAccessList>(this->shim().GetFutureAccessListForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMostRecentlyUsedListForUser(void* user, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList>(this->shim().GetMostRecentlyUsedListForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IStorageItemAccessList> : produce_base<D, llm::OS::Storage::AccessCache::IStorageItemAccessList>
    {
        int32_t __stdcall AddOverloadDefaultMetadata(void* file, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Add(void* file, void* metadata, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplaceOverloadDefaultMetadata(void* token, void* file) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplace(void* token, void* file, void* metadata) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>>(this->shim().GetItemAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFileAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().GetFileAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFolderAsync(void* token, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>>(this->shim().GetFolderAsync(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::IStorageItem>>(this->shim().GetItemAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFileWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFile>>(this->shim().GetFileAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFolderWithOptionsAsync(void* token, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>>(this->shim().GetFolderAsync(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::AccessCache::AccessCacheOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* token) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<hstring const*>(&token));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ContainsItem(void* token, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ContainsItem(*reinterpret_cast<hstring const*>(&token)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clear() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CheckAccess(void* file, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CheckAccess(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Entries(void** entries) noexcept final try
        {
            clear_abi(entries);
            typename D::abi_guard guard(this->shim());
            *entries = detach_from<llm::OS::Storage::AccessCache::AccessListEntryView>(this->shim().Entries());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaximumItemsAllowed(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaximumItemsAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : produce_base<D, llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
    {
        int32_t __stdcall add_ItemRemoved(void* handler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().ItemRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList, llm::OS::Storage::AccessCache::ItemRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ItemRemoved(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemRemoved(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : produce_base<D, llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
    {
        int32_t __stdcall AddWithMetadataAndVisibility(void* file, void* metadata, int32_t visibility, void** token) noexcept final try
        {
            clear_abi(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<hstring>(this->shim().Add(*reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata), *reinterpret_cast<llm::OS::Storage::AccessCache::RecentStorageItemVisibility const*>(&visibility)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddOrReplaceWithMetadataAndVisibility(void* token, void* file, void* metadata, int32_t visibility) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<hstring const*>(&token), *reinterpret_cast<llm::OS::Storage::IStorageItem const*>(&file), *reinterpret_cast<hstring const*>(&metadata), *reinterpret_cast<llm::OS::Storage::AccessCache::RecentStorageItemVisibility const*>(&visibility));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::AccessCache
{
    constexpr auto operator|(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(AccessCacheOptions const value) noexcept
    {
        return static_cast<AccessCacheOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(AccessCacheOptions const left, AccessCacheOptions const right) noexcept
    {
        return static_cast<AccessCacheOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(AccessCacheOptions& left, AccessCacheOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto StorageApplicationPermissions::FutureAccessList()
    {
        return impl::call_factory_cast<llm::OS::Storage::AccessCache::StorageItemAccessList(*)(IStorageApplicationPermissionsStatics const&), StorageApplicationPermissions, IStorageApplicationPermissionsStatics>([](IStorageApplicationPermissionsStatics const& f) { return f.FutureAccessList(); });
    }
    inline auto StorageApplicationPermissions::MostRecentlyUsedList()
    {
        return impl::call_factory_cast<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList(*)(IStorageApplicationPermissionsStatics const&), StorageApplicationPermissions, IStorageApplicationPermissionsStatics>([](IStorageApplicationPermissionsStatics const& f) { return f.MostRecentlyUsedList(); });
    }
    inline auto StorageApplicationPermissions::GetFutureAccessListForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics2>([&](IStorageApplicationPermissionsStatics2 const& f) { return f.GetFutureAccessListForUser(user); });
    }
    inline auto StorageApplicationPermissions::GetMostRecentlyUsedListForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics2>([&](IStorageApplicationPermissionsStatics2 const& f) { return f.GetMostRecentlyUsedListForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::AccessCache::IItemRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::IStorageApplicationPermissionsStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::IStorageItemAccessList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::AccessListEntryView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::ItemRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::StorageApplicationPermissions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::StorageItemAccessList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::AccessCache::StorageItemMostRecentlyUsedList> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
