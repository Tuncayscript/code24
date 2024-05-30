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
#ifndef LLM_OS_System_Preview_2_H
#define LLM_OS_System_Preview_2_H
#include "llm/impl/Windows.System.Preview.1.h"
LLM_EXPORT namespace llm:OS::System::Preview
{
    struct __declspec(empty_bases) TwoPanelHingedDevicePosturePreview : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview
    {
        TwoPanelHingedDevicePosturePreview(std::nullptr_t) noexcept {}
        TwoPanelHingedDevicePosturePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreview(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
    };
    struct __declspec(empty_bases) TwoPanelHingedDevicePosturePreviewReading : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading
    {
        TwoPanelHingedDevicePosturePreviewReading(std::nullptr_t) noexcept {}
        TwoPanelHingedDevicePosturePreviewReading(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs
    {
        TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs(std::nullptr_t) noexcept {}
        TwoPanelHingedDevicePosturePreviewReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Preview::ITwoPanelHingedDevicePosturePreviewReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
