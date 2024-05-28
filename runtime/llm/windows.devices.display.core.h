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
#ifndef LLM_OS_Devices_Display_Core_H
#define LLM_OS_Devices_Display_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Display.h"
#include "llm/impl/Windows.Devices.Display.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Display.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::Id() const
    {
        llm::OS::Graphics::DisplayAdapterId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::DeviceInterfacePath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_DeviceInterfacePath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::SourceCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_SourceCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::PciVendorId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_PciVendorId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::PciDeviceId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_PciDeviceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::PciSubSystemId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_PciSubSystemId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::PciRevision() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_PciRevision(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayAdapter<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapter)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayAdapter) consume_Windows_Devices_Display_Core_IDisplayAdapterStatics<D>::FromId(llm::OS::Graphics::DisplayAdapterId const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayAdapterStatics)->FromId(impl::bind_in(id), &result));
        return llm::OS::Devices::Display::Core::DisplayAdapter{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySource) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::CreateScanoutSource(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->CreateScanoutSource(*(void**)(&target), &result));
        return llm::OS::Devices::Display::Core::DisplaySource{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySurface) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::CreatePrimary(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayPrimaryDescription const& desc) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->CreatePrimary(*(void**)(&target), *(void**)(&desc), &result));
        return llm::OS::Devices::Display::Core::DisplaySurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTaskPool) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::CreateTaskPool() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->CreateTaskPool(&result));
        return llm::OS::Devices::Display::Core::DisplayTaskPool{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayFence) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::CreatePeriodicFence(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Foundation::TimeSpan const& offsetFromVBlank) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->CreatePeriodicFence(*(void**)(&target), impl::bind_in(offsetFromVBlank), &result));
        return llm::OS::Devices::Display::Core::DisplayFence{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::WaitForVBlank(llm::OS::Devices::Display::Core::DisplaySource const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->WaitForVBlank(*(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayScanout) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::CreateSimpleScanout(llm::OS::Devices::Display::Core::DisplaySource const& pSource, llm::OS::Devices::Display::Core::DisplaySurface const& pSurface, uint32_t SubResourceIndex, uint32_t SyncInterval) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->CreateSimpleScanout(*(void**)(&pSource), *(void**)(&pSurface), SubResourceIndex, SyncInterval, &result));
        return llm::OS::Devices::Display::Core::DisplayScanout{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayDevice<D>::IsCapabilitySupported(llm::OS::Devices::Display::Core::DisplayDeviceCapability const& capability) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice)->IsCapabilitySupported(static_cast<int32_t>(capability), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayScanout) consume_Windows_Devices_Display_Core_IDisplayDevice2<D>::CreateSimpleScanoutWithDirtyRectsAndOptions(llm::OS::Devices::Display::Core::DisplaySource const& source, llm::OS::Devices::Display::Core::DisplaySurface const& surface, uint32_t subresourceIndex, uint32_t syncInterval, param::iterable<llm::OS::Graphics::RectInt32> const& dirtyRects, llm::OS::Devices::Display::Core::DisplayScanoutOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayDevice2)->CreateSimpleScanoutWithDirtyRectsAndOptions(*(void**)(&source), *(void**)(&surface), subresourceIndex, syncInterval, *(void**)(&dirtyRects), static_cast<uint32_t>(options), &result));
        return llm::OS::Devices::Display::Core::DisplayScanout{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>) consume_Windows_Devices_Display_Core_IDisplayManager<D>::GetCurrentTargets() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->GetCurrentTargets(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayAdapter>) consume_Windows_Devices_Display_Core_IDisplayManager<D>::GetCurrentAdapters() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->GetCurrentAdapters(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayAdapter>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResult) consume_Windows_Devices_Display_Core_IDisplayManager<D>::TryAcquireTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        llm::OS::Devices::Display::Core::DisplayManagerResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->TryAcquireTarget(*(void**)(&target), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::ReleaseTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->ReleaseTarget(*(void**)(&target)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) consume_Windows_Devices_Display_Core_IDisplayManager<D>::TryReadCurrentStateForAllTargets() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->TryReadCurrentStateForAllTargets(&result));
        return llm::OS::Devices::Display::Core::DisplayManagerResultWithState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) consume_Windows_Devices_Display_Core_IDisplayManager<D>::TryAcquireTargetsAndReadCurrentState(param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->TryAcquireTargetsAndReadCurrentState(*(void**)(&targets), &result));
        return llm::OS::Devices::Display::Core::DisplayManagerResultWithState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) consume_Windows_Devices_Display_Core_IDisplayManager<D>::TryAcquireTargetsAndCreateEmptyState(param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->TryAcquireTargetsAndCreateEmptyState(*(void**)(&targets), &result));
        return llm::OS::Devices::Display::Core::DisplayManagerResultWithState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResultWithState) consume_Windows_Devices_Display_Core_IDisplayManager<D>::TryAcquireTargetsAndCreateSubstate(llm::OS::Devices::Display::Core::DisplayState const& existingState, param::iterable<llm::OS::Devices::Display::Core::DisplayTarget> const& targets) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->TryAcquireTargetsAndCreateSubstate(*(void**)(&existingState), *(void**)(&targets), &result));
        return llm::OS::Devices::Display::Core::DisplayManagerResultWithState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayDevice) consume_Windows_Devices_Display_Core_IDisplayManager<D>::CreateDisplayDevice(llm::OS::Devices::Display::Core::DisplayAdapter const& adapter) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->CreateDisplayDevice(*(void**)(&adapter), &result));
        return llm::OS::Devices::Display::Core::DisplayDevice{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Enabled(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->add_Enabled(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Display_Core_IDisplayManager<D>::Enabled_revoker consume_Windows_Devices_Display_Core_IDisplayManager<D>::Enabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Enabled_revoker>(this, Enabled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Enabled(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->remove_Enabled(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Disabled(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->add_Disabled(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Display_Core_IDisplayManager<D>::Disabled_revoker consume_Windows_Devices_Display_Core_IDisplayManager<D>::Disabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Disabled_revoker>(this, Disabled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Disabled(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->remove_Disabled(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Display_Core_IDisplayManager<D>::Changed_revoker consume_Windows_Devices_Display_Core_IDisplayManager<D>::Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Changed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Display_Core_IDisplayManager<D>::PathsFailedOrInvalidated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->add_PathsFailedOrInvalidated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Display_Core_IDisplayManager<D>::PathsFailedOrInvalidated_revoker consume_Windows_Devices_Display_Core_IDisplayManager<D>::PathsFailedOrInvalidated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PathsFailedOrInvalidated_revoker>(this, PathsFailedOrInvalidated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::PathsFailedOrInvalidated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->remove_PathsFailedOrInvalidated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManager<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManager)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayManagerChangedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManagerChangedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Devices_Display_Core_IDisplayManagerChangedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayManagerDisabledEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManagerDisabledEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Devices_Display_Core_IDisplayManagerDisabledEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayManagerEnabledEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManagerEnabledEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Devices_Display_Core_IDisplayManagerEnabledEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayManagerPathsFailedOrInvalidatedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayManagerPathsFailedOrInvalidatedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Devices_Display_Core_IDisplayManagerPathsFailedOrInvalidatedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManagerResult) consume_Windows_Devices_Display_Core_IDisplayManagerResultWithState<D>::ErrorCode() const
    {
        llm::OS::Devices::Display::Core::DisplayManagerResult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerResultWithState)->get_ErrorCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Devices_Display_Core_IDisplayManagerResultWithState<D>::ExtendedErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerResultWithState)->get_ExtendedErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayState) consume_Windows_Devices_Display_Core_IDisplayManagerResultWithState<D>::State() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerResultWithState)->get_State(&value));
        return llm::OS::Devices::Display::Core::DisplayState{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayManager) consume_Windows_Devices_Display_Core_IDisplayManagerStatics<D>::Create(llm::OS::Devices::Display::Core::DisplayManagerOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayManagerStatics)->Create(static_cast<uint32_t>(options), &result));
        return llm::OS::Devices::Display::Core::DisplayManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::SourceResolution() const
    {
        llm::OS::Graphics::SizeInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_SourceResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::SourcePixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_SourcePixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::TargetResolution() const
    {
        llm::OS::Graphics::SizeInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_TargetResolution(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentationRate) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::PresentationRate() const
    {
        llm::OS::Devices::Display::Core::DisplayPresentationRate value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_PresentationRate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::IsInterlaced() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_IsInterlaced(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayBitsPerChannel) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::GetWireFormatSupportedBitsPerChannel(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& encoding) const
    {
        llm::OS::Devices::Display::Core::DisplayBitsPerChannel result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->GetWireFormatSupportedBitsPerChannel(static_cast<int32_t>(encoding), reinterpret_cast<uint32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::IsWireFormatSupported(llm::OS::Devices::Display::Core::DisplayWireFormat const& wireFormat) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->IsWireFormatSupported(*(void**)(&wireFormat), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayModeInfo<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentationRate) consume_Windows_Devices_Display_Core_IDisplayModeInfo2<D>::PhysicalPresentationRate() const
    {
        llm::OS::Devices::Display::Core::DisplayPresentationRate value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayModeInfo2)->get_PhysicalPresentationRate(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayView) consume_Windows_Devices_Display_Core_IDisplayPath<D>::View() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_View(&value));
        return llm::OS::Devices::Display::Core::DisplayView{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTarget) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Target() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_Target(&value));
        return llm::OS::Devices::Display::Core::DisplayTarget{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPathStatus) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Status() const
    {
        llm::OS::Devices::Display::Core::DisplayPathStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::SourceResolution() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_SourceResolution(&value));
        return llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::SourceResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_SourceResolution(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Devices_Display_Core_IDisplayPath<D>::SourcePixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_SourcePixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::SourcePixelFormat(llm::OS::Graphics::DirectX::DirectXPixelFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_SourcePixelFormat(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayPath<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::IsStereo(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_IsStereo(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::TargetResolution() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_TargetResolution(&value));
        return llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::TargetResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_TargetResolution(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::PresentationRate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_PresentationRate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::PresentationRate(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_PresentationRate(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::IsInterlaced() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_IsInterlaced(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::IsInterlaced(llm::OS::Foundation::IReference<bool> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_IsInterlaced(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) consume_Windows_Devices_Display_Core_IDisplayPath<D>::WireFormat() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_WireFormat(&value));
        return llm::OS::Devices::Display::Core::DisplayWireFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::WireFormat(llm::OS::Devices::Display::Core::DisplayWireFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_WireFormat(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayRotation) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Rotation() const
    {
        llm::OS::Devices::Display::Core::DisplayRotation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_Rotation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Rotation(llm::OS::Devices::Display::Core::DisplayRotation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_Rotation(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPathScaling) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Scaling() const
    {
        llm::OS::Devices::Display::Core::DisplayPathScaling value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_Scaling(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Scaling(llm::OS::Devices::Display::Core::DisplayPathScaling const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->put_Scaling(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayModeInfo>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::FindModes(llm::OS::Devices::Display::Core::DisplayModeQueryOptions const& flags) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->FindModes(static_cast<uint32_t>(flags), &result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayModeInfo>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath<D>::ApplyPropertiesFromMode(llm::OS::Devices::Display::Core::DisplayModeInfo const& modeResult) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->ApplyPropertiesFromMode(*(void**)(&modeResult)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayPath<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>) consume_Windows_Devices_Display_Core_IDisplayPath2<D>::PhysicalPresentationRate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath2)->get_PhysicalPresentationRate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayPath2<D>::PhysicalPresentationRate(llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPath2)->put_PhysicalPresentationRate(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::Width() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_Width(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::Height() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_Height(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::Format() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXColorSpace) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::ColorSpace() const
    {
        llm::OS::Graphics::DirectX::DirectXColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_ColorSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::IsStereo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_IsStereo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::MultisampleDescription() const
    {
        llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_MultisampleDescription(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescription<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescription)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPrimaryDescription) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionFactory<D>::CreateInstance(uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory)->CreateInstance(width, height, static_cast<int32_t>(pixelFormat), static_cast<int32_t>(colorSpace), isStereo, impl::bind_in(multisampleDescription), &value));
        return llm::OS::Devices::Display::Core::DisplayPrimaryDescription{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPrimaryDescription) consume_Windows_Devices_Display_Core_IDisplayPrimaryDescriptionStatics<D>::CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics)->CreateWithProperties(*(void**)(&extraProperties), width, height, static_cast<int32_t>(pixelFormat), static_cast<int32_t>(colorSpace), isStereo, impl::bind_in(multisampleDescription), &result));
        return llm::OS::Devices::Display::Core::DisplayPrimaryDescription{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) consume_Windows_Devices_Display_Core_IDisplaySource<D>::AdapterId() const
    {
        llm::OS::Graphics::DisplayAdapterId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource)->get_AdapterId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplaySource<D>::SourceId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource)->get_SourceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Display_Core_IDisplaySource<D>::GetMetadata(llm::guid const& Key) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource)->GetMetadata(impl::bind_in(Key), &result));
        return llm::OS::Storage::Streams::IBuffer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySourceStatus) consume_Windows_Devices_Display_Core_IDisplaySource2<D>::Status() const
    {
        llm::OS::Devices::Display::Core::DisplaySourceStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource2)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Display_Core_IDisplaySource2<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplaySource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource2)->add_StatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Display_Core_IDisplaySource2<D>::StatusChanged_revoker consume_Windows_Devices_Display_Core_IDisplaySource2<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplaySource, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplaySource2<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplaySource2)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayState<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayState<D>::IsStale() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->get_IsStale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>) consume_Windows_Devices_Display_Core_IDisplayState<D>::Targets() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->get_Targets(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayView>) consume_Windows_Devices_Display_Core_IDisplayState<D>::Views() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->get_Views(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayView>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayState<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) consume_Windows_Devices_Display_Core_IDisplayState<D>::ConnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->ConnectTarget(*(void**)(&target), &result));
        return llm::OS::Devices::Display::Core::DisplayPath{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) consume_Windows_Devices_Display_Core_IDisplayState<D>::ConnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayView const& view) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->ConnectTargetToView(*(void**)(&target), *(void**)(&view), &result));
        return llm::OS::Devices::Display::Core::DisplayPath{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayState<D>::CanConnectTargetToView(llm::OS::Devices::Display::Core::DisplayTarget const& target, llm::OS::Devices::Display::Core::DisplayView const& view) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->CanConnectTargetToView(*(void**)(&target), *(void**)(&view), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayView) consume_Windows_Devices_Display_Core_IDisplayState<D>::GetViewForTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->GetViewForTarget(*(void**)(&target), &result));
        return llm::OS::Devices::Display::Core::DisplayView{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPath) consume_Windows_Devices_Display_Core_IDisplayState<D>::GetPathForTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->GetPathForTarget(*(void**)(&target), &result));
        return llm::OS::Devices::Display::Core::DisplayPath{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayState<D>::DisconnectTarget(llm::OS::Devices::Display::Core::DisplayTarget const& target) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->DisconnectTarget(*(void**)(&target)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationResult) consume_Windows_Devices_Display_Core_IDisplayState<D>::TryFunctionalize(llm::OS::Devices::Display::Core::DisplayStateFunctionalizeOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->TryFunctionalize(static_cast<uint32_t>(options), &result));
        return llm::OS::Devices::Display::Core::DisplayStateOperationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationResult) consume_Windows_Devices_Display_Core_IDisplayState<D>::TryApply(llm::OS::Devices::Display::Core::DisplayStateApplyOptions const& options) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->TryApply(static_cast<uint32_t>(options), &result));
        return llm::OS::Devices::Display::Core::DisplayStateOperationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayState) consume_Windows_Devices_Display_Core_IDisplayState<D>::Clone() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayState)->Clone(&result));
        return llm::OS::Devices::Display::Core::DisplayState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayStateOperationStatus) consume_Windows_Devices_Display_Core_IDisplayStateOperationResult<D>::Status() const
    {
        llm::OS::Devices::Display::Core::DisplayStateOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayStateOperationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Devices_Display_Core_IDisplayStateOperationResult<D>::ExtendedErrorCode() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayStateOperationResult)->get_ExtendedErrorCode(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayAdapter) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::Adapter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_Adapter(&value));
        return llm::OS::Devices::Display::Core::DisplayAdapter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::DeviceInterfacePath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_DeviceInterfacePath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::AdapterRelativeId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_AdapterRelativeId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsConnected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_IsConnected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsVirtualModeEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_IsVirtualModeEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsVirtualTopologyEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_IsVirtualTopologyEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorUsageKind) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::UsageKind() const
    {
        llm::OS::Devices::Display::DisplayMonitorUsageKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_UsageKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTargetPersistence) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::MonitorPersistence() const
    {
        llm::OS::Devices::Display::Core::DisplayTargetPersistence value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_MonitorPersistence(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::StableMonitorId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_StableMonitorId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitor) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::TryGetMonitor() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->TryGetMonitor(&result));
        return llm::OS::Devices::Display::DisplayMonitor{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsStale() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->get_IsStale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsSame(llm::OS::Devices::Display::Core::DisplayTarget const& otherTarget) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->IsSame(*(void**)(&otherTarget), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_Core_IDisplayTarget<D>::IsEqual(llm::OS::Devices::Display::Core::DisplayTarget const& otherTarget) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTarget)->IsEqual(*(void**)(&otherTarget), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayTask<D>::SetScanout(llm::OS::Devices::Display::Core::DisplayScanout const& scanout) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTask)->SetScanout(*(void**)(&scanout)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayTask<D>::SetWait(llm::OS::Devices::Display::Core::DisplayFence const& readyFence, uint64_t readyFenceValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTask)->SetWait(*(void**)(&readyFence), readyFenceValue));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayTask2<D>::SetSignal(llm::OS::Devices::Display::Core::DisplayTaskSignalKind const& signalKind, llm::OS::Devices::Display::Core::DisplayFence const& fence) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTask2)->SetSignal(static_cast<int32_t>(signalKind), *(void**)(&fence)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTask) consume_Windows_Devices_Display_Core_IDisplayTaskPool<D>::CreateTask() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskPool)->CreateTask(&result));
        return llm::OS::Devices::Display::Core::DisplayTask{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayTaskPool<D>::ExecuteTask(llm::OS::Devices::Display::Core::DisplayTask const& task) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskPool)->ExecuteTask(*(void**)(&task)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayTaskResult) consume_Windows_Devices_Display_Core_IDisplayTaskPool2<D>::TryExecuteTask(llm::OS::Devices::Display::Core::DisplayTask const& task) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskPool2)->TryExecuteTask(*(void**)(&task), &result));
        return llm::OS::Devices::Display::Core::DisplayTaskResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayPresentStatus) consume_Windows_Devices_Display_Core_IDisplayTaskResult<D>::PresentStatus() const
    {
        llm::OS::Devices::Display::Core::DisplayPresentStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskResult)->get_PresentStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Devices_Display_Core_IDisplayTaskResult<D>::PresentId() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskResult)->get_PresentId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplaySourceStatus) consume_Windows_Devices_Display_Core_IDisplayTaskResult<D>::SourceStatus() const
    {
        llm::OS::Devices::Display::Core::DisplaySourceStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayTaskResult)->get_SourceStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayPath>) consume_Windows_Devices_Display_Core_IDisplayView<D>::Paths() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayView)->get_Paths(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayPath>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>) consume_Windows_Devices_Display_Core_IDisplayView<D>::ContentResolution() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayView)->get_ContentResolution(&value));
        return llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayView<D>::ContentResolution(llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayView)->put_ContentResolution(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Display_Core_IDisplayView<D>::SetPrimaryPath(llm::OS::Devices::Display::Core::DisplayPath const& path) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayView)->SetPrimaryPath(*(void**)(&path)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayView<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayView)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::PixelEncoding() const
    {
        llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_PixelEncoding(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::BitsPerChannel() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_BitsPerChannel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::ColorSpace() const
    {
        llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_ColorSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatEotf) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::Eotf() const
    {
        llm::OS::Devices::Display::Core::DisplayWireFormatEotf value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_Eotf(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::HdrMetadata() const
    {
        llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_HdrMetadata(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Display_Core_IDisplayWireFormat<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormat)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<llm::guid, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) consume_Windows_Devices_Display_Core_IDisplayWireFormatFactory<D>::CreateInstance(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormatFactory)->CreateInstance(static_cast<int32_t>(pixelEncoding), bitsPerChannel, static_cast<int32_t>(colorSpace), static_cast<int32_t>(eotf), static_cast<int32_t>(hdrMetadata), &value));
        return llm::OS::Devices::Display::Core::DisplayWireFormat{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::Core::DisplayWireFormat) consume_Windows_Devices_Display_Core_IDisplayWireFormatStatics<D>::CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::Core::IDisplayWireFormatStatics)->CreateWithProperties(*(void**)(&extraProperties), static_cast<int32_t>(pixelEncoding), bitsPerChannel, static_cast<int32_t>(colorSpace), static_cast<int32_t>(eotf), static_cast<int32_t>(hdrMetadata), &result));
        return llm::OS::Devices::Display::Core::DisplayWireFormat{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayAdapter> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayAdapter>
    {
        int32_t __stdcall get_Id(struct struct_Windows_Graphics_DisplayAdapterId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::DisplayAdapterId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DisplayAdapterId>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInterfacePath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceInterfacePath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SourceCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PciVendorId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PciVendorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PciDeviceId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PciDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PciSubSystemId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PciSubSystemId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PciRevision(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PciRevision());
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayAdapterStatics> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayAdapterStatics>
    {
        int32_t __stdcall FromId(struct struct_Windows_Graphics_DisplayAdapterId id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayAdapter>(this->shim().FromId(*reinterpret_cast<llm::OS::Graphics::DisplayAdapterId const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayDevice> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayDevice>
    {
        int32_t __stdcall CreateScanoutSource(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplaySource>(this->shim().CreateScanoutSource(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePrimary(void* target, void* desc, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplaySurface>(this->shim().CreatePrimary(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayPrimaryDescription const*>(&desc)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTaskPool(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayTaskPool>(this->shim().CreateTaskPool());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePeriodicFence(void* target, int64_t offsetFromVBlank, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayFence>(this->shim().CreatePeriodicFence(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target), *reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&offsetFromVBlank)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WaitForVBlank(void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForVBlank(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplaySource const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSimpleScanout(void* pSource, void* pSurface, uint32_t SubResourceIndex, uint32_t SyncInterval, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayScanout>(this->shim().CreateSimpleScanout(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplaySource const*>(&pSource), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplaySurface const*>(&pSurface), SubResourceIndex, SyncInterval));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCapabilitySupported(int32_t capability, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsCapabilitySupported(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayDeviceCapability const*>(&capability)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayDevice2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayDevice2>
    {
        int32_t __stdcall CreateSimpleScanoutWithDirtyRectsAndOptions(void* source, void* surface, uint32_t subresourceIndex, uint32_t syncInterval, void* dirtyRects, uint32_t options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayScanout>(this->shim().CreateSimpleScanoutWithDirtyRectsAndOptions(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplaySource const*>(&source), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplaySurface const*>(&surface), subresourceIndex, syncInterval, *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Graphics::RectInt32> const*>(&dirtyRects), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayScanoutOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayFence> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayFence>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManager> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManager>
    {
        int32_t __stdcall GetCurrentTargets(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>>(this->shim().GetCurrentTargets());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentAdapters(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayAdapter>>(this->shim().GetCurrentAdapters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryAcquireTarget(void* target, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResult>(this->shim().TryAcquireTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReleaseTarget(void* target) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryReadCurrentStateForAllTargets(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>(this->shim().TryReadCurrentStateForAllTargets());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryAcquireTargetsAndReadCurrentState(void* targets, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>(this->shim().TryAcquireTargetsAndReadCurrentState(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Display::Core::DisplayTarget> const*>(&targets)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryAcquireTargetsAndCreateEmptyState(void* targets, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>(this->shim().TryAcquireTargetsAndCreateEmptyState(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Display::Core::DisplayTarget> const*>(&targets)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryAcquireTargetsAndCreateSubstate(void* existingState, void* targets, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResultWithState>(this->shim().TryAcquireTargetsAndCreateSubstate(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayState const*>(&existingState), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Display::Core::DisplayTarget> const*>(&targets)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDisplayDevice(void* adapter, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayDevice>(this->shim().CreateDisplayDevice(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayAdapter const*>(&adapter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Enabled(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Enabled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Enabled(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Disabled(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Disabled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Disabled(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disabled(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Changed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Changed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PathsFailedOrInvalidated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PathsFailedOrInvalidated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplayManager, llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PathsFailedOrInvalidated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PathsFailedOrInvalidated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
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
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
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
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
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
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
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
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
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
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerResultWithState> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerResultWithState>
    {
        int32_t __stdcall get_ErrorCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayManagerResult>(this->shim().ErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayManagerStatics> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayManagerStatics>
    {
        int32_t __stdcall Create(uint32_t options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayManager>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayManagerOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayModeInfo> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayModeInfo>
    {
        int32_t __stdcall get_SourceResolution(struct struct_Windows_Graphics_SizeInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::SizeInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::SizeInt32>(this->shim().SourceResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().SourcePixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetResolution(struct struct_Windows_Graphics_SizeInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::SizeInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::SizeInt32>(this->shim().TargetResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentationRate(struct struct_Windows_Devices_Display_Core_DisplayPresentationRate* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Display::Core::DisplayPresentationRate>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPresentationRate>(this->shim().PresentationRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInterlaced(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInterlaced());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetWireFormatSupportedBitsPerChannel(int32_t encoding, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayBitsPerChannel>(this->shim().GetWireFormatSupportedBitsPerChannel(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const*>(&encoding)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsWireFormatSupported(void* wireFormat, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsWireFormatSupported(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormat const*>(&wireFormat)));
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayModeInfo2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayModeInfo2>
    {
        int32_t __stdcall get_PhysicalPresentationRate(struct struct_Windows_Devices_Display_Core_DisplayPresentationRate* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Display::Core::DisplayPresentationRate>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPresentationRate>(this->shim().PhysicalPresentationRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayPath> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayPath>
    {
        int32_t __stdcall get_View(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayView>(this->shim().View());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Target(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayTarget>(this->shim().Target());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPathStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceResolution(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>>(this->shim().SourceResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceResolution(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceResolution(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourcePixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().SourcePixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourcePixelFormat(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourcePixelFormat(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsStereo(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStereo(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TargetResolution(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>>(this->shim().TargetResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TargetResolution(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetResolution(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentationRate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>>(this->shim().PresentationRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PresentationRate(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PresentationRate(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInterlaced(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().IsInterlaced());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInterlaced(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInterlaced(*reinterpret_cast<llm::OS::Foundation::IReference<bool> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WireFormat(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormat>(this->shim().WireFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WireFormat(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WireFormat(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rotation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayRotation>(this->shim().Rotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Rotation(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayRotation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scaling(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPathScaling>(this->shim().Scaling());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scaling(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scaling(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayPathScaling const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindModes(uint32_t flags, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayModeInfo>>(this->shim().FindModes(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayModeQueryOptions const*>(&flags)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyPropertiesFromMode(void* modeResult) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyPropertiesFromMode(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayModeInfo const*>(&modeResult));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayPath2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayPath2>
    {
        int32_t __stdcall get_PhysicalPresentationRate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate>>(this->shim().PhysicalPresentationRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PhysicalPresentationRate(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhysicalPresentationRate(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Devices::Display::Core::DisplayPresentationRate> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescription> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescription>
    {
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
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXColorSpace>(this->shim().ColorSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStereo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStereo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MultisampleDescription(struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription>(this->shim().MultisampleDescription());
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory>
    {
        int32_t __stdcall CreateInstance(uint32_t width, uint32_t height, int32_t pixelFormat, int32_t colorSpace, bool isStereo, struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription multisampleDescription, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPrimaryDescription>(this->shim().CreateInstance(width, height, *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXColorSpace const*>(&colorSpace), isStereo, *reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const*>(&multisampleDescription)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics>
    {
        int32_t __stdcall CreateWithProperties(void* extraProperties, uint32_t width, uint32_t height, int32_t pixelFormat, int32_t colorSpace, bool isStereo, struct struct_Windows_Graphics_DirectX_Direct3D11_Direct3DMultisampleDescription multisampleDescription, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayPrimaryDescription>(this->shim().CreateWithProperties(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const*>(&extraProperties), width, height, *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXColorSpace const*>(&colorSpace), isStereo, *reinterpret_cast<llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const*>(&multisampleDescription)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayScanout> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayScanout>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplaySource> : produce_base<D, llm::OS::Devices::Display::Core::IDisplaySource>
    {
        int32_t __stdcall get_AdapterId(struct struct_Windows_Graphics_DisplayAdapterId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::DisplayAdapterId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DisplayAdapterId>(this->shim().AdapterId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SourceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMetadata(llm::guid Key, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetMetadata(*reinterpret_cast<llm::guid const*>(&Key)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplaySource2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplaySource2>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplaySourceStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Display::Core::DisplaySource, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayState> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayState>
    {
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStale(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Targets(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayTarget>>(this->shim().Targets());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Views(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayView>>(this->shim().Views());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectTarget(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayPath>(this->shim().ConnectTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectTargetToView(void* target, void* view, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayPath>(this->shim().ConnectTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayView const*>(&view)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CanConnectTargetToView(void* target, void* view, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().CanConnectTargetToView(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayView const*>(&view)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetViewForTarget(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayView>(this->shim().GetViewForTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPathForTarget(void* target, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayPath>(this->shim().GetPathForTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisconnectTarget(void* target) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectTarget(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&target));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryFunctionalize(uint32_t options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayStateOperationResult>(this->shim().TryFunctionalize(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayStateFunctionalizeOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryApply(uint32_t options, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayStateOperationResult>(this->shim().TryApply(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayStateApplyOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clone(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayState>(this->shim().Clone());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayStateOperationResult> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayStateOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayStateOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedErrorCode(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplaySurface> : produce_base<D, llm::OS::Devices::Display::Core::IDisplaySurface>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTarget> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTarget>
    {
        int32_t __stdcall get_Adapter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayAdapter>(this->shim().Adapter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInterfacePath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceInterfacePath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdapterRelativeId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().AdapterRelativeId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsConnected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConnected());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVirtualModeEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVirtualModeEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVirtualTopologyEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVirtualTopologyEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsageKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::DisplayMonitorUsageKind>(this->shim().UsageKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MonitorPersistence(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayTargetPersistence>(this->shim().MonitorPersistence());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StableMonitorId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StableMonitorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetMonitor(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::DisplayMonitor>(this->shim().TryGetMonitor());
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
        int32_t __stdcall get_IsStale(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSame(void* otherTarget, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSame(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&otherTarget)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEqual(void* otherTarget, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsEqual(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTarget const*>(&otherTarget)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTask> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTask>
    {
        int32_t __stdcall SetScanout(void* scanout) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetScanout(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayScanout const*>(&scanout));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetWait(void* readyFence, uint64_t readyFenceValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetWait(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayFence const*>(&readyFence), readyFenceValue);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTask2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTask2>
    {
        int32_t __stdcall SetSignal(int32_t signalKind, void* fence) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSignal(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTaskSignalKind const*>(&signalKind), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayFence const*>(&fence));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTaskPool> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTaskPool>
    {
        int32_t __stdcall CreateTask(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayTask>(this->shim().CreateTask());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ExecuteTask(void* task) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExecuteTask(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTask const*>(&task));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTaskPool2> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTaskPool2>
    {
        int32_t __stdcall TryExecuteTask(void* task, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayTaskResult>(this->shim().TryExecuteTask(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayTask const*>(&task)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayTaskResult> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayTaskResult>
    {
        int32_t __stdcall get_PresentStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayPresentStatus>(this->shim().PresentStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PresentId(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().PresentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplaySourceStatus>(this->shim().SourceStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayView> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayView>
    {
        int32_t __stdcall get_Paths(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Display::Core::DisplayPath>>(this->shim().Paths());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentResolution(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32>>(this->shim().ContentResolution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ContentResolution(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentResolution(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Graphics::SizeInt32> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPrimaryPath(void* path) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPrimaryPath(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayPath const*>(&path));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<llm::guid, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayWireFormat> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayWireFormat>
    {
        int32_t __stdcall get_PixelEncoding(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding>(this->shim().PixelEncoding());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BitsPerChannel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().BitsPerChannel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace>(this->shim().ColorSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Eotf(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormatEotf>(this->shim().Eotf());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HdrMetadata(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata>(this->shim().HdrMetadata());
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayWireFormatFactory> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayWireFormatFactory>
    {
        int32_t __stdcall CreateInstance(int32_t pixelEncoding, int32_t bitsPerChannel, int32_t colorSpace, int32_t eotf, int32_t hdrMetadata, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormat>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const*>(&pixelEncoding), bitsPerChannel, *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const*>(&colorSpace), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatEotf const*>(&eotf), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const*>(&hdrMetadata)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::Core::IDisplayWireFormatStatics> : produce_base<D, llm::OS::Devices::Display::Core::IDisplayWireFormatStatics>
    {
        int32_t __stdcall CreateWithProperties(void* extraProperties, int32_t pixelEncoding, int32_t bitsPerChannel, int32_t colorSpace, int32_t eotf, int32_t hdrMetadata, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Display::Core::DisplayWireFormat>(this->shim().CreateWithProperties(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const*>(&extraProperties), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const*>(&pixelEncoding), bitsPerChannel, *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const*>(&colorSpace), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatEotf const*>(&eotf), *reinterpret_cast<llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const*>(&hdrMetadata)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Display::Core
{
    constexpr auto operator|(DisplayBitsPerChannel const left, DisplayBitsPerChannel const right) noexcept
    {
        return static_cast<DisplayBitsPerChannel>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayBitsPerChannel& left, DisplayBitsPerChannel const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayBitsPerChannel const left, DisplayBitsPerChannel const right) noexcept
    {
        return static_cast<DisplayBitsPerChannel>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayBitsPerChannel& left, DisplayBitsPerChannel const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayBitsPerChannel const value) noexcept
    {
        return static_cast<DisplayBitsPerChannel>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayBitsPerChannel const left, DisplayBitsPerChannel const right) noexcept
    {
        return static_cast<DisplayBitsPerChannel>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayBitsPerChannel& left, DisplayBitsPerChannel const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayManagerOptions const left, DisplayManagerOptions const right) noexcept
    {
        return static_cast<DisplayManagerOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayManagerOptions& left, DisplayManagerOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayManagerOptions const left, DisplayManagerOptions const right) noexcept
    {
        return static_cast<DisplayManagerOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayManagerOptions& left, DisplayManagerOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayManagerOptions const value) noexcept
    {
        return static_cast<DisplayManagerOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayManagerOptions const left, DisplayManagerOptions const right) noexcept
    {
        return static_cast<DisplayManagerOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayManagerOptions& left, DisplayManagerOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayModeQueryOptions const left, DisplayModeQueryOptions const right) noexcept
    {
        return static_cast<DisplayModeQueryOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayModeQueryOptions& left, DisplayModeQueryOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayModeQueryOptions const left, DisplayModeQueryOptions const right) noexcept
    {
        return static_cast<DisplayModeQueryOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayModeQueryOptions& left, DisplayModeQueryOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayModeQueryOptions const value) noexcept
    {
        return static_cast<DisplayModeQueryOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayModeQueryOptions const left, DisplayModeQueryOptions const right) noexcept
    {
        return static_cast<DisplayModeQueryOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayModeQueryOptions& left, DisplayModeQueryOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayScanoutOptions const left, DisplayScanoutOptions const right) noexcept
    {
        return static_cast<DisplayScanoutOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayScanoutOptions& left, DisplayScanoutOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayScanoutOptions const left, DisplayScanoutOptions const right) noexcept
    {
        return static_cast<DisplayScanoutOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayScanoutOptions& left, DisplayScanoutOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayScanoutOptions const value) noexcept
    {
        return static_cast<DisplayScanoutOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayScanoutOptions const left, DisplayScanoutOptions const right) noexcept
    {
        return static_cast<DisplayScanoutOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayScanoutOptions& left, DisplayScanoutOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayStateApplyOptions const left, DisplayStateApplyOptions const right) noexcept
    {
        return static_cast<DisplayStateApplyOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayStateApplyOptions& left, DisplayStateApplyOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayStateApplyOptions const left, DisplayStateApplyOptions const right) noexcept
    {
        return static_cast<DisplayStateApplyOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayStateApplyOptions& left, DisplayStateApplyOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayStateApplyOptions const value) noexcept
    {
        return static_cast<DisplayStateApplyOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayStateApplyOptions const left, DisplayStateApplyOptions const right) noexcept
    {
        return static_cast<DisplayStateApplyOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayStateApplyOptions& left, DisplayStateApplyOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DisplayStateFunctionalizeOptions const left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        return static_cast<DisplayStateFunctionalizeOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DisplayStateFunctionalizeOptions& left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DisplayStateFunctionalizeOptions const left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        return static_cast<DisplayStateFunctionalizeOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DisplayStateFunctionalizeOptions& left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DisplayStateFunctionalizeOptions const value) noexcept
    {
        return static_cast<DisplayStateFunctionalizeOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DisplayStateFunctionalizeOptions const left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        return static_cast<DisplayStateFunctionalizeOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DisplayStateFunctionalizeOptions& left, DisplayStateFunctionalizeOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto DisplayAdapter::FromId(llm::OS::Graphics::DisplayAdapterId const& id)
    {
        return impl::call_factory<DisplayAdapter, IDisplayAdapterStatics>([&](IDisplayAdapterStatics const& f) { return f.FromId(id); });
    }
    inline auto DisplayManager::Create(llm::OS::Devices::Display::Core::DisplayManagerOptions const& options)
    {
        return impl::call_factory<DisplayManager, IDisplayManagerStatics>([&](IDisplayManagerStatics const& f) { return f.Create(options); });
    }
    inline DisplayPrimaryDescription::DisplayPrimaryDescription(uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription) :
        DisplayPrimaryDescription(impl::call_factory<DisplayPrimaryDescription, IDisplayPrimaryDescriptionFactory>([&](IDisplayPrimaryDescriptionFactory const& f) { return f.CreateInstance(width, height, pixelFormat, colorSpace, isStereo, multisampleDescription); }))
    {
    }
    inline auto DisplayPrimaryDescription::CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, uint32_t width, uint32_t height, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, llm::OS::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription)
    {
        return impl::call_factory<DisplayPrimaryDescription, IDisplayPrimaryDescriptionStatics>([&](IDisplayPrimaryDescriptionStatics const& f) { return f.CreateWithProperties(extraProperties, width, height, pixelFormat, colorSpace, isStereo, multisampleDescription); });
    }
    inline DisplayWireFormat::DisplayWireFormat(llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata) :
        DisplayWireFormat(impl::call_factory<DisplayWireFormat, IDisplayWireFormatFactory>([&](IDisplayWireFormatFactory const& f) { return f.CreateInstance(pixelEncoding, bitsPerChannel, colorSpace, eotf, hdrMetadata); }))
    {
    }
    inline auto DisplayWireFormat::CreateWithProperties(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<llm::guid, llm::OS::Foundation::IInspectable>> const& extraProperties, llm::OS::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, llm::OS::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, llm::OS::Devices::Display::Core::DisplayWireFormatEotf const& eotf, llm::OS::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata)
    {
        return impl::call_factory<DisplayWireFormat, IDisplayWireFormatStatics>([&](IDisplayWireFormatStatics const& f) { return f.CreateWithProperties(extraProperties, pixelEncoding, bitsPerChannel, colorSpace, eotf, hdrMetadata); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayAdapter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayAdapterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayFence> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerDisabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerEnabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerResultWithState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayModeInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayModeInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayPath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayPath2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayPrimaryDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayPrimaryDescriptionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayScanout> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplaySource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplaySource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayStateOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplaySurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTarget> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTask2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTaskPool> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTaskPool2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayTaskResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayWireFormat> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayWireFormatFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::IDisplayWireFormatStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayAdapter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayFence> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManagerChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManagerDisabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManagerEnabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManagerPathsFailedOrInvalidatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayManagerResultWithState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayModeInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayPath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayPrimaryDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayScanout> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplaySource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayStateOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplaySurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayTarget> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayTask> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayTaskPool> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayTaskResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::Core::DisplayWireFormat> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
