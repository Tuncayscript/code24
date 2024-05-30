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
#ifndef LLM_OS_Web_UI_Interop_1_H
#define LLM_OS_Web_UI_Interop_1_H
#include "llm/impl/Windows.Web.UI.Interop.0.h"
LLM_EXPORT namespace llm::OS::Web::UI::Interop
{
    struct __declspec(empty_bases) IWebViewControlAcceleratorKeyPressedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlAcceleratorKeyPressedEventArgs>
    {
        IWebViewControlAcceleratorKeyPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlAcceleratorKeyPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlMoveFocusRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlMoveFocusRequestedEventArgs>
    {
        IWebViewControlMoveFocusRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlMoveFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlProcess :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlProcess>
    {
        IWebViewControlProcess(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlProcess(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlProcessFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlProcessFactory>
    {
        IWebViewControlProcessFactory(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlProcessFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlProcessOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlProcessOptions>
    {
        IWebViewControlProcessOptions(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlProcessOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlSite :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlSite>
    {
        IWebViewControlSite(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlSite(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebViewControlSite2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebViewControlSite2>
    {
        IWebViewControlSite2(std::nullptr_t = nullptr) noexcept {}
        IWebViewControlSite2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
