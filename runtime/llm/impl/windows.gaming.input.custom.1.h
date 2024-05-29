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
#ifndef LLM_OS_Gaming_Input_Custom_1_H
#define LLM_OS_Gaming_Input_Custom_1_H
#include "llm/impl/Windows.Gaming.Input.Custom.0.h"
LLM_EXPORT namespace llm::OS::Gaming::Input::Custom
{
    struct __declspec(empty_bases) ICustomGameControllerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomGameControllerFactory>
    {
        ICustomGameControllerFactory(std::nullptr_t = nullptr) noexcept {}
        ICustomGameControllerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameControllerFactoryManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameControllerFactoryManagerStatics>
    {
        IGameControllerFactoryManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IGameControllerFactoryManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameControllerFactoryManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameControllerFactoryManagerStatics2>,
        impl::require<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2, llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>
    {
        IGameControllerFactoryManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IGameControllerFactoryManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameControllerInputSink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameControllerInputSink>
    {
        IGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
        IGameControllerInputSink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGameControllerProvider>
    {
        IGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
        IGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGipFirmwareUpdateResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGipFirmwareUpdateResult>
    {
        IGipFirmwareUpdateResult(std::nullptr_t = nullptr) noexcept {}
        IGipFirmwareUpdateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGipGameControllerInputSink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGipGameControllerInputSink>,
        impl::require<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink, llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        IGipGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
        IGipGameControllerInputSink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGipGameControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGipGameControllerProvider>,
        impl::require<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider, llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        IGipGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
        IGipGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidGameControllerInputSink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidGameControllerInputSink>,
        impl::require<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink, llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        IHidGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
        IHidGameControllerInputSink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHidGameControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHidGameControllerProvider>,
        impl::require<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider, llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        IHidGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
        IHidGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXusbGameControllerInputSink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXusbGameControllerInputSink>,
        impl::require<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink, llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        IXusbGameControllerInputSink(std::nullptr_t = nullptr) noexcept {}
        IXusbGameControllerInputSink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXusbGameControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXusbGameControllerProvider>,
        impl::require<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider, llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        IXusbGameControllerProvider(std::nullptr_t = nullptr) noexcept {}
        IXusbGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
