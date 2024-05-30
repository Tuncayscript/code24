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
#ifndef LLM_OS_UI_Core_Preview_1_H
#define LLM_OS_UI_Core_Preview_1_H
#include "llm/impl/Windows.UI.Core.Preview.0.h"
LLM_EXPORT namespace llm:OS::UI::Core::Preview
{
    struct __declspec(empty_bases) ICoreAppWindowPreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAppWindowPreview>
    {
        ICoreAppWindowPreview(std::nullptr_t = nullptr) noexcept {}
        ICoreAppWindowPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAppWindowPreviewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAppWindowPreviewStatics>
    {
        ICoreAppWindowPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreAppWindowPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationCloseRequestedPreviewEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        ISystemNavigationCloseRequestedPreviewEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationCloseRequestedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationManagerPreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationManagerPreview>
    {
        ISystemNavigationManagerPreview(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationManagerPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationManagerPreviewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationManagerPreviewStatics>
    {
        ISystemNavigationManagerPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationManagerPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
