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
#ifndef LLM_OS_Media_Casting_2_H
#define LLM_OS_Media_Casting_2_H
#include "llm/impl/Windows.Devices.Enumeration.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Casting.1.h"
LLM_EXPORT namespace llm:OS::Media::Casting
{
    struct __declspec(empty_bases) CastingConnection : llm:OS::Media::Casting::ICastingConnection
    {
        CastingConnection(std::nullptr_t) noexcept {}
        CastingConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CastingConnectionErrorOccurredEventArgs : llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs
    {
        CastingConnectionErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        CastingConnectionErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingConnectionErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CastingDevice : llm:OS::Media::Casting::ICastingDevice
    {
        CastingDevice(std::nullptr_t) noexcept {}
        CastingDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(llm:OS::Media::Casting::CastingPlaybackTypes const& type);
        static auto GetDeviceSelectorFromCastingSourceAsync(llm:OS::Media::Casting::CastingSource const& castingSource);
        static auto FromIdAsync(param::hstring const& value);
        static auto DeviceInfoSupportsCastingAsync(llm:OS::Devices::Enumeration::DeviceInformation const& device);
    };
    struct __declspec(empty_bases) CastingDevicePicker : llm:OS::Media::Casting::ICastingDevicePicker
    {
        CastingDevicePicker(std::nullptr_t) noexcept {}
        CastingDevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingDevicePicker(ptr, take_ownership_from_abi) {}
        CastingDevicePicker();
    };
    struct __declspec(empty_bases) CastingDevicePickerFilter : llm:OS::Media::Casting::ICastingDevicePickerFilter
    {
        CastingDevicePickerFilter(std::nullptr_t) noexcept {}
        CastingDevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingDevicePickerFilter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CastingDeviceSelectedEventArgs : llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs
    {
        CastingDeviceSelectedEventArgs(std::nullptr_t) noexcept {}
        CastingDeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingDeviceSelectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CastingSource : llm:OS::Media::Casting::ICastingSource
    {
        CastingSource(std::nullptr_t) noexcept {}
        CastingSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Casting::ICastingSource(ptr, take_ownership_from_abi) {}
    };
}
#endif
