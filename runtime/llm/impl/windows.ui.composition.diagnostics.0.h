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
#ifndef LLM_OS_UI_Composition_Diagnostics_0_H
#define LLM_OS_UI_Composition_Diagnostics_0_H
LLM_EXPORT namespace llm:OS::UI::Composition
{
    struct Compositor;
    struct Visual;
}
LLM_EXPORT namespace llm:OS::UI::Composition::Diagnostics
{
    enum class CompositionDebugOverdrawContentKinds : uint32_t
    {
        None = 0,
        OffscreenRendered = 0x1,
        Colors = 0x2,
        Effects = 0x4,
        Shadows = 0x8,
        Lights = 0x10,
        Surfaces = 0x20,
        SwapChains = 0x40,
        All = 0xffffffff,
    };
    struct ICompositionDebugHeatMaps;
    struct ICompositionDebugSettings;
    struct ICompositionDebugSettingsStatics;
    struct CompositionDebugHeatMaps;
    struct CompositionDebugSettings;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Diagnostics::CompositionDebugSettings>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Composition::Diagnostics::CompositionDebugOverdrawContentKinds>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps> = L"Windows.UI.Composition.Diagnostics.CompositionDebugHeatMaps";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::CompositionDebugSettings> = L"Windows.UI.Composition.Diagnostics.CompositionDebugSettings";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::CompositionDebugOverdrawContentKinds> = L"Windows.UI.Composition.Diagnostics.CompositionDebugOverdrawContentKinds";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps> = L"Windows.UI.Composition.Diagnostics.ICompositionDebugHeatMaps";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings> = L"Windows.UI.Composition.Diagnostics.ICompositionDebugSettings";
    template <> inline constexpr auto& name_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics> = L"Windows.UI.Composition.Diagnostics.ICompositionDebugSettingsStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps>{ 0xE49C90AC,0x2FF3,0x5805,{ 0x71,0x8C,0xB7,0x25,0xEE,0x07,0x65,0x0F } }; // E49C90AC-2FF3-5805-718C-B725EE07650F
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings>{ 0x2831987E,0x1D82,0x4D38,{ 0xB7,0xB7,0xEF,0xD1,0x1C,0x7B,0xC3,0xD1 } }; // 2831987E-1D82-4D38-B7B7-EFD11C7BC3D1
    template <> inline constexpr guid guid_v<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics>{ 0x64EC1F1E,0x6AF8,0x4AF8,{ 0xB8,0x14,0xC8,0x70,0xFD,0x5A,0x95,0x05 } }; // 64EC1F1E-6AF8-4AF8-B814-C870FD5A9505
    template <> struct default_interface<llm:OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps>{ using type = llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps; };
    template <> struct default_interface<llm:OS::UI::Composition::Diagnostics::CompositionDebugSettings>{ using type = llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings; };
    template <> struct abi<llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Hide(void*) noexcept = 0;
            virtual int32_t __stdcall ShowMemoryUsage(void*) noexcept = 0;
            virtual int32_t __stdcall ShowOverdraw(void*, uint32_t) noexcept = 0;
            virtual int32_t __stdcall ShowRedraw(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HeatMaps(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetSettings(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps
    {
        LLM_IMPL_AUTO(void) Hide(llm:OS::UI::Composition::Visual const& subtree) const;
        LLM_IMPL_AUTO(void) ShowMemoryUsage(llm:OS::UI::Composition::Visual const& subtree) const;
        LLM_IMPL_AUTO(void) ShowOverdraw(llm:OS::UI::Composition::Visual const& subtree, llm:OS::UI::Composition::Diagnostics::CompositionDebugOverdrawContentKinds const& contentKinds) const;
        LLM_IMPL_AUTO(void) ShowRedraw(llm:OS::UI::Composition::Visual const& subtree) const;
    };
    template <> struct consume<llm:OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps>
    {
        template <typename D> using type = consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps) HeatMaps() const;
    };
    template <> struct consume<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettings>
    {
        template <typename D> using type = consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettings<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettingsStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Composition::Diagnostics::CompositionDebugSettings) TryGetSettings(llm:OS::UI::Composition::Compositor const& compositor) const;
    };
    template <> struct consume<llm:OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics>
    {
        template <typename D> using type = consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettingsStatics<D>;
    };
}
#endif
