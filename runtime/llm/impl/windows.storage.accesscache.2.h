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
#ifndef LLM_OS_Storage_AccessCache_2_H
#define LLM_OS_Storage_AccessCache_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Storage.AccessCache.1.h"
LLM_EXPORT namespace llm:OS::Storage::AccessCache
{
    struct AccessListEntry
    {
        hstring Token;
        hstring Metadata;
    };
    inline bool operator==(AccessListEntry const& left, AccessListEntry const& right) noexcept
    {
        return left.Token == right.Token && left.Metadata == right.Metadata;
    }
    inline bool operator!=(AccessListEntry const& left, AccessListEntry const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AccessListEntryView : llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::AccessCache::AccessListEntry>
    {
        AccessListEntryView(std::nullptr_t) noexcept {}
        AccessListEntryView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::AccessCache::AccessListEntry>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ItemRemovedEventArgs : llm:OS::Storage::AccessCache::IItemRemovedEventArgs
    {
        ItemRemovedEventArgs(std::nullptr_t) noexcept {}
        ItemRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::AccessCache::IItemRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct StorageApplicationPermissions
    {
        StorageApplicationPermissions() = delete;
        [[nodiscard]] static auto FutureAccessList();
        [[nodiscard]] static auto MostRecentlyUsedList();
        static auto GetFutureAccessListForUser(llm:OS::System::User const& user);
        static auto GetMostRecentlyUsedListForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) StorageItemAccessList : llm:OS::Storage::AccessCache::IStorageItemAccessList
    {
        StorageItemAccessList(std::nullptr_t) noexcept {}
        StorageItemAccessList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::AccessCache::IStorageItemAccessList(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageItemMostRecentlyUsedList : llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList,
        impl::require<StorageItemMostRecentlyUsedList, llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
    {
        StorageItemMostRecentlyUsedList(std::nullptr_t) noexcept {}
        StorageItemMostRecentlyUsedList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList(ptr, take_ownership_from_abi) {}
        using llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList::Add;
        using impl::consume_t<StorageItemMostRecentlyUsedList, llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>::Add;
        using llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList::AddOrReplace;
        using impl::consume_t<StorageItemMostRecentlyUsedList, llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>::AddOrReplace;
    };
}
#endif
