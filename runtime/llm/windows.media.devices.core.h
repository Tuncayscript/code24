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
#ifndef LLM_OS_Media_Devices_Core_H
#define LLM_OS_Media_Devices_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Media.MediaProperties.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.Media.Devices.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::FocalLength() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_FocalLength(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::PrincipalPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_PrincipalPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::RadialDistortion() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_RadialDistortion(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::TangentialDistortion() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_TangentialDistortion(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::ImageWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_ImageWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::ImageHeight() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->get_ImageHeight(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::ProjectOntoFrame(llm::OS::Foundation::Numerics::float3 const& coordinate) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->ProjectOntoFrame(impl::bind_in(coordinate), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::UnprojectAtUnitDepth(llm::OS::Foundation::Point const& pixelCoordinate) const
    {
        llm::OS::Foundation::Numerics::float2 result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->UnprojectAtUnitDepth(impl::bind_in(pixelCoordinate), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::ProjectManyOntoFrame(array_view<llm::OS::Foundation::Numerics::float3 const> coordinates, array_view<llm::OS::Foundation::Point> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->ProjectManyOntoFrame(coordinates.size(), get_abi(coordinates), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_ICameraIntrinsics<D>::UnprojectPixelsAtUnitDepth(array_view<llm::OS::Foundation::Point const> pixelCoordinates, array_view<llm::OS::Foundation::Numerics::float2> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics)->UnprojectPixelsAtUnitDepth(pixelCoordinates.size(), get_abi(pixelCoordinates), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>::UndistortedProjectionTransform() const
    {
        llm::OS::Foundation::Numerics::float4x4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics2)->get_UndistortedProjectionTransform(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>::DistortPoint(llm::OS::Foundation::Point const& input) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics2)->DistortPoint(impl::bind_in(input), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>::DistortPoints(array_view<llm::OS::Foundation::Point const> inputs, array_view<llm::OS::Foundation::Point> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics2)->DistortPoints(inputs.size(), get_abi(inputs), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>::UndistortPoint(llm::OS::Foundation::Point const& input) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics2)->UndistortPoint(impl::bind_in(input), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_ICameraIntrinsics2<D>::UndistortPoints(array_view<llm::OS::Foundation::Point const> inputs, array_view<llm::OS::Foundation::Point> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsics2)->UndistortPoints(inputs.size(), get_abi(inputs), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::CameraIntrinsics) consume_Windows_Media_Devices_Core_ICameraIntrinsicsFactory<D>::Create(llm::OS::Foundation::Numerics::float2 const& focalLength, llm::OS::Foundation::Numerics::float2 const& principalPoint, llm::OS::Foundation::Numerics::float3 const& radialDistortion, llm::OS::Foundation::Numerics::float2 const& tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::ICameraIntrinsicsFactory)->Create(impl::bind_in(focalLength), impl::bind_in(principalPoint), impl::bind_in(radialDistortion), impl::bind_in(tangentialDistortion), imageWidth, imageHeight, &result));
        return llm::OS::Media::Devices::Core::CameraIntrinsics{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper<D>::UnprojectPoint(llm::OS::Foundation::Point const& sourcePoint, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem) const
    {
        llm::OS::Foundation::Numerics::float3 result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper)->UnprojectPoint(impl::bind_in(sourcePoint), *(void**)(&targetCoordinateSystem), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper<D>::UnprojectPoints(array_view<llm::OS::Foundation::Point const> sourcePoints, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, array_view<llm::OS::Foundation::Numerics::float3> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper)->UnprojectPoints(sourcePoints.size(), get_abi(sourcePoints), *(void**)(&targetCoordinateSystem), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper<D>::MapPoint(llm::OS::Foundation::Point const& sourcePoint, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, llm::OS::Media::Devices::Core::CameraIntrinsics const& targetCameraIntrinsics) const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper)->MapPoint(impl::bind_in(sourcePoint), *(void**)(&targetCoordinateSystem), *(void**)(&targetCameraIntrinsics), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IDepthCorrelatedCoordinateMapper<D>::MapPoints(array_view<llm::OS::Foundation::Point const> sourcePoints, llm::OS::Perception::Spatial::SpatialCoordinateSystem const& targetCoordinateSystem, llm::OS::Media::Devices::Core::CameraIntrinsics const& targetCameraIntrinsics, array_view<llm::OS::Foundation::Point> results) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper)->MapPoints(sourcePoints.size(), get_abi(sourcePoints), *(void**)(&targetCoordinateSystem), *(void**)(&targetCameraIntrinsics), results.size(), put_abi(results)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameExposureCapabilities) consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>::Exposure() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities)->get_Exposure(&value));
        return llm::OS::Media::Devices::Core::FrameExposureCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameExposureCompensationCapabilities) consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>::ExposureCompensation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities)->get_ExposureCompensation(&value));
        return llm::OS::Media::Devices::Core::FrameExposureCompensationCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameIsoSpeedCapabilities) consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>::IsoSpeed() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities)->get_IsoSpeed(&value));
        return llm::OS::Media::Devices::Core::FrameIsoSpeedCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameFocusCapabilities) consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>::Focus() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities)->get_Focus(&value));
        return llm::OS::Media::Devices::Core::FrameFocusCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameControlCapabilities<D>::PhotoConfirmationSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities)->get_PhotoConfirmationSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameFlashCapabilities) consume_Windows_Media_Devices_Core_IFrameControlCapabilities2<D>::Flash() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameControlCapabilities2)->get_Flash(&value));
        return llm::OS::Media::Devices::Core::FrameFlashCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameExposureControl) consume_Windows_Media_Devices_Core_IFrameController<D>::ExposureControl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->get_ExposureControl(&value));
        return llm::OS::Media::Devices::Core::FrameExposureControl{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameExposureCompensationControl) consume_Windows_Media_Devices_Core_IFrameController<D>::ExposureCompensationControl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->get_ExposureCompensationControl(&value));
        return llm::OS::Media::Devices::Core::FrameExposureCompensationControl{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameIsoSpeedControl) consume_Windows_Media_Devices_Core_IFrameController<D>::IsoSpeedControl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->get_IsoSpeedControl(&value));
        return llm::OS::Media::Devices::Core::FrameIsoSpeedControl{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameFocusControl) consume_Windows_Media_Devices_Core_IFrameController<D>::FocusControl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->get_FocusControl(&value));
        return llm::OS::Media::Devices::Core::FrameFocusControl{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Media_Devices_Core_IFrameController<D>::PhotoConfirmationEnabled() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->get_PhotoConfirmationEnabled(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameController<D>::PhotoConfirmationEnabled(llm::OS::Foundation::IReference<bool> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController)->put_PhotoConfirmationEnabled(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameFlashControl) consume_Windows_Media_Devices_Core_IFrameController2<D>::FlashControl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameController2)->get_FlashControl(&value));
        return llm::OS::Media::Devices::Core::FrameFlashControl{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameExposureCapabilities<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCapabilities)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Devices_Core_IFrameExposureCapabilities<D>::Min() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCapabilities)->get_Min(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Devices_Core_IFrameExposureCapabilities<D>::Max() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCapabilities)->get_Max(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Media_Devices_Core_IFrameExposureCapabilities<D>::Step() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCapabilities)->get_Step(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities<D>::Min() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities)->get_Min(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities<D>::Max() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities)->get_Max(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IFrameExposureCompensationCapabilities<D>::Step() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities)->get_Step(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_Media_Devices_Core_IFrameExposureCompensationControl<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationControl)->get_Value(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameExposureCompensationControl<D>::Value(llm::OS::Foundation::IReference<float> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureCompensationControl)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameExposureControl<D>::Auto() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureControl)->get_Auto(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameExposureControl<D>::Auto(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureControl)->put_Auto(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Media_Devices_Core_IFrameExposureControl<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureControl)->get_Value(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameExposureControl<D>::Value(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameExposureControl)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFlashCapabilities<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashCapabilities)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFlashCapabilities<D>::RedEyeReductionSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashCapabilities)->get_RedEyeReductionSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFlashCapabilities<D>::PowerSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashCapabilities)->get_PowerSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameFlashMode) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::Mode() const
    {
        llm::OS::Media::Devices::Core::FrameFlashMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::Mode(llm::OS::Media::Devices::Core::FrameFlashMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->put_Mode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::Auto() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->get_Auto(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::Auto(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->put_Auto(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::RedEyeReduction() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->get_RedEyeReduction(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::RedEyeReduction(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->put_RedEyeReduction(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::PowerPercent() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->get_PowerPercent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameFlashControl<D>::PowerPercent(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFlashControl)->put_PowerPercent(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameFocusCapabilities<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusCapabilities)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameFocusCapabilities<D>::Min() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusCapabilities)->get_Min(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameFocusCapabilities<D>::Max() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusCapabilities)->get_Max(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameFocusCapabilities<D>::Step() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusCapabilities)->get_Step(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Devices_Core_IFrameFocusControl<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusControl)->get_Value(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameFocusControl<D>::Value(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameFocusControl)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities<D>::Min() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities)->get_Min(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities<D>::Max() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities)->get_Max(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Media_Devices_Core_IFrameIsoSpeedCapabilities<D>::Step() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities)->get_Step(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl<D>::Auto() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedControl)->get_Auto(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl<D>::Auto(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedControl)->put_Auto(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedControl)->get_Value(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IFrameIsoSpeedControl<D>::Value(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IFrameIsoSpeedControl)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::Supported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->get_Supported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::MaxPhotosPerSecond() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->get_MaxPhotosPerSecond(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::PhotosPerSecondLimit() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->get_PhotosPerSecondLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::PhotosPerSecondLimit(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->put_PhotosPerSecondLimit(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaRatio) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::GetHighestConcurrentFrameRate(llm::OS::Media::MediaProperties::IMediaEncodingProperties const& captureProperties) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->GetHighestConcurrentFrameRate(*(void**)(&captureProperties), &value));
        return llm::OS::Media::MediaProperties::MediaRatio{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::MediaProperties::MediaRatio) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::GetCurrentFrameRate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->GetCurrentFrameRate(&value));
        return llm::OS::Media::MediaProperties::MediaRatio{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Devices::Core::FrameControlCapabilities) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::FrameCapabilities() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->get_FrameCapabilities(&value));
        return llm::OS::Media::Devices::Core::FrameControlCapabilities{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Media::Devices::Core::FrameController>) consume_Windows_Media_Devices_Core_IVariablePhotoSequenceController<D>::DesiredFrameControllers() const
    {
        void* items{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Devices::Core::IVariablePhotoSequenceController)->get_DesiredFrameControllers(&items));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Media::Devices::Core::FrameController>{ items, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::ICameraIntrinsics> : produce_base<D, llm::OS::Media::Devices::Core::ICameraIntrinsics>
    {
        int32_t __stdcall get_FocalLength(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().FocalLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrincipalPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().PrincipalPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RadialDistortion(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().RadialDistortion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TangentialDistortion(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().TangentialDistortion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImageWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ImageWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImageHeight(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ImageHeight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProjectOntoFrame(llm::OS::Foundation::Numerics::float3 coordinate, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().ProjectOntoFrame(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&coordinate)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectAtUnitDepth(llm::OS::Foundation::Point pixelCoordinate, llm::OS::Foundation::Numerics::float2* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().UnprojectAtUnitDepth(*reinterpret_cast<llm::OS::Foundation::Point const*>(&pixelCoordinate)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProjectManyOntoFrame(uint32_t __coordinatesSize, llm::OS::Foundation::Numerics::float3* coordinates, uint32_t __resultsSize, llm::OS::Foundation::Point* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectManyOntoFrame(array_view<llm::OS::Foundation::Numerics::float3 const>(reinterpret_cast<llm::OS::Foundation::Numerics::float3 const *>(coordinates), reinterpret_cast<llm::OS::Foundation::Numerics::float3 const *>(coordinates) + __coordinatesSize), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(results), reinterpret_cast<llm::OS::Foundation::Point*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectPixelsAtUnitDepth(uint32_t __pixelCoordinatesSize, llm::OS::Foundation::Point* pixelCoordinates, uint32_t __resultsSize, llm::OS::Foundation::Numerics::float2* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPixelsAtUnitDepth(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(pixelCoordinates), reinterpret_cast<llm::OS::Foundation::Point const *>(pixelCoordinates) + __pixelCoordinatesSize), array_view<llm::OS::Foundation::Numerics::float2>(reinterpret_cast<llm::OS::Foundation::Numerics::float2*>(results), reinterpret_cast<llm::OS::Foundation::Numerics::float2*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::ICameraIntrinsics2> : produce_base<D, llm::OS::Media::Devices::Core::ICameraIntrinsics2>
    {
        int32_t __stdcall get_UndistortedProjectionTransform(llm::OS::Foundation::Numerics::float4x4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4x4>(this->shim().UndistortedProjectionTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DistortPoint(llm::OS::Foundation::Point input, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().DistortPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&input)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DistortPoints(uint32_t __inputsSize, llm::OS::Foundation::Point* inputs, uint32_t __resultsSize, llm::OS::Foundation::Point* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().DistortPoints(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(inputs), reinterpret_cast<llm::OS::Foundation::Point const *>(inputs) + __inputsSize), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(results), reinterpret_cast<llm::OS::Foundation::Point*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UndistortPoint(llm::OS::Foundation::Point input, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().UndistortPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&input)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UndistortPoints(uint32_t __inputsSize, llm::OS::Foundation::Point* inputs, uint32_t __resultsSize, llm::OS::Foundation::Point* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().UndistortPoints(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(inputs), reinterpret_cast<llm::OS::Foundation::Point const *>(inputs) + __inputsSize), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(results), reinterpret_cast<llm::OS::Foundation::Point*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::ICameraIntrinsicsFactory> : produce_base<D, llm::OS::Media::Devices::Core::ICameraIntrinsicsFactory>
    {
        int32_t __stdcall Create(llm::OS::Foundation::Numerics::float2 focalLength, llm::OS::Foundation::Numerics::float2 principalPoint, llm::OS::Foundation::Numerics::float3 radialDistortion, llm::OS::Foundation::Numerics::float2 tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Devices::Core::CameraIntrinsics>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&focalLength), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&principalPoint), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&radialDistortion), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&tangentialDistortion), imageWidth, imageHeight));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> : produce_base<D, llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>
    {
        int32_t __stdcall UnprojectPoint(llm::OS::Foundation::Point sourcePoint, void* targetCoordinateSystem, llm::OS::Foundation::Numerics::float3* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().UnprojectPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&sourcePoint), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&targetCoordinateSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnprojectPoints(uint32_t __sourcePointsSize, llm::OS::Foundation::Point* sourcePoints, void* targetCoordinateSystem, uint32_t __resultsSize, llm::OS::Foundation::Numerics::float3* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPoints(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(sourcePoints), reinterpret_cast<llm::OS::Foundation::Point const *>(sourcePoints) + __sourcePointsSize), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&targetCoordinateSystem), array_view<llm::OS::Foundation::Numerics::float3>(reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results), reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MapPoint(llm::OS::Foundation::Point sourcePoint, void* targetCoordinateSystem, void* targetCameraIntrinsics, llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().MapPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&sourcePoint), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&targetCoordinateSystem), *reinterpret_cast<llm::OS::Media::Devices::Core::CameraIntrinsics const*>(&targetCameraIntrinsics)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall MapPoints(uint32_t __sourcePointsSize, llm::OS::Foundation::Point* sourcePoints, void* targetCoordinateSystem, void* targetCameraIntrinsics, uint32_t __resultsSize, llm::OS::Foundation::Point* results) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(results, __resultsSize);
            typename D::abi_guard guard(this->shim());
            this->shim().MapPoints(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(sourcePoints), reinterpret_cast<llm::OS::Foundation::Point const *>(sourcePoints) + __sourcePointsSize), *reinterpret_cast<llm::OS::Perception::Spatial::SpatialCoordinateSystem const*>(&targetCoordinateSystem), *reinterpret_cast<llm::OS::Media::Devices::Core::CameraIntrinsics const*>(&targetCameraIntrinsics), array_view<llm::OS::Foundation::Point>(reinterpret_cast<llm::OS::Foundation::Point*>(results), reinterpret_cast<llm::OS::Foundation::Point*>(results) + __resultsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameControlCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameControlCapabilities>
    {
        int32_t __stdcall get_Exposure(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameExposureCapabilities>(this->shim().Exposure());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExposureCompensation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameExposureCompensationCapabilities>(this->shim().ExposureCompensation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsoSpeed(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameIsoSpeedCapabilities>(this->shim().IsoSpeed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Focus(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameFocusCapabilities>(this->shim().Focus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotoConfirmationSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().PhotoConfirmationSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameControlCapabilities2> : produce_base<D, llm::OS::Media::Devices::Core::IFrameControlCapabilities2>
    {
        int32_t __stdcall get_Flash(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameFlashCapabilities>(this->shim().Flash());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameController> : produce_base<D, llm::OS::Media::Devices::Core::IFrameController>
    {
        int32_t __stdcall get_ExposureControl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameExposureControl>(this->shim().ExposureControl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExposureCompensationControl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameExposureCompensationControl>(this->shim().ExposureCompensationControl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsoSpeedControl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameIsoSpeedControl>(this->shim().IsoSpeedControl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FocusControl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameFocusControl>(this->shim().FocusControl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotoConfirmationEnabled(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().PhotoConfirmationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PhotoConfirmationEnabled(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoConfirmationEnabled(*reinterpret_cast<llm::OS::Foundation::IReference<bool> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameController2> : produce_base<D, llm::OS::Media::Devices::Core::IFrameController2>
    {
        int32_t __stdcall get_FlashControl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameFlashControl>(this->shim().FlashControl());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameExposureCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameExposureCapabilities>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Min(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Min());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Max(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Max());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Step(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Step());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Min(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Min());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Max(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Max());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Step(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Step());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameExposureCompensationControl> : produce_base<D, llm::OS::Media::Devices::Core::IFrameExposureCompensationControl>
    {
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Foundation::IReference<float> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameExposureControl> : produce_base<D, llm::OS::Media::Devices::Core::IFrameExposureControl>
    {
        int32_t __stdcall get_Auto(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Auto());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Auto(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameFlashCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameFlashCapabilities>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedEyeReductionSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RedEyeReductionSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PowerSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().PowerSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameFlashControl> : produce_base<D, llm::OS::Media::Devices::Core::IFrameFlashControl>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameFlashMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(*reinterpret_cast<llm::OS::Media::Devices::Core::FrameFlashMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Auto(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Auto());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Auto(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedEyeReduction(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RedEyeReduction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RedEyeReduction(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RedEyeReduction(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PowerPercent(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().PowerPercent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PowerPercent(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PowerPercent(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameFocusCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameFocusCapabilities>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Min(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Min());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Max(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Max());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Step(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Step());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameFocusControl> : produce_base<D, llm::OS::Media::Devices::Core::IFrameFocusControl>
    {
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities> : produce_base<D, llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Min(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Min());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Max(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Max());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Step(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Step());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IFrameIsoSpeedControl> : produce_base<D, llm::OS::Media::Devices::Core::IFrameIsoSpeedControl>
    {
        int32_t __stdcall get_Auto(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Auto());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Auto(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Devices::Core::IVariablePhotoSequenceController> : produce_base<D, llm::OS::Media::Devices::Core::IVariablePhotoSequenceController>
    {
        int32_t __stdcall get_Supported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Supported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxPhotosPerSecond(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxPhotosPerSecond());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhotosPerSecondLimit(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().PhotosPerSecondLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PhotosPerSecondLimit(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotosPerSecondLimit(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetHighestConcurrentFrameRate(void* captureProperties, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaRatio>(this->shim().GetHighestConcurrentFrameRate(*reinterpret_cast<llm::OS::Media::MediaProperties::IMediaEncodingProperties const*>(&captureProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentFrameRate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::MediaProperties::MediaRatio>(this->shim().GetCurrentFrameRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameCapabilities(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::Devices::Core::FrameControlCapabilities>(this->shim().FrameCapabilities());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredFrameControllers(void** items) noexcept final try
        {
            clear_abi(items);
            typename D::abi_guard guard(this->shim());
            *items = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Media::Devices::Core::FrameController>>(this->shim().DesiredFrameControllers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Devices::Core
{
    inline CameraIntrinsics::CameraIntrinsics(llm::OS::Foundation::Numerics::float2 const& focalLength, llm::OS::Foundation::Numerics::float2 const& principalPoint, llm::OS::Foundation::Numerics::float3 const& radialDistortion, llm::OS::Foundation::Numerics::float2 const& tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight) :
        CameraIntrinsics(impl::call_factory<CameraIntrinsics, ICameraIntrinsicsFactory>([&](ICameraIntrinsicsFactory const& f) { return f.Create(focalLength, principalPoint, radialDistortion, tangentialDistortion, imageWidth, imageHeight); }))
    {
    }
    inline FrameController::FrameController() :
        FrameController(impl::call_factory_cast<FrameController(*)(llm::OS::Foundation::IActivationFactory const&), FrameController>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FrameController>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Devices::Core::ICameraIntrinsics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::ICameraIntrinsics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::ICameraIntrinsicsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameControlCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameControlCapabilities2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameController2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameExposureCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameExposureCompensationCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameExposureCompensationControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameExposureControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameFlashCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameFlashControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameFocusCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameFocusControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameIsoSpeedCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IFrameIsoSpeedControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::IVariablePhotoSequenceController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::CameraIntrinsics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::DepthCorrelatedCoordinateMapper> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameControlCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameExposureCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameExposureCompensationCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameExposureCompensationControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameExposureControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameFlashCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameFlashControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameFocusCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameFocusControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameIsoSpeedCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::FrameIsoSpeedControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Devices::Core::VariablePhotoSequenceController> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
