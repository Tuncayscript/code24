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
#ifndef LLM_OS_Security_Cryptography_2_H
#define LLM_OS_Security_Cryptography_2_H
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Security.Cryptography.1.h"
LLM_EXPORT namespace llm:OS::Security::Cryptography
{
    struct CryptographicBuffer
    {
        CryptographicBuffer() = delete;
        static auto Compare(llm:OS::Storage::Streams::IBuffer const& object1, llm:OS::Storage::Streams::IBuffer const& object2);
        static auto GenerateRandom(uint32_t length);
        static auto GenerateRandomNumber();
        static auto CreateFromByteArray(array_view<uint8_t const> value);
        static auto CopyToByteArray(llm:OS::Storage::Streams::IBuffer const& buffer, com_array<uint8_t>& value);
        static auto DecodeFromHexString(param::hstring const& value);
        static auto EncodeToHexString(llm:OS::Storage::Streams::IBuffer const& buffer);
        static auto DecodeFromBase64String(param::hstring const& value);
        static auto EncodeToBase64String(llm:OS::Storage::Streams::IBuffer const& buffer);
        static auto ConvertStringToBinary(param::hstring const& value, llm:OS::Security::Cryptography::BinaryStringEncoding const& encoding);
        static auto ConvertBinaryToString(llm:OS::Security::Cryptography::BinaryStringEncoding const& encoding, llm:OS::Storage::Streams::IBuffer const& buffer);
    };
}
#endif
