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
#ifndef LLM_OS_UI_Input_Inking_Core_2_H
#define LLM_OS_UI_Input_Inking_Core_2_H
#include "llm/impl/Windows.Foundation.Numerics.1.h"
#include "llm/impl/Windows.UI.Input.Inking.1.h"
#include "llm/impl/Windows.UI.Input.Inking.Core.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Core
{
    struct __declspec(empty_bases) CoreIncrementalInkStroke : llm:OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke
    {
        CoreIncrementalInkStroke(std::nullptr_t) noexcept {}
        CoreIncrementalInkStroke(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke(ptr, take_ownership_from_abi) {}
        CoreIncrementalInkStroke(llm:OS::UI::Input::Inking::InkDrawingAttributes const& drawingAttributes, llm:OS::Foundation::Numerics::float3x2 const& pointTransform);
    };
    struct __declspec(empty_bases) CoreInkIndependentInputSource : llm:OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource,
        impl::require<CoreInkIndependentInputSource, llm:OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2>
    {
        CoreInkIndependentInputSource(std::nullptr_t) noexcept {}
        CoreInkIndependentInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource(ptr, take_ownership_from_abi) {}
        static auto Create(llm:OS::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
    struct __declspec(empty_bases) CoreInkPresenterHost : llm:OS::UI::Input::Inking::Core::ICoreInkPresenterHost
    {
        CoreInkPresenterHost(std::nullptr_t) noexcept {}
        CoreInkPresenterHost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Core::ICoreInkPresenterHost(ptr, take_ownership_from_abi) {}
        CoreInkPresenterHost();
    };
    struct __declspec(empty_bases) CoreWetStrokeUpdateEventArgs : llm:OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs
    {
        CoreWetStrokeUpdateEventArgs(std::nullptr_t) noexcept {}
        CoreWetStrokeUpdateEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreWetStrokeUpdateSource : llm:OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource
    {
        CoreWetStrokeUpdateSource(std::nullptr_t) noexcept {}
        CoreWetStrokeUpdateSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource(ptr, take_ownership_from_abi) {}
        static auto Create(llm:OS::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
}
#endif
