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
#ifndef LLM_OS_Web_Http_Diagnostics_1_H
#define LLM_OS_Web_Http_Diagnostics_1_H
#include "llm/impl/Windows.Web.Http.Diagnostics.0.h"
LLM_EXPORT namespace llm::OS::Web::Http::Diagnostics
{
    struct __declspec(empty_bases) IHttpDiagnosticProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProvider>
    {
        IHttpDiagnosticProvider(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticProviderRequestResponseCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProviderRequestResponseCompletedEventArgs>
    {
        IHttpDiagnosticProviderRequestResponseCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProviderRequestResponseCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticProviderRequestResponseTimestamps :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProviderRequestResponseTimestamps>
    {
        IHttpDiagnosticProviderRequestResponseTimestamps(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProviderRequestResponseTimestamps(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticProviderRequestSentEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProviderRequestSentEventArgs>
    {
        IHttpDiagnosticProviderRequestSentEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProviderRequestSentEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticProviderResponseReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProviderResponseReceivedEventArgs>
    {
        IHttpDiagnosticProviderResponseReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProviderResponseReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticProviderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticProviderStatics>
    {
        IHttpDiagnosticProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpDiagnosticSourceLocation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpDiagnosticSourceLocation>
    {
        IHttpDiagnosticSourceLocation(std::nullptr_t = nullptr) noexcept {}
        IHttpDiagnosticSourceLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
