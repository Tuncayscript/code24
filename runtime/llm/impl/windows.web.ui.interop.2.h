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
#ifndef LLM_OS_Web_UI_Interop_2_H
#define LLM_OS_Web_UI_Interop_2_H
#include "llm/impl/Windows.Web.UI.1.h"
#include "llm/impl/Windows.Web.UI.Interop.1.h"
LLM_EXPORT namespace llm::OS::Web::UI::Interop
{
    struct __declspec(empty_bases) WebViewControl : llm::OS::Web::UI::IWebViewControl,
        impl::require<WebViewControl, llm::OS::Web::UI::Interop::IWebViewControlSite, llm::OS::Web::UI::IWebViewControl2, llm::OS::Web::UI::Interop::IWebViewControlSite2>
    {
        WebViewControl(std::nullptr_t) noexcept {}
        WebViewControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::IWebViewControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlAcceleratorKeyPressedEventArgs : llm::OS::Web::UI::Interop::IWebViewControlAcceleratorKeyPressedEventArgs
    {
        WebViewControlAcceleratorKeyPressedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlAcceleratorKeyPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::Interop::IWebViewControlAcceleratorKeyPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlMoveFocusRequestedEventArgs : llm::OS::Web::UI::Interop::IWebViewControlMoveFocusRequestedEventArgs
    {
        WebViewControlMoveFocusRequestedEventArgs(std::nullptr_t) noexcept {}
        WebViewControlMoveFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::Interop::IWebViewControlMoveFocusRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebViewControlProcess : llm::OS::Web::UI::Interop::IWebViewControlProcess
    {
        WebViewControlProcess(std::nullptr_t) noexcept {}
        WebViewControlProcess(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::Interop::IWebViewControlProcess(ptr, take_ownership_from_abi) {}
        WebViewControlProcess();
        explicit WebViewControlProcess(llm::OS::Web::UI::Interop::WebViewControlProcessOptions const& processOptions);
    };
    struct __declspec(empty_bases) WebViewControlProcessOptions : llm::OS::Web::UI::Interop::IWebViewControlProcessOptions
    {
        WebViewControlProcessOptions(std::nullptr_t) noexcept {}
        WebViewControlProcessOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::UI::Interop::IWebViewControlProcessOptions(ptr, take_ownership_from_abi) {}
        WebViewControlProcessOptions();
    };
}
#endif
