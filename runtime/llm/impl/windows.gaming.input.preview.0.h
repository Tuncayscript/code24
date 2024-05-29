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
#ifndef LLM_OS_Gaming_Input_Preview_0_H
#define LLM_OS_Gaming_Input_Preview_0_H
LLM_EXPORT namespace llm::OS::Gaming::Input::Custom
{
    struct IGameControllerProvider;
}
LLM_EXPORT namespace llm::OS::Gaming::Input::Preview
{
    struct IGameControllerProviderInfoStatics;
    struct GameControllerProviderInfo;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Preview::GameControllerProviderInfo>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Preview::GameControllerProviderInfo> = L"Windows.Gaming.Input.Preview.GameControllerProviderInfo";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics> = L"Windows.Gaming.Input.Preview.IGameControllerProviderInfoStatics";
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics>{ 0x0BE1E6C5,0xD9BD,0x44EE,{ 0x83,0x62,0x48,0x8B,0x2E,0x46,0x4B,0xFB } }; // 0BE1E6C5-D9BD-44EE-8362-488B2E464BFB
    template <> struct abi<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetParentProviderId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetProviderId(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics
    {
        LLM_IMPL_AUTO(hstring) GetParentProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const;
        LLM_IMPL_AUTO(hstring) GetProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics<D>;
    };
}
#endif
