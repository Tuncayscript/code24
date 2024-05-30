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
#ifndef LLM_OS_Media_Control_1_H
#define LLM_OS_Media_Control_1_H
#include "llm/impl/Windows.Media.Control.0.h"
LLM_EXPORT namespace llm:OS::Media::Control
{
    struct __declspec(empty_bases) ICurrentSessionChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICurrentSessionChangedEventArgs>
    {
        ICurrentSessionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICurrentSessionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSession>
    {
        IGlobalSystemMediaTransportControlsSession(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionManager>
    {
        IGlobalSystemMediaTransportControlsSessionManager(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionManagerStatics>
    {
        IGlobalSystemMediaTransportControlsSessionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionMediaProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionMediaProperties>
    {
        IGlobalSystemMediaTransportControlsSessionMediaProperties(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionMediaProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionPlaybackControls :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionPlaybackControls>
    {
        IGlobalSystemMediaTransportControlsSessionPlaybackControls(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionPlaybackControls(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionPlaybackInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionPlaybackInfo>
    {
        IGlobalSystemMediaTransportControlsSessionPlaybackInfo(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionPlaybackInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalSystemMediaTransportControlsSessionTimelineProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalSystemMediaTransportControlsSessionTimelineProperties>
    {
        IGlobalSystemMediaTransportControlsSessionTimelineProperties(std::nullptr_t = nullptr) noexcept {}
        IGlobalSystemMediaTransportControlsSessionTimelineProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaPropertiesChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaPropertiesChangedEventArgs>
    {
        IMediaPropertiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaPropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPlaybackInfoChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPlaybackInfoChangedEventArgs>
    {
        IPlaybackInfoChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPlaybackInfoChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISessionsChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISessionsChangedEventArgs>
    {
        ISessionsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISessionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITimelinePropertiesChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITimelinePropertiesChangedEventArgs>
    {
        ITimelinePropertiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITimelinePropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
