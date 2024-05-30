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
#ifndef LLM_OS_UI_UIAutomation_Core_2_H
#define LLM_OS_UI_UIAutomation_Core_2_H
#include "llm/impl/Windows.UI.UIAutomation.Core.1.h"
LLM_EXPORT namespace llm:OS::UI::UIAutomation::Core
{
    struct AutomationAnnotationTypeRegistration
    {
        int32_t LocalId;
    };
    inline bool operator==(AutomationAnnotationTypeRegistration const& left, AutomationAnnotationTypeRegistration const& right) noexcept
    {
        return left.LocalId == right.LocalId;
    }
    inline bool operator!=(AutomationAnnotationTypeRegistration const& left, AutomationAnnotationTypeRegistration const& right) noexcept
    {
        return !(left == right);
    }
    struct AutomationRemoteOperationOperandId
    {
        int32_t Value;
    };
    inline bool operator==(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return left.Value == right.Value;
    }
    inline bool operator!=(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AutomationRemoteOperationResult : llm:OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult
    {
        AutomationRemoteOperationResult(std::nullptr_t) noexcept {}
        AutomationRemoteOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::IAutomationRemoteOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct CoreAutomationRegistrar
    {
        CoreAutomationRegistrar() = delete;
        static auto RegisterAnnotationType(llm::guid const& guid);
        static auto UnregisterAnnotationType(llm:OS::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration const& registration);
    };
    struct __declspec(empty_bases) CoreAutomationRemoteOperation : llm:OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation,
        impl::require<CoreAutomationRemoteOperation, llm:OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2>
    {
        CoreAutomationRemoteOperation(std::nullptr_t) noexcept {}
        CoreAutomationRemoteOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperation(ptr, take_ownership_from_abi) {}
        CoreAutomationRemoteOperation();
    };
    struct __declspec(empty_bases) CoreAutomationRemoteOperationContext : llm:OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext
    {
        CoreAutomationRemoteOperationContext(std::nullptr_t) noexcept {}
        CoreAutomationRemoteOperationContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteAutomationClientSession : llm:OS::UI::UIAutomation::Core::IRemoteAutomationClientSession
    {
        RemoteAutomationClientSession(std::nullptr_t) noexcept {}
        RemoteAutomationClientSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::IRemoteAutomationClientSession(ptr, take_ownership_from_abi) {}
        explicit RemoteAutomationClientSession(param::hstring const& name);
        RemoteAutomationClientSession(param::hstring const& name, llm::guid const& sessionId);
    };
    struct __declspec(empty_bases) RemoteAutomationConnectionRequestedEventArgs : llm:OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs
    {
        RemoteAutomationConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
        RemoteAutomationConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteAutomationDisconnectedEventArgs : llm:OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs
    {
        RemoteAutomationDisconnectedEventArgs(std::nullptr_t) noexcept {}
        RemoteAutomationDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct RemoteAutomationServer
    {
        RemoteAutomationServer() = delete;
        static auto ReportSession(llm::guid const& sessionId);
    };
    struct __declspec(empty_bases) RemoteAutomationWindow : llm:OS::UI::UIAutomation::Core::IRemoteAutomationWindow
    {
        RemoteAutomationWindow(std::nullptr_t) noexcept {}
        RemoteAutomationWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::Core::IRemoteAutomationWindow(ptr, take_ownership_from_abi) {}
    };
}
#endif
