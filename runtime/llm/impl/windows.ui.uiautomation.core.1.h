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
#ifndef LLM_OS_UI_UIAutomation_Core_1_H
#define LLM_OS_UI_UIAutomation_Core_1_H
#include "llm/impl/Windows.UI.UIAutomation.Core.0.h"
LLM_EXPORT namespace llm:OS::UI::UIAutomation::Core
{
    struct __declspec(empty_bases) IAutomationRemoteOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAutomationRemoteOperationResult>
    {
        IAutomationRemoteOperationResult(std::nullptr_t = nullptr) noexcept {}
        IAutomationRemoteOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationConnectionBoundObjectProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationConnectionBoundObjectProvider>
    {
        ICoreAutomationConnectionBoundObjectProvider(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationConnectionBoundObjectProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationRegistrarStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationRegistrarStatics>
    {
        ICoreAutomationRegistrarStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationRegistrarStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationRemoteOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationRemoteOperation>
    {
        ICoreAutomationRemoteOperation(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationRemoteOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationRemoteOperation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationRemoteOperation2>
    {
        ICoreAutomationRemoteOperation2(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationRemoteOperation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationRemoteOperationContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationRemoteOperationContext>
    {
        ICoreAutomationRemoteOperationContext(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationRemoteOperationContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAutomationRemoteOperationExtensionProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAutomationRemoteOperationExtensionProvider>
    {
        ICoreAutomationRemoteOperationExtensionProvider(std::nullptr_t = nullptr) noexcept {}
        ICoreAutomationRemoteOperationExtensionProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationClientSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationClientSession>
    {
        IRemoteAutomationClientSession(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationClientSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationClientSessionFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationClientSessionFactory>
    {
        IRemoteAutomationClientSessionFactory(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationClientSessionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationConnectionRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationConnectionRequestedEventArgs>
    {
        IRemoteAutomationConnectionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationDisconnectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationDisconnectedEventArgs>
    {
        IRemoteAutomationDisconnectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationServerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationServerStatics>
    {
        IRemoteAutomationServerStatics(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationServerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRemoteAutomationWindow :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRemoteAutomationWindow>
    {
        IRemoteAutomationWindow(std::nullptr_t = nullptr) noexcept {}
        IRemoteAutomationWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
