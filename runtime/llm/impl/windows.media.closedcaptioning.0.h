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
#ifndef LLM_OS_Media_ClosedCaptioning_0_H
#define LLM_OS_Media_ClosedCaptioning_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm:OS::Media::ClosedCaptioning
{
    enum class ClosedCaptionColor : int32_t
    {
        Default = 0,
        White = 1,
        Black = 2,
        Red = 3,
        Green = 4,
        Blue = 5,
        Yellow = 6,
        Magenta = 7,
        Cyan = 8,
    };
    enum class ClosedCaptionEdgeEffect : int32_t
    {
        Default = 0,
        None = 1,
        Raised = 2,
        Depressed = 3,
        Uniform = 4,
        DropShadow = 5,
    };
    enum class ClosedCaptionOpacity : int32_t
    {
        Default = 0,
        OneHundredPercent = 1,
        SeventyFivePercent = 2,
        TwentyFivePercent = 3,
        ZeroPercent = 4,
    };
    enum class ClosedCaptionSize : int32_t
    {
        Default = 0,
        FiftyPercent = 1,
        OneHundredPercent = 2,
        OneHundredFiftyPercent = 3,
        TwoHundredPercent = 4,
    };
    enum class ClosedCaptionStyle : int32_t
    {
        Default = 0,
        MonospacedWithSerifs = 1,
        ProportionalWithSerifs = 2,
        MonospacedWithoutSerifs = 3,
        ProportionalWithoutSerifs = 4,
        Casual = 5,
        Cursive = 6,
        SmallCapitals = 7,
    };
    struct IClosedCaptionPropertiesStatics;
    struct IClosedCaptionPropertiesStatics2;
    struct ClosedCaptionProperties;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionProperties>{ using type = class_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionColor>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionOpacity>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionSize>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::ClosedCaptioning::ClosedCaptionStyle>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionProperties> = L"Windows.Media.ClosedCaptioning.ClosedCaptionProperties";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionColor> = L"Windows.Media.ClosedCaptioning.ClosedCaptionColor";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect> = L"Windows.Media.ClosedCaptioning.ClosedCaptionEdgeEffect";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionOpacity> = L"Windows.Media.ClosedCaptioning.ClosedCaptionOpacity";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionSize> = L"Windows.Media.ClosedCaptioning.ClosedCaptionSize";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::ClosedCaptionStyle> = L"Windows.Media.ClosedCaptioning.ClosedCaptionStyle";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> = L"Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2> = L"Windows.Media.ClosedCaptioning.IClosedCaptionPropertiesStatics2";
    template <> inline constexpr guid guid_v<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>{ 0x10AA1F84,0xCC30,0x4141,{ 0xB5,0x03,0x52,0x72,0x28,0x9E,0x0C,0x20 } }; // 10AA1F84-CC30-4141-B503-5272289E0C20
    template <> inline constexpr guid guid_v<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>{ 0x9DE26870,0x37DE,0x4197,{ 0x88,0x45,0x9A,0x48,0xDC,0x5A,0xC3,0x17 } }; // 9DE26870-37DE-4197-8845-9A48DC5AC317
    template <> struct abi<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FontColor(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ComputedFontColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_FontOpacity(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FontSize(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FontStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FontEffect(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundColor(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ComputedBackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundOpacity(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RegionColor(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ComputedRegionColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_RegionOpacity(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_PropertiesChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PropertiesChanged(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionColor) FontColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) ComputedFontColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionOpacity) FontOpacity() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionSize) FontSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionStyle) FontStyle() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionEdgeEffect) FontEffect() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionColor) BackgroundColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) ComputedBackgroundColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionOpacity) BackgroundOpacity() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionColor) RegionColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) ComputedRegionColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ClosedCaptioning::ClosedCaptionOpacity) RegionOpacity() const;
    };
    template <> struct consume<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>
    {
        template <typename D> using type = consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2
    {
        LLM_IMPL_AUTO(llm::event_token) PropertiesChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using PropertiesChanged_revoker = impl::event_revoker<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2, &impl::abi_t<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>::remove_PropertiesChanged>;
        [[nodiscard]] PropertiesChanged_revoker PropertiesChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) PropertiesChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics2>
    {
        template <typename D> using type = consume_Windows_Media_ClosedCaptioning_IClosedCaptionPropertiesStatics2<D>;
    };
}
#endif
