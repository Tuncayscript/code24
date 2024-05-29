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
#ifndef LLM_OS_Devices_Perception_Provider_2_H
#define LLM_OS_Devices_Perception_Provider_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Foundation.Numerics.1.h"
#include "llm/impl/Windows.Graphics.Imaging.1.h"
#include "llm/impl/Windows.Devices.Perception.Provider.1.h"
LLM_EXPORT namespace llm::OS::Devices::Perception::Provider
{
    struct PerceptionStartFaceAuthenticationHandler : llm::OS::Foundation::IUnknown
    {
        PerceptionStartFaceAuthenticationHandler(std::nullptr_t = nullptr) noexcept {}
        PerceptionStartFaceAuthenticationHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PerceptionStartFaceAuthenticationHandler(L lambda);
        template <typename F> PerceptionStartFaceAuthenticationHandler(F* function);
        template <typename O, typename M> PerceptionStartFaceAuthenticationHandler(O* object, M method);
        template <typename O, typename M> PerceptionStartFaceAuthenticationHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PerceptionStartFaceAuthenticationHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup const& sender) const;
    };
    struct PerceptionStopFaceAuthenticationHandler : llm::OS::Foundation::IUnknown
    {
        PerceptionStopFaceAuthenticationHandler(std::nullptr_t = nullptr) noexcept {}
        PerceptionStopFaceAuthenticationHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> PerceptionStopFaceAuthenticationHandler(L lambda);
        template <typename F> PerceptionStopFaceAuthenticationHandler(F* function);
        template <typename O, typename M> PerceptionStopFaceAuthenticationHandler(O* object, M method);
        template <typename O, typename M> PerceptionStopFaceAuthenticationHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> PerceptionStopFaceAuthenticationHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup const& sender) const;
    };
    struct KnownPerceptionFrameKind
    {
        KnownPerceptionFrameKind() = delete;
        [[nodiscard]] static auto Color();
        [[nodiscard]] static auto Depth();
        [[nodiscard]] static auto Infrared();
    };
    struct __declspec(empty_bases) PerceptionControlGroup : llm::OS::Devices::Perception::Provider::IPerceptionControlGroup
    {
        PerceptionControlGroup(std::nullptr_t) noexcept {}
        PerceptionControlGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionControlGroup(ptr, take_ownership_from_abi) {}
        explicit PerceptionControlGroup(param::iterable<hstring> const& ids);
    };
    struct __declspec(empty_bases) PerceptionCorrelation : llm::OS::Devices::Perception::Provider::IPerceptionCorrelation
    {
        PerceptionCorrelation(std::nullptr_t) noexcept {}
        PerceptionCorrelation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionCorrelation(ptr, take_ownership_from_abi) {}
        PerceptionCorrelation(param::hstring const& targetId, llm::OS::Foundation::Numerics::float3 const& position, llm::OS::Foundation::Numerics::quaternion const& orientation);
    };
    struct __declspec(empty_bases) PerceptionCorrelationGroup : llm::OS::Devices::Perception::Provider::IPerceptionCorrelationGroup
    {
        PerceptionCorrelationGroup(std::nullptr_t) noexcept {}
        PerceptionCorrelationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionCorrelationGroup(ptr, take_ownership_from_abi) {}
        explicit PerceptionCorrelationGroup(param::iterable<llm::OS::Devices::Perception::Provider::PerceptionCorrelation> const& relativeLocations);
    };
    struct __declspec(empty_bases) PerceptionFaceAuthenticationGroup : llm::OS::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup
    {
        PerceptionFaceAuthenticationGroup(std::nullptr_t) noexcept {}
        PerceptionFaceAuthenticationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup(ptr, take_ownership_from_abi) {}
        PerceptionFaceAuthenticationGroup(param::iterable<hstring> const& ids, llm::OS::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler const& startHandler, llm::OS::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler const& stopHandler);
    };
    struct __declspec(empty_bases) PerceptionFrame : llm::OS::Devices::Perception::Provider::IPerceptionFrame
    {
        PerceptionFrame(std::nullptr_t) noexcept {}
        PerceptionFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionFrameProviderInfo : llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderInfo
    {
        PerceptionFrameProviderInfo(std::nullptr_t) noexcept {}
        PerceptionFrameProviderInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderInfo(ptr, take_ownership_from_abi) {}
        PerceptionFrameProviderInfo();
    };
    struct PerceptionFrameProviderManagerService
    {
        PerceptionFrameProviderManagerService() = delete;
        static auto RegisterFrameProviderInfo(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionFrameProviderInfo const& frameProviderInfo);
        static auto UnregisterFrameProviderInfo(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionFrameProviderInfo const& frameProviderInfo);
        static auto RegisterFaceAuthenticationGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup const& faceAuthenticationGroup);
        static auto UnregisterFaceAuthenticationGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup const& faceAuthenticationGroup);
        static auto RegisterControlGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionControlGroup const& controlGroup);
        static auto UnregisterControlGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionControlGroup const& controlGroup);
        static auto RegisterCorrelationGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionCorrelationGroup const& correlationGroup);
        static auto UnregisterCorrelationGroup(llm::OS::Devices::Perception::Provider::IPerceptionFrameProviderManager const& manager, llm::OS::Devices::Perception::Provider::PerceptionCorrelationGroup const& correlationGroup);
        static auto UpdateAvailabilityForProvider(llm::OS::Devices::Perception::Provider::IPerceptionFrameProvider const& provider, bool available);
        static auto PublishFrameForProvider(llm::OS::Devices::Perception::Provider::IPerceptionFrameProvider const& provider, llm::OS::Devices::Perception::Provider::PerceptionFrame const& frame);
    };
    struct __declspec(empty_bases) PerceptionPropertyChangeRequest : llm::OS::Devices::Perception::Provider::IPerceptionPropertyChangeRequest
    {
        PerceptionPropertyChangeRequest(std::nullptr_t) noexcept {}
        PerceptionPropertyChangeRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionPropertyChangeRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PerceptionVideoFrameAllocator : llm::OS::Devices::Perception::Provider::IPerceptionVideoFrameAllocator
    {
        PerceptionVideoFrameAllocator(std::nullptr_t) noexcept {}
        PerceptionVideoFrameAllocator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Perception::Provider::IPerceptionVideoFrameAllocator(ptr, take_ownership_from_abi) {}
        PerceptionVideoFrameAllocator(uint32_t maxOutstandingFrameCountForWrite, llm::OS::Graphics::Imaging::BitmapPixelFormat const& format, llm::OS::Foundation::Size const& resolution, llm::OS::Graphics::Imaging::BitmapAlphaMode const& alpha);
    };
}
#endif
