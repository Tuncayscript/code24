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
#ifndef LLM_OS_Storage_Compression_1_H
#define LLM_OS_Storage_Compression_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Storage.Streams.0.h"
#include "llm/impl/Windows.Storage.Compression.0.h"
LLM_EXPORT namespace llm:OS::Storage::Compression
{
    struct __declspec(empty_bases) ICompressor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompressor>,
        impl::require<llm:OS::Storage::Compression::ICompressor, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IOutputStream>
    {
        ICompressor(std::nullptr_t = nullptr) noexcept {}
        ICompressor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompressorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompressorFactory>
    {
        ICompressorFactory(std::nullptr_t = nullptr) noexcept {}
        ICompressorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDecompressor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDecompressor>,
        impl::require<llm:OS::Storage::Compression::IDecompressor, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IInputStream>
    {
        IDecompressor(std::nullptr_t = nullptr) noexcept {}
        IDecompressor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDecompressorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDecompressorFactory>
    {
        IDecompressorFactory(std::nullptr_t = nullptr) noexcept {}
        IDecompressorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
