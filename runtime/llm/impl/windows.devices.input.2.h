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
#ifndef LLM_OS_Devices_Input_2_H
#define LLM_OS_Devices_Input_2_H
#include "llm/impl/Windows.Devices.Input.1.h"
LLM_EXPORT namespace llm::OS::Devices::Input
{
    struct MouseDelta
    {
        int32_t X;
        int32_t Y;
    };
    inline bool operator==(MouseDelta const& left, MouseDelta const& right) noexcept
    {
        return left.X == right.X && left.Y == right.Y;
    }
    inline bool operator!=(MouseDelta const& left, MouseDelta const& right) noexcept
    {
        return !(left == right);
    }
    struct PointerDeviceUsage
    {
        uint32_t UsagePage;
        uint32_t Usage;
        int32_t MinLogical;
        int32_t MaxLogical;
        int32_t MinPhysical;
        int32_t MaxPhysical;
        uint32_t Unit;
        float PhysicalMultiplier;
    };
    inline bool operator==(PointerDeviceUsage const& left, PointerDeviceUsage const& right) noexcept
    {
        return left.UsagePage == right.UsagePage && left.Usage == right.Usage && left.MinLogical == right.MinLogical && left.MaxLogical == right.MaxLogical && left.MinPhysical == right.MinPhysical && left.MaxPhysical == right.MaxPhysical && left.Unit == right.Unit && left.PhysicalMultiplier == right.PhysicalMultiplier;
    }
    inline bool operator!=(PointerDeviceUsage const& left, PointerDeviceUsage const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) KeyboardCapabilities : llm::OS::Devices::Input::IKeyboardCapabilities
    {
        KeyboardCapabilities(std::nullptr_t) noexcept {}
        KeyboardCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IKeyboardCapabilities(ptr, take_ownership_from_abi) {}
        KeyboardCapabilities();
    };
    struct __declspec(empty_bases) MouseCapabilities : llm::OS::Devices::Input::IMouseCapabilities
    {
        MouseCapabilities(std::nullptr_t) noexcept {}
        MouseCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IMouseCapabilities(ptr, take_ownership_from_abi) {}
        MouseCapabilities();
    };
    struct __declspec(empty_bases) MouseDevice : llm::OS::Devices::Input::IMouseDevice
    {
        MouseDevice(std::nullptr_t) noexcept {}
        MouseDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IMouseDevice(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) MouseEventArgs : llm::OS::Devices::Input::IMouseEventArgs
    {
        MouseEventArgs(std::nullptr_t) noexcept {}
        MouseEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IMouseEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenButtonListener : llm::OS::Devices::Input::IPenButtonListener
    {
        PenButtonListener(std::nullptr_t) noexcept {}
        PenButtonListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenButtonListener(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) PenDevice : llm::OS::Devices::Input::IPenDevice,
        impl::require<PenDevice, llm::OS::Devices::Input::IPenDevice2>
    {
        PenDevice(std::nullptr_t) noexcept {}
        PenDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenDevice(ptr, take_ownership_from_abi) {}
        static auto GetFromPointerId(uint32_t pointerId);
    };
    struct __declspec(empty_bases) PenDockListener : llm::OS::Devices::Input::IPenDockListener
    {
        PenDockListener(std::nullptr_t) noexcept {}
        PenDockListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenDockListener(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) PenDockedEventArgs : llm::OS::Devices::Input::IPenDockedEventArgs
    {
        PenDockedEventArgs(std::nullptr_t) noexcept {}
        PenDockedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenDockedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenTailButtonClickedEventArgs : llm::OS::Devices::Input::IPenTailButtonClickedEventArgs
    {
        PenTailButtonClickedEventArgs(std::nullptr_t) noexcept {}
        PenTailButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenTailButtonClickedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenTailButtonDoubleClickedEventArgs : llm::OS::Devices::Input::IPenTailButtonDoubleClickedEventArgs
    {
        PenTailButtonDoubleClickedEventArgs(std::nullptr_t) noexcept {}
        PenTailButtonDoubleClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenTailButtonDoubleClickedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenTailButtonLongPressedEventArgs : llm::OS::Devices::Input::IPenTailButtonLongPressedEventArgs
    {
        PenTailButtonLongPressedEventArgs(std::nullptr_t) noexcept {}
        PenTailButtonLongPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenTailButtonLongPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PenUndockedEventArgs : llm::OS::Devices::Input::IPenUndockedEventArgs
    {
        PenUndockedEventArgs(std::nullptr_t) noexcept {}
        PenUndockedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPenUndockedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointerDevice : llm::OS::Devices::Input::IPointerDevice,
        impl::require<PointerDevice, llm::OS::Devices::Input::IPointerDevice2>
    {
        PointerDevice(std::nullptr_t) noexcept {}
        PointerDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::IPointerDevice(ptr, take_ownership_from_abi) {}
        static auto GetPointerDevice(uint32_t pointerId);
        static auto GetPointerDevices();
    };
    struct __declspec(empty_bases) TouchCapabilities : llm::OS::Devices::Input::ITouchCapabilities
    {
        TouchCapabilities(std::nullptr_t) noexcept {}
        TouchCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Input::ITouchCapabilities(ptr, take_ownership_from_abi) {}
        TouchCapabilities();
    };
}
#endif
