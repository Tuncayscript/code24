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
#ifndef LLM_OS_Media_Editing_0_H
#define LLM_OS_Media_Editing_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Rect;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Graphics::DirectX::Direct3D11
{
    struct IDirect3DSurface;
}
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct ImageStream;
}
LLM_EXPORT namespace llm:OS::Media::Core
{
    struct MediaStreamSource;
}
LLM_EXPORT namespace llm:OS::Media::Effects
{
    struct IAudioEffectDefinition;
    struct IVideoCompositorDefinition;
    struct IVideoEffectDefinition;
}
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct AudioEncodingProperties;
    struct MediaEncodingProfile;
    struct VideoEncodingProperties;
}
LLM_EXPORT namespace llm:OS::Media::Transcoding
{
    enum class TranscodeFailureReason : int32_t;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageFile;
    struct StorageFile;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm:OS::Media::Editing
{
    enum class MediaTrimmingPreference : int32_t
    {
        Fast = 0,
        Precise = 1,
    };
    enum class VideoFramePrecision : int32_t
    {
        NearestFrame = 0,
        NearestKeyFrame = 1,
    };
    struct IBackgroundAudioTrack;
    struct IBackgroundAudioTrackStatics;
    struct IEmbeddedAudioTrack;
    struct IMediaClip;
    struct IMediaClipStatics;
    struct IMediaClipStatics2;
    struct IMediaComposition;
    struct IMediaComposition2;
    struct IMediaCompositionStatics;
    struct IMediaOverlay;
    struct IMediaOverlayFactory;
    struct IMediaOverlayLayer;
    struct IMediaOverlayLayerFactory;
    struct BackgroundAudioTrack;
    struct EmbeddedAudioTrack;
    struct MediaClip;
    struct MediaComposition;
    struct MediaOverlay;
    struct MediaOverlayLayer;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Editing::IBackgroundAudioTrack>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IBackgroundAudioTrackStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IEmbeddedAudioTrack>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaClip>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaClipStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaClipStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaComposition>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaComposition2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaCompositionStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaOverlay>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaOverlayFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaOverlayLayer>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::IMediaOverlayLayerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Editing::BackgroundAudioTrack>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::EmbeddedAudioTrack>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::MediaClip>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::MediaComposition>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::MediaOverlay>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::MediaOverlayLayer>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Editing::MediaTrimmingPreference>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Editing::VideoFramePrecision>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::BackgroundAudioTrack> = L"Windows.Media.Editing.BackgroundAudioTrack";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::EmbeddedAudioTrack> = L"Windows.Media.Editing.EmbeddedAudioTrack";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::MediaClip> = L"Windows.Media.Editing.MediaClip";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::MediaComposition> = L"Windows.Media.Editing.MediaComposition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::MediaOverlay> = L"Windows.Media.Editing.MediaOverlay";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::MediaOverlayLayer> = L"Windows.Media.Editing.MediaOverlayLayer";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::MediaTrimmingPreference> = L"Windows.Media.Editing.MediaTrimmingPreference";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::VideoFramePrecision> = L"Windows.Media.Editing.VideoFramePrecision";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IBackgroundAudioTrack> = L"Windows.Media.Editing.IBackgroundAudioTrack";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IBackgroundAudioTrackStatics> = L"Windows.Media.Editing.IBackgroundAudioTrackStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IEmbeddedAudioTrack> = L"Windows.Media.Editing.IEmbeddedAudioTrack";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaClip> = L"Windows.Media.Editing.IMediaClip";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaClipStatics> = L"Windows.Media.Editing.IMediaClipStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaClipStatics2> = L"Windows.Media.Editing.IMediaClipStatics2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaComposition> = L"Windows.Media.Editing.IMediaComposition";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaComposition2> = L"Windows.Media.Editing.IMediaComposition2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaCompositionStatics> = L"Windows.Media.Editing.IMediaCompositionStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaOverlay> = L"Windows.Media.Editing.IMediaOverlay";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaOverlayFactory> = L"Windows.Media.Editing.IMediaOverlayFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaOverlayLayer> = L"Windows.Media.Editing.IMediaOverlayLayer";
    template <> inline constexpr auto& name_v<llm:OS::Media::Editing::IMediaOverlayLayerFactory> = L"Windows.Media.Editing.IMediaOverlayLayerFactory";
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IBackgroundAudioTrack>{ 0x4B91B3BD,0x9E21,0x4266,{ 0xA9,0xC2,0x67,0xDD,0x01,0x1A,0x23,0x57 } }; // 4B91B3BD-9E21-4266-A9C2-67DD011A2357
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IBackgroundAudioTrackStatics>{ 0xD9B1C0D7,0xD018,0x42A8,{ 0xA5,0x59,0xCB,0x4D,0x9E,0x97,0xE6,0x64 } }; // D9B1C0D7-D018-42A8-A559-CB4D9E97E664
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IEmbeddedAudioTrack>{ 0x55EE5A7A,0x2D30,0x3FBA,{ 0xA1,0x90,0x4F,0x1A,0x64,0x54,0xF8,0x8F } }; // 55EE5A7A-2D30-3FBA-A190-4F1A6454F88F
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaClip>{ 0x53F25366,0x5FBA,0x3EA4,{ 0x86,0x93,0x24,0x76,0x18,0x11,0x14,0x0A } }; // 53F25366-5FBA-3EA4-8693-24761811140A
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaClipStatics>{ 0xFA402B68,0x928F,0x43C4,{ 0xBC,0x6E,0x78,0x3A,0x1A,0x35,0x96,0x56 } }; // FA402B68-928F-43C4-BC6E-783A1A359656
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaClipStatics2>{ 0x5B1DD7B3,0x854E,0x4D9B,{ 0x87,0x7D,0x47,0x74,0xA5,0x56,0xCD,0x12 } }; // 5B1DD7B3-854E-4D9B-877D-4774A556CD12
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaComposition>{ 0x2E06E605,0xDC71,0x41D6,{ 0xB8,0x37,0x2D,0x2B,0xC1,0x4A,0x29,0x47 } }; // 2E06E605-DC71-41D6-B837-2D2BC14A2947
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaComposition2>{ 0xA59E5372,0x2366,0x492C,{ 0xBE,0xC8,0xE6,0xDF,0xBA,0x6D,0x02,0x81 } }; // A59E5372-2366-492C-BEC8-E6DFBA6D0281
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaCompositionStatics>{ 0x87A08F04,0xE32A,0x45CE,{ 0x8F,0x66,0xA3,0x0D,0xF0,0x76,0x62,0x24 } }; // 87A08F04-E32A-45CE-8F66-A30DF0766224
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaOverlay>{ 0xA902AE5D,0x7869,0x4830,{ 0x8A,0xB1,0x94,0xDC,0x01,0xC0,0x5F,0xA4 } }; // A902AE5D-7869-4830-8AB1-94DC01C05FA4
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaOverlayFactory>{ 0xB584828A,0x6188,0x4F8F,{ 0xA2,0xE0,0xAA,0x55,0x2D,0x59,0x8E,0x18 } }; // B584828A-6188-4F8F-A2E0-AA552D598E18
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaOverlayLayer>{ 0xA6D9BA57,0xEEDA,0x46C6,{ 0xBB,0xE5,0xE3,0x98,0xC8,0x41,0x68,0xAC } }; // A6D9BA57-EEDA-46C6-BBE5-E398C84168AC
    template <> inline constexpr guid guid_v<llm:OS::Media::Editing::IMediaOverlayLayerFactory>{ 0x947CB473,0xA39E,0x4362,{ 0xAB,0xBF,0x9F,0x8B,0x50,0x70,0xA0,0x62 } }; // 947CB473-A39E-4362-ABBF-9F8B5070A062
    template <> struct default_interface<llm:OS::Media::Editing::BackgroundAudioTrack>{ using type = llm:OS::Media::Editing::IBackgroundAudioTrack; };
    template <> struct default_interface<llm:OS::Media::Editing::EmbeddedAudioTrack>{ using type = llm:OS::Media::Editing::IEmbeddedAudioTrack; };
    template <> struct default_interface<llm:OS::Media::Editing::MediaClip>{ using type = llm:OS::Media::Editing::IMediaClip; };
    template <> struct default_interface<llm:OS::Media::Editing::MediaComposition>{ using type = llm:OS::Media::Editing::IMediaComposition; };
    template <> struct default_interface<llm:OS::Media::Editing::MediaOverlay>{ using type = llm:OS::Media::Editing::IMediaOverlay; };
    template <> struct default_interface<llm:OS::Media::Editing::MediaOverlayLayer>{ using type = llm:OS::Media::Editing::IMediaOverlayLayer; };
    template <> struct abi<llm:OS::Media::Editing::IBackgroundAudioTrack>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TrimTimeFromStart(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_TrimTimeFromStart(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_TrimTimeFromEnd(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_TrimTimeFromEnd(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_OriginalDuration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TrimmedDuration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_UserData(void**) noexcept = 0;
            virtual int32_t __stdcall put_Delay(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_Delay(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Volume(double) noexcept = 0;
            virtual int32_t __stdcall get_Volume(double*) noexcept = 0;
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioEncodingProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_AudioEffectDefinitions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IBackgroundAudioTrackStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFromEmbeddedAudioTrack(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromFileAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IEmbeddedAudioTrack>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAudioEncodingProperties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaClip>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TrimTimeFromStart(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_TrimTimeFromStart(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_TrimTimeFromEnd(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_TrimTimeFromEnd(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_OriginalDuration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TrimmedDuration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_UserData(void**) noexcept = 0;
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
            virtual int32_t __stdcall get_StartTimeInComposition(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_EndTimeInComposition(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_EmbeddedAudioTracks(void**) noexcept = 0;
            virtual int32_t __stdcall get_SelectedEmbeddedAudioTrackIndex(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SelectedEmbeddedAudioTrackIndex(uint32_t) noexcept = 0;
            virtual int32_t __stdcall put_Volume(double) noexcept = 0;
            virtual int32_t __stdcall get_Volume(double*) noexcept = 0;
            virtual int32_t __stdcall GetVideoEncodingProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_AudioEffectDefinitions(void**) noexcept = 0;
            virtual int32_t __stdcall get_VideoEffectDefinitions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaClipStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFromColor(struct struct_Windows_UI_Color, int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromImageFileAsync(void*, int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaClipStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFromSurface(void*, int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaComposition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Duration(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Clips(void**) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundAudioTracks(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserData(void**) noexcept = 0;
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
            virtual int32_t __stdcall SaveAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetThumbnailAsync(int64_t, int32_t, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetThumbnailsAsync(void*, int32_t, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RenderToFileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RenderToFileWithTrimmingPreferenceAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RenderToFileWithProfileAsync(void*, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDefaultEncodingProfile(void**) noexcept = 0;
            virtual int32_t __stdcall GenerateMediaStreamSource(void**) noexcept = 0;
            virtual int32_t __stdcall GenerateMediaStreamSourceWithProfile(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GeneratePreviewMediaStreamSource(int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaComposition2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OverlayLayers(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaCompositionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LoadAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaOverlay>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Position(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_Position(llm:OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall put_Delay(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_Delay(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Opacity(double*) noexcept = 0;
            virtual int32_t __stdcall put_Opacity(double) noexcept = 0;
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
            virtual int32_t __stdcall get_Clip(void**) noexcept = 0;
            virtual int32_t __stdcall get_AudioEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AudioEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaOverlayFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithPositionAndOpacity(void*, llm:OS::Foundation::Rect, double, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaOverlayLayer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Clone(void**) noexcept = 0;
            virtual int32_t __stdcall get_Overlays(void**) noexcept = 0;
            virtual int32_t __stdcall get_CustomCompositorDefinition(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Editing::IMediaOverlayLayerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithCompositorDefinition(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IBackgroundAudioTrack
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimTimeFromStart() const;
        LLM_IMPL_AUTO(void) TrimTimeFromStart(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimTimeFromEnd() const;
        LLM_IMPL_AUTO(void) TrimTimeFromEnd(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) OriginalDuration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimmedDuration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) UserData() const;
        LLM_IMPL_AUTO(void) Delay(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Delay() const;
        LLM_IMPL_AUTO(void) Volume(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Volume() const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::BackgroundAudioTrack) Clone() const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::AudioEncodingProperties) GetAudioEncodingProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Effects::IAudioEffectDefinition>) AudioEffectDefinitions() const;
    };
    template <> struct consume<llm:OS::Media::Editing::IBackgroundAudioTrack>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IBackgroundAudioTrack<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IBackgroundAudioTrackStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::BackgroundAudioTrack) CreateFromEmbeddedAudioTrack(llm:OS::Media::Editing::EmbeddedAudioTrack const& embeddedAudioTrack) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Editing::BackgroundAudioTrack>) CreateFromFileAsync(llm:OS::Storage::IStorageFile const& file) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IBackgroundAudioTrackStatics>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IBackgroundAudioTrackStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IEmbeddedAudioTrack
    {
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::AudioEncodingProperties) GetAudioEncodingProperties() const;
    };
    template <> struct consume<llm:OS::Media::Editing::IEmbeddedAudioTrack>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IEmbeddedAudioTrack<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaClip
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimTimeFromStart() const;
        LLM_IMPL_AUTO(void) TrimTimeFromStart(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimTimeFromEnd() const;
        LLM_IMPL_AUTO(void) TrimTimeFromEnd(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) OriginalDuration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) TrimmedDuration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) UserData() const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaClip) Clone() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) StartTimeInComposition() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) EndTimeInComposition() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Editing::EmbeddedAudioTrack>) EmbeddedAudioTracks() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedEmbeddedAudioTrackIndex() const;
        LLM_IMPL_AUTO(void) SelectedEmbeddedAudioTrackIndex(uint32_t value) const;
        LLM_IMPL_AUTO(void) Volume(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Volume() const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::VideoEncodingProperties) GetVideoEncodingProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Effects::IAudioEffectDefinition>) AudioEffectDefinitions() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Effects::IVideoEffectDefinition>) VideoEffectDefinitions() const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaClip>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaClip<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaClipStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaClip) CreateFromColor(llm:OS::UI::Color const& color, llm:OS::Foundation::TimeSpan const& originalDuration) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Editing::MediaClip>) CreateFromFileAsync(llm:OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Editing::MediaClip>) CreateFromImageFileAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Foundation::TimeSpan const& originalDuration) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaClipStatics>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaClipStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaClipStatics2
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaClip) CreateFromSurface(llm:OS::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, llm:OS::Foundation::TimeSpan const& originalDuration) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaClipStatics2>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaClipStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaComposition
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Duration() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Editing::MediaClip>) Clips() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Editing::BackgroundAudioTrack>) BackgroundAudioTracks() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IMap<hstring, hstring>) UserData() const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaComposition) Clone() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SaveAsync(llm:OS::Storage::IStorageFile const& file) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Graphics::Imaging::ImageStream>) GetThumbnailAsync(llm:OS::Foundation::TimeSpan const& timeFromStart, int32_t scaledWidth, int32_t scaledHeight, llm:OS::Media::Editing::VideoFramePrecision const& framePrecision) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::Imaging::ImageStream>>) GetThumbnailsAsync(param::async_iterable<llm:OS::Foundation::TimeSpan> const& timesFromStart, int32_t scaledWidth, int32_t scaledHeight, llm:OS::Media::Editing::VideoFramePrecision const& framePrecision) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Transcoding::TranscodeFailureReason, double>) RenderToFileAsync(llm:OS::Storage::IStorageFile const& destination) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Transcoding::TranscodeFailureReason, double>) RenderToFileAsync(llm:OS::Storage::IStorageFile const& destination, llm:OS::Media::Editing::MediaTrimmingPreference const& trimmingPreference) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Transcoding::TranscodeFailureReason, double>) RenderToFileAsync(llm:OS::Storage::IStorageFile const& destination, llm:OS::Media::Editing::MediaTrimmingPreference const& trimmingPreference, llm:OS::Media::MediaProperties::MediaEncodingProfile const& encodingProfile) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaEncodingProfile) CreateDefaultEncodingProfile() const;
        LLM_IMPL_AUTO(llm:OS::Media::Core::MediaStreamSource) GenerateMediaStreamSource() const;
        LLM_IMPL_AUTO(llm:OS::Media::Core::MediaStreamSource) GenerateMediaStreamSource(llm:OS::Media::MediaProperties::MediaEncodingProfile const& encodingProfile) const;
        LLM_IMPL_AUTO(llm:OS::Media::Core::MediaStreamSource) GeneratePreviewMediaStreamSource(int32_t scaledWidth, int32_t scaledHeight) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaComposition>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaComposition<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaComposition2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Editing::MediaOverlayLayer>) OverlayLayers() const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaComposition2>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaComposition2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaCompositionStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Editing::MediaComposition>) LoadAsync(llm:OS::Storage::StorageFile const& file) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaCompositionStatics>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaCompositionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaOverlay
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) Position() const;
        LLM_IMPL_AUTO(void) Position(llm:OS::Foundation::Rect const& value) const;
        LLM_IMPL_AUTO(void) Delay(llm:OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Delay() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Opacity() const;
        LLM_IMPL_AUTO(void) Opacity(double value) const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlay) Clone() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaClip) Clip() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AudioEnabled() const;
        LLM_IMPL_AUTO(void) AudioEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaOverlay>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaOverlay<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaOverlayFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlay) Create(llm:OS::Media::Editing::MediaClip const& clip) const;
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlay) CreateWithPositionAndOpacity(llm:OS::Media::Editing::MediaClip const& clip, llm:OS::Foundation::Rect const& position, double opacity) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaOverlayFactory>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaOverlayFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaOverlayLayer
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlayLayer) Clone() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Media::Editing::MediaOverlay>) Overlays() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Effects::IVideoCompositorDefinition) CustomCompositorDefinition() const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaOverlayLayer>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaOverlayLayer<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Editing_IMediaOverlayLayerFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Editing::MediaOverlayLayer) CreateWithCompositorDefinition(llm:OS::Media::Effects::IVideoCompositorDefinition const& compositorDefinition) const;
    };
    template <> struct consume<llm:OS::Media::Editing::IMediaOverlayLayerFactory>
    {
        template <typename D> using type = consume_Windows_Media_Editing_IMediaOverlayLayerFactory<D>;
    };
}
#endif
