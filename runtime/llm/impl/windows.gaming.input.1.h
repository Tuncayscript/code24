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
#ifndef LLM_OS_Gaming_Input_1_H
#define LLM_OS_Gaming_Input_1_H
#include "llm/impl/Windows.Gaming.Input.0.h"
LLM_EXPORT namespace llm::OS::Gaming::Input
{
    struct __declspec(empty_bases) IArcadeStick :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IArcadeStick>,
        impl::require<llm::OS::Gaming::Input::IArcadeStick, llm::OS::Gaming::Input::IGameController>
    {
        IArcadeStick(std::nullptr_t = nullptr) noexcept {}
        IArcadeStick(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IArcadeStickStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IArcadeStickStatics>
    {
        IArcadeStickStatics(std::nullptr_t = nullptr) noexcept {}
        IArcadeStickStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IArcadeStickStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IArcadeStickStatics2>,
        impl::require<llm::OS::Gaming::Input::IArcadeStickStatics2, llm::OS::Gaming::Input::IArcadeStickStatics>
    {
        IArcadeStickStatics2(std::nullptr_t = nullptr) noexcept {}
        IArcadeStickStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFlightStick :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFlightStick>,
        impl::require<llm::OS::Gaming::Input::IFlightStick, llm::OS::Gaming::Input::IGameController>
    {
        IFlightStick(std::nullptr_t = nullptr) noexcept {}
        IFlightStick(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFlightStickStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFlightStickStatics>
    {
        IFlightStickStatics(std::nullptr_t = nullptr) noexcept {}
        IFlightStickStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameController>
    {
        IGameController(std::nullptr_t = nullptr) noexcept {}
        IGameController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameControllerBatteryInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameControllerBatteryInfo>
    {
        IGameControllerBatteryInfo(std::nullptr_t = nullptr) noexcept {}
        IGameControllerBatteryInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGamepad :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGamepad>,
        impl::require<llm::OS::Gaming::Input::IGamepad, llm::OS::Gaming::Input::IGameController>
    {
        IGamepad(std::nullptr_t = nullptr) noexcept {}
        IGamepad(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGamepad2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGamepad2>,
        impl::require<llm::OS::Gaming::Input::IGamepad2, llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::IGamepad>
    {
        IGamepad2(std::nullptr_t = nullptr) noexcept {}
        IGamepad2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGamepadStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGamepadStatics>
    {
        IGamepadStatics(std::nullptr_t = nullptr) noexcept {}
        IGamepadStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGamepadStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGamepadStatics2>,
        impl::require<llm::OS::Gaming::Input::IGamepadStatics2, llm::OS::Gaming::Input::IGamepadStatics>
    {
        IGamepadStatics2(std::nullptr_t = nullptr) noexcept {}
        IGamepadStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHeadset :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHeadset>
    {
        IHeadset(std::nullptr_t = nullptr) noexcept {}
        IHeadset(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRacingWheel :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRacingWheel>,
        impl::require<llm::OS::Gaming::Input::IRacingWheel, llm::OS::Gaming::Input::IGameController>
    {
        IRacingWheel(std::nullptr_t = nullptr) noexcept {}
        IRacingWheel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRacingWheelStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRacingWheelStatics>
    {
        IRacingWheelStatics(std::nullptr_t = nullptr) noexcept {}
        IRacingWheelStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRacingWheelStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRacingWheelStatics2>,
        impl::require<llm::OS::Gaming::Input::IRacingWheelStatics2, llm::OS::Gaming::Input::IRacingWheelStatics>
    {
        IRacingWheelStatics2(std::nullptr_t = nullptr) noexcept {}
        IRacingWheelStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawGameController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRawGameController>,
        impl::require<llm::OS::Gaming::Input::IRawGameController, llm::OS::Gaming::Input::IGameController>
    {
        IRawGameController(std::nullptr_t = nullptr) noexcept {}
        IRawGameController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawGameController2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRawGameController2>,
        impl::require<llm::OS::Gaming::Input::IRawGameController2, llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::IRawGameController>
    {
        IRawGameController2(std::nullptr_t = nullptr) noexcept {}
        IRawGameController2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawGameControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRawGameControllerStatics>
    {
        IRawGameControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IRawGameControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUINavigationController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUINavigationController>,
        impl::require<llm::OS::Gaming::Input::IUINavigationController, llm::OS::Gaming::Input::IGameController>
    {
        IUINavigationController(std::nullptr_t = nullptr) noexcept {}
        IUINavigationController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUINavigationControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUINavigationControllerStatics>
    {
        IUINavigationControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IUINavigationControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUINavigationControllerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUINavigationControllerStatics2>,
        impl::require<llm::OS::Gaming::Input::IUINavigationControllerStatics2, llm::OS::Gaming::Input::IUINavigationControllerStatics>
    {
        IUINavigationControllerStatics2(std::nullptr_t = nullptr) noexcept {}
        IUINavigationControllerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
