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
#ifndef LLM_OS_Security_Isolation_2_H
#define LLM_OS_Security_Isolation_2_H
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Isolation.1.h"
LLM_EXPORT namespace llm:OS::Security::Isolation
{
    struct HostMessageReceivedCallback : llm:OS::Foundation::IUnknown
    {
        HostMessageReceivedCallback(std::nullptr_t = nullptr) noexcept {}
        HostMessageReceivedCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> HostMessageReceivedCallback(L lambda);
        template <typename F> HostMessageReceivedCallback(F* function);
        template <typename O, typename M> HostMessageReceivedCallback(O* object, M method);
        template <typename O, typename M> HostMessageReceivedCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> HostMessageReceivedCallback(weak_ref<O>&& object, M method);
        auto operator()(llm::guid const& receiverId, param::vector_view<llm:OS::Foundation::IInspectable> const& message) const;
    };
    struct MessageReceivedCallback : llm:OS::Foundation::IUnknown
    {
        MessageReceivedCallback(std::nullptr_t = nullptr) noexcept {}
        MessageReceivedCallback(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MessageReceivedCallback(L lambda);
        template <typename F> MessageReceivedCallback(F* function);
        template <typename O, typename M> MessageReceivedCallback(O* object, M method);
        template <typename O, typename M> MessageReceivedCallback(com_ptr<O>&& object, M method);
        template <typename O, typename M> MessageReceivedCallback(weak_ref<O>&& object, M method);
        auto operator()(llm::guid const& receiverId, param::vector_view<llm:OS::Foundation::IInspectable> const& message) const;
    };
    struct IsolatedWindowsEnvironmentCreateProgress
    {
        llm:OS::Security::Isolation::IsolatedWindowsEnvironmentProgressState State;
        uint32_t PercentComplete;
    };
    inline bool operator==(IsolatedWindowsEnvironmentCreateProgress const& left, IsolatedWindowsEnvironmentCreateProgress const& right) noexcept
    {
        return left.State == right.State && left.PercentComplete == right.PercentComplete;
    }
    inline bool operator!=(IsolatedWindowsEnvironmentCreateProgress const& left, IsolatedWindowsEnvironmentCreateProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) IsolatedWindowsEnvironment : llm:OS::Security::Isolation::IIsolatedWindowsEnvironment,
        impl::require<IsolatedWindowsEnvironment, llm:OS::Security::Isolation::IIsolatedWindowsEnvironment2, llm:OS::Security::Isolation::IIsolatedWindowsEnvironment3, llm:OS::Security::Isolation::IIsolatedWindowsEnvironment4>
    {
        IsolatedWindowsEnvironment(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironment(ptr, take_ownership_from_abi) {}
        static auto CreateAsync(llm:OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options);
        static auto CreateAsync(llm:OS::Security::Isolation::IsolatedWindowsEnvironmentOptions const& options, llm:OS::Security::Isolation::IsolatedWindowsEnvironmentTelemetryParameters const& telemetryParameters);
        static auto GetById(param::hstring const& environmentId);
        static auto FindByOwnerId(param::hstring const& environmentOwnerId);
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentCreateResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult,
        impl::require<IsolatedWindowsEnvironmentCreateResult, llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult2>
    {
        IsolatedWindowsEnvironmentCreateResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentCreateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentCreateResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentFile : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentFile,
        impl::require<IsolatedWindowsEnvironmentFile, llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentFile2>
    {
        IsolatedWindowsEnvironmentFile(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentFile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentFile(ptr, take_ownership_from_abi) {}
    };
    struct IsolatedWindowsEnvironmentHost
    {
        IsolatedWindowsEnvironmentHost() = delete;
        [[nodiscard]] static auto IsReady();
        [[nodiscard]] static auto HostErrors();
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentLaunchFileResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult
    {
        IsolatedWindowsEnvironmentLaunchFileResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentLaunchFileResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentLaunchFileResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentOptions : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions,
        impl::require<IsolatedWindowsEnvironmentOptions, llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions2, llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions3>
    {
        IsolatedWindowsEnvironmentOptions(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOptions(ptr, take_ownership_from_abi) {}
        IsolatedWindowsEnvironmentOptions();
    };
    struct IsolatedWindowsEnvironmentOwnerRegistration
    {
        IsolatedWindowsEnvironmentOwnerRegistration() = delete;
        static auto Register(param::hstring const& ownerName, llm:OS::Security::Isolation::IsolatedWindowsEnvironmentOwnerRegistrationData const& ownerRegistrationData);
        static auto Unregister(param::hstring const& ownerName);
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentOwnerRegistrationData : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData
    {
        IsolatedWindowsEnvironmentOwnerRegistrationData(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentOwnerRegistrationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationData(ptr, take_ownership_from_abi) {}
        IsolatedWindowsEnvironmentOwnerRegistrationData();
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentOwnerRegistrationResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult
    {
        IsolatedWindowsEnvironmentOwnerRegistrationResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentOwnerRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentOwnerRegistrationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentPostMessageResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult
    {
        IsolatedWindowsEnvironmentPostMessageResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentPostMessageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentPostMessageResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentProcess : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess
    {
        IsolatedWindowsEnvironmentProcess(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentProcess(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentProcess(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentShareFileRequestOptions : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions
    {
        IsolatedWindowsEnvironmentShareFileRequestOptions(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentShareFileRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileRequestOptions(ptr, take_ownership_from_abi) {}
        IsolatedWindowsEnvironmentShareFileRequestOptions();
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentShareFileResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult
    {
        IsolatedWindowsEnvironmentShareFileResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentShareFileResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFileResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentShareFolderRequestOptions : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions
    {
        IsolatedWindowsEnvironmentShareFolderRequestOptions(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentShareFolderRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderRequestOptions(ptr, take_ownership_from_abi) {}
        IsolatedWindowsEnvironmentShareFolderRequestOptions();
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentShareFolderResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult
    {
        IsolatedWindowsEnvironmentShareFolderResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentShareFolderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentShareFolderResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentStartProcessResult : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult
    {
        IsolatedWindowsEnvironmentStartProcessResult(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentStartProcessResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentStartProcessResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentTelemetryParameters : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters
    {
        IsolatedWindowsEnvironmentTelemetryParameters(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentTelemetryParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentTelemetryParameters(ptr, take_ownership_from_abi) {}
        IsolatedWindowsEnvironmentTelemetryParameters();
    };
    struct __declspec(empty_bases) IsolatedWindowsEnvironmentUserInfo : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo,
        impl::require<IsolatedWindowsEnvironmentUserInfo, llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo2>
    {
        IsolatedWindowsEnvironmentUserInfo(std::nullptr_t) noexcept {}
        IsolatedWindowsEnvironmentUserInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Isolation::IIsolatedWindowsEnvironmentUserInfo(ptr, take_ownership_from_abi) {}
    };
    struct IsolatedWindowsHostMessenger
    {
        IsolatedWindowsHostMessenger() = delete;
        static auto PostMessageToReceiver(llm::guid const& receiverId, param::vector_view<llm:OS::Foundation::IInspectable> const& message);
        static auto GetFileId(param::hstring const& filePath);
        static auto RegisterHostMessageReceiver(llm::guid const& receiverId, llm:OS::Security::Isolation::HostMessageReceivedCallback const& hostMessageReceivedCallback);
        static auto UnregisterHostMessageReceiver(llm::guid const& receiverId);
    };
}
#endif
