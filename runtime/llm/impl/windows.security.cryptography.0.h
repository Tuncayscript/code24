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
#ifndef LLM_OS_Security_Cryptography_0_H
#define LLM_OS_Security_Cryptography_0_H
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::Security::Cryptography
{
    enum class BinaryStringEncoding : int32_t
    {
        Utf8 = 0,
        Utf16LE = 1,
        Utf16BE = 2,
    };
    struct ICryptographicBufferStatics;
    struct CryptographicBuffer;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Cryptography::ICryptographicBufferStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Cryptography::CryptographicBuffer>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Cryptography::BinaryStringEncoding>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::CryptographicBuffer> = L"Windows.Security.Cryptography.CryptographicBuffer";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::BinaryStringEncoding> = L"Windows.Security.Cryptography.BinaryStringEncoding";
    template <> inline constexpr auto& name_v<llm:OS::Security::Cryptography::ICryptographicBufferStatics> = L"Windows.Security.Cryptography.ICryptographicBufferStatics";
    template <> inline constexpr guid guid_v<llm:OS::Security::Cryptography::ICryptographicBufferStatics>{ 0x320B7E22,0x3CB0,0x4CDF,{ 0x86,0x63,0x1D,0x28,0x91,0x00,0x65,0xEB } }; // 320B7E22-3CB0-4CDF-8663-1D28910065EB
    template <> struct abi<llm:OS::Security::Cryptography::ICryptographicBufferStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Compare(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GenerateRandom(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GenerateRandomNumber(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall CreateFromByteArray(uint32_t, uint8_t*, void**) noexcept = 0;
            virtual int32_t __stdcall CopyToByteArray(void*, uint32_t*, uint8_t**) noexcept = 0;
            virtual int32_t __stdcall DecodeFromHexString(void*, void**) noexcept = 0;
            virtual int32_t __stdcall EncodeToHexString(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DecodeFromBase64String(void*, void**) noexcept = 0;
            virtual int32_t __stdcall EncodeToBase64String(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertStringToBinary(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertBinaryToString(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Cryptography_ICryptographicBufferStatics
    {
        LLM_IMPL_AUTO(bool) Compare(llm:OS::Storage::Streams::IBuffer const& object1, llm:OS::Storage::Streams::IBuffer const& object2) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) GenerateRandom(uint32_t length) const;
        LLM_IMPL_AUTO(uint32_t) GenerateRandomNumber() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) CreateFromByteArray(array_view<uint8_t const> value) const;
        LLM_IMPL_AUTO(void) CopyToByteArray(llm:OS::Storage::Streams::IBuffer const& buffer, com_array<uint8_t>& value) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DecodeFromHexString(param::hstring const& value) const;
        LLM_IMPL_AUTO(hstring) EncodeToHexString(llm:OS::Storage::Streams::IBuffer const& buffer) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DecodeFromBase64String(param::hstring const& value) const;
        LLM_IMPL_AUTO(hstring) EncodeToBase64String(llm:OS::Storage::Streams::IBuffer const& buffer) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) ConvertStringToBinary(param::hstring const& value, llm:OS::Security::Cryptography::BinaryStringEncoding const& encoding) const;
        LLM_IMPL_AUTO(hstring) ConvertBinaryToString(llm:OS::Security::Cryptography::BinaryStringEncoding const& encoding, llm:OS::Storage::Streams::IBuffer const& buffer) const;
    };
    template <> struct consume<llm:OS::Security::Cryptography::ICryptographicBufferStatics>
    {
        template <typename D> using type = consume_Windows_Security_Cryptography_ICryptographicBufferStatics<D>;
    };
}
#endif
