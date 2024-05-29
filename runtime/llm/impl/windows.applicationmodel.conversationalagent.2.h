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
#ifndef LLM_OS_ApplicationModel_ConversationalAgent_2_H
#define LLM_OS_ApplicationModel_ConversationalAgent_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.ApplicationModel.ConversationalAgent.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::ConversationalAgent
{
    struct __declspec(empty_bases) ActivationSignalDetectionConfiguration : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration,
        impl::require<ActivationSignalDetectionConfiguration, llm::OS::Foundation::IClosable, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>
    {
        ActivationSignalDetectionConfiguration(std::nullptr_t) noexcept {}
        ActivationSignalDetectionConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivationSignalDetectionConfigurationCreationResult : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult
    {
        ActivationSignalDetectionConfigurationCreationResult(std::nullptr_t) noexcept {}
        ActivationSignalDetectionConfigurationCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivationSignalDetector : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector,
        impl::require<ActivationSignalDetector, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>
    {
        ActivationSignalDetector(std::nullptr_t) noexcept {}
        ActivationSignalDetector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentDetectorManager : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager,
        impl::require<ConversationalAgentDetectorManager, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>
    {
        ConversationalAgentDetectorManager(std::nullptr_t) noexcept {}
        ConversationalAgentDetectorManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Default();
    };
    struct __declspec(empty_bases) ConversationalAgentSession : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession,
        impl::require<ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2, llm::OS::Foundation::IClosable>
    {
        ConversationalAgentSession(std::nullptr_t) noexcept {}
        ConversationalAgentSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession(ptr, take_ownership_from_abi) {}
        static auto GetCurrentSessionAsync();
        static auto GetCurrentSessionSync();
    };
    struct __declspec(empty_bases) ConversationalAgentSessionInterruptedEventArgs : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs
    {
        ConversationalAgentSessionInterruptedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSessionInterruptedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSignal : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal,
        impl::require<ConversationalAgentSignal, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>
    {
        ConversationalAgentSignal(std::nullptr_t) noexcept {}
        ConversationalAgentSignal(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSignalDetectedEventArgs : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs
    {
        ConversationalAgentSignalDetectedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSignalDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ConversationalAgentSystemStateChangedEventArgs : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs
    {
        ConversationalAgentSystemStateChangedEventArgs(std::nullptr_t) noexcept {}
        ConversationalAgentSystemStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DetectionConfigurationAvailabilityChangedEventArgs : llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs
    {
        DetectionConfigurationAvailabilityChangedEventArgs(std::nullptr_t) noexcept {}
        DetectionConfigurationAvailabilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DetectionConfigurationAvailabilityInfo : llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo,
        impl::require<DetectionConfigurationAvailabilityInfo, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>
    {
        DetectionConfigurationAvailabilityInfo(std::nullptr_t) noexcept {}
        DetectionConfigurationAvailabilityInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
