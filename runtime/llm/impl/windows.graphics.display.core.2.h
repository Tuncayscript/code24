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
#ifndef LLM_OS_Graphics_Display_Core_2_H
#define LLM_OS_Graphics_Display_Core_2_H
#include "llm/impl/Windows.Graphics.Display.Core.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Display::Core
{
    struct HdmiDisplayHdr2086Metadata
    {
        uint16_t RedPrimaryX;
        uint16_t RedPrimaryY;
        uint16_t GreenPrimaryX;
        uint16_t GreenPrimaryY;
        uint16_t BluePrimaryX;
        uint16_t BluePrimaryY;
        uint16_t WhitePointX;
        uint16_t WhitePointY;
        uint16_t MaxMasteringLuminance;
        uint16_t MinMasteringLuminance;
        uint16_t MaxContentLightLevel;
        uint16_t MaxFrameAverageLightLevel;
    };
    inline bool operator==(HdmiDisplayHdr2086Metadata const& left, HdmiDisplayHdr2086Metadata const& right) noexcept
    {
        return left.RedPrimaryX == right.RedPrimaryX && left.RedPrimaryY == right.RedPrimaryY && left.GreenPrimaryX == right.GreenPrimaryX && left.GreenPrimaryY == right.GreenPrimaryY && left.BluePrimaryX == right.BluePrimaryX && left.BluePrimaryY == right.BluePrimaryY && left.WhitePointX == right.WhitePointX && left.WhitePointY == right.WhitePointY && left.MaxMasteringLuminance == right.MaxMasteringLuminance && left.MinMasteringLuminance == right.MinMasteringLuminance && left.MaxContentLightLevel == right.MaxContentLightLevel && left.MaxFrameAverageLightLevel == right.MaxFrameAverageLightLevel;
    }
    inline bool operator!=(HdmiDisplayHdr2086Metadata const& left, HdmiDisplayHdr2086Metadata const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) HdmiDisplayInformation : llm:OS::Graphics::Display::Core::IHdmiDisplayInformation
    {
        HdmiDisplayInformation(std::nullptr_t) noexcept {}
        HdmiDisplayInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::Core::IHdmiDisplayInformation(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) HdmiDisplayMode : llm:OS::Graphics::Display::Core::IHdmiDisplayMode,
        impl::require<HdmiDisplayMode, llm:OS::Graphics::Display::Core::IHdmiDisplayMode2>
    {
        HdmiDisplayMode(std::nullptr_t) noexcept {}
        HdmiDisplayMode(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Display::Core::IHdmiDisplayMode(ptr, take_ownership_from_abi) {}
    };
}
#endif
