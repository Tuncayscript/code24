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
#ifndef LLM_OS_UI_Core_Preview_Communications_1_H
#define LLM_OS_UI_Core_Preview_Communications_1_H
#include "llm/impl/Windows.UI.Core.Preview.Communications.0.h"
LLM_EXPORT namespace llm:OS::UI::Core::Preview::Communications
{
    struct __declspec(empty_bases) IPreviewTeamCleanupRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamCleanupRequestedEventArgs>
    {
        IPreviewTeamCleanupRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamCleanupRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamCommandInvokedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamCommandInvokedEventArgs>
    {
        IPreviewTeamCommandInvokedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamCommandInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamDeviceCredentials :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamDeviceCredentials>
    {
        IPreviewTeamDeviceCredentials(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamDeviceCredentials(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamEndMeetingRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamEndMeetingRequestedEventArgs>
    {
        IPreviewTeamEndMeetingRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamEndMeetingRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamJoinMeetingRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamJoinMeetingRequestedEventArgs>
    {
        IPreviewTeamJoinMeetingRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamJoinMeetingRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamView>
    {
        IPreviewTeamView(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamView2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamView2>
    {
        IPreviewTeamView2(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamView2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewTeamViewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewTeamViewStatics>
    {
        IPreviewTeamViewStatics(std::nullptr_t = nullptr) noexcept {}
        IPreviewTeamViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
