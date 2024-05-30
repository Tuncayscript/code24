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
#ifndef LLM_OS_Graphics_Display_Core_0_H
#define LLM_OS_Graphics_Display_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Graphics::Display::Core
{
    enum class HdmiDisplayColorSpace : int32_t
    {
        RgbLimited = 0,
        RgbFull = 1,
        BT2020 = 2,
        BT709 = 3,
    };
    enum class HdmiDisplayHdrOption : int32_t
    {
        None = 0,
        EotfSdr = 1,
        Eotf2084 = 2,
        DolbyVisionLowLatency = 3,
    };
    enum class HdmiDisplayPixelEncoding : int32_t
    {
        Rgb444 = 0,
        Ycc444 = 1,
        Ycc422 = 2,
        Ycc420 = 3,
    };
    struct IHdmiDisplayInformation;
    struct IHdmiDisplayInformationStatics;
    struct IHdmiDisplayMode;
    struct IHdmiDisplayMode2;
    struct HdmiDisplayInformation;
    struct HdmiDisplayMode;
    struct HdmiDisplayHdr2086Metadata;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::IHdmiDisplayInformationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::IHdmiDisplayMode>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::IHdmiDisplayMode2>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayInformation>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayMode>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayColorSpace>{ using type = enum_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayHdrOption>{ using type = enum_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayPixelEncoding>{ using type = enum_category; };
    template <> struct category<llm:OS::Graphics::Display::Core::HdmiDisplayHdr2086Metadata>{ using type = struct_category<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t>; };
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayInformation> = L"Windows.Graphics.Display.Core.HdmiDisplayInformation";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayMode> = L"Windows.Graphics.Display.Core.HdmiDisplayMode";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayColorSpace> = L"Windows.Graphics.Display.Core.HdmiDisplayColorSpace";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayHdrOption> = L"Windows.Graphics.Display.Core.HdmiDisplayHdrOption";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayPixelEncoding> = L"Windows.Graphics.Display.Core.HdmiDisplayPixelEncoding";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::HdmiDisplayHdr2086Metadata> = L"Windows.Graphics.Display.Core.HdmiDisplayHdr2086Metadata";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation> = L"Windows.Graphics.Display.Core.IHdmiDisplayInformation";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::IHdmiDisplayInformationStatics> = L"Windows.Graphics.Display.Core.IHdmiDisplayInformationStatics";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::IHdmiDisplayMode> = L"Windows.Graphics.Display.Core.IHdmiDisplayMode";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Display::Core::IHdmiDisplayMode2> = L"Windows.Graphics.Display.Core.IHdmiDisplayMode2";
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation>{ 0x130B3C0A,0xF565,0x476E,{ 0xAB,0xD5,0xEA,0x05,0xAE,0xE7,0x4C,0x69 } }; // 130B3C0A-F565-476E-ABD5-EA05AEE74C69
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Display::Core::IHdmiDisplayInformationStatics>{ 0x6CE6B260,0xF42A,0x4A15,{ 0x91,0x4C,0x7B,0x8E,0x2A,0x5A,0x65,0xDF } }; // 6CE6B260-F42A-4A15-914C-7B8E2A5A65DF
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Display::Core::IHdmiDisplayMode>{ 0x0C06D5AD,0x1B90,0x4F51,{ 0x99,0x81,0xEF,0x5A,0x1C,0x0D,0xDF,0x66 } }; // 0C06D5AD-1B90-4F51-9981-EF5A1C0DDF66
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Display::Core::IHdmiDisplayMode2>{ 0x07CD4E9F,0x4B3C,0x42B8,{ 0x84,0xE7,0x89,0x53,0x68,0x71,0x8A,0xF2 } }; // 07CD4E9F-4B3C-42B8-84E7-895368718AF2
    template <> struct default_interface<llm:OS::Graphics::Display::Core::HdmiDisplayInformation>{ using type = llm:OS::Graphics::Display::Core::IHdmiDisplayInformation; };
    template <> struct default_interface<llm:OS::Graphics::Display::Core::HdmiDisplayMode>{ using type = llm:OS::Graphics::Display::Core::IHdmiDisplayMode; };
    template <> struct abi<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetSupportedDisplayModes(void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentDisplayMode(void**) noexcept = 0;
            virtual int32_t __stdcall SetDefaultDisplayModeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestSetCurrentDisplayModeAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestSetCurrentDisplayModeWithHdrAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestSetCurrentDisplayModeWithHdrAndMetadataAsync(void*, int32_t, struct struct_Windows_Graphics_Display_Core_HdmiDisplayHdr2086Metadata, void**) noexcept = 0;
            virtual int32_t __stdcall add_DisplayModesChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DisplayModesChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Display::Core::IHdmiDisplayInformationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Display::Core::IHdmiDisplayMode>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ResolutionWidthInRawPixels(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ResolutionHeightInRawPixels(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RefreshRate(double*) noexcept = 0;
            virtual int32_t __stdcall get_StereoEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_BitsPerPixel(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall IsEqual(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall get_ColorSpace(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PixelEncoding(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsSdrLuminanceSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSmpte2084Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Is2086MetadataSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Display::Core::IHdmiDisplayMode2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsDolbyVisionLowLatencySupported(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::Display::Core::HdmiDisplayMode>) GetSupportedDisplayModes() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Display::Core::HdmiDisplayMode) GetCurrentDisplayMode() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetDefaultDisplayModeAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestSetCurrentDisplayModeAsync(llm:OS::Graphics::Display::Core::HdmiDisplayMode const& mode) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestSetCurrentDisplayModeAsync(llm:OS::Graphics::Display::Core::HdmiDisplayMode const& mode, llm:OS::Graphics::Display::Core::HdmiDisplayHdrOption const& hdrOption) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestSetCurrentDisplayModeAsync(llm:OS::Graphics::Display::Core::HdmiDisplayMode const& mode, llm:OS::Graphics::Display::Core::HdmiDisplayHdrOption const& hdrOption, llm:OS::Graphics::Display::Core::HdmiDisplayHdr2086Metadata const& hdrMetadata) const;
        LLM_IMPL_AUTO(llm::event_token) DisplayModesChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Graphics::Display::Core::HdmiDisplayInformation, llm:OS::Foundation::IInspectable> const& value) const;
        using DisplayModesChanged_revoker = impl::event_revoker<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation, &impl::abi_t<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation>::remove_DisplayModesChanged>;
        [[nodiscard]] DisplayModesChanged_revoker DisplayModesChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Graphics::Display::Core::HdmiDisplayInformation, llm:OS::Foundation::IInspectable> const& value) const;
        LLM_IMPL_AUTO(void) DisplayModesChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Graphics::Display::Core::IHdmiDisplayInformation>
    {
        template <typename D> using type = consume_Windows_Graphics_Display_Core_IHdmiDisplayInformation<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Display_Core_IHdmiDisplayInformationStatics
    {
        LLM_IMPL_AUTO(llm:OS::Graphics::Display::Core::HdmiDisplayInformation) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::Graphics::Display::Core::IHdmiDisplayInformationStatics>
    {
        template <typename D> using type = consume_Windows_Graphics_Display_Core_IHdmiDisplayInformationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Display_Core_IHdmiDisplayMode
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ResolutionWidthInRawPixels() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ResolutionHeightInRawPixels() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) RefreshRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) StereoEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) BitsPerPixel() const;
        LLM_IMPL_AUTO(bool) IsEqual(llm:OS::Graphics::Display::Core::HdmiDisplayMode const& mode) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Display::Core::HdmiDisplayColorSpace) ColorSpace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Display::Core::HdmiDisplayPixelEncoding) PixelEncoding() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSdrLuminanceSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSmpte2084Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Is2086MetadataSupported() const;
    };
    template <> struct consume<llm:OS::Graphics::Display::Core::IHdmiDisplayMode>
    {
        template <typename D> using type = consume_Windows_Graphics_Display_Core_IHdmiDisplayMode<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Display_Core_IHdmiDisplayMode2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDolbyVisionLowLatencySupported() const;
    };
    template <> struct consume<llm:OS::Graphics::Display::Core::IHdmiDisplayMode2>
    {
        template <typename D> using type = consume_Windows_Graphics_Display_Core_IHdmiDisplayMode2<D>;
    };
    struct struct_Windows_Graphics_Display_Core_HdmiDisplayHdr2086Metadata
    {
        uint16_t RedPrimaryX;
        uint16_t RedPrimaryY;
        uint16_t GreenPrimaryX;
        uint16_t GreenPrimaryY;
        uint16_t BluePrimaryX;
        uint16_t BluePrimaryY;
        uint16_t WhitePointX;
        uint16_t WhitePointY;
        uint16_t MaxMasteringLuminance;
        uint16_t MinMasteringLuminance;
        uint16_t MaxContentLightLevel;
        uint16_t MaxFrameAverageLightLevel;
    };
    template <> struct abi<Windows::Graphics::Display::Core::HdmiDisplayHdr2086Metadata>
    {
        using type = struct_Windows_Graphics_Display_Core_HdmiDisplayHdr2086Metadata;
    };
}
#endif
