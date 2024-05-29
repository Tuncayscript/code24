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
#ifndef LLM_OS_Devices_Haptics_2_H
#define LLM_OS_Devices_Haptics_2_H
#include "llm/impl/Windows.Devices.Haptics.1.h"
LLM_EXPORT namespace llm::OS::Devices::Haptics
{
    struct KnownSimpleHapticsControllerWaveforms
    {
        KnownSimpleHapticsControllerWaveforms() = delete;
        [[nodiscard]] static auto Click();
        [[nodiscard]] static auto BuzzContinuous();
        [[nodiscard]] static auto RumbleContinuous();
        [[nodiscard]] static auto Press();
        [[nodiscard]] static auto Release();
        [[nodiscard]] static auto BrushContinuous();
        [[nodiscard]] static auto ChiselMarkerContinuous();
        [[nodiscard]] static auto EraserContinuous();
        [[nodiscard]] static auto Error();
        [[nodiscard]] static auto GalaxyPenContinuous();
        [[nodiscard]] static auto Hover();
        [[nodiscard]] static auto InkContinuous();
        [[nodiscard]] static auto MarkerContinuous();
        [[nodiscard]] static auto PencilContinuous();
        [[nodiscard]] static auto Success();
    };
    struct __declspec(empty_bases) SimpleHapticsController : llm::OS::Devices::Haptics::ISimpleHapticsController
    {
        SimpleHapticsController(std::nullptr_t) noexcept {}
        SimpleHapticsController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Haptics::ISimpleHapticsController(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SimpleHapticsControllerFeedback : llm::OS::Devices::Haptics::ISimpleHapticsControllerFeedback
    {
        SimpleHapticsControllerFeedback(std::nullptr_t) noexcept {}
        SimpleHapticsControllerFeedback(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Haptics::ISimpleHapticsControllerFeedback(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VibrationDevice : llm::OS::Devices::Haptics::IVibrationDevice
    {
        VibrationDevice(std::nullptr_t) noexcept {}
        VibrationDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Haptics::IVibrationDevice(ptr, take_ownership_from_abi) {}
        static auto RequestAccessAsync();
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
        static auto FindAllAsync();
    };
}
#endif
