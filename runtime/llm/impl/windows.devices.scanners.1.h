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
#ifndef LLM_OS_Devices_Scanners_1_H
#define LLM_OS_Devices_Scanners_1_H
#include "llm/impl/Windows.Devices.Scanners.0.h"
LLM_EXPORT namespace llm::OS::Devices::Scanners
{
    struct __declspec(empty_bases) IImageScanner :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScanner>
    {
        IImageScanner(std::nullptr_t = nullptr) noexcept {}
        IImageScanner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerFeederConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerFeederConfiguration>,
        impl::require<llm::OS::Devices::Scanners::IImageScannerFeederConfiguration, llm::OS::Devices::Scanners::IImageScannerFormatConfiguration, llm::OS::Devices::Scanners::IImageScannerSourceConfiguration>
    {
        IImageScannerFeederConfiguration(std::nullptr_t = nullptr) noexcept {}
        IImageScannerFeederConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerFormatConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerFormatConfiguration>
    {
        IImageScannerFormatConfiguration(std::nullptr_t = nullptr) noexcept {}
        IImageScannerFormatConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerPreviewResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerPreviewResult>
    {
        IImageScannerPreviewResult(std::nullptr_t = nullptr) noexcept {}
        IImageScannerPreviewResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerScanResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerScanResult>
    {
        IImageScannerScanResult(std::nullptr_t = nullptr) noexcept {}
        IImageScannerScanResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerSourceConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerSourceConfiguration>,
        impl::require<llm::OS::Devices::Scanners::IImageScannerSourceConfiguration, llm::OS::Devices::Scanners::IImageScannerFormatConfiguration>
    {
        IImageScannerSourceConfiguration(std::nullptr_t = nullptr) noexcept {}
        IImageScannerSourceConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IImageScannerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IImageScannerStatics>
    {
        IImageScannerStatics(std::nullptr_t = nullptr) noexcept {}
        IImageScannerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
