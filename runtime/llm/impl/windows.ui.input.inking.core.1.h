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
#ifndef LLM_OS_UI_Input_Inking_Core_1_H
#define LLM_OS_UI_Input_Inking_Core_1_H
#include "llm/impl/Windows.UI.Input.Inking.Core.0.h"
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Core
{
    struct __declspec(empty_bases) ICoreIncrementalInkStroke :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreIncrementalInkStroke>
    {
        ICoreIncrementalInkStroke(std::nullptr_t = nullptr) noexcept {}
        ICoreIncrementalInkStroke(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreIncrementalInkStrokeFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreIncrementalInkStrokeFactory>
    {
        ICoreIncrementalInkStrokeFactory(std::nullptr_t = nullptr) noexcept {}
        ICoreIncrementalInkStrokeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInkIndependentInputSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInkIndependentInputSource>
    {
        ICoreInkIndependentInputSource(std::nullptr_t = nullptr) noexcept {}
        ICoreInkIndependentInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInkIndependentInputSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInkIndependentInputSource2>
    {
        ICoreInkIndependentInputSource2(std::nullptr_t = nullptr) noexcept {}
        ICoreInkIndependentInputSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInkIndependentInputSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInkIndependentInputSourceStatics>
    {
        ICoreInkIndependentInputSourceStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreInkIndependentInputSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInkPresenterHost :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInkPresenterHost>
    {
        ICoreInkPresenterHost(std::nullptr_t = nullptr) noexcept {}
        ICoreInkPresenterHost(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWetStrokeUpdateEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWetStrokeUpdateEventArgs>
    {
        ICoreWetStrokeUpdateEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreWetStrokeUpdateEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWetStrokeUpdateSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWetStrokeUpdateSource>
    {
        ICoreWetStrokeUpdateSource(std::nullptr_t = nullptr) noexcept {}
        ICoreWetStrokeUpdateSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWetStrokeUpdateSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWetStrokeUpdateSourceStatics>
    {
        ICoreWetStrokeUpdateSourceStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreWetStrokeUpdateSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
