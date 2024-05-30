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
#ifndef LLM_OS_Media_Devices_0_H
#define LLM_OS_Media_Devices_0_H
LLM_EXPORT namespace llm:OS::Devices::Enumeration
{
    enum class Panel : int32_t;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Media::Capture
{
    enum class MediaCaptureDeviceExclusiveControlReleaseMode : int32_t;
    enum class MediaStreamType : int32_t;
    enum class PowerlineFrequency : int32_t;
}
LLM_EXPORT namespace llm:OS::Media::Devices::Core
{
    struct VariablePhotoSequenceController;
}
LLM_EXPORT namespace llm:OS::Media::MediaProperties
{
    struct IMediaEncodingProperties;
    enum class MediaPixelFormat : int32_t;
    struct MediaRatio;
    enum class MediaThumbnailFormat : int32_t;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::Media::Devices
{
    enum class AdvancedPhotoMode : int32_t
    {
        Auto = 0,
        Standard = 1,
        Hdr = 2,
        LowLight = 3,
    };
    enum class AudioDeviceRole : int32_t
    {
        Default = 0,
        Communications = 1,
    };
    enum class AutoFocusRange : int32_t
    {
        FullRange = 0,
        Macro = 1,
        Normal = 2,
    };
    enum class CameraOcclusionKind : int32_t
    {
        Lid = 0,
        CameraHardware = 1,
    };
    enum class CameraStreamState : int32_t
    {
        NotStreaming = 0,
        Streaming = 1,
        BlockedForPrivacy = 2,
        Shutdown = 3,
    };
    enum class CaptureSceneMode : int32_t
    {
        Auto = 0,
        Manual = 1,
        Macro = 2,
        Portrait = 3,
        Sport = 4,
        Snow = 5,
        Night = 6,
        Beach = 7,
        Sunset = 8,
        Candlelight = 9,
        Landscape = 10,
        NightPortrait = 11,
        Backlit = 12,
    };
    enum class CaptureUse : int32_t
    {
        None = 0,
        Photo = 1,
        Video = 2,
    };
    enum class ColorTemperaturePreset : int32_t
    {
        Auto = 0,
        Manual = 1,
        Cloudy = 2,
        Daylight = 3,
        Flash = 4,
        Fluorescent = 5,
        Tungsten = 6,
        Candlelight = 7,
    };
    enum class DigitalWindowMode : int32_t
    {
        Off = 0,
        On = 1,
        Auto = 2,
    };
    enum class FocusMode : int32_t
    {
        Auto = 0,
        Single = 1,
        Continuous = 2,
        Manual = 3,
    };
    enum class FocusPreset : int32_t
    {
        Auto = 0,
        Manual = 1,
        AutoMacro = 2,
        AutoNormal = 3,
        AutoInfinity = 4,
        AutoHyperfocal = 5,
    };
    enum class HdrVideoMode : int32_t
    {
        Off = 0,
        On = 1,
        Auto = 2,
    };
    enum class InfraredTorchMode : int32_t
    {
        Off = 0,
        On = 1,
        AlternatingFrameIllumination = 2,
    };
    enum class IsoSpeedPreset : int32_t
    {
        Auto = 0,
        Iso50 = 1,
        Iso80 = 2,
        Iso100 = 3,
        Iso200 = 4,
        Iso400 = 5,
        Iso800 = 6,
        Iso1600 = 7,
        Iso3200 = 8,
        Iso6400 = 9,
        Iso12800 = 10,
        Iso25600 = 11,
    };
    enum class ManualFocusDistance : int32_t
    {
        Infinity = 0,
        Hyperfocal = 1,
        Nearest = 2,
    };
    enum class MediaCaptureFocusState : int32_t
    {
        Uninitialized = 0,
        Lost = 1,
        Searching = 2,
        Focused = 3,
        Failed = 4,
    };
    enum class MediaCaptureOptimization : int32_t
    {
        Default = 0,
        Quality = 1,
        Latency = 2,
        Power = 3,
        LatencyThenQuality = 4,
        LatencyThenPower = 5,
        PowerAndQuality = 6,
    };
    enum class MediaCapturePauseBehavior : int32_t
    {
        RetainHardwareResources = 0,
        ReleaseHardwareResources = 1,
    };
    enum class OpticalImageStabilizationMode : int32_t
    {
        Off = 0,
        On = 1,
        Auto = 2,
    };
    enum class RegionOfInterestType : int32_t
    {
        Unknown = 0,
        Face = 1,
    };
    enum class SendCommandStatus : int32_t
    {
        Success = 0,
        DeviceNotAvailable = 1,
    };
    enum class TelephonyKey : int32_t
    {
        D0 = 0,
        D1 = 1,
        D2 = 2,
        D3 = 3,
        D4 = 4,
        D5 = 5,
        D6 = 6,
        D7 = 7,
        D8 = 8,
        D9 = 9,
        Star = 10,
        Pound = 11,
        A = 12,
        B = 13,
        C = 14,
        D = 15,
    };
    enum class VideoDeviceControllerGetDevicePropertyStatus : int32_t
    {
        Success = 0,
        UnknownFailure = 1,
        BufferTooSmall = 2,
        NotSupported = 3,
        DeviceNotAvailable = 4,
        MaxPropertyValueSizeTooSmall = 5,
        MaxPropertyValueSizeRequired = 6,
    };
    enum class VideoDeviceControllerSetDevicePropertyStatus : int32_t
    {
        Success = 0,
        UnknownFailure = 1,
        NotSupported = 2,
        InvalidValue = 3,
        DeviceNotAvailable = 4,
        NotInControl = 5,
    };
    enum class VideoTemporalDenoisingMode : int32_t
    {
        Off = 0,
        On = 1,
        Auto = 2,
    };
    enum class ZoomTransitionMode : int32_t
    {
        Auto = 0,
        Direct = 1,
        Smooth = 2,
    };
    struct IAdvancedPhotoCaptureSettings;
    struct IAdvancedPhotoControl;
    struct IAdvancedVideoCaptureDeviceController;
    struct IAdvancedVideoCaptureDeviceController10;
    struct IAdvancedVideoCaptureDeviceController11;
    struct IAdvancedVideoCaptureDeviceController2;
    struct IAdvancedVideoCaptureDeviceController3;
    struct IAdvancedVideoCaptureDeviceController4;
    struct IAdvancedVideoCaptureDeviceController5;
    struct IAdvancedVideoCaptureDeviceController6;
    struct IAdvancedVideoCaptureDeviceController7;
    struct IAdvancedVideoCaptureDeviceController8;
    struct IAdvancedVideoCaptureDeviceController9;
    struct IAudioDeviceController;
    struct IAudioDeviceModule;
    struct IAudioDeviceModuleNotificationEventArgs;
    struct IAudioDeviceModulesManager;
    struct IAudioDeviceModulesManagerFactory;
    struct ICallControl;
    struct ICallControlStatics;
    struct ICameraOcclusionInfo;
    struct ICameraOcclusionState;
    struct ICameraOcclusionStateChangedEventArgs;
    struct IDefaultAudioDeviceChangedEventArgs;
    struct IDialRequestedEventArgs;
    struct IDigitalWindowBounds;
    struct IDigitalWindowCapability;
    struct IDigitalWindowControl;
    struct IExposureCompensationControl;
    struct IExposureControl;
    struct IExposurePriorityVideoControl;
    struct IFlashControl;
    struct IFlashControl2;
    struct IFocusControl;
    struct IFocusControl2;
    struct IFocusSettings;
    struct IHdrVideoControl;
    struct IInfraredTorchControl;
    struct IIsoSpeedControl;
    struct IIsoSpeedControl2;
    struct IKeypadPressedEventArgs;
    struct ILowLagPhotoControl;
    struct ILowLagPhotoSequenceControl;
    struct IMediaDeviceControl;
    struct IMediaDeviceControlCapabilities;
    struct IMediaDeviceController;
    struct IMediaDeviceStatics;
    struct IModuleCommandResult;
    struct IOpticalImageStabilizationControl;
    struct IPanelBasedOptimizationControl;
    struct IPhotoConfirmationControl;
    struct IRedialRequestedEventArgs;
    struct IRegionOfInterest;
    struct IRegionOfInterest2;
    struct IRegionsOfInterestControl;
    struct ISceneModeControl;
    struct ITorchControl;
    struct IVideoDeviceController;
    struct IVideoDeviceControllerGetDevicePropertyResult;
    struct IVideoTemporalDenoisingControl;
    struct IWhiteBalanceControl;
    struct IZoomControl;
    struct IZoomControl2;
    struct IZoomSettings;
    struct AdvancedPhotoCaptureSettings;
    struct AdvancedPhotoControl;
    struct AudioDeviceController;
    struct AudioDeviceModule;
    struct AudioDeviceModuleNotificationEventArgs;
    struct AudioDeviceModulesManager;
    struct CallControl;
    struct CameraOcclusionInfo;
    struct CameraOcclusionState;
    struct CameraOcclusionStateChangedEventArgs;
    struct DefaultAudioCaptureDeviceChangedEventArgs;
    struct DefaultAudioRenderDeviceChangedEventArgs;
    struct DialRequestedEventArgs;
    struct DigitalWindowBounds;
    struct DigitalWindowCapability;
    struct DigitalWindowControl;
    struct ExposureCompensationControl;
    struct ExposureControl;
    struct ExposurePriorityVideoControl;
    struct FlashControl;
    struct FocusControl;
    struct FocusSettings;
    struct HdrVideoControl;
    struct InfraredTorchControl;
    struct IsoSpeedControl;
    struct KeypadPressedEventArgs;
    struct LowLagPhotoControl;
    struct LowLagPhotoSequenceControl;
    struct MediaDevice;
    struct MediaDeviceControl;
    struct MediaDeviceControlCapabilities;
    struct ModuleCommandResult;
    struct OpticalImageStabilizationControl;
    struct PanelBasedOptimizationControl;
    struct PhotoConfirmationControl;
    struct RedialRequestedEventArgs;
    struct RegionOfInterest;
    struct RegionsOfInterestControl;
    struct SceneModeControl;
    struct TorchControl;
    struct VideoDeviceController;
    struct VideoDeviceControllerGetDevicePropertyResult;
    struct VideoTemporalDenoisingControl;
    struct WhiteBalanceControl;
    struct ZoomControl;
    struct ZoomSettings;
    struct CallControlEventHandler;
    struct DialRequestedEventHandler;
    struct KeypadPressedEventHandler;
    struct RedialRequestedEventHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedPhotoControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAudioDeviceController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAudioDeviceModule>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAudioDeviceModulesManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IAudioDeviceModulesManagerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ICallControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ICallControlStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ICameraOcclusionInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ICameraOcclusionState>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IDialRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IDigitalWindowBounds>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IDigitalWindowCapability>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IDigitalWindowControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IExposureCompensationControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IExposureControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IExposurePriorityVideoControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IFlashControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IFlashControl2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IFocusControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IFocusControl2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IFocusSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IHdrVideoControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IInfraredTorchControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IIsoSpeedControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IIsoSpeedControl2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IKeypadPressedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ILowLagPhotoControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ILowLagPhotoSequenceControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IMediaDeviceControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IMediaDeviceControlCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IMediaDeviceController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IMediaDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IModuleCommandResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IOpticalImageStabilizationControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IPanelBasedOptimizationControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IPhotoConfirmationControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IRedialRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IRegionOfInterest>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IRegionOfInterest2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IRegionsOfInterestControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ISceneModeControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::ITorchControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IVideoDeviceController>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IVideoTemporalDenoisingControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IWhiteBalanceControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IZoomControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IZoomControl2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::IZoomSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Devices::AdvancedPhotoCaptureSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AdvancedPhotoControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AudioDeviceController>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AudioDeviceModule>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AudioDeviceModuleNotificationEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AudioDeviceModulesManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::CallControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::CameraOcclusionInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::CameraOcclusionState>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::CameraOcclusionStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DialRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DigitalWindowBounds>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DigitalWindowCapability>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::DigitalWindowControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ExposureCompensationControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ExposureControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ExposurePriorityVideoControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::FlashControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::FocusControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::FocusSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::HdrVideoControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::InfraredTorchControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::IsoSpeedControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::KeypadPressedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::LowLagPhotoControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::LowLagPhotoSequenceControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::MediaDevice>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::MediaDeviceControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::MediaDeviceControlCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ModuleCommandResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::OpticalImageStabilizationControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::PanelBasedOptimizationControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::PhotoConfirmationControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::RedialRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::RegionOfInterest>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::RegionsOfInterestControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::SceneModeControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::TorchControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::VideoDeviceController>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::VideoTemporalDenoisingControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::WhiteBalanceControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ZoomControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::ZoomSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Devices::AdvancedPhotoMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::AudioDeviceRole>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::AutoFocusRange>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::CameraOcclusionKind>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::CameraStreamState>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::CaptureSceneMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::CaptureUse>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::ColorTemperaturePreset>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::DigitalWindowMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::FocusMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::FocusPreset>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::HdrVideoMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::InfraredTorchMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::IsoSpeedPreset>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::ManualFocusDistance>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::MediaCaptureFocusState>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::MediaCaptureOptimization>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::MediaCapturePauseBehavior>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::OpticalImageStabilizationMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::RegionOfInterestType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::SendCommandStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::TelephonyKey>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::VideoDeviceControllerSetDevicePropertyStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::VideoTemporalDenoisingMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::ZoomTransitionMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Devices::CallControlEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::Media::Devices::DialRequestedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::Media::Devices::KeypadPressedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::Media::Devices::RedialRequestedEventHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AdvancedPhotoCaptureSettings> = L"Windows.Media.Devices.AdvancedPhotoCaptureSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AdvancedPhotoControl> = L"Windows.Media.Devices.AdvancedPhotoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AudioDeviceController> = L"Windows.Media.Devices.AudioDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AudioDeviceModule> = L"Windows.Media.Devices.AudioDeviceModule";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AudioDeviceModuleNotificationEventArgs> = L"Windows.Media.Devices.AudioDeviceModuleNotificationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AudioDeviceModulesManager> = L"Windows.Media.Devices.AudioDeviceModulesManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CallControl> = L"Windows.Media.Devices.CallControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CameraOcclusionInfo> = L"Windows.Media.Devices.CameraOcclusionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CameraOcclusionState> = L"Windows.Media.Devices.CameraOcclusionState";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CameraOcclusionStateChangedEventArgs> = L"Windows.Media.Devices.CameraOcclusionStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> = L"Windows.Media.Devices.DefaultAudioCaptureDeviceChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> = L"Windows.Media.Devices.DefaultAudioRenderDeviceChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DialRequestedEventArgs> = L"Windows.Media.Devices.DialRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DigitalWindowBounds> = L"Windows.Media.Devices.DigitalWindowBounds";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DigitalWindowCapability> = L"Windows.Media.Devices.DigitalWindowCapability";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DigitalWindowControl> = L"Windows.Media.Devices.DigitalWindowControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ExposureCompensationControl> = L"Windows.Media.Devices.ExposureCompensationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ExposureControl> = L"Windows.Media.Devices.ExposureControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ExposurePriorityVideoControl> = L"Windows.Media.Devices.ExposurePriorityVideoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::FlashControl> = L"Windows.Media.Devices.FlashControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::FocusControl> = L"Windows.Media.Devices.FocusControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::FocusSettings> = L"Windows.Media.Devices.FocusSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::HdrVideoControl> = L"Windows.Media.Devices.HdrVideoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::InfraredTorchControl> = L"Windows.Media.Devices.InfraredTorchControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IsoSpeedControl> = L"Windows.Media.Devices.IsoSpeedControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::KeypadPressedEventArgs> = L"Windows.Media.Devices.KeypadPressedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::LowLagPhotoControl> = L"Windows.Media.Devices.LowLagPhotoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::LowLagPhotoSequenceControl> = L"Windows.Media.Devices.LowLagPhotoSequenceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaDevice> = L"Windows.Media.Devices.MediaDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaDeviceControl> = L"Windows.Media.Devices.MediaDeviceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaDeviceControlCapabilities> = L"Windows.Media.Devices.MediaDeviceControlCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ModuleCommandResult> = L"Windows.Media.Devices.ModuleCommandResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::OpticalImageStabilizationControl> = L"Windows.Media.Devices.OpticalImageStabilizationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::PanelBasedOptimizationControl> = L"Windows.Media.Devices.PanelBasedOptimizationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::PhotoConfirmationControl> = L"Windows.Media.Devices.PhotoConfirmationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::RedialRequestedEventArgs> = L"Windows.Media.Devices.RedialRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::RegionOfInterest> = L"Windows.Media.Devices.RegionOfInterest";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::RegionsOfInterestControl> = L"Windows.Media.Devices.RegionsOfInterestControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::SceneModeControl> = L"Windows.Media.Devices.SceneModeControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::TorchControl> = L"Windows.Media.Devices.TorchControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoDeviceController> = L"Windows.Media.Devices.VideoDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyResult> = L"Windows.Media.Devices.VideoDeviceControllerGetDevicePropertyResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoTemporalDenoisingControl> = L"Windows.Media.Devices.VideoTemporalDenoisingControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::WhiteBalanceControl> = L"Windows.Media.Devices.WhiteBalanceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ZoomControl> = L"Windows.Media.Devices.ZoomControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ZoomSettings> = L"Windows.Media.Devices.ZoomSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AdvancedPhotoMode> = L"Windows.Media.Devices.AdvancedPhotoMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AudioDeviceRole> = L"Windows.Media.Devices.AudioDeviceRole";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::AutoFocusRange> = L"Windows.Media.Devices.AutoFocusRange";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CameraOcclusionKind> = L"Windows.Media.Devices.CameraOcclusionKind";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CameraStreamState> = L"Windows.Media.Devices.CameraStreamState";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CaptureSceneMode> = L"Windows.Media.Devices.CaptureSceneMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CaptureUse> = L"Windows.Media.Devices.CaptureUse";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ColorTemperaturePreset> = L"Windows.Media.Devices.ColorTemperaturePreset";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DigitalWindowMode> = L"Windows.Media.Devices.DigitalWindowMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::FocusMode> = L"Windows.Media.Devices.FocusMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::FocusPreset> = L"Windows.Media.Devices.FocusPreset";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::HdrVideoMode> = L"Windows.Media.Devices.HdrVideoMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::InfraredTorchMode> = L"Windows.Media.Devices.InfraredTorchMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IsoSpeedPreset> = L"Windows.Media.Devices.IsoSpeedPreset";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ManualFocusDistance> = L"Windows.Media.Devices.ManualFocusDistance";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaCaptureFocusState> = L"Windows.Media.Devices.MediaCaptureFocusState";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaCaptureOptimization> = L"Windows.Media.Devices.MediaCaptureOptimization";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::MediaCapturePauseBehavior> = L"Windows.Media.Devices.MediaCapturePauseBehavior";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::OpticalImageStabilizationMode> = L"Windows.Media.Devices.OpticalImageStabilizationMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::RegionOfInterestType> = L"Windows.Media.Devices.RegionOfInterestType";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::SendCommandStatus> = L"Windows.Media.Devices.SendCommandStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::TelephonyKey> = L"Windows.Media.Devices.TelephonyKey";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyStatus> = L"Windows.Media.Devices.VideoDeviceControllerGetDevicePropertyStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoDeviceControllerSetDevicePropertyStatus> = L"Windows.Media.Devices.VideoDeviceControllerSetDevicePropertyStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::VideoTemporalDenoisingMode> = L"Windows.Media.Devices.VideoTemporalDenoisingMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ZoomTransitionMode> = L"Windows.Media.Devices.ZoomTransitionMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings> = L"Windows.Media.Devices.IAdvancedPhotoCaptureSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedPhotoControl> = L"Windows.Media.Devices.IAdvancedPhotoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController10";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController11";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController3";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController4";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController5";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController6";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController7";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController8";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9> = L"Windows.Media.Devices.IAdvancedVideoCaptureDeviceController9";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAudioDeviceController> = L"Windows.Media.Devices.IAudioDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAudioDeviceModule> = L"Windows.Media.Devices.IAudioDeviceModule";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs> = L"Windows.Media.Devices.IAudioDeviceModuleNotificationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAudioDeviceModulesManager> = L"Windows.Media.Devices.IAudioDeviceModulesManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IAudioDeviceModulesManagerFactory> = L"Windows.Media.Devices.IAudioDeviceModulesManagerFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ICallControl> = L"Windows.Media.Devices.ICallControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ICallControlStatics> = L"Windows.Media.Devices.ICallControlStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ICameraOcclusionInfo> = L"Windows.Media.Devices.ICameraOcclusionInfo";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ICameraOcclusionState> = L"Windows.Media.Devices.ICameraOcclusionState";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs> = L"Windows.Media.Devices.ICameraOcclusionStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs> = L"Windows.Media.Devices.IDefaultAudioDeviceChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IDialRequestedEventArgs> = L"Windows.Media.Devices.IDialRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IDigitalWindowBounds> = L"Windows.Media.Devices.IDigitalWindowBounds";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IDigitalWindowCapability> = L"Windows.Media.Devices.IDigitalWindowCapability";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IDigitalWindowControl> = L"Windows.Media.Devices.IDigitalWindowControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IExposureCompensationControl> = L"Windows.Media.Devices.IExposureCompensationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IExposureControl> = L"Windows.Media.Devices.IExposureControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IExposurePriorityVideoControl> = L"Windows.Media.Devices.IExposurePriorityVideoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IFlashControl> = L"Windows.Media.Devices.IFlashControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IFlashControl2> = L"Windows.Media.Devices.IFlashControl2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IFocusControl> = L"Windows.Media.Devices.IFocusControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IFocusControl2> = L"Windows.Media.Devices.IFocusControl2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IFocusSettings> = L"Windows.Media.Devices.IFocusSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IHdrVideoControl> = L"Windows.Media.Devices.IHdrVideoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IInfraredTorchControl> = L"Windows.Media.Devices.IInfraredTorchControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IIsoSpeedControl> = L"Windows.Media.Devices.IIsoSpeedControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IIsoSpeedControl2> = L"Windows.Media.Devices.IIsoSpeedControl2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IKeypadPressedEventArgs> = L"Windows.Media.Devices.IKeypadPressedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ILowLagPhotoControl> = L"Windows.Media.Devices.ILowLagPhotoControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ILowLagPhotoSequenceControl> = L"Windows.Media.Devices.ILowLagPhotoSequenceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IMediaDeviceControl> = L"Windows.Media.Devices.IMediaDeviceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IMediaDeviceControlCapabilities> = L"Windows.Media.Devices.IMediaDeviceControlCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IMediaDeviceController> = L"Windows.Media.Devices.IMediaDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IMediaDeviceStatics> = L"Windows.Media.Devices.IMediaDeviceStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IModuleCommandResult> = L"Windows.Media.Devices.IModuleCommandResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IOpticalImageStabilizationControl> = L"Windows.Media.Devices.IOpticalImageStabilizationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IPanelBasedOptimizationControl> = L"Windows.Media.Devices.IPanelBasedOptimizationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IPhotoConfirmationControl> = L"Windows.Media.Devices.IPhotoConfirmationControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IRedialRequestedEventArgs> = L"Windows.Media.Devices.IRedialRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IRegionOfInterest> = L"Windows.Media.Devices.IRegionOfInterest";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IRegionOfInterest2> = L"Windows.Media.Devices.IRegionOfInterest2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IRegionsOfInterestControl> = L"Windows.Media.Devices.IRegionsOfInterestControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ISceneModeControl> = L"Windows.Media.Devices.ISceneModeControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::ITorchControl> = L"Windows.Media.Devices.ITorchControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IVideoDeviceController> = L"Windows.Media.Devices.IVideoDeviceController";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult> = L"Windows.Media.Devices.IVideoDeviceControllerGetDevicePropertyResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IVideoTemporalDenoisingControl> = L"Windows.Media.Devices.IVideoTemporalDenoisingControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IWhiteBalanceControl> = L"Windows.Media.Devices.IWhiteBalanceControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IZoomControl> = L"Windows.Media.Devices.IZoomControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IZoomControl2> = L"Windows.Media.Devices.IZoomControl2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::IZoomSettings> = L"Windows.Media.Devices.IZoomSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::CallControlEventHandler> = L"Windows.Media.Devices.CallControlEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::DialRequestedEventHandler> = L"Windows.Media.Devices.DialRequestedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::KeypadPressedEventHandler> = L"Windows.Media.Devices.KeypadPressedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::Media::Devices::RedialRequestedEventHandler> = L"Windows.Media.Devices.RedialRequestedEventHandler";
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings>{ 0x08F3863A,0x0018,0x445B,{ 0x93,0xD2,0x64,0x6D,0x1C,0x5E,0xD0,0x5C } }; // 08F3863A-0018-445B-93D2-646D1C5ED05C
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedPhotoControl>{ 0xC5B15486,0x9001,0x4682,{ 0x93,0x09,0x68,0xEA,0xE0,0x08,0x0E,0xEC } }; // C5B15486-9001-4682-9309-68EAE0080EEC
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController>{ 0xDE6FF4D3,0x2B96,0x4583,{ 0x80,0xAB,0xB5,0xB0,0x1D,0xC6,0xA8,0xD7 } }; // DE6FF4D3-2B96-4583-80AB-B5B01DC6A8D7
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10>{ 0xC621B82D,0xD6F0,0x5C1B,{ 0xA3,0x88,0xA6,0xE9,0x38,0x40,0x71,0x46 } }; // C621B82D-D6F0-5C1B-A388-A6E938407146
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11>{ 0xD5B65AE2,0x3772,0x580C,{ 0xA6,0x30,0xE7,0x5D,0xE9,0x10,0x69,0x04 } }; // D5B65AE2-3772-580C-A630-E75DE9106904
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2>{ 0x8BB94F8F,0xF11A,0x43DB,{ 0xB4,0x02,0x11,0x93,0x0B,0x80,0xAE,0x56 } }; // 8BB94F8F-F11A-43DB-B402-11930B80AE56
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3>{ 0xA98B8F34,0xEE0D,0x470C,{ 0xB9,0xF0,0x42,0x29,0xC4,0xBB,0xD0,0x89 } }; // A98B8F34-EE0D-470C-B9F0-4229C4BBD089
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4>{ 0xEA9FBFAF,0xD371,0x41C3,{ 0x9A,0x17,0x82,0x4A,0x87,0xEB,0xDF,0xD2 } }; // EA9FBFAF-D371-41C3-9A17-824A87EBDFD2
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5>{ 0x33512B17,0xB9CB,0x4A23,{ 0xB8,0x75,0xF9,0xEA,0xAB,0x53,0x54,0x92 } }; // 33512B17-B9CB-4A23-B875-F9EAAB535492
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6>{ 0xB6563A53,0x68A1,0x44B7,{ 0x9F,0x89,0xB5,0xFA,0x97,0xAC,0x0C,0xBE } }; // B6563A53-68A1-44B7-9F89-B5FA97AC0CBE
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7>{ 0x8D2927F0,0xA054,0x50E7,{ 0xB7,0xDF,0x7C,0x04,0x23,0x4D,0x10,0xF0 } }; // 8D2927F0-A054-50E7-B7DF-7C04234D10F0
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8>{ 0xD843F010,0xE7FB,0x595B,{ 0x9A,0x78,0x0E,0x54,0xC4,0x53,0x2B,0x43 } }; // D843F010-E7FB-595B-9A78-0E54C4532B43
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9>{ 0x8BDCA95D,0x0255,0x51BC,{ 0xA1,0x0D,0x5A,0x16,0x9E,0xC1,0x62,0x5A } }; // 8BDCA95D-0255-51BC-A10D-5A169EC1625A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAudioDeviceController>{ 0xEDD4A388,0x79C7,0x4F7C,{ 0x90,0xE8,0xEF,0x93,0x4B,0x21,0x58,0x0A } }; // EDD4A388-79C7-4F7C-90E8-EF934B21580A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAudioDeviceModule>{ 0x86CFAC36,0x47C1,0x4B33,{ 0x98,0x52,0x87,0x73,0xEC,0x4B,0xE1,0x23 } }; // 86CFAC36-47C1-4B33-9852-8773EC4BE123
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs>{ 0xE3E3CCAF,0x224C,0x48BE,{ 0x95,0x6B,0x9A,0x13,0x13,0x4E,0x96,0xE8 } }; // E3E3CCAF-224C-48BE-956B-9A13134E96E8
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAudioDeviceModulesManager>{ 0x6AA40C4D,0x960A,0x4D1C,{ 0xB3,0x18,0x00,0x22,0x60,0x45,0x47,0xED } }; // 6AA40C4D-960A-4D1C-B318-0022604547ED
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IAudioDeviceModulesManagerFactory>{ 0x8DB03670,0xE64D,0x4773,{ 0x96,0xC0,0xBC,0x7E,0xBF,0x0E,0x06,0x3F } }; // 8DB03670-E64D-4773-96C0-BC7EBF0E063F
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ICallControl>{ 0xA520D0D6,0xAE8D,0x45DB,{ 0x80,0x11,0xCA,0x49,0xD3,0xB3,0xE5,0x78 } }; // A520D0D6-AE8D-45DB-8011-CA49D3B3E578
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ICallControlStatics>{ 0x03945AD5,0x85AB,0x40E1,{ 0xAF,0x19,0x56,0xC9,0x43,0x03,0xB0,0x19 } }; // 03945AD5-85AB-40E1-AF19-56C94303B019
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ICameraOcclusionInfo>{ 0xAF6C4AD0,0xA84D,0x5DB6,{ 0xBE,0x58,0xA5,0xDA,0x21,0xCF,0xE0,0x11 } }; // AF6C4AD0-A84D-5DB6-BE58-A5DA21CFE011
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ICameraOcclusionState>{ 0x430ADEB8,0x6842,0x5E55,{ 0x9B,0xDE,0x04,0xB4,0xEF,0x3A,0x8A,0x57 } }; // 430ADEB8-6842-5E55-9BDE-04B4EF3A8A57
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs>{ 0x8512D848,0xC0DE,0x57CA,{ 0xA1,0xCA,0xFB,0x2C,0x3D,0x23,0xDF,0x55 } }; // 8512D848-C0DE-57CA-A1CA-FB2C3D23DF55
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs>{ 0x110F882F,0x1C05,0x4657,{ 0xA1,0x8E,0x47,0xC9,0xB6,0x9F,0x07,0xAB } }; // 110F882F-1C05-4657-A18E-47C9B69F07AB
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IDialRequestedEventArgs>{ 0x037B929E,0x953C,0x4286,{ 0x88,0x66,0x4F,0x0F,0x37,0x6C,0x85,0x5A } }; // 037B929E-953C-4286-8866-4F0F376C855A
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IDigitalWindowBounds>{ 0xDD4F21DD,0xD173,0x5C6B,{ 0x8C,0x25,0xBD,0xD2,0x6D,0x51,0x22,0xB1 } }; // DD4F21DD-D173-5C6B-8C25-BDD26D5122B1
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IDigitalWindowCapability>{ 0xD78BAD2C,0xF721,0x5244,{ 0xA1,0x96,0xB5,0x6C,0xCB,0xEC,0x60,0x6C } }; // D78BAD2C-F721-5244-A196-B56CCBEC606C
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IDigitalWindowControl>{ 0x23B69EFF,0x65D2,0x53EA,{ 0x87,0x80,0xDE,0x58,0x2B,0x48,0xB5,0x44 } }; // 23B69EFF-65D2-53EA-8780-DE582B48B544
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IExposureCompensationControl>{ 0x81C8E834,0xDCEC,0x4011,{ 0xA6,0x10,0x1F,0x38,0x47,0xE6,0x4A,0xCA } }; // 81C8E834-DCEC-4011-A610-1F3847E64ACA
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IExposureControl>{ 0x09E8CBE2,0xAD96,0x4F28,{ 0xA0,0xE0,0x96,0xED,0x7E,0x1B,0x5F,0xD2 } }; // 09E8CBE2-AD96-4F28-A0E0-96ED7E1B5FD2
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IExposurePriorityVideoControl>{ 0x2CB240A3,0x5168,0x4271,{ 0x9E,0xA5,0x47,0x62,0x1A,0x98,0xA3,0x52 } }; // 2CB240A3-5168-4271-9EA5-47621A98A352
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IFlashControl>{ 0xDEF41DBE,0x7D68,0x45E3,{ 0x8C,0x0F,0xBE,0x7B,0xB3,0x28,0x37,0xD0 } }; // DEF41DBE-7D68-45E3-8C0F-BE7BB32837D0
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IFlashControl2>{ 0x7D29CC9E,0x75E1,0x4AF7,{ 0xBD,0x7D,0x4E,0x38,0xE1,0xC0,0x6C,0xD6 } }; // 7D29CC9E-75E1-4AF7-BD7D-4E38E1C06CD6
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IFocusControl>{ 0xC0D889F6,0x5228,0x4453,{ 0xB1,0x53,0x85,0x60,0x65,0x92,0xB2,0x38 } }; // C0D889F6-5228-4453-B153-85606592B238
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IFocusControl2>{ 0x3F7CFF48,0xC534,0x4E9E,{ 0x94,0xC3,0x52,0xEF,0x2A,0xFD,0x5D,0x07 } }; // 3F7CFF48-C534-4E9E-94C3-52EF2AFD5D07
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IFocusSettings>{ 0x79958F6B,0x3263,0x4275,{ 0x85,0xD6,0xAE,0xAE,0x89,0x1C,0x96,0xEE } }; // 79958F6B-3263-4275-85D6-AEAE891C96EE
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IHdrVideoControl>{ 0x55D8E2D0,0x30C0,0x43BF,{ 0x9B,0x9A,0x97,0x99,0xD7,0x0C,0xED,0x94 } }; // 55D8E2D0-30C0-43BF-9B9A-9799D70CED94
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IInfraredTorchControl>{ 0x1CBA2C83,0x6CB6,0x5A04,{ 0xA6,0xFC,0x3B,0xE7,0xB3,0x3F,0xF0,0x56 } }; // 1CBA2C83-6CB6-5A04-A6FC-3BE7B33FF056
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IIsoSpeedControl>{ 0x27B6C322,0x25AD,0x4F1B,{ 0xAA,0xAB,0x52,0x4A,0xB3,0x76,0xCA,0x33 } }; // 27B6C322-25AD-4F1B-AAAB-524AB376CA33
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IIsoSpeedControl2>{ 0x6F1578F2,0x6D77,0x4F8A,{ 0x8C,0x2F,0x61,0x30,0xB6,0x39,0x50,0x53 } }; // 6F1578F2-6D77-4F8A-8C2F-6130B6395053
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IKeypadPressedEventArgs>{ 0xD3A43900,0xB4FA,0x49CD,{ 0x94,0x42,0x89,0xAF,0x65,0x68,0xF6,0x01 } }; // D3A43900-B4FA-49CD-9442-89AF6568F601
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ILowLagPhotoControl>{ 0x6D5C4DD0,0xFADF,0x415D,{ 0xAE,0xE6,0x3B,0xAA,0x52,0x93,0x00,0xC9 } }; // 6D5C4DD0-FADF-415D-AEE6-3BAA529300C9
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ILowLagPhotoSequenceControl>{ 0x3DCF909D,0x6D16,0x409C,{ 0xBA,0xFE,0xB9,0xA5,0x94,0xC6,0xFD,0xE6 } }; // 3DCF909D-6D16-409C-BAFE-B9A594C6FDE6
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IMediaDeviceControl>{ 0xEFA8DFA9,0x6F75,0x4863,{ 0xBA,0x0B,0x58,0x3F,0x30,0x36,0xB4,0xDE } }; // EFA8DFA9-6F75-4863-BA0B-583F3036B4DE
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IMediaDeviceControlCapabilities>{ 0x23005816,0xEB85,0x43E2,{ 0xB9,0x2B,0x82,0x40,0xD5,0xEE,0x70,0xEC } }; // 23005816-EB85-43E2-B92B-8240D5EE70EC
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IMediaDeviceController>{ 0xF6F8F5CE,0x209A,0x48FB,{ 0x86,0xFC,0xD4,0x45,0x78,0xF3,0x17,0xE6 } }; // F6F8F5CE-209A-48FB-86FC-D44578F317E6
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IMediaDeviceStatics>{ 0xAA2D9A40,0x909F,0x4BBA,{ 0xBF,0x8B,0x0C,0x0D,0x29,0x6F,0x14,0xF0 } }; // AA2D9A40-909F-4BBA-BF8B-0C0D296F14F0
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IModuleCommandResult>{ 0x520D1EB4,0x1374,0x4C7D,{ 0xB1,0xE4,0x39,0xDC,0xDF,0x3E,0xAE,0x4E } }; // 520D1EB4-1374-4C7D-B1E4-39DCDF3EAE4E
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IOpticalImageStabilizationControl>{ 0xBFAD9C1D,0x00BC,0x423B,{ 0x8E,0xB2,0xA0,0x17,0x8C,0xA9,0x42,0x47 } }; // BFAD9C1D-00BC-423B-8EB2-A0178CA94247
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IPanelBasedOptimizationControl>{ 0x33323223,0x6247,0x5419,{ 0xA5,0xA4,0x3D,0x80,0x86,0x45,0xD9,0x17 } }; // 33323223-6247-5419-A5A4-3D808645D917
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IPhotoConfirmationControl>{ 0xC8F3F363,0xFF5E,0x4582,{ 0xA9,0xA8,0x05,0x50,0xF8,0x5A,0x4A,0x76 } }; // C8F3F363-FF5E-4582-A9A8-0550F85A4A76
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IRedialRequestedEventArgs>{ 0x7EB55209,0x76AB,0x4C31,{ 0xB4,0x0E,0x4B,0x58,0x37,0x9D,0x58,0x0C } }; // 7EB55209-76AB-4C31-B40E-4B58379D580C
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IRegionOfInterest>{ 0xE5ECC834,0xCE66,0x4E05,{ 0xA7,0x8F,0xCF,0x39,0x1A,0x5E,0xC2,0xD1 } }; // E5ECC834-CE66-4E05-A78F-CF391A5EC2D1
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IRegionOfInterest2>{ 0x19FE2A91,0x73AA,0x4D51,{ 0x8A,0x9D,0x56,0xCC,0xF7,0xDB,0x7F,0x54 } }; // 19FE2A91-73AA-4D51-8A9D-56CCF7DB7F54
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IRegionsOfInterestControl>{ 0xC323F527,0xAB0B,0x4558,{ 0x8B,0x5B,0xDF,0x56,0x93,0xDB,0x03,0x78 } }; // C323F527-AB0B-4558-8B5B-DF5693DB0378
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ISceneModeControl>{ 0xD48E5AF7,0x8D59,0x4854,{ 0x8C,0x62,0x12,0xC7,0x0B,0xA8,0x9B,0x7C } }; // D48E5AF7-8D59-4854-8C62-12C70BA89B7C
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::ITorchControl>{ 0xA6053665,0x8250,0x416C,{ 0x91,0x9A,0x72,0x42,0x96,0xAF,0xA3,0x06 } }; // A6053665-8250-416C-919A-724296AFA306
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IVideoDeviceController>{ 0x99555575,0x2E2E,0x40B8,{ 0xB6,0xC7,0xF8,0x2D,0x10,0x01,0x32,0x10 } }; // 99555575-2E2E-40B8-B6C7-F82D10013210
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult>{ 0xC5D88395,0x6ED5,0x4790,{ 0x8B,0x5D,0x0E,0xF1,0x39,0x35,0xD0,0xF8 } }; // C5D88395-6ED5-4790-8B5D-0EF13935D0F8
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IVideoTemporalDenoisingControl>{ 0x7AB34735,0x3E2A,0x4A32,{ 0xBA,0xFF,0x43,0x58,0xC4,0xFB,0xDD,0x57 } }; // 7AB34735-3E2A-4A32-BAFF-4358C4FBDD57
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IWhiteBalanceControl>{ 0x781F047E,0x7162,0x49C8,{ 0xA8,0xF9,0x94,0x81,0xC5,0x65,0x36,0x3E } }; // 781F047E-7162-49C8-A8F9-9481C565363E
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IZoomControl>{ 0x3A1E0B12,0x32DA,0x4C17,{ 0xBF,0xD7,0x8D,0x0C,0x73,0xC8,0xF5,0xA5 } }; // 3A1E0B12-32DA-4C17-BFD7-8D0C73C8F5A5
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IZoomControl2>{ 0x69843DB0,0x2E99,0x4641,{ 0x85,0x29,0x18,0x4F,0x31,0x9D,0x16,0x71 } }; // 69843DB0-2E99-4641-8529-184F319D1671
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::IZoomSettings>{ 0x6AD66B24,0x14B4,0x4BFD,{ 0xB1,0x8F,0x88,0xFE,0x24,0x46,0x3B,0x52 } }; // 6AD66B24-14B4-4BFD-B18F-88FE24463B52
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::CallControlEventHandler>{ 0x596F759F,0x50DF,0x4454,{ 0xBC,0x63,0x4D,0x3D,0x01,0xB6,0x19,0x58 } }; // 596F759F-50DF-4454-BC63-4D3D01B61958
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::DialRequestedEventHandler>{ 0x5ABBFFDB,0xC21F,0x4BC4,{ 0x89,0x1B,0x25,0x7E,0x28,0xC1,0xB1,0xA4 } }; // 5ABBFFDB-C21F-4BC4-891B-257E28C1B1A4
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::KeypadPressedEventHandler>{ 0xE637A454,0xC527,0x422C,{ 0x89,0x26,0xC9,0xAF,0x83,0xB5,0x59,0xA0 } }; // E637A454-C527-422C-8926-C9AF83B559A0
    template <> inline constexpr guid guid_v<llm:OS::Media::Devices::RedialRequestedEventHandler>{ 0xBAF257D1,0x4EBD,0x4B84,{ 0x9F,0x47,0x6E,0xC4,0x3D,0x75,0xD8,0xB1 } }; // BAF257D1-4EBD-4B84-9F47-6EC43D75D8B1
    template <> struct default_interface<llm:OS::Media::Devices::AdvancedPhotoCaptureSettings>{ using type = llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings; };
    template <> struct default_interface<llm:OS::Media::Devices::AdvancedPhotoControl>{ using type = llm:OS::Media::Devices::IAdvancedPhotoControl; };
    template <> struct default_interface<llm:OS::Media::Devices::AudioDeviceController>{ using type = llm:OS::Media::Devices::IAudioDeviceController; };
    template <> struct default_interface<llm:OS::Media::Devices::AudioDeviceModule>{ using type = llm:OS::Media::Devices::IAudioDeviceModule; };
    template <> struct default_interface<llm:OS::Media::Devices::AudioDeviceModuleNotificationEventArgs>{ using type = llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::AudioDeviceModulesManager>{ using type = llm:OS::Media::Devices::IAudioDeviceModulesManager; };
    template <> struct default_interface<llm:OS::Media::Devices::CallControl>{ using type = llm:OS::Media::Devices::ICallControl; };
    template <> struct default_interface<llm:OS::Media::Devices::CameraOcclusionInfo>{ using type = llm:OS::Media::Devices::ICameraOcclusionInfo; };
    template <> struct default_interface<llm:OS::Media::Devices::CameraOcclusionState>{ using type = llm:OS::Media::Devices::ICameraOcclusionState; };
    template <> struct default_interface<llm:OS::Media::Devices::CameraOcclusionStateChangedEventArgs>{ using type = llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs>{ using type = llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs>{ using type = llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::DialRequestedEventArgs>{ using type = llm:OS::Media::Devices::IDialRequestedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::DigitalWindowBounds>{ using type = llm:OS::Media::Devices::IDigitalWindowBounds; };
    template <> struct default_interface<llm:OS::Media::Devices::DigitalWindowCapability>{ using type = llm:OS::Media::Devices::IDigitalWindowCapability; };
    template <> struct default_interface<llm:OS::Media::Devices::DigitalWindowControl>{ using type = llm:OS::Media::Devices::IDigitalWindowControl; };
    template <> struct default_interface<llm:OS::Media::Devices::ExposureCompensationControl>{ using type = llm:OS::Media::Devices::IExposureCompensationControl; };
    template <> struct default_interface<llm:OS::Media::Devices::ExposureControl>{ using type = llm:OS::Media::Devices::IExposureControl; };
    template <> struct default_interface<llm:OS::Media::Devices::ExposurePriorityVideoControl>{ using type = llm:OS::Media::Devices::IExposurePriorityVideoControl; };
    template <> struct default_interface<llm:OS::Media::Devices::FlashControl>{ using type = llm:OS::Media::Devices::IFlashControl; };
    template <> struct default_interface<llm:OS::Media::Devices::FocusControl>{ using type = llm:OS::Media::Devices::IFocusControl; };
    template <> struct default_interface<llm:OS::Media::Devices::FocusSettings>{ using type = llm:OS::Media::Devices::IFocusSettings; };
    template <> struct default_interface<llm:OS::Media::Devices::HdrVideoControl>{ using type = llm:OS::Media::Devices::IHdrVideoControl; };
    template <> struct default_interface<llm:OS::Media::Devices::InfraredTorchControl>{ using type = llm:OS::Media::Devices::IInfraredTorchControl; };
    template <> struct default_interface<llm:OS::Media::Devices::IsoSpeedControl>{ using type = llm:OS::Media::Devices::IIsoSpeedControl; };
    template <> struct default_interface<llm:OS::Media::Devices::KeypadPressedEventArgs>{ using type = llm:OS::Media::Devices::IKeypadPressedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::LowLagPhotoControl>{ using type = llm:OS::Media::Devices::ILowLagPhotoControl; };
    template <> struct default_interface<llm:OS::Media::Devices::LowLagPhotoSequenceControl>{ using type = llm:OS::Media::Devices::ILowLagPhotoSequenceControl; };
    template <> struct default_interface<llm:OS::Media::Devices::MediaDeviceControl>{ using type = llm:OS::Media::Devices::IMediaDeviceControl; };
    template <> struct default_interface<llm:OS::Media::Devices::MediaDeviceControlCapabilities>{ using type = llm:OS::Media::Devices::IMediaDeviceControlCapabilities; };
    template <> struct default_interface<llm:OS::Media::Devices::ModuleCommandResult>{ using type = llm:OS::Media::Devices::IModuleCommandResult; };
    template <> struct default_interface<llm:OS::Media::Devices::OpticalImageStabilizationControl>{ using type = llm:OS::Media::Devices::IOpticalImageStabilizationControl; };
    template <> struct default_interface<llm:OS::Media::Devices::PanelBasedOptimizationControl>{ using type = llm:OS::Media::Devices::IPanelBasedOptimizationControl; };
    template <> struct default_interface<llm:OS::Media::Devices::PhotoConfirmationControl>{ using type = llm:OS::Media::Devices::IPhotoConfirmationControl; };
    template <> struct default_interface<llm:OS::Media::Devices::RedialRequestedEventArgs>{ using type = llm:OS::Media::Devices::IRedialRequestedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Devices::RegionOfInterest>{ using type = llm:OS::Media::Devices::IRegionOfInterest; };
    template <> struct default_interface<llm:OS::Media::Devices::RegionsOfInterestControl>{ using type = llm:OS::Media::Devices::IRegionsOfInterestControl; };
    template <> struct default_interface<llm:OS::Media::Devices::SceneModeControl>{ using type = llm:OS::Media::Devices::ISceneModeControl; };
    template <> struct default_interface<llm:OS::Media::Devices::TorchControl>{ using type = llm:OS::Media::Devices::ITorchControl; };
    template <> struct default_interface<llm:OS::Media::Devices::VideoDeviceController>{ using type = llm:OS::Media::Devices::IVideoDeviceController; };
    template <> struct default_interface<llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyResult>{ using type = llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult; };
    template <> struct default_interface<llm:OS::Media::Devices::VideoTemporalDenoisingControl>{ using type = llm:OS::Media::Devices::IVideoTemporalDenoisingControl; };
    template <> struct default_interface<llm:OS::Media::Devices::WhiteBalanceControl>{ using type = llm:OS::Media::Devices::IWhiteBalanceControl; };
    template <> struct default_interface<llm:OS::Media::Devices::ZoomControl>{ using type = llm:OS::Media::Devices::IZoomControl; };
    template <> struct default_interface<llm:OS::Media::Devices::ZoomSettings>{ using type = llm:OS::Media::Devices::IZoomSettings; };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedPhotoControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Configure(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetDeviceProperty(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetDeviceProperty(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CameraOcclusionInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryAcquireExclusiveControl(void*, int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LowLagPhotoSequence(void**) noexcept = 0;
            virtual int32_t __stdcall get_LowLagPhoto(void**) noexcept = 0;
            virtual int32_t __stdcall get_SceneModeControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_TorchControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_FlashControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_WhiteBalanceControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExposureControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_FocusControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExposureCompensationControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsoSpeedControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_RegionsOfInterestControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrimaryUse(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PrimaryUse(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_VariablePhotoSequenceController(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotoConfirmationControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_ZoomControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExposurePriorityVideoControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_DesiredOptimization(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredOptimization(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_HdrVideoControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_OpticalImageStabilizationControl(void**) noexcept = 0;
            virtual int32_t __stdcall get_AdvancedPhotoControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall GetDevicePropertyById(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetDevicePropertyById(void*, void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetDevicePropertyByExtendedId(uint32_t, uint8_t*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetDevicePropertyByExtendedId(uint32_t, uint8_t*, uint32_t, uint8_t*, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_VideoTemporalDenoisingControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InfraredTorchControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PanelBasedOptimizationControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DigitalWindowControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAudioDeviceController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Muted(bool) noexcept = 0;
            virtual int32_t __stdcall get_Muted(bool*) noexcept = 0;
            virtual int32_t __stdcall put_VolumePercent(float) noexcept = 0;
            virtual int32_t __stdcall get_VolumePercent(float*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAudioDeviceModule>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ClassId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstanceId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MajorVersion(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinorVersion(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SendCommandAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Module(void**) noexcept = 0;
            virtual int32_t __stdcall get_NotificationData(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAudioDeviceModulesManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ModuleNotificationReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ModuleNotificationReceived(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall FindAllById(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAll(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IAudioDeviceModulesManagerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ICallControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IndicateNewIncomingCall(bool, void*, uint64_t*) noexcept = 0;
            virtual int32_t __stdcall IndicateNewOutgoingCall(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall IndicateActiveCall(uint64_t) noexcept = 0;
            virtual int32_t __stdcall EndCall(uint64_t) noexcept = 0;
            virtual int32_t __stdcall get_HasRinger(bool*) noexcept = 0;
            virtual int32_t __stdcall add_AnswerRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AnswerRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_HangUpRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HangUpRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DialRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DialRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RedialRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RedialRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_KeypadPressed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_KeypadPressed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AudioTransferRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AudioTransferRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ICallControlStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall FromId(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ICameraOcclusionInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetState(void**) noexcept = 0;
            virtual int32_t __stdcall IsOcclusionKindSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall add_StateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StateChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ICameraOcclusionState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsOccluded(bool*) noexcept = 0;
            virtual int32_t __stdcall IsOcclusionKind(int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Role(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IDialRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Handled() noexcept = 0;
            virtual int32_t __stdcall get_Contact(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IDigitalWindowBounds>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NormalizedOriginTop(double*) noexcept = 0;
            virtual int32_t __stdcall put_NormalizedOriginTop(double) noexcept = 0;
            virtual int32_t __stdcall get_NormalizedOriginLeft(double*) noexcept = 0;
            virtual int32_t __stdcall put_NormalizedOriginLeft(double) noexcept = 0;
            virtual int32_t __stdcall get_Scale(double*) noexcept = 0;
            virtual int32_t __stdcall put_Scale(double) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IDigitalWindowCapability>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Width(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Height(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MinScaleValue(double*) noexcept = 0;
            virtual int32_t __stdcall get_MaxScaleValue(double*) noexcept = 0;
            virtual int32_t __stdcall get_MinScaleValueWithoutUpsampling(double*) noexcept = 0;
            virtual int32_t __stdcall get_NormalizedFieldOfViewLimit(llm:OS::Foundation::Rect*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IDigitalWindowControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(uint32_t* __valueSize, int32_t**) noexcept = 0;
            virtual int32_t __stdcall get_CurrentMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetBounds(void**) noexcept = 0;
            virtual int32_t __stdcall Configure(int32_t) noexcept = 0;
            virtual int32_t __stdcall ConfigureWithBounds(int32_t, void*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedCapabilities(void**) noexcept = 0;
            virtual int32_t __stdcall GetCapabilityForSize(int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IExposureCompensationControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(float*) noexcept = 0;
            virtual int32_t __stdcall get_Max(float*) noexcept = 0;
            virtual int32_t __stdcall get_Step(float*) noexcept = 0;
            virtual int32_t __stdcall get_Value(float*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(float, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IExposureControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall SetAutoAsync(bool, void**) noexcept = 0;
            virtual int32_t __stdcall get_Min(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(int64_t*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(int64_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IExposurePriorityVideoControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Enabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Enabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IFlashControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_PowerSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_RedEyeReductionSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Enabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Enabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Auto(bool) noexcept = 0;
            virtual int32_t __stdcall get_RedEyeReduction(bool*) noexcept = 0;
            virtual int32_t __stdcall put_RedEyeReduction(bool) noexcept = 0;
            virtual int32_t __stdcall get_PowerPercent(float*) noexcept = 0;
            virtual int32_t __stdcall put_PowerPercent(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IFlashControl2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AssistantLightSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AssistantLightEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AssistantLightEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IFocusControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedPresets(void**) noexcept = 0;
            virtual int32_t __stdcall get_Preset(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetPresetAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SetPresetWithCompletionOptionAsync(int32_t, bool, void**) noexcept = 0;
            virtual int32_t __stdcall get_Min(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall FocusAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IFocusControl2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FocusChangedSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_WaitForFocusSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedFocusModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedFocusDistances(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedFocusRanges(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FocusState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall UnlockAsync(void**) noexcept = 0;
            virtual int32_t __stdcall LockAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Configure(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IFocusSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_AutoFocusRange(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AutoFocusRange(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
            virtual int32_t __stdcall get_Distance(void**) noexcept = 0;
            virtual int32_t __stdcall put_Distance(void*) noexcept = 0;
            virtual int32_t __stdcall get_WaitForFocus(bool*) noexcept = 0;
            virtual int32_t __stdcall put_WaitForFocus(bool) noexcept = 0;
            virtual int32_t __stdcall get_DisableDriverFallback(bool*) noexcept = 0;
            virtual int32_t __stdcall put_DisableDriverFallback(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IHdrVideoControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IInfraredTorchControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_CurrentMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CurrentMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_MinPower(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPower(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PowerStep(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Power(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Power(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IIsoSpeedControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedPresets(void**) noexcept = 0;
            virtual int32_t __stdcall get_Preset(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetPresetAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IIsoSpeedControl2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Min(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_Auto(bool*) noexcept = 0;
            virtual int32_t __stdcall SetAutoAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IKeypadPressedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TelephonyKey(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ILowLagPhotoControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetHighestConcurrentFrameRate(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentFrameRate(void**) noexcept = 0;
            virtual int32_t __stdcall get_ThumbnailEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ThumbnailEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_ThumbnailFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ThumbnailFormat(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DesiredThumbnailSize(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredThumbnailSize(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_HardwareAcceleratedThumbnailSupported(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ILowLagPhotoSequenceControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPastPhotos(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPhotosPerSecond(float*) noexcept = 0;
            virtual int32_t __stdcall get_PastPhotoLimit(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PastPhotoLimit(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_PhotosPerSecondLimit(float*) noexcept = 0;
            virtual int32_t __stdcall put_PhotosPerSecondLimit(float) noexcept = 0;
            virtual int32_t __stdcall GetHighestConcurrentFrameRate(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentFrameRate(void**) noexcept = 0;
            virtual int32_t __stdcall get_ThumbnailEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ThumbnailEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_ThumbnailFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ThumbnailFormat(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DesiredThumbnailSize(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredThumbnailSize(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_HardwareAcceleratedThumbnailSupported(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IMediaDeviceControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Capabilities(void**) noexcept = 0;
            virtual int32_t __stdcall TryGetValue(double*, bool*) noexcept = 0;
            virtual int32_t __stdcall TrySetValue(double, bool*) noexcept = 0;
            virtual int32_t __stdcall TryGetAuto(bool*, bool*) noexcept = 0;
            virtual int32_t __stdcall TrySetAuto(bool, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IMediaDeviceControlCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(double*) noexcept = 0;
            virtual int32_t __stdcall get_Max(double*) noexcept = 0;
            virtual int32_t __stdcall get_Step(double*) noexcept = 0;
            virtual int32_t __stdcall get_Default(double*) noexcept = 0;
            virtual int32_t __stdcall get_AutoModeSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IMediaDeviceController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAvailableMediaStreamProperties(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetMediaStreamProperties(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SetMediaStreamPropertiesAsync(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IMediaDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAudioCaptureSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioRenderSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetVideoCaptureSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetDefaultAudioCaptureId(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetDefaultAudioRenderId(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall add_DefaultAudioCaptureDeviceChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DefaultAudioCaptureDeviceChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_DefaultAudioRenderDeviceChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_DefaultAudioRenderDeviceChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IModuleCommandResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Result(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IOpticalImageStabilizationControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IPanelBasedOptimizationControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Panel(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Panel(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IPhotoConfirmationControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Enabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Enabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_PixelFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PixelFormat(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IRedialRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Handled() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IRegionOfInterest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AutoFocusEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoFocusEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_AutoWhiteBalanceEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoWhiteBalanceEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_AutoExposureEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoExposureEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_Bounds(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall put_Bounds(llm:OS::Foundation::Rect) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IRegionOfInterest2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Type(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_BoundsNormalized(bool*) noexcept = 0;
            virtual int32_t __stdcall put_BoundsNormalized(bool) noexcept = 0;
            virtual int32_t __stdcall get_Weight(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Weight(uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IRegionsOfInterestControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxRegions(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SetRegionsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetRegionsWithLockAsync(void*, bool, void**) noexcept = 0;
            virtual int32_t __stdcall ClearRegionsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_AutoFocusSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AutoWhiteBalanceSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AutoExposureSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ISceneModeControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::ITorchControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_PowerSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Enabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Enabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_PowerPercent(float*) noexcept = 0;
            virtual int32_t __stdcall put_PowerPercent(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IVideoDeviceController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Brightness(void**) noexcept = 0;
            virtual int32_t __stdcall get_Contrast(void**) noexcept = 0;
            virtual int32_t __stdcall get_Hue(void**) noexcept = 0;
            virtual int32_t __stdcall get_WhiteBalance(void**) noexcept = 0;
            virtual int32_t __stdcall get_BacklightCompensation(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pan(void**) noexcept = 0;
            virtual int32_t __stdcall get_Tilt(void**) noexcept = 0;
            virtual int32_t __stdcall get_Zoom(void**) noexcept = 0;
            virtual int32_t __stdcall get_Roll(void**) noexcept = 0;
            virtual int32_t __stdcall get_Exposure(void**) noexcept = 0;
            virtual int32_t __stdcall get_Focus(void**) noexcept = 0;
            virtual int32_t __stdcall TrySetPowerlineFrequency(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall TryGetPowerlineFrequency(int32_t*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IVideoTemporalDenoisingControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IWhiteBalanceControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Preset(int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetPresetAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_Min(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Max(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Step(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SetValueAsync(uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IZoomControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Supported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Min(float*) noexcept = 0;
            virtual int32_t __stdcall get_Max(float*) noexcept = 0;
            virtual int32_t __stdcall get_Step(float*) noexcept = 0;
            virtual int32_t __stdcall get_Value(float*) noexcept = 0;
            virtual int32_t __stdcall put_Value(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IZoomControl2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportedModes(void**) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall Configure(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::IZoomSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Value(float*) noexcept = 0;
            virtual int32_t __stdcall put_Value(float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::CallControlEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::DialRequestedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::KeypadPressedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Devices::RedialRequestedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedPhotoCaptureSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AdvancedPhotoMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::AdvancedPhotoMode const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedPhotoCaptureSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedPhotoControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::AdvancedPhotoMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AdvancedPhotoMode) Mode() const;
        LLM_IMPL_AUTO(void) Configure(llm:OS::Media::Devices::AdvancedPhotoCaptureSettings const& settings) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedPhotoControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedPhotoControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController
    {
        LLM_IMPL_AUTO(void) SetDeviceProperty(param::hstring const& propertyId, llm:OS::Foundation::IInspectable const& propertyValue) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) GetDeviceProperty(param::hstring const& propertyId) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController10
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::CameraOcclusionInfo) CameraOcclusionInfo() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController10<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController11
    {
        LLM_IMPL_AUTO(bool) TryAcquireExclusiveControl(param::hstring const& deviceId, llm:OS::Media::Capture::MediaCaptureDeviceExclusiveControlReleaseMode const& mode) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController11<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::LowLagPhotoSequenceControl) LowLagPhotoSequence() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::LowLagPhotoControl) LowLagPhoto() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::SceneModeControl) SceneModeControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::TorchControl) TorchControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::FlashControl) FlashControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::WhiteBalanceControl) WhiteBalanceControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ExposureControl) ExposureControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::FocusControl) FocusControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ExposureCompensationControl) ExposureCompensationControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::IsoSpeedControl) IsoSpeedControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::RegionsOfInterestControl) RegionsOfInterestControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::CaptureUse) PrimaryUse() const;
        LLM_IMPL_AUTO(void) PrimaryUse(llm:OS::Media::Devices::CaptureUse const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::Core::VariablePhotoSequenceController) VariablePhotoSequenceController() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::PhotoConfirmationControl) PhotoConfirmationControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ZoomControl) ZoomControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController3<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController4
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ExposurePriorityVideoControl) ExposurePriorityVideoControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaCaptureOptimization) DesiredOptimization() const;
        LLM_IMPL_AUTO(void) DesiredOptimization(llm:OS::Media::Devices::MediaCaptureOptimization const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::HdrVideoControl) HdrVideoControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::OpticalImageStabilizationControl) OpticalImageStabilizationControl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AdvancedPhotoControl) AdvancedPhotoControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController4<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController5
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyResult) GetDevicePropertyById(param::hstring const& propertyId, llm:OS::Foundation::IReference<uint32_t> const& maxPropertyValueSize) const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoDeviceControllerSetDevicePropertyStatus) SetDevicePropertyById(param::hstring const& propertyId, llm:OS::Foundation::IInspectable const& propertyValue) const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyResult) GetDevicePropertyByExtendedId(array_view<uint8_t const> extendedPropertyId, llm:OS::Foundation::IReference<uint32_t> const& maxPropertyValueSize) const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoDeviceControllerSetDevicePropertyStatus) SetDevicePropertyByExtendedId(array_view<uint8_t const> extendedPropertyId, array_view<uint8_t const> propertyValue) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController5<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController6
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoTemporalDenoisingControl) VideoTemporalDenoisingControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController6<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController7
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::InfraredTorchControl) InfraredTorchControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController7<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController8
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::PanelBasedOptimizationControl) PanelBasedOptimizationControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController8<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController9
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::DigitalWindowControl) DigitalWindowControl() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAdvancedVideoCaptureDeviceController9<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAudioDeviceController
    {
        LLM_IMPL_AUTO(void) Muted(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Muted() const;
        LLM_IMPL_AUTO(void) VolumePercent(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) VolumePercent() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAudioDeviceController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAudioDeviceController<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAudioDeviceModule
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ClassId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) InstanceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MajorVersion() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MinorVersion() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Devices::ModuleCommandResult>) SendCommandAsync(llm:OS::Storage::Streams::IBuffer const& Command) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAudioDeviceModule>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAudioDeviceModule<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAudioDeviceModuleNotificationEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AudioDeviceModule) Module() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) NotificationData() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAudioDeviceModuleNotificationEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAudioDeviceModulesManager
    {
        LLM_IMPL_AUTO(llm::event_token) ModuleNotificationReceived(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Devices::AudioDeviceModulesManager, llm:OS::Media::Devices::AudioDeviceModuleNotificationEventArgs> const& handler) const;
        using ModuleNotificationReceived_revoker = impl::event_revoker<llm:OS::Media::Devices::IAudioDeviceModulesManager, &impl::abi_t<llm:OS::Media::Devices::IAudioDeviceModulesManager>::remove_ModuleNotificationReceived>;
        [[nodiscard]] ModuleNotificationReceived_revoker ModuleNotificationReceived(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Devices::AudioDeviceModulesManager, llm:OS::Media::Devices::AudioDeviceModuleNotificationEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ModuleNotificationReceived(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::AudioDeviceModule>) FindAllById(param::hstring const& moduleId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::AudioDeviceModule>) FindAll() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAudioDeviceModulesManager>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAudioDeviceModulesManager<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IAudioDeviceModulesManagerFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::Devices::AudioDeviceModulesManager) Create(param::hstring const& deviceId) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IAudioDeviceModulesManagerFactory>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IAudioDeviceModulesManagerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ICallControl
    {
        LLM_IMPL_AUTO(uint64_t) IndicateNewIncomingCall(bool enableRinger, param::hstring const& callerId) const;
        LLM_IMPL_AUTO(uint64_t) IndicateNewOutgoingCall() const;
        LLM_IMPL_AUTO(void) IndicateActiveCall(uint64_t callToken) const;
        LLM_IMPL_AUTO(void) EndCall(uint64_t callToken) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasRinger() const;
        LLM_IMPL_AUTO(llm::event_token) AnswerRequested(llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        using AnswerRequested_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_AnswerRequested>;
        [[nodiscard]] AnswerRequested_revoker AnswerRequested(auto_revoke_t, llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) AnswerRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) HangUpRequested(llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        using HangUpRequested_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_HangUpRequested>;
        [[nodiscard]] HangUpRequested_revoker HangUpRequested(auto_revoke_t, llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) HangUpRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DialRequested(llm:OS::Media::Devices::DialRequestedEventHandler const& handler) const;
        using DialRequested_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_DialRequested>;
        [[nodiscard]] DialRequested_revoker DialRequested(auto_revoke_t, llm:OS::Media::Devices::DialRequestedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) DialRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RedialRequested(llm:OS::Media::Devices::RedialRequestedEventHandler const& handler) const;
        using RedialRequested_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_RedialRequested>;
        [[nodiscard]] RedialRequested_revoker RedialRequested(auto_revoke_t, llm:OS::Media::Devices::RedialRequestedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) RedialRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) KeypadPressed(llm:OS::Media::Devices::KeypadPressedEventHandler const& handler) const;
        using KeypadPressed_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_KeypadPressed>;
        [[nodiscard]] KeypadPressed_revoker KeypadPressed(auto_revoke_t, llm:OS::Media::Devices::KeypadPressedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) KeypadPressed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AudioTransferRequested(llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        using AudioTransferRequested_revoker = impl::event_revoker<llm:OS::Media::Devices::ICallControl, &impl::abi_t<llm:OS::Media::Devices::ICallControl>::remove_AudioTransferRequested>;
        [[nodiscard]] AudioTransferRequested_revoker AudioTransferRequested(auto_revoke_t, llm:OS::Media::Devices::CallControlEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) AudioTransferRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Devices::ICallControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ICallControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ICallControlStatics
    {
        LLM_IMPL_AUTO(llm:OS::Media::Devices::CallControl) GetDefault() const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::CallControl) FromId(param::hstring const& deviceId) const;
    };
    template <> struct consume<llm:OS::Media::Devices::ICallControlStatics>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ICallControlStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ICameraOcclusionInfo
    {
        LLM_IMPL_AUTO(llm:OS::Media::Devices::CameraOcclusionState) GetState() const;
        LLM_IMPL_AUTO(bool) IsOcclusionKindSupported(llm:OS::Media::Devices::CameraOcclusionKind const& occlusionKind) const;
        LLM_IMPL_AUTO(llm::event_token) StateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Devices::CameraOcclusionInfo, llm:OS::Media::Devices::CameraOcclusionStateChangedEventArgs> const& handler) const;
        using StateChanged_revoker = impl::event_revoker<llm:OS::Media::Devices::ICameraOcclusionInfo, &impl::abi_t<llm:OS::Media::Devices::ICameraOcclusionInfo>::remove_StateChanged>;
        [[nodiscard]] StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Devices::CameraOcclusionInfo, llm:OS::Media::Devices::CameraOcclusionStateChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) StateChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Devices::ICameraOcclusionInfo>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ICameraOcclusionInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ICameraOcclusionState
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsOccluded() const;
        LLM_IMPL_AUTO(bool) IsOcclusionKind(llm:OS::Media::Devices::CameraOcclusionKind const& occlusionKind) const;
    };
    template <> struct consume<llm:OS::Media::Devices::ICameraOcclusionState>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ICameraOcclusionState<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ICameraOcclusionStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::CameraOcclusionState) State() const;
    };
    template <> struct consume<llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ICameraOcclusionStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IDefaultAudioDeviceChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AudioDeviceRole) Role() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IDefaultAudioDeviceChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IDialRequestedEventArgs
    {
        LLM_IMPL_AUTO(void) Handled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) Contact() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IDialRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IDialRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IDigitalWindowBounds
    {
        [[nodiscard]] LLM_IMPL_AUTO(double) NormalizedOriginTop() const;
        LLM_IMPL_AUTO(void) NormalizedOriginTop(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) NormalizedOriginLeft() const;
        LLM_IMPL_AUTO(void) NormalizedOriginLeft(double value) const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Scale() const;
        LLM_IMPL_AUTO(void) Scale(double value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IDigitalWindowBounds>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IDigitalWindowBounds<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IDigitalWindowCapability
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Width() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Height() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinScaleValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MaxScaleValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MinScaleValueWithoutUpsampling() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) NormalizedFieldOfViewLimit() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IDigitalWindowCapability>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IDigitalWindowCapability<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IDigitalWindowControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(com_array<llm:OS::Media::Devices::DigitalWindowMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::DigitalWindowMode) CurrentMode() const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::DigitalWindowBounds) GetBounds() const;
        LLM_IMPL_AUTO(void) Configure(llm:OS::Media::Devices::DigitalWindowMode const& digitalWindowMode) const;
        LLM_IMPL_AUTO(void) Configure(llm:OS::Media::Devices::DigitalWindowMode const& digitalWindowMode, llm:OS::Media::Devices::DigitalWindowBounds const& digitalWindowBounds) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::DigitalWindowCapability>) SupportedCapabilities() const;
        LLM_IMPL_AUTO(llm:OS::Media::Devices::DigitalWindowCapability) GetCapabilityForSize(int32_t width, int32_t height) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IDigitalWindowControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IDigitalWindowControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IExposureCompensationControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IExposureCompensationControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IExposureCompensationControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IExposureControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetAutoAsync(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(llm:OS::Foundation::TimeSpan const& shutterDuration) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IExposureControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IExposureControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IExposurePriorityVideoControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Enabled() const;
        LLM_IMPL_AUTO(void) Enabled(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IExposurePriorityVideoControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IExposurePriorityVideoControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IFlashControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) PowerSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RedEyeReductionSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Enabled() const;
        LLM_IMPL_AUTO(void) Enabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(void) Auto(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RedEyeReduction() const;
        LLM_IMPL_AUTO(void) RedEyeReduction(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PowerPercent() const;
        LLM_IMPL_AUTO(void) PowerPercent(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IFlashControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IFlashControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IFlashControl2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AssistantLightSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AssistantLightEnabled() const;
        LLM_IMPL_AUTO(void) AssistantLightEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IFlashControl2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IFlashControl2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IFocusControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::FocusPreset>) SupportedPresets() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::FocusPreset) Preset() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetPresetAsync(llm:OS::Media::Devices::FocusPreset const& preset) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetPresetAsync(llm:OS::Media::Devices::FocusPreset const& preset, bool completeBeforeFocus) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(uint32_t focus) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) FocusAsync() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IFocusControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IFocusControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IFocusControl2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) FocusChangedSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) WaitForFocusSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::FocusMode>) SupportedFocusModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::ManualFocusDistance>) SupportedFocusDistances() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::AutoFocusRange>) SupportedFocusRanges() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::FocusMode) Mode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaCaptureFocusState) FocusState() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UnlockAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) LockAsync() const;
        LLM_IMPL_AUTO(void) Configure(llm:OS::Media::Devices::FocusSettings const& settings) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IFocusControl2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IFocusControl2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IFocusSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::FocusMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::FocusMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::AutoFocusRange) AutoFocusRange() const;
        LLM_IMPL_AUTO(void) AutoFocusRange(llm:OS::Media::Devices::AutoFocusRange const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) Value() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Foundation::IReference<uint32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Media::Devices::ManualFocusDistance>) Distance() const;
        LLM_IMPL_AUTO(void) Distance(llm:OS::Foundation::IReference<llm:OS::Media::Devices::ManualFocusDistance> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) WaitForFocus() const;
        LLM_IMPL_AUTO(void) WaitForFocus(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) DisableDriverFallback() const;
        LLM_IMPL_AUTO(void) DisableDriverFallback(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IFocusSettings>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IFocusSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IHdrVideoControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::HdrVideoMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::HdrVideoMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::HdrVideoMode const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IHdrVideoControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IHdrVideoControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IInfraredTorchControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::InfraredTorchMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::InfraredTorchMode) CurrentMode() const;
        LLM_IMPL_AUTO(void) CurrentMode(llm:OS::Media::Devices::InfraredTorchMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinPower() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxPower() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) PowerStep() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Power() const;
        LLM_IMPL_AUTO(void) Power(int32_t value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IInfraredTorchControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IInfraredTorchControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IIsoSpeedControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::IsoSpeedPreset>) SupportedPresets() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::IsoSpeedPreset) Preset() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetPresetAsync(llm:OS::Media::Devices::IsoSpeedPreset const& preset) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IIsoSpeedControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IIsoSpeedControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IIsoSpeedControl2
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(uint32_t isoSpeed) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Auto() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetAutoAsync() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IIsoSpeedControl2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IIsoSpeedControl2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IKeypadPressedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::TelephonyKey) TelephonyKey() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IKeypadPressedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IKeypadPressedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ILowLagPhotoControl
    {
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetHighestConcurrentFrameRate(llm:OS::Media::MediaProperties::IMediaEncodingProperties const& captureProperties) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetCurrentFrameRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ThumbnailEnabled() const;
        LLM_IMPL_AUTO(void) ThumbnailEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaThumbnailFormat) ThumbnailFormat() const;
        LLM_IMPL_AUTO(void) ThumbnailFormat(llm:OS::Media::MediaProperties::MediaThumbnailFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DesiredThumbnailSize() const;
        LLM_IMPL_AUTO(void) DesiredThumbnailSize(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) HardwareAcceleratedThumbnailSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::ILowLagPhotoControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ILowLagPhotoControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ILowLagPhotoSequenceControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxPastPhotos() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) MaxPhotosPerSecond() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PastPhotoLimit() const;
        LLM_IMPL_AUTO(void) PastPhotoLimit(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PhotosPerSecondLimit() const;
        LLM_IMPL_AUTO(void) PhotosPerSecondLimit(float value) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetHighestConcurrentFrameRate(llm:OS::Media::MediaProperties::IMediaEncodingProperties const& captureProperties) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaRatio) GetCurrentFrameRate() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ThumbnailEnabled() const;
        LLM_IMPL_AUTO(void) ThumbnailEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaThumbnailFormat) ThumbnailFormat() const;
        LLM_IMPL_AUTO(void) ThumbnailFormat(llm:OS::Media::MediaProperties::MediaThumbnailFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) DesiredThumbnailSize() const;
        LLM_IMPL_AUTO(void) DesiredThumbnailSize(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) HardwareAcceleratedThumbnailSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::ILowLagPhotoSequenceControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ILowLagPhotoSequenceControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IMediaDeviceControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControlCapabilities) Capabilities() const;
        LLM_IMPL_AUTO(bool) TryGetValue(double& value) const;
        LLM_IMPL_AUTO(bool) TrySetValue(double value) const;
        LLM_IMPL_AUTO(bool) TryGetAuto(bool& value) const;
        LLM_IMPL_AUTO(bool) TrySetAuto(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IMediaDeviceControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IMediaDeviceControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IMediaDeviceControlCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Default() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoModeSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IMediaDeviceControlCapabilities>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IMediaDeviceControlCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IMediaDeviceController
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::MediaProperties::IMediaEncodingProperties>) GetAvailableMediaStreamProperties(llm:OS::Media::Capture::MediaStreamType const& mediaStreamType) const;
        LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::IMediaEncodingProperties) GetMediaStreamProperties(llm:OS::Media::Capture::MediaStreamType const& mediaStreamType) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetMediaStreamPropertiesAsync(llm:OS::Media::Capture::MediaStreamType const& mediaStreamType, llm:OS::Media::MediaProperties::IMediaEncodingProperties const& mediaEncodingProperties) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IMediaDeviceController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IMediaDeviceController<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IMediaDeviceStatics
    {
        LLM_IMPL_AUTO(hstring) GetAudioCaptureSelector() const;
        LLM_IMPL_AUTO(hstring) GetAudioRenderSelector() const;
        LLM_IMPL_AUTO(hstring) GetVideoCaptureSelector() const;
        LLM_IMPL_AUTO(hstring) GetDefaultAudioCaptureId(llm:OS::Media::Devices::AudioDeviceRole const& role) const;
        LLM_IMPL_AUTO(hstring) GetDefaultAudioRenderId(llm:OS::Media::Devices::AudioDeviceRole const& role) const;
        LLM_IMPL_AUTO(llm::event_token) DefaultAudioCaptureDeviceChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> const& handler) const;
        using DefaultAudioCaptureDeviceChanged_revoker = impl::event_revoker<llm:OS::Media::Devices::IMediaDeviceStatics, &impl::abi_t<llm:OS::Media::Devices::IMediaDeviceStatics>::remove_DefaultAudioCaptureDeviceChanged>;
        [[nodiscard]] DefaultAudioCaptureDeviceChanged_revoker DefaultAudioCaptureDeviceChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DefaultAudioCaptureDeviceChanged(llm::event_token const& cookie) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) DefaultAudioRenderDeviceChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> const& handler) const;
        using DefaultAudioRenderDeviceChanged_revoker = impl::event_revoker<llm:OS::Media::Devices::IMediaDeviceStatics, &impl::abi_t<llm:OS::Media::Devices::IMediaDeviceStatics>::remove_DefaultAudioRenderDeviceChanged>;
        [[nodiscard]] DefaultAudioRenderDeviceChanged_revoker DefaultAudioRenderDeviceChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) DefaultAudioRenderDeviceChanged(llm::event_token const& cookie) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Devices::IMediaDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IMediaDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IModuleCommandResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::SendCommandStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) Result() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IModuleCommandResult>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IModuleCommandResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IOpticalImageStabilizationControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::OpticalImageStabilizationMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::OpticalImageStabilizationMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::OpticalImageStabilizationMode const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IOpticalImageStabilizationControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IOpticalImageStabilizationControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IPanelBasedOptimizationControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Devices::Enumeration::Panel) Panel() const;
        LLM_IMPL_AUTO(void) Panel(llm:OS::Devices::Enumeration::Panel const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IPanelBasedOptimizationControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IPanelBasedOptimizationControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IPhotoConfirmationControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Enabled() const;
        LLM_IMPL_AUTO(void) Enabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::MediaProperties::MediaPixelFormat) PixelFormat() const;
        LLM_IMPL_AUTO(void) PixelFormat(llm:OS::Media::MediaProperties::MediaPixelFormat const& format) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IPhotoConfirmationControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IPhotoConfirmationControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IRedialRequestedEventArgs
    {
        LLM_IMPL_AUTO(void) Handled() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IRedialRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IRedialRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IRegionOfInterest
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoFocusEnabled() const;
        LLM_IMPL_AUTO(void) AutoFocusEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoWhiteBalanceEnabled() const;
        LLM_IMPL_AUTO(void) AutoWhiteBalanceEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoExposureEnabled() const;
        LLM_IMPL_AUTO(void) AutoExposureEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) Bounds() const;
        LLM_IMPL_AUTO(void) Bounds(llm:OS::Foundation::Rect const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IRegionOfInterest>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IRegionOfInterest<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IRegionOfInterest2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::RegionOfInterestType) Type() const;
        LLM_IMPL_AUTO(void) Type(llm:OS::Media::Devices::RegionOfInterestType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) BoundsNormalized() const;
        LLM_IMPL_AUTO(void) BoundsNormalized(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Weight() const;
        LLM_IMPL_AUTO(void) Weight(uint32_t value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IRegionOfInterest2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IRegionOfInterest2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IRegionsOfInterestControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxRegions() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetRegionsAsync(param::async_iterable<llm:OS::Media::Devices::RegionOfInterest> const& regions) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetRegionsAsync(param::async_iterable<llm:OS::Media::Devices::RegionOfInterest> const& regions, bool lockValues) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ClearRegionsAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoFocusSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoWhiteBalanceSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoExposureSupported() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IRegionsOfInterestControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IRegionsOfInterestControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ISceneModeControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::CaptureSceneMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::CaptureSceneMode) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(llm:OS::Media::Devices::CaptureSceneMode const& sceneMode) const;
    };
    template <> struct consume<llm:OS::Media::Devices::ISceneModeControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ISceneModeControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_ITorchControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) PowerSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Enabled() const;
        LLM_IMPL_AUTO(void) Enabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PowerPercent() const;
        LLM_IMPL_AUTO(void) PowerPercent(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::ITorchControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_ITorchControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IVideoDeviceController
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Brightness() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Contrast() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Hue() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) WhiteBalance() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) BacklightCompensation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Pan() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Tilt() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Zoom() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Roll() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Exposure() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::MediaDeviceControl) Focus() const;
        LLM_IMPL_AUTO(bool) TrySetPowerlineFrequency(llm:OS::Media::Capture::PowerlineFrequency const& value) const;
        LLM_IMPL_AUTO(bool) TryGetPowerlineFrequency(llm:OS::Media::Capture::PowerlineFrequency& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IVideoDeviceController>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IVideoDeviceController<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IVideoDeviceControllerGetDevicePropertyResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoDeviceControllerGetDevicePropertyStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) Value() const;
    };
    template <> struct consume<llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IVideoDeviceControllerGetDevicePropertyResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IVideoTemporalDenoisingControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::VideoTemporalDenoisingMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::VideoTemporalDenoisingMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::VideoTemporalDenoisingMode const& value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IVideoTemporalDenoisingControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IVideoTemporalDenoisingControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IWhiteBalanceControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ColorTemperaturePreset) Preset() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetPresetAsync(llm:OS::Media::Devices::ColorTemperaturePreset const& preset) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Value() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SetValueAsync(uint32_t temperature) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IWhiteBalanceControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IWhiteBalanceControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IZoomControl
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Supported() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Min() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Max() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Step() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Value() const;
        LLM_IMPL_AUTO(void) Value(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IZoomControl>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IZoomControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IZoomControl2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Devices::ZoomTransitionMode>) SupportedModes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ZoomTransitionMode) Mode() const;
        LLM_IMPL_AUTO(void) Configure(llm:OS::Media::Devices::ZoomSettings const& settings) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IZoomControl2>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IZoomControl2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Devices_IZoomSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Devices::ZoomTransitionMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Devices::ZoomTransitionMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Value() const;
        LLM_IMPL_AUTO(void) Value(float value) const;
    };
    template <> struct consume<llm:OS::Media::Devices::IZoomSettings>
    {
        template <typename D> using type = consume_Windows_Media_Devices_IZoomSettings<D>;
    };
}
#endif
