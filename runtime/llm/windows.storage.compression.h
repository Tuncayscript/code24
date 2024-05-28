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
#ifndef LLM_OS_Storage_Compression_H
#define LLM_OS_Storage_Compression_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Storage.Compression.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Storage_Compression_ICompressor<D>::FinishAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::ICompressor)->FinishAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) consume_Windows_Storage_Compression_ICompressor<D>::DetachStream() const
    {
        void* stream{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::ICompressor)->DetachStream(&stream));
        return llm::OS::Storage::Streams::IOutputStream{ stream, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Compression::Compressor) consume_Windows_Storage_Compression_ICompressorFactory<D>::CreateCompressor(llm::OS::Storage::Streams::IOutputStream const& underlyingStream) const
    {
        void* createdCompressor{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::ICompressorFactory)->CreateCompressor(*(void**)(&underlyingStream), &createdCompressor));
        return llm::OS::Storage::Compression::Compressor{ createdCompressor, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Compression::Compressor) consume_Windows_Storage_Compression_ICompressorFactory<D>::CreateCompressorEx(llm::OS::Storage::Streams::IOutputStream const& underlyingStream, llm::OS::Storage::Compression::CompressAlgorithm const& algorithm, uint32_t blockSize) const
    {
        void* createdCompressor{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::ICompressorFactory)->CreateCompressorEx(*(void**)(&underlyingStream), static_cast<int32_t>(algorithm), blockSize, &createdCompressor));
        return llm::OS::Storage::Compression::Compressor{ createdCompressor, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Storage_Compression_IDecompressor<D>::DetachStream() const
    {
        void* stream{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::IDecompressor)->DetachStream(&stream));
        return llm::OS::Storage::Streams::IInputStream{ stream, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Compression::Decompressor) consume_Windows_Storage_Compression_IDecompressorFactory<D>::CreateDecompressor(llm::OS::Storage::Streams::IInputStream const& underlyingStream) const
    {
        void* createdDecompressor{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Compression::IDecompressorFactory)->CreateDecompressor(*(void**)(&underlyingStream), &createdDecompressor));
        return llm::OS::Storage::Compression::Decompressor{ createdDecompressor, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Compression::ICompressor> : produce_base<D, llm::OS::Storage::Compression::ICompressor>
    {
        int32_t __stdcall FinishAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().FinishAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DetachStream(void** stream) noexcept final try
        {
            clear_abi(stream);
            typename D::abi_guard guard(this->shim());
            *stream = detach_from<llm::OS::Storage::Streams::IOutputStream>(this->shim().DetachStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Compression::ICompressorFactory> : produce_base<D, llm::OS::Storage::Compression::ICompressorFactory>
    {
        int32_t __stdcall CreateCompressor(void* underlyingStream, void** createdCompressor) noexcept final try
        {
            clear_abi(createdCompressor);
            typename D::abi_guard guard(this->shim());
            *createdCompressor = detach_from<llm::OS::Storage::Compression::Compressor>(this->shim().CreateCompressor(*reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&underlyingStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCompressorEx(void* underlyingStream, int32_t algorithm, uint32_t blockSize, void** createdCompressor) noexcept final try
        {
            clear_abi(createdCompressor);
            typename D::abi_guard guard(this->shim());
            *createdCompressor = detach_from<llm::OS::Storage::Compression::Compressor>(this->shim().CreateCompressorEx(*reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&underlyingStream), *reinterpret_cast<llm::OS::Storage::Compression::CompressAlgorithm const*>(&algorithm), blockSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Compression::IDecompressor> : produce_base<D, llm::OS::Storage::Compression::IDecompressor>
    {
        int32_t __stdcall DetachStream(void** stream) noexcept final try
        {
            clear_abi(stream);
            typename D::abi_guard guard(this->shim());
            *stream = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().DetachStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Compression::IDecompressorFactory> : produce_base<D, llm::OS::Storage::Compression::IDecompressorFactory>
    {
        int32_t __stdcall CreateDecompressor(void* underlyingStream, void** createdDecompressor) noexcept final try
        {
            clear_abi(createdDecompressor);
            typename D::abi_guard guard(this->shim());
            *createdDecompressor = detach_from<llm::OS::Storage::Compression::Decompressor>(this->shim().CreateDecompressor(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&underlyingStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::Compression
{
    inline Compressor::Compressor(llm::OS::Storage::Streams::IOutputStream const& underlyingStream) :
        Compressor(impl::call_factory<Compressor, ICompressorFactory>([&](ICompressorFactory const& f) { return f.CreateCompressor(underlyingStream); }))
    {
    }
    inline Compressor::Compressor(llm::OS::Storage::Streams::IOutputStream const& underlyingStream, llm::OS::Storage::Compression::CompressAlgorithm const& algorithm, uint32_t blockSize) :
        Compressor(impl::call_factory<Compressor, ICompressorFactory>([&](ICompressorFactory const& f) { return f.CreateCompressorEx(underlyingStream, algorithm, blockSize); }))
    {
    }
    inline Decompressor::Decompressor(llm::OS::Storage::Streams::IInputStream const& underlyingStream) :
        Decompressor(impl::call_factory<Decompressor, IDecompressorFactory>([&](IDecompressorFactory const& f) { return f.CreateDecompressor(underlyingStream); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::Compression::ICompressor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Compression::ICompressorFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Compression::IDecompressor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Compression::IDecompressorFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Compression::Compressor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Compression::Decompressor> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
