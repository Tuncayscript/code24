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
#ifndef LLM_OS_Devices_Lights_Effects_2_H
#define LLM_OS_Devices_Lights_Effects_2_H
#include "llm/impl/Windows.Devices.Lights.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Devices.Lights.Effects.1.h"
LLM_EXPORT namespace llm::OS::Devices::Lights::Effects
{
    struct __declspec(empty_bases) LampArrayBitmapEffect : llm::OS::Devices::Lights::Effects::ILampArrayBitmapEffect,
        impl::require<LampArrayBitmapEffect, llm::OS::Devices::Lights::Effects::ILampArrayEffect>
    {
        LampArrayBitmapEffect(std::nullptr_t) noexcept {}
        LampArrayBitmapEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayBitmapEffect(ptr, take_ownership_from_abi) {}
        LampArrayBitmapEffect(llm::OS::Devices::Lights::LampArray const& lampArray, array_view<int32_t const> lampIndexes);
    };
    struct __declspec(empty_bases) LampArrayBitmapRequestedEventArgs : llm::OS::Devices::Lights::Effects::ILampArrayBitmapRequestedEventArgs
    {
        LampArrayBitmapRequestedEventArgs(std::nullptr_t) noexcept {}
        LampArrayBitmapRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayBitmapRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LampArrayBlinkEffect : llm::OS::Devices::Lights::Effects::ILampArrayBlinkEffect,
        impl::require<LampArrayBlinkEffect, llm::OS::Devices::Lights::Effects::ILampArrayEffect>
    {
        LampArrayBlinkEffect(std::nullptr_t) noexcept {}
        LampArrayBlinkEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayBlinkEffect(ptr, take_ownership_from_abi) {}
        LampArrayBlinkEffect(llm::OS::Devices::Lights::LampArray const& lampArray, array_view<int32_t const> lampIndexes);
    };
    struct __declspec(empty_bases) LampArrayColorRampEffect : llm::OS::Devices::Lights::Effects::ILampArrayColorRampEffect,
        impl::require<LampArrayColorRampEffect, llm::OS::Devices::Lights::Effects::ILampArrayEffect>
    {
        LampArrayColorRampEffect(std::nullptr_t) noexcept {}
        LampArrayColorRampEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayColorRampEffect(ptr, take_ownership_from_abi) {}
        LampArrayColorRampEffect(llm::OS::Devices::Lights::LampArray const& lampArray, array_view<int32_t const> lampIndexes);
    };
    struct __declspec(empty_bases) LampArrayCustomEffect : llm::OS::Devices::Lights::Effects::ILampArrayCustomEffect,
        impl::require<LampArrayCustomEffect, llm::OS::Devices::Lights::Effects::ILampArrayEffect>
    {
        LampArrayCustomEffect(std::nullptr_t) noexcept {}
        LampArrayCustomEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayCustomEffect(ptr, take_ownership_from_abi) {}
        LampArrayCustomEffect(llm::OS::Devices::Lights::LampArray const& lampArray, array_view<int32_t const> lampIndexes);
    };
    struct __declspec(empty_bases) LampArrayEffectPlaylist : llm::OS::Devices::Lights::Effects::ILampArrayEffectPlaylist,
        impl::require<LampArrayEffectPlaylist, llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Lights::Effects::ILampArrayEffect>, llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Lights::Effects::ILampArrayEffect>>
    {
        LampArrayEffectPlaylist(std::nullptr_t) noexcept {}
        LampArrayEffectPlaylist(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayEffectPlaylist(ptr, take_ownership_from_abi) {}
        LampArrayEffectPlaylist();
        static auto StartAll(param::iterable<llm::OS::Devices::Lights::Effects::LampArrayEffectPlaylist> const& value);
        static auto StopAll(param::iterable<llm::OS::Devices::Lights::Effects::LampArrayEffectPlaylist> const& value);
        static auto PauseAll(param::iterable<llm::OS::Devices::Lights::Effects::LampArrayEffectPlaylist> const& value);
    };
    struct __declspec(empty_bases) LampArraySolidEffect : llm::OS::Devices::Lights::Effects::ILampArraySolidEffect,
        impl::require<LampArraySolidEffect, llm::OS::Devices::Lights::Effects::ILampArrayEffect>
    {
        LampArraySolidEffect(std::nullptr_t) noexcept {}
        LampArraySolidEffect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArraySolidEffect(ptr, take_ownership_from_abi) {}
        LampArraySolidEffect(llm::OS::Devices::Lights::LampArray const& lampArray, array_view<int32_t const> lampIndexes);
    };
    struct __declspec(empty_bases) LampArrayUpdateRequestedEventArgs : llm::OS::Devices::Lights::Effects::ILampArrayUpdateRequestedEventArgs
    {
        LampArrayUpdateRequestedEventArgs(std::nullptr_t) noexcept {}
        LampArrayUpdateRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::Effects::ILampArrayUpdateRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
