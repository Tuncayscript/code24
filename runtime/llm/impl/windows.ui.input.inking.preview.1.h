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
#ifndef LLM_OS_UI_Input_Inking_Preview_1_H
#define LLM_OS_UI_Input_Inking_Preview_1_H
#include "llm/impl/Windows.UI.Input.Inking.Preview.0.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Preview
{
    struct __declspec(empty_bases) IPalmRejectionDelayZonePreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPalmRejectionDelayZonePreview>
    {
        IPalmRejectionDelayZonePreview(std::nullptr_t = nullptr) noexcept {}
        IPalmRejectionDelayZonePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPalmRejectionDelayZonePreviewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPalmRejectionDelayZonePreviewStatics>
    {
        IPalmRejectionDelayZonePreviewStatics(std::nullptr_t = nullptr) noexcept {}
        IPalmRejectionDelayZonePreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
