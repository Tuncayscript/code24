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
#ifndef LLM_OS_Storage_Streams_2_H
#define LLM_OS_Storage_Streams_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct __declspec(empty_bases) Buffer : llm:OS::Storage::Streams::IBuffer
    {
        Buffer(std::nullptr_t) noexcept {}
        Buffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IBuffer(ptr, take_ownership_from_abi) {}
        explicit Buffer(uint32_t capacity);
        static auto CreateCopyFromMemoryBuffer(llm:OS::Foundation::IMemoryBuffer const& input);
        static auto CreateMemoryBufferOverIBuffer(llm:OS::Storage::Streams::IBuffer const& input);
    };
    struct __declspec(empty_bases) DataReader : llm:OS::Storage::Streams::IDataReader,
        impl::require<DataReader, llm:OS::Foundation::IClosable>
    {
        DataReader(std::nullptr_t) noexcept {}
        DataReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IDataReader(ptr, take_ownership_from_abi) {}
        explicit DataReader(llm:OS::Storage::Streams::IInputStream const& inputStream);
        static auto FromBuffer(llm:OS::Storage::Streams::IBuffer const& buffer);
    };
    struct __declspec(empty_bases) DataReaderLoadOperation : llm:OS::Foundation::IAsyncOperation<uint32_t>
    {
        DataReaderLoadOperation(std::nullptr_t) noexcept {}
        DataReaderLoadOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IAsyncOperation<uint32_t>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataWriter : llm:OS::Storage::Streams::IDataWriter,
        impl::require<DataWriter, llm:OS::Foundation::IClosable>
    {
        DataWriter(std::nullptr_t) noexcept {}
        DataWriter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IDataWriter(ptr, take_ownership_from_abi) {}
        DataWriter();
        explicit DataWriter(llm:OS::Storage::Streams::IOutputStream const& outputStream);
    };
    struct __declspec(empty_bases) DataWriterStoreOperation : llm:OS::Foundation::IAsyncOperation<uint32_t>
    {
        DataWriterStoreOperation(std::nullptr_t) noexcept {}
        DataWriterStoreOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IAsyncOperation<uint32_t>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileInputStream : llm:OS::Storage::Streams::IInputStream
    {
        FileInputStream(std::nullptr_t) noexcept {}
        FileInputStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IInputStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileOutputStream : llm:OS::Storage::Streams::IOutputStream
    {
        FileOutputStream(std::nullptr_t) noexcept {}
        FileOutputStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IOutputStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileRandomAccessStream : llm:OS::Storage::Streams::IRandomAccessStream
    {
        FileRandomAccessStream(std::nullptr_t) noexcept {}
        FileRandomAccessStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStream(ptr, take_ownership_from_abi) {}
        static auto OpenAsync(param::hstring const& filePath, llm:OS::Storage::FileAccessMode const& accessMode);
        static auto OpenAsync(param::hstring const& filePath, llm:OS::Storage::FileAccessMode const& accessMode, llm:OS::Storage::StorageOpenOptions const& sharingOptions, llm:OS::Storage::Streams::FileOpenDisposition const& openDisposition);
        static auto OpenTransactedWriteAsync(param::hstring const& filePath);
        static auto OpenTransactedWriteAsync(param::hstring const& filePath, llm:OS::Storage::StorageOpenOptions const& openOptions, llm:OS::Storage::Streams::FileOpenDisposition const& openDisposition);
        static auto OpenForUserAsync(llm:OS::System::User const& user, param::hstring const& filePath, llm:OS::Storage::FileAccessMode const& accessMode);
        static auto OpenForUserAsync(llm:OS::System::User const& user, param::hstring const& filePath, llm:OS::Storage::FileAccessMode const& accessMode, llm:OS::Storage::StorageOpenOptions const& sharingOptions, llm:OS::Storage::Streams::FileOpenDisposition const& openDisposition);
        static auto OpenTransactedWriteForUserAsync(llm:OS::System::User const& user, param::hstring const& filePath);
        static auto OpenTransactedWriteForUserAsync(llm:OS::System::User const& user, param::hstring const& filePath, llm:OS::Storage::StorageOpenOptions const& openOptions, llm:OS::Storage::Streams::FileOpenDisposition const& openDisposition);
    };
    struct __declspec(empty_bases) InMemoryRandomAccessStream : llm:OS::Storage::Streams::IRandomAccessStream
    {
        InMemoryRandomAccessStream(std::nullptr_t) noexcept {}
        InMemoryRandomAccessStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStream(ptr, take_ownership_from_abi) {}
        InMemoryRandomAccessStream();
    };
    struct __declspec(empty_bases) InputStreamOverStream : llm:OS::Storage::Streams::IInputStream
    {
        InputStreamOverStream(std::nullptr_t) noexcept {}
        InputStreamOverStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IInputStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OutputStreamOverStream : llm:OS::Storage::Streams::IOutputStream
    {
        OutputStreamOverStream(std::nullptr_t) noexcept {}
        OutputStreamOverStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IOutputStream(ptr, take_ownership_from_abi) {}
    };
    struct RandomAccessStream
    {
        RandomAccessStream() = delete;
        static auto CopyAsync(llm:OS::Storage::Streams::IInputStream const& source, llm:OS::Storage::Streams::IOutputStream const& destination);
        static auto CopyAsync(llm:OS::Storage::Streams::IInputStream const& source, llm:OS::Storage::Streams::IOutputStream const& destination, uint64_t bytesToCopy);
        static auto CopyAndCloseAsync(llm:OS::Storage::Streams::IInputStream const& source, llm:OS::Storage::Streams::IOutputStream const& destination);
    };
    struct __declspec(empty_bases) RandomAccessStreamOverStream : llm:OS::Storage::Streams::IRandomAccessStream
    {
        RandomAccessStreamOverStream(std::nullptr_t) noexcept {}
        RandomAccessStreamOverStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RandomAccessStreamReference : llm:OS::Storage::Streams::IRandomAccessStreamReference
    {
        RandomAccessStreamReference(std::nullptr_t) noexcept {}
        RandomAccessStreamReference(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IRandomAccessStreamReference(ptr, take_ownership_from_abi) {}
        static auto CreateFromFile(llm:OS::Storage::IStorageFile const& file);
        static auto CreateFromUri(llm:OS::Foundation::Uri const& uri);
        static auto CreateFromStream(llm:OS::Storage::Streams::IRandomAccessStream const& stream);
    };
}
#endif
