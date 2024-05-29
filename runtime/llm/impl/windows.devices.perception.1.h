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
#ifndef LLM_OS_Devices_Perception_1_H
#define LLM_OS_Devices_Perception_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Perception.0.h"
LLM_EXPORT namespace llm::OS::Devices::Perception
{
    struct __declspec(empty_bases) IKnownCameraIntrinsicsPropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownCameraIntrinsicsPropertiesStatics>
    {
        IKnownCameraIntrinsicsPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownCameraIntrinsicsPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionColorFrameSourcePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionColorFrameSourcePropertiesStatics>
    {
        IKnownPerceptionColorFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionColorFrameSourcePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionDepthFrameSourcePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionDepthFrameSourcePropertiesStatics>
    {
        IKnownPerceptionDepthFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionDepthFrameSourcePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionFrameSourcePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionFrameSourcePropertiesStatics>
    {
        IKnownPerceptionFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionFrameSourcePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionFrameSourcePropertiesStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionFrameSourcePropertiesStatics2>
    {
        IKnownPerceptionFrameSourcePropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionFrameSourcePropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionInfraredFrameSourcePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionInfraredFrameSourcePropertiesStatics>
    {
        IKnownPerceptionInfraredFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionInfraredFrameSourcePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionVideoFrameSourcePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionVideoFrameSourcePropertiesStatics>
    {
        IKnownPerceptionVideoFrameSourcePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionVideoFrameSourcePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownPerceptionVideoProfilePropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionVideoProfilePropertiesStatics>
    {
        IKnownPerceptionVideoProfilePropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionVideoProfilePropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrame>,
        impl::require<llm::OS::Devices::Perception::IPerceptionColorFrame, llm::OS::Foundation::IClosable>
    {
        IPerceptionColorFrame(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameArrivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameArrivedEventArgs>
    {
        IPerceptionColorFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameReader>,
        impl::require<llm::OS::Devices::Perception::IPerceptionColorFrameReader, llm::OS::Foundation::IClosable>
    {
        IPerceptionColorFrameReader(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSource>
    {
        IPerceptionColorFrameSource(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSource2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSource2>
    {
        IPerceptionColorFrameSource2(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSourceAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSourceAddedEventArgs>
    {
        IPerceptionColorFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSourceRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSourceRemovedEventArgs>
    {
        IPerceptionColorFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSourceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSourceStatics>
    {
        IPerceptionColorFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionColorFrameSourceWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionColorFrameSourceWatcher>
    {
        IPerceptionColorFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
        IPerceptionColorFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionControlSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionControlSession>,
        impl::require<llm::OS::Devices::Perception::IPerceptionControlSession, llm::OS::Foundation::IClosable>
    {
        IPerceptionControlSession(std::nullptr_t = nullptr) noexcept {}
        IPerceptionControlSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthCorrelatedCameraIntrinsics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthCorrelatedCameraIntrinsics>
    {
        IPerceptionDepthCorrelatedCameraIntrinsics(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthCorrelatedCameraIntrinsics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthCorrelatedCoordinateMapper :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthCorrelatedCoordinateMapper>
    {
        IPerceptionDepthCorrelatedCoordinateMapper(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthCorrelatedCoordinateMapper(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrame>,
        impl::require<llm::OS::Devices::Perception::IPerceptionDepthFrame, llm::OS::Foundation::IClosable>
    {
        IPerceptionDepthFrame(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameArrivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameArrivedEventArgs>
    {
        IPerceptionDepthFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameReader>,
        impl::require<llm::OS::Devices::Perception::IPerceptionDepthFrameReader, llm::OS::Foundation::IClosable>
    {
        IPerceptionDepthFrameReader(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSource>
    {
        IPerceptionDepthFrameSource(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSource2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSource2>
    {
        IPerceptionDepthFrameSource2(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSourceAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSourceAddedEventArgs>
    {
        IPerceptionDepthFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSourceRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSourceRemovedEventArgs>
    {
        IPerceptionDepthFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSourceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSourceStatics>
    {
        IPerceptionDepthFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionDepthFrameSourceWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionDepthFrameSourceWatcher>
    {
        IPerceptionDepthFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
        IPerceptionDepthFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameSourcePropertiesChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameSourcePropertiesChangedEventArgs>
    {
        IPerceptionFrameSourcePropertiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameSourcePropertiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameSourcePropertyChangeResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameSourcePropertyChangeResult>
    {
        IPerceptionFrameSourcePropertyChangeResult(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameSourcePropertyChangeResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrame>,
        impl::require<llm::OS::Devices::Perception::IPerceptionInfraredFrame, llm::OS::Foundation::IClosable>
    {
        IPerceptionInfraredFrame(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameArrivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameArrivedEventArgs>
    {
        IPerceptionInfraredFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameReader>,
        impl::require<llm::OS::Devices::Perception::IPerceptionInfraredFrameReader, llm::OS::Foundation::IClosable>
    {
        IPerceptionInfraredFrameReader(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSource :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSource>
    {
        IPerceptionInfraredFrameSource(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSource2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSource2>
    {
        IPerceptionInfraredFrameSource2(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSourceAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSourceAddedEventArgs>
    {
        IPerceptionInfraredFrameSourceAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSourceAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSourceRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSourceRemovedEventArgs>
    {
        IPerceptionInfraredFrameSourceRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSourceRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSourceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSourceStatics>
    {
        IPerceptionInfraredFrameSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionInfraredFrameSourceWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionInfraredFrameSourceWatcher>
    {
        IPerceptionInfraredFrameSourceWatcher(std::nullptr_t = nullptr) noexcept {}
        IPerceptionInfraredFrameSourceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionVideoProfile :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionVideoProfile>
    {
        IPerceptionVideoProfile(std::nullptr_t = nullptr) noexcept {}
        IPerceptionVideoProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
