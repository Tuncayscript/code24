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
#ifndef LLM_OS_Media_Transcoding_H
#define LLM_OS_Media_Transcoding_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Media.Core.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Media.Transcoding.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::TrimStartTime(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->put_TrimStartTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::TrimStartTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->get_TrimStartTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::TrimStopTime(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->put_TrimStopTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::TrimStopTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->get_TrimStopTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AlwaysReencode(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->put_AlwaysReencode(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AlwaysReencode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->get_AlwaysReencode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::HardwareAccelerationEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->put_HardwareAccelerationEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::HardwareAccelerationEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->get_HardwareAccelerationEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AddAudioEffect(param::hstring const& activatableClassId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->AddAudioEffect(*(void**)(&activatableClassId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AddAudioEffect(param::hstring const& activatableClassId, bool effectRequired, llm::OS::Foundation::Collections::IPropertySet const& configuration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->AddAudioEffectWithSettings(*(void**)(&activatableClassId), effectRequired, *(void**)(&configuration)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AddVideoEffect(param::hstring const& activatableClassId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->AddVideoEffect(*(void**)(&activatableClassId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::AddVideoEffect(param::hstring const& activatableClassId, bool effectRequired, llm::OS::Foundation::Collections::IPropertySet const& configuration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->AddVideoEffectWithSettings(*(void**)(&activatableClassId), effectRequired, *(void**)(&configuration)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::ClearEffects() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->ClearEffects());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::PrepareFileTranscodeAsync(llm::OS::Storage::IStorageFile const& source, llm::OS::Storage::IStorageFile const& destination, llm::OS::Media::MediaProperties::MediaEncodingProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->PrepareFileTranscodeAsync(*(void**)(&source), *(void**)(&destination), *(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>) consume_Windows_Media_Transcoding_IMediaTranscoder<D>::PrepareStreamTranscodeAsync(llm::OS::Storage::Streams::IRandomAccessStream const& source, llm::OS::Storage::Streams::IRandomAccessStream const& destination, llm::OS::Media::MediaProperties::MediaEncodingProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder)->PrepareStreamTranscodeAsync(*(void**)(&source), *(void**)(&destination), *(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>) consume_Windows_Media_Transcoding_IMediaTranscoder2<D>::PrepareMediaStreamSourceTranscodeAsync(llm::OS::Media::Core::IMediaSource const& source, llm::OS::Storage::Streams::IRandomAccessStream const& destination, llm::OS::Media::MediaProperties::MediaEncodingProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder2)->PrepareMediaStreamSourceTranscodeAsync(*(void**)(&source), *(void**)(&destination), *(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Transcoding_IMediaTranscoder2<D>::VideoProcessingAlgorithm(llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder2)->put_VideoProcessingAlgorithm(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm) consume_Windows_Media_Transcoding_IMediaTranscoder2<D>::VideoProcessingAlgorithm() const
    {
        llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IMediaTranscoder2)->get_VideoProcessingAlgorithm(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Transcoding_IPrepareTranscodeResult<D>::CanTranscode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IPrepareTranscodeResult)->get_CanTranscode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Transcoding::TranscodeFailureReason) consume_Windows_Media_Transcoding_IPrepareTranscodeResult<D>::FailureReason() const
    {
        llm::OS::Media::Transcoding::TranscodeFailureReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IPrepareTranscodeResult)->get_FailureReason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncActionWithProgress<double>) consume_Windows_Media_Transcoding_IPrepareTranscodeResult<D>::TranscodeAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Transcoding::IPrepareTranscodeResult)->TranscodeAsync(&operation));
        return llm::OS::Foundation::IAsyncActionWithProgress<double>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Transcoding::IMediaTranscoder> : produce_base<D, llm::OS::Media::Transcoding::IMediaTranscoder>
    {
        int32_t __stdcall put_TrimStartTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimStartTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimStartTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimStartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimStopTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimStopTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimStopTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimStopTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlwaysReencode(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysReencode(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlwaysReencode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AlwaysReencode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HardwareAccelerationEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HardwareAccelerationEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareAccelerationEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HardwareAccelerationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddAudioEffect(void* activatableClassId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<hstring const*>(&activatableClassId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddAudioEffectWithSettings(void* activatableClassId, bool effectRequired, void* configuration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<hstring const*>(&activatableClassId), effectRequired, *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&configuration));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddVideoEffect(void* activatableClassId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<hstring const*>(&activatableClassId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddVideoEffectWithSettings(void* activatableClassId, bool effectRequired, void* configuration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<hstring const*>(&activatableClassId), effectRequired, *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&configuration));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearEffects() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearEffects();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PrepareFileTranscodeAsync(void* source, void* destination, void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>>(this->shim().PrepareFileTranscodeAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&source), *reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&destination), *reinterpret_cast<llm::OS::Media::MediaProperties::MediaEncodingProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PrepareStreamTranscodeAsync(void* source, void* destination, void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>>(this->shim().PrepareStreamTranscodeAsync(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&source), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&destination), *reinterpret_cast<llm::OS::Media::MediaProperties::MediaEncodingProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Transcoding::IMediaTranscoder2> : produce_base<D, llm::OS::Media::Transcoding::IMediaTranscoder2>
    {
        int32_t __stdcall PrepareMediaStreamSourceTranscodeAsync(void* source, void* destination, void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Transcoding::PrepareTranscodeResult>>(this->shim().PrepareMediaStreamSourceTranscodeAsync(*reinterpret_cast<llm::OS::Media::Core::IMediaSource const*>(&source), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&destination), *reinterpret_cast<llm::OS::Media::MediaProperties::MediaEncodingProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VideoProcessingAlgorithm(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProcessingAlgorithm(*reinterpret_cast<llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProcessingAlgorithm(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm>(this->shim().VideoProcessingAlgorithm());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Transcoding::IPrepareTranscodeResult> : produce_base<D, llm::OS::Media::Transcoding::IPrepareTranscodeResult>
    {
        int32_t __stdcall get_CanTranscode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanTranscode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FailureReason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Transcoding::TranscodeFailureReason>(this->shim().FailureReason());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TranscodeAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncActionWithProgress<double>>(this->shim().TranscodeAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Transcoding
{
    inline MediaTranscoder::MediaTranscoder() :
        MediaTranscoder(impl::call_factory_cast<MediaTranscoder(*)(llm::OS::Foundation::IActivationFactory const&), MediaTranscoder>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaTranscoder>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Transcoding::IMediaTranscoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Transcoding::IMediaTranscoder2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Transcoding::IPrepareTranscodeResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Transcoding::MediaTranscoder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Transcoding::PrepareTranscodeResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
