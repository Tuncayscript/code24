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
#ifndef LLM_OS_ApplicationModel_Preview_Holographic_2_H
#define LLM_OS_ApplicationModel_Preview_Holographic_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.ApplicationModel.Preview.Holographic.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Holographic
{
    struct HolographicApplicationPreview
    {
        HolographicApplicationPreview() = delete;
        static auto IsCurrentViewPresentedOnHolographicDisplay();
        static auto IsHolographicActivation(llm::OS::ApplicationModel::Activation::IActivatedEventArgs const& activatedEventArgs);
    };
    struct __declspec(empty_bases) HolographicKeyboardPlacementOverridePreview : llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview
    {
        HolographicKeyboardPlacementOverridePreview(std::nullptr_t) noexcept {}
        HolographicKeyboardPlacementOverridePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Preview::Holographic::IHolographicKeyboardPlacementOverridePreview(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
}
#endif
