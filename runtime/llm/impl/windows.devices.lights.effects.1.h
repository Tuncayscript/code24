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
#ifndef LLM_OS_Devices_Lights_Effects_1_H
#define LLM_OS_Devices_Lights_Effects_1_H
#include "llm/impl/Windows.Devices.Lights.Effects.0.h"
LLM_EXPORT namespace llm::OS::Devices::Lights::Effects
{
    struct __declspec(empty_bases) ILampArrayBitmapEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayBitmapEffect>
    {
        ILampArrayBitmapEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArrayBitmapEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayBitmapEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayBitmapEffectFactory>
    {
        ILampArrayBitmapEffectFactory(std::nullptr_t = nullptr) noexcept {}
        ILampArrayBitmapEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayBitmapRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayBitmapRequestedEventArgs>
    {
        ILampArrayBitmapRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILampArrayBitmapRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayBlinkEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayBlinkEffect>
    {
        ILampArrayBlinkEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArrayBlinkEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayBlinkEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayBlinkEffectFactory>
    {
        ILampArrayBlinkEffectFactory(std::nullptr_t = nullptr) noexcept {}
        ILampArrayBlinkEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayColorRampEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayColorRampEffect>
    {
        ILampArrayColorRampEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArrayColorRampEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayColorRampEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayColorRampEffectFactory>
    {
        ILampArrayColorRampEffectFactory(std::nullptr_t = nullptr) noexcept {}
        ILampArrayColorRampEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayCustomEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayCustomEffect>
    {
        ILampArrayCustomEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArrayCustomEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayCustomEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayCustomEffectFactory>
    {
        ILampArrayCustomEffectFactory(std::nullptr_t = nullptr) noexcept {}
        ILampArrayCustomEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayEffect>
    {
        ILampArrayEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArrayEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayEffectPlaylist :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayEffectPlaylist>
    {
        ILampArrayEffectPlaylist(std::nullptr_t = nullptr) noexcept {}
        ILampArrayEffectPlaylist(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayEffectPlaylistStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayEffectPlaylistStatics>
    {
        ILampArrayEffectPlaylistStatics(std::nullptr_t = nullptr) noexcept {}
        ILampArrayEffectPlaylistStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArraySolidEffect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArraySolidEffect>
    {
        ILampArraySolidEffect(std::nullptr_t = nullptr) noexcept {}
        ILampArraySolidEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArraySolidEffectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArraySolidEffectFactory>
    {
        ILampArraySolidEffectFactory(std::nullptr_t = nullptr) noexcept {}
        ILampArraySolidEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayUpdateRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayUpdateRequestedEventArgs>
    {
        ILampArrayUpdateRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILampArrayUpdateRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
