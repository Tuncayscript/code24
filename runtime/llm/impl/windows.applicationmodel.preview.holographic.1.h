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
#ifndef LLM_OS_ApplicationModel_Preview_Holographic_1_H
#define LLM_OS_ApplicationModel_Preview_Holographic_1_H
#include "llm/impl/Windows.ApplicationModel.Preview.Holographic.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Preview::Holographic
{
    struct __declspec(empty_bases) IHolographicApplicationPreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHolographicApplicationPreviewStatics>
    {
        IHolographicApplicationPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        IHolographicApplicationPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicKeyboardPlacementOverridePreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHolographicKeyboardPlacementOverridePreview>
    {
        IHolographicKeyboardPlacementOverridePreview(std::nullptr_t = nullptr) noexcept {}
        IHolographicKeyboardPlacementOverridePreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHolographicKeyboardPlacementOverridePreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHolographicKeyboardPlacementOverridePreviewStatics>
    {
        IHolographicKeyboardPlacementOverridePreviewStatics(std::nullptr_t = nullptr) noexcept {}
        IHolographicKeyboardPlacementOverridePreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
