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
#ifndef LLM_OS_UI_Input_Preview_Injection_1_H
#define LLM_OS_UI_Input_Preview_Injection_1_H
#include "llm/impl/Windows.UI.Input.Preview.Injection.0.h"
LLM_EXPORT namespace llm:OS::UI::Input::Preview::Injection
{
    struct __declspec(empty_bases) IInjectedInputGamepadInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputGamepadInfo>
    {
        IInjectedInputGamepadInfo(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputGamepadInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInjectedInputGamepadInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputGamepadInfoFactory>
    {
        IInjectedInputGamepadInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputGamepadInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInjectedInputKeyboardInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputKeyboardInfo>
    {
        IInjectedInputKeyboardInfo(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputKeyboardInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInjectedInputMouseInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputMouseInfo>
    {
        IInjectedInputMouseInfo(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputMouseInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInjectedInputPenInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputPenInfo>
    {
        IInjectedInputPenInfo(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputPenInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInjectedInputTouchInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInjectedInputTouchInfo>
    {
        IInjectedInputTouchInfo(std::nullptr_t = nullptr) noexcept {}
        IInjectedInputTouchInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputInjector :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputInjector>
    {
        IInputInjector(std::nullptr_t = nullptr) noexcept {}
        IInputInjector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputInjector2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputInjector2>,
        impl::require<llm:OS::UI::Input::Preview::Injection::IInputInjector2, llm:OS::UI::Input::Preview::Injection::IInputInjector>
    {
        IInputInjector2(std::nullptr_t = nullptr) noexcept {}
        IInputInjector2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputInjectorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputInjectorStatics>
    {
        IInputInjectorStatics(std::nullptr_t = nullptr) noexcept {}
        IInputInjectorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputInjectorStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputInjectorStatics2>,
        impl::require<llm:OS::UI::Input::Preview::Injection::IInputInjectorStatics2, llm:OS::UI::Input::Preview::Injection::IInputInjectorStatics>
    {
        IInputInjectorStatics2(std::nullptr_t = nullptr) noexcept {}
        IInputInjectorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
