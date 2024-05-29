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
#ifndef LLM_OS_Devices_Scanners_2_H
#define LLM_OS_Devices_Scanners_2_H
#include "llm/impl/Windows.Devices.Scanners.1.h"
LLM_EXPORT namespace llm::OS::Devices::Scanners
{
    struct ImageScannerResolution
    {
        float DpiX;
        float DpiY;
    };
    inline bool operator==(ImageScannerResolution const& left, ImageScannerResolution const& right) noexcept
    {
        return left.DpiX == right.DpiX && left.DpiY == right.DpiY;
    }
    inline bool operator!=(ImageScannerResolution const& left, ImageScannerResolution const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ImageScanner : llm::OS::Devices::Scanners::IImageScanner
    {
        ImageScanner(std::nullptr_t) noexcept {}
        ImageScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScanner(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) ImageScannerAutoConfiguration : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration
    {
        ImageScannerAutoConfiguration(std::nullptr_t) noexcept {}
        ImageScannerAutoConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageScannerFeederConfiguration : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration,
        impl::require<ImageScannerFeederConfiguration, llm::OS::Devices::Scanners::IImageScannerSourceConfiguration, llm::OS::Devices::Scanners::IImageScannerFeederConfiguration>
    {
        ImageScannerFeederConfiguration(std::nullptr_t) noexcept {}
        ImageScannerFeederConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageScannerFlatbedConfiguration : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration,
        impl::require<ImageScannerFlatbedConfiguration, llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        ImageScannerFlatbedConfiguration(std::nullptr_t) noexcept {}
        ImageScannerFlatbedConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScannerFormatConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageScannerPreviewResult : llm::OS::Devices::Scanners::IImageScannerPreviewResult
    {
        ImageScannerPreviewResult(std::nullptr_t) noexcept {}
        ImageScannerPreviewResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScannerPreviewResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ImageScannerScanResult : llm::OS::Devices::Scanners::IImageScannerScanResult
    {
        ImageScannerScanResult(std::nullptr_t) noexcept {}
        ImageScannerScanResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Scanners::IImageScannerScanResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
