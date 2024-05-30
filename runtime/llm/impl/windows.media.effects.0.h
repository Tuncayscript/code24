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
#ifndef LLM_OS_Media_Effects_0_H
#define LLM_OS_Media_Effects_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct Rect;
    struct Size;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    struct IPropertySet;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Foundation::Numerics
{
}
LLM_EXPORT namespace llm:OS::Graphics::DirectX::Direct3D11
{
    struct IDirect3DDevice;
    struct IDirect3DSurface;
}
LLM_EXPORT namespace llm:OS::Media
{
    struct AudioFrame;
    enum class AudioProcessing : int32_t;
    struct VideoFrame;
}
LLM_EXPORT namespace llm:OS::Media::Capture
{
    enum class MediaCategory : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Editing
{
    struct MediaOverlay;
}
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct AudioEncodingProperties;
    enum class MediaMirroringOptions : uint32_t;
    enum class MediaRotation : int32_t;
    enum class SphericalVideoFrameFormat : int32_t;
    struct VideoEncodingProperties;
}
LLM_EXPORT namespace llm:OS::Media::Playback
{
    enum class SphericalVideoProjectionMode : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Render
{
    enum class AudioRenderCategory : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Transcoding
{
    enum class MediaVideoProcessingAlgorithm : int32_t;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamWithContentType;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm:OS::Media::Effects
{
    enum class AudioEffectType : int32_t
    {
        Other = 0,
        AcousticEchoCancellation = 1,
        NoiseSuppression = 2,
        AutomaticGainControl = 3,
        BeamForming = 4,
        ConstantToneRemoval = 5,
        Equalizer = 6,
        LoudnessEqualizer = 7,
        BassBoost = 8,
        VirtualSurround = 9,
        VirtualHeadphones = 10,
        SpeakerFill = 11,
        RoomCorrection = 12,
        BassManagement = 13,
        EnvironmentalEffects = 14,
        SpeakerProtection = 15,
        SpeakerCompensation = 16,
        DynamicRangeCompression = 17,
        FarFieldBeamForming = 18,
        DeepNoiseSuppression = 19,
    };
    enum class MediaEffectClosedReason : int32_t
    {
        Done = 0,
        UnknownError = 1,
        UnsupportedEncodingFormat = 2,
        EffectCurrentlyUnloaded = 3,
    };
    enum class MediaMemoryTypes : int32_t
    {
        Gpu = 0,
        Cpu = 1,
        GpuAndCpu = 2,
    };
    struct IAudioCaptureEffectsManager;
    struct IAudioEffect;
    struct IAudioEffectDefinition;
    struct IAudioEffectDefinitionFactory;
    struct IAudioEffectsManagerStatics;
    struct IAudioRenderEffectsManager;
    struct IAudioRenderEffectsManager2;
    struct IBasicAudioEffect;
    struct IBasicVideoEffect;
    struct ICompositeVideoFrameContext;
    struct IProcessAudioFrameContext;
    struct IProcessVideoFrameContext;
    struct IVideoCompositor;
    struct IVideoCompositorDefinition;
    struct IVideoCompositorDefinitionFactory;
    struct IVideoEffectDefinition;
    struct IVideoEffectDefinitionFactory;
    struct IVideoTransformEffectDefinition;
    struct IVideoTransformEffectDefinition2;
    struct IVideoTransformSphericalProjection;
    struct AudioCaptureEffectsManager;
    struct AudioEffect;
    struct AudioEffectDefinition;
    struct AudioEffectsManager;
    struct AudioRenderEffectsManager;
    struct CompositeVideoFrameContext;
    struct ProcessAudioFrameContext;
    struct ProcessVideoFrameContext;
    struct VideoCompositorDefinition;
    struct VideoEffectDefinition;
    struct VideoTransformEffectDefinition;
    struct VideoTransformSphericalProjection;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Effects::IAudioCaptureEffectsManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioEffect>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioEffectDefinition>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioEffectDefinitionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioEffectsManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioRenderEffectsManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IAudioRenderEffectsManager2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IBasicAudioEffect>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IBasicVideoEffect>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::ICompositeVideoFrameContext>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IProcessAudioFrameContext>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IProcessVideoFrameContext>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoCompositor>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoCompositorDefinition>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoCompositorDefinitionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoEffectDefinition>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoEffectDefinitionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoTransformEffectDefinition>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoTransformEffectDefinition2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::IVideoTransformSphericalProjection>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Effects::AudioCaptureEffectsManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::AudioEffect>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::AudioEffectDefinition>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::AudioEffectsManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::AudioRenderEffectsManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::CompositeVideoFrameContext>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::ProcessAudioFrameContext>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::ProcessVideoFrameContext>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::VideoCompositorDefinition>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::VideoEffectDefinition>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::VideoTransformEffectDefinition>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::VideoTransformSphericalProjection>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Effects::AudioEffectType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Effects::MediaEffectClosedReason>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Effects::MediaMemoryTypes>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioCaptureEffectsManager> = L"Windows.Media.Effects.AudioCaptureEffectsManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioEffect> = L"Windows.Media.Effects.AudioEffect";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioEffectDefinition> = L"Windows.Media.Effects.AudioEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioEffectsManager> = L"Windows.Media.Effects.AudioEffectsManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioRenderEffectsManager> = L"Windows.Media.Effects.AudioRenderEffectsManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::CompositeVideoFrameContext> = L"Windows.Media.Effects.CompositeVideoFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::ProcessAudioFrameContext> = L"Windows.Media.Effects.ProcessAudioFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::ProcessVideoFrameContext> = L"Windows.Media.Effects.ProcessVideoFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::VideoCompositorDefinition> = L"Windows.Media.Effects.VideoCompositorDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::VideoEffectDefinition> = L"Windows.Media.Effects.VideoEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::VideoTransformEffectDefinition> = L"Windows.Media.Effects.VideoTransformEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::VideoTransformSphericalProjection> = L"Windows.Media.Effects.VideoTransformSphericalProjection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::AudioEffectType> = L"Windows.Media.Effects.AudioEffectType";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::MediaEffectClosedReason> = L"Windows.Media.Effects.MediaEffectClosedReason";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::MediaMemoryTypes> = L"Windows.Media.Effects.MediaMemoryTypes";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioCaptureEffectsManager> = L"Windows.Media.Effects.IAudioCaptureEffectsManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioEffect> = L"Windows.Media.Effects.IAudioEffect";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioEffectDefinition> = L"Windows.Media.Effects.IAudioEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioEffectDefinitionFactory> = L"Windows.Media.Effects.IAudioEffectDefinitionFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioEffectsManagerStatics> = L"Windows.Media.Effects.IAudioEffectsManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioRenderEffectsManager> = L"Windows.Media.Effects.IAudioRenderEffectsManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IAudioRenderEffectsManager2> = L"Windows.Media.Effects.IAudioRenderEffectsManager2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IBasicAudioEffect> = L"Windows.Media.Effects.IBasicAudioEffect";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IBasicVideoEffect> = L"Windows.Media.Effects.IBasicVideoEffect";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::ICompositeVideoFrameContext> = L"Windows.Media.Effects.ICompositeVideoFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IProcessAudioFrameContext> = L"Windows.Media.Effects.IProcessAudioFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IProcessVideoFrameContext> = L"Windows.Media.Effects.IProcessVideoFrameContext";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoCompositor> = L"Windows.Media.Effects.IVideoCompositor";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoCompositorDefinition> = L"Windows.Media.Effects.IVideoCompositorDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoCompositorDefinitionFactory> = L"Windows.Media.Effects.IVideoCompositorDefinitionFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoEffectDefinition> = L"Windows.Media.Effects.IVideoEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoEffectDefinitionFactory> = L"Windows.Media.Effects.IVideoEffectDefinitionFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoTransformEffectDefinition> = L"Windows.Media.Effects.IVideoTransformEffectDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoTransformEffectDefinition2> = L"Windows.Media.Effects.IVideoTransformEffectDefinition2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Effects::IVideoTransformSphericalProjection> = L"Windows.Media.Effects.IVideoTransformSphericalProjection";
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioCaptureEffectsManager>{ 0x8F85C271,0x038D,0x4393,{ 0x82,0x98,0x54,0x01,0x10,0x60,0x8E,0xEF } }; // 8F85C271-038D-4393-8298-540110608EEF
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioEffect>{ 0x34AAFA51,0x9207,0x4055,{ 0xBE,0x93,0x6E,0x57,0x34,0xA8,0x6A,0xE4 } }; // 34AAFA51-9207-4055-BE93-6E5734A86AE4
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioEffectDefinition>{ 0xE4D7F974,0x7D80,0x4F73,{ 0x90,0x89,0xE3,0x1C,0x9D,0xB9,0xC2,0x94 } }; // E4D7F974-7D80-4F73-9089-E31C9DB9C294
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioEffectDefinitionFactory>{ 0x8E1DA646,0xE705,0x45ED,{ 0x8A,0x2B,0xFC,0x4E,0x4F,0x40,0x5A,0x97 } }; // 8E1DA646-E705-45ED-8A2B-FC4E4F405A97
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioEffectsManagerStatics>{ 0x66406C04,0x86FA,0x47CC,{ 0xA3,0x15,0xF4,0x89,0xD8,0xC3,0xFE,0x10 } }; // 66406C04-86FA-47CC-A315-F489D8C3FE10
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioRenderEffectsManager>{ 0x4DC98966,0x8751,0x42B2,{ 0xBF,0xCB,0x39,0xCA,0x78,0x64,0xBD,0x47 } }; // 4DC98966-8751-42B2-BFCB-39CA7864BD47
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IAudioRenderEffectsManager2>{ 0xA844CD09,0x5ECC,0x44B3,{ 0xBB,0x4E,0x1D,0xB0,0x72,0x87,0x13,0x9C } }; // A844CD09-5ECC-44B3-BB4E-1DB07287139C
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IBasicAudioEffect>{ 0x8C062C53,0x6BC0,0x48B8,{ 0xA9,0x9A,0x4B,0x41,0x55,0x0F,0x13,0x59 } }; // 8C062C53-6BC0-48B8-A99A-4B41550F1359
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IBasicVideoEffect>{ 0x8262C7EF,0xB360,0x40BE,{ 0x94,0x9B,0x2F,0xF4,0x2F,0xF3,0x56,0x93 } }; // 8262C7EF-B360-40BE-949B-2FF42FF35693
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::ICompositeVideoFrameContext>{ 0x6C30024B,0xF514,0x4278,{ 0xA5,0xF7,0xB9,0x18,0x80,0x49,0xD1,0x10 } }; // 6C30024B-F514-4278-A5F7-B9188049D110
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IProcessAudioFrameContext>{ 0x4CD92946,0x1222,0x4A27,{ 0xA5,0x86,0xFB,0x3E,0x20,0x27,0x32,0x55 } }; // 4CD92946-1222-4A27-A586-FB3E20273255
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IProcessVideoFrameContext>{ 0x276F0E2B,0x6461,0x401E,{ 0xBA,0x78,0x0F,0xDA,0xD6,0x11,0x4E,0xEC } }; // 276F0E2B-6461-401E-BA78-0FDAD6114EEC
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoCompositor>{ 0x8510B43E,0x420C,0x420F,{ 0x96,0xC7,0x7C,0x98,0xBB,0xA1,0xFC,0x55 } }; // 8510B43E-420C-420F-96C7-7C98BBA1FC55
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoCompositorDefinition>{ 0x7946B8D0,0x2010,0x4AE3,{ 0x9A,0xB2,0x2C,0xEF,0x42,0xED,0xD4,0xD2 } }; // 7946B8D0-2010-4AE3-9AB2-2CEF42EDD4D2
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoCompositorDefinitionFactory>{ 0x4366FD10,0x68B8,0x4D52,{ 0x89,0xB6,0x02,0xA9,0x68,0xCC,0xA8,0x99 } }; // 4366FD10-68B8-4D52-89B6-02A968CCA899
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoEffectDefinition>{ 0x39F38CF0,0x8D0F,0x4F3E,{ 0x84,0xFC,0x2D,0x46,0xA5,0x29,0x79,0x43 } }; // 39F38CF0-8D0F-4F3E-84FC-2D46A5297943
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoEffectDefinitionFactory>{ 0x81439B4E,0x6E33,0x428F,{ 0x9D,0x21,0xB5,0xAA,0xFE,0xF7,0x61,0x7C } }; // 81439B4E-6E33-428F-9D21-B5AAFEF7617C
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoTransformEffectDefinition>{ 0x9664BB6A,0x1EA6,0x4AA6,{ 0x80,0x74,0xAB,0xE8,0x85,0x1E,0xCA,0xE2 } }; // 9664BB6A-1EA6-4AA6-8074-ABE8851ECAE2
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoTransformEffectDefinition2>{ 0xF0A8089F,0x66C8,0x4694,{ 0x9F,0xD9,0x11,0x36,0xAB,0xF7,0x44,0x4A } }; // F0A8089F-66C8-4694-9FD9-1136ABF7444A
    template <> inline constexpr guid guid_v<llm:OS::Media::Effects::IVideoTransformSphericalProjection>{ 0xCF4401F0,0x9BF2,0x4C39,{ 0x9F,0x41,0xE0,0x22,0x51,0x4A,0x84,0x68 } }; // CF4401F0-9BF2-4C39-9F41-E022514A8468
    template <> struct default_interface<llm:OS::Media::Effects::AudioCaptureEffectsManager>{ using type = llm:OS::Media::Effects::IAudioCaptureEffectsManager; };
    template <> struct default_interface<llm:OS::Media::Effects::AudioEffect>{ using type = llm:OS::Media::Effects::IAudioEffect; };
    template <> struct default_interface<llm:OS::Media::Effects::AudioEffectDefinition>{ using type = llm:OS::Media::Effects::IAudioEffectDefinition; };
    template <> struct default_interface<llm:OS::Media::Effects::AudioRenderEffectsManager>{ using type = llm:OS::Media::Effects::IAudioRenderEffectsManager; };
    template <> struct default_interface<llm:OS::Media::Effects::CompositeVideoFrameContext>{ using type = llm:OS::Media::Effects::ICompositeVideoFrameContext; };
    template <> struct default_interface<llm:OS::Media::Effects::ProcessAudioFrameContext>{ using type = llm:OS::Media::Effects::IProcessAudioFrameContext; };
    template <> struct default_interface<llm:OS::Media::Effects::ProcessVideoFrameContext>{ using type = llm:OS::Media::Effects::IProcessVideoFrameContext; };
    template <> struct default_interface<llm:OS::Media::Effects::VideoCompositorDefinition>{ using type = llm:OS::Media::Effects::IVideoCompositorDefinition; };
    template <> struct default_interface<llm:OS::Media::Effects::VideoEffectDefinition>{ using type = llm:OS::Media::Effects::IVideoEffectDefinition; };
    template <> struct default_interface<llm:OS::Media::Effects::VideoTransformEffectDefinition>{ using type = llm:OS::Media::Effects::IVideoEffectDefinition; };
    template <> struct default_interface<llm:OS::Media::Effects::VideoTransformSphericalProjection>{ using type = llm:OS::Media::Effects::IVideoTransformSphericalProjection; };
    template <> struct abi<llm:OS::Media::Effects::IAudioCaptureEffectsManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_AudioCaptureEffectsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AudioCaptureEffectsChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetAudioCaptureEffects(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AudioEffectType(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivatableClassId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioEffectDefinitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithProperties(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioEffectsManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAudioRenderEffectsManager(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateAudioRenderEffectsManagerWithMode(void*, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateAudioCaptureEffectsManager(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateAudioCaptureEffectsManagerWithMode(void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioRenderEffectsManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_AudioRenderEffectsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AudioRenderEffectsChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetAudioRenderEffects(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IAudioRenderEffectsManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EffectsProviderThumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall get_EffectsProviderSettingsLabel(void**) noexcept = 0;
            virtual int32_t __stdcall ShowSettingsUI() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IBasicAudioEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UseInputFrameForOutput(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedEncodingProperties(void**) noexcept = 0;
            virtual int32_t __stdcall SetEncodingProperties(void*) noexcept = 0;
            virtual int32_t __stdcall ProcessFrame(void*) noexcept = 0;
            virtual int32_t __stdcall Close(int32_t) noexcept = 0;
            virtual int32_t __stdcall DiscardQueuedFrames() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IBasicVideoEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsReadOnly(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedMemoryTypes(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TimeIndependent(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedEncodingProperties(void**) noexcept = 0;
            virtual int32_t __stdcall SetEncodingProperties(void*, void*) noexcept = 0;
            virtual int32_t __stdcall ProcessFrame(void*) noexcept = 0;
            virtual int32_t __stdcall Close(int32_t) noexcept = 0;
            virtual int32_t __stdcall DiscardQueuedFrames() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::ICompositeVideoFrameContext>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SurfacesToOverlay(void**) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundFrame(void**) noexcept = 0;
            virtual int32_t __stdcall get_OutputFrame(void**) noexcept = 0;
            virtual int32_t __stdcall GetOverlayForSurface(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IProcessAudioFrameContext>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InputFrame(void**) noexcept = 0;
            virtual int32_t __stdcall get_OutputFrame(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IProcessVideoFrameContext>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InputFrame(void**) noexcept = 0;
            virtual int32_t __stdcall get_OutputFrame(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoCompositor>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TimeIndependent(bool*) noexcept = 0;
            virtual int32_t __stdcall SetEncodingProperties(void*, void*) noexcept = 0;
            virtual int32_t __stdcall CompositeFrame(void*) noexcept = 0;
            virtual int32_t __stdcall Close(int32_t) noexcept = 0;
            virtual int32_t __stdcall DiscardQueuedFrames() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoCompositorDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivatableClassId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoCompositorDefinitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithProperties(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoEffectDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivatableClassId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoEffectDefinitionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithProperties(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoTransformEffectDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PaddingColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_PaddingColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_OutputSize(llm:OS::Foundation::Size*) noexcept = 0;
            virtual int32_t __stdcall put_OutputSize(llm:OS::Foundation::Size) noexcept = 0;
            virtual int32_t __stdcall get_CropRectangle(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_CropRectangle(llm:OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall get_Rotation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Rotation(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Mirror(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mirror(uint32_t) noexcept = 0;
            virtual int32_t __stdcall put_ProcessingAlgorithm(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ProcessingAlgorithm(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoTransformEffectDefinition2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SphericalProjection(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Effects::IVideoTransformSphericalProjection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_FrameFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FrameFormat(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ProjectionMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ProjectionMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_HorizontalFieldOfViewInDegrees(double*) noexcept = 0;
            virtual int32_t __stdcall put_HorizontalFieldOfViewInDegrees(double) noexcept = 0;
            virtual int32_t __stdcall get_ViewOrientation(llm:OS::Foundation::Numerics::quaternion*) noexcept = 0;
            virtual int32_t __stdcall put_ViewOrientation(llm:OS::Foundation::Numerics::quaternion) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioCaptureEffectsManager
    {
        LLM_IMPL_AUTO(llm::event_token) AudioCaptureEffectsChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Effects::AudioCaptureEffectsManager, llm:OS::Foundation::IInspectable> const& handler) const;
        using AudioCaptureEffectsChanged_revoker = impl::event_revoker<llm:OS::Media::Effects::IAudioCaptureEffectsManager, &impl::abi_t<llm:OS::Media::Effects::IAudioCaptureEffectsManager>::remove_AudioCaptureEffectsChanged>;
        [[nodiscard]] AudioCaptureEffectsChanged_revoker AudioCaptureEffectsChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Effects::AudioCaptureEffectsManager, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AudioCaptureEffectsChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Effects::AudioEffect>) GetAudioCaptureEffects() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioCaptureEffectsManager>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioCaptureEffectsManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioEffectType) AudioEffectType() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioEffect>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioEffectDefinition
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ActivatableClassId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioEffectDefinition>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioEffectDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioEffectDefinitionFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioEffectDefinition) Create(param::hstring const& activatableClassId) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioEffectDefinition) CreateWithProperties(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props) const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioEffectDefinitionFactory>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioEffectDefinitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioEffectsManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioRenderEffectsManager) CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm:OS::Media::Render::AudioRenderCategory const& category) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioRenderEffectsManager) CreateAudioRenderEffectsManager(param::hstring const& deviceId, llm:OS::Media::Render::AudioRenderCategory const& category, llm:OS::Media::AudioProcessing const& mode) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioCaptureEffectsManager) CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm:OS::Media::Capture::MediaCategory const& category) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::AudioCaptureEffectsManager) CreateAudioCaptureEffectsManager(param::hstring const& deviceId, llm:OS::Media::Capture::MediaCategory const& category, llm:OS::Media::AudioProcessing const& mode) const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioEffectsManagerStatics>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioEffectsManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioRenderEffectsManager
    {
        LLM_IMPL_AUTO(llm::event_token) AudioRenderEffectsChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Effects::AudioRenderEffectsManager, llm:OS::Foundation::IInspectable> const& handler) const;
        using AudioRenderEffectsChanged_revoker = impl::event_revoker<llm:OS::Media::Effects::IAudioRenderEffectsManager, &impl::abi_t<llm:OS::Media::Effects::IAudioRenderEffectsManager>::remove_AudioRenderEffectsChanged>;
        [[nodiscard]] AudioRenderEffectsChanged_revoker AudioRenderEffectsChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Effects::AudioRenderEffectsManager, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AudioRenderEffectsChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Effects::AudioEffect>) GetAudioRenderEffects() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioRenderEffectsManager>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioRenderEffectsManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IAudioRenderEffectsManager2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamWithContentType) EffectsProviderThumbnail() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EffectsProviderSettingsLabel() const;
        LLM_IMPL_AUTO(void) ShowSettingsUI() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IAudioRenderEffectsManager2>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IAudioRenderEffectsManager2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IBasicAudioEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) UseInputFrameForOutput() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::MediaProperties::AudioEncodingProperties>) SupportedEncodingProperties() const;
        LLM_IMPL_AUTO(void) SetEncodingProperties(llm:OS::Media::MediaProperties::AudioEncodingProperties const& encodingProperties) const;
        LLM_IMPL_AUTO(void) ProcessFrame(llm:OS::Media::Effects::ProcessAudioFrameContext const& context) const;
        LLM_IMPL_AUTO(void) Close(llm:OS::Media::Effects::MediaEffectClosedReason const& reason) const;
        LLM_IMPL_AUTO(void) DiscardQueuedFrames() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IBasicAudioEffect>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IBasicAudioEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IBasicVideoEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsReadOnly() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Effects::MediaMemoryTypes) SupportedMemoryTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) TimeIndependent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::MediaProperties::VideoEncodingProperties>) SupportedEncodingProperties() const;
        LLM_IMPL_AUTO(void) SetEncodingProperties(llm:OS::Media::MediaProperties::VideoEncodingProperties const& encodingProperties, llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device) const;
        LLM_IMPL_AUTO(void) ProcessFrame(llm:OS::Media::Effects::ProcessVideoFrameContext const& context) const;
        LLM_IMPL_AUTO(void) Close(llm:OS::Media::Effects::MediaEffectClosedReason const& reason) const;
        LLM_IMPL_AUTO(void) DiscardQueuedFrames() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IBasicVideoEffect>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IBasicVideoEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_ICompositeVideoFrameContext
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>) SurfacesToOverlay() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::VideoFrame) BackgroundFrame() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::VideoFrame) OutputFrame() const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlay) GetOverlayForSurface(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surfaceToOverlay) const;
    };
    template <> struct consume<llm:OS::Media::Effects::ICompositeVideoFrameContext>
    {
        template <typename D> using type = consume_Windows_Media_Effects_ICompositeVideoFrameContext<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IProcessAudioFrameContext
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::AudioFrame) InputFrame() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::AudioFrame) OutputFrame() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IProcessAudioFrameContext>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IProcessAudioFrameContext<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IProcessVideoFrameContext
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::VideoFrame) InputFrame() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::VideoFrame) OutputFrame() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IProcessVideoFrameContext>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IProcessVideoFrameContext<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoCompositor
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) TimeIndependent() const;
        LLM_IMPL_AUTO(void) SetEncodingProperties(llm:OS::Media::MediaProperties::VideoEncodingProperties const& backgroundProperties, llm:OS::Graphics::DirectX::Direct3D11::IDirect3DDevice const& device) const;
        LLM_IMPL_AUTO(void) CompositeFrame(llm:OS::Media::Effects::CompositeVideoFrameContext const& context) const;
        LLM_IMPL_AUTO(void) Close(llm:OS::Media::Effects::MediaEffectClosedReason const& reason) const;
        LLM_IMPL_AUTO(void) DiscardQueuedFrames() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoCompositor>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoCompositor<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoCompositorDefinition
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ActivatableClassId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoCompositorDefinition>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoCompositorDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoCompositorDefinitionFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Effects::VideoCompositorDefinition) Create(param::hstring const& activatableClassId) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::VideoCompositorDefinition) CreateWithProperties(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props) const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoCompositorDefinitionFactory>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoCompositorDefinitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoEffectDefinition
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ActivatableClassId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IPropertySet) Properties() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoEffectDefinition>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoEffectDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoEffectDefinitionFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Effects::VideoEffectDefinition) Create(param::hstring const& activatableClassId) const;
        LLM_IMPL_AUTO(llm:OS::Media::Effects::VideoEffectDefinition) CreateWithProperties(param::hstring const& activatableClassId, llm:OS::Foundation::Collections::IPropertySet const& props) const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoEffectDefinitionFactory>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoEffectDefinitionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoTransformEffectDefinition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) PaddingColor() const;
        LLM_IMPL_AUTO(void) PaddingColor(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Size) OutputSize() const;
        LLM_IMPL_AUTO(void) OutputSize(llm:OS::Foundation::Size const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) CropRectangle() const;
        LLM_IMPL_AUTO(void) CropRectangle(llm:OS::Foundation::Rect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRotation) Rotation() const;
        LLM_IMPL_AUTO(void) Rotation(llm:OS::Media::MediaProperties::MediaRotation const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaMirroringOptions) Mirror() const;
        LLM_IMPL_AUTO(void) Mirror(llm:OS::Media::MediaProperties::MediaMirroringOptions const& value) const;
        LLM_IMPL_AUTO(void) ProcessingAlgorithm(llm:OS::Media::Transcoding::MediaVideoProcessingAlgorithm const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Transcoding::MediaVideoProcessingAlgorithm) ProcessingAlgorithm() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoTransformEffectDefinition>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoTransformEffectDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoTransformEffectDefinition2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Effects::VideoTransformSphericalProjection) SphericalProjection() const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoTransformEffectDefinition2>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoTransformEffectDefinition2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Effects_IVideoTransformSphericalProjection
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::SphericalVideoFrameFormat) FrameFormat() const;
        LLM_IMPL_AUTO(void) FrameFormat(llm:OS::Media::MediaProperties::SphericalVideoFrameFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Playback::SphericalVideoProjectionMode) ProjectionMode() const;
        LLM_IMPL_AUTO(void) ProjectionMode(llm:OS::Media::Playback::SphericalVideoProjectionMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) HorizontalFieldOfViewInDegrees() const;
        LLM_IMPL_AUTO(void) HorizontalFieldOfViewInDegrees(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Numerics::quaternion) ViewOrientation() const;
        LLM_IMPL_AUTO(void) ViewOrientation(llm:OS::Foundation::Numerics::quaternion const& value) const;
    };
    template <> struct consume<llm:OS::Media::Effects::IVideoTransformSphericalProjection>
    {
        template <typename D> using type = consume_Windows_Media_Effects_IVideoTransformSphericalProjection<D>;
    };
}
#endif
