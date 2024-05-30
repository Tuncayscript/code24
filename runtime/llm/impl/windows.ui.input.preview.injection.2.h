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
#ifndef LLM_OS_UI_Input_Preview_Injection_2_H
#define LLM_OS_UI_Input_Preview_Injection_2_H
#include "llm/impl/Windows.Gaming.Input.2.h"
#include "llm/impl/Windows.UI.Input.Preview.Injection.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Preview::Injection
{
    struct InjectedInputPoint
    {
        int32_t PositionX;
        int32_t PositionY;
    };
    inline bool operator==(InjectedInputPoint const& left, InjectedInputPoint const& right) noexcept
    {
        return left.PositionX == right.PositionX && left.PositionY == right.PositionY;
    }
    inline bool operator!=(InjectedInputPoint const& left, InjectedInputPoint const& right) noexcept
    {
        return !(left == right);
    }
    struct InjectedInputPointerInfo
    {
        uint32_t PointerId;
        llm:OS::UI::Input::Preview::Injection::InjectedInputPointerOptions PointerOptions;
        llm:OS::UI::Input::Preview::Injection::InjectedInputPoint PixelLocation;
        uint32_t TimeOffsetInMilliseconds;
        uint64_t PerformanceCount;
    };
    inline bool operator==(InjectedInputPointerInfo const& left, InjectedInputPointerInfo const& right) noexcept
    {
        return left.PointerId == right.PointerId && left.PointerOptions == right.PointerOptions && left.PixelLocation == right.PixelLocation && left.TimeOffsetInMilliseconds == right.TimeOffsetInMilliseconds && left.PerformanceCount == right.PerformanceCount;
    }
    inline bool operator!=(InjectedInputPointerInfo const& left, InjectedInputPointerInfo const& right) noexcept
    {
        return !(left == right);
    }
    struct InjectedInputRectangle
    {
        int32_t Left;
        int32_t Top;
        int32_t Bottom;
        int32_t Right;
    };
    inline bool operator==(InjectedInputRectangle const& left, InjectedInputRectangle const& right) noexcept
    {
        return left.Left == right.Left && left.Top == right.Top && left.Bottom == right.Bottom && left.Right == right.Right;
    }
    inline bool operator!=(InjectedInputRectangle const& left, InjectedInputRectangle const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) InjectedInputGamepadInfo : llm:OS::UI::Input::Preview::Injection::IInjectedInputGamepadInfo
    {
        InjectedInputGamepadInfo(std::nullptr_t) noexcept {}
        InjectedInputGamepadInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInjectedInputGamepadInfo(ptr, take_ownership_from_abi) {}
        InjectedInputGamepadInfo();
        explicit InjectedInputGamepadInfo(llm:OS::Gaming::Input::GamepadReading const& reading);
    };
    struct __declspec(empty_bases) InjectedInputKeyboardInfo : llm:OS::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo
    {
        InjectedInputKeyboardInfo(std::nullptr_t) noexcept {}
        InjectedInputKeyboardInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo(ptr, take_ownership_from_abi) {}
        InjectedInputKeyboardInfo();
    };
    struct __declspec(empty_bases) InjectedInputMouseInfo : llm:OS::UI::Input::Preview::Injection::IInjectedInputMouseInfo
    {
        InjectedInputMouseInfo(std::nullptr_t) noexcept {}
        InjectedInputMouseInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInjectedInputMouseInfo(ptr, take_ownership_from_abi) {}
        InjectedInputMouseInfo();
    };
    struct __declspec(empty_bases) InjectedInputPenInfo : llm:OS::UI::Input::Preview::Injection::IInjectedInputPenInfo
    {
        InjectedInputPenInfo(std::nullptr_t) noexcept {}
        InjectedInputPenInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInjectedInputPenInfo(ptr, take_ownership_from_abi) {}
        InjectedInputPenInfo();
    };
    struct __declspec(empty_bases) InjectedInputTouchInfo : llm:OS::UI::Input::Preview::Injection::IInjectedInputTouchInfo
    {
        InjectedInputTouchInfo(std::nullptr_t) noexcept {}
        InjectedInputTouchInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInjectedInputTouchInfo(ptr, take_ownership_from_abi) {}
        InjectedInputTouchInfo();
    };
    struct __declspec(empty_bases) InputInjector : llm:OS::UI::Input::Preview::Injection::IInputInjector,
        impl::require<InputInjector, llm:OS::UI::Input::Preview::Injection::IInputInjector2>
    {
        InputInjector(std::nullptr_t) noexcept {}
        InputInjector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Preview::Injection::IInputInjector(ptr, take_ownership_from_abi) {}
        static auto TryCreate();
        static auto TryCreateForAppBroadcastOnly();
    };
}
#endif
