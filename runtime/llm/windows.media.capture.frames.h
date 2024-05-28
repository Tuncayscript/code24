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
#ifndef LLM_OS_Media_Capture_Frames_H
#define LLM_OS_Media_Capture_Frames_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.Capture.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Capture.2.h"
#include "llm/impl/Windows.Media.Devices.2.h"
#include "llm/impl/Windows.Media.Devices.Core.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
#include "llm/impl/Windows.Media.Capture.Frames.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IAudioMediaFrame<D>::FrameReference() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IAudioMediaFrame)->get_FrameReference(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::AudioEncodingProperties) consume_Windows_Media_Capture_Frames_IAudioMediaFrame<D>::AudioEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IAudioMediaFrame)->get_AudioEncodingProperties(&value));
        return llm::OS::Media::MediaProperties::AudioEncodingProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::AudioFrame) consume_Windows_Media_Capture_Frames_IAudioMediaFrame<D>::GetAudioFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IAudioMediaFrame)->GetAudioFrame(&value));
        return llm::OS::Media::AudioFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IBufferMediaFrame<D>::FrameReference() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IBufferMediaFrame)->get_FrameReference(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Media_Capture_Frames_IBufferMediaFrame<D>::Buffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IBufferMediaFrame)->get_Buffer(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IDepthMediaFrame<D>::FrameReference() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame)->get_FrameReference(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrame) consume_Windows_Media_Capture_Frames_IDepthMediaFrame<D>::VideoMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame)->get_VideoMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::DepthMediaFrameFormat) consume_Windows_Media_Capture_Frames_IDepthMediaFrame<D>::DepthFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame)->get_DepthFormat(&value));
        return llm::OS::Media::Capture::Frames::DepthMediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper) consume_Windows_Media_Capture_Frames_IDepthMediaFrame<D>::TryCreateCoordinateMapper(llm::OS::Media::Devices::Core::CameraIntrinsics const& cameraIntrinsics, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame)->TryCreateCoordinateMapper(*(void**)(&cameraIntrinsics), *(void**)(&coordinateSystem), &value));
        return llm::OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Capture_Frames_IDepthMediaFrame2<D>::MaxReliableDepth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame2)->get_MaxReliableDepth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Capture_Frames_IDepthMediaFrame2<D>::MinReliableDepth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrame2)->get_MinReliableDepth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrameFormat) consume_Windows_Media_Capture_Frames_IDepthMediaFrameFormat<D>::VideoFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrameFormat)->get_VideoFormat(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Media_Capture_Frames_IDepthMediaFrameFormat<D>::DepthScaleInMeters() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IDepthMediaFrameFormat)->get_DepthScaleInMeters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IInfraredMediaFrame<D>::FrameReference() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IInfraredMediaFrame)->get_FrameReference(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrame) consume_Windows_Media_Capture_Frames_IInfraredMediaFrame<D>::VideoMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IInfraredMediaFrame)->get_VideoMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Capture_Frames_IInfraredMediaFrame<D>::IsIlluminated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IInfraredMediaFrame)->get_IsIlluminated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameFormat<D>::MajorType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat)->get_MajorType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameFormat<D>::Subtype() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat)->get_Subtype(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaRatio) consume_Windows_Media_Capture_Frames_IMediaFrameFormat<D>::FrameRate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat)->get_FrameRate(&value));
        return llm::OS::Media::MediaProperties::MediaRatio{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Media_Capture_Frames_IMediaFrameFormat<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrameFormat) consume_Windows_Media_Capture_Frames_IMediaFrameFormat<D>::VideoFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat)->get_VideoFormat(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::AudioEncodingProperties) consume_Windows_Media_Capture_Frames_IMediaFrameFormat2<D>::AudioEncodingProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameFormat2)->get_AudioEncodingProperties(&value));
        return llm::OS::Media::MediaProperties::AudioEncodingProperties{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::FrameArrived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameReader, llm::OS::Media::Capture::Frames::MediaFrameArrivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader)->add_FrameArrived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::FrameArrived_revoker consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::FrameArrived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameReader, llm::OS::Media::Capture::Frames::MediaFrameArrivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FrameArrived_revoker>(this, FrameArrived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::FrameArrived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader)->remove_FrameArrived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::TryAcquireLatestFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader)->TryAcquireLatestFrame(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameReaderStartStatus>) consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::StartAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader)->StartAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameReaderStartStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Frames_IMediaFrameReader<D>::StopAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader)->StopAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Frames_IMediaFrameReader2<D>::AcquisitionMode(llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader2)->put_AcquisitionMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode) consume_Windows_Media_Capture_Frames_IMediaFrameReader2<D>::AcquisitionMode() const
    {
        llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReader2)->get_AcquisitionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceKind) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::SourceKind() const
    {
        llm::OS::Media::Capture::Frames::MediaFrameSourceKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_SourceKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameFormat) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::Format() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_Format(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::SystemRelativeTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_SystemRelativeTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::BufferMediaFrame) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::BufferMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_BufferMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::BufferMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrame) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::VideoMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_VideoMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Media_Capture_Frames_IMediaFrameReference<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::AudioMediaFrame) consume_Windows_Media_Capture_Frames_IMediaFrameReference2<D>::AudioMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameReference2)->get_AudioMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::AudioMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceInfo) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::Info() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->get_Info(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameSourceInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceController) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::Controller() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->get_Controller(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameSourceController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameFormat>) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::SupportedFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->get_SupportedFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameFormat) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::CurrentFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->get_CurrentFormat(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::SetFormatAsync(llm::OS::Media::Capture::Frames::MediaFrameFormat const& format) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->SetFormatAsync(*(void**)(&format), &value));
        return llm::OS::Foundation::IAsyncAction{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::FormatChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->add_FormatChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::FormatChanged_revoker consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::FormatChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameSource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, FormatChanged_revoker>(this, FormatChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::FormatChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->remove_FormatChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Media_Capture_Frames_IMediaFrameSource<D>::TryGetCameraIntrinsics(llm::OS::Media::Capture::Frames::MediaFrameFormat const& format) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSource)->TryGetCameraIntrinsics(*(void**)(&format), &value));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController<D>::GetPropertyAsync(param::hstring const& propertyId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController)->GetPropertyAsync(*(void**)(&propertyId), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController<D>::SetPropertyAsync(param::hstring const& propertyId, llm::OS::Foundation::IInspectable const& propertyValue) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController)->SetPropertyAsync(*(void**)(&propertyId), *(void**)(&propertyValue), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::VideoDeviceController) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController<D>::VideoDeviceController() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController)->get_VideoDeviceController(&value));
        return llm::OS::Media::Devices::VideoDeviceController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController2<D>::GetPropertyByExtendedIdAsync(array_view<uint8_t const> extendedPropertyId, llm::OS::Foundation::IReference<uint32_t> const& maxPropertyValueSize) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController2)->GetPropertyByExtendedIdAsync(extendedPropertyId.size(), get_abi(extendedPropertyId), *(void**)(&maxPropertyValueSize), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController2<D>::SetPropertyByExtendedIdAsync(array_view<uint8_t const> extendedPropertyId, array_view<uint8_t const> propertyValue) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController2)->SetPropertyByExtendedIdAsync(extendedPropertyId.size(), get_abi(extendedPropertyId), propertyValue.size(), get_abi(propertyValue), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::AudioDeviceController) consume_Windows_Media_Capture_Frames_IMediaFrameSourceController3<D>::AudioDeviceController() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceController3)->get_AudioDeviceController(&value));
        return llm::OS::Media::Devices::AudioDeviceController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGetPropertyResult<D>::Status() const
    {
        llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGetPropertyResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult)->get_Value(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroup<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroup<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceInfo>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroup<D>::SourceInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup)->get_SourceInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroupStatics<D>::FindAllAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics)->FindAllAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroupStatics<D>::FromIdAsync(param::hstring const& id) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics)->FromIdAsync(*(void**)(&id), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameSourceGroupStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::MediaStreamType) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::MediaStreamType() const
    {
        llm::OS::Media::Capture::MediaStreamType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_MediaStreamType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceKind) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::SourceKind() const
    {
        llm::OS::Media::Capture::Frames::MediaFrameSourceKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_SourceKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameSourceGroup) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::SourceGroup() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_SourceGroup(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameSourceGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_DeviceInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Perception::Spatial::SpatialCoordinateSystem) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo<D>::CoordinateSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo)->get_CoordinateSystem(&value));
        return llm::OS::Perception::Spatial::SpatialCoordinateSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo2<D>::ProfileId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo2)->get_ProfileId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::MediaCaptureVideoProfileMediaDescription>) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo2<D>::VideoProfileMediaDescription() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo2)->get_VideoProfileMediaDescription(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::MediaCaptureVideoProfileMediaDescription>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Panel) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo3<D>::GetRelativePanel(llm::OS::UI::WindowManagement::DisplayRegion const& displayRegion) const
    {
        llm::OS::Devices::Enumeration::Panel result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo3)->GetRelativePanel(*(void**)(&displayRegion), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Capture_Frames_IMediaFrameSourceInfo4<D>::IsShareable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo4)->get_IsShareable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::FrameArrived(llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReader, llm::OS::Media::Capture::Frames::MultiSourceMediaFrameArrivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader)->add_FrameArrived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::FrameArrived_revoker consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::FrameArrived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReader, llm::OS::Media::Capture::Frames::MultiSourceMediaFrameArrivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FrameArrived_revoker>(this, FrameArrived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::FrameArrived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader)->remove_FrameArrived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReference) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::TryAcquireLatestFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader)->TryAcquireLatestFrame(&value));
        return llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReaderStartStatus>) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::StartAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader)->StartAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReaderStartStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader<D>::StopAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader)->StopAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader2<D>::AcquisitionMode(llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2)->put_AcquisitionMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReader2<D>::AcquisitionMode() const
    {
        llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2)->get_AcquisitionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IMultiSourceMediaFrameReference<D>::TryGetFrameReferenceBySourceId(param::hstring const& sourceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReference)->TryGetFrameReferenceBySourceId(*(void**)(&sourceId), &value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameReference) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::FrameReference() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_FrameReference(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::VideoMediaFrameFormat) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::VideoFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_VideoFormat(&value));
        return llm::OS::Media::Capture::Frames::VideoMediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::SoftwareBitmap) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::SoftwareBitmap() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_SoftwareBitmap(&value));
        return llm::OS::Graphics::Imaging::SoftwareBitmap{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::Direct3DSurface() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_Direct3DSurface(&value));
        return llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::CameraIntrinsics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_CameraIntrinsics(&value));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::InfraredMediaFrame) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::InfraredMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_InfraredMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::InfraredMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::DepthMediaFrame) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::DepthMediaFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->get_DepthMediaFrame(&value));
        return llm::OS::Media::Capture::Frames::DepthMediaFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::VideoFrame) consume_Windows_Media_Capture_Frames_IVideoMediaFrame<D>::GetVideoFrame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrame)->GetVideoFrame(&value));
        return llm::OS::Media::VideoFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::MediaFrameFormat) consume_Windows_Media_Capture_Frames_IVideoMediaFrameFormat<D>::MediaFrameFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat)->get_MediaFrameFormat(&value));
        return llm::OS::Media::Capture::Frames::MediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Capture::Frames::DepthMediaFrameFormat) consume_Windows_Media_Capture_Frames_IVideoMediaFrameFormat<D>::DepthFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat)->get_DepthFormat(&value));
        return llm::OS::Media::Capture::Frames::DepthMediaFrameFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Capture_Frames_IVideoMediaFrameFormat<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Capture_Frames_IVideoMediaFrameFormat<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat)->get_Height(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IAudioMediaFrame> : produce_base<D, llm::OS::Media::Capture::Frames::IAudioMediaFrame>
    {
        int32_t __stdcall get_FrameReference(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().FrameReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AudioEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::AudioEncodingProperties>(this->shim().AudioEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::AudioFrame>(this->shim().GetAudioFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IBufferMediaFrame> : produce_base<D, llm::OS::Media::Capture::Frames::IBufferMediaFrame>
    {
        int32_t __stdcall get_FrameReference(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().FrameReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Buffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Buffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IDepthMediaFrame> : produce_base<D, llm::OS::Media::Capture::Frames::IDepthMediaFrame>
    {
        int32_t __stdcall get_FrameReference(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().FrameReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrame>(this->shim().VideoMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DepthFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::DepthMediaFrameFormat>(this->shim().DepthFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateCoordinateMapper(void* cameraIntrinsics, void* coordinateSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper>(this->shim().TryCreateCoordinateMapper(*reinterpret_cast<llm::OS::Media::Devices::Core::CameraIntrinsics const*>(&cameraIntrinsics), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&coordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IDepthMediaFrame2> : produce_base<D, llm::OS::Media::Capture::Frames::IDepthMediaFrame2>
    {
        int32_t __stdcall get_MaxReliableDepth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxReliableDepth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinReliableDepth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MinReliableDepth());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IDepthMediaFrameFormat> : produce_base<D, llm::OS::Media::Capture::Frames::IDepthMediaFrameFormat>
    {
        int32_t __stdcall get_VideoFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrameFormat>(this->shim().VideoFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DepthScaleInMeters(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().DepthScaleInMeters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IInfraredMediaFrame> : produce_base<D, llm::OS::Media::Capture::Frames::IInfraredMediaFrame>
    {
        int32_t __stdcall get_FrameReference(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().FrameReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrame>(this->shim().VideoMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsIlluminated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsIlluminated());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameArrivedEventArgs> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameArrivedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameFormat> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameFormat>
    {
        int32_t __stdcall get_MajorType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MajorType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Subtype(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Subtype());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameRate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaRatio>(this->shim().FrameRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrameFormat>(this->shim().VideoFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameFormat2> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameFormat2>
    {
        int32_t __stdcall get_AudioEncodingProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::AudioEncodingProperties>(this->shim().AudioEncodingProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameReader> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameReader>
    {
        int32_t __stdcall add_FrameArrived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FrameArrived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameReader, llm::OS::Media::Capture::Frames::MediaFrameArrivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FrameArrived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall TryAcquireLatestFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().TryAcquireLatestFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameReaderStartStatus>>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StopAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameReader2> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameReader2>
    {
        int32_t __stdcall put_AcquisitionMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcquisitionMode(*reinterpret_cast<llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AcquisitionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode>(this->shim().AcquisitionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameReference> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameReference>
    {
        int32_t __stdcall get_SourceKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceKind>(this->shim().SourceKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemRelativeTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().SystemRelativeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::BufferMediaFrame>(this->shim().BufferMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrame>(this->shim().VideoMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameReference2> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameReference2>
    {
        int32_t __stdcall get_AudioMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::AudioMediaFrame>(this->shim().AudioMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSource> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSource>
    {
        int32_t __stdcall get_Info(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceInfo>(this->shim().Info());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Controller(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceController>(this->shim().Controller());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameFormat>>(this->shim().SupportedFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameFormat>(this->shim().CurrentFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFormatAsync(void* format, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetFormatAsync(*reinterpret_cast<llm::OS::Media::Capture::Frames::MediaFrameFormat const*>(&format)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_FormatChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FormatChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MediaFrameSource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FormatChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FormatChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall TryGetCameraIntrinsics(void* format, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::CameraIntrinsics>(this->shim().TryGetCameraIntrinsics(*reinterpret_cast<llm::OS::Media::Capture::Frames::MediaFrameFormat const*>(&format)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController>
    {
        int32_t __stdcall GetPropertyAsync(void* propertyId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>>(this->shim().GetPropertyAsync(*reinterpret_cast<hstring const*>(&propertyId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyAsync(void* propertyId, void* propertyValue, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>>(this->shim().SetPropertyAsync(*reinterpret_cast<hstring const*>(&propertyId), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&propertyValue)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoDeviceController(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::VideoDeviceController>(this->shim().VideoDeviceController());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController2> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController2>
    {
        int32_t __stdcall GetPropertyByExtendedIdAsync(uint32_t __extendedPropertyIdSize, uint8_t* extendedPropertyId, void* maxPropertyValueSize, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>>(this->shim().GetPropertyByExtendedIdAsync(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(extendedPropertyId), reinterpret_cast<uint8_t const *>(extendedPropertyId) + __extendedPropertyIdSize), *reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&maxPropertyValueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyByExtendedIdAsync(uint32_t __extendedPropertyIdSize, uint8_t* extendedPropertyId, uint32_t __propertyValueSize, uint8_t* propertyValue, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>>(this->shim().SetPropertyByExtendedIdAsync(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(extendedPropertyId), reinterpret_cast<uint8_t const *>(extendedPropertyId) + __extendedPropertyIdSize), array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(propertyValue), reinterpret_cast<uint8_t const *>(propertyValue) + __propertyValueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController3> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceController3>
    {
        int32_t __stdcall get_AudioDeviceController(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::AudioDeviceController>(this->shim().AudioDeviceController());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup>
    {
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
        int32_t __stdcall get_SourceInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceInfo>>(this->shim().SourceInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics>
    {
        int32_t __stdcall FindAllAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* id, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MediaStreamType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::MediaStreamType>(this->shim().MediaStreamType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceKind>(this->shim().SourceKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceGroup(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>(this->shim().SourceGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().DeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Perception::Spatial::SpatialCoordinateSystem>(this->shim().CoordinateSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo2> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo2>
    {
        int32_t __stdcall get_ProfileId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProfileId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoProfileMediaDescription(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::MediaCaptureVideoProfileMediaDescription>>(this->shim().VideoProfileMediaDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo3> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo3>
    {
        int32_t __stdcall GetRelativePanel(void* displayRegion, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Enumeration::Panel>(this->shim().GetRelativePanel(*reinterpret_cast<llm::OS::UI::WindowManagement::DisplayRegion const*>(&displayRegion)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo4> : produce_base<D, llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo4>
    {
        int32_t __stdcall get_IsShareable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsShareable());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameArrivedEventArgs> : produce_base<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameArrivedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader> : produce_base<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader>
    {
        int32_t __stdcall add_FrameArrived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().FrameArrived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReader, llm::OS::Media::Capture::Frames::MultiSourceMediaFrameArrivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FrameArrived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall TryAcquireLatestFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReference>(this->shim().TryAcquireLatestFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReaderStartStatus>>(this->shim().StartAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StopAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2> : produce_base<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2>
    {
        int32_t __stdcall put_AcquisitionMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcquisitionMode(*reinterpret_cast<llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AcquisitionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReaderAcquisitionMode>(this->shim().AcquisitionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReference> : produce_base<D, llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReference>
    {
        int32_t __stdcall TryGetFrameReferenceBySourceId(void* sourceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().TryGetFrameReferenceBySourceId(*reinterpret_cast<hstring const*>(&sourceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IVideoMediaFrame> : produce_base<D, llm::OS::Media::Capture::Frames::IVideoMediaFrame>
    {
        int32_t __stdcall get_FrameReference(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameReference>(this->shim().FrameReference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::VideoMediaFrameFormat>(this->shim().VideoFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SoftwareBitmap(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::SoftwareBitmap>(this->shim().SoftwareBitmap());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direct3DSurface(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::IDirect3DSurface>(this->shim().Direct3DSurface());
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
        int32_t __stdcall get_InfraredMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::InfraredMediaFrame>(this->shim().InfraredMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DepthMediaFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::DepthMediaFrame>(this->shim().DepthMediaFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVideoFrame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::VideoFrame>(this->shim().GetVideoFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat> : produce_base<D, llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat>
    {
        int32_t __stdcall get_MediaFrameFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::MediaFrameFormat>(this->shim().MediaFrameFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DepthFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Capture::Frames::DepthMediaFrameFormat>(this->shim().DepthFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Width(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Width());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Height(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Height());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Capture::Frames
{
    inline auto MediaFrameSourceGroup::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup>>(*)(IMediaFrameSourceGroupStatics const&), MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>([](IMediaFrameSourceGroupStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto MediaFrameSourceGroup::FromIdAsync(param::hstring const& id)
    {
        return impl::call_factory<MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>([&](IMediaFrameSourceGroupStatics const& f) { return f.FromIdAsync(id); });
    }
    inline auto MediaFrameSourceGroup::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IMediaFrameSourceGroupStatics const&), MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>([](IMediaFrameSourceGroupStatics const& f) { return f.GetDeviceSelector(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Capture::Frames::IAudioMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IBufferMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IDepthMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IDepthMediaFrame2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IDepthMediaFrameFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IInfraredMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameFormat2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameReader2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameReference2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceController2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceController3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceGroupStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMediaFrameSourceInfo4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReader2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IMultiSourceMediaFrameReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IVideoMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::IVideoMediaFrameFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::AudioMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::BufferMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::DepthMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::DepthMediaFrameFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::InfraredMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameSourceController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameSourceGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MediaFrameSourceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameArrivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReader> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::MultiSourceMediaFrameReference> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::VideoMediaFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Capture::Frames::VideoMediaFrameFormat> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
