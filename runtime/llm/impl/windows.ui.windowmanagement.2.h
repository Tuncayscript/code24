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
#ifndef LLM_OS_UI_WindowManagement_2_H
#define LLM_OS_UI_WindowManagement_2_H
#include "llm/impl/Windows.UI.WindowManagement.1.h"
LLM_EXPORT namespace llm::OS::UI::WindowManagement
{
    struct __declspec(empty_bases) AppWindow : llm::OS::UI::WindowManagement::IAppWindow
    {
        AppWindow(std::nullptr_t) noexcept {}
        AppWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindow(ptr, take_ownership_from_abi) {}
        static auto TryCreateAsync();
        static auto ClearAllPersistedState();
        static auto ClearPersistedState(param::hstring const& key);
    };
    struct __declspec(empty_bases) AppWindowChangedEventArgs : llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs
    {
        AppWindowChangedEventArgs(std::nullptr_t) noexcept {}
        AppWindowChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowCloseRequestedEventArgs : llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs
    {
        AppWindowCloseRequestedEventArgs(std::nullptr_t) noexcept {}
        AppWindowCloseRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowClosedEventArgs : llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs
    {
        AppWindowClosedEventArgs(std::nullptr_t) noexcept {}
        AppWindowClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowFrame : llm::OS::UI::WindowManagement::IAppWindowFrame,
        impl::require<AppWindowFrame, llm::OS::UI::WindowManagement::IAppWindowFrameStyle>
    {
        AppWindowFrame(std::nullptr_t) noexcept {}
        AppWindowFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowPlacement : llm::OS::UI::WindowManagement::IAppWindowPlacement
    {
        AppWindowPlacement(std::nullptr_t) noexcept {}
        AppWindowPlacement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowPlacement(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowPresentationConfiguration : llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration
    {
        AppWindowPresentationConfiguration(std::nullptr_t) noexcept {}
        AppWindowPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowPresenter : llm::OS::UI::WindowManagement::IAppWindowPresenter
    {
        AppWindowPresenter(std::nullptr_t) noexcept {}
        AppWindowPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowPresenter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowTitleBar : llm::OS::UI::WindowManagement::IAppWindowTitleBar,
        impl::require<AppWindowTitleBar, llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>
    {
        AppWindowTitleBar(std::nullptr_t) noexcept {}
        AppWindowTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowTitleBar(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppWindowTitleBarOcclusion : llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion
    {
        AppWindowTitleBarOcclusion(std::nullptr_t) noexcept {}
        AppWindowTitleBarOcclusion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CompactOverlayPresentationConfiguration : llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration,
        impl::base<CompactOverlayPresentationConfiguration, llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>,
        impl::require<CompactOverlayPresentationConfiguration, llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        CompactOverlayPresentationConfiguration(std::nullptr_t) noexcept {}
        CompactOverlayPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration(ptr, take_ownership_from_abi) {}
        CompactOverlayPresentationConfiguration();
    };
    struct __declspec(empty_bases) DefaultPresentationConfiguration : llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration,
        impl::base<DefaultPresentationConfiguration, llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>,
        impl::require<DefaultPresentationConfiguration, llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        DefaultPresentationConfiguration(std::nullptr_t) noexcept {}
        DefaultPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration(ptr, take_ownership_from_abi) {}
        DefaultPresentationConfiguration();
    };
    struct __declspec(empty_bases) DisplayRegion : llm::OS::UI::WindowManagement::IDisplayRegion
    {
        DisplayRegion(std::nullptr_t) noexcept {}
        DisplayRegion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IDisplayRegion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FullScreenPresentationConfiguration : llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration,
        impl::base<FullScreenPresentationConfiguration, llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>,
        impl::require<FullScreenPresentationConfiguration, llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        FullScreenPresentationConfiguration(std::nullptr_t) noexcept {}
        FullScreenPresentationConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration(ptr, take_ownership_from_abi) {}
        FullScreenPresentationConfiguration();
    };
    struct WindowServices
    {
        WindowServices() = delete;
        static auto FindAllTopLevelWindowIds();
    };
    struct __declspec(empty_bases) WindowingEnvironment : llm::OS::UI::WindowManagement::IWindowingEnvironment
    {
        WindowingEnvironment(std::nullptr_t) noexcept {}
        WindowingEnvironment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IWindowingEnvironment(ptr, take_ownership_from_abi) {}
        static auto FindAll();
        static auto FindAll(llm::OS::UI::WindowManagement::WindowingEnvironmentKind const& kind);
    };
    struct __declspec(empty_bases) WindowingEnvironmentAddedEventArgs : llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs
    {
        WindowingEnvironmentAddedEventArgs(std::nullptr_t) noexcept {}
        WindowingEnvironmentAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowingEnvironmentChangedEventArgs : llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs
    {
        WindowingEnvironmentChangedEventArgs(std::nullptr_t) noexcept {}
        WindowingEnvironmentChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowingEnvironmentRemovedEventArgs : llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs
    {
        WindowingEnvironmentRemovedEventArgs(std::nullptr_t) noexcept {}
        WindowingEnvironmentRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
