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
#ifndef LLM_OS_UI_Input_Core_0_H
#define LLM_OS_UI_Input_Core_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel::Core
{
    struct CoreApplicationView;
}
LLM_EXPORT namespace llm:OS::System
{
    struct DispatcherQueue;
}
LLM_EXPORT namespace llm:OS::UI::Core
{
    struct CoreDispatcher;
}
LLM_EXPORT namespace llm:OS::UI::Input
{
    struct RadialController;
}
LLM_EXPORT namespace llm:OS::UI::Input::Core
{
    struct IRadialControllerIndependentInputSource;
    struct IRadialControllerIndependentInputSource2;
    struct IRadialControllerIndependentInputSourceStatics;
    struct RadialControllerIndependentInputSource;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Core::RadialControllerIndependentInputSource>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Core::RadialControllerIndependentInputSource> = L"Windows.UI.Input.Core.RadialControllerIndependentInputSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource> = L"Windows.UI.Input.Core.IRadialControllerIndependentInputSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource2> = L"Windows.UI.Input.Core.IRadialControllerIndependentInputSource2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics> = L"Windows.UI.Input.Core.IRadialControllerIndependentInputSourceStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource>{ 0x3D577EF6,0x4CEE,0x11E6,{ 0xB5,0x35,0x00,0x1B,0xDC,0x06,0xAB,0x3B } }; // 3D577EF6-4CEE-11E6-B535-001BDC06AB3B
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource2>{ 0x7073AAD8,0x35F3,0x4EEB,{ 0x87,0x51,0xBE,0x4D,0x0A,0x66,0xFA,0xF4 } }; // 7073AAD8-35F3-4EEB-8751-BE4D0A66FAF4
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics>{ 0x3D577EF5,0x4CEE,0x11E6,{ 0xB5,0x35,0x00,0x1B,0xDC,0x06,0xAB,0x3B } }; // 3D577EF5-4CEE-11E6-B535-001BDC06AB3B
    template <> struct default_interface<llm:OS::UI::Input::Core::RadialControllerIndependentInputSource>{ using type = llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource; };
    template <> struct abi<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Controller(void**) noexcept = 0;
            virtual int32_t __stdcall get_Dispatcher(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DispatcherQueue(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateForView(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Input::RadialController) Controller() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Core::CoreDispatcher) Dispatcher() const;
    };
    template <> struct consume<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource>
    {
        template <typename D> using type = consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::DispatcherQueue) DispatcherQueue() const;
    };
    template <> struct consume<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSource2>
    {
        template <typename D> using type = consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSource2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSourceStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Input::Core::RadialControllerIndependentInputSource) CreateForView(llm:OS::ApplicationModel::Core::CoreApplicationView const& view) const;
    };
    template <> struct consume<llm:OS::UI::Input::Core::IRadialControllerIndependentInputSourceStatics>
    {
        template <typename D> using type = consume_Windows_UI_Input_Core_IRadialControllerIndependentInputSourceStatics<D>;
    };
}
#endif
