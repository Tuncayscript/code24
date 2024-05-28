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
#ifndef LLM_OS_Media_Effects_H
#define LLM_OS_Media_Effects_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Capture.2.h"
#include "llm/impl/Windows.Media.Editing.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Media.Playback.2.h"
#include "llm/impl/Windows.Media.Render.2.h"
#include "llm/impl/Windows.Media.Transcoding.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Media.Effects.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioCaptureEffectsManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioCaptureEffectsManager)->add_AudioCaptureEffectsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged_revoker consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioCaptureEffectsManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AudioCaptureEffectsChanged_revoker>(this, AudioCaptureEffectsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioCaptureEffectsManager)->remove_AudioCaptureEffectsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>) consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>::GetAudioCaptureEffects() const
    {
        void* effects{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioCaptureEffectsManager)->GetAudioCaptureEffects(&effects));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>{ effects, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioEffectType) consume_Windows_Media_Effects_IAudioEffect<D>::AudioEffectType() const
    {
        llm::OS::Media::Effects::AudioEffectType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffect)->get_AudioEffectType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Effects_IAudioEffectDefinition<D>::ActivatableClassId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectDefinition)->get_ActivatableClassId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_Media_Effects_IAudioEffectDefinition<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectDefinition)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioEffectDefinition) consume_Windows_Media_Effects_IAudioEffectDefinitionFactory<D>::Create(param::hstring const& activatableClassId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectDefinitionFactory)->Create(*(void**)(&activatableClassId), &value));
        return llm::OS::Media::Effects::AudioEffectDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioEffectDefinition) consume_Windows_Media_Effects_IAudioEffectDefinitionFactory<D>::CreateWithProperties(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectDefinitionFactory)->CreateWithProperties(*(void**)(&activatableClassId), *(void**)(&props), &value));
        return llm::OS::Media::Effects::AudioEffectDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioRenderEffectsManager) consume_Windows_Media_Effects_IAudioEffectsManagerStatics<D>::CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm::OS::Media::Render::AudioRenderCategory const& category) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectsManagerStatics)->CreateAudioRenderEffectsManager(*(void**)(&deviceId), static_cast<int32_t>(category), &value));
        return llm::OS::Media::Effects::AudioRenderEffectsManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioRenderEffectsManager) consume_Windows_Media_Effects_IAudioEffectsManagerStatics<D>::CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm::OS::Media::Render::AudioRenderCategory const& category, llm::OS::Media::AudioProcessing const& mode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectsManagerStatics)->CreateAudioRenderEffectsManagerWithMode(*(void**)(&deviceId), static_cast<int32_t>(category), static_cast<int32_t>(mode), &value));
        return llm::OS::Media::Effects::AudioRenderEffectsManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioCaptureEffectsManager) consume_Windows_Media_Effects_IAudioEffectsManagerStatics<D>::CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm::OS::Media::Capture::MediaCategory const& category) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectsManagerStatics)->CreateAudioCaptureEffectsManager(*(void**)(&deviceId), static_cast<int32_t>(category), &value));
        return llm::OS::Media::Effects::AudioCaptureEffectsManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::AudioCaptureEffectsManager) consume_Windows_Media_Effects_IAudioEffectsManagerStatics<D>::CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm::OS::Media::Capture::MediaCategory const& category, llm::OS::Media::AudioProcessing const& mode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioEffectsManagerStatics)->CreateAudioCaptureEffectsManagerWithMode(*(void**)(&deviceId), static_cast<int32_t>(category), static_cast<int32_t>(mode), &value));
        return llm::OS::Media::Effects::AudioCaptureEffectsManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioRenderEffectsManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager)->add_AudioRenderEffectsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged_revoker consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioRenderEffectsManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AudioRenderEffectsChanged_revoker>(this, AudioRenderEffectsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager)->remove_AudioRenderEffectsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>) consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>::GetAudioRenderEffects() const
    {
        void* effects{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager)->GetAudioRenderEffects(&effects));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>{ effects, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamWithContentType) consume_Windows_Media_Effects_IAudioRenderEffectsManager2<D>::EffectsProviderThumbnail() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager2)->get_EffectsProviderThumbnail(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamWithContentType{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Effects_IAudioRenderEffectsManager2<D>::EffectsProviderSettingsLabel() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager2)->get_EffectsProviderSettingsLabel(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IAudioRenderEffectsManager2<D>::ShowSettingsUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IAudioRenderEffectsManager2)->ShowSettingsUI());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Effects_IBasicAudioEffect<D>::UseInputFrameForOutput() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->get_UseInputFrameForOutput(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::AudioEncodingProperties>) consume_Windows_Media_Effects_IBasicAudioEffect<D>::SupportedEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->get_SupportedEncodingProperties(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::AudioEncodingProperties>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicAudioEffect<D>::SetEncodingProperties(llm::OS::Media::MediaProperties::AudioEncodingProperties const& encodingProperties) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->SetEncodingProperties(*(void**)(&encodingProperties)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicAudioEffect<D>::ProcessFrame(llm::OS::Media::Effects::ProcessAudioFrameContext const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->ProcessFrame(*(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicAudioEffect<D>::Close(llm::OS::Media::Effects::MediaEffectClosedReason const& reason) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->Close(static_cast<int32_t>(reason)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicAudioEffect<D>::DiscardQueuedFrames() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicAudioEffect)->DiscardQueuedFrames());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Effects_IBasicVideoEffect<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::MediaMemoryTypes) consume_Windows_Media_Effects_IBasicVideoEffect<D>::SupportedMemoryTypes() const
    {
        llm::OS::Media::Effects::MediaMemoryTypes value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->get_SupportedMemoryTypes(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Effects_IBasicVideoEffect<D>::TimeIndependent() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->get_TimeIndependent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::VideoEncodingProperties>) consume_Windows_Media_Effects_IBasicVideoEffect<D>::SupportedEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->get_SupportedEncodingProperties(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::VideoEncodingProperties>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicVideoEffect<D>::SetEncodingProperties(llm::OS::Media::MediaProperties::VideoEncodingProperties const& encodingProperties, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->SetEncodingProperties(*(void**)(&encodingProperties), *(void**)(&device)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicVideoEffect<D>::ProcessFrame(llm::OS::Media::Effects::ProcessVideoFrameContext const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->ProcessFrame(*(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicVideoEffect<D>::Close(llm::OS::Media::Effects::MediaEffectClosedReason const& reason) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->Close(static_cast<int32_t>(reason)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IBasicVideoEffect<D>::DiscardQueuedFrames() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IBasicVideoEffect)->DiscardQueuedFrames());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>) consume_Windows_Media_Effects_ICompositeVideoFrameContext<D>::SurfacesToOverlay() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::ICompositeVideoFrameContext)->get_SurfacesToOverlay(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Media_Effects_ICompositeVideoFrameContext<D>::BackgroundFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::ICompositeVideoFrameContext)->get_BackgroundFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Media_Effects_ICompositeVideoFrameContext<D>::OutputFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::ICompositeVideoFrameContext)->get_OutputFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Editing::MediaOverlay) consume_Windows_Media_Effects_ICompositeVideoFrameContext<D>::GetOverlayForSurface(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surfaceToOverlay) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::ICompositeVideoFrameContext)->GetOverlayForSurface(*(void**)(&surfaceToOverlay), &value));
        return llm::OS::Media::Editing::MediaOverlay{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AudioFrame) consume_Windows_Media_Effects_IProcessAudioFrameContext<D>::InputFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IProcessAudioFrameContext)->get_InputFrame(&value));
        return llm::OS::Media::AudioFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AudioFrame) consume_Windows_Media_Effects_IProcessAudioFrameContext<D>::OutputFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IProcessAudioFrameContext)->get_OutputFrame(&value));
        return llm::OS::Media::AudioFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Media_Effects_IProcessVideoFrameContext<D>::InputFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IProcessVideoFrameContext)->get_InputFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Media_Effects_IProcessVideoFrameContext<D>::OutputFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IProcessVideoFrameContext)->get_OutputFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Effects_IVideoCompositor<D>::TimeIndependent() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositor)->get_TimeIndependent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoCompositor<D>::SetEncodingProperties(llm::OS::Media::MediaProperties::VideoEncodingProperties const& backgroundProperties, llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositor)->SetEncodingProperties(*(void**)(&backgroundProperties), *(void**)(&device)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoCompositor<D>::CompositeFrame(llm::OS::Media::Effects::CompositeVideoFrameContext const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositor)->CompositeFrame(*(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoCompositor<D>::Close(llm::OS::Media::Effects::MediaEffectClosedReason const& reason) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositor)->Close(static_cast<int32_t>(reason)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoCompositor<D>::DiscardQueuedFrames() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositor)->DiscardQueuedFrames());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Effects_IVideoCompositorDefinition<D>::ActivatableClassId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositorDefinition)->get_ActivatableClassId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_Media_Effects_IVideoCompositorDefinition<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositorDefinition)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::VideoCompositorDefinition) consume_Windows_Media_Effects_IVideoCompositorDefinitionFactory<D>::Create(param::hstring const& activatableClassId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositorDefinitionFactory)->Create(*(void**)(&activatableClassId), &value));
        return llm::OS::Media::Effects::VideoCompositorDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::VideoCompositorDefinition) consume_Windows_Media_Effects_IVideoCompositorDefinitionFactory<D>::CreateWithProperties(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoCompositorDefinitionFactory)->CreateWithProperties(*(void**)(&activatableClassId), *(void**)(&props), &value));
        return llm::OS::Media::Effects::VideoCompositorDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Effects_IVideoEffectDefinition<D>::ActivatableClassId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoEffectDefinition)->get_ActivatableClassId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_Media_Effects_IVideoEffectDefinition<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoEffectDefinition)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::VideoEffectDefinition) consume_Windows_Media_Effects_IVideoEffectDefinitionFactory<D>::Create(param::hstring const& activatableClassId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoEffectDefinitionFactory)->Create(*(void**)(&activatableClassId), &value));
        return llm::OS::Media::Effects::VideoEffectDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::VideoEffectDefinition) consume_Windows_Media_Effects_IVideoEffectDefinitionFactory<D>::CreateWithProperties(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoEffectDefinitionFactory)->CreateWithProperties(*(void**)(&activatableClassId), *(void**)(&props), &value));
        return llm::OS::Media::Effects::VideoEffectDefinition{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::PaddingColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_PaddingColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::PaddingColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_PaddingColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::OutputSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_OutputSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::OutputSize(llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_OutputSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::CropRectangle() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_CropRectangle(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::CropRectangle(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_CropRectangle(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaRotation) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::Rotation() const
    {
        llm::OS::Media::MediaProperties::MediaRotation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_Rotation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::Rotation(llm::OS::Media::MediaProperties::MediaRotation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_Rotation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaMirroringOptions) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::Mirror() const
    {
        llm::OS::Media::MediaProperties::MediaMirroringOptions value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_Mirror(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::Mirror(llm::OS::Media::MediaProperties::MediaMirroringOptions const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_Mirror(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::ProcessingAlgorithm(llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->put_ProcessingAlgorithm(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm) consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>::ProcessingAlgorithm() const
    {
        llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition)->get_ProcessingAlgorithm(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Effects::VideoTransformSphericalProjection) consume_Windows_Media_Effects_IVideoTransformEffectDefinition2<D>::SphericalProjection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformEffectDefinition2)->get_SphericalProjection(&value));
        return llm::OS::Media::Effects::VideoTransformSphericalProjection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::SphericalVideoFrameFormat) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::FrameFormat() const
    {
        llm::OS::Media::MediaProperties::SphericalVideoFrameFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->get_FrameFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::FrameFormat(llm::OS::Media::MediaProperties::SphericalVideoFrameFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->put_FrameFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Playback::SphericalVideoProjectionMode) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::ProjectionMode() const
    {
        llm::OS::Media::Playback::SphericalVideoProjectionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->get_ProjectionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::ProjectionMode(llm::OS::Media::Playback::SphericalVideoProjectionMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->put_ProjectionMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::HorizontalFieldOfViewInDegrees() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->get_HorizontalFieldOfViewInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::HorizontalFieldOfViewInDegrees(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->put_HorizontalFieldOfViewInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::ViewOrientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->get_ViewOrientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>::ViewOrientation(llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Effects::IVideoTransformSphericalProjection)->put_ViewOrientation(impl::bind_in(value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioCaptureEffectsManager> : produce_base<D, llm::OS::Media::Effects::IAudioCaptureEffectsManager>
    {
        int32_t __stdcall add_AudioCaptureEffectsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AudioCaptureEffectsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioCaptureEffectsManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AudioCaptureEffectsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioCaptureEffectsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetAudioCaptureEffects(void** effects) noexcept final try
        {
            clear_abi(effects);
            typename D::abi_guard guard(this->shim());
            *effects = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>>(this->shim().GetAudioCaptureEffects());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioEffect> : produce_base<D, llm::OS::Media::Effects::IAudioEffect>
    {
        int32_t __stdcall get_AudioEffectType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioEffectType>(this->shim().AudioEffectType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioEffectDefinition> : produce_base<D, llm::OS::Media::Effects::IAudioEffectDefinition>
    {
        int32_t __stdcall get_ActivatableClassId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActivatableClassId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioEffectDefinitionFactory> : produce_base<D, llm::OS::Media::Effects::IAudioEffectDefinitionFactory>
    {
        int32_t __stdcall Create(void* activatableClassId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioEffectDefinition>(this->shim().Create(*reinterpret_cast<hstring const*>(&activatableClassId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithProperties(void* activatableClassId, void* props, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioEffectDefinition>(this->shim().CreateWithProperties(*reinterpret_cast<hstring const*>(&activatableClassId), *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&props)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioEffectsManagerStatics> : produce_base<D, llm::OS::Media::Effects::IAudioEffectsManagerStatics>
    {
        int32_t __stdcall CreateAudioRenderEffectsManager(void* deviceId, int32_t category, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioRenderEffectsManager>(this->shim().CreateAudioRenderEffectsManager(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Media::Render::AudioRenderCategory const*>(&category)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAudioRenderEffectsManagerWithMode(void* deviceId, int32_t category, int32_t mode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioRenderEffectsManager>(this->shim().CreateAudioRenderEffectsManager(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Media::Render::AudioRenderCategory const*>(&category), *reinterpret_cast<llm::OS::Media::AudioProcessing const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAudioCaptureEffectsManager(void* deviceId, int32_t category, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioCaptureEffectsManager>(this->shim().CreateAudioCaptureEffectsManager(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Media::Capture::MediaCategory const*>(&category)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAudioCaptureEffectsManagerWithMode(void* deviceId, int32_t category, int32_t mode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::AudioCaptureEffectsManager>(this->shim().CreateAudioCaptureEffectsManager(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Media::Capture::MediaCategory const*>(&category), *reinterpret_cast<llm::OS::Media::AudioProcessing const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioRenderEffectsManager> : produce_base<D, llm::OS::Media::Effects::IAudioRenderEffectsManager>
    {
        int32_t __stdcall add_AudioRenderEffectsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AudioRenderEffectsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Effects::AudioRenderEffectsManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AudioRenderEffectsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioRenderEffectsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetAudioRenderEffects(void** effects) noexcept final try
        {
            clear_abi(effects);
            typename D::abi_guard guard(this->shim());
            *effects = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Effects::AudioEffect>>(this->shim().GetAudioRenderEffects());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IAudioRenderEffectsManager2> : produce_base<D, llm::OS::Media::Effects::IAudioRenderEffectsManager2>
    {
        int32_t __stdcall get_EffectsProviderThumbnail(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>(this->shim().EffectsProviderThumbnail());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EffectsProviderSettingsLabel(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EffectsProviderSettingsLabel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowSettingsUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowSettingsUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IBasicAudioEffect> : produce_base<D, llm::OS::Media::Effects::IBasicAudioEffect>
    {
        int32_t __stdcall get_UseInputFrameForOutput(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().UseInputFrameForOutput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::AudioEncodingProperties>>(this->shim().SupportedEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEncodingProperties(void* encodingProperties) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<llm::OS::Media::MediaProperties::AudioEncodingProperties const*>(&encodingProperties));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProcessFrame(void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessFrame(*reinterpret_cast<llm::OS::Media::Effects::ProcessAudioFrameContext const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close(int32_t reason) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(*reinterpret_cast<llm::OS::Media::Effects::MediaEffectClosedReason const*>(&reason));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscardQueuedFrames() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IBasicVideoEffect> : produce_base<D, llm::OS::Media::Effects::IBasicVideoEffect>
    {
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedMemoryTypes(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::MediaMemoryTypes>(this->shim().SupportedMemoryTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeIndependent(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().TimeIndependent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::MediaProperties::VideoEncodingProperties>>(this->shim().SupportedEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEncodingProperties(void* encodingProperties, void* device) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<llm::OS::Media::MediaProperties::VideoEncodingProperties const*>(&encodingProperties), *reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const*>(&device));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProcessFrame(void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessFrame(*reinterpret_cast<llm::OS::Media::Effects::ProcessVideoFrameContext const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close(int32_t reason) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(*reinterpret_cast<llm::OS::Media::Effects::MediaEffectClosedReason const*>(&reason));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscardQueuedFrames() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::ICompositeVideoFrameContext> : produce_base<D, llm::OS::Media::Effects::ICompositeVideoFrameContext>
    {
        int32_t __stdcall get_SurfacesToOverlay(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>>(this->shim().SurfacesToOverlay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().BackgroundFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().OutputFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOverlayForSurface(void* surfaceToOverlay, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Editing::MediaOverlay>(this->shim().GetOverlayForSurface(*reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const*>(&surfaceToOverlay)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IProcessAudioFrameContext> : produce_base<D, llm::OS::Media::Effects::IProcessAudioFrameContext>
    {
        int32_t __stdcall get_InputFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::AudioFrame>(this->shim().InputFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::AudioFrame>(this->shim().OutputFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IProcessVideoFrameContext> : produce_base<D, llm::OS::Media::Effects::IProcessVideoFrameContext>
    {
        int32_t __stdcall get_InputFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().InputFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().OutputFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoCompositor> : produce_base<D, llm::OS::Media::Effects::IVideoCompositor>
    {
        int32_t __stdcall get_TimeIndependent(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().TimeIndependent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEncodingProperties(void* backgroundProperties, void* device) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<llm::OS::Media::MediaProperties::VideoEncodingProperties const*>(&backgroundProperties), *reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const*>(&device));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CompositeFrame(void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositeFrame(*reinterpret_cast<llm::OS::Media::Effects::CompositeVideoFrameContext const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close(int32_t reason) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(*reinterpret_cast<llm::OS::Media::Effects::MediaEffectClosedReason const*>(&reason));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscardQueuedFrames() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoCompositorDefinition> : produce_base<D, llm::OS::Media::Effects::IVideoCompositorDefinition>
    {
        int32_t __stdcall get_ActivatableClassId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActivatableClassId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoCompositorDefinitionFactory> : produce_base<D, llm::OS::Media::Effects::IVideoCompositorDefinitionFactory>
    {
        int32_t __stdcall Create(void* activatableClassId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::VideoCompositorDefinition>(this->shim().Create(*reinterpret_cast<hstring const*>(&activatableClassId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithProperties(void* activatableClassId, void* props, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::VideoCompositorDefinition>(this->shim().CreateWithProperties(*reinterpret_cast<hstring const*>(&activatableClassId), *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&props)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoEffectDefinition> : produce_base<D, llm::OS::Media::Effects::IVideoEffectDefinition>
    {
        int32_t __stdcall get_ActivatableClassId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActivatableClassId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoEffectDefinitionFactory> : produce_base<D, llm::OS::Media::Effects::IVideoEffectDefinitionFactory>
    {
        int32_t __stdcall Create(void* activatableClassId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::VideoEffectDefinition>(this->shim().Create(*reinterpret_cast<hstring const*>(&activatableClassId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithProperties(void* activatableClassId, void* props, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::VideoEffectDefinition>(this->shim().CreateWithProperties(*reinterpret_cast<hstring const*>(&activatableClassId), *reinterpret_cast<llm::OS::Foundation::Collections::IPropertySet const*>(&props)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoTransformEffectDefinition> : produce_base<D, llm::OS::Media::Effects::IVideoTransformEffectDefinition>
    {
        int32_t __stdcall get_PaddingColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().PaddingColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PaddingColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PaddingColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().OutputSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OutputSize(llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutputSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CropRectangle(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().CropRectangle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CropRectangle(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CropRectangle(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rotation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaRotation>(this->shim().Rotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rotation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(*reinterpret_cast<llm::OS::Media::MediaProperties::MediaRotation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mirror(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaMirroringOptions>(this->shim().Mirror());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mirror(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mirror(*reinterpret_cast<llm::OS::Media::MediaProperties::MediaMirroringOptions const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProcessingAlgorithm(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessingAlgorithm(*reinterpret_cast<llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessingAlgorithm(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Transcoding::MediaVideoProcessingAlgorithm>(this->shim().ProcessingAlgorithm());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoTransformEffectDefinition2> : produce_base<D, llm::OS::Media::Effects::IVideoTransformEffectDefinition2>
    {
        int32_t __stdcall get_SphericalProjection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Effects::VideoTransformSphericalProjection>(this->shim().SphericalProjection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Effects::IVideoTransformSphericalProjection> : produce_base<D, llm::OS::Media::Effects::IVideoTransformSphericalProjection>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::SphericalVideoFrameFormat>(this->shim().FrameFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FrameFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameFormat(*reinterpret_cast<llm::OS::Media::MediaProperties::SphericalVideoFrameFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProjectionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Playback::SphericalVideoProjectionMode>(this->shim().ProjectionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProjectionMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectionMode(*reinterpret_cast<llm::OS::Media::Playback::SphericalVideoProjectionMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HorizontalFieldOfViewInDegrees(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().HorizontalFieldOfViewInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HorizontalFieldOfViewInDegrees(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalFieldOfViewInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ViewOrientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().ViewOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewOrientation(llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewOrientation(*reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Effects
{
    inline AudioEffectDefinition::AudioEffectDefinition(param::hstring const& activatableClassId) :
        AudioEffectDefinition(impl::call_factory<AudioEffectDefinition, IAudioEffectDefinitionFactory>([&](IAudioEffectDefinitionFactory const& f) { return f.Create(activatableClassId); }))
    {
    }
    inline AudioEffectDefinition::AudioEffectDefinition(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) :
        AudioEffectDefinition(impl::call_factory<AudioEffectDefinition, IAudioEffectDefinitionFactory>([&](IAudioEffectDefinitionFactory const& f) { return f.CreateWithProperties(activatableClassId, props); }))
    {
    }
    inline auto AudioEffectsManager::CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm::OS::Media::Render::AudioRenderCategory const& category)
    {
        return impl::call_factory<AudioEffectsManager, IAudioEffectsManagerStatics>([&](IAudioEffectsManagerStatics const& f) { return f.CreateAudioRenderEffectsManager(deviceId, category); });
    }
    inline auto AudioEffectsManager::CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm::OS::Media::Render::AudioRenderCategory const& category, llm::OS::Media::AudioProcessing const& mode)
    {
        return impl::call_factory<AudioEffectsManager, IAudioEffectsManagerStatics>([&](IAudioEffectsManagerStatics const& f) { return f.CreateAudioRenderEffectsManager(deviceId, category, mode); });
    }
    inline auto AudioEffectsManager::CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm::OS::Media::Capture::MediaCategory const& category)
    {
        return impl::call_factory<AudioEffectsManager, IAudioEffectsManagerStatics>([&](IAudioEffectsManagerStatics const& f) { return f.CreateAudioCaptureEffectsManager(deviceId, category); });
    }
    inline auto AudioEffectsManager::CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm::OS::Media::Capture::MediaCategory const& category, llm::OS::Media::AudioProcessing const& mode)
    {
        return impl::call_factory<AudioEffectsManager, IAudioEffectsManagerStatics>([&](IAudioEffectsManagerStatics const& f) { return f.CreateAudioCaptureEffectsManager(deviceId, category, mode); });
    }
    inline VideoCompositorDefinition::VideoCompositorDefinition(param::hstring const& activatableClassId) :
        VideoCompositorDefinition(impl::call_factory<VideoCompositorDefinition, IVideoCompositorDefinitionFactory>([&](IVideoCompositorDefinitionFactory const& f) { return f.Create(activatableClassId); }))
    {
    }
    inline VideoCompositorDefinition::VideoCompositorDefinition(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) :
        VideoCompositorDefinition(impl::call_factory<VideoCompositorDefinition, IVideoCompositorDefinitionFactory>([&](IVideoCompositorDefinitionFactory const& f) { return f.CreateWithProperties(activatableClassId, props); }))
    {
    }
    inline VideoEffectDefinition::VideoEffectDefinition(param::hstring const& activatableClassId) :
        VideoEffectDefinition(impl::call_factory<VideoEffectDefinition, IVideoEffectDefinitionFactory>([&](IVideoEffectDefinitionFactory const& f) { return f.Create(activatableClassId); }))
    {
    }
    inline VideoEffectDefinition::VideoEffectDefinition(param::hstring const& activatableClassId, llm::OS::Foundation::Collections::IPropertySet const& props) :
        VideoEffectDefinition(impl::call_factory<VideoEffectDefinition, IVideoEffectDefinitionFactory>([&](IVideoEffectDefinitionFactory const& f) { return f.CreateWithProperties(activatableClassId, props); }))
    {
    }
    inline VideoTransformEffectDefinition::VideoTransformEffectDefinition() :
        VideoTransformEffectDefinition(impl::call_factory_cast<VideoTransformEffectDefinition(*)(llm::OS::Foundation::IActivationFactory const&), VideoTransformEffectDefinition>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VideoTransformEffectDefinition>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Effects::IAudioCaptureEffectsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioEffectDefinitionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioEffectsManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioRenderEffectsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IAudioRenderEffectsManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IBasicAudioEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IBasicVideoEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::ICompositeVideoFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IProcessAudioFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IProcessVideoFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoCompositor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoCompositorDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoCompositorDefinitionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoEffectDefinitionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoTransformEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoTransformEffectDefinition2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::IVideoTransformSphericalProjection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::AudioCaptureEffectsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::AudioEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::AudioEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::AudioEffectsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::AudioRenderEffectsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::CompositeVideoFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::ProcessAudioFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::ProcessVideoFrameContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::VideoCompositorDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::VideoEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::VideoTransformEffectDefinition> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Effects::VideoTransformSphericalProjection> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
