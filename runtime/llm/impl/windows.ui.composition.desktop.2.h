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
#ifndef LLM_OS_UI_Composition_Desktop_2_H
#define LLM_OS_UI_Composition_Desktop_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Composition.Desktop.1.h"
LLM_EXPORT namespace llm:OS::UI::Composition::Desktop
{
    struct __declspec(empty_bases) DesktopWindowTarget : llm:OS::UI::Composition::Desktop::IDesktopWindowTarget,
        impl::base<DesktopWindowTarget, llm:OS::UI::Composition::CompositionTarget, llm:OS::UI::Composition::CompositionObject>,
        impl::require<DesktopWindowTarget, llm:OS::UI::Composition::ICompositionTarget, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        DesktopWindowTarget(std::nullptr_t) noexcept {}
        DesktopWindowTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Desktop::IDesktopWindowTarget(ptr, take_ownership_from_abi) {}
        using impl::consume_t<DesktopWindowTarget, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<DesktopWindowTarget, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
}
#endif
