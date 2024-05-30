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
#ifndef LLM_OS_Storage_FileProperties_1_H
#define LLM_OS_Storage_FileProperties_1_H
#include "llm/impl/Windows.Storage.FileProperties.0.h"
LLM_EXPORT namespace llm:OS::Storage::FileProperties
{
    struct __declspec(empty_bases) IBasicProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBasicProperties>
    {
        IBasicProperties(std::nullptr_t = nullptr) noexcept {}
        IBasicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDocumentProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDocumentProperties>,
        impl::require<llm:OS::Storage::FileProperties::IDocumentProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        IDocumentProperties(std::nullptr_t = nullptr) noexcept {}
        IDocumentProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGeotagHelperStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGeotagHelperStatics>
    {
        IGeotagHelperStatics(std::nullptr_t = nullptr) noexcept {}
        IGeotagHelperStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IImageProperties>,
        impl::require<llm:OS::Storage::FileProperties::IImageProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        IImageProperties(std::nullptr_t = nullptr) noexcept {}
        IImageProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMusicProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMusicProperties>,
        impl::require<llm:OS::Storage::FileProperties::IMusicProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        IMusicProperties(std::nullptr_t = nullptr) noexcept {}
        IMusicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemContentProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemContentProperties>,
        impl::require<llm:OS::Storage::FileProperties::IStorageItemContentProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        IStorageItemContentProperties(std::nullptr_t = nullptr) noexcept {}
        IStorageItemContentProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemExtraProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemExtraProperties>
    {
        IStorageItemExtraProperties(std::nullptr_t = nullptr) noexcept {}
        IStorageItemExtraProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IThumbnailProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IThumbnailProperties>
    {
        IThumbnailProperties(std::nullptr_t = nullptr) noexcept {}
        IThumbnailProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoProperties>,
        impl::require<llm:OS::Storage::FileProperties::IVideoProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        IVideoProperties(std::nullptr_t = nullptr) noexcept {}
        IVideoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
