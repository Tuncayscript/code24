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
#ifndef LLM_OS_UI_ViewManagement_Core_2_H
#define LLM_OS_UI_ViewManagement_Core_2_H
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.UI.ViewManagement.Core.1.h"
LLM_EXPORT namespace llm:OS::UI::ViewManagement::Core
{
    struct __declspec(empty_bases) CoreFrameworkInputView : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView
    {
        CoreFrameworkInputView(std::nullptr_t) noexcept {}
        CoreFrameworkInputView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView(ptr, take_ownership_from_abi) {}
        static auto GetForUIContext(llm:OS::UI::UIContext const& context);
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) CoreFrameworkInputViewAnimationStartingEventArgs : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs
    {
        CoreFrameworkInputViewAnimationStartingEventArgs(std::nullptr_t) noexcept {}
        CoreFrameworkInputViewAnimationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreFrameworkInputViewOcclusionsChangedEventArgs : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs
    {
        CoreFrameworkInputViewOcclusionsChangedEventArgs(std::nullptr_t) noexcept {}
        CoreFrameworkInputViewOcclusionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputView : llm:OS::UI::ViewManagement::Core::ICoreInputView,
        impl::require<CoreInputView, llm:OS::UI::ViewManagement::Core::ICoreInputView2, llm:OS::UI::ViewManagement::Core::ICoreInputView3, llm:OS::UI::ViewManagement::Core::ICoreInputView4, llm:OS::UI::ViewManagement::Core::ICoreInputView5>
    {
        CoreInputView(std::nullptr_t) noexcept {}
        CoreInputView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputView(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto GetForUIContext(llm:OS::UI::UIContext const& context);
    };
    struct __declspec(empty_bases) CoreInputViewAnimationStartingEventArgs : llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs
    {
        CoreInputViewAnimationStartingEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewAnimationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputViewHidingEventArgs : llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs
    {
        CoreInputViewHidingEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewHidingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputViewOcclusion : llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion
    {
        CoreInputViewOcclusion(std::nullptr_t) noexcept {}
        CoreInputViewOcclusion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputViewOcclusionsChangedEventArgs : llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs
    {
        CoreInputViewOcclusionsChangedEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewOcclusionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputViewShowingEventArgs : llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs
    {
        CoreInputViewShowingEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreInputViewTransferringXYFocusEventArgs : llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs
    {
        CoreInputViewTransferringXYFocusEventArgs(std::nullptr_t) noexcept {}
        CoreInputViewTransferringXYFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UISettingsController : llm:OS::UI::ViewManagement::Core::IUISettingsController
    {
        UISettingsController(std::nullptr_t) noexcept {}
        UISettingsController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::Core::IUISettingsController(ptr, take_ownership_from_abi) {}
        static auto RequestDefaultAsync();
    };
}
#endif
