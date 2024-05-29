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
#ifndef LLM_OS_Gaming_Input_Custom_2_H
#define LLM_OS_Gaming_Input_Custom_2_H
#include "llm/impl/Windows.Gaming.Input.1.h"
#include "llm/impl/Windows.Gaming.Input.Custom.1.h"
LLM_EXPORT namespace llm::OS::Gaming::Input::Custom
{
    struct GameControllerVersionInfo
    {
        uint16_t Major;
        uint16_t Minor;
        uint16_t Build;
        uint16_t Revision;
    };
    inline bool operator==(GameControllerVersionInfo const& left, GameControllerVersionInfo const& right) noexcept
    {
        return left.Major == right.Major && left.Minor == right.Minor && left.Build == right.Build && left.Revision == right.Revision;
    }
    inline bool operator!=(GameControllerVersionInfo const& left, GameControllerVersionInfo const& right) noexcept
    {
        return !(left == right);
    }
    struct GipFirmwareUpdateProgress
    {
        double PercentCompleted;
        uint32_t CurrentComponentId;
    };
    inline bool operator==(GipFirmwareUpdateProgress const& left, GipFirmwareUpdateProgress const& right) noexcept
    {
        return left.PercentCompleted == right.PercentCompleted && left.CurrentComponentId == right.CurrentComponentId;
    }
    inline bool operator!=(GipFirmwareUpdateProgress const& left, GipFirmwareUpdateProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct GameControllerFactoryManager
    {
        GameControllerFactoryManager() = delete;
        static auto RegisterCustomFactoryForGipInterface(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::guid const& interfaceId);
        static auto RegisterCustomFactoryForHardwareId(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, uint16_t hardwareVendorId, uint16_t hardwareProductId);
        static auto RegisterCustomFactoryForXusbType(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::Custom::XusbDeviceType const& xusbType, llm::OS::Gaming::Input::Custom::XusbDeviceSubtype const& xusbSubtype);
        static auto TryGetFactoryControllerFromGameController(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::IGameController const& gameController);
    };
    struct __declspec(empty_bases) GipFirmwareUpdateResult : llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult
    {
        GipFirmwareUpdateResult(std::nullptr_t) noexcept {}
        GipFirmwareUpdateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GipGameControllerProvider : llm::OS::Gaming::Input::Custom::IGipGameControllerProvider
    {
        GipGameControllerProvider(std::nullptr_t) noexcept {}
        GipGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::Custom::IGipGameControllerProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HidGameControllerProvider : llm::OS::Gaming::Input::Custom::IHidGameControllerProvider
    {
        HidGameControllerProvider(std::nullptr_t) noexcept {}
        HidGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::Custom::IHidGameControllerProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XusbGameControllerProvider : llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider
    {
        XusbGameControllerProvider(std::nullptr_t) noexcept {}
        XusbGameControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider(ptr, take_ownership_from_abi) {}
    };
}
#endif
