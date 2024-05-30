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
#ifndef LLM_OS_Media_Devices_2_H
#define LLM_OS_Media_Devices_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Devices.1.h"
LLM_EXPORT namespace llm:OS::Media::Devices
{
    struct CallControlEventHandler : llm:OS::Foundation::IUnknown
    {
        CallControlEventHandler(std::nullptr_t = nullptr) noexcept {}
        CallControlEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> CallControlEventHandler(L lambda);
        template <typename F> CallControlEventHandler(F* function);
        template <typename O, typename M> CallControlEventHandler(O* object, M method);
        template <typename O, typename M> CallControlEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> CallControlEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Devices::CallControl const& sender) const;
    };
    struct DialRequestedEventHandler : llm:OS::Foundation::IUnknown
    {
        DialRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DialRequestedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DialRequestedEventHandler(L lambda);
        template <typename F> DialRequestedEventHandler(F* function);
        template <typename O, typename M> DialRequestedEventHandler(O* object, M method);
        template <typename O, typename M> DialRequestedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DialRequestedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Devices::CallControl const& sender, llm:OS::Media::Devices::DialRequestedEventArgs const& e) const;
    };
    struct KeypadPressedEventHandler : llm:OS::Foundation::IUnknown
    {
        KeypadPressedEventHandler(std::nullptr_t = nullptr) noexcept {}
        KeypadPressedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> KeypadPressedEventHandler(L lambda);
        template <typename F> KeypadPressedEventHandler(F* function);
        template <typename O, typename M> KeypadPressedEventHandler(O* object, M method);
        template <typename O, typename M> KeypadPressedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> KeypadPressedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Devices::CallControl const& sender, llm:OS::Media::Devices::KeypadPressedEventArgs const& e) const;
    };
    struct RedialRequestedEventHandler : llm:OS::Foundation::IUnknown
    {
        RedialRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
        RedialRequestedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RedialRequestedEventHandler(L lambda);
        template <typename F> RedialRequestedEventHandler(F* function);
        template <typename O, typename M> RedialRequestedEventHandler(O* object, M method);
        template <typename O, typename M> RedialRequestedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RedialRequestedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Devices::CallControl const& sender, llm:OS::Media::Devices::RedialRequestedEventArgs const& e) const;
    };
    struct __declspec(empty_bases) AdvancedPhotoCaptureSettings : llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings
    {
        AdvancedPhotoCaptureSettings(std::nullptr_t) noexcept {}
        AdvancedPhotoCaptureSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAdvancedPhotoCaptureSettings(ptr, take_ownership_from_abi) {}
        AdvancedPhotoCaptureSettings();
    };
    struct __declspec(empty_bases) AdvancedPhotoControl : llm:OS::Media::Devices::IAdvancedPhotoControl
    {
        AdvancedPhotoControl(std::nullptr_t) noexcept {}
        AdvancedPhotoControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAdvancedPhotoControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioDeviceController : llm:OS::Media::Devices::IAudioDeviceController
    {
        AudioDeviceController(std::nullptr_t) noexcept {}
        AudioDeviceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAudioDeviceController(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioDeviceModule : llm:OS::Media::Devices::IAudioDeviceModule
    {
        AudioDeviceModule(std::nullptr_t) noexcept {}
        AudioDeviceModule(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAudioDeviceModule(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioDeviceModuleNotificationEventArgs : llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs
    {
        AudioDeviceModuleNotificationEventArgs(std::nullptr_t) noexcept {}
        AudioDeviceModuleNotificationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAudioDeviceModuleNotificationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AudioDeviceModulesManager : llm:OS::Media::Devices::IAudioDeviceModulesManager
    {
        AudioDeviceModulesManager(std::nullptr_t) noexcept {}
        AudioDeviceModulesManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IAudioDeviceModulesManager(ptr, take_ownership_from_abi) {}
        explicit AudioDeviceModulesManager(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) CallControl : llm:OS::Media::Devices::ICallControl
    {
        CallControl(std::nullptr_t) noexcept {}
        CallControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ICallControl(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto FromId(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) CameraOcclusionInfo : llm:OS::Media::Devices::ICameraOcclusionInfo
    {
        CameraOcclusionInfo(std::nullptr_t) noexcept {}
        CameraOcclusionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ICameraOcclusionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraOcclusionState : llm:OS::Media::Devices::ICameraOcclusionState
    {
        CameraOcclusionState(std::nullptr_t) noexcept {}
        CameraOcclusionState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ICameraOcclusionState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraOcclusionStateChangedEventArgs : llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs
    {
        CameraOcclusionStateChangedEventArgs(std::nullptr_t) noexcept {}
        CameraOcclusionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ICameraOcclusionStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DefaultAudioCaptureDeviceChangedEventArgs : llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs
    {
        DefaultAudioCaptureDeviceChangedEventArgs(std::nullptr_t) noexcept {}
        DefaultAudioCaptureDeviceChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DefaultAudioRenderDeviceChangedEventArgs : llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs
    {
        DefaultAudioRenderDeviceChangedEventArgs(std::nullptr_t) noexcept {}
        DefaultAudioRenderDeviceChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDefaultAudioDeviceChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialRequestedEventArgs : llm:OS::Media::Devices::IDialRequestedEventArgs
    {
        DialRequestedEventArgs(std::nullptr_t) noexcept {}
        DialRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDialRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DigitalWindowBounds : llm:OS::Media::Devices::IDigitalWindowBounds
    {
        DigitalWindowBounds(std::nullptr_t) noexcept {}
        DigitalWindowBounds(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDigitalWindowBounds(ptr, take_ownership_from_abi) {}
        DigitalWindowBounds();
    };
    struct __declspec(empty_bases) DigitalWindowCapability : llm:OS::Media::Devices::IDigitalWindowCapability
    {
        DigitalWindowCapability(std::nullptr_t) noexcept {}
        DigitalWindowCapability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDigitalWindowCapability(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DigitalWindowControl : llm:OS::Media::Devices::IDigitalWindowControl
    {
        DigitalWindowControl(std::nullptr_t) noexcept {}
        DigitalWindowControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IDigitalWindowControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ExposureCompensationControl : llm:OS::Media::Devices::IExposureCompensationControl
    {
        ExposureCompensationControl(std::nullptr_t) noexcept {}
        ExposureCompensationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IExposureCompensationControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ExposureControl : llm:OS::Media::Devices::IExposureControl
    {
        ExposureControl(std::nullptr_t) noexcept {}
        ExposureControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IExposureControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ExposurePriorityVideoControl : llm:OS::Media::Devices::IExposurePriorityVideoControl
    {
        ExposurePriorityVideoControl(std::nullptr_t) noexcept {}
        ExposurePriorityVideoControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IExposurePriorityVideoControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FlashControl : llm:OS::Media::Devices::IFlashControl,
        impl::require<FlashControl, llm:OS::Media::Devices::IFlashControl2>
    {
        FlashControl(std::nullptr_t) noexcept {}
        FlashControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IFlashControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FocusControl : llm:OS::Media::Devices::IFocusControl,
        impl::require<FocusControl, llm:OS::Media::Devices::IFocusControl2>
    {
        FocusControl(std::nullptr_t) noexcept {}
        FocusControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IFocusControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FocusSettings : llm:OS::Media::Devices::IFocusSettings
    {
        FocusSettings(std::nullptr_t) noexcept {}
        FocusSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IFocusSettings(ptr, take_ownership_from_abi) {}
        FocusSettings();
    };
    struct __declspec(empty_bases) HdrVideoControl : llm:OS::Media::Devices::IHdrVideoControl
    {
        HdrVideoControl(std::nullptr_t) noexcept {}
        HdrVideoControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IHdrVideoControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InfraredTorchControl : llm:OS::Media::Devices::IInfraredTorchControl
    {
        InfraredTorchControl(std::nullptr_t) noexcept {}
        InfraredTorchControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IInfraredTorchControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IsoSpeedControl : llm:OS::Media::Devices::IIsoSpeedControl,
        impl::require<IsoSpeedControl, llm:OS::Media::Devices::IIsoSpeedControl2>
    {
        IsoSpeedControl(std::nullptr_t) noexcept {}
        IsoSpeedControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IIsoSpeedControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeypadPressedEventArgs : llm:OS::Media::Devices::IKeypadPressedEventArgs
    {
        KeypadPressedEventArgs(std::nullptr_t) noexcept {}
        KeypadPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IKeypadPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LowLagPhotoControl : llm:OS::Media::Devices::ILowLagPhotoControl
    {
        LowLagPhotoControl(std::nullptr_t) noexcept {}
        LowLagPhotoControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ILowLagPhotoControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LowLagPhotoSequenceControl : llm:OS::Media::Devices::ILowLagPhotoSequenceControl
    {
        LowLagPhotoSequenceControl(std::nullptr_t) noexcept {}
        LowLagPhotoSequenceControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ILowLagPhotoSequenceControl(ptr, take_ownership_from_abi) {}
    };
    struct MediaDevice
    {
        MediaDevice() = delete;
        static auto GetAudioCaptureSelector();
        static auto GetAudioRenderSelector();
        static auto GetVideoCaptureSelector();
        static auto GetDefaultAudioCaptureId(llm:OS::Media::Devices::AudioDeviceRole const& role);
        static auto GetDefaultAudioRenderId(llm:OS::Media::Devices::AudioDeviceRole const& role);
        static auto DefaultAudioCaptureDeviceChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> const& handler);
        using DefaultAudioCaptureDeviceChanged_revoker = impl::factory_event_revoker<llm:OS::Media::Devices::IMediaDeviceStatics, &impl::abi_t<llm:OS::Media::Devices::IMediaDeviceStatics>::remove_DefaultAudioCaptureDeviceChanged>;
        [[nodiscard]] static DefaultAudioCaptureDeviceChanged_revoker DefaultAudioCaptureDeviceChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs> const& handler);
        static auto DefaultAudioCaptureDeviceChanged(llm::event_token const& cookie);
        static auto DefaultAudioRenderDeviceChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> const& handler);
        using DefaultAudioRenderDeviceChanged_revoker = impl::factory_event_revoker<llm:OS::Media::Devices::IMediaDeviceStatics, &impl::abi_t<llm:OS::Media::Devices::IMediaDeviceStatics>::remove_DefaultAudioRenderDeviceChanged>;
        [[nodiscard]] static DefaultAudioRenderDeviceChanged_revoker DefaultAudioRenderDeviceChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs> const& handler);
        static auto DefaultAudioRenderDeviceChanged(llm::event_token const& cookie);
    };
    struct __declspec(empty_bases) MediaDeviceControl : llm:OS::Media::Devices::IMediaDeviceControl
    {
        MediaDeviceControl(std::nullptr_t) noexcept {}
        MediaDeviceControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IMediaDeviceControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MediaDeviceControlCapabilities : llm:OS::Media::Devices::IMediaDeviceControlCapabilities
    {
        MediaDeviceControlCapabilities(std::nullptr_t) noexcept {}
        MediaDeviceControlCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IMediaDeviceControlCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ModuleCommandResult : llm:OS::Media::Devices::IModuleCommandResult
    {
        ModuleCommandResult(std::nullptr_t) noexcept {}
        ModuleCommandResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IModuleCommandResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) OpticalImageStabilizationControl : llm:OS::Media::Devices::IOpticalImageStabilizationControl
    {
        OpticalImageStabilizationControl(std::nullptr_t) noexcept {}
        OpticalImageStabilizationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IOpticalImageStabilizationControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PanelBasedOptimizationControl : llm:OS::Media::Devices::IPanelBasedOptimizationControl
    {
        PanelBasedOptimizationControl(std::nullptr_t) noexcept {}
        PanelBasedOptimizationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IPanelBasedOptimizationControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoConfirmationControl : llm:OS::Media::Devices::IPhotoConfirmationControl
    {
        PhotoConfirmationControl(std::nullptr_t) noexcept {}
        PhotoConfirmationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IPhotoConfirmationControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RedialRequestedEventArgs : llm:OS::Media::Devices::IRedialRequestedEventArgs
    {
        RedialRequestedEventArgs(std::nullptr_t) noexcept {}
        RedialRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IRedialRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RegionOfInterest : llm:OS::Media::Devices::IRegionOfInterest,
        impl::require<RegionOfInterest, llm:OS::Media::Devices::IRegionOfInterest2>
    {
        RegionOfInterest(std::nullptr_t) noexcept {}
        RegionOfInterest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IRegionOfInterest(ptr, take_ownership_from_abi) {}
        RegionOfInterest();
    };
    struct __declspec(empty_bases) RegionsOfInterestControl : llm:OS::Media::Devices::IRegionsOfInterestControl
    {
        RegionsOfInterestControl(std::nullptr_t) noexcept {}
        RegionsOfInterestControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IRegionsOfInterestControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SceneModeControl : llm:OS::Media::Devices::ISceneModeControl
    {
        SceneModeControl(std::nullptr_t) noexcept {}
        SceneModeControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ISceneModeControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TorchControl : llm:OS::Media::Devices::ITorchControl
    {
        TorchControl(std::nullptr_t) noexcept {}
        TorchControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::ITorchControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoDeviceController : llm:OS::Media::Devices::IVideoDeviceController,
        impl::require<VideoDeviceController, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController2, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController3, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController4, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController5, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController6, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController7, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController8, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController9, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController10, llm:OS::Media::Devices::IAdvancedVideoCaptureDeviceController11>
    {
        VideoDeviceController(std::nullptr_t) noexcept {}
        VideoDeviceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IVideoDeviceController(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoDeviceControllerGetDevicePropertyResult : llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult
    {
        VideoDeviceControllerGetDevicePropertyResult(std::nullptr_t) noexcept {}
        VideoDeviceControllerGetDevicePropertyResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IVideoDeviceControllerGetDevicePropertyResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VideoTemporalDenoisingControl : llm:OS::Media::Devices::IVideoTemporalDenoisingControl
    {
        VideoTemporalDenoisingControl(std::nullptr_t) noexcept {}
        VideoTemporalDenoisingControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IVideoTemporalDenoisingControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WhiteBalanceControl : llm:OS::Media::Devices::IWhiteBalanceControl
    {
        WhiteBalanceControl(std::nullptr_t) noexcept {}
        WhiteBalanceControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IWhiteBalanceControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ZoomControl : llm:OS::Media::Devices::IZoomControl,
        impl::require<ZoomControl, llm:OS::Media::Devices::IZoomControl2>
    {
        ZoomControl(std::nullptr_t) noexcept {}
        ZoomControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IZoomControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ZoomSettings : llm:OS::Media::Devices::IZoomSettings
    {
        ZoomSettings(std::nullptr_t) noexcept {}
        ZoomSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Devices::IZoomSettings(ptr, take_ownership_from_abi) {}
        ZoomSettings();
    };
}
#endif
