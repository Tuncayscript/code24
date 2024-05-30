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
#ifndef LLM_OS_Web_UI_1_H
#define LLM_OS_Web_UI_1_H
#include "llm/impl/Windows.Web.UI.0.h"
LLM_EXPORT namespace llm::OS::Web::UI
{
    struct __declspec(empty_bases) IWebViewControl :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControl>
    {
        IWebViewControl(std::nullptr_t = nullptr) noexcept {}
        IWebViewControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControl2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControl2>
    {
        IWebViewControl2(std::nullptr_t = nullptr) noexcept {}
        IWebViewControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlContentLoadingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlContentLoadingEventArgs>
    {
        IWebViewControlContentLoadingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlContentLoadingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlDOMContentLoadedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlDOMContentLoadedEventArgs>
    {
        IWebViewControlDOMContentLoadedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlDOMContentLoadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlDeferredPermissionRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlDeferredPermissionRequest>
    {
        IWebViewControlDeferredPermissionRequest(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlDeferredPermissionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlLongRunningScriptDetectedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlLongRunningScriptDetectedEventArgs>
    {
        IWebViewControlLongRunningScriptDetectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlLongRunningScriptDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlNavigationCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlNavigationCompletedEventArgs>
    {
        IWebViewControlNavigationCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlNavigationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlNavigationStartingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlNavigationStartingEventArgs>
    {
        IWebViewControlNavigationStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlNavigationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlNewWindowRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlNewWindowRequestedEventArgs>
    {
        IWebViewControlNewWindowRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlNewWindowRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlNewWindowRequestedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlNewWindowRequestedEventArgs2>
    {
        IWebViewControlNewWindowRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlNewWindowRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlPermissionRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlPermissionRequest>
    {
        IWebViewControlPermissionRequest(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlPermissionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlPermissionRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlPermissionRequestedEventArgs>
    {
        IWebViewControlPermissionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlPermissionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlScriptNotifyEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlScriptNotifyEventArgs>
    {
        IWebViewControlScriptNotifyEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlScriptNotifyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlSettings>
    {
        IWebViewControlSettings(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs>
    {
        IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlUnviewableContentIdentifiedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlUnviewableContentIdentifiedEventArgs>
    {
        IWebViewControlUnviewableContentIdentifiedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlUnviewableContentIdentifiedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlWebResourceRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlWebResourceRequestedEventArgs>
    {
        IWebViewControlWebResourceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlWebResourceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
