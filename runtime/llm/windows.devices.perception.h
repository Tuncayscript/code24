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
#ifndef LLM_OS_Devices_Perception_H
#define LLM_OS_Devices_Perception_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Devices.Core.2.h"
#include "llm/impl/Windows.Devices.Perception.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownCameraIntrinsicsPropertiesStatics<D>::FocalLength() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics)->get_FocalLength(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownCameraIntrinsicsPropertiesStatics<D>::PrincipalPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics)->get_PrincipalPoint(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownCameraIntrinsicsPropertiesStatics<D>::RadialDistortion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics)->get_RadialDistortion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownCameraIntrinsicsPropertiesStatics<D>::TangentialDistortion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics)->get_TangentialDistortion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::Exposure() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics)->get_Exposure(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::AutoExposureEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics)->get_AutoExposureEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::ExposureCompensation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics)->get_ExposureCompensation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>::MinDepth() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics)->get_MinDepth(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>::MaxDepth() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics)->get_MaxDepth(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics<D>::PhysicalDeviceIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics)->get_PhysicalDeviceIds(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics<D>::FrameKind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics)->get_FrameKind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics<D>::DeviceModelVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics)->get_DeviceModelVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics<D>::EnclosureLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics)->get_EnclosureLocation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionFrameSourcePropertiesStatics2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::Exposure() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_Exposure(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::AutoExposureEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_AutoExposureEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::ExposureCompensation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_ExposureCompensation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::ActiveIlluminationEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_ActiveIlluminationEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::AmbientSubtractionEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_AmbientSubtractionEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::StructureLightPatternEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_StructureLightPatternEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::InterleavedIlluminationEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_InterleavedIlluminationEnabled(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::VideoProfile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_VideoProfile(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::SupportedVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_SupportedVideoProfiles(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::AvailableVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_AvailableVideoProfiles(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::IsMirrored() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_IsMirrored(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::CameraIntrinsics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_CameraIntrinsics(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoProfilePropertiesStatics<D>::BitmapPixelFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics)->get_BitmapPixelFormat(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoProfilePropertiesStatics<D>::BitmapAlphaMode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics)->get_BitmapAlphaMode(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoProfilePropertiesStatics<D>::Width() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics)->get_Width(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoProfilePropertiesStatics<D>::Height() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics)->get_Height(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IKnownPerceptionVideoProfilePropertiesStatics<D>::FrameDuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics)->get_FrameDuration(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Devices_Perception_IPerceptionColorFrame<D>::VideoFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrame)->get_VideoFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Perception_IPerceptionColorFrameArrivedEventArgs<D>::RelativeTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrame) consume_Windows_Devices_Perception_IPerceptionColorFrameArrivedEventArgs<D>::TryOpenFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs)->TryOpenFrame(&result));
        return llm::OS::Devices::Perception::PerceptionColorFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::FrameArrived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameReader, llm::OS::Devices::Perception::PerceptionColorFrameArrivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->add_FrameArrived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::FrameArrived_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::FrameArrived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameReader, llm::OS::Devices::Perception::PerceptionColorFrameArrivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FrameArrived_revoker>(this, FrameArrived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::FrameArrived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->remove_FrameArrived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrameSource) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->get_Source(&value));
        return llm::OS::Devices::Perception::PerceptionColorFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::IsPaused() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->get_IsPaused(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::IsPaused(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->put_IsPaused(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrame) consume_Windows_Devices_Perception_IPerceptionColorFrameReader<D>::TryReadLatestFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameReader)->TryReadLatestFrame(&result));
        return llm::OS::Devices::Perception::PerceptionColorFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AvailableChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->add_AvailableChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AvailableChanged_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AvailableChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AvailableChanged_revoker>(this, AvailableChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AvailableChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->remove_AvailableChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::ActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->add_ActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::ActiveChanged_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::ActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ActiveChanged_revoker>(this, ActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::ActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->remove_ActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::PropertiesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->add_PropertiesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::PropertiesChanged_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::PropertiesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PropertiesChanged_revoker>(this, PropertiesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::PropertiesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->remove_PropertiesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::VideoProfileChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->add_VideoProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::VideoProfileChanged_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::VideoProfileChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, VideoProfileChanged_revoker>(this, VideoProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::VideoProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->remove_VideoProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->add_CameraIntrinsicsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CameraIntrinsicsChanged_revoker>(this, CameraIntrinsicsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->remove_CameraIntrinsicsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::DeviceKind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_DeviceKind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::Available() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_Available(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::Active() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_Active(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::IsControlled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_IsControlled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::SupportedVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_SupportedVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AvailableVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_AvailableVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionVideoProfile) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::VideoProfile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_VideoProfile(&value));
        return llm::OS::Devices::Perception::PerceptionVideoProfile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CameraIntrinsics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->get_CameraIntrinsics(&value));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionControlSession) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::AcquireControlSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->AcquireControlSession(&value));
        return llm::OS::Devices::Perception::PerceptionControlSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::CanControlIndependentlyFrom(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->CanControlIndependentlyFrom(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::IsCorrelatedWith(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->IsCorrelatedWith(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::TryGetTransformTo(param::hstring const& targetId, llm::OS::Foundation::Numerics::float4x4& result) const
    {
        bool hasResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->TryGetTransformTo(*(void**)(&targetId), impl::bind_out(result), &hasResult));
        return hasResult;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(llm::OS::Devices::Perception::PerceptionDepthFrameSource const& correlatedDepthFrameSource) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->TryGetDepthCorrelatedCameraIntrinsicsAsync(*(void**)(&correlatedDepthFrameSource), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(param::hstring const& targetSourceId, llm::OS::Devices::Perception::PerceptionDepthFrameSource const& correlatedDepthFrameSource) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->TryGetDepthCorrelatedCoordinateMapperAsync(*(void**)(&targetSourceId), *(void**)(&correlatedDepthFrameSource), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::TrySetVideoProfileAsync(llm::OS::Devices::Perception::PerceptionControlSession const& controlSession, llm::OS::Devices::Perception::PerceptionVideoProfile const& profile) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->TrySetVideoProfileAsync(*(void**)(&controlSession), *(void**)(&profile), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrameReader) consume_Windows_Devices_Perception_IPerceptionColorFrameSource<D>::OpenReader() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource)->OpenReader(&result));
        return llm::OS::Devices::Perception::PerceptionColorFrameReader{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionColorFrameSource2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSource2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrameSource) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceAddedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionColorFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrameSource) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceRemovedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionColorFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceStatics<D>::CreateWatcher() const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics)->CreateWatcher(&watcher));
        return llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionColorFrameSource>>) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceStatics<D>::FindAllAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics)->FindAllAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionColorFrameSource>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionColorFrameSource>) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceStatics<D>::FromIdAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics)->FromIdAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionColorFrameSource>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->add_SourceAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceAdded_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceAdded_revoker>(this, SourceAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->remove_SourceAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->add_SourceRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceRemoved_revoker>(this, SourceRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->remove_SourceRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Stopped_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted_revoker consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherStatus) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionColorFrameSourceWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionControlSession<D>::ControlLost(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionControlSession, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionControlSession)->add_ControlLost(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionControlSession<D>::ControlLost_revoker consume_Windows_Devices_Perception_IPerceptionControlSession<D>::ControlLost(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionControlSession, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ControlLost_revoker>(this, ControlLost(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionControlSession<D>::ControlLost(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionControlSession)->remove_ControlLost(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>) consume_Windows_Devices_Perception_IPerceptionControlSession<D>::TrySetPropertyAsync(param::hstring const& name, llm::OS::Foundation::IInspectable const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionControlSession)->TrySetPropertyAsync(*(void**)(&name), *(void**)(&value), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectPixelAtCorrelatedDepth(llm::OS::Foundation::Point const& pixelCoordinate, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame) const
    {
        llm::OS::Foundation::Numerics::float3 result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics)->UnprojectPixelAtCorrelatedDepth(impl::bind_in(pixelCoordinate), *(void**)(&depthFrame), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectPixelsAtCorrelatedDepth(array_view<llm::OS::Foundation::Point const> sourceCoordinates, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Numerics::float3> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics)->UnprojectPixelsAtCorrelatedDepth(sourceCoordinates.size(), get_abi(sourceCoordinates), *(void**)(&depthFrame), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectRegionPixelsAtCorrelatedDepthAsync(llm::OS::Foundation::Rect const& region, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Numerics::float3> results) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics)->UnprojectRegionPixelsAtCorrelatedDepthAsync(impl::bind_in(region), *(void**)(&depthFrame), results.size(), put_abi(results), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectAllPixelsAtCorrelatedDepthAsync(llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Numerics::float3> results) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics)->UnprojectAllPixelsAtCorrelatedDepthAsync(*(void**)(&depthFrame), results.size(), put_abi(results), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapPixelToTarget(llm::OS::Foundation::Point const& sourcePixelCoordinate, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper)->MapPixelToTarget(impl::bind_in(sourcePixelCoordinate), *(void**)(&depthFrame), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapPixelsToTarget(array_view<llm::OS::Foundation::Point const> sourceCoordinates, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Point> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper)->MapPixelsToTarget(sourceCoordinates.size(), get_abi(sourceCoordinates), *(void**)(&depthFrame), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapRegionOfPixelsToTargetAsync(llm::OS::Foundation::Rect const& region, llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Point> targetCoordinates) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper)->MapRegionOfPixelsToTargetAsync(impl::bind_in(region), *(void**)(&depthFrame), targetCoordinates.size(), put_abi(targetCoordinates), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Perception_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapAllPixelsToTargetAsync(llm::OS::Devices::Perception::PerceptionDepthFrame const& depthFrame, array_view<llm::OS::Foundation::Point> targetCoordinates) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper)->MapAllPixelsToTargetAsync(*(void**)(&depthFrame), targetCoordinates.size(), put_abi(targetCoordinates), &result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Devices_Perception_IPerceptionDepthFrame<D>::VideoFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrame)->get_VideoFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Perception_IPerceptionDepthFrameArrivedEventArgs<D>::RelativeTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrame) consume_Windows_Devices_Perception_IPerceptionDepthFrameArrivedEventArgs<D>::TryOpenFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs)->TryOpenFrame(&result));
        return llm::OS::Devices::Perception::PerceptionDepthFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::FrameArrived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameReader, llm::OS::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->add_FrameArrived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::FrameArrived_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::FrameArrived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameReader, llm::OS::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FrameArrived_revoker>(this, FrameArrived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::FrameArrived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->remove_FrameArrived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrameSource) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->get_Source(&value));
        return llm::OS::Devices::Perception::PerceptionDepthFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::IsPaused() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->get_IsPaused(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::IsPaused(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->put_IsPaused(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrame) consume_Windows_Devices_Perception_IPerceptionDepthFrameReader<D>::TryReadLatestFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameReader)->TryReadLatestFrame(&result));
        return llm::OS::Devices::Perception::PerceptionDepthFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AvailableChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->add_AvailableChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AvailableChanged_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AvailableChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AvailableChanged_revoker>(this, AvailableChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AvailableChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->remove_AvailableChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::ActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->add_ActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::ActiveChanged_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::ActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ActiveChanged_revoker>(this, ActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::ActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->remove_ActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::PropertiesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->add_PropertiesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::PropertiesChanged_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::PropertiesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PropertiesChanged_revoker>(this, PropertiesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::PropertiesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->remove_PropertiesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::VideoProfileChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->add_VideoProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::VideoProfileChanged_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::VideoProfileChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, VideoProfileChanged_revoker>(this, VideoProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::VideoProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->remove_VideoProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->add_CameraIntrinsicsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CameraIntrinsicsChanged_revoker>(this, CameraIntrinsicsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->remove_CameraIntrinsicsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::DeviceKind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_DeviceKind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::Available() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_Available(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::Active() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_Active(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::IsControlled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_IsControlled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::SupportedVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_SupportedVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AvailableVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_AvailableVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionVideoProfile) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::VideoProfile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_VideoProfile(&value));
        return llm::OS::Devices::Perception::PerceptionVideoProfile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CameraIntrinsics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->get_CameraIntrinsics(&value));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionControlSession) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::AcquireControlSession() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->AcquireControlSession(&result));
        return llm::OS::Devices::Perception::PerceptionControlSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::CanControlIndependentlyFrom(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->CanControlIndependentlyFrom(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::IsCorrelatedWith(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->IsCorrelatedWith(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::TryGetTransformTo(param::hstring const& targetId, llm::OS::Foundation::Numerics::float4x4& result) const
    {
        bool hasResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->TryGetTransformTo(*(void**)(&targetId), impl::bind_out(result), &hasResult));
        return hasResult;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(llm::OS::Devices::Perception::PerceptionDepthFrameSource const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->TryGetDepthCorrelatedCameraIntrinsicsAsync(*(void**)(&target), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(param::hstring const& targetId, llm::OS::Devices::Perception::PerceptionDepthFrameSource const& depthFrameSourceToMapWith) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->TryGetDepthCorrelatedCoordinateMapperAsync(*(void**)(&targetId), *(void**)(&depthFrameSourceToMapWith), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::TrySetVideoProfileAsync(llm::OS::Devices::Perception::PerceptionControlSession const& controlSession, llm::OS::Devices::Perception::PerceptionVideoProfile const& profile) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->TrySetVideoProfileAsync(*(void**)(&controlSession), *(void**)(&profile), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrameReader) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource<D>::OpenReader() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource)->OpenReader(&result));
        return llm::OS::Devices::Perception::PerceptionDepthFrameReader{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionDepthFrameSource2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSource2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrameSource) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceAddedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionDepthFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrameSource) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceRemovedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionDepthFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceStatics<D>::CreateWatcher() const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics)->CreateWatcher(&watcher));
        return llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionDepthFrameSource>>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceStatics<D>::FindAllAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics)->FindAllAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionDepthFrameSource>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthFrameSource>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceStatics<D>::FromIdAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics)->FromIdAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthFrameSource>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->add_SourceAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceAdded_revoker>(this, SourceAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->remove_SourceAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->add_SourceRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceRemoved_revoker>(this, SourceRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->remove_SourceRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Stopped_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted_revoker consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherStatus) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionDepthFrameSourceWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::CollectionChange) consume_Windows_Devices_Perception_IPerceptionFrameSourcePropertiesChangedEventArgs<D>::CollectionChange() const
    {
        llm::OS::Foundation::Collections::CollectionChange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs)->get_CollectionChange(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionFrameSourcePropertiesChangedEventArgs<D>::Key() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs)->get_Key(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus) consume_Windows_Devices_Perception_IPerceptionFrameSourcePropertyChangeResult<D>::Status() const
    {
        llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Devices_Perception_IPerceptionFrameSourcePropertyChangeResult<D>::NewValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult)->get_NewValue(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Devices_Perception_IPerceptionInfraredFrame<D>::VideoFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrame)->get_VideoFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Perception_IPerceptionInfraredFrameArrivedEventArgs<D>::RelativeTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrame) consume_Windows_Devices_Perception_IPerceptionInfraredFrameArrivedEventArgs<D>::TryOpenFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs)->TryOpenFrame(&result));
        return llm::OS::Devices::Perception::PerceptionInfraredFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::FrameArrived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameReader, llm::OS::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->add_FrameArrived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::FrameArrived_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::FrameArrived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameReader, llm::OS::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FrameArrived_revoker>(this, FrameArrived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::FrameArrived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->remove_FrameArrived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrameSource) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->get_Source(&value));
        return llm::OS::Devices::Perception::PerceptionInfraredFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::IsPaused() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->get_IsPaused(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::IsPaused(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->put_IsPaused(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrame) consume_Windows_Devices_Perception_IPerceptionInfraredFrameReader<D>::TryReadLatestFrame() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameReader)->TryReadLatestFrame(&result));
        return llm::OS::Devices::Perception::PerceptionInfraredFrame{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AvailableChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->add_AvailableChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AvailableChanged_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AvailableChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AvailableChanged_revoker>(this, AvailableChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AvailableChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->remove_AvailableChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::ActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->add_ActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::ActiveChanged_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::ActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ActiveChanged_revoker>(this, ActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::ActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->remove_ActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::PropertiesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->add_PropertiesChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::PropertiesChanged_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::PropertiesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PropertiesChanged_revoker>(this, PropertiesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::PropertiesChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->remove_PropertiesChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->add_VideoProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::VideoProfileChanged_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, VideoProfileChanged_revoker>(this, VideoProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->remove_VideoProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->add_CameraIntrinsicsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CameraIntrinsicsChanged_revoker>(this, CameraIntrinsicsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->remove_CameraIntrinsicsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::DeviceKind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_DeviceKind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::Available() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_Available(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::Active() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_Active(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::IsControlled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_IsControlled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::SupportedVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_SupportedVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AvailableVideoProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_AvailableVideoProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionVideoProfile) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::VideoProfile() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_VideoProfile(&value));
        return llm::OS::Devices::Perception::PerceptionVideoProfile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CameraIntrinsics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->get_CameraIntrinsics(&value));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionControlSession) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::AcquireControlSession() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->AcquireControlSession(&result));
        return llm::OS::Devices::Perception::PerceptionControlSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::CanControlIndependentlyFrom(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->CanControlIndependentlyFrom(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::IsCorrelatedWith(param::hstring const& targetId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->IsCorrelatedWith(*(void**)(&targetId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::TryGetTransformTo(param::hstring const& targetId, llm::OS::Foundation::Numerics::float4x4& result) const
    {
        bool hasResult{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->TryGetTransformTo(*(void**)(&targetId), impl::bind_out(result), &hasResult));
        return hasResult;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(llm::OS::Devices::Perception::PerceptionDepthFrameSource const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->TryGetDepthCorrelatedCameraIntrinsicsAsync(*(void**)(&target), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(param::hstring const& targetId, llm::OS::Devices::Perception::PerceptionDepthFrameSource const& depthFrameSourceToMapWith) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->TryGetDepthCorrelatedCoordinateMapperAsync(*(void**)(&targetId), *(void**)(&depthFrameSourceToMapWith), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::TrySetVideoProfileAsync(llm::OS::Devices::Perception::PerceptionControlSession const& controlSession, llm::OS::Devices::Perception::PerceptionVideoProfile const& profile) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->TrySetVideoProfileAsync(*(void**)(&controlSession), *(void**)(&profile), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrameReader) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource<D>::OpenReader() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource)->OpenReader(&result));
        return llm::OS::Devices::Perception::PerceptionInfraredFrameReader{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSource2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSource2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrameSource) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceAddedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionInfraredFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrameSource) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceRemovedEventArgs<D>::FrameSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs)->get_FrameSource(&value));
        return llm::OS::Devices::Perception::PerceptionInfraredFrameSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceStatics<D>::CreateWatcher() const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics)->CreateWatcher(&watcher));
        return llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceStatics<D>::FindAllAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics)->FindAllAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceStatics<D>::FromIdAsync(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics)->FromIdAsync(*(void**)(&id), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceStatics<D>::RequestAccessAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics)->RequestAccessAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->add_SourceAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceAdded_revoker>(this, SourceAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->remove_SourceAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->add_SourceRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SourceRemoved_revoker>(this, SourceRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->remove_SourceRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Stopped_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted_revoker consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherStatus) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Perception_IPerceptionInfraredFrameSourceWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapPixelFormat) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::BitmapPixelFormat() const
    {
        llm::OS::Graphics::Imaging::BitmapPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->get_BitmapPixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapAlphaMode) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::BitmapAlphaMode() const
    {
        llm::OS::Graphics::Imaging::BitmapAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->get_BitmapAlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::Width() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::Height() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::FrameDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->get_FrameDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Perception_IPerceptionVideoProfile<D>::IsEqual(llm::OS::Devices::Perception::PerceptionVideoProfile const& other) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Perception::IPerceptionVideoProfile)->IsEqual(*(void**)(&other), &result));
        return result;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics>
    {
        int32_t __stdcall get_FocalLength(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FocalLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrincipalPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PrincipalPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RadialDistortion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RadialDistortion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TangentialDistortion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TangentialDistortion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
    {
        int32_t __stdcall get_Exposure(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Exposure());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoExposureEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AutoExposureEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExposureCompensation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExposureCompensation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
    {
        int32_t __stdcall get_MinDepth(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MinDepth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxDepth(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MaxDepth());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalDeviceIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PhysicalDeviceIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameKind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FrameKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceModelVersion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceModelVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnclosureLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnclosureLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
    {
        int32_t __stdcall get_Exposure(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Exposure());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AutoExposureEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AutoExposureEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExposureCompensation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ExposureCompensation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActiveIlluminationEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActiveIlluminationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AmbientSubtractionEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AmbientSubtractionEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StructureLightPatternEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StructureLightPatternEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InterleavedIlluminationEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().InterleavedIlluminationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
    {
        int32_t __stdcall get_VideoProfile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().VideoProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SupportedVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AvailableVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMirrored(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().IsMirrored());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraIntrinsics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CameraIntrinsics());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics> : produce_base<D, llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
    {
        int32_t __stdcall get_BitmapPixelFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BitmapPixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapAlphaMode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().BitmapAlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameDuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FrameDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrame> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrame>
    {
        int32_t __stdcall get_VideoFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().VideoFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>
    {
        int32_t __stdcall get_RelativeTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().RelativeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryOpenFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionColorFrame>(this->shim().TryOpenFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameReader> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameReader>
    {
        int32_t __stdcall add_FrameArrived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FrameArrived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameReader, llm::OS::Devices::Perception::PerceptionColorFrameArrivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FrameArrived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionColorFrameSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPaused(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPaused());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPaused(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReadLatestFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionColorFrame>(this->shim().TryReadLatestFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSource> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSource>
    {
        int32_t __stdcall add_AvailableChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailableChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailableChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PropertiesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PropertiesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PropertiesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_VideoProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VideoProfileChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VideoProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CameraIntrinsicsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CameraIntrinsicsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceKind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Available(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Available());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Active(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Active());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsControlled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsControlled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().SupportedVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().AvailableVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProfile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionVideoProfile>(this->shim().VideoProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraIntrinsics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::CameraIntrinsics>(this->shim().CameraIntrinsics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireControlSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionControlSession>(this->shim().AcquireControlSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanControlIndependentlyFrom(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCorrelatedWith(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsCorrelatedWith(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetTransformTo(void* targetId, llm::OS::Foundation::Numerics::float4x4* result, bool* hasResult) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(result);
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_from<bool>(this->shim().TryGetTransformTo(*reinterpret_cast<hstring const*>(&targetId), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4*>(result)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCameraIntrinsicsAsync(void* correlatedDepthFrameSource, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>>(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&correlatedDepthFrameSource)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCoordinateMapperAsync(void* targetSourceId, void* correlatedDepthFrameSource, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>>(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<hstring const*>(&targetSourceId), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&correlatedDepthFrameSource)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetVideoProfileAsync(void* controlSession, void* profile, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>>(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionControlSession const*>(&controlSession), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionVideoProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenReader(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionColorFrameReader>(this->shim().OpenReader());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSource2> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSource2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionColorFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionColorFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics>
    {
        int32_t __stdcall CreateWatcher(void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionColorFrameSource>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionColorFrameSource>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher> : produce_base<D, llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher>
    {
        int32_t __stdcall add_SourceAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SourceRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionControlSession> : produce_base<D, llm::OS::Devices::Perception::IPerceptionControlSession>
    {
        int32_t __stdcall add_ControlLost(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ControlLost(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionControlSession, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ControlLost(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlLost(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall TrySetPropertyAsync(void* name, void* value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>>(this->shim().TrySetPropertyAsync(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>
    {
        int32_t __stdcall UnprojectPixelAtCorrelatedDepth(llm::OS::Foundation::Point pixelCoordinate, void* depthFrame, llm::OS::Foundation::Numerics::float3* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().UnprojectPixelAtCorrelatedDepth(*reinterpret_cast<llm::OS::Foundation::Point const*>(&pixelCoordinate), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectPixelsAtCorrelatedDepth(uint32_t __sourceCoordinatesSize, llm::OS::Foundation::Point* sourceCoordinates, void* depthFrame, uint32_t __resultsSize, llm::OS::Foundation::Numerics::float3* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPixelsAtCorrelatedDepth(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(sourceCoordinates), reinterpret_cast<llm::OS::Foundation::Point const *>(sourceCoordinates) + __sourceCoordinatesSize), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Numerics::float3>(reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results), reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectRegionPixelsAtCorrelatedDepthAsync(llm::OS::Foundation::Rect region, void* depthFrame, uint32_t __resultsSize, llm::OS::Foundation::Numerics::float3* results, void** result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(results, __resultsSize);
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnprojectRegionPixelsAtCorrelatedDepthAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&region), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Numerics::float3>(reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results), reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results) + __resultsSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectAllPixelsAtCorrelatedDepthAsync(void* depthFrame, uint32_t __resultsSize, llm::OS::Foundation::Numerics::float3* results, void** result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(results, __resultsSize);
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UnprojectAllPixelsAtCorrelatedDepthAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Numerics::float3>(reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results), reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results) + __resultsSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>
    {
        int32_t __stdcall MapPixelToTarget(llm::OS::Foundation::Point sourcePixelCoordinate, void* depthFrame, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().MapPixelToTarget(*reinterpret_cast<llm::OS::Foundation::Point const*>(&sourcePixelCoordinate), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MapPixelsToTarget(uint32_t __sourceCoordinatesSize, llm::OS::Foundation::Point* sourceCoordinates, void* depthFrame, uint32_t __resultsSize, llm::OS::Foundation::Point* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().MapPixelsToTarget(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(sourceCoordinates), reinterpret_cast<llm::OS::Foundation::Point const *>(sourceCoordinates) + __sourceCoordinatesSize), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(results), reinterpret_cast<llm::OS::Foundation::Point*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MapRegionOfPixelsToTargetAsync(llm::OS::Foundation::Rect region, void* depthFrame, uint32_t __targetCoordinatesSize, llm::OS::Foundation::Point* targetCoordinates, void** result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(targetCoordinates, __targetCoordinatesSize);
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MapRegionOfPixelsToTargetAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&region), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(targetCoordinates), reinterpret_cast<llm::OS::Foundation::Point*>(targetCoordinates) + __targetCoordinatesSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MapAllPixelsToTargetAsync(void* depthFrame, uint32_t __targetCoordinatesSize, llm::OS::Foundation::Point* targetCoordinates, void** result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(targetCoordinates, __targetCoordinatesSize);
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MapAllPixelsToTargetAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrame const*>(&depthFrame), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(targetCoordinates), reinterpret_cast<llm::OS::Foundation::Point*>(targetCoordinates) + __targetCoordinatesSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrame> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrame>
    {
        int32_t __stdcall get_VideoFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().VideoFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>
    {
        int32_t __stdcall get_RelativeTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().RelativeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryOpenFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrame>(this->shim().TryOpenFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameReader> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameReader>
    {
        int32_t __stdcall add_FrameArrived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FrameArrived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameReader, llm::OS::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FrameArrived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrameSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPaused(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPaused());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPaused(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReadLatestFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrame>(this->shim().TryReadLatestFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSource> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSource>
    {
        int32_t __stdcall add_AvailableChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailableChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailableChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PropertiesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PropertiesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PropertiesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_VideoProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VideoProfileChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VideoProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CameraIntrinsicsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CameraIntrinsicsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceKind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Available(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Available());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Active(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Active());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsControlled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsControlled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().SupportedVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().AvailableVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProfile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionVideoProfile>(this->shim().VideoProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraIntrinsics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::CameraIntrinsics>(this->shim().CameraIntrinsics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireControlSession(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionControlSession>(this->shim().AcquireControlSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanControlIndependentlyFrom(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCorrelatedWith(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsCorrelatedWith(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetTransformTo(void* targetId, llm::OS::Foundation::Numerics::float4x4* result, bool* hasResult) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(result);
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_from<bool>(this->shim().TryGetTransformTo(*reinterpret_cast<hstring const*>(&targetId), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4*>(result)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCameraIntrinsicsAsync(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>>(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCoordinateMapperAsync(void* targetId, void* depthFrameSourceToMapWith, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>>(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<hstring const*>(&targetId), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&depthFrameSourceToMapWith)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetVideoProfileAsync(void* controlSession, void* profile, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>>(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionControlSession const*>(&controlSession), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionVideoProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenReader(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrameReader>(this->shim().OpenReader());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSource2> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSource2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics>
    {
        int32_t __stdcall CreateWatcher(void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionDepthFrameSource>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthFrameSource>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher> : produce_base<D, llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher>
    {
        int32_t __stdcall add_SourceAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SourceRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>
    {
        int32_t __stdcall get_CollectionChange(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::CollectionChange>(this->shim().CollectionChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Key(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Key());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> : produce_base<D, llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().NewValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrame> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrame>
    {
        int32_t __stdcall get_VideoFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().VideoFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>
    {
        int32_t __stdcall get_RelativeTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().RelativeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryOpenFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrame>(this->shim().TryOpenFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameReader> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameReader>
    {
        int32_t __stdcall add_FrameArrived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FrameArrived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameReader, llm::OS::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FrameArrived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPaused(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPaused());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPaused(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReadLatestFrame(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrame>(this->shim().TryReadLatestFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSource> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSource>
    {
        int32_t __stdcall add_AvailableChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailableChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailableChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PropertiesChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PropertiesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PropertiesChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_VideoProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VideoProfileChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VideoProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CameraIntrinsicsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CameraIntrinsicsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceKind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Available(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Available());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Active(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Active());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsControlled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsControlled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().SupportedVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableVideoProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionVideoProfile>>(this->shim().AvailableVideoProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProfile(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionVideoProfile>(this->shim().VideoProfile());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CameraIntrinsics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::CameraIntrinsics>(this->shim().CameraIntrinsics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireControlSession(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionControlSession>(this->shim().AcquireControlSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanControlIndependentlyFrom(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCorrelatedWith(void* targetId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsCorrelatedWith(*reinterpret_cast<hstring const*>(&targetId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetTransformTo(void* targetId, llm::OS::Foundation::Numerics::float4x4* result, bool* hasResult) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(result);
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_from<bool>(this->shim().TryGetTransformTo(*reinterpret_cast<hstring const*>(&targetId), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4*>(result)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCameraIntrinsicsAsync(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>>(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetDepthCorrelatedCoordinateMapperAsync(void* targetId, void* depthFrameSourceToMapWith, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>>(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<hstring const*>(&targetId), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSource const*>(&depthFrameSourceToMapWith)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetVideoProfileAsync(void* controlSession, void* profile, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>>(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionControlSession const*>(&controlSession), *reinterpret_cast<llm::OS::Devices::Perception::PerceptionVideoProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenReader(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrameReader>(this->shim().OpenReader());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSource2> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSource2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs>
    {
        int32_t __stdcall get_FrameSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>(this->shim().FrameSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics>
    {
        int32_t __stdcall CreateWatcher(void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> : produce_base<D, llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>
    {
        int32_t __stdcall add_SourceAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SourceRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SourceRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SourceRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Perception::IPerceptionVideoProfile> : produce_base<D, llm::OS::Devices::Perception::IPerceptionVideoProfile>
    {
        int32_t __stdcall get_BitmapPixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapPixelFormat>(this->shim().BitmapPixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitmapAlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapAlphaMode>(this->shim().BitmapAlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().FrameDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEqual(void* other, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsEqual(*reinterpret_cast<llm::OS::Devices::Perception::PerceptionVideoProfile const*>(&other)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Perception
{
    inline auto KnownCameraIntrinsicsProperties::FocalLength()
    {
        return impl::call_factory_cast<hstring(*)(IKnownCameraIntrinsicsPropertiesStatics const&), KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>([](IKnownCameraIntrinsicsPropertiesStatics const& f) { return f.FocalLength(); });
    }
    inline auto KnownCameraIntrinsicsProperties::PrincipalPoint()
    {
        return impl::call_factory_cast<hstring(*)(IKnownCameraIntrinsicsPropertiesStatics const&), KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>([](IKnownCameraIntrinsicsPropertiesStatics const& f) { return f.PrincipalPoint(); });
    }
    inline auto KnownCameraIntrinsicsProperties::RadialDistortion()
    {
        return impl::call_factory_cast<hstring(*)(IKnownCameraIntrinsicsPropertiesStatics const&), KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>([](IKnownCameraIntrinsicsPropertiesStatics const& f) { return f.RadialDistortion(); });
    }
    inline auto KnownCameraIntrinsicsProperties::TangentialDistortion()
    {
        return impl::call_factory_cast<hstring(*)(IKnownCameraIntrinsicsPropertiesStatics const&), KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>([](IKnownCameraIntrinsicsPropertiesStatics const& f) { return f.TangentialDistortion(); });
    }
    inline auto KnownPerceptionColorFrameSourceProperties::Exposure()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionColorFrameSourcePropertiesStatics const&), KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>([](IKnownPerceptionColorFrameSourcePropertiesStatics const& f) { return f.Exposure(); });
    }
    inline auto KnownPerceptionColorFrameSourceProperties::AutoExposureEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionColorFrameSourcePropertiesStatics const&), KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>([](IKnownPerceptionColorFrameSourcePropertiesStatics const& f) { return f.AutoExposureEnabled(); });
    }
    inline auto KnownPerceptionColorFrameSourceProperties::ExposureCompensation()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionColorFrameSourcePropertiesStatics const&), KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>([](IKnownPerceptionColorFrameSourcePropertiesStatics const& f) { return f.ExposureCompensation(); });
    }
    inline auto KnownPerceptionDepthFrameSourceProperties::MinDepth()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionDepthFrameSourcePropertiesStatics const&), KnownPerceptionDepthFrameSourceProperties, IKnownPerceptionDepthFrameSourcePropertiesStatics>([](IKnownPerceptionDepthFrameSourcePropertiesStatics const& f) { return f.MinDepth(); });
    }
    inline auto KnownPerceptionDepthFrameSourceProperties::MaxDepth()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionDepthFrameSourcePropertiesStatics const&), KnownPerceptionDepthFrameSourceProperties, IKnownPerceptionDepthFrameSourcePropertiesStatics>([](IKnownPerceptionDepthFrameSourcePropertiesStatics const& f) { return f.MaxDepth(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::Id()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>([](IKnownPerceptionFrameSourcePropertiesStatics const& f) { return f.Id(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::PhysicalDeviceIds()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>([](IKnownPerceptionFrameSourcePropertiesStatics const& f) { return f.PhysicalDeviceIds(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::FrameKind()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>([](IKnownPerceptionFrameSourcePropertiesStatics const& f) { return f.FrameKind(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::DeviceModelVersion()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>([](IKnownPerceptionFrameSourcePropertiesStatics const& f) { return f.DeviceModelVersion(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::EnclosureLocation()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>([](IKnownPerceptionFrameSourcePropertiesStatics const& f) { return f.EnclosureLocation(); });
    }
    inline auto KnownPerceptionFrameSourceProperties::DeviceId()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionFrameSourcePropertiesStatics2 const&), KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics2>([](IKnownPerceptionFrameSourcePropertiesStatics2 const& f) { return f.DeviceId(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::Exposure()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.Exposure(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::AutoExposureEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.AutoExposureEnabled(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::ExposureCompensation()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.ExposureCompensation(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::ActiveIlluminationEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.ActiveIlluminationEnabled(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::AmbientSubtractionEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.AmbientSubtractionEnabled(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::StructureLightPatternEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.StructureLightPatternEnabled(); });
    }
    inline auto KnownPerceptionInfraredFrameSourceProperties::InterleavedIlluminationEnabled()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionInfraredFrameSourcePropertiesStatics const&), KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>([](IKnownPerceptionInfraredFrameSourcePropertiesStatics const& f) { return f.InterleavedIlluminationEnabled(); });
    }
    inline auto KnownPerceptionVideoFrameSourceProperties::VideoProfile()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoFrameSourcePropertiesStatics const&), KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>([](IKnownPerceptionVideoFrameSourcePropertiesStatics const& f) { return f.VideoProfile(); });
    }
    inline auto KnownPerceptionVideoFrameSourceProperties::SupportedVideoProfiles()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoFrameSourcePropertiesStatics const&), KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>([](IKnownPerceptionVideoFrameSourcePropertiesStatics const& f) { return f.SupportedVideoProfiles(); });
    }
    inline auto KnownPerceptionVideoFrameSourceProperties::AvailableVideoProfiles()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoFrameSourcePropertiesStatics const&), KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>([](IKnownPerceptionVideoFrameSourcePropertiesStatics const& f) { return f.AvailableVideoProfiles(); });
    }
    inline auto KnownPerceptionVideoFrameSourceProperties::IsMirrored()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoFrameSourcePropertiesStatics const&), KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>([](IKnownPerceptionVideoFrameSourcePropertiesStatics const& f) { return f.IsMirrored(); });
    }
    inline auto KnownPerceptionVideoFrameSourceProperties::CameraIntrinsics()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoFrameSourcePropertiesStatics const&), KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>([](IKnownPerceptionVideoFrameSourcePropertiesStatics const& f) { return f.CameraIntrinsics(); });
    }
    inline auto KnownPerceptionVideoProfileProperties::BitmapPixelFormat()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoProfilePropertiesStatics const&), KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>([](IKnownPerceptionVideoProfilePropertiesStatics const& f) { return f.BitmapPixelFormat(); });
    }
    inline auto KnownPerceptionVideoProfileProperties::BitmapAlphaMode()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoProfilePropertiesStatics const&), KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>([](IKnownPerceptionVideoProfilePropertiesStatics const& f) { return f.BitmapAlphaMode(); });
    }
    inline auto KnownPerceptionVideoProfileProperties::Width()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoProfilePropertiesStatics const&), KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>([](IKnownPerceptionVideoProfilePropertiesStatics const& f) { return f.Width(); });
    }
    inline auto KnownPerceptionVideoProfileProperties::Height()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoProfilePropertiesStatics const&), KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>([](IKnownPerceptionVideoProfilePropertiesStatics const& f) { return f.Height(); });
    }
    inline auto KnownPerceptionVideoProfileProperties::FrameDuration()
    {
        return impl::call_factory_cast<hstring(*)(IKnownPerceptionVideoProfilePropertiesStatics const&), KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>([](IKnownPerceptionVideoProfilePropertiesStatics const& f) { return f.FrameDuration(); });
    }
    inline auto PerceptionColorFrameSource::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher(*)(IPerceptionColorFrameSourceStatics const&), PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>([](IPerceptionColorFrameSourceStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto PerceptionColorFrameSource::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionColorFrameSource>>(*)(IPerceptionColorFrameSourceStatics const&), PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>([](IPerceptionColorFrameSourceStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto PerceptionColorFrameSource::FromIdAsync(param::hstring const& id)
    {
        return impl::call_factory<PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>([&](IPerceptionColorFrameSourceStatics const& f) { return f.FromIdAsync(id); });
    }
    inline auto PerceptionColorFrameSource::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>(*)(IPerceptionColorFrameSourceStatics const&), PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>([](IPerceptionColorFrameSourceStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto PerceptionDepthFrameSource::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher(*)(IPerceptionDepthFrameSourceStatics const&), PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>([](IPerceptionDepthFrameSourceStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto PerceptionDepthFrameSource::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionDepthFrameSource>>(*)(IPerceptionDepthFrameSourceStatics const&), PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>([](IPerceptionDepthFrameSourceStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto PerceptionDepthFrameSource::FromIdAsync(param::hstring const& id)
    {
        return impl::call_factory<PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>([&](IPerceptionDepthFrameSourceStatics const& f) { return f.FromIdAsync(id); });
    }
    inline auto PerceptionDepthFrameSource::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>(*)(IPerceptionDepthFrameSourceStatics const&), PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>([](IPerceptionDepthFrameSourceStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto PerceptionInfraredFrameSource::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher(*)(IPerceptionInfraredFrameSourceStatics const&), PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>([](IPerceptionInfraredFrameSourceStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto PerceptionInfraredFrameSource::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Perception::PerceptionInfraredFrameSource>>(*)(IPerceptionInfraredFrameSourceStatics const&), PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>([](IPerceptionInfraredFrameSourceStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto PerceptionInfraredFrameSource::FromIdAsync(param::hstring const& id)
    {
        return impl::call_factory<PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>([&](IPerceptionInfraredFrameSourceStatics const& f) { return f.FromIdAsync(id); });
    }
    inline auto PerceptionInfraredFrameSource::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Perception::PerceptionFrameSourceAccessStatus>(*)(IPerceptionInfraredFrameSourceStatics const&), PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>([](IPerceptionInfraredFrameSourceStatics const& f) { return f.RequestAccessAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionColorFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionControlSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionDepthFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::IPerceptionVideoProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownCameraIntrinsicsProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionColorFrameSourceProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionDepthFrameSourceProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionFrameSourceProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionInfraredFrameSourceProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionVideoFrameSourceProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::KnownPerceptionVideoProfileProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionColorFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionControlSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionDepthFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionInfraredFrameSourceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Perception::PerceptionVideoProfile> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
