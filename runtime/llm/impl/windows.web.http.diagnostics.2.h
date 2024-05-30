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
#ifndef LLM_OS_Web_Http_Diagnostics_2_H
#define LLM_OS_Web_Http_Diagnostics_2_H
#include "llm/impl/Windows.System.Diagnostics.1.h"
#include "llm/impl/Windows.Web.Http.Diagnostics.1.h"
LLM_EXPORT namespace llm::OS::Web::Http::Diagnostics
{
    struct __declspec(empty_bases) HttpDiagnosticProvider : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider
    {
        HttpDiagnosticProvider(std::nullptr_t) noexcept {}
        HttpDiagnosticProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider(ptr, take_ownership_from_abi) {}
        static auto CreateFromProcessDiagnosticInfo(llm::OS::System::Diagnostics::ProcessDiagnosticInfo const& processDiagnosticInfo);
    };
    struct __declspec(empty_bases) HttpDiagnosticProviderRequestResponseCompletedEventArgs : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs
    {
        HttpDiagnosticProviderRequestResponseCompletedEventArgs(std::nullptr_t) noexcept {}
        HttpDiagnosticProviderRequestResponseCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpDiagnosticProviderRequestResponseTimestamps : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps
    {
        HttpDiagnosticProviderRequestResponseTimestamps(std::nullptr_t) noexcept {}
        HttpDiagnosticProviderRequestResponseTimestamps(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpDiagnosticProviderRequestSentEventArgs : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs
    {
        HttpDiagnosticProviderRequestSentEventArgs(std::nullptr_t) noexcept {}
        HttpDiagnosticProviderRequestSentEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpDiagnosticProviderResponseReceivedEventArgs : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs
    {
        HttpDiagnosticProviderResponseReceivedEventArgs(std::nullptr_t) noexcept {}
        HttpDiagnosticProviderResponseReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpDiagnosticSourceLocation : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation
    {
        HttpDiagnosticSourceLocation(std::nullptr_t) noexcept {}
        HttpDiagnosticSourceLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation(ptr, take_ownership_from_abi) {}
    };
}
#endif
