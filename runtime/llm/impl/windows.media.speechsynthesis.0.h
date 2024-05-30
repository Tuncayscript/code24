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
#ifndef LLM_OS_Media_SpeechSynthesis_0_H
#define LLM_OS_Media_SpeechSynthesis_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Media
{
    struct IMediaMarker;
}
LLM_EXPORT namespace llm:OS::Media::SpeechSynthesis
{
    enum class SpeechAppendedSilence : int32_t
    {
        Default = 0,
        Min = 1,
    };
    enum class SpeechPunctuationSilence : int32_t
    {
        Default = 0,
        Min = 1,
    };
    enum class VoiceGender : int32_t
    {
        Male = 0,
        Female = 1,
    };
    struct IInstalledVoicesStatic;
    struct IInstalledVoicesStatic2;
    struct ISpeechSynthesisStream;
    struct ISpeechSynthesizer;
    struct ISpeechSynthesizer2;
    struct ISpeechSynthesizerOptions;
    struct ISpeechSynthesizerOptions2;
    struct ISpeechSynthesizerOptions3;
    struct IVoiceInformation;
    struct SpeechSynthesisStream;
    struct SpeechSynthesizer;
    struct SpeechSynthesizerOptions;
    struct VoiceInformation;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::IVoiceInformation>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::SpeechSynthesisStream>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::SpeechSynthesizer>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::SpeechSynthesizerOptions>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::VoiceInformation>{ using type = class_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::SpeechAppendedSilence>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::SpeechPunctuationSilence>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::SpeechSynthesis::VoiceGender>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::SpeechSynthesisStream> = L"Windows.Media.SpeechSynthesis.SpeechSynthesisStream";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::SpeechSynthesizer> = L"Windows.Media.SpeechSynthesis.SpeechSynthesizer";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::SpeechSynthesizerOptions> = L"Windows.Media.SpeechSynthesis.SpeechSynthesizerOptions";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::VoiceInformation> = L"Windows.Media.SpeechSynthesis.VoiceInformation";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::SpeechAppendedSilence> = L"Windows.Media.SpeechSynthesis.SpeechAppendedSilence";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::SpeechPunctuationSilence> = L"Windows.Media.SpeechSynthesis.SpeechPunctuationSilence";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::VoiceGender> = L"Windows.Media.SpeechSynthesis.VoiceGender";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic> = L"Windows.Media.SpeechSynthesis.IInstalledVoicesStatic";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic2> = L"Windows.Media.SpeechSynthesis.IInstalledVoicesStatic2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesisStream";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesizer";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesizer2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesizerOptions";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesizerOptions2";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3> = L"Windows.Media.SpeechSynthesis.ISpeechSynthesizerOptions3";
    template <> inline constexpr auto& name_v<llm:OS::Media::SpeechSynthesis::IVoiceInformation> = L"Windows.Media.SpeechSynthesis.IVoiceInformation";
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic>{ 0x7D526ECC,0x7533,0x4C3F,{ 0x85,0xBE,0x88,0x8C,0x2B,0xAE,0xEB,0xDC } }; // 7D526ECC-7533-4C3F-85BE-888C2BAEEBDC
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic2>{ 0x64255F2E,0x358D,0x4058,{ 0xBE,0x9A,0xFD,0x3F,0xCB,0x42,0x35,0x30 } }; // 64255F2E-358D-4058-BE9A-FD3FCB423530
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream>{ 0x83E46E93,0x244C,0x4622,{ 0xBA,0x0B,0x62,0x29,0xC4,0xD0,0xD6,0x5D } }; // 83E46E93-244C-4622-BA0B-6229C4D0D65D
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer>{ 0xCE9F7C76,0x97F4,0x4CED,{ 0xAD,0x68,0xD5,0x1C,0x45,0x8E,0x45,0xC6 } }; // CE9F7C76-97F4-4CED-AD68-D51C458E45C6
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2>{ 0xA7C5ECB2,0x4339,0x4D6A,{ 0xBB,0xF8,0xC7,0xA4,0xF1,0x54,0x4C,0x2E } }; // A7C5ECB2-4339-4D6A-BBF8-C7A4F1544C2E
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions>{ 0xA0E23871,0xCC3D,0x43C9,{ 0x91,0xB1,0xEE,0x18,0x53,0x24,0xD8,0x3D } }; // A0E23871-CC3D-43C9-91B1-EE185324D83D
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2>{ 0x1CBEF60E,0x119C,0x4BED,{ 0xB1,0x18,0xD2,0x50,0xC3,0xA2,0x57,0x93 } }; // 1CBEF60E-119C-4BED-B118-D250C3A25793
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>{ 0x401ED877,0x902C,0x4814,{ 0xA5,0x82,0xA5,0xD0,0xC0,0x76,0x9F,0xA8 } }; // 401ED877-902C-4814-A582-A5D0C0769FA8
    template <> inline constexpr guid guid_v<llm:OS::Media::SpeechSynthesis::IVoiceInformation>{ 0xB127D6A4,0x1291,0x4604,{ 0xAA,0x9C,0x83,0x13,0x40,0x83,0x35,0x2C } }; // B127D6A4-1291-4604-AA9C-83134083352C
    template <> struct default_interface<llm:OS::Media::SpeechSynthesis::SpeechSynthesisStream>{ using type = llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream; };
    template <> struct default_interface<llm:OS::Media::SpeechSynthesis::SpeechSynthesizer>{ using type = llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer; };
    template <> struct default_interface<llm:OS::Media::SpeechSynthesis::SpeechSynthesizerOptions>{ using type = llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions; };
    template <> struct default_interface<llm:OS::Media::SpeechSynthesis::VoiceInformation>{ using type = llm:OS::Media::SpeechSynthesis::IVoiceInformation; };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllVoices(void**) noexcept = 0;
            virtual int32_t __stdcall get_DefaultVoice(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TrySetDefaultVoiceAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Markers(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SynthesizeTextToStreamAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SynthesizeSsmlToStreamAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall put_Voice(void*) noexcept = 0;
            virtual int32_t __stdcall get_Voice(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Options(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IncludeWordBoundaryMetadata(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeWordBoundaryMetadata(bool) noexcept = 0;
            virtual int32_t __stdcall get_IncludeSentenceBoundaryMetadata(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeSentenceBoundaryMetadata(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AudioVolume(double*) noexcept = 0;
            virtual int32_t __stdcall put_AudioVolume(double) noexcept = 0;
            virtual int32_t __stdcall get_SpeakingRate(double*) noexcept = 0;
            virtual int32_t __stdcall put_SpeakingRate(double) noexcept = 0;
            virtual int32_t __stdcall get_AudioPitch(double*) noexcept = 0;
            virtual int32_t __stdcall put_AudioPitch(double) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppendedSilence(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AppendedSilence(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_PunctuationSilence(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PunctuationSilence(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::SpeechSynthesis::IVoiceInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Language(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Gender(int32_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::SpeechSynthesis::VoiceInformation>) AllVoices() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::VoiceInformation) DefaultVoice() const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) TrySetDefaultVoiceAsync(llm:OS::Media::SpeechSynthesis::VoiceInformation const& voice) const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::IInstalledVoicesStatic2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_IInstalledVoicesStatic2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesisStream
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::IMediaMarker>) Markers() const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesisStream<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::SpeechSynthesis::SpeechSynthesisStream>) SynthesizeTextToStreamAsync(param::hstring const& text) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::SpeechSynthesis::SpeechSynthesisStream>) SynthesizeSsmlToStreamAsync(param::hstring const& Ssml) const;
        LLM_IMPL_AUTO(void) Voice(llm:OS::Media::SpeechSynthesis::VoiceInformation const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::VoiceInformation) Voice() const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::SpeechSynthesizerOptions) Options() const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizer2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeWordBoundaryMetadata() const;
        LLM_IMPL_AUTO(void) IncludeWordBoundaryMetadata(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeSentenceBoundaryMetadata() const;
        LLM_IMPL_AUTO(void) IncludeSentenceBoundaryMetadata(bool value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) AudioVolume() const;
        LLM_IMPL_AUTO(void) AudioVolume(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) SpeakingRate() const;
        LLM_IMPL_AUTO(void) SpeakingRate(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) AudioPitch() const;
        LLM_IMPL_AUTO(void) AudioPitch(double value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::SpeechAppendedSilence) AppendedSilence() const;
        LLM_IMPL_AUTO(void) AppendedSilence(llm:OS::Media::SpeechSynthesis::SpeechAppendedSilence const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::SpeechPunctuationSilence) PunctuationSilence() const;
        LLM_IMPL_AUTO(void) PunctuationSilence(llm:OS::Media::SpeechSynthesis::SpeechPunctuationSilence const& value) const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_ISpeechSynthesizerOptions3<D>;
    };
    template <typename D>
    struct consume_Windows_Media_SpeechSynthesis_IVoiceInformation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Language() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::SpeechSynthesis::VoiceGender) Gender() const;
    };
    template <> struct consume<llm:OS::Media::SpeechSynthesis::IVoiceInformation>
    {
        template <typename D> using type = consume_Windows_Media_SpeechSynthesis_IVoiceInformation<D>;
    };
}
#endif
