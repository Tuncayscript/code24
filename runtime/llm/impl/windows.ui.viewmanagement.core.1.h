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
#ifndef LLM_OS_UI_ViewManagement_Core_1_H
#define LLM_OS_UI_ViewManagement_Core_1_H
#include "llm/impl/Windows.UI.ViewManagement.Core.0.h"
LLM_EXPORT namespace llm:OS::UI::ViewManagement::Core
{
    struct __declspec(empty_bases) ICoreFrameworkInputView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreFrameworkInputView>
    {
        ICoreFrameworkInputView(std::nullptr_t = nullptr) noexcept {}
        ICoreFrameworkInputView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreFrameworkInputViewAnimationStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreFrameworkInputViewAnimationStartingEventArgs>
    {
        ICoreFrameworkInputViewAnimationStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreFrameworkInputViewAnimationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreFrameworkInputViewOcclusionsChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreFrameworkInputViewOcclusionsChangedEventArgs>
    {
        ICoreFrameworkInputViewOcclusionsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreFrameworkInputViewOcclusionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreFrameworkInputViewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreFrameworkInputViewStatics>
    {
        ICoreFrameworkInputViewStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreFrameworkInputViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputView>
    {
        ICoreInputView(std::nullptr_t = nullptr) noexcept {}
        ICoreInputView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputView2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputView2>
    {
        ICoreInputView2(std::nullptr_t = nullptr) noexcept {}
        ICoreInputView2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputView3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputView3>
    {
        ICoreInputView3(std::nullptr_t = nullptr) noexcept {}
        ICoreInputView3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputView4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputView4>
    {
        ICoreInputView4(std::nullptr_t = nullptr) noexcept {}
        ICoreInputView4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputView5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputView5>
    {
        ICoreInputView5(std::nullptr_t = nullptr) noexcept {}
        ICoreInputView5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewAnimationStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewAnimationStartingEventArgs>
    {
        ICoreInputViewAnimationStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewAnimationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewHidingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewHidingEventArgs>
    {
        ICoreInputViewHidingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewHidingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewOcclusion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewOcclusion>
    {
        ICoreInputViewOcclusion(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewOcclusion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewOcclusionsChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewOcclusionsChangedEventArgs>
    {
        ICoreInputViewOcclusionsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewOcclusionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewShowingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewShowingEventArgs>
    {
        ICoreInputViewShowingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewStatics>
    {
        ICoreInputViewStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewStatics2>
    {
        ICoreInputViewStatics2(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputViewTransferringXYFocusEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputViewTransferringXYFocusEventArgs>
    {
        ICoreInputViewTransferringXYFocusEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreInputViewTransferringXYFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettingsController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettingsController>
    {
        IUISettingsController(std::nullptr_t = nullptr) noexcept {}
        IUISettingsController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettingsControllerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettingsControllerStatics>
    {
        IUISettingsControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IUISettingsControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
