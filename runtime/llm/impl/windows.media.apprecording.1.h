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
#ifndef LLM_OS_Media_AppRecording_1_H
#define LLM_OS_Media_AppRecording_1_H
#include "llm/impl/Windows.Media.AppRecording.0.h"
LLM_EXPORT namespace llm:OS::Media::AppRecording
{
    struct __declspec(empty_bases) IAppRecordingManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingManager>
    {
        IAppRecordingManager(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingManagerStatics>
    {
        IAppRecordingManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingResult>
    {
        IAppRecordingResult(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingSaveScreenshotResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingSaveScreenshotResult>
    {
        IAppRecordingSaveScreenshotResult(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingSaveScreenshotResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingSavedScreenshotInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingSavedScreenshotInfo>
    {
        IAppRecordingSavedScreenshotInfo(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingSavedScreenshotInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingStatus :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingStatus>
    {
        IAppRecordingStatus(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppRecordingStatusDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppRecordingStatusDetails>
    {
        IAppRecordingStatusDetails(std::nullptr_t = nullptr) noexcept {}
        IAppRecordingStatusDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
