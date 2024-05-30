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
#ifndef LLM_OS_UI_WindowManagement_1_H
#define LLM_OS_UI_WindowManagement_1_H
#include "llm/impl/Windows.UI.WindowManagement.0.h"
LLM_EXPORT namespace llm::OS::UI::WindowManagement
{
    struct __declspec(empty_bases) IAppWindow :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindow>
    {
        IAppWindow(std::nullptr_t = nullptr) noexcept {}
        IAppWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowChangedEventArgs>
    {
        IAppWindowChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppWindowChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowCloseRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowCloseRequestedEventArgs>
    {
        IAppWindowCloseRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppWindowCloseRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowClosedEventArgs>
    {
        IAppWindowClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppWindowClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowFrame>
    {
        IAppWindowFrame(std::nullptr_t = nullptr) noexcept {}
        IAppWindowFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowFrameStyle :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowFrameStyle>
    {
        IAppWindowFrameStyle(std::nullptr_t = nullptr) noexcept {}
        IAppWindowFrameStyle(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowPlacement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowPlacement>
    {
        IAppWindowPlacement(std::nullptr_t = nullptr) noexcept {}
        IAppWindowPlacement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowPresentationConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowPresentationConfiguration>
    {
        IAppWindowPresentationConfiguration(std::nullptr_t = nullptr) noexcept {}
        IAppWindowPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowPresentationConfigurationFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowPresentationConfigurationFactory>
    {
        IAppWindowPresentationConfigurationFactory(std::nullptr_t = nullptr) noexcept {}
        IAppWindowPresentationConfigurationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowPresenter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowPresenter>
    {
        IAppWindowPresenter(std::nullptr_t = nullptr) noexcept {}
        IAppWindowPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowStatics>
    {
        IAppWindowStatics(std::nullptr_t = nullptr) noexcept {}
        IAppWindowStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowTitleBar :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowTitleBar>
    {
        IAppWindowTitleBar(std::nullptr_t = nullptr) noexcept {}
        IAppWindowTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowTitleBarOcclusion :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowTitleBarOcclusion>
    {
        IAppWindowTitleBarOcclusion(std::nullptr_t = nullptr) noexcept {}
        IAppWindowTitleBarOcclusion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppWindowTitleBarVisibility :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppWindowTitleBarVisibility>
    {
        IAppWindowTitleBarVisibility(std::nullptr_t = nullptr) noexcept {}
        IAppWindowTitleBarVisibility(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompactOverlayPresentationConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICompactOverlayPresentationConfiguration>
    {
        ICompactOverlayPresentationConfiguration(std::nullptr_t = nullptr) noexcept {}
        ICompactOverlayPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDefaultPresentationConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDefaultPresentationConfiguration>
    {
        IDefaultPresentationConfiguration(std::nullptr_t = nullptr) noexcept {}
        IDefaultPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDisplayRegion :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDisplayRegion>
    {
        IDisplayRegion(std::nullptr_t = nullptr) noexcept {}
        IDisplayRegion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFullScreenPresentationConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFullScreenPresentationConfiguration>
    {
        IFullScreenPresentationConfiguration(std::nullptr_t = nullptr) noexcept {}
        IFullScreenPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowServicesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowServicesStatics>
    {
        IWindowServicesStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowServicesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowingEnvironment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowingEnvironment>
    {
        IWindowingEnvironment(std::nullptr_t = nullptr) noexcept {}
        IWindowingEnvironment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowingEnvironmentAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowingEnvironmentAddedEventArgs>
    {
        IWindowingEnvironmentAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowingEnvironmentAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowingEnvironmentChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowingEnvironmentChangedEventArgs>
    {
        IWindowingEnvironmentChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowingEnvironmentChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowingEnvironmentRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowingEnvironmentRemovedEventArgs>
    {
        IWindowingEnvironmentRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowingEnvironmentRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowingEnvironmentStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWindowingEnvironmentStatics>
    {
        IWindowingEnvironmentStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowingEnvironmentStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
