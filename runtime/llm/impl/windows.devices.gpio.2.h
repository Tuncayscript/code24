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
#ifndef LLM_OS_Devices_Gpio_2_H
#define LLM_OS_Devices_Gpio_2_H
#include "llm/impl/Windows.Devices.Gpio.Provider.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Devices.Gpio.1.h"
LLM_EXPORT namespace llm::OS::Devices::Gpio
{
    struct GpioChangeCount
    {
        uint64_t Count;
        llm::OS::Foundation::TimeSpan RelativeTime;
    };
    inline bool operator==(GpioChangeCount const& left, GpioChangeCount const& right) noexcept
    {
        return left.Count == right.Count && left.RelativeTime == right.RelativeTime;
    }
    inline bool operator!=(GpioChangeCount const& left, GpioChangeCount const& right) noexcept
    {
        return !(left == right);
    }
    struct GpioChangeRecord
    {
        llm::OS::Foundation::TimeSpan RelativeTime;
        llm::OS::Devices::Gpio::GpioPinEdge Edge;
    };
    inline bool operator==(GpioChangeRecord const& left, GpioChangeRecord const& right) noexcept
    {
        return left.RelativeTime == right.RelativeTime && left.Edge == right.Edge;
    }
    inline bool operator!=(GpioChangeRecord const& left, GpioChangeRecord const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) GpioChangeCounter : llm::OS::Devices::Gpio::IGpioChangeCounter
    {
        GpioChangeCounter(std::nullptr_t) noexcept {}
        GpioChangeCounter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Gpio::IGpioChangeCounter(ptr, take_ownership_from_abi) {}
        explicit GpioChangeCounter(llm::OS::Devices::Gpio::GpioPin const& pin);
    };
    struct __declspec(empty_bases) GpioChangeReader : llm::OS::Devices::Gpio::IGpioChangeReader
    {
        GpioChangeReader(std::nullptr_t) noexcept {}
        GpioChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Gpio::IGpioChangeReader(ptr, take_ownership_from_abi) {}
        explicit GpioChangeReader(llm::OS::Devices::Gpio::GpioPin const& pin);
        GpioChangeReader(llm::OS::Devices::Gpio::GpioPin const& pin, int32_t minCapacity);
    };
    struct __declspec(empty_bases) GpioController : llm::OS::Devices::Gpio::IGpioController
    {
        GpioController(std::nullptr_t) noexcept {}
        GpioController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Gpio::IGpioController(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetControllersAsync(llm::OS::Devices::Gpio::Provider::IGpioProvider const& provider);
        static auto GetDefaultAsync();
    };
    struct __declspec(empty_bases) GpioPin : llm::OS::Devices::Gpio::IGpioPin
    {
        GpioPin(std::nullptr_t) noexcept {}
        GpioPin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Gpio::IGpioPin(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GpioPinValueChangedEventArgs : llm::OS::Devices::Gpio::IGpioPinValueChangedEventArgs
    {
        GpioPinValueChangedEventArgs(std::nullptr_t) noexcept {}
        GpioPinValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Gpio::IGpioPinValueChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
