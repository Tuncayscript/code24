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
#ifndef LLM_OS_Media_Control_2_H
#define LLM_OS_Media_Control_2_H
#include "llm/impl/Windows.Media.Control.1.h"
LLM_EXPORT namespace llm:OS::Media::Control
{
    struct __declspec(empty_bases) CurrentSessionChangedEventArgs : llm:OS::Media::Control::ICurrentSessionChangedEventArgs
    {
        CurrentSessionChangedEventArgs(std::nullptr_t) noexcept {}
        CurrentSessionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::ICurrentSessionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSession : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSession
    {
        GlobalSystemMediaTransportControlsSession(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSessionManager : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionManager
    {
        GlobalSystemMediaTransportControlsSessionManager(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSessionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionManager(ptr, take_ownership_from_abi) {}
        static auto RequestAsync();
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSessionMediaProperties : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionMediaProperties
    {
        GlobalSystemMediaTransportControlsSessionMediaProperties(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSessionMediaProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionMediaProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSessionPlaybackControls : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionPlaybackControls
    {
        GlobalSystemMediaTransportControlsSessionPlaybackControls(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSessionPlaybackControls(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionPlaybackControls(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSessionPlaybackInfo : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionPlaybackInfo
    {
        GlobalSystemMediaTransportControlsSessionPlaybackInfo(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSessionPlaybackInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionPlaybackInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GlobalSystemMediaTransportControlsSessionTimelineProperties : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionTimelineProperties
    {
        GlobalSystemMediaTransportControlsSessionTimelineProperties(std::nullptr_t) noexcept {}
        GlobalSystemMediaTransportControlsSessionTimelineProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IGlobalSystemMediaTransportControlsSessionTimelineProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaPropertiesChangedEventArgs : llm:OS::Media::Control::IMediaPropertiesChangedEventArgs
    {
        MediaPropertiesChangedEventArgs(std::nullptr_t) noexcept {}
        MediaPropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IMediaPropertiesChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PlaybackInfoChangedEventArgs : llm:OS::Media::Control::IPlaybackInfoChangedEventArgs
    {
        PlaybackInfoChangedEventArgs(std::nullptr_t) noexcept {}
        PlaybackInfoChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::IPlaybackInfoChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SessionsChangedEventArgs : llm:OS::Media::Control::ISessionsChangedEventArgs
    {
        SessionsChangedEventArgs(std::nullptr_t) noexcept {}
        SessionsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::ISessionsChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TimelinePropertiesChangedEventArgs : llm:OS::Media::Control::ITimelinePropertiesChangedEventArgs
    {
        TimelinePropertiesChangedEventArgs(std::nullptr_t) noexcept {}
        TimelinePropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Control::ITimelinePropertiesChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
