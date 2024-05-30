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
#ifndef LLM_OS_UI_Core_Preview_2_H
#define LLM_OS_UI_Core_Preview_2_H
#include "llm/impl/Windows.UI.WindowManagement.1.h"
#include "llm/impl/Windows.UI.Core.Preview.1.h"
LLM_EXPORT namespace llm:OS::UI::Core::Preview
{
    struct __declspec(empty_bases) CoreAppWindowPreview : llm:OS::UI::Core::Preview::ICoreAppWindowPreview
    {
        CoreAppWindowPreview(std::nullptr_t) noexcept {}
        CoreAppWindowPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::Preview::ICoreAppWindowPreview(ptr, take_ownership_from_abi) {}
        static auto GetIdFromWindow(llm:OS::UI::WindowManagement::AppWindow const& window);
    };
    struct __declspec(empty_bases) SystemNavigationCloseRequestedPreviewEventArgs : llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs
    {
        SystemNavigationCloseRequestedPreviewEventArgs(std::nullptr_t) noexcept {}
        SystemNavigationCloseRequestedPreviewEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemNavigationManagerPreview : llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview
    {
        SystemNavigationManagerPreview(std::nullptr_t) noexcept {}
        SystemNavigationManagerPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::Preview::ISystemNavigationManagerPreview(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
}
#endif
