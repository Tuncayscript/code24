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
#ifndef LLM_OS_ApplicationModel_Resources_Core_2_H
#define LLM_OS_ApplicationModel_Resources_Core_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.ApplicationModel.Resources.Core.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Resources::Core
{
    struct ResourceLayoutInfo
    {
        uint32_t MajorVersion;
        uint32_t MinorVersion;
        uint32_t ResourceSubtreeCount;
        uint32_t NamedResourceCount;
        int32_t Checksum;
    };
    inline bool operator==(ResourceLayoutInfo const& left, ResourceLayoutInfo const& right) noexcept
    {
        return left.MajorVersion == right.MajorVersion && left.MinorVersion == right.MinorVersion && left.ResourceSubtreeCount == right.ResourceSubtreeCount && left.NamedResourceCount == right.NamedResourceCount && left.Checksum == right.Checksum;
    }
    inline bool operator!=(ResourceLayoutInfo const& left, ResourceLayoutInfo const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) NamedResource : llm::OS::ApplicationModel::Resources::Core::INamedResource
    {
        NamedResource(std::nullptr_t) noexcept {}
        NamedResource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::INamedResource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceCandidate : llm::OS::ApplicationModel::Resources::Core::IResourceCandidate,
        impl::require<ResourceCandidate, llm::OS::ApplicationModel::Resources::Core::IResourceCandidate2, llm::OS::ApplicationModel::Resources::Core::IResourceCandidate3>
    {
        ResourceCandidate(std::nullptr_t) noexcept {}
        ResourceCandidate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::IResourceCandidate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceCandidateVectorView : llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Core::ResourceCandidate>
    {
        ResourceCandidateVectorView(std::nullptr_t) noexcept {}
        ResourceCandidateVectorView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Core::ResourceCandidate>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceContext : llm::OS::ApplicationModel::Resources::Core::IResourceContext
    {
        ResourceContext(std::nullptr_t) noexcept {}
        ResourceContext(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::IResourceContext(ptr, take_ownership_from_abi) {}
        ResourceContext();
        static auto CreateMatchingContext(param::iterable<llm::OS::ApplicationModel::Resources::Core::ResourceQualifier> const& result);
        static auto GetForCurrentView();
        static auto SetGlobalQualifierValue(param::hstring const& key, param::hstring const& value);
        static auto ResetGlobalQualifierValues();
        static auto ResetGlobalQualifierValues(param::iterable<hstring> const& qualifierNames);
        static auto GetForViewIndependentUse();
        static auto SetGlobalQualifierValue(param::hstring const& key, param::hstring const& value, llm::OS::ApplicationModel::Resources::Core::ResourceQualifierPersistence const& persistence);
        static auto GetForUIContext(llm::OS::UI::UIContext const& context);
    };
    struct __declspec(empty_bases) ResourceContextLanguagesVectorView : llm::OS::Foundation::Collections::IVectorView<hstring>
    {
        ResourceContextLanguagesVectorView(std::nullptr_t) noexcept {}
        ResourceContextLanguagesVectorView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<hstring>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceManager : llm::OS::ApplicationModel::Resources::Core::IResourceManager,
        impl::require<ResourceManager, llm::OS::ApplicationModel::Resources::Core::IResourceManager2>
    {
        ResourceManager(std::nullptr_t) noexcept {}
        ResourceManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::IResourceManager(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto IsResourceReference(param::hstring const& resourceReference);
    };
    struct __declspec(empty_bases) ResourceMap : llm::OS::ApplicationModel::Resources::Core::IResourceMap
    {
        ResourceMap(std::nullptr_t) noexcept {}
        ResourceMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::IResourceMap(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceMapIterator : llm::OS::Foundation::Collections::IIterator<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::ApplicationModel::Resources::Core::NamedResource>>
    {
        ResourceMapIterator(std::nullptr_t) noexcept {}
        ResourceMapIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IIterator<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::ApplicationModel::Resources::Core::NamedResource>>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceMapMapView : llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Resources::Core::ResourceMap>
    {
        ResourceMapMapView(std::nullptr_t) noexcept {}
        ResourceMapMapView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::ApplicationModel::Resources::Core::ResourceMap>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceMapMapViewIterator : llm::OS::Foundation::Collections::IIterator<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::ApplicationModel::Resources::Core::ResourceMap>>
    {
        ResourceMapMapViewIterator(std::nullptr_t) noexcept {}
        ResourceMapMapViewIterator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IIterator<llm::OS::Foundation::Collections::IKeyValuePair<hstring, llm::OS::ApplicationModel::Resources::Core::ResourceMap>>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceQualifier : llm::OS::ApplicationModel::Resources::Core::IResourceQualifier
    {
        ResourceQualifier(std::nullptr_t) noexcept {}
        ResourceQualifier(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Resources::Core::IResourceQualifier(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceQualifierMapView : llm::OS::Foundation::Collections::IMapView<hstring, hstring>
    {
        ResourceQualifierMapView(std::nullptr_t) noexcept {}
        ResourceQualifierMapView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IMapView<hstring, hstring>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceQualifierObservableMap : llm::OS::Foundation::Collections::IObservableMap<hstring, hstring>
    {
        ResourceQualifierObservableMap(std::nullptr_t) noexcept {}
        ResourceQualifierObservableMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IObservableMap<hstring, hstring>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ResourceQualifierVectorView : llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Core::ResourceQualifier>
    {
        ResourceQualifierVectorView(std::nullptr_t) noexcept {}
        ResourceQualifierVectorView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Resources::Core::ResourceQualifier>(ptr, take_ownership_from_abi) {}
    };
}
#endif
