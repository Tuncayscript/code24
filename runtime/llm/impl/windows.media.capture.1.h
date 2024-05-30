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
#ifndef LLM_OS_Media_Capture_1_H
#define LLM_OS_Media_Capture_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Storage.Streams.0.h"
#include "llm/impl/Windows.Media.Capture.0.h"
LLM_EXPORT namespace llm:OS::Media::Capture
{
    struct __declspec(empty_bases) IAdvancedCapturedPhoto :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvancedCapturedPhoto>
    {
        IAdvancedCapturedPhoto(std::nullptr_t = nullptr) noexcept {}
        IAdvancedCapturedPhoto(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdvancedCapturedPhoto2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvancedCapturedPhoto2>
    {
        IAdvancedCapturedPhoto2(std::nullptr_t = nullptr) noexcept {}
        IAdvancedCapturedPhoto2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdvancedPhotoCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvancedPhotoCapture>
    {
        IAdvancedPhotoCapture(std::nullptr_t = nullptr) noexcept {}
        IAdvancedPhotoCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundService :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundService>
    {
        IAppBroadcastBackgroundService(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundService2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundService2>
    {
        IAppBroadcastBackgroundService2(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundService2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundServiceSignInInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundServiceSignInInfo>
    {
        IAppBroadcastBackgroundServiceSignInInfo(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundServiceSignInInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundServiceSignInInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundServiceSignInInfo2>
    {
        IAppBroadcastBackgroundServiceSignInInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundServiceSignInInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundServiceStreamInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundServiceStreamInfo>
    {
        IAppBroadcastBackgroundServiceStreamInfo(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundServiceStreamInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastBackgroundServiceStreamInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastBackgroundServiceStreamInfo2>
    {
        IAppBroadcastBackgroundServiceStreamInfo2(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastBackgroundServiceStreamInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastCameraCaptureStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastCameraCaptureStateChangedEventArgs>
    {
        IAppBroadcastCameraCaptureStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastCameraCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastGlobalSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastGlobalSettings>
    {
        IAppBroadcastGlobalSettings(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastGlobalSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastHeartbeatRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastHeartbeatRequestedEventArgs>
    {
        IAppBroadcastHeartbeatRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastHeartbeatRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastManagerStatics>
    {
        IAppBroadcastManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastMicrophoneCaptureStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastMicrophoneCaptureStateChangedEventArgs>
    {
        IAppBroadcastMicrophoneCaptureStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastMicrophoneCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPlugIn :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPlugIn>
    {
        IAppBroadcastPlugIn(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPlugIn(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPlugInManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPlugInManager>
    {
        IAppBroadcastPlugInManager(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPlugInManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPlugInManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPlugInManagerStatics>
    {
        IAppBroadcastPlugInManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPlugInManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPlugInStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPlugInStateChangedEventArgs>
    {
        IAppBroadcastPlugInStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPlugInStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPreview>
    {
        IAppBroadcastPreview(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPreviewStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPreviewStateChangedEventArgs>
    {
        IAppBroadcastPreviewStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPreviewStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPreviewStreamReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPreviewStreamReader>
    {
        IAppBroadcastPreviewStreamReader(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPreviewStreamReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPreviewStreamVideoFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPreviewStreamVideoFrame>
    {
        IAppBroadcastPreviewStreamVideoFrame(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPreviewStreamVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastPreviewStreamVideoHeader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastPreviewStreamVideoHeader>
    {
        IAppBroadcastPreviewStreamVideoHeader(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastPreviewStreamVideoHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastProviderSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastProviderSettings>
    {
        IAppBroadcastProviderSettings(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastProviderSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastServices :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastServices>
    {
        IAppBroadcastServices(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastSignInStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastSignInStateChangedEventArgs>
    {
        IAppBroadcastSignInStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastSignInStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastState :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastState>
    {
        IAppBroadcastState(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamAudioFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamAudioFrame>
    {
        IAppBroadcastStreamAudioFrame(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamAudioFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamAudioHeader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamAudioHeader>
    {
        IAppBroadcastStreamAudioHeader(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamAudioHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamReader>
    {
        IAppBroadcastStreamReader(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamStateChangedEventArgs>
    {
        IAppBroadcastStreamStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamVideoFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamVideoFrame>
    {
        IAppBroadcastStreamVideoFrame(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastStreamVideoHeader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastStreamVideoHeader>
    {
        IAppBroadcastStreamVideoHeader(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastStreamVideoHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastTriggerDetails>
    {
        IAppBroadcastTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppBroadcastViewerCountChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppBroadcastViewerCountChangedEventArgs>
    {
        IAppBroadcastViewerCountChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppBroadcastViewerCountChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCapture>
    {
        IAppCapture(std::nullptr_t = nullptr) noexcept {}
        IAppCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureAlternateShortcutKeys :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureAlternateShortcutKeys>
    {
        IAppCaptureAlternateShortcutKeys(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureAlternateShortcutKeys(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureAlternateShortcutKeys2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureAlternateShortcutKeys2>
    {
        IAppCaptureAlternateShortcutKeys2(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureAlternateShortcutKeys2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureAlternateShortcutKeys3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureAlternateShortcutKeys3>
    {
        IAppCaptureAlternateShortcutKeys3(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureAlternateShortcutKeys3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureDurationGeneratedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureDurationGeneratedEventArgs>
    {
        IAppCaptureDurationGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureDurationGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureFileGeneratedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureFileGeneratedEventArgs>
    {
        IAppCaptureFileGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureFileGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureManagerStatics>
    {
        IAppCaptureManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureMetadataWriter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureMetadataWriter>
    {
        IAppCaptureMetadataWriter(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureMetadataWriter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureMicrophoneCaptureStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureMicrophoneCaptureStateChangedEventArgs>
    {
        IAppCaptureMicrophoneCaptureStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureMicrophoneCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureRecordOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureRecordOperation>
    {
        IAppCaptureRecordOperation(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureRecordOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureRecordingStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureRecordingStateChangedEventArgs>
    {
        IAppCaptureRecordingStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureRecordingStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureServices :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureServices>
    {
        IAppCaptureServices(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureSettings>
    {
        IAppCaptureSettings(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureSettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureSettings2>
    {
        IAppCaptureSettings2(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureSettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureSettings3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureSettings3>
    {
        IAppCaptureSettings3(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureSettings3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureSettings4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureSettings4>
    {
        IAppCaptureSettings4(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureSettings4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureSettings5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureSettings5>
    {
        IAppCaptureSettings5(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureSettings5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureState :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureState>
    {
        IAppCaptureState(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureStatics>
    {
        IAppCaptureStatics(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCaptureStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCaptureStatics2>
    {
        IAppCaptureStatics2(std::nullptr_t = nullptr) noexcept {}
        IAppCaptureStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraCaptureUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraCaptureUI>
    {
        ICameraCaptureUI(std::nullptr_t = nullptr) noexcept {}
        ICameraCaptureUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraCaptureUIPhotoCaptureSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraCaptureUIPhotoCaptureSettings>
    {
        ICameraCaptureUIPhotoCaptureSettings(std::nullptr_t = nullptr) noexcept {}
        ICameraCaptureUIPhotoCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraCaptureUIVideoCaptureSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraCaptureUIVideoCaptureSettings>
    {
        ICameraCaptureUIVideoCaptureSettings(std::nullptr_t = nullptr) noexcept {}
        ICameraCaptureUIVideoCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraOptionsUIStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraOptionsUIStatics>
    {
        ICameraOptionsUIStatics(std::nullptr_t = nullptr) noexcept {}
        ICameraOptionsUIStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedFrame :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedFrame>,
        impl::require<llm:OS::Media::Capture::ICapturedFrame, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IInputStream, llm:OS::Storage::Streams::IOutputStream, llm:OS::Storage::Streams::IRandomAccessStream, llm:OS::Storage::Streams::IContentTypeProvider, llm:OS::Storage::Streams::IRandomAccessStreamWithContentType>
    {
        ICapturedFrame(std::nullptr_t = nullptr) noexcept {}
        ICapturedFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedFrame2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedFrame2>
    {
        ICapturedFrame2(std::nullptr_t = nullptr) noexcept {}
        ICapturedFrame2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedFrameControlValues :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedFrameControlValues>
    {
        ICapturedFrameControlValues(std::nullptr_t = nullptr) noexcept {}
        ICapturedFrameControlValues(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedFrameControlValues2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedFrameControlValues2>
    {
        ICapturedFrameControlValues2(std::nullptr_t = nullptr) noexcept {}
        ICapturedFrameControlValues2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedFrameWithSoftwareBitmap :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedFrameWithSoftwareBitmap>
    {
        ICapturedFrameWithSoftwareBitmap(std::nullptr_t = nullptr) noexcept {}
        ICapturedFrameWithSoftwareBitmap(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICapturedPhoto :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICapturedPhoto>
    {
        ICapturedPhoto(std::nullptr_t = nullptr) noexcept {}
        ICapturedPhoto(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServices :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServices>
    {
        IGameBarServices(std::nullptr_t = nullptr) noexcept {}
        IGameBarServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServicesCommandEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServicesCommandEventArgs>
    {
        IGameBarServicesCommandEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGameBarServicesCommandEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServicesManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServicesManager>
    {
        IGameBarServicesManager(std::nullptr_t = nullptr) noexcept {}
        IGameBarServicesManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServicesManagerGameBarServicesCreatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServicesManagerGameBarServicesCreatedEventArgs>
    {
        IGameBarServicesManagerGameBarServicesCreatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGameBarServicesManagerGameBarServicesCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServicesManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServicesManagerStatics>
    {
        IGameBarServicesManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IGameBarServicesManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameBarServicesTargetInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarServicesTargetInfo>
    {
        IGameBarServicesTargetInfo(std::nullptr_t = nullptr) noexcept {}
        IGameBarServicesTargetInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLagMediaRecording :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLagMediaRecording>
    {
        ILowLagMediaRecording(std::nullptr_t = nullptr) noexcept {}
        ILowLagMediaRecording(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLagMediaRecording2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLagMediaRecording2>
    {
        ILowLagMediaRecording2(std::nullptr_t = nullptr) noexcept {}
        ILowLagMediaRecording2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLagMediaRecording3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLagMediaRecording3>
    {
        ILowLagMediaRecording3(std::nullptr_t = nullptr) noexcept {}
        ILowLagMediaRecording3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLagPhotoCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLagPhotoCapture>
    {
        ILowLagPhotoCapture(std::nullptr_t = nullptr) noexcept {}
        ILowLagPhotoCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILowLagPhotoSequenceCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILowLagPhotoSequenceCapture>
    {
        ILowLagPhotoSequenceCapture(std::nullptr_t = nullptr) noexcept {}
        ILowLagPhotoSequenceCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture>
    {
        IMediaCapture(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture2>
    {
        IMediaCapture2(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture3>
    {
        IMediaCapture3(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture4>
    {
        IMediaCapture4(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture5>
    {
        IMediaCapture5(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture6>
    {
        IMediaCapture6(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapture7 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapture7>
    {
        IMediaCapture7(std::nullptr_t = nullptr) noexcept {}
        IMediaCapture7(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs>
    {
        IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureFailedEventArgs>
    {
        IMediaCaptureFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureFocusChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureFocusChangedEventArgs>
    {
        IMediaCaptureFocusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureFocusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings>
    {
        IMediaCaptureInitializationSettings(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings2>
    {
        IMediaCaptureInitializationSettings2(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings3>
    {
        IMediaCaptureInitializationSettings3(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings4>
    {
        IMediaCaptureInitializationSettings4(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings5>
    {
        IMediaCaptureInitializationSettings5(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings6>
    {
        IMediaCaptureInitializationSettings6(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureInitializationSettings7 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureInitializationSettings7>
    {
        IMediaCaptureInitializationSettings7(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureInitializationSettings7(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCapturePauseResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCapturePauseResult>
    {
        IMediaCapturePauseResult(std::nullptr_t = nullptr) noexcept {}
        IMediaCapturePauseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureRelativePanelWatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureRelativePanelWatcher>
    {
        IMediaCaptureRelativePanelWatcher(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureRelativePanelWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureSettings>
    {
        IMediaCaptureSettings(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureSettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureSettings2>
    {
        IMediaCaptureSettings2(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureSettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureSettings3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureSettings3>
    {
        IMediaCaptureSettings3(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureSettings3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureStatics>
    {
        IMediaCaptureStatics(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureStopResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureStopResult>
    {
        IMediaCaptureStopResult(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureStopResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureVideoPreview :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureVideoPreview>
    {
        IMediaCaptureVideoPreview(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureVideoPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureVideoProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureVideoProfile>
    {
        IMediaCaptureVideoProfile(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureVideoProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureVideoProfile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureVideoProfile2>
    {
        IMediaCaptureVideoProfile2(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureVideoProfile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureVideoProfileMediaDescription :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureVideoProfileMediaDescription>
    {
        IMediaCaptureVideoProfileMediaDescription(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureVideoProfileMediaDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaCaptureVideoProfileMediaDescription2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaCaptureVideoProfileMediaDescription2>
    {
        IMediaCaptureVideoProfileMediaDescription2(std::nullptr_t = nullptr) noexcept {}
        IMediaCaptureVideoProfileMediaDescription2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IOptionalReferencePhotoCapturedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOptionalReferencePhotoCapturedEventArgs>
    {
        IOptionalReferencePhotoCapturedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IOptionalReferencePhotoCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoCapturedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoCapturedEventArgs>
    {
        IPhotoCapturedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhotoCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhotoConfirmationCapturedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPhotoConfirmationCapturedEventArgs>
    {
        IPhotoConfirmationCapturedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhotoConfirmationCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVideoStreamConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVideoStreamConfiguration>
    {
        IVideoStreamConfiguration(std::nullptr_t = nullptr) noexcept {}
        IVideoStreamConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
