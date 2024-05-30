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
#ifndef LLM_OS_Media_Capture_2_H
#define LLM_OS_Media_Capture_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Media.Capture.1.h"
LLM_EXPORT namespace llm:OS::Media::Capture
{
    struct MediaCaptureFailedEventHandler : llm:OS::Foundation::IUnknown
    {
        MediaCaptureFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
        MediaCaptureFailedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MediaCaptureFailedEventHandler(L lambda);
        template <typename F> MediaCaptureFailedEventHandler(F* function);
        template <typename O, typename M> MediaCaptureFailedEventHandler(O* object, M method);
        template <typename O, typename M> MediaCaptureFailedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MediaCaptureFailedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Capture::MediaCapture const& sender, llm:OS::Media::Capture::MediaCaptureFailedEventArgs const& errorEventArgs) const;
    };
    struct RecordLimitationExceededEventHandler : llm:OS::Foundation::IUnknown
    {
        RecordLimitationExceededEventHandler(std::nullptr_t = nullptr) noexcept {}
        RecordLimitationExceededEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RecordLimitationExceededEventHandler(L lambda);
        template <typename F> RecordLimitationExceededEventHandler(F* function);
        template <typename O, typename M> RecordLimitationExceededEventHandler(O* object, M method);
        template <typename O, typename M> RecordLimitationExceededEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RecordLimitationExceededEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Capture::MediaCapture const& sender) const;
    };
    struct WhiteBalanceGain
    {
        double R;
        double G;
        double B;
    };
    inline bool operator==(WhiteBalanceGain const& left, WhiteBalanceGain const& right) noexcept
    {
        return left.R == right.R && left.G == right.G && left.B == right.B;
    }
    inline bool operator!=(WhiteBalanceGain const& left, WhiteBalanceGain const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AdvancedCapturedPhoto : llm:OS::Media::Capture::IAdvancedCapturedPhoto,
        impl::require<AdvancedCapturedPhoto, llm:OS::Media::Capture::IAdvancedCapturedPhoto2>
    {
        AdvancedCapturedPhoto(std::nullptr_t) noexcept {}
        AdvancedCapturedPhoto(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAdvancedCapturedPhoto(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AdvancedPhotoCapture : llm:OS::Media::Capture::IAdvancedPhotoCapture
    {
        AdvancedPhotoCapture(std::nullptr_t) noexcept {}
        AdvancedPhotoCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAdvancedPhotoCapture(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastBackgroundService : llm:OS::Media::Capture::IAppBroadcastBackgroundService,
        impl::require<AppBroadcastBackgroundService, llm:OS::Media::Capture::IAppBroadcastBackgroundService2>
    {
        AppBroadcastBackgroundService(std::nullptr_t) noexcept {}
        AppBroadcastBackgroundService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastBackgroundService(ptr, take_ownership_from_abi) {}
        using llm:OS::Media::Capture::IAppBroadcastBackgroundService::BroadcastTitle;
        using impl::consume_t<AppBroadcastBackgroundService, llm:OS::Media::Capture::IAppBroadcastBackgroundService2>::BroadcastTitle;
    };
    struct __declspec(empty_bases) AppBroadcastBackgroundServiceSignInInfo : llm:OS::Media::Capture::IAppBroadcastBackgroundServiceSignInInfo,
        impl::require<AppBroadcastBackgroundServiceSignInInfo, llm:OS::Media::Capture::IAppBroadcastBackgroundServiceSignInInfo2>
    {
        AppBroadcastBackgroundServiceSignInInfo(std::nullptr_t) noexcept {}
        AppBroadcastBackgroundServiceSignInInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastBackgroundServiceSignInInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastBackgroundServiceStreamInfo : llm:OS::Media::Capture::IAppBroadcastBackgroundServiceStreamInfo,
        impl::require<AppBroadcastBackgroundServiceStreamInfo, llm:OS::Media::Capture::IAppBroadcastBackgroundServiceStreamInfo2>
    {
        AppBroadcastBackgroundServiceStreamInfo(std::nullptr_t) noexcept {}
        AppBroadcastBackgroundServiceStreamInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastBackgroundServiceStreamInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastCameraCaptureStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastCameraCaptureStateChangedEventArgs
    {
        AppBroadcastCameraCaptureStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastCameraCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastCameraCaptureStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastGlobalSettings : llm:OS::Media::Capture::IAppBroadcastGlobalSettings
    {
        AppBroadcastGlobalSettings(std::nullptr_t) noexcept {}
        AppBroadcastGlobalSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastGlobalSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastHeartbeatRequestedEventArgs : llm:OS::Media::Capture::IAppBroadcastHeartbeatRequestedEventArgs
    {
        AppBroadcastHeartbeatRequestedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastHeartbeatRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastHeartbeatRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct AppBroadcastManager
    {
        AppBroadcastManager() = delete;
        static auto GetGlobalSettings();
        static auto ApplyGlobalSettings(llm:OS::Media::Capture::AppBroadcastGlobalSettings const& value);
        static auto GetProviderSettings();
        static auto ApplyProviderSettings(llm:OS::Media::Capture::AppBroadcastProviderSettings const& value);
    };
    struct __declspec(empty_bases) AppBroadcastMicrophoneCaptureStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastMicrophoneCaptureStateChangedEventArgs
    {
        AppBroadcastMicrophoneCaptureStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastMicrophoneCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastMicrophoneCaptureStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPlugIn : llm:OS::Media::Capture::IAppBroadcastPlugIn
    {
        AppBroadcastPlugIn(std::nullptr_t) noexcept {}
        AppBroadcastPlugIn(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPlugIn(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPlugInManager : llm:OS::Media::Capture::IAppBroadcastPlugInManager
    {
        AppBroadcastPlugInManager(std::nullptr_t) noexcept {}
        AppBroadcastPlugInManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPlugInManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) AppBroadcastPlugInStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastPlugInStateChangedEventArgs
    {
        AppBroadcastPlugInStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastPlugInStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPlugInStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPreview : llm:OS::Media::Capture::IAppBroadcastPreview
    {
        AppBroadcastPreview(std::nullptr_t) noexcept {}
        AppBroadcastPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPreview(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPreviewStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastPreviewStateChangedEventArgs
    {
        AppBroadcastPreviewStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastPreviewStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPreviewStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPreviewStreamReader : llm:OS::Media::Capture::IAppBroadcastPreviewStreamReader
    {
        AppBroadcastPreviewStreamReader(std::nullptr_t) noexcept {}
        AppBroadcastPreviewStreamReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPreviewStreamReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPreviewStreamVideoFrame : llm:OS::Media::Capture::IAppBroadcastPreviewStreamVideoFrame
    {
        AppBroadcastPreviewStreamVideoFrame(std::nullptr_t) noexcept {}
        AppBroadcastPreviewStreamVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPreviewStreamVideoFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastPreviewStreamVideoHeader : llm:OS::Media::Capture::IAppBroadcastPreviewStreamVideoHeader
    {
        AppBroadcastPreviewStreamVideoHeader(std::nullptr_t) noexcept {}
        AppBroadcastPreviewStreamVideoHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastPreviewStreamVideoHeader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastProviderSettings : llm:OS::Media::Capture::IAppBroadcastProviderSettings
    {
        AppBroadcastProviderSettings(std::nullptr_t) noexcept {}
        AppBroadcastProviderSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastProviderSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastServices : llm:OS::Media::Capture::IAppBroadcastServices
    {
        AppBroadcastServices(std::nullptr_t) noexcept {}
        AppBroadcastServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastServices(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastSignInStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastSignInStateChangedEventArgs
    {
        AppBroadcastSignInStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastSignInStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastSignInStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastState : llm:OS::Media::Capture::IAppBroadcastState
    {
        AppBroadcastState(std::nullptr_t) noexcept {}
        AppBroadcastState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamAudioFrame : llm:OS::Media::Capture::IAppBroadcastStreamAudioFrame
    {
        AppBroadcastStreamAudioFrame(std::nullptr_t) noexcept {}
        AppBroadcastStreamAudioFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamAudioFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamAudioHeader : llm:OS::Media::Capture::IAppBroadcastStreamAudioHeader
    {
        AppBroadcastStreamAudioHeader(std::nullptr_t) noexcept {}
        AppBroadcastStreamAudioHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamAudioHeader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamReader : llm:OS::Media::Capture::IAppBroadcastStreamReader
    {
        AppBroadcastStreamReader(std::nullptr_t) noexcept {}
        AppBroadcastStreamReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamStateChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastStreamStateChangedEventArgs
    {
        AppBroadcastStreamStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastStreamStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamVideoFrame : llm:OS::Media::Capture::IAppBroadcastStreamVideoFrame
    {
        AppBroadcastStreamVideoFrame(std::nullptr_t) noexcept {}
        AppBroadcastStreamVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamVideoFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastStreamVideoHeader : llm:OS::Media::Capture::IAppBroadcastStreamVideoHeader
    {
        AppBroadcastStreamVideoHeader(std::nullptr_t) noexcept {}
        AppBroadcastStreamVideoHeader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastStreamVideoHeader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastTriggerDetails : llm:OS::Media::Capture::IAppBroadcastTriggerDetails
    {
        AppBroadcastTriggerDetails(std::nullptr_t) noexcept {}
        AppBroadcastTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppBroadcastViewerCountChangedEventArgs : llm:OS::Media::Capture::IAppBroadcastViewerCountChangedEventArgs
    {
        AppBroadcastViewerCountChangedEventArgs(std::nullptr_t) noexcept {}
        AppBroadcastViewerCountChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppBroadcastViewerCountChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCapture : llm:OS::Media::Capture::IAppCapture
    {
        AppCapture(std::nullptr_t) noexcept {}
        AppCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCapture(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto SetAllowedAsync(bool allowed);
    };
    struct __declspec(empty_bases) AppCaptureAlternateShortcutKeys : llm:OS::Media::Capture::IAppCaptureAlternateShortcutKeys,
        impl::require<AppCaptureAlternateShortcutKeys, llm:OS::Media::Capture::IAppCaptureAlternateShortcutKeys2, llm:OS::Media::Capture::IAppCaptureAlternateShortcutKeys3>
    {
        AppCaptureAlternateShortcutKeys(std::nullptr_t) noexcept {}
        AppCaptureAlternateShortcutKeys(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureAlternateShortcutKeys(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureDurationGeneratedEventArgs : llm:OS::Media::Capture::IAppCaptureDurationGeneratedEventArgs
    {
        AppCaptureDurationGeneratedEventArgs(std::nullptr_t) noexcept {}
        AppCaptureDurationGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureDurationGeneratedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureFileGeneratedEventArgs : llm:OS::Media::Capture::IAppCaptureFileGeneratedEventArgs
    {
        AppCaptureFileGeneratedEventArgs(std::nullptr_t) noexcept {}
        AppCaptureFileGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureFileGeneratedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct AppCaptureManager
    {
        AppCaptureManager() = delete;
        static auto GetCurrentSettings();
        static auto ApplySettings(llm:OS::Media::Capture::AppCaptureSettings const& appCaptureSettings);
    };
    struct __declspec(empty_bases) AppCaptureMetadataWriter : llm:OS::Media::Capture::IAppCaptureMetadataWriter,
        impl::require<AppCaptureMetadataWriter, llm:OS::Foundation::IClosable>
    {
        AppCaptureMetadataWriter(std::nullptr_t) noexcept {}
        AppCaptureMetadataWriter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureMetadataWriter(ptr, take_ownership_from_abi) {}
        AppCaptureMetadataWriter();
    };
    struct __declspec(empty_bases) AppCaptureMicrophoneCaptureStateChangedEventArgs : llm:OS::Media::Capture::IAppCaptureMicrophoneCaptureStateChangedEventArgs
    {
        AppCaptureMicrophoneCaptureStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppCaptureMicrophoneCaptureStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureMicrophoneCaptureStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureRecordOperation : llm:OS::Media::Capture::IAppCaptureRecordOperation
    {
        AppCaptureRecordOperation(std::nullptr_t) noexcept {}
        AppCaptureRecordOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureRecordOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureRecordingStateChangedEventArgs : llm:OS::Media::Capture::IAppCaptureRecordingStateChangedEventArgs
    {
        AppCaptureRecordingStateChangedEventArgs(std::nullptr_t) noexcept {}
        AppCaptureRecordingStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureRecordingStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureServices : llm:OS::Media::Capture::IAppCaptureServices
    {
        AppCaptureServices(std::nullptr_t) noexcept {}
        AppCaptureServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureServices(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureSettings : llm:OS::Media::Capture::IAppCaptureSettings,
        impl::require<AppCaptureSettings, llm:OS::Media::Capture::IAppCaptureSettings2, llm:OS::Media::Capture::IAppCaptureSettings3, llm:OS::Media::Capture::IAppCaptureSettings4, llm:OS::Media::Capture::IAppCaptureSettings5>
    {
        AppCaptureSettings(std::nullptr_t) noexcept {}
        AppCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppCaptureState : llm:OS::Media::Capture::IAppCaptureState
    {
        AppCaptureState(std::nullptr_t) noexcept {}
        AppCaptureState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IAppCaptureState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraCaptureUI : llm:OS::Media::Capture::ICameraCaptureUI
    {
        CameraCaptureUI(std::nullptr_t) noexcept {}
        CameraCaptureUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICameraCaptureUI(ptr, take_ownership_from_abi) {}
        CameraCaptureUI();
    };
    struct __declspec(empty_bases) CameraCaptureUIPhotoCaptureSettings : llm:OS::Media::Capture::ICameraCaptureUIPhotoCaptureSettings
    {
        CameraCaptureUIPhotoCaptureSettings(std::nullptr_t) noexcept {}
        CameraCaptureUIPhotoCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICameraCaptureUIPhotoCaptureSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraCaptureUIVideoCaptureSettings : llm:OS::Media::Capture::ICameraCaptureUIVideoCaptureSettings
    {
        CameraCaptureUIVideoCaptureSettings(std::nullptr_t) noexcept {}
        CameraCaptureUIVideoCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICameraCaptureUIVideoCaptureSettings(ptr, take_ownership_from_abi) {}
    };
    struct CameraOptionsUI
    {
        CameraOptionsUI() = delete;
        static auto Show(llm:OS::Media::Capture::MediaCapture const& mediaCapture);
    };
    struct __declspec(empty_bases) CapturedFrame : llm:OS::Media::Capture::ICapturedFrame,
        impl::require<CapturedFrame, llm:OS::Media::Capture::ICapturedFrameWithSoftwareBitmap, llm:OS::Media::Capture::ICapturedFrame2>
    {
        CapturedFrame(std::nullptr_t) noexcept {}
        CapturedFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICapturedFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CapturedFrameControlValues : llm:OS::Media::Capture::ICapturedFrameControlValues,
        impl::require<CapturedFrameControlValues, llm:OS::Media::Capture::ICapturedFrameControlValues2>
    {
        CapturedFrameControlValues(std::nullptr_t) noexcept {}
        CapturedFrameControlValues(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICapturedFrameControlValues(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CapturedPhoto : llm:OS::Media::Capture::ICapturedPhoto
    {
        CapturedPhoto(std::nullptr_t) noexcept {}
        CapturedPhoto(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ICapturedPhoto(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameBarServices : llm:OS::Media::Capture::IGameBarServices
    {
        GameBarServices(std::nullptr_t) noexcept {}
        GameBarServices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IGameBarServices(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameBarServicesCommandEventArgs : llm:OS::Media::Capture::IGameBarServicesCommandEventArgs
    {
        GameBarServicesCommandEventArgs(std::nullptr_t) noexcept {}
        GameBarServicesCommandEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IGameBarServicesCommandEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameBarServicesManager : llm:OS::Media::Capture::IGameBarServicesManager
    {
        GameBarServicesManager(std::nullptr_t) noexcept {}
        GameBarServicesManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IGameBarServicesManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) GameBarServicesManagerGameBarServicesCreatedEventArgs : llm:OS::Media::Capture::IGameBarServicesManagerGameBarServicesCreatedEventArgs
    {
        GameBarServicesManagerGameBarServicesCreatedEventArgs(std::nullptr_t) noexcept {}
        GameBarServicesManagerGameBarServicesCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IGameBarServicesManagerGameBarServicesCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameBarServicesTargetInfo : llm:OS::Media::Capture::IGameBarServicesTargetInfo
    {
        GameBarServicesTargetInfo(std::nullptr_t) noexcept {}
        GameBarServicesTargetInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IGameBarServicesTargetInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LowLagMediaRecording : llm:OS::Media::Capture::ILowLagMediaRecording,
        impl::require<LowLagMediaRecording, llm:OS::Media::Capture::ILowLagMediaRecording2, llm:OS::Media::Capture::ILowLagMediaRecording3>
    {
        LowLagMediaRecording(std::nullptr_t) noexcept {}
        LowLagMediaRecording(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ILowLagMediaRecording(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LowLagPhotoCapture : llm:OS::Media::Capture::ILowLagPhotoCapture
    {
        LowLagPhotoCapture(std::nullptr_t) noexcept {}
        LowLagPhotoCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ILowLagPhotoCapture(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LowLagPhotoSequenceCapture : llm:OS::Media::Capture::ILowLagPhotoSequenceCapture
    {
        LowLagPhotoSequenceCapture(std::nullptr_t) noexcept {}
        LowLagPhotoSequenceCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::ILowLagPhotoSequenceCapture(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCapture : llm:OS::Media::Capture::IMediaCapture,
        impl::require<MediaCapture, llm:OS::Media::Capture::IMediaCaptureVideoPreview, llm:OS::Media::Capture::IMediaCapture2, llm:OS::Foundation::IClosable, llm:OS::Media::Capture::IMediaCapture3, llm:OS::Media::Capture::IMediaCapture4, llm:OS::Media::Capture::IMediaCapture5, llm:OS::Media::Capture::IMediaCapture6, llm:OS::Media::Capture::IMediaCapture7>
    {
        MediaCapture(std::nullptr_t) noexcept {}
        MediaCapture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCapture(ptr, take_ownership_from_abi) {}
        MediaCapture();
        static auto IsVideoProfileSupported(param::hstring const& videoDeviceId);
        static auto FindAllVideoProfiles(param::hstring const& videoDeviceId);
        static auto FindConcurrentProfiles(param::hstring const& videoDeviceId);
        static auto FindKnownVideoProfiles(param::hstring const& videoDeviceId, llm:OS::Media::Capture::KnownVideoProfile const& name);
    };
    struct __declspec(empty_bases) MediaCaptureDeviceExclusiveControlStatusChangedEventArgs : llm:OS::Media::Capture::IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs
    {
        MediaCaptureDeviceExclusiveControlStatusChangedEventArgs(std::nullptr_t) noexcept {}
        MediaCaptureDeviceExclusiveControlStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureDeviceExclusiveControlStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureFailedEventArgs : llm:OS::Media::Capture::IMediaCaptureFailedEventArgs
    {
        MediaCaptureFailedEventArgs(std::nullptr_t) noexcept {}
        MediaCaptureFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureFocusChangedEventArgs : llm:OS::Media::Capture::IMediaCaptureFocusChangedEventArgs
    {
        MediaCaptureFocusChangedEventArgs(std::nullptr_t) noexcept {}
        MediaCaptureFocusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureFocusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureInitializationSettings : llm:OS::Media::Capture::IMediaCaptureInitializationSettings,
        impl::require<MediaCaptureInitializationSettings, llm:OS::Media::Capture::IMediaCaptureInitializationSettings2, llm:OS::Media::Capture::IMediaCaptureInitializationSettings3, llm:OS::Media::Capture::IMediaCaptureInitializationSettings4, llm:OS::Media::Capture::IMediaCaptureInitializationSettings5, llm:OS::Media::Capture::IMediaCaptureInitializationSettings6, llm:OS::Media::Capture::IMediaCaptureInitializationSettings7>
    {
        MediaCaptureInitializationSettings(std::nullptr_t) noexcept {}
        MediaCaptureInitializationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureInitializationSettings(ptr, take_ownership_from_abi) {}
        MediaCaptureInitializationSettings();
    };
    struct __declspec(empty_bases) MediaCapturePauseResult : llm:OS::Media::Capture::IMediaCapturePauseResult,
        impl::require<MediaCapturePauseResult, llm:OS::Foundation::IClosable>
    {
        MediaCapturePauseResult(std::nullptr_t) noexcept {}
        MediaCapturePauseResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCapturePauseResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureRelativePanelWatcher : llm:OS::Media::Capture::IMediaCaptureRelativePanelWatcher,
        impl::require<MediaCaptureRelativePanelWatcher, llm:OS::Foundation::IClosable>
    {
        MediaCaptureRelativePanelWatcher(std::nullptr_t) noexcept {}
        MediaCaptureRelativePanelWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureRelativePanelWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureSettings : llm:OS::Media::Capture::IMediaCaptureSettings,
        impl::require<MediaCaptureSettings, llm:OS::Media::Capture::IMediaCaptureSettings2, llm:OS::Media::Capture::IMediaCaptureSettings3>
    {
        MediaCaptureSettings(std::nullptr_t) noexcept {}
        MediaCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureStopResult : llm:OS::Media::Capture::IMediaCaptureStopResult,
        impl::require<MediaCaptureStopResult, llm:OS::Foundation::IClosable>
    {
        MediaCaptureStopResult(std::nullptr_t) noexcept {}
        MediaCaptureStopResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureStopResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureVideoProfile : llm:OS::Media::Capture::IMediaCaptureVideoProfile,
        impl::require<MediaCaptureVideoProfile, llm:OS::Media::Capture::IMediaCaptureVideoProfile2>
    {
        MediaCaptureVideoProfile(std::nullptr_t) noexcept {}
        MediaCaptureVideoProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureVideoProfile(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaCaptureVideoProfileMediaDescription : llm:OS::Media::Capture::IMediaCaptureVideoProfileMediaDescription,
        impl::require<MediaCaptureVideoProfileMediaDescription, llm:OS::Media::Capture::IMediaCaptureVideoProfileMediaDescription2>
    {
        MediaCaptureVideoProfileMediaDescription(std::nullptr_t) noexcept {}
        MediaCaptureVideoProfileMediaDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IMediaCaptureVideoProfileMediaDescription(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OptionalReferencePhotoCapturedEventArgs : llm:OS::Media::Capture::IOptionalReferencePhotoCapturedEventArgs
    {
        OptionalReferencePhotoCapturedEventArgs(std::nullptr_t) noexcept {}
        OptionalReferencePhotoCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IOptionalReferencePhotoCapturedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoCapturedEventArgs : llm:OS::Media::Capture::IPhotoCapturedEventArgs
    {
        PhotoCapturedEventArgs(std::nullptr_t) noexcept {}
        PhotoCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IPhotoCapturedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoConfirmationCapturedEventArgs : llm:OS::Media::Capture::IPhotoConfirmationCapturedEventArgs
    {
        PhotoConfirmationCapturedEventArgs(std::nullptr_t) noexcept {}
        PhotoConfirmationCapturedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IPhotoConfirmationCapturedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoStreamConfiguration : llm:OS::Media::Capture::IVideoStreamConfiguration
    {
        VideoStreamConfiguration(std::nullptr_t) noexcept {}
        VideoStreamConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Capture::IVideoStreamConfiguration(ptr, take_ownership_from_abi) {}
    };
}
#endif
