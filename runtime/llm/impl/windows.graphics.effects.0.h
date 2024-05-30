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
#ifndef LLM_OS_Graphics_Effects_0_H
#define LLM_OS_Graphics_Effects_0_H
LLM_EXPORT namespace llm:OS::Graphics::Effects
{
    struct IGraphicsEffect;
    struct IGraphicsEffectSource;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Graphics::Effects::IGraphicsEffect>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Effects::IGraphicsEffectSource>{ using type = interface_category; };
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Effects::IGraphicsEffect> = L"Windows.Graphics.Effects.IGraphicsEffect";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Effects::IGraphicsEffectSource> = L"Windows.Graphics.Effects.IGraphicsEffectSource";
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Effects::IGraphicsEffect>{ 0xCB51C0CE,0x8FE6,0x4636,{ 0xB2,0x02,0x86,0x1F,0xAA,0x07,0xD8,0xF3 } }; // CB51C0CE-8FE6-4636-B202-861FAA07D8F3
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Effects::IGraphicsEffectSource>{ 0x2D8F9DDC,0x4339,0x4EB9,{ 0x92,0x16,0xF9,0xDE,0xB7,0x56,0x58,0xA2 } }; // 2D8F9DDC-4339-4EB9-9216-F9DEB75658A2
    template <> struct abi<llm:OS::Graphics::Effects::IGraphicsEffect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Effects::IGraphicsEffectSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <typename D>
    struct consume_Windows_Graphics_Effects_IGraphicsEffect
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& name) const;
    };
    template <> struct consume<llm:OS::Graphics::Effects::IGraphicsEffect>
    {
        template <typename D> using type = consume_Windows_Graphics_Effects_IGraphicsEffect<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Effects_IGraphicsEffectSource
    {
    };
    template <> struct consume<llm:OS::Graphics::Effects::IGraphicsEffectSource>
    {
        template <typename D> using type = consume_Windows_Graphics_Effects_IGraphicsEffectSource<D>;
    };
}
#endif
