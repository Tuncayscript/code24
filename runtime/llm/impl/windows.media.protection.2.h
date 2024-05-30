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
#ifndef LLM_OS_Media_Protection_2_H
#define LLM_OS_Media_Protection_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Media.Protection.1.h"
LLM_EXPORT namespace llm:OS::Media::Protection
{
    struct ComponentLoadFailedEventHandler : llm:OS::Foundation::IUnknown
    {
        ComponentLoadFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ComponentLoadFailedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ComponentLoadFailedEventHandler(L lambda);
        template <typename F> ComponentLoadFailedEventHandler(F* function);
        template <typename O, typename M> ComponentLoadFailedEventHandler(O* object, M method);
        template <typename O, typename M> ComponentLoadFailedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ComponentLoadFailedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Protection::MediaProtectionManager const& sender, llm:OS::Media::Protection::ComponentLoadFailedEventArgs const& e) const;
    };
    struct RebootNeededEventHandler : llm:OS::Foundation::IUnknown
    {
        RebootNeededEventHandler(std::nullptr_t = nullptr) noexcept {}
        RebootNeededEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> RebootNeededEventHandler(L lambda);
        template <typename F> RebootNeededEventHandler(F* function);
        template <typename O, typename M> RebootNeededEventHandler(O* object, M method);
        template <typename O, typename M> RebootNeededEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> RebootNeededEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Protection::MediaProtectionManager const& sender) const;
    };
    struct ServiceRequestedEventHandler : llm:OS::Foundation::IUnknown
    {
        ServiceRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ServiceRequestedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ServiceRequestedEventHandler(L lambda);
        template <typename F> ServiceRequestedEventHandler(F* function);
        template <typename O, typename M> ServiceRequestedEventHandler(O* object, M method);
        template <typename O, typename M> ServiceRequestedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ServiceRequestedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Media::Protection::MediaProtectionManager const& sender, llm:OS::Media::Protection::ServiceRequestedEventArgs const& e) const;
    };
    struct __declspec(empty_bases) ComponentLoadFailedEventArgs : llm:OS::Media::Protection::IComponentLoadFailedEventArgs
    {
        ComponentLoadFailedEventArgs(std::nullptr_t) noexcept {}
        ComponentLoadFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IComponentLoadFailedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct ComponentRenewal
    {
        ComponentRenewal() = delete;
        static auto RenewSystemComponentsAsync(llm:OS::Media::Protection::RevocationAndRenewalInformation const& information);
    };
    struct __declspec(empty_bases) HdcpSession : llm:OS::Media::Protection::IHdcpSession
    {
        HdcpSession(std::nullptr_t) noexcept {}
        HdcpSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IHdcpSession(ptr, take_ownership_from_abi) {}
        HdcpSession();
    };
    struct __declspec(empty_bases) MediaProtectionManager : llm:OS::Media::Protection::IMediaProtectionManager
    {
        MediaProtectionManager(std::nullptr_t) noexcept {}
        MediaProtectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IMediaProtectionManager(ptr, take_ownership_from_abi) {}
        MediaProtectionManager();
    };
    struct __declspec(empty_bases) MediaProtectionPMPServer : llm:OS::Media::Protection::IMediaProtectionPMPServer
    {
        MediaProtectionPMPServer(std::nullptr_t) noexcept {}
        MediaProtectionPMPServer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IMediaProtectionPMPServer(ptr, take_ownership_from_abi) {}
        explicit MediaProtectionPMPServer(llm:OS::Foundation::Collections::IPropertySet const& pProperties);
    };
    struct __declspec(empty_bases) MediaProtectionServiceCompletion : llm:OS::Media::Protection::IMediaProtectionServiceCompletion
    {
        MediaProtectionServiceCompletion(std::nullptr_t) noexcept {}
        MediaProtectionServiceCompletion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IMediaProtectionServiceCompletion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectionCapabilities : llm:OS::Media::Protection::IProtectionCapabilities
    {
        ProtectionCapabilities(std::nullptr_t) noexcept {}
        ProtectionCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IProtectionCapabilities(ptr, take_ownership_from_abi) {}
        ProtectionCapabilities();
    };
    struct __declspec(empty_bases) RevocationAndRenewalInformation : llm:OS::Media::Protection::IRevocationAndRenewalInformation
    {
        RevocationAndRenewalInformation(std::nullptr_t) noexcept {}
        RevocationAndRenewalInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IRevocationAndRenewalInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RevocationAndRenewalItem : llm:OS::Media::Protection::IRevocationAndRenewalItem
    {
        RevocationAndRenewalItem(std::nullptr_t) noexcept {}
        RevocationAndRenewalItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IRevocationAndRenewalItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServiceRequestedEventArgs : llm:OS::Media::Protection::IServiceRequestedEventArgs,
        impl::require<ServiceRequestedEventArgs, llm:OS::Media::Protection::IServiceRequestedEventArgs2>
    {
        ServiceRequestedEventArgs(std::nullptr_t) noexcept {}
        ServiceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Protection::IServiceRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
