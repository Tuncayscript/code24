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
#ifndef LLM_OS_Devices_Perception_Provider_1_H
#define LLM_OS_Devices_Perception_Provider_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Perception.Provider.0.h"
LLM_EXPORT namespace llm::OS::Devices::Perception::Provider
{
    struct __declspec(empty_bases) IKnownPerceptionFrameKindStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownPerceptionFrameKindStatics>
    {
        IKnownPerceptionFrameKindStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownPerceptionFrameKindStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionControlGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionControlGroup>
    {
        IPerceptionControlGroup(std::nullptr_t = nullptr) noexcept {}
        IPerceptionControlGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionControlGroupFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionControlGroupFactory>
    {
        IPerceptionControlGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPerceptionControlGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionCorrelation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionCorrelation>
    {
        IPerceptionCorrelation(std::nullptr_t = nullptr) noexcept {}
        IPerceptionCorrelation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionCorrelationFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionCorrelationFactory>
    {
        IPerceptionCorrelationFactory(std::nullptr_t = nullptr) noexcept {}
        IPerceptionCorrelationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionCorrelationGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionCorrelationGroup>
    {
        IPerceptionCorrelationGroup(std::nullptr_t = nullptr) noexcept {}
        IPerceptionCorrelationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionCorrelationGroupFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionCorrelationGroupFactory>
    {
        IPerceptionCorrelationGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPerceptionCorrelationGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFaceAuthenticationGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFaceAuthenticationGroup>
    {
        IPerceptionFaceAuthenticationGroup(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFaceAuthenticationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFaceAuthenticationGroupFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFaceAuthenticationGroupFactory>
    {
        IPerceptionFaceAuthenticationGroupFactory(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFaceAuthenticationGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrame>
    {
        IPerceptionFrame(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameProvider>,
        impl::require<llm::OS::Devices::Perception::Provider::IPerceptionFrameProvider, llm::OS::Foundation::IClosable>
    {
        IPerceptionFrameProvider(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameProviderInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameProviderInfo>
    {
        IPerceptionFrameProviderInfo(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameProviderInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameProviderManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameProviderManager>,
        impl::require<llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager, llm::OS::Foundation::IClosable>
    {
        IPerceptionFrameProviderManager(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameProviderManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionFrameProviderManagerServiceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionFrameProviderManagerServiceStatics>
    {
        IPerceptionFrameProviderManagerServiceStatics(std::nullptr_t = nullptr) noexcept {}
        IPerceptionFrameProviderManagerServiceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionPropertyChangeRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionPropertyChangeRequest>
    {
        IPerceptionPropertyChangeRequest(std::nullptr_t = nullptr) noexcept {}
        IPerceptionPropertyChangeRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionVideoFrameAllocator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionVideoFrameAllocator>,
        impl::require<llm::OS::Devices::Perception::Provider::IPerceptionVideoFrameAllocator, llm::OS::Foundation::IClosable>
    {
        IPerceptionVideoFrameAllocator(std::nullptr_t = nullptr) noexcept {}
        IPerceptionVideoFrameAllocator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPerceptionVideoFrameAllocatorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPerceptionVideoFrameAllocatorFactory>
    {
        IPerceptionVideoFrameAllocatorFactory(std::nullptr_t = nullptr) noexcept {}
        IPerceptionVideoFrameAllocatorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
