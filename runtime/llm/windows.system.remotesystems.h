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
#ifndef LLM_OS_System_RemoteSystems_H
#define LLM_OS_System_RemoteSystems_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.ApplicationModel.AppService.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.System.RemoteSystems.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IKnownRemoteSystemCapabilitiesStatics<D>::AppService() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics)->get_AppService(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IKnownRemoteSystemCapabilitiesStatics<D>::LaunchUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics)->get_LaunchUri(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IKnownRemoteSystemCapabilitiesStatics<D>::RemoteSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics)->get_RemoteSession(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IKnownRemoteSystemCapabilitiesStatics<D>::SpatialEntity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics)->get_SpatialEntity(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystem<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystem<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystem<D>::Kind() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem)->get_Kind(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemStatus) consume_Windows_System_RemoteSystems_IRemoteSystem<D>::Status() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystem<D>::IsAvailableByProximity() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem)->get_IsAvailableByProximity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystem2<D>::IsAvailableBySpatialProximity() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem2)->get_IsAvailableBySpatialProximity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystem2<D>::GetCapabilitySupportedAsync(param::hstring const& capabilityName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem2)->GetCapabilitySupportedAsync(*(void**)(&capabilityName), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystem3<D>::ManufacturerDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem3)->get_ManufacturerDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystem3<D>::ModelDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem3)->get_ModelDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemPlatform) consume_Windows_System_RemoteSystems_IRemoteSystem4<D>::Platform() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemPlatform value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem4)->get_Platform(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::System::RemoteSystems::RemoteSystemApp>) consume_Windows_System_RemoteSystems_IRemoteSystem5<D>::Apps() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem5)->get_Apps(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::System::RemoteSystems::RemoteSystemApp>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_RemoteSystems_IRemoteSystem6<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystem6)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystem) consume_Windows_System_RemoteSystems_IRemoteSystemAddedEventArgs<D>::RemoteSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAddedEventArgs)->get_RemoteSystem(&value));
        return llm::OS::System::RemoteSystems::RemoteSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemApp<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemApp<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystemApp<D>::IsAvailableByProximity() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp)->get_IsAvailableByProximity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystemApp<D>::IsAvailableBySpatialProximity() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp)->get_IsAvailableBySpatialProximity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, hstring>) consume_Windows_System_RemoteSystems_IRemoteSystemApp<D>::Attributes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp)->get_Attributes(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_RemoteSystems_IRemoteSystemApp2<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp2)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemApp2<D>::ConnectionToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemApp2)->get_ConnectionToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_RemoteSystems_IRemoteSystemAppRegistration<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_System_RemoteSystems_IRemoteSystemAppRegistration<D>::Attributes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration)->get_Attributes(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemAppRegistration<D>::SaveAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration)->SaveAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemAppRegistration) consume_Windows_System_RemoteSystems_IRemoteSystemAppRegistrationStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAppRegistrationStatics)->GetDefault(&result));
        return llm::OS::System::RemoteSystems::RemoteSystemAppRegistration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemAppRegistration) consume_Windows_System_RemoteSystems_IRemoteSystemAppRegistrationStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAppRegistrationStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemAppRegistration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind) consume_Windows_System_RemoteSystems_IRemoteSystemAuthorizationKindFilter<D>::RemoteSystemAuthorizationKind() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter)->get_RemoteSystemAuthorizationKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKindFilter) consume_Windows_System_RemoteSystems_IRemoteSystemAuthorizationKindFilterFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& remoteSystemAuthorizationKind) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilterFactory)->Create(static_cast<int32_t>(remoteSystemAuthorizationKind), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKindFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionInfo<D>::IsProximal() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfo)->get_IsProximal(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemConnectionInfo) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionInfoStatics<D>::TryCreateFromAppServiceConnection(llm::OS::ApplicationModel::AppService::AppServiceConnection const& connection) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfoStatics)->TryCreateFromAppServiceConnection(*(void**)(&connection), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemConnectionInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystem) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequest<D>::RemoteSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest)->get_RemoteSystem(&value));
        return llm::OS::System::RemoteSystems::RemoteSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemApp) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequest2<D>::RemoteSystemApp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest2)->get_RemoteSystemApp(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemApp{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequest3<D>::ConnectionToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest3)->get_ConnectionToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequestFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystem const& remoteSystem) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestFactory)->Create(*(void**)(&remoteSystem), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequestStatics<D>::CreateForApp(llm::OS::System::RemoteSystems::RemoteSystemApp const& remoteSystemApp) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics)->CreateForApp(*(void**)(&remoteSystemApp), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequestStatics2<D>::CreateFromConnectionToken(param::hstring const& connectionToken) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics2)->CreateFromConnectionToken(*(void**)(&connectionToken), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest) consume_Windows_System_RemoteSystems_IRemoteSystemConnectionRequestStatics2<D>::CreateFromConnectionTokenForUser(llm::OS::System::User const& user, param::hstring const& connectionToken) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics2)->CreateFromConnectionTokenForUser(*(void**)(&user), *(void**)(&connectionToken), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType) consume_Windows_System_RemoteSystems_IRemoteSystemDiscoveryTypeFilter<D>::RemoteSystemDiscoveryType() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter)->get_RemoteSystemDiscoveryType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter) consume_Windows_System_RemoteSystems_IRemoteSystemDiscoveryTypeFilterFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType const& discoveryType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory)->Create(static_cast<int32_t>(discoveryType), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_RemoteSystems_IRemoteSystemKindFilter<D>::RemoteSystemKinds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindFilter)->get_RemoteSystemKinds(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemKindFilter) consume_Windows_System_RemoteSystems_IRemoteSystemKindFilterFactory<D>::Create(param::iterable<hstring> const& remoteSystemKinds) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindFilterFactory)->Create(*(void**)(&remoteSystemKinds), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemKindFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics<D>::Phone() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics)->get_Phone(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics<D>::Hub() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics)->get_Hub(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics<D>::Holographic() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics)->get_Holographic(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics<D>::Desktop() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics)->get_Desktop(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics<D>::Xbox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics)->get_Xbox(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics2<D>::Iot() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2)->get_Iot(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics2<D>::Tablet() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2)->get_Tablet(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemKindStatics2<D>::Laptop() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2)->get_Laptop(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemRemovedEventArgs<D>::RemoteSystemId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs)->get_RemoteSystemId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::ControllerDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->get_ControllerDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::Disconnected(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSession, llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->add_Disconnected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::Disconnected_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::Disconnected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSession, llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Disconnected_revoker>(this, Disconnected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::Disconnected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->remove_Disconnected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::CreateParticipantWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->CreateParticipantWatcher(&result));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemSession<D>::SendInvitationAsync(llm::OS::System::RemoteSystems::RemoteSystem const& invitee) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSession)->SendInvitationAsync(*(void**)(&invitee), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionInfo) consume_Windows_System_RemoteSystems_IRemoteSystemSessionAddedEventArgs<D>::SessionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs)->get_SessionInfo(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::JoinRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionController, llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionController)->add_JoinRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::JoinRequested_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::JoinRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionController, llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, JoinRequested_revoker>(this, JoinRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::JoinRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionController)->remove_JoinRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::RemoveParticipantAsync(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant const& pParticipant) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionController)->RemoveParticipantAsync(*(void**)(&pParticipant), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionCreationResult>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionController<D>::CreateSessionAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionController)->CreateSessionAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionController) consume_Windows_System_RemoteSystems_IRemoteSystemSessionControllerFactory<D>::CreateController(param::hstring const& displayName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionControllerFactory)->CreateController(*(void**)(&displayName), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionController) consume_Windows_System_RemoteSystems_IRemoteSystemSessionControllerFactory<D>::CreateController(param::hstring const& displayName, llm::OS::System::RemoteSystems::RemoteSystemSessionOptions const& options) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionControllerFactory)->CreateControllerWithSessionOptions(*(void**)(&displayName), *(void**)(&options), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionController{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionCreationStatus) consume_Windows_System_RemoteSystems_IRemoteSystemSessionCreationResult<D>::Status() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemSessionCreationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionCreationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSession) consume_Windows_System_RemoteSystems_IRemoteSystemSessionCreationResult<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionCreationResult)->get_Session(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedReason) consume_Windows_System_RemoteSystems_IRemoteSystemSessionDisconnectedEventArgs<D>::Reason() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInfo<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInfo<D>::ControllerDisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo)->get_ControllerDisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinResult>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInfo<D>::JoinAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo)->JoinAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystem) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitation<D>::Sender() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitation)->get_Sender(&value));
        return llm::OS::System::RemoteSystems::RemoteSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionInfo) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitation<D>::SessionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitation)->get_SessionInfo(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitationListener<D>::InvitationReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationListener, llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener)->add_InvitationReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitationListener<D>::InvitationReceived_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitationListener<D>::InvitationReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationListener, llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, InvitationReceived_revoker>(this, InvitationReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitationListener<D>::InvitationReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener)->remove_InvitationReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionInvitation) consume_Windows_System_RemoteSystems_IRemoteSystemSessionInvitationReceivedEventArgs<D>::Invitation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs)->get_Invitation(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionInvitation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinRequest<D>::Participant() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest)->get_Participant(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinRequest<D>::Accept() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest)->Accept());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequest) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinRequestedEventArgs<D>::JoinRequest() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs)->get_JoinRequest(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinRequestedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionJoinStatus) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinResult<D>::Status() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemSessionJoinStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSession) consume_Windows_System_RemoteSystems_IRemoteSystemSessionJoinResult<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinResult)->get_Session(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSession) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::Session() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->get_Session(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::BroadcastValueSetAsync(llm::OS::Foundation::Collections::ValueSet const& messageData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->BroadcastValueSetAsync(*(void**)(&messageData), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::SendValueSetAsync(llm::OS::Foundation::Collections::ValueSet const& messageData, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant const& participant) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->SendValueSetAsync(*(void**)(&messageData), *(void**)(&participant), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::SendValueSetToParticipantsAsync(llm::OS::Foundation::Collections::ValueSet const& messageData, param::async_iterable<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant> const& participants) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->SendValueSetToParticipantsAsync(*(void**)(&messageData), *(void**)(&participants), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::ValueSetReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel, llm::OS::System::RemoteSystems::RemoteSystemSessionValueSetReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->add_ValueSetReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::ValueSetReceived_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::ValueSetReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel, llm::OS::System::RemoteSystems::RemoteSystemSessionValueSetReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ValueSetReceived_revoker>(this, ValueSetReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannel<D>::ValueSetReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel)->remove_ValueSetReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannelFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannelFactory)->Create(*(void**)(&session), *(void**)(&channelName), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel) consume_Windows_System_RemoteSystems_IRemoteSystemSessionMessageChannelFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName, llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannelReliability const& reliability) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannelFactory)->CreateWithReliability(*(void**)(&session), *(void**)(&channelName), static_cast<int32_t>(reliability), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystemSessionOptions<D>::IsInviteOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionOptions)->get_IsInviteOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionOptions<D>::IsInviteOnly(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionOptions)->put_IsInviteOnly(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystem) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipant<D>::RemoteSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipant)->get_RemoteSystem(&value));
        return llm::OS::System::RemoteSystems::RemoteSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipant<D>::GetHostNames() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipant)->GetHostNames(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantAddedEventArgs<D>::Participant() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs)->get_Participant(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantRemovedEventArgs<D>::Participant() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs)->get_Participant(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcherStatus) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Status() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Added_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Removed_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::EnumerationCompleted_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionParticipantWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionInfo) consume_Windows_System_RemoteSystems_IRemoteSystemSessionRemovedEventArgs<D>::SessionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs)->get_SessionInfo(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemSessionStatics<D>::CreateWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionStatics)->CreateWatcher(&result));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionInfo) consume_Windows_System_RemoteSystems_IRemoteSystemSessionUpdatedEventArgs<D>::SessionInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs)->get_SessionInfo(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant) consume_Windows_System_RemoteSystems_IRemoteSystemSessionValueSetReceivedEventArgs<D>::Sender() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs)->get_Sender(&value));
        return llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_System_RemoteSystems_IRemoteSystemSessionValueSetReceivedEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs)->get_Message(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemSessionWatcherStatus) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Status() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemSessionWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Added_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionUpdatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Updated_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Removed_revoker consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemSessionWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystem>) consume_Windows_System_RemoteSystems_IRemoteSystemStatics<D>::FindByHostNameAsync(llm::OS::Networking::HostName const& hostName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics)->FindByHostNameAsync(*(void**)(&hostName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystem>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemStatics<D>::CreateWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics)->CreateWatcher(&result));
        return llm::OS::System::RemoteSystems::RemoteSystemWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemStatics<D>::CreateWatcher(param::iterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const& filters) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics)->CreateWatcherWithFilters(*(void**)(&filters), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemAccessStatus>) consume_Windows_System_RemoteSystems_IRemoteSystemStatics<D>::RequestAccessAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics)->RequestAccessAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemAccessStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteSystems_IRemoteSystemStatics2<D>::IsAuthorizationKindEnabled(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& kind) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics2)->IsAuthorizationKindEnabled(static_cast<int32_t>(kind), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemStatics3<D>::CreateWatcherForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics3)->CreateWatcherForUser(*(void**)(&user), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWatcher) consume_Windows_System_RemoteSystems_IRemoteSystemStatics3<D>::CreateWatcherForUser(llm::OS::System::User const& user, param::iterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const& filters) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatics3)->CreateWatcherWithFiltersForUser(*(void**)(&user), *(void**)(&filters), &result));
        return llm::OS::System::RemoteSystems::RemoteSystemWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemStatusType) consume_Windows_System_RemoteSystems_IRemoteSystemStatusTypeFilter<D>::RemoteSystemStatusType() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemStatusType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter)->get_RemoteSystemStatusType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemStatusTypeFilter) consume_Windows_System_RemoteSystems_IRemoteSystemStatusTypeFilterFactory<D>::Create(llm::OS::System::RemoteSystems::RemoteSystemStatusType const& remoteSystemStatusType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory)->Create(static_cast<int32_t>(remoteSystemStatusType), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemStatusTypeFilter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystem) consume_Windows_System_RemoteSystems_IRemoteSystemUpdatedEventArgs<D>::RemoteSystem() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs)->get_RemoteSystem(&value));
        return llm::OS::System::RemoteSystems::RemoteSystem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->add_RemoteSystemAdded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemAdded_revoker consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RemoteSystemAdded_revoker>(this, RemoteSystemAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemAdded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->remove_RemoteSystemAdded(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemUpdatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->add_RemoteSystemUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemUpdated_revoker consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RemoteSystemUpdated_revoker>(this, RemoteSystemUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemUpdated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->remove_RemoteSystemUpdated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->add_RemoteSystemRemoved(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemRemoved_revoker consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RemoteSystemRemoved_revoker>(this, RemoteSystemRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher<D>::RemoteSystemRemoved(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher)->remove_RemoteSystemRemoved(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemEnumerationCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher2)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::EnumerationCompleted_revoker consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemEnumerationCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher2)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::ErrorOccurred(llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemWatcherErrorOccurredEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher2)->add_ErrorOccurred(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::ErrorOccurred_revoker consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::ErrorOccurred(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemWatcherErrorOccurredEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ErrorOccurred_revoker>(this, ErrorOccurred(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher2<D>::ErrorOccurred(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher2)->remove_ErrorOccurred(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_System_RemoteSystems_IRemoteSystemWatcher3<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcher3)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWatcherError) consume_Windows_System_RemoteSystems_IRemoteSystemWatcherErrorOccurredEventArgs<D>::Error() const
    {
        llm::OS::System::RemoteSystems::RemoteSystemWatcherError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::WebAccount) consume_Windows_System_RemoteSystems_IRemoteSystemWebAccountFilter<D>::Account() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilter)->get_Account(&value));
        return llm::OS::Security::Credentials::WebAccount{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::RemoteSystems::RemoteSystemWebAccountFilter) consume_Windows_System_RemoteSystems_IRemoteSystemWebAccountFilterFactory<D>::Create(llm::OS::Security::Credentials::WebAccount const& account) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilterFactory)->Create(*(void**)(&account), &value));
        return llm::OS::System::RemoteSystems::RemoteSystemWebAccountFilter{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics> : produce_base<D, llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics>
    {
        int32_t __stdcall get_AppService(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppService());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LaunchUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LaunchUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpatialEntity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SpatialEntity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAvailableByProximity(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailableByProximity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem2>
    {
        int32_t __stdcall get_IsAvailableBySpatialProximity(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailableBySpatialProximity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCapabilitySupportedAsync(void* capabilityName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetCapabilitySupportedAsync(*reinterpret_cast<hstring const*>(&capabilityName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem3> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem3>
    {
        int32_t __stdcall get_ManufacturerDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ManufacturerDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ModelDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ModelDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem4> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem4>
    {
        int32_t __stdcall get_Platform(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemPlatform>(this->shim().Platform());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem5> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem5>
    {
        int32_t __stdcall get_Apps(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::System::RemoteSystems::RemoteSystemApp>>(this->shim().Apps());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystem6> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystem6>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemAddedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemAddedEventArgs>
    {
        int32_t __stdcall get_RemoteSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystem>(this->shim().RemoteSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemApp> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemApp>
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
        int32_t __stdcall get_IsAvailableByProximity(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailableByProximity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAvailableBySpatialProximity(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailableBySpatialProximity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Attributes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, hstring>>(this->shim().Attributes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemApp2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemApp2>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ConnectionToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Attributes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().Attributes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemAppRegistrationStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemAppRegistrationStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemAppRegistration>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemAppRegistration>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter>
    {
        int32_t __stdcall get_RemoteSystemAuthorizationKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind>(this->shim().RemoteSystemAuthorizationKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilterFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilterFactory>
    {
        int32_t __stdcall Create(int32_t remoteSystemAuthorizationKind, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKindFilter>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const*>(&remoteSystemAuthorizationKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfo> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfo>
    {
        int32_t __stdcall get_IsProximal(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsProximal());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfoStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfoStatics>
    {
        int32_t __stdcall TryCreateFromAppServiceConnection(void* connection, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemConnectionInfo>(this->shim().TryCreateFromAppServiceConnection(*reinterpret_cast<llm::OS::ApplicationModel::AppService::AppServiceConnection const*>(&connection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest>
    {
        int32_t __stdcall get_RemoteSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystem>(this->shim().RemoteSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest2>
    {
        int32_t __stdcall get_RemoteSystemApp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemApp>(this->shim().RemoteSystemApp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest3> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest3>
    {
        int32_t __stdcall get_ConnectionToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ConnectionToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestFactory>
    {
        int32_t __stdcall Create(void* remoteSystem, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystem const*>(&remoteSystem)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics>
    {
        int32_t __stdcall CreateForApp(void* remoteSystemApp, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest>(this->shim().CreateForApp(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemApp const*>(&remoteSystemApp)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics2>
    {
        int32_t __stdcall CreateFromConnectionToken(void* connectionToken, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest>(this->shim().CreateFromConnectionToken(*reinterpret_cast<hstring const*>(&connectionToken)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromConnectionTokenForUser(void* user, void* connectionToken, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest>(this->shim().CreateFromConnectionTokenForUser(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&connectionToken)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter>
    {
        int32_t __stdcall get_RemoteSystemDiscoveryType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType>(this->shim().RemoteSystemDiscoveryType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory>
    {
        int32_t __stdcall Create(int32_t discoveryType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType const*>(&discoveryType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs>
    {
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemFilter>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemKindFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemKindFilter>
    {
        int32_t __stdcall get_RemoteSystemKinds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().RemoteSystemKinds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemKindFilterFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemKindFilterFactory>
    {
        int32_t __stdcall Create(void* remoteSystemKinds, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemKindFilter>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&remoteSystemKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemKindStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemKindStatics>
    {
        int32_t __stdcall get_Phone(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Phone());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Hub(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Hub());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Holographic(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Holographic());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Desktop(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Desktop());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Xbox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Xbox());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2>
    {
        int32_t __stdcall get_Iot(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Iot());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Tablet(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Tablet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Laptop(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Laptop());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs>
    {
        int32_t __stdcall get_RemoteSystemId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemoteSystemId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSession> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSession>
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
        int32_t __stdcall get_ControllerDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ControllerDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Disconnected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Disconnected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSession, llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Disconnected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall CreateParticipantWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher>(this->shim().CreateParticipantWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendInvitationAsync(void* invitee, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SendInvitationAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystem const*>(&invitee)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs>
    {
        int32_t __stdcall get_SessionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionInfo>(this->shim().SessionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionController> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionController>
    {
        int32_t __stdcall add_JoinRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().JoinRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionController, llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_JoinRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().JoinRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RemoveParticipantAsync(void* pParticipant, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RemoveParticipantAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant const*>(&pParticipant)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSessionAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionCreationResult>>(this->shim().CreateSessionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionControllerFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionControllerFactory>
    {
        int32_t __stdcall CreateController(void* displayName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionController>(this->shim().CreateController(*reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateControllerWithSessionOptions(void* displayName, void* options, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionController>(this->shim().CreateController(*reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSessionOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionCreationResult> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionCreationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionCreationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ControllerDisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ControllerDisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall JoinAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinResult>>(this->shim().JoinAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitation> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitation>
    {
        int32_t __stdcall get_Sender(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystem>(this->shim().Sender());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SessionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionInfo>(this->shim().SessionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener>
    {
        int32_t __stdcall add_InvitationReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().InvitationReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationListener, llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InvitationReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvitationReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs>
    {
        int32_t __stdcall get_Invitation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitation>(this->shim().Invitation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest>
    {
        int32_t __stdcall get_Participant(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant>(this->shim().Participant());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Accept() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs>
    {
        int32_t __stdcall get_JoinRequest(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequest>(this->shim().JoinRequest());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinResult> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel>
    {
        int32_t __stdcall get_Session(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSession>(this->shim().Session());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall BroadcastValueSetAsync(void* messageData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().BroadcastValueSetAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&messageData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendValueSetAsync(void* messageData, void* participant, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SendValueSetAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&messageData), *reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant const*>(&participant)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendValueSetToParticipantsAsync(void* messageData, void* participants, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SendValueSetToParticipantsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&messageData), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant> const*>(&participants)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ValueSetReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ValueSetReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel, llm::OS::System::RemoteSystems::RemoteSystemSessionValueSetReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ValueSetReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValueSetReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannelFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannelFactory>
    {
        int32_t __stdcall Create(void* session, void* channelName, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSession const*>(&session), *reinterpret_cast<hstring const*>(&channelName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithReliability(void* session, void* channelName, int32_t reliability, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSession const*>(&session), *reinterpret_cast<hstring const*>(&channelName), *reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannelReliability const*>(&reliability)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionOptions> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionOptions>
    {
        int32_t __stdcall get_IsInviteOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInviteOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInviteOnly(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInviteOnly(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipant> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipant>
    {
        int32_t __stdcall get_RemoteSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystem>(this->shim().RemoteSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetHostNames(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>>(this->shim().GetHostNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs>
    {
        int32_t __stdcall get_Participant(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant>(this->shim().Participant());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs>
    {
        int32_t __stdcall get_Participant(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant>(this->shim().Participant());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher>
    {
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
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs>
    {
        int32_t __stdcall get_SessionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionInfo>(this->shim().SessionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionStatics>
    {
        int32_t __stdcall CreateWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs>
    {
        int32_t __stdcall get_SessionInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionInfo>(this->shim().SessionInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs>
    {
        int32_t __stdcall get_Sender(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant>(this->shim().Sender());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher>
    {
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
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher, llm::OS::System::RemoteSystems::RemoteSystemSessionRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics>
    {
        int32_t __stdcall FindByHostNameAsync(void* hostName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystem>>(this->shim().FindByHostNameAsync(*reinterpret_cast<llm::OS::Networking::HostName const*>(&hostName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherWithFilters(void* filters, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWatcher>(this->shim().CreateWatcher(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const*>(&filters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics2>
    {
        int32_t __stdcall IsAuthorizationKindEnabled(int32_t kind, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsAuthorizationKindEnabled(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics3> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemStatics3>
    {
        int32_t __stdcall CreateWatcherForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWatcher>(this->shim().CreateWatcherForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherWithFiltersForUser(void* user, void* filters, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWatcher>(this->shim().CreateWatcherForUser(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const*>(&filters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter>
    {
        int32_t __stdcall get_RemoteSystemStatusType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemStatusType>(this->shim().RemoteSystemStatusType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory>
    {
        int32_t __stdcall Create(int32_t remoteSystemStatusType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemStatusTypeFilter>(this->shim().Create(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemStatusType const*>(&remoteSystemStatusType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs>
    {
        int32_t __stdcall get_RemoteSystem(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystem>(this->shim().RemoteSystem());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher>
    {
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
        int32_t __stdcall add_RemoteSystemAdded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RemoteSystemAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemoteSystemAdded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemAdded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RemoteSystemUpdated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RemoteSystemUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemoteSystemUpdated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemUpdated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RemoteSystemRemoved(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RemoteSystemRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemoteSystemRemoved(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemRemoved(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher2> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher2>
    {
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemEnumerationCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ErrorOccurred(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ErrorOccurred(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::RemoteSystems::RemoteSystemWatcher, llm::OS::System::RemoteSystems::RemoteSystemWatcherErrorOccurredEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ErrorOccurred(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorOccurred(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher3> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcher3>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs>
    {
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWatcherError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilter> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilter>
    {
        int32_t __stdcall get_Account(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::WebAccount>(this->shim().Account());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilterFactory> : produce_base<D, llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilterFactory>
    {
        int32_t __stdcall Create(void* account, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::RemoteSystems::RemoteSystemWebAccountFilter>(this->shim().Create(*reinterpret_cast<llm::OS::Security::Credentials::WebAccount const*>(&account)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::RemoteSystems
{
    inline auto KnownRemoteSystemCapabilities::AppService()
    {
        return impl::call_factory_cast<hstring(*)(IKnownRemoteSystemCapabilitiesStatics const&), KnownRemoteSystemCapabilities, IKnownRemoteSystemCapabilitiesStatics>([](IKnownRemoteSystemCapabilitiesStatics const& f) { return f.AppService(); });
    }
    inline auto KnownRemoteSystemCapabilities::LaunchUri()
    {
        return impl::call_factory_cast<hstring(*)(IKnownRemoteSystemCapabilitiesStatics const&), KnownRemoteSystemCapabilities, IKnownRemoteSystemCapabilitiesStatics>([](IKnownRemoteSystemCapabilitiesStatics const& f) { return f.LaunchUri(); });
    }
    inline auto KnownRemoteSystemCapabilities::RemoteSession()
    {
        return impl::call_factory_cast<hstring(*)(IKnownRemoteSystemCapabilitiesStatics const&), KnownRemoteSystemCapabilities, IKnownRemoteSystemCapabilitiesStatics>([](IKnownRemoteSystemCapabilitiesStatics const& f) { return f.RemoteSession(); });
    }
    inline auto KnownRemoteSystemCapabilities::SpatialEntity()
    {
        return impl::call_factory_cast<hstring(*)(IKnownRemoteSystemCapabilitiesStatics const&), KnownRemoteSystemCapabilities, IKnownRemoteSystemCapabilitiesStatics>([](IKnownRemoteSystemCapabilitiesStatics const& f) { return f.SpatialEntity(); });
    }
    inline auto RemoteSystem::FindByHostNameAsync(llm::OS::Networking::HostName const& hostName)
    {
        return impl::call_factory<RemoteSystem, IRemoteSystemStatics>([&](IRemoteSystemStatics const& f) { return f.FindByHostNameAsync(hostName); });
    }
    inline auto RemoteSystem::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::System::RemoteSystems::RemoteSystemWatcher(*)(IRemoteSystemStatics const&), RemoteSystem, IRemoteSystemStatics>([](IRemoteSystemStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto RemoteSystem::CreateWatcher(param::iterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const& filters)
    {
        return impl::call_factory<RemoteSystem, IRemoteSystemStatics>([&](IRemoteSystemStatics const& f) { return f.CreateWatcher(filters); });
    }
    inline auto RemoteSystem::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::System::RemoteSystems::RemoteSystemAccessStatus>(*)(IRemoteSystemStatics const&), RemoteSystem, IRemoteSystemStatics>([](IRemoteSystemStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto RemoteSystem::IsAuthorizationKindEnabled(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& kind)
    {
        return impl::call_factory<RemoteSystem, IRemoteSystemStatics2>([&](IRemoteSystemStatics2 const& f) { return f.IsAuthorizationKindEnabled(kind); });
    }
    inline auto RemoteSystem::CreateWatcherForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<RemoteSystem, IRemoteSystemStatics3>([&](IRemoteSystemStatics3 const& f) { return f.CreateWatcherForUser(user); });
    }
    inline auto RemoteSystem::CreateWatcherForUser(llm::OS::System::User const& user, param::iterable<llm::OS::System::RemoteSystems::IRemoteSystemFilter> const& filters)
    {
        return impl::call_factory<RemoteSystem, IRemoteSystemStatics3>([&](IRemoteSystemStatics3 const& f) { return f.CreateWatcherForUser(user, filters); });
    }
    inline auto RemoteSystemAppRegistration::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::System::RemoteSystems::RemoteSystemAppRegistration(*)(IRemoteSystemAppRegistrationStatics const&), RemoteSystemAppRegistration, IRemoteSystemAppRegistrationStatics>([](IRemoteSystemAppRegistrationStatics const& f) { return f.GetDefault(); });
    }
    inline auto RemoteSystemAppRegistration::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<RemoteSystemAppRegistration, IRemoteSystemAppRegistrationStatics>([&](IRemoteSystemAppRegistrationStatics const& f) { return f.GetForUser(user); });
    }
    inline RemoteSystemAuthorizationKindFilter::RemoteSystemAuthorizationKindFilter(llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& remoteSystemAuthorizationKind) :
        RemoteSystemAuthorizationKindFilter(impl::call_factory<RemoteSystemAuthorizationKindFilter, IRemoteSystemAuthorizationKindFilterFactory>([&](IRemoteSystemAuthorizationKindFilterFactory const& f) { return f.Create(remoteSystemAuthorizationKind); }))
    {
    }
    inline auto RemoteSystemConnectionInfo::TryCreateFromAppServiceConnection(llm::OS::ApplicationModel::AppService::AppServiceConnection const& connection)
    {
        return impl::call_factory<RemoteSystemConnectionInfo, IRemoteSystemConnectionInfoStatics>([&](IRemoteSystemConnectionInfoStatics const& f) { return f.TryCreateFromAppServiceConnection(connection); });
    }
    inline RemoteSystemConnectionRequest::RemoteSystemConnectionRequest(llm::OS::System::RemoteSystems::RemoteSystem const& remoteSystem) :
        RemoteSystemConnectionRequest(impl::call_factory<RemoteSystemConnectionRequest, IRemoteSystemConnectionRequestFactory>([&](IRemoteSystemConnectionRequestFactory const& f) { return f.Create(remoteSystem); }))
    {
    }
    inline auto RemoteSystemConnectionRequest::CreateForApp(llm::OS::System::RemoteSystems::RemoteSystemApp const& remoteSystemApp)
    {
        return impl::call_factory<RemoteSystemConnectionRequest, IRemoteSystemConnectionRequestStatics>([&](IRemoteSystemConnectionRequestStatics const& f) { return f.CreateForApp(remoteSystemApp); });
    }
    inline auto RemoteSystemConnectionRequest::CreateFromConnectionToken(param::hstring const& connectionToken)
    {
        return impl::call_factory<RemoteSystemConnectionRequest, IRemoteSystemConnectionRequestStatics2>([&](IRemoteSystemConnectionRequestStatics2 const& f) { return f.CreateFromConnectionToken(connectionToken); });
    }
    inline auto RemoteSystemConnectionRequest::CreateFromConnectionTokenForUser(llm::OS::System::User const& user, param::hstring const& connectionToken)
    {
        return impl::call_factory<RemoteSystemConnectionRequest, IRemoteSystemConnectionRequestStatics2>([&](IRemoteSystemConnectionRequestStatics2 const& f) { return f.CreateFromConnectionTokenForUser(user, connectionToken); });
    }
    inline RemoteSystemDiscoveryTypeFilter::RemoteSystemDiscoveryTypeFilter(llm::OS::System::RemoteSystems::RemoteSystemDiscoveryType const& discoveryType) :
        RemoteSystemDiscoveryTypeFilter(impl::call_factory<RemoteSystemDiscoveryTypeFilter, IRemoteSystemDiscoveryTypeFilterFactory>([&](IRemoteSystemDiscoveryTypeFilterFactory const& f) { return f.Create(discoveryType); }))
    {
    }
    inline RemoteSystemKindFilter::RemoteSystemKindFilter(param::iterable<hstring> const& remoteSystemKinds) :
        RemoteSystemKindFilter(impl::call_factory<RemoteSystemKindFilter, IRemoteSystemKindFilterFactory>([&](IRemoteSystemKindFilterFactory const& f) { return f.Create(remoteSystemKinds); }))
    {
    }
    inline auto RemoteSystemKinds::Phone()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics const&), RemoteSystemKinds, IRemoteSystemKindStatics>([](IRemoteSystemKindStatics const& f) { return f.Phone(); });
    }
    inline auto RemoteSystemKinds::Hub()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics const&), RemoteSystemKinds, IRemoteSystemKindStatics>([](IRemoteSystemKindStatics const& f) { return f.Hub(); });
    }
    inline auto RemoteSystemKinds::Holographic()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics const&), RemoteSystemKinds, IRemoteSystemKindStatics>([](IRemoteSystemKindStatics const& f) { return f.Holographic(); });
    }
    inline auto RemoteSystemKinds::Desktop()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics const&), RemoteSystemKinds, IRemoteSystemKindStatics>([](IRemoteSystemKindStatics const& f) { return f.Desktop(); });
    }
    inline auto RemoteSystemKinds::Xbox()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics const&), RemoteSystemKinds, IRemoteSystemKindStatics>([](IRemoteSystemKindStatics const& f) { return f.Xbox(); });
    }
    inline auto RemoteSystemKinds::Iot()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics2 const&), RemoteSystemKinds, IRemoteSystemKindStatics2>([](IRemoteSystemKindStatics2 const& f) { return f.Iot(); });
    }
    inline auto RemoteSystemKinds::Tablet()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics2 const&), RemoteSystemKinds, IRemoteSystemKindStatics2>([](IRemoteSystemKindStatics2 const& f) { return f.Tablet(); });
    }
    inline auto RemoteSystemKinds::Laptop()
    {
        return impl::call_factory_cast<hstring(*)(IRemoteSystemKindStatics2 const&), RemoteSystemKinds, IRemoteSystemKindStatics2>([](IRemoteSystemKindStatics2 const& f) { return f.Laptop(); });
    }
    inline auto RemoteSystemSession::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher(*)(IRemoteSystemSessionStatics const&), RemoteSystemSession, IRemoteSystemSessionStatics>([](IRemoteSystemSessionStatics const& f) { return f.CreateWatcher(); });
    }
    inline RemoteSystemSessionController::RemoteSystemSessionController(param::hstring const& displayName) :
        RemoteSystemSessionController(impl::call_factory<RemoteSystemSessionController, IRemoteSystemSessionControllerFactory>([&](IRemoteSystemSessionControllerFactory const& f) { return f.CreateController(displayName); }))
    {
    }
    inline RemoteSystemSessionController::RemoteSystemSessionController(param::hstring const& displayName, llm::OS::System::RemoteSystems::RemoteSystemSessionOptions const& options) :
        RemoteSystemSessionController(impl::call_factory<RemoteSystemSessionController, IRemoteSystemSessionControllerFactory>([&](IRemoteSystemSessionControllerFactory const& f) { return f.CreateController(displayName, options); }))
    {
    }
    inline RemoteSystemSessionInvitationListener::RemoteSystemSessionInvitationListener() :
        RemoteSystemSessionInvitationListener(impl::call_factory_cast<RemoteSystemSessionInvitationListener(*)(llm::OS::Foundation::IActivationFactory const&), RemoteSystemSessionInvitationListener>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RemoteSystemSessionInvitationListener>(); }))
    {
    }
    inline RemoteSystemSessionMessageChannel::RemoteSystemSessionMessageChannel(llm::OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName) :
        RemoteSystemSessionMessageChannel(impl::call_factory<RemoteSystemSessionMessageChannel, IRemoteSystemSessionMessageChannelFactory>([&](IRemoteSystemSessionMessageChannelFactory const& f) { return f.Create(session, channelName); }))
    {
    }
    inline RemoteSystemSessionMessageChannel::RemoteSystemSessionMessageChannel(llm::OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName, llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannelReliability const& reliability) :
        RemoteSystemSessionMessageChannel(impl::call_factory<RemoteSystemSessionMessageChannel, IRemoteSystemSessionMessageChannelFactory>([&](IRemoteSystemSessionMessageChannelFactory const& f) { return f.Create(session, channelName, reliability); }))
    {
    }
    inline RemoteSystemSessionOptions::RemoteSystemSessionOptions() :
        RemoteSystemSessionOptions(impl::call_factory_cast<RemoteSystemSessionOptions(*)(llm::OS::Foundation::IActivationFactory const&), RemoteSystemSessionOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<RemoteSystemSessionOptions>(); }))
    {
    }
    inline RemoteSystemStatusTypeFilter::RemoteSystemStatusTypeFilter(llm::OS::System::RemoteSystems::RemoteSystemStatusType const& remoteSystemStatusType) :
        RemoteSystemStatusTypeFilter(impl::call_factory<RemoteSystemStatusTypeFilter, IRemoteSystemStatusTypeFilterFactory>([&](IRemoteSystemStatusTypeFilterFactory const& f) { return f.Create(remoteSystemStatusType); }))
    {
    }
    inline RemoteSystemWebAccountFilter::RemoteSystemWebAccountFilter(llm::OS::Security::Credentials::WebAccount const& account) :
        RemoteSystemWebAccountFilter(impl::call_factory<RemoteSystemWebAccountFilter, IRemoteSystemWebAccountFilterFactory>([&](IRemoteSystemWebAccountFilterFactory const& f) { return f.Create(account); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::RemoteSystems::IKnownRemoteSystemCapabilitiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystem6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemApp2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemAppRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemAppRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequest3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemConnectionRequestStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemKindFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemKindFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemKindStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemKindStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionControllerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionJoinResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionMessageChannelFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipant> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemSessionWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWatcher2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWatcher3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::IRemoteSystemWebAccountFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::KnownRemoteSystemCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemAppRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemAuthorizationKindFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemConnectionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemEnumerationCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemKindFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemKinds> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionDisconnectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionInvitationReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionJoinResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionMessageChannel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipant> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionParticipantWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionValueSetReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemSessionWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemStatusTypeFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemWatcherErrorOccurredEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteSystems::RemoteSystemWebAccountFilter> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
