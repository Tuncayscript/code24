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
#ifndef LLM_OS_Foundation_Diagnostics_1_H
#define LLM_OS_Foundation_Diagnostics_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Foundation.Diagnostics.0.h"
LLM_EXPORT namespace llm::OS::Foundation::Diagnostics
{
    struct __declspec(empty_bases) IAsyncCausalityTracerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAsyncCausalityTracerStatics>
    {
        IAsyncCausalityTracerStatics(std::nullptr_t = nullptr) noexcept {}
        IAsyncCausalityTracerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IErrorDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IErrorDetails>
    {
        IErrorDetails(std::nullptr_t = nullptr) noexcept {}
        IErrorDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IErrorDetailsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IErrorDetailsStatics>
    {
        IErrorDetailsStatics(std::nullptr_t = nullptr) noexcept {}
        IErrorDetailsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IErrorReportingSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IErrorReportingSettings>
    {
        IErrorReportingSettings(std::nullptr_t = nullptr) noexcept {}
        IErrorReportingSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileLoggingSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileLoggingSession>,
        impl::require<llm::OS::Foundation::Diagnostics::IFileLoggingSession, llm::OS::Foundation::IClosable>
    {
        IFileLoggingSession(std::nullptr_t = nullptr) noexcept {}
        IFileLoggingSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileLoggingSessionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileLoggingSessionFactory>
    {
        IFileLoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
        IFileLoggingSessionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILogFileGeneratedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILogFileGeneratedEventArgs>
    {
        ILogFileGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILogFileGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingActivity :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingActivity>,
        impl::require<llm::OS::Foundation::Diagnostics::ILoggingActivity, llm::OS::Foundation::IClosable>
    {
        ILoggingActivity(std::nullptr_t = nullptr) noexcept {}
        ILoggingActivity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingActivity2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingActivity2>,
        impl::require<llm::OS::Foundation::Diagnostics::ILoggingActivity2, llm::OS::Foundation::IClosable, llm::OS::Foundation::Diagnostics::ILoggingActivity, llm::OS::Foundation::Diagnostics::ILoggingTarget>
    {
        ILoggingActivity2(std::nullptr_t = nullptr) noexcept {}
        ILoggingActivity2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingActivityFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingActivityFactory>
    {
        ILoggingActivityFactory(std::nullptr_t = nullptr) noexcept {}
        ILoggingActivityFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannel :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannel>,
        impl::require<llm::OS::Foundation::Diagnostics::ILoggingChannel, llm::OS::Foundation::IClosable>
    {
        ILoggingChannel(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannel2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannel2>,
        impl::require<llm::OS::Foundation::Diagnostics::ILoggingChannel2, llm::OS::Foundation::IClosable, llm::OS::Foundation::Diagnostics::ILoggingChannel, llm::OS::Foundation::Diagnostics::ILoggingTarget>
    {
        ILoggingChannel2(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannel2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannelFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannelFactory>
    {
        ILoggingChannelFactory(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannelFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannelFactory2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannelFactory2>
    {
        ILoggingChannelFactory2(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannelFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannelOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannelOptions>
    {
        ILoggingChannelOptions(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannelOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingChannelOptionsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingChannelOptionsFactory>
    {
        ILoggingChannelOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        ILoggingChannelOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingFields :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingFields>
    {
        ILoggingFields(std::nullptr_t = nullptr) noexcept {}
        ILoggingFields(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingOptions>
    {
        ILoggingOptions(std::nullptr_t = nullptr) noexcept {}
        ILoggingOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingOptionsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingOptionsFactory>
    {
        ILoggingOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        ILoggingOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingSession>,
        impl::require<llm::OS::Foundation::Diagnostics::ILoggingSession, llm::OS::Foundation::IClosable>
    {
        ILoggingSession(std::nullptr_t = nullptr) noexcept {}
        ILoggingSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingSessionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingSessionFactory>
    {
        ILoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
        ILoggingSessionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILoggingTarget :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILoggingTarget>
    {
        ILoggingTarget(std::nullptr_t = nullptr) noexcept {}
        ILoggingTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITracingStatusChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITracingStatusChangedEventArgs>
    {
        ITracingStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITracingStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
