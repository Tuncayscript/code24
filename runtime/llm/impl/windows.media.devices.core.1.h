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
#ifndef LLM_OS_Media_Devices_Core_1_H
#define LLM_OS_Media_Devices_Core_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.Devices.Core.0.h"
LLM_EXPORT namespace llm:OS::Media::Devices::Core
{
    struct __declspec(empty_bases) ICameraIntrinsics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraIntrinsics>
    {
        ICameraIntrinsics(std::nullptr_t = nullptr) noexcept {}
        ICameraIntrinsics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraIntrinsics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraIntrinsics2>
    {
        ICameraIntrinsics2(std::nullptr_t = nullptr) noexcept {}
        ICameraIntrinsics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraIntrinsicsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICameraIntrinsicsFactory>
    {
        ICameraIntrinsicsFactory(std::nullptr_t = nullptr) noexcept {}
        ICameraIntrinsicsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDepthCorrelatedCoordinateMapper :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDepthCorrelatedCoordinateMapper>,
        impl::require<llm:OS::Media::Devices::Core::IDepthCorrelatedCoordinateMapper, llm:OS::Foundation::IClosable>
    {
        IDepthCorrelatedCoordinateMapper(std::nullptr_t = nullptr) noexcept {}
        IDepthCorrelatedCoordinateMapper(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameControlCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameControlCapabilities>
    {
        IFrameControlCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameControlCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameControlCapabilities2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameControlCapabilities2>
    {
        IFrameControlCapabilities2(std::nullptr_t = nullptr) noexcept {}
        IFrameControlCapabilities2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameController>
    {
        IFrameController(std::nullptr_t = nullptr) noexcept {}
        IFrameController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameController2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameController2>
    {
        IFrameController2(std::nullptr_t = nullptr) noexcept {}
        IFrameController2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameExposureCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameExposureCapabilities>
    {
        IFrameExposureCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameExposureCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameExposureCompensationCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameExposureCompensationCapabilities>
    {
        IFrameExposureCompensationCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameExposureCompensationCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameExposureCompensationControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameExposureCompensationControl>
    {
        IFrameExposureCompensationControl(std::nullptr_t = nullptr) noexcept {}
        IFrameExposureCompensationControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameExposureControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameExposureControl>
    {
        IFrameExposureControl(std::nullptr_t = nullptr) noexcept {}
        IFrameExposureControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameFlashCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameFlashCapabilities>
    {
        IFrameFlashCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameFlashCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameFlashControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameFlashControl>
    {
        IFrameFlashControl(std::nullptr_t = nullptr) noexcept {}
        IFrameFlashControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameFocusCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameFocusCapabilities>
    {
        IFrameFocusCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameFocusCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameFocusControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameFocusControl>
    {
        IFrameFocusControl(std::nullptr_t = nullptr) noexcept {}
        IFrameFocusControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameIsoSpeedCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameIsoSpeedCapabilities>
    {
        IFrameIsoSpeedCapabilities(std::nullptr_t = nullptr) noexcept {}
        IFrameIsoSpeedCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameIsoSpeedControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFrameIsoSpeedControl>
    {
        IFrameIsoSpeedControl(std::nullptr_t = nullptr) noexcept {}
        IFrameIsoSpeedControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVariablePhotoSequenceController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVariablePhotoSequenceController>
    {
        IVariablePhotoSequenceController(std::nullptr_t = nullptr) noexcept {}
        IVariablePhotoSequenceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
