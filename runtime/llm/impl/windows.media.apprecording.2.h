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
#ifndef LLM_OS_Media_AppRecording_2_H
#define LLM_OS_Media_AppRecording_2_H
#include "llm/impl/Windows.Media.AppRecording.1.h"
LLM_EXPORT namespace llm:OS::Media::AppRecording
{
    struct __declspec(empty_bases) AppRecordingManager : llm:OS::Media::AppRecording::IAppRecordingManager
    {
        AppRecordingManager(std::nullptr_t) noexcept {}
        AppRecordingManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) AppRecordingResult : llm:OS::Media::AppRecording::IAppRecordingResult
    {
        AppRecordingResult(std::nullptr_t) noexcept {}
        AppRecordingResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppRecordingSaveScreenshotResult : llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult
    {
        AppRecordingSaveScreenshotResult(std::nullptr_t) noexcept {}
        AppRecordingSaveScreenshotResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingSaveScreenshotResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppRecordingSavedScreenshotInfo : llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo
    {
        AppRecordingSavedScreenshotInfo(std::nullptr_t) noexcept {}
        AppRecordingSavedScreenshotInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingSavedScreenshotInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppRecordingStatus : llm:OS::Media::AppRecording::IAppRecordingStatus
    {
        AppRecordingStatus(std::nullptr_t) noexcept {}
        AppRecordingStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppRecordingStatusDetails : llm:OS::Media::AppRecording::IAppRecordingStatusDetails
    {
        AppRecordingStatusDetails(std::nullptr_t) noexcept {}
        AppRecordingStatusDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::AppRecording::IAppRecordingStatusDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
