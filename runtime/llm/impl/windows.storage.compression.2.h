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
#ifndef LLM_OS_Storage_Compression_2_H
#define LLM_OS_Storage_Compression_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Storage.Compression.1.h"
LLM_EXPORT namespace llm:OS::Storage::Compression
{
    struct __declspec(empty_bases) Compressor : llm:OS::Storage::Compression::ICompressor
    {
        Compressor(std::nullptr_t) noexcept {}
        Compressor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Compression::ICompressor(ptr, take_ownership_from_abi) {}
        explicit Compressor(llm:OS::Storage::Streams::IOutputStream const& underlyingStream);
        Compressor(llm:OS::Storage::Streams::IOutputStream const& underlyingStream, llm:OS::Storage::Compression::CompressAlgorithm const& algorithm, uint32_t blockSize);
    };
    struct __declspec(empty_bases) Decompressor : llm:OS::Storage::Compression::IDecompressor
    {
        Decompressor(std::nullptr_t) noexcept {}
        Decompressor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Compression::IDecompressor(ptr, take_ownership_from_abi) {}
        explicit Decompressor(llm:OS::Storage::Streams::IInputStream const& underlyingStream);
    };
}
#endif
