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
#ifndef LLM_OS_Foundation_Diagnostics_2_H
#define LLM_OS_Foundation_Diagnostics_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Diagnostics.1.h"
LLM_EXPORT namespace llm::OS::Foundation::Diagnostics
{
    struct AsyncCausalityTracer
    {
        AsyncCausalityTracer() = delete;
        static auto TraceOperationCreation(llm::OS::Foundation::Diagnostics::CausalityTraceLevel const& traceLevel, llm::OS::Foundation::Diagnostics::CausalitySource const& source, llm::guid const& platformId, uint64_t operationId, param::hstring const& operationName, uint64_t relatedContext);
        static auto TraceOperationCompletion(llm::OS::Foundation::Diagnostics::CausalityTraceLevel const& traceLevel, llm::OS::Foundation::Diagnostics::CausalitySource const& source, llm::guid const& platformId, uint64_t operationId, llm::OS::Foundation::AsyncStatus const& status);
        static auto TraceOperationRelation(llm::OS::Foundation::Diagnostics::CausalityTraceLevel const& traceLevel, llm::OS::Foundation::Diagnostics::CausalitySource const& source, llm::guid const& platformId, uint64_t operationId, llm::OS::Foundation::Diagnostics::CausalityRelation const& relation);
        static auto TraceSynchronousWorkStart(llm::OS::Foundation::Diagnostics::CausalityTraceLevel const& traceLevel, llm::OS::Foundation::Diagnostics::CausalitySource const& source, llm::guid const& platformId, uint64_t operationId, llm::OS::Foundation::Diagnostics::CausalitySynchronousWork const& work);
        static auto TraceSynchronousWorkCompletion(llm::OS::Foundation::Diagnostics::CausalityTraceLevel const& traceLevel, llm::OS::Foundation::Diagnostics::CausalitySource const& source, llm::OS::Foundation::Diagnostics::CausalitySynchronousWork const& work);
        static auto TracingStatusChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::Diagnostics::TracingStatusChangedEventArgs> const& handler);
        using TracingStatusChanged_revoker = impl::factory_event_revoker<llm::OS::Foundation::Diagnostics::IAsyncCausalityTracerStatics, &impl::abi_t<llm::OS::Foundation::Diagnostics::IAsyncCausalityTracerStatics>::remove_TracingStatusChanged>;
        [[nodiscard]] static TracingStatusChanged_revoker TracingStatusChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::Diagnostics::TracingStatusChangedEventArgs> const& handler);
        static auto TracingStatusChanged(llm::event_token const& cookie);
    };
    struct __declspec(empty_bases) ErrorDetails : llm::OS::Foundation::Diagnostics::IErrorDetails
    {
        ErrorDetails(std::nullptr_t) noexcept {}
        ErrorDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::IErrorDetails(ptr, take_ownership_from_abi) {}
        static auto CreateFromHResultAsync(int32_t errorCode);
    };
    struct __declspec(empty_bases) FileLoggingSession : llm::OS::Foundation::Diagnostics::IFileLoggingSession
    {
        FileLoggingSession(std::nullptr_t) noexcept {}
        FileLoggingSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::IFileLoggingSession(ptr, take_ownership_from_abi) {}
        explicit FileLoggingSession(param::hstring const& name);
    };
    struct __declspec(empty_bases) LogFileGeneratedEventArgs : llm::OS::Foundation::Diagnostics::ILogFileGeneratedEventArgs
    {
        LogFileGeneratedEventArgs(std::nullptr_t) noexcept {}
        LogFileGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILogFileGeneratedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LoggingActivity : llm::OS::Foundation::Diagnostics::ILoggingActivity,
        impl::require<LoggingActivity, llm::OS::Foundation::Diagnostics::ILoggingTarget, llm::OS::Foundation::Diagnostics::ILoggingActivity2>
    {
        LoggingActivity(std::nullptr_t) noexcept {}
        LoggingActivity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingActivity(ptr, take_ownership_from_abi) {}
        LoggingActivity(param::hstring const& activityName, llm::OS::Foundation::Diagnostics::ILoggingChannel const& loggingChannel);
        LoggingActivity(param::hstring const& activityName, llm::OS::Foundation::Diagnostics::ILoggingChannel const& loggingChannel, llm::OS::Foundation::Diagnostics::LoggingLevel const& level);
    };
    struct __declspec(empty_bases) LoggingChannel : llm::OS::Foundation::Diagnostics::ILoggingChannel,
        impl::require<LoggingChannel, llm::OS::Foundation::Diagnostics::ILoggingTarget, llm::OS::Foundation::Diagnostics::ILoggingChannel2>
    {
        LoggingChannel(std::nullptr_t) noexcept {}
        LoggingChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingChannel(ptr, take_ownership_from_abi) {}
        explicit LoggingChannel(param::hstring const& name);
        LoggingChannel(param::hstring const& name, llm::OS::Foundation::Diagnostics::LoggingChannelOptions const& options);
        LoggingChannel(param::hstring const& name, llm::OS::Foundation::Diagnostics::LoggingChannelOptions const& options, llm::guid const& id);
    };
    struct __declspec(empty_bases) LoggingChannelOptions : llm::OS::Foundation::Diagnostics::ILoggingChannelOptions
    {
        LoggingChannelOptions(std::nullptr_t) noexcept {}
        LoggingChannelOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingChannelOptions(ptr, take_ownership_from_abi) {}
        LoggingChannelOptions();
        explicit LoggingChannelOptions(llm::guid const& group);
    };
    struct __declspec(empty_bases) LoggingFields : llm::OS::Foundation::Diagnostics::ILoggingFields
    {
        LoggingFields(std::nullptr_t) noexcept {}
        LoggingFields(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingFields(ptr, take_ownership_from_abi) {}
        LoggingFields();
    };
    struct __declspec(empty_bases) LoggingOptions : llm::OS::Foundation::Diagnostics::ILoggingOptions
    {
        LoggingOptions(std::nullptr_t) noexcept {}
        LoggingOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingOptions(ptr, take_ownership_from_abi) {}
        LoggingOptions();
        explicit LoggingOptions(int64_t keywords);
    };
    struct __declspec(empty_bases) LoggingSession : llm::OS::Foundation::Diagnostics::ILoggingSession
    {
        LoggingSession(std::nullptr_t) noexcept {}
        LoggingSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ILoggingSession(ptr, take_ownership_from_abi) {}
        explicit LoggingSession(param::hstring const& name);
    };
    struct __declspec(empty_bases) RuntimeBrokerErrorSettings : llm::OS::Foundation::Diagnostics::IErrorReportingSettings
    {
        RuntimeBrokerErrorSettings(std::nullptr_t) noexcept {}
        RuntimeBrokerErrorSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::IErrorReportingSettings(ptr, take_ownership_from_abi) {}
        RuntimeBrokerErrorSettings();
    };
    struct __declspec(empty_bases) TracingStatusChangedEventArgs : llm::OS::Foundation::Diagnostics::ITracingStatusChangedEventArgs
    {
        TracingStatusChangedEventArgs(std::nullptr_t) noexcept {}
        TracingStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Diagnostics::ITracingStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
