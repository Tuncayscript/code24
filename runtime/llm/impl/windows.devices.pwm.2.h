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
#ifndef LLM_OS_Devices_Pwm_2_H
#define LLM_OS_Devices_Pwm_2_H
#include "llm/impl/Windows.Devices.Pwm.Provider.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Pwm.1.h"
LLM_EXPORT namespace llm::OS::Devices::Pwm
{
    struct __declspec(empty_bases) PwmController : llm::OS::Devices::Pwm::IPwmController
    {
        PwmController(std::nullptr_t) noexcept {}
        PwmController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Pwm::IPwmController(ptr, take_ownership_from_abi) {}
        static auto GetControllersAsync(llm::OS::Devices::Pwm::Provider::IPwmProvider const& provider);
        static auto GetDefaultAsync();
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(param::hstring const& friendlyName);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) PwmPin : llm::OS::Devices::Pwm::IPwmPin
    {
        PwmPin(std::nullptr_t) noexcept {}
        PwmPin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Pwm::IPwmPin(ptr, take_ownership_from_abi) {}
    };
}
#endif
