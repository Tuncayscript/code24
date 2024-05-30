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
#ifndef LLM_OS_Media_Audio_1_H
#define LLM_OS_Media_Audio_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.Effects.0.h"
#include "llm/impl/Windows.Media.Audio.0.h"
LLM_EXPORT namespace llm:OS::Media::Audio
{
    struct __declspec(empty_bases) IAudioDeviceInputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioDeviceInputNode>,
        impl::require<llm:OS::Media::Audio::IAudioDeviceInputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode, llm:OS::Media::Audio::IAudioInputNode>
    {
        IAudioDeviceInputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioDeviceInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioDeviceOutputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioDeviceOutputNode>,
        impl::require<llm:OS::Media::Audio::IAudioDeviceOutputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode>
    {
        IAudioDeviceOutputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioDeviceOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFileInputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFileInputNode>,
        impl::require<llm:OS::Media::Audio::IAudioFileInputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode, llm:OS::Media::Audio::IAudioInputNode>
    {
        IAudioFileInputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioFileInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFileOutputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFileOutputNode>,
        impl::require<llm:OS::Media::Audio::IAudioFileOutputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode>
    {
        IAudioFileOutputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioFileOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFrameCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFrameCompletedEventArgs>
    {
        IAudioFrameCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAudioFrameCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFrameInputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFrameInputNode>,
        impl::require<llm:OS::Media::Audio::IAudioFrameInputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode, llm:OS::Media::Audio::IAudioInputNode>
    {
        IAudioFrameInputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioFrameInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioFrameOutputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioFrameOutputNode>,
        impl::require<llm:OS::Media::Audio::IAudioFrameOutputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode>
    {
        IAudioFrameOutputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioFrameOutputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraph :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraph>,
        impl::require<llm:OS::Media::Audio::IAudioGraph, llm:OS::Foundation::IClosable>
    {
        IAudioGraph(std::nullptr_t = nullptr) noexcept {}
        IAudioGraph(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraph2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraph2>,
        impl::require<llm:OS::Media::Audio::IAudioGraph2, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioGraph>
    {
        IAudioGraph2(std::nullptr_t = nullptr) noexcept {}
        IAudioGraph2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IAudioGraph2, IAudioGraph2>::CreateDeviceInputNodeAsync;
        using impl::consume_t<IAudioGraph2, llm:OS::Media::Audio::IAudioGraph>::CreateDeviceInputNodeAsync;
        using impl::consume_t<IAudioGraph2, IAudioGraph2>::CreateFileInputNodeAsync;
        using impl::consume_t<IAudioGraph2, llm:OS::Media::Audio::IAudioGraph>::CreateFileInputNodeAsync;
        using impl::consume_t<IAudioGraph2, IAudioGraph2>::CreateFrameInputNode;
        using impl::consume_t<IAudioGraph2, llm:OS::Media::Audio::IAudioGraph>::CreateFrameInputNode;
        using impl::consume_t<IAudioGraph2, IAudioGraph2>::CreateSubmixNode;
        using impl::consume_t<IAudioGraph2, llm:OS::Media::Audio::IAudioGraph>::CreateSubmixNode;
    };
    struct __declspec(empty_bases) IAudioGraph3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraph3>
    {
        IAudioGraph3(std::nullptr_t = nullptr) noexcept {}
        IAudioGraph3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphConnection>
    {
        IAudioGraphConnection(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphSettings>
    {
        IAudioGraphSettings(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphSettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphSettings2>
    {
        IAudioGraphSettings2(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphSettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphSettingsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphSettingsFactory>
    {
        IAudioGraphSettingsFactory(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphSettingsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphStatics>
    {
        IAudioGraphStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioGraphUnrecoverableErrorOccurredEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioGraphUnrecoverableErrorOccurredEventArgs>
    {
        IAudioGraphUnrecoverableErrorOccurredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAudioGraphUnrecoverableErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioInputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioInputNode>,
        impl::require<llm:OS::Media::Audio::IAudioInputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode>
    {
        IAudioInputNode(std::nullptr_t = nullptr) noexcept {}
        IAudioInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioInputNode2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioInputNode2>,
        impl::require<llm:OS::Media::Audio::IAudioInputNode2, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode, llm:OS::Media::Audio::IAudioInputNode>
    {
        IAudioInputNode2(std::nullptr_t = nullptr) noexcept {}
        IAudioInputNode2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNode>,
        impl::require<llm:OS::Media::Audio::IAudioNode, llm:OS::Foundation::IClosable>
    {
        IAudioNode(std::nullptr_t = nullptr) noexcept {}
        IAudioNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitter>
    {
        IAudioNodeEmitter(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitter2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitter2>
    {
        IAudioNodeEmitter2(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitter2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterConeProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterConeProperties>
    {
        IAudioNodeEmitterConeProperties(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterConeProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterDecayModel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterDecayModel>
    {
        IAudioNodeEmitterDecayModel(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterDecayModel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterDecayModelStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterDecayModelStatics>
    {
        IAudioNodeEmitterDecayModelStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterDecayModelStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterFactory>
    {
        IAudioNodeEmitterFactory(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterNaturalDecayModelProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterNaturalDecayModelProperties>
    {
        IAudioNodeEmitterNaturalDecayModelProperties(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterNaturalDecayModelProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterShape :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterShape>
    {
        IAudioNodeEmitterShape(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterShape(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeEmitterShapeStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeEmitterShapeStatics>
    {
        IAudioNodeEmitterShapeStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeEmitterShapeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeListener :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeListener>
    {
        IAudioNodeListener(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioNodeWithListener :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioNodeWithListener>,
        impl::require<llm:OS::Media::Audio::IAudioNodeWithListener, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode>
    {
        IAudioNodeWithListener(std::nullptr_t = nullptr) noexcept {}
        IAudioNodeWithListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioPlaybackConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioPlaybackConnection>
    {
        IAudioPlaybackConnection(std::nullptr_t = nullptr) noexcept {}
        IAudioPlaybackConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioPlaybackConnectionOpenResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioPlaybackConnectionOpenResult>
    {
        IAudioPlaybackConnectionOpenResult(std::nullptr_t = nullptr) noexcept {}
        IAudioPlaybackConnectionOpenResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioPlaybackConnectionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioPlaybackConnectionStatics>
    {
        IAudioPlaybackConnectionStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioPlaybackConnectionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioStateMonitor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStateMonitor>
    {
        IAudioStateMonitor(std::nullptr_t = nullptr) noexcept {}
        IAudioStateMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAudioStateMonitorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAudioStateMonitorStatics>
    {
        IAudioStateMonitorStatics(std::nullptr_t = nullptr) noexcept {}
        IAudioStateMonitorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioDeviceInputNodeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioDeviceInputNodeResult>
    {
        ICreateAudioDeviceInputNodeResult(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioDeviceInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioDeviceInputNodeResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioDeviceInputNodeResult2>
    {
        ICreateAudioDeviceInputNodeResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioDeviceInputNodeResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioDeviceOutputNodeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioDeviceOutputNodeResult>
    {
        ICreateAudioDeviceOutputNodeResult(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioDeviceOutputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioDeviceOutputNodeResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioDeviceOutputNodeResult2>
    {
        ICreateAudioDeviceOutputNodeResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioDeviceOutputNodeResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioFileInputNodeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioFileInputNodeResult>
    {
        ICreateAudioFileInputNodeResult(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioFileInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioFileInputNodeResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioFileInputNodeResult2>
    {
        ICreateAudioFileInputNodeResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioFileInputNodeResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioFileOutputNodeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioFileOutputNodeResult>
    {
        ICreateAudioFileOutputNodeResult(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioFileOutputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioFileOutputNodeResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioFileOutputNodeResult2>
    {
        ICreateAudioFileOutputNodeResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioFileOutputNodeResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioGraphResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioGraphResult>
    {
        ICreateAudioGraphResult(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioGraphResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateAudioGraphResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateAudioGraphResult2>
    {
        ICreateAudioGraphResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateAudioGraphResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateMediaSourceAudioInputNodeResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateMediaSourceAudioInputNodeResult>
    {
        ICreateMediaSourceAudioInputNodeResult(std::nullptr_t = nullptr) noexcept {}
        ICreateMediaSourceAudioInputNodeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICreateMediaSourceAudioInputNodeResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICreateMediaSourceAudioInputNodeResult2>
    {
        ICreateMediaSourceAudioInputNodeResult2(std::nullptr_t = nullptr) noexcept {}
        ICreateMediaSourceAudioInputNodeResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEchoEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEchoEffectDefinition>,
        impl::require<llm:OS::Media::Audio::IEchoEffectDefinition, llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        IEchoEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IEchoEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEchoEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEchoEffectDefinitionFactory>
    {
        IEchoEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IEchoEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEqualizerBand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEqualizerBand>
    {
        IEqualizerBand(std::nullptr_t = nullptr) noexcept {}
        IEqualizerBand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEqualizerEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEqualizerEffectDefinition>,
        impl::require<llm:OS::Media::Audio::IEqualizerEffectDefinition, llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        IEqualizerEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IEqualizerEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEqualizerEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEqualizerEffectDefinitionFactory>
    {
        IEqualizerEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IEqualizerEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameInputNodeQuantumStartedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameInputNodeQuantumStartedEventArgs>
    {
        IFrameInputNodeQuantumStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFrameInputNodeQuantumStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILimiterEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILimiterEffectDefinition>,
        impl::require<llm:OS::Media::Audio::ILimiterEffectDefinition, llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        ILimiterEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        ILimiterEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILimiterEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILimiterEffectDefinitionFactory>
    {
        ILimiterEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        ILimiterEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaSourceAudioInputNode :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaSourceAudioInputNode>,
        impl::require<llm:OS::Media::Audio::IMediaSourceAudioInputNode, llm:OS::Foundation::IClosable, llm:OS::Media::Audio::IAudioNode, llm:OS::Media::Audio::IAudioInputNode, llm:OS::Media::Audio::IAudioInputNode2>
    {
        IMediaSourceAudioInputNode(std::nullptr_t = nullptr) noexcept {}
        IMediaSourceAudioInputNode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReverbEffectDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IReverbEffectDefinition>,
        impl::require<llm:OS::Media::Audio::IReverbEffectDefinition, llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        IReverbEffectDefinition(std::nullptr_t = nullptr) noexcept {}
        IReverbEffectDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReverbEffectDefinitionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IReverbEffectDefinitionFactory>
    {
        IReverbEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
        IReverbEffectDefinitionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISetDefaultSpatialAudioFormatResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISetDefaultSpatialAudioFormatResult>
    {
        ISetDefaultSpatialAudioFormatResult(std::nullptr_t = nullptr) noexcept {}
        ISetDefaultSpatialAudioFormatResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioDeviceConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioDeviceConfiguration>
    {
        ISpatialAudioDeviceConfiguration(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioDeviceConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioDeviceConfigurationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioDeviceConfigurationStatics>
    {
        ISpatialAudioDeviceConfigurationStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioDeviceConfigurationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioFormatConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioFormatConfiguration>
    {
        ISpatialAudioFormatConfiguration(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioFormatConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioFormatConfigurationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioFormatConfigurationStatics>
    {
        ISpatialAudioFormatConfigurationStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioFormatConfigurationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioFormatSubtypeStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioFormatSubtypeStatics>
    {
        ISpatialAudioFormatSubtypeStatics(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioFormatSubtypeStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpatialAudioFormatSubtypeStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpatialAudioFormatSubtypeStatics2>
    {
        ISpatialAudioFormatSubtypeStatics2(std::nullptr_t = nullptr) noexcept {}
        ISpatialAudioFormatSubtypeStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
