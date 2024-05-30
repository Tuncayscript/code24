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
#ifndef LLM_OS_Storage_Compression_0_H
#define LLM_OS_Storage_Compression_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IInputStream;
    struct IOutputStream;
}
LLM_EXPORT namespace llm:OS::Storage::Compression
{
    enum class CompressAlgorithm : int32_t
    {
        InvalidAlgorithm = 0,
        NullAlgorithm = 1,
        Mszip = 2,
        Xpress = 3,
        XpressHuff = 4,
        Lzms = 5,
    };
    struct ICompressor;
    struct ICompressorFactory;
    struct IDecompressor;
    struct IDecompressorFactory;
    struct Compressor;
    struct Decompressor;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Storage::Compression::ICompressor>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Compression::ICompressorFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Compression::IDecompressor>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Compression::IDecompressorFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::Compression::Compressor>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Compression::Decompressor>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::Compression::CompressAlgorithm>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::Compressor> = L"Windows.Storage.Compression.Compressor";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::Decompressor> = L"Windows.Storage.Compression.Decompressor";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::CompressAlgorithm> = L"Windows.Storage.Compression.CompressAlgorithm";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::ICompressor> = L"Windows.Storage.Compression.ICompressor";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::ICompressorFactory> = L"Windows.Storage.Compression.ICompressorFactory";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::IDecompressor> = L"Windows.Storage.Compression.IDecompressor";
    template <> inline constexpr auto& name_v<llm:OS::Storage::Compression::IDecompressorFactory> = L"Windows.Storage.Compression.IDecompressorFactory";
    template <> inline constexpr guid guid_v<llm:OS::Storage::Compression::ICompressor>{ 0x0AC3645A,0x57AC,0x4EE1,{ 0xB7,0x02,0x84,0xD3,0x9D,0x54,0x24,0xE0 } }; // 0AC3645A-57AC-4EE1-B702-84D39D5424E0
    template <> inline constexpr guid guid_v<llm:OS::Storage::Compression::ICompressorFactory>{ 0x5F3D96A4,0x2CFB,0x442C,{ 0xA8,0xBA,0xD7,0xD1,0x1B,0x03,0x9D,0xA0 } }; // 5F3D96A4-2CFB-442C-A8BA-D7D11B039DA0
    template <> inline constexpr guid guid_v<llm:OS::Storage::Compression::IDecompressor>{ 0xB883FE46,0xD68A,0x4C8B,{ 0xAD,0xA0,0x4E,0xE8,0x13,0xFC,0x52,0x83 } }; // B883FE46-D68A-4C8B-ADA0-4EE813FC5283
    template <> inline constexpr guid guid_v<llm:OS::Storage::Compression::IDecompressorFactory>{ 0x5337E252,0x1DA2,0x42E1,{ 0x88,0x34,0x03,0x79,0xD2,0x8D,0x74,0x2F } }; // 5337E252-1DA2-42E1-8834-0379D28D742F
    template <> struct default_interface<llm:OS::Storage::Compression::Compressor>{ using type = llm:OS::Storage::Compression::ICompressor; };
    template <> struct default_interface<llm:OS::Storage::Compression::Decompressor>{ using type = llm:OS::Storage::Compression::IDecompressor; };
    template <> struct abi<llm:OS::Storage::Compression::ICompressor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FinishAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DetachStream(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Compression::ICompressorFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateCompressor(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCompressorEx(void*, int32_t, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Compression::IDecompressor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DetachStream(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::Compression::IDecompressorFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateDecompressor(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_ICompressor
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) FinishAsync() const;
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IOutputStream) DetachStream() const;
    };
    template <> struct consume<llm:OS::Storage::Compression::ICompressor>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_ICompressor<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_ICompressorFactory
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Compression::Compressor) CreateCompressor(llm:OS::Storage::Streams::IOutputStream const& underlyingStream) const;
        LLM_IMPL_AUTO(llm:OS::Storage::Compression::Compressor) CreateCompressorEx(llm:OS::Storage::Streams::IOutputStream const& underlyingStream, llm:OS::Storage::Compression::CompressAlgorithm const& algorithm, uint32_t blockSize) const;
    };
    template <> struct consume<llm:OS::Storage::Compression::ICompressorFactory>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_ICompressorFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_IDecompressor
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Streams::IInputStream) DetachStream() const;
    };
    template <> struct consume<llm:OS::Storage::Compression::IDecompressor>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_IDecompressor<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_Compression_IDecompressorFactory
    {
        LLM_IMPL_AUTO(llm:OS::Storage::Compression::Decompressor) CreateDecompressor(llm:OS::Storage::Streams::IInputStream const& underlyingStream) const;
    };
    template <> struct consume<llm:OS::Storage::Compression::IDecompressorFactory>
    {
        template <typename D> using type = consume_Windows_Storage_Compression_IDecompressorFactory<D>;
    };
}
#endif
