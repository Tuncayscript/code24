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
#ifndef LLM_OS_UI_WebUI_1_H
#define LLM_OS_UI_WebUI_1_H
#include "llm/impl/Windows.Graphics.Printing.0.h"
#include "llm/impl/Windows.UI.WebUI.0.h"
LLM_EXPORT namespace llm:OS::UI::WebUI
{
    struct __declspec(empty_bases) IActivatedDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IActivatedDeferral>
    {
        IActivatedDeferral(std::nullptr_t = nullptr) noexcept {}
        IActivatedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActivatedEventArgsDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IActivatedEventArgsDeferral>
    {
        IActivatedEventArgsDeferral(std::nullptr_t = nullptr) noexcept {}
        IActivatedEventArgsDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActivatedOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IActivatedOperation>
    {
        IActivatedOperation(std::nullptr_t = nullptr) noexcept {}
        IActivatedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHtmlPrintDocumentSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHtmlPrintDocumentSource>,
        impl::require<llm:OS::UI::WebUI::IHtmlPrintDocumentSource, llm:OS::Graphics::Printing::IPrintDocumentSource>
    {
        IHtmlPrintDocumentSource(std::nullptr_t = nullptr) noexcept {}
        IHtmlPrintDocumentSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INewWebUIViewCreatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<INewWebUIViewCreatedEventArgs>
    {
        INewWebUIViewCreatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INewWebUIViewCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIActivationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIActivationStatics>
    {
        IWebUIActivationStatics(std::nullptr_t = nullptr) noexcept {}
        IWebUIActivationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIActivationStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIActivationStatics2>
    {
        IWebUIActivationStatics2(std::nullptr_t = nullptr) noexcept {}
        IWebUIActivationStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIActivationStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIActivationStatics3>
    {
        IWebUIActivationStatics3(std::nullptr_t = nullptr) noexcept {}
        IWebUIActivationStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIActivationStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIActivationStatics4>
    {
        IWebUIActivationStatics4(std::nullptr_t = nullptr) noexcept {}
        IWebUIActivationStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIBackgroundTaskInstance :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIBackgroundTaskInstance>
    {
        IWebUIBackgroundTaskInstance(std::nullptr_t = nullptr) noexcept {}
        IWebUIBackgroundTaskInstance(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIBackgroundTaskInstanceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIBackgroundTaskInstanceStatics>
    {
        IWebUIBackgroundTaskInstanceStatics(std::nullptr_t = nullptr) noexcept {}
        IWebUIBackgroundTaskInstanceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUINavigatedDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUINavigatedDeferral>
    {
        IWebUINavigatedDeferral(std::nullptr_t = nullptr) noexcept {}
        IWebUINavigatedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUINavigatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUINavigatedEventArgs>
    {
        IWebUINavigatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebUINavigatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUINavigatedOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUINavigatedOperation>
    {
        IWebUINavigatedOperation(std::nullptr_t = nullptr) noexcept {}
        IWebUINavigatedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIView>
    {
        IWebUIView(std::nullptr_t = nullptr) noexcept {}
        IWebUIView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUIViewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebUIViewStatics>
    {
        IWebUIViewStatics(std::nullptr_t = nullptr) noexcept {}
        IWebUIViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
