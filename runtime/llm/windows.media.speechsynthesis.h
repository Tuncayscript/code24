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
#ifndef LLM_OS_Media_SpeechSynthesis_H
#define LLM_OS_Media_SpeechSynthesis_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Core.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Media.SpeechSynthesis.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::SpeechSynthesis::VoiceInformation>) consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic<D>::AllVoices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic)->get_AllVoices(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::SpeechSynthesis::VoiceInformation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::VoiceInformation) consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic<D>::DefaultVoice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic)->get_DefaultVoice(&value));
        return llm::OS::Media::SpeechSynthesis::VoiceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic2<D>::TrySetDefaultVoiceAsync(llm::OS::Media::SpeechSynthesis::VoiceInformation const& voice) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic2)->TrySetDefaultVoiceAsync(*(void**)(&voice), &result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::IMediaMarker>) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesisStream<D>::Markers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesisStream)->get_Markers(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::IMediaMarker>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer<D>::SynthesizeTextToStreamAsync(param::hstring const& text) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer)->SynthesizeTextToStreamAsync(*(void**)(&text), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer<D>::SynthesizeSsmlToStreamAsync(param::hstring const& Ssml) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer)->SynthesizeSsmlToStreamAsync(*(void**)(&Ssml), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer<D>::Voice(llm::OS::Media::SpeechSynthesis::VoiceInformation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer)->put_Voice(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::VoiceInformation) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer<D>::Voice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer)->get_Voice(&value));
        return llm::OS::Media::SpeechSynthesis::VoiceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::SpeechSynthesizerOptions) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer2<D>::Options() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer2)->get_Options(&value));
        return llm::OS::Media::SpeechSynthesis::SpeechSynthesizerOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions<D>::IncludeWordBoundaryMetadata() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions)->get_IncludeWordBoundaryMetadata(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions<D>::IncludeWordBoundaryMetadata(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions)->put_IncludeWordBoundaryMetadata(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions<D>::IncludeSentenceBoundaryMetadata() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions)->get_IncludeSentenceBoundaryMetadata(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions<D>::IncludeSentenceBoundaryMetadata(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions)->put_IncludeSentenceBoundaryMetadata(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::AudioVolume() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->get_AudioVolume(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::AudioVolume(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->put_AudioVolume(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::SpeakingRate() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->get_SpeakingRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::SpeakingRate(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->put_SpeakingRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::AudioPitch() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->get_AudioPitch(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>::AudioPitch(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2)->put_AudioPitch(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::SpeechAppendedSilence) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3<D>::AppendedSilence() const
    {
        llm::OS::Media::SpeechSynthesis::SpeechAppendedSilence value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3)->get_AppendedSilence(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3<D>::AppendedSilence(llm::OS::Media::SpeechSynthesis::SpeechAppendedSilence const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3)->put_AppendedSilence(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::SpeechPunctuationSilence) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3<D>::PunctuationSilence() const
    {
        llm::OS::Media::SpeechSynthesis::SpeechPunctuationSilence value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3)->get_PunctuationSilence(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3<D>::PunctuationSilence(llm::OS::Media::SpeechSynthesis::SpeechPunctuationSilence const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3)->put_PunctuationSilence(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IVoiceInformation)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IVoiceInformation)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IVoiceInformation)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IVoiceInformation)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechSynthesis::VoiceGender) consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>::Gender() const
    {
        llm::OS::Media::SpeechSynthesis::VoiceGender value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::SpeechSynthesis::IVoiceInformation)->get_Gender(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic> : produce_base<D, llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic>
    {
        int32_t __stdcall get_AllVoices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::SpeechSynthesis::VoiceInformation>>(this->shim().AllVoices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultVoice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::VoiceInformation>(this->shim().DefaultVoice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic2> : produce_base<D, llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic2>
    {
        int32_t __stdcall TrySetDefaultVoiceAsync(void* voice, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TrySetDefaultVoiceAsync(*reinterpret_cast<llm::OS::Media::SpeechSynthesis::VoiceInformation const*>(&voice)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesisStream> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesisStream>
    {
        int32_t __stdcall get_Markers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::IMediaMarker>>(this->shim().Markers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer>
    {
        int32_t __stdcall SynthesizeTextToStreamAsync(void* text, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>>(this->shim().SynthesizeTextToStreamAsync(*reinterpret_cast<hstring const*>(&text)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SynthesizeSsmlToStreamAsync(void* Ssml, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream>>(this->shim().SynthesizeSsmlToStreamAsync(*reinterpret_cast<hstring const*>(&Ssml)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Voice(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Voice(*reinterpret_cast<llm::OS::Media::SpeechSynthesis::VoiceInformation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Voice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::VoiceInformation>(this->shim().Voice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer2> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer2>
    {
        int32_t __stdcall get_Options(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::SpeechSynthesizerOptions>(this->shim().Options());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions>
    {
        int32_t __stdcall get_IncludeWordBoundaryMetadata(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeWordBoundaryMetadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeWordBoundaryMetadata(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeWordBoundaryMetadata(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IncludeSentenceBoundaryMetadata(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IncludeSentenceBoundaryMetadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IncludeSentenceBoundaryMetadata(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeSentenceBoundaryMetadata(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2>
    {
        int32_t __stdcall get_AudioVolume(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().AudioVolume());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioVolume(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioVolume(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpeakingRate(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().SpeakingRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SpeakingRate(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpeakingRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioPitch(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().AudioPitch());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioPitch(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioPitch(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> : produce_base<D, llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>
    {
        int32_t __stdcall get_AppendedSilence(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::SpeechAppendedSilence>(this->shim().AppendedSilence());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AppendedSilence(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendedSilence(*reinterpret_cast<llm::OS::Media::SpeechSynthesis::SpeechAppendedSilence const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PunctuationSilence(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::SpeechPunctuationSilence>(this->shim().PunctuationSilence());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PunctuationSilence(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PunctuationSilence(*reinterpret_cast<llm::OS::Media::SpeechSynthesis::SpeechPunctuationSilence const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::SpeechSynthesis::IVoiceInformation> : produce_base<D, llm::OS::Media::SpeechSynthesis::IVoiceInformation>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gender(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechSynthesis::VoiceGender>(this->shim().Gender());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::SpeechSynthesis
{
    inline SpeechSynthesizer::SpeechSynthesizer() :
        SpeechSynthesizer(impl::call_factory_cast<SpeechSynthesizer(*)(llm::OS::Foundation::IActivationFactory const&), SpeechSynthesizer>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SpeechSynthesizer>(); }))
    {
    }
    inline auto SpeechSynthesizer::AllVoices()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::SpeechSynthesis::VoiceInformation>(*)(IInstalledVoicesStatic const&), SpeechSynthesizer, IInstalledVoicesStatic>([](IInstalledVoicesStatic const& f) { return f.AllVoices(); });
    }
    inline auto SpeechSynthesizer::DefaultVoice()
    {
        return impl::call_factory_cast<llm::OS::Media::SpeechSynthesis::VoiceInformation(*)(IInstalledVoicesStatic const&), SpeechSynthesizer, IInstalledVoicesStatic>([](IInstalledVoicesStatic const& f) { return f.DefaultVoice(); });
    }
    inline auto SpeechSynthesizer::TrySetDefaultVoiceAsync(llm::OS::Media::SpeechSynthesis::VoiceInformation const& voice)
    {
        return impl::call_factory<SpeechSynthesizer, IInstalledVoicesStatic2>([&](IInstalledVoicesStatic2 const& f) { return f.TrySetDefaultVoiceAsync(voice); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::IInstalledVoicesStatic2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesisStream> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesizer2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::IVoiceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::SpeechSynthesisStream> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::SpeechSynthesizer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::SpeechSynthesizerOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::SpeechSynthesis::VoiceInformation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
