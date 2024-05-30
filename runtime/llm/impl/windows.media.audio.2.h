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
#ifndef LLM_OS_Media_Audio_2_H
#define LLM_OS_Media_Audio_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Capture.1.h"
#include "llm/impl/Windows.Media.Devices.1.h"
#include "llm/impl/Windows.Media.Effects.1.h"
#include "llm/impl/Windows.Media.Render.1.h"
#include "llm/impl/Windows.Media.Audio.1.h"
LLM_EXPORT namespace llm:OS::Media::Audio
{
    struct __declspec(empty_bases) AudioDeviceInputNode : llm:OS::Media::Audio::IAudioDeviceInputNode,
        impl::require<AudioDeviceInputNode, llm:OS::Media::Audio::IAudioInputNode2>
    {
        AudioDeviceInputNode(std::nullptr_t) noexcept {}
        AudioDeviceInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioDeviceInputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioDeviceOutputNode : llm:OS::Media::Audio::IAudioDeviceOutputNode,
        impl::require<AudioDeviceOutputNode, llm:OS::Media::Audio::IAudioNodeWithListener>
    {
        AudioDeviceOutputNode(std::nullptr_t) noexcept {}
        AudioDeviceOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioDeviceOutputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFileInputNode : llm:OS::Media::Audio::IAudioFileInputNode,
        impl::require<AudioFileInputNode, llm:OS::Media::Audio::IAudioInputNode2>
    {
        AudioFileInputNode(std::nullptr_t) noexcept {}
        AudioFileInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioFileInputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFileOutputNode : llm:OS::Media::Audio::IAudioFileOutputNode
    {
        AudioFileOutputNode(std::nullptr_t) noexcept {}
        AudioFileOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioFileOutputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFrameCompletedEventArgs : llm:OS::Media::Audio::IAudioFrameCompletedEventArgs
    {
        AudioFrameCompletedEventArgs(std::nullptr_t) noexcept {}
        AudioFrameCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioFrameCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFrameInputNode : llm:OS::Media::Audio::IAudioFrameInputNode,
        impl::require<AudioFrameInputNode, llm:OS::Media::Audio::IAudioInputNode2>
    {
        AudioFrameInputNode(std::nullptr_t) noexcept {}
        AudioFrameInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioFrameInputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioFrameOutputNode : llm:OS::Media::Audio::IAudioFrameOutputNode
    {
        AudioFrameOutputNode(std::nullptr_t) noexcept {}
        AudioFrameOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioFrameOutputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioGraph : llm:OS::Media::Audio::IAudioGraph,
        impl::require<AudioGraph, llm:OS::Media::Audio::IAudioGraph2, llm:OS::Media::Audio::IAudioGraph3>
    {
        AudioGraph(std::nullptr_t) noexcept {}
        AudioGraph(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioGraph(ptr, take_ownership_from_abi) {}
        using llm:OS::Media::Audio::IAudioGraph::CreateDeviceInputNodeAsync;
        using impl::consume_t<AudioGraph, llm:OS::Media::Audio::IAudioGraph2>::CreateDeviceInputNodeAsync;
        using llm:OS::Media::Audio::IAudioGraph::CreateFileInputNodeAsync;
        using impl::consume_t<AudioGraph, llm:OS::Media::Audio::IAudioGraph2>::CreateFileInputNodeAsync;
        using llm:OS::Media::Audio::IAudioGraph::CreateFrameInputNode;
        using impl::consume_t<AudioGraph, llm:OS::Media::Audio::IAudioGraph2>::CreateFrameInputNode;
        using llm:OS::Media::Audio::IAudioGraph::CreateSubmixNode;
        using impl::consume_t<AudioGraph, llm:OS::Media::Audio::IAudioGraph2>::CreateSubmixNode;
        static auto CreateAsync(llm:OS::Media::Audio::AudioGraphSettings const& settings);
    };
    struct __declspec(empty_bases) AudioGraphBatchUpdater : llm:OS::Foundation::IClosable
    {
        AudioGraphBatchUpdater(std::nullptr_t) noexcept {}
        AudioGraphBatchUpdater(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IClosable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioGraphConnection : llm:OS::Media::Audio::IAudioGraphConnection
    {
        AudioGraphConnection(std::nullptr_t) noexcept {}
        AudioGraphConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioGraphConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioGraphSettings : llm:OS::Media::Audio::IAudioGraphSettings,
        impl::require<AudioGraphSettings, llm:OS::Media::Audio::IAudioGraphSettings2>
    {
        AudioGraphSettings(std::nullptr_t) noexcept {}
        AudioGraphSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioGraphSettings(ptr, take_ownership_from_abi) {}
        explicit AudioGraphSettings(llm:OS::Media::Render::AudioRenderCategory const& audioRenderCategory);
    };
    struct __declspec(empty_bases) AudioGraphUnrecoverableErrorOccurredEventArgs : llm:OS::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs
    {
        AudioGraphUnrecoverableErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        AudioGraphUnrecoverableErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioNodeEmitter : llm:OS::Media::Audio::IAudioNodeEmitter,
        impl::require<AudioNodeEmitter, llm:OS::Media::Audio::IAudioNodeEmitter2>
    {
        AudioNodeEmitter(std::nullptr_t) noexcept {}
        AudioNodeEmitter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeEmitter(ptr, take_ownership_from_abi) {}
        AudioNodeEmitter();
        AudioNodeEmitter(llm:OS::Media::Audio::AudioNodeEmitterShape const& shape, llm:OS::Media::Audio::AudioNodeEmitterDecayModel const& decayModel, llm:OS::Media::Audio::AudioNodeEmitterSettings const& settings);
    };
    struct __declspec(empty_bases) AudioNodeEmitterConeProperties : llm:OS::Media::Audio::IAudioNodeEmitterConeProperties
    {
        AudioNodeEmitterConeProperties(std::nullptr_t) noexcept {}
        AudioNodeEmitterConeProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeEmitterConeProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioNodeEmitterDecayModel : llm:OS::Media::Audio::IAudioNodeEmitterDecayModel
    {
        AudioNodeEmitterDecayModel(std::nullptr_t) noexcept {}
        AudioNodeEmitterDecayModel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeEmitterDecayModel(ptr, take_ownership_from_abi) {}
        static auto CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance);
        static auto CreateCustom(double minGain, double maxGain);
    };
    struct __declspec(empty_bases) AudioNodeEmitterNaturalDecayModelProperties : llm:OS::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties
    {
        AudioNodeEmitterNaturalDecayModelProperties(std::nullptr_t) noexcept {}
        AudioNodeEmitterNaturalDecayModelProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioNodeEmitterShape : llm:OS::Media::Audio::IAudioNodeEmitterShape
    {
        AudioNodeEmitterShape(std::nullptr_t) noexcept {}
        AudioNodeEmitterShape(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeEmitterShape(ptr, take_ownership_from_abi) {}
        static auto CreateCone(double innerAngle, double outerAngle, double outerAngleGain);
        static auto CreateOmnidirectional();
    };
    struct __declspec(empty_bases) AudioNodeListener : llm:OS::Media::Audio::IAudioNodeListener
    {
        AudioNodeListener(std::nullptr_t) noexcept {}
        AudioNodeListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioNodeListener(ptr, take_ownership_from_abi) {}
        AudioNodeListener();
    };
    struct __declspec(empty_bases) AudioPlaybackConnection : llm:OS::Media::Audio::IAudioPlaybackConnection,
        impl::require<AudioPlaybackConnection, llm:OS::Foundation::IClosable>
    {
        AudioPlaybackConnection(std::nullptr_t) noexcept {}
        AudioPlaybackConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioPlaybackConnection(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto TryCreateFromId(param::hstring const& id);
    };
    struct __declspec(empty_bases) AudioPlaybackConnectionOpenResult : llm:OS::Media::Audio::IAudioPlaybackConnectionOpenResult
    {
        AudioPlaybackConnectionOpenResult(std::nullptr_t) noexcept {}
        AudioPlaybackConnectionOpenResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioPlaybackConnectionOpenResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioStateMonitor : llm:OS::Media::Audio::IAudioStateMonitor
    {
        AudioStateMonitor(std::nullptr_t) noexcept {}
        AudioStateMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioStateMonitor(ptr, take_ownership_from_abi) {}
        static auto CreateForRenderMonitoring();
        static auto CreateForRenderMonitoring(llm:OS::Media::Render::AudioRenderCategory const& category);
        static auto CreateForRenderMonitoring(llm:OS::Media::Render::AudioRenderCategory const& category, llm:OS::Media::Devices::AudioDeviceRole const& role);
        static auto CreateForRenderMonitoringWithCategoryAndDeviceId(llm:OS::Media::Render::AudioRenderCategory const& category, param::hstring const& deviceId);
        static auto CreateForCaptureMonitoring();
        static auto CreateForCaptureMonitoring(llm:OS::Media::Capture::MediaCategory const& category);
        static auto CreateForCaptureMonitoring(llm:OS::Media::Capture::MediaCategory const& category, llm:OS::Media::Devices::AudioDeviceRole const& role);
        static auto CreateForCaptureMonitoringWithCategoryAndDeviceId(llm:OS::Media::Capture::MediaCategory const& category, param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) AudioSubmixNode : llm:OS::Media::Audio::IAudioInputNode,
        impl::require<AudioSubmixNode, llm:OS::Media::Audio::IAudioInputNode2>
    {
        AudioSubmixNode(std::nullptr_t) noexcept {}
        AudioSubmixNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IAudioInputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateAudioDeviceInputNodeResult : llm:OS::Media::Audio::ICreateAudioDeviceInputNodeResult,
        impl::require<CreateAudioDeviceInputNodeResult, llm:OS::Media::Audio::ICreateAudioDeviceInputNodeResult2>
    {
        CreateAudioDeviceInputNodeResult(std::nullptr_t) noexcept {}
        CreateAudioDeviceInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateAudioDeviceInputNodeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateAudioDeviceOutputNodeResult : llm:OS::Media::Audio::ICreateAudioDeviceOutputNodeResult,
        impl::require<CreateAudioDeviceOutputNodeResult, llm:OS::Media::Audio::ICreateAudioDeviceOutputNodeResult2>
    {
        CreateAudioDeviceOutputNodeResult(std::nullptr_t) noexcept {}
        CreateAudioDeviceOutputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateAudioDeviceOutputNodeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateAudioFileInputNodeResult : llm:OS::Media::Audio::ICreateAudioFileInputNodeResult,
        impl::require<CreateAudioFileInputNodeResult, llm:OS::Media::Audio::ICreateAudioFileInputNodeResult2>
    {
        CreateAudioFileInputNodeResult(std::nullptr_t) noexcept {}
        CreateAudioFileInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateAudioFileInputNodeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateAudioFileOutputNodeResult : llm:OS::Media::Audio::ICreateAudioFileOutputNodeResult,
        impl::require<CreateAudioFileOutputNodeResult, llm:OS::Media::Audio::ICreateAudioFileOutputNodeResult2>
    {
        CreateAudioFileOutputNodeResult(std::nullptr_t) noexcept {}
        CreateAudioFileOutputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateAudioFileOutputNodeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateAudioGraphResult : llm:OS::Media::Audio::ICreateAudioGraphResult,
        impl::require<CreateAudioGraphResult, llm:OS::Media::Audio::ICreateAudioGraphResult2>
    {
        CreateAudioGraphResult(std::nullptr_t) noexcept {}
        CreateAudioGraphResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateAudioGraphResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CreateMediaSourceAudioInputNodeResult : llm:OS::Media::Audio::ICreateMediaSourceAudioInputNodeResult,
        impl::require<CreateMediaSourceAudioInputNodeResult, llm:OS::Media::Audio::ICreateMediaSourceAudioInputNodeResult2>
    {
        CreateMediaSourceAudioInputNodeResult(std::nullptr_t) noexcept {}
        CreateMediaSourceAudioInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ICreateMediaSourceAudioInputNodeResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EchoEffectDefinition : llm:OS::Media::Audio::IEchoEffectDefinition
    {
        EchoEffectDefinition(std::nullptr_t) noexcept {}
        EchoEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IEchoEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit EchoEffectDefinition(llm:OS::Media::Audio::AudioGraph const& audioGraph);
    };
    struct __declspec(empty_bases) EqualizerBand : llm:OS::Media::Audio::IEqualizerBand
    {
        EqualizerBand(std::nullptr_t) noexcept {}
        EqualizerBand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IEqualizerBand(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EqualizerEffectDefinition : llm:OS::Media::Audio::IEqualizerEffectDefinition
    {
        EqualizerEffectDefinition(std::nullptr_t) noexcept {}
        EqualizerEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IEqualizerEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit EqualizerEffectDefinition(llm:OS::Media::Audio::AudioGraph const& audioGraph);
    };
    struct __declspec(empty_bases) FrameInputNodeQuantumStartedEventArgs : llm:OS::Media::Audio::IFrameInputNodeQuantumStartedEventArgs
    {
        FrameInputNodeQuantumStartedEventArgs(std::nullptr_t) noexcept {}
        FrameInputNodeQuantumStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IFrameInputNodeQuantumStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LimiterEffectDefinition : llm:OS::Media::Audio::ILimiterEffectDefinition
    {
        LimiterEffectDefinition(std::nullptr_t) noexcept {}
        LimiterEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ILimiterEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit LimiterEffectDefinition(llm:OS::Media::Audio::AudioGraph const& audioGraph);
    };
    struct __declspec(empty_bases) MediaSourceAudioInputNode : llm:OS::Media::Audio::IMediaSourceAudioInputNode
    {
        MediaSourceAudioInputNode(std::nullptr_t) noexcept {}
        MediaSourceAudioInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IMediaSourceAudioInputNode(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ReverbEffectDefinition : llm:OS::Media::Audio::IReverbEffectDefinition
    {
        ReverbEffectDefinition(std::nullptr_t) noexcept {}
        ReverbEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::IReverbEffectDefinition(ptr, take_ownership_from_abi) {}
        explicit ReverbEffectDefinition(llm:OS::Media::Audio::AudioGraph const& audioGraph);
    };
    struct __declspec(empty_bases) SetDefaultSpatialAudioFormatResult : llm:OS::Media::Audio::ISetDefaultSpatialAudioFormatResult
    {
        SetDefaultSpatialAudioFormatResult(std::nullptr_t) noexcept {}
        SetDefaultSpatialAudioFormatResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ISetDefaultSpatialAudioFormatResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialAudioDeviceConfiguration : llm:OS::Media::Audio::ISpatialAudioDeviceConfiguration
    {
        SpatialAudioDeviceConfiguration(std::nullptr_t) noexcept {}
        SpatialAudioDeviceConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ISpatialAudioDeviceConfiguration(ptr, take_ownership_from_abi) {}
        static auto GetForDeviceId(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) SpatialAudioFormatConfiguration : llm:OS::Media::Audio::ISpatialAudioFormatConfiguration
    {
        SpatialAudioFormatConfiguration(std::nullptr_t) noexcept {}
        SpatialAudioFormatConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Audio::ISpatialAudioFormatConfiguration(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct SpatialAudioFormatSubtype
    {
        SpatialAudioFormatSubtype() = delete;
        [[nodiscard]] static auto WindowsSonic();
        [[nodiscard]] static auto DolbyAtmosForHeadphones();
        [[nodiscard]] static auto DolbyAtmosForHomeTheater();
        [[nodiscard]] static auto DolbyAtmosForSpeakers();
        [[nodiscard]] static auto DTSHeadphoneX();
        [[nodiscard]] static auto DTSXUltra();
        [[nodiscard]] static auto DTSXForHomeTheater();
    };
}
#endif
