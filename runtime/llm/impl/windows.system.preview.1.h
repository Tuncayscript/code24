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
#ifndef LLM_OS_System_Preview_1_H
#define LLM_OS_System_Preview_1_H
#include "llm/impl/Windows.System.Preview.0.h"
LLM_EXPORT namespace llm:OS::System::Preview
{
    struct __declspec(empty_bases) ITwoPanelHingedDevicePosturePreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITwoPanelHingedDevicePosturePreview>
    {
        ITwoPanelHingedDevicePosturePreview(std::nullptr_t = nullptr) noexcept {}
        ITwoPanelHingedDevicePosturePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITwoPanelHingedDevicePosturePreviewReading :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITwoPanelHingedDevicePosturePreviewReading>
    {
        ITwoPanelHingedDevicePosturePreviewReading(std::nullptr_t = nullptr) noexcept {}
        ITwoPanelHingedDevicePosturePreviewReading(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs>
    {
        ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITwoPanelHingedDevicePosturePreviewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITwoPanelHingedDevicePosturePreviewStatics>
    {
        ITwoPanelHingedDevicePosturePreviewStatics(std::nullptr_t = nullptr) noexcept {}
        ITwoPanelHingedDevicePosturePreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
