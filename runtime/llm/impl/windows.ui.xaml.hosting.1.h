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
#ifndef LLM_OS_UI_Xaml_Hosting_1_H
#define LLM_OS_UI_Xaml_Hosting_1_H
#include "llm/impl/Windows.UI.Xaml.Hosting.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Hosting
{
    struct __declspec(empty_bases) IDesignerAppExitedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignerAppExitedEventArgs>
    {
        IDesignerAppExitedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDesignerAppExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesignerAppManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignerAppManager>
    {
        IDesignerAppManager(std::nullptr_t = nullptr) noexcept {}
        IDesignerAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesignerAppManagerFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignerAppManagerFactory>
    {
        IDesignerAppManagerFactory(std::nullptr_t = nullptr) noexcept {}
        IDesignerAppManagerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesignerAppView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesignerAppView>
    {
        IDesignerAppView(std::nullptr_t = nullptr) noexcept {}
        IDesignerAppView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesktopWindowXamlSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesktopWindowXamlSource>
    {
        IDesktopWindowXamlSource(std::nullptr_t = nullptr) noexcept {}
        IDesktopWindowXamlSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesktopWindowXamlSourceFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesktopWindowXamlSourceFactory>
    {
        IDesktopWindowXamlSourceFactory(std::nullptr_t = nullptr) noexcept {}
        IDesktopWindowXamlSourceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesktopWindowXamlSourceGotFocusEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesktopWindowXamlSourceGotFocusEventArgs>
    {
        IDesktopWindowXamlSourceGotFocusEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDesktopWindowXamlSourceGotFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDesktopWindowXamlSourceTakeFocusRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDesktopWindowXamlSourceTakeFocusRequestedEventArgs>
    {
        IDesktopWindowXamlSourceTakeFocusRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDesktopWindowXamlSourceTakeFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IElementCompositionPreview :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IElementCompositionPreview>
    {
        IElementCompositionPreview(std::nullptr_t = nullptr) noexcept {}
        IElementCompositionPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IElementCompositionPreviewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IElementCompositionPreviewStatics>
    {
        IElementCompositionPreviewStatics(std::nullptr_t = nullptr) noexcept {}
        IElementCompositionPreviewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IElementCompositionPreviewStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IElementCompositionPreviewStatics2>
    {
        IElementCompositionPreviewStatics2(std::nullptr_t = nullptr) noexcept {}
        IElementCompositionPreviewStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IElementCompositionPreviewStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IElementCompositionPreviewStatics3>
    {
        IElementCompositionPreviewStatics3(std::nullptr_t = nullptr) noexcept {}
        IElementCompositionPreviewStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsXamlManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowsXamlManager>
    {
        IWindowsXamlManager(std::nullptr_t = nullptr) noexcept {}
        IWindowsXamlManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsXamlManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowsXamlManagerStatics>
    {
        IWindowsXamlManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowsXamlManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlSourceFocusNavigationRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlSourceFocusNavigationRequest>
    {
        IXamlSourceFocusNavigationRequest(std::nullptr_t = nullptr) noexcept {}
        IXamlSourceFocusNavigationRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlSourceFocusNavigationRequestFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlSourceFocusNavigationRequestFactory>
    {
        IXamlSourceFocusNavigationRequestFactory(std::nullptr_t = nullptr) noexcept {}
        IXamlSourceFocusNavigationRequestFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlSourceFocusNavigationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlSourceFocusNavigationResult>
    {
        IXamlSourceFocusNavigationResult(std::nullptr_t = nullptr) noexcept {}
        IXamlSourceFocusNavigationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlSourceFocusNavigationResultFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlSourceFocusNavigationResultFactory>
    {
        IXamlSourceFocusNavigationResultFactory(std::nullptr_t = nullptr) noexcept {}
        IXamlSourceFocusNavigationResultFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenter>
    {
        IXamlUIPresenter(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenterHost :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenterHost>
    {
        IXamlUIPresenterHost(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenterHost(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenterHost2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenterHost2>
    {
        IXamlUIPresenterHost2(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenterHost2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenterHost3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenterHost3>
    {
        IXamlUIPresenterHost3(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenterHost3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenterStatics>
    {
        IXamlUIPresenterStatics(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXamlUIPresenterStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXamlUIPresenterStatics2>
    {
        IXamlUIPresenterStatics2(std::nullptr_t = nullptr) noexcept {}
        IXamlUIPresenterStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
