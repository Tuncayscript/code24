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
#ifndef LLM_OS_Security_Isolation_1_H
#define LLM_OS_Security_Isolation_1_H
#include "llm/impl/Windows.Security.Isolation.0.h"
LLM_EXPORT namespace llm:OS::Security::Isolation
{
    struct __declspec(empty_bases) IIsolatedWindowsEnvironment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironment>
    {
        IIsolatedWindowsEnvironment(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironment2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironment2>
    {
        IIsolatedWindowsEnvironment2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironment2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironment3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironment3>
    {
        IIsolatedWindowsEnvironment3(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironment3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironment4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironment4>
    {
        IIsolatedWindowsEnvironment4(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironment4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentCreateResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentCreateResult>
    {
        IIsolatedWindowsEnvironmentCreateResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentCreateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentCreateResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentCreateResult2>
    {
        IIsolatedWindowsEnvironmentCreateResult2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentCreateResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentFactory>
    {
        IIsolatedWindowsEnvironmentFactory(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentFile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentFile>
    {
        IIsolatedWindowsEnvironmentFile(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentFile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentFile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentFile2>
    {
        IIsolatedWindowsEnvironmentFile2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentFile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentHostStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentHostStatics>
    {
        IIsolatedWindowsEnvironmentHostStatics(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentHostStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentLaunchFileResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentLaunchFileResult>
    {
        IIsolatedWindowsEnvironmentLaunchFileResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentLaunchFileResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOptions>
    {
        IIsolatedWindowsEnvironmentOptions(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOptions2>
    {
        IIsolatedWindowsEnvironmentOptions2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOptions3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOptions3>
    {
        IIsolatedWindowsEnvironmentOptions3(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOptions3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOwnerRegistrationData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOwnerRegistrationData>
    {
        IIsolatedWindowsEnvironmentOwnerRegistrationData(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOwnerRegistrationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOwnerRegistrationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOwnerRegistrationResult>
    {
        IIsolatedWindowsEnvironmentOwnerRegistrationResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOwnerRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentOwnerRegistrationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentOwnerRegistrationStatics>
    {
        IIsolatedWindowsEnvironmentOwnerRegistrationStatics(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentOwnerRegistrationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentPostMessageResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentPostMessageResult>
    {
        IIsolatedWindowsEnvironmentPostMessageResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentPostMessageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentProcess :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentProcess>
    {
        IIsolatedWindowsEnvironmentProcess(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentProcess(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentShareFileRequestOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentShareFileRequestOptions>
    {
        IIsolatedWindowsEnvironmentShareFileRequestOptions(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentShareFileRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentShareFileResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentShareFileResult>
    {
        IIsolatedWindowsEnvironmentShareFileResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentShareFileResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentShareFolderRequestOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentShareFolderRequestOptions>
    {
        IIsolatedWindowsEnvironmentShareFolderRequestOptions(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentShareFolderRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentShareFolderResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentShareFolderResult>
    {
        IIsolatedWindowsEnvironmentShareFolderResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentShareFolderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentStartProcessResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentStartProcessResult>
    {
        IIsolatedWindowsEnvironmentStartProcessResult(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentStartProcessResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentTelemetryParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentTelemetryParameters>
    {
        IIsolatedWindowsEnvironmentTelemetryParameters(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentTelemetryParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentUserInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentUserInfo>
    {
        IIsolatedWindowsEnvironmentUserInfo(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentUserInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsEnvironmentUserInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsEnvironmentUserInfo2>
    {
        IIsolatedWindowsEnvironmentUserInfo2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsEnvironmentUserInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsHostMessengerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsHostMessengerStatics>
    {
        IIsolatedWindowsHostMessengerStatics(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsHostMessengerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIsolatedWindowsHostMessengerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIsolatedWindowsHostMessengerStatics2>
    {
        IIsolatedWindowsHostMessengerStatics2(std::nullptr_t = nullptr) noexcept {}
        IIsolatedWindowsHostMessengerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
