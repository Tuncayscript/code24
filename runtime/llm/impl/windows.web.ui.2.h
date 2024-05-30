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
#ifndef LLM_OS_Web_UI_2_H
#define LLM_OS_Web_UI_2_H
#include "llm/impl/Windows.Web.UI.1.h"
LLM_EXPORT namespace llm::OS::Web::UI
{
    struct __declspec(empty_bases) WebViewControlContentLoadingEventArgs : llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs
    {
        WebViewControlContentLoadingEventArgs(std::nullptr_t) noexcept {}
        WebViewControlContentLoadingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlContentLoadingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlDOMContentLoadedEventArgs : llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs
    {
        WebViewControlDOMContentLoadedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlDOMContentLoadedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlDOMContentLoadedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlDeferredPermissionRequest : llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest
    {
        WebViewControlDeferredPermissionRequest(std::nullptr_t) noexcept {}
        WebViewControlDeferredPermissionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlDeferredPermissionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlLongRunningScriptDetectedEventArgs : llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs
    {
        WebViewControlLongRunningScriptDetectedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlLongRunningScriptDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlLongRunningScriptDetectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlNavigationCompletedEventArgs : llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs
    {
        WebViewControlNavigationCompletedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlNavigationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlNavigationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlNavigationStartingEventArgs : llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs
    {
        WebViewControlNavigationStartingEventArgs(std::nullptr_t) noexcept {}
        WebViewControlNavigationStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlNavigationStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlNewWindowRequestedEventArgs : llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs,
        impl::require<WebViewControlNewWindowRequestedEventArgs, llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs2>
    {
        WebViewControlNewWindowRequestedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlNewWindowRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlNewWindowRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlPermissionRequest : llm::OS::Web::UI::IWebViewControlPermissionRequest
    {
        WebViewControlPermissionRequest(std::nullptr_t) noexcept {}
        WebViewControlPermissionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlPermissionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlPermissionRequestedEventArgs : llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs
    {
        WebViewControlPermissionRequestedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlPermissionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlPermissionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlScriptNotifyEventArgs : llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs
    {
        WebViewControlScriptNotifyEventArgs(std::nullptr_t) noexcept {}
        WebViewControlScriptNotifyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlScriptNotifyEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlSettings : llm::OS::Web::UI::IWebViewControlSettings
    {
        WebViewControlSettings(std::nullptr_t) noexcept {}
        WebViewControlSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlUnsupportedUriSchemeIdentifiedEventArgs : llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs
    {
        WebViewControlUnsupportedUriSchemeIdentifiedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlUnsupportedUriSchemeIdentifiedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlUnsupportedUriSchemeIdentifiedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlUnviewableContentIdentifiedEventArgs : llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs
    {
        WebViewControlUnviewableContentIdentifiedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlUnviewableContentIdentifiedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlUnviewableContentIdentifiedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlWebResourceRequestedEventArgs : llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs
    {
        WebViewControlWebResourceRequestedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlWebResourceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControlWebResourceRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
