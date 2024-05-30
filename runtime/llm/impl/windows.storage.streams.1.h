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
#ifndef LLM_OS_Storage_Streams_1_H
#define LLM_OS_Storage_Streams_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Storage.Streams.0.h"
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct __declspec(empty_bases) IBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBuffer>
    {
        IBuffer(std::nullptr_t = nullptr) noexcept {}
        IBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBufferFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBufferFactory>
    {
        IBufferFactory(std::nullptr_t = nullptr) noexcept {}
        IBufferFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBufferStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBufferStatics>
    {
        IBufferStatics(std::nullptr_t = nullptr) noexcept {}
        IBufferStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentTypeProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentTypeProvider>
    {
        IContentTypeProvider(std::nullptr_t = nullptr) noexcept {}
        IContentTypeProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataReader>
    {
        IDataReader(std::nullptr_t = nullptr) noexcept {}
        IDataReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataReaderFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataReaderFactory>
    {
        IDataReaderFactory(std::nullptr_t = nullptr) noexcept {}
        IDataReaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataReaderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataReaderStatics>
    {
        IDataReaderStatics(std::nullptr_t = nullptr) noexcept {}
        IDataReaderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataWriter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataWriter>
    {
        IDataWriter(std::nullptr_t = nullptr) noexcept {}
        IDataWriter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataWriterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataWriterFactory>
    {
        IDataWriterFactory(std::nullptr_t = nullptr) noexcept {}
        IDataWriterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileRandomAccessStreamStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileRandomAccessStreamStatics>
    {
        IFileRandomAccessStreamStatics(std::nullptr_t = nullptr) noexcept {}
        IFileRandomAccessStreamStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputStream :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputStream>,
        impl::require<llm:OS::Storage::Streams::IInputStream, llm:OS::Foundation::IClosable>
    {
        IInputStream(std::nullptr_t = nullptr) noexcept {}
        IInputStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputStreamReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputStreamReference>
    {
        IInputStreamReference(std::nullptr_t = nullptr) noexcept {}
        IInputStreamReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOutputStream :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOutputStream>,
        impl::require<llm:OS::Storage::Streams::IOutputStream, llm:OS::Foundation::IClosable>
    {
        IOutputStream(std::nullptr_t = nullptr) noexcept {}
        IOutputStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPropertySetSerializer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPropertySetSerializer>
    {
        IPropertySetSerializer(std::nullptr_t = nullptr) noexcept {}
        IPropertySetSerializer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRandomAccessStream :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRandomAccessStream>,
        impl::require<llm:OS::Storage::Streams::IRandomAccessStream, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IInputStream, llm:OS::Storage::Streams::IOutputStream>
    {
        IRandomAccessStream(std::nullptr_t = nullptr) noexcept {}
        IRandomAccessStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRandomAccessStreamReference :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRandomAccessStreamReference>
    {
        IRandomAccessStreamReference(std::nullptr_t = nullptr) noexcept {}
        IRandomAccessStreamReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRandomAccessStreamReferenceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRandomAccessStreamReferenceStatics>
    {
        IRandomAccessStreamReferenceStatics(std::nullptr_t = nullptr) noexcept {}
        IRandomAccessStreamReferenceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRandomAccessStreamStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRandomAccessStreamStatics>
    {
        IRandomAccessStreamStatics(std::nullptr_t = nullptr) noexcept {}
        IRandomAccessStreamStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRandomAccessStreamWithContentType :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRandomAccessStreamWithContentType>,
        impl::require<llm:OS::Storage::Streams::IRandomAccessStreamWithContentType, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IInputStream, llm:OS::Storage::Streams::IOutputStream, llm:OS::Storage::Streams::IRandomAccessStream, llm:OS::Storage::Streams::IContentTypeProvider>
    {
        IRandomAccessStreamWithContentType(std::nullptr_t = nullptr) noexcept {}
        IRandomAccessStreamWithContentType(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
