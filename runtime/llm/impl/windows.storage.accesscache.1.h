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
#ifndef LLM_OS_Storage_AccessCache_1_H
#define LLM_OS_Storage_AccessCache_1_H
#include "llm/impl/Windows.Storage.AccessCache.0.h"
LLM_EXPORT namespace llm:OS::Storage::AccessCache
{
    struct __declspec(empty_bases) IItemRemovedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IItemRemovedEventArgs>
    {
        IItemRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IItemRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageApplicationPermissionsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageApplicationPermissionsStatics>
    {
        IStorageApplicationPermissionsStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageApplicationPermissionsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageApplicationPermissionsStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageApplicationPermissionsStatics2>
    {
        IStorageApplicationPermissionsStatics2(std::nullptr_t = nullptr) noexcept {}
        IStorageApplicationPermissionsStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemAccessList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemAccessList>
    {
        IStorageItemAccessList(std::nullptr_t = nullptr) noexcept {}
        IStorageItemAccessList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemMostRecentlyUsedList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemMostRecentlyUsedList>,
        impl::require<llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList, llm:OS::Storage::AccessCache::IStorageItemAccessList>
    {
        IStorageItemMostRecentlyUsedList(std::nullptr_t = nullptr) noexcept {}
        IStorageItemMostRecentlyUsedList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemMostRecentlyUsedList2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemMostRecentlyUsedList2>,
        impl::require<llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList2, llm:OS::Storage::AccessCache::IStorageItemAccessList, llm:OS::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
    {
        IStorageItemMostRecentlyUsedList2(std::nullptr_t = nullptr) noexcept {}
        IStorageItemMostRecentlyUsedList2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IStorageItemMostRecentlyUsedList2, IStorageItemMostRecentlyUsedList2>::Add;
        using impl::consume_t<IStorageItemMostRecentlyUsedList2, llm:OS::Storage::AccessCache::IStorageItemAccessList>::Add;
        using impl::consume_t<IStorageItemMostRecentlyUsedList2, IStorageItemMostRecentlyUsedList2>::AddOrReplace;
        using impl::consume_t<IStorageItemMostRecentlyUsedList2, llm:OS::Storage::AccessCache::IStorageItemAccessList>::AddOrReplace;
    };
}
#endif
