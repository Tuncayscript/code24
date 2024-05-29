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
#ifndef LLM_OS_ApplicationModel_Core_1_H
#define LLM_OS_ApplicationModel_Core_1_H
#include "llm/impl/Windows.ApplicationModel.Core.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Core
{
    struct __declspec(empty_bases) IAppListEntry :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppListEntry>
    {
        IAppListEntry(std::nullptr_t = nullptr) noexcept {}
        IAppListEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppListEntry2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppListEntry2>
    {
        IAppListEntry2(std::nullptr_t = nullptr) noexcept {}
        IAppListEntry2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppListEntry3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppListEntry3>
    {
        IAppListEntry3(std::nullptr_t = nullptr) noexcept {}
        IAppListEntry3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppListEntry4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppListEntry4>
    {
        IAppListEntry4(std::nullptr_t = nullptr) noexcept {}
        IAppListEntry4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplication :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplication>
    {
        ICoreApplication(std::nullptr_t = nullptr) noexcept {}
        ICoreApplication(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplication2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplication2>
    {
        ICoreApplication2(std::nullptr_t = nullptr) noexcept {}
        ICoreApplication2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplication3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplication3>
    {
        ICoreApplication3(std::nullptr_t = nullptr) noexcept {}
        ICoreApplication3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationExit :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationExit>
    {
        ICoreApplicationExit(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationExit(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationUnhandledError :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationUnhandledError>
    {
        ICoreApplicationUnhandledError(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationUnhandledError(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationUseCount :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationUseCount>
    {
        ICoreApplicationUseCount(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationUseCount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationView>
    {
        ICoreApplicationView(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationView2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationView2>
    {
        ICoreApplicationView2(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationView2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationView3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationView3>
    {
        ICoreApplicationView3(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationView3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationView5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationView5>
    {
        ICoreApplicationView5(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationView5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationView6 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationView6>
    {
        ICoreApplicationView6(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationView6(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreApplicationViewTitleBar :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreApplicationViewTitleBar>
    {
        ICoreApplicationViewTitleBar(std::nullptr_t = nullptr) noexcept {}
        ICoreApplicationViewTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreImmersiveApplication :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreImmersiveApplication>
    {
        ICoreImmersiveApplication(std::nullptr_t = nullptr) noexcept {}
        ICoreImmersiveApplication(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreImmersiveApplication2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreImmersiveApplication2>
    {
        ICoreImmersiveApplication2(std::nullptr_t = nullptr) noexcept {}
        ICoreImmersiveApplication2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreImmersiveApplication3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICoreImmersiveApplication3>
    {
        ICoreImmersiveApplication3(std::nullptr_t = nullptr) noexcept {}
        ICoreImmersiveApplication3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameworkView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFrameworkView>
    {
        IFrameworkView(std::nullptr_t = nullptr) noexcept {}
        IFrameworkView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameworkViewSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFrameworkViewSource>
    {
        IFrameworkViewSource(std::nullptr_t = nullptr) noexcept {}
        IFrameworkViewSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHostedViewClosingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHostedViewClosingEventArgs>
    {
        IHostedViewClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHostedViewClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnhandledError :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnhandledError>
    {
        IUnhandledError(std::nullptr_t = nullptr) noexcept {}
        IUnhandledError(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnhandledErrorDetectedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnhandledErrorDetectedEventArgs>
    {
        IUnhandledErrorDetectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUnhandledErrorDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
