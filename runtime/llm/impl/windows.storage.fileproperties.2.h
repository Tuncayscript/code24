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
#ifndef LLM_OS_Storage_FileProperties_2_H
#define LLM_OS_Storage_FileProperties_2_H
#include "llm/impl/Windows.Devices.Geolocation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Storage.FileProperties.1.h"
LLM_EXPORT namespace llm:OS::Storage::FileProperties
{
    struct __declspec(empty_bases) BasicProperties : llm:OS::Storage::FileProperties::IBasicProperties,
        impl::require<BasicProperties, llm:OS::Storage::FileProperties::IStorageItemExtraProperties>
    {
        BasicProperties(std::nullptr_t) noexcept {}
        BasicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IBasicProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DocumentProperties : llm:OS::Storage::FileProperties::IDocumentProperties
    {
        DocumentProperties(std::nullptr_t) noexcept {}
        DocumentProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IDocumentProperties(ptr, take_ownership_from_abi) {}
    };
    struct GeotagHelper
    {
        GeotagHelper() = delete;
        static auto GetGeotagAsync(llm:OS::Storage::IStorageFile const& file);
        static auto SetGeotagFromGeolocatorAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Devices::Geolocation::Geolocator const& geolocator);
        static auto SetGeotagAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Devices::Geolocation::Geopoint const& geopoint);
    };
    struct __declspec(empty_bases) ImageProperties : llm:OS::Storage::FileProperties::IImageProperties
    {
        ImageProperties(std::nullptr_t) noexcept {}
        ImageProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IImageProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MusicProperties : llm:OS::Storage::FileProperties::IMusicProperties
    {
        MusicProperties(std::nullptr_t) noexcept {}
        MusicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IMusicProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageItemContentProperties : llm:OS::Storage::FileProperties::IStorageItemContentProperties
    {
        StorageItemContentProperties(std::nullptr_t) noexcept {}
        StorageItemContentProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IStorageItemContentProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageItemThumbnail : llm:OS::Storage::Streams::IRandomAccessStreamWithContentType,
        impl::require<StorageItemThumbnail, llm:OS::Storage::FileProperties::IThumbnailProperties>
    {
        StorageItemThumbnail(std::nullptr_t) noexcept {}
        StorageItemThumbnail(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStreamWithContentType(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoProperties : llm:OS::Storage::FileProperties::IVideoProperties
    {
        VideoProperties(std::nullptr_t) noexcept {}
        VideoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::FileProperties::IVideoProperties(ptr, take_ownership_from_abi) {}
    };
}
#endif
