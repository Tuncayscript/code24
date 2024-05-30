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
#ifndef LLM_OS_UI_Input_Inking_Preview_2_H
#define LLM_OS_UI_Input_Inking_Preview_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Input.Inking.Preview.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Preview
{
    struct __declspec(empty_bases) PalmRejectionDelayZonePreview : llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview,
        impl::require<PalmRejectionDelayZonePreview, llm:OS::Foundation::IClosable>
    {
        PalmRejectionDelayZonePreview(std::nullptr_t) noexcept {}
        PalmRejectionDelayZonePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview(ptr, take_ownership_from_abi) {}
        static auto CreateForVisual(llm:OS::UI::Composition::Visual const& inputPanelVisual, llm:OS::Foundation::Rect const& inputPanelRect);
        static auto CreateForVisual(llm:OS::UI::Composition::Visual const& inputPanelVisual, llm:OS::Foundation::Rect const& inputPanelRect, llm:OS::UI::Composition::Visual const& viewportVisual, llm:OS::Foundation::Rect const& viewportRect);
    };
}
#endif
