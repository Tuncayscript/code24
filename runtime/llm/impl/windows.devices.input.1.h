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
#ifndef LLM_OS_Devices_Input_1_H
#define LLM_OS_Devices_Input_1_H
#include "llm/impl/Windows.Devices.Input.0.h"
LLM_EXPORT namespace llm::OS::Devices::Input
{
    struct __declspec(empty_bases) IKeyboardCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKeyboardCapabilities>
    {
        IKeyboardCapabilities(std::nullptr_t = nullptr) noexcept {}
        IKeyboardCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMouseCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMouseCapabilities>
    {
        IMouseCapabilities(std::nullptr_t = nullptr) noexcept {}
        IMouseCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMouseDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMouseDevice>
    {
        IMouseDevice(std::nullptr_t = nullptr) noexcept {}
        IMouseDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMouseDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMouseDeviceStatics>
    {
        IMouseDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IMouseDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMouseEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMouseEventArgs>
    {
        IMouseEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMouseEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenButtonListener :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenButtonListener>
    {
        IPenButtonListener(std::nullptr_t = nullptr) noexcept {}
        IPenButtonListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenButtonListenerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenButtonListenerStatics>
    {
        IPenButtonListenerStatics(std::nullptr_t = nullptr) noexcept {}
        IPenButtonListenerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDevice>
    {
        IPenDevice(std::nullptr_t = nullptr) noexcept {}
        IPenDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDevice2>
    {
        IPenDevice2(std::nullptr_t = nullptr) noexcept {}
        IPenDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDeviceStatics>
    {
        IPenDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IPenDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDockListener :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDockListener>
    {
        IPenDockListener(std::nullptr_t = nullptr) noexcept {}
        IPenDockListener(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDockListenerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDockListenerStatics>
    {
        IPenDockListenerStatics(std::nullptr_t = nullptr) noexcept {}
        IPenDockListenerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenDockedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenDockedEventArgs>
    {
        IPenDockedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPenDockedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenTailButtonClickedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenTailButtonClickedEventArgs>
    {
        IPenTailButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPenTailButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenTailButtonDoubleClickedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenTailButtonDoubleClickedEventArgs>
    {
        IPenTailButtonDoubleClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPenTailButtonDoubleClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenTailButtonLongPressedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenTailButtonLongPressedEventArgs>
    {
        IPenTailButtonLongPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPenTailButtonLongPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPenUndockedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPenUndockedEventArgs>
    {
        IPenUndockedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPenUndockedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPointerDevice>
    {
        IPointerDevice(std::nullptr_t = nullptr) noexcept {}
        IPointerDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPointerDevice2>
    {
        IPointerDevice2(std::nullptr_t = nullptr) noexcept {}
        IPointerDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPointerDeviceStatics>
    {
        IPointerDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IPointerDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITouchCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITouchCapabilities>
    {
        ITouchCapabilities(std::nullptr_t = nullptr) noexcept {}
        ITouchCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
