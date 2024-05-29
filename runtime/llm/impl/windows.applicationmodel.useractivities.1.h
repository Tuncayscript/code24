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
#ifndef LLM_OS_ApplicationModel_UserActivities_1_H
#define LLM_OS_ApplicationModel_UserActivities_1_H
#include "llm/impl/Windows.ApplicationModel.UserActivities.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities
{
    struct __declspec(empty_bases) IUserActivity :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivity>
    {
        IUserActivity(std::nullptr_t = nullptr) noexcept {}
        IUserActivity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivity2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivity2>
    {
        IUserActivity2(std::nullptr_t = nullptr) noexcept {}
        IUserActivity2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivity3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivity3>
    {
        IUserActivity3(std::nullptr_t = nullptr) noexcept {}
        IUserActivity3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityAttribution :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityAttribution>
    {
        IUserActivityAttribution(std::nullptr_t = nullptr) noexcept {}
        IUserActivityAttribution(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityAttributionFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityAttributionFactory>
    {
        IUserActivityAttributionFactory(std::nullptr_t = nullptr) noexcept {}
        IUserActivityAttributionFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityChannel :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityChannel>
    {
        IUserActivityChannel(std::nullptr_t = nullptr) noexcept {}
        IUserActivityChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityChannel2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityChannel2>
    {
        IUserActivityChannel2(std::nullptr_t = nullptr) noexcept {}
        IUserActivityChannel2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityChannelStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityChannelStatics>
    {
        IUserActivityChannelStatics(std::nullptr_t = nullptr) noexcept {}
        IUserActivityChannelStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityChannelStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityChannelStatics2>
    {
        IUserActivityChannelStatics2(std::nullptr_t = nullptr) noexcept {}
        IUserActivityChannelStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityChannelStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityChannelStatics3>
    {
        IUserActivityChannelStatics3(std::nullptr_t = nullptr) noexcept {}
        IUserActivityChannelStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityContentInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityContentInfo>
    {
        IUserActivityContentInfo(std::nullptr_t = nullptr) noexcept {}
        IUserActivityContentInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityContentInfoStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityContentInfoStatics>
    {
        IUserActivityContentInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IUserActivityContentInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityFactory>
    {
        IUserActivityFactory(std::nullptr_t = nullptr) noexcept {}
        IUserActivityFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityRequest>
    {
        IUserActivityRequest(std::nullptr_t = nullptr) noexcept {}
        IUserActivityRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityRequestManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityRequestManager>
    {
        IUserActivityRequestManager(std::nullptr_t = nullptr) noexcept {}
        IUserActivityRequestManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityRequestManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityRequestManagerStatics>
    {
        IUserActivityRequestManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserActivityRequestManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityRequestedEventArgs>
    {
        IUserActivityRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserActivityRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivitySession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivitySession>
    {
        IUserActivitySession(std::nullptr_t = nullptr) noexcept {}
        IUserActivitySession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivitySessionHistoryItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivitySessionHistoryItem>
    {
        IUserActivitySessionHistoryItem(std::nullptr_t = nullptr) noexcept {}
        IUserActivitySessionHistoryItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityStatics>
    {
        IUserActivityStatics(std::nullptr_t = nullptr) noexcept {}
        IUserActivityStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityVisualElements :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityVisualElements>
    {
        IUserActivityVisualElements(std::nullptr_t = nullptr) noexcept {}
        IUserActivityVisualElements(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserActivityVisualElements2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserActivityVisualElements2>
    {
        IUserActivityVisualElements2(std::nullptr_t = nullptr) noexcept {}
        IUserActivityVisualElements2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
