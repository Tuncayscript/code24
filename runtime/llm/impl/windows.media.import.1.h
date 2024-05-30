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
#ifndef LLM_OS_Media_Import_1_H
#define LLM_OS_Media_Import_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.Import.0.h"
LLM_EXPORT namespace llm:OS::Media::Import
{
    struct __declspec(empty_bases) IPhotoImportDeleteImportedItemsFromSourceResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportDeleteImportedItemsFromSourceResult>
    {
        IPhotoImportDeleteImportedItemsFromSourceResult(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportDeleteImportedItemsFromSourceResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportFindItemsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportFindItemsResult>
    {
        IPhotoImportFindItemsResult(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportFindItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportFindItemsResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportFindItemsResult2>
    {
        IPhotoImportFindItemsResult2(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportFindItemsResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportImportItemsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportImportItemsResult>
    {
        IPhotoImportImportItemsResult(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportImportItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportItem>
    {
        IPhotoImportItem(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportItem2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportItem2>
    {
        IPhotoImportItem2(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportItem2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportItemImportedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportItemImportedEventArgs>
    {
        IPhotoImportItemImportedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportItemImportedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportManagerStatics>
    {
        IPhotoImportManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportOperation>
    {
        IPhotoImportOperation(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSelectionChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSelectionChangedEventArgs>
    {
        IPhotoImportSelectionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSelectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSession>,
        impl::require<llm:OS::Media::Import::IPhotoImportSession, llm:OS::Foundation::IClosable>
    {
        IPhotoImportSession(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSession2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSession2>
    {
        IPhotoImportSession2(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSession2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSidecar :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSidecar>
    {
        IPhotoImportSidecar(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSidecar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSource>
    {
        IPhotoImportSource(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportSourceStatics>
    {
        IPhotoImportSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportStorageMedium :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportStorageMedium>
    {
        IPhotoImportStorageMedium(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportStorageMedium(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoImportVideoSegment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoImportVideoSegment>
    {
        IPhotoImportVideoSegment(std::nullptr_t = nullptr) noexcept {}
        IPhotoImportVideoSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
