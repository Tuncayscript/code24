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
#ifndef LLM_OS_Media_Editing_H
#define LLM_OS_Media_Editing_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.Core.2.h"
#include "llm/impl/Windows.Media.Effects.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Media.Transcoding.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Media.Editing.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::TrimTimeFromStart() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_TrimTimeFromStart(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::TrimTimeFromStart(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->put_TrimTimeFromStart(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::TrimTimeFromEnd() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_TrimTimeFromEnd(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::TrimTimeFromEnd(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->put_TrimTimeFromEnd(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::OriginalDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_OriginalDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::TrimmedDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_TrimmedDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::UserData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_UserData(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::Delay(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->put_Delay(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::Delay() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_Delay(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::Volume(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->put_Volume(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::Volume() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_Volume(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::BackgroundAudioTrack) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::Clone() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->Clone(&value));
        return llm::OS::Media::Editing::BackgroundAudioTrack{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::AudioEncodingProperties) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::GetAudioEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->GetAudioEncodingProperties(&value));
        return llm::OS::Media::MediaProperties::AudioEncodingProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>) consume_Windows_Media_Editing_IBackgroundAudioTrack<D>::AudioEffectDefinitions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrack)->get_AudioEffectDefinitions(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::BackgroundAudioTrack) consume_Windows_Media_Editing_IBackgroundAudioTrackStatics<D>::CreateFromEmbeddedAudioTrack(llm::OS::Media::Editing::EmbeddedAudioTrack const& embeddedAudioTrack) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrackStatics)->CreateFromEmbeddedAudioTrack(*(void**)(&embeddedAudioTrack), &value));
        return llm::OS::Media::Editing::BackgroundAudioTrack{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::BackgroundAudioTrack>) consume_Windows_Media_Editing_IBackgroundAudioTrackStatics<D>::CreateFromFileAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IBackgroundAudioTrackStatics)->CreateFromFileAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::BackgroundAudioTrack>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::AudioEncodingProperties) consume_Windows_Media_Editing_IEmbeddedAudioTrack<D>::GetAudioEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IEmbeddedAudioTrack)->GetAudioEncodingProperties(&value));
        return llm::OS::Media::MediaProperties::AudioEncodingProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::TrimTimeFromStart() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_TrimTimeFromStart(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaClip<D>::TrimTimeFromStart(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->put_TrimTimeFromStart(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::TrimTimeFromEnd() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_TrimTimeFromEnd(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaClip<D>::TrimTimeFromEnd(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->put_TrimTimeFromEnd(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::OriginalDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_OriginalDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::TrimmedDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_TrimmedDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_Media_Editing_IMediaClip<D>::UserData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_UserData(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaClip) consume_Windows_Media_Editing_IMediaClip<D>::Clone() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->Clone(&result));
        return llm::OS::Media::Editing::MediaClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::StartTimeInComposition() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_StartTimeInComposition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaClip<D>::EndTimeInComposition() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_EndTimeInComposition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Editing::EmbeddedAudioTrack>) consume_Windows_Media_Editing_IMediaClip<D>::EmbeddedAudioTracks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_EmbeddedAudioTracks(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Editing::EmbeddedAudioTrack>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Editing_IMediaClip<D>::SelectedEmbeddedAudioTrackIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_SelectedEmbeddedAudioTrackIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaClip<D>::SelectedEmbeddedAudioTrackIndex(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->put_SelectedEmbeddedAudioTrackIndex(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaClip<D>::Volume(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->put_Volume(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Editing_IMediaClip<D>::Volume() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_Volume(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::VideoEncodingProperties) consume_Windows_Media_Editing_IMediaClip<D>::GetVideoEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->GetVideoEncodingProperties(&value));
        return llm::OS::Media::MediaProperties::VideoEncodingProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>) consume_Windows_Media_Editing_IMediaClip<D>::AudioEffectDefinitions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_AudioEffectDefinitions(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IVideoEffectDefinition>) consume_Windows_Media_Editing_IMediaClip<D>::VideoEffectDefinitions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClip)->get_VideoEffectDefinitions(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IVideoEffectDefinition>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaClip) consume_Windows_Media_Editing_IMediaClipStatics<D>::CreateFromColor(llm::OS::UI::Color const& color, llm::OS::Foundation::TimeSpan const& originalDuration) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClipStatics)->CreateFromColor(impl::bind_in(color), impl::bind_in(originalDuration), &value));
        return llm::OS::Media::Editing::MediaClip{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>) consume_Windows_Media_Editing_IMediaClipStatics<D>::CreateFromFileAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClipStatics)->CreateFromFileAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>) consume_Windows_Media_Editing_IMediaClipStatics<D>::CreateFromImageFileAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Foundation::TimeSpan const& originalDuration) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClipStatics)->CreateFromImageFileAsync(*(void**)(&file), impl::bind_in(originalDuration), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaClip) consume_Windows_Media_Editing_IMediaClipStatics2<D>::CreateFromSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm::OS::Foundation::TimeSpan const& originalDuration) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaClipStatics2)->CreateFromSurface(*(void**)(&surface), impl::bind_in(originalDuration), &value));
        return llm::OS::Media::Editing::MediaClip{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaComposition<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaClip>) consume_Windows_Media_Editing_IMediaComposition<D>::Clips() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->get_Clips(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaClip>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::BackgroundAudioTrack>) consume_Windows_Media_Editing_IMediaComposition<D>::BackgroundAudioTracks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->get_BackgroundAudioTracks(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::BackgroundAudioTrack>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_Media_Editing_IMediaComposition<D>::UserData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->get_UserData(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaComposition) consume_Windows_Media_Editing_IMediaComposition<D>::Clone() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->Clone(&result));
        return llm::OS::Media::Editing::MediaComposition{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Editing_IMediaComposition<D>::SaveAsync(llm::OS::Storage::IStorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->SaveAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>) consume_Windows_Media_Editing_IMediaComposition<D>::GetThumbnailAsync(llm::OS::Foundation::TimeSpan const& timeFromStart, int32_t scaledWidth, int32_t scaledHeight, llm::OS::Media::Editing::VideoFramePrecision const& framePrecision) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->GetThumbnailAsync(impl::bind_in(timeFromStart), scaledWidth, scaledHeight, static_cast<int32_t>(framePrecision), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::ImageStream>>) consume_Windows_Media_Editing_IMediaComposition<D>::GetThumbnailsAsync(param::async_iterable<llm::OS::Foundation::TimeSpan> const& timesFromStart, int32_t scaledWidth, int32_t scaledHeight, llm::OS::Media::Editing::VideoFramePrecision const& framePrecision) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->GetThumbnailsAsync(*(void**)(&timesFromStart), scaledWidth, scaledHeight, static_cast<int32_t>(framePrecision), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::ImageStream>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>) consume_Windows_Media_Editing_IMediaComposition<D>::RenderToFileAsync(llm::OS::Storage::IStorageFile const& destination) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->RenderToFileAsync(*(void**)(&destination), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>) consume_Windows_Media_Editing_IMediaComposition<D>::RenderToFileAsync(llm::OS::Storage::IStorageFile const& destination, llm::OS::Media::Editing::MediaTrimmingPreference const& trimmingPreference) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->RenderToFileWithTrimmingPreferenceAsync(*(void**)(&destination), static_cast<int32_t>(trimmingPreference), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>) consume_Windows_Media_Editing_IMediaComposition<D>::RenderToFileAsync(llm::OS::Storage::IStorageFile const& destination, llm::OS::Media::Editing::MediaTrimmingPreference const& trimmingPreference, llm::OS::Media::MediaProperties::MediaEncodingProfile const& encodingProfile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->RenderToFileWithProfileAsync(*(void**)(&destination), static_cast<int32_t>(trimmingPreference), *(void**)(&encodingProfile), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaEncodingProfile) consume_Windows_Media_Editing_IMediaComposition<D>::CreateDefaultEncodingProfile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->CreateDefaultEncodingProfile(&value));
        return llm::OS::Media::MediaProperties::MediaEncodingProfile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Core::MediaStreamSource) consume_Windows_Media_Editing_IMediaComposition<D>::GenerateMediaStreamSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->GenerateMediaStreamSource(&value));
        return llm::OS::Media::Core::MediaStreamSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Core::MediaStreamSource) consume_Windows_Media_Editing_IMediaComposition<D>::GenerateMediaStreamSource(llm::OS::Media::MediaProperties::MediaEncodingProfile const& encodingProfile) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->GenerateMediaStreamSourceWithProfile(*(void**)(&encodingProfile), &value));
        return llm::OS::Media::Core::MediaStreamSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Core::MediaStreamSource) consume_Windows_Media_Editing_IMediaComposition<D>::GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition)->GeneratePreviewMediaStreamSource(scaledWidth, scaledHeight, &value));
        return llm::OS::Media::Core::MediaStreamSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlayLayer>) consume_Windows_Media_Editing_IMediaComposition2<D>::OverlayLayers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaComposition2)->get_OverlayLayers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlayLayer>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaComposition>) consume_Windows_Media_Editing_IMediaCompositionStatics<D>::LoadAsync(llm::OS::Storage::StorageFile const& file) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaCompositionStatics)->LoadAsync(*(void**)(&file), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaComposition>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Media_Editing_IMediaOverlay<D>::Position() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaOverlay<D>::Position(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->put_Position(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaOverlay<D>::Delay(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->put_Delay(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Editing_IMediaOverlay<D>::Delay() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->get_Delay(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Editing_IMediaOverlay<D>::Opacity() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->get_Opacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaOverlay<D>::Opacity(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->put_Opacity(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlay) consume_Windows_Media_Editing_IMediaOverlay<D>::Clone() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->Clone(&result));
        return llm::OS::Media::Editing::MediaOverlay{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaClip) consume_Windows_Media_Editing_IMediaOverlay<D>::Clip() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->get_Clip(&value));
        return llm::OS::Media::Editing::MediaClip{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Editing_IMediaOverlay<D>::AudioEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->get_AudioEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Editing_IMediaOverlay<D>::AudioEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlay)->put_AudioEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlay) consume_Windows_Media_Editing_IMediaOverlayFactory<D>::Create(llm::OS::Media::Editing::MediaClip const& clip) const
    {
        void* mediaOverlay{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayFactory)->Create(*(void**)(&clip), &mediaOverlay));
        return llm::OS::Media::Editing::MediaOverlay{ mediaOverlay, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlay) consume_Windows_Media_Editing_IMediaOverlayFactory<D>::CreateWithPositionAndOpacity(llm::OS::Media::Editing::MediaClip const& clip, llm::OS::Foundation::Rect const& position, double opacity) const
    {
        void* mediaOverlay{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayFactory)->CreateWithPositionAndOpacity(*(void**)(&clip), impl::bind_in(position), opacity, &mediaOverlay));
        return llm::OS::Media::Editing::MediaOverlay{ mediaOverlay, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlayLayer) consume_Windows_Media_Editing_IMediaOverlayLayer<D>::Clone() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayLayer)->Clone(&result));
        return llm::OS::Media::Editing::MediaOverlayLayer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlay>) consume_Windows_Media_Editing_IMediaOverlayLayer<D>::Overlays() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayLayer)->get_Overlays(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlay>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::IVideoCompositorDefinition) consume_Windows_Media_Editing_IMediaOverlayLayer<D>::CustomCompositorDefinition() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayLayer)->get_CustomCompositorDefinition(&value));
        return llm::OS::Media::Effects::IVideoCompositorDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlayLayer) consume_Windows_Media_Editing_IMediaOverlayLayerFactory<D>::CreateWithCompositorDefinition(llm::OS::Media::Effects::IVideoCompositorDefinition const& compositorDefinition) const
    {
        void* mediaOverlayLayer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Editing::IMediaOverlayLayerFactory)->CreateWithCompositorDefinition(*(void**)(&compositorDefinition), &mediaOverlayLayer));
        return llm::OS::Media::Editing::MediaOverlayLayer{ mediaOverlayLayer, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IBackgroundAudioTrack> : produce_base<D, llm::OS::Media::Editing::IBackgroundAudioTrack>
    {
        int32_t __stdcall get_TrimTimeFromStart(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimTimeFromStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimTimeFromStart(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromStart(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimTimeFromEnd(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimTimeFromEnd());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimTimeFromEnd(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromEnd(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OriginalDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().OriginalDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimmedDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimmedDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().UserData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Delay(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delay(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Delay(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Delay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Volume(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Volume(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Volume());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::BackgroundAudioTrack>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::AudioEncodingProperties>(this->shim().GetAudioEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioEffectDefinitions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>>(this->shim().AudioEffectDefinitions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IBackgroundAudioTrackStatics> : produce_base<D, llm::OS::Media::Editing::IBackgroundAudioTrackStatics>
    {
        int32_t __stdcall CreateFromEmbeddedAudioTrack(void* embeddedAudioTrack, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::BackgroundAudioTrack>(this->shim().CreateFromEmbeddedAudioTrack(*reinterpret_cast<llm::OS::Media::Editing::EmbeddedAudioTrack const*>(&embeddedAudioTrack)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromFileAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::BackgroundAudioTrack>>(this->shim().CreateFromFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IEmbeddedAudioTrack> : produce_base<D, llm::OS::Media::Editing::IEmbeddedAudioTrack>
    {
        int32_t __stdcall GetAudioEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::AudioEncodingProperties>(this->shim().GetAudioEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaClip> : produce_base<D, llm::OS::Media::Editing::IMediaClip>
    {
        int32_t __stdcall get_TrimTimeFromStart(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimTimeFromStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimTimeFromStart(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromStart(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimTimeFromEnd(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimTimeFromEnd());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimTimeFromEnd(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimTimeFromEnd(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OriginalDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().OriginalDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimmedDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().TrimmedDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().UserData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Editing::MediaClip>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartTimeInComposition(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().StartTimeInComposition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndTimeInComposition(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().EndTimeInComposition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EmbeddedAudioTracks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Editing::EmbeddedAudioTrack>>(this->shim().EmbeddedAudioTracks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedEmbeddedAudioTrackIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedEmbeddedAudioTrackIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedEmbeddedAudioTrackIndex(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedEmbeddedAudioTrackIndex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Volume(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Volume(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Volume());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVideoEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::VideoEncodingProperties>(this->shim().GetVideoEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioEffectDefinitions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IAudioEffectDefinition>>(this->shim().AudioEffectDefinitions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoEffectDefinitions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Effects::IVideoEffectDefinition>>(this->shim().VideoEffectDefinitions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaClipStatics> : produce_base<D, llm::OS::Media::Editing::IMediaClipStatics>
    {
        int32_t __stdcall CreateFromColor(struct struct_Windows_UI_Color color, int64_t originalDuration, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::MediaClip>(this->shim().CreateFromColor(*reinterpret_cast<llm::OS::UI::Color const*>(&color), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&originalDuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromFileAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>>(this->shim().CreateFromFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromImageFileAsync(void* file, int64_t originalDuration, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaClip>>(this->shim().CreateFromImageFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&originalDuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaClipStatics2> : produce_base<D, llm::OS::Media::Editing::IMediaClipStatics2>
    {
        int32_t __stdcall CreateFromSurface(void* surface, int64_t originalDuration, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::MediaClip>(this->shim().CreateFromSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&surface), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&originalDuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaComposition> : produce_base<D, llm::OS::Media::Editing::IMediaComposition>
    {
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clips(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaClip>>(this->shim().Clips());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundAudioTracks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::BackgroundAudioTrack>>(this->shim().BackgroundAudioTracks());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().UserData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Editing::MediaComposition>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetThumbnailAsync(int64_t timeFromStart, int32_t scaledWidth, int32_t scaledHeight, int32_t framePrecision, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Graphics::Imaging::ImageStream>>(this->shim().GetThumbnailAsync(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timeFromStart), scaledWidth, scaledHeight, *reinterpret_cast<llm::OS::Media::Editing::VideoFramePrecision const*>(&framePrecision)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetThumbnailsAsync(void* timesFromStart, int32_t scaledWidth, int32_t scaledHeight, int32_t framePrecision, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::Imaging::ImageStream>>>(this->shim().GetThumbnailsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::TimeSpan> const*>(&timesFromStart), scaledWidth, scaledHeight, *reinterpret_cast<llm::OS::Media::Editing::VideoFramePrecision const*>(&framePrecision)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RenderToFileAsync(void* destination, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>>(this->shim().RenderToFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&destination)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RenderToFileWithTrimmingPreferenceAsync(void* destination, int32_t trimmingPreference, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>>(this->shim().RenderToFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&destination), *reinterpret_cast<llm::OS::Media::Editing::MediaTrimmingPreference const*>(&trimmingPreference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RenderToFileWithProfileAsync(void* destination, int32_t trimmingPreference, void* encodingProfile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Media::Transcoding::TranscodeFailureReason, double>>(this->shim().RenderToFileAsync(*reinterpret_cast<llm::OS::Storage::IStorageFile const*>(&destination), *reinterpret_cast<llm::OS::Media::Editing::MediaTrimmingPreference const*>(&trimmingPreference), *reinterpret_cast<llm::OS::Media::MediaProperties::MediaEncodingProfile const*>(&encodingProfile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDefaultEncodingProfile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaEncodingProfile>(this->shim().CreateDefaultEncodingProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GenerateMediaStreamSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Core::MediaStreamSource>(this->shim().GenerateMediaStreamSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GenerateMediaStreamSourceWithProfile(void* encodingProfile, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Core::MediaStreamSource>(this->shim().GenerateMediaStreamSource(*reinterpret_cast<llm::OS::Media::MediaProperties::MediaEncodingProfile const*>(&encodingProfile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Core::MediaStreamSource>(this->shim().GeneratePreviewMediaStreamSource(scaledWidth, scaledHeight));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaComposition2> : produce_base<D, llm::OS::Media::Editing::IMediaComposition2>
    {
        int32_t __stdcall get_OverlayLayers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlayLayer>>(this->shim().OverlayLayers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaCompositionStatics> : produce_base<D, llm::OS::Media::Editing::IMediaCompositionStatics>
    {
        int32_t __stdcall LoadAsync(void* file, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Editing::MediaComposition>>(this->shim().LoadAsync(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaOverlay> : produce_base<D, llm::OS::Media::Editing::IMediaOverlay>
    {
        int32_t __stdcall get_Position(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Position(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Delay(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delay(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Delay(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Delay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Opacity(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Opacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Opacity(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Editing::MediaOverlay>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clip(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::MediaClip>(this->shim().Clip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AudioEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AudioEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaOverlayFactory> : produce_base<D, llm::OS::Media::Editing::IMediaOverlayFactory>
    {
        int32_t __stdcall Create(void* clip, void** mediaOverlay) noexcept final try
        {
            clear_abi(mediaOverlay);
            typename D::abi_guard guard(this->shim());
            *mediaOverlay = detach_from<llm::OS::Media::Editing::MediaOverlay>(this->shim().Create(*reinterpret_cast<llm::OS::Media::Editing::MediaClip const*>(&clip)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithPositionAndOpacity(void* clip, llm::OS::Foundation::Rect position, double opacity, void** mediaOverlay) noexcept final try
        {
            clear_abi(mediaOverlay);
            typename D::abi_guard guard(this->shim());
            *mediaOverlay = detach_from<llm::OS::Media::Editing::MediaOverlay>(this->shim().CreateWithPositionAndOpacity(*reinterpret_cast<llm::OS::Media::Editing::MediaClip const*>(&clip), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&position), opacity));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaOverlayLayer> : produce_base<D, llm::OS::Media::Editing::IMediaOverlayLayer>
    {
        int32_t __stdcall Clone(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Editing::MediaOverlayLayer>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Overlays(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Editing::MediaOverlay>>(this->shim().Overlays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomCompositorDefinition(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::IVideoCompositorDefinition>(this->shim().CustomCompositorDefinition());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Editing::IMediaOverlayLayerFactory> : produce_base<D, llm::OS::Media::Editing::IMediaOverlayLayerFactory>
    {
        int32_t __stdcall CreateWithCompositorDefinition(void* compositorDefinition, void** mediaOverlayLayer) noexcept final try
        {
            clear_abi(mediaOverlayLayer);
            typename D::abi_guard guard(this->shim());
            *mediaOverlayLayer = detach_from<llm::OS::Media::Editing::MediaOverlayLayer>(this->shim().CreateWithCompositorDefinition(*reinterpret_cast<llm::OS::Media::Effects::IVideoCompositorDefinition const*>(&compositorDefinition)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Editing
{
    inline auto BackgroundAudioTrack::CreateFromEmbeddedAudioTrack(llm::OS::Media::Editing::EmbeddedAudioTrack const& embeddedAudioTrack)
    {
        return impl::call_factory<BackgroundAudioTrack, IBackgroundAudioTrackStatics>([&](IBackgroundAudioTrackStatics const& f) { return f.CreateFromEmbeddedAudioTrack(embeddedAudioTrack); });
    }
    inline auto BackgroundAudioTrack::CreateFromFileAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<BackgroundAudioTrack, IBackgroundAudioTrackStatics>([&](IBackgroundAudioTrackStatics const& f) { return f.CreateFromFileAsync(file); });
    }
    inline auto MediaClip::CreateFromColor(llm::OS::UI::Color const& color, llm::OS::Foundation::TimeSpan const& originalDuration)
    {
        return impl::call_factory<MediaClip, IMediaClipStatics>([&](IMediaClipStatics const& f) { return f.CreateFromColor(color, originalDuration); });
    }
    inline auto MediaClip::CreateFromFileAsync(llm::OS::Storage::IStorageFile const& file)
    {
        return impl::call_factory<MediaClip, IMediaClipStatics>([&](IMediaClipStatics const& f) { return f.CreateFromFileAsync(file); });
    }
    inline auto MediaClip::CreateFromImageFileAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Foundation::TimeSpan const& originalDuration)
    {
        return impl::call_factory<MediaClip, IMediaClipStatics>([&](IMediaClipStatics const& f) { return f.CreateFromImageFileAsync(file, originalDuration); });
    }
    inline auto MediaClip::CreateFromSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm::OS::Foundation::TimeSpan const& originalDuration)
    {
        return impl::call_factory<MediaClip, IMediaClipStatics2>([&](IMediaClipStatics2 const& f) { return f.CreateFromSurface(surface, originalDuration); });
    }
    inline MediaComposition::MediaComposition() :
        MediaComposition(impl::call_factory_cast<MediaComposition(*)(llm::OS::Foundation::IActivationFactory const&), MediaComposition>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaComposition>(); }))
    {
    }
    inline auto MediaComposition::LoadAsync(llm::OS::Storage::StorageFile const& file)
    {
        return impl::call_factory<MediaComposition, IMediaCompositionStatics>([&](IMediaCompositionStatics const& f) { return f.LoadAsync(file); });
    }
    inline MediaOverlay::MediaOverlay(llm::OS::Media::Editing::MediaClip const& clip) :
        MediaOverlay(impl::call_factory<MediaOverlay, IMediaOverlayFactory>([&](IMediaOverlayFactory const& f) { return f.Create(clip); }))
    {
    }
    inline MediaOverlay::MediaOverlay(llm::OS::Media::Editing::MediaClip const& clip, llm::OS::Foundation::Rect const& position, double opacity) :
        MediaOverlay(impl::call_factory<MediaOverlay, IMediaOverlayFactory>([&](IMediaOverlayFactory const& f) { return f.CreateWithPositionAndOpacity(clip, position, opacity); }))
    {
    }
    inline MediaOverlayLayer::MediaOverlayLayer() :
        MediaOverlayLayer(impl::call_factory_cast<MediaOverlayLayer(*)(llm::OS::Foundation::IActivationFactory const&), MediaOverlayLayer>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MediaOverlayLayer>(); }))
    {
    }
    inline MediaOverlayLayer::MediaOverlayLayer(llm::OS::Media::Effects::IVideoCompositorDefinition const& compositorDefinition) :
        MediaOverlayLayer(impl::call_factory<MediaOverlayLayer, IMediaOverlayLayerFactory>([&](IMediaOverlayLayerFactory const& f) { return f.CreateWithCompositorDefinition(compositorDefinition); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Editing::IBackgroundAudioTrack> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IBackgroundAudioTrackStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IEmbeddedAudioTrack> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaClipStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaClipStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaComposition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaComposition2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaCompositionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaOverlay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaOverlayFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaOverlayLayer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::IMediaOverlayLayerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::BackgroundAudioTrack> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::EmbeddedAudioTrack> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::MediaClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::MediaComposition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::MediaOverlay> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Editing::MediaOverlayLayer> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
